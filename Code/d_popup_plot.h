/************************************
 *   added:     08.11.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_POPUP_PLOT_H
#define D_POPUP_PLOT_H

//own
#include <d_enum.h>
#include <d_plot.h>

//general
#include <vector>

//Qt
#include <QDialog>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QGridLayout>
#include <QComboBox>

//namespaces
using namespace std;

namespace Ui {
class D_Popup_Plot;
}

/*!
 * \brief The D_Popup_Plot class WIP
 * \details Shall be able to plot data when needed temporarily only.
 */
class D_Popup_Plot : public QDialog
{
    Q_OBJECT

public:
    explicit D_Popup_Plot(QString Title, QString nameX, QString nameY, QString namePlot, QString nameSeries,        vector<double> vX,          vector<double> vY,          int plot_mode = c_PLOT_SIMPLE_POINT, bool as_exec = true, QWidget *parent = nullptr);
    explicit D_Popup_Plot(QString Title, QString nameX, QString nameY, QString namePlot, QString nameSeries,                                    vector<double> vY,          int plot_mode = c_PLOT_SIMPLE_POINT, bool as_exec = true, QWidget *parent = nullptr);
    explicit D_Popup_Plot(QString Title, QString nameX, QString nameY, QString namePlot, QStringList namesSeries,   vector<vector<double>> vvX, vector<vector<double>> vvY, int plot_mode = c_PLOT_SIMPLE_POINT, bool as_exec = true, QWidget *parent = nullptr);
    explicit D_Popup_Plot(QString Title, QString nameX, QString nameY, QString namePlot, QStringList namesSeries,                               vector<vector<double>> vvY, int plot_mode = c_PLOT_SIMPLE_POINT, bool as_exec = true, QWidget *parent = nullptr);
    ~D_Popup_Plot();

private slots:
    void Plot();

private:
    Ui::D_Popup_Plot *ui;

    void Init_Ui(QString QS_Titel, int init_PlotMode, bool as_exec);
    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init);



    QChartView              *pChartView;

    //data
    vector<vector<double>>  vvData_X;
    vector<vector<double>>  vvData_Y;
    QString                 QS_NamePlot;
    QString                 QS_Name_X;
    QString                 QS_Name_Y;
    QStringList             QSL_NamesSeries;

    //error handling
    D_Error_Handler ER;
    void ERR(int err, QString func = "not specified", QString detail = "not specified");
};

#endif // D_POPUP_PLOT_H
