#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_orbicon_app.h"

#include "image.h"

using namespace cv;
using namespace gpu;
using namespace orbicon;
using namespace std;

class OrbiconApp : public QMainWindow
{
	Q_OBJECT

public:
	OrbiconApp(QWidget *parent = 0);
	~OrbiconApp();

public slots:
	void on_action_open_image_triggered();
	void on_action_add_images_to_catalog_triggered();
	void on_action_match_triggered();
	void on_action_settings_triggered();

private:
	Ui::OrbiconAppClass ui;

	Image* subject;
	Image* scene;

	void setup_actions();

	QString open_single_image();

	void match();
};