/************************************
 *   added:     11.03.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VIEWER_PLOT_H
#define D_VIEWER_PLOT_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_math.h>
#include <d_plot.h>

//general
#include <iostream>
#include <vector>

//Qt
#include <QObject>
#include <QPixmap>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QElapsedTimer>
#include <QGridLayout>

//Qt-Charts
#include <QtCharts/QChartView>
#include <QtCharts/QChart>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

class D_Viewer_Plot : public QWidget
{
    Q_OBJECT

public:
    D_Viewer_Plot();
    D_Viewer_Plot(QGridLayout *pGL);
    void set_Layout(QGridLayout *pGL);

    //int Plot_X1D_Y1D(vector<double> vX, vector<double> vY, int mode, QString QS_Title, QString QS_X, QString QS_Y, QString QS_Series);

private:


private slots:


signals:

private:
    //ui
    QGridLayout *Layout;
    QChartView *pChartView;

    //data & transformation
    //x
    vector<double>              *vX;
    vector<vector<double>>      *vvX;
    int                         trans_x;
    double                      min_x;
    double                      min_x_trans;
    double                      max_x;
    double                      max_x_trans;
    //y
    vector<double>              *vY;
    vector<vector<double>>      *vvY;
    int                         trans_y;
    double                      min_y;
    double                      min_y_trans;
    double                      max_y;
    double                      max_y_trans;


    bool state_GL_set = false;
};

#endif // D_VIEWER_PLOT_H
