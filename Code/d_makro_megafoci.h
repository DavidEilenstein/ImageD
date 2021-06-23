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

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

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
    void Update_ImageProcessing_StepSingle(size_t step);

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

    //img proc prepare
    void on_doubleSpinBox_ImgProc_Stitch_Border_valueChanged(double arg1);
    void on_comboBox_ImgProc_ProjectZ_Stat_currentIndexChanged(int index);

    //img proc nuclei
    void on_doubleSpinBox_ImgProc_Nuc_AreaMin_valueChanged(double arg1);
    void on_doubleSpinBox_ImgProc_Nuc_AreaMax_valueChanged(double arg1);
    void on_doubleSpinBox_ImgProc_Nuc_RFP_SignalMeanMin_valueChanged(double arg1);
    void on_spinBox_ImgProc_Nuc_GFP_BlurMedianSize_valueChanged(int arg1);
    void on_spinBox_ImgProc_Nuc_GFP_EdgeCVSize_valueChanged(int arg1);
    void on_doubleSpinBox_ImgProc_Nuc_GFP_ThresEdges_valueChanged(double arg1);
    void on_spinBox_ImgProc_Nuc_ErodeBorder_valueChanged(int arg1);
    void on_doubleSpinBox_ImgProc_Nuc_GFP_DistThres_valueChanged(double arg1);
    void on_checkBox_ImgProc_Nuc_Watershed_NonSeed_stateChanged(int arg1);
    void on_checkBox_ImgProc_Nuc_Watershed_ExBordered_stateChanged(int arg1);
    void on_doubleSpinBox_ImgProc_Nuc_RoundnesMin_valueChanged(double arg1);

    //img proc foci gfp
    void on_spinBox_ImgProc_Foc_GFP_BlurMedianSize_valueChanged(int arg1);
    void on_spinBox_ImgProc_Foc_GFP_BinarySize_valueChanged(int arg1);
    void on_doubleSpinBox_ImgProc_Foc_GFP_BinaryOffset_valueChanged(double arg1);
    void on_doubleSpinBox_ImgProc_Foc_GFP_AreaMin_valueChanged(double arg1);
    void on_doubleSpinBox_ImgProc_Foc_GFP_AreaMax_valueChanged(double arg1);
    void on_doubleSpinBox_ImgProc_Foc_GFP_BinarySigma_valueChanged(double arg1);

    //img proc foci rfp
    void on_spinBox_ImgProc_Foc_RFP_BlurMedianSize_valueChanged(int arg1);
    void on_spinBox_ImgProc_Foc_RFP_BinarySize_valueChanged(int arg1);
    void on_doubleSpinBox_ImgProc_Foc_RFP_BinaryOffset_valueChanged(double arg1);
    void on_doubleSpinBox_ImgProc_Foc_RFP_AreaMin_valueChanged(double arg1);
    void on_doubleSpinBox_ImgProc_Foc_RFP_AreaMax_valueChanged(double arg1);
    void on_doubleSpinBox_ImgProc_Foc_RFP_BinarySigma_valueChanged(double arg1);

    void on_spinBox_DataDim_P_exist_valueChanged(int arg1);

    void on_doubleSpinBox_ImgProc_Vis_BackgroundQuantil_low_valueChanged(double arg1);
    void on_doubleSpinBox_ImgProc_Vis_BackgroundQuantil_high_valueChanged(double arg1);

    void on_doubleSpinBox_ImgProc_Foc_Both_AreaMin_valueChanged(double arg1);
    void on_doubleSpinBox_ImgProc_Foc_Both_AreaMax_valueChanged(double arg1);

    void on_spinBox_ImgProc_Stitch_Overlap_x_valueChanged(int arg1);
    void on_spinBox_ImgProc_Stitch_Overlap_y_valueChanged(int arg1);

    void on_doubleSpinBox_ImgProc_Vis_Intensity_Background_valueChanged(double arg1);
    void on_doubleSpinBox_ImgProc_Vis_Intensity_Overlay_valueChanged(double arg1);

    void on_pushButton_StepMajor_1_clicked();
    void on_pushButton_StepMajor_2_clicked();
    void on_pushButton_StepMajor_3_clicked();
    void on_pushButton_StepMajor_4_clicked();
    void on_pushButton_StepMajor_5_clicked();
    void on_pushButton_StepMajor_6_clicked();

    void on_horizontalSlider_OverviewBig_T_valueChanged(int value);

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
    QDir                                DIR_SaveMosaik_AutoDetetctions;
    QDir                                DIR_SaveDetections;

    //dataset dimension
    size_t                              dataset_dim_mosaic_x = 15;
    size_t                              dataset_dim_mosaic_y = 15;
    size_t                              dataset_dim_mosaic_xy = 15 * 15;
    size_t                              dataset_dim_z = 8;
    size_t                              dataset_dim_t = 49;
    size_t                              dataset_dim_xyt = 15 * 15 * 49;
    size_t                              dataset_dim_p_used = 2;
    size_t                              dataset_dim_p_exist = 3;
    size_t                              dataset_dim_tzp_used = 49 * 8 * 2;
    size_t                              dataset_dim_tzp_exist = 49 * 8 * 3;
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
        //Prepare (Load, Stitch, Project)
        STEP_PRE_LOAD_MAIN,
        STEP_PRE_LOAD_RIGHT,
        STEP_PRE_LOAD_BOTTOM,
        STEP_PRE_LOAD_BOTTOM_RIGHT,
        STEP_PRE_STITCH,
        STEP_PRE_PROJECT_Z,

        //Pick Channels
        STEP_PCK_OTHER,
        STEP_PCK_GFP,
        STEP_PCK_RFP,

        //Visualization
        STEP_VIS_PAGES_AS_COLOR_GFP_RFP,
        STEP_VIS_PAGES_AS_COLOR_QUANTILS_GFP_RFP,
        STEP_VIS_PAGES_AS_COLOR_ALL,
        STEP_VIS_PAGES_AS_COLOR_QUANTILS_ALL,

        //Find Nuclei
        STEP_NUC_GFP_BLUR_MEDIAN,
        STEP_NUC_GFP_EDGE_CV,
        STEP_NUC_GFP_BINARY_THRES,
        STEP_NUC_GFP_BINARY_FILL_HOLES,
        STEP_NUC_GFP_BINARY_MORPH_ERODE,
        STEP_NUC_DISTANCE,
        STEP_NUC_SEEDS,
        STEP_NUC_WATERSHED,
        STEP_NUC_SELECT_AREA,
        STEP_NUC_SELECT_ROUNDNESS,
        STEP_NUC_RFP_SELECT_MEAN,

        //Visualization
        STEP_VIS_NUC_BORDERS,

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
        STEP_VIS_REGIONS,
        STEP_VIS_REGIONS_BACKGROUND,
        STEP_VIS_REGIONS_FOCI_COUNT,

        STEP_NUMBER_OF
    };
    const QStringList QSL_Steps = {
        "pre-0 Load main image",
        "pre-1 Load border image R",
        "pre-2 Load border image B",
        "pre-3 Load border image BR",
        "pre-4 Stitch borders to main image",
        "pre-5 Z-Projection",

        "pck-0 OTHER pick signal",
        "pck-1 GFP pick signal",
        "pck-2 RFP pick Signal",

        "vis-0 Color GFP green RFP blue",
        "vis-1 Color GFP RFP crop interquantil",
        "vis-2 Color all channels",
        "vis-3 Color all crop interquantil",

        "nuc-0 GFP circular median blur",
        "nuc-1 GFP circular CV edges",
        "nuc-2 GFP binarize edge image",
        "nuc-3 fill holes in edge image",
        "nuc-4 erode border",
        "nuc-5 distance transformation",
        "nuc-6 nuclei segmentation seeds",
        "nuc-7 watershed segmentation",
        "nuc-8 Select by Area",
        "nuc-9 Select by Roundness",
        "nuc-10 Select by Mean RFP Signal",

        "vis-4 Nuclei segemntation borders",

        "foc-gfp-0 circular median blur",
        "foc-gfp-1 binarize by threshold",
        "foc-gfp-2 Select by Area",

        "foc-rfp-0 circular median blur",
        "foc-rfp-1 binarize by threshold",
        "foc-rfp-2 Select by Area",

        "foc-both-0 foci detected in GFP and RFP",
        "foc-both-0 Select by Area",

        "cla-0 Foci in at least one channel",
        "cla-1 Foci in one channel only",
        "cla-2 Foci in GFP only",
        "cla-3 Foci in RFP only",

        "vis-5 Regions",
        "vis-6 Regions with background",
        "vis-7 Regions with foci counts"
    };

    //Tabs
    enum TABS_CONTROL {
        TAB_CONTROL_VIEWPORT,
        TAB_CONTROL_IMG_PROC,
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
        OVERVIEW_TYPE_AUTODETECT,
        OVERVIEW_TYPE_NUMBER_OF
    };
    const QStringList QSL_OverviewTypes = {
        "Gray DIC",
        "Gray GFP",
        "Gray RFP",
        "Color GFP and RFP",
        "Color auto detections"
    };

    //major steps managment ----------------------------------------------------------

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
        "Dataset definition",
        "Automatic detection",
        "Manuel correction of detetctions",
        "Automatic matching foci to nuclei",
        "Automatic pedigree reconstruction",
        "Manual pedigree correction",
        "Epic analysis"
    };

    size_t mode_major_current = MODE_MAJOR_0_DATASET_DIM;
    void set_ModeMajor_Current(size_t mode);

    //major steps 2 ----------------------------------------------------------

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

    void on_pushButton_MS2_Tools_ProgressToCorrect_clicked();
    void on_pushButton_MS2_Tools_Progress_Corrected_clicked();

    void on_pushButton_MS2_Tools_Channel_Nuclei_clicked();
    void on_pushButton_MS2_Tools_Channel_GFPonly_clicked();
    void on_pushButton_MS2_Tools_Channel_RFPonly_clicked();
    void on_pushButton_MS2_Tools_Channel_GFPandRFP_clicked();

    void on_comboBox_MS2_ViewportBackground_currentIndexChanged(int index);

    void MS2_ViewerMaximize(int v2max);
    void MS2_ViewerPointColor(size_t v2col);
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

    void MS2_UpdateImage_Viewport();

    void MS2_UpdateViewportPos();
    void MS2_InitOverlays();
    void MS2_UpdateOverlays();
    void MS2_UpdateOverlay(size_t overlay_index);


    void MS2_DrawMode_Set(size_t mode);

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

    void on_groupBox_VisTrafo_clicked();

    void on_doubleSpinBox_MS2_Params_NucleusBorderThickness_valueChanged(double arg1);
    void on_doubleSpinBox_MS2_Params_FociMinRadius_valueChanged(double arg1);

    void on_pushButton_MS2_Viewport_Left_clicked();
    void on_pushButton_MS2_Viewport_Right_clicked();
    void on_pushButton_MS2_Viewport_Up_clicked();
    void on_pushButton_MS2_Viewport_Down_clicked();
    void on_pushButton_MS2_Viewport_Next_clicked();
    void on_pushButton_MS2_Viewport_Previous_clicked();

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
    vector<D_Viewer*>           v_MS2_Viewer;
    vector<QPushButton*>        v_MS2_PUB_Viewer_Maximize;
    vector<QPushButton*>        v_MS2_PUB_Viewer_PointColor;
    vector<vector<QComboBox*>>  vv_MS2_COB_ViewerChannel_Image_viewer_bgr;
    vector<vector<QComboBox*>>  vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr;
    vector<QCheckBox*>          v_MS2_CHB_Viewer_Transform;
    vector<QCheckBox*>          v_MS2_CHB_Viewer_ConnectZoom;
    vector<QGroupBox*>          v_MS2_GRB_Viewer_GroupAll;
    vector<QGroupBox*>          v_MS2_GRB_Viewer_GroupSettings;

    vector<QPushButton*>        v_MS2_PUB_DrawModi;

    //remember stuff for ui
    vector<QColor>              v_MS2_COL_Viewer_PointColor;

    //images to show
    vector<Mat>                 v_MS2_MA_Images2Show;
    Mat                         MA_MS2_ViewportShow;

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
    vector<vector<QDir>>        vvDIR_MS2_Out_DetectionsCorrected_TimesNuclei;

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
    Point                       MS2_ViewportOffset_NotScaled = Point(0,0);
    Point                       MS2_ViewportOffset_Scaled = Point(0,0);

    //drawing
    size_t                      MS2_draw_mode = MS2_DRAW_MODE_NUCLEI;

    //states
    bool                        state_MS2_data_loaded = false;
    bool                        state_MS2_detections_loaded = false;



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
        MS2_CH_IMG_NUMBER_OF
    };
    const QStringList QSL_MS2_ChannelsImage = {
        "empty",
        "DIC",
        "GFP",
        "RFP"
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
};

#endif // D_MAKRO_MEGAFOCI_H
