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
using namespace cv;

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

    //loss/accuracy
    double                  loss = 0;
    double                  accuracy = 0;
    vector<double>          vLoss;
    vector<double>          vAccuracy;
    size_t                  iteration = 0;

    //Statusbar
    QLabel                  *pQL_ValueUnderCursor;
    QLabel                  *pQL_CursorPosition;

    //Error handler
    D_Error_Handler ER;
    void ERR(int err, QString func = "not specified", QString detail = "not specified");

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
