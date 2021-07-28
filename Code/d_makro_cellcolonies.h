/************************************
 *   added:     20.11.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MAKRO_CELLCOLONIES_H
#define D_MAKRO_CELLCOLONIES_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_img_proc.h>
#include <d_plot.h>
#include <d_stat.h>
#include <d_viewer.h>
#include <d_storage.h>

//Qt
#include <QMainWindow>
#include <QFileDialog>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QDateTime>
#include <QComboBox>

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
class D_MAKRO_CellColonies;
}

class D_MAKRO_CellColonies : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_CellColonies(D_Storage *pStorage, QWidget *parent = 0);
    ~D_MAKRO_CellColonies();

    void closeEvent(QCloseEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

private slots:

    //Load
    void Load_Images();

    //Save
    void Save_Stack();
    void Save_Analysis_Dialog();
    void Save_Analysis();
    void Save_Processing_Chain();
    void Save_Image(D_Viewer *viewer, QString name_default);
    void Save_Image_Cells();
    void Save_Image_Results_Color();
    void Save_Image_Results_Surrival();
    void Save_Image_Results_Segmentation();
    void Save_Image_Results_Attribute();
    void Save_Plot(QChartView *pCV_Save, QString name_default);
    void Save_Plot_Colony();
    void Save_Plot_Image();
    void Save_Plot_Surrival();
    void Save_Parameters();
    void Save_Results();
    void Save_Raw_Data();

    //View
    void Update_Views();
    void Update_View_Cells();
    void Update_View_Results();
    void Update_View_Surrival();
    void Update_View_Segmentation();
    void Update_View_Attribute();
    void Update_Ui();

    //Image
    void Update_Images();
    void Update_Image_Cells();
    void Update_Image_Results();
    void Update_Image_Surrival();
    void Update_Image_Segmentation();
    void Update_Image_Attribute();

    //Results
    void Update_Results();

    //Settings
    void Settings_Reset();

    //Image Processing
    void Update_ImgProc();
    void Update_ImgProc_Cells(int start_step);
    void Update_ImgProc_Results(int start_step);
    void Update_Step_Cells(int step);
    void Update_Step_Results(int step);

    //Calculation
    void Calc_All();
    void Calc_Colony_Values_Split();
    void Calc_Colony_Stats();
    void Calc_Colony_Attributes();
    void Calc_Image_Stats();
    void Calc_Colony_Survival();

    //Plot
    void Plot_Histogram_Colonies();
    void Plot_Stat_Compare();
    void Plot_MM_Colonies();
    void Plot_CSK_Colonies();
    void Plot_Quantiles_Colonies();
    void Plot_Histogram_Image();
    void Plot_Attribute_Compare();
    void Plot_Colony_Surrival();
    void Plot_Radial_Transmission_Colony();

    //Populate UI
    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init);
    void Populate_CB_Stat();
    void Populate_CB_Attribute();
    void Populate_CB_Typ();

    //Trigger Image Proc
    void on_doubleSpinBox_ProcCon_ROI_X1_valueChanged(double arg1);
    void on_doubleSpinBox_ProcCon_ROI_Y1_valueChanged(double arg1);
    void on_doubleSpinBox_ProcCon_ROI_X2_valueChanged(double arg1);
    void on_doubleSpinBox_ProcCon_ROI_Y2_valueChanged(double arg1);
    void on_spinBox_ProcCon_ColGrab_H_Min_valueChanged(int arg1);
    void on_spinBox_ProcCon_ColGrab_S_Min_valueChanged(int arg1);
    void on_spinBox_ProcCon_ColGrab_V_Min_valueChanged(int arg1);
    void on_spinBox_ProcCon_ColGrab_H_Max_valueChanged(int arg1);
    void on_spinBox_ProcCon_ColGrab_S_Max_valueChanged(int arg1);
    void on_spinBox_ProcCon_ColGrab_V_Max_valueChanged(int arg1);
    void on_spinBox_ProcCon_CellCol_Black_Noise_valueChanged(int arg1);
    void on_spinBox_ProcCon_CellCol_White_Noise_valueChanged(int arg1);
    void on_spinBox_ProcCon_Seed_Blur_Size_valueChanged(int arg1);
    void on_doubleSpinBox_ProcCon_Seed_Blur_Sigma_valueChanged(double arg1);
    void on_spinBox_ProcCon_Thres_Size_valueChanged(int arg1);
    void on_doubleSpinBox_ProcCon_Thres_Offset_valueChanged(double arg1);
    void on_spinBox_ProcCon_Seed_Open_Size_valueChanged(int arg1);
    void on_checkBox_ProcCon_Watershed_Border_stateChanged(int arg1);
    void on_checkBox_ProcCon_Watershed_nSeed_stateChanged(int arg1);
    void on_spinBox_ProcCon_Ref_Blur_Size_valueChanged(int arg1);
    void on_doubleSpinBox_ProcCon_Ref_Blur_Sigma_valueChanged(double arg1);

    //Stack
    void on_action_Last_Image_triggered();
    void on_action_Next_Image_triggered();

    //Update Results
    void on_comboBox_ProcView_Image_currentIndexChanged(const QString &arg1);

    //Trigger Surrival Calculation


    void on_doubleSpinBox_Extract_Asphere_Thres_valueChanged(double arg1);

    void on_doubleSpinBox_Separtate_Asphere_Thres_valueChanged(double arg1);

    void on_doubleSpinBox_Measure_Base_valueChanged(double arg1);

    void on_doubleSpinBox_Measure_Factor_valueChanged(double arg1);

    void on_doubleSpinBox_Sur_CellCount_valueChanged(double arg1);

private:
    Ui::D_MAKRO_CellColonies *ui;

    bool                    ClosingPossible = false;

    //Store
    D_Storage       *pStore;

    //Paths
    QDir            DIR_Input_Dir;
    QFileInfoList   FIL_Input_Images;
    QFileInfo       FI_Reference_Image;
    QString         QS_BaseName_Current = "";

    //Images
    Mat             MA_Reference;
    vector<Mat>     vMA_Cells;
    vector<Mat>     vMA_Results;
    Mat             MA_Result_Color;
    Mat             MA_Result_Surrival;
    Mat             MA_Result_Segmentation;
    Mat             MA_Result_Attribute;
    bool            Loaded_FileInfos = false;

    //Stats
    vector<vector<vector<double>>>  vvvd_TypColVal;
    vector<vector<vector<double>>>  vvvd_TypColSta;
    vector<vector<double>>          vvd_AttCol_new;
    vector<vector<double>>          vvd_AttSta_new;
    vector<int>                     vi_ColSur_new;
    bool                            Calced_TypColVal = false;
    bool                            Calced_TypColSta = false;
    bool                            Calced_AttCol_new = false;
    bool                            Calced_AttSta_new = false;
    bool                            Calced_ColSur_new = false;



    //Plot
    QChartView  *pChartView_Colony;
    QChartView  *pChartView_Image;
    QChartView  *pChartView_Surrival;
    QChart      *pChart_Colony;
    QChart      *pChart_Image;
    QChart      *pChart_Surrival;
    void        Init_Plot();

    //View
    D_Viewer    Viewer_Cells;
    D_Viewer    Viewer_Results;
    D_Viewer    Viewer_Surrival;
    D_Viewer    Viewer_Segmentation;
    D_Viewer    Viewer_Attribute;

    //Statusbar
    QLabel      *L_SB_ValAtPos;

    //Surrival
    int         count_detected;
    int         count_surrival;
    int         count_dead;
    double      prz_surrival;
    double      prz_dead;

    //Save
    bool        stream_active = false;
    bool        stack_proc_active = false;
    QDir        DIR_Stream;
    QDir        DIR_Stream_Processing;
    QDir        DIR_Stream_Stack;
    QDir        DIR_Stream_Stack_Labeling;
    QDir        DIR_Stream_Stack_Surrival;
    QDir        DIR_Stream_Stack_Attribute;
    ofstream    OS_Parameters;
    ofstream    OS_Results;
    ofstream    OS_Raw_Data;
    ofstream    OS_Stack;
    ofstream    OS_Stack_Summary;


    //CONSTANTS

    //Cells
    static unsigned const int
    c_ST_REFERENCE_LOAD     = 0,
    c_ST_REFERENCE_CROP     = 1,
    c_ST_REFERENCE_BLUR     = 2,
    c_ST_INPUT_LOAD         = 3,
    c_ST_INPUT_CROP         = 4,
    c_ST_INPUT_ANTI_SHADE   = 5,
    c_ST_CELLS_GRAB_COLOR   = 6,
    c_ST_CELLS_BINARY       = 7,
    c_ST_CELLS_NOISE_BLACK  = 8,
    c_ST_CELLS_NOISE_WHITE  = 9,
    c_ST_SEED_HSV           = 10,
    c_ST_SEED_SATURATION    = 11,
    c_ST_SEED_BLUR          = 12,
    c_ST_SEED_THRESH        = 13,
    c_ST_SEED_OPEN          = 14,
    c_ST_SEED_SPHERICITY_INV= 15,
    c_ST_SEED_ASPH_EXTRACT  = 16,
    c_ST_SEED_ASPH_DISTANCE = 17,
    c_ST_SEED_ASPH_SEPARATE = 18,
    c_ST_SEED_SPHERE_EXTRACT= 19,
    c_ST_SEED_ALL_SEEDS     = 20,
    c_ST_SEGM_WATERSHED     = 21,
    c_ST_SEGM_BINARY        = 22,
    c_ST_MEASURE_DIFF       = 23,
    c_ST_MEASURE_HSV        = 24,
    c_ST_MEASURE_VALUE      = 25,
    c_ST_MEASURE_VALUE_MASK = 26,
    c_ST_MEASURE_ABSORPTION = 27,
    c_ST_MEASURE_TRANSMISSON= 28,
    c_ST_MEASURE_CELL_COUNT = 29,
    c_CELLS_STEPS           = 30;

    //Results
    static unsigned const int
    c_ST_C_RGB              = 0,
    c_ST_C_RGB_ANTISHADE    = 1,
    c_ST_C_RGB_DIFFERENCE   = 2,
    c_ST_C_HSV_INPUT        = 3,
    c_ST_C_HSV_DIFFERENCE   = 4,
    c_ST_G_INPUT_SAT        = 5,
    c_ST_G_DIFF_VAL         = 6,
    c_ST_B_EDGES            = 7,
    c_ST_B_NUMBERS          = 8,
    c_ST_B_EDGES_NUMBERS    = 9,
    c_ST_B_ROI_OUT          = 10,
    c_ST_B_ROI_IN           = 11,
    c_RESULTS_STEPS         = 12;

    static unsigned const int
    c_ATT_SIZE_AREA             = 0,
    c_ATT_SIZE_RADIUS           = 1,
    c_ATT_SIZE_DIAMETER         = 2,
    c_ATT_ABSORB_MEAN           = 3,
    c_ATT_ABSORB_MEDIAN         = 4,
    c_ATT_ABSORB_SUM            = 5,
    c_ATT_TRANS_MEAN            = 6,
    c_ATT_TRANS_MEDIAN          = 7,
    c_ATT_TRANS_SUM             = 8,
    c_ATT_TRANS_RADIAL_MEAN     = 9,
    c_ATT_TRANS_RADIAL_MEDIAN   = 10,
    c_ATT_TRANS_RADIAL_SUM      = 11,
    c_ATT_CELL_DENSITY_MEAN     = 12,
    c_ATT_CELL_DENSITY_MEDIAN   = 13,
    c_ATT_CELL_DENSITY_SUM      = 14,
    c_ATT_COUNT                 = 15;
    QStringList QSL_Attrib      = {
        "Size_Area",                    "Size_Radius",                  "Size_Diameter",
        "Absorption_Mean",              "Absorption_Median",            "Absorption_Sum",
        "Transmission_Mean",            "Transmission_Median",          "Transmission_Sum",
        "Transmission_Radial_Mean",     "Transmission_Radial_Median",   "Transmission_Radial_Sum",
        "Aprox_Cell_Density_pPx_Mean",  "Aprox_Cell_Density_pPx_Median","Aprox_Cell_Count"
    };

    //Calculation
    static unsigned const int
    c_TYP_ABS               = 0,
    c_TYP_TRANS             = 1,
    c_TYP_TRANS_RADIAL      = 2,
    c_TYP_CELL_DENSITY      = 3,
    c_TYP_NUMBER_OF         = 4;
    QStringList QSL_Types   = {"Absorption", "Transmission", "Transmission_Radial", "Aprox_Cell_Density_per_Pixel"};

    //error handling
    D_Error_Handler ER;
    void ERR(int err, QString func = "not specified", QString detail = "not specified");



};

#endif // D_MAKRO_CELLCOLONIES_H
