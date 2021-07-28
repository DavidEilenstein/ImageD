/************************************
 *   added:     20.01.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MAKRO_MANUELSEGMENTATION_H
#define D_MAKRO_MANUELSEGMENTATION_H

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
#include <qplaintextedit.h>
#include <QColorDialog>

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
class D_MAKRO_ManuelSegmentation;
}

class D_MAKRO_ManuelSegmentation : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_ManuelSegmentation(D_Storage *pStorage, QWidget *parent = 0);
    ~D_MAKRO_ManuelSegmentation();

    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

private slots:
    void Data_Load();
    void Data_Clear();
    void Data_Next();
    void Data_Previous();

    void Data_CalcContainers_Init();

    void LoadMode_Calib();

    void Save_Analysis();

    void Update_Ui();

    void Update_Views();
    void Update_Images();
    void Update_Image_Draw();
    void Update_Image_Seg();

    void Update_SB_DrawInfo();

    void Update_ImgProc_All();
    void Update_ImgProc(int step_start);
    void Update_ImgProc_Step(int step);

    void Update_Calc_All();
    void Update_Calc_Current_Feats();
    void Update_Calc_Current_Stats();
    void Update_Calc_Pool();
    void Update_Calc_All_Stats();
    void Update_Calc_Selections();

    void Draw_RecieveClickLeft(int x, int y);
    void Draw_RecieveClickRight(int x, int y);
    void Draw_ConsecutiveLine_FG();
    void Draw_ConsecutiveLine_BG();
    void Draw_Floodfill();
    void Draw_Reset();
    void Draw_Undo();
    void Draw_FillHoles();
    void Draw_BackupCreate();
    void Draw_WriteFile();

    void Update_Results();
    void Update_Table_Current_Feat();
    void Update_Table_Current_Stat();
    void Update_Table_All_Feat();
    void Update_Table_All_Stat();

    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init);
    void Populate_CB_Start();

    void ShowList(QPlainTextEdit *text_edit, QStringList QSL_ParentList, vector<int> *vSelection);
    void Edit_FeatsOfInterest();
    void Edit_StatsOfInterest();

    void Draw_Set_Tool_LineForeground();
    void Draw_Set_Tool_LineBackground();
    void Draw_Set_Tool_FillFlood();


    bool Scale_GetFromFile();
    void Scale_WriteToFile();
    void Scale_SetToDefault();
    void Scale_ToUi();
    void Scale_UpdateFactor();
    void Scale_UpdateFactor_Recalculate();

    void Overlay_Set_Color();

    void on_doubleSpinBox_Intensity_Overlay_valueChanged(double arg1);
    void on_doubleSpinBox_Intensity_Backgrouond_valueChanged(double arg1);

    void on_spinBox_Scale_Px_valueChanged(int arg1);
    void on_doubleSpinBox_Scale_CutomUnit_valueChanged(double arg1);
    void on_lineEdit_Scale_CustomUnit_textChanged(const QString &arg1);

private:
    Ui::D_MAKRO_ManuelSegmentation *ui;
    bool ClosingPossible = false;

    //Storage
    D_Storage                           *pStore;

    //Load Mode
    int                                 LoadMode_Current = LOAD_GRAY;
    vector<int>                         vLoadMode_PagesOfInterest_Indices = {0};
    vector<Mat>                         vLoadMode_PagesOfInterest;
    vector<QColor>                      vLoadMode_Colors;
    vector<int>                         vLoadMode_Colors_R;
    vector<int>                         vLoadMode_Colors_G;
    vector<int>                         vLoadMode_Colors_B;
    vector<int>                         vLoadMode_Colors_A;
    D_VisDat_Obj                        VD_LoadAny;
    D_VisDat_Obj                        VD_LoadAny_8bit;

    //Path
    QFileInfoList                       FIL_Images;
    QFileInfoList                       FIL_DrawFiles;
    QFileInfoList                       FIL_Param;
    QStringList                         QSL_Images_Names;
    QStringList                         QSL_Images_Paths;
    QStringList                         QSL_Images_Suffix;
    QDir                                DIR_SaveMaster;

    //Images
    vector<Mat>                         vMA_ProcSteps;

    //Drawing
    int                                 Draw_ActiveTool = DRAW_TOOL_LINE_FG;
    QColor                              Draw_OverlayColor = Qt::green;
    vector<Point>                       Draw_vPoints;
    int                                 Draw_RememberedClicks = 0;
    Mat                                 Draw_MA_Backup;

    //Scaling
    int                                 ScaleInit_Calib_Px = 1000;
    double                              ScaleInit_Calib_CustomUnit = 200;
    double                              ScaleInit_Factor = 0.04;
    QString                             Scale_CustomUnit = "um";
    vector<int>                         Scale_vCalib_Px;
    vector<double>                      Scale_vCalib_CustomUnit;
    vector<double>                      Scale_vFactor;

    //Measurement selections
    vector<int>                         v_FeatsOfInterest   = {c_FEAT_AREA, FEAT_CUSTOM_AREA_SCALED};
    vector<int>                         v_StatsOfInterest   = {c_STAT_SUM, c_STAT_MEAN_ARITMETIC, c_STAT_STAN_DEV_SAMPLE, c_STAT_SEM_ABS_SAMPLE};
    QStringList                         QSL_FeatsOfInterest;
    QStringList                         QSL_StatsOfInterest;
    QStringList                         QSL_FeatsMaster     = QSL_FeatureList;//appended in constructor
    QString                             QS_AreaScaled       = "Area in um";

    //Measurement
    vector<vector<double>>              vv_FeatComp_Current;
    vector<vector<double>>              vv_FeatStat_Current;
    vector<int>                         v_ImgAnalysed;
    vector<vector<vector<double>>>      vvv_ImgFeatComp_All;
    vector<vector<vector<double>>>      vvv_ImgFeatStat_All;
    vector<vector<double>>              vv_FeatComp_All;
    vector<vector<double>>              vv_FeatStat_All;
    vector<vector<double>>              vv_FeatComp_Current_Selection;
    vector<vector<double>>              vv_FeatStat_Current_Selection;
    vector<vector<double>>              vv_FeatComp_All_Selection;
    vector<vector<double>>              vv_FeatStat_All_Selection;

    //Viewers
    D_Viewer                            View_Draw;
    D_Viewer                            View_Segments;

    //statusbar
    QLabel                              *pL_SB_DrawInfo_HowTo;
    QLabel                              *pL_SB_DrawInfo_Selected;

    //Tables
    D_Table                             Table_Current_Feats;
    D_Table                             Table_Current_Stats;
    D_Table                             Table_All_Feats;
    D_Table                             Table_All_Stats;

    //states
    bool                                state_LoadMode_Pages_Calibrated = false;
    bool                                state_Images_Loaded = false;
    bool                                state_CalcContainers_CorrectSize = false;
    bool                                state_Current_ImgProc_Done = false;
    bool                                state_Current_Calc_Done = false;
    bool                                state_All_Calc_Done = false;
    bool                                state_Selections_Calc = false;

    //error handling
    D_Error_Handler ER;
    void ERR(int err, QString func = "no specified", QString detail = "no specified");

    //CONSTANTS
    static const int Draw_ClickMemoryCount = 5;

    enum PARAM {
        PARAM_SCALE_PX,
        PARAM_SCALE_CUSTOM_UNIT,
        PARAM_NUMBER_OF
    };
    const QStringList QSL_Param = {
        "ScalePx",
        "ScaleCustomUnit"
    };

    enum FEAT_CUSTOM {
        FEAT_CUSTOM_AREA_SCALED = c_FEAT_NUMBER_OF_FEATS,
        FEAT_CUSTOM_NUMBER_OF
    };

    enum LOAD_MODE_COLOR {
        LOAD_GRAY,
        LOAD_COLOR,
        LOAD_PAGES_GRAY,
        LOAD_PAGES_COLOR,
        LOAD_NUMBER_OF
    };
    const QStringList QSL_LoadModeColor = {
        "Grayscale Image",
        "Color Image",
        "Multipaged Grayscale Image",
        "Multipaged Color Image"
    };

    enum PROC_STEPS {
        STEP_LOAD,
        STEP_CONVERT_COLOR,
        STEP_DRAW_BINARY,
        STEP_DRAW_EDGES,
        STEP_DRAW_OVERLAY,
        STEP_LABELING,
        STEP_SEGMENTATION_NUMBERS,
        STEP_NUMBER_OF
    };
    const QStringList QSL_ProcSteps = {
        "Load Image",
        "Convert to Color",
        "Draw Binary",
        "Draw Edges",
        "Draw Overlay",
        "Labeling",
        "Segmentation Numbers"
    };

    enum DRAW_TOOL {
        DRAW_TOOL_LINE_FG,
        DRAW_TOOL_LINE_BG,
        DRAW_TOOL_FLOODFILL,
        DRAW_TOOL_NUMBER_OF
    };
    const QStringList QSL_DrawTool = {
        "Consecutive Foreground Line",
        "Consecutive Background Line",
        "Floodfill"
    };

    enum RESULTS {
        RES_GRAPHIC_SEG,
        RES_TAB_CUR_FEAT,
        RES_TAB_CUR_STAT,
        RES_TAB_ALL_FEAT,
        RES_TAB_ALL_STAT,
        RES_NUMBER_OF
    };
    const QStringList QSL_Results = {
        "Segmentation",
        "Current Features",
        "Current Statistics",
        "All Features",
        "All Statistics"
    };
};

#endif // D_MAKRO_MANUELSEGMENTATION_H
