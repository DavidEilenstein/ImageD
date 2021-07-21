/********************************************************************************
** Form generated from reading UI file 'd_makro_ciliaspheretracker.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
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
#include <QtWidgets/QLineEdit>
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
    QAction *action_Save_vectorfield_videos_on_analysis;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
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
    QSlider *horizontalSlider_Proc_Frame;
    QSpinBox *spinBox_Proc_Frame;
    QGraphicsView *graphicsView_Proc;
    QComboBox *comboBox_Proc_Step;
    QPushButton *pushButton_Proc_FullVideo;
    QDoubleSpinBox *doubleSpinBox_Proc_Time;
    QGroupBox *groupBox_Res;
    QGridLayout *gridLayout_4;
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
    QGroupBox *groupBox_Res_GraphicsParam;
    QGridLayout *gridLayout_7;
    QDoubleSpinBox *doubleSpinBox_Res_TimeProjSum_Gamma;
    QDoubleSpinBox *doubleSpinBox_Res_TimeProjSum_ColorHigh;
    QCheckBox *checkBox_Res_TimeProjSum_ColorLow;
    QCheckBox *checkBox_Res_TimeProjSum_Gamma;
    QCheckBox *checkBox_Res_TimeProjSum_ColorHigh;
    QDoubleSpinBox *doubleSpinBox_Res_TimeProjSum_ColorLow;
    QComboBox *comboBox;
    QGroupBox *groupBox_Res_Heat;
    QGridLayout *gridLayout_11;
    QComboBox *comboBox_Res_Heat_Mode;
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
    QWidget *page_Res_OverviewNew;
    QGridLayout *gridLayout_30;
    QGridLayout *gridLayout_Res_OverviewNew_Hist_DistanceCenterIntersections;
    QGridLayout *gridLayout_Res_OverviewNew_Line_LinearSpeed;
    QGridLayout *gridLayout_Res_OverviewNew_Hist_AngularSpeed;
    QGridLayout *gridLayout_Res_OverviewNew_Line_AngularSpeed;
    QGridLayout *gridLayout_Res_OverviewNew_Hist_LinearSpeed;
    QGroupBox *groupBox_Res_AngleCustom;
    QGridLayout *gridLayout_16;
    QLabel *label_Res_AngleCustom_Stat_Uncertanty;
    QDoubleSpinBox *doubleSpinBox_Res_PlotLine_FixRange_A_max;
    QLabel *label_14;
    QComboBox *comboBox_Res_AngleCustom_Stat_Uncertanty;
    QCheckBox *checkBox_Res_PlotLine_FixRange_A;
    QFrame *line_7;
    QDoubleSpinBox *doubleSpinBox_Res_PlotLine_FixRange_A_min;
    QComboBox *comboBox_Res_AngleCustom_Stat_Value;
    QGroupBox *groupBox_Res_GridVisParam;
    QGridLayout *gridLayout_14;
    QDoubleSpinBox *doubleSpinBox_Res_GridVisParam_Label_Scaling;
    QCheckBox *checkBox_Res_GridVisParam_Grid;
    QSpinBox *spinBox_Res_GridVisParam_Thickness_Grid;
    QCheckBox *checkBox_Res_GridVisParam_Labels;
    QSpinBox *spinBox_Res_GridVisParam_Thickness_Label;
    QGroupBox *groupBox_Res_SpeedCustom;
    QGridLayout *gridLayout_15;
    QComboBox *comboBox_Res_SpeedCustom_Stat_Value;
    QStackedWidget *stackedWidget_Res_SpeedCustom_ShiftType_SpeedRange;
    QWidget *page_6;
    QGridLayout *gridLayout_32;
    QDoubleSpinBox *doubleSpinBox_Res_PlotLine_FixRange_S_min_linear;
    QDoubleSpinBox *doubleSpinBox_Res_PlotLine_FixRange_S_max_linear;
    QWidget *page_7;
    QGridLayout *gridLayout_33;
    QDoubleSpinBox *doubleSpinBox_Res_PlotLine_FixRange_S_max_angular;
    QDoubleSpinBox *doubleSpinBox_Res_PlotLine_FixRange_S_min_angular;
    QComboBox *comboBox_Res_SpeedCustom_ShiftType;
    QFrame *line_3;
    QComboBox *comboBox_Res_SpeedCustom_Stat_Uncertanty;
    QCheckBox *checkBox_Res_PlotLine_FixRange_S;
    QLabel *label_13;
    QLabel *label_Res_SpeedCustom_Stat_Uncertanty;
    QGroupBox *groupBox_Res_VectorFieldParam;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_Res_VectorFieldParam_ShiftType;
    QLabel *label_5;
    QComboBox *comboBox_Res_VectorFieldParam_Length_Value;
    QLabel *label_7;
    QComboBox *comboBox_Res_VectorFieldParam_Length_Error;
    QFrame *line_13;
    QLabel *label_Res_VectorFieldParam_Angle;
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
    QGroupBox *groupBox_Res_VortexCenter;
    QGridLayout *gridLayout_20;
    QFrame *line_9;
    QGridLayout *gridLayout_25;
    QDoubleSpinBox *doubleSpinBox_Res_VortexCenter_Ransac_pGoodGuess;
    QCheckBox *checkBox_Res_VortexCenter_Ransac;
    QSpinBox *spinBox_Res_VortexCenter_RansacIterations;
    QDoubleSpinBox *doubleSpinBox_Res_VortexCenter_Ransac_pOutliers;
    QHBoxLayout *horizontalLayout_5;
    QDoubleSpinBox *doubleSpinBox_Res_VortexCenter_RansacSubsetSize;
    QComboBox *comboBox_Res_VortexCenter_Ransac_PointsOrLines;
    QFrame *line_5;
    QGridLayout *gridLayout_21;
    QCheckBox *checkBox_Res_VortexCenter_MovingAverage;
    QSpinBox *spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm;
    QDoubleSpinBox *doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec;
    QFrame *line_12;
    QFrame *line_10;
    QGridLayout *gridLayout_34;
    QDoubleSpinBox *doubleSpinBox_Res_VortexCenter_RelPos_H_Set1;
    QLineEdit *lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set1;
    QLabel *label_23;
    QLabel *label_21;
    QDoubleSpinBox *doubleSpinBox_Res_VortexCenter_RelPos_H_Use;
    QLineEdit *lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set2;
    QLabel *label_24;
    QDoubleSpinBox *doubleSpinBox_Res_VortexCenter_RelPos_H_Set2;
    QLabel *label_6;
    QLabel *label_18;
    QLabel *label_19;
    QGridLayout *gridLayout_36;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBox_Res_VortexCenter_WellDiameter;
    QGridLayout *gridLayout_35;
    QSpinBox *spinBox_Res_VortexCenter_Thickness;
    QDoubleSpinBox *doubleSpinBox_Res_VortexCenter_Resolution_Rel;
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
    QComboBox *comboBox_Res_Type;
    QGroupBox *groupBox_Res_GridSamplingParam;
    QGridLayout *gridLayout_8;
    QSpinBox *spinBox_ParamGridHorizontal;
    QSpinBox *spinBox_ParamGridVertical;
    QSpinBox *spinBox_ParamGrid_CellEnd;
    QSpinBox *spinBox_ParamGrid_CellStart;
    QGroupBox *groupBox_Res_Histo;
    QGridLayout *gridLayout_22;
    QCheckBox *checkBox_Res_Histo_Uni;
    QStackedWidget *stackedWidget_HistClasses;
    QWidget *page_4;
    QGridLayout *gridLayout_29;
    QSpinBox *spinBox_Res_Histo_Classes_Speed;
    QWidget *page_5;
    QGridLayout *gridLayout_31;
    QSpinBox *spinBox_Res_Histo_Classes_Dist;
    QStackedWidget *stackedWidget_Res_Histo_Type;
    QWidget *page;
    QGridLayout *gridLayout_26;
    QDoubleSpinBox *doubleSpinBox_Res_Histo_MaxSpeedLinear;
    QWidget *page_3;
    QGridLayout *gridLayout_27;
    QDoubleSpinBox *doubleSpinBox_Res_Histo_MaxSpeedAngular;
    QWidget *page_2;
    QGridLayout *gridLayout_28;
    QDoubleSpinBox *doubleSpinBox_Res_Histo_MaxDistCenterIntersections;
    QCheckBox *checkBox_Res_Histo_Acc;
    QComboBox *comboBox_Res_Histo_Type;
    QCheckBox *checkBox_Res_Histo_VariationAsColorValue;
    QMenuBar *menubar;
    QMenu *menuData;
    QMenu *menuWindow;
    QMenu *menuAnalysis;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_CiliaSphereTracker)
    {
        if (D_MAKRO_CiliaSphereTracker->objectName().isEmpty())
            D_MAKRO_CiliaSphereTracker->setObjectName(QString::fromUtf8("D_MAKRO_CiliaSphereTracker"));
        D_MAKRO_CiliaSphereTracker->resize(1247, 839);
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
        action_Save_vectorfield_videos_on_analysis = new QAction(D_MAKRO_CiliaSphereTracker);
        action_Save_vectorfield_videos_on_analysis->setObjectName(QString::fromUtf8("action_Save_vectorfield_videos_on_analysis"));
        action_Save_vectorfield_videos_on_analysis->setCheckable(true);
        action_Save_vectorfield_videos_on_analysis->setChecked(false);
        centralwidget = new QWidget(D_MAKRO_CiliaSphereTracker);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_Data = new QGroupBox(centralwidget);
        groupBox_Data->setObjectName(QString::fromUtf8("groupBox_Data"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_Data->sizePolicy().hasHeightForWidth());
        groupBox_Data->setSizePolicy(sizePolicy);
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
        sizePolicy.setHeightForWidth(groupBox_Param->sizePolicy().hasHeightForWidth());
        groupBox_Param->setSizePolicy(sizePolicy);
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
        doubleSpinBox_Param_Crop_Start->setMaximum(999.000000000000000);
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
        doubleSpinBox_Param_Crop_End->setMaximum(999.000000000000000);
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
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_Proc->sizePolicy().hasHeightForWidth());
        groupBox_Proc->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(groupBox_Proc);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(6, 6, 6, 6);
        horizontalSlider_Proc_Frame = new QSlider(groupBox_Proc);
        horizontalSlider_Proc_Frame->setObjectName(QString::fromUtf8("horizontalSlider_Proc_Frame"));
        horizontalSlider_Proc_Frame->setMaximum(480);
        horizontalSlider_Proc_Frame->setOrientation(Qt::Horizontal);
        horizontalSlider_Proc_Frame->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_Proc_Frame->setTickInterval(240);

        gridLayout_3->addWidget(horizontalSlider_Proc_Frame, 2, 1, 1, 1);

        spinBox_Proc_Frame = new QSpinBox(groupBox_Proc);
        spinBox_Proc_Frame->setObjectName(QString::fromUtf8("spinBox_Proc_Frame"));
        spinBox_Proc_Frame->setMinimumSize(QSize(120, 0));
        spinBox_Proc_Frame->setMaximumSize(QSize(120, 16777215));
        spinBox_Proc_Frame->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Proc_Frame->setMaximum(480);

        gridLayout_3->addWidget(spinBox_Proc_Frame, 2, 2, 1, 1);

        graphicsView_Proc = new QGraphicsView(groupBox_Proc);
        graphicsView_Proc->setObjectName(QString::fromUtf8("graphicsView_Proc"));
        graphicsView_Proc->setMouseTracking(true);

        gridLayout_3->addWidget(graphicsView_Proc, 1, 1, 1, 3);

        comboBox_Proc_Step = new QComboBox(groupBox_Proc);
        comboBox_Proc_Step->setObjectName(QString::fromUtf8("comboBox_Proc_Step"));

        gridLayout_3->addWidget(comboBox_Proc_Step, 0, 1, 1, 2);

        pushButton_Proc_FullVideo = new QPushButton(groupBox_Proc);
        pushButton_Proc_FullVideo->setObjectName(QString::fromUtf8("pushButton_Proc_FullVideo"));

        gridLayout_3->addWidget(pushButton_Proc_FullVideo, 0, 3, 1, 1);

        doubleSpinBox_Proc_Time = new QDoubleSpinBox(groupBox_Proc);
        doubleSpinBox_Proc_Time->setObjectName(QString::fromUtf8("doubleSpinBox_Proc_Time"));
        doubleSpinBox_Proc_Time->setMinimumSize(QSize(120, 0));
        doubleSpinBox_Proc_Time->setMaximumSize(QSize(120, 16777215));
        doubleSpinBox_Proc_Time->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Proc_Time->setDecimals(2);
        doubleSpinBox_Proc_Time->setMaximum(20.000000000000000);
        doubleSpinBox_Proc_Time->setValue(0.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_Proc_Time, 2, 3, 1, 1);


        gridLayout->addWidget(groupBox_Proc, 2, 0, 1, 1);

        groupBox_Res = new QGroupBox(centralwidget);
        groupBox_Res->setObjectName(QString::fromUtf8("groupBox_Res"));
        groupBox_Res->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(5);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_Res->sizePolicy().hasHeightForWidth());
        groupBox_Res->setSizePolicy(sizePolicy2);
        gridLayout_4 = new QGridLayout(groupBox_Res);
        gridLayout_4->setSpacing(3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(6, 6, 6, 6);
        groupBox_Res_TimeAxis = new QGroupBox(groupBox_Res);
        groupBox_Res_TimeAxis->setObjectName(QString::fromUtf8("groupBox_Res_TimeAxis"));
        groupBox_Res_TimeAxis->setFlat(true);
        gridLayout_24 = new QGridLayout(groupBox_Res_TimeAxis);
        gridLayout_24->setSpacing(3);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        gridLayout_24->setContentsMargins(0, 3, 0, 3);
        comboBox_Res_PlotLine_FixRange_T = new QComboBox(groupBox_Res_TimeAxis);
        comboBox_Res_PlotLine_FixRange_T->setObjectName(QString::fromUtf8("comboBox_Res_PlotLine_FixRange_T"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox_Res_PlotLine_FixRange_T->sizePolicy().hasHeightForWidth());
        comboBox_Res_PlotLine_FixRange_T->setSizePolicy(sizePolicy3);

        gridLayout_24->addWidget(comboBox_Res_PlotLine_FixRange_T, 0, 1, 1, 1);

        doubleSpinBox_Res_PlotLine_FixRange_T_max = new QDoubleSpinBox(groupBox_Res_TimeAxis);
        doubleSpinBox_Res_PlotLine_FixRange_T_max->setObjectName(QString::fromUtf8("doubleSpinBox_Res_PlotLine_FixRange_T_max"));
        doubleSpinBox_Res_PlotLine_FixRange_T_max->setEnabled(false);
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(doubleSpinBox_Res_PlotLine_FixRange_T_max->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_PlotLine_FixRange_T_max->setSizePolicy(sizePolicy4);
        doubleSpinBox_Res_PlotLine_FixRange_T_max->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_PlotLine_FixRange_T_max->setMaximum(9999.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_T_max->setValue(120.000000000000000);

        gridLayout_24->addWidget(doubleSpinBox_Res_PlotLine_FixRange_T_max, 0, 3, 1, 1);

        label_16 = new QLabel(groupBox_Res_TimeAxis);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_24->addWidget(label_16, 0, 5, 1, 1);

        label_15 = new QLabel(groupBox_Res_TimeAxis);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy5);

        gridLayout_24->addWidget(label_15, 0, 0, 1, 1);

        spinBox_Res_PlotPoincare_Shift_Frames = new QSpinBox(groupBox_Res_TimeAxis);
        spinBox_Res_PlotPoincare_Shift_Frames->setObjectName(QString::fromUtf8("spinBox_Res_PlotPoincare_Shift_Frames"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(spinBox_Res_PlotPoincare_Shift_Frames->sizePolicy().hasHeightForWidth());
        spinBox_Res_PlotPoincare_Shift_Frames->setSizePolicy(sizePolicy6);
        spinBox_Res_PlotPoincare_Shift_Frames->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_PlotPoincare_Shift_Frames->setValue(1);

        gridLayout_24->addWidget(spinBox_Res_PlotPoincare_Shift_Frames, 0, 6, 1, 1);

        doubleSpinBox_Res_PlotLine_FixRange_T_min = new QDoubleSpinBox(groupBox_Res_TimeAxis);
        doubleSpinBox_Res_PlotLine_FixRange_T_min->setObjectName(QString::fromUtf8("doubleSpinBox_Res_PlotLine_FixRange_T_min"));
        doubleSpinBox_Res_PlotLine_FixRange_T_min->setEnabled(false);
        sizePolicy4.setHeightForWidth(doubleSpinBox_Res_PlotLine_FixRange_T_min->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_PlotLine_FixRange_T_min->setSizePolicy(sizePolicy4);
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
        sizePolicy6.setHeightForWidth(doubleSpinBox_Res_PlotPoincare_Shift_Seconds->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setSizePolicy(sizePolicy6);
        doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setDecimals(2);
        doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setValue(0.020000000000000);

        gridLayout_24->addWidget(doubleSpinBox_Res_PlotPoincare_Shift_Seconds, 0, 7, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_TimeAxis, 8, 0, 1, 2);

        groupBox_Res_GraphicsParam = new QGroupBox(groupBox_Res);
        groupBox_Res_GraphicsParam->setObjectName(QString::fromUtf8("groupBox_Res_GraphicsParam"));
        groupBox_Res_GraphicsParam->setFlat(true);
        gridLayout_7 = new QGridLayout(groupBox_Res_GraphicsParam);
        gridLayout_7->setSpacing(3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 3, 0, 3);
        doubleSpinBox_Res_TimeProjSum_Gamma = new QDoubleSpinBox(groupBox_Res_GraphicsParam);
        doubleSpinBox_Res_TimeProjSum_Gamma->setObjectName(QString::fromUtf8("doubleSpinBox_Res_TimeProjSum_Gamma"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(doubleSpinBox_Res_TimeProjSum_Gamma->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_TimeProjSum_Gamma->setSizePolicy(sizePolicy7);
        doubleSpinBox_Res_TimeProjSum_Gamma->setMinimumSize(QSize(50, 0));
        doubleSpinBox_Res_TimeProjSum_Gamma->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_TimeProjSum_Gamma->setSingleStep(0.100000000000000);
        doubleSpinBox_Res_TimeProjSum_Gamma->setValue(0.500000000000000);

        gridLayout_7->addWidget(doubleSpinBox_Res_TimeProjSum_Gamma, 0, 6, 1, 1);

        doubleSpinBox_Res_TimeProjSum_ColorHigh = new QDoubleSpinBox(groupBox_Res_GraphicsParam);
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setObjectName(QString::fromUtf8("doubleSpinBox_Res_TimeProjSum_ColorHigh"));
        sizePolicy7.setHeightForWidth(doubleSpinBox_Res_TimeProjSum_ColorHigh->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setSizePolicy(sizePolicy7);
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setMinimumSize(QSize(100, 0));
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setDecimals(2);
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setMaximum(100.000000000000000);
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setValue(75.000000000000000);

        gridLayout_7->addWidget(doubleSpinBox_Res_TimeProjSum_ColorHigh, 0, 3, 1, 1);

        checkBox_Res_TimeProjSum_ColorLow = new QCheckBox(groupBox_Res_GraphicsParam);
        checkBox_Res_TimeProjSum_ColorLow->setObjectName(QString::fromUtf8("checkBox_Res_TimeProjSum_ColorLow"));
        sizePolicy6.setHeightForWidth(checkBox_Res_TimeProjSum_ColorLow->sizePolicy().hasHeightForWidth());
        checkBox_Res_TimeProjSum_ColorLow->setSizePolicy(sizePolicy6);
        checkBox_Res_TimeProjSum_ColorLow->setChecked(false);

        gridLayout_7->addWidget(checkBox_Res_TimeProjSum_ColorLow, 0, 0, 1, 1);

        checkBox_Res_TimeProjSum_Gamma = new QCheckBox(groupBox_Res_GraphicsParam);
        checkBox_Res_TimeProjSum_Gamma->setObjectName(QString::fromUtf8("checkBox_Res_TimeProjSum_Gamma"));
        sizePolicy6.setHeightForWidth(checkBox_Res_TimeProjSum_Gamma->sizePolicy().hasHeightForWidth());
        checkBox_Res_TimeProjSum_Gamma->setSizePolicy(sizePolicy6);
        checkBox_Res_TimeProjSum_Gamma->setChecked(true);

        gridLayout_7->addWidget(checkBox_Res_TimeProjSum_Gamma, 0, 5, 1, 1);

        checkBox_Res_TimeProjSum_ColorHigh = new QCheckBox(groupBox_Res_GraphicsParam);
        checkBox_Res_TimeProjSum_ColorHigh->setObjectName(QString::fromUtf8("checkBox_Res_TimeProjSum_ColorHigh"));
        sizePolicy6.setHeightForWidth(checkBox_Res_TimeProjSum_ColorHigh->sizePolicy().hasHeightForWidth());
        checkBox_Res_TimeProjSum_ColorHigh->setSizePolicy(sizePolicy6);
        checkBox_Res_TimeProjSum_ColorHigh->setChecked(true);

        gridLayout_7->addWidget(checkBox_Res_TimeProjSum_ColorHigh, 0, 2, 1, 1);

        doubleSpinBox_Res_TimeProjSum_ColorLow = new QDoubleSpinBox(groupBox_Res_GraphicsParam);
        doubleSpinBox_Res_TimeProjSum_ColorLow->setObjectName(QString::fromUtf8("doubleSpinBox_Res_TimeProjSum_ColorLow"));
        sizePolicy7.setHeightForWidth(doubleSpinBox_Res_TimeProjSum_ColorLow->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_TimeProjSum_ColorLow->setSizePolicy(sizePolicy7);
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
        sizePolicy7.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy7);
        comboBox->setMinimumSize(QSize(100, 0));

        gridLayout_7->addWidget(comboBox, 0, 4, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_GraphicsParam, 13, 0, 1, 2);

        groupBox_Res_Heat = new QGroupBox(groupBox_Res);
        groupBox_Res_Heat->setObjectName(QString::fromUtf8("groupBox_Res_Heat"));
        groupBox_Res_Heat->setFlat(true);
        gridLayout_11 = new QGridLayout(groupBox_Res_Heat);
        gridLayout_11->setSpacing(3);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 3, 0, 3);
        comboBox_Res_Heat_Mode = new QComboBox(groupBox_Res_Heat);
        comboBox_Res_Heat_Mode->setObjectName(QString::fromUtf8("comboBox_Res_Heat_Mode"));

        gridLayout_11->addWidget(comboBox_Res_Heat_Mode, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_Heat, 4, 0, 1, 2);

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
        page_Res_OverviewNew = new QWidget();
        page_Res_OverviewNew->setObjectName(QString::fromUtf8("page_Res_OverviewNew"));
        gridLayout_30 = new QGridLayout(page_Res_OverviewNew);
        gridLayout_30->setSpacing(0);
        gridLayout_30->setObjectName(QString::fromUtf8("gridLayout_30"));
        gridLayout_30->setContentsMargins(0, 0, 0, 0);
        gridLayout_Res_OverviewNew_Hist_DistanceCenterIntersections = new QGridLayout();
        gridLayout_Res_OverviewNew_Hist_DistanceCenterIntersections->setObjectName(QString::fromUtf8("gridLayout_Res_OverviewNew_Hist_DistanceCenterIntersections"));

        gridLayout_30->addLayout(gridLayout_Res_OverviewNew_Hist_DistanceCenterIntersections, 0, 4, 1, 2);

        gridLayout_Res_OverviewNew_Line_LinearSpeed = new QGridLayout();
        gridLayout_Res_OverviewNew_Line_LinearSpeed->setObjectName(QString::fromUtf8("gridLayout_Res_OverviewNew_Line_LinearSpeed"));

        gridLayout_30->addLayout(gridLayout_Res_OverviewNew_Line_LinearSpeed, 1, 0, 1, 3);

        gridLayout_Res_OverviewNew_Hist_AngularSpeed = new QGridLayout();
        gridLayout_Res_OverviewNew_Hist_AngularSpeed->setObjectName(QString::fromUtf8("gridLayout_Res_OverviewNew_Hist_AngularSpeed"));

        gridLayout_30->addLayout(gridLayout_Res_OverviewNew_Hist_AngularSpeed, 0, 2, 1, 2);

        gridLayout_Res_OverviewNew_Line_AngularSpeed = new QGridLayout();
        gridLayout_Res_OverviewNew_Line_AngularSpeed->setObjectName(QString::fromUtf8("gridLayout_Res_OverviewNew_Line_AngularSpeed"));

        gridLayout_30->addLayout(gridLayout_Res_OverviewNew_Line_AngularSpeed, 1, 3, 1, 3);

        gridLayout_Res_OverviewNew_Hist_LinearSpeed = new QGridLayout();
        gridLayout_Res_OverviewNew_Hist_LinearSpeed->setObjectName(QString::fromUtf8("gridLayout_Res_OverviewNew_Hist_LinearSpeed"));

        gridLayout_30->addLayout(gridLayout_Res_OverviewNew_Hist_LinearSpeed, 0, 0, 1, 2);

        stackedWidget_Res_Type->addWidget(page_Res_OverviewNew);

        gridLayout_4->addWidget(stackedWidget_Res_Type, 1, 0, 1, 2);

        groupBox_Res_AngleCustom = new QGroupBox(groupBox_Res);
        groupBox_Res_AngleCustom->setObjectName(QString::fromUtf8("groupBox_Res_AngleCustom"));
        groupBox_Res_AngleCustom->setFlat(true);
        gridLayout_16 = new QGridLayout(groupBox_Res_AngleCustom);
        gridLayout_16->setSpacing(3);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 3, 0, 3);
        label_Res_AngleCustom_Stat_Uncertanty = new QLabel(groupBox_Res_AngleCustom);
        label_Res_AngleCustom_Stat_Uncertanty->setObjectName(QString::fromUtf8("label_Res_AngleCustom_Stat_Uncertanty"));
        sizePolicy5.setHeightForWidth(label_Res_AngleCustom_Stat_Uncertanty->sizePolicy().hasHeightForWidth());
        label_Res_AngleCustom_Stat_Uncertanty->setSizePolicy(sizePolicy5);

        gridLayout_16->addWidget(label_Res_AngleCustom_Stat_Uncertanty, 0, 2, 1, 1);

        doubleSpinBox_Res_PlotLine_FixRange_A_max = new QDoubleSpinBox(groupBox_Res_AngleCustom);
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setObjectName(QString::fromUtf8("doubleSpinBox_Res_PlotLine_FixRange_A_max"));
        sizePolicy4.setHeightForWidth(doubleSpinBox_Res_PlotLine_FixRange_A_max->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setSizePolicy(sizePolicy4);
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setMinimumSize(QSize(100, 0));
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setMinimum(-9999.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setMaximum(9999.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setValue(180.000000000000000);

        gridLayout_16->addWidget(doubleSpinBox_Res_PlotLine_FixRange_A_max, 0, 7, 1, 1);

        label_14 = new QLabel(groupBox_Res_AngleCustom);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy5.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy5);

        gridLayout_16->addWidget(label_14, 0, 0, 1, 1);

        comboBox_Res_AngleCustom_Stat_Uncertanty = new QComboBox(groupBox_Res_AngleCustom);
        comboBox_Res_AngleCustom_Stat_Uncertanty->setObjectName(QString::fromUtf8("comboBox_Res_AngleCustom_Stat_Uncertanty"));

        gridLayout_16->addWidget(comboBox_Res_AngleCustom_Stat_Uncertanty, 0, 3, 1, 1);

        checkBox_Res_PlotLine_FixRange_A = new QCheckBox(groupBox_Res_AngleCustom);
        checkBox_Res_PlotLine_FixRange_A->setObjectName(QString::fromUtf8("checkBox_Res_PlotLine_FixRange_A"));
        sizePolicy6.setHeightForWidth(checkBox_Res_PlotLine_FixRange_A->sizePolicy().hasHeightForWidth());
        checkBox_Res_PlotLine_FixRange_A->setSizePolicy(sizePolicy6);
        checkBox_Res_PlotLine_FixRange_A->setMinimumSize(QSize(0, 0));
        checkBox_Res_PlotLine_FixRange_A->setMaximumSize(QSize(16777215, 16777215));
        checkBox_Res_PlotLine_FixRange_A->setChecked(true);

        gridLayout_16->addWidget(checkBox_Res_PlotLine_FixRange_A, 0, 5, 1, 1);

        line_7 = new QFrame(groupBox_Res_AngleCustom);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_16->addWidget(line_7, 0, 4, 1, 1);

        doubleSpinBox_Res_PlotLine_FixRange_A_min = new QDoubleSpinBox(groupBox_Res_AngleCustom);
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setObjectName(QString::fromUtf8("doubleSpinBox_Res_PlotLine_FixRange_A_min"));
        sizePolicy4.setHeightForWidth(doubleSpinBox_Res_PlotLine_FixRange_A_min->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setSizePolicy(sizePolicy4);
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setMinimumSize(QSize(100, 0));
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setMinimum(-360.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setMaximum(360.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setValue(-180.000000000000000);

        gridLayout_16->addWidget(doubleSpinBox_Res_PlotLine_FixRange_A_min, 0, 6, 1, 1);

        comboBox_Res_AngleCustom_Stat_Value = new QComboBox(groupBox_Res_AngleCustom);
        comboBox_Res_AngleCustom_Stat_Value->setObjectName(QString::fromUtf8("comboBox_Res_AngleCustom_Stat_Value"));

        gridLayout_16->addWidget(comboBox_Res_AngleCustom_Stat_Value, 0, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_AngleCustom, 7, 0, 1, 2);

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
        sizePolicy6.setHeightForWidth(checkBox_Res_GridVisParam_Grid->sizePolicy().hasHeightForWidth());
        checkBox_Res_GridVisParam_Grid->setSizePolicy(sizePolicy6);
        checkBox_Res_GridVisParam_Grid->setChecked(true);

        gridLayout_14->addWidget(checkBox_Res_GridVisParam_Grid, 0, 1, 1, 1);

        spinBox_Res_GridVisParam_Thickness_Grid = new QSpinBox(groupBox_Res_GridVisParam);
        spinBox_Res_GridVisParam_Thickness_Grid->setObjectName(QString::fromUtf8("spinBox_Res_GridVisParam_Thickness_Grid"));
        sizePolicy7.setHeightForWidth(spinBox_Res_GridVisParam_Thickness_Grid->sizePolicy().hasHeightForWidth());
        spinBox_Res_GridVisParam_Thickness_Grid->setSizePolicy(sizePolicy7);
        spinBox_Res_GridVisParam_Thickness_Grid->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_GridVisParam_Thickness_Grid->setMinimum(1);
        spinBox_Res_GridVisParam_Thickness_Grid->setMaximum(99);
        spinBox_Res_GridVisParam_Thickness_Grid->setValue(1);

        gridLayout_14->addWidget(spinBox_Res_GridVisParam_Thickness_Grid, 0, 2, 1, 1);

        checkBox_Res_GridVisParam_Labels = new QCheckBox(groupBox_Res_GridVisParam);
        checkBox_Res_GridVisParam_Labels->setObjectName(QString::fromUtf8("checkBox_Res_GridVisParam_Labels"));
        sizePolicy6.setHeightForWidth(checkBox_Res_GridVisParam_Labels->sizePolicy().hasHeightForWidth());
        checkBox_Res_GridVisParam_Labels->setSizePolicy(sizePolicy6);
        checkBox_Res_GridVisParam_Labels->setChecked(true);

        gridLayout_14->addWidget(checkBox_Res_GridVisParam_Labels, 0, 3, 1, 1);

        spinBox_Res_GridVisParam_Thickness_Label = new QSpinBox(groupBox_Res_GridVisParam);
        spinBox_Res_GridVisParam_Thickness_Label->setObjectName(QString::fromUtf8("spinBox_Res_GridVisParam_Thickness_Label"));
        spinBox_Res_GridVisParam_Thickness_Label->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_GridVisParam_Thickness_Label->setMinimum(1);
        spinBox_Res_GridVisParam_Thickness_Label->setMaximum(99);
        spinBox_Res_GridVisParam_Thickness_Label->setValue(1);

        gridLayout_14->addWidget(spinBox_Res_GridVisParam_Thickness_Label, 0, 4, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_GridVisParam, 11, 0, 1, 2);

        groupBox_Res_SpeedCustom = new QGroupBox(groupBox_Res);
        groupBox_Res_SpeedCustom->setObjectName(QString::fromUtf8("groupBox_Res_SpeedCustom"));
        groupBox_Res_SpeedCustom->setFlat(true);
        gridLayout_15 = new QGridLayout(groupBox_Res_SpeedCustom);
        gridLayout_15->setSpacing(3);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(0, 3, 0, 3);
        comboBox_Res_SpeedCustom_Stat_Value = new QComboBox(groupBox_Res_SpeedCustom);
        comboBox_Res_SpeedCustom_Stat_Value->setObjectName(QString::fromUtf8("comboBox_Res_SpeedCustom_Stat_Value"));

        gridLayout_15->addWidget(comboBox_Res_SpeedCustom_Stat_Value, 0, 2, 1, 1);

        stackedWidget_Res_SpeedCustom_ShiftType_SpeedRange = new QStackedWidget(groupBox_Res_SpeedCustom);
        stackedWidget_Res_SpeedCustom_ShiftType_SpeedRange->setObjectName(QString::fromUtf8("stackedWidget_Res_SpeedCustom_ShiftType_SpeedRange"));
        sizePolicy5.setHeightForWidth(stackedWidget_Res_SpeedCustom_ShiftType_SpeedRange->sizePolicy().hasHeightForWidth());
        stackedWidget_Res_SpeedCustom_ShiftType_SpeedRange->setSizePolicy(sizePolicy5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        gridLayout_32 = new QGridLayout(page_6);
        gridLayout_32->setSpacing(3);
        gridLayout_32->setObjectName(QString::fromUtf8("gridLayout_32"));
        gridLayout_32->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_Res_PlotLine_FixRange_S_min_linear = new QDoubleSpinBox(page_6);
        doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->setObjectName(QString::fromUtf8("doubleSpinBox_Res_PlotLine_FixRange_S_min_linear"));
        sizePolicy4.setHeightForWidth(doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->setSizePolicy(sizePolicy4);
        doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->setMinimumSize(QSize(50, 0));
        doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->setMinimum(-9999.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->setMaximum(9999.000000000000000);

        gridLayout_32->addWidget(doubleSpinBox_Res_PlotLine_FixRange_S_min_linear, 0, 0, 1, 1);

        doubleSpinBox_Res_PlotLine_FixRange_S_max_linear = new QDoubleSpinBox(page_6);
        doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->setObjectName(QString::fromUtf8("doubleSpinBox_Res_PlotLine_FixRange_S_max_linear"));
        sizePolicy4.setHeightForWidth(doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->setSizePolicy(sizePolicy4);
        doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->setMinimumSize(QSize(50, 0));
        doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->setMinimum(0.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->setMaximum(9999.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->setValue(160.000000000000000);

        gridLayout_32->addWidget(doubleSpinBox_Res_PlotLine_FixRange_S_max_linear, 0, 1, 1, 1);

        stackedWidget_Res_SpeedCustom_ShiftType_SpeedRange->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        gridLayout_33 = new QGridLayout(page_7);
        gridLayout_33->setSpacing(3);
        gridLayout_33->setObjectName(QString::fromUtf8("gridLayout_33"));
        gridLayout_33->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_Res_PlotLine_FixRange_S_max_angular = new QDoubleSpinBox(page_7);
        doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->setObjectName(QString::fromUtf8("doubleSpinBox_Res_PlotLine_FixRange_S_max_angular"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->setSizePolicy(sizePolicy6);
        doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->setMinimumSize(QSize(100, 0));
        doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->setDecimals(2);
        doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->setMinimum(0.010000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->setMaximum(1.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->setSingleStep(0.000100000000000);
        doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->setValue(0.200000000000000);

        gridLayout_33->addWidget(doubleSpinBox_Res_PlotLine_FixRange_S_max_angular, 0, 1, 1, 1);

        doubleSpinBox_Res_PlotLine_FixRange_S_min_angular = new QDoubleSpinBox(page_7);
        doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->setObjectName(QString::fromUtf8("doubleSpinBox_Res_PlotLine_FixRange_S_min_angular"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->setSizePolicy(sizePolicy6);
        doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->setMinimumSize(QSize(100, 0));
        doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->setDecimals(3);
        doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->setMinimum(0.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->setMaximum(1.000000000000000);
        doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->setSingleStep(0.000100000000000);
        doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->setValue(0.000000000000000);

        gridLayout_33->addWidget(doubleSpinBox_Res_PlotLine_FixRange_S_min_angular, 0, 0, 1, 1);

        stackedWidget_Res_SpeedCustom_ShiftType_SpeedRange->addWidget(page_7);

        gridLayout_15->addWidget(stackedWidget_Res_SpeedCustom_ShiftType_SpeedRange, 0, 7, 1, 1);

        comboBox_Res_SpeedCustom_ShiftType = new QComboBox(groupBox_Res_SpeedCustom);
        comboBox_Res_SpeedCustom_ShiftType->addItem(QString());
        comboBox_Res_SpeedCustom_ShiftType->addItem(QString());
        comboBox_Res_SpeedCustom_ShiftType->setObjectName(QString::fromUtf8("comboBox_Res_SpeedCustom_ShiftType"));

        gridLayout_15->addWidget(comboBox_Res_SpeedCustom_ShiftType, 0, 0, 1, 1);

        line_3 = new QFrame(groupBox_Res_SpeedCustom);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_15->addWidget(line_3, 0, 5, 1, 1);

        comboBox_Res_SpeedCustom_Stat_Uncertanty = new QComboBox(groupBox_Res_SpeedCustom);
        comboBox_Res_SpeedCustom_Stat_Uncertanty->setObjectName(QString::fromUtf8("comboBox_Res_SpeedCustom_Stat_Uncertanty"));

        gridLayout_15->addWidget(comboBox_Res_SpeedCustom_Stat_Uncertanty, 0, 4, 1, 1);

        checkBox_Res_PlotLine_FixRange_S = new QCheckBox(groupBox_Res_SpeedCustom);
        checkBox_Res_PlotLine_FixRange_S->setObjectName(QString::fromUtf8("checkBox_Res_PlotLine_FixRange_S"));
        sizePolicy6.setHeightForWidth(checkBox_Res_PlotLine_FixRange_S->sizePolicy().hasHeightForWidth());
        checkBox_Res_PlotLine_FixRange_S->setSizePolicy(sizePolicy6);
        checkBox_Res_PlotLine_FixRange_S->setMinimumSize(QSize(0, 0));
        checkBox_Res_PlotLine_FixRange_S->setMaximumSize(QSize(16777215, 16777215));
        checkBox_Res_PlotLine_FixRange_S->setChecked(true);

        gridLayout_15->addWidget(checkBox_Res_PlotLine_FixRange_S, 0, 6, 1, 1);

        label_13 = new QLabel(groupBox_Res_SpeedCustom);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy5.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy5);

        gridLayout_15->addWidget(label_13, 0, 1, 1, 1);

        label_Res_SpeedCustom_Stat_Uncertanty = new QLabel(groupBox_Res_SpeedCustom);
        label_Res_SpeedCustom_Stat_Uncertanty->setObjectName(QString::fromUtf8("label_Res_SpeedCustom_Stat_Uncertanty"));
        sizePolicy5.setHeightForWidth(label_Res_SpeedCustom_Stat_Uncertanty->sizePolicy().hasHeightForWidth());
        label_Res_SpeedCustom_Stat_Uncertanty->setSizePolicy(sizePolicy5);

        gridLayout_15->addWidget(label_Res_SpeedCustom_Stat_Uncertanty, 0, 3, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_SpeedCustom, 6, 0, 1, 2);

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
        comboBox_Res_VectorFieldParam_ShiftType = new QComboBox(groupBox_Res_VectorFieldParam);
        comboBox_Res_VectorFieldParam_ShiftType->addItem(QString());
        comboBox_Res_VectorFieldParam_ShiftType->addItem(QString());
        comboBox_Res_VectorFieldParam_ShiftType->setObjectName(QString::fromUtf8("comboBox_Res_VectorFieldParam_ShiftType"));
        sizePolicy6.setHeightForWidth(comboBox_Res_VectorFieldParam_ShiftType->sizePolicy().hasHeightForWidth());
        comboBox_Res_VectorFieldParam_ShiftType->setSizePolicy(sizePolicy6);
        comboBox_Res_VectorFieldParam_ShiftType->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(comboBox_Res_VectorFieldParam_ShiftType);

        label_5 = new QLabel(groupBox_Res_VectorFieldParam);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy5.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy5);

        horizontalLayout_2->addWidget(label_5);

        comboBox_Res_VectorFieldParam_Length_Value = new QComboBox(groupBox_Res_VectorFieldParam);
        comboBox_Res_VectorFieldParam_Length_Value->setObjectName(QString::fromUtf8("comboBox_Res_VectorFieldParam_Length_Value"));

        horizontalLayout_2->addWidget(comboBox_Res_VectorFieldParam_Length_Value);

        label_7 = new QLabel(groupBox_Res_VectorFieldParam);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy5.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy5);

        horizontalLayout_2->addWidget(label_7);

        comboBox_Res_VectorFieldParam_Length_Error = new QComboBox(groupBox_Res_VectorFieldParam);
        comboBox_Res_VectorFieldParam_Length_Error->setObjectName(QString::fromUtf8("comboBox_Res_VectorFieldParam_Length_Error"));

        horizontalLayout_2->addWidget(comboBox_Res_VectorFieldParam_Length_Error);

        line_13 = new QFrame(groupBox_Res_VectorFieldParam);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setFrameShape(QFrame::VLine);
        line_13->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_13);

        label_Res_VectorFieldParam_Angle = new QLabel(groupBox_Res_VectorFieldParam);
        label_Res_VectorFieldParam_Angle->setObjectName(QString::fromUtf8("label_Res_VectorFieldParam_Angle"));
        sizePolicy5.setHeightForWidth(label_Res_VectorFieldParam_Angle->sizePolicy().hasHeightForWidth());
        label_Res_VectorFieldParam_Angle->setSizePolicy(sizePolicy5);
        label_Res_VectorFieldParam_Angle->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(label_Res_VectorFieldParam_Angle);

        comboBox_Res_VectorFieldParam_Angle_Value = new QComboBox(groupBox_Res_VectorFieldParam);
        comboBox_Res_VectorFieldParam_Angle_Value->setObjectName(QString::fromUtf8("comboBox_Res_VectorFieldParam_Angle_Value"));

        horizontalLayout_2->addWidget(comboBox_Res_VectorFieldParam_Angle_Value);

        label_12 = new QLabel(groupBox_Res_VectorFieldParam);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy5.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy5);

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
        doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setMaximum(999.000000000000000);
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
        sizePolicy7.setHeightForWidth(spinBox_Res_VectorFieldParam_KindeySteps->sizePolicy().hasHeightForWidth());
        spinBox_Res_VectorFieldParam_KindeySteps->setSizePolicy(sizePolicy7);
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


        gridLayout_4->addWidget(groupBox_Res_VectorFieldParam, 9, 0, 1, 2);

        groupBox_Res_VortexCenter = new QGroupBox(groupBox_Res);
        groupBox_Res_VortexCenter->setObjectName(QString::fromUtf8("groupBox_Res_VortexCenter"));
        groupBox_Res_VortexCenter->setFlat(true);
        gridLayout_20 = new QGridLayout(groupBox_Res_VortexCenter);
        gridLayout_20->setSpacing(3);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        gridLayout_20->setContentsMargins(0, 3, 0, 3);
        line_9 = new QFrame(groupBox_Res_VortexCenter);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout_20->addWidget(line_9, 0, 2, 2, 1);

        gridLayout_25 = new QGridLayout();
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        doubleSpinBox_Res_VortexCenter_Ransac_pGoodGuess = new QDoubleSpinBox(groupBox_Res_VortexCenter);
        doubleSpinBox_Res_VortexCenter_Ransac_pGoodGuess->setObjectName(QString::fromUtf8("doubleSpinBox_Res_VortexCenter_Ransac_pGoodGuess"));
        doubleSpinBox_Res_VortexCenter_Ransac_pGoodGuess->setEnabled(false);
        doubleSpinBox_Res_VortexCenter_Ransac_pGoodGuess->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_VortexCenter_Ransac_pGoodGuess->setDecimals(2);
        doubleSpinBox_Res_VortexCenter_Ransac_pGoodGuess->setValue(90.000000000000000);

        gridLayout_25->addWidget(doubleSpinBox_Res_VortexCenter_Ransac_pGoodGuess, 1, 1, 1, 1);

        checkBox_Res_VortexCenter_Ransac = new QCheckBox(groupBox_Res_VortexCenter);
        checkBox_Res_VortexCenter_Ransac->setObjectName(QString::fromUtf8("checkBox_Res_VortexCenter_Ransac"));
        sizePolicy6.setHeightForWidth(checkBox_Res_VortexCenter_Ransac->sizePolicy().hasHeightForWidth());
        checkBox_Res_VortexCenter_Ransac->setSizePolicy(sizePolicy6);
        checkBox_Res_VortexCenter_Ransac->setChecked(true);

        gridLayout_25->addWidget(checkBox_Res_VortexCenter_Ransac, 0, 0, 1, 1);

        spinBox_Res_VortexCenter_RansacIterations = new QSpinBox(groupBox_Res_VortexCenter);
        spinBox_Res_VortexCenter_RansacIterations->setObjectName(QString::fromUtf8("spinBox_Res_VortexCenter_RansacIterations"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(spinBox_Res_VortexCenter_RansacIterations->sizePolicy().hasHeightForWidth());
        spinBox_Res_VortexCenter_RansacIterations->setSizePolicy(sizePolicy8);
        spinBox_Res_VortexCenter_RansacIterations->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_VortexCenter_RansacIterations->setMinimum(1);
        spinBox_Res_VortexCenter_RansacIterations->setMaximum(1000000);
        spinBox_Res_VortexCenter_RansacIterations->setValue(100000);

        gridLayout_25->addWidget(spinBox_Res_VortexCenter_RansacIterations, 1, 2, 1, 1);

        doubleSpinBox_Res_VortexCenter_Ransac_pOutliers = new QDoubleSpinBox(groupBox_Res_VortexCenter);
        doubleSpinBox_Res_VortexCenter_Ransac_pOutliers->setObjectName(QString::fromUtf8("doubleSpinBox_Res_VortexCenter_Ransac_pOutliers"));
        doubleSpinBox_Res_VortexCenter_Ransac_pOutliers->setEnabled(false);
        doubleSpinBox_Res_VortexCenter_Ransac_pOutliers->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_VortexCenter_Ransac_pOutliers->setDecimals(0);
        doubleSpinBox_Res_VortexCenter_Ransac_pOutliers->setValue(25.000000000000000);

        gridLayout_25->addWidget(doubleSpinBox_Res_VortexCenter_Ransac_pOutliers, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        doubleSpinBox_Res_VortexCenter_RansacSubsetSize = new QDoubleSpinBox(groupBox_Res_VortexCenter);
        doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setObjectName(QString::fromUtf8("doubleSpinBox_Res_VortexCenter_RansacSubsetSize"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_Res_VortexCenter_RansacSubsetSize->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setSizePolicy(sizePolicy6);
        doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setDecimals(0);
        doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setMaximum(100.000000000000000);
        doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setSingleStep(5.000000000000000);
        doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(50.000000000000000);

        horizontalLayout_5->addWidget(doubleSpinBox_Res_VortexCenter_RansacSubsetSize);

        comboBox_Res_VortexCenter_Ransac_PointsOrLines = new QComboBox(groupBox_Res_VortexCenter);
        comboBox_Res_VortexCenter_Ransac_PointsOrLines->addItem(QString());
        comboBox_Res_VortexCenter_Ransac_PointsOrLines->addItem(QString());
        comboBox_Res_VortexCenter_Ransac_PointsOrLines->setObjectName(QString::fromUtf8("comboBox_Res_VortexCenter_Ransac_PointsOrLines"));

        horizontalLayout_5->addWidget(comboBox_Res_VortexCenter_Ransac_PointsOrLines);


        gridLayout_25->addLayout(horizontalLayout_5, 0, 1, 1, 2);


        gridLayout_20->addLayout(gridLayout_25, 0, 7, 2, 1);

        line_5 = new QFrame(groupBox_Res_VortexCenter);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_20->addWidget(line_5, 0, 6, 2, 1);

        gridLayout_21 = new QGridLayout();
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        checkBox_Res_VortexCenter_MovingAverage = new QCheckBox(groupBox_Res_VortexCenter);
        checkBox_Res_VortexCenter_MovingAverage->setObjectName(QString::fromUtf8("checkBox_Res_VortexCenter_MovingAverage"));
        checkBox_Res_VortexCenter_MovingAverage->setTristate(true);

        gridLayout_21->addWidget(checkBox_Res_VortexCenter_MovingAverage, 0, 0, 1, 1);

        spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm = new QSpinBox(groupBox_Res_VortexCenter);
        spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm->setObjectName(QString::fromUtf8("spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm"));
        spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm->setMinimum(1);
        spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm->setMaximum(9999);
        spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm->setValue(439);

        gridLayout_21->addWidget(spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm, 1, 0, 1, 1);

        doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec = new QDoubleSpinBox(groupBox_Res_VortexCenter);
        doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec->setObjectName(QString::fromUtf8("doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec"));
        doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec->setMaximum(100.000000000000000);
        doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec->setValue(10.000000000000000);

        gridLayout_21->addWidget(doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec, 2, 0, 1, 1);


        gridLayout_20->addLayout(gridLayout_21, 0, 9, 2, 1);

        line_12 = new QFrame(groupBox_Res_VortexCenter);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setFrameShape(QFrame::VLine);
        line_12->setFrameShadow(QFrame::Sunken);

        gridLayout_20->addWidget(line_12, 0, 4, 2, 1);

        line_10 = new QFrame(groupBox_Res_VortexCenter);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        gridLayout_20->addWidget(line_10, 0, 8, 2, 1);

        gridLayout_34 = new QGridLayout();
        gridLayout_34->setObjectName(QString::fromUtf8("gridLayout_34"));
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set1 = new QDoubleSpinBox(groupBox_Res_VortexCenter);
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set1->setObjectName(QString::fromUtf8("doubleSpinBox_Res_VortexCenter_RelPos_H_Set1"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_Res_VortexCenter_RelPos_H_Set1->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set1->setSizePolicy(sizePolicy6);
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set1->setMinimumSize(QSize(50, 15));
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set1->setMaximumSize(QSize(50, 15));
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set1->setDecimals(0);
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set1->setValue(25.000000000000000);

        gridLayout_34->addWidget(doubleSpinBox_Res_VortexCenter_RelPos_H_Set1, 1, 0, 1, 1);

        lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set1 = new QLineEdit(groupBox_Res_VortexCenter);
        lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set1->setObjectName(QString::fromUtf8("lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set1"));
        sizePolicy6.setHeightForWidth(lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set1->sizePolicy().hasHeightForWidth());
        lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set1->setSizePolicy(sizePolicy6);
        lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set1->setMinimumSize(QSize(0, 15));
        lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set1->setMaximumSize(QSize(50, 15));

        gridLayout_34->addWidget(lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set1, 1, 2, 1, 1);

        label_23 = new QLabel(groupBox_Res_VortexCenter);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        sizePolicy5.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy5);
        label_23->setMinimumSize(QSize(50, 0));
        label_23->setMaximumSize(QSize(50, 16777215));

        gridLayout_34->addWidget(label_23, 1, 1, 1, 1);

        label_21 = new QLabel(groupBox_Res_VortexCenter);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy5.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy5);
        label_21->setMinimumSize(QSize(0, 15));
        label_21->setMaximumSize(QSize(16777215, 15));

        gridLayout_34->addWidget(label_21, 0, 0, 1, 2);

        doubleSpinBox_Res_VortexCenter_RelPos_H_Use = new QDoubleSpinBox(groupBox_Res_VortexCenter);
        doubleSpinBox_Res_VortexCenter_RelPos_H_Use->setObjectName(QString::fromUtf8("doubleSpinBox_Res_VortexCenter_RelPos_H_Use"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_Res_VortexCenter_RelPos_H_Use->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_VortexCenter_RelPos_H_Use->setSizePolicy(sizePolicy6);
        doubleSpinBox_Res_VortexCenter_RelPos_H_Use->setMinimumSize(QSize(50, 15));
        doubleSpinBox_Res_VortexCenter_RelPos_H_Use->setMaximumSize(QSize(50, 15));
        doubleSpinBox_Res_VortexCenter_RelPos_H_Use->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_VortexCenter_RelPos_H_Use->setDecimals(0);
        doubleSpinBox_Res_VortexCenter_RelPos_H_Use->setMaximum(100.000000000000000);
        doubleSpinBox_Res_VortexCenter_RelPos_H_Use->setValue(50.000000000000000);

        gridLayout_34->addWidget(doubleSpinBox_Res_VortexCenter_RelPos_H_Use, 0, 2, 1, 1);

        lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set2 = new QLineEdit(groupBox_Res_VortexCenter);
        lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set2->setObjectName(QString::fromUtf8("lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set2"));
        sizePolicy6.setHeightForWidth(lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set2->sizePolicy().hasHeightForWidth());
        lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set2->setSizePolicy(sizePolicy6);
        lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set2->setMinimumSize(QSize(0, 15));
        lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set2->setMaximumSize(QSize(50, 15));

        gridLayout_34->addWidget(lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set2, 2, 2, 1, 1);

        label_24 = new QLabel(groupBox_Res_VortexCenter);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        sizePolicy5.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy5);
        label_24->setMinimumSize(QSize(50, 0));
        label_24->setMaximumSize(QSize(50, 16777215));

        gridLayout_34->addWidget(label_24, 2, 1, 1, 1);

        doubleSpinBox_Res_VortexCenter_RelPos_H_Set2 = new QDoubleSpinBox(groupBox_Res_VortexCenter);
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set2->setObjectName(QString::fromUtf8("doubleSpinBox_Res_VortexCenter_RelPos_H_Set2"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_Res_VortexCenter_RelPos_H_Set2->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set2->setSizePolicy(sizePolicy6);
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set2->setMinimumSize(QSize(50, 15));
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set2->setMaximumSize(QSize(50, 15));
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set2->setDecimals(0);
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set2->setValue(75.000000000000000);

        gridLayout_34->addWidget(doubleSpinBox_Res_VortexCenter_RelPos_H_Set2, 2, 0, 1, 1);

        label_6 = new QLabel(groupBox_Res_VortexCenter);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy5.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy5);
        label_6->setMinimumSize(QSize(50, 15));
        label_6->setMaximumSize(QSize(50, 15));

        gridLayout_34->addWidget(label_6, 3, 0, 1, 1);

        label_18 = new QLabel(groupBox_Res_VortexCenter);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy5.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy5);
        label_18->setMinimumSize(QSize(50, 15));
        label_18->setMaximumSize(QSize(50, 15));

        gridLayout_34->addWidget(label_18, 3, 1, 1, 1);

        label_19 = new QLabel(groupBox_Res_VortexCenter);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy5.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy5);
        label_19->setMinimumSize(QSize(50, 15));
        label_19->setMaximumSize(QSize(50, 15));

        gridLayout_34->addWidget(label_19, 3, 2, 1, 1);


        gridLayout_20->addLayout(gridLayout_34, 0, 5, 2, 1);

        gridLayout_36 = new QGridLayout();
        gridLayout_36->setObjectName(QString::fromUtf8("gridLayout_36"));
        label_17 = new QLabel(groupBox_Res_VortexCenter);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy5.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy5);
        label_17->setMinimumSize(QSize(0, 20));
        label_17->setMaximumSize(QSize(16777215, 20));

        gridLayout_36->addWidget(label_17, 0, 0, 1, 1);

        doubleSpinBox_Res_VortexCenter_WellDiameter = new QDoubleSpinBox(groupBox_Res_VortexCenter);
        doubleSpinBox_Res_VortexCenter_WellDiameter->setObjectName(QString::fromUtf8("doubleSpinBox_Res_VortexCenter_WellDiameter"));
        QSizePolicy sizePolicy9(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(doubleSpinBox_Res_VortexCenter_WellDiameter->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_VortexCenter_WellDiameter->setSizePolicy(sizePolicy9);
        doubleSpinBox_Res_VortexCenter_WellDiameter->setMinimumSize(QSize(0, 20));
        doubleSpinBox_Res_VortexCenter_WellDiameter->setMaximumSize(QSize(16777215, 20));
        doubleSpinBox_Res_VortexCenter_WellDiameter->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_VortexCenter_WellDiameter->setProperty("showGroupSeparator", QVariant(false));
        doubleSpinBox_Res_VortexCenter_WellDiameter->setDecimals(0);
        doubleSpinBox_Res_VortexCenter_WellDiameter->setMinimum(1000.000000000000000);
        doubleSpinBox_Res_VortexCenter_WellDiameter->setMaximum(1000000.000000000000000);
        doubleSpinBox_Res_VortexCenter_WellDiameter->setSingleStep(1000.000000000000000);
        doubleSpinBox_Res_VortexCenter_WellDiameter->setValue(12000.000000000000000);

        gridLayout_36->addWidget(doubleSpinBox_Res_VortexCenter_WellDiameter, 1, 0, 1, 1);


        gridLayout_20->addLayout(gridLayout_36, 0, 3, 2, 1);

        gridLayout_35 = new QGridLayout();
        gridLayout_35->setObjectName(QString::fromUtf8("gridLayout_35"));
        spinBox_Res_VortexCenter_Thickness = new QSpinBox(groupBox_Res_VortexCenter);
        spinBox_Res_VortexCenter_Thickness->setObjectName(QString::fromUtf8("spinBox_Res_VortexCenter_Thickness"));
        spinBox_Res_VortexCenter_Thickness->setMinimumSize(QSize(0, 20));
        spinBox_Res_VortexCenter_Thickness->setMaximumSize(QSize(16777215, 20));
        spinBox_Res_VortexCenter_Thickness->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_VortexCenter_Thickness->setMinimum(2);
        spinBox_Res_VortexCenter_Thickness->setValue(5);

        gridLayout_35->addWidget(spinBox_Res_VortexCenter_Thickness, 0, 0, 1, 1);

        doubleSpinBox_Res_VortexCenter_Resolution_Rel = new QDoubleSpinBox(groupBox_Res_VortexCenter);
        doubleSpinBox_Res_VortexCenter_Resolution_Rel->setObjectName(QString::fromUtf8("doubleSpinBox_Res_VortexCenter_Resolution_Rel"));
        doubleSpinBox_Res_VortexCenter_Resolution_Rel->setMinimumSize(QSize(0, 20));
        doubleSpinBox_Res_VortexCenter_Resolution_Rel->setMaximumSize(QSize(16777215, 20));
        doubleSpinBox_Res_VortexCenter_Resolution_Rel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_VortexCenter_Resolution_Rel->setDecimals(0);
        doubleSpinBox_Res_VortexCenter_Resolution_Rel->setMinimum(5.000000000000000);
        doubleSpinBox_Res_VortexCenter_Resolution_Rel->setSingleStep(5.000000000000000);
        doubleSpinBox_Res_VortexCenter_Resolution_Rel->setValue(25.000000000000000);

        gridLayout_35->addWidget(doubleSpinBox_Res_VortexCenter_Resolution_Rel, 1, 0, 1, 1);


        gridLayout_20->addLayout(gridLayout_35, 0, 1, 2, 1);


        gridLayout_4->addWidget(groupBox_Res_VortexCenter, 2, 0, 1, 2);

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
        QSizePolicy sizePolicy10(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(spinBox_Res_MovAv_CurrentFrame->sizePolicy().hasHeightForWidth());
        spinBox_Res_MovAv_CurrentFrame->setSizePolicy(sizePolicy10);
        spinBox_Res_MovAv_CurrentFrame->setMinimumSize(QSize(130, 30));
        spinBox_Res_MovAv_CurrentFrame->setMaximumSize(QSize(130, 30));
        spinBox_Res_MovAv_CurrentFrame->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_MovAv_CurrentFrame->setMaximum(480);

        gridLayout_18->addWidget(spinBox_Res_MovAv_CurrentFrame, 0, 1, 2, 1);

        doubleSpinBox_Res_MovAv_CurrentTime = new QDoubleSpinBox(groupBox_Res_MovAv);
        doubleSpinBox_Res_MovAv_CurrentTime->setObjectName(QString::fromUtf8("doubleSpinBox_Res_MovAv_CurrentTime"));
        sizePolicy10.setHeightForWidth(doubleSpinBox_Res_MovAv_CurrentTime->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_MovAv_CurrentTime->setSizePolicy(sizePolicy10);
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
        sizePolicy7.setHeightForWidth(comboBox_Res_MovAv_TimeWindow->sizePolicy().hasHeightForWidth());
        comboBox_Res_MovAv_TimeWindow->setSizePolicy(sizePolicy7);
        comboBox_Res_MovAv_TimeWindow->setMinimumSize(QSize(105, 0));

        horizontalLayout->addWidget(comboBox_Res_MovAv_TimeWindow);

        comboBox_Res_MovAv_Background = new QComboBox(groupBox_Res_MovAv);
        comboBox_Res_MovAv_Background->addItem(QString());
        comboBox_Res_MovAv_Background->addItem(QString());
        comboBox_Res_MovAv_Background->setObjectName(QString::fromUtf8("comboBox_Res_MovAv_Background"));
        sizePolicy7.setHeightForWidth(comboBox_Res_MovAv_Background->sizePolicy().hasHeightForWidth());
        comboBox_Res_MovAv_Background->setSizePolicy(sizePolicy7);
        comboBox_Res_MovAv_Background->setMinimumSize(QSize(105, 0));

        horizontalLayout->addWidget(comboBox_Res_MovAv_Background);

        doubleSpinBox_Res_MovAv_ReqFrmWithDetect = new QDoubleSpinBox(groupBox_Res_MovAv);
        doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setObjectName(QString::fromUtf8("doubleSpinBox_Res_MovAv_ReqFrmWithDetect"));
        sizePolicy7.setHeightForWidth(doubleSpinBox_Res_MovAv_ReqFrmWithDetect->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setSizePolicy(sizePolicy7);
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
        QSizePolicy sizePolicy11(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(spinBox_Res_MovAv_WindowFrames->sizePolicy().hasHeightForWidth());
        spinBox_Res_MovAv_WindowFrames->setSizePolicy(sizePolicy11);
        spinBox_Res_MovAv_WindowFrames->setMinimumSize(QSize(130, 0));
        spinBox_Res_MovAv_WindowFrames->setMaximumSize(QSize(130, 40));
        spinBox_Res_MovAv_WindowFrames->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_MovAv_WindowFrames->setMinimum(1);
        spinBox_Res_MovAv_WindowFrames->setMaximum(480);
        spinBox_Res_MovAv_WindowFrames->setValue(12);

        horizontalLayout->addWidget(spinBox_Res_MovAv_WindowFrames);

        doubleSpinBox_Res_MovAv_WindowTime = new QDoubleSpinBox(groupBox_Res_MovAv);
        doubleSpinBox_Res_MovAv_WindowTime->setObjectName(QString::fromUtf8("doubleSpinBox_Res_MovAv_WindowTime"));
        sizePolicy11.setHeightForWidth(doubleSpinBox_Res_MovAv_WindowTime->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_MovAv_WindowTime->setSizePolicy(sizePolicy11);
        doubleSpinBox_Res_MovAv_WindowTime->setMinimumSize(QSize(130, 0));
        doubleSpinBox_Res_MovAv_WindowTime->setMaximumSize(QSize(130, 40));
        doubleSpinBox_Res_MovAv_WindowTime->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_MovAv_WindowTime->setMinimum(0.420000000000000);
        doubleSpinBox_Res_MovAv_WindowTime->setMaximum(480.000000000000000);
        doubleSpinBox_Res_MovAv_WindowTime->setValue(0.500000000000000);

        horizontalLayout->addWidget(doubleSpinBox_Res_MovAv_WindowTime);


        gridLayout_17->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_MovAv, 10, 0, 1, 2);

        comboBox_Res_Type = new QComboBox(groupBox_Res);
        comboBox_Res_Type->setObjectName(QString::fromUtf8("comboBox_Res_Type"));

        gridLayout_4->addWidget(comboBox_Res_Type, 0, 0, 1, 2);

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
        sizePolicy6.setHeightForWidth(spinBox_ParamGrid_CellEnd->sizePolicy().hasHeightForWidth());
        spinBox_ParamGrid_CellEnd->setSizePolicy(sizePolicy6);
        spinBox_ParamGrid_CellEnd->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ParamGrid_CellEnd->setMinimum(1);
        spinBox_ParamGrid_CellEnd->setMaximum(20);
        spinBox_ParamGrid_CellEnd->setValue(20);

        gridLayout_8->addWidget(spinBox_ParamGrid_CellEnd, 0, 3, 1, 1);

        spinBox_ParamGrid_CellStart = new QSpinBox(groupBox_Res_GridSamplingParam);
        spinBox_ParamGrid_CellStart->setObjectName(QString::fromUtf8("spinBox_ParamGrid_CellStart"));
        sizePolicy6.setHeightForWidth(spinBox_ParamGrid_CellStart->sizePolicy().hasHeightForWidth());
        spinBox_ParamGrid_CellStart->setSizePolicy(sizePolicy6);
        spinBox_ParamGrid_CellStart->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ParamGrid_CellStart->setMaximum(19);

        gridLayout_8->addWidget(spinBox_ParamGrid_CellStart, 0, 2, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_GridSamplingParam, 12, 0, 1, 2);

        groupBox_Res_Histo = new QGroupBox(groupBox_Res);
        groupBox_Res_Histo->setObjectName(QString::fromUtf8("groupBox_Res_Histo"));
        groupBox_Res_Histo->setFlat(true);
        gridLayout_22 = new QGridLayout(groupBox_Res_Histo);
        gridLayout_22->setSpacing(3);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        gridLayout_22->setContentsMargins(0, 3, 0, 3);
        checkBox_Res_Histo_Uni = new QCheckBox(groupBox_Res_Histo);
        checkBox_Res_Histo_Uni->setObjectName(QString::fromUtf8("checkBox_Res_Histo_Uni"));
        sizePolicy6.setHeightForWidth(checkBox_Res_Histo_Uni->sizePolicy().hasHeightForWidth());
        checkBox_Res_Histo_Uni->setSizePolicy(sizePolicy6);
        checkBox_Res_Histo_Uni->setChecked(true);
        checkBox_Res_Histo_Uni->setTristate(false);

        gridLayout_22->addWidget(checkBox_Res_Histo_Uni, 0, 4, 1, 1);

        stackedWidget_HistClasses = new QStackedWidget(groupBox_Res_Histo);
        stackedWidget_HistClasses->setObjectName(QString::fromUtf8("stackedWidget_HistClasses"));
        sizePolicy5.setHeightForWidth(stackedWidget_HistClasses->sizePolicy().hasHeightForWidth());
        stackedWidget_HistClasses->setSizePolicy(sizePolicy5);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        gridLayout_29 = new QGridLayout(page_4);
        gridLayout_29->setSpacing(0);
        gridLayout_29->setObjectName(QString::fromUtf8("gridLayout_29"));
        gridLayout_29->setContentsMargins(0, 0, 0, 0);
        spinBox_Res_Histo_Classes_Speed = new QSpinBox(page_4);
        spinBox_Res_Histo_Classes_Speed->setObjectName(QString::fromUtf8("spinBox_Res_Histo_Classes_Speed"));
        sizePolicy6.setHeightForWidth(spinBox_Res_Histo_Classes_Speed->sizePolicy().hasHeightForWidth());
        spinBox_Res_Histo_Classes_Speed->setSizePolicy(sizePolicy6);
        spinBox_Res_Histo_Classes_Speed->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_Histo_Classes_Speed->setMinimum(5);
        spinBox_Res_Histo_Classes_Speed->setMaximum(1000);
        spinBox_Res_Histo_Classes_Speed->setSingleStep(10);
        spinBox_Res_Histo_Classes_Speed->setValue(500);

        gridLayout_29->addWidget(spinBox_Res_Histo_Classes_Speed, 0, 0, 1, 1);

        stackedWidget_HistClasses->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        gridLayout_31 = new QGridLayout(page_5);
        gridLayout_31->setSpacing(0);
        gridLayout_31->setObjectName(QString::fromUtf8("gridLayout_31"));
        gridLayout_31->setContentsMargins(0, 0, 0, 0);
        spinBox_Res_Histo_Classes_Dist = new QSpinBox(page_5);
        spinBox_Res_Histo_Classes_Dist->setObjectName(QString::fromUtf8("spinBox_Res_Histo_Classes_Dist"));
        sizePolicy6.setHeightForWidth(spinBox_Res_Histo_Classes_Dist->sizePolicy().hasHeightForWidth());
        spinBox_Res_Histo_Classes_Dist->setSizePolicy(sizePolicy6);
        spinBox_Res_Histo_Classes_Dist->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Res_Histo_Classes_Dist->setMinimum(5);
        spinBox_Res_Histo_Classes_Dist->setMaximum(1000);
        spinBox_Res_Histo_Classes_Dist->setSingleStep(10);
        spinBox_Res_Histo_Classes_Dist->setValue(50);

        gridLayout_31->addWidget(spinBox_Res_Histo_Classes_Dist, 0, 0, 1, 1);

        stackedWidget_HistClasses->addWidget(page_5);

        gridLayout_22->addWidget(stackedWidget_HistClasses, 0, 1, 1, 1);

        stackedWidget_Res_Histo_Type = new QStackedWidget(groupBox_Res_Histo);
        stackedWidget_Res_Histo_Type->setObjectName(QString::fromUtf8("stackedWidget_Res_Histo_Type"));
        QSizePolicy sizePolicy12(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(stackedWidget_Res_Histo_Type->sizePolicy().hasHeightForWidth());
        stackedWidget_Res_Histo_Type->setSizePolicy(sizePolicy12);
        stackedWidget_Res_Histo_Type->setMinimumSize(QSize(200, 0));
        stackedWidget_Res_Histo_Type->setMaximumSize(QSize(200, 16777215));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_26 = new QGridLayout(page);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        gridLayout_26->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_Res_Histo_MaxSpeedLinear = new QDoubleSpinBox(page);
        doubleSpinBox_Res_Histo_MaxSpeedLinear->setObjectName(QString::fromUtf8("doubleSpinBox_Res_Histo_MaxSpeedLinear"));
        sizePolicy7.setHeightForWidth(doubleSpinBox_Res_Histo_MaxSpeedLinear->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_Histo_MaxSpeedLinear->setSizePolicy(sizePolicy7);
        doubleSpinBox_Res_Histo_MaxSpeedLinear->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_Histo_MaxSpeedLinear->setDecimals(0);
        doubleSpinBox_Res_Histo_MaxSpeedLinear->setMinimum(1.000000000000000);
        doubleSpinBox_Res_Histo_MaxSpeedLinear->setMaximum(500.000000000000000);
        doubleSpinBox_Res_Histo_MaxSpeedLinear->setSingleStep(10.000000000000000);
        doubleSpinBox_Res_Histo_MaxSpeedLinear->setValue(180.000000000000000);

        gridLayout_26->addWidget(doubleSpinBox_Res_Histo_MaxSpeedLinear, 0, 0, 1, 1);

        stackedWidget_Res_Histo_Type->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_27 = new QGridLayout(page_3);
        gridLayout_27->setSpacing(0);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        gridLayout_27->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_Res_Histo_MaxSpeedAngular = new QDoubleSpinBox(page_3);
        doubleSpinBox_Res_Histo_MaxSpeedAngular->setObjectName(QString::fromUtf8("doubleSpinBox_Res_Histo_MaxSpeedAngular"));
        sizePolicy7.setHeightForWidth(doubleSpinBox_Res_Histo_MaxSpeedAngular->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_Histo_MaxSpeedAngular->setSizePolicy(sizePolicy7);
        doubleSpinBox_Res_Histo_MaxSpeedAngular->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_Histo_MaxSpeedAngular->setDecimals(2);
        doubleSpinBox_Res_Histo_MaxSpeedAngular->setMinimum(0.010000000000000);
        doubleSpinBox_Res_Histo_MaxSpeedAngular->setMaximum(1.000000000000000);
        doubleSpinBox_Res_Histo_MaxSpeedAngular->setSingleStep(0.001000000000000);
        doubleSpinBox_Res_Histo_MaxSpeedAngular->setValue(0.200000000000000);

        gridLayout_27->addWidget(doubleSpinBox_Res_Histo_MaxSpeedAngular, 0, 0, 1, 1);

        stackedWidget_Res_Histo_Type->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_28 = new QGridLayout(page_2);
        gridLayout_28->setSpacing(0);
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        gridLayout_28->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_Res_Histo_MaxDistCenterIntersections = new QDoubleSpinBox(page_2);
        doubleSpinBox_Res_Histo_MaxDistCenterIntersections->setObjectName(QString::fromUtf8("doubleSpinBox_Res_Histo_MaxDistCenterIntersections"));
        sizePolicy7.setHeightForWidth(doubleSpinBox_Res_Histo_MaxDistCenterIntersections->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Res_Histo_MaxDistCenterIntersections->setSizePolicy(sizePolicy7);
        doubleSpinBox_Res_Histo_MaxDistCenterIntersections->setReadOnly(false);
        doubleSpinBox_Res_Histo_MaxDistCenterIntersections->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Res_Histo_MaxDistCenterIntersections->setDecimals(0);
        doubleSpinBox_Res_Histo_MaxDistCenterIntersections->setMinimum(500.000000000000000);
        doubleSpinBox_Res_Histo_MaxDistCenterIntersections->setMaximum(100000.000000000000000);
        doubleSpinBox_Res_Histo_MaxDistCenterIntersections->setSingleStep(1000.000000000000000);
        doubleSpinBox_Res_Histo_MaxDistCenterIntersections->setValue(6000.000000000000000);

        gridLayout_28->addWidget(doubleSpinBox_Res_Histo_MaxDistCenterIntersections, 0, 0, 1, 1);

        stackedWidget_Res_Histo_Type->addWidget(page_2);

        gridLayout_22->addWidget(stackedWidget_Res_Histo_Type, 0, 2, 1, 1);

        checkBox_Res_Histo_Acc = new QCheckBox(groupBox_Res_Histo);
        checkBox_Res_Histo_Acc->setObjectName(QString::fromUtf8("checkBox_Res_Histo_Acc"));
        sizePolicy6.setHeightForWidth(checkBox_Res_Histo_Acc->sizePolicy().hasHeightForWidth());
        checkBox_Res_Histo_Acc->setSizePolicy(sizePolicy6);

        gridLayout_22->addWidget(checkBox_Res_Histo_Acc, 0, 5, 1, 1);

        comboBox_Res_Histo_Type = new QComboBox(groupBox_Res_Histo);
        comboBox_Res_Histo_Type->addItem(QString());
        comboBox_Res_Histo_Type->addItem(QString());
        comboBox_Res_Histo_Type->addItem(QString());
        comboBox_Res_Histo_Type->setObjectName(QString::fromUtf8("comboBox_Res_Histo_Type"));

        gridLayout_22->addWidget(comboBox_Res_Histo_Type, 0, 0, 1, 1);

        checkBox_Res_Histo_VariationAsColorValue = new QCheckBox(groupBox_Res_Histo);
        checkBox_Res_Histo_VariationAsColorValue->setObjectName(QString::fromUtf8("checkBox_Res_Histo_VariationAsColorValue"));
        sizePolicy6.setHeightForWidth(checkBox_Res_Histo_VariationAsColorValue->sizePolicy().hasHeightForWidth());
        checkBox_Res_Histo_VariationAsColorValue->setSizePolicy(sizePolicy6);
        checkBox_Res_Histo_VariationAsColorValue->setChecked(true);

        gridLayout_22->addWidget(checkBox_Res_Histo_VariationAsColorValue, 0, 3, 1, 1);


        gridLayout_4->addWidget(groupBox_Res_Histo, 3, 0, 1, 2);


        gridLayout->addWidget(groupBox_Res, 1, 1, 3, 1);

        D_MAKRO_CiliaSphereTracker->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_CiliaSphereTracker);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1247, 21));
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
        menuAnalysis->addAction(action_Save_vectorfield_videos_on_analysis);

        retranslateUi(D_MAKRO_CiliaSphereTracker);
        QObject::connect(action_Show_Normal, SIGNAL(triggered()), D_MAKRO_CiliaSphereTracker, SLOT(showNormal()));
        QObject::connect(action_Show_Minimum, SIGNAL(triggered()), D_MAKRO_CiliaSphereTracker, SLOT(showMinimized()));
        QObject::connect(action_Show_Maximum, SIGNAL(triggered()), D_MAKRO_CiliaSphereTracker, SLOT(showMaximized()));
        QObject::connect(action_Show_Fullscreen, SIGNAL(triggered()), D_MAKRO_CiliaSphereTracker, SLOT(showFullScreen()));
        QObject::connect(comboBox_Res_Histo_Type, SIGNAL(currentIndexChanged(int)), stackedWidget_Res_Histo_Type, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_Res_SpeedCustom_ShiftType, SIGNAL(currentIndexChanged(int)), stackedWidget_Res_SpeedCustom_ShiftType_SpeedRange, SLOT(setCurrentIndex(int)));

        tabWidget_ResType->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(D_MAKRO_CiliaSphereTracker);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_CiliaSphereTracker)
    {
        D_MAKRO_CiliaSphereTracker->setWindowTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "MainWindow", nullptr));
        action_Data_Add->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Add", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Data_Add->setShortcut(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        action_Data_Clear->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Clear", nullptr));
        action_Show_Minimum->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Minimum", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Minimum->setShortcut(QApplication::translate("D_MAKRO_CiliaSphereTracker", "F9", nullptr));
#endif // QT_NO_SHORTCUT
        action_Show_Normal->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Normal", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Normal->setShortcut(QApplication::translate("D_MAKRO_CiliaSphereTracker", "F10", nullptr));
#endif // QT_NO_SHORTCUT
        action_Show_Maximum->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Maximum", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Maximum->setShortcut(QApplication::translate("D_MAKRO_CiliaSphereTracker", "F11", nullptr));
#endif // QT_NO_SHORTCUT
        action_Show_Fullscreen->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Fullscreen", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Fullscreen->setShortcut(QApplication::translate("D_MAKRO_CiliaSphereTracker", "F12", nullptr));
#endif // QT_NO_SHORTCUT
        action_Save_Analysis_All->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Save Analysis of all Videos", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Save_Analysis_All->setShortcut(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Ctrl+F5", nullptr));
#endif // QT_NO_SHORTCUT
        action_Save_vectorfield_videos_on_analysis->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Save vectorfield videos on analysis", nullptr));
#ifndef QT_NO_TOOLTIP
        action_Save_vectorfield_videos_on_analysis->setToolTip(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Save vectorfield videos on analysis", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox_Data->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Data", nullptr));
        pushButton_Data_Add->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Add", nullptr));
        pushButton_Data_Clear->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Clear", nullptr));
        groupBox_Param->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Parameters", nullptr));
        doubleSpinBox_Param_Blur_Sigma->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "sigma: ", nullptr));
        spinBox_Param_FrameCountSmooth->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " frames", nullptr));
        spinBox_Param_FrameCountSmooth->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Measure between: ", nullptr));
        doubleSpinBox_Param_Crop_Start->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "start: ", nullptr));
        doubleSpinBox_Param_Crop_Start->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "s", nullptr));
        doubleSpinBox_Param_Scale_mm->setPrefix(QString());
        doubleSpinBox_Param_Scale_mm->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "mm", nullptr));
        spinBox_Param_Crop_Left->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Param_Crop_Left->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "left: ", nullptr));
        label->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Scale", nullptr));
        label_Param_CropHeight->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Crop Height", nullptr));
        label_9->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Blur", nullptr));
        spinBox_Param_Crop_Bottom->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Param_Crop_Bottom->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "bottom: ", nullptr));
        spinBox_Param_Crop_Top->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " px", nullptr));
        spinBox_Param_Crop_Top->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "top: ", nullptr));
        label_3->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Crop", nullptr));
        spinBox_Param_Blur_Size->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Param_Blur_Size->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "size: ", nullptr));
        label_2->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Image Pixels <-> World mm", nullptr));
        label_Param_CropTime->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Crop Time", nullptr));
        label_8->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Smooth", nullptr));
        spinBox_Param_Crop_Right->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Param_Crop_Right->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "right: ", nullptr));
        label_10->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Remove Noise", nullptr));
        label_Param_CropWidth->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Crop Width", nullptr));
        doubleSpinBox_Param_Crop_End->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "end: ", nullptr));
        doubleSpinBox_Param_Crop_End->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "s", nullptr));
        label_11->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Maximum Speed", nullptr));
        label_4->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Tracking", nullptr));
        doubleSpinBox_Param_MaxSpeed->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Maximum speed: ", nullptr));
        doubleSpinBox_Param_MaxSpeed->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "px/frame", nullptr));
        doubleSpinBox_Param_Scale_Px->setPrefix(QString());
        doubleSpinBox_Param_Scale_Px->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        groupBox_Proc->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Frame Processing", nullptr));
        spinBox_Proc_Frame->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " / 480", nullptr));
        spinBox_Proc_Frame->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "frame: ", nullptr));
        pushButton_Proc_FullVideo->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Process Full Video", nullptr));
        doubleSpinBox_Proc_Time->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "second: ", nullptr));
        doubleSpinBox_Proc_Time->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " / 20,00", nullptr));
        groupBox_Res->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Results", nullptr));
        groupBox_Res_TimeAxis->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Time axis", nullptr));
        doubleSpinBox_Res_PlotLine_FixRange_T_max->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "s", nullptr));
        label_16->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Time shift poincare plots:", nullptr));
        label_15->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Plot range linear plot:", nullptr));
        spinBox_Res_PlotPoincare_Shift_Frames->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " frames", nullptr));
        doubleSpinBox_Res_PlotLine_FixRange_T_min->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "s", nullptr));
        doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " seconds", nullptr));
        groupBox_Res_GraphicsParam->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Graphics", nullptr));
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "> ", nullptr));
        doubleSpinBox_Res_TimeProjSum_ColorHigh->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "% (red)", nullptr));
        checkBox_Res_TimeProjSum_ColorLow->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Color Low", nullptr));
        checkBox_Res_TimeProjSum_Gamma->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Gamma Correct", nullptr));
        checkBox_Res_TimeProjSum_ColorHigh->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Color High", nullptr));
        doubleSpinBox_Res_TimeProjSum_ColorLow->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "<= ", nullptr));
        doubleSpinBox_Res_TimeProjSum_ColorLow->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "% (black)", nullptr));
        comboBox->setItemText(0, QApplication::translate("D_MAKRO_CiliaSphereTracker", "of value range", nullptr));
        comboBox->setItemText(1, QApplication::translate("D_MAKRO_CiliaSphereTracker", "of nonzero px", nullptr));

        groupBox_Res_Heat->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Heatmap", nullptr));
        tabWidget_ResType->setTabText(tabWidget_ResType->indexOf(tab_ResPlotLine), QApplication::translate("D_MAKRO_CiliaSphereTracker", "Line", nullptr));
        tabWidget_ResType->setTabText(tabWidget_ResType->indexOf(tab_ResPlotPoincare), QApplication::translate("D_MAKRO_CiliaSphereTracker", "Poincare", nullptr));
        tabWidget_ResType->setTabText(tabWidget_ResType->indexOf(tab_ResTable), QApplication::translate("D_MAKRO_CiliaSphereTracker", "Table", nullptr));
        groupBox_Res_AngleCustom->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Angle analysis", nullptr));
        label_Res_AngleCustom_Stat_Uncertanty->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "\302\261", nullptr));
        doubleSpinBox_Res_PlotLine_FixRange_A_max->setSuffix(QString());
        label_14->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Stat", nullptr));
        checkBox_Res_PlotLine_FixRange_A->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Fix plot range", nullptr));
        doubleSpinBox_Res_PlotLine_FixRange_A_min->setSuffix(QString());
        groupBox_Res_GridVisParam->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Grid visualization", nullptr));
        doubleSpinBox_Res_GridVisParam_Label_Scaling->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "scale: ", nullptr));
        doubleSpinBox_Res_GridVisParam_Label_Scaling->setSuffix(QString());
        checkBox_Res_GridVisParam_Grid->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Grid", nullptr));
        spinBox_Res_GridVisParam_Thickness_Grid->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Res_GridVisParam_Thickness_Grid->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "grid thickness: ", nullptr));
        checkBox_Res_GridVisParam_Labels->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Labels", nullptr));
        spinBox_Res_GridVisParam_Thickness_Label->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Res_GridVisParam_Thickness_Label->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "label thickness: ", nullptr));
        groupBox_Res_SpeedCustom->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Speed analysis", nullptr));
        doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " um/s", nullptr));
        doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " um/s", nullptr));
        doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " \302\260/s", nullptr));
        doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " \302\260/s", nullptr));
        comboBox_Res_SpeedCustom_ShiftType->setItemText(0, QApplication::translate("D_MAKRO_CiliaSphereTracker", "Linear Speed", nullptr));
        comboBox_Res_SpeedCustom_ShiftType->setItemText(1, QApplication::translate("D_MAKRO_CiliaSphereTracker", "Angular Speed", nullptr));

        checkBox_Res_PlotLine_FixRange_S->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Fix plot range", nullptr));
        label_13->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Stat", nullptr));
        label_Res_SpeedCustom_Stat_Uncertanty->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "\302\261", nullptr));
        groupBox_Res_VectorFieldParam->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Vectorfield settings", nullptr));
        comboBox_Res_VectorFieldParam_ShiftType->setItemText(0, QApplication::translate("D_MAKRO_CiliaSphereTracker", "Linear Shift", nullptr));
        comboBox_Res_VectorFieldParam_ShiftType->setItemText(1, QApplication::translate("D_MAKRO_CiliaSphereTracker", "Angular Shift", nullptr));

        label_5->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", ":", nullptr));
        label_7->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "\302\261", nullptr));
        label_Res_VectorFieldParam_Angle->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Angle:", nullptr));
        label_12->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "\302\261", nullptr));
        doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "scale in: px shift / ", nullptr));
        doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " s", nullptr));
        doubleSpinBox_Res_VectorFieldParam_ScaleLength->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "scale show: ", nullptr));
        doubleSpinBox_Res_VectorFieldParam_ScaleLength->setSuffix(QString());
        spinBox_Res_VectorFieldParam_Thickness_Vector->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Res_VectorFieldParam_Thickness_Vector->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "vector thickness: ", nullptr));
        spinBox_Res_VectorFieldParam_KindeySteps->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "steps", nullptr));
        spinBox_Res_VectorFieldParam_KindeySteps->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "error resolution: ", nullptr));
        spinBox_Res_VectorFieldParam_Thickness_Error->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Res_VectorFieldParam_Thickness_Error->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "error thickness: ", nullptr));
        groupBox_Res_VortexCenter->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Vortex Center", nullptr));
        doubleSpinBox_Res_VortexCenter_Ransac_pGoodGuess->setPrefix(QString());
        doubleSpinBox_Res_VortexCenter_Ransac_pGoodGuess->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "% good guess ", nullptr));
        checkBox_Res_VortexCenter_Ransac->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Ransac", nullptr));
        spinBox_Res_VortexCenter_RansacIterations->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " iters", nullptr));
        spinBox_Res_VortexCenter_RansacIterations->setPrefix(QString());
        doubleSpinBox_Res_VortexCenter_Ransac_pOutliers->setPrefix(QString());
        doubleSpinBox_Res_VortexCenter_Ransac_pOutliers->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "% outliers", nullptr));
        doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setPrefix(QString());
        doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "% of", nullptr));
        comboBox_Res_VortexCenter_Ransac_PointsOrLines->setItemText(0, QApplication::translate("D_MAKRO_CiliaSphereTracker", "points", nullptr));
        comboBox_Res_VortexCenter_Ransac_PointsOrLines->setItemText(1, QApplication::translate("D_MAKRO_CiliaSphereTracker", "lines", nullptr));

        checkBox_Res_VortexCenter_MovingAverage->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Moving Average", nullptr));
        spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " frames", nullptr));
        doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "s", nullptr));
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set1->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "%", nullptr));
        lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set1->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "c,f", nullptr));
        label_23->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "ends with", nullptr));
        label_21->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "pos horizontal relative:", nullptr));
        doubleSpinBox_Res_VortexCenter_RelPos_H_Use->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "%", nullptr));
        lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set2->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "a,d", nullptr));
        label_24->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "ends with", nullptr));
        doubleSpinBox_Res_VortexCenter_RelPos_H_Set2->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "%", nullptr));
        label_6->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "xyz%", nullptr));
        label_18->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "ends with", nullptr));
        label_19->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "xyz", nullptr));
        label_17->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Well diameter", nullptr));
        doubleSpinBox_Res_VortexCenter_WellDiameter->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "D=", nullptr));
        doubleSpinBox_Res_VortexCenter_WellDiameter->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "um", nullptr));
        spinBox_Res_VortexCenter_Thickness->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "px", nullptr));
        spinBox_Res_VortexCenter_Thickness->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "thickness ", nullptr));
        doubleSpinBox_Res_VortexCenter_Resolution_Rel->setPrefix(QString());
        doubleSpinBox_Res_VortexCenter_Resolution_Rel->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "% of resolution", nullptr));
        groupBox_Res_MovAv->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Moving average", nullptr));
        spinBox_Res_MovAv_CurrentFrame->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " to 120", nullptr));
        spinBox_Res_MovAv_CurrentFrame->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "frames ", nullptr));
        doubleSpinBox_Res_MovAv_CurrentTime->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "seconds ", nullptr));
        doubleSpinBox_Res_MovAv_CurrentTime->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " to 5,00", nullptr));
        comboBox_Res_MovAv_TimeWindow->setItemText(0, QApplication::translate("D_MAKRO_CiliaSphereTracker", "Full Video", nullptr));
        comboBox_Res_MovAv_TimeWindow->setItemText(1, QApplication::translate("D_MAKRO_CiliaSphereTracker", "Moving Average", nullptr));

        comboBox_Res_MovAv_Background->setItemText(0, QApplication::translate("D_MAKRO_CiliaSphereTracker", "Time Projection", nullptr));
        comboBox_Res_MovAv_Background->setItemText(1, QApplication::translate("D_MAKRO_CiliaSphereTracker", "Input Video", nullptr));

        doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "required frames w. detections: ", nullptr));
        doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "%", nullptr));
        spinBox_Res_MovAv_WindowFrames->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " frames", nullptr));
        spinBox_Res_MovAv_WindowFrames->setPrefix(QString());
        doubleSpinBox_Res_MovAv_WindowTime->setPrefix(QString());
        doubleSpinBox_Res_MovAv_WindowTime->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " seconds", nullptr));
        groupBox_Res_GridSamplingParam->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Grid sampling", nullptr));
        spinBox_ParamGridHorizontal->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " (width: ?px each)", nullptr));
        spinBox_ParamGridHorizontal->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "horizontal: ", nullptr));
        spinBox_ParamGridVertical->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " (height: ?px each)", nullptr));
        spinBox_ParamGridVertical->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "vertical: ", nullptr));
        spinBox_ParamGrid_CellEnd->setSuffix(QString());
        spinBox_ParamGrid_CellEnd->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "to cell ", nullptr));
        spinBox_ParamGrid_CellStart->setSuffix(QString());
        spinBox_ParamGrid_CellStart->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "display from cell ", nullptr));
        groupBox_Res_Histo->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Histogram", nullptr));
        checkBox_Res_Histo_Uni->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Uniform", nullptr));
        spinBox_Res_Histo_Classes_Speed->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " classes", nullptr));
        spinBox_Res_Histo_Classes_Dist->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " classes", nullptr));
        doubleSpinBox_Res_Histo_MaxSpeedLinear->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "maximum speed ", nullptr));
        doubleSpinBox_Res_Histo_MaxSpeedLinear->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " um/s", nullptr));
        doubleSpinBox_Res_Histo_MaxSpeedAngular->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "maximum speed ", nullptr));
        doubleSpinBox_Res_Histo_MaxSpeedAngular->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "\302\260/s", nullptr));
        doubleSpinBox_Res_Histo_MaxDistCenterIntersections->setPrefix(QApplication::translate("D_MAKRO_CiliaSphereTracker", "maximum distance ", nullptr));
        doubleSpinBox_Res_Histo_MaxDistCenterIntersections->setSuffix(QApplication::translate("D_MAKRO_CiliaSphereTracker", " um", nullptr));
        checkBox_Res_Histo_Acc->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Accumulate", nullptr));
        comboBox_Res_Histo_Type->setItemText(0, QApplication::translate("D_MAKRO_CiliaSphereTracker", "Linear Speed", nullptr));
        comboBox_Res_Histo_Type->setItemText(1, QApplication::translate("D_MAKRO_CiliaSphereTracker", "Angular Speed", nullptr));
        comboBox_Res_Histo_Type->setItemText(2, QApplication::translate("D_MAKRO_CiliaSphereTracker", "Distance Intersections to Center", nullptr));

        checkBox_Res_Histo_VariationAsColorValue->setText(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Variation dependent brightness of color", nullptr));
        menuData->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Data", nullptr));
        menuWindow->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Window", nullptr));
        menuAnalysis->setTitle(QApplication::translate("D_MAKRO_CiliaSphereTracker", "Analysis", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_CiliaSphereTracker: public Ui_D_MAKRO_CiliaSphereTracker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_CILIASPHERETRACKER_H
