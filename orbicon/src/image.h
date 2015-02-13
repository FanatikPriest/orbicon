#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>

using namespace cv;

namespace orbicon {
	class Image;
}

class orbicon::Image {
public:
	Image(const string image_path);
	Image(const string image_path, Mat descriptors);
	Image(const string image_path, Mat descriptors, vector<KeyPoint> keypoints);

	const string get_image_path() const;
	Mat& get_image();
	Mat& get_grayscale_image();
	Mat& get_descriptors();
	vector<KeyPoint>& get_keypoints();

	Mat grayscale_with_keypoints();

private:
	string image_path;
	Mat image;
	Mat grayscale_image;
	Mat descriptors;
	vector<KeyPoint> keypoints;

	Image();

	void generate_image();
	void generate_grayscale_image();
	void generate_descriptors_and_keypoints(); // TODO research how this can be split-up

	Mat resize_grayscale_image(const Mat some_image);
	Mat crop_image(const Mat some_image);
};