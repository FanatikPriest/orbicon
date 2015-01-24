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
};