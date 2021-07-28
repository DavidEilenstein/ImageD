/************************************
 *   added:     ??.01.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MAKRO_IONTRACKS_H
#define D_MAKRO_IONTRACKS_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_img_proc.h>
#include <d_plot.h>
#include <d_stat.h>
#include <d_viewer.h>
#include <d_storage.h>
#include <d_component.h>
#include <d_component_list.h>
#include <d_value_distribution_list.h>
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
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

namespace Ui {
class D_MAKRO_IonTracks;
}

class D_MAKRO_IonTracks : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_IonTracks(D_Storage *pStorage, QWidget *parent = 0);
    ~D_MAKRO_IonTracks();

    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

private slots:

    void Update_Views();
    void Update_View_Proc();
    void Update_Ui();

    void Update_ImgProc();
    void Update_ImgProc_Proc(int start_step);
    void Update_Step_Proc(int img, int step);

    void Calc_All();
    void Calc_ValueDistribution();
    void Calc_Track_Stats();
    void Calc_Stack_Stats_All();

    void Update_Results();

    void Plot_StatAtRadius_All();
    void Plot_StatAtRadius_All_Group();
    void Plot_MeanSD_All();
    void Plot_MedianADM_All();
    void Plot_Quantiles_All();

    void Table_SingleTrack();
    void Table_TrackStats();

    void Image_ColorRGB_Info();

    void Update_Dimensions();
    void Init_ImageVectors();

    void Populate_CB_Single(QComboBox *CB, QStringList QSL);
    void Populate_CB_All();
    void Populate_CB_Stats();
    void Populate_CB_AxeTrans();
    void Populate_CB_PlotTypes();
    void Populate_CB_TableTypes();
    void Populate_CB_Dimensions();
    void Populate_CB_Groups();
    void Populate_CB_ProcSteps();
    void Populate_CB_ImageRGB_Info();

    void Load_DirectoriesList();
    void Load_Directoty();

    void Save_Analysis();
    void Save_Table();
    void Save_Plot();
    void Save_Plot(QString path);

    void on_spinBox_ProcSet_Blur_Size_valueChanged(int arg1);
    void on_doubleSpinBox_ProcSet_Blur_Sigma_valueChanged(double arg1);
    void on_doubleSpinBox_ProcSet_Binarization_Thres_valueChanged(double arg1);
    void on_doubleSpinBox_ProcSet_ExLarge_MaxArea_valueChanged(double arg1);
    void on_doubleSpinBox_ProcSet_ExAsphere_MinSphere_valueChanged(double arg1);
    void on_spinBox_ProcSet_SafetyDist_MinRadius_valueChanged(int arg1);
    void on_doubleSpinBox_ProcSet_ExConn_MinSphere_valueChanged(double arg1);
    void on_doubleSpinBox_ProcSet_TOI_RelRadius_valueChanged(double arg1);

    void on_comboBox_ResTab_Group_currentIndexChanged(int index);

    void on_comboBox_ResPlo_Group_currentIndexChanged(int index);

private:
    //interface
    Ui::D_MAKRO_IonTracks                   *ui;
    bool                                    ClosingPossible = false;

    //Storage
    D_Storage                               *pStore;

    //Data Base
    vector<vector<Mat>>                     vvMA_Proc_ImgStep;
    vector<D_Value_Distribution_List>       vVD_ValDistLists_Img;

    //Data All
    vector<vector<vector<double>>>          vvvd_All_StaRadTra;
    vector<vector<vector<double>>>          vvvd_All_StaStaRad;
    //Data Lateral
    vector<vector<vector<vector<double>>>>  vvvvd_Lat_DimStaRadTra;
    vector<vector<vector<vector<double>>>>  vvvvd_Lat_DimStaStaRad;
    //Data Depth
    vector<vector<vector<vector<double>>>>  vvvvd_Dep_DimStaRadTra;
    vector<vector<vector<vector<double>>>>  vvvvd_Dep_DimStaStaRad;

    //Calc checks
    bool                                    calced_ImgProc      = false;
    bool                                    calced_ValDist      = false;
    bool                                    calced_StaTra       = false;
    bool                                    calced_StaSta       = false;

    //Viewer
    D_Viewer            View_Proc;
    D_Viewer            View_Results;

    //Plot
    QChartView          *pChartView_Plot;

    //Table
    D_Table             Table_Tracks;

    //Dimensions
    int                 Dim_XLat_Dim    = 2;
    int                 Dim_YLat_Dim    = 2;
    int                 Dim_ZDep_Dim    = 20;
    int                 Dim_Lat_Dim     = 4;
    int                 Dim_All         = 80;
    double              Dim_XLat_Step   = 100.0;
    double              Dim_YLat_Step   = 100.0;
    double              Dim_ZDep_Step   = 5.0;
    QString             Dim_Unit        = "µm";
    QStringList         QSL_Dim_Lat;
    QStringList         QSL_Dim_Dep;
    int                 Index_CurrentView();
    void                Update_Max_Radius();
    int                 max_radius      = 8;
    int                 tracks_count;

    //Paths
    QDir                DIR_MasterDirectory;
    QStringList         QSL_ImageDirectories;
    QStringList         QSL_ImageDirectories_Names;
    QDir                DIR_Input;
    QFileInfoList       FIL_InputCurrentSet;
    QString             QS_CurrentSetName;
    QDir                DIR_SaveAnalysis_Master;
    QDir                DIR_SaveAnalysis_Current;

    //error handling
    D_Error_Handler ER;
    void ERR(int err, QString func = "not specified", QString detail = "not specified");

    //CONSTANTS

    QStringList QSL_Radius;

    //Proc Steps
    enum ProcStepsSingle
    {
        c_STEP_LOAD,
        c_STEP_BLUR,
        c_STEP_BIN,
        c_STEP_EX_LARGE,
        c_STEP_EX_ASPHERES,
        c_STEP_SAFETY_DIST,
        c_STEP_EX_CONNECTED,
        c_STEP_TOI_ORIGINAL,
        c_STEP_TOI_CENTROID,
        c_STEP_TOI_AREA,
        c_STEP_TOI_LABEL,
        c_STEP_NUMBER_OF
    };
    QStringList QSL_ProcStepSingle =
    {
        "00 - Load",
        "01 - Blur",
        "02 - Binarization",
        "03 - Exclude Large",
        "04 - Exclude Aspheres",
        "05 - Safety Distance",
        "06 - Exclude Connected",
        "07 - Tracks of Interest",
        "08 - Centroids",
        "09 - Areas",
        "10 - Labels"
    };

    //result types
    enum ResultTypes
    {
        c_RES_IMG,
        c_RES_TABLE,
        c_RES_PLOT
    };

    //plot types
    enum PlotTypes
    {
        c_PLO_STAT_AT_RADIUS,
        c_PLO_MEAN_SD,
        c_PLO_MEDIAN_ADM,
        c_PLO_QUANTILES,
        c_PLO_STAT_AT_RADIUS_ALL,
        c_PLO_NUMBER_OF
    };
    QStringList QSL_PlotTypes =
    {
        "Stat at radius",
        "Mean and standard deviation",
        "Median and average absolute deviation from median",
        "Quantiles",
        "Stat at radius (grouped)"
    };

    //table types
    enum TableTypes
    {
        c_TAB_RAW,
        c_TAB_STAT
    };
    QStringList QSL_TableTypes =
    {
        "Single Tracks",
        "Statistics for all Tracks"
    };

    //groups
    enum GroupTypes
    {
        c_GRP_ALL,
        c_GRP_LATERAL,
        c_GRP_DEPTH
    };
    QStringList QSL_GroupsResolution =
    {
        "All",
        "Lateral",
        "Depth"
    };

    //image channel infos
    enum ImageInfoRGB
    {
        c_IMG_BINARY,
        c_IMG_TOI,
        c_IMG_ROI,
        c_IMG_EX_LARGE,
        c_IMG_EX_ASPHERE,
        c_IMG_SAPHETY_RADIUS,
        c_IMG_EX_CONNECTED
    };
    QStringList QSL_ImageInfoRGB =
    {
        "Binary",
        "Tracks of Interest",
        "Region of Interes",
        "Excluded Large",
        "Excluded Aspheres",
        "Saphety Radius",
        "Exclude Connected"
    };
};

#endif // D_MAKRO_IONTRACKS_H
