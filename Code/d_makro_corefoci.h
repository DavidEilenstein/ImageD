/************************************
 *   added:     26.09.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MAKRO_COREFOCI_H
#define D_MAKRO_COREFOCI_H

//own
#include <d_enum.h>
#include <scenemousetrack.h>
#include <d_img_proc.h>
#include <d_plot.h>
#include <d_storage.h>
#include <d_viewer.h>
#include <d_error_handler.h>
#include <d_table.h>
#include <d_math.h>
#include <d_value_distribution_list.h>

//general
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//Qt
#include <QMainWindow>
#include <QImage>
#include <QPixmap>
#include <QGraphicsScene>
#include <QFileInfo>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QBuffer>
#include <QSpacerItem>
#include <QElapsedTimer>
#include <QComboBox>
#include <QDateTime>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

namespace Ui {
class D_MAKRO_CoreFoci;
}

class D_MAKRO_CoreFoci : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_CoreFoci(D_Storage *pStorage, QWidget *parent = 0);
    ~D_MAKRO_CoreFoci();

    void resizeEvent(QResizeEvent* event);
    void closeEvent(QCloseEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

    Mat             *get_pMA_Substep(unsigned int vec_number, unsigned int pos);
    unsigned int    get_StepCount_Cores()   {return c_ST_C_NUMBER_OF;}
    unsigned int    get_StepCount_Plasma()  {return c_ST_P_NUMBER_OF;}
    unsigned int    get_StepCount_Foci()    {return c_ST_F_NUMBER_OF;}
    unsigned int    get_StepCount_Results() {return c_ST_R_NUMBER_OF;}

public slots:

    void Update_ImgProc_All();

private slots:

    void Update_Views();
    void Update_View_Cores();
    void Update_View_Plasma();
    void Update_View_Foci();
    void Update_View_Results();
    void Update_Ui();

    void Update_ImgProc_Cores(unsigned int start_step);
    void Update_ImgProc_Plasma(unsigned int start_step);
    void Update_ImgProc_Foci(unsigned int start_step);
    void Update_ImgProc_Results(unsigned int start_step);
    void Update_Step_Cores(unsigned int step);
    void Update_Step_Plasma(unsigned int step);
    void Update_Step_Foci(unsigned int step);
    void Update_Step_Results(unsigned int step);
    void Update_Combi_Results();
    void Update_Combi_Results_Preset(int preset);

    void Update_Results();

    void Plot_Cells_Attribute();
    void Plot_Cells_Attribute_Hist();
    void Plot_Cells_Attribute_Scatter();
    void Plot_Image_Attribute();
    void Plot_Image_Attribute_Hist();
    void Plot_Image_Attribute_Scatter();

    void Table_Cells_AttCel();
    void Table_Cells_AttSta();
    void Table_Image_AttImg();
    void Table_Image_AttSta();

    void Table_Summary();

    void Parameters_Init();
    void Parameters_ActivatePreset();
    void Parameters_ParamSetToUi(vector<double> vParams);

    void Calc_All();
    void Calc_Cells_Attrib();
    void Calc_Cells_Stats();

    void Load_Images();
    void Next_Image();
    void Clear_Images();

    bool LoadParams_CurrentDir();
    bool LoadParams();
    bool LoadParams(QString QS_FileName);
    void SaveParams();

    void Stack_Attributes_AskUpdate();
    void Stack_Attributes_Process();
    void Stack_Attributes_Init();
    void Stack_Attributes_Calc();
    void Stack_Attributes_Calc_Stats();
    void Stack_Attributes_Stream_Init();
    void Stack_Attributes_Stream_Parameters();

    void Stack_Attributes_Stream_Cells();
    void Stack_Attributes_Stream_Cells_Images();
    void Stack_Attributes_Stream_Cells_Tables();
    void Stack_Attributes_Stream_Cells_Plots();

    void Stack_Attributes_Stream_Images();
    void Stack_Attributes_Stream_Images_Images();
    void Stack_Attributes_Stream_Images_Tables();
    void Stack_Attributes_Stream_Images_Plots();

    void Save_Image_Cores();
    void Save_Image_Plasma();
    void Save_Image_Foci();
    void Save_Image_Results();
    void Save_Plot_Cells();
    void Save_Plot_Image();
    void Save_Plot(QChartView *pCV, QString path);

    void Populate_CB();
    void Populate_CB(QComboBox *CB, QStringList QSL);

    void View_BlockSignals(bool block);
    void Proc_BlocSignals(bool block);

    void ERR(int err, QString func = "not specified", QString detail = "not specified");

    void on_spinBox_SetFoci_02_Size_valueChanged(int arg1);
    void on_doubleSpinBox_SetFoci_02_Sigma_valueChanged(double arg1);
    void on_spinBox_SetFoci_03_Size_valueChanged(int arg1);
    void on_doubleSpinBox_SetFoci_03_Offset_valueChanged(double arg1);
    void on_spinBox_SetFoci_04_Size_valueChanged(int arg1);
    void on_spinBox_SetFoci_05_Size_valueChanged(int arg1);
    void on_spinBox_SetFoci_06_Size_Min_valueChanged(int arg1);
    void on_spinBox_SetFoci_06_Size_Max_valueChanged(int arg1);

    void on_spinBox_SetCore_02_Gauss_Size_valueChanged(int arg1);
    void on_doubleSpinBox_SetCore_02_Gauss_Sigma_valueChanged(double arg1);
    void on_spinBox_SetCore_04_Thres_Size_valueChanged(int arg1);
    void on_doubleSpinBox_SetCore_04_Thres_Offset_valueChanged(double arg1);
    void on_spinBox_SetCore_05_Fill_Area_valueChanged(int arg1);
    void on_spinBox_SetCore_09_Eilenstein_Size_valueChanged(int arg1);
    void on_doubleSpinBox_Set_Core_09_Eilenstein_Offset_valueChanged(double arg1);
    void on_spinBox_SetCore_11_Thresh_Thres_valueChanged(int arg1);
    void on_spinBox_SetCore_12_Open_Area_valueChanged(int arg1);
    void on_spinBox_SetCore_13_Dilation_Size_valueChanged(int arg1);

    void on_doubleSpinBox_SetCyto_Gauss_Sigma_valueChanged(double arg1);
    void on_spinBox_SetCyto_Gauss_Size_valueChanged(int arg1);
    void on_spinBox_SetCyto_Closing_Size_valueChanged(int arg1);
    void on_spinBox_SetCyto_Dilation_Size_valueChanged(int arg1);

    void on_pushButton_ResCol_Preset_ContrastAll_clicked();
    void on_pushButton_ResCol_Preset_NormalAll_clicked();
    void on_pushButton_ResCol_Preset_NucSegmentation_clicked();
    void on_pushButton_ResCol_Preset_Regions_clicked();
    void on_pushButton_ResCol_Preset_Foci_clicked();
    void on_pushButton_ResCol_Preset_Plasma_clicked();

    void on_spinBox_Results_SpreadMax_valueChanged(int arg1);

    void on_comboBox_FileName_currentIndexChanged(int index);


    void on_spinBox_SetCyto_Thresh_Size_valueChanged(int arg1);
    void on_doubleSpinBox_SetCyto_Thresh_Offset_valueChanged(double arg1);


    void on_checkBox_SetFoci_13_ExcludeBordered_clicked();
    void on_checkBox_SetCore_13_ExcludeBordered_clicked();

    void on_pushButton_PresetActivate_clicked();

    void on_spinBox_SetCore_14_AreaDistMin_valueChanged(int arg1);

    void on_spinBox_SetCore_14_AreaDistMax_valueChanged(int arg1);

    void on_spinBox_SetCore_14_AreaMaxOfSmall_valueChanged(int arg1);

    void on_spinBox_SetCore_14_AreaMinOfBig_valueChanged(int arg1);

    void on_pushButton_ParamsLoad_clicked();
    void on_pushButton_ParamsSave_clicked();

private:
    Ui::D_MAKRO_CoreFoci *ui;

    bool                    ClosingPossible = false;

    //Data Storage
    D_Storage       *pStore;
    vector<Mat>     vMA_Cores;
    vector<Mat>     vMA_Plasma;
    vector<Mat>     vMA_Foci;
    vector<Mat>     vMA_Results;
    Mat             MA_Result = Mat();
    unsigned int    pos_dest;

    //image
    bool                            calced_AttCel_cel = false;
    vector<vector<double>>          vvd_AttCel_cel;
    bool                            calced_AttSta_cel = false;
    vector<vector<double>>          vvd_AttSta_cel;

    //stack
    bool                            stack_processing = false;
    int                             stack_img_curent = 0;
    bool                            stack_processed = false;
    bool                            calced_AttCel_cel_stack = false;
    vector<vector<double>>          vvd_AttCel_cel_stack;
    bool                            calced_AttSta_cel_stack = false;
    vector<vector<double>>          vvd_AttSta_cel_stack;


    //pathes of images
    QStringList     QSL_Input_Images;
    QStringList     QSL_BaseNames;
    QStringList     QSL_FileNames;
    QFileInfoList   FIL_Input_Images;
    QString         QS_BaseName_Current;
    QString         QS_FileName_Current;

    //Display images
    D_Viewer        V_Nuclei;
    D_Viewer        V_Plasma;
    D_Viewer        V_Foci;
    D_Viewer        V_Results;

    //Display plot
    QChartView      *ChartView_Cells;
    QChart          *Chart_Cells;
    QChartView      *ChartView_Image;
    QChart          *Chart_Image;

    //Tables
    D_Table         Table_CellStat;
    D_Table         Table_ImageStat;
    D_Table         Table_Summary_Single;
    D_Table         Table_Summary_Quotients;

    //stream to output data
    QDir            DIR_Stream_Main;
    QDir            DIR_Stream_Stack;
    QDir            DIR_Stream_Stack_Images;
    QDir            DIR_Stream_Stack_Tables;
    QDir            DIR_Stream_Stack_Plots;
    QDir            DIR_Stream_Images;
    QDir            DIR_Stream_Images_Sub;
    QDir            DIR_Stream_Other;
    bool            B_Stream_Out = false;
    vector<int>     v_StreamImage_Images;
    vector<int>     v_StreamImage_PlotAttrib;
    vector<int>     v_StreamStack_Images;
    vector<int>     v_StreamStack_PlotAttrib;
    bool            dont_stream = false;

    //statusbar
    QLabel          *L_SB_PixVal;

    //ParameterPresets
    vector<vector<double>> vvd_ParameterPresets_SetPar;

    //CONSTANTS

    D_Error_Handler ER;

    enum c_Presets
    {
        c_PRESET_NIKON,
        c_PRESET_LEICA,
        c_PRESET_NUMBER_OF
    };
    QStringList QSL_PresetNames =
    {
        "Nikon",
        "Leica"
    };

    enum c_Parameters
    {
        c_PAR_NUC_BLUR_SIZE,
        c_PAR_NUC_BLUR_SIGMA,
        c_PAR_NUC_THRES_SIZE,
        c_PAR_NUC_THRES_OFFSET,
        c_PAR_NUC_AREA_FILL,
        c_PAR_NUC_EILENSTEIN_SIZE,
        c_PAR_NUC_EILENSTEIN_OFFSET,
        c_PAR_NUC_LOCMAX_THRES,
        c_PAR_NUC_REMOVE_SMALL,
        c_PAR_NUC_CONNECT_NEAR,
        c_PAR_NUC_EXCULDE_BORDER,
        c_PAR_NUC_AREA_DIST_MIN,
        c_PAR_NUC_AREA_DIST_MAX,
        c_PAR_NUC_AREA_MAX_SMALL,
        c_PAR_NUC_AREA_MIN_BIG,
        c_PAR_CYT_BLUR_SIZE,
        c_PAR_CYT_BLUR_SIGMA,
        c_PAR_CTT_THRES_SIZE,
        c_PAR_CYT_THRES_SIGMA,
        c_PAR_CYT_CLOSE_HOLES,
        c_PAR_CYT_MARGIN,
        c_PAR_FOCI_BLUR_SIZE,
        c_PAR_FOCI_BLUR_SIGMA,
        c_PAR_FOCI_THRES_SIZE,
        C_PAR_FOCI_THRES_SIGMA,
        C_PAR_FOCI_MARGIN,
        C_PAR_FOCI_CONNECT_NEAR,
        C_PAR_FOCI_AREA_MIN,
        C_PAR_FOCI_AREA_MAX,
        C_PAR_FOCI_EXCLUDE_BORDER,
        C_PAR_FOCI_RES_MAX_EXPECTED,
        C_PAR_CALC_PX_TO_UM,
        c_PAR_NUMBER_OF
    };
    const QStringList QSL_ParameterNames = {
        "Nuclei, blur size",
        "Nuclei, blur sigma",
        "Nuclei, local adaptive threshold filter size",
        "Nuclei, local adaptive threshold offset",
        "Nuclei, fill holes",
        "Nuclei, local adaptive contrast equilibration (eilenstein filter) size",
        "Nuclei, local adaptive contrast equilibration (eilenstein filter) offset",
        "Nuclei, threshold for local maxima",
        "Nuclei, remove small seeds",
        "Nuclei, connect near seeds",
        "Nuclei, eclude border connected",
        "Nuclei, merge by area context - dist min",
        "Nuclei, merge by area context - dist max",
        "Nuclei, merge by area context - max area of small",
        "Nuclei, merge by area context - min area of big",
        "Cytoplasma, blur size",
        "Cytoplasma, blur sigma",
        "Cytoplasma, local adaptive threshold filter size",
        "Cytoplasma, local adaptive threshold offset",
        "Cytoplasma, fill holes",
        "Cytoplasma, add margin",
        "Foci, blur size",
        "Foci, blur sigma",
        "Foci, local adaptive threshold filter size",
        "Foci, local adaptive threshold offset",
        "Foci, add margin to nuclei",
        "Foci, connect near foci",
        "Foci, area selection min",
        "Foci, area selection max",
        "Foci, exclude border connected",
        "Results, visualization max value expected",
        "Calc, px area to um area factor"
    };

    //Resulttypes
    enum c_ResultTypes {
        c_RES_IMAGE             = 0,
        c_RES_PLOT_CELLS        = 1,
        c_RES_TABLE_CELLS       = 2,
        c_RES_PLOT_IMAGE        = 3,
        c_RES_TABLE_IMAGE       = 4,
        c_RES_NUMBER_OF         = 5
    };

    //TableTypes
    enum c_TableTypes {
        c_TAB_BASIC             = 0,
        c_TAB_STAT              = 1,
        c_TAB_NUMBER_OF         = 2
    };
    QStringList QSL_TabeleTypes =
    {
        "Basic Data",
        "Statistics"
    };

    //Color Combi Results
    enum c_ColorCombiResults {
        c_RES_COLOR_NORMAL      = 0,
        c_RES_COLOR_CONTRAST    = 1,
        c_RES_COLOR_NUCLEI      = 2,
        c_RES_COLOR_PLASMA      = 3,
        c_RES_COLOR_FOCI        = 4,
        c_RES_COLOR_REGIONS     = 5,
        c_RES_COLOR_NUMBER_OF   = 6
    };
    QStringList QSL_ResColor_Presets =
    {
        "Normal",
        "Contrast",
        "Nuclei",
        "Plasma",
        "Foci",
        "Regions"
    };


    //Plot Cell
    enum c_PlotCell {
        c_RESPLOCEL_ATT         = 0,
        c_RESPLOCEL_ATT_HIST    = 1,
        c_RESPLOCEL_ATT_SCATTER = 2
    };
    QStringList QSL_ResPloCel =
    {
        "Attributes",
        "Attributes Histogram",
        "Attributes Scatter"
    };

    //Res plot image
    enum c_ResPlotImage {
        c_RESPLOIMG_ATT         = 0,
        c_RESPLOIMG_ATT_HIST    = 1,
        c_RESPLOIMG_ATT_SCATTER = 2
    };
    QStringList QSL_ResPloImg =
    {
        "Attributes",
        "Attributes Histogram",
        "Attributes Scatter"
    };

    //Attributes

    //Cells
    enum c_AttCell {
        c_ATT_CELL_NUCLEUS_AREA_PX,
        c_ATT_CELL_NUCLEUS_AREA_UM,
        c_ATT_CELL_CYTO_AREA_PX,
        c_ATT_CELL_CYTO_AREA_UM,
        c_ATT_CELL_FOCI_COUNT,
        c_ATT_CELL_FOCI_AREA_PX,
        c_ATT_CELL_FOCI_AREA_UM,
        c_ATT_CELL_NUCLEUS_MEAN_I,
        c_ATT_CELL_NUMBER_OF
    };
    QStringList QSL_AttCel =
    {
        "Area of Nucleus px x px",
        "Area of Nucleus um x um",
        "Area of Cytoplasma px x px",
        "Area of Cytoplasma um x um",
        "Number of Foci",
        "Area of Foci px x px",
        "Area of Foci um x um",
        "Mean Nucleus Intensity"
        //"Sum Nucleus Intensity"
    };

/*
    //Images
    static const unsigned int
    c_ATT_IMG_NUCLEI_COUNT_SUM  = 0,
    c_ATT_IMG_NUCLEI_AREA_SUM   = 1,
    c_ATT_IMG_NUCLEI_AREA_MEAN  = 2,
    c_ATT_IMG_CYTO_AREA_SUM     = 3,
    c_ATT_IMG_CYTO_AREA_MEAN    = 4,
    c_ATT_IMG_CYTOAREApNUCAREA  = 5,
    c_ATT_IMG_FOCI_COUNT_SUM    = 6,
    //c_ATT_IMG_FOCI_COUNT_MEAN   = 7,
    c_ATT_IMG_FOCICOUNTpNUCCOUNT= 7,
    c_ATT_IMG_FOCICOUNTpNUCAREA = 8,
    c_ATT_IMG_FOCICOUNTpCYTOAREA= 9,
    c_ATT_IMG_FOCI_AREA_SUM     = 10,
    c_ATT_IMG_FOCI_AREA_MEAN    = 11,
    c_ATT_IMG_NUMBER_OF         = 12;

    QStringList QSL_AttImg =
    {
        "Nuclei Number Sum",
        "Nuclei Area Sum",
        "Nuclei Area Mean",
        "Cytoplasma Area Sum",
        "Cytoplasma Area Mean",
        "Cytoplasma Area per Nuclei Area",
        "Foci Number Sum",
        //"Foci Number Mean",
        "Foci Number per Nuclei Number",
        "Foci Number per Nuclei Area",
        "Foci Number per Cytoplasma Area",
        "Foci Area Sum",
        "Foci Area Mean"
    };
*/

    //Nuclei Steps
    enum c_StepNuclei {
        c_ST_C_LOAD,
        c_ST_C_INPUT_CONV_8BIT,
        c_ST_C_INPUT_CONTRAST,
        c_ST_C_INPUT_BLUR,
        c_ST_C_BIN_THRES,
        c_ST_C_BIN_AREA,
        c_ST_C_BIN_INV,
        c_ST_C_DIST_TRANSFORM,
        c_ST_C_RANK_EILENSTEIN,
        c_ST_C_RANK_CONV_8BIT,
        c_ST_C_LMAX_BIN,
        c_ST_C_LMAX_OPEN,
        c_ST_C_LMAX_DILATION,
        c_ST_C_SEGM_WATERSHADE,
        c_ST_C_SEGM_BINARY,
        c_ST_C_SEGM_AREA_CONNECT,
        c_ST_C_SEGM_LABELS_FINAL,
        c_ST_C_SEGM_EDGES,
        c_ST_C_NUMBER_OF
    };
    const QStringList QSL_StepNuclei =
    {
        "00 Load Image",
        "01 Convert to 8bit",
        "02 Contrast Improvement",
        "03 Blur",
        "04 Local adaptive Threshold",
        "05 Fill Holes selected by Area",
        "06 Invert",
        "07 Distance Transformation",
        "08 Local Rank Eilenstein Filter",
        "09 Convert to 8bit",
        "10 Binarize to get initial Seeds",
        "11 Remove Small Seeds",
        "12 Connect Near Seeds",
        "13 Watershed Segmentation",
        "14 Binary Nuclei",
        "15 Connect small Nuclei to nearby big Nuclei",
        "16 Final Nuclei Segmentation",
        "17 Edges of segmented Nuclei"
    };

    //Plasma Steps
    enum c_StepPlasma {
        c_ST_P_LOAD,
        c_ST_P_INPUT_CONV_8BIT,
        c_ST_P_INPUT_CONTRAST,
        c_ST_P_INPUT_BLUR,
        c_ST_P_BIN_THRES,
        c_ST_P_MORPH_CLOSE,
        c_ST_P_MORPH_DILATE,
        c_ST_P_REG_PLASMA,
        c_ST_P_REG_PLASMA_EDGES,
        c_ST_P_NUMBER_OF
    };
    const QStringList QSL_StepPlasma =
    {
        "00 Load Image",
        "01 Convert to 8bit",
        "02 Contrast Improvement",
        "03 Blur",
        "04 Local adaptive Threshold",
        "05 Closing Holes",
        "06 Dilation",
        "07 Cytoplasma Regions",
        "08 Edges of Cytoplasma Regions"
    };

    //Foci Steps
    enum c_StepFoci {
        c_ST_F_LOAD,
        c_ST_F_INPUT_CONV_8BIT,
        c_ST_F_INPUT_CONTRAST,
        c_ST_F_INPUT_BLUR,
        c_ST_F_BIN_THRES,
        c_ST_F_ROI_NUC_MARGIN,
        c_ST_F_ROI,
        c_ST_F_ROI_EDEGS,
        c_ST_F_OUT_CORES,
        c_ST_F_OUT_CORES_CLOSE,
        c_ST_F_OUT_CORES_AREA,
        c_ST_F_CENTROID,
        c_ST_F_REGIONS_NUCLEI,
        c_ST_F_REGIONS_SEEDS,
        c_ST_F_REGIONS_ROI2LABEL,
        c_ST_F_REGIONS_CELLS_APPROX,
        c_ST_F_REGIONS_8BIT,
        c_ST_F_CENTROID_CORES,
        c_ST_F_NUMBER_OF
    };
    const QStringList QSL_StepFoci =
    {
        "00 Load Image",
        "01 Convert to 8bit",
        "02 Contrast Improvement",
        "03 Blur",
        "04 Local adaptive Threshold",
        "05 Nuclei with additional Margin",
        "06 Cytoplasmatic Region but without Nuclei",
        "07 Edges of ROI to detect Foci in it",
        "08 Apply ROI to binary Foci Image",
        "09 Connect near Foci",
        "10 Select Foci by Area",
        "11 Reduce Foci to Centroids",
        "12 Nuclei as initial Seed for Cells",
        "13 Erode Seeds",
        "14 Possible Cell Area",
        "15 Watershed Segmentation of Nuclei in Cytoplasma to approximate Cells",
        "16 Convert to 8bit",
        "17 Assign Foci to Cells"
    };

    //Results
    enum c_Results {
        c_ST_R_EMPTY,
        c_ST_R_C_INPUT,
        c_ST_R_C_CONTRAST,
        c_ST_R_C_BINARY,
        c_ST_R_C_SEEDS,
        c_ST_R_C_EDGES,
        c_ST_R_P_INPUT,
        c_ST_R_P_CONTRAST,
        c_ST_R_P_BINARY,
        c_ST_R_P_EDGES,
        c_ST_R_F_INPUT,
        c_ST_R_F_CONTRAST,
        c_ST_R_F_BINARY,
        c_ST_R_F_SELECTED,
        c_ST_R_F_DOT,
        c_ST_R_R_ROI,
        c_ST_R_R_ROI_EDGES,
        c_ST_R_R_EDGES,
        c_ST_R_NUMBER_OF
    };
};

#endif // D_MAKRO_COREFOCI_H
