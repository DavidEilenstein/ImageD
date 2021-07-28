/************************************
 *   added:     13.11.2018          *
 *   author:    Manon Nickler       *
 *   contact:   M.Nickler@gsi.de    *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef M_MAKRO_FOCI_H
#define M_MAKRO_FOCI_H

//own
#include <scenemousetrack.h>
#include <d_img_proc.h>
#include <d_plot.h>
#include <d_storage.h>
#include <d_viewer.h>
#include <d_error_handler.h>

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
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QBuffer>
#include <QSpacerItem>
#include <QElapsedTimer>
#include <QDesktopServices>
#include <QRubberBand>
#include <QApplication>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>


#include <QMainWindow>

namespace Ui {
class m_makro_foci;
}

class m_makro_foci : public QMainWindow
{
    Q_OBJECT

public:
    explicit m_makro_foci(D_Storage *pStorage,QWidget *parent = nullptr);
    ~m_makro_foci();

    void closeEvent(QCloseEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

public slots:

    void Update_ImgProc_Results();
    void Update_Step_Results_all(int step);
    void Update_Step_Results_av(int step);
    void Update_Step_Results_feature();

    void Update_View();
    void Update_Ui();



private slots:

    void Update_SimpleOrMulti_Page();

    void Update_size_t();
    void Update_nb_interval();
    void Update_time_interval_values();
    void Update_ComboBox_index_changes();
    void Update_Time_scale();
    void Ititialise_time_interval();

        // step all images
    void step_load();
    void Convert();
    void Threshold();
    void Reduction();
    void Dilatation();
    void Finaladd();

    int draw_circle(Mat *pMA_out, Mat *pMA_int);
    int draw_circle(Mat *pMA_out, Mat *pMA_Out2, Mat *pMA_int,Mat *pMA_label);
    int draw_circle_2(Mat *pMA_out, Mat *pMA_Out2, Mat *pMA_int,Mat *pMA_label,int t);

    void Update_selected_centroid();
    void Circled_selected_centroid();

        // step average images
    void step_average();
    void Threshold_av();
    void Reduction_av();
    void Watershed_av();
    int Image_average(vector<Mat> pvMA_In, Mat *pMA_Out);
//    int Image_average(vector<Mat> *pvMA_In, Mat *pMA_Out);
    int Image_proj_max_intensity(vector<Mat> pvMA_In, Mat *pMA_Out);
    int Image_proj_max_intensity_t_positif(vector<Mat> pvMA_In, Mat *pMA_Out);


    // Feature Foci
    void Feature_Foci();
    void Unselect_occasional_detected_foci();
    void Interpolation_Feature_Foci();
    void Normalization_Feature_Foci();
    void Get_Average_Feature_Foci();
    void Select_pertinent_Foci();
    void Select_pertinent_Foci_Std_dev();
    void Select_pertinent_Foci_to_unify();
    void Select_pertinent_Foci_first_images();
    void Unselect_decreasing_curves();
    void Unselect_non_pertinent_Foci_User();
    void Update_selected_Foci_array();
    void Sort_label();
    void Swap_foci_to_sort_label(int labelIn, int labelOut, int t);

    void Condition_emergence_time();
    void Set_emergence_time_by_user();
    void Vector_2_Mat(vector<vector<double>> *p_vvIn, Mat *pM_Out);
    void Mat_2_vector(Mat *pM_In, vector<vector<double>> *p_vvOut);

    void Variance_in_time_window();

    void Filter_Intensity_values();
    void Mean_Filter_intensity();
    void Derivativ();


    // Label Foci
    void Label_Foci_in_time();
    int Check_Foci_in_Circle(Mat * pIn,int* CoordX_In, int* CoordY_In, int* CoordX_Out, int* CoordY_Out,int* label_Out);
    void Single_Circled_Focus(int label);
    void Assigne_label_to_Foci(Mat * pIn,int label,int t, int* CoordX, int* CoordY);
    void Update_label_state(int label, int t, const int state);

    // Histo
    int Plot_Curves_Single_Classes(QChartView *pChartView, vector<double> *v_histx,vector<double> *v_histy, double min, double step, double time, double time_cursor,QString name_title, QString name_series, QString name_x, QString name_y, bool ignore_first);
    void Calc_Curves();
    void Update_Curves();
    void Update_detail_Values();

    // Write in cvs file
    int Save_csv_file_full();
    void Save_info_full();
    void Stream_Open_foci_in_time_full();
    void Stream_Init_foci_in_time_full();
    void Stream_End_foci_in_time_full();

    int Save_csv_file();
    void Save_info();
    void Save_Parameters();
    void Save_emergence_time();
    void Save_Picture_of_Circled_Foci();
    void Stream_Open_foci_in_time();
    void Stream_Init_foci_in_time();
    void Stream_End_foci_in_time();

    // Select Background area with mouse
    void Enable_disable_select_area();
    void Select_bckgd_area(int, int );
    void Delete_bckgd_area();
    void Confirm_bckgd_area();
    void Set_MA_area_bckgd();
    void Get_values_backgd();
    void Enable_Foci_Features_Tab();

    //Select foci with mouse
    void Add_focus_user(int x, int y);
    void Confirm_Added_focus_user();
    void Init_add_focus_user();
    void Delete_added_foci_user();

    // Update parameters
    void on_pushButton_02_default_values_clicked();

    // Others
    void Dilatation_centroid_labeled();
    void Black_Bckgd_2_white(int step);

    void Update_displayed_time();

    //Nucleus edges
    void Nucleus_edges();
    int Feature_biggest_area(Mat *pMA_Out, Mat *pMA_In, int feature);

    //Parameters changed
    void Threshold_parameters_changed();
    void Settings_parameters_changed();
    void Foci_tracking_parameters_changed();
    void Foci_feature_parameters_changed();

    void on_comboBox_step_av_currentIndexChanged(int index);

    void resize_array(vector<double> *v_value, int size);
    void resize_array(vector<vector<double>> *vv_value,int size1, int size2);
    void resize_array(vector<vector<vector<double>>> *vvv_value, int size1, int size2, int size3);

private:
    Ui::m_makro_foci *ui;

    bool                    ClosingPossible = false;

    int Size_image_in_time;

    //error handling
    D_Error_Handler ER;
    void ERR(int err, QString func = "no specified", QString detail = "no specified");

    // Time interval
    int nb_time_interval;
    int nb_combo_time_interval=0;
    vector<vector<int>> vv_Interval_info;
    vector<int> v_Time_scale;
    QStringList Time_interval_List;

    //Loaded image
    bool Flag_loaded_image =false;

    //Data Storage
    D_Storage       *pStore;

    vector<Mat>     vMA_Nuclei;
    vector<Mat>     vMA_temp;
    vector<Mat>     vMA_Average;
    Mat             MA_Average_area,MA_Average_area_without_bckgd;
    Mat             MA_Max_proj_add_focus;
    vector<vector<Mat>>  vvMA_Nuclei;
    vector<Mat>     vMA_Circled_Focus;
    Mat             MA_Result = Mat();

    unsigned int    pos_dest;

    //Tracking Foci

//    vector<vector<vector<int>>> vvvCentroid_Features;


    //Feature Storage
    vector<vector<vector<double>>>  vvvFeatureFoci;
    vector<vector<vector<double>>>  vvvFeatureFoci_selected;
    int FeatureFoci_nb_label=0;
    int FeatureFoci_nb_label_selected=0;
    vector<int> LabelFociSelected_To_LabelFoci;
    vector<int> LabelFoci_To_LabelFociSelected;

    vector<int> vEmergence_time;

    // Intensity values

    float IntensityMax=0,IntensityMin=0;
    float Intensity_filter_Max=0,Intensity_filter_Min=0;
    Mat M_foci_intensity, M_foci_intensity_filtered;
    vector<vector<double>> vv_intensity, vv_intensity_filtered;

    //Intensity : variance in time window

    vector<vector<double>> vv_intensity_std_dev;

    // Intensity derivation
    Mat M_foci_intensity_filter_1st_deriv, M_foci_intensity_filter_2nd_deriv;
    vector<vector<double>> vv_intensity_filter_1st_deriv, vv_intensity_filter_2nd_deriv;

    //Statitic Intensity values

    vector<vector<vector<double>>> vvvv_stat_intensity;

    //
    vector<double> v_labels , v_temps;
    vector<vector<char>> vv_label_state;

    vector<vector<float>>    vvFeatureFoci_Average;

    // selection Foci
    vector<int> Foci_unselect_by_user;
    int nb_Foci_unselect_by_user=0;

    vector<vector<int>> Foci_added_by_user;
    int nb_Foci_added_by_user=0;
    vector<int> vFoci_added;

    //pathes of images
    QFileInfoList   FIL_Input_Images;


    //Load file name
    QFileInfo       FI_Load_File;
    QFileInfoList   FIL_Examples;


    //stream to output data
    bool            Stream_Open_Foci = false;
    ofstream        OS_Stream_Foci_Info;
//    vector<ofstream>OS_Stream_Details_Foci;
    QDir            DIR_Stream_Foci;


    //Display images
    D_Viewer        V_Nuclei_tab_Average;
    D_Viewer        V_Nuclei_img_proc;
    D_Viewer        V_Nuclei_Label_Foci;
    D_Viewer        V_Nuclei_tab_Results;
    D_Viewer        V_Nuclei_tab_Add_focus;
    D_Viewer        V_Nuclei_tab_Curves;

    //Stuff needed to display hist
    QChartView      *ChartView_Hist;
    QChart          *Chart_Hist;

    //Statusbar
    QLabel          *L_SB_ValAtPos;
    QLabel          *L_SB_Path;
    QLabel          *L_SB_State;

    // Select bckgd

    bool                    Flag_selected_Bckgd;
    QRubberBand*            rubberBand;
    vector<vector<int>>     vv_Feature_area_bckgd;
    int                     nb_area_bckgd           = 0;
    vector<double>           Bckgd_in_nuclei,Bckgd_out_nuclei;
    vector<double>           v_stats_bckgd_in, v_stats_bckgd_out;

    //Tabs
    enum e_TAB
    {
        e_TAB_AVERAGE,
        e_TAB_IMG_PROC,
        e_TAB_RESULTS,
        e_TAB_CURVES,
        e_TAB_SAVE
    };

    //AV img
    enum e_AV_IMG
    {
        e_AV_IMG_ORIGINAL,
        e_AV_IMG_BLUR,
        e_AV_IMG_AVERAGE_IMAGE,
        e_AV_IMG_THRESHOLD,
        e_AV_IMG_REDUCE_CENTROID,
        e_AV_IMG_LABEL_MASK
    };

    //Img Proc
    enum e_IMG_PROC
    {
        e_IMG_PROC_ORIGINAL,
        e_IMG_PROC_THRESHOLD,
        e_IMG_PROC_REDUCE
    };


    //Error Codes
    unsigned static const int
    ER_okay                 = 0,
    ER_other                = 1,
    ER_empty                = 2,
    ER_type_bad             = 3,
    ER_type_missmatch       = 4,
    ER_bitdepth_bad         = 5,
    ER_bitdepth_missmatch   = 6,
    ER_size_bad             = 7,
    ER_size_missmatch       = 8,
    ER_parameter_bad        = 9,
    ER_parameter_missmatch  = 10,
    ER_channel_bad          = 11,
    ER_channel_missmatch    = 12,
    ER_index_out_of_range   = 13;

    //Single page or multi page
    static const unsigned int
    c_ST_single_page        = 0,
    c_ST_multi_page         = 1;

    //Steps Count
    static const int
    c_SC_NUCLEI              = 21;

    //Nuclei Steps
    enum M_NUCLEI_STEP_PROCESS {
    c_ST_N_LOAD             ,
    c_ST_N_INPUT_CONV_8BIT  ,
    c_sT_N_THRESHOLD        ,
    c_sT_N_REDUCTION        ,
    c_sT_N_DILATATION_WITHOUT_LABEL,
    c_sT_N_FOCI_NO_BKGRD,
    c_sT_N_AVERAGE_INTENSITY_FOCI,
    c_sT_N_Label_in_time ,
    c_sT_N_CENTROID_SELECTED,
    c_sT_N_Label_in_time_dilated,
    c_sT_N_Label_in_time_CIRCLED_without_labels,
    c_sT_N_Label_in_time_CIRCLED_with_labels,
    c_sT_N_Label_interpoled_centroid,
    c_ST_N_INPUT_CONV_8BIT_bigger_DIM,
    c_ST_N_INPUT_CONV_16BIT,
    c_ST_N_TEMP,
    c_ST_N_Otsu_threshold,
    c_ST_N_Convex_hull,
    c_ST_N_Contour_nuclei
};

    //vMA_Average step
    enum M_AVERAGE_STEP {
    c_sT_Max_Proj,
    c_sT_Max_Proj_T_positives,
    c_sT_Max_Proj_Threshold,
    c_sT_Max_Proj_Reducted,
    c_sT_Max_Proj_Watershed
    };

    // Feature image Processing
    static const unsigned int
    c_sT_thickness_centroid     =1;

    // Displayed Nuclei Steps Tab 1
    static const unsigned int
    c_sT_N_AVERAGE_IMAGE                = 2,
    c_sT_N_THRESHOLD_AVERAGE_IMG        = 3,
    c_sT_N_REDUCTION_AVERAGE_IMG        = 4,
    c_sT_N_WATERSHED_AVERAGE_IMG        = 5,
    c_sT_N_AVERAGE_INTENSITY            = 6;

    // Displayed Nuclei Steps Tab 2
    static const unsigned int
    c_ST_N_INPUT_CONV_8BIT_VIEW  = 0,
    c_sT_N_THRESHOLD_VIEW        = 1,
    c_sT_N_REDUCTION_VIEW        = 2,
    c_sT_N_CIRCLED_NUCLEUS       = 3;

    // Displayed Nuclei Steps Tab 4
    static const unsigned int
    c_sT_N_CIRCLED_FOCI_VIEW            =0,
    c_sT_N_ADD_FOCUS                    =1;

    //Time intervals values

    static const int
    c_sT_interval_info_number           =3,

    c_sT_Interval_info_From             =0,
    c_sT_Interval_info_To               =1,
    c_sT_Interval_info_Value            =2;



    //Number of image in time
    static const int
    c_size_time            = 80;

    // FeatureFoci

    static const unsigned int
    c_sT_N_FEATURE_AVERAGE_IMG          = 0;

    //
   const int c_nb_Array_intensity= 4;

   static const unsigned int
   c_sT_Array_intensity_normalized                   =0,
   c_sT_Array_intensity_normalized_filter            =1,
   c_sT_Array_intensity_normalized_filter_1st_deriv  =2,
   c_sT_Array_intensity_normalized_filter_2nd_deriv  =3;


    //Foci
    static const int

    c_sT_Nb_label_max           =10000;

    // Background value
    static const int
    c_sT_Value_bckgd_centroid       =0,
    c_sT_Value_centroid             =255,

    c_sT_Value_bckgd_foci_labeled   =0;

    // FeatureFoci Storage
            //vvvFeatureFoci[label][time][c_sT_Feature_Foci]
            //vvvFeatureFoci_selected[label][time][c_sT_Feature_Foci]
    static const int
    c_sT_Feature_Foci           =8,

    c_sT_Feature_Foci_state         =0,
            c_sT_state_unassigned       =0,
            c_sT_state_assigned         =1,
            c_sT_state_lost             =2,
            c_sT_state_interpolated     =3,
    c_sT_Feature_Foci_coordX        =1,
    c_sT_Feature_Foci_coordY        =2,
    c_ST_Feature_Foci_Nb_pixels     =3,
    c_ST_Feature_Foci_Intensity     =4,
    c_ST_Feature_Foci_Intensity_norm=5,
    c_sT_Feature_Foci_label         =6,
    c_sT_Feature_Foci_selected      =7;

    //Feature Foci with foci tracking
    static const int
      c_ST_interval_time          =10,// 15
//      c_sT_radius_circle          = 4, -->set by user

      c_sT_Minimum_count_foci     =3, // Unselect_occasional_detected_foci
      c_sT_Minimum_average_dist   =7; // Select_pertinent_Foci_to_unify

    // Condition variance
    static const int
        c_sT_variance_min           =1;

    // Feature Foci Average Storage
        // vvFeatureFoci_Average[label][c_sT_Feature_Foci_Average]
    static const int
    c_sT_Feature_Foci_Average           =5,

    c_sT_Feature_Foci_Average_intensity =0,
    c_sT_Feature_Foci_Average_min_value =1,
    c_sT_Feature_Foci_Average_max_value =2,
    c_sT_Feature_Foci_Average_variance  =3,
    c_sT_Feature_Foci_Average_appear_time   =4;

    // Area Background
    static const int
    c_sT_nb_Feature_area_bckgd          =4,

    c_sT_area_bckgd_label               =0,
        c_sT_label_bckgd_foci               =255,
        c_sT_label_bckgd_nuclei             =125,
    c_sT_area_bckgd_coord_X             =1,
    c_sT_area_bckgd_coord_Y             =2,
    c_sT_area_bckgd_radius              =3;

};

#endif // M_MAKRO_FOCI_H
