#pragma once

namespace orbicon {
	class GlobalSettings;
}

class orbicon::GlobalSettings {
public:
	static bool   use_knn_match;       // default: true
	static int    features_number;     // default: 500
	static double knn_match_distance;  // default: 0.7
	static double match_distance;      // default: 1.35
};