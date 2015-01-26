#include "global_settings.h"

bool   orbicon::GlobalSettings::use_knn_match                    = true;
int    orbicon::GlobalSettings::features_number                  = 1500;
double orbicon::GlobalSettings::knn_match_distance_ratio         = 0.65;
double orbicon::GlobalSettings::simple_match_distance_coef       = 1.35;
bool   orbicon::GlobalSettings::use_ransac_filterring            = true;
double orbicon::GlobalSettings::ransac_distance                  = 1.0;
double orbicon::GlobalSettings::ransac_confidence                = 0.98;
bool   orbicon::GlobalSettings::ransac_refine_fundamental_matrix = true;
bool   orbicon::GlobalSettings::display_homography               = true;