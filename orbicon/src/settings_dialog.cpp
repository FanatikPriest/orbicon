#include "settings_dialog.h"

#include "global_settings.h"

using namespace orbicon;

SettingsDialog::SettingsDialog(QWidget *parent, Qt::WindowFlags f) : QDialog(parent, f)
{
	ui.setupUi(this);

	populate_settings_in_dialog();
}

SettingsDialog::~SettingsDialog()
{

}

void SettingsDialog::populate_settings_in_dialog()
{
	ui.use_knn_match_check_box->setChecked(GlobalSettings::use_knn_match);
	ui.features_number_spin_box->setValue(GlobalSettings::features_number);
	ui.knn_match_distance_ratio_double_spin_box->setValue(GlobalSettings::knn_match_distance_ratio);
	ui.simple_match_distance_coef_double_spin_box->setValue(GlobalSettings::simple_match_distance_coef);
	ui.use_ransac_filterring_check_box->setChecked(GlobalSettings::use_ransac_filterring);
	ui.ransac_distance_double_spin_box->setValue(GlobalSettings::ransac_distance);
	ui.ransac_confidence_double_spin_box->setValue(GlobalSettings::ransac_confidence);
	ui.ransac_refine_fundamental_matrix_check_box->setChecked(GlobalSettings::ransac_refine_fundamental_matrix);
	ui.display_homography_check_box->setChecked(GlobalSettings::display_homography);
	ui.resize_input_image_check_box->setChecked(GlobalSettings::resize_input_image);
	ui.input_image_max_dimmension_size_spin_box->setValue(GlobalSettings::input_image_max_dimmesion_size);
	ui.crop_image_check_box->setChecked(GlobalSettings::crop_image);
	ui.crop_padding_spin_box->setValue(GlobalSettings::crop_padding);
}

void SettingsDialog::fetch_settings_from_dialog()
{
	bool stuff_1 = ui.use_knn_match_check_box->isChecked();

	int stuff_2 = ui.features_number_spin_box->value();
}