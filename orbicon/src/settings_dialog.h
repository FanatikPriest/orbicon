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

private:
	Ui::SettingsDialogClass ui;

	void populate_settings_in_dialog();
	void fetch_settings_from_dialog();
};