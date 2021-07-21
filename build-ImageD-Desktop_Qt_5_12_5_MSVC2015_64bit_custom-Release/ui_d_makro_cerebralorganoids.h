/********************************************************************************
** Form generated from reading UI file 'd_makro_cerebralorganoids.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_CEREBRALORGANOIDS_H
#define UI_D_MAKRO_CEREBRALORGANOIDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_CerebralOrganoids
{
public:
    QAction *action_Load_Data;
    QAction *action_Process_Stack;
    QAction *action_Save_Image_Processing;
    QAction *action_Save_Image_Visualization;
    QAction *action_Save_Table_Flask;
    QAction *action_Save_Table_Time_Dose;
    QAction *action_Save_Plot_Experiment;
    QAction *action_Save_Analysis;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_ProcView;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView_Proc;
    QComboBox *comboBox_Proc_Step;
    QGroupBox *groupBox_ProcSet;
    QGridLayout *gridLayout_4;
    QLabel *label_7;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_ProcSet_BlurSigma;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_25;
    QLabel *label_12;
    QSpinBox *spinBox_ProcSet_ColorSelect_S_Min;
    QLabel *label_13;
    QLabel *label_9;
    QLabel *label_14;
    QSpinBox *spinBox_ProcSet_ColorSelect_S_Max;
    QFrame *line_2;
    QFrame *line_3;
    QSpinBox *spinBox_ProcSet_BlurSize;
    QSpinBox *spinBox_ProcSet_ColorSelect_H_Min;
    QSpinBox *spinBox_ProcSet_ColorSelect_H_Max;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label_19;
    QLabel *label_20;
    QDoubleSpinBox *doubleSpinBox_ProcSet_PixelSize;
    QFrame *line;
    QSpinBox *spinBox_ProcSet_ColorSelect_V_Min;
    QLabel *label_18;
    QLabel *label_17;
    QSpinBox *spinBox_ProcSet_ColorSelect_V_Max;
    QFrame *line_4;
    QDoubleSpinBox *doubleSpinBox_ProcSet_SelectArea_Min;
    QDoubleSpinBox *doubleSpinBox_ProcSet_SelectRoundness_Min;
    QDoubleSpinBox *doubleSpinBox_ProcSet_SelectArea_Max;
    QDoubleSpinBox *doubleSpinBox_ProcSet_SelectRoundness_Max;
    QSpinBox *spinBox_ProcSet_ClosingSize;
    QSpinBox *spinBox_ProcSet_OpeningSize;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_ProcSet_Close;
    QLabel *label_ProcSet_Open;
    QLabel *label_ProcSet_Area;
    QLabel *label_28;
    QLabel *label_34;
    QLabel *label_40;
    QLabel *label_27;
    QSpinBox *spinBox_ProcSet_ROI_Dilate;
    QLabel *label_32;
    QLabel *label_31;
    QLabel *label_43;
    QLabel *label_30;
    QLabel *label_39;
    QLabel *label_33;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_29;
    QLabel *label_26;
    QSpinBox *spinBox_ProcSet_ROI_Close;
    QLabel *label_38;
    QSpinBox *spinBox_ProcSet_ROI_Open;
    QSpinBox *spinBox_ProcSet_ROI_Area;
    QDoubleSpinBox *doubleSpinBox_ProcSet_Thresh;
    QFrame *line_7;
    QFrame *line_6;
    QFrame *line_5;
    QGroupBox *groupBox_Data;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLabel *label;
    QComboBox *comboBox_Data_Flask;
    QComboBox *comboBox_Data_Time;
    QComboBox *comboBox_Data_Dose;
    QLabel *label_3;
    QTabWidget *tabWidget_Results;
    QWidget *tab_Vis;
    QGridLayout *gridLayout_5;
    QGraphicsView *graphicsView_Vis;
    QSpinBox *spinBox_Vis_Precision;
    QLabel *label_Vis_Precision;
    QComboBox *comboBox_VisFeat;
    QLabel *label_Vis_Feat;
    QLabel *label_Vis_Scale;
    QSpinBox *spinBox_Vis_Thickness;
    QLabel *label_Vis_Thickness;
    QDoubleSpinBox *doubleSpinBox_Vis_Scale;
    QWidget *tab_Flask;
    QGridLayout *gridLayout_7;
    QTableWidget *tableWidget_ResFlask;
    QComboBox *comboBox_ResFlask_Mode;
    QWidget *tab_TD;
    QGridLayout *gridLayout_6;
    QTableWidget *tableWidget_ResTD;
    QComboBox *comboBox_ResTD_Mode;
    QWidget *tab_Exp;
    QGridLayout *gridLayout_8;
    QLabel *label_36;
    QLabel *label_35;
    QComboBox *comboBox_ResExp_Stat_Line;
    QComboBox *comboBox_ResExp_Feat;
    QLabel *label_37;
    QComboBox *comboBox_ResExp_Stat_Errors;
    QGridLayout *gridLayout_ResExp;
    QComboBox *comboBox_ResExp_Mode;
    QMenuBar *menubar;
    QMenu *menuData;
    QMenu *menuStack;
    QMenu *menuSave;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_CerebralOrganoids)
    {
        if (D_MAKRO_CerebralOrganoids->objectName().isEmpty())
            D_MAKRO_CerebralOrganoids->setObjectName(QString::fromUtf8("D_MAKRO_CerebralOrganoids"));
        D_MAKRO_CerebralOrganoids->resize(1165, 873);
        action_Load_Data = new QAction(D_MAKRO_CerebralOrganoids);
        action_Load_Data->setObjectName(QString::fromUtf8("action_Load_Data"));
        action_Process_Stack = new QAction(D_MAKRO_CerebralOrganoids);
        action_Process_Stack->setObjectName(QString::fromUtf8("action_Process_Stack"));
        action_Save_Image_Processing = new QAction(D_MAKRO_CerebralOrganoids);
        action_Save_Image_Processing->setObjectName(QString::fromUtf8("action_Save_Image_Processing"));
        action_Save_Image_Visualization = new QAction(D_MAKRO_CerebralOrganoids);
        action_Save_Image_Visualization->setObjectName(QString::fromUtf8("action_Save_Image_Visualization"));
        action_Save_Table_Flask = new QAction(D_MAKRO_CerebralOrganoids);
        action_Save_Table_Flask->setObjectName(QString::fromUtf8("action_Save_Table_Flask"));
        action_Save_Table_Time_Dose = new QAction(D_MAKRO_CerebralOrganoids);
        action_Save_Table_Time_Dose->setObjectName(QString::fromUtf8("action_Save_Table_Time_Dose"));
        action_Save_Plot_Experiment = new QAction(D_MAKRO_CerebralOrganoids);
        action_Save_Plot_Experiment->setObjectName(QString::fromUtf8("action_Save_Plot_Experiment"));
        action_Save_Analysis = new QAction(D_MAKRO_CerebralOrganoids);
        action_Save_Analysis->setObjectName(QString::fromUtf8("action_Save_Analysis"));
        centralwidget = new QWidget(D_MAKRO_CerebralOrganoids);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_ProcView = new QGroupBox(centralwidget);
        groupBox_ProcView->setObjectName(QString::fromUtf8("groupBox_ProcView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_ProcView->sizePolicy().hasHeightForWidth());
        groupBox_ProcView->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox_ProcView);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphicsView_Proc = new QGraphicsView(groupBox_ProcView);
        graphicsView_Proc->setObjectName(QString::fromUtf8("graphicsView_Proc"));
        graphicsView_Proc->setMouseTracking(true);

        gridLayout_2->addWidget(graphicsView_Proc, 1, 0, 1, 1);

        comboBox_Proc_Step = new QComboBox(groupBox_ProcView);
        comboBox_Proc_Step->setObjectName(QString::fromUtf8("comboBox_Proc_Step"));

        gridLayout_2->addWidget(comboBox_Proc_Step, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_ProcView, 1, 0, 1, 1);

        groupBox_ProcSet = new QGroupBox(centralwidget);
        groupBox_ProcSet->setObjectName(QString::fromUtf8("groupBox_ProcSet"));
        sizePolicy.setHeightForWidth(groupBox_ProcSet->sizePolicy().hasHeightForWidth());
        groupBox_ProcSet->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(groupBox_ProcSet);
        gridLayout_4->setSpacing(3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(6, 6, 6, 6);
        label_7 = new QLabel(groupBox_ProcSet);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(100, 0));
        label_7->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(label_7, 4, 0, 3, 1);

        label_8 = new QLabel(groupBox_ProcSet);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(100, 0));
        label_8->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(label_8, 4, 1, 1, 1);

        doubleSpinBox_ProcSet_BlurSigma = new QDoubleSpinBox(groupBox_ProcSet);
        doubleSpinBox_ProcSet_BlurSigma->setObjectName(QString::fromUtf8("doubleSpinBox_ProcSet_BlurSigma"));
        doubleSpinBox_ProcSet_BlurSigma->setMinimumSize(QSize(50, 0));
        doubleSpinBox_ProcSet_BlurSigma->setMaximumSize(QSize(50, 16777215));
        doubleSpinBox_ProcSet_BlurSigma->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_ProcSet_BlurSigma->setValue(3.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_ProcSet_BlurSigma, 2, 3, 1, 1);

        label_15 = new QLabel(groupBox_ProcSet);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(100, 0));
        label_15->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(label_15, 11, 0, 1, 1);

        label_16 = new QLabel(groupBox_ProcSet);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(100, 0));
        label_16->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(label_16, 12, 0, 1, 1);

        label_25 = new QLabel(groupBox_ProcSet);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_4->addWidget(label_25, 14, 0, 1, 1);

        label_12 = new QLabel(groupBox_ProcSet);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(100, 0));
        label_12->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(label_12, 9, 0, 1, 1);

        spinBox_ProcSet_ColorSelect_S_Min = new QSpinBox(groupBox_ProcSet);
        spinBox_ProcSet_ColorSelect_S_Min->setObjectName(QString::fromUtf8("spinBox_ProcSet_ColorSelect_S_Min"));
        spinBox_ProcSet_ColorSelect_S_Min->setMinimumSize(QSize(50, 0));
        spinBox_ProcSet_ColorSelect_S_Min->setMaximumSize(QSize(50, 16777215));
        spinBox_ProcSet_ColorSelect_S_Min->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ProcSet_ColorSelect_S_Min->setMaximum(254);
        spinBox_ProcSet_ColorSelect_S_Min->setValue(45);

        gridLayout_4->addWidget(spinBox_ProcSet_ColorSelect_S_Min, 5, 2, 1, 1);

        label_13 = new QLabel(groupBox_ProcSet);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(100, 0));
        label_13->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(label_13, 8, 1, 1, 1);

        label_9 = new QLabel(groupBox_ProcSet);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(100, 0));
        label_9->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(label_9, 5, 1, 1, 1);

        label_14 = new QLabel(groupBox_ProcSet);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(100, 0));
        label_14->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(label_14, 9, 1, 1, 1);

        spinBox_ProcSet_ColorSelect_S_Max = new QSpinBox(groupBox_ProcSet);
        spinBox_ProcSet_ColorSelect_S_Max->setObjectName(QString::fromUtf8("spinBox_ProcSet_ColorSelect_S_Max"));
        spinBox_ProcSet_ColorSelect_S_Max->setMinimumSize(QSize(50, 0));
        spinBox_ProcSet_ColorSelect_S_Max->setMaximumSize(QSize(50, 16777215));
        spinBox_ProcSet_ColorSelect_S_Max->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ProcSet_ColorSelect_S_Max->setMinimum(1);
        spinBox_ProcSet_ColorSelect_S_Max->setMaximum(255);
        spinBox_ProcSet_ColorSelect_S_Max->setValue(150);

        gridLayout_4->addWidget(spinBox_ProcSet_ColorSelect_S_Max, 5, 3, 1, 1);

        line_2 = new QFrame(groupBox_ProcSet);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_2, 3, 0, 1, 5);

        line_3 = new QFrame(groupBox_ProcSet);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_3, 7, 0, 1, 5);

        spinBox_ProcSet_BlurSize = new QSpinBox(groupBox_ProcSet);
        spinBox_ProcSet_BlurSize->setObjectName(QString::fromUtf8("spinBox_ProcSet_BlurSize"));
        spinBox_ProcSet_BlurSize->setMinimumSize(QSize(50, 0));
        spinBox_ProcSet_BlurSize->setMaximumSize(QSize(50, 16777215));
        spinBox_ProcSet_BlurSize->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ProcSet_BlurSize->setMinimum(3);
        spinBox_ProcSet_BlurSize->setSingleStep(2);
        spinBox_ProcSet_BlurSize->setValue(7);

        gridLayout_4->addWidget(spinBox_ProcSet_BlurSize, 2, 2, 1, 1);

        spinBox_ProcSet_ColorSelect_H_Min = new QSpinBox(groupBox_ProcSet);
        spinBox_ProcSet_ColorSelect_H_Min->setObjectName(QString::fromUtf8("spinBox_ProcSet_ColorSelect_H_Min"));
        spinBox_ProcSet_ColorSelect_H_Min->setMinimumSize(QSize(50, 0));
        spinBox_ProcSet_ColorSelect_H_Min->setMaximumSize(QSize(50, 16777215));
        spinBox_ProcSet_ColorSelect_H_Min->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ProcSet_ColorSelect_H_Min->setMinimum(0);
        spinBox_ProcSet_ColorSelect_H_Min->setMaximum(254);
        spinBox_ProcSet_ColorSelect_H_Min->setValue(15);

        gridLayout_4->addWidget(spinBox_ProcSet_ColorSelect_H_Min, 4, 2, 1, 1);

        spinBox_ProcSet_ColorSelect_H_Max = new QSpinBox(groupBox_ProcSet);
        spinBox_ProcSet_ColorSelect_H_Max->setObjectName(QString::fromUtf8("spinBox_ProcSet_ColorSelect_H_Max"));
        spinBox_ProcSet_ColorSelect_H_Max->setMinimumSize(QSize(50, 0));
        spinBox_ProcSet_ColorSelect_H_Max->setMaximumSize(QSize(50, 16777215));
        spinBox_ProcSet_ColorSelect_H_Max->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ProcSet_ColorSelect_H_Max->setMinimum(1);
        spinBox_ProcSet_ColorSelect_H_Max->setMaximum(255);
        spinBox_ProcSet_ColorSelect_H_Max->setValue(50);

        gridLayout_4->addWidget(spinBox_ProcSet_ColorSelect_H_Max, 4, 3, 1, 1);

        label_4 = new QLabel(groupBox_ProcSet);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(100, 0));
        label_4->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(groupBox_ProcSet);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_4->addWidget(label_5, 2, 4, 1, 1);

        label_11 = new QLabel(groupBox_ProcSet);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(100, 0));
        label_11->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(label_11, 8, 0, 1, 1);

        label_10 = new QLabel(groupBox_ProcSet);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(100, 0));
        label_10->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(label_10, 6, 1, 1, 1);

        label_6 = new QLabel(groupBox_ProcSet);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(100, 0));
        label_6->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(label_6, 2, 1, 1, 1);

        label_19 = new QLabel(groupBox_ProcSet);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_4->addWidget(label_19, 0, 0, 1, 1);

        label_20 = new QLabel(groupBox_ProcSet);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMinimumSize(QSize(100, 0));
        label_20->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(label_20, 0, 1, 1, 1);

        doubleSpinBox_ProcSet_PixelSize = new QDoubleSpinBox(groupBox_ProcSet);
        doubleSpinBox_ProcSet_PixelSize->setObjectName(QString::fromUtf8("doubleSpinBox_ProcSet_PixelSize"));
        doubleSpinBox_ProcSet_PixelSize->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_ProcSet_PixelSize->setDecimals(6);
        doubleSpinBox_ProcSet_PixelSize->setSingleStep(0.001000000000000);
        doubleSpinBox_ProcSet_PixelSize->setValue(0.071600000000000);

        gridLayout_4->addWidget(doubleSpinBox_ProcSet_PixelSize, 0, 2, 1, 2);

        line = new QFrame(groupBox_ProcSet);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 1, 0, 1, 5);

        spinBox_ProcSet_ColorSelect_V_Min = new QSpinBox(groupBox_ProcSet);
        spinBox_ProcSet_ColorSelect_V_Min->setObjectName(QString::fromUtf8("spinBox_ProcSet_ColorSelect_V_Min"));
        spinBox_ProcSet_ColorSelect_V_Min->setMinimumSize(QSize(50, 0));
        spinBox_ProcSet_ColorSelect_V_Min->setMaximumSize(QSize(50, 16777215));
        spinBox_ProcSet_ColorSelect_V_Min->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ProcSet_ColorSelect_V_Min->setMaximum(254);
        spinBox_ProcSet_ColorSelect_V_Min->setValue(35);

        gridLayout_4->addWidget(spinBox_ProcSet_ColorSelect_V_Min, 6, 2, 1, 1);

        label_18 = new QLabel(groupBox_ProcSet);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMinimumSize(QSize(100, 0));
        label_18->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(label_18, 12, 1, 1, 1);

        label_17 = new QLabel(groupBox_ProcSet);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(100, 0));
        label_17->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(label_17, 11, 1, 1, 1);

        spinBox_ProcSet_ColorSelect_V_Max = new QSpinBox(groupBox_ProcSet);
        spinBox_ProcSet_ColorSelect_V_Max->setObjectName(QString::fromUtf8("spinBox_ProcSet_ColorSelect_V_Max"));
        spinBox_ProcSet_ColorSelect_V_Max->setMinimumSize(QSize(50, 0));
        spinBox_ProcSet_ColorSelect_V_Max->setMaximumSize(QSize(50, 16777215));
        spinBox_ProcSet_ColorSelect_V_Max->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ProcSet_ColorSelect_V_Max->setMinimum(1);
        spinBox_ProcSet_ColorSelect_V_Max->setMaximum(255);
        spinBox_ProcSet_ColorSelect_V_Max->setValue(140);

        gridLayout_4->addWidget(spinBox_ProcSet_ColorSelect_V_Max, 6, 3, 1, 1);

        line_4 = new QFrame(groupBox_ProcSet);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_4, 10, 0, 1, 5);

        doubleSpinBox_ProcSet_SelectArea_Min = new QDoubleSpinBox(groupBox_ProcSet);
        doubleSpinBox_ProcSet_SelectArea_Min->setObjectName(QString::fromUtf8("doubleSpinBox_ProcSet_SelectArea_Min"));
        doubleSpinBox_ProcSet_SelectArea_Min->setMinimumSize(QSize(50, 0));
        doubleSpinBox_ProcSet_SelectArea_Min->setMaximumSize(QSize(50, 16777215));
        doubleSpinBox_ProcSet_SelectArea_Min->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_ProcSet_SelectArea_Min->setDecimals(0);
        doubleSpinBox_ProcSet_SelectArea_Min->setMaximum(99999.000000000000000);
        doubleSpinBox_ProcSet_SelectArea_Min->setSingleStep(10.000000000000000);
        doubleSpinBox_ProcSet_SelectArea_Min->setValue(150.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_ProcSet_SelectArea_Min, 11, 2, 1, 1);

        doubleSpinBox_ProcSet_SelectRoundness_Min = new QDoubleSpinBox(groupBox_ProcSet);
        doubleSpinBox_ProcSet_SelectRoundness_Min->setObjectName(QString::fromUtf8("doubleSpinBox_ProcSet_SelectRoundness_Min"));
        doubleSpinBox_ProcSet_SelectRoundness_Min->setMinimumSize(QSize(50, 0));
        doubleSpinBox_ProcSet_SelectRoundness_Min->setMaximumSize(QSize(50, 16777215));
        doubleSpinBox_ProcSet_SelectRoundness_Min->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_ProcSet_SelectRoundness_Min->setDecimals(2);
        doubleSpinBox_ProcSet_SelectRoundness_Min->setMaximum(1.000000000000000);
        doubleSpinBox_ProcSet_SelectRoundness_Min->setValue(0.500000000000000);

        gridLayout_4->addWidget(doubleSpinBox_ProcSet_SelectRoundness_Min, 12, 2, 1, 1);

        doubleSpinBox_ProcSet_SelectArea_Max = new QDoubleSpinBox(groupBox_ProcSet);
        doubleSpinBox_ProcSet_SelectArea_Max->setObjectName(QString::fromUtf8("doubleSpinBox_ProcSet_SelectArea_Max"));
        doubleSpinBox_ProcSet_SelectArea_Max->setMinimumSize(QSize(50, 0));
        doubleSpinBox_ProcSet_SelectArea_Max->setMaximumSize(QSize(50, 16777215));
        doubleSpinBox_ProcSet_SelectArea_Max->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_ProcSet_SelectArea_Max->setDecimals(0);
        doubleSpinBox_ProcSet_SelectArea_Max->setMaximum(99999.000000000000000);
        doubleSpinBox_ProcSet_SelectArea_Max->setSingleStep(1000.000000000000000);
        doubleSpinBox_ProcSet_SelectArea_Max->setValue(20000.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_ProcSet_SelectArea_Max, 11, 3, 1, 1);

        doubleSpinBox_ProcSet_SelectRoundness_Max = new QDoubleSpinBox(groupBox_ProcSet);
        doubleSpinBox_ProcSet_SelectRoundness_Max->setObjectName(QString::fromUtf8("doubleSpinBox_ProcSet_SelectRoundness_Max"));
        doubleSpinBox_ProcSet_SelectRoundness_Max->setMinimumSize(QSize(50, 0));
        doubleSpinBox_ProcSet_SelectRoundness_Max->setMaximumSize(QSize(50, 16777215));
        doubleSpinBox_ProcSet_SelectRoundness_Max->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_ProcSet_SelectRoundness_Max->setDecimals(2);
        doubleSpinBox_ProcSet_SelectRoundness_Max->setMaximum(1.000000000000000);
        doubleSpinBox_ProcSet_SelectRoundness_Max->setValue(1.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_ProcSet_SelectRoundness_Max, 12, 3, 1, 1);

        spinBox_ProcSet_ClosingSize = new QSpinBox(groupBox_ProcSet);
        spinBox_ProcSet_ClosingSize->setObjectName(QString::fromUtf8("spinBox_ProcSet_ClosingSize"));
        spinBox_ProcSet_ClosingSize->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ProcSet_ClosingSize->setMinimum(1);
        spinBox_ProcSet_ClosingSize->setSingleStep(2);
        spinBox_ProcSet_ClosingSize->setValue(5);

        gridLayout_4->addWidget(spinBox_ProcSet_ClosingSize, 8, 2, 1, 2);

        spinBox_ProcSet_OpeningSize = new QSpinBox(groupBox_ProcSet);
        spinBox_ProcSet_OpeningSize->setObjectName(QString::fromUtf8("spinBox_ProcSet_OpeningSize"));
        spinBox_ProcSet_OpeningSize->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ProcSet_OpeningSize->setMinimum(1);
        spinBox_ProcSet_OpeningSize->setSingleStep(2);
        spinBox_ProcSet_OpeningSize->setValue(5);

        gridLayout_4->addWidget(spinBox_ProcSet_OpeningSize, 9, 2, 1, 2);

        label_21 = new QLabel(groupBox_ProcSet);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_4->addWidget(label_21, 0, 4, 1, 1);

        label_22 = new QLabel(groupBox_ProcSet);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_4->addWidget(label_22, 4, 4, 1, 1);

        label_23 = new QLabel(groupBox_ProcSet);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_4->addWidget(label_23, 5, 4, 1, 1);

        label_24 = new QLabel(groupBox_ProcSet);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_4->addWidget(label_24, 6, 4, 1, 1);

        label_ProcSet_Close = new QLabel(groupBox_ProcSet);
        label_ProcSet_Close->setObjectName(QString::fromUtf8("label_ProcSet_Close"));

        gridLayout_4->addWidget(label_ProcSet_Close, 8, 4, 1, 1);

        label_ProcSet_Open = new QLabel(groupBox_ProcSet);
        label_ProcSet_Open->setObjectName(QString::fromUtf8("label_ProcSet_Open"));

        gridLayout_4->addWidget(label_ProcSet_Open, 9, 4, 1, 1);

        label_ProcSet_Area = new QLabel(groupBox_ProcSet);
        label_ProcSet_Area->setObjectName(QString::fromUtf8("label_ProcSet_Area"));

        gridLayout_4->addWidget(label_ProcSet_Area, 11, 4, 1, 1);

        label_28 = new QLabel(groupBox_ProcSet);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_4->addWidget(label_28, 12, 4, 1, 1);

        label_34 = new QLabel(groupBox_ProcSet);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout_4->addWidget(label_34, 18, 0, 1, 1);

        label_40 = new QLabel(groupBox_ProcSet);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout_4->addWidget(label_40, 16, 4, 1, 1);

        label_27 = new QLabel(groupBox_ProcSet);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_4->addWidget(label_27, 16, 1, 1, 1);

        spinBox_ProcSet_ROI_Dilate = new QSpinBox(groupBox_ProcSet);
        spinBox_ProcSet_ROI_Dilate->setObjectName(QString::fromUtf8("spinBox_ProcSet_ROI_Dilate"));
        spinBox_ProcSet_ROI_Dilate->setMinimum(1);
        spinBox_ProcSet_ROI_Dilate->setMaximum(999);
        spinBox_ProcSet_ROI_Dilate->setSingleStep(2);
        spinBox_ProcSet_ROI_Dilate->setValue(11);

        gridLayout_4->addWidget(spinBox_ProcSet_ROI_Dilate, 20, 2, 1, 2);

        label_32 = new QLabel(groupBox_ProcSet);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_4->addWidget(label_32, 16, 0, 1, 1);

        label_31 = new QLabel(groupBox_ProcSet);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_4->addWidget(label_31, 20, 1, 1, 1);

        label_43 = new QLabel(groupBox_ProcSet);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        gridLayout_4->addWidget(label_43, 20, 4, 1, 1);

        label_30 = new QLabel(groupBox_ProcSet);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_4->addWidget(label_30, 18, 1, 1, 1);

        label_39 = new QLabel(groupBox_ProcSet);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        gridLayout_4->addWidget(label_39, 14, 4, 1, 1);

        label_33 = new QLabel(groupBox_ProcSet);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout_4->addWidget(label_33, 17, 0, 1, 1);

        label_41 = new QLabel(groupBox_ProcSet);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        gridLayout_4->addWidget(label_41, 17, 4, 1, 1);

        label_42 = new QLabel(groupBox_ProcSet);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        gridLayout_4->addWidget(label_42, 18, 4, 1, 1);

        label_29 = new QLabel(groupBox_ProcSet);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_4->addWidget(label_29, 17, 1, 1, 1);

        label_26 = new QLabel(groupBox_ProcSet);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_4->addWidget(label_26, 14, 1, 1, 1);

        spinBox_ProcSet_ROI_Close = new QSpinBox(groupBox_ProcSet);
        spinBox_ProcSet_ROI_Close->setObjectName(QString::fromUtf8("spinBox_ProcSet_ROI_Close"));
        spinBox_ProcSet_ROI_Close->setMinimum(1);
        spinBox_ProcSet_ROI_Close->setMaximum(999);
        spinBox_ProcSet_ROI_Close->setSingleStep(2);
        spinBox_ProcSet_ROI_Close->setValue(11);

        gridLayout_4->addWidget(spinBox_ProcSet_ROI_Close, 16, 2, 1, 2);

        label_38 = new QLabel(groupBox_ProcSet);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        gridLayout_4->addWidget(label_38, 20, 0, 1, 1);

        spinBox_ProcSet_ROI_Open = new QSpinBox(groupBox_ProcSet);
        spinBox_ProcSet_ROI_Open->setObjectName(QString::fromUtf8("spinBox_ProcSet_ROI_Open"));
        spinBox_ProcSet_ROI_Open->setMinimum(1);
        spinBox_ProcSet_ROI_Open->setMaximum(999);
        spinBox_ProcSet_ROI_Open->setSingleStep(2);
        spinBox_ProcSet_ROI_Open->setValue(31);

        gridLayout_4->addWidget(spinBox_ProcSet_ROI_Open, 17, 2, 1, 2);

        spinBox_ProcSet_ROI_Area = new QSpinBox(groupBox_ProcSet);
        spinBox_ProcSet_ROI_Area->setObjectName(QString::fromUtf8("spinBox_ProcSet_ROI_Area"));
        spinBox_ProcSet_ROI_Area->setMaximum(999999999);
        spinBox_ProcSet_ROI_Area->setSingleStep(2500);
        spinBox_ProcSet_ROI_Area->setValue(200000);

        gridLayout_4->addWidget(spinBox_ProcSet_ROI_Area, 18, 2, 1, 2);

        doubleSpinBox_ProcSet_Thresh = new QDoubleSpinBox(groupBox_ProcSet);
        doubleSpinBox_ProcSet_Thresh->setObjectName(QString::fromUtf8("doubleSpinBox_ProcSet_Thresh"));
        doubleSpinBox_ProcSet_Thresh->setDecimals(0);
        doubleSpinBox_ProcSet_Thresh->setMaximum(255.000000000000000);
        doubleSpinBox_ProcSet_Thresh->setValue(188.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_ProcSet_Thresh, 14, 2, 1, 2);

        line_7 = new QFrame(groupBox_ProcSet);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_7, 19, 0, 1, 5);

        line_6 = new QFrame(groupBox_ProcSet);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_6, 15, 0, 1, 5);

        line_5 = new QFrame(groupBox_ProcSet);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_5, 13, 0, 1, 5);


        gridLayout->addWidget(groupBox_ProcSet, 2, 0, 1, 1);

        groupBox_Data = new QGroupBox(centralwidget);
        groupBox_Data->setObjectName(QString::fromUtf8("groupBox_Data"));
        gridLayout_3 = new QGridLayout(groupBox_Data);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(groupBox_Data);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(groupBox_Data);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label, 0, 2, 1, 1);

        comboBox_Data_Flask = new QComboBox(groupBox_Data);
        comboBox_Data_Flask->setObjectName(QString::fromUtf8("comboBox_Data_Flask"));

        gridLayout_3->addWidget(comboBox_Data_Flask, 0, 5, 1, 1);

        comboBox_Data_Time = new QComboBox(groupBox_Data);
        comboBox_Data_Time->setObjectName(QString::fromUtf8("comboBox_Data_Time"));
        comboBox_Data_Time->setMinimumSize(QSize(50, 0));
        comboBox_Data_Time->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(comboBox_Data_Time, 0, 1, 1, 1);

        comboBox_Data_Dose = new QComboBox(groupBox_Data);
        comboBox_Data_Dose->setObjectName(QString::fromUtf8("comboBox_Data_Dose"));
        comboBox_Data_Dose->setMinimumSize(QSize(50, 0));
        comboBox_Data_Dose->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(comboBox_Data_Dose, 0, 3, 1, 1);

        label_3 = new QLabel(groupBox_Data);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_3, 0, 4, 1, 1);


        gridLayout->addWidget(groupBox_Data, 0, 0, 1, 1);

        tabWidget_Results = new QTabWidget(centralwidget);
        tabWidget_Results->setObjectName(QString::fromUtf8("tabWidget_Results"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget_Results->sizePolicy().hasHeightForWidth());
        tabWidget_Results->setSizePolicy(sizePolicy2);
        tab_Vis = new QWidget();
        tab_Vis->setObjectName(QString::fromUtf8("tab_Vis"));
        gridLayout_5 = new QGridLayout(tab_Vis);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        graphicsView_Vis = new QGraphicsView(tab_Vis);
        graphicsView_Vis->setObjectName(QString::fromUtf8("graphicsView_Vis"));
        graphicsView_Vis->setMouseTracking(true);

        gridLayout_5->addWidget(graphicsView_Vis, 1, 0, 1, 8);

        spinBox_Vis_Precision = new QSpinBox(tab_Vis);
        spinBox_Vis_Precision->setObjectName(QString::fromUtf8("spinBox_Vis_Precision"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spinBox_Vis_Precision->sizePolicy().hasHeightForWidth());
        spinBox_Vis_Precision->setSizePolicy(sizePolicy3);
        spinBox_Vis_Precision->setMinimum(1);
        spinBox_Vis_Precision->setMaximum(9);
        spinBox_Vis_Precision->setValue(3);

        gridLayout_5->addWidget(spinBox_Vis_Precision, 0, 7, 1, 1);

        label_Vis_Precision = new QLabel(tab_Vis);
        label_Vis_Precision->setObjectName(QString::fromUtf8("label_Vis_Precision"));
        sizePolicy1.setHeightForWidth(label_Vis_Precision->sizePolicy().hasHeightForWidth());
        label_Vis_Precision->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_Vis_Precision, 0, 6, 1, 1);

        comboBox_VisFeat = new QComboBox(tab_Vis);
        comboBox_VisFeat->setObjectName(QString::fromUtf8("comboBox_VisFeat"));

        gridLayout_5->addWidget(comboBox_VisFeat, 0, 1, 1, 1);

        label_Vis_Feat = new QLabel(tab_Vis);
        label_Vis_Feat->setObjectName(QString::fromUtf8("label_Vis_Feat"));
        sizePolicy1.setHeightForWidth(label_Vis_Feat->sizePolicy().hasHeightForWidth());
        label_Vis_Feat->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_Vis_Feat, 0, 0, 1, 1);

        label_Vis_Scale = new QLabel(tab_Vis);
        label_Vis_Scale->setObjectName(QString::fromUtf8("label_Vis_Scale"));
        sizePolicy1.setHeightForWidth(label_Vis_Scale->sizePolicy().hasHeightForWidth());
        label_Vis_Scale->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_Vis_Scale, 0, 4, 1, 1);

        spinBox_Vis_Thickness = new QSpinBox(tab_Vis);
        spinBox_Vis_Thickness->setObjectName(QString::fromUtf8("spinBox_Vis_Thickness"));
        sizePolicy3.setHeightForWidth(spinBox_Vis_Thickness->sizePolicy().hasHeightForWidth());
        spinBox_Vis_Thickness->setSizePolicy(sizePolicy3);
        spinBox_Vis_Thickness->setMinimum(1);
        spinBox_Vis_Thickness->setMaximum(9);
        spinBox_Vis_Thickness->setValue(2);

        gridLayout_5->addWidget(spinBox_Vis_Thickness, 0, 3, 1, 1);

        label_Vis_Thickness = new QLabel(tab_Vis);
        label_Vis_Thickness->setObjectName(QString::fromUtf8("label_Vis_Thickness"));
        sizePolicy1.setHeightForWidth(label_Vis_Thickness->sizePolicy().hasHeightForWidth());
        label_Vis_Thickness->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_Vis_Thickness, 0, 2, 1, 1);

        doubleSpinBox_Vis_Scale = new QDoubleSpinBox(tab_Vis);
        doubleSpinBox_Vis_Scale->setObjectName(QString::fromUtf8("doubleSpinBox_Vis_Scale"));
        sizePolicy3.setHeightForWidth(doubleSpinBox_Vis_Scale->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Vis_Scale->setSizePolicy(sizePolicy3);
        doubleSpinBox_Vis_Scale->setMinimum(1.000000000000000);
        doubleSpinBox_Vis_Scale->setMaximum(9.000000000000000);
        doubleSpinBox_Vis_Scale->setSingleStep(0.250000000000000);
        doubleSpinBox_Vis_Scale->setValue(2.750000000000000);

        gridLayout_5->addWidget(doubleSpinBox_Vis_Scale, 0, 5, 1, 1);

        tabWidget_Results->addTab(tab_Vis, QString());
        tab_Flask = new QWidget();
        tab_Flask->setObjectName(QString::fromUtf8("tab_Flask"));
        gridLayout_7 = new QGridLayout(tab_Flask);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        tableWidget_ResFlask = new QTableWidget(tab_Flask);
        tableWidget_ResFlask->setObjectName(QString::fromUtf8("tableWidget_ResFlask"));

        gridLayout_7->addWidget(tableWidget_ResFlask, 2, 0, 1, 6);

        comboBox_ResFlask_Mode = new QComboBox(tab_Flask);
        comboBox_ResFlask_Mode->setObjectName(QString::fromUtf8("comboBox_ResFlask_Mode"));

        gridLayout_7->addWidget(comboBox_ResFlask_Mode, 0, 0, 1, 6);

        tabWidget_Results->addTab(tab_Flask, QString());
        tab_TD = new QWidget();
        tab_TD->setObjectName(QString::fromUtf8("tab_TD"));
        gridLayout_6 = new QGridLayout(tab_TD);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        tableWidget_ResTD = new QTableWidget(tab_TD);
        tableWidget_ResTD->setObjectName(QString::fromUtf8("tableWidget_ResTD"));

        gridLayout_6->addWidget(tableWidget_ResTD, 1, 0, 1, 2);

        comboBox_ResTD_Mode = new QComboBox(tab_TD);
        comboBox_ResTD_Mode->setObjectName(QString::fromUtf8("comboBox_ResTD_Mode"));

        gridLayout_6->addWidget(comboBox_ResTD_Mode, 0, 0, 1, 2);

        tabWidget_Results->addTab(tab_TD, QString());
        tab_Exp = new QWidget();
        tab_Exp->setObjectName(QString::fromUtf8("tab_Exp"));
        gridLayout_8 = new QGridLayout(tab_Exp);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_36 = new QLabel(tab_Exp);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        sizePolicy1.setHeightForWidth(label_36->sizePolicy().hasHeightForWidth());
        label_36->setSizePolicy(sizePolicy1);

        gridLayout_8->addWidget(label_36, 1, 2, 1, 1);

        label_35 = new QLabel(tab_Exp);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        sizePolicy1.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy1);

        gridLayout_8->addWidget(label_35, 1, 0, 1, 1);

        comboBox_ResExp_Stat_Line = new QComboBox(tab_Exp);
        comboBox_ResExp_Stat_Line->setObjectName(QString::fromUtf8("comboBox_ResExp_Stat_Line"));

        gridLayout_8->addWidget(comboBox_ResExp_Stat_Line, 1, 3, 1, 1);

        comboBox_ResExp_Feat = new QComboBox(tab_Exp);
        comboBox_ResExp_Feat->setObjectName(QString::fromUtf8("comboBox_ResExp_Feat"));

        gridLayout_8->addWidget(comboBox_ResExp_Feat, 1, 1, 1, 1);

        label_37 = new QLabel(tab_Exp);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        sizePolicy1.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy1);

        gridLayout_8->addWidget(label_37, 1, 4, 1, 1);

        comboBox_ResExp_Stat_Errors = new QComboBox(tab_Exp);
        comboBox_ResExp_Stat_Errors->setObjectName(QString::fromUtf8("comboBox_ResExp_Stat_Errors"));

        gridLayout_8->addWidget(comboBox_ResExp_Stat_Errors, 1, 5, 1, 1);

        gridLayout_ResExp = new QGridLayout();
        gridLayout_ResExp->setObjectName(QString::fromUtf8("gridLayout_ResExp"));

        gridLayout_8->addLayout(gridLayout_ResExp, 2, 0, 1, 6);

        comboBox_ResExp_Mode = new QComboBox(tab_Exp);
        comboBox_ResExp_Mode->setObjectName(QString::fromUtf8("comboBox_ResExp_Mode"));

        gridLayout_8->addWidget(comboBox_ResExp_Mode, 0, 0, 1, 6);

        tabWidget_Results->addTab(tab_Exp, QString());

        gridLayout->addWidget(tabWidget_Results, 0, 1, 3, 1);

        D_MAKRO_CerebralOrganoids->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_CerebralOrganoids);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1165, 21));
        menuData = new QMenu(menubar);
        menuData->setObjectName(QString::fromUtf8("menuData"));
        menuStack = new QMenu(menubar);
        menuStack->setObjectName(QString::fromUtf8("menuStack"));
        menuSave = new QMenu(menubar);
        menuSave->setObjectName(QString::fromUtf8("menuSave"));
        D_MAKRO_CerebralOrganoids->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_CerebralOrganoids);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_CerebralOrganoids->setStatusBar(statusbar);

        menubar->addAction(menuData->menuAction());
        menubar->addAction(menuSave->menuAction());
        menubar->addAction(menuStack->menuAction());
        menuData->addAction(action_Load_Data);
        menuStack->addAction(action_Process_Stack);
        menuSave->addAction(action_Save_Image_Processing);
        menuSave->addAction(action_Save_Image_Visualization);
        menuSave->addSeparator();
        menuSave->addAction(action_Save_Table_Flask);
        menuSave->addAction(action_Save_Table_Time_Dose);
        menuSave->addSeparator();
        menuSave->addAction(action_Save_Plot_Experiment);
        menuSave->addSeparator();
        menuSave->addAction(action_Save_Analysis);

        retranslateUi(D_MAKRO_CerebralOrganoids);

        tabWidget_Results->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(D_MAKRO_CerebralOrganoids);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_CerebralOrganoids)
    {
        D_MAKRO_CerebralOrganoids->setWindowTitle(QApplication::translate("D_MAKRO_CerebralOrganoids", "MainWindow", nullptr));
        action_Load_Data->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Load Data", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Load_Data->setShortcut(QApplication::translate("D_MAKRO_CerebralOrganoids", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        action_Process_Stack->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Process Stack", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Process_Stack->setShortcut(QApplication::translate("D_MAKRO_CerebralOrganoids", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        action_Save_Image_Processing->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Save Image Processing", nullptr));
        action_Save_Image_Visualization->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Save Image Visualization", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Save_Image_Visualization->setShortcut(QApplication::translate("D_MAKRO_CerebralOrganoids", "Ctrl+F1", nullptr));
#endif // QT_NO_SHORTCUT
        action_Save_Table_Flask->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Save Table Flask", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Save_Table_Flask->setShortcut(QApplication::translate("D_MAKRO_CerebralOrganoids", "Ctrl+F2", nullptr));
#endif // QT_NO_SHORTCUT
        action_Save_Table_Time_Dose->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Save Table Time Dose", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Save_Table_Time_Dose->setShortcut(QApplication::translate("D_MAKRO_CerebralOrganoids", "Ctrl+F3", nullptr));
#endif // QT_NO_SHORTCUT
        action_Save_Plot_Experiment->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Save Plot Experiment", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Save_Plot_Experiment->setShortcut(QApplication::translate("D_MAKRO_CerebralOrganoids", "Ctrl+F4", nullptr));
#endif // QT_NO_SHORTCUT
        action_Save_Analysis->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Save Analysis", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Save_Analysis->setShortcut(QApplication::translate("D_MAKRO_CerebralOrganoids", "Ctrl+F5", nullptr));
#endif // QT_NO_SHORTCUT
        groupBox_ProcView->setTitle(QApplication::translate("D_MAKRO_CerebralOrganoids", "Image Processing Viewer", nullptr));
        groupBox_ProcSet->setTitle(QApplication::translate("D_MAKRO_CerebralOrganoids", "Image Processing Settings", nullptr));
        label_7->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "06 Color Select", nullptr));
        label_8->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Range Hue", nullptr));
        label_15->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "09 Area Select", nullptr));
        label_16->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "10 Roundness Select", nullptr));
        label_25->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "12 Binary", nullptr));
        label_12->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "08 Opening", nullptr));
        label_13->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Size", nullptr));
        label_9->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Range Saturation", nullptr));
        label_14->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Size", nullptr));
        spinBox_ProcSet_BlurSize->setSuffix(QApplication::translate("D_MAKRO_CerebralOrganoids", "px", nullptr));
        spinBox_ProcSet_BlurSize->setPrefix(QString());
        spinBox_ProcSet_ColorSelect_H_Min->setSuffix(QString());
        label_4->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "01 Blur", nullptr));
        label_5->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Remove noise, keep objects", nullptr));
        label_11->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "07 Closing", nullptr));
        label_10->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Range Value", nullptr));
        label_6->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Size/Sigma", nullptr));
        label_19->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "-- Pixelsize", nullptr));
        label_20->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Calibration factor", nullptr));
        doubleSpinBox_ProcSet_PixelSize->setSuffix(QApplication::translate("D_MAKRO_CerebralOrganoids", "mm", nullptr));
        label_18->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Range Roundness", nullptr));
        label_17->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Range Area", nullptr));
        doubleSpinBox_ProcSet_SelectArea_Min->setSuffix(QApplication::translate("D_MAKRO_CerebralOrganoids", "px", nullptr));
        doubleSpinBox_ProcSet_SelectArea_Max->setSuffix(QApplication::translate("D_MAKRO_CerebralOrganoids", "px", nullptr));
        spinBox_ProcSet_ClosingSize->setSuffix(QApplication::translate("D_MAKRO_CerebralOrganoids", "px", nullptr));
        spinBox_ProcSet_OpeningSize->setSuffix(QApplication::translate("D_MAKRO_CerebralOrganoids", "px", nullptr));
        label_21->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Pixel length in object space", nullptr));
        label_22->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Color Angle (Red, Yellow, Purple, ...)", nullptr));
        label_23->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Greyish vs. Intense Color", nullptr));
        label_24->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Dark vs. Bright", nullptr));
        label_ProcSet_Close->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Remove black noise, connect", nullptr));
        label_ProcSet_Open->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Remove white noise, separate", nullptr));
        label_ProcSet_Area->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Select X-Ymm\302\262", nullptr));
        label_28->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Select round", nullptr));
        label_34->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "15 Area Select", nullptr));
        label_40->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Exclude black noise", nullptr));
        label_27->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Size", nullptr));
        spinBox_ProcSet_ROI_Dilate->setSuffix(QApplication::translate("D_MAKRO_CerebralOrganoids", "px", nullptr));
        label_32->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "13 Closing", nullptr));
        label_31->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Size", nullptr));
        label_43->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Add a margin", nullptr));
        label_30->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Size", nullptr));
        label_39->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Binarize flask bottom area", nullptr));
        label_33->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "14 Opening", nullptr));
        label_41->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Exclude unwanted detected white objetcs", nullptr));
        label_42->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Exclude objects other than flask bottom", nullptr));
        label_29->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Size", nullptr));
        label_26->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Threshold", nullptr));
        spinBox_ProcSet_ROI_Close->setSuffix(QApplication::translate("D_MAKRO_CerebralOrganoids", "px", nullptr));
        label_38->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "16 Margin", nullptr));
        spinBox_ProcSet_ROI_Open->setSuffix(QApplication::translate("D_MAKRO_CerebralOrganoids", "px", nullptr));
        spinBox_ProcSet_ROI_Area->setSuffix(QApplication::translate("D_MAKRO_CerebralOrganoids", "px", nullptr));
        groupBox_Data->setTitle(QApplication::translate("D_MAKRO_CerebralOrganoids", "Data Selection (Processing)", nullptr));
        label_2->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Time", nullptr));
        label->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Dose", nullptr));
        label_3->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Flask", nullptr));
        label_Vis_Precision->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Precision", nullptr));
        label_Vis_Feat->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Feature", nullptr));
        label_Vis_Scale->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Scale", nullptr));
        label_Vis_Thickness->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Thickness", nullptr));
        tabWidget_Results->setTabText(tabWidget_Results->indexOf(tab_Vis), QApplication::translate("D_MAKRO_CerebralOrganoids", "Visualization", nullptr));
        tabWidget_Results->setTabText(tabWidget_Results->indexOf(tab_Flask), QApplication::translate("D_MAKRO_CerebralOrganoids", "Single Flask", nullptr));
        tabWidget_Results->setTabText(tabWidget_Results->indexOf(tab_TD), QApplication::translate("D_MAKRO_CerebralOrganoids", "Fix Time and Dose", nullptr));
        label_36->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Statistic (Line)", nullptr));
        label_35->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Feature", nullptr));
        label_37->setText(QApplication::translate("D_MAKRO_CerebralOrganoids", "Statistic (Errors)", nullptr));
        tabWidget_Results->setTabText(tabWidget_Results->indexOf(tab_Exp), QApplication::translate("D_MAKRO_CerebralOrganoids", "Whole Experiment", nullptr));
        menuData->setTitle(QApplication::translate("D_MAKRO_CerebralOrganoids", "Load", nullptr));
        menuStack->setTitle(QApplication::translate("D_MAKRO_CerebralOrganoids", "Stack", nullptr));
        menuSave->setTitle(QApplication::translate("D_MAKRO_CerebralOrganoids", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_CerebralOrganoids: public Ui_D_MAKRO_CerebralOrganoids {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_CEREBRALORGANOIDS_H
