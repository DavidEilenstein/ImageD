/****************************************************
 *   added:     24.01.2021                          *
 *   author:    David Eilenstein                    *
 *   contact:   David.Eilenstein@stud.h-da.de.de    *
 *   project:   ImageD                              *
 *   facility:  Hochschule Darmstadt, Ger           *
 ****************************************************/

#ifndef D_MAKRO_SOFTMAXVISUALIZATION_H
#define D_MAKRO_SOFTMAXVISUALIZATION_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_visdat_proc.h>
#include <d_plot.h>
#include <d_stat.h>
#include <d_viewer.h>
#include <d_storage.h>
#include <d_table.h>
#include <d_img_proc.h>
#include <d_videowriter.h>

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
class D_MAKRO_SoftmaxVisualization;
}

class D_MAKRO_SoftmaxVisualization : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_SoftmaxVisualization(D_Storage *pStorage, QWidget *parent = nullptr);
    ~D_MAKRO_SoftmaxVisualization();

    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

private slots:

    void Update_Ui();

    void Update_Views();
    void Update_Images();

    void Load_File_CSV();
    void Data_Vec2Mat();
    void Data_InitMats_CorrectSize(bool init_x_and_y = true);

    void Init_W();

    void Set_MatrixViewDiemsnions();

    void Proc_Step();
    void Proc_StepDetail();
    void Proc_StepIteration();
    void Proc_StepEndless();

    void Proc_SaveVideos();
    void Proc_SaveVideo();
    void Proc_SaveVideo(QDir DIR_Save, double lambda, double delta, double fps, size_t max_iterations);
    void Proc_SaveVideos(QDir Path, double fps, size_t max_iterations, double lambda_min, double lambda_max, double lambda_step, double delta_min_exp, double delta_max_exp, double delta_step_exp);

    void Proc_s();
    void Proc_s_normed();
    void Proc_classify();
    void Proc_accuracy();
    void Proc_L();
    void Proc_loss();
    void Proc_L_partial();
    void Proc_grad();
    void Proc_W();

    void on_pushButton_LoadData_clicked();
    void on_pushButton_Proc_Step_clicked();
    void on_pushButton_Proc_Iteration_clicked();
    void on_pushButton_Proc_Endless_clicked();
    void on_pushButton_Proc_Stop_clicked();

    void on_pushButton_ResetAndInit_clicked();


    void on_checkBox_lambda_stateChanged(int arg1);

private:
    Ui::D_MAKRO_SoftmaxVisualization *ui;
    bool ClosingPossible = false;

    //dimensions
    size_t K = 3;
    size_t M = 5;
    size_t N = 7;

    //Matrixes
    Mat MA_x;
    Mat MA_y;
    Mat MA_W;
    Mat MA_s;
    Mat MA_s_normed;
    Mat MA_classification;
    Mat MA_L;
    Mat MA_L_partial_s;
    Mat MA_gradient;

    Mat MA_color_x;
    Mat MA_color_y;
    Mat MA_color_W;
    Mat MA_color_s;
    Mat MA_color_s_normed;
    Mat MA_color_classification;
    Mat MA_color_L;
    Mat MA_color_L_partial_s;
    Mat MA_color_gradient;

    //Viewers
    D_Viewer Viewer_x;
    D_Viewer Viewer_y;
    D_Viewer Viewer_W;
    D_Viewer Viewer_s;
    D_Viewer Viewer_s_normed;
    D_Viewer Viewer_classification;
    D_Viewer Viewer_L;
    D_Viewer Viewer_L_partial_s;
    D_Viewer Viewer_gradient;

    //Stuff needed to display plots
    QChartView              *pChartView_Loss;
    QChartView              *pChartView_Accuracy;

    //Storage
    D_Storage               *pStore;

    //data vectors
    vector<vector<double>>  vvData_X;
    vector<int>             vData_Y;

    //data vectors default
    vector<vector<double>>  vvData_X_default = {
        {0.866359,0.648724,0.915475,0.774046,0.29548,0.700584,0.664165,1},
        {0.928156,0.714069,0.950374,0.790589,0.394482,0.755629,0.54843,1},
        {0.859534,0.628962,0.927481,0.731163,0.249574,0.689212,0.575987,1},
        {0.827632,0.592264,0.914473,0.708229,0.227076,0.676201,0.582829,1},
        {0.931524,0.720506,0.936026,0.82236,0.411425,0.79493,0.595197,1},
        {0.844312,0.597158,0.880445,0.770344,0.191811,0.705399,0.671659,1},
        {0.82187,0.566162,0.884021,0.724462,0.10111,0.681813,0.647746,1},
        {0.826701,0.577694,0.902557,0.709167,0.16867,0.669326,0.608026,1},
        {0.876158,0.655822,0.933991,0.751797,0.251131,0.702768,0.591723,1},
        {0.885632,0.671388,0.938044,0.763005,0.304516,0.724269,0.589883,1},
        {0.856731,0.627637,0.920574,0.740614,0.261042,0.68192,0.6067,1},
        {0.89496,0.679769,0.944439,0.762103,0.322769,0.722978,0.578113,1},
        {0.86862,0.61673,0.896961,0.766564,0.249199,0.709011,0.583487,1},
        {0.848867,0.602751,0.899702,0.744629,0.16704,0.70259,0.59923,1},
        {0.80779,0.565745,0.898087,0.70143,0.175321,0.658018,0.594111,1},
        {0.833912,0.596372,0.897724,0.739999,0.198475,0.684264,0.621166,1},
        {0.818235,0.547453,0.882017,0.703708,0.141858,0.684256,0.594548,1},
        {0.848497,0.619851,0.932614,0.712661,0.253004,0.690594,0.552916,1},

        {0.985175,0.878277,0.950167,0.972818,0.834999,0.782597,0.92665,1},
        {0.987205,0.878681,0.95072,0.972132,0.813235,0.799759,0.91587,1},
        {0.987195,0.889996,0.95817,0.9694,0.831583,0.803753,0.990909,1},
        {0.985127,0.878145,0.949495,0.97405,0.888338,0.784302,1,1},
        {0.989203,0.885642,0.952854,0.975451,0.855294,0.805421,0.915751,1},
        {0.988613,0.885136,0.957021,0.966423,0.813052,0.79056,0.921053,1},
        {0.9836,0.874373,0.952222,0.964318,0.848497,0.779409,0.949367,1},
        {0.986967,0.886581,0.956612,0.968829,0.83314,0.78104,0.993333,1},
        {0.986627,0.859847,0.957316,0.938232,0.680274,0.76569,0.742857,1},
        {0.985711,0.882421,0.951451,0.974771,0.868461,0.802579,0.935065,1},
        {0.988231,0.875756,0.950679,0.968981,0.798331,0.805016,0.87557,1},
        {0.987317,0.885967,0.955766,0.969873,0.832722,0.795875,0.973684,1},
        {0.989393,0.887392,0.958209,0.966484,0.790791,0.787293,0.855856,1},
        {0.988157,0.888124,0.953339,0.977189,0.892848,0.795465,1,1},
        {0.988299,0.882066,0.95144,0.974402,0.831782,0.788393,0.9625,1},
        {0.988234,0.878626,0.952737,0.967961,0.78283,0.780456,0.849246,1},
        {0.986832,0.883144,0.95187,0.974712,0.888545,0.795468,0.971831,1},
        {0.986593,0.871116,0.949967,0.965293,0.798915,0.775214,0.905847,1},
        {0.990771,0.896778,0.95498,0.983323,0.898937,0.785882,0.944444,1},

        {0.985785,0.727501,0.957502,0.793514,0.407978,0.769593,0.497326,1},
        {0.985101,0.703588,0.952131,0.776113,0.37786,0.767275,0.473282,1},
        {0.983257,0.710069,0.949994,0.78679,0.391829,0.785028,0.480505,1},
        {0.988398,0.754014,0.955316,0.826201,0.488928,0.74822,0.515385,1},
        {0.98551,0.76665,0.945564,0.857463,0.504937,0.820216,0.595652,1},
        {0.989224,0.79441,0.953551,0.873689,0.540131,0.771232,0.623596,1},
        {0.949833,0.597741,0.948322,0.664664,0.265085,0.774013,0.375053,1},
        {0.983959,0.668986,0.947537,0.745117,0.378312,0.760697,0.451801,1},
        {0.983792,0.71889,0.954615,0.788872,0.394541,0.730556,0.50309,1},
        {0.984208,0.660396,0.96245,0.712933,0.329624,0.786978,0.391196,1},
        {0.985829,0.719326,0.948457,0.799633,0.429681,0.738559,0.498866,1},
        {0.985701,0.668001,0.946639,0.745433,0.374695,0.782016,0.413174,1},
        {0.983176,0.725491,0.94679,0.809327,0.440624,0.758519,0.536817,1},
        {0.985277,0.678122,0.948193,0.754247,0.365632,0.760595,0.449575,1},
        {0.978861,0.70589,0.949681,0.782674,0.430535,0.716313,0.54386,1},
        {0.976651,0.685715,0.947664,0.763545,0.366541,0.762839,0.470523,1},
        {0.986969,0.76173,0.95535,0.834594,0.471337,0.771196,0.52459,1},
        {0.987792,0.753577,0.951862,0.831726,0.470487,0.771024,0.51444,1},
        {0.988111,0.727022,0.946377,0.811745,0.447654,0.760482,0.518008,1}};

    vector<int>             vData_Y_default = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};

    //loss/accuracy
    double                  loss = 0;
    double                  accuracy = 0;
    vector<double>          vLoss;
    vector<double>          vAccuracy;
    size_t                  iteration = 0;

    //Statusbar
    QLabel                  *pQL_ValueUnderCursor;
    QLabel                  *pQL_CursorPosition;

    //proc chain
    bool endless_proc_stop = false;
    size_t step_next = STEP_s;
    enum STEP {
        STEP_s,
        STEP_s_norm,
        STEP_classify,
        STEP_accuracy,
        STEP_L,
        STEP_loss,
        STEP_L_partial,
        STEP_grad,
        STEP_W,
        STEP_NUMBER_OF
    };
};

#endif // D_MAKRO_SOFTMAXVISUALIZATION_H
