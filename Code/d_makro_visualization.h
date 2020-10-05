/************************************
 *   added:     30.01.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MAKRO_VISUALIZATION_H
#define D_MAKRO_VISUALIZATION_H

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
#include <QColorDialog>
#include <QMouseEvent>

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
class D_MAKRO_Visualization;
}

class D_MAKRO_Visualization : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_MAKRO_Visualization(D_Storage *pStorage, QWidget *parent = 0);
    ~D_MAKRO_Visualization();
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);
    void set_ClosingPossible(bool closeable)     {ClosingPossible = closeable;}

private slots:

    void Images_Add();
    void Images_Clear();
    void Images_DefineDialog();

    void Save_Single();
    void Save_Stack();

    void Populate_All();
    void Populate_Single(QComboBox *CB, QStringList QSL);
    void Populate_Images();
    void Populate_Pages();
    void Populate_Proc();
    void Populate_ViewImgType();
    void Populate_Geometrics();
    void Populate_Paint();

    void BlockSignals_Ui(bool block);
    void ProcSet_SetToUi();
    void GammaSpread_MinMax();

    void Parameters_Init();
    void Images_Init();

    void Paint_GetClickPos(int x, int y);
    void Paint_Init();
    void Paint_Export();
    void Paint_Line();
    void Paint_Fill();
    void Paint_Reset();

    void Update_Views();
    void Update_ImgProc();
    void Update_ImageInfo();
    void Update_ColorPreview();
    void Update_Ui();

    void ColorDialog();

    void ImgProc_Load();
    void ImgProc_PageProc(int page);
    void ImgProc_PseudoColor(int page);
    void ImgProc_Merge_Output();
    void ImgProc_Scalebar();



    void on_comboBox_Image_currentIndexChanged(int index);
    void on_comboBox_Page_currentIndexChanged(int index);
    void on_comboBox_Processing_currentIndexChanged(int index);

    void on_groupBox_Bin_Smooth_clicked(bool checked);
    void on_spinBox_Bin_Size_valueChanged(int arg1);
    void on_doubleSpinBox_Bin_Sigma_valueChanged(double arg1);
    void on_doubleSpinBox_Bin_Threshold_valueChanged(double arg1);
    void on_groupBox_Bin_Segmentation_clicked(bool checked);
    void on_doubleSpinBox_Bin_Distance_valueChanged(double arg1);
    void on_checkBox_Bin_InclNonSeed_clicked(bool checked);
    void on_checkBox_Bin_InclBorder_clicked(bool checked);
    void on_groupBox_Reduce_clicked(bool checked);
    void on_comboBox_Bin_Geometric_currentIndexChanged(int index);

    void on_spinBox_Color_Red_valueChanged(int arg1);
    void on_spinBox_Color_Green_valueChanged(int arg1);
    void on_spinBox_Color_Blue_valueChanged(int arg1);
    void on_spinBox_Color_Alpha_valueChanged(int arg1);

    void on_doubleSpinBox_Val_Gamma_valueChanged(double arg1);
    void on_doubleSpinBox_Val_In_Min_valueChanged(double arg1);
    void on_doubleSpinBox_Val_In_Max_valueChanged(double arg1);
    void on_doubleSpinBox_Val_Out_Min_valueChanged(double arg1);
    void on_doubleSpinBox_Val_Out_Max_valueChanged(double arg1);

    void on_comboBox_ViewImgType_currentIndexChanged(int index);

    void on_groupBox_Bin_Paint_clicked(bool checked);
    void on_comboBox_Bin_Paint_Type_currentIndexChanged(int index);
    void on_comboBox_Bin_Paint_FG_BG_currentIndexChanged(int index);
    void on_spinBox_Bin_Paint_Width_valueChanged(int arg1);
    void on_pushButton_Bin_Paint_Reset_clicked();

    void on_lineEdit_Scalebar_Unit_textChanged(const QString &arg1);
    void on_doubleSpinBox_Scalebar_Pixelsize_valueChanged(double arg1);
    void on_doubleSpinBox_Scalebar_Barsize_valueChanged(double arg1);

    void on_groupBox_Scalebar_clicked();

private:
    Ui::D_MAKRO_Visualization *ui;

    bool                    ClosingPossible = false;

    //Storage
    D_Storage       *pStore;

    //Data
    //images
    QStringList     QSL_Images_Path;
    QStringList     QSL_Images_FileNames;
    QStringList     QSL_Images_BaseNames;
    QFileInfoList   FIL_Images;
    vector<Mat>     vMA_Image_Pages_In;
    vector<Mat>     vMA_Image_Pages_Out_Gray;
    vector<Mat>     vMA_Image_Pages_Out_Color;
    Mat             MA_Output;
    bool            firstRealImages = true;
    //pages
    bool            defined_dataSet = false;
    int             pages_number = 1;
    QStringList     QSL_Pages;
    int             current_page = 0;
    int             current_image = 0;

    //Paint
    bool            paint_initialized = false;
    QDir            DIR_Settings;
    QFileInfo       FI_Paint_FG;
    QFileInfo       FI_Paint_BG;
    Mat             MA_Paint_FG;
    Mat             MA_Paint_BG;
    bool            Paint_NewLine = true;
    Point           Paint_PtCurr;
    Point           Paint_PtLast;

    //Scalebar
    QString         Scalebar_Unit = "px";
    double          Scalebar_Pixelsize = 1.0;
    double          Scalebar_Barsize = 100.0;

    //Save
    bool            stackProcActive = false;
    QDir            DIR_SaveMaster;
    QDir            DIR_SaveStack;
    QDir            DIR_SaveImages;
    QDir            DIR_SaveCurrentImage;

    //PARAMETERS
    vector<vector<double>>  vvd_Parameter_PagePar;
    bool            block_parameter_update = false;


    //View
    D_Viewer        View_Page;
    D_Viewer        View_Output;

    //Error handler
    D_Error_Handler             ER;
    void                        ERR(int err, QString func = "not specified", QString detail = "not specified");

    //CONSTANTS
    enum Parameters
    {
        c_PAR_TYPE,
        c_PAR_BIN_BLUR_DO,
        c_PAR_BIN_BLUR_SIZE,
        c_PAR_BIN_BLUR_SIGMA,
        c_PAR_BIN_BIN_THRES,
        c_PAR_BIN_SEG_DO,
        c_PAR_BIN_SEG_DISTANCE,
        c_PAR_BIN_SEG_INCLNONSEED,
        c_PAR_BIN_SEG_INCLBORDER,
        c_PAR_BIN_GEO_DO,
        c_PAR_BIN_GEO_GEOMETRIC,
        c_PAR_VAL_IN_MIN,
        c_PAR_VAL_IN_MAX,
        c_PAR_VAL_OUT_MIN,
        c_PAR_VAL_OUT_MAX,
        c_PAR_VAL_GAMMA,
        c_PAR_COL_RED,
        c_PAR_COL_GREEN,
        c_PAR_COL_BLUE,
        c_PAR_COL_ALPHA,
        c_PAR_PAINT_DO,
        c_PAR_PAINT_TYPE,
        c_PAR_PAINT_COLOR,
        c_PAR_PAINT_WIDTH,
        c_PAR_NUMBER_OF
    };

    enum ProcTypes
    {
        c_PROC_SKIP,
        c_PROC_COPY,
        c_PROC_BINARY,
        c_PROC_VALUES
    };
    QStringList QSL_ProcTypes =
    {
        "Ignore",
        "Copy",
        "Binary",
        "Values"
    };

    enum ImgType
    {
        c_IMG_IN,
        c_IMG_OUT_GRAY,
        c_IMG_OUT_COLOR,
        c_IMG_NUMBER_OF
    };
    QStringList QSL_ImgType =
    {
        "View: In",
        "View: Out Gray",
        "View: Out Color"
    };

    enum Paint_Color
    {
        c_PAINT_FG,
        c_PAINT_BG
    };
    QStringList QSL_Paint_Color =
    {
        "Foreground",
        "Background"
    };

    enum Paint_Type
    {
        c_PAINT_LINE,
        c_PAINT_FILL
    };
    QStringList QSL_Paint_Type =
    {
        "Line",
        "Fill"
    };
};

#endif // D_MAKRO_VISUALIZATION_H
