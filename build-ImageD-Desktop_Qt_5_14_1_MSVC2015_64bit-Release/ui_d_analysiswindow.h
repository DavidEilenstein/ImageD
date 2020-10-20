/********************************************************************************
** Form generated from reading UI file 'd_analysiswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_ANALYSISWINDOW_H
#define UI_D_ANALYSISWINDOW_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_AnalysisWindow
{
public:
    QAction *action_Smooth_Transformation;
    QAction *action_Keep_Aspect_Ratio;
    QAction *action_Show_Normal;
    QAction *action_Show_Minimum;
    QAction *action_Show_Maximum;
    QAction *action_Show_Fullscreen;
    QAction *action_Show_Images;
    QAction *action_Show_Plots;
    QAction *action_Get_Images;
    QAction *action_Update_Views;
    QAction *action_Rename_Image;
    QAction *action_Rename_Component;
    QAction *action_Save_Image;
    QAction *action_Save_Plot;
    QAction *action_Save_Table;
    QAction *action_Save_Image_Plot_Table;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_Images;
    QGridLayout *gridLayout_2;
    QLabel *label_Img_Type_MA;
    QLabel *label_Img_Type_QI;
    QTabWidget *tabWidget_Images;
    QWidget *tab_ImgLab;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_ImgLab_GetImage;
    QComboBox *comboBox_ImgLab_Connectivity;
    QFrame *line_ImgLab;
    QSpacerItem *verticalSpacer_ImgLab;
    QLabel *label_ImgLab_Info;
    QWidget *tab_ImgVal;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_ImgVal_AddImage;
    QPushButton *pushButton_ImgVal_Clear;
    QSpacerItem *verticalSpacer_ImgVal;
    QFrame *line_ImgVal;
    QComboBox *comboBox_ImgVal_Image;
    QLabel *label_ImgVal_Info;
    QWidget *tab_ImgFea;
    QGridLayout *gridLayout_5;
    QFrame *line_ImgFea;
    QDoubleSpinBox *doubleSpinBox_ImgFea_Scale;
    QSpinBox *spinBox_ImgFea_Precision;
    QLabel *label_ImgFea_Scale;
    QComboBox *comboBox_ImgFea_Feature;
    QLabel *label_ImgFea_Precision;
    QComboBox *comboBox_ImgFea_Geometric;
    QComboBox *comboBox_ImgFea_BaseImage;
    QSpinBox *spinBox_ImgFea_Thickness;
    QLabel *label_ImgFea_Thickness;
    QLabel *label_ImgFea_Info;
    QSpacerItem *verticalSpacer_ImgFea;
    QWidget *tab_ImgSta;
    QGridLayout *gridLayout_7;
    QLabel *label_ImgSta_Info;
    QSpinBox *spinBox_ImgSta_Thickness;
    QLabel *label_ImgSta_Thickness;
    QComboBox *comboBox_ImgSta_Image;
    QComboBox *comboBox_ImgSta_Geometric;
    QComboBox *comboBox_ImgSta_Stat;
    QLabel *label_ImgSta_Precision;
    QLabel *label_ImgSta_Scale;
    QSpinBox *spinBox_ImgSta_Precision;
    QDoubleSpinBox *doubleSpinBox_ImgSta_Scale;
    QFrame *line_ImgSta;
    QSpacerItem *verticalSpacer_ImgSta;
    QLabel *label_Img_Scale;
    QGraphicsView *graphicsView_Image;
    QLabel *label_Img_Size;
    QLabel *label_Img_ValueAtPos;
    QGroupBox *groupBox_Plots;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget_Plots;
    QWidget *tab_PlotPixel;
    QGridLayout *gridLayout_9;
    QStackedWidget *stackedWidget_PlotPixel_Type;
    QWidget *page_PlotPixel_Hist;
    QGridLayout *gridLayout_8;
    QComboBox *comboBox_PlotPixel_Hist_Mode;
    QFrame *line_PlotPixel_Hist;
    QLabel *label_PlotPixel_Hist_X;
    QComboBox *comboBox_PlotPixel_Hist_Component;
    QLabel *label_PlotPixel_Hist_X_Description;
    QComboBox *comboBox_PlotPixel_Hist_Image;
    QLabel *label_PlotPixel_Hist_Classes;
    QSpinBox *spinBox_PlotPixel_Hist_Classes;
    QCheckBox *checkBox_PlotPixel_Hist_Uniform;
    QCheckBox *checkBox_PlotPixel_Hist_Accumulate;
    QLabel *label_PlotPixel_Hist_Y;
    QLabel *label_PlotPixel_Hist_Y_Description;
    QWidget *page_PlotPixel_Axe;
    QGridLayout *gridLayout_10;
    QComboBox *comboBox_PlotPixel_Axe_Component;
    QLabel *label_PlotPixel_Axe_X;
    QLabel *label_PlotPixel_Axe_Y;
    QComboBox *comboBox_PlotPixel_Axe_Axis;
    QComboBox *comboBox_PlotPixel_Axe_Mode;
    QFrame *line_PlotPixel_Axe;
    QLabel *label_PlotPixel_Axe_X_Description;
    QComboBox *comboBox_PlotPixel_Axe_Image;
    QComboBox *comboBox_PlotPixel_Axe_Stat;
    QWidget *page_PlotPixel_ScatterValue;
    QGridLayout *gridLayout_12;
    QFrame *line_PlotPixel_ScatterValue;
    QComboBox *comboBox_PlotPixel_ScatterValue_Image_Y;
    QLabel *label_PlotPixel_ScatterValue_Y;
    QComboBox *comboBox_PlotPixel_ScatterValue_Image_X;
    QLabel *label_PlotPixel_ScatterValue_X;
    QComboBox *comboBox_PlotPixel_ScatterValue_Component;
    QComboBox *comboBox_PlotPixel_ScatterValue_Mode;
    QWidget *page_PlotPixel_ScatterHist;
    QGridLayout *gridLayout_14;
    QFrame *line_PlotPixel_ScatterHist;
    QLabel *label_PlotPixel_ScatterHist_X;
    QComboBox *comboBox_PlotPixel_ScatterHist_Component_X;
    QCheckBox *checkBox_PlotPixel_ScatterHist_Uniform;
    QCheckBox *checkBox_PlotPixel_ScatterHist_Accumulate;
    QLabel *label_PlotPixel_ScatterHist_Y;
    QComboBox *comboBox_PlotPixel_ScatterHist_Component_Y;
    QLabel *label_PlotPixel_ScatterHist_Classes;
    QSpinBox *spinBox_PlotPixel_ScatterHist_Classes;
    QComboBox *comboBox_PlotPixel_ScatterHist_Mode;
    QLabel *label_PlotPixel_ScatterHist_Y_Description;
    QLabel *label_PlotPixel_ScatterHist_X_Description;
    QComboBox *comboBox_PlotPixel_ScatterHist_Image_X;
    QComboBox *comboBox_PlotPixel_ScatterHist_Image_Y;
    QWidget *page_PlotPixel_ScatterAxe;
    QGridLayout *gridLayout_16;
    QComboBox *comboBox_PlotPixel_ScatterAxe_Image_X;
    QComboBox *comboBox_PlotPixel_ScatterAxe_Image_Y;
    QFrame *line_PlotPixel_ScatterAxe;
    QLabel *label_PlotPixel_ScatterAxe_X;
    QLabel *label_PlotPixel_ScatterAxe_Y;
    QLabel *label_PlotPixel_ScatterAxe_X_Description;
    QLabel *label_PlotPixel_ScatterAxe_Y_Description;
    QComboBox *comboBox_PlotPixel_ScatterAxe_Stat_Y;
    QComboBox *comboBox_PlotPixel_ScatterAxe_Component;
    QComboBox *comboBox_PlotPixel_ScatterAxe_Stat_X;
    QLabel *label_PlotPixel_ScatterAxe_Description;
    QComboBox *comboBox_PlotPixel_ScatterAxe_Axis;
    QComboBox *comboBox_PlotPixel_ScatterAxe_Mode;
    QFrame *line_PlotPixel;
    QComboBox *comboBox_PlotPixel_Type;
    QWidget *tab_PlotComp;
    QGridLayout *gridLayout_11;
    QComboBox *comboBox_PlotComp_Type;
    QFrame *line_PlotComp;
    QStackedWidget *stackedWidget_PlotComp_Type;
    QWidget *page_PlotComp_Feat;
    QGridLayout *gridLayout_17;
    QLabel *label_PlotComp_Feat_Y;
    QFrame *line_PlotComp_Feat;
    QLabel *label_PlotComp_Feat_X;
    QComboBox *comboBox_PlotComp_Feat_Feature;
    QLabel *label_PlotComp_Feat_X_Description;
    QSpacerItem *horizontalSpacer_PlotComp_Feat;
    QWidget *page_PlotComp_FeatHist;
    QGridLayout *gridLayout_18;
    QLabel *label_PlotComp_FeatHist_Y;
    QFrame *line_PlotComp_FeatHist;
    QLabel *label_PlotComp_FeatHist_X;
    QCheckBox *checkBox_PlotComp_FeatHist_Accumulate;
    QSpinBox *spinBox_PlotComp_FeatHist_Classes;
    QCheckBox *checkBox_PlotComp_FeatHist_Uniform;
    QLabel *label_PlotComp_FeatHist_Classes;
    QLabel *label_PlotComp_FeatHist_Y_Description;
    QComboBox *comboBox_PlotComp_FeatHist_Feature;
    QSpacerItem *horizontalSpacer_PlotComp_FeatHist;
    QWidget *page_PlotComp_FeatScatter;
    QGridLayout *gridLayout_19;
    QLabel *label_PlotComp_FeatScatter_Y;
    QComboBox *comboBox_PlotComp_FeatScatter_Feature_Y;
    QFrame *line_PlotComp_FeatScatter;
    QLabel *label_PlotComp_FeatScatter_X;
    QComboBox *comboBox_PlotComp_FeatScatter_Feature_X;
    QSpacerItem *horizontalSpacer_PlotComp_FeatScatter;
    QWidget *page_PlotComp_Stat;
    QGridLayout *gridLayout_20;
    QComboBox *comboBox_PlotComp_Stat_Mode;
    QFrame *line_PlotComp_Stat;
    QLabel *label_PlotComp_Stat_X;
    QComboBox *comboBox_PlotComp_Stat_Image;
    QLabel *label_PlotComp_Stat_Y;
    QComboBox *comboBox_PlotComp_Stat_Stat;
    QWidget *page_PlotComp_StatHist;
    QGridLayout *gridLayout_21;
    QComboBox *comboBox_PlotComp_StatHist_Mode;
    QFrame *line_PlotComp_StatHist;
    QLabel *label_PlotComp_StatHist_X;
    QLabel *label_PlotComp_StatHist_Classes;
    QSpinBox *spinBox_PlotComp_StatHist_Classes;
    QCheckBox *checkBox_PlotComp_StatHist_Uniform;
    QCheckBox *checkBox_PlotComp_StatHist_Accumulate;
    QLabel *label_PlotComp_StatHist_Y;
    QLabel *label_PlotComp_StatHist_X_Description;
    QComboBox *comboBox_PlotComp_StatHist_Stat;
    QComboBox *comboBox_PlotComp_StatHist_Image;
    QLabel *label_PlotComp_StatHist_Y_Description;
    QWidget *page_PlotComp_StatScatter;
    QGridLayout *gridLayout_22;
    QComboBox *comboBox_PlotComp_StatScatter_Mode;
    QFrame *line_PlotComp_StatScatter;
    QLabel *label_PlotComp_StatScatter_X;
    QComboBox *comboBox_PlotComp_StatScatter_Image_X;
    QLabel *label_PlotComp_StatScatter_Y;
    QComboBox *comboBox_PlotComp_StatScatter_Image_Y;
    QLabel *label_PlotComp_StatScatter_X_Description;
    QLabel *label_PlotComp_StatScatter_Y_Description;
    QComboBox *comboBox_PlotComp_StatScatter_Stat_Y;
    QComboBox *comboBox_PlotComp_StatScatter_Stat_X;
    QWidget *page_PlotComp_StatFeatScatter;
    QGridLayout *gridLayout_23;
    QComboBox *comboBox_PlotComp_StatFeatScatter_Mode;
    QFrame *line_PlotComp_StatFeatScatter;
    QLabel *label_PlotComp_StatFeatScatter_X;
    QLabel *label_PlotComp_StatFeatScatter_Y;
    QComboBox *comboBox_PlotComp_StatFeatScatter_Stat_Y;
    QComboBox *comboBox_PlotComp_StatFeatScatter_Image_Y;
    QComboBox *comboBox_PlotComp_StatFeatScatter_Feature_X;
    QLabel *label_PlotComp_StatFeatScatter_X_Description;
    QWidget *tab_PlotImg;
    QGridLayout *gridLayout_13;
    QStackedWidget *stackedWidget_PlotImg_Type;
    QWidget *page_PlotImg_Feat;
    QGridLayout *gridLayout_24;
    QFrame *line_PlotImg_Feat;
    QSpacerItem *horizontalSpacer_PlotImg_Feat;
    QLabel *label_PlotImg_Feat_Y;
    QLabel *label_PlotImg_Feat_X;
    QSpacerItem *horizontalSpacer;
    QWidget *page_PlotImg_Stat;
    QGridLayout *gridLayout_26;
    QSpacerItem *horizontalSpacer_PlotImg_Stat;
    QFrame *line_PlotImg_Stat;
    QLabel *label_PlotImg_Stat_X;
    QLabel *label_PlotImg_Stat_Y;
    QComboBox *comboBox_PlotImg_Stat_StatImg;
    QLabel *label_PlotImg_Stat_Y_Description_1;
    QComboBox *comboBox_PlotImg_Stat_StatComp;
    QLabel *label_PlotImg_Stat_X_Description;
    QWidget *page_PlotImg_StatHist;
    QGridLayout *gridLayout_27;
    QSpacerItem *horizontalSpacer_PlotImg_StatHist;
    QFrame *line_PlotImg_StatHist;
    QLabel *label_PlotImg_StatHist_X;
    QComboBox *comboBox_PlotImg_StatHist_StatImg;
    QLabel *label_PlotImg_StatHist_X_Description_1;
    QComboBox *comboBox_PlotImg_StatHist_StatComp;
    QLabel *label_PlotImg_StatHist_Classes;
    QSpinBox *spinBox_PlotImg_StatHist_Classes;
    QCheckBox *checkBox_PlotImg_StatHist_Uni;
    QCheckBox *checkBox_PlotImg_StatHist_Acc;
    QLabel *label_PlotImg_StatHist_Y;
    QLabel *label_PlotImg_StatHist_Y_Description;
    QWidget *page_PlotImg_StatScatter;
    QGridLayout *gridLayout_28;
    QLabel *label_PlotImg_StatScatter_X_Description_1;
    QLabel *label_PlotImg_StatScatter_Y_Description_1;
    QComboBox *comboBox_PlotImg_StatScatter_StatImg_X;
    QComboBox *comboBox_PlotImg_StatScatter_StatImg_Y;
    QComboBox *comboBox_PlotImg_StatScatter_StatComp_Y;
    QLabel *label_PlotImg_StatScatter_Y;
    QFrame *line_PlotImg_StatScatter;
    QSpacerItem *horizontalSpacer_PlotImg_StatScatter;
    QLabel *label_PlotImg_StatScatter_X;
    QComboBox *comboBox_PlotImg_StatScatter_StatComp_X;
    QWidget *page_PlotImg_StatFeatScatter;
    QGridLayout *gridLayout_29;
    QFrame *line_PlotImg_StatFeatScatter;
    QLabel *label_PlotImg_StatFeatScatter_X;
    QComboBox *comboBox_PlotImg_StatFeatScatter_StatImg_X;
    QLabel *label_PlotImg_StatFeatScatter_X_Description_1;
    QComboBox *comboBox_PlotImg_StatFeatScatter_FeatComp_X;
    QLabel *label_PlotImg_StatFeatScatter_Y;
    QComboBox *comboBox_PlotImg_StatFeatScatter_StatImg_Y;
    QLabel *label_PlotImg_StatFeatScatter_Y_Description_1;
    QComboBox *comboBox_PlotImg_StatFeatScatter_StatComp_Y;
    QSpacerItem *horizontalSpacer_PlotImg_StatFeatScatter;
    QWidget *page_PlotImg_FeatHist;
    QGridLayout *gridLayout_25;
    QSpacerItem *horizontalSpacer_PlotImg_FeatHist;
    QSpinBox *spinBox_PlotImg_FeatHist_Classes;
    QLabel *label_PlotImg_FeatHist_Y;
    QCheckBox *checkBox_PlotImg_FeatHist_Uni;
    QLabel *label_PlotImg_FeatHist_Classes;
    QLabel *label_PlotImg_FeatHist_X;
    QFrame *line_PlotImg_FeatHist;
    QComboBox *comboBox_PlotImg_FeatHist_Feature;
    QCheckBox *checkBox_PlotImg_FeatHist_Acc;
    QComboBox *comboBox_PlotImg_FeatHist_Stat;
    QLabel *label_PlotImg_FeatHist_X_Description_1;
    QLabel *label_PlotImg_FeatHist_Y_Description;
    QFrame *line_PlotImg;
    QComboBox *comboBox_PlotImg_Type;
    QWidget *tab_PlotStack;
    QGridLayout *gridLayout_15;
    QComboBox *comboBox_PlotStack_Type;
    QFrame *line_PlotStack;
    QStackedWidget *stackedWidget_PlotStack_Type;
    QWidget *page_PlotStack_Stat;
    QGridLayout *gridLayout_34;
    QLabel *label_PlotStack_Stat_StatImg;
    QComboBox *comboBox_PlotStack_Stat_StatComp;
    QLabel *label_PlotStack_Stat_StatComp;
    QComboBox *comboBox_PlotStack_Stat_StatImg;
    QLabel *label_PlotStack_Stat_Description_1;
    QLabel *label_PlotStack_Stat_Description_2;
    QLabel *label_PlotStack_Stat_StatStack_2;
    QLabel *label_PlotStack_Stat_StatStack_1;
    QWidget *page_PlotStack_1;
    QTabWidget *tabWidget_PlotTable;
    QWidget *tab_Plot;
    QGridLayout *gridLayout_31;
    QGridLayout *gridLayout_Plot;
    QCheckBox *checkBox_Plot_Y_Range;
    QDoubleSpinBox *doubleSpinBox_Plot_Y_Max;
    QLabel *label_Plot_Time;
    QDoubleSpinBox *doubleSpinBox_Plot_X_Max;
    QCheckBox *checkBox_Plot_X_Range;
    QDoubleSpinBox *doubleSpinBox_Plot_Y_Min;
    QDoubleSpinBox *doubleSpinBox_Plot_X_Min;
    QSpacerItem *horizontalSpacer_Plot;
    QWidget *tab_Table;
    QGridLayout *gridLayout_33;
    QTableWidget *tableWidget_PlottedData;
    QMenuBar *menubar;
    QMenu *menuViewer;
    QMenu *menuWindow;
    QMenu *menuData;
    QMenu *menuUpdate;
    QMenu *menuLayout;
    QMenu *menuRename;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_AnalysisWindow)
    {
        if (D_AnalysisWindow->objectName().isEmpty())
            D_AnalysisWindow->setObjectName(QString::fromUtf8("D_AnalysisWindow"));
        D_AnalysisWindow->resize(1169, 736);
        action_Smooth_Transformation = new QAction(D_AnalysisWindow);
        action_Smooth_Transformation->setObjectName(QString::fromUtf8("action_Smooth_Transformation"));
        action_Smooth_Transformation->setCheckable(true);
        action_Smooth_Transformation->setChecked(true);
        action_Keep_Aspect_Ratio = new QAction(D_AnalysisWindow);
        action_Keep_Aspect_Ratio->setObjectName(QString::fromUtf8("action_Keep_Aspect_Ratio"));
        action_Keep_Aspect_Ratio->setCheckable(true);
        action_Keep_Aspect_Ratio->setChecked(true);
        action_Show_Normal = new QAction(D_AnalysisWindow);
        action_Show_Normal->setObjectName(QString::fromUtf8("action_Show_Normal"));
        action_Show_Minimum = new QAction(D_AnalysisWindow);
        action_Show_Minimum->setObjectName(QString::fromUtf8("action_Show_Minimum"));
        action_Show_Maximum = new QAction(D_AnalysisWindow);
        action_Show_Maximum->setObjectName(QString::fromUtf8("action_Show_Maximum"));
        action_Show_Fullscreen = new QAction(D_AnalysisWindow);
        action_Show_Fullscreen->setObjectName(QString::fromUtf8("action_Show_Fullscreen"));
        action_Show_Images = new QAction(D_AnalysisWindow);
        action_Show_Images->setObjectName(QString::fromUtf8("action_Show_Images"));
        action_Show_Images->setCheckable(true);
        action_Show_Images->setChecked(true);
        action_Show_Plots = new QAction(D_AnalysisWindow);
        action_Show_Plots->setObjectName(QString::fromUtf8("action_Show_Plots"));
        action_Show_Plots->setCheckable(true);
        action_Show_Plots->setChecked(true);
        action_Get_Images = new QAction(D_AnalysisWindow);
        action_Get_Images->setObjectName(QString::fromUtf8("action_Get_Images"));
        action_Update_Views = new QAction(D_AnalysisWindow);
        action_Update_Views->setObjectName(QString::fromUtf8("action_Update_Views"));
        action_Rename_Image = new QAction(D_AnalysisWindow);
        action_Rename_Image->setObjectName(QString::fromUtf8("action_Rename_Image"));
        action_Rename_Component = new QAction(D_AnalysisWindow);
        action_Rename_Component->setObjectName(QString::fromUtf8("action_Rename_Component"));
        action_Save_Image = new QAction(D_AnalysisWindow);
        action_Save_Image->setObjectName(QString::fromUtf8("action_Save_Image"));
        action_Save_Plot = new QAction(D_AnalysisWindow);
        action_Save_Plot->setObjectName(QString::fromUtf8("action_Save_Plot"));
        action_Save_Table = new QAction(D_AnalysisWindow);
        action_Save_Table->setObjectName(QString::fromUtf8("action_Save_Table"));
        action_Save_Image_Plot_Table = new QAction(D_AnalysisWindow);
        action_Save_Image_Plot_Table->setObjectName(QString::fromUtf8("action_Save_Image_Plot_Table"));
        centralwidget = new QWidget(D_AnalysisWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_Images = new QGroupBox(centralwidget);
        groupBox_Images->setObjectName(QString::fromUtf8("groupBox_Images"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(groupBox_Images->sizePolicy().hasHeightForWidth());
        groupBox_Images->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox_Images);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(9, 9, 9, 9);
        label_Img_Type_MA = new QLabel(groupBox_Images);
        label_Img_Type_MA->setObjectName(QString::fromUtf8("label_Img_Type_MA"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_Img_Type_MA->sizePolicy().hasHeightForWidth());
        label_Img_Type_MA->setSizePolicy(sizePolicy1);
        label_Img_Type_MA->setMinimumSize(QSize(0, 0));
        label_Img_Type_MA->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(label_Img_Type_MA, 2, 4, 1, 1);

        label_Img_Type_QI = new QLabel(groupBox_Images);
        label_Img_Type_QI->setObjectName(QString::fromUtf8("label_Img_Type_QI"));
        sizePolicy1.setHeightForWidth(label_Img_Type_QI->sizePolicy().hasHeightForWidth());
        label_Img_Type_QI->setSizePolicy(sizePolicy1);
        label_Img_Type_QI->setMinimumSize(QSize(0, 0));
        label_Img_Type_QI->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(label_Img_Type_QI, 2, 3, 1, 1);

        tabWidget_Images = new QTabWidget(groupBox_Images);
        tabWidget_Images->setObjectName(QString::fromUtf8("tabWidget_Images"));
        tabWidget_Images->setEnabled(true);
        tabWidget_Images->setMinimumSize(QSize(0, 20));
        tabWidget_Images->setMaximumSize(QSize(16777215, 122));
        tab_ImgLab = new QWidget();
        tab_ImgLab->setObjectName(QString::fromUtf8("tab_ImgLab"));
        gridLayout_6 = new QGridLayout(tab_ImgLab);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        pushButton_ImgLab_GetImage = new QPushButton(tab_ImgLab);
        pushButton_ImgLab_GetImage->setObjectName(QString::fromUtf8("pushButton_ImgLab_GetImage"));
        pushButton_ImgLab_GetImage->setMinimumSize(QSize(0, 20));
        pushButton_ImgLab_GetImage->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(pushButton_ImgLab_GetImage, 0, 0, 1, 1);

        comboBox_ImgLab_Connectivity = new QComboBox(tab_ImgLab);
        comboBox_ImgLab_Connectivity->addItem(QString());
        comboBox_ImgLab_Connectivity->addItem(QString());
        comboBox_ImgLab_Connectivity->setObjectName(QString::fromUtf8("comboBox_ImgLab_Connectivity"));
        comboBox_ImgLab_Connectivity->setEnabled(false);
        comboBox_ImgLab_Connectivity->setMinimumSize(QSize(0, 20));
        comboBox_ImgLab_Connectivity->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(comboBox_ImgLab_Connectivity, 0, 1, 1, 1);

        line_ImgLab = new QFrame(tab_ImgLab);
        line_ImgLab->setObjectName(QString::fromUtf8("line_ImgLab"));
        line_ImgLab->setFrameShape(QFrame::HLine);
        line_ImgLab->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_ImgLab, 1, 0, 1, 2);

        verticalSpacer_ImgLab = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_ImgLab, 2, 0, 1, 1);

        label_ImgLab_Info = new QLabel(tab_ImgLab);
        label_ImgLab_Info->setObjectName(QString::fromUtf8("label_ImgLab_Info"));

        gridLayout_6->addWidget(label_ImgLab_Info, 3, 0, 1, 2);

        tabWidget_Images->addTab(tab_ImgLab, QString());
        tab_ImgVal = new QWidget();
        tab_ImgVal->setObjectName(QString::fromUtf8("tab_ImgVal"));
        tab_ImgVal->setEnabled(true);
        gridLayout_4 = new QGridLayout(tab_ImgVal);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton_ImgVal_AddImage = new QPushButton(tab_ImgVal);
        pushButton_ImgVal_AddImage->setObjectName(QString::fromUtf8("pushButton_ImgVal_AddImage"));
        pushButton_ImgVal_AddImage->setMinimumSize(QSize(0, 20));
        pushButton_ImgVal_AddImage->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(pushButton_ImgVal_AddImage, 0, 0, 1, 1);

        pushButton_ImgVal_Clear = new QPushButton(tab_ImgVal);
        pushButton_ImgVal_Clear->setObjectName(QString::fromUtf8("pushButton_ImgVal_Clear"));
        pushButton_ImgVal_Clear->setMinimumSize(QSize(0, 20));
        pushButton_ImgVal_Clear->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(pushButton_ImgVal_Clear, 0, 1, 1, 1);

        verticalSpacer_ImgVal = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_ImgVal, 3, 0, 1, 1);

        line_ImgVal = new QFrame(tab_ImgVal);
        line_ImgVal->setObjectName(QString::fromUtf8("line_ImgVal"));
        line_ImgVal->setFrameShape(QFrame::HLine);
        line_ImgVal->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_ImgVal, 1, 0, 1, 2);

        comboBox_ImgVal_Image = new QComboBox(tab_ImgVal);
        comboBox_ImgVal_Image->setObjectName(QString::fromUtf8("comboBox_ImgVal_Image"));
        comboBox_ImgVal_Image->setMinimumSize(QSize(0, 20));

        gridLayout_4->addWidget(comboBox_ImgVal_Image, 2, 0, 1, 2);

        label_ImgVal_Info = new QLabel(tab_ImgVal);
        label_ImgVal_Info->setObjectName(QString::fromUtf8("label_ImgVal_Info"));

        gridLayout_4->addWidget(label_ImgVal_Info, 5, 0, 1, 2);

        tabWidget_Images->addTab(tab_ImgVal, QString());
        tab_ImgFea = new QWidget();
        tab_ImgFea->setObjectName(QString::fromUtf8("tab_ImgFea"));
        gridLayout_5 = new QGridLayout(tab_ImgFea);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        line_ImgFea = new QFrame(tab_ImgFea);
        line_ImgFea->setObjectName(QString::fromUtf8("line_ImgFea"));
        line_ImgFea->setFrameShape(QFrame::HLine);
        line_ImgFea->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_ImgFea, 1, 0, 1, 6);

        doubleSpinBox_ImgFea_Scale = new QDoubleSpinBox(tab_ImgFea);
        doubleSpinBox_ImgFea_Scale->setObjectName(QString::fromUtf8("doubleSpinBox_ImgFea_Scale"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(doubleSpinBox_ImgFea_Scale->sizePolicy().hasHeightForWidth());
        doubleSpinBox_ImgFea_Scale->setSizePolicy(sizePolicy2);
        doubleSpinBox_ImgFea_Scale->setDecimals(1);
        doubleSpinBox_ImgFea_Scale->setMinimum(0.100000000000000);
        doubleSpinBox_ImgFea_Scale->setMaximum(9.900000000000000);
        doubleSpinBox_ImgFea_Scale->setSingleStep(0.100000000000000);
        doubleSpinBox_ImgFea_Scale->setValue(1.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_ImgFea_Scale, 3, 3, 1, 1);

        spinBox_ImgFea_Precision = new QSpinBox(tab_ImgFea);
        spinBox_ImgFea_Precision->setObjectName(QString::fromUtf8("spinBox_ImgFea_Precision"));
        sizePolicy2.setHeightForWidth(spinBox_ImgFea_Precision->sizePolicy().hasHeightForWidth());
        spinBox_ImgFea_Precision->setSizePolicy(sizePolicy2);
        spinBox_ImgFea_Precision->setMinimum(1);
        spinBox_ImgFea_Precision->setMaximum(9);
        spinBox_ImgFea_Precision->setValue(3);

        gridLayout_5->addWidget(spinBox_ImgFea_Precision, 3, 1, 1, 1);

        label_ImgFea_Scale = new QLabel(tab_ImgFea);
        label_ImgFea_Scale->setObjectName(QString::fromUtf8("label_ImgFea_Scale"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_ImgFea_Scale->sizePolicy().hasHeightForWidth());
        label_ImgFea_Scale->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(label_ImgFea_Scale, 3, 2, 1, 1);

        comboBox_ImgFea_Feature = new QComboBox(tab_ImgFea);
        comboBox_ImgFea_Feature->setObjectName(QString::fromUtf8("comboBox_ImgFea_Feature"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(comboBox_ImgFea_Feature->sizePolicy().hasHeightForWidth());
        comboBox_ImgFea_Feature->setSizePolicy(sizePolicy4);
        comboBox_ImgFea_Feature->setMinimumSize(QSize(0, 20));
        comboBox_ImgFea_Feature->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_5->addWidget(comboBox_ImgFea_Feature, 0, 2, 1, 2);

        label_ImgFea_Precision = new QLabel(tab_ImgFea);
        label_ImgFea_Precision->setObjectName(QString::fromUtf8("label_ImgFea_Precision"));
        sizePolicy3.setHeightForWidth(label_ImgFea_Precision->sizePolicy().hasHeightForWidth());
        label_ImgFea_Precision->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(label_ImgFea_Precision, 3, 0, 1, 1);

        comboBox_ImgFea_Geometric = new QComboBox(tab_ImgFea);
        comboBox_ImgFea_Geometric->setObjectName(QString::fromUtf8("comboBox_ImgFea_Geometric"));
        sizePolicy4.setHeightForWidth(comboBox_ImgFea_Geometric->sizePolicy().hasHeightForWidth());
        comboBox_ImgFea_Geometric->setSizePolicy(sizePolicy4);
        comboBox_ImgFea_Geometric->setMinimumSize(QSize(0, 20));
        comboBox_ImgFea_Geometric->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_5->addWidget(comboBox_ImgFea_Geometric, 0, 4, 1, 2);

        comboBox_ImgFea_BaseImage = new QComboBox(tab_ImgFea);
        comboBox_ImgFea_BaseImage->setObjectName(QString::fromUtf8("comboBox_ImgFea_BaseImage"));
        sizePolicy4.setHeightForWidth(comboBox_ImgFea_BaseImage->sizePolicy().hasHeightForWidth());
        comboBox_ImgFea_BaseImage->setSizePolicy(sizePolicy4);
        comboBox_ImgFea_BaseImage->setMinimumSize(QSize(0, 20));
        comboBox_ImgFea_BaseImage->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_5->addWidget(comboBox_ImgFea_BaseImage, 0, 0, 1, 2);

        spinBox_ImgFea_Thickness = new QSpinBox(tab_ImgFea);
        spinBox_ImgFea_Thickness->setObjectName(QString::fromUtf8("spinBox_ImgFea_Thickness"));
        sizePolicy2.setHeightForWidth(spinBox_ImgFea_Thickness->sizePolicy().hasHeightForWidth());
        spinBox_ImgFea_Thickness->setSizePolicy(sizePolicy2);
        spinBox_ImgFea_Thickness->setMinimum(1);
        spinBox_ImgFea_Thickness->setMaximum(9);
        spinBox_ImgFea_Thickness->setValue(2);

        gridLayout_5->addWidget(spinBox_ImgFea_Thickness, 3, 5, 1, 1);

        label_ImgFea_Thickness = new QLabel(tab_ImgFea);
        label_ImgFea_Thickness->setObjectName(QString::fromUtf8("label_ImgFea_Thickness"));
        sizePolicy3.setHeightForWidth(label_ImgFea_Thickness->sizePolicy().hasHeightForWidth());
        label_ImgFea_Thickness->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(label_ImgFea_Thickness, 3, 4, 1, 1);

        label_ImgFea_Info = new QLabel(tab_ImgFea);
        label_ImgFea_Info->setObjectName(QString::fromUtf8("label_ImgFea_Info"));

        gridLayout_5->addWidget(label_ImgFea_Info, 4, 0, 1, 6);

        verticalSpacer_ImgFea = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_ImgFea, 2, 0, 1, 1);

        tabWidget_Images->addTab(tab_ImgFea, QString());
        tab_ImgSta = new QWidget();
        tab_ImgSta->setObjectName(QString::fromUtf8("tab_ImgSta"));
        tab_ImgSta->setEnabled(true);
        gridLayout_7 = new QGridLayout(tab_ImgSta);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_ImgSta_Info = new QLabel(tab_ImgSta);
        label_ImgSta_Info->setObjectName(QString::fromUtf8("label_ImgSta_Info"));

        gridLayout_7->addWidget(label_ImgSta_Info, 4, 1, 1, 6);

        spinBox_ImgSta_Thickness = new QSpinBox(tab_ImgSta);
        spinBox_ImgSta_Thickness->setObjectName(QString::fromUtf8("spinBox_ImgSta_Thickness"));
        sizePolicy2.setHeightForWidth(spinBox_ImgSta_Thickness->sizePolicy().hasHeightForWidth());
        spinBox_ImgSta_Thickness->setSizePolicy(sizePolicy2);
        spinBox_ImgSta_Thickness->setMinimum(1);
        spinBox_ImgSta_Thickness->setMaximum(9);
        spinBox_ImgSta_Thickness->setValue(2);

        gridLayout_7->addWidget(spinBox_ImgSta_Thickness, 3, 6, 1, 1);

        label_ImgSta_Thickness = new QLabel(tab_ImgSta);
        label_ImgSta_Thickness->setObjectName(QString::fromUtf8("label_ImgSta_Thickness"));
        sizePolicy3.setHeightForWidth(label_ImgSta_Thickness->sizePolicy().hasHeightForWidth());
        label_ImgSta_Thickness->setSizePolicy(sizePolicy3);

        gridLayout_7->addWidget(label_ImgSta_Thickness, 3, 5, 1, 1);

        comboBox_ImgSta_Image = new QComboBox(tab_ImgSta);
        comboBox_ImgSta_Image->setObjectName(QString::fromUtf8("comboBox_ImgSta_Image"));
        sizePolicy4.setHeightForWidth(comboBox_ImgSta_Image->sizePolicy().hasHeightForWidth());
        comboBox_ImgSta_Image->setSizePolicy(sizePolicy4);
        comboBox_ImgSta_Image->setMinimumSize(QSize(0, 20));
        comboBox_ImgSta_Image->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_7->addWidget(comboBox_ImgSta_Image, 0, 1, 1, 2);

        comboBox_ImgSta_Geometric = new QComboBox(tab_ImgSta);
        comboBox_ImgSta_Geometric->setObjectName(QString::fromUtf8("comboBox_ImgSta_Geometric"));
        sizePolicy4.setHeightForWidth(comboBox_ImgSta_Geometric->sizePolicy().hasHeightForWidth());
        comboBox_ImgSta_Geometric->setSizePolicy(sizePolicy4);
        comboBox_ImgSta_Geometric->setMinimumSize(QSize(0, 20));
        comboBox_ImgSta_Geometric->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_7->addWidget(comboBox_ImgSta_Geometric, 0, 5, 1, 2);

        comboBox_ImgSta_Stat = new QComboBox(tab_ImgSta);
        comboBox_ImgSta_Stat->setObjectName(QString::fromUtf8("comboBox_ImgSta_Stat"));
        sizePolicy4.setHeightForWidth(comboBox_ImgSta_Stat->sizePolicy().hasHeightForWidth());
        comboBox_ImgSta_Stat->setSizePolicy(sizePolicy4);
        comboBox_ImgSta_Stat->setMinimumSize(QSize(0, 20));
        comboBox_ImgSta_Stat->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_7->addWidget(comboBox_ImgSta_Stat, 0, 3, 1, 2);

        label_ImgSta_Precision = new QLabel(tab_ImgSta);
        label_ImgSta_Precision->setObjectName(QString::fromUtf8("label_ImgSta_Precision"));
        sizePolicy3.setHeightForWidth(label_ImgSta_Precision->sizePolicy().hasHeightForWidth());
        label_ImgSta_Precision->setSizePolicy(sizePolicy3);

        gridLayout_7->addWidget(label_ImgSta_Precision, 3, 1, 1, 1);

        label_ImgSta_Scale = new QLabel(tab_ImgSta);
        label_ImgSta_Scale->setObjectName(QString::fromUtf8("label_ImgSta_Scale"));
        sizePolicy3.setHeightForWidth(label_ImgSta_Scale->sizePolicy().hasHeightForWidth());
        label_ImgSta_Scale->setSizePolicy(sizePolicy3);

        gridLayout_7->addWidget(label_ImgSta_Scale, 3, 3, 1, 1);

        spinBox_ImgSta_Precision = new QSpinBox(tab_ImgSta);
        spinBox_ImgSta_Precision->setObjectName(QString::fromUtf8("spinBox_ImgSta_Precision"));
        sizePolicy2.setHeightForWidth(spinBox_ImgSta_Precision->sizePolicy().hasHeightForWidth());
        spinBox_ImgSta_Precision->setSizePolicy(sizePolicy2);
        spinBox_ImgSta_Precision->setMinimum(1);
        spinBox_ImgSta_Precision->setMaximum(9);
        spinBox_ImgSta_Precision->setValue(3);

        gridLayout_7->addWidget(spinBox_ImgSta_Precision, 3, 2, 1, 1);

        doubleSpinBox_ImgSta_Scale = new QDoubleSpinBox(tab_ImgSta);
        doubleSpinBox_ImgSta_Scale->setObjectName(QString::fromUtf8("doubleSpinBox_ImgSta_Scale"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_ImgSta_Scale->sizePolicy().hasHeightForWidth());
        doubleSpinBox_ImgSta_Scale->setSizePolicy(sizePolicy2);
        doubleSpinBox_ImgSta_Scale->setDecimals(1);
        doubleSpinBox_ImgSta_Scale->setMinimum(0.100000000000000);
        doubleSpinBox_ImgSta_Scale->setMaximum(9.900000000000000);
        doubleSpinBox_ImgSta_Scale->setSingleStep(0.100000000000000);
        doubleSpinBox_ImgSta_Scale->setValue(1.000000000000000);

        gridLayout_7->addWidget(doubleSpinBox_ImgSta_Scale, 3, 4, 1, 1);

        line_ImgSta = new QFrame(tab_ImgSta);
        line_ImgSta->setObjectName(QString::fromUtf8("line_ImgSta"));
        line_ImgSta->setFrameShape(QFrame::HLine);
        line_ImgSta->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_ImgSta, 1, 1, 1, 6);

        verticalSpacer_ImgSta = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_ImgSta, 2, 1, 1, 1);

        tabWidget_Images->addTab(tab_ImgSta, QString());

        gridLayout_2->addWidget(tabWidget_Images, 0, 0, 1, 5);

        label_Img_Scale = new QLabel(groupBox_Images);
        label_Img_Scale->setObjectName(QString::fromUtf8("label_Img_Scale"));
        sizePolicy1.setHeightForWidth(label_Img_Scale->sizePolicy().hasHeightForWidth());
        label_Img_Scale->setSizePolicy(sizePolicy1);
        label_Img_Scale->setMinimumSize(QSize(0, 0));
        label_Img_Scale->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(label_Img_Scale, 2, 1, 1, 1);

        graphicsView_Image = new QGraphicsView(groupBox_Images);
        graphicsView_Image->setObjectName(QString::fromUtf8("graphicsView_Image"));
        graphicsView_Image->setMouseTracking(true);

        gridLayout_2->addWidget(graphicsView_Image, 1, 0, 1, 5);

        label_Img_Size = new QLabel(groupBox_Images);
        label_Img_Size->setObjectName(QString::fromUtf8("label_Img_Size"));
        sizePolicy1.setHeightForWidth(label_Img_Size->sizePolicy().hasHeightForWidth());
        label_Img_Size->setSizePolicy(sizePolicy1);
        label_Img_Size->setMinimumSize(QSize(0, 0));
        label_Img_Size->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(label_Img_Size, 2, 2, 1, 1);

        label_Img_ValueAtPos = new QLabel(groupBox_Images);
        label_Img_ValueAtPos->setObjectName(QString::fromUtf8("label_Img_ValueAtPos"));
        sizePolicy1.setHeightForWidth(label_Img_ValueAtPos->sizePolicy().hasHeightForWidth());
        label_Img_ValueAtPos->setSizePolicy(sizePolicy1);
        label_Img_ValueAtPos->setMinimumSize(QSize(0, 0));
        label_Img_ValueAtPos->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(label_Img_ValueAtPos, 2, 0, 1, 1);


        gridLayout->addWidget(groupBox_Images, 0, 0, 1, 1);

        groupBox_Plots = new QGroupBox(centralwidget);
        groupBox_Plots->setObjectName(QString::fromUtf8("groupBox_Plots"));
        sizePolicy.setHeightForWidth(groupBox_Plots->sizePolicy().hasHeightForWidth());
        groupBox_Plots->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(groupBox_Plots);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tabWidget_Plots = new QTabWidget(groupBox_Plots);
        tabWidget_Plots->setObjectName(QString::fromUtf8("tabWidget_Plots"));
        tabWidget_Plots->setMaximumSize(QSize(16777215, 122));
        tab_PlotPixel = new QWidget();
        tab_PlotPixel->setObjectName(QString::fromUtf8("tab_PlotPixel"));
        gridLayout_9 = new QGridLayout(tab_PlotPixel);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(9, 9, 9, 9);
        stackedWidget_PlotPixel_Type = new QStackedWidget(tab_PlotPixel);
        stackedWidget_PlotPixel_Type->setObjectName(QString::fromUtf8("stackedWidget_PlotPixel_Type"));
        stackedWidget_PlotPixel_Type->setMaximumSize(QSize(16777215, 50));
        page_PlotPixel_Hist = new QWidget();
        page_PlotPixel_Hist->setObjectName(QString::fromUtf8("page_PlotPixel_Hist"));
        gridLayout_8 = new QGridLayout(page_PlotPixel_Hist);
        gridLayout_8->setSpacing(3);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        comboBox_PlotPixel_Hist_Mode = new QComboBox(page_PlotPixel_Hist);
        comboBox_PlotPixel_Hist_Mode->setObjectName(QString::fromUtf8("comboBox_PlotPixel_Hist_Mode"));
        comboBox_PlotPixel_Hist_Mode->setMinimumSize(QSize(225, 0));
        comboBox_PlotPixel_Hist_Mode->setMaximumSize(QSize(225, 16777215));

        gridLayout_8->addWidget(comboBox_PlotPixel_Hist_Mode, 0, 0, 1, 4);

        line_PlotPixel_Hist = new QFrame(page_PlotPixel_Hist);
        line_PlotPixel_Hist->setObjectName(QString::fromUtf8("line_PlotPixel_Hist"));
        line_PlotPixel_Hist->setFrameShape(QFrame::VLine);
        line_PlotPixel_Hist->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(line_PlotPixel_Hist, 0, 4, 2, 1);

        label_PlotPixel_Hist_X = new QLabel(page_PlotPixel_Hist);
        label_PlotPixel_Hist_X->setObjectName(QString::fromUtf8("label_PlotPixel_Hist_X"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_Hist_X->sizePolicy().hasHeightForWidth());
        label_PlotPixel_Hist_X->setSizePolicy(sizePolicy3);

        gridLayout_8->addWidget(label_PlotPixel_Hist_X, 0, 5, 1, 1);

        comboBox_PlotPixel_Hist_Component = new QComboBox(page_PlotPixel_Hist);
        comboBox_PlotPixel_Hist_Component->setObjectName(QString::fromUtf8("comboBox_PlotPixel_Hist_Component"));

        gridLayout_8->addWidget(comboBox_PlotPixel_Hist_Component, 0, 6, 1, 1);

        label_PlotPixel_Hist_X_Description = new QLabel(page_PlotPixel_Hist);
        label_PlotPixel_Hist_X_Description->setObjectName(QString::fromUtf8("label_PlotPixel_Hist_X_Description"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_Hist_X_Description->sizePolicy().hasHeightForWidth());
        label_PlotPixel_Hist_X_Description->setSizePolicy(sizePolicy3);

        gridLayout_8->addWidget(label_PlotPixel_Hist_X_Description, 0, 7, 1, 1);

        comboBox_PlotPixel_Hist_Image = new QComboBox(page_PlotPixel_Hist);
        comboBox_PlotPixel_Hist_Image->setObjectName(QString::fromUtf8("comboBox_PlotPixel_Hist_Image"));

        gridLayout_8->addWidget(comboBox_PlotPixel_Hist_Image, 0, 8, 1, 1);

        label_PlotPixel_Hist_Classes = new QLabel(page_PlotPixel_Hist);
        label_PlotPixel_Hist_Classes->setObjectName(QString::fromUtf8("label_PlotPixel_Hist_Classes"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_Hist_Classes->sizePolicy().hasHeightForWidth());
        label_PlotPixel_Hist_Classes->setSizePolicy(sizePolicy3);
        label_PlotPixel_Hist_Classes->setMinimumSize(QSize(0, 0));
        label_PlotPixel_Hist_Classes->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_8->addWidget(label_PlotPixel_Hist_Classes, 1, 0, 1, 1);

        spinBox_PlotPixel_Hist_Classes = new QSpinBox(page_PlotPixel_Hist);
        spinBox_PlotPixel_Hist_Classes->setObjectName(QString::fromUtf8("spinBox_PlotPixel_Hist_Classes"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(spinBox_PlotPixel_Hist_Classes->sizePolicy().hasHeightForWidth());
        spinBox_PlotPixel_Hist_Classes->setSizePolicy(sizePolicy5);
        spinBox_PlotPixel_Hist_Classes->setMinimumSize(QSize(98, 0));
        spinBox_PlotPixel_Hist_Classes->setMaximumSize(QSize(16777215, 16777215));
        spinBox_PlotPixel_Hist_Classes->setMinimum(1);
        spinBox_PlotPixel_Hist_Classes->setMaximum(10000);
        spinBox_PlotPixel_Hist_Classes->setSingleStep(10);
        spinBox_PlotPixel_Hist_Classes->setValue(1000);

        gridLayout_8->addWidget(spinBox_PlotPixel_Hist_Classes, 1, 1, 1, 1);

        checkBox_PlotPixel_Hist_Uniform = new QCheckBox(page_PlotPixel_Hist);
        checkBox_PlotPixel_Hist_Uniform->setObjectName(QString::fromUtf8("checkBox_PlotPixel_Hist_Uniform"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(checkBox_PlotPixel_Hist_Uniform->sizePolicy().hasHeightForWidth());
        checkBox_PlotPixel_Hist_Uniform->setSizePolicy(sizePolicy6);
        checkBox_PlotPixel_Hist_Uniform->setMinimumSize(QSize(0, 0));
        checkBox_PlotPixel_Hist_Uniform->setMaximumSize(QSize(16777215, 16777215));
        checkBox_PlotPixel_Hist_Uniform->setChecked(true);

        gridLayout_8->addWidget(checkBox_PlotPixel_Hist_Uniform, 1, 2, 1, 1);

        checkBox_PlotPixel_Hist_Accumulate = new QCheckBox(page_PlotPixel_Hist);
        checkBox_PlotPixel_Hist_Accumulate->setObjectName(QString::fromUtf8("checkBox_PlotPixel_Hist_Accumulate"));
        sizePolicy6.setHeightForWidth(checkBox_PlotPixel_Hist_Accumulate->sizePolicy().hasHeightForWidth());
        checkBox_PlotPixel_Hist_Accumulate->setSizePolicy(sizePolicy6);
        checkBox_PlotPixel_Hist_Accumulate->setMinimumSize(QSize(0, 0));
        checkBox_PlotPixel_Hist_Accumulate->setMaximumSize(QSize(16777215, 16777215));
        checkBox_PlotPixel_Hist_Accumulate->setChecked(true);

        gridLayout_8->addWidget(checkBox_PlotPixel_Hist_Accumulate, 1, 3, 1, 1);

        label_PlotPixel_Hist_Y = new QLabel(page_PlotPixel_Hist);
        label_PlotPixel_Hist_Y->setObjectName(QString::fromUtf8("label_PlotPixel_Hist_Y"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_Hist_Y->sizePolicy().hasHeightForWidth());
        label_PlotPixel_Hist_Y->setSizePolicy(sizePolicy3);

        gridLayout_8->addWidget(label_PlotPixel_Hist_Y, 1, 5, 1, 1);

        label_PlotPixel_Hist_Y_Description = new QLabel(page_PlotPixel_Hist);
        label_PlotPixel_Hist_Y_Description->setObjectName(QString::fromUtf8("label_PlotPixel_Hist_Y_Description"));

        gridLayout_8->addWidget(label_PlotPixel_Hist_Y_Description, 1, 6, 1, 3);

        stackedWidget_PlotPixel_Type->addWidget(page_PlotPixel_Hist);
        page_PlotPixel_Axe = new QWidget();
        page_PlotPixel_Axe->setObjectName(QString::fromUtf8("page_PlotPixel_Axe"));
        gridLayout_10 = new QGridLayout(page_PlotPixel_Axe);
        gridLayout_10->setSpacing(3);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        comboBox_PlotPixel_Axe_Component = new QComboBox(page_PlotPixel_Axe);
        comboBox_PlotPixel_Axe_Component->setObjectName(QString::fromUtf8("comboBox_PlotPixel_Axe_Component"));

        gridLayout_10->addWidget(comboBox_PlotPixel_Axe_Component, 0, 4, 1, 1);

        label_PlotPixel_Axe_X = new QLabel(page_PlotPixel_Axe);
        label_PlotPixel_Axe_X->setObjectName(QString::fromUtf8("label_PlotPixel_Axe_X"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_Axe_X->sizePolicy().hasHeightForWidth());
        label_PlotPixel_Axe_X->setSizePolicy(sizePolicy3);

        gridLayout_10->addWidget(label_PlotPixel_Axe_X, 0, 2, 1, 1);

        label_PlotPixel_Axe_Y = new QLabel(page_PlotPixel_Axe);
        label_PlotPixel_Axe_Y->setObjectName(QString::fromUtf8("label_PlotPixel_Axe_Y"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_Axe_Y->sizePolicy().hasHeightForWidth());
        label_PlotPixel_Axe_Y->setSizePolicy(sizePolicy3);

        gridLayout_10->addWidget(label_PlotPixel_Axe_Y, 1, 2, 1, 1);

        comboBox_PlotPixel_Axe_Axis = new QComboBox(page_PlotPixel_Axe);
        comboBox_PlotPixel_Axe_Axis->setObjectName(QString::fromUtf8("comboBox_PlotPixel_Axe_Axis"));
        sizePolicy1.setHeightForWidth(comboBox_PlotPixel_Axe_Axis->sizePolicy().hasHeightForWidth());
        comboBox_PlotPixel_Axe_Axis->setSizePolicy(sizePolicy1);
        comboBox_PlotPixel_Axe_Axis->setMinimumSize(QSize(225, 0));
        comboBox_PlotPixel_Axe_Axis->setMaximumSize(QSize(225, 16777215));

        gridLayout_10->addWidget(comboBox_PlotPixel_Axe_Axis, 1, 0, 1, 1);

        comboBox_PlotPixel_Axe_Mode = new QComboBox(page_PlotPixel_Axe);
        comboBox_PlotPixel_Axe_Mode->setObjectName(QString::fromUtf8("comboBox_PlotPixel_Axe_Mode"));
        comboBox_PlotPixel_Axe_Mode->setMinimumSize(QSize(225, 0));
        comboBox_PlotPixel_Axe_Mode->setMaximumSize(QSize(225, 16777215));

        gridLayout_10->addWidget(comboBox_PlotPixel_Axe_Mode, 0, 0, 1, 1);

        line_PlotPixel_Axe = new QFrame(page_PlotPixel_Axe);
        line_PlotPixel_Axe->setObjectName(QString::fromUtf8("line_PlotPixel_Axe"));
        line_PlotPixel_Axe->setFrameShape(QFrame::VLine);
        line_PlotPixel_Axe->setFrameShadow(QFrame::Sunken);

        gridLayout_10->addWidget(line_PlotPixel_Axe, 0, 1, 2, 1);

        label_PlotPixel_Axe_X_Description = new QLabel(page_PlotPixel_Axe);
        label_PlotPixel_Axe_X_Description->setObjectName(QString::fromUtf8("label_PlotPixel_Axe_X_Description"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_Axe_X_Description->sizePolicy().hasHeightForWidth());
        label_PlotPixel_Axe_X_Description->setSizePolicy(sizePolicy3);

        gridLayout_10->addWidget(label_PlotPixel_Axe_X_Description, 0, 5, 1, 1);

        comboBox_PlotPixel_Axe_Image = new QComboBox(page_PlotPixel_Axe);
        comboBox_PlotPixel_Axe_Image->setObjectName(QString::fromUtf8("comboBox_PlotPixel_Axe_Image"));

        gridLayout_10->addWidget(comboBox_PlotPixel_Axe_Image, 0, 6, 1, 1);

        comboBox_PlotPixel_Axe_Stat = new QComboBox(page_PlotPixel_Axe);
        comboBox_PlotPixel_Axe_Stat->setObjectName(QString::fromUtf8("comboBox_PlotPixel_Axe_Stat"));

        gridLayout_10->addWidget(comboBox_PlotPixel_Axe_Stat, 1, 4, 1, 3);

        stackedWidget_PlotPixel_Type->addWidget(page_PlotPixel_Axe);
        page_PlotPixel_ScatterValue = new QWidget();
        page_PlotPixel_ScatterValue->setObjectName(QString::fromUtf8("page_PlotPixel_ScatterValue"));
        gridLayout_12 = new QGridLayout(page_PlotPixel_ScatterValue);
        gridLayout_12->setSpacing(3);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        line_PlotPixel_ScatterValue = new QFrame(page_PlotPixel_ScatterValue);
        line_PlotPixel_ScatterValue->setObjectName(QString::fromUtf8("line_PlotPixel_ScatterValue"));
        line_PlotPixel_ScatterValue->setFrameShape(QFrame::VLine);
        line_PlotPixel_ScatterValue->setFrameShadow(QFrame::Sunken);

        gridLayout_12->addWidget(line_PlotPixel_ScatterValue, 0, 1, 2, 1);

        comboBox_PlotPixel_ScatterValue_Image_Y = new QComboBox(page_PlotPixel_ScatterValue);
        comboBox_PlotPixel_ScatterValue_Image_Y->setObjectName(QString::fromUtf8("comboBox_PlotPixel_ScatterValue_Image_Y"));

        gridLayout_12->addWidget(comboBox_PlotPixel_ScatterValue_Image_Y, 1, 3, 1, 1);

        label_PlotPixel_ScatterValue_Y = new QLabel(page_PlotPixel_ScatterValue);
        label_PlotPixel_ScatterValue_Y->setObjectName(QString::fromUtf8("label_PlotPixel_ScatterValue_Y"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_ScatterValue_Y->sizePolicy().hasHeightForWidth());
        label_PlotPixel_ScatterValue_Y->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(label_PlotPixel_ScatterValue_Y, 1, 2, 1, 1);

        comboBox_PlotPixel_ScatterValue_Image_X = new QComboBox(page_PlotPixel_ScatterValue);
        comboBox_PlotPixel_ScatterValue_Image_X->setObjectName(QString::fromUtf8("comboBox_PlotPixel_ScatterValue_Image_X"));

        gridLayout_12->addWidget(comboBox_PlotPixel_ScatterValue_Image_X, 0, 3, 1, 1);

        label_PlotPixel_ScatterValue_X = new QLabel(page_PlotPixel_ScatterValue);
        label_PlotPixel_ScatterValue_X->setObjectName(QString::fromUtf8("label_PlotPixel_ScatterValue_X"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_ScatterValue_X->sizePolicy().hasHeightForWidth());
        label_PlotPixel_ScatterValue_X->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(label_PlotPixel_ScatterValue_X, 0, 2, 1, 1);

        comboBox_PlotPixel_ScatterValue_Component = new QComboBox(page_PlotPixel_ScatterValue);
        comboBox_PlotPixel_ScatterValue_Component->setObjectName(QString::fromUtf8("comboBox_PlotPixel_ScatterValue_Component"));
        sizePolicy1.setHeightForWidth(comboBox_PlotPixel_ScatterValue_Component->sizePolicy().hasHeightForWidth());
        comboBox_PlotPixel_ScatterValue_Component->setSizePolicy(sizePolicy1);
        comboBox_PlotPixel_ScatterValue_Component->setMinimumSize(QSize(225, 0));
        comboBox_PlotPixel_ScatterValue_Component->setMaximumSize(QSize(225, 16777215));

        gridLayout_12->addWidget(comboBox_PlotPixel_ScatterValue_Component, 1, 0, 1, 1);

        comboBox_PlotPixel_ScatterValue_Mode = new QComboBox(page_PlotPixel_ScatterValue);
        comboBox_PlotPixel_ScatterValue_Mode->setObjectName(QString::fromUtf8("comboBox_PlotPixel_ScatterValue_Mode"));
        comboBox_PlotPixel_ScatterValue_Mode->setMinimumSize(QSize(225, 0));
        comboBox_PlotPixel_ScatterValue_Mode->setMaximumSize(QSize(225, 16777215));

        gridLayout_12->addWidget(comboBox_PlotPixel_ScatterValue_Mode, 0, 0, 1, 1);

        stackedWidget_PlotPixel_Type->addWidget(page_PlotPixel_ScatterValue);
        page_PlotPixel_ScatterHist = new QWidget();
        page_PlotPixel_ScatterHist->setObjectName(QString::fromUtf8("page_PlotPixel_ScatterHist"));
        gridLayout_14 = new QGridLayout(page_PlotPixel_ScatterHist);
        gridLayout_14->setSpacing(3);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        line_PlotPixel_ScatterHist = new QFrame(page_PlotPixel_ScatterHist);
        line_PlotPixel_ScatterHist->setObjectName(QString::fromUtf8("line_PlotPixel_ScatterHist"));
        line_PlotPixel_ScatterHist->setFrameShape(QFrame::VLine);
        line_PlotPixel_ScatterHist->setFrameShadow(QFrame::Sunken);

        gridLayout_14->addWidget(line_PlotPixel_ScatterHist, 0, 4, 2, 1);

        label_PlotPixel_ScatterHist_X = new QLabel(page_PlotPixel_ScatterHist);
        label_PlotPixel_ScatterHist_X->setObjectName(QString::fromUtf8("label_PlotPixel_ScatterHist_X"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_ScatterHist_X->sizePolicy().hasHeightForWidth());
        label_PlotPixel_ScatterHist_X->setSizePolicy(sizePolicy3);

        gridLayout_14->addWidget(label_PlotPixel_ScatterHist_X, 0, 5, 1, 1);

        comboBox_PlotPixel_ScatterHist_Component_X = new QComboBox(page_PlotPixel_ScatterHist);
        comboBox_PlotPixel_ScatterHist_Component_X->setObjectName(QString::fromUtf8("comboBox_PlotPixel_ScatterHist_Component_X"));

        gridLayout_14->addWidget(comboBox_PlotPixel_ScatterHist_Component_X, 0, 7, 1, 1);

        checkBox_PlotPixel_ScatterHist_Uniform = new QCheckBox(page_PlotPixel_ScatterHist);
        checkBox_PlotPixel_ScatterHist_Uniform->setObjectName(QString::fromUtf8("checkBox_PlotPixel_ScatterHist_Uniform"));
        sizePolicy6.setHeightForWidth(checkBox_PlotPixel_ScatterHist_Uniform->sizePolicy().hasHeightForWidth());
        checkBox_PlotPixel_ScatterHist_Uniform->setSizePolicy(sizePolicy6);
        checkBox_PlotPixel_ScatterHist_Uniform->setMinimumSize(QSize(0, 0));
        checkBox_PlotPixel_ScatterHist_Uniform->setMaximumSize(QSize(16777215, 16777215));
        checkBox_PlotPixel_ScatterHist_Uniform->setChecked(true);

        gridLayout_14->addWidget(checkBox_PlotPixel_ScatterHist_Uniform, 1, 2, 1, 1);

        checkBox_PlotPixel_ScatterHist_Accumulate = new QCheckBox(page_PlotPixel_ScatterHist);
        checkBox_PlotPixel_ScatterHist_Accumulate->setObjectName(QString::fromUtf8("checkBox_PlotPixel_ScatterHist_Accumulate"));
        sizePolicy6.setHeightForWidth(checkBox_PlotPixel_ScatterHist_Accumulate->sizePolicy().hasHeightForWidth());
        checkBox_PlotPixel_ScatterHist_Accumulate->setSizePolicy(sizePolicy6);
        checkBox_PlotPixel_ScatterHist_Accumulate->setMinimumSize(QSize(0, 0));
        checkBox_PlotPixel_ScatterHist_Accumulate->setMaximumSize(QSize(16777215, 16777215));
        checkBox_PlotPixel_ScatterHist_Accumulate->setChecked(true);

        gridLayout_14->addWidget(checkBox_PlotPixel_ScatterHist_Accumulate, 1, 3, 1, 1);

        label_PlotPixel_ScatterHist_Y = new QLabel(page_PlotPixel_ScatterHist);
        label_PlotPixel_ScatterHist_Y->setObjectName(QString::fromUtf8("label_PlotPixel_ScatterHist_Y"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_ScatterHist_Y->sizePolicy().hasHeightForWidth());
        label_PlotPixel_ScatterHist_Y->setSizePolicy(sizePolicy3);

        gridLayout_14->addWidget(label_PlotPixel_ScatterHist_Y, 1, 5, 1, 1);

        comboBox_PlotPixel_ScatterHist_Component_Y = new QComboBox(page_PlotPixel_ScatterHist);
        comboBox_PlotPixel_ScatterHist_Component_Y->setObjectName(QString::fromUtf8("comboBox_PlotPixel_ScatterHist_Component_Y"));

        gridLayout_14->addWidget(comboBox_PlotPixel_ScatterHist_Component_Y, 1, 7, 1, 1);

        label_PlotPixel_ScatterHist_Classes = new QLabel(page_PlotPixel_ScatterHist);
        label_PlotPixel_ScatterHist_Classes->setObjectName(QString::fromUtf8("label_PlotPixel_ScatterHist_Classes"));
        sizePolicy6.setHeightForWidth(label_PlotPixel_ScatterHist_Classes->sizePolicy().hasHeightForWidth());
        label_PlotPixel_ScatterHist_Classes->setSizePolicy(sizePolicy6);
        label_PlotPixel_ScatterHist_Classes->setMinimumSize(QSize(0, 0));
        label_PlotPixel_ScatterHist_Classes->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_14->addWidget(label_PlotPixel_ScatterHist_Classes, 1, 0, 1, 1);

        spinBox_PlotPixel_ScatterHist_Classes = new QSpinBox(page_PlotPixel_ScatterHist);
        spinBox_PlotPixel_ScatterHist_Classes->setObjectName(QString::fromUtf8("spinBox_PlotPixel_ScatterHist_Classes"));
        sizePolicy5.setHeightForWidth(spinBox_PlotPixel_ScatterHist_Classes->sizePolicy().hasHeightForWidth());
        spinBox_PlotPixel_ScatterHist_Classes->setSizePolicy(sizePolicy5);
        spinBox_PlotPixel_ScatterHist_Classes->setMinimumSize(QSize(98, 0));
        spinBox_PlotPixel_ScatterHist_Classes->setMaximumSize(QSize(98, 16777215));
        spinBox_PlotPixel_ScatterHist_Classes->setMinimum(1);
        spinBox_PlotPixel_ScatterHist_Classes->setMaximum(10000);
        spinBox_PlotPixel_ScatterHist_Classes->setSingleStep(10);
        spinBox_PlotPixel_ScatterHist_Classes->setValue(1000);

        gridLayout_14->addWidget(spinBox_PlotPixel_ScatterHist_Classes, 1, 1, 1, 1);

        comboBox_PlotPixel_ScatterHist_Mode = new QComboBox(page_PlotPixel_ScatterHist);
        comboBox_PlotPixel_ScatterHist_Mode->setObjectName(QString::fromUtf8("comboBox_PlotPixel_ScatterHist_Mode"));
        comboBox_PlotPixel_ScatterHist_Mode->setMinimumSize(QSize(225, 0));
        comboBox_PlotPixel_ScatterHist_Mode->setMaximumSize(QSize(225, 16777215));

        gridLayout_14->addWidget(comboBox_PlotPixel_ScatterHist_Mode, 0, 0, 1, 4);

        label_PlotPixel_ScatterHist_Y_Description = new QLabel(page_PlotPixel_ScatterHist);
        label_PlotPixel_ScatterHist_Y_Description->setObjectName(QString::fromUtf8("label_PlotPixel_ScatterHist_Y_Description"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_ScatterHist_Y_Description->sizePolicy().hasHeightForWidth());
        label_PlotPixel_ScatterHist_Y_Description->setSizePolicy(sizePolicy3);

        gridLayout_14->addWidget(label_PlotPixel_ScatterHist_Y_Description, 1, 8, 1, 1);

        label_PlotPixel_ScatterHist_X_Description = new QLabel(page_PlotPixel_ScatterHist);
        label_PlotPixel_ScatterHist_X_Description->setObjectName(QString::fromUtf8("label_PlotPixel_ScatterHist_X_Description"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_ScatterHist_X_Description->sizePolicy().hasHeightForWidth());
        label_PlotPixel_ScatterHist_X_Description->setSizePolicy(sizePolicy3);

        gridLayout_14->addWidget(label_PlotPixel_ScatterHist_X_Description, 0, 8, 1, 1);

        comboBox_PlotPixel_ScatterHist_Image_X = new QComboBox(page_PlotPixel_ScatterHist);
        comboBox_PlotPixel_ScatterHist_Image_X->setObjectName(QString::fromUtf8("comboBox_PlotPixel_ScatterHist_Image_X"));

        gridLayout_14->addWidget(comboBox_PlotPixel_ScatterHist_Image_X, 0, 9, 1, 1);

        comboBox_PlotPixel_ScatterHist_Image_Y = new QComboBox(page_PlotPixel_ScatterHist);
        comboBox_PlotPixel_ScatterHist_Image_Y->setObjectName(QString::fromUtf8("comboBox_PlotPixel_ScatterHist_Image_Y"));

        gridLayout_14->addWidget(comboBox_PlotPixel_ScatterHist_Image_Y, 1, 9, 1, 1);

        stackedWidget_PlotPixel_Type->addWidget(page_PlotPixel_ScatterHist);
        page_PlotPixel_ScatterAxe = new QWidget();
        page_PlotPixel_ScatterAxe->setObjectName(QString::fromUtf8("page_PlotPixel_ScatterAxe"));
        gridLayout_16 = new QGridLayout(page_PlotPixel_ScatterAxe);
        gridLayout_16->setSpacing(3);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        comboBox_PlotPixel_ScatterAxe_Image_X = new QComboBox(page_PlotPixel_ScatterAxe);
        comboBox_PlotPixel_ScatterAxe_Image_X->setObjectName(QString::fromUtf8("comboBox_PlotPixel_ScatterAxe_Image_X"));

        gridLayout_16->addWidget(comboBox_PlotPixel_ScatterAxe_Image_X, 0, 8, 1, 1);

        comboBox_PlotPixel_ScatterAxe_Image_Y = new QComboBox(page_PlotPixel_ScatterAxe);
        comboBox_PlotPixel_ScatterAxe_Image_Y->setObjectName(QString::fromUtf8("comboBox_PlotPixel_ScatterAxe_Image_Y"));

        gridLayout_16->addWidget(comboBox_PlotPixel_ScatterAxe_Image_Y, 1, 8, 1, 1);

        line_PlotPixel_ScatterAxe = new QFrame(page_PlotPixel_ScatterAxe);
        line_PlotPixel_ScatterAxe->setObjectName(QString::fromUtf8("line_PlotPixel_ScatterAxe"));
        line_PlotPixel_ScatterAxe->setFrameShape(QFrame::VLine);
        line_PlotPixel_ScatterAxe->setFrameShadow(QFrame::Sunken);

        gridLayout_16->addWidget(line_PlotPixel_ScatterAxe, 0, 4, 2, 1);

        label_PlotPixel_ScatterAxe_X = new QLabel(page_PlotPixel_ScatterAxe);
        label_PlotPixel_ScatterAxe_X->setObjectName(QString::fromUtf8("label_PlotPixel_ScatterAxe_X"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_ScatterAxe_X->sizePolicy().hasHeightForWidth());
        label_PlotPixel_ScatterAxe_X->setSizePolicy(sizePolicy3);

        gridLayout_16->addWidget(label_PlotPixel_ScatterAxe_X, 0, 5, 1, 1);

        label_PlotPixel_ScatterAxe_Y = new QLabel(page_PlotPixel_ScatterAxe);
        label_PlotPixel_ScatterAxe_Y->setObjectName(QString::fromUtf8("label_PlotPixel_ScatterAxe_Y"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_ScatterAxe_Y->sizePolicy().hasHeightForWidth());
        label_PlotPixel_ScatterAxe_Y->setSizePolicy(sizePolicy3);

        gridLayout_16->addWidget(label_PlotPixel_ScatterAxe_Y, 1, 5, 1, 1);

        label_PlotPixel_ScatterAxe_X_Description = new QLabel(page_PlotPixel_ScatterAxe);
        label_PlotPixel_ScatterAxe_X_Description->setObjectName(QString::fromUtf8("label_PlotPixel_ScatterAxe_X_Description"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_ScatterAxe_X_Description->sizePolicy().hasHeightForWidth());
        label_PlotPixel_ScatterAxe_X_Description->setSizePolicy(sizePolicy3);

        gridLayout_16->addWidget(label_PlotPixel_ScatterAxe_X_Description, 0, 7, 1, 1);

        label_PlotPixel_ScatterAxe_Y_Description = new QLabel(page_PlotPixel_ScatterAxe);
        label_PlotPixel_ScatterAxe_Y_Description->setObjectName(QString::fromUtf8("label_PlotPixel_ScatterAxe_Y_Description"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_ScatterAxe_Y_Description->sizePolicy().hasHeightForWidth());
        label_PlotPixel_ScatterAxe_Y_Description->setSizePolicy(sizePolicy3);

        gridLayout_16->addWidget(label_PlotPixel_ScatterAxe_Y_Description, 1, 7, 1, 1);

        comboBox_PlotPixel_ScatterAxe_Stat_Y = new QComboBox(page_PlotPixel_ScatterAxe);
        comboBox_PlotPixel_ScatterAxe_Stat_Y->setObjectName(QString::fromUtf8("comboBox_PlotPixel_ScatterAxe_Stat_Y"));

        gridLayout_16->addWidget(comboBox_PlotPixel_ScatterAxe_Stat_Y, 1, 6, 1, 1);

        comboBox_PlotPixel_ScatterAxe_Component = new QComboBox(page_PlotPixel_ScatterAxe);
        comboBox_PlotPixel_ScatterAxe_Component->setObjectName(QString::fromUtf8("comboBox_PlotPixel_ScatterAxe_Component"));
        sizePolicy1.setHeightForWidth(comboBox_PlotPixel_ScatterAxe_Component->sizePolicy().hasHeightForWidth());
        comboBox_PlotPixel_ScatterAxe_Component->setSizePolicy(sizePolicy1);
        comboBox_PlotPixel_ScatterAxe_Component->setMinimumSize(QSize(0, 0));
        comboBox_PlotPixel_ScatterAxe_Component->setMaximumSize(QSize(105, 16777215));

        gridLayout_16->addWidget(comboBox_PlotPixel_ScatterAxe_Component, 1, 2, 1, 1);

        comboBox_PlotPixel_ScatterAxe_Stat_X = new QComboBox(page_PlotPixel_ScatterAxe);
        comboBox_PlotPixel_ScatterAxe_Stat_X->setObjectName(QString::fromUtf8("comboBox_PlotPixel_ScatterAxe_Stat_X"));

        gridLayout_16->addWidget(comboBox_PlotPixel_ScatterAxe_Stat_X, 0, 6, 1, 1);

        label_PlotPixel_ScatterAxe_Description = new QLabel(page_PlotPixel_ScatterAxe);
        label_PlotPixel_ScatterAxe_Description->setObjectName(QString::fromUtf8("label_PlotPixel_ScatterAxe_Description"));
        sizePolicy3.setHeightForWidth(label_PlotPixel_ScatterAxe_Description->sizePolicy().hasHeightForWidth());
        label_PlotPixel_ScatterAxe_Description->setSizePolicy(sizePolicy3);

        gridLayout_16->addWidget(label_PlotPixel_ScatterAxe_Description, 1, 1, 1, 1);

        comboBox_PlotPixel_ScatterAxe_Axis = new QComboBox(page_PlotPixel_ScatterAxe);
        comboBox_PlotPixel_ScatterAxe_Axis->setObjectName(QString::fromUtf8("comboBox_PlotPixel_ScatterAxe_Axis"));
        sizePolicy1.setHeightForWidth(comboBox_PlotPixel_ScatterAxe_Axis->sizePolicy().hasHeightForWidth());
        comboBox_PlotPixel_ScatterAxe_Axis->setSizePolicy(sizePolicy1);
        comboBox_PlotPixel_ScatterAxe_Axis->setMinimumSize(QSize(0, 0));
        comboBox_PlotPixel_ScatterAxe_Axis->setMaximumSize(QSize(105, 16777215));

        gridLayout_16->addWidget(comboBox_PlotPixel_ScatterAxe_Axis, 1, 0, 1, 1);

        comboBox_PlotPixel_ScatterAxe_Mode = new QComboBox(page_PlotPixel_ScatterAxe);
        comboBox_PlotPixel_ScatterAxe_Mode->setObjectName(QString::fromUtf8("comboBox_PlotPixel_ScatterAxe_Mode"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(comboBox_PlotPixel_ScatterAxe_Mode->sizePolicy().hasHeightForWidth());
        comboBox_PlotPixel_ScatterAxe_Mode->setSizePolicy(sizePolicy7);
        comboBox_PlotPixel_ScatterAxe_Mode->setMinimumSize(QSize(225, 0));
        comboBox_PlotPixel_ScatterAxe_Mode->setMaximumSize(QSize(225, 16777215));

        gridLayout_16->addWidget(comboBox_PlotPixel_ScatterAxe_Mode, 0, 0, 1, 3);

        stackedWidget_PlotPixel_Type->addWidget(page_PlotPixel_ScatterAxe);

        gridLayout_9->addWidget(stackedWidget_PlotPixel_Type, 2, 0, 1, 2);

        line_PlotPixel = new QFrame(tab_PlotPixel);
        line_PlotPixel->setObjectName(QString::fromUtf8("line_PlotPixel"));
        line_PlotPixel->setFrameShape(QFrame::HLine);
        line_PlotPixel->setFrameShadow(QFrame::Sunken);

        gridLayout_9->addWidget(line_PlotPixel, 1, 0, 1, 2);

        comboBox_PlotPixel_Type = new QComboBox(tab_PlotPixel);
        comboBox_PlotPixel_Type->setObjectName(QString::fromUtf8("comboBox_PlotPixel_Type"));

        gridLayout_9->addWidget(comboBox_PlotPixel_Type, 0, 0, 1, 2);

        tabWidget_Plots->addTab(tab_PlotPixel, QString());
        tab_PlotComp = new QWidget();
        tab_PlotComp->setObjectName(QString::fromUtf8("tab_PlotComp"));
        gridLayout_11 = new QGridLayout(tab_PlotComp);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(9, 9, 9, 9);
        comboBox_PlotComp_Type = new QComboBox(tab_PlotComp);
        comboBox_PlotComp_Type->setObjectName(QString::fromUtf8("comboBox_PlotComp_Type"));

        gridLayout_11->addWidget(comboBox_PlotComp_Type, 0, 0, 1, 1);

        line_PlotComp = new QFrame(tab_PlotComp);
        line_PlotComp->setObjectName(QString::fromUtf8("line_PlotComp"));
        line_PlotComp->setFrameShape(QFrame::HLine);
        line_PlotComp->setFrameShadow(QFrame::Sunken);

        gridLayout_11->addWidget(line_PlotComp, 1, 0, 1, 1);

        stackedWidget_PlotComp_Type = new QStackedWidget(tab_PlotComp);
        stackedWidget_PlotComp_Type->setObjectName(QString::fromUtf8("stackedWidget_PlotComp_Type"));
        stackedWidget_PlotComp_Type->setMaximumSize(QSize(16777215, 50));
        page_PlotComp_Feat = new QWidget();
        page_PlotComp_Feat->setObjectName(QString::fromUtf8("page_PlotComp_Feat"));
        gridLayout_17 = new QGridLayout(page_PlotComp_Feat);
        gridLayout_17->setSpacing(3);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        label_PlotComp_Feat_Y = new QLabel(page_PlotComp_Feat);
        label_PlotComp_Feat_Y->setObjectName(QString::fromUtf8("label_PlotComp_Feat_Y"));
        sizePolicy3.setHeightForWidth(label_PlotComp_Feat_Y->sizePolicy().hasHeightForWidth());
        label_PlotComp_Feat_Y->setSizePolicy(sizePolicy3);

        gridLayout_17->addWidget(label_PlotComp_Feat_Y, 1, 3, 1, 1);

        line_PlotComp_Feat = new QFrame(page_PlotComp_Feat);
        line_PlotComp_Feat->setObjectName(QString::fromUtf8("line_PlotComp_Feat"));
        line_PlotComp_Feat->setFrameShape(QFrame::VLine);
        line_PlotComp_Feat->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line_PlotComp_Feat, 0, 2, 2, 1);

        label_PlotComp_Feat_X = new QLabel(page_PlotComp_Feat);
        label_PlotComp_Feat_X->setObjectName(QString::fromUtf8("label_PlotComp_Feat_X"));
        sizePolicy3.setHeightForWidth(label_PlotComp_Feat_X->sizePolicy().hasHeightForWidth());
        label_PlotComp_Feat_X->setSizePolicy(sizePolicy3);

        gridLayout_17->addWidget(label_PlotComp_Feat_X, 0, 3, 1, 1);

        comboBox_PlotComp_Feat_Feature = new QComboBox(page_PlotComp_Feat);
        comboBox_PlotComp_Feat_Feature->setObjectName(QString::fromUtf8("comboBox_PlotComp_Feat_Feature"));

        gridLayout_17->addWidget(comboBox_PlotComp_Feat_Feature, 1, 4, 1, 1);

        label_PlotComp_Feat_X_Description = new QLabel(page_PlotComp_Feat);
        label_PlotComp_Feat_X_Description->setObjectName(QString::fromUtf8("label_PlotComp_Feat_X_Description"));

        gridLayout_17->addWidget(label_PlotComp_Feat_X_Description, 0, 4, 1, 1);

        horizontalSpacer_PlotComp_Feat = new QSpacerItem(225, 40, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_17->addItem(horizontalSpacer_PlotComp_Feat, 0, 1, 2, 1);

        stackedWidget_PlotComp_Type->addWidget(page_PlotComp_Feat);
        page_PlotComp_FeatHist = new QWidget();
        page_PlotComp_FeatHist->setObjectName(QString::fromUtf8("page_PlotComp_FeatHist"));
        gridLayout_18 = new QGridLayout(page_PlotComp_FeatHist);
        gridLayout_18->setSpacing(3);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        label_PlotComp_FeatHist_Y = new QLabel(page_PlotComp_FeatHist);
        label_PlotComp_FeatHist_Y->setObjectName(QString::fromUtf8("label_PlotComp_FeatHist_Y"));
        sizePolicy3.setHeightForWidth(label_PlotComp_FeatHist_Y->sizePolicy().hasHeightForWidth());
        label_PlotComp_FeatHist_Y->setSizePolicy(sizePolicy3);

        gridLayout_18->addWidget(label_PlotComp_FeatHist_Y, 1, 5, 1, 1);

        line_PlotComp_FeatHist = new QFrame(page_PlotComp_FeatHist);
        line_PlotComp_FeatHist->setObjectName(QString::fromUtf8("line_PlotComp_FeatHist"));
        line_PlotComp_FeatHist->setFrameShape(QFrame::VLine);
        line_PlotComp_FeatHist->setFrameShadow(QFrame::Sunken);

        gridLayout_18->addWidget(line_PlotComp_FeatHist, 0, 4, 2, 1);

        label_PlotComp_FeatHist_X = new QLabel(page_PlotComp_FeatHist);
        label_PlotComp_FeatHist_X->setObjectName(QString::fromUtf8("label_PlotComp_FeatHist_X"));
        sizePolicy3.setHeightForWidth(label_PlotComp_FeatHist_X->sizePolicy().hasHeightForWidth());
        label_PlotComp_FeatHist_X->setSizePolicy(sizePolicy3);

        gridLayout_18->addWidget(label_PlotComp_FeatHist_X, 0, 5, 1, 1);

        checkBox_PlotComp_FeatHist_Accumulate = new QCheckBox(page_PlotComp_FeatHist);
        checkBox_PlotComp_FeatHist_Accumulate->setObjectName(QString::fromUtf8("checkBox_PlotComp_FeatHist_Accumulate"));
        sizePolicy6.setHeightForWidth(checkBox_PlotComp_FeatHist_Accumulate->sizePolicy().hasHeightForWidth());
        checkBox_PlotComp_FeatHist_Accumulate->setSizePolicy(sizePolicy6);
        checkBox_PlotComp_FeatHist_Accumulate->setChecked(true);

        gridLayout_18->addWidget(checkBox_PlotComp_FeatHist_Accumulate, 1, 3, 1, 1);

        spinBox_PlotComp_FeatHist_Classes = new QSpinBox(page_PlotComp_FeatHist);
        spinBox_PlotComp_FeatHist_Classes->setObjectName(QString::fromUtf8("spinBox_PlotComp_FeatHist_Classes"));
        sizePolicy5.setHeightForWidth(spinBox_PlotComp_FeatHist_Classes->sizePolicy().hasHeightForWidth());
        spinBox_PlotComp_FeatHist_Classes->setSizePolicy(sizePolicy5);
        spinBox_PlotComp_FeatHist_Classes->setMinimumSize(QSize(98, 0));
        spinBox_PlotComp_FeatHist_Classes->setMinimum(1);
        spinBox_PlotComp_FeatHist_Classes->setMaximum(10000);
        spinBox_PlotComp_FeatHist_Classes->setSingleStep(10);
        spinBox_PlotComp_FeatHist_Classes->setValue(1000);

        gridLayout_18->addWidget(spinBox_PlotComp_FeatHist_Classes, 1, 1, 1, 1);

        checkBox_PlotComp_FeatHist_Uniform = new QCheckBox(page_PlotComp_FeatHist);
        checkBox_PlotComp_FeatHist_Uniform->setObjectName(QString::fromUtf8("checkBox_PlotComp_FeatHist_Uniform"));
        sizePolicy6.setHeightForWidth(checkBox_PlotComp_FeatHist_Uniform->sizePolicy().hasHeightForWidth());
        checkBox_PlotComp_FeatHist_Uniform->setSizePolicy(sizePolicy6);
        checkBox_PlotComp_FeatHist_Uniform->setChecked(true);

        gridLayout_18->addWidget(checkBox_PlotComp_FeatHist_Uniform, 1, 2, 1, 1);

        label_PlotComp_FeatHist_Classes = new QLabel(page_PlotComp_FeatHist);
        label_PlotComp_FeatHist_Classes->setObjectName(QString::fromUtf8("label_PlotComp_FeatHist_Classes"));
        sizePolicy3.setHeightForWidth(label_PlotComp_FeatHist_Classes->sizePolicy().hasHeightForWidth());
        label_PlotComp_FeatHist_Classes->setSizePolicy(sizePolicy3);

        gridLayout_18->addWidget(label_PlotComp_FeatHist_Classes, 1, 0, 1, 1);

        label_PlotComp_FeatHist_Y_Description = new QLabel(page_PlotComp_FeatHist);
        label_PlotComp_FeatHist_Y_Description->setObjectName(QString::fromUtf8("label_PlotComp_FeatHist_Y_Description"));

        gridLayout_18->addWidget(label_PlotComp_FeatHist_Y_Description, 1, 6, 1, 2);

        comboBox_PlotComp_FeatHist_Feature = new QComboBox(page_PlotComp_FeatHist);
        comboBox_PlotComp_FeatHist_Feature->setObjectName(QString::fromUtf8("comboBox_PlotComp_FeatHist_Feature"));

        gridLayout_18->addWidget(comboBox_PlotComp_FeatHist_Feature, 0, 6, 1, 2);

        horizontalSpacer_PlotComp_FeatHist = new QSpacerItem(225, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_18->addItem(horizontalSpacer_PlotComp_FeatHist, 0, 0, 1, 4);

        stackedWidget_PlotComp_Type->addWidget(page_PlotComp_FeatHist);
        page_PlotComp_FeatScatter = new QWidget();
        page_PlotComp_FeatScatter->setObjectName(QString::fromUtf8("page_PlotComp_FeatScatter"));
        gridLayout_19 = new QGridLayout(page_PlotComp_FeatScatter);
        gridLayout_19->setSpacing(3);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setContentsMargins(0, 0, 0, 0);
        label_PlotComp_FeatScatter_Y = new QLabel(page_PlotComp_FeatScatter);
        label_PlotComp_FeatScatter_Y->setObjectName(QString::fromUtf8("label_PlotComp_FeatScatter_Y"));
        sizePolicy3.setHeightForWidth(label_PlotComp_FeatScatter_Y->sizePolicy().hasHeightForWidth());
        label_PlotComp_FeatScatter_Y->setSizePolicy(sizePolicy3);

        gridLayout_19->addWidget(label_PlotComp_FeatScatter_Y, 1, 2, 1, 1);

        comboBox_PlotComp_FeatScatter_Feature_Y = new QComboBox(page_PlotComp_FeatScatter);
        comboBox_PlotComp_FeatScatter_Feature_Y->setObjectName(QString::fromUtf8("comboBox_PlotComp_FeatScatter_Feature_Y"));

        gridLayout_19->addWidget(comboBox_PlotComp_FeatScatter_Feature_Y, 1, 3, 1, 1);

        line_PlotComp_FeatScatter = new QFrame(page_PlotComp_FeatScatter);
        line_PlotComp_FeatScatter->setObjectName(QString::fromUtf8("line_PlotComp_FeatScatter"));
        line_PlotComp_FeatScatter->setFrameShape(QFrame::VLine);
        line_PlotComp_FeatScatter->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line_PlotComp_FeatScatter, 0, 1, 2, 1);

        label_PlotComp_FeatScatter_X = new QLabel(page_PlotComp_FeatScatter);
        label_PlotComp_FeatScatter_X->setObjectName(QString::fromUtf8("label_PlotComp_FeatScatter_X"));
        sizePolicy3.setHeightForWidth(label_PlotComp_FeatScatter_X->sizePolicy().hasHeightForWidth());
        label_PlotComp_FeatScatter_X->setSizePolicy(sizePolicy3);

        gridLayout_19->addWidget(label_PlotComp_FeatScatter_X, 0, 2, 1, 1);

        comboBox_PlotComp_FeatScatter_Feature_X = new QComboBox(page_PlotComp_FeatScatter);
        comboBox_PlotComp_FeatScatter_Feature_X->setObjectName(QString::fromUtf8("comboBox_PlotComp_FeatScatter_Feature_X"));

        gridLayout_19->addWidget(comboBox_PlotComp_FeatScatter_Feature_X, 0, 3, 1, 1);

        horizontalSpacer_PlotComp_FeatScatter = new QSpacerItem(225, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_19->addItem(horizontalSpacer_PlotComp_FeatScatter, 1, 0, 1, 1);

        stackedWidget_PlotComp_Type->addWidget(page_PlotComp_FeatScatter);
        page_PlotComp_Stat = new QWidget();
        page_PlotComp_Stat->setObjectName(QString::fromUtf8("page_PlotComp_Stat"));
        gridLayout_20 = new QGridLayout(page_PlotComp_Stat);
        gridLayout_20->setSpacing(3);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        gridLayout_20->setContentsMargins(0, 0, 0, 0);
        comboBox_PlotComp_Stat_Mode = new QComboBox(page_PlotComp_Stat);
        comboBox_PlotComp_Stat_Mode->setObjectName(QString::fromUtf8("comboBox_PlotComp_Stat_Mode"));
        sizePolicy5.setHeightForWidth(comboBox_PlotComp_Stat_Mode->sizePolicy().hasHeightForWidth());
        comboBox_PlotComp_Stat_Mode->setSizePolicy(sizePolicy5);
        comboBox_PlotComp_Stat_Mode->setMinimumSize(QSize(225, 0));
        comboBox_PlotComp_Stat_Mode->setMaximumSize(QSize(225, 16777215));

        gridLayout_20->addWidget(comboBox_PlotComp_Stat_Mode, 0, 0, 1, 1);

        line_PlotComp_Stat = new QFrame(page_PlotComp_Stat);
        line_PlotComp_Stat->setObjectName(QString::fromUtf8("line_PlotComp_Stat"));
        line_PlotComp_Stat->setFrameShape(QFrame::VLine);
        line_PlotComp_Stat->setFrameShadow(QFrame::Sunken);

        gridLayout_20->addWidget(line_PlotComp_Stat, 0, 1, 2, 1);

        label_PlotComp_Stat_X = new QLabel(page_PlotComp_Stat);
        label_PlotComp_Stat_X->setObjectName(QString::fromUtf8("label_PlotComp_Stat_X"));
        sizePolicy3.setHeightForWidth(label_PlotComp_Stat_X->sizePolicy().hasHeightForWidth());
        label_PlotComp_Stat_X->setSizePolicy(sizePolicy3);

        gridLayout_20->addWidget(label_PlotComp_Stat_X, 0, 2, 1, 1);

        comboBox_PlotComp_Stat_Image = new QComboBox(page_PlotComp_Stat);
        comboBox_PlotComp_Stat_Image->setObjectName(QString::fromUtf8("comboBox_PlotComp_Stat_Image"));

        gridLayout_20->addWidget(comboBox_PlotComp_Stat_Image, 0, 3, 1, 1);

        label_PlotComp_Stat_Y = new QLabel(page_PlotComp_Stat);
        label_PlotComp_Stat_Y->setObjectName(QString::fromUtf8("label_PlotComp_Stat_Y"));
        sizePolicy3.setHeightForWidth(label_PlotComp_Stat_Y->sizePolicy().hasHeightForWidth());
        label_PlotComp_Stat_Y->setSizePolicy(sizePolicy3);

        gridLayout_20->addWidget(label_PlotComp_Stat_Y, 1, 2, 1, 1);

        comboBox_PlotComp_Stat_Stat = new QComboBox(page_PlotComp_Stat);
        comboBox_PlotComp_Stat_Stat->setObjectName(QString::fromUtf8("comboBox_PlotComp_Stat_Stat"));

        gridLayout_20->addWidget(comboBox_PlotComp_Stat_Stat, 1, 3, 1, 1);

        stackedWidget_PlotComp_Type->addWidget(page_PlotComp_Stat);
        page_PlotComp_StatHist = new QWidget();
        page_PlotComp_StatHist->setObjectName(QString::fromUtf8("page_PlotComp_StatHist"));
        gridLayout_21 = new QGridLayout(page_PlotComp_StatHist);
        gridLayout_21->setSpacing(3);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        gridLayout_21->setContentsMargins(0, 0, 0, 0);
        comboBox_PlotComp_StatHist_Mode = new QComboBox(page_PlotComp_StatHist);
        comboBox_PlotComp_StatHist_Mode->setObjectName(QString::fromUtf8("comboBox_PlotComp_StatHist_Mode"));
        sizePolicy5.setHeightForWidth(comboBox_PlotComp_StatHist_Mode->sizePolicy().hasHeightForWidth());
        comboBox_PlotComp_StatHist_Mode->setSizePolicy(sizePolicy5);
        comboBox_PlotComp_StatHist_Mode->setMinimumSize(QSize(225, 0));
        comboBox_PlotComp_StatHist_Mode->setMaximumSize(QSize(225, 16777215));

        gridLayout_21->addWidget(comboBox_PlotComp_StatHist_Mode, 0, 0, 1, 4);

        line_PlotComp_StatHist = new QFrame(page_PlotComp_StatHist);
        line_PlotComp_StatHist->setObjectName(QString::fromUtf8("line_PlotComp_StatHist"));
        line_PlotComp_StatHist->setFrameShape(QFrame::VLine);
        line_PlotComp_StatHist->setFrameShadow(QFrame::Sunken);

        gridLayout_21->addWidget(line_PlotComp_StatHist, 0, 4, 2, 1);

        label_PlotComp_StatHist_X = new QLabel(page_PlotComp_StatHist);
        label_PlotComp_StatHist_X->setObjectName(QString::fromUtf8("label_PlotComp_StatHist_X"));
        sizePolicy3.setHeightForWidth(label_PlotComp_StatHist_X->sizePolicy().hasHeightForWidth());
        label_PlotComp_StatHist_X->setSizePolicy(sizePolicy3);

        gridLayout_21->addWidget(label_PlotComp_StatHist_X, 0, 5, 1, 1);

        label_PlotComp_StatHist_Classes = new QLabel(page_PlotComp_StatHist);
        label_PlotComp_StatHist_Classes->setObjectName(QString::fromUtf8("label_PlotComp_StatHist_Classes"));
        sizePolicy3.setHeightForWidth(label_PlotComp_StatHist_Classes->sizePolicy().hasHeightForWidth());
        label_PlotComp_StatHist_Classes->setSizePolicy(sizePolicy3);

        gridLayout_21->addWidget(label_PlotComp_StatHist_Classes, 1, 0, 1, 1);

        spinBox_PlotComp_StatHist_Classes = new QSpinBox(page_PlotComp_StatHist);
        spinBox_PlotComp_StatHist_Classes->setObjectName(QString::fromUtf8("spinBox_PlotComp_StatHist_Classes"));
        sizePolicy5.setHeightForWidth(spinBox_PlotComp_StatHist_Classes->sizePolicy().hasHeightForWidth());
        spinBox_PlotComp_StatHist_Classes->setSizePolicy(sizePolicy5);
        spinBox_PlotComp_StatHist_Classes->setMinimumSize(QSize(98, 0));
        spinBox_PlotComp_StatHist_Classes->setMaximumSize(QSize(98, 16777215));
        spinBox_PlotComp_StatHist_Classes->setMinimum(1);
        spinBox_PlotComp_StatHist_Classes->setMaximum(10000);
        spinBox_PlotComp_StatHist_Classes->setSingleStep(10);
        spinBox_PlotComp_StatHist_Classes->setValue(1000);

        gridLayout_21->addWidget(spinBox_PlotComp_StatHist_Classes, 1, 1, 1, 1);

        checkBox_PlotComp_StatHist_Uniform = new QCheckBox(page_PlotComp_StatHist);
        checkBox_PlotComp_StatHist_Uniform->setObjectName(QString::fromUtf8("checkBox_PlotComp_StatHist_Uniform"));
        sizePolicy6.setHeightForWidth(checkBox_PlotComp_StatHist_Uniform->sizePolicy().hasHeightForWidth());
        checkBox_PlotComp_StatHist_Uniform->setSizePolicy(sizePolicy6);
        checkBox_PlotComp_StatHist_Uniform->setChecked(true);

        gridLayout_21->addWidget(checkBox_PlotComp_StatHist_Uniform, 1, 2, 1, 1);

        checkBox_PlotComp_StatHist_Accumulate = new QCheckBox(page_PlotComp_StatHist);
        checkBox_PlotComp_StatHist_Accumulate->setObjectName(QString::fromUtf8("checkBox_PlotComp_StatHist_Accumulate"));
        sizePolicy6.setHeightForWidth(checkBox_PlotComp_StatHist_Accumulate->sizePolicy().hasHeightForWidth());
        checkBox_PlotComp_StatHist_Accumulate->setSizePolicy(sizePolicy6);
        checkBox_PlotComp_StatHist_Accumulate->setChecked(true);

        gridLayout_21->addWidget(checkBox_PlotComp_StatHist_Accumulate, 1, 3, 1, 1);

        label_PlotComp_StatHist_Y = new QLabel(page_PlotComp_StatHist);
        label_PlotComp_StatHist_Y->setObjectName(QString::fromUtf8("label_PlotComp_StatHist_Y"));
        sizePolicy3.setHeightForWidth(label_PlotComp_StatHist_Y->sizePolicy().hasHeightForWidth());
        label_PlotComp_StatHist_Y->setSizePolicy(sizePolicy3);

        gridLayout_21->addWidget(label_PlotComp_StatHist_Y, 1, 5, 1, 1);

        label_PlotComp_StatHist_X_Description = new QLabel(page_PlotComp_StatHist);
        label_PlotComp_StatHist_X_Description->setObjectName(QString::fromUtf8("label_PlotComp_StatHist_X_Description"));
        sizePolicy3.setHeightForWidth(label_PlotComp_StatHist_X_Description->sizePolicy().hasHeightForWidth());
        label_PlotComp_StatHist_X_Description->setSizePolicy(sizePolicy3);

        gridLayout_21->addWidget(label_PlotComp_StatHist_X_Description, 0, 7, 1, 1);

        comboBox_PlotComp_StatHist_Stat = new QComboBox(page_PlotComp_StatHist);
        comboBox_PlotComp_StatHist_Stat->setObjectName(QString::fromUtf8("comboBox_PlotComp_StatHist_Stat"));

        gridLayout_21->addWidget(comboBox_PlotComp_StatHist_Stat, 0, 6, 1, 1);

        comboBox_PlotComp_StatHist_Image = new QComboBox(page_PlotComp_StatHist);
        comboBox_PlotComp_StatHist_Image->setObjectName(QString::fromUtf8("comboBox_PlotComp_StatHist_Image"));

        gridLayout_21->addWidget(comboBox_PlotComp_StatHist_Image, 0, 8, 1, 1);

        label_PlotComp_StatHist_Y_Description = new QLabel(page_PlotComp_StatHist);
        label_PlotComp_StatHist_Y_Description->setObjectName(QString::fromUtf8("label_PlotComp_StatHist_Y_Description"));

        gridLayout_21->addWidget(label_PlotComp_StatHist_Y_Description, 1, 6, 1, 3);

        stackedWidget_PlotComp_Type->addWidget(page_PlotComp_StatHist);
        page_PlotComp_StatScatter = new QWidget();
        page_PlotComp_StatScatter->setObjectName(QString::fromUtf8("page_PlotComp_StatScatter"));
        gridLayout_22 = new QGridLayout(page_PlotComp_StatScatter);
        gridLayout_22->setSpacing(3);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        gridLayout_22->setContentsMargins(0, 0, 0, 0);
        comboBox_PlotComp_StatScatter_Mode = new QComboBox(page_PlotComp_StatScatter);
        comboBox_PlotComp_StatScatter_Mode->setObjectName(QString::fromUtf8("comboBox_PlotComp_StatScatter_Mode"));
        sizePolicy5.setHeightForWidth(comboBox_PlotComp_StatScatter_Mode->sizePolicy().hasHeightForWidth());
        comboBox_PlotComp_StatScatter_Mode->setSizePolicy(sizePolicy5);
        comboBox_PlotComp_StatScatter_Mode->setMinimumSize(QSize(225, 0));
        comboBox_PlotComp_StatScatter_Mode->setMaximumSize(QSize(225, 16777215));

        gridLayout_22->addWidget(comboBox_PlotComp_StatScatter_Mode, 0, 0, 1, 1);

        line_PlotComp_StatScatter = new QFrame(page_PlotComp_StatScatter);
        line_PlotComp_StatScatter->setObjectName(QString::fromUtf8("line_PlotComp_StatScatter"));
        line_PlotComp_StatScatter->setFrameShape(QFrame::VLine);
        line_PlotComp_StatScatter->setFrameShadow(QFrame::Sunken);

        gridLayout_22->addWidget(line_PlotComp_StatScatter, 0, 1, 2, 1);

        label_PlotComp_StatScatter_X = new QLabel(page_PlotComp_StatScatter);
        label_PlotComp_StatScatter_X->setObjectName(QString::fromUtf8("label_PlotComp_StatScatter_X"));
        sizePolicy3.setHeightForWidth(label_PlotComp_StatScatter_X->sizePolicy().hasHeightForWidth());
        label_PlotComp_StatScatter_X->setSizePolicy(sizePolicy3);

        gridLayout_22->addWidget(label_PlotComp_StatScatter_X, 0, 2, 1, 1);

        comboBox_PlotComp_StatScatter_Image_X = new QComboBox(page_PlotComp_StatScatter);
        comboBox_PlotComp_StatScatter_Image_X->setObjectName(QString::fromUtf8("comboBox_PlotComp_StatScatter_Image_X"));

        gridLayout_22->addWidget(comboBox_PlotComp_StatScatter_Image_X, 0, 5, 1, 1);

        label_PlotComp_StatScatter_Y = new QLabel(page_PlotComp_StatScatter);
        label_PlotComp_StatScatter_Y->setObjectName(QString::fromUtf8("label_PlotComp_StatScatter_Y"));
        sizePolicy3.setHeightForWidth(label_PlotComp_StatScatter_Y->sizePolicy().hasHeightForWidth());
        label_PlotComp_StatScatter_Y->setSizePolicy(sizePolicy3);

        gridLayout_22->addWidget(label_PlotComp_StatScatter_Y, 1, 2, 1, 1);

        comboBox_PlotComp_StatScatter_Image_Y = new QComboBox(page_PlotComp_StatScatter);
        comboBox_PlotComp_StatScatter_Image_Y->setObjectName(QString::fromUtf8("comboBox_PlotComp_StatScatter_Image_Y"));

        gridLayout_22->addWidget(comboBox_PlotComp_StatScatter_Image_Y, 1, 5, 1, 1);

        label_PlotComp_StatScatter_X_Description = new QLabel(page_PlotComp_StatScatter);
        label_PlotComp_StatScatter_X_Description->setObjectName(QString::fromUtf8("label_PlotComp_StatScatter_X_Description"));
        sizePolicy3.setHeightForWidth(label_PlotComp_StatScatter_X_Description->sizePolicy().hasHeightForWidth());
        label_PlotComp_StatScatter_X_Description->setSizePolicy(sizePolicy3);

        gridLayout_22->addWidget(label_PlotComp_StatScatter_X_Description, 0, 4, 1, 1);

        label_PlotComp_StatScatter_Y_Description = new QLabel(page_PlotComp_StatScatter);
        label_PlotComp_StatScatter_Y_Description->setObjectName(QString::fromUtf8("label_PlotComp_StatScatter_Y_Description"));
        sizePolicy3.setHeightForWidth(label_PlotComp_StatScatter_Y_Description->sizePolicy().hasHeightForWidth());
        label_PlotComp_StatScatter_Y_Description->setSizePolicy(sizePolicy3);

        gridLayout_22->addWidget(label_PlotComp_StatScatter_Y_Description, 1, 4, 1, 1);

        comboBox_PlotComp_StatScatter_Stat_Y = new QComboBox(page_PlotComp_StatScatter);
        comboBox_PlotComp_StatScatter_Stat_Y->setObjectName(QString::fromUtf8("comboBox_PlotComp_StatScatter_Stat_Y"));

        gridLayout_22->addWidget(comboBox_PlotComp_StatScatter_Stat_Y, 1, 3, 1, 1);

        comboBox_PlotComp_StatScatter_Stat_X = new QComboBox(page_PlotComp_StatScatter);
        comboBox_PlotComp_StatScatter_Stat_X->setObjectName(QString::fromUtf8("comboBox_PlotComp_StatScatter_Stat_X"));

        gridLayout_22->addWidget(comboBox_PlotComp_StatScatter_Stat_X, 0, 3, 1, 1);

        stackedWidget_PlotComp_Type->addWidget(page_PlotComp_StatScatter);
        page_PlotComp_StatFeatScatter = new QWidget();
        page_PlotComp_StatFeatScatter->setObjectName(QString::fromUtf8("page_PlotComp_StatFeatScatter"));
        gridLayout_23 = new QGridLayout(page_PlotComp_StatFeatScatter);
        gridLayout_23->setSpacing(3);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        gridLayout_23->setContentsMargins(0, 0, 0, 0);
        comboBox_PlotComp_StatFeatScatter_Mode = new QComboBox(page_PlotComp_StatFeatScatter);
        comboBox_PlotComp_StatFeatScatter_Mode->setObjectName(QString::fromUtf8("comboBox_PlotComp_StatFeatScatter_Mode"));
        comboBox_PlotComp_StatFeatScatter_Mode->setMinimumSize(QSize(225, 0));
        comboBox_PlotComp_StatFeatScatter_Mode->setMaximumSize(QSize(225, 16777215));

        gridLayout_23->addWidget(comboBox_PlotComp_StatFeatScatter_Mode, 0, 0, 1, 1);

        line_PlotComp_StatFeatScatter = new QFrame(page_PlotComp_StatFeatScatter);
        line_PlotComp_StatFeatScatter->setObjectName(QString::fromUtf8("line_PlotComp_StatFeatScatter"));
        line_PlotComp_StatFeatScatter->setFrameShape(QFrame::VLine);
        line_PlotComp_StatFeatScatter->setFrameShadow(QFrame::Sunken);

        gridLayout_23->addWidget(line_PlotComp_StatFeatScatter, 0, 1, 2, 1);

        label_PlotComp_StatFeatScatter_X = new QLabel(page_PlotComp_StatFeatScatter);
        label_PlotComp_StatFeatScatter_X->setObjectName(QString::fromUtf8("label_PlotComp_StatFeatScatter_X"));
        sizePolicy3.setHeightForWidth(label_PlotComp_StatFeatScatter_X->sizePolicy().hasHeightForWidth());
        label_PlotComp_StatFeatScatter_X->setSizePolicy(sizePolicy3);

        gridLayout_23->addWidget(label_PlotComp_StatFeatScatter_X, 0, 2, 1, 1);

        label_PlotComp_StatFeatScatter_Y = new QLabel(page_PlotComp_StatFeatScatter);
        label_PlotComp_StatFeatScatter_Y->setObjectName(QString::fromUtf8("label_PlotComp_StatFeatScatter_Y"));
        sizePolicy3.setHeightForWidth(label_PlotComp_StatFeatScatter_Y->sizePolicy().hasHeightForWidth());
        label_PlotComp_StatFeatScatter_Y->setSizePolicy(sizePolicy3);

        gridLayout_23->addWidget(label_PlotComp_StatFeatScatter_Y, 1, 2, 1, 1);

        comboBox_PlotComp_StatFeatScatter_Stat_Y = new QComboBox(page_PlotComp_StatFeatScatter);
        comboBox_PlotComp_StatFeatScatter_Stat_Y->setObjectName(QString::fromUtf8("comboBox_PlotComp_StatFeatScatter_Stat_Y"));

        gridLayout_23->addWidget(comboBox_PlotComp_StatFeatScatter_Stat_Y, 1, 3, 1, 1);

        comboBox_PlotComp_StatFeatScatter_Image_Y = new QComboBox(page_PlotComp_StatFeatScatter);
        comboBox_PlotComp_StatFeatScatter_Image_Y->setObjectName(QString::fromUtf8("comboBox_PlotComp_StatFeatScatter_Image_Y"));

        gridLayout_23->addWidget(comboBox_PlotComp_StatFeatScatter_Image_Y, 1, 5, 1, 1);

        comboBox_PlotComp_StatFeatScatter_Feature_X = new QComboBox(page_PlotComp_StatFeatScatter);
        comboBox_PlotComp_StatFeatScatter_Feature_X->setObjectName(QString::fromUtf8("comboBox_PlotComp_StatFeatScatter_Feature_X"));

        gridLayout_23->addWidget(comboBox_PlotComp_StatFeatScatter_Feature_X, 0, 3, 1, 3);

        label_PlotComp_StatFeatScatter_X_Description = new QLabel(page_PlotComp_StatFeatScatter);
        label_PlotComp_StatFeatScatter_X_Description->setObjectName(QString::fromUtf8("label_PlotComp_StatFeatScatter_X_Description"));
        sizePolicy3.setHeightForWidth(label_PlotComp_StatFeatScatter_X_Description->sizePolicy().hasHeightForWidth());
        label_PlotComp_StatFeatScatter_X_Description->setSizePolicy(sizePolicy3);

        gridLayout_23->addWidget(label_PlotComp_StatFeatScatter_X_Description, 1, 4, 1, 1);

        stackedWidget_PlotComp_Type->addWidget(page_PlotComp_StatFeatScatter);

        gridLayout_11->addWidget(stackedWidget_PlotComp_Type, 2, 0, 1, 1);

        tabWidget_Plots->addTab(tab_PlotComp, QString());
        tab_PlotImg = new QWidget();
        tab_PlotImg->setObjectName(QString::fromUtf8("tab_PlotImg"));
        gridLayout_13 = new QGridLayout(tab_PlotImg);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(9, 9, 9, 9);
        stackedWidget_PlotImg_Type = new QStackedWidget(tab_PlotImg);
        stackedWidget_PlotImg_Type->setObjectName(QString::fromUtf8("stackedWidget_PlotImg_Type"));
        stackedWidget_PlotImg_Type->setMaximumSize(QSize(16777215, 50));
        page_PlotImg_Feat = new QWidget();
        page_PlotImg_Feat->setObjectName(QString::fromUtf8("page_PlotImg_Feat"));
        gridLayout_24 = new QGridLayout(page_PlotImg_Feat);
        gridLayout_24->setSpacing(3);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        gridLayout_24->setContentsMargins(0, 0, 0, 0);
        line_PlotImg_Feat = new QFrame(page_PlotImg_Feat);
        line_PlotImg_Feat->setObjectName(QString::fromUtf8("line_PlotImg_Feat"));
        line_PlotImg_Feat->setFrameShape(QFrame::VLine);
        line_PlotImg_Feat->setFrameShadow(QFrame::Sunken);

        gridLayout_24->addWidget(line_PlotImg_Feat, 0, 1, 2, 1);

        horizontalSpacer_PlotImg_Feat = new QSpacerItem(225, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_24->addItem(horizontalSpacer_PlotImg_Feat, 0, 0, 2, 1);

        label_PlotImg_Feat_Y = new QLabel(page_PlotImg_Feat);
        label_PlotImg_Feat_Y->setObjectName(QString::fromUtf8("label_PlotImg_Feat_Y"));
        sizePolicy3.setHeightForWidth(label_PlotImg_Feat_Y->sizePolicy().hasHeightForWidth());
        label_PlotImg_Feat_Y->setSizePolicy(sizePolicy3);

        gridLayout_24->addWidget(label_PlotImg_Feat_Y, 1, 2, 1, 1);

        label_PlotImg_Feat_X = new QLabel(page_PlotImg_Feat);
        label_PlotImg_Feat_X->setObjectName(QString::fromUtf8("label_PlotImg_Feat_X"));
        sizePolicy3.setHeightForWidth(label_PlotImg_Feat_X->sizePolicy().hasHeightForWidth());
        label_PlotImg_Feat_X->setSizePolicy(sizePolicy3);

        gridLayout_24->addWidget(label_PlotImg_Feat_X, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_24->addItem(horizontalSpacer, 0, 3, 2, 1);

        stackedWidget_PlotImg_Type->addWidget(page_PlotImg_Feat);
        page_PlotImg_Stat = new QWidget();
        page_PlotImg_Stat->setObjectName(QString::fromUtf8("page_PlotImg_Stat"));
        gridLayout_26 = new QGridLayout(page_PlotImg_Stat);
        gridLayout_26->setSpacing(3);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        gridLayout_26->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_PlotImg_Stat = new QSpacerItem(225, 40, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_26->addItem(horizontalSpacer_PlotImg_Stat, 0, 0, 2, 1);

        line_PlotImg_Stat = new QFrame(page_PlotImg_Stat);
        line_PlotImg_Stat->setObjectName(QString::fromUtf8("line_PlotImg_Stat"));
        line_PlotImg_Stat->setFrameShape(QFrame::VLine);
        line_PlotImg_Stat->setFrameShadow(QFrame::Sunken);

        gridLayout_26->addWidget(line_PlotImg_Stat, 0, 1, 2, 1);

        label_PlotImg_Stat_X = new QLabel(page_PlotImg_Stat);
        label_PlotImg_Stat_X->setObjectName(QString::fromUtf8("label_PlotImg_Stat_X"));
        sizePolicy3.setHeightForWidth(label_PlotImg_Stat_X->sizePolicy().hasHeightForWidth());
        label_PlotImg_Stat_X->setSizePolicy(sizePolicy3);

        gridLayout_26->addWidget(label_PlotImg_Stat_X, 0, 2, 1, 1);

        label_PlotImg_Stat_Y = new QLabel(page_PlotImg_Stat);
        label_PlotImg_Stat_Y->setObjectName(QString::fromUtf8("label_PlotImg_Stat_Y"));
        sizePolicy3.setHeightForWidth(label_PlotImg_Stat_Y->sizePolicy().hasHeightForWidth());
        label_PlotImg_Stat_Y->setSizePolicy(sizePolicy3);

        gridLayout_26->addWidget(label_PlotImg_Stat_Y, 1, 2, 1, 1);

        comboBox_PlotImg_Stat_StatImg = new QComboBox(page_PlotImg_Stat);
        comboBox_PlotImg_Stat_StatImg->setObjectName(QString::fromUtf8("comboBox_PlotImg_Stat_StatImg"));

        gridLayout_26->addWidget(comboBox_PlotImg_Stat_StatImg, 1, 3, 1, 1);

        label_PlotImg_Stat_Y_Description_1 = new QLabel(page_PlotImg_Stat);
        label_PlotImg_Stat_Y_Description_1->setObjectName(QString::fromUtf8("label_PlotImg_Stat_Y_Description_1"));
        sizePolicy3.setHeightForWidth(label_PlotImg_Stat_Y_Description_1->sizePolicy().hasHeightForWidth());
        label_PlotImg_Stat_Y_Description_1->setSizePolicy(sizePolicy3);

        gridLayout_26->addWidget(label_PlotImg_Stat_Y_Description_1, 1, 4, 1, 1);

        comboBox_PlotImg_Stat_StatComp = new QComboBox(page_PlotImg_Stat);
        comboBox_PlotImg_Stat_StatComp->setObjectName(QString::fromUtf8("comboBox_PlotImg_Stat_StatComp"));

        gridLayout_26->addWidget(comboBox_PlotImg_Stat_StatComp, 1, 5, 1, 1);

        label_PlotImg_Stat_X_Description = new QLabel(page_PlotImg_Stat);
        label_PlotImg_Stat_X_Description->setObjectName(QString::fromUtf8("label_PlotImg_Stat_X_Description"));

        gridLayout_26->addWidget(label_PlotImg_Stat_X_Description, 0, 3, 1, 3);

        stackedWidget_PlotImg_Type->addWidget(page_PlotImg_Stat);
        page_PlotImg_StatHist = new QWidget();
        page_PlotImg_StatHist->setObjectName(QString::fromUtf8("page_PlotImg_StatHist"));
        gridLayout_27 = new QGridLayout(page_PlotImg_StatHist);
        gridLayout_27->setSpacing(3);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        gridLayout_27->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_PlotImg_StatHist = new QSpacerItem(225, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_27->addItem(horizontalSpacer_PlotImg_StatHist, 0, 0, 1, 4);

        line_PlotImg_StatHist = new QFrame(page_PlotImg_StatHist);
        line_PlotImg_StatHist->setObjectName(QString::fromUtf8("line_PlotImg_StatHist"));
        line_PlotImg_StatHist->setFrameShape(QFrame::VLine);
        line_PlotImg_StatHist->setFrameShadow(QFrame::Sunken);

        gridLayout_27->addWidget(line_PlotImg_StatHist, 0, 4, 2, 1);

        label_PlotImg_StatHist_X = new QLabel(page_PlotImg_StatHist);
        label_PlotImg_StatHist_X->setObjectName(QString::fromUtf8("label_PlotImg_StatHist_X"));
        sizePolicy3.setHeightForWidth(label_PlotImg_StatHist_X->sizePolicy().hasHeightForWidth());
        label_PlotImg_StatHist_X->setSizePolicy(sizePolicy3);

        gridLayout_27->addWidget(label_PlotImg_StatHist_X, 0, 5, 1, 1);

        comboBox_PlotImg_StatHist_StatImg = new QComboBox(page_PlotImg_StatHist);
        comboBox_PlotImg_StatHist_StatImg->setObjectName(QString::fromUtf8("comboBox_PlotImg_StatHist_StatImg"));

        gridLayout_27->addWidget(comboBox_PlotImg_StatHist_StatImg, 0, 6, 1, 1);

        label_PlotImg_StatHist_X_Description_1 = new QLabel(page_PlotImg_StatHist);
        label_PlotImg_StatHist_X_Description_1->setObjectName(QString::fromUtf8("label_PlotImg_StatHist_X_Description_1"));
        sizePolicy3.setHeightForWidth(label_PlotImg_StatHist_X_Description_1->sizePolicy().hasHeightForWidth());
        label_PlotImg_StatHist_X_Description_1->setSizePolicy(sizePolicy3);

        gridLayout_27->addWidget(label_PlotImg_StatHist_X_Description_1, 0, 7, 1, 1);

        comboBox_PlotImg_StatHist_StatComp = new QComboBox(page_PlotImg_StatHist);
        comboBox_PlotImg_StatHist_StatComp->setObjectName(QString::fromUtf8("comboBox_PlotImg_StatHist_StatComp"));

        gridLayout_27->addWidget(comboBox_PlotImg_StatHist_StatComp, 0, 8, 1, 1);

        label_PlotImg_StatHist_Classes = new QLabel(page_PlotImg_StatHist);
        label_PlotImg_StatHist_Classes->setObjectName(QString::fromUtf8("label_PlotImg_StatHist_Classes"));
        sizePolicy3.setHeightForWidth(label_PlotImg_StatHist_Classes->sizePolicy().hasHeightForWidth());
        label_PlotImg_StatHist_Classes->setSizePolicy(sizePolicy3);

        gridLayout_27->addWidget(label_PlotImg_StatHist_Classes, 1, 0, 1, 1);

        spinBox_PlotImg_StatHist_Classes = new QSpinBox(page_PlotImg_StatHist);
        spinBox_PlotImg_StatHist_Classes->setObjectName(QString::fromUtf8("spinBox_PlotImg_StatHist_Classes"));
        sizePolicy5.setHeightForWidth(spinBox_PlotImg_StatHist_Classes->sizePolicy().hasHeightForWidth());
        spinBox_PlotImg_StatHist_Classes->setSizePolicy(sizePolicy5);
        spinBox_PlotImg_StatHist_Classes->setMinimumSize(QSize(98, 0));
        spinBox_PlotImg_StatHist_Classes->setMaximumSize(QSize(98, 16777215));
        spinBox_PlotImg_StatHist_Classes->setMinimum(1);
        spinBox_PlotImg_StatHist_Classes->setMaximum(10000);
        spinBox_PlotImg_StatHist_Classes->setSingleStep(10);
        spinBox_PlotImg_StatHist_Classes->setValue(1000);

        gridLayout_27->addWidget(spinBox_PlotImg_StatHist_Classes, 1, 1, 1, 1);

        checkBox_PlotImg_StatHist_Uni = new QCheckBox(page_PlotImg_StatHist);
        checkBox_PlotImg_StatHist_Uni->setObjectName(QString::fromUtf8("checkBox_PlotImg_StatHist_Uni"));
        sizePolicy6.setHeightForWidth(checkBox_PlotImg_StatHist_Uni->sizePolicy().hasHeightForWidth());
        checkBox_PlotImg_StatHist_Uni->setSizePolicy(sizePolicy6);
        checkBox_PlotImg_StatHist_Uni->setChecked(true);

        gridLayout_27->addWidget(checkBox_PlotImg_StatHist_Uni, 1, 2, 1, 1);

        checkBox_PlotImg_StatHist_Acc = new QCheckBox(page_PlotImg_StatHist);
        checkBox_PlotImg_StatHist_Acc->setObjectName(QString::fromUtf8("checkBox_PlotImg_StatHist_Acc"));
        sizePolicy6.setHeightForWidth(checkBox_PlotImg_StatHist_Acc->sizePolicy().hasHeightForWidth());
        checkBox_PlotImg_StatHist_Acc->setSizePolicy(sizePolicy6);
        checkBox_PlotImg_StatHist_Acc->setChecked(true);

        gridLayout_27->addWidget(checkBox_PlotImg_StatHist_Acc, 1, 3, 1, 1);

        label_PlotImg_StatHist_Y = new QLabel(page_PlotImg_StatHist);
        label_PlotImg_StatHist_Y->setObjectName(QString::fromUtf8("label_PlotImg_StatHist_Y"));
        sizePolicy3.setHeightForWidth(label_PlotImg_StatHist_Y->sizePolicy().hasHeightForWidth());
        label_PlotImg_StatHist_Y->setSizePolicy(sizePolicy3);

        gridLayout_27->addWidget(label_PlotImg_StatHist_Y, 1, 5, 1, 1);

        label_PlotImg_StatHist_Y_Description = new QLabel(page_PlotImg_StatHist);
        label_PlotImg_StatHist_Y_Description->setObjectName(QString::fromUtf8("label_PlotImg_StatHist_Y_Description"));

        gridLayout_27->addWidget(label_PlotImg_StatHist_Y_Description, 1, 6, 1, 3);

        stackedWidget_PlotImg_Type->addWidget(page_PlotImg_StatHist);
        page_PlotImg_StatScatter = new QWidget();
        page_PlotImg_StatScatter->setObjectName(QString::fromUtf8("page_PlotImg_StatScatter"));
        gridLayout_28 = new QGridLayout(page_PlotImg_StatScatter);
        gridLayout_28->setSpacing(3);
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        gridLayout_28->setContentsMargins(0, 0, 0, 0);
        label_PlotImg_StatScatter_X_Description_1 = new QLabel(page_PlotImg_StatScatter);
        label_PlotImg_StatScatter_X_Description_1->setObjectName(QString::fromUtf8("label_PlotImg_StatScatter_X_Description_1"));
        sizePolicy3.setHeightForWidth(label_PlotImg_StatScatter_X_Description_1->sizePolicy().hasHeightForWidth());
        label_PlotImg_StatScatter_X_Description_1->setSizePolicy(sizePolicy3);

        gridLayout_28->addWidget(label_PlotImg_StatScatter_X_Description_1, 0, 4, 1, 1);

        label_PlotImg_StatScatter_Y_Description_1 = new QLabel(page_PlotImg_StatScatter);
        label_PlotImg_StatScatter_Y_Description_1->setObjectName(QString::fromUtf8("label_PlotImg_StatScatter_Y_Description_1"));
        sizePolicy3.setHeightForWidth(label_PlotImg_StatScatter_Y_Description_1->sizePolicy().hasHeightForWidth());
        label_PlotImg_StatScatter_Y_Description_1->setSizePolicy(sizePolicy3);

        gridLayout_28->addWidget(label_PlotImg_StatScatter_Y_Description_1, 1, 4, 1, 1);

        comboBox_PlotImg_StatScatter_StatImg_X = new QComboBox(page_PlotImg_StatScatter);
        comboBox_PlotImg_StatScatter_StatImg_X->setObjectName(QString::fromUtf8("comboBox_PlotImg_StatScatter_StatImg_X"));

        gridLayout_28->addWidget(comboBox_PlotImg_StatScatter_StatImg_X, 0, 3, 1, 1);

        comboBox_PlotImg_StatScatter_StatImg_Y = new QComboBox(page_PlotImg_StatScatter);
        comboBox_PlotImg_StatScatter_StatImg_Y->setObjectName(QString::fromUtf8("comboBox_PlotImg_StatScatter_StatImg_Y"));

        gridLayout_28->addWidget(comboBox_PlotImg_StatScatter_StatImg_Y, 1, 3, 1, 1);

        comboBox_PlotImg_StatScatter_StatComp_Y = new QComboBox(page_PlotImg_StatScatter);
        comboBox_PlotImg_StatScatter_StatComp_Y->setObjectName(QString::fromUtf8("comboBox_PlotImg_StatScatter_StatComp_Y"));

        gridLayout_28->addWidget(comboBox_PlotImg_StatScatter_StatComp_Y, 1, 5, 1, 1);

        label_PlotImg_StatScatter_Y = new QLabel(page_PlotImg_StatScatter);
        label_PlotImg_StatScatter_Y->setObjectName(QString::fromUtf8("label_PlotImg_StatScatter_Y"));
        sizePolicy3.setHeightForWidth(label_PlotImg_StatScatter_Y->sizePolicy().hasHeightForWidth());
        label_PlotImg_StatScatter_Y->setSizePolicy(sizePolicy3);

        gridLayout_28->addWidget(label_PlotImg_StatScatter_Y, 1, 2, 1, 1);

        line_PlotImg_StatScatter = new QFrame(page_PlotImg_StatScatter);
        line_PlotImg_StatScatter->setObjectName(QString::fromUtf8("line_PlotImg_StatScatter"));
        line_PlotImg_StatScatter->setFrameShape(QFrame::VLine);
        line_PlotImg_StatScatter->setFrameShadow(QFrame::Sunken);

        gridLayout_28->addWidget(line_PlotImg_StatScatter, 0, 1, 2, 1);

        horizontalSpacer_PlotImg_StatScatter = new QSpacerItem(225, 40, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_28->addItem(horizontalSpacer_PlotImg_StatScatter, 0, 0, 2, 1);

        label_PlotImg_StatScatter_X = new QLabel(page_PlotImg_StatScatter);
        label_PlotImg_StatScatter_X->setObjectName(QString::fromUtf8("label_PlotImg_StatScatter_X"));
        sizePolicy3.setHeightForWidth(label_PlotImg_StatScatter_X->sizePolicy().hasHeightForWidth());
        label_PlotImg_StatScatter_X->setSizePolicy(sizePolicy3);

        gridLayout_28->addWidget(label_PlotImg_StatScatter_X, 0, 2, 1, 1);

        comboBox_PlotImg_StatScatter_StatComp_X = new QComboBox(page_PlotImg_StatScatter);
        comboBox_PlotImg_StatScatter_StatComp_X->setObjectName(QString::fromUtf8("comboBox_PlotImg_StatScatter_StatComp_X"));

        gridLayout_28->addWidget(comboBox_PlotImg_StatScatter_StatComp_X, 0, 5, 1, 1);

        stackedWidget_PlotImg_Type->addWidget(page_PlotImg_StatScatter);
        page_PlotImg_StatFeatScatter = new QWidget();
        page_PlotImg_StatFeatScatter->setObjectName(QString::fromUtf8("page_PlotImg_StatFeatScatter"));
        gridLayout_29 = new QGridLayout(page_PlotImg_StatFeatScatter);
        gridLayout_29->setSpacing(3);
        gridLayout_29->setObjectName(QString::fromUtf8("gridLayout_29"));
        gridLayout_29->setContentsMargins(0, 0, 0, 0);
        line_PlotImg_StatFeatScatter = new QFrame(page_PlotImg_StatFeatScatter);
        line_PlotImg_StatFeatScatter->setObjectName(QString::fromUtf8("line_PlotImg_StatFeatScatter"));
        line_PlotImg_StatFeatScatter->setFrameShape(QFrame::VLine);
        line_PlotImg_StatFeatScatter->setFrameShadow(QFrame::Sunken);

        gridLayout_29->addWidget(line_PlotImg_StatFeatScatter, 0, 1, 2, 1);

        label_PlotImg_StatFeatScatter_X = new QLabel(page_PlotImg_StatFeatScatter);
        label_PlotImg_StatFeatScatter_X->setObjectName(QString::fromUtf8("label_PlotImg_StatFeatScatter_X"));
        sizePolicy3.setHeightForWidth(label_PlotImg_StatFeatScatter_X->sizePolicy().hasHeightForWidth());
        label_PlotImg_StatFeatScatter_X->setSizePolicy(sizePolicy3);

        gridLayout_29->addWidget(label_PlotImg_StatFeatScatter_X, 0, 2, 1, 1);

        comboBox_PlotImg_StatFeatScatter_StatImg_X = new QComboBox(page_PlotImg_StatFeatScatter);
        comboBox_PlotImg_StatFeatScatter_StatImg_X->setObjectName(QString::fromUtf8("comboBox_PlotImg_StatFeatScatter_StatImg_X"));

        gridLayout_29->addWidget(comboBox_PlotImg_StatFeatScatter_StatImg_X, 0, 3, 1, 1);

        label_PlotImg_StatFeatScatter_X_Description_1 = new QLabel(page_PlotImg_StatFeatScatter);
        label_PlotImg_StatFeatScatter_X_Description_1->setObjectName(QString::fromUtf8("label_PlotImg_StatFeatScatter_X_Description_1"));
        sizePolicy3.setHeightForWidth(label_PlotImg_StatFeatScatter_X_Description_1->sizePolicy().hasHeightForWidth());
        label_PlotImg_StatFeatScatter_X_Description_1->setSizePolicy(sizePolicy3);

        gridLayout_29->addWidget(label_PlotImg_StatFeatScatter_X_Description_1, 0, 4, 1, 1);

        comboBox_PlotImg_StatFeatScatter_FeatComp_X = new QComboBox(page_PlotImg_StatFeatScatter);
        comboBox_PlotImg_StatFeatScatter_FeatComp_X->setObjectName(QString::fromUtf8("comboBox_PlotImg_StatFeatScatter_FeatComp_X"));

        gridLayout_29->addWidget(comboBox_PlotImg_StatFeatScatter_FeatComp_X, 0, 5, 1, 1);

        label_PlotImg_StatFeatScatter_Y = new QLabel(page_PlotImg_StatFeatScatter);
        label_PlotImg_StatFeatScatter_Y->setObjectName(QString::fromUtf8("label_PlotImg_StatFeatScatter_Y"));
        sizePolicy3.setHeightForWidth(label_PlotImg_StatFeatScatter_Y->sizePolicy().hasHeightForWidth());
        label_PlotImg_StatFeatScatter_Y->setSizePolicy(sizePolicy3);

        gridLayout_29->addWidget(label_PlotImg_StatFeatScatter_Y, 1, 2, 1, 1);

        comboBox_PlotImg_StatFeatScatter_StatImg_Y = new QComboBox(page_PlotImg_StatFeatScatter);
        comboBox_PlotImg_StatFeatScatter_StatImg_Y->setObjectName(QString::fromUtf8("comboBox_PlotImg_StatFeatScatter_StatImg_Y"));

        gridLayout_29->addWidget(comboBox_PlotImg_StatFeatScatter_StatImg_Y, 1, 3, 1, 1);

        label_PlotImg_StatFeatScatter_Y_Description_1 = new QLabel(page_PlotImg_StatFeatScatter);
        label_PlotImg_StatFeatScatter_Y_Description_1->setObjectName(QString::fromUtf8("label_PlotImg_StatFeatScatter_Y_Description_1"));
        sizePolicy3.setHeightForWidth(label_PlotImg_StatFeatScatter_Y_Description_1->sizePolicy().hasHeightForWidth());
        label_PlotImg_StatFeatScatter_Y_Description_1->setSizePolicy(sizePolicy3);

        gridLayout_29->addWidget(label_PlotImg_StatFeatScatter_Y_Description_1, 1, 4, 1, 1);

        comboBox_PlotImg_StatFeatScatter_StatComp_Y = new QComboBox(page_PlotImg_StatFeatScatter);
        comboBox_PlotImg_StatFeatScatter_StatComp_Y->setObjectName(QString::fromUtf8("comboBox_PlotImg_StatFeatScatter_StatComp_Y"));

        gridLayout_29->addWidget(comboBox_PlotImg_StatFeatScatter_StatComp_Y, 1, 5, 1, 1);

        horizontalSpacer_PlotImg_StatFeatScatter = new QSpacerItem(225, 40, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_29->addItem(horizontalSpacer_PlotImg_StatFeatScatter, 0, 0, 2, 1);

        stackedWidget_PlotImg_Type->addWidget(page_PlotImg_StatFeatScatter);
        page_PlotImg_FeatHist = new QWidget();
        page_PlotImg_FeatHist->setObjectName(QString::fromUtf8("page_PlotImg_FeatHist"));
        gridLayout_25 = new QGridLayout(page_PlotImg_FeatHist);
        gridLayout_25->setSpacing(3);
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        gridLayout_25->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_PlotImg_FeatHist = new QSpacerItem(225, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_25->addItem(horizontalSpacer_PlotImg_FeatHist, 0, 0, 1, 4);

        spinBox_PlotImg_FeatHist_Classes = new QSpinBox(page_PlotImg_FeatHist);
        spinBox_PlotImg_FeatHist_Classes->setObjectName(QString::fromUtf8("spinBox_PlotImg_FeatHist_Classes"));
        sizePolicy5.setHeightForWidth(spinBox_PlotImg_FeatHist_Classes->sizePolicy().hasHeightForWidth());
        spinBox_PlotImg_FeatHist_Classes->setSizePolicy(sizePolicy5);
        spinBox_PlotImg_FeatHist_Classes->setMinimumSize(QSize(98, 0));
        spinBox_PlotImg_FeatHist_Classes->setMaximumSize(QSize(98, 16777215));
        spinBox_PlotImg_FeatHist_Classes->setMinimum(1);
        spinBox_PlotImg_FeatHist_Classes->setMaximum(10000);
        spinBox_PlotImg_FeatHist_Classes->setSingleStep(10);
        spinBox_PlotImg_FeatHist_Classes->setValue(1000);

        gridLayout_25->addWidget(spinBox_PlotImg_FeatHist_Classes, 1, 1, 1, 1);

        label_PlotImg_FeatHist_Y = new QLabel(page_PlotImg_FeatHist);
        label_PlotImg_FeatHist_Y->setObjectName(QString::fromUtf8("label_PlotImg_FeatHist_Y"));
        sizePolicy3.setHeightForWidth(label_PlotImg_FeatHist_Y->sizePolicy().hasHeightForWidth());
        label_PlotImg_FeatHist_Y->setSizePolicy(sizePolicy3);

        gridLayout_25->addWidget(label_PlotImg_FeatHist_Y, 1, 5, 1, 1);

        checkBox_PlotImg_FeatHist_Uni = new QCheckBox(page_PlotImg_FeatHist);
        checkBox_PlotImg_FeatHist_Uni->setObjectName(QString::fromUtf8("checkBox_PlotImg_FeatHist_Uni"));
        sizePolicy6.setHeightForWidth(checkBox_PlotImg_FeatHist_Uni->sizePolicy().hasHeightForWidth());
        checkBox_PlotImg_FeatHist_Uni->setSizePolicy(sizePolicy6);
        checkBox_PlotImg_FeatHist_Uni->setChecked(true);

        gridLayout_25->addWidget(checkBox_PlotImg_FeatHist_Uni, 1, 2, 1, 1);

        label_PlotImg_FeatHist_Classes = new QLabel(page_PlotImg_FeatHist);
        label_PlotImg_FeatHist_Classes->setObjectName(QString::fromUtf8("label_PlotImg_FeatHist_Classes"));
        sizePolicy3.setHeightForWidth(label_PlotImg_FeatHist_Classes->sizePolicy().hasHeightForWidth());
        label_PlotImg_FeatHist_Classes->setSizePolicy(sizePolicy3);

        gridLayout_25->addWidget(label_PlotImg_FeatHist_Classes, 1, 0, 1, 1);

        label_PlotImg_FeatHist_X = new QLabel(page_PlotImg_FeatHist);
        label_PlotImg_FeatHist_X->setObjectName(QString::fromUtf8("label_PlotImg_FeatHist_X"));
        sizePolicy3.setHeightForWidth(label_PlotImg_FeatHist_X->sizePolicy().hasHeightForWidth());
        label_PlotImg_FeatHist_X->setSizePolicy(sizePolicy3);

        gridLayout_25->addWidget(label_PlotImg_FeatHist_X, 0, 5, 1, 1);

        line_PlotImg_FeatHist = new QFrame(page_PlotImg_FeatHist);
        line_PlotImg_FeatHist->setObjectName(QString::fromUtf8("line_PlotImg_FeatHist"));
        line_PlotImg_FeatHist->setFrameShape(QFrame::VLine);
        line_PlotImg_FeatHist->setFrameShadow(QFrame::Sunken);

        gridLayout_25->addWidget(line_PlotImg_FeatHist, 0, 4, 2, 1);

        comboBox_PlotImg_FeatHist_Feature = new QComboBox(page_PlotImg_FeatHist);
        comboBox_PlotImg_FeatHist_Feature->setObjectName(QString::fromUtf8("comboBox_PlotImg_FeatHist_Feature"));

        gridLayout_25->addWidget(comboBox_PlotImg_FeatHist_Feature, 0, 8, 1, 1);

        checkBox_PlotImg_FeatHist_Acc = new QCheckBox(page_PlotImg_FeatHist);
        checkBox_PlotImg_FeatHist_Acc->setObjectName(QString::fromUtf8("checkBox_PlotImg_FeatHist_Acc"));
        sizePolicy6.setHeightForWidth(checkBox_PlotImg_FeatHist_Acc->sizePolicy().hasHeightForWidth());
        checkBox_PlotImg_FeatHist_Acc->setSizePolicy(sizePolicy6);
        checkBox_PlotImg_FeatHist_Acc->setChecked(true);

        gridLayout_25->addWidget(checkBox_PlotImg_FeatHist_Acc, 1, 3, 1, 1);

        comboBox_PlotImg_FeatHist_Stat = new QComboBox(page_PlotImg_FeatHist);
        comboBox_PlotImg_FeatHist_Stat->setObjectName(QString::fromUtf8("comboBox_PlotImg_FeatHist_Stat"));

        gridLayout_25->addWidget(comboBox_PlotImg_FeatHist_Stat, 0, 6, 1, 1);

        label_PlotImg_FeatHist_X_Description_1 = new QLabel(page_PlotImg_FeatHist);
        label_PlotImg_FeatHist_X_Description_1->setObjectName(QString::fromUtf8("label_PlotImg_FeatHist_X_Description_1"));
        sizePolicy3.setHeightForWidth(label_PlotImg_FeatHist_X_Description_1->sizePolicy().hasHeightForWidth());
        label_PlotImg_FeatHist_X_Description_1->setSizePolicy(sizePolicy3);

        gridLayout_25->addWidget(label_PlotImg_FeatHist_X_Description_1, 0, 7, 1, 1);

        label_PlotImg_FeatHist_Y_Description = new QLabel(page_PlotImg_FeatHist);
        label_PlotImg_FeatHist_Y_Description->setObjectName(QString::fromUtf8("label_PlotImg_FeatHist_Y_Description"));

        gridLayout_25->addWidget(label_PlotImg_FeatHist_Y_Description, 1, 6, 1, 3);

        stackedWidget_PlotImg_Type->addWidget(page_PlotImg_FeatHist);

        gridLayout_13->addWidget(stackedWidget_PlotImg_Type, 2, 0, 1, 1);

        line_PlotImg = new QFrame(tab_PlotImg);
        line_PlotImg->setObjectName(QString::fromUtf8("line_PlotImg"));
        line_PlotImg->setFrameShape(QFrame::HLine);
        line_PlotImg->setFrameShadow(QFrame::Sunken);

        gridLayout_13->addWidget(line_PlotImg, 1, 0, 1, 1);

        comboBox_PlotImg_Type = new QComboBox(tab_PlotImg);
        comboBox_PlotImg_Type->setObjectName(QString::fromUtf8("comboBox_PlotImg_Type"));

        gridLayout_13->addWidget(comboBox_PlotImg_Type, 0, 0, 1, 1);

        tabWidget_Plots->addTab(tab_PlotImg, QString());
        tab_PlotStack = new QWidget();
        tab_PlotStack->setObjectName(QString::fromUtf8("tab_PlotStack"));
        gridLayout_15 = new QGridLayout(tab_PlotStack);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        comboBox_PlotStack_Type = new QComboBox(tab_PlotStack);
        comboBox_PlotStack_Type->setObjectName(QString::fromUtf8("comboBox_PlotStack_Type"));

        gridLayout_15->addWidget(comboBox_PlotStack_Type, 0, 0, 1, 1);

        line_PlotStack = new QFrame(tab_PlotStack);
        line_PlotStack->setObjectName(QString::fromUtf8("line_PlotStack"));
        line_PlotStack->setFrameShape(QFrame::HLine);
        line_PlotStack->setFrameShadow(QFrame::Sunken);

        gridLayout_15->addWidget(line_PlotStack, 1, 0, 1, 1);

        stackedWidget_PlotStack_Type = new QStackedWidget(tab_PlotStack);
        stackedWidget_PlotStack_Type->setObjectName(QString::fromUtf8("stackedWidget_PlotStack_Type"));
        stackedWidget_PlotStack_Type->setMaximumSize(QSize(16777215, 50));
        page_PlotStack_Stat = new QWidget();
        page_PlotStack_Stat->setObjectName(QString::fromUtf8("page_PlotStack_Stat"));
        gridLayout_34 = new QGridLayout(page_PlotStack_Stat);
        gridLayout_34->setSpacing(3);
        gridLayout_34->setObjectName(QString::fromUtf8("gridLayout_34"));
        gridLayout_34->setContentsMargins(0, 0, 0, 0);
        label_PlotStack_Stat_StatImg = new QLabel(page_PlotStack_Stat);
        label_PlotStack_Stat_StatImg->setObjectName(QString::fromUtf8("label_PlotStack_Stat_StatImg"));

        gridLayout_34->addWidget(label_PlotStack_Stat_StatImg, 1, 2, 1, 1);

        comboBox_PlotStack_Stat_StatComp = new QComboBox(page_PlotStack_Stat);
        comboBox_PlotStack_Stat_StatComp->setObjectName(QString::fromUtf8("comboBox_PlotStack_Stat_StatComp"));

        gridLayout_34->addWidget(comboBox_PlotStack_Stat_StatComp, 0, 4, 1, 1);

        label_PlotStack_Stat_StatComp = new QLabel(page_PlotStack_Stat);
        label_PlotStack_Stat_StatComp->setObjectName(QString::fromUtf8("label_PlotStack_Stat_StatComp"));

        gridLayout_34->addWidget(label_PlotStack_Stat_StatComp, 1, 4, 1, 1);

        comboBox_PlotStack_Stat_StatImg = new QComboBox(page_PlotStack_Stat);
        comboBox_PlotStack_Stat_StatImg->setObjectName(QString::fromUtf8("comboBox_PlotStack_Stat_StatImg"));

        gridLayout_34->addWidget(comboBox_PlotStack_Stat_StatImg, 0, 2, 1, 1);

        label_PlotStack_Stat_Description_1 = new QLabel(page_PlotStack_Stat);
        label_PlotStack_Stat_Description_1->setObjectName(QString::fromUtf8("label_PlotStack_Stat_Description_1"));
        sizePolicy3.setHeightForWidth(label_PlotStack_Stat_Description_1->sizePolicy().hasHeightForWidth());
        label_PlotStack_Stat_Description_1->setSizePolicy(sizePolicy3);

        gridLayout_34->addWidget(label_PlotStack_Stat_Description_1, 0, 1, 1, 1);

        label_PlotStack_Stat_Description_2 = new QLabel(page_PlotStack_Stat);
        label_PlotStack_Stat_Description_2->setObjectName(QString::fromUtf8("label_PlotStack_Stat_Description_2"));
        sizePolicy3.setHeightForWidth(label_PlotStack_Stat_Description_2->sizePolicy().hasHeightForWidth());
        label_PlotStack_Stat_Description_2->setSizePolicy(sizePolicy3);

        gridLayout_34->addWidget(label_PlotStack_Stat_Description_2, 0, 3, 1, 1);

        label_PlotStack_Stat_StatStack_2 = new QLabel(page_PlotStack_Stat);
        label_PlotStack_Stat_StatStack_2->setObjectName(QString::fromUtf8("label_PlotStack_Stat_StatStack_2"));

        gridLayout_34->addWidget(label_PlotStack_Stat_StatStack_2, 1, 0, 1, 1);

        label_PlotStack_Stat_StatStack_1 = new QLabel(page_PlotStack_Stat);
        label_PlotStack_Stat_StatStack_1->setObjectName(QString::fromUtf8("label_PlotStack_Stat_StatStack_1"));

        gridLayout_34->addWidget(label_PlotStack_Stat_StatStack_1, 0, 0, 1, 1);

        stackedWidget_PlotStack_Type->addWidget(page_PlotStack_Stat);
        page_PlotStack_1 = new QWidget();
        page_PlotStack_1->setObjectName(QString::fromUtf8("page_PlotStack_1"));
        stackedWidget_PlotStack_Type->addWidget(page_PlotStack_1);

        gridLayout_15->addWidget(stackedWidget_PlotStack_Type, 2, 0, 1, 1);

        tabWidget_Plots->addTab(tab_PlotStack, QString());

        gridLayout_3->addWidget(tabWidget_Plots, 0, 0, 1, 3);

        tabWidget_PlotTable = new QTabWidget(groupBox_Plots);
        tabWidget_PlotTable->setObjectName(QString::fromUtf8("tabWidget_PlotTable"));
        tabWidget_PlotTable->setTabPosition(QTabWidget::South);
        tabWidget_PlotTable->setElideMode(Qt::ElideNone);
        tab_Plot = new QWidget();
        tab_Plot->setObjectName(QString::fromUtf8("tab_Plot"));
        gridLayout_31 = new QGridLayout(tab_Plot);
        gridLayout_31->setSpacing(3);
        gridLayout_31->setObjectName(QString::fromUtf8("gridLayout_31"));
        gridLayout_31->setContentsMargins(0, 0, 0, 0);
        gridLayout_Plot = new QGridLayout();
        gridLayout_Plot->setObjectName(QString::fromUtf8("gridLayout_Plot"));

        gridLayout_31->addLayout(gridLayout_Plot, 0, 0, 1, 8);

        checkBox_Plot_Y_Range = new QCheckBox(tab_Plot);
        checkBox_Plot_Y_Range->setObjectName(QString::fromUtf8("checkBox_Plot_Y_Range"));
        sizePolicy6.setHeightForWidth(checkBox_Plot_Y_Range->sizePolicy().hasHeightForWidth());
        checkBox_Plot_Y_Range->setSizePolicy(sizePolicy6);

        gridLayout_31->addWidget(checkBox_Plot_Y_Range, 1, 3, 1, 1);

        doubleSpinBox_Plot_Y_Max = new QDoubleSpinBox(tab_Plot);
        doubleSpinBox_Plot_Y_Max->setObjectName(QString::fromUtf8("doubleSpinBox_Plot_Y_Max"));
        doubleSpinBox_Plot_Y_Max->setEnabled(false);
        sizePolicy5.setHeightForWidth(doubleSpinBox_Plot_Y_Max->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Plot_Y_Max->setSizePolicy(sizePolicy5);
        doubleSpinBox_Plot_Y_Max->setMaximumSize(QSize(75, 16777215));
        doubleSpinBox_Plot_Y_Max->setDecimals(3);
        doubleSpinBox_Plot_Y_Max->setMinimum(-999999999999999945322333868247445125709646570021247924665841614848.000000000000000);
        doubleSpinBox_Plot_Y_Max->setMaximum(9999999999999999827367757839185598317239782875580932278577147150336.000000000000000);
        doubleSpinBox_Plot_Y_Max->setValue(1.000000000000000);

        gridLayout_31->addWidget(doubleSpinBox_Plot_Y_Max, 1, 5, 1, 1);

        label_Plot_Time = new QLabel(tab_Plot);
        label_Plot_Time->setObjectName(QString::fromUtf8("label_Plot_Time"));
        sizePolicy7.setHeightForWidth(label_Plot_Time->sizePolicy().hasHeightForWidth());
        label_Plot_Time->setSizePolicy(sizePolicy7);
        label_Plot_Time->setMinimumSize(QSize(100, 0));
        label_Plot_Time->setMaximumSize(QSize(100, 20));

        gridLayout_31->addWidget(label_Plot_Time, 1, 7, 1, 1);

        doubleSpinBox_Plot_X_Max = new QDoubleSpinBox(tab_Plot);
        doubleSpinBox_Plot_X_Max->setObjectName(QString::fromUtf8("doubleSpinBox_Plot_X_Max"));
        doubleSpinBox_Plot_X_Max->setEnabled(false);
        sizePolicy5.setHeightForWidth(doubleSpinBox_Plot_X_Max->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Plot_X_Max->setSizePolicy(sizePolicy5);
        doubleSpinBox_Plot_X_Max->setMaximumSize(QSize(75, 16777215));
        doubleSpinBox_Plot_X_Max->setDecimals(3);
        doubleSpinBox_Plot_X_Max->setMinimum(-999999999999999945322333868247445125709646570021247924665841614848.000000000000000);
        doubleSpinBox_Plot_X_Max->setMaximum(9999999999999999827367757839185598317239782875580932278577147150336.000000000000000);
        doubleSpinBox_Plot_X_Max->setValue(1.000000000000000);

        gridLayout_31->addWidget(doubleSpinBox_Plot_X_Max, 1, 2, 1, 1);

        checkBox_Plot_X_Range = new QCheckBox(tab_Plot);
        checkBox_Plot_X_Range->setObjectName(QString::fromUtf8("checkBox_Plot_X_Range"));
        sizePolicy6.setHeightForWidth(checkBox_Plot_X_Range->sizePolicy().hasHeightForWidth());
        checkBox_Plot_X_Range->setSizePolicy(sizePolicy6);

        gridLayout_31->addWidget(checkBox_Plot_X_Range, 1, 0, 1, 1);

        doubleSpinBox_Plot_Y_Min = new QDoubleSpinBox(tab_Plot);
        doubleSpinBox_Plot_Y_Min->setObjectName(QString::fromUtf8("doubleSpinBox_Plot_Y_Min"));
        doubleSpinBox_Plot_Y_Min->setEnabled(false);
        sizePolicy5.setHeightForWidth(doubleSpinBox_Plot_Y_Min->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Plot_Y_Min->setSizePolicy(sizePolicy5);
        doubleSpinBox_Plot_Y_Min->setMaximumSize(QSize(75, 16777215));
        doubleSpinBox_Plot_Y_Min->setDecimals(3);
        doubleSpinBox_Plot_Y_Min->setMinimum(-999999999999999945322333868247445125709646570021247924665841614848.000000000000000);
        doubleSpinBox_Plot_Y_Min->setMaximum(9999999999999999827367757839185598317239782875580932278577147150336.000000000000000);

        gridLayout_31->addWidget(doubleSpinBox_Plot_Y_Min, 1, 4, 1, 1);

        doubleSpinBox_Plot_X_Min = new QDoubleSpinBox(tab_Plot);
        doubleSpinBox_Plot_X_Min->setObjectName(QString::fromUtf8("doubleSpinBox_Plot_X_Min"));
        doubleSpinBox_Plot_X_Min->setEnabled(false);
        sizePolicy5.setHeightForWidth(doubleSpinBox_Plot_X_Min->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Plot_X_Min->setSizePolicy(sizePolicy5);
        doubleSpinBox_Plot_X_Min->setMaximumSize(QSize(75, 16777215));
        doubleSpinBox_Plot_X_Min->setDecimals(3);
        doubleSpinBox_Plot_X_Min->setMinimum(-999999999999999945322333868247445125709646570021247924665841614848.000000000000000);
        doubleSpinBox_Plot_X_Min->setMaximum(9999999999999999827367757839185598317239782875580932278577147150336.000000000000000);

        gridLayout_31->addWidget(doubleSpinBox_Plot_X_Min, 1, 1, 1, 1);

        horizontalSpacer_Plot = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_31->addItem(horizontalSpacer_Plot, 1, 6, 1, 1);

        tabWidget_PlotTable->addTab(tab_Plot, QString());
        tab_Table = new QWidget();
        tab_Table->setObjectName(QString::fromUtf8("tab_Table"));
        gridLayout_33 = new QGridLayout(tab_Table);
        gridLayout_33->setSpacing(3);
        gridLayout_33->setObjectName(QString::fromUtf8("gridLayout_33"));
        gridLayout_33->setContentsMargins(0, 0, 0, -1);
        tableWidget_PlottedData = new QTableWidget(tab_Table);
        tableWidget_PlottedData->setObjectName(QString::fromUtf8("tableWidget_PlottedData"));

        gridLayout_33->addWidget(tableWidget_PlottedData, 0, 0, 1, 1);

        tabWidget_PlotTable->addTab(tab_Table, QString());

        gridLayout_3->addWidget(tabWidget_PlotTable, 1, 0, 2, 3);


        gridLayout->addWidget(groupBox_Plots, 0, 1, 1, 1);

        D_AnalysisWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_AnalysisWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1169, 21));
        menuViewer = new QMenu(menubar);
        menuViewer->setObjectName(QString::fromUtf8("menuViewer"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuData = new QMenu(menubar);
        menuData->setObjectName(QString::fromUtf8("menuData"));
        menuUpdate = new QMenu(menubar);
        menuUpdate->setObjectName(QString::fromUtf8("menuUpdate"));
        menuLayout = new QMenu(menubar);
        menuLayout->setObjectName(QString::fromUtf8("menuLayout"));
        menuRename = new QMenu(menubar);
        menuRename->setObjectName(QString::fromUtf8("menuRename"));
        D_AnalysisWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(D_AnalysisWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_AnalysisWindow->setStatusBar(statusbar);

        menubar->addAction(menuData->menuAction());
        menubar->addAction(menuViewer->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menubar->addAction(menuUpdate->menuAction());
        menubar->addAction(menuLayout->menuAction());
        menubar->addAction(menuRename->menuAction());
        menuViewer->addAction(action_Smooth_Transformation);
        menuViewer->addAction(action_Keep_Aspect_Ratio);
        menuWindow->addAction(action_Show_Minimum);
        menuWindow->addAction(action_Show_Normal);
        menuWindow->addAction(action_Show_Maximum);
        menuWindow->addAction(action_Show_Fullscreen);
        menuData->addAction(action_Save_Image);
        menuData->addAction(action_Save_Plot);
        menuData->addAction(action_Save_Table);
        menuData->addAction(action_Save_Image_Plot_Table);
        menuUpdate->addAction(action_Update_Views);
        menuLayout->addAction(action_Show_Images);
        menuLayout->addAction(action_Show_Plots);
        menuRename->addAction(action_Rename_Image);
        menuRename->addAction(action_Rename_Component);

        retranslateUi(D_AnalysisWindow);
        QObject::connect(action_Show_Fullscreen, SIGNAL(triggered()), D_AnalysisWindow, SLOT(showFullScreen()));
        QObject::connect(action_Show_Images, SIGNAL(toggled(bool)), groupBox_Images, SLOT(setVisible(bool)));
        QObject::connect(action_Show_Minimum, SIGNAL(triggered()), D_AnalysisWindow, SLOT(showMinimized()));
        QObject::connect(action_Show_Maximum, SIGNAL(triggered()), D_AnalysisWindow, SLOT(showMaximized()));
        QObject::connect(action_Show_Normal, SIGNAL(triggered()), D_AnalysisWindow, SLOT(showNormal()));
        QObject::connect(action_Show_Plots, SIGNAL(toggled(bool)), groupBox_Plots, SLOT(setVisible(bool)));
        QObject::connect(comboBox_PlotPixel_Type, SIGNAL(currentIndexChanged(int)), stackedWidget_PlotPixel_Type, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_PlotImg_Type, SIGNAL(currentIndexChanged(int)), stackedWidget_PlotImg_Type, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_PlotStack_Type, SIGNAL(currentIndexChanged(int)), stackedWidget_PlotStack_Type, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_PlotComp_Type, SIGNAL(currentIndexChanged(int)), stackedWidget_PlotComp_Type, SLOT(setCurrentIndex(int)));
        QObject::connect(checkBox_Plot_X_Range, SIGNAL(clicked(bool)), doubleSpinBox_Plot_X_Max, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_Plot_X_Range, SIGNAL(clicked(bool)), doubleSpinBox_Plot_X_Min, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_Plot_Y_Range, SIGNAL(clicked(bool)), doubleSpinBox_Plot_Y_Min, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_Plot_Y_Range, SIGNAL(clicked(bool)), doubleSpinBox_Plot_Y_Max, SLOT(setEnabled(bool)));

        tabWidget_Images->setCurrentIndex(0);
        tabWidget_Plots->setCurrentIndex(0);
        stackedWidget_PlotPixel_Type->setCurrentIndex(0);
        stackedWidget_PlotComp_Type->setCurrentIndex(0);
        stackedWidget_PlotImg_Type->setCurrentIndex(0);
        stackedWidget_PlotStack_Type->setCurrentIndex(0);
        tabWidget_PlotTable->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(D_AnalysisWindow);
    } // setupUi

    void retranslateUi(QMainWindow *D_AnalysisWindow)
    {
        D_AnalysisWindow->setWindowTitle(QCoreApplication::translate("D_AnalysisWindow", "MainWindow", nullptr));
        action_Smooth_Transformation->setText(QCoreApplication::translate("D_AnalysisWindow", "Smooth Transformation", nullptr));
        action_Keep_Aspect_Ratio->setText(QCoreApplication::translate("D_AnalysisWindow", "Keep Aspect Ratio", nullptr));
        action_Show_Normal->setText(QCoreApplication::translate("D_AnalysisWindow", "Normal", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Normal->setShortcut(QCoreApplication::translate("D_AnalysisWindow", "F10", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Minimum->setText(QCoreApplication::translate("D_AnalysisWindow", "Minimum", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Minimum->setShortcut(QCoreApplication::translate("D_AnalysisWindow", "F9", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Maximum->setText(QCoreApplication::translate("D_AnalysisWindow", "Maximum", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Maximum->setShortcut(QCoreApplication::translate("D_AnalysisWindow", "F11", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Fullscreen->setText(QCoreApplication::translate("D_AnalysisWindow", "Fullscreen", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Fullscreen->setShortcut(QCoreApplication::translate("D_AnalysisWindow", "F12", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Images->setText(QCoreApplication::translate("D_AnalysisWindow", "Show Images", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Images->setShortcut(QCoreApplication::translate("D_AnalysisWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Plots->setText(QCoreApplication::translate("D_AnalysisWindow", "Show Plots", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Plots->setShortcut(QCoreApplication::translate("D_AnalysisWindow", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Get_Images->setText(QCoreApplication::translate("D_AnalysisWindow", "Get Images", nullptr));
#if QT_CONFIG(shortcut)
        action_Get_Images->setShortcut(QCoreApplication::translate("D_AnalysisWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Update_Views->setText(QCoreApplication::translate("D_AnalysisWindow", "Update Views", nullptr));
#if QT_CONFIG(shortcut)
        action_Update_Views->setShortcut(QCoreApplication::translate("D_AnalysisWindow", "F4", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Rename_Image->setText(QCoreApplication::translate("D_AnalysisWindow", "Rename Image", nullptr));
#if QT_CONFIG(shortcut)
        action_Rename_Image->setShortcut(QCoreApplication::translate("D_AnalysisWindow", "Alt+I", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Rename_Component->setText(QCoreApplication::translate("D_AnalysisWindow", "Rename Component", nullptr));
#if QT_CONFIG(shortcut)
        action_Rename_Component->setShortcut(QCoreApplication::translate("D_AnalysisWindow", "Alt+C", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Save_Image->setText(QCoreApplication::translate("D_AnalysisWindow", "Save Image", nullptr));
        action_Save_Plot->setText(QCoreApplication::translate("D_AnalysisWindow", "Save Plot", nullptr));
        action_Save_Table->setText(QCoreApplication::translate("D_AnalysisWindow", "Save Table", nullptr));
        action_Save_Image_Plot_Table->setText(QCoreApplication::translate("D_AnalysisWindow", "Save Image, Plot, Table", nullptr));
#if QT_CONFIG(shortcut)
        action_Save_Image_Plot_Table->setShortcut(QCoreApplication::translate("D_AnalysisWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_Images->setTitle(QCoreApplication::translate("D_AnalysisWindow", "Images", nullptr));
        label_Img_Type_MA->setText(QCoreApplication::translate("D_AnalysisWindow", "Type MA", nullptr));
        label_Img_Type_QI->setText(QCoreApplication::translate("D_AnalysisWindow", "Type QI", nullptr));
        pushButton_ImgLab_GetImage->setText(QCoreApplication::translate("D_AnalysisWindow", "Set Label Image (Alt + L)", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_ImgLab_GetImage->setShortcut(QCoreApplication::translate("D_AnalysisWindow", "Alt+L", nullptr));
#endif // QT_CONFIG(shortcut)
        comboBox_ImgLab_Connectivity->setItemText(0, QCoreApplication::translate("D_AnalysisWindow", "8-Connectivity", nullptr));
        comboBox_ImgLab_Connectivity->setItemText(1, QCoreApplication::translate("D_AnalysisWindow", "4-Connectivity", nullptr));

        label_ImgLab_Info->setText(QCoreApplication::translate("D_AnalysisWindow", "The Labels in this image are used to define the regions of the components.", nullptr));
        tabWidget_Images->setTabText(tabWidget_Images->indexOf(tab_ImgLab), QCoreApplication::translate("D_AnalysisWindow", "IN - Labels", nullptr));
        pushButton_ImgVal_AddImage->setText(QCoreApplication::translate("D_AnalysisWindow", "Add Value Image (Alt + V)", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_ImgVal_AddImage->setShortcut(QCoreApplication::translate("D_AnalysisWindow", "Alt+V", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_ImgVal_Clear->setText(QCoreApplication::translate("D_AnalysisWindow", "Clear Value Images", nullptr));
        label_ImgVal_Info->setText(QCoreApplication::translate("D_AnalysisWindow", "The pixel values from these images are used for histograms, statistics, etc.", nullptr));
        tabWidget_Images->setTabText(tabWidget_Images->indexOf(tab_ImgVal), QCoreApplication::translate("D_AnalysisWindow", "IN - Values", nullptr));
        label_ImgFea_Scale->setText(QCoreApplication::translate("D_AnalysisWindow", "Scale", nullptr));
        label_ImgFea_Precision->setText(QCoreApplication::translate("D_AnalysisWindow", "Precision", nullptr));
        label_ImgFea_Thickness->setText(QCoreApplication::translate("D_AnalysisWindow", "Thickness", nullptr));
        label_ImgFea_Info->setText(QCoreApplication::translate("D_AnalysisWindow", "Features of the components descibing their shape (pixel values are ignored).", nullptr));
        tabWidget_Images->setTabText(tabWidget_Images->indexOf(tab_ImgFea), QCoreApplication::translate("D_AnalysisWindow", "Feature", nullptr));
        label_ImgSta_Info->setText(QCoreApplication::translate("D_AnalysisWindow", "Statistical quantities about the pixel values in the value images resoved after components.", nullptr));
        label_ImgSta_Thickness->setText(QCoreApplication::translate("D_AnalysisWindow", "Thickness", nullptr));
        label_ImgSta_Precision->setText(QCoreApplication::translate("D_AnalysisWindow", "Precision", nullptr));
        label_ImgSta_Scale->setText(QCoreApplication::translate("D_AnalysisWindow", "Scale", nullptr));
        tabWidget_Images->setTabText(tabWidget_Images->indexOf(tab_ImgSta), QCoreApplication::translate("D_AnalysisWindow", "Statistic", nullptr));
        label_Img_Scale->setText(QCoreApplication::translate("D_AnalysisWindow", "Scale", nullptr));
        label_Img_Size->setText(QCoreApplication::translate("D_AnalysisWindow", "Size", nullptr));
        label_Img_ValueAtPos->setText(QCoreApplication::translate("D_AnalysisWindow", "Value", nullptr));
        groupBox_Plots->setTitle(QCoreApplication::translate("D_AnalysisWindow", "Plots and Tables", nullptr));
        label_PlotPixel_Hist_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        label_PlotPixel_Hist_X_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "in", nullptr));
        label_PlotPixel_Hist_Classes->setText(QCoreApplication::translate("D_AnalysisWindow", "Classes:", nullptr));
        checkBox_PlotPixel_Hist_Uniform->setText(QCoreApplication::translate("D_AnalysisWindow", "Uni", nullptr));
        checkBox_PlotPixel_Hist_Accumulate->setText(QCoreApplication::translate("D_AnalysisWindow", "Acc", nullptr));
        label_PlotPixel_Hist_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotPixel_Hist_Y_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "Amount of Pixels", nullptr));
        label_PlotPixel_Axe_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        label_PlotPixel_Axe_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotPixel_Axe_X_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "in", nullptr));
        label_PlotPixel_ScatterValue_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotPixel_ScatterValue_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        label_PlotPixel_ScatterHist_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        checkBox_PlotPixel_ScatterHist_Uniform->setText(QCoreApplication::translate("D_AnalysisWindow", "Uni", nullptr));
        checkBox_PlotPixel_ScatterHist_Accumulate->setText(QCoreApplication::translate("D_AnalysisWindow", "Acc", nullptr));
        label_PlotPixel_ScatterHist_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotPixel_ScatterHist_Classes->setText(QCoreApplication::translate("D_AnalysisWindow", "Classes:", nullptr));
        label_PlotPixel_ScatterHist_Y_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "in", nullptr));
        label_PlotPixel_ScatterHist_X_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "in", nullptr));
        label_PlotPixel_ScatterAxe_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        label_PlotPixel_ScatterAxe_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotPixel_ScatterAxe_X_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "in", nullptr));
        label_PlotPixel_ScatterAxe_Y_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "in", nullptr));
        label_PlotPixel_ScatterAxe_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "of", nullptr));
        tabWidget_Plots->setTabText(tabWidget_Plots->indexOf(tab_PlotPixel), QCoreApplication::translate("D_AnalysisWindow", "Pixels", nullptr));
        label_PlotComp_Feat_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotComp_Feat_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        label_PlotComp_Feat_X_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "Components", nullptr));
        label_PlotComp_FeatHist_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotComp_FeatHist_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        checkBox_PlotComp_FeatHist_Accumulate->setText(QCoreApplication::translate("D_AnalysisWindow", "Acc", nullptr));
        checkBox_PlotComp_FeatHist_Uniform->setText(QCoreApplication::translate("D_AnalysisWindow", "Uni", nullptr));
        label_PlotComp_FeatHist_Classes->setText(QCoreApplication::translate("D_AnalysisWindow", "Classes:", nullptr));
        label_PlotComp_FeatHist_Y_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "Amount of Components", nullptr));
        label_PlotComp_FeatScatter_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotComp_FeatScatter_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        label_PlotComp_Stat_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        label_PlotComp_Stat_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotComp_StatHist_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        label_PlotComp_StatHist_Classes->setText(QCoreApplication::translate("D_AnalysisWindow", "Classes:", nullptr));
        checkBox_PlotComp_StatHist_Uniform->setText(QCoreApplication::translate("D_AnalysisWindow", "Uni", nullptr));
        checkBox_PlotComp_StatHist_Accumulate->setText(QCoreApplication::translate("D_AnalysisWindow", "Acc", nullptr));
        label_PlotComp_StatHist_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotComp_StatHist_X_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "in", nullptr));
        label_PlotComp_StatHist_Y_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "Amount of Components", nullptr));
        label_PlotComp_StatScatter_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        label_PlotComp_StatScatter_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotComp_StatScatter_X_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "in", nullptr));
        label_PlotComp_StatScatter_Y_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "in", nullptr));
        label_PlotComp_StatFeatScatter_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        label_PlotComp_StatFeatScatter_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotComp_StatFeatScatter_X_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "in", nullptr));
        tabWidget_Plots->setTabText(tabWidget_Plots->indexOf(tab_PlotComp), QCoreApplication::translate("D_AnalysisWindow", "Components", nullptr));
        label_PlotImg_Feat_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotImg_Feat_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        label_PlotImg_Stat_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        label_PlotImg_Stat_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotImg_Stat_Y_Description_1->setText(QCoreApplication::translate("D_AnalysisWindow", "of", nullptr));
        label_PlotImg_Stat_X_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "Images", nullptr));
        label_PlotImg_StatHist_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        label_PlotImg_StatHist_X_Description_1->setText(QCoreApplication::translate("D_AnalysisWindow", "of", nullptr));
        label_PlotImg_StatHist_Classes->setText(QCoreApplication::translate("D_AnalysisWindow", "Classes:", nullptr));
        checkBox_PlotImg_StatHist_Uni->setText(QCoreApplication::translate("D_AnalysisWindow", "uni", nullptr));
        checkBox_PlotImg_StatHist_Acc->setText(QCoreApplication::translate("D_AnalysisWindow", "Acc", nullptr));
        label_PlotImg_StatHist_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotImg_StatHist_Y_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "Amount of Images", nullptr));
        label_PlotImg_StatScatter_X_Description_1->setText(QCoreApplication::translate("D_AnalysisWindow", "of", nullptr));
        label_PlotImg_StatScatter_Y_Description_1->setText(QCoreApplication::translate("D_AnalysisWindow", "of", nullptr));
        label_PlotImg_StatScatter_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotImg_StatScatter_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        label_PlotImg_StatFeatScatter_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        label_PlotImg_StatFeatScatter_X_Description_1->setText(QCoreApplication::translate("D_AnalysisWindow", "of", nullptr));
        label_PlotImg_StatFeatScatter_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_PlotImg_StatFeatScatter_Y_Description_1->setText(QCoreApplication::translate("D_AnalysisWindow", "of", nullptr));
        label_PlotImg_FeatHist_Y->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        checkBox_PlotImg_FeatHist_Uni->setText(QCoreApplication::translate("D_AnalysisWindow", "Uni", nullptr));
        label_PlotImg_FeatHist_Classes->setText(QCoreApplication::translate("D_AnalysisWindow", "Classes:", nullptr));
        label_PlotImg_FeatHist_X->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        checkBox_PlotImg_FeatHist_Acc->setText(QCoreApplication::translate("D_AnalysisWindow", "Acc", nullptr));
        label_PlotImg_FeatHist_X_Description_1->setText(QCoreApplication::translate("D_AnalysisWindow", "of", nullptr));
        label_PlotImg_FeatHist_Y_Description->setText(QCoreApplication::translate("D_AnalysisWindow", "Amount of Images", nullptr));
        tabWidget_Plots->setTabText(tabWidget_Plots->indexOf(tab_PlotImg), QCoreApplication::translate("D_AnalysisWindow", "Image", nullptr));
        label_PlotStack_Stat_StatImg->setText(QCoreApplication::translate("D_AnalysisWindow", "(Components in Images)", nullptr));
        label_PlotStack_Stat_StatComp->setText(QCoreApplication::translate("D_AnalysisWindow", "(Pixel-Values in Components)", nullptr));
        label_PlotStack_Stat_Description_1->setText(QCoreApplication::translate("D_AnalysisWindow", "of", nullptr));
        label_PlotStack_Stat_Description_2->setText(QCoreApplication::translate("D_AnalysisWindow", "of", nullptr));
        label_PlotStack_Stat_StatStack_2->setText(QCoreApplication::translate("D_AnalysisWindow", "(Images in Stack)", nullptr));
        label_PlotStack_Stat_StatStack_1->setText(QCoreApplication::translate("D_AnalysisWindow", "Stats", nullptr));
        tabWidget_Plots->setTabText(tabWidget_Plots->indexOf(tab_PlotStack), QCoreApplication::translate("D_AnalysisWindow", "Stack", nullptr));
        checkBox_Plot_Y_Range->setText(QCoreApplication::translate("D_AnalysisWindow", "Y:", nullptr));
        label_Plot_Time->setText(QCoreApplication::translate("D_AnalysisWindow", "plot time", nullptr));
        checkBox_Plot_X_Range->setText(QCoreApplication::translate("D_AnalysisWindow", "X:", nullptr));
        tabWidget_PlotTable->setTabText(tabWidget_PlotTable->indexOf(tab_Plot), QCoreApplication::translate("D_AnalysisWindow", "Plot", nullptr));
        tabWidget_PlotTable->setTabText(tabWidget_PlotTable->indexOf(tab_Table), QCoreApplication::translate("D_AnalysisWindow", "Table", nullptr));
        menuViewer->setTitle(QCoreApplication::translate("D_AnalysisWindow", "Viewer", nullptr));
        menuWindow->setTitle(QCoreApplication::translate("D_AnalysisWindow", "Window", nullptr));
        menuData->setTitle(QCoreApplication::translate("D_AnalysisWindow", "Data", nullptr));
        menuUpdate->setTitle(QCoreApplication::translate("D_AnalysisWindow", "Update", nullptr));
        menuLayout->setTitle(QCoreApplication::translate("D_AnalysisWindow", "Layout", nullptr));
        menuRename->setTitle(QCoreApplication::translate("D_AnalysisWindow", "Rename", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_AnalysisWindow: public Ui_D_AnalysisWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_ANALYSISWINDOW_H
