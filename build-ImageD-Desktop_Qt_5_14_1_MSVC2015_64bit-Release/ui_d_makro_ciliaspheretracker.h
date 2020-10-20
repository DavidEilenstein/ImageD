/********************************************************************************
** Form generated from reading UI file 'd_makro_ciliaspheretracker.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_CILIASPHERETRACKER_H
#define UI_D_MAKRO_CILIASPHERETRACKER_H

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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_CiliaSphereTracker
{
public:
    QAction *action_Data_Add;
    QAction *action_Data_Clear;
    QAction *action_Show_Minimum;
    QAction *action_Show_Normal;
    QAction *action_Show_Maximum;
    QAction *action_Show_Fullscreen;
    QAction *action_Save_Analysis_All;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_Res;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_Res_GridSamplingParam;
    QGridLayout *gridLayout_8;
    QSpinBox *spinBox_ParamGridHorizontal;
    QSpinBox *spinBox_ParamGridVertical;
    QSpinBox *spinBox_ParamGrid_CellEnd;
    QSpinBox *spinBox_ParamGrid_CellStart;
    QGroupBox *groupBox_Res_TimeAxis;
    QGridLayout *gridLayout_24;
    QComboBox *comboBox_Res_PlotLine_FixRange_T;
    QDoubleSpinBox *doubleSpinBox_Res_PlotLine_FixRange_T_max;
    QLabel *label_16;
    QLabel *label_15;
    QSpinBox *spinBox_Res_PlotPoincare_Shift_Frames;
    QDoubleSpinBox *doubleSpinBox_Res_PlotLine_FixRange_T_min;
    QFrame *line_4;
    QDoubleSpinBox *doubleSpinBox_Res_PlotPoincare_Shift_Seconds;
    QGroupBox *groupBox_Res_VectorFieldParam;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QComboBox *comboBox_Res_VectorFieldParam_Length_Value;
    QLabel *label_7;
    QComboBox *comboBox_Res_VectorFieldParam_Length_Error;
    QLabel *label_6;
    QComboBox *comboBox_Res_VectorFieldParam_Angle_Value;
    QLabel *label_12;
    QComboBox *comboBox_Res_VectorFieldParam_Angle_Error;
    QFrame *line_8;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds;
    QDoubleSpinBox *doubleSpinBox_Res_VectorFieldParam_ScaleLength;
    QSpinBox *spinBox_Res_VectorFieldParam_Thickness_Vector;
    QSpinBox *spinBox_Res_VectorFieldParam_KindeySteps;
    QSpinBox *spinBox_Res_VectorFieldParam_Thickness_Error;
    QGroupBox *groupBox_Res_GraphicsParam;
    QGridLayout *gridLayout_7;
    QDoubleSpinBox *doubleSpinBox_Res_TimeProjSum_Gamma;
    QDoubleSpinBox *doubleSpinBox_Res_TimeProjSum_ColorHigh;
    QCheckBox *checkBox_Res_TimeProjSum_ColorLow;
    QCheckBox *checkBox_Res_TimeProjSum_Gamma;
    QCheckBox *checkBox_Res_TimeProjSum_ColorHigh;
    QDoubleSpinBox *doubleSpinBox_Res_TimeProjSum_ColorLow;
    QComboBox *comboBox;
    QGroupBox *groupBox_Res_AngleCustom;
    QGridLayout *gridLayout_16;
    QLabel *label_14;
    QComboBox *comboBox_Res_AngleCustom_Stat_Uncertanty;
    QFrame *line_7;
    QDoubleSpinBox *doubleSpinBox_Res_PlotLine_FixRange_A_min;
    QLabel *label_Res_AngleCustom_Stat_Uncertanty;
    QCheckBox *checkBox_Res_PlotLine_FixRange_A;
    QComboBox *comboBox_Res_AngleCustom_Stat_Value;
    QDoubleSpinBox *doubleSpinBox_Res_PlotLine_FixRange_A_max;
    QGroupBox *groupBox_Res_MovAv;
    QGridLayout *gridLayout_17;
    QGridLayout *gridLayout_18;
    QSlider *horizontalSlider_Res_MovAv_CurrentStart;
    QSlider *horizontalSlider_Res_MovAv_CurrentEnd;
    QSpinBox *spinBox_Res_MovAv_CurrentFrame;
    QDoubleSpinBox *doubleSpinBox_Res_MovAv_CurrentTime;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_Res_MovAv_TimeWindow;
    QComboBox *comboBox_Res_MovAv_Background;
    QDoubleSpinBox *doubleSpinBox_Res_MovAv_ReqFrmWithDetect;
    QSpinBox *spinBox_Res_MovAv_WindowFrames;
    QDoubleSpinBox *doubleSpinBox_Res_MovAv_WindowTime;
    QStackedWidget *stackedWidget_Res_Type;
    QWidget *page_Res_Graphics;
    QGridLayout *gridLayout_6;
    QGraphicsView *graphicsView_Results;
    QWidget *page_Res_PlotTable;
    QGridLayout *gridLayout_9;
    QTabWidget *tabWidget_ResType;
    QWidget *tab_ResPlotLine;
    QGridLayout *gridLayout_19;
    QGridLayout *gridLayout_ResPlotLine;
    QWidget *tab_ResPlotPoincare;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_ResPlotPoincare;
    QWidget *tab_ResTable;
    QGridLayout *gridLayout_12;
    QTableWidget *tableWidget_Results;
    QWidget *page_Res_Overview;
    QGridLayout *gridLayout_23;
    QGridLayout *gridLayout_Res_Overview_SpeedLine;
    QGridLayout *gridLayout_Res_Overview_SpeedPoincare;
    QGridLayout *gridLayout_Res_Overview_AngleLine;
    QGridLayout *gridLayout_Res_Overview_AnglePoincare;
    QGroupBox *groupBox_Res_SpeedCustom;
    QGridLayout *gridLayout_15;
    QComboBox *comboBox_Res_SpeedCustom_Stat_Value;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_Res_PlotLine_FixRange_S_min;
    QCheckBox *checkBox_Res_PlotLine_FixRange_S;
    QDoubleSpinBox *doubleSpinBox_Res_PlotLine_FixRange_S_max;
    QLabel *label_Res_SpeedCustom_Stat_Uncertanty;
    QFrame *line_3;
    QComboBox *comboBox_Res_SpeedCustom_Stat_Uncertanty;
    QComboBox *comboBox_Res_Type;
    QGroupBox *groupBox_Res_GridVisParam;
    QGridLayout *gridLayout_14;
    QDoubleSpinBox *doubleSpinBox_Res_GridVisParam_Label_Scaling;
    QCheckBox *checkBox_Res_GridVisParam_Grid;
    QSpinBox *spinBox_Res_GridVisParam_Thickness_Grid;
    QCheckBox *checkBox_Res_GridVisParam_Labels;
    QSpinBox *spinBox_Res_GridVisParam_Thickness_Label;
    QGroupBox *groupBox_Res_Heat;
    QGridLayout *gridLayout_11;
    QComboBox *comboBox_Res_Heat_Mode;
    QGroupBox *groupBox_Data;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_Data_Add;
    QPushButton *pushButton_Data_Clear;
    QComboBox *comboBox_Data_Videos;
    QGroupBox *groupBox_Param;
    QGridLayout *gridLayout_5;
    QDoubleSpinBox *doubleSpinBox_Param_Blur_Sigma;
    QSpinBox *spinBox_Param_FrameCountSmooth;
    QDoubleSpinBox *doubleSpinBox_Param_Crop_Start;
    QFrame *line_2;
    QDoubleSpinBox *doubleSpinBox_Param_Scale_mm;
    QSpinBox *spinBox_Param_Crop_Left;
    QLabel *label;
    QLabel *label_Param_CropHeight;
    QLabel *label_9;
    QSpinBox *spinBox_Param_Crop_Bottom;
    QSpinBox *spinBox_Param_Crop_Top;
    QFrame *line;
    QLabel *label_3;
    QSpinBox *spinBox_Param_Blur_Size;
    QLabel *label_2;
    QLabel *label_Param_CropTime;
    QLabel *label_8;
    QSpinBox *spinBox_Param_Crop_Right;
    QLabel *label_10;
    QFrame *line_6;
    QLabel *label_Param_CropWidth;
    QDoubleSpinBox *doubleSpinBox_Param_Crop_End;
    QLabel *label_11;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_Param_MaxSpeed;
    QDoubleSpinBox *doubleSpinBox_Param_Scale_Px;
    QGroupBox *groupBox_Proc;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *doubleSpinBox_Proc_Time;
    QComboBox *comboBox_Proc_Step;
    QGraphicsView *graphicsView_Proc;
    QPushButton *pushButton_Proc_FullVideo;
    QSpinBox *spinBox_Proc_Frame;
    QSlider *horizontalSlider_Proc_Frame;
    QMenuBar *menubar;
    QMenu *menuData;
    QMenu *menuWindow;
    QMenu *menuAnalysis;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_CiliaSphereTracker)
    {
        if (D_MAKRO_CiliaSphereTracker->objectName().isEmpty())
            D_MAKRO_CiliaSphereTracker->setObjectName(QString::fromUtf8("D_MAKRO_CiliaSphereTracker"));
        D_MAKRO_CiliaSphereTracker->resize(1155, 751);
        action_Data_Add = new QAction(D_MAKRO_CiliaSphereTracker);
        action_Data_Add->setObjectName(QString::fromUtf8("action_Data_Add"));
        action_Data_Clear = new QAction(D_MAKRO_CiliaSphereTracker);
        action_Data_Clear->setObjectName(QString::fromUtf8("action_Data_Clear"));
        action_Show_Minimum = new QAction(D_MAKRO_CiliaSphereTracker);
        action_Show_Minimum->setObjectName(QString::fromUtf8("action_Show_Minimum"));
        action_Show_Normal = new QAction(D_MAKRO_CiliaSphereTracker);
        action_Show_Normal->setObjectName(QString::fromUtf8("action_Show_Normal"));
        action_Show_Maximum = new QAction(D_MAKRO_CiliaSphereTracker);
        action_Show_Maximum->setObjectName(QString::fromUtf8("action_Show_Maximum"));
        action_Show_Fullscreen = new QAction(D_MAKRO_CiliaSphereTracker);
        action_Show_Fullscreen->setObjectName(QString::fromUtf8("action_Show_Fullscreen"));
        action_Save_Analysis_All = new QAction(D_MAKRO_CiliaSphereTracker);
        action_Save_Analysis_All->setObjectName(QString::fromUtf8("action_Save_Analysis_All"));
        centralwidget = new QWidget(D_MAKRO_CiliaSphereTracker);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_Res = new QGroupBox(centralwidget);
        groupBox_Res->setObjectName(QString::fromUtf8("groupBox_Res"));
        groupBox_Res->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_Res->sizePolicy().hasHeightForWidth());
        groupBox_Res->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(groupBox_Res);
        gridLayout_4->setSpacing(3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(6, 6, 6, 6);
        groupBox_Res_GridSamplingParam = new QGroupBox(groupBox_Res);
        groupBox_Res_GridSamplingParam->setObjectName(QString::fromUtf8("groupBox_Res_GridSamplingParam"));
        groupBox_Res_GridSamplingParam->setFlat(true);
        gridLayout_8 = new QGridLayout(groupBox_Res_GridSamplingParam);
        gridLayout_8->setSpacing(3);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 3, 0, 3);
        spinBox_ParamGridHorizontal = new QSpinBox(groupBox_Res_GridSamplingParam);
        spinBox_ParamGridHorizontal->setObjectName(QString::fromUtf8("spinBox_ParamGridHorizontal"));
        spinBox_ParamGridHorizontal->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ParamGridHorizontal->setMinimum(1);
        spinBox_ParamGridHorizontal->setMaximum(999);
        spinBox_ParamGridHorizontal->setValue(5);

        gridLayout_8->addWidget(spinBox_ParamGridHorizontal, 0, 1, 1, 1);

        spinBox_ParamGridVertical = new QSpinBox(groupBox_Res_GridSamplingParam);
        spinBox_ParamGridVertical->setObjectName(QString::fromUtf8("spinBox_ParamGridVertical"));
        spinBox_ParamGridVertical->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ParamGridVertical->setMinimum(1);
        spinBox_ParamGridVertical->setMaximum(999);
        spinBox_ParamGridVertical->setValue(4);

        gridLayout_8->addWidget(spinBox_ParamGridVertical, 0, 0, 1, 1);

        spinBox_ParamGrid_CellEnd = new QSpinBox(groupBox_Res_GridSamplingParam);
        spinBox_ParamGrid_CellEnd->setObjectName(QString::fromUtf8("spinBox_ParamGrid_CellEnd"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox_ParamGrid_CellEnd->sizePolicy().hasHeightForWidth());
        spinBox_ParamGrid_CellEnd->setSizePolicy(sizePolicy1);
        spinBox_ParamGrid_CellEnd->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ParamGrid_CellEnd->setMinimum(1);
        spinBox_ParamGrid_CellEnd->setMaximum(20);
        spinBox_ParamGrid_CellEnd->setValue(20);

        gridLayout_8->addWidget(spinBox_ParamGrid_CellEnd, 0, 3, 1, 1);

        spinBox_ParamGrid_CellStart = new QSpinBox(groupBox_Res_GridSamplingParam);
        spinBox_ParamGrid_CellStart->setObjectName(QString::fromUtf8("spinBox_ParamGrid_CellStart"));
        sizePolicy1.setHeightForWidth(spinBox_ParamGrid_CellStart->sizePolicy().hasHeightForWidth());
        spinBox_ParamGrid_CellStart->setSizePolicy(sizePolicy1);
        spinBox_ParamGrid_CellStart->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ParamGrid_CellStart->setMaximum(19);

        gridLayout_8->addWidget(spinBox_ParamGrid_CellStart, 0, 2, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_GridSamplingParam, 9, 0, 1, 2);

        groupBox_Res_TimeAxis = new QGroupBox(groupBox_Res);
        groupBox_Res_TimeAxis->setObjectName(QString::fromUtf8("groupBox_Res_TimeAxis"));
        groupBox_Res_TimeAxis->setFlat(true);
        gridLayout_24 = new QGridLayout(groupBox_Res_TimeAxis);
        gridLayout_24->setSpacing(3);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        gridLayout_24->setContentsMargins(0, 3, 0, 3);
        comboBox_Res_PlotLine_FixRange_T = new QComboBox(groupBox_Res_TimeAxis);
        comboBox_Res_PlotLine_FixRange_T->setObjectName(QString::fromUtf8("comboBox_Res_PlotLine_FixRange_T"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox_Res_PlotLine_FixRange_T->sizePolicy().hasHeightForWidth());
        comboBox_Res_PlotLine_FixRange_T->setSizePolicy(sizePolicy2);

        gridLayout_24->addWidget(comboBox_Res_PlotLine_FixRange_T, 0, 1, 1, 1);

        doubleSpinBox_Res_PlotLine_FixRange_T_max = new QDoubleSpinBox(groupBox_Res_TimeAxis);
        doubleSpinBox_Res_PlotLine_FixRange_T_max->setObjectName(QString::fromUtf8("doubleSpinBox_Res_PlotLine_FixRange_T_max"));
        doubleSpinBox_Res_PlotLine_FixRange_T_max->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(doubleSpinBox_Res_PlotLine_FixRange_T_max->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_PlotLine_FixRange_T_max->setSizePolicy(sizePolicy3);
        doubleSpinBox_Res_PlotLine_FixRange_T_max->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_PlotLine_FixRange_T_max->setMaximum(9999.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_T_max->setValue(120.000000000000000);

        gridLayout_24->addWidget(doubleSpinBox_Res_PlotLine_FixRange_T_max, 0, 3, 1, 1);

        label_16 = new QLabel(groupBox_Res_TimeAxis);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_24->addWidget(label_16, 0, 5, 1, 1);

        label_15 = new QLabel(groupBox_Res_TimeAxis);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy4);

        gridLayout_24->addWidget(label_15, 0, 0, 1, 1);

        spinBox_Res_PlotPoincare_Shift_Frames = new QSpinBox(groupBox_Res_TimeAxis);
        spinBox_Res_PlotPoincare_Shift_Frames->setObjectName(QString::fromUtf8("spinBox_Res_PlotPoincare_Shift_Frames"));
        sizePolicy1.setHeightForWidth(spinBox_Res_PlotPoincare_Shift_Frames->sizePolicy().hasHeightForWidth());
        spinBox_Res_PlotPoincare_Shift_Frames->setSizePolicy(sizePolicy1);
        spinBox_Res_PlotPoincare_Shift_Frames->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_PlotPoincare_Shift_Frames->setValue(1);

        gridLayout_24->addWidget(spinBox_Res_PlotPoincare_Shift_Frames, 0, 6, 1, 1);

        doubleSpinBox_Res_PlotLine_FixRange_T_min = new QDoubleSpinBox(groupBox_Res_TimeAxis);
        doubleSpinBox_Res_PlotLine_FixRange_T_min->setObjectName(QString::fromUtf8("doubleSpinBox_Res_PlotLine_FixRange_T_min"));
        doubleSpinBox_Res_PlotLine_FixRange_T_min->setEnabled(false);
        sizePolicy3.setHeightForWidth(doubleSpinBox_Res_PlotLine_FixRange_T_min->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_PlotLine_FixRange_T_min->setSizePolicy(sizePolicy3);
        doubleSpinBox_Res_PlotLine_FixRange_T_min->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_PlotLine_FixRange_T_min->setMaximum(9999.000000000000000);

        gridLayout_24->addWidget(doubleSpinBox_Res_PlotLine_FixRange_T_min, 0, 2, 1, 1);

        line_4 = new QFrame(groupBox_Res_TimeAxis);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_24->addWidget(line_4, 0, 4, 1, 1);

        doubleSpinBox_Res_PlotPoincare_Shift_Seconds = new QDoubleSpinBox(groupBox_Res_TimeAxis);
        doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setObjectName(QString::fromUtf8("doubleSpinBox_Res_PlotPoincare_Shift_Seconds"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_Res_PlotPoincare_Shift_Seconds->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setSizePolicy(sizePolicy1);
        doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setDecimals(2);
        doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setValue(0.020000000000000);

        gridLayout_24->addWidget(doubleSpinBox_Res_PlotPoincare_Shift_Seconds, 0, 7, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_TimeAxis, 5, 0, 1, 2);

        groupBox_Res_VectorFieldParam = new QGroupBox(groupBox_Res);
        groupBox_Res_VectorFieldParam->setObjectName(QString::fromUtf8("groupBox_Res_VectorFieldParam"));
        groupBox_Res_VectorFieldParam->setFlat(true);
        gridLayout_10 = new QGridLayout(groupBox_Res_VectorFieldParam);
        gridLayout_10->setSpacing(3);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 3, 0, 3);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(groupBox_Res_VectorFieldParam);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy4.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy4);

        horizontalLayout_2->addWidget(label_5);

        comboBox_Res_VectorFieldParam_Length_Value = new QComboBox(groupBox_Res_VectorFieldParam);
        comboBox_Res_VectorFieldParam_Length_Value->setObjectName(QString::fromUtf8("comboBox_Res_VectorFieldParam_Length_Value"));

        horizontalLayout_2->addWidget(comboBox_Res_VectorFieldParam_Length_Value);

        label_7 = new QLabel(groupBox_Res_VectorFieldParam);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy4.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy4);

        horizontalLayout_2->addWidget(label_7);

        comboBox_Res_VectorFieldParam_Length_Error = new QComboBox(groupBox_Res_VectorFieldParam);
        comboBox_Res_VectorFieldParam_Length_Error->setObjectName(QString::fromUtf8("comboBox_Res_VectorFieldParam_Length_Error"));

        horizontalLayout_2->addWidget(comboBox_Res_VectorFieldParam_Length_Error);

        label_6 = new QLabel(groupBox_Res_VectorFieldParam);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy4.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy4);

        horizontalLayout_2->addWidget(label_6);

        comboBox_Res_VectorFieldParam_Angle_Value = new QComboBox(groupBox_Res_VectorFieldParam);
        comboBox_Res_VectorFieldParam_Angle_Value->setObjectName(QString::fromUtf8("comboBox_Res_VectorFieldParam_Angle_Value"));

        horizontalLayout_2->addWidget(comboBox_Res_VectorFieldParam_Angle_Value);

        label_12 = new QLabel(groupBox_Res_VectorFieldParam);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy4.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy4);

        horizontalLayout_2->addWidget(label_12);

        comboBox_Res_VectorFieldParam_Angle_Error = new QComboBox(groupBox_Res_VectorFieldParam);
        comboBox_Res_VectorFieldParam_Angle_Error->setObjectName(QString::fromUtf8("comboBox_Res_VectorFieldParam_Angle_Error"));

        horizontalLayout_2->addWidget(comboBox_Res_VectorFieldParam_Angle_Error);


        gridLayout_10->addLayout(horizontalLayout_2, 0, 9, 1, 3);

        line_8 = new QFrame(groupBox_Res_VectorFieldParam);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout_10->addWidget(line_8, 2, 9, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds = new QDoubleSpinBox(groupBox_Res_VectorFieldParam);
        doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setObjectName(QString::fromUtf8("doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds"));
        doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setDecimals(2);
        doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setMinimum(0.010000000000000);
        doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setMaximum(99.000000000000000);
        doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setSingleStep(0.250000000000000);
        doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setValue(1.000000000000000);

        horizontalLayout_3->addWidget(doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds);

        doubleSpinBox_Res_VectorFieldParam_ScaleLength = new QDoubleSpinBox(groupBox_Res_VectorFieldParam);
        doubleSpinBox_Res_VectorFieldParam_ScaleLength->setObjectName(QString::fromUtf8("doubleSpinBox_Res_VectorFieldParam_ScaleLength"));
        doubleSpinBox_Res_VectorFieldParam_ScaleLength->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_VectorFieldParam_ScaleLength->setMinimum(0.010000000000000);
        doubleSpinBox_Res_VectorFieldParam_ScaleLength->setMaximum(9999.000000000000000);
        doubleSpinBox_Res_VectorFieldParam_ScaleLength->setValue(1.000000000000000);

        horizontalLayout_3->addWidget(doubleSpinBox_Res_VectorFieldParam_ScaleLength);

        spinBox_Res_VectorFieldParam_Thickness_Vector = new QSpinBox(groupBox_Res_VectorFieldParam);
        spinBox_Res_VectorFieldParam_Thickness_Vector->setObjectName(QString::fromUtf8("spinBox_Res_VectorFieldParam_Thickness_Vector"));
        spinBox_Res_VectorFieldParam_Thickness_Vector->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_VectorFieldParam_Thickness_Vector->setMinimum(1);
        spinBox_Res_VectorFieldParam_Thickness_Vector->setMaximum(99);
        spinBox_Res_VectorFieldParam_Thickness_Vector->setValue(3);

        horizontalLayout_3->addWidget(spinBox_Res_VectorFieldParam_Thickness_Vector);

        spinBox_Res_VectorFieldParam_KindeySteps = new QSpinBox(groupBox_Res_VectorFieldParam);
        spinBox_Res_VectorFieldParam_KindeySteps->setObjectName(QString::fromUtf8("spinBox_Res_VectorFieldParam_KindeySteps"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(spinBox_Res_VectorFieldParam_KindeySteps->sizePolicy().hasHeightForWidth());
        spinBox_Res_VectorFieldParam_KindeySteps->setSizePolicy(sizePolicy5);
        spinBox_Res_VectorFieldParam_KindeySteps->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_VectorFieldParam_KindeySteps->setMaximum(999);
        spinBox_Res_VectorFieldParam_KindeySteps->setValue(720);

        horizontalLayout_3->addWidget(spinBox_Res_VectorFieldParam_KindeySteps);

        spinBox_Res_VectorFieldParam_Thickness_Error = new QSpinBox(groupBox_Res_VectorFieldParam);
        spinBox_Res_VectorFieldParam_Thickness_Error->setObjectName(QString::fromUtf8("spinBox_Res_VectorFieldParam_Thickness_Error"));
        spinBox_Res_VectorFieldParam_Thickness_Error->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_VectorFieldParam_Thickness_Error->setMinimum(1);
        spinBox_Res_VectorFieldParam_Thickness_Error->setMaximum(99);
        spinBox_Res_VectorFieldParam_Thickness_Error->setValue(1);

        horizontalLayout_3->addWidget(spinBox_Res_VectorFieldParam_Thickness_Error);


        gridLayout_10->addLayout(horizontalLayout_3, 1, 9, 1, 3);


        gridLayout_4->addWidget(groupBox_Res_VectorFieldParam, 6, 0, 1, 2);

        groupBox_Res_GraphicsParam = new QGroupBox(groupBox_Res);
        groupBox_Res_GraphicsParam->setObjectName(QString::fromUtf8("groupBox_Res_GraphicsParam"));
        groupBox_Res_GraphicsParam->setFlat(true);
        gridLayout_7 = new QGridLayout(groupBox_Res_GraphicsParam);
        gridLayout_7->setSpacing(3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 3, 0, 3);
        doubleSpinBox_Res_TimeProjSum_Gamma = new QDoubleSpinBox(groupBox_Res_GraphicsParam);
        doubleSpinBox_Res_TimeProjSum_Gamma->setObjectName(QString::fromUtf8("doubleSpinBox_Res_TimeProjSum_Gamma"));
        sizePolicy5.setHeightForWidth(doubleSpinBox_Res_TimeProjSum_Gamma->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_TimeProjSum_Gamma->setSizePolicy(sizePolicy5);
        doubleSpinBox_Res_TimeProjSum_Gamma->setMinimumSize(QSize(50, 0));
        doubleSpinBox_Res_TimeProjSum_Gamma->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_TimeProjSum_Gamma->setSingleStep(0.100000000000000);
        doubleSpinBox_Res_TimeProjSum_Gamma->setValue(0.500000000000000);

        gridLayout_7->addWidget(doubleSpinBox_Res_TimeProjSum_Gamma, 0, 6, 1, 1);

        doubleSpinBox_Res_TimeProjSum_ColorHigh = new QDoubleSpinBox(groupBox_Res_GraphicsParam);
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setObjectName(QString::fromUtf8("doubleSpinBox_Res_TimeProjSum_ColorHigh"));
        sizePolicy5.setHeightForWidth(doubleSpinBox_Res_TimeProjSum_ColorHigh->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setSizePolicy(sizePolicy5);
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setMinimumSize(QSize(100, 0));
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setDecimals(2);
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setMaximum(100.000000000000000);
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setValue(75.000000000000000);

        gridLayout_7->addWidget(doubleSpinBox_Res_TimeProjSum_ColorHigh, 0, 3, 1, 1);

        checkBox_Res_TimeProjSum_ColorLow = new QCheckBox(groupBox_Res_GraphicsParam);
        checkBox_Res_TimeProjSum_ColorLow->setObjectName(QString::fromUtf8("checkBox_Res_TimeProjSum_ColorLow"));
        sizePolicy1.setHeightForWidth(checkBox_Res_TimeProjSum_ColorLow->sizePolicy().hasHeightForWidth());
        checkBox_Res_TimeProjSum_ColorLow->setSizePolicy(sizePolicy1);
        checkBox_Res_TimeProjSum_ColorLow->setChecked(false);

        gridLayout_7->addWidget(checkBox_Res_TimeProjSum_ColorLow, 0, 0, 1, 1);

        checkBox_Res_TimeProjSum_Gamma = new QCheckBox(groupBox_Res_GraphicsParam);
        checkBox_Res_TimeProjSum_Gamma->setObjectName(QString::fromUtf8("checkBox_Res_TimeProjSum_Gamma"));
        sizePolicy1.setHeightForWidth(checkBox_Res_TimeProjSum_Gamma->sizePolicy().hasHeightForWidth());
        checkBox_Res_TimeProjSum_Gamma->setSizePolicy(sizePolicy1);
        checkBox_Res_TimeProjSum_Gamma->setChecked(true);

        gridLayout_7->addWidget(checkBox_Res_TimeProjSum_Gamma, 0, 5, 1, 1);

        checkBox_Res_TimeProjSum_ColorHigh = new QCheckBox(groupBox_Res_GraphicsParam);
        checkBox_Res_TimeProjSum_ColorHigh->setObjectName(QString::fromUtf8("checkBox_Res_TimeProjSum_ColorHigh"));
        sizePolicy1.setHeightForWidth(checkBox_Res_TimeProjSum_ColorHigh->sizePolicy().hasHeightForWidth());
        checkBox_Res_TimeProjSum_ColorHigh->setSizePolicy(sizePolicy1);
        checkBox_Res_TimeProjSum_ColorHigh->setChecked(true);

        gridLayout_7->addWidget(checkBox_Res_TimeProjSum_ColorHigh, 0, 2, 1, 1);

        doubleSpinBox_Res_TimeProjSum_ColorLow = new QDoubleSpinBox(groupBox_Res_GraphicsParam);
        doubleSpinBox_Res_TimeProjSum_ColorLow->setObjectName(QString::fromUtf8("doubleSpinBox_Res_TimeProjSum_ColorLow"));
        sizePolicy5.setHeightForWidth(doubleSpinBox_Res_TimeProjSum_ColorLow->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_TimeProjSum_ColorLow->setSizePolicy(sizePolicy5);
        doubleSpinBox_Res_TimeProjSum_ColorLow->setMinimumSize(QSize(100, 0));
        doubleSpinBox_Res_TimeProjSum_ColorLow->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_TimeProjSum_ColorLow->setDecimals(2);
        doubleSpinBox_Res_TimeProjSum_ColorLow->setMaximum(100.000000000000000);
        doubleSpinBox_Res_TimeProjSum_ColorLow->setValue(0.000000000000000);

        gridLayout_7->addWidget(doubleSpinBox_Res_TimeProjSum_ColorLow, 0, 1, 1, 1);

        comboBox = new QComboBox(groupBox_Res_GraphicsParam);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(false);
        sizePolicy5.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy5);
        comboBox->setMinimumSize(QSize(100, 0));

        gridLayout_7->addWidget(comboBox, 0, 4, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_GraphicsParam, 10, 0, 1, 2);

        groupBox_Res_AngleCustom = new QGroupBox(groupBox_Res);
        groupBox_Res_AngleCustom->setObjectName(QString::fromUtf8("groupBox_Res_AngleCustom"));
        groupBox_Res_AngleCustom->setFlat(true);
        gridLayout_16 = new QGridLayout(groupBox_Res_AngleCustom);
        gridLayout_16->setSpacing(3);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 3, 0, 3);
        label_14 = new QLabel(groupBox_Res_AngleCustom);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy4.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy4);

        gridLayout_16->addWidget(label_14, 0, 0, 1, 1);

        comboBox_Res_AngleCustom_Stat_Uncertanty = new QComboBox(groupBox_Res_AngleCustom);
        comboBox_Res_AngleCustom_Stat_Uncertanty->setObjectName(QString::fromUtf8("comboBox_Res_AngleCustom_Stat_Uncertanty"));

        gridLayout_16->addWidget(comboBox_Res_AngleCustom_Stat_Uncertanty, 0, 3, 1, 1);

        line_7 = new QFrame(groupBox_Res_AngleCustom);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_16->addWidget(line_7, 0, 4, 1, 1);

        doubleSpinBox_Res_PlotLine_FixRange_A_min = new QDoubleSpinBox(groupBox_Res_AngleCustom);
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setObjectName(QString::fromUtf8("doubleSpinBox_Res_PlotLine_FixRange_A_min"));
        sizePolicy3.setHeightForWidth(doubleSpinBox_Res_PlotLine_FixRange_A_min->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setSizePolicy(sizePolicy3);
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setMinimumSize(QSize(50, 0));
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setMaximumSize(QSize(50, 16777215));
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setMinimum(-360.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setMaximum(360.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setValue(-180.000000000000000);

        gridLayout_16->addWidget(doubleSpinBox_Res_PlotLine_FixRange_A_min, 0, 6, 1, 1);

        label_Res_AngleCustom_Stat_Uncertanty = new QLabel(groupBox_Res_AngleCustom);
        label_Res_AngleCustom_Stat_Uncertanty->setObjectName(QString::fromUtf8("label_Res_AngleCustom_Stat_Uncertanty"));
        sizePolicy4.setHeightForWidth(label_Res_AngleCustom_Stat_Uncertanty->sizePolicy().hasHeightForWidth());
        label_Res_AngleCustom_Stat_Uncertanty->setSizePolicy(sizePolicy4);

        gridLayout_16->addWidget(label_Res_AngleCustom_Stat_Uncertanty, 0, 2, 1, 1);

        checkBox_Res_PlotLine_FixRange_A = new QCheckBox(groupBox_Res_AngleCustom);
        checkBox_Res_PlotLine_FixRange_A->setObjectName(QString::fromUtf8("checkBox_Res_PlotLine_FixRange_A"));
        sizePolicy1.setHeightForWidth(checkBox_Res_PlotLine_FixRange_A->sizePolicy().hasHeightForWidth());
        checkBox_Res_PlotLine_FixRange_A->setSizePolicy(sizePolicy1);
        checkBox_Res_PlotLine_FixRange_A->setMinimumSize(QSize(0, 0));
        checkBox_Res_PlotLine_FixRange_A->setMaximumSize(QSize(16777215, 16777215));
        checkBox_Res_PlotLine_FixRange_A->setChecked(true);

        gridLayout_16->addWidget(checkBox_Res_PlotLine_FixRange_A, 0, 5, 1, 1);

        comboBox_Res_AngleCustom_Stat_Value = new QComboBox(groupBox_Res_AngleCustom);
        comboBox_Res_AngleCustom_Stat_Value->setObjectName(QString::fromUtf8("comboBox_Res_AngleCustom_Stat_Value"));

        gridLayout_16->addWidget(comboBox_Res_AngleCustom_Stat_Value, 0, 1, 1, 1);

        doubleSpinBox_Res_PlotLine_FixRange_A_max = new QDoubleSpinBox(groupBox_Res_AngleCustom);
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setObjectName(QString::fromUtf8("doubleSpinBox_Res_PlotLine_FixRange_A_max"));
        sizePolicy3.setHeightForWidth(doubleSpinBox_Res_PlotLine_FixRange_A_max->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setSizePolicy(sizePolicy3);
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setMinimumSize(QSize(50, 0));
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setMaximumSize(QSize(50, 16777215));
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setMinimum(-9999.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setMaximum(9999.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setValue(180.000000000000000);

        gridLayout_16->addWidget(doubleSpinBox_Res_PlotLine_FixRange_A_max, 0, 7, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_AngleCustom, 4, 0, 1, 2);

        groupBox_Res_MovAv = new QGroupBox(groupBox_Res);
        groupBox_Res_MovAv->setObjectName(QString::fromUtf8("groupBox_Res_MovAv"));
        groupBox_Res_MovAv->setFlat(true);
        gridLayout_17 = new QGridLayout(groupBox_Res_MovAv);
        gridLayout_17->setSpacing(3);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 3, 0, 3);
        gridLayout_18 = new QGridLayout();
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setHorizontalSpacing(3);
        gridLayout_18->setVerticalSpacing(0);
        horizontalSlider_Res_MovAv_CurrentStart = new QSlider(groupBox_Res_MovAv);
        horizontalSlider_Res_MovAv_CurrentStart->setObjectName(QString::fromUtf8("horizontalSlider_Res_MovAv_CurrentStart"));
        horizontalSlider_Res_MovAv_CurrentStart->setMinimumSize(QSize(0, 15));
        horizontalSlider_Res_MovAv_CurrentStart->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_Res_MovAv_CurrentStart->setMaximum(480);
        horizontalSlider_Res_MovAv_CurrentStart->setOrientation(Qt::Horizontal);
        horizontalSlider_Res_MovAv_CurrentStart->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_Res_MovAv_CurrentStart->setTickInterval(240);

        gridLayout_18->addWidget(horizontalSlider_Res_MovAv_CurrentStart, 0, 0, 1, 1);

        horizontalSlider_Res_MovAv_CurrentEnd = new QSlider(groupBox_Res_MovAv);
        horizontalSlider_Res_MovAv_CurrentEnd->setObjectName(QString::fromUtf8("horizontalSlider_Res_MovAv_CurrentEnd"));
        horizontalSlider_Res_MovAv_CurrentEnd->setMinimumSize(QSize(0, 15));
        horizontalSlider_Res_MovAv_CurrentEnd->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_Res_MovAv_CurrentEnd->setMaximum(480);
        horizontalSlider_Res_MovAv_CurrentEnd->setValue(120);
        horizontalSlider_Res_MovAv_CurrentEnd->setSliderPosition(120);
        horizontalSlider_Res_MovAv_CurrentEnd->setOrientation(Qt::Horizontal);
        horizontalSlider_Res_MovAv_CurrentEnd->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_Res_MovAv_CurrentEnd->setTickInterval(240);

        gridLayout_18->addWidget(horizontalSlider_Res_MovAv_CurrentEnd, 1, 0, 1, 1);

        spinBox_Res_MovAv_CurrentFrame = new QSpinBox(groupBox_Res_MovAv);
        spinBox_Res_MovAv_CurrentFrame->setObjectName(QString::fromUtf8("spinBox_Res_MovAv_CurrentFrame"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(spinBox_Res_MovAv_CurrentFrame->sizePolicy().hasHeightForWidth());
        spinBox_Res_MovAv_CurrentFrame->setSizePolicy(sizePolicy6);
        spinBox_Res_MovAv_CurrentFrame->setMinimumSize(QSize(130, 30));
        spinBox_Res_MovAv_CurrentFrame->setMaximumSize(QSize(130, 30));
        spinBox_Res_MovAv_CurrentFrame->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_MovAv_CurrentFrame->setMaximum(480);

        gridLayout_18->addWidget(spinBox_Res_MovAv_CurrentFrame, 0, 1, 2, 1);

        doubleSpinBox_Res_MovAv_CurrentTime = new QDoubleSpinBox(groupBox_Res_MovAv);
        doubleSpinBox_Res_MovAv_CurrentTime->setObjectName(QString::fromUtf8("doubleSpinBox_Res_MovAv_CurrentTime"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_Res_MovAv_CurrentTime->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_MovAv_CurrentTime->setSizePolicy(sizePolicy6);
        doubleSpinBox_Res_MovAv_CurrentTime->setMinimumSize(QSize(130, 30));
        doubleSpinBox_Res_MovAv_CurrentTime->setMaximumSize(QSize(130, 30));
        doubleSpinBox_Res_MovAv_CurrentTime->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_MovAv_CurrentTime->setMaximum(20.000000000000000);

        gridLayout_18->addWidget(doubleSpinBox_Res_MovAv_CurrentTime, 0, 2, 2, 1);


        gridLayout_17->addLayout(gridLayout_18, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox_Res_MovAv_TimeWindow = new QComboBox(groupBox_Res_MovAv);
        comboBox_Res_MovAv_TimeWindow->addItem(QString());
        comboBox_Res_MovAv_TimeWindow->addItem(QString());
        comboBox_Res_MovAv_TimeWindow->setObjectName(QString::fromUtf8("comboBox_Res_MovAv_TimeWindow"));
        sizePolicy5.setHeightForWidth(comboBox_Res_MovAv_TimeWindow->sizePolicy().hasHeightForWidth());
        comboBox_Res_MovAv_TimeWindow->setSizePolicy(sizePolicy5);
        comboBox_Res_MovAv_TimeWindow->setMinimumSize(QSize(105, 0));

        horizontalLayout->addWidget(comboBox_Res_MovAv_TimeWindow);

        comboBox_Res_MovAv_Background = new QComboBox(groupBox_Res_MovAv);
        comboBox_Res_MovAv_Background->addItem(QString());
        comboBox_Res_MovAv_Background->addItem(QString());
        comboBox_Res_MovAv_Background->setObjectName(QString::fromUtf8("comboBox_Res_MovAv_Background"));
        sizePolicy5.setHeightForWidth(comboBox_Res_MovAv_Background->sizePolicy().hasHeightForWidth());
        comboBox_Res_MovAv_Background->setSizePolicy(sizePolicy5);
        comboBox_Res_MovAv_Background->setMinimumSize(QSize(105, 0));

        horizontalLayout->addWidget(comboBox_Res_MovAv_Background);

        doubleSpinBox_Res_MovAv_ReqFrmWithDetect = new QDoubleSpinBox(groupBox_Res_MovAv);
        doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setObjectName(QString::fromUtf8("doubleSpinBox_Res_MovAv_ReqFrmWithDetect"));
        sizePolicy5.setHeightForWidth(doubleSpinBox_Res_MovAv_ReqFrmWithDetect->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setSizePolicy(sizePolicy5);
        doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setMinimumSize(QSize(200, 0));
        doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setMaximumSize(QSize(16777215, 40));
        doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setDecimals(2);
        doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setMaximum(100.000000000000000);
        doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setSingleStep(5.000000000000000);
        doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setValue(75.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox_Res_MovAv_ReqFrmWithDetect);

        spinBox_Res_MovAv_WindowFrames = new QSpinBox(groupBox_Res_MovAv);
        spinBox_Res_MovAv_WindowFrames->setObjectName(QString::fromUtf8("spinBox_Res_MovAv_WindowFrames"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(spinBox_Res_MovAv_WindowFrames->sizePolicy().hasHeightForWidth());
        spinBox_Res_MovAv_WindowFrames->setSizePolicy(sizePolicy7);
        spinBox_Res_MovAv_WindowFrames->setMinimumSize(QSize(130, 0));
        spinBox_Res_MovAv_WindowFrames->setMaximumSize(QSize(130, 40));
        spinBox_Res_MovAv_WindowFrames->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_MovAv_WindowFrames->setMinimum(1);
        spinBox_Res_MovAv_WindowFrames->setMaximum(480);
        spinBox_Res_MovAv_WindowFrames->setValue(12);

        horizontalLayout->addWidget(spinBox_Res_MovAv_WindowFrames);

        doubleSpinBox_Res_MovAv_WindowTime = new QDoubleSpinBox(groupBox_Res_MovAv);
        doubleSpinBox_Res_MovAv_WindowTime->setObjectName(QString::fromUtf8("doubleSpinBox_Res_MovAv_WindowTime"));
        sizePolicy7.setHeightForWidth(doubleSpinBox_Res_MovAv_WindowTime->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_MovAv_WindowTime->setSizePolicy(sizePolicy7);
        doubleSpinBox_Res_MovAv_WindowTime->setMinimumSize(QSize(130, 0));
        doubleSpinBox_Res_MovAv_WindowTime->setMaximumSize(QSize(130, 40));
        doubleSpinBox_Res_MovAv_WindowTime->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_MovAv_WindowTime->setMinimum(0.420000000000000);
        doubleSpinBox_Res_MovAv_WindowTime->setMaximum(480.000000000000000);
        doubleSpinBox_Res_MovAv_WindowTime->setValue(0.500000000000000);

        horizontalLayout->addWidget(doubleSpinBox_Res_MovAv_WindowTime);


        gridLayout_17->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_MovAv, 7, 0, 1, 2);

        stackedWidget_Res_Type = new QStackedWidget(groupBox_Res);
        stackedWidget_Res_Type->setObjectName(QString::fromUtf8("stackedWidget_Res_Type"));
        page_Res_Graphics = new QWidget();
        page_Res_Graphics->setObjectName(QString::fromUtf8("page_Res_Graphics"));
        gridLayout_6 = new QGridLayout(page_Res_Graphics);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        graphicsView_Results = new QGraphicsView(page_Res_Graphics);
        graphicsView_Results->setObjectName(QString::fromUtf8("graphicsView_Results"));
        graphicsView_Results->setMouseTracking(true);

        gridLayout_6->addWidget(graphicsView_Results, 0, 2, 1, 9);

        stackedWidget_Res_Type->addWidget(page_Res_Graphics);
        page_Res_PlotTable = new QWidget();
        page_Res_PlotTable->setObjectName(QString::fromUtf8("page_Res_PlotTable"));
        gridLayout_9 = new QGridLayout(page_Res_PlotTable);
        gridLayout_9->setSpacing(3);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 3, 0, 6);
        tabWidget_ResType = new QTabWidget(page_Res_PlotTable);
        tabWidget_ResType->setObjectName(QString::fromUtf8("tabWidget_ResType"));
        tabWidget_ResType->setTabPosition(QTabWidget::South);
        tab_ResPlotLine = new QWidget();
        tab_ResPlotLine->setObjectName(QString::fromUtf8("tab_ResPlotLine"));
        gridLayout_19 = new QGridLayout(tab_ResPlotLine);
        gridLayout_19->setSpacing(3);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setContentsMargins(3, 3, 3, 3);
        gridLayout_ResPlotLine = new QGridLayout();
        gridLayout_ResPlotLine->setObjectName(QString::fromUtf8("gridLayout_ResPlotLine"));

        gridLayout_19->addLayout(gridLayout_ResPlotLine, 0, 0, 1, 13);

        tabWidget_ResType->addTab(tab_ResPlotLine, QString());
        tab_ResPlotPoincare = new QWidget();
        tab_ResPlotPoincare->setObjectName(QString::fromUtf8("tab_ResPlotPoincare"));
        gridLayout_13 = new QGridLayout(tab_ResPlotPoincare);
        gridLayout_13->setSpacing(0);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        gridLayout_ResPlotPoincare = new QGridLayout();
        gridLayout_ResPlotPoincare->setObjectName(QString::fromUtf8("gridLayout_ResPlotPoincare"));

        gridLayout_13->addLayout(gridLayout_ResPlotPoincare, 0, 0, 1, 1);

        tabWidget_ResType->addTab(tab_ResPlotPoincare, QString());
        tab_ResTable = new QWidget();
        tab_ResTable->setObjectName(QString::fromUtf8("tab_ResTable"));
        gridLayout_12 = new QGridLayout(tab_ResTable);
        gridLayout_12->setSpacing(0);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        tableWidget_Results = new QTableWidget(tab_ResTable);
        tableWidget_Results->setObjectName(QString::fromUtf8("tableWidget_Results"));

        gridLayout_12->addWidget(tableWidget_Results, 0, 0, 1, 1);

        tabWidget_ResType->addTab(tab_ResTable, QString());

        gridLayout_9->addWidget(tabWidget_ResType, 0, 0, 1, 13);

        stackedWidget_Res_Type->addWidget(page_Res_PlotTable);
        page_Res_Overview = new QWidget();
        page_Res_Overview->setObjectName(QString::fromUtf8("page_Res_Overview"));
        gridLayout_23 = new QGridLayout(page_Res_Overview);
        gridLayout_23->setSpacing(0);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        gridLayout_23->setContentsMargins(0, 0, 0, 0);
        gridLayout_Res_Overview_SpeedLine = new QGridLayout();
        gridLayout_Res_Overview_SpeedLine->setObjectName(QString::fromUtf8("gridLayout_Res_Overview_SpeedLine"));

        gridLayout_23->addLayout(gridLayout_Res_Overview_SpeedLine, 0, 0, 1, 1);

        gridLayout_Res_Overview_SpeedPoincare = new QGridLayout();
        gridLayout_Res_Overview_SpeedPoincare->setObjectName(QString::fromUtf8("gridLayout_Res_Overview_SpeedPoincare"));

        gridLayout_23->addLayout(gridLayout_Res_Overview_SpeedPoincare, 0, 1, 1, 1);

        gridLayout_Res_Overview_AngleLine = new QGridLayout();
        gridLayout_Res_Overview_AngleLine->setObjectName(QString::fromUtf8("gridLayout_Res_Overview_AngleLine"));

        gridLayout_23->addLayout(gridLayout_Res_Overview_AngleLine, 1, 0, 1, 1);

        gridLayout_Res_Overview_AnglePoincare = new QGridLayout();
        gridLayout_Res_Overview_AnglePoincare->setObjectName(QString::fromUtf8("gridLayout_Res_Overview_AnglePoincare"));

        gridLayout_23->addLayout(gridLayout_Res_Overview_AnglePoincare, 1, 1, 1, 1);

        stackedWidget_Res_Type->addWidget(page_Res_Overview);

        gridLayout_4->addWidget(stackedWidget_Res_Type, 1, 0, 1, 2);

        groupBox_Res_SpeedCustom = new QGroupBox(groupBox_Res);
        groupBox_Res_SpeedCustom->setObjectName(QString::fromUtf8("groupBox_Res_SpeedCustom"));
        groupBox_Res_SpeedCustom->setFlat(true);
        gridLayout_15 = new QGridLayout(groupBox_Res_SpeedCustom);
        gridLayout_15->setSpacing(3);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(0, 3, 0, 3);
        comboBox_Res_SpeedCustom_Stat_Value = new QComboBox(groupBox_Res_SpeedCustom);
        comboBox_Res_SpeedCustom_Stat_Value->setObjectName(QString::fromUtf8("comboBox_Res_SpeedCustom_Stat_Value"));

        gridLayout_15->addWidget(comboBox_Res_SpeedCustom_Stat_Value, 0, 1, 1, 1);

        label_13 = new QLabel(groupBox_Res_SpeedCustom);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy4.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy4);

        gridLayout_15->addWidget(label_13, 0, 0, 1, 1);

        doubleSpinBox_Res_PlotLine_FixRange_S_min = new QDoubleSpinBox(groupBox_Res_SpeedCustom);
        doubleSpinBox_Res_PlotLine_FixRange_S_min->setObjectName(QString::fromUtf8("doubleSpinBox_Res_PlotLine_FixRange_S_min"));
        sizePolicy3.setHeightForWidth(doubleSpinBox_Res_PlotLine_FixRange_S_min->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_PlotLine_FixRange_S_min->setSizePolicy(sizePolicy3);
        doubleSpinBox_Res_PlotLine_FixRange_S_min->setMinimumSize(QSize(50, 0));
        doubleSpinBox_Res_PlotLine_FixRange_S_min->setMaximumSize(QSize(50, 16777215));
        doubleSpinBox_Res_PlotLine_FixRange_S_min->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_PlotLine_FixRange_S_min->setMinimum(-9999.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_S_min->setMaximum(9999.000000000000000);

        gridLayout_15->addWidget(doubleSpinBox_Res_PlotLine_FixRange_S_min, 0, 6, 1, 1);

        checkBox_Res_PlotLine_FixRange_S = new QCheckBox(groupBox_Res_SpeedCustom);
        checkBox_Res_PlotLine_FixRange_S->setObjectName(QString::fromUtf8("checkBox_Res_PlotLine_FixRange_S"));
        sizePolicy1.setHeightForWidth(checkBox_Res_PlotLine_FixRange_S->sizePolicy().hasHeightForWidth());
        checkBox_Res_PlotLine_FixRange_S->setSizePolicy(sizePolicy1);
        checkBox_Res_PlotLine_FixRange_S->setMinimumSize(QSize(0, 0));
        checkBox_Res_PlotLine_FixRange_S->setMaximumSize(QSize(16777215, 16777215));
        checkBox_Res_PlotLine_FixRange_S->setChecked(true);

        gridLayout_15->addWidget(checkBox_Res_PlotLine_FixRange_S, 0, 5, 1, 1);

        doubleSpinBox_Res_PlotLine_FixRange_S_max = new QDoubleSpinBox(groupBox_Res_SpeedCustom);
        doubleSpinBox_Res_PlotLine_FixRange_S_max->setObjectName(QString::fromUtf8("doubleSpinBox_Res_PlotLine_FixRange_S_max"));
        sizePolicy3.setHeightForWidth(doubleSpinBox_Res_PlotLine_FixRange_S_max->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_PlotLine_FixRange_S_max->setSizePolicy(sizePolicy3);
        doubleSpinBox_Res_PlotLine_FixRange_S_max->setMinimumSize(QSize(50, 0));
        doubleSpinBox_Res_PlotLine_FixRange_S_max->setMaximumSize(QSize(50, 16777215));
        doubleSpinBox_Res_PlotLine_FixRange_S_max->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_PlotLine_FixRange_S_max->setMinimum(0.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_S_max->setMaximum(9999.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_S_max->setValue(160.000000000000000);

        gridLayout_15->addWidget(doubleSpinBox_Res_PlotLine_FixRange_S_max, 0, 7, 1, 1);

        label_Res_SpeedCustom_Stat_Uncertanty = new QLabel(groupBox_Res_SpeedCustom);
        label_Res_SpeedCustom_Stat_Uncertanty->setObjectName(QString::fromUtf8("label_Res_SpeedCustom_Stat_Uncertanty"));
        sizePolicy4.setHeightForWidth(label_Res_SpeedCustom_Stat_Uncertanty->sizePolicy().hasHeightForWidth());
        label_Res_SpeedCustom_Stat_Uncertanty->setSizePolicy(sizePolicy4);

        gridLayout_15->addWidget(label_Res_SpeedCustom_Stat_Uncertanty, 0, 2, 1, 1);

        line_3 = new QFrame(groupBox_Res_SpeedCustom);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_15->addWidget(line_3, 0, 4, 1, 1);

        comboBox_Res_SpeedCustom_Stat_Uncertanty = new QComboBox(groupBox_Res_SpeedCustom);
        comboBox_Res_SpeedCustom_Stat_Uncertanty->setObjectName(QString::fromUtf8("comboBox_Res_SpeedCustom_Stat_Uncertanty"));

        gridLayout_15->addWidget(comboBox_Res_SpeedCustom_Stat_Uncertanty, 0, 3, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_SpeedCustom, 3, 0, 1, 2);

        comboBox_Res_Type = new QComboBox(groupBox_Res);
        comboBox_Res_Type->setObjectName(QString::fromUtf8("comboBox_Res_Type"));

        gridLayout_4->addWidget(comboBox_Res_Type, 0, 0, 1, 2);

        groupBox_Res_GridVisParam = new QGroupBox(groupBox_Res);
        groupBox_Res_GridVisParam->setObjectName(QString::fromUtf8("groupBox_Res_GridVisParam"));
        groupBox_Res_GridVisParam->setFlat(true);
        gridLayout_14 = new QGridLayout(groupBox_Res_GridVisParam);
        gridLayout_14->setSpacing(3);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 3, 0, 3);
        doubleSpinBox_Res_GridVisParam_Label_Scaling = new QDoubleSpinBox(groupBox_Res_GridVisParam);
        doubleSpinBox_Res_GridVisParam_Label_Scaling->setObjectName(QString::fromUtf8("doubleSpinBox_Res_GridVisParam_Label_Scaling"));
        doubleSpinBox_Res_GridVisParam_Label_Scaling->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_GridVisParam_Label_Scaling->setDecimals(2);
        doubleSpinBox_Res_GridVisParam_Label_Scaling->setSingleStep(0.100000000000000);
        doubleSpinBox_Res_GridVisParam_Label_Scaling->setValue(0.600000000000000);

        gridLayout_14->addWidget(doubleSpinBox_Res_GridVisParam_Label_Scaling, 0, 5, 1, 1);

        checkBox_Res_GridVisParam_Grid = new QCheckBox(groupBox_Res_GridVisParam);
        checkBox_Res_GridVisParam_Grid->setObjectName(QString::fromUtf8("checkBox_Res_GridVisParam_Grid"));
        sizePolicy1.setHeightForWidth(checkBox_Res_GridVisParam_Grid->sizePolicy().hasHeightForWidth());
        checkBox_Res_GridVisParam_Grid->setSizePolicy(sizePolicy1);
        checkBox_Res_GridVisParam_Grid->setChecked(true);

        gridLayout_14->addWidget(checkBox_Res_GridVisParam_Grid, 0, 1, 1, 1);

        spinBox_Res_GridVisParam_Thickness_Grid = new QSpinBox(groupBox_Res_GridVisParam);
        spinBox_Res_GridVisParam_Thickness_Grid->setObjectName(QString::fromUtf8("spinBox_Res_GridVisParam_Thickness_Grid"));
        sizePolicy5.setHeightForWidth(spinBox_Res_GridVisParam_Thickness_Grid->sizePolicy().hasHeightForWidth());
        spinBox_Res_GridVisParam_Thickness_Grid->setSizePolicy(sizePolicy5);
        spinBox_Res_GridVisParam_Thickness_Grid->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_GridVisParam_Thickness_Grid->setMinimum(1);
        spinBox_Res_GridVisParam_Thickness_Grid->setMaximum(99);
        spinBox_Res_GridVisParam_Thickness_Grid->setValue(1);

        gridLayout_14->addWidget(spinBox_Res_GridVisParam_Thickness_Grid, 0, 2, 1, 1);

        checkBox_Res_GridVisParam_Labels = new QCheckBox(groupBox_Res_GridVisParam);
        checkBox_Res_GridVisParam_Labels->setObjectName(QString::fromUtf8("checkBox_Res_GridVisParam_Labels"));
        sizePolicy1.setHeightForWidth(checkBox_Res_GridVisParam_Labels->sizePolicy().hasHeightForWidth());
        checkBox_Res_GridVisParam_Labels->setSizePolicy(sizePolicy1);
        checkBox_Res_GridVisParam_Labels->setChecked(true);

        gridLayout_14->addWidget(checkBox_Res_GridVisParam_Labels, 0, 3, 1, 1);

        spinBox_Res_GridVisParam_Thickness_Label = new QSpinBox(groupBox_Res_GridVisParam);
        spinBox_Res_GridVisParam_Thickness_Label->setObjectName(QString::fromUtf8("spinBox_Res_GridVisParam_Thickness_Label"));
        spinBox_Res_GridVisParam_Thickness_Label->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_GridVisParam_Thickness_Label->setMinimum(1);
        spinBox_Res_GridVisParam_Thickness_Label->setMaximum(99);
        spinBox_Res_GridVisParam_Thickness_Label->setValue(1);

        gridLayout_14->addWidget(spinBox_Res_GridVisParam_Thickness_Label, 0, 4, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_GridVisParam, 8, 0, 1, 2);

        groupBox_Res_Heat = new QGroupBox(groupBox_Res);
        groupBox_Res_Heat->setObjectName(QString::fromUtf8("groupBox_Res_Heat"));
        groupBox_Res_Heat->setFlat(true);
        gridLayout_11 = new QGridLayout(groupBox_Res_Heat);
        gridLayout_11->setSpacing(3);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 3, 0, 3);
        comboBox_Res_Heat_Mode = new QComboBox(groupBox_Res_Heat);
        comboBox_Res_Heat_Mode->addItem(QString());
        comboBox_Res_Heat_Mode->addItem(QString());
        comboBox_Res_Heat_Mode->addItem(QString());
        comboBox_Res_Heat_Mode->setObjectName(QString::fromUtf8("comboBox_Res_Heat_Mode"));

        gridLayout_11->addWidget(comboBox_Res_Heat_Mode, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_Heat, 2, 0, 1, 2);


        gridLayout->addWidget(groupBox_Res, 1, 1, 3, 1);

        groupBox_Data = new QGroupBox(centralwidget);
        groupBox_Data->setObjectName(QString::fromUtf8("groupBox_Data"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy8.setHorizontalStretch(1);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(groupBox_Data->sizePolicy().hasHeightForWidth());
        groupBox_Data->setSizePolicy(sizePolicy8);
        gridLayout_2 = new QGridLayout(groupBox_Data);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(6, 6, 6, 6);
        pushButton_Data_Add = new QPushButton(groupBox_Data);
        pushButton_Data_Add->setObjectName(QString::fromUtf8("pushButton_Data_Add"));

        gridLayout_2->addWidget(pushButton_Data_Add, 1, 0, 1, 1);

        pushButton_Data_Clear = new QPushButton(groupBox_Data);
        pushButton_Data_Clear->setObjectName(QString::fromUtf8("pushButton_Data_Clear"));
        pushButton_Data_Clear->setEnabled(false);

        gridLayout_2->addWidget(pushButton_Data_Clear, 1, 1, 1, 1);

        comboBox_Data_Videos = new QComboBox(groupBox_Data);
        comboBox_Data_Videos->setObjectName(QString::fromUtf8("comboBox_Data_Videos"));
        comboBox_Data_Videos->setEnabled(false);

        gridLayout_2->addWidget(comboBox_Data_Videos, 0, 0, 1, 2);


        gridLayout->addWidget(groupBox_Data, 1, 0, 1, 1);

        groupBox_Param = new QGroupBox(centralwidget);
        groupBox_Param->setObjectName(QString::fromUtf8("groupBox_Param"));
        groupBox_Param->setEnabled(false);
        sizePolicy8.setHeightForWidth(groupBox_Param->sizePolicy().hasHeightForWidth());
        groupBox_Param->setSizePolicy(sizePolicy8);
        gridLayout_5 = new QGridLayout(groupBox_Param);
        gridLayout_5->setSpacing(3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(6, 6, 6, 6);
        doubleSpinBox_Param_Blur_Sigma = new QDoubleSpinBox(groupBox_Param);
        doubleSpinBox_Param_Blur_Sigma->setObjectName(QString::fromUtf8("doubleSpinBox_Param_Blur_Sigma"));
        doubleSpinBox_Param_Blur_Sigma->setMinimumSize(QSize(100, 0));
        doubleSpinBox_Param_Blur_Sigma->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_Param_Blur_Sigma->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Param_Blur_Sigma->setSingleStep(0.250000000000000);
        doubleSpinBox_Param_Blur_Sigma->setValue(1.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_Param_Blur_Sigma, 7, 2, 1, 1);

        spinBox_Param_FrameCountSmooth = new QSpinBox(groupBox_Param);
        spinBox_Param_FrameCountSmooth->setObjectName(QString::fromUtf8("spinBox_Param_FrameCountSmooth"));
        spinBox_Param_FrameCountSmooth->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Param_FrameCountSmooth->setMinimum(2);
        spinBox_Param_FrameCountSmooth->setMaximum(999);
        spinBox_Param_FrameCountSmooth->setValue(12);

        gridLayout_5->addWidget(spinBox_Param_FrameCountSmooth, 9, 1, 1, 2);

        doubleSpinBox_Param_Crop_Start = new QDoubleSpinBox(groupBox_Param);
        doubleSpinBox_Param_Crop_Start->setObjectName(QString::fromUtf8("doubleSpinBox_Param_Crop_Start"));
        doubleSpinBox_Param_Crop_Start->setMinimumSize(QSize(100, 0));
        doubleSpinBox_Param_Crop_Start->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_Param_Crop_Start->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Param_Crop_Start->setValue(6.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_Param_Crop_Start, 3, 1, 1, 1);

        line_2 = new QFrame(groupBox_Param);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_2, 2, 0, 1, 4);

        doubleSpinBox_Param_Scale_mm = new QDoubleSpinBox(groupBox_Param);
        doubleSpinBox_Param_Scale_mm->setObjectName(QString::fromUtf8("doubleSpinBox_Param_Scale_mm"));
        doubleSpinBox_Param_Scale_mm->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Param_Scale_mm->setDecimals(3);
        doubleSpinBox_Param_Scale_mm->setMaximum(9999.000000000000000);
        doubleSpinBox_Param_Scale_mm->setValue(0.850000000000000);

        gridLayout_5->addWidget(doubleSpinBox_Param_Scale_mm, 1, 2, 1, 1);

        spinBox_Param_Crop_Left = new QSpinBox(groupBox_Param);
        spinBox_Param_Crop_Left->setObjectName(QString::fromUtf8("spinBox_Param_Crop_Left"));
        spinBox_Param_Crop_Left->setMinimumSize(QSize(100, 0));
        spinBox_Param_Crop_Left->setMaximumSize(QSize(100, 16777215));
        spinBox_Param_Crop_Left->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Param_Crop_Left->setMaximum(999);
        spinBox_Param_Crop_Left->setSingleStep(5);

        gridLayout_5->addWidget(spinBox_Param_Crop_Left, 5, 1, 1, 1);

        label = new QLabel(groupBox_Param);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 1, 0, 1, 1);

        label_Param_CropHeight = new QLabel(groupBox_Param);
        label_Param_CropHeight->setObjectName(QString::fromUtf8("label_Param_CropHeight"));

        gridLayout_5->addWidget(label_Param_CropHeight, 4, 3, 1, 1);

        label_9 = new QLabel(groupBox_Param);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(75, 0));
        label_9->setMaximumSize(QSize(75, 16777215));

        gridLayout_5->addWidget(label_9, 7, 0, 1, 1);

        spinBox_Param_Crop_Bottom = new QSpinBox(groupBox_Param);
        spinBox_Param_Crop_Bottom->setObjectName(QString::fromUtf8("spinBox_Param_Crop_Bottom"));
        spinBox_Param_Crop_Bottom->setMinimumSize(QSize(100, 0));
        spinBox_Param_Crop_Bottom->setMaximumSize(QSize(100, 16777215));
        spinBox_Param_Crop_Bottom->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Param_Crop_Bottom->setMaximum(999);
        spinBox_Param_Crop_Bottom->setSingleStep(5);
        spinBox_Param_Crop_Bottom->setValue(420);

        gridLayout_5->addWidget(spinBox_Param_Crop_Bottom, 4, 2, 1, 1);

        spinBox_Param_Crop_Top = new QSpinBox(groupBox_Param);
        spinBox_Param_Crop_Top->setObjectName(QString::fromUtf8("spinBox_Param_Crop_Top"));
        spinBox_Param_Crop_Top->setMinimumSize(QSize(100, 0));
        spinBox_Param_Crop_Top->setMaximumSize(QSize(100, 16777215));
        spinBox_Param_Crop_Top->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Param_Crop_Top->setMaximum(999);
        spinBox_Param_Crop_Top->setSingleStep(5);
        spinBox_Param_Crop_Top->setValue(425);

        gridLayout_5->addWidget(spinBox_Param_Crop_Top, 4, 1, 1, 1);

        line = new QFrame(groupBox_Param);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line, 6, 0, 1, 4);

        label_3 = new QLabel(groupBox_Param);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(75, 0));
        label_3->setMaximumSize(QSize(75, 16777215));

        gridLayout_5->addWidget(label_3, 3, 0, 3, 1);

        spinBox_Param_Blur_Size = new QSpinBox(groupBox_Param);
        spinBox_Param_Blur_Size->setObjectName(QString::fromUtf8("spinBox_Param_Blur_Size"));
        spinBox_Param_Blur_Size->setMinimumSize(QSize(100, 0));
        spinBox_Param_Blur_Size->setMaximumSize(QSize(100, 16777215));
        spinBox_Param_Blur_Size->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Param_Blur_Size->setMinimum(1);
        spinBox_Param_Blur_Size->setSingleStep(2);
        spinBox_Param_Blur_Size->setValue(3);

        gridLayout_5->addWidget(spinBox_Param_Blur_Size, 7, 1, 1, 1);

        label_2 = new QLabel(groupBox_Param);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_5->addWidget(label_2, 1, 3, 1, 1);

        label_Param_CropTime = new QLabel(groupBox_Param);
        label_Param_CropTime->setObjectName(QString::fromUtf8("label_Param_CropTime"));

        gridLayout_5->addWidget(label_Param_CropTime, 3, 3, 1, 1);

        label_8 = new QLabel(groupBox_Param);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_5->addWidget(label_8, 9, 3, 1, 1);

        spinBox_Param_Crop_Right = new QSpinBox(groupBox_Param);
        spinBox_Param_Crop_Right->setObjectName(QString::fromUtf8("spinBox_Param_Crop_Right"));
        spinBox_Param_Crop_Right->setMinimumSize(QSize(100, 0));
        spinBox_Param_Crop_Right->setMaximumSize(QSize(100, 16777215));
        spinBox_Param_Crop_Right->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Param_Crop_Right->setMaximum(999);
        spinBox_Param_Crop_Right->setSingleStep(5);
        spinBox_Param_Crop_Right->setValue(100);

        gridLayout_5->addWidget(spinBox_Param_Crop_Right, 5, 2, 1, 1);

        label_10 = new QLabel(groupBox_Param);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_5->addWidget(label_10, 7, 3, 1, 1);

        line_6 = new QFrame(groupBox_Param);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_6, 8, 0, 1, 4);

        label_Param_CropWidth = new QLabel(groupBox_Param);
        label_Param_CropWidth->setObjectName(QString::fromUtf8("label_Param_CropWidth"));

        gridLayout_5->addWidget(label_Param_CropWidth, 5, 3, 1, 1);

        doubleSpinBox_Param_Crop_End = new QDoubleSpinBox(groupBox_Param);
        doubleSpinBox_Param_Crop_End->setObjectName(QString::fromUtf8("doubleSpinBox_Param_Crop_End"));
        doubleSpinBox_Param_Crop_End->setMinimumSize(QSize(100, 0));
        doubleSpinBox_Param_Crop_End->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_Param_Crop_End->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Param_Crop_End->setValue(6.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_Param_Crop_End, 3, 2, 1, 1);

        label_11 = new QLabel(groupBox_Param);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_5->addWidget(label_11, 10, 3, 1, 1);

        label_4 = new QLabel(groupBox_Param);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_5->addWidget(label_4, 9, 0, 2, 1);

        doubleSpinBox_Param_MaxSpeed = new QDoubleSpinBox(groupBox_Param);
        doubleSpinBox_Param_MaxSpeed->setObjectName(QString::fromUtf8("doubleSpinBox_Param_MaxSpeed"));
        doubleSpinBox_Param_MaxSpeed->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Param_MaxSpeed->setDecimals(3);
        doubleSpinBox_Param_MaxSpeed->setValue(20.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_Param_MaxSpeed, 10, 1, 1, 2);

        doubleSpinBox_Param_Scale_Px = new QDoubleSpinBox(groupBox_Param);
        doubleSpinBox_Param_Scale_Px->setObjectName(QString::fromUtf8("doubleSpinBox_Param_Scale_Px"));
        doubleSpinBox_Param_Scale_Px->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Param_Scale_Px->setDecimals(3);
        doubleSpinBox_Param_Scale_Px->setMaximum(9999.000000000000000);
        doubleSpinBox_Param_Scale_Px->setValue(843.894999999999982);

        gridLayout_5->addWidget(doubleSpinBox_Param_Scale_Px, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox_Param, 3, 0, 1, 1);

        groupBox_Proc = new QGroupBox(centralwidget);
        groupBox_Proc->setObjectName(QString::fromUtf8("groupBox_Proc"));
        groupBox_Proc->setEnabled(false);
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(1);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(groupBox_Proc->sizePolicy().hasHeightForWidth());
        groupBox_Proc->setSizePolicy(sizePolicy9);
        gridLayout_3 = new QGridLayout(groupBox_Proc);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(6, 6, 6, 6);
        doubleSpinBox_Proc_Time = new QDoubleSpinBox(groupBox_Proc);
        doubleSpinBox_Proc_Time->setObjectName(QString::fromUtf8("doubleSpinBox_Proc_Time"));
        doubleSpinBox_Proc_Time->setMinimumSize(QSize(120, 0));
        doubleSpinBox_Proc_Time->setMaximumSize(QSize(120, 16777215));
        doubleSpinBox_Proc_Time->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Proc_Time->setDecimals(2);
        doubleSpinBox_Proc_Time->setMaximum(20.000000000000000);
        doubleSpinBox_Proc_Time->setValue(0.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_Proc_Time, 2, 3, 1, 1);

        comboBox_Proc_Step = new QComboBox(groupBox_Proc);
        comboBox_Proc_Step->setObjectName(QString::fromUtf8("comboBox_Proc_Step"));

        gridLayout_3->addWidget(comboBox_Proc_Step, 0, 1, 1, 2);

        graphicsView_Proc = new QGraphicsView(groupBox_Proc);
        graphicsView_Proc->setObjectName(QString::fromUtf8("graphicsView_Proc"));
        graphicsView_Proc->setMouseTracking(true);

        gridLayout_3->addWidget(graphicsView_Proc, 1, 1, 1, 3);

        pushButton_Proc_FullVideo = new QPushButton(groupBox_Proc);
        pushButton_Proc_FullVideo->setObjectName(QString::fromUtf8("pushButton_Proc_FullVideo"));

        gridLayout_3->addWidget(pushButton_Proc_FullVideo, 0, 3, 1, 1);

        spinBox_Proc_Frame = new QSpinBox(groupBox_Proc);
        spinBox_Proc_Frame->setObjectName(QString::fromUtf8("spinBox_Proc_Frame"));
        spinBox_Proc_Frame->setMinimumSize(QSize(120, 0));
        spinBox_Proc_Frame->setMaximumSize(QSize(120, 16777215));
        spinBox_Proc_Frame->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Proc_Frame->setMaximum(480);

        gridLayout_3->addWidget(spinBox_Proc_Frame, 2, 2, 1, 1);

        horizontalSlider_Proc_Frame = new QSlider(groupBox_Proc);
        horizontalSlider_Proc_Frame->setObjectName(QString::fromUtf8("horizontalSlider_Proc_Frame"));
        horizontalSlider_Proc_Frame->setMaximum(480);
        horizontalSlider_Proc_Frame->setOrientation(Qt::Horizontal);
        horizontalSlider_Proc_Frame->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_Proc_Frame->setTickInterval(240);

        gridLayout_3->addWidget(horizontalSlider_Proc_Frame, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox_Proc, 2, 0, 1, 1);

        D_MAKRO_CiliaSphereTracker->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_CiliaSphereTracker);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1155, 21));
        menuData = new QMenu(menubar);
        menuData->setObjectName(QString::fromUtf8("menuData"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuAnalysis = new QMenu(menubar);
        menuAnalysis->setObjectName(QString::fromUtf8("menuAnalysis"));
        D_MAKRO_CiliaSphereTracker->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_CiliaSphereTracker);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_CiliaSphereTracker->setStatusBar(statusbar);

        menubar->addAction(menuData->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menubar->addAction(menuAnalysis->menuAction());
        menuData->addAction(action_Data_Add);
        menuData->addAction(action_Data_Clear);
        menuWindow->addAction(action_Show_Minimum);
        menuWindow->addAction(action_Show_Normal);
        menuWindow->addAction(action_Show_Maximum);
        menuWindow->addAction(action_Show_Fullscreen);
        menuAnalysis->addAction(action_Save_Analysis_All);

        retranslateUi(D_MAKRO_CiliaSphereTracker);
        QObject::connect(action_Show_Normal, SIGNAL(triggered()), D_MAKRO_CiliaSphereTracker, SLOT(showNormal()));
        QObject::connect(action_Show_Minimum, SIGNAL(triggered()), D_MAKRO_CiliaSphereTracker, SLOT(showMinimized()));
        QObject::connect(action_Show_Maximum, SIGNAL(triggered()), D_MAKRO_CiliaSphereTracker, SLOT(showMaximized()));
        QObject::connect(action_Show_Fullscreen, SIGNAL(triggered()), D_MAKRO_CiliaSphereTracker, SLOT(showFullScreen()));

        tabWidget_ResType->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(D_MAKRO_CiliaSphereTracker);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_CiliaSphereTracker)
    {
        D_MAKRO_CiliaSphereTracker->setWindowTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "MainWindow", nullptr));
        action_Data_Add->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Add", nullptr));
#if QT_CONFIG(shortcut)
        action_Data_Add->setShortcut(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Data_Clear->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Clear", nullptr));
        action_Show_Minimum->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Minimum", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Minimum->setShortcut(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "F9", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Normal->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Normal", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Normal->setShortcut(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "F10", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Maximum->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Maximum", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Maximum->setShortcut(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "F11", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Fullscreen->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Fullscreen", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Fullscreen->setShortcut(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "F12", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Save_Analysis_All->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Save Analysis of all Videos", nullptr));
#if QT_CONFIG(shortcut)
        action_Save_Analysis_All->setShortcut(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Ctrl+F5", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_Res->setTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Results", nullptr));
        groupBox_Res_GridSamplingParam->setTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Grid sampling", nullptr));
        spinBox_ParamGridHorizontal->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", " (width: ?px each)", nullptr));
        spinBox_ParamGridHorizontal->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "horizontal: ", nullptr));
        spinBox_ParamGridVertical->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", " (height: ?px each)", nullptr));
        spinBox_ParamGridVertical->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "vertical: ", nullptr));
        spinBox_ParamGrid_CellEnd->setSuffix(QString());
        spinBox_ParamGrid_CellEnd->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "to cell ", nullptr));
        spinBox_ParamGrid_CellStart->setSuffix(QString());
        spinBox_ParamGrid_CellStart->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "display from cell ", nullptr));
        groupBox_Res_TimeAxis->setTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Time axis", nullptr));
        doubleSpinBox_Res_PlotLine_FixRange_T_max->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "s", nullptr));
        label_16->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Time shift poincare plots:", nullptr));
        label_15->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Plot range linear plot:", nullptr));
        spinBox_Res_PlotPoincare_Shift_Frames->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", " frames", nullptr));
        doubleSpinBox_Res_PlotLine_FixRange_T_min->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "s", nullptr));
        doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", " seconds", nullptr));
        groupBox_Res_VectorFieldParam->setTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Vectorfield settings", nullptr));
        label_5->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Shift/Length", nullptr));
        label_7->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "\302\261", nullptr));
        label_6->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Angle", nullptr));
        label_12->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "\302\261", nullptr));
        doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "scale in: px shift / ", nullptr));
        doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", " s", nullptr));
        doubleSpinBox_Res_VectorFieldParam_ScaleLength->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "scale show: ", nullptr));
        doubleSpinBox_Res_VectorFieldParam_ScaleLength->setSuffix(QString());
        spinBox_Res_VectorFieldParam_Thickness_Vector->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Res_VectorFieldParam_Thickness_Vector->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "vector thickness: ", nullptr));
        spinBox_Res_VectorFieldParam_KindeySteps->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "steps", nullptr));
        spinBox_Res_VectorFieldParam_KindeySteps->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "error resolution: ", nullptr));
        spinBox_Res_VectorFieldParam_Thickness_Error->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Res_VectorFieldParam_Thickness_Error->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "error thickness: ", nullptr));
        groupBox_Res_GraphicsParam->setTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Graphics", nullptr));
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "> ", nullptr));
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "% (red)", nullptr));
        checkBox_Res_TimeProjSum_ColorLow->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Color Low", nullptr));
        checkBox_Res_TimeProjSum_Gamma->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Gamma Correct", nullptr));
        checkBox_Res_TimeProjSum_ColorHigh->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Color High", nullptr));
        doubleSpinBox_Res_TimeProjSum_ColorLow->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "<= ", nullptr));
        doubleSpinBox_Res_TimeProjSum_ColorLow->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "% (black)", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "of value range", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "of nonzero px", nullptr));

        groupBox_Res_AngleCustom->setTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Angle analysis", nullptr));
        label_14->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Stat", nullptr));
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setSuffix(QString());
        label_Res_AngleCustom_Stat_Uncertanty->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "\302\261", nullptr));
        checkBox_Res_PlotLine_FixRange_A->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Fix plot range", nullptr));
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setSuffix(QString());
        groupBox_Res_MovAv->setTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Moving average", nullptr));
        spinBox_Res_MovAv_CurrentFrame->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", " to 120", nullptr));
        spinBox_Res_MovAv_CurrentFrame->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "frames ", nullptr));
        doubleSpinBox_Res_MovAv_CurrentTime->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "seconds ", nullptr));
        doubleSpinBox_Res_MovAv_CurrentTime->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", " to 5,00", nullptr));
        comboBox_Res_MovAv_TimeWindow->setItemText(0, QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Full Video", nullptr));
        comboBox_Res_MovAv_TimeWindow->setItemText(1, QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Moving Average", nullptr));

        comboBox_Res_MovAv_Background->setItemText(0, QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Time Projection", nullptr));
        comboBox_Res_MovAv_Background->setItemText(1, QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Input Video", nullptr));

        doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "required frames w. detections: ", nullptr));
        doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "%", nullptr));
        spinBox_Res_MovAv_WindowFrames->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", " frames", nullptr));
        spinBox_Res_MovAv_WindowFrames->setPrefix(QString());
        doubleSpinBox_Res_MovAv_WindowTime->setPrefix(QString());
        doubleSpinBox_Res_MovAv_WindowTime->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", " seconds", nullptr));
        tabWidget_ResType->setTabText(tabWidget_ResType->indexOf(tab_ResPlotLine), QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Line", nullptr));
        tabWidget_ResType->setTabText(tabWidget_ResType->indexOf(tab_ResPlotPoincare), QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Poincare", nullptr));
        tabWidget_ResType->setTabText(tabWidget_ResType->indexOf(tab_ResTable), QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Table", nullptr));
        groupBox_Res_SpeedCustom->setTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Speed analysis", nullptr));
        label_13->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Stat", nullptr));
        checkBox_Res_PlotLine_FixRange_S->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Fix plot range", nullptr));
        label_Res_SpeedCustom_Stat_Uncertanty->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "\302\261", nullptr));
        groupBox_Res_GridVisParam->setTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Grid visualization", nullptr));
        doubleSpinBox_Res_GridVisParam_Label_Scaling->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "scale: ", nullptr));
        doubleSpinBox_Res_GridVisParam_Label_Scaling->setSuffix(QString());
        checkBox_Res_GridVisParam_Grid->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Grid", nullptr));
        spinBox_Res_GridVisParam_Thickness_Grid->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Res_GridVisParam_Thickness_Grid->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "grid thickness: ", nullptr));
        checkBox_Res_GridVisParam_Labels->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Labels", nullptr));
        spinBox_Res_GridVisParam_Thickness_Label->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Res_GridVisParam_Thickness_Label->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "label thickness: ", nullptr));
        groupBox_Res_Heat->setTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Heatmap", nullptr));
        comboBox_Res_Heat_Mode->setItemText(0, QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Speed as color (blue=slow, red=fast)", nullptr));
        comboBox_Res_Heat_Mode->setItemText(1, QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Angle as color (red=0\302\260)", nullptr));
        comboBox_Res_Heat_Mode->setItemText(2, QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Speed as saturation (gray=slow, intense=fast), angle as color (red=0\302\260)", nullptr));

        groupBox_Data->setTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Data", nullptr));
        pushButton_Data_Add->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Add", nullptr));
        pushButton_Data_Clear->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Clear", nullptr));
        groupBox_Param->setTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Parameters", nullptr));
        doubleSpinBox_Param_Blur_Sigma->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "sigma: ", nullptr));
        spinBox_Param_FrameCountSmooth->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", " frames", nullptr));
        spinBox_Param_FrameCountSmooth->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Measure between: ", nullptr));
        doubleSpinBox_Param_Crop_Start->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "start: ", nullptr));
        doubleSpinBox_Param_Crop_Start->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "s", nullptr));
        doubleSpinBox_Param_Scale_mm->setPrefix(QString());
        doubleSpinBox_Param_Scale_mm->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "mm", nullptr));
        spinBox_Param_Crop_Left->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Param_Crop_Left->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "left: ", nullptr));
        label->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Scale", nullptr));
        label_Param_CropHeight->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Crop Height", nullptr));
        label_9->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Blur", nullptr));
        spinBox_Param_Crop_Bottom->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Param_Crop_Bottom->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "bottom: ", nullptr));
        spinBox_Param_Crop_Top->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", " px", nullptr));
        spinBox_Param_Crop_Top->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "top: ", nullptr));
        label_3->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Crop", nullptr));
        spinBox_Param_Blur_Size->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Param_Blur_Size->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "size: ", nullptr));
        label_2->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Image Pixels <-> World mm", nullptr));
        label_Param_CropTime->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Crop Time", nullptr));
        label_8->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Smooth", nullptr));
        spinBox_Param_Crop_Right->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Param_Crop_Right->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "right: ", nullptr));
        label_10->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Remove Noise", nullptr));
        label_Param_CropWidth->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Crop Width", nullptr));
        doubleSpinBox_Param_Crop_End->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "end: ", nullptr));
        doubleSpinBox_Param_Crop_End->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "s", nullptr));
        label_11->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Maximum Speed", nullptr));
        label_4->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Tracking", nullptr));
        doubleSpinBox_Param_MaxSpeed->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Maximum speed: ", nullptr));
        doubleSpinBox_Param_MaxSpeed->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "px/frame", nullptr));
        doubleSpinBox_Param_Scale_Px->setPrefix(QString());
        doubleSpinBox_Param_Scale_Px->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        groupBox_Proc->setTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Frame Processing", nullptr));
        doubleSpinBox_Proc_Time->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "second: ", nullptr));
        doubleSpinBox_Proc_Time->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", " / 20,00", nullptr));
        pushButton_Proc_FullVideo->setText(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Process Full Video", nullptr));
        spinBox_Proc_Frame->setSuffix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", " / 480", nullptr));
        spinBox_Proc_Frame->setPrefix(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "frame: ", nullptr));
        menuData->setTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Data", nullptr));
        menuWindow->setTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Window", nullptr));
        menuAnalysis->setTitle(QCoreApplication::translate("D_MAKRO_CiliaSphereTracker", "Analysis", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_CiliaSphereTracker: public Ui_D_MAKRO_CiliaSphereTracker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_CILIASPHERETRACKER_H
