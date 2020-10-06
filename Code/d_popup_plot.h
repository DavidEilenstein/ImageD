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
    explicit D_Popup_Plot(QString Title, QString nameX, QString nameY, QString namePlot, QString nameSeries, vector<double> *pvX, vector<double> *pvY, QWidget *parent = nullptr);
    ~D_Popup_Plot();



private:
    Ui::D_Popup_Plot *ui;

    void Init_Ui(QString QS_Titel);
    QChartView *pChartView;
};

#endif // D_POPUP_PLOT_H
