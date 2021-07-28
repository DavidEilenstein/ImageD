/************************************
 *   added:     ??.??.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MAKRO_OSTEOCLASTS_H
#define D_MAKRO_OSTEOCLASTS_H

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
#include <QMouseEvent>
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
class D_MAKRO_Osteoclasts;
}

class D_MAKRO_Osteoclasts : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_Osteoclasts(D_Storage *pStorage, QWidget *parent = 0);
    ~D_MAKRO_Osteoclasts();

    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

private slots:

    void Update_Views();
    void Update_View_Proc();

    void Update_Images();
    void Update_Image_ProcView();
    void Update_Image_ProcView_Visualize();
    void Update_Image_ProcView_SegmentationAuto();
    void Update_Image_ProcView_SegmentationManual();

    void Update_newViewport();

    void Update_NucleiSegmentation_Auto();
    void Update_NucleiSegmentation_Auto_Steps(int start_step);

    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init = 0);
    void Populate_CB_All_onStartUp();
    void Populate_CB_All_onImgInit();
    void Populate_CB_Stats();
    void Populate_CB_AxeTrans();
    void Populate_CB_Dimensions();
    void Populate_CB_Draw();
    void Populate_CB_ProcSteps();
    void Populate_CB_Segmentations();

    void Images_NucleiSegmentation_Init();
    void Images_VisVPin_init();

    void Load_Platelet();

    void Visualize_DataSet();

    void Segmentation_Next();

    void SegmentationManual_DIR_Init();
    void SegmentationManual_Scan();
    void SegmentationManual_Load(int seg_type);
    void SegmentationManual_Init(int seg_type);
    void SegmentationManual_Save(int seg_type);
    void SegmentationManual_Reset();
    void SegmentationManual_Backup();
    void SegmentationManual_Undo();
    void SegmentationManual_AdaptUi2BackupState();
    void SegmentationManual_TriggerDraw(int x, int y);
    void Segmentations_Combine();
    void Segmentations_Combine(int seg_type);

    void Extrema_Init();
    void Extrema_Viewport();
    void Extrema_2ui();

    void VisVP_MouseMovedOnScene(int x, int y);

    void on_comboBox_Viewport_currentIndexChanged(int index);


    void on_spinBox_SegAuto_Blur_Size_valueChanged(int arg1);

    void on_doubleSpinBox_SegAuto_Blur_Sigma_valueChanged(double arg1);

    void on_spinBox_SegAuto_Thres_Size_valueChanged(int arg1);

    void on_doubleSpinBox_SegAuto_Thres_Offset_valueChanged(double arg1);

    void on_doubleSpinBox_SegAuto_Distance_Thres_valueChanged(double arg1);

    void on_checkBox_SegAuto_Watershed_Bordered_stateChanged(int arg1);

    void on_checkBox_SegAuto_Watershed_nSeeded_stateChanged(int arg1);

    void on_spinBox_SegAuto_Area_Min_valueChanged(int arg1);

    void on_spinBox_SegAuto_Area_Max_valueChanged(int arg1);

    void on_doubleSpinBox_SegAuto_Roundness_Thres_valueChanged(double arg1);

    void on_comboBox_SegMan_SegmentationType_currentIndexChanged(int index);

    void on_comboBox_SegMan_Draw_Type_currentIndexChanged(int index);


private:
    Ui::D_MAKRO_Osteoclasts *ui;
    bool                            ClosingPossible = false;
    const bool                      MessageOnFunctionStart = true;
    const bool                      MessageOnBreakFromState = false;

    //Paths
    QDir                            DIR_InputPlatelet;
    QDir                            DIR_Segmentations;
    QStringList                     QSL_Viewport_Path;
    QString                         QS_PlateletName;
    QFileInfoList                   FIL_Segmentations_current;
    //bool                            segmentations_DirFil_init = false;
    //bool                            segmentations_DirFil_scanned = false;

    //States
    bool                            state_Startup               = true;

    bool                            state_Platelet_New          = true;
    bool                            state_Platelet_Loaded       = false;

    bool                            state_SegPath_Init          = false;

    bool                            state_Viewport_New          = true;
    bool                            state_Viewport_Loaded       = false;

    bool                            state_VisVP_Init            = false;
    bool                            state_VisVP_Updating        = false;
    bool                            state_VisVp_Done            = false;

    bool                            state_SegAuto_Init          = false;
    bool                            state_SegAuto_Updating      = false;
    bool                            state_SegAuto_Done          = false;

    bool                            state_SegMan_Init           = false;
    bool                            state_SegMan_Scanned        = false;
    bool                            state_SegMan_Combined       = false;
    bool                            state_SegMan_Draw_Active    = false;
    bool                            state_SegMan_Draw_NewLine   = true;



    //Images

    //Original Data
    vector<vector<vector<Mat>>>     vvvMA_VpZCh_Stacks;                     //Base Data
  //bool                            loaded_PlateletImages = false;

    //Visualizer
    vector<Mat>                     vMA_Ch_VisVP_in;                        //used for displaying Viewport (color)
    Mat                             MA_VisVP_3ch;                           //displayed visVP image
  //bool                            proced_visVP = false;

    //Nuclei segmentation (auto)
    vector<vector<Mat>>             vvMA_VpStep_NucAutoSeg;                 //Automatic Nuclei Segmentation
  //bool                            proced_NucSegAuto = false;

    //Segmnentations (manual)
    vector<vector<Mat>>             vvMA_VpSeg_Manual_Saved;                //Saved Segmentations
    vector<vector<Mat>>             vvMA_VpSeg_Manual_Combined;             //Displayed Combined
    vector<vector<vector<Mat>>>     vvvMA_VpSegStep_Manual_Backup;          //Backups
    vector<vector<unsigned int>>    vvI_VpSeg_ActionsCount;                 //Draw Action Counter
    vector<vector<unsigned int>>    vvI_VpSeg_UndoCount;                    //Undo Counter
    static const int                c_SEG_MAN_BACKUPS = 10;                 //Max count of Backups



    //Ranges
    vector<vector<vector<double>>>  vvvd_ProjExtCh_Extrema;

    //Dimensions
    QStringList                     QSL_Viewport_Names;
    QStringList                     QSL_Depths;
    int                             Dim_Viewports = 0;
    int                             DIM_Depths = 0;
    int                             VP_current = 0;

    //Drawing tool
    Point                           PT_Draw_Last = Point(0, 0);
    Point                           PT_Draw_Current = Point(0, 0);
  //bool                            Draw_New_Line = true;

    //Storage
    D_Storage                       *pStore;

    //Viewer
    D_Viewer                        View_Proc;
    D_Viewer                        View_Results;

    //Plot
    QChartView                      *pChartView_Plot;

    //Table
    D_Table                         Table_Results;

    //Error handler
    D_Error_Handler             ER;
    void                        ERR(int err, QString func = "not specified", QString detail = "not specified");
    void                        ERR_StatesCheck(QString func);

    //CONSTANTS

    enum ProcViews
    {
        c_PROC_VIEW_STACK,
        c_PROC_VIEW_SEG_AUTO,
        c_PROC_VIEW_SEG_MANUAL
    };

    enum VisualizeParameters
    {
        c_VIS_PAR_DISPLAY,
        c_VIS_PAR_PROJECT,
        c_VIS_PAR_Z_LAYER,
        c_VIS_PAR_RANGE_MIN,
        c_VIS_PAR_RANGE_MAX,
        c_VIS_PAR_GAMMA,
        c_VIS_PAR_NUMBER_OF
    };

    enum Projected
    {
        c_PROJ_SINGLE_IMAGES,
        c_PROJ_CURRENT_PROJECTION,
        c_PROJ_NUMBER_OF
    };

    enum Extrema
    {
        c_EXTREMA_MIN,
        c_EXTREMA_MAX,
        c_EXTREMA_NUMBER_OF
    };

    enum Channels
    {
        c_CH_B_DAPI,
        c_CH_G_FACTIN,
        c_CH_R_TRAP,
        c_CH_NUMBER_OF
    };
    QStringList QSL_Channels =
    {
        "Dapi",
        "F-Actin",
        "Trap"
    };

    enum Segmentations
    {
        c_SEG_CELLS,
        c_SEG_ZONES,
        c_SEG_NUCLEI,
        c_SEG_NUMBER_OF
    };
    QStringList QSL_Segmentations =
    {
        "1_Cells",
        "2_Zones",
        "3_Nuclei"
    };

    enum SegmentationsSave
    {
        c_SEG_SAVE_CELLS,
        c_SEG_SAVE_ZONES,
        c_SEG_SAVE_NUCLEI_FG,
        c_SEG_SAVE_NUCLEI_BG,
        c_SEG_SAVE_NUMBER_OF
    };
    QStringList QSL_SegmentationsSave =
    {
        "Cells",
        "Zones",
        "NucleiFG",
        "NucleiBG"
    };

    enum SegmentationColor
    {
        c_SEG_COLOR_FOREGROUND,
        c_SEG_COLOR_BACKGROUND,
        c_SEG_COLOR_NUMBER_OF
    };
    QStringList QSL_SegmentationColor =
    {
        "Pencil",
        "Rubber"
    };

    enum SegmentationPen
    {
        c_SEG_PEN_LINE,
        c_SEG_PEN_FILL,
        c_SEG_PEN_NUMBER_OF
    };
    QStringList QSL_SegmentationPen =
    {
        "Line",
        "Floodfill"
    };

    enum ProcSteps
    {
        c_STEP_PROJECT,
        c_STEP_8BIT,
        c_STEP_BLUR,
        c_STEP_THRES,
        c_STEP_DISTANCE,
        c_STEP_SEEDS,
        c_STEP_WATERSHED,
        c_STEP_AREA,
        c_STEP_ROUNDNESS,
        c_STEP_OUTLINES,
        c_STEP_CONTROL,
        c_STEP_NUMBER_OF
    };
    QStringList QSL_ProcSteps =
    {
        "00 - Nuclei Projection",
        "01 - Convert 8bit",
        "02 - Blur",
        "03 - Threshold",
        "04 - Distance Transform",
        "05 - Seeds",
        "06 - Watershed Transform",
        "07 - Area Filter",
        "08 - Roundness Filter",
        "09 - Outlines",
        "10 - Control"
    };


};

#endif // D_MAKRO_OSTEOCLASTS_H
