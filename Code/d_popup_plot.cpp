/************************************
 *   added:     08.11.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_popup_plot.h"
#include "ui_d_popup_plot.h"

D_Popup_Plot::D_Popup_Plot(QString Title, QString nameX, QString nameY, QString namePlot, QString nameSeries, vector<double> *pvX, vector<double> *pvY, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::D_Popup_Plot)
{
    Init_Ui(Title);
    D_Plot::Plot_Scatter_2D_Single_Y(
                pChartView,
                pvX,
                pvY,
                namePlot,
                nameSeries,
                nameX,
                nameY);
}

D_Popup_Plot::~D_Popup_Plot()
{
    delete ui;
}

void D_Popup_Plot::Init_Ui(QString QS_Titel)
{
    ui->setupUi(this);
    setWindowTitle(QS_Titel);
    ui->gridLayout_Plot->addWidget(pChartView);
}
