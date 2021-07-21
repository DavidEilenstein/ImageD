/********************************************************************************
** Form generated from reading UI file 'd_popup_listedit_numbers.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_POPUP_LISTEDIT_NUMBERS_H
#define UI_D_POPUP_LISTEDIT_NUMBERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_D_Popup_ListEdit_Numbers
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *plainTextEdit_Numbers;
    QPushButton *pushButton_Update;
    QLabel *label;
    QPushButton *pushButton_Ok;
    QGridLayout *gridLayout_NumbersPlot;

    void setupUi(QDialog *D_Popup_ListEdit_Numbers)
    {
        if (D_Popup_ListEdit_Numbers->objectName().isEmpty())
            D_Popup_ListEdit_Numbers->setObjectName(QString::fromUtf8("D_Popup_ListEdit_Numbers"));
        D_Popup_ListEdit_Numbers->resize(1082, 533);
        gridLayout = new QGridLayout(D_Popup_ListEdit_Numbers);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plainTextEdit_Numbers = new QPlainTextEdit(D_Popup_ListEdit_Numbers);
        plainTextEdit_Numbers->setObjectName(QString::fromUtf8("plainTextEdit_Numbers"));
        plainTextEdit_Numbers->setMinimumSize(QSize(50, 0));
        plainTextEdit_Numbers->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(plainTextEdit_Numbers, 2, 0, 1, 1);

        pushButton_Update = new QPushButton(D_Popup_ListEdit_Numbers);
        pushButton_Update->setObjectName(QString::fromUtf8("pushButton_Update"));

        gridLayout->addWidget(pushButton_Update, 1, 0, 1, 1);

        label = new QLabel(D_Popup_ListEdit_Numbers);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_Ok = new QPushButton(D_Popup_ListEdit_Numbers);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));

        gridLayout->addWidget(pushButton_Ok, 3, 0, 1, 1);

        gridLayout_NumbersPlot = new QGridLayout();
        gridLayout_NumbersPlot->setSpacing(0);
        gridLayout_NumbersPlot->setObjectName(QString::fromUtf8("gridLayout_NumbersPlot"));

        gridLayout->addLayout(gridLayout_NumbersPlot, 0, 1, 4, 2);

        QWidget::setTabOrder(pushButton_Ok, pushButton_Update);
        QWidget::setTabOrder(pushButton_Update, plainTextEdit_Numbers);

        retranslateUi(D_Popup_ListEdit_Numbers);

        QMetaObject::connectSlotsByName(D_Popup_ListEdit_Numbers);
    } // setupUi

    void retranslateUi(QDialog *D_Popup_ListEdit_Numbers)
    {
        D_Popup_ListEdit_Numbers->setWindowTitle(QApplication::translate("D_Popup_ListEdit_Numbers", "Dialog", nullptr));
        pushButton_Update->setText(QApplication::translate("D_Popup_ListEdit_Numbers", "Update (F5)", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_Update->setShortcut(QApplication::translate("D_Popup_ListEdit_Numbers", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        label->setText(QApplication::translate("D_Popup_ListEdit_Numbers", "Enter one number per line", nullptr));
        pushButton_Ok->setText(QApplication::translate("D_Popup_ListEdit_Numbers", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_Popup_ListEdit_Numbers: public Ui_D_Popup_ListEdit_Numbers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_POPUP_LISTEDIT_NUMBERS_H
