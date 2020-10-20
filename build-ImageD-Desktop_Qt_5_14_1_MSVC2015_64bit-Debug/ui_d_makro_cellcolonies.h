/********************************************************************************
** Form generated from reading UI file 'd_makro_cellcolonies.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_CELLCOLONIES_H
#define UI_D_MAKRO_CELLCOLONIES_H

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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_CellColonies
{
public:
    QAction *action_Show_Normal;
    QAction *action_Show_Minimize;
    QAction *action_Show_Maximize;
    QAction *action_Show_Fullscreen;
    QAction *action_Load_Images;
    QAction *action_Clear_Queue;
    QAction *action_Show_Processing;
    QAction *action_Show_Results;
    QAction *action_Smooth_Transformation;
    QAction *action_Keep_Aspect_Ratio;
    QAction *action_Update_View;
    QAction *action_Update_ImgProc;
    QAction *action_Next_Image;
    QAction *action_Last_Image;
    QAction *action_Show_Control;
    QAction *action_Save_Image_Cells;
    QAction *action_Save_Image_Color;
    QAction *action_Save_Plot_Value_in_Colony;
    QAction *action_Save_Plot_Colony_in_Image;
    QAction *action_Save_Image_Surrival;
    QAction *action_Save_Image_Segmentation;
    QAction *action_Save_whole_Analysis;
    QAction *action_Analyze_Stack;
    QAction *action_Save_Plot_Surrival;
    QAction *action_Save_Image_Attribute;
    QAction *action_SettingsReset;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_ResView;
    QGridLayout *gridLayout_5;
    QTabWidget *tabWidget_Res;
    QWidget *tab_Res_Image;
    QGridLayout *gridLayout_6;
    QComboBox *comboBox_ResImg_Color;
    QLabel *label_28;
    QLabel *label_27;
    QComboBox *comboBox_ResImg_Binary;
    QGraphicsView *graphicsView_ResImg;
    QWidget *tab_Res_Plot;
    QGridLayout *gridLayout_10;
    QComboBox *comboBox_Res_PlotType;
    QStackedWidget *stackedWidget_ResPlo_Type;
    QWidget *page_His_Colony;
    QGridLayout *gridLayout_11;
    QFrame *line_5;
    QCheckBox *checkBox_ResPlo_HisCol_Uniform;
    QSpinBox *spinBox_ResPlo_HisCol_ClassCount;
    QCheckBox *checkBox_ResPlo_HisCol_Accumulate;
    QComboBox *comboBox_ResPlo_HisCol_Typ;
    QWidget *page_Stat_Compare;
    QGridLayout *gridLayout_9;
    QLabel *label_6;
    QComboBox *comboBox_ResPlo_StatComp_X_Stat;
    QFrame *line_4;
    QLabel *label_29;
    QComboBox *comboBox_ResPlo_StatComp_Y_Stat;
    QComboBox *comboBox_ResPlo_StatComp_X_Typ;
    QComboBox *comboBox_ResPlo_StatComp_Y_Typ;
    QWidget *page_MeanMedian;
    QGridLayout *gridLayout_12;
    QComboBox *comboBox_ResPlo_MM_Typ;
    QCheckBox *checkBox_ResPlo_MM_Median;
    QCheckBox *checkBox_ResPlo_MM_Mean;
    QCheckBox *checkBox_ResPlo_MM_SD;
    QCheckBox *checkBox_ResPlo_MM_ADM;
    QFrame *line_6;
    QWidget *page_CSK;
    QGridLayout *gridLayout_13;
    QCheckBox *checkBox_ResPlo_CSK_CV;
    QCheckBox *checkBox_ResPlo_CSK_Skewness;
    QCheckBox *checkBox_ResPlo_CSK_Kurtosis;
    QComboBox *comboBox_ResPlo_CSK_Typ;
    QWidget *page_Quantiles;
    QGridLayout *gridLayout_14;
    QComboBox *comboBox_ResPlo_Quant_Steps;
    QLabel *label_30;
    QComboBox *comboBox_ResPlo_Quant_Typ;
    QWidget *page_TransRadial;
    QGridLayout *gridLayout_32;
    QGridLayout *gridLayout_ResPlo;
    QWidget *tab_Res_Plot_Img;
    QGridLayout *gridLayout_16;
    QComboBox *comboBox_Res_PlotType_Img;
    QStackedWidget *stackedWidget_ResPlo_Type_Img;
    QWidget *page_ResPlo_Hist_Img;
    QGridLayout *gridLayout_17;
    QComboBox *comboBox_ResPlo_HisImg_Attribute;
    QFrame *line_7;
    QSpinBox *spinBox_ResPlo_HisImg_ClassCount;
    QFrame *line_8;
    QCheckBox *checkBox_ResPlo_HisImg_Uniform;
    QCheckBox *checkBox_ResPlo_HisImg_Accumulate;
    QWidget *page_ResPlo_StatComp_Img;
    QGridLayout *gridLayout_15;
    QFrame *line_9;
    QComboBox *comboBox_ResPlo_StatComp_Img_Y_Attribute;
    QLabel *label_31;
    QComboBox *comboBox_ResPlo_StatComp_Img_X_Attribute;
    QLabel *label_32;
    QGridLayout *gridLayout_ResPlo_Img;
    QWidget *tab_res_Surrival;
    QGridLayout *gridLayout_19;
    QGraphicsView *graphicsView_Surrival;
    QWidget *tab_res_Segmentation;
    QGridLayout *gridLayout_21;
    QGraphicsView *graphicsView_Segmentation;
    QWidget *tab_res_Attribute;
    QGridLayout *gridLayout_31;
    QLabel *label_15;
    QComboBox *comboBox_ResAtt_BaseImage;
    QLabel *label_21;
    QComboBox *comboBox_ResAtt_Attribute;
    QFrame *line;
    QCheckBox *checkBox_ResAtt_Border;
    QLabel *label_46;
    QSpinBox *spinBox_ResAtt_Precision;
    QFrame *line_2;
    QLabel *label_45;
    QDoubleSpinBox *doubleSpinBox_ResAtt_Scale;
    QLabel *label_47;
    QSpinBox *spinBox_ResAtt_Tickness;
    QGraphicsView *graphicsView_Attribute;
    QGroupBox *groupBox_ProcView;
    QGridLayout *gridLayout_4;
    QLabel *label_ProcView_MA;
    QLabel *label_ProcView_QI;
    QComboBox *comboBox_ProcView_Step;
    QLabel *label_5;
    QGraphicsView *graphicsView_Cells;
    QGroupBox *groupBox_Control;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_Results;
    QGridLayout *gridLayout_23;
    QGridLayout *gridLayout_ResPlo_Surrival;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_ResPloSur_prz_dead;
    QLabel *label_ResPloSur_prz_surrival;
    QLabel *label_24;
    QLabel *label_ResPloSur_count_surrival;
    QLabel *label_ResPloSur_count_dead;
    QLabel *label_ResPloSur_count_detected;
    QTabWidget *tabWidget_Control;
    QWidget *tab_Processing;
    QGridLayout *gridLayout_24;
    QGroupBox *groupBox_Seedds;
    QGridLayout *gridLayout_3;
    QLabel *label_16;
    QSpinBox *spinBox_ProcCon_Seed_Blur_Size;
    QDoubleSpinBox *doubleSpinBox_ProcCon_Seed_Blur_Sigma;
    QLabel *label_17;
    QLabel *label_18;
    QSpinBox *spinBox_ProcCon_Thres_Size;
    QDoubleSpinBox *doubleSpinBox_ProcCon_Thres_Offset;
    QLabel *label_20;
    QLabel *label_22;
    QSpinBox *spinBox_ProcCon_Seed_Open_Size;
    QLabel *label_23;
    QLabel *label_37;
    QLabel *label_38;
    QDoubleSpinBox *doubleSpinBox_Separtate_Asphere_Thres;
    QDoubleSpinBox *doubleSpinBox_Extract_Asphere_Thres;
    QLabel *label_39;
    QLabel *label_40;
    QGroupBox *groupBox_Segmentation;
    QGridLayout *gridLayout_20;
    QLabel *label_25;
    QCheckBox *checkBox_ProcCon_Watershed_Border;
    QCheckBox *checkBox_ProcCon_Watershed_nSeed;
    QLabel *label_26;
    QGroupBox *groupBox_Reference_Input;
    QGridLayout *gridLayout_18;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_ProcCon_ROI_X1;
    QDoubleSpinBox *doubleSpinBox_ProcCon_ROI_X2;
    QDoubleSpinBox *doubleSpinBox_ProcCon_ROI_Y1;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_ProcCon_ROI_Y2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinBox_ProcCon_Ref_Blur_Size;
    QDoubleSpinBox *doubleSpinBox_ProcCon_Ref_Blur_Sigma;
    QGroupBox *groupBox_Stack;
    QGridLayout *gridLayout_7;
    QComboBox *comboBox_ProcView_Image;
    QGroupBox *groupBox_Foreground;
    QGridLayout *gridLayout_8;
    QSpinBox *spinBox_ProcCon_ColGrab_H_Min;
    QLabel *label_9;
    QSpinBox *spinBox_ProcCon_ColGrab_V_Min;
    QSpinBox *spinBox_ProcCon_ColGrab_H_Max;
    QLabel *label_10;
    QSpinBox *spinBox_ProcCon_ColGrab_S_Min;
    QSpinBox *spinBox_ProcCon_ColGrab_V_Max;
    QSpinBox *spinBox_ProcCon_ColGrab_S_Max;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_12;
    QLabel *label_35;
    QLabel *label_36;
    QSpinBox *spinBox_ProcCon_CellCol_Black_Noise;
    QSpinBox *spinBox_ProcCon_CellCol_White_Noise;
    QGroupBox *groupBox_Measure;
    QGridLayout *gridLayout_30;
    QLabel *label_41;
    QDoubleSpinBox *doubleSpinBox_Measure_Base;
    QDoubleSpinBox *doubleSpinBox_Measure_Factor;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_44;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_Output;
    QGridLayout *gridLayout_28;
    QGroupBox *groupBox_Output_Img;
    QGridLayout *gridLayout_34;
    QGroupBox *groupBox_Output_Img_Images;
    QGridLayout *gridLayout_26;
    QCheckBox *checkBox_Output_CellCount;
    QCheckBox *checkBox_Output_Labeling;
    QCheckBox *checkBox_Output_Surrival;
    QCheckBox *checkBox_Output_Segmentation;
    QCheckBox *checkBox_Output_Area;
    QCheckBox *checkBox_Output_ProcSteps;
    QGroupBox *groupBox_Output_Img_Plots;
    QGridLayout *gridLayout_33;
    QCheckBox *checkBox_Output_Plot_Img_Hist;
    QCheckBox *checkBox_Output_Plot_Img_Surrival;
    QCheckBox *checkBox_Output_Plot_Img_Scatter;
    QGroupBox *groupBox_Output_Img_CSV;
    QGridLayout *gridLayout_25;
    QSpacerItem *verticalSpacer;
    QCheckBox *checkBox_Output_CSV_Parameter;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_Output_Col;
    QGridLayout *gridLayout_35;
    QGroupBox *groupBox_Output_Col_Plots;
    QGridLayout *gridLayout_29;
    QCheckBox *checkBox_Output_Plot_Col_ADM;
    QCheckBox *checkBox_Output_Plot_Col_CV;
    QCheckBox *checkBox_Output_Plot_Col_SD;
    QCheckBox *checkBox_Output_Plot_Col_Mean;
    QCheckBox *checkBox_Output_Plot_Col_Median;
    QCheckBox *checkBox_Output_Plot_Col_Hist;
    QCheckBox *checkBox_Output_Plot_Col_Quantiles;
    QCheckBox *checkBox_Output_Plot_Col_Skewness;
    QCheckBox *checkBox_Output_Plot_Col_Kurtosis;
    QGroupBox *groupBox_Output_Col_CSV;
    QGridLayout *gridLayout_27;
    QCheckBox *checkBox_Output_CSV_Results;
    QCheckBox *checkBox_Output_CSV_RawData;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_Output_Col_Types;
    QGridLayout *gridLayout_36;
    QCheckBox *checkBox_Output_Absorbtion;
    QCheckBox *checkBox_Output_Transmission;
    QCheckBox *checkBox_Output_TransmissionRadial;
    QCheckBox *checkBox_Output_CellDensity;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_37;
    QCheckBox *checkBox_Output_TransRad;
    QGroupBox *groupBox_Surrival;
    QGridLayout *gridLayout_22;
    QLabel *label_11;
    QLabel *label_19;
    QDoubleSpinBox *doubleSpinBox_Sur_CellCount;
    QMenuBar *menubar;
    QMenu *menuData;
    QMenu *menuLayout;
    QMenu *menuViewer;
    QMenu *menuUpdate;
    QMenu *menuWindow;
    QMenu *menuStack;
    QMenu *menuSettings;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_CellColonies)
    {
        if (D_MAKRO_CellColonies->objectName().isEmpty())
            D_MAKRO_CellColonies->setObjectName(QString::fromUtf8("D_MAKRO_CellColonies"));
        D_MAKRO_CellColonies->resize(1144, 941);
        action_Show_Normal = new QAction(D_MAKRO_CellColonies);
        action_Show_Normal->setObjectName(QString::fromUtf8("action_Show_Normal"));
        action_Show_Minimize = new QAction(D_MAKRO_CellColonies);
        action_Show_Minimize->setObjectName(QString::fromUtf8("action_Show_Minimize"));
        action_Show_Maximize = new QAction(D_MAKRO_CellColonies);
        action_Show_Maximize->setObjectName(QString::fromUtf8("action_Show_Maximize"));
        action_Show_Fullscreen = new QAction(D_MAKRO_CellColonies);
        action_Show_Fullscreen->setObjectName(QString::fromUtf8("action_Show_Fullscreen"));
        action_Load_Images = new QAction(D_MAKRO_CellColonies);
        action_Load_Images->setObjectName(QString::fromUtf8("action_Load_Images"));
        action_Clear_Queue = new QAction(D_MAKRO_CellColonies);
        action_Clear_Queue->setObjectName(QString::fromUtf8("action_Clear_Queue"));
        action_Show_Processing = new QAction(D_MAKRO_CellColonies);
        action_Show_Processing->setObjectName(QString::fromUtf8("action_Show_Processing"));
        action_Show_Processing->setCheckable(true);
        action_Show_Processing->setChecked(true);
        action_Show_Results = new QAction(D_MAKRO_CellColonies);
        action_Show_Results->setObjectName(QString::fromUtf8("action_Show_Results"));
        action_Show_Results->setCheckable(true);
        action_Show_Results->setChecked(true);
        action_Smooth_Transformation = new QAction(D_MAKRO_CellColonies);
        action_Smooth_Transformation->setObjectName(QString::fromUtf8("action_Smooth_Transformation"));
        action_Smooth_Transformation->setCheckable(true);
        action_Smooth_Transformation->setChecked(true);
        action_Keep_Aspect_Ratio = new QAction(D_MAKRO_CellColonies);
        action_Keep_Aspect_Ratio->setObjectName(QString::fromUtf8("action_Keep_Aspect_Ratio"));
        action_Keep_Aspect_Ratio->setCheckable(true);
        action_Keep_Aspect_Ratio->setChecked(true);
        action_Update_View = new QAction(D_MAKRO_CellColonies);
        action_Update_View->setObjectName(QString::fromUtf8("action_Update_View"));
        action_Update_ImgProc = new QAction(D_MAKRO_CellColonies);
        action_Update_ImgProc->setObjectName(QString::fromUtf8("action_Update_ImgProc"));
        action_Next_Image = new QAction(D_MAKRO_CellColonies);
        action_Next_Image->setObjectName(QString::fromUtf8("action_Next_Image"));
        action_Last_Image = new QAction(D_MAKRO_CellColonies);
        action_Last_Image->setObjectName(QString::fromUtf8("action_Last_Image"));
        action_Show_Control = new QAction(D_MAKRO_CellColonies);
        action_Show_Control->setObjectName(QString::fromUtf8("action_Show_Control"));
        action_Show_Control->setCheckable(true);
        action_Show_Control->setChecked(true);
        action_Save_Image_Cells = new QAction(D_MAKRO_CellColonies);
        action_Save_Image_Cells->setObjectName(QString::fromUtf8("action_Save_Image_Cells"));
        action_Save_Image_Color = new QAction(D_MAKRO_CellColonies);
        action_Save_Image_Color->setObjectName(QString::fromUtf8("action_Save_Image_Color"));
        action_Save_Plot_Value_in_Colony = new QAction(D_MAKRO_CellColonies);
        action_Save_Plot_Value_in_Colony->setObjectName(QString::fromUtf8("action_Save_Plot_Value_in_Colony"));
        action_Save_Plot_Colony_in_Image = new QAction(D_MAKRO_CellColonies);
        action_Save_Plot_Colony_in_Image->setObjectName(QString::fromUtf8("action_Save_Plot_Colony_in_Image"));
        action_Save_Image_Surrival = new QAction(D_MAKRO_CellColonies);
        action_Save_Image_Surrival->setObjectName(QString::fromUtf8("action_Save_Image_Surrival"));
        action_Save_Image_Segmentation = new QAction(D_MAKRO_CellColonies);
        action_Save_Image_Segmentation->setObjectName(QString::fromUtf8("action_Save_Image_Segmentation"));
        action_Save_whole_Analysis = new QAction(D_MAKRO_CellColonies);
        action_Save_whole_Analysis->setObjectName(QString::fromUtf8("action_Save_whole_Analysis"));
        action_Analyze_Stack = new QAction(D_MAKRO_CellColonies);
        action_Analyze_Stack->setObjectName(QString::fromUtf8("action_Analyze_Stack"));
        action_Save_Plot_Surrival = new QAction(D_MAKRO_CellColonies);
        action_Save_Plot_Surrival->setObjectName(QString::fromUtf8("action_Save_Plot_Surrival"));
        action_Save_Image_Attribute = new QAction(D_MAKRO_CellColonies);
        action_Save_Image_Attribute->setObjectName(QString::fromUtf8("action_Save_Image_Attribute"));
        action_SettingsReset = new QAction(D_MAKRO_CellColonies);
        action_SettingsReset->setObjectName(QString::fromUtf8("action_SettingsReset"));
        centralwidget = new QWidget(D_MAKRO_CellColonies);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_ResView = new QGroupBox(centralwidget);
        groupBox_ResView->setObjectName(QString::fromUtf8("groupBox_ResView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(groupBox_ResView->sizePolicy().hasHeightForWidth());
        groupBox_ResView->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(groupBox_ResView);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tabWidget_Res = new QTabWidget(groupBox_ResView);
        tabWidget_Res->setObjectName(QString::fromUtf8("tabWidget_Res"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget_Res->sizePolicy().hasHeightForWidth());
        tabWidget_Res->setSizePolicy(sizePolicy1);
        tab_Res_Image = new QWidget();
        tab_Res_Image->setObjectName(QString::fromUtf8("tab_Res_Image"));
        gridLayout_6 = new QGridLayout(tab_Res_Image);
        gridLayout_6->setSpacing(3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(6, 6, 6, 6);
        comboBox_ResImg_Color = new QComboBox(tab_Res_Image);
        comboBox_ResImg_Color->addItem(QString());
        comboBox_ResImg_Color->addItem(QString());
        comboBox_ResImg_Color->addItem(QString());
        comboBox_ResImg_Color->addItem(QString());
        comboBox_ResImg_Color->addItem(QString());
        comboBox_ResImg_Color->addItem(QString());
        comboBox_ResImg_Color->addItem(QString());
        comboBox_ResImg_Color->setObjectName(QString::fromUtf8("comboBox_ResImg_Color"));

        gridLayout_6->addWidget(comboBox_ResImg_Color, 0, 1, 1, 1);

        label_28 = new QLabel(tab_Res_Image);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMaximumSize(QSize(35, 16777215));

        gridLayout_6->addWidget(label_28, 0, 2, 1, 1);

        label_27 = new QLabel(tab_Res_Image);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMaximumSize(QSize(35, 16777215));

        gridLayout_6->addWidget(label_27, 0, 0, 1, 1);

        comboBox_ResImg_Binary = new QComboBox(tab_Res_Image);
        comboBox_ResImg_Binary->addItem(QString());
        comboBox_ResImg_Binary->addItem(QString());
        comboBox_ResImg_Binary->addItem(QString());
        comboBox_ResImg_Binary->addItem(QString());
        comboBox_ResImg_Binary->addItem(QString());
        comboBox_ResImg_Binary->setObjectName(QString::fromUtf8("comboBox_ResImg_Binary"));

        gridLayout_6->addWidget(comboBox_ResImg_Binary, 0, 3, 1, 1);

        graphicsView_ResImg = new QGraphicsView(tab_Res_Image);
        graphicsView_ResImg->setObjectName(QString::fromUtf8("graphicsView_ResImg"));
        graphicsView_ResImg->setMouseTracking(true);

        gridLayout_6->addWidget(graphicsView_ResImg, 1, 0, 1, 4);

        tabWidget_Res->addTab(tab_Res_Image, QString());
        tab_Res_Plot = new QWidget();
        tab_Res_Plot->setObjectName(QString::fromUtf8("tab_Res_Plot"));
        gridLayout_10 = new QGridLayout(tab_Res_Plot);
        gridLayout_10->setSpacing(3);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(6, 6, 6, 6);
        comboBox_Res_PlotType = new QComboBox(tab_Res_Plot);
        comboBox_Res_PlotType->addItem(QString());
        comboBox_Res_PlotType->addItem(QString());
        comboBox_Res_PlotType->addItem(QString());
        comboBox_Res_PlotType->addItem(QString());
        comboBox_Res_PlotType->addItem(QString());
        comboBox_Res_PlotType->addItem(QString());
        comboBox_Res_PlotType->setObjectName(QString::fromUtf8("comboBox_Res_PlotType"));

        gridLayout_10->addWidget(comboBox_Res_PlotType, 0, 0, 1, 1);

        stackedWidget_ResPlo_Type = new QStackedWidget(tab_Res_Plot);
        stackedWidget_ResPlo_Type->setObjectName(QString::fromUtf8("stackedWidget_ResPlo_Type"));
        stackedWidget_ResPlo_Type->setMaximumSize(QSize(16777215, 20));
        page_His_Colony = new QWidget();
        page_His_Colony->setObjectName(QString::fromUtf8("page_His_Colony"));
        gridLayout_11 = new QGridLayout(page_His_Colony);
        gridLayout_11->setSpacing(3);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        line_5 = new QFrame(page_His_Colony);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_11->addWidget(line_5, 0, 2, 1, 1);

        checkBox_ResPlo_HisCol_Uniform = new QCheckBox(page_His_Colony);
        checkBox_ResPlo_HisCol_Uniform->setObjectName(QString::fromUtf8("checkBox_ResPlo_HisCol_Uniform"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(checkBox_ResPlo_HisCol_Uniform->sizePolicy().hasHeightForWidth());
        checkBox_ResPlo_HisCol_Uniform->setSizePolicy(sizePolicy2);
        checkBox_ResPlo_HisCol_Uniform->setChecked(true);

        gridLayout_11->addWidget(checkBox_ResPlo_HisCol_Uniform, 0, 3, 1, 1);

        spinBox_ResPlo_HisCol_ClassCount = new QSpinBox(page_His_Colony);
        spinBox_ResPlo_HisCol_ClassCount->setObjectName(QString::fromUtf8("spinBox_ResPlo_HisCol_ClassCount"));
        sizePolicy2.setHeightForWidth(spinBox_ResPlo_HisCol_ClassCount->sizePolicy().hasHeightForWidth());
        spinBox_ResPlo_HisCol_ClassCount->setSizePolicy(sizePolicy2);
        spinBox_ResPlo_HisCol_ClassCount->setMinimumSize(QSize(55, 0));
        spinBox_ResPlo_HisCol_ClassCount->setMaximumSize(QSize(55, 16777215));
        spinBox_ResPlo_HisCol_ClassCount->setMinimum(1);
        spinBox_ResPlo_HisCol_ClassCount->setMaximum(256);
        spinBox_ResPlo_HisCol_ClassCount->setValue(256);

        gridLayout_11->addWidget(spinBox_ResPlo_HisCol_ClassCount, 0, 1, 1, 1);

        checkBox_ResPlo_HisCol_Accumulate = new QCheckBox(page_His_Colony);
        checkBox_ResPlo_HisCol_Accumulate->setObjectName(QString::fromUtf8("checkBox_ResPlo_HisCol_Accumulate"));
        sizePolicy2.setHeightForWidth(checkBox_ResPlo_HisCol_Accumulate->sizePolicy().hasHeightForWidth());
        checkBox_ResPlo_HisCol_Accumulate->setSizePolicy(sizePolicy2);
        checkBox_ResPlo_HisCol_Accumulate->setChecked(true);

        gridLayout_11->addWidget(checkBox_ResPlo_HisCol_Accumulate, 0, 4, 1, 1);

        comboBox_ResPlo_HisCol_Typ = new QComboBox(page_His_Colony);
        comboBox_ResPlo_HisCol_Typ->setObjectName(QString::fromUtf8("comboBox_ResPlo_HisCol_Typ"));
        comboBox_ResPlo_HisCol_Typ->setMinimumSize(QSize(200, 0));
        comboBox_ResPlo_HisCol_Typ->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_11->addWidget(comboBox_ResPlo_HisCol_Typ, 0, 0, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_His_Colony);
        page_Stat_Compare = new QWidget();
        page_Stat_Compare->setObjectName(QString::fromUtf8("page_Stat_Compare"));
        gridLayout_9 = new QGridLayout(page_Stat_Compare);
        gridLayout_9->setSpacing(3);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(page_Stat_Compare);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(10, 16777215));

        gridLayout_9->addWidget(label_6, 0, 0, 1, 1);

        comboBox_ResPlo_StatComp_X_Stat = new QComboBox(page_Stat_Compare);
        comboBox_ResPlo_StatComp_X_Stat->setObjectName(QString::fromUtf8("comboBox_ResPlo_StatComp_X_Stat"));

        gridLayout_9->addWidget(comboBox_ResPlo_StatComp_X_Stat, 0, 2, 1, 1);

        line_4 = new QFrame(page_Stat_Compare);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_9->addWidget(line_4, 0, 3, 1, 1);

        label_29 = new QLabel(page_Stat_Compare);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setMaximumSize(QSize(10, 16777215));

        gridLayout_9->addWidget(label_29, 0, 4, 1, 1);

        comboBox_ResPlo_StatComp_Y_Stat = new QComboBox(page_Stat_Compare);
        comboBox_ResPlo_StatComp_Y_Stat->setObjectName(QString::fromUtf8("comboBox_ResPlo_StatComp_Y_Stat"));

        gridLayout_9->addWidget(comboBox_ResPlo_StatComp_Y_Stat, 0, 6, 1, 1);

        comboBox_ResPlo_StatComp_X_Typ = new QComboBox(page_Stat_Compare);
        comboBox_ResPlo_StatComp_X_Typ->setObjectName(QString::fromUtf8("comboBox_ResPlo_StatComp_X_Typ"));

        gridLayout_9->addWidget(comboBox_ResPlo_StatComp_X_Typ, 0, 1, 1, 1);

        comboBox_ResPlo_StatComp_Y_Typ = new QComboBox(page_Stat_Compare);
        comboBox_ResPlo_StatComp_Y_Typ->setObjectName(QString::fromUtf8("comboBox_ResPlo_StatComp_Y_Typ"));

        gridLayout_9->addWidget(comboBox_ResPlo_StatComp_Y_Typ, 0, 5, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_Stat_Compare);
        page_MeanMedian = new QWidget();
        page_MeanMedian->setObjectName(QString::fromUtf8("page_MeanMedian"));
        gridLayout_12 = new QGridLayout(page_MeanMedian);
        gridLayout_12->setSpacing(3);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        comboBox_ResPlo_MM_Typ = new QComboBox(page_MeanMedian);
        comboBox_ResPlo_MM_Typ->setObjectName(QString::fromUtf8("comboBox_ResPlo_MM_Typ"));

        gridLayout_12->addWidget(comboBox_ResPlo_MM_Typ, 0, 0, 1, 1);

        checkBox_ResPlo_MM_Median = new QCheckBox(page_MeanMedian);
        checkBox_ResPlo_MM_Median->setObjectName(QString::fromUtf8("checkBox_ResPlo_MM_Median"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(checkBox_ResPlo_MM_Median->sizePolicy().hasHeightForWidth());
        checkBox_ResPlo_MM_Median->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(checkBox_ResPlo_MM_Median, 0, 4, 1, 1);

        checkBox_ResPlo_MM_Mean = new QCheckBox(page_MeanMedian);
        checkBox_ResPlo_MM_Mean->setObjectName(QString::fromUtf8("checkBox_ResPlo_MM_Mean"));
        sizePolicy3.setHeightForWidth(checkBox_ResPlo_MM_Mean->sizePolicy().hasHeightForWidth());
        checkBox_ResPlo_MM_Mean->setSizePolicy(sizePolicy3);
        checkBox_ResPlo_MM_Mean->setChecked(true);

        gridLayout_12->addWidget(checkBox_ResPlo_MM_Mean, 0, 1, 1, 1);

        checkBox_ResPlo_MM_SD = new QCheckBox(page_MeanMedian);
        checkBox_ResPlo_MM_SD->setObjectName(QString::fromUtf8("checkBox_ResPlo_MM_SD"));
        sizePolicy3.setHeightForWidth(checkBox_ResPlo_MM_SD->sizePolicy().hasHeightForWidth());
        checkBox_ResPlo_MM_SD->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(checkBox_ResPlo_MM_SD, 0, 2, 1, 1);

        checkBox_ResPlo_MM_ADM = new QCheckBox(page_MeanMedian);
        checkBox_ResPlo_MM_ADM->setObjectName(QString::fromUtf8("checkBox_ResPlo_MM_ADM"));
        sizePolicy3.setHeightForWidth(checkBox_ResPlo_MM_ADM->sizePolicy().hasHeightForWidth());
        checkBox_ResPlo_MM_ADM->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(checkBox_ResPlo_MM_ADM, 0, 5, 1, 1);

        line_6 = new QFrame(page_MeanMedian);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_12->addWidget(line_6, 0, 3, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_MeanMedian);
        page_CSK = new QWidget();
        page_CSK->setObjectName(QString::fromUtf8("page_CSK"));
        gridLayout_13 = new QGridLayout(page_CSK);
        gridLayout_13->setSpacing(3);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        checkBox_ResPlo_CSK_CV = new QCheckBox(page_CSK);
        checkBox_ResPlo_CSK_CV->setObjectName(QString::fromUtf8("checkBox_ResPlo_CSK_CV"));
        sizePolicy3.setHeightForWidth(checkBox_ResPlo_CSK_CV->sizePolicy().hasHeightForWidth());
        checkBox_ResPlo_CSK_CV->setSizePolicy(sizePolicy3);
        checkBox_ResPlo_CSK_CV->setChecked(true);

        gridLayout_13->addWidget(checkBox_ResPlo_CSK_CV, 0, 1, 1, 1);

        checkBox_ResPlo_CSK_Skewness = new QCheckBox(page_CSK);
        checkBox_ResPlo_CSK_Skewness->setObjectName(QString::fromUtf8("checkBox_ResPlo_CSK_Skewness"));
        sizePolicy3.setHeightForWidth(checkBox_ResPlo_CSK_Skewness->sizePolicy().hasHeightForWidth());
        checkBox_ResPlo_CSK_Skewness->setSizePolicy(sizePolicy3);

        gridLayout_13->addWidget(checkBox_ResPlo_CSK_Skewness, 0, 2, 1, 1);

        checkBox_ResPlo_CSK_Kurtosis = new QCheckBox(page_CSK);
        checkBox_ResPlo_CSK_Kurtosis->setObjectName(QString::fromUtf8("checkBox_ResPlo_CSK_Kurtosis"));
        sizePolicy3.setHeightForWidth(checkBox_ResPlo_CSK_Kurtosis->sizePolicy().hasHeightForWidth());
        checkBox_ResPlo_CSK_Kurtosis->setSizePolicy(sizePolicy3);

        gridLayout_13->addWidget(checkBox_ResPlo_CSK_Kurtosis, 0, 3, 1, 1);

        comboBox_ResPlo_CSK_Typ = new QComboBox(page_CSK);
        comboBox_ResPlo_CSK_Typ->setObjectName(QString::fromUtf8("comboBox_ResPlo_CSK_Typ"));

        gridLayout_13->addWidget(comboBox_ResPlo_CSK_Typ, 0, 0, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_CSK);
        page_Quantiles = new QWidget();
        page_Quantiles->setObjectName(QString::fromUtf8("page_Quantiles"));
        gridLayout_14 = new QGridLayout(page_Quantiles);
        gridLayout_14->setSpacing(3);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        comboBox_ResPlo_Quant_Steps = new QComboBox(page_Quantiles);
        comboBox_ResPlo_Quant_Steps->addItem(QString());
        comboBox_ResPlo_Quant_Steps->addItem(QString());
        comboBox_ResPlo_Quant_Steps->addItem(QString());
        comboBox_ResPlo_Quant_Steps->addItem(QString());
        comboBox_ResPlo_Quant_Steps->addItem(QString());
        comboBox_ResPlo_Quant_Steps->setObjectName(QString::fromUtf8("comboBox_ResPlo_Quant_Steps"));
        comboBox_ResPlo_Quant_Steps->setMaximumSize(QSize(40, 16777215));

        gridLayout_14->addWidget(comboBox_ResPlo_Quant_Steps, 0, 1, 1, 1);

        label_30 = new QLabel(page_Quantiles);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        sizePolicy3.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy3);

        gridLayout_14->addWidget(label_30, 0, 2, 1, 1);

        comboBox_ResPlo_Quant_Typ = new QComboBox(page_Quantiles);
        comboBox_ResPlo_Quant_Typ->setObjectName(QString::fromUtf8("comboBox_ResPlo_Quant_Typ"));

        gridLayout_14->addWidget(comboBox_ResPlo_Quant_Typ, 0, 0, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_Quantiles);
        page_TransRadial = new QWidget();
        page_TransRadial->setObjectName(QString::fromUtf8("page_TransRadial"));
        gridLayout_32 = new QGridLayout(page_TransRadial);
        gridLayout_32->setSpacing(3);
        gridLayout_32->setObjectName(QString::fromUtf8("gridLayout_32"));
        gridLayout_32->setContentsMargins(0, 0, 0, 0);
        stackedWidget_ResPlo_Type->addWidget(page_TransRadial);

        gridLayout_10->addWidget(stackedWidget_ResPlo_Type, 1, 0, 1, 1);

        gridLayout_ResPlo = new QGridLayout();
        gridLayout_ResPlo->setObjectName(QString::fromUtf8("gridLayout_ResPlo"));

        gridLayout_10->addLayout(gridLayout_ResPlo, 2, 0, 1, 1);

        tabWidget_Res->addTab(tab_Res_Plot, QString());
        tab_Res_Plot_Img = new QWidget();
        tab_Res_Plot_Img->setObjectName(QString::fromUtf8("tab_Res_Plot_Img"));
        gridLayout_16 = new QGridLayout(tab_Res_Plot_Img);
        gridLayout_16->setSpacing(3);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(6, 6, 6, 6);
        comboBox_Res_PlotType_Img = new QComboBox(tab_Res_Plot_Img);
        comboBox_Res_PlotType_Img->addItem(QString());
        comboBox_Res_PlotType_Img->addItem(QString());
        comboBox_Res_PlotType_Img->setObjectName(QString::fromUtf8("comboBox_Res_PlotType_Img"));

        gridLayout_16->addWidget(comboBox_Res_PlotType_Img, 0, 0, 1, 1);

        stackedWidget_ResPlo_Type_Img = new QStackedWidget(tab_Res_Plot_Img);
        stackedWidget_ResPlo_Type_Img->setObjectName(QString::fromUtf8("stackedWidget_ResPlo_Type_Img"));
        stackedWidget_ResPlo_Type_Img->setMaximumSize(QSize(16777215, 20));
        page_ResPlo_Hist_Img = new QWidget();
        page_ResPlo_Hist_Img->setObjectName(QString::fromUtf8("page_ResPlo_Hist_Img"));
        gridLayout_17 = new QGridLayout(page_ResPlo_Hist_Img);
        gridLayout_17->setSpacing(3);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        comboBox_ResPlo_HisImg_Attribute = new QComboBox(page_ResPlo_Hist_Img);
        comboBox_ResPlo_HisImg_Attribute->setObjectName(QString::fromUtf8("comboBox_ResPlo_HisImg_Attribute"));

        gridLayout_17->addWidget(comboBox_ResPlo_HisImg_Attribute, 0, 0, 1, 1);

        line_7 = new QFrame(page_ResPlo_Hist_Img);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line_7, 0, 1, 1, 1);

        spinBox_ResPlo_HisImg_ClassCount = new QSpinBox(page_ResPlo_Hist_Img);
        spinBox_ResPlo_HisImg_ClassCount->setObjectName(QString::fromUtf8("spinBox_ResPlo_HisImg_ClassCount"));
        sizePolicy2.setHeightForWidth(spinBox_ResPlo_HisImg_ClassCount->sizePolicy().hasHeightForWidth());
        spinBox_ResPlo_HisImg_ClassCount->setSizePolicy(sizePolicy2);
        spinBox_ResPlo_HisImg_ClassCount->setMinimum(1);
        spinBox_ResPlo_HisImg_ClassCount->setMaximum(10000);
        spinBox_ResPlo_HisImg_ClassCount->setValue(1000);

        gridLayout_17->addWidget(spinBox_ResPlo_HisImg_ClassCount, 0, 2, 1, 1);

        line_8 = new QFrame(page_ResPlo_Hist_Img);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line_8, 0, 3, 1, 1);

        checkBox_ResPlo_HisImg_Uniform = new QCheckBox(page_ResPlo_Hist_Img);
        checkBox_ResPlo_HisImg_Uniform->setObjectName(QString::fromUtf8("checkBox_ResPlo_HisImg_Uniform"));
        sizePolicy2.setHeightForWidth(checkBox_ResPlo_HisImg_Uniform->sizePolicy().hasHeightForWidth());
        checkBox_ResPlo_HisImg_Uniform->setSizePolicy(sizePolicy2);
        checkBox_ResPlo_HisImg_Uniform->setChecked(true);

        gridLayout_17->addWidget(checkBox_ResPlo_HisImg_Uniform, 0, 4, 1, 1);

        checkBox_ResPlo_HisImg_Accumulate = new QCheckBox(page_ResPlo_Hist_Img);
        checkBox_ResPlo_HisImg_Accumulate->setObjectName(QString::fromUtf8("checkBox_ResPlo_HisImg_Accumulate"));
        sizePolicy2.setHeightForWidth(checkBox_ResPlo_HisImg_Accumulate->sizePolicy().hasHeightForWidth());
        checkBox_ResPlo_HisImg_Accumulate->setSizePolicy(sizePolicy2);
        checkBox_ResPlo_HisImg_Accumulate->setChecked(true);

        gridLayout_17->addWidget(checkBox_ResPlo_HisImg_Accumulate, 0, 5, 1, 1);

        stackedWidget_ResPlo_Type_Img->addWidget(page_ResPlo_Hist_Img);
        page_ResPlo_StatComp_Img = new QWidget();
        page_ResPlo_StatComp_Img->setObjectName(QString::fromUtf8("page_ResPlo_StatComp_Img"));
        gridLayout_15 = new QGridLayout(page_ResPlo_StatComp_Img);
        gridLayout_15->setSpacing(3);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        line_9 = new QFrame(page_ResPlo_StatComp_Img);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout_15->addWidget(line_9, 0, 2, 1, 1);

        comboBox_ResPlo_StatComp_Img_Y_Attribute = new QComboBox(page_ResPlo_StatComp_Img);
        comboBox_ResPlo_StatComp_Img_Y_Attribute->setObjectName(QString::fromUtf8("comboBox_ResPlo_StatComp_Img_Y_Attribute"));

        gridLayout_15->addWidget(comboBox_ResPlo_StatComp_Img_Y_Attribute, 0, 4, 1, 1);

        label_31 = new QLabel(page_ResPlo_StatComp_Img);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setMaximumSize(QSize(20, 16777215));

        gridLayout_15->addWidget(label_31, 0, 0, 1, 1);

        comboBox_ResPlo_StatComp_Img_X_Attribute = new QComboBox(page_ResPlo_StatComp_Img);
        comboBox_ResPlo_StatComp_Img_X_Attribute->setObjectName(QString::fromUtf8("comboBox_ResPlo_StatComp_Img_X_Attribute"));

        gridLayout_15->addWidget(comboBox_ResPlo_StatComp_Img_X_Attribute, 0, 1, 1, 1);

        label_32 = new QLabel(page_ResPlo_StatComp_Img);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setMaximumSize(QSize(20, 16777215));

        gridLayout_15->addWidget(label_32, 0, 3, 1, 1);

        stackedWidget_ResPlo_Type_Img->addWidget(page_ResPlo_StatComp_Img);

        gridLayout_16->addWidget(stackedWidget_ResPlo_Type_Img, 1, 0, 1, 1);

        gridLayout_ResPlo_Img = new QGridLayout();
        gridLayout_ResPlo_Img->setObjectName(QString::fromUtf8("gridLayout_ResPlo_Img"));

        gridLayout_16->addLayout(gridLayout_ResPlo_Img, 2, 0, 1, 1);

        tabWidget_Res->addTab(tab_Res_Plot_Img, QString());
        tab_res_Surrival = new QWidget();
        tab_res_Surrival->setObjectName(QString::fromUtf8("tab_res_Surrival"));
        gridLayout_19 = new QGridLayout(tab_res_Surrival);
        gridLayout_19->setSpacing(3);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setContentsMargins(6, 6, 6, 6);
        graphicsView_Surrival = new QGraphicsView(tab_res_Surrival);
        graphicsView_Surrival->setObjectName(QString::fromUtf8("graphicsView_Surrival"));

        gridLayout_19->addWidget(graphicsView_Surrival, 0, 0, 1, 1);

        tabWidget_Res->addTab(tab_res_Surrival, QString());
        tab_res_Segmentation = new QWidget();
        tab_res_Segmentation->setObjectName(QString::fromUtf8("tab_res_Segmentation"));
        gridLayout_21 = new QGridLayout(tab_res_Segmentation);
        gridLayout_21->setSpacing(3);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        gridLayout_21->setContentsMargins(6, 6, 6, 6);
        graphicsView_Segmentation = new QGraphicsView(tab_res_Segmentation);
        graphicsView_Segmentation->setObjectName(QString::fromUtf8("graphicsView_Segmentation"));

        gridLayout_21->addWidget(graphicsView_Segmentation, 0, 0, 1, 1);

        tabWidget_Res->addTab(tab_res_Segmentation, QString());
        tab_res_Attribute = new QWidget();
        tab_res_Attribute->setObjectName(QString::fromUtf8("tab_res_Attribute"));
        gridLayout_31 = new QGridLayout(tab_res_Attribute);
        gridLayout_31->setObjectName(QString::fromUtf8("gridLayout_31"));
        label_15 = new QLabel(tab_res_Attribute);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy3.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy3);

        gridLayout_31->addWidget(label_15, 0, 0, 1, 1);

        comboBox_ResAtt_BaseImage = new QComboBox(tab_res_Attribute);
        comboBox_ResAtt_BaseImage->addItem(QString());
        comboBox_ResAtt_BaseImage->addItem(QString());
        comboBox_ResAtt_BaseImage->addItem(QString());
        comboBox_ResAtt_BaseImage->addItem(QString());
        comboBox_ResAtt_BaseImage->addItem(QString());
        comboBox_ResAtt_BaseImage->addItem(QString());
        comboBox_ResAtt_BaseImage->addItem(QString());
        comboBox_ResAtt_BaseImage->setObjectName(QString::fromUtf8("comboBox_ResAtt_BaseImage"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(comboBox_ResAtt_BaseImage->sizePolicy().hasHeightForWidth());
        comboBox_ResAtt_BaseImage->setSizePolicy(sizePolicy4);

        gridLayout_31->addWidget(comboBox_ResAtt_BaseImage, 0, 1, 1, 1);

        label_21 = new QLabel(tab_res_Attribute);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy3.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy3);

        gridLayout_31->addWidget(label_21, 0, 2, 1, 1);

        comboBox_ResAtt_Attribute = new QComboBox(tab_res_Attribute);
        comboBox_ResAtt_Attribute->setObjectName(QString::fromUtf8("comboBox_ResAtt_Attribute"));
        sizePolicy4.setHeightForWidth(comboBox_ResAtt_Attribute->sizePolicy().hasHeightForWidth());
        comboBox_ResAtt_Attribute->setSizePolicy(sizePolicy4);

        gridLayout_31->addWidget(comboBox_ResAtt_Attribute, 0, 3, 1, 1);

        line = new QFrame(tab_res_Attribute);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_31->addWidget(line, 0, 4, 1, 1);

        checkBox_ResAtt_Border = new QCheckBox(tab_res_Attribute);
        checkBox_ResAtt_Border->setObjectName(QString::fromUtf8("checkBox_ResAtt_Border"));
        sizePolicy3.setHeightForWidth(checkBox_ResAtt_Border->sizePolicy().hasHeightForWidth());
        checkBox_ResAtt_Border->setSizePolicy(sizePolicy3);
        checkBox_ResAtt_Border->setChecked(true);

        gridLayout_31->addWidget(checkBox_ResAtt_Border, 0, 5, 1, 1);

        label_46 = new QLabel(tab_res_Attribute);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        sizePolicy3.setHeightForWidth(label_46->sizePolicy().hasHeightForWidth());
        label_46->setSizePolicy(sizePolicy3);

        gridLayout_31->addWidget(label_46, 0, 6, 1, 1);

        spinBox_ResAtt_Precision = new QSpinBox(tab_res_Attribute);
        spinBox_ResAtt_Precision->setObjectName(QString::fromUtf8("spinBox_ResAtt_Precision"));
        sizePolicy3.setHeightForWidth(spinBox_ResAtt_Precision->sizePolicy().hasHeightForWidth());
        spinBox_ResAtt_Precision->setSizePolicy(sizePolicy3);
        spinBox_ResAtt_Precision->setMinimum(1);
        spinBox_ResAtt_Precision->setMaximum(9);
        spinBox_ResAtt_Precision->setValue(4);

        gridLayout_31->addWidget(spinBox_ResAtt_Precision, 0, 7, 1, 1);

        line_2 = new QFrame(tab_res_Attribute);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_31->addWidget(line_2, 0, 8, 1, 1);

        label_45 = new QLabel(tab_res_Attribute);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        sizePolicy3.setHeightForWidth(label_45->sizePolicy().hasHeightForWidth());
        label_45->setSizePolicy(sizePolicy3);

        gridLayout_31->addWidget(label_45, 0, 9, 1, 1);

        doubleSpinBox_ResAtt_Scale = new QDoubleSpinBox(tab_res_Attribute);
        doubleSpinBox_ResAtt_Scale->setObjectName(QString::fromUtf8("doubleSpinBox_ResAtt_Scale"));
        sizePolicy3.setHeightForWidth(doubleSpinBox_ResAtt_Scale->sizePolicy().hasHeightForWidth());
        doubleSpinBox_ResAtt_Scale->setSizePolicy(sizePolicy3);
        doubleSpinBox_ResAtt_Scale->setDecimals(1);
        doubleSpinBox_ResAtt_Scale->setMinimum(0.100000000000000);
        doubleSpinBox_ResAtt_Scale->setMaximum(9.000000000000000);
        doubleSpinBox_ResAtt_Scale->setSingleStep(0.100000000000000);
        doubleSpinBox_ResAtt_Scale->setValue(0.700000000000000);

        gridLayout_31->addWidget(doubleSpinBox_ResAtt_Scale, 0, 10, 1, 1);

        label_47 = new QLabel(tab_res_Attribute);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        sizePolicy3.setHeightForWidth(label_47->sizePolicy().hasHeightForWidth());
        label_47->setSizePolicy(sizePolicy3);

        gridLayout_31->addWidget(label_47, 0, 11, 1, 1);

        spinBox_ResAtt_Tickness = new QSpinBox(tab_res_Attribute);
        spinBox_ResAtt_Tickness->setObjectName(QString::fromUtf8("spinBox_ResAtt_Tickness"));
        sizePolicy3.setHeightForWidth(spinBox_ResAtt_Tickness->sizePolicy().hasHeightForWidth());
        spinBox_ResAtt_Tickness->setSizePolicy(sizePolicy3);
        spinBox_ResAtt_Tickness->setMinimum(1);
        spinBox_ResAtt_Tickness->setMaximum(9);

        gridLayout_31->addWidget(spinBox_ResAtt_Tickness, 0, 12, 1, 1);

        graphicsView_Attribute = new QGraphicsView(tab_res_Attribute);
        graphicsView_Attribute->setObjectName(QString::fromUtf8("graphicsView_Attribute"));

        gridLayout_31->addWidget(graphicsView_Attribute, 1, 0, 1, 13);

        tabWidget_Res->addTab(tab_res_Attribute, QString());

        gridLayout_5->addWidget(tabWidget_Res, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_ResView, 1, 0, 1, 1);

        groupBox_ProcView = new QGroupBox(centralwidget);
        groupBox_ProcView->setObjectName(QString::fromUtf8("groupBox_ProcView"));
        sizePolicy.setHeightForWidth(groupBox_ProcView->sizePolicy().hasHeightForWidth());
        groupBox_ProcView->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(groupBox_ProcView);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_ProcView_MA = new QLabel(groupBox_ProcView);
        label_ProcView_MA->setObjectName(QString::fromUtf8("label_ProcView_MA"));
        label_ProcView_MA->setMinimumSize(QSize(75, 0));
        label_ProcView_MA->setMaximumSize(QSize(75, 16777215));

        gridLayout_4->addWidget(label_ProcView_MA, 1, 3, 1, 1);

        label_ProcView_QI = new QLabel(groupBox_ProcView);
        label_ProcView_QI->setObjectName(QString::fromUtf8("label_ProcView_QI"));
        label_ProcView_QI->setMinimumSize(QSize(75, 0));
        label_ProcView_QI->setMaximumSize(QSize(75, 16777215));

        gridLayout_4->addWidget(label_ProcView_QI, 1, 2, 1, 1);

        comboBox_ProcView_Step = new QComboBox(groupBox_ProcView);
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->addItem(QString());
        comboBox_ProcView_Step->setObjectName(QString::fromUtf8("comboBox_ProcView_Step"));

        gridLayout_4->addWidget(comboBox_ProcView_Step, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_ProcView);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(75, 0));
        label_5->setMaximumSize(QSize(75, 16777215));

        gridLayout_4->addWidget(label_5, 1, 0, 1, 1);

        graphicsView_Cells = new QGraphicsView(groupBox_ProcView);
        graphicsView_Cells->setObjectName(QString::fromUtf8("graphicsView_Cells"));
        sizePolicy1.setHeightForWidth(graphicsView_Cells->sizePolicy().hasHeightForWidth());
        graphicsView_Cells->setSizePolicy(sizePolicy1);
        graphicsView_Cells->setMouseTracking(true);

        gridLayout_4->addWidget(graphicsView_Cells, 2, 0, 1, 4);


        gridLayout->addWidget(groupBox_ProcView, 0, 0, 1, 1);

        groupBox_Control = new QGroupBox(centralwidget);
        groupBox_Control->setObjectName(QString::fromUtf8("groupBox_Control"));
        groupBox_Control->setMinimumSize(QSize(0, 0));
        groupBox_Control->setMaximumSize(QSize(410, 16777215));
        gridLayout_2 = new QGridLayout(groupBox_Control);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_Results = new QGroupBox(groupBox_Control);
        groupBox_Results->setObjectName(QString::fromUtf8("groupBox_Results"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox_Results->sizePolicy().hasHeightForWidth());
        groupBox_Results->setSizePolicy(sizePolicy5);
        groupBox_Results->setMinimumSize(QSize(0, 50));
        groupBox_Results->setMaximumSize(QSize(16777215, 16777215));
        groupBox_Results->setFlat(true);
        gridLayout_23 = new QGridLayout(groupBox_Results);
        gridLayout_23->setSpacing(3);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        gridLayout_23->setContentsMargins(6, 6, 6, 6);
        gridLayout_ResPlo_Surrival = new QGridLayout();
        gridLayout_ResPlo_Surrival->setObjectName(QString::fromUtf8("gridLayout_ResPlo_Surrival"));

        gridLayout_23->addLayout(gridLayout_ResPlo_Surrival, 3, 0, 1, 5);

        label_33 = new QLabel(groupBox_Results);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        sizePolicy4.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy4);
        label_33->setMaximumSize(QSize(50, 20));

        gridLayout_23->addWidget(label_33, 1, 2, 1, 1);

        label_34 = new QLabel(groupBox_Results);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        sizePolicy4.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy4);
        label_34->setMaximumSize(QSize(50, 20));

        gridLayout_23->addWidget(label_34, 2, 2, 1, 1);

        label_ResPloSur_prz_dead = new QLabel(groupBox_Results);
        label_ResPloSur_prz_dead->setObjectName(QString::fromUtf8("label_ResPloSur_prz_dead"));
        sizePolicy4.setHeightForWidth(label_ResPloSur_prz_dead->sizePolicy().hasHeightForWidth());
        label_ResPloSur_prz_dead->setSizePolicy(sizePolicy4);
        label_ResPloSur_prz_dead->setMaximumSize(QSize(16777215, 20));

        gridLayout_23->addWidget(label_ResPloSur_prz_dead, 2, 4, 1, 1);

        label_ResPloSur_prz_surrival = new QLabel(groupBox_Results);
        label_ResPloSur_prz_surrival->setObjectName(QString::fromUtf8("label_ResPloSur_prz_surrival"));
        sizePolicy4.setHeightForWidth(label_ResPloSur_prz_surrival->sizePolicy().hasHeightForWidth());
        label_ResPloSur_prz_surrival->setSizePolicy(sizePolicy4);
        label_ResPloSur_prz_surrival->setMaximumSize(QSize(16777215, 20));

        gridLayout_23->addWidget(label_ResPloSur_prz_surrival, 1, 4, 1, 1);

        label_24 = new QLabel(groupBox_Results);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_23->addWidget(label_24, 1, 0, 2, 1);

        label_ResPloSur_count_surrival = new QLabel(groupBox_Results);
        label_ResPloSur_count_surrival->setObjectName(QString::fromUtf8("label_ResPloSur_count_surrival"));
        sizePolicy4.setHeightForWidth(label_ResPloSur_count_surrival->sizePolicy().hasHeightForWidth());
        label_ResPloSur_count_surrival->setSizePolicy(sizePolicy4);
        label_ResPloSur_count_surrival->setMaximumSize(QSize(50, 20));

        gridLayout_23->addWidget(label_ResPloSur_count_surrival, 1, 3, 1, 1);

        label_ResPloSur_count_dead = new QLabel(groupBox_Results);
        label_ResPloSur_count_dead->setObjectName(QString::fromUtf8("label_ResPloSur_count_dead"));
        sizePolicy4.setHeightForWidth(label_ResPloSur_count_dead->sizePolicy().hasHeightForWidth());
        label_ResPloSur_count_dead->setSizePolicy(sizePolicy4);
        label_ResPloSur_count_dead->setMaximumSize(QSize(50, 20));

        gridLayout_23->addWidget(label_ResPloSur_count_dead, 2, 3, 1, 1);

        label_ResPloSur_count_detected = new QLabel(groupBox_Results);
        label_ResPloSur_count_detected->setObjectName(QString::fromUtf8("label_ResPloSur_count_detected"));
        label_ResPloSur_count_detected->setMaximumSize(QSize(50, 16777215));

        gridLayout_23->addWidget(label_ResPloSur_count_detected, 1, 1, 2, 1);


        gridLayout_2->addWidget(groupBox_Results, 6, 0, 1, 1);

        tabWidget_Control = new QTabWidget(groupBox_Control);
        tabWidget_Control->setObjectName(QString::fromUtf8("tabWidget_Control"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(tabWidget_Control->sizePolicy().hasHeightForWidth());
        tabWidget_Control->setSizePolicy(sizePolicy6);
        tabWidget_Control->setMaximumSize(QSize(16777215, 565));
        tab_Processing = new QWidget();
        tab_Processing->setObjectName(QString::fromUtf8("tab_Processing"));
        gridLayout_24 = new QGridLayout(tab_Processing);
        gridLayout_24->setSpacing(3);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        gridLayout_24->setContentsMargins(6, 6, 6, 6);
        groupBox_Seedds = new QGroupBox(tab_Processing);
        groupBox_Seedds->setObjectName(QString::fromUtf8("groupBox_Seedds"));
        groupBox_Seedds->setFlat(true);
        gridLayout_3 = new QGridLayout(groupBox_Seedds);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(6, 6, 6, -1);
        label_16 = new QLabel(groupBox_Seedds);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(0, 0));
        label_16->setMaximumSize(QSize(65, 16777215));

        gridLayout_3->addWidget(label_16, 0, 0, 1, 1);

        spinBox_ProcCon_Seed_Blur_Size = new QSpinBox(groupBox_Seedds);
        spinBox_ProcCon_Seed_Blur_Size->setObjectName(QString::fromUtf8("spinBox_ProcCon_Seed_Blur_Size"));
        sizePolicy2.setHeightForWidth(spinBox_ProcCon_Seed_Blur_Size->sizePolicy().hasHeightForWidth());
        spinBox_ProcCon_Seed_Blur_Size->setSizePolicy(sizePolicy2);
        spinBox_ProcCon_Seed_Blur_Size->setMinimumSize(QSize(61, 0));
        spinBox_ProcCon_Seed_Blur_Size->setMaximumSize(QSize(61, 16777215));
        spinBox_ProcCon_Seed_Blur_Size->setMinimum(1);
        spinBox_ProcCon_Seed_Blur_Size->setMaximum(1000);
        spinBox_ProcCon_Seed_Blur_Size->setSingleStep(2);
        spinBox_ProcCon_Seed_Blur_Size->setValue(7);

        gridLayout_3->addWidget(spinBox_ProcCon_Seed_Blur_Size, 0, 1, 1, 1);

        doubleSpinBox_ProcCon_Seed_Blur_Sigma = new QDoubleSpinBox(groupBox_Seedds);
        doubleSpinBox_ProcCon_Seed_Blur_Sigma->setObjectName(QString::fromUtf8("doubleSpinBox_ProcCon_Seed_Blur_Sigma"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_ProcCon_Seed_Blur_Sigma->sizePolicy().hasHeightForWidth());
        doubleSpinBox_ProcCon_Seed_Blur_Sigma->setSizePolicy(sizePolicy2);
        doubleSpinBox_ProcCon_Seed_Blur_Sigma->setMinimumSize(QSize(61, 0));
        doubleSpinBox_ProcCon_Seed_Blur_Sigma->setMaximumSize(QSize(61, 16777215));
        doubleSpinBox_ProcCon_Seed_Blur_Sigma->setMaximum(100.000000000000000);
        doubleSpinBox_ProcCon_Seed_Blur_Sigma->setValue(5.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_ProcCon_Seed_Blur_Sigma, 0, 2, 1, 1);

        label_17 = new QLabel(groupBox_Seedds);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_3->addWidget(label_17, 0, 3, 1, 1);

        label_18 = new QLabel(groupBox_Seedds);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMinimumSize(QSize(0, 0));
        label_18->setMaximumSize(QSize(65, 16777215));

        gridLayout_3->addWidget(label_18, 1, 0, 1, 1);

        spinBox_ProcCon_Thres_Size = new QSpinBox(groupBox_Seedds);
        spinBox_ProcCon_Thres_Size->setObjectName(QString::fromUtf8("spinBox_ProcCon_Thres_Size"));
        sizePolicy2.setHeightForWidth(spinBox_ProcCon_Thres_Size->sizePolicy().hasHeightForWidth());
        spinBox_ProcCon_Thres_Size->setSizePolicy(sizePolicy2);
        spinBox_ProcCon_Thres_Size->setMinimumSize(QSize(61, 0));
        spinBox_ProcCon_Thres_Size->setMaximumSize(QSize(61, 16777215));
        spinBox_ProcCon_Thres_Size->setMinimum(3);
        spinBox_ProcCon_Thres_Size->setMaximum(1000);
        spinBox_ProcCon_Thres_Size->setSingleStep(2);
        spinBox_ProcCon_Thres_Size->setValue(11);

        gridLayout_3->addWidget(spinBox_ProcCon_Thres_Size, 1, 1, 1, 1);

        doubleSpinBox_ProcCon_Thres_Offset = new QDoubleSpinBox(groupBox_Seedds);
        doubleSpinBox_ProcCon_Thres_Offset->setObjectName(QString::fromUtf8("doubleSpinBox_ProcCon_Thres_Offset"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_ProcCon_Thres_Offset->sizePolicy().hasHeightForWidth());
        doubleSpinBox_ProcCon_Thres_Offset->setSizePolicy(sizePolicy2);
        doubleSpinBox_ProcCon_Thres_Offset->setMinimumSize(QSize(61, 0));
        doubleSpinBox_ProcCon_Thres_Offset->setMaximumSize(QSize(61, 16777215));
        doubleSpinBox_ProcCon_Thres_Offset->setMinimum(-256.000000000000000);
        doubleSpinBox_ProcCon_Thres_Offset->setMaximum(255.000000000000000);
        doubleSpinBox_ProcCon_Thres_Offset->setValue(-4.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_ProcCon_Thres_Offset, 1, 2, 1, 1);

        label_20 = new QLabel(groupBox_Seedds);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_3->addWidget(label_20, 1, 3, 1, 1);

        label_22 = new QLabel(groupBox_Seedds);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(0, 0));
        label_22->setMaximumSize(QSize(65, 16777215));

        gridLayout_3->addWidget(label_22, 2, 0, 1, 1);

        spinBox_ProcCon_Seed_Open_Size = new QSpinBox(groupBox_Seedds);
        spinBox_ProcCon_Seed_Open_Size->setObjectName(QString::fromUtf8("spinBox_ProcCon_Seed_Open_Size"));
        spinBox_ProcCon_Seed_Open_Size->setMinimumSize(QSize(126, 0));
        spinBox_ProcCon_Seed_Open_Size->setMaximumSize(QSize(126, 16777215));
        spinBox_ProcCon_Seed_Open_Size->setMinimum(1);
        spinBox_ProcCon_Seed_Open_Size->setMaximum(1000);
        spinBox_ProcCon_Seed_Open_Size->setSingleStep(2);
        spinBox_ProcCon_Seed_Open_Size->setValue(7);

        gridLayout_3->addWidget(spinBox_ProcCon_Seed_Open_Size, 2, 1, 1, 2);

        label_23 = new QLabel(groupBox_Seedds);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_3->addWidget(label_23, 2, 3, 1, 1);

        label_37 = new QLabel(groupBox_Seedds);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setMinimumSize(QSize(0, 0));
        label_37->setMaximumSize(QSize(65, 16777215));

        gridLayout_3->addWidget(label_37, 3, 0, 1, 1);

        label_38 = new QLabel(groupBox_Seedds);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setMinimumSize(QSize(0, 0));
        label_38->setMaximumSize(QSize(65, 16777215));

        gridLayout_3->addWidget(label_38, 4, 0, 1, 1);

        doubleSpinBox_Separtate_Asphere_Thres = new QDoubleSpinBox(groupBox_Seedds);
        doubleSpinBox_Separtate_Asphere_Thres->setObjectName(QString::fromUtf8("doubleSpinBox_Separtate_Asphere_Thres"));
        doubleSpinBox_Separtate_Asphere_Thres->setMinimumSize(QSize(126, 0));
        doubleSpinBox_Separtate_Asphere_Thres->setMaximumSize(QSize(126, 16777215));
        doubleSpinBox_Separtate_Asphere_Thres->setDecimals(3);
        doubleSpinBox_Separtate_Asphere_Thres->setMaximum(100000.000000000000000);
        doubleSpinBox_Separtate_Asphere_Thres->setSingleStep(0.250000000000000);
        doubleSpinBox_Separtate_Asphere_Thres->setValue(4.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_Separtate_Asphere_Thres, 4, 1, 1, 2);

        doubleSpinBox_Extract_Asphere_Thres = new QDoubleSpinBox(groupBox_Seedds);
        doubleSpinBox_Extract_Asphere_Thres->setObjectName(QString::fromUtf8("doubleSpinBox_Extract_Asphere_Thres"));
        doubleSpinBox_Extract_Asphere_Thres->setMinimumSize(QSize(126, 0));
        doubleSpinBox_Extract_Asphere_Thres->setMaximumSize(QSize(126, 16777215));
        doubleSpinBox_Extract_Asphere_Thres->setDecimals(3);
        doubleSpinBox_Extract_Asphere_Thres->setMaximum(100000.000000000000000);
        doubleSpinBox_Extract_Asphere_Thres->setSingleStep(0.010000000000000);
        doubleSpinBox_Extract_Asphere_Thres->setValue(4.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_Extract_Asphere_Thres, 3, 1, 1, 2);

        label_39 = new QLabel(groupBox_Seedds);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        gridLayout_3->addWidget(label_39, 3, 3, 1, 1);

        label_40 = new QLabel(groupBox_Seedds);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout_3->addWidget(label_40, 4, 3, 1, 1);


        gridLayout_24->addWidget(groupBox_Seedds, 3, 0, 1, 1);

        groupBox_Segmentation = new QGroupBox(tab_Processing);
        groupBox_Segmentation->setObjectName(QString::fromUtf8("groupBox_Segmentation"));
        groupBox_Segmentation->setFlat(true);
        gridLayout_20 = new QGridLayout(groupBox_Segmentation);
        gridLayout_20->setSpacing(3);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        gridLayout_20->setContentsMargins(6, 6, 6, 6);
        label_25 = new QLabel(groupBox_Segmentation);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setMinimumSize(QSize(0, 0));
        label_25->setMaximumSize(QSize(65, 16777215));

        gridLayout_20->addWidget(label_25, 0, 0, 1, 1);

        checkBox_ProcCon_Watershed_Border = new QCheckBox(groupBox_Segmentation);
        checkBox_ProcCon_Watershed_Border->setObjectName(QString::fromUtf8("checkBox_ProcCon_Watershed_Border"));
        checkBox_ProcCon_Watershed_Border->setMinimumSize(QSize(61, 0));
        checkBox_ProcCon_Watershed_Border->setMaximumSize(QSize(61, 16777215));
        checkBox_ProcCon_Watershed_Border->setChecked(false);

        gridLayout_20->addWidget(checkBox_ProcCon_Watershed_Border, 0, 1, 1, 1);

        checkBox_ProcCon_Watershed_nSeed = new QCheckBox(groupBox_Segmentation);
        checkBox_ProcCon_Watershed_nSeed->setObjectName(QString::fromUtf8("checkBox_ProcCon_Watershed_nSeed"));
        checkBox_ProcCon_Watershed_nSeed->setMinimumSize(QSize(61, 0));
        checkBox_ProcCon_Watershed_nSeed->setMaximumSize(QSize(61, 16777215));
        checkBox_ProcCon_Watershed_nSeed->setChecked(true);

        gridLayout_20->addWidget(checkBox_ProcCon_Watershed_nSeed, 0, 2, 1, 1);

        label_26 = new QLabel(groupBox_Segmentation);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_20->addWidget(label_26, 0, 3, 1, 1);


        gridLayout_24->addWidget(groupBox_Segmentation, 4, 0, 1, 1);

        groupBox_Reference_Input = new QGroupBox(tab_Processing);
        groupBox_Reference_Input->setObjectName(QString::fromUtf8("groupBox_Reference_Input"));
        groupBox_Reference_Input->setFlat(true);
        groupBox_Reference_Input->setCheckable(true);
        groupBox_Reference_Input->setChecked(true);
        gridLayout_18 = new QGridLayout(groupBox_Reference_Input);
        gridLayout_18->setSpacing(3);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(6, 6, 6, 6);
        label_7 = new QLabel(groupBox_Reference_Input);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 0));
        label_7->setMaximumSize(QSize(65, 16777215));

        gridLayout_18->addWidget(label_7, 1, 0, 1, 1);

        label = new QLabel(groupBox_Reference_Input);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_18->addWidget(label, 2, 3, 1, 1);

        label_8 = new QLabel(groupBox_Reference_Input);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 0));
        label_8->setMaximumSize(QSize(65, 16777215));

        gridLayout_18->addWidget(label_8, 2, 0, 1, 1);

        doubleSpinBox_ProcCon_ROI_X1 = new QDoubleSpinBox(groupBox_Reference_Input);
        doubleSpinBox_ProcCon_ROI_X1->setObjectName(QString::fromUtf8("doubleSpinBox_ProcCon_ROI_X1"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_ProcCon_ROI_X1->sizePolicy().hasHeightForWidth());
        doubleSpinBox_ProcCon_ROI_X1->setSizePolicy(sizePolicy2);
        doubleSpinBox_ProcCon_ROI_X1->setMinimumSize(QSize(61, 0));
        doubleSpinBox_ProcCon_ROI_X1->setMaximumSize(QSize(61, 20));
        doubleSpinBox_ProcCon_ROI_X1->setMinimum(0.000000000000000);
        doubleSpinBox_ProcCon_ROI_X1->setMaximum(99.000000000000000);
        doubleSpinBox_ProcCon_ROI_X1->setValue(22.000000000000000);

        gridLayout_18->addWidget(doubleSpinBox_ProcCon_ROI_X1, 1, 1, 1, 1);

        doubleSpinBox_ProcCon_ROI_X2 = new QDoubleSpinBox(groupBox_Reference_Input);
        doubleSpinBox_ProcCon_ROI_X2->setObjectName(QString::fromUtf8("doubleSpinBox_ProcCon_ROI_X2"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_ProcCon_ROI_X2->sizePolicy().hasHeightForWidth());
        doubleSpinBox_ProcCon_ROI_X2->setSizePolicy(sizePolicy2);
        doubleSpinBox_ProcCon_ROI_X2->setMinimumSize(QSize(61, 0));
        doubleSpinBox_ProcCon_ROI_X2->setMaximumSize(QSize(61, 20));
        doubleSpinBox_ProcCon_ROI_X2->setMinimum(1.000000000000000);
        doubleSpinBox_ProcCon_ROI_X2->setMaximum(100.000000000000000);
        doubleSpinBox_ProcCon_ROI_X2->setValue(84.000000000000000);

        gridLayout_18->addWidget(doubleSpinBox_ProcCon_ROI_X2, 2, 1, 1, 1);

        doubleSpinBox_ProcCon_ROI_Y1 = new QDoubleSpinBox(groupBox_Reference_Input);
        doubleSpinBox_ProcCon_ROI_Y1->setObjectName(QString::fromUtf8("doubleSpinBox_ProcCon_ROI_Y1"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_ProcCon_ROI_Y1->sizePolicy().hasHeightForWidth());
        doubleSpinBox_ProcCon_ROI_Y1->setSizePolicy(sizePolicy2);
        doubleSpinBox_ProcCon_ROI_Y1->setMinimumSize(QSize(61, 0));
        doubleSpinBox_ProcCon_ROI_Y1->setMaximumSize(QSize(61, 20));
        doubleSpinBox_ProcCon_ROI_Y1->setMinimum(0.000000000000000);
        doubleSpinBox_ProcCon_ROI_Y1->setMaximum(99.000000000000000);
        doubleSpinBox_ProcCon_ROI_Y1->setValue(20.000000000000000);

        gridLayout_18->addWidget(doubleSpinBox_ProcCon_ROI_Y1, 1, 2, 1, 1);

        label_2 = new QLabel(groupBox_Reference_Input);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_18->addWidget(label_2, 1, 3, 1, 1);

        doubleSpinBox_ProcCon_ROI_Y2 = new QDoubleSpinBox(groupBox_Reference_Input);
        doubleSpinBox_ProcCon_ROI_Y2->setObjectName(QString::fromUtf8("doubleSpinBox_ProcCon_ROI_Y2"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_ProcCon_ROI_Y2->sizePolicy().hasHeightForWidth());
        doubleSpinBox_ProcCon_ROI_Y2->setSizePolicy(sizePolicy2);
        doubleSpinBox_ProcCon_ROI_Y2->setMinimumSize(QSize(61, 0));
        doubleSpinBox_ProcCon_ROI_Y2->setMaximumSize(QSize(61, 20));
        doubleSpinBox_ProcCon_ROI_Y2->setMinimum(1.000000000000000);
        doubleSpinBox_ProcCon_ROI_Y2->setMaximum(100.000000000000000);
        doubleSpinBox_ProcCon_ROI_Y2->setValue(83.000000000000000);

        gridLayout_18->addWidget(doubleSpinBox_ProcCon_ROI_Y2, 2, 2, 1, 1);

        label_3 = new QLabel(groupBox_Reference_Input);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_18->addWidget(label_3, 0, 3, 1, 1);

        label_4 = new QLabel(groupBox_Reference_Input);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 0));
        label_4->setMaximumSize(QSize(65, 16777215));

        gridLayout_18->addWidget(label_4, 0, 0, 1, 1);

        spinBox_ProcCon_Ref_Blur_Size = new QSpinBox(groupBox_Reference_Input);
        spinBox_ProcCon_Ref_Blur_Size->setObjectName(QString::fromUtf8("spinBox_ProcCon_Ref_Blur_Size"));
        spinBox_ProcCon_Ref_Blur_Size->setMinimumSize(QSize(61, 0));
        spinBox_ProcCon_Ref_Blur_Size->setMaximumSize(QSize(61, 16777215));
        spinBox_ProcCon_Ref_Blur_Size->setMinimum(1);
        spinBox_ProcCon_Ref_Blur_Size->setMaximum(1000);
        spinBox_ProcCon_Ref_Blur_Size->setSingleStep(2);
        spinBox_ProcCon_Ref_Blur_Size->setValue(31);

        gridLayout_18->addWidget(spinBox_ProcCon_Ref_Blur_Size, 0, 1, 1, 1);

        doubleSpinBox_ProcCon_Ref_Blur_Sigma = new QDoubleSpinBox(groupBox_Reference_Input);
        doubleSpinBox_ProcCon_Ref_Blur_Sigma->setObjectName(QString::fromUtf8("doubleSpinBox_ProcCon_Ref_Blur_Sigma"));
        doubleSpinBox_ProcCon_Ref_Blur_Sigma->setMinimumSize(QSize(61, 0));
        doubleSpinBox_ProcCon_Ref_Blur_Sigma->setMaximumSize(QSize(61, 16777215));
        doubleSpinBox_ProcCon_Ref_Blur_Sigma->setMaximum(100.000000000000000);
        doubleSpinBox_ProcCon_Ref_Blur_Sigma->setValue(10.000000000000000);

        gridLayout_18->addWidget(doubleSpinBox_ProcCon_Ref_Blur_Sigma, 0, 2, 1, 1);


        gridLayout_24->addWidget(groupBox_Reference_Input, 1, 0, 1, 1);

        groupBox_Stack = new QGroupBox(tab_Processing);
        groupBox_Stack->setObjectName(QString::fromUtf8("groupBox_Stack"));
        groupBox_Stack->setFlat(true);
        gridLayout_7 = new QGridLayout(groupBox_Stack);
        gridLayout_7->setSpacing(3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(6, 6, 6, 6);
        comboBox_ProcView_Image = new QComboBox(groupBox_Stack);
        comboBox_ProcView_Image->setObjectName(QString::fromUtf8("comboBox_ProcView_Image"));

        gridLayout_7->addWidget(comboBox_ProcView_Image, 0, 0, 1, 1);


        gridLayout_24->addWidget(groupBox_Stack, 0, 0, 1, 1);

        groupBox_Foreground = new QGroupBox(tab_Processing);
        groupBox_Foreground->setObjectName(QString::fromUtf8("groupBox_Foreground"));
        groupBox_Foreground->setFlat(true);
        gridLayout_8 = new QGridLayout(groupBox_Foreground);
        gridLayout_8->setSpacing(3);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(6, 6, 6, 6);
        spinBox_ProcCon_ColGrab_H_Min = new QSpinBox(groupBox_Foreground);
        spinBox_ProcCon_ColGrab_H_Min->setObjectName(QString::fromUtf8("spinBox_ProcCon_ColGrab_H_Min"));
        sizePolicy2.setHeightForWidth(spinBox_ProcCon_ColGrab_H_Min->sizePolicy().hasHeightForWidth());
        spinBox_ProcCon_ColGrab_H_Min->setSizePolicy(sizePolicy2);
        spinBox_ProcCon_ColGrab_H_Min->setMinimumSize(QSize(40, 0));
        spinBox_ProcCon_ColGrab_H_Min->setMaximumSize(QSize(40, 20));
        spinBox_ProcCon_ColGrab_H_Min->setMaximum(255);
        spinBox_ProcCon_ColGrab_H_Min->setValue(110);

        gridLayout_8->addWidget(spinBox_ProcCon_ColGrab_H_Min, 0, 1, 1, 1);

        label_9 = new QLabel(groupBox_Foreground);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 0));
        label_9->setMaximumSize(QSize(65, 16777215));

        gridLayout_8->addWidget(label_9, 0, 0, 1, 1);

        spinBox_ProcCon_ColGrab_V_Min = new QSpinBox(groupBox_Foreground);
        spinBox_ProcCon_ColGrab_V_Min->setObjectName(QString::fromUtf8("spinBox_ProcCon_ColGrab_V_Min"));
        sizePolicy2.setHeightForWidth(spinBox_ProcCon_ColGrab_V_Min->sizePolicy().hasHeightForWidth());
        spinBox_ProcCon_ColGrab_V_Min->setSizePolicy(sizePolicy2);
        spinBox_ProcCon_ColGrab_V_Min->setMinimumSize(QSize(40, 0));
        spinBox_ProcCon_ColGrab_V_Min->setMaximumSize(QSize(40, 20));
        spinBox_ProcCon_ColGrab_V_Min->setMaximum(255);

        gridLayout_8->addWidget(spinBox_ProcCon_ColGrab_V_Min, 0, 3, 1, 1);

        spinBox_ProcCon_ColGrab_H_Max = new QSpinBox(groupBox_Foreground);
        spinBox_ProcCon_ColGrab_H_Max->setObjectName(QString::fromUtf8("spinBox_ProcCon_ColGrab_H_Max"));
        sizePolicy2.setHeightForWidth(spinBox_ProcCon_ColGrab_H_Max->sizePolicy().hasHeightForWidth());
        spinBox_ProcCon_ColGrab_H_Max->setSizePolicy(sizePolicy2);
        spinBox_ProcCon_ColGrab_H_Max->setMinimumSize(QSize(40, 0));
        spinBox_ProcCon_ColGrab_H_Max->setMaximumSize(QSize(40, 20));
        spinBox_ProcCon_ColGrab_H_Max->setMaximum(255);
        spinBox_ProcCon_ColGrab_H_Max->setValue(135);

        gridLayout_8->addWidget(spinBox_ProcCon_ColGrab_H_Max, 1, 1, 1, 1);

        label_10 = new QLabel(groupBox_Foreground);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 0));
        label_10->setMaximumSize(QSize(65, 16777215));

        gridLayout_8->addWidget(label_10, 1, 0, 1, 1);

        spinBox_ProcCon_ColGrab_S_Min = new QSpinBox(groupBox_Foreground);
        spinBox_ProcCon_ColGrab_S_Min->setObjectName(QString::fromUtf8("spinBox_ProcCon_ColGrab_S_Min"));
        sizePolicy2.setHeightForWidth(spinBox_ProcCon_ColGrab_S_Min->sizePolicy().hasHeightForWidth());
        spinBox_ProcCon_ColGrab_S_Min->setSizePolicy(sizePolicy2);
        spinBox_ProcCon_ColGrab_S_Min->setMinimumSize(QSize(40, 0));
        spinBox_ProcCon_ColGrab_S_Min->setMaximumSize(QSize(40, 20));
        spinBox_ProcCon_ColGrab_S_Min->setMaximum(255);
        spinBox_ProcCon_ColGrab_S_Min->setValue(11);

        gridLayout_8->addWidget(spinBox_ProcCon_ColGrab_S_Min, 0, 2, 1, 1);

        spinBox_ProcCon_ColGrab_V_Max = new QSpinBox(groupBox_Foreground);
        spinBox_ProcCon_ColGrab_V_Max->setObjectName(QString::fromUtf8("spinBox_ProcCon_ColGrab_V_Max"));
        sizePolicy2.setHeightForWidth(spinBox_ProcCon_ColGrab_V_Max->sizePolicy().hasHeightForWidth());
        spinBox_ProcCon_ColGrab_V_Max->setSizePolicy(sizePolicy2);
        spinBox_ProcCon_ColGrab_V_Max->setMinimumSize(QSize(40, 0));
        spinBox_ProcCon_ColGrab_V_Max->setMaximumSize(QSize(40, 20));
        spinBox_ProcCon_ColGrab_V_Max->setMaximum(255);
        spinBox_ProcCon_ColGrab_V_Max->setValue(255);

        gridLayout_8->addWidget(spinBox_ProcCon_ColGrab_V_Max, 1, 3, 1, 1);

        spinBox_ProcCon_ColGrab_S_Max = new QSpinBox(groupBox_Foreground);
        spinBox_ProcCon_ColGrab_S_Max->setObjectName(QString::fromUtf8("spinBox_ProcCon_ColGrab_S_Max"));
        sizePolicy2.setHeightForWidth(spinBox_ProcCon_ColGrab_S_Max->sizePolicy().hasHeightForWidth());
        spinBox_ProcCon_ColGrab_S_Max->setSizePolicy(sizePolicy2);
        spinBox_ProcCon_ColGrab_S_Max->setMinimumSize(QSize(40, 0));
        spinBox_ProcCon_ColGrab_S_Max->setMaximumSize(QSize(40, 20));
        spinBox_ProcCon_ColGrab_S_Max->setMaximum(255);
        spinBox_ProcCon_ColGrab_S_Max->setValue(255);

        gridLayout_8->addWidget(spinBox_ProcCon_ColGrab_S_Max, 1, 2, 1, 1);

        label_13 = new QLabel(groupBox_Foreground);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(0, 0));
        label_13->setMaximumSize(QSize(65, 16777215));

        gridLayout_8->addWidget(label_13, 2, 0, 1, 1);

        label_14 = new QLabel(groupBox_Foreground);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_8->addWidget(label_14, 2, 4, 1, 1);

        label_12 = new QLabel(groupBox_Foreground);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_8->addWidget(label_12, 0, 4, 2, 1);

        label_35 = new QLabel(groupBox_Foreground);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setMinimumSize(QSize(0, 0));
        label_35->setMaximumSize(QSize(65, 16777215));

        gridLayout_8->addWidget(label_35, 3, 0, 1, 1);

        label_36 = new QLabel(groupBox_Foreground);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_8->addWidget(label_36, 3, 4, 1, 1);

        spinBox_ProcCon_CellCol_Black_Noise = new QSpinBox(groupBox_Foreground);
        spinBox_ProcCon_CellCol_Black_Noise->setObjectName(QString::fromUtf8("spinBox_ProcCon_CellCol_Black_Noise"));
        spinBox_ProcCon_CellCol_Black_Noise->setMinimumSize(QSize(126, 0));
        spinBox_ProcCon_CellCol_Black_Noise->setMaximumSize(QSize(126, 16777215));
        spinBox_ProcCon_CellCol_Black_Noise->setMinimum(1);
        spinBox_ProcCon_CellCol_Black_Noise->setMaximum(100);
        spinBox_ProcCon_CellCol_Black_Noise->setSingleStep(2);
        spinBox_ProcCon_CellCol_Black_Noise->setValue(7);

        gridLayout_8->addWidget(spinBox_ProcCon_CellCol_Black_Noise, 2, 1, 1, 3);

        spinBox_ProcCon_CellCol_White_Noise = new QSpinBox(groupBox_Foreground);
        spinBox_ProcCon_CellCol_White_Noise->setObjectName(QString::fromUtf8("spinBox_ProcCon_CellCol_White_Noise"));
        spinBox_ProcCon_CellCol_White_Noise->setMinimumSize(QSize(126, 0));
        spinBox_ProcCon_CellCol_White_Noise->setMaximumSize(QSize(126, 16777215));
        spinBox_ProcCon_CellCol_White_Noise->setMinimum(1);
        spinBox_ProcCon_CellCol_White_Noise->setMaximum(100);
        spinBox_ProcCon_CellCol_White_Noise->setSingleStep(2);
        spinBox_ProcCon_CellCol_White_Noise->setValue(5);

        gridLayout_8->addWidget(spinBox_ProcCon_CellCol_White_Noise, 3, 1, 1, 3);


        gridLayout_24->addWidget(groupBox_Foreground, 2, 0, 1, 1);

        groupBox_Measure = new QGroupBox(tab_Processing);
        groupBox_Measure->setObjectName(QString::fromUtf8("groupBox_Measure"));
        groupBox_Measure->setFlat(true);
        gridLayout_30 = new QGridLayout(groupBox_Measure);
        gridLayout_30->setSpacing(3);
        gridLayout_30->setObjectName(QString::fromUtf8("gridLayout_30"));
        gridLayout_30->setContentsMargins(6, 6, 6, 6);
        label_41 = new QLabel(groupBox_Measure);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setMinimumSize(QSize(0, 0));
        label_41->setMaximumSize(QSize(65, 16777215));

        gridLayout_30->addWidget(label_41, 0, 0, 1, 1);

        doubleSpinBox_Measure_Base = new QDoubleSpinBox(groupBox_Measure);
        doubleSpinBox_Measure_Base->setObjectName(QString::fromUtf8("doubleSpinBox_Measure_Base"));
        doubleSpinBox_Measure_Base->setMinimumSize(QSize(126, 0));
        doubleSpinBox_Measure_Base->setMaximumSize(QSize(126, 16777215));
        doubleSpinBox_Measure_Base->setDecimals(6);
        doubleSpinBox_Measure_Base->setMinimum(0.000001000000000);
        doubleSpinBox_Measure_Base->setMaximum(0.999999000000000);
        doubleSpinBox_Measure_Base->setSingleStep(0.001000000000000);
        doubleSpinBox_Measure_Base->setValue(0.920000000000000);

        gridLayout_30->addWidget(doubleSpinBox_Measure_Base, 0, 1, 1, 1);

        doubleSpinBox_Measure_Factor = new QDoubleSpinBox(groupBox_Measure);
        doubleSpinBox_Measure_Factor->setObjectName(QString::fromUtf8("doubleSpinBox_Measure_Factor"));
        doubleSpinBox_Measure_Factor->setMinimumSize(QSize(126, 0));
        doubleSpinBox_Measure_Factor->setMaximumSize(QSize(126, 16777215));
        doubleSpinBox_Measure_Factor->setDecimals(6);
        doubleSpinBox_Measure_Factor->setMinimum(0.000001000000000);
        doubleSpinBox_Measure_Factor->setMaximum(100.000000000000000);
        doubleSpinBox_Measure_Factor->setSingleStep(0.001000000000000);
        doubleSpinBox_Measure_Factor->setValue(1.800000000000000);

        gridLayout_30->addWidget(doubleSpinBox_Measure_Factor, 1, 1, 1, 1);

        label_42 = new QLabel(groupBox_Measure);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setMinimumSize(QSize(0, 0));
        label_42->setMaximumSize(QSize(65, 16777215));

        gridLayout_30->addWidget(label_42, 1, 0, 1, 1);

        label_43 = new QLabel(groupBox_Measure);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        gridLayout_30->addWidget(label_43, 0, 2, 1, 1);

        label_44 = new QLabel(groupBox_Measure);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        gridLayout_30->addWidget(label_44, 1, 2, 1, 1);


        gridLayout_24->addWidget(groupBox_Measure, 5, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_24->addItem(verticalSpacer_3, 6, 0, 1, 1);

        tabWidget_Control->addTab(tab_Processing, QString());
        tab_Output = new QWidget();
        tab_Output->setObjectName(QString::fromUtf8("tab_Output"));
        gridLayout_28 = new QGridLayout(tab_Output);
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        groupBox_Output_Img = new QGroupBox(tab_Output);
        groupBox_Output_Img->setObjectName(QString::fromUtf8("groupBox_Output_Img"));
        groupBox_Output_Img->setFlat(true);
        gridLayout_34 = new QGridLayout(groupBox_Output_Img);
        gridLayout_34->setSpacing(3);
        gridLayout_34->setObjectName(QString::fromUtf8("gridLayout_34"));
        gridLayout_34->setContentsMargins(6, 6, 6, 6);
        groupBox_Output_Img_Images = new QGroupBox(groupBox_Output_Img);
        groupBox_Output_Img_Images->setObjectName(QString::fromUtf8("groupBox_Output_Img_Images"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(1);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(groupBox_Output_Img_Images->sizePolicy().hasHeightForWidth());
        groupBox_Output_Img_Images->setSizePolicy(sizePolicy7);
        gridLayout_26 = new QGridLayout(groupBox_Output_Img_Images);
        gridLayout_26->setSpacing(3);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        gridLayout_26->setContentsMargins(6, 6, 6, 6);
        checkBox_Output_CellCount = new QCheckBox(groupBox_Output_Img_Images);
        checkBox_Output_CellCount->setObjectName(QString::fromUtf8("checkBox_Output_CellCount"));
        checkBox_Output_CellCount->setChecked(true);

        gridLayout_26->addWidget(checkBox_Output_CellCount, 4, 0, 1, 1);

        checkBox_Output_Labeling = new QCheckBox(groupBox_Output_Img_Images);
        checkBox_Output_Labeling->setObjectName(QString::fromUtf8("checkBox_Output_Labeling"));
        checkBox_Output_Labeling->setChecked(true);

        gridLayout_26->addWidget(checkBox_Output_Labeling, 1, 0, 1, 1);

        checkBox_Output_Surrival = new QCheckBox(groupBox_Output_Img_Images);
        checkBox_Output_Surrival->setObjectName(QString::fromUtf8("checkBox_Output_Surrival"));
        checkBox_Output_Surrival->setChecked(true);

        gridLayout_26->addWidget(checkBox_Output_Surrival, 2, 0, 1, 1);

        checkBox_Output_Segmentation = new QCheckBox(groupBox_Output_Img_Images);
        checkBox_Output_Segmentation->setObjectName(QString::fromUtf8("checkBox_Output_Segmentation"));

        gridLayout_26->addWidget(checkBox_Output_Segmentation, 0, 0, 1, 1);

        checkBox_Output_Area = new QCheckBox(groupBox_Output_Img_Images);
        checkBox_Output_Area->setObjectName(QString::fromUtf8("checkBox_Output_Area"));
        checkBox_Output_Area->setChecked(true);

        gridLayout_26->addWidget(checkBox_Output_Area, 3, 0, 1, 1);

        checkBox_Output_ProcSteps = new QCheckBox(groupBox_Output_Img_Images);
        checkBox_Output_ProcSteps->setObjectName(QString::fromUtf8("checkBox_Output_ProcSteps"));

        gridLayout_26->addWidget(checkBox_Output_ProcSteps, 5, 0, 1, 1);


        gridLayout_34->addWidget(groupBox_Output_Img_Images, 0, 0, 2, 1);

        groupBox_Output_Img_Plots = new QGroupBox(groupBox_Output_Img);
        groupBox_Output_Img_Plots->setObjectName(QString::fromUtf8("groupBox_Output_Img_Plots"));
        sizePolicy7.setHeightForWidth(groupBox_Output_Img_Plots->sizePolicy().hasHeightForWidth());
        groupBox_Output_Img_Plots->setSizePolicy(sizePolicy7);
        gridLayout_33 = new QGridLayout(groupBox_Output_Img_Plots);
        gridLayout_33->setSpacing(3);
        gridLayout_33->setObjectName(QString::fromUtf8("gridLayout_33"));
        gridLayout_33->setContentsMargins(6, 6, 6, 6);
        checkBox_Output_Plot_Img_Hist = new QCheckBox(groupBox_Output_Img_Plots);
        checkBox_Output_Plot_Img_Hist->setObjectName(QString::fromUtf8("checkBox_Output_Plot_Img_Hist"));
        checkBox_Output_Plot_Img_Hist->setChecked(true);

        gridLayout_33->addWidget(checkBox_Output_Plot_Img_Hist, 1, 0, 1, 1);

        checkBox_Output_Plot_Img_Surrival = new QCheckBox(groupBox_Output_Img_Plots);
        checkBox_Output_Plot_Img_Surrival->setObjectName(QString::fromUtf8("checkBox_Output_Plot_Img_Surrival"));
        checkBox_Output_Plot_Img_Surrival->setChecked(true);

        gridLayout_33->addWidget(checkBox_Output_Plot_Img_Surrival, 0, 0, 1, 1);

        checkBox_Output_Plot_Img_Scatter = new QCheckBox(groupBox_Output_Img_Plots);
        checkBox_Output_Plot_Img_Scatter->setObjectName(QString::fromUtf8("checkBox_Output_Plot_Img_Scatter"));

        gridLayout_33->addWidget(checkBox_Output_Plot_Img_Scatter, 2, 0, 1, 1);


        gridLayout_34->addWidget(groupBox_Output_Img_Plots, 0, 1, 1, 1);

        groupBox_Output_Img_CSV = new QGroupBox(groupBox_Output_Img);
        groupBox_Output_Img_CSV->setObjectName(QString::fromUtf8("groupBox_Output_Img_CSV"));
        sizePolicy7.setHeightForWidth(groupBox_Output_Img_CSV->sizePolicy().hasHeightForWidth());
        groupBox_Output_Img_CSV->setSizePolicy(sizePolicy7);
        groupBox_Output_Img_CSV->setFlat(false);
        gridLayout_25 = new QGridLayout(groupBox_Output_Img_CSV);
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_25->addItem(verticalSpacer, 2, 0, 1, 1);

        checkBox_Output_CSV_Parameter = new QCheckBox(groupBox_Output_Img_CSV);
        checkBox_Output_CSV_Parameter->setObjectName(QString::fromUtf8("checkBox_Output_CSV_Parameter"));
        checkBox_Output_CSV_Parameter->setChecked(true);

        gridLayout_25->addWidget(checkBox_Output_CSV_Parameter, 0, 0, 1, 1);


        gridLayout_34->addWidget(groupBox_Output_Img_CSV, 1, 1, 1, 1);


        gridLayout_28->addWidget(groupBox_Output_Img, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_28->addItem(verticalSpacer_2, 8, 0, 1, 2);

        groupBox_Output_Col = new QGroupBox(tab_Output);
        groupBox_Output_Col->setObjectName(QString::fromUtf8("groupBox_Output_Col"));
        groupBox_Output_Col->setFlat(true);
        gridLayout_35 = new QGridLayout(groupBox_Output_Col);
        gridLayout_35->setSpacing(3);
        gridLayout_35->setObjectName(QString::fromUtf8("gridLayout_35"));
        gridLayout_35->setContentsMargins(6, 6, 6, 6);
        groupBox_Output_Col_Plots = new QGroupBox(groupBox_Output_Col);
        groupBox_Output_Col_Plots->setObjectName(QString::fromUtf8("groupBox_Output_Col_Plots"));
        sizePolicy7.setHeightForWidth(groupBox_Output_Col_Plots->sizePolicy().hasHeightForWidth());
        groupBox_Output_Col_Plots->setSizePolicy(sizePolicy7);
        gridLayout_29 = new QGridLayout(groupBox_Output_Col_Plots);
        gridLayout_29->setSpacing(3);
        gridLayout_29->setObjectName(QString::fromUtf8("gridLayout_29"));
        gridLayout_29->setContentsMargins(6, 6, 6, 6);
        checkBox_Output_Plot_Col_ADM = new QCheckBox(groupBox_Output_Col_Plots);
        checkBox_Output_Plot_Col_ADM->setObjectName(QString::fromUtf8("checkBox_Output_Plot_Col_ADM"));

        gridLayout_29->addWidget(checkBox_Output_Plot_Col_ADM, 4, 0, 1, 1);

        checkBox_Output_Plot_Col_CV = new QCheckBox(groupBox_Output_Col_Plots);
        checkBox_Output_Plot_Col_CV->setObjectName(QString::fromUtf8("checkBox_Output_Plot_Col_CV"));

        gridLayout_29->addWidget(checkBox_Output_Plot_Col_CV, 5, 0, 1, 1);

        checkBox_Output_Plot_Col_SD = new QCheckBox(groupBox_Output_Col_Plots);
        checkBox_Output_Plot_Col_SD->setObjectName(QString::fromUtf8("checkBox_Output_Plot_Col_SD"));
        checkBox_Output_Plot_Col_SD->setChecked(true);

        gridLayout_29->addWidget(checkBox_Output_Plot_Col_SD, 2, 0, 1, 1);

        checkBox_Output_Plot_Col_Mean = new QCheckBox(groupBox_Output_Col_Plots);
        checkBox_Output_Plot_Col_Mean->setObjectName(QString::fromUtf8("checkBox_Output_Plot_Col_Mean"));
        checkBox_Output_Plot_Col_Mean->setChecked(true);

        gridLayout_29->addWidget(checkBox_Output_Plot_Col_Mean, 1, 0, 1, 1);

        checkBox_Output_Plot_Col_Median = new QCheckBox(groupBox_Output_Col_Plots);
        checkBox_Output_Plot_Col_Median->setObjectName(QString::fromUtf8("checkBox_Output_Plot_Col_Median"));
        checkBox_Output_Plot_Col_Median->setChecked(true);

        gridLayout_29->addWidget(checkBox_Output_Plot_Col_Median, 3, 0, 1, 1);

        checkBox_Output_Plot_Col_Hist = new QCheckBox(groupBox_Output_Col_Plots);
        checkBox_Output_Plot_Col_Hist->setObjectName(QString::fromUtf8("checkBox_Output_Plot_Col_Hist"));
        checkBox_Output_Plot_Col_Hist->setChecked(true);

        gridLayout_29->addWidget(checkBox_Output_Plot_Col_Hist, 0, 0, 1, 1);

        checkBox_Output_Plot_Col_Quantiles = new QCheckBox(groupBox_Output_Col_Plots);
        checkBox_Output_Plot_Col_Quantiles->setObjectName(QString::fromUtf8("checkBox_Output_Plot_Col_Quantiles"));
        checkBox_Output_Plot_Col_Quantiles->setChecked(false);

        gridLayout_29->addWidget(checkBox_Output_Plot_Col_Quantiles, 8, 0, 1, 1);

        checkBox_Output_Plot_Col_Skewness = new QCheckBox(groupBox_Output_Col_Plots);
        checkBox_Output_Plot_Col_Skewness->setObjectName(QString::fromUtf8("checkBox_Output_Plot_Col_Skewness"));

        gridLayout_29->addWidget(checkBox_Output_Plot_Col_Skewness, 6, 0, 1, 1);

        checkBox_Output_Plot_Col_Kurtosis = new QCheckBox(groupBox_Output_Col_Plots);
        checkBox_Output_Plot_Col_Kurtosis->setObjectName(QString::fromUtf8("checkBox_Output_Plot_Col_Kurtosis"));

        gridLayout_29->addWidget(checkBox_Output_Plot_Col_Kurtosis, 7, 0, 1, 1);


        gridLayout_35->addWidget(groupBox_Output_Col_Plots, 2, 0, 1, 1);

        groupBox_Output_Col_CSV = new QGroupBox(groupBox_Output_Col);
        groupBox_Output_Col_CSV->setObjectName(QString::fromUtf8("groupBox_Output_Col_CSV"));
        sizePolicy7.setHeightForWidth(groupBox_Output_Col_CSV->sizePolicy().hasHeightForWidth());
        groupBox_Output_Col_CSV->setSizePolicy(sizePolicy7);
        gridLayout_27 = new QGridLayout(groupBox_Output_Col_CSV);
        gridLayout_27->setSpacing(3);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        gridLayout_27->setContentsMargins(6, 6, 6, 6);
        checkBox_Output_CSV_Results = new QCheckBox(groupBox_Output_Col_CSV);
        checkBox_Output_CSV_Results->setObjectName(QString::fromUtf8("checkBox_Output_CSV_Results"));
        checkBox_Output_CSV_Results->setChecked(true);

        gridLayout_27->addWidget(checkBox_Output_CSV_Results, 0, 0, 1, 1);

        checkBox_Output_CSV_RawData = new QCheckBox(groupBox_Output_Col_CSV);
        checkBox_Output_CSV_RawData->setObjectName(QString::fromUtf8("checkBox_Output_CSV_RawData"));
        checkBox_Output_CSV_RawData->setChecked(true);

        gridLayout_27->addWidget(checkBox_Output_CSV_RawData, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_27->addItem(verticalSpacer_4, 2, 0, 1, 1);


        gridLayout_35->addWidget(groupBox_Output_Col_CSV, 2, 1, 1, 1);

        groupBox_Output_Col_Types = new QGroupBox(groupBox_Output_Col);
        groupBox_Output_Col_Types->setObjectName(QString::fromUtf8("groupBox_Output_Col_Types"));
        groupBox_Output_Col_Types->setFlat(true);
        gridLayout_36 = new QGridLayout(groupBox_Output_Col_Types);
        gridLayout_36->setSpacing(3);
        gridLayout_36->setObjectName(QString::fromUtf8("gridLayout_36"));
        gridLayout_36->setContentsMargins(6, 6, 6, 6);
        checkBox_Output_Absorbtion = new QCheckBox(groupBox_Output_Col_Types);
        checkBox_Output_Absorbtion->setObjectName(QString::fromUtf8("checkBox_Output_Absorbtion"));
        checkBox_Output_Absorbtion->setChecked(true);

        gridLayout_36->addWidget(checkBox_Output_Absorbtion, 0, 0, 1, 1);

        checkBox_Output_Transmission = new QCheckBox(groupBox_Output_Col_Types);
        checkBox_Output_Transmission->setObjectName(QString::fromUtf8("checkBox_Output_Transmission"));
        checkBox_Output_Transmission->setChecked(true);

        gridLayout_36->addWidget(checkBox_Output_Transmission, 0, 1, 1, 1);

        checkBox_Output_TransmissionRadial = new QCheckBox(groupBox_Output_Col_Types);
        checkBox_Output_TransmissionRadial->setObjectName(QString::fromUtf8("checkBox_Output_TransmissionRadial"));
        checkBox_Output_TransmissionRadial->setChecked(true);

        gridLayout_36->addWidget(checkBox_Output_TransmissionRadial, 1, 0, 1, 1);

        checkBox_Output_CellDensity = new QCheckBox(groupBox_Output_Col_Types);
        checkBox_Output_CellDensity->setObjectName(QString::fromUtf8("checkBox_Output_CellDensity"));
        checkBox_Output_CellDensity->setChecked(true);

        gridLayout_36->addWidget(checkBox_Output_CellDensity, 1, 1, 1, 1);


        gridLayout_35->addWidget(groupBox_Output_Col_Types, 1, 0, 1, 2);

        groupBox = new QGroupBox(groupBox_Output_Col);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_37 = new QGridLayout(groupBox);
        gridLayout_37->setSpacing(3);
        gridLayout_37->setObjectName(QString::fromUtf8("gridLayout_37"));
        gridLayout_37->setContentsMargins(6, 6, 6, 6);
        checkBox_Output_TransRad = new QCheckBox(groupBox);
        checkBox_Output_TransRad->setObjectName(QString::fromUtf8("checkBox_Output_TransRad"));
        checkBox_Output_TransRad->setChecked(true);

        gridLayout_37->addWidget(checkBox_Output_TransRad, 0, 0, 1, 1);


        gridLayout_35->addWidget(groupBox, 0, 0, 1, 2);


        gridLayout_28->addWidget(groupBox_Output_Col, 1, 0, 1, 1);

        tabWidget_Control->addTab(tab_Output, QString());

        gridLayout_2->addWidget(tabWidget_Control, 0, 0, 1, 1);

        groupBox_Surrival = new QGroupBox(groupBox_Control);
        groupBox_Surrival->setObjectName(QString::fromUtf8("groupBox_Surrival"));
        groupBox_Surrival->setEnabled(true);
        groupBox_Surrival->setFlat(true);
        gridLayout_22 = new QGridLayout(groupBox_Surrival);
        gridLayout_22->setSpacing(3);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        gridLayout_22->setContentsMargins(6, 6, 6, 6);
        label_11 = new QLabel(groupBox_Surrival);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(0, 0));
        label_11->setMaximumSize(QSize(75, 16777215));

        gridLayout_22->addWidget(label_11, 0, 0, 1, 1);

        label_19 = new QLabel(groupBox_Surrival);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_22->addWidget(label_19, 0, 2, 1, 1);

        doubleSpinBox_Sur_CellCount = new QDoubleSpinBox(groupBox_Surrival);
        doubleSpinBox_Sur_CellCount->setObjectName(QString::fromUtf8("doubleSpinBox_Sur_CellCount"));
        doubleSpinBox_Sur_CellCount->setMinimumSize(QSize(126, 0));
        doubleSpinBox_Sur_CellCount->setMaximumSize(QSize(126, 16777215));
        doubleSpinBox_Sur_CellCount->setMaximum(10000000000000.000000000000000);
        doubleSpinBox_Sur_CellCount->setValue(50.000000000000000);

        gridLayout_22->addWidget(doubleSpinBox_Sur_CellCount, 0, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_Surrival, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_Control, 0, 1, 2, 1);

        D_MAKRO_CellColonies->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_CellColonies);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1144, 21));
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
        menuStack = new QMenu(menubar);
        menuStack->setObjectName(QString::fromUtf8("menuStack"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        D_MAKRO_CellColonies->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_CellColonies);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_CellColonies->setStatusBar(statusbar);

        menubar->addAction(menuData->menuAction());
        menubar->addAction(menuLayout->menuAction());
        menubar->addAction(menuViewer->menuAction());
        menubar->addAction(menuUpdate->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menubar->addAction(menuStack->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menuData->addAction(action_Load_Images);
        menuData->addAction(action_Clear_Queue);
        menuData->addSeparator();
        menuData->addAction(action_Save_Image_Cells);
        menuData->addAction(action_Save_Image_Color);
        menuData->addAction(action_Save_Image_Surrival);
        menuData->addAction(action_Save_Image_Segmentation);
        menuData->addAction(action_Save_Image_Attribute);
        menuData->addSeparator();
        menuData->addAction(action_Save_Plot_Value_in_Colony);
        menuData->addAction(action_Save_Plot_Colony_in_Image);
        menuData->addAction(action_Save_Plot_Surrival);
        menuData->addSeparator();
        menuData->addAction(action_Save_whole_Analysis);
        menuLayout->addAction(action_Show_Processing);
        menuLayout->addAction(action_Show_Results);
        menuLayout->addAction(action_Show_Control);
        menuViewer->addAction(action_Smooth_Transformation);
        menuViewer->addAction(action_Keep_Aspect_Ratio);
        menuUpdate->addAction(action_Update_View);
        menuUpdate->addAction(action_Update_ImgProc);
        menuWindow->addAction(action_Show_Minimize);
        menuWindow->addAction(action_Show_Normal);
        menuWindow->addAction(action_Show_Maximize);
        menuWindow->addAction(action_Show_Fullscreen);
        menuStack->addAction(action_Next_Image);
        menuStack->addAction(action_Last_Image);
        menuStack->addSeparator();
        menuStack->addAction(action_Analyze_Stack);
        menuSettings->addAction(action_SettingsReset);

        retranslateUi(D_MAKRO_CellColonies);
        QObject::connect(action_Show_Fullscreen, SIGNAL(triggered()), D_MAKRO_CellColonies, SLOT(showFullScreen()));
        QObject::connect(action_Show_Maximize, SIGNAL(triggered()), D_MAKRO_CellColonies, SLOT(showMaximized()));
        QObject::connect(action_Show_Minimize, SIGNAL(triggered()), D_MAKRO_CellColonies, SLOT(showMinimized()));
        QObject::connect(action_Show_Normal, SIGNAL(triggered()), D_MAKRO_CellColonies, SLOT(showNormal()));
        QObject::connect(action_Show_Processing, SIGNAL(triggered(bool)), groupBox_ProcView, SLOT(setVisible(bool)));
        QObject::connect(action_Show_Results, SIGNAL(triggered(bool)), groupBox_ResView, SLOT(setVisible(bool)));
        QObject::connect(comboBox_Res_PlotType, SIGNAL(currentIndexChanged(int)), stackedWidget_ResPlo_Type, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_Res_PlotType_Img, SIGNAL(currentIndexChanged(int)), stackedWidget_ResPlo_Type_Img, SLOT(setCurrentIndex(int)));
        QObject::connect(action_Show_Control, SIGNAL(triggered(bool)), groupBox_Control, SLOT(setVisible(bool)));

        tabWidget_Res->setCurrentIndex(0);
        stackedWidget_ResPlo_Type->setCurrentIndex(0);
        tabWidget_Control->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(D_MAKRO_CellColonies);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_CellColonies)
    {
        D_MAKRO_CellColonies->setWindowTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "MainWindow", nullptr));
        action_Show_Normal->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Normal", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Normal->setShortcut(QCoreApplication::translate("D_MAKRO_CellColonies", "F10", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Minimize->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Minimize", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Minimize->setShortcut(QCoreApplication::translate("D_MAKRO_CellColonies", "F9", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Maximize->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Maximize", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Maximize->setShortcut(QCoreApplication::translate("D_MAKRO_CellColonies", "F11", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Fullscreen->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Fullscreen", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Fullscreen->setShortcut(QCoreApplication::translate("D_MAKRO_CellColonies", "F12", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Load_Images->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Load Image Stack", nullptr));
#if QT_CONFIG(shortcut)
        action_Load_Images->setShortcut(QCoreApplication::translate("D_MAKRO_CellColonies", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Clear_Queue->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Clear Image Stack", nullptr));
        action_Show_Processing->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Show Processing", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Processing->setShortcut(QCoreApplication::translate("D_MAKRO_CellColonies", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Results->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Show Results", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Results->setShortcut(QCoreApplication::translate("D_MAKRO_CellColonies", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Smooth_Transformation->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Smooth Transformation", nullptr));
        action_Keep_Aspect_Ratio->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Keep Aspect Ratio", nullptr));
        action_Update_View->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Update View", nullptr));
#if QT_CONFIG(shortcut)
        action_Update_View->setShortcut(QCoreApplication::translate("D_MAKRO_CellColonies", "F4", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Update_ImgProc->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Update Image Processing", nullptr));
#if QT_CONFIG(shortcut)
        action_Update_ImgProc->setShortcut(QCoreApplication::translate("D_MAKRO_CellColonies", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Next_Image->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Next Image", nullptr));
#if QT_CONFIG(shortcut)
        action_Next_Image->setShortcut(QCoreApplication::translate("D_MAKRO_CellColonies", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Last_Image->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Last Image", nullptr));
#if QT_CONFIG(shortcut)
        action_Last_Image->setShortcut(QCoreApplication::translate("D_MAKRO_CellColonies", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Control->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Show Control", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Control->setShortcut(QCoreApplication::translate("D_MAKRO_CellColonies", "F3", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Save_Image_Cells->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Save Image Processing", nullptr));
        action_Save_Image_Color->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Save Image Results", nullptr));
        action_Save_Plot_Value_in_Colony->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Save Plot Value in Colony", nullptr));
        action_Save_Plot_Colony_in_Image->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Save Plot Colony in Image", nullptr));
        action_Save_Image_Surrival->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Save Image Surrival", nullptr));
        action_Save_Image_Segmentation->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Save Image Segmentation", nullptr));
        action_Save_whole_Analysis->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Save Analysis", nullptr));
#if QT_CONFIG(shortcut)
        action_Save_whole_Analysis->setShortcut(QCoreApplication::translate("D_MAKRO_CellColonies", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Analyze_Stack->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Analyze Stack and Save Analyzes", nullptr));
#if QT_CONFIG(shortcut)
        action_Analyze_Stack->setShortcut(QCoreApplication::translate("D_MAKRO_CellColonies", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Save_Plot_Surrival->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Save Plot Surrival", nullptr));
        action_Save_Image_Attribute->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Save Image Attribute", nullptr));
        action_SettingsReset->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Reset to default", nullptr));
        groupBox_ResView->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Results - View", nullptr));
        comboBox_ResImg_Color->setItemText(0, QCoreApplication::translate("D_MAKRO_CellColonies", "RGB - Input", nullptr));
        comboBox_ResImg_Color->setItemText(1, QCoreApplication::translate("D_MAKRO_CellColonies", "RGB - Shading corrected", nullptr));
        comboBox_ResImg_Color->setItemText(2, QCoreApplication::translate("D_MAKRO_CellColonies", "RGB - Reference minus Input", nullptr));
        comboBox_ResImg_Color->setItemText(3, QCoreApplication::translate("D_MAKRO_CellColonies", "HSV - Shading corrected", nullptr));
        comboBox_ResImg_Color->setItemText(4, QCoreApplication::translate("D_MAKRO_CellColonies", "HSV - Reference minus Input", nullptr));
        comboBox_ResImg_Color->setItemText(5, QCoreApplication::translate("D_MAKRO_CellColonies", "Saturation - Finding Seeds", nullptr));
        comboBox_ResImg_Color->setItemText(6, QCoreApplication::translate("D_MAKRO_CellColonies", "Value - Measurement", nullptr));

        label_28->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Binary:", nullptr));
        label_27->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Color:", nullptr));
        comboBox_ResImg_Binary->setItemText(0, QCoreApplication::translate("D_MAKRO_CellColonies", "Edges", nullptr));
        comboBox_ResImg_Binary->setItemText(1, QCoreApplication::translate("D_MAKRO_CellColonies", "Numbers", nullptr));
        comboBox_ResImg_Binary->setItemText(2, QCoreApplication::translate("D_MAKRO_CellColonies", "Edges and Numbers", nullptr));
        comboBox_ResImg_Binary->setItemText(3, QCoreApplication::translate("D_MAKRO_CellColonies", "out of Roi", nullptr));
        comboBox_ResImg_Binary->setItemText(4, QCoreApplication::translate("D_MAKRO_CellColonies", "in Roi", nullptr));

        tabWidget_Res->setTabText(tabWidget_Res->indexOf(tab_Res_Image), QCoreApplication::translate("D_MAKRO_CellColonies", "Base Image", nullptr));
        comboBox_Res_PlotType->setItemText(0, QCoreApplication::translate("D_MAKRO_CellColonies", "Histogram - Colonies", nullptr));
        comboBox_Res_PlotType->setItemText(1, QCoreApplication::translate("D_MAKRO_CellColonies", "Compare statistical quantities", nullptr));
        comboBox_Res_PlotType->setItemText(2, QCoreApplication::translate("D_MAKRO_CellColonies", "Mean Median SD ADM", nullptr));
        comboBox_Res_PlotType->setItemText(3, QCoreApplication::translate("D_MAKRO_CellColonies", "CV Skewness Kurtosis", nullptr));
        comboBox_Res_PlotType->setItemText(4, QCoreApplication::translate("D_MAKRO_CellColonies", "Quantiles", nullptr));
        comboBox_Res_PlotType->setItemText(5, QCoreApplication::translate("D_MAKRO_CellColonies", "Radial Transmission", nullptr));

        checkBox_ResPlo_HisCol_Uniform->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Uniform", nullptr));
        checkBox_ResPlo_HisCol_Accumulate->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Accumulate", nullptr));
        label_6->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "X:", nullptr));
        label_29->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Y:", nullptr));
        checkBox_ResPlo_MM_Median->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Median", nullptr));
        checkBox_ResPlo_MM_Mean->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Mean", nullptr));
        checkBox_ResPlo_MM_SD->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Standard Devaiation", nullptr));
        checkBox_ResPlo_MM_ADM->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Average Absolute Deviation from Median", nullptr));
        checkBox_ResPlo_CSK_CV->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Coefficient of Variance", nullptr));
        checkBox_ResPlo_CSK_Skewness->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Skewness", nullptr));
        checkBox_ResPlo_CSK_Kurtosis->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Kurtosis", nullptr));
        comboBox_ResPlo_Quant_Steps->setItemText(0, QCoreApplication::translate("D_MAKRO_CellColonies", "05", nullptr));
        comboBox_ResPlo_Quant_Steps->setItemText(1, QCoreApplication::translate("D_MAKRO_CellColonies", "10", nullptr));
        comboBox_ResPlo_Quant_Steps->setItemText(2, QCoreApplication::translate("D_MAKRO_CellColonies", "20", nullptr));
        comboBox_ResPlo_Quant_Steps->setItemText(3, QCoreApplication::translate("D_MAKRO_CellColonies", "25", nullptr));
        comboBox_ResPlo_Quant_Steps->setItemText(4, QCoreApplication::translate("D_MAKRO_CellColonies", "50", nullptr));

        label_30->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "% Steps", nullptr));
        tabWidget_Res->setTabText(tabWidget_Res->indexOf(tab_Res_Plot), QCoreApplication::translate("D_MAKRO_CellColonies", "Plot - Value/Colony", nullptr));
        comboBox_Res_PlotType_Img->setItemText(0, QCoreApplication::translate("D_MAKRO_CellColonies", "Histogram - Image", nullptr));
        comboBox_Res_PlotType_Img->setItemText(1, QCoreApplication::translate("D_MAKRO_CellColonies", "Compare Attributes", nullptr));

        checkBox_ResPlo_HisImg_Uniform->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Uniform", nullptr));
        checkBox_ResPlo_HisImg_Accumulate->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Accumulate", nullptr));
        label_31->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "X:", nullptr));
        label_32->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Y:", nullptr));
        tabWidget_Res->setTabText(tabWidget_Res->indexOf(tab_Res_Plot_Img), QCoreApplication::translate("D_MAKRO_CellColonies", "Plot - Colony/Image", nullptr));
        tabWidget_Res->setTabText(tabWidget_Res->indexOf(tab_res_Surrival), QCoreApplication::translate("D_MAKRO_CellColonies", "Surrival", nullptr));
        tabWidget_Res->setTabText(tabWidget_Res->indexOf(tab_res_Segmentation), QCoreApplication::translate("D_MAKRO_CellColonies", "Segmentation", nullptr));
        label_15->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Base Image:", nullptr));
        comboBox_ResAtt_BaseImage->setItemText(0, QCoreApplication::translate("D_MAKRO_CellColonies", "RGB - Input", nullptr));
        comboBox_ResAtt_BaseImage->setItemText(1, QCoreApplication::translate("D_MAKRO_CellColonies", "RGB - Shading corrected", nullptr));
        comboBox_ResAtt_BaseImage->setItemText(2, QCoreApplication::translate("D_MAKRO_CellColonies", "RGB - Refenrence minus Input", nullptr));
        comboBox_ResAtt_BaseImage->setItemText(3, QCoreApplication::translate("D_MAKRO_CellColonies", "HSV - Shading corrected", nullptr));
        comboBox_ResAtt_BaseImage->setItemText(4, QCoreApplication::translate("D_MAKRO_CellColonies", "HSV - Refenrence minus Input", nullptr));
        comboBox_ResAtt_BaseImage->setItemText(5, QCoreApplication::translate("D_MAKRO_CellColonies", "Saturation - Finding Seeds", nullptr));
        comboBox_ResAtt_BaseImage->setItemText(6, QCoreApplication::translate("D_MAKRO_CellColonies", "Value - Measurement", nullptr));

        label_21->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Attribute:", nullptr));
        checkBox_ResAtt_Border->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Border", nullptr));
        label_46->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Precision:", nullptr));
        label_45->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Scale:", nullptr));
        label_47->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Thickness:", nullptr));
        tabWidget_Res->setTabText(tabWidget_Res->indexOf(tab_res_Attribute), QCoreApplication::translate("D_MAKRO_CellColonies", "Attribute Image", nullptr));
        groupBox_ProcView->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Processing - View", nullptr));
        label_ProcView_MA->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "MA Type", nullptr));
        label_ProcView_QI->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "QI Type", nullptr));
        comboBox_ProcView_Step->setItemText(0, QCoreApplication::translate("D_MAKRO_CellColonies", "00   -   Reference   -   Loaded from File", nullptr));
        comboBox_ProcView_Step->setItemText(1, QCoreApplication::translate("D_MAKRO_CellColonies", "01   -   Reference   -   Crop Rectangle", nullptr));
        comboBox_ProcView_Step->setItemText(2, QCoreApplication::translate("D_MAKRO_CellColonies", "02   -   Reference   -   Remove Noise", nullptr));
        comboBox_ProcView_Step->setItemText(3, QCoreApplication::translate("D_MAKRO_CellColonies", "03   -   Input   -   Loaded from File", nullptr));
        comboBox_ProcView_Step->setItemText(4, QCoreApplication::translate("D_MAKRO_CellColonies", "04   -   Input   -   Crop Rectangle", nullptr));
        comboBox_ProcView_Step->setItemText(5, QCoreApplication::translate("D_MAKRO_CellColonies", "05   -   Input   -   Shading Correction", nullptr));
        comboBox_ProcView_Step->setItemText(6, QCoreApplication::translate("D_MAKRO_CellColonies", "06   -   Cells   -   Grab Color", nullptr));
        comboBox_ProcView_Step->setItemText(7, QCoreApplication::translate("D_MAKRO_CellColonies", "07   -   Cells   -   Binary", nullptr));
        comboBox_ProcView_Step->setItemText(8, QCoreApplication::translate("D_MAKRO_CellColonies", "08   -   Cells   -   Remove Black Noise", nullptr));
        comboBox_ProcView_Step->setItemText(9, QCoreApplication::translate("D_MAKRO_CellColonies", "09   -   Cells   -   Remove White Noise", nullptr));
        comboBox_ProcView_Step->setItemText(10, QCoreApplication::translate("D_MAKRO_CellColonies", "10   -   Seeds   -   HSV Transform", nullptr));
        comboBox_ProcView_Step->setItemText(11, QCoreApplication::translate("D_MAKRO_CellColonies", "11   -   Seeds   -   Grab Saturation", nullptr));
        comboBox_ProcView_Step->setItemText(12, QCoreApplication::translate("D_MAKRO_CellColonies", "12   -   Seeds   -   Remove Noise", nullptr));
        comboBox_ProcView_Step->setItemText(13, QCoreApplication::translate("D_MAKRO_CellColonies", "13   -   Seeds   -   Thresh", nullptr));
        comboBox_ProcView_Step->setItemText(14, QCoreApplication::translate("D_MAKRO_CellColonies", "14   -   Seeds   -   Opening", nullptr));
        comboBox_ProcView_Step->setItemText(15, QCoreApplication::translate("D_MAKRO_CellColonies", "15   -   Seeds   -   Inverted Sphericity", nullptr));
        comboBox_ProcView_Step->setItemText(16, QCoreApplication::translate("D_MAKRO_CellColonies", "16   -   Seeds   -   Extract Aspheres", nullptr));
        comboBox_ProcView_Step->setItemText(17, QCoreApplication::translate("D_MAKRO_CellColonies", "17   -   Seeds   -   Distance to Background", nullptr));
        comboBox_ProcView_Step->setItemText(18, QCoreApplication::translate("D_MAKRO_CellColonies", "18   -   Seeds   -   Separate Aspheres", nullptr));
        comboBox_ProcView_Step->setItemText(19, QCoreApplication::translate("D_MAKRO_CellColonies", "19   -   Seeds   -   Extract Spheres", nullptr));
        comboBox_ProcView_Step->setItemText(20, QCoreApplication::translate("D_MAKRO_CellColonies", "20   -   Seeds   -   All Seeds", nullptr));
        comboBox_ProcView_Step->setItemText(21, QCoreApplication::translate("D_MAKRO_CellColonies", "21   -   Segmentation   -   Watershed", nullptr));
        comboBox_ProcView_Step->setItemText(22, QCoreApplication::translate("D_MAKRO_CellColonies", "22   -   Segmentation   -   Binary", nullptr));
        comboBox_ProcView_Step->setItemText(23, QCoreApplication::translate("D_MAKRO_CellColonies", "23   -   Measure   -   Input minus Reference", nullptr));
        comboBox_ProcView_Step->setItemText(24, QCoreApplication::translate("D_MAKRO_CellColonies", "24   -   Measure   -   HSV Transform", nullptr));
        comboBox_ProcView_Step->setItemText(25, QCoreApplication::translate("D_MAKRO_CellColonies", "25   -   Measure   -   Grab Value", nullptr));
        comboBox_ProcView_Step->setItemText(26, QCoreApplication::translate("D_MAKRO_CellColonies", "26   -   Measure   -   Value Masked", nullptr));
        comboBox_ProcView_Step->setItemText(27, QCoreApplication::translate("D_MAKRO_CellColonies", "27   -   Measure   -   Absorption", nullptr));
        comboBox_ProcView_Step->setItemText(28, QCoreApplication::translate("D_MAKRO_CellColonies", "28   -   Measure   -   Transmission", nullptr));
        comboBox_ProcView_Step->setItemText(29, QCoreApplication::translate("D_MAKRO_CellColonies", "29   -   Measure   -   Cell Count", nullptr));

        label_5->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Processing Step", nullptr));
        groupBox_Control->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Control and Results", nullptr));
        groupBox_Results->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Results", nullptr));
        label_33->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Surrival:", nullptr));
        label_34->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Dead:", nullptr));
        label_ResPloSur_prz_dead->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "d%", nullptr));
        label_ResPloSur_prz_surrival->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "s%", nullptr));
        label_24->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Detected Cell-Colonies:", nullptr));
        label_ResPloSur_count_surrival->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "s", nullptr));
        label_ResPloSur_count_dead->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "d", nullptr));
        label_ResPloSur_count_detected->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "n", nullptr));
        groupBox_Seedds->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "10-20   -   Seeds", nullptr));
        label_16->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Size / Sigma", nullptr));
        label_17->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Remove Noise in Seeds (Gauss)", nullptr));
        label_18->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Size / Offset", nullptr));
        label_20->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Binarize Seeds (Loc Adapt Thres)", nullptr));
        label_22->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Size", nullptr));
        label_23->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Remove White Noise (Opening)", nullptr));
        label_37->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Threshold", nullptr));
        label_38->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Threshold", nullptr));
        label_39->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Extract non-spherical (inv) Seeds", nullptr));
        label_40->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Separate non-spherical Seeds", nullptr));
        groupBox_Segmentation->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "21-22   -   Segmentation", nullptr));
        label_25->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Include", nullptr));
        checkBox_ProcCon_Watershed_Border->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Border", nullptr));
        checkBox_ProcCon_Watershed_nSeed->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "nSeed", nullptr));
        label_26->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Options Segemntation", nullptr));
        groupBox_Reference_Input->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "00-05   -   Reference/Input", nullptr));
        label_7->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Min X/Y", nullptr));
        label->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "ROI: Right / Bottom", nullptr));
        label_8->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Max X/Y", nullptr));
        label_2->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "ROI: Left / Top", nullptr));
        label_3->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Remove Noise in Reference", nullptr));
        label_4->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Size / Sigma", nullptr));
        groupBox_Stack->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Image Stack", nullptr));
        groupBox_Foreground->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "06-09   -   Foreground", nullptr));
        label_9->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Min H/S/V", nullptr));
        label_10->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Max H/S/V", nullptr));
        label_13->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Size", nullptr));
        label_14->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Remove Black Noise in Cell-Col.", nullptr));
        label_12->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Grab Cell-Colonies", nullptr));
        label_35->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Size", nullptr));
        label_36->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Remove White Noise in Cell-Col.", nullptr));
        groupBox_Measure->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "23-28   -   Measure", nullptr));
        label_41->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Base", nullptr));
        label_42->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Scale", nullptr));
        label_43->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Transmission: Single cell layer", nullptr));
        label_44->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Cell count: Single cell layer pixel", nullptr));
        tabWidget_Control->setTabText(tabWidget_Control->indexOf(tab_Processing), QCoreApplication::translate("D_MAKRO_CellColonies", "Processing", nullptr));
        groupBox_Output_Img->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Image", nullptr));
        groupBox_Output_Img_Images->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Images", nullptr));
        checkBox_Output_CellCount->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Number of Cells", nullptr));
        checkBox_Output_Labeling->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Labeling", nullptr));
        checkBox_Output_Surrival->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Surrival", nullptr));
        checkBox_Output_Segmentation->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Segmentation", nullptr));
        checkBox_Output_Area->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Area in Pixels", nullptr));
        checkBox_Output_ProcSteps->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Processing Step images", nullptr));
        groupBox_Output_Img_Plots->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Plots", nullptr));
        checkBox_Output_Plot_Img_Hist->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Attribute Histograms", nullptr));
        checkBox_Output_Plot_Img_Surrival->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Colony Surrival", nullptr));
        checkBox_Output_Plot_Img_Scatter->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Attribute Scatter", nullptr));
        groupBox_Output_Img_CSV->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "CSV Tables", nullptr));
        checkBox_Output_CSV_Parameter->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Parameters used", nullptr));
        groupBox_Output_Col->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Colonies and Pixels", nullptr));
        groupBox_Output_Col_Plots->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Plots", nullptr));
        checkBox_Output_Plot_Col_ADM->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Av.  Dev. from Median", nullptr));
        checkBox_Output_Plot_Col_CV->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Coefficient of Variance", nullptr));
        checkBox_Output_Plot_Col_SD->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Standard Deviation", nullptr));
        checkBox_Output_Plot_Col_Mean->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Mean", nullptr));
        checkBox_Output_Plot_Col_Median->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Median", nullptr));
        checkBox_Output_Plot_Col_Hist->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Histogram", nullptr));
        checkBox_Output_Plot_Col_Quantiles->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Quantiles in Val. Range", nullptr));
        checkBox_Output_Plot_Col_Skewness->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Skewness", nullptr));
        checkBox_Output_Plot_Col_Kurtosis->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Kurtosis", nullptr));
        groupBox_Output_Col_CSV->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "CSV Tables", nullptr));
        checkBox_Output_CSV_Results->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Statistics", nullptr));
        checkBox_Output_CSV_RawData->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Raw Data", nullptr));
        groupBox_Output_Col_Types->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Save the following for:", nullptr));
        checkBox_Output_Absorbtion->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Absorption", nullptr));
        checkBox_Output_Transmission->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Transmission", nullptr));
        checkBox_Output_TransmissionRadial->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Transmission Radial", nullptr));
        checkBox_Output_CellDensity->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Approx Cell Density per Px", nullptr));
        groupBox->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Plots (special)", nullptr));
        checkBox_Output_TransRad->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Transmission Radial", nullptr));
        tabWidget_Control->setTabText(tabWidget_Control->indexOf(tab_Output), QCoreApplication::translate("D_MAKRO_CellColonies", "Output", nullptr));
        groupBox_Surrival->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Survival", nullptr));
        label_11->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Minimum", nullptr));
        label_19->setText(QCoreApplication::translate("D_MAKRO_CellColonies", "Number of Cells for Survival", nullptr));
        menuData->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Data", nullptr));
        menuLayout->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Layout", nullptr));
        menuViewer->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Viewer", nullptr));
        menuUpdate->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Update", nullptr));
        menuWindow->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Window", nullptr));
        menuStack->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Stack", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("D_MAKRO_CellColonies", "Parameters", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_CellColonies: public Ui_D_MAKRO_CellColonies {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_CELLCOLONIES_H
