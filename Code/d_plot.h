/************************************
 *   added:     20.09.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_PLOT_H
#define D_PLOT_H

//own
#include <d_enum.h>
#include <d_img_proc.h>
#include <d_storage.h>
#include <d_stat.h>
#include <d_visdat_obj.h>

//general
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

//Qt
#include <QImage>
#include <QFileInfo>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QStringList>
#include <QLabel>

//Qt-Charts
#include <QChartView>
#include <QChart>
#include <QValueAxis>
#include <QLineSeries>
#include <QAreaSeries>
#include <QSplineSeries>
#include <QScatterSeries>
#include <QPieSeries>
#include <QBarSeries>
#include <QStackedBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QCandlestickSeries>
#include <QCandlestickSet>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>
QT_CHARTS_USE_NAMESPACE

/*!
 * \brief The D_Plot class Plot data in <a href="https://doc.qt.io/qt-5/qchartview.html">QChartView</a> in the user interface.
 * \details Wrapper functions for <a href="https://doc.qt.io/qt-5/qtcharts-index.html">OpenCV</a> methods to plot data in <a href="https://doc.qt.io/qt-5/qchartview.html">QChartView</a>
 */
class D_Plot
{
public:
    D_Plot();

    static int      Plot_Empty                  (QChartView *pChartView, QString QS_Text = "No_Additional_Information");

    static int      Plot_AnyReal                (QChartView *pChartView, vector<vector<double>> *vvX, vector<vector<double>> *vvY, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y, int plot_mode = c_PLOT_SIMPLE_LINE, int mode_crop_y = c_VIS_TRAFO_CROP_DYNAMIC, double in_min_y = 0, double in_max_y = 255, int mode_trafo_y = c_VIS_TRAFO_LINEAR, double gamma_y = 1, double center_y = 0, double divisor_y = 1, int mode_crop_x = c_VIS_TRAFO_CROP_DYNAMIC, double in_min_x = 0, double in_max_x = 255, int mode_trafo_x = c_VIS_TRAFO_LINEAR, double gamma_x = 1, double center_x = 0, double divisor_x = 1);

    static int      Plot_Hist                   (QChartView *pChartView, Mat *pMA_In, bool plot_ch[4], bool uniform, bool accum, double *max_occured);
    static int      Plot_Hist_WithStats         (QChartView *pChartView, vector<double> v_Data, size_t n_classes, QString name_title, QString name_x, bool uni = true, bool acc = false, size_t axe_tick_count = AXE_TICK_COUNT_MAJOR_DEFAULT);
    static int      Plot_Hist_WithStats         (QChartView *pChartView, vector<vector<double>> vv_Data, double min_x, double max_x, size_t n_classes, QString name_title, QString name_x, bool uni = true, bool acc = false, size_t axe_tick_count = AXE_TICK_COUNT_MAJOR_DEFAULT);
    static int      Plot_Hist_WithStats         (QChartView *pChartView, vector<vector<double>> vv_Data, double min_x, double max_x, size_t n_classes, vector<double> v_mean, vector<double> v_std, QString name_title, QString name_x, bool uni = true, bool acc = false, size_t axe_tick_count = AXE_TICK_COUNT_MAJOR_DEFAULT);
    static int      Plot_Hist_WithStats_Color   (QChartView *pChartView, vector<double> v_DataHist, vector<double> v_DataColor, function<double (vector<double>)> F_ColorStat_Hue, function<double (vector<double>)> F_ColorStat_Value, double min_x_hist, double max_x_hist, double min_x_color_hue, double max_x_color_hue, double min_x_color_value, double max_x_color_value, size_t n_classes, double mean_hist, double std_hist, QString name_title, QString name_x, bool uni = true, bool acc = false, size_t axe_tick_count = AXE_TICK_COUNT_MAJOR_DEFAULT);
    static int      Plot_Hist_Single_Classes    (QChartView *pChartView, vector<double> *v_hist, double min, double step, QString name_title, QString name_series, QString name_x, QString name_y, bool ignore_first);
    static int      Plot_Hist_Multi_Classes     (QChartView *pChartView, vector<vector<double>> *vv_hist, double min_x, double max_x, double max_y, double step, QString name_title, QString name_series, QString name_x, QString name_y, bool ignore_first);
    static int      Plot_Hist_Multi_Classes     (QChartView *pChartView, vector<vector<double>> *vv_hist, double min_x, double max_x, double max_y, double step, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y, bool ignore_first);
    static int      Plot_Hist_Any               (QChartView *pChartView, Mat *pMA_In, int classes, QString name_title = "histogram", QString qs_name_series = "channel_", QString name_x = "pixel value", QString name_y = "amount of pixels", bool uniform = true, bool accum = true, bool ignore_first = false);
    static int      Plot_Hist_Any               (QChartView *pChartView, Mat *pMA_In, int classes, QString name_title, QStringList qsl_name_series, QString name_x = "pixel value", QString name_y = "amount of pixels", bool uniform = true, bool accum = true, bool ignore_first = false);
    static int      Plot_Hist_Any               (QChartView *pChartView, D_VisDat_Obj *pVD_In, int classes, QString name_title = "histogram", QString qs_name_series = "channel_", QString name_x = "pixel value", QString name_y = "amount of pixels", bool uniform = true, bool accum = true, bool ignore_first = false);
    static int      Plot_Hist_Any               (QChartView *pChartView, D_VisDat_Obj *pVD_In, int classes, QString name_title, QStringList qsl_name_series, QString name_x = "pixel value", QString name_y = "amount of pixels", bool uniform = true, bool accum = true, bool ignore_first = false);

    static int      Plot_Times_Step             (QChartView *pChartView, unsigned int *times, bool plot_time[4]);
    static int      Plot_Times_All              (QChartView *pChartView, D_Storage *pStore, bool plot_time[4], QLabel *L_total);

    static int      Plot_Bar_PoolStat_Single    (QChartView *pChartView, vector<double> vData_X_Pool, vector<double> vData_Y_Stat, double x_min, double x_max, size_t x_classes, size_t y_stat, QString name_title, QString name_series, QString name_x, QString name_y);
    static int      Plot_BarCore_Single         (QChartView *pChartView, vector<double> v_data, QString name_title, QString name_series, QStringList name_categories, QString name_x, QString name_y);
    static int      Plot_BarCore_Multi          (QChartView *pChartView, vector<vector<double>> vv_data_SetVal, QString name_title, QStringList qsl_name_sets, QStringList name_categories, QString name_x, QString name_y);
    static int      Plot_BarCore_Start1_Single  (QChartView *pChartView, vector<double> *v_hist, QString name_title, QString name_series, QString name_x, QString name_y);

    static int      Plot_Scatter_2D_Parameter   (QChartView *pChartView, vector<vector<vector<double>>> *vvv_ParSetVal, unsigned int set, unsigned int par_x, unsigned int par_y, QString name_title, QString name_series, QString name_x, QString name_y);
    static int      Plot_Scatter_2D_Parameter   (QChartView *pChartView, vector<vector<double>> *vv_ParVal, unsigned int par_x, unsigned int par_y, QString name_title, QString name_series, QString name_x, QString name_y);
    static int      Plot_Scatter_2D_Single_Y    (QChartView *pChartView, vector<double>  v_X_Val, vector<double>  v_Y_Val, QString name_title, QString name_series, QString name_x, QString name_y, bool man_axis_style_x = false, bool man_axis_style_y = false, double man_min_x = 0, double man_max_x = 1, double man_min_y = 0, double man_max_y = 1, int ticks_x = AXE_TICK_COUNT_MAJOR_DEFAULT, int ticks_y = AXE_TICK_COUNT_MAJOR_DEFAULT);
    static int      Plot_Scatter_2D_Single_Y    (QChartView *pChartView, vector<double> *v_X_Val, vector<double> *v_Y_Val, QString name_title, QString name_series, QString name_x, QString name_y, bool man_axis_style_x = false, bool man_axis_style_y = false, double man_min_x = 0, double man_max_x = 1, double man_min_y = 0, double man_max_y = 1, int ticks_x = AXE_TICK_COUNT_MAJOR_DEFAULT, int ticks_y = AXE_TICK_COUNT_MAJOR_DEFAULT);
    static int      Plot_Scatter_2D_Multi_Y     (QChartView *pChartView, vector<double> *v_X_Val, vector<vector<double>> *vv_Y_SerVal, QString name_title, QString name_series, QString name_x, QString name_y);
    static int      Plot_Scatter_2D_Multi_Y     (QChartView *pChartView, vector<double> *v_X_Val, vector<vector<double>> *vv_Y_SerVal, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y);
    static int      Plot_Scatter_2D_Multi_XY    (QChartView *pChartView, vector<vector<double>> *vv_X_SerVal, vector<vector<double>> *vv_Y_SerVal, QString name_title, QString name_series, QString name_x, QString name_y);
    static int      Plot_Scatter_2D_Multi_XY    (QChartView *pChartView, vector<vector<double>> *vv_X_SerVal, vector<vector<double>> *vv_Y_SerVal, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y);

    static int      Plot_Scatter_Heatmap        (QChartView *pChartView, vector<double> vData_X, double min_x, double step_x, bool auto_range_x, size_t classes_x, QString name_x, vector<double> vData_Y, double min_y, double step_y, bool auto_range_y, size_t classes_y, QString name_y, vector<double> vData_Z, size_t stat_z, QString name_z, QString name_title, bool man_axis_style_x = false, bool man_axis_style_y = false, double man_min_x = 0, double man_max_x = 1, double man_min_y = 0, double man_max_y = 1, int ticks_x = AXE_TICK_COUNT_MAJOR_DEFAULT, int ticks_y = AXE_TICK_COUNT_MAJOR_DEFAULT);

    static int      Plot_Poincare_XY_Single     (QChartView *pChartView, vector<double> v_Data, QString name_title, QString name_series, QString name_x, QString name_y, size_t shift_elements = 1, bool show_dots = true, bool show_ellipse = true, bool show_line_YequalX = true, Qt::Alignment legend_pos = Qt::AlignTop);

    static int      Plot_Line_XY_Single         (QChartView *pChartView, vector<double> v_XY_Data, QString name_title, QString name_series, QString name_x, QString name_y, int x_trans = c_AXE_TRANS_LIN, int y_trans = c_AXE_TRANS_LIN, bool dots_visible = false, bool man_axis_style_x = false, bool man_axis_style_y = false, double man_min_x = 0, double man_max_x = 1, double man_min_y = 0, double man_max_y = 1, int ticks_x = AXE_TICK_COUNT_MAJOR_DEFAULT, int ticks_y = AXE_TICK_COUNT_MAJOR_DEFAULT, bool show_n = true);
    static int      Plot_Line_XY_Single         (QChartView *pChartView, vector<double> v_X_Data, vector<double> v_Y_Data, QString name_title, QString name_series, QString name_x, QString name_y, int x_trans = c_AXE_TRANS_LIN, int y_trans = c_AXE_TRANS_LIN, bool dots_visible = false, bool man_axis_style_x = false, bool man_axis_style_y = false, double man_min_x = 0, double man_max_x = 1, double man_min_y = 0, double man_max_y = 1, int ticks_x = AXE_TICK_COUNT_MAJOR_DEFAULT, int ticks_y = AXE_TICK_COUNT_MAJOR_DEFAULT, bool show_n = true);
    static int      Plot_Line_XY_Multi          (QChartView *pChartView, vector<vector<double>> vv_XY_Data, QString name_title, QString name_series, QString name_x, QString name_y, int x_trans = c_AXE_TRANS_LIN, int y_trans = c_AXE_TRANS_LIN, bool dots_visible = false, bool heat_color = false, bool heat_color_AllColors = false, Qt::Alignment legend_pos = Qt::AlignTop);
    static int      Plot_Line_XY_Multi          (QChartView *pChartView, vector<vector<double>> vv_XY_Data, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y, int x_trans = c_AXE_TRANS_LIN, int y_trans = c_AXE_TRANS_LIN, bool dots_visible = false, bool heat_color = false, bool heat_color_AllColors = false, Qt::Alignment legend_pos = Qt::AlignTop);
    static int      Plot_Line_XY_Multi          (QChartView *pChartView, vector<double> v_X_Data, vector<vector<double>> vv_Y_Data, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y, bool dots_visible = false, bool heat_color = false, bool heat_color_AllColors = false, Qt::Alignment legend_pos = Qt::AlignTop);
    static int      Plot_Line_XY_Multi          (QChartView *pChartView, vector<vector<double>> vv_X_Data, vector<vector<double>> vv_Y_Data, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y, bool dots_visible = false, bool heat_color = false, bool heat_color_AllColors = false, Qt::Alignment legend_pos = Qt::AlignTop);
    static int      Plot_Line_XY_Multi          (QChartView *pChartView, vector<vector<double>> vv_X_Data, vector<vector<double>> vv_Y_Data, vector<vector<double>> vv_Y_Errors, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y, bool dots_visible = false, bool heat_color = false, bool heat_color_AllColors = false, Qt::Alignment legend_pos = Qt::AlignTop);

    static int      Plot_LineAreaError_XY       (QChartView *pChartView, vector<double> v_X_Data, vector<double> v_Y_Data_1stVal, vector<double> v_Y_Data_1stErr, vector<double> v_Y_Data_2ndVal, QString name_title, QString name_series_1stVal, QString name_series_1stErr, QString name_series_2ndVal, QString name_x, QString name_y_1st, QString name_y_2nd, int x_trans = c_AXE_TRANS_LIN, int y_trans_1st = c_AXE_TRANS_LIN, int y_trans_2nd = c_AXE_TRANS_LIN, bool dots_visible = false, bool man_axis_style_x = false, bool man_axis_style_y = false, double man_min_x = 0, double man_max_x = 1, double man_min_y_1st = 0, double man_max_y_1st = 1, int ticks_x = AXE_TICK_COUNT_MAJOR_DEFAULT, int ticks_y = AXE_TICK_COUNT_MAJOR_DEFAULT, bool show_n = true);

    static int      Plot_Line_PoolStat_Single   (QChartView *pChartView, vector<double> vData_X_Pool, vector<double> vData_Y_Stat, double x_min, double x_step, size_t x_classes, size_t y_stat, QString name_title, QString qs_name_series, QString name_x, QString name_y, bool auto_range, bool man_axis_style_x = false, bool man_axis_style_y = false, double man_min_x = 0, double man_max_x = 1, double man_min_y = 0, double man_max_y = 1, int ticks_x = AXE_TICK_COUNT_MAJOR_DEFAULT, int ticks_y = AXE_TICK_COUNT_MAJOR_DEFAULT);
    static int      Plot_Line_PoolStat_Single   (QChartView *pChartView, vector<double> vData_X_Pool, vector<double> vData_Y_Stat,                              size_t x_classes, size_t y_stat, QString name_title, QString qs_name_series, QString name_x, QString name_y,                  bool man_axis_style_x = false, bool man_axis_style_y = false, double man_min_x = 0, double man_max_x = 1, double man_min_y = 0, double man_max_y = 1, int ticks_x = AXE_TICK_COUNT_MAJOR_DEFAULT, int ticks_y = AXE_TICK_COUNT_MAJOR_DEFAULT);
    static int      Plot_Line_PoolStat_Single   (QChartView *pChartView, vector<double> vData_X_Pool, vector<double> vData_Y_Stat, double x_min, double x_step, size_t x_classes, size_t y_stat, QString name_title, QString qs_name_series, QString name_x, QString name_y,                  bool man_axis_style_x = false, bool man_axis_style_y = false, double man_min_x = 0, double man_max_x = 1, double man_min_y = 0, double man_max_y = 1, int ticks_x = AXE_TICK_COUNT_MAJOR_DEFAULT, int ticks_y = AXE_TICK_COUNT_MAJOR_DEFAULT);

    static int      Plot_Line_PoolStat_DualErr  (QChartView *pChartView, vector<double> vData_X_Pool, vector<double> vData_Y_Stat, double x_min, double x_step, size_t x_classes, size_t stat_y_main_val, size_t stat_y_main_err, size_t stat_y_secondary_val, QString name_title, QString name_series, QString name_x, QString name_y, bool auto_range, int x_trans = c_AXE_TRANS_LIN, int y_trans_1st = c_AXE_TRANS_LIN, int y_trans_2nd = c_AXE_TRANS_LIN, bool dots_visible = false, bool man_axis_style_x = false, bool man_axis_style_y = false, double man_min_x = 0, double man_max_x = 1, double man_min_y = 0, double man_max_y = 1, int ticks_x = AXE_TICK_COUNT_MAJOR_DEFAULT, int ticks_y = AXE_TICK_COUNT_MAJOR_DEFAULT);
    static int      Plot_Line_PoolStat_DualErr  (QChartView *pChartView, vector<double> vData_X_Pool, vector<double> vData_Y_Stat,                              size_t x_classes, size_t stat_y_main_val, size_t stat_y_main_err, size_t stat_y_secondary_val, QString name_title, QString name_series, QString name_x, QString name_y,                  int x_trans = c_AXE_TRANS_LIN, int y_trans_1st = c_AXE_TRANS_LIN, int y_trans_2nd = c_AXE_TRANS_LIN, bool dots_visible = false, bool man_axis_style_x = false, bool man_axis_style_y = false, double man_min_x = 0, double man_max_x = 1, double man_min_y = 0, double man_max_y = 1, int ticks_x = AXE_TICK_COUNT_MAJOR_DEFAULT, int ticks_y = AXE_TICK_COUNT_MAJOR_DEFAULT);
    static int      Plot_Line_PoolStat_DualErr  (QChartView *pChartView, vector<double> vData_X_Pool, vector<double> vData_Y_Stat, double x_min, double x_step, size_t x_classes, size_t stat_y_main_val, size_t stat_y_main_err, size_t stat_y_secondary_val, QString name_title, QString name_series, QString name_x, QString name_y,                  int x_trans = c_AXE_TRANS_LIN, int y_trans_1st = c_AXE_TRANS_LIN, int y_trans_2nd = c_AXE_TRANS_LIN, bool dots_visible = false, bool man_axis_style_x = false, bool man_axis_style_y = false, double man_min_x = 0, double man_max_x = 1, double man_min_y = 0, double man_max_y = 1, int ticks_x = AXE_TICK_COUNT_MAJOR_DEFAULT, int ticks_y = AXE_TICK_COUNT_MAJOR_DEFAULT);

    static int      Plot_XY_Fit                 (QChartView *pChartView, vector<vector<vector<double>>> vvv_XY_Data_Measure, vector<vector<vector<double>>> vvv_XY_Data_Fit, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y);

    static int      Plot_StatPar_Quantiles      (QChartView *pChartView, vector<vector<vector<double>>> *vvv_ParSetSta, unsigned int par, QString name_title, QString name_series, QString name_x, QString name_y);

    static int      Plot_Stat_Multi_MeanMedian  (QChartView *pChartView, vector<vector<double>> *vv_SetSta, bool pl_mean, bool pl_sd, bool pl_median, bool pl_adm, QString name_title, QString name_categories, QString name_y);
    static int      Plot_Stat_Multi_CvSkewKurt  (QChartView *pChartView, vector<vector<double>> *vv_SetSta, bool pl_cv, bool pl_skew, bool pl_kurt, QString name_title, QString name_categories, QString name_y);
    static int      Plot_Stat_Multi_Quantiles   (QChartView *pChartView, vector<vector<double>> *vv_SetSta, unsigned int steps, QString name_title, QString name_categories, QString name_y);
    static int      Plot_Stat_Multi_Distancees  (QChartView *pChartView, vector<vector<double>> *vv_SetSta, unsigned int steps, QString name_title, QString name_categories, QString name_y);
    static int      Plot_Stat_Multi_Custom      (QChartView *pChartView, vector<vector<vector<double>>> *vvv_ParSetSta, unsigned int par_x, unsigned int par_y, unsigned int stat_x, unsigned int stat_y, QString name_title, QString name_series, QString name_x, QString name_y);

    static int      Plot_Pie_Surrival           (QChartView *pChartView, int surrival, int dead, QString name_title);

    static int      Free_Memory                 (QChartView *pChartView);
};

#endif // D_PLOT_H
