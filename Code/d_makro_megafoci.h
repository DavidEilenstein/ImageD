/************************************
 *   added:     ??.03.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MAKRO_MEGAFOCI_H
#define D_MAKRO_MEGAFOCI_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_visdat_proc.h>
#include <d_plot.h>
#include <d_stat.h>
#include <d_viewer.h>
#include <d_viewer_3d.h>
#include <d_storage.h>
#include <d_table.h>
#include <d_popup_listedit.h>
#include <d_videowriter.h>
#include <d_finishtimeprognosis.h>
#include <d_bio_nucleuspedigree.h>
#include <d_bio_nucleusimage.h>
#include <d_imagerewardsystem.h>

//Qt
#include <QMainWindow>
#include <QFileDialog>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QDateTime>
#include <QComboBox>
#include <QStackedWidget>
#include <QCloseEvent>
#include <QResizeEvent>
#include <QInputDialog>
#include <qplaintextedit.h>
#include <QColorDialog>
#include <QLabel>
#include <d_popup_rangeselector.h>
#include <QPushButton>
#include <QCheckBox>
#include <QGroupBox>

//Qt::Charts
#include <QChartView>
#include <QChart>

//general
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <thread>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

namespace Ui {
class D_MAKRO_MegaFoci;
}

class D_MAKRO_MegaFoci : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_MegaFoci(D_Storage *pStorage, QWidget *parent = nullptr);
    ~D_MAKRO_MegaFoci();

    //overloaded events
    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

private slots:

    //show and update (images)
    void Update_Ui();
    void Update_Views();
    void Update_Images();
    void Update_Images_Proc();
    void Update_Images_OverviewSmall();
    void Update_Images_OverviewBig();

    //image processing
    void Update_ImageProcessing_CurrentImage();
    void Update_ImageProcessing_StepFrom(size_t step_start);
    void Update_ImageProcessing_StepFrom_MS1(size_t step_start);
    void Update_ImageProcessing_StepSingle(size_t step);
    void Update_ImageProcessing_StepSingle_MS1(size_t step);

    //image Decomp
    void ImageDecomp_Init();
    void Update_ImageDecomposition();

    //stack processing
    void Stack_Process_All();
    void Stack_Porcess_Single_XYT_Viewport();

    //populate ui
    void Populate_CB_AtStart();
    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int init_index = 0);

    //connectors
    void ConnectViewersVisTrafo(D_Viewer* view);

    bool Load_Dataset();
    bool Params_Load_CurrentDir();
    bool Params_Load();
    bool Params_Load(QString QS_FileName);
    void Params_Save();
    void Overview_Init();
    void Overview_Update();

    //set dims
    void set_dataset_dim_x(int x);
    void set_dataset_dim_y(int y);
    void set_dataset_dim_t(int t);
    void set_dataset_dim_z(int z);
    void set_LoadButton_FilelistSize();

    //indices
    bool Update_PagesConfig(bool give_2nd_try = true);

    //status info to statius panel
    void StatusSet(QString NewStatus);

    //vis trafo
    void on_comboBox_VisTrafo_CropMode_currentIndexChanged(int index);
    void on_comboBox_VisTrafo_TransformationMode_currentIndexChanged(int index);
    void on_comboBox_VisTrafo_AnchorMode_currentIndexChanged(int index);
    void on_comboBox_VisTrafo_RangeMode_currentIndexChanged(int index);

    void on_comboBox_ImgProc_StepShow_currentIndexChanged(int index);

    void on_spinBox_Viewport_P_valueChanged(int arg1);

    void on_tabWidget_Control_currentChanged(int index);

    void on_spinBox_DataDim_P_exist_valueChanged(int arg1);

    void on_spinBox_ImgProc_Stitch_Overlap_x_valueChanged(int arg1);
    void on_spinBox_ImgProc_Stitch_Overlap_y_valueChanged(int arg1);

    void on_horizontalSlider_OverviewBig_T_valueChanged(int value);

    void on_pushButton_ParamLoad_clicked();
    void on_pushButton_ParamSave_clicked();

private:
    Ui::D_MAKRO_MegaFoci *ui;
    bool ClosingPossible = false;

    //error handling
    D_Error_Handler ER;
    void ERR(int err, QString func = "not specified", QString detail = "not specified");

    //reward system
    D_ImageRewardSystem                 RewardSystem;

    //Storage
    D_Storage                           *pStore;

    //states
    bool                                state_dataset_dim_set = false;
    bool                                state_dataset_img_list_loaded = false;
    bool                                state_overview_init = false;
    bool                                state_stack_processing = false;
    bool                                state_image_decomposed = false;
    bool                                state_image_decomposition_init = false;
    bool                                state_first_proc_on_start = true;
    bool                                state_page_indices_consistent = true;
    bool                                state_block_img_proc_update = false;

    //data files
    QFileInfoList                       FIL_ImagesYXT;
    QStringList                         QSL_ImagesYXT_Paths;
    QStringList                         QSL_ImagesYXT_Names;
    QStringList                         QSL_ImagesYXT_Suffix;

    //save dirs
    QDir                                DIR_SaveMaster;
    QDir                                DIR_SaveMosaik_All;
    QDir                                DIR_SaveMosaik_Color;
    QDir                                DIR_SaveMosaik_GFP;
    QDir                                DIR_SaveMosaik_RFP;
    QDir                                DIR_SaveMosaik_DIC;
    QDir                                DIR_SaveMosaik_Info_Foci;
    QDir                                DIR_SaveMosaik_Info_Shape;
    QDir                                DIR_SaveMosaik_Info_Value_Mean;
    QDir                                DIR_SaveMosaik_Info_Value_STD;
    QDir                                DIR_SaveMosaik_Info_Value_Skewness;
    QDir                                DIR_SaveMosaik_Info_Value_Kurtosis;
    QDir                                DIR_SaveMosaik_Info_Value_Median;
    QDir                                DIR_SaveMosaik_Info_Value_MedianDeviation;
    QDir                                DIR_SaveDetections;

    //dataset dimension
    size_t                              dataset_dim_mosaic_x = 15;
    size_t                              dataset_dim_mosaic_y = 15;
    size_t                              dataset_dim_mosaic_xy = 15 * 15;
    size_t                              dataset_dim_z = 8;
    size_t                              dataset_dim_t = 52;
    size_t                              dataset_dim_xyt = 15 * 15 * 52;
    size_t                              dataset_dim_p_used = 2;
    size_t                              dataset_dim_p_exist = 3;
    size_t                              dataset_dim_tzp_used = 52 * 8 * 2;
    size_t                              dataset_dim_tzp_exist = 52 * 8 * 3;
    size_t                              dataset_dim_img_x = 1004;
    size_t                              dataset_dim_img_y = 1002;
    int                                 dataset_type_mat = CV_16UC1;
    int                                 dataset_depth_mat = CV_16U;
    size_t                              get_index_of_image(size_t x, size_t y, size_t t);
    size_t                              get_index_of_page(size_t z, size_t p);

    //scale to real world
    double                              dataset_step_x = 1;
    double                              dataset_step_y = 1;
    double                              dataset_step_t = 1;


    //Main Viewer
    D_VisDat_Obj                        VD_Show;
    Mat                                 MA_Show;
    D_Viewer                            Viewer_Main;

    //img proc
    vector<D_VisDat_Obj>                vVD_ImgProcSteps;

    //img decomposition
    vector<vector<vector<D_Bio_NucleusImage>>>  vvvImageDecomp_TYX;
    vector<vector<vector<int>>>                 vvvImageDecompCalced_TYX;


    //image buffer to save load operations
    vector<D_VisDat_Obj>                vVD_ImgLoadBuffer;
    vector<vector<int>>                 vv_ImgLoadBuffer_XYT_Index;
    size_t                              ImgLoadBuffer_BufferSize = dataset_dim_mosaic_x + 1;
    void                                ImgBuffer_Init();
    void                                ImgBuffer_Write(D_VisDat_Obj *img, int x_img, int y_img, int t_img);
    int                                 ImgBuffer_Find(int x, int y, int t);
    bool                                ImgBuffer_Read(D_VisDat_Obj *img, size_t i);
    int                                 Load_Image(D_VisDat_Obj *img, size_t x, size_t y, size_t t);
    void                                CreateZero_Image(D_VisDat_Obj *img);

    //overview
    double                              overview_scale = 0.30;
    D_VisDat_Obj                        VD_Overview_Save;
    Mat                                 MA_OverviewSmall_Show;
    Mat                                 MA_OverviewBig_Show;
    D_Viewer                            Viewer_OverviewSmall;
    D_Viewer                            Viewer_OverviewBig;

    //Status
    const int                           status_EntryNumber = 250;
    QStringList                         QSL_Status;

    //Statusbar
    QLabel                              *L_SB_ValueAtCursor;
    QLabel                              *L_SB_InfoVD;

    //time measurement
    qint64                              time_LastSingleImgProc = 0;

    //Pages (values)
    size_t index_page_other = 0;
    size_t index_GFP = 1;
    size_t index_RFP = 2;
    QStringList QSL_Pages = {
        "Other",
        "GFP",
        "RFP"
    };

    //Foci types
    enum FOCI_TYPES {
        FOCI_GFP,
        FOCI_RFP,
        FOCI_BOTH,
        FOCI_NUMBER_OF
    };
    const QStringList QSL_FociTypes = {
        "Foci GFP",
        "Foci RFP",
        "Foci both"
    };

    //Img Proc Step
    enum STEPS {
        //Prepare
        STEP_PRE_LOAD_MAIN,
        STEP_PRE_LOAD_RIGHT,
        STEP_PRE_LOAD_BOTTOM,
        STEP_PRE_LOAD_BOTTOM_RIGHT,
        STEP_PRE_STITCH,

        //Preprocessing OTHER
        STEP_PRE_PICK_OTHER,
        STEP_PRE_CROP_Z_OTHER,
        STEP_PRE_BLUR_PLANES_INDEPENDENT_OTHER,
        STEP_PRE_PROJECT_Z_OTHER,
        STEP_PRE_BACKGROUND_ESTIMATION_OTHER,
        STEP_PRE_SHADING_CORRECTED_OTHER,
        STEP_PRE_VIS_OTHER,

        //Preprocessing GFP
        STEP_PRE_PICK_GFP,
        STEP_PRE_CROP_Z_GFP,
        STEP_PRE_BLUR_PLANES_INDEPENDENT_GFP,
        STEP_PRE_PROJECT_Z_GFP,
        STEP_PRE_BACKGROUND_ESTIMATION_GFP,
        STEP_PRE_SHADING_CORRECTED_GFP,
        STEP_PRE_VIS_GFP,

        //Preprocessing RFP
        STEP_PRE_PICK_RFP,
        STEP_PRE_CROP_Z_RFP,
        STEP_PRE_BLUR_PLANES_INDEPENDENT_RFP,
        STEP_PRE_PROJECT_Z_RFP,
        STEP_PRE_BACKGROUND_ESTIMATION_RFP,
        STEP_PRE_SHADING_CORRECTED_RFP,
        STEP_PRE_VIS_RFP,

        //Visualization Color
        STEP_VIS_PAGES_AS_COLOR_GFP_RFP,
        STEP_VIS_PAGES_AS_COLOR_ALL,

        //Nuclei thres GFP
        STEP_NUC_SEG_GFP_BLUR_MEDIAN,
        STEP_NUC_SEG_GFP_BLUR_MORPH_A_DILATE,
        STEP_NUC_SEG_GFP_BLUR_MORPH_B_ERODE,
        STEP_NUC_SEG_GFP_BLUR_MORPH_C_DILATE,
        STEP_NUC_SEG_GFP_THRES_0_AREA,
        STEP_NUC_SEG_GFP_THRES_1_AREA,
        STEP_NUC_SEG_GFP_THRES_2_AREA,
        STEP_NUC_SEG_GFP_THRES_3_AREA,
        STEP_NUC_SEG_GFP_THRES_0_CONTOUR,
        STEP_NUC_SEG_GFP_THRES_1_CONTOUR,
        STEP_NUC_SEG_GFP_THRES_2_CONTOUR,
        STEP_NUC_SEG_GFP_THRES_3_CONTOUR,
        STEP_NUC_SEG_GFP_THRES_BASE_VIS_ALL_AREAS,
        STEP_NUC_SEG_GFP_THRES_BASE_VIS_ALL_CONTOURS,

        //Nuclei thres RFP
        STEP_NUC_SEG_RFP_BLUR_MEDIAN,
        STEP_NUC_SEG_RFP_BLUR_MORPH_A_DILATE,
        STEP_NUC_SEG_RFP_BLUR_MORPH_B_ERODE,
        STEP_NUC_SEG_RFP_BLUR_MORPH_C_DILATE,
        STEP_NUC_SEG_RFP_THRES_0_AREA,
        STEP_NUC_SEG_RFP_THRES_1_AREA,
        STEP_NUC_SEG_RFP_THRES_2_AREA,
        STEP_NUC_SEG_RFP_THRES_3_AREA,
        STEP_NUC_SEG_RFP_THRES_0_CONTOUR,
        STEP_NUC_SEG_RFP_THRES_1_CONTOUR,
        STEP_NUC_SEG_RFP_THRES_2_CONTOUR,
        STEP_NUC_SEG_RFP_THRES_3_CONTOUR,
        STEP_NUC_SEG_RFP_THRES_BASE_VIS_ALL_AREAS,
        STEP_NUC_SEG_RFP_THRES_BASE_VIS_ALL_CONTOURS,

        //thres vis
        STEP_NUC_SEG_BOTH_THRES_BASE_VIS_AREAS,
        STEP_NUC_SEG_BOTH_THRES_BASE_VIS_CONTOURS,
        STEP_NUC_SEG_BOTH_THRES_BASE_VIS_CONTOURS_ON_IMG,

        //nuc seg combi
        //rfp t3
        STEP_NUC_SEG_LVLCOMBI_RFP_T3_OBJECTS_NEW_AREA,
        STEP_NUC_SEG_LVLCOMBI_RFP_T3_OBJECTS_NEW_CONT,
        //gfp t3
        STEP_NUC_SEG_LVLCOMBI_GFP_T3_WITHOUT_ACCEPTED_OBJECTS,
        STEP_NUC_SEG_LVLCOMBI_GFP_T3_BASE_MORPH_CLEAR,
        STEP_NUC_SEG_LVLCOMBI_GFP_T3_OBJECTS_NEW_AREA,
        STEP_NUC_SEG_LVLCOMBI_GFP_T3_OBJECTS_NEW_CONT,
        STEP_NUC_SEG_LVLCOMBI_GFP_T3_OBJECTS_ALL,
        //rfp t2
        STEP_NUC_SEG_LVLCOMBI_RFP_T2_WITHOUT_ACCEPTED_OBJECTS,
        STEP_NUC_SEG_LVLCOMBI_RFP_T2_BASE_MORPH_CLEAR,
        STEP_NUC_SEG_LVLCOMBI_RFP_T2_OBJECTS_NEW_AREA,
        STEP_NUC_SEG_LVLCOMBI_RFP_T2_OBJECTS_NEW_CONT,
        STEP_NUC_SEG_LVLCOMBI_RFP_T2_OBJECTS_ALL,
        //gfp t2
        STEP_NUC_SEG_LVLCOMBI_GFP_T2_WITHOUT_ACCEPTED_OBJECTS,
        STEP_NUC_SEG_LVLCOMBI_GFP_T2_BASE_MORPH_CLEAR,
        STEP_NUC_SEG_LVLCOMBI_GFP_T2_OBJECTS_NEW_AREA,
        STEP_NUC_SEG_LVLCOMBI_GFP_T2_OBJECTS_NEW_CONT,
        STEP_NUC_SEG_LVLCOMBI_GFP_T2_OBJECTS_ALL,
        //rfp t1
        STEP_NUC_SEG_LVLCOMBI_RFP_T1_WITHOUT_ACCEPTED_OBJECTS,
        STEP_NUC_SEG_LVLCOMBI_RFP_T1_BASE_MORPH_CLEAR,
        STEP_NUC_SEG_LVLCOMBI_RFP_T1_OBJECTS_NEW_AREA,
        STEP_NUC_SEG_LVLCOMBI_RFP_T1_OBJECTS_NEW_CONT,
        STEP_NUC_SEG_LVLCOMBI_RFP_T1_OBJECTS_ALL,
        //gfp t1
        STEP_NUC_SEG_LVLCOMBI_GFP_T1_WITHOUT_ACCEPTED_OBJECTS,
        STEP_NUC_SEG_LVLCOMBI_GFP_T1_BASE_MORPH_CLEAR,
        STEP_NUC_SEG_LVLCOMBI_GFP_T1_OBJECTS_NEW_AREA,
        STEP_NUC_SEG_LVLCOMBI_GFP_T1_OBJECTS_NEW_CONT,
        STEP_NUC_SEG_LVLCOMBI_GFP_T1_OBJECTS_ALL,
        //rfp t0
        STEP_NUC_SEG_LVLCOMBI_RFP_T0_WITHOUT_ACCEPTED_OBJECTS,
        STEP_NUC_SEG_LVLCOMBI_RFP_T0_BASE_MORPH_CLEAR,
        STEP_NUC_SEG_LVLCOMBI_RFP_T0_OBJECTS_NEW_AREA,
        STEP_NUC_SEG_LVLCOMBI_RFP_T0_OBJECTS_NEW_CONT,
        STEP_NUC_SEG_LVLCOMBI_RFP_T0_OBJECTS_ALL,
        //gfp t0
        STEP_NUC_SEG_LVLCOMBI_GFP_T0_WITHOUT_ACCEPTED_OBJECTS,
        STEP_NUC_SEG_LVLCOMBI_GFP_T0_BASE_MORPH_CLEAR,
        STEP_NUC_SEG_LVLCOMBI_GFP_T0_OBJECTS_NEW_AREA,
        STEP_NUC_SEG_LVLCOMBI_GFP_T0_OBJECTS_NEW_CONT,
        STEP_NUC_SEG_LVLCOMBI_GFP_T0_OBJECTS_ALL,
        //all
        STEP_NUC_SEG_LVLCOMBI_CONTOURS_ALL_VIS_GFP_INTENSITY,
        STEP_NUC_SEG_LVLCOMBI_CONTOURS_ALL_VIS_RFP_INTENSITY,
        STEP_NUC_SEG_LVLCOMBI_CONTOURS_ALL_VIS_BOTH_COLOR_INTENSITY,
        STEP_NUC_SEG_LVLCOMBI_CONTOURS_ALL_VIS_BOTH_COLOR_INTENSITY_ON_IMG,
        STEP_NUC_SEG_LVLCOMBI_CONTOURS_ALL_VIS_GFP_BINARY,
        STEP_NUC_SEG_LVLCOMBI_CONTOURS_ALL_VIS_RFP_BINARY,
        STEP_NUC_SEG_LVLCOMBI_CONTOURS_ALL_VIS_BOTH_COLOR_BINARY,
        STEP_NUC_SEG_LVLCOMBI_CONTOURS_ALL_BOTH_MONO_BINARY,
        STEP_NUC_SEG_LVLCOMBI_OBJECTS_ALL_VIS_GFP_INTENSITY,
        STEP_NUC_SEG_LVLCOMBI_OBJECTS_ALL_VIS_RFP_INTENSITY,
        STEP_NUC_SEG_LVLCOMBI_OBJECTS_ALL_VIS_BOTH_COLOR_INTENSITY,
        STEP_NUC_SEG_LVLCOMBI_OBJECTS_ALL_VIS_GFP_BINARY,
        STEP_NUC_SEG_LVLCOMBI_OBJECTS_ALL_VIS_RFP_BINARY,
        STEP_NUC_SEG_LVLCOMBI_OBJECTS_ALL_VIS_BOTH_COLOR_BINARY,
        STEP_NUC_SEG_LVLCOMBI_OBJECTS_ALL_BOTH_MONO,
        STEP_NUC_SEG_LVLCOMBI_OBJECTS_ALL_BOTH_MONO_SEPARATED,

        //distance separation of objs
        STEP_NUC_SEG_DISTSEP_DIST,
        STEP_NUC_SEG_DISTSEP_SEEDS,
        STEP_NUC_SEG_DISTSEP_SEEDS_CLEAR,
        STEP_NUC_SEG_DISTSEP_WATERSHED,
        STEP_NUC_SEG_DISTSEP_OBJECTS,
        STEP_NUC_SEG_DISTSEP_CONTOURS,

        //nuc sep final
        STEP_NUC_SEG_FINAL_OBJECTS,
        STEP_NUC_SEG_FINAL_CONTOURS,

        //Find Foci GFP
        STEP_FOC_GFP_BLUR_MEDIAN,
        STEP_FOC_GFP_BINARY_THRES,
        STEP_FOC_GFP_SELECT_AREA,

        //Find Foci RFP
        STEP_FOC_RFP_BLUR_MEDIAN,
        STEP_FOC_RFP_BINARY_THRES,
        STEP_FOC_RFP_SELECT_AREA,

        //Match Foci
        STEP_FOC_BOTH_INTERSECT,
        STEP_FOC_BOTH_SELECT_AREA,

        //Classification
        STEP_CLA_FOC_ALL,
        STEP_CLA_FOC_IN_ONE_ONLY,
        STEP_CLA_FOC_IN_GFP_ONLY,
        STEP_CLA_FOC_IN_RFP_ONLY,

        //Visualization
        STEP_VIS_REGIONS_FOCI_COLOR,
        STEP_VIS_REGIONS_FOCI_MONO,
        STEP_VIS_REGIONS_FOCI_ON_IMG_ALL,
        STEP_VIS_REGIONS_FOCI_ON_IMG_USED,
        STEP_VIS_REGIONS_NUCLEI_ON_IMG_ALL_MONO,
        STEP_VIS_REGIONS_NUCLEI_ON_IMG_USED_MONO,
        STEP_VIS_REGIONS_NUCLEIFOCI_ON_IMG_ALL,
        STEP_VIS_REGIONS_NUCLEIFOCI_ON_IMG_USED,

        //this huge list finally has an end...
        STEP_NUMBER_OF
    };
    const QStringList QSL_Steps = {
        //Prepare
        "p0 - load main",
        "p1 - load right",
        "p2 - load bottom",
        "p3 - load bottom right",
        "p4 - stitch",

        //Preprocessing OTHER
        "po0 - other - pick channel",
        "po1 - other - crop z",
        "po2 - other - blur planes",
        "po3 - other - project z",
        "po4 - other - background estimation",
        "po5 - other - shading corrected",
        "po6 - other - visualize 8bit",

        //Preprocessing GFP
        "pg0 - GFP - pick channel",
        "pg1 - GFP - crop z",
        "pg2 - GFP - blur planes",
        "pg3 - GFP - project z",
        "pg4 - GFP - background estimation",
        "pg5 - GFP - shading corrected",
        "pg6 - GFP - visualize 8bit",

        //Preprocessing RFP
        "pr0 - RFP - pick channel",
        "pr1 - RFP - crop z",
        "pr2 - RFP - blur planes",
        "pr3 - RFP - project z",
        "pr4 - RFP - background estimation",
        "pr5 - RFP - shading corrected",
        "pr6 - RFP - visualize 8bit",

        //Visualization Color
        "v0 - pages as color (GFP and RFP)",
        "v1 - pages as color (all)",

        //Nuclei thres GFP
        "ntg00 - GFP - blur median",
        "ntg01 - GFP - morph a dilate",
        "ntg02 - GFP - morph b erode",
        "ntg03 - GFP - morph c dilate",
        "ntg04 - GFP - thres 0 area",
        "ntg05 - GFP - thres 1 area",
        "ntg06 - GFP - thres 2 area",
        "ntg07 - GFP - thres 3 area",
        "ntg08 - GFP - thres 0 contour",
        "ntg09 - GFP - thres 1 contour",
        "ntg10 - GFP - thres 2 contour",
        "ntg11 - GFP - thres 3 contour",
        "ntg12 - GFP - base vis all areas",
        "ntg13 - GFP - base vis all contours",

        //Nuclei thres RFP
        "ntr00 - RFP - blur median",
        "ntr01 - RFP - morph a dilate",
        "ntr02 - RFP - morph b erode",
        "ntr03 - RFP - morph c dilate",
        "ntr04 - RFP - thres 0 area",
        "ntr05 - RFP - thres 1 area",
        "ntr06 - RFP - thres 2 area",
        "ntr07 - RFP - thres 3 area",
        "ntr08 - RFP - thres 0 contour",
        "ntr09 - RFP - thres 1 contour",
        "ntr10 - RFP - thres 2 contour",
        "ntr11 - RFP - thres 3 contour",
        "ntr12 - RFP - base vis all areas",
        "ntr13 - RFP - base vis all contours",

        //thres vis
        "ntb0 - both - base vis areas",
        "ntb1 - both - base vis contours",
        "ntb2 - both - base vis contours on image",

        //nuc seg combi
        //rfp t3
        "nlr30 - RFP - objects new",
        "nlr31 - RFP - objects new contours",
        //gfp t3
        "nlg30 - GFP - without accepted objects",
        "nlg31 - GFP - base morphological clear",
        "nlg32 - GFP - objects new",
        "nlg33 - GFP - objects new contour",
        "nlg34 - GFP - objects all",
        //rfp t2
        "nlr20 - RFP - without accepted objects",
        "nlr21 - RFP - base morphological clear",
        "nlr22 - RFP - objects new",
        "nlr23 - RFP - objects new contour",
        "nlr24 - RFP - objects all",
        //gfp t2
        "nlg20 - GFP - without accepted objects",
        "nlg21 - GFP - base morphological clear",
        "nlg22 - GFP - objects new",
        "nlg23 - GFP - objects new contour",
        "nlg24 - GFP - objects all",
        //rfp t1
        "nlr10 - RFP - without accepted objects",
        "nlr11 - RFP - base morphological clear",
        "nlr12 - RFP - objects new",
        "nlr13 - RFP - objects new contour",
        "nlr14 - RFP - objects all",
        //gfp t1
        "nlg10 - GFP - without accepted objects",
        "nlg11 - GFP - base morphological clear",
        "nlg12 - GFP - objects new",
        "nlg13 - GFP - objects new contour",
        "nlg14 - GFP - objects all",
        //rfp t0
        "nlr00 - RFP - without accepted objects",
        "nlr01 - RFP - base morphological clear",
        "nlr02 - RFP - objects new",
        "nlr03 - RFP - objects new contour",
        "nlr04 - RFP - objects all",
        //gfp t0
        "nlg00 - GFP - without accepted objects",
        "nlg01 - GFP - base morphological clear",
        "nlg02 - GFP - objects new",
        "nlg03 - GFP - objects new contour",
        "nlg04 - GFP - objects all",
        //all
        "nla00 - GFP - contours gfp vis intensity",
        "nla01 - RFP - contours rfp vis intensity",
        "nla02 - both - contours color vis intensity",
        "nla03 - both - contours color vis intensity on image",
        "nla04 - GFP - contours gfp vis binary",
        "nla05 - RFP - contours rfp vis binary",
        "nla06 - both - contours color vis binary",
        "nla07 - both - contours both mono binary",
        "nla08 - GFP - objects gfp vis intensity",
        "nla09 - RFP - objects rfp vis intensity",
        "nla10 - both - objects color vis intensity",
        "nla11 - GFP - objects gfp vis binary",
        "nla12 - RFP - objects rfp vis binary",
        "nla13 - both - objects color vis binary",
        "nla14 - both - objects both mono",
        "nla15 - both - objects both mono separated",

        //distance separation of objs
        "nd0 - distance",
        "nd1 - seeds",
        "nd2 - seeds clear",
        "nd3 - watershed",
        "nd4 - objects",
        "nd5 - contours",

        //nuc sep final
        "nf0 - objects",
        "nf1 - contours",

        //Find Foci GFP
        "fg0 - GFP - blur",
        "fg1 - GFP - thres",
        "fg2 - GFP - select area",

        //Find Foci RFP
        "fr0 - RFP - blur",
        "fr1 - RFP - thres",
        "fr2 - RFP - select area",

        //Match Foci
        "fb0 - both - intersect",
        "fb1 - both - select area",

        //Classification
        "fc0 - all",
        "fc1 - only one",
        "fc2 - only GFP",
        "fc3 - only RFP",

        //Visualization
        "v04 - regions foci color",
        "v05 - regions foci mono",
        "v06 - regions foci color on image all",
        "v07 - regions foci color on image used",
        "v08 - regions nuclei mono on img all",
        "v09 - regions nuclei mono on image used",
        "v10 - regions nuclei and foci on image all",
        "v11 - regions nuclei and foci on image used"

        //this huge list finally has an end...

    };

    enum MS1_PARAMS {
        MS1_PARAM_PRE5_BLUR_SIZE,
        MS1_PARAM_PRE5_BLUR_SIGMA,
        MS1_PARAM_PRE6_STAT,
        MS1_PARAM_VIS0_NUC_MIN,
        MS1_PARAM_VIS0_NUC_MAX,
        MS1_PARAM_VIS0_NUC_GAMMA,
        MS1_PARAM_VIS1_GFP_MIN,
        MS1_PARAM_VIS1_GFP_MAX,
        MS1_PARAM_VIS1_GFP_GAMMA,
        MS1_PARAM_VIS2_RFP_MIN,
        MS1_PARAM_VIS2_RFP_MAX,
        MS1_PARAM_VIS2_RFP_GAMMA,
        MS1_PARAM_NUC0_IN_USE,
        MS1_PARAM_NUC0_BLUR_SIZE,
        MS1_PARAM_NUC0_BLUR_SIGMA,
        MS1_PARAM_NUC1_QUANTIL,
        MS1_PARAM_NUC1_RADIUS,
        MS1_PARAM_NUC3_THRES_INDICATOR,
        MS1_PARAM_NUC4_THRES_HYSTERESIS,
        MS1_PARAM_NUC6_CLOSE_SIZE,
        MS1_PARAM_NUC8_STAT,
        MS1_PARAM_NUC8_THRESH_DIRT,
        MS1_PARAM_NUC9_IN_USE,
        MS1_PARAM_NUC9_BLUR_SIZE,
        MS1_PARAM_NUC9_BLUR_SIGMA,
        MS1_PARAM_NUC10_QUANTIL,
        MS1_PARAM_NUC10_RADIUS,
        MS1_PARAM_NUC12_THRES_INDICATOR,
        MS1_PARAM_NUC13_THRES_HYSTERESIS,
        MS1_PARAM_NUC15_CLOSE_SIZE,
        MS1_PARAM_NUC17_STAT,
        MS1_PARAM_NUC17_THRESH_DIRT,
        MS1_PARAM_NUC19_CLOSE_SIZE,
        MS1_PARAM_NUC21_AREA_MIN,
        MS1_PARAM_NUC21_AREA_MAX,
        MS1_PARAM_NUC22_CLOSE_SIZE,
        MS1_PARAM_NUC23_AREA_MIN,
        MS1_PARAM_NUC23_AREA_MAX,
        MS1_PARAM_NUC25_DISTANCE,
        MS1_PARAM_NUC26_OPEN_SIZE,
        MS1_PARAM_NUC30_DISTANCE,
        MS1_PARAM_NUC31_OPEN_SIZE,
        MS1_PARAM_NUC33_AREA_MIN,
        MS1_PARAM_NUC33_AREA_MAX,
        MS1_PARAM_NUC40_OPEN_SIZE,
        MS1_PARAM_FOCGFP0_RADIUS,
        MS1_PARAM_FOCGFP1_SIZE,
        MS1_PARAM_FOCGFP1_SIGMA,
        MS1_PARAM_FOCGFP1_SCALE,
        MS1_PARAM_FOCGFP1_OFFSET,
        MS1_PARAM_FOCGFP3_AREA_MIN,
        MS1_PARAM_FOCGFP3_AREA_MAX,
        MS1_PARAM_FOCRFP0_RADIUS,
        MS1_PARAM_FOCRFP1_SIZE,
        MS1_PARAM_FOCRFP1_SIGMA,
        MS1_PARAM_FOCRFP1_SCALE,
        MS1_PARAM_FOCRFP1_OFFSET,
        MS1_PARAM_FOCRFP3_AREA_MIN,
        MS1_PARAM_FOCRFP3_AREA_MAX,
        MS1_PARAM_FOCBOTH1_AREA_MIN,
        MS1_PARAM_FOCBOTH1_AREA_MAX,
        MS1_PARAM_VIS8_INTENSITY_OVERLAY,
        MS1_PARAM_VIS8_INTENSITY_BACKGROUND,
        MS1_PARAM_OTHER_DUPLICATE_OVERLAP,
        MS1_PARAM_NUMBER_OF
    };

    const QStringList QSL_MS1_Params = {
        "MS1_PARAM_PRE5_BLUR_SIZE",
        "MS1_PARAM_PRE5_BLUR_SIGMA",
        "MS1_PARAM_PRE6_STAT",
        "MS1_PARAM_VIS0_NUC_MIN",
        "MS1_PARAM_VIS0_NUC_MAX",
        "MS1_PARAM_VIS0_NUC_GAMMA",
        "MS1_PARAM_VIS1_GFP_MIN",
        "MS1_PARAM_VIS1_GFP_MAX",
        "MS1_PARAM_VIS1_GFP_GAMMA",
        "MS1_PARAM_VIS2_RFP_MIN",
        "MS1_PARAM_VIS2_RFP_MAX",
        "MS1_PARAM_VIS2_RFP_GAMMA",
        "MS1_PARAM_NUC0_IN_USE",
        "MS1_PARAM_NUC0_BLUR_SIZE",
        "MS1_PARAM_NUC0_BLUR_SIGMA",
        "MS1_PARAM_NUC1_QUANTIL",
        "MS1_PARAM_NUC1_RADIUS",
        "MS1_PARAM_NUC3_THRES_INDICATOR",
        "MS1_PARAM_NUC4_THRES_HYSTERESIS",
        "MS1_PARAM_NUC6_CLOSE_SIZE",
        "MS1_PARAM_NUC8_STAT",
        "MS1_PARAM_NUC8_THRESH_DIRT",
        "MS1_PARAM_NUC9_IN_USE",
        "MS1_PARAM_NUC9_BLUR_SIZE",
        "MS1_PARAM_NUC9_BLUR_SIGMA",
        "MS1_PARAM_NUC10_QUANTIL",
        "MS1_PARAM_NUC10_RADIUS",
        "MS1_PARAM_NUC12_THRES_INDICATOR",
        "MS1_PARAM_NUC13_THRES_HYSTERESIS",
        "MS1_PARAM_NUC15_CLOSE_SIZE",
        "MS1_PARAM_NUC17_STAT",
        "MS1_PARAM_NUC17_THRESH_DIRT",
        "MS1_PARAM_NUC19_CLOSE_SIZE",
        "MS1_PARAM_NUC21_AREA_MIN",
        "MS1_PARAM_NUC21_AREA_MAX",
        "MS1_PARAM_NUC22_CLOSE_SIZE",
        "MS1_PARAM_NUC23_AREA_MIN",
        "MS1_PARAM_NUC23_AREA_MAX",
        "MS1_PARAM_NUC25_DISTANCE",
        "MS1_PARAM_NUC26_OPEN_SIZE",
        "MS1_PARAM_NUC30_DISTANCE",
        "MS1_PARAM_NUC31_OPEN_SIZE",
        "MS1_PARAM_NUC33_AREA_MIN",
        "MS1_PARAM_NUC33_AREA_MAX",
        "MS1_PARAM_NUC40_OPEN_SIZE",
        "MS1_PARAM_FOCGFP0_RADIUS",
        "MS1_PARAM_FOCGFP1_SIZE",
        "MS1_PARAM_FOCGFP1_SIGMA",
        "MS1_PARAM_FOCGFP1_SCALE",
        "MS1_PARAM_FOCGFP1_OFFSET",
        "MS1_PARAM_FOCGFP3_AREA_MIN",
        "MS1_PARAM_FOCGFP3_AREA_MAX",
        "MS1_PARAM_FOCRFP0_RADIUS",
        "MS1_PARAM_FOCRFP1_SIZE",
        "MS1_PARAM_FOCRFP1_SIGMA",
        "MS1_PARAM_FOCRFP1_SCALE",
        "MS1_PARAM_FOCRFP1_OFFSET",
        "MS1_PARAM_FOCRFP3_AREA_MIN",
        "MS1_PARAM_FOCRFP3_AREA_MAX",
        "MS1_PARAM_FOCBOTH1_AREA_MIN",
        "MS1_PARAM_FOCBOTH1_AREA_MAX",
        "MS1_PARAM_VIS8_INTENSITY_OVERLAY",
        "MS1_PARAM_VIS8_INTENSITY_BACKGROUND",
        "MS1_PARAM_OTHER_DUPLICATE_OVERLAP"
    };

    //Tabs
    enum TABS_CONTROL {
        TAB_CONTROL_VIEWPORT,
        TAB_CONTROL_IMG_PROC_MS1,
        TAB_CONTROL_IMG_PROC_MS3,
        TAB_CONTROL_OVERVIEW_BIG,
        TAB_CONTROL_NUMBER_OF
    };

    //View
    enum VIEW_PAGE {
        VIEW_PAGE_IMG_PROC,
        VIEW_PAGE_OVERVIEW_BIG,
        VIEW_PAGE_STACK,
        VIEW_PAGE_PLOT
    };

    //overview types
    enum OVERVIEW_TYPE {
        OVERVIEW_TYPE_DIC,
        OVERVIEW_TYPE_GFP,
        OVERVIEW_TYPE_RFP,
        OVERVIEW_TYPE_COLOR,
        OVERVIEW_TYPE_INFO_FOCI,
        OVERVIEW_TYPE_INFO_SHAPE,
        OVERVIEW_TYPE_INFO_VALUE_MEAN,
        OVERVIEW_TYPE_INFO_VALUE_STD,
        OVERVIEW_TYPE_INFO_VALUE_SKEWNESS,
        OVERVIEW_TYPE_INFO_VALUE_KURTOSIS,
        OVERVIEW_TYPE_INFO_VALUE_MEDIAN,
        OVERVIEW_TYPE_INFO_VALUE_MED_DEV,
        OVERVIEW_TYPE_NUMBER_OF
    };
    const QStringList QSL_OverviewTypes = {
        "Gray DIC",
        "Gray GFP",
        "Gray RFP",
        "Color GFP and RFP",
        "Foci",
        "Shape",
        "Values: Medians",
        "Values: Deviation from median",
        "Values: Mean",
        "Values: Standard deviation",
        "Values: Skewness",
        "Values: Kurtosis"
    };

    //-------------------------------------------------------------------- MS Management ----------------------------------------------------

    //major steps
    enum MODE_MAJOR {
        MODE_MAJOR_0_DATASET_DIM,
        MODE_MAJOR_1_AUTO_DETECTION,
        MODE_MAJOR_2_MANU_CORRECT_DETECTION,
        MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI,
        MODE_MAJOR_4_AUTO_RECONSTRUCT_PEDIGREE,
        MODE_MAJOR_5_MANU_CORRECT_PEDIGREE,
        MODE_MAJOR_6_EPIC_ANALYSIS,
        MODE_MAJOR_NUMBER_OF
    };
    const QStringList QSL_ModeMajor = {
        "S0 Dataset definition",
        "S1 Automatic detection",
        "S2 Manuel correction of detetctions",
        "S3 Automatic matching foci to nuclei",
        "S4 Automatic pedigree reconstruction",
        "S5 Manual pedigree correction",
        "S6 Epic analysis"
    };

    size_t mode_major_current = MODE_MAJOR_0_DATASET_DIM;
    void set_ModeMajor_Current(size_t mode);

private slots:

    void on_stackedWidget_StepMajor_currentChanged(int arg1);

    void on_pushButton_StepMajor_1_clicked();
    void on_pushButton_StepMajor_2_clicked();
    void on_pushButton_StepMajor_3_clicked();
    void on_pushButton_StepMajor_4_clicked();
    void on_pushButton_StepMajor_5_clicked();
    void on_pushButton_StepMajor_6_clicked();

    //-------------------------------------------------------------------- MS2 ----------------------------------------------------

private slots:

    void MS2_SetComboboxColor(QComboBox *CB_R, QComboBox *CB_G, QComboBox *CB_B, bool color_background_not_text);
    void MS2_SetComboboxColor_Image(size_t viewer_id);
    void MS2_SetComboboxColor_Overlay(size_t viewer_id);
    void MS2_SetComboboxColor_ImageAll();
    void MS2_SetComboboxColor_OverlayAll();
    void MS2_SetComboboxColor_All();

    void on_checkBox_MS2_ViewerShowSettings_clicked(bool checked);
    void on_pushButton_MS2_FileDialog_clicked();

    void on_pushButton_MS2_ViewerMaximize_1_clicked();
    void on_pushButton_MS2_ViewerMaximize_2_clicked();
    void on_pushButton_MS2_ViewerMaximize_3_clicked();
    void on_pushButton_MS2_ViewerMaximize_4_clicked();

    void on_pushButton_MS2_ViewerSettings_PointColor_1_clicked();
    void on_pushButton_MS2_ViewerSettings_PointColor_2_clicked();
    void on_pushButton_MS2_ViewerSettings_PointColor_3_clicked();
    void on_pushButton_MS2_ViewerSettings_PointColor_4_clicked();

    void on_checkBox_MS2_ViewerSettings_ConnectZoom_1_clicked(bool checked);
    void on_checkBox_MS2_ViewerSettings_ConnectZoom_2_clicked(bool checked);
    void on_checkBox_MS2_ViewerSettings_ConnectZoom_3_clicked(bool checked);
    void on_checkBox_MS2_ViewerSettings_ConnectZoom_4_clicked(bool checked);

    void on_checkBox_MS2_ViewerSettings_ViewTransform_1_clicked(bool checked);
    void on_checkBox_MS2_ViewerSettings_ViewTransform_2_clicked(bool checked);
    void on_checkBox_MS2_ViewerSettings_ViewTransform_3_clicked(bool checked);
    void on_checkBox_MS2_ViewerSettings_ViewTransform_4_clicked(bool checked);

    void on_pushButton_MS2_Tools_Channel_Nuclei_clicked();
    void on_pushButton_MS2_Tools_Channel_GFPonly_clicked();
    void on_pushButton_MS2_Tools_Channel_RFPonly_clicked();
    void on_pushButton_MS2_Tools_Channel_GFPandRFP_clicked();

    void on_comboBox_MS2_ViewportBackground_currentIndexChanged(int index);

    void on_pushButton_MS2_EventList_Load_clicked();
    void on_pushButton_MS2_EventList_Close_clicked();
    void on_pushButton_MS2_EventList_Move_clicked();
    void on_checkBox_MS2_EventList_Event_Solved_stateChanged(int arg1);
    void on_pushButton_MS2_EventList_ToBegin_clicked();
    void on_pushButton_MS2_EventList_ToEnd_clicked();

    void MS2_ViewerMaximize(int v2max);
    void MS2_ViewerPointColor(size_t v2col);
    void MS2_ViewerPointDiameter(size_t v, double d);
    void MS2_ViewerConnectZooms(size_t v2con, bool con);
    void MS2_ViewerSetVisTrafoActive(size_t v2tra);
    void MS2_ViewerSetVisTrafoActive_All();
    void MS2_ViewersPopulateCBs();
    void MS2_ViewersSelectDefaultCBs();

    void MS2_UpdateViews();
    void MS2_UpdateImages();
    void MS2_UpdateImage1();
    void MS2_UpdateImage2();
    void MS2_UpdateImage3();
    void MS2_UpdateImage4();
    void MS2_UpdateImage(size_t img2update);
    void MS2_UpdateImages_Editing();

    void MS2_UpdateImage_ToDo_Static();
    void MS2_UpdateImage_ToDo_Highlight(int x, int y);
    void MS2_UpdateImage_ToDo_Highlight();

    void MS2_UpdateImage_Viewport();
    void MS2_MoveToNextViewportToProcess();
    void MS2_MoveToNextViewport();

    void MS2_UpdateViewportPos();
    void MS2_InitOverlays();
    void MS2_UpdateOverlays();
    void MS2_UpdateOverlay(size_t overlay_index);

    void MS2_DrawMode_Set(size_t mode);
    void MS2_Draw_RecordedClicks_UpdateAvailiableDrawModi();
    void MS2_Draw_RecordedClicksChanged(size_t point_count);

    bool MS2_CalcMosaik_Size();

    bool MS2_LoadData();
    bool MS2_LoadData_DirsIn();
    bool MS2_LoadData_DirsOut();

    bool MS2_LoadData_TimeSelected();
    bool MS2_LoadData_Time(size_t t);
    bool MS2_LoadData_Mosaiks_In(size_t t);
    bool MS2_LoadData_Detections_In(size_t t, bool error_when_no_dir);
    bool MS2_LoadData_Detections_Out(size_t t);
    bool MS2_LoadData_Detections(size_t t, bool error_when_no_dir, vector<vector<D_Bio_NucleusImage> > *vvNucleiTarget, QDir DIR_Source, vector<vector<size_t> > *vvState, size_t state_found, size_t state_not_found);

    void MS2_ChangeMode(int mode);

    void MS2_EventList_Load();
    void MS2_EventList_Close();
    bool MS2_EventList_Sort();
    void MS2_EventList_SaveList();
    void MS2_EventList_SaveCurrent();
    bool MS2_EventList_ReadAtCursor();
    bool MS2_EventList_MoveToEvent();
    void MS2_EventList_Move();
    void MS2_EventList_Move_ToBegin();
    void MS2_EventList_Move_ToEnd();
    int     MS2_EventList_Decode_Number_Current(char number_name, bool *ok);
    int     MS2_EventList_Decode_Number(int line, char number_name, bool *ok);
    int     MS2_EventList_Decode_Number(QStringList QSL_List, int line, char number_name, bool *ok);
    QString MS2_EventList_Decode_Comment_Current(bool *ok);
    QString MS2_EventList_Decode_Comment(int line, bool *ok);
    bool    MS2_EventList_Decode_Status_Current(bool *ok);
    bool    MS2_EventList_Decode_Status(int line, bool *ok);

    void on_groupBox_VisTrafo_clicked();

    void on_doubleSpinBox_MS2_Params_NucleusBorderThickness_valueChanged(double arg1);
    void on_doubleSpinBox_MS2_Params_FociMinRadius_valueChanged(double arg1);

    void on_pushButton_MS2_Viewport_Left_clicked();
    void on_pushButton_MS2_Viewport_Right_clicked();
    void on_pushButton_MS2_Viewport_Up_clicked();
    void on_pushButton_MS2_Viewport_Down_clicked();
    void on_pushButton_MS2_Viewport_Next_clicked();
    void on_pushButton_MS2_Viewport_Previous_clicked();

    void on_checkBox_MS2_ViewportOverlay_clicked();

    void on_pushButton_MS2_Tools_Progress_Corrected_clicked();
    void on_pushButton_MS2_Tools_Progress_Clear_clicked();
    void on_pushButton_MS2_Tools_Progress_Reset_clicked();
    void on_pushButton_MS2_Tools_Progress_ToCorrect_clicked();

    void on_pushButton_MS2_Tools_History_Undo_clicked();
    void on_pushButton_MS2_Tools_History_Redo_clicked();

    void on_pushButton_MS2_Tools_RecordPoints_Start_clicked();
    void on_pushButton_MS2_Tools_RecordPoints_Cancel_clicked();
    void on_pushButton_MS2_Tools_ApplyPoints_Polygon_clicked();
    void on_pushButton_MS2_Tools_ApplyPoints_Ellipse_clicked();
    void on_pushButton_MS2_Tools_ApplyPoints_Remove_clicked();

    void on_spinBox_MS2_ViewerSettings_PointDiameter_1_valueChanged(int arg1);
    void on_spinBox_MS2_ViewerSettings_PointDiameter_2_valueChanged(int arg1);
    void on_spinBox_MS2_ViewerSettings_PointDiameter_3_valueChanged(int arg1);
    void on_spinBox_MS2_ViewerSettings_PointDiameter_4_valueChanged(int arg1);

    void on_pushButton_MS2_Viewport_NextToCorrect_clicked();
    void on_pushButton_MS2_Viewport_NextSegment_clicked();

    void on_spinBox_MS2_Viewport_X_valueChanged(int arg1);
    void on_spinBox_MS2_Viewport_Y_valueChanged(int arg1);
    void on_spinBox_MS2_Viewport_T_valueChanged(int arg1);

    void on_progressBar_MS2_CorrectionProgress_valueChanged(int value);

    void on_pushButton_MS2_Tools_ApplyPoints_ConvexHull_clicked();
    void on_pushButton_MS2_Tools_ApplyPoints_Points_clicked();
    void on_pushButton_MS2_Tools_ApplyPoints_Merge_clicked();
    void on_pushButton_MS2_Tools_ApplyPoints_Separate_clicked();
    void on_pushButton_MS2_Tools_ApplyPointsParam_PointsBigger_clicked();
    void on_pushButton_MS2_Tools_ApplyPointsParam_PointsSmaller_clicked();

    void on_radioButton_MS2_Mode_ToDo_clicked(bool checked);
    void on_radioButton_MS2_Mode_Detailed_clicked(bool checked);
    void on_checkBox_MS2_ToDo_StateBorders_clicked();
    void on_checkBox_MS2_ToDo_StateMarkers_clicked();
    void on_checkBox_MS2_ToDo_SegmentBorders_clicked();
    void on_checkBox_MS2_ToDo_DetectionsOverlay_clicked();
    void on_pushButton_MS2_ToDo_HoveredToOk_clicked();
    void on_pushButton_MS2_ToDo_HoveredToUnknown_clicked();

private:
    void                        MS2_init_ui();
    const static size_t         MS2_ViewersCount = 4;
    const static size_t         MS2_ViewersChannels = 3; //sorted bgr
    int                         MS2_ViewerMaximized = -1;

    //ui elments
    D_Viewer                    MS2_Viewer1;
    D_Viewer                    MS2_Viewer2;
    D_Viewer                    MS2_Viewer3;
    D_Viewer                    MS2_Viewer4;
    D_Viewer                    MS2_Viewer_Viewport;
    D_Viewer                    MS2_Viewer_ToDo;
    vector<D_Viewer*>           v_MS2_Viewer;
    vector<QPushButton*>        v_MS2_PUB_Viewer_Maximize;
    vector<QPushButton*>        v_MS2_PUB_Viewer_PointColor;
    vector<vector<QComboBox*>>  vv_MS2_COB_ViewerChannel_Image_viewer_bgr;
    vector<vector<QComboBox*>>  vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr;
    vector<QCheckBox*>          v_MS2_CHB_Viewer_Transform;
    vector<QCheckBox*>          v_MS2_CHB_Viewer_SegmentBox;
    vector<QCheckBox*>          v_MS2_CHB_Viewer_ConnectZoom;
    vector<QGroupBox*>          v_MS2_GRB_Viewer_GroupAll;
    vector<QGroupBox*>          v_MS2_GRB_Viewer_GroupSettings;

    vector<QPushButton*>        v_MS2_PUB_DrawModi;

    //remember stuff for ui
    vector<QColor>              v_MS2_COL_Viewer_PointColor;

    //images to show
    vector<Mat>                 v_MS2_MA_Images2Show;
    Mat                         MA_MS2_ViewportShow;
    Mat                         MA_MS2_ToDo_Static;
    Mat                         MA_MS2_ToDo_Highlight;

    //channel images
    vector<Mat>                 v_MS2_MA_ChannelsImage_Full;
    vector<Mat>                 v_MS2_MA_ChannelsImage_Croped;
    vector<Mat>                 v_MS2_MA_ChannelsOverlay_Croped;

    //DIRs in
    QDir                        DIR_MS2_In_Master;
    QDir                        DIR_MS2_In_Detections;
    QDir                        DIR_MS2_In_Mosaik;
    vector<QDir>                vDIR_MS2_In_MosaikChannels;
    vector<vector<QDir>>        vvDIR_MS2_In_Detections_TimesNuclei;

    //DIRs out
    QDir                        DIR_MS2_Out_Master;
    QDir                        DIR_MS2_Out_DetectionsCorrected;

    //data
    double                              MS2_MosaikImageScale;
    double                              MS2_MosaikBorderPrz;
    int                                 MS2_MosaikImageWidth;
    int                                 MS2_MosaikImageHeight;
    vector<vector<D_Bio_NucleusImage>>  vv_MS2_NucImg_In_mosaikXY;
    vector<vector<D_Bio_NucleusImage>>  vv_MS2_NucImg_Out_mosaikXY;
    vector<vector<size_t>>              vv_MS2_NucImg_State_In_mosaikXY;
    vector<vector<size_t>>              vv_MS2_NucImg_State_Out_mosaikXY;

    //viewport pos
    Point                               MS2_ViewportOffset_NotScaled = Point(0,0);
    Point                               MS2_ViewportOffset_Scaled = Point(0,0);

    //drawing
    size_t                              MS2_draw_mode = MS2_DRAW_MODE_NUCLEI;
    void                                MS2_Draw_Save();
    void                                MS2_Draw_Clear();
    void                                MS2_Draw_Reset();
    void                                MS2_Draw_SetProcessed();
    void                                MS2_Draw_SetToProcess();
    void                                MS2_Draw_UpdateUi();
    void                                MS2_Draw_RecordingStart();
    void                                MS2_Draw_RecordingEnd();
    void                                MS2_Draw_Ellipse();
    void                                MS2_Draw_Polygon();
    void                                MS2_Draw_ConvexHull();
    void                                MS2_Draw_Points();
    void                                MS2_Draw_SeparateObject();
    void                                MS2_Draw_MergeObjects();
    void                                MS2_Draw_Contour(vector<Point> contour);
    void                                MS2_Draw_Remove();

    //drawing editing backups
    const size_t                                MS2_DetOutBackup_Count = 20;
    bool                                        MS2_DetOutBackup_Init();
    void                                        MS2_DetOutBackup_Save();
    bool                                        MS2_DetOutBackup_Undo();
    bool                                        MS2_DetOutBackup_Redo();
    void                                        MS2_DetOutBackup_UpdateUi();
    vector<vector<vector<D_Bio_NucleusImage>>>  vvv_MS2_DetectionsOutBackups_XYI;
    vector<vector<size_t>>                      vvv_MS2_DetectionsOut_BackupCursor;
    vector<vector<size_t>>                      vvv_MS2_DetectionsOut_BackupValidMax;

    //to do list / fast editing
    void                                MS2_ToDo_SetFinished();
    void                                MS2_ToDo_SetFinished(int x, int y);
    void                                MS2_ToDo_SetToBeEdited();
    void                                MS2_ToDo_SetToBeEdited(int x, int y);

    //Event List
    bool                MS2_EventList_FileSet           = false;
    QFileInfo           MS2_EventList_File;
    QStringList         MS2_EventList_Events;
    const int           MS2_EventList_CursorOffset       = 6;
    bool                MS2_EventList_ReadEventValid    = false;


    //states
    bool                        state_MS2_data_loaded = false;
    bool                        state_MS2_detections_loaded = false;
    bool                        state_MS2_backups_init = false;
    bool                        state_MS2_todo_static_img_created = false;

    enum MS2_EDITING_MODE {
        MS2_MODE_DETAILED,
        MS2_MODE_TO_DO,
        MS2_MODE_NUMBER_OF
    };

    enum MS2_CHANNELS_MOSAIK {
        MS2_CH_MOSAIK_DIC,
        MS2_CH_MOSAIK_GFP,
        MS2_CH_MOSAIK_RFP,
        MS2_CH_MOSAIK_NUMBER_OF
    };
    const QStringList QSL_MS2_ChannelsMosaik = {
        "DIC",
        "GFP",
        "RFP"
    };

    enum MS2_CHANNELS_IMAGE {
        MS2_CH_IMG_EMPTY,
        MS2_CH_IMG_DIC,
        MS2_CH_IMG_GFP,
        MS2_CH_IMG_RFP,
        MS2_CH_IMG_DET_IN,
        MS2_CH_IMG_NUMBER_OF
    };
    const QStringList QSL_MS2_ChannelsImage = {
        "empty",
        "DIC",
        "GFP",
        "RFP",
        "Detections in"
    };

    enum MS2_CHANNELS_OVERLAY {
        MS2_CH_OVR_EMPTY,
        MS2_CH_OVR_NUCLEI,
        MS2_CH_OVR_FOCI_GFP,
        MS2_CH_OVR_FOCI_RFP,
        MS2_CH_OVR_FOCI_BOTH,
        MS2_CH_OVR_NUMBER_OF
    };
    const QStringList QSL_MS2_ChannelsOverlay = {
        "empty",
        "Nuclei",
        "Foci GFP",
        "Foci RFP",
        "Foci both"
    };

    enum MS2_IMAGE_STATE {
        MS2_IMG_STATE_NOT_FOUND,
        MS2_IMG_STATE_LOADED,
        MS2_IMG_STATE_TO_PROCESS,
        MS2_IMG_STATE_PROCESSED,
        MS2_IMG_STATE_NUMBER_OF
    };

    enum MS2_DRAW_MODE {
        MS2_DRAW_MODE_NUCLEI,
        MS2_DRAW_MODE_FOCI_GFP,
        MS2_DRAW_MODE_FOCI_RFP,
        MS2_DRAW_MODE_FOCI_BOTH,
        MS2_DRAW_MODE_NUMBER_OF
    };
    const QStringList QSL_MS2_DrawMode = {
        "nuclei",
        "GFP",
        "RFP",
        "GFP and RFP"
    };

    //-------------------------------------------------------------------- MS3 ----------------------------------------------------

private slots:

    void on_comboBox_MS3_ImgProc_ProjectZ_Stat_currentIndexChanged(int index);
    void on_doubleSpinBox_MS3_ImgProc_Vis_Intensity_Overlay_valueChanged(double arg1);
    void on_doubleSpinBox_MS3_ImgProc_Vis_Intensity_Background_valueChanged(double arg1);
    void on_doubleSpinBox_MS3_ImgProc_DuplicateRelThres_valueChanged(double arg1);
    void on_spinBox_MS3_ImgProc_Vis_Other_Min_valueChanged(int arg1);
    void on_spinBox_MS3_ImgProc_Vis_Other_Max_valueChanged(int arg1);
    void on_doubleSpinBox_MS3_ImgProc_Vis_Other_Gamma_valueChanged(double arg1);
    void on_spinBox_MS3_ImgProc_Vis_GFP_Min_valueChanged(int arg1);
    void on_spinBox_MS3_ImgProc_Vis_GFP_Max_valueChanged(int arg1);
    void on_doubleSpinBox_MS3_ImgProc_Vis_GFP_Gamma_valueChanged(double arg1);
    void on_spinBox_MS3_ImgProc_Vis_RFP_Min_valueChanged(int arg1);
    void on_spinBox_MS3_ImgProc_Vis_RFP_Max_valueChanged(int arg1);
    void on_doubleSpinBox_MS3_ImgProc_Vis_RFP_Gamma_valueChanged(double arg1);

    void on_comboBox_MS3_ImgProc_StepShow_currentIndexChanged(int index);

    void on_spinBox_DataDim_X_valueChanged(int arg1);
    void on_spinBox_DataDim_Y_valueChanged(int arg1);
    void on_spinBox_DataDim_T_valueChanged(int arg1);


private:

    void MS3_UiInit();
    bool MS3_LoadDirs();
    bool MS3_LoadDetections(size_t t);
    //void MS3_ProcessStack();

    void Update_ImageProcessing_StepFrom_MS3(size_t step_start);
    void Update_ImageProcessing_StepSingle_MS3(size_t step);
    void Update_ImageProcessing_StepSingle_MS3_ReuseProcChainMS1(size_t step);
    void Update_ImageProcessing_StepSingle_MS3_DrawDetections(size_t step);
    void Update_ImageProcessing_StepSingle_MS3_VisualizeResults(size_t step);

    //data
    QDir DIR_MS3_In_Master;
    QDir DIR_MS3_In_DetectionsCorrected;
    vector<vector<D_Bio_NucleusImage>> vv_MS3_NucImg_InCorrected_mosaikXY;
    vector<vector<size_t>> vv_MS3_NucImg_InCorrected_States_mosaikXY;

    //states
    bool state_MS3_data_loaded = false;
    bool state_MS3_stack_processing = false;
    bool state_MS3_detections_loaded = false;

    int MS3_current_loaded_detections_T = -1;

    //Img Proc Step
    enum STEPS_MS3 {
        //Prepare (Load, Stitch, Project)
        STEP_MS3_PRE_LOAD_MAIN,
        STEP_MS3_PRE_LOAD_RIGHT,
        STEP_MS3_PRE_LOAD_BOTTOM,
        STEP_MS3_PRE_LOAD_BOTTOM_RIGHT,
        STEP_MS3_PRE_STITCH,
        STEP_MS3_PRE_BLUR_GAUSS,
        STEP_MS3_PRE_PROJECT_Z,

        //Pick Channels
        STEP_MS3_PCK_OTHER,
        STEP_MS3_PCK_GFP,
        STEP_MS3_PCK_RFP,

        //Visualization
        STEP_MS3_VIS_OTHER,
        STEP_MS3_VIS_GFP,
        STEP_MS3_VIS_RFP,
        STEP_MS3_VIS_PAGES_AS_COLOR_GFP_RFP,
        STEP_MS3_VIS_PAGES_AS_COLOR_ALL,

        //draw detections
        STEP_MS3_VIS_NUCLEI_BORDERS_NO_REMOVE,
        STEP_MS3_VIS_NUCLEI_BORDERS,
        STEP_MS3_VIS_NUCLEI_FILLED_STACK,
        STEP_MS3_VIS_NUCLEI_FILLED_PICKED,
        STEP_MS3_VIS_NUCLEI_FILLED_ALL,
        STEP_MS3_VIS_FOCI_GFP,
        STEP_MS3_VIS_FOCI_RFP,
        STEP_MS3_VIS_FOCI_BOTH,

        //Visualization
        STEP_MS3_VIS_REGIONS,
        STEP_MS3_VIS_REGIONS_BACKGROUND,
        //STEP_MS3_VIS_REGIONS_FOCI_COUNT,

        STEP_MS3_NUMBER_OF
    };
    const QStringList QSL_Steps_MS3 = {
        "pre-0 Load main image",
        "pre-1 Load border image R",
        "pre-2 Load border image B",
        "pre-3 Load border image BR",
        "pre-4 Stitch borders to main image",
        "pre-5 Blur gaussian",
        "pre-6 Z-Projection",

        "pck-0 OTHER pick signal",
        "pck-1 GFP pick signal",
        "pck-2 RFP pick Signal",

        "vis-0 visualize OTHER",
        "vis-1 visualize GFP",
        "vis-2 visualize RFP",
        "vis-3 Color GFP and RFP",
        "vis-4 Color all channels",

        "draw-0 Nuclei Borders (without remove duplicates)",
        "draw-1 Nuclei Borders",
        "draw-2 Nuclei Filled (stacked)",
        "draw-2 Nuclei Filled (picked)",
        "draw-2 Nuclei Filled (projected all)",
        "draw-3 Foci GFP",
        "draw-4 Foci RFP",
        "draw-5 Foci Both",

        "vis-5 Regions",
        "vis-6 Regions with background"
        //"vis-7 Regions with foci counts"
    };

    enum MS3_PARAMS {
        MS3_PARAM_PRE5_BLUR_SIZE,
        MS3_PARAM_PRE5_BLUR_SIGMA,
        MS3_PARAM_PRE6_STAT,
        MS3_PARAM_VIS0_NUC_MIN,
        MS3_PARAM_VIS0_NUC_MAX,
        MS3_PARAM_VIS0_NUC_GAMMA,
        MS3_PARAM_VIS1_GFP_MIN,
        MS3_PARAM_VIS1_GFP_MAX,
        MS3_PARAM_VIS1_GFP_GAMMA,
        MS3_PARAM_VIS2_RFP_MIN,
        MS3_PARAM_VIS2_RFP_MAX,
        MS3_PARAM_VIS2_RFP_GAMMA,
        MS3_PARAM_VIS6_INTENSITY_OVERLAY,
        MS3_PARAM_VIS6_INTENSITY_BACKGROUND,
        MS3_PARAM_OTHER_DUPLICATE_OVERLAP,
        MS3_PARAM_NUMBER_OF
    };

    const QStringList QSL_MS3_Params = {
        "MS3_PARAM_PRE5_BLUR_SIZE",
        "MS3_PARAM_PRE5_BLUR_SIGMA",
        "MS3_PARAM_PRE6_STAT",
        "MS3_PARAM_VIS0_NUC_MIN",
        "MS3_PARAM_VIS0_NUC_MAX",
        "MS3_PARAM_VIS0_NUC_GAMMA",
        "MS3_PARAM_VIS1_GFP_MIN",
        "MS3_PARAM_VIS1_GFP_MAX",
        "MS3_PARAM_VIS1_GFP_GAMMA",
        "MS3_PARAM_VIS2_RFP_MIN",
        "MS3_PARAM_VIS2_RFP_MAX",
        "MS3_PARAM_VIS2_RFP_GAMMA",
        "MS3_PARAM_VIS6_INTENSITY_OVERLAY",
        "MS3_PARAM_VIS6_INTENSITY_BACKGROUND",
        "MS3_PARAM_OTHER_DUPLICATE_OVERLAP"
    };


    //-------------------------------------------------------------------- MS4 ----------------------------------------------------

private:

    //data
    QDir DIR_MS4_In_Master;
    QDir DIR_MS4_In_DetectionsAssigned;
    QDir DIR_MS4_Out_NucleiLifes;

    D_Bio_NucleusPedigree MS4_NucPedigree_AutoReconstruct;
    D_Bio_NucleusPedigree MS4_NucPedigree_CleanBackup;

    //viewer
    D_Viewer_Plot_3D MS4_Viewer_Pedigree_Plot3D;
    D_Viewer_3D MS4_Viewer_Pedigree_Volumetric;

    //states
    bool state_MS4_dirs_loaded = false;
    bool state_MS4_detections_loaded_to_pedigree = false;
  //bool state_MS4_pedigree_backup_created = false;
    bool state_MS4_pedigree_init = false;
    bool state_MS4_pedigree_init_1st_time = false;
    bool state_MS4_pedigree_reconstructed = false;

private slots:

    void MS4_UiInit();
    bool MS4_LoadData();
    bool MS4_LoadDirs();
    bool MS4_LoadDetectionsToPedigree();

    //bool MS4_PedigreeBackup_Create();
    //bool MS4_PedigreeBackup_Load();

    bool MS4_SaveData();

    void MS4_DisplayRelativeScoreWeights();
    bool MS4_InitPedigree();
    bool MS4_ReconstructPedigree();
    bool MS4_UpdatePedigreePlot();

    void MS4_CalcVolumetricView_Memory();
    void MS4_CalcOriginalMosaicSize();

    void on_pushButton_MS4_LoadData_clicked();
    void on_pushButton_MS4_SaveData_clicked();
    void on_pushButton_MS4_StartPedigreeReconstruction_clicked();
    void on_pushButton_MS4_UpdatePedigreeView_clicked();
    void on_spinBox_MS4_PedigreeView_Param_Volumetric_SubVolumeSize_X_valueChanged(int arg1);
    void on_spinBox_MS4_PedigreeView_Param_Volumetric_SubVolumeSize_Y_valueChanged(int arg1);
    void on_spinBox_MS4_PedigreeView_Param_Volumetric_SubVolumeSize_T_valueChanged(int arg1);
    void on_spinBox_MS4_PedigreeProp_OriginalImgSize_Single_X_valueChanged(int arg1);
    void on_spinBox_MS4_PedigreeProp_OriginalImgSize_Single_Y_valueChanged(int arg1);

    void on_checkBox_MS4_Score_AdvancedSettings_clicked(bool checked);


    //-------------------------------------------------------------------- MS5 ----------------------------------------------------

private slots:
    void MS5_UiInit();
    bool MS5_LoadAll();
    bool MS5_LoadDirs();
    bool MS5_LoadMosaics();
    bool MS5_LoadNucleiData();
    bool MS5_LoadNucleiLifes();

    bool MS5_SaveData();
    bool MS5_SaveImgStack();

    void MS5_UpdateImages_Basic();
    void MS5_UpdateImages_Highlight();
    void MS5_FindConnectedNucsToDraw(vector<D_Bio_NucleusBlob*>* pvpNucs, vector<size_t> *pvKinshipDegrees, D_Bio_NucleusBlob* pNucCheck, size_t t_min, size_t t_max, size_t kinship_degree = 0);

    bool MS5_CoordTransform_MosaicPx_2_OriginalPx(int* x, int* y);
    void MS5_NucleiHighlight_Select_Viewer0(int x, int y);
    void MS5_NucleiHighlight_Select_Viewer1(int x, int y);
    void MS5_NucleiHighlight_Select_Viewer2(int x, int y);
    void MS5_NucleiHighlight_Select_Viewer3(int x, int y);
    void MS5_NucleiHighlight_Select_Viewer4(int x, int y);
    void MS5_NucleiHighlight_Hover_Viewer0(int x, int y);
    void MS5_NucleiHighlight_Hover_Viewer1(int x, int y);
    void MS5_NucleiHighlight_Hover_Viewer2(int x, int y);
    void MS5_NucleiHighlight_Hover_Viewer3(int x, int y);
    void MS5_NucleiHighlight_Hover_Viewer4(int x, int y);
    void MS5_NucleiHighlight_Select(int x, int y, size_t t);
    void MS5_NucleiHighlight_Hover(int x, int y, size_t t);

    bool MS5_Editing_SelectionCheck();
    void MS5_Editing_SelectionForget();
    void MS5_Editing_ConnectionCheck();
    bool MS5_Editing_ConnectionCreate();
    bool MS5_Editing_ConnectionDelete();
    bool MS5_Editing_Include();
    bool MS5_Editing_Exclude();

    void MS5_EventToS2_SetList();
    void MS5_EventToS2_Start();
    void MS5_EventToS2_Stop();
    void MS5_EventToS2_GetClick_v0(int x, int y);
    void MS5_EventToS2_GetClick_v1(int x, int y);
    void MS5_EventToS2_GetClick_v2(int x, int y);
    void MS5_EventToS2_GetClick_v3(int x, int y);
    void MS5_EventToS2_GetClick_v4(int x, int y);
    void MS5_EventToS2_GetClick(int x, int y, size_t t);
    void MS5_EventToS2_AddEvent();
    void MS5_EventToS2_SaveEventList();

    void MS5_EventS5intern_JumpToNext();
    void MS5_EventS5intern_MoveToVP();
    void MS5_EventS5intern_CountEvents();

    void on_pushButton_MS5_DataLoad_clicked();
    void on_spinBox_MS5_Y_size_valueChanged(int arg1);
    void on_spinBox_MS5_X_size_valueChanged(int arg1);
    void on_pushButton_MS5_DataSave_clicked();
    void on_pushButton_MS5_Editing_ConnectionCreate_clicked();
    void on_pushButton_MS5_Editing_ConnectionDelete_clicked();
    void on_pushButton_MS5_Editing_Exclude_clicked();
    void on_pushButton_MS5_Editing_Include_clicked();
    void on_pushButton_MS5_Editing_ForgetSelection_clicked();

    void on_pushButton_MS5_SaveViewportImageStack_clicked();

    void on_pushButton_MS5_EventS2_RecordStart_clicked();
    void on_pushButton_MS5_EventS2_RecordStop_clicked();

    void on_spinBox_MS5_Events_S5intern_Pos_T_valueChanged(int arg1);
    void on_spinBox_MS5_Events_S5intern_Pos_Y_valueChanged(int arg1);
    void on_spinBox_MS5_Events_S5intern_Pos_X_valueChanged(int arg1);
    void on_pushButton_MS5_Events_S5intern_JumpToNextEvent_clicked();
    void on_spinBox_MS5_Events_S5intern_Draw_Radius_valueChanged(int arg1);
    void on_spinBox_MS5_Events_S5intern_Draw_Thickness_valueChanged(int arg1);
    void on_spinBox_MS5_Events_S5intern_Draw_Red_valueChanged(int arg1);
    void on_spinBox_MS5_Events_S5intern_Draw_Green_valueChanged(int arg1);
    void on_spinBox_MS5_Events_S5intern_Draw_Blue_valueChanged(int arg1);
    void on_pushButton_MS5_Events_S5intern_Draw_SelectColor_clicked();
    void on_pushButton_MS5_Events_S5intern_BackToZero_clicked();
    void on_pushButton_MS5_Events_S5intern_CountEvents_clicked();
    void on_checkBox_MS5_Events_S5intern_AutoUpdateCount_stateChanged(int arg1);
    void on_spinBox_MS5_Events_S5intern_LargeDist_Dist_valueChanged(int arg1);
    void on_spinBox_MS5_Events_S5intern_ShortTracking_Isolated_Duration_valueChanged(int arg1);
    void on_spinBox_MS5_Events_S5intern_ShortTracking_LooseStart_Duration_valueChanged(int arg1);
    void on_spinBox_MS5_Events_S5intern_ShortTracking_LooseEnd_Duration_valueChanged(int arg1);
    void on_spinBox_MS5_Events_S5intern_ShortTracking_BetweenMitoses_Duration_valueChanged(int arg1);
    void on_checkBox_MS5_Events_S5intern_Excluded_stateChanged(int arg1);
    void on_checkBox_Events_S5intern_EventConstraints_AfterT_clicked();
    void on_spinBox_Events_S5intern_EventConstraints_AfterT_Time_valueChanged(int arg1);
    void on_checkBox_Events_S5intern_EventConstraints_BeforeT_clicked();
    void on_spinBox_Events_S5intern_EventConstraints_BeforeT_Time_valueChanged(int arg1);
    void on_checkBox_Events_S5intern_EventConstraints_NotBorder_stateChanged(int arg1);
    void on_spinBox_Events_S5intern_EventConstraints_NotBorder_Size_valueChanged(int arg1);
    void on_checkBox_Events_S5intern_EventConstraints_Mosaik_stateChanged(int arg1);
    void on_spinBox_Events_S5intern_EventConstraints_Mosaik_MaxX_valueChanged(int arg1);
    void on_spinBox_Events_S5intern_EventConstraints_Mosaik_MaxY_valueChanged(int arg1);
    void on_checkBox_Events_S5intern_EventConstraints_NoExcluded_stateChanged(int arg1);
    void on_checkBox_MS5_Events_S5intern_LargeDist_stateChanged(int arg1);
    void on_checkBox_MS5_Events_S5intern_Mitosis_stateChanged(int arg1);
    void on_checkBox_MS5_Events_S5intern_ShortTracking_Isolated_stateChanged(int arg1);
    void on_checkBox_MS5_Events_S5intern_ShortTracking_LooseStart_stateChanged(int arg1);
    void on_checkBox_MS5_Events_S5intern_ShortTracking_LooseEnd_stateChanged(int arg1);
    void on_checkBox_MS5_Events_S5intern_ShortTracking_BetweenMitoses_stateChanged(int arg1);

private:
    static void MS5_CalcImage_Thread(Mat *pMA_out, vector<vector<Mat> > *pvv_imgs_ct, D_Bio_NucleusPedigree *pPedigree, size_t t, size_t y_min_mosaic, size_t y_size_mosaic, size_t x_min_mosaic, size_t x_size_mosaic, bool use_DIC, bool use_GFP, bool use_RFP, bool draw_contour_parent, bool draw_contour_current, bool draw_contour_childs, bool draw_shift_parent, bool draw_shift_childs, bool age_text, bool color_info, size_t ny_mosaic, size_t nx_mosaic, int thickness, double scale);


    //path
    QDir DIR_MS5_Load_Mosaics;
    QDir DIR_MS5_Load_NucleiData;
    QDir DIR_MS5_Load_NucleiLifes;
    QDir DIR_MS5_Out_NucleiLifes;

    //data mosaics
    enum MS5_MOSAIC_CHANNELS {
        MS5_MOSAIC_CH_RFP,
        MS5_MOSAIC_CH_GFP,
        MS5_MOSAIC_CH_DIC,
        MS5_MOSAIC_CH_NUMBER_OF
    };
    const QStringList QSL_MS5_MosaicChannels = {
        "RFP",
        "GFP",
        "DIC"
    };
    vector<vector<Mat>> vv_MS5_Mosaics_CT;

    //data pedigree
    D_Bio_NucleusPedigree MS5_NucPedigree_Editing;

    //Viewers
    const size_t        MS5_ViewersCount = 5;
    D_Viewer            MS5_Viewer_T0;
    D_Viewer            MS5_Viewer_T1;
    D_Viewer            MS5_Viewer_T2;
    D_Viewer            MS5_Viewer_T3;
    D_Viewer            MS5_Viewer_T4;
    vector<D_Viewer*>   v_MS5_Viewers_T;
    vector<QLabel*>     v_MS5_ViewerLabels_T;
    vector<Mat>         v_MS5_MAs_ShowBasic;
    vector<Mat>         v_MS5_MAs_ShowHighlight;

    //highlighted nuclei
    vector<D_Bio_NucleusBlob*> v_MS5_pNuc_Highlighted;
    enum MS5_NUC_HIGHLIGHT {
        MS5_NUC_HIGHLIGHT_SELECT1,
        MS5_NUC_HIGHLIGHT_SELECT2,
        MS5_NUC_HIGHLIGHT_HOVERED,
        MS5_NUC_HIGHLIGHT_NUMBER_OF
    };

    //EventToS2
    bool                MS5_EventToS2_FileSet           = false;
    bool                MS5_EventToS2_Recording         = false;
    int                 MS5_EventToS2_ClicksRecorded    = 0;
    double              MS5_EventToS2_Click_Time        = 0;
    Point               MS5_EventToS2_Click_Point       = Point(0,0);
    double              MS5_EventToS2_Click_Radius      = 0;
    QFileInfo           MS5_EventToS2_File;
    QStringList         MS5_EventToS2_Events;

    //Events S5 intern
    bool                MS5_EventS5intern_EventActive   = false;

    //states
    bool                MS5_state_loaded_all = false;
    bool                MS5_state_loaded_dirs = false;
    bool                MS5_state_loaded_mosaics = false;
    bool                MS5_state_loaded_nuc_data = false;
    bool                MS5_state_loaded_nuc_lifes = false;
    bool                MS5_state_imgs_shown_at_lesast_once = false;


    //-------------------------------------------------------------------- MS6 ----------------------------------------------------

private slots:
    void MS6_UiInit();

    void MS6_UpdateViews();

    bool MS6_LoadAll();
    bool MS6_LoadDirs();
    bool MS6_LoadMosaics();
    bool MS6_LoadNucleiData();
    bool MS6_LoadNucleiLifes();

    bool MS6_GetChannelsFromUi();
    bool MS6_GetIrradiationTimeFromUi();
    bool MS6_GetRangeXYFromUi();

    void            MS6_ResAxis_UpdateModi();
    void            MS6_ResAxis_SetMode(size_t i_axis, QString axis_description, size_t i_mode);
    vector<double>  MS6_DataForAxis(size_t i_axis);
    size_t          MS6_Data_ChannelIndex(size_t i_axis);
    QString         MS6_Data_ChannelSuffix(size_t i_axis);
    QString         MS6_DefaultTitle_Result();
    QString         MS6_DefaultTitle_Series();
    QString         MS6_DefaultTitle_Axis_NoChanelSuffix(size_t i_axis);
    QString         MS6_DefaultTitle_Axis(size_t i_axis);

    void MS6_Update_Results();
    void MS6_Update_Result_HistSimple();
    void MS6_Update_Result_PoolStatLine_Single();
    void MS6_Update_Result_PoolStatLine_DualWithError();
    void MS6_Update_Result_Scatter_2D();
    void MS6_Update_Result_Heatmap_2D();
    void MS6_Update_Result_Heatmap_3D();
    void MS6_Update_Result_DataTable_3Axis();
    void MS6_Update_Result_MosaicData();
    void MS6_Update_Result_NucLifeImg();

    bool MS6_Save_Result_Current();
    bool MS6_Save_NucLifes();
    bool MS6_Save_StatisticAnalysis();

    void on_pushButton_MS6_LoadData_clicked();

    void on_checkBox_MS6_ResType_Param_PoolStatLine_AutoRange_clicked(bool checked);
    void on_checkBox_MS6_ResType_Params_ScatterHeatmap_ManuelRange_x_clicked(bool checked);
    void on_checkBox_MS6_ResType_Params_ScatterHeatmap_ManuelRange_y_clicked(bool checked);

    void on_spinBox_MS6_MarginToBorder_valueChanged(int arg1);
    void on_doubleSpinBox_MS6_Scale_px2um_valueChanged(double arg1);
    void on_comboBox_MS6_ResultTypes_currentIndexChanged(int index);

    void on_spinBox_MS6_ResType_Params_MosaicData_T_valueChanged(int arg1);

    void on_spinBox_MS6_ResType_Params_NucLifeImg_NucLife_valueChanged(int arg1);

    void on_pushButton_MS6_SaveResult_clicked();
    void on_pushButton_MS6_SaveAnalysis_clicked();
    void on_pushButton_MS6_SaveNucLifes_clicked();





    void on_checkBox_S6_StyleAxis_CustomRange_X_clicked(bool checked);

    void on_checkBox_S6_StyleAxis_CustomRange_Y_clicked(bool checked);

    void on_checkBox_S6_StyleAxis_CustomRange_Z_clicked(bool checked);

    void on_checkBox_S6_StyleAxis_CustomTitle_X_clicked(bool checked);

    void on_checkBox_S6_StyleAxis_CustomTitle_Y_clicked(bool checked);

    void on_checkBox_S6_StyleAxis_CustomTitle_Z_clicked(bool checked);

    void on_checkBox_S6_SytleGeneral_CustomTitle_clicked(bool checked);

    void on_checkBox_S6_SytleGeneral_CustomSeries_clicked(bool checked);

    void on_verticalSlider_MS6_ResSize_valueChanged(int value);

    void on_horizontalSlider_MS6_ResSize_valueChanged(int value);

    void on_checkBox_MS6_ResType_Param_PoolStatLine_DualErr_AutoRange_clicked(bool checked);

    void on_pushButton_MS6_DefaultPlot_FociVsTime_clicked();

    void on_pushButton_MS6_DefaultPlot_FociVsTime_WithError_clicked();

    void on_pushButton_MS6_DefaultPlot_FociVsTimeAndCellCycle_clicked();

    void on_pushButton_MS1_UdateImgProc_Single_clicked();

    void on_pushButton_MS1_UdateImgProc_All_clicked();

    void on_pushButton_MS1_UdateImgProc_ThisToEnd_clicked();

private:

    //Data
    D_Bio_NucleusPedigree   MS6_NucPedigree_Results;

    //channels
    QStringList             MS6_QSL_Channels_Values;
    QStringList             MS6_QSL_Channels_Foci;

    //Dirs
    QDir                    DIR_MS6_Load_Mosaics;
    QDir                    DIR_MS6_Load_NucleiData;
    QDir                    DIR_MS6_Load_NucleiLifes;
    QDir                    DIR_MS6_Out_SaveAnalysisMaster;

    //mosaics
    enum MS6_MOSAIC_CHANNELS {
        MS6_MOSAIC_CH_RFP,
        MS6_MOSAIC_CH_GFP,
        MS6_MOSAIC_CH_DIC,
        MS6_MOSAIC_CH_NUMBER_OF
    };
    const QStringList QSL_MS6_MosaicChannels = {
        "RFP",
        "GFP",
        "DIC"
    };
    vector<vector<Mat>>     vv_MS6_Mosaics_CT;

    //ui elements for axis control
    const size_t            MS6_ResAxis_Count = 3;
    vector<QLabel*>         MS6_vL_ResAxis_Description;
    vector<QComboBox*>      MS6_vCB_ResAxis_Level_Foc;
    vector<QComboBox*>      MS6_vCB_ResAxis_Level_NucBlob;
    vector<QComboBox*>      MS6_vCB_ResAxis_Level_NucLife;
    vector<QComboBox*>      MS6_vCB_ResAxis_Attrib_Foc;
    vector<QComboBox*>      MS6_vCB_ResAxis_Attrib_NucBlob;
    vector<QComboBox*>      MS6_vCB_ResAxis_Attrib_NucLife;
    vector<QComboBox*>      MS6_vCB_ResAxis_Stat_low;
    vector<QComboBox*>      MS6_vCB_ResAxis_Stat_high;
    vector<QComboBox*>      MS6_vCB_ResAxis_FocChannel;
    vector<QComboBox*>      MS6_vCB_ResAxis_AttribChannel_Val;
    vector<QComboBox*>      MS6_vCB_ResAxis_AttribChannel_Foc;
    vector<QStackedWidget*> MS6_cSW_ResAxis_Level;
    vector<QStackedWidget*> MS6_cSW_ResAxis_Attrib;
    vector<QStackedWidget*> MS6_cSW_ResAxis_Stat_low;
    vector<QStackedWidget*> MS6_cSW_ResAxis_Stat_high;
    vector<QStackedWidget*> MS6_cSW_ResAxis_FocChannel;
    vector<QStackedWidget*> MS6_cSW_ResAxis_AttribChannel;

    //viewer elements
    QChartView*             MS6_pChartView_Plot_2D;
    D_Viewer_Plot_3D        MS6_Viewer_Plot_3D;
    D_Viewer                MS6_Viewer_Img_2D;
    D_Viewer_3D             MS6_Viewer_Img_3D;
    D_Table                 MS6_Viewer_Table;
    Mat                     MS6_ResultImgShow;

    //States
    bool                    MS6_state_ui_init = false;
    bool                    MS6_state_loaded_all = false;
    bool                    MS6_state_loaded_dirs = false;
    bool                    MS6_state_loaded_mosaics = false;
    bool                    MS6_state_loaded_nuc_data = false;
    bool                    MS6_state_loaded_nuc_lifes = false;


    enum MS6_RES_VIEW_TYPE {
        MS6_RES_VIEW_TYPE_PLOT_2D,
        MS6_RES_VIEW_TYPE_PLOT_3D,
        MS6_RES_VIEW_TYPE_IMAGE_2D,
        MS6_RES_VIEW_TYPE_IMAGE_3D,
        MS6_RES_VIEW_TYPE_TABLE,
        MS6_RES_VIEW_TYPE_ERROR,
        MS6_RES_VIEW_TYPE_NUMBER_OF
    };


    enum MS6_RESULT_TYPES {
        MS6_RES_TYP_HIST_SIMPLE,
        MS6_RES_TYP_POOL_STAT_LINE_SINGLE,
        MS6_RES_TYP_POOL_STAT_LINE_DUAL_WITH_ERROR,
        MS6_RES_TYP_SCATTER_2D_SIMPLE,
        MS6_RES_TYP_SCATTER_HEATMAP_2D,
        MS6_RES_TYP_SCATTER_HEATMAP_3D,
        MS6_RES_TYP_DATA_TABLE_3D,
        MS6_RES_TYP_MOSAIC_DATA,
        MS6_RES_TYP_NUC_LIFE_IMG,
        MS6_RES_TYP_NUMBER_OF
    };
    const QStringList QSL_MS6_ResultTypes = {
        "Histogram simple",
        "Pooled statistic line single",
        "Pooled statistic line dual with error",
        "Scatter 2D simple",
        "Scatter 2D heatmap",
        "Scatter 3D heatmap",
        "Data table 3 attributes",
        "Mosaic with foci counts",
        "Nucleus life image"
    };


    enum MS6_RES_AXIS_MODE {
        MS6_RES_AXIS_MODE_NONE,
        MS6_RES_AXIS_MODE_NUCLIFE,
        MS6_RES_AXIS_MODE_NUCBLOB,
        MS6_RES_AXIS_MODE_FOC,
        MS6_RES_AXIS_MODE_NUMBER_OF
    };
    const QStringList QSL_MS6_ResAxisMode {
        "None",
        "Nuc Life",
        "Nuc Blob",
        "Foc"
    };


    enum MS6_RES_AXIS_STAT {
        MS6_RES_AXIS_STAT_OFF,
        MS6_RES_AXIS_STAT_ON,
        MS6_RES_AXIS_STAT_NUMBER_OF
    };
    const QStringList QSL_MS6_ResAxisStat = {
        "on",
        "off"
    };


    enum MS6_RES_AXIS_CHANNEL_FOC {
        MS6_RES_AXIS_CHANNEL_FOC_OFF,
        MS6_RES_AXIS_CHANNEL_FOC_ON,
        MS6_RES_AXIS_CHANNEL_FOC_NUMBER_OF
    };
    const QStringList QSL_MS6_ResAxisChannel_Foc = {
        "off",
        "on"
    };

    enum MS6_RES_AXIS_CHANNEL_ATTRIB {
        MS6_RES_AXIS_CHANNEL_ATTRIB_OFF,
        MS6_RES_AXIS_CHANNEL_ATTRIB_ON_VAL,
        MS6_RES_AXIS_CHANNEL_ATTRIB_ON_FOC,
        MS6_RES_AXIS_CHANNEL_ATTRIB_NUMBER_OF
    };
    const QStringList QSL_MS6_ResAxisChannel_Attrib = {
        "off",
        "value",
        "foci"
    };


    //attrib lvl
    enum MS6_RES_AXIS_ATTRIB {
        MS6_RES_AXIS_ATTRIB_EMPTY,
        MS6_RES_AXIS_ATTRIB_NUCLIFE,
        MS6_RES_AXIS_ATTRIB_NUCBLOB,
        MS6_RES_AXIS_ATTRIB_FOC,
        MS6_RES_AXIS_ATTRIB_NUMBER_OF
    };
    const QStringList QSL_MS6_ResAttribLevel = {
        "None",
        "Nuc life",
        "Nuc blob",
        "Foc"
    };

};

#endif // D_MAKRO_MEGAFOCI_H
