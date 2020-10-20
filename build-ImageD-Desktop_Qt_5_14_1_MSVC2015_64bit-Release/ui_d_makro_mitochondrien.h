/********************************************************************************
** Form generated from reading UI file 'd_makro_mitochondrien.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_MITOCHONDRIEN_H
#define UI_D_MAKRO_MITOCHONDRIEN_H

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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_Mitochondrien
{
public:
    QAction *action_Load;
    QAction *action_Show_Photons;
    QAction *action_Show_Parameters;
    QAction *action_Show_Results;
    QAction *action_Show_Normal;
    QAction *action_Show_Maximum;
    QAction *action_Show_Fullscreen;
    QAction *action_Show_Minimum;
    QAction *action_Smooth_Transformation;
    QAction *action_Keep_Aspect_Ratio;
    QAction *action_Update_View;
    QAction *action_Update_Image_Processing;
    QAction *action_Update_Plot;
    QAction *action_Clear_Queue;
    QAction *action_Next_Image;
    QAction *action_Autoupdate_Plot_on_ImgProc;
    QAction *action_Autoupdate_ImgProc_on_Paint;
    QAction *action_Autosave_CellSep_in_Img;
    QAction *action_Update_Calculation;
    QAction *action_Autoupdate_Calc_on_ImgProc;
    QAction *action_Stream_Open;
    QAction *action_Stream_Current;
    QAction *action_Stream_Close;
    QAction *action_Save_Photons;
    QAction *action_Save_Parameters;
    QAction *action_Save_Results;
    QAction *action_Save_Plot;
    QAction *action_Autoselect_Save_Filename;
    QAction *actionSave_Cytoplasma;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_Photons_View;
    QGridLayout *gridLayout_4;
    QGraphicsView *graphicsView_Photons;
    QComboBox *comboBox_PhoVie_Step;
    QLabel *label_PhoVie_Format_MA;
    QLabel *label_PhoVie_Format_QI;
    QGroupBox *groupBox_Parameters_View;
    QGridLayout *gridLayout_5;
    QGraphicsView *graphicsView_Parameter;
    QLabel *label_ParVie_Format_MA;
    QLabel *label_ParVie_Format_QI;
    QComboBox *comboBox_ParVie_Parameter;
    QGroupBox *groupBox_Results_View;
    QGridLayout *gridLayout_6;
    QTabWidget *tabWidget_Results;
    QWidget *tab_Image;
    QGridLayout *gridLayout_16;
    QStackedWidget *stackedWidget_ResImg_Type;
    QWidget *page_ResImg_Color;
    QGridLayout *gridLayout_17;
    QLabel *label_Gra_B;
    QLabel *label_Gra_R;
    QComboBox *comboBox_Gra_R;
    QComboBox *comboBox_Gra_G;
    QLabel *label_Gra_G;
    QComboBox *comboBox_Gra_B;
    QWidget *page_ResImg_Math;
    QGridLayout *gridLayout_18;
    QLabel *label_Math_Par_1;
    QLabel *label_Math_Par_2;
    QComboBox *comboBox_Math_Operator;
    QComboBox *comboBox_Math_Par_1;
    QLabel *label_Math_Operator;
    QComboBox *comboBox_Math_Par_2;
    QComboBox *comboBox_ResImg_Type;
    QGraphicsView *graphicsView_Results;
    QWidget *tab_Plot;
    QGridLayout *gridLayout_19;
    QGridLayout *gridLayout_Plot;
    QLabel *label_SpacerForPlot;
    QLabel *label_ResPlo_Information;
    QComboBox *comboBox_ResPlo_Type;
    QStackedWidget *stackedWidget_ResPlo_Type;
    QWidget *page_His_Img;
    QGridLayout *gridLayout_11;
    QComboBox *comboBox_His_Image;
    QFrame *line_His_2;
    QFrame *line_His_1;
    QCheckBox *checkBox_His_Uniform;
    QSpinBox *spinBox_His_ClassCount;
    QCheckBox *checkBox_His_Accumulate;
    QWidget *page_His_Cell;
    QGridLayout *gridLayout_2;
    QSpinBox *spinBox_ParAll_ClassCount;
    QFrame *line_ParAll_2;
    QFrame *line_ParAll_1;
    QCheckBox *checkBox_ParAll_Accumulate;
    QComboBox *comboBox_ParAll_Parameter;
    QCheckBox *checkBox_ParAll_Uniform;
    QWidget *page_Par_Pixel;
    QGridLayout *gridLayout_13;
    QComboBox *comboBox_Par_Nucleus;
    QLabel *label_Par_Nucleus;
    QLabel *label_Par_X_Parameter;
    QComboBox *comboBox_Par_X_Parameter;
    QLabel *label_Par_Y_Parameter;
    QComboBox *comboBox_Par_Y_Parameter;
    QWidget *page_Par_Cell;
    QGridLayout *gridLayout_20;
    QLabel *label_ParCell_X;
    QComboBox *comboBox_ParCell_X_Parameter;
    QComboBox *comboBox_ParCell_Y_Parameter;
    QComboBox *comboBox_ParCell_X_Stat;
    QComboBox *comboBox_ParCell_Y_Stat;
    QLabel *label_parCell_Y;
    QWidget *page_Stat_MM;
    QGridLayout *gridLayout_15;
    QFrame *line_Stat_MM_1;
    QComboBox *comboBox_Stat_MM_Parameter;
    QCheckBox *checkBox_Stat_MM_ADM;
    QCheckBox *checkBox_Stat_MM_Median;
    QCheckBox *checkBox_Stat_MM_SD;
    QCheckBox *checkBox_Stat_MM_Mean;
    QFrame *line_Stat_MM_2;
    QWidget *page_Stat_CSK;
    QGridLayout *gridLayout_12;
    QComboBox *comboBox_Stat_CSK_Parameter;
    QFrame *line_Stat_CSK;
    QCheckBox *checkBox_Stat_CSK_CV;
    QCheckBox *checkBox_Stat_CSK_Kurtosis;
    QCheckBox *checkBox_Stat_CSK_Skewness;
    QWidget *page_Stat_Quantiles;
    QGridLayout *gridLayout_14;
    QComboBox *comboBox_Stat_Quantiles_Parameter;
    QFrame *line_Stat_Quantiles;
    QComboBox *comboBox_Stat_Quantiles_Step;
    QGroupBox *groupBox_Photons_Controls;
    QGridLayout *gridLayout_3;
    QSpinBox *spinBox_PhoCon_EdgCon_Size;
    QLabel *label_PhoCon_Blur_Description;
    QFrame *line_PhoCon_1;
    QFrame *line_PhoCon_2;
    QLabel *label_PhoCon_EdgCon_Desciption;
    QLabel *label_PhoCon_Paint_Title;
    QLabel *label_PhoCon_Paint_Pos;
    QPushButton *pushButton_PhoCon_Paint_Load;
    QPushButton *pushButton_PhoCon_Paint_Save;
    QPushButton *pushButton_PhoCon_Paint_Undo;
    QPushButton *pushButton_PhoCon_Paint_Reset;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_PhoCon_Preset;
    QSpacerItem *verticalSpacer_PhoCon;
    QDoubleSpinBox *doubleSpinBox_PhoCon_Thres_Offset;
    QSpinBox *spinBox_PhoCon_Thres_Size;
    QLabel *label_PhoCon_Thres_Pos;
    QLabel *label_PhoCon_Blur_Pos;
    QLabel *label_PhoCon_Thres_Title;
    QDoubleSpinBox *doubleSpinBox_PhoCon_Blur_Sigma;
    QLabel *label_PhoCon_Blur_Title;
    QRadioButton *radioButton_PhoCon_Paint_Line;
    QLabel *label_PhoCon_EdgCon_Pos;
    QLabel *label_PhoCon_EdgCon_Title;
    QSpinBox *spinBox_PhoCon_Blur_Size;
    QRadioButton *radioButton_PhoCon_Paint_Fill;
    QComboBox *comboBox_PhoCon_Paint_Color;
    QComboBox *comboBox_PhoCon_Paint_FillStep;
    QHBoxLayout *horizontalLayout_PhoCon_Paint_Thick;
    QLabel *label_PhoCon_Paint_Thick;
    QSpinBox *spinBox_PhoCon_Paint_Thick;
    QLabel *label_PhoCon_Thres_Description;
    QGroupBox *groupBox_Parameters_Controls;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_ParCon_View;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout_ParCon_View;
    QCheckBox *checkBox_ParVie_RoI_Only;
    QCheckBox *checkBox_ParVie_Contrast;
    QSpacerItem *horizontalSpacer_ParCon_View;
    QHBoxLayout *horizontalLayout_ParCon_0_Handling;
    QLabel *label_ParVie_0;
    QRadioButton *radioButton_ParVie_0_as_0;
    QRadioButton *radioButton_ParVie_0_as_Min;
    QRadioButton *radioButton_ParVie_0_as_Max;
    QSpacerItem *horizontalSpacer_Par_Con_0;
    QGroupBox *groupBox_ParCon_T2;
    QGridLayout *gridLayout_21;
    QLabel *ParCon_T2_Const;
    QLabel *ParCon_T2_Thres;
    QLabel *label_ParCon_T2_NADH_NADPH;
    QLabel *label_ParCon_T2_Min;
    QDoubleSpinBox *doubleSpinBox_ParCon_T2_Min_Const;
    QDoubleSpinBox *doubleSpinBox_ParCon_T2_Min_Thres;
    QLabel *label_ParCon_T2_NADH_NADPH_ValLow;
    QSpacerItem *horizontalSpacer_ParCon;
    QLabel *label_ParCon_T2_Max;
    QDoubleSpinBox *doubleSpinBox_ParCon_T2_Max_Const;
    QDoubleSpinBox *doubleSpinBox_ParCon_T2_Max_Thres;
    QLabel *label_ParCon_T2_NADH_NADPH_ValHigh;
    QGroupBox *groupBox_ParCon_Suffix;
    QGridLayout *gridLayout_9;
    QPlainTextEdit *plainTextEdit_ParCon_Suffixes;
    QGroupBox *groupBox_Results_Controls;
    QGridLayout *gridLayout_8;
    QComboBox *comboBox_ResCon_Theme;
    QComboBox *comboBox_ResCon_Rubberband;
    QSpacerItem *verticalSpacer_ResCon;
    QFrame *line_ResCon_1;
    QFrame *line;
    QCheckBox *checkBox_ResCon_Ignore_Zero;
    QCheckBox *checkBox_ResCon_RoI_Only;
    QGridLayout *gridLayout_ResCon;
    QPushButton *pushButton_RessCon_Zoom_In;
    QPushButton *pushButton_ResCon_Zoom_Out;
    QPushButton *pushButton_ResCon_Zoom_Reset;
    QLabel *label_ResCon_Zoom;
    QComboBox *comboBox_ResCon_Legend;
    QCheckBox *checkBox_ResCon_AA;
    QSpacerItem *horizontalSpacer_ResCon;
    QComboBox *comboBox_AnalysedImage;
    QMenuBar *menubar;
    QMenu *menuData;
    QMenu *menuLayout;
    QMenu *menuWindow;
    QMenu *menuViewer;
    QMenu *menuUpdate;
    QMenu *menuSave;
    QMenu *menuStream;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_Mitochondrien)
    {
        if (D_MAKRO_Mitochondrien->objectName().isEmpty())
            D_MAKRO_Mitochondrien->setObjectName(QString::fromUtf8("D_MAKRO_Mitochondrien"));
        D_MAKRO_Mitochondrien->setEnabled(true);
        D_MAKRO_Mitochondrien->resize(1412, 779);
        action_Load = new QAction(D_MAKRO_Mitochondrien);
        action_Load->setObjectName(QString::fromUtf8("action_Load"));
        action_Show_Photons = new QAction(D_MAKRO_Mitochondrien);
        action_Show_Photons->setObjectName(QString::fromUtf8("action_Show_Photons"));
        action_Show_Photons->setCheckable(true);
        action_Show_Photons->setChecked(true);
        action_Show_Parameters = new QAction(D_MAKRO_Mitochondrien);
        action_Show_Parameters->setObjectName(QString::fromUtf8("action_Show_Parameters"));
        action_Show_Parameters->setCheckable(true);
        action_Show_Parameters->setChecked(true);
        action_Show_Results = new QAction(D_MAKRO_Mitochondrien);
        action_Show_Results->setObjectName(QString::fromUtf8("action_Show_Results"));
        action_Show_Results->setCheckable(true);
        action_Show_Results->setChecked(true);
        action_Show_Normal = new QAction(D_MAKRO_Mitochondrien);
        action_Show_Normal->setObjectName(QString::fromUtf8("action_Show_Normal"));
        action_Show_Maximum = new QAction(D_MAKRO_Mitochondrien);
        action_Show_Maximum->setObjectName(QString::fromUtf8("action_Show_Maximum"));
        action_Show_Fullscreen = new QAction(D_MAKRO_Mitochondrien);
        action_Show_Fullscreen->setObjectName(QString::fromUtf8("action_Show_Fullscreen"));
        action_Show_Minimum = new QAction(D_MAKRO_Mitochondrien);
        action_Show_Minimum->setObjectName(QString::fromUtf8("action_Show_Minimum"));
        action_Smooth_Transformation = new QAction(D_MAKRO_Mitochondrien);
        action_Smooth_Transformation->setObjectName(QString::fromUtf8("action_Smooth_Transformation"));
        action_Smooth_Transformation->setCheckable(true);
        action_Smooth_Transformation->setChecked(true);
        action_Keep_Aspect_Ratio = new QAction(D_MAKRO_Mitochondrien);
        action_Keep_Aspect_Ratio->setObjectName(QString::fromUtf8("action_Keep_Aspect_Ratio"));
        action_Keep_Aspect_Ratio->setCheckable(true);
        action_Keep_Aspect_Ratio->setChecked(true);
        action_Update_View = new QAction(D_MAKRO_Mitochondrien);
        action_Update_View->setObjectName(QString::fromUtf8("action_Update_View"));
        action_Update_Image_Processing = new QAction(D_MAKRO_Mitochondrien);
        action_Update_Image_Processing->setObjectName(QString::fromUtf8("action_Update_Image_Processing"));
        action_Update_Plot = new QAction(D_MAKRO_Mitochondrien);
        action_Update_Plot->setObjectName(QString::fromUtf8("action_Update_Plot"));
        action_Clear_Queue = new QAction(D_MAKRO_Mitochondrien);
        action_Clear_Queue->setObjectName(QString::fromUtf8("action_Clear_Queue"));
        action_Next_Image = new QAction(D_MAKRO_Mitochondrien);
        action_Next_Image->setObjectName(QString::fromUtf8("action_Next_Image"));
        action_Autoupdate_Plot_on_ImgProc = new QAction(D_MAKRO_Mitochondrien);
        action_Autoupdate_Plot_on_ImgProc->setObjectName(QString::fromUtf8("action_Autoupdate_Plot_on_ImgProc"));
        action_Autoupdate_Plot_on_ImgProc->setCheckable(true);
        action_Autoupdate_Plot_on_ImgProc->setChecked(true);
        action_Autoupdate_ImgProc_on_Paint = new QAction(D_MAKRO_Mitochondrien);
        action_Autoupdate_ImgProc_on_Paint->setObjectName(QString::fromUtf8("action_Autoupdate_ImgProc_on_Paint"));
        action_Autoupdate_ImgProc_on_Paint->setCheckable(true);
        action_Autoupdate_ImgProc_on_Paint->setChecked(true);
        action_Autosave_CellSep_in_Img = new QAction(D_MAKRO_Mitochondrien);
        action_Autosave_CellSep_in_Img->setObjectName(QString::fromUtf8("action_Autosave_CellSep_in_Img"));
        action_Autosave_CellSep_in_Img->setCheckable(true);
        action_Autosave_CellSep_in_Img->setChecked(true);
        action_Update_Calculation = new QAction(D_MAKRO_Mitochondrien);
        action_Update_Calculation->setObjectName(QString::fromUtf8("action_Update_Calculation"));
        action_Autoupdate_Calc_on_ImgProc = new QAction(D_MAKRO_Mitochondrien);
        action_Autoupdate_Calc_on_ImgProc->setObjectName(QString::fromUtf8("action_Autoupdate_Calc_on_ImgProc"));
        action_Autoupdate_Calc_on_ImgProc->setCheckable(true);
        action_Autoupdate_Calc_on_ImgProc->setChecked(true);
        action_Stream_Open = new QAction(D_MAKRO_Mitochondrien);
        action_Stream_Open->setObjectName(QString::fromUtf8("action_Stream_Open"));
        action_Stream_Current = new QAction(D_MAKRO_Mitochondrien);
        action_Stream_Current->setObjectName(QString::fromUtf8("action_Stream_Current"));
        action_Stream_Close = new QAction(D_MAKRO_Mitochondrien);
        action_Stream_Close->setObjectName(QString::fromUtf8("action_Stream_Close"));
        action_Save_Photons = new QAction(D_MAKRO_Mitochondrien);
        action_Save_Photons->setObjectName(QString::fromUtf8("action_Save_Photons"));
        action_Save_Parameters = new QAction(D_MAKRO_Mitochondrien);
        action_Save_Parameters->setObjectName(QString::fromUtf8("action_Save_Parameters"));
        action_Save_Results = new QAction(D_MAKRO_Mitochondrien);
        action_Save_Results->setObjectName(QString::fromUtf8("action_Save_Results"));
        action_Save_Plot = new QAction(D_MAKRO_Mitochondrien);
        action_Save_Plot->setObjectName(QString::fromUtf8("action_Save_Plot"));
        action_Autoselect_Save_Filename = new QAction(D_MAKRO_Mitochondrien);
        action_Autoselect_Save_Filename->setObjectName(QString::fromUtf8("action_Autoselect_Save_Filename"));
        action_Autoselect_Save_Filename->setCheckable(true);
        actionSave_Cytoplasma = new QAction(D_MAKRO_Mitochondrien);
        actionSave_Cytoplasma->setObjectName(QString::fromUtf8("actionSave_Cytoplasma"));
        centralwidget = new QWidget(D_MAKRO_Mitochondrien);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_Photons_View = new QGroupBox(centralwidget);
        groupBox_Photons_View->setObjectName(QString::fromUtf8("groupBox_Photons_View"));
        groupBox_Photons_View->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(groupBox_Photons_View->sizePolicy().hasHeightForWidth());
        groupBox_Photons_View->setSizePolicy(sizePolicy);
        groupBox_Photons_View->setMinimumSize(QSize(400, 0));
        gridLayout_4 = new QGridLayout(groupBox_Photons_View);
        gridLayout_4->setSpacing(3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(6, 6, 6, 6);
        graphicsView_Photons = new QGraphicsView(groupBox_Photons_View);
        graphicsView_Photons->setObjectName(QString::fromUtf8("graphicsView_Photons"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView_Photons->sizePolicy().hasHeightForWidth());
        graphicsView_Photons->setSizePolicy(sizePolicy1);
        graphicsView_Photons->setMouseTracking(true);

        gridLayout_4->addWidget(graphicsView_Photons, 1, 0, 1, 3);

        comboBox_PhoVie_Step = new QComboBox(groupBox_Photons_View);
        comboBox_PhoVie_Step->addItem(QString());
        comboBox_PhoVie_Step->addItem(QString());
        comboBox_PhoVie_Step->addItem(QString());
        comboBox_PhoVie_Step->addItem(QString());
        comboBox_PhoVie_Step->addItem(QString());
        comboBox_PhoVie_Step->addItem(QString());
        comboBox_PhoVie_Step->addItem(QString());
        comboBox_PhoVie_Step->addItem(QString());
        comboBox_PhoVie_Step->addItem(QString());
        comboBox_PhoVie_Step->addItem(QString());
        comboBox_PhoVie_Step->addItem(QString());
        comboBox_PhoVie_Step->setObjectName(QString::fromUtf8("comboBox_PhoVie_Step"));

        gridLayout_4->addWidget(comboBox_PhoVie_Step, 0, 0, 1, 1);

        label_PhoVie_Format_MA = new QLabel(groupBox_Photons_View);
        label_PhoVie_Format_MA->setObjectName(QString::fromUtf8("label_PhoVie_Format_MA"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_PhoVie_Format_MA->sizePolicy().hasHeightForWidth());
        label_PhoVie_Format_MA->setSizePolicy(sizePolicy2);
        label_PhoVie_Format_MA->setMaximumSize(QSize(65, 16777215));

        gridLayout_4->addWidget(label_PhoVie_Format_MA, 0, 2, 1, 1);

        label_PhoVie_Format_QI = new QLabel(groupBox_Photons_View);
        label_PhoVie_Format_QI->setObjectName(QString::fromUtf8("label_PhoVie_Format_QI"));
        sizePolicy2.setHeightForWidth(label_PhoVie_Format_QI->sizePolicy().hasHeightForWidth());
        label_PhoVie_Format_QI->setSizePolicy(sizePolicy2);
        label_PhoVie_Format_QI->setMaximumSize(QSize(65, 16777215));

        gridLayout_4->addWidget(label_PhoVie_Format_QI, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox_Photons_View, 0, 0, 1, 1);

        groupBox_Parameters_View = new QGroupBox(centralwidget);
        groupBox_Parameters_View->setObjectName(QString::fromUtf8("groupBox_Parameters_View"));
        groupBox_Parameters_View->setEnabled(false);
        sizePolicy.setHeightForWidth(groupBox_Parameters_View->sizePolicy().hasHeightForWidth());
        groupBox_Parameters_View->setSizePolicy(sizePolicy);
        groupBox_Parameters_View->setMinimumSize(QSize(400, 0));
        gridLayout_5 = new QGridLayout(groupBox_Parameters_View);
        gridLayout_5->setSpacing(3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(6, 6, 6, 6);
        graphicsView_Parameter = new QGraphicsView(groupBox_Parameters_View);
        graphicsView_Parameter->setObjectName(QString::fromUtf8("graphicsView_Parameter"));
        sizePolicy1.setHeightForWidth(graphicsView_Parameter->sizePolicy().hasHeightForWidth());
        graphicsView_Parameter->setSizePolicy(sizePolicy1);
        graphicsView_Parameter->setMouseTracking(true);

        gridLayout_5->addWidget(graphicsView_Parameter, 1, 0, 1, 4);

        label_ParVie_Format_MA = new QLabel(groupBox_Parameters_View);
        label_ParVie_Format_MA->setObjectName(QString::fromUtf8("label_ParVie_Format_MA"));
        sizePolicy2.setHeightForWidth(label_ParVie_Format_MA->sizePolicy().hasHeightForWidth());
        label_ParVie_Format_MA->setSizePolicy(sizePolicy2);
        label_ParVie_Format_MA->setMaximumSize(QSize(65, 16777215));

        gridLayout_5->addWidget(label_ParVie_Format_MA, 0, 3, 1, 1);

        label_ParVie_Format_QI = new QLabel(groupBox_Parameters_View);
        label_ParVie_Format_QI->setObjectName(QString::fromUtf8("label_ParVie_Format_QI"));
        sizePolicy2.setHeightForWidth(label_ParVie_Format_QI->sizePolicy().hasHeightForWidth());
        label_ParVie_Format_QI->setSizePolicy(sizePolicy2);
        label_ParVie_Format_QI->setMaximumSize(QSize(65, 16777215));

        gridLayout_5->addWidget(label_ParVie_Format_QI, 0, 2, 1, 1);

        comboBox_ParVie_Parameter = new QComboBox(groupBox_Parameters_View);
        comboBox_ParVie_Parameter->setObjectName(QString::fromUtf8("comboBox_ParVie_Parameter"));

        gridLayout_5->addWidget(comboBox_ParVie_Parameter, 0, 0, 1, 2);


        gridLayout->addWidget(groupBox_Parameters_View, 0, 1, 1, 1);

        groupBox_Results_View = new QGroupBox(centralwidget);
        groupBox_Results_View->setObjectName(QString::fromUtf8("groupBox_Results_View"));
        groupBox_Results_View->setEnabled(false);
        sizePolicy.setHeightForWidth(groupBox_Results_View->sizePolicy().hasHeightForWidth());
        groupBox_Results_View->setSizePolicy(sizePolicy);
        groupBox_Results_View->setMinimumSize(QSize(400, 0));
        gridLayout_6 = new QGridLayout(groupBox_Results_View);
        gridLayout_6->setSpacing(3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(6, 6, 6, 6);
        tabWidget_Results = new QTabWidget(groupBox_Results_View);
        tabWidget_Results->setObjectName(QString::fromUtf8("tabWidget_Results"));
        sizePolicy1.setHeightForWidth(tabWidget_Results->sizePolicy().hasHeightForWidth());
        tabWidget_Results->setSizePolicy(sizePolicy1);
        tab_Image = new QWidget();
        tab_Image->setObjectName(QString::fromUtf8("tab_Image"));
        gridLayout_16 = new QGridLayout(tab_Image);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        stackedWidget_ResImg_Type = new QStackedWidget(tab_Image);
        stackedWidget_ResImg_Type->setObjectName(QString::fromUtf8("stackedWidget_ResImg_Type"));
        stackedWidget_ResImg_Type->setEnabled(false);
        stackedWidget_ResImg_Type->setMaximumSize(QSize(16777215, 40));
        page_ResImg_Color = new QWidget();
        page_ResImg_Color->setObjectName(QString::fromUtf8("page_ResImg_Color"));
        gridLayout_17 = new QGridLayout(page_ResImg_Color);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        label_Gra_B = new QLabel(page_ResImg_Color);
        label_Gra_B->setObjectName(QString::fromUtf8("label_Gra_B"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_Gra_B->sizePolicy().hasHeightForWidth());
        label_Gra_B->setSizePolicy(sizePolicy3);
        label_Gra_B->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_17->addWidget(label_Gra_B, 0, 4, 1, 1);

        label_Gra_R = new QLabel(page_ResImg_Color);
        label_Gra_R->setObjectName(QString::fromUtf8("label_Gra_R"));
        sizePolicy3.setHeightForWidth(label_Gra_R->sizePolicy().hasHeightForWidth());
        label_Gra_R->setSizePolicy(sizePolicy3);
        label_Gra_R->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_17->addWidget(label_Gra_R, 0, 0, 1, 1);

        comboBox_Gra_R = new QComboBox(page_ResImg_Color);
        comboBox_Gra_R->setObjectName(QString::fromUtf8("comboBox_Gra_R"));

        gridLayout_17->addWidget(comboBox_Gra_R, 0, 1, 1, 1);

        comboBox_Gra_G = new QComboBox(page_ResImg_Color);
        comboBox_Gra_G->setObjectName(QString::fromUtf8("comboBox_Gra_G"));

        gridLayout_17->addWidget(comboBox_Gra_G, 0, 3, 1, 1);

        label_Gra_G = new QLabel(page_ResImg_Color);
        label_Gra_G->setObjectName(QString::fromUtf8("label_Gra_G"));
        sizePolicy3.setHeightForWidth(label_Gra_G->sizePolicy().hasHeightForWidth());
        label_Gra_G->setSizePolicy(sizePolicy3);
        label_Gra_G->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_17->addWidget(label_Gra_G, 0, 2, 1, 1);

        comboBox_Gra_B = new QComboBox(page_ResImg_Color);
        comboBox_Gra_B->setObjectName(QString::fromUtf8("comboBox_Gra_B"));

        gridLayout_17->addWidget(comboBox_Gra_B, 0, 5, 1, 1);

        stackedWidget_ResImg_Type->addWidget(page_ResImg_Color);
        page_ResImg_Math = new QWidget();
        page_ResImg_Math->setObjectName(QString::fromUtf8("page_ResImg_Math"));
        gridLayout_18 = new QGridLayout(page_ResImg_Math);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        label_Math_Par_1 = new QLabel(page_ResImg_Math);
        label_Math_Par_1->setObjectName(QString::fromUtf8("label_Math_Par_1"));
        label_Math_Par_1->setMaximumSize(QSize(30, 16777215));

        gridLayout_18->addWidget(label_Math_Par_1, 0, 0, 1, 1);

        label_Math_Par_2 = new QLabel(page_ResImg_Math);
        label_Math_Par_2->setObjectName(QString::fromUtf8("label_Math_Par_2"));
        label_Math_Par_2->setMaximumSize(QSize(30, 16777215));

        gridLayout_18->addWidget(label_Math_Par_2, 0, 4, 1, 1);

        comboBox_Math_Operator = new QComboBox(page_ResImg_Math);
        comboBox_Math_Operator->addItem(QString());
        comboBox_Math_Operator->addItem(QString());
        comboBox_Math_Operator->addItem(QString());
        comboBox_Math_Operator->addItem(QString());
        comboBox_Math_Operator->addItem(QString());
        comboBox_Math_Operator->addItem(QString());
        comboBox_Math_Operator->addItem(QString());
        comboBox_Math_Operator->addItem(QString());
        comboBox_Math_Operator->addItem(QString());
        comboBox_Math_Operator->addItem(QString());
        comboBox_Math_Operator->addItem(QString());
        comboBox_Math_Operator->addItem(QString());
        comboBox_Math_Operator->addItem(QString());
        comboBox_Math_Operator->setObjectName(QString::fromUtf8("comboBox_Math_Operator"));

        gridLayout_18->addWidget(comboBox_Math_Operator, 0, 3, 1, 1);

        comboBox_Math_Par_1 = new QComboBox(page_ResImg_Math);
        comboBox_Math_Par_1->setObjectName(QString::fromUtf8("comboBox_Math_Par_1"));

        gridLayout_18->addWidget(comboBox_Math_Par_1, 0, 1, 1, 1);

        label_Math_Operator = new QLabel(page_ResImg_Math);
        label_Math_Operator->setObjectName(QString::fromUtf8("label_Math_Operator"));
        label_Math_Operator->setMaximumSize(QSize(30, 16777215));

        gridLayout_18->addWidget(label_Math_Operator, 0, 2, 1, 1);

        comboBox_Math_Par_2 = new QComboBox(page_ResImg_Math);
        comboBox_Math_Par_2->setObjectName(QString::fromUtf8("comboBox_Math_Par_2"));

        gridLayout_18->addWidget(comboBox_Math_Par_2, 0, 5, 1, 1);

        stackedWidget_ResImg_Type->addWidget(page_ResImg_Math);

        gridLayout_16->addWidget(stackedWidget_ResImg_Type, 1, 0, 1, 1);

        comboBox_ResImg_Type = new QComboBox(tab_Image);
        comboBox_ResImg_Type->addItem(QString());
        comboBox_ResImg_Type->addItem(QString());
        comboBox_ResImg_Type->setObjectName(QString::fromUtf8("comboBox_ResImg_Type"));

        gridLayout_16->addWidget(comboBox_ResImg_Type, 0, 0, 1, 1);

        graphicsView_Results = new QGraphicsView(tab_Image);
        graphicsView_Results->setObjectName(QString::fromUtf8("graphicsView_Results"));
        sizePolicy1.setHeightForWidth(graphicsView_Results->sizePolicy().hasHeightForWidth());
        graphicsView_Results->setSizePolicy(sizePolicy1);
        graphicsView_Results->setMouseTracking(true);

        gridLayout_16->addWidget(graphicsView_Results, 2, 0, 1, 1);

        tabWidget_Results->addTab(tab_Image, QString());
        tab_Plot = new QWidget();
        tab_Plot->setObjectName(QString::fromUtf8("tab_Plot"));
        gridLayout_19 = new QGridLayout(tab_Plot);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_Plot = new QGridLayout();
        gridLayout_Plot->setObjectName(QString::fromUtf8("gridLayout_Plot"));
        label_SpacerForPlot = new QLabel(tab_Plot);
        label_SpacerForPlot->setObjectName(QString::fromUtf8("label_SpacerForPlot"));

        gridLayout_Plot->addWidget(label_SpacerForPlot, 0, 0, 1, 1);


        gridLayout_19->addLayout(gridLayout_Plot, 2, 0, 1, 3);

        label_ResPlo_Information = new QLabel(tab_Plot);
        label_ResPlo_Information->setObjectName(QString::fromUtf8("label_ResPlo_Information"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_ResPlo_Information->sizePolicy().hasHeightForWidth());
        label_ResPlo_Information->setSizePolicy(sizePolicy4);

        gridLayout_19->addWidget(label_ResPlo_Information, 3, 0, 1, 3);

        comboBox_ResPlo_Type = new QComboBox(tab_Plot);
        comboBox_ResPlo_Type->addItem(QString());
        comboBox_ResPlo_Type->addItem(QString());
        comboBox_ResPlo_Type->addItem(QString());
        comboBox_ResPlo_Type->addItem(QString());
        comboBox_ResPlo_Type->addItem(QString());
        comboBox_ResPlo_Type->addItem(QString());
        comboBox_ResPlo_Type->addItem(QString());
        comboBox_ResPlo_Type->setObjectName(QString::fromUtf8("comboBox_ResPlo_Type"));

        gridLayout_19->addWidget(comboBox_ResPlo_Type, 0, 0, 1, 3);

        stackedWidget_ResPlo_Type = new QStackedWidget(tab_Plot);
        stackedWidget_ResPlo_Type->setObjectName(QString::fromUtf8("stackedWidget_ResPlo_Type"));
        stackedWidget_ResPlo_Type->setEnabled(false);
        stackedWidget_ResPlo_Type->setMinimumSize(QSize(0, 0));
        stackedWidget_ResPlo_Type->setMaximumSize(QSize(16777215, 40));
        page_His_Img = new QWidget();
        page_His_Img->setObjectName(QString::fromUtf8("page_His_Img"));
        gridLayout_11 = new QGridLayout(page_His_Img);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        comboBox_His_Image = new QComboBox(page_His_Img);
        comboBox_His_Image->setObjectName(QString::fromUtf8("comboBox_His_Image"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(comboBox_His_Image->sizePolicy().hasHeightForWidth());
        comboBox_His_Image->setSizePolicy(sizePolicy5);

        gridLayout_11->addWidget(comboBox_His_Image, 0, 0, 1, 1);

        line_His_2 = new QFrame(page_His_Img);
        line_His_2->setObjectName(QString::fromUtf8("line_His_2"));
        line_His_2->setFrameShape(QFrame::VLine);
        line_His_2->setFrameShadow(QFrame::Sunken);

        gridLayout_11->addWidget(line_His_2, 0, 3, 1, 1);

        line_His_1 = new QFrame(page_His_Img);
        line_His_1->setObjectName(QString::fromUtf8("line_His_1"));
        line_His_1->setFrameShape(QFrame::VLine);
        line_His_1->setFrameShadow(QFrame::Sunken);

        gridLayout_11->addWidget(line_His_1, 0, 1, 1, 1);

        checkBox_His_Uniform = new QCheckBox(page_His_Img);
        checkBox_His_Uniform->setObjectName(QString::fromUtf8("checkBox_His_Uniform"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(checkBox_His_Uniform->sizePolicy().hasHeightForWidth());
        checkBox_His_Uniform->setSizePolicy(sizePolicy6);
        checkBox_His_Uniform->setChecked(true);

        gridLayout_11->addWidget(checkBox_His_Uniform, 0, 4, 1, 1);

        spinBox_His_ClassCount = new QSpinBox(page_His_Img);
        spinBox_His_ClassCount->setObjectName(QString::fromUtf8("spinBox_His_ClassCount"));
        spinBox_His_ClassCount->setMaximumSize(QSize(55, 16777215));
        spinBox_His_ClassCount->setMinimum(1);
        spinBox_His_ClassCount->setMaximum(10000);
        spinBox_His_ClassCount->setSingleStep(100);
        spinBox_His_ClassCount->setValue(1000);

        gridLayout_11->addWidget(spinBox_His_ClassCount, 0, 2, 1, 1);

        checkBox_His_Accumulate = new QCheckBox(page_His_Img);
        checkBox_His_Accumulate->setObjectName(QString::fromUtf8("checkBox_His_Accumulate"));
        sizePolicy6.setHeightForWidth(checkBox_His_Accumulate->sizePolicy().hasHeightForWidth());
        checkBox_His_Accumulate->setSizePolicy(sizePolicy6);
        checkBox_His_Accumulate->setChecked(true);

        gridLayout_11->addWidget(checkBox_His_Accumulate, 0, 5, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_His_Img);
        page_His_Cell = new QWidget();
        page_His_Cell->setObjectName(QString::fromUtf8("page_His_Cell"));
        gridLayout_2 = new QGridLayout(page_His_Cell);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        spinBox_ParAll_ClassCount = new QSpinBox(page_His_Cell);
        spinBox_ParAll_ClassCount->setObjectName(QString::fromUtf8("spinBox_ParAll_ClassCount"));
        sizePolicy6.setHeightForWidth(spinBox_ParAll_ClassCount->sizePolicy().hasHeightForWidth());
        spinBox_ParAll_ClassCount->setSizePolicy(sizePolicy6);
        spinBox_ParAll_ClassCount->setMaximumSize(QSize(55, 16777215));
        spinBox_ParAll_ClassCount->setMinimum(1);
        spinBox_ParAll_ClassCount->setMaximum(10000);
        spinBox_ParAll_ClassCount->setSingleStep(100);
        spinBox_ParAll_ClassCount->setValue(1000);

        gridLayout_2->addWidget(spinBox_ParAll_ClassCount, 0, 2, 1, 1);

        line_ParAll_2 = new QFrame(page_His_Cell);
        line_ParAll_2->setObjectName(QString::fromUtf8("line_ParAll_2"));
        line_ParAll_2->setFrameShape(QFrame::VLine);
        line_ParAll_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_ParAll_2, 0, 3, 1, 1);

        line_ParAll_1 = new QFrame(page_His_Cell);
        line_ParAll_1->setObjectName(QString::fromUtf8("line_ParAll_1"));
        line_ParAll_1->setFrameShape(QFrame::VLine);
        line_ParAll_1->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_ParAll_1, 0, 1, 1, 1);

        checkBox_ParAll_Accumulate = new QCheckBox(page_His_Cell);
        checkBox_ParAll_Accumulate->setObjectName(QString::fromUtf8("checkBox_ParAll_Accumulate"));
        sizePolicy6.setHeightForWidth(checkBox_ParAll_Accumulate->sizePolicy().hasHeightForWidth());
        checkBox_ParAll_Accumulate->setSizePolicy(sizePolicy6);
        checkBox_ParAll_Accumulate->setChecked(true);

        gridLayout_2->addWidget(checkBox_ParAll_Accumulate, 0, 5, 1, 1);

        comboBox_ParAll_Parameter = new QComboBox(page_His_Cell);
        comboBox_ParAll_Parameter->setObjectName(QString::fromUtf8("comboBox_ParAll_Parameter"));

        gridLayout_2->addWidget(comboBox_ParAll_Parameter, 0, 0, 1, 1);

        checkBox_ParAll_Uniform = new QCheckBox(page_His_Cell);
        checkBox_ParAll_Uniform->setObjectName(QString::fromUtf8("checkBox_ParAll_Uniform"));
        sizePolicy6.setHeightForWidth(checkBox_ParAll_Uniform->sizePolicy().hasHeightForWidth());
        checkBox_ParAll_Uniform->setSizePolicy(sizePolicy6);
        checkBox_ParAll_Uniform->setChecked(true);

        gridLayout_2->addWidget(checkBox_ParAll_Uniform, 0, 4, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_His_Cell);
        page_Par_Pixel = new QWidget();
        page_Par_Pixel->setObjectName(QString::fromUtf8("page_Par_Pixel"));
        gridLayout_13 = new QGridLayout(page_Par_Pixel);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        comboBox_Par_Nucleus = new QComboBox(page_Par_Pixel);
        comboBox_Par_Nucleus->setObjectName(QString::fromUtf8("comboBox_Par_Nucleus"));

        gridLayout_13->addWidget(comboBox_Par_Nucleus, 0, 1, 1, 1);

        label_Par_Nucleus = new QLabel(page_Par_Pixel);
        label_Par_Nucleus->setObjectName(QString::fromUtf8("label_Par_Nucleus"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_Par_Nucleus->sizePolicy().hasHeightForWidth());
        label_Par_Nucleus->setSizePolicy(sizePolicy7);
        label_Par_Nucleus->setMinimumSize(QSize(30, 0));
        label_Par_Nucleus->setMaximumSize(QSize(30, 16777215));

        gridLayout_13->addWidget(label_Par_Nucleus, 0, 0, 1, 1);

        label_Par_X_Parameter = new QLabel(page_Par_Pixel);
        label_Par_X_Parameter->setObjectName(QString::fromUtf8("label_Par_X_Parameter"));
        sizePolicy7.setHeightForWidth(label_Par_X_Parameter->sizePolicy().hasHeightForWidth());
        label_Par_X_Parameter->setSizePolicy(sizePolicy7);
        label_Par_X_Parameter->setMinimumSize(QSize(30, 0));
        label_Par_X_Parameter->setMaximumSize(QSize(30, 16777215));

        gridLayout_13->addWidget(label_Par_X_Parameter, 0, 2, 1, 1);

        comboBox_Par_X_Parameter = new QComboBox(page_Par_Pixel);
        comboBox_Par_X_Parameter->setObjectName(QString::fromUtf8("comboBox_Par_X_Parameter"));

        gridLayout_13->addWidget(comboBox_Par_X_Parameter, 0, 3, 1, 1);

        label_Par_Y_Parameter = new QLabel(page_Par_Pixel);
        label_Par_Y_Parameter->setObjectName(QString::fromUtf8("label_Par_Y_Parameter"));
        sizePolicy7.setHeightForWidth(label_Par_Y_Parameter->sizePolicy().hasHeightForWidth());
        label_Par_Y_Parameter->setSizePolicy(sizePolicy7);
        label_Par_Y_Parameter->setMinimumSize(QSize(30, 0));
        label_Par_Y_Parameter->setMaximumSize(QSize(30, 16777215));

        gridLayout_13->addWidget(label_Par_Y_Parameter, 0, 4, 1, 1);

        comboBox_Par_Y_Parameter = new QComboBox(page_Par_Pixel);
        comboBox_Par_Y_Parameter->setObjectName(QString::fromUtf8("comboBox_Par_Y_Parameter"));

        gridLayout_13->addWidget(comboBox_Par_Y_Parameter, 0, 5, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_Par_Pixel);
        page_Par_Cell = new QWidget();
        page_Par_Cell->setObjectName(QString::fromUtf8("page_Par_Cell"));
        gridLayout_20 = new QGridLayout(page_Par_Cell);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        label_ParCell_X = new QLabel(page_Par_Cell);
        label_ParCell_X->setObjectName(QString::fromUtf8("label_ParCell_X"));
        sizePolicy3.setHeightForWidth(label_ParCell_X->sizePolicy().hasHeightForWidth());
        label_ParCell_X->setSizePolicy(sizePolicy3);

        gridLayout_20->addWidget(label_ParCell_X, 0, 0, 1, 1);

        comboBox_ParCell_X_Parameter = new QComboBox(page_Par_Cell);
        comboBox_ParCell_X_Parameter->setObjectName(QString::fromUtf8("comboBox_ParCell_X_Parameter"));

        gridLayout_20->addWidget(comboBox_ParCell_X_Parameter, 0, 1, 1, 1);

        comboBox_ParCell_Y_Parameter = new QComboBox(page_Par_Cell);
        comboBox_ParCell_Y_Parameter->setObjectName(QString::fromUtf8("comboBox_ParCell_Y_Parameter"));

        gridLayout_20->addWidget(comboBox_ParCell_Y_Parameter, 0, 4, 1, 1);

        comboBox_ParCell_X_Stat = new QComboBox(page_Par_Cell);
        comboBox_ParCell_X_Stat->setObjectName(QString::fromUtf8("comboBox_ParCell_X_Stat"));

        gridLayout_20->addWidget(comboBox_ParCell_X_Stat, 0, 2, 1, 1);

        comboBox_ParCell_Y_Stat = new QComboBox(page_Par_Cell);
        comboBox_ParCell_Y_Stat->setObjectName(QString::fromUtf8("comboBox_ParCell_Y_Stat"));

        gridLayout_20->addWidget(comboBox_ParCell_Y_Stat, 0, 5, 1, 1);

        label_parCell_Y = new QLabel(page_Par_Cell);
        label_parCell_Y->setObjectName(QString::fromUtf8("label_parCell_Y"));
        sizePolicy3.setHeightForWidth(label_parCell_Y->sizePolicy().hasHeightForWidth());
        label_parCell_Y->setSizePolicy(sizePolicy3);

        gridLayout_20->addWidget(label_parCell_Y, 0, 3, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_Par_Cell);
        page_Stat_MM = new QWidget();
        page_Stat_MM->setObjectName(QString::fromUtf8("page_Stat_MM"));
        gridLayout_15 = new QGridLayout(page_Stat_MM);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        line_Stat_MM_1 = new QFrame(page_Stat_MM);
        line_Stat_MM_1->setObjectName(QString::fromUtf8("line_Stat_MM_1"));
        line_Stat_MM_1->setFrameShape(QFrame::VLine);
        line_Stat_MM_1->setFrameShadow(QFrame::Sunken);

        gridLayout_15->addWidget(line_Stat_MM_1, 0, 1, 1, 1);

        comboBox_Stat_MM_Parameter = new QComboBox(page_Stat_MM);
        comboBox_Stat_MM_Parameter->setObjectName(QString::fromUtf8("comboBox_Stat_MM_Parameter"));

        gridLayout_15->addWidget(comboBox_Stat_MM_Parameter, 0, 0, 1, 1);

        checkBox_Stat_MM_ADM = new QCheckBox(page_Stat_MM);
        checkBox_Stat_MM_ADM->setObjectName(QString::fromUtf8("checkBox_Stat_MM_ADM"));
        sizePolicy6.setHeightForWidth(checkBox_Stat_MM_ADM->sizePolicy().hasHeightForWidth());
        checkBox_Stat_MM_ADM->setSizePolicy(sizePolicy6);
        checkBox_Stat_MM_ADM->setChecked(false);

        gridLayout_15->addWidget(checkBox_Stat_MM_ADM, 0, 6, 1, 1);

        checkBox_Stat_MM_Median = new QCheckBox(page_Stat_MM);
        checkBox_Stat_MM_Median->setObjectName(QString::fromUtf8("checkBox_Stat_MM_Median"));
        sizePolicy6.setHeightForWidth(checkBox_Stat_MM_Median->sizePolicy().hasHeightForWidth());
        checkBox_Stat_MM_Median->setSizePolicy(sizePolicy6);
        checkBox_Stat_MM_Median->setChecked(false);

        gridLayout_15->addWidget(checkBox_Stat_MM_Median, 0, 5, 1, 1);

        checkBox_Stat_MM_SD = new QCheckBox(page_Stat_MM);
        checkBox_Stat_MM_SD->setObjectName(QString::fromUtf8("checkBox_Stat_MM_SD"));
        sizePolicy6.setHeightForWidth(checkBox_Stat_MM_SD->sizePolicy().hasHeightForWidth());
        checkBox_Stat_MM_SD->setSizePolicy(sizePolicy6);
        checkBox_Stat_MM_SD->setChecked(false);

        gridLayout_15->addWidget(checkBox_Stat_MM_SD, 0, 3, 1, 1);

        checkBox_Stat_MM_Mean = new QCheckBox(page_Stat_MM);
        checkBox_Stat_MM_Mean->setObjectName(QString::fromUtf8("checkBox_Stat_MM_Mean"));
        sizePolicy6.setHeightForWidth(checkBox_Stat_MM_Mean->sizePolicy().hasHeightForWidth());
        checkBox_Stat_MM_Mean->setSizePolicy(sizePolicy6);
        checkBox_Stat_MM_Mean->setChecked(true);

        gridLayout_15->addWidget(checkBox_Stat_MM_Mean, 0, 2, 1, 1);

        line_Stat_MM_2 = new QFrame(page_Stat_MM);
        line_Stat_MM_2->setObjectName(QString::fromUtf8("line_Stat_MM_2"));
        line_Stat_MM_2->setFrameShape(QFrame::VLine);
        line_Stat_MM_2->setFrameShadow(QFrame::Sunken);

        gridLayout_15->addWidget(line_Stat_MM_2, 0, 4, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_Stat_MM);
        page_Stat_CSK = new QWidget();
        page_Stat_CSK->setObjectName(QString::fromUtf8("page_Stat_CSK"));
        gridLayout_12 = new QGridLayout(page_Stat_CSK);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        comboBox_Stat_CSK_Parameter = new QComboBox(page_Stat_CSK);
        comboBox_Stat_CSK_Parameter->setObjectName(QString::fromUtf8("comboBox_Stat_CSK_Parameter"));

        gridLayout_12->addWidget(comboBox_Stat_CSK_Parameter, 0, 0, 1, 1);

        line_Stat_CSK = new QFrame(page_Stat_CSK);
        line_Stat_CSK->setObjectName(QString::fromUtf8("line_Stat_CSK"));
        line_Stat_CSK->setFrameShape(QFrame::VLine);
        line_Stat_CSK->setFrameShadow(QFrame::Sunken);

        gridLayout_12->addWidget(line_Stat_CSK, 0, 1, 1, 1);

        checkBox_Stat_CSK_CV = new QCheckBox(page_Stat_CSK);
        checkBox_Stat_CSK_CV->setObjectName(QString::fromUtf8("checkBox_Stat_CSK_CV"));
        sizePolicy6.setHeightForWidth(checkBox_Stat_CSK_CV->sizePolicy().hasHeightForWidth());
        checkBox_Stat_CSK_CV->setSizePolicy(sizePolicy6);
        checkBox_Stat_CSK_CV->setChecked(true);

        gridLayout_12->addWidget(checkBox_Stat_CSK_CV, 0, 2, 1, 1);

        checkBox_Stat_CSK_Kurtosis = new QCheckBox(page_Stat_CSK);
        checkBox_Stat_CSK_Kurtosis->setObjectName(QString::fromUtf8("checkBox_Stat_CSK_Kurtosis"));
        sizePolicy6.setHeightForWidth(checkBox_Stat_CSK_Kurtosis->sizePolicy().hasHeightForWidth());
        checkBox_Stat_CSK_Kurtosis->setSizePolicy(sizePolicy6);
        checkBox_Stat_CSK_Kurtosis->setChecked(true);

        gridLayout_12->addWidget(checkBox_Stat_CSK_Kurtosis, 0, 4, 1, 1);

        checkBox_Stat_CSK_Skewness = new QCheckBox(page_Stat_CSK);
        checkBox_Stat_CSK_Skewness->setObjectName(QString::fromUtf8("checkBox_Stat_CSK_Skewness"));
        sizePolicy6.setHeightForWidth(checkBox_Stat_CSK_Skewness->sizePolicy().hasHeightForWidth());
        checkBox_Stat_CSK_Skewness->setSizePolicy(sizePolicy6);
        checkBox_Stat_CSK_Skewness->setChecked(true);

        gridLayout_12->addWidget(checkBox_Stat_CSK_Skewness, 0, 3, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_Stat_CSK);
        page_Stat_Quantiles = new QWidget();
        page_Stat_Quantiles->setObjectName(QString::fromUtf8("page_Stat_Quantiles"));
        gridLayout_14 = new QGridLayout(page_Stat_Quantiles);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        comboBox_Stat_Quantiles_Parameter = new QComboBox(page_Stat_Quantiles);
        comboBox_Stat_Quantiles_Parameter->setObjectName(QString::fromUtf8("comboBox_Stat_Quantiles_Parameter"));

        gridLayout_14->addWidget(comboBox_Stat_Quantiles_Parameter, 0, 0, 1, 1);

        line_Stat_Quantiles = new QFrame(page_Stat_Quantiles);
        line_Stat_Quantiles->setObjectName(QString::fromUtf8("line_Stat_Quantiles"));
        line_Stat_Quantiles->setFrameShape(QFrame::VLine);
        line_Stat_Quantiles->setFrameShadow(QFrame::Sunken);

        gridLayout_14->addWidget(line_Stat_Quantiles, 0, 1, 1, 1);

        comboBox_Stat_Quantiles_Step = new QComboBox(page_Stat_Quantiles);
        comboBox_Stat_Quantiles_Step->addItem(QString());
        comboBox_Stat_Quantiles_Step->addItem(QString());
        comboBox_Stat_Quantiles_Step->addItem(QString());
        comboBox_Stat_Quantiles_Step->addItem(QString());
        comboBox_Stat_Quantiles_Step->addItem(QString());
        comboBox_Stat_Quantiles_Step->setObjectName(QString::fromUtf8("comboBox_Stat_Quantiles_Step"));
        comboBox_Stat_Quantiles_Step->setMaximumSize(QSize(80, 16777215));

        gridLayout_14->addWidget(comboBox_Stat_Quantiles_Step, 0, 2, 1, 1);

        stackedWidget_ResPlo_Type->addWidget(page_Stat_Quantiles);

        gridLayout_19->addWidget(stackedWidget_ResPlo_Type, 1, 0, 1, 3);

        tabWidget_Results->addTab(tab_Plot, QString());

        gridLayout_6->addWidget(tabWidget_Results, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_Results_View, 0, 2, 1, 1);

        groupBox_Photons_Controls = new QGroupBox(centralwidget);
        groupBox_Photons_Controls->setObjectName(QString::fromUtf8("groupBox_Photons_Controls"));
        groupBox_Photons_Controls->setEnabled(false);
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(1);
        sizePolicy8.setVerticalStretch(1);
        sizePolicy8.setHeightForWidth(groupBox_Photons_Controls->sizePolicy().hasHeightForWidth());
        groupBox_Photons_Controls->setSizePolicy(sizePolicy8);
        groupBox_Photons_Controls->setMinimumSize(QSize(400, 190));
        groupBox_Photons_Controls->setMaximumSize(QSize(16777215, 190));
        gridLayout_3 = new QGridLayout(groupBox_Photons_Controls);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(6, 6, 6, 6);
        spinBox_PhoCon_EdgCon_Size = new QSpinBox(groupBox_Photons_Controls);
        spinBox_PhoCon_EdgCon_Size->setObjectName(QString::fromUtf8("spinBox_PhoCon_EdgCon_Size"));
        spinBox_PhoCon_EdgCon_Size->setEnabled(false);
        spinBox_PhoCon_EdgCon_Size->setMinimum(1);
        spinBox_PhoCon_EdgCon_Size->setMaximum(1000000);
        spinBox_PhoCon_EdgCon_Size->setSingleStep(2);
        spinBox_PhoCon_EdgCon_Size->setValue(7);

        gridLayout_3->addWidget(spinBox_PhoCon_EdgCon_Size, 8, 3, 1, 2);

        label_PhoCon_Blur_Description = new QLabel(groupBox_Photons_Controls);
        label_PhoCon_Blur_Description->setObjectName(QString::fromUtf8("label_PhoCon_Blur_Description"));
        label_PhoCon_Blur_Description->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(label_PhoCon_Blur_Description, 0, 5, 1, 2);

        line_PhoCon_1 = new QFrame(groupBox_Photons_Controls);
        line_PhoCon_1->setObjectName(QString::fromUtf8("line_PhoCon_1"));
        line_PhoCon_1->setFrameShape(QFrame::HLine);
        line_PhoCon_1->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_PhoCon_1, 2, 0, 1, 7);

        line_PhoCon_2 = new QFrame(groupBox_Photons_Controls);
        line_PhoCon_2->setObjectName(QString::fromUtf8("line_PhoCon_2"));
        line_PhoCon_2->setFrameShape(QFrame::HLine);
        line_PhoCon_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_PhoCon_2, 7, 0, 1, 7);

        label_PhoCon_EdgCon_Desciption = new QLabel(groupBox_Photons_Controls);
        label_PhoCon_EdgCon_Desciption->setObjectName(QString::fromUtf8("label_PhoCon_EdgCon_Desciption"));
        label_PhoCon_EdgCon_Desciption->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(label_PhoCon_EdgCon_Desciption, 8, 5, 1, 2);

        label_PhoCon_Paint_Title = new QLabel(groupBox_Photons_Controls);
        label_PhoCon_Paint_Title->setObjectName(QString::fromUtf8("label_PhoCon_Paint_Title"));
        sizePolicy2.setHeightForWidth(label_PhoCon_Paint_Title->sizePolicy().hasHeightForWidth());
        label_PhoCon_Paint_Title->setSizePolicy(sizePolicy2);
        label_PhoCon_Paint_Title->setMinimumSize(QSize(75, 20));
        label_PhoCon_Paint_Title->setMaximumSize(QSize(75, 20));

        gridLayout_3->addWidget(label_PhoCon_Paint_Title, 3, 1, 4, 1);

        label_PhoCon_Paint_Pos = new QLabel(groupBox_Photons_Controls);
        label_PhoCon_Paint_Pos->setObjectName(QString::fromUtf8("label_PhoCon_Paint_Pos"));
        sizePolicy2.setHeightForWidth(label_PhoCon_Paint_Pos->sizePolicy().hasHeightForWidth());
        label_PhoCon_Paint_Pos->setSizePolicy(sizePolicy2);
        label_PhoCon_Paint_Pos->setMinimumSize(QSize(20, 20));
        label_PhoCon_Paint_Pos->setMaximumSize(QSize(20, 20));

        gridLayout_3->addWidget(label_PhoCon_Paint_Pos, 3, 0, 4, 1);

        pushButton_PhoCon_Paint_Load = new QPushButton(groupBox_Photons_Controls);
        pushButton_PhoCon_Paint_Load->setObjectName(QString::fromUtf8("pushButton_PhoCon_Paint_Load"));
        sizePolicy2.setHeightForWidth(pushButton_PhoCon_Paint_Load->sizePolicy().hasHeightForWidth());
        pushButton_PhoCon_Paint_Load->setSizePolicy(sizePolicy2);
        pushButton_PhoCon_Paint_Load->setMinimumSize(QSize(75, 20));
        pushButton_PhoCon_Paint_Load->setMaximumSize(QSize(75, 20));

        gridLayout_3->addWidget(pushButton_PhoCon_Paint_Load, 6, 4, 1, 1);

        pushButton_PhoCon_Paint_Save = new QPushButton(groupBox_Photons_Controls);
        pushButton_PhoCon_Paint_Save->setObjectName(QString::fromUtf8("pushButton_PhoCon_Paint_Save"));
        sizePolicy2.setHeightForWidth(pushButton_PhoCon_Paint_Save->sizePolicy().hasHeightForWidth());
        pushButton_PhoCon_Paint_Save->setSizePolicy(sizePolicy2);
        pushButton_PhoCon_Paint_Save->setMinimumSize(QSize(75, 20));
        pushButton_PhoCon_Paint_Save->setMaximumSize(QSize(75, 20));

        gridLayout_3->addWidget(pushButton_PhoCon_Paint_Save, 6, 3, 1, 1);

        pushButton_PhoCon_Paint_Undo = new QPushButton(groupBox_Photons_Controls);
        pushButton_PhoCon_Paint_Undo->setObjectName(QString::fromUtf8("pushButton_PhoCon_Paint_Undo"));
        sizePolicy2.setHeightForWidth(pushButton_PhoCon_Paint_Undo->sizePolicy().hasHeightForWidth());
        pushButton_PhoCon_Paint_Undo->setSizePolicy(sizePolicy2);
        pushButton_PhoCon_Paint_Undo->setMinimumSize(QSize(75, 20));
        pushButton_PhoCon_Paint_Undo->setMaximumSize(QSize(75, 20));

        gridLayout_3->addWidget(pushButton_PhoCon_Paint_Undo, 5, 3, 1, 1);

        pushButton_PhoCon_Paint_Reset = new QPushButton(groupBox_Photons_Controls);
        pushButton_PhoCon_Paint_Reset->setObjectName(QString::fromUtf8("pushButton_PhoCon_Paint_Reset"));
        sizePolicy2.setHeightForWidth(pushButton_PhoCon_Paint_Reset->sizePolicy().hasHeightForWidth());
        pushButton_PhoCon_Paint_Reset->setSizePolicy(sizePolicy2);
        pushButton_PhoCon_Paint_Reset->setMinimumSize(QSize(75, 20));
        pushButton_PhoCon_Paint_Reset->setMaximumSize(QSize(75, 20));

        gridLayout_3->addWidget(pushButton_PhoCon_Paint_Reset, 5, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 3, 6, 3, 1);

        lineEdit_PhoCon_Preset = new QLineEdit(groupBox_Photons_Controls);
        lineEdit_PhoCon_Preset->setObjectName(QString::fromUtf8("lineEdit_PhoCon_Preset"));
        sizePolicy6.setHeightForWidth(lineEdit_PhoCon_Preset->sizePolicy().hasHeightForWidth());
        lineEdit_PhoCon_Preset->setSizePolicy(sizePolicy6);
        lineEdit_PhoCon_Preset->setMinimumSize(QSize(100, 20));
        lineEdit_PhoCon_Preset->setMaximumSize(QSize(100, 20));
        lineEdit_PhoCon_Preset->setDragEnabled(false);
        lineEdit_PhoCon_Preset->setReadOnly(false);
        lineEdit_PhoCon_Preset->setClearButtonEnabled(false);

        gridLayout_3->addWidget(lineEdit_PhoCon_Preset, 6, 5, 1, 1);

        verticalSpacer_PhoCon = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_PhoCon, 9, 0, 1, 7);

        doubleSpinBox_PhoCon_Thres_Offset = new QDoubleSpinBox(groupBox_Photons_Controls);
        doubleSpinBox_PhoCon_Thres_Offset->setObjectName(QString::fromUtf8("doubleSpinBox_PhoCon_Thres_Offset"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_PhoCon_Thres_Offset->sizePolicy().hasHeightForWidth());
        doubleSpinBox_PhoCon_Thres_Offset->setSizePolicy(sizePolicy2);
        doubleSpinBox_PhoCon_Thres_Offset->setMinimumSize(QSize(75, 20));
        doubleSpinBox_PhoCon_Thres_Offset->setMaximumSize(QSize(75, 20));
        doubleSpinBox_PhoCon_Thres_Offset->setMinimum(-256.000000000000000);
        doubleSpinBox_PhoCon_Thres_Offset->setMaximum(255.000000000000000);
        doubleSpinBox_PhoCon_Thres_Offset->setValue(-8.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_PhoCon_Thres_Offset, 1, 4, 1, 1);

        spinBox_PhoCon_Thres_Size = new QSpinBox(groupBox_Photons_Controls);
        spinBox_PhoCon_Thres_Size->setObjectName(QString::fromUtf8("spinBox_PhoCon_Thres_Size"));
        sizePolicy2.setHeightForWidth(spinBox_PhoCon_Thres_Size->sizePolicy().hasHeightForWidth());
        spinBox_PhoCon_Thres_Size->setSizePolicy(sizePolicy2);
        spinBox_PhoCon_Thres_Size->setMinimumSize(QSize(75, 20));
        spinBox_PhoCon_Thres_Size->setMaximumSize(QSize(75, 20));
        spinBox_PhoCon_Thres_Size->setMinimum(3);
        spinBox_PhoCon_Thres_Size->setMaximum(100003);
        spinBox_PhoCon_Thres_Size->setSingleStep(2);
        spinBox_PhoCon_Thres_Size->setValue(45);

        gridLayout_3->addWidget(spinBox_PhoCon_Thres_Size, 1, 3, 1, 1);

        label_PhoCon_Thres_Pos = new QLabel(groupBox_Photons_Controls);
        label_PhoCon_Thres_Pos->setObjectName(QString::fromUtf8("label_PhoCon_Thres_Pos"));
        sizePolicy2.setHeightForWidth(label_PhoCon_Thres_Pos->sizePolicy().hasHeightForWidth());
        label_PhoCon_Thres_Pos->setSizePolicy(sizePolicy2);
        label_PhoCon_Thres_Pos->setMinimumSize(QSize(20, 20));
        label_PhoCon_Thres_Pos->setMaximumSize(QSize(20, 20));

        gridLayout_3->addWidget(label_PhoCon_Thres_Pos, 1, 0, 1, 1);

        label_PhoCon_Blur_Pos = new QLabel(groupBox_Photons_Controls);
        label_PhoCon_Blur_Pos->setObjectName(QString::fromUtf8("label_PhoCon_Blur_Pos"));
        sizePolicy2.setHeightForWidth(label_PhoCon_Blur_Pos->sizePolicy().hasHeightForWidth());
        label_PhoCon_Blur_Pos->setSizePolicy(sizePolicy2);
        label_PhoCon_Blur_Pos->setMinimumSize(QSize(20, 20));
        label_PhoCon_Blur_Pos->setMaximumSize(QSize(20, 20));

        gridLayout_3->addWidget(label_PhoCon_Blur_Pos, 0, 0, 1, 1);

        label_PhoCon_Thres_Title = new QLabel(groupBox_Photons_Controls);
        label_PhoCon_Thres_Title->setObjectName(QString::fromUtf8("label_PhoCon_Thres_Title"));
        sizePolicy2.setHeightForWidth(label_PhoCon_Thres_Title->sizePolicy().hasHeightForWidth());
        label_PhoCon_Thres_Title->setSizePolicy(sizePolicy2);
        label_PhoCon_Thres_Title->setMinimumSize(QSize(75, 20));
        label_PhoCon_Thres_Title->setMaximumSize(QSize(75, 20));

        gridLayout_3->addWidget(label_PhoCon_Thres_Title, 1, 1, 1, 2);

        doubleSpinBox_PhoCon_Blur_Sigma = new QDoubleSpinBox(groupBox_Photons_Controls);
        doubleSpinBox_PhoCon_Blur_Sigma->setObjectName(QString::fromUtf8("doubleSpinBox_PhoCon_Blur_Sigma"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_PhoCon_Blur_Sigma->sizePolicy().hasHeightForWidth());
        doubleSpinBox_PhoCon_Blur_Sigma->setSizePolicy(sizePolicy2);
        doubleSpinBox_PhoCon_Blur_Sigma->setMinimumSize(QSize(75, 20));
        doubleSpinBox_PhoCon_Blur_Sigma->setMaximumSize(QSize(75, 20));
        doubleSpinBox_PhoCon_Blur_Sigma->setDecimals(2);
        doubleSpinBox_PhoCon_Blur_Sigma->setMaximum(1000000.000000000000000);
        doubleSpinBox_PhoCon_Blur_Sigma->setValue(3.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_PhoCon_Blur_Sigma, 0, 4, 1, 1);

        label_PhoCon_Blur_Title = new QLabel(groupBox_Photons_Controls);
        label_PhoCon_Blur_Title->setObjectName(QString::fromUtf8("label_PhoCon_Blur_Title"));
        sizePolicy2.setHeightForWidth(label_PhoCon_Blur_Title->sizePolicy().hasHeightForWidth());
        label_PhoCon_Blur_Title->setSizePolicy(sizePolicy2);
        label_PhoCon_Blur_Title->setMinimumSize(QSize(75, 20));
        label_PhoCon_Blur_Title->setMaximumSize(QSize(75, 20));

        gridLayout_3->addWidget(label_PhoCon_Blur_Title, 0, 1, 1, 2);

        radioButton_PhoCon_Paint_Line = new QRadioButton(groupBox_Photons_Controls);
        radioButton_PhoCon_Paint_Line->setObjectName(QString::fromUtf8("radioButton_PhoCon_Paint_Line"));
        sizePolicy2.setHeightForWidth(radioButton_PhoCon_Paint_Line->sizePolicy().hasHeightForWidth());
        radioButton_PhoCon_Paint_Line->setSizePolicy(sizePolicy2);
        radioButton_PhoCon_Paint_Line->setMinimumSize(QSize(75, 20));
        radioButton_PhoCon_Paint_Line->setMaximumSize(QSize(75, 20));
        radioButton_PhoCon_Paint_Line->setChecked(true);

        gridLayout_3->addWidget(radioButton_PhoCon_Paint_Line, 3, 3, 1, 1);

        label_PhoCon_EdgCon_Pos = new QLabel(groupBox_Photons_Controls);
        label_PhoCon_EdgCon_Pos->setObjectName(QString::fromUtf8("label_PhoCon_EdgCon_Pos"));
        sizePolicy2.setHeightForWidth(label_PhoCon_EdgCon_Pos->sizePolicy().hasHeightForWidth());
        label_PhoCon_EdgCon_Pos->setSizePolicy(sizePolicy2);
        label_PhoCon_EdgCon_Pos->setMinimumSize(QSize(20, 20));
        label_PhoCon_EdgCon_Pos->setMaximumSize(QSize(20, 20));

        gridLayout_3->addWidget(label_PhoCon_EdgCon_Pos, 8, 0, 1, 1);

        label_PhoCon_EdgCon_Title = new QLabel(groupBox_Photons_Controls);
        label_PhoCon_EdgCon_Title->setObjectName(QString::fromUtf8("label_PhoCon_EdgCon_Title"));
        sizePolicy2.setHeightForWidth(label_PhoCon_EdgCon_Title->sizePolicy().hasHeightForWidth());
        label_PhoCon_EdgCon_Title->setSizePolicy(sizePolicy2);
        label_PhoCon_EdgCon_Title->setMinimumSize(QSize(75, 20));
        label_PhoCon_EdgCon_Title->setMaximumSize(QSize(75, 20));

        gridLayout_3->addWidget(label_PhoCon_EdgCon_Title, 8, 1, 1, 2);

        spinBox_PhoCon_Blur_Size = new QSpinBox(groupBox_Photons_Controls);
        spinBox_PhoCon_Blur_Size->setObjectName(QString::fromUtf8("spinBox_PhoCon_Blur_Size"));
        sizePolicy2.setHeightForWidth(spinBox_PhoCon_Blur_Size->sizePolicy().hasHeightForWidth());
        spinBox_PhoCon_Blur_Size->setSizePolicy(sizePolicy2);
        spinBox_PhoCon_Blur_Size->setMinimumSize(QSize(75, 20));
        spinBox_PhoCon_Blur_Size->setMaximumSize(QSize(75, 20));
        spinBox_PhoCon_Blur_Size->setMinimum(1);
        spinBox_PhoCon_Blur_Size->setMaximum(100003);
        spinBox_PhoCon_Blur_Size->setSingleStep(2);
        spinBox_PhoCon_Blur_Size->setValue(3);

        gridLayout_3->addWidget(spinBox_PhoCon_Blur_Size, 0, 3, 1, 1);

        radioButton_PhoCon_Paint_Fill = new QRadioButton(groupBox_Photons_Controls);
        radioButton_PhoCon_Paint_Fill->setObjectName(QString::fromUtf8("radioButton_PhoCon_Paint_Fill"));
        sizePolicy2.setHeightForWidth(radioButton_PhoCon_Paint_Fill->sizePolicy().hasHeightForWidth());
        radioButton_PhoCon_Paint_Fill->setSizePolicy(sizePolicy2);
        radioButton_PhoCon_Paint_Fill->setMinimumSize(QSize(75, 20));
        radioButton_PhoCon_Paint_Fill->setMaximumSize(QSize(75, 20));

        gridLayout_3->addWidget(radioButton_PhoCon_Paint_Fill, 4, 3, 1, 1);

        comboBox_PhoCon_Paint_Color = new QComboBox(groupBox_Photons_Controls);
        comboBox_PhoCon_Paint_Color->addItem(QString());
        comboBox_PhoCon_Paint_Color->addItem(QString());
        comboBox_PhoCon_Paint_Color->setObjectName(QString::fromUtf8("comboBox_PhoCon_Paint_Color"));
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(comboBox_PhoCon_Paint_Color->sizePolicy().hasHeightForWidth());
        comboBox_PhoCon_Paint_Color->setSizePolicy(sizePolicy9);
        comboBox_PhoCon_Paint_Color->setMinimumSize(QSize(100, 0));
        comboBox_PhoCon_Paint_Color->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(comboBox_PhoCon_Paint_Color, 3, 5, 2, 1);

        comboBox_PhoCon_Paint_FillStep = new QComboBox(groupBox_Photons_Controls);
        comboBox_PhoCon_Paint_FillStep->addItem(QString());
        comboBox_PhoCon_Paint_FillStep->addItem(QString());
        comboBox_PhoCon_Paint_FillStep->setObjectName(QString::fromUtf8("comboBox_PhoCon_Paint_FillStep"));
        comboBox_PhoCon_Paint_FillStep->setEnabled(false);
        comboBox_PhoCon_Paint_FillStep->setMinimumSize(QSize(75, 0));
        comboBox_PhoCon_Paint_FillStep->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(comboBox_PhoCon_Paint_FillStep, 4, 4, 1, 1);

        horizontalLayout_PhoCon_Paint_Thick = new QHBoxLayout();
        horizontalLayout_PhoCon_Paint_Thick->setObjectName(QString::fromUtf8("horizontalLayout_PhoCon_Paint_Thick"));
        label_PhoCon_Paint_Thick = new QLabel(groupBox_Photons_Controls);
        label_PhoCon_Paint_Thick->setObjectName(QString::fromUtf8("label_PhoCon_Paint_Thick"));
        sizePolicy3.setHeightForWidth(label_PhoCon_Paint_Thick->sizePolicy().hasHeightForWidth());
        label_PhoCon_Paint_Thick->setSizePolicy(sizePolicy3);
        label_PhoCon_Paint_Thick->setMinimumSize(QSize(0, 20));
        label_PhoCon_Paint_Thick->setMaximumSize(QSize(47, 20));

        horizontalLayout_PhoCon_Paint_Thick->addWidget(label_PhoCon_Paint_Thick);

        spinBox_PhoCon_Paint_Thick = new QSpinBox(groupBox_Photons_Controls);
        spinBox_PhoCon_Paint_Thick->setObjectName(QString::fromUtf8("spinBox_PhoCon_Paint_Thick"));
        sizePolicy6.setHeightForWidth(spinBox_PhoCon_Paint_Thick->sizePolicy().hasHeightForWidth());
        spinBox_PhoCon_Paint_Thick->setSizePolicy(sizePolicy6);
        spinBox_PhoCon_Paint_Thick->setMinimumSize(QSize(0, 20));
        spinBox_PhoCon_Paint_Thick->setMaximumSize(QSize(46, 20));
        spinBox_PhoCon_Paint_Thick->setMinimum(1);
        spinBox_PhoCon_Paint_Thick->setMaximum(99);

        horizontalLayout_PhoCon_Paint_Thick->addWidget(spinBox_PhoCon_Paint_Thick);


        gridLayout_3->addLayout(horizontalLayout_PhoCon_Paint_Thick, 3, 4, 1, 1);

        label_PhoCon_Thres_Description = new QLabel(groupBox_Photons_Controls);
        label_PhoCon_Thres_Description->setObjectName(QString::fromUtf8("label_PhoCon_Thres_Description"));
        label_PhoCon_Thres_Description->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(label_PhoCon_Thres_Description, 1, 5, 1, 2);


        gridLayout->addWidget(groupBox_Photons_Controls, 1, 0, 1, 1);

        groupBox_Parameters_Controls = new QGroupBox(centralwidget);
        groupBox_Parameters_Controls->setObjectName(QString::fromUtf8("groupBox_Parameters_Controls"));
        sizePolicy8.setHeightForWidth(groupBox_Parameters_Controls->sizePolicy().hasHeightForWidth());
        groupBox_Parameters_Controls->setSizePolicy(sizePolicy8);
        groupBox_Parameters_Controls->setMinimumSize(QSize(400, 190));
        groupBox_Parameters_Controls->setMaximumSize(QSize(16777215, 190));
        gridLayout_7 = new QGridLayout(groupBox_Parameters_Controls);
        gridLayout_7->setSpacing(3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(6, 6, 6, 6);
        groupBox_ParCon_View = new QGroupBox(groupBox_Parameters_Controls);
        groupBox_ParCon_View->setObjectName(QString::fromUtf8("groupBox_ParCon_View"));
        groupBox_ParCon_View->setEnabled(false);
        groupBox_ParCon_View->setMinimumSize(QSize(0, 76));
        groupBox_ParCon_View->setMaximumSize(QSize(16777215, 76));
        gridLayout_10 = new QGridLayout(groupBox_ParCon_View);
        gridLayout_10->setSpacing(2);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_ParCon_View = new QHBoxLayout();
        horizontalLayout_ParCon_View->setObjectName(QString::fromUtf8("horizontalLayout_ParCon_View"));
        checkBox_ParVie_RoI_Only = new QCheckBox(groupBox_ParCon_View);
        checkBox_ParVie_RoI_Only->setObjectName(QString::fromUtf8("checkBox_ParVie_RoI_Only"));
        sizePolicy6.setHeightForWidth(checkBox_ParVie_RoI_Only->sizePolicy().hasHeightForWidth());
        checkBox_ParVie_RoI_Only->setSizePolicy(sizePolicy6);
        checkBox_ParVie_RoI_Only->setMinimumSize(QSize(0, 20));
        checkBox_ParVie_RoI_Only->setMaximumSize(QSize(16777215, 20));
        checkBox_ParVie_RoI_Only->setChecked(true);

        horizontalLayout_ParCon_View->addWidget(checkBox_ParVie_RoI_Only);

        checkBox_ParVie_Contrast = new QCheckBox(groupBox_ParCon_View);
        checkBox_ParVie_Contrast->setObjectName(QString::fromUtf8("checkBox_ParVie_Contrast"));
        sizePolicy6.setHeightForWidth(checkBox_ParVie_Contrast->sizePolicy().hasHeightForWidth());
        checkBox_ParVie_Contrast->setSizePolicy(sizePolicy6);
        checkBox_ParVie_Contrast->setMinimumSize(QSize(0, 20));
        checkBox_ParVie_Contrast->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_ParCon_View->addWidget(checkBox_ParVie_Contrast);

        horizontalSpacer_ParCon_View = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_ParCon_View->addItem(horizontalSpacer_ParCon_View);


        gridLayout_10->addLayout(horizontalLayout_ParCon_View, 0, 0, 1, 1);

        horizontalLayout_ParCon_0_Handling = new QHBoxLayout();
        horizontalLayout_ParCon_0_Handling->setObjectName(QString::fromUtf8("horizontalLayout_ParCon_0_Handling"));
        label_ParVie_0 = new QLabel(groupBox_ParCon_View);
        label_ParVie_0->setObjectName(QString::fromUtf8("label_ParVie_0"));
        sizePolicy7.setHeightForWidth(label_ParVie_0->sizePolicy().hasHeightForWidth());
        label_ParVie_0->setSizePolicy(sizePolicy7);
        label_ParVie_0->setMinimumSize(QSize(0, 20));
        label_ParVie_0->setMaximumSize(QSize(125, 20));

        horizontalLayout_ParCon_0_Handling->addWidget(label_ParVie_0);

        radioButton_ParVie_0_as_0 = new QRadioButton(groupBox_ParCon_View);
        radioButton_ParVie_0_as_0->setObjectName(QString::fromUtf8("radioButton_ParVie_0_as_0"));
        sizePolicy6.setHeightForWidth(radioButton_ParVie_0_as_0->sizePolicy().hasHeightForWidth());
        radioButton_ParVie_0_as_0->setSizePolicy(sizePolicy6);
        radioButton_ParVie_0_as_0->setMinimumSize(QSize(0, 20));
        radioButton_ParVie_0_as_0->setMaximumSize(QSize(16777215, 20));
        radioButton_ParVie_0_as_0->setChecked(true);

        horizontalLayout_ParCon_0_Handling->addWidget(radioButton_ParVie_0_as_0);

        radioButton_ParVie_0_as_Min = new QRadioButton(groupBox_ParCon_View);
        radioButton_ParVie_0_as_Min->setObjectName(QString::fromUtf8("radioButton_ParVie_0_as_Min"));
        sizePolicy6.setHeightForWidth(radioButton_ParVie_0_as_Min->sizePolicy().hasHeightForWidth());
        radioButton_ParVie_0_as_Min->setSizePolicy(sizePolicy6);
        radioButton_ParVie_0_as_Min->setMinimumSize(QSize(0, 20));
        radioButton_ParVie_0_as_Min->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_ParCon_0_Handling->addWidget(radioButton_ParVie_0_as_Min);

        radioButton_ParVie_0_as_Max = new QRadioButton(groupBox_ParCon_View);
        radioButton_ParVie_0_as_Max->setObjectName(QString::fromUtf8("radioButton_ParVie_0_as_Max"));
        sizePolicy6.setHeightForWidth(radioButton_ParVie_0_as_Max->sizePolicy().hasHeightForWidth());
        radioButton_ParVie_0_as_Max->setSizePolicy(sizePolicy6);
        radioButton_ParVie_0_as_Max->setMinimumSize(QSize(0, 20));
        radioButton_ParVie_0_as_Max->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_ParCon_0_Handling->addWidget(radioButton_ParVie_0_as_Max);

        horizontalSpacer_Par_Con_0 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_ParCon_0_Handling->addItem(horizontalSpacer_Par_Con_0);


        gridLayout_10->addLayout(horizontalLayout_ParCon_0_Handling, 1, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_ParCon_View, 0, 1, 1, 1);

        groupBox_ParCon_T2 = new QGroupBox(groupBox_Parameters_Controls);
        groupBox_ParCon_T2->setObjectName(QString::fromUtf8("groupBox_ParCon_T2"));
        groupBox_ParCon_T2->setEnabled(false);
        groupBox_ParCon_T2->setMinimumSize(QSize(0, 84));
        groupBox_ParCon_T2->setMaximumSize(QSize(16777215, 84));
        gridLayout_21 = new QGridLayout(groupBox_ParCon_T2);
        gridLayout_21->setSpacing(3);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        gridLayout_21->setContentsMargins(3, 3, 3, 3);
        ParCon_T2_Const = new QLabel(groupBox_ParCon_T2);
        ParCon_T2_Const->setObjectName(QString::fromUtf8("ParCon_T2_Const"));
        sizePolicy3.setHeightForWidth(ParCon_T2_Const->sizePolicy().hasHeightForWidth());
        ParCon_T2_Const->setSizePolicy(sizePolicy3);
        ParCon_T2_Const->setMinimumSize(QSize(90, 20));
        ParCon_T2_Const->setMaximumSize(QSize(90, 20));

        gridLayout_21->addWidget(ParCon_T2_Const, 0, 1, 1, 1);

        ParCon_T2_Thres = new QLabel(groupBox_ParCon_T2);
        ParCon_T2_Thres->setObjectName(QString::fromUtf8("ParCon_T2_Thres"));
        sizePolicy3.setHeightForWidth(ParCon_T2_Thres->sizePolicy().hasHeightForWidth());
        ParCon_T2_Thres->setSizePolicy(sizePolicy3);
        ParCon_T2_Thres->setMinimumSize(QSize(90, 20));
        ParCon_T2_Thres->setMaximumSize(QSize(90, 20));

        gridLayout_21->addWidget(ParCon_T2_Thres, 0, 2, 1, 1);

        label_ParCon_T2_NADH_NADPH = new QLabel(groupBox_ParCon_T2);
        label_ParCon_T2_NADH_NADPH->setObjectName(QString::fromUtf8("label_ParCon_T2_NADH_NADPH"));
        sizePolicy3.setHeightForWidth(label_ParCon_T2_NADH_NADPH->sizePolicy().hasHeightForWidth());
        label_ParCon_T2_NADH_NADPH->setSizePolicy(sizePolicy3);
        label_ParCon_T2_NADH_NADPH->setMinimumSize(QSize(70, 0));
        label_ParCon_T2_NADH_NADPH->setMaximumSize(QSize(70, 16777215));

        gridLayout_21->addWidget(label_ParCon_T2_NADH_NADPH, 0, 3, 1, 1);

        label_ParCon_T2_Min = new QLabel(groupBox_ParCon_T2);
        label_ParCon_T2_Min->setObjectName(QString::fromUtf8("label_ParCon_T2_Min"));
        sizePolicy3.setHeightForWidth(label_ParCon_T2_Min->sizePolicy().hasHeightForWidth());
        label_ParCon_T2_Min->setSizePolicy(sizePolicy3);
        label_ParCon_T2_Min->setMinimumSize(QSize(0, 20));
        label_ParCon_T2_Min->setMaximumSize(QSize(60, 20));

        gridLayout_21->addWidget(label_ParCon_T2_Min, 1, 0, 1, 1);

        doubleSpinBox_ParCon_T2_Min_Const = new QDoubleSpinBox(groupBox_ParCon_T2);
        doubleSpinBox_ParCon_T2_Min_Const->setObjectName(QString::fromUtf8("doubleSpinBox_ParCon_T2_Min_Const"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_ParCon_T2_Min_Const->sizePolicy().hasHeightForWidth());
        doubleSpinBox_ParCon_T2_Min_Const->setSizePolicy(sizePolicy6);
        doubleSpinBox_ParCon_T2_Min_Const->setMinimumSize(QSize(90, 20));
        doubleSpinBox_ParCon_T2_Min_Const->setMaximumSize(QSize(90, 20));
        doubleSpinBox_ParCon_T2_Min_Const->setDecimals(6);
        doubleSpinBox_ParCon_T2_Min_Const->setMaximum(10.000000000000000);
        doubleSpinBox_ParCon_T2_Min_Const->setSingleStep(0.010000000000000);
        doubleSpinBox_ParCon_T2_Min_Const->setValue(1.500000000000000);

        gridLayout_21->addWidget(doubleSpinBox_ParCon_T2_Min_Const, 1, 1, 1, 1);

        doubleSpinBox_ParCon_T2_Min_Thres = new QDoubleSpinBox(groupBox_ParCon_T2);
        doubleSpinBox_ParCon_T2_Min_Thres->setObjectName(QString::fromUtf8("doubleSpinBox_ParCon_T2_Min_Thres"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_ParCon_T2_Min_Thres->sizePolicy().hasHeightForWidth());
        doubleSpinBox_ParCon_T2_Min_Thres->setSizePolicy(sizePolicy6);
        doubleSpinBox_ParCon_T2_Min_Thres->setMinimumSize(QSize(90, 20));
        doubleSpinBox_ParCon_T2_Min_Thres->setMaximumSize(QSize(90, 20));
        doubleSpinBox_ParCon_T2_Min_Thres->setDecimals(6);
        doubleSpinBox_ParCon_T2_Min_Thres->setMaximum(10.000000000000000);
        doubleSpinBox_ParCon_T2_Min_Thres->setSingleStep(0.010000000000000);
        doubleSpinBox_ParCon_T2_Min_Thres->setValue(1.500000000000000);

        gridLayout_21->addWidget(doubleSpinBox_ParCon_T2_Min_Thres, 1, 2, 1, 1);

        label_ParCon_T2_NADH_NADPH_ValLow = new QLabel(groupBox_ParCon_T2);
        label_ParCon_T2_NADH_NADPH_ValLow->setObjectName(QString::fromUtf8("label_ParCon_T2_NADH_NADPH_ValLow"));
        sizePolicy3.setHeightForWidth(label_ParCon_T2_NADH_NADPH_ValLow->sizePolicy().hasHeightForWidth());
        label_ParCon_T2_NADH_NADPH_ValLow->setSizePolicy(sizePolicy3);
        label_ParCon_T2_NADH_NADPH_ValLow->setMinimumSize(QSize(70, 0));
        label_ParCon_T2_NADH_NADPH_ValLow->setMaximumSize(QSize(70, 16777215));

        gridLayout_21->addWidget(label_ParCon_T2_NADH_NADPH_ValLow, 1, 3, 1, 1);

        horizontalSpacer_ParCon = new QSpacerItem(42, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_21->addItem(horizontalSpacer_ParCon, 1, 4, 2, 1);

        label_ParCon_T2_Max = new QLabel(groupBox_ParCon_T2);
        label_ParCon_T2_Max->setObjectName(QString::fromUtf8("label_ParCon_T2_Max"));
        sizePolicy3.setHeightForWidth(label_ParCon_T2_Max->sizePolicy().hasHeightForWidth());
        label_ParCon_T2_Max->setSizePolicy(sizePolicy3);
        label_ParCon_T2_Max->setMinimumSize(QSize(0, 20));
        label_ParCon_T2_Max->setMaximumSize(QSize(60, 20));

        gridLayout_21->addWidget(label_ParCon_T2_Max, 2, 0, 1, 1);

        doubleSpinBox_ParCon_T2_Max_Const = new QDoubleSpinBox(groupBox_ParCon_T2);
        doubleSpinBox_ParCon_T2_Max_Const->setObjectName(QString::fromUtf8("doubleSpinBox_ParCon_T2_Max_Const"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_ParCon_T2_Max_Const->sizePolicy().hasHeightForWidth());
        doubleSpinBox_ParCon_T2_Max_Const->setSizePolicy(sizePolicy6);
        doubleSpinBox_ParCon_T2_Max_Const->setMinimumSize(QSize(90, 20));
        doubleSpinBox_ParCon_T2_Max_Const->setMaximumSize(QSize(90, 20));
        doubleSpinBox_ParCon_T2_Max_Const->setDecimals(6);
        doubleSpinBox_ParCon_T2_Max_Const->setMaximum(10.000000000000000);
        doubleSpinBox_ParCon_T2_Max_Const->setSingleStep(0.010000000000000);
        doubleSpinBox_ParCon_T2_Max_Const->setValue(4.400000000000000);

        gridLayout_21->addWidget(doubleSpinBox_ParCon_T2_Max_Const, 2, 1, 1, 1);

        doubleSpinBox_ParCon_T2_Max_Thres = new QDoubleSpinBox(groupBox_ParCon_T2);
        doubleSpinBox_ParCon_T2_Max_Thres->setObjectName(QString::fromUtf8("doubleSpinBox_ParCon_T2_Max_Thres"));
        sizePolicy6.setHeightForWidth(doubleSpinBox_ParCon_T2_Max_Thres->sizePolicy().hasHeightForWidth());
        doubleSpinBox_ParCon_T2_Max_Thres->setSizePolicy(sizePolicy6);
        doubleSpinBox_ParCon_T2_Max_Thres->setMinimumSize(QSize(90, 20));
        doubleSpinBox_ParCon_T2_Max_Thres->setMaximumSize(QSize(90, 20));
        doubleSpinBox_ParCon_T2_Max_Thres->setDecimals(6);
        doubleSpinBox_ParCon_T2_Max_Thres->setMaximum(10.000000000000000);
        doubleSpinBox_ParCon_T2_Max_Thres->setSingleStep(0.010000000000000);
        doubleSpinBox_ParCon_T2_Max_Thres->setValue(4.350000000000000);

        gridLayout_21->addWidget(doubleSpinBox_ParCon_T2_Max_Thres, 2, 2, 1, 1);

        label_ParCon_T2_NADH_NADPH_ValHigh = new QLabel(groupBox_ParCon_T2);
        label_ParCon_T2_NADH_NADPH_ValHigh->setObjectName(QString::fromUtf8("label_ParCon_T2_NADH_NADPH_ValHigh"));
        sizePolicy3.setHeightForWidth(label_ParCon_T2_NADH_NADPH_ValHigh->sizePolicy().hasHeightForWidth());
        label_ParCon_T2_NADH_NADPH_ValHigh->setSizePolicy(sizePolicy3);
        label_ParCon_T2_NADH_NADPH_ValHigh->setMinimumSize(QSize(70, 0));
        label_ParCon_T2_NADH_NADPH_ValHigh->setMaximumSize(QSize(70, 16777215));

        gridLayout_21->addWidget(label_ParCon_T2_NADH_NADPH_ValHigh, 2, 3, 1, 1);


        gridLayout_7->addWidget(groupBox_ParCon_T2, 1, 1, 1, 1);

        groupBox_ParCon_Suffix = new QGroupBox(groupBox_Parameters_Controls);
        groupBox_ParCon_Suffix->setObjectName(QString::fromUtf8("groupBox_ParCon_Suffix"));
        groupBox_ParCon_Suffix->setMinimumSize(QSize(102, 163));
        groupBox_ParCon_Suffix->setMaximumSize(QSize(163, 16777215));
        gridLayout_9 = new QGridLayout(groupBox_ParCon_Suffix);
        gridLayout_9->setSpacing(2);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(1, 1, 1, 1);
        plainTextEdit_ParCon_Suffixes = new QPlainTextEdit(groupBox_ParCon_Suffix);
        plainTextEdit_ParCon_Suffixes->setObjectName(QString::fromUtf8("plainTextEdit_ParCon_Suffixes"));
        sizePolicy7.setHeightForWidth(plainTextEdit_ParCon_Suffixes->sizePolicy().hasHeightForWidth());
        plainTextEdit_ParCon_Suffixes->setSizePolicy(sizePolicy7);
        plainTextEdit_ParCon_Suffixes->setMinimumSize(QSize(85, 0));
        plainTextEdit_ParCon_Suffixes->setMaximumSize(QSize(85, 16777215));

        gridLayout_9->addWidget(plainTextEdit_ParCon_Suffixes, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_ParCon_Suffix, 0, 0, 2, 1);


        gridLayout->addWidget(groupBox_Parameters_Controls, 1, 1, 1, 1);

        groupBox_Results_Controls = new QGroupBox(centralwidget);
        groupBox_Results_Controls->setObjectName(QString::fromUtf8("groupBox_Results_Controls"));
        groupBox_Results_Controls->setEnabled(true);
        sizePolicy8.setHeightForWidth(groupBox_Results_Controls->sizePolicy().hasHeightForWidth());
        groupBox_Results_Controls->setSizePolicy(sizePolicy8);
        groupBox_Results_Controls->setMinimumSize(QSize(400, 190));
        groupBox_Results_Controls->setMaximumSize(QSize(16777215, 190));
        gridLayout_8 = new QGridLayout(groupBox_Results_Controls);
        gridLayout_8->setSpacing(3);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(6, 6, 6, 6);
        comboBox_ResCon_Theme = new QComboBox(groupBox_Results_Controls);
        comboBox_ResCon_Theme->setObjectName(QString::fromUtf8("comboBox_ResCon_Theme"));
        comboBox_ResCon_Theme->setEnabled(false);
        sizePolicy2.setHeightForWidth(comboBox_ResCon_Theme->sizePolicy().hasHeightForWidth());
        comboBox_ResCon_Theme->setSizePolicy(sizePolicy2);
        comboBox_ResCon_Theme->setMinimumSize(QSize(150, 0));
        comboBox_ResCon_Theme->setMaximumSize(QSize(150, 16777215));

        gridLayout_8->addWidget(comboBox_ResCon_Theme, 2, 3, 1, 1);

        comboBox_ResCon_Rubberband = new QComboBox(groupBox_Results_Controls);
        comboBox_ResCon_Rubberband->addItem(QString());
        comboBox_ResCon_Rubberband->addItem(QString());
        comboBox_ResCon_Rubberband->addItem(QString());
        comboBox_ResCon_Rubberband->addItem(QString());
        comboBox_ResCon_Rubberband->setObjectName(QString::fromUtf8("comboBox_ResCon_Rubberband"));
        comboBox_ResCon_Rubberband->setEnabled(false);
        sizePolicy2.setHeightForWidth(comboBox_ResCon_Rubberband->sizePolicy().hasHeightForWidth());
        comboBox_ResCon_Rubberband->setSizePolicy(sizePolicy2);
        comboBox_ResCon_Rubberband->setMinimumSize(QSize(150, 0));
        comboBox_ResCon_Rubberband->setMaximumSize(QSize(150, 16777215));

        gridLayout_8->addWidget(comboBox_ResCon_Rubberband, 4, 1, 1, 2);

        verticalSpacer_ResCon = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_ResCon, 7, 1, 1, 2);

        line_ResCon_1 = new QFrame(groupBox_Results_Controls);
        line_ResCon_1->setObjectName(QString::fromUtf8("line_ResCon_1"));
        line_ResCon_1->setFrameShape(QFrame::HLine);
        line_ResCon_1->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(line_ResCon_1, 5, 1, 1, 6);

        line = new QFrame(groupBox_Results_Controls);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(line, 1, 1, 1, 6);

        checkBox_ResCon_Ignore_Zero = new QCheckBox(groupBox_Results_Controls);
        checkBox_ResCon_Ignore_Zero->setObjectName(QString::fromUtf8("checkBox_ResCon_Ignore_Zero"));
        checkBox_ResCon_Ignore_Zero->setEnabled(false);
        sizePolicy2.setHeightForWidth(checkBox_ResCon_Ignore_Zero->sizePolicy().hasHeightForWidth());
        checkBox_ResCon_Ignore_Zero->setSizePolicy(sizePolicy2);
        checkBox_ResCon_Ignore_Zero->setMinimumSize(QSize(150, 0));
        checkBox_ResCon_Ignore_Zero->setMaximumSize(QSize(150, 16777215));
        checkBox_ResCon_Ignore_Zero->setChecked(true);

        gridLayout_8->addWidget(checkBox_ResCon_Ignore_Zero, 0, 3, 1, 1);

        checkBox_ResCon_RoI_Only = new QCheckBox(groupBox_Results_Controls);
        checkBox_ResCon_RoI_Only->setObjectName(QString::fromUtf8("checkBox_ResCon_RoI_Only"));
        checkBox_ResCon_RoI_Only->setEnabled(false);
        sizePolicy2.setHeightForWidth(checkBox_ResCon_RoI_Only->sizePolicy().hasHeightForWidth());
        checkBox_ResCon_RoI_Only->setSizePolicy(sizePolicy2);
        checkBox_ResCon_RoI_Only->setMinimumSize(QSize(150, 0));
        checkBox_ResCon_RoI_Only->setMaximumSize(QSize(150, 16777215));
        checkBox_ResCon_RoI_Only->setChecked(true);

        gridLayout_8->addWidget(checkBox_ResCon_RoI_Only, 0, 1, 1, 2);

        gridLayout_ResCon = new QGridLayout();
        gridLayout_ResCon->setObjectName(QString::fromUtf8("gridLayout_ResCon"));
        gridLayout_ResCon->setHorizontalSpacing(6);
        gridLayout_ResCon->setVerticalSpacing(0);
        pushButton_RessCon_Zoom_In = new QPushButton(groupBox_Results_Controls);
        pushButton_RessCon_Zoom_In->setObjectName(QString::fromUtf8("pushButton_RessCon_Zoom_In"));
        pushButton_RessCon_Zoom_In->setEnabled(false);
        pushButton_RessCon_Zoom_In->setMaximumSize(QSize(30, 16777215));

        gridLayout_ResCon->addWidget(pushButton_RessCon_Zoom_In, 0, 1, 1, 1);

        pushButton_ResCon_Zoom_Out = new QPushButton(groupBox_Results_Controls);
        pushButton_ResCon_Zoom_Out->setObjectName(QString::fromUtf8("pushButton_ResCon_Zoom_Out"));
        pushButton_ResCon_Zoom_Out->setEnabled(false);
        pushButton_ResCon_Zoom_Out->setMaximumSize(QSize(30, 16777215));

        gridLayout_ResCon->addWidget(pushButton_ResCon_Zoom_Out, 0, 3, 1, 1);

        pushButton_ResCon_Zoom_Reset = new QPushButton(groupBox_Results_Controls);
        pushButton_ResCon_Zoom_Reset->setObjectName(QString::fromUtf8("pushButton_ResCon_Zoom_Reset"));
        pushButton_ResCon_Zoom_Reset->setEnabled(false);
        pushButton_ResCon_Zoom_Reset->setMaximumSize(QSize(30, 16777215));

        gridLayout_ResCon->addWidget(pushButton_ResCon_Zoom_Reset, 0, 2, 1, 1);

        label_ResCon_Zoom = new QLabel(groupBox_Results_Controls);
        label_ResCon_Zoom->setObjectName(QString::fromUtf8("label_ResCon_Zoom"));
        label_ResCon_Zoom->setEnabled(false);
        sizePolicy3.setHeightForWidth(label_ResCon_Zoom->sizePolicy().hasHeightForWidth());
        label_ResCon_Zoom->setSizePolicy(sizePolicy3);

        gridLayout_ResCon->addWidget(label_ResCon_Zoom, 0, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_ResCon, 4, 3, 1, 1);

        comboBox_ResCon_Legend = new QComboBox(groupBox_Results_Controls);
        comboBox_ResCon_Legend->setObjectName(QString::fromUtf8("comboBox_ResCon_Legend"));
        comboBox_ResCon_Legend->setEnabled(false);
        sizePolicy2.setHeightForWidth(comboBox_ResCon_Legend->sizePolicy().hasHeightForWidth());
        comboBox_ResCon_Legend->setSizePolicy(sizePolicy2);
        comboBox_ResCon_Legend->setMinimumSize(QSize(150, 0));
        comboBox_ResCon_Legend->setMaximumSize(QSize(150, 16777215));

        gridLayout_8->addWidget(comboBox_ResCon_Legend, 2, 1, 1, 2);

        checkBox_ResCon_AA = new QCheckBox(groupBox_Results_Controls);
        checkBox_ResCon_AA->setObjectName(QString::fromUtf8("checkBox_ResCon_AA"));
        checkBox_ResCon_AA->setEnabled(false);
        checkBox_ResCon_AA->setMinimumSize(QSize(40, 0));
        checkBox_ResCon_AA->setMaximumSize(QSize(40, 16777215));
        checkBox_ResCon_AA->setChecked(true);
        checkBox_ResCon_AA->setTristate(true);

        gridLayout_8->addWidget(checkBox_ResCon_AA, 2, 4, 1, 1);

        horizontalSpacer_ResCon = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_ResCon, 2, 5, 3, 2);


        gridLayout->addWidget(groupBox_Results_Controls, 1, 2, 1, 1);

        comboBox_AnalysedImage = new QComboBox(centralwidget);
        comboBox_AnalysedImage->setObjectName(QString::fromUtf8("comboBox_AnalysedImage"));

        gridLayout->addWidget(comboBox_AnalysedImage, 2, 0, 1, 3);

        D_MAKRO_Mitochondrien->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_Mitochondrien);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1412, 21));
        menuData = new QMenu(menubar);
        menuData->setObjectName(QString::fromUtf8("menuData"));
        menuLayout = new QMenu(menubar);
        menuLayout->setObjectName(QString::fromUtf8("menuLayout"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuViewer = new QMenu(menubar);
        menuViewer->setObjectName(QString::fromUtf8("menuViewer"));
        menuUpdate = new QMenu(menubar);
        menuUpdate->setObjectName(QString::fromUtf8("menuUpdate"));
        menuSave = new QMenu(menubar);
        menuSave->setObjectName(QString::fromUtf8("menuSave"));
        menuStream = new QMenu(menubar);
        menuStream->setObjectName(QString::fromUtf8("menuStream"));
        D_MAKRO_Mitochondrien->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_Mitochondrien);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_Mitochondrien->setStatusBar(statusbar);

        menubar->addAction(menuData->menuAction());
        menubar->addAction(menuSave->menuAction());
        menubar->addAction(menuLayout->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menubar->addAction(menuViewer->menuAction());
        menubar->addAction(menuUpdate->menuAction());
        menubar->addAction(menuStream->menuAction());
        menuData->addAction(action_Load);
        menuData->addAction(action_Clear_Queue);
        menuData->addAction(action_Next_Image);
        menuLayout->addAction(action_Show_Photons);
        menuLayout->addSeparator();
        menuLayout->addAction(action_Show_Parameters);
        menuLayout->addSeparator();
        menuLayout->addAction(action_Show_Results);
        menuWindow->addAction(action_Show_Minimum);
        menuWindow->addAction(action_Show_Normal);
        menuWindow->addAction(action_Show_Maximum);
        menuWindow->addAction(action_Show_Fullscreen);
        menuViewer->addAction(action_Smooth_Transformation);
        menuViewer->addAction(action_Keep_Aspect_Ratio);
        menuUpdate->addAction(action_Update_View);
        menuUpdate->addSeparator();
        menuUpdate->addAction(action_Update_Image_Processing);
        menuUpdate->addAction(action_Autoupdate_ImgProc_on_Paint);
        menuUpdate->addSeparator();
        menuUpdate->addAction(action_Update_Plot);
        menuUpdate->addAction(action_Autoupdate_Plot_on_ImgProc);
        menuUpdate->addSeparator();
        menuUpdate->addAction(action_Update_Calculation);
        menuUpdate->addAction(action_Autoupdate_Calc_on_ImgProc);
        menuSave->addAction(action_Autosave_CellSep_in_Img);
        menuSave->addSeparator();
        menuSave->addAction(action_Save_Photons);
        menuSave->addAction(action_Save_Parameters);
        menuSave->addAction(action_Save_Results);
        menuSave->addAction(action_Save_Plot);
        menuSave->addSeparator();
        menuSave->addAction(action_Autoselect_Save_Filename);
        menuStream->addAction(action_Stream_Open);
        menuStream->addAction(action_Stream_Current);
        menuStream->addAction(action_Stream_Close);

        retranslateUi(D_MAKRO_Mitochondrien);
        QObject::connect(action_Show_Fullscreen, SIGNAL(triggered(bool)), D_MAKRO_Mitochondrien, SLOT(showFullScreen()));
        QObject::connect(action_Show_Maximum, SIGNAL(triggered(bool)), D_MAKRO_Mitochondrien, SLOT(showMaximized()));
        QObject::connect(action_Show_Normal, SIGNAL(triggered(bool)), D_MAKRO_Mitochondrien, SLOT(showNormal()));
        QObject::connect(action_Show_Minimum, SIGNAL(triggered(bool)), D_MAKRO_Mitochondrien, SLOT(showMinimized()));
        QObject::connect(comboBox_ResImg_Type, SIGNAL(currentIndexChanged(int)), stackedWidget_ResImg_Type, SLOT(setCurrentIndex(int)));
        QObject::connect(comboBox_ResPlo_Type, SIGNAL(currentIndexChanged(int)), stackedWidget_ResPlo_Type, SLOT(setCurrentIndex(int)));

        tabWidget_Results->setCurrentIndex(0);
        stackedWidget_ResImg_Type->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(D_MAKRO_Mitochondrien);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_Mitochondrien)
    {
        D_MAKRO_Mitochondrien->setWindowTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "MainWindow", nullptr));
        action_Load->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Select Directory", nullptr));
#if QT_CONFIG(shortcut)
        action_Load->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Photons->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Photons", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Photons->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Parameters->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Parameters", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Parameters->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Results->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Results", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Results->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "F3", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Normal->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Normal", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Normal->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "F10", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Maximum->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Maximum", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Maximum->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "F11", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Fullscreen->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Fullscreen", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Fullscreen->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "F12", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Show_Minimum->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Minimum", nullptr));
#if QT_CONFIG(shortcut)
        action_Show_Minimum->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "F9", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Smooth_Transformation->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Smooth Transformation", nullptr));
        action_Keep_Aspect_Ratio->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Keep Aspect Ratio", nullptr));
        action_Update_View->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Update View", nullptr));
#if QT_CONFIG(shortcut)
        action_Update_View->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "F4", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Update_Image_Processing->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Update Image Processing", nullptr));
#if QT_CONFIG(shortcut)
        action_Update_Image_Processing->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Update_Plot->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Update Plot", nullptr));
#if QT_CONFIG(shortcut)
        action_Update_Plot->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "F6", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Clear_Queue->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Clear Queue", nullptr));
        action_Next_Image->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Next Image", nullptr));
#if QT_CONFIG(shortcut)
        action_Next_Image->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Autoupdate_Plot_on_ImgProc->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Autoupdate Plot on Image Processing", nullptr));
        action_Autoupdate_ImgProc_on_Paint->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Autoupdate Image Processing on Cell Separation", nullptr));
        action_Autosave_CellSep_in_Img->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Autosave Cell Separation in Image", nullptr));
        action_Update_Calculation->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Update Calculation", nullptr));
#if QT_CONFIG(shortcut)
        action_Update_Calculation->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "F7", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Autoupdate_Calc_on_ImgProc->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Autoupdate Calculation on Image Processing", nullptr));
        action_Stream_Open->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Open", nullptr));
        action_Stream_Current->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Stream Current", nullptr));
#if QT_CONFIG(shortcut)
        action_Stream_Current->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Stream_Close->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Close", nullptr));
        action_Save_Photons->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Save Photons", nullptr));
        action_Save_Parameters->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Save Parameters", nullptr));
        action_Save_Results->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Save Results", nullptr));
        action_Save_Plot->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Save Plot", nullptr));
        action_Autoselect_Save_Filename->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Autoselect Save Filename", nullptr));
        actionSave_Cytoplasma->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Save Cytoplasma", nullptr));
        groupBox_Photons_View->setTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "View   -   Photons", nullptr));
        comboBox_PhoVie_Step->setItemText(0, QCoreApplication::translate("D_MAKRO_Mitochondrien", "00 - Input - Loaded from file", nullptr));
        comboBox_PhoVie_Step->setItemText(1, QCoreApplication::translate("D_MAKRO_Mitochondrien", "01 - Input - Shading Correted", nullptr));
        comboBox_PhoVie_Step->setItemText(2, QCoreApplication::translate("D_MAKRO_Mitochondrien", "02 - Input - Convert to 8bit", nullptr));
        comboBox_PhoVie_Step->setItemText(3, QCoreApplication::translate("D_MAKRO_Mitochondrien", "03 - Input - Improved Contrast", nullptr));
        comboBox_PhoVie_Step->setItemText(4, QCoreApplication::translate("D_MAKRO_Mitochondrien", "04 - Blur - Remove Noise", nullptr));
        comboBox_PhoVie_Step->setItemText(5, QCoreApplication::translate("D_MAKRO_Mitochondrien", "05 - Binary - Get Foreground", nullptr));
        comboBox_PhoVie_Step->setItemText(6, QCoreApplication::translate("D_MAKRO_Mitochondrien", "06 - Regions - Paint Edges", nullptr));
        comboBox_PhoVie_Step->setItemText(7, QCoreApplication::translate("D_MAKRO_Mitochondrien", "07 - Regions - Edges Connected", nullptr));
        comboBox_PhoVie_Step->setItemText(8, QCoreApplication::translate("D_MAKRO_Mitochondrien", "08 - Regions - Separate Cells", nullptr));
        comboBox_PhoVie_Step->setItemText(9, QCoreApplication::translate("D_MAKRO_Mitochondrien", "09 - Regions - Labeled", nullptr));
        comboBox_PhoVie_Step->setItemText(10, QCoreApplication::translate("D_MAKRO_Mitochondrien", "10 - ROI - Mitochondria", nullptr));

        label_PhoVie_Format_MA->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "MA Format", nullptr));
        label_PhoVie_Format_QI->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "QI Format", nullptr));
        groupBox_Parameters_View->setTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "View   -   Parameters", nullptr));
        label_ParVie_Format_MA->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "MA Format", nullptr));
        label_ParVie_Format_QI->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "QI Format", nullptr));
        groupBox_Results_View->setTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "View   -   Results", nullptr));
        label_Gra_B->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "B", nullptr));
        label_Gra_R->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "R", nullptr));
        label_Gra_G->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "G", nullptr));
        label_Math_Par_1->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Par. 1", nullptr));
        label_Math_Par_2->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Par. 2", nullptr));
        comboBox_Math_Operator->setItemText(0, QCoreApplication::translate("D_MAKRO_Mitochondrien", "add", nullptr));
        comboBox_Math_Operator->setItemText(1, QCoreApplication::translate("D_MAKRO_Mitochondrien", "diff", nullptr));
        comboBox_Math_Operator->setItemText(2, QCoreApplication::translate("D_MAKRO_Mitochondrien", "diff (abs)", nullptr));
        comboBox_Math_Operator->setItemText(3, QCoreApplication::translate("D_MAKRO_Mitochondrien", "mult", nullptr));
        comboBox_Math_Operator->setItemText(4, QCoreApplication::translate("D_MAKRO_Mitochondrien", "div", nullptr));
        comboBox_Math_Operator->setItemText(5, QCoreApplication::translate("D_MAKRO_Mitochondrien", "min", nullptr));
        comboBox_Math_Operator->setItemText(6, QCoreApplication::translate("D_MAKRO_Mitochondrien", "max", nullptr));
        comboBox_Math_Operator->setItemText(7, QCoreApplication::translate("D_MAKRO_Mitochondrien", "equal", nullptr));
        comboBox_Math_Operator->setItemText(8, QCoreApplication::translate("D_MAKRO_Mitochondrien", "greater", nullptr));
        comboBox_Math_Operator->setItemText(9, QCoreApplication::translate("D_MAKRO_Mitochondrien", "greater equal", nullptr));
        comboBox_Math_Operator->setItemText(10, QCoreApplication::translate("D_MAKRO_Mitochondrien", "smaller", nullptr));
        comboBox_Math_Operator->setItemText(11, QCoreApplication::translate("D_MAKRO_Mitochondrien", "smaller equal", nullptr));
        comboBox_Math_Operator->setItemText(12, QCoreApplication::translate("D_MAKRO_Mitochondrien", "not equal", nullptr));

        label_Math_Operator->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Oper.", nullptr));
        comboBox_ResImg_Type->setItemText(0, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Color", nullptr));
        comboBox_ResImg_Type->setItemText(1, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Math", nullptr));

        tabWidget_Results->setTabText(tabWidget_Results->indexOf(tab_Image), QCoreApplication::translate("D_MAKRO_Mitochondrien", "Image", nullptr));
        label_SpacerForPlot->setText(QString());
        label_ResPlo_Information->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "-", nullptr));
        comboBox_ResPlo_Type->setItemText(0, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Histogram - Image", nullptr));
        comboBox_ResPlo_Type->setItemText(1, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Histogram - Cells", nullptr));
        comboBox_ResPlo_Type->setItemText(2, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Parameter - Pixels", nullptr));
        comboBox_ResPlo_Type->setItemText(3, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Parameter - Cells", nullptr));
        comboBox_ResPlo_Type->setItemText(4, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Statistic - Mean Median", nullptr));
        comboBox_ResPlo_Type->setItemText(5, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Statistic - CV Skewness Kurtosis", nullptr));
        comboBox_ResPlo_Type->setItemText(6, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Statistic - Quantiles", nullptr));

        checkBox_His_Uniform->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Uniform", nullptr));
        checkBox_His_Accumulate->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Accumulate", nullptr));
        checkBox_ParAll_Accumulate->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Accumulate", nullptr));
        checkBox_ParAll_Uniform->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Uniform", nullptr));
        label_Par_Nucleus->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Cell", nullptr));
        label_Par_X_Parameter->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "X Par.", nullptr));
        label_Par_Y_Parameter->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Y Par.", nullptr));
        label_ParCell_X->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "X:", nullptr));
        label_parCell_Y->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Y:", nullptr));
        checkBox_Stat_MM_ADM->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Dev.", nullptr));
        checkBox_Stat_MM_Median->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Median", nullptr));
        checkBox_Stat_MM_SD->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Dev.", nullptr));
        checkBox_Stat_MM_Mean->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Mean", nullptr));
        checkBox_Stat_CSK_CV->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "CV", nullptr));
        checkBox_Stat_CSK_Kurtosis->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Kurtosis", nullptr));
        checkBox_Stat_CSK_Skewness->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Skewness", nullptr));
        comboBox_Stat_Quantiles_Step->setItemText(0, QCoreApplication::translate("D_MAKRO_Mitochondrien", "05% Steps", nullptr));
        comboBox_Stat_Quantiles_Step->setItemText(1, QCoreApplication::translate("D_MAKRO_Mitochondrien", "10% Steps", nullptr));
        comboBox_Stat_Quantiles_Step->setItemText(2, QCoreApplication::translate("D_MAKRO_Mitochondrien", "20% Steps", nullptr));
        comboBox_Stat_Quantiles_Step->setItemText(3, QCoreApplication::translate("D_MAKRO_Mitochondrien", "25% Steps", nullptr));
        comboBox_Stat_Quantiles_Step->setItemText(4, QCoreApplication::translate("D_MAKRO_Mitochondrien", "50% Steps", nullptr));

        tabWidget_Results->setTabText(tabWidget_Results->indexOf(tab_Plot), QCoreApplication::translate("D_MAKRO_Mitochondrien", "Plot", nullptr));
        groupBox_Photons_Controls->setTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Controls   -   Photons", nullptr));
        label_PhoCon_Blur_Description->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Bluring Strength", nullptr));
        label_PhoCon_EdgCon_Desciption->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Connect Lines", nullptr));
        label_PhoCon_Paint_Title->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Seperate Cells", nullptr));
        label_PhoCon_Paint_Pos->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "06", nullptr));
        pushButton_PhoCon_Paint_Load->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Load", nullptr));
        pushButton_PhoCon_Paint_Save->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Save", nullptr));
        pushButton_PhoCon_Paint_Undo->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Undo", nullptr));
        pushButton_PhoCon_Paint_Reset->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Reset", nullptr));
        lineEdit_PhoCon_Preset->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "suffix", nullptr));
        label_PhoCon_Thres_Pos->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "05", nullptr));
        label_PhoCon_Blur_Pos->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "04", nullptr));
        label_PhoCon_Thres_Title->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Size / Offset", nullptr));
        label_PhoCon_Blur_Title->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Size / Sigma", nullptr));
        radioButton_PhoCon_Paint_Line->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Line", nullptr));
        label_PhoCon_EdgCon_Pos->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "07", nullptr));
        label_PhoCon_EdgCon_Title->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Size", nullptr));
        spinBox_PhoCon_Blur_Size->setSuffix(QString());
        radioButton_PhoCon_Paint_Fill->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Fill", nullptr));
        comboBox_PhoCon_Paint_Color->setItemText(0, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Background", nullptr));
        comboBox_PhoCon_Paint_Color->setItemText(1, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Foreground", nullptr));

        comboBox_PhoCon_Paint_FillStep->setItemText(0, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Step 7", nullptr));
        comboBox_PhoCon_Paint_FillStep->setItemText(1, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Step 6", nullptr));

        label_PhoCon_Paint_Thick->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Width", nullptr));
        label_PhoCon_Thres_Description->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Foreground Mitoch.", nullptr));
        groupBox_Parameters_Controls->setTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Controls   -   Parameters", nullptr));
        groupBox_ParCon_View->setTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "View", nullptr));
        checkBox_ParVie_RoI_Only->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "View RoI only", nullptr));
        checkBox_ParVie_Contrast->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "View contrast improved", nullptr));
        label_ParVie_0->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Show 0 as:", nullptr));
        radioButton_ParVie_0_as_0->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "0", nullptr));
        radioButton_ParVie_0_as_Min->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Min", nullptr));
        radioButton_ParVie_0_as_Max->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Max", nullptr));
        groupBox_ParCon_T2->setTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "t2", nullptr));
        ParCon_T2_Const->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Formula-Constant", nullptr));
        ParCon_T2_Thres->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Threshold", nullptr));
#if QT_CONFIG(whatsthis)
        label_ParCon_T2_NADH_NADPH->setWhatsThis(QCoreApplication::translate("D_MAKRO_Mitochondrien", "<html><head/><body><p>If t2 value is set to threshold value, this is the resulting NADH/NADPH value.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_ParCon_T2_NADH_NADPH->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "NADH/NADPH", nullptr));
        label_ParCon_T2_Min->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Minimum", nullptr));
        label_ParCon_T2_NADH_NADPH_ValLow->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "0", nullptr));
        label_ParCon_T2_Max->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Maximum", nullptr));
        label_ParCon_T2_NADH_NADPH_ValHigh->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "57", nullptr));
        groupBox_ParCon_Suffix->setTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Suffixes", nullptr));
        plainTextEdit_ParCon_Suffixes->setPlainText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "a1[%]\n"
"a2[%]\n"
"t1\n"
"t2\n"
"chi\n"
"offset\n"
"scatter", nullptr));
        groupBox_Results_Controls->setTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Controls   -   Results", nullptr));
        comboBox_ResCon_Rubberband->setItemText(0, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Rubberband: both", nullptr));
        comboBox_ResCon_Rubberband->setItemText(1, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Rubberband: X", nullptr));
        comboBox_ResCon_Rubberband->setItemText(2, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Rubberband: Y", nullptr));
        comboBox_ResCon_Rubberband->setItemText(3, QCoreApplication::translate("D_MAKRO_Mitochondrien", "Rubberband: none", nullptr));

        checkBox_ResCon_Ignore_Zero->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Ignore 0 parameters", nullptr));
        checkBox_ResCon_RoI_Only->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Calc for RoI only", nullptr));
        pushButton_RessCon_Zoom_In->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "+", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_RessCon_Zoom_In->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "+", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_ResCon_Zoom_Out->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "-", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_ResCon_Zoom_Out->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "-", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_ResCon_Zoom_Reset->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "o", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_ResCon_Zoom_Reset->setShortcut(QCoreApplication::translate("D_MAKRO_Mitochondrien", "0", nullptr));
#endif // QT_CONFIG(shortcut)
        label_ResCon_Zoom->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Zoom:", nullptr));
        checkBox_ResCon_AA->setText(QCoreApplication::translate("D_MAKRO_Mitochondrien", "AA", nullptr));
        menuData->setTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Data", nullptr));
        menuLayout->setTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Layout", nullptr));
        menuWindow->setTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Window", nullptr));
        menuViewer->setTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Viewer", nullptr));
        menuUpdate->setTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Update", nullptr));
        menuSave->setTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Save", nullptr));
        menuStream->setTitle(QCoreApplication::translate("D_MAKRO_Mitochondrien", "Stream", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_Mitochondrien: public Ui_D_MAKRO_Mitochondrien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_MITOCHONDRIEN_H
