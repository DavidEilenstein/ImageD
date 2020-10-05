/************************************
 *   added:     04.11.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_popup_listedit.h"
#include "ui_d_popup_listedit.h"

D_Popup_ListEdit::D_Popup_ListEdit(QString Title, vector<int> *Indices, QStringList Names, int init_index, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::D_Popup_ListEdit)
{
    //save in this class
    pvIndices = Indices;
    vIndicesBackup = *pvIndices;
    QSL_IndicesNames = Names;

    //show
    ui->setupUi(this);
    setWindowTitle(Title);
    ui->comboBox_List->addItems(QSL_IndicesNames);
    ui->comboBox_List->setCurrentIndex(init_index);
    ShowSelection();
}

D_Popup_ListEdit::~D_Popup_ListEdit()
{
    delete ui;
}

void D_Popup_ListEdit::ShowSelection()
{
    ui->plainTextEdit_Selection->clear();

    QString QS_Selection;
    for(size_t i = 0; i < pvIndices->size(); i++)
    {
        int val = (*pvIndices)[i];
        if(val < QSL_IndicesNames.size() && val >= 0)
        {
            if(i != 0)
                QS_Selection.append("\n");
            QS_Selection.append(QSL_IndicesNames[val]);
        }
    }

    ui->plainTextEdit_Selection->setPlainText(QS_Selection);
}

void D_Popup_ListEdit::on_pushButton_Add_clicked()
{
    int val = ui->comboBox_List->currentIndex();

    for(size_t i = 0; i < pvIndices->size(); i++)
        if((*pvIndices)[i] == val)
            return;

    pvIndices->push_back(val);
    ShowSelection();
}

void D_Popup_ListEdit::on_pushButton_All_clicked()
{
    pvIndices->clear();
    pvIndices->resize(QSL_IndicesNames.size());
    for(int i = 0; i < QSL_IndicesNames.size(); i++)
        (*pvIndices)[i] = i;

    ShowSelection();
}

void D_Popup_ListEdit::on_pushButton_Remove_clicked()
{
    pvIndices->erase(std::remove(pvIndices->begin(), pvIndices->end(), ui->comboBox_List->currentIndex()), pvIndices->end());
    ShowSelection();
}

void D_Popup_ListEdit::on_pushButton_Clear_clicked()
{
    pvIndices->clear();
    ShowSelection();
}

void D_Popup_ListEdit::on_pushButton_Reset_clicked()
{
    *pvIndices = vIndicesBackup;
    ShowSelection();
}

void D_Popup_ListEdit::on_pushButton_Done_clicked()
{
    close();
}
