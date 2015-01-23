#include "image_matcher.h"
#include "global_settings.h"

using namespace orbicon;

ImageMatcher::ImageMatcher() {}

ImageMatcher::ImageMatcher(Image& left, Image& right, bool use_good_matches)
{
	this->left  = &left;
	this->right = &right;

	this->use_good_matches = use_good_matches;

	this->matcher = BFMatcher(NORM_HAMMING);

	match();
	knn_match();
}

vector<DMatch, allocator<DMatch>> ImageMatcher::get_matches()
{
	return matches;
}

vector<vector<DMatch>> ImageMatcher::get_knn_matches()
{
	return knn_matches;
}

vector<DMatch, allocator<DMatch>> ImageMatcher::get_good_matches()
{
	double min_dist = 10000;

	vector<DMatch, allocator<DMatch>> matches = get_matches();
	vector<DMatch, allocator<DMatch>> good_matches;

	for (auto & m : matches)
	{
		double dist = m.distance;

		if (dist < min_dist)
		{
			min_dist = dist;
		}
	}

	for (auto & m : matches)
	{
		if (m.distance <= GlobalSettings::match_distance_coef * min_dist)
		{
			good_matches.push_back(m);
		}
	}
	
	return good_matches;
}

vector<DMatch, allocator<DMatch>> ImageMatcher::get_good_knn_matches()
{
	vector<DMatch, allocator<DMatch>> good_matches;
	vector<vector<DMatch>> matches = get_knn_matches();

	for (auto & m : matches)
	{
		if (m[0].distance <= GlobalSettings::knn_match_distance_ratio * m[1].distance)
		{
			good_matches.push_back(m[0]);
		}
	}

	return good_matches;
}

Mat& ImageMatcher::get_matches_drawing()
{
	if (matches_drawing.empty())
	{

		vector<DMatch, allocator<DMatch>> matches = GlobalSettings::use_knn_match ? get_good_knn_matches () : get_good_matches();

		drawMatches(left->get_grayscale_image(), left->get_keypoints(),
					right->get_grayscale_image(), right->get_keypoints(),
					matches, matches_drawing,
					Scalar::all(-1), Scalar::all(1),
					vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	}

	return matches_drawing;
}

void ImageMatcher::match()
{
	matcher.match(left->get_descriptors(), right->get_descriptors(), matches);
}

void ImageMatcher::knn_match()
{
	matcher.knnMatch(left->get_descriptors(), right->get_descriptors(), knn_matches, 2);
}