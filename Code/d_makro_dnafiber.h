/************************************
 *   added:     29.07.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MAKRO_DNAFIBER_H
#define D_MAKRO_DNAFIBER_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_visdat_proc.h>
#include <d_plot.h>
#include <d_stat.h>
#include <d_viewer.h>
#include <d_storage.h>
#include <d_table.h>

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
class D_MAKRO_DnaFiber;
}

class D_MAKRO_DnaFiber : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_DnaFiber(D_Storage *pStorage, QWidget *parent = 0);
    ~D_MAKRO_DnaFiber();

    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

private slots:
    void Load_Images();

    void Param_SetToDefault();
    bool Param_LoadFromFile();
    void Param_SaveInFile();
    void Param_FromUi();
    void Param_ToUi();

    void Update_Views();
    void Update_View_ImgProc();
    void Update_View_Results();
    void Update_Ui();

    void Update_ImgProc(int step_start = 0);
    void Update_ImgProc_Step(int step);
    void Update_ImgProc_Visualization();

    void UpdateSave_AllSingle();
    void UpdateSave_AllStack();

    void Calc_DiaHist_Single();
    void Calc_DiaHist_Stack();
    void Calc_DiaHist_ClassCount();
    void Calc_Results_All();
    void Calc_Results_InputHist();
    void Calc_Results_DataVector();
    void Calc_Results_EulerNumber();
    void Calc_Results_StatVector();

    void Update_Results();
    void Update_Results_Visualization();
    void Update_Results_InputHist();
    void Update_Results_DiameterHist();
    void Update_Results_DiameterStat();
    void Update_Results_Euler();
    void Update_Results_PixelRatio();

    void Save_Image_Proc();
    void Save_Image_Vis();
    void Save_Plot_DiaHist();
    void Save_Plot_InputHist();
    void Save_Table_DiaStat();
    void Save_Table_Euler();
    void Save_Table_PixelRatio();

    void Save_Image_Proc(QString path);
    void Save_Image_Vis(QString path);
    void Save_Plot_DiaHist(QString path);
    void Save_Plot_InputHist(QString path);
    void Save_Table_DiaStat(QString path);
    void Save_Table_Euler(QString path);
    void Save_Table_PixelRatio(QString path);

    D_VisDat_Slice_2D Slice2D_fromUI();

    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init);
    void Populate_CB();

    void Init_Images();

    void BlockSignals_ImgProc(bool block);
    void BlockSignals_Viewer(bool block);
    void SpacingAdapt_XY_to_Z();
    void SpacingAdapt_Z_to_XY();
    void SpacingAdapt_Viewer();
    void Skelleton_ThresOfVol_Adapt();
    void SizeAdapt();

    void on_doubleSpinBox_Controls_Spacing_XY_valueChanged(double arg1);
    void on_doubleSpinBox_Controls_Spacing_Z_valueChanged(double arg1);

    void on_spinBox_Controls_Median_Size_XY_valueChanged(int arg1);
    void on_spinBox_Controls_Median_Size_Z_valueChanged(int arg1);
    void on_spinBox_Controls_Binary_Thres_valueChanged(int arg1);
    void on_spinBox_Controls_Eilenstein_XY_valueChanged(int arg1);
    void on_spinBox_Controls_Eilenstein_Z_valueChanged(int arg1);
    void on_spinBox_Controls_Skelleton_Thres_valueChanged(int arg1);

    void on_comboBox_ImgProc_View_Plane_currentIndexChanged(int index);
    void on_spinBox_ImgProc_View_X_valueChanged(int arg1);
    void on_spinBox_ImgProc_View_Y_valueChanged(int arg1);
    void on_spinBox_ImgProc_View_Z_valueChanged(int arg1);

    void on_comboBox_ImgProc_Img_currentIndexChanged(int index);
    void on_comboBox_ImgProc_Step_currentIndexChanged(int index);


    void on_action_Update_Image_Processing_triggered();

    void on_action_Update_Results_triggered();


    void on_pushButton_Controls_SaveParam_clicked();

    void on_comboBox_ResAna_SingleStack_currentIndexChanged(int index);

private:
    Ui::D_MAKRO_DnaFiber            *ui;
    bool                            ClosingPossible = false;

    //Spacing Ratio
    double                          Spacing_XY_nm = 2;
    double                          Spacing_Z_nm = 3;
    double                          Spacing_XY_to_Z = Spacing_Z_nm / Spacing_XY_nm;
    double                          Spacing_Z_to_XY = Spacing_XY_nm / Spacing_Z_nm;

    //Paths
    QStringList                     QSL_InputImages;
    QStringList                     QSL_InputImages_Names;
    QFileInfoList                   FIL_InputImages;
    QFileInfoList                   FIL_RoiImages;
    QFileInfoList                   FIL_Parameters;

    //Images
    D_VisDat_Slicing                ProcSlicing = D_VisDat_Slicing(c_SLICE_3D_XYZ);
    vector<D_VisDat_Obj>            vVD_ProcSteps;
    D_VisDat_Obj                    VD_ROI;

    //Data
    vector<double>                  v_Data_Single;
    vector<double>                  v_Data_Stack;
    vector<double>                  v_Stat_Single;
    vector<double>                  v_Stat_Stack;
    vector<size_t>                  v_Volume;
    size_t                          count_pixels_single = 0;
    size_t                          count_pixels_stack = 0;
    size_t                          count_zeros_single = 0;
    size_t                          count_zeros_stack = 0;
    double                          euler_number_single = 0;
    vector<double>                  v_euler_number_stack;
    vector<double>                  v_hist_input_single;
    vector<double>                  v_hist_input_stack;

    vector<vector<double>>          vv_hist_diameters_single;
    vector<vector<double>>          vv_hist_diameters_single_acc;
    vector<double>                  v_hist_diameters_stack_equal;
    vector<double>                  v_hist_diameters_stack_equal_acc;
    vector<double>                  v_hist_diameters_stack_vol;
    vector<double>                  v_hist_diameters_stack_vol_acc;
    const double                    hist_diameters_min = 0.0;
    const double                    hist_diameters_max = 201.0;
    const double                    hist_diameters_step = 1.0;
    size_t                          hist_diameters_class_count;

    //Storage
    D_Storage                       *pStore;

    //Viewer
    Mat                             MA_Proc_Show;
    D_Viewer                        View_Proc;
    int                             ViewPlane = c_PLANE_XY;
    D_VisDat_Obj                    VD_ResultsVis;
    Mat                             MA_ResultsVis;
    D_Viewer                        View_Results;

    //Table
    D_Table                         Table_DiameterStat;
    D_Table                         Table_Euler;
    D_Table                         Table_PixelRatio;

    //Plot
    QChartView                      *pChartView_DiameterHist;
    QChartView                      *pChartView_InputHist;

    //paths
    QDir                            DIR_SaveDefault;
    QDir                            DIR_SaveSingle;
    QDir                            DIR_SaveStack;
    QDir                            DIR_SaveStack_Sub;

    //States
    bool                            state_cur_img_loaded        = false;
    bool                            state_cur_img_processed     = false;
    bool                            state_cur_img_visualization = false;
    bool                            state_cur_res_calced        = false;
    bool                            state_stack_processed       = false;
    bool                            state_stack_res_calced      = false;
    bool                            state_analyse_single        = false;
    bool                            state_analyse_stack         = false;

    //Param vector
    vector<double>                  vParam;

    //Error handler
    D_Error_Handler                 ER;
    void                            ERR(int err, QString func = "not specified", QString detail = "not specified");

    //CONSTANTS

    //Parameters
    enum PARAM {
        PARAM_Spacing_Size_XY,
        PARAM_Spacing_Size_Z,
        PARAM_Blur_Size_XY,
        PARAM_Blur_Size_Z,
        PARAM_Binary_Thresh,
        PARAM_Eilenstein_Size_XY,
        PARAM_Eilenstein_Size_Z,
        PARAM_Skelleton_Thresh,
        PARAM_NUMBER_OF
    };
    const QStringList QSL_PARAM {
        "Spacing_Size_XY",
        "Spacing_Size_Z",
        "Blur_Size_XY",
        "Blur_Size_Z",
        "Binary_Thresh",
        "Eilenstein_Size_XY",
        "Eilenstein_Size_Z",
        "Skelleton_Thresh"
    };

    //Planes
    enum xyzPlanes
    {
        c_PL_XY,
        c_PL_XZ,
        c_PL_YZ,
        c_PL_NUMBER_OF
    };
    const QStringList QSL_XYZ_Planes
    {
        "XY",
        "XZ",
        "YZ"
    };

    //Proc Steps
    enum ProcSteps
    {
        c_ST_LOAD,
        c_ST_INVERT,
        c_ST_BLUR,
        c_ST_ROI_LOAD,
        c_ST_ROI_CROP,
        c_ST_BINARY,
        c_ST_DISTANCE,
        c_ST_EILENSTEIN,
        c_ST_SKELLETON,
        c_ST_DIAMETERS,
        c_ST_NUMBER_OF
    };
    const QStringList QSL_ProcSteps =
    {
        "0 - Load Image",
        "1 - White Foreground",
        "2 - Median Blur",
        "3 - Load Region of Interest",
        "4 - Crop Region of Interest",
        "5 - Binary",
        "6 - Distance Map",
        "7 - Eilenstein Filter",
        "8 - Skelleton",
        "9 - Diameters"
    };

    //Results

    enum ResultStyles
    {
        c_RES_STYLE_VIS,
        c_RES_STYLE_PLOT,
        c_RES_STYLE_NUMBER_OF
    };

    enum ResultsTypes
    {
        c_RES_TYPE_INPUT_HIST,
        c_RES_TYPE_DIAMETER_HIST,
        c_RES_TYPE_DIAMETER_STAT,
        c_RES_TYPE_EULER,
        c_RES_TYPE_PIXEL_RATIO,
        c_RES_TYPE_NUMBER_OF
    };
    const QStringList QSL_ResultsTypes =
    {
        "Input Histogram",
        "Diameter Histogram",
        "Diameter Statistics",
        "Euler Number",
        "Pixel Ratio"
    };

    enum ResultsPool
    {
        c_RES_POOL_SINGLE,
        c_RES_POOL_STACK,
        c_RES_POOL_NUMBER_OF
    };
    const QStringList QSL_ResultsPool =
    {
        "Single Image (3D)",
        "Stack of Images (3D each)"
    };

    enum PoolingWeights
    {
        c_POOL_WEIGHT_EQUAL,
        c_POOL_WEIGHT_VOLUME,
        c_POOL_WEIGHT_NUMBER_OF
    };
    const QStringList QSL_PoolingWeights = {
        "Pooling weight equal",
        "Pooling weight by analysed volume"
    };

    enum PixelRatio
    {
        c_RES_PX_RATIO_ALL,
        c_RES_PX_RATIO_FG,
        c_RES_PX_RATIO_FG_ALL,
        c_RES_PX_RATIO_FG_BG,
        c_RES_PX_RATIO_BG,
        c_RES_PX_RATIO_BG_ALL,
        c_RES_PX_RATIO_BG_FG,
        c_RES_PX_RATIO_NUMBER_OF
    };
    QStringList QSL_PixelRatio =
    {
        "Overall Pixels",
        "Foreground Pixels",
        "FG/All Pixel Ratio",
        "FG/BG Pixel Ratio",
        "Background Pixels",
        "BG/All Pixel Ratio",
        "BG/FG Pixel Ratio"
    };

    const double euler_average_edges_per_knot = 4;
    enum EulerStat
    {
        c_RES_EULER_NUM,
        c_RES_EULER_NUM_PER_VX,
        c_RES_EULER_KN4_PER_LN_VX,
        c_RES_EULER_KN4,
        c_RES_EULER_NUMBER_OF
    };
    QStringList QSL_Euler =
    {
        "Euler Number",
        "Euler Number per Voxel",
        "Connections per Voxel (if 2 Fibers per Connection)",
        "Connections (if 2 Fibers per Connection)"
    };
};

#endif // D_MAKRO_DNAFIBER_H
