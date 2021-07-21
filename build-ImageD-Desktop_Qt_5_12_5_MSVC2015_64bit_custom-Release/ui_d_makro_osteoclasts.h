/********************************************************************************
** Form generated from reading UI file 'd_makro_osteoclasts.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_OSTEOCLASTS_H
#define UI_D_MAKRO_OSTEOCLASTS_H

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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_Osteoclasts
{
public:
    QAction *action_Load_Dataset;
    QAction *action_Window_Minimize;
    QAction *action_Window_Normal;
    QAction *action_Window_Maximize;
    QAction *action_Window_Fullscreen;
    QAction *action_Update_Views;
    QAction *action_Smooth_Transformation;
    QAction *action_Keep_Aspect_Ratio;
    QAction *action_Clear_Dataset;
    QAction *action_Show_Proccessing;
    QAction *action_Show_Results;
    QAction *action_Prompt_Load_Platelet_Dimension;
    QAction *action_Prompt_Scan_Segmentations;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_Proc;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox_Viewport;
    QGraphicsView *graphicsView_Proc;
    QLabel *label_Viewport;
    QTabWidget *tabWidget_Proc_Settings;
    QWidget *tab_VisVP;
    QGridLayout *gridLayout_5;
    QLabel *label_VisVP_Channel;
    QLabel *label_VisVP_ZProject_Type;
    QDoubleSpinBox *doubleSpinBox_VisVP_Range_Max_B;
    QLabel *label_VisVP_ValAtCur;
    QCheckBox *checkBox_VisVP_Auto;
    QFrame *line_VisVP_1;
    QFrame *line_VisVP_9;
    QSpinBox *spinBox_VisVP_ZLayer;
    QComboBox *comboBox_VisVP_ProjectionStat;
    QLabel *label_VisVP_Name_R;
    QDoubleSpinBox *doubleSpinBox_VisVP_Range_Min_G;
    QDoubleSpinBox *doubleSpinBox_VisVP_Gamma_B;
    QFrame *line_VisVP_2;
    QDoubleSpinBox *doubleSpinBox_VisVP_Range_Min_B;
    QFrame *line_VisVP_7;
    QFrame *line_VisVP_4;
    QFrame *line_VisVP_6;
    QFrame *line_VisVP_5;
    QDoubleSpinBox *doubleSpinBox_VisVP_Range_Max_G;
    QLabel *label_VisVP_Gamma;
    QDoubleSpinBox *doubleSpinBox_VisVP_Range_Max_R;
    QCheckBox *checkBox_VisVP_ZProject_R;
    QSpacerItem *verticalSpacer_VisVP;
    QLabel *label_VisVP_ZProject;
    QLabel *label_VisVP_ValAtCur_R;
    QFrame *line_VisVP_10;
    QLabel *label_VisVP_ValAtCur_B;
    QLabel *label_VisVP_ValAtCur_G;
    QDoubleSpinBox *doubleSpinBox_VisVP_Range_Min_R;
    QFrame *line_VisVP_8;
    QLabel *label_VisVP_Name_G;
    QCheckBox *checkBox_VisVP_Show_B;
    QLabel *label_VisVP_Name_B;
    QDoubleSpinBox *doubleSpinBox_VisVP_Gamma_G;
    QCheckBox *checkBox_VisVP_Show_R;
    QDoubleSpinBox *doubleSpinBox_VisVP_Gamma_R;
    QLabel *label_VisVP_Range;
    QCheckBox *checkBox_VisVP_ZProject_G;
    QCheckBox *checkBox_VisVP_ZProject_B;
    QFrame *line_VisVP_3;
    QCheckBox *checkBox_VisVP_Show_G;
    QWidget *tab_SegAuto;
    QGridLayout *gridLayout_6;
    QLabel *label_SegAuto_Roundness_Parameter;
    QLabel *label_SegAuto_Blur_Parameter;
    QDoubleSpinBox *doubleSpinBox_SegAuto_Blur_Sigma;
    QDoubleSpinBox *doubleSpinBox_SegAuto_Thres_Offset;
    QLabel *label_SegAuto_Watershed_Parameter;
    QLabel *label_SegAuto_Thres_Parameter;
    QSpinBox *spinBox_SegAuto_Thres_Size;
    QCheckBox *checkBox_SegAuto_Watershed_Bordered;
    QCheckBox *checkBox_SegAuto_Watershed_nSeeded;
    QDoubleSpinBox *doubleSpinBox_SegAuto_Distance_Thres;
    QDoubleSpinBox *doubleSpinBox_SegAuto_Roundness_Thres;
    QSpinBox *spinBox_SegAuto_Blur_Size;
    QLabel *label_SegAuto_Distance_Parameter;
    QLabel *label_SegAuto_Blur_Description;
    QLabel *label_SegAuto_Thres_Description;
    QLabel *label_SegAuto_Distance_Description;
    QLabel *label_SegAuto_Watershed_Description;
    QLabel *label_SegAuto_Blur_Position;
    QLabel *label_SegAuto_Roundness_Description;
    QLabel *label_SegAuto_Thres_Position;
    QLabel *label_SegAuto_Distance_Position;
    QLabel *label_SegAuto_Watershed_Position;
    QLabel *label_SegAuto_Roundness_Position;
    QComboBox *comboBox_SegAuto_Step;
    QLabel *label_SegAuto_Area_Position;
    QLabel *label_SegAuto_Area_Parameter;
    QLabel *label_SegAuto_Area_Description;
    QSpinBox *spinBox_SegAuto_Area_Min;
    QSpinBox *spinBox_SegAuto_Area_Max;
    QWidget *tab_SegMan;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox_SegMan_Draw_Type;
    QFrame *line_SegMan_2;
    QPushButton *pushButton_SegMan_Save;
    QFrame *line_SegMan_3;
    QPushButton *pushButton_SegMan_Load;
    QLineEdit *lineEdit_SegMan_SaveLoad_Suffix;
    QPushButton *pushButton_SegMan_NextSegmentation;
    QSpacerItem *verticalSpacer_SegMan;
    QComboBox *comboBox_SegMan_SegmentationType;
    QFrame *line_SegMan_1;
    QSpacerItem *horizontalSpacer_SegMan;
    QLabel *label_SegMan_NewLine_Description;
    QComboBox *comboBox_SegMan_Draw_Color;
    QSpinBox *spinBox_SegMan_Line_Width;
    QPushButton *pushButton_SegMan_Undo;
    QPushButton *pushButton_SegMan_Reset;
    QGroupBox *groupBox_Results;
    QGridLayout *gridLayout_4;
    QLabel *label_SpacerForUndefinedTime;
    QMenuBar *menubar;
    QMenu *menuData;
    QMenu *menuLayout;
    QMenu *menuViewer;
    QMenu *menuUpdate;
    QMenu *menuWindow;
    QMenu *menuPrompts;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_Osteoclasts)
    {
        if (D_MAKRO_Osteoclasts->objectName().isEmpty())
            D_MAKRO_Osteoclasts->setObjectName(QString::fromUtf8("D_MAKRO_Osteoclasts"));
        D_MAKRO_Osteoclasts->resize(974, 714);
        action_Load_Dataset = new QAction(D_MAKRO_Osteoclasts);
        action_Load_Dataset->setObjectName(QString::fromUtf8("action_Load_Dataset"));
        action_Window_Minimize = new QAction(D_MAKRO_Osteoclasts);
        action_Window_Minimize->setObjectName(QString::fromUtf8("action_Window_Minimize"));
        action_Window_Normal = new QAction(D_MAKRO_Osteoclasts);
        action_Window_Normal->setObjectName(QString::fromUtf8("action_Window_Normal"));
        action_Window_Maximize = new QAction(D_MAKRO_Osteoclasts);
        action_Window_Maximize->setObjectName(QString::fromUtf8("action_Window_Maximize"));
        action_Window_Fullscreen = new QAction(D_MAKRO_Osteoclasts);
        action_Window_Fullscreen->setObjectName(QString::fromUtf8("action_Window_Fullscreen"));
        action_Update_Views = new QAction(D_MAKRO_Osteoclasts);
        action_Update_Views->setObjectName(QString::fromUtf8("action_Update_Views"));
        action_Smooth_Transformation = new QAction(D_MAKRO_Osteoclasts);
        action_Smooth_Transformation->setObjectName(QString::fromUtf8("action_Smooth_Transformation"));
        action_Smooth_Transformation->setCheckable(true);
        action_Smooth_Transformation->setChecked(true);
        action_Keep_Aspect_Ratio = new QAction(D_MAKRO_Osteoclasts);
        action_Keep_Aspect_Ratio->setObjectName(QString::fromUtf8("action_Keep_Aspect_Ratio"));
        action_Keep_Aspect_Ratio->setCheckable(true);
        action_Keep_Aspect_Ratio->setChecked(true);
        action_Clear_Dataset = new QAction(D_MAKRO_Osteoclasts);
        action_Clear_Dataset->setObjectName(QString::fromUtf8("action_Clear_Dataset"));
        action_Show_Proccessing = new QAction(D_MAKRO_Osteoclasts);
        action_Show_Proccessing->setObjectName(QString::fromUtf8("action_Show_Proccessing"));
        action_Show_Proccessing->setCheckable(true);
        action_Show_Results = new QAction(D_MAKRO_Osteoclasts);
        action_Show_Results->setObjectName(QString::fromUtf8("action_Show_Results"));
        action_Show_Results->setCheckable(true);
        action_Prompt_Load_Platelet_Dimension = new QAction(D_MAKRO_Osteoclasts);
        action_Prompt_Load_Platelet_Dimension->setObjectName(QString::fromUtf8("action_Prompt_Load_Platelet_Dimension"));
        action_Prompt_Load_Platelet_Dimension->setCheckable(true);
        action_Prompt_Load_Platelet_Dimension->setChecked(true);
        action_Prompt_Scan_Segmentations = new QAction(D_MAKRO_Osteoclasts);
        action_Prompt_Scan_Segmentations->setObjectName(QString::fromUtf8("action_Prompt_Scan_Segmentations"));
        action_Prompt_Scan_Segmentations->setCheckable(true);
        action_Prompt_Scan_Segmentations->setChecked(true);
        centralwidget = new QWidget(D_MAKRO_Osteoclasts);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_Proc = new QGroupBox(centralwidget);
        groupBox_Proc->setObjectName(QString::fromUtf8("groupBox_Proc"));
        groupBox_Proc->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_Proc->sizePolicy().hasHeightForWidth());
        groupBox_Proc->setSizePolicy(sizePolicy);
        groupBox_Proc->setMinimumSize(QSize(400, 0));
        groupBox_Proc->setTabletTracking(false);
        gridLayout_2 = new QGridLayout(groupBox_Proc);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        comboBox_Viewport = new QComboBox(groupBox_Proc);
        comboBox_Viewport->addItem(QString());
        comboBox_Viewport->setObjectName(QString::fromUtf8("comboBox_Viewport"));

        gridLayout_2->addWidget(comboBox_Viewport, 0, 1, 1, 1);

        graphicsView_Proc = new QGraphicsView(groupBox_Proc);
        graphicsView_Proc->setObjectName(QString::fromUtf8("graphicsView_Proc"));
        graphicsView_Proc->setMouseTracking(true);

        gridLayout_2->addWidget(graphicsView_Proc, 2, 0, 1, 2);

        label_Viewport = new QLabel(groupBox_Proc);
        label_Viewport->setObjectName(QString::fromUtf8("label_Viewport"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_Viewport->sizePolicy().hasHeightForWidth());
        label_Viewport->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_Viewport, 0, 0, 1, 1);

        tabWidget_Proc_Settings = new QTabWidget(groupBox_Proc);
        tabWidget_Proc_Settings->setObjectName(QString::fromUtf8("tabWidget_Proc_Settings"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget_Proc_Settings->sizePolicy().hasHeightForWidth());
        tabWidget_Proc_Settings->setSizePolicy(sizePolicy2);
        tabWidget_Proc_Settings->setMinimumSize(QSize(0, 0));
        tabWidget_Proc_Settings->setMaximumSize(QSize(16777215, 195));
        tab_VisVP = new QWidget();
        tab_VisVP->setObjectName(QString::fromUtf8("tab_VisVP"));
        gridLayout_5 = new QGridLayout(tab_VisVP);
        gridLayout_5->setSpacing(3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(6, 6, 6, 6);
        label_VisVP_Channel = new QLabel(tab_VisVP);
        label_VisVP_Channel->setObjectName(QString::fromUtf8("label_VisVP_Channel"));

        gridLayout_5->addWidget(label_VisVP_Channel, 0, 0, 1, 2);

        label_VisVP_ZProject_Type = new QLabel(tab_VisVP);
        label_VisVP_ZProject_Type->setObjectName(QString::fromUtf8("label_VisVP_ZProject_Type"));

        gridLayout_5->addWidget(label_VisVP_ZProject_Type, 6, 0, 1, 3);

        doubleSpinBox_VisVP_Range_Max_B = new QDoubleSpinBox(tab_VisVP);
        doubleSpinBox_VisVP_Range_Max_B->setObjectName(QString::fromUtf8("doubleSpinBox_VisVP_Range_Max_B"));
        doubleSpinBox_VisVP_Range_Max_B->setMinimum(-999999999.000000000000000);
        doubleSpinBox_VisVP_Range_Max_B->setMaximum(999999999.000000000000000);
        doubleSpinBox_VisVP_Range_Max_B->setValue(255.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_VisVP_Range_Max_B, 4, 7, 1, 1);

        label_VisVP_ValAtCur = new QLabel(tab_VisVP);
        label_VisVP_ValAtCur->setObjectName(QString::fromUtf8("label_VisVP_ValAtCur"));

        gridLayout_5->addWidget(label_VisVP_ValAtCur, 0, 11, 1, 1);

        checkBox_VisVP_Auto = new QCheckBox(tab_VisVP);
        checkBox_VisVP_Auto->setObjectName(QString::fromUtf8("checkBox_VisVP_Auto"));
        checkBox_VisVP_Auto->setChecked(true);

        gridLayout_5->addWidget(checkBox_VisVP_Auto, 0, 7, 1, 1);

        line_VisVP_1 = new QFrame(tab_VisVP);
        line_VisVP_1->setObjectName(QString::fromUtf8("line_VisVP_1"));
        line_VisVP_1->setFrameShape(QFrame::HLine);
        line_VisVP_1->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_VisVP_1, 1, 0, 1, 2);

        line_VisVP_9 = new QFrame(tab_VisVP);
        line_VisVP_9->setObjectName(QString::fromUtf8("line_VisVP_9"));
        line_VisVP_9->setFrameShape(QFrame::VLine);
        line_VisVP_9->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_VisVP_9, 0, 10, 5, 1);

        spinBox_VisVP_ZLayer = new QSpinBox(tab_VisVP);
        spinBox_VisVP_ZLayer->setObjectName(QString::fromUtf8("spinBox_VisVP_ZLayer"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spinBox_VisVP_ZLayer->sizePolicy().hasHeightForWidth());
        spinBox_VisVP_ZLayer->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(spinBox_VisVP_ZLayer, 2, 4, 3, 1);

        comboBox_VisVP_ProjectionStat = new QComboBox(tab_VisVP);
        comboBox_VisVP_ProjectionStat->setObjectName(QString::fromUtf8("comboBox_VisVP_ProjectionStat"));

        gridLayout_5->addWidget(comboBox_VisVP_ProjectionStat, 6, 3, 1, 7);

        label_VisVP_Name_R = new QLabel(tab_VisVP);
        label_VisVP_Name_R->setObjectName(QString::fromUtf8("label_VisVP_Name_R"));

        gridLayout_5->addWidget(label_VisVP_Name_R, 2, 1, 1, 1);

        doubleSpinBox_VisVP_Range_Min_G = new QDoubleSpinBox(tab_VisVP);
        doubleSpinBox_VisVP_Range_Min_G->setObjectName(QString::fromUtf8("doubleSpinBox_VisVP_Range_Min_G"));
        doubleSpinBox_VisVP_Range_Min_G->setMinimum(-999999999.000000000000000);
        doubleSpinBox_VisVP_Range_Min_G->setMaximum(999999999.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_VisVP_Range_Min_G, 3, 6, 1, 1);

        doubleSpinBox_VisVP_Gamma_B = new QDoubleSpinBox(tab_VisVP);
        doubleSpinBox_VisVP_Gamma_B->setObjectName(QString::fromUtf8("doubleSpinBox_VisVP_Gamma_B"));
        doubleSpinBox_VisVP_Gamma_B->setMinimum(0.010000000000000);
        doubleSpinBox_VisVP_Gamma_B->setSingleStep(0.050000000000000);
        doubleSpinBox_VisVP_Gamma_B->setValue(1.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_VisVP_Gamma_B, 4, 9, 1, 1);

        line_VisVP_2 = new QFrame(tab_VisVP);
        line_VisVP_2->setObjectName(QString::fromUtf8("line_VisVP_2"));
        line_VisVP_2->setFrameShape(QFrame::HLine);
        line_VisVP_2->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_VisVP_2, 1, 3, 1, 2);

        doubleSpinBox_VisVP_Range_Min_B = new QDoubleSpinBox(tab_VisVP);
        doubleSpinBox_VisVP_Range_Min_B->setObjectName(QString::fromUtf8("doubleSpinBox_VisVP_Range_Min_B"));
        doubleSpinBox_VisVP_Range_Min_B->setMinimum(-999999999.000000000000000);
        doubleSpinBox_VisVP_Range_Min_B->setMaximum(999999999.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_VisVP_Range_Min_B, 4, 6, 1, 1);

        line_VisVP_7 = new QFrame(tab_VisVP);
        line_VisVP_7->setObjectName(QString::fromUtf8("line_VisVP_7"));
        line_VisVP_7->setFrameShape(QFrame::VLine);
        line_VisVP_7->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_VisVP_7, 0, 8, 5, 1);

        line_VisVP_4 = new QFrame(tab_VisVP);
        line_VisVP_4->setObjectName(QString::fromUtf8("line_VisVP_4"));
        line_VisVP_4->setFrameShape(QFrame::HLine);
        line_VisVP_4->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_VisVP_4, 1, 9, 1, 1);

        line_VisVP_6 = new QFrame(tab_VisVP);
        line_VisVP_6->setObjectName(QString::fromUtf8("line_VisVP_6"));
        line_VisVP_6->setFrameShape(QFrame::VLine);
        line_VisVP_6->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_VisVP_6, 0, 5, 5, 1);

        line_VisVP_5 = new QFrame(tab_VisVP);
        line_VisVP_5->setObjectName(QString::fromUtf8("line_VisVP_5"));
        line_VisVP_5->setFrameShape(QFrame::VLine);
        line_VisVP_5->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_VisVP_5, 0, 2, 5, 1);

        doubleSpinBox_VisVP_Range_Max_G = new QDoubleSpinBox(tab_VisVP);
        doubleSpinBox_VisVP_Range_Max_G->setObjectName(QString::fromUtf8("doubleSpinBox_VisVP_Range_Max_G"));
        doubleSpinBox_VisVP_Range_Max_G->setMinimum(-999999999.000000000000000);
        doubleSpinBox_VisVP_Range_Max_G->setMaximum(999999999.000000000000000);
        doubleSpinBox_VisVP_Range_Max_G->setValue(255.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_VisVP_Range_Max_G, 3, 7, 1, 1);

        label_VisVP_Gamma = new QLabel(tab_VisVP);
        label_VisVP_Gamma->setObjectName(QString::fromUtf8("label_VisVP_Gamma"));

        gridLayout_5->addWidget(label_VisVP_Gamma, 0, 9, 1, 1);

        doubleSpinBox_VisVP_Range_Max_R = new QDoubleSpinBox(tab_VisVP);
        doubleSpinBox_VisVP_Range_Max_R->setObjectName(QString::fromUtf8("doubleSpinBox_VisVP_Range_Max_R"));
        doubleSpinBox_VisVP_Range_Max_R->setMinimum(-999999999.000000000000000);
        doubleSpinBox_VisVP_Range_Max_R->setMaximum(999999999.000000000000000);
        doubleSpinBox_VisVP_Range_Max_R->setValue(255.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_VisVP_Range_Max_R, 2, 7, 1, 1);

        checkBox_VisVP_ZProject_R = new QCheckBox(tab_VisVP);
        checkBox_VisVP_ZProject_R->setObjectName(QString::fromUtf8("checkBox_VisVP_ZProject_R"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(checkBox_VisVP_ZProject_R->sizePolicy().hasHeightForWidth());
        checkBox_VisVP_ZProject_R->setSizePolicy(sizePolicy4);
        checkBox_VisVP_ZProject_R->setChecked(true);

        gridLayout_5->addWidget(checkBox_VisVP_ZProject_R, 2, 3, 1, 1);

        verticalSpacer_VisVP = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_VisVP, 7, 6, 1, 1);

        label_VisVP_ZProject = new QLabel(tab_VisVP);
        label_VisVP_ZProject->setObjectName(QString::fromUtf8("label_VisVP_ZProject"));

        gridLayout_5->addWidget(label_VisVP_ZProject, 0, 3, 1, 2);

        label_VisVP_ValAtCur_R = new QLabel(tab_VisVP);
        label_VisVP_ValAtCur_R->setObjectName(QString::fromUtf8("label_VisVP_ValAtCur_R"));

        gridLayout_5->addWidget(label_VisVP_ValAtCur_R, 2, 11, 1, 1);

        line_VisVP_10 = new QFrame(tab_VisVP);
        line_VisVP_10->setObjectName(QString::fromUtf8("line_VisVP_10"));
        line_VisVP_10->setFrameShape(QFrame::HLine);
        line_VisVP_10->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_VisVP_10, 1, 11, 1, 1);

        label_VisVP_ValAtCur_B = new QLabel(tab_VisVP);
        label_VisVP_ValAtCur_B->setObjectName(QString::fromUtf8("label_VisVP_ValAtCur_B"));

        gridLayout_5->addWidget(label_VisVP_ValAtCur_B, 4, 11, 1, 1);

        label_VisVP_ValAtCur_G = new QLabel(tab_VisVP);
        label_VisVP_ValAtCur_G->setObjectName(QString::fromUtf8("label_VisVP_ValAtCur_G"));

        gridLayout_5->addWidget(label_VisVP_ValAtCur_G, 3, 11, 1, 1);

        doubleSpinBox_VisVP_Range_Min_R = new QDoubleSpinBox(tab_VisVP);
        doubleSpinBox_VisVP_Range_Min_R->setObjectName(QString::fromUtf8("doubleSpinBox_VisVP_Range_Min_R"));
        doubleSpinBox_VisVP_Range_Min_R->setMinimum(-999999999.000000000000000);
        doubleSpinBox_VisVP_Range_Min_R->setMaximum(999999999.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_VisVP_Range_Min_R, 2, 6, 1, 1);

        line_VisVP_8 = new QFrame(tab_VisVP);
        line_VisVP_8->setObjectName(QString::fromUtf8("line_VisVP_8"));
        line_VisVP_8->setFrameShape(QFrame::HLine);
        line_VisVP_8->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_VisVP_8, 5, 0, 1, 12);

        label_VisVP_Name_G = new QLabel(tab_VisVP);
        label_VisVP_Name_G->setObjectName(QString::fromUtf8("label_VisVP_Name_G"));

        gridLayout_5->addWidget(label_VisVP_Name_G, 3, 1, 1, 1);

        checkBox_VisVP_Show_B = new QCheckBox(tab_VisVP);
        checkBox_VisVP_Show_B->setObjectName(QString::fromUtf8("checkBox_VisVP_Show_B"));
        sizePolicy4.setHeightForWidth(checkBox_VisVP_Show_B->sizePolicy().hasHeightForWidth());
        checkBox_VisVP_Show_B->setSizePolicy(sizePolicy4);
        checkBox_VisVP_Show_B->setChecked(true);

        gridLayout_5->addWidget(checkBox_VisVP_Show_B, 4, 0, 1, 1);

        label_VisVP_Name_B = new QLabel(tab_VisVP);
        label_VisVP_Name_B->setObjectName(QString::fromUtf8("label_VisVP_Name_B"));

        gridLayout_5->addWidget(label_VisVP_Name_B, 4, 1, 1, 1);

        doubleSpinBox_VisVP_Gamma_G = new QDoubleSpinBox(tab_VisVP);
        doubleSpinBox_VisVP_Gamma_G->setObjectName(QString::fromUtf8("doubleSpinBox_VisVP_Gamma_G"));
        doubleSpinBox_VisVP_Gamma_G->setMinimum(0.010000000000000);
        doubleSpinBox_VisVP_Gamma_G->setSingleStep(0.050000000000000);
        doubleSpinBox_VisVP_Gamma_G->setValue(1.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_VisVP_Gamma_G, 3, 9, 1, 1);

        checkBox_VisVP_Show_R = new QCheckBox(tab_VisVP);
        checkBox_VisVP_Show_R->setObjectName(QString::fromUtf8("checkBox_VisVP_Show_R"));
        sizePolicy4.setHeightForWidth(checkBox_VisVP_Show_R->sizePolicy().hasHeightForWidth());
        checkBox_VisVP_Show_R->setSizePolicy(sizePolicy4);
        checkBox_VisVP_Show_R->setChecked(true);

        gridLayout_5->addWidget(checkBox_VisVP_Show_R, 2, 0, 1, 1);

        doubleSpinBox_VisVP_Gamma_R = new QDoubleSpinBox(tab_VisVP);
        doubleSpinBox_VisVP_Gamma_R->setObjectName(QString::fromUtf8("doubleSpinBox_VisVP_Gamma_R"));
        doubleSpinBox_VisVP_Gamma_R->setMinimum(0.010000000000000);
        doubleSpinBox_VisVP_Gamma_R->setSingleStep(0.050000000000000);
        doubleSpinBox_VisVP_Gamma_R->setValue(1.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_VisVP_Gamma_R, 2, 9, 1, 1);

        label_VisVP_Range = new QLabel(tab_VisVP);
        label_VisVP_Range->setObjectName(QString::fromUtf8("label_VisVP_Range"));

        gridLayout_5->addWidget(label_VisVP_Range, 0, 6, 1, 1);

        checkBox_VisVP_ZProject_G = new QCheckBox(tab_VisVP);
        checkBox_VisVP_ZProject_G->setObjectName(QString::fromUtf8("checkBox_VisVP_ZProject_G"));
        sizePolicy4.setHeightForWidth(checkBox_VisVP_ZProject_G->sizePolicy().hasHeightForWidth());
        checkBox_VisVP_ZProject_G->setSizePolicy(sizePolicy4);
        checkBox_VisVP_ZProject_G->setChecked(true);

        gridLayout_5->addWidget(checkBox_VisVP_ZProject_G, 3, 3, 1, 1);

        checkBox_VisVP_ZProject_B = new QCheckBox(tab_VisVP);
        checkBox_VisVP_ZProject_B->setObjectName(QString::fromUtf8("checkBox_VisVP_ZProject_B"));
        sizePolicy4.setHeightForWidth(checkBox_VisVP_ZProject_B->sizePolicy().hasHeightForWidth());
        checkBox_VisVP_ZProject_B->setSizePolicy(sizePolicy4);
        checkBox_VisVP_ZProject_B->setChecked(true);

        gridLayout_5->addWidget(checkBox_VisVP_ZProject_B, 4, 3, 1, 1);

        line_VisVP_3 = new QFrame(tab_VisVP);
        line_VisVP_3->setObjectName(QString::fromUtf8("line_VisVP_3"));
        line_VisVP_3->setFrameShape(QFrame::HLine);
        line_VisVP_3->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_VisVP_3, 1, 6, 1, 2);

        checkBox_VisVP_Show_G = new QCheckBox(tab_VisVP);
        checkBox_VisVP_Show_G->setObjectName(QString::fromUtf8("checkBox_VisVP_Show_G"));
        sizePolicy4.setHeightForWidth(checkBox_VisVP_Show_G->sizePolicy().hasHeightForWidth());
        checkBox_VisVP_Show_G->setSizePolicy(sizePolicy4);
        checkBox_VisVP_Show_G->setChecked(true);

        gridLayout_5->addWidget(checkBox_VisVP_Show_G, 3, 0, 1, 1);

        tabWidget_Proc_Settings->addTab(tab_VisVP, QString());
        tab_SegAuto = new QWidget();
        tab_SegAuto->setObjectName(QString::fromUtf8("tab_SegAuto"));
        gridLayout_6 = new QGridLayout(tab_SegAuto);
        gridLayout_6->setSpacing(3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(6, 6, 6, 6);
        label_SegAuto_Roundness_Parameter = new QLabel(tab_SegAuto);
        label_SegAuto_Roundness_Parameter->setObjectName(QString::fromUtf8("label_SegAuto_Roundness_Parameter"));
        label_SegAuto_Roundness_Parameter->setMinimumSize(QSize(75, 0));
        label_SegAuto_Roundness_Parameter->setMaximumSize(QSize(75, 16777215));

        gridLayout_6->addWidget(label_SegAuto_Roundness_Parameter, 6, 1, 1, 1);

        label_SegAuto_Blur_Parameter = new QLabel(tab_SegAuto);
        label_SegAuto_Blur_Parameter->setObjectName(QString::fromUtf8("label_SegAuto_Blur_Parameter"));
        label_SegAuto_Blur_Parameter->setMinimumSize(QSize(75, 0));
        label_SegAuto_Blur_Parameter->setMaximumSize(QSize(75, 16777215));

        gridLayout_6->addWidget(label_SegAuto_Blur_Parameter, 1, 1, 1, 1);

        doubleSpinBox_SegAuto_Blur_Sigma = new QDoubleSpinBox(tab_SegAuto);
        doubleSpinBox_SegAuto_Blur_Sigma->setObjectName(QString::fromUtf8("doubleSpinBox_SegAuto_Blur_Sigma"));
        doubleSpinBox_SegAuto_Blur_Sigma->setMaximumSize(QSize(75, 16777215));
        doubleSpinBox_SegAuto_Blur_Sigma->setMinimum(-999.000000000000000);
        doubleSpinBox_SegAuto_Blur_Sigma->setMaximum(999.000000000000000);
        doubleSpinBox_SegAuto_Blur_Sigma->setValue(15.000000000000000);

        gridLayout_6->addWidget(doubleSpinBox_SegAuto_Blur_Sigma, 1, 3, 1, 1);

        doubleSpinBox_SegAuto_Thres_Offset = new QDoubleSpinBox(tab_SegAuto);
        doubleSpinBox_SegAuto_Thres_Offset->setObjectName(QString::fromUtf8("doubleSpinBox_SegAuto_Thres_Offset"));
        doubleSpinBox_SegAuto_Thres_Offset->setMaximumSize(QSize(75, 16777215));
        doubleSpinBox_SegAuto_Thres_Offset->setMinimum(-999.000000000000000);
        doubleSpinBox_SegAuto_Thres_Offset->setMaximum(999.000000000000000);
        doubleSpinBox_SegAuto_Thres_Offset->setValue(-9.000000000000000);

        gridLayout_6->addWidget(doubleSpinBox_SegAuto_Thres_Offset, 2, 3, 1, 1);

        label_SegAuto_Watershed_Parameter = new QLabel(tab_SegAuto);
        label_SegAuto_Watershed_Parameter->setObjectName(QString::fromUtf8("label_SegAuto_Watershed_Parameter"));
        label_SegAuto_Watershed_Parameter->setMinimumSize(QSize(75, 0));
        label_SegAuto_Watershed_Parameter->setMaximumSize(QSize(75, 16777215));

        gridLayout_6->addWidget(label_SegAuto_Watershed_Parameter, 4, 1, 1, 1);

        label_SegAuto_Thres_Parameter = new QLabel(tab_SegAuto);
        label_SegAuto_Thres_Parameter->setObjectName(QString::fromUtf8("label_SegAuto_Thres_Parameter"));
        label_SegAuto_Thres_Parameter->setMinimumSize(QSize(75, 0));
        label_SegAuto_Thres_Parameter->setMaximumSize(QSize(75, 16777215));

        gridLayout_6->addWidget(label_SegAuto_Thres_Parameter, 2, 1, 1, 1);

        spinBox_SegAuto_Thres_Size = new QSpinBox(tab_SegAuto);
        spinBox_SegAuto_Thres_Size->setObjectName(QString::fromUtf8("spinBox_SegAuto_Thres_Size"));
        spinBox_SegAuto_Thres_Size->setMaximumSize(QSize(75, 16777215));
        spinBox_SegAuto_Thres_Size->setMinimum(1);
        spinBox_SegAuto_Thres_Size->setMaximum(999);
        spinBox_SegAuto_Thres_Size->setSingleStep(2);
        spinBox_SegAuto_Thres_Size->setValue(23);

        gridLayout_6->addWidget(spinBox_SegAuto_Thres_Size, 2, 2, 1, 1);

        checkBox_SegAuto_Watershed_Bordered = new QCheckBox(tab_SegAuto);
        checkBox_SegAuto_Watershed_Bordered->setObjectName(QString::fromUtf8("checkBox_SegAuto_Watershed_Bordered"));
        checkBox_SegAuto_Watershed_Bordered->setMaximumSize(QSize(75, 16777215));
        checkBox_SegAuto_Watershed_Bordered->setChecked(true);

        gridLayout_6->addWidget(checkBox_SegAuto_Watershed_Bordered, 4, 2, 1, 1);

        checkBox_SegAuto_Watershed_nSeeded = new QCheckBox(tab_SegAuto);
        checkBox_SegAuto_Watershed_nSeeded->setObjectName(QString::fromUtf8("checkBox_SegAuto_Watershed_nSeeded"));
        checkBox_SegAuto_Watershed_nSeeded->setMaximumSize(QSize(75, 16777215));
        checkBox_SegAuto_Watershed_nSeeded->setChecked(true);

        gridLayout_6->addWidget(checkBox_SegAuto_Watershed_nSeeded, 4, 3, 1, 1);

        doubleSpinBox_SegAuto_Distance_Thres = new QDoubleSpinBox(tab_SegAuto);
        doubleSpinBox_SegAuto_Distance_Thres->setObjectName(QString::fromUtf8("doubleSpinBox_SegAuto_Distance_Thres"));
        doubleSpinBox_SegAuto_Distance_Thres->setMaximumSize(QSize(153, 16777215));
        doubleSpinBox_SegAuto_Distance_Thres->setMaximum(999.000000000000000);
        doubleSpinBox_SegAuto_Distance_Thres->setSingleStep(0.010000000000000);
        doubleSpinBox_SegAuto_Distance_Thres->setValue(6.000000000000000);

        gridLayout_6->addWidget(doubleSpinBox_SegAuto_Distance_Thres, 3, 2, 1, 2);

        doubleSpinBox_SegAuto_Roundness_Thres = new QDoubleSpinBox(tab_SegAuto);
        doubleSpinBox_SegAuto_Roundness_Thres->setObjectName(QString::fromUtf8("doubleSpinBox_SegAuto_Roundness_Thres"));
        doubleSpinBox_SegAuto_Roundness_Thres->setMaximumSize(QSize(153, 16777215));
        doubleSpinBox_SegAuto_Roundness_Thres->setSingleStep(0.010000000000000);
        doubleSpinBox_SegAuto_Roundness_Thres->setValue(0.830000000000000);

        gridLayout_6->addWidget(doubleSpinBox_SegAuto_Roundness_Thres, 6, 2, 1, 2);

        spinBox_SegAuto_Blur_Size = new QSpinBox(tab_SegAuto);
        spinBox_SegAuto_Blur_Size->setObjectName(QString::fromUtf8("spinBox_SegAuto_Blur_Size"));
        spinBox_SegAuto_Blur_Size->setMaximumSize(QSize(75, 16777215));
        spinBox_SegAuto_Blur_Size->setMinimum(1);
        spinBox_SegAuto_Blur_Size->setMaximum(999);
        spinBox_SegAuto_Blur_Size->setSingleStep(2);
        spinBox_SegAuto_Blur_Size->setValue(7);

        gridLayout_6->addWidget(spinBox_SegAuto_Blur_Size, 1, 2, 1, 1);

        label_SegAuto_Distance_Parameter = new QLabel(tab_SegAuto);
        label_SegAuto_Distance_Parameter->setObjectName(QString::fromUtf8("label_SegAuto_Distance_Parameter"));
        label_SegAuto_Distance_Parameter->setMinimumSize(QSize(75, 0));
        label_SegAuto_Distance_Parameter->setMaximumSize(QSize(75, 16777215));

        gridLayout_6->addWidget(label_SegAuto_Distance_Parameter, 3, 1, 1, 1);

        label_SegAuto_Blur_Description = new QLabel(tab_SegAuto);
        label_SegAuto_Blur_Description->setObjectName(QString::fromUtf8("label_SegAuto_Blur_Description"));
        label_SegAuto_Blur_Description->setMinimumSize(QSize(75, 0));
        label_SegAuto_Blur_Description->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(label_SegAuto_Blur_Description, 1, 4, 1, 1);

        label_SegAuto_Thres_Description = new QLabel(tab_SegAuto);
        label_SegAuto_Thres_Description->setObjectName(QString::fromUtf8("label_SegAuto_Thres_Description"));
        label_SegAuto_Thres_Description->setMinimumSize(QSize(75, 0));
        label_SegAuto_Thres_Description->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(label_SegAuto_Thres_Description, 2, 4, 1, 1);

        label_SegAuto_Distance_Description = new QLabel(tab_SegAuto);
        label_SegAuto_Distance_Description->setObjectName(QString::fromUtf8("label_SegAuto_Distance_Description"));
        label_SegAuto_Distance_Description->setMinimumSize(QSize(75, 0));
        label_SegAuto_Distance_Description->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(label_SegAuto_Distance_Description, 3, 4, 1, 1);

        label_SegAuto_Watershed_Description = new QLabel(tab_SegAuto);
        label_SegAuto_Watershed_Description->setObjectName(QString::fromUtf8("label_SegAuto_Watershed_Description"));
        label_SegAuto_Watershed_Description->setMinimumSize(QSize(75, 0));
        label_SegAuto_Watershed_Description->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(label_SegAuto_Watershed_Description, 4, 4, 1, 1);

        label_SegAuto_Blur_Position = new QLabel(tab_SegAuto);
        label_SegAuto_Blur_Position->setObjectName(QString::fromUtf8("label_SegAuto_Blur_Position"));
        label_SegAuto_Blur_Position->setMinimumSize(QSize(20, 0));
        label_SegAuto_Blur_Position->setMaximumSize(QSize(20, 16777215));

        gridLayout_6->addWidget(label_SegAuto_Blur_Position, 1, 0, 1, 1);

        label_SegAuto_Roundness_Description = new QLabel(tab_SegAuto);
        label_SegAuto_Roundness_Description->setObjectName(QString::fromUtf8("label_SegAuto_Roundness_Description"));
        label_SegAuto_Roundness_Description->setMinimumSize(QSize(75, 0));
        label_SegAuto_Roundness_Description->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(label_SegAuto_Roundness_Description, 6, 4, 1, 1);

        label_SegAuto_Thres_Position = new QLabel(tab_SegAuto);
        label_SegAuto_Thres_Position->setObjectName(QString::fromUtf8("label_SegAuto_Thres_Position"));
        label_SegAuto_Thres_Position->setMinimumSize(QSize(20, 0));
        label_SegAuto_Thres_Position->setMaximumSize(QSize(20, 16777215));

        gridLayout_6->addWidget(label_SegAuto_Thres_Position, 2, 0, 1, 1);

        label_SegAuto_Distance_Position = new QLabel(tab_SegAuto);
        label_SegAuto_Distance_Position->setObjectName(QString::fromUtf8("label_SegAuto_Distance_Position"));
        label_SegAuto_Distance_Position->setMinimumSize(QSize(20, 0));
        label_SegAuto_Distance_Position->setMaximumSize(QSize(20, 16777215));

        gridLayout_6->addWidget(label_SegAuto_Distance_Position, 3, 0, 1, 1);

        label_SegAuto_Watershed_Position = new QLabel(tab_SegAuto);
        label_SegAuto_Watershed_Position->setObjectName(QString::fromUtf8("label_SegAuto_Watershed_Position"));
        label_SegAuto_Watershed_Position->setMinimumSize(QSize(20, 0));
        label_SegAuto_Watershed_Position->setMaximumSize(QSize(20, 16777215));

        gridLayout_6->addWidget(label_SegAuto_Watershed_Position, 4, 0, 1, 1);

        label_SegAuto_Roundness_Position = new QLabel(tab_SegAuto);
        label_SegAuto_Roundness_Position->setObjectName(QString::fromUtf8("label_SegAuto_Roundness_Position"));
        label_SegAuto_Roundness_Position->setMinimumSize(QSize(20, 0));
        label_SegAuto_Roundness_Position->setMaximumSize(QSize(20, 16777215));

        gridLayout_6->addWidget(label_SegAuto_Roundness_Position, 6, 0, 1, 1);

        comboBox_SegAuto_Step = new QComboBox(tab_SegAuto);
        comboBox_SegAuto_Step->addItem(QString());
        comboBox_SegAuto_Step->setObjectName(QString::fromUtf8("comboBox_SegAuto_Step"));

        gridLayout_6->addWidget(comboBox_SegAuto_Step, 0, 0, 1, 5);

        label_SegAuto_Area_Position = new QLabel(tab_SegAuto);
        label_SegAuto_Area_Position->setObjectName(QString::fromUtf8("label_SegAuto_Area_Position"));

        gridLayout_6->addWidget(label_SegAuto_Area_Position, 5, 0, 1, 1);

        label_SegAuto_Area_Parameter = new QLabel(tab_SegAuto);
        label_SegAuto_Area_Parameter->setObjectName(QString::fromUtf8("label_SegAuto_Area_Parameter"));

        gridLayout_6->addWidget(label_SegAuto_Area_Parameter, 5, 1, 1, 1);

        label_SegAuto_Area_Description = new QLabel(tab_SegAuto);
        label_SegAuto_Area_Description->setObjectName(QString::fromUtf8("label_SegAuto_Area_Description"));

        gridLayout_6->addWidget(label_SegAuto_Area_Description, 5, 4, 1, 1);

        spinBox_SegAuto_Area_Min = new QSpinBox(tab_SegAuto);
        spinBox_SegAuto_Area_Min->setObjectName(QString::fromUtf8("spinBox_SegAuto_Area_Min"));
        spinBox_SegAuto_Area_Min->setMaximum(999998);
        spinBox_SegAuto_Area_Min->setValue(190);

        gridLayout_6->addWidget(spinBox_SegAuto_Area_Min, 5, 2, 1, 1);

        spinBox_SegAuto_Area_Max = new QSpinBox(tab_SegAuto);
        spinBox_SegAuto_Area_Max->setObjectName(QString::fromUtf8("spinBox_SegAuto_Area_Max"));
        spinBox_SegAuto_Area_Max->setMinimum(1);
        spinBox_SegAuto_Area_Max->setMaximum(999999);
        spinBox_SegAuto_Area_Max->setValue(1000);

        gridLayout_6->addWidget(spinBox_SegAuto_Area_Max, 5, 3, 1, 1);

        tabWidget_Proc_Settings->addTab(tab_SegAuto, QString());
        tab_SegMan = new QWidget();
        tab_SegMan->setObjectName(QString::fromUtf8("tab_SegMan"));
        gridLayout_3 = new QGridLayout(tab_SegMan);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(6, 6, 6, 6);
        comboBox_SegMan_Draw_Type = new QComboBox(tab_SegMan);
        comboBox_SegMan_Draw_Type->addItem(QString());
        comboBox_SegMan_Draw_Type->setObjectName(QString::fromUtf8("comboBox_SegMan_Draw_Type"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(comboBox_SegMan_Draw_Type->sizePolicy().hasHeightForWidth());
        comboBox_SegMan_Draw_Type->setSizePolicy(sizePolicy5);
        comboBox_SegMan_Draw_Type->setMinimumSize(QSize(100, 20));
        comboBox_SegMan_Draw_Type->setMaximumSize(QSize(100, 20));

        gridLayout_3->addWidget(comboBox_SegMan_Draw_Type, 2, 0, 1, 1);

        line_SegMan_2 = new QFrame(tab_SegMan);
        line_SegMan_2->setObjectName(QString::fromUtf8("line_SegMan_2"));
        line_SegMan_2->setFrameShape(QFrame::VLine);
        line_SegMan_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_SegMan_2, 2, 1, 5, 1);

        pushButton_SegMan_Save = new QPushButton(tab_SegMan);
        pushButton_SegMan_Save->setObjectName(QString::fromUtf8("pushButton_SegMan_Save"));
        pushButton_SegMan_Save->setEnabled(false);
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(1);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pushButton_SegMan_Save->sizePolicy().hasHeightForWidth());
        pushButton_SegMan_Save->setSizePolicy(sizePolicy6);
        pushButton_SegMan_Save->setMinimumSize(QSize(100, 20));
        pushButton_SegMan_Save->setMaximumSize(QSize(100, 20));

        gridLayout_3->addWidget(pushButton_SegMan_Save, 2, 2, 1, 1);

        line_SegMan_3 = new QFrame(tab_SegMan);
        line_SegMan_3->setObjectName(QString::fromUtf8("line_SegMan_3"));
        line_SegMan_3->setFrameShape(QFrame::VLine);
        line_SegMan_3->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_SegMan_3, 2, 3, 5, 1);

        pushButton_SegMan_Load = new QPushButton(tab_SegMan);
        pushButton_SegMan_Load->setObjectName(QString::fromUtf8("pushButton_SegMan_Load"));
        pushButton_SegMan_Load->setEnabled(false);
        sizePolicy6.setHeightForWidth(pushButton_SegMan_Load->sizePolicy().hasHeightForWidth());
        pushButton_SegMan_Load->setSizePolicy(sizePolicy6);
        pushButton_SegMan_Load->setMinimumSize(QSize(100, 20));
        pushButton_SegMan_Load->setMaximumSize(QSize(100, 20));

        gridLayout_3->addWidget(pushButton_SegMan_Load, 3, 2, 1, 1);

        lineEdit_SegMan_SaveLoad_Suffix = new QLineEdit(tab_SegMan);
        lineEdit_SegMan_SaveLoad_Suffix->setObjectName(QString::fromUtf8("lineEdit_SegMan_SaveLoad_Suffix"));
        lineEdit_SegMan_SaveLoad_Suffix->setEnabled(false);
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(1);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(lineEdit_SegMan_SaveLoad_Suffix->sizePolicy().hasHeightForWidth());
        lineEdit_SegMan_SaveLoad_Suffix->setSizePolicy(sizePolicy7);
        lineEdit_SegMan_SaveLoad_Suffix->setMinimumSize(QSize(0, 20));
        lineEdit_SegMan_SaveLoad_Suffix->setMaximumSize(QSize(100, 20));

        gridLayout_3->addWidget(lineEdit_SegMan_SaveLoad_Suffix, 4, 2, 1, 1);

        pushButton_SegMan_NextSegmentation = new QPushButton(tab_SegMan);
        pushButton_SegMan_NextSegmentation->setObjectName(QString::fromUtf8("pushButton_SegMan_NextSegmentation"));
        sizePolicy6.setHeightForWidth(pushButton_SegMan_NextSegmentation->sizePolicy().hasHeightForWidth());
        pushButton_SegMan_NextSegmentation->setSizePolicy(sizePolicy6);
        pushButton_SegMan_NextSegmentation->setMinimumSize(QSize(100, 20));
        pushButton_SegMan_NextSegmentation->setMaximumSize(QSize(100, 20));

        gridLayout_3->addWidget(pushButton_SegMan_NextSegmentation, 0, 0, 1, 1);

        verticalSpacer_SegMan = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_SegMan, 6, 2, 1, 1);

        comboBox_SegMan_SegmentationType = new QComboBox(tab_SegMan);
        comboBox_SegMan_SegmentationType->addItem(QString());
        comboBox_SegMan_SegmentationType->setObjectName(QString::fromUtf8("comboBox_SegMan_SegmentationType"));
        sizePolicy5.setHeightForWidth(comboBox_SegMan_SegmentationType->sizePolicy().hasHeightForWidth());
        comboBox_SegMan_SegmentationType->setSizePolicy(sizePolicy5);
        comboBox_SegMan_SegmentationType->setMinimumSize(QSize(0, 20));
        comboBox_SegMan_SegmentationType->setMaximumSize(QSize(16777215, 20));

        gridLayout_3->addWidget(comboBox_SegMan_SegmentationType, 0, 2, 1, 4);

        line_SegMan_1 = new QFrame(tab_SegMan);
        line_SegMan_1->setObjectName(QString::fromUtf8("line_SegMan_1"));
        line_SegMan_1->setFrameShape(QFrame::HLine);
        line_SegMan_1->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_SegMan_1, 1, 0, 1, 6);

        horizontalSpacer_SegMan = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_SegMan, 2, 5, 2, 1);

        label_SegMan_NewLine_Description = new QLabel(tab_SegMan);
        label_SegMan_NewLine_Description->setObjectName(QString::fromUtf8("label_SegMan_NewLine_Description"));

        gridLayout_3->addWidget(label_SegMan_NewLine_Description, 5, 0, 1, 1);

        comboBox_SegMan_Draw_Color = new QComboBox(tab_SegMan);
        comboBox_SegMan_Draw_Color->addItem(QString());
        comboBox_SegMan_Draw_Color->setObjectName(QString::fromUtf8("comboBox_SegMan_Draw_Color"));

        gridLayout_3->addWidget(comboBox_SegMan_Draw_Color, 3, 0, 1, 1);

        spinBox_SegMan_Line_Width = new QSpinBox(tab_SegMan);
        spinBox_SegMan_Line_Width->setObjectName(QString::fromUtf8("spinBox_SegMan_Line_Width"));
        spinBox_SegMan_Line_Width->setMinimum(1);

        gridLayout_3->addWidget(spinBox_SegMan_Line_Width, 4, 0, 1, 1);

        pushButton_SegMan_Undo = new QPushButton(tab_SegMan);
        pushButton_SegMan_Undo->setObjectName(QString::fromUtf8("pushButton_SegMan_Undo"));
        pushButton_SegMan_Undo->setEnabled(false);
        pushButton_SegMan_Undo->setMaximumSize(QSize(16777215, 20));

        gridLayout_3->addWidget(pushButton_SegMan_Undo, 2, 4, 1, 1);

        pushButton_SegMan_Reset = new QPushButton(tab_SegMan);
        pushButton_SegMan_Reset->setObjectName(QString::fromUtf8("pushButton_SegMan_Reset"));
        pushButton_SegMan_Reset->setMaximumSize(QSize(16777215, 20));

        gridLayout_3->addWidget(pushButton_SegMan_Reset, 3, 4, 1, 1);

        tabWidget_Proc_Settings->addTab(tab_SegMan, QString());

        gridLayout_2->addWidget(tabWidget_Proc_Settings, 1, 0, 1, 2);


        gridLayout->addWidget(groupBox_Proc, 0, 0, 1, 1);

        groupBox_Results = new QGroupBox(centralwidget);
        groupBox_Results->setObjectName(QString::fromUtf8("groupBox_Results"));
        groupBox_Results->setEnabled(false);
        sizePolicy.setHeightForWidth(groupBox_Results->sizePolicy().hasHeightForWidth());
        groupBox_Results->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(groupBox_Results);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_SpacerForUndefinedTime = new QLabel(groupBox_Results);
        label_SpacerForUndefinedTime->setObjectName(QString::fromUtf8("label_SpacerForUndefinedTime"));

        gridLayout_4->addWidget(label_SpacerForUndefinedTime, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_Results, 0, 1, 1, 1);

        D_MAKRO_Osteoclasts->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_Osteoclasts);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 974, 21));
        menuData = new QMenu(menubar);
        menuData->setObjectName(QString::fromUtf8("menuData"));
        menuLayout = new QMenu(menubar);
        menuLayout->setObjectName(QString::fromUtf8("menuLayout"));
        menuViewer = new QMenu(menubar);
        menuViewer->setObjectName(QString::fromUtf8("menuViewer"));
        menuUpdate = new QMenu(menubar);
        menuUpdate->setObjectName(QString::fromUtf8("menuUpdate"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuPrompts = new QMenu(menubar);
        menuPrompts->setObjectName(QString::fromUtf8("menuPrompts"));
        D_MAKRO_Osteoclasts->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_Osteoclasts);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_Osteoclasts->setStatusBar(statusbar);

        menubar->addAction(menuData->menuAction());
        menubar->addAction(menuLayout->menuAction());
        menubar->addAction(menuViewer->menuAction());
        menubar->addAction(menuUpdate->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menubar->addAction(menuPrompts->menuAction());
        menuData->addAction(action_Load_Dataset);
        menuData->addAction(action_Clear_Dataset);
        menuLayout->addAction(action_Show_Proccessing);
        menuLayout->addAction(action_Show_Results);
        menuViewer->addAction(action_Smooth_Transformation);
        menuViewer->addAction(action_Keep_Aspect_Ratio);
        menuUpdate->addAction(action_Update_Views);
        menuWindow->addAction(action_Window_Minimize);
        menuWindow->addAction(action_Window_Normal);
        menuWindow->addAction(action_Window_Maximize);
        menuWindow->addAction(action_Window_Fullscreen);
        menuPrompts->addAction(action_Prompt_Load_Platelet_Dimension);
        menuPrompts->addAction(action_Prompt_Scan_Segmentations);

        retranslateUi(D_MAKRO_Osteoclasts);
        QObject::connect(action_Window_Fullscreen, SIGNAL(triggered()), D_MAKRO_Osteoclasts, SLOT(showFullScreen()));
        QObject::connect(action_Window_Maximize, SIGNAL(triggered()), D_MAKRO_Osteoclasts, SLOT(showMaximized()));
        QObject::connect(action_Window_Normal, SIGNAL(triggered()), D_MAKRO_Osteoclasts, SLOT(showNormal()));
        QObject::connect(action_Window_Minimize, SIGNAL(triggered()), D_MAKRO_Osteoclasts, SLOT(showMinimized()));
        QObject::connect(action_Show_Proccessing, SIGNAL(triggered(bool)), groupBox_Proc, SLOT(setVisible(bool)));
        QObject::connect(action_Show_Results, SIGNAL(triggered(bool)), groupBox_Results, SLOT(setVisible(bool)));

        tabWidget_Proc_Settings->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(D_MAKRO_Osteoclasts);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_Osteoclasts)
    {
        D_MAKRO_Osteoclasts->setWindowTitle(QApplication::translate("D_MAKRO_Osteoclasts", "MainWindow", nullptr));
        action_Load_Dataset->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Load Dataset", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Load_Dataset->setShortcut(QApplication::translate("D_MAKRO_Osteoclasts", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        action_Window_Minimize->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Minimize", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Window_Minimize->setShortcut(QApplication::translate("D_MAKRO_Osteoclasts", "F9", nullptr));
#endif // QT_NO_SHORTCUT
        action_Window_Normal->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Normal", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Window_Normal->setShortcut(QApplication::translate("D_MAKRO_Osteoclasts", "F10", nullptr));
#endif // QT_NO_SHORTCUT
        action_Window_Maximize->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Maximize", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Window_Maximize->setShortcut(QApplication::translate("D_MAKRO_Osteoclasts", "F11", nullptr));
#endif // QT_NO_SHORTCUT
        action_Window_Fullscreen->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Fullscreen", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Window_Fullscreen->setShortcut(QApplication::translate("D_MAKRO_Osteoclasts", "F12", nullptr));
#endif // QT_NO_SHORTCUT
        action_Update_Views->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Update Views", nullptr));
        action_Smooth_Transformation->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Smooth Transformation", nullptr));
        action_Keep_Aspect_Ratio->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Keep Aspect Ratio", nullptr));
        action_Clear_Dataset->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Clear Dataset", nullptr));
        action_Show_Proccessing->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Show Proccessing", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Proccessing->setShortcut(QApplication::translate("D_MAKRO_Osteoclasts", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        action_Show_Results->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Show Results", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Results->setShortcut(QApplication::translate("D_MAKRO_Osteoclasts", "F2", nullptr));
#endif // QT_NO_SHORTCUT
        action_Prompt_Load_Platelet_Dimension->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Load Platelet Dimension", nullptr));
        action_Prompt_Scan_Segmentations->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Scan Segmentations", nullptr));
        groupBox_Proc->setTitle(QApplication::translate("D_MAKRO_Osteoclasts", "Processing", nullptr));
        comboBox_Viewport->setItemText(0, QApplication::translate("D_MAKRO_Osteoclasts", "[viewport]", nullptr));

        label_Viewport->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Viewport", nullptr));
        label_VisVP_Channel->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Channel", nullptr));
        label_VisVP_ZProject_Type->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Projection-Typ:", nullptr));
        label_VisVP_ValAtCur->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Value@Cursor", nullptr));
        checkBox_VisVP_Auto->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Auto", nullptr));
        label_VisVP_Name_R->setText(QApplication::translate("D_MAKRO_Osteoclasts", "trap", nullptr));
        label_VisVP_Gamma->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Gamma", nullptr));
        checkBox_VisVP_ZProject_R->setText(QString());
        label_VisVP_ZProject->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Z-Projection", nullptr));
        label_VisVP_ValAtCur_R->setText(QApplication::translate("D_MAKRO_Osteoclasts", "r_val", nullptr));
        label_VisVP_ValAtCur_B->setText(QApplication::translate("D_MAKRO_Osteoclasts", "b_val", nullptr));
        label_VisVP_ValAtCur_G->setText(QApplication::translate("D_MAKRO_Osteoclasts", "g_val", nullptr));
        label_VisVP_Name_G->setText(QApplication::translate("D_MAKRO_Osteoclasts", "f-actin", nullptr));
        checkBox_VisVP_Show_B->setText(QApplication::translate("D_MAKRO_Osteoclasts", "B", nullptr));
        label_VisVP_Name_B->setText(QApplication::translate("D_MAKRO_Osteoclasts", "dapi", nullptr));
        checkBox_VisVP_Show_R->setText(QApplication::translate("D_MAKRO_Osteoclasts", "R", nullptr));
        label_VisVP_Range->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Range", nullptr));
        checkBox_VisVP_ZProject_G->setText(QString());
        checkBox_VisVP_ZProject_B->setText(QString());
        checkBox_VisVP_Show_G->setText(QApplication::translate("D_MAKRO_Osteoclasts", "G", nullptr));
        tabWidget_Proc_Settings->setTabText(tabWidget_Proc_Settings->indexOf(tab_VisVP), QApplication::translate("D_MAKRO_Osteoclasts", "Visualize Viewport", nullptr));
        label_SegAuto_Roundness_Parameter->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Thres", nullptr));
        label_SegAuto_Blur_Parameter->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Size/Sigma", nullptr));
        label_SegAuto_Watershed_Parameter->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Options", nullptr));
        label_SegAuto_Thres_Parameter->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Size/Offset", nullptr));
        checkBox_SegAuto_Watershed_Bordered->setText(QApplication::translate("D_MAKRO_Osteoclasts", "bordered", nullptr));
        checkBox_SegAuto_Watershed_nSeeded->setText(QApplication::translate("D_MAKRO_Osteoclasts", "not seeded", nullptr));
        label_SegAuto_Distance_Parameter->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Thres", nullptr));
        label_SegAuto_Blur_Description->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Gauss-Blur", nullptr));
        label_SegAuto_Thres_Description->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Niblack-Thres", nullptr));
        label_SegAuto_Distance_Description->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Distance", nullptr));
        label_SegAuto_Watershed_Description->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Watershed", nullptr));
        label_SegAuto_Blur_Position->setText(QApplication::translate("D_MAKRO_Osteoclasts", "x", nullptr));
        label_SegAuto_Roundness_Description->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Roundnes", nullptr));
        label_SegAuto_Thres_Position->setText(QApplication::translate("D_MAKRO_Osteoclasts", "x", nullptr));
        label_SegAuto_Distance_Position->setText(QApplication::translate("D_MAKRO_Osteoclasts", "x", nullptr));
        label_SegAuto_Watershed_Position->setText(QApplication::translate("D_MAKRO_Osteoclasts", "x", nullptr));
        label_SegAuto_Roundness_Position->setText(QApplication::translate("D_MAKRO_Osteoclasts", "x", nullptr));
        comboBox_SegAuto_Step->setItemText(0, QApplication::translate("D_MAKRO_Osteoclasts", "[nuclei proc steps]", nullptr));

        label_SegAuto_Area_Position->setText(QApplication::translate("D_MAKRO_Osteoclasts", "x", nullptr));
        label_SegAuto_Area_Parameter->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Interval", nullptr));
        label_SegAuto_Area_Description->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Area", nullptr));
        tabWidget_Proc_Settings->setTabText(tabWidget_Proc_Settings->indexOf(tab_SegAuto), QApplication::translate("D_MAKRO_Osteoclasts", "Segmentation Automatic", nullptr));
        comboBox_SegMan_Draw_Type->setItemText(0, QApplication::translate("D_MAKRO_Osteoclasts", "[line]", nullptr));

        pushButton_SegMan_Save->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Save", nullptr));
        pushButton_SegMan_Load->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Load", nullptr));
        lineEdit_SegMan_SaveLoad_Suffix->setText(QApplication::translate("D_MAKRO_Osteoclasts", "suffix", nullptr));
        pushButton_SegMan_NextSegmentation->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Next (Space)", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_SegMan_NextSegmentation->setShortcut(QApplication::translate("D_MAKRO_Osteoclasts", "Space", nullptr));
#endif // QT_NO_SHORTCUT
        comboBox_SegMan_SegmentationType->setItemText(0, QApplication::translate("D_MAKRO_Osteoclasts", "[segmentations]", nullptr));

        label_SegMan_NewLine_Description->setText(QApplication::translate("D_MAKRO_Osteoclasts", "R-Click -> new Line", nullptr));
        comboBox_SegMan_Draw_Color->setItemText(0, QApplication::translate("D_MAKRO_Osteoclasts", "[pencil]", nullptr));

        spinBox_SegMan_Line_Width->setSuffix(QApplication::translate("D_MAKRO_Osteoclasts", "px", nullptr));
        pushButton_SegMan_Undo->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Undo", nullptr));
        pushButton_SegMan_Reset->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Reset", nullptr));
        tabWidget_Proc_Settings->setTabText(tabWidget_Proc_Settings->indexOf(tab_SegMan), QApplication::translate("D_MAKRO_Osteoclasts", "Segmentation Manual", nullptr));
        groupBox_Results->setTitle(QApplication::translate("D_MAKRO_Osteoclasts", "Results", nullptr));
        label_SpacerForUndefinedTime->setText(QApplication::translate("D_MAKRO_Osteoclasts", "Just like BER Airport - to be finished in the future...", nullptr));
        menuData->setTitle(QApplication::translate("D_MAKRO_Osteoclasts", "Data", nullptr));
        menuLayout->setTitle(QApplication::translate("D_MAKRO_Osteoclasts", "Layout", nullptr));
        menuViewer->setTitle(QApplication::translate("D_MAKRO_Osteoclasts", "Viewer", nullptr));
        menuUpdate->setTitle(QApplication::translate("D_MAKRO_Osteoclasts", "Update", nullptr));
        menuWindow->setTitle(QApplication::translate("D_MAKRO_Osteoclasts", "Window", nullptr));
        menuPrompts->setTitle(QApplication::translate("D_MAKRO_Osteoclasts", "Prompts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_Osteoclasts: public Ui_D_MAKRO_Osteoclasts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_OSTEOCLASTS_H
