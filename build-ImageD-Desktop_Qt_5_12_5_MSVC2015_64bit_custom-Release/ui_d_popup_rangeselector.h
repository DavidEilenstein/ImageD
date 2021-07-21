/********************************************************************************
** Form generated from reading UI file 'd_popup_rangeselector.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_POPUP_RANGESELECTOR_H
#define UI_D_POPUP_RANGESELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_D_PopUp_RangeSelector
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_Z;
    QGridLayout *gridLayout_4;
    QSlider *horizontalSlider_Z_to;
    QSpinBox *spinBox_Z_from;
    QSlider *horizontalSlider_Z_from;
    QFrame *line_Z;
    QLabel *label_Z_ext;
    QSpinBox *spinBox_Z_to;
    QLabel *label_Z_imp;
    QGroupBox *groupBox_S;
    QGridLayout *gridLayout_5;
    QSlider *horizontalSlider_S_to;
    QSpinBox *spinBox_S_from;
    QSlider *horizontalSlider_S_from;
    QSpinBox *spinBox_S_to;
    QFrame *line_S;
    QLabel *label_S_ext;
    QLabel *label_S_imp;
    QGroupBox *groupBox_Y;
    QGridLayout *gridLayout_3;
    QSlider *horizontalSlider_Y_to;
    QLabel *label_Y_ext;
    QSpinBox *spinBox_Y_from;
    QSpinBox *spinBox_Y_to;
    QSlider *horizontalSlider_Y_from;
    QFrame *line_Y;
    QLabel *label_Y_imp;
    QGroupBox *groupBox_T;
    QGridLayout *gridLayout_6;
    QLabel *label_T_ext;
    QSlider *horizontalSlider_T_from;
    QSlider *horizontalSlider_T_to;
    QSpinBox *spinBox_T_from;
    QFrame *line_T;
    QSpinBox *spinBox_T_to;
    QLabel *label_T_imp;
    QGroupBox *groupBox_P;
    QGridLayout *gridLayout_7;
    QLabel *label_P_ext;
    QSlider *horizontalSlider_P_from;
    QSlider *horizontalSlider_P_to;
    QSpinBox *spinBox_P_from;
    QSpinBox *spinBox_P_to;
    QFrame *line_P;
    QLabel *label_P_imp;
    QGroupBox *groupBox_X;
    QGridLayout *gridLayout_2;
    QSpinBox *spinBox_X_to;
    QSlider *horizontalSlider_X_to;
    QLabel *label_X_ext;
    QSpinBox *spinBox_X_from;
    QSlider *horizontalSlider_X_from;
    QFrame *line_X;
    QLabel *label_X_imp;
    QGroupBox *groupBox_Overall;
    QGridLayout *gridLayout_8;
    QLabel *label_Dims;
    QLabel *label_Volume;
    QPushButton *pushButton_Done;

    void setupUi(QDialog *D_PopUp_RangeSelector)
    {
        if (D_PopUp_RangeSelector->objectName().isEmpty())
            D_PopUp_RangeSelector->setObjectName(QString::fromUtf8("D_PopUp_RangeSelector"));
        D_PopUp_RangeSelector->resize(773, 555);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(D_PopUp_RangeSelector->sizePolicy().hasHeightForWidth());
        D_PopUp_RangeSelector->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(D_PopUp_RangeSelector);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_Z = new QGroupBox(D_PopUp_RangeSelector);
        groupBox_Z->setObjectName(QString::fromUtf8("groupBox_Z"));
        sizePolicy.setHeightForWidth(groupBox_Z->sizePolicy().hasHeightForWidth());
        groupBox_Z->setSizePolicy(sizePolicy);
        groupBox_Z->setAlignment(Qt::AlignCenter);
        gridLayout_4 = new QGridLayout(groupBox_Z);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(4);
        gridLayout_4->setVerticalSpacing(1);
        gridLayout_4->setContentsMargins(3, 3, 3, 3);
        horizontalSlider_Z_to = new QSlider(groupBox_Z);
        horizontalSlider_Z_to->setObjectName(QString::fromUtf8("horizontalSlider_Z_to"));
        horizontalSlider_Z_to->setMaximum(9);
        horizontalSlider_Z_to->setValue(9);
        horizontalSlider_Z_to->setOrientation(Qt::Horizontal);
        horizontalSlider_Z_to->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_Z_to->setTickInterval(1);

        gridLayout_4->addWidget(horizontalSlider_Z_to, 1, 1, 1, 1);

        spinBox_Z_from = new QSpinBox(groupBox_Z);
        spinBox_Z_from->setObjectName(QString::fromUtf8("spinBox_Z_from"));
        spinBox_Z_from->setMinimumSize(QSize(120, 0));
        spinBox_Z_from->setMaximumSize(QSize(120, 16777215));
        spinBox_Z_from->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Z_from->setMaximum(9);

        gridLayout_4->addWidget(spinBox_Z_from, 0, 0, 1, 1);

        horizontalSlider_Z_from = new QSlider(groupBox_Z);
        horizontalSlider_Z_from->setObjectName(QString::fromUtf8("horizontalSlider_Z_from"));
        horizontalSlider_Z_from->setMaximum(9);
        horizontalSlider_Z_from->setOrientation(Qt::Horizontal);
        horizontalSlider_Z_from->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_Z_from->setTickInterval(1);

        gridLayout_4->addWidget(horizontalSlider_Z_from, 0, 1, 1, 1);

        line_Z = new QFrame(groupBox_Z);
        line_Z->setObjectName(QString::fromUtf8("line_Z"));
        line_Z->setFrameShape(QFrame::VLine);
        line_Z->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_Z, 0, 2, 2, 1);

        label_Z_ext = new QLabel(groupBox_Z);
        label_Z_ext->setObjectName(QString::fromUtf8("label_Z_ext"));
        label_Z_ext->setMinimumSize(QSize(120, 0));
        label_Z_ext->setMaximumSize(QSize(120, 16777215));

        gridLayout_4->addWidget(label_Z_ext, 0, 3, 1, 1);

        spinBox_Z_to = new QSpinBox(groupBox_Z);
        spinBox_Z_to->setObjectName(QString::fromUtf8("spinBox_Z_to"));
        spinBox_Z_to->setMinimumSize(QSize(120, 0));
        spinBox_Z_to->setMaximumSize(QSize(120, 16777215));
        spinBox_Z_to->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Z_to->setMaximum(9);
        spinBox_Z_to->setValue(9);

        gridLayout_4->addWidget(spinBox_Z_to, 1, 0, 1, 1);

        label_Z_imp = new QLabel(groupBox_Z);
        label_Z_imp->setObjectName(QString::fromUtf8("label_Z_imp"));
        label_Z_imp->setMinimumSize(QSize(120, 0));
        label_Z_imp->setMaximumSize(QSize(120, 16777215));

        gridLayout_4->addWidget(label_Z_imp, 1, 3, 1, 1);


        gridLayout->addWidget(groupBox_Z, 7, 0, 1, 1);

        groupBox_S = new QGroupBox(D_PopUp_RangeSelector);
        groupBox_S->setObjectName(QString::fromUtf8("groupBox_S"));
        sizePolicy.setHeightForWidth(groupBox_S->sizePolicy().hasHeightForWidth());
        groupBox_S->setSizePolicy(sizePolicy);
        groupBox_S->setAlignment(Qt::AlignCenter);
        gridLayout_5 = new QGridLayout(groupBox_S);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(4);
        gridLayout_5->setVerticalSpacing(1);
        gridLayout_5->setContentsMargins(3, 3, 3, 3);
        horizontalSlider_S_to = new QSlider(groupBox_S);
        horizontalSlider_S_to->setObjectName(QString::fromUtf8("horizontalSlider_S_to"));
        horizontalSlider_S_to->setMaximum(9);
        horizontalSlider_S_to->setValue(9);
        horizontalSlider_S_to->setOrientation(Qt::Horizontal);
        horizontalSlider_S_to->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_S_to->setTickInterval(1);

        gridLayout_5->addWidget(horizontalSlider_S_to, 1, 1, 1, 1);

        spinBox_S_from = new QSpinBox(groupBox_S);
        spinBox_S_from->setObjectName(QString::fromUtf8("spinBox_S_from"));
        spinBox_S_from->setMinimumSize(QSize(120, 0));
        spinBox_S_from->setMaximumSize(QSize(120, 16777215));
        spinBox_S_from->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_S_from->setMaximum(9);

        gridLayout_5->addWidget(spinBox_S_from, 0, 0, 1, 1);

        horizontalSlider_S_from = new QSlider(groupBox_S);
        horizontalSlider_S_from->setObjectName(QString::fromUtf8("horizontalSlider_S_from"));
        horizontalSlider_S_from->setMaximum(9);
        horizontalSlider_S_from->setOrientation(Qt::Horizontal);
        horizontalSlider_S_from->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_S_from->setTickInterval(1);

        gridLayout_5->addWidget(horizontalSlider_S_from, 0, 1, 1, 1);

        spinBox_S_to = new QSpinBox(groupBox_S);
        spinBox_S_to->setObjectName(QString::fromUtf8("spinBox_S_to"));
        spinBox_S_to->setMinimumSize(QSize(120, 0));
        spinBox_S_to->setMaximumSize(QSize(120, 16777215));
        spinBox_S_to->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_S_to->setMaximum(9);
        spinBox_S_to->setValue(9);

        gridLayout_5->addWidget(spinBox_S_to, 1, 0, 1, 1);

        line_S = new QFrame(groupBox_S);
        line_S->setObjectName(QString::fromUtf8("line_S"));
        line_S->setFrameShape(QFrame::VLine);
        line_S->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_S, 0, 2, 2, 1);

        label_S_ext = new QLabel(groupBox_S);
        label_S_ext->setObjectName(QString::fromUtf8("label_S_ext"));
        label_S_ext->setMinimumSize(QSize(120, 0));
        label_S_ext->setMaximumSize(QSize(120, 16777215));

        gridLayout_5->addWidget(label_S_ext, 0, 3, 1, 1);

        label_S_imp = new QLabel(groupBox_S);
        label_S_imp->setObjectName(QString::fromUtf8("label_S_imp"));
        label_S_imp->setMinimumSize(QSize(120, 0));
        label_S_imp->setMaximumSize(QSize(120, 16777215));

        gridLayout_5->addWidget(label_S_imp, 1, 3, 1, 1);


        gridLayout->addWidget(groupBox_S, 9, 0, 1, 1);

        groupBox_Y = new QGroupBox(D_PopUp_RangeSelector);
        groupBox_Y->setObjectName(QString::fromUtf8("groupBox_Y"));
        sizePolicy.setHeightForWidth(groupBox_Y->sizePolicy().hasHeightForWidth());
        groupBox_Y->setSizePolicy(sizePolicy);
        groupBox_Y->setAlignment(Qt::AlignCenter);
        gridLayout_3 = new QGridLayout(groupBox_Y);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(4);
        gridLayout_3->setVerticalSpacing(1);
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        horizontalSlider_Y_to = new QSlider(groupBox_Y);
        horizontalSlider_Y_to->setObjectName(QString::fromUtf8("horizontalSlider_Y_to"));
        horizontalSlider_Y_to->setMaximum(9);
        horizontalSlider_Y_to->setValue(9);
        horizontalSlider_Y_to->setOrientation(Qt::Horizontal);
        horizontalSlider_Y_to->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_Y_to->setTickInterval(1);

        gridLayout_3->addWidget(horizontalSlider_Y_to, 1, 1, 1, 1);

        label_Y_ext = new QLabel(groupBox_Y);
        label_Y_ext->setObjectName(QString::fromUtf8("label_Y_ext"));
        label_Y_ext->setMinimumSize(QSize(120, 0));
        label_Y_ext->setMaximumSize(QSize(120, 16777215));

        gridLayout_3->addWidget(label_Y_ext, 0, 3, 1, 1);

        spinBox_Y_from = new QSpinBox(groupBox_Y);
        spinBox_Y_from->setObjectName(QString::fromUtf8("spinBox_Y_from"));
        spinBox_Y_from->setMinimumSize(QSize(120, 0));
        spinBox_Y_from->setMaximumSize(QSize(120, 16777215));
        spinBox_Y_from->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Y_from->setMaximum(9);

        gridLayout_3->addWidget(spinBox_Y_from, 0, 0, 1, 1);

        spinBox_Y_to = new QSpinBox(groupBox_Y);
        spinBox_Y_to->setObjectName(QString::fromUtf8("spinBox_Y_to"));
        spinBox_Y_to->setMinimumSize(QSize(120, 0));
        spinBox_Y_to->setMaximumSize(QSize(120, 16777215));
        spinBox_Y_to->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_Y_to->setMaximum(9);
        spinBox_Y_to->setValue(9);

        gridLayout_3->addWidget(spinBox_Y_to, 1, 0, 1, 1);

        horizontalSlider_Y_from = new QSlider(groupBox_Y);
        horizontalSlider_Y_from->setObjectName(QString::fromUtf8("horizontalSlider_Y_from"));
        horizontalSlider_Y_from->setMaximum(9);
        horizontalSlider_Y_from->setOrientation(Qt::Horizontal);
        horizontalSlider_Y_from->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_Y_from->setTickInterval(1);

        gridLayout_3->addWidget(horizontalSlider_Y_from, 0, 1, 1, 1);

        line_Y = new QFrame(groupBox_Y);
        line_Y->setObjectName(QString::fromUtf8("line_Y"));
        line_Y->setFrameShape(QFrame::VLine);
        line_Y->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_Y, 0, 2, 2, 1);

        label_Y_imp = new QLabel(groupBox_Y);
        label_Y_imp->setObjectName(QString::fromUtf8("label_Y_imp"));
        label_Y_imp->setMinimumSize(QSize(120, 0));
        label_Y_imp->setMaximumSize(QSize(120, 16777215));

        gridLayout_3->addWidget(label_Y_imp, 1, 3, 1, 1);


        gridLayout->addWidget(groupBox_Y, 6, 0, 1, 1);

        groupBox_T = new QGroupBox(D_PopUp_RangeSelector);
        groupBox_T->setObjectName(QString::fromUtf8("groupBox_T"));
        sizePolicy.setHeightForWidth(groupBox_T->sizePolicy().hasHeightForWidth());
        groupBox_T->setSizePolicy(sizePolicy);
        groupBox_T->setAlignment(Qt::AlignCenter);
        gridLayout_6 = new QGridLayout(groupBox_T);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(4);
        gridLayout_6->setVerticalSpacing(1);
        gridLayout_6->setContentsMargins(3, 3, 3, 3);
        label_T_ext = new QLabel(groupBox_T);
        label_T_ext->setObjectName(QString::fromUtf8("label_T_ext"));
        label_T_ext->setMinimumSize(QSize(120, 0));
        label_T_ext->setMaximumSize(QSize(120, 16777215));

        gridLayout_6->addWidget(label_T_ext, 0, 3, 1, 1);

        horizontalSlider_T_from = new QSlider(groupBox_T);
        horizontalSlider_T_from->setObjectName(QString::fromUtf8("horizontalSlider_T_from"));
        horizontalSlider_T_from->setMaximum(9);
        horizontalSlider_T_from->setOrientation(Qt::Horizontal);
        horizontalSlider_T_from->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_T_from->setTickInterval(1);

        gridLayout_6->addWidget(horizontalSlider_T_from, 0, 1, 1, 1);

        horizontalSlider_T_to = new QSlider(groupBox_T);
        horizontalSlider_T_to->setObjectName(QString::fromUtf8("horizontalSlider_T_to"));
        horizontalSlider_T_to->setMaximum(9);
        horizontalSlider_T_to->setValue(9);
        horizontalSlider_T_to->setOrientation(Qt::Horizontal);
        horizontalSlider_T_to->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_T_to->setTickInterval(1);

        gridLayout_6->addWidget(horizontalSlider_T_to, 1, 1, 1, 1);

        spinBox_T_from = new QSpinBox(groupBox_T);
        spinBox_T_from->setObjectName(QString::fromUtf8("spinBox_T_from"));
        spinBox_T_from->setMinimumSize(QSize(120, 0));
        spinBox_T_from->setMaximumSize(QSize(120, 16777215));
        spinBox_T_from->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_T_from->setMaximum(9);

        gridLayout_6->addWidget(spinBox_T_from, 0, 0, 1, 1);

        line_T = new QFrame(groupBox_T);
        line_T->setObjectName(QString::fromUtf8("line_T"));
        line_T->setFrameShape(QFrame::VLine);
        line_T->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_T, 0, 2, 2, 1);

        spinBox_T_to = new QSpinBox(groupBox_T);
        spinBox_T_to->setObjectName(QString::fromUtf8("spinBox_T_to"));
        spinBox_T_to->setMinimumSize(QSize(120, 0));
        spinBox_T_to->setMaximumSize(QSize(120, 16777215));
        spinBox_T_to->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_T_to->setMaximum(9);
        spinBox_T_to->setValue(9);

        gridLayout_6->addWidget(spinBox_T_to, 1, 0, 1, 1);

        label_T_imp = new QLabel(groupBox_T);
        label_T_imp->setObjectName(QString::fromUtf8("label_T_imp"));
        label_T_imp->setMinimumSize(QSize(120, 0));
        label_T_imp->setMaximumSize(QSize(120, 16777215));

        gridLayout_6->addWidget(label_T_imp, 1, 3, 1, 1);


        gridLayout->addWidget(groupBox_T, 8, 0, 1, 1);

        groupBox_P = new QGroupBox(D_PopUp_RangeSelector);
        groupBox_P->setObjectName(QString::fromUtf8("groupBox_P"));
        sizePolicy.setHeightForWidth(groupBox_P->sizePolicy().hasHeightForWidth());
        groupBox_P->setSizePolicy(sizePolicy);
        groupBox_P->setAlignment(Qt::AlignCenter);
        gridLayout_7 = new QGridLayout(groupBox_P);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(4);
        gridLayout_7->setVerticalSpacing(1);
        gridLayout_7->setContentsMargins(3, 3, 3, 3);
        label_P_ext = new QLabel(groupBox_P);
        label_P_ext->setObjectName(QString::fromUtf8("label_P_ext"));
        label_P_ext->setMinimumSize(QSize(120, 0));
        label_P_ext->setMaximumSize(QSize(120, 16777215));

        gridLayout_7->addWidget(label_P_ext, 0, 3, 1, 1);

        horizontalSlider_P_from = new QSlider(groupBox_P);
        horizontalSlider_P_from->setObjectName(QString::fromUtf8("horizontalSlider_P_from"));
        horizontalSlider_P_from->setMaximum(9);
        horizontalSlider_P_from->setOrientation(Qt::Horizontal);
        horizontalSlider_P_from->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_P_from->setTickInterval(1);

        gridLayout_7->addWidget(horizontalSlider_P_from, 0, 1, 1, 1);

        horizontalSlider_P_to = new QSlider(groupBox_P);
        horizontalSlider_P_to->setObjectName(QString::fromUtf8("horizontalSlider_P_to"));
        horizontalSlider_P_to->setMaximum(9);
        horizontalSlider_P_to->setValue(9);
        horizontalSlider_P_to->setOrientation(Qt::Horizontal);
        horizontalSlider_P_to->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_P_to->setTickInterval(1);

        gridLayout_7->addWidget(horizontalSlider_P_to, 1, 1, 1, 1);

        spinBox_P_from = new QSpinBox(groupBox_P);
        spinBox_P_from->setObjectName(QString::fromUtf8("spinBox_P_from"));
        spinBox_P_from->setMinimumSize(QSize(120, 0));
        spinBox_P_from->setMaximumSize(QSize(120, 16777215));
        spinBox_P_from->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_P_from->setMaximum(9);

        gridLayout_7->addWidget(spinBox_P_from, 0, 0, 1, 1);

        spinBox_P_to = new QSpinBox(groupBox_P);
        spinBox_P_to->setObjectName(QString::fromUtf8("spinBox_P_to"));
        spinBox_P_to->setMinimumSize(QSize(120, 0));
        spinBox_P_to->setMaximumSize(QSize(120, 16777215));
        spinBox_P_to->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_P_to->setMaximum(9);
        spinBox_P_to->setValue(9);

        gridLayout_7->addWidget(spinBox_P_to, 1, 0, 1, 1);

        line_P = new QFrame(groupBox_P);
        line_P->setObjectName(QString::fromUtf8("line_P"));
        line_P->setFrameShape(QFrame::VLine);
        line_P->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_P, 0, 2, 2, 1);

        label_P_imp = new QLabel(groupBox_P);
        label_P_imp->setObjectName(QString::fromUtf8("label_P_imp"));
        label_P_imp->setMinimumSize(QSize(120, 0));
        label_P_imp->setMaximumSize(QSize(120, 16777215));

        gridLayout_7->addWidget(label_P_imp, 1, 3, 1, 1);


        gridLayout->addWidget(groupBox_P, 10, 0, 1, 1);

        groupBox_X = new QGroupBox(D_PopUp_RangeSelector);
        groupBox_X->setObjectName(QString::fromUtf8("groupBox_X"));
        sizePolicy.setHeightForWidth(groupBox_X->sizePolicy().hasHeightForWidth());
        groupBox_X->setSizePolicy(sizePolicy);
        groupBox_X->setAlignment(Qt::AlignCenter);
        groupBox_X->setCheckable(false);
        gridLayout_2 = new QGridLayout(groupBox_X);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(4);
        gridLayout_2->setVerticalSpacing(1);
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        spinBox_X_to = new QSpinBox(groupBox_X);
        spinBox_X_to->setObjectName(QString::fromUtf8("spinBox_X_to"));
        spinBox_X_to->setMinimumSize(QSize(120, 0));
        spinBox_X_to->setMaximumSize(QSize(120, 16777215));
        spinBox_X_to->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_X_to->setMaximum(9);
        spinBox_X_to->setValue(9);

        gridLayout_2->addWidget(spinBox_X_to, 1, 0, 1, 1);

        horizontalSlider_X_to = new QSlider(groupBox_X);
        horizontalSlider_X_to->setObjectName(QString::fromUtf8("horizontalSlider_X_to"));
        horizontalSlider_X_to->setMaximum(9);
        horizontalSlider_X_to->setValue(9);
        horizontalSlider_X_to->setOrientation(Qt::Horizontal);
        horizontalSlider_X_to->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_X_to->setTickInterval(1);

        gridLayout_2->addWidget(horizontalSlider_X_to, 1, 1, 1, 1);

        label_X_ext = new QLabel(groupBox_X);
        label_X_ext->setObjectName(QString::fromUtf8("label_X_ext"));
        label_X_ext->setMinimumSize(QSize(120, 0));
        label_X_ext->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(label_X_ext, 0, 3, 1, 1);

        spinBox_X_from = new QSpinBox(groupBox_X);
        spinBox_X_from->setObjectName(QString::fromUtf8("spinBox_X_from"));
        spinBox_X_from->setMinimumSize(QSize(120, 0));
        spinBox_X_from->setMaximumSize(QSize(120, 16777215));
        spinBox_X_from->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_X_from->setMaximum(9);

        gridLayout_2->addWidget(spinBox_X_from, 0, 0, 1, 1);

        horizontalSlider_X_from = new QSlider(groupBox_X);
        horizontalSlider_X_from->setObjectName(QString::fromUtf8("horizontalSlider_X_from"));
        horizontalSlider_X_from->setMaximum(9);
        horizontalSlider_X_from->setOrientation(Qt::Horizontal);
        horizontalSlider_X_from->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_X_from->setTickInterval(1);

        gridLayout_2->addWidget(horizontalSlider_X_from, 0, 1, 1, 1);

        line_X = new QFrame(groupBox_X);
        line_X->setObjectName(QString::fromUtf8("line_X"));
        line_X->setFrameShape(QFrame::VLine);
        line_X->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_X, 0, 2, 2, 1);

        label_X_imp = new QLabel(groupBox_X);
        label_X_imp->setObjectName(QString::fromUtf8("label_X_imp"));
        label_X_imp->setMinimumSize(QSize(120, 0));
        label_X_imp->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(label_X_imp, 1, 3, 1, 1);


        gridLayout->addWidget(groupBox_X, 5, 0, 1, 1);

        groupBox_Overall = new QGroupBox(D_PopUp_RangeSelector);
        groupBox_Overall->setObjectName(QString::fromUtf8("groupBox_Overall"));
        sizePolicy.setHeightForWidth(groupBox_Overall->sizePolicy().hasHeightForWidth());
        groupBox_Overall->setSizePolicy(sizePolicy);
        groupBox_Overall->setAlignment(Qt::AlignCenter);
        gridLayout_8 = new QGridLayout(groupBox_Overall);
        gridLayout_8->setSpacing(3);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(3, 3, 3, 3);
        label_Dims = new QLabel(groupBox_Overall);
        label_Dims->setObjectName(QString::fromUtf8("label_Dims"));
        label_Dims->setMinimumSize(QSize(120, 0));
        label_Dims->setMaximumSize(QSize(120, 16777215));
        label_Dims->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        label_Dims->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_Dims, 0, 0, 1, 1);

        label_Volume = new QLabel(groupBox_Overall);
        label_Volume->setObjectName(QString::fromUtf8("label_Volume"));
        label_Volume->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        label_Volume->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_Volume, 0, 1, 1, 1);

        pushButton_Done = new QPushButton(groupBox_Overall);
        pushButton_Done->setObjectName(QString::fromUtf8("pushButton_Done"));
        pushButton_Done->setMinimumSize(QSize(120, 0));
        pushButton_Done->setMaximumSize(QSize(120, 16777215));

        gridLayout_8->addWidget(pushButton_Done, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox_Overall, 11, 0, 1, 1);

        QWidget::setTabOrder(pushButton_Done, spinBox_X_from);
        QWidget::setTabOrder(spinBox_X_from, spinBox_X_to);
        QWidget::setTabOrder(spinBox_X_to, spinBox_Y_from);
        QWidget::setTabOrder(spinBox_Y_from, spinBox_Y_to);
        QWidget::setTabOrder(spinBox_Y_to, spinBox_Z_from);
        QWidget::setTabOrder(spinBox_Z_from, spinBox_Z_to);
        QWidget::setTabOrder(spinBox_Z_to, spinBox_T_from);
        QWidget::setTabOrder(spinBox_T_from, spinBox_T_to);
        QWidget::setTabOrder(spinBox_T_to, spinBox_S_from);
        QWidget::setTabOrder(spinBox_S_from, spinBox_S_to);
        QWidget::setTabOrder(spinBox_S_to, spinBox_P_from);
        QWidget::setTabOrder(spinBox_P_from, spinBox_P_to);
        QWidget::setTabOrder(spinBox_P_to, horizontalSlider_X_from);
        QWidget::setTabOrder(horizontalSlider_X_from, horizontalSlider_X_to);
        QWidget::setTabOrder(horizontalSlider_X_to, horizontalSlider_Y_from);
        QWidget::setTabOrder(horizontalSlider_Y_from, horizontalSlider_Y_to);
        QWidget::setTabOrder(horizontalSlider_Y_to, horizontalSlider_Z_from);
        QWidget::setTabOrder(horizontalSlider_Z_from, horizontalSlider_Z_to);
        QWidget::setTabOrder(horizontalSlider_Z_to, horizontalSlider_T_from);
        QWidget::setTabOrder(horizontalSlider_T_from, horizontalSlider_T_to);
        QWidget::setTabOrder(horizontalSlider_T_to, horizontalSlider_S_from);
        QWidget::setTabOrder(horizontalSlider_S_from, horizontalSlider_S_to);
        QWidget::setTabOrder(horizontalSlider_S_to, horizontalSlider_P_from);
        QWidget::setTabOrder(horizontalSlider_P_from, horizontalSlider_P_to);

        retranslateUi(D_PopUp_RangeSelector);
        QObject::connect(horizontalSlider_X_from, SIGNAL(valueChanged(int)), spinBox_X_from, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_X_to, SIGNAL(valueChanged(int)), spinBox_X_to, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_P_from, SIGNAL(valueChanged(int)), spinBox_P_from, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_P_to, SIGNAL(valueChanged(int)), spinBox_P_to, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_S_from, SIGNAL(valueChanged(int)), spinBox_S_from, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_S_to, SIGNAL(valueChanged(int)), spinBox_S_to, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_T_from, SIGNAL(valueChanged(int)), spinBox_T_from, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_T_to, SIGNAL(valueChanged(int)), spinBox_T_to, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_Y_from, SIGNAL(valueChanged(int)), spinBox_Y_from, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_Y_to, SIGNAL(valueChanged(int)), spinBox_Y_to, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_Z_from, SIGNAL(valueChanged(int)), spinBox_Z_from, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_Z_to, SIGNAL(valueChanged(int)), spinBox_Z_to, SLOT(setValue(int)));
        QObject::connect(spinBox_P_from, SIGNAL(valueChanged(int)), horizontalSlider_P_from, SLOT(setValue(int)));
        QObject::connect(spinBox_P_to, SIGNAL(valueChanged(int)), horizontalSlider_P_to, SLOT(setValue(int)));
        QObject::connect(spinBox_Z_from, SIGNAL(valueChanged(int)), horizontalSlider_Z_from, SLOT(setValue(int)));
        QObject::connect(spinBox_Z_to, SIGNAL(valueChanged(int)), horizontalSlider_Z_to, SLOT(setValue(int)));
        QObject::connect(spinBox_Y_to, SIGNAL(valueChanged(int)), horizontalSlider_Y_to, SLOT(setValue(int)));
        QObject::connect(spinBox_Y_from, SIGNAL(valueChanged(int)), horizontalSlider_Y_from, SLOT(setValue(int)));
        QObject::connect(spinBox_X_to, SIGNAL(valueChanged(int)), horizontalSlider_X_to, SLOT(setValue(int)));
        QObject::connect(spinBox_X_from, SIGNAL(valueChanged(int)), horizontalSlider_X_from, SLOT(setValue(int)));
        QObject::connect(spinBox_T_to, SIGNAL(valueChanged(int)), horizontalSlider_T_to, SLOT(setValue(int)));
        QObject::connect(spinBox_T_from, SIGNAL(valueChanged(int)), horizontalSlider_T_from, SLOT(setValue(int)));
        QObject::connect(spinBox_S_to, SIGNAL(valueChanged(int)), horizontalSlider_S_to, SLOT(setValue(int)));
        QObject::connect(spinBox_S_from, SIGNAL(valueChanged(int)), horizontalSlider_S_from, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(D_PopUp_RangeSelector);
    } // setupUi

    void retranslateUi(QDialog *D_PopUp_RangeSelector)
    {
        D_PopUp_RangeSelector->setWindowTitle(QApplication::translate("D_PopUp_RangeSelector", "Dialog", nullptr));
        groupBox_Z->setTitle(QApplication::translate("D_PopUp_RangeSelector", "Z Space", nullptr));
        spinBox_Z_from->setPrefix(QApplication::translate("D_PopUp_RangeSelector", "from ", nullptr));
        label_Z_ext->setText(QApplication::translate("D_PopUp_RangeSelector", "Extend: 10", nullptr));
        spinBox_Z_to->setPrefix(QApplication::translate("D_PopUp_RangeSelector", "to ", nullptr));
        label_Z_imp->setText(QApplication::translate("D_PopUp_RangeSelector", "Change impact: 10%", nullptr));
        groupBox_S->setTitle(QApplication::translate("D_PopUp_RangeSelector", "S Stack", nullptr));
        spinBox_S_from->setPrefix(QApplication::translate("D_PopUp_RangeSelector", "from ", nullptr));
        spinBox_S_to->setPrefix(QApplication::translate("D_PopUp_RangeSelector", "to ", nullptr));
        label_S_ext->setText(QApplication::translate("D_PopUp_RangeSelector", "Extend: 10", nullptr));
        label_S_imp->setText(QApplication::translate("D_PopUp_RangeSelector", "Change impact: 10%", nullptr));
        groupBox_Y->setTitle(QApplication::translate("D_PopUp_RangeSelector", "Y Space", nullptr));
        label_Y_ext->setText(QApplication::translate("D_PopUp_RangeSelector", "Extend: 10", nullptr));
        spinBox_Y_from->setPrefix(QApplication::translate("D_PopUp_RangeSelector", "from ", nullptr));
        spinBox_Y_to->setPrefix(QApplication::translate("D_PopUp_RangeSelector", "to ", nullptr));
        label_Y_imp->setText(QApplication::translate("D_PopUp_RangeSelector", "Change impact: 10%", nullptr));
        groupBox_T->setTitle(QApplication::translate("D_PopUp_RangeSelector", "T Time", nullptr));
        label_T_ext->setText(QApplication::translate("D_PopUp_RangeSelector", "Extend: 10", nullptr));
        spinBox_T_from->setPrefix(QApplication::translate("D_PopUp_RangeSelector", "from ", nullptr));
        spinBox_T_to->setPrefix(QApplication::translate("D_PopUp_RangeSelector", "to ", nullptr));
        label_T_imp->setText(QApplication::translate("D_PopUp_RangeSelector", "Change impact: 10%", nullptr));
        groupBox_P->setTitle(QApplication::translate("D_PopUp_RangeSelector", "P Pages", nullptr));
        label_P_ext->setText(QApplication::translate("D_PopUp_RangeSelector", "Extend: 10", nullptr));
        spinBox_P_from->setPrefix(QApplication::translate("D_PopUp_RangeSelector", "from ", nullptr));
        spinBox_P_to->setPrefix(QApplication::translate("D_PopUp_RangeSelector", "to ", nullptr));
        label_P_imp->setText(QApplication::translate("D_PopUp_RangeSelector", "Change impact: 10%", nullptr));
        groupBox_X->setTitle(QApplication::translate("D_PopUp_RangeSelector", "X Space", nullptr));
        spinBox_X_to->setPrefix(QApplication::translate("D_PopUp_RangeSelector", "to ", nullptr));
        label_X_ext->setText(QApplication::translate("D_PopUp_RangeSelector", "Extend: 10", nullptr));
        spinBox_X_from->setPrefix(QApplication::translate("D_PopUp_RangeSelector", "from ", nullptr));
        label_X_imp->setText(QApplication::translate("D_PopUp_RangeSelector", "Change impact: 10%", nullptr));
        groupBox_Overall->setTitle(QApplication::translate("D_PopUp_RangeSelector", "Overall", nullptr));
        label_Dims->setText(QApplication::translate("D_PopUp_RangeSelector", "6D", nullptr));
        label_Volume->setText(QApplication::translate("D_PopUp_RangeSelector", "Volume: 1000000", nullptr));
        pushButton_Done->setText(QApplication::translate("D_PopUp_RangeSelector", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_PopUp_RangeSelector: public Ui_D_PopUp_RangeSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_POPUP_RANGESELECTOR_H
