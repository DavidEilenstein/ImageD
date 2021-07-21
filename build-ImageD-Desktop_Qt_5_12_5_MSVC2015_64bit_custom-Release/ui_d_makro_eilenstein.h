/********************************************************************************
** Form generated from reading UI file 'd_makro_eilenstein.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_EILENSTEIN_H
#define UI_D_MAKRO_EILENSTEIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_Eilenstein
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_Out;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_Out_Select;
    QPushButton *pushButton_Out_Open;
    QLabel *label_Out_Path;
    QSpacerItem *verticalSpacer_Out;
    QSpacerItem *horizontalSpacer_Out;
    QGroupBox *groupBox_Run;
    QGridLayout *gridLayout_2;
    QLabel *label_Run_Stack;
    QSpacerItem *verticalSpacer_Run;
    QPushButton *pushButton_Run;
    QSpacerItem *horizontalSpacer_Run;
    QGroupBox *groupBox_Set;
    QGridLayout *gridLayout_4;
    QLabel *label_Min;
    QLabel *label_Max;
    QLabel *label_Step;
    QSpacerItem *horizontalSpacer_Set;
    QLabel *label_Size;
    QSpinBox *spinBox_Min;
    QSpinBox *spinBox_Max;
    QSpinBox *spinBox_Step;
    QLabel *label_Off;
    QDoubleSpinBox *doubleSpinBox_Off_Min;
    QDoubleSpinBox *doubleSpinBox_Off_Max;
    QDoubleSpinBox *doubleSpinBox_Off_Step;
    QSpacerItem *verticalSpacer_Set;
    QGroupBox *groupBox_In;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_Img_Add;
    QPushButton *pushButton_img_Clear;
    QComboBox *comboBox_Img;
    QGraphicsView *graphicsView_Img;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_Eilenstein)
    {
        if (D_MAKRO_Eilenstein->objectName().isEmpty())
            D_MAKRO_Eilenstein->setObjectName(QString::fromUtf8("D_MAKRO_Eilenstein"));
        D_MAKRO_Eilenstein->resize(916, 696);
        centralwidget = new QWidget(D_MAKRO_Eilenstein);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_Out = new QGroupBox(centralwidget);
        groupBox_Out->setObjectName(QString::fromUtf8("groupBox_Out"));
        gridLayout_3 = new QGridLayout(groupBox_Out);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_Out_Select = new QPushButton(groupBox_Out);
        pushButton_Out_Select->setObjectName(QString::fromUtf8("pushButton_Out_Select"));
        pushButton_Out_Select->setMinimumSize(QSize(75, 0));
        pushButton_Out_Select->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(pushButton_Out_Select, 0, 0, 1, 1);

        pushButton_Out_Open = new QPushButton(groupBox_Out);
        pushButton_Out_Open->setObjectName(QString::fromUtf8("pushButton_Out_Open"));
        pushButton_Out_Open->setEnabled(false);
        pushButton_Out_Open->setMinimumSize(QSize(75, 0));
        pushButton_Out_Open->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(pushButton_Out_Open, 0, 1, 1, 1);

        label_Out_Path = new QLabel(groupBox_Out);
        label_Out_Path->setObjectName(QString::fromUtf8("label_Out_Path"));
        label_Out_Path->setMaximumSize(QSize(156, 22));

        gridLayout_3->addWidget(label_Out_Path, 1, 0, 1, 2);

        verticalSpacer_Out = new QSpacerItem(153, 15, QSizePolicy::Minimum, QSizePolicy::Ignored);

        gridLayout_3->addItem(verticalSpacer_Out, 2, 0, 1, 2);

        horizontalSpacer_Out = new QSpacerItem(80, 44, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_Out, 0, 2, 2, 1);


        gridLayout->addWidget(groupBox_Out, 1, 1, 1, 1);

        groupBox_Run = new QGroupBox(centralwidget);
        groupBox_Run->setObjectName(QString::fromUtf8("groupBox_Run"));
        groupBox_Run->setEnabled(false);
        gridLayout_2 = new QGridLayout(groupBox_Run);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_Run_Stack = new QLabel(groupBox_Run);
        label_Run_Stack->setObjectName(QString::fromUtf8("label_Run_Stack"));
        label_Run_Stack->setMinimumSize(QSize(156, 0));
        label_Run_Stack->setMaximumSize(QSize(156, 16777215));

        gridLayout_2->addWidget(label_Run_Stack, 1, 0, 1, 1);

        verticalSpacer_Run = new QSpacerItem(20, 11, QSizePolicy::Minimum, QSizePolicy::Ignored);

        gridLayout_2->addItem(verticalSpacer_Run, 2, 0, 1, 1);

        pushButton_Run = new QPushButton(groupBox_Run);
        pushButton_Run->setObjectName(QString::fromUtf8("pushButton_Run"));
        pushButton_Run->setMinimumSize(QSize(156, 0));
        pushButton_Run->setMaximumSize(QSize(156, 16777215));

        gridLayout_2->addWidget(pushButton_Run, 0, 0, 1, 2);

        horizontalSpacer_Run = new QSpacerItem(73, 48, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_Run, 0, 2, 2, 1);


        gridLayout->addWidget(groupBox_Run, 1, 2, 1, 1);

        groupBox_Set = new QGroupBox(centralwidget);
        groupBox_Set->setObjectName(QString::fromUtf8("groupBox_Set"));
        gridLayout_4 = new QGridLayout(groupBox_Set);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_Min = new QLabel(groupBox_Set);
        label_Min->setObjectName(QString::fromUtf8("label_Min"));
        label_Min->setMinimumSize(QSize(75, 0));
        label_Min->setMaximumSize(QSize(75, 16777215));

        gridLayout_4->addWidget(label_Min, 0, 1, 1, 1);

        label_Max = new QLabel(groupBox_Set);
        label_Max->setObjectName(QString::fromUtf8("label_Max"));
        label_Max->setMinimumSize(QSize(75, 0));
        label_Max->setMaximumSize(QSize(75, 16777215));

        gridLayout_4->addWidget(label_Max, 0, 2, 1, 1);

        label_Step = new QLabel(groupBox_Set);
        label_Step->setObjectName(QString::fromUtf8("label_Step"));
        label_Step->setMinimumSize(QSize(75, 0));
        label_Step->setMaximumSize(QSize(75, 16777215));

        gridLayout_4->addWidget(label_Step, 0, 3, 1, 1);

        horizontalSpacer_Set = new QSpacerItem(4, 62, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_Set, 0, 4, 3, 1);

        label_Size = new QLabel(groupBox_Set);
        label_Size->setObjectName(QString::fromUtf8("label_Size"));
        label_Size->setMinimumSize(QSize(75, 0));
        label_Size->setMaximumSize(QSize(75, 16777215));

        gridLayout_4->addWidget(label_Size, 1, 0, 1, 1);

        spinBox_Min = new QSpinBox(groupBox_Set);
        spinBox_Min->setObjectName(QString::fromUtf8("spinBox_Min"));
        spinBox_Min->setMinimumSize(QSize(75, 0));
        spinBox_Min->setMaximumSize(QSize(75, 16777215));
        spinBox_Min->setMinimum(1);
        spinBox_Min->setSingleStep(2);
        spinBox_Min->setValue(3);

        gridLayout_4->addWidget(spinBox_Min, 1, 1, 1, 1);

        spinBox_Max = new QSpinBox(groupBox_Set);
        spinBox_Max->setObjectName(QString::fromUtf8("spinBox_Max"));
        spinBox_Max->setMinimumSize(QSize(75, 0));
        spinBox_Max->setMaximumSize(QSize(75, 16777215));
        spinBox_Max->setMinimum(3);
        spinBox_Max->setSingleStep(2);
        spinBox_Max->setValue(15);

        gridLayout_4->addWidget(spinBox_Max, 1, 2, 1, 1);

        spinBox_Step = new QSpinBox(groupBox_Set);
        spinBox_Step->setObjectName(QString::fromUtf8("spinBox_Step"));
        spinBox_Step->setMinimumSize(QSize(75, 0));
        spinBox_Step->setMaximumSize(QSize(75, 16777215));
        spinBox_Step->setMinimum(1);
        spinBox_Step->setValue(2);

        gridLayout_4->addWidget(spinBox_Step, 1, 3, 1, 1);

        label_Off = new QLabel(groupBox_Set);
        label_Off->setObjectName(QString::fromUtf8("label_Off"));
        label_Off->setMinimumSize(QSize(75, 0));
        label_Off->setMaximumSize(QSize(75, 16777215));

        gridLayout_4->addWidget(label_Off, 2, 0, 1, 1);

        doubleSpinBox_Off_Min = new QDoubleSpinBox(groupBox_Set);
        doubleSpinBox_Off_Min->setObjectName(QString::fromUtf8("doubleSpinBox_Off_Min"));
        doubleSpinBox_Off_Min->setMinimumSize(QSize(75, 0));
        doubleSpinBox_Off_Min->setMaximumSize(QSize(75, 16777215));
        doubleSpinBox_Off_Min->setDecimals(3);
        doubleSpinBox_Off_Min->setMinimum(-256.000000000000000);
        doubleSpinBox_Off_Min->setMaximum(255.000000000000000);
        doubleSpinBox_Off_Min->setValue(-16.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_Off_Min, 2, 1, 1, 1);

        doubleSpinBox_Off_Max = new QDoubleSpinBox(groupBox_Set);
        doubleSpinBox_Off_Max->setObjectName(QString::fromUtf8("doubleSpinBox_Off_Max"));
        doubleSpinBox_Off_Max->setMinimumSize(QSize(75, 0));
        doubleSpinBox_Off_Max->setMaximumSize(QSize(75, 16777215));
        doubleSpinBox_Off_Max->setDecimals(3);
        doubleSpinBox_Off_Max->setMinimum(-256.000000000000000);
        doubleSpinBox_Off_Max->setMaximum(255.000000000000000);
        doubleSpinBox_Off_Max->setValue(16.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_Off_Max, 2, 2, 1, 1);

        doubleSpinBox_Off_Step = new QDoubleSpinBox(groupBox_Set);
        doubleSpinBox_Off_Step->setObjectName(QString::fromUtf8("doubleSpinBox_Off_Step"));
        doubleSpinBox_Off_Step->setMinimumSize(QSize(75, 0));
        doubleSpinBox_Off_Step->setMaximumSize(QSize(75, 16777215));
        doubleSpinBox_Off_Step->setDecimals(3);
        doubleSpinBox_Off_Step->setMinimum(-256.000000000000000);
        doubleSpinBox_Off_Step->setMaximum(255.000000000000000);
        doubleSpinBox_Off_Step->setValue(4.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_Off_Step, 2, 3, 1, 1);

        verticalSpacer_Set = new QSpacerItem(321, 13, QSizePolicy::Minimum, QSizePolicy::Ignored);

        gridLayout_4->addItem(verticalSpacer_Set, 3, 0, 1, 4);


        gridLayout->addWidget(groupBox_Set, 1, 0, 1, 1);

        groupBox_In = new QGroupBox(centralwidget);
        groupBox_In->setObjectName(QString::fromUtf8("groupBox_In"));
        gridLayout_5 = new QGridLayout(groupBox_In);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pushButton_Img_Add = new QPushButton(groupBox_In);
        pushButton_Img_Add->setObjectName(QString::fromUtf8("pushButton_Img_Add"));
        pushButton_Img_Add->setMaximumSize(QSize(150, 16777215));

        gridLayout_5->addWidget(pushButton_Img_Add, 0, 0, 1, 1);

        pushButton_img_Clear = new QPushButton(groupBox_In);
        pushButton_img_Clear->setObjectName(QString::fromUtf8("pushButton_img_Clear"));
        pushButton_img_Clear->setMaximumSize(QSize(150, 16777215));

        gridLayout_5->addWidget(pushButton_img_Clear, 0, 1, 1, 1);

        comboBox_Img = new QComboBox(groupBox_In);
        comboBox_Img->setObjectName(QString::fromUtf8("comboBox_Img"));

        gridLayout_5->addWidget(comboBox_Img, 0, 2, 1, 1);

        graphicsView_Img = new QGraphicsView(groupBox_In);
        graphicsView_Img->setObjectName(QString::fromUtf8("graphicsView_Img"));

        gridLayout_5->addWidget(graphicsView_Img, 1, 0, 1, 3);


        gridLayout->addWidget(groupBox_In, 0, 0, 1, 3);

        D_MAKRO_Eilenstein->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_Eilenstein);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 916, 21));
        D_MAKRO_Eilenstein->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_Eilenstein);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_Eilenstein->setStatusBar(statusbar);

        retranslateUi(D_MAKRO_Eilenstein);

        QMetaObject::connectSlotsByName(D_MAKRO_Eilenstein);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_Eilenstein)
    {
        D_MAKRO_Eilenstein->setWindowTitle(QApplication::translate("D_MAKRO_Eilenstein", "MainWindow", nullptr));
        groupBox_Out->setTitle(QApplication::translate("D_MAKRO_Eilenstein", "Output", nullptr));
        pushButton_Out_Select->setText(QApplication::translate("D_MAKRO_Eilenstein", "Select", nullptr));
        pushButton_Out_Open->setText(QApplication::translate("D_MAKRO_Eilenstein", "Open", nullptr));
        label_Out_Path->setText(QApplication::translate("D_MAKRO_Eilenstein", "Output Path", nullptr));
        groupBox_Run->setTitle(QApplication::translate("D_MAKRO_Eilenstein", "Run", nullptr));
        label_Run_Stack->setText(QApplication::translate("D_MAKRO_Eilenstein", "Process X Images", nullptr));
        pushButton_Run->setText(QApplication::translate("D_MAKRO_Eilenstein", "Process Stack", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_Run->setShortcut(QApplication::translate("D_MAKRO_Eilenstein", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        groupBox_Set->setTitle(QApplication::translate("D_MAKRO_Eilenstein", "Settings", nullptr));
        label_Min->setText(QApplication::translate("D_MAKRO_Eilenstein", "Min", nullptr));
        label_Max->setText(QApplication::translate("D_MAKRO_Eilenstein", "Max", nullptr));
        label_Step->setText(QApplication::translate("D_MAKRO_Eilenstein", "Step", nullptr));
        label_Size->setText(QApplication::translate("D_MAKRO_Eilenstein", "Size", nullptr));
        label_Off->setText(QApplication::translate("D_MAKRO_Eilenstein", "Offset", nullptr));
        groupBox_In->setTitle(QApplication::translate("D_MAKRO_Eilenstein", "Input", nullptr));
        pushButton_Img_Add->setText(QApplication::translate("D_MAKRO_Eilenstein", "Add Images", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_Img_Add->setShortcut(QApplication::translate("D_MAKRO_Eilenstein", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_img_Clear->setText(QApplication::translate("D_MAKRO_Eilenstein", "Clear Images", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_Eilenstein: public Ui_D_MAKRO_Eilenstein {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_EILENSTEIN_H
