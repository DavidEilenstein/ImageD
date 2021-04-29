/************************************
 *   added:     ??.10.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MAKRO_CILIASPHERETRACKER_H
#define D_MAKRO_CILIASPHERETRACKER_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_visdat_proc.h>
#include <d_plot.h>
#include <d_stat.h>
#include <d_viewer.h>
#include <d_storage.h>
#include <d_table.h>
#include <d_popup_listedit.h>
#include <d_videoslicer.h>
#include <d_videowriter.h>
#include <d_pdf_writer.h>
#include <d_geo_pointset_2d.h>
#include <d_geo_lineset_2d.h>
#include <d_geo_line_2d.h>
#include <d_geo_point_2d.h>

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
#include <qplaintextedit.h>
#include <QColorDialog>
#include <QPdfWriter>

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
class D_MAKRO_CiliaSphereTracker;
}

class D_MAKRO_CiliaSphereTracker : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_CiliaSphereTracker(D_Storage *pStorage, QWidget *parent = nullptr);
    ~D_MAKRO_CiliaSphereTracker();

    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

private slots:
    void Update_Ui();
    void Update_Views();
    void Update_Images();
    void Update_Image_Proc();
    void Update_Image_Results();

    void Update_ImgProc_All();
    void Update_ImgProc(int step_start);
    void Update_ImgProc_Step(int step);

    void Update_VideoProc_All();

    void TimeProjectSum_Init();
    void TimeProjectSum_Add();

    void Update_Results();

    void Update_Result_GraphicsTimeProjectSum();
    void Update_Result_GraphicsVectors();
    void Update_Result_GraphicsHeatmap();
    void Update_Result_GraphicsVortexCenter();
    void Update_Result_SpeedStatCustom();
    void Update_Result_AngleStatCustom();
    void Update_Result_SpeedAnalysis();
    void Update_Result_AngleAnalysis();

    void Save_AnalysisAll();
    void Save_AnalysisSingle();
    void Save_ResultVectorFieldVideo(QString Path_Out, int gridCellsHorizontal, int gridCellsVertical, double timeWindowSeconds, int backgroundMode);

    void Data_Add();
    void Data_Clear();
    void Data_SelectVideo();
    void Data_SelectRoiTime();
    void Data_SelectRoiSpace();

    void Data_CalcFullVideoStats();
    void Data_Split2GridSampling();

    void Update_Ui_Roi();
    void Update_Ui_ResParam();
    void Update_Ui_ResMovAv();

    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init);
    void Populate_CB_Start();

    void BlockSignals_FrameSelection(bool block);
    void BlockSignals_FrameSelection_MovingAverage(bool block);

    void on_horizontalSlider_Proc_Frame_valueChanged(int value);
    void on_spinBox_Proc_Frame_valueChanged(int arg1);
    void on_doubleSpinBox_Proc_Time_valueChanged(double arg1);

    void on_comboBox_Data_Videos_currentIndexChanged(int index);
    void on_comboBox_Proc_Step_currentIndexChanged(int index);

    void on_doubleSpinBox_Param_Scale_Px_valueChanged(double arg1);
    void on_doubleSpinBox_Param_Scale_mm_valueChanged(double arg1);
    void on_doubleSpinBox_Param_Crop_Start_valueChanged(double arg1);
    void on_doubleSpinBox_Param_Crop_End_valueChanged(double arg1);
    void on_spinBox_Param_Crop_Top_valueChanged(int arg1);
    void on_spinBox_Param_Crop_Bottom_valueChanged(int arg1);
    void on_spinBox_Param_Crop_Left_valueChanged(int arg1);
    void on_spinBox_Param_Crop_Right_valueChanged(int arg1);
    void on_spinBox_Param_Blur_Size_valueChanged(int arg1);
    void on_doubleSpinBox_Param_Blur_Sigma_valueChanged(double arg1);

    void on_checkBox_Res_TimeProjSum_Gamma_stateChanged(int arg1);
    void on_doubleSpinBox_Res_TimeProjSum_ColorLow_valueChanged(double arg1);
    void on_doubleSpinBox_Res_TimeProjSum_ColorHigh_valueChanged(double arg1);

    void on_checkBox_Res_TimeProjSum_ColorLow_stateChanged(int arg1);
    void on_checkBox_Res_TimeProjSum_ColorHigh_stateChanged(int arg1);

    void on_spinBox_Param_FrameCountSmooth_valueChanged(int arg1);

    void on_comboBox_Res_Type_currentIndexChanged(int index);

    void on_spinBox_ParamGridVertical_valueChanged(int arg1);

    void on_spinBox_ParamGridHorizontal_valueChanged(int arg1);

    void on_spinBox_Res_MovAv_WindowFrames_valueChanged(int arg1);

    void on_doubleSpinBox_Res_MovAv_WindowTime_valueChanged(double arg1);

    void on_spinBox_Res_MovAv_CurrentFrame_valueChanged(int arg1);

    void on_doubleSpinBox_Res_MovAv_CurrentTime_valueChanged(double arg1);

    void on_horizontalSlider_Res_MovAv_CurrentStart_valueChanged(int value);

    void on_horizontalSlider_Res_MovAv_CurrentEnd_valueChanged(int value);

    void on_comboBox_Res_MovAv_TimeWindow_currentIndexChanged(int index);

    void on_comboBox_Res_MovAv_Background_currentIndexChanged(int index);

    void on_spinBox_ParamGrid_CellStart_valueChanged(int arg1);

    void on_spinBox_ParamGrid_CellEnd_valueChanged(int arg1);

    void on_comboBox_Res_PlotLine_FixRange_T_currentIndexChanged(int index);

    void on_checkBox_Res_PlotLine_FixRange_S_stateChanged(int arg1);

    void on_checkBox_Res_PlotLine_FixRange_A_stateChanged(int arg1);

    void on_spinBox_Res_PlotPoincare_Shift_Frames_valueChanged(int arg1);

    void on_doubleSpinBox_Res_PlotPoincare_Shift_Seconds_valueChanged(double arg1);

    void on_checkBox_Res_VortexCenter_MovingAverage_stateChanged(int arg1);
    void on_checkBox_Res_VortexCenter_Ransac_stateChanged(int arg1);
    void on_checkBox_Res_VortexCenter_kMeans_stateChanged(int arg1);

private:
    Ui::D_MAKRO_CiliaSphereTracker *ui;
    bool ClosingPossible = false;

    //Storage
    D_Storage                           *pStore;

    //Paths
    QFileInfoList                       FIL_Videos;
    QStringList                         QSL_Videos_Names;
    QStringList                         QSL_Videos_Paths;
    QStringList                         QSL_Videos_Suffix;
    QDir                                DIR_SaveMaster;
    QDir                                DIR_SaveStack;
    QDir                                DIR_SaveStackGraphics;
    QDir                                DIR_SaveStackGraphics_Heatmap;
    QDir                                DIR_SaveStackGraphics_Vector;
    QDir                                DIR_SaveStackGraphics_Angle;
    QDir                                DIR_SaveStackGraphics_Speed;
    QDir                                DIR_SaveStackGraphics_Video;
    QDir                                DIR_SaveStackPlot;
    QDir                                DIR_SaveStackPlot_Overview;
    QDir                                DIR_SaveStackPlot_Speed;
    QDir                                DIR_SaveStackPlot_Angle;
    QDir                                DIR_SaveStackOverview;
    QDir                                DIR_SaveSingles;
    QDir                                DIR_SaveCurrent;
    QDir                                DIR_SaveCurrentGraphics;
    QDir                                DIR_SaveCurrentPlot;

    //Images (one Frame only to save Ram)
    D_VideoSlicer                       VS_InputVideo;
    vector<Mat>                         vMA_ProcSteps;
    Mat                                 MA_Result;
    Mat                                 MA_Result_HeatmapLegend;
    Mat                                 MA_TimeProject_Sum;
    Mat                                 MA_TimeProject_Show;
    Mat                                 MA_TimeProject_LastBinary;

    //size conversion
    double                              conv_px2um = 1.00723;
    double                              conv_um2px = 0.992817941;

    //Data of objects
    vector<vector<Point2f>>             vv_FrmObjPositions;
    vector<vector<double>>              vv_FrmObjShifts;
    vector<vector<double>>              vv_FrmObjAngles;

    //Summary of Data (full video)
    vector<double>                      v_VideoStats_Shifts_px_frm;
    vector<double>                      v_VideoStats_Shifts_um_s;
    vector<double>                      v_VideoStats_Angles_Rad;
    vector<double>                      v_VideoStats_Angles_Grad;

    //Grid Sampling
    vector<vector<vector<vector<Point2f>>>>     vvvv_XYFrmObjPositions;
    vector<vector<vector<vector<double>>>>      vvvv_XYFrmObjShifts;
    vector<vector<vector<vector<double>>>>      vvvv_XYFrmObjAngles;
    vector<vector<vector<Point2f>>>             vvv_XYObjPositions;
    vector<vector<vector<double>>>              vvv_XYObjShifts;
    vector<vector<vector<double>>>              vvv_XYObjAngles;

    //Viewers
    D_Viewer                            View_Proc;
    D_Viewer                            View_Results;
    D_Table                             Table_Results;

    //Plot
    QChartView                          *pChartView_Results_Line;
    QChartView                          *pChartView_Results_Poincare;
    QChartView                          *pChartView_Results_Overview_SpeedLine;
    QChartView                          *pChartView_Results_Overview_AngleLine;
    QChartView                          *pChartView_Results_Overview_SpeedPoincare;
    QChartView                          *pChartView_Results_Overview_AnglePoincare;

    //ROI (Time)
    int                                 frame_start = 4 * 24;//1
    int                                 frame_end = (20 - 2) * 24;//1
    int                                 spatial_roi_width = 1250;//px
    int                                 spatial_roi_height = 1000;//px
    //for results
    int                                 frame_start_ana = 4 * 24 + 12;

    //Moving Average Window
    int                                 movav_window_frames = 24;
    int                                 movav_current_start = 0;

    //states
    bool                                state_VideosLoaded      = false;
    bool                                state_VideoSelected     = false;
    bool                                state_RoiTimeSelected   = false;
    bool                                state_RoiSpaceSelected  = false;
    bool                                state_ImgProcUp2date    = false;
    bool                                state_VidProcUp2date    = false;
    bool                                state_VidProcActive     = false;
    void                                state_set_VidProcUp2date(bool is_up2date);
    bool                                state_TimeProjectInit   = false;
    bool                                state_GridSamplingSplit = false;
    bool                                state_StackProcessing   = false;
    bool                                state_StatSummaryCalced = false;


    //error handling
    D_Error_Handler ER;
    void ERR(int err, QString func = "no specified", QString detail = "no specified");

    //CONSTANTS
    enum PROC_STEPS {
        STEP_LOAD,
        STEP_GRAY,
        STEP_CROP,
        STEP_BLUR,
        STEP_BINARY,
        STEP_NUMBER_OF
    };
    const QStringList QSL_ProcSteps = {
        "Load Image",
        "Extract Green Channel",
        "Crop Roi",
        "Blur",
        "Binarize"
    };

    enum BACKGR {
        BACKGR_PROJECTION,
        BACKGR_VIDEO,
        BACKGR_NUMBER_OF
    };
    const QStringList QSL_Background{
        "Time Projection",
        "Input Video"
    };

    enum TIME_WINDOW {
        TIME_WINDOW_FULL_VIDEO,
        TIME_WINDOW_MOVING_AVERAGE,
        TIME_WINDOW_NUMBER_OF
    };
    const QStringList QSL_TimeWindow = {
        "Full Video",
        "Moving Average"
    };

    enum PLOT_TIME {
        PLOT_TIME_VIDEO_LENGTH,
        PLOT_TIME_CUSTOM,
        PLOT_TIME_DEFAULT,
        PLOT_TIME_NUMBER_OF
    };
    const QStringList QSL_PlotTime{
        "Length",
        "Custom",
        "Default"
    };

    enum PLOT_SUMMARY {
        PLOT_SUMMARY_LOW,
        PLOT_SUMMARY_MID,
        PLOT_SUMMARY_HIGH,
        PLOT_SUMMARY_NUMBER_OF
    };

    enum RES_TYPE {
        RES_TYPE_LINE,
        RES_TYPE_POINCARE,
        RES_TYPE_TABLE,
        RES_TYPE_NUMBER_OF
    };

    enum RESULTS_TYPES {
        RES_GRAPHICS_TIME_SUM_PROJ,
        RES_GRAPHICS_VECTORS,
        RES_GRAPHICS_HEATMAP,
        RES_GRAPHICS_VORTEX_CENTER,
        RES_SPEED_STAT_CUSTOM,
        RES_ANGLE_STAT_CUSTOM,
        RES_SPEED_ANALYSIS,
        RES_ANGLE_ANALYSIS,
        RES_OVERVIEW,
        RES_NUMBER_OF
    };
    const QStringList QSL_ResTypes = {
        "Graphics: Time Sum-Projection of Objects",
        "Graphics: Movement Vectors",
        "Graphics: Heatmap",
        "Graphixs: Vortex Center",
        "Custom Statistical Speed Analysis",
        "Custom Statistical Angle Analysis",
        "Main Speed Analysis",
        "Main Angle Analysis",
        "Overview"
    };

};

#endif // D_MAKRO_CILIASPHERETRACKER_H
