/************************************
 *   added:     09.10.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MAKRO_MITOCHONDRIEN_H
#define D_MAKRO_MITOCHONDRIEN_H

//own
#include <d_enum.h>
#include <scenemousetrack.h>
#include <d_img_proc.h>
#include <d_plot.h>
#include <d_storage.h>
#include <d_stat.h>
#include <d_error_handler.h>
#include <d_viewer.h>

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
#include <QTextDocument>
#include <QTextBlock>
#include <QGridLayout>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QDateTime>
#include <QDesktopServices>
#include <QUrl>
#include <QComboBox>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
using namespace cv;

namespace Ui {
class D_MAKRO_Mitochondrien;
}

class D_MAKRO_Mitochondrien : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_Mitochondrien(D_Storage *pStorage, QWidget *parent = 0);
    ~D_MAKRO_Mitochondrien();

    void closeEvent(QCloseEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

public slots:
    void Update_ImgProc_All();

private slots:
    void mousePressEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);

    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init);

    void Update_ImgProc_Photons(unsigned int start_step);
    void Update_ImgProc_Parameters();
    void Convert_Parameters_8bit_All();
    void Convert_Parameters_8bit_RoI();
    void Update_ImgProc_Results(unsigned int start_step);
    void Update_Step_Photons(unsigned int step);

    void Update_Results_Proc();
    void Update_Results_Proc_Force();

    void Update_Step_Results(unsigned int step);

    void Update_Combi_Results();
    void Update_Math_Image();

    void Update_Plot_Hist_Img();
    void Update_Plot_Hist_Cells();

    void Update_Plot_Parameter_Pixel();
    void Update_Plot_Parameter_Cells();

    void Update_Plot_Stat_MeanMedian();
    void Update_Plot_Stat_CvSkewKurt();
    void Update_Plot_Stat_Quantiles();

    void Calc_Data_All();
    int  Calc_Data_Split_Img2vv();
    void Calc_Data_Parameter_Stats();

    void Calc_T2_Handling();
    void Calc_NADPH_NADH_All();
    void Calc_NADPH_NADH();
    void Calc_NADH();
    void Calc_NADPH();

    void Stream_Stats_Start();
    void Stream_Init();
    void Stream_Stats();
    void Stream_ImagesPlots();
    void Stream_Settings();
    void Stream_Stats_End();

    void Update_Views();
    void Update_View_Photons();
    void Update_View_Parameters();
    void Update_View_Results();
    void Update_View(QImage *QI_Show, Mat *MA_Show, QPixmap *PX_Show, SceneMouseTrack *SC_Show, QGraphicsView *GV_Show, double *x_factor, double *y_factor);
    void Update_Ui();

    void Populate_CB_Style();
    void Update_Style();

    void Load_Directory();
    void Load_Images();
    void Clear_Queue();
    void Next_Image();

    void Save_Image_Photons();
    void Save_Image_Parameters();
    void Save_Image_Results();
    void Save_Image(QImage *QI_Save, QString name_default);
    void Save_Image(D_Viewer *ViewerSave, QString name_default);
    void Save_Plot();
    void Save_Plot(QChartView *pCV_Save, QString name_default);

    //Manual RoI
    void Get_Click_Pos(int x, int y);
    void Draw_Line();
    void Fill_Background();
    void CellSep_Undo();
    void CellSep_Load();
    void CellSep_Save();
    void CellSep_Open();
    void Set_Scale_Factor_View(QImage *QI, QGraphicsView *GV);
    void Init_Cell_Regions();
    void Export_Cell_Regions();

    //Statusbar
    void Update_SB_ValAtPos(int x, int y, Mat *pMA);

    //UI adapt
    void AdaptUI_NADH_p_NADPH_MinMax();
    void AdaptUI_Results();

    void ERR(int err, QString func = "no specified", QString detail = "no specified");

    void on_spinBox_PhoCon_Blur_Size_valueChanged(int arg1);

    void on_doubleSpinBox_PhoCon_Blur_Sigma_valueChanged(double arg1);

    void on_spinBox_PhoCon_Thres_Size_valueChanged(int arg1);

    void on_doubleSpinBox_PhoCon_Thres_Offset_valueChanged(double arg1);

    void on_comboBox_PhoVie_Step_currentIndexChanged(int index);

    void on_spinBox_PhoCon_EdgCon_Size_valueChanged(int arg1);

    void on_pushButton_PhoCon_Paint_Reset_clicked();

    void on_pushButton_ResCon_Zoom_Reset_clicked();

    void on_spinBox_His_ClassCount_valueChanged(int arg1);

    void on_comboBox_ResCon_Rubberband_currentIndexChanged(int index);

    void on_pushButton_RessCon_Zoom_In_clicked();

    void on_pushButton_ResCon_Zoom_Out_clicked();

    void on_spinBox_ParAll_ClassCount_valueChanged(int arg1);

    void on_action_Autoselect_Save_Filename_triggered(bool checked);

    void on_doubleSpinBox_ParCon_T2_Min_Const_valueChanged(double arg1);

    void on_doubleSpinBox_ParCon_T2_Max_Const_valueChanged(double arg1);

    void on_doubleSpinBox_ParCon_T2_Min_Thres_valueChanged(double arg1);

    void on_doubleSpinBox_ParCon_T2_Max_Thres_valueChanged(double arg1);

    void on_action_Show_Photons_triggered(bool checked);

    void on_action_Show_Parameters_triggered(bool checked);

    void on_action_Show_Results_triggered(bool checked);

    void on_comboBox_AnalysedImage_currentIndexChanged(int index);

    void on_radioButton_PhoCon_Paint_Line_clicked(bool checked);

    void on_comboBox_PhoCon_Paint_FillStep_currentIndexChanged(int index);

    void on_radioButton_PhoCon_Paint_Fill_clicked(bool checked);

private:
    Ui::D_MAKRO_Mitochondrien *ui;

    bool                    ClosingPossible = false;

    //Data Storage
    Mat             MA_Init;
    D_Storage       *pStore;
    unsigned int    pos_dest;

    //Files
    QDir            DIR_Input_Dir;
    QFileInfoList   FIL_Input_Images;
    QString         QS_Image_BasePath;
    QString         QS_Image_BaseName;
    bool            Auto_SaveName = false;

    //Photons
    vector<Mat>     vMA_Photons;

    //Parameters
    vector<Mat>     vMA_Parameter_All_Float;
    vector<Mat>     vMA_Parameter_All_8Bit;
    vector<Mat>     vMA_Parameter_RoI_Float;
    vector<Mat>     vMA_Parameter_RoI_8Bit;
    QStringList     QSL_Parameter_Suffixes;
    unsigned int    PARAMETERS;
    unsigned int    PARAMETERS_only_input;
    bool            param_set = false;
    void            Init_Parameters();
    void            Read_Parameters_From_UI();
    void            Populate_CB_Parameters();
    void            Init_vMA_Parameter();

    //Shading Correct
    Mat             MA_Reference;
    void            Load_Reference();
    QFileInfo       FI_Reference;
    bool            Exist_Refernce = false;

    //Output Data
    bool                            Calc_Done = false;
    bool                            CB_Cells_Updated = false;
    unsigned int                    CellCount = 0;
    vector<int>                     CellColor_LUT;
    vector<vector<vector<double>>>  vvv_Data_ParNucPix;
    vector<vector<vector<double>>>  vvv_Stat_ParNucSta;
    void                            Populate_CB_Cells();
    void                            Check_Parameter_Existence();
    void                            Norm_Parameters();
    bool                            Exist_photons = false;
    bool                            Exist_t1 = false;
    bool                            Exist_t2 = false;
    bool                            Exist_a1 = false;
    bool                            Exist_a2 = false;
    bool                            Exist_chi = false;
    bool                            Calced_NADPH_NADH = false;
    bool                            Calced_NADH = false;
    bool                            Calced_NADPH = false;
    //vector<double>                  v_NADH;
    //vector<double>                  v_NADPH;
    //vector<double>                  v_NADPH_NADH;
    void                            Populate_CB_Stat();
    QStringList                     QSL_Stats;

    //Results
    vector<Mat>     vMA_Results;
    Mat             MA_Color;
    QStringList     QSL_Results;
    void            Init_QSL_Results();
    void            Populate_CB_Results();
    void            Init_MatVector(vector<Mat> *vec, unsigned int l);

    //Math
    Mat             MA_Math;

    //Manual Seperation of cells
    //Mat             MA_Cell_Regions;
    bool            ManSep_Manip = false;
    bool            ManSep_Line_Begin = true;
    double          ManSep_Scale_Factor = 1.0;
    QPoint          ManSep_Pos_Last;
    QPoint          ManSep_Pos_Curr;
    QDir            DIR_CellSep;
    QDir            DIR_CellSep_Img;
    QFileInfo       FI_CellSep;
    bool            ManSep_FromFile;
    Mat             MA_CellSep_Last;

    //Display images
    D_Viewer        Viewer_Photons;
    D_Viewer        Viewer_Parameters;
    D_Viewer        Viewer_Results;
    /*QImage          QI_Photons;
    QImage          QI_Parameters;
    QImage          QI_Results;
    QPixmap         PX_Photons;
    QPixmap         PX_Parameters;
    QPixmap         PX_Results;
    SceneMouseTrack SC_Photons;
    SceneMouseTrack SC_Parameters;
    SceneMouseTrack SC_Results;
    void            Init_GraphicsView(QGraphicsView *view, SceneMouseTrack *scene);
    double          scale_factor_x_photons;
    double          scale_factor_y_photons;
    double          scale_factor_x_parameters;
    double          scale_factor_y_parameters;
    double          scale_factor_x_results;
    double          scale_factor_y_results;*/

    //Display plot
    QChartView      *ChartView_Plot;
    QChart          *Chart_Plot;
    void            Init_Plot();

    //stream to output data
    bool            Stream_Open = false;
    ofstream        OS_Stream_Summary;
    vector<ofstream>OS_Stream_Parameters;
    QDir            DIR_Stream;
    bool            Auto_ResultsProc_blocked = false;

    //Statusbar
    QLabel          *L_SB_ValAtPos;
    QLabel          *L_SB_Size;

    //CONSTANTS

    D_Error_Handler ER;

    //Result types
    static const unsigned int
    c_RT_IMAGE              = 0,
    c_RT_PLOT               = 1;
    static const unsigned int
    c_RT_IMAGE_COLOR        = 0,
    c_RT_IMAGE_MATH         = 1;
    static const unsigned int
    c_RT_PLOT_HIST_IMG      = 0,
    c_RT_PLOT_HIST_CELL     = 1,
    c_RT_PLOT_PAR_PIXEL     = 2,
    c_RT_PLOT_PAR_CELL      = 3,
    c_RT_PLOT_STAT_MM       = 4,
    c_RT_PLOT_STAT_CSK      = 5,
    c_RT_PLOT_STAT_QUANT    = 6;

    //Counts
    static const unsigned int
    c_SC_PHOTONS            = 11,
    c_SC_PARAMETERS         = 2,
    c_SC_RESULTS            = 7;

    //Photon Steps
    static const unsigned int
    c_ST_PH_LOAD            = 0,
    c_ST_PH_SHADE_CORRECT   = 1,
    c_ST_PH_INPUT_CONV_8bit = 2,
    c_ST_PH_INPUT_CONTRAST  = 3,
    c_ST_PH_INPUT_BLUR      = 4,
    c_ST_PH_BIN_THRES       = 5,
    c_ST_PH_REGIONS_EDGES   = 6,
    c_ST_PH_REGIONS_CONNECT = 7,
    c_ST_PH_REGIONS_SEP_VIEW= 8,
    c_ST_PH_REGIONS_LABEL   = 9,
    c_ST_PH_ROI_MITO        = 10;

    //Parameter Steps
    static const unsigned int
    c_ST_PA_ALL             = 0,
    c_ST_PA_ROI             = 1;
    unsigned int           //const after first load of images
    INDEX_NADPH_NADH        = 0,
    INDEX_NADH              = 0,
    INDEX_NADPH             = 0,
    INDEX_T1                = 0,
    INDEX_T2                = 0,
    INDEX_PHOTONS           = 0,
    INDEX_A2                = 0,
    INDEX_A1                = 0,
    INDEX_CHI               = 0;

    //Results Steps
    static const unsigned int
    c_ST_RE_EMPTY           = 0,
    c_ST_RE_PH_INPUT        = 1,
    c_ST_RE_PH_CONTRAST     = 2,
    c_ST_RE_PH_BINARY       = 3,
    c_ST_RE_PH_EDGES        = 4,
    c_ST_RE_PH_LABEL_NUMBER = 5,
    c_ST_RE_PH_EDGES_NUMBER = 6;
};

#endif // D_MAKRO_MITOCHONDRIEN_H
