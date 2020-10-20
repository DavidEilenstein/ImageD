/********************************************************************************
** Form generated from reading UI file 'd_makro_airdragtrack.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_AIRDRAGTRACK_H
#define UI_D_MAKRO_AIRDRAGTRACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
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
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_AirDragTrack
{
public:
    QAction *action_Data_Add;
    QAction *action_Data_Clear;
    QAction *action_View_Results_Big;
    QAction *action_Save_Screenshot_Full_Window;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_In;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QGraphicsView *graphicsView_Proc_Crop;
    QGraphicsView *graphicsView_Proc_Thres;
    QGraphicsView *graphicsView_Proc_ExBorder;
    QGraphicsView *graphicsView_Proc_Gray;
    QGraphicsView *graphicsView_Proc_Blur;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QSpinBox *spinBox_T_Frame;
    QGroupBox *groupBox_ProcSettings;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox_Color2Mono;
    QLabel *label_2;
    QSpinBox *spinBox_CropStart;
    QLabel *label_4;
    QSpinBox *spinBox_AreaMin;
    QLabel *label_7;
    QLabel *label_6;
    QSpinBox *spinBox_BlurSize;
    QLabel *label_5;
    QSpinBox *spinBox_CropWidth;
    QLabel *label;
    QSpinBox *spinBox_AreaMax;
    QDoubleSpinBox *doubleSpinBox_Thresh;
    QSpinBox *spinBox_CropEnd;
    QSpinBox *spinBox_CropTop;
    QSpinBox *spinBox_CropLeft;
    QLabel *label_3;
    QSpinBox *spinBox_CropHeight;
    QDoubleSpinBox *doubleSpinBox_BlurSigma;
    QLabel *label_8;
    QSpinBox *spinBox_BlurFrames;
    QLabel *label_9;
    QSpinBox *spinBox_FramesInARow;
    QDoubleSpinBox *doubleSpinBox_T_Sec;
    QSlider *horizontalSlider_T_Frame;
    QPushButton *pushButton_ProcVideo;
    QPushButton *pushButton_ProcAllVideos;
    QComboBox *comboBox_DataInput;
    QGroupBox *groupBox_Out;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_S1;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_S1;
    QGroupBox *groupBox_S2;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_S2;
    QGroupBox *groupBox_S0;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_S0;
    QGroupBox *groupBox_Results;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_ResultsAll;
    QComboBox *comboBox_Results;
    QGroupBox *groupBox_S3;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_S3;
    QGroupBox *groupBox_S4;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_S4;
    QMenuBar *menubar;
    QMenu *menuData;
    QMenu *menuView;
    QMenu *menuScreenshot;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_AirDragTrack)
    {
        if (D_MAKRO_AirDragTrack->objectName().isEmpty())
            D_MAKRO_AirDragTrack->setObjectName(QString::fromUtf8("D_MAKRO_AirDragTrack"));
        D_MAKRO_AirDragTrack->resize(1002, 770);
        action_Data_Add = new QAction(D_MAKRO_AirDragTrack);
        action_Data_Add->setObjectName(QString::fromUtf8("action_Data_Add"));
        action_Data_Clear = new QAction(D_MAKRO_AirDragTrack);
        action_Data_Clear->setObjectName(QString::fromUtf8("action_Data_Clear"));
        action_View_Results_Big = new QAction(D_MAKRO_AirDragTrack);
        action_View_Results_Big->setObjectName(QString::fromUtf8("action_View_Results_Big"));
        action_View_Results_Big->setCheckable(true);
        action_Save_Screenshot_Full_Window = new QAction(D_MAKRO_AirDragTrack);
        action_Save_Screenshot_Full_Window->setObjectName(QString::fromUtf8("action_Save_Screenshot_Full_Window"));
        centralwidget = new QWidget(D_MAKRO_AirDragTrack);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_In = new QGroupBox(centralwidget);
        groupBox_In->setObjectName(QString::fromUtf8("groupBox_In"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_In->sizePolicy().hasHeightForWidth());
        groupBox_In->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox_In);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(groupBox_In);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(6, 6, 6, 6);
        graphicsView_Proc_Crop = new QGraphicsView(groupBox);
        graphicsView_Proc_Crop->setObjectName(QString::fromUtf8("graphicsView_Proc_Crop"));

        gridLayout_5->addWidget(graphicsView_Proc_Crop, 1, 0, 1, 1);

        graphicsView_Proc_Thres = new QGraphicsView(groupBox);
        graphicsView_Proc_Thres->setObjectName(QString::fromUtf8("graphicsView_Proc_Thres"));

        gridLayout_5->addWidget(graphicsView_Proc_Thres, 1, 3, 1, 1);

        graphicsView_Proc_ExBorder = new QGraphicsView(groupBox);
        graphicsView_Proc_ExBorder->setObjectName(QString::fromUtf8("graphicsView_Proc_ExBorder"));

        gridLayout_5->addWidget(graphicsView_Proc_ExBorder, 1, 4, 1, 1);

        graphicsView_Proc_Gray = new QGraphicsView(groupBox);
        graphicsView_Proc_Gray->setObjectName(QString::fromUtf8("graphicsView_Proc_Gray"));

        gridLayout_5->addWidget(graphicsView_Proc_Gray, 1, 1, 1, 1);

        graphicsView_Proc_Blur = new QGraphicsView(groupBox);
        graphicsView_Proc_Blur->setObjectName(QString::fromUtf8("graphicsView_Proc_Blur"));

        gridLayout_5->addWidget(graphicsView_Proc_Blur, 1, 2, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_5->addWidget(label_10, 0, 0, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_5->addWidget(label_11, 0, 1, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_5->addWidget(label_12, 0, 2, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_5->addWidget(label_13, 0, 3, 1, 1);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_5->addWidget(label_14, 0, 4, 1, 1);


        gridLayout_2->addWidget(groupBox, 2, 0, 1, 3);

        spinBox_T_Frame = new QSpinBox(groupBox_In);
        spinBox_T_Frame->setObjectName(QString::fromUtf8("spinBox_T_Frame"));

        gridLayout_2->addWidget(spinBox_T_Frame, 3, 1, 1, 1);

        groupBox_ProcSettings = new QGroupBox(groupBox_In);
        groupBox_ProcSettings->setObjectName(QString::fromUtf8("groupBox_ProcSettings"));
        gridLayout_3 = new QGridLayout(groupBox_ProcSettings);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(6, 6, 6, 6);
        comboBox_Color2Mono = new QComboBox(groupBox_ProcSettings);
        comboBox_Color2Mono->setObjectName(QString::fromUtf8("comboBox_Color2Mono"));

        gridLayout_3->addWidget(comboBox_Color2Mono, 4, 2, 1, 4);

        label_2 = new QLabel(groupBox_ProcSettings);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 6, 1, 1, 1);

        spinBox_CropStart = new QSpinBox(groupBox_ProcSettings);
        spinBox_CropStart->setObjectName(QString::fromUtf8("spinBox_CropStart"));
        spinBox_CropStart->setEnabled(true);
        spinBox_CropStart->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_3->addWidget(spinBox_CropStart, 8, 2, 1, 2);

        label_4 = new QLabel(groupBox_ProcSettings);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 4, 1, 1, 1);

        spinBox_AreaMin = new QSpinBox(groupBox_ProcSettings);
        spinBox_AreaMin->setObjectName(QString::fromUtf8("spinBox_AreaMin"));
        spinBox_AreaMin->setEnabled(true);
        spinBox_AreaMin->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_AreaMin->setMinimum(0);
        spinBox_AreaMin->setMaximum(999999999);
        spinBox_AreaMin->setValue(50);

        gridLayout_3->addWidget(spinBox_AreaMin, 10, 2, 1, 2);

        label_7 = new QLabel(groupBox_ProcSettings);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setEnabled(true);

        gridLayout_3->addWidget(label_7, 8, 1, 1, 1);

        label_6 = new QLabel(groupBox_ProcSettings);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 2, 1, 1, 1);

        spinBox_BlurSize = new QSpinBox(groupBox_ProcSettings);
        spinBox_BlurSize->setObjectName(QString::fromUtf8("spinBox_BlurSize"));
        spinBox_BlurSize->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_BlurSize->setMinimum(1);
        spinBox_BlurSize->setSingleStep(2);
        spinBox_BlurSize->setValue(7);

        gridLayout_3->addWidget(spinBox_BlurSize, 5, 2, 1, 2);

        label_5 = new QLabel(groupBox_ProcSettings);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 1, 1, 1, 1);

        spinBox_CropWidth = new QSpinBox(groupBox_ProcSettings);
        spinBox_CropWidth->setObjectName(QString::fromUtf8("spinBox_CropWidth"));
        spinBox_CropWidth->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_CropWidth->setMaximum(999999);
        spinBox_CropWidth->setValue(195);

        gridLayout_3->addWidget(spinBox_CropWidth, 2, 4, 1, 2);

        label = new QLabel(groupBox_ProcSettings);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 5, 1, 1, 1);

        spinBox_AreaMax = new QSpinBox(groupBox_ProcSettings);
        spinBox_AreaMax->setObjectName(QString::fromUtf8("spinBox_AreaMax"));
        spinBox_AreaMax->setEnabled(true);
        spinBox_AreaMax->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_AreaMax->setMaximum(999999999);
        spinBox_AreaMax->setValue(999999999);

        gridLayout_3->addWidget(spinBox_AreaMax, 10, 4, 1, 2);

        doubleSpinBox_Thresh = new QDoubleSpinBox(groupBox_ProcSettings);
        doubleSpinBox_Thresh->setObjectName(QString::fromUtf8("doubleSpinBox_Thresh"));
        doubleSpinBox_Thresh->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Thresh->setDecimals(0);
        doubleSpinBox_Thresh->setMaximum(255.000000000000000);
        doubleSpinBox_Thresh->setValue(127.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_Thresh, 6, 2, 1, 4);

        spinBox_CropEnd = new QSpinBox(groupBox_ProcSettings);
        spinBox_CropEnd->setObjectName(QString::fromUtf8("spinBox_CropEnd"));
        spinBox_CropEnd->setEnabled(true);
        spinBox_CropEnd->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_3->addWidget(spinBox_CropEnd, 8, 4, 1, 2);

        spinBox_CropTop = new QSpinBox(groupBox_ProcSettings);
        spinBox_CropTop->setObjectName(QString::fromUtf8("spinBox_CropTop"));
        spinBox_CropTop->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_CropTop->setMaximum(999999);
        spinBox_CropTop->setValue(180);

        gridLayout_3->addWidget(spinBox_CropTop, 1, 2, 1, 2);

        spinBox_CropLeft = new QSpinBox(groupBox_ProcSettings);
        spinBox_CropLeft->setObjectName(QString::fromUtf8("spinBox_CropLeft"));
        spinBox_CropLeft->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_CropLeft->setMaximum(999999);
        spinBox_CropLeft->setValue(321);

        gridLayout_3->addWidget(spinBox_CropLeft, 2, 2, 1, 2);

        label_3 = new QLabel(groupBox_ProcSettings);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(true);

        gridLayout_3->addWidget(label_3, 10, 1, 1, 1);

        spinBox_CropHeight = new QSpinBox(groupBox_ProcSettings);
        spinBox_CropHeight->setObjectName(QString::fromUtf8("spinBox_CropHeight"));
        spinBox_CropHeight->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_CropHeight->setMaximum(999999);
        spinBox_CropHeight->setValue(990);

        gridLayout_3->addWidget(spinBox_CropHeight, 1, 4, 1, 2);

        doubleSpinBox_BlurSigma = new QDoubleSpinBox(groupBox_ProcSettings);
        doubleSpinBox_BlurSigma->setObjectName(QString::fromUtf8("doubleSpinBox_BlurSigma"));
        doubleSpinBox_BlurSigma->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_BlurSigma->setSingleStep(0.250000000000000);
        doubleSpinBox_BlurSigma->setValue(3.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_BlurSigma, 5, 4, 1, 2);

        label_8 = new QLabel(groupBox_ProcSettings);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 11, 1, 1, 1);

        spinBox_BlurFrames = new QSpinBox(groupBox_ProcSettings);
        spinBox_BlurFrames->setObjectName(QString::fromUtf8("spinBox_BlurFrames"));
        spinBox_BlurFrames->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_BlurFrames->setMinimum(1);
        spinBox_BlurFrames->setSingleStep(2);
        spinBox_BlurFrames->setValue(15);

        gridLayout_3->addWidget(spinBox_BlurFrames, 11, 2, 1, 4);

        label_9 = new QLabel(groupBox_ProcSettings);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 9, 1, 1, 1);

        spinBox_FramesInARow = new QSpinBox(groupBox_ProcSettings);
        spinBox_FramesInARow->setObjectName(QString::fromUtf8("spinBox_FramesInARow"));
        spinBox_FramesInARow->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_FramesInARow->setMinimum(1);
        spinBox_FramesInARow->setMaximum(999);
        spinBox_FramesInARow->setValue(10);

        gridLayout_3->addWidget(spinBox_FramesInARow, 9, 2, 1, 4);


        gridLayout_2->addWidget(groupBox_ProcSettings, 4, 0, 1, 3);

        doubleSpinBox_T_Sec = new QDoubleSpinBox(groupBox_In);
        doubleSpinBox_T_Sec->setObjectName(QString::fromUtf8("doubleSpinBox_T_Sec"));

        gridLayout_2->addWidget(doubleSpinBox_T_Sec, 3, 2, 1, 1);

        horizontalSlider_T_Frame = new QSlider(groupBox_In);
        horizontalSlider_T_Frame->setObjectName(QString::fromUtf8("horizontalSlider_T_Frame"));
        horizontalSlider_T_Frame->setMaximum(999);
        horizontalSlider_T_Frame->setOrientation(Qt::Horizontal);
        horizontalSlider_T_Frame->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_T_Frame->setTickInterval(100);

        gridLayout_2->addWidget(horizontalSlider_T_Frame, 3, 0, 1, 1);

        pushButton_ProcVideo = new QPushButton(groupBox_In);
        pushButton_ProcVideo->setObjectName(QString::fromUtf8("pushButton_ProcVideo"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_ProcVideo->sizePolicy().hasHeightForWidth());
        pushButton_ProcVideo->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushButton_ProcVideo, 0, 1, 1, 1);

        pushButton_ProcAllVideos = new QPushButton(groupBox_In);
        pushButton_ProcAllVideos->setObjectName(QString::fromUtf8("pushButton_ProcAllVideos"));
        sizePolicy1.setHeightForWidth(pushButton_ProcAllVideos->sizePolicy().hasHeightForWidth());
        pushButton_ProcAllVideos->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushButton_ProcAllVideos, 0, 2, 1, 1);

        comboBox_DataInput = new QComboBox(groupBox_In);
        comboBox_DataInput->setObjectName(QString::fromUtf8("comboBox_DataInput"));

        gridLayout_2->addWidget(comboBox_DataInput, 0, 0, 2, 1);


        gridLayout->addWidget(groupBox_In, 0, 0, 1, 1);

        groupBox_Out = new QGroupBox(centralwidget);
        groupBox_Out->setObjectName(QString::fromUtf8("groupBox_Out"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_Out->sizePolicy().hasHeightForWidth());
        groupBox_Out->setSizePolicy(sizePolicy2);
        gridLayout_4 = new QGridLayout(groupBox_Out);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_S1 = new QGroupBox(groupBox_Out);
        groupBox_S1->setObjectName(QString::fromUtf8("groupBox_S1"));
        groupBox_S1->setFlat(true);
        gridLayout_9 = new QGridLayout(groupBox_S1);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        gridLayout_S1 = new QGridLayout();
        gridLayout_S1->setObjectName(QString::fromUtf8("gridLayout_S1"));

        gridLayout_9->addLayout(gridLayout_S1, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_S1, 1, 1, 1, 1);

        groupBox_S2 = new QGroupBox(groupBox_Out);
        groupBox_S2->setObjectName(QString::fromUtf8("groupBox_S2"));
        groupBox_S2->setFlat(true);
        gridLayout_11 = new QGridLayout(groupBox_S2);
        gridLayout_11->setSpacing(0);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        gridLayout_S2 = new QGridLayout();
        gridLayout_S2->setObjectName(QString::fromUtf8("gridLayout_S2"));

        gridLayout_11->addLayout(gridLayout_S2, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_S2, 2, 1, 1, 1);

        groupBox_S0 = new QGroupBox(groupBox_Out);
        groupBox_S0->setObjectName(QString::fromUtf8("groupBox_S0"));
        groupBox_S0->setFlat(true);
        gridLayout_6 = new QGridLayout(groupBox_S0);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        gridLayout_S0 = new QGridLayout();
        gridLayout_S0->setObjectName(QString::fromUtf8("gridLayout_S0"));

        gridLayout_6->addLayout(gridLayout_S0, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_S0, 0, 1, 1, 1);

        groupBox_Results = new QGroupBox(groupBox_Out);
        groupBox_Results->setObjectName(QString::fromUtf8("groupBox_Results"));
        groupBox_Results->setFlat(true);
        gridLayout_7 = new QGridLayout(groupBox_Results);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_ResultsAll = new QGridLayout();
        gridLayout_ResultsAll->setObjectName(QString::fromUtf8("gridLayout_ResultsAll"));

        gridLayout_7->addLayout(gridLayout_ResultsAll, 1, 0, 1, 1);

        comboBox_Results = new QComboBox(groupBox_Results);
        comboBox_Results->setObjectName(QString::fromUtf8("comboBox_Results"));

        gridLayout_7->addWidget(comboBox_Results, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_Results, 2, 2, 1, 1);

        groupBox_S3 = new QGroupBox(groupBox_Out);
        groupBox_S3->setObjectName(QString::fromUtf8("groupBox_S3"));
        groupBox_S3->setFlat(true);
        gridLayout_8 = new QGridLayout(groupBox_S3);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        gridLayout_S3 = new QGridLayout();
        gridLayout_S3->setObjectName(QString::fromUtf8("gridLayout_S3"));

        gridLayout_8->addLayout(gridLayout_S3, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_S3, 0, 2, 1, 1);

        groupBox_S4 = new QGroupBox(groupBox_Out);
        groupBox_S4->setObjectName(QString::fromUtf8("groupBox_S4"));
        groupBox_S4->setFlat(true);
        gridLayout_10 = new QGridLayout(groupBox_S4);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        gridLayout_S4 = new QGridLayout();
        gridLayout_S4->setObjectName(QString::fromUtf8("gridLayout_S4"));

        gridLayout_10->addLayout(gridLayout_S4, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_S4, 1, 2, 1, 1);


        gridLayout->addWidget(groupBox_Out, 0, 1, 1, 1);

        D_MAKRO_AirDragTrack->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_AirDragTrack);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1002, 21));
        menuData = new QMenu(menubar);
        menuData->setObjectName(QString::fromUtf8("menuData"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuScreenshot = new QMenu(menubar);
        menuScreenshot->setObjectName(QString::fromUtf8("menuScreenshot"));
        D_MAKRO_AirDragTrack->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_AirDragTrack);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_AirDragTrack->setStatusBar(statusbar);

        menubar->addAction(menuData->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuScreenshot->menuAction());
        menuData->addAction(action_Data_Add);
        menuData->addAction(action_Data_Clear);
        menuView->addAction(action_View_Results_Big);
        menuScreenshot->addAction(action_Save_Screenshot_Full_Window);

        retranslateUi(D_MAKRO_AirDragTrack);

        QMetaObject::connectSlotsByName(D_MAKRO_AirDragTrack);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_AirDragTrack)
    {
        D_MAKRO_AirDragTrack->setWindowTitle(QCoreApplication::translate("D_MAKRO_AirDragTrack", "MainWindow", nullptr));
        action_Data_Add->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Add", nullptr));
#if QT_CONFIG(shortcut)
        action_Data_Add->setShortcut(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Data_Clear->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Clear", nullptr));
        action_View_Results_Big->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "View Results Big", nullptr));
#if QT_CONFIG(shortcut)
        action_View_Results_Big->setShortcut(QCoreApplication::translate("D_MAKRO_AirDragTrack", "F8", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Save_Screenshot_Full_Window->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Save Screenshot Full Window", nullptr));
#if QT_CONFIG(shortcut)
        action_Save_Screenshot_Full_Window->setShortcut(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_In->setTitle(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Input", nullptr));
        groupBox->setTitle(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Image Processing", nullptr));
        label_10->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Crop", nullptr));
        label_11->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Gray", nullptr));
        label_12->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Blur", nullptr));
        label_13->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Thres", nullptr));
        label_14->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Excl. Border", nullptr));
        spinBox_T_Frame->setPrefix(QCoreApplication::translate("D_MAKRO_AirDragTrack", "frame: ", nullptr));
        groupBox_ProcSettings->setTitle(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Parameters", nullptr));
        label_2->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Thresh", nullptr));
        spinBox_CropStart->setPrefix(QCoreApplication::translate("D_MAKRO_AirDragTrack", "frame ", nullptr));
        label_4->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Color to Mono", nullptr));
        spinBox_AreaMin->setSuffix(QCoreApplication::translate("D_MAKRO_AirDragTrack", " px", nullptr));
        label_7->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Analyse Frames", nullptr));
        label_6->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Crop Left/Width", nullptr));
        spinBox_BlurSize->setSuffix(QCoreApplication::translate("D_MAKRO_AirDragTrack", " px", nullptr));
        label_5->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Crop Top/Height", nullptr));
        spinBox_CropWidth->setSuffix(QCoreApplication::translate("D_MAKRO_AirDragTrack", " px", nullptr));
        label->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Space Blur", nullptr));
        spinBox_AreaMax->setSuffix(QCoreApplication::translate("D_MAKRO_AirDragTrack", " px", nullptr));
        doubleSpinBox_Thresh->setSuffix(QCoreApplication::translate("D_MAKRO_AirDragTrack", " GVU", nullptr));
        spinBox_CropEnd->setPrefix(QCoreApplication::translate("D_MAKRO_AirDragTrack", "frame ", nullptr));
        spinBox_CropTop->setSuffix(QCoreApplication::translate("D_MAKRO_AirDragTrack", " px", nullptr));
        spinBox_CropLeft->setSuffix(QCoreApplication::translate("D_MAKRO_AirDragTrack", " px", nullptr));
        label_3->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Area Filter", nullptr));
        spinBox_CropHeight->setSuffix(QCoreApplication::translate("D_MAKRO_AirDragTrack", " px", nullptr));
        label_8->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Time Blur", nullptr));
        spinBox_BlurFrames->setSuffix(QCoreApplication::translate("D_MAKRO_AirDragTrack", " frames", nullptr));
        label_9->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Min. frames in row", nullptr));
        spinBox_FramesInARow->setSuffix(QCoreApplication::translate("D_MAKRO_AirDragTrack", " frames", nullptr));
        doubleSpinBox_T_Sec->setPrefix(QCoreApplication::translate("D_MAKRO_AirDragTrack", "time: ", nullptr));
        doubleSpinBox_T_Sec->setSuffix(QCoreApplication::translate("D_MAKRO_AirDragTrack", "s", nullptr));
        pushButton_ProcVideo->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Do It", nullptr));
        pushButton_ProcAllVideos->setText(QCoreApplication::translate("D_MAKRO_AirDragTrack", "All of it!", nullptr));
        groupBox_Out->setTitle(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Output", nullptr));
        groupBox_S1->setTitle(QString());
        groupBox_S2->setTitle(QString());
        groupBox_S0->setTitle(QString());
        groupBox_Results->setTitle(QString());
        groupBox_S3->setTitle(QString());
        groupBox_S4->setTitle(QString());
        menuData->setTitle(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Data", nullptr));
        menuView->setTitle(QCoreApplication::translate("D_MAKRO_AirDragTrack", "View", nullptr));
        menuScreenshot->setTitle(QCoreApplication::translate("D_MAKRO_AirDragTrack", "Screenshot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_AirDragTrack: public Ui_D_MAKRO_AirDragTrack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_AIRDRAGTRACK_H
