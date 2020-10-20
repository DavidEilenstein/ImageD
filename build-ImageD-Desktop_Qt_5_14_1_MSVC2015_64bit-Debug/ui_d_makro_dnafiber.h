/********************************************************************************
** Form generated from reading UI file 'd_makro_dnafiber.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_DNAFIBER_H
#define UI_D_MAKRO_DNAFIBER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_DnaFiber
{
public:
    QAction *action_Load_Images;
    QAction *action_Update_Image_Processing;
    QAction *action_Update_Results;
    QAction *action_Save_Image_Proc;
    QAction *action_Save_Image_Visualize;
    QAction *action_Save_Plot_Diameter_Histogram;
    QAction *action_Save_Table_Diameter_Statistics;
    QAction *action_Save_Analysis_Single;
    QAction *action_Save_Analysis_Stack;
    QAction *action_Save_Plot_Input_Gray_Values;
    QAction *action_Save_Table_Euler_Characteristic;
    QAction *action_Save_Table_Pixel_Ratios;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_Controls;
    QGridLayout *gridLayout_3;
    QLabel *label_14;
    QSpinBox *spinBox_Controls_Eilenstein_Z;
    QSpinBox *spinBox_Controls_Median_Size_Z;
    QLabel *label_13;
    QLabel *label_5;
    QFrame *line_2;
    QLabel *label_6;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_Controls_Skelleton_ThreshOfVol;
    QFrame *line_3;
    QFrame *line;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QFrame *line_5;
    QSpinBox *spinBox_Controls_Binary_Thres;
    QDoubleSpinBox *doubleSpinBox_Controls_Spacing_XY;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox_Controls_Eilenstein_XY;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_Controls_Spacing_Z;
    QSpinBox *spinBox_Controls_Median_Size_XY;
    QSpinBox *spinBox_Controls_Skelleton_Thres;
    QLabel *label_8;
    QPushButton *pushButton_Controls_SaveParam;
    QLabel *label_17;
    QLabel *label_21;
    QLabel *label_22;
    QGroupBox *groupBox_ImgProc;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView_ImgProc;
    QSpinBox *spinBox_ImgProc_View_Y;
    QComboBox *comboBox_ImgProc_Step;
    QComboBox *comboBox_ImgProc_Img;
    QComboBox *comboBox_ImgProc_View_Plane;
    QSpinBox *spinBox_ImgProc_View_Z;
    QSpinBox *spinBox_ImgProc_View_X;
    QFrame *line_4;
    QTabWidget *tabWidget_Results;
    QWidget *tab_Res_Visualization;
    QGridLayout *gridLayout_4;
    QGraphicsView *graphicsView_ResVis;
    QWidget *tab_Res_Analysis;
    QGridLayout *gridLayout_5;
    QStackedWidget *stackedWidget_ResAna_Type;
    QWidget *stackedWidget_ResAna_InputHist;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_ResAna_InputHist;
    QWidget *stackedWidget_ResAna_DiaHist;
    QGridLayout *gridLayout_6;
    QComboBox *comboBox_ResAna_DiaHist_PoolingWeights;
    QFrame *line_6;
    QCheckBox *checkBox_ResAna_DiaHist_Uni;
    QCheckBox *checkBox_ResAna_DiaHist_Acc;
    QLabel *label_ResAna_DiaHist_Classes;
    QSpinBox *spinBox_ResAna_DiaHist_Classes;
    QFrame *line_ResAna_DiaHist;
    QGridLayout *gridLayout_ResAna_DiaHist;
    QWidget *stackedWidget_ResAna_DiaStat;
    QGridLayout *gridLayout_8;
    QTableWidget *tableWidget_ResAna_DiaStat;
    QWidget *stackedWidget_ResAna_Euler;
    QGridLayout *gridLayout_7;
    QTableWidget *tableWidget_ResAna_Euler;
    QWidget *stackedWidget_ResAna_PixelRatio;
    QGridLayout *gridLayout_9;
    QTableWidget *tableWidget_ResAna_PixelRatio;
    QComboBox *comboBox_ResAna_SingleStack;
    QComboBox *comboBox_ResAna_Type;
    QMenuBar *menubar;
    QMenu *menuData;
    QMenu *menuUpdate;
    QMenu *menuSave;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_DnaFiber)
    {
        if (D_MAKRO_DnaFiber->objectName().isEmpty())
            D_MAKRO_DnaFiber->setObjectName(QString::fromUtf8("D_MAKRO_DnaFiber"));
        D_MAKRO_DnaFiber->resize(1018, 807);
        action_Load_Images = new QAction(D_MAKRO_DnaFiber);
        action_Load_Images->setObjectName(QString::fromUtf8("action_Load_Images"));
        action_Update_Image_Processing = new QAction(D_MAKRO_DnaFiber);
        action_Update_Image_Processing->setObjectName(QString::fromUtf8("action_Update_Image_Processing"));
        action_Update_Results = new QAction(D_MAKRO_DnaFiber);
        action_Update_Results->setObjectName(QString::fromUtf8("action_Update_Results"));
        action_Save_Image_Proc = new QAction(D_MAKRO_DnaFiber);
        action_Save_Image_Proc->setObjectName(QString::fromUtf8("action_Save_Image_Proc"));
        action_Save_Image_Visualize = new QAction(D_MAKRO_DnaFiber);
        action_Save_Image_Visualize->setObjectName(QString::fromUtf8("action_Save_Image_Visualize"));
        action_Save_Plot_Diameter_Histogram = new QAction(D_MAKRO_DnaFiber);
        action_Save_Plot_Diameter_Histogram->setObjectName(QString::fromUtf8("action_Save_Plot_Diameter_Histogram"));
        action_Save_Table_Diameter_Statistics = new QAction(D_MAKRO_DnaFiber);
        action_Save_Table_Diameter_Statistics->setObjectName(QString::fromUtf8("action_Save_Table_Diameter_Statistics"));
        action_Save_Analysis_Single = new QAction(D_MAKRO_DnaFiber);
        action_Save_Analysis_Single->setObjectName(QString::fromUtf8("action_Save_Analysis_Single"));
        action_Save_Analysis_Stack = new QAction(D_MAKRO_DnaFiber);
        action_Save_Analysis_Stack->setObjectName(QString::fromUtf8("action_Save_Analysis_Stack"));
        action_Save_Plot_Input_Gray_Values = new QAction(D_MAKRO_DnaFiber);
        action_Save_Plot_Input_Gray_Values->setObjectName(QString::fromUtf8("action_Save_Plot_Input_Gray_Values"));
        action_Save_Table_Euler_Characteristic = new QAction(D_MAKRO_DnaFiber);
        action_Save_Table_Euler_Characteristic->setObjectName(QString::fromUtf8("action_Save_Table_Euler_Characteristic"));
        action_Save_Table_Pixel_Ratios = new QAction(D_MAKRO_DnaFiber);
        action_Save_Table_Pixel_Ratios->setObjectName(QString::fromUtf8("action_Save_Table_Pixel_Ratios"));
        centralwidget = new QWidget(D_MAKRO_DnaFiber);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_Controls = new QGroupBox(centralwidget);
        groupBox_Controls->setObjectName(QString::fromUtf8("groupBox_Controls"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_Controls->sizePolicy().hasHeightForWidth());
        groupBox_Controls->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(groupBox_Controls);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(6, 6, 6, 6);
        label_14 = new QLabel(groupBox_Controls);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(75, 0));
        label_14->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_14, 0, 3, 1, 1);

        spinBox_Controls_Eilenstein_Z = new QSpinBox(groupBox_Controls);
        spinBox_Controls_Eilenstein_Z->setObjectName(QString::fromUtf8("spinBox_Controls_Eilenstein_Z"));
        spinBox_Controls_Eilenstein_Z->setMinimumSize(QSize(75, 0));
        spinBox_Controls_Eilenstein_Z->setMaximumSize(QSize(75, 16777215));
        spinBox_Controls_Eilenstein_Z->setMinimum(3);
        spinBox_Controls_Eilenstein_Z->setMaximum(15);
        spinBox_Controls_Eilenstein_Z->setSingleStep(2);
        spinBox_Controls_Eilenstein_Z->setValue(3);

        gridLayout_3->addWidget(spinBox_Controls_Eilenstein_Z, 7, 3, 1, 1);

        spinBox_Controls_Median_Size_Z = new QSpinBox(groupBox_Controls);
        spinBox_Controls_Median_Size_Z->setObjectName(QString::fromUtf8("spinBox_Controls_Median_Size_Z"));
        spinBox_Controls_Median_Size_Z->setMinimumSize(QSize(75, 0));
        spinBox_Controls_Median_Size_Z->setMaximumSize(QSize(75, 16777215));
        spinBox_Controls_Median_Size_Z->setMinimum(3);
        spinBox_Controls_Median_Size_Z->setMaximum(15);
        spinBox_Controls_Median_Size_Z->setSingleStep(2);
        spinBox_Controls_Median_Size_Z->setValue(9);

        gridLayout_3->addWidget(spinBox_Controls_Median_Size_Z, 4, 3, 1, 1);

        label_13 = new QLabel(groupBox_Controls);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(75, 0));
        label_13->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_13, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox_Controls);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 2, 4, 1, 1);

        line_2 = new QFrame(groupBox_Controls);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 1, 0, 1, 5);

        label_6 = new QLabel(groupBox_Controls);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 4, 4, 1, 1);

        label_15 = new QLabel(groupBox_Controls);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 5, 4, 1, 1);

        label_16 = new QLabel(groupBox_Controls);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_3->addWidget(label_16, 7, 4, 1, 1);

        label_Controls_Skelleton_ThreshOfVol = new QLabel(groupBox_Controls);
        label_Controls_Skelleton_ThreshOfVol->setObjectName(QString::fromUtf8("label_Controls_Skelleton_ThreshOfVol"));

        gridLayout_3->addWidget(label_Controls_Skelleton_ThreshOfVol, 8, 4, 1, 1);

        line_3 = new QFrame(groupBox_Controls);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_3, 6, 0, 1, 5);

        line = new QFrame(groupBox_Controls);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 3, 0, 1, 5);

        label_18 = new QLabel(groupBox_Controls);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_3->addWidget(label_18, 0, 4, 1, 1);

        label_19 = new QLabel(groupBox_Controls);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMinimumSize(QSize(75, 0));
        label_19->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_19, 0, 1, 1, 1);

        label_20 = new QLabel(groupBox_Controls);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMinimumSize(QSize(75, 0));
        label_20->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_20, 0, 0, 1, 1);

        line_5 = new QFrame(groupBox_Controls);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_5, 9, 0, 1, 5);

        spinBox_Controls_Binary_Thres = new QSpinBox(groupBox_Controls);
        spinBox_Controls_Binary_Thres->setObjectName(QString::fromUtf8("spinBox_Controls_Binary_Thres"));
        spinBox_Controls_Binary_Thres->setMinimumSize(QSize(153, 0));
        spinBox_Controls_Binary_Thres->setMaximumSize(QSize(153, 16777215));
        spinBox_Controls_Binary_Thres->setMaximum(65535);
        spinBox_Controls_Binary_Thres->setValue(80);

        gridLayout_3->addWidget(spinBox_Controls_Binary_Thres, 5, 2, 1, 2);

        doubleSpinBox_Controls_Spacing_XY = new QDoubleSpinBox(groupBox_Controls);
        doubleSpinBox_Controls_Spacing_XY->setObjectName(QString::fromUtf8("doubleSpinBox_Controls_Spacing_XY"));
        doubleSpinBox_Controls_Spacing_XY->setMinimumSize(QSize(75, 0));
        doubleSpinBox_Controls_Spacing_XY->setMaximumSize(QSize(75, 16777215));
        doubleSpinBox_Controls_Spacing_XY->setSingleStep(0.010000000000000);
        doubleSpinBox_Controls_Spacing_XY->setValue(2.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_Controls_Spacing_XY, 2, 2, 1, 1);

        label_4 = new QLabel(groupBox_Controls);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(75, 0));
        label_4->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_4, 5, 1, 1, 1);

        label_7 = new QLabel(groupBox_Controls);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(75, 0));
        label_7->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_7, 8, 0, 1, 1);

        label = new QLabel(groupBox_Controls);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(75, 0));
        label->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label, 4, 0, 1, 1);

        label_2 = new QLabel(groupBox_Controls);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(75, 0));
        label_2->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_2, 4, 1, 1, 1);

        spinBox_Controls_Eilenstein_XY = new QSpinBox(groupBox_Controls);
        spinBox_Controls_Eilenstein_XY->setObjectName(QString::fromUtf8("spinBox_Controls_Eilenstein_XY"));
        spinBox_Controls_Eilenstein_XY->setMinimumSize(QSize(75, 0));
        spinBox_Controls_Eilenstein_XY->setMaximumSize(QSize(75, 16777215));
        spinBox_Controls_Eilenstein_XY->setMinimum(3);
        spinBox_Controls_Eilenstein_XY->setMaximum(15);
        spinBox_Controls_Eilenstein_XY->setSingleStep(2);
        spinBox_Controls_Eilenstein_XY->setValue(3);

        gridLayout_3->addWidget(spinBox_Controls_Eilenstein_XY, 7, 2, 1, 1);

        label_3 = new QLabel(groupBox_Controls);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(75, 0));
        label_3->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_3, 5, 0, 1, 1);

        label_9 = new QLabel(groupBox_Controls);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(75, 0));
        label_9->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_9, 7, 0, 1, 1);

        label_11 = new QLabel(groupBox_Controls);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(75, 0));
        label_11->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_11, 2, 0, 1, 1);

        label_12 = new QLabel(groupBox_Controls);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(75, 0));
        label_12->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_12, 2, 1, 1, 1);

        label_10 = new QLabel(groupBox_Controls);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(75, 0));
        label_10->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_10, 7, 1, 1, 1);

        doubleSpinBox_Controls_Spacing_Z = new QDoubleSpinBox(groupBox_Controls);
        doubleSpinBox_Controls_Spacing_Z->setObjectName(QString::fromUtf8("doubleSpinBox_Controls_Spacing_Z"));
        doubleSpinBox_Controls_Spacing_Z->setMinimumSize(QSize(75, 0));
        doubleSpinBox_Controls_Spacing_Z->setMaximumSize(QSize(75, 16777215));
        doubleSpinBox_Controls_Spacing_Z->setMinimum(0.010000000000000);
        doubleSpinBox_Controls_Spacing_Z->setMaximum(10.000000000000000);
        doubleSpinBox_Controls_Spacing_Z->setSingleStep(0.010000000000000);
        doubleSpinBox_Controls_Spacing_Z->setValue(3.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_Controls_Spacing_Z, 2, 3, 1, 1);

        spinBox_Controls_Median_Size_XY = new QSpinBox(groupBox_Controls);
        spinBox_Controls_Median_Size_XY->setObjectName(QString::fromUtf8("spinBox_Controls_Median_Size_XY"));
        spinBox_Controls_Median_Size_XY->setMinimumSize(QSize(75, 0));
        spinBox_Controls_Median_Size_XY->setMaximumSize(QSize(75, 16777215));
        spinBox_Controls_Median_Size_XY->setMinimum(3);
        spinBox_Controls_Median_Size_XY->setMaximum(15);
        spinBox_Controls_Median_Size_XY->setSingleStep(2);
        spinBox_Controls_Median_Size_XY->setValue(11);

        gridLayout_3->addWidget(spinBox_Controls_Median_Size_XY, 4, 2, 1, 1);

        spinBox_Controls_Skelleton_Thres = new QSpinBox(groupBox_Controls);
        spinBox_Controls_Skelleton_Thres->setObjectName(QString::fromUtf8("spinBox_Controls_Skelleton_Thres"));
        spinBox_Controls_Skelleton_Thres->setMinimumSize(QSize(153, 0));
        spinBox_Controls_Skelleton_Thres->setMaximumSize(QSize(153, 16777215));
        spinBox_Controls_Skelleton_Thres->setMaximum(27);
        spinBox_Controls_Skelleton_Thres->setValue(23);

        gridLayout_3->addWidget(spinBox_Controls_Skelleton_Thres, 8, 2, 1, 2);

        label_8 = new QLabel(groupBox_Controls);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(75, 0));
        label_8->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_8, 8, 1, 1, 1);

        pushButton_Controls_SaveParam = new QPushButton(groupBox_Controls);
        pushButton_Controls_SaveParam->setObjectName(QString::fromUtf8("pushButton_Controls_SaveParam"));

        gridLayout_3->addWidget(pushButton_Controls_SaveParam, 10, 2, 1, 2);

        label_17 = new QLabel(groupBox_Controls);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_3->addWidget(label_17, 10, 0, 1, 1);

        label_21 = new QLabel(groupBox_Controls);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_3->addWidget(label_21, 10, 1, 1, 1);

        label_22 = new QLabel(groupBox_Controls);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_3->addWidget(label_22, 10, 4, 1, 1);


        gridLayout->addWidget(groupBox_Controls, 1, 0, 1, 1);

        groupBox_ImgProc = new QGroupBox(centralwidget);
        groupBox_ImgProc->setObjectName(QString::fromUtf8("groupBox_ImgProc"));
        sizePolicy.setHeightForWidth(groupBox_ImgProc->sizePolicy().hasHeightForWidth());
        groupBox_ImgProc->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox_ImgProc);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphicsView_ImgProc = new QGraphicsView(groupBox_ImgProc);
        graphicsView_ImgProc->setObjectName(QString::fromUtf8("graphicsView_ImgProc"));
        graphicsView_ImgProc->setMouseTracking(true);

        gridLayout_2->addWidget(graphicsView_ImgProc, 4, 0, 1, 4);

        spinBox_ImgProc_View_Y = new QSpinBox(groupBox_ImgProc);
        spinBox_ImgProc_View_Y->setObjectName(QString::fromUtf8("spinBox_ImgProc_View_Y"));
        spinBox_ImgProc_View_Y->setEnabled(false);
        spinBox_ImgProc_View_Y->setMaximum(10);

        gridLayout_2->addWidget(spinBox_ImgProc_View_Y, 3, 2, 1, 1);

        comboBox_ImgProc_Step = new QComboBox(groupBox_ImgProc);
        comboBox_ImgProc_Step->addItem(QString());
        comboBox_ImgProc_Step->setObjectName(QString::fromUtf8("comboBox_ImgProc_Step"));

        gridLayout_2->addWidget(comboBox_ImgProc_Step, 2, 0, 1, 4);

        comboBox_ImgProc_Img = new QComboBox(groupBox_ImgProc);
        comboBox_ImgProc_Img->addItem(QString());
        comboBox_ImgProc_Img->setObjectName(QString::fromUtf8("comboBox_ImgProc_Img"));

        gridLayout_2->addWidget(comboBox_ImgProc_Img, 0, 0, 1, 4);

        comboBox_ImgProc_View_Plane = new QComboBox(groupBox_ImgProc);
        comboBox_ImgProc_View_Plane->addItem(QString());
        comboBox_ImgProc_View_Plane->setObjectName(QString::fromUtf8("comboBox_ImgProc_View_Plane"));

        gridLayout_2->addWidget(comboBox_ImgProc_View_Plane, 3, 0, 1, 1);

        spinBox_ImgProc_View_Z = new QSpinBox(groupBox_ImgProc);
        spinBox_ImgProc_View_Z->setObjectName(QString::fromUtf8("spinBox_ImgProc_View_Z"));
        spinBox_ImgProc_View_Z->setMaximum(10);

        gridLayout_2->addWidget(spinBox_ImgProc_View_Z, 3, 3, 1, 1);

        spinBox_ImgProc_View_X = new QSpinBox(groupBox_ImgProc);
        spinBox_ImgProc_View_X->setObjectName(QString::fromUtf8("spinBox_ImgProc_View_X"));
        spinBox_ImgProc_View_X->setEnabled(false);
        spinBox_ImgProc_View_X->setMaximum(10);

        gridLayout_2->addWidget(spinBox_ImgProc_View_X, 3, 1, 1, 1);

        line_4 = new QFrame(groupBox_ImgProc);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_4, 1, 0, 1, 4);


        gridLayout->addWidget(groupBox_ImgProc, 0, 0, 1, 1);

        tabWidget_Results = new QTabWidget(centralwidget);
        tabWidget_Results->setObjectName(QString::fromUtf8("tabWidget_Results"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget_Results->sizePolicy().hasHeightForWidth());
        tabWidget_Results->setSizePolicy(sizePolicy1);
        tab_Res_Visualization = new QWidget();
        tab_Res_Visualization->setObjectName(QString::fromUtf8("tab_Res_Visualization"));
        gridLayout_4 = new QGridLayout(tab_Res_Visualization);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        graphicsView_ResVis = new QGraphicsView(tab_Res_Visualization);
        graphicsView_ResVis->setObjectName(QString::fromUtf8("graphicsView_ResVis"));
        graphicsView_ResVis->setMouseTracking(true);

        gridLayout_4->addWidget(graphicsView_ResVis, 0, 0, 1, 1);

        tabWidget_Results->addTab(tab_Res_Visualization, QString());
        tab_Res_Analysis = new QWidget();
        tab_Res_Analysis->setObjectName(QString::fromUtf8("tab_Res_Analysis"));
        gridLayout_5 = new QGridLayout(tab_Res_Analysis);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        stackedWidget_ResAna_Type = new QStackedWidget(tab_Res_Analysis);
        stackedWidget_ResAna_Type->setObjectName(QString::fromUtf8("stackedWidget_ResAna_Type"));
        stackedWidget_ResAna_InputHist = new QWidget();
        stackedWidget_ResAna_InputHist->setObjectName(QString::fromUtf8("stackedWidget_ResAna_InputHist"));
        gridLayout_10 = new QGridLayout(stackedWidget_ResAna_InputHist);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        gridLayout_ResAna_InputHist = new QGridLayout();
        gridLayout_ResAna_InputHist->setObjectName(QString::fromUtf8("gridLayout_ResAna_InputHist"));

        gridLayout_10->addLayout(gridLayout_ResAna_InputHist, 0, 0, 1, 1);

        stackedWidget_ResAna_Type->addWidget(stackedWidget_ResAna_InputHist);
        stackedWidget_ResAna_DiaHist = new QWidget();
        stackedWidget_ResAna_DiaHist->setObjectName(QString::fromUtf8("stackedWidget_ResAna_DiaHist"));
        gridLayout_6 = new QGridLayout(stackedWidget_ResAna_DiaHist);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        comboBox_ResAna_DiaHist_PoolingWeights = new QComboBox(stackedWidget_ResAna_DiaHist);
        comboBox_ResAna_DiaHist_PoolingWeights->setObjectName(QString::fromUtf8("comboBox_ResAna_DiaHist_PoolingWeights"));
        comboBox_ResAna_DiaHist_PoolingWeights->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox_ResAna_DiaHist_PoolingWeights->sizePolicy().hasHeightForWidth());
        comboBox_ResAna_DiaHist_PoolingWeights->setSizePolicy(sizePolicy2);

        gridLayout_6->addWidget(comboBox_ResAna_DiaHist_PoolingWeights, 0, 6, 1, 2);

        line_6 = new QFrame(stackedWidget_ResAna_DiaHist);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_6, 0, 5, 1, 1);

        checkBox_ResAna_DiaHist_Uni = new QCheckBox(stackedWidget_ResAna_DiaHist);
        checkBox_ResAna_DiaHist_Uni->setObjectName(QString::fromUtf8("checkBox_ResAna_DiaHist_Uni"));
        checkBox_ResAna_DiaHist_Uni->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(checkBox_ResAna_DiaHist_Uni->sizePolicy().hasHeightForWidth());
        checkBox_ResAna_DiaHist_Uni->setSizePolicy(sizePolicy3);
        checkBox_ResAna_DiaHist_Uni->setChecked(true);

        gridLayout_6->addWidget(checkBox_ResAna_DiaHist_Uni, 0, 1, 1, 1);

        checkBox_ResAna_DiaHist_Acc = new QCheckBox(stackedWidget_ResAna_DiaHist);
        checkBox_ResAna_DiaHist_Acc->setObjectName(QString::fromUtf8("checkBox_ResAna_DiaHist_Acc"));
        sizePolicy3.setHeightForWidth(checkBox_ResAna_DiaHist_Acc->sizePolicy().hasHeightForWidth());
        checkBox_ResAna_DiaHist_Acc->setSizePolicy(sizePolicy3);
        checkBox_ResAna_DiaHist_Acc->setChecked(false);

        gridLayout_6->addWidget(checkBox_ResAna_DiaHist_Acc, 0, 0, 1, 1);

        label_ResAna_DiaHist_Classes = new QLabel(stackedWidget_ResAna_DiaHist);
        label_ResAna_DiaHist_Classes->setObjectName(QString::fromUtf8("label_ResAna_DiaHist_Classes"));
        label_ResAna_DiaHist_Classes->setEnabled(false);
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_ResAna_DiaHist_Classes->sizePolicy().hasHeightForWidth());
        label_ResAna_DiaHist_Classes->setSizePolicy(sizePolicy4);

        gridLayout_6->addWidget(label_ResAna_DiaHist_Classes, 0, 3, 1, 1);

        spinBox_ResAna_DiaHist_Classes = new QSpinBox(stackedWidget_ResAna_DiaHist);
        spinBox_ResAna_DiaHist_Classes->setObjectName(QString::fromUtf8("spinBox_ResAna_DiaHist_Classes"));
        spinBox_ResAna_DiaHist_Classes->setEnabled(false);
        sizePolicy3.setHeightForWidth(spinBox_ResAna_DiaHist_Classes->sizePolicy().hasHeightForWidth());
        spinBox_ResAna_DiaHist_Classes->setSizePolicy(sizePolicy3);
        spinBox_ResAna_DiaHist_Classes->setMinimum(1);
        spinBox_ResAna_DiaHist_Classes->setMaximum(10000);
        spinBox_ResAna_DiaHist_Classes->setSingleStep(50);
        spinBox_ResAna_DiaHist_Classes->setValue(200);

        gridLayout_6->addWidget(spinBox_ResAna_DiaHist_Classes, 0, 4, 1, 1);

        line_ResAna_DiaHist = new QFrame(stackedWidget_ResAna_DiaHist);
        line_ResAna_DiaHist->setObjectName(QString::fromUtf8("line_ResAna_DiaHist"));
        line_ResAna_DiaHist->setFrameShape(QFrame::VLine);
        line_ResAna_DiaHist->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_ResAna_DiaHist, 0, 2, 1, 1);

        gridLayout_ResAna_DiaHist = new QGridLayout();
        gridLayout_ResAna_DiaHist->setObjectName(QString::fromUtf8("gridLayout_ResAna_DiaHist"));

        gridLayout_6->addLayout(gridLayout_ResAna_DiaHist, 1, 0, 1, 8);

        stackedWidget_ResAna_Type->addWidget(stackedWidget_ResAna_DiaHist);
        stackedWidget_ResAna_DiaStat = new QWidget();
        stackedWidget_ResAna_DiaStat->setObjectName(QString::fromUtf8("stackedWidget_ResAna_DiaStat"));
        gridLayout_8 = new QGridLayout(stackedWidget_ResAna_DiaStat);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        tableWidget_ResAna_DiaStat = new QTableWidget(stackedWidget_ResAna_DiaStat);
        tableWidget_ResAna_DiaStat->setObjectName(QString::fromUtf8("tableWidget_ResAna_DiaStat"));

        gridLayout_8->addWidget(tableWidget_ResAna_DiaStat, 0, 0, 1, 1);

        stackedWidget_ResAna_Type->addWidget(stackedWidget_ResAna_DiaStat);
        stackedWidget_ResAna_Euler = new QWidget();
        stackedWidget_ResAna_Euler->setObjectName(QString::fromUtf8("stackedWidget_ResAna_Euler"));
        gridLayout_7 = new QGridLayout(stackedWidget_ResAna_Euler);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        tableWidget_ResAna_Euler = new QTableWidget(stackedWidget_ResAna_Euler);
        tableWidget_ResAna_Euler->setObjectName(QString::fromUtf8("tableWidget_ResAna_Euler"));

        gridLayout_7->addWidget(tableWidget_ResAna_Euler, 0, 0, 1, 1);

        stackedWidget_ResAna_Type->addWidget(stackedWidget_ResAna_Euler);
        stackedWidget_ResAna_PixelRatio = new QWidget();
        stackedWidget_ResAna_PixelRatio->setObjectName(QString::fromUtf8("stackedWidget_ResAna_PixelRatio"));
        gridLayout_9 = new QGridLayout(stackedWidget_ResAna_PixelRatio);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        tableWidget_ResAna_PixelRatio = new QTableWidget(stackedWidget_ResAna_PixelRatio);
        tableWidget_ResAna_PixelRatio->setObjectName(QString::fromUtf8("tableWidget_ResAna_PixelRatio"));

        gridLayout_9->addWidget(tableWidget_ResAna_PixelRatio, 0, 0, 1, 1);

        stackedWidget_ResAna_Type->addWidget(stackedWidget_ResAna_PixelRatio);

        gridLayout_5->addWidget(stackedWidget_ResAna_Type, 6, 0, 1, 1);

        comboBox_ResAna_SingleStack = new QComboBox(tab_Res_Analysis);
        comboBox_ResAna_SingleStack->addItem(QString());
        comboBox_ResAna_SingleStack->setObjectName(QString::fromUtf8("comboBox_ResAna_SingleStack"));

        gridLayout_5->addWidget(comboBox_ResAna_SingleStack, 4, 0, 1, 1);

        comboBox_ResAna_Type = new QComboBox(tab_Res_Analysis);
        comboBox_ResAna_Type->addItem(QString());
        comboBox_ResAna_Type->setObjectName(QString::fromUtf8("comboBox_ResAna_Type"));

        gridLayout_5->addWidget(comboBox_ResAna_Type, 5, 0, 1, 1);

        tabWidget_Results->addTab(tab_Res_Analysis, QString());

        gridLayout->addWidget(tabWidget_Results, 0, 1, 2, 1);

        D_MAKRO_DnaFiber->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_DnaFiber);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1018, 21));
        menuData = new QMenu(menubar);
        menuData->setObjectName(QString::fromUtf8("menuData"));
        menuUpdate = new QMenu(menubar);
        menuUpdate->setObjectName(QString::fromUtf8("menuUpdate"));
        menuSave = new QMenu(menubar);
        menuSave->setObjectName(QString::fromUtf8("menuSave"));
        D_MAKRO_DnaFiber->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_DnaFiber);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_DnaFiber->setStatusBar(statusbar);

        menubar->addAction(menuData->menuAction());
        menubar->addAction(menuSave->menuAction());
        menubar->addAction(menuUpdate->menuAction());
        menuData->addAction(action_Load_Images);
        menuUpdate->addAction(action_Update_Image_Processing);
        menuUpdate->addAction(action_Update_Results);
        menuSave->addAction(action_Save_Image_Proc);
        menuSave->addAction(action_Save_Image_Visualize);
        menuSave->addAction(action_Save_Plot_Input_Gray_Values);
        menuSave->addAction(action_Save_Plot_Diameter_Histogram);
        menuSave->addAction(action_Save_Table_Diameter_Statistics);
        menuSave->addAction(action_Save_Table_Euler_Characteristic);
        menuSave->addAction(action_Save_Table_Pixel_Ratios);
        menuSave->addSeparator();
        menuSave->addAction(action_Save_Analysis_Single);
        menuSave->addAction(action_Save_Analysis_Stack);

        retranslateUi(D_MAKRO_DnaFiber);
        QObject::connect(comboBox_ResAna_Type, SIGNAL(currentIndexChanged(int)), stackedWidget_ResAna_Type, SLOT(setCurrentIndex(int)));

        tabWidget_Results->setCurrentIndex(1);
        stackedWidget_ResAna_Type->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(D_MAKRO_DnaFiber);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_DnaFiber)
    {
        D_MAKRO_DnaFiber->setWindowTitle(QCoreApplication::translate("D_MAKRO_DnaFiber", "MainWindow", nullptr));
        action_Load_Images->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Load Images", nullptr));
#if QT_CONFIG(shortcut)
        action_Load_Images->setShortcut(QCoreApplication::translate("D_MAKRO_DnaFiber", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Update_Image_Processing->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Update Image Processing", nullptr));
#if QT_CONFIG(shortcut)
        action_Update_Image_Processing->setShortcut(QCoreApplication::translate("D_MAKRO_DnaFiber", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Update_Results->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Update Results", nullptr));
#if QT_CONFIG(shortcut)
        action_Update_Results->setShortcut(QCoreApplication::translate("D_MAKRO_DnaFiber", "F6", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Save_Image_Proc->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Save Image Proc", nullptr));
        action_Save_Image_Visualize->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Save Image Visualize", nullptr));
        action_Save_Plot_Diameter_Histogram->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Save Plot Diameter Histogram", nullptr));
        action_Save_Table_Diameter_Statistics->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Save Table Diameter Statistics", nullptr));
        action_Save_Analysis_Single->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Save Analysis Single", nullptr));
        action_Save_Analysis_Stack->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Save Analysis Stack", nullptr));
#if QT_CONFIG(shortcut)
        action_Save_Analysis_Stack->setShortcut(QCoreApplication::translate("D_MAKRO_DnaFiber", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Save_Plot_Input_Gray_Values->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Save Plot Input Gray Values", nullptr));
        action_Save_Table_Euler_Characteristic->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Save Table Euler Characteristic", nullptr));
        action_Save_Table_Pixel_Ratios->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Save Table Pixel Ratios", nullptr));
        groupBox_Controls->setTitle(QCoreApplication::translate("D_MAKRO_DnaFiber", "Controls Image Processing", nullptr));
        label_14->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Z", nullptr));
        spinBox_Controls_Eilenstein_Z->setSuffix(QCoreApplication::translate("D_MAKRO_DnaFiber", " px", nullptr));
        spinBox_Controls_Median_Size_Z->setSuffix(QCoreApplication::translate("D_MAKRO_DnaFiber", " px", nullptr));
        label_13->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "X/Y", nullptr));
        label_5->setText(QString());
        label_6->setText(QString());
        label_15->setText(QString());
        label_16->setText(QString());
        label_Controls_Skelleton_ThreshOfVol->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "/ 27 vx = 85,2%", nullptr));
        label_18->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Description", nullptr));
        label_19->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Type", nullptr));
        label_20->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Step", nullptr));
        spinBox_Controls_Binary_Thres->setSuffix(QCoreApplication::translate("D_MAKRO_DnaFiber", " GVU", nullptr));
        doubleSpinBox_Controls_Spacing_XY->setSuffix(QCoreApplication::translate("D_MAKRO_DnaFiber", " nm", nullptr));
        label_4->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Thresh", nullptr));
        label_7->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Skelleton", nullptr));
        label->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Blur", nullptr));
        label_2->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Size", nullptr));
        spinBox_Controls_Eilenstein_XY->setSuffix(QCoreApplication::translate("D_MAKRO_DnaFiber", " px", nullptr));
        label_3->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Binary", nullptr));
        label_9->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Eilenstein", nullptr));
        label_11->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Spacing", nullptr));
        label_12->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Size per Pixel", nullptr));
        label_10->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Size", nullptr));
        doubleSpinBox_Controls_Spacing_Z->setSuffix(QCoreApplication::translate("D_MAKRO_DnaFiber", " nm", nullptr));
        spinBox_Controls_Median_Size_XY->setSuffix(QCoreApplication::translate("D_MAKRO_DnaFiber", " px", nullptr));
        spinBox_Controls_Skelleton_Thres->setSuffix(QCoreApplication::translate("D_MAKRO_DnaFiber", " vx", nullptr));
        label_8->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Thresh", nullptr));
        pushButton_Controls_SaveParam->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Save Parameters in File", nullptr));
        label_17->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Parameters", nullptr));
        label_21->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Save", nullptr));
        label_22->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Use as defaults for this image", nullptr));
        groupBox_ImgProc->setTitle(QCoreApplication::translate("D_MAKRO_DnaFiber", "Images", nullptr));
        spinBox_ImgProc_View_Y->setSuffix(QCoreApplication::translate("D_MAKRO_DnaFiber", "px (0nm)", nullptr));
        spinBox_ImgProc_View_Y->setPrefix(QCoreApplication::translate("D_MAKRO_DnaFiber", "Y = ", nullptr));
        comboBox_ImgProc_Step->setItemText(0, QCoreApplication::translate("D_MAKRO_DnaFiber", "image processing steps", nullptr));

        comboBox_ImgProc_Img->setItemText(0, QCoreApplication::translate("D_MAKRO_DnaFiber", "[please load images]", nullptr));

        comboBox_ImgProc_View_Plane->setItemText(0, QCoreApplication::translate("D_MAKRO_DnaFiber", "planes", nullptr));

        spinBox_ImgProc_View_Z->setSuffix(QCoreApplication::translate("D_MAKRO_DnaFiber", "px (0nm)", nullptr));
        spinBox_ImgProc_View_Z->setPrefix(QCoreApplication::translate("D_MAKRO_DnaFiber", "Z = ", nullptr));
        spinBox_ImgProc_View_X->setSuffix(QCoreApplication::translate("D_MAKRO_DnaFiber", "px (0nm)", nullptr));
        spinBox_ImgProc_View_X->setPrefix(QCoreApplication::translate("D_MAKRO_DnaFiber", "X = ", nullptr));
        tabWidget_Results->setTabText(tabWidget_Results->indexOf(tab_Res_Visualization), QCoreApplication::translate("D_MAKRO_DnaFiber", "Visualization", nullptr));
        checkBox_ResAna_DiaHist_Uni->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Uniform", nullptr));
        checkBox_ResAna_DiaHist_Acc->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Accumulate", nullptr));
        label_ResAna_DiaHist_Classes->setText(QCoreApplication::translate("D_MAKRO_DnaFiber", "Classes:", nullptr));
        comboBox_ResAna_SingleStack->setItemText(0, QCoreApplication::translate("D_MAKRO_DnaFiber", "[single/stack]", nullptr));

        comboBox_ResAna_Type->setItemText(0, QCoreApplication::translate("D_MAKRO_DnaFiber", "[AnalysisType]", nullptr));

        tabWidget_Results->setTabText(tabWidget_Results->indexOf(tab_Res_Analysis), QCoreApplication::translate("D_MAKRO_DnaFiber", "Analysis", nullptr));
        menuData->setTitle(QCoreApplication::translate("D_MAKRO_DnaFiber", "Load", nullptr));
        menuUpdate->setTitle(QCoreApplication::translate("D_MAKRO_DnaFiber", "Update", nullptr));
        menuSave->setTitle(QCoreApplication::translate("D_MAKRO_DnaFiber", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_DnaFiber: public Ui_D_MAKRO_DnaFiber {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_DNAFIBER_H
