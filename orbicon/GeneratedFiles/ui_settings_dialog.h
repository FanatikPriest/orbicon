/********************************************************************************
** Form generated from reading UI file 'settings_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_DIALOG_H
#define UI_SETTINGS_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialogClass
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *features_number_spin_box;
    QCheckBox *display_homography_check_box;
    QDoubleSpinBox *simple_match_distance_coef_double_spin_box;
    QDoubleSpinBox *knn_match_distance_ratio_double_spin_box;
    QCheckBox *use_knn_match_check_box;
    QLabel *features_number_label;
    QLabel *knn_match_distance_ratio_label;
    QLabel *simple_match_distance_coef_label;
    QCheckBox *use_ransac_filterring_check_box;
    QDoubleSpinBox *ransac_distance_double_spin_box;
    QLabel *ransac_distance_label;
    QDoubleSpinBox *ransac_confidence_double_spin_box;
    QLabel *ransac_confidence_label;
    QCheckBox *ransac_refine_fundamental_matrix_check_box;
    QCheckBox *resize_input_image_check_box;
    QSpinBox *input_image_max_dimmension_size_spin_box;
    QLabel *input_image_max_dimmension_size_label;
    QFrame *line;
    QCheckBox *crop_image_check_box;
    QLabel *crop_padding_label;
    QSpinBox *crop_padding_spin_box;

    void setupUi(QDialog *SettingsDialogClass)
    {
        if (SettingsDialogClass->objectName().isEmpty())
            SettingsDialogClass->setObjectName(QStringLiteral("SettingsDialogClass"));
        SettingsDialogClass->setWindowModality(Qt::NonModal);
        SettingsDialogClass->resize(500, 310);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingsDialogClass->sizePolicy().hasHeightForWidth());
        SettingsDialogClass->setSizePolicy(sizePolicy);
        SettingsDialogClass->setWindowOpacity(1);
        SettingsDialogClass->setModal(true);
        buttonBox = new QDialogButtonBox(SettingsDialogClass);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(170, 270, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        features_number_spin_box = new QSpinBox(SettingsDialogClass);
        features_number_spin_box->setObjectName(QStringLiteral("features_number_spin_box"));
        features_number_spin_box->setGeometry(QRect(180, 50, 61, 20));
        features_number_spin_box->setMinimum(100);
        features_number_spin_box->setMaximum(3000);
        display_homography_check_box = new QCheckBox(SettingsDialogClass);
        display_homography_check_box->setObjectName(QStringLiteral("display_homography_check_box"));
        display_homography_check_box->setGeometry(QRect(260, 20, 221, 17));
        simple_match_distance_coef_double_spin_box = new QDoubleSpinBox(SettingsDialogClass);
        simple_match_distance_coef_double_spin_box->setObjectName(QStringLiteral("simple_match_distance_coef_double_spin_box"));
        simple_match_distance_coef_double_spin_box->setGeometry(QRect(180, 110, 61, 20));
        simple_match_distance_coef_double_spin_box->setMinimum(1);
        simple_match_distance_coef_double_spin_box->setSingleStep(0.01);
        knn_match_distance_ratio_double_spin_box = new QDoubleSpinBox(SettingsDialogClass);
        knn_match_distance_ratio_double_spin_box->setObjectName(QStringLiteral("knn_match_distance_ratio_double_spin_box"));
        knn_match_distance_ratio_double_spin_box->setGeometry(QRect(180, 80, 61, 20));
        knn_match_distance_ratio_double_spin_box->setMinimum(0.1);
        knn_match_distance_ratio_double_spin_box->setMaximum(0.99);
        knn_match_distance_ratio_double_spin_box->setSingleStep(0.01);
        use_knn_match_check_box = new QCheckBox(SettingsDialogClass);
        use_knn_match_check_box->setObjectName(QStringLiteral("use_knn_match_check_box"));
        use_knn_match_check_box->setGeometry(QRect(20, 20, 221, 17));
        features_number_label = new QLabel(SettingsDialogClass);
        features_number_label->setObjectName(QStringLiteral("features_number_label"));
        features_number_label->setGeometry(QRect(20, 50, 151, 16));
        knn_match_distance_ratio_label = new QLabel(SettingsDialogClass);
        knn_match_distance_ratio_label->setObjectName(QStringLiteral("knn_match_distance_ratio_label"));
        knn_match_distance_ratio_label->setGeometry(QRect(20, 80, 151, 16));
        simple_match_distance_coef_label = new QLabel(SettingsDialogClass);
        simple_match_distance_coef_label->setObjectName(QStringLiteral("simple_match_distance_coef_label"));
        simple_match_distance_coef_label->setGeometry(QRect(20, 110, 151, 16));
        use_ransac_filterring_check_box = new QCheckBox(SettingsDialogClass);
        use_ransac_filterring_check_box->setObjectName(QStringLiteral("use_ransac_filterring_check_box"));
        use_ransac_filterring_check_box->setGeometry(QRect(20, 140, 221, 17));
        ransac_distance_double_spin_box = new QDoubleSpinBox(SettingsDialogClass);
        ransac_distance_double_spin_box->setObjectName(QStringLiteral("ransac_distance_double_spin_box"));
        ransac_distance_double_spin_box->setGeometry(QRect(180, 170, 61, 20));
        ransac_distance_double_spin_box->setSingleStep(0.01);
        ransac_distance_label = new QLabel(SettingsDialogClass);
        ransac_distance_label->setObjectName(QStringLiteral("ransac_distance_label"));
        ransac_distance_label->setGeometry(QRect(20, 170, 151, 16));
        ransac_confidence_double_spin_box = new QDoubleSpinBox(SettingsDialogClass);
        ransac_confidence_double_spin_box->setObjectName(QStringLiteral("ransac_confidence_double_spin_box"));
        ransac_confidence_double_spin_box->setGeometry(QRect(180, 200, 61, 20));
        ransac_confidence_double_spin_box->setSingleStep(0.01);
        ransac_confidence_label = new QLabel(SettingsDialogClass);
        ransac_confidence_label->setObjectName(QStringLiteral("ransac_confidence_label"));
        ransac_confidence_label->setGeometry(QRect(20, 200, 151, 16));
        ransac_refine_fundamental_matrix_check_box = new QCheckBox(SettingsDialogClass);
        ransac_refine_fundamental_matrix_check_box->setObjectName(QStringLiteral("ransac_refine_fundamental_matrix_check_box"));
        ransac_refine_fundamental_matrix_check_box->setGeometry(QRect(20, 230, 221, 17));
        resize_input_image_check_box = new QCheckBox(SettingsDialogClass);
        resize_input_image_check_box->setObjectName(QStringLiteral("resize_input_image_check_box"));
        resize_input_image_check_box->setGeometry(QRect(260, 50, 221, 17));
        input_image_max_dimmension_size_spin_box = new QSpinBox(SettingsDialogClass);
        input_image_max_dimmension_size_spin_box->setObjectName(QStringLiteral("input_image_max_dimmension_size_spin_box"));
        input_image_max_dimmension_size_spin_box->setGeometry(QRect(420, 80, 61, 22));
        input_image_max_dimmension_size_spin_box->setMinimum(300);
        input_image_max_dimmension_size_spin_box->setMaximum(1000);
        input_image_max_dimmension_size_label = new QLabel(SettingsDialogClass);
        input_image_max_dimmension_size_label->setObjectName(QStringLiteral("input_image_max_dimmension_size_label"));
        input_image_max_dimmension_size_label->setGeometry(QRect(260, 80, 161, 16));
        line = new QFrame(SettingsDialogClass);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(240, 20, 21, 231));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        crop_image_check_box = new QCheckBox(SettingsDialogClass);
        crop_image_check_box->setObjectName(QStringLiteral("crop_image_check_box"));
        crop_image_check_box->setGeometry(QRect(260, 110, 221, 17));
        crop_padding_label = new QLabel(SettingsDialogClass);
        crop_padding_label->setObjectName(QStringLiteral("crop_padding_label"));
        crop_padding_label->setGeometry(QRect(260, 140, 151, 16));
        crop_padding_spin_box = new QSpinBox(SettingsDialogClass);
        crop_padding_spin_box->setObjectName(QStringLiteral("crop_padding_spin_box"));
        crop_padding_spin_box->setGeometry(QRect(420, 140, 61, 22));
        crop_padding_spin_box->setMaximum(45);

        retranslateUi(SettingsDialogClass);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsDialogClass, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialogClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsDialogClass);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialogClass)
    {
        SettingsDialogClass->setWindowTitle(QApplication::translate("SettingsDialogClass", "Settings", 0));
        display_homography_check_box->setText(QApplication::translate("SettingsDialogClass", "Display homography", 0));
        use_knn_match_check_box->setText(QApplication::translate("SettingsDialogClass", "Use KNN matching", 0));
        features_number_label->setText(QApplication::translate("SettingsDialogClass", "Number of features", 0));
        knn_match_distance_ratio_label->setText(QApplication::translate("SettingsDialogClass", "KNN match distance ratio", 0));
        simple_match_distance_coef_label->setText(QApplication::translate("SettingsDialogClass", "Simple match distance coef", 0));
        use_ransac_filterring_check_box->setText(QApplication::translate("SettingsDialogClass", "Use RANSAC filterring", 0));
        ransac_distance_label->setText(QApplication::translate("SettingsDialogClass", "RANSAC distance", 0));
        ransac_confidence_label->setText(QApplication::translate("SettingsDialogClass", "RANSAC confidence", 0));
        ransac_refine_fundamental_matrix_check_box->setText(QApplication::translate("SettingsDialogClass", "RANSAC refine fundamental matrix", 0));
        resize_input_image_check_box->setText(QApplication::translate("SettingsDialogClass", "Resize input image", 0));
        input_image_max_dimmension_size_label->setText(QApplication::translate("SettingsDialogClass", "Input image max dimenssion size", 0));
        crop_image_check_box->setText(QApplication::translate("SettingsDialogClass", "Crop image", 0));
        crop_padding_label->setText(QApplication::translate("SettingsDialogClass", "Crop padding", 0));
        crop_padding_spin_box->setSuffix(QApplication::translate("SettingsDialogClass", "%", 0));
        crop_padding_spin_box->setPrefix(QString());
    } // retranslateUi

};

namespace Ui {
    class SettingsDialogClass: public Ui_SettingsDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_DIALOG_H
