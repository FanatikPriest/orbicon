#pragma once

#include <QtWidgets/QFrame>

#include "ui_main_image_container.h"

class MainImageContainer : public QFrame
{
	Q_OBJECT

public:
	MainImageContainer(QWidget *parent = 0);
	~MainImageContainer();

private:
	Ui::MainImageContainerClass ui;
};

