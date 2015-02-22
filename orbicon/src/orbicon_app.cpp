#include <qfiledialog.h>
#include <qmessagebox.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/gpu/gpu.hpp>

#include "orbicon_app.h"

#include "image_matcher.h"
#include "global_settings.h"

OrbiconApp::OrbiconApp(QWidget *parent) : QMainWindow(parent)
{
	subject = NULL;
	scene   = NULL;

	ui.setupUi(this);

	setup_actions();
}

OrbiconApp::~OrbiconApp()
{
	delete scene;
	delete subject;
}

void OrbiconApp::on_action_open_image_triggered()
{
	QString filename = open_single_image();

	delete subject;

	subject = new Image(filename.toStdString());
}

void OrbiconApp::on_action_add_images_to_catalog_triggered()
{
	QString filename = open_single_image();

	delete scene;

	scene = new Image(filename.toStdString());
}

void OrbiconApp::on_action_match_triggered()
{
	if (subject == NULL || scene == NULL)
	{
		QMessageBox::information(this, tr("Load Images"), tr("You need to open a subject image and add some images in the catalog before matching."));

		return;
	}

	match();
}

void OrbiconApp::setup_actions()
{
	connect(ui.action_Open_Image, SIGNAL(triggered()), this, SLOT(on_action_open_image_triggered()));
	connect(ui.action_Add_Images_to_Catalog, SIGNAL(triggered()), this, SLOT(on_action_add_images_to_catalog_triggered()));
	connect(ui.action_Match, SIGNAL(triggered()), this, SLOT(on_action_match_triggered()));
}

QString OrbiconApp::open_single_image()
{
	QString filename = QFileDialog::getOpenFileName(
		this,
		tr("Open File"),
		"C://",
		tr("Images (*.png *.jpg *.jpeg *.bmp)")
	);

	return QDir::toNativeSeparators(filename);
}

void OrbiconApp::match()
{
	GlobalSettings::use_knn_match = true;

	ImageMatcher matcher(*subject, *scene);

	namedWindow("KNN matching", WINDOW_AUTOSIZE);
	imshow("KNN matching", matcher.get_matches_drawing());

	GlobalSettings::use_knn_match = false;

	matcher.match();

	namedWindow("Simple matching", WINDOW_AUTOSIZE);
	imshow("Simple matching", matcher.get_matches_drawing());

	waitKey(0); // Wait for a keystroke in the window
}