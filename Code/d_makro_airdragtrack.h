/************************************************
 *   added:     05.06.2020                      *
 *   author:    David Eilenstein                *
 *   contact:   David.Eilenstein@stud.h-da.de   *
 *   project:   ImageD                          *
 *   facility:  Hochschule Darmstadt, Ger       *
 ************************************************/

#ifndef D_MAKRO_AIRDRAGTRACK_H
#define D_MAKRO_AIRDRAGTRACK_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_img_proc.h>
#include <d_plot.h>
#include <d_stat.h>
#include <d_viewer.h>
#include <d_storage.h>
#include<d_videoslicer.h>

//Qt
#include <QMainWindow>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QComboBox>

//Qt::Charts
#include <QChartView>
#include <QChart>
#include <QGridLayout>

//general
#include <iostream>
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
class D_MAKRO_AirDragTrack;
}

class D_MAKRO_AirDragTrack : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_AirDragTrack(D_Storage *pStorage, QWidget *parent = nullptr);
    ~D_MAKRO_AirDragTrack();

    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

private slots:
    void Data_Add();
    void Data_Clear();
    void Data_SelectVideo();

    void Update_Ui();
    void Update_Views();
    void Update_Images();
    void Update_Image_Proc();

    void Update_ImgProc_All();
    void Update_ImgProc(int step_start);
    void Update_ImgProc_Step(int step);

    void Update_ImgProc_FullVideo();
    void CalcAll();
    void PlotAll();
    void PlotAllVideos();

    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init);
    void Populate_CB_Start();

    void BlockSignals_FrameSelection(bool block);

    void on_horizontalSlider_T_Frame_valueChanged(int value);
    void on_spinBox_T_Frame_valueChanged(int arg1);
    void on_doubleSpinBox_T_Sec_valueChanged(double arg1);

    void on_comboBox_ProcStep_currentIndexChanged(int index);

    void on_spinBox_CropStart_valueChanged(int arg1);

    void on_spinBox_CropEnd_valueChanged(int arg1);

    void on_pushButton_ProcVideo_clicked();

    void on_pushButton_ProcAllVideos_clicked();

    void on_action_View_Results_Big_triggered(bool checked);

    void on_action_Save_Screenshot_Full_Window_triggered();

private:
    Ui::D_MAKRO_AirDragTrack *ui;
    bool ClosingPossible = false;

    //Storage
    D_Storage                           *pStore;

    //states
    bool                                state_video_valid = false;
    bool                                state_frame_img_proc_ready = false;
    bool                                state_video_analysed = false;

    //Files
    QFileInfoList                       FIL_Videos;
    QStringList                         QSL_Videos_Names;
    QStringList                         QSL_Videos_Paths;
    QStringList                         QSL_Videos_Suffix;

    //Video
    D_VideoSlicer           VS_Video;

    //Data
    vector<vector<Point2f>>         vv_CentersVF;
    double                          F_start = 0;
    double                          F_end = 0;
    vector<vector<vector<double>>>  vvv_PositionsVSF;

    //proc
    vector<Mat>             vMA_ProcSteps;

    //viewer
    D_Viewer                Viewer_Proc_Crop;
    D_Viewer                Viewer_Proc_Gray;
    D_Viewer                Viewer_Proc_Blur;
    D_Viewer                Viewer_Proc_Thresh;
    D_Viewer                Viewer_Proc_ExBorder;

    //plot
    const size_t            S_Count = 5; //s and 1st-4th derviate of s (v,a,...)
    vector<QGridLayout*>    vPLot_Grids_S;
    vector<QChartView*>     vPlot_ChartViews_S;
    QStringList             QSL_S_Names = {"location", "speed", "accelaration", "change of acceleration", "change of change of acceleration"};
    QChartView*             Plot_Results;

    //error handling
    D_Error_Handler ER;
    void ERR(int err, QString func = "not specified", QString detail = "not specified");

    //CONSTANTS
    enum PROC_STEPS {
        STEP_LOAD,
        STEP_CROP,
        STEP_GRAY,
        STEP_BLUR,
        STEP_BINARY,
        STEP_EXCLUDE_BORDER,
        STEP_NUMBER_OF
    };
    const QStringList QSL_ProcSteps = {
        "Load Image",
        "Crop",
        "Gray",
        "Blur",
        "Binary",
        "Exclude Border"
    };
};

#endif // D_MAKRO_AIRDRAGTRACK_H
