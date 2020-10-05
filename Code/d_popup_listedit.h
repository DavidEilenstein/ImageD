/************************************
 *   added:     04.11.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_POPUP_LISTEDIT_H
#define D_POPUP_LISTEDIT_H

//own
#include <d_enum.h>

//general
#include <vector>

//Qt
#include <QDialog>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>

//namespaces
using namespace std;

namespace Ui {
class D_Popup_ListEdit;
}

class D_Popup_ListEdit : public QDialog
{
    Q_OBJECT

public:
    explicit D_Popup_ListEdit(QString Title, vector<int> *Indices, QStringList Names, int init_index, QWidget *parent = nullptr);
    ~D_Popup_ListEdit();

private slots:
    void ShowSelection();

    void on_pushButton_Add_clicked();

    void on_pushButton_All_clicked();

    void on_pushButton_Remove_clicked();

    void on_pushButton_Clear_clicked();

    void on_pushButton_Reset_clicked();

    void on_pushButton_Done_clicked();

private:
    Ui::D_Popup_ListEdit *ui;

    vector<int> *pvIndices;
    vector<int> vIndicesBackup;
    QStringList QSL_IndicesNames;
};

#endif // D_POPUP_LISTEDIT_H
