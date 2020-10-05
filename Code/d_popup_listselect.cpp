/************************************
 *   added:     09.12.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_popup_listselect.h"
#include "ui_d_popup_listselect.h"

D_Popup_ListSelect::D_Popup_ListSelect(QString Title, int *index, QStringList Names, int init_index, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::D_Popup_ListSelect)
{
    ui->setupUi(this);

    //keep data
    index_selected = index;
    QSL_Names = Names;

    //Show stuff
    setWindowTitle(Title);
    ui->comboBox_List->blockSignals(true);
    ui->comboBox_List->addItems(QSL_Names);
    ui->comboBox_List->setCurrentIndex(init_index);
    ui->comboBox_List->blockSignals(false);
}

D_Popup_ListSelect::~D_Popup_ListSelect()
{
    delete ui;
}

void D_Popup_ListSelect::on_pushButton_Done_clicked()
{
    close();
}

void D_Popup_ListSelect::on_comboBox_List_currentIndexChanged(int index)
{
    *index_selected = index;
}
