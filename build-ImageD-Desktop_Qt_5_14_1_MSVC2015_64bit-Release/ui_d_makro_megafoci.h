/********************************************************************************
** Form generated from reading UI file 'd_makro_megafoci.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_MEGAFOCI_H
#define UI_D_MAKRO_MEGAFOCI_H

#include <QtCore/QVariant>
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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_MegaFoci
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_Viewport;
    QGridLayout *gridLayout_4;
    QSpinBox *spinBox_Viewport_T;
    QSpinBox *spinBox_Viewport_X;
    QSpinBox *spinBox_Viewport_Z;
    QSpinBox *spinBox_Viewport_Y;
    QSpinBox *spinBox_Viewport_P;
    QGraphicsView *graphicsView_OverviewSmall;
    QGroupBox *groupBox_Other;
    QGridLayout *gridLayout_9;
    QPlainTextEdit *plainTextEdit_Status;
    QGroupBox *groupBox_Dataset;
    QGridLayout *gridLayout_10;
    QPushButton *pushButton_DataLoad;
    QSpinBox *spinBox_DataDim_X;
    QSpinBox *spinBox_DataDim_Y;
    QSpinBox *spinBox_DataDim_T;
    QSpinBox *spinBox_DataDim_Z;
    QDoubleSpinBox *doubleSpinBox_OverviewQuality;
    QGroupBox *groupBox_VisTrafo;
    QGridLayout *gridLayout_8;
    QDoubleSpinBox *doubleSpinBox_VisTrafo_CropMax;
    QDoubleSpinBox *doubleSpinBox_VisTrafo_Anchor;
    QComboBox *comboBox_VisTrafo_RangeMode;
    QComboBox *comboBox_VisTrafo_AnchorMode;
    QDoubleSpinBox *doubleSpinBox_VisTrafo_Gamma;
    QDoubleSpinBox *doubleSpinBox_VisTrafo_LogDivisor;
    QDoubleSpinBox *doubleSpinBox_VisTrafo_Range;
    QComboBox *comboBox_VisTrafo_TransformationMode;
    QDoubleSpinBox *doubleSpinBox_VisTrafo_CropMin;
    QComboBox *comboBox_VisTrafo_CropMode;
    QDoubleSpinBox *doubleSpinBox_VisTrafo_LogCenter;
    QGroupBox *groupBox_View;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget_View;
    QWidget *page_ViewGraphics_Proc;
    QGridLayout *gridLayout_5;
    QGraphicsView *graphicsView_ImgProc;
    QWidget *page_ViewGraphics_OverviewBig;
    QGridLayout *gridLayout_12;
    QGraphicsView *graphicsView_OverviewBig;
    QWidget *page_ViewPlot;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_ViewPlot;
    QGroupBox *groupBox_Control;
    QGridLayout *gridLayout_7;
    QTabWidget *tabWidget_Control;
    QWidget *tab_ImgProc;
    QGridLayout *gridLayout_6;
    QFrame *line_3;
    QSpacerItem *verticalSpacer_ImgProc;
    QLabel *label_ImgProc_Stitch;
    QLabel *label_4;
    QComboBox *comboBox_ImgProc_ProjectZ_Stat;
    QSpinBox *spinBox_ImgProc_GFP_BlurMedianSize;
    QDoubleSpinBox *doubleSpinBox_ImgProc_GFP_AreaMax;
    QCheckBox *checkBox_ImgProc_NucWatershed_ExBordered;
    QCheckBox *checkBox_ImgProc_NucWatershed_NonSeed;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_ImgProc_GFP_AreaMin;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_ImgProc_Stitch_Overlap;
    QLabel *label_3;
    QFrame *line_2;
    QDoubleSpinBox *doubleSpinBox_ImgProc_Stitch_Border;
    QLabel *label_ImgProc_ProjectStat;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_ImgProc_GFP_ThresEdges;
    QDoubleSpinBox *doubleSpinBox_ImgProc_GFP_DistThres;
    QFrame *line;
    QComboBox *comboBox_ImgProc_StepShow;
    QLabel *label_6;
    QSpinBox *spinBox_ImgProc_GFP_EdgeCVSize;
    QWidget *tab_OverviewBig;
    QGridLayout *gridLayout_3;
    QSpinBox *spinBox_OverviewBig_T;
    QSlider *horizontalSlider_OverviewBig_T;
    QSpacerItem *verticalSpacer_OverviewBig;
    QFrame *line_OverviewBig;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_MegaFoci)
    {
        if (D_MAKRO_MegaFoci->objectName().isEmpty())
            D_MAKRO_MegaFoci->setObjectName(QString::fromUtf8("D_MAKRO_MegaFoci"));
        D_MAKRO_MegaFoci->resize(1416, 832);
        centralwidget = new QWidget(D_MAKRO_MegaFoci);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_Viewport = new QGroupBox(centralwidget);
        groupBox_Viewport->setObjectName(QString::fromUtf8("groupBox_Viewport"));
        groupBox_Viewport->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_Viewport->sizePolicy().hasHeightForWidth());
        groupBox_Viewport->setSizePolicy(sizePolicy);
        groupBox_Viewport->setMinimumSize(QSize(300, 382));
        groupBox_Viewport->setMaximumSize(QSize(300, 382));
        gridLayout_4 = new QGridLayout(groupBox_Viewport);
        gridLayout_4->setSpacing(3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(3, 3, 3, 3);
        spinBox_Viewport_T = new QSpinBox(groupBox_Viewport);
        spinBox_Viewport_T->setObjectName(QString::fromUtf8("spinBox_Viewport_T"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox_Viewport_T->sizePolicy().hasHeightForWidth());
        spinBox_Viewport_T->setSizePolicy(sizePolicy1);
        spinBox_Viewport_T->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_4->addWidget(spinBox_Viewport_T, 6, 2, 1, 1);

        spinBox_Viewport_X = new QSpinBox(groupBox_Viewport);
        spinBox_Viewport_X->setObjectName(QString::fromUtf8("spinBox_Viewport_X"));
        sizePolicy1.setHeightForWidth(spinBox_Viewport_X->sizePolicy().hasHeightForWidth());
        spinBox_Viewport_X->setSizePolicy(sizePolicy1);
        spinBox_Viewport_X->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_4->addWidget(spinBox_Viewport_X, 4, 1, 1, 1);

        spinBox_Viewport_Z = new QSpinBox(groupBox_Viewport);
        spinBox_Viewport_Z->setObjectName(QString::fromUtf8("spinBox_Viewport_Z"));
        spinBox_Viewport_Z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Viewport_Z->setValue(2);

        gridLayout_4->addWidget(spinBox_Viewport_Z, 6, 1, 1, 1);

        spinBox_Viewport_Y = new QSpinBox(groupBox_Viewport);
        spinBox_Viewport_Y->setObjectName(QString::fromUtf8("spinBox_Viewport_Y"));
        sizePolicy1.setHeightForWidth(spinBox_Viewport_Y->sizePolicy().hasHeightForWidth());
        spinBox_Viewport_Y->setSizePolicy(sizePolicy1);
        spinBox_Viewport_Y->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_4->addWidget(spinBox_Viewport_Y, 4, 2, 1, 1);

        spinBox_Viewport_P = new QSpinBox(groupBox_Viewport);
        spinBox_Viewport_P->setObjectName(QString::fromUtf8("spinBox_Viewport_P"));
        spinBox_Viewport_P->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Viewport_P->setMaximum(1);

        gridLayout_4->addWidget(spinBox_Viewport_P, 7, 1, 1, 2);

        graphicsView_OverviewSmall = new QGraphicsView(groupBox_Viewport);
        graphicsView_OverviewSmall->setObjectName(QString::fromUtf8("graphicsView_OverviewSmall"));
        graphicsView_OverviewSmall->setMinimumSize(QSize(292, 0));
        graphicsView_OverviewSmall->setMaximumSize(QSize(292, 292));
        graphicsView_OverviewSmall->setMouseTracking(true);

        gridLayout_4->addWidget(graphicsView_OverviewSmall, 0, 1, 1, 2);


        gridLayout->addWidget(groupBox_Viewport, 1, 0, 1, 1);

        groupBox_Other = new QGroupBox(centralwidget);
        groupBox_Other->setObjectName(QString::fromUtf8("groupBox_Other"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_Other->sizePolicy().hasHeightForWidth());
        groupBox_Other->setSizePolicy(sizePolicy2);
        groupBox_Other->setMinimumSize(QSize(300, 60));
        groupBox_Other->setMaximumSize(QSize(300, 16777215));
        gridLayout_9 = new QGridLayout(groupBox_Other);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        plainTextEdit_Status = new QPlainTextEdit(groupBox_Other);
        plainTextEdit_Status->setObjectName(QString::fromUtf8("plainTextEdit_Status"));
        plainTextEdit_Status->setReadOnly(true);

        gridLayout_9->addWidget(plainTextEdit_Status, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_Other, 3, 0, 1, 1);

        groupBox_Dataset = new QGroupBox(centralwidget);
        groupBox_Dataset->setObjectName(QString::fromUtf8("groupBox_Dataset"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_Dataset->sizePolicy().hasHeightForWidth());
        groupBox_Dataset->setSizePolicy(sizePolicy3);
        groupBox_Dataset->setMinimumSize(QSize(300, 0));
        groupBox_Dataset->setMaximumSize(QSize(300, 16777215));
        gridLayout_10 = new QGridLayout(groupBox_Dataset);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        pushButton_DataLoad = new QPushButton(groupBox_Dataset);
        pushButton_DataLoad->setObjectName(QString::fromUtf8("pushButton_DataLoad"));

        gridLayout_10->addWidget(pushButton_DataLoad, 3, 0, 1, 2);

        spinBox_DataDim_X = new QSpinBox(groupBox_Dataset);
        spinBox_DataDim_X->setObjectName(QString::fromUtf8("spinBox_DataDim_X"));
        spinBox_DataDim_X->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_DataDim_X->setMinimum(1);
        spinBox_DataDim_X->setValue(15);

        gridLayout_10->addWidget(spinBox_DataDim_X, 0, 0, 1, 1);

        spinBox_DataDim_Y = new QSpinBox(groupBox_Dataset);
        spinBox_DataDim_Y->setObjectName(QString::fromUtf8("spinBox_DataDim_Y"));
        spinBox_DataDim_Y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_DataDim_Y->setMinimum(1);
        spinBox_DataDim_Y->setValue(15);

        gridLayout_10->addWidget(spinBox_DataDim_Y, 0, 1, 1, 1);

        spinBox_DataDim_T = new QSpinBox(groupBox_Dataset);
        spinBox_DataDim_T->setObjectName(QString::fromUtf8("spinBox_DataDim_T"));
        spinBox_DataDim_T->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_DataDim_T->setMinimum(1);
        spinBox_DataDim_T->setValue(42);

        gridLayout_10->addWidget(spinBox_DataDim_T, 1, 1, 1, 1);

        spinBox_DataDim_Z = new QSpinBox(groupBox_Dataset);
        spinBox_DataDim_Z->setObjectName(QString::fromUtf8("spinBox_DataDim_Z"));
        spinBox_DataDim_Z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_DataDim_Z->setMinimum(1);
        spinBox_DataDim_Z->setValue(6);

        gridLayout_10->addWidget(spinBox_DataDim_Z, 1, 0, 1, 1);

        doubleSpinBox_OverviewQuality = new QDoubleSpinBox(groupBox_Dataset);
        doubleSpinBox_OverviewQuality->setObjectName(QString::fromUtf8("doubleSpinBox_OverviewQuality"));
        doubleSpinBox_OverviewQuality->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_OverviewQuality->setDecimals(0);
        doubleSpinBox_OverviewQuality->setMinimum(1.000000000000000);
        doubleSpinBox_OverviewQuality->setValue(5.000000000000000);

        gridLayout_10->addWidget(doubleSpinBox_OverviewQuality, 2, 0, 1, 2);


        gridLayout->addWidget(groupBox_Dataset, 0, 0, 1, 1);

        groupBox_VisTrafo = new QGroupBox(centralwidget);
        groupBox_VisTrafo->setObjectName(QString::fromUtf8("groupBox_VisTrafo"));
        groupBox_VisTrafo->setEnabled(true);
        sizePolicy3.setHeightForWidth(groupBox_VisTrafo->sizePolicy().hasHeightForWidth());
        groupBox_VisTrafo->setSizePolicy(sizePolicy3);
        groupBox_VisTrafo->setMinimumSize(QSize(300, 0));
        groupBox_VisTrafo->setMaximumSize(QSize(300, 16777215));
        groupBox_VisTrafo->setCheckable(true);
        groupBox_VisTrafo->setChecked(true);
        gridLayout_8 = new QGridLayout(groupBox_VisTrafo);
        gridLayout_8->setSpacing(3);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(3, 3, 3, 3);
        doubleSpinBox_VisTrafo_CropMax = new QDoubleSpinBox(groupBox_VisTrafo);
        doubleSpinBox_VisTrafo_CropMax->setObjectName(QString::fromUtf8("doubleSpinBox_VisTrafo_CropMax"));
        doubleSpinBox_VisTrafo_CropMax->setEnabled(false);
        doubleSpinBox_VisTrafo_CropMax->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_VisTrafo_CropMax->setDecimals(0);
        doubleSpinBox_VisTrafo_CropMax->setMaximum(65535.000000000000000);
        doubleSpinBox_VisTrafo_CropMax->setSingleStep(250.000000000000000);
        doubleSpinBox_VisTrafo_CropMax->setValue(3000.000000000000000);

        gridLayout_8->addWidget(doubleSpinBox_VisTrafo_CropMax, 1, 2, 1, 2);

        doubleSpinBox_VisTrafo_Anchor = new QDoubleSpinBox(groupBox_VisTrafo);
        doubleSpinBox_VisTrafo_Anchor->setObjectName(QString::fromUtf8("doubleSpinBox_VisTrafo_Anchor"));
        doubleSpinBox_VisTrafo_Anchor->setEnabled(false);
        doubleSpinBox_VisTrafo_Anchor->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_VisTrafo_Anchor->setDecimals(0);
        doubleSpinBox_VisTrafo_Anchor->setMaximum(65535.000000000000000);

        gridLayout_8->addWidget(doubleSpinBox_VisTrafo_Anchor, 6, 0, 1, 2);

        comboBox_VisTrafo_RangeMode = new QComboBox(groupBox_VisTrafo);
        comboBox_VisTrafo_RangeMode->setObjectName(QString::fromUtf8("comboBox_VisTrafo_RangeMode"));

        gridLayout_8->addWidget(comboBox_VisTrafo_RangeMode, 5, 2, 1, 2);

        comboBox_VisTrafo_AnchorMode = new QComboBox(groupBox_VisTrafo);
        comboBox_VisTrafo_AnchorMode->setObjectName(QString::fromUtf8("comboBox_VisTrafo_AnchorMode"));

        gridLayout_8->addWidget(comboBox_VisTrafo_AnchorMode, 5, 0, 1, 2);

        doubleSpinBox_VisTrafo_Gamma = new QDoubleSpinBox(groupBox_VisTrafo);
        doubleSpinBox_VisTrafo_Gamma->setObjectName(QString::fromUtf8("doubleSpinBox_VisTrafo_Gamma"));
        doubleSpinBox_VisTrafo_Gamma->setEnabled(false);
        doubleSpinBox_VisTrafo_Gamma->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_VisTrafo_Gamma->setDecimals(3);
        doubleSpinBox_VisTrafo_Gamma->setMinimum(0.001000000000000);
        doubleSpinBox_VisTrafo_Gamma->setSingleStep(0.010000000000000);
        doubleSpinBox_VisTrafo_Gamma->setValue(1.000000000000000);

        gridLayout_8->addWidget(doubleSpinBox_VisTrafo_Gamma, 3, 0, 1, 4);

        doubleSpinBox_VisTrafo_LogDivisor = new QDoubleSpinBox(groupBox_VisTrafo);
        doubleSpinBox_VisTrafo_LogDivisor->setObjectName(QString::fromUtf8("doubleSpinBox_VisTrafo_LogDivisor"));
        doubleSpinBox_VisTrafo_LogDivisor->setEnabled(false);
        doubleSpinBox_VisTrafo_LogDivisor->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_VisTrafo_LogDivisor->setDecimals(3);
        doubleSpinBox_VisTrafo_LogDivisor->setMinimum(0.001000000000000);
        doubleSpinBox_VisTrafo_LogDivisor->setMaximum(1000000.000000000000000);
        doubleSpinBox_VisTrafo_LogDivisor->setSingleStep(1.000000000000000);
        doubleSpinBox_VisTrafo_LogDivisor->setValue(250.000000000000000);

        gridLayout_8->addWidget(doubleSpinBox_VisTrafo_LogDivisor, 4, 2, 1, 2);

        doubleSpinBox_VisTrafo_Range = new QDoubleSpinBox(groupBox_VisTrafo);
        doubleSpinBox_VisTrafo_Range->setObjectName(QString::fromUtf8("doubleSpinBox_VisTrafo_Range"));
        doubleSpinBox_VisTrafo_Range->setEnabled(false);
        doubleSpinBox_VisTrafo_Range->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_VisTrafo_Range->setDecimals(0);
        doubleSpinBox_VisTrafo_Range->setMaximum(65536.000000000000000);
        doubleSpinBox_VisTrafo_Range->setValue(10000.000000000000000);

        gridLayout_8->addWidget(doubleSpinBox_VisTrafo_Range, 6, 2, 1, 2);

        comboBox_VisTrafo_TransformationMode = new QComboBox(groupBox_VisTrafo);
        comboBox_VisTrafo_TransformationMode->setObjectName(QString::fromUtf8("comboBox_VisTrafo_TransformationMode"));

        gridLayout_8->addWidget(comboBox_VisTrafo_TransformationMode, 2, 0, 1, 4);

        doubleSpinBox_VisTrafo_CropMin = new QDoubleSpinBox(groupBox_VisTrafo);
        doubleSpinBox_VisTrafo_CropMin->setObjectName(QString::fromUtf8("doubleSpinBox_VisTrafo_CropMin"));
        doubleSpinBox_VisTrafo_CropMin->setEnabled(false);
        doubleSpinBox_VisTrafo_CropMin->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_VisTrafo_CropMin->setDecimals(0);
        doubleSpinBox_VisTrafo_CropMin->setMaximum(65535.000000000000000);

        gridLayout_8->addWidget(doubleSpinBox_VisTrafo_CropMin, 1, 0, 1, 2);

        comboBox_VisTrafo_CropMode = new QComboBox(groupBox_VisTrafo);
        comboBox_VisTrafo_CropMode->setObjectName(QString::fromUtf8("comboBox_VisTrafo_CropMode"));

        gridLayout_8->addWidget(comboBox_VisTrafo_CropMode, 0, 0, 1, 4);

        doubleSpinBox_VisTrafo_LogCenter = new QDoubleSpinBox(groupBox_VisTrafo);
        doubleSpinBox_VisTrafo_LogCenter->setObjectName(QString::fromUtf8("doubleSpinBox_VisTrafo_LogCenter"));
        doubleSpinBox_VisTrafo_LogCenter->setEnabled(false);
        doubleSpinBox_VisTrafo_LogCenter->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_VisTrafo_LogCenter->setDecimals(3);
        doubleSpinBox_VisTrafo_LogCenter->setMinimum(-100000000000000003502199685943161173046080317798311825604870144.000000000000000);
        doubleSpinBox_VisTrafo_LogCenter->setMaximum(10000000000000000725314363815292351261583744096465219555182101554790400.000000000000000);

        gridLayout_8->addWidget(doubleSpinBox_VisTrafo_LogCenter, 4, 0, 1, 2);


        gridLayout->addWidget(groupBox_VisTrafo, 2, 0, 1, 1);

        groupBox_View = new QGroupBox(centralwidget);
        groupBox_View->setObjectName(QString::fromUtf8("groupBox_View"));
        groupBox_View->setEnabled(true);
        gridLayout_2 = new QGridLayout(groupBox_View);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget_View = new QStackedWidget(groupBox_View);
        stackedWidget_View->setObjectName(QString::fromUtf8("stackedWidget_View"));
        page_ViewGraphics_Proc = new QWidget();
        page_ViewGraphics_Proc->setObjectName(QString::fromUtf8("page_ViewGraphics_Proc"));
        gridLayout_5 = new QGridLayout(page_ViewGraphics_Proc);
        gridLayout_5->setSpacing(3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(3, 3, 3, 3);
        graphicsView_ImgProc = new QGraphicsView(page_ViewGraphics_Proc);
        graphicsView_ImgProc->setObjectName(QString::fromUtf8("graphicsView_ImgProc"));
        graphicsView_ImgProc->setMouseTracking(true);

        gridLayout_5->addWidget(graphicsView_ImgProc, 0, 0, 1, 1);

        stackedWidget_View->addWidget(page_ViewGraphics_Proc);
        page_ViewGraphics_OverviewBig = new QWidget();
        page_ViewGraphics_OverviewBig->setObjectName(QString::fromUtf8("page_ViewGraphics_OverviewBig"));
        gridLayout_12 = new QGridLayout(page_ViewGraphics_OverviewBig);
        gridLayout_12->setSpacing(3);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(3, 3, 3, 3);
        graphicsView_OverviewBig = new QGraphicsView(page_ViewGraphics_OverviewBig);
        graphicsView_OverviewBig->setObjectName(QString::fromUtf8("graphicsView_OverviewBig"));

        gridLayout_12->addWidget(graphicsView_OverviewBig, 0, 0, 1, 1);

        stackedWidget_View->addWidget(page_ViewGraphics_OverviewBig);
        page_ViewPlot = new QWidget();
        page_ViewPlot->setObjectName(QString::fromUtf8("page_ViewPlot"));
        gridLayout_11 = new QGridLayout(page_ViewPlot);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_ViewPlot = new QGridLayout();
        gridLayout_ViewPlot->setObjectName(QString::fromUtf8("gridLayout_ViewPlot"));

        gridLayout_11->addLayout(gridLayout_ViewPlot, 0, 0, 1, 1);

        stackedWidget_View->addWidget(page_ViewPlot);

        gridLayout_2->addWidget(stackedWidget_View, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_View, 0, 1, 4, 1);

        groupBox_Control = new QGroupBox(centralwidget);
        groupBox_Control->setObjectName(QString::fromUtf8("groupBox_Control"));
        groupBox_Control->setEnabled(true);
        groupBox_Control->setMinimumSize(QSize(400, 0));
        groupBox_Control->setMaximumSize(QSize(400, 16777215));
        gridLayout_7 = new QGridLayout(groupBox_Control);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        tabWidget_Control = new QTabWidget(groupBox_Control);
        tabWidget_Control->setObjectName(QString::fromUtf8("tabWidget_Control"));
        tabWidget_Control->setMinimumSize(QSize(0, 0));
        tabWidget_Control->setMaximumSize(QSize(16777215, 16777215));
        tab_ImgProc = new QWidget();
        tab_ImgProc->setObjectName(QString::fromUtf8("tab_ImgProc"));
        gridLayout_6 = new QGridLayout(tab_ImgProc);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        line_3 = new QFrame(tab_ImgProc);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_3, 11, 0, 1, 3);

        verticalSpacer_ImgProc = new QSpacerItem(273, 277, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_ImgProc, 12, 0, 1, 3);

        label_ImgProc_Stitch = new QLabel(tab_ImgProc);
        label_ImgProc_Stitch->setObjectName(QString::fromUtf8("label_ImgProc_Stitch"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_ImgProc_Stitch->sizePolicy().hasHeightForWidth());
        label_ImgProc_Stitch->setSizePolicy(sizePolicy4);

        gridLayout_6->addWidget(label_ImgProc_Stitch, 2, 0, 1, 1);

        label_4 = new QLabel(tab_ImgProc);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_6->addWidget(label_4, 9, 0, 1, 1);

        comboBox_ImgProc_ProjectZ_Stat = new QComboBox(tab_ImgProc);
        comboBox_ImgProc_ProjectZ_Stat->addItem(QString());
        comboBox_ImgProc_ProjectZ_Stat->setObjectName(QString::fromUtf8("comboBox_ImgProc_ProjectZ_Stat"));

        gridLayout_6->addWidget(comboBox_ImgProc_ProjectZ_Stat, 3, 1, 1, 2);

        spinBox_ImgProc_GFP_BlurMedianSize = new QSpinBox(tab_ImgProc);
        spinBox_ImgProc_GFP_BlurMedianSize->setObjectName(QString::fromUtf8("spinBox_ImgProc_GFP_BlurMedianSize"));
        spinBox_ImgProc_GFP_BlurMedianSize->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ImgProc_GFP_BlurMedianSize->setMinimum(1);
        spinBox_ImgProc_GFP_BlurMedianSize->setMaximum(299);
        spinBox_ImgProc_GFP_BlurMedianSize->setSingleStep(2);
        spinBox_ImgProc_GFP_BlurMedianSize->setValue(31);

        gridLayout_6->addWidget(spinBox_ImgProc_GFP_BlurMedianSize, 5, 1, 1, 2);

        doubleSpinBox_ImgProc_GFP_AreaMax = new QDoubleSpinBox(tab_ImgProc);
        doubleSpinBox_ImgProc_GFP_AreaMax->setObjectName(QString::fromUtf8("doubleSpinBox_ImgProc_GFP_AreaMax"));
        doubleSpinBox_ImgProc_GFP_AreaMax->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_ImgProc_GFP_AreaMax->setDecimals(0);
        doubleSpinBox_ImgProc_GFP_AreaMax->setMaximum(1000000.000000000000000);
        doubleSpinBox_ImgProc_GFP_AreaMax->setSingleStep(500.000000000000000);
        doubleSpinBox_ImgProc_GFP_AreaMax->setValue(1000000.000000000000000);

        gridLayout_6->addWidget(doubleSpinBox_ImgProc_GFP_AreaMax, 8, 2, 1, 1);

        checkBox_ImgProc_NucWatershed_ExBordered = new QCheckBox(tab_ImgProc);
        checkBox_ImgProc_NucWatershed_ExBordered->setObjectName(QString::fromUtf8("checkBox_ImgProc_NucWatershed_ExBordered"));
        checkBox_ImgProc_NucWatershed_ExBordered->setChecked(true);

        gridLayout_6->addWidget(checkBox_ImgProc_NucWatershed_ExBordered, 10, 2, 1, 1);

        checkBox_ImgProc_NucWatershed_NonSeed = new QCheckBox(tab_ImgProc);
        checkBox_ImgProc_NucWatershed_NonSeed->setObjectName(QString::fromUtf8("checkBox_ImgProc_NucWatershed_NonSeed"));
        checkBox_ImgProc_NucWatershed_NonSeed->setChecked(true);

        gridLayout_6->addWidget(checkBox_ImgProc_NucWatershed_NonSeed, 10, 1, 1, 1);

        label_2 = new QLabel(tab_ImgProc);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_6->addWidget(label_2, 7, 0, 1, 1);

        doubleSpinBox_ImgProc_GFP_AreaMin = new QDoubleSpinBox(tab_ImgProc);
        doubleSpinBox_ImgProc_GFP_AreaMin->setObjectName(QString::fromUtf8("doubleSpinBox_ImgProc_GFP_AreaMin"));
        doubleSpinBox_ImgProc_GFP_AreaMin->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_ImgProc_GFP_AreaMin->setProperty("showGroupSeparator", QVariant(false));
        doubleSpinBox_ImgProc_GFP_AreaMin->setDecimals(0);
        doubleSpinBox_ImgProc_GFP_AreaMin->setMaximum(999999.000000000000000);
        doubleSpinBox_ImgProc_GFP_AreaMin->setSingleStep(500.000000000000000);
        doubleSpinBox_ImgProc_GFP_AreaMin->setValue(15000.000000000000000);

        gridLayout_6->addWidget(doubleSpinBox_ImgProc_GFP_AreaMin, 8, 1, 1, 1);

        label_5 = new QLabel(tab_ImgProc);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_6->addWidget(label_5, 10, 0, 1, 1);

        doubleSpinBox_ImgProc_Stitch_Overlap = new QDoubleSpinBox(tab_ImgProc);
        doubleSpinBox_ImgProc_Stitch_Overlap->setObjectName(QString::fromUtf8("doubleSpinBox_ImgProc_Stitch_Overlap"));
        doubleSpinBox_ImgProc_Stitch_Overlap->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_ImgProc_Stitch_Overlap->setDecimals(2);
        doubleSpinBox_ImgProc_Stitch_Overlap->setMaximum(75.000000000000000);
        doubleSpinBox_ImgProc_Stitch_Overlap->setSingleStep(0.250000000000000);
        doubleSpinBox_ImgProc_Stitch_Overlap->setValue(3.000000000000000);

        gridLayout_6->addWidget(doubleSpinBox_ImgProc_Stitch_Overlap, 2, 2, 1, 1);

        label_3 = new QLabel(tab_ImgProc);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_6->addWidget(label_3, 8, 0, 1, 1);

        line_2 = new QFrame(tab_ImgProc);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_2, 4, 0, 1, 3);

        doubleSpinBox_ImgProc_Stitch_Border = new QDoubleSpinBox(tab_ImgProc);
        doubleSpinBox_ImgProc_Stitch_Border->setObjectName(QString::fromUtf8("doubleSpinBox_ImgProc_Stitch_Border"));
        doubleSpinBox_ImgProc_Stitch_Border->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_ImgProc_Stitch_Border->setDecimals(2);
        doubleSpinBox_ImgProc_Stitch_Border->setMaximum(100.000000000000000);
        doubleSpinBox_ImgProc_Stitch_Border->setSingleStep(0.250000000000000);
        doubleSpinBox_ImgProc_Stitch_Border->setValue(50.000000000000000);

        gridLayout_6->addWidget(doubleSpinBox_ImgProc_Stitch_Border, 2, 1, 1, 1);

        label_ImgProc_ProjectStat = new QLabel(tab_ImgProc);
        label_ImgProc_ProjectStat->setObjectName(QString::fromUtf8("label_ImgProc_ProjectStat"));

        gridLayout_6->addWidget(label_ImgProc_ProjectStat, 3, 0, 1, 1);

        label = new QLabel(tab_ImgProc);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_6->addWidget(label, 5, 0, 1, 1);

        doubleSpinBox_ImgProc_GFP_ThresEdges = new QDoubleSpinBox(tab_ImgProc);
        doubleSpinBox_ImgProc_GFP_ThresEdges->setObjectName(QString::fromUtf8("doubleSpinBox_ImgProc_GFP_ThresEdges"));
        doubleSpinBox_ImgProc_GFP_ThresEdges->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_ImgProc_GFP_ThresEdges->setDecimals(3);
        doubleSpinBox_ImgProc_GFP_ThresEdges->setSingleStep(0.002000000000000);
        doubleSpinBox_ImgProc_GFP_ThresEdges->setValue(0.080000000000000);

        gridLayout_6->addWidget(doubleSpinBox_ImgProc_GFP_ThresEdges, 7, 1, 1, 2);

        doubleSpinBox_ImgProc_GFP_DistThres = new QDoubleSpinBox(tab_ImgProc);
        doubleSpinBox_ImgProc_GFP_DistThres->setObjectName(QString::fromUtf8("doubleSpinBox_ImgProc_GFP_DistThres"));
        doubleSpinBox_ImgProc_GFP_DistThres->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_ImgProc_GFP_DistThres->setMaximum(1000.000000000000000);
        doubleSpinBox_ImgProc_GFP_DistThres->setValue(72.000000000000000);

        gridLayout_6->addWidget(doubleSpinBox_ImgProc_GFP_DistThres, 9, 1, 1, 2);

        line = new QFrame(tab_ImgProc);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line, 1, 0, 1, 3);

        comboBox_ImgProc_StepShow = new QComboBox(tab_ImgProc);
        comboBox_ImgProc_StepShow->addItem(QString());
        comboBox_ImgProc_StepShow->setObjectName(QString::fromUtf8("comboBox_ImgProc_StepShow"));

        gridLayout_6->addWidget(comboBox_ImgProc_StepShow, 0, 0, 1, 3);

        label_6 = new QLabel(tab_ImgProc);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_6->addWidget(label_6, 6, 0, 1, 1);

        spinBox_ImgProc_GFP_EdgeCVSize = new QSpinBox(tab_ImgProc);
        spinBox_ImgProc_GFP_EdgeCVSize->setObjectName(QString::fromUtf8("spinBox_ImgProc_GFP_EdgeCVSize"));
        spinBox_ImgProc_GFP_EdgeCVSize->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ImgProc_GFP_EdgeCVSize->setMinimum(1);
        spinBox_ImgProc_GFP_EdgeCVSize->setMaximum(299);
        spinBox_ImgProc_GFP_EdgeCVSize->setSingleStep(2);
        spinBox_ImgProc_GFP_EdgeCVSize->setValue(15);

        gridLayout_6->addWidget(spinBox_ImgProc_GFP_EdgeCVSize, 6, 1, 1, 2);

        tabWidget_Control->addTab(tab_ImgProc, QString());
        tab_OverviewBig = new QWidget();
        tab_OverviewBig->setObjectName(QString::fromUtf8("tab_OverviewBig"));
        gridLayout_3 = new QGridLayout(tab_OverviewBig);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        spinBox_OverviewBig_T = new QSpinBox(tab_OverviewBig);
        spinBox_OverviewBig_T->setObjectName(QString::fromUtf8("spinBox_OverviewBig_T"));
        spinBox_OverviewBig_T->setMinimumSize(QSize(0, 0));
        spinBox_OverviewBig_T->setMaximumSize(QSize(16777215, 16777215));
        spinBox_OverviewBig_T->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_OverviewBig_T->setMaximum(42);

        gridLayout_3->addWidget(spinBox_OverviewBig_T, 0, 0, 1, 1);

        horizontalSlider_OverviewBig_T = new QSlider(tab_OverviewBig);
        horizontalSlider_OverviewBig_T->setObjectName(QString::fromUtf8("horizontalSlider_OverviewBig_T"));
        horizontalSlider_OverviewBig_T->setPageStep(1);
        horizontalSlider_OverviewBig_T->setOrientation(Qt::Horizontal);
        horizontalSlider_OverviewBig_T->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_OverviewBig_T->setTickInterval(1);

        gridLayout_3->addWidget(horizontalSlider_OverviewBig_T, 1, 0, 1, 1);

        verticalSpacer_OverviewBig = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_OverviewBig, 3, 0, 2, 1);

        line_OverviewBig = new QFrame(tab_OverviewBig);
        line_OverviewBig->setObjectName(QString::fromUtf8("line_OverviewBig"));
        line_OverviewBig->setFrameShape(QFrame::HLine);
        line_OverviewBig->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_OverviewBig, 2, 0, 1, 1);

        tabWidget_Control->addTab(tab_OverviewBig, QString());

        gridLayout_7->addWidget(tabWidget_Control, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_Control, 0, 2, 4, 1);

        D_MAKRO_MegaFoci->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_MegaFoci);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1416, 21));
        D_MAKRO_MegaFoci->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_MegaFoci);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_MegaFoci->setStatusBar(statusbar);

        retranslateUi(D_MAKRO_MegaFoci);
        QObject::connect(horizontalSlider_OverviewBig_T, SIGNAL(valueChanged(int)), spinBox_OverviewBig_T, SLOT(setValue(int)));
        QObject::connect(spinBox_OverviewBig_T, SIGNAL(valueChanged(int)), horizontalSlider_OverviewBig_T, SLOT(setValue(int)));

        stackedWidget_View->setCurrentIndex(0);
        tabWidget_Control->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(D_MAKRO_MegaFoci);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_MegaFoci)
    {
        D_MAKRO_MegaFoci->setWindowTitle(QCoreApplication::translate("D_MAKRO_MegaFoci", "MainWindow", nullptr));
        groupBox_Viewport->setTitle(QCoreApplication::translate("D_MAKRO_MegaFoci", "Viewport (currently processed)", nullptr));
        spinBox_Viewport_T->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "T=", nullptr));
        spinBox_Viewport_X->setSuffix(QCoreApplication::translate("D_MAKRO_MegaFoci", " (stitched)", nullptr));
        spinBox_Viewport_X->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "X=", nullptr));
        spinBox_Viewport_Z->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "Z=", nullptr));
        spinBox_Viewport_Y->setSuffix(QCoreApplication::translate("D_MAKRO_MegaFoci", " (stitched)", nullptr));
        spinBox_Viewport_Y->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "Y=", nullptr));
        spinBox_Viewport_P->setSuffix(QCoreApplication::translate("D_MAKRO_MegaFoci", " (GFP)", nullptr));
        spinBox_Viewport_P->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "P=", nullptr));
        groupBox_Other->setTitle(QCoreApplication::translate("D_MAKRO_MegaFoci", "Status", nullptr));
        groupBox_Dataset->setTitle(QCoreApplication::translate("D_MAKRO_MegaFoci", "Dataset", nullptr));
        pushButton_DataLoad->setText(QCoreApplication::translate("D_MAKRO_MegaFoci", "Load Dataset", nullptr));
        spinBox_DataDim_X->setSuffix(QCoreApplication::translate("D_MAKRO_MegaFoci", " images", nullptr));
        spinBox_DataDim_X->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "X: ", nullptr));
        spinBox_DataDim_Y->setSuffix(QCoreApplication::translate("D_MAKRO_MegaFoci", " images", nullptr));
        spinBox_DataDim_Y->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "Y: ", nullptr));
        spinBox_DataDim_T->setSuffix(QCoreApplication::translate("D_MAKRO_MegaFoci", " times", nullptr));
        spinBox_DataDim_T->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "T: ", nullptr));
        spinBox_DataDim_Z->setSuffix(QCoreApplication::translate("D_MAKRO_MegaFoci", " planes", nullptr));
        spinBox_DataDim_Z->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "Z: ", nullptr));
        doubleSpinBox_OverviewQuality->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "Overview quality: ", nullptr));
        doubleSpinBox_OverviewQuality->setSuffix(QCoreApplication::translate("D_MAKRO_MegaFoci", "% of original image", nullptr));
        groupBox_VisTrafo->setTitle(QCoreApplication::translate("D_MAKRO_MegaFoci", "View transformation", nullptr));
        doubleSpinBox_VisTrafo_CropMax->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "max=", nullptr));
        doubleSpinBox_VisTrafo_Anchor->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "anchor=", nullptr));
        doubleSpinBox_VisTrafo_Gamma->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "gamma=", nullptr));
        doubleSpinBox_VisTrafo_LogDivisor->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "divisor=", nullptr));
        doubleSpinBox_VisTrafo_Range->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "range=", nullptr));
        doubleSpinBox_VisTrafo_CropMin->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "min=", nullptr));
        doubleSpinBox_VisTrafo_LogCenter->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "center=", nullptr));
        groupBox_View->setTitle(QCoreApplication::translate("D_MAKRO_MegaFoci", "View", nullptr));
        groupBox_Control->setTitle(QCoreApplication::translate("D_MAKRO_MegaFoci", "Control", nullptr));
        label_ImgProc_Stitch->setText(QCoreApplication::translate("D_MAKRO_MegaFoci", "00", nullptr));
        label_4->setText(QCoreApplication::translate("D_MAKRO_MegaFoci", "15", nullptr));
        comboBox_ImgProc_ProjectZ_Stat->setItemText(0, QCoreApplication::translate("D_MAKRO_MegaFoci", "[project stats]", nullptr));

        spinBox_ImgProc_GFP_BlurMedianSize->setSuffix(QCoreApplication::translate("D_MAKRO_MegaFoci", "px", nullptr));
        spinBox_ImgProc_GFP_BlurMedianSize->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "median filter radius ", nullptr));
        doubleSpinBox_ImgProc_GFP_AreaMax->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "max area ", nullptr));
        doubleSpinBox_ImgProc_GFP_AreaMax->setSuffix(QCoreApplication::translate("D_MAKRO_MegaFoci", "px", nullptr));
        checkBox_ImgProc_NucWatershed_ExBordered->setText(QCoreApplication::translate("D_MAKRO_MegaFoci", "Exclude Bordered", nullptr));
        checkBox_ImgProc_NucWatershed_NonSeed->setText(QCoreApplication::translate("D_MAKRO_MegaFoci", "Include not seeded", nullptr));
        label_2->setText(QCoreApplication::translate("D_MAKRO_MegaFoci", "11", nullptr));
        doubleSpinBox_ImgProc_GFP_AreaMin->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "min area ", nullptr));
        doubleSpinBox_ImgProc_GFP_AreaMin->setSuffix(QCoreApplication::translate("D_MAKRO_MegaFoci", "px", nullptr));
        label_5->setText(QCoreApplication::translate("D_MAKRO_MegaFoci", "16", nullptr));
        doubleSpinBox_ImgProc_Stitch_Overlap->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "overlap=", nullptr));
        doubleSpinBox_ImgProc_Stitch_Overlap->setSuffix(QCoreApplication::translate("D_MAKRO_MegaFoci", "%", nullptr));
        label_3->setText(QCoreApplication::translate("D_MAKRO_MegaFoci", "13", nullptr));
        doubleSpinBox_ImgProc_Stitch_Border->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "border=", nullptr));
        doubleSpinBox_ImgProc_Stitch_Border->setSuffix(QCoreApplication::translate("D_MAKRO_MegaFoci", "%", nullptr));
        label_ImgProc_ProjectStat->setText(QCoreApplication::translate("D_MAKRO_MegaFoci", "05", nullptr));
        label->setText(QCoreApplication::translate("D_MAKRO_MegaFoci", "09", nullptr));
        doubleSpinBox_ImgProc_GFP_ThresEdges->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "threshold edge image ", nullptr));
        doubleSpinBox_ImgProc_GFP_DistThres->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "threshold distance ", nullptr));
        doubleSpinBox_ImgProc_GFP_DistThres->setSuffix(QCoreApplication::translate("D_MAKRO_MegaFoci", "px", nullptr));
        comboBox_ImgProc_StepShow->setItemText(0, QCoreApplication::translate("D_MAKRO_MegaFoci", "[steps]", nullptr));

        label_6->setText(QCoreApplication::translate("D_MAKRO_MegaFoci", "10", nullptr));
        spinBox_ImgProc_GFP_EdgeCVSize->setSuffix(QCoreApplication::translate("D_MAKRO_MegaFoci", "px", nullptr));
        spinBox_ImgProc_GFP_EdgeCVSize->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "coefficient of variance filter radius ", nullptr));
        tabWidget_Control->setTabText(tabWidget_Control->indexOf(tab_ImgProc), QCoreApplication::translate("D_MAKRO_MegaFoci", "ImgProc", nullptr));
        spinBox_OverviewBig_T->setSuffix(QCoreApplication::translate("D_MAKRO_MegaFoci", " (only processed can be viewed)", nullptr));
        spinBox_OverviewBig_T->setPrefix(QCoreApplication::translate("D_MAKRO_MegaFoci", "Show time frame ", nullptr));
        tabWidget_Control->setTabText(tabWidget_Control->indexOf(tab_OverviewBig), QCoreApplication::translate("D_MAKRO_MegaFoci", "Overview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_MegaFoci: public Ui_D_MAKRO_MegaFoci {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_MEGAFOCI_H
