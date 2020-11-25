/************************************
 *   added:     25.11.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_popup_listedit_numbers.h"
#include "ui_d_popup_listedit_numbers.h"

D_Popup_ListEdit_Numbers::D_Popup_ListEdit_Numbers(vector<double> *vDataToEdit, QString QS_Title, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::D_Popup_ListEdit_Numbers)
{
    ui->setupUi(this);
    setWindowTitle(QS_Title);
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));

    pChartView = new QChartView();
    ui->gridLayout_NumbersPlot->addWidget(pChartView);
    pChartView->setRenderHint(QPainter::Antialiasing);
    pChartView->setRubberBand(QChartView::RectangleRubberBand);
    pChartView->setInteractive(true);

    vData = vDataToEdit;
    Data_2_Ui();

    connect(ui->pushButton_Update, SIGNAL(clicked()), this, SLOT(Ui_2_Data()));
}


D_Popup_ListEdit_Numbers::~D_Popup_ListEdit_Numbers()
{
    delete ui;
}

void D_Popup_ListEdit_Numbers::Data_2_Ui()
{
    QString QS_Numbers;
    for(size_t i = 0; i < vData->size(); i++)
    {
        if(i != 0)
            QS_Numbers.append("\n");
        QS_Numbers.append(QString::number((*vData)[i]));
    }

    ui->plainTextEdit_Numbers->clear();
    ui->plainTextEdit_Numbers->setPlainText(QS_Numbers);

    //plot
    D_Plot::Plot_Line_XY_Single(
                pChartView,
                *vData,
                "Visualization",
                "Data",
                "order",
                "value",
                c_AXE_TRANS_LIN,
                c_AXE_TRANS_LIN,
                true);
}

void D_Popup_ListEdit_Numbers::Ui_2_Data()
{
    //clear old
    vData->clear();

    //read
    QStringList QSL_Numbers = ui->plainTextEdit_Numbers->toPlainText().split("\n");
    for(int i = 0; i < QSL_Numbers.size(); i++)
    {
        bool ok;
        double value = QSL_Numbers[i].toDouble(&ok);
        if(ok)
            vData->push_back(value);
    }

    ui->plainTextEdit_Numbers->blockSignals(true);
    Data_2_Ui();
    ui->plainTextEdit_Numbers->blockSignals(false);
}




void D_Popup_ListEdit_Numbers::on_pushButton_Ok_clicked()
{
    Ui_2_Data();
    close();
}
