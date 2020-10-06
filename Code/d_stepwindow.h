/************************************
 *   added:     11.09.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_STEPWINDOW_H
#define D_STEPWINDOW_H

//own
#include <d_enum.h>
#include <d_viewer.h>
#include <scenemousetrack.h>
#include <d_img_proc.h>
#include <d_storage.h>
#include <d_plot.h>
#include <d_makro_corefoci.h>
#include <d_makro_mitochondrien.h>
#include <d_makro_eilenstein.h>
#include <d_makro_cellcolonies.h>
#include <d_error_handler.h>
#include <m_makro_foci.h>
#include <d_makro_iontracks.h>
#include <d_makro_visualization.h>
#include <d_math.h>
#include <d_visdat_obj.h>
#include <d_visdat_proc.h>
#include <d_popup_listedit.h>
#include <d_videoslicer.h>

//general
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <thread>
//#include <time.h>

//Qt
#include <QApplication>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QRect>
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
#include <QInputDialog>
#include <QDateTime>
#include <QDoubleSpinBox>

//Qt-Charts
#include <QChartView>
#include <QChart>
#include <QValueAxis>
#include <QLineSeries>
#include <QSplineSeries>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/stitching.hpp"

//namespaces
using namespace std;
using namespace cv;
QT_CHARTS_USE_NAMESPACE


namespace Ui {
class D_StepWindow;
}

/*!
 * \brief The D_StepWindow class Represents an image processing step in an image processing chain.
 * \details Any number of these can be created via the D_MainWindow .
 * The basic funcionality is to chose a type of image processing and source image(s) for it.
 * There are some more features like displaying histograms, time measurement, information about its position in the image processing chain, etc.
 */
class D_StepWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_StepWindow(D_Storage *pStorage, vector<D_StepWindow *> *pSteps_inMW, vector<int> vDefaults, QWidget *parent = 0);
    ~D_StepWindow();

    void                    resizeEvent(QResizeEvent* event);
    void                    closeEvent(QCloseEvent *event);
    void                    set_Position();

public slots:

    void                    Update_Ui();
    void                    Update_from_extern();
    void                    set_need_Update(bool update_need)       {Need_Update = update_need;}
    void                    set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}
    void                    set_chain_pos(unsigned int pos);
    void                    set_ViewPlanePos(vector<int> pos);
    void                    set_ViewZoom(double x_rel, double y_rel, double factor, int plane);
    bool                    needs_Update()                          {return Need_Update;}
    vector<unsigned int>    *sources()                              {return &vUI_Sources;}
    vector<unsigned int>    *destinations()                         {return &vUI_Destinations;}
    void                    add_destination(unsigned int dest)      {vUI_Destinations.push_back(dest);}
    void                    pop_destination(unsigned int dest)      {vUI_Destinations.erase(remove(vUI_Destinations.begin(), vUI_Destinations.end(), dest), vUI_Destinations.end());}
    void                    Update_Chain_Info(bool update_sources);
    unsigned int            get_root_toUpdate();

    QImage                  *get_pQI_Step_Image()                   {return Viewer.QI();}

    void                    Update_Source_Info();

    void                    Save_Steps(QDir *dir_save, ofstream *os_stream);

    QString                 get_Title()                             {return QS_title;}


signals:
    void                    ViewPlanePosChanged(vector<int>);
    void                    ViewZoomChanged(double x_rel, double y_rel, double factor, int plane);

private slots:

    //void Update_STEP();

    void Update_Image();
    void Update_View();
    void Update_Img_Proc();
    void Update_ParameterList();
    void Update_Hist();
    void Update_Title();
    void Update_Type_Descriptions();
    void Update_Source_Preview();
    void Update_Descriptions();
    void Update_HistSettings();
    void Update_vSources_vDestinations();
    void Update_Destinations_Info();
    void Update_Range_Info();
    void Update_Size_Info();

    void Update_Times();
    void Update_Time_Img_Cvt(unsigned int t);
    void Update_Time_View_Update(unsigned int t);

    void Dim_GetFromVD();
    int  ProcDimCountFromUi();
    void ProcDimCountAdaptUi();

    void Emitter_ViewPlanePosChanged();
    void Emitter_ViewZoomChanged();

    void Save_Image_Step();
    void Save_ImageList_Step();
    void Save_VisDat();
    void Save_Screenshot_Step();
    void Save_Feature_List();
    void Save_Analysis();

    void Connect_HistSettings_2_UpdateHist(bool con);
    void Connect_TimesSettings_2_UpdateTimes(bool con);
    void Connect_ImgProcSettings_2_UpdateImgProc(bool con);
    void Connect_OtherSteps();

    void Activate_Makro();


    void CO_Depth_Set_Range(int prec, double min, double max);
    void FI_General_Adapt_Ui(int index);
    void FI_Blur_Adapt_Ui(int index);
    void FI_Edge_Adapt_Ui(int index);
    void FI_Spec_Adapt_Ui(int index);
    void FI_Function_RandomAll();
    void FI_Function_RandomFunction();
    void FI_Function_RandomParameters();
    void MA_1Img_Adapt_Ui(int index);
    void MA_2Img_Adapt_Ui(int index);
    void AdaptUi_SourceNumber_ProcDims();
    void ViewerPlanePosChange_Block(bool block);

    void Populate_CB_All();
    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int init_index = 0);
    void Populate_CB_Statistics();
    void Populate_CB_Features();
    void Populate_CB_Geometrics();
    void Populate_CB_Math();
    void Populate_CB_Planes();
    void Populate_CB_Dims();
    void Populate_CB_LoadModes();
    void Populate_CB_Color2Mono();
    void Populate_CB_CompDist();
    void Populate_CB_VisTrafo();
    void Populate_CB_Other();
    void Test_Feature_Visualize();

    void Measure_SaveClick(int x, int y);
    void Measure_LineDistance();

    void on_spinBox_Source_Pos_1_valueChanged(int arg1);
    void on_spinBox_Source_Pos_2_valueChanged(int arg1);
    void on_spinBox_Source_Pos_3_valueChanged(int arg1);
    void on_spinBox_Source_Pos_4_valueChanged(int arg1);

    void on_comboBox_00_Load_Mode_currentIndexChanged(int index);

    void on_comboBox_02_Depth_Type_currentIndexChanged(int index);

    void on_comboBox_Type_04_Filter_currentIndexChanged(int index);
    void on_spinBox_04_Edge_dX_valueChanged(int arg1);
    void on_spinBox_04_Edge_dY_valueChanged(int arg1);

    void on_tabWidget_Output_currentChanged(int index);

    void on_pushButton_00_Load_Image_clicked();
    void Scan_Examples_Dir();

    void on_spinBox_02_Merge_Channels_valueChanged(int arg1);

    void on_checkBox_07_Watershed_Auto_stateChanged(int arg1);

    void on_action_Change_Title_triggered(bool checked);

    void on_pushButton_00_Sample_Select_Directory_clicked();

    void on_comboBox_03_GrabColor_ColorSpace_currentIndexChanged(int index);

    void on_doubleSpinBox_01_Crop_Rect_X1_valueChanged(double arg1);
    void on_doubleSpinBox_01_Crop_Rect_Y1_valueChanged(double arg1);
    void on_doubleSpinBox_01_Crop_Rect_X2_valueChanged(double arg1);
    void on_doubleSpinBox_01_Crop_Rect_Y2_valueChanged(double arg1);

    void block_signals_thres(bool block);
    void on_doubleSpinBox_03_Thres_Rel_Base_valueChanged(double arg1);
    void on_doubleSpinBox_03_Thres_Rel_Thres_Rel_valueChanged(double arg1);
    void on_doubleSpinBox_03_Thres_Rel_Thresh_Abs_valueChanged(double arg1);
    void on_horizontalSlider_03_Thres_Rel_Thresh_Rel_valueChanged(int value);

    void on_comboBox_03_Thres_Type_currentIndexChanged(int index);

    void on_doubleSpinBox_08_Select_Step_valueChanged(double arg1);

    void on_spinBox_08_Select_Decimals_valueChanged(int arg1);

    void on_spinBox_04_Edge_Thresh_Low_valueChanged(int arg1);
    void on_spinBox_04_Edge_Thresh_High_valueChanged(int arg1);

    void on_pushButton_00_CastRaw_Path_clicked();

    void on_spinBox_10_Crop_Min_X_valueChanged(int arg1);
    void on_spinBox_10_Crop_Min_Y_valueChanged(int arg1);
    void on_spinBox_10_Crop_Min_Z_valueChanged(int arg1);
    void on_spinBox_10_Crop_Min_T_valueChanged(int arg1);
    void on_spinBox_10_Crop_Min_S_valueChanged(int arg1);
    void on_spinBox_10_Crop_Min_P_valueChanged(int arg1);
    void on_spinBox_10_Crop_Max_X_valueChanged(int arg1);
    void on_spinBox_10_Crop_Max_Y_valueChanged(int arg1);
    void on_spinBox_10_Crop_Max_Z_valueChanged(int arg1);
    void on_spinBox_10_Crop_Max_T_valueChanged(int arg1);
    void on_spinBox_10_Crop_Max_S_valueChanged(int arg1);
    void on_spinBox_10_Crop_Max_P_valueChanged(int arg1);

    void on_comboBox_05_Elem_Morph_Type_currentIndexChanged(int index);

    void on_spinBox_00_VideoStream_T_Offset_valueChanged(int arg1);
    void on_spinBox_00_VideoStream_T1_Frames_valueChanged(int arg1);
    void on_spinBox_00_VideoStream_T2_Frames_valueChanged(int arg1);
    void on_pushButton_00_VideoStream_Browse_clicked();

    void on_comboBox_View_Plane_currentIndexChanged(int index);

    void on_comboBox_08_FeatContextVal_Stat_currentIndexChanged(int index);
    void on_comboBox_08_FeatContextSelect_Stat_currentIndexChanged(int index);

    void on_checkBox_06_4Img_Value_clicked(bool checked);
    void on_checkBox_06_3Img_Value_clicked(bool checked);
    void on_comboBox_06_3Img_Type_currentIndexChanged(int index);
    void on_comboBox_06_4Img_Type_currentIndexChanged(int index);

    void on_checkBox_09_HDR_Thresh_stateChanged(int arg1);
    void on_checkBox_09_HDR_Project_stateChanged(int arg1);
    void on_doubleSpinBox_09_HDR_Thresh_Low_valueChanged(double arg1);
    void on_doubleSpinBox_09_HDR_Thresh_High_valueChanged(double arg1);

    void on_checkBox_07_Fourier_Output_RealOnly_stateChanged(int arg1);

    void on_comboBox_View_Crop_currentIndexChanged(int index);
    void on_comboBox_View_Transform_currentIndexChanged(int index);
    void on_comboBox_View_Anchor_currentIndexChanged(int index);
    void on_comboBox_View_Range_currentIndexChanged(int index);
    void on_checkBox_View_VisTrafo_stateChanged(int arg1);
    void on_doubleSpinBox_View_Min_valueChanged(double arg1);
    void on_doubleSpinBox_View_Max_valueChanged(double arg1);

    void on_radioButton_09_RelationStat_Distance_clicked(bool checked);
    void on_radioButton_09_RelationStat_Angle_clicked(bool checked);

private:
    Ui::D_StepWindow *ui;

    //error handling
    D_Error_Handler ER;
    void ERR(int err, QString func = "no specified", QString detail = "no specified");

    //Dummy for VisDat Test
    //D_VisDat                VD_Test;

    //Data Storage (shared)
    D_Storage               *pStore;
    unsigned int            pos_Dest;
    unsigned int            pos_Source1 = 0;
    unsigned int            pos_Source2 = 0;
    unsigned int            pos_Source3 = 0;
    unsigned int            pos_Source4 = 0;
    unsigned int            pos_Source1_last_Update = 0;
    unsigned int            pos_Source2_last_Update = 0;
    unsigned int            pos_Source3_last_Update = 0;
    unsigned int            pos_Source4_last_Update = 0;
    unsigned int            pos_in_chain = 0;

    vector<unsigned int>    vUI_Sources;
    vector<unsigned int>    vUI_Destinations;
    bool                    Need_Update = false;
    vector<D_StepWindow*>   *pSteps;
    bool                    ClosingPossible = false;

    //Load file name
    QFileInfo       FI_Load_File;
    QFileInfoList   FIL_Load_Files;
    QFileInfoList   FIL_Examples;
    QFileInfo       FI_RawFile;

    //Stuff to show images
    D_Viewer        Viewer;
    QChartView      *pCV_Viewer;
  //Mat             MA_Show2d;

    //Dimension of Dataset
    vector<QDoubleSpinBox*>     vDSB_Dims;
    vector<QCheckBox*>          vCHB_ProcDims;
    D_VisDat_Slicing            SlicingFromUi();

    //QImage          QI_Step_Image;
    //QPixmap         PX_Step_Image;
    //SceneMouseTrack SC_Step_Image;
    QImage          *pQI_Source_1;
    QImage          *pQI_Source_2;
    QImage          *pQI_Source_3;
    QImage          *pQI_Source_4;
    //double          scale_factor_x;
    //double          scale_factor_y;

    //Stuff needed to display hist
    QChartView      *ChartView_Hist;
    QChart          *Chart_Hist;

    //Statusbar
    QLabel          *L_SB_SizeType;
    QLabel          *L_SB_Zoom;
    QLabel          *L_SB_Range;
    QLabel          *L_SB_Pos;
    QLabel          *L_SB_ValAtPos;

    //Title
    QString         QS_AlternativeTitle;
    QString         QS_title;
    QStringList     QSL_Parameters;
    QString         QS_Type;
    QString         QS_Subtype;

    //Time measurement
    unsigned int    times[5] = {0};
    QChartView      *ChartView_Times;
    QChart          *Chart_Times;

    //function filter
    bool            FI_Func_all_random = false;

    //Measure
    Point Measure_P1;
    Point Measure_P2;

    //CONSTANTS

    //Types
    enum c_Type {
        c_T_SOURCE,
        c_T_EDIT,
        c_T_CONV,
        c_T_ELEM,
        c_T_FILT,
        c_T_MORPH,
        c_T_MATH,
        c_T_TRANS,
        c_T_FEATURE,
        c_T_OTHER,
        c_T_DIM,
        c_T_NUMBER_OF
    };

    //Subtypes: Source
    enum c_Source {
        c_sT_SO_LOAD,
        c_sT_SO_DUPLICATE,
        c_sT_SO_SAMPLE,
        c_sT_SO_GENERATE,
        c_sT_SO_RANDOM,
        c_sT_SO_RAW,
        c_sT_SO_VIDEO_PROC
    };

    //Subtypes: Edit
    enum c_Edit {
        c_sT_ED_CROP,
        c_sT_ED_FLOODFILL,
        c_sT_ED_PADDING,
        c_sT_ED_FORCE_SIZE
    };

    //Subtypes: Convert
    enum c_Convert {
        c_sT_CO_COLOR2MONO,
        c_sT_CO_COLOR,
        c_sT_CO_DOUBLE,
        c_sT_CO_DEPTH,
        c_sT_CO_MERGE,
        c_sT_CO_SPLIT,
        c_sT_CO_COMBI,
        c_sT_CO_ANGLE2COLOR
    };

    //Subtypes: Elemental
    enum c_Elemental {
        c_sT_EL_THRES,
        c_sT_EL_LABEL,
        c_sT_EL_SHADE_CORRECT,
        c_sT_EL_COLORGRAB,
        c_sT_EL_FILLHOLES
    };

    //Subtypes: Filter
    enum c_Filter {
        c_sT_FI_BLUR,
        c_ST_FI_EDGE,
        c_sT_FI_SPEC,
        c_sT_FI_EILENSTEIN,
        c_sT_FI_FUNCTION
    };

    //Subsubtypes: Filter
    enum c_FilterBlur {
        c_ssT_FI_BLUR_MEAN,
        c_ssT_FI_BLUR_RMS,
        c_ssT_FI_BLUR_GAUSS,
        c_ssT_FI_BLUR_MEDIAN_BOX,
        c_ssT_FI_BLUR_MEDIAN_CUSTOM
        //c_ssT_FI_BLUR_MEDIAN_SPHERE
    };

    //Subtypes: Morphology
    enum c_Morphology {
        c_sT_MO_ELEM,
        c_sT_MO_LOC_MAX
    };

    //Subtypes: Math
    enum c_Math {
        c_sT_MA_1IMG,
        c_sT_MA_2IMG,
        c_sT_MA_2IMG_FUNCTION,
        c_sT_MA_2IMG_FUNCTION_COMPLEX,
        c_sT_MA_3IMG,
        c_sT_MA_4IMG
    };

    //Subtypes: Transformation
    enum c_Transformation {
        c_sT_TR_DIST,
        c_sT_TR_WATERSHADE,
        c_sT_TR_FOURIER,
        c_sT_TR_RADON
    };

    //Subtypes: Feature
    enum c_Feature {
        c_sT_FE_VALUE,
        c_sT_FE_CONTEXT_VALUE,
        c_sT_FE_SELECT,
        c_sT_FE_CONTEXT_SELECT,
        c_sT_FE_CONNECT,
        c_sT_FE_REDUCE,
        c_sT_FE_VISUALIZE
    };

    //Subtypes: Other
    enum c_Other {
        c_sT_OT_EQUAL_HIST,
        c_sT_OT_GAMMA_SPREAD,
        c_sT_OT_LABEL_NUMBER,
        c_sT_OT_NEIGHBORHOOD_CONFIG,
        c_sT_OT_MOTION_FIELD,
        c_sT_OT_CLASS_KNN,
        c_sT_OT_HDR,
        c_sT_OT_RELATION_STAT,
        c_sT_OT_ZERNIKE_STACK,
        c_sT_OT_RADIOMETRIC_STEREO
    };

    //Subtypes: Dimension
    enum c_Dimension{
        c_sT_DI_PICK,
        c_sT_DI_CROP,
        c_sT_DI_PROJECT,
        c_sT_DI_DESERIALISE,
        c_sT_DI_PAGES2COLOR,
        c_sT_DI_STITCH_BORDER,
        c_ST_Di_EXTEND,
        c_ST_DI_FLIPED
    };

    //math operation order
    enum c_Math_3_4{
        c_ssT_MA_3_4_ADD,
        c_ssT_MA_3_4_MULT,
        c_ssT_MA_3_4_AND,
        c_ssT_MA_3_4_OR
    };
};

#endif // D_STEPWINDOW_H
