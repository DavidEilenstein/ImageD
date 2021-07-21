/********************************************************************************
** Form generated from reading UI file 'd_makro_curvefitting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_CURVEFITTING_H
#define UI_D_MAKRO_CURVEFITTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_CurveFitting
{
public:
    QAction *action_Live_Preview;
    QAction *action_Brealk_Loop;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_Fitting;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_Fit;
    QComboBox *comboBox_FitStat;
    QComboBox *comboBox_FitOptimization;
    QGroupBox *groupBox_Results;
    QGridLayout *gridLayout_7;
    QLabel *label_out_score;
    QLabel *label_6;
    QLabel *label_21;
    QLabel *label_ResCur_SuReSq;
    QLabel *label_ResCur_w2;
    QLabel *label_ResCur_d1;
    QFrame *line_6;
    QLabel *label_11;
    QLabel *label_5;
    QLabel *label_10;
    QFrame *line_2;
    QLabel *label_ResOpt_w2;
    QLabel *label_ResOpt_d2;
    QLabel *label_ResOpt_d1;
    QLabel *label_ResOpt_w1;
    QLabel *label_ResCur_w1;
    QFrame *line_5;
    QFrame *line_4;
    QLabel *label_20;
    QFrame *line_3;
    QLabel *label_ResOpt_SuReSq;
    QLabel *label_ResCur_d2;
    QProgressBar *progressBar_ParamLoop;
    QGroupBox *groupBox_Parameters;
    QGridLayout *gridLayout_4;
    QDoubleSpinBox *doubleSpinBox_min_w2;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_min_d2;
    QDoubleSpinBox *doubleSpinBox_step_w1;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_step_w2;
    QDoubleSpinBox *doubleSpinBox_min_d1;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_step_d1;
    QDoubleSpinBox *doubleSpinBox_max_w2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_max_d2;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_min_w1;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_max_d1;
    QDoubleSpinBox *doubleSpinBox_max_w1;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_step_d2;
    QGroupBox *groupBox_Data;
    QGridLayout *gridLayout_8;
    QPlainTextEdit *plainTextEdit_Data_Pb_295;
    QLabel *label_12;
    QLabel *label_13;
    QPlainTextEdit *plainTextEdit_Data_Bi;
    QPlainTextEdit *plainTextEdit_Data_Pb_352;
    QLabel *label_14;
    QLabel *label_16;
    QLabel *label_15;
    QLabel *label_17;
    QSpinBox *spinBox_Data_Weight_Pb_295;
    QSpinBox *spinBox_Data_Weight_Pb_352;
    QSpinBox *spinBox_Data_Weight_Bi;
    QTabWidget *tabWidget_Plot;
    QWidget *tabWidget_PlotPage1;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_Plot;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *doubleSpinBox_Test_w1;
    QDoubleSpinBox *doubleSpinBox_Test_w2;
    QDoubleSpinBox *doubleSpinBox_Test_d2;
    QDoubleSpinBox *doubleSpinBox_Test_d1;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QDoubleSpinBox *doubleSpinBox_range_t_max;
    QDoubleSpinBox *doubleSpinBox_range_a_max;
    QWidget *tab;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox_VisDispPlane;
    QGridLayout *gridLayout_10;
    QComboBox *comboBox_VisDispPlane_Plane;
    QSpinBox *spinBox_VisDispPlane_w1;
    QSpinBox *spinBox_VisDispPlane_d2;
    QSpinBox *spinBox_VisDispPlane_w2;
    QSpinBox *spinBox_VisDispPlane_d1;
    QGraphicsView *graphicsView_VisParamSpace;
    QMenuBar *menubar;
    QMenu *menuSettings;
    QMenu *menuStop;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_CurveFitting)
    {
        if (D_MAKRO_CurveFitting->objectName().isEmpty())
            D_MAKRO_CurveFitting->setObjectName(QString::fromUtf8("D_MAKRO_CurveFitting"));
        D_MAKRO_CurveFitting->resize(1152, 705);
        action_Live_Preview = new QAction(D_MAKRO_CurveFitting);
        action_Live_Preview->setObjectName(QString::fromUtf8("action_Live_Preview"));
        action_Live_Preview->setCheckable(true);
        action_Live_Preview->setChecked(true);
        action_Brealk_Loop = new QAction(D_MAKRO_CurveFitting);
        action_Brealk_Loop->setObjectName(QString::fromUtf8("action_Brealk_Loop"));
        action_Brealk_Loop->setCheckable(true);
        centralwidget = new QWidget(D_MAKRO_CurveFitting);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_Fitting = new QGroupBox(centralwidget);
        groupBox_Fitting->setObjectName(QString::fromUtf8("groupBox_Fitting"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_Fitting->sizePolicy().hasHeightForWidth());
        groupBox_Fitting->setSizePolicy(sizePolicy);
        groupBox_Fitting->setMinimumSize(QSize(430, 0));
        groupBox_Fitting->setMaximumSize(QSize(430, 16777215));
        gridLayout_6 = new QGridLayout(groupBox_Fitting);
        gridLayout_6->setSpacing(3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(6, 6, 6, 6);
        pushButton_Fit = new QPushButton(groupBox_Fitting);
        pushButton_Fit->setObjectName(QString::fromUtf8("pushButton_Fit"));

        gridLayout_6->addWidget(pushButton_Fit, 0, 2, 1, 1);

        comboBox_FitStat = new QComboBox(groupBox_Fitting);
        comboBox_FitStat->setObjectName(QString::fromUtf8("comboBox_FitStat"));

        gridLayout_6->addWidget(comboBox_FitStat, 0, 1, 1, 1);

        comboBox_FitOptimization = new QComboBox(groupBox_Fitting);
        comboBox_FitOptimization->setObjectName(QString::fromUtf8("comboBox_FitOptimization"));

        gridLayout_6->addWidget(comboBox_FitOptimization, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_Fitting, 2, 0, 1, 1);

        groupBox_Results = new QGroupBox(centralwidget);
        groupBox_Results->setObjectName(QString::fromUtf8("groupBox_Results"));
        sizePolicy.setHeightForWidth(groupBox_Results->sizePolicy().hasHeightForWidth());
        groupBox_Results->setSizePolicy(sizePolicy);
        groupBox_Results->setMinimumSize(QSize(430, 0));
        groupBox_Results->setMaximumSize(QSize(430, 16777215));
        gridLayout_7 = new QGridLayout(groupBox_Results);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_out_score = new QLabel(groupBox_Results);
        label_out_score->setObjectName(QString::fromUtf8("label_out_score"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_out_score->sizePolicy().hasHeightForWidth());
        label_out_score->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(label_out_score, 9, 0, 1, 1);

        label_6 = new QLabel(groupBox_Results);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(label_6, 6, 0, 1, 1);

        label_21 = new QLabel(groupBox_Results);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_7->addWidget(label_21, 1, 3, 1, 1);

        label_ResCur_SuReSq = new QLabel(groupBox_Results);
        label_ResCur_SuReSq->setObjectName(QString::fromUtf8("label_ResCur_SuReSq"));

        gridLayout_7->addWidget(label_ResCur_SuReSq, 9, 2, 1, 1);

        label_ResCur_w2 = new QLabel(groupBox_Results);
        label_ResCur_w2->setObjectName(QString::fromUtf8("label_ResCur_w2"));

        gridLayout_7->addWidget(label_ResCur_w2, 6, 2, 1, 1);

        label_ResCur_d1 = new QLabel(groupBox_Results);
        label_ResCur_d1->setObjectName(QString::fromUtf8("label_ResCur_d1"));

        gridLayout_7->addWidget(label_ResCur_d1, 3, 2, 1, 1);

        line_6 = new QFrame(groupBox_Results);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_6, 1, 1, 1, 1);

        label_11 = new QLabel(groupBox_Results);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(label_11, 5, 0, 1, 1);

        label_5 = new QLabel(groupBox_Results);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(label_5, 3, 0, 1, 1);

        label_10 = new QLabel(groupBox_Results);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(label_10, 4, 0, 1, 1);

        line_2 = new QFrame(groupBox_Results);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_2, 8, 0, 1, 4);

        label_ResOpt_w2 = new QLabel(groupBox_Results);
        label_ResOpt_w2->setObjectName(QString::fromUtf8("label_ResOpt_w2"));

        gridLayout_7->addWidget(label_ResOpt_w2, 6, 3, 1, 1);

        label_ResOpt_d2 = new QLabel(groupBox_Results);
        label_ResOpt_d2->setObjectName(QString::fromUtf8("label_ResOpt_d2"));

        gridLayout_7->addWidget(label_ResOpt_d2, 5, 3, 1, 1);

        label_ResOpt_d1 = new QLabel(groupBox_Results);
        label_ResOpt_d1->setObjectName(QString::fromUtf8("label_ResOpt_d1"));

        gridLayout_7->addWidget(label_ResOpt_d1, 3, 3, 1, 1);

        label_ResOpt_w1 = new QLabel(groupBox_Results);
        label_ResOpt_w1->setObjectName(QString::fromUtf8("label_ResOpt_w1"));

        gridLayout_7->addWidget(label_ResOpt_w1, 4, 3, 1, 1);

        label_ResCur_w1 = new QLabel(groupBox_Results);
        label_ResCur_w1->setObjectName(QString::fromUtf8("label_ResCur_w1"));

        gridLayout_7->addWidget(label_ResCur_w1, 4, 2, 1, 1);

        line_5 = new QFrame(groupBox_Results);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_5, 9, 1, 1, 1);

        line_4 = new QFrame(groupBox_Results);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_4, 3, 1, 4, 1);

        label_20 = new QLabel(groupBox_Results);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_7->addWidget(label_20, 1, 2, 1, 1);

        line_3 = new QFrame(groupBox_Results);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_3, 2, 0, 1, 4);

        label_ResOpt_SuReSq = new QLabel(groupBox_Results);
        label_ResOpt_SuReSq->setObjectName(QString::fromUtf8("label_ResOpt_SuReSq"));

        gridLayout_7->addWidget(label_ResOpt_SuReSq, 9, 3, 1, 1);

        label_ResCur_d2 = new QLabel(groupBox_Results);
        label_ResCur_d2->setObjectName(QString::fromUtf8("label_ResCur_d2"));

        gridLayout_7->addWidget(label_ResCur_d2, 5, 2, 1, 1);

        progressBar_ParamLoop = new QProgressBar(groupBox_Results);
        progressBar_ParamLoop->setObjectName(QString::fromUtf8("progressBar_ParamLoop"));
        progressBar_ParamLoop->setMaximumSize(QSize(16777215, 15));
        progressBar_ParamLoop->setStyleSheet(QString::fromUtf8("QProgressBar::chunk {\n"
"	background-color: #3add36;\n"
"	width = 1px;\n"
"}"));
        progressBar_ParamLoop->setMaximum(1000);
        progressBar_ParamLoop->setValue(0);
        progressBar_ParamLoop->setAlignment(Qt::AlignCenter);
        progressBar_ParamLoop->setInvertedAppearance(false);

        gridLayout_7->addWidget(progressBar_ParamLoop, 0, 0, 1, 4);


        gridLayout->addWidget(groupBox_Results, 3, 0, 1, 1);

        groupBox_Parameters = new QGroupBox(centralwidget);
        groupBox_Parameters->setObjectName(QString::fromUtf8("groupBox_Parameters"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_Parameters->sizePolicy().hasHeightForWidth());
        groupBox_Parameters->setSizePolicy(sizePolicy2);
        groupBox_Parameters->setMinimumSize(QSize(430, 0));
        groupBox_Parameters->setMaximumSize(QSize(430, 16777215));
        gridLayout_4 = new QGridLayout(groupBox_Parameters);
        gridLayout_4->setSpacing(3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(6, 6, 6, -1);
        doubleSpinBox_min_w2 = new QDoubleSpinBox(groupBox_Parameters);
        doubleSpinBox_min_w2->setObjectName(QString::fromUtf8("doubleSpinBox_min_w2"));
        doubleSpinBox_min_w2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_min_w2->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_min_w2->setDecimals(6);
        doubleSpinBox_min_w2->setMinimum(-1000000000000000044885712678075916785549312.000000000000000);
        doubleSpinBox_min_w2->setMaximum(1000000000000000078291540404596243842305360299886116864.000000000000000);
        doubleSpinBox_min_w2->setSingleStep(1000.000000000000000);
        doubleSpinBox_min_w2->setValue(13000.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_min_w2, 4, 1, 1, 1);

        label = new QLabel(groupBox_Parameters);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_4->addWidget(label, 1, 0, 1, 1);

        doubleSpinBox_min_d2 = new QDoubleSpinBox(groupBox_Parameters);
        doubleSpinBox_min_d2->setObjectName(QString::fromUtf8("doubleSpinBox_min_d2"));
        doubleSpinBox_min_d2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_min_d2->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_min_d2->setDecimals(6);
        doubleSpinBox_min_d2->setMinimum(-1000000000000000044885712678075916785549312.000000000000000);
        doubleSpinBox_min_d2->setMaximum(1000000000000000078291540404596243842305360299886116864.000000000000000);
        doubleSpinBox_min_d2->setValue(0.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_min_d2, 3, 1, 1, 1);

        doubleSpinBox_step_w1 = new QDoubleSpinBox(groupBox_Parameters);
        doubleSpinBox_step_w1->setObjectName(QString::fromUtf8("doubleSpinBox_step_w1"));
        doubleSpinBox_step_w1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_step_w1->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_step_w1->setDecimals(6);
        doubleSpinBox_step_w1->setMinimum(-1000000000000000044885712678075916785549312.000000000000000);
        doubleSpinBox_step_w1->setMaximum(1000000000000000078291540404596243842305360299886116864.000000000000000);
        doubleSpinBox_step_w1->setSingleStep(25000.000000000000000);
        doubleSpinBox_step_w1->setValue(250000.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_step_w1, 2, 3, 1, 1);

        label_3 = new QLabel(groupBox_Parameters);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 3, 0, 1, 1);

        doubleSpinBox_step_w2 = new QDoubleSpinBox(groupBox_Parameters);
        doubleSpinBox_step_w2->setObjectName(QString::fromUtf8("doubleSpinBox_step_w2"));
        doubleSpinBox_step_w2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_step_w2->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_step_w2->setDecimals(6);
        doubleSpinBox_step_w2->setMinimum(-1000000000000000044885712678075916785549312.000000000000000);
        doubleSpinBox_step_w2->setMaximum(1000000000000000078291540404596243842305360299886116864.000000000000000);
        doubleSpinBox_step_w2->setSingleStep(100.000000000000000);
        doubleSpinBox_step_w2->setValue(1000.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_step_w2, 4, 3, 1, 1);

        doubleSpinBox_min_d1 = new QDoubleSpinBox(groupBox_Parameters);
        doubleSpinBox_min_d1->setObjectName(QString::fromUtf8("doubleSpinBox_min_d1"));
        doubleSpinBox_min_d1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_min_d1->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_min_d1->setDecimals(6);
        doubleSpinBox_min_d1->setMinimum(-1000000000000000044885712678075916785549312.000000000000000);
        doubleSpinBox_min_d1->setMaximum(1000000000000000078291540404596243842305360299886116864.000000000000000);
        doubleSpinBox_min_d1->setSingleStep(0.010000000000000);
        doubleSpinBox_min_d1->setValue(0.160000000000000);

        gridLayout_4->addWidget(doubleSpinBox_min_d1, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_Parameters);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 0, 2, 1, 1);

        doubleSpinBox_step_d1 = new QDoubleSpinBox(groupBox_Parameters);
        doubleSpinBox_step_d1->setObjectName(QString::fromUtf8("doubleSpinBox_step_d1"));
        doubleSpinBox_step_d1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_step_d1->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_step_d1->setDecimals(6);
        doubleSpinBox_step_d1->setMinimum(-1000000000000000044885712678075916785549312.000000000000000);
        doubleSpinBox_step_d1->setMaximum(1000000000000000078291540404596243842305360299886116864.000000000000000);
        doubleSpinBox_step_d1->setSingleStep(0.001000000000000);
        doubleSpinBox_step_d1->setValue(0.010000000000000);

        gridLayout_4->addWidget(doubleSpinBox_step_d1, 1, 3, 1, 1);

        doubleSpinBox_max_w2 = new QDoubleSpinBox(groupBox_Parameters);
        doubleSpinBox_max_w2->setObjectName(QString::fromUtf8("doubleSpinBox_max_w2"));
        doubleSpinBox_max_w2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_max_w2->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_max_w2->setDecimals(6);
        doubleSpinBox_max_w2->setMinimum(-1000000000000000044885712678075916785549312.000000000000000);
        doubleSpinBox_max_w2->setMaximum(1000000000000000078291540404596243842305360299886116864.000000000000000);
        doubleSpinBox_max_w2->setSingleStep(1000.000000000000000);
        doubleSpinBox_max_w2->setValue(35000.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_max_w2, 4, 2, 1, 1);

        label_2 = new QLabel(groupBox_Parameters);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 2, 0, 1, 1);

        doubleSpinBox_max_d2 = new QDoubleSpinBox(groupBox_Parameters);
        doubleSpinBox_max_d2->setObjectName(QString::fromUtf8("doubleSpinBox_max_d2"));
        doubleSpinBox_max_d2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_max_d2->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_max_d2->setDecimals(6);
        doubleSpinBox_max_d2->setMinimum(-1000000000000000044885712678075916785549312.000000000000000);
        doubleSpinBox_max_d2->setMaximum(1000000000000000078291540404596243842305360299886116864.000000000000000);
        doubleSpinBox_max_d2->setValue(0.005000000000000);

        gridLayout_4->addWidget(doubleSpinBox_max_d2, 3, 2, 1, 1);

        label_4 = new QLabel(groupBox_Parameters);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 4, 0, 1, 1);

        doubleSpinBox_min_w1 = new QDoubleSpinBox(groupBox_Parameters);
        doubleSpinBox_min_w1->setObjectName(QString::fromUtf8("doubleSpinBox_min_w1"));
        doubleSpinBox_min_w1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_min_w1->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_min_w1->setDecimals(6);
        doubleSpinBox_min_w1->setMinimum(-1000000000000000044885712678075916785549312.000000000000000);
        doubleSpinBox_min_w1->setMaximum(1000000000000000078291540404596243842305360299886116864.000000000000000);
        doubleSpinBox_min_w1->setSingleStep(250000.000000000000000);
        doubleSpinBox_min_w1->setValue(2000000.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_min_w1, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox_Parameters);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 0, 3, 1, 1);

        doubleSpinBox_max_d1 = new QDoubleSpinBox(groupBox_Parameters);
        doubleSpinBox_max_d1->setObjectName(QString::fromUtf8("doubleSpinBox_max_d1"));
        doubleSpinBox_max_d1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_max_d1->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_max_d1->setDecimals(6);
        doubleSpinBox_max_d1->setMinimum(-1000000000000000044885712678075916785549312.000000000000000);
        doubleSpinBox_max_d1->setMaximum(1000000000000000078291540404596243842305360299886116864.000000000000000);
        doubleSpinBox_max_d1->setSingleStep(0.010000000000000);
        doubleSpinBox_max_d1->setValue(0.270000000000000);

        gridLayout_4->addWidget(doubleSpinBox_max_d1, 1, 2, 1, 1);

        doubleSpinBox_max_w1 = new QDoubleSpinBox(groupBox_Parameters);
        doubleSpinBox_max_w1->setObjectName(QString::fromUtf8("doubleSpinBox_max_w1"));
        doubleSpinBox_max_w1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_max_w1->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_max_w1->setDecimals(6);
        doubleSpinBox_max_w1->setMinimum(-1000000000000000044885712678075916785549312.000000000000000);
        doubleSpinBox_max_w1->setMaximum(1000000000000000078291540404596243842305360299886116864.000000000000000);
        doubleSpinBox_max_w1->setSingleStep(250000.000000000000000);
        doubleSpinBox_max_w1->setValue(3300000.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_max_w1, 2, 2, 1, 1);

        label_7 = new QLabel(groupBox_Parameters);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 0, 1, 1, 1);

        doubleSpinBox_step_d2 = new QDoubleSpinBox(groupBox_Parameters);
        doubleSpinBox_step_d2->setObjectName(QString::fromUtf8("doubleSpinBox_step_d2"));
        doubleSpinBox_step_d2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_step_d2->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_step_d2->setDecimals(6);
        doubleSpinBox_step_d2->setMinimum(-1000000000000000044885712678075916785549312.000000000000000);
        doubleSpinBox_step_d2->setMaximum(1000000000000000078291540404596243842305360299886116864.000000000000000);
        doubleSpinBox_step_d2->setSingleStep(0.000100000000000);
        doubleSpinBox_step_d2->setValue(0.001000000000000);

        gridLayout_4->addWidget(doubleSpinBox_step_d2, 3, 3, 1, 1);


        gridLayout->addWidget(groupBox_Parameters, 1, 0, 1, 1);

        groupBox_Data = new QGroupBox(centralwidget);
        groupBox_Data->setObjectName(QString::fromUtf8("groupBox_Data"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_Data->sizePolicy().hasHeightForWidth());
        groupBox_Data->setSizePolicy(sizePolicy3);
        groupBox_Data->setMinimumSize(QSize(430, 0));
        groupBox_Data->setMaximumSize(QSize(430, 16777215));
        gridLayout_8 = new QGridLayout(groupBox_Data);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        plainTextEdit_Data_Pb_295 = new QPlainTextEdit(groupBox_Data);
        plainTextEdit_Data_Pb_295->setObjectName(QString::fromUtf8("plainTextEdit_Data_Pb_295"));

        gridLayout_8->addWidget(plainTextEdit_Data_Pb_295, 1, 1, 1, 1);

        label_12 = new QLabel(groupBox_Data);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_8->addWidget(label_12, 0, 1, 1, 1);

        label_13 = new QLabel(groupBox_Data);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_8->addWidget(label_13, 0, 3, 1, 1);

        plainTextEdit_Data_Bi = new QPlainTextEdit(groupBox_Data);
        plainTextEdit_Data_Bi->setObjectName(QString::fromUtf8("plainTextEdit_Data_Bi"));

        gridLayout_8->addWidget(plainTextEdit_Data_Bi, 1, 3, 1, 1);

        plainTextEdit_Data_Pb_352 = new QPlainTextEdit(groupBox_Data);
        plainTextEdit_Data_Pb_352->setObjectName(QString::fromUtf8("plainTextEdit_Data_Pb_352"));

        gridLayout_8->addWidget(plainTextEdit_Data_Pb_352, 1, 2, 1, 1);

        label_14 = new QLabel(groupBox_Data);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_8->addWidget(label_14, 0, 2, 1, 1);

        label_16 = new QLabel(groupBox_Data);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_8->addWidget(label_16, 0, 0, 1, 1);

        label_15 = new QLabel(groupBox_Data);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_8->addWidget(label_15, 1, 0, 1, 1);

        label_17 = new QLabel(groupBox_Data);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_8->addWidget(label_17, 2, 0, 1, 1);

        spinBox_Data_Weight_Pb_295 = new QSpinBox(groupBox_Data);
        spinBox_Data_Weight_Pb_295->setObjectName(QString::fromUtf8("spinBox_Data_Weight_Pb_295"));
        spinBox_Data_Weight_Pb_295->setMinimum(0);
        spinBox_Data_Weight_Pb_295->setMaximum(100);
        spinBox_Data_Weight_Pb_295->setValue(1);

        gridLayout_8->addWidget(spinBox_Data_Weight_Pb_295, 2, 1, 1, 1);

        spinBox_Data_Weight_Pb_352 = new QSpinBox(groupBox_Data);
        spinBox_Data_Weight_Pb_352->setObjectName(QString::fromUtf8("spinBox_Data_Weight_Pb_352"));
        spinBox_Data_Weight_Pb_352->setMinimum(0);
        spinBox_Data_Weight_Pb_352->setMaximum(100);
        spinBox_Data_Weight_Pb_352->setValue(1);

        gridLayout_8->addWidget(spinBox_Data_Weight_Pb_352, 2, 2, 1, 1);

        spinBox_Data_Weight_Bi = new QSpinBox(groupBox_Data);
        spinBox_Data_Weight_Bi->setObjectName(QString::fromUtf8("spinBox_Data_Weight_Bi"));
        spinBox_Data_Weight_Bi->setMinimum(0);
        spinBox_Data_Weight_Bi->setMaximum(100);
        spinBox_Data_Weight_Bi->setValue(2);

        gridLayout_8->addWidget(spinBox_Data_Weight_Bi, 2, 3, 1, 1);


        gridLayout->addWidget(groupBox_Data, 0, 0, 1, 1);

        tabWidget_Plot = new QTabWidget(centralwidget);
        tabWidget_Plot->setObjectName(QString::fromUtf8("tabWidget_Plot"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tabWidget_Plot->sizePolicy().hasHeightForWidth());
        tabWidget_Plot->setSizePolicy(sizePolicy4);
        tabWidget_PlotPage1 = new QWidget();
        tabWidget_PlotPage1->setObjectName(QString::fromUtf8("tabWidget_PlotPage1"));
        gridLayout_3 = new QGridLayout(tabWidget_PlotPage1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_Plot = new QGridLayout();
        gridLayout_Plot->setObjectName(QString::fromUtf8("gridLayout_Plot"));

        gridLayout_3->addLayout(gridLayout_Plot, 0, 0, 1, 1);

        groupBox = new QGroupBox(tabWidget_PlotPage1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        doubleSpinBox_Test_w1 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_Test_w1->setObjectName(QString::fromUtf8("doubleSpinBox_Test_w1"));
        doubleSpinBox_Test_w1->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_Test_w1->setDecimals(6);
        doubleSpinBox_Test_w1->setMinimum(0.000000000000000);
        doubleSpinBox_Test_w1->setMaximum(999999999999999949387135297074018866963645011013410073083904.000000000000000);
        doubleSpinBox_Test_w1->setSingleStep(250000.000000000000000);
        doubleSpinBox_Test_w1->setValue(3000000.000000000000000);

        gridLayout_2->addWidget(doubleSpinBox_Test_w1, 0, 1, 1, 1);

        doubleSpinBox_Test_w2 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_Test_w2->setObjectName(QString::fromUtf8("doubleSpinBox_Test_w2"));
        doubleSpinBox_Test_w2->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_Test_w2->setDecimals(6);
        doubleSpinBox_Test_w2->setMinimum(0.000000000000000);
        doubleSpinBox_Test_w2->setMaximum(999999999999999949387135297074018866963645011013410073083904.000000000000000);
        doubleSpinBox_Test_w2->setSingleStep(1000.000000000000000);
        doubleSpinBox_Test_w2->setValue(32000.000000000000000);

        gridLayout_2->addWidget(doubleSpinBox_Test_w2, 0, 3, 1, 1);

        doubleSpinBox_Test_d2 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_Test_d2->setObjectName(QString::fromUtf8("doubleSpinBox_Test_d2"));
        doubleSpinBox_Test_d2->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_Test_d2->setDecimals(6);
        doubleSpinBox_Test_d2->setMinimum(0.000000000000000);
        doubleSpinBox_Test_d2->setMaximum(999999999999999949387135297074018866963645011013410073083904.000000000000000);
        doubleSpinBox_Test_d2->setSingleStep(0.001000000000000);
        doubleSpinBox_Test_d2->setValue(0.004000000000000);

        gridLayout_2->addWidget(doubleSpinBox_Test_d2, 0, 2, 1, 1);

        doubleSpinBox_Test_d1 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_Test_d1->setObjectName(QString::fromUtf8("doubleSpinBox_Test_d1"));
        doubleSpinBox_Test_d1->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_Test_d1->setDecimals(6);
        doubleSpinBox_Test_d1->setMinimum(0.000000000000000);
        doubleSpinBox_Test_d1->setMaximum(999999999999999949387135297074018866963645011013410073083904.000000000000000);
        doubleSpinBox_Test_d1->setSingleStep(0.010000000000000);
        doubleSpinBox_Test_d1->setValue(25.000000000000000);

        gridLayout_2->addWidget(doubleSpinBox_Test_d1, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(tabWidget_PlotPage1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        doubleSpinBox_range_t_max = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_range_t_max->setObjectName(QString::fromUtf8("doubleSpinBox_range_t_max"));
        doubleSpinBox_range_t_max->setMinimum(1.000000000000000);
        doubleSpinBox_range_t_max->setMaximum(100000000000000008821361405306422640701865984.000000000000000);
        doubleSpinBox_range_t_max->setSingleStep(60.000000000000000);
        doubleSpinBox_range_t_max->setValue(240.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_range_t_max, 0, 0, 1, 1);

        doubleSpinBox_range_a_max = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_range_a_max->setObjectName(QString::fromUtf8("doubleSpinBox_range_a_max"));
        doubleSpinBox_range_a_max->setMinimum(1.000000000000000);
        doubleSpinBox_range_a_max->setMaximum(9999999999999999464902769475481793196872414789632.000000000000000);
        doubleSpinBox_range_a_max->setSingleStep(200.000000000000000);
        doubleSpinBox_range_a_max->setValue(2000.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_range_a_max, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);

        tabWidget_Plot->addTab(tabWidget_PlotPage1, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_9 = new QGridLayout(tab);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        groupBox_VisDispPlane = new QGroupBox(tab);
        groupBox_VisDispPlane->setObjectName(QString::fromUtf8("groupBox_VisDispPlane"));
        gridLayout_10 = new QGridLayout(groupBox_VisDispPlane);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        comboBox_VisDispPlane_Plane = new QComboBox(groupBox_VisDispPlane);
        comboBox_VisDispPlane_Plane->setObjectName(QString::fromUtf8("comboBox_VisDispPlane_Plane"));

        gridLayout_10->addWidget(comboBox_VisDispPlane_Plane, 0, 0, 1, 1);

        spinBox_VisDispPlane_w1 = new QSpinBox(groupBox_VisDispPlane);
        spinBox_VisDispPlane_w1->setObjectName(QString::fromUtf8("spinBox_VisDispPlane_w1"));
        spinBox_VisDispPlane_w1->setEnabled(false);
        spinBox_VisDispPlane_w1->setMaximum(0);

        gridLayout_10->addWidget(spinBox_VisDispPlane_w1, 0, 2, 1, 1);

        spinBox_VisDispPlane_d2 = new QSpinBox(groupBox_VisDispPlane);
        spinBox_VisDispPlane_d2->setObjectName(QString::fromUtf8("spinBox_VisDispPlane_d2"));
        spinBox_VisDispPlane_d2->setMaximum(0);

        gridLayout_10->addWidget(spinBox_VisDispPlane_d2, 0, 3, 1, 1);

        spinBox_VisDispPlane_w2 = new QSpinBox(groupBox_VisDispPlane);
        spinBox_VisDispPlane_w2->setObjectName(QString::fromUtf8("spinBox_VisDispPlane_w2"));
        spinBox_VisDispPlane_w2->setMaximum(0);

        gridLayout_10->addWidget(spinBox_VisDispPlane_w2, 0, 4, 1, 1);

        spinBox_VisDispPlane_d1 = new QSpinBox(groupBox_VisDispPlane);
        spinBox_VisDispPlane_d1->setObjectName(QString::fromUtf8("spinBox_VisDispPlane_d1"));
        spinBox_VisDispPlane_d1->setEnabled(false);
        spinBox_VisDispPlane_d1->setMaximum(0);

        gridLayout_10->addWidget(spinBox_VisDispPlane_d1, 0, 1, 1, 1);


        gridLayout_9->addWidget(groupBox_VisDispPlane, 1, 0, 1, 1);

        graphicsView_VisParamSpace = new QGraphicsView(tab);
        graphicsView_VisParamSpace->setObjectName(QString::fromUtf8("graphicsView_VisParamSpace"));

        gridLayout_9->addWidget(graphicsView_VisParamSpace, 0, 0, 1, 1);

        tabWidget_Plot->addTab(tab, QString());

        gridLayout->addWidget(tabWidget_Plot, 0, 1, 4, 1);

        D_MAKRO_CurveFitting->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_CurveFitting);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1152, 21));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuStop = new QMenu(menubar);
        menuStop->setObjectName(QString::fromUtf8("menuStop"));
        D_MAKRO_CurveFitting->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_CurveFitting);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_CurveFitting->setStatusBar(statusbar);

        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuStop->menuAction());
        menuSettings->addAction(action_Live_Preview);
        menuStop->addAction(action_Brealk_Loop);

        retranslateUi(D_MAKRO_CurveFitting);

        tabWidget_Plot->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(D_MAKRO_CurveFitting);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_CurveFitting)
    {
        D_MAKRO_CurveFitting->setWindowTitle(QApplication::translate("D_MAKRO_CurveFitting", "MainWindow", nullptr));
        action_Live_Preview->setText(QApplication::translate("D_MAKRO_CurveFitting", "Live Preview", nullptr));
        action_Brealk_Loop->setText(QApplication::translate("D_MAKRO_CurveFitting", "Break Loop", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Brealk_Loop->setShortcut(QApplication::translate("D_MAKRO_CurveFitting", "Esc", nullptr));
#endif // QT_NO_SHORTCUT
        groupBox_Fitting->setTitle(QApplication::translate("D_MAKRO_CurveFitting", "Fitting", nullptr));
        pushButton_Fit->setText(QApplication::translate("D_MAKRO_CurveFitting", "Start Fitting", nullptr));
        groupBox_Results->setTitle(QApplication::translate("D_MAKRO_CurveFitting", "Results", nullptr));
        label_out_score->setText(QApplication::translate("D_MAKRO_CurveFitting", "weighted sum(residuals\302\262)", nullptr));
        label_6->setText(QApplication::translate("D_MAKRO_CurveFitting", "w2", nullptr));
        label_21->setText(QApplication::translate("D_MAKRO_CurveFitting", "Optimum", nullptr));
        label_ResCur_SuReSq->setText(QApplication::translate("D_MAKRO_CurveFitting", "-", nullptr));
        label_ResCur_w2->setText(QApplication::translate("D_MAKRO_CurveFitting", "-", nullptr));
        label_ResCur_d1->setText(QApplication::translate("D_MAKRO_CurveFitting", "-", nullptr));
        label_11->setText(QApplication::translate("D_MAKRO_CurveFitting", "d2", nullptr));
        label_5->setText(QApplication::translate("D_MAKRO_CurveFitting", "d1", nullptr));
        label_10->setText(QApplication::translate("D_MAKRO_CurveFitting", "w1", nullptr));
        label_ResOpt_w2->setText(QApplication::translate("D_MAKRO_CurveFitting", "-", nullptr));
        label_ResOpt_d2->setText(QApplication::translate("D_MAKRO_CurveFitting", "-", nullptr));
        label_ResOpt_d1->setText(QApplication::translate("D_MAKRO_CurveFitting", "-", nullptr));
        label_ResOpt_w1->setText(QApplication::translate("D_MAKRO_CurveFitting", "-", nullptr));
        label_ResCur_w1->setText(QApplication::translate("D_MAKRO_CurveFitting", "-", nullptr));
        label_20->setText(QApplication::translate("D_MAKRO_CurveFitting", "Current", nullptr));
        label_ResOpt_SuReSq->setText(QApplication::translate("D_MAKRO_CurveFitting", "-", nullptr));
        label_ResCur_d2->setText(QApplication::translate("D_MAKRO_CurveFitting", "-", nullptr));
        groupBox_Parameters->setTitle(QApplication::translate("D_MAKRO_CurveFitting", "Parameters", nullptr));
        label->setText(QApplication::translate("D_MAKRO_CurveFitting", "d1", nullptr));
        label_3->setText(QApplication::translate("D_MAKRO_CurveFitting", "d2", nullptr));
        label_8->setText(QApplication::translate("D_MAKRO_CurveFitting", "Max", nullptr));
        label_2->setText(QApplication::translate("D_MAKRO_CurveFitting", "w1", nullptr));
        label_4->setText(QApplication::translate("D_MAKRO_CurveFitting", "w2", nullptr));
        label_9->setText(QApplication::translate("D_MAKRO_CurveFitting", "Step", nullptr));
        label_7->setText(QApplication::translate("D_MAKRO_CurveFitting", "Min", nullptr));
        groupBox_Data->setTitle(QApplication::translate("D_MAKRO_CurveFitting", "Data", nullptr));
        plainTextEdit_Data_Pb_295->setPlainText(QApplication::translate("D_MAKRO_CurveFitting", "65, 1280.22801\n"
"73, 1350.1463\n"
"82, 966.26542\n"
"91, 1021.71785\n"
"100, 468.47933\n"
"111, 652.28497\n"
"126, 516.91315\n"
"144, 337.17939\n"
"200, 282.67349", nullptr));
        label_12->setText(QApplication::translate("D_MAKRO_CurveFitting", "Plumbum 295", nullptr));
        label_13->setText(QApplication::translate("D_MAKRO_CurveFitting", "Bismut", nullptr));
        plainTextEdit_Data_Bi->setPlainText(QApplication::translate("D_MAKRO_CurveFitting", "65, 814.27541\n"
"73, 906.65105\n"
"82, 963.70659\n"
"91, 950.12194\n"
"100, 892.52301\n"
"111, 767.42345\n"
"126, 529.29957\n"
"144, 440.42575\n"
"159, 321.24306\n"
"180, 291.1757\n"
"200, 258.21027\n"
"321, 104.97539", nullptr));
        plainTextEdit_Data_Pb_352->setPlainText(QApplication::translate("D_MAKRO_CurveFitting", "65, 1148.27168\n"
"73, 1237.67672\n"
"82, 1117.17428\n"
"91, 827.96841\n"
"100, 642.47239\n"
"111, 641.85044\n"
"126, 616.55788\n"
"144, 402.89798\n"
"159, 363.52866\n"
"180, 250.27192\n"
"200, 215.84709\n"
"321, 248.36461", nullptr));
        label_14->setText(QApplication::translate("D_MAKRO_CurveFitting", "Plumbum 352", nullptr));
        label_16->setText(QApplication::translate("D_MAKRO_CurveFitting", "Set", nullptr));
        label_15->setText(QApplication::translate("D_MAKRO_CurveFitting", "Data", nullptr));
        label_17->setText(QApplication::translate("D_MAKRO_CurveFitting", "Weight", nullptr));
        groupBox->setTitle(QApplication::translate("D_MAKRO_CurveFitting", "Test", nullptr));
        doubleSpinBox_Test_w1->setPrefix(QApplication::translate("D_MAKRO_CurveFitting", "w1 = ", nullptr));
        doubleSpinBox_Test_w2->setPrefix(QApplication::translate("D_MAKRO_CurveFitting", "w2 = ", nullptr));
        doubleSpinBox_Test_d2->setPrefix(QApplication::translate("D_MAKRO_CurveFitting", "d2 = ", nullptr));
        doubleSpinBox_Test_d1->setPrefix(QApplication::translate("D_MAKRO_CurveFitting", "d1 = ", nullptr));
        groupBox_2->setTitle(QApplication::translate("D_MAKRO_CurveFitting", "Plot Range", nullptr));
        doubleSpinBox_range_t_max->setPrefix(QApplication::translate("D_MAKRO_CurveFitting", "t_max = ", nullptr));
        doubleSpinBox_range_t_max->setSuffix(QString());
        doubleSpinBox_range_a_max->setPrefix(QApplication::translate("D_MAKRO_CurveFitting", "a_max = ", nullptr));
        doubleSpinBox_range_a_max->setSuffix(QString());
        tabWidget_Plot->setTabText(tabWidget_Plot->indexOf(tabWidget_PlotPage1), QApplication::translate("D_MAKRO_CurveFitting", "Plot", nullptr));
        groupBox_VisDispPlane->setTitle(QApplication::translate("D_MAKRO_CurveFitting", "Displayed Plane", nullptr));
        spinBox_VisDispPlane_w1->setSuffix(QApplication::translate("D_MAKRO_CurveFitting", " (0.0)", nullptr));
        spinBox_VisDispPlane_w1->setPrefix(QApplication::translate("D_MAKRO_CurveFitting", "w1: ", nullptr));
        spinBox_VisDispPlane_d2->setSuffix(QApplication::translate("D_MAKRO_CurveFitting", " (0.0)", nullptr));
        spinBox_VisDispPlane_d2->setPrefix(QApplication::translate("D_MAKRO_CurveFitting", "d2: ", nullptr));
        spinBox_VisDispPlane_w2->setSuffix(QApplication::translate("D_MAKRO_CurveFitting", " (0.0)", nullptr));
        spinBox_VisDispPlane_w2->setPrefix(QApplication::translate("D_MAKRO_CurveFitting", "w2: ", nullptr));
        spinBox_VisDispPlane_d1->setSuffix(QApplication::translate("D_MAKRO_CurveFitting", " (0.0)", nullptr));
        spinBox_VisDispPlane_d1->setPrefix(QApplication::translate("D_MAKRO_CurveFitting", "d1: ", nullptr));
        tabWidget_Plot->setTabText(tabWidget_Plot->indexOf(tab), QApplication::translate("D_MAKRO_CurveFitting", "Parameter Space Visualization", nullptr));
        menuSettings->setTitle(QApplication::translate("D_MAKRO_CurveFitting", "Settings", nullptr));
        menuStop->setTitle(QApplication::translate("D_MAKRO_CurveFitting", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_CurveFitting: public Ui_D_MAKRO_CurveFitting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_CURVEFITTING_H
