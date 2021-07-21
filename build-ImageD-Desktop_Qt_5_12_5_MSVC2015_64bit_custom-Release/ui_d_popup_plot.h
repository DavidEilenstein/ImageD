/********************************************************************************
** Form generated from reading UI file 'd_popup_plot.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_POPUP_PLOT_H
#define UI_D_POPUP_PLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_D_Popup_Plot
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_Trafo;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_CropMax_Y;
    QDoubleSpinBox *doubleSpinBox_CropMin_X;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_TrafoGamma_Y;
    QDoubleSpinBox *doubleSpinBox_TrafoGamma_X;
    QLabel *label_3;
    QFrame *line;
    QComboBox *comboBox_ModeCrop_X;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_TrafoDivisor_X;
    QLabel *label_10;
    QLabel *label_7;
    QComboBox *comboBox_ModeCrop_Y;
    QDoubleSpinBox *doubleSpinBox_CropMin_Y;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_TrafoDivisor_Y;
    QDoubleSpinBox *doubleSpinBox_CropMax_X;
    QDoubleSpinBox *doubleSpinBox_TrafoCenter_X;
    QComboBox *comboBox_ModeTrafo_X;
    QFrame *line_2;
    QDoubleSpinBox *doubleSpinBox_TrafoCenter_Y;
    QComboBox *comboBox_ModeTrafo_Y;
    QGroupBox *groupBox_PlotMode;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox_ModePlot;
    QGridLayout *gridLayout_Plot;

    void setupUi(QDialog *D_Popup_Plot)
    {
        if (D_Popup_Plot->objectName().isEmpty())
            D_Popup_Plot->setObjectName(QString::fromUtf8("D_Popup_Plot"));
        D_Popup_Plot->resize(1097, 537);
        gridLayout_2 = new QGridLayout(D_Popup_Plot);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_Trafo = new QGroupBox(D_Popup_Plot);
        groupBox_Trafo->setObjectName(QString::fromUtf8("groupBox_Trafo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_Trafo->sizePolicy().hasHeightForWidth());
        groupBox_Trafo->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(groupBox_Trafo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_8 = new QLabel(groupBox_Trafo);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 6, 1, 1);

        doubleSpinBox_CropMax_Y = new QDoubleSpinBox(groupBox_Trafo);
        doubleSpinBox_CropMax_Y->setObjectName(QString::fromUtf8("doubleSpinBox_CropMax_Y"));
        doubleSpinBox_CropMax_Y->setEnabled(false);
        doubleSpinBox_CropMax_Y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_CropMax_Y->setDecimals(3);
        doubleSpinBox_CropMax_Y->setMinimum(-999999999.000000000000000);
        doubleSpinBox_CropMax_Y->setMaximum(999999999.000000000000000);
        doubleSpinBox_CropMax_Y->setValue(255.000000000000000);

        gridLayout->addWidget(doubleSpinBox_CropMax_Y, 2, 4, 1, 1);

        doubleSpinBox_CropMin_X = new QDoubleSpinBox(groupBox_Trafo);
        doubleSpinBox_CropMin_X->setObjectName(QString::fromUtf8("doubleSpinBox_CropMin_X"));
        doubleSpinBox_CropMin_X->setEnabled(false);
        doubleSpinBox_CropMin_X->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_CropMin_X->setDecimals(3);
        doubleSpinBox_CropMin_X->setMinimum(-999999999.000000000000000);
        doubleSpinBox_CropMin_X->setMaximum(999999999.000000000000000);

        gridLayout->addWidget(doubleSpinBox_CropMin_X, 1, 3, 1, 1);

        label_6 = new QLabel(groupBox_Trafo);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 3, 1, 1);

        doubleSpinBox_TrafoGamma_Y = new QDoubleSpinBox(groupBox_Trafo);
        doubleSpinBox_TrafoGamma_Y->setObjectName(QString::fromUtf8("doubleSpinBox_TrafoGamma_Y"));
        doubleSpinBox_TrafoGamma_Y->setEnabled(false);
        doubleSpinBox_TrafoGamma_Y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_TrafoGamma_Y->setDecimals(3);
        doubleSpinBox_TrafoGamma_Y->setMinimum(0.000000000000000);
        doubleSpinBox_TrafoGamma_Y->setMaximum(1.000000000000000);
        doubleSpinBox_TrafoGamma_Y->setSingleStep(0.010000000000000);

        gridLayout->addWidget(doubleSpinBox_TrafoGamma_Y, 2, 7, 1, 1);

        doubleSpinBox_TrafoGamma_X = new QDoubleSpinBox(groupBox_Trafo);
        doubleSpinBox_TrafoGamma_X->setObjectName(QString::fromUtf8("doubleSpinBox_TrafoGamma_X"));
        doubleSpinBox_TrafoGamma_X->setEnabled(false);
        doubleSpinBox_TrafoGamma_X->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_TrafoGamma_X->setDecimals(3);
        doubleSpinBox_TrafoGamma_X->setMinimum(0.000000000000000);
        doubleSpinBox_TrafoGamma_X->setMaximum(1.000000000000000);
        doubleSpinBox_TrafoGamma_X->setSingleStep(0.010000000000000);

        gridLayout->addWidget(doubleSpinBox_TrafoGamma_X, 1, 7, 1, 1);

        label_3 = new QLabel(groupBox_Trafo);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        line = new QFrame(groupBox_Trafo);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 3, 1);

        comboBox_ModeCrop_X = new QComboBox(groupBox_Trafo);
        comboBox_ModeCrop_X->setObjectName(QString::fromUtf8("comboBox_ModeCrop_X"));

        gridLayout->addWidget(comboBox_ModeCrop_X, 1, 2, 1, 1);

        label_2 = new QLabel(groupBox_Trafo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        doubleSpinBox_TrafoDivisor_X = new QDoubleSpinBox(groupBox_Trafo);
        doubleSpinBox_TrafoDivisor_X->setObjectName(QString::fromUtf8("doubleSpinBox_TrafoDivisor_X"));
        doubleSpinBox_TrafoDivisor_X->setEnabled(false);
        doubleSpinBox_TrafoDivisor_X->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_TrafoDivisor_X->setDecimals(3);
        doubleSpinBox_TrafoDivisor_X->setMinimum(0.001000000000000);
        doubleSpinBox_TrafoDivisor_X->setMaximum(999999999.000000000000000);
        doubleSpinBox_TrafoDivisor_X->setSingleStep(0.100000000000000);
        doubleSpinBox_TrafoDivisor_X->setValue(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_TrafoDivisor_X, 1, 9, 1, 1);

        label_10 = new QLabel(groupBox_Trafo);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 0, 8, 1, 1);

        label_7 = new QLabel(groupBox_Trafo);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 4, 1, 1);

        comboBox_ModeCrop_Y = new QComboBox(groupBox_Trafo);
        comboBox_ModeCrop_Y->setObjectName(QString::fromUtf8("comboBox_ModeCrop_Y"));

        gridLayout->addWidget(comboBox_ModeCrop_Y, 2, 2, 1, 1);

        doubleSpinBox_CropMin_Y = new QDoubleSpinBox(groupBox_Trafo);
        doubleSpinBox_CropMin_Y->setObjectName(QString::fromUtf8("doubleSpinBox_CropMin_Y"));
        doubleSpinBox_CropMin_Y->setEnabled(false);
        doubleSpinBox_CropMin_Y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_CropMin_Y->setDecimals(3);
        doubleSpinBox_CropMin_Y->setMinimum(-999999999.000000000000000);
        doubleSpinBox_CropMin_Y->setMaximum(999999999.000000000000000);

        gridLayout->addWidget(doubleSpinBox_CropMin_Y, 2, 3, 1, 1);

        label_4 = new QLabel(groupBox_Trafo);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_9 = new QLabel(groupBox_Trafo);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 0, 7, 1, 1);

        label_5 = new QLabel(groupBox_Trafo);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 9, 1, 1);

        doubleSpinBox_TrafoDivisor_Y = new QDoubleSpinBox(groupBox_Trafo);
        doubleSpinBox_TrafoDivisor_Y->setObjectName(QString::fromUtf8("doubleSpinBox_TrafoDivisor_Y"));
        doubleSpinBox_TrafoDivisor_Y->setEnabled(false);
        doubleSpinBox_TrafoDivisor_Y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_TrafoDivisor_Y->setDecimals(3);
        doubleSpinBox_TrafoDivisor_Y->setMinimum(0.001000000000000);
        doubleSpinBox_TrafoDivisor_Y->setMaximum(999999999.000000000000000);
        doubleSpinBox_TrafoDivisor_Y->setSingleStep(0.100000000000000);
        doubleSpinBox_TrafoDivisor_Y->setValue(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_TrafoDivisor_Y, 2, 9, 1, 1);

        doubleSpinBox_CropMax_X = new QDoubleSpinBox(groupBox_Trafo);
        doubleSpinBox_CropMax_X->setObjectName(QString::fromUtf8("doubleSpinBox_CropMax_X"));
        doubleSpinBox_CropMax_X->setEnabled(false);
        doubleSpinBox_CropMax_X->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_CropMax_X->setDecimals(3);
        doubleSpinBox_CropMax_X->setMinimum(-999999999.000000000000000);
        doubleSpinBox_CropMax_X->setMaximum(999999999.000000000000000);
        doubleSpinBox_CropMax_X->setValue(255.000000000000000);

        gridLayout->addWidget(doubleSpinBox_CropMax_X, 1, 4, 1, 1);

        doubleSpinBox_TrafoCenter_X = new QDoubleSpinBox(groupBox_Trafo);
        doubleSpinBox_TrafoCenter_X->setObjectName(QString::fromUtf8("doubleSpinBox_TrafoCenter_X"));
        doubleSpinBox_TrafoCenter_X->setEnabled(false);
        doubleSpinBox_TrafoCenter_X->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_TrafoCenter_X->setDecimals(3);
        doubleSpinBox_TrafoCenter_X->setMinimum(-999999999.000000000000000);
        doubleSpinBox_TrafoCenter_X->setMaximum(999999999.000000000000000);
        doubleSpinBox_TrafoCenter_X->setSingleStep(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_TrafoCenter_X, 1, 8, 1, 1);

        comboBox_ModeTrafo_X = new QComboBox(groupBox_Trafo);
        comboBox_ModeTrafo_X->setObjectName(QString::fromUtf8("comboBox_ModeTrafo_X"));

        gridLayout->addWidget(comboBox_ModeTrafo_X, 1, 6, 1, 1);

        line_2 = new QFrame(groupBox_Trafo);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 0, 5, 3, 1);

        doubleSpinBox_TrafoCenter_Y = new QDoubleSpinBox(groupBox_Trafo);
        doubleSpinBox_TrafoCenter_Y->setObjectName(QString::fromUtf8("doubleSpinBox_TrafoCenter_Y"));
        doubleSpinBox_TrafoCenter_Y->setEnabled(false);
        doubleSpinBox_TrafoCenter_Y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_TrafoCenter_Y->setDecimals(3);
        doubleSpinBox_TrafoCenter_Y->setMinimum(-999999999.000000000000000);
        doubleSpinBox_TrafoCenter_Y->setMaximum(999999999.000000000000000);
        doubleSpinBox_TrafoCenter_Y->setSingleStep(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_TrafoCenter_Y, 2, 8, 1, 1);

        comboBox_ModeTrafo_Y = new QComboBox(groupBox_Trafo);
        comboBox_ModeTrafo_Y->setObjectName(QString::fromUtf8("comboBox_ModeTrafo_Y"));

        gridLayout->addWidget(comboBox_ModeTrafo_Y, 2, 6, 1, 1);


        gridLayout_2->addWidget(groupBox_Trafo, 1, 1, 1, 2);

        groupBox_PlotMode = new QGroupBox(D_Popup_Plot);
        groupBox_PlotMode->setObjectName(QString::fromUtf8("groupBox_PlotMode"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_PlotMode->sizePolicy().hasHeightForWidth());
        groupBox_PlotMode->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(groupBox_PlotMode);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        comboBox_ModePlot = new QComboBox(groupBox_PlotMode);
        comboBox_ModePlot->setObjectName(QString::fromUtf8("comboBox_ModePlot"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox_ModePlot->sizePolicy().hasHeightForWidth());
        comboBox_ModePlot->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(comboBox_ModePlot, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_PlotMode, 1, 0, 1, 1);

        gridLayout_Plot = new QGridLayout();
        gridLayout_Plot->setObjectName(QString::fromUtf8("gridLayout_Plot"));

        gridLayout_2->addLayout(gridLayout_Plot, 0, 0, 1, 3);


        retranslateUi(D_Popup_Plot);

        QMetaObject::connectSlotsByName(D_Popup_Plot);
    } // setupUi

    void retranslateUi(QDialog *D_Popup_Plot)
    {
        D_Popup_Plot->setWindowTitle(QApplication::translate("D_Popup_Plot", "Dialog", nullptr));
        groupBox_Trafo->setTitle(QApplication::translate("D_Popup_Plot", "Transformation", nullptr));
        label_8->setText(QApplication::translate("D_Popup_Plot", "Trafo", nullptr));
        label_6->setText(QApplication::translate("D_Popup_Plot", "Min", nullptr));
        label_3->setText(QApplication::translate("D_Popup_Plot", "Y", nullptr));
        label_2->setText(QApplication::translate("D_Popup_Plot", "X", nullptr));
        label_10->setText(QApplication::translate("D_Popup_Plot", "Center", nullptr));
        label_7->setText(QApplication::translate("D_Popup_Plot", "Max", nullptr));
        label_4->setText(QApplication::translate("D_Popup_Plot", "Crop", nullptr));
        label_9->setText(QApplication::translate("D_Popup_Plot", "Gamma", nullptr));
        label_5->setText(QApplication::translate("D_Popup_Plot", "Divisor", nullptr));
        groupBox_PlotMode->setTitle(QApplication::translate("D_Popup_Plot", "Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_Popup_Plot: public Ui_D_Popup_Plot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_POPUP_PLOT_H
