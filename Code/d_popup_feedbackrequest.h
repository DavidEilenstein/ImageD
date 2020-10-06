/************************************
 *   added:     29.09.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_POPUP_FEEDBACKREQUEST_H
#define D_POPUP_FEEDBACKREQUEST_H

//own
#include <d_enum.h>
#include <d_storage.h>

//general
#include <vector>

//Qt
#include <QDialog>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <QComboBox>
#include <QDesktopServices>

//namespaces
using namespace std;

namespace Ui {
class D_Popup_FeedbackRequest;
}

/*!
 * \brief The D_Popup_FeedbackRequest class Popup that askes the user for feedback about ImageD
 * \details Pops up after a given number of uses and asks for feedback.
 */
class D_Popup_FeedbackRequest : public QDialog
{
    Q_OBJECT

public:
    explicit D_Popup_FeedbackRequest(D_Storage *pStorage, QWidget *parent = nullptr);
    ~D_Popup_FeedbackRequest();

private slots:
    void on_pushButton_Send_clicked();
    void on_pushButton_Remind_clicked();

private:
    Ui::D_Popup_FeedbackRequest *ui;

    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int init_index = 0);
    void Populate_CB_All();

    D_Storage *pStore;
    int use_counter = 0;
};

#endif // D_POPUP_FEEDBACKREQUEST_H
