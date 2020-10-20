/********************************************************************************
** Form generated from reading UI file 'd_makro_manuelsegmentation.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_MANUELSEGMENTATION_H
#define UI_D_MAKRO_MANUELSEGMENTATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_ManuelSegmentation
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_Data;
    QGridLayout *gridLayout_5;
    QComboBox *comboBox_Data;
    QPushButton *pushButton_Data_Clear;
    QPushButton *pushButton_Data_Load;
    QPushButton *pushButton_Data_Next;
    QPushButton *pushButton_Data_Previous;
    QLabel *label_Select;
    QLabel *label_Files;
    QLabel *label_Scale;
    QHBoxLayout *horizontalLayout_Scale;
    QSpinBox *spinBox_Scale_Px;
    QLabel *label_Scale_2;
    QDoubleSpinBox *doubleSpinBox_Scale_CutomUnit;
    QLineEdit *lineEdit_Scale_CustomUnit;
    QLabel *label_Scale_3;
    QLabel *label_Scale_Factor;
    QGroupBox *groupBox_Draw;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView_Draw;
    QComboBox *comboBox_StepsDraw;
    QGroupBox *groupBox_Measurement;
    QGridLayout *gridLayout_4;
    QPlainTextEdit *plainTextEdit_Stats;
    QPlainTextEdit *plainTextEdit_Feats;
    QPushButton *pushButton_Select_Feats;
    QPushButton *pushButton_Select_Stats;
    QLabel *label_4;
    QLabel *label_5;
    QGroupBox *groupBox_Results;
    QGridLayout *gridLayout_3;
    QStackedWidget *stackedWidget_Results;
    QWidget *page_Graphics_Segmentation;
    QGridLayout *gridLayout_7;
    QGraphicsView *graphicsView_Res_Gra_Seg;
    QWidget *page_Res_Tab_Current_Feats;
    QGridLayout *gridLayout_6;
    QTableWidget *tableWidget_Res_Current_Feats;
    QWidget *page_Res_Tab_Current_Stats;
    QGridLayout *gridLayout_10;
    QTableWidget *tableWidget_Res_Current_Stats;
    QWidget *page_Res_Tab_All_Feats;
    QGridLayout *gridLayout_9;
    QTableWidget *tableWidget_Res_All_Feats;
    QWidget *page_Res_Tab_All_Stats;
    QGridLayout *gridLayout_8;
    QTableWidget *tableWidget_Res_All_Stats;
    QComboBox *comboBox_Results;
    QPushButton *pushButton_Results_SaveAnalysis;
    QGroupBox *groupBox_ToolBox;
    QGridLayout *gridLayout_11;
    QHBoxLayout *horizontalLayout_Pen;
    QPushButton *pushButton_Draw_FillHoles;
    QPushButton *pushButton_Draw_Undo;
    QPushButton *pushButton_Draw_Clear;
    QHBoxLayout *horizontalLayout_Tool;
    QPushButton *pushButton_DrawTool_Line_FG;
    QPushButton *pushButton_DrawTool_Line_BG;
    QPushButton *pushButton_DrawTool_Floodfill;
    QLabel *label_Pen;
    QLabel *label_Tool;
    QGroupBox *groupBox_Overlay;
    QGridLayout *gridLayout_12;
    QLabel *label_Overlay;
    QLabel *label_Overlay_Intensity;
    QPushButton *pushButton_Overlay_Color;
    QDoubleSpinBox *doubleSpinBox_Intensity_Overlay;
    QDoubleSpinBox *doubleSpinBox_Intensity_Backgrouond;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_ManuelSegmentation)
    {
        if (D_MAKRO_ManuelSegmentation->objectName().isEmpty())
            D_MAKRO_ManuelSegmentation->setObjectName(QString::fromUtf8("D_MAKRO_ManuelSegmentation"));
        D_MAKRO_ManuelSegmentation->resize(1007, 661);
        centralwidget = new QWidget(D_MAKRO_ManuelSegmentation);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_Data = new QGroupBox(centralwidget);
        groupBox_Data->setObjectName(QString::fromUtf8("groupBox_Data"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_Data->sizePolicy().hasHeightForWidth());
        groupBox_Data->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(groupBox_Data);
        gridLayout_5->setSpacing(3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        comboBox_Data = new QComboBox(groupBox_Data);
        comboBox_Data->setObjectName(QString::fromUtf8("comboBox_Data"));

        gridLayout_5->addWidget(comboBox_Data, 1, 1, 1, 4);

        pushButton_Data_Clear = new QPushButton(groupBox_Data);
        pushButton_Data_Clear->setObjectName(QString::fromUtf8("pushButton_Data_Clear"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_Data_Clear->sizePolicy().hasHeightForWidth());
        pushButton_Data_Clear->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(pushButton_Data_Clear, 0, 2, 1, 1);

        pushButton_Data_Load = new QPushButton(groupBox_Data);
        pushButton_Data_Load->setObjectName(QString::fromUtf8("pushButton_Data_Load"));
        sizePolicy1.setHeightForWidth(pushButton_Data_Load->sizePolicy().hasHeightForWidth());
        pushButton_Data_Load->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(pushButton_Data_Load, 0, 1, 1, 1);

        pushButton_Data_Next = new QPushButton(groupBox_Data);
        pushButton_Data_Next->setObjectName(QString::fromUtf8("pushButton_Data_Next"));
        sizePolicy1.setHeightForWidth(pushButton_Data_Next->sizePolicy().hasHeightForWidth());
        pushButton_Data_Next->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(pushButton_Data_Next, 0, 4, 1, 1);

        pushButton_Data_Previous = new QPushButton(groupBox_Data);
        pushButton_Data_Previous->setObjectName(QString::fromUtf8("pushButton_Data_Previous"));
        sizePolicy1.setHeightForWidth(pushButton_Data_Previous->sizePolicy().hasHeightForWidth());
        pushButton_Data_Previous->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(pushButton_Data_Previous, 0, 3, 1, 1);

        label_Select = new QLabel(groupBox_Data);
        label_Select->setObjectName(QString::fromUtf8("label_Select"));
        label_Select->setMinimumSize(QSize(50, 0));
        label_Select->setMaximumSize(QSize(50, 16777215));

        gridLayout_5->addWidget(label_Select, 0, 0, 1, 1);

        label_Files = new QLabel(groupBox_Data);
        label_Files->setObjectName(QString::fromUtf8("label_Files"));
        label_Files->setMinimumSize(QSize(50, 0));
        label_Files->setMaximumSize(QSize(50, 16777215));

        gridLayout_5->addWidget(label_Files, 1, 0, 1, 1);

        label_Scale = new QLabel(groupBox_Data);
        label_Scale->setObjectName(QString::fromUtf8("label_Scale"));
        label_Scale->setMinimumSize(QSize(50, 0));
        label_Scale->setMaximumSize(QSize(50, 16777215));

        gridLayout_5->addWidget(label_Scale, 2, 0, 1, 1);

        horizontalLayout_Scale = new QHBoxLayout();
        horizontalLayout_Scale->setSpacing(1);
        horizontalLayout_Scale->setObjectName(QString::fromUtf8("horizontalLayout_Scale"));
        spinBox_Scale_Px = new QSpinBox(groupBox_Data);
        spinBox_Scale_Px->setObjectName(QString::fromUtf8("spinBox_Scale_Px"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinBox_Scale_Px->sizePolicy().hasHeightForWidth());
        spinBox_Scale_Px->setSizePolicy(sizePolicy2);
        spinBox_Scale_Px->setMinimumSize(QSize(50, 0));
        spinBox_Scale_Px->setMaximumSize(QSize(50, 16777215));
        spinBox_Scale_Px->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Scale_Px->setMinimum(1);
        spinBox_Scale_Px->setMaximum(99999);
        spinBox_Scale_Px->setValue(1000);

        horizontalLayout_Scale->addWidget(spinBox_Scale_Px);

        label_Scale_2 = new QLabel(groupBox_Data);
        label_Scale_2->setObjectName(QString::fromUtf8("label_Scale_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_Scale_2->sizePolicy().hasHeightForWidth());
        label_Scale_2->setSizePolicy(sizePolicy3);

        horizontalLayout_Scale->addWidget(label_Scale_2);

        doubleSpinBox_Scale_CutomUnit = new QDoubleSpinBox(groupBox_Data);
        doubleSpinBox_Scale_CutomUnit->setObjectName(QString::fromUtf8("doubleSpinBox_Scale_CutomUnit"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_Scale_CutomUnit->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Scale_CutomUnit->setSizePolicy(sizePolicy2);
        doubleSpinBox_Scale_CutomUnit->setMinimumSize(QSize(50, 0));
        doubleSpinBox_Scale_CutomUnit->setMaximumSize(QSize(50, 16777215));
        doubleSpinBox_Scale_CutomUnit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Scale_CutomUnit->setDecimals(3);
        doubleSpinBox_Scale_CutomUnit->setMaximum(99999.000000000000000);
        doubleSpinBox_Scale_CutomUnit->setValue(200.000000000000000);

        horizontalLayout_Scale->addWidget(doubleSpinBox_Scale_CutomUnit);

        lineEdit_Scale_CustomUnit = new QLineEdit(groupBox_Data);
        lineEdit_Scale_CustomUnit->setObjectName(QString::fromUtf8("lineEdit_Scale_CustomUnit"));
        sizePolicy2.setHeightForWidth(lineEdit_Scale_CustomUnit->sizePolicy().hasHeightForWidth());
        lineEdit_Scale_CustomUnit->setSizePolicy(sizePolicy2);
        lineEdit_Scale_CustomUnit->setMinimumSize(QSize(20, 0));
        lineEdit_Scale_CustomUnit->setMaximumSize(QSize(20, 16777215));
        lineEdit_Scale_CustomUnit->setReadOnly(true);

        horizontalLayout_Scale->addWidget(lineEdit_Scale_CustomUnit);

        label_Scale_3 = new QLabel(groupBox_Data);
        label_Scale_3->setObjectName(QString::fromUtf8("label_Scale_3"));
        sizePolicy3.setHeightForWidth(label_Scale_3->sizePolicy().hasHeightForWidth());
        label_Scale_3->setSizePolicy(sizePolicy3);

        horizontalLayout_Scale->addWidget(label_Scale_3);

        label_Scale_Factor = new QLabel(groupBox_Data);
        label_Scale_Factor->setObjectName(QString::fromUtf8("label_Scale_Factor"));

        horizontalLayout_Scale->addWidget(label_Scale_Factor);


        gridLayout_5->addLayout(horizontalLayout_Scale, 2, 1, 1, 4);


        gridLayout->addWidget(groupBox_Data, 0, 2, 1, 1);

        groupBox_Draw = new QGroupBox(centralwidget);
        groupBox_Draw->setObjectName(QString::fromUtf8("groupBox_Draw"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(3);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox_Draw->sizePolicy().hasHeightForWidth());
        groupBox_Draw->setSizePolicy(sizePolicy4);
        gridLayout_2 = new QGridLayout(groupBox_Draw);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphicsView_Draw = new QGraphicsView(groupBox_Draw);
        graphicsView_Draw->setObjectName(QString::fromUtf8("graphicsView_Draw"));
        graphicsView_Draw->setMouseTracking(true);

        gridLayout_2->addWidget(graphicsView_Draw, 1, 0, 1, 1);

        comboBox_StepsDraw = new QComboBox(groupBox_Draw);
        comboBox_StepsDraw->setObjectName(QString::fromUtf8("comboBox_StepsDraw"));

        gridLayout_2->addWidget(comboBox_StepsDraw, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_Draw, 0, 0, 7, 1);

        groupBox_Measurement = new QGroupBox(centralwidget);
        groupBox_Measurement->setObjectName(QString::fromUtf8("groupBox_Measurement"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(1);
        sizePolicy5.setHeightForWidth(groupBox_Measurement->sizePolicy().hasHeightForWidth());
        groupBox_Measurement->setSizePolicy(sizePolicy5);
        gridLayout_4 = new QGridLayout(groupBox_Measurement);
        gridLayout_4->setSpacing(3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        plainTextEdit_Stats = new QPlainTextEdit(groupBox_Measurement);
        plainTextEdit_Stats->setObjectName(QString::fromUtf8("plainTextEdit_Stats"));
        plainTextEdit_Stats->setMaximumSize(QSize(16777215, 100));

        gridLayout_4->addWidget(plainTextEdit_Stats, 1, 2, 1, 1);

        plainTextEdit_Feats = new QPlainTextEdit(groupBox_Measurement);
        plainTextEdit_Feats->setObjectName(QString::fromUtf8("plainTextEdit_Feats"));
        plainTextEdit_Feats->setMaximumSize(QSize(16777215, 100));

        gridLayout_4->addWidget(plainTextEdit_Feats, 1, 1, 1, 1);

        pushButton_Select_Feats = new QPushButton(groupBox_Measurement);
        pushButton_Select_Feats->setObjectName(QString::fromUtf8("pushButton_Select_Feats"));

        gridLayout_4->addWidget(pushButton_Select_Feats, 0, 1, 1, 1);

        pushButton_Select_Stats = new QPushButton(groupBox_Measurement);
        pushButton_Select_Stats->setObjectName(QString::fromUtf8("pushButton_Select_Stats"));

        gridLayout_4->addWidget(pushButton_Select_Stats, 0, 2, 1, 1);

        label_4 = new QLabel(groupBox_Measurement);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(50, 0));
        label_4->setMaximumSize(QSize(50, 16777215));

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox_Measurement);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(50, 0));
        label_5->setMaximumSize(QSize(50, 16777215));

        gridLayout_4->addWidget(label_5, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_Measurement, 4, 2, 1, 1);

        groupBox_Results = new QGroupBox(centralwidget);
        groupBox_Results->setObjectName(QString::fromUtf8("groupBox_Results"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(1);
        sizePolicy6.setVerticalStretch(2);
        sizePolicy6.setHeightForWidth(groupBox_Results->sizePolicy().hasHeightForWidth());
        groupBox_Results->setSizePolicy(sizePolicy6);
        gridLayout_3 = new QGridLayout(groupBox_Results);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        stackedWidget_Results = new QStackedWidget(groupBox_Results);
        stackedWidget_Results->setObjectName(QString::fromUtf8("stackedWidget_Results"));
        page_Graphics_Segmentation = new QWidget();
        page_Graphics_Segmentation->setObjectName(QString::fromUtf8("page_Graphics_Segmentation"));
        gridLayout_7 = new QGridLayout(page_Graphics_Segmentation);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        graphicsView_Res_Gra_Seg = new QGraphicsView(page_Graphics_Segmentation);
        graphicsView_Res_Gra_Seg->setObjectName(QString::fromUtf8("graphicsView_Res_Gra_Seg"));

        gridLayout_7->addWidget(graphicsView_Res_Gra_Seg, 0, 0, 1, 1);

        stackedWidget_Results->addWidget(page_Graphics_Segmentation);
        page_Res_Tab_Current_Feats = new QWidget();
        page_Res_Tab_Current_Feats->setObjectName(QString::fromUtf8("page_Res_Tab_Current_Feats"));
        gridLayout_6 = new QGridLayout(page_Res_Tab_Current_Feats);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        tableWidget_Res_Current_Feats = new QTableWidget(page_Res_Tab_Current_Feats);
        tableWidget_Res_Current_Feats->setObjectName(QString::fromUtf8("tableWidget_Res_Current_Feats"));

        gridLayout_6->addWidget(tableWidget_Res_Current_Feats, 0, 0, 1, 1);

        stackedWidget_Results->addWidget(page_Res_Tab_Current_Feats);
        page_Res_Tab_Current_Stats = new QWidget();
        page_Res_Tab_Current_Stats->setObjectName(QString::fromUtf8("page_Res_Tab_Current_Stats"));
        gridLayout_10 = new QGridLayout(page_Res_Tab_Current_Stats);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        tableWidget_Res_Current_Stats = new QTableWidget(page_Res_Tab_Current_Stats);
        tableWidget_Res_Current_Stats->setObjectName(QString::fromUtf8("tableWidget_Res_Current_Stats"));

        gridLayout_10->addWidget(tableWidget_Res_Current_Stats, 0, 0, 1, 1);

        stackedWidget_Results->addWidget(page_Res_Tab_Current_Stats);
        page_Res_Tab_All_Feats = new QWidget();
        page_Res_Tab_All_Feats->setObjectName(QString::fromUtf8("page_Res_Tab_All_Feats"));
        gridLayout_9 = new QGridLayout(page_Res_Tab_All_Feats);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        tableWidget_Res_All_Feats = new QTableWidget(page_Res_Tab_All_Feats);
        tableWidget_Res_All_Feats->setObjectName(QString::fromUtf8("tableWidget_Res_All_Feats"));

        gridLayout_9->addWidget(tableWidget_Res_All_Feats, 0, 0, 1, 1);

        stackedWidget_Results->addWidget(page_Res_Tab_All_Feats);
        page_Res_Tab_All_Stats = new QWidget();
        page_Res_Tab_All_Stats->setObjectName(QString::fromUtf8("page_Res_Tab_All_Stats"));
        gridLayout_8 = new QGridLayout(page_Res_Tab_All_Stats);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        tableWidget_Res_All_Stats = new QTableWidget(page_Res_Tab_All_Stats);
        tableWidget_Res_All_Stats->setObjectName(QString::fromUtf8("tableWidget_Res_All_Stats"));

        gridLayout_8->addWidget(tableWidget_Res_All_Stats, 0, 0, 1, 1);

        stackedWidget_Results->addWidget(page_Res_Tab_All_Stats);

        gridLayout_3->addWidget(stackedWidget_Results, 1, 0, 1, 1);

        comboBox_Results = new QComboBox(groupBox_Results);
        comboBox_Results->setObjectName(QString::fromUtf8("comboBox_Results"));

        gridLayout_3->addWidget(comboBox_Results, 0, 0, 1, 1);

        pushButton_Results_SaveAnalysis = new QPushButton(groupBox_Results);
        pushButton_Results_SaveAnalysis->setObjectName(QString::fromUtf8("pushButton_Results_SaveAnalysis"));

        gridLayout_3->addWidget(pushButton_Results_SaveAnalysis, 2, 0, 1, 1);


        gridLayout->addWidget(groupBox_Results, 6, 2, 1, 1);

        groupBox_ToolBox = new QGroupBox(centralwidget);
        groupBox_ToolBox->setObjectName(QString::fromUtf8("groupBox_ToolBox"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(1);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(groupBox_ToolBox->sizePolicy().hasHeightForWidth());
        groupBox_ToolBox->setSizePolicy(sizePolicy7);
        gridLayout_11 = new QGridLayout(groupBox_ToolBox);
        gridLayout_11->setSpacing(3);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        horizontalLayout_Pen = new QHBoxLayout();
        horizontalLayout_Pen->setSpacing(1);
        horizontalLayout_Pen->setObjectName(QString::fromUtf8("horizontalLayout_Pen"));
        pushButton_Draw_FillHoles = new QPushButton(groupBox_ToolBox);
        pushButton_Draw_FillHoles->setObjectName(QString::fromUtf8("pushButton_Draw_FillHoles"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(pushButton_Draw_FillHoles->sizePolicy().hasHeightForWidth());
        pushButton_Draw_FillHoles->setSizePolicy(sizePolicy8);
        pushButton_Draw_FillHoles->setFlat(false);

        horizontalLayout_Pen->addWidget(pushButton_Draw_FillHoles);

        pushButton_Draw_Undo = new QPushButton(groupBox_ToolBox);
        pushButton_Draw_Undo->setObjectName(QString::fromUtf8("pushButton_Draw_Undo"));
        pushButton_Draw_Undo->setEnabled(false);
        sizePolicy8.setHeightForWidth(pushButton_Draw_Undo->sizePolicy().hasHeightForWidth());
        pushButton_Draw_Undo->setSizePolicy(sizePolicy8);
        pushButton_Draw_Undo->setAutoDefault(false);
        pushButton_Draw_Undo->setFlat(false);

        horizontalLayout_Pen->addWidget(pushButton_Draw_Undo);

        pushButton_Draw_Clear = new QPushButton(groupBox_ToolBox);
        pushButton_Draw_Clear->setObjectName(QString::fromUtf8("pushButton_Draw_Clear"));

        horizontalLayout_Pen->addWidget(pushButton_Draw_Clear);


        gridLayout_11->addLayout(horizontalLayout_Pen, 2, 1, 1, 1);

        horizontalLayout_Tool = new QHBoxLayout();
        horizontalLayout_Tool->setSpacing(1);
        horizontalLayout_Tool->setObjectName(QString::fromUtf8("horizontalLayout_Tool"));
        pushButton_DrawTool_Line_FG = new QPushButton(groupBox_ToolBox);
        pushButton_DrawTool_Line_FG->setObjectName(QString::fromUtf8("pushButton_DrawTool_Line_FG"));
        sizePolicy8.setHeightForWidth(pushButton_DrawTool_Line_FG->sizePolicy().hasHeightForWidth());
        pushButton_DrawTool_Line_FG->setSizePolicy(sizePolicy8);
        pushButton_DrawTool_Line_FG->setFlat(false);

        horizontalLayout_Tool->addWidget(pushButton_DrawTool_Line_FG);

        pushButton_DrawTool_Line_BG = new QPushButton(groupBox_ToolBox);
        pushButton_DrawTool_Line_BG->setObjectName(QString::fromUtf8("pushButton_DrawTool_Line_BG"));
        sizePolicy8.setHeightForWidth(pushButton_DrawTool_Line_BG->sizePolicy().hasHeightForWidth());
        pushButton_DrawTool_Line_BG->setSizePolicy(sizePolicy8);
        pushButton_DrawTool_Line_BG->setFlat(true);

        horizontalLayout_Tool->addWidget(pushButton_DrawTool_Line_BG);

        pushButton_DrawTool_Floodfill = new QPushButton(groupBox_ToolBox);
        pushButton_DrawTool_Floodfill->setObjectName(QString::fromUtf8("pushButton_DrawTool_Floodfill"));
        sizePolicy8.setHeightForWidth(pushButton_DrawTool_Floodfill->sizePolicy().hasHeightForWidth());
        pushButton_DrawTool_Floodfill->setSizePolicy(sizePolicy8);
        pushButton_DrawTool_Floodfill->setFlat(true);

        horizontalLayout_Tool->addWidget(pushButton_DrawTool_Floodfill);


        gridLayout_11->addLayout(horizontalLayout_Tool, 1, 1, 1, 1);

        label_Pen = new QLabel(groupBox_ToolBox);
        label_Pen->setObjectName(QString::fromUtf8("label_Pen"));
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(label_Pen->sizePolicy().hasHeightForWidth());
        label_Pen->setSizePolicy(sizePolicy9);
        label_Pen->setMinimumSize(QSize(50, 0));
        label_Pen->setMaximumSize(QSize(50, 16777215));

        gridLayout_11->addWidget(label_Pen, 2, 0, 1, 1);

        label_Tool = new QLabel(groupBox_ToolBox);
        label_Tool->setObjectName(QString::fromUtf8("label_Tool"));
        sizePolicy9.setHeightForWidth(label_Tool->sizePolicy().hasHeightForWidth());
        label_Tool->setSizePolicy(sizePolicy9);
        label_Tool->setMinimumSize(QSize(50, 0));
        label_Tool->setMaximumSize(QSize(50, 16777215));

        gridLayout_11->addWidget(label_Tool, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_ToolBox, 2, 2, 1, 1);

        groupBox_Overlay = new QGroupBox(centralwidget);
        groupBox_Overlay->setObjectName(QString::fromUtf8("groupBox_Overlay"));
        gridLayout_12 = new QGridLayout(groupBox_Overlay);
        gridLayout_12->setSpacing(3);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        label_Overlay = new QLabel(groupBox_Overlay);
        label_Overlay->setObjectName(QString::fromUtf8("label_Overlay"));
        sizePolicy9.setHeightForWidth(label_Overlay->sizePolicy().hasHeightForWidth());
        label_Overlay->setSizePolicy(sizePolicy9);
        label_Overlay->setMinimumSize(QSize(50, 0));
        label_Overlay->setMaximumSize(QSize(50, 16777215));

        gridLayout_12->addWidget(label_Overlay, 0, 0, 1, 1);

        label_Overlay_Intensity = new QLabel(groupBox_Overlay);
        label_Overlay_Intensity->setObjectName(QString::fromUtf8("label_Overlay_Intensity"));
        label_Overlay_Intensity->setMinimumSize(QSize(50, 0));
        label_Overlay_Intensity->setMaximumSize(QSize(50, 16777215));

        gridLayout_12->addWidget(label_Overlay_Intensity, 1, 0, 1, 1);

        pushButton_Overlay_Color = new QPushButton(groupBox_Overlay);
        pushButton_Overlay_Color->setObjectName(QString::fromUtf8("pushButton_Overlay_Color"));
        sizePolicy8.setHeightForWidth(pushButton_Overlay_Color->sizePolicy().hasHeightForWidth());
        pushButton_Overlay_Color->setSizePolicy(sizePolicy8);
        pushButton_Overlay_Color->setStyleSheet(QString::fromUtf8(""));
        pushButton_Overlay_Color->setFlat(false);

        gridLayout_12->addWidget(pushButton_Overlay_Color, 0, 1, 1, 2);

        doubleSpinBox_Intensity_Overlay = new QDoubleSpinBox(groupBox_Overlay);
        doubleSpinBox_Intensity_Overlay->setObjectName(QString::fromUtf8("doubleSpinBox_Intensity_Overlay"));
        doubleSpinBox_Intensity_Overlay->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Intensity_Overlay->setDecimals(0);
        doubleSpinBox_Intensity_Overlay->setValue(100.000000000000000);

        gridLayout_12->addWidget(doubleSpinBox_Intensity_Overlay, 1, 1, 1, 1);

        doubleSpinBox_Intensity_Backgrouond = new QDoubleSpinBox(groupBox_Overlay);
        doubleSpinBox_Intensity_Backgrouond->setObjectName(QString::fromUtf8("doubleSpinBox_Intensity_Backgrouond"));
        doubleSpinBox_Intensity_Backgrouond->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Intensity_Backgrouond->setDecimals(0);
        doubleSpinBox_Intensity_Backgrouond->setValue(70.000000000000000);

        gridLayout_12->addWidget(doubleSpinBox_Intensity_Backgrouond, 1, 2, 1, 1);


        gridLayout->addWidget(groupBox_Overlay, 1, 2, 1, 1);

        D_MAKRO_ManuelSegmentation->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_ManuelSegmentation);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1007, 21));
        D_MAKRO_ManuelSegmentation->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_ManuelSegmentation);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_ManuelSegmentation->setStatusBar(statusbar);

        retranslateUi(D_MAKRO_ManuelSegmentation);
        QObject::connect(comboBox_Results, SIGNAL(currentIndexChanged(int)), stackedWidget_Results, SLOT(setCurrentIndex(int)));

        pushButton_Draw_Undo->setDefault(false);


        QMetaObject::connectSlotsByName(D_MAKRO_ManuelSegmentation);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_ManuelSegmentation)
    {
        D_MAKRO_ManuelSegmentation->setWindowTitle(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "MainWindow", nullptr));
        groupBox_Data->setTitle(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Data", nullptr));
        pushButton_Data_Clear->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Clear", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_Data_Load->setToolTip(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "<html><head/><body><p>Ctrl+O</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Data_Load->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Load", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_Data_Next->setToolTip(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "<html><head/><body><p>Ctrl+N</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Data_Next->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Next", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_Data_Next->setShortcut(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_Data_Previous->setToolTip(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "<html><head/><body><p>Ctrl+B</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Data_Previous->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Previous", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_Data_Previous->setShortcut(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        label_Select->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Select", nullptr));
        label_Files->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Files", nullptr));
        label_Scale->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Scale", nullptr));
        spinBox_Scale_Px->setSuffix(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "px", nullptr));
        label_Scale_2->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", " equals ", nullptr));
        lineEdit_Scale_CustomUnit->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "um", nullptr));
        label_Scale_3->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "-> 1px\302\262 equals ", nullptr));
        label_Scale_Factor->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "0.04um\302\262", nullptr));
        groupBox_Draw->setTitle(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Draw", nullptr));
        groupBox_Measurement->setTitle(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Measurement", nullptr));
        pushButton_Select_Feats->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Features", nullptr));
        pushButton_Select_Stats->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Statistics", nullptr));
        label_4->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Select", nullptr));
        label_5->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Selection", nullptr));
        groupBox_Results->setTitle(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Results", nullptr));
        pushButton_Results_SaveAnalysis->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Save Analysis", nullptr));
        groupBox_ToolBox->setTitle(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Toolbox", nullptr));
        pushButton_Draw_FillHoles->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Fill Holes (F5)", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_Draw_FillHoles->setShortcut(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_Draw_Undo->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Undo (F6)", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_Draw_Undo->setShortcut(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "F6", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_Draw_Clear->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Clear (F7)", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_Draw_Clear->setShortcut(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "F7", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_DrawTool_Line_FG->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Line Draw (F1)", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_DrawTool_Line_FG->setShortcut(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_DrawTool_Line_BG->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Line Cut (F2)", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_DrawTool_Line_BG->setShortcut(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_DrawTool_Floodfill->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Flood Fill (F3)", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_DrawTool_Floodfill->setShortcut(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "F3", nullptr));
#endif // QT_CONFIG(shortcut)
        label_Pen->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Other", nullptr));
        label_Tool->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Tool", nullptr));
        groupBox_Overlay->setTitle(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Overlay", nullptr));
        label_Overlay->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Color", nullptr));
        label_Overlay_Intensity->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Intensity", nullptr));
        pushButton_Overlay_Color->setText(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Select", nullptr));
        doubleSpinBox_Intensity_Overlay->setPrefix(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Overlay: ", nullptr));
        doubleSpinBox_Intensity_Overlay->setSuffix(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "%", nullptr));
        doubleSpinBox_Intensity_Backgrouond->setPrefix(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "Background: ", nullptr));
        doubleSpinBox_Intensity_Backgrouond->setSuffix(QCoreApplication::translate("D_MAKRO_ManuelSegmentation", "%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_ManuelSegmentation: public Ui_D_MAKRO_ManuelSegmentation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_MANUELSEGMENTATION_H
