#include "image_matcher.h"

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
			matches, matches_drawing);
	}

	return matches_drawing;
}

void ImageMatcher::match()
{
	matcher.match(left->get_descriptors(), right->get_descriptors(), matches);
}