#include "settings_dialog.h"

#include "global_settings.h"

using namespace orbicon;

SettingsDialog::SettingsDialog(QWidget *parent, Qt::WindowFlags f) : QDialog(parent, f)
{
	ui.setupUi(this);

	populate_settings_in_dialog();

	setup_actions();

	do_actions();
}

SettingsDialog::~SettingsDialog()
{

}

void SettingsDialog::accept()
{
	fetch_settings_from_dialog();
	QDialog::accept();
}

void SettingsDialog::use_knn_match_check_box_state_changed()
{
	bool is_checked = ui.use_knn_match_check_box->isChecked();

	ui.knn_match_distance_ratio_double_spin_box->setEnabled(is_checked);
}

void SettingsDialog::use_ransac_filterring_check_box_state_changed()
{
	bool is_checked = ui.use_ransac_filterring_check_box->isChecked();

	ui.ransac_distance_double_spin_box->setEnabled(is_checked);
	ui.ransac_confidence_double_spin_box->setEnabled(is_checked);
	ui.ransac_refine_fundamental_matrix_check_box->setEnabled(is_checked);
}

void SettingsDialog::resize_input_image_check_box_state_changed()
{
	bool is_checked = ui.resize_input_image_check_box->isChecked();

	ui.input_image_max_dimmension_size_spin_box->setEnabled(is_checked);
}

void SettingsDialog::crop_image_check_box_state_changed()
{
	bool is_checked = ui.crop_image_check_box->isChecked();

	ui.crop_padding_spin_box->setEnabled(is_checked);
}

void SettingsDialog::setup_actions()
{
	connect(ui.use_knn_match_check_box, SIGNAL(stateChanged(int)), this, SLOT(use_knn_match_check_box_state_changed()));
	connect(ui.use_ransac_filterring_check_box, SIGNAL(stateChanged(int)), this, SLOT(use_ransac_filterring_check_box_state_changed()));
	connect(ui.resize_input_image_check_box, SIGNAL(stateChanged(int)), this, SLOT(resize_input_image_check_box_state_changed()));
	connect(ui.crop_image_check_box, SIGNAL(stateChanged(int)), this, SLOT(crop_image_check_box_state_changed()));
}

void SettingsDialog::do_actions()
{
	use_knn_match_check_box_state_changed();
	use_ransac_filterring_check_box_state_changed();
	resize_input_image_check_box_state_changed();
	crop_image_check_box_state_changed();
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
	ui.grayscale_resize_mode_combo_box->setCurrentIndex((int)GlobalSettings::grayscale_resize_mode);
}

void SettingsDialog::fetch_settings_from_dialog()
{
	GlobalSettings::use_knn_match                    = ui.use_knn_match_check_box->isChecked();
	GlobalSettings::features_number                  = ui.features_number_spin_box->value();
	GlobalSettings::knn_match_distance_ratio         = ui.knn_match_distance_ratio_double_spin_box->value();
	GlobalSettings::simple_match_distance_coef       = ui.simple_match_distance_coef_double_spin_box->value();
	GlobalSettings::use_ransac_filterring            = ui.use_ransac_filterring_check_box->isChecked();
	GlobalSettings::ransac_distance                  = ui.ransac_distance_double_spin_box->value();
	GlobalSettings::ransac_confidence                = ui.ransac_confidence_double_spin_box->value();
	GlobalSettings::ransac_refine_fundamental_matrix = ui.ransac_refine_fundamental_matrix_check_box->isChecked();
	GlobalSettings::display_homography               = ui.display_homography_check_box->isChecked();
	GlobalSettings::resize_input_image               = ui.resize_input_image_check_box->isChecked();
	GlobalSettings::input_image_max_dimmesion_size   = ui.input_image_max_dimmension_size_spin_box->value();
	GlobalSettings::crop_image                       = ui.crop_image_check_box->isChecked();
	GlobalSettings::crop_padding                     = ui.crop_padding_spin_box->value();
	GlobalSettings::grayscale_resize_mode            = (GlobalSettings::GrayscaleResize)ui.grayscale_resize_mode_combo_box->currentIndex();
}