/********************************************************************************
** Form generated from reading UI file 'd_makro_visualization.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_VISUALIZATION_H
#define UI_D_MAKRO_VISUALIZATION_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_Visualization
{
public:
    QAction *action_Add_Images;
    QAction *action_Clear_Stack;
    QAction *action_Save_Single;
    QAction *action_Save_Stack;
    QAction *action_AutoValRange;
    QAction *actionMinimum;
    QAction *actionNormal;
    QAction *actionMaximum;
    QAction *actionFullscreen;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_Page;
    QGridLayout *gridLayout_5;
    QGraphicsView *graphicsView_Page;
    QComboBox *comboBox_Page;
    QFrame *line;
    QHBoxLayout *horizontalLayout_PageInfo;
    QLabel *label_PageInfo_ValAtCursor;
    QLabel *label_PageInfo_Range;
    QLabel *label_PageInfo_Size;
    QComboBox *comboBox_ViewImgType;
    QGroupBox *groupBox_Processing;
    QGridLayout *gridLayout_7;
    QComboBox *comboBox_Processing;
    QStackedWidget *stackedWidget_Processing;
    QWidget *page_Skip;
    QGridLayout *gridLayout_15;
    QLabel *label_Bin_Skip;
    QSpacerItem *verticalSpacer_Bin_Skip;
    QWidget *page_Copy;
    QGridLayout *gridLayout_14;
    QLabel *label_Bin_Copy;
    QSpacerItem *verticalSpacer_Bin_Copy;
    QWidget *page_Binary;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_Bin_Smooth;
    QGridLayout *gridLayout_9;
    QLabel *label_2;
    QSpinBox *spinBox_Bin_Size;
    QDoubleSpinBox *doubleSpinBox_Bin_Sigma;
    QGroupBox *groupBox_Binarization;
    QGridLayout *gridLayout_11;
    QDoubleSpinBox *doubleSpinBox_Bin_Threshold;
    QLabel *label_3;
    QGroupBox *groupBox_Bin_Segmentation;
    QGridLayout *gridLayout_8;
    QCheckBox *checkBox_Bin_InclBorder;
    QCheckBox *checkBox_Bin_InclNonSeed;
    QDoubleSpinBox *doubleSpinBox_Bin_Distance;
    QLabel *label;
    QGroupBox *groupBox_Reduce;
    QGridLayout *gridLayout_10;
    QComboBox *comboBox_Bin_Geometric;
    QGroupBox *groupBox_Bin_Paint;
    QGridLayout *gridLayout_16;
    QSpinBox *spinBox_Bin_Paint_Width;
    QComboBox *comboBox_Bin_Paint_Type;
    QPushButton *pushButton_Bin_Paint_Reset;
    QComboBox *comboBox_Bin_Paint_FG_BG;
    QWidget *page_Values;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_12;
    QSpacerItem *verticalSpacer;
    QDoubleSpinBox *doubleSpinBox_Val_Out_Max;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_Val_Out_Min;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_Val_Gamma;
    QDoubleSpinBox *doubleSpinBox_Val_In_Min;
    QDoubleSpinBox *doubleSpinBox_Val_In_Max;
    QLabel *label_7;
    QLabel *label_8;
    QGroupBox *groupBox_Color;
    QGridLayout *gridLayout_6;
    QLabel *label_Color_G;
    QLabel *label_Color_Preview;
    QLabel *label_Color_B;
    QLabel *label_Color_R;
    QLabel *label_Color_Alpha;
    QSpinBox *spinBox_Color_Red;
    QSpinBox *spinBox_Color_Green;
    QPushButton *pushButton_ColorSet;
    QSpinBox *spinBox_Color_Blue;
    QSpinBox *spinBox_Color_Alpha;
    QGroupBox *groupBox_Image;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_Add;
    QPushButton *pushButton_Clear;
    QComboBox *comboBox_Image;
    QGroupBox *groupBox_Output;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_SaveStack;
    QGraphicsView *graphicsView_Output;
    QPushButton *pushButton_SaveSingle;
    QGroupBox *groupBox_Scalebar;
    QGridLayout *gridLayout_17;
    QDoubleSpinBox *doubleSpinBox_Scalebar_Barsize;
    QLabel *label_Scalebar_Pixel;
    QDoubleSpinBox *doubleSpinBox_Scalebar_Pixelsize;
    QFrame *line_Scalebar_1;
    QLineEdit *lineEdit_Scalebar_Unit;
    QFrame *line_Scalebar_2;
    QLabel *label_Scalebar_Unit;
    QLabel *label_Scalebar_Bar;
    QMenuBar *menubar;
    QMenu *menuData;
    QMenu *menuMakros;
    QMenu *menuWindow;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_Visualization)
    {
        if (D_MAKRO_Visualization->objectName().isEmpty())
            D_MAKRO_Visualization->setObjectName(QString::fromUtf8("D_MAKRO_Visualization"));
        D_MAKRO_Visualization->resize(1169, 820);
        action_Add_Images = new QAction(D_MAKRO_Visualization);
        action_Add_Images->setObjectName(QString::fromUtf8("action_Add_Images"));
        action_Clear_Stack = new QAction(D_MAKRO_Visualization);
        action_Clear_Stack->setObjectName(QString::fromUtf8("action_Clear_Stack"));
        action_Clear_Stack->setEnabled(false);
        action_Save_Single = new QAction(D_MAKRO_Visualization);
        action_Save_Single->setObjectName(QString::fromUtf8("action_Save_Single"));
        action_Save_Single->setEnabled(false);
        action_Save_Stack = new QAction(D_MAKRO_Visualization);
        action_Save_Stack->setObjectName(QString::fromUtf8("action_Save_Stack"));
        action_Save_Stack->setEnabled(false);
        action_AutoValRange = new QAction(D_MAKRO_Visualization);
        action_AutoValRange->setObjectName(QString::fromUtf8("action_AutoValRange"));
        actionMinimum = new QAction(D_MAKRO_Visualization);
        actionMinimum->setObjectName(QString::fromUtf8("actionMinimum"));
        actionNormal = new QAction(D_MAKRO_Visualization);
        actionNormal->setObjectName(QString::fromUtf8("actionNormal"));
        actionMaximum = new QAction(D_MAKRO_Visualization);
        actionMaximum->setObjectName(QString::fromUtf8("actionMaximum"));
        actionFullscreen = new QAction(D_MAKRO_Visualization);
        actionFullscreen->setObjectName(QString::fromUtf8("actionFullscreen"));
        centralwidget = new QWidget(D_MAKRO_Visualization);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_Page = new QGroupBox(centralwidget);
        groupBox_Page->setObjectName(QString::fromUtf8("groupBox_Page"));
        groupBox_Page->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_Page->sizePolicy().hasHeightForWidth());
        groupBox_Page->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(groupBox_Page);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        graphicsView_Page = new QGraphicsView(groupBox_Page);
        graphicsView_Page->setObjectName(QString::fromUtf8("graphicsView_Page"));
        graphicsView_Page->setMouseTracking(true);

        gridLayout_5->addWidget(graphicsView_Page, 1, 0, 1, 2);

        comboBox_Page = new QComboBox(groupBox_Page);
        comboBox_Page->setObjectName(QString::fromUtf8("comboBox_Page"));

        gridLayout_5->addWidget(comboBox_Page, 0, 0, 1, 2);

        line = new QFrame(groupBox_Page);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line, 3, 0, 1, 2);

        horizontalLayout_PageInfo = new QHBoxLayout();
        horizontalLayout_PageInfo->setObjectName(QString::fromUtf8("horizontalLayout_PageInfo"));
        label_PageInfo_ValAtCursor = new QLabel(groupBox_Page);
        label_PageInfo_ValAtCursor->setObjectName(QString::fromUtf8("label_PageInfo_ValAtCursor"));

        horizontalLayout_PageInfo->addWidget(label_PageInfo_ValAtCursor);

        label_PageInfo_Range = new QLabel(groupBox_Page);
        label_PageInfo_Range->setObjectName(QString::fromUtf8("label_PageInfo_Range"));

        horizontalLayout_PageInfo->addWidget(label_PageInfo_Range);

        label_PageInfo_Size = new QLabel(groupBox_Page);
        label_PageInfo_Size->setObjectName(QString::fromUtf8("label_PageInfo_Size"));

        horizontalLayout_PageInfo->addWidget(label_PageInfo_Size);


        gridLayout_5->addLayout(horizontalLayout_PageInfo, 2, 0, 1, 1);

        comboBox_ViewImgType = new QComboBox(groupBox_Page);
        comboBox_ViewImgType->setObjectName(QString::fromUtf8("comboBox_ViewImgType"));

        gridLayout_5->addWidget(comboBox_ViewImgType, 2, 1, 1, 1);

        groupBox_Processing = new QGroupBox(groupBox_Page);
        groupBox_Processing->setObjectName(QString::fromUtf8("groupBox_Processing"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_Processing->sizePolicy().hasHeightForWidth());
        groupBox_Processing->setSizePolicy(sizePolicy1);
        groupBox_Processing->setMinimumSize(QSize(0, 0));
        groupBox_Processing->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_7 = new QGridLayout(groupBox_Processing);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(9, 9, 9, 9);
        comboBox_Processing = new QComboBox(groupBox_Processing);
        comboBox_Processing->setObjectName(QString::fromUtf8("comboBox_Processing"));

        gridLayout_7->addWidget(comboBox_Processing, 0, 0, 1, 1);

        stackedWidget_Processing = new QStackedWidget(groupBox_Processing);
        stackedWidget_Processing->setObjectName(QString::fromUtf8("stackedWidget_Processing"));
        page_Skip = new QWidget();
        page_Skip->setObjectName(QString::fromUtf8("page_Skip"));
        gridLayout_15 = new QGridLayout(page_Skip);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        label_Bin_Skip = new QLabel(page_Skip);
        label_Bin_Skip->setObjectName(QString::fromUtf8("label_Bin_Skip"));

        gridLayout_15->addWidget(label_Bin_Skip, 0, 0, 1, 1);

        verticalSpacer_Bin_Skip = new QSpacerItem(20, 216, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_15->addItem(verticalSpacer_Bin_Skip, 1, 0, 1, 1);

        stackedWidget_Processing->addWidget(page_Skip);
        page_Copy = new QWidget();
        page_Copy->setObjectName(QString::fromUtf8("page_Copy"));
        gridLayout_14 = new QGridLayout(page_Copy);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        label_Bin_Copy = new QLabel(page_Copy);
        label_Bin_Copy->setObjectName(QString::fromUtf8("label_Bin_Copy"));

        gridLayout_14->addWidget(label_Bin_Copy, 0, 0, 1, 1);

        verticalSpacer_Bin_Copy = new QSpacerItem(20, 216, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_14->addItem(verticalSpacer_Bin_Copy, 1, 0, 1, 1);

        stackedWidget_Processing->addWidget(page_Copy);
        page_Binary = new QWidget();
        page_Binary->setObjectName(QString::fromUtf8("page_Binary"));
        gridLayout_3 = new QGridLayout(page_Binary);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_Bin_Smooth = new QGroupBox(page_Binary);
        groupBox_Bin_Smooth->setObjectName(QString::fromUtf8("groupBox_Bin_Smooth"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_Bin_Smooth->sizePolicy().hasHeightForWidth());
        groupBox_Bin_Smooth->setSizePolicy(sizePolicy2);
        groupBox_Bin_Smooth->setFlat(true);
        groupBox_Bin_Smooth->setCheckable(true);
        gridLayout_9 = new QGridLayout(groupBox_Bin_Smooth);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setVerticalSpacing(3);
        gridLayout_9->setContentsMargins(15, 3, 3, -1);
        label_2 = new QLabel(groupBox_Bin_Smooth);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(55, 0));
        label_2->setMaximumSize(QSize(55, 16777215));

        gridLayout_9->addWidget(label_2, 0, 0, 1, 1);

        spinBox_Bin_Size = new QSpinBox(groupBox_Bin_Smooth);
        spinBox_Bin_Size->setObjectName(QString::fromUtf8("spinBox_Bin_Size"));
        spinBox_Bin_Size->setMinimum(3);
        spinBox_Bin_Size->setMaximum(999);
        spinBox_Bin_Size->setSingleStep(2);

        gridLayout_9->addWidget(spinBox_Bin_Size, 0, 1, 1, 1);

        doubleSpinBox_Bin_Sigma = new QDoubleSpinBox(groupBox_Bin_Smooth);
        doubleSpinBox_Bin_Sigma->setObjectName(QString::fromUtf8("doubleSpinBox_Bin_Sigma"));

        gridLayout_9->addWidget(doubleSpinBox_Bin_Sigma, 0, 2, 1, 1);


        gridLayout_3->addWidget(groupBox_Bin_Smooth, 0, 0, 1, 1);

        groupBox_Binarization = new QGroupBox(page_Binary);
        groupBox_Binarization->setObjectName(QString::fromUtf8("groupBox_Binarization"));
        sizePolicy2.setHeightForWidth(groupBox_Binarization->sizePolicy().hasHeightForWidth());
        groupBox_Binarization->setSizePolicy(sizePolicy2);
        groupBox_Binarization->setFlat(true);
        groupBox_Binarization->setCheckable(false);
        gridLayout_11 = new QGridLayout(groupBox_Binarization);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setVerticalSpacing(3);
        gridLayout_11->setContentsMargins(15, 3, 3, -1);
        doubleSpinBox_Bin_Threshold = new QDoubleSpinBox(groupBox_Binarization);
        doubleSpinBox_Bin_Threshold->setObjectName(QString::fromUtf8("doubleSpinBox_Bin_Threshold"));
        doubleSpinBox_Bin_Threshold->setMinimum(-9999999.000000000000000);
        doubleSpinBox_Bin_Threshold->setMaximum(9999999.000000000000000);
        doubleSpinBox_Bin_Threshold->setValue(127.000000000000000);

        gridLayout_11->addWidget(doubleSpinBox_Bin_Threshold, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_Binarization);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(55, 0));
        label_3->setMaximumSize(QSize(55, 16777215));

        gridLayout_11->addWidget(label_3, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_Binarization, 1, 0, 1, 1);

        groupBox_Bin_Segmentation = new QGroupBox(page_Binary);
        groupBox_Bin_Segmentation->setObjectName(QString::fromUtf8("groupBox_Bin_Segmentation"));
        sizePolicy2.setHeightForWidth(groupBox_Bin_Segmentation->sizePolicy().hasHeightForWidth());
        groupBox_Bin_Segmentation->setSizePolicy(sizePolicy2);
        groupBox_Bin_Segmentation->setFlat(true);
        groupBox_Bin_Segmentation->setCheckable(true);
        groupBox_Bin_Segmentation->setChecked(false);
        gridLayout_8 = new QGridLayout(groupBox_Bin_Segmentation);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setVerticalSpacing(3);
        gridLayout_8->setContentsMargins(15, 3, 3, -1);
        checkBox_Bin_InclBorder = new QCheckBox(groupBox_Bin_Segmentation);
        checkBox_Bin_InclBorder->setObjectName(QString::fromUtf8("checkBox_Bin_InclBorder"));
        checkBox_Bin_InclBorder->setChecked(true);

        gridLayout_8->addWidget(checkBox_Bin_InclBorder, 2, 0, 1, 2);

        checkBox_Bin_InclNonSeed = new QCheckBox(groupBox_Bin_Segmentation);
        checkBox_Bin_InclNonSeed->setObjectName(QString::fromUtf8("checkBox_Bin_InclNonSeed"));
        checkBox_Bin_InclNonSeed->setChecked(true);

        gridLayout_8->addWidget(checkBox_Bin_InclNonSeed, 1, 0, 1, 2);

        doubleSpinBox_Bin_Distance = new QDoubleSpinBox(groupBox_Bin_Segmentation);
        doubleSpinBox_Bin_Distance->setObjectName(QString::fromUtf8("doubleSpinBox_Bin_Distance"));
        doubleSpinBox_Bin_Distance->setMaximum(99999.000000000000000);
        doubleSpinBox_Bin_Distance->setValue(10.000000000000000);

        gridLayout_8->addWidget(doubleSpinBox_Bin_Distance, 0, 1, 1, 1);

        label = new QLabel(groupBox_Bin_Segmentation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(55, 0));
        label->setMaximumSize(QSize(55, 16777215));

        gridLayout_8->addWidget(label, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_Bin_Segmentation, 2, 0, 1, 1);

        groupBox_Reduce = new QGroupBox(page_Binary);
        groupBox_Reduce->setObjectName(QString::fromUtf8("groupBox_Reduce"));
        sizePolicy2.setHeightForWidth(groupBox_Reduce->sizePolicy().hasHeightForWidth());
        groupBox_Reduce->setSizePolicy(sizePolicy2);
        groupBox_Reduce->setFlat(true);
        groupBox_Reduce->setCheckable(true);
        groupBox_Reduce->setChecked(false);
        gridLayout_10 = new QGridLayout(groupBox_Reduce);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setVerticalSpacing(3);
        gridLayout_10->setContentsMargins(15, 3, 3, -1);
        comboBox_Bin_Geometric = new QComboBox(groupBox_Reduce);
        comboBox_Bin_Geometric->setObjectName(QString::fromUtf8("comboBox_Bin_Geometric"));

        gridLayout_10->addWidget(comboBox_Bin_Geometric, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_Reduce, 3, 0, 1, 1);

        groupBox_Bin_Paint = new QGroupBox(page_Binary);
        groupBox_Bin_Paint->setObjectName(QString::fromUtf8("groupBox_Bin_Paint"));
        sizePolicy2.setHeightForWidth(groupBox_Bin_Paint->sizePolicy().hasHeightForWidth());
        groupBox_Bin_Paint->setSizePolicy(sizePolicy2);
        groupBox_Bin_Paint->setFlat(true);
        groupBox_Bin_Paint->setCheckable(true);
        groupBox_Bin_Paint->setChecked(false);
        gridLayout_16 = new QGridLayout(groupBox_Bin_Paint);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setVerticalSpacing(3);
        gridLayout_16->setContentsMargins(15, 3, 3, -1);
        spinBox_Bin_Paint_Width = new QSpinBox(groupBox_Bin_Paint);
        spinBox_Bin_Paint_Width->setObjectName(QString::fromUtf8("spinBox_Bin_Paint_Width"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spinBox_Bin_Paint_Width->sizePolicy().hasHeightForWidth());
        spinBox_Bin_Paint_Width->setSizePolicy(sizePolicy3);
        spinBox_Bin_Paint_Width->setMinimumSize(QSize(40, 0));
        spinBox_Bin_Paint_Width->setMaximumSize(QSize(40, 16777215));
        spinBox_Bin_Paint_Width->setMinimum(1);

        gridLayout_16->addWidget(spinBox_Bin_Paint_Width, 0, 2, 1, 1);

        comboBox_Bin_Paint_Type = new QComboBox(groupBox_Bin_Paint);
        comboBox_Bin_Paint_Type->setObjectName(QString::fromUtf8("comboBox_Bin_Paint_Type"));

        gridLayout_16->addWidget(comboBox_Bin_Paint_Type, 0, 0, 1, 1);

        pushButton_Bin_Paint_Reset = new QPushButton(groupBox_Bin_Paint);
        pushButton_Bin_Paint_Reset->setObjectName(QString::fromUtf8("pushButton_Bin_Paint_Reset"));
        sizePolicy3.setHeightForWidth(pushButton_Bin_Paint_Reset->sizePolicy().hasHeightForWidth());
        pushButton_Bin_Paint_Reset->setSizePolicy(sizePolicy3);
        pushButton_Bin_Paint_Reset->setMaximumSize(QSize(40, 16777215));

        gridLayout_16->addWidget(pushButton_Bin_Paint_Reset, 0, 4, 1, 1);

        comboBox_Bin_Paint_FG_BG = new QComboBox(groupBox_Bin_Paint);
        comboBox_Bin_Paint_FG_BG->setObjectName(QString::fromUtf8("comboBox_Bin_Paint_FG_BG"));

        gridLayout_16->addWidget(comboBox_Bin_Paint_FG_BG, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_Bin_Paint, 4, 0, 1, 1);

        stackedWidget_Processing->addWidget(page_Binary);
        page_Values = new QWidget();
        page_Values->setObjectName(QString::fromUtf8("page_Values"));
        gridLayout_13 = new QGridLayout(page_Values);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer, 0, 0, 1, 1);


        gridLayout_13->addLayout(gridLayout_12, 4, 0, 1, 3);

        doubleSpinBox_Val_Out_Max = new QDoubleSpinBox(page_Values);
        doubleSpinBox_Val_Out_Max->setObjectName(QString::fromUtf8("doubleSpinBox_Val_Out_Max"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(doubleSpinBox_Val_Out_Max->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Val_Out_Max->setSizePolicy(sizePolicy4);
        doubleSpinBox_Val_Out_Max->setMinimumSize(QSize(45, 0));
        doubleSpinBox_Val_Out_Max->setMaximumSize(QSize(45, 16777215));
        doubleSpinBox_Val_Out_Max->setDecimals(0);
        doubleSpinBox_Val_Out_Max->setMinimum(0.000000000000000);
        doubleSpinBox_Val_Out_Max->setMaximum(255.000000000000000);
        doubleSpinBox_Val_Out_Max->setValue(255.000000000000000);

        gridLayout_13->addWidget(doubleSpinBox_Val_Out_Max, 2, 2, 1, 1);

        label_6 = new QLabel(page_Values);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(55, 0));
        label_6->setMaximumSize(QSize(55, 16777215));

        gridLayout_13->addWidget(label_6, 3, 0, 1, 1);

        doubleSpinBox_Val_Out_Min = new QDoubleSpinBox(page_Values);
        doubleSpinBox_Val_Out_Min->setObjectName(QString::fromUtf8("doubleSpinBox_Val_Out_Min"));
        sizePolicy4.setHeightForWidth(doubleSpinBox_Val_Out_Min->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Val_Out_Min->setSizePolicy(sizePolicy4);
        doubleSpinBox_Val_Out_Min->setMinimumSize(QSize(45, 0));
        doubleSpinBox_Val_Out_Min->setMaximumSize(QSize(45, 16777215));
        doubleSpinBox_Val_Out_Min->setDecimals(0);
        doubleSpinBox_Val_Out_Min->setMinimum(0.000000000000000);
        doubleSpinBox_Val_Out_Min->setMaximum(255.000000000000000);

        gridLayout_13->addWidget(doubleSpinBox_Val_Out_Min, 1, 2, 1, 1);

        label_4 = new QLabel(page_Values);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(55, 0));
        label_4->setMaximumSize(QSize(55, 16777215));

        gridLayout_13->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(page_Values);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(55, 0));
        label_5->setMaximumSize(QSize(55, 16777215));

        gridLayout_13->addWidget(label_5, 2, 0, 1, 1);

        doubleSpinBox_Val_Gamma = new QDoubleSpinBox(page_Values);
        doubleSpinBox_Val_Gamma->setObjectName(QString::fromUtf8("doubleSpinBox_Val_Gamma"));
        doubleSpinBox_Val_Gamma->setDecimals(3);
        doubleSpinBox_Val_Gamma->setMinimum(0.000000000000000);
        doubleSpinBox_Val_Gamma->setMaximum(999.000000000000000);
        doubleSpinBox_Val_Gamma->setSingleStep(0.100000000000000);
        doubleSpinBox_Val_Gamma->setValue(1.000000000000000);

        gridLayout_13->addWidget(doubleSpinBox_Val_Gamma, 3, 1, 1, 2);

        doubleSpinBox_Val_In_Min = new QDoubleSpinBox(page_Values);
        doubleSpinBox_Val_In_Min->setObjectName(QString::fromUtf8("doubleSpinBox_Val_In_Min"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(2);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(doubleSpinBox_Val_In_Min->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Val_In_Min->setSizePolicy(sizePolicy5);
        doubleSpinBox_Val_In_Min->setMinimum(-999999.000000000000000);
        doubleSpinBox_Val_In_Min->setMaximum(999999.000000000000000);

        gridLayout_13->addWidget(doubleSpinBox_Val_In_Min, 1, 1, 1, 1);

        doubleSpinBox_Val_In_Max = new QDoubleSpinBox(page_Values);
        doubleSpinBox_Val_In_Max->setObjectName(QString::fromUtf8("doubleSpinBox_Val_In_Max"));
        sizePolicy5.setHeightForWidth(doubleSpinBox_Val_In_Max->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Val_In_Max->setSizePolicy(sizePolicy5);
        doubleSpinBox_Val_In_Max->setMinimum(-999999.000000000000000);
        doubleSpinBox_Val_In_Max->setMaximum(999999.000000000000000);
        doubleSpinBox_Val_In_Max->setValue(255.000000000000000);

        gridLayout_13->addWidget(doubleSpinBox_Val_In_Max, 2, 1, 1, 1);

        label_7 = new QLabel(page_Values);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_13->addWidget(label_7, 0, 1, 1, 1);

        label_8 = new QLabel(page_Values);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_13->addWidget(label_8, 0, 2, 1, 1);

        stackedWidget_Processing->addWidget(page_Values);

        gridLayout_7->addWidget(stackedWidget_Processing, 1, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_Processing, 4, 0, 2, 1);

        groupBox_Color = new QGroupBox(groupBox_Page);
        groupBox_Color->setObjectName(QString::fromUtf8("groupBox_Color"));
        sizePolicy.setHeightForWidth(groupBox_Color->sizePolicy().hasHeightForWidth());
        groupBox_Color->setSizePolicy(sizePolicy);
        groupBox_Color->setMinimumSize(QSize(125, 0));
        groupBox_Color->setMaximumSize(QSize(125, 16777215));
        gridLayout_6 = new QGridLayout(groupBox_Color);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_Color_G = new QLabel(groupBox_Color);
        label_Color_G->setObjectName(QString::fromUtf8("label_Color_G"));
        sizePolicy2.setHeightForWidth(label_Color_G->sizePolicy().hasHeightForWidth());
        label_Color_G->setSizePolicy(sizePolicy2);
        label_Color_G->setMinimumSize(QSize(30, 0));
        label_Color_G->setMaximumSize(QSize(30, 16777215));

        gridLayout_6->addWidget(label_Color_G, 3, 0, 1, 1);

        label_Color_Preview = new QLabel(groupBox_Color);
        label_Color_Preview->setObjectName(QString::fromUtf8("label_Color_Preview"));
        sizePolicy2.setHeightForWidth(label_Color_Preview->sizePolicy().hasHeightForWidth());
        label_Color_Preview->setSizePolicy(sizePolicy2);
        label_Color_Preview->setStyleSheet(QString::fromUtf8(""));

        gridLayout_6->addWidget(label_Color_Preview, 0, 0, 1, 2);

        label_Color_B = new QLabel(groupBox_Color);
        label_Color_B->setObjectName(QString::fromUtf8("label_Color_B"));
        sizePolicy2.setHeightForWidth(label_Color_B->sizePolicy().hasHeightForWidth());
        label_Color_B->setSizePolicy(sizePolicy2);
        label_Color_B->setMinimumSize(QSize(30, 0));
        label_Color_B->setMaximumSize(QSize(30, 16777215));

        gridLayout_6->addWidget(label_Color_B, 4, 0, 1, 1);

        label_Color_R = new QLabel(groupBox_Color);
        label_Color_R->setObjectName(QString::fromUtf8("label_Color_R"));
        sizePolicy2.setHeightForWidth(label_Color_R->sizePolicy().hasHeightForWidth());
        label_Color_R->setSizePolicy(sizePolicy2);
        label_Color_R->setMinimumSize(QSize(30, 0));
        label_Color_R->setMaximumSize(QSize(30, 16777215));

        gridLayout_6->addWidget(label_Color_R, 2, 0, 1, 1);

        label_Color_Alpha = new QLabel(groupBox_Color);
        label_Color_Alpha->setObjectName(QString::fromUtf8("label_Color_Alpha"));
        sizePolicy2.setHeightForWidth(label_Color_Alpha->sizePolicy().hasHeightForWidth());
        label_Color_Alpha->setSizePolicy(sizePolicy2);
        label_Color_Alpha->setMinimumSize(QSize(30, 0));
        label_Color_Alpha->setMaximumSize(QSize(30, 16777215));

        gridLayout_6->addWidget(label_Color_Alpha, 5, 0, 1, 1);

        spinBox_Color_Red = new QSpinBox(groupBox_Color);
        spinBox_Color_Red->setObjectName(QString::fromUtf8("spinBox_Color_Red"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(spinBox_Color_Red->sizePolicy().hasHeightForWidth());
        spinBox_Color_Red->setSizePolicy(sizePolicy6);
        spinBox_Color_Red->setMaximum(255);
        spinBox_Color_Red->setValue(255);

        gridLayout_6->addWidget(spinBox_Color_Red, 2, 1, 1, 1);

        spinBox_Color_Green = new QSpinBox(groupBox_Color);
        spinBox_Color_Green->setObjectName(QString::fromUtf8("spinBox_Color_Green"));
        sizePolicy6.setHeightForWidth(spinBox_Color_Green->sizePolicy().hasHeightForWidth());
        spinBox_Color_Green->setSizePolicy(sizePolicy6);
        spinBox_Color_Green->setMaximum(255);
        spinBox_Color_Green->setValue(0);

        gridLayout_6->addWidget(spinBox_Color_Green, 3, 1, 1, 1);

        pushButton_ColorSet = new QPushButton(groupBox_Color);
        pushButton_ColorSet->setObjectName(QString::fromUtf8("pushButton_ColorSet"));

        gridLayout_6->addWidget(pushButton_ColorSet, 6, 0, 1, 2);

        spinBox_Color_Blue = new QSpinBox(groupBox_Color);
        spinBox_Color_Blue->setObjectName(QString::fromUtf8("spinBox_Color_Blue"));
        sizePolicy6.setHeightForWidth(spinBox_Color_Blue->sizePolicy().hasHeightForWidth());
        spinBox_Color_Blue->setSizePolicy(sizePolicy6);
        spinBox_Color_Blue->setMaximum(255);
        spinBox_Color_Blue->setValue(0);

        gridLayout_6->addWidget(spinBox_Color_Blue, 4, 1, 1, 1);

        spinBox_Color_Alpha = new QSpinBox(groupBox_Color);
        spinBox_Color_Alpha->setObjectName(QString::fromUtf8("spinBox_Color_Alpha"));
        spinBox_Color_Alpha->setMaximum(255);
        spinBox_Color_Alpha->setValue(255);

        gridLayout_6->addWidget(spinBox_Color_Alpha, 5, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_Color, 4, 1, 2, 1);


        gridLayout->addWidget(groupBox_Page, 2, 0, 1, 1);

        groupBox_Image = new QGroupBox(centralwidget);
        groupBox_Image->setObjectName(QString::fromUtf8("groupBox_Image"));
        gridLayout_2 = new QGridLayout(groupBox_Image);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_Add = new QPushButton(groupBox_Image);
        pushButton_Add->setObjectName(QString::fromUtf8("pushButton_Add"));

        gridLayout_2->addWidget(pushButton_Add, 0, 0, 1, 1);

        pushButton_Clear = new QPushButton(groupBox_Image);
        pushButton_Clear->setObjectName(QString::fromUtf8("pushButton_Clear"));
        pushButton_Clear->setEnabled(false);

        gridLayout_2->addWidget(pushButton_Clear, 0, 1, 1, 1);

        comboBox_Image = new QComboBox(groupBox_Image);
        comboBox_Image->setObjectName(QString::fromUtf8("comboBox_Image"));
        comboBox_Image->setEnabled(false);

        gridLayout_2->addWidget(comboBox_Image, 1, 0, 1, 2);


        gridLayout->addWidget(groupBox_Image, 1, 0, 1, 1);

        groupBox_Output = new QGroupBox(centralwidget);
        groupBox_Output->setObjectName(QString::fromUtf8("groupBox_Output"));
        groupBox_Output->setEnabled(false);
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(2);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(groupBox_Output->sizePolicy().hasHeightForWidth());
        groupBox_Output->setSizePolicy(sizePolicy7);
        gridLayout_4 = new QGridLayout(groupBox_Output);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton_SaveStack = new QPushButton(groupBox_Output);
        pushButton_SaveStack->setObjectName(QString::fromUtf8("pushButton_SaveStack"));

        gridLayout_4->addWidget(pushButton_SaveStack, 1, 1, 1, 1);

        graphicsView_Output = new QGraphicsView(groupBox_Output);
        graphicsView_Output->setObjectName(QString::fromUtf8("graphicsView_Output"));
        graphicsView_Output->setMouseTracking(true);

        gridLayout_4->addWidget(graphicsView_Output, 0, 0, 1, 2);

        pushButton_SaveSingle = new QPushButton(groupBox_Output);
        pushButton_SaveSingle->setObjectName(QString::fromUtf8("pushButton_SaveSingle"));

        gridLayout_4->addWidget(pushButton_SaveSingle, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_Output, 1, 1, 3, 1);

        groupBox_Scalebar = new QGroupBox(centralwidget);
        groupBox_Scalebar->setObjectName(QString::fromUtf8("groupBox_Scalebar"));
        groupBox_Scalebar->setEnabled(false);
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(groupBox_Scalebar->sizePolicy().hasHeightForWidth());
        groupBox_Scalebar->setSizePolicy(sizePolicy8);
        groupBox_Scalebar->setMinimumSize(QSize(0, 0));
        groupBox_Scalebar->setMaximumSize(QSize(16777215, 16777215));
        groupBox_Scalebar->setCheckable(true);
        groupBox_Scalebar->setChecked(false);
        gridLayout_17 = new QGridLayout(groupBox_Scalebar);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        doubleSpinBox_Scalebar_Barsize = new QDoubleSpinBox(groupBox_Scalebar);
        doubleSpinBox_Scalebar_Barsize->setObjectName(QString::fromUtf8("doubleSpinBox_Scalebar_Barsize"));
        sizePolicy4.setHeightForWidth(doubleSpinBox_Scalebar_Barsize->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Scalebar_Barsize->setSizePolicy(sizePolicy4);
        doubleSpinBox_Scalebar_Barsize->setDecimals(3);
        doubleSpinBox_Scalebar_Barsize->setMinimum(0.000000000000000);
        doubleSpinBox_Scalebar_Barsize->setMaximum(999999.000000000000000);
        doubleSpinBox_Scalebar_Barsize->setValue(100.000000000000000);

        gridLayout_17->addWidget(doubleSpinBox_Scalebar_Barsize, 0, 7, 1, 1);

        label_Scalebar_Pixel = new QLabel(groupBox_Scalebar);
        label_Scalebar_Pixel->setObjectName(QString::fromUtf8("label_Scalebar_Pixel"));
        QSizePolicy sizePolicy9(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(label_Scalebar_Pixel->sizePolicy().hasHeightForWidth());
        label_Scalebar_Pixel->setSizePolicy(sizePolicy9);
        label_Scalebar_Pixel->setMinimumSize(QSize(0, 0));
        label_Scalebar_Pixel->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_17->addWidget(label_Scalebar_Pixel, 0, 0, 1, 1);

        doubleSpinBox_Scalebar_Pixelsize = new QDoubleSpinBox(groupBox_Scalebar);
        doubleSpinBox_Scalebar_Pixelsize->setObjectName(QString::fromUtf8("doubleSpinBox_Scalebar_Pixelsize"));
        sizePolicy4.setHeightForWidth(doubleSpinBox_Scalebar_Pixelsize->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Scalebar_Pixelsize->setSizePolicy(sizePolicy4);
        doubleSpinBox_Scalebar_Pixelsize->setDecimals(3);
        doubleSpinBox_Scalebar_Pixelsize->setMinimum(0.000000000000000);
        doubleSpinBox_Scalebar_Pixelsize->setMaximum(999999.000000000000000);
        doubleSpinBox_Scalebar_Pixelsize->setValue(1.000000000000000);

        gridLayout_17->addWidget(doubleSpinBox_Scalebar_Pixelsize, 0, 1, 1, 1);

        line_Scalebar_1 = new QFrame(groupBox_Scalebar);
        line_Scalebar_1->setObjectName(QString::fromUtf8("line_Scalebar_1"));
        line_Scalebar_1->setFrameShape(QFrame::VLine);
        line_Scalebar_1->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line_Scalebar_1, 0, 2, 1, 1);

        lineEdit_Scalebar_Unit = new QLineEdit(groupBox_Scalebar);
        lineEdit_Scalebar_Unit->setObjectName(QString::fromUtf8("lineEdit_Scalebar_Unit"));
        QSizePolicy sizePolicy10(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(1);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(lineEdit_Scalebar_Unit->sizePolicy().hasHeightForWidth());
        lineEdit_Scalebar_Unit->setSizePolicy(sizePolicy10);

        gridLayout_17->addWidget(lineEdit_Scalebar_Unit, 0, 4, 1, 1);

        line_Scalebar_2 = new QFrame(groupBox_Scalebar);
        line_Scalebar_2->setObjectName(QString::fromUtf8("line_Scalebar_2"));
        line_Scalebar_2->setFrameShape(QFrame::VLine);
        line_Scalebar_2->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line_Scalebar_2, 0, 5, 1, 1);

        label_Scalebar_Unit = new QLabel(groupBox_Scalebar);
        label_Scalebar_Unit->setObjectName(QString::fromUtf8("label_Scalebar_Unit"));
        sizePolicy9.setHeightForWidth(label_Scalebar_Unit->sizePolicy().hasHeightForWidth());
        label_Scalebar_Unit->setSizePolicy(sizePolicy9);
        label_Scalebar_Unit->setMinimumSize(QSize(0, 0));
        label_Scalebar_Unit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_17->addWidget(label_Scalebar_Unit, 0, 3, 1, 1);

        label_Scalebar_Bar = new QLabel(groupBox_Scalebar);
        label_Scalebar_Bar->setObjectName(QString::fromUtf8("label_Scalebar_Bar"));
        sizePolicy9.setHeightForWidth(label_Scalebar_Bar->sizePolicy().hasHeightForWidth());
        label_Scalebar_Bar->setSizePolicy(sizePolicy9);
        label_Scalebar_Bar->setMinimumSize(QSize(0, 0));
        label_Scalebar_Bar->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_17->addWidget(label_Scalebar_Bar, 0, 6, 1, 1);


        gridLayout->addWidget(groupBox_Scalebar, 3, 0, 1, 1);

        D_MAKRO_Visualization->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_Visualization);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1169, 21));
        menuData = new QMenu(menubar);
        menuData->setObjectName(QString::fromUtf8("menuData"));
        menuMakros = new QMenu(menubar);
        menuMakros->setObjectName(QString::fromUtf8("menuMakros"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        D_MAKRO_Visualization->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_Visualization);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_Visualization->setStatusBar(statusbar);

        menubar->addAction(menuData->menuAction());
        menubar->addAction(menuMakros->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menuData->addAction(action_Add_Images);
        menuData->addAction(action_Clear_Stack);
        menuData->addSeparator();
        menuData->addAction(action_Save_Single);
        menuData->addAction(action_Save_Stack);
        menuMakros->addAction(action_AutoValRange);
        menuWindow->addAction(actionMinimum);
        menuWindow->addAction(actionNormal);
        menuWindow->addAction(actionMaximum);
        menuWindow->addAction(actionFullscreen);

        retranslateUi(D_MAKRO_Visualization);
        QObject::connect(comboBox_Processing, SIGNAL(currentIndexChanged(int)), stackedWidget_Processing, SLOT(setCurrentIndex(int)));
        QObject::connect(actionFullscreen, SIGNAL(triggered(bool)), D_MAKRO_Visualization, SLOT(showFullScreen()));
        QObject::connect(actionMaximum, SIGNAL(triggered(bool)), D_MAKRO_Visualization, SLOT(showMaximized()));
        QObject::connect(actionMinimum, SIGNAL(triggered(bool)), D_MAKRO_Visualization, SLOT(showMinimized()));
        QObject::connect(actionNormal, SIGNAL(triggered(bool)), D_MAKRO_Visualization, SLOT(showNormal()));

        stackedWidget_Processing->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(D_MAKRO_Visualization);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_Visualization)
    {
        D_MAKRO_Visualization->setWindowTitle(QApplication::translate("D_MAKRO_Visualization", "MainWindow", nullptr));
        action_Add_Images->setText(QApplication::translate("D_MAKRO_Visualization", "Add Images", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Add_Images->setShortcut(QApplication::translate("D_MAKRO_Visualization", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        action_Clear_Stack->setText(QApplication::translate("D_MAKRO_Visualization", "Clear Stack", nullptr));
        action_Save_Single->setText(QApplication::translate("D_MAKRO_Visualization", "Save Single", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Save_Single->setShortcut(QApplication::translate("D_MAKRO_Visualization", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        action_Save_Stack->setText(QApplication::translate("D_MAKRO_Visualization", "Save Stack", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Save_Stack->setShortcut(QApplication::translate("D_MAKRO_Visualization", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        action_AutoValRange->setText(QApplication::translate("D_MAKRO_Visualization", "Automatic Value Range: Min to Max", nullptr));
        actionMinimum->setText(QApplication::translate("D_MAKRO_Visualization", "Minimum", nullptr));
        actionNormal->setText(QApplication::translate("D_MAKRO_Visualization", "Normal", nullptr));
        actionMaximum->setText(QApplication::translate("D_MAKRO_Visualization", "Maximum", nullptr));
        actionFullscreen->setText(QApplication::translate("D_MAKRO_Visualization", "Fullscreen", nullptr));
        groupBox_Page->setTitle(QApplication::translate("D_MAKRO_Visualization", "Pages", nullptr));
        label_PageInfo_ValAtCursor->setText(QApplication::translate("D_MAKRO_Visualization", "ValueAtCursor", nullptr));
        label_PageInfo_Range->setText(QApplication::translate("D_MAKRO_Visualization", "Range", nullptr));
        label_PageInfo_Size->setText(QApplication::translate("D_MAKRO_Visualization", "Size", nullptr));
        groupBox_Processing->setTitle(QApplication::translate("D_MAKRO_Visualization", "Processing", nullptr));
        label_Bin_Skip->setText(QApplication::translate("D_MAKRO_Visualization", "Ignores this page.", nullptr));
        label_Bin_Copy->setText(QApplication::translate("D_MAKRO_Visualization", "Copy the data without scaling.", nullptr));
        groupBox_Bin_Smooth->setTitle(QApplication::translate("D_MAKRO_Visualization", "Smooth", nullptr));
        label_2->setText(QApplication::translate("D_MAKRO_Visualization", "Size/Sigma:", nullptr));
        groupBox_Binarization->setTitle(QApplication::translate("D_MAKRO_Visualization", "Binarization", nullptr));
        label_3->setText(QApplication::translate("D_MAKRO_Visualization", "Threshold:", nullptr));
        groupBox_Bin_Segmentation->setTitle(QApplication::translate("D_MAKRO_Visualization", "Segmentation", nullptr));
        checkBox_Bin_InclBorder->setText(QApplication::translate("D_MAKRO_Visualization", "Include objects at border", nullptr));
        checkBox_Bin_InclNonSeed->setText(QApplication::translate("D_MAKRO_Visualization", "Include not seeded objects", nullptr));
        label->setText(QApplication::translate("D_MAKRO_Visualization", "Distance:", nullptr));
        groupBox_Reduce->setTitle(QApplication::translate("D_MAKRO_Visualization", "Reduce to", nullptr));
#ifndef QT_NO_WHATSTHIS
        groupBox_Bin_Paint->setWhatsThis(QApplication::translate("D_MAKRO_Visualization", "<html><head/><body><p>Left-click on Image: Line to / Fill from position</p><p><br/></p><p>Right-click on Image: Start new line</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        groupBox_Bin_Paint->setTitle(QApplication::translate("D_MAKRO_Visualization", "Manually Paint", nullptr));
        pushButton_Bin_Paint_Reset->setText(QApplication::translate("D_MAKRO_Visualization", "Reset", nullptr));
        label_6->setText(QApplication::translate("D_MAKRO_Visualization", "Gamma:", nullptr));
        label_4->setText(QApplication::translate("D_MAKRO_Visualization", "Minimum:", nullptr));
        label_5->setText(QApplication::translate("D_MAKRO_Visualization", "Maximum:", nullptr));
        label_7->setText(QApplication::translate("D_MAKRO_Visualization", "In", nullptr));
        label_8->setText(QApplication::translate("D_MAKRO_Visualization", "Out", nullptr));
        groupBox_Color->setTitle(QApplication::translate("D_MAKRO_Visualization", "Color", nullptr));
        label_Color_G->setText(QApplication::translate("D_MAKRO_Visualization", "Green", nullptr));
        label_Color_Preview->setText(QString());
        label_Color_B->setText(QApplication::translate("D_MAKRO_Visualization", "Blue", nullptr));
        label_Color_R->setText(QApplication::translate("D_MAKRO_Visualization", "Red", nullptr));
        label_Color_Alpha->setText(QApplication::translate("D_MAKRO_Visualization", "Alpha", nullptr));
        pushButton_ColorSet->setText(QApplication::translate("D_MAKRO_Visualization", "Select Color", nullptr));
        groupBox_Image->setTitle(QApplication::translate("D_MAKRO_Visualization", "Images", nullptr));
        pushButton_Add->setText(QApplication::translate("D_MAKRO_Visualization", "Add Images (Ctrl + O)", nullptr));
        pushButton_Clear->setText(QApplication::translate("D_MAKRO_Visualization", "Clear Stack", nullptr));
        groupBox_Output->setTitle(QApplication::translate("D_MAKRO_Visualization", "Output", nullptr));
        pushButton_SaveStack->setText(QApplication::translate("D_MAKRO_Visualization", "Save Stack (Ctrl + Shift + S)", nullptr));
        pushButton_SaveSingle->setText(QApplication::translate("D_MAKRO_Visualization", "Save Single (Ctrl + S)", nullptr));
        groupBox_Scalebar->setTitle(QApplication::translate("D_MAKRO_Visualization", "Scalebar", nullptr));
        doubleSpinBox_Scalebar_Barsize->setSuffix(QApplication::translate("D_MAKRO_Visualization", "px", nullptr));
        label_Scalebar_Pixel->setText(QApplication::translate("D_MAKRO_Visualization", "Pixesize:", nullptr));
        doubleSpinBox_Scalebar_Pixelsize->setSuffix(QApplication::translate("D_MAKRO_Visualization", "px", nullptr));
        lineEdit_Scalebar_Unit->setText(QApplication::translate("D_MAKRO_Visualization", "px", nullptr));
        label_Scalebar_Unit->setText(QApplication::translate("D_MAKRO_Visualization", "Unit:", nullptr));
        label_Scalebar_Bar->setText(QApplication::translate("D_MAKRO_Visualization", "Barsize:", nullptr));
        menuData->setTitle(QApplication::translate("D_MAKRO_Visualization", "Data", nullptr));
        menuMakros->setTitle(QApplication::translate("D_MAKRO_Visualization", "Presets", nullptr));
        menuWindow->setTitle(QApplication::translate("D_MAKRO_Visualization", "Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_Visualization: public Ui_D_MAKRO_Visualization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_VISUALIZATION_H
