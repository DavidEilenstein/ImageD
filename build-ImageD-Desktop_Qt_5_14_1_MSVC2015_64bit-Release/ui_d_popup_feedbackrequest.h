/********************************************************************************
** Form generated from reading UI file 'd_popup_feedbackrequest.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_POPUP_FEEDBACKREQUEST_H
#define UI_D_POPUP_FEEDBACKREQUEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_D_Popup_FeedbackRequest
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Send;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Remind;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_Environment;
    QComboBox *comboBox_Department;
    QLineEdit *lineEdit_Department;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_10;
    QLineEdit *lineEdit_Country;
    QComboBox *comboBox_Environment;
    QLineEdit *lineEdit_UserType;
    QComboBox *comboBox_Country;
    QLineEdit *lineEdit_Achived;
    QComboBox *comboBox_UserType;
    QLineEdit *lineEdit_Grade;
    QComboBox *comboBox_Grade;
    QPlainTextEdit *plainTextEdit_Comments;
    QComboBox *comboBox_Achived;
    QLabel *label_12;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_UseCount;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_2;

    void setupUi(QDialog *D_Popup_FeedbackRequest)
    {
        if (D_Popup_FeedbackRequest->objectName().isEmpty())
            D_Popup_FeedbackRequest->setObjectName(QString::fromUtf8("D_Popup_FeedbackRequest"));
        D_Popup_FeedbackRequest->resize(700, 575);
        gridLayout = new QGridLayout(D_Popup_FeedbackRequest);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(D_Popup_FeedbackRequest);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setAlignment(Qt::AlignCenter);
        groupBox_3->setFlat(true);
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 5, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color:red\n"
""));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label, 1, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton_Send = new QPushButton(groupBox_3);
        pushButton_Send->setObjectName(QString::fromUtf8("pushButton_Send"));
        pushButton_Send->setMinimumSize(QSize(77, 50));
        pushButton_Send->setMaximumSize(QSize(77, 50));

        gridLayout_4->addWidget(pushButton_Send, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("color:blue"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_8, 1, 3, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        pushButton_Remind = new QPushButton(groupBox_3);
        pushButton_Remind->setObjectName(QString::fromUtf8("pushButton_Remind"));
        pushButton_Remind->setMinimumSize(QSize(77, 50));
        pushButton_Remind->setMaximumSize(QSize(77, 50));

        gridLayout_4->addWidget(pushButton_Remind, 0, 4, 1, 1);


        gridLayout->addWidget(groupBox_3, 3, 0, 1, 3);

        groupBox_2 = new QGroupBox(D_Popup_FeedbackRequest);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        groupBox_2->setFlat(true);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lineEdit_Environment = new QLineEdit(groupBox_2);
        lineEdit_Environment->setObjectName(QString::fromUtf8("lineEdit_Environment"));

        gridLayout_3->addWidget(lineEdit_Environment, 3, 2, 1, 1);

        comboBox_Department = new QComboBox(groupBox_2);
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->setObjectName(QString::fromUtf8("comboBox_Department"));
        comboBox_Department->setMinimumSize(QSize(150, 0));
        comboBox_Department->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(comboBox_Department, 2, 1, 1, 1);

        lineEdit_Department = new QLineEdit(groupBox_2);
        lineEdit_Department->setObjectName(QString::fromUtf8("lineEdit_Department"));

        gridLayout_3->addWidget(lineEdit_Department, 2, 2, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(75, 0));
        label_13->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_13, 7, 0, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(75, 0));
        label_11->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_11, 2, 0, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(75, 0));
        label_10->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_10, 5, 0, 1, 1);

        lineEdit_Country = new QLineEdit(groupBox_2);
        lineEdit_Country->setObjectName(QString::fromUtf8("lineEdit_Country"));

        gridLayout_3->addWidget(lineEdit_Country, 7, 2, 1, 1);

        comboBox_Environment = new QComboBox(groupBox_2);
        comboBox_Environment->addItem(QString());
        comboBox_Environment->addItem(QString());
        comboBox_Environment->addItem(QString());
        comboBox_Environment->addItem(QString());
        comboBox_Environment->addItem(QString());
        comboBox_Environment->addItem(QString());
        comboBox_Environment->addItem(QString());
        comboBox_Environment->setObjectName(QString::fromUtf8("comboBox_Environment"));
        comboBox_Environment->setMinimumSize(QSize(150, 0));
        comboBox_Environment->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(comboBox_Environment, 3, 1, 1, 1);

        lineEdit_UserType = new QLineEdit(groupBox_2);
        lineEdit_UserType->setObjectName(QString::fromUtf8("lineEdit_UserType"));

        gridLayout_3->addWidget(lineEdit_UserType, 5, 2, 1, 1);

        comboBox_Country = new QComboBox(groupBox_2);
        comboBox_Country->addItem(QString());
        comboBox_Country->setObjectName(QString::fromUtf8("comboBox_Country"));
        comboBox_Country->setMinimumSize(QSize(150, 0));
        comboBox_Country->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(comboBox_Country, 7, 1, 1, 1);

        lineEdit_Achived = new QLineEdit(groupBox_2);
        lineEdit_Achived->setObjectName(QString::fromUtf8("lineEdit_Achived"));

        gridLayout_3->addWidget(lineEdit_Achived, 1, 2, 1, 1);

        comboBox_UserType = new QComboBox(groupBox_2);
        comboBox_UserType->addItem(QString());
        comboBox_UserType->addItem(QString());
        comboBox_UserType->addItem(QString());
        comboBox_UserType->addItem(QString());
        comboBox_UserType->addItem(QString());
        comboBox_UserType->addItem(QString());
        comboBox_UserType->setObjectName(QString::fromUtf8("comboBox_UserType"));
        comboBox_UserType->setMinimumSize(QSize(150, 0));
        comboBox_UserType->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(comboBox_UserType, 5, 1, 1, 1);

        lineEdit_Grade = new QLineEdit(groupBox_2);
        lineEdit_Grade->setObjectName(QString::fromUtf8("lineEdit_Grade"));

        gridLayout_3->addWidget(lineEdit_Grade, 6, 2, 1, 1);

        comboBox_Grade = new QComboBox(groupBox_2);
        comboBox_Grade->addItem(QString());
        comboBox_Grade->addItem(QString());
        comboBox_Grade->addItem(QString());
        comboBox_Grade->addItem(QString());
        comboBox_Grade->addItem(QString());
        comboBox_Grade->addItem(QString());
        comboBox_Grade->addItem(QString());
        comboBox_Grade->addItem(QString());
        comboBox_Grade->addItem(QString());
        comboBox_Grade->setObjectName(QString::fromUtf8("comboBox_Grade"));
        comboBox_Grade->setMinimumSize(QSize(150, 0));
        comboBox_Grade->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(comboBox_Grade, 6, 1, 1, 1);

        plainTextEdit_Comments = new QPlainTextEdit(groupBox_2);
        plainTextEdit_Comments->setObjectName(QString::fromUtf8("plainTextEdit_Comments"));

        gridLayout_3->addWidget(plainTextEdit_Comments, 8, 1, 1, 2);

        comboBox_Achived = new QComboBox(groupBox_2);
        comboBox_Achived->addItem(QString());
        comboBox_Achived->addItem(QString());
        comboBox_Achived->addItem(QString());
        comboBox_Achived->addItem(QString());
        comboBox_Achived->addItem(QString());
        comboBox_Achived->addItem(QString());
        comboBox_Achived->setObjectName(QString::fromUtf8("comboBox_Achived"));
        comboBox_Achived->setMinimumSize(QSize(150, 0));
        comboBox_Achived->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(comboBox_Achived, 1, 1, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(75, 0));
        label_12->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_12, 1, 0, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(75, 0));
        label_6->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_6, 6, 0, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(75, 0));
        label_9->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(label_9, 3, 0, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 0, 1, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 0, 2, 1, 1);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_3->addWidget(label_16, 8, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 2, 0, 1, 3);

        label_UseCount = new QLabel(D_Popup_FeedbackRequest);
        label_UseCount->setObjectName(QString::fromUtf8("label_UseCount"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_UseCount->sizePolicy().hasHeightForWidth());
        label_UseCount->setSizePolicy(sizePolicy1);
        label_UseCount->setMinimumSize(QSize(0, 40));
        label_UseCount->setMaximumSize(QSize(9999999, 40));
        label_UseCount->setStyleSheet(QString::fromUtf8("font-size: 30px;"));
        label_UseCount->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_UseCount, 0, 1, 1, 1);

        label_3 = new QLabel(D_Popup_FeedbackRequest);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 10);
        label_4 = new QLabel(D_Popup_FeedbackRequest);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 20));
        label_4->setMaximumSize(QSize(16777215, 20));
        label_4->setStyleSheet(QString::fromUtf8("background-color: white"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(D_Popup_FeedbackRequest);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 20));
        label_5->setMaximumSize(QSize(16777215, 20));
        label_5->setStyleSheet(QString::fromUtf8("background-color: white"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);

        label_7 = new QLabel(D_Popup_FeedbackRequest);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 20));
        label_7->setMaximumSize(QSize(16777215, 20));
        label_7->setStyleSheet(QString::fromUtf8("background-color: white"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_7);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 3);

        label_2 = new QLabel(D_Popup_FeedbackRequest);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);


        retranslateUi(D_Popup_FeedbackRequest);

        QMetaObject::connectSlotsByName(D_Popup_FeedbackRequest);
    } // setupUi

    void retranslateUi(QDialog *D_Popup_FeedbackRequest)
    {
        D_Popup_FeedbackRequest->setWindowTitle(QCoreApplication::translate("D_Popup_FeedbackRequest", "Feedback Request", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("D_Popup_FeedbackRequest", "How do you want to react to this anoying popup? Choose wisely!", nullptr));
        label->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "Take the red pill: Send survey as e-mail", nullptr));
        pushButton_Send->setText(QString());
        label_8->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "Take the blue pill: Remind me later", nullptr));
        pushButton_Remind->setText(QString());
        groupBox_2->setTitle(QString());
        comboBox_Department->setItemText(0, QCoreApplication::translate("D_Popup_FeedbackRequest", "-", nullptr));
        comboBox_Department->setItemText(1, QCoreApplication::translate("D_Popup_FeedbackRequest", "biophysics", nullptr));
        comboBox_Department->setItemText(2, QCoreApplication::translate("D_Popup_FeedbackRequest", "physics", nullptr));
        comboBox_Department->setItemText(3, QCoreApplication::translate("D_Popup_FeedbackRequest", "biology", nullptr));
        comboBox_Department->setItemText(4, QCoreApplication::translate("D_Popup_FeedbackRequest", "informatics", nullptr));
        comboBox_Department->setItemText(5, QCoreApplication::translate("D_Popup_FeedbackRequest", "image processing", nullptr));
        comboBox_Department->setItemText(6, QCoreApplication::translate("D_Popup_FeedbackRequest", "math", nullptr));
        comboBox_Department->setItemText(7, QCoreApplication::translate("D_Popup_FeedbackRequest", "pharma", nullptr));
        comboBox_Department->setItemText(8, QCoreApplication::translate("D_Popup_FeedbackRequest", "medicine", nullptr));
        comboBox_Department->setItemText(9, QCoreApplication::translate("D_Popup_FeedbackRequest", "other", nullptr));

        label_13->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "Country", nullptr));
        label_11->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "Department", nullptr));
        label_10->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "User Type", nullptr));
        comboBox_Environment->setItemText(0, QCoreApplication::translate("D_Popup_FeedbackRequest", "-", nullptr));
        comboBox_Environment->setItemText(1, QCoreApplication::translate("D_Popup_FeedbackRequest", "institute", nullptr));
        comboBox_Environment->setItemText(2, QCoreApplication::translate("D_Popup_FeedbackRequest", "industry", nullptr));
        comboBox_Environment->setItemText(3, QCoreApplication::translate("D_Popup_FeedbackRequest", "university", nullptr));
        comboBox_Environment->setItemText(4, QCoreApplication::translate("D_Popup_FeedbackRequest", "school", nullptr));
        comboBox_Environment->setItemText(5, QCoreApplication::translate("D_Popup_FeedbackRequest", "hobby", nullptr));
        comboBox_Environment->setItemText(6, QCoreApplication::translate("D_Popup_FeedbackRequest", "other", nullptr));

        comboBox_Country->setItemText(0, QCoreApplication::translate("D_Popup_FeedbackRequest", "-", nullptr));

        comboBox_UserType->setItemText(0, QCoreApplication::translate("D_Popup_FeedbackRequest", "-", nullptr));
        comboBox_UserType->setItemText(1, QCoreApplication::translate("D_Popup_FeedbackRequest", "plugin user", nullptr));
        comboBox_UserType->setItemText(2, QCoreApplication::translate("D_Popup_FeedbackRequest", "base programm user", nullptr));
        comboBox_UserType->setItemText(3, QCoreApplication::translate("D_Popup_FeedbackRequest", "co-developer", nullptr));
        comboBox_UserType->setItemText(4, QCoreApplication::translate("D_Popup_FeedbackRequest", "code-spy", nullptr));
        comboBox_UserType->setItemText(5, QCoreApplication::translate("D_Popup_FeedbackRequest", "other", nullptr));

        comboBox_Grade->setItemText(0, QCoreApplication::translate("D_Popup_FeedbackRequest", "-", nullptr));
        comboBox_Grade->setItemText(1, QCoreApplication::translate("D_Popup_FeedbackRequest", "Professor", nullptr));
        comboBox_Grade->setItemText(2, QCoreApplication::translate("D_Popup_FeedbackRequest", "Post-Doc", nullptr));
        comboBox_Grade->setItemText(3, QCoreApplication::translate("D_Popup_FeedbackRequest", "PhD", nullptr));
        comboBox_Grade->setItemText(4, QCoreApplication::translate("D_Popup_FeedbackRequest", "Master", nullptr));
        comboBox_Grade->setItemText(5, QCoreApplication::translate("D_Popup_FeedbackRequest", "Bachelor", nullptr));
        comboBox_Grade->setItemText(6, QCoreApplication::translate("D_Popup_FeedbackRequest", "Student", nullptr));
        comboBox_Grade->setItemText(7, QCoreApplication::translate("D_Popup_FeedbackRequest", "Pupil", nullptr));
        comboBox_Grade->setItemText(8, QCoreApplication::translate("D_Popup_FeedbackRequest", "Other", nullptr));

        comboBox_Achived->setItemText(0, QCoreApplication::translate("D_Popup_FeedbackRequest", "-", nullptr));
        comboBox_Achived->setItemText(1, QCoreApplication::translate("D_Popup_FeedbackRequest", "GitHub", nullptr));
        comboBox_Achived->setItemText(2, QCoreApplication::translate("D_Popup_FeedbackRequest", "Workmate", nullptr));
        comboBox_Achived->setItemText(3, QCoreApplication::translate("D_Popup_FeedbackRequest", "Classmate", nullptr));
        comboBox_Achived->setItemText(4, QCoreApplication::translate("D_Popup_FeedbackRequest", "Friend", nullptr));
        comboBox_Achived->setItemText(5, QCoreApplication::translate("D_Popup_FeedbackRequest", "Other", nullptr));

        label_12->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "Achived", nullptr));
        label_6->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "Grade", nullptr));
        label_9->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "Environment", nullptr));
        label_14->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "Category", nullptr));
        label_15->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "Aditional information", nullptr));
        label_16->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "Comments", nullptr));
        label_UseCount->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "10000th", nullptr));
        label_3->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "time :-)", nullptr));
        label_4->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "I'm developing and publishing ImageD as OpenSource so everyone can use it to learn about and do image processing as easy as possible. ", nullptr));
        label_5->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "It would be very nice if you can give me some feedback who you are and what you are doing with it.", nullptr));
        label_7->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "If you spent one minute filling the survey, you don't need to see this popup again, i promise! ;-)", nullptr));
        label_2->setText(QCoreApplication::translate("D_Popup_FeedbackRequest", "Thanks for using ImageD for the ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class D_Popup_FeedbackRequest: public Ui_D_Popup_FeedbackRequest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_POPUP_FEEDBACKREQUEST_H
