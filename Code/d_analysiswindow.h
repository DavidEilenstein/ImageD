/************************************
 *   added:     17.12.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_ANALYSISWINDOW_H
#define D_ANALYSISWINDOW_H

//own
#include <d_enum.h>
#include <d_stat.h>
#include <d_component.h>
#include <d_component_list.h>
#include <d_value_distribution_list.h>
#include <d_plot.h>
#include <d_img_proc.h>
#include <d_storage.h>
#include <d_viewer.h>
#include <d_table.h>

//general
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

//Qt
#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QFileInfo>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QInputDialog>
#include <QComboBox>
#include <QElapsedTimer>

//Qt::Charts
#include <QChartView>
#include <QChart>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

namespace Ui {
class D_AnalysisWindow;
}

/*!
 * \brief The D_AnalysisWindow class GUI based custom analysis of images.
 * \details It takes a label image and any number of value images and generates lots of statistics and graphs based on these.
 * There are "features" that describe the shape of an object and there are "statistics" that describe the distribution of values in the blobs.
 */
class D_AnalysisWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit D_AnalysisWindow(D_Storage *pStorage, QWidget *parent = 0);
    ~D_AnalysisWindow();

    void resizeEvent(QResizeEvent* event);

private slots:

    void Image_Label_Get();
    void Image_Binary_Add();
    void Image_Value_Add_Dialog();
    void Image_Value_Add(Mat *pMA_add, QString name);
    void Image_Value_Clear();

    void Save_ImagePlotTable();
    void Save_Image();
    void Save_Plot();
    void Save_Table();

    void Calc_All();
    void Calc_ValDistr();
    void Calc_ImgComVal();
    void Calc_ImgComAxeClaSta();
    void Calc_ImgComSta();
    void Calc_ComFea();
    void Calc_ImgStaSta();
    void Calc_FeaSta();
    void Calc_StaStaSta();

    void Update_Images();
    void Update_Image_Label();
    void Update_Image_Value();
    void Update_Image_Stat();
    void Update_Image_Feature();

    void Update_Views();
    void Update_View_Label();
    void Update_View_Value();
    void Update_View_Stat();
    void Update_View_Feature();
    void Update_View_Plot();

    void Update_Plot();

    void Plot_Pixel_Histogram();
    void Plot_Pixel_Values_on_Axis();
    void Plot_Pixel_ScatterValue();
    void Plot_Pixel_ScatterHist();
    void Plot_Pixel_ScatterAxe();

    void Plot_Comp_Feature();
    void Plot_Comp_FeatureHist();
    void Plot_Comp_FeatureScatter();
    void Plot_Comp_Stat();
    void Plot_Comp_StatHist();
    void Plot_Comp_StatScatter();
    void Plot_Comp_StatFeatScatter();

    void Plot_Img_Feature();
    void Plot_Img_FeatureHist();
    void Plot_Img_Stat();
    void Plot_Img_StatHist();
    void Plot_Img_StatScatter();
    void Plot_Img_StatFeatScatter();

    void Plot_Stack_Stat();

    void Populate_CB();
    void Populate_CB_Stats();
    void Populate_CB_Feature();
    void Populate_CB_ImageNames();
    void Populate_CB_ImageNames_Single(QComboBox *CB);
    void Populate_CB_ComponentNames();
    void Populate_CB_ComponentNames_Single(QComboBox *CB);
    void Populate_CB_Geometrics();
    void Populate_CB_Geometrics_Single(QComboBox *CB);
    void Populate_CB_Axe();
    void Populate_CB_PlotTypes();
    void Populate_CB_Single(QComboBox *CB, QStringList QSL);
    void Populate_CB_PlotModePixel();
    void Populate_CB_PlotModeComp();

    void Init_ComponentNames();
    void Rename_Image();
    void Rename_Component();

    void on_comboBox_ImgLab_Connectivity_currentIndexChanged(int index);

    void on_comboBox_PlotPixel_Hist_Mode_currentIndexChanged(int index);
    void on_comboBox_PlotPixel_Axe_Mode_currentIndexChanged(int index);
    void on_comboBox_PlotPixel_ScatterValue_Mode_currentIndexChanged(int index);
    void on_comboBox_PlotPixel_ScatterHist_Mode_currentIndexChanged(int index);
    void on_comboBox_PlotPixel_ScatterAxe_Mode_currentIndexChanged(int index);

    void on_comboBox_PlotComp_Stat_Mode_currentIndexChanged(int index);
    void on_comboBox_PlotComp_StatHist_Mode_currentIndexChanged(int index);
    void on_comboBox_PlotComp_StatScatter_Mode_currentIndexChanged(int index);

    void on_comboBox_PlotComp_StatFeatScatter_Mode_currentIndexChanged(int index);

    void on_checkBox_Plot_X_Range_clicked(bool checked);

    void on_checkBox_Plot_Y_Range_clicked(bool checked);

private:
    Ui::D_AnalysisWindow *ui;

    //Store
    D_Storage                           *pStore;

    //Images & basic containers
    int                                 connectivity = 8;
    Mat                             MA_Label;
    Mat                             MA_Binary;
    vector<Mat>                     vMA_Images;
    vector<Mat>                     vMA_Images_8bit;
    vector<D_Value_Distribution_List>   v_ValDistList;
    QStringList                         QSL_ImageNames;
    QStringList                         QSL_ImageNames_noBinary;
    QStringList                         QSL_ComponentNames;


    //result images
    Mat                             MA_Features;
    Mat                             MA_Stats;

    //checks
    bool                                b_LabelLoaded = false;
    bool                                b_Calced_ValDistr = false;
    bool                                b_Calced_ImgComVal = false;
    bool                                b_Calced_ImgComAxeClaSta = false;
    bool                                b_Calced_ImgComSta = false;
    bool                                b_Calced_ComFea = false;
    bool                                b_Calced_ImgStaSta = false;
    bool                                b_Calced_FeaSta = false;
    bool                                b_Calced_StaStaSta = false;

    //DATA
    //pixels
    vector<vector<vector<double>>>                  vvvd_ImgComVal_val;
    vector<vector<vector<vector<vector<double>>>>>  vvvvvd_ImgComAxeClaSta_val;
    vector<vector<vector<vector<vector<double>>>>>  vvvvvd_ImgComAxeStaCla_val;
    //components
    vector<vector<vector<double>>>                  vvvd_ImgComSta_val;
    vector<vector<vector<double>>>                  vvvd_ImgStaCom_val;
    vector<vector<double>>                          vvd_ComFea_fea;
    vector<vector<double>>                          vvd_FeaCom_fea;
    //images
    vector<vector<vector<double>>>                  vvvd_ImgStaSta_val;
    vector<vector<double>>                          vvd_FeaSta_fea;
    //stack
    vector<vector<vector<double>>>                  vvvd_StaStaSta_val;


    //Viewer
    D_Viewer                    Viewer_Image;

    //Plots
    QChartView                  *pChartView_Plot;
    void                        Init_Plot();

    //Table
    D_Table                     Table_PlottedData;

    //Save
    bool                        AutoSave = false;

    //Error handler
    D_Error_Handler             ER;
    void                        ERR(int err, QString func = "not specified", QString detail = "not specified");

    //CONSTANTS

    //Image Types
    enum IMAGE_TYPES  {
        IMAGE_LABEL,
        IMAGE_VALUE,
        IMAGE_FEATURE,
        IMAGE_STATS
    };

    //Plot Types
    enum PLOT_TYPE_MASTER  {
        PLOT_PIXEL,
        PLOT_COMP,
        PLOT_IMAGE,
        PLOT_STACK
    };

    //Plot Pixel--------------------------------------------
    enum PLOT_TYPE_PIXEL {
        PLOT_PIXEL_HIST,
        PLOT_PIXEL_AXE,
        PLOT_PIXEL_SCATTER_VALUE,
        PLOT_PIXEL_SCATTER_HIST,
        PLOT_PIXEL_SCATTER_AXE
    };
    const QStringList QSL_PlotTypes_Pixel =
    {
        "Histogram of Pixel Values",
        "Value Distribution on Axis",
        "Compare Values",
        "Compare Histograms",
        "Compare Values on Axis"
    };

    //Plot Comp Mode
    enum PLOT_MODE_COMP {
        PLOT_MODE_COMP_SINGLE,
        PLOT_MODE_COMP_ALL_IMG
    };
    const QStringList QSL_PlotModes_Comp =
    {
        "Single",
        "All Images"
    };

    //Plot Component--------------------------------------------
    enum PLOT_TYPE_COMP {
        PLOT_COMP_FEAT_BAR,
        PLOT_COMP_FEAT_HIST,
        PLOT_COMP_FEAT_SCATTER,
        PLOT_COMP_STAT_BAR,
        PLOT_COMP_STAT_HIST,
        PLOT_COMP_STAT_SCATTER,
        PLOT_COMP_STATFEAT_SCATTER
    };
    const QStringList QSL_PlotTypes_Component =
    {
        "Features",
        "Features Histogram",
        "Features Compare",
        "Statistics",
        "Statistics Histogram",
        "Statistics Compare",
        "Statistics vs Feature"
    };

    //Plot Pixel Mode
    enum PLOT_MODE_PIXEL {
        PLOT_MODE_PIXEL_SINGLE,
        PLOT_MODE_PIXEL_ALL_COMP,
        PLOT_MODE_PIXEL_ALL_IMG
    };
    const QStringList QSL_PlotModes_Pixel =
    {
        "Single",
        "All Components",
        "All Images"
    };

    //Plot Image--------------------------------------------
    enum PLOT_TYPE_IMAGE {
        PLOT_IMAGE_FEAT,
        PLOT_IMAGE_STAT,
        PLOT_IMAGE_STAT_HIST,
        PLOT_IMAGE_STAT_SCATTER
        //PLOT_IMAGE_STATFEAT_SCATTER,
        //PLOT_IMAGE_FEAT_HIST
    };
    const QStringList QSL_PlotTypes_Image =
    {
        "Features",
        "Statistics",
        "Statistics Histogram",
        "Statistics Compare"
        //"Statistics vs Feature"
        //"Features Histogram",
    };

    //Plot Stack--------------------------------------------
    enum PLOT_TYPE_STACK {
        PLOT_STACK_STAT
    };
    const QStringList QSL_PlotTypes_Stack =
    {
        "Statistics"
    };

};

#endif // D_ANALYSISWINDOW_H
