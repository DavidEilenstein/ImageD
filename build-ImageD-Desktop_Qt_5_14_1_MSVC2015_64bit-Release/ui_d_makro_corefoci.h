/********************************************************************************
** Form generated from reading UI file 'd_makro_corefoci.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_COREFOCI_H
#define UI_D_MAKRO_COREFOCI_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_CoreFoci
{
public:
    QAction *action_Smooth_Transformation;
    QAction *action_Keep_Aspect_Ratio;
    QAction *action_Load_Images;
    QAction *action_Update_All;
    QAction *action_Update_Cores;
    QAction *action_Update_Foci;
    QAction *action_Update_Results;
    QAction *action_Update_View;
    QAction *action_Next_Image;
    QAction *action_Clear_Images;
    QAction *action_Save_Image_Cores;
    QAction *action_Save_Image_Foci;
    QAction *action_Save_Image_Results;
    QAction *action_Stack_Process;
    QAction *action_Save_image_cytoplasma;
    QAction *action_Show_View_Nuclei;
    QAction *action_Show_View_Cytoplasma;
    QAction *action_Show_View_Foci;
    QAction *action_Show_View_Results;
    QAction *action_Show_Settings_and_Other;
    QAction *action_Show_Minimized;
    QAction *action_Show_Normal;
    QAction *action_Show_Maximized;
    QAction *action_Show_Fullscreen;
    QAction *action_Process_Stack;
    QAction *action_Save_plot_image;
    QAction *action_Save_plot_stack;
    QWidget *centralwidget;
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_Viewer;
    QGroupBox *groupBox_View_Result;
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget_View_Results;
    QWidget *tab_Result_Image;
    QGridLayout *gridLayout_8;
    QLabel *label_View_Result_R;
    QComboBox *comboBox_View_Result_R;
    QLabel *label_View_Result_G;
    QLabel *label_View_Result_B;
    QComboBox *comboBox_View_Result_G;
    QComboBox *comboBox_View_Result_B;
    QGraphicsView *graphicsView_Result;
    QHBoxLayout *horizontalLayout_ResCol_Preset;
    QPushButton *pushButton_ResCol_Preset_NormalAll;
    QPushButton *pushButton_ResCol_Preset_ContrastAll;
    QPushButton *pushButton_ResCol_Preset_NucSegmentation;
    QPushButton *pushButton_ResCol_Preset_Plasma;
    QPushButton *pushButton_ResCol_Preset_Foci;
    QPushButton *pushButton_ResCol_Preset_Regions;
    QWidget *tab_ResPlo_Cells;
    QGridLayout *gridLayout_10;
    QComboBox *comboBox_ResPlo_Cells_Type;
    QStackedWidget *stackedWidget_ResPlo_Cells;
    QWidget *page_ResPlo_Cells_Att;
    QGridLayout *gridLayout_14;
    QComboBox *comboBox_ResPlo_Cells_Att_Att;
    QWidget *page_ResPlo_Cells_Att_Hist;
    QGridLayout *gridLayout_17;
    QComboBox *comboBox_ResPlo_Cells_Att_Hist_Att;
    QFrame *lineResPlo_Cells_Att_Hist;
    QLabel *label_ResPlo_Cells_Att_Hist_Classes;
    QSpinBox *spinBox_ResPlo_Cells_Att_Hist_Classes;
    QCheckBox *checkBox_ResPlo_Cells_Att_Hist_Uni;
    QCheckBox *checkBox_ResPlo_Cells_Att_Hist_Acc;
    QWidget *page_ResPlo_Cells_Att_Scatter;
    QGridLayout *gridLayout_18;
    QComboBox *comboBox_ResPlo_Cells_Att_Scatter_Att_X;
    QComboBox *comboBox_ResPlo_Cells_Att_Scatter_Att_Y;
    QGridLayout *gridLayout_ResPlo_Cells;
    QWidget *tab_ResTab_Cells;
    QGridLayout *gridLayout_19;
    QTableWidget *tableWidget_Cells;
    QComboBox *comboBox_TabCell_Type;
    QWidget *tab_ResPlo_Image;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_ResPlo_Image;
    QComboBox *comboBox_ResPlo_Img_Type;
    QStackedWidget *stackedWidget_ResPlo_Img;
    QWidget *page_ResPlo_Img_Att;
    QGridLayout *gridLayout_21;
    QComboBox *comboBox_ResPlo_Img_Att_Att;
    QWidget *page_ResPlo_Img_Att_Hist;
    QGridLayout *gridLayout_22;
    QComboBox *comboBox_ResPlo_Img_Att_Hist_Att;
    QFrame *line_ResPlo_Img_Att_Hist;
    QLabel *label_ResPlo_Img_Att_Hist_Classes;
    QSpinBox *spinBox_ResPlo_Img_Att_Hist_Classes;
    QCheckBox *checkBox_ResPlo_Img_Att_Hist_Uni;
    QCheckBox *checkBox_ResPlo_Img_Att_Hist_Acc;
    QWidget *page_ResPlo_Img_Att_Scatter;
    QGridLayout *gridLayout_23;
    QComboBox *comboBox_ResPlo_Img_Att_Scatter_Att_X;
    QComboBox *comboBox_ResPlo_Img_Att_Scatter_Att_Y;
    QWidget *tab_ResTab_Image;
    QGridLayout *gridLayout_20;
    QTableWidget *tableWidget_Image;
    QComboBox *comboBox_TabImg_Type;
    QGroupBox *groupBox_View_Cyto;
    QGridLayout *gridLayout_9;
    QComboBox *comboBox_View_Cyto;
    QLabel *label_View_Cyto_Format_QI;
    QLabel *label_View_Cyto_Format_MA;
    QGraphicsView *graphicsView_Cyto;
    QGroupBox *groupBox_View_Cores;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView_Cores;
    QComboBox *comboBox_View_Cores;
    QLabel *label_View_Cores_QI_Format;
    QLabel *label_View_Cores_MA_Format;
    QGroupBox *groupBox_View_Foci;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox_View_Foci;
    QLabel *label_View_Foci_QI_Format;
    QLabel *label_View_Foci_MA_Format;
    QGraphicsView *graphicsView_Foci;
    QGroupBox *groupBox_Settings;
    QGridLayout *gridLayout_13;
    QTabWidget *tabWidget;
    QWidget *tab_InputDefinition;
    QGridLayout *gridLayout_35;
    QGroupBox *groupBox_MikroPreset;
    QGridLayout *gridLayout_34;
    QComboBox *comboBox_Preset;
    QPushButton *pushButton_PresetActivate;
    QGroupBox *groupBox_PageIndex;
    QGridLayout *gridLayout_36;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QSpinBox *spinBox_IndexNuclei;
    QSpinBox *spinBox_IndexFoci;
    QSpinBox *spinBox_IndexCytoplasm;
    QSpacerItem *verticalSpacer;
    QWidget *tab_Settings;
    QGridLayout *gridLayout_24;
    QGroupBox *groupBox_File;
    QGridLayout *gridLayout_15;
    QComboBox *comboBox_FileName;
    QGroupBox *groupBox_Settings_Foci;
    QGridLayout *gridLayout_7;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_SetFoci_02_Sigma;
    QLabel *label_3;
    QSpinBox *spinBox_SetFoci_02_Size;
    QLabel *label_2;
    QLabel *label;
    QSpinBox *spinBox_SetFoci_03_Size;
    QDoubleSpinBox *doubleSpinBox_SetFoci_03_Offset;
    QLabel *label_8;
    QLabel *label_9;
    QSpinBox *spinBox_SetFoci_04_Size;
    QLabel *label_5;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QSpinBox *spinBox_SetFoci_05_Size;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QSpinBox *spinBox_SetFoci_06_Size_Min;
    QSpinBox *spinBox_SetFoci_06_Size_Max;
    QLabel *label_32;
    QLabel *label_31;
    QCheckBox *checkBox_SetFoci_13_ExcludeBordered;
    QLabel *label_33;
    QGroupBox *groupBox_Settings_Cores;
    QGridLayout *gridLayout_5;
    QSpinBox *spinBox_SetCore_14_AreaMinOfBig;
    QLabel *label_SetCore_04_Thres_Desription;
    QLabel *label_SetCore_05_Fill_Title;
    QLabel *label_SetCore_08_Desription;
    QLabel *label_SetCore_02_Gauss_Pos;
    QLabel *label_SetCore_04_Thres_Pos;
    QLabel *label_SetCore_02_Gauss_Title;
    QDoubleSpinBox *doubleSpinBox_SetCore_02_Gauss_Sigma;
    QLabel *label_SetCore_12_Open_Pos;
    QSpinBox *spinBox_SetCore_09_Eilenstein_Size;
    QDoubleSpinBox *doubleSpinBox_SetCore_04_Thres_Offset;
    QLabel *label_SetCore_12_Open_Desription;
    QLabel *label_SetCore_12_Open_Title;
    QLabel *label_SetCore_09_Eilenstein_Pos;
    QLabel *label_SetCore_09_Eilenstein_Title;
    QSpinBox *spinBox_SetCore_12_Open_Area;
    QLabel *label_SetCore_04_Thres_Title;
    QSpinBox *spinBox_SetCore_02_Gauss_Size;
    QSpinBox *spinBox_SetCore_04_Thres_Size;
    QLabel *label_SetCore_02_Gauss_Desription;
    QLabel *label_SetCore_05_Fill_Description;
    QSpinBox *spinBox_SetCore_05_Fill_Area;
    QLabel *label_SetCore_05_Fill_Pos;
    QLabel *label_SetCore_13_Dilation_Pos;
    QLabel *label_SetCore_13_Dilation_Description;
    QLabel *label_SetCore_11_Thresh_Pos;
    QSpinBox *spinBox_SetCore_13_Dilation_Size;
    QDoubleSpinBox *doubleSpinBox_Set_Core_09_Eilenstein_Offset;
    QSpinBox *spinBox_SetCore_11_Thresh_Thres;
    QLabel *label_SetCore_11_Thresh_Desription;
    QLabel *label_SetCore_11_Thresh_Title;
    QLabel *label_SetCore_13_Dilation_Title;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QCheckBox *checkBox_SetCore_13_ExcludeBordered;
    QLabel *label_41;
    QSpinBox *spinBox_SetCore_14_AreaMaxOfSmall;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_40;
    QLabel *label_44;
    QSpinBox *spinBox_SetCore_14_AreaDistMin;
    QSpinBox *spinBox_SetCore_14_AreaDistMax;
    QGroupBox *groupBox_Settings_Cyto;
    QGridLayout *gridLayout;
    QLabel *label_11;
    QSpinBox *spinBox_SetCyto_Gauss_Size;
    QLabel *label_10;
    QLabel *label_20;
    QLabel *label_19;
    QLabel *label_22;
    QSpinBox *spinBox_SetCyto_Dilation_Size;
    QSpinBox *spinBox_SetCyto_Closing_Size;
    QDoubleSpinBox *doubleSpinBox_SetCyto_Gauss_Sigma;
    QLabel *label_21;
    QLabel *label_12;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QSpinBox *spinBox_SetCyto_Thresh_Size;
    QDoubleSpinBox *doubleSpinBox_SetCyto_Thresh_Offset;
    QGroupBox *groupBox_Results;
    QGridLayout *gridLayout_16;
    QLabel *label_27;
    QLabel *label_25;
    QSpinBox *spinBox_Results_SpreadMax;
    QLabel *label_26;
    QWidget *tab_Output;
    QGridLayout *gridLayout_25;
    QGroupBox *groupBox_OutImg;
    QGridLayout *gridLayout_27;
    QGroupBox *groupBox_OutImg_Img;
    QGridLayout *gridLayout_26;
    QCheckBox *checkBox_OutImg_Img_Plasma;
    QCheckBox *checkBox_OutImg_Img_Contrast;
    QCheckBox *checkBox_OutImg_Img_ProcSteps;
    QCheckBox *checkBox_OutImg_Img_Nuclei;
    QSpacerItem *verticalSpacer_OutImg_Img;
    QCheckBox *checkBox_OutImg_Img_Foci;
    QCheckBox *checkBox_OutImg_Img_Regions;
    QCheckBox *checkBox_OutImg_Img_Normal;
    QFrame *line_OutImg_Img;
    QGroupBox *groupBox_OutImg_Plots;
    QGridLayout *gridLayout_33;
    QCheckBox *checkBox_OutImg_Plots_FocArea;
    QCheckBox *checkBox_OutImg_Plots_Bar;
    QCheckBox *checkBox_OutImg_Plots_Hist;
    QCheckBox *checkBox_OutImg_Plots_FocNumber;
    QCheckBox *checkBox_OutImg_Plots_CytArea;
    QCheckBox *checkBox_OutImg_Plots_Scatter;
    QCheckBox *checkBox_OutImg_Plots_NucArea;
    QFrame *line_OutImg_Plots;
    QSpacerItem *verticalSpacer_OutImg_Plots;
    QCheckBox *checkBox_OutImg_Plots_NucMeanInt;
    QGroupBox *groupBox_OutImg_Table;
    QGridLayout *gridLayout_30;
    QCheckBox *checkBox_OutImg_Table_Stat;
    QCheckBox *checkBox_OutImg_Table_Raw;
    QSpacerItem *verticalSpacer_OutImg_Table;
    QGroupBox *groupBox_OutStack;
    QGridLayout *gridLayout_28;
    QGroupBox *groupBox_OutStack_Img;
    QGridLayout *gridLayout_31;
    QCheckBox *checkBox_OutStack_Img_Plasma;
    QCheckBox *checkBox_OutStack_Img_Nuclei;
    QCheckBox *checkBox_OutStack_Img_Regions;
    QCheckBox *checkBox_OutStack_Img_Foci;
    QCheckBox *checkBox_OutStack_Img_Normal;
    QCheckBox *checkBox_OutStack_Img_Contrast;
    QSpacerItem *verticalSpacer_OutStack_Img;
    QGroupBox *groupBox_OutStack_Plots;
    QGridLayout *gridLayout_32;
    QCheckBox *checkBox_OutStack_Plots_FocNumberMean;
    QCheckBox *checkBox_OutStack_Plots_CytArea_Sum;
    QCheckBox *checkBox_OutStack_Plots_FocNumber_p_NucNumber;
    QCheckBox *checkBox_OutStack_Plots_NucNumberSum;
    QCheckBox *checkBox_OutStack_Plots_Hist;
    QCheckBox *checkBox_OutStack_Plots_Bar;
    QCheckBox *checkBox_OutStack_Plots_FocNumber_p_CytArea;
    QCheckBox *checkBox_OutStack_Plots_NucAreaSum;
    QFrame *line_OutStack_Plots;
    QCheckBox *checkBox_OutStack_Plots_FocAreaMean;
    QCheckBox *checkBox_OutStack_Plots_Scatter;
    QCheckBox *checkBox_OutStack_Plots_CytAreaMean;
    QCheckBox *checkBox_OutStack_Plots_FocAreaSum;
    QCheckBox *checkBox_OutStack_Plots_FocNumber_p_NucArea;
    QSpacerItem *verticalSpacer_OutStack_Plots;
    QCheckBox *checkBox_OutStack_Plots_FocNumberSum;
    QCheckBox *checkBox_OutStack_Plots_NucAreaMean;
    QCheckBox *checkBox_OutStack_Plots_CytArea_p_NucArea;
    QGroupBox *groupBox_OutStack_Table;
    QGridLayout *gridLayout_29;
    QCheckBox *checkBox_OutStack_Table_Raw;
    QCheckBox *checkBox_OutStack_Table_Stat;
    QSpacerItem *verticalSpacer_OutStack_Table;
    QGroupBox *groupBox_Summary;
    QGridLayout *gridLayout_6;
    QTableWidget *tableWidget_Summary_CurrentCell_Single;
    QTableWidget *tableWidget_Summary_CurrentCell_Quotients;
    QMenuBar *menubar;
    QMenu *menuLayout;
    QMenu *menuViewer;
    QMenu *menuData;
    QMenu *menuUpdate;
    QMenu *menuStack_Processing;
    QMenu *menuWindow;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_CoreFoci)
    {
        if (D_MAKRO_CoreFoci->objectName().isEmpty())
            D_MAKRO_CoreFoci->setObjectName(QString::fromUtf8("D_MAKRO_CoreFoci"));
        D_MAKRO_CoreFoci->resize(1352, 906);
        action_Smooth_Transformation = new QAction(D_MAKRO_CoreFoci);
        action_Smooth_Transformation->setObjectName(QString::fromUtf8("action_Smooth_Transformation"));
        action_Smooth_Transformation->setCheckable(true);
        action_Smooth_Transformation->setChecked(true);
        action_Keep_Aspect_Ratio = new QAction(D_MAKRO_CoreFoci);
        action_Keep_Aspect_Ratio->setObjectName(QString::fromUtf8("action_Keep_Aspect_Ratio"));
        action_Keep_Aspect_Ratio->setCheckable(true);
        action_Keep_Aspect_Ratio->setChecked(true);
        action_Load_Images = new QAction(D_MAKRO_CoreFoci);
        action_Load_Images->setObjectName(QString::fromUtf8("action_Load_Images"));
        action_Update_All = new QAction(D_MAKRO_CoreFoci);
        action_Update_All->setObjectName(QString::fromUtf8("action_Update_All"));
        action_Update_Cores = new QAction(D_MAKRO_CoreFoci);
        action_Update_Cores->setObjectName(QString::fromUtf8("action_Update_Cores"));
        action_Update_Cores->setEnabled(false);
        action_Update_Foci = new QAction(D_MAKRO_CoreFoci);
        action_Update_Foci->setObjectName(QString::fromUtf8("action_Update_Foci"));
        action_Update_Foci->setEnabled(false);
        action_Update_Results = new QAction(D_MAKRO_CoreFoci);
        action_Update_Results->setObjectName(QString::fromUtf8("action_Update_Results"));
        action_Update_Results->setEnabled(false);
        action_Update_View = new QAction(D_MAKRO_CoreFoci);
        action_Update_View->setObjectName(QString::fromUtf8("action_Update_View"));
        action_Next_Image = new QAction(D_MAKRO_CoreFoci);
        action_Next_Image->setObjectName(QString::fromUtf8("action_Next_Image"));
        action_Clear_Images = new QAction(D_MAKRO_CoreFoci);
        action_Clear_Images->setObjectName(QString::fromUtf8("action_Clear_Images"));
        action_Save_Image_Cores = new QAction(D_MAKRO_CoreFoci);
        action_Save_Image_Cores->setObjectName(QString::fromUtf8("action_Save_Image_Cores"));
        action_Save_Image_Foci = new QAction(D_MAKRO_CoreFoci);
        action_Save_Image_Foci->setObjectName(QString::fromUtf8("action_Save_Image_Foci"));
        action_Save_Image_Results = new QAction(D_MAKRO_CoreFoci);
        action_Save_Image_Results->setObjectName(QString::fromUtf8("action_Save_Image_Results"));
        action_Save_Image_Results->setShortcutVisibleInContextMenu(true);
        action_Stack_Process = new QAction(D_MAKRO_CoreFoci);
        action_Stack_Process->setObjectName(QString::fromUtf8("action_Stack_Process"));
        action_Save_image_cytoplasma = new QAction(D_MAKRO_CoreFoci);
        action_Save_image_cytoplasma->setObjectName(QString::fromUtf8("action_Save_image_cytoplasma"));
        action_Show_View_Nuclei = new QAction(D_MAKRO_CoreFoci);
        action_Show_View_Nuclei->setObjectName(QString::fromUtf8("action_Show_View_Nuclei"));
        action_Show_View_Nuclei->setCheckable(true);
        action_Show_View_Nuclei->setChecked(true);
        action_Show_View_Cytoplasma = new QAction(D_MAKRO_CoreFoci);
        action_Show_View_Cytoplasma->setObjectName(QString::fromUtf8("action_Show_View_Cytoplasma"));
        action_Show_View_Cytoplasma->setCheckable(true);
        action_Show_View_Cytoplasma->setChecked(true);
        action_Show_View_Foci = new QAction(D_MAKRO_CoreFoci);
        action_Show_View_Foci->setObjectName(QString::fromUtf8("action_Show_View_Foci"));
        action_Show_View_Foci->setCheckable(true);
        action_Show_View_Foci->setChecked(true);
        action_Show_View_Results = new QAction(D_MAKRO_CoreFoci);
        action_Show_View_Results->setObjectName(QString::fromUtf8("action_Show_View_Results"));
        action_Show_View_Results->setCheckable(true);
        action_Show_View_Results->setChecked(true);
        action_Show_Settings_and_Other = new QAction(D_MAKRO_CoreFoci);
        action_Show_Settings_and_Other->setObjectName(QString::fromUtf8("action_Show_Settings_and_Other"));
        action_Show_Settings_and_Other->setCheckable(true);
        action_Show_Settings_and_Other->setChecked(true);
        action_Show_Minimized = new QAction(D_MAKRO_CoreFoci);
        action_Show_Minimized->setObjectName(QString::fromUtf8("action_Show_Minimized"));
        action_Show_Normal = new QAction(D_MAKRO_CoreFoci);
        action_Show_Normal->setObjectName(QString::fromUtf8("action_Show_Normal"));
        action_Show_Maximized = new QAction(D_MAKRO_CoreFoci);
        action_Show_Maximized->setObjectName(QString::fromUtf8("action_Show_Maximized"));
        action_Show_Fullscreen = new QAction(D_MAKRO_CoreFoci);
        action_Show_Fullscreen->setObjectName(QString::fromUtf8("action_Show_Fullscreen"));
        action_Process_Stack = new QAction(D_MAKRO_CoreFoci);
        action_Process_Stack->setObjectName(QString::fromUtf8("action_Process_Stack"));
        action_Save_plot_image = new QAction(D_MAKRO_CoreFoci);
        action_Save_plot_image->setObjectName(QString::fromUtf8("action_Save_plot_image"));
        action_Save_plot_stack = new QAction(D_MAKRO_CoreFoci);
        action_Save_plot_stack->setObjectName(QString::fromUtf8("action_Save_plot_stack"));
        centralwidget = new QWidget(D_MAKRO_CoreFoci);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_12 = new QGridLayout(centralwidget);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_Viewer = new QGridLayout();
        gridLayout_Viewer->setSpacing(3);
        gridLayout_Viewer->setObjectName(QString::fromUtf8("gridLayout_Viewer"));
        groupBox_View_Result = new QGroupBox(centralwidget);
        groupBox_View_Result->setObjectName(QString::fromUtf8("groupBox_View_Result"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(groupBox_View_Result->sizePolicy().hasHeightForWidth());
        groupBox_View_Result->setSizePolicy(sizePolicy);
        groupBox_View_Result->setMinimumSize(QSize(375, 0));
        gridLayout_4 = new QGridLayout(groupBox_View_Result);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tabWidget_View_Results = new QTabWidget(groupBox_View_Result);
        tabWidget_View_Results->setObjectName(QString::fromUtf8("tabWidget_View_Results"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget_View_Results->sizePolicy().hasHeightForWidth());
        tabWidget_View_Results->setSizePolicy(sizePolicy1);
        tab_Result_Image = new QWidget();
        tab_Result_Image->setObjectName(QString::fromUtf8("tab_Result_Image"));
        gridLayout_8 = new QGridLayout(tab_Result_Image);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_View_Result_R = new QLabel(tab_Result_Image);
        label_View_Result_R->setObjectName(QString::fromUtf8("label_View_Result_R"));
        label_View_Result_R->setMaximumSize(QSize(10, 16777215));

        gridLayout_8->addWidget(label_View_Result_R, 0, 0, 1, 1);

        comboBox_View_Result_R = new QComboBox(tab_Result_Image);
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->addItem(QString());
        comboBox_View_Result_R->setObjectName(QString::fromUtf8("comboBox_View_Result_R"));

        gridLayout_8->addWidget(comboBox_View_Result_R, 0, 1, 1, 1);

        label_View_Result_G = new QLabel(tab_Result_Image);
        label_View_Result_G->setObjectName(QString::fromUtf8("label_View_Result_G"));
        label_View_Result_G->setMaximumSize(QSize(10, 16777215));

        gridLayout_8->addWidget(label_View_Result_G, 0, 2, 1, 1);

        label_View_Result_B = new QLabel(tab_Result_Image);
        label_View_Result_B->setObjectName(QString::fromUtf8("label_View_Result_B"));
        label_View_Result_B->setMaximumSize(QSize(10, 16777215));

        gridLayout_8->addWidget(label_View_Result_B, 0, 4, 1, 1);

        comboBox_View_Result_G = new QComboBox(tab_Result_Image);
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->addItem(QString());
        comboBox_View_Result_G->setObjectName(QString::fromUtf8("comboBox_View_Result_G"));

        gridLayout_8->addWidget(comboBox_View_Result_G, 0, 3, 1, 1);

        comboBox_View_Result_B = new QComboBox(tab_Result_Image);
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->addItem(QString());
        comboBox_View_Result_B->setObjectName(QString::fromUtf8("comboBox_View_Result_B"));

        gridLayout_8->addWidget(comboBox_View_Result_B, 0, 5, 1, 1);

        graphicsView_Result = new QGraphicsView(tab_Result_Image);
        graphicsView_Result->setObjectName(QString::fromUtf8("graphicsView_Result"));
        graphicsView_Result->setMouseTracking(true);

        gridLayout_8->addWidget(graphicsView_Result, 1, 0, 1, 6);

        horizontalLayout_ResCol_Preset = new QHBoxLayout();
        horizontalLayout_ResCol_Preset->setSpacing(3);
        horizontalLayout_ResCol_Preset->setObjectName(QString::fromUtf8("horizontalLayout_ResCol_Preset"));
        pushButton_ResCol_Preset_NormalAll = new QPushButton(tab_Result_Image);
        pushButton_ResCol_Preset_NormalAll->setObjectName(QString::fromUtf8("pushButton_ResCol_Preset_NormalAll"));

        horizontalLayout_ResCol_Preset->addWidget(pushButton_ResCol_Preset_NormalAll);

        pushButton_ResCol_Preset_ContrastAll = new QPushButton(tab_Result_Image);
        pushButton_ResCol_Preset_ContrastAll->setObjectName(QString::fromUtf8("pushButton_ResCol_Preset_ContrastAll"));

        horizontalLayout_ResCol_Preset->addWidget(pushButton_ResCol_Preset_ContrastAll);

        pushButton_ResCol_Preset_NucSegmentation = new QPushButton(tab_Result_Image);
        pushButton_ResCol_Preset_NucSegmentation->setObjectName(QString::fromUtf8("pushButton_ResCol_Preset_NucSegmentation"));

        horizontalLayout_ResCol_Preset->addWidget(pushButton_ResCol_Preset_NucSegmentation);

        pushButton_ResCol_Preset_Plasma = new QPushButton(tab_Result_Image);
        pushButton_ResCol_Preset_Plasma->setObjectName(QString::fromUtf8("pushButton_ResCol_Preset_Plasma"));

        horizontalLayout_ResCol_Preset->addWidget(pushButton_ResCol_Preset_Plasma);

        pushButton_ResCol_Preset_Foci = new QPushButton(tab_Result_Image);
        pushButton_ResCol_Preset_Foci->setObjectName(QString::fromUtf8("pushButton_ResCol_Preset_Foci"));

        horizontalLayout_ResCol_Preset->addWidget(pushButton_ResCol_Preset_Foci);

        pushButton_ResCol_Preset_Regions = new QPushButton(tab_Result_Image);
        pushButton_ResCol_Preset_Regions->setObjectName(QString::fromUtf8("pushButton_ResCol_Preset_Regions"));

        horizontalLayout_ResCol_Preset->addWidget(pushButton_ResCol_Preset_Regions);


        gridLayout_8->addLayout(horizontalLayout_ResCol_Preset, 2, 0, 1, 6);

        tabWidget_View_Results->addTab(tab_Result_Image, QString());
        tab_ResPlo_Cells = new QWidget();
        tab_ResPlo_Cells->setObjectName(QString::fromUtf8("tab_ResPlo_Cells"));
        gridLayout_10 = new QGridLayout(tab_ResPlo_Cells);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        comboBox_ResPlo_Cells_Type = new QComboBox(tab_ResPlo_Cells);
        comboBox_ResPlo_Cells_Type->setObjectName(QString::fromUtf8("comboBox_ResPlo_Cells_Type"));

        gridLayout_10->addWidget(comboBox_ResPlo_Cells_Type, 0, 0, 1, 1);

        stackedWidget_ResPlo_Cells = new QStackedWidget(tab_ResPlo_Cells);
        stackedWidget_ResPlo_Cells->setObjectName(QString::fromUtf8("stackedWidget_ResPlo_Cells"));
        stackedWidget_ResPlo_Cells->setMaximumSize(QSize(16777215, 20));
        page_ResPlo_Cells_Att = new QWidget();
        page_ResPlo_Cells_Att->setObjectName(QString::fromUtf8("page_ResPlo_Cells_Att"));
        gridLayout_14 = new QGridLayout(page_ResPlo_Cells_Att);
        gridLayout_14->setSpacing(3);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        comboBox_ResPlo_Cells_Att_Att = new QComboBox(page_ResPlo_Cells_Att);
        comboBox_ResPlo_Cells_Att_Att->setObjectName(QString::fromUtf8("comboBox_ResPlo_Cells_Att_Att"));

        gridLayout_14->addWidget(comboBox_ResPlo_Cells_Att_Att, 0, 0, 1, 1);

        stackedWidget_ResPlo_Cells->addWidget(page_ResPlo_Cells_Att);
        page_ResPlo_Cells_Att_Hist = new QWidget();
        page_ResPlo_Cells_Att_Hist->setObjectName(QString::fromUtf8("page_ResPlo_Cells_Att_Hist"));
        gridLayout_17 = new QGridLayout(page_ResPlo_Cells_Att_Hist);
        gridLayout_17->setSpacing(3);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        comboBox_ResPlo_Cells_Att_Hist_Att = new QComboBox(page_ResPlo_Cells_Att_Hist);
        comboBox_ResPlo_Cells_Att_Hist_Att->setObjectName(QString::fromUtf8("comboBox_ResPlo_Cells_Att_Hist_Att"));

        gridLayout_17->addWidget(comboBox_ResPlo_Cells_Att_Hist_Att, 0, 0, 1, 1);

        lineResPlo_Cells_Att_Hist = new QFrame(page_ResPlo_Cells_Att_Hist);
        lineResPlo_Cells_Att_Hist->setObjectName(QString::fromUtf8("lineResPlo_Cells_Att_Hist"));
        lineResPlo_Cells_Att_Hist->setFrameShape(QFrame::VLine);
        lineResPlo_Cells_Att_Hist->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(lineResPlo_Cells_Att_Hist, 0, 1, 1, 1);

        label_ResPlo_Cells_Att_Hist_Classes = new QLabel(page_ResPlo_Cells_Att_Hist);
        label_ResPlo_Cells_Att_Hist_Classes->setObjectName(QString::fromUtf8("label_ResPlo_Cells_Att_Hist_Classes"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_ResPlo_Cells_Att_Hist_Classes->sizePolicy().hasHeightForWidth());
        label_ResPlo_Cells_Att_Hist_Classes->setSizePolicy(sizePolicy2);

        gridLayout_17->addWidget(label_ResPlo_Cells_Att_Hist_Classes, 0, 2, 1, 1);

        spinBox_ResPlo_Cells_Att_Hist_Classes = new QSpinBox(page_ResPlo_Cells_Att_Hist);
        spinBox_ResPlo_Cells_Att_Hist_Classes->setObjectName(QString::fromUtf8("spinBox_ResPlo_Cells_Att_Hist_Classes"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spinBox_ResPlo_Cells_Att_Hist_Classes->sizePolicy().hasHeightForWidth());
        spinBox_ResPlo_Cells_Att_Hist_Classes->setSizePolicy(sizePolicy3);
        spinBox_ResPlo_Cells_Att_Hist_Classes->setMinimum(1);
        spinBox_ResPlo_Cells_Att_Hist_Classes->setMaximum(10000);
        spinBox_ResPlo_Cells_Att_Hist_Classes->setSingleStep(5);
        spinBox_ResPlo_Cells_Att_Hist_Classes->setValue(100);

        gridLayout_17->addWidget(spinBox_ResPlo_Cells_Att_Hist_Classes, 0, 3, 1, 1);

        checkBox_ResPlo_Cells_Att_Hist_Uni = new QCheckBox(page_ResPlo_Cells_Att_Hist);
        checkBox_ResPlo_Cells_Att_Hist_Uni->setObjectName(QString::fromUtf8("checkBox_ResPlo_Cells_Att_Hist_Uni"));
        sizePolicy3.setHeightForWidth(checkBox_ResPlo_Cells_Att_Hist_Uni->sizePolicy().hasHeightForWidth());
        checkBox_ResPlo_Cells_Att_Hist_Uni->setSizePolicy(sizePolicy3);
        checkBox_ResPlo_Cells_Att_Hist_Uni->setChecked(true);

        gridLayout_17->addWidget(checkBox_ResPlo_Cells_Att_Hist_Uni, 0, 4, 1, 1);

        checkBox_ResPlo_Cells_Att_Hist_Acc = new QCheckBox(page_ResPlo_Cells_Att_Hist);
        checkBox_ResPlo_Cells_Att_Hist_Acc->setObjectName(QString::fromUtf8("checkBox_ResPlo_Cells_Att_Hist_Acc"));
        sizePolicy3.setHeightForWidth(checkBox_ResPlo_Cells_Att_Hist_Acc->sizePolicy().hasHeightForWidth());
        checkBox_ResPlo_Cells_Att_Hist_Acc->setSizePolicy(sizePolicy3);
        checkBox_ResPlo_Cells_Att_Hist_Acc->setChecked(true);

        gridLayout_17->addWidget(checkBox_ResPlo_Cells_Att_Hist_Acc, 0, 5, 1, 1);

        stackedWidget_ResPlo_Cells->addWidget(page_ResPlo_Cells_Att_Hist);
        page_ResPlo_Cells_Att_Scatter = new QWidget();
        page_ResPlo_Cells_Att_Scatter->setObjectName(QString::fromUtf8("page_ResPlo_Cells_Att_Scatter"));
        gridLayout_18 = new QGridLayout(page_ResPlo_Cells_Att_Scatter);
        gridLayout_18->setSpacing(3);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        comboBox_ResPlo_Cells_Att_Scatter_Att_X = new QComboBox(page_ResPlo_Cells_Att_Scatter);
        comboBox_ResPlo_Cells_Att_Scatter_Att_X->setObjectName(QString::fromUtf8("comboBox_ResPlo_Cells_Att_Scatter_Att_X"));

        gridLayout_18->addWidget(comboBox_ResPlo_Cells_Att_Scatter_Att_X, 0, 0, 1, 1);

        comboBox_ResPlo_Cells_Att_Scatter_Att_Y = new QComboBox(page_ResPlo_Cells_Att_Scatter);
        comboBox_ResPlo_Cells_Att_Scatter_Att_Y->setObjectName(QString::fromUtf8("comboBox_ResPlo_Cells_Att_Scatter_Att_Y"));

        gridLayout_18->addWidget(comboBox_ResPlo_Cells_Att_Scatter_Att_Y, 0, 1, 1, 1);

        stackedWidget_ResPlo_Cells->addWidget(page_ResPlo_Cells_Att_Scatter);

        gridLayout_10->addWidget(stackedWidget_ResPlo_Cells, 1, 0, 1, 1);

        gridLayout_ResPlo_Cells = new QGridLayout();
        gridLayout_ResPlo_Cells->setObjectName(QString::fromUtf8("gridLayout_ResPlo_Cells"));

        gridLayout_10->addLayout(gridLayout_ResPlo_Cells, 2, 0, 2, 1);

        tabWidget_View_Results->addTab(tab_ResPlo_Cells, QString());
        tab_ResTab_Cells = new QWidget();
        tab_ResTab_Cells->setObjectName(QString::fromUtf8("tab_ResTab_Cells"));
        gridLayout_19 = new QGridLayout(tab_ResTab_Cells);
        gridLayout_19->setSpacing(6);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setContentsMargins(9, 9, 9, 9);
        tableWidget_Cells = new QTableWidget(tab_ResTab_Cells);
        tableWidget_Cells->setObjectName(QString::fromUtf8("tableWidget_Cells"));

        gridLayout_19->addWidget(tableWidget_Cells, 1, 0, 1, 1);

        comboBox_TabCell_Type = new QComboBox(tab_ResTab_Cells);
        comboBox_TabCell_Type->setObjectName(QString::fromUtf8("comboBox_TabCell_Type"));

        gridLayout_19->addWidget(comboBox_TabCell_Type, 0, 0, 1, 1);

        tabWidget_View_Results->addTab(tab_ResTab_Cells, QString());
        tab_ResPlo_Image = new QWidget();
        tab_ResPlo_Image->setObjectName(QString::fromUtf8("tab_ResPlo_Image"));
        gridLayout_11 = new QGridLayout(tab_ResPlo_Image);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_ResPlo_Image = new QGridLayout();
        gridLayout_ResPlo_Image->setObjectName(QString::fromUtf8("gridLayout_ResPlo_Image"));

        gridLayout_11->addLayout(gridLayout_ResPlo_Image, 2, 0, 1, 1);

        comboBox_ResPlo_Img_Type = new QComboBox(tab_ResPlo_Image);
        comboBox_ResPlo_Img_Type->setObjectName(QString::fromUtf8("comboBox_ResPlo_Img_Type"));

        gridLayout_11->addWidget(comboBox_ResPlo_Img_Type, 0, 0, 1, 1);

        stackedWidget_ResPlo_Img = new QStackedWidget(tab_ResPlo_Image);
        stackedWidget_ResPlo_Img->setObjectName(QString::fromUtf8("stackedWidget_ResPlo_Img"));
        stackedWidget_ResPlo_Img->setMaximumSize(QSize(16777215, 20));
        page_ResPlo_Img_Att = new QWidget();
        page_ResPlo_Img_Att->setObjectName(QString::fromUtf8("page_ResPlo_Img_Att"));
        gridLayout_21 = new QGridLayout(page_ResPlo_Img_Att);
        gridLayout_21->setSpacing(3);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        gridLayout_21->setContentsMargins(0, 0, 0, 0);
        comboBox_ResPlo_Img_Att_Att = new QComboBox(page_ResPlo_Img_Att);
        comboBox_ResPlo_Img_Att_Att->setObjectName(QString::fromUtf8("comboBox_ResPlo_Img_Att_Att"));

        gridLayout_21->addWidget(comboBox_ResPlo_Img_Att_Att, 0, 0, 1, 1);

        stackedWidget_ResPlo_Img->addWidget(page_ResPlo_Img_Att);
        page_ResPlo_Img_Att_Hist = new QWidget();
        page_ResPlo_Img_Att_Hist->setObjectName(QString::fromUtf8("page_ResPlo_Img_Att_Hist"));
        gridLayout_22 = new QGridLayout(page_ResPlo_Img_Att_Hist);
        gridLayout_22->setSpacing(3);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        gridLayout_22->setContentsMargins(0, 0, 0, 0);
        comboBox_ResPlo_Img_Att_Hist_Att = new QComboBox(page_ResPlo_Img_Att_Hist);
        comboBox_ResPlo_Img_Att_Hist_Att->setObjectName(QString::fromUtf8("comboBox_ResPlo_Img_Att_Hist_Att"));

        gridLayout_22->addWidget(comboBox_ResPlo_Img_Att_Hist_Att, 0, 0, 1, 1);

        line_ResPlo_Img_Att_Hist = new QFrame(page_ResPlo_Img_Att_Hist);
        line_ResPlo_Img_Att_Hist->setObjectName(QString::fromUtf8("line_ResPlo_Img_Att_Hist"));
        line_ResPlo_Img_Att_Hist->setFrameShape(QFrame::VLine);
        line_ResPlo_Img_Att_Hist->setFrameShadow(QFrame::Sunken);

        gridLayout_22->addWidget(line_ResPlo_Img_Att_Hist, 0, 1, 1, 1);

        label_ResPlo_Img_Att_Hist_Classes = new QLabel(page_ResPlo_Img_Att_Hist);
        label_ResPlo_Img_Att_Hist_Classes->setObjectName(QString::fromUtf8("label_ResPlo_Img_Att_Hist_Classes"));
        sizePolicy2.setHeightForWidth(label_ResPlo_Img_Att_Hist_Classes->sizePolicy().hasHeightForWidth());
        label_ResPlo_Img_Att_Hist_Classes->setSizePolicy(sizePolicy2);

        gridLayout_22->addWidget(label_ResPlo_Img_Att_Hist_Classes, 0, 2, 1, 1);

        spinBox_ResPlo_Img_Att_Hist_Classes = new QSpinBox(page_ResPlo_Img_Att_Hist);
        spinBox_ResPlo_Img_Att_Hist_Classes->setObjectName(QString::fromUtf8("spinBox_ResPlo_Img_Att_Hist_Classes"));
        sizePolicy3.setHeightForWidth(spinBox_ResPlo_Img_Att_Hist_Classes->sizePolicy().hasHeightForWidth());
        spinBox_ResPlo_Img_Att_Hist_Classes->setSizePolicy(sizePolicy3);
        spinBox_ResPlo_Img_Att_Hist_Classes->setMinimum(1);
        spinBox_ResPlo_Img_Att_Hist_Classes->setMaximum(10000);
        spinBox_ResPlo_Img_Att_Hist_Classes->setSingleStep(5);
        spinBox_ResPlo_Img_Att_Hist_Classes->setValue(100);

        gridLayout_22->addWidget(spinBox_ResPlo_Img_Att_Hist_Classes, 0, 3, 1, 1);

        checkBox_ResPlo_Img_Att_Hist_Uni = new QCheckBox(page_ResPlo_Img_Att_Hist);
        checkBox_ResPlo_Img_Att_Hist_Uni->setObjectName(QString::fromUtf8("checkBox_ResPlo_Img_Att_Hist_Uni"));
        sizePolicy3.setHeightForWidth(checkBox_ResPlo_Img_Att_Hist_Uni->sizePolicy().hasHeightForWidth());
        checkBox_ResPlo_Img_Att_Hist_Uni->setSizePolicy(sizePolicy3);
        checkBox_ResPlo_Img_Att_Hist_Uni->setChecked(true);

        gridLayout_22->addWidget(checkBox_ResPlo_Img_Att_Hist_Uni, 0, 4, 1, 1);

        checkBox_ResPlo_Img_Att_Hist_Acc = new QCheckBox(page_ResPlo_Img_Att_Hist);
        checkBox_ResPlo_Img_Att_Hist_Acc->setObjectName(QString::fromUtf8("checkBox_ResPlo_Img_Att_Hist_Acc"));
        sizePolicy3.setHeightForWidth(checkBox_ResPlo_Img_Att_Hist_Acc->sizePolicy().hasHeightForWidth());
        checkBox_ResPlo_Img_Att_Hist_Acc->setSizePolicy(sizePolicy3);
        checkBox_ResPlo_Img_Att_Hist_Acc->setChecked(true);

        gridLayout_22->addWidget(checkBox_ResPlo_Img_Att_Hist_Acc, 0, 5, 1, 1);

        stackedWidget_ResPlo_Img->addWidget(page_ResPlo_Img_Att_Hist);
        page_ResPlo_Img_Att_Scatter = new QWidget();
        page_ResPlo_Img_Att_Scatter->setObjectName(QString::fromUtf8("page_ResPlo_Img_Att_Scatter"));
        gridLayout_23 = new QGridLayout(page_ResPlo_Img_Att_Scatter);
        gridLayout_23->setSpacing(3);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        gridLayout_23->setContentsMargins(0, 0, 0, 0);
        comboBox_ResPlo_Img_Att_Scatter_Att_X = new QComboBox(page_ResPlo_Img_Att_Scatter);
        comboBox_ResPlo_Img_Att_Scatter_Att_X->setObjectName(QString::fromUtf8("comboBox_ResPlo_Img_Att_Scatter_Att_X"));

        gridLayout_23->addWidget(comboBox_ResPlo_Img_Att_Scatter_Att_X, 0, 0, 1, 1);

        comboBox_ResPlo_Img_Att_Scatter_Att_Y = new QComboBox(page_ResPlo_Img_Att_Scatter);
        comboBox_ResPlo_Img_Att_Scatter_Att_Y->setObjectName(QString::fromUtf8("comboBox_ResPlo_Img_Att_Scatter_Att_Y"));

        gridLayout_23->addWidget(comboBox_ResPlo_Img_Att_Scatter_Att_Y, 0, 1, 1, 1);

        stackedWidget_ResPlo_Img->addWidget(page_ResPlo_Img_Att_Scatter);

        gridLayout_11->addWidget(stackedWidget_ResPlo_Img, 1, 0, 1, 1);

        tabWidget_View_Results->addTab(tab_ResPlo_Image, QString());
        tab_ResTab_Image = new QWidget();
        tab_ResTab_Image->setObjectName(QString::fromUtf8("tab_ResTab_Image"));
        gridLayout_20 = new QGridLayout(tab_ResTab_Image);
        gridLayout_20->setSpacing(6);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        gridLayout_20->setContentsMargins(9, 9, 9, 9);
        tableWidget_Image = new QTableWidget(tab_ResTab_Image);
        tableWidget_Image->setObjectName(QString::fromUtf8("tableWidget_Image"));

        gridLayout_20->addWidget(tableWidget_Image, 1, 0, 1, 1);

        comboBox_TabImg_Type = new QComboBox(tab_ResTab_Image);
        comboBox_TabImg_Type->setObjectName(QString::fromUtf8("comboBox_TabImg_Type"));

        gridLayout_20->addWidget(comboBox_TabImg_Type, 0, 0, 1, 1);

        tabWidget_View_Results->addTab(tab_ResTab_Image, QString());

        gridLayout_4->addWidget(tabWidget_View_Results, 0, 0, 1, 1);


        gridLayout_Viewer->addWidget(groupBox_View_Result, 1, 1, 1, 1);

        groupBox_View_Cyto = new QGroupBox(centralwidget);
        groupBox_View_Cyto->setObjectName(QString::fromUtf8("groupBox_View_Cyto"));
        sizePolicy.setHeightForWidth(groupBox_View_Cyto->sizePolicy().hasHeightForWidth());
        groupBox_View_Cyto->setSizePolicy(sizePolicy);
        groupBox_View_Cyto->setMinimumSize(QSize(375, 0));
        gridLayout_9 = new QGridLayout(groupBox_View_Cyto);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        comboBox_View_Cyto = new QComboBox(groupBox_View_Cyto);
        comboBox_View_Cyto->addItem(QString());
        comboBox_View_Cyto->addItem(QString());
        comboBox_View_Cyto->addItem(QString());
        comboBox_View_Cyto->addItem(QString());
        comboBox_View_Cyto->addItem(QString());
        comboBox_View_Cyto->addItem(QString());
        comboBox_View_Cyto->addItem(QString());
        comboBox_View_Cyto->addItem(QString());
        comboBox_View_Cyto->addItem(QString());
        comboBox_View_Cyto->setObjectName(QString::fromUtf8("comboBox_View_Cyto"));

        gridLayout_9->addWidget(comboBox_View_Cyto, 0, 0, 1, 1);

        label_View_Cyto_Format_QI = new QLabel(groupBox_View_Cyto);
        label_View_Cyto_Format_QI->setObjectName(QString::fromUtf8("label_View_Cyto_Format_QI"));
        label_View_Cyto_Format_QI->setMaximumSize(QSize(65, 16777215));

        gridLayout_9->addWidget(label_View_Cyto_Format_QI, 0, 1, 1, 1);

        label_View_Cyto_Format_MA = new QLabel(groupBox_View_Cyto);
        label_View_Cyto_Format_MA->setObjectName(QString::fromUtf8("label_View_Cyto_Format_MA"));
        label_View_Cyto_Format_MA->setMaximumSize(QSize(65, 16777215));

        gridLayout_9->addWidget(label_View_Cyto_Format_MA, 0, 2, 1, 1);

        graphicsView_Cyto = new QGraphicsView(groupBox_View_Cyto);
        graphicsView_Cyto->setObjectName(QString::fromUtf8("graphicsView_Cyto"));
        graphicsView_Cyto->setMouseTracking(true);

        gridLayout_9->addWidget(graphicsView_Cyto, 1, 0, 1, 3);


        gridLayout_Viewer->addWidget(groupBox_View_Cyto, 0, 1, 1, 1);

        groupBox_View_Cores = new QGroupBox(centralwidget);
        groupBox_View_Cores->setObjectName(QString::fromUtf8("groupBox_View_Cores"));
        sizePolicy.setHeightForWidth(groupBox_View_Cores->sizePolicy().hasHeightForWidth());
        groupBox_View_Cores->setSizePolicy(sizePolicy);
        groupBox_View_Cores->setMinimumSize(QSize(375, 0));
        gridLayout_2 = new QGridLayout(groupBox_View_Cores);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphicsView_Cores = new QGraphicsView(groupBox_View_Cores);
        graphicsView_Cores->setObjectName(QString::fromUtf8("graphicsView_Cores"));
        graphicsView_Cores->setMouseTracking(true);

        gridLayout_2->addWidget(graphicsView_Cores, 1, 0, 1, 3);

        comboBox_View_Cores = new QComboBox(groupBox_View_Cores);
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->addItem(QString());
        comboBox_View_Cores->setObjectName(QString::fromUtf8("comboBox_View_Cores"));

        gridLayout_2->addWidget(comboBox_View_Cores, 0, 0, 1, 1);

        label_View_Cores_QI_Format = new QLabel(groupBox_View_Cores);
        label_View_Cores_QI_Format->setObjectName(QString::fromUtf8("label_View_Cores_QI_Format"));
        label_View_Cores_QI_Format->setMaximumSize(QSize(65, 16777215));

        gridLayout_2->addWidget(label_View_Cores_QI_Format, 0, 1, 1, 1);

        label_View_Cores_MA_Format = new QLabel(groupBox_View_Cores);
        label_View_Cores_MA_Format->setObjectName(QString::fromUtf8("label_View_Cores_MA_Format"));
        label_View_Cores_MA_Format->setMaximumSize(QSize(65, 16777215));

        gridLayout_2->addWidget(label_View_Cores_MA_Format, 0, 2, 1, 1);


        gridLayout_Viewer->addWidget(groupBox_View_Cores, 0, 0, 1, 1);

        groupBox_View_Foci = new QGroupBox(centralwidget);
        groupBox_View_Foci->setObjectName(QString::fromUtf8("groupBox_View_Foci"));
        sizePolicy.setHeightForWidth(groupBox_View_Foci->sizePolicy().hasHeightForWidth());
        groupBox_View_Foci->setSizePolicy(sizePolicy);
        groupBox_View_Foci->setMinimumSize(QSize(375, 0));
        gridLayout_3 = new QGridLayout(groupBox_View_Foci);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        comboBox_View_Foci = new QComboBox(groupBox_View_Foci);
        comboBox_View_Foci->addItem(QString());
        comboBox_View_Foci->addItem(QString());
        comboBox_View_Foci->addItem(QString());
        comboBox_View_Foci->addItem(QString());
        comboBox_View_Foci->addItem(QString());
        comboBox_View_Foci->addItem(QString());
        comboBox_View_Foci->addItem(QString());
        comboBox_View_Foci->addItem(QString());
        comboBox_View_Foci->addItem(QString());
        comboBox_View_Foci->addItem(QString());
        comboBox_View_Foci->addItem(QString());
        comboBox_View_Foci->addItem(QString());
        comboBox_View_Foci->addItem(QString());
        comboBox_View_Foci->addItem(QString());
        comboBox_View_Foci->addItem(QString());
        comboBox_View_Foci->setObjectName(QString::fromUtf8("comboBox_View_Foci"));

        gridLayout_3->addWidget(comboBox_View_Foci, 0, 0, 1, 1);

        label_View_Foci_QI_Format = new QLabel(groupBox_View_Foci);
        label_View_Foci_QI_Format->setObjectName(QString::fromUtf8("label_View_Foci_QI_Format"));
        label_View_Foci_QI_Format->setMaximumSize(QSize(65, 16777215));

        gridLayout_3->addWidget(label_View_Foci_QI_Format, 0, 1, 1, 1);

        label_View_Foci_MA_Format = new QLabel(groupBox_View_Foci);
        label_View_Foci_MA_Format->setObjectName(QString::fromUtf8("label_View_Foci_MA_Format"));
        label_View_Foci_MA_Format->setMaximumSize(QSize(65, 16777215));

        gridLayout_3->addWidget(label_View_Foci_MA_Format, 0, 2, 1, 1);

        graphicsView_Foci = new QGraphicsView(groupBox_View_Foci);
        graphicsView_Foci->setObjectName(QString::fromUtf8("graphicsView_Foci"));
        graphicsView_Foci->setMouseTracking(true);

        gridLayout_3->addWidget(graphicsView_Foci, 1, 0, 1, 3);


        gridLayout_Viewer->addWidget(groupBox_View_Foci, 1, 0, 1, 1);


        gridLayout_12->addLayout(gridLayout_Viewer, 0, 0, 1, 1);

        groupBox_Settings = new QGroupBox(centralwidget);
        groupBox_Settings->setObjectName(QString::fromUtf8("groupBox_Settings"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(groupBox_Settings->sizePolicy().hasHeightForWidth());
        groupBox_Settings->setSizePolicy(sizePolicy4);
        groupBox_Settings->setMinimumSize(QSize(480, 0));
        groupBox_Settings->setMaximumSize(QSize(480, 16777215));
        gridLayout_13 = new QGridLayout(groupBox_Settings);
        gridLayout_13->setSpacing(3);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(6, 6, 6, 6);
        tabWidget = new QTabWidget(groupBox_Settings);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setMaximumSize(QSize(16777215, 600));
        tab_InputDefinition = new QWidget();
        tab_InputDefinition->setObjectName(QString::fromUtf8("tab_InputDefinition"));
        gridLayout_35 = new QGridLayout(tab_InputDefinition);
        gridLayout_35->setObjectName(QString::fromUtf8("gridLayout_35"));
        groupBox_MikroPreset = new QGroupBox(tab_InputDefinition);
        groupBox_MikroPreset->setObjectName(QString::fromUtf8("groupBox_MikroPreset"));
        gridLayout_34 = new QGridLayout(groupBox_MikroPreset);
        gridLayout_34->setObjectName(QString::fromUtf8("gridLayout_34"));
        comboBox_Preset = new QComboBox(groupBox_MikroPreset);
        comboBox_Preset->setObjectName(QString::fromUtf8("comboBox_Preset"));

        gridLayout_34->addWidget(comboBox_Preset, 0, 0, 1, 1);

        pushButton_PresetActivate = new QPushButton(groupBox_MikroPreset);
        pushButton_PresetActivate->setObjectName(QString::fromUtf8("pushButton_PresetActivate"));

        gridLayout_34->addWidget(pushButton_PresetActivate, 1, 0, 1, 1);


        gridLayout_35->addWidget(groupBox_MikroPreset, 0, 0, 1, 1);

        groupBox_PageIndex = new QGroupBox(tab_InputDefinition);
        groupBox_PageIndex->setObjectName(QString::fromUtf8("groupBox_PageIndex"));
        gridLayout_36 = new QGridLayout(groupBox_PageIndex);
        gridLayout_36->setObjectName(QString::fromUtf8("gridLayout_36"));
        label_37 = new QLabel(groupBox_PageIndex);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy5);

        gridLayout_36->addWidget(label_37, 0, 0, 1, 1);

        label_38 = new QLabel(groupBox_PageIndex);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        sizePolicy5.setHeightForWidth(label_38->sizePolicy().hasHeightForWidth());
        label_38->setSizePolicy(sizePolicy5);

        gridLayout_36->addWidget(label_38, 0, 1, 1, 1);

        label_39 = new QLabel(groupBox_PageIndex);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        sizePolicy5.setHeightForWidth(label_39->sizePolicy().hasHeightForWidth());
        label_39->setSizePolicy(sizePolicy5);

        gridLayout_36->addWidget(label_39, 0, 2, 1, 1);

        spinBox_IndexNuclei = new QSpinBox(groupBox_PageIndex);
        spinBox_IndexNuclei->setObjectName(QString::fromUtf8("spinBox_IndexNuclei"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(spinBox_IndexNuclei->sizePolicy().hasHeightForWidth());
        spinBox_IndexNuclei->setSizePolicy(sizePolicy6);
        spinBox_IndexNuclei->setMinimum(1);
        spinBox_IndexNuclei->setMaximum(999);

        gridLayout_36->addWidget(spinBox_IndexNuclei, 1, 0, 1, 1);

        spinBox_IndexFoci = new QSpinBox(groupBox_PageIndex);
        spinBox_IndexFoci->setObjectName(QString::fromUtf8("spinBox_IndexFoci"));
        sizePolicy6.setHeightForWidth(spinBox_IndexFoci->sizePolicy().hasHeightForWidth());
        spinBox_IndexFoci->setSizePolicy(sizePolicy6);
        spinBox_IndexFoci->setMinimum(1);
        spinBox_IndexFoci->setMaximum(999);
        spinBox_IndexFoci->setValue(2);

        gridLayout_36->addWidget(spinBox_IndexFoci, 1, 1, 1, 1);

        spinBox_IndexCytoplasm = new QSpinBox(groupBox_PageIndex);
        spinBox_IndexCytoplasm->setObjectName(QString::fromUtf8("spinBox_IndexCytoplasm"));
        sizePolicy6.setHeightForWidth(spinBox_IndexCytoplasm->sizePolicy().hasHeightForWidth());
        spinBox_IndexCytoplasm->setSizePolicy(sizePolicy6);
        spinBox_IndexCytoplasm->setMinimum(1);
        spinBox_IndexCytoplasm->setMaximum(999);
        spinBox_IndexCytoplasm->setValue(3);

        gridLayout_36->addWidget(spinBox_IndexCytoplasm, 1, 2, 1, 1);


        gridLayout_35->addWidget(groupBox_PageIndex, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 367, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_35->addItem(verticalSpacer, 2, 0, 1, 1);

        tabWidget->addTab(tab_InputDefinition, QString());
        tab_Settings = new QWidget();
        tab_Settings->setObjectName(QString::fromUtf8("tab_Settings"));
        gridLayout_24 = new QGridLayout(tab_Settings);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        groupBox_File = new QGroupBox(tab_Settings);
        groupBox_File->setObjectName(QString::fromUtf8("groupBox_File"));
        sizePolicy5.setHeightForWidth(groupBox_File->sizePolicy().hasHeightForWidth());
        groupBox_File->setSizePolicy(sizePolicy5);
        groupBox_File->setMinimumSize(QSize(0, 0));
        groupBox_File->setMaximumSize(QSize(466, 16777215));
        groupBox_File->setFlat(true);
        gridLayout_15 = new QGridLayout(groupBox_File);
        gridLayout_15->setSpacing(3);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(9, 0, 0, 0);
        comboBox_FileName = new QComboBox(groupBox_File);
        comboBox_FileName->setObjectName(QString::fromUtf8("comboBox_FileName"));

        gridLayout_15->addWidget(comboBox_FileName, 0, 0, 1, 2);


        gridLayout_24->addWidget(groupBox_File, 0, 0, 1, 1);

        groupBox_Settings_Foci = new QGroupBox(tab_Settings);
        groupBox_Settings_Foci->setObjectName(QString::fromUtf8("groupBox_Settings_Foci"));
        sizePolicy5.setHeightForWidth(groupBox_Settings_Foci->sizePolicy().hasHeightForWidth());
        groupBox_Settings_Foci->setSizePolicy(sizePolicy5);
        groupBox_Settings_Foci->setMinimumSize(QSize(0, 0));
        groupBox_Settings_Foci->setMaximumSize(QSize(466, 16777215));
        groupBox_Settings_Foci->setFlat(true);
        gridLayout_7 = new QGridLayout(groupBox_Settings_Foci);
        gridLayout_7->setSpacing(3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(9, 0, 0, 0);
        label_7 = new QLabel(groupBox_Settings_Foci);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_7->addWidget(label_7, 1, 4, 1, 1);

        label_6 = new QLabel(groupBox_Settings_Foci);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(75, 0));
        label_6->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_6, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox_Settings_Foci);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setMinimumSize(QSize(15, 0));
        label_4->setMaximumSize(QSize(15, 16777215));

        gridLayout_7->addWidget(label_4, 1, 0, 1, 1);

        doubleSpinBox_SetFoci_02_Sigma = new QDoubleSpinBox(groupBox_Settings_Foci);
        doubleSpinBox_SetFoci_02_Sigma->setObjectName(QString::fromUtf8("doubleSpinBox_SetFoci_02_Sigma"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(doubleSpinBox_SetFoci_02_Sigma->sizePolicy().hasHeightForWidth());
        doubleSpinBox_SetFoci_02_Sigma->setSizePolicy(sizePolicy7);
        doubleSpinBox_SetFoci_02_Sigma->setMinimumSize(QSize(65, 0));
        doubleSpinBox_SetFoci_02_Sigma->setMaximumSize(QSize(65, 16777215));
        doubleSpinBox_SetFoci_02_Sigma->setMaximum(10000.000000000000000);
        doubleSpinBox_SetFoci_02_Sigma->setValue(6.000000000000000);

        gridLayout_7->addWidget(doubleSpinBox_SetFoci_02_Sigma, 0, 3, 1, 1);

        label_3 = new QLabel(groupBox_Settings_Foci);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_7->addWidget(label_3, 0, 4, 1, 1);

        spinBox_SetFoci_02_Size = new QSpinBox(groupBox_Settings_Foci);
        spinBox_SetFoci_02_Size->setObjectName(QString::fromUtf8("spinBox_SetFoci_02_Size"));
        sizePolicy7.setHeightForWidth(spinBox_SetFoci_02_Size->sizePolicy().hasHeightForWidth());
        spinBox_SetFoci_02_Size->setSizePolicy(sizePolicy7);
        spinBox_SetFoci_02_Size->setMinimumSize(QSize(65, 19));
        spinBox_SetFoci_02_Size->setMaximumSize(QSize(65, 20));
        spinBox_SetFoci_02_Size->setMinimum(1);
        spinBox_SetFoci_02_Size->setMaximum(10000);
        spinBox_SetFoci_02_Size->setSingleStep(2);
        spinBox_SetFoci_02_Size->setValue(13);

        gridLayout_7->addWidget(spinBox_SetFoci_02_Size, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox_Settings_Foci);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(75, 0));
        label_2->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_2, 0, 1, 1, 1);

        label = new QLabel(groupBox_Settings_Foci);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(15, 0));
        label->setMaximumSize(QSize(15, 16777215));

        gridLayout_7->addWidget(label, 0, 0, 1, 1);

        spinBox_SetFoci_03_Size = new QSpinBox(groupBox_Settings_Foci);
        spinBox_SetFoci_03_Size->setObjectName(QString::fromUtf8("spinBox_SetFoci_03_Size"));
        sizePolicy7.setHeightForWidth(spinBox_SetFoci_03_Size->sizePolicy().hasHeightForWidth());
        spinBox_SetFoci_03_Size->setSizePolicy(sizePolicy7);
        spinBox_SetFoci_03_Size->setMinimumSize(QSize(65, 19));
        spinBox_SetFoci_03_Size->setMaximumSize(QSize(65, 20));
        spinBox_SetFoci_03_Size->setMinimum(3);
        spinBox_SetFoci_03_Size->setMaximum(10000);
        spinBox_SetFoci_03_Size->setSingleStep(2);
        spinBox_SetFoci_03_Size->setValue(63);

        gridLayout_7->addWidget(spinBox_SetFoci_03_Size, 1, 2, 1, 1);

        doubleSpinBox_SetFoci_03_Offset = new QDoubleSpinBox(groupBox_Settings_Foci);
        doubleSpinBox_SetFoci_03_Offset->setObjectName(QString::fromUtf8("doubleSpinBox_SetFoci_03_Offset"));
        sizePolicy7.setHeightForWidth(doubleSpinBox_SetFoci_03_Offset->sizePolicy().hasHeightForWidth());
        doubleSpinBox_SetFoci_03_Offset->setSizePolicy(sizePolicy7);
        doubleSpinBox_SetFoci_03_Offset->setMinimumSize(QSize(65, 0));
        doubleSpinBox_SetFoci_03_Offset->setMaximumSize(QSize(65, 16777215));
        doubleSpinBox_SetFoci_03_Offset->setMinimum(-256.000000000000000);
        doubleSpinBox_SetFoci_03_Offset->setMaximum(0.000000000000000);
        doubleSpinBox_SetFoci_03_Offset->setValue(-13.000000000000000);

        gridLayout_7->addWidget(doubleSpinBox_SetFoci_03_Offset, 1, 3, 1, 1);

        label_8 = new QLabel(groupBox_Settings_Foci);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(75, 0));
        label_8->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_8, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox_Settings_Foci);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_7->addWidget(label_9, 2, 4, 1, 1);

        spinBox_SetFoci_04_Size = new QSpinBox(groupBox_Settings_Foci);
        spinBox_SetFoci_04_Size->setObjectName(QString::fromUtf8("spinBox_SetFoci_04_Size"));
        spinBox_SetFoci_04_Size->setMinimumSize(QSize(133, 19));
        spinBox_SetFoci_04_Size->setMaximumSize(QSize(133, 20));
        spinBox_SetFoci_04_Size->setMinimum(1);
        spinBox_SetFoci_04_Size->setMaximum(100000);
        spinBox_SetFoci_04_Size->setSingleStep(2);
        spinBox_SetFoci_04_Size->setValue(25);

        gridLayout_7->addWidget(spinBox_SetFoci_04_Size, 2, 2, 1, 2);

        label_5 = new QLabel(groupBox_Settings_Foci);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setMinimumSize(QSize(15, 0));
        label_5->setMaximumSize(QSize(15, 16777215));

        gridLayout_7->addWidget(label_5, 2, 0, 1, 1);

        label_13 = new QLabel(groupBox_Settings_Foci);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy2.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy2);
        label_13->setMinimumSize(QSize(15, 0));
        label_13->setMaximumSize(QSize(15, 16777215));

        gridLayout_7->addWidget(label_13, 3, 0, 1, 1);

        label_14 = new QLabel(groupBox_Settings_Foci);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(75, 0));
        label_14->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_14, 3, 1, 1, 1);

        label_15 = new QLabel(groupBox_Settings_Foci);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_7->addWidget(label_15, 3, 4, 1, 1);

        spinBox_SetFoci_05_Size = new QSpinBox(groupBox_Settings_Foci);
        spinBox_SetFoci_05_Size->setObjectName(QString::fromUtf8("spinBox_SetFoci_05_Size"));
        spinBox_SetFoci_05_Size->setMinimumSize(QSize(133, 19));
        spinBox_SetFoci_05_Size->setMaximumSize(QSize(133, 20));
        spinBox_SetFoci_05_Size->setMinimum(1);
        spinBox_SetFoci_05_Size->setMaximum(100000);
        spinBox_SetFoci_05_Size->setSingleStep(2);
        spinBox_SetFoci_05_Size->setValue(3);

        gridLayout_7->addWidget(spinBox_SetFoci_05_Size, 3, 2, 1, 2);

        label_16 = new QLabel(groupBox_Settings_Foci);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy2.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy2);
        label_16->setMinimumSize(QSize(15, 0));
        label_16->setMaximumSize(QSize(15, 16777215));

        gridLayout_7->addWidget(label_16, 4, 0, 1, 1);

        label_17 = new QLabel(groupBox_Settings_Foci);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(75, 0));
        label_17->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_17, 4, 1, 1, 1);

        label_18 = new QLabel(groupBox_Settings_Foci);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_7->addWidget(label_18, 4, 4, 1, 1);

        spinBox_SetFoci_06_Size_Min = new QSpinBox(groupBox_Settings_Foci);
        spinBox_SetFoci_06_Size_Min->setObjectName(QString::fromUtf8("spinBox_SetFoci_06_Size_Min"));
        sizePolicy7.setHeightForWidth(spinBox_SetFoci_06_Size_Min->sizePolicy().hasHeightForWidth());
        spinBox_SetFoci_06_Size_Min->setSizePolicy(sizePolicy7);
        spinBox_SetFoci_06_Size_Min->setMinimumSize(QSize(65, 19));
        spinBox_SetFoci_06_Size_Min->setMaximumSize(QSize(65, 20));
        spinBox_SetFoci_06_Size_Min->setMaximum(1000000000);
        spinBox_SetFoci_06_Size_Min->setSingleStep(5);
        spinBox_SetFoci_06_Size_Min->setValue(5);

        gridLayout_7->addWidget(spinBox_SetFoci_06_Size_Min, 4, 2, 1, 1);

        spinBox_SetFoci_06_Size_Max = new QSpinBox(groupBox_Settings_Foci);
        spinBox_SetFoci_06_Size_Max->setObjectName(QString::fromUtf8("spinBox_SetFoci_06_Size_Max"));
        sizePolicy7.setHeightForWidth(spinBox_SetFoci_06_Size_Max->sizePolicy().hasHeightForWidth());
        spinBox_SetFoci_06_Size_Max->setSizePolicy(sizePolicy7);
        spinBox_SetFoci_06_Size_Max->setMinimumSize(QSize(65, 0));
        spinBox_SetFoci_06_Size_Max->setMaximumSize(QSize(65, 16777215));
        spinBox_SetFoci_06_Size_Max->setMaximum(1000000000);
        spinBox_SetFoci_06_Size_Max->setSingleStep(100);
        spinBox_SetFoci_06_Size_Max->setValue(1000);

        gridLayout_7->addWidget(spinBox_SetFoci_06_Size_Max, 4, 3, 1, 1);

        label_32 = new QLabel(groupBox_Settings_Foci);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_7->addWidget(label_32, 5, 0, 1, 1);

        label_31 = new QLabel(groupBox_Settings_Foci);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_7->addWidget(label_31, 5, 1, 1, 1);

        checkBox_SetFoci_13_ExcludeBordered = new QCheckBox(groupBox_Settings_Foci);
        checkBox_SetFoci_13_ExcludeBordered->setObjectName(QString::fromUtf8("checkBox_SetFoci_13_ExcludeBordered"));
        checkBox_SetFoci_13_ExcludeBordered->setMinimumSize(QSize(0, 19));
        checkBox_SetFoci_13_ExcludeBordered->setMaximumSize(QSize(16777215, 20));
        checkBox_SetFoci_13_ExcludeBordered->setChecked(true);

        gridLayout_7->addWidget(checkBox_SetFoci_13_ExcludeBordered, 5, 2, 1, 2);

        label_33 = new QLabel(groupBox_Settings_Foci);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout_7->addWidget(label_33, 5, 4, 1, 1);


        gridLayout_24->addWidget(groupBox_Settings_Foci, 3, 0, 1, 1);

        groupBox_Settings_Cores = new QGroupBox(tab_Settings);
        groupBox_Settings_Cores->setObjectName(QString::fromUtf8("groupBox_Settings_Cores"));
        sizePolicy5.setHeightForWidth(groupBox_Settings_Cores->sizePolicy().hasHeightForWidth());
        groupBox_Settings_Cores->setSizePolicy(sizePolicy5);
        groupBox_Settings_Cores->setMinimumSize(QSize(0, 0));
        groupBox_Settings_Cores->setMaximumSize(QSize(466, 16777215));
        groupBox_Settings_Cores->setFlat(true);
        gridLayout_5 = new QGridLayout(groupBox_Settings_Cores);
        gridLayout_5->setSpacing(3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(9, 0, 0, 0);
        spinBox_SetCore_14_AreaMinOfBig = new QSpinBox(groupBox_Settings_Cores);
        spinBox_SetCore_14_AreaMinOfBig->setObjectName(QString::fromUtf8("spinBox_SetCore_14_AreaMinOfBig"));
        spinBox_SetCore_14_AreaMinOfBig->setMinimumSize(QSize(65, 0));
        spinBox_SetCore_14_AreaMinOfBig->setMaximumSize(QSize(65, 16777215));
        spinBox_SetCore_14_AreaMinOfBig->setMinimum(0);
        spinBox_SetCore_14_AreaMinOfBig->setMaximum(99999999);
        spinBox_SetCore_14_AreaMinOfBig->setSingleStep(100);
        spinBox_SetCore_14_AreaMinOfBig->setValue(4000);

        gridLayout_5->addWidget(spinBox_SetCore_14_AreaMinOfBig, 10, 3, 1, 1);

        label_SetCore_04_Thres_Desription = new QLabel(groupBox_Settings_Cores);
        label_SetCore_04_Thres_Desription->setObjectName(QString::fromUtf8("label_SetCore_04_Thres_Desription"));

        gridLayout_5->addWidget(label_SetCore_04_Thres_Desription, 1, 4, 1, 1);

        label_SetCore_05_Fill_Title = new QLabel(groupBox_Settings_Cores);
        label_SetCore_05_Fill_Title->setObjectName(QString::fromUtf8("label_SetCore_05_Fill_Title"));
        label_SetCore_05_Fill_Title->setMinimumSize(QSize(75, 0));
        label_SetCore_05_Fill_Title->setMaximumSize(QSize(75, 16777215));

        gridLayout_5->addWidget(label_SetCore_05_Fill_Title, 2, 1, 1, 1);

        label_SetCore_08_Desription = new QLabel(groupBox_Settings_Cores);
        label_SetCore_08_Desription->setObjectName(QString::fromUtf8("label_SetCore_08_Desription"));

        gridLayout_5->addWidget(label_SetCore_08_Desription, 4, 4, 1, 1);

        label_SetCore_02_Gauss_Pos = new QLabel(groupBox_Settings_Cores);
        label_SetCore_02_Gauss_Pos->setObjectName(QString::fromUtf8("label_SetCore_02_Gauss_Pos"));
        sizePolicy2.setHeightForWidth(label_SetCore_02_Gauss_Pos->sizePolicy().hasHeightForWidth());
        label_SetCore_02_Gauss_Pos->setSizePolicy(sizePolicy2);
        label_SetCore_02_Gauss_Pos->setMinimumSize(QSize(15, 0));
        label_SetCore_02_Gauss_Pos->setMaximumSize(QSize(15, 16777215));

        gridLayout_5->addWidget(label_SetCore_02_Gauss_Pos, 0, 0, 1, 1);

        label_SetCore_04_Thres_Pos = new QLabel(groupBox_Settings_Cores);
        label_SetCore_04_Thres_Pos->setObjectName(QString::fromUtf8("label_SetCore_04_Thres_Pos"));
        sizePolicy2.setHeightForWidth(label_SetCore_04_Thres_Pos->sizePolicy().hasHeightForWidth());
        label_SetCore_04_Thres_Pos->setSizePolicy(sizePolicy2);
        label_SetCore_04_Thres_Pos->setMinimumSize(QSize(15, 0));
        label_SetCore_04_Thres_Pos->setMaximumSize(QSize(15, 16777215));

        gridLayout_5->addWidget(label_SetCore_04_Thres_Pos, 1, 0, 1, 1);

        label_SetCore_02_Gauss_Title = new QLabel(groupBox_Settings_Cores);
        label_SetCore_02_Gauss_Title->setObjectName(QString::fromUtf8("label_SetCore_02_Gauss_Title"));
        label_SetCore_02_Gauss_Title->setMinimumSize(QSize(75, 0));
        label_SetCore_02_Gauss_Title->setMaximumSize(QSize(75, 16777215));

        gridLayout_5->addWidget(label_SetCore_02_Gauss_Title, 0, 1, 1, 1);

        doubleSpinBox_SetCore_02_Gauss_Sigma = new QDoubleSpinBox(groupBox_Settings_Cores);
        doubleSpinBox_SetCore_02_Gauss_Sigma->setObjectName(QString::fromUtf8("doubleSpinBox_SetCore_02_Gauss_Sigma"));
        sizePolicy7.setHeightForWidth(doubleSpinBox_SetCore_02_Gauss_Sigma->sizePolicy().hasHeightForWidth());
        doubleSpinBox_SetCore_02_Gauss_Sigma->setSizePolicy(sizePolicy7);
        doubleSpinBox_SetCore_02_Gauss_Sigma->setMinimumSize(QSize(65, 0));
        doubleSpinBox_SetCore_02_Gauss_Sigma->setMaximumSize(QSize(65, 16777215));
        doubleSpinBox_SetCore_02_Gauss_Sigma->setMaximum(100000.000000000000000);
        doubleSpinBox_SetCore_02_Gauss_Sigma->setValue(26.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_SetCore_02_Gauss_Sigma, 0, 3, 1, 1);

        label_SetCore_12_Open_Pos = new QLabel(groupBox_Settings_Cores);
        label_SetCore_12_Open_Pos->setObjectName(QString::fromUtf8("label_SetCore_12_Open_Pos"));
        sizePolicy2.setHeightForWidth(label_SetCore_12_Open_Pos->sizePolicy().hasHeightForWidth());
        label_SetCore_12_Open_Pos->setSizePolicy(sizePolicy2);
        label_SetCore_12_Open_Pos->setMinimumSize(QSize(15, 0));
        label_SetCore_12_Open_Pos->setMaximumSize(QSize(15, 16777215));

        gridLayout_5->addWidget(label_SetCore_12_Open_Pos, 6, 0, 1, 1);

        spinBox_SetCore_09_Eilenstein_Size = new QSpinBox(groupBox_Settings_Cores);
        spinBox_SetCore_09_Eilenstein_Size->setObjectName(QString::fromUtf8("spinBox_SetCore_09_Eilenstein_Size"));
        sizePolicy7.setHeightForWidth(spinBox_SetCore_09_Eilenstein_Size->sizePolicy().hasHeightForWidth());
        spinBox_SetCore_09_Eilenstein_Size->setSizePolicy(sizePolicy7);
        spinBox_SetCore_09_Eilenstein_Size->setMinimumSize(QSize(65, 19));
        spinBox_SetCore_09_Eilenstein_Size->setMaximumSize(QSize(65, 20));
        spinBox_SetCore_09_Eilenstein_Size->setMinimum(1);
        spinBox_SetCore_09_Eilenstein_Size->setMaximum(10000);
        spinBox_SetCore_09_Eilenstein_Size->setSingleStep(2);
        spinBox_SetCore_09_Eilenstein_Size->setValue(25);

        gridLayout_5->addWidget(spinBox_SetCore_09_Eilenstein_Size, 4, 2, 1, 1);

        doubleSpinBox_SetCore_04_Thres_Offset = new QDoubleSpinBox(groupBox_Settings_Cores);
        doubleSpinBox_SetCore_04_Thres_Offset->setObjectName(QString::fromUtf8("doubleSpinBox_SetCore_04_Thres_Offset"));
        sizePolicy7.setHeightForWidth(doubleSpinBox_SetCore_04_Thres_Offset->sizePolicy().hasHeightForWidth());
        doubleSpinBox_SetCore_04_Thres_Offset->setSizePolicy(sizePolicy7);
        doubleSpinBox_SetCore_04_Thres_Offset->setMinimumSize(QSize(65, 0));
        doubleSpinBox_SetCore_04_Thres_Offset->setMaximumSize(QSize(65, 16777215));
        doubleSpinBox_SetCore_04_Thres_Offset->setMinimum(-256.000000000000000);
        doubleSpinBox_SetCore_04_Thres_Offset->setMaximum(255.000000000000000);
        doubleSpinBox_SetCore_04_Thres_Offset->setSingleStep(1.000000000000000);
        doubleSpinBox_SetCore_04_Thres_Offset->setValue(-2.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_SetCore_04_Thres_Offset, 1, 3, 1, 1);

        label_SetCore_12_Open_Desription = new QLabel(groupBox_Settings_Cores);
        label_SetCore_12_Open_Desription->setObjectName(QString::fromUtf8("label_SetCore_12_Open_Desription"));

        gridLayout_5->addWidget(label_SetCore_12_Open_Desription, 6, 4, 1, 1);

        label_SetCore_12_Open_Title = new QLabel(groupBox_Settings_Cores);
        label_SetCore_12_Open_Title->setObjectName(QString::fromUtf8("label_SetCore_12_Open_Title"));
        label_SetCore_12_Open_Title->setMinimumSize(QSize(75, 0));
        label_SetCore_12_Open_Title->setMaximumSize(QSize(75, 16777215));

        gridLayout_5->addWidget(label_SetCore_12_Open_Title, 6, 1, 1, 1);

        label_SetCore_09_Eilenstein_Pos = new QLabel(groupBox_Settings_Cores);
        label_SetCore_09_Eilenstein_Pos->setObjectName(QString::fromUtf8("label_SetCore_09_Eilenstein_Pos"));
        sizePolicy2.setHeightForWidth(label_SetCore_09_Eilenstein_Pos->sizePolicy().hasHeightForWidth());
        label_SetCore_09_Eilenstein_Pos->setSizePolicy(sizePolicy2);
        label_SetCore_09_Eilenstein_Pos->setMinimumSize(QSize(15, 0));
        label_SetCore_09_Eilenstein_Pos->setMaximumSize(QSize(15, 16777215));

        gridLayout_5->addWidget(label_SetCore_09_Eilenstein_Pos, 4, 0, 1, 1);

        label_SetCore_09_Eilenstein_Title = new QLabel(groupBox_Settings_Cores);
        label_SetCore_09_Eilenstein_Title->setObjectName(QString::fromUtf8("label_SetCore_09_Eilenstein_Title"));
        label_SetCore_09_Eilenstein_Title->setMinimumSize(QSize(75, 0));
        label_SetCore_09_Eilenstein_Title->setMaximumSize(QSize(75, 16777215));

        gridLayout_5->addWidget(label_SetCore_09_Eilenstein_Title, 4, 1, 1, 1);

        spinBox_SetCore_12_Open_Area = new QSpinBox(groupBox_Settings_Cores);
        spinBox_SetCore_12_Open_Area->setObjectName(QString::fromUtf8("spinBox_SetCore_12_Open_Area"));
        spinBox_SetCore_12_Open_Area->setMinimumSize(QSize(133, 19));
        spinBox_SetCore_12_Open_Area->setMaximumSize(QSize(133, 20));
        spinBox_SetCore_12_Open_Area->setMinimum(1);
        spinBox_SetCore_12_Open_Area->setMaximum(100001);
        spinBox_SetCore_12_Open_Area->setSingleStep(2);
        spinBox_SetCore_12_Open_Area->setValue(5);

        gridLayout_5->addWidget(spinBox_SetCore_12_Open_Area, 6, 2, 1, 2);

        label_SetCore_04_Thres_Title = new QLabel(groupBox_Settings_Cores);
        label_SetCore_04_Thres_Title->setObjectName(QString::fromUtf8("label_SetCore_04_Thres_Title"));
        label_SetCore_04_Thres_Title->setMinimumSize(QSize(75, 0));
        label_SetCore_04_Thres_Title->setMaximumSize(QSize(75, 16777215));

        gridLayout_5->addWidget(label_SetCore_04_Thres_Title, 1, 1, 1, 1);

        spinBox_SetCore_02_Gauss_Size = new QSpinBox(groupBox_Settings_Cores);
        spinBox_SetCore_02_Gauss_Size->setObjectName(QString::fromUtf8("spinBox_SetCore_02_Gauss_Size"));
        sizePolicy7.setHeightForWidth(spinBox_SetCore_02_Gauss_Size->sizePolicy().hasHeightForWidth());
        spinBox_SetCore_02_Gauss_Size->setSizePolicy(sizePolicy7);
        spinBox_SetCore_02_Gauss_Size->setMinimumSize(QSize(65, 19));
        spinBox_SetCore_02_Gauss_Size->setMaximumSize(QSize(65, 20));
        spinBox_SetCore_02_Gauss_Size->setMinimum(3);
        spinBox_SetCore_02_Gauss_Size->setMaximum(10000);
        spinBox_SetCore_02_Gauss_Size->setSingleStep(2);
        spinBox_SetCore_02_Gauss_Size->setValue(33);

        gridLayout_5->addWidget(spinBox_SetCore_02_Gauss_Size, 0, 2, 1, 1);

        spinBox_SetCore_04_Thres_Size = new QSpinBox(groupBox_Settings_Cores);
        spinBox_SetCore_04_Thres_Size->setObjectName(QString::fromUtf8("spinBox_SetCore_04_Thres_Size"));
        sizePolicy7.setHeightForWidth(spinBox_SetCore_04_Thres_Size->sizePolicy().hasHeightForWidth());
        spinBox_SetCore_04_Thres_Size->setSizePolicy(sizePolicy7);
        spinBox_SetCore_04_Thres_Size->setMinimumSize(QSize(65, 19));
        spinBox_SetCore_04_Thres_Size->setMaximumSize(QSize(65, 20));
        spinBox_SetCore_04_Thres_Size->setMinimum(3);
        spinBox_SetCore_04_Thres_Size->setMaximum(100000);
        spinBox_SetCore_04_Thres_Size->setSingleStep(10);
        spinBox_SetCore_04_Thres_Size->setValue(401);

        gridLayout_5->addWidget(spinBox_SetCore_04_Thres_Size, 1, 2, 1, 1);

        label_SetCore_02_Gauss_Desription = new QLabel(groupBox_Settings_Cores);
        label_SetCore_02_Gauss_Desription->setObjectName(QString::fromUtf8("label_SetCore_02_Gauss_Desription"));

        gridLayout_5->addWidget(label_SetCore_02_Gauss_Desription, 0, 4, 1, 1);

        label_SetCore_05_Fill_Description = new QLabel(groupBox_Settings_Cores);
        label_SetCore_05_Fill_Description->setObjectName(QString::fromUtf8("label_SetCore_05_Fill_Description"));

        gridLayout_5->addWidget(label_SetCore_05_Fill_Description, 2, 4, 1, 1);

        spinBox_SetCore_05_Fill_Area = new QSpinBox(groupBox_Settings_Cores);
        spinBox_SetCore_05_Fill_Area->setObjectName(QString::fromUtf8("spinBox_SetCore_05_Fill_Area"));
        spinBox_SetCore_05_Fill_Area->setMinimumSize(QSize(133, 19));
        spinBox_SetCore_05_Fill_Area->setMaximumSize(QSize(133, 20));
        spinBox_SetCore_05_Fill_Area->setMaximum(999999999);
        spinBox_SetCore_05_Fill_Area->setSingleStep(10000);
        spinBox_SetCore_05_Fill_Area->setValue(450000);

        gridLayout_5->addWidget(spinBox_SetCore_05_Fill_Area, 2, 2, 1, 2);

        label_SetCore_05_Fill_Pos = new QLabel(groupBox_Settings_Cores);
        label_SetCore_05_Fill_Pos->setObjectName(QString::fromUtf8("label_SetCore_05_Fill_Pos"));
        sizePolicy2.setHeightForWidth(label_SetCore_05_Fill_Pos->sizePolicy().hasHeightForWidth());
        label_SetCore_05_Fill_Pos->setSizePolicy(sizePolicy2);
        label_SetCore_05_Fill_Pos->setMinimumSize(QSize(15, 0));
        label_SetCore_05_Fill_Pos->setMaximumSize(QSize(15, 16777215));

        gridLayout_5->addWidget(label_SetCore_05_Fill_Pos, 2, 0, 1, 1);

        label_SetCore_13_Dilation_Pos = new QLabel(groupBox_Settings_Cores);
        label_SetCore_13_Dilation_Pos->setObjectName(QString::fromUtf8("label_SetCore_13_Dilation_Pos"));
        sizePolicy2.setHeightForWidth(label_SetCore_13_Dilation_Pos->sizePolicy().hasHeightForWidth());
        label_SetCore_13_Dilation_Pos->setSizePolicy(sizePolicy2);
        label_SetCore_13_Dilation_Pos->setMinimumSize(QSize(15, 0));
        label_SetCore_13_Dilation_Pos->setMaximumSize(QSize(15, 16777215));

        gridLayout_5->addWidget(label_SetCore_13_Dilation_Pos, 7, 0, 1, 1);

        label_SetCore_13_Dilation_Description = new QLabel(groupBox_Settings_Cores);
        label_SetCore_13_Dilation_Description->setObjectName(QString::fromUtf8("label_SetCore_13_Dilation_Description"));

        gridLayout_5->addWidget(label_SetCore_13_Dilation_Description, 7, 4, 1, 1);

        label_SetCore_11_Thresh_Pos = new QLabel(groupBox_Settings_Cores);
        label_SetCore_11_Thresh_Pos->setObjectName(QString::fromUtf8("label_SetCore_11_Thresh_Pos"));
        sizePolicy2.setHeightForWidth(label_SetCore_11_Thresh_Pos->sizePolicy().hasHeightForWidth());
        label_SetCore_11_Thresh_Pos->setSizePolicy(sizePolicy2);
        label_SetCore_11_Thresh_Pos->setMinimumSize(QSize(15, 0));
        label_SetCore_11_Thresh_Pos->setMaximumSize(QSize(15, 16777215));

        gridLayout_5->addWidget(label_SetCore_11_Thresh_Pos, 5, 0, 1, 1);

        spinBox_SetCore_13_Dilation_Size = new QSpinBox(groupBox_Settings_Cores);
        spinBox_SetCore_13_Dilation_Size->setObjectName(QString::fromUtf8("spinBox_SetCore_13_Dilation_Size"));
        spinBox_SetCore_13_Dilation_Size->setMinimumSize(QSize(133, 19));
        spinBox_SetCore_13_Dilation_Size->setMaximumSize(QSize(133, 20));
        spinBox_SetCore_13_Dilation_Size->setMinimum(1);
        spinBox_SetCore_13_Dilation_Size->setMaximum(100001);
        spinBox_SetCore_13_Dilation_Size->setSingleStep(2);
        spinBox_SetCore_13_Dilation_Size->setValue(29);

        gridLayout_5->addWidget(spinBox_SetCore_13_Dilation_Size, 7, 2, 1, 2);

        doubleSpinBox_Set_Core_09_Eilenstein_Offset = new QDoubleSpinBox(groupBox_Settings_Cores);
        doubleSpinBox_Set_Core_09_Eilenstein_Offset->setObjectName(QString::fromUtf8("doubleSpinBox_Set_Core_09_Eilenstein_Offset"));
        doubleSpinBox_Set_Core_09_Eilenstein_Offset->setEnabled(true);
        sizePolicy7.setHeightForWidth(doubleSpinBox_Set_Core_09_Eilenstein_Offset->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Set_Core_09_Eilenstein_Offset->setSizePolicy(sizePolicy7);
        doubleSpinBox_Set_Core_09_Eilenstein_Offset->setMinimumSize(QSize(65, 0));
        doubleSpinBox_Set_Core_09_Eilenstein_Offset->setMaximumSize(QSize(65, 16777215));
#if QT_CONFIG(tooltip)
        doubleSpinBox_Set_Core_09_Eilenstein_Offset->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
        doubleSpinBox_Set_Core_09_Eilenstein_Offset->setDecimals(0);
        doubleSpinBox_Set_Core_09_Eilenstein_Offset->setMinimum(-100000.000000000000000);
        doubleSpinBox_Set_Core_09_Eilenstein_Offset->setMaximum(100000.000000000000000);
        doubleSpinBox_Set_Core_09_Eilenstein_Offset->setValue(0.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_Set_Core_09_Eilenstein_Offset, 4, 3, 1, 1);

        spinBox_SetCore_11_Thresh_Thres = new QSpinBox(groupBox_Settings_Cores);
        spinBox_SetCore_11_Thresh_Thres->setObjectName(QString::fromUtf8("spinBox_SetCore_11_Thresh_Thres"));
        spinBox_SetCore_11_Thresh_Thres->setMinimumSize(QSize(133, 19));
        spinBox_SetCore_11_Thresh_Thres->setMaximumSize(QSize(133, 20));
        spinBox_SetCore_11_Thresh_Thres->setMaximum(255);
        spinBox_SetCore_11_Thresh_Thres->setSingleStep(1);
        spinBox_SetCore_11_Thresh_Thres->setValue(208);

        gridLayout_5->addWidget(spinBox_SetCore_11_Thresh_Thres, 5, 2, 1, 2);

        label_SetCore_11_Thresh_Desription = new QLabel(groupBox_Settings_Cores);
        label_SetCore_11_Thresh_Desription->setObjectName(QString::fromUtf8("label_SetCore_11_Thresh_Desription"));

        gridLayout_5->addWidget(label_SetCore_11_Thresh_Desription, 5, 4, 1, 1);

        label_SetCore_11_Thresh_Title = new QLabel(groupBox_Settings_Cores);
        label_SetCore_11_Thresh_Title->setObjectName(QString::fromUtf8("label_SetCore_11_Thresh_Title"));
        label_SetCore_11_Thresh_Title->setMinimumSize(QSize(75, 0));
        label_SetCore_11_Thresh_Title->setMaximumSize(QSize(75, 16777215));

        gridLayout_5->addWidget(label_SetCore_11_Thresh_Title, 5, 1, 1, 1);

        label_SetCore_13_Dilation_Title = new QLabel(groupBox_Settings_Cores);
        label_SetCore_13_Dilation_Title->setObjectName(QString::fromUtf8("label_SetCore_13_Dilation_Title"));
        label_SetCore_13_Dilation_Title->setMinimumSize(QSize(75, 0));
        label_SetCore_13_Dilation_Title->setMaximumSize(QSize(75, 16777215));

        gridLayout_5->addWidget(label_SetCore_13_Dilation_Title, 7, 1, 1, 1);

        label_34 = new QLabel(groupBox_Settings_Cores);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout_5->addWidget(label_34, 8, 0, 1, 1);

        label_35 = new QLabel(groupBox_Settings_Cores);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout_5->addWidget(label_35, 8, 1, 1, 1);

        label_36 = new QLabel(groupBox_Settings_Cores);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_5->addWidget(label_36, 8, 4, 1, 1);

        checkBox_SetCore_13_ExcludeBordered = new QCheckBox(groupBox_Settings_Cores);
        checkBox_SetCore_13_ExcludeBordered->setObjectName(QString::fromUtf8("checkBox_SetCore_13_ExcludeBordered"));
        checkBox_SetCore_13_ExcludeBordered->setMinimumSize(QSize(0, 19));
        checkBox_SetCore_13_ExcludeBordered->setMaximumSize(QSize(16777215, 20));
        checkBox_SetCore_13_ExcludeBordered->setChecked(false);

        gridLayout_5->addWidget(checkBox_SetCore_13_ExcludeBordered, 8, 2, 1, 2);

        label_41 = new QLabel(groupBox_Settings_Cores);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        gridLayout_5->addWidget(label_41, 10, 1, 1, 1);

        spinBox_SetCore_14_AreaMaxOfSmall = new QSpinBox(groupBox_Settings_Cores);
        spinBox_SetCore_14_AreaMaxOfSmall->setObjectName(QString::fromUtf8("spinBox_SetCore_14_AreaMaxOfSmall"));
        spinBox_SetCore_14_AreaMaxOfSmall->setMinimumSize(QSize(65, 19));
        spinBox_SetCore_14_AreaMaxOfSmall->setMaximumSize(QSize(65, 20));
        spinBox_SetCore_14_AreaMaxOfSmall->setMinimum(0);
        spinBox_SetCore_14_AreaMaxOfSmall->setMaximum(999999999);
        spinBox_SetCore_14_AreaMaxOfSmall->setSingleStep(100);
        spinBox_SetCore_14_AreaMaxOfSmall->setValue(2500);

        gridLayout_5->addWidget(spinBox_SetCore_14_AreaMaxOfSmall, 10, 2, 1, 1);

        label_42 = new QLabel(groupBox_Settings_Cores);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        gridLayout_5->addWidget(label_42, 10, 4, 1, 1);

        label_43 = new QLabel(groupBox_Settings_Cores);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        gridLayout_5->addWidget(label_43, 9, 1, 1, 1);

        label_40 = new QLabel(groupBox_Settings_Cores);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout_5->addWidget(label_40, 9, 0, 2, 1);

        label_44 = new QLabel(groupBox_Settings_Cores);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        gridLayout_5->addWidget(label_44, 9, 4, 1, 1);

        spinBox_SetCore_14_AreaDistMin = new QSpinBox(groupBox_Settings_Cores);
        spinBox_SetCore_14_AreaDistMin->setObjectName(QString::fromUtf8("spinBox_SetCore_14_AreaDistMin"));
        spinBox_SetCore_14_AreaDistMin->setMinimumSize(QSize(0, 19));
        spinBox_SetCore_14_AreaDistMin->setMaximumSize(QSize(16777215, 20));
        spinBox_SetCore_14_AreaDistMin->setMaximum(9999);
        spinBox_SetCore_14_AreaDistMin->setValue(1);

        gridLayout_5->addWidget(spinBox_SetCore_14_AreaDistMin, 9, 2, 1, 1);

        spinBox_SetCore_14_AreaDistMax = new QSpinBox(groupBox_Settings_Cores);
        spinBox_SetCore_14_AreaDistMax->setObjectName(QString::fromUtf8("spinBox_SetCore_14_AreaDistMax"));
        spinBox_SetCore_14_AreaDistMax->setMaximum(9999);
        spinBox_SetCore_14_AreaDistMax->setValue(5);

        gridLayout_5->addWidget(spinBox_SetCore_14_AreaDistMax, 9, 3, 1, 1);


        gridLayout_24->addWidget(groupBox_Settings_Cores, 1, 0, 1, 1);

        groupBox_Settings_Cyto = new QGroupBox(tab_Settings);
        groupBox_Settings_Cyto->setObjectName(QString::fromUtf8("groupBox_Settings_Cyto"));
        sizePolicy5.setHeightForWidth(groupBox_Settings_Cyto->sizePolicy().hasHeightForWidth());
        groupBox_Settings_Cyto->setSizePolicy(sizePolicy5);
        groupBox_Settings_Cyto->setMinimumSize(QSize(0, 0));
        groupBox_Settings_Cyto->setMaximumSize(QSize(466, 16777215));
        groupBox_Settings_Cyto->setFlat(true);
        gridLayout = new QGridLayout(groupBox_Settings_Cyto);
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, 0, 0, 0);
        label_11 = new QLabel(groupBox_Settings_Cyto);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(75, 0));
        label_11->setMaximumSize(QSize(75, 16777215));

        gridLayout->addWidget(label_11, 1, 1, 1, 1);

        spinBox_SetCyto_Gauss_Size = new QSpinBox(groupBox_Settings_Cyto);
        spinBox_SetCyto_Gauss_Size->setObjectName(QString::fromUtf8("spinBox_SetCyto_Gauss_Size"));
        spinBox_SetCyto_Gauss_Size->setMinimumSize(QSize(65, 19));
        spinBox_SetCyto_Gauss_Size->setMaximumSize(QSize(65, 20));
        spinBox_SetCyto_Gauss_Size->setMinimum(1);
        spinBox_SetCyto_Gauss_Size->setMaximum(100001);
        spinBox_SetCyto_Gauss_Size->setSingleStep(2);
        spinBox_SetCyto_Gauss_Size->setValue(15);

        gridLayout->addWidget(spinBox_SetCyto_Gauss_Size, 1, 2, 1, 1);

        label_10 = new QLabel(groupBox_Settings_Cyto);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);
        label_10->setMinimumSize(QSize(15, 0));
        label_10->setMaximumSize(QSize(15, 16777215));

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        label_20 = new QLabel(groupBox_Settings_Cyto);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMinimumSize(QSize(75, 0));
        label_20->setMaximumSize(QSize(75, 16777215));

        gridLayout->addWidget(label_20, 3, 1, 1, 1);

        label_19 = new QLabel(groupBox_Settings_Cyto);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy2.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy2);
        label_19->setMinimumSize(QSize(15, 0));
        label_19->setMaximumSize(QSize(15, 16777215));

        gridLayout->addWidget(label_19, 3, 0, 1, 1);

        label_22 = new QLabel(groupBox_Settings_Cyto);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout->addWidget(label_22, 4, 4, 1, 1);

        spinBox_SetCyto_Dilation_Size = new QSpinBox(groupBox_Settings_Cyto);
        spinBox_SetCyto_Dilation_Size->setObjectName(QString::fromUtf8("spinBox_SetCyto_Dilation_Size"));
        spinBox_SetCyto_Dilation_Size->setMinimumSize(QSize(133, 19));
        spinBox_SetCyto_Dilation_Size->setMaximumSize(QSize(133, 20));
        spinBox_SetCyto_Dilation_Size->setMinimum(1);
        spinBox_SetCyto_Dilation_Size->setMaximum(100001);
        spinBox_SetCyto_Dilation_Size->setSingleStep(2);
        spinBox_SetCyto_Dilation_Size->setValue(27);

        gridLayout->addWidget(spinBox_SetCyto_Dilation_Size, 4, 2, 1, 2);

        spinBox_SetCyto_Closing_Size = new QSpinBox(groupBox_Settings_Cyto);
        spinBox_SetCyto_Closing_Size->setObjectName(QString::fromUtf8("spinBox_SetCyto_Closing_Size"));
        spinBox_SetCyto_Closing_Size->setMinimumSize(QSize(133, 19));
        spinBox_SetCyto_Closing_Size->setMaximumSize(QSize(133, 20));
        spinBox_SetCyto_Closing_Size->setMinimum(1);
        spinBox_SetCyto_Closing_Size->setMaximum(100001);
        spinBox_SetCyto_Closing_Size->setSingleStep(2);
        spinBox_SetCyto_Closing_Size->setValue(85);

        gridLayout->addWidget(spinBox_SetCyto_Closing_Size, 3, 2, 1, 2);

        doubleSpinBox_SetCyto_Gauss_Sigma = new QDoubleSpinBox(groupBox_Settings_Cyto);
        doubleSpinBox_SetCyto_Gauss_Sigma->setObjectName(QString::fromUtf8("doubleSpinBox_SetCyto_Gauss_Sigma"));
        doubleSpinBox_SetCyto_Gauss_Sigma->setMinimumSize(QSize(65, 0));
        doubleSpinBox_SetCyto_Gauss_Sigma->setMaximumSize(QSize(65, 16777215));
        doubleSpinBox_SetCyto_Gauss_Sigma->setMaximum(1000000.000000000000000);
        doubleSpinBox_SetCyto_Gauss_Sigma->setValue(7.000000000000000);

        gridLayout->addWidget(doubleSpinBox_SetCyto_Gauss_Sigma, 1, 3, 1, 1);

        label_21 = new QLabel(groupBox_Settings_Cyto);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout->addWidget(label_21, 3, 4, 1, 1);

        label_12 = new QLabel(groupBox_Settings_Cyto);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 1, 4, 1, 1);

        label_23 = new QLabel(groupBox_Settings_Cyto);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        sizePolicy2.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy2);
        label_23->setMinimumSize(QSize(15, 0));
        label_23->setMaximumSize(QSize(15, 16777215));

        gridLayout->addWidget(label_23, 4, 0, 1, 1);

        label_24 = new QLabel(groupBox_Settings_Cyto);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMinimumSize(QSize(75, 0));
        label_24->setMaximumSize(QSize(75, 16777215));

        gridLayout->addWidget(label_24, 4, 1, 1, 1);

        label_28 = new QLabel(groupBox_Settings_Cyto);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout->addWidget(label_28, 2, 0, 1, 1);

        label_29 = new QLabel(groupBox_Settings_Cyto);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout->addWidget(label_29, 2, 1, 1, 1);

        label_30 = new QLabel(groupBox_Settings_Cyto);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout->addWidget(label_30, 2, 4, 1, 1);

        spinBox_SetCyto_Thresh_Size = new QSpinBox(groupBox_Settings_Cyto);
        spinBox_SetCyto_Thresh_Size->setObjectName(QString::fromUtf8("spinBox_SetCyto_Thresh_Size"));
        spinBox_SetCyto_Thresh_Size->setMinimumSize(QSize(65, 19));
        spinBox_SetCyto_Thresh_Size->setMaximumSize(QSize(65, 20));
        spinBox_SetCyto_Thresh_Size->setMinimum(1);
        spinBox_SetCyto_Thresh_Size->setMaximum(100001);
        spinBox_SetCyto_Thresh_Size->setSingleStep(2);
        spinBox_SetCyto_Thresh_Size->setValue(31);

        gridLayout->addWidget(spinBox_SetCyto_Thresh_Size, 2, 2, 1, 1);

        doubleSpinBox_SetCyto_Thresh_Offset = new QDoubleSpinBox(groupBox_Settings_Cyto);
        doubleSpinBox_SetCyto_Thresh_Offset->setObjectName(QString::fromUtf8("doubleSpinBox_SetCyto_Thresh_Offset"));
        doubleSpinBox_SetCyto_Thresh_Offset->setMinimumSize(QSize(65, 0));
        doubleSpinBox_SetCyto_Thresh_Offset->setMaximumSize(QSize(65, 16777215));
        doubleSpinBox_SetCyto_Thresh_Offset->setMinimum(-256.000000000000000);
        doubleSpinBox_SetCyto_Thresh_Offset->setMaximum(255.000000000000000);
        doubleSpinBox_SetCyto_Thresh_Offset->setValue(-2.000000000000000);

        gridLayout->addWidget(doubleSpinBox_SetCyto_Thresh_Offset, 2, 3, 1, 1);


        gridLayout_24->addWidget(groupBox_Settings_Cyto, 2, 0, 1, 1);

        groupBox_Results = new QGroupBox(tab_Settings);
        groupBox_Results->setObjectName(QString::fromUtf8("groupBox_Results"));
        sizePolicy5.setHeightForWidth(groupBox_Results->sizePolicy().hasHeightForWidth());
        groupBox_Results->setSizePolicy(sizePolicy5);
        groupBox_Results->setMinimumSize(QSize(0, 0));
        groupBox_Results->setMaximumSize(QSize(466, 16777215));
        groupBox_Results->setFlat(true);
        gridLayout_16 = new QGridLayout(groupBox_Results);
        gridLayout_16->setSpacing(3);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(9, 0, 0, 0);
        label_27 = new QLabel(groupBox_Results);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMinimumSize(QSize(20, 0));
        label_27->setMaximumSize(QSize(20, 16777215));

        gridLayout_16->addWidget(label_27, 0, 0, 1, 1);

        label_25 = new QLabel(groupBox_Results);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setMinimumSize(QSize(70, 0));
        label_25->setMaximumSize(QSize(70, 16777215));

        gridLayout_16->addWidget(label_25, 0, 1, 1, 1);

        spinBox_Results_SpreadMax = new QSpinBox(groupBox_Results);
        spinBox_Results_SpreadMax->setObjectName(QString::fromUtf8("spinBox_Results_SpreadMax"));
        spinBox_Results_SpreadMax->setMinimumSize(QSize(133, 19));
        spinBox_Results_SpreadMax->setMaximumSize(QSize(133, 20));
        spinBox_Results_SpreadMax->setMinimum(255);
        spinBox_Results_SpreadMax->setMaximum(65535);
        spinBox_Results_SpreadMax->setSingleStep(100);
        spinBox_Results_SpreadMax->setValue(15000);

        gridLayout_16->addWidget(spinBox_Results_SpreadMax, 0, 2, 1, 1);

        label_26 = new QLabel(groupBox_Results);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_16->addWidget(label_26, 0, 3, 1, 1);


        gridLayout_24->addWidget(groupBox_Results, 4, 0, 1, 1);

        tabWidget->addTab(tab_Settings, QString());
        tab_Output = new QWidget();
        tab_Output->setObjectName(QString::fromUtf8("tab_Output"));
        gridLayout_25 = new QGridLayout(tab_Output);
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        groupBox_OutImg = new QGroupBox(tab_Output);
        groupBox_OutImg->setObjectName(QString::fromUtf8("groupBox_OutImg"));
        groupBox_OutImg->setFlat(true);
        gridLayout_27 = new QGridLayout(groupBox_OutImg);
        gridLayout_27->setSpacing(3);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        gridLayout_27->setContentsMargins(0, 0, 0, 0);
        groupBox_OutImg_Img = new QGroupBox(groupBox_OutImg);
        groupBox_OutImg_Img->setObjectName(QString::fromUtf8("groupBox_OutImg_Img"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(1);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(groupBox_OutImg_Img->sizePolicy().hasHeightForWidth());
        groupBox_OutImg_Img->setSizePolicy(sizePolicy8);
        gridLayout_26 = new QGridLayout(groupBox_OutImg_Img);
        gridLayout_26->setSpacing(3);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        gridLayout_26->setContentsMargins(3, 0, 3, 0);
        checkBox_OutImg_Img_Plasma = new QCheckBox(groupBox_OutImg_Img);
        checkBox_OutImg_Img_Plasma->setObjectName(QString::fromUtf8("checkBox_OutImg_Img_Plasma"));
        checkBox_OutImg_Img_Plasma->setChecked(true);

        gridLayout_26->addWidget(checkBox_OutImg_Img_Plasma, 3, 0, 1, 1);

        checkBox_OutImg_Img_Contrast = new QCheckBox(groupBox_OutImg_Img);
        checkBox_OutImg_Img_Contrast->setObjectName(QString::fromUtf8("checkBox_OutImg_Img_Contrast"));
        checkBox_OutImg_Img_Contrast->setChecked(true);

        gridLayout_26->addWidget(checkBox_OutImg_Img_Contrast, 1, 0, 1, 1);

        checkBox_OutImg_Img_ProcSteps = new QCheckBox(groupBox_OutImg_Img);
        checkBox_OutImg_Img_ProcSteps->setObjectName(QString::fromUtf8("checkBox_OutImg_Img_ProcSteps"));
        checkBox_OutImg_Img_ProcSteps->setChecked(false);

        gridLayout_26->addWidget(checkBox_OutImg_Img_ProcSteps, 7, 0, 1, 1);

        checkBox_OutImg_Img_Nuclei = new QCheckBox(groupBox_OutImg_Img);
        checkBox_OutImg_Img_Nuclei->setObjectName(QString::fromUtf8("checkBox_OutImg_Img_Nuclei"));
        checkBox_OutImg_Img_Nuclei->setChecked(true);

        gridLayout_26->addWidget(checkBox_OutImg_Img_Nuclei, 2, 0, 1, 1);

        verticalSpacer_OutImg_Img = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_26->addItem(verticalSpacer_OutImg_Img, 8, 0, 1, 1);

        checkBox_OutImg_Img_Foci = new QCheckBox(groupBox_OutImg_Img);
        checkBox_OutImg_Img_Foci->setObjectName(QString::fromUtf8("checkBox_OutImg_Img_Foci"));
        checkBox_OutImg_Img_Foci->setChecked(true);

        gridLayout_26->addWidget(checkBox_OutImg_Img_Foci, 4, 0, 1, 1);

        checkBox_OutImg_Img_Regions = new QCheckBox(groupBox_OutImg_Img);
        checkBox_OutImg_Img_Regions->setObjectName(QString::fromUtf8("checkBox_OutImg_Img_Regions"));
        checkBox_OutImg_Img_Regions->setChecked(true);

        gridLayout_26->addWidget(checkBox_OutImg_Img_Regions, 5, 0, 1, 1);

        checkBox_OutImg_Img_Normal = new QCheckBox(groupBox_OutImg_Img);
        checkBox_OutImg_Img_Normal->setObjectName(QString::fromUtf8("checkBox_OutImg_Img_Normal"));
        checkBox_OutImg_Img_Normal->setChecked(true);

        gridLayout_26->addWidget(checkBox_OutImg_Img_Normal, 0, 0, 1, 1);

        line_OutImg_Img = new QFrame(groupBox_OutImg_Img);
        line_OutImg_Img->setObjectName(QString::fromUtf8("line_OutImg_Img"));
        line_OutImg_Img->setFrameShape(QFrame::HLine);
        line_OutImg_Img->setFrameShadow(QFrame::Sunken);

        gridLayout_26->addWidget(line_OutImg_Img, 6, 0, 1, 1);


        gridLayout_27->addWidget(groupBox_OutImg_Img, 0, 0, 1, 1);

        groupBox_OutImg_Plots = new QGroupBox(groupBox_OutImg);
        groupBox_OutImg_Plots->setObjectName(QString::fromUtf8("groupBox_OutImg_Plots"));
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(2);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(groupBox_OutImg_Plots->sizePolicy().hasHeightForWidth());
        groupBox_OutImg_Plots->setSizePolicy(sizePolicy9);
        gridLayout_33 = new QGridLayout(groupBox_OutImg_Plots);
        gridLayout_33->setSpacing(3);
        gridLayout_33->setObjectName(QString::fromUtf8("gridLayout_33"));
        gridLayout_33->setContentsMargins(3, 0, 3, 0);
        checkBox_OutImg_Plots_FocArea = new QCheckBox(groupBox_OutImg_Plots);
        checkBox_OutImg_Plots_FocArea->setObjectName(QString::fromUtf8("checkBox_OutImg_Plots_FocArea"));
        checkBox_OutImg_Plots_FocArea->setChecked(true);
        checkBox_OutImg_Plots_FocArea->setTristate(true);

        gridLayout_33->addWidget(checkBox_OutImg_Plots_FocArea, 7, 0, 1, 1);

        checkBox_OutImg_Plots_Bar = new QCheckBox(groupBox_OutImg_Plots);
        checkBox_OutImg_Plots_Bar->setObjectName(QString::fromUtf8("checkBox_OutImg_Plots_Bar"));
        checkBox_OutImg_Plots_Bar->setChecked(true);

        gridLayout_33->addWidget(checkBox_OutImg_Plots_Bar, 0, 0, 1, 1);

        checkBox_OutImg_Plots_Hist = new QCheckBox(groupBox_OutImg_Plots);
        checkBox_OutImg_Plots_Hist->setObjectName(QString::fromUtf8("checkBox_OutImg_Plots_Hist"));
        checkBox_OutImg_Plots_Hist->setChecked(true);

        gridLayout_33->addWidget(checkBox_OutImg_Plots_Hist, 1, 0, 1, 1);

        checkBox_OutImg_Plots_FocNumber = new QCheckBox(groupBox_OutImg_Plots);
        checkBox_OutImg_Plots_FocNumber->setObjectName(QString::fromUtf8("checkBox_OutImg_Plots_FocNumber"));
        checkBox_OutImg_Plots_FocNumber->setChecked(true);
        checkBox_OutImg_Plots_FocNumber->setTristate(true);

        gridLayout_33->addWidget(checkBox_OutImg_Plots_FocNumber, 6, 0, 1, 1);

        checkBox_OutImg_Plots_CytArea = new QCheckBox(groupBox_OutImg_Plots);
        checkBox_OutImg_Plots_CytArea->setObjectName(QString::fromUtf8("checkBox_OutImg_Plots_CytArea"));
        checkBox_OutImg_Plots_CytArea->setChecked(true);
        checkBox_OutImg_Plots_CytArea->setTristate(true);

        gridLayout_33->addWidget(checkBox_OutImg_Plots_CytArea, 5, 0, 1, 1);

        checkBox_OutImg_Plots_Scatter = new QCheckBox(groupBox_OutImg_Plots);
        checkBox_OutImg_Plots_Scatter->setObjectName(QString::fromUtf8("checkBox_OutImg_Plots_Scatter"));
        checkBox_OutImg_Plots_Scatter->setChecked(true);

        gridLayout_33->addWidget(checkBox_OutImg_Plots_Scatter, 2, 0, 1, 1);

        checkBox_OutImg_Plots_NucArea = new QCheckBox(groupBox_OutImg_Plots);
        checkBox_OutImg_Plots_NucArea->setObjectName(QString::fromUtf8("checkBox_OutImg_Plots_NucArea"));
        checkBox_OutImg_Plots_NucArea->setChecked(true);
        checkBox_OutImg_Plots_NucArea->setTristate(true);

        gridLayout_33->addWidget(checkBox_OutImg_Plots_NucArea, 4, 0, 1, 1);

        line_OutImg_Plots = new QFrame(groupBox_OutImg_Plots);
        line_OutImg_Plots->setObjectName(QString::fromUtf8("line_OutImg_Plots"));
        line_OutImg_Plots->setFrameShape(QFrame::HLine);
        line_OutImg_Plots->setFrameShadow(QFrame::Sunken);

        gridLayout_33->addWidget(line_OutImg_Plots, 3, 0, 1, 1);

        verticalSpacer_OutImg_Plots = new QSpacerItem(20, 31, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_33->addItem(verticalSpacer_OutImg_Plots, 9, 0, 1, 1);

        checkBox_OutImg_Plots_NucMeanInt = new QCheckBox(groupBox_OutImg_Plots);
        checkBox_OutImg_Plots_NucMeanInt->setObjectName(QString::fromUtf8("checkBox_OutImg_Plots_NucMeanInt"));
        checkBox_OutImg_Plots_NucMeanInt->setChecked(true);

        gridLayout_33->addWidget(checkBox_OutImg_Plots_NucMeanInt, 8, 0, 1, 1);


        gridLayout_27->addWidget(groupBox_OutImg_Plots, 0, 2, 1, 1);

        groupBox_OutImg_Table = new QGroupBox(groupBox_OutImg);
        groupBox_OutImg_Table->setObjectName(QString::fromUtf8("groupBox_OutImg_Table"));
        sizePolicy8.setHeightForWidth(groupBox_OutImg_Table->sizePolicy().hasHeightForWidth());
        groupBox_OutImg_Table->setSizePolicy(sizePolicy8);
        gridLayout_30 = new QGridLayout(groupBox_OutImg_Table);
        gridLayout_30->setSpacing(3);
        gridLayout_30->setObjectName(QString::fromUtf8("gridLayout_30"));
        gridLayout_30->setContentsMargins(3, 0, 3, 0);
        checkBox_OutImg_Table_Stat = new QCheckBox(groupBox_OutImg_Table);
        checkBox_OutImg_Table_Stat->setObjectName(QString::fromUtf8("checkBox_OutImg_Table_Stat"));
        checkBox_OutImg_Table_Stat->setChecked(true);

        gridLayout_30->addWidget(checkBox_OutImg_Table_Stat, 1, 0, 1, 1);

        checkBox_OutImg_Table_Raw = new QCheckBox(groupBox_OutImg_Table);
        checkBox_OutImg_Table_Raw->setObjectName(QString::fromUtf8("checkBox_OutImg_Table_Raw"));
        checkBox_OutImg_Table_Raw->setChecked(true);

        gridLayout_30->addWidget(checkBox_OutImg_Table_Raw, 0, 0, 1, 1);

        verticalSpacer_OutImg_Table = new QSpacerItem(20, 133, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_30->addItem(verticalSpacer_OutImg_Table, 2, 0, 1, 1);


        gridLayout_27->addWidget(groupBox_OutImg_Table, 0, 1, 1, 1);


        gridLayout_25->addWidget(groupBox_OutImg, 0, 0, 1, 1);

        groupBox_OutStack = new QGroupBox(tab_Output);
        groupBox_OutStack->setObjectName(QString::fromUtf8("groupBox_OutStack"));
        groupBox_OutStack->setFlat(true);
        gridLayout_28 = new QGridLayout(groupBox_OutStack);
        gridLayout_28->setSpacing(3);
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        gridLayout_28->setContentsMargins(0, 0, 0, 0);
        groupBox_OutStack_Img = new QGroupBox(groupBox_OutStack);
        groupBox_OutStack_Img->setObjectName(QString::fromUtf8("groupBox_OutStack_Img"));
        sizePolicy8.setHeightForWidth(groupBox_OutStack_Img->sizePolicy().hasHeightForWidth());
        groupBox_OutStack_Img->setSizePolicy(sizePolicy8);
        gridLayout_31 = new QGridLayout(groupBox_OutStack_Img);
        gridLayout_31->setSpacing(3);
        gridLayout_31->setObjectName(QString::fromUtf8("gridLayout_31"));
        gridLayout_31->setContentsMargins(3, 0, 3, 0);
        checkBox_OutStack_Img_Plasma = new QCheckBox(groupBox_OutStack_Img);
        checkBox_OutStack_Img_Plasma->setObjectName(QString::fromUtf8("checkBox_OutStack_Img_Plasma"));
        checkBox_OutStack_Img_Plasma->setChecked(true);

        gridLayout_31->addWidget(checkBox_OutStack_Img_Plasma, 3, 0, 1, 1);

        checkBox_OutStack_Img_Nuclei = new QCheckBox(groupBox_OutStack_Img);
        checkBox_OutStack_Img_Nuclei->setObjectName(QString::fromUtf8("checkBox_OutStack_Img_Nuclei"));
        checkBox_OutStack_Img_Nuclei->setChecked(true);

        gridLayout_31->addWidget(checkBox_OutStack_Img_Nuclei, 2, 0, 1, 1);

        checkBox_OutStack_Img_Regions = new QCheckBox(groupBox_OutStack_Img);
        checkBox_OutStack_Img_Regions->setObjectName(QString::fromUtf8("checkBox_OutStack_Img_Regions"));
        checkBox_OutStack_Img_Regions->setChecked(true);

        gridLayout_31->addWidget(checkBox_OutStack_Img_Regions, 5, 0, 1, 1);

        checkBox_OutStack_Img_Foci = new QCheckBox(groupBox_OutStack_Img);
        checkBox_OutStack_Img_Foci->setObjectName(QString::fromUtf8("checkBox_OutStack_Img_Foci"));
        checkBox_OutStack_Img_Foci->setChecked(true);

        gridLayout_31->addWidget(checkBox_OutStack_Img_Foci, 4, 0, 1, 1);

        checkBox_OutStack_Img_Normal = new QCheckBox(groupBox_OutStack_Img);
        checkBox_OutStack_Img_Normal->setObjectName(QString::fromUtf8("checkBox_OutStack_Img_Normal"));
        checkBox_OutStack_Img_Normal->setChecked(true);

        gridLayout_31->addWidget(checkBox_OutStack_Img_Normal, 0, 0, 1, 1);

        checkBox_OutStack_Img_Contrast = new QCheckBox(groupBox_OutStack_Img);
        checkBox_OutStack_Img_Contrast->setObjectName(QString::fromUtf8("checkBox_OutStack_Img_Contrast"));
        checkBox_OutStack_Img_Contrast->setChecked(true);

        gridLayout_31->addWidget(checkBox_OutStack_Img_Contrast, 1, 0, 1, 1);

        verticalSpacer_OutStack_Img = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_31->addItem(verticalSpacer_OutStack_Img, 6, 0, 1, 1);


        gridLayout_28->addWidget(groupBox_OutStack_Img, 0, 0, 1, 1);

        groupBox_OutStack_Plots = new QGroupBox(groupBox_OutStack);
        groupBox_OutStack_Plots->setObjectName(QString::fromUtf8("groupBox_OutStack_Plots"));
        sizePolicy9.setHeightForWidth(groupBox_OutStack_Plots->sizePolicy().hasHeightForWidth());
        groupBox_OutStack_Plots->setSizePolicy(sizePolicy9);
        gridLayout_32 = new QGridLayout(groupBox_OutStack_Plots);
        gridLayout_32->setSpacing(3);
        gridLayout_32->setObjectName(QString::fromUtf8("gridLayout_32"));
        gridLayout_32->setContentsMargins(3, 0, 3, 0);
        checkBox_OutStack_Plots_FocNumberMean = new QCheckBox(groupBox_OutStack_Plots);
        checkBox_OutStack_Plots_FocNumberMean->setObjectName(QString::fromUtf8("checkBox_OutStack_Plots_FocNumberMean"));
        checkBox_OutStack_Plots_FocNumberMean->setEnabled(false);
        checkBox_OutStack_Plots_FocNumberMean->setChecked(true);
        checkBox_OutStack_Plots_FocNumberMean->setTristate(true);

        gridLayout_32->addWidget(checkBox_OutStack_Plots_FocNumberMean, 11, 0, 1, 1);

        checkBox_OutStack_Plots_CytArea_Sum = new QCheckBox(groupBox_OutStack_Plots);
        checkBox_OutStack_Plots_CytArea_Sum->setObjectName(QString::fromUtf8("checkBox_OutStack_Plots_CytArea_Sum"));
        checkBox_OutStack_Plots_CytArea_Sum->setEnabled(false);
        checkBox_OutStack_Plots_CytArea_Sum->setChecked(true);
        checkBox_OutStack_Plots_CytArea_Sum->setTristate(true);

        gridLayout_32->addWidget(checkBox_OutStack_Plots_CytArea_Sum, 7, 0, 1, 1);

        checkBox_OutStack_Plots_FocNumber_p_NucNumber = new QCheckBox(groupBox_OutStack_Plots);
        checkBox_OutStack_Plots_FocNumber_p_NucNumber->setObjectName(QString::fromUtf8("checkBox_OutStack_Plots_FocNumber_p_NucNumber"));
        checkBox_OutStack_Plots_FocNumber_p_NucNumber->setEnabled(false);
        checkBox_OutStack_Plots_FocNumber_p_NucNumber->setChecked(true);
        checkBox_OutStack_Plots_FocNumber_p_NucNumber->setTristate(true);

        gridLayout_32->addWidget(checkBox_OutStack_Plots_FocNumber_p_NucNumber, 12, 0, 1, 1);

        checkBox_OutStack_Plots_NucNumberSum = new QCheckBox(groupBox_OutStack_Plots);
        checkBox_OutStack_Plots_NucNumberSum->setObjectName(QString::fromUtf8("checkBox_OutStack_Plots_NucNumberSum"));
        checkBox_OutStack_Plots_NucNumberSum->setEnabled(false);
        checkBox_OutStack_Plots_NucNumberSum->setChecked(true);
        checkBox_OutStack_Plots_NucNumberSum->setTristate(true);

        gridLayout_32->addWidget(checkBox_OutStack_Plots_NucNumberSum, 4, 0, 1, 1);

        checkBox_OutStack_Plots_Hist = new QCheckBox(groupBox_OutStack_Plots);
        checkBox_OutStack_Plots_Hist->setObjectName(QString::fromUtf8("checkBox_OutStack_Plots_Hist"));
        checkBox_OutStack_Plots_Hist->setChecked(true);

        gridLayout_32->addWidget(checkBox_OutStack_Plots_Hist, 1, 0, 1, 1);

        checkBox_OutStack_Plots_Bar = new QCheckBox(groupBox_OutStack_Plots);
        checkBox_OutStack_Plots_Bar->setObjectName(QString::fromUtf8("checkBox_OutStack_Plots_Bar"));
        checkBox_OutStack_Plots_Bar->setChecked(true);

        gridLayout_32->addWidget(checkBox_OutStack_Plots_Bar, 0, 0, 1, 1);

        checkBox_OutStack_Plots_FocNumber_p_CytArea = new QCheckBox(groupBox_OutStack_Plots);
        checkBox_OutStack_Plots_FocNumber_p_CytArea->setObjectName(QString::fromUtf8("checkBox_OutStack_Plots_FocNumber_p_CytArea"));
        checkBox_OutStack_Plots_FocNumber_p_CytArea->setEnabled(false);
        checkBox_OutStack_Plots_FocNumber_p_CytArea->setChecked(true);
        checkBox_OutStack_Plots_FocNumber_p_CytArea->setTristate(true);

        gridLayout_32->addWidget(checkBox_OutStack_Plots_FocNumber_p_CytArea, 14, 0, 1, 1);

        checkBox_OutStack_Plots_NucAreaSum = new QCheckBox(groupBox_OutStack_Plots);
        checkBox_OutStack_Plots_NucAreaSum->setObjectName(QString::fromUtf8("checkBox_OutStack_Plots_NucAreaSum"));
        checkBox_OutStack_Plots_NucAreaSum->setEnabled(false);
        checkBox_OutStack_Plots_NucAreaSum->setChecked(true);
        checkBox_OutStack_Plots_NucAreaSum->setTristate(true);

        gridLayout_32->addWidget(checkBox_OutStack_Plots_NucAreaSum, 5, 0, 1, 1);

        line_OutStack_Plots = new QFrame(groupBox_OutStack_Plots);
        line_OutStack_Plots->setObjectName(QString::fromUtf8("line_OutStack_Plots"));
        line_OutStack_Plots->setFrameShape(QFrame::HLine);
        line_OutStack_Plots->setFrameShadow(QFrame::Sunken);

        gridLayout_32->addWidget(line_OutStack_Plots, 3, 0, 1, 1);

        checkBox_OutStack_Plots_FocAreaMean = new QCheckBox(groupBox_OutStack_Plots);
        checkBox_OutStack_Plots_FocAreaMean->setObjectName(QString::fromUtf8("checkBox_OutStack_Plots_FocAreaMean"));
        checkBox_OutStack_Plots_FocAreaMean->setEnabled(false);
        checkBox_OutStack_Plots_FocAreaMean->setChecked(true);
        checkBox_OutStack_Plots_FocAreaMean->setTristate(true);

        gridLayout_32->addWidget(checkBox_OutStack_Plots_FocAreaMean, 16, 0, 1, 1);

        checkBox_OutStack_Plots_Scatter = new QCheckBox(groupBox_OutStack_Plots);
        checkBox_OutStack_Plots_Scatter->setObjectName(QString::fromUtf8("checkBox_OutStack_Plots_Scatter"));
        checkBox_OutStack_Plots_Scatter->setChecked(true);

        gridLayout_32->addWidget(checkBox_OutStack_Plots_Scatter, 2, 0, 1, 1);

        checkBox_OutStack_Plots_CytAreaMean = new QCheckBox(groupBox_OutStack_Plots);
        checkBox_OutStack_Plots_CytAreaMean->setObjectName(QString::fromUtf8("checkBox_OutStack_Plots_CytAreaMean"));
        checkBox_OutStack_Plots_CytAreaMean->setEnabled(false);
        checkBox_OutStack_Plots_CytAreaMean->setChecked(true);
        checkBox_OutStack_Plots_CytAreaMean->setTristate(true);

        gridLayout_32->addWidget(checkBox_OutStack_Plots_CytAreaMean, 8, 0, 1, 1);

        checkBox_OutStack_Plots_FocAreaSum = new QCheckBox(groupBox_OutStack_Plots);
        checkBox_OutStack_Plots_FocAreaSum->setObjectName(QString::fromUtf8("checkBox_OutStack_Plots_FocAreaSum"));
        checkBox_OutStack_Plots_FocAreaSum->setEnabled(false);
        checkBox_OutStack_Plots_FocAreaSum->setChecked(true);
        checkBox_OutStack_Plots_FocAreaSum->setTristate(true);

        gridLayout_32->addWidget(checkBox_OutStack_Plots_FocAreaSum, 15, 0, 1, 1);

        checkBox_OutStack_Plots_FocNumber_p_NucArea = new QCheckBox(groupBox_OutStack_Plots);
        checkBox_OutStack_Plots_FocNumber_p_NucArea->setObjectName(QString::fromUtf8("checkBox_OutStack_Plots_FocNumber_p_NucArea"));
        checkBox_OutStack_Plots_FocNumber_p_NucArea->setEnabled(false);
        checkBox_OutStack_Plots_FocNumber_p_NucArea->setChecked(true);
        checkBox_OutStack_Plots_FocNumber_p_NucArea->setTristate(true);

        gridLayout_32->addWidget(checkBox_OutStack_Plots_FocNumber_p_NucArea, 13, 0, 1, 1);

        verticalSpacer_OutStack_Plots = new QSpacerItem(20, 24, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_32->addItem(verticalSpacer_OutStack_Plots, 18, 0, 1, 1);

        checkBox_OutStack_Plots_FocNumberSum = new QCheckBox(groupBox_OutStack_Plots);
        checkBox_OutStack_Plots_FocNumberSum->setObjectName(QString::fromUtf8("checkBox_OutStack_Plots_FocNumberSum"));
        checkBox_OutStack_Plots_FocNumberSum->setEnabled(false);
        checkBox_OutStack_Plots_FocNumberSum->setChecked(true);
        checkBox_OutStack_Plots_FocNumberSum->setTristate(true);

        gridLayout_32->addWidget(checkBox_OutStack_Plots_FocNumberSum, 10, 0, 1, 1);

        checkBox_OutStack_Plots_NucAreaMean = new QCheckBox(groupBox_OutStack_Plots);
        checkBox_OutStack_Plots_NucAreaMean->setObjectName(QString::fromUtf8("checkBox_OutStack_Plots_NucAreaMean"));
        checkBox_OutStack_Plots_NucAreaMean->setEnabled(false);
        checkBox_OutStack_Plots_NucAreaMean->setChecked(true);
        checkBox_OutStack_Plots_NucAreaMean->setTristate(true);

        gridLayout_32->addWidget(checkBox_OutStack_Plots_NucAreaMean, 6, 0, 1, 1);

        checkBox_OutStack_Plots_CytArea_p_NucArea = new QCheckBox(groupBox_OutStack_Plots);
        checkBox_OutStack_Plots_CytArea_p_NucArea->setObjectName(QString::fromUtf8("checkBox_OutStack_Plots_CytArea_p_NucArea"));
        checkBox_OutStack_Plots_CytArea_p_NucArea->setEnabled(false);
        checkBox_OutStack_Plots_CytArea_p_NucArea->setChecked(true);
        checkBox_OutStack_Plots_CytArea_p_NucArea->setTristate(true);

        gridLayout_32->addWidget(checkBox_OutStack_Plots_CytArea_p_NucArea, 9, 0, 1, 1);


        gridLayout_28->addWidget(groupBox_OutStack_Plots, 0, 2, 1, 1);

        groupBox_OutStack_Table = new QGroupBox(groupBox_OutStack);
        groupBox_OutStack_Table->setObjectName(QString::fromUtf8("groupBox_OutStack_Table"));
        sizePolicy8.setHeightForWidth(groupBox_OutStack_Table->sizePolicy().hasHeightForWidth());
        groupBox_OutStack_Table->setSizePolicy(sizePolicy8);
        gridLayout_29 = new QGridLayout(groupBox_OutStack_Table);
        gridLayout_29->setSpacing(3);
        gridLayout_29->setObjectName(QString::fromUtf8("gridLayout_29"));
        gridLayout_29->setContentsMargins(3, 0, 3, 0);
        checkBox_OutStack_Table_Raw = new QCheckBox(groupBox_OutStack_Table);
        checkBox_OutStack_Table_Raw->setObjectName(QString::fromUtf8("checkBox_OutStack_Table_Raw"));
        checkBox_OutStack_Table_Raw->setChecked(true);

        gridLayout_29->addWidget(checkBox_OutStack_Table_Raw, 0, 0, 1, 1);

        checkBox_OutStack_Table_Stat = new QCheckBox(groupBox_OutStack_Table);
        checkBox_OutStack_Table_Stat->setObjectName(QString::fromUtf8("checkBox_OutStack_Table_Stat"));
        checkBox_OutStack_Table_Stat->setChecked(true);

        gridLayout_29->addWidget(checkBox_OutStack_Table_Stat, 1, 0, 1, 1);

        verticalSpacer_OutStack_Table = new QSpacerItem(20, 280, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_29->addItem(verticalSpacer_OutStack_Table, 2, 0, 1, 1);


        gridLayout_28->addWidget(groupBox_OutStack_Table, 0, 1, 1, 1);


        gridLayout_25->addWidget(groupBox_OutStack, 1, 0, 1, 1);

        tabWidget->addTab(tab_Output, QString());

        gridLayout_13->addWidget(tabWidget, 0, 0, 1, 1);

        groupBox_Summary = new QGroupBox(groupBox_Settings);
        groupBox_Summary->setObjectName(QString::fromUtf8("groupBox_Summary"));
        groupBox_Summary->setFlat(true);
        gridLayout_6 = new QGridLayout(groupBox_Summary);
        gridLayout_6->setSpacing(3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(3, 3, 3, 3);
        tableWidget_Summary_CurrentCell_Single = new QTableWidget(groupBox_Summary);
        tableWidget_Summary_CurrentCell_Single->setObjectName(QString::fromUtf8("tableWidget_Summary_CurrentCell_Single"));
        QSizePolicy sizePolicy10(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy10.setHorizontalStretch(2);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(tableWidget_Summary_CurrentCell_Single->sizePolicy().hasHeightForWidth());
        tableWidget_Summary_CurrentCell_Single->setSizePolicy(sizePolicy10);

        gridLayout_6->addWidget(tableWidget_Summary_CurrentCell_Single, 0, 0, 1, 1);

        tableWidget_Summary_CurrentCell_Quotients = new QTableWidget(groupBox_Summary);
        tableWidget_Summary_CurrentCell_Quotients->setObjectName(QString::fromUtf8("tableWidget_Summary_CurrentCell_Quotients"));
        QSizePolicy sizePolicy11(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy11.setHorizontalStretch(3);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(tableWidget_Summary_CurrentCell_Quotients->sizePolicy().hasHeightForWidth());
        tableWidget_Summary_CurrentCell_Quotients->setSizePolicy(sizePolicy11);

        gridLayout_6->addWidget(tableWidget_Summary_CurrentCell_Quotients, 0, 1, 1, 1);


        gridLayout_13->addWidget(groupBox_Summary, 1, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_Settings, 0, 1, 1, 1);

        D_MAKRO_CoreFoci->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_CoreFoci);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1352, 21));
        menuLayout = new QMenu(menubar);
        menuLayout->setObjectName(QString::fromUtf8("menuLayout"));
        menuViewer = new QMenu(menubar);
        menuViewer->setObjectName(QString::fromUtf8("menuViewer"));
        menuData = new QMenu(menubar);
        menuData->setObjectName(QString::fromUtf8("menuData"));
        menuUpdate = new QMenu(menubar);
        menuUpdate->setObjectName(QString::fromUtf8("menuUpdate"));
        menuStack_Processing = new QMenu(menubar);
        menuStack_Processing->setObjectName(QString::fromUtf8("menuStack_Processing"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        D_MAKRO_CoreFoci->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_CoreFoci);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_CoreFoci->setStatusBar(statusbar);

        menubar->addAction(menuData->menuAction());
        menubar->addAction(menuLayout->menuAction());
        menubar->addAction(menuViewer->menuAction());
        menubar->addAction(menuUpdate->menuAction());
        menubar->addAction(menuStack_Processing->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menuLayout->addAction(action_Show_View_Nuclei);
        menuLayout->addAction(action_Show_View_Cytoplasma);
        menuLayout->addAction(action_Show_View_Foci);
        menuLayout->addAction(action_Show_View_Results);
        menuLayout->addAction(action_Show_Settings_and_Other);
        menuViewer->addAction(action_Smooth_Transformation);
        menuViewer->addAction(action_Keep_Aspect_Ratio);
        menuData->addAction(action_Load_Images);
        menuData->addAction(action_Next_Image);
        menuData->addSeparator();
        menuData->addAction(action_Clear_Images);
        menuData->addSeparator();
        menuData->addAction(action_Save_Image_Cores);
        menuData->addAction(action_Save_image_cytoplasma);
        menuData->addAction(action_Save_Image_Foci);
        menuData->addAction(action_Save_Image_Results);
        menuData->addSeparator();
        menuData->addAction(action_Save_plot_image);
        menuData->addAction(action_Save_plot_stack);
        menuUpdate->addAction(action_Update_All);
        menuUpdate->addSeparator();
        menuUpdate->addAction(action_Update_Cores);
        menuUpdate->addAction(action_Update_Foci);
        menuUpdate->addAction(action_Update_Results);
        menuUpdate->addSeparator();
        menuUpdate->addAction(action_Update_View);
        menuStack_Processing->addAction(action_Process_Stack);
        menuWindow->addAction(action_Show_Minimized);
        menuWindow->addAction(action_Show_Normal);
        menuWindow->addAction(action_Show_Maximized);
        menuWindow->addAction(action_Show_Fullscreen);

        retranslateUi(D_MAKRO_CoreFoci);
        QObject::connect(action_Show_View_Cytoplasma, SIGNAL(triggered(bool)), groupBox_View_Cyto, SLOT(setVisible(bool)));
        QObject::connect(action_Show_View_Foci, SIGNAL(triggered(bool)), groupBox_View_Foci, SLOT(setVisible(bool)));
        QObject::connect(action_Show_View_Nuclei, SIGNAL(triggered(bool)), groupBox_View_Cores, SLOT(setVisible(bool)));
        QObject::connect(action_Show_View_Results, SIGNAL(triggered(bool)), groupBox_View_Result, SLOT(setVisible(bool)));
        QObject::connect(action_Show_Settings_and_Other, SIGNAL(triggered(bool)), groupBox_Settings, SLOT(setVisible(bool)));
        QObject::connect(action_Show_Minimized, SIGNAL(triggered()), D_MAKRO_CoreFoci, SLOT(showMinimized()));
        QObject::connect(action_Show_Normal, SIGNAL(triggered()), D_MAKRO_CoreFoci, SLOT(showNormal()));
        QObject::connect(action_Show_Maximized, SIGNAL(triggered()), D_MAKRO_CoreFoci, SLOT(showMaximized()));
        QObject::connect(action_Show_Fullscreen, SIGNAL(triggered()), D_MAKRO_CoreFoci, SLOT(showFullScreen()));
        QObject::connect(comboBox_ResPlo_Cells_Type, SIGNAL(currentIndexChanged(int)), stackedWidget_ResPlo_Cells, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_ResPlo_Img_Type, SIGNAL(currentIndexChanged(int)), stackedWidget_ResPlo_Img, SLOT(setCurrentIndex(int)));

        tabWidget_View_Results->setCurrentIndex(1);
        stackedWidget_ResPlo_Cells->setCurrentIndex(0);
        stackedWidget_ResPlo_Img->setCurrentIndex(1);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(D_MAKRO_CoreFoci);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_CoreFoci)
    {
        D_MAKRO_CoreFoci->setWindowTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "MainWindow", nullptr));
        action_Smooth_Transformation->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Smooth Transformation", nullptr));
        action_Keep_Aspect_Ratio->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Keep Aspect Ratio", nullptr));
        action_Load_Images->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Load images to queue", nullptr));
#if QT_CONFIG(shortcut)
        action_Load_Images->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Update_All->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Update All", nullptr));
#if QT_CONFIG(shortcut)
        action_Update_All->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Update_Cores->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Update Cores", nullptr));
#if QT_CONFIG(shortcut)
        action_Update_Cores->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "F6", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Update_Foci->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Update Foci", nullptr));
#if QT_CONFIG(shortcut)
        action_Update_Foci->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "F7", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Update_Results->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Update Results", nullptr));
#if QT_CONFIG(shortcut)
        action_Update_Results->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "F8", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Update_View->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Update all Viewers", nullptr));
        action_Next_Image->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Next image", nullptr));
#if QT_CONFIG(shortcut)
        action_Next_Image->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Clear_Images->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Clear image queue", nullptr));
        action_Save_Image_Cores->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Save image nuclei", nullptr));
        action_Save_Image_Foci->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Save image foci", nullptr));
        action_Save_Image_Results->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Save image results", nullptr));
#if QT_CONFIG(shortcut)
        action_Save_Image_Results->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Stack_Process->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Process and Save Stack", nullptr));
#if QT_CONFIG(shortcut)
        action_Stack_Process->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Save_image_cytoplasma->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Save image cytoplasma", nullptr));
        action_Show_View_Nuclei->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Show View Nuclei", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_View_Nuclei->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_View_Cytoplasma->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Show View Cytoplasma", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_View_Cytoplasma->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_View_Foci->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Show View Foci", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_View_Foci->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "F3", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_View_Results->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Show View Results", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_View_Results->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "F4", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Settings_and_Other->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Show Settings and Other", nullptr));
        action_Show_Minimized->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Show Minimized", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Minimized->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "F9", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Normal->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Show Normal", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Normal->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "F10", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Maximized->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Show Maximized", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Maximized->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "F11", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Fullscreen->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Show Fullscreen", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Fullscreen->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "F12", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Process_Stack->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Process Stack", nullptr));
#if QT_CONFIG(shortcut)
        action_Process_Stack->setShortcut(QCoreApplication::translate("D_MAKRO_CoreFoci", "Ctrl+F5", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Save_plot_image->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Save plot image", nullptr));
        action_Save_plot_stack->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Save plot stack", nullptr));
        groupBox_View_Result->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "View - Result", nullptr));
        label_View_Result_R->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "R:", nullptr));
        comboBox_View_Result_R->setItemText(0, QCoreApplication::translate("D_MAKRO_CoreFoci", "Empty", nullptr));
        comboBox_View_Result_R->setItemText(1, QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei", nullptr));
        comboBox_View_Result_R->setItemText(2, QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei_Contrast", nullptr));
        comboBox_View_Result_R->setItemText(3, QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei_Binary", nullptr));
        comboBox_View_Result_R->setItemText(4, QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei_Seeds", nullptr));
        comboBox_View_Result_R->setItemText(5, QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei_Edges", nullptr));
        comboBox_View_Result_R->setItemText(6, QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma", nullptr));
        comboBox_View_Result_R->setItemText(7, QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma_Contrast", nullptr));
        comboBox_View_Result_R->setItemText(8, QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma_Binary", nullptr));
        comboBox_View_Result_R->setItemText(9, QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma_Edges", nullptr));
        comboBox_View_Result_R->setItemText(10, QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci", nullptr));
        comboBox_View_Result_R->setItemText(11, QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci_Contrast", nullptr));
        comboBox_View_Result_R->setItemText(12, QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci_Binary", nullptr));
        comboBox_View_Result_R->setItemText(13, QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci_Selected", nullptr));
        comboBox_View_Result_R->setItemText(14, QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci_Dot", nullptr));
        comboBox_View_Result_R->setItemText(15, QCoreApplication::translate("D_MAKRO_CoreFoci", "ROI", nullptr));
        comboBox_View_Result_R->setItemText(16, QCoreApplication::translate("D_MAKRO_CoreFoci", "ROI_Edges", nullptr));
        comboBox_View_Result_R->setItemText(17, QCoreApplication::translate("D_MAKRO_CoreFoci", "Regions_Edges", nullptr));

        label_View_Result_G->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "G:", nullptr));
        label_View_Result_B->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "B:", nullptr));
        comboBox_View_Result_G->setItemText(0, QCoreApplication::translate("D_MAKRO_CoreFoci", "Empty", nullptr));
        comboBox_View_Result_G->setItemText(1, QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei", nullptr));
        comboBox_View_Result_G->setItemText(2, QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei_Contrast", nullptr));
        comboBox_View_Result_G->setItemText(3, QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei_Binary", nullptr));
        comboBox_View_Result_G->setItemText(4, QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei_Seeds", nullptr));
        comboBox_View_Result_G->setItemText(5, QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei_Edges", nullptr));
        comboBox_View_Result_G->setItemText(6, QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma", nullptr));
        comboBox_View_Result_G->setItemText(7, QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma_Contrast", nullptr));
        comboBox_View_Result_G->setItemText(8, QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma_Binary", nullptr));
        comboBox_View_Result_G->setItemText(9, QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma_Edges", nullptr));
        comboBox_View_Result_G->setItemText(10, QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci", nullptr));
        comboBox_View_Result_G->setItemText(11, QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci_Contrast", nullptr));
        comboBox_View_Result_G->setItemText(12, QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci_Binary", nullptr));
        comboBox_View_Result_G->setItemText(13, QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci_Selected", nullptr));
        comboBox_View_Result_G->setItemText(14, QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci_Dot", nullptr));
        comboBox_View_Result_G->setItemText(15, QCoreApplication::translate("D_MAKRO_CoreFoci", "ROI", nullptr));
        comboBox_View_Result_G->setItemText(16, QCoreApplication::translate("D_MAKRO_CoreFoci", "ROI_Edges", nullptr));
        comboBox_View_Result_G->setItemText(17, QCoreApplication::translate("D_MAKRO_CoreFoci", "Regions_Edges", nullptr));

        comboBox_View_Result_B->setItemText(0, QCoreApplication::translate("D_MAKRO_CoreFoci", "Empty", nullptr));
        comboBox_View_Result_B->setItemText(1, QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei", nullptr));
        comboBox_View_Result_B->setItemText(2, QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei_Contrast", nullptr));
        comboBox_View_Result_B->setItemText(3, QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei_Binary", nullptr));
        comboBox_View_Result_B->setItemText(4, QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei_Seeds", nullptr));
        comboBox_View_Result_B->setItemText(5, QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei_Edges", nullptr));
        comboBox_View_Result_B->setItemText(6, QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma", nullptr));
        comboBox_View_Result_B->setItemText(7, QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma_Contrast", nullptr));
        comboBox_View_Result_B->setItemText(8, QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma_Binary", nullptr));
        comboBox_View_Result_B->setItemText(9, QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma_Edges", nullptr));
        comboBox_View_Result_B->setItemText(10, QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci", nullptr));
        comboBox_View_Result_B->setItemText(11, QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci_Contrast", nullptr));
        comboBox_View_Result_B->setItemText(12, QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci_Binary", nullptr));
        comboBox_View_Result_B->setItemText(13, QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci_Selected", nullptr));
        comboBox_View_Result_B->setItemText(14, QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci_Dot", nullptr));
        comboBox_View_Result_B->setItemText(15, QCoreApplication::translate("D_MAKRO_CoreFoci", "ROI", nullptr));
        comboBox_View_Result_B->setItemText(16, QCoreApplication::translate("D_MAKRO_CoreFoci", "ROI_Edges", nullptr));
        comboBox_View_Result_B->setItemText(17, QCoreApplication::translate("D_MAKRO_CoreFoci", "Regions_Edges", nullptr));

        pushButton_ResCol_Preset_NormalAll->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Normal", nullptr));
        pushButton_ResCol_Preset_ContrastAll->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Contrast", nullptr));
        pushButton_ResCol_Preset_NucSegmentation->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei", nullptr));
        pushButton_ResCol_Preset_Plasma->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Plasma", nullptr));
        pushButton_ResCol_Preset_Foci->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci", nullptr));
        pushButton_ResCol_Preset_Regions->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Regions", nullptr));
        tabWidget_View_Results->setTabText(tabWidget_View_Results->indexOf(tab_Result_Image), QCoreApplication::translate("D_MAKRO_CoreFoci", "Image", nullptr));
        label_ResPlo_Cells_Att_Hist_Classes->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Classes:", nullptr));
        checkBox_ResPlo_Cells_Att_Hist_Uni->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Uni", nullptr));
        checkBox_ResPlo_Cells_Att_Hist_Acc->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Acc", nullptr));
        tabWidget_View_Results->setTabText(tabWidget_View_Results->indexOf(tab_ResPlo_Cells), QCoreApplication::translate("D_MAKRO_CoreFoci", "Plot - Image", nullptr));
        tabWidget_View_Results->setTabText(tabWidget_View_Results->indexOf(tab_ResTab_Cells), QCoreApplication::translate("D_MAKRO_CoreFoci", "Table - Image", nullptr));
        label_ResPlo_Img_Att_Hist_Classes->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Classes:", nullptr));
        checkBox_ResPlo_Img_Att_Hist_Uni->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Uni", nullptr));
        checkBox_ResPlo_Img_Att_Hist_Acc->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Acc", nullptr));
        tabWidget_View_Results->setTabText(tabWidget_View_Results->indexOf(tab_ResPlo_Image), QCoreApplication::translate("D_MAKRO_CoreFoci", "Plot - Stack", nullptr));
        tabWidget_View_Results->setTabText(tabWidget_View_Results->indexOf(tab_ResTab_Image), QCoreApplication::translate("D_MAKRO_CoreFoci", "Table - Stack", nullptr));
        groupBox_View_Cyto->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "View - Cytoplasm", nullptr));
        comboBox_View_Cyto->setItemText(0, QCoreApplication::translate("D_MAKRO_CoreFoci", "00   -   Input Image   -   Loaded From File", nullptr));
        comboBox_View_Cyto->setItemText(1, QCoreApplication::translate("D_MAKRO_CoreFoci", "01   -   Input Image   -   Convert Depth to 8bit", nullptr));
        comboBox_View_Cyto->setItemText(2, QCoreApplication::translate("D_MAKRO_CoreFoci", "02   -   Input Image   -   Contrast Improved", nullptr));
        comboBox_View_Cyto->setItemText(3, QCoreApplication::translate("D_MAKRO_CoreFoci", "03   -   Input Image   -   Gauss Filter", nullptr));
        comboBox_View_Cyto->setItemText(4, QCoreApplication::translate("D_MAKRO_CoreFoci", "04   -   Binarization   -   Local Adaptive Thres", nullptr));
        comboBox_View_Cyto->setItemText(5, QCoreApplication::translate("D_MAKRO_CoreFoci", "05   -   Morphology   -   Closing Holes", nullptr));
        comboBox_View_Cyto->setItemText(6, QCoreApplication::translate("D_MAKRO_CoreFoci", "06   -   Morphology   -   Dilation", nullptr));
        comboBox_View_Cyto->setItemText(7, QCoreApplication::translate("D_MAKRO_CoreFoci", "07   -   Region   -   Cytoplasma", nullptr));
        comboBox_View_Cyto->setItemText(8, QCoreApplication::translate("D_MAKRO_CoreFoci", "08   -   Region   -   Cytoplasma Edges", nullptr));

        label_View_Cyto_Format_QI->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Format QI", nullptr));
        label_View_Cyto_Format_MA->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Format MA", nullptr));
        groupBox_View_Cores->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "View - Nuclei", nullptr));
        comboBox_View_Cores->setItemText(0, QCoreApplication::translate("D_MAKRO_CoreFoci", "00   -   Input Image   -   Loaded From File", nullptr));
        comboBox_View_Cores->setItemText(1, QCoreApplication::translate("D_MAKRO_CoreFoci", "01   -   Input Image   -   Convert Depth to 8bit", nullptr));
        comboBox_View_Cores->setItemText(2, QCoreApplication::translate("D_MAKRO_CoreFoci", "02   -   Input Image   -   Improved Contrast", nullptr));
        comboBox_View_Cores->setItemText(3, QCoreApplication::translate("D_MAKRO_CoreFoci", "03   -   Remove Noise   -   Gauss Filter", nullptr));
        comboBox_View_Cores->setItemText(4, QCoreApplication::translate("D_MAKRO_CoreFoci", "04   -   Binarization   -   Local Adaptive Mean", nullptr));
        comboBox_View_Cores->setItemText(5, QCoreApplication::translate("D_MAKRO_CoreFoci", "05   -   Binarization   -   Fill Holes by Area", nullptr));
        comboBox_View_Cores->setItemText(6, QCoreApplication::translate("D_MAKRO_CoreFoci", "06   -   Binarization   -   Invert", nullptr));
        comboBox_View_Cores->setItemText(7, QCoreApplication::translate("D_MAKRO_CoreFoci", "07   -   Distance   -   Transformation", nullptr));
        comboBox_View_Cores->setItemText(8, QCoreApplication::translate("D_MAKRO_CoreFoci", "08   -   Lokal Rank   -   Eilenstein Filter", nullptr));
        comboBox_View_Cores->setItemText(9, QCoreApplication::translate("D_MAKRO_CoreFoci", "09   -   Lokal Rank   -   Convert Depth to 8bit", nullptr));
        comboBox_View_Cores->setItemText(10, QCoreApplication::translate("D_MAKRO_CoreFoci", "10   -   Lokal Maxima   -   Binarization", nullptr));
        comboBox_View_Cores->setItemText(11, QCoreApplication::translate("D_MAKRO_CoreFoci", "11   -   Remove Small   -   Opening", nullptr));
        comboBox_View_Cores->setItemText(12, QCoreApplication::translate("D_MAKRO_CoreFoci", "12   -   Connect Near   -   Dilation", nullptr));
        comboBox_View_Cores->setItemText(13, QCoreApplication::translate("D_MAKRO_CoreFoci", "13   -   Segments   -   Watershade Transformation", nullptr));
        comboBox_View_Cores->setItemText(14, QCoreApplication::translate("D_MAKRO_CoreFoci", "14   -   Segments   -   Binary", nullptr));
        comboBox_View_Cores->setItemText(15, QCoreApplication::translate("D_MAKRO_CoreFoci", "15   -   Segments   -   Connect Small to nearby Big", nullptr));
        comboBox_View_Cores->setItemText(16, QCoreApplication::translate("D_MAKRO_CoreFoci", "16   -   Segments   -   Labels Final", nullptr));
        comboBox_View_Cores->setItemText(17, QCoreApplication::translate("D_MAKRO_CoreFoci", "17   -   Segments   -   Edges", nullptr));

        label_View_Cores_QI_Format->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Format QI", nullptr));
        label_View_Cores_MA_Format->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Format MA", nullptr));
        groupBox_View_Foci->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "View - Foci", nullptr));
        comboBox_View_Foci->setItemText(0, QCoreApplication::translate("D_MAKRO_CoreFoci", "00   -   Input Image   -   Loaded From File", nullptr));
        comboBox_View_Foci->setItemText(1, QCoreApplication::translate("D_MAKRO_CoreFoci", "01   -   Input Image   -   Converted Depth to 8bit", nullptr));
        comboBox_View_Foci->setItemText(2, QCoreApplication::translate("D_MAKRO_CoreFoci", "02   -   Input Image   -   Contrast Improved", nullptr));
        comboBox_View_Foci->setItemText(3, QCoreApplication::translate("D_MAKRO_CoreFoci", "03   -   Input Image   -   Remove Noise", nullptr));
        comboBox_View_Foci->setItemText(4, QCoreApplication::translate("D_MAKRO_CoreFoci", "04   -   Binarization   -   Local Adaptive Mean", nullptr));
        comboBox_View_Foci->setItemText(5, QCoreApplication::translate("D_MAKRO_CoreFoci", "05   -   ROI   -   Margin to Nuclei", nullptr));
        comboBox_View_Foci->setItemText(6, QCoreApplication::translate("D_MAKRO_CoreFoci", "06   -   ROI   -   Out of Nuclei and in Cytoplasma", nullptr));
        comboBox_View_Foci->setItemText(7, QCoreApplication::translate("D_MAKRO_CoreFoci", "07   -   ROI   -   Edges", nullptr));
        comboBox_View_Foci->setItemText(8, QCoreApplication::translate("D_MAKRO_CoreFoci", "08   -   ROI   -   Mask applyed", nullptr));
        comboBox_View_Foci->setItemText(9, QCoreApplication::translate("D_MAKRO_CoreFoci", "09   -   ROI  -   Connect near Foci", nullptr));
        comboBox_View_Foci->setItemText(10, QCoreApplication::translate("D_MAKRO_CoreFoci", "10   -   ROI   -   Select by Area", nullptr));
        comboBox_View_Foci->setItemText(11, QCoreApplication::translate("D_MAKRO_CoreFoci", "11   -   Centroid   -   Reduced to Centroid", nullptr));
        comboBox_View_Foci->setItemText(12, QCoreApplication::translate("D_MAKRO_CoreFoci", "12   -   Regions   -   Watershed of Nuclei in Cytoplasm", nullptr));
        comboBox_View_Foci->setItemText(13, QCoreApplication::translate("D_MAKRO_CoreFoci", "13   -   Regions   -   Convert to 8bit", nullptr));
        comboBox_View_Foci->setItemText(14, QCoreApplication::translate("D_MAKRO_CoreFoci", "14   -   Centroid   -   Assign to Cores", nullptr));

        label_View_Foci_QI_Format->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Format QI", nullptr));
        label_View_Foci_MA_Format->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Format MA", nullptr));
        groupBox_Settings->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Settings and Output", nullptr));
        groupBox_MikroPreset->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Mikroscope Presets", nullptr));
        pushButton_PresetActivate->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "preset -> settings", nullptr));
        groupBox_PageIndex->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Page Indices", nullptr));
        label_37->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei", nullptr));
        label_38->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci", nullptr));
        label_39->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasm", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_InputDefinition), QCoreApplication::translate("D_MAKRO_CoreFoci", "Input", nullptr));
        groupBox_File->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Image", nullptr));
        groupBox_Settings_Foci->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci", nullptr));
        label_7->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Black: Background, White: Potential foci", nullptr));
        label_6->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Size/Offset", nullptr));
        label_4->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "04", nullptr));
        label_3->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Bluring strength", nullptr));
        spinBox_SetFoci_02_Size->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        label_2->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Size/Sigma", nullptr));
        label->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "03", nullptr));
        spinBox_SetFoci_03_Size->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        label_8->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Size", nullptr));
        label_9->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Add margin to nuclei", nullptr));
        spinBox_SetFoci_04_Size->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        label_5->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "05", nullptr));
        label_13->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "09", nullptr));
        label_14->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Size", nullptr));
        label_15->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Connect near foci", nullptr));
        spinBox_SetFoci_05_Size->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        label_16->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "10", nullptr));
        label_17->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Area Min/Max", nullptr));
        label_18->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Select range of area allowed for foci", nullptr));
        spinBox_SetFoci_06_Size_Min->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        spinBox_SetFoci_06_Size_Max->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        label_32->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "15", nullptr));
        label_31->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Options", nullptr));
        checkBox_SetFoci_13_ExcludeBordered->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Exclude bordered", nullptr));
        label_33->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Segmentation (Cells and Analysis)", nullptr));
        groupBox_Settings_Cores->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei", nullptr));
        spinBox_SetCore_14_AreaMinOfBig->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        label_SetCore_04_Thres_Desription->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Black: Nuclei, White: Background", nullptr));
        label_SetCore_05_Fill_Title->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Area", nullptr));
        label_SetCore_08_Desription->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Eilenstein filter", nullptr));
        label_SetCore_02_Gauss_Pos->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "03", nullptr));
        label_SetCore_04_Thres_Pos->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "04", nullptr));
        label_SetCore_02_Gauss_Title->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Size/Sigma", nullptr));
        label_SetCore_12_Open_Pos->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "11", nullptr));
        spinBox_SetCore_09_Eilenstein_Size->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        label_SetCore_12_Open_Desription->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Remove small and disconnect big objects", nullptr));
        label_SetCore_12_Open_Title->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Size", nullptr));
        label_SetCore_09_Eilenstein_Pos->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "08", nullptr));
        label_SetCore_09_Eilenstein_Title->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Size/Offset", nullptr));
        spinBox_SetCore_12_Open_Area->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        label_SetCore_04_Thres_Title->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Size/Offset", nullptr));
        spinBox_SetCore_02_Gauss_Size->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        spinBox_SetCore_04_Thres_Size->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        label_SetCore_02_Gauss_Desription->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Bluring strength", nullptr));
        label_SetCore_05_Fill_Description->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Fill holes in nuclei", nullptr));
        spinBox_SetCore_05_Fill_Area->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        label_SetCore_05_Fill_Pos->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "05", nullptr));
        label_SetCore_13_Dilation_Pos->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "12", nullptr));
        label_SetCore_13_Dilation_Description->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Minimum size / connect near", nullptr));
        label_SetCore_11_Thresh_Pos->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "10", nullptr));
        spinBox_SetCore_13_Dilation_Size->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        label_SetCore_11_Thresh_Desription->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Local maxima", nullptr));
        label_SetCore_11_Thresh_Title->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Threshold", nullptr));
        label_SetCore_13_Dilation_Title->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Size", nullptr));
        label_34->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "13", nullptr));
        label_35->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Options", nullptr));
        label_36->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Segmentation (Nuclei)", nullptr));
        checkBox_SetCore_13_ExcludeBordered->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Exclude  bordered", nullptr));
        label_41->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Area", nullptr));
        spinBox_SetCore_14_AreaMaxOfSmall->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        label_42->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Small (max of) connect with big (min of)", nullptr));
        label_43->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Distance", nullptr));
        label_40->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "15", nullptr));
        label_44->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Distance interval for connecting objects", nullptr));
        spinBox_SetCore_14_AreaDistMin->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        spinBox_SetCore_14_AreaDistMax->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        groupBox_Settings_Cyto->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma", nullptr));
        label_11->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Size/Sigma", nullptr));
        spinBox_SetCyto_Gauss_Size->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        label_10->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "03", nullptr));
        label_20->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Size", nullptr));
        label_19->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "05", nullptr));
        label_22->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Add margin to cytoplasma", nullptr));
        spinBox_SetCyto_Dilation_Size->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        spinBox_SetCyto_Closing_Size->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        label_21->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Closing holes", nullptr));
        label_12->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Bluring strength", nullptr));
        label_23->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "06", nullptr));
        label_24->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Size", nullptr));
        label_28->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "04", nullptr));
        label_29->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Size/Offset", nullptr));
        label_30->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Black: Backgr., White: Cytoplasma", nullptr));
        spinBox_SetCyto_Thresh_Size->setSuffix(QCoreApplication::translate("D_MAKRO_CoreFoci", "px", nullptr));
        groupBox_Results->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Results", nullptr));
        label_27->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Col", nullptr));
        label_25->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Max Expected", nullptr));
        label_26->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Range to spread to 8bit for visualisation", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Settings), QCoreApplication::translate("D_MAKRO_CoreFoci", "Settings", nullptr));
        groupBox_OutImg->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Images", nullptr));
        groupBox_OutImg_Img->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Images", nullptr));
        checkBox_OutImg_Img_Plasma->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Plasma", nullptr));
        checkBox_OutImg_Img_Contrast->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Contrast", nullptr));
        checkBox_OutImg_Img_ProcSteps->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Processing Steps", nullptr));
        checkBox_OutImg_Img_Nuclei->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei", nullptr));
        checkBox_OutImg_Img_Foci->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci", nullptr));
        checkBox_OutImg_Img_Regions->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Regions", nullptr));
        checkBox_OutImg_Img_Normal->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Normal", nullptr));
        groupBox_OutImg_Plots->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Plots", nullptr));
        checkBox_OutImg_Plots_FocArea->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci Area", nullptr));
        checkBox_OutImg_Plots_Bar->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Attributes Bar", nullptr));
        checkBox_OutImg_Plots_Hist->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Attributes Histogram", nullptr));
        checkBox_OutImg_Plots_FocNumber->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci Number", nullptr));
        checkBox_OutImg_Plots_CytArea->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma Area", nullptr));
        checkBox_OutImg_Plots_Scatter->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Attributes Scatter", nullptr));
        checkBox_OutImg_Plots_NucArea->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Nucleus Area", nullptr));
        checkBox_OutImg_Plots_NucMeanInt->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Nucleus Mean Intensity", nullptr));
        groupBox_OutImg_Table->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Tables", nullptr));
        checkBox_OutImg_Table_Stat->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Attributes Stats", nullptr));
        checkBox_OutImg_Table_Raw->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Attributes Raw", nullptr));
        groupBox_OutStack->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Stack", nullptr));
        groupBox_OutStack_Img->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Images", nullptr));
        checkBox_OutStack_Img_Plasma->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Plasma", nullptr));
        checkBox_OutStack_Img_Nuclei->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei", nullptr));
        checkBox_OutStack_Img_Regions->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Regions", nullptr));
        checkBox_OutStack_Img_Foci->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci", nullptr));
        checkBox_OutStack_Img_Normal->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Normal", nullptr));
        checkBox_OutStack_Img_Contrast->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Contrast", nullptr));
        groupBox_OutStack_Plots->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Plots", nullptr));
        checkBox_OutStack_Plots_FocNumberMean->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci Number Mean", nullptr));
        checkBox_OutStack_Plots_CytArea_Sum->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma Area Sum", nullptr));
        checkBox_OutStack_Plots_FocNumber_p_NucNumber->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci Number / Nuclei Number", nullptr));
        checkBox_OutStack_Plots_NucNumberSum->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei Number Sum", nullptr));
        checkBox_OutStack_Plots_Hist->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Attributes Histogram", nullptr));
        checkBox_OutStack_Plots_Bar->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Attributes Bar", nullptr));
        checkBox_OutStack_Plots_FocNumber_p_CytArea->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci Number / Cytoplasma Area", nullptr));
        checkBox_OutStack_Plots_NucAreaSum->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei Area Sum", nullptr));
        checkBox_OutStack_Plots_FocAreaMean->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci Area Mean", nullptr));
        checkBox_OutStack_Plots_Scatter->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Attributes Scatter", nullptr));
        checkBox_OutStack_Plots_CytAreaMean->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma Area Mean", nullptr));
        checkBox_OutStack_Plots_FocAreaSum->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci Area Sum", nullptr));
        checkBox_OutStack_Plots_FocNumber_p_NucArea->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci Number / Nuclei Area", nullptr));
        checkBox_OutStack_Plots_FocNumberSum->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Foci Number Sum", nullptr));
        checkBox_OutStack_Plots_NucAreaMean->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Nuclei Area Mean", nullptr));
        checkBox_OutStack_Plots_CytArea_p_NucArea->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Cytoplasma Area / Nuclei Area", nullptr));
        groupBox_OutStack_Table->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Tables", nullptr));
        checkBox_OutStack_Table_Raw->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Attributes Raw", nullptr));
        checkBox_OutStack_Table_Stat->setText(QCoreApplication::translate("D_MAKRO_CoreFoci", "Attributes Stats", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Output), QCoreApplication::translate("D_MAKRO_CoreFoci", "Output", nullptr));
        groupBox_Summary->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Summary (current image)", nullptr));
        menuLayout->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Layout", nullptr));
        menuViewer->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Viewer", nullptr));
        menuData->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Data", nullptr));
        menuUpdate->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Update", nullptr));
        menuStack_Processing->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Stack", nullptr));
        menuWindow->setTitle(QCoreApplication::translate("D_MAKRO_CoreFoci", "Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_CoreFoci: public Ui_D_MAKRO_CoreFoci {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_COREFOCI_H
