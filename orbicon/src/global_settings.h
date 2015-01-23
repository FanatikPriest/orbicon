#pragma once

namespace orbicon {
	class GlobalSettings;
}

class orbicon::GlobalSettings {
public:
	/*
		A flag wheter or not to use knn matching.
		Default: true
	*/
	static bool use_knn_match;

	/*
		The number of features to be found.
		Default: 500
	*/
	static int features_number;

	/*
		The minimum distance ratio used in knn matching.
		Default: 0.7
	*/
	static double knn_match_distance_ratio;

	/*
		The multiplier of the minimum distance. Used in non-knn matching.
		Default: 1.35
	*/
	static double match_distance_coef;
};