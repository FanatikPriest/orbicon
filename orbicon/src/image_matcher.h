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
	ImageMatcher(Image& left, Image& right, bool use_good_matches = true);

	vector<DMatch, allocator<DMatch>> get_matches();
	vector<vector<DMatch>> get_knn_matches();
	vector<DMatch, allocator<DMatch>> get_good_matches();
	vector<DMatch, allocator<DMatch>> get_good_knn_matches();
	Mat& get_matches_drawing();

private:
	Image* left;
	Image* right;

	bool use_good_matches;
		
	BFMatcher matcher;
	vector<DMatch, allocator<DMatch>> matches;
	vector<vector<DMatch>> knn_matches;
	Mat matches_drawing;
		
	ImageMatcher();

	void match();
	void knn_match();
};