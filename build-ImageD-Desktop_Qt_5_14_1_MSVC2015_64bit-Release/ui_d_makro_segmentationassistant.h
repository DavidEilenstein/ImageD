/********************************************************************************
** Form generated from reading UI file 'd_makro_segmentationassistant.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_SEGMENTATIONASSISTANT_H
#define UI_D_MAKRO_SEGMENTATIONASSISTANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_SegmentationAssistant
{
public:
    QAction *action_Data_Add;
    QAction *action_Data_Clear;
    QAction *action_Data_Next;
    QAction *action_Data_Previous;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox_Step;
    QStackedWidget *stackedWidget_Step;
    QWidget *page_In;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton_In_Clear;
    QComboBox *comboBox_In_Images;
    QPushButton *pushButton_In_Add;
    QSpinBox *spinBox_In_PageDisplay;
    QWidget *page_Select_Page;
    QGridLayout *gridLayout_9;
    QLabel *label;
    QSpinBox *spinBox_Select_Page;
    QWidget *page_Select_Channel;
    QGridLayout *gridLayout_10;
    QLabel *label_5;
    QComboBox *comboBox_Select_Mono;
    QWidget *page_PreProc_Blur;
    QGridLayout *gridLayout_11;
    QLabel *label_2;
    QSpinBox *spinBox_Blur_Size;
    QDoubleSpinBox *doubleSpinBox_Blur_Sigma;
    QWidget *page_PreProc_Binary;
    QGridLayout *gridLayout_12;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_Binary_Thres;
    QWidget *page_PreProc_Segments;
    QGridLayout *gridLayout_13;
    QSpinBox *spinBox_Seg_Size;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_Seg_Sigma;
    QCheckBox *checkBox_Seg_ExclBorder;
    QCheckBox *checkBox_Seg_InclNonSeed;
    QWidget *page_Train_Re;
    QGridLayout *gridLayout_6;
    QLabel *label_9;
    QLabel *label_10;
    QWidget *page_Train_Merge;
    QGridLayout *gridLayout_7;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *page_Train_Sep;
    QGridLayout *gridLayout_14;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *page_Train_Kick;
    QGridLayout *gridLayout_15;
    QLabel *label_15;
    QLabel *label_16;
    QWidget *page_Out;
    QGridLayout *gridLayout_16;
    QLabel *label_17;
    QPushButton *pushButton_NextImage;
    QWidget *page_Inf_Merge;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QWidget *page_Inf_Sep;
    QGridLayout *gridLayout_4;
    QLabel *label_7;
    QWidget *page_Inf_Kick;
    QGridLayout *gridLayout_5;
    QLabel *label_8;
    QGraphicsView *graphicsView_Proc;
    QGroupBox *groupBox_2;
    QMenuBar *menubar;
    QMenu *menuData;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_SegmentationAssistant)
    {
        if (D_MAKRO_SegmentationAssistant->objectName().isEmpty())
            D_MAKRO_SegmentationAssistant->setObjectName(QString::fromUtf8("D_MAKRO_SegmentationAssistant"));
        D_MAKRO_SegmentationAssistant->resize(705, 698);
        action_Data_Add = new QAction(D_MAKRO_SegmentationAssistant);
        action_Data_Add->setObjectName(QString::fromUtf8("action_Data_Add"));
        action_Data_Clear = new QAction(D_MAKRO_SegmentationAssistant);
        action_Data_Clear->setObjectName(QString::fromUtf8("action_Data_Clear"));
        action_Data_Next = new QAction(D_MAKRO_SegmentationAssistant);
        action_Data_Next->setObjectName(QString::fromUtf8("action_Data_Next"));
        action_Data_Previous = new QAction(D_MAKRO_SegmentationAssistant);
        action_Data_Previous->setObjectName(QString::fromUtf8("action_Data_Previous"));
        centralwidget = new QWidget(D_MAKRO_SegmentationAssistant);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        comboBox_Step = new QComboBox(groupBox);
        comboBox_Step->setObjectName(QString::fromUtf8("comboBox_Step"));

        gridLayout_2->addWidget(comboBox_Step, 0, 0, 1, 1);

        stackedWidget_Step = new QStackedWidget(groupBox);
        stackedWidget_Step->setObjectName(QString::fromUtf8("stackedWidget_Step"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget_Step->sizePolicy().hasHeightForWidth());
        stackedWidget_Step->setSizePolicy(sizePolicy);
        page_In = new QWidget();
        page_In->setObjectName(QString::fromUtf8("page_In"));
        gridLayout_8 = new QGridLayout(page_In);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        pushButton_In_Clear = new QPushButton(page_In);
        pushButton_In_Clear->setObjectName(QString::fromUtf8("pushButton_In_Clear"));
        pushButton_In_Clear->setMinimumSize(QSize(74, 0));
        pushButton_In_Clear->setMaximumSize(QSize(74, 16777215));

        gridLayout_8->addWidget(pushButton_In_Clear, 0, 1, 1, 1);

        comboBox_In_Images = new QComboBox(page_In);
        comboBox_In_Images->setObjectName(QString::fromUtf8("comboBox_In_Images"));

        gridLayout_8->addWidget(comboBox_In_Images, 0, 3, 1, 1);

        pushButton_In_Add = new QPushButton(page_In);
        pushButton_In_Add->setObjectName(QString::fromUtf8("pushButton_In_Add"));
        pushButton_In_Add->setMinimumSize(QSize(74, 0));
        pushButton_In_Add->setMaximumSize(QSize(74, 16777215));

        gridLayout_8->addWidget(pushButton_In_Add, 0, 0, 1, 1);

        spinBox_In_PageDisplay = new QSpinBox(page_In);
        spinBox_In_PageDisplay->setObjectName(QString::fromUtf8("spinBox_In_PageDisplay"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox_In_PageDisplay->sizePolicy().hasHeightForWidth());
        spinBox_In_PageDisplay->setSizePolicy(sizePolicy1);
        spinBox_In_PageDisplay->setMinimumSize(QSize(40, 0));
        spinBox_In_PageDisplay->setMaximumSize(QSize(40, 16777215));
        spinBox_In_PageDisplay->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_8->addWidget(spinBox_In_PageDisplay, 0, 4, 1, 1);

        stackedWidget_Step->addWidget(page_In);
        page_Select_Page = new QWidget();
        page_Select_Page->setObjectName(QString::fromUtf8("page_Select_Page"));
        gridLayout_9 = new QGridLayout(page_Select_Page);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(page_Select_Page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(150, 0));
        label->setMaximumSize(QSize(150, 16777215));

        gridLayout_9->addWidget(label, 0, 0, 1, 1);

        spinBox_Select_Page = new QSpinBox(page_Select_Page);
        spinBox_Select_Page->setObjectName(QString::fromUtf8("spinBox_Select_Page"));

        gridLayout_9->addWidget(spinBox_Select_Page, 0, 1, 1, 1);

        stackedWidget_Step->addWidget(page_Select_Page);
        page_Select_Channel = new QWidget();
        page_Select_Channel->setObjectName(QString::fromUtf8("page_Select_Channel"));
        gridLayout_10 = new QGridLayout(page_Select_Channel);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(page_Select_Channel);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(150, 0));
        label_5->setMaximumSize(QSize(150, 16777215));

        gridLayout_10->addWidget(label_5, 0, 0, 1, 1);

        comboBox_Select_Mono = new QComboBox(page_Select_Channel);
        comboBox_Select_Mono->setObjectName(QString::fromUtf8("comboBox_Select_Mono"));

        gridLayout_10->addWidget(comboBox_Select_Mono, 0, 1, 1, 1);

        stackedWidget_Step->addWidget(page_Select_Channel);
        page_PreProc_Blur = new QWidget();
        page_PreProc_Blur->setObjectName(QString::fromUtf8("page_PreProc_Blur"));
        gridLayout_11 = new QGridLayout(page_PreProc_Blur);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(page_PreProc_Blur);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(150, 0));
        label_2->setMaximumSize(QSize(150, 16777215));

        gridLayout_11->addWidget(label_2, 0, 0, 1, 1);

        spinBox_Blur_Size = new QSpinBox(page_PreProc_Blur);
        spinBox_Blur_Size->setObjectName(QString::fromUtf8("spinBox_Blur_Size"));
        spinBox_Blur_Size->setMinimum(1);
        spinBox_Blur_Size->setMaximum(999);
        spinBox_Blur_Size->setSingleStep(2);
        spinBox_Blur_Size->setValue(3);

        gridLayout_11->addWidget(spinBox_Blur_Size, 0, 1, 1, 1);

        doubleSpinBox_Blur_Sigma = new QDoubleSpinBox(page_PreProc_Blur);
        doubleSpinBox_Blur_Sigma->setObjectName(QString::fromUtf8("doubleSpinBox_Blur_Sigma"));
        doubleSpinBox_Blur_Sigma->setSingleStep(5.000000000000000);
        doubleSpinBox_Blur_Sigma->setValue(1.000000000000000);

        gridLayout_11->addWidget(doubleSpinBox_Blur_Sigma, 0, 2, 1, 1);

        stackedWidget_Step->addWidget(page_PreProc_Blur);
        page_PreProc_Binary = new QWidget();
        page_PreProc_Binary->setObjectName(QString::fromUtf8("page_PreProc_Binary"));
        gridLayout_12 = new QGridLayout(page_PreProc_Binary);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(page_PreProc_Binary);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(150, 0));
        label_4->setMaximumSize(QSize(150, 16777215));

        gridLayout_12->addWidget(label_4, 0, 0, 1, 1);

        doubleSpinBox_Binary_Thres = new QDoubleSpinBox(page_PreProc_Binary);
        doubleSpinBox_Binary_Thres->setObjectName(QString::fromUtf8("doubleSpinBox_Binary_Thres"));
        doubleSpinBox_Binary_Thres->setMinimum(-999999999.000000000000000);
        doubleSpinBox_Binary_Thres->setMaximum(999999999.000000000000000);
        doubleSpinBox_Binary_Thres->setValue(127.000000000000000);

        gridLayout_12->addWidget(doubleSpinBox_Binary_Thres, 0, 1, 1, 1);

        stackedWidget_Step->addWidget(page_PreProc_Binary);
        page_PreProc_Segments = new QWidget();
        page_PreProc_Segments->setObjectName(QString::fromUtf8("page_PreProc_Segments"));
        gridLayout_13 = new QGridLayout(page_PreProc_Segments);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        spinBox_Seg_Size = new QSpinBox(page_PreProc_Segments);
        spinBox_Seg_Size->setObjectName(QString::fromUtf8("spinBox_Seg_Size"));
        spinBox_Seg_Size->setMinimum(1);
        spinBox_Seg_Size->setMaximum(999);
        spinBox_Seg_Size->setSingleStep(2);
        spinBox_Seg_Size->setValue(3);

        gridLayout_13->addWidget(spinBox_Seg_Size, 0, 1, 1, 1);

        label_3 = new QLabel(page_PreProc_Segments);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(150, 0));
        label_3->setMaximumSize(QSize(150, 16777215));

        gridLayout_13->addWidget(label_3, 0, 0, 1, 1);

        doubleSpinBox_Seg_Sigma = new QDoubleSpinBox(page_PreProc_Segments);
        doubleSpinBox_Seg_Sigma->setObjectName(QString::fromUtf8("doubleSpinBox_Seg_Sigma"));
        doubleSpinBox_Seg_Sigma->setSingleStep(5.000000000000000);
        doubleSpinBox_Seg_Sigma->setValue(1.000000000000000);

        gridLayout_13->addWidget(doubleSpinBox_Seg_Sigma, 0, 2, 1, 1);

        checkBox_Seg_ExclBorder = new QCheckBox(page_PreProc_Segments);
        checkBox_Seg_ExclBorder->setObjectName(QString::fromUtf8("checkBox_Seg_ExclBorder"));
        checkBox_Seg_ExclBorder->setChecked(true);

        gridLayout_13->addWidget(checkBox_Seg_ExclBorder, 0, 4, 1, 1);

        checkBox_Seg_InclNonSeed = new QCheckBox(page_PreProc_Segments);
        checkBox_Seg_InclNonSeed->setObjectName(QString::fromUtf8("checkBox_Seg_InclNonSeed"));
        checkBox_Seg_InclNonSeed->setChecked(true);

        gridLayout_13->addWidget(checkBox_Seg_InclNonSeed, 0, 3, 1, 1);

        stackedWidget_Step->addWidget(page_PreProc_Segments);
        page_Train_Re = new QWidget();
        page_Train_Re->setObjectName(QString::fromUtf8("page_Train_Re"));
        gridLayout_6 = new QGridLayout(page_Train_Re);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(page_Train_Re);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(150, 0));
        label_9->setMaximumSize(QSize(150, 16777215));

        gridLayout_6->addWidget(label_9, 0, 0, 1, 1);

        label_10 = new QLabel(page_Train_Re);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_6->addWidget(label_10, 0, 1, 1, 1);

        stackedWidget_Step->addWidget(page_Train_Re);
        page_Train_Merge = new QWidget();
        page_Train_Merge->setObjectName(QString::fromUtf8("page_Train_Merge"));
        gridLayout_7 = new QGridLayout(page_Train_Merge);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(page_Train_Merge);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(150, 0));
        label_11->setMaximumSize(QSize(150, 16777215));

        gridLayout_7->addWidget(label_11, 0, 0, 1, 1);

        label_12 = new QLabel(page_Train_Merge);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_7->addWidget(label_12, 0, 1, 1, 1);

        stackedWidget_Step->addWidget(page_Train_Merge);
        page_Train_Sep = new QWidget();
        page_Train_Sep->setObjectName(QString::fromUtf8("page_Train_Sep"));
        gridLayout_14 = new QGridLayout(page_Train_Sep);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(page_Train_Sep);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(150, 0));
        label_13->setMaximumSize(QSize(150, 16777215));

        gridLayout_14->addWidget(label_13, 0, 0, 1, 1);

        label_14 = new QLabel(page_Train_Sep);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_14->addWidget(label_14, 0, 1, 1, 1);

        stackedWidget_Step->addWidget(page_Train_Sep);
        page_Train_Kick = new QWidget();
        page_Train_Kick->setObjectName(QString::fromUtf8("page_Train_Kick"));
        gridLayout_15 = new QGridLayout(page_Train_Kick);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(page_Train_Kick);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(150, 0));
        label_15->setMaximumSize(QSize(150, 16777215));

        gridLayout_15->addWidget(label_15, 0, 0, 1, 1);

        label_16 = new QLabel(page_Train_Kick);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_15->addWidget(label_16, 0, 1, 1, 1);

        stackedWidget_Step->addWidget(page_Train_Kick);
        page_Out = new QWidget();
        page_Out->setObjectName(QString::fromUtf8("page_Out"));
        gridLayout_16 = new QGridLayout(page_Out);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(page_Out);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(150, 0));
        label_17->setMaximumSize(QSize(150, 16777215));

        gridLayout_16->addWidget(label_17, 0, 0, 1, 1);

        pushButton_NextImage = new QPushButton(page_Out);
        pushButton_NextImage->setObjectName(QString::fromUtf8("pushButton_NextImage"));

        gridLayout_16->addWidget(pushButton_NextImage, 0, 1, 1, 1);

        stackedWidget_Step->addWidget(page_Out);
        page_Inf_Merge = new QWidget();
        page_Inf_Merge->setObjectName(QString::fromUtf8("page_Inf_Merge"));
        gridLayout_3 = new QGridLayout(page_Inf_Merge);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(page_Inf_Merge);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        stackedWidget_Step->addWidget(page_Inf_Merge);
        page_Inf_Sep = new QWidget();
        page_Inf_Sep->setObjectName(QString::fromUtf8("page_Inf_Sep"));
        gridLayout_4 = new QGridLayout(page_Inf_Sep);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(page_Inf_Sep);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);

        stackedWidget_Step->addWidget(page_Inf_Sep);
        page_Inf_Kick = new QWidget();
        page_Inf_Kick->setObjectName(QString::fromUtf8("page_Inf_Kick"));
        gridLayout_5 = new QGridLayout(page_Inf_Kick);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(page_Inf_Kick);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_5->addWidget(label_8, 0, 0, 1, 1);

        stackedWidget_Step->addWidget(page_Inf_Kick);

        gridLayout_2->addWidget(stackedWidget_Step, 1, 0, 1, 1);

        graphicsView_Proc = new QGraphicsView(groupBox);
        graphicsView_Proc->setObjectName(QString::fromUtf8("graphicsView_Proc"));

        gridLayout_2->addWidget(graphicsView_Proc, 2, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));

        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        D_MAKRO_SegmentationAssistant->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_SegmentationAssistant);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 705, 21));
        menuData = new QMenu(menubar);
        menuData->setObjectName(QString::fromUtf8("menuData"));
        D_MAKRO_SegmentationAssistant->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_SegmentationAssistant);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_SegmentationAssistant->setStatusBar(statusbar);

        menubar->addAction(menuData->menuAction());
        menuData->addAction(action_Data_Add);
        menuData->addAction(action_Data_Clear);
        menuData->addAction(action_Data_Next);
        menuData->addAction(action_Data_Previous);

        retranslateUi(D_MAKRO_SegmentationAssistant);
        QObject::connect(comboBox_Step, SIGNAL(currentIndexChanged(int)), stackedWidget_Step, SLOT(setCurrentIndex(int)));

        stackedWidget_Step->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(D_MAKRO_SegmentationAssistant);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_SegmentationAssistant)
    {
        D_MAKRO_SegmentationAssistant->setWindowTitle(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "MainWindow", nullptr));
        action_Data_Add->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Add", nullptr));
#if QT_CONFIG(shortcut)
        action_Data_Add->setShortcut(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Data_Clear->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Clear", nullptr));
        action_Data_Next->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Next", nullptr));
#if QT_CONFIG(shortcut)
        action_Data_Next->setShortcut(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Space", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Data_Previous->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Previous", nullptr));
#if QT_CONFIG(shortcut)
        action_Data_Previous->setShortcut(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Ctrl+Space", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox->setTitle(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Processing", nullptr));
        pushButton_In_Clear->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Clear", nullptr));
        pushButton_In_Add->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Add", nullptr));
#if QT_CONFIG(tooltip)
        spinBox_In_PageDisplay->setToolTip(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "<html><head/><body><p>Displayed Page</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        spinBox_In_PageDisplay->setPrefix(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "p=", nullptr));
        label->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Page:", nullptr));
        label_5->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Color to Mono:", nullptr));
        label_2->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Blur (Size/Sigma):", nullptr));
        label_4->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Binarization (Thresh):", nullptr));
        label_3->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Segmentation (Size/Sigma):", nullptr));
        checkBox_Seg_ExclBorder->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Exclude border", nullptr));
        checkBox_Seg_InclNonSeed->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Include non seeded", nullptr));
        label_9->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Click Left Double:", nullptr));
        label_10->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Recover object", nullptr));
        label_11->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Click Left:", nullptr));
        label_12->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Merge objects", nullptr));
        label_13->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Click Right:", nullptr));
        label_14->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Separate objects", nullptr));
        label_15->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Click Right Double:", nullptr));
        label_16->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Kick object", nullptr));
        label_17->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Output Segmentation", nullptr));
        pushButton_NextImage->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Next Image (Space)", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_NextImage->setShortcut(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Space", nullptr));
#endif // QT_CONFIG(shortcut)
        label_6->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Machine-learned automatic merging", nullptr));
        label_7->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Machine-learned automatic separation", nullptr));
        label_8->setText(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Machine-learned automatic kicking", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Results", nullptr));
        menuData->setTitle(QCoreApplication::translate("D_MAKRO_SegmentationAssistant", "Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_SegmentationAssistant: public Ui_D_MAKRO_SegmentationAssistant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_SEGMENTATIONASSISTANT_H
