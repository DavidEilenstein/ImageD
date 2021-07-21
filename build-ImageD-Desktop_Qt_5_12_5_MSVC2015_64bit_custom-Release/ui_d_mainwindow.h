/********************************************************************************
** Form generated from reading UI file 'd_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAINWINDOW_H
#define UI_D_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MainWindow
{
public:
    QAction *action_Smooth_Transformation;
    QAction *action_Keep_Aspect_Ratio;
    QAction *action_Show_Minimize;
    QAction *action_Show_Normal;
    QAction *action_Show_Maximize;
    QAction *action_Show_Fullscreen;
    QAction *action_Update_All_Steps;
    QAction *action_Update_Times;
    QAction *action_Autoupdate_Times_on_Steps;
    QAction *action_Autoupdate_Times_on_TimesSettings;
    QAction *action_Set_Step_Pos;
    QAction *action_Test_Statistic_Function;
    QAction *action_Test_Quatile_Access;
    QAction *action_Stat_Tester;
    QAction *action_Steps_Normal_Size;
    QAction *action_Test_D_VisDat;
    QAction *actionTest_ND_Mat_load_and_display;
    QAction *action_Test_1D_EDT;
    QAction *action_StepDefault_Autoupdate_Steps_on_Settings_changed;
    QAction *action_StepDefault_Viewer_Smooth_Transformation;
    QAction *action_StepDefault_Viewer_Keep_Aspect_Ratio;
    QAction *action_StepDefault_Skip_when_all_Steps_are_updated;
    QAction *action_StepDefault_Connect_Plane_Position;
    QAction *action_StepDefault_Connect_Steps_Zoom;
    QAction *actionTest_DPF_Writer;
    QAction *actionTest_Running_Median;
    QAction *actionTest_Maximum_Gil;
    QAction *actionTest_nD_for_loop;
    QAction *actionTest_range_selector;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_Plugins;
    QGridLayout *gridLayout_7;
    QComboBox *comboBox_PluginList;
    QPushButton *pushButton_PluginLaunch;
    QGroupBox *groupBox_Analysis;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_Analysis_Add;
    QGroupBox *groupBox_References;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_Ref_OBV;
    QPushButton *pushButton_Ref_Docs;
    QPushButton *pushButton_Ref_OpenCV;
    QPushButton *pushButton_Ref_Qt;
    QPushButton *pushButton_Ref_Biophysics;
    QPushButton *pushButton_Ref_Citation;
    QPushButton *pushButton_Ref_Contact;
    QPushButton *pushButton_Ref_Licence;
    QPushButton *pushButton_Ref_GSI;
    QPushButton *pushButton_Ref_hda;
    QPushButton *pushButton_Ref_Github;
    QTabWidget *tabWidget_Overview;
    QWidget *Images;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_Step_Add;
    QLabel *label_Viewer;
    QSpinBox *spinBox_Viewer_Image_Number;
    QPushButton *pushButton_Steps_Save;
    QPushButton *pushButton_Steps_Update;
    QSpacerItem *horizontalSpacer;
    QGraphicsView *graphicsView_Viewer;
    QWidget *Times;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_Times;
    QCheckBox *checkBox_Times_Processing;
    QPushButton *pushButton_Update_Times;
    QCheckBox *checkBox_Times_Conversion;
    QFrame *line_Times;
    QCheckBox *checkBox_Times_Show;
    QSpacerItem *horizontalSpacer_Times;
    QCheckBox *checkBox_Times_Hist;
    QLabel *label_Times_Total;
    QMenuBar *menuBar;
    QMenu *menuViewer;
    QMenu *menuWindow;
    QMenu *menuUpdate;
    QMenu *menuSteps;
    QMenu *menuTests;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *D_MainWindow)
    {
        if (D_MainWindow->objectName().isEmpty())
            D_MainWindow->setObjectName(QString::fromUtf8("D_MainWindow"));
        D_MainWindow->resize(580, 639);
        D_MainWindow->setStyleSheet(QString::fromUtf8(""));
        D_MainWindow->setDockNestingEnabled(false);
        D_MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        action_Smooth_Transformation = new QAction(D_MainWindow);
        action_Smooth_Transformation->setObjectName(QString::fromUtf8("action_Smooth_Transformation"));
        action_Smooth_Transformation->setCheckable(true);
        action_Smooth_Transformation->setChecked(true);
        action_Keep_Aspect_Ratio = new QAction(D_MainWindow);
        action_Keep_Aspect_Ratio->setObjectName(QString::fromUtf8("action_Keep_Aspect_Ratio"));
        action_Keep_Aspect_Ratio->setCheckable(true);
        action_Keep_Aspect_Ratio->setChecked(true);
        action_Show_Minimize = new QAction(D_MainWindow);
        action_Show_Minimize->setObjectName(QString::fromUtf8("action_Show_Minimize"));
        action_Show_Normal = new QAction(D_MainWindow);
        action_Show_Normal->setObjectName(QString::fromUtf8("action_Show_Normal"));
        action_Show_Maximize = new QAction(D_MainWindow);
        action_Show_Maximize->setObjectName(QString::fromUtf8("action_Show_Maximize"));
        action_Show_Fullscreen = new QAction(D_MainWindow);
        action_Show_Fullscreen->setObjectName(QString::fromUtf8("action_Show_Fullscreen"));
        action_Update_All_Steps = new QAction(D_MainWindow);
        action_Update_All_Steps->setObjectName(QString::fromUtf8("action_Update_All_Steps"));
        action_Update_Times = new QAction(D_MainWindow);
        action_Update_Times->setObjectName(QString::fromUtf8("action_Update_Times"));
        action_Autoupdate_Times_on_Steps = new QAction(D_MainWindow);
        action_Autoupdate_Times_on_Steps->setObjectName(QString::fromUtf8("action_Autoupdate_Times_on_Steps"));
        action_Autoupdate_Times_on_Steps->setCheckable(true);
        action_Autoupdate_Times_on_TimesSettings = new QAction(D_MainWindow);
        action_Autoupdate_Times_on_TimesSettings->setObjectName(QString::fromUtf8("action_Autoupdate_Times_on_TimesSettings"));
        action_Autoupdate_Times_on_TimesSettings->setCheckable(true);
        action_Autoupdate_Times_on_TimesSettings->setChecked(true);
        action_Set_Step_Pos = new QAction(D_MainWindow);
        action_Set_Step_Pos->setObjectName(QString::fromUtf8("action_Set_Step_Pos"));
        action_Test_Statistic_Function = new QAction(D_MainWindow);
        action_Test_Statistic_Function->setObjectName(QString::fromUtf8("action_Test_Statistic_Function"));
        action_Test_Quatile_Access = new QAction(D_MainWindow);
        action_Test_Quatile_Access->setObjectName(QString::fromUtf8("action_Test_Quatile_Access"));
        action_Stat_Tester = new QAction(D_MainWindow);
        action_Stat_Tester->setObjectName(QString::fromUtf8("action_Stat_Tester"));
        action_Steps_Normal_Size = new QAction(D_MainWindow);
        action_Steps_Normal_Size->setObjectName(QString::fromUtf8("action_Steps_Normal_Size"));
        action_Test_D_VisDat = new QAction(D_MainWindow);
        action_Test_D_VisDat->setObjectName(QString::fromUtf8("action_Test_D_VisDat"));
        actionTest_ND_Mat_load_and_display = new QAction(D_MainWindow);
        actionTest_ND_Mat_load_and_display->setObjectName(QString::fromUtf8("actionTest_ND_Mat_load_and_display"));
        action_Test_1D_EDT = new QAction(D_MainWindow);
        action_Test_1D_EDT->setObjectName(QString::fromUtf8("action_Test_1D_EDT"));
        action_StepDefault_Autoupdate_Steps_on_Settings_changed = new QAction(D_MainWindow);
        action_StepDefault_Autoupdate_Steps_on_Settings_changed->setObjectName(QString::fromUtf8("action_StepDefault_Autoupdate_Steps_on_Settings_changed"));
        action_StepDefault_Autoupdate_Steps_on_Settings_changed->setCheckable(true);
        action_StepDefault_Autoupdate_Steps_on_Settings_changed->setChecked(true);
        action_StepDefault_Viewer_Smooth_Transformation = new QAction(D_MainWindow);
        action_StepDefault_Viewer_Smooth_Transformation->setObjectName(QString::fromUtf8("action_StepDefault_Viewer_Smooth_Transformation"));
        action_StepDefault_Viewer_Smooth_Transformation->setCheckable(true);
        action_StepDefault_Viewer_Smooth_Transformation->setChecked(true);
        action_StepDefault_Viewer_Keep_Aspect_Ratio = new QAction(D_MainWindow);
        action_StepDefault_Viewer_Keep_Aspect_Ratio->setObjectName(QString::fromUtf8("action_StepDefault_Viewer_Keep_Aspect_Ratio"));
        action_StepDefault_Viewer_Keep_Aspect_Ratio->setCheckable(true);
        action_StepDefault_Viewer_Keep_Aspect_Ratio->setChecked(true);
        action_StepDefault_Skip_when_all_Steps_are_updated = new QAction(D_MainWindow);
        action_StepDefault_Skip_when_all_Steps_are_updated->setObjectName(QString::fromUtf8("action_StepDefault_Skip_when_all_Steps_are_updated"));
        action_StepDefault_Skip_when_all_Steps_are_updated->setCheckable(true);
        action_StepDefault_Connect_Plane_Position = new QAction(D_MainWindow);
        action_StepDefault_Connect_Plane_Position->setObjectName(QString::fromUtf8("action_StepDefault_Connect_Plane_Position"));
        action_StepDefault_Connect_Plane_Position->setCheckable(true);
        action_StepDefault_Connect_Plane_Position->setChecked(true);
        action_StepDefault_Connect_Steps_Zoom = new QAction(D_MainWindow);
        action_StepDefault_Connect_Steps_Zoom->setObjectName(QString::fromUtf8("action_StepDefault_Connect_Steps_Zoom"));
        action_StepDefault_Connect_Steps_Zoom->setCheckable(true);
        action_StepDefault_Connect_Steps_Zoom->setChecked(true);
        actionTest_DPF_Writer = new QAction(D_MainWindow);
        actionTest_DPF_Writer->setObjectName(QString::fromUtf8("actionTest_DPF_Writer"));
        actionTest_Running_Median = new QAction(D_MainWindow);
        actionTest_Running_Median->setObjectName(QString::fromUtf8("actionTest_Running_Median"));
        actionTest_Maximum_Gil = new QAction(D_MainWindow);
        actionTest_Maximum_Gil->setObjectName(QString::fromUtf8("actionTest_Maximum_Gil"));
        actionTest_nD_for_loop = new QAction(D_MainWindow);
        actionTest_nD_for_loop->setObjectName(QString::fromUtf8("actionTest_nD_for_loop"));
        actionTest_range_selector = new QAction(D_MainWindow);
        actionTest_range_selector->setObjectName(QString::fromUtf8("actionTest_range_selector"));
        centralWidget = new QWidget(D_MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_Plugins = new QGroupBox(centralWidget);
        groupBox_Plugins->setObjectName(QString::fromUtf8("groupBox_Plugins"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_Plugins->sizePolicy().hasHeightForWidth());
        groupBox_Plugins->setSizePolicy(sizePolicy);
        gridLayout_7 = new QGridLayout(groupBox_Plugins);
        gridLayout_7->setSpacing(3);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(6, 6, 6, 6);
        comboBox_PluginList = new QComboBox(groupBox_Plugins);
        comboBox_PluginList->setObjectName(QString::fromUtf8("comboBox_PluginList"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_PluginList->sizePolicy().hasHeightForWidth());
        comboBox_PluginList->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(comboBox_PluginList, 0, 1, 1, 1);

        pushButton_PluginLaunch = new QPushButton(groupBox_Plugins);
        pushButton_PluginLaunch->setObjectName(QString::fromUtf8("pushButton_PluginLaunch"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(120);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_PluginLaunch->sizePolicy().hasHeightForWidth());
        pushButton_PluginLaunch->setSizePolicy(sizePolicy2);
        pushButton_PluginLaunch->setMinimumSize(QSize(120, 0));

        gridLayout_7->addWidget(pushButton_PluginLaunch, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox_Plugins, 2, 1, 1, 1);

        groupBox_Analysis = new QGroupBox(centralWidget);
        groupBox_Analysis->setObjectName(QString::fromUtf8("groupBox_Analysis"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_Analysis->sizePolicy().hasHeightForWidth());
        groupBox_Analysis->setSizePolicy(sizePolicy3);
        groupBox_Analysis->setMinimumSize(QSize(0, 0));
        gridLayout_5 = new QGridLayout(groupBox_Analysis);
        gridLayout_5->setSpacing(3);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(6, 6, 6, 6);
        pushButton_Analysis_Add = new QPushButton(groupBox_Analysis);
        pushButton_Analysis_Add->setObjectName(QString::fromUtf8("pushButton_Analysis_Add"));
        sizePolicy1.setHeightForWidth(pushButton_Analysis_Add->sizePolicy().hasHeightForWidth());
        pushButton_Analysis_Add->setSizePolicy(sizePolicy1);
        pushButton_Analysis_Add->setMinimumSize(QSize(0, 0));
        pushButton_Analysis_Add->setMaximumSize(QSize(120, 16777215));

        gridLayout_5->addWidget(pushButton_Analysis_Add, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_Analysis, 2, 2, 1, 1);

        groupBox_References = new QGroupBox(centralWidget);
        groupBox_References->setObjectName(QString::fromUtf8("groupBox_References"));
        gridLayout_6 = new QGridLayout(groupBox_References);
        gridLayout_6->setSpacing(3);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(6, 6, 6, 6);
        pushButton_Ref_OBV = new QPushButton(groupBox_References);
        pushButton_Ref_OBV->setObjectName(QString::fromUtf8("pushButton_Ref_OBV"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_Ref_OBV->sizePolicy().hasHeightForWidth());
        pushButton_Ref_OBV->setSizePolicy(sizePolicy4);
        pushButton_Ref_OBV->setMinimumSize(QSize(30, 30));
        pushButton_Ref_OBV->setMaximumSize(QSize(16777215, 30));
        pushButton_Ref_OBV->setStyleSheet(QString::fromUtf8("background-color : white;"));

        gridLayout_6->addWidget(pushButton_Ref_OBV, 0, 8, 1, 1);

        pushButton_Ref_Docs = new QPushButton(groupBox_References);
        pushButton_Ref_Docs->setObjectName(QString::fromUtf8("pushButton_Ref_Docs"));
        sizePolicy4.setHeightForWidth(pushButton_Ref_Docs->sizePolicy().hasHeightForWidth());
        pushButton_Ref_Docs->setSizePolicy(sizePolicy4);
        pushButton_Ref_Docs->setMinimumSize(QSize(30, 30));
        pushButton_Ref_Docs->setMaximumSize(QSize(16777215, 30));
        pushButton_Ref_Docs->setStyleSheet(QString::fromUtf8("background-color : white;"));

        gridLayout_6->addWidget(pushButton_Ref_Docs, 0, 0, 1, 1);

        pushButton_Ref_OpenCV = new QPushButton(groupBox_References);
        pushButton_Ref_OpenCV->setObjectName(QString::fromUtf8("pushButton_Ref_OpenCV"));
        sizePolicy4.setHeightForWidth(pushButton_Ref_OpenCV->sizePolicy().hasHeightForWidth());
        pushButton_Ref_OpenCV->setSizePolicy(sizePolicy4);
        pushButton_Ref_OpenCV->setMinimumSize(QSize(30, 30));
        pushButton_Ref_OpenCV->setMaximumSize(QSize(16777215, 30));
        pushButton_Ref_OpenCV->setStyleSheet(QString::fromUtf8("background-color : white;"));

        gridLayout_6->addWidget(pushButton_Ref_OpenCV, 0, 9, 1, 1);

        pushButton_Ref_Qt = new QPushButton(groupBox_References);
        pushButton_Ref_Qt->setObjectName(QString::fromUtf8("pushButton_Ref_Qt"));
        sizePolicy4.setHeightForWidth(pushButton_Ref_Qt->sizePolicy().hasHeightForWidth());
        pushButton_Ref_Qt->setSizePolicy(sizePolicy4);
        pushButton_Ref_Qt->setMinimumSize(QSize(30, 30));
        pushButton_Ref_Qt->setMaximumSize(QSize(16777215, 30));
        pushButton_Ref_Qt->setStyleSheet(QString::fromUtf8("background-color : white;"));

        gridLayout_6->addWidget(pushButton_Ref_Qt, 0, 10, 1, 1);

        pushButton_Ref_Biophysics = new QPushButton(groupBox_References);
        pushButton_Ref_Biophysics->setObjectName(QString::fromUtf8("pushButton_Ref_Biophysics"));
        sizePolicy4.setHeightForWidth(pushButton_Ref_Biophysics->sizePolicy().hasHeightForWidth());
        pushButton_Ref_Biophysics->setSizePolicy(sizePolicy4);
        pushButton_Ref_Biophysics->setMinimumSize(QSize(30, 30));
        pushButton_Ref_Biophysics->setMaximumSize(QSize(16777215, 30));
        pushButton_Ref_Biophysics->setStyleSheet(QString::fromUtf8("background-color : white;"));

        gridLayout_6->addWidget(pushButton_Ref_Biophysics, 0, 6, 1, 1);

        pushButton_Ref_Citation = new QPushButton(groupBox_References);
        pushButton_Ref_Citation->setObjectName(QString::fromUtf8("pushButton_Ref_Citation"));
        sizePolicy4.setHeightForWidth(pushButton_Ref_Citation->sizePolicy().hasHeightForWidth());
        pushButton_Ref_Citation->setSizePolicy(sizePolicy4);
        pushButton_Ref_Citation->setMinimumSize(QSize(30, 30));
        pushButton_Ref_Citation->setMaximumSize(QSize(16777215, 30));
        pushButton_Ref_Citation->setStyleSheet(QString::fromUtf8("background-color : white;"));

        gridLayout_6->addWidget(pushButton_Ref_Citation, 0, 3, 1, 1);

        pushButton_Ref_Contact = new QPushButton(groupBox_References);
        pushButton_Ref_Contact->setObjectName(QString::fromUtf8("pushButton_Ref_Contact"));
        sizePolicy4.setHeightForWidth(pushButton_Ref_Contact->sizePolicy().hasHeightForWidth());
        pushButton_Ref_Contact->setSizePolicy(sizePolicy4);
        pushButton_Ref_Contact->setMinimumSize(QSize(30, 30));
        pushButton_Ref_Contact->setMaximumSize(QSize(16777215, 30));
        pushButton_Ref_Contact->setStyleSheet(QString::fromUtf8("background-color : white;"));

        gridLayout_6->addWidget(pushButton_Ref_Contact, 0, 4, 1, 1);

        pushButton_Ref_Licence = new QPushButton(groupBox_References);
        pushButton_Ref_Licence->setObjectName(QString::fromUtf8("pushButton_Ref_Licence"));
        sizePolicy4.setHeightForWidth(pushButton_Ref_Licence->sizePolicy().hasHeightForWidth());
        pushButton_Ref_Licence->setSizePolicy(sizePolicy4);
        pushButton_Ref_Licence->setMinimumSize(QSize(30, 30));
        pushButton_Ref_Licence->setMaximumSize(QSize(16777215, 30));
        pushButton_Ref_Licence->setStyleSheet(QString::fromUtf8("background-color : white;"));

        gridLayout_6->addWidget(pushButton_Ref_Licence, 0, 2, 1, 1);

        pushButton_Ref_GSI = new QPushButton(groupBox_References);
        pushButton_Ref_GSI->setObjectName(QString::fromUtf8("pushButton_Ref_GSI"));
        sizePolicy4.setHeightForWidth(pushButton_Ref_GSI->sizePolicy().hasHeightForWidth());
        pushButton_Ref_GSI->setSizePolicy(sizePolicy4);
        pushButton_Ref_GSI->setMinimumSize(QSize(30, 30));
        pushButton_Ref_GSI->setMaximumSize(QSize(16777215, 30));
        pushButton_Ref_GSI->setStyleSheet(QString::fromUtf8("background-color : white;"));

        gridLayout_6->addWidget(pushButton_Ref_GSI, 0, 5, 1, 1);

        pushButton_Ref_hda = new QPushButton(groupBox_References);
        pushButton_Ref_hda->setObjectName(QString::fromUtf8("pushButton_Ref_hda"));
        sizePolicy4.setHeightForWidth(pushButton_Ref_hda->sizePolicy().hasHeightForWidth());
        pushButton_Ref_hda->setSizePolicy(sizePolicy4);
        pushButton_Ref_hda->setMinimumSize(QSize(30, 30));
        pushButton_Ref_hda->setMaximumSize(QSize(16777215, 30));
        pushButton_Ref_hda->setStyleSheet(QString::fromUtf8("background-color : white;"));

        gridLayout_6->addWidget(pushButton_Ref_hda, 0, 7, 1, 1);

        pushButton_Ref_Github = new QPushButton(groupBox_References);
        pushButton_Ref_Github->setObjectName(QString::fromUtf8("pushButton_Ref_Github"));
        sizePolicy4.setHeightForWidth(pushButton_Ref_Github->sizePolicy().hasHeightForWidth());
        pushButton_Ref_Github->setSizePolicy(sizePolicy4);
        pushButton_Ref_Github->setMinimumSize(QSize(30, 30));
        pushButton_Ref_Github->setMaximumSize(QSize(16777215, 30));
        pushButton_Ref_Github->setStyleSheet(QString::fromUtf8("background-color : white;"));

        gridLayout_6->addWidget(pushButton_Ref_Github, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox_References, 3, 0, 1, 3);

        tabWidget_Overview = new QTabWidget(centralWidget);
        tabWidget_Overview->setObjectName(QString::fromUtf8("tabWidget_Overview"));
        tabWidget_Overview->setTabShape(QTabWidget::Rounded);
        Images = new QWidget();
        Images->setObjectName(QString::fromUtf8("Images"));
        gridLayout_2 = new QGridLayout(Images);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(6, 6, 6, 6);
        pushButton_Step_Add = new QPushButton(Images);
        pushButton_Step_Add->setObjectName(QString::fromUtf8("pushButton_Step_Add"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(2);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pushButton_Step_Add->sizePolicy().hasHeightForWidth());
        pushButton_Step_Add->setSizePolicy(sizePolicy5);
        pushButton_Step_Add->setMinimumSize(QSize(120, 0));
        pushButton_Step_Add->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(pushButton_Step_Add, 1, 0, 1, 1);

        label_Viewer = new QLabel(Images);
        label_Viewer->setObjectName(QString::fromUtf8("label_Viewer"));
        sizePolicy3.setHeightForWidth(label_Viewer->sizePolicy().hasHeightForWidth());
        label_Viewer->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(label_Viewer, 1, 3, 1, 1);

        spinBox_Viewer_Image_Number = new QSpinBox(Images);
        spinBox_Viewer_Image_Number->setObjectName(QString::fromUtf8("spinBox_Viewer_Image_Number"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(1);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(spinBox_Viewer_Image_Number->sizePolicy().hasHeightForWidth());
        spinBox_Viewer_Image_Number->setSizePolicy(sizePolicy6);
        spinBox_Viewer_Image_Number->setMaximum(10000);

        gridLayout_2->addWidget(spinBox_Viewer_Image_Number, 1, 4, 1, 1);

        pushButton_Steps_Save = new QPushButton(Images);
        pushButton_Steps_Save->setObjectName(QString::fromUtf8("pushButton_Steps_Save"));
        sizePolicy5.setHeightForWidth(pushButton_Steps_Save->sizePolicy().hasHeightForWidth());
        pushButton_Steps_Save->setSizePolicy(sizePolicy5);
        pushButton_Steps_Save->setMinimumSize(QSize(120, 0));
        pushButton_Steps_Save->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(pushButton_Steps_Save, 1, 2, 1, 1);

        pushButton_Steps_Update = new QPushButton(Images);
        pushButton_Steps_Update->setObjectName(QString::fromUtf8("pushButton_Steps_Update"));
        pushButton_Steps_Update->setEnabled(true);
        sizePolicy5.setHeightForWidth(pushButton_Steps_Update->sizePolicy().hasHeightForWidth());
        pushButton_Steps_Update->setSizePolicy(sizePolicy5);
        pushButton_Steps_Update->setMinimumSize(QSize(120, 0));
        pushButton_Steps_Update->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(pushButton_Steps_Update, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 5, 1, 1);

        graphicsView_Viewer = new QGraphicsView(Images);
        graphicsView_Viewer->setObjectName(QString::fromUtf8("graphicsView_Viewer"));

        gridLayout_2->addWidget(graphicsView_Viewer, 0, 0, 1, 6);

        tabWidget_Overview->addTab(Images, QString());
        Times = new QWidget();
        Times->setObjectName(QString::fromUtf8("Times"));
        gridLayout_4 = new QGridLayout(Times);
        gridLayout_4->setSpacing(3);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(6, 6, 6, 6);
        gridLayout_Times = new QGridLayout();
        gridLayout_Times->setSpacing(6);
        gridLayout_Times->setObjectName(QString::fromUtf8("gridLayout_Times"));

        gridLayout_4->addLayout(gridLayout_Times, 1, 0, 1, 7);

        checkBox_Times_Processing = new QCheckBox(Times);
        checkBox_Times_Processing->setObjectName(QString::fromUtf8("checkBox_Times_Processing"));
        checkBox_Times_Processing->setEnabled(true);
        checkBox_Times_Processing->setChecked(true);

        gridLayout_4->addWidget(checkBox_Times_Processing, 0, 2, 1, 1);

        pushButton_Update_Times = new QPushButton(Times);
        pushButton_Update_Times->setObjectName(QString::fromUtf8("pushButton_Update_Times"));
        pushButton_Update_Times->setEnabled(true);
        pushButton_Update_Times->setMinimumSize(QSize(130, 0));

        gridLayout_4->addWidget(pushButton_Update_Times, 0, 0, 1, 1);

        checkBox_Times_Conversion = new QCheckBox(Times);
        checkBox_Times_Conversion->setObjectName(QString::fromUtf8("checkBox_Times_Conversion"));
        checkBox_Times_Conversion->setEnabled(true);
        checkBox_Times_Conversion->setChecked(true);

        gridLayout_4->addWidget(checkBox_Times_Conversion, 0, 3, 1, 1);

        line_Times = new QFrame(Times);
        line_Times->setObjectName(QString::fromUtf8("line_Times"));
        line_Times->setFrameShape(QFrame::VLine);
        line_Times->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_Times, 0, 1, 1, 1);

        checkBox_Times_Show = new QCheckBox(Times);
        checkBox_Times_Show->setObjectName(QString::fromUtf8("checkBox_Times_Show"));
        checkBox_Times_Show->setEnabled(true);
        checkBox_Times_Show->setChecked(true);

        gridLayout_4->addWidget(checkBox_Times_Show, 0, 4, 1, 1);

        horizontalSpacer_Times = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_Times, 0, 6, 1, 1);

        checkBox_Times_Hist = new QCheckBox(Times);
        checkBox_Times_Hist->setObjectName(QString::fromUtf8("checkBox_Times_Hist"));
        checkBox_Times_Hist->setEnabled(true);

        gridLayout_4->addWidget(checkBox_Times_Hist, 0, 5, 1, 1);

        label_Times_Total = new QLabel(Times);
        label_Times_Total->setObjectName(QString::fromUtf8("label_Times_Total"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_Times_Total->sizePolicy().hasHeightForWidth());
        label_Times_Total->setSizePolicy(sizePolicy7);

        gridLayout_4->addWidget(label_Times_Total, 2, 0, 1, 7);

        tabWidget_Overview->addTab(Times, QString());

        gridLayout->addWidget(tabWidget_Overview, 0, 0, 1, 3);

        D_MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(D_MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 580, 21));
        menuViewer = new QMenu(menuBar);
        menuViewer->setObjectName(QString::fromUtf8("menuViewer"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuUpdate = new QMenu(menuBar);
        menuUpdate->setObjectName(QString::fromUtf8("menuUpdate"));
        menuSteps = new QMenu(menuBar);
        menuSteps->setObjectName(QString::fromUtf8("menuSteps"));
        menuTests = new QMenu(menuBar);
        menuTests->setObjectName(QString::fromUtf8("menuTests"));
        D_MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(D_MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        D_MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(D_MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        D_MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuViewer->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuUpdate->menuAction());
        menuBar->addAction(menuSteps->menuAction());
        menuBar->addAction(menuTests->menuAction());
        menuViewer->addAction(action_Smooth_Transformation);
        menuViewer->addAction(action_Keep_Aspect_Ratio);
        menuWindow->addAction(action_Show_Minimize);
        menuWindow->addAction(action_Show_Normal);
        menuWindow->addAction(action_Show_Maximize);
        menuWindow->addAction(action_Show_Fullscreen);
        menuUpdate->addAction(action_Update_All_Steps);
        menuUpdate->addAction(action_Update_Times);
        menuUpdate->addSeparator();
        menuUpdate->addAction(action_Autoupdate_Times_on_Steps);
        menuUpdate->addAction(action_Autoupdate_Times_on_TimesSettings);
        menuSteps->addAction(action_Set_Step_Pos);
        menuSteps->addAction(action_Steps_Normal_Size);
        menuSteps->addSeparator();
        menuSteps->addAction(action_StepDefault_Autoupdate_Steps_on_Settings_changed);
        menuSteps->addAction(action_StepDefault_Skip_when_all_Steps_are_updated);
        menuSteps->addAction(action_StepDefault_Connect_Plane_Position);
        menuSteps->addAction(action_StepDefault_Connect_Steps_Zoom);
        menuSteps->addAction(action_StepDefault_Viewer_Smooth_Transformation);
        menuSteps->addAction(action_StepDefault_Viewer_Keep_Aspect_Ratio);
        menuTests->addAction(action_Test_Statistic_Function);
        menuTests->addAction(action_Test_Quatile_Access);
        menuTests->addAction(action_Test_D_VisDat);
        menuTests->addSeparator();
        menuTests->addAction(action_Stat_Tester);
        menuTests->addAction(actionTest_ND_Mat_load_and_display);
        menuTests->addSeparator();
        menuTests->addAction(action_Test_1D_EDT);
        menuTests->addAction(actionTest_DPF_Writer);
        menuTests->addSeparator();
        menuTests->addAction(actionTest_Running_Median);
        menuTests->addAction(actionTest_Maximum_Gil);
        menuTests->addSeparator();
        menuTests->addAction(actionTest_nD_for_loop);
        menuTests->addSeparator();
        menuTests->addAction(actionTest_range_selector);

        retranslateUi(D_MainWindow);
        QObject::connect(action_Show_Fullscreen, SIGNAL(triggered()), D_MainWindow, SLOT(showFullScreen()));
        QObject::connect(action_Show_Maximize, SIGNAL(triggered()), D_MainWindow, SLOT(showMaximized()));
        QObject::connect(action_Show_Minimize, SIGNAL(triggered()), D_MainWindow, SLOT(showMinimized()));
        QObject::connect(action_Show_Normal, SIGNAL(triggered()), D_MainWindow, SLOT(showNormal()));

        tabWidget_Overview->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(D_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *D_MainWindow)
    {
        D_MainWindow->setWindowTitle(QApplication::translate("D_MainWindow", "D_MainWindow", nullptr));
        action_Smooth_Transformation->setText(QApplication::translate("D_MainWindow", "Smooth Transformation", nullptr));
        action_Keep_Aspect_Ratio->setText(QApplication::translate("D_MainWindow", "Keep Aspect Ratio", nullptr));
        action_Show_Minimize->setText(QApplication::translate("D_MainWindow", "Minimize", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Minimize->setShortcut(QApplication::translate("D_MainWindow", "F9", nullptr));
#endif // QT_NO_SHORTCUT
        action_Show_Normal->setText(QApplication::translate("D_MainWindow", "Normal", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Normal->setShortcut(QApplication::translate("D_MainWindow", "F10", nullptr));
#endif // QT_NO_SHORTCUT
        action_Show_Maximize->setText(QApplication::translate("D_MainWindow", "Maximize", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Maximize->setShortcut(QApplication::translate("D_MainWindow", "F11", nullptr));
#endif // QT_NO_SHORTCUT
        action_Show_Fullscreen->setText(QApplication::translate("D_MainWindow", "Fullscreen", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Show_Fullscreen->setShortcut(QApplication::translate("D_MainWindow", "F12", nullptr));
#endif // QT_NO_SHORTCUT
        action_Update_All_Steps->setText(QApplication::translate("D_MainWindow", "Update All Steps", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Update_All_Steps->setShortcut(QApplication::translate("D_MainWindow", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        action_Update_Times->setText(QApplication::translate("D_MainWindow", "Update Times", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Update_Times->setShortcut(QApplication::translate("D_MainWindow", "F7", nullptr));
#endif // QT_NO_SHORTCUT
        action_Autoupdate_Times_on_Steps->setText(QApplication::translate("D_MainWindow", "Autoupdate Times on update all steps", nullptr));
        action_Autoupdate_Times_on_TimesSettings->setText(QApplication::translate("D_MainWindow", "Autoupdate Times on Times settings changed", nullptr));
        action_Set_Step_Pos->setText(QApplication::translate("D_MainWindow", "Set Position", nullptr));
        action_Test_Statistic_Function->setText(QApplication::translate("D_MainWindow", "Test Statistic Function", nullptr));
        action_Test_Quatile_Access->setText(QApplication::translate("D_MainWindow", "Test Quatile Access", nullptr));
#ifndef QT_NO_TOOLTIP
        action_Test_Quatile_Access->setToolTip(QApplication::translate("D_MainWindow", "Test Quatile Access", nullptr));
#endif // QT_NO_TOOLTIP
        action_Stat_Tester->setText(QApplication::translate("D_MainWindow", "Open Stat-Tester Window", nullptr));
        action_Steps_Normal_Size->setText(QApplication::translate("D_MainWindow", "Normal Size", nullptr));
        action_Test_D_VisDat->setText(QApplication::translate("D_MainWindow", "Test D_VisDat", nullptr));
        actionTest_ND_Mat_load_and_display->setText(QApplication::translate("D_MainWindow", "Test_ ND_Mat load and display", nullptr));
        action_Test_1D_EDT->setText(QApplication::translate("D_MainWindow", "Test 1D EDT", nullptr));
        action_StepDefault_Autoupdate_Steps_on_Settings_changed->setText(QApplication::translate("D_MainWindow", "Autoupdate Settings changed", nullptr));
        action_StepDefault_Viewer_Smooth_Transformation->setText(QApplication::translate("D_MainWindow", "Viewer Smooth Transformation", nullptr));
        action_StepDefault_Viewer_Keep_Aspect_Ratio->setText(QApplication::translate("D_MainWindow", "Viewer Keep Aspect Ratio", nullptr));
        action_StepDefault_Skip_when_all_Steps_are_updated->setText(QApplication::translate("D_MainWindow", "Skip when all Steps are updated", nullptr));
        action_StepDefault_Connect_Plane_Position->setText(QApplication::translate("D_MainWindow", "Connect Plane Position", nullptr));
        action_StepDefault_Connect_Steps_Zoom->setText(QApplication::translate("D_MainWindow", "Connect Steps Zoom", nullptr));
        actionTest_DPF_Writer->setText(QApplication::translate("D_MainWindow", "Test DPF Writer", nullptr));
        actionTest_Running_Median->setText(QApplication::translate("D_MainWindow", "Test Running Median", nullptr));
        actionTest_Maximum_Gil->setText(QApplication::translate("D_MainWindow", "Test Maximum Gil", nullptr));
        actionTest_nD_for_loop->setText(QApplication::translate("D_MainWindow", "Test nD for loop", nullptr));
        actionTest_range_selector->setText(QApplication::translate("D_MainWindow", "Test range selector", nullptr));
        groupBox_Plugins->setTitle(QApplication::translate("D_MainWindow", "Plugins", nullptr));
        pushButton_PluginLaunch->setText(QApplication::translate("D_MainWindow", "Launch", nullptr));
        groupBox_Analysis->setTitle(QApplication::translate("D_MainWindow", "Other", nullptr));
        pushButton_Analysis_Add->setText(QApplication::translate("D_MainWindow", "Add Analysis", nullptr));
        groupBox_References->setTitle(QApplication::translate("D_MainWindow", "References", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_Ref_OBV->setToolTip(QApplication::translate("D_MainWindow", "<html><head/><body><p>University of applied sciences Darmstadt<br/>Machine vision and photonics</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Ref_OBV->setText(QString());
        pushButton_Ref_Docs->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Ref_OpenCV->setToolTip(QApplication::translate("D_MainWindow", "<html><head/><body><p>OpenCV</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Ref_OpenCV->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Ref_Qt->setToolTip(QApplication::translate("D_MainWindow", "<html><head/><body><p>Qt-Creator</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Ref_Qt->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Ref_Biophysics->setToolTip(QApplication::translate("D_MainWindow", "<html><head/><body><p>GSI Helmholzfacility for heavy ion reserach<br/>Biophysics</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Ref_Biophysics->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Ref_Citation->setToolTip(QApplication::translate("D_MainWindow", "<html><head/><body><p>Citation</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Ref_Citation->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Ref_Contact->setToolTip(QApplication::translate("D_MainWindow", "<html><head/><body><p>Contact developer</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Ref_Contact->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Ref_Licence->setToolTip(QApplication::translate("D_MainWindow", "<html><head/><body><p>Licence</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Ref_Licence->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Ref_GSI->setToolTip(QApplication::translate("D_MainWindow", "<html><head/><body><p>GSI Helmholzfacility for heavy ion reserach</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Ref_GSI->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Ref_hda->setToolTip(QApplication::translate("D_MainWindow", "<html><head/><body><p>University of applied sciences Darmstadt</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Ref_hda->setText(QString());
        pushButton_Ref_Github->setText(QString());
        pushButton_Step_Add->setText(QApplication::translate("D_MainWindow", "Add Step (+)", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_Step_Add->setShortcut(QApplication::translate("D_MainWindow", "+", nullptr));
#endif // QT_NO_SHORTCUT
        label_Viewer->setText(QApplication::translate("D_MainWindow", "Show Step:", nullptr));
        pushButton_Steps_Save->setText(QApplication::translate("D_MainWindow", "Save Steps (Str+S)", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_Steps_Save->setShortcut(QApplication::translate("D_MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_Steps_Update->setText(QApplication::translate("D_MainWindow", "Update Steps (F5)", nullptr));
#ifndef QT_NO_TOOLTIP
        graphicsView_Viewer->setToolTip(QApplication::translate("D_MainWindow", "<html><head/><body><p>Initialization image by Bahar Djouiai, GSI Darmstadt</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        tabWidget_Overview->setTabText(tabWidget_Overview->indexOf(Images), QApplication::translate("D_MainWindow", "Images", nullptr));
        checkBox_Times_Processing->setText(QApplication::translate("D_MainWindow", "Processing", nullptr));
        pushButton_Update_Times->setText(QApplication::translate("D_MainWindow", "Update Times (F7)", nullptr));
        checkBox_Times_Conversion->setText(QApplication::translate("D_MainWindow", "Conversion", nullptr));
        checkBox_Times_Show->setText(QApplication::translate("D_MainWindow", "Show", nullptr));
        checkBox_Times_Hist->setText(QApplication::translate("D_MainWindow", "Histogram", nullptr));
        label_Times_Total->setText(QApplication::translate("D_MainWindow", "Total of displayed times: Xms", nullptr));
        tabWidget_Overview->setTabText(tabWidget_Overview->indexOf(Times), QApplication::translate("D_MainWindow", "Times", nullptr));
        menuViewer->setTitle(QApplication::translate("D_MainWindow", "Viewer", nullptr));
        menuWindow->setTitle(QApplication::translate("D_MainWindow", "Window", nullptr));
        menuUpdate->setTitle(QApplication::translate("D_MainWindow", "Update", nullptr));
        menuSteps->setTitle(QApplication::translate("D_MainWindow", "Steps", nullptr));
        menuTests->setTitle(QApplication::translate("D_MainWindow", "Tests", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MainWindow: public Ui_D_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAINWINDOW_H
