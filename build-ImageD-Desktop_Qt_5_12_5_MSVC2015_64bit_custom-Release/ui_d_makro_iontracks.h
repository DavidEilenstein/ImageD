/********************************************************************************
** Form generated from reading UI file 'd_makro_iontracks.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_IONTRACKS_H
#define UI_D_MAKRO_IONTRACKS_H

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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_IonTracks
{
public:
    QAction *action_Minimize;
    QAction *action_Normal;
    QAction *action_Maximize;
    QAction *action_Fullscreen;
    QAction *action_Update_Views;
    QAction *action_Smooth_Transformation;
    QAction *action_Keep_Aspect_Ratio;
    QAction *action_Show_Dimensions;
    QAction *action_Show_Processing;
    QAction *action_Show_Results;
    QAction *action_Open_Files;
    QAction *action_Clear_Queue;
    QAction *action_Save_Table;
    QAction *action_Save_Plot;
    QAction *action_Save_Analysis;
    QAction *action_Update_Processing;
    QAction *action_Block_Processing_Update;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_ProcView;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox_ProcView_Depth;
    QGraphicsView *graphicsView_ProcView;
    QLabel *label_ProcView_Type_MA;
    QLabel *label_ProcView_Type_QI;
    QComboBox *comboBox_ProcView_ProcStep;
    QComboBox *comboBox_ProcView_Lateral;
    QGroupBox *groupBox_Dimension;
    QGridLayout *gridLayout_3;
    QSpinBox *spinBox_Dimension_Dimension_Y_Lateral;
    QSpinBox *spinBox_Dimension_Dimension_Z_Depth;
    QDoubleSpinBox *doubleSpinBox_Dimension_Step_Z_Depth;
    QLabel *label_Dimension_Title_Y_Lateral;
    QLabel *label_Dimension_Title_X_Lateral;
    QDoubleSpinBox *doubleSpinBox_Dimension_Step_X_Lateral;
    QSpinBox *spinBox_Dimension_Dimension_X_Lateral;
    QDoubleSpinBox *doubleSpinBox_Dimension_Step_Y_Lateral;
    QLabel *label_Dimension_Dimension;
    QLabel *label_Dimension_Title_Z_Depth;
    QLabel *label_Dimension_Step;
    QLabel *label_Dimension_Size_X_Lateral;
    QLineEdit *lineEdit_Dimension_Unit;
    QLabel *label_Dimension_Size_Y_Lateral;
    QLabel *label_Dimension_Size_Z_Depth;
    QLabel *label_Dimension_Size;
    QGroupBox *groupBox_CurAna;
    QGridLayout *gridLayout_4;
    QComboBox *comboBox_CurAna_DataSet;
    QGroupBox *groupBox_ProcSet;
    QGridLayout *gridLayout_5;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_ProcSet_Binarization_Thres;
    QDoubleSpinBox *doubleSpinBox_ProcSet_Blur_Sigma;
    QSpinBox *spinBox_ProcSet_Blur_Size;
    QLabel *label_ProcSet_Blur_Description;
    QLabel *label_ProcSet_Thres_Description;
    QLabel *label_ProcSet_Thres_Titel;
    QLabel *label_ProcSet_Blur_Titel;
    QLabel *label_9;
    QFrame *line;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_ProcSet_ExConn_MinSphere;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_ProcSet_ExLarge_MaxArea;
    QSpinBox *spinBox_ProcSet_SafetyDist_MinRadius;
    QLabel *label_6;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_ProcSet_ExAsphere_MinSphere;
    QLabel *label_2;
    QLabel *label;
    QFrame *line_2;
    QDoubleSpinBox *doubleSpinBox_ProcSet_TOI_RelRadius;
    QTabWidget *tabWidget_Results;
    QWidget *tab_ResImg;
    QGridLayout *gridLayout_12;
    QCheckBox *checkBox_ResImg_Edge_B;
    QComboBox *comboBox_ResImg_Lateral;
    QComboBox *comboBox_ResImg_G;
    QLabel *label_ResImg_B;
    QLabel *label_ResImg_G;
    QGraphicsView *graphicsView_ResImg;
    QComboBox *comboBox_ResImg_Depth;
    QComboBox *comboBox_ResImg_B;
    QCheckBox *checkBox_ResImg_Edge_G;
    QWidget *tab_ResTab;
    QGridLayout *gridLayout_11;
    QComboBox *comboBox_ResTab_StatSingle;
    QTableWidget *tableWidget_ResTab;
    QGridLayout *gridLayout_ResTab_TabDef;
    QComboBox *comboBox_ResTab_Depth;
    QComboBox *comboBox_ResTab_Type;
    QComboBox *comboBox_ResTab_Group;
    QComboBox *comboBox_ResTab_Lateral;
    QWidget *tab_ResPlo;
    QGridLayout *gridLayout_7;
    QLabel *label_ResPlo_X;
    QStackedWidget *stackedWidget_ResPlo_Type;
    QWidget *page_ResPlo_StatAtRadius;
    QGridLayout *gridLayout_6;
    QComboBox *comboBox_ResPlo_SaR_StatTracks;
    QWidget *page_ResPlo_MeanSD;
    QGridLayout *gridLayout_8;
    QLabel *label_ResPlo_MeanSD_Description_1;
    QWidget *page_ResPlo_MedianAMD;
    QGridLayout *gridLayout_9;
    QLabel *label_ResPlo_MedianAMD_Description_1;
    QWidget *page_ResPlo_Quantiles;
    QGridLayout *gridLayout_10;
    QLabel *label_ResPlo_Quantiles_Description_1;
    QWidget *page_ResPlo_StatAtRadius_Grp;
    QGridLayout *gridLayout_13;
    QComboBox *comboBox_ResPlo_Grp_SaR_StatTracks;
    QComboBox *comboBox_ResPlo_StatSingle;
    QLabel *label_ResPlo_Description_2;
    QLabel *label_ResPlo_Description_1;
    QFrame *line_ResPlo_1;
    QComboBox *comboBox_ResPlo_AxeTrans_X;
    QComboBox *comboBox_ResPlo_AxeTrans_Y;
    QGridLayout *gridLayout_ResPlo;
    QCheckBox *checkBox_ResPlo_DisplayPoints;
    QLabel *label_ResPlo_Y;
    QFrame *line_ResPlo_2;
    QGridLayout *gridLayout_ResPlo_PlotDef;
    QComboBox *comboBox_ResPlo_Group;
    QComboBox *comboBox_ResPlo_Type;
    QComboBox *comboBox_ResPlo_Lateral;
    QComboBox *comboBox_ResPlo_Depth;
    QMenuBar *menubar;
    QMenu *menuData;
    QMenu *menuLayout;
    QMenu *menuViewer;
    QMenu *menuUpdate;
    QMenu *menuWindow;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_IonTracks)
    {
        if (D_MAKRO_IonTracks->objectName().isEmpty())
            D_MAKRO_IonTracks->setObjectName(QString::fromUtf8("D_MAKRO_IonTracks"));
        D_MAKRO_IonTracks->resize(1283, 866);
        action_Minimize = new QAction(D_MAKRO_IonTracks);
        action_Minimize->setObjectName(QString::fromUtf8("action_Minimize"));
        action_Normal = new QAction(D_MAKRO_IonTracks);
        action_Normal->setObjectName(QString::fromUtf8("action_Normal"));
        action_Maximize = new QAction(D_MAKRO_IonTracks);
        action_Maximize->setObjectName(QString::fromUtf8("action_Maximize"));
        action_Fullscreen = new QAction(D_MAKRO_IonTracks);
        action_Fullscreen->setObjectName(QString::fromUtf8("action_Fullscreen"));
        action_Update_Views = new QAction(D_MAKRO_IonTracks);
        action_Update_Views->setObjectName(QString::fromUtf8("action_Update_Views"));
        action_Smooth_Transformation = new QAction(D_MAKRO_IonTracks);
        action_Smooth_Transformation->setObjectName(QString::fromUtf8("action_Smooth_Transformation"));
        action_Smooth_Transformation->setCheckable(true);
        action_Smooth_Transformation->setChecked(true);
        action_Keep_Aspect_Ratio = new QAction(D_MAKRO_IonTracks);
        action_Keep_Aspect_Ratio->setObjectName(QString::fromUtf8("action_Keep_Aspect_Ratio"));
        action_Keep_Aspect_Ratio->setCheckable(true);
        action_Keep_Aspect_Ratio->setChecked(true);
        action_Show_Dimensions = new QAction(D_MAKRO_IonTracks);
        action_Show_Dimensions->setObjectName(QString::fromUtf8("action_Show_Dimensions"));
        action_Show_Dimensions->setCheckable(true);
        action_Show_Dimensions->setChecked(true);
        action_Show_Processing = new QAction(D_MAKRO_IonTracks);
        action_Show_Processing->setObjectName(QString::fromUtf8("action_Show_Processing"));
        action_Show_Processing->setCheckable(true);
        action_Show_Processing->setChecked(true);
        action_Show_Results = new QAction(D_MAKRO_IonTracks);
        action_Show_Results->setObjectName(QString::fromUtf8("action_Show_Results"));
        action_Show_Results->setCheckable(true);
        action_Show_Results->setChecked(true);
        action_Open_Files = new QAction(D_MAKRO_IonTracks);
        action_Open_Files->setObjectName(QString::fromUtf8("action_Open_Files"));
        action_Clear_Queue = new QAction(D_MAKRO_IonTracks);
        action_Clear_Queue->setObjectName(QString::fromUtf8("action_Clear_Queue"));
        action_Save_Table = new QAction(D_MAKRO_IonTracks);
        action_Save_Table->setObjectName(QString::fromUtf8("action_Save_Table"));
        action_Save_Plot = new QAction(D_MAKRO_IonTracks);
        action_Save_Plot->setObjectName(QString::fromUtf8("action_Save_Plot"));
        action_Save_Analysis = new QAction(D_MAKRO_IonTracks);
        action_Save_Analysis->setObjectName(QString::fromUtf8("action_Save_Analysis"));
        action_Update_Processing = new QAction(D_MAKRO_IonTracks);
        action_Update_Processing->setObjectName(QString::fromUtf8("action_Update_Processing"));
        action_Block_Processing_Update = new QAction(D_MAKRO_IonTracks);
        action_Block_Processing_Update->setObjectName(QString::fromUtf8("action_Block_Processing_Update"));
        action_Block_Processing_Update->setCheckable(true);
        centralwidget = new QWidget(D_MAKRO_IonTracks);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_ProcView = new QGroupBox(centralwidget);
        groupBox_ProcView->setObjectName(QString::fromUtf8("groupBox_ProcView"));
        groupBox_ProcView->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_ProcView->sizePolicy().hasHeightForWidth());
        groupBox_ProcView->setSizePolicy(sizePolicy);
        groupBox_ProcView->setFlat(true);
        gridLayout_2 = new QGridLayout(groupBox_ProcView);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(6, 6, 6, 6);
        comboBox_ProcView_Depth = new QComboBox(groupBox_ProcView);
        comboBox_ProcView_Depth->setObjectName(QString::fromUtf8("comboBox_ProcView_Depth"));

        gridLayout_2->addWidget(comboBox_ProcView_Depth, 0, 1, 1, 1);

        graphicsView_ProcView = new QGraphicsView(groupBox_ProcView);
        graphicsView_ProcView->setObjectName(QString::fromUtf8("graphicsView_ProcView"));
        graphicsView_ProcView->setMouseTracking(true);

        gridLayout_2->addWidget(graphicsView_ProcView, 1, 0, 1, 5);

        label_ProcView_Type_MA = new QLabel(groupBox_ProcView);
        label_ProcView_Type_MA->setObjectName(QString::fromUtf8("label_ProcView_Type_MA"));
        label_ProcView_Type_MA->setMinimumSize(QSize(50, 0));
        label_ProcView_Type_MA->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(label_ProcView_Type_MA, 0, 4, 1, 1);

        label_ProcView_Type_QI = new QLabel(groupBox_ProcView);
        label_ProcView_Type_QI->setObjectName(QString::fromUtf8("label_ProcView_Type_QI"));
        label_ProcView_Type_QI->setMinimumSize(QSize(50, 0));
        label_ProcView_Type_QI->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(label_ProcView_Type_QI, 0, 3, 1, 1);

        comboBox_ProcView_ProcStep = new QComboBox(groupBox_ProcView);
        comboBox_ProcView_ProcStep->setObjectName(QString::fromUtf8("comboBox_ProcView_ProcStep"));

        gridLayout_2->addWidget(comboBox_ProcView_ProcStep, 0, 2, 1, 1);

        comboBox_ProcView_Lateral = new QComboBox(groupBox_ProcView);
        comboBox_ProcView_Lateral->setObjectName(QString::fromUtf8("comboBox_ProcView_Lateral"));

        gridLayout_2->addWidget(comboBox_ProcView_Lateral, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_ProcView, 2, 0, 1, 1);

        groupBox_Dimension = new QGroupBox(centralwidget);
        groupBox_Dimension->setObjectName(QString::fromUtf8("groupBox_Dimension"));
        groupBox_Dimension->setFlat(true);
        gridLayout_3 = new QGridLayout(groupBox_Dimension);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(6, 6, 6, 6);
        spinBox_Dimension_Dimension_Y_Lateral = new QSpinBox(groupBox_Dimension);
        spinBox_Dimension_Dimension_Y_Lateral->setObjectName(QString::fromUtf8("spinBox_Dimension_Dimension_Y_Lateral"));
        sizePolicy.setHeightForWidth(spinBox_Dimension_Dimension_Y_Lateral->sizePolicy().hasHeightForWidth());
        spinBox_Dimension_Dimension_Y_Lateral->setSizePolicy(sizePolicy);
        spinBox_Dimension_Dimension_Y_Lateral->setMaximum(1000);
        spinBox_Dimension_Dimension_Y_Lateral->setValue(2);

        gridLayout_3->addWidget(spinBox_Dimension_Dimension_Y_Lateral, 1, 2, 1, 1);

        spinBox_Dimension_Dimension_Z_Depth = new QSpinBox(groupBox_Dimension);
        spinBox_Dimension_Dimension_Z_Depth->setObjectName(QString::fromUtf8("spinBox_Dimension_Dimension_Z_Depth"));
        sizePolicy.setHeightForWidth(spinBox_Dimension_Dimension_Z_Depth->sizePolicy().hasHeightForWidth());
        spinBox_Dimension_Dimension_Z_Depth->setSizePolicy(sizePolicy);
        spinBox_Dimension_Dimension_Z_Depth->setMinimum(1);
        spinBox_Dimension_Dimension_Z_Depth->setMaximum(1000);
        spinBox_Dimension_Dimension_Z_Depth->setValue(20);

        gridLayout_3->addWidget(spinBox_Dimension_Dimension_Z_Depth, 1, 3, 1, 1);

        doubleSpinBox_Dimension_Step_Z_Depth = new QDoubleSpinBox(groupBox_Dimension);
        doubleSpinBox_Dimension_Step_Z_Depth->setObjectName(QString::fromUtf8("doubleSpinBox_Dimension_Step_Z_Depth"));
        sizePolicy.setHeightForWidth(doubleSpinBox_Dimension_Step_Z_Depth->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Dimension_Step_Z_Depth->setSizePolicy(sizePolicy);
        doubleSpinBox_Dimension_Step_Z_Depth->setDecimals(3);
        doubleSpinBox_Dimension_Step_Z_Depth->setMinimum(0.001000000000000);
        doubleSpinBox_Dimension_Step_Z_Depth->setMaximum(1000.000000000000000);
        doubleSpinBox_Dimension_Step_Z_Depth->setValue(5.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_Dimension_Step_Z_Depth, 2, 3, 1, 1);

        label_Dimension_Title_Y_Lateral = new QLabel(groupBox_Dimension);
        label_Dimension_Title_Y_Lateral->setObjectName(QString::fromUtf8("label_Dimension_Title_Y_Lateral"));
        sizePolicy.setHeightForWidth(label_Dimension_Title_Y_Lateral->sizePolicy().hasHeightForWidth());
        label_Dimension_Title_Y_Lateral->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_Dimension_Title_Y_Lateral, 0, 2, 1, 1);

        label_Dimension_Title_X_Lateral = new QLabel(groupBox_Dimension);
        label_Dimension_Title_X_Lateral->setObjectName(QString::fromUtf8("label_Dimension_Title_X_Lateral"));
        sizePolicy.setHeightForWidth(label_Dimension_Title_X_Lateral->sizePolicy().hasHeightForWidth());
        label_Dimension_Title_X_Lateral->setSizePolicy(sizePolicy);
        label_Dimension_Title_X_Lateral->setMinimumSize(QSize(0, 0));
        label_Dimension_Title_X_Lateral->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(label_Dimension_Title_X_Lateral, 0, 1, 1, 1);

        doubleSpinBox_Dimension_Step_X_Lateral = new QDoubleSpinBox(groupBox_Dimension);
        doubleSpinBox_Dimension_Step_X_Lateral->setObjectName(QString::fromUtf8("doubleSpinBox_Dimension_Step_X_Lateral"));
        sizePolicy.setHeightForWidth(doubleSpinBox_Dimension_Step_X_Lateral->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Dimension_Step_X_Lateral->setSizePolicy(sizePolicy);
        doubleSpinBox_Dimension_Step_X_Lateral->setDecimals(3);
        doubleSpinBox_Dimension_Step_X_Lateral->setMinimum(0.001000000000000);
        doubleSpinBox_Dimension_Step_X_Lateral->setMaximum(1000.000000000000000);
        doubleSpinBox_Dimension_Step_X_Lateral->setValue(100.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_Dimension_Step_X_Lateral, 2, 1, 1, 1);

        spinBox_Dimension_Dimension_X_Lateral = new QSpinBox(groupBox_Dimension);
        spinBox_Dimension_Dimension_X_Lateral->setObjectName(QString::fromUtf8("spinBox_Dimension_Dimension_X_Lateral"));
        sizePolicy.setHeightForWidth(spinBox_Dimension_Dimension_X_Lateral->sizePolicy().hasHeightForWidth());
        spinBox_Dimension_Dimension_X_Lateral->setSizePolicy(sizePolicy);
        spinBox_Dimension_Dimension_X_Lateral->setMinimum(1);
        spinBox_Dimension_Dimension_X_Lateral->setMaximum(1000);
        spinBox_Dimension_Dimension_X_Lateral->setValue(2);

        gridLayout_3->addWidget(spinBox_Dimension_Dimension_X_Lateral, 1, 1, 1, 1);

        doubleSpinBox_Dimension_Step_Y_Lateral = new QDoubleSpinBox(groupBox_Dimension);
        doubleSpinBox_Dimension_Step_Y_Lateral->setObjectName(QString::fromUtf8("doubleSpinBox_Dimension_Step_Y_Lateral"));
        sizePolicy.setHeightForWidth(doubleSpinBox_Dimension_Step_Y_Lateral->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Dimension_Step_Y_Lateral->setSizePolicy(sizePolicy);
        doubleSpinBox_Dimension_Step_Y_Lateral->setDecimals(3);
        doubleSpinBox_Dimension_Step_Y_Lateral->setMinimum(0.001000000000000);
        doubleSpinBox_Dimension_Step_Y_Lateral->setMaximum(1000.000000000000000);
        doubleSpinBox_Dimension_Step_Y_Lateral->setValue(100.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_Dimension_Step_Y_Lateral, 2, 2, 1, 1);

        label_Dimension_Dimension = new QLabel(groupBox_Dimension);
        label_Dimension_Dimension->setObjectName(QString::fromUtf8("label_Dimension_Dimension"));
        sizePolicy.setHeightForWidth(label_Dimension_Dimension->sizePolicy().hasHeightForWidth());
        label_Dimension_Dimension->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_Dimension_Dimension, 1, 0, 1, 1);

        label_Dimension_Title_Z_Depth = new QLabel(groupBox_Dimension);
        label_Dimension_Title_Z_Depth->setObjectName(QString::fromUtf8("label_Dimension_Title_Z_Depth"));
        sizePolicy.setHeightForWidth(label_Dimension_Title_Z_Depth->sizePolicy().hasHeightForWidth());
        label_Dimension_Title_Z_Depth->setSizePolicy(sizePolicy);
        label_Dimension_Title_Z_Depth->setMinimumSize(QSize(0, 0));
        label_Dimension_Title_Z_Depth->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(label_Dimension_Title_Z_Depth, 0, 3, 1, 1);

        label_Dimension_Step = new QLabel(groupBox_Dimension);
        label_Dimension_Step->setObjectName(QString::fromUtf8("label_Dimension_Step"));
        sizePolicy.setHeightForWidth(label_Dimension_Step->sizePolicy().hasHeightForWidth());
        label_Dimension_Step->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_Dimension_Step, 2, 0, 1, 1);

        label_Dimension_Size_X_Lateral = new QLabel(groupBox_Dimension);
        label_Dimension_Size_X_Lateral->setObjectName(QString::fromUtf8("label_Dimension_Size_X_Lateral"));
        sizePolicy.setHeightForWidth(label_Dimension_Size_X_Lateral->sizePolicy().hasHeightForWidth());
        label_Dimension_Size_X_Lateral->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_Dimension_Size_X_Lateral, 3, 1, 1, 1);

        lineEdit_Dimension_Unit = new QLineEdit(groupBox_Dimension);
        lineEdit_Dimension_Unit->setObjectName(QString::fromUtf8("lineEdit_Dimension_Unit"));
        sizePolicy.setHeightForWidth(lineEdit_Dimension_Unit->sizePolicy().hasHeightForWidth());
        lineEdit_Dimension_Unit->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(lineEdit_Dimension_Unit, 0, 0, 1, 1);

        label_Dimension_Size_Y_Lateral = new QLabel(groupBox_Dimension);
        label_Dimension_Size_Y_Lateral->setObjectName(QString::fromUtf8("label_Dimension_Size_Y_Lateral"));
        sizePolicy.setHeightForWidth(label_Dimension_Size_Y_Lateral->sizePolicy().hasHeightForWidth());
        label_Dimension_Size_Y_Lateral->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_Dimension_Size_Y_Lateral, 3, 2, 1, 1);

        label_Dimension_Size_Z_Depth = new QLabel(groupBox_Dimension);
        label_Dimension_Size_Z_Depth->setObjectName(QString::fromUtf8("label_Dimension_Size_Z_Depth"));
        sizePolicy.setHeightForWidth(label_Dimension_Size_Z_Depth->sizePolicy().hasHeightForWidth());
        label_Dimension_Size_Z_Depth->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_Dimension_Size_Z_Depth, 3, 3, 1, 1);

        label_Dimension_Size = new QLabel(groupBox_Dimension);
        label_Dimension_Size->setObjectName(QString::fromUtf8("label_Dimension_Size"));
        sizePolicy.setHeightForWidth(label_Dimension_Size->sizePolicy().hasHeightForWidth());
        label_Dimension_Size->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_Dimension_Size, 3, 0, 1, 1);


        gridLayout->addWidget(groupBox_Dimension, 0, 0, 1, 1);

        groupBox_CurAna = new QGroupBox(centralwidget);
        groupBox_CurAna->setObjectName(QString::fromUtf8("groupBox_CurAna"));
        groupBox_CurAna->setEnabled(false);
        groupBox_CurAna->setFlat(true);
        gridLayout_4 = new QGridLayout(groupBox_CurAna);
        gridLayout_4->setSpacing(3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(6, 6, 6, 6);
        comboBox_CurAna_DataSet = new QComboBox(groupBox_CurAna);
        comboBox_CurAna_DataSet->setObjectName(QString::fromUtf8("comboBox_CurAna_DataSet"));

        gridLayout_4->addWidget(comboBox_CurAna_DataSet, 0, 0, 1, 2);


        gridLayout->addWidget(groupBox_CurAna, 1, 0, 1, 1);

        groupBox_ProcSet = new QGroupBox(centralwidget);
        groupBox_ProcSet->setObjectName(QString::fromUtf8("groupBox_ProcSet"));
        groupBox_ProcSet->setEnabled(false);
        sizePolicy.setHeightForWidth(groupBox_ProcSet->sizePolicy().hasHeightForWidth());
        groupBox_ProcSet->setSizePolicy(sizePolicy);
        groupBox_ProcSet->setFlat(true);
        gridLayout_5 = new QGridLayout(groupBox_ProcSet);
        gridLayout_5->setSpacing(3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(6, 6, 6, 6);
        label_10 = new QLabel(groupBox_ProcSet);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setEnabled(false);

        gridLayout_5->addWidget(label_10, 8, 3, 1, 1);

        doubleSpinBox_ProcSet_Binarization_Thres = new QDoubleSpinBox(groupBox_ProcSet);
        doubleSpinBox_ProcSet_Binarization_Thres->setObjectName(QString::fromUtf8("doubleSpinBox_ProcSet_Binarization_Thres"));
        doubleSpinBox_ProcSet_Binarization_Thres->setDecimals(3);
        doubleSpinBox_ProcSet_Binarization_Thres->setMaximum(10000.000000000000000);
        doubleSpinBox_ProcSet_Binarization_Thres->setSingleStep(0.010000000000000);
        doubleSpinBox_ProcSet_Binarization_Thres->setValue(1.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_ProcSet_Binarization_Thres, 1, 1, 1, 2);

        doubleSpinBox_ProcSet_Blur_Sigma = new QDoubleSpinBox(groupBox_ProcSet);
        doubleSpinBox_ProcSet_Blur_Sigma->setObjectName(QString::fromUtf8("doubleSpinBox_ProcSet_Blur_Sigma"));
        doubleSpinBox_ProcSet_Blur_Sigma->setMaximum(10000.000000000000000);
        doubleSpinBox_ProcSet_Blur_Sigma->setValue(3.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_ProcSet_Blur_Sigma, 0, 2, 1, 1);

        spinBox_ProcSet_Blur_Size = new QSpinBox(groupBox_ProcSet);
        spinBox_ProcSet_Blur_Size->setObjectName(QString::fromUtf8("spinBox_ProcSet_Blur_Size"));
        spinBox_ProcSet_Blur_Size->setMinimum(1);
        spinBox_ProcSet_Blur_Size->setMaximum(10001);
        spinBox_ProcSet_Blur_Size->setValue(5);

        gridLayout_5->addWidget(spinBox_ProcSet_Blur_Size, 0, 1, 1, 1);

        label_ProcSet_Blur_Description = new QLabel(groupBox_ProcSet);
        label_ProcSet_Blur_Description->setObjectName(QString::fromUtf8("label_ProcSet_Blur_Description"));

        gridLayout_5->addWidget(label_ProcSet_Blur_Description, 0, 3, 1, 1);

        label_ProcSet_Thres_Description = new QLabel(groupBox_ProcSet);
        label_ProcSet_Thres_Description->setObjectName(QString::fromUtf8("label_ProcSet_Thres_Description"));

        gridLayout_5->addWidget(label_ProcSet_Thres_Description, 1, 3, 1, 1);

        label_ProcSet_Thres_Titel = new QLabel(groupBox_ProcSet);
        label_ProcSet_Thres_Titel->setObjectName(QString::fromUtf8("label_ProcSet_Thres_Titel"));

        gridLayout_5->addWidget(label_ProcSet_Thres_Titel, 1, 0, 1, 1);

        label_ProcSet_Blur_Titel = new QLabel(groupBox_ProcSet);
        label_ProcSet_Blur_Titel->setObjectName(QString::fromUtf8("label_ProcSet_Blur_Titel"));

        gridLayout_5->addWidget(label_ProcSet_Blur_Titel, 0, 0, 1, 1);

        label_9 = new QLabel(groupBox_ProcSet);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setEnabled(false);

        gridLayout_5->addWidget(label_9, 8, 0, 1, 1);

        line = new QFrame(groupBox_ProcSet);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line, 2, 0, 1, 4);

        label_8 = new QLabel(groupBox_ProcSet);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_5->addWidget(label_8, 7, 3, 1, 1);

        label_4 = new QLabel(groupBox_ProcSet);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_5->addWidget(label_4, 4, 0, 1, 1);

        label_3 = new QLabel(groupBox_ProcSet);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_5->addWidget(label_3, 4, 3, 1, 1);

        doubleSpinBox_ProcSet_ExConn_MinSphere = new QDoubleSpinBox(groupBox_ProcSet);
        doubleSpinBox_ProcSet_ExConn_MinSphere->setObjectName(QString::fromUtf8("doubleSpinBox_ProcSet_ExConn_MinSphere"));
        doubleSpinBox_ProcSet_ExConn_MinSphere->setDecimals(3);
        doubleSpinBox_ProcSet_ExConn_MinSphere->setMaximum(1.000000000000000);
        doubleSpinBox_ProcSet_ExConn_MinSphere->setSingleStep(0.005000000000000);
        doubleSpinBox_ProcSet_ExConn_MinSphere->setValue(0.800000000000000);

        gridLayout_5->addWidget(doubleSpinBox_ProcSet_ExConn_MinSphere, 7, 1, 1, 2);

        label_7 = new QLabel(groupBox_ProcSet);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_5->addWidget(label_7, 7, 0, 1, 1);

        doubleSpinBox_ProcSet_ExLarge_MaxArea = new QDoubleSpinBox(groupBox_ProcSet);
        doubleSpinBox_ProcSet_ExLarge_MaxArea->setObjectName(QString::fromUtf8("doubleSpinBox_ProcSet_ExLarge_MaxArea"));
        doubleSpinBox_ProcSet_ExLarge_MaxArea->setMaximum(10000000.000000000000000);
        doubleSpinBox_ProcSet_ExLarge_MaxArea->setValue(85.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_ProcSet_ExLarge_MaxArea, 3, 1, 1, 2);

        spinBox_ProcSet_SafetyDist_MinRadius = new QSpinBox(groupBox_ProcSet);
        spinBox_ProcSet_SafetyDist_MinRadius->setObjectName(QString::fromUtf8("spinBox_ProcSet_SafetyDist_MinRadius"));
        spinBox_ProcSet_SafetyDist_MinRadius->setMinimum(1);
        spinBox_ProcSet_SafetyDist_MinRadius->setMaximum(999);
        spinBox_ProcSet_SafetyDist_MinRadius->setValue(15);

        gridLayout_5->addWidget(spinBox_ProcSet_SafetyDist_MinRadius, 6, 1, 1, 2);

        label_6 = new QLabel(groupBox_ProcSet);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_5->addWidget(label_6, 6, 0, 1, 1);

        label_5 = new QLabel(groupBox_ProcSet);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_5->addWidget(label_5, 6, 3, 1, 1);

        doubleSpinBox_ProcSet_ExAsphere_MinSphere = new QDoubleSpinBox(groupBox_ProcSet);
        doubleSpinBox_ProcSet_ExAsphere_MinSphere->setObjectName(QString::fromUtf8("doubleSpinBox_ProcSet_ExAsphere_MinSphere"));
        doubleSpinBox_ProcSet_ExAsphere_MinSphere->setDecimals(3);
        doubleSpinBox_ProcSet_ExAsphere_MinSphere->setMaximum(1.000000000000000);
        doubleSpinBox_ProcSet_ExAsphere_MinSphere->setSingleStep(0.005000000000000);
        doubleSpinBox_ProcSet_ExAsphere_MinSphere->setValue(0.500000000000000);

        gridLayout_5->addWidget(doubleSpinBox_ProcSet_ExAsphere_MinSphere, 4, 1, 1, 2);

        label_2 = new QLabel(groupBox_ProcSet);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_5->addWidget(label_2, 3, 0, 1, 1);

        label = new QLabel(groupBox_ProcSet);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 3, 3, 1, 1);

        line_2 = new QFrame(groupBox_ProcSet);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_2, 5, 0, 1, 4);

        doubleSpinBox_ProcSet_TOI_RelRadius = new QDoubleSpinBox(groupBox_ProcSet);
        doubleSpinBox_ProcSet_TOI_RelRadius->setObjectName(QString::fromUtf8("doubleSpinBox_ProcSet_TOI_RelRadius"));
        doubleSpinBox_ProcSet_TOI_RelRadius->setEnabled(false);
        doubleSpinBox_ProcSet_TOI_RelRadius->setDecimals(0);
        doubleSpinBox_ProcSet_TOI_RelRadius->setMaximum(100.000000000000000);
        doubleSpinBox_ProcSet_TOI_RelRadius->setValue(100.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_ProcSet_TOI_RelRadius, 8, 1, 1, 2);


        gridLayout->addWidget(groupBox_ProcSet, 3, 0, 1, 1);

        tabWidget_Results = new QTabWidget(centralwidget);
        tabWidget_Results->setObjectName(QString::fromUtf8("tabWidget_Results"));
        tabWidget_Results->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget_Results->sizePolicy().hasHeightForWidth());
        tabWidget_Results->setSizePolicy(sizePolicy1);
        tab_ResImg = new QWidget();
        tab_ResImg->setObjectName(QString::fromUtf8("tab_ResImg"));
        gridLayout_12 = new QGridLayout(tab_ResImg);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        checkBox_ResImg_Edge_B = new QCheckBox(tab_ResImg);
        checkBox_ResImg_Edge_B->setObjectName(QString::fromUtf8("checkBox_ResImg_Edge_B"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(checkBox_ResImg_Edge_B->sizePolicy().hasHeightForWidth());
        checkBox_ResImg_Edge_B->setSizePolicy(sizePolicy2);
        checkBox_ResImg_Edge_B->setChecked(true);

        gridLayout_12->addWidget(checkBox_ResImg_Edge_B, 1, 5, 1, 1);

        comboBox_ResImg_Lateral = new QComboBox(tab_ResImg);
        comboBox_ResImg_Lateral->setObjectName(QString::fromUtf8("comboBox_ResImg_Lateral"));

        gridLayout_12->addWidget(comboBox_ResImg_Lateral, 0, 0, 1, 3);

        comboBox_ResImg_G = new QComboBox(tab_ResImg);
        comboBox_ResImg_G->setObjectName(QString::fromUtf8("comboBox_ResImg_G"));

        gridLayout_12->addWidget(comboBox_ResImg_G, 1, 1, 1, 1);

        label_ResImg_B = new QLabel(tab_ResImg);
        label_ResImg_B->setObjectName(QString::fromUtf8("label_ResImg_B"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_ResImg_B->sizePolicy().hasHeightForWidth());
        label_ResImg_B->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(label_ResImg_B, 1, 3, 1, 1);

        label_ResImg_G = new QLabel(tab_ResImg);
        label_ResImg_G->setObjectName(QString::fromUtf8("label_ResImg_G"));
        sizePolicy3.setHeightForWidth(label_ResImg_G->sizePolicy().hasHeightForWidth());
        label_ResImg_G->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(label_ResImg_G, 1, 0, 1, 1);

        graphicsView_ResImg = new QGraphicsView(tab_ResImg);
        graphicsView_ResImg->setObjectName(QString::fromUtf8("graphicsView_ResImg"));
        graphicsView_ResImg->setMouseTracking(true);

        gridLayout_12->addWidget(graphicsView_ResImg, 2, 0, 1, 6);

        comboBox_ResImg_Depth = new QComboBox(tab_ResImg);
        comboBox_ResImg_Depth->setObjectName(QString::fromUtf8("comboBox_ResImg_Depth"));

        gridLayout_12->addWidget(comboBox_ResImg_Depth, 0, 3, 1, 3);

        comboBox_ResImg_B = new QComboBox(tab_ResImg);
        comboBox_ResImg_B->setObjectName(QString::fromUtf8("comboBox_ResImg_B"));

        gridLayout_12->addWidget(comboBox_ResImg_B, 1, 4, 1, 1);

        checkBox_ResImg_Edge_G = new QCheckBox(tab_ResImg);
        checkBox_ResImg_Edge_G->setObjectName(QString::fromUtf8("checkBox_ResImg_Edge_G"));
        sizePolicy2.setHeightForWidth(checkBox_ResImg_Edge_G->sizePolicy().hasHeightForWidth());
        checkBox_ResImg_Edge_G->setSizePolicy(sizePolicy2);
        checkBox_ResImg_Edge_G->setChecked(true);

        gridLayout_12->addWidget(checkBox_ResImg_Edge_G, 1, 2, 1, 1);

        tabWidget_Results->addTab(tab_ResImg, QString());
        tab_ResTab = new QWidget();
        tab_ResTab->setObjectName(QString::fromUtf8("tab_ResTab"));
        gridLayout_11 = new QGridLayout(tab_ResTab);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        comboBox_ResTab_StatSingle = new QComboBox(tab_ResTab);
        comboBox_ResTab_StatSingle->setObjectName(QString::fromUtf8("comboBox_ResTab_StatSingle"));

        gridLayout_11->addWidget(comboBox_ResTab_StatSingle, 1, 0, 1, 2);

        tableWidget_ResTab = new QTableWidget(tab_ResTab);
        tableWidget_ResTab->setObjectName(QString::fromUtf8("tableWidget_ResTab"));

        gridLayout_11->addWidget(tableWidget_ResTab, 2, 0, 1, 2);

        gridLayout_ResTab_TabDef = new QGridLayout();
        gridLayout_ResTab_TabDef->setObjectName(QString::fromUtf8("gridLayout_ResTab_TabDef"));
        comboBox_ResTab_Depth = new QComboBox(tab_ResTab);
        comboBox_ResTab_Depth->setObjectName(QString::fromUtf8("comboBox_ResTab_Depth"));
        comboBox_ResTab_Depth->setEnabled(false);

        gridLayout_ResTab_TabDef->addWidget(comboBox_ResTab_Depth, 0, 3, 1, 1);

        comboBox_ResTab_Type = new QComboBox(tab_ResTab);
        comboBox_ResTab_Type->setObjectName(QString::fromUtf8("comboBox_ResTab_Type"));

        gridLayout_ResTab_TabDef->addWidget(comboBox_ResTab_Type, 0, 0, 1, 1);

        comboBox_ResTab_Group = new QComboBox(tab_ResTab);
        comboBox_ResTab_Group->setObjectName(QString::fromUtf8("comboBox_ResTab_Group"));

        gridLayout_ResTab_TabDef->addWidget(comboBox_ResTab_Group, 0, 1, 1, 1);

        comboBox_ResTab_Lateral = new QComboBox(tab_ResTab);
        comboBox_ResTab_Lateral->setObjectName(QString::fromUtf8("comboBox_ResTab_Lateral"));
        comboBox_ResTab_Lateral->setEnabled(false);

        gridLayout_ResTab_TabDef->addWidget(comboBox_ResTab_Lateral, 0, 2, 1, 1);


        gridLayout_11->addLayout(gridLayout_ResTab_TabDef, 0, 0, 1, 2);

        tabWidget_Results->addTab(tab_ResTab, QString());
        tab_ResPlo = new QWidget();
        tab_ResPlo->setObjectName(QString::fromUtf8("tab_ResPlo"));
        gridLayout_7 = new QGridLayout(tab_ResPlo);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_ResPlo_X = new QLabel(tab_ResPlo);
        label_ResPlo_X->setObjectName(QString::fromUtf8("label_ResPlo_X"));

        gridLayout_7->addWidget(label_ResPlo_X, 1, 5, 1, 1);

        stackedWidget_ResPlo_Type = new QStackedWidget(tab_ResPlo);
        stackedWidget_ResPlo_Type->setObjectName(QString::fromUtf8("stackedWidget_ResPlo_Type"));
        sizePolicy.setHeightForWidth(stackedWidget_ResPlo_Type->sizePolicy().hasHeightForWidth());
        stackedWidget_ResPlo_Type->setSizePolicy(sizePolicy);
        stackedWidget_ResPlo_Type->setMaximumSize(QSize(16777215, 20));
        page_ResPlo_StatAtRadius = new QWidget();
        page_ResPlo_StatAtRadius->setObjectName(QString::fromUtf8("page_ResPlo_StatAtRadius"));
        gridLayout_6 = new QGridLayout(page_ResPlo_StatAtRadius);
        gridLayout_6->setSpacing(3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        comboBox_ResPlo_SaR_StatTracks = new QComboBox(page_ResPlo_StatAtRadius);
        comboBox_ResPlo_SaR_StatTracks->setObjectName(QString::fromUtf8("comboBox_ResPlo_SaR_StatTracks"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(comboBox_ResPlo_SaR_StatTracks->sizePolicy().hasHeightForWidth());
        comboBox_ResPlo_SaR_StatTracks->setSizePolicy(sizePolicy4);

        gridLayout_6->addWidget(comboBox_ResPlo_SaR_StatTracks, 0, 0, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_ResPlo_StatAtRadius);
        page_ResPlo_MeanSD = new QWidget();
        page_ResPlo_MeanSD->setObjectName(QString::fromUtf8("page_ResPlo_MeanSD"));
        gridLayout_8 = new QGridLayout(page_ResPlo_MeanSD);
        gridLayout_8->setSpacing(3);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        label_ResPlo_MeanSD_Description_1 = new QLabel(page_ResPlo_MeanSD);
        label_ResPlo_MeanSD_Description_1->setObjectName(QString::fromUtf8("label_ResPlo_MeanSD_Description_1"));

        gridLayout_8->addWidget(label_ResPlo_MeanSD_Description_1, 0, 0, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_ResPlo_MeanSD);
        page_ResPlo_MedianAMD = new QWidget();
        page_ResPlo_MedianAMD->setObjectName(QString::fromUtf8("page_ResPlo_MedianAMD"));
        gridLayout_9 = new QGridLayout(page_ResPlo_MedianAMD);
        gridLayout_9->setSpacing(3);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        label_ResPlo_MedianAMD_Description_1 = new QLabel(page_ResPlo_MedianAMD);
        label_ResPlo_MedianAMD_Description_1->setObjectName(QString::fromUtf8("label_ResPlo_MedianAMD_Description_1"));

        gridLayout_9->addWidget(label_ResPlo_MedianAMD_Description_1, 0, 0, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_ResPlo_MedianAMD);
        page_ResPlo_Quantiles = new QWidget();
        page_ResPlo_Quantiles->setObjectName(QString::fromUtf8("page_ResPlo_Quantiles"));
        gridLayout_10 = new QGridLayout(page_ResPlo_Quantiles);
        gridLayout_10->setSpacing(3);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        label_ResPlo_Quantiles_Description_1 = new QLabel(page_ResPlo_Quantiles);
        label_ResPlo_Quantiles_Description_1->setObjectName(QString::fromUtf8("label_ResPlo_Quantiles_Description_1"));

        gridLayout_10->addWidget(label_ResPlo_Quantiles_Description_1, 0, 0, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_ResPlo_Quantiles);
        page_ResPlo_StatAtRadius_Grp = new QWidget();
        page_ResPlo_StatAtRadius_Grp->setObjectName(QString::fromUtf8("page_ResPlo_StatAtRadius_Grp"));
        gridLayout_13 = new QGridLayout(page_ResPlo_StatAtRadius_Grp);
        gridLayout_13->setSpacing(3);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        comboBox_ResPlo_Grp_SaR_StatTracks = new QComboBox(page_ResPlo_StatAtRadius_Grp);
        comboBox_ResPlo_Grp_SaR_StatTracks->setObjectName(QString::fromUtf8("comboBox_ResPlo_Grp_SaR_StatTracks"));

        gridLayout_13->addWidget(comboBox_ResPlo_Grp_SaR_StatTracks, 0, 0, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_ResPlo_StatAtRadius_Grp);

        gridLayout_7->addWidget(stackedWidget_ResPlo_Type, 1, 0, 1, 1);

        comboBox_ResPlo_StatSingle = new QComboBox(tab_ResPlo);
        comboBox_ResPlo_StatSingle->setObjectName(QString::fromUtf8("comboBox_ResPlo_StatSingle"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(comboBox_ResPlo_StatSingle->sizePolicy().hasHeightForWidth());
        comboBox_ResPlo_StatSingle->setSizePolicy(sizePolicy5);

        gridLayout_7->addWidget(comboBox_ResPlo_StatSingle, 1, 2, 1, 1);

        label_ResPlo_Description_2 = new QLabel(tab_ResPlo);
        label_ResPlo_Description_2->setObjectName(QString::fromUtf8("label_ResPlo_Description_2"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_ResPlo_Description_2->sizePolicy().hasHeightForWidth());
        label_ResPlo_Description_2->setSizePolicy(sizePolicy6);

        gridLayout_7->addWidget(label_ResPlo_Description_2, 1, 3, 1, 1);

        label_ResPlo_Description_1 = new QLabel(tab_ResPlo);
        label_ResPlo_Description_1->setObjectName(QString::fromUtf8("label_ResPlo_Description_1"));
        sizePolicy6.setHeightForWidth(label_ResPlo_Description_1->sizePolicy().hasHeightForWidth());
        label_ResPlo_Description_1->setSizePolicy(sizePolicy6);

        gridLayout_7->addWidget(label_ResPlo_Description_1, 1, 1, 1, 1);

        line_ResPlo_1 = new QFrame(tab_ResPlo);
        line_ResPlo_1->setObjectName(QString::fromUtf8("line_ResPlo_1"));
        line_ResPlo_1->setFrameShape(QFrame::VLine);
        line_ResPlo_1->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_ResPlo_1, 1, 4, 1, 1);

        comboBox_ResPlo_AxeTrans_X = new QComboBox(tab_ResPlo);
        comboBox_ResPlo_AxeTrans_X->setObjectName(QString::fromUtf8("comboBox_ResPlo_AxeTrans_X"));

        gridLayout_7->addWidget(comboBox_ResPlo_AxeTrans_X, 1, 6, 1, 1);

        comboBox_ResPlo_AxeTrans_Y = new QComboBox(tab_ResPlo);
        comboBox_ResPlo_AxeTrans_Y->setObjectName(QString::fromUtf8("comboBox_ResPlo_AxeTrans_Y"));

        gridLayout_7->addWidget(comboBox_ResPlo_AxeTrans_Y, 1, 8, 1, 1);

        gridLayout_ResPlo = new QGridLayout();
        gridLayout_ResPlo->setObjectName(QString::fromUtf8("gridLayout_ResPlo"));

        gridLayout_7->addLayout(gridLayout_ResPlo, 2, 0, 1, 11);

        checkBox_ResPlo_DisplayPoints = new QCheckBox(tab_ResPlo);
        checkBox_ResPlo_DisplayPoints->setObjectName(QString::fromUtf8("checkBox_ResPlo_DisplayPoints"));
        checkBox_ResPlo_DisplayPoints->setChecked(true);

        gridLayout_7->addWidget(checkBox_ResPlo_DisplayPoints, 1, 10, 1, 1);

        label_ResPlo_Y = new QLabel(tab_ResPlo);
        label_ResPlo_Y->setObjectName(QString::fromUtf8("label_ResPlo_Y"));

        gridLayout_7->addWidget(label_ResPlo_Y, 1, 7, 1, 1);

        line_ResPlo_2 = new QFrame(tab_ResPlo);
        line_ResPlo_2->setObjectName(QString::fromUtf8("line_ResPlo_2"));
        line_ResPlo_2->setFrameShape(QFrame::VLine);
        line_ResPlo_2->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_ResPlo_2, 1, 9, 1, 1);

        gridLayout_ResPlo_PlotDef = new QGridLayout();
        gridLayout_ResPlo_PlotDef->setObjectName(QString::fromUtf8("gridLayout_ResPlo_PlotDef"));
        gridLayout_ResPlo_PlotDef->setSizeConstraint(QLayout::SetDefaultConstraint);
        comboBox_ResPlo_Group = new QComboBox(tab_ResPlo);
        comboBox_ResPlo_Group->setObjectName(QString::fromUtf8("comboBox_ResPlo_Group"));

        gridLayout_ResPlo_PlotDef->addWidget(comboBox_ResPlo_Group, 0, 1, 1, 1);

        comboBox_ResPlo_Type = new QComboBox(tab_ResPlo);
        comboBox_ResPlo_Type->setObjectName(QString::fromUtf8("comboBox_ResPlo_Type"));

        gridLayout_ResPlo_PlotDef->addWidget(comboBox_ResPlo_Type, 0, 0, 1, 1);

        comboBox_ResPlo_Lateral = new QComboBox(tab_ResPlo);
        comboBox_ResPlo_Lateral->setObjectName(QString::fromUtf8("comboBox_ResPlo_Lateral"));
        comboBox_ResPlo_Lateral->setEnabled(false);

        gridLayout_ResPlo_PlotDef->addWidget(comboBox_ResPlo_Lateral, 0, 2, 1, 1);

        comboBox_ResPlo_Depth = new QComboBox(tab_ResPlo);
        comboBox_ResPlo_Depth->setObjectName(QString::fromUtf8("comboBox_ResPlo_Depth"));
        comboBox_ResPlo_Depth->setEnabled(false);

        gridLayout_ResPlo_PlotDef->addWidget(comboBox_ResPlo_Depth, 0, 3, 1, 1);


        gridLayout_7->addLayout(gridLayout_ResPlo_PlotDef, 0, 0, 1, 11);

        tabWidget_Results->addTab(tab_ResPlo, QString());

        gridLayout->addWidget(tabWidget_Results, 0, 1, 4, 1);

        D_MAKRO_IonTracks->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_IonTracks);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1283, 21));
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
        D_MAKRO_IonTracks->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_IonTracks);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_IonTracks->setStatusBar(statusbar);

        menubar->addAction(menuData->menuAction());
        menubar->addAction(menuLayout->menuAction());
        menubar->addAction(menuViewer->menuAction());
        menubar->addAction(menuUpdate->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menuData->addAction(action_Open_Files);
        menuData->addAction(action_Clear_Queue);
        menuData->addSeparator();
        menuData->addAction(action_Save_Table);
        menuData->addAction(action_Save_Plot);
        menuData->addAction(action_Save_Analysis);
        menuLayout->addAction(action_Show_Dimensions);
        menuLayout->addAction(action_Show_Processing);
        menuLayout->addAction(action_Show_Results);
        menuViewer->addAction(action_Smooth_Transformation);
        menuViewer->addAction(action_Keep_Aspect_Ratio);
        menuUpdate->addAction(action_Update_Views);
        menuUpdate->addAction(action_Update_Processing);
        menuUpdate->addAction(action_Block_Processing_Update);
        menuWindow->addAction(action_Minimize);
        menuWindow->addAction(action_Normal);
        menuWindow->addAction(action_Maximize);
        menuWindow->addAction(action_Fullscreen);

        retranslateUi(D_MAKRO_IonTracks);
        QObject::connect(action_Fullscreen, SIGNAL(triggered(bool)), D_MAKRO_IonTracks, SLOT(showFullScreen()));
        QObject::connect(action_Maximize, SIGNAL(triggered(bool)), D_MAKRO_IonTracks, SLOT(showMaximized()));
        QObject::connect(action_Normal, SIGNAL(triggered(bool)), D_MAKRO_IonTracks, SLOT(showNormal()));
        QObject::connect(action_Minimize, SIGNAL(triggered(bool)), D_MAKRO_IonTracks, SLOT(showMinimized()));
        QObject::connect(action_Show_Results, SIGNAL(triggered(bool)), tabWidget_Results, SLOT(setVisible(bool)));
        QObject::connect(action_Show_Dimensions, SIGNAL(triggered(bool)), groupBox_Dimension, SLOT(setVisible(bool)));
        QObject::connect(action_Show_Processing, SIGNAL(triggered(bool)), groupBox_CurAna, SLOT(setVisible(bool)));
        QObject::connect(action_Show_Processing, SIGNAL(triggered(bool)), groupBox_ProcSet, SLOT(setVisible(bool)));
        QObject::connect(action_Show_Processing, SIGNAL(triggered(bool)), groupBox_ProcView, SLOT(setVisible(bool)));
        QObject::connect(comboBox_ResPlo_Type, SIGNAL(currentIndexChanged(int)), stackedWidget_ResPlo_Type, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_ProcView_Depth, SIGNAL(currentIndexChanged(int)), comboBox_ResImg_Depth, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_ProcView_Lateral, SIGNAL(currentIndexChanged(int)), comboBox_ResImg_Lateral, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_ResImg_Depth, SIGNAL(currentIndexChanged(int)), comboBox_ProcView_Depth, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_ResImg_Lateral, SIGNAL(currentIndexChanged(int)), comboBox_ProcView_Lateral, SLOT(setCurrentIndex(int)));

        tabWidget_Results->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(D_MAKRO_IonTracks);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_IonTracks)
    {
        D_MAKRO_IonTracks->setWindowTitle(QApplication::translate("D_MAKRO_IonTracks", "MainWindow", nullptr));
        action_Minimize->setText(QApplication::translate("D_MAKRO_IonTracks", "Minimize", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Minimize->setShortcut(QApplication::translate("D_MAKRO_IonTracks", "F9", nullptr));
#endif // QT_NO_SHORTCUT
        action_Normal->setText(QApplication::translate("D_MAKRO_IonTracks", "Normal", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Normal->setShortcut(QApplication::translate("D_MAKRO_IonTracks", "F10", nullptr));
#endif // QT_NO_SHORTCUT
        action_Maximize->setText(QApplication::translate("D_MAKRO_IonTracks", "Maximize", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Maximize->setShortcut(QApplication::translate("D_MAKRO_IonTracks", "F11", nullptr));
#endif // QT_NO_SHORTCUT
        action_Fullscreen->setText(QApplication::translate("D_MAKRO_IonTracks", "Fullscreen", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Fullscreen->setShortcut(QApplication::translate("D_MAKRO_IonTracks", "F12", nullptr));
#endif // QT_NO_SHORTCUT
        action_Update_Views->setText(QApplication::translate("D_MAKRO_IonTracks", "Update Views", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Update_Views->setShortcut(QApplication::translate("D_MAKRO_IonTracks", "F4", nullptr));
#endif // QT_NO_SHORTCUT
        action_Smooth_Transformation->setText(QApplication::translate("D_MAKRO_IonTracks", "Smooth Transformation", nullptr));
        action_Keep_Aspect_Ratio->setText(QApplication::translate("D_MAKRO_IonTracks", "Keep Aspect Ratio", nullptr));
        action_Show_Dimensions->setText(QApplication::translate("D_MAKRO_IonTracks", "Dimensions", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Dimensions->setShortcut(QApplication::translate("D_MAKRO_IonTracks", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        action_Show_Processing->setText(QApplication::translate("D_MAKRO_IonTracks", "Processing", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Processing->setShortcut(QApplication::translate("D_MAKRO_IonTracks", "F2", nullptr));
#endif // QT_NO_SHORTCUT
        action_Show_Results->setText(QApplication::translate("D_MAKRO_IonTracks", "Results", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Results->setShortcut(QApplication::translate("D_MAKRO_IonTracks", "F3", nullptr));
#endif // QT_NO_SHORTCUT
        action_Open_Files->setText(QApplication::translate("D_MAKRO_IonTracks", "Open Files", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Open_Files->setShortcut(QApplication::translate("D_MAKRO_IonTracks", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        action_Clear_Queue->setText(QApplication::translate("D_MAKRO_IonTracks", "Clear Queue", nullptr));
        action_Save_Table->setText(QApplication::translate("D_MAKRO_IonTracks", "Save Table", nullptr));
        action_Save_Plot->setText(QApplication::translate("D_MAKRO_IonTracks", "Save Plot", nullptr));
        action_Save_Analysis->setText(QApplication::translate("D_MAKRO_IonTracks", "Save Analysis", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Save_Analysis->setShortcut(QApplication::translate("D_MAKRO_IonTracks", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        action_Update_Processing->setText(QApplication::translate("D_MAKRO_IonTracks", "Update Processing", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Update_Processing->setShortcut(QApplication::translate("D_MAKRO_IonTracks", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        action_Block_Processing_Update->setText(QApplication::translate("D_MAKRO_IonTracks", "Block Processing Update", nullptr));
        groupBox_ProcView->setTitle(QApplication::translate("D_MAKRO_IonTracks", "Processing View", nullptr));
        label_ProcView_Type_MA->setText(QApplication::translate("D_MAKRO_IonTracks", "Type MA", nullptr));
        label_ProcView_Type_QI->setText(QApplication::translate("D_MAKRO_IonTracks", "Type QI", nullptr));
        groupBox_Dimension->setTitle(QApplication::translate("D_MAKRO_IonTracks", "Dimensions", nullptr));
        label_Dimension_Title_Y_Lateral->setText(QApplication::translate("D_MAKRO_IonTracks", "Lateral Y", nullptr));
        label_Dimension_Title_X_Lateral->setText(QApplication::translate("D_MAKRO_IonTracks", "Lateral X", nullptr));
        label_Dimension_Dimension->setText(QApplication::translate("D_MAKRO_IonTracks", "Dimension", nullptr));
        label_Dimension_Title_Z_Depth->setText(QApplication::translate("D_MAKRO_IonTracks", "Depth Z", nullptr));
        label_Dimension_Step->setText(QApplication::translate("D_MAKRO_IonTracks", "Step", nullptr));
        label_Dimension_Size_X_Lateral->setText(QApplication::translate("D_MAKRO_IonTracks", "200\302\265m", nullptr));
        lineEdit_Dimension_Unit->setText(QApplication::translate("D_MAKRO_IonTracks", "\302\265m", nullptr));
        label_Dimension_Size_Y_Lateral->setText(QApplication::translate("D_MAKRO_IonTracks", "200\302\265m", nullptr));
        label_Dimension_Size_Z_Depth->setText(QApplication::translate("D_MAKRO_IonTracks", "100\302\265m", nullptr));
        label_Dimension_Size->setText(QApplication::translate("D_MAKRO_IonTracks", "Size", nullptr));
        groupBox_CurAna->setTitle(QApplication::translate("D_MAKRO_IonTracks", "Current Single Analysis", nullptr));
        groupBox_ProcSet->setTitle(QApplication::translate("D_MAKRO_IonTracks", "Processing Settings", nullptr));
        label_10->setText(QApplication::translate("D_MAKRO_IonTracks", "Tracks of Interest", nullptr));
        spinBox_ProcSet_Blur_Size->setSuffix(QApplication::translate("D_MAKRO_IonTracks", "px", nullptr));
        label_ProcSet_Blur_Description->setText(QApplication::translate("D_MAKRO_IonTracks", "Blur", nullptr));
        label_ProcSet_Thres_Description->setText(QApplication::translate("D_MAKRO_IonTracks", "Binarization", nullptr));
        label_ProcSet_Thres_Titel->setText(QApplication::translate("D_MAKRO_IonTracks", "Threshold", nullptr));
        label_ProcSet_Blur_Titel->setText(QApplication::translate("D_MAKRO_IonTracks", "Size/Sigma", nullptr));
        label_9->setText(QApplication::translate("D_MAKRO_IonTracks", "Relative Radius", nullptr));
        label_8->setText(QApplication::translate("D_MAKRO_IonTracks", "Exclude Connected", nullptr));
        label_4->setText(QApplication::translate("D_MAKRO_IonTracks", "Min Sphericity", nullptr));
        label_3->setText(QApplication::translate("D_MAKRO_IonTracks", "Exclude Aspheres", nullptr));
        label_7->setText(QApplication::translate("D_MAKRO_IonTracks", "Min Sphericity", nullptr));
        doubleSpinBox_ProcSet_ExLarge_MaxArea->setSuffix(QApplication::translate("D_MAKRO_IonTracks", "px\302\262", nullptr));
        spinBox_ProcSet_SafetyDist_MinRadius->setSuffix(QApplication::translate("D_MAKRO_IonTracks", "px", nullptr));
        label_6->setText(QApplication::translate("D_MAKRO_IonTracks", "Min Radius", nullptr));
        label_5->setText(QApplication::translate("D_MAKRO_IonTracks", "Safety Distance", nullptr));
        label_2->setText(QApplication::translate("D_MAKRO_IonTracks", "Max Area", nullptr));
        label->setText(QApplication::translate("D_MAKRO_IonTracks", "Exclude Large", nullptr));
        doubleSpinBox_ProcSet_TOI_RelRadius->setSuffix(QApplication::translate("D_MAKRO_IonTracks", "% of safety distance", nullptr));
        checkBox_ResImg_Edge_B->setText(QApplication::translate("D_MAKRO_IonTracks", "Edges", nullptr));
        label_ResImg_B->setText(QApplication::translate("D_MAKRO_IonTracks", "Blue:", nullptr));
        label_ResImg_G->setText(QApplication::translate("D_MAKRO_IonTracks", "Green:", nullptr));
        checkBox_ResImg_Edge_G->setText(QApplication::translate("D_MAKRO_IonTracks", "Edges", nullptr));
        tabWidget_Results->setTabText(tabWidget_Results->indexOf(tab_ResImg), QApplication::translate("D_MAKRO_IonTracks", "Image", nullptr));
        tabWidget_Results->setTabText(tabWidget_Results->indexOf(tab_ResTab), QApplication::translate("D_MAKRO_IonTracks", "Table", nullptr));
        label_ResPlo_X->setText(QApplication::translate("D_MAKRO_IonTracks", "X:", nullptr));
        label_ResPlo_MeanSD_Description_1->setText(QApplication::translate("D_MAKRO_IonTracks", "Arithmetic mean and standard deviataion (total) ", nullptr));
        label_ResPlo_MedianAMD_Description_1->setText(QApplication::translate("D_MAKRO_IonTracks", "Median and average absolute deviation from median", nullptr));
        label_ResPlo_Quantiles_Description_1->setText(QApplication::translate("D_MAKRO_IonTracks", "20% Quartiles", nullptr));
        label_ResPlo_Description_2->setText(QApplication::translate("D_MAKRO_IonTracks", "of pixels at radius in tracks", nullptr));
        label_ResPlo_Description_1->setText(QApplication::translate("D_MAKRO_IonTracks", "of", nullptr));
        checkBox_ResPlo_DisplayPoints->setText(QApplication::translate("D_MAKRO_IonTracks", "Points", nullptr));
        label_ResPlo_Y->setText(QApplication::translate("D_MAKRO_IonTracks", "Y:", nullptr));
        tabWidget_Results->setTabText(tabWidget_Results->indexOf(tab_ResPlo), QApplication::translate("D_MAKRO_IonTracks", "Plot", nullptr));
        menuData->setTitle(QApplication::translate("D_MAKRO_IonTracks", "Data", nullptr));
        menuLayout->setTitle(QApplication::translate("D_MAKRO_IonTracks", "Layout", nullptr));
        menuViewer->setTitle(QApplication::translate("D_MAKRO_IonTracks", "Viewer", nullptr));
        menuUpdate->setTitle(QApplication::translate("D_MAKRO_IonTracks", "Update", nullptr));
        menuWindow->setTitle(QApplication::translate("D_MAKRO_IonTracks", "Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_IonTracks: public Ui_D_MAKRO_IonTracks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_IONTRACKS_H
