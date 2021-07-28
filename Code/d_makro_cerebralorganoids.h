/************************************
 *   added:     13.11.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MAKRO_CEREBRALORGANOIDS_H
#define D_MAKRO_CEREBRALORGANOIDS_H

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
#include <math.h>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

namespace Ui {
class D_MAKRO_CerebralOrganoids;
}

class D_MAKRO_CerebralOrganoids : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_CerebralOrganoids(D_Storage *pStorage, QWidget *parent = 0);
    ~D_MAKRO_CerebralOrganoids();

    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

private slots:
    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init = 0);
    void Populate_CB_Init();
    bool Populate_CB_LoadExp();

    void Load_Exp();

    void UpdateViews();
    void UpdateView_Proc();
    void UpdateView_Vis();
    void UpdateImages();
    void UpdateImage_Proc();
    void UpdateImage_Vis();

    void UpdateUi();

    void UpdateProc_Stack();

    void UpdateImgProc(int step_start);
    void UpdateImgProc_Step(int step);

    bool Calc_Single_All();
    bool Calc_Single_Feats();
    bool Calc_Single_Stats();

    void Calc_Stack_All();
    void Calc_Stack_TD_Comps();
    void Calc_Stack_Flask_Stats();
    void Calc_Stack_TD_Stats();

    void UpdateResults();
    void UpdateResults_Visualization();
    void UpdateResults_Flask();
    void UpdateResults_TD();
    void UpdateResults_Exp();
    void UpdateTable_Flask_Comp();
    void UpdateTable_Flask_Stat();
    void UpdateTable_TD_Comp();
    void UpdateTable_TD_Stat();
    void UpdatePlot_Exp_Stat_Line();
    void UpdatePlot_Exp_Stat_Line_Errors();

    void Save_Image(D_Viewer *pViewer, QString name_default);
    void Save_Plot(QChartView *pCV_Save, QString name_default);
    void Save_Table(D_Table *pTable, QString name_default);
    void Save_Image_Processing();
    void Save_Image_Visualization();
    void Save_Table_Flask();
    void Save_Table_TD();
    void Save_Plot_Experiment();

    bool Save_Analysis_DoAgainQuestion();
    void Save_Analysis();
    void Save_Analysis_Save();
    void Save_Analysis_Update();



    void Update_SettingsMM();

    void on_comboBox_Data_Time_currentIndexChanged(int index);
    void on_comboBox_Data_Dose_currentIndexChanged(int index);
    void on_comboBox_Data_Flask_currentIndexChanged(int index);

    void on_doubleSpinBox_ProcSet_PixelSize_valueChanged(double arg1);

    void on_spinBox_ProcSet_BlurSize_valueChanged(int arg1);

    void on_doubleSpinBox_ProcSet_BlurSigma_valueChanged(double arg1);

    void on_spinBox_ProcSet_ColorSelect_H_Min_valueChanged(int arg1);

    void on_spinBox_ProcSet_ColorSelect_H_Max_valueChanged(int arg1);

    void on_spinBox_ProcSet_ColorSelect_S_Min_valueChanged(int arg1);

    void on_spinBox_ProcSet_ColorSelect_S_Max_valueChanged(int arg1);

    void on_spinBox_ProcSet_ColorSelect_V_Min_valueChanged(int arg1);

    void on_spinBox_ProcSet_ColorSelect_V_Max_valueChanged(int arg1);

    void on_spinBox_ProcSet_ClosingSize_valueChanged(int arg1);

    void on_spinBox_ProcSet_OpeningSize_valueChanged(int arg1);

    void on_doubleSpinBox_ProcSet_SelectArea_Min_valueChanged(double arg1);

    void on_doubleSpinBox_ProcSet_SelectArea_Max_valueChanged(double arg1);

    void on_doubleSpinBox_ProcSet_SelectRoundness_Min_valueChanged(double arg1);

    void on_doubleSpinBox_ProcSet_SelectRoundness_Max_valueChanged(double arg1);

    void on_tabWidget_Results_currentChanged(int index);

    void on_comboBox_ResFlask_Mode_currentIndexChanged(int index);

    void on_comboBox_ResTD_Mode_currentIndexChanged(int index);

    void on_comboBox_ResExp_Mode_currentIndexChanged(int index);

    void on_doubleSpinBox_ProcSet_Thresh_valueChanged(double arg1);

    void on_spinBox_ProcSet_ROI_Close_valueChanged(int arg1);

    void on_spinBox_ProcSet_ROI_Open_valueChanged(int arg1);

    void on_spinBox_ProcSet_ROI_Area_valueChanged(int arg1);

    void on_spinBox_ProcSet_ROI_Dilate_valueChanged(int arg1);

private:
    Ui::D_MAKRO_CerebralOrganoids       *ui;
    bool                                ClosingPossible = false;

    //Storage
    D_Storage                           *pStore;

    //Viewer
    D_Viewer                            ViewProc;
    D_Viewer                            ViewRes;

    //Table
    D_Table                             Table_Flask;
    D_Table                             Table_TD;


    //Plot
    QChartView                          *pChartView;

    //Files and Paths
    //Experiment
    QString                             QS_ExpName;
    QDir                                DIR_Experiment;
    //Time
    vector<QDir>                        vDIR_Times;
    QStringList                         QSL_Times;
    vector<double>                      vVAL_Times;
    //Dose
    vector<vector<QDir>>                vvDIR_Dose;
    vector<QStringList>                 vQSL_Dose;
    vector<vector<double>>              vvVAL_Dose;
    //Flask
    vector<vector<vector<QFileInfo>>>   vvvFI_Flask;
    vector<vector<QStringList>>         vvQSL_Flask;
    //Reference
    QFileInfo                           FIL_Reference;

    //Save
    QDir                                DIR_Save_Main;
    QDir                                DIR_Save_Images;
    QDir                                DIR_Save_Tables;
    QDir                                DIR_Save_Plots;
    ofstream                            OS_comps;
    vector<vector<ofstream>>            vvOS_stats;
    vector<int>                         vFeatsOfInterest        = {FEAT_CUSTOM_AREA_MM, c_FEAT_AREA, c_FEAT_ROUNDNESS};
    vector<int>                         vStatsOfInterest_Line   = {c_STAT_MEAN_ARITMETIC};
    vector<int>                         vStatsOfInterest_Errors = {c_STAT_STAN_DEV_TOTAL, c_STAT_SEM_ABS_TOTAL};
    vector<int>                         vStatsOfInterest_All    = {c_STAT_MEAN_ARITMETIC, c_STAT_STAN_DEV_TOTAL, c_STAT_SEM_ABS_TOTAL};

    //Style
    QString                             StyleDefault;


    //states
    bool                                state_exp_loaded = false;
    bool                                state_img_loaded_current = false;
    bool                                state_img_proc_up2date_current = false;
    bool                                state_stack_analysed = false;
    bool                                state_stack_processing = false;
    bool                                state_calced_stack = false;
    bool                                state_calced_stack_comps = false;
    bool                                state_calced_stack_stats = false;
    bool                                state_calced_current = false;
    bool                                state_calced_current_feats = false;
    bool                                state_calced_current_stats = false;

    //Data
    vector<vector<double>>                          vvFeatComp_current;
    vector<vector<double>>                          vvFeatStat_current;
    vector<vector<vector<vector<vector<double>>>>>  vvvvvTimeDoseFlaskFeatComp;
    vector<vector<vector<vector<vector<double>>>>>  vvvvvTimeDoseFlaskFeatStat;
    vector<vector<vector<vector<double>>>>          vvvvTimeDoseFeatComp;
    vector<vector<vector<vector<double>>>>          vvvvTimeDoseFeatStat;

    //pixel size
    double                          px_scale;//mm

    //Img Proc
    vector<Mat>                     vMA_ProcSteps;
    vector<vector<int>>             vvProcSteps_up2date;

    //Visualization
    Mat                             MA_Vis;

    //mouse hover pixel value display
    QLabel                          *pL_SB_PxVal;

    //Error handler
    D_Error_Handler ER;
    void ERR(int err, QString func = "not specified", QString detail = "not specified");

    //CONSTANTS
    enum PROC_STEP {
        STEP_LOAD,
        STEP_BLUR,
        STEP_COLOR_HSV,
        STEP_COLOR_HUE,
        STEP_COLOR_SAT,
        STEP_COLOR_VAL,
        STEP_COLOR_GRAB,
        STEP_OBJ_CLOSING,
        STEP_OBJ_OPENING,
        STEP_OBJ_SELECT_AREA,
        STEP_OBJ_SELECT_ROUNDNESS,
        STEP_GRAY,
        STEP_ROI_THRES,
        STEP_ROI_CLOSING,
        STEP_ROI_OPENING,
        STEP_ROI_AREA,
        STEP_ROI_DILATION,
        STEP_ROI_CONVEX_HULL,
        STEP_OBJECTS_ACCEPTED,
        STEP_NUMBER_OF
    };
    const QStringList QSL_ProcStep = {
        "00 Load",
        "01 Blur",
        "02 Color HSV",
        "03 Color Hue",
        "04 Color Saturation",
        "05 Color Value",
        "06 Color Grab",
        "07 Objects Closing",
        "08 Objects Opening",
        "09 Objects Select by Area",
        "10 Objects Select by Roundness",
        "11 Gray",
        "12 Roi Binary",
        "13 Roi Closing",
        "14 Roi Opening",
        "15 Roi Area",
        "16 Roi Margin",
        "17 Roi Convex Hull",
        "18 Objects Accepted",
    };

    enum FEAT_CUSTOM {
        FEAT_CUSTOM_AREA_MM = c_FEAT_NUMBER_OF_FEATS,
        FEAT_CUSTOM_NUMBER_OF
    };
    const QStringList QSL_FeatCustom = {
        "Area(mm^2)"
    };
    QStringList QSL_FeatAll;


    enum RES_TYPE {
        RES_VIS,
        RES_FLASK,
        RES_TD,
        RES_EXP,
        RES_NUMBER_OF
    };

    enum RES_TYPE_FLASK {
        RES_TYPE_FLASK_COMP,
        RES_TYPE_FLASK_STAT,
        RES_TYPE_FLASK_NUMBER_OF
    };
    const QStringList QSL_ResType_Flask = {
        "Features of Components in Flask",
        "Statistics of Features in Components in Flask"
    };

    enum RES_TYPE_TD {
        RES_TYPE_TD_COMP,
        RES_TYPE_TD_STAT,
        RES_TYPE_TD_NUMBER_OF
    };
    const QStringList QSL_ResType_TD = {
        "Features of Components at Time and Dose",
        "Statistics of Features in Components at Time and Dose"
    };

    enum RES_TYPE_EXP {
        RES_TYPE_EXP_STATS_LINE_ERR,
        RES_TYPE_EXP_STATS_LINE,
        RES_TYPE_EXP_NUMBER_OF
    };
    const QStringList QSL_ResType_Exp = {
        "Statistics of Features vs Time and Dose with Errors",
        "Statistics of Features vs Time and Dose"
    };
};

#endif // D_MAKRO_CEREBRALORGANOIDS_H
