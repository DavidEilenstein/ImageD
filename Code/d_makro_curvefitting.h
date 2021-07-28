/************************************
 *   added:     08.08.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MAKRO_CURVEFITTING_H
#define D_MAKRO_CURVEFITTING_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_plot.h>
#include <d_stat.h>
#include <d_table.h>
#include <d_storage.h>
#include <d_viewer.h>

//Qt
#include <QMainWindow>
#include <QFileDialog>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QDateTime>
#include <QComboBox>
#include <QCloseEvent>
#include <QResizeEvent>
#include <QInputDialog>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPlainTextEdit>

//Qt::Charts
#include <QChartView>
#include <QChart>

//general
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

namespace Ui {
class D_MAKRO_CurveFitting;
}

class D_MAKRO_CurveFitting : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_CurveFitting(D_Storage *pStorage ,QWidget *parent = 0);
    ~D_MAKRO_CurveFitting();

    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void set_ClosingPossible(bool closeable)        {ClosingPossible = closeable;}

    void UpdateUi();

    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init);
    void Populate_CB();
    void ParamInitUiVectors();
    void DataInitUiVectors();

private slots:
    void FittingStart();
    void DataRead();
    void DataWeightsRead();
    void ParametersRead();
    void ParametersCount();
    void ParameterSpaceInit();
    void FittingLoop();
    void ParameterSpaceShow();
    void ParameterSpaceWrite(int i_d1, int i_w1, int i_d2, int i_w2, double val);


    void Update_View();

    void PlotTest_PbBi();

    void on_doubleSpinBox_step_d1_valueChanged(double arg1);

    void on_doubleSpinBox_step_w1_valueChanged(double arg1);

    void on_doubleSpinBox_step_d2_valueChanged(double arg1);

    void on_doubleSpinBox_step_w2_valueChanged(double arg1);


    void on_doubleSpinBox_range_t_max_valueChanged(double arg1);

    void on_doubleSpinBox_range_a_max_valueChanged(double arg1);

    void on_spinBox_VisDispPlane_d1_valueChanged(int arg1);

    void on_spinBox_VisDispPlane_w1_valueChanged(int arg1);

    void on_spinBox_VisDispPlane_d2_valueChanged(int arg1);

    void on_spinBox_VisDispPlane_w2_valueChanged(int arg1);

    void on_comboBox_VisDispPlane_Plane_currentIndexChanged(int index);

private:
    Ui::D_MAKRO_CurveFitting *ui;

    bool ClosingPossible = false;

    bool state_function_selected = false;
    bool state_data_read = false;
    bool state_parameters_read = false;

    //Store
    D_Storage                       *pStore;

    //Data
    vector<vector<vector<double>>>  vvv_Data_Set_TA;
    vector<int>                     v_number_of_points;
    vector<double>                  v_data_score_weights;
    vector<QSpinBox*>               v_data_score_weights_ui;
    vector<QPlainTextEdit*>         v_Data_ui;



    //Parameters
    vector<QLabel*>         v_param_cur_ui;
    vector<QLabel*>         v_param_opt_ui;
    vector<QDoubleSpinBox*> v_param_min_ui;
    vector<QDoubleSpinBox*> v_param_max_ui;
    vector<QDoubleSpinBox*> v_param_step_ui;
    vector<double>          v_param_cur;
    vector<double>          v_param_min;
    vector<double>          v_param_max;
    vector<double>          v_param_step;
    vector<double>          v_param_opt;
    vector<int>             v_param_count;
    int                     param_space_size = 0;

    //Parameter Space
    D_Viewer                View_ParamSpace;
    D_VisDat_Obj            VD_ParamSpace;
    Mat                     MA_ParamSpaceSlice;

    //Functions

    //Testing
    long double         Test_Combi(long double t, long double w1, long double d1, long double w2, long double d2, int set);
    long double         Test_F3_Pb(long double t, long double w1, long double d1, long double w2, long double d2);
    long double         Test_F4_Bi(long double t, long double w1, long double d1, long double w2, long double d2);

    //DGL
    long double         Franzi_Combi(long double t, long double w1, long double d1, long double w2, long double d2, int set, bool past);
    long double         Franzi_Pb_Combi(long double t, long double w1, long double d1, long double w2, long double d2);
    long double         Franzi_Bi_Combi(long double t, long double w1, long double d1, long double w2, long double d2);

    //pre 60 min
    long double         Franzi_n1_Rn_pre60min(long double t, long double ld);
    long double         Franzi_n2_Po_pre60min(long double t, long double ld);
    long double         Franzi_n3_Pb_pre60min(long double t, long double ld);
    long double         Franzi_n4_Bi_pre60min(long double t, long double ld);

    //past 60min
    long double         Franzi_n1_Rn_past60min(long double t, long double ld, long double n10);
    long double         Franzi_n2_Po_past60min(long double t, long double ld, long double n10, long double n20);
    long double         Franzi_n3_Pb_past60min(long double t, long double ld, long double n10, long double n20, long double n30);
    long double         Franzi_n4_Bi_past60min(long double t, long double ld, long double n10, long double n20, long double n30, long double n40);

    long double         Franzi_n1_Rn_past60min_single(long double t, long double ld);
    long double         Franzi_n2_Po_past60min_single(long double t, long double ld);
    long double         Franzi_n3_Pb_past60min_single(long double t, long double ld);
    long double         Franzi_n4_Bi_past60min_single(long double t, long double ld);

    //60min
    long double         Franzi_n10_Rn_60min(long double w1, long double d1, long double w2, long double d2);
    long double         Franzi_n20_Po_60min(long double w1, long double d1, long double w2, long double d2);
    long double         Franzi_n30_Pb_60min(long double w1, long double d1, long double w2, long double d2);
    long double         Franzi_n40_Bi_60min(long double w1, long double d1, long double w2, long double d2);

    long double         Franzi_n10_Rn_60min_single(long double ld);
    long double         Franzi_n20_Po_60min_single(long double ld);
    long double         Franzi_n30_Pb_60min_single(long double ld);
    long double         Franzi_n40_Bi_60min_single(long double ld);




    QChartView              *pChartView;

    //Error handler
    D_Error_Handler                 ER;
    void                            ERR(int err, QString func = "not specified", QString detail = "not specified");

    //CONSTANTS
    const double     t_fix = 60;    //minutes
    const double     t_min = 0;     //minutes (min displayed)
    double           t_max = 240;   //minutes (max displayed)
    double           a_display_min_max = 2000;
    const double     l1 = log(2) / (3.80 * 60.0 * 24.0);
    const double     l2 = log(2) / (3.10);
    const double     l3 = log(2) / (26.80);
    const double     l4 = log(2) / (19.80);

    enum C_PARAM
    {
        c_PARAM_D1,
        c_PARAM_W1,
        c_PARAM_D2,
        c_PARAM_W2,
        c_PARAM_NUMBER_OF
    };

    enum C_KOORD
    {
        c_KOORD_T,
        c_KOORD_A,
        c_KOORD_NUMBER_OF
    };

    enum C_DATASET
    {
        c_DATA_PB_295,
        c_DATA_PB_352,
        c_DATA_BI,
        c_DATA_NUMBER_OF
    };
    QStringList QSL_DataSet =
    {
        "Plumbum 295",
        "Plumbum 352",
        "Bismut"
    };

    enum C_PLANES_DW
    {
        c_PLANE_DW_D1_W1,
        c_PLANE_DW_D1_D2,
        c_PLANE_DW_D1_W2,
        c_PLANE_DW_W1_D2,
        c_PLANE_DW_W1_W2,
        c_PLANE_DW_D2_W2,
        c_PLANE_DW_NUMBER_OF
    };
    const QStringList QSL_PlanesDW =
    {
        "x_d1 y_w1",
        "x_d1 y_d2",
        "x_d1 y_w2",
        "x_w1 y_d2",
        "x_w1 y_w2",
        "x_d2 y_w2"
    };
};

#endif // D_MAKRO_CURVEFITTING_H
