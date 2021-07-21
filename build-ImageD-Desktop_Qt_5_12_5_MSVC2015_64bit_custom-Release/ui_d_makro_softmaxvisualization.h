/********************************************************************************
** Form generated from reading UI file 'd_makro_softmaxvisualization.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_MAKRO_SOFTMAXVISUALIZATION_H
#define UI_D_MAKRO_SOFTMAXVISUALIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
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

class Ui_D_MAKRO_SoftmaxVisualization
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_y;
    QGridLayout *gridLayout_3;
    QGraphicsView *graphicsView_y;
    QGroupBox *groupBox_x;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView_x;
    QGroupBox *groupBox_W;
    QGridLayout *gridLayout_9;
    QGraphicsView *graphicsView_W;
    QGroupBox *groupBox_s;
    QGridLayout *gridLayout_11;
    QGraphicsView *graphicsView_s;
    QGroupBox *groupBox_s_normed;
    QGridLayout *gridLayout_4;
    QGraphicsView *graphicsView_s_normed;
    QGroupBox *groupBox_L;
    QGridLayout *gridLayout_6;
    QGraphicsView *graphicsView_L;
    QGroupBox *groupBox_classification;
    QGridLayout *gridLayout_13;
    QGraphicsView *graphicsView_classes;
    QGroupBox *groupBox_grad;
    QGridLayout *gridLayout_8;
    QGraphicsView *graphicsView_grad;
    QGroupBox *groupBox_L_partial_s;
    QGridLayout *gridLayout_5;
    QGraphicsView *graphicsView_L_partial_s;
    QGroupBox *groupBox_loss;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_Loss;
    QGroupBox *groupBox_Other;
    QGridLayout *gridLayout_17;
    QDoubleSpinBox *doubleSpinBox_W_mu;
    QSpacerItem *verticalSpacer;
    QDoubleSpinBox *doubleSpinBox_delta;
    QPushButton *pushButton_Proc_Iteration;
    QFrame *line_2;
    QFrame *line_4;
    QSpinBox *spinBox_K_classes;
    QDoubleSpinBox *doubleSpinBox_W_sigma;
    QFrame *line;
    QPushButton *pushButton_Proc_Stop;
    QPushButton *pushButton_ResetAndInit;
    QPushButton *pushButton_LoadData;
    QSpinBox *spinBox_N_datasets;
    QSpinBox *spinBox_M_features;
    QFrame *line_3;
    QLabel *label_2;
    QPushButton *pushButton_Proc_Endless;
    QLabel *label;
    QPushButton *pushButton_Proc_Step;
    QGridLayout *gridLayout_10;
    QDoubleSpinBox *doubleSpinBox_lambda;
    QCheckBox *checkBox_lambda;
    QLabel *label_Iteration;
    QGroupBox *groupBox_accuracy;
    QGridLayout *gridLayout_14;
    QGridLayout *gridLayout_Accuracy;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *D_MAKRO_SoftmaxVisualization)
    {
        if (D_MAKRO_SoftmaxVisualization->objectName().isEmpty())
            D_MAKRO_SoftmaxVisualization->setObjectName(QString::fromUtf8("D_MAKRO_SoftmaxVisualization"));
        D_MAKRO_SoftmaxVisualization->resize(970, 750);
        centralwidget = new QWidget(D_MAKRO_SoftmaxVisualization);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(6, 6, 6, 6);
        groupBox_y = new QGroupBox(centralwidget);
        groupBox_y->setObjectName(QString::fromUtf8("groupBox_y"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_y->sizePolicy().hasHeightForWidth());
        groupBox_y->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(groupBox_y);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        graphicsView_y = new QGraphicsView(groupBox_y);
        graphicsView_y->setObjectName(QString::fromUtf8("graphicsView_y"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView_y->sizePolicy().hasHeightForWidth());
        graphicsView_y->setSizePolicy(sizePolicy1);
        graphicsView_y->setMaximumSize(QSize(16777215, 20));
        graphicsView_y->setMouseTracking(true);

        gridLayout_3->addWidget(graphicsView_y, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_y, 0, 1, 1, 1);

        groupBox_x = new QGroupBox(centralwidget);
        groupBox_x->setObjectName(QString::fromUtf8("groupBox_x"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(3);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_x->sizePolicy().hasHeightForWidth());
        groupBox_x->setSizePolicy(sizePolicy2);
        gridLayout_2 = new QGridLayout(groupBox_x);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        graphicsView_x = new QGraphicsView(groupBox_x);
        graphicsView_x->setObjectName(QString::fromUtf8("graphicsView_x"));
        sizePolicy1.setHeightForWidth(graphicsView_x->sizePolicy().hasHeightForWidth());
        graphicsView_x->setSizePolicy(sizePolicy1);
        graphicsView_x->setMouseTracking(true);

        gridLayout_2->addWidget(graphicsView_x, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_x, 1, 1, 1, 1);

        groupBox_W = new QGroupBox(centralwidget);
        groupBox_W->setObjectName(QString::fromUtf8("groupBox_W"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(groupBox_W->sizePolicy().hasHeightForWidth());
        groupBox_W->setSizePolicy(sizePolicy3);
        gridLayout_9 = new QGridLayout(groupBox_W);
        gridLayout_9->setSpacing(3);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(3, 3, 3, 3);
        graphicsView_W = new QGraphicsView(groupBox_W);
        graphicsView_W->setObjectName(QString::fromUtf8("graphicsView_W"));
        sizePolicy1.setHeightForWidth(graphicsView_W->sizePolicy().hasHeightForWidth());
        graphicsView_W->setSizePolicy(sizePolicy1);
        graphicsView_W->setMouseTracking(true);

        gridLayout_9->addWidget(graphicsView_W, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_W, 2, 0, 1, 1);

        groupBox_s = new QGroupBox(centralwidget);
        groupBox_s->setObjectName(QString::fromUtf8("groupBox_s"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(3);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(groupBox_s->sizePolicy().hasHeightForWidth());
        groupBox_s->setSizePolicy(sizePolicy4);
        gridLayout_11 = new QGridLayout(groupBox_s);
        gridLayout_11->setSpacing(3);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(3, 3, 3, 3);
        graphicsView_s = new QGraphicsView(groupBox_s);
        graphicsView_s->setObjectName(QString::fromUtf8("graphicsView_s"));
        sizePolicy1.setHeightForWidth(graphicsView_s->sizePolicy().hasHeightForWidth());
        graphicsView_s->setSizePolicy(sizePolicy1);
        graphicsView_s->setMouseTracking(true);

        gridLayout_11->addWidget(graphicsView_s, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_s, 2, 1, 1, 1);

        groupBox_s_normed = new QGroupBox(centralwidget);
        groupBox_s_normed->setObjectName(QString::fromUtf8("groupBox_s_normed"));
        sizePolicy4.setHeightForWidth(groupBox_s_normed->sizePolicy().hasHeightForWidth());
        groupBox_s_normed->setSizePolicy(sizePolicy4);
        gridLayout_4 = new QGridLayout(groupBox_s_normed);
        gridLayout_4->setSpacing(3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(3, 3, 3, 3);
        graphicsView_s_normed = new QGraphicsView(groupBox_s_normed);
        graphicsView_s_normed->setObjectName(QString::fromUtf8("graphicsView_s_normed"));
        sizePolicy1.setHeightForWidth(graphicsView_s_normed->sizePolicy().hasHeightForWidth());
        graphicsView_s_normed->setSizePolicy(sizePolicy1);
        graphicsView_s_normed->setMouseTracking(true);

        gridLayout_4->addWidget(graphicsView_s_normed, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_s_normed, 2, 2, 1, 1);

        groupBox_L = new QGroupBox(centralwidget);
        groupBox_L->setObjectName(QString::fromUtf8("groupBox_L"));
        sizePolicy.setHeightForWidth(groupBox_L->sizePolicy().hasHeightForWidth());
        groupBox_L->setSizePolicy(sizePolicy);
        gridLayout_6 = new QGridLayout(groupBox_L);
        gridLayout_6->setSpacing(3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(3, 3, 3, 3);
        graphicsView_L = new QGraphicsView(groupBox_L);
        graphicsView_L->setObjectName(QString::fromUtf8("graphicsView_L"));
        sizePolicy1.setHeightForWidth(graphicsView_L->sizePolicy().hasHeightForWidth());
        graphicsView_L->setSizePolicy(sizePolicy1);
        graphicsView_L->setMaximumSize(QSize(16777215, 20));
        graphicsView_L->setMouseTracking(true);

        gridLayout_6->addWidget(graphicsView_L, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_L, 3, 1, 1, 1);

        groupBox_classification = new QGroupBox(centralwidget);
        groupBox_classification->setObjectName(QString::fromUtf8("groupBox_classification"));
        sizePolicy.setHeightForWidth(groupBox_classification->sizePolicy().hasHeightForWidth());
        groupBox_classification->setSizePolicy(sizePolicy);
        gridLayout_13 = new QGridLayout(groupBox_classification);
        gridLayout_13->setSpacing(3);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(3, 3, 3, 3);
        graphicsView_classes = new QGraphicsView(groupBox_classification);
        graphicsView_classes->setObjectName(QString::fromUtf8("graphicsView_classes"));
        sizePolicy1.setHeightForWidth(graphicsView_classes->sizePolicy().hasHeightForWidth());
        graphicsView_classes->setSizePolicy(sizePolicy1);
        graphicsView_classes->setMaximumSize(QSize(16777215, 20));
        graphicsView_classes->setMouseTracking(true);

        gridLayout_13->addWidget(graphicsView_classes, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_classification, 3, 2, 1, 1);

        groupBox_grad = new QGroupBox(centralwidget);
        groupBox_grad->setObjectName(QString::fromUtf8("groupBox_grad"));
        sizePolicy3.setHeightForWidth(groupBox_grad->sizePolicy().hasHeightForWidth());
        groupBox_grad->setSizePolicy(sizePolicy3);
        gridLayout_8 = new QGridLayout(groupBox_grad);
        gridLayout_8->setSpacing(3);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(3, 3, 3, 3);
        graphicsView_grad = new QGraphicsView(groupBox_grad);
        graphicsView_grad->setObjectName(QString::fromUtf8("graphicsView_grad"));
        sizePolicy1.setHeightForWidth(graphicsView_grad->sizePolicy().hasHeightForWidth());
        graphicsView_grad->setSizePolicy(sizePolicy1);
        graphicsView_grad->setMouseTracking(true);

        gridLayout_8->addWidget(graphicsView_grad, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_grad, 4, 0, 1, 1);

        groupBox_L_partial_s = new QGroupBox(centralwidget);
        groupBox_L_partial_s->setObjectName(QString::fromUtf8("groupBox_L_partial_s"));
        sizePolicy4.setHeightForWidth(groupBox_L_partial_s->sizePolicy().hasHeightForWidth());
        groupBox_L_partial_s->setSizePolicy(sizePolicy4);
        gridLayout_5 = new QGridLayout(groupBox_L_partial_s);
        gridLayout_5->setSpacing(3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(3, 3, 3, 3);
        graphicsView_L_partial_s = new QGraphicsView(groupBox_L_partial_s);
        graphicsView_L_partial_s->setObjectName(QString::fromUtf8("graphicsView_L_partial_s"));
        sizePolicy1.setHeightForWidth(graphicsView_L_partial_s->sizePolicy().hasHeightForWidth());
        graphicsView_L_partial_s->setSizePolicy(sizePolicy1);
        graphicsView_L_partial_s->setMouseTracking(true);

        gridLayout_5->addWidget(graphicsView_L_partial_s, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_L_partial_s, 4, 1, 1, 1);

        groupBox_loss = new QGroupBox(centralwidget);
        groupBox_loss->setObjectName(QString::fromUtf8("groupBox_loss"));
        sizePolicy4.setHeightForWidth(groupBox_loss->sizePolicy().hasHeightForWidth());
        groupBox_loss->setSizePolicy(sizePolicy4);
        gridLayout_7 = new QGridLayout(groupBox_loss);
        gridLayout_7->setSpacing(3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(3, 0, 0, 0);
        gridLayout_Loss = new QGridLayout();
        gridLayout_Loss->setObjectName(QString::fromUtf8("gridLayout_Loss"));

        gridLayout_7->addLayout(gridLayout_Loss, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_loss, 4, 2, 1, 1);

        groupBox_Other = new QGroupBox(centralwidget);
        groupBox_Other->setObjectName(QString::fromUtf8("groupBox_Other"));
        sizePolicy3.setHeightForWidth(groupBox_Other->sizePolicy().hasHeightForWidth());
        groupBox_Other->setSizePolicy(sizePolicy3);
        gridLayout_17 = new QGridLayout(groupBox_Other);
        gridLayout_17->setSpacing(3);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(3, 3, 3, 3);
        doubleSpinBox_W_mu = new QDoubleSpinBox(groupBox_Other);
        doubleSpinBox_W_mu->setObjectName(QString::fromUtf8("doubleSpinBox_W_mu"));
        doubleSpinBox_W_mu->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_W_mu->setDecimals(6);
        doubleSpinBox_W_mu->setMinimum(-9999.000000000000000);
        doubleSpinBox_W_mu->setMaximum(9999.000000000000000);
        doubleSpinBox_W_mu->setSingleStep(0.010000000000000);
        doubleSpinBox_W_mu->setValue(0.000000000000000);

        gridLayout_17->addWidget(doubleSpinBox_W_mu, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_17->addItem(verticalSpacer, 10, 1, 1, 1);

        doubleSpinBox_delta = new QDoubleSpinBox(groupBox_Other);
        doubleSpinBox_delta->setObjectName(QString::fromUtf8("doubleSpinBox_delta"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(doubleSpinBox_delta->sizePolicy().hasHeightForWidth());
        doubleSpinBox_delta->setSizePolicy(sizePolicy5);
        doubleSpinBox_delta->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_delta->setDecimals(3);
        doubleSpinBox_delta->setMinimum(-300.000000000000000);
        doubleSpinBox_delta->setMaximum(300.000000000000000);
        doubleSpinBox_delta->setSingleStep(0.500000000000000);
        doubleSpinBox_delta->setValue(0.500000000000000);

        gridLayout_17->addWidget(doubleSpinBox_delta, 16, 0, 1, 2);

        pushButton_Proc_Iteration = new QPushButton(groupBox_Other);
        pushButton_Proc_Iteration->setObjectName(QString::fromUtf8("pushButton_Proc_Iteration"));
        pushButton_Proc_Iteration->setEnabled(false);
        sizePolicy5.setHeightForWidth(pushButton_Proc_Iteration->sizePolicy().hasHeightForWidth());
        pushButton_Proc_Iteration->setSizePolicy(sizePolicy5);

        gridLayout_17->addWidget(pushButton_Proc_Iteration, 5, 1, 1, 1);

        line_2 = new QFrame(groupBox_Other);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        sizePolicy5.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy5);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line_2, 17, 0, 1, 2);

        line_4 = new QFrame(groupBox_Other);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line_4, 1, 0, 1, 2);

        spinBox_K_classes = new QSpinBox(groupBox_Other);
        spinBox_K_classes->setObjectName(QString::fromUtf8("spinBox_K_classes"));
        sizePolicy5.setHeightForWidth(spinBox_K_classes->sizePolicy().hasHeightForWidth());
        spinBox_K_classes->setSizePolicy(sizePolicy5);
        spinBox_K_classes->setReadOnly(true);
        spinBox_K_classes->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_K_classes->setMaximum(999999999);

        gridLayout_17->addWidget(spinBox_K_classes, 21, 0, 1, 2);

        doubleSpinBox_W_sigma = new QDoubleSpinBox(groupBox_Other);
        doubleSpinBox_W_sigma->setObjectName(QString::fromUtf8("doubleSpinBox_W_sigma"));
        doubleSpinBox_W_sigma->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_W_sigma->setDecimals(6);
        doubleSpinBox_W_sigma->setMaximum(9999.000000000000000);
        doubleSpinBox_W_sigma->setSingleStep(0.010000000000000);
        doubleSpinBox_W_sigma->setValue(0.000000000000000);

        gridLayout_17->addWidget(doubleSpinBox_W_sigma, 2, 1, 1, 1);

        line = new QFrame(groupBox_Other);
        line->setObjectName(QString::fromUtf8("line"));
        sizePolicy5.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy5);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line, 11, 0, 1, 2);

        pushButton_Proc_Stop = new QPushButton(groupBox_Other);
        pushButton_Proc_Stop->setObjectName(QString::fromUtf8("pushButton_Proc_Stop"));
        pushButton_Proc_Stop->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushButton_Proc_Stop->sizePolicy().hasHeightForWidth());
        pushButton_Proc_Stop->setSizePolicy(sizePolicy1);

        gridLayout_17->addWidget(pushButton_Proc_Stop, 7, 1, 2, 1);

        pushButton_ResetAndInit = new QPushButton(groupBox_Other);
        pushButton_ResetAndInit->setObjectName(QString::fromUtf8("pushButton_ResetAndInit"));
        pushButton_ResetAndInit->setEnabled(true);

        gridLayout_17->addWidget(pushButton_ResetAndInit, 3, 0, 1, 2);

        pushButton_LoadData = new QPushButton(groupBox_Other);
        pushButton_LoadData->setObjectName(QString::fromUtf8("pushButton_LoadData"));
        sizePolicy5.setHeightForWidth(pushButton_LoadData->sizePolicy().hasHeightForWidth());
        pushButton_LoadData->setSizePolicy(sizePolicy5);

        gridLayout_17->addWidget(pushButton_LoadData, 0, 0, 1, 2);

        spinBox_N_datasets = new QSpinBox(groupBox_Other);
        spinBox_N_datasets->setObjectName(QString::fromUtf8("spinBox_N_datasets"));
        sizePolicy5.setHeightForWidth(spinBox_N_datasets->sizePolicy().hasHeightForWidth());
        spinBox_N_datasets->setSizePolicy(sizePolicy5);
        spinBox_N_datasets->setReadOnly(true);
        spinBox_N_datasets->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_N_datasets->setMaximum(999999999);

        gridLayout_17->addWidget(spinBox_N_datasets, 19, 0, 1, 2);

        spinBox_M_features = new QSpinBox(groupBox_Other);
        spinBox_M_features->setObjectName(QString::fromUtf8("spinBox_M_features"));
        sizePolicy5.setHeightForWidth(spinBox_M_features->sizePolicy().hasHeightForWidth());
        spinBox_M_features->setSizePolicy(sizePolicy5);
        spinBox_M_features->setReadOnly(true);
        spinBox_M_features->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_M_features->setMaximum(999999999);

        gridLayout_17->addWidget(spinBox_M_features, 20, 0, 1, 2);

        line_3 = new QFrame(groupBox_Other);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line_3, 4, 0, 1, 2);

        label_2 = new QLabel(groupBox_Other);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy5.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy5);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_17->addWidget(label_2, 12, 0, 1, 2);

        pushButton_Proc_Endless = new QPushButton(groupBox_Other);
        pushButton_Proc_Endless->setObjectName(QString::fromUtf8("pushButton_Proc_Endless"));
        pushButton_Proc_Endless->setEnabled(false);
        sizePolicy5.setHeightForWidth(pushButton_Proc_Endless->sizePolicy().hasHeightForWidth());
        pushButton_Proc_Endless->setSizePolicy(sizePolicy5);

        gridLayout_17->addWidget(pushButton_Proc_Endless, 7, 0, 1, 1);

        label = new QLabel(groupBox_Other);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy5.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy5);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_17->addWidget(label, 18, 0, 1, 2);

        pushButton_Proc_Step = new QPushButton(groupBox_Other);
        pushButton_Proc_Step->setObjectName(QString::fromUtf8("pushButton_Proc_Step"));
        pushButton_Proc_Step->setEnabled(false);
        sizePolicy5.setHeightForWidth(pushButton_Proc_Step->sizePolicy().hasHeightForWidth());
        pushButton_Proc_Step->setSizePolicy(sizePolicy5);

        gridLayout_17->addWidget(pushButton_Proc_Step, 5, 0, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        doubleSpinBox_lambda = new QDoubleSpinBox(groupBox_Other);
        doubleSpinBox_lambda->setObjectName(QString::fromUtf8("doubleSpinBox_lambda"));
        doubleSpinBox_lambda->setEnabled(false);
        sizePolicy5.setHeightForWidth(doubleSpinBox_lambda->sizePolicy().hasHeightForWidth());
        doubleSpinBox_lambda->setSizePolicy(sizePolicy5);
        doubleSpinBox_lambda->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_lambda->setDecimals(3);
        doubleSpinBox_lambda->setMinimum(-300.000000000000000);
        doubleSpinBox_lambda->setMaximum(300.000000000000000);
        doubleSpinBox_lambda->setSingleStep(25.000000000000000);
        doubleSpinBox_lambda->setValue(-1.000000000000000);

        gridLayout_10->addWidget(doubleSpinBox_lambda, 0, 1, 1, 1);

        checkBox_lambda = new QCheckBox(groupBox_Other);
        checkBox_lambda->setObjectName(QString::fromUtf8("checkBox_lambda"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(checkBox_lambda->sizePolicy().hasHeightForWidth());
        checkBox_lambda->setSizePolicy(sizePolicy6);

        gridLayout_10->addWidget(checkBox_lambda, 0, 0, 1, 1);


        gridLayout_17->addLayout(gridLayout_10, 13, 0, 1, 2);


        gridLayout->addWidget(groupBox_Other, 0, 0, 2, 1);

        label_Iteration = new QLabel(centralwidget);
        label_Iteration->setObjectName(QString::fromUtf8("label_Iteration"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy7.setHorizontalStretch(1);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_Iteration->sizePolicy().hasHeightForWidth());
        label_Iteration->setSizePolicy(sizePolicy7);
        label_Iteration->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        label_Iteration->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_Iteration, 3, 0, 1, 1);

        groupBox_accuracy = new QGroupBox(centralwidget);
        groupBox_accuracy->setObjectName(QString::fromUtf8("groupBox_accuracy"));
        sizePolicy4.setHeightForWidth(groupBox_accuracy->sizePolicy().hasHeightForWidth());
        groupBox_accuracy->setSizePolicy(sizePolicy4);
        gridLayout_14 = new QGridLayout(groupBox_accuracy);
        gridLayout_14->setSpacing(3);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(3, 0, 0, 0);
        gridLayout_Accuracy = new QGridLayout();
        gridLayout_Accuracy->setObjectName(QString::fromUtf8("gridLayout_Accuracy"));

        gridLayout_14->addLayout(gridLayout_Accuracy, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_accuracy, 0, 2, 2, 1);

        D_MAKRO_SoftmaxVisualization->setCentralWidget(centralwidget);
        menubar = new QMenuBar(D_MAKRO_SoftmaxVisualization);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 970, 21));
        D_MAKRO_SoftmaxVisualization->setMenuBar(menubar);
        statusbar = new QStatusBar(D_MAKRO_SoftmaxVisualization);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        D_MAKRO_SoftmaxVisualization->setStatusBar(statusbar);

        retranslateUi(D_MAKRO_SoftmaxVisualization);

        QMetaObject::connectSlotsByName(D_MAKRO_SoftmaxVisualization);
    } // setupUi

    void retranslateUi(QMainWindow *D_MAKRO_SoftmaxVisualization)
    {
        D_MAKRO_SoftmaxVisualization->setWindowTitle(QApplication::translate("D_MAKRO_SoftmaxVisualization", "MainWindow", nullptr));
        groupBox_y->setTitle(QApplication::translate("D_MAKRO_SoftmaxVisualization", "y", nullptr));
        groupBox_x->setTitle(QApplication::translate("D_MAKRO_SoftmaxVisualization", "x", nullptr));
        groupBox_W->setTitle(QApplication::translate("D_MAKRO_SoftmaxVisualization", "W", nullptr));
        groupBox_s->setTitle(QApplication::translate("D_MAKRO_SoftmaxVisualization", "s", nullptr));
        groupBox_s_normed->setTitle(QApplication::translate("D_MAKRO_SoftmaxVisualization", "softmax(s)", nullptr));
        groupBox_L->setTitle(QApplication::translate("D_MAKRO_SoftmaxVisualization", "L", nullptr));
        groupBox_classification->setTitle(QApplication::translate("D_MAKRO_SoftmaxVisualization", "classes", nullptr));
        groupBox_grad->setTitle(QApplication::translate("D_MAKRO_SoftmaxVisualization", "gradient", nullptr));
        groupBox_L_partial_s->setTitle(QApplication::translate("D_MAKRO_SoftmaxVisualization", "L partial s", nullptr));
        groupBox_loss->setTitle(QApplication::translate("D_MAKRO_SoftmaxVisualization", "loss", nullptr));
        groupBox_Other->setTitle(QApplication::translate("D_MAKRO_SoftmaxVisualization", "Control", nullptr));
        doubleSpinBox_W_mu->setPrefix(QApplication::translate("D_MAKRO_SoftmaxVisualization", "\316\274=", nullptr));
        doubleSpinBox_delta->setPrefix(QApplication::translate("D_MAKRO_SoftmaxVisualization", "Learn \316\264 = 10^(", nullptr));
        doubleSpinBox_delta->setSuffix(QApplication::translate("D_MAKRO_SoftmaxVisualization", ")", nullptr));
        pushButton_Proc_Iteration->setText(QApplication::translate("D_MAKRO_SoftmaxVisualization", "Proc Iteration", nullptr));
        spinBox_K_classes->setSuffix(QApplication::translate("D_MAKRO_SoftmaxVisualization", " classes", nullptr));
        spinBox_K_classes->setPrefix(QApplication::translate("D_MAKRO_SoftmaxVisualization", "K = ", nullptr));
        doubleSpinBox_W_sigma->setPrefix(QApplication::translate("D_MAKRO_SoftmaxVisualization", "\317\203=", nullptr));
        pushButton_Proc_Stop->setText(QApplication::translate("D_MAKRO_SoftmaxVisualization", "Stop", nullptr));
        pushButton_ResetAndInit->setText(QApplication::translate("D_MAKRO_SoftmaxVisualization", "Init W", nullptr));
        pushButton_LoadData->setText(QApplication::translate("D_MAKRO_SoftmaxVisualization", "Load Data", nullptr));
        spinBox_N_datasets->setSuffix(QApplication::translate("D_MAKRO_SoftmaxVisualization", " datasets", nullptr));
        spinBox_N_datasets->setPrefix(QApplication::translate("D_MAKRO_SoftmaxVisualization", "N = ", nullptr));
        spinBox_M_features->setSuffix(QApplication::translate("D_MAKRO_SoftmaxVisualization", " features", nullptr));
        spinBox_M_features->setPrefix(QApplication::translate("D_MAKRO_SoftmaxVisualization", "M = ", nullptr));
        label_2->setText(QApplication::translate("D_MAKRO_SoftmaxVisualization", "Hyperparameter", nullptr));
        pushButton_Proc_Endless->setText(QApplication::translate("D_MAKRO_SoftmaxVisualization", "Proc Endless", nullptr));
        label->setText(QApplication::translate("D_MAKRO_SoftmaxVisualization", "Dimensions", nullptr));
        pushButton_Proc_Step->setText(QApplication::translate("D_MAKRO_SoftmaxVisualization", "Proc Step", nullptr));
        doubleSpinBox_lambda->setPrefix(QApplication::translate("D_MAKRO_SoftmaxVisualization", "Regul. \316\273 = 10^(", nullptr));
        doubleSpinBox_lambda->setSuffix(QApplication::translate("D_MAKRO_SoftmaxVisualization", ")", nullptr));
        checkBox_lambda->setText(QString());
        label_Iteration->setText(QApplication::translate("D_MAKRO_SoftmaxVisualization", "Iteration: 0", nullptr));
        groupBox_accuracy->setTitle(QApplication::translate("D_MAKRO_SoftmaxVisualization", "Accuracy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_MAKRO_SoftmaxVisualization: public Ui_D_MAKRO_SoftmaxVisualization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_MAKRO_SOFTMAXVISUALIZATION_H
