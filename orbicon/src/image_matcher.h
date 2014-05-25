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

private:
	Image* left;
	Image* right;
		
	BFMatcher matcher;
	vector<DMatch, allocator<DMatch>> matches;
	Mat matches_drawing;
		
	ImageMatcher();

	void match();
};