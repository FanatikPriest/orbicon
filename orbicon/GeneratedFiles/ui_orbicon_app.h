/********************************************************************************
** Form generated from reading UI file 'orbicon_app.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORBICON_APP_H
#define UI_ORBICON_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrbiconAppClass
{
public:
    QAction *action_Open_Image;
    QAction *action_Add_Images_to_Catalog;
    QAction *action_Match;
    QAction *action_Settings;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Options;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OrbiconAppClass)
    {
        if (OrbiconAppClass->objectName().isEmpty())
            OrbiconAppClass->setObjectName(QStringLiteral("OrbiconAppClass"));
        OrbiconAppClass->resize(600, 400);
        action_Open_Image = new QAction(OrbiconAppClass);
        action_Open_Image->setObjectName(QStringLiteral("action_Open_Image"));
        action_Add_Images_to_Catalog = new QAction(OrbiconAppClass);
        action_Add_Images_to_Catalog->setObjectName(QStringLiteral("action_Add_Images_to_Catalog"));
        action_Match = new QAction(OrbiconAppClass);
        action_Match->setObjectName(QStringLiteral("action_Match"));
        action_Settings = new QAction(OrbiconAppClass);
        action_Settings->setObjectName(QStringLiteral("action_Settings"));
        centralWidget = new QWidget(OrbiconAppClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        OrbiconAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OrbiconAppClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Options = new QMenu(menuBar);
        menu_Options->setObjectName(QStringLiteral("menu_Options"));
        OrbiconAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OrbiconAppClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        OrbiconAppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OrbiconAppClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OrbiconAppClass->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Options->menuAction());
        menu_File->addAction(action_Open_Image);
        menu_File->addAction(action_Add_Images_to_Catalog);
        menu_Options->addAction(action_Settings);
        mainToolBar->addAction(action_Match);

        retranslateUi(OrbiconAppClass);

        QMetaObject::connectSlotsByName(OrbiconAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *OrbiconAppClass)
    {
        OrbiconAppClass->setWindowTitle(QApplication::translate("OrbiconAppClass", "OrbiconApp", 0));
        action_Open_Image->setText(QApplication::translate("OrbiconAppClass", "&Open Image...", 0));
        action_Add_Images_to_Catalog->setText(QApplication::translate("OrbiconAppClass", "&Add Images to Catalog...", 0));
        action_Match->setText(QApplication::translate("OrbiconAppClass", "&Match", 0));
#ifndef QT_NO_TOOLTIP
        action_Match->setToolTip(QApplication::translate("OrbiconAppClass", "Match", 0));
#endif // QT_NO_TOOLTIP
        action_Settings->setText(QApplication::translate("OrbiconAppClass", "&Settings...", 0));
        menu_File->setTitle(QApplication::translate("OrbiconAppClass", "&File", 0));
        menu_Options->setTitle(QApplication::translate("OrbiconAppClass", "&Options", 0));
    } // retranslateUi

};

namespace Ui {
    class OrbiconAppClass: public Ui_OrbiconAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORBICON_APP_H
