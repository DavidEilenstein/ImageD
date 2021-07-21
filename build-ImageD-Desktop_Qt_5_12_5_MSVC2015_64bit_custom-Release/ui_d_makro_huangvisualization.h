/********************************************************************************
** Form generated from reading UI file 'd_makro_huangvisualization.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_HUANGVISUALIZATION_H
#define UI_D_MAKRO_HUANGVISUALIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_HuangVisualization
{
public:
    QAction *actionLoad_Image;
    QAction *actionSet_Mask;
    QAction *actionChoose_new_quantile;
    QAction *actionStep_Detail;
    QAction *actionStep_Value;
    QAction *actionStep_Pixel;
    QAction *actionStep_Line;
    QAction *actionProc_All;
    QAction *actionProcStop;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_11;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_direction;
    QLabel *label_x;
    QLabel *label_y;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_9;
    QLabel *label_6;
    QLabel *label_add;
    QLabel *label_quantil_description;
    QLabel *label_rem;
    QLabel *label_quantil;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_8;
    QGraphicsView *graphicsView_Hist;
    QGraphicsView *graphicsView_HistLegend;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_12;
    QLabel *label_mass_quantil;
    QLabel *label_3;
    QLabel *label_mass_smaller;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_mass_greater;
    QGraphicsView *graphicsView_Mass;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QGraphicsView *graphicsView_In;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QGraphicsView *graphicsView_Out;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QGraphicsView *graphicsView_Mask_ZoomOutput;
    QGraphicsView *graphicsView_Mask_ZoomInput_Gray;
    QGraphicsView *graphicsView_Mask_BinaryAndPos;
    QGraphicsView *graphicsView_Mask_ZoomInput_Color;
    QPushButton *pushButton_VideoGuide;
    QMenuBar *menubar;
    QMenu *menuData;
    QMenu *menuProcessing;
    QMenu *menuQuantile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_HuangVisualization)
    {
        if (D_MAKRO_HuangVisualization->objectName().isEmpty())
            D_MAKRO_HuangVisualization->setObjectName(QString::fromUtf8("D_MAKRO_HuangVisualization"));
        D_MAKRO_HuangVisualization->resize(940, 589);
        actionLoad_Image = new QAction(D_MAKRO_HuangVisualization);
        actionLoad_Image->setObjectName(QString::fromUtf8("actionLoad_Image"));
        actionSet_Mask = new QAction(D_MAKRO_HuangVisualization);
        actionSet_Mask->setObjectName(QString::fromUtf8("actionSet_Mask"));
        actionChoose_new_quantile = new QAction(D_MAKRO_HuangVisualization);
        actionChoose_new_quantile->setObjectName(QString::fromUtf8("actionChoose_new_quantile"));
        actionStep_Detail = new QAction(D_MAKRO_HuangVisualization);
        actionStep_Detail->setObjectName(QString::fromUtf8("actionStep_Detail"));
        actionStep_Value = new QAction(D_MAKRO_HuangVisualization);
        actionStep_Value->setObjectName(QString::fromUtf8("actionStep_Value"));
        actionStep_Pixel = new QAction(D_MAKRO_HuangVisualization);
        actionStep_Pixel->setObjectName(QString::fromUtf8("actionStep_Pixel"));
        actionStep_Line = new QAction(D_MAKRO_HuangVisualization);
        actionStep_Line->setObjectName(QString::fromUtf8("actionStep_Line"));
        actionProc_All = new QAction(D_MAKRO_HuangVisualization);
        actionProc_All->setObjectName(QString::fromUtf8("actionProc_All"));
        actionProcStop = new QAction(D_MAKRO_HuangVisualization);
        actionProcStop->setObjectName(QString::fromUtf8("actionProcStop"));
        actionProcStop->setCheckable(true);
        centralwidget = new QWidget(D_MAKRO_HuangVisualization);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy);
        gridLayout_6 = new QGridLayout(groupBox_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        groupBox_8 = new QGroupBox(groupBox_5);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_8->sizePolicy().hasHeightForWidth());
        groupBox_8->setSizePolicy(sizePolicy1);
        groupBox_8->setMinimumSize(QSize(0, 100));
        groupBox_8->setMaximumSize(QSize(16777215, 100));
        gridLayout_11 = new QGridLayout(groupBox_8);
        gridLayout_11->setSpacing(3);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_4 = new QLabel(groupBox_8);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_11->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox_8);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_11->addWidget(label_5, 1, 0, 1, 1);

        label_direction = new QLabel(groupBox_8);
        label_direction->setObjectName(QString::fromUtf8("label_direction"));
        label_direction->setMinimumSize(QSize(0, 30));
        label_direction->setMaximumSize(QSize(16777215, 30));
        label_direction->setStyleSheet(QString::fromUtf8("font: bold 20px;\n"
"background-color: black;\n"
"color: white;"));
        label_direction->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_direction, 0, 1, 1, 2);

        label_x = new QLabel(groupBox_8);
        label_x->setObjectName(QString::fromUtf8("label_x"));
        label_x->setMinimumSize(QSize(0, 30));
        label_x->setMaximumSize(QSize(16777215, 30));
        label_x->setStyleSheet(QString::fromUtf8("font: bold 20px;\n"
"background-color: rgb(0, 255, 0);\n"
"color: black;"));
        label_x->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_x, 1, 1, 1, 1);

        label_y = new QLabel(groupBox_8);
        label_y->setObjectName(QString::fromUtf8("label_y"));
        label_y->setMinimumSize(QSize(0, 30));
        label_y->setMaximumSize(QSize(16777215, 30));
        label_y->setStyleSheet(QString::fromUtf8("font: bold 20px;\n"
"background-color: rgb(0, 255, 0);\n"
"color: black;"));
        label_y->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_y, 1, 2, 1, 1);


        gridLayout_6->addWidget(groupBox_8, 0, 1, 1, 1);

        groupBox_7 = new QGroupBox(groupBox_5);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_7->sizePolicy().hasHeightForWidth());
        groupBox_7->setSizePolicy(sizePolicy2);
        groupBox_7->setMinimumSize(QSize(0, 100));
        groupBox_7->setMaximumSize(QSize(16777215, 100));
        gridLayout_9 = new QGridLayout(groupBox_7);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_6 = new QLabel(groupBox_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_9->addWidget(label_6, 0, 0, 1, 1);

        label_add = new QLabel(groupBox_7);
        label_add->setObjectName(QString::fromUtf8("label_add"));
        label_add->setMinimumSize(QSize(0, 30));
        label_add->setMaximumSize(QSize(16777215, 30));
        label_add->setStyleSheet(QString::fromUtf8("font: bold 20px;\n"
"background-color: blue;\n"
"color: white;"));
        label_add->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_add, 0, 1, 1, 1);

        label_quantil_description = new QLabel(groupBox_7);
        label_quantil_description->setObjectName(QString::fromUtf8("label_quantil_description"));

        gridLayout_9->addWidget(label_quantil_description, 1, 0, 1, 1);

        label_rem = new QLabel(groupBox_7);
        label_rem->setObjectName(QString::fromUtf8("label_rem"));
        label_rem->setMinimumSize(QSize(0, 30));
        label_rem->setMaximumSize(QSize(16777215, 30));
        label_rem->setStyleSheet(QString::fromUtf8("font: bold 20px;\n"
"background-color: red;\n"
"color: white;"));
        label_rem->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_rem, 0, 2, 1, 1);

        label_quantil = new QLabel(groupBox_7);
        label_quantil->setObjectName(QString::fromUtf8("label_quantil"));
        label_quantil->setMinimumSize(QSize(0, 30));
        label_quantil->setMaximumSize(QSize(16777215, 30));
        label_quantil->setStyleSheet(QString::fromUtf8("font: bold 20px;\n"
"background-color: black;\n"
"color: yellow;"));
        label_quantil->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_quantil, 1, 1, 1, 2);


        gridLayout_6->addWidget(groupBox_7, 0, 2, 1, 1);

        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(8);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy3);
        gridLayout_8 = new QGridLayout(groupBox_6);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        graphicsView_Hist = new QGraphicsView(groupBox_6);
        graphicsView_Hist->setObjectName(QString::fromUtf8("graphicsView_Hist"));

        gridLayout_8->addWidget(graphicsView_Hist, 0, 0, 1, 1);

        graphicsView_HistLegend = new QGraphicsView(groupBox_6);
        graphicsView_HistLegend->setObjectName(QString::fromUtf8("graphicsView_HistLegend"));
        graphicsView_HistLegend->setMinimumSize(QSize(0, 20));
        graphicsView_HistLegend->setMaximumSize(QSize(16777215, 20));

        gridLayout_8->addWidget(graphicsView_HistLegend, 1, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_6, 0, 0, 3, 1);

        groupBox_9 = new QGroupBox(groupBox_5);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox_9->sizePolicy().hasHeightForWidth());
        groupBox_9->setSizePolicy(sizePolicy4);
        gridLayout_10 = new QGridLayout(groupBox_9);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        label_mass_quantil = new QLabel(groupBox_9);
        label_mass_quantil->setObjectName(QString::fromUtf8("label_mass_quantil"));
        label_mass_quantil->setMinimumSize(QSize(0, 30));
        label_mass_quantil->setMaximumSize(QSize(16777215, 30));
        label_mass_quantil->setStyleSheet(QString::fromUtf8("font: bold 20px;\n"
"background-color: yellow;\n"
"color: black;"));
        label_mass_quantil->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(label_mass_quantil, 0, 3, 1, 1);

        label_3 = new QLabel(groupBox_9);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_12->addWidget(label_3, 0, 4, 1, 1);

        label_mass_smaller = new QLabel(groupBox_9);
        label_mass_smaller->setObjectName(QString::fromUtf8("label_mass_smaller"));
        label_mass_smaller->setMinimumSize(QSize(0, 30));
        label_mass_smaller->setMaximumSize(QSize(16777215, 30));
        label_mass_smaller->setStyleSheet(QString::fromUtf8("font: bold 20px;\n"
"background-color: magenta;\n"
"color: black;"));
        label_mass_smaller->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(label_mass_smaller, 0, 1, 1, 1);

        label = new QLabel(groupBox_9);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_12->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox_9);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_12->addWidget(label_2, 0, 2, 1, 1);

        label_mass_greater = new QLabel(groupBox_9);
        label_mass_greater->setObjectName(QString::fromUtf8("label_mass_greater"));
        label_mass_greater->setMinimumSize(QSize(0, 30));
        label_mass_greater->setMaximumSize(QSize(16777215, 30));
        label_mass_greater->setStyleSheet(QString::fromUtf8("font: bold 20px;\n"
"background-color: cyan;\n"
"color: black;"));
        label_mass_greater->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(label_mass_greater, 0, 5, 1, 1);


        gridLayout_10->addLayout(gridLayout_12, 1, 1, 1, 1);

        graphicsView_Mass = new QGraphicsView(groupBox_9);
        graphicsView_Mass->setObjectName(QString::fromUtf8("graphicsView_Mass"));

        gridLayout_10->addWidget(graphicsView_Mass, 2, 1, 1, 1);


        gridLayout_6->addWidget(groupBox_9, 1, 1, 2, 2);


        gridLayout->addWidget(groupBox_5, 2, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(3);
        sizePolicy5.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy5);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(4);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy6);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        graphicsView_In = new QGraphicsView(groupBox_2);
        graphicsView_In->setObjectName(QString::fromUtf8("graphicsView_In"));

        gridLayout_3->addWidget(graphicsView_In, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy6.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy6);
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        graphicsView_Out = new QGraphicsView(groupBox_3);
        graphicsView_Out->setObjectName(QString::fromUtf8("graphicsView_Out"));

        gridLayout_4->addWidget(graphicsView_Out, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        sizePolicy6.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy6);
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        graphicsView_Mask_ZoomOutput = new QGraphicsView(groupBox_4);
        graphicsView_Mask_ZoomOutput->setObjectName(QString::fromUtf8("graphicsView_Mask_ZoomOutput"));

        gridLayout_5->addWidget(graphicsView_Mask_ZoomOutput, 1, 1, 1, 1);

        graphicsView_Mask_ZoomInput_Gray = new QGraphicsView(groupBox_4);
        graphicsView_Mask_ZoomInput_Gray->setObjectName(QString::fromUtf8("graphicsView_Mask_ZoomInput_Gray"));

        gridLayout_5->addWidget(graphicsView_Mask_ZoomInput_Gray, 1, 0, 1, 1);

        graphicsView_Mask_BinaryAndPos = new QGraphicsView(groupBox_4);
        graphicsView_Mask_BinaryAndPos->setObjectName(QString::fromUtf8("graphicsView_Mask_BinaryAndPos"));

        gridLayout_5->addWidget(graphicsView_Mask_BinaryAndPos, 0, 1, 1, 1);

        graphicsView_Mask_ZoomInput_Color = new QGraphicsView(groupBox_4);
        graphicsView_Mask_ZoomInput_Color->setObjectName(QString::fromUtf8("graphicsView_Mask_ZoomInput_Color"));

        gridLayout_5->addWidget(graphicsView_Mask_ZoomInput_Color, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_4, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        pushButton_VideoGuide = new QPushButton(centralwidget);
        pushButton_VideoGuide->setObjectName(QString::fromUtf8("pushButton_VideoGuide"));

        gridLayout->addWidget(pushButton_VideoGuide, 0, 0, 1, 1);

        D_MAKRO_HuangVisualization->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_HuangVisualization);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 940, 21));
        menuData = new QMenu(menubar);
        menuData->setObjectName(QString::fromUtf8("menuData"));
        menuProcessing = new QMenu(menubar);
        menuProcessing->setObjectName(QString::fromUtf8("menuProcessing"));
        menuQuantile = new QMenu(menubar);
        menuQuantile->setObjectName(QString::fromUtf8("menuQuantile"));
        D_MAKRO_HuangVisualization->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_HuangVisualization);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_HuangVisualization->setStatusBar(statusbar);

        menubar->addAction(menuData->menuAction());
        menubar->addAction(menuQuantile->menuAction());
        menubar->addAction(menuProcessing->menuAction());
        menuData->addAction(actionLoad_Image);
        menuData->addAction(actionSet_Mask);
        menuProcessing->addAction(actionStep_Detail);
        menuProcessing->addAction(actionStep_Value);
        menuProcessing->addAction(actionStep_Pixel);
        menuProcessing->addAction(actionStep_Line);
        menuProcessing->addAction(actionProc_All);
        menuProcessing->addSeparator();
        menuProcessing->addAction(actionProcStop);
        menuQuantile->addAction(actionChoose_new_quantile);

        retranslateUi(D_MAKRO_HuangVisualization);

        QMetaObject::connectSlotsByName(D_MAKRO_HuangVisualization);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_HuangVisualization)
    {
        D_MAKRO_HuangVisualization->setWindowTitle(QApplication::translate("D_MAKRO_HuangVisualization", "MainWindow", nullptr));
        actionLoad_Image->setText(QApplication::translate("D_MAKRO_HuangVisualization", "Load Image", nullptr));
#ifndef QT_NO_SHORTCUT
        actionLoad_Image->setShortcut(QApplication::translate("D_MAKRO_HuangVisualization", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSet_Mask->setText(QApplication::translate("D_MAKRO_HuangVisualization", "Set Mask", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSet_Mask->setShortcut(QApplication::translate("D_MAKRO_HuangVisualization", "Ctrl+M", nullptr));
#endif // QT_NO_SHORTCUT
        actionChoose_new_quantile->setText(QApplication::translate("D_MAKRO_HuangVisualization", "Choose new quantile", nullptr));
#ifndef QT_NO_SHORTCUT
        actionChoose_new_quantile->setShortcut(QApplication::translate("D_MAKRO_HuangVisualization", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionStep_Detail->setText(QApplication::translate("D_MAKRO_HuangVisualization", "Step Detail", nullptr));
#ifndef QT_NO_SHORTCUT
        actionStep_Detail->setShortcut(QApplication::translate("D_MAKRO_HuangVisualization", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        actionStep_Value->setText(QApplication::translate("D_MAKRO_HuangVisualization", "Step Value", nullptr));
#ifndef QT_NO_SHORTCUT
        actionStep_Value->setShortcut(QApplication::translate("D_MAKRO_HuangVisualization", "F6", nullptr));
#endif // QT_NO_SHORTCUT
        actionStep_Pixel->setText(QApplication::translate("D_MAKRO_HuangVisualization", "Step Pixel", nullptr));
#ifndef QT_NO_SHORTCUT
        actionStep_Pixel->setShortcut(QApplication::translate("D_MAKRO_HuangVisualization", "F7", nullptr));
#endif // QT_NO_SHORTCUT
        actionStep_Line->setText(QApplication::translate("D_MAKRO_HuangVisualization", "Step Line", nullptr));
#ifndef QT_NO_SHORTCUT
        actionStep_Line->setShortcut(QApplication::translate("D_MAKRO_HuangVisualization", "F8", nullptr));
#endif // QT_NO_SHORTCUT
        actionProc_All->setText(QApplication::translate("D_MAKRO_HuangVisualization", "Proc All", nullptr));
#ifndef QT_NO_SHORTCUT
        actionProc_All->setShortcut(QApplication::translate("D_MAKRO_HuangVisualization", "F9", nullptr));
#endif // QT_NO_SHORTCUT
        actionProcStop->setText(QApplication::translate("D_MAKRO_HuangVisualization", "Stop", nullptr));
#ifndef QT_NO_SHORTCUT
        actionProcStop->setShortcut(QApplication::translate("D_MAKRO_HuangVisualization", "Esc", nullptr));
#endif // QT_NO_SHORTCUT
        groupBox_5->setTitle(QApplication::translate("D_MAKRO_HuangVisualization", "Variables", nullptr));
        groupBox_8->setTitle(QApplication::translate("D_MAKRO_HuangVisualization", "Spacial", nullptr));
        label_4->setText(QApplication::translate("D_MAKRO_HuangVisualization", "Direction:", nullptr));
        label_5->setText(QApplication::translate("D_MAKRO_HuangVisualization", "X/Y:", nullptr));
        label_direction->setText(QApplication::translate("D_MAKRO_HuangVisualization", "-", nullptr));
        label_x->setText(QApplication::translate("D_MAKRO_HuangVisualization", "0", nullptr));
        label_y->setText(QApplication::translate("D_MAKRO_HuangVisualization", "0", nullptr));
        groupBox_7->setTitle(QApplication::translate("D_MAKRO_HuangVisualization", "Values", nullptr));
        label_6->setText(QApplication::translate("D_MAKRO_HuangVisualization", "Add/Remove:", nullptr));
        label_add->setText(QApplication::translate("D_MAKRO_HuangVisualization", "0", nullptr));
        label_quantil_description->setText(QApplication::translate("D_MAKRO_HuangVisualization", "Quantil:", nullptr));
        label_rem->setText(QApplication::translate("D_MAKRO_HuangVisualization", "0", nullptr));
        label_quantil->setText(QApplication::translate("D_MAKRO_HuangVisualization", "0", nullptr));
        groupBox_6->setTitle(QApplication::translate("D_MAKRO_HuangVisualization", "Histogram", nullptr));
        groupBox_9->setTitle(QApplication::translate("D_MAKRO_HuangVisualization", "Masses", nullptr));
        label_mass_quantil->setText(QApplication::translate("D_MAKRO_HuangVisualization", "0", nullptr));
        label_3->setText(QApplication::translate("D_MAKRO_HuangVisualization", "Greater:", nullptr));
        label_mass_smaller->setText(QApplication::translate("D_MAKRO_HuangVisualization", "0", nullptr));
        label->setText(QApplication::translate("D_MAKRO_HuangVisualization", "Smaller:", nullptr));
        label_2->setText(QApplication::translate("D_MAKRO_HuangVisualization", "Quantil:", nullptr));
        label_mass_greater->setText(QApplication::translate("D_MAKRO_HuangVisualization", "0", nullptr));
        groupBox->setTitle(QApplication::translate("D_MAKRO_HuangVisualization", "Images", nullptr));
        groupBox_2->setTitle(QApplication::translate("D_MAKRO_HuangVisualization", "In", nullptr));
        groupBox_3->setTitle(QApplication::translate("D_MAKRO_HuangVisualization", "Out", nullptr));
        groupBox_4->setTitle(QApplication::translate("D_MAKRO_HuangVisualization", "Mask", nullptr));
        pushButton_VideoGuide->setText(QApplication::translate("D_MAKRO_HuangVisualization", "--> click here for demo video (german) <---", nullptr));
        menuData->setTitle(QApplication::translate("D_MAKRO_HuangVisualization", "Data", nullptr));
        menuProcessing->setTitle(QApplication::translate("D_MAKRO_HuangVisualization", "Processing", nullptr));
        menuQuantile->setTitle(QApplication::translate("D_MAKRO_HuangVisualization", "Quantile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_HuangVisualization: public Ui_D_MAKRO_HuangVisualization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_HUANGVISUALIZATION_H
