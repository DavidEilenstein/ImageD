/********************************************************************************
** Form generated from reading UI file 'd_popup_listselect.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_POPUP_LISTSELECT_H
#define UI_D_POPUP_LISTSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_D_Popup_ListSelect
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox_List;
    QPushButton *pushButton_Done;

    void setupUi(QDialog *D_Popup_ListSelect)
    {
        if (D_Popup_ListSelect->objectName().isEmpty())
            D_Popup_ListSelect->setObjectName(QString::fromUtf8("D_Popup_ListSelect"));
        D_Popup_ListSelect->resize(400, 67);
        gridLayout = new QGridLayout(D_Popup_ListSelect);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBox_List = new QComboBox(D_Popup_ListSelect);
        comboBox_List->setObjectName(QString::fromUtf8("comboBox_List"));

        gridLayout->addWidget(comboBox_List, 0, 0, 1, 1);

        pushButton_Done = new QPushButton(D_Popup_ListSelect);
        pushButton_Done->setObjectName(QString::fromUtf8("pushButton_Done"));

        gridLayout->addWidget(pushButton_Done, 1, 0, 1, 1);

        QWidget::setTabOrder(pushButton_Done, comboBox_List);

        retranslateUi(D_Popup_ListSelect);

        QMetaObject::connectSlotsByName(D_Popup_ListSelect);
    } // setupUi

    void retranslateUi(QDialog *D_Popup_ListSelect)
    {
        D_Popup_ListSelect->setWindowTitle(QApplication::translate("D_Popup_ListSelect", "Dialog", nullptr));
        pushButton_Done->setText(QApplication::translate("D_Popup_ListSelect", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_Popup_ListSelect: public Ui_D_Popup_ListSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_POPUP_LISTSELECT_H
