/************************************
 *   added:     30.10.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_STAT_TESTER_H
#define D_STAT_TESTER_H

//own
#include <d_enum.h>
#include <scenemousetrack.h>
#include <d_stat.h>
#include <d_table.h>

//basic
#include <vector>

//Qt
#include <QMainWindow>
#include <QImage>
#include <QPixmap>
#include <QInputDialog>

namespace Ui {
class D_stat_tester;
}

/*!
 * \brief The D_stat_tester class Little tool to play with statistic functions.
 * \details Can be accesed via D_MainWindow and offers tools for experimenting with linear and circular statistics.
 */
class D_stat_tester : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_stat_tester(QWidget *parent = 0);
    ~D_stat_tester();

private slots:
    void Init_ImageHist();

    void Position_Clicked(int x, int y);

    void Update_ImageHist();
    void Update_Image();
    void Update_Hist();
    void Update_Hist2Data();
    void Update_Data2Stats();

    void Set_Scale_Factor_View(QImage *QI, QGraphicsView *GV);
    void Update_View_Image();
    void Update_View_Stats();

    void Update_CircStats();

    void on_spinBox_Init_X_Min_valueChanged(int arg1);
    void on_spinBox_Init_X_Max_valueChanged(int arg1);

    void on_spinBox_Init_Y_Max_valueChanged(int arg1);

    void on_pushButton_DistributionUniform_clicked();

private:
    Ui::D_stat_tester *ui;

    int             x_min;
    int             x_max;
    int             y_min;
    int             y_max;

    double          x_factor;
    double          y_factor;

    int             x_pos_clk = 0;
    int             y_pos_clk = 0;
    int             x_val_clk = 0;
    int             y_val_clk = 0;

    int             h_hist;
    int             w_hist;

    QImage          QI_Hist;
    QPixmap         PX_Hist;
    SceneMouseTrack SC_Hist;

    vector<int>     v_hist;
    vector<double>  v_data;
    vector<double>  v_stat;

    //Circular (added 1.5 years later)
    D_Table         TableCircOut;
};

#endif // D_STAT_TESTER_H
