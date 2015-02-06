#include <opencv2/calib3d/calib3d.hpp>

#include "image_matcher.h"
#include "global_settings.h"

using namespace orbicon;

ImageMatcher::ImageMatcher() {}

ImageMatcher::ImageMatcher(Image& left, Image& right)
{
	this->left  = &left;
	this->right = &right;

	this->matcher = BFMatcher(NORM_HAMMING);

	match();
}

vector<DMatch, allocator<DMatch>> ImageMatcher::get_matches()
{
	return matches;
}

Mat& ImageMatcher::get_matches_drawing()
{
	if (matches_drawing.empty())
	{
		drawMatches(left->get_grayscale_image(), left->get_keypoints(),
					right->get_grayscale_image(), right->get_keypoints(),
					get_matches(), matches_drawing,
					Scalar::all(-1), Scalar::all(1),
					vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

		display_homography();
	}

	return matches_drawing;
}

void ImageMatcher::match()
{
	clear();

	if (GlobalSettings::use_knn_match)
	{
		knn_match();
	}
	else
	{
		simple_match();
	}
}

void ImageMatcher::clear()
{
	clear_matches();
	clear_matches_drawing();
}

void ImageMatcher::clear_matches()
{
	matches.clear();
	vector<DMatch, allocator<DMatch>>().swap(matches); //reallocating the vector
}

void ImageMatcher::clear_matches_drawing()
{
	matches_drawing = Mat();
}

void ImageMatcher::simple_match()
{
	vector<DMatch, allocator<DMatch>> all_matches;

	matcher.match(left->get_descriptors(), right->get_descriptors(), all_matches);

	double min_dist = 100000;

	vector<DMatch, allocator<DMatch>> good_matches;

	for (auto& m : all_matches)
	{
		double dist = m.distance;

		if (dist < min_dist)
		{
			min_dist = dist;
		}
	}

	const double allowed_distance = GlobalSettings::simple_match_distance_coef * min_dist;

	for (auto& m : all_matches)
	{
		if (m.distance <= allowed_distance)
		{
			good_matches.push_back(m);
		}
	}

	if (GlobalSettings::use_ransac_filterring)
	{
		Mat fundamental = ransac_filter(good_matches, left->get_keypoints(), right->get_keypoints());
	}
	else
	{
		matches = good_matches;
	}
}

void ImageMatcher::knn_match()
{
	vector<vector<DMatch>> left_to_right_matches;
	vector<vector<DMatch>> right_to_left_matches;

	matcher.knnMatch(left->get_descriptors(),  right->get_descriptors(), left_to_right_matches, 2);
	matcher.knnMatch(right->get_descriptors(), left->get_descriptors(),  right_to_left_matches, 2);

	int removed_left_to_right = ratio_filter(left_to_right_matches);
	int removed_right_to_left = ratio_filter(right_to_left_matches);

	vector<DMatch> symmetrical_matches;
	symmetry_filter(left_to_right_matches, right_to_left_matches, symmetrical_matches);

	if (GlobalSettings::use_ransac_filterring)
	{
		Mat fundamental = ransac_filter(symmetrical_matches, left->get_keypoints(), right->get_keypoints());
	}
	else
	{
		matches = symmetrical_matches;
	}
}

int ImageMatcher::ratio_filter(vector<vector<DMatch>>& matches)
{
	int removed = 0;
	
	for (vector<vector<DMatch>>::iterator match_iterator = matches.begin(); match_iterator != matches.end(); ++match_iterator)
	{
		// if 2 NN has been identified
		if (match_iterator->size() > 1)
		{
			// check distance ratio
			if (((*match_iterator)[0].distance / (*match_iterator)[1].distance) > GlobalSettings::knn_match_distance_ratio)
			{
				match_iterator->clear(); // remove match
				removed++;
			}
		}
		else
		{ // does not have 2 neighbours
			match_iterator->clear(); // remove match
			removed++;
		}
	}

	return removed;
}

void ImageMatcher::symmetry_filter(const vector<vector<DMatch>>& matches1,
								   const vector<vector<DMatch>>& matches2,
								   vector<DMatch>& symmetrical_matches)
{
	// for all matches image 1 -> image 2
	for (vector<vector<DMatch>>::const_iterator match_iterator1 = matches1.begin();
		 match_iterator1 != matches1.end();
		 ++match_iterator1)
	{
		// ignore deleted matches
		if (match_iterator1->size() < 2)
		{
			continue;
		}

		// for all matches image 2 -> image 1
		for (vector<vector<DMatch>>::const_iterator match_iterator2 = matches2.begin();
			 match_iterator2 != matches2.end();
			 ++match_iterator2)
		{
			// ignore deleted matches
			if (match_iterator2->size() < 2)
			{
				continue;
			}

			// Match symmetry test
			if ((*match_iterator1)[0].queryIdx == (*match_iterator2)[0].trainIdx &&
				(*match_iterator2)[0].queryIdx == (*match_iterator1)[0].trainIdx)
			{
				// add symmetrical match
				symmetrical_matches.push_back(DMatch((*match_iterator1)[0].queryIdx,
													 (*match_iterator1)[0].trainIdx,
													 (*match_iterator1)[0].distance));


				break; // next match in image 1 -> image 2
			}
		}
	}
}

/*
	It cannot deal with rotation.
*/
Mat ImageMatcher::ransac_filter(const vector<DMatch>&   all_matches,
								const vector<KeyPoint>& keypoints1,
								const vector<KeyPoint>& keypoints2)
{
	// Convert keypoints into Point2f
	vector<Point2f> points1, points2;
	Mat fundemental;

	for (vector<DMatch>::const_iterator it = all_matches.begin(); it != all_matches.end(); ++it)
	{
		// Get the position of left keypoints
		float x = keypoints1[it->queryIdx].pt.x;
		float y = keypoints1[it->queryIdx].pt.y;
		points1.push_back(Point2f(x, y));

		// Get the position of right keypoints
		x = keypoints2[it->trainIdx].pt.x;
		y = keypoints2[it->trainIdx].pt.y;
		points2.push_back(Point2f(x, y));
	}

	// Compute F matrix using RANSAC
	vector<uchar> inliers(points1.size(), 0);

	if (points1.size() > 0 && points2.size() > 0)
	{
		Mat fundemental = findFundamentalMat(Mat(points1), Mat(points2),		 // matching points
											 inliers,							 // match status (inlier or outlier)
											 CV_FM_RANSAC,						 // RANSAC method
											 GlobalSettings::ransac_distance,    // distance to epipolar line
											 GlobalSettings::ransac_confidence); // confidence probability

		// extract the surviving (inliers) matches
		vector<uchar>::const_iterator  inliers_iterator		= inliers.begin();
		vector<DMatch>::const_iterator all_matches_iterator = all_matches.begin();

		// for all matches
		for (; inliers_iterator != inliers.end(); ++inliers_iterator, ++all_matches_iterator)
		{
			if (*inliers_iterator)
			{ // it is a valid match
				matches.push_back(*all_matches_iterator);
			}
		}

		if (GlobalSettings::ransac_refine_fundamental_matrix)
		{
			// The F matrix will be recomputed with
			// all accepted matches
			// Convert keypoints into Point2f
			// for final F computation
			points1.clear();
			points2.clear();

			for (vector<DMatch>::const_iterator iterator = matches.begin(); iterator != matches.end(); ++iterator)
			{
				// Get the position of left keypoints
				float x = keypoints1[iterator->queryIdx].pt.x;
				float y = keypoints1[iterator->queryIdx].pt.y;
				points1.push_back(Point2f(x, y));

				// Get the position of right keypoints
				x = keypoints2[iterator->trainIdx].pt.x;
				y = keypoints2[iterator->trainIdx].pt.y;
				points2.push_back(Point2f(x, y));
			}

			// Compute 8-point F from all accepted matches
			if (points1.size() > 0 && points2.size() > 0)
			{
				fundemental = findFundamentalMat(Mat(points1), Mat(points2), // matches
												 CV_FM_8POINT); // 8-point method
			}
		}
	}
	return fundemental;
}

/*
	Requires at least 4 matching points.
*/
void ImageMatcher::display_homography()
{
	if (!GlobalSettings::display_homography || matches_drawing.empty() || matches.size() < 4)
	{
		return;
	}

	vector<KeyPoint> object_keypoints = left->get_keypoints();
	vector<KeyPoint> scene_keypoints  = right->get_keypoints();

	vector<Point2f> object_points;
	vector<Point2f> scene_points;

	for (auto& m : matches)
	{
		object_points.push_back(object_keypoints[m.queryIdx].pt);
		scene_points.push_back(scene_keypoints[m.trainIdx].pt);
	}

	Mat homography = findHomography(object_points, scene_points, CV_RANSAC);

	Mat left_image = left->get_grayscale_image();

	// Get the corners from the left image (the object to be "detected")
	vector<Point2f> object_corners(4);

	object_corners[0] = cvPoint(0, 0);
	object_corners[1] = cvPoint(left_image.cols, 0);
	object_corners[2] = cvPoint(left_image.cols, left_image.rows);
	object_corners[3] = cvPoint(0, left_image.rows);

	vector<Point2f> scene_corners(4);

	perspectiveTransform(object_corners, scene_corners, homography);

	Point2f x_offset = Point2f(left_image.cols, 0);
	Scalar scalar = Scalar(0, 255, 0);
	int thickness = 2;

	// Draw lines between the corners (the mapped object in the scene - right image)
	line(matches_drawing, scene_corners[0] + x_offset, scene_corners[1] + x_offset, scalar, thickness);
	line(matches_drawing, scene_corners[1] + x_offset, scene_corners[2] + x_offset, scalar, thickness);
	line(matches_drawing, scene_corners[2] + x_offset, scene_corners[3] + x_offset, scalar, thickness);
	line(matches_drawing, scene_corners[3] + x_offset, scene_corners[0] + x_offset, scalar, thickness);
}
