/********************************************************************************
** Form generated from reading UI file 'd_stat_tester.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_STAT_TESTER_H
#define UI_D_STAT_TESTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_stat_tester
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBox_In;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_View;
    QLabel *label_View_X_Min;
    QLabel *label_View_Y_Min;
    QLabel *label_View_X_Max;
    QLabel *label_View_Y_Max;
    QGraphicsView *graphicsView_Hist;
    QSpacerItem *horizontalSpacer_View;
    QGroupBox *groupBox_Out;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_Out;
    QGroupBox *groupBox_Out_Moments;
    QGridLayout *gridLayout_6;
    QLabel *label_Out_Value_Skewness_T;
    QLabel *label_Out_Value_Variance_T;
    QLabel *label_Out_Value_Mean_T;
    QLabel *label_Out_Title_Sample;
    QLabel *label_Out_Value_Skewness_S;
    QLabel *label_Out_Title_Mean;
    QLabel *label_Out_Title_Varienace;
    QLabel *label_Out_Title_Total;
    QLabel *label_Out_Value_Mean_S;
    QLabel *label_Out_Value_Variance_S;
    QLabel *label_Out_Value_Kurtosis_S;
    QLabel *label_Out_Value_Kurtosis_T;
    QLabel *label_Out_Value_StanDev_S;
    QLabel *label_Out_Value_StanDev_T;
    QLabel *label_Out_Title_VarCoeff;
    QLabel *label_Out_Value_VarCoeff_T;
    QLabel *label_Out_Value_VarCoeff_S;
    QLabel *label_Out_Title_Skewness;
    QLabel *label_Out_Title_Kurtosis;
    QLabel *label_Out_Title_StanDev;
    QGroupBox *groupBox_Out_Other;
    QGridLayout *gridLayout_5;
    QLabel *label_Out_Title_Count;
    QLabel *label_Out_Value_Sum;
    QLabel *label_Out_Value_Count;
    QLabel *label_Out_Title_Sum;
    QLabel *label_Out_Title_ADM;
    QLabel *label_Out_Value_ADM;
    QGroupBox *groupBox_Out_Sorted;
    QGridLayout *gridLayout_7;
    QLabel *label_Out_Title_90;
    QLabel *label_Out_Title_70;
    QLabel *label_Out_Value_Q_75;
    QLabel *label_Out_Title_85;
    QLabel *label_Out_Title_75;
    QLabel *label_Out_Title_65;
    QLabel *label_Out_Title_100;
    QLabel *label_Out_Title_00;
    QLabel *label_Out_Title_80;
    QLabel *label_Out_Title_Quantiles;
    QLabel *label_Out_Title_25;
    QLabel *label_Out_Title_20;
    QLabel *label_Out_Title_Distnace;
    QLabel *label_Out_Title_45;
    QLabel *label_Out_Title_40;
    QLabel *label_Out_Title_30;
    QLabel *label_Out_Title_50;
    QLabel *label_Out_Title_05;
    QLabel *label_Out_Title_10;
    QLabel *label_Out_Title_15;
    QLabel *label_Out_Title_60;
    QLabel *label_Out_Title_95;
    QLabel *label_Out_Title_35;
    QLabel *label_Out_Title_55;
    QLabel *label_Out_Value_Q_15;
    QLabel *label_Out_Value_Q_60;
    QLabel *label_Out_Value_Q_25;
    QLabel *label_Out_Value_Q_40;
    QLabel *label_Out_Value_Q_30;
    QLabel *label_Out_Value_Q_05;
    QLabel *label_Out_Value_Q_00;
    QLabel *label_Out_Value_Q_35;
    QLabel *label_Out_Value_Q_90;
    QLabel *label_Out_Value_Q_65;
    QLabel *label_Out_Value_Q_10;
    QLabel *label_Out_Value_Q_95;
    QLabel *label_Out_Value_Q_50;
    QLabel *label_Out_Value_Q_70;
    QLabel *label_Out_Value_Q_45;
    QLabel *label_Out_Value_Q_55;
    QLabel *label_Out_Value_Q_20;
    QLabel *label_Out_Value_Q_80;
    QLabel *label_Out_Value_D_20;
    QLabel *label_Out_Value_D_40;
    QLabel *label_Out_Value_D_60;
    QLabel *label_Out_Value_D_80;
    QLabel *label_Out_Value_D_100;
    QLabel *label_Out_Value_Q_100;
    QLabel *label_Out_Value_D_90;
    QLabel *label_Out_Value_D_30;
    QLabel *label_Out_Value_D_10;
    QLabel *label_Out_Value_D_50;
    QLabel *label_Out_Value_D_70;
    QLabel *label_Out_Value_Q_85;
    QGroupBox *groupBox_Init;
    QGridLayout *gridLayout_4;
    QFrame *line_Init_2;
    QLabel *label_Init_X_Range_2;
    QSpinBox *spinBox_Init_X_Max;
    QFrame *line_Init_1;
    QLabel *label_Init_X_Range_1;
    QSpinBox *spinBox_Init_X_Min;
    QSpinBox *spinBox_Init_Y_Max;
    QSpacerItem *horizontalSpacer_Init;
    QLabel *label_Init_Y_Max;
    QPushButton *pushButton_Init_Hist;
    QWidget *tab_2;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_11;
    QLabel *label;
    QPushButton *pushButton_DistributionUniform;
    QPlainTextEdit *plainTextEdit_Input;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_10;
    QTableWidget *tableWidget_Output;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_stat_tester)
    {
        if (D_stat_tester->objectName().isEmpty())
            D_stat_tester->setObjectName(QString::fromUtf8("D_stat_tester"));
        D_stat_tester->resize(993, 741);
        centralwidget = new QWidget(D_stat_tester);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_8 = new QGridLayout(tab);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        groupBox_In = new QGroupBox(tab);
        groupBox_In->setObjectName(QString::fromUtf8("groupBox_In"));
        gridLayout_2 = new QGridLayout(groupBox_In);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_View = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_View, 1, 0, 1, 1);

        label_View_X_Min = new QLabel(groupBox_In);
        label_View_X_Min->setObjectName(QString::fromUtf8("label_View_X_Min"));

        gridLayout_2->addWidget(label_View_X_Min, 3, 1, 1, 1);

        label_View_Y_Min = new QLabel(groupBox_In);
        label_View_Y_Min->setObjectName(QString::fromUtf8("label_View_Y_Min"));

        gridLayout_2->addWidget(label_View_Y_Min, 2, 0, 1, 1);

        label_View_X_Max = new QLabel(groupBox_In);
        label_View_X_Max->setObjectName(QString::fromUtf8("label_View_X_Max"));

        gridLayout_2->addWidget(label_View_X_Max, 3, 3, 1, 1);

        label_View_Y_Max = new QLabel(groupBox_In);
        label_View_Y_Max->setObjectName(QString::fromUtf8("label_View_Y_Max"));

        gridLayout_2->addWidget(label_View_Y_Max, 0, 0, 1, 1);

        graphicsView_Hist = new QGraphicsView(groupBox_In);
        graphicsView_Hist->setObjectName(QString::fromUtf8("graphicsView_Hist"));

        gridLayout_2->addWidget(graphicsView_Hist, 0, 1, 3, 3);

        horizontalSpacer_View = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_View, 3, 2, 1, 1);


        gridLayout_8->addWidget(groupBox_In, 0, 0, 1, 1);

        groupBox_Out = new QGroupBox(tab);
        groupBox_Out->setObjectName(QString::fromUtf8("groupBox_Out"));
        groupBox_Out->setMinimumSize(QSize(300, 0));
        groupBox_Out->setMaximumSize(QSize(400, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_Out);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer_Out = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_Out, 16, 2, 1, 1);

        groupBox_Out_Moments = new QGroupBox(groupBox_Out);
        groupBox_Out_Moments->setObjectName(QString::fromUtf8("groupBox_Out_Moments"));
        groupBox_Out_Moments->setFlat(true);
        gridLayout_6 = new QGridLayout(groupBox_Out_Moments);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setVerticalSpacing(4);
        label_Out_Value_Skewness_T = new QLabel(groupBox_Out_Moments);
        label_Out_Value_Skewness_T->setObjectName(QString::fromUtf8("label_Out_Value_Skewness_T"));

        gridLayout_6->addWidget(label_Out_Value_Skewness_T, 3, 2, 1, 1);

        label_Out_Value_Variance_T = new QLabel(groupBox_Out_Moments);
        label_Out_Value_Variance_T->setObjectName(QString::fromUtf8("label_Out_Value_Variance_T"));

        gridLayout_6->addWidget(label_Out_Value_Variance_T, 2, 2, 1, 1);

        label_Out_Value_Mean_T = new QLabel(groupBox_Out_Moments);
        label_Out_Value_Mean_T->setObjectName(QString::fromUtf8("label_Out_Value_Mean_T"));

        gridLayout_6->addWidget(label_Out_Value_Mean_T, 1, 2, 1, 1);

        label_Out_Title_Sample = new QLabel(groupBox_Out_Moments);
        label_Out_Title_Sample->setObjectName(QString::fromUtf8("label_Out_Title_Sample"));

        gridLayout_6->addWidget(label_Out_Title_Sample, 0, 1, 1, 1);

        label_Out_Value_Skewness_S = new QLabel(groupBox_Out_Moments);
        label_Out_Value_Skewness_S->setObjectName(QString::fromUtf8("label_Out_Value_Skewness_S"));

        gridLayout_6->addWidget(label_Out_Value_Skewness_S, 3, 1, 1, 1);

        label_Out_Title_Mean = new QLabel(groupBox_Out_Moments);
        label_Out_Title_Mean->setObjectName(QString::fromUtf8("label_Out_Title_Mean"));
        label_Out_Title_Mean->setMaximumSize(QSize(75, 16777215));

        gridLayout_6->addWidget(label_Out_Title_Mean, 1, 0, 1, 1);

        label_Out_Title_Varienace = new QLabel(groupBox_Out_Moments);
        label_Out_Title_Varienace->setObjectName(QString::fromUtf8("label_Out_Title_Varienace"));
        label_Out_Title_Varienace->setMaximumSize(QSize(75, 16777215));

        gridLayout_6->addWidget(label_Out_Title_Varienace, 2, 0, 1, 1);

        label_Out_Title_Total = new QLabel(groupBox_Out_Moments);
        label_Out_Title_Total->setObjectName(QString::fromUtf8("label_Out_Title_Total"));

        gridLayout_6->addWidget(label_Out_Title_Total, 0, 2, 1, 1);

        label_Out_Value_Mean_S = new QLabel(groupBox_Out_Moments);
        label_Out_Value_Mean_S->setObjectName(QString::fromUtf8("label_Out_Value_Mean_S"));

        gridLayout_6->addWidget(label_Out_Value_Mean_S, 1, 1, 1, 1);

        label_Out_Value_Variance_S = new QLabel(groupBox_Out_Moments);
        label_Out_Value_Variance_S->setObjectName(QString::fromUtf8("label_Out_Value_Variance_S"));

        gridLayout_6->addWidget(label_Out_Value_Variance_S, 2, 1, 1, 1);

        label_Out_Value_Kurtosis_S = new QLabel(groupBox_Out_Moments);
        label_Out_Value_Kurtosis_S->setObjectName(QString::fromUtf8("label_Out_Value_Kurtosis_S"));

        gridLayout_6->addWidget(label_Out_Value_Kurtosis_S, 4, 1, 1, 1);

        label_Out_Value_Kurtosis_T = new QLabel(groupBox_Out_Moments);
        label_Out_Value_Kurtosis_T->setObjectName(QString::fromUtf8("label_Out_Value_Kurtosis_T"));

        gridLayout_6->addWidget(label_Out_Value_Kurtosis_T, 4, 2, 1, 1);

        label_Out_Value_StanDev_S = new QLabel(groupBox_Out_Moments);
        label_Out_Value_StanDev_S->setObjectName(QString::fromUtf8("label_Out_Value_StanDev_S"));

        gridLayout_6->addWidget(label_Out_Value_StanDev_S, 5, 1, 1, 1);

        label_Out_Value_StanDev_T = new QLabel(groupBox_Out_Moments);
        label_Out_Value_StanDev_T->setObjectName(QString::fromUtf8("label_Out_Value_StanDev_T"));

        gridLayout_6->addWidget(label_Out_Value_StanDev_T, 5, 2, 1, 1);

        label_Out_Title_VarCoeff = new QLabel(groupBox_Out_Moments);
        label_Out_Title_VarCoeff->setObjectName(QString::fromUtf8("label_Out_Title_VarCoeff"));
        label_Out_Title_VarCoeff->setMaximumSize(QSize(75, 16777215));

        gridLayout_6->addWidget(label_Out_Title_VarCoeff, 7, 0, 1, 1);

        label_Out_Value_VarCoeff_T = new QLabel(groupBox_Out_Moments);
        label_Out_Value_VarCoeff_T->setObjectName(QString::fromUtf8("label_Out_Value_VarCoeff_T"));

        gridLayout_6->addWidget(label_Out_Value_VarCoeff_T, 7, 2, 1, 1);

        label_Out_Value_VarCoeff_S = new QLabel(groupBox_Out_Moments);
        label_Out_Value_VarCoeff_S->setObjectName(QString::fromUtf8("label_Out_Value_VarCoeff_S"));

        gridLayout_6->addWidget(label_Out_Value_VarCoeff_S, 7, 1, 1, 1);

        label_Out_Title_Skewness = new QLabel(groupBox_Out_Moments);
        label_Out_Title_Skewness->setObjectName(QString::fromUtf8("label_Out_Title_Skewness"));
        label_Out_Title_Skewness->setMaximumSize(QSize(75, 16777215));

        gridLayout_6->addWidget(label_Out_Title_Skewness, 3, 0, 1, 1);

        label_Out_Title_Kurtosis = new QLabel(groupBox_Out_Moments);
        label_Out_Title_Kurtosis->setObjectName(QString::fromUtf8("label_Out_Title_Kurtosis"));
        label_Out_Title_Kurtosis->setMaximumSize(QSize(75, 16777215));

        gridLayout_6->addWidget(label_Out_Title_Kurtosis, 4, 0, 1, 1);

        label_Out_Title_StanDev = new QLabel(groupBox_Out_Moments);
        label_Out_Title_StanDev->setObjectName(QString::fromUtf8("label_Out_Title_StanDev"));
        label_Out_Title_StanDev->setMaximumSize(QSize(75, 16777215));

        gridLayout_6->addWidget(label_Out_Title_StanDev, 5, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_Out_Moments, 13, 2, 1, 1);

        groupBox_Out_Other = new QGroupBox(groupBox_Out);
        groupBox_Out_Other->setObjectName(QString::fromUtf8("groupBox_Out_Other"));
        groupBox_Out_Other->setFlat(true);
        gridLayout_5 = new QGridLayout(groupBox_Out_Other);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setVerticalSpacing(4);
        label_Out_Title_Count = new QLabel(groupBox_Out_Other);
        label_Out_Title_Count->setObjectName(QString::fromUtf8("label_Out_Title_Count"));
        label_Out_Title_Count->setMaximumSize(QSize(75, 16777215));

        gridLayout_5->addWidget(label_Out_Title_Count, 0, 0, 1, 1);

        label_Out_Value_Sum = new QLabel(groupBox_Out_Other);
        label_Out_Value_Sum->setObjectName(QString::fromUtf8("label_Out_Value_Sum"));

        gridLayout_5->addWidget(label_Out_Value_Sum, 1, 1, 1, 1);

        label_Out_Value_Count = new QLabel(groupBox_Out_Other);
        label_Out_Value_Count->setObjectName(QString::fromUtf8("label_Out_Value_Count"));

        gridLayout_5->addWidget(label_Out_Value_Count, 0, 1, 1, 1);

        label_Out_Title_Sum = new QLabel(groupBox_Out_Other);
        label_Out_Title_Sum->setObjectName(QString::fromUtf8("label_Out_Title_Sum"));
        label_Out_Title_Sum->setMaximumSize(QSize(75, 16777215));

        gridLayout_5->addWidget(label_Out_Title_Sum, 1, 0, 1, 1);

        label_Out_Title_ADM = new QLabel(groupBox_Out_Other);
        label_Out_Title_ADM->setObjectName(QString::fromUtf8("label_Out_Title_ADM"));
        label_Out_Title_ADM->setMaximumSize(QSize(75, 16777215));

        gridLayout_5->addWidget(label_Out_Title_ADM, 2, 0, 1, 1);

        label_Out_Value_ADM = new QLabel(groupBox_Out_Other);
        label_Out_Value_ADM->setObjectName(QString::fromUtf8("label_Out_Value_ADM"));

        gridLayout_5->addWidget(label_Out_Value_ADM, 2, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_Out_Other, 15, 2, 1, 1);

        groupBox_Out_Sorted = new QGroupBox(groupBox_Out);
        groupBox_Out_Sorted->setObjectName(QString::fromUtf8("groupBox_Out_Sorted"));
        groupBox_Out_Sorted->setFlat(true);
        gridLayout_7 = new QGridLayout(groupBox_Out_Sorted);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setVerticalSpacing(4);
        label_Out_Title_90 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_90->setObjectName(QString::fromUtf8("label_Out_Title_90"));
        label_Out_Title_90->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_90, 19, 0, 1, 1);

        label_Out_Title_70 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_70->setObjectName(QString::fromUtf8("label_Out_Title_70"));
        label_Out_Title_70->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_70, 15, 0, 1, 1);

        label_Out_Value_Q_75 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_75->setObjectName(QString::fromUtf8("label_Out_Value_Q_75"));

        gridLayout_7->addWidget(label_Out_Value_Q_75, 16, 1, 1, 1);

        label_Out_Title_85 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_85->setObjectName(QString::fromUtf8("label_Out_Title_85"));
        label_Out_Title_85->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_85, 18, 0, 1, 1);

        label_Out_Title_75 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_75->setObjectName(QString::fromUtf8("label_Out_Title_75"));
        label_Out_Title_75->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_75, 16, 0, 1, 1);

        label_Out_Title_65 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_65->setObjectName(QString::fromUtf8("label_Out_Title_65"));
        label_Out_Title_65->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_65, 14, 0, 1, 1);

        label_Out_Title_100 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_100->setObjectName(QString::fromUtf8("label_Out_Title_100"));
        label_Out_Title_100->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_100, 21, 0, 1, 1);

        label_Out_Title_00 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_00->setObjectName(QString::fromUtf8("label_Out_Title_00"));
        label_Out_Title_00->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_00, 1, 0, 1, 1);

        label_Out_Title_80 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_80->setObjectName(QString::fromUtf8("label_Out_Title_80"));
        label_Out_Title_80->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_80, 17, 0, 1, 1);

        label_Out_Title_Quantiles = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_Quantiles->setObjectName(QString::fromUtf8("label_Out_Title_Quantiles"));

        gridLayout_7->addWidget(label_Out_Title_Quantiles, 0, 1, 1, 1);

        label_Out_Title_25 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_25->setObjectName(QString::fromUtf8("label_Out_Title_25"));
        label_Out_Title_25->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_25, 6, 0, 1, 1);

        label_Out_Title_20 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_20->setObjectName(QString::fromUtf8("label_Out_Title_20"));
        label_Out_Title_20->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_20, 5, 0, 1, 1);

        label_Out_Title_Distnace = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_Distnace->setObjectName(QString::fromUtf8("label_Out_Title_Distnace"));

        gridLayout_7->addWidget(label_Out_Title_Distnace, 0, 2, 1, 1);

        label_Out_Title_45 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_45->setObjectName(QString::fromUtf8("label_Out_Title_45"));
        label_Out_Title_45->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_45, 10, 0, 1, 1);

        label_Out_Title_40 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_40->setObjectName(QString::fromUtf8("label_Out_Title_40"));
        label_Out_Title_40->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_40, 9, 0, 1, 1);

        label_Out_Title_30 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_30->setObjectName(QString::fromUtf8("label_Out_Title_30"));
        label_Out_Title_30->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_30, 7, 0, 1, 1);

        label_Out_Title_50 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_50->setObjectName(QString::fromUtf8("label_Out_Title_50"));
        label_Out_Title_50->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_50, 11, 0, 1, 1);

        label_Out_Title_05 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_05->setObjectName(QString::fromUtf8("label_Out_Title_05"));
        label_Out_Title_05->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_05, 2, 0, 1, 1);

        label_Out_Title_10 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_10->setObjectName(QString::fromUtf8("label_Out_Title_10"));
        label_Out_Title_10->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_10, 3, 0, 1, 1);

        label_Out_Title_15 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_15->setObjectName(QString::fromUtf8("label_Out_Title_15"));
        label_Out_Title_15->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_15, 4, 0, 1, 1);

        label_Out_Title_60 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_60->setObjectName(QString::fromUtf8("label_Out_Title_60"));
        label_Out_Title_60->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_60, 13, 0, 1, 1);

        label_Out_Title_95 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_95->setObjectName(QString::fromUtf8("label_Out_Title_95"));
        label_Out_Title_95->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_95, 20, 0, 1, 1);

        label_Out_Title_35 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_35->setObjectName(QString::fromUtf8("label_Out_Title_35"));
        label_Out_Title_35->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_35, 8, 0, 1, 1);

        label_Out_Title_55 = new QLabel(groupBox_Out_Sorted);
        label_Out_Title_55->setObjectName(QString::fromUtf8("label_Out_Title_55"));
        label_Out_Title_55->setMaximumSize(QSize(75, 16777215));

        gridLayout_7->addWidget(label_Out_Title_55, 12, 0, 1, 1);

        label_Out_Value_Q_15 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_15->setObjectName(QString::fromUtf8("label_Out_Value_Q_15"));

        gridLayout_7->addWidget(label_Out_Value_Q_15, 4, 1, 1, 1);

        label_Out_Value_Q_60 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_60->setObjectName(QString::fromUtf8("label_Out_Value_Q_60"));

        gridLayout_7->addWidget(label_Out_Value_Q_60, 13, 1, 1, 1);

        label_Out_Value_Q_25 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_25->setObjectName(QString::fromUtf8("label_Out_Value_Q_25"));

        gridLayout_7->addWidget(label_Out_Value_Q_25, 6, 1, 1, 1);

        label_Out_Value_Q_40 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_40->setObjectName(QString::fromUtf8("label_Out_Value_Q_40"));

        gridLayout_7->addWidget(label_Out_Value_Q_40, 9, 1, 1, 1);

        label_Out_Value_Q_30 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_30->setObjectName(QString::fromUtf8("label_Out_Value_Q_30"));

        gridLayout_7->addWidget(label_Out_Value_Q_30, 7, 1, 1, 1);

        label_Out_Value_Q_05 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_05->setObjectName(QString::fromUtf8("label_Out_Value_Q_05"));

        gridLayout_7->addWidget(label_Out_Value_Q_05, 2, 1, 1, 1);

        label_Out_Value_Q_00 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_00->setObjectName(QString::fromUtf8("label_Out_Value_Q_00"));

        gridLayout_7->addWidget(label_Out_Value_Q_00, 1, 1, 1, 1);

        label_Out_Value_Q_35 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_35->setObjectName(QString::fromUtf8("label_Out_Value_Q_35"));

        gridLayout_7->addWidget(label_Out_Value_Q_35, 8, 1, 1, 1);

        label_Out_Value_Q_90 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_90->setObjectName(QString::fromUtf8("label_Out_Value_Q_90"));

        gridLayout_7->addWidget(label_Out_Value_Q_90, 19, 1, 1, 1);

        label_Out_Value_Q_65 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_65->setObjectName(QString::fromUtf8("label_Out_Value_Q_65"));

        gridLayout_7->addWidget(label_Out_Value_Q_65, 14, 1, 1, 1);

        label_Out_Value_Q_10 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_10->setObjectName(QString::fromUtf8("label_Out_Value_Q_10"));

        gridLayout_7->addWidget(label_Out_Value_Q_10, 3, 1, 1, 1);

        label_Out_Value_Q_95 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_95->setObjectName(QString::fromUtf8("label_Out_Value_Q_95"));

        gridLayout_7->addWidget(label_Out_Value_Q_95, 20, 1, 1, 1);

        label_Out_Value_Q_50 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_50->setObjectName(QString::fromUtf8("label_Out_Value_Q_50"));

        gridLayout_7->addWidget(label_Out_Value_Q_50, 11, 1, 1, 1);

        label_Out_Value_Q_70 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_70->setObjectName(QString::fromUtf8("label_Out_Value_Q_70"));

        gridLayout_7->addWidget(label_Out_Value_Q_70, 15, 1, 1, 1);

        label_Out_Value_Q_45 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_45->setObjectName(QString::fromUtf8("label_Out_Value_Q_45"));

        gridLayout_7->addWidget(label_Out_Value_Q_45, 10, 1, 1, 1);

        label_Out_Value_Q_55 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_55->setObjectName(QString::fromUtf8("label_Out_Value_Q_55"));

        gridLayout_7->addWidget(label_Out_Value_Q_55, 12, 1, 1, 1);

        label_Out_Value_Q_20 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_20->setObjectName(QString::fromUtf8("label_Out_Value_Q_20"));

        gridLayout_7->addWidget(label_Out_Value_Q_20, 5, 1, 1, 1);

        label_Out_Value_Q_80 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_80->setObjectName(QString::fromUtf8("label_Out_Value_Q_80"));

        gridLayout_7->addWidget(label_Out_Value_Q_80, 17, 1, 1, 1);

        label_Out_Value_D_20 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_D_20->setObjectName(QString::fromUtf8("label_Out_Value_D_20"));

        gridLayout_7->addWidget(label_Out_Value_D_20, 5, 2, 1, 1);

        label_Out_Value_D_40 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_D_40->setObjectName(QString::fromUtf8("label_Out_Value_D_40"));

        gridLayout_7->addWidget(label_Out_Value_D_40, 9, 2, 1, 1);

        label_Out_Value_D_60 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_D_60->setObjectName(QString::fromUtf8("label_Out_Value_D_60"));

        gridLayout_7->addWidget(label_Out_Value_D_60, 13, 2, 1, 1);

        label_Out_Value_D_80 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_D_80->setObjectName(QString::fromUtf8("label_Out_Value_D_80"));

        gridLayout_7->addWidget(label_Out_Value_D_80, 17, 2, 1, 1);

        label_Out_Value_D_100 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_D_100->setObjectName(QString::fromUtf8("label_Out_Value_D_100"));

        gridLayout_7->addWidget(label_Out_Value_D_100, 21, 2, 1, 1);

        label_Out_Value_Q_100 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_100->setObjectName(QString::fromUtf8("label_Out_Value_Q_100"));

        gridLayout_7->addWidget(label_Out_Value_Q_100, 21, 1, 1, 1);

        label_Out_Value_D_90 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_D_90->setObjectName(QString::fromUtf8("label_Out_Value_D_90"));

        gridLayout_7->addWidget(label_Out_Value_D_90, 19, 2, 1, 1);

        label_Out_Value_D_30 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_D_30->setObjectName(QString::fromUtf8("label_Out_Value_D_30"));

        gridLayout_7->addWidget(label_Out_Value_D_30, 7, 2, 1, 1);

        label_Out_Value_D_10 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_D_10->setObjectName(QString::fromUtf8("label_Out_Value_D_10"));

        gridLayout_7->addWidget(label_Out_Value_D_10, 3, 2, 1, 1);

        label_Out_Value_D_50 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_D_50->setObjectName(QString::fromUtf8("label_Out_Value_D_50"));

        gridLayout_7->addWidget(label_Out_Value_D_50, 11, 2, 1, 1);

        label_Out_Value_D_70 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_D_70->setObjectName(QString::fromUtf8("label_Out_Value_D_70"));

        gridLayout_7->addWidget(label_Out_Value_D_70, 15, 2, 1, 1);

        label_Out_Value_Q_85 = new QLabel(groupBox_Out_Sorted);
        label_Out_Value_Q_85->setObjectName(QString::fromUtf8("label_Out_Value_Q_85"));

        gridLayout_7->addWidget(label_Out_Value_Q_85, 18, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_Out_Sorted, 14, 2, 1, 1);


        gridLayout_8->addWidget(groupBox_Out, 0, 1, 2, 1);

        groupBox_Init = new QGroupBox(tab);
        groupBox_Init->setObjectName(QString::fromUtf8("groupBox_Init"));
        gridLayout_4 = new QGridLayout(groupBox_Init);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        line_Init_2 = new QFrame(groupBox_Init);
        line_Init_2->setObjectName(QString::fromUtf8("line_Init_2"));
        line_Init_2->setFrameShape(QFrame::VLine);
        line_Init_2->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_Init_2, 0, 7, 1, 1);

        label_Init_X_Range_2 = new QLabel(groupBox_Init);
        label_Init_X_Range_2->setObjectName(QString::fromUtf8("label_Init_X_Range_2"));

        gridLayout_4->addWidget(label_Init_X_Range_2, 0, 2, 1, 1);

        spinBox_Init_X_Max = new QSpinBox(groupBox_Init);
        spinBox_Init_X_Max->setObjectName(QString::fromUtf8("spinBox_Init_X_Max"));
        spinBox_Init_X_Max->setMinimum(-500);
        spinBox_Init_X_Max->setMaximum(500);
        spinBox_Init_X_Max->setValue(20);

        gridLayout_4->addWidget(spinBox_Init_X_Max, 0, 3, 1, 1);

        line_Init_1 = new QFrame(groupBox_Init);
        line_Init_1->setObjectName(QString::fromUtf8("line_Init_1"));
        line_Init_1->setFrameShape(QFrame::VLine);
        line_Init_1->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_Init_1, 0, 4, 1, 1);

        label_Init_X_Range_1 = new QLabel(groupBox_Init);
        label_Init_X_Range_1->setObjectName(QString::fromUtf8("label_Init_X_Range_1"));

        gridLayout_4->addWidget(label_Init_X_Range_1, 0, 0, 1, 1);

        spinBox_Init_X_Min = new QSpinBox(groupBox_Init);
        spinBox_Init_X_Min->setObjectName(QString::fromUtf8("spinBox_Init_X_Min"));
        spinBox_Init_X_Min->setMinimum(-500);
        spinBox_Init_X_Min->setMaximum(500);
        spinBox_Init_X_Min->setValue(-20);

        gridLayout_4->addWidget(spinBox_Init_X_Min, 0, 1, 1, 1);

        spinBox_Init_Y_Max = new QSpinBox(groupBox_Init);
        spinBox_Init_Y_Max->setObjectName(QString::fromUtf8("spinBox_Init_Y_Max"));
        spinBox_Init_Y_Max->setMinimum(1);
        spinBox_Init_Y_Max->setMaximum(500);
        spinBox_Init_Y_Max->setValue(20);

        gridLayout_4->addWidget(spinBox_Init_Y_Max, 0, 6, 1, 1);

        horizontalSpacer_Init = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_Init, 0, 9, 1, 1);

        label_Init_Y_Max = new QLabel(groupBox_Init);
        label_Init_Y_Max->setObjectName(QString::fromUtf8("label_Init_Y_Max"));

        gridLayout_4->addWidget(label_Init_Y_Max, 0, 5, 1, 1);

        pushButton_Init_Hist = new QPushButton(groupBox_Init);
        pushButton_Init_Hist->setObjectName(QString::fromUtf8("pushButton_Init_Hist"));

        gridLayout_4->addWidget(pushButton_Init_Hist, 0, 8, 1, 1);


        gridLayout_8->addWidget(groupBox_Init, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_9 = new QGridLayout(tab_2);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout_11 = new QGridLayout(groupBox);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_11->addWidget(label, 0, 0, 1, 1);

        pushButton_DistributionUniform = new QPushButton(groupBox);
        pushButton_DistributionUniform->setObjectName(QString::fromUtf8("pushButton_DistributionUniform"));

        gridLayout_11->addWidget(pushButton_DistributionUniform, 0, 1, 1, 1);

        plainTextEdit_Input = new QPlainTextEdit(groupBox);
        plainTextEdit_Input->setObjectName(QString::fromUtf8("plainTextEdit_Input"));

        gridLayout_11->addWidget(plainTextEdit_Input, 1, 0, 1, 2);


        gridLayout_9->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        gridLayout_10 = new QGridLayout(groupBox_2);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        tableWidget_Output = new QTableWidget(groupBox_2);
        tableWidget_Output->setObjectName(QString::fromUtf8("tableWidget_Output"));

        gridLayout_10->addWidget(tableWidget_Output, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_10->addWidget(label_2, 0, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_2, 0, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        D_stat_tester->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_stat_tester);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 993, 21));
        D_stat_tester->setMenuBar(menubar);
        statusbar = new QStatusBar(D_stat_tester);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_stat_tester->setStatusBar(statusbar);

        retranslateUi(D_stat_tester);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(D_stat_tester);
    } // setupUi

    void retranslateUi(QMainWindow *D_stat_tester)
    {
        D_stat_tester->setWindowTitle(QApplication::translate("D_stat_tester", "MainWindow", nullptr));
        groupBox_In->setTitle(QApplication::translate("D_stat_tester", "In: Histogram", nullptr));
        label_View_X_Min->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_View_Y_Min->setText(QApplication::translate("D_stat_tester", "0", nullptr));
        label_View_X_Max->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_View_Y_Max->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        groupBox_Out->setTitle(QApplication::translate("D_stat_tester", "Out: Statistics", nullptr));
        groupBox_Out_Moments->setTitle(QApplication::translate("D_stat_tester", "Moments", nullptr));
        label_Out_Value_Skewness_T->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Variance_T->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Mean_T->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Title_Sample->setText(QApplication::translate("D_stat_tester", "Sample", nullptr));
        label_Out_Value_Skewness_S->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Title_Mean->setText(QApplication::translate("D_stat_tester", "Mean", nullptr));
        label_Out_Title_Varienace->setText(QApplication::translate("D_stat_tester", "Variance", nullptr));
        label_Out_Title_Total->setText(QApplication::translate("D_stat_tester", "Total", nullptr));
        label_Out_Value_Mean_S->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Variance_S->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Kurtosis_S->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Kurtosis_T->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_StanDev_S->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_StanDev_T->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Title_VarCoeff->setText(QApplication::translate("D_stat_tester", "Var. Coeff.", nullptr));
        label_Out_Value_VarCoeff_T->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_VarCoeff_S->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Title_Skewness->setText(QApplication::translate("D_stat_tester", "Skewness", nullptr));
        label_Out_Title_Kurtosis->setText(QApplication::translate("D_stat_tester", "Kurtosis", nullptr));
        label_Out_Title_StanDev->setText(QApplication::translate("D_stat_tester", "Stan. Dev.", nullptr));
        groupBox_Out_Other->setTitle(QApplication::translate("D_stat_tester", "Other", nullptr));
        label_Out_Title_Count->setText(QApplication::translate("D_stat_tester", "Count", nullptr));
        label_Out_Value_Sum->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Count->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Title_Sum->setText(QApplication::translate("D_stat_tester", "Sum", nullptr));
        label_Out_Title_ADM->setText(QApplication::translate("D_stat_tester", "Abs. Dev. Med.", nullptr));
        label_Out_Value_ADM->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        groupBox_Out_Sorted->setTitle(QApplication::translate("D_stat_tester", "Sorted", nullptr));
        label_Out_Title_90->setText(QApplication::translate("D_stat_tester", "90%", nullptr));
        label_Out_Title_70->setText(QApplication::translate("D_stat_tester", "70%", nullptr));
        label_Out_Value_Q_75->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Title_85->setText(QApplication::translate("D_stat_tester", "85%", nullptr));
        label_Out_Title_75->setText(QApplication::translate("D_stat_tester", "75%", nullptr));
        label_Out_Title_65->setText(QApplication::translate("D_stat_tester", "65%", nullptr));
        label_Out_Title_100->setText(QApplication::translate("D_stat_tester", "100%", nullptr));
        label_Out_Title_00->setText(QApplication::translate("D_stat_tester", "00%", nullptr));
        label_Out_Title_80->setText(QApplication::translate("D_stat_tester", "80%", nullptr));
        label_Out_Title_Quantiles->setText(QApplication::translate("D_stat_tester", "Quantiles", nullptr));
        label_Out_Title_25->setText(QApplication::translate("D_stat_tester", "25%", nullptr));
        label_Out_Title_20->setText(QApplication::translate("D_stat_tester", "20%", nullptr));
        label_Out_Title_Distnace->setText(QApplication::translate("D_stat_tester", "Distance", nullptr));
        label_Out_Title_45->setText(QApplication::translate("D_stat_tester", "45%", nullptr));
        label_Out_Title_40->setText(QApplication::translate("D_stat_tester", "40%", nullptr));
        label_Out_Title_30->setText(QApplication::translate("D_stat_tester", "30%", nullptr));
        label_Out_Title_50->setText(QApplication::translate("D_stat_tester", "50%", nullptr));
        label_Out_Title_05->setText(QApplication::translate("D_stat_tester", "05%", nullptr));
        label_Out_Title_10->setText(QApplication::translate("D_stat_tester", "10%", nullptr));
        label_Out_Title_15->setText(QApplication::translate("D_stat_tester", "15%", nullptr));
        label_Out_Title_60->setText(QApplication::translate("D_stat_tester", "60%", nullptr));
        label_Out_Title_95->setText(QApplication::translate("D_stat_tester", "95%", nullptr));
        label_Out_Title_35->setText(QApplication::translate("D_stat_tester", "35%", nullptr));
        label_Out_Title_55->setText(QApplication::translate("D_stat_tester", "55%", nullptr));
        label_Out_Value_Q_15->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_60->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_25->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_40->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_30->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_05->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_00->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_35->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_90->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_65->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_10->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_95->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_50->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_70->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_45->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_55->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_20->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_80->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_D_20->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_D_40->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_D_60->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_D_80->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_D_100->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_100->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_D_90->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_D_30->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_D_10->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_D_50->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_D_70->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        label_Out_Value_Q_85->setText(QApplication::translate("D_stat_tester", "-", nullptr));
        groupBox_Init->setTitle(QApplication::translate("D_stat_tester", "Init: Range", nullptr));
        label_Init_X_Range_2->setText(QApplication::translate("D_stat_tester", "to", nullptr));
        label_Init_X_Range_1->setText(QApplication::translate("D_stat_tester", "Value Range (X)", nullptr));
        label_Init_Y_Max->setText(QApplication::translate("D_stat_tester", "Amount Maximum (Y)", nullptr));
        pushButton_Init_Hist->setText(QApplication::translate("D_stat_tester", "Init Hist", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("D_stat_tester", "Linear", nullptr));
        groupBox->setTitle(QApplication::translate("D_stat_tester", "Input", nullptr));
        label->setText(QApplication::translate("D_stat_tester", "AngleInDegree-Count, each in a separate line", nullptr));
        pushButton_DistributionUniform->setText(QApplication::translate("D_stat_tester", "Uniform Distribution", nullptr));
        plainTextEdit_Input->setPlainText(QApplication::translate("D_stat_tester", "0-50\n"
"180-50\n"
"5-1", nullptr));
        groupBox_2->setTitle(QApplication::translate("D_stat_tester", "Output", nullptr));
        label_2->setText(QApplication::translate("D_stat_tester", "Circular statistics in degree and rad ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("D_stat_tester", "Circular", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_stat_tester: public Ui_D_stat_tester {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_STAT_TESTER_H
