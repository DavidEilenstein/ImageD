/************************************
 *   added:     29.09.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_popup_feedbackrequest.h"
#include "ui_d_popup_feedbackrequest.h"

D_Popup_FeedbackRequest::D_Popup_FeedbackRequest(D_Storage *pStorage, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::D_Popup_FeedbackRequest)
{
    ui->setupUi(this);

    pStore = pStorage;

    ui->pushButton_Send->setIcon(QIcon(":other/pill_red.jpg"));
    ui->pushButton_Send->setIconSize(ui->pushButton_Send->size());
    ui->pushButton_Remind->setIcon(QIcon(":other/pill_blue.jpg"));
    ui->pushButton_Remind->setIconSize(ui->pushButton_Remind->size());
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    Populate_CB_All();

    use_counter = pStore->get_UseCounter();
    if(use_counter == 1)
        ui->label_UseCount->setText("1st");
    else if(use_counter == 2)
        ui->label_UseCount->setText("2nd");
    else
        ui->label_UseCount->setText(QString::number(use_counter) + "th");
}

D_Popup_FeedbackRequest::~D_Popup_FeedbackRequest()
{
    delete ui;
}

void D_Popup_FeedbackRequest::Populate_CB_Single(QComboBox *CB, QStringList QSL, int init_index)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(init_index);
    CB->blockSignals(false);
}

void D_Popup_FeedbackRequest::Populate_CB_All()
{
    QStringList QSL_CountriesExpanded = QSL_Counties;
    QSL_CountriesExpanded.push_front("-");
    QSL_CountriesExpanded.push_back("other");
    Populate_CB_Single(ui->comboBox_Country, QSL_CountriesExpanded);
}

void D_Popup_FeedbackRequest::on_pushButton_Send_clicked()
{
    int counter_filled = 0;
    if(ui->comboBox_Achived->currentIndex() != 0)       counter_filled++;
    if(ui->comboBox_Department->currentIndex() != 0)    counter_filled++;
    if(ui->comboBox_Environment->currentIndex() != 0)   counter_filled++;
    if(ui->comboBox_UserType->currentIndex() != 0)      counter_filled++;
    if(ui->comboBox_Grade->currentIndex() != 0)         counter_filled++;
    if(ui->comboBox_Country->currentIndex() != 0)       counter_filled++;

    if(counter_filled < 4)
    {
        QMessageBox::warning(
                    this,
                    "Cheat attempt detected",
                    "Trying to send a kind of uncomplete survey is not really nice, right?"
                    "<br>Please select a non'-' entry in at least 4 drop down menus.");
        return;
    }

    QSysInfo SI;

    QString QS_MailAdress   = "D.Eilenstein@gsi.de";
    QString QS_Subject      = "ImageD - User Statistics";
    QString QS_Body         =
            " Hello David Eilenstein,"
            "\n here are my user stats:"
            "\n"
            "\n ________________________________________________________"
            "\n Comments:     " + ui->plainTextEdit_Comments->toPlainText() +
            "\n ________________________________________________________"
            "\n Achived:      " + ui->comboBox_Achived->currentText()       + " - " + ui->lineEdit_Achived->text() +
            "\n Department:   " + ui->comboBox_Department->currentText()    + " - " + ui->lineEdit_Department->text() +
            "\n Environment:  " + ui->comboBox_Environment->currentText()   + " - " + ui->lineEdit_Environment->text() +
            "\n User Type:    " + ui->comboBox_UserType->currentText()      + " - " + ui->lineEdit_UserType->text() +
            "\n Grade:        " + ui->comboBox_Grade->currentText()         + " - " + ui->lineEdit_Grade->text() +
            "\n Country:      " + ui->comboBox_Country->currentText()       + " - " + ui->lineEdit_Country->text() +
            "\n ________________________________________________________"
            "\n Version:      " + D_QS_Version +
            "\n Release:      " + D_QS_Release +
            "\n Time:         " + QDateTime::currentDateTime().date().toString(Qt::SystemLocaleShortDate) +
            "\n ________________________________________________________"
            "\n Machine:      " + SI.machineHostName() +
            "\n System:       " + SI.productType() +
            "\n Version:      " + SI.productVersion() +
            "\n CPU build:    " + SI.buildCpuArchitecture() +
            "\n CPU current:  " + SI.currentCpuArchitecture() +
            "\n ________________________________________________________";

    QString QS_HTML_Magic   = "mailto:?to=" + QS_MailAdress + "&subject=" + QS_Subject + "&body=" + QS_Body;

    QDesktopServices::openUrl(QUrl(QS_HTML_Magic, QUrl::TolerantMode));

    pStore->set_FeedbackIsSent(true);
}

void D_Popup_FeedbackRequest::on_pushButton_Remind_clicked()
{
    if     (use_counter < 10)      pStore->set_ReminderNextAt(10);
    else if(use_counter < 25)      pStore->set_ReminderNextAt(25);
    else if(use_counter < 50)      pStore->set_ReminderNextAt(50);
    else if(use_counter < 75)      pStore->set_ReminderNextAt(75);
    else if(use_counter < 100)     pStore->set_ReminderNextAt(100);
    else if(use_counter < 150)     pStore->set_ReminderNextAt(150);
    else if(use_counter < 200)     pStore->set_ReminderNextAt(200);
    else if(use_counter < 250)     pStore->set_ReminderNextAt(250);
    else if(use_counter < 500)     pStore->set_ReminderNextAt(500);
    else if(use_counter < 750)     pStore->set_ReminderNextAt(750);
    else if(use_counter < 1000)    pStore->set_ReminderNextAt(1000);
    else                           pStore->set_ReminderNextAt(use_counter + 1);

    close();
}
