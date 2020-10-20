/********************************************************************************
** Form generated from reading UI file 'd_popup_plot.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_POPUP_PLOT_H
#define UI_D_POPUP_PLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>

QT_BEGIN_NAMESPACE

class Ui_D_Popup_Plot
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_Plot;

    void setupUi(QDialog *D_Popup_Plot)
    {
        if (D_Popup_Plot->objectName().isEmpty())
            D_Popup_Plot->setObjectName(QString::fromUtf8("D_Popup_Plot"));
        D_Popup_Plot->resize(595, 389);
        gridLayout_2 = new QGridLayout(D_Popup_Plot);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_Plot = new QGridLayout();
        gridLayout_Plot->setObjectName(QString::fromUtf8("gridLayout_Plot"));

        gridLayout_2->addLayout(gridLayout_Plot, 0, 0, 1, 1);


        retranslateUi(D_Popup_Plot);

        QMetaObject::connectSlotsByName(D_Popup_Plot);
    } // setupUi

    void retranslateUi(QDialog *D_Popup_Plot)
    {
        D_Popup_Plot->setWindowTitle(QCoreApplication::translate("D_Popup_Plot", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_Popup_Plot: public Ui_D_Popup_Plot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_POPUP_PLOT_H
