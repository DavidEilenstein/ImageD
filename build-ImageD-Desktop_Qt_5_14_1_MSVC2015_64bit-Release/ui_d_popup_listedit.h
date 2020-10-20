/********************************************************************************
** Form generated from reading UI file 'd_popup_listedit.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_POPUP_LISTEDIT_H
#define UI_D_POPUP_LISTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_D_Popup_ListEdit
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_Add;
    QPushButton *pushButton_Remove;
    QPushButton *pushButton_All;
    QComboBox *comboBox_List;
    QPushButton *pushButton_Clear;
    QPushButton *pushButton_Reset;
    QPushButton *pushButton_Done;
    QPlainTextEdit *plainTextEdit_Selection;

    void setupUi(QDialog *D_Popup_ListEdit)
    {
        if (D_Popup_ListEdit->objectName().isEmpty())
            D_Popup_ListEdit->setObjectName(QString::fromUtf8("D_Popup_ListEdit"));
        D_Popup_ListEdit->resize(348, 348);
        gridLayout = new QGridLayout(D_Popup_ListEdit);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_Add = new QPushButton(D_Popup_ListEdit);
        pushButton_Add->setObjectName(QString::fromUtf8("pushButton_Add"));
        pushButton_Add->setMinimumSize(QSize(50, 0));

        gridLayout->addWidget(pushButton_Add, 1, 0, 1, 1);

        pushButton_Remove = new QPushButton(D_Popup_ListEdit);
        pushButton_Remove->setObjectName(QString::fromUtf8("pushButton_Remove"));
        pushButton_Remove->setMinimumSize(QSize(50, 0));

        gridLayout->addWidget(pushButton_Remove, 1, 2, 1, 1);

        pushButton_All = new QPushButton(D_Popup_ListEdit);
        pushButton_All->setObjectName(QString::fromUtf8("pushButton_All"));
        pushButton_All->setMinimumSize(QSize(50, 0));

        gridLayout->addWidget(pushButton_All, 1, 1, 1, 1);

        comboBox_List = new QComboBox(D_Popup_ListEdit);
        comboBox_List->setObjectName(QString::fromUtf8("comboBox_List"));

        gridLayout->addWidget(comboBox_List, 0, 0, 1, 6);

        pushButton_Clear = new QPushButton(D_Popup_ListEdit);
        pushButton_Clear->setObjectName(QString::fromUtf8("pushButton_Clear"));
        pushButton_Clear->setMinimumSize(QSize(50, 0));

        gridLayout->addWidget(pushButton_Clear, 1, 3, 1, 1);

        pushButton_Reset = new QPushButton(D_Popup_ListEdit);
        pushButton_Reset->setObjectName(QString::fromUtf8("pushButton_Reset"));
        pushButton_Reset->setMinimumSize(QSize(50, 0));

        gridLayout->addWidget(pushButton_Reset, 1, 4, 1, 1);

        pushButton_Done = new QPushButton(D_Popup_ListEdit);
        pushButton_Done->setObjectName(QString::fromUtf8("pushButton_Done"));
        pushButton_Done->setMinimumSize(QSize(50, 0));

        gridLayout->addWidget(pushButton_Done, 1, 5, 1, 1);

        plainTextEdit_Selection = new QPlainTextEdit(D_Popup_ListEdit);
        plainTextEdit_Selection->setObjectName(QString::fromUtf8("plainTextEdit_Selection"));
        plainTextEdit_Selection->setReadOnly(true);

        gridLayout->addWidget(plainTextEdit_Selection, 2, 0, 1, 6);

        QWidget::setTabOrder(pushButton_Done, pushButton_Add);
        QWidget::setTabOrder(pushButton_Add, pushButton_All);
        QWidget::setTabOrder(pushButton_All, pushButton_Remove);
        QWidget::setTabOrder(pushButton_Remove, pushButton_Clear);
        QWidget::setTabOrder(pushButton_Clear, pushButton_Reset);
        QWidget::setTabOrder(pushButton_Reset, comboBox_List);
        QWidget::setTabOrder(comboBox_List, plainTextEdit_Selection);

        retranslateUi(D_Popup_ListEdit);

        QMetaObject::connectSlotsByName(D_Popup_ListEdit);
    } // setupUi

    void retranslateUi(QDialog *D_Popup_ListEdit)
    {
        D_Popup_ListEdit->setWindowTitle(QCoreApplication::translate("D_Popup_ListEdit", "Dialog", nullptr));
        pushButton_Add->setText(QCoreApplication::translate("D_Popup_ListEdit", "Add", nullptr));
        pushButton_Remove->setText(QCoreApplication::translate("D_Popup_ListEdit", "Remove", nullptr));
        pushButton_All->setText(QCoreApplication::translate("D_Popup_ListEdit", "All", nullptr));
        pushButton_Clear->setText(QCoreApplication::translate("D_Popup_ListEdit", "Clear", nullptr));
        pushButton_Reset->setText(QCoreApplication::translate("D_Popup_ListEdit", "Reset", nullptr));
        pushButton_Done->setText(QCoreApplication::translate("D_Popup_ListEdit", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_Popup_ListEdit: public Ui_D_Popup_ListEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_POPUP_LISTEDIT_H
