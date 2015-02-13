#include "global_settings.h"

using namespace orbicon;

bool   GlobalSettings::use_knn_match                    = true;
int    GlobalSettings::features_number                  = 1500;
double GlobalSettings::knn_match_distance_ratio         = 0.65;
double GlobalSettings::simple_match_distance_coef       = 1.35;
bool   GlobalSettings::use_ransac_filterring            = true;
double GlobalSettings::ransac_distance                  = 1.0;
double GlobalSettings::ransac_confidence                = 0.98;
bool   GlobalSettings::ransac_refine_fundamental_matrix = true;
bool   GlobalSettings::display_homography               = true;
bool   GlobalSettings::resize_input_image               = true;
int    GlobalSettings::input_image_max_dimmesion_size   = 500;
bool   GlobalSettings::crop_image                       = true;
int    GlobalSettings::crop_padding                     = 20;

GlobalSettings::GrayscaleResize GlobalSettings::grayscale_resize_mode = Original;