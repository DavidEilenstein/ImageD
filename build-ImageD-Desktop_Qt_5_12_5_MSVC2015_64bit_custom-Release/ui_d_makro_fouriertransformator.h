/********************************************************************************
** Form generated from reading UI file 'd_makro_fouriertransformator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_FOURIERTRANSFORMATOR_H
#define UI_D_MAKRO_FOURIERTRANSFORMATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_D_MAKRO_FourierTransformator
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_5;
    QGroupBox *groupBox_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_FourierTransformator)
    {
        if (D_MAKRO_FourierTransformator->objectName().isEmpty())
            D_MAKRO_FourierTransformator->setObjectName(QString::fromUtf8("D_MAKRO_FourierTransformator"));
        D_MAKRO_FourierTransformator->resize(800, 600);
        centralwidget = new QWidget(D_MAKRO_FourierTransformator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(groupBox_4, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        sizePolicy.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(groupBox_5, 0, 0, 1, 1);

        groupBox_6 = new QGroupBox(groupBox);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        sizePolicy1.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(groupBox_6, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        D_MAKRO_FourierTransformator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_FourierTransformator);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        D_MAKRO_FourierTransformator->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_FourierTransformator);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_FourierTransformator->setStatusBar(statusbar);

        retranslateUi(D_MAKRO_FourierTransformator);

        QMetaObject::connectSlotsByName(D_MAKRO_FourierTransformator);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_FourierTransformator)
    {
        D_MAKRO_FourierTransformator->setWindowTitle(QApplication::translate("D_MAKRO_FourierTransformator", "MainWindow", nullptr));
        groupBox_2->setTitle(QApplication::translate("D_MAKRO_FourierTransformator", "Space", nullptr));
        groupBox_3->setTitle(QApplication::translate("D_MAKRO_FourierTransformator", "GroupBox", nullptr));
        groupBox_4->setTitle(QApplication::translate("D_MAKRO_FourierTransformator", "GroupBox", nullptr));
        groupBox->setTitle(QApplication::translate("D_MAKRO_FourierTransformator", "Frequencies", nullptr));
        groupBox_5->setTitle(QApplication::translate("D_MAKRO_FourierTransformator", "GroupBox", nullptr));
        groupBox_6->setTitle(QApplication::translate("D_MAKRO_FourierTransformator", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_FourierTransformator: public Ui_D_MAKRO_FourierTransformator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_FOURIERTRANSFORMATOR_H
