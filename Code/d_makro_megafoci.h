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

    //overladed events
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
    void Update_ImageDecomposition();

    //stack processing
    void Stack_Process_All();
    void Stack_Porcess_Single_XYT_Viewport();

    //populate ui
    void Populate_CB_AtStart();
    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int init_index = 0);

    bool Load_Dataset();
    void Overview_Init();
    void Overview_Update();

    //load image operations
    bool LoadShow_Image_UiSelected();    
    int  Load_Image_full_ZP_Stitched_UiSelected(D_VisDat_Obj *pVD_Target);
    bool Load_Image_UiSelected(Mat *pMA_Target);
    bool Load_Image(Mat *pMA_Target, size_t x, size_t y, size_t z, size_t t, size_t p);
    int  Load_Image_full_ZP(D_VisDat_Obj *pVD_Target, size_t x, size_t y, size_t t);
    int  Load_Image_full_ZP_Stitched(D_VisDat_Obj *pVD_Target, size_t x, size_t y, size_t t);

    //set dims
    void set_dataset_dim_x(int x) {if(!state_dataset_dim_set) {dataset_dim_mosaic_x = x; dataset_dim_mosaic_xy = dataset_dim_mosaic_x * dataset_dim_mosaic_y;}}
    void set_dataset_dim_y(int y) {if(!state_dataset_dim_set) {dataset_dim_mosaic_y = y; dataset_dim_mosaic_xy = dataset_dim_mosaic_x * dataset_dim_mosaic_y;}}
    void set_dataset_dim_t(int t) {if(!state_dataset_dim_set) {dataset_dim_t = t; dataset_dim_tzp = dataset_dim_t * dataset_dim_z * dataset_dim_p;}}
    void set_dataset_dim_z(int z) {if(!state_dataset_dim_set) {dataset_dim_z = z; dataset_dim_tzp = dataset_dim_t * dataset_dim_z * dataset_dim_p;}}

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
    void on_doubleSpinBox_ImgProc_Stitch_Overlap_valueChanged(double arg1);
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


    void on_action_Process_full_stack_triggered();

private:
    Ui::D_MAKRO_MegaFoci *ui;
    bool ClosingPossible = false;

    //error handling
    D_Error_Handler ER;
    void ERR(int err, QString func = "not specified", QString detail = "not specified");

    //Storage
    D_Storage                           *pStore;

    //states
    bool                                state_dataset_dim_set = false;
    bool                                state_dataset_img_list_loaded = false;
    bool                                state_overview_init = false;
    bool                                state_stack_processing = false;
    bool                                state_image_decomposed = false;
    bool                                state_first_proc_on_start = true;

    //data files
    QFileInfoList                       FIL_Images;
    QStringList                         QSL_Images_Paths;
    QStringList                         QSL_Images_Names;
    QStringList                         QSL_Images_Suffix;

    //save dirs
    QDir                                DIR_SaveMaster;
    QDir                                DIR_SaveMosaik;
    QDir                                DIR_SaveDetections;

    //dataset dimension
    size_t                              dataset_dim_mosaic_x = 15;
    size_t                              dataset_dim_mosaic_y = 15;
    size_t                              dataset_dim_mosaic_xy = 15 * 15;
    size_t                              dataset_dim_z = 6;
    size_t                              dataset_dim_t = 42;
    const size_t                        dataset_dim_p = 2;
    size_t                              dataset_dim_tzp = 42 * 6 * 2;
    size_t                              dataset_dim_img_x = 1004;
    size_t                              dataset_dim_img_y = 1002;
    int                                 dataset_type_mat = CV_16UC1;
    int                                 dataset_depth_mat = CV_16U;
    size_t                              get_index_of_image(size_t x, size_t y);
    size_t                              get_index_of_page(size_t z, size_t t, size_t p);

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

    //overview
    double                              overview_scale = 0.10;
    size_t                              overview_SubImgSizeX = overview_scale * dataset_dim_img_x;
    size_t                              overview_SubImgSizeY = overview_scale * dataset_dim_img_y;
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
    enum PAGES {
        PAGE_GFP,
        PAGE_RFP,
        PAGES_NUMBER_OF
    };
    const QStringList QSL_Pages = {
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
        STEP_PCK_P0,
        STEP_PCK_P1,
        //Visualization
        STEP_VIS_PAGES_AS_COLOR,
        //Find Nuclei
        STEP_NUC_P0_BLUR_MEDIAN,
        STEP_NUC_P0_EDGE_CV,
        STEP_NUC_P0_BINARY_THRES,
        STEP_NUC_P0_BINARY_FILL_HOLES,
        STEP_NUC_P0_BINARY_MORPH_ERODE,
        STEP_NUC_DISTANCE,
        STEP_NUC_SEEDS,
        STEP_NUC_WATERSHED,
        STEP_NUC_SELECT_AREA,
        STEP_NUC_SELECT_ROUNDNESS,
        STEP_NUC_P1_SELECT_MEAN,
        STEP_VIS_NUC_BORDERS,
        //Find Foci GFP
        STEP_FOC_P0_BLUR_MEDIAN,
        STEP_FOC_P0_BINARY_THRES,
        STEP_FOC_P0_MASK_IN_NUC,
        STEP_FOC_P0_SELECT_AREA,
        //Find Foci RFP
        STEP_FOC_P1_BLUR_MEDIAN,
        STEP_FOC_P1_BINARY_THRES,
        STEP_FOC_P1_MASK_IN_NUC,
        STEP_FOC_P1_SELECT_AREA,
        //Match Foci
        STEP_FOC_BOTH_INTERSECT,
        STEP_FOC_BOTH_SELECT_AREA,
        //Classification
        STEP_CLA_FOC_ALL,
        STEP_CLA_FOC_IN_ONE_ONLY,
        STEP_CLA_FOC_IN_P0_ONLY,
        STEP_CLA_FOC_IN_P1_ONLY,
        //Visualization
        STEP_VIS_REGIONS,
        STEP_VIS_REGIONS_BACKGROUND,
        STEP_NUMBER_OF
    };
    const QStringList QSL_Steps = {
        "pre-0 Load main image",
        "pre-1 Load border image R",
        "pre-2 Load border image B",
        "pre-3 Load border image BR",
        "pre-4 Stitch borders to main image",
        "pre-5 Z-Projection",

        "pck-0 GFP pick signal",
        "pck-1 RFP pick Signal",

        "vis-0 Color GFP blue RFP green",

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

        "vis-1 Nuclei segemntation borders",

        "foc-gfp-0 circular median blur",
        "foc-gfp-1 binarize by threshold",
        "foc-gfp-2 Mask by selected nuclei",
        "foc-gfp-3 Select by Area",

        "foc-rfp-0 circular median blur",
        "foc-rfp-1 binarize by threshold",
        "foc-rfp-2 Mask by selected nuclei",
        "foc-rfp-3 Select by Area",

        "foc-both-0 foci detected in GFP and RFP",
        "foc-both-0 Select by Area",

        "cla-0 Foci in at least one channel",
        "cla-1 Foci in one channel only",
        "cla-2 Foci in GFP only",
        "cla-3 Foci in RFP only",

        "vis-2 Regions",
        "vis-3 Regions with background"
    };

    //Tabs
    enum TABS_CONTROL {
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

};

#endif // D_MAKRO_MEGAFOCI_H
