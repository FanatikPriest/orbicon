#pragma once

#include "image.h"

namespace orbicon {
	class ImageMatcher;
}

using namespace orbicon;
using namespace cv;
using namespace std;

/*
	Finds the matching keypoint of two images.
	Does the matching on instance creation.
	Provides drawing of images and matching keypoints.
*/
class orbicon::ImageMatcher {
public:
	ImageMatcher(Image& left, Image& right);

	vector<DMatch, allocator<DMatch>> get_matches();
	Mat& get_matches_drawing();

	void match();
	void clear();

private:
	Image* left;
	Image* right;
		
	BFMatcher matcher;
	vector<DMatch, allocator<DMatch>> matches;
	Mat matches_drawing;
		
	ImageMatcher();

	void clear_matches();
	void clear_matches_drawing();

	void simple_match();
	void knn_match();

	int ratio_filter(vector<vector<DMatch>>& matches);
	void symmetry_filter(const vector<vector<DMatch>>& matches1,
						 const vector<vector<DMatch>>& matches2,
						 vector<DMatch>& symmetrical_matches);
	Mat ransac_filter(const vector<DMatch>& all_matches,
					  const vector<KeyPoint>& keypoints1,
					  const vector<KeyPoint>& keypoints2);
};