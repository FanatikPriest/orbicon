#pragma once

#include <QtWidgets/QDialog>

#include "ui_settings_dialog.h"

class SettingsDialog : public QDialog
{
	Q_OBJECT

public:
	SettingsDialog(QWidget *parent = 0, Qt::WindowFlags f = 0);
	~SettingsDialog();

public slots:
	void accept();
	void use_knn_match_check_box_state_changed();
	void use_ransac_filterring_check_box_state_changed();
	void resize_input_image_check_box_state_changed();
	void crop_image_check_box_state_changed();

private:
	Ui::SettingsDialogClass ui;

	void setup_actions();
	void do_actions();

	void populate_settings_in_dialog();
	void fetch_settings_from_dialog();
};