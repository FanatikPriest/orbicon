#pragma once

namespace orbicon {
	class GlobalSettings;
}

class orbicon::GlobalSettings {
public:
	/*
		A flag whether or not to use knn matching.
		Default: true
	*/
	static bool use_knn_match;

	/*
		The number of features to be found.
		Default: 1500
	*/
	static int features_number;

	/*
		The minimum distance ratio used in knn matching.
		Default: 0.65
	*/
	static double knn_match_distance_ratio;

	/*
		The multiplier of the minimum distance used in simple matching.
		Default: 1.35
	*/
	static double simple_match_distance_coef;

	/*
		A flag whether or not to use RANSAC filterring in KNN.
		Default: true
	*/
	static bool use_ransac_filterring;

	/*
		The minimal distance to epipolar line in RANSAC.
		Default: 1.0
	*/
	static double ransac_distance;

	/*
		The confidence level (probability) in RANSAC.
		Default: 0.98
	*/
	static double ransac_confidence;

	/*
		A flag whether or not to refine the fundamental matrix at the end of the RANSAC filterring.
		Default: true
	*/
	static bool ransac_refine_fundamental_matrix;

	/*
		A flag whether or not to to display the homography of the left image on the right image.
		Default: true
	*/
	static bool display_homography;

	/*
		A flag whether or not to resize bigger input images. See GlobalSettings::input_image_max_dimmesion_size
		for further info.
		Default: true
	*/
	static bool resize_input_image;

	/*
		The maximum size of any of the dimensions of the input image. If the input image has smaller than
		this number, then it would not be resized. Otherwise it will be resized so it proportionally fit the
		square defined by this measure.
		Default: 500
	*/
	static int input_image_max_dimmesion_size;

	/*
		The mode of grayscale image size manipulation before running the descriptor.

		Original       - Does not resize the image.
		Shrink         - Resizes the image to half its size.
		BlurByResizing - This will shrink the image to half its size and then will expand it back to full size.
	*/
	enum GrayscaleResize { Original, Shrink, BlurByResizing };

	/*
		The chosen grayscale image resize mode
		Default: Original
	*/
	static GrayscaleResize grayscale_resize_mode;
};