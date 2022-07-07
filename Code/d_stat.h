/************************************
 *   added:     12.10.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_STAT_H
#define D_STAT_H

//own
#include <d_enum.h>

//general
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <thread>

//Qt
#include <QString>
#include <QDebug>
#include <QStringList>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

/*!
 * \brief The D_Stat class Calculate statistical quantities of vectors of values.
 * \details There are methods that function as a factory for functors for statistical quantities as well as methods that calculate a list of stats from a list of numbers.
 * There are linear statistics, circular statistics and 2D statistics. Use these enumerators: D_STATISTIC_ENUM , D_STATISTIC_2D_ENUM and D_STATISTIC_CIRC_ENUM
 */
class D_Stat
{
public:
    D_Stat();

    static int          Calc_Stats                  (vector<double> *v_stats, vector<double> v_data, bool calc_sorted);
    static int          Calc_Stats_2D               (vector<double> *v_stats, vector<double> v_data_x, vector<double> v_data_y);
    static int          Calc_Stats_Circ_Rad         (vector<double> *v_stats, vector<double> v_data_a);
    static int          Calc_Stats_Circ_Grad        (vector<double> *v_stats, vector<double> v_data_a);

    static function<double (vector<double>)>        Function_SingleStat(int stat);
    static function<uchar  (vector<double>)>        Function_SingleStat_8bit(int stat);
    static function<double (vector<double>)>        Function_SingleStat_Circ_Rad(int stat);

    static double           Mean                        (vector<double> v_data, double nan_value = NAN);
    static double           MeanWeighted                (vector<double> v_data, vector<double> v_weights, double nan_value = NAN);

    static int              Calc_Vector2Hist_1          (vector<double> *v_hist, vector<double> *v_data, unsigned int class_count, double *min_ext, double *max_ext, double *max_y_ext, double *step_ext, bool accumulate, bool uniform);
    static int              Calc_Vector2Hist_2          (vector<vector<double>> *vv_hist, vector<vector<double>> *vv_data, unsigned int class_count, double *min_ext, double *max_ext, double *max_y_ext, double *step_ext, bool accumulate, bool uniform);

    static double           AxeTrans                    (double in_val, int trans_index);
    static int              Calc_MinMax                 (double* min, double* max, vector<double> vData);
    static int              Calc_MinMax                 (double* min, double* max, vector<double>* vData);
    static int              Calc_MinMax                 (vector<double> v_y_data, double *x_min_ext, double *x_max_ext, double *y_min_ext, double *y_max_ext, int x_trans = c_AXE_TRANS_LIN, int y_trans = c_AXE_TRANS_LIN);
    static int              Calc_MinMax                 (vector<vector<double>> vv_sy_data, double *x_min_ext, double *x_max_ext, double *y_min_ext, double *y_max_ext, int x_trans = c_AXE_TRANS_LIN, int y_trans = c_AXE_TRANS_LIN);

    static double           Quant                       (vector<double> *v_stats, unsigned int index);
    static double           Quant_Norm                  (vector<double> *v_stats, unsigned int index);
    static double           Quant_1stD                  (vector<double> *v_stats, unsigned int index, unsigned int step_width);
    static double           Quant_1stD_Norm             (vector<double> *v_stats, unsigned int index, unsigned int step_width);
    static double           Dist                        (vector<double> *v_stats, unsigned int index);
    static double           Dist_Norm                   (vector<double> *v_stats, unsigned int index);
    static double           Dist_1stD                   (vector<double> *v_stats, unsigned int index, unsigned int step_width);
    static double           Dist_1stD_Norm              (vector<double> *v_stats, unsigned int index, unsigned int step_width);

    static bool             Optimize(double val, double *opt, int opt_type);
    static double           Optimize_Init(int opt_type);

    static size_t           Value2PoolIndex(double val, double min, double range, size_t classes);
    static double           PoolCenter_From_Value(size_t class_index, double min, double range, size_t classes);
    static int              PoolStat_Data(vector<Point2d>* vData_Out_PoolStat, vector<double> vData_X_Pool, vector<double> vData_Y_Stat, double x_min, double x_step, size_t x_classes, size_t y_stat);
    static int              PoolStat_Data(vector<double>* pvData_Out_x_Pools, vector<double>* pvData_Out_y_Stats, vector<double> vData_X_Pool, vector<double> vData_Y_Stat, double x_min, double x_step, size_t x_classes, size_t y_stat);
    static int              PoolStat_Data(vector<double>* pvData_Out_x_Pools, vector<vector<double>>* pvvData_Out_y_Stats, vector<double> vData_X_Pool, vector<double> vData_Y_Stat, double x_min, double x_step, size_t x_classes, vector<size_t> vy_stat);


private:
    static double           DistCircular_Rad        (double angle1, double angle2);
    static double           DistCircular_Grad       (double angle1, double angle2);
    static void             DistCircular_Rad_Sum    (double *sum_abs, double *sum_sqr, vector<double> v_angles, size_t index_start, size_t index_end);
    static void             DistCircular_Grad_Sum   (double *sum_abs, double *sum_sqr, vector<double> v_angles, size_t index_start, size_t index_end);
    static vector<double>   Convert_Rad2Grad        (vector<double> v_data_a_rad);
    static vector<double>   Convert_Grad2Rad        (vector<double> v_data_a_grad);
};


#endif // D_STAT_H
