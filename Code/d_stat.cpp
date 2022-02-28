/************************************
 *   added:     12.10.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_stat.h"

D_Stat::D_Stat()
{

}

int D_Stat::Calc_Stats(vector<double> *v_stats, vector<double> v_data, bool calc_sorted)
{
    //qDebug() << "Calc_Stats-------------------------------------";

    //allocate space for stats
    v_stats->clear();
    v_stats->resize(c_STAT_NUMBER_OF_STATS, 0.0);

    //count
    size_t n = v_data.size();
    (*v_stats)[c_STAT_COUNT] = n;
    if(n == 0)
        return ER_empty;

    //sort data (needed for quantiles - see below)
    if(calc_sorted)
        sort(v_data.begin(), v_data.end());

    //sum
    int n_non_zero      = 0;
    double sum          = 0;
    double sum_abs      = 0;
    double sum_non_zero = 0;
    double sum_squares  = 0;
    for(size_t i = 0; i < n; i++)
    {
        double val      =  v_data[i];
        sum             += val;
        sum_abs         += abs(val);
        sum_squares     += val * val;

        if(val != 0)
        {
            n_non_zero++;
            sum_non_zero += val;
        }
    }
    (*v_stats)[c_STAT_SUM]                  = sum;
    (*v_stats)[c_STAT_SUM_OF_ABS]           = sum_abs;
    (*v_stats)[c_STAT_SUM_OF_SQUARES]       = sum_squares;

    //mean
    double mean = sum / n;
    double mean_abs = sum_abs / n;
    double mean_non_zero = n_non_zero > 0 ? sum_non_zero / n_non_zero : 0;
    (*v_stats)[c_STAT_MEAN_ARITMETIC]               = mean;
    (*v_stats)[c_STAT_MEAN_ARITMETIC_OF_ABS]        = mean_abs;
    (*v_stats)[c_STAT_MEAN_ARITMETIC_OF_NON_ZERO]   = mean_non_zero;

    //potences of diff of mean
    double variance_cum = 0;
    double skewness_cum = 0;
    double kurtosis_cum = 0;
    for(size_t i = 0; i < n; i++)
    {
        //diff to mean and powers
        double mean_diff_p1 = mean - v_data[i];
        double mean_diff_p2 = mean_diff_p1 * mean_diff_p1;
        double mean_diff_p3 = mean_diff_p2 * mean_diff_p1;
        double mean_diff_p4 = mean_diff_p3 * mean_diff_p1;

        //cumulate
        variance_cum += mean_diff_p2;
        skewness_cum += mean_diff_p3;
        kurtosis_cum += mean_diff_p4;
    }

    //variance
    double variance_tot = variance_cum / n;
    double variance_sam = variance_tot;
    if(n > 1) variance_sam = variance_cum / (n - 1);    //only do this correct formula if no zero division occurs
    (*v_stats)[c_STAT_VARIANCE_TOTAL] = variance_tot;
    (*v_stats)[c_STAT_VARIANCE_SAMPLE] = variance_sam;

    //standard deviation
    double stan_dev_tot = sqrt(variance_tot);
    double stan_dev_sam = sqrt(variance_sam);
    (*v_stats)[c_STAT_STAN_DEV_TOTAL] = stan_dev_tot;
    (*v_stats)[c_STAT_STAN_DEV_SAMPLE] = stan_dev_sam;

    //skewness
    double skewness_tot = skewness_cum / (n * sqrt(variance_tot * variance_tot * variance_tot));
    double skewness_sam = skewness_cum / (n * sqrt(variance_sam * variance_sam * variance_sam));
    (*v_stats)[c_STAT_SKEWNESS_TOTAL] = skewness_tot;
    (*v_stats)[c_STAT_SKEWNESS_SAMPLE] = skewness_sam;

    //kurtosis
    double kurtosis_tot = kurtosis_cum / (n * variance_tot * variance_tot) - 3;
    double kurtosis_sam = kurtosis_cum / (n * variance_sam * variance_sam) - 3;
    (*v_stats)[c_STAT_KURTOSIS_TOTAL] = kurtosis_tot;
    (*v_stats)[c_STAT_KURTOSIS_SAMPLE] = kurtosis_sam;

    //coeffiecient of variance
    double var_coef_tot = stan_dev_tot / mean;
    double var_coef_sam = stan_dev_sam / mean;
    (*v_stats)[c_STAT_VAR_COEF_TOTAL] = var_coef_tot;
    (*v_stats)[c_STAT_VAR_COEF_SAMPLE] = var_coef_sam;

    //standard error to the mean
    double sem_abs_tot = 0;
    if(n > 0)   sem_abs_tot = stan_dev_tot / sqrt(n);
    double sem_abs_sam = 0;
    if(n > 0)   sem_abs_sam = stan_dev_sam / sqrt(n);
    double sem_rel_tot = 0;
    if(n > 0)   sem_rel_tot = var_coef_tot / sqrt(n);
    double sem_rel_sam = 0;
    if(n > 0)   sem_rel_sam = var_coef_sam / sqrt(n);
    (*v_stats)[c_STAT_SEM_ABS_TOTAL] = sem_abs_tot;
    (*v_stats)[c_STAT_SEM_ABS_SAMPLE] = sem_abs_sam;
    (*v_stats)[c_STAT_SEM_REL_TOTAL] = sem_rel_tot;
    (*v_stats)[c_STAT_SEM_REL_SAMPLE] = sem_rel_sam;

    //Reference constants
    (*v_stats)[c_STAT_CONST_0] = 0;
    (*v_stats)[c_STAT_CONST_1] = 1;

    //only proceed if calc_sorted====================================================================
    if(!calc_sorted)
        return ER_okay;

    //Quantiles
    (*v_stats)[c_STAT_MINIMUM]      = (v_data)[(unsigned int)(0.00 * (n - 1))];
    (*v_stats)[c_STAT_QUANTIL_05]   = (v_data)[(unsigned int)(0.05 * (n - 1))];
    (*v_stats)[c_STAT_QUANTIL_10]   = (v_data)[(unsigned int)(0.10 * (n - 1))];
    (*v_stats)[c_STAT_QUANTIL_15]   = (v_data)[(unsigned int)(0.15 * (n - 1))];
    (*v_stats)[c_STAT_QUANTIL_20]   = (v_data)[(unsigned int)(0.20 * (n - 1))];
    (*v_stats)[c_STAT_QUARTIL_LOW]  = (v_data)[(unsigned int)(0.25 * (n - 1))];
    (*v_stats)[c_STAT_QUANTIL_30]   = (v_data)[(unsigned int)(0.30 * (n - 1))];
    (*v_stats)[c_STAT_QUANTIL_35]   = (v_data)[(unsigned int)(0.35 * (n - 1))];
    (*v_stats)[c_STAT_QUANTIL_40]   = (v_data)[(unsigned int)(0.40 * (n - 1))];
    (*v_stats)[c_STAT_QUANTIL_45]   = (v_data)[(unsigned int)(0.45 * (n - 1))];
    (*v_stats)[c_STAT_MEDIAN]       = (v_data)[(unsigned int)(0.50 * (n - 1))];
    (*v_stats)[c_STAT_QUANTIL_55]   = (v_data)[(unsigned int)(0.55 * (n - 1))];
    (*v_stats)[c_STAT_QUANTIL_60]   = (v_data)[(unsigned int)(0.60 * (n - 1))];
    (*v_stats)[c_STAT_QUANTIL_65]   = (v_data)[(unsigned int)(0.65 * (n - 1))];
    (*v_stats)[c_STAT_QUANTIL_70]   = (v_data)[(unsigned int)(0.70 * (n - 1))];
    (*v_stats)[c_STAT_QUARTIL_UP]   = (v_data)[(unsigned int)(0.75 * (n - 1))];
    (*v_stats)[c_STAT_QUANTIL_80]   = (v_data)[(unsigned int)(0.80 * (n - 1))];
    (*v_stats)[c_STAT_QUANTIL_85]   = (v_data)[(unsigned int)(0.85 * (n - 1))];
    (*v_stats)[c_STAT_QUANTIL_90]   = (v_data)[(unsigned int)(0.90 * (n - 1))];
    (*v_stats)[c_STAT_QUANTIL_95]   = (v_data)[(unsigned int)(0.95 * (n - 1))];
    (*v_stats)[c_STAT_MAXIMUM]      = (v_data)[(unsigned int)(1.00 * (n - 1))];
    //min/max/med/up_quart/low_quart are double indexed and calced at this point

    //average absolute devation of median
    double median = (*v_stats)[c_STAT_MEDIAN];
    double dev_med = 0;
    for(unsigned int i = 0; i < n; i++)
        dev_med += abs(median - (v_data)[i]);
    dev_med /= (double)n;
    (*v_stats)[c_STAT_ABS_DEV_MED] = dev_med;

    //10%-distances
    (*v_stats)[c_STAT_SPAN]          = (*v_stats)[c_STAT_MAXIMUM]    - (*v_stats)[c_STAT_MINIMUM];
    (*v_stats)[c_STAT_DIST_90_0_PRZ] = (*v_stats)[c_STAT_QUANTIL_95] - (*v_stats)[c_STAT_QUANTIL_05];
    (*v_stats)[c_STAT_DIST_80_0_PRZ] = (*v_stats)[c_STAT_QUANTIL_90] - (*v_stats)[c_STAT_QUANTIL_10];
    (*v_stats)[c_STAT_DIST_70_0_PRZ] = (*v_stats)[c_STAT_QUANTIL_85] - (*v_stats)[c_STAT_QUANTIL_15];
    (*v_stats)[c_STAT_DIST_60_0_PRZ] = (*v_stats)[c_STAT_QUANTIL_80] - (*v_stats)[c_STAT_QUANTIL_20];
    (*v_stats)[c_STAT_DIST_QUARTIL]  = (*v_stats)[c_STAT_QUARTIL_UP] - (*v_stats)[c_STAT_QUARTIL_LOW];
    (*v_stats)[c_STAT_DIST_40_0_PRZ] = (*v_stats)[c_STAT_QUANTIL_70] - (*v_stats)[c_STAT_QUANTIL_30];
    (*v_stats)[c_STAT_DIST_30_0_PRZ] = (*v_stats)[c_STAT_QUANTIL_65] - (*v_stats)[c_STAT_QUANTIL_35];
    (*v_stats)[c_STAT_DIST_20_0_PRZ] = (*v_stats)[c_STAT_QUANTIL_60] - (*v_stats)[c_STAT_QUANTIL_40];
    (*v_stats)[c_STAT_DIST_10_0_PRZ] = (*v_stats)[c_STAT_QUANTIL_55] - (*v_stats)[c_STAT_QUANTIL_45];

    //"sigma"-distances
    (*v_stats)[c_STAT_DIST_68_3_PRZ] = (v_data)[(unsigned int)(0.8415 * (n - 1))] - (v_data)[(unsigned int)(0.1585 * (n - 1))];
    (*v_stats)[c_STAT_DIST_95_4_PRZ] = (v_data)[(unsigned int)(0.9770 * (n - 1))] - (v_data)[(unsigned int)(0.0230 * (n - 1))];
    (*v_stats)[c_STAT_DIST_99_7_PRZ] = (v_data)[(unsigned int)(0.9985 * (n - 1))] - (v_data)[(unsigned int)(0.0015 * (n - 1))];

    return ER_okay;
}

/*
int D_Stat::Calc_Stats_2D(vector<double> *v_stats, vector<double> v_data_x, vector<double> v_data_y)
{
    //Errors
    if(v_data_x.empty())                    return ER_empty;
    if(v_data_y.empty())                    return ER_empty;
    if(v_data_x.size() != v_data_y.size())  return ER_size_missmatch;
    int ER = ER_okay;

    //sample size
    double n = static_cast<double>(v_data_x.size());

    //Stats of single datasets

    //x
    vector<double> v_stats_x;
    ER = Calc_Stats(&v_stats_x, v_data_x, false);
    if(ER != ER_okay)   return ER;

    //y
    vector<double> v_stats_y;
    ER = Calc_Stats(&v_stats_y, v_data_y, false);
    if(ER != ER_okay)   return ER;

    //stats of x and y needed for further calculation
    double mean_x           = v_stats_x[c_STAT_MEAN_ARITMETIC];
    double mean_y           = v_stats_y[c_STAT_MEAN_ARITMETIC];
    double var_tot_x        = v_stats_x[c_STAT_VARIANCE_TOTAL];
    double var_tot_y        = v_stats_y[c_STAT_VARIANCE_TOTAL];
    double var_sam_x        = v_stats_x[c_STAT_VARIANCE_SAMPLE];
    double var_sam_y        = v_stats_y[c_STAT_VARIANCE_SAMPLE];

    //usefull calced datasets
    vector<double>  v_dif_yx(n);
    vector<double>  v_dif_yx_rel(n);
    vector<double>  v_dif_xm_tms_dif_ym(n);
    bool            dif_yx_rel_is_inf = false;
    //loop
    for(size_t i = 0; i < n; i++)
    {
        //data
        double x        = v_data_x[i];
        double y        = v_data_y[i];

        //diff
        double dif_yx   = y - x;

        //mean
        double mean_yx  = 0.5 * (y + x);

        //export
        v_dif_yx[i]            = dif_yx;
        v_dif_xm_tms_dif_ym[i] = (x - mean_x) * (y - mean_y);

        //rel
        if(mean_yx == 0)
        {
            v_dif_yx_rel[i] = 0;
            if(dif_yx != 0)
                dif_yx_rel_is_inf = true;
        }
        else
        {
            v_dif_yx_rel[i] = dif_yx / mean_yx;
        }
    }

    //stats of secondary data sets

    //yx
    vector<double> v_stats_dif_yx;
    ER = Calc_Stats(&v_stats_dif_yx, v_dif_yx, false);
    if(ER != ER_okay)   return ER;

    //yx rel
    vector<double> v_stats_dif_yx_rel;
    ER = Calc_Stats(&v_stats_dif_yx_rel, v_dif_yx_rel, false);
    if(ER != ER_okay)   return ER;

    //for covariance
    vector<double> v_stats_dif_xm_tms_dif_ym;
    ER = Calc_Stats(&v_stats_dif_xm_tms_dif_ym, v_dif_xm_tms_dif_ym, false);
    if(ER != ER_okay)   return ER;

    //covariance
    double covar_cum                        = v_stats_dif_xm_tms_dif_ym[c_STAT_SUM];
    double covar_tot                        = covar_cum / n;
    double covar_sam                        = covar_tot;
    if(n > 1) covar_sam                     = covar_cum / (n - 1);

    //correlation
    double correl_tot = 0;
    double correl_sam = 0;
    if(var_tot_x != 0 && var_tot_y != 0)    correl_tot = covar_tot / sqrt(var_tot_x * var_tot_y);
    if(var_sam_x != 0 && var_sam_y != 0)    correl_sam = covar_sam / sqrt(var_sam_x * var_sam_y);

    //R^2
    double r_square_tot                     = correl_tot * correl_tot;
    double r_square_sam                     = correl_sam * correl_sam;

    //linear fit
    double lin_fit_a = 0;
    if(var_sam_x != 0)                      lin_fit_a = covar_sam / var_sam_x;
    double lin_fit_b                        = mean_y - (lin_fit_a * mean_x);

    //difference of data to linear fit
    vector<double> v_residuals(n);
    for(size_t i = 0; i < n; i++)
        v_residuals[i] = (lin_fit_a * v_data_x[x] + lin_fit_b) - v_data_y[i];

    //stats of fit
    vector<double> v_stats_residuals;
    ER = Calc_Stats(&v_stats_residuals, v_residuals, false);
    if(ER != ER_okay)   return ER;

    //useful stats
    double ss_mean_y                = v_stats_y[c_STAT_SUM_OF_SQUARES];
    double ss_fit_y                 = v_stats_residuals[c_STAT_SUM_OF_SQUARES];
    double ss_y_explained_by_x      = ss_mean_y - ss_fit_y;
    double ss_y_not_explained_by_x  = ss_fit_y;
    double free_deg_fit             = 2;
    double free_deg_mean            = 1;
    double free_deg_reduced_by_fit  = free_deg_fit - free_deg_mean;

    //F-Value
    bool free_deg_fail = false;
    double F_value = 0;
    if(free_deg_fit < n || ss_fit_y != 0 || free_deg_reduced_by_fit != 0)
        F_value = ((ss_y_explained_by_x)/(free_deg_reduced_by_fit)) / ((ss_fit_y)/(n - free_deg_fit));
    else
        free_deg_fail = true;



    //calc sucessful?
    if(dif_yx_rel_is_inf || free_deg_fail)
        return ER_other;
    else
        return ER_okay;
}
*/

int D_Stat::Calc_Stats_2D(vector<double> *v_stats, vector<double> v_data_x, vector<double> v_data_y)
{
    if(v_data_x.empty())                    return ER_empty;
    if(v_data_y.empty())                    return ER_empty;
    if(v_data_x.size() != v_data_y.size())  return ER_size_missmatch;

    int ER = ER_okay;

    //Stats x
    vector<double> v_stats_x;
    ER = Calc_Stats(&v_stats_x, v_data_x, false);
    if(ER != ER_okay)   return ER;

    //Stats y
    vector<double> v_stats_y;
    ER = Calc_Stats(&v_stats_y, v_data_y, false);
    if(ER != ER_okay)   return ER;

    //single stats to be used for further calculation
    double n            = v_stats_x[c_STAT_COUNT];
    double mean_x       = v_stats_x[c_STAT_MEAN_ARITMETIC];
    double mean_y       = v_stats_y[c_STAT_MEAN_ARITMETIC];
    double var_tot_x    = v_stats_x[c_STAT_VARIANCE_TOTAL];
    double var_tot_y    = v_stats_y[c_STAT_VARIANCE_TOTAL];
    double var_sam_x    = v_stats_x[c_STAT_VARIANCE_SAMPLE];
    double var_sam_y    = v_stats_y[c_STAT_VARIANCE_SAMPLE];

    //resize & clear
    v_stats->clear();
    v_stats->resize(c_STAT_2D_NUMBER_OF, 0);

    //residuals
    vector<double> v_residulas;
    v_residulas.resize(n);

    //potences of diff of mean and other loop stuff
    double covar_cum = 0;
    double sum_rel_resid = 0;

    //loop to calc stuff
    for(unsigned int i = 0; i < n; i++)
    {
        //x, y, residual
        double x = v_data_x[i];
        double y = v_data_y[i];
        double r = abs(x - y);

        //diffs from means
        double mean_diff_x  = x - mean_x;
        double mean_diff_y  = y - mean_y;

        //residuals
        v_residulas[i]      = r;

        //weight
        double mean_asb_xy  = abs(0.5 * (x + y));

        //cumulate sums
        covar_cum           += mean_diff_x * mean_diff_y;

        if(sum_rel_resid != INFINITY)
            if(r != 0)
            {
                if(mean_asb_xy != 0)
                    sum_rel_resid += r / mean_asb_xy;
                else
                    sum_rel_resid = INFINITY;
            }
    }

    //Stats residuals
    vector<double> v_stats_r;
    ER = Calc_Stats(&v_stats_r, v_residulas, false);
    if(ER != ER_okay)   return ER;

    //mean relative differences of x and y
    double mean_rel_res = INFINITY;
    if(sum_rel_resid != INFINITY)                   mean_rel_res = sum_rel_resid / n;
    (*v_stats)[c_STAT_2D_DIFF_REL_MEAN]            = mean_rel_res;

    //basic residual stats export
    (*v_stats)[c_STAT_2D_DIFF_SUM_ABS]             = v_stats_r[c_STAT_SUM];
    (*v_stats)[c_STAT_2D_DIFF_SQUARE_SUM]          = v_stats_r[c_STAT_SUM_OF_SQUARES];
    (*v_stats)[c_STAT_2D_DIFF_ABS_MEAN]            = v_stats_r[c_STAT_MEAN_ARITMETIC];

    //covariance
    double covar_tot                                = covar_cum / n;
    double covar_sam                                = covar_tot;
    if(n > 1)                                       covar_sam = covar_cum / (n - 1);
    (*v_stats)[c_STAT_2D_COVARIANCE_TOTAL]          = covar_tot;
    (*v_stats)[c_STAT_2D_COVARIANCE_SAMPLE]         = covar_sam;

    //korrelation
    double correl_tot = 0;
    double correl_sam = 0;
    if(var_tot_x != 0 && var_tot_y != 0)            correl_tot = covar_tot / sqrt(var_tot_x * var_tot_y);
    if(var_sam_x != 0 && var_sam_y != 0)            correl_sam = covar_sam / sqrt(var_sam_x * var_sam_y);
    (*v_stats)[c_STAT_2D_CORRELATION_TOTAL]         = correl_tot;
    (*v_stats)[c_STAT_2D_CORRELATION_SAMPLE]        = correl_sam;
    (*v_stats)[c_STAT_2D_R_SQUARE_TOTAL]            = correl_tot * correl_tot;
    (*v_stats)[c_STAT_2D_R_SQUARE_SAMPLE]           = correl_sam * correl_sam;

    //linear fit
    double lin_fit_a = 0;
    if(var_sam_x != 0)                              lin_fit_a = covar_sam / var_sam_x;
    double lin_fit_b                                = mean_y - (lin_fit_a * mean_x);
    (*v_stats)[c_STAT_2D_LINEAR_FIT_SLOPE]          = lin_fit_a;
    (*v_stats)[c_STAT_2D_LINEAR_FIT_Y_AXIS_SECTION] = lin_fit_b;

    return ER_okay;
}

int D_Stat::Calc_Stats_Circ_Rad(vector<double> *v_stats, vector<double> v_data_a)
{
    //init out
    v_stats->clear();
    v_stats->resize(c_STAT_CIRC_NUMBER_OF, 0);

    //number of elements
    size_t n = v_data_a.size();
    (*v_stats)[c_STAT_CIRC_COUNT] = n;
    if(n == 0)
        return ER_empty;

    //sums of sines/cosines
    double sum_c = 0;
    double sum_s = 0;
    for(size_t i = 0; i < n; i++)
    {
        sum_c += cos(v_data_a[i]);
        sum_s += sin(v_data_a[i]);
    }

    //means
    double mean_c = sum_c / n;
    double mean_s = sum_s / n;
    double mean_a = atan2(mean_s, mean_c);
    (*v_stats)[c_STAT_CIRC_MEAN_ANG] = mean_a;
    (*v_stats)[c_STAT_CIRC_MEAN_SIN] = mean_s;
    (*v_stats)[c_STAT_CIRC_MEAN_COS] = mean_c;

    //Balances
    double mean_unb = sqrt(mean_c * mean_c + mean_s * mean_s);
    double mean_bal = 1 - mean_unb;
    double mean_bal_pi = mean_bal * PI;
    double mean_bal_pi_1sig = mean_bal_pi * SIGMA1_PROB;
    double mean_bal_pi_2sig = mean_bal_pi * SIGMA2_PROB;
    double mean_bal_pi_3sig = mean_bal_pi * SIGMA3_PROB;
    double mean_bal_pi_4sig = mean_bal_pi * SIGMA4_PROB;
    double mean_bal_pi_5sig = mean_bal_pi * SIGMA5_PROB;
    double mean_bal_pi_6sig = mean_bal_pi * SIGMA6_PROB;
    double mean_bal_pi_7sig = mean_bal_pi * SIGMA7_PROB;
    (*v_stats)[c_STAT_CIRC_UNBALANCE] = mean_unb;
    (*v_stats)[c_STAT_CIRC_BALANCE] = mean_bal;
    (*v_stats)[c_STAT_CIRC_BALANCE_PI_OR_180] = mean_bal_pi;
    (*v_stats)[c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA] = mean_bal_pi_1sig;
    (*v_stats)[c_STAT_CIRC_BALANCE_PI_OR_180_2SIGMA] = mean_bal_pi_2sig;
    (*v_stats)[c_STAT_CIRC_BALANCE_PI_OR_180_3SIGMA] = mean_bal_pi_3sig;
    (*v_stats)[c_STAT_CIRC_BALANCE_PI_OR_180_4SIGMA] = mean_bal_pi_4sig;
    (*v_stats)[c_STAT_CIRC_BALANCE_PI_OR_180_5SIGMA] = mean_bal_pi_5sig;
    (*v_stats)[c_STAT_CIRC_BALANCE_PI_OR_180_6SIGMA] = mean_bal_pi_6sig;
    (*v_stats)[c_STAT_CIRC_BALANCE_PI_OR_180_7SIGMA] = mean_bal_pi_7sig;

    //sums momentums
    double sum_mean_diff_pow2 = 0;
    double sum_mean_diff_pow3 = 0;
    double sum_mean_diff_pow4 = 0;
    for(size_t i = 0; i < n; i++)
    {
        //circular distance
        double dist = DistCircular_Rad(v_data_a[i], mean_a);

        //powers of distance
        double dist_pow2 = dist * dist;
        double dist_pow3 = dist * dist_pow2;
        double dist_pow4 = dist * dist_pow3;

        //cumulate
        sum_mean_diff_pow2 += dist_pow2;
        sum_mean_diff_pow3 += dist_pow3;
        sum_mean_diff_pow4 += dist_pow4;
    }

    //variance
    double variance_tot = sum_mean_diff_pow2 / n;
    double variance_sam = variance_tot;
    if(n > 1) variance_sam = sum_mean_diff_pow2 / (n - 1);    //only do this correct formula if no zero division occurs
    (*v_stats)[c_STAT_CIRC_VARIANCE_TOTAL] = variance_tot;
    (*v_stats)[c_STAT_CIRC_VARIANCE_SAMPLE] = variance_sam;

    //standard deviation
    double stan_dev_tot = sqrt(variance_tot);
    double stan_dev_sam = sqrt(variance_sam);
    (*v_stats)[c_STAT_CIRC_STAN_DEV_TOTAL] = stan_dev_tot;
    (*v_stats)[c_STAT_CIRC_STAN_DEV_SAMPLE] = stan_dev_sam;

    //skewness
    double skewness_tot = sum_mean_diff_pow3 / (n * sqrt(variance_tot * variance_tot * variance_tot));
    double skewness_sam = sum_mean_diff_pow3 / (n * sqrt(variance_sam * variance_sam * variance_sam));
    (*v_stats)[c_STAT_CIRC_SKEWNESS_TOTAL] = skewness_tot;
    (*v_stats)[c_STAT_CIRC_SKEWNESS_SAMPLE] = skewness_sam;

    //kurtosis
    double kurtosis_tot = sum_mean_diff_pow4 / (n * variance_tot * variance_tot) - 3;
    double kurtosis_sam = sum_mean_diff_pow4 / (n * variance_sam * variance_sam) - 3;
    (*v_stats)[c_STAT_CIRC_KURTOSIS_TOTAL] = kurtosis_tot;
    (*v_stats)[c_STAT_CIRC_KURTOSIS_SAMPLE] = kurtosis_sam;

    //standard error to the mean
    double sem_tot = 0;
    if(n > 0)   sem_tot = stan_dev_tot / sqrt(n);
    double sem_sam = 0;
    if(n > 0)   sem_sam = stan_dev_sam / sqrt(n);
    (*v_stats)[c_STAT_CIRC_SEM_TOTAL] = sem_tot;
    (*v_stats)[c_STAT_CIRC_SEM_SAMPLE] = sem_sam;

    //Reference constants
    (*v_stats)[c_STAT_CIRC_CONST_0] = 0;
    (*v_stats)[c_STAT_CIRC_CONST_1] = 1;
    (*v_stats)[c_STAT_CIRC_CONST_PI] = PI;

    return ER_okay;
}

int D_Stat::Calc_Stats_Circ_Grad(vector<double> *v_stats, vector<double> v_data_a)
{
    //init out
    v_stats->clear();
    v_stats->resize(c_STAT_CIRC_NUMBER_OF, 0);

    //number of elements
    size_t n = v_data_a.size();
    (*v_stats)[c_STAT_CIRC_COUNT] = n;
    if(n == 0)
        return ER_empty;

    //sums of sines/cosines
    double sum_c = 0;
    double sum_s = 0;
    for(size_t i = 0; i < n; i++)
    {
        sum_c += cos(v_data_a[i] * Grad2Rad);
        sum_s += sin(v_data_a[i] * Grad2Rad);
    }

    //means
    double mean_c = sum_c / n;
    double mean_s = sum_s / n;
    double mean_a = atan2(mean_s, mean_c) * Rad2Grad;
    (*v_stats)[c_STAT_CIRC_MEAN_ANG] = mean_a;
    (*v_stats)[c_STAT_CIRC_MEAN_SIN] = mean_s;
    (*v_stats)[c_STAT_CIRC_MEAN_COS] = mean_c;

    double mean_unb = sqrt(mean_c * mean_c + mean_s * mean_s);
    double mean_bal = 1 - mean_unb;
    double mean_bal_pi = mean_bal * 180;
    double mean_bal_pi_1sig = mean_bal_pi * SIGMA1_PROB;
    double mean_bal_pi_2sig = mean_bal_pi * SIGMA2_PROB;
    double mean_bal_pi_3sig = mean_bal_pi * SIGMA3_PROB;
    double mean_bal_pi_4sig = mean_bal_pi * SIGMA4_PROB;
    double mean_bal_pi_5sig = mean_bal_pi * SIGMA5_PROB;
    double mean_bal_pi_6sig = mean_bal_pi * SIGMA6_PROB;
    double mean_bal_pi_7sig = mean_bal_pi * SIGMA7_PROB;
    (*v_stats)[c_STAT_CIRC_UNBALANCE] = mean_unb;
    (*v_stats)[c_STAT_CIRC_BALANCE] = mean_bal;
    (*v_stats)[c_STAT_CIRC_BALANCE_PI_OR_180] = mean_bal_pi;
    (*v_stats)[c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA] = mean_bal_pi_1sig;
    (*v_stats)[c_STAT_CIRC_BALANCE_PI_OR_180_2SIGMA] = mean_bal_pi_2sig;
    (*v_stats)[c_STAT_CIRC_BALANCE_PI_OR_180_3SIGMA] = mean_bal_pi_3sig;
    (*v_stats)[c_STAT_CIRC_BALANCE_PI_OR_180_4SIGMA] = mean_bal_pi_4sig;
    (*v_stats)[c_STAT_CIRC_BALANCE_PI_OR_180_5SIGMA] = mean_bal_pi_5sig;
    (*v_stats)[c_STAT_CIRC_BALANCE_PI_OR_180_6SIGMA] = mean_bal_pi_6sig;
    (*v_stats)[c_STAT_CIRC_BALANCE_PI_OR_180_7SIGMA] = mean_bal_pi_7sig;

    //sums momentums
    double sum_mean_diff_pow2 = 0;
    double sum_mean_diff_pow3 = 0;
    double sum_mean_diff_pow4 = 0;
    for(size_t i = 0; i < n; i++)
    {
        //circular distance
        double dist = DistCircular_Grad(v_data_a[i], mean_a);

        //powers of distance
        double dist_pow2 = dist * dist;
        double dist_pow3 = dist * dist_pow2;
        double dist_pow4 = dist * dist_pow3;

        //cumulate
        sum_mean_diff_pow2 += dist_pow2;
        sum_mean_diff_pow3 += dist_pow3;
        sum_mean_diff_pow4 += dist_pow4;
    }

    //variance
    double variance_tot = sum_mean_diff_pow2 / n;
    double variance_sam = variance_tot;
    if(n > 1) variance_sam = sum_mean_diff_pow2 / (n - 1);    //only do this correct formula if no zero division occurs
    (*v_stats)[c_STAT_CIRC_VARIANCE_TOTAL] = variance_tot;
    (*v_stats)[c_STAT_CIRC_VARIANCE_SAMPLE] = variance_sam;

    //standard deviation
    double stan_dev_tot = sqrt(variance_tot);
    double stan_dev_sam = sqrt(variance_sam);
    (*v_stats)[c_STAT_CIRC_STAN_DEV_TOTAL] = stan_dev_tot;
    (*v_stats)[c_STAT_CIRC_STAN_DEV_SAMPLE] = stan_dev_sam;

    //skewness
    double skewness_tot = sum_mean_diff_pow3 / (n * sqrt(variance_tot * variance_tot * variance_tot));
    double skewness_sam = sum_mean_diff_pow3 / (n * sqrt(variance_sam * variance_sam * variance_sam));
    (*v_stats)[c_STAT_CIRC_SKEWNESS_TOTAL] = skewness_tot;
    (*v_stats)[c_STAT_CIRC_SKEWNESS_SAMPLE] = skewness_sam;

    //kurtosis
    double kurtosis_tot = sum_mean_diff_pow4 / (n * variance_tot * variance_tot) - 3;
    double kurtosis_sam = sum_mean_diff_pow4 / (n * variance_sam * variance_sam) - 3;
    (*v_stats)[c_STAT_CIRC_KURTOSIS_TOTAL] = kurtosis_tot;
    (*v_stats)[c_STAT_CIRC_KURTOSIS_SAMPLE] = kurtosis_sam;

    //standard error to the mean
    double sem_tot = 0;
    if(n > 0)   sem_tot = stan_dev_tot / sqrt(n);
    double sem_sam = 0;
    if(n > 0)   sem_sam = stan_dev_sam / sqrt(n);
    (*v_stats)[c_STAT_CIRC_SEM_TOTAL] = sem_tot;
    (*v_stats)[c_STAT_CIRC_SEM_SAMPLE] = sem_sam;

    //Reference constants
    (*v_stats)[c_STAT_CIRC_CONST_0] = 0;
    (*v_stats)[c_STAT_CIRC_CONST_1] = 1;
    (*v_stats)[c_STAT_CIRC_CONST_PI] = 180;

    return ER_okay;
}

function<double (vector<double>)> D_Stat::Function_SingleStat(int stat)
{
    switch (stat) {

    case c_STAT_COUNT:
        return [](vector<double> v_x)
        {
            return static_cast<double>(v_x.size());
        };

    case c_STAT_SUM:
        return [](vector<double> v_x)
        {
            double sum = 0;
            for(size_t i = 0; i < v_x.size(); i++)
                sum += v_x[i];
            return sum;
        };

    case c_STAT_SUM_OF_ABS:
        return [](vector<double> v_x)
        {
            double sum = 0;
            for(size_t i = 0; i < v_x.size(); i++)
                sum += abs(v_x[i]);
            return sum;
        };

    case c_STAT_SUM_OF_SQUARES:
        return [](vector<double> v_x)
        {
            double sum = 0;
            for(size_t i = 0; i < v_x.size(); i++)
                sum += v_x[i] * v_x[i];
            return sum;
        };

    case c_STAT_MEAN_ARITMETIC:
        return [](vector<double> v_x)
        {
            double sum = 0;
            for(size_t i = 0; i < v_x.size(); i++)
                sum += v_x[i];
            double mean = sum / v_x.size();
            return mean;
        };

    case c_STAT_MEAN_ARITMETIC_OF_ABS:
        return [](vector<double> v_x)
        {
            double sum = 0;
            for(size_t i = 0; i < v_x.size(); i++)
                sum += abs(v_x[i]);
            double mean = sum / v_x.size();
            return mean;
        };

    case c_STAT_MEAN_ARITMETIC_OF_NON_ZERO:
        return [](vector<double> v_x)
        {
            int n = 0;
            double sum = 0;

            for(size_t i = 0; i < v_x.size(); i++)
                if(v_x[i] != 0)
                {
                    n++;
                    sum += v_x[i];
                }

            double mean = n > 0 ? sum / n : 0;
            return mean;
        };

    case c_STAT_VARIANCE_TOTAL:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 0)
                var /= n;

            return var;
        };

    case c_STAT_VARIANCE_SAMPLE:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 1)
                var /= n - 1;

            return var;
        };

    case c_STAT_SKEWNESS_TOTAL:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 0)
                var /= n;

            //skewness
            double skew = 0;
            if(var != 0 && n != 0)
            {
                for(size_t i = 0; i < n; i++)
                    skew += (v_x[i] - mean) * (v_x[i] - mean) * (v_x[i] - mean);
                skew /= sqrt(var * var * var) * n;
            }

            return skew;
        };

    case c_STAT_SKEWNESS_SAMPLE:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 1)
                var /= n - 1;

            //skewness
            double skew = 0;
            if(var != 0 && n != 0)
            {
                for(size_t i = 0; i < n; i++)
                    skew += (v_x[i] - mean) * (v_x[i] - mean) * (v_x[i] - mean);
                skew /= sqrt(var * var * var) * n;
            }

            return skew;
        };

    case c_STAT_KURTOSIS_TOTAL:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 0)
                var /= n;

            //kurtosis
            double kurt = 0;
            if(var != 0 && n != 0)
            {
                for(size_t i = 0; i < n; i++)
                    kurt += (v_x[i] - mean) * (v_x[i] - mean) * (v_x[i] - mean) * (v_x[i] - mean);
                kurt /= var * var * n;
                kurt -= 3;
            }

            return kurt;
        };

    case c_STAT_KURTOSIS_SAMPLE:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 1)
                var /= n - 1;

            //kurtosis
            double kurt = 0;
            if(var != 0 && n != 0)
            {
                for(size_t i = 0; i < n; i++)
                    kurt += (v_x[i] - mean) * (v_x[i] - mean) * (v_x[i] - mean) * (v_x[i] - mean);
                kurt /= var * var * n;
                kurt -= 3;
            }

            return kurt;
        };

    case c_STAT_STAN_DEV_TOTAL:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 0)
                var /= n;

            //stan dev
            double sd = sqrt(var);

            return sd;
        };

    case c_STAT_STAN_DEV_SAMPLE:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 1)
                var /= n - 1;

            //stan dev
            double sd = sqrt(var);

            return sd;
        };

    case c_STAT_VAR_COEF_TOTAL:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 1)
                var /= n;

            //stan dev
            double sd = sqrt(var);

            //var coeff
            double cv = sd / mean;

            return cv;
        };

    case c_STAT_VAR_COEF_SAMPLE:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 1)
                var /= n - 1;

            //stan dev
            double sd = sqrt(var);

            //var coeff
            double cv = sd / mean;

            return cv;
        };


    case c_STAT_MINIMUM:
        return [](vector<double> v_x)
        {
            double n = v_x.size();

            double q = INFINITY;
            for(size_t i = 0; i < n; i++)
                if(v_x[i] < q)
                    q = v_x[i];

            return q;
        };

    case c_STAT_QUANTIL_05:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.05 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUANTIL_10:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.10 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUANTIL_15:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.15 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUANTIL_20:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.20 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUARTIL_LOW:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.25 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUANTIL_30:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.30 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUANTIL_35:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.35 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUANTIL_40:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.40 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUANTIL_45:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.45 * (n - 1))];
            }

            return q;
        };

    case c_STAT_MEDIAN:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.50 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUANTIL_55:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.55 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUANTIL_60:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.60 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUANTIL_65:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.65 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUANTIL_70:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.70 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUARTIL_UP:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.75 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUANTIL_80:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.80 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUANTIL_85:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.85 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUANTIL_90:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.90 * (n - 1))];
            }

            return q;
        };

    case c_STAT_QUANTIL_95:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.95 * (n - 1))];
            }

            return q;
        };

    case c_STAT_MAXIMUM:
        return [](vector<double> v_x)
        {
            double n = v_x.size();

            double q = -INFINITY;
            for(size_t i = 0; i < n; i++)
                if(v_x[i] > q)
                    q = v_x[i];

            return q;
        };


    case c_STAT_ABS_DEV_MED:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double m = 0;
            double adm = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                m =  v_x[static_cast<int>(0.50 * (n - 1))];

                for(size_t i = 0; i < n; i++)
                    adm += abs(m - v_x[i]);
                adm /= n;
            }

            return adm;
        };

    case c_STAT_DIST_10_0_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.55 * (n - 1))] - v_x[static_cast<int>(0.45 * (n - 1))];
            }

            return d;
        };

    case c_STAT_DIST_20_0_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.60 * (n - 1))] - v_x[static_cast<int>(0.40 * (n - 1))];
            }

            return d;
        };

    case c_STAT_DIST_30_0_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.65 * (n - 1))] - v_x[static_cast<int>(0.35 * (n - 1))];
            }

            return d;
        };

    case c_STAT_DIST_40_0_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.70 * (n - 1))] - v_x[static_cast<int>(0.30 * (n - 1))];
            }

            return d;
        };

    case c_STAT_DIST_QUARTIL:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.75 * (n - 1))] - v_x[static_cast<int>(0.25 * (n - 1))];
            }

            return d;
        };

    case c_STAT_DIST_60_0_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.80 * (n - 1))] - v_x[static_cast<int>(0.20 * (n - 1))];
            }

            return d;
        };

    case c_STAT_DIST_70_0_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.85 * (n - 1))] - v_x[static_cast<int>(0.15 * (n - 1))];
            }

            return d;
        };

    case c_STAT_DIST_80_0_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.90 * (n - 1))] - v_x[static_cast<int>(0.10 * (n - 1))];
            }

            return d;
        };

    case c_STAT_DIST_90_0_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.95 * (n - 1))] - v_x[static_cast<int>(0.05 * (n - 1))];
            }

            return d;
        };

    case c_STAT_SPAN:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(1.00 * (n - 1))] - v_x[static_cast<int>(0.00 * (n - 1))];
            }

            return d;
        };

    case c_STAT_DIST_68_3_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.8415 * (n - 1))] - v_x[static_cast<int>(0.1585 * (n - 1))];
            }

            return d;
        };

    case c_STAT_DIST_95_4_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.9770 * (n - 1))] - v_x[static_cast<int>(0.0230 * (n - 1))];
            }

            return d;
        };

    case c_STAT_DIST_99_7_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.9985 * (n - 1))] - v_x[static_cast<int>(0.0015 * (n - 1))];
            }

            return d;
        };

    case c_STAT_SEM_ABS_TOTAL:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 0)
                var /= n;

            //stan dev
            double sd = sqrt(var);

            //standard error to the mean
            double sem = 0;
            if(n > 0)
                sem = sd / sqrt(n);

            return sem;
        };

    case c_STAT_SEM_ABS_SAMPLE:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 1)
                var /= n - 1;

            //stan dev
            double sd = sqrt(var);

            //standard error to the mean
            double sem = 0;
            if(n > 0)
                sem = sd / sqrt(n);

            return sem;
        };

    case c_STAT_SEM_REL_TOTAL:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 0)
                var /= n;

            //stan dev
            double sd = sqrt(var);

            //var coeff
            double cv = sd / mean;

            //standard error to the mean
            double sem = 0;
            if(n > 0)
                sem = cv / sqrt(n);

            return sem;
        };

    case c_STAT_SEM_REL_SAMPLE:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 1)
                var /= n - 1;

            //stan dev
            double sd = sqrt(var);

            //var coeff
            double cv = sd / mean;

            //standard error to the mean
            double sem = 0;
            if(n > 0)
                sem = cv / sqrt(n);

            return sem;
        };

    case c_STAT_CONST_0:
        return [](vector<double> v_x)
        {
            return 0;
        };

    case c_STAT_CONST_1:
        return [](vector<double> v_x)
        {
            return 1;
        };

    default:
        return [](vector<double> v_x)
        {
            v_x;
            return NAN;
        };
    }
}

function<uchar (vector<double>)> D_Stat::Function_SingleStat_8bit(int stat)
{
    switch (stat) {

    case c_STAT_COUNT:
        return [](vector<double> v_x)
        {
            return static_cast<uchar>(v_x.size());
        };

    case c_STAT_SUM:
        return [](vector<double> v_x)
        {
            unsigned int sum = 0;
            for(size_t i = 0; i < v_x.size(); i++)
                sum += v_x[i];
            return static_cast<uchar>(sum);
        };

    case c_STAT_SUM_OF_SQUARES:
        return [](vector<double> v_x)
        {
            unsigned int sum = 0;
            for(size_t i = 0; i < v_x.size(); i++)
                sum += v_x[i] * v_x[i];
            return static_cast<uchar>(sum);
        };

    case c_STAT_MEAN_ARITMETIC:
        return [](vector<double> v_x)
        {
            double sum = 0;
            for(size_t i = 0; i < v_x.size(); i++)
                sum += v_x[i];
            double mean = sum / v_x.size();
            return static_cast<uchar>(mean);
        };

    case c_STAT_VARIANCE_TOTAL:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 0)
                var /= n;

            return static_cast<uchar>(var);
        };

    case c_STAT_VARIANCE_SAMPLE:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 1)
                var /= n - 1;

            return static_cast<uchar>(var);
        };

    case c_STAT_SKEWNESS_TOTAL:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 0)
                var /= n;

            //skewness
            double skew = 0;
            if(var != 0 && n != 0)
            {
                for(size_t i = 0; i < n; i++)
                    skew += (v_x[i] - mean) * (v_x[i] - mean) * (v_x[i] - mean);
                skew /= sqrt(var * var * var) * n;
            }

            return static_cast<uchar>(skew);
        };

    case c_STAT_SKEWNESS_SAMPLE:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 1)
                var /= n - 1;

            //skewness
            double skew = 0;
            if(var != 0 && n != 0)
            {
                for(size_t i = 0; i < n; i++)
                    skew += (v_x[i] - mean) * (v_x[i] - mean) * (v_x[i] - mean);
                skew /= sqrt(var * var * var) * n;
            }

            return static_cast<uchar>(skew);
        };

    case c_STAT_KURTOSIS_TOTAL:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 0)
                var /= n;

            //kurtosis
            double kurt = 0;
            if(var != 0 && n != 0)
            {
                for(size_t i = 0; i < n; i++)
                    kurt += (v_x[i] - mean) * (v_x[i] - mean) * (v_x[i] - mean) * (v_x[i] - mean);
                kurt /= var * var * n;
                kurt -= 3;
            }

            return static_cast<uchar>(kurt);
        };

    case c_STAT_KURTOSIS_SAMPLE:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 1)
                var /= n - 1;

            //kurtosis
            double kurt = 0;
            if(var != 0 && n != 0)
            {
                for(size_t i = 0; i < n; i++)
                    kurt += (v_x[i] - mean) * (v_x[i] - mean) * (v_x[i] - mean) * (v_x[i] - mean);
                kurt /= var * var * n;
                kurt -= 3;
            }

            return static_cast<uchar>(kurt);
        };

    case c_STAT_STAN_DEV_TOTAL:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 0)
                var /= n;

            //stan dev
            double sd = sqrt(var);

            return static_cast<uchar>(sd);
        };

    case c_STAT_STAN_DEV_SAMPLE:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 1)
                var /= n - 1;

            //stan dev
            double sd = sqrt(var);

            return static_cast<uchar>(sd);
        };

    case c_STAT_VAR_COEF_TOTAL:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 1)
                var /= n;

            //stan dev
            double sd = sqrt(var);

            //var coeff
            double cv = sd / mean;

            return static_cast<uchar>(cv);
        };

    case c_STAT_VAR_COEF_SAMPLE:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 1)
                var /= n - 1;

            //stan dev
            double sd = sqrt(var);

            //var coeff
            double cv = sd / mean;

            return static_cast<uchar>(cv);
        };



    case c_STAT_MINIMUM:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.00 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUANTIL_05:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.05 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUANTIL_10:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.10 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUANTIL_15:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.15 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUANTIL_20:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.20 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUARTIL_LOW:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.25 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUANTIL_30:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.30 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUANTIL_35:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.35 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUANTIL_40:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.40 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUANTIL_45:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.45 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_MEDIAN:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.50 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUANTIL_55:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.55 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUANTIL_60:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.60 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUANTIL_65:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.65 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUANTIL_70:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.70 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUARTIL_UP:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.75 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUANTIL_80:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.80 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUANTIL_85:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.85 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUANTIL_90:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.90 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_QUANTIL_95:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(0.95 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };

    case c_STAT_MAXIMUM:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double q = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                q =  v_x[static_cast<int>(1.00 * (n - 1))];
            }

            return static_cast<uchar>(q);
        };


    case c_STAT_ABS_DEV_MED:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double m = 0;
            double adm = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                m =  v_x[static_cast<int>(0.50 * (n - 1))];

                for(size_t i = 0; i < n; i++)
                    adm += abs(m - v_x[i]);
                adm /= n;
            }

            return static_cast<uchar>(adm);
        };

    case c_STAT_DIST_10_0_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.55 * (n - 1))] - v_x[static_cast<int>(0.45 * (n - 1))];
            }

            return static_cast<uchar>(d);
        };

    case c_STAT_DIST_20_0_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.60 * (n - 1))] - v_x[static_cast<int>(0.40 * (n - 1))];
            }

            return static_cast<uchar>(d);
        };

    case c_STAT_DIST_30_0_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.65 * (n - 1))] - v_x[static_cast<int>(0.35 * (n - 1))];
            }

            return static_cast<uchar>(d);
        };

    case c_STAT_DIST_40_0_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.70 * (n - 1))] - v_x[static_cast<int>(0.30 * (n - 1))];
            }

            return static_cast<uchar>(d);
        };

    case c_STAT_DIST_QUARTIL:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.75 * (n - 1))] - v_x[static_cast<int>(0.25 * (n - 1))];
            }

            return static_cast<uchar>(d);
        };

    case c_STAT_DIST_60_0_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.80 * (n - 1))] - v_x[static_cast<int>(0.20 * (n - 1))];
            }

            return static_cast<uchar>(d);
        };

    case c_STAT_DIST_70_0_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.85 * (n - 1))] - v_x[static_cast<int>(0.15 * (n - 1))];
            }

            return static_cast<uchar>(d);
        };

    case c_STAT_DIST_80_0_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.90 * (n - 1))] - v_x[static_cast<int>(0.10 * (n - 1))];
            }

            return static_cast<uchar>(d);
        };

    case c_STAT_DIST_90_0_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.95 * (n - 1))] - v_x[static_cast<int>(0.05 * (n - 1))];
            }

            return static_cast<uchar>(d);
        };

    case c_STAT_SPAN:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(1.00 * (n - 1))] - v_x[static_cast<int>(0.00 * (n - 1))];
            }

            return static_cast<uchar>(d);
        };

    case c_STAT_DIST_68_3_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.8415 * (n - 1))] - v_x[static_cast<int>(0.1585 * (n - 1))];
            }

            return static_cast<uchar>(d);
        };

    case c_STAT_DIST_95_4_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.9770 * (n - 1))] - v_x[static_cast<int>(0.0230 * (n - 1))];
            }

            return static_cast<uchar>(d);
        };

    case c_STAT_DIST_99_7_PRZ:
        return [](vector<double> v_x)
        {
            double n = v_x.size();
            double d = 0;

            if(n != 0)
            {
                sort(v_x.begin(), v_x.end());
                d =  v_x[static_cast<int>(0.9985 * (n - 1))] - v_x[static_cast<int>(0.0015 * (n - 1))];
            }

            return static_cast<uchar>(d);
        };

    case c_STAT_SEM_ABS_TOTAL:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 0)
                var /= n;

            //stan dev
            double sd = sqrt(var);

            //standard error to the mean
            double sem = 0;
            if(n > 0)
                sem = sd / sqrt(n);

            return static_cast<uchar>(sem);
        };

    case c_STAT_SEM_ABS_SAMPLE:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 1)
                var /= n - 1;

            //stan dev
            double sd = sqrt(var);

            //standard error to the mean
            double sem = 0;
            if(n > 0)
                sem = sd / sqrt(n);

            return static_cast<uchar>(sem);
        };

    case c_STAT_SEM_REL_TOTAL:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 0)
                var /= n;

            //stan dev
            double sd = sqrt(var);

            //var coeff
            double cv = sd / mean;

            //standard error to the mean
            double sem = 0;
            if(n > 0)
                sem = cv / sqrt(n);

            return static_cast<uchar>(sem);
        };

    case c_STAT_SEM_REL_SAMPLE:
        return [](vector<double> v_x)
        {
            //size
            double n = v_x.size();

            //sum
            double sum = 0;
            for(size_t i = 0; i < n; i++)
                sum += v_x[i];

            //mean
            double mean = sum / n;

            //variance
            double var = 0;
            for(size_t i = 0; i < n; i++)
                var += (v_x[i] - mean) * (v_x[i] - mean);
            if(n > 1)
                var /= n - 1;

            //stan dev
            double sd = sqrt(var);

            //var coeff
            double cv = sd / mean;

            //standard error to the mean
            double sem = 0;
            if(n > 0)
                sem = cv / sqrt(n);

            return static_cast<uchar>(sem);
        };

    case c_STAT_CONST_0:
        return [](vector<double> v_x)
        {
            return 0;
        };

    case c_STAT_CONST_1:
        return [](vector<double> v_x)
        {
            return 1;
        };

    default:
        return [](vector<double> v_x)
        {
            v_x;
            return static_cast<uchar>(NAN);
        };
    }
}

function<double (vector<double>)> D_Stat::Function_SingleStat_Circ_Rad(int stat)
{
    switch (stat) {

    case c_STAT_CIRC_COUNT:
        return [](vector<double> v_x)
        {
            return static_cast<double>(v_x.size());
        };

    case c_STAT_CIRC_MEAN_SIN:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
                sum_s += sin(v_x[i]);

            //mean sin
            return sum_s / n;
        };

    case c_STAT_CIRC_MEAN_COS:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines
            double sum_c = 0;
            for(size_t i = 0; i < n; i++)
                sum_c += cos(v_x[i]);

            //mean sin
            return sum_c / n;
        };

    case c_STAT_CIRC_MEAN_ANG:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;
            return atan2(mean_s, mean_c);
        };

    case c_STAT_CIRC_UNBALANCE:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;

            //unbalance
            return sqrt(mean_c * mean_c + mean_s * mean_s);
        };

    case c_STAT_CIRC_BALANCE:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;

            //balance
            return 1.0 - sqrt(mean_c * mean_c + mean_s * mean_s);
        };

    case c_STAT_CIRC_BALANCE_PI_OR_180:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;

            //balance
            double unbalance = sqrt(mean_c * mean_c + mean_s * mean_s);
            double balance = 1.0 - unbalance;

            return balance * PI;
        };

    case c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;

            //balance
            double unbalance = sqrt(mean_c * mean_c + mean_s * mean_s);
            double balance = 1.0 - unbalance;
            double balance_pi = balance * PI;

            return balance_pi * SIGMA1_PROB;
        };

    case c_STAT_CIRC_BALANCE_PI_OR_180_2SIGMA:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;

            //balance
            double unbalance = sqrt(mean_c * mean_c + mean_s * mean_s);
            double balance = 1.0 - unbalance;
            double balance_pi = balance * PI;

            return balance_pi * SIGMA2_PROB;
        };

    case c_STAT_CIRC_BALANCE_PI_OR_180_3SIGMA:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;

            //balance
            double unbalance = sqrt(mean_c * mean_c + mean_s * mean_s);
            double balance = 1.0 - unbalance;
            double balance_pi = balance * PI;

            return balance_pi * SIGMA3_PROB;
        };

    case c_STAT_CIRC_BALANCE_PI_OR_180_4SIGMA:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;

            //balance
            double unbalance = sqrt(mean_c * mean_c + mean_s * mean_s);
            double balance = 1.0 - unbalance;
            double balance_pi = balance * PI;

            return balance_pi * SIGMA4_PROB;
        };

    case c_STAT_CIRC_BALANCE_PI_OR_180_5SIGMA:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;

            //balance
            double unbalance = sqrt(mean_c * mean_c + mean_s * mean_s);
            double balance = 1.0 - unbalance;
            double balance_pi = balance * PI;

            return balance_pi * SIGMA5_PROB;
        };

    case c_STAT_CIRC_BALANCE_PI_OR_180_6SIGMA:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;

            //balance
            double unbalance = sqrt(mean_c * mean_c + mean_s * mean_s);
            double balance = 1.0 - unbalance;
            double balance_pi = balance * PI;

            return balance_pi * SIGMA6_PROB;
        };

    case c_STAT_CIRC_BALANCE_PI_OR_180_7SIGMA:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;

            //balance
            double unbalance = sqrt(mean_c * mean_c + mean_s * mean_s);
            double balance = 1.0 - unbalance;
            double balance_pi = balance * PI;

            return balance_pi * SIGMA7_PROB;
        };

    case c_STAT_CIRC_VARIANCE_TOTAL:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;
            double mean_a = atan2(mean_s, mean_c);

            //sums momentums
            double sum_mean_diff_pow2 = 0;
            for(size_t i = 0; i < n; i++)
            {
                //circular distance
                double dist = DistCircular_Rad(v_x[i], mean_a);

                //powers of distance
                double dist_pow2 = dist * dist;

                //cumulate
                sum_mean_diff_pow2 += dist_pow2;
            }

            //variance
            double variance_tot = sum_mean_diff_pow2 / n;

            return variance_tot;
        };

    case c_STAT_CIRC_VARIANCE_SAMPLE:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;
            double mean_a = atan2(mean_s, mean_c);

            //sums momentums
            double sum_mean_diff_pow2 = 0;
            for(size_t i = 0; i < n; i++)
            {
                //circular distance
                double dist = DistCircular_Rad(v_x[i], mean_a);

                //powers of distance
                double dist_pow2 = dist * dist;

                //cumulate
                sum_mean_diff_pow2 += dist_pow2;
            }

            //variance
            double variance_tot = sum_mean_diff_pow2 / n;
            double variance_sam = variance_tot;
            if(n > 1) variance_sam = sum_mean_diff_pow2 / (n - 1);

            return variance_sam;
        };

    case c_STAT_CIRC_SKEWNESS_TOTAL:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;
            double mean_a = atan2(mean_s, mean_c);

            //sums momentums
            double sum_mean_diff_pow2 = 0;
            double sum_mean_diff_pow3 = 0;
            for(size_t i = 0; i < n; i++)
            {
                //circular distance
                double dist = DistCircular_Rad(v_x[i], mean_a);

                //powers of distance
                double dist_pow2 = dist * dist;
                double dist_pow3 = dist * dist_pow2;

                //cumulate
                sum_mean_diff_pow2 += dist_pow2;
                sum_mean_diff_pow3 += dist_pow3;
            }

            //variance
            double variance_tot = sum_mean_diff_pow2 / n;

            //skewness
            double skewness_tot = sum_mean_diff_pow3 / (n * sqrt(variance_tot * variance_tot * variance_tot));

            return skewness_tot;
        };

    case c_STAT_CIRC_SKEWNESS_SAMPLE:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;
            double mean_a = atan2(mean_s, mean_c);

            //sums momentums
            double sum_mean_diff_pow2 = 0;
            double sum_mean_diff_pow3 = 0;
            for(size_t i = 0; i < n; i++)
            {
                //circular distance
                double dist = DistCircular_Rad(v_x[i], mean_a);

                //powers of distance
                double dist_pow2 = dist * dist;
                double dist_pow3 = dist * dist_pow2;

                //cumulate
                sum_mean_diff_pow2 += dist_pow2;
                sum_mean_diff_pow3 += dist_pow3;
            }

            //variance
            double variance_tot = sum_mean_diff_pow2 / n;
            double variance_sam = variance_tot;
            if(n > 1) variance_sam = sum_mean_diff_pow2 / (n - 1);

            //skewness
            double skewness_sam = sum_mean_diff_pow3 / (n * sqrt(variance_sam * variance_sam * variance_sam));

            return skewness_sam;
        };

    case c_STAT_CIRC_KURTOSIS_TOTAL:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;
            double mean_a = atan2(mean_s, mean_c);

            //sums momentums
            double sum_mean_diff_pow2 = 0;
            double sum_mean_diff_pow3 = 0;
            double sum_mean_diff_pow4 = 0;
            for(size_t i = 0; i < n; i++)
            {
                //circular distance
                double dist = DistCircular_Rad(v_x[i], mean_a);

                //powers of distance
                double dist_pow2 = dist * dist;
                double dist_pow3 = dist * dist_pow2;
                double dist_pow4 = dist * dist_pow3;

                //cumulate
                sum_mean_diff_pow2 += dist_pow2;
                sum_mean_diff_pow3 += dist_pow3;
                sum_mean_diff_pow4 += dist_pow4;
            }

            //variance
            double variance_tot = sum_mean_diff_pow2 / n;

            //kurtosis
            return sum_mean_diff_pow4 / (n * variance_tot * variance_tot) - 3;
        };

    case c_STAT_CIRC_KURTOSIS_SAMPLE:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;
            double mean_a = atan2(mean_s, mean_c);

            //sums momentums
            double sum_mean_diff_pow2 = 0;
            double sum_mean_diff_pow3 = 0;
            double sum_mean_diff_pow4 = 0;
            for(size_t i = 0; i < n; i++)
            {
                //circular distance
                double dist = DistCircular_Rad(v_x[i], mean_a);

                //powers of distance
                double dist_pow2 = dist * dist;
                double dist_pow3 = dist * dist_pow2;
                double dist_pow4 = dist * dist_pow3;

                //cumulate
                sum_mean_diff_pow2 += dist_pow2;
                sum_mean_diff_pow3 += dist_pow3;
                sum_mean_diff_pow4 += dist_pow4;
            }

            //variance
            double variance_tot = sum_mean_diff_pow2 / n;
            double variance_sam = variance_tot;
            if(n > 1) variance_sam = sum_mean_diff_pow2 / (n - 1);

            //kurtosis
            return sum_mean_diff_pow4 / (n * variance_sam * variance_sam) - 3;
        };

    case c_STAT_CIRC_STAN_DEV_TOTAL:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;
            double mean_a = atan2(mean_s, mean_c);

            //sums momentums
            double sum_mean_diff_pow2 = 0;
            double sum_mean_diff_pow3 = 0;
            double sum_mean_diff_pow4 = 0;
            for(size_t i = 0; i < n; i++)
            {
                //circular distance
                double dist = DistCircular_Rad(v_x[i], mean_a);

                //powers of distance
                double dist_pow2 = dist * dist;
                double dist_pow3 = dist * dist_pow2;
                double dist_pow4 = dist * dist_pow3;

                //cumulate
                sum_mean_diff_pow2 += dist_pow2;
                sum_mean_diff_pow3 += dist_pow3;
                sum_mean_diff_pow4 += dist_pow4;
            }

            //variance
            double variance_tot = sum_mean_diff_pow2 / n;

            //std
            return sqrt(variance_tot);
        };

    case c_STAT_CIRC_STAN_DEV_SAMPLE:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;
            double mean_a = atan2(mean_s, mean_c);

            //sums momentums
            double sum_mean_diff_pow2 = 0;
            double sum_mean_diff_pow3 = 0;
            double sum_mean_diff_pow4 = 0;
            for(size_t i = 0; i < n; i++)
            {
                //circular distance
                double dist = DistCircular_Rad(v_x[i], mean_a);

                //powers of distance
                double dist_pow2 = dist * dist;
                double dist_pow3 = dist * dist_pow2;
                double dist_pow4 = dist * dist_pow3;

                //cumulate
                sum_mean_diff_pow2 += dist_pow2;
                sum_mean_diff_pow3 += dist_pow3;
                sum_mean_diff_pow4 += dist_pow4;
            }

            //variance
            double variance_tot = sum_mean_diff_pow2 / n;
            double variance_sam = variance_tot;
            if(n > 1) variance_sam = sum_mean_diff_pow2 / (n - 1);

            //std
            return sqrt(variance_sam);
        };

    case c_STAT_CIRC_SEM_TOTAL:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;
            double mean_a = atan2(mean_s, mean_c);

            //sums momentums
            double sum_mean_diff_pow2 = 0;
            double sum_mean_diff_pow3 = 0;
            double sum_mean_diff_pow4 = 0;
            for(size_t i = 0; i < n; i++)
            {
                //circular distance
                double dist = DistCircular_Rad(v_x[i], mean_a);

                //powers of distance
                double dist_pow2 = dist * dist;
                double dist_pow3 = dist * dist_pow2;
                double dist_pow4 = dist * dist_pow3;

                //cumulate
                sum_mean_diff_pow2 += dist_pow2;
                sum_mean_diff_pow3 += dist_pow3;
                sum_mean_diff_pow4 += dist_pow4;
            }

            //variance
            double variance_tot = sum_mean_diff_pow2 / n;

            //std
            double stan_dev_tot = sqrt(variance_tot);

            //standard error to the mean
            double sem_tot = 0;
            if(n > 0)   sem_tot = stan_dev_tot / sqrt(n);

            return sem_tot;
        };

    case c_STAT_CIRC_SEM_SAMPLE:
        return [](vector<double> v_x)
        {
            //count
            size_t n = v_x.size();

            //sums of sines/cosines
            double sum_c = 0;
            double sum_s = 0;
            for(size_t i = 0; i < n; i++)
            {
                sum_c += cos(v_x[i]);
                sum_s += sin(v_x[i]);
            }

            //means
            double mean_c = sum_c / n;
            double mean_s = sum_s / n;
            double mean_a = atan2(mean_s, mean_c);

            //sums momentums
            double sum_mean_diff_pow2 = 0;
            double sum_mean_diff_pow3 = 0;
            double sum_mean_diff_pow4 = 0;
            for(size_t i = 0; i < n; i++)
            {
                //circular distance
                double dist = DistCircular_Rad(v_x[i], mean_a);

                //powers of distance
                double dist_pow2 = dist * dist;
                double dist_pow3 = dist * dist_pow2;
                double dist_pow4 = dist * dist_pow3;

                //cumulate
                sum_mean_diff_pow2 += dist_pow2;
                sum_mean_diff_pow3 += dist_pow3;
                sum_mean_diff_pow4 += dist_pow4;
            }

            //variance
            double variance_tot = sum_mean_diff_pow2 / n;
            double variance_sam = variance_tot;
            if(n > 1) variance_sam = sum_mean_diff_pow2 / (n - 1);

            //std
            double stan_dev_sam = sqrt(variance_sam);

            //standard error to the mean
            double sem_sam = 0;
            if(n > 0)   sem_sam = stan_dev_sam / sqrt(n);

            return sem_sam;
        };

    case c_STAT_CIRC_CONST_0:
        return [](vector<double> v_x)
        {
            return 0;
        };

    case c_STAT_CIRC_CONST_1:
        return [](vector<double> v_x)
        {
            return 1;
        };

    case c_STAT_CIRC_CONST_PI:
        return [](vector<double> v_x)
        {
            return PI;
        };

    default:
        return [](vector<double> v_x)
        {
            v_x;
            return NAN;
        };
    }
}

double D_Stat::Mean(vector<double> v_data, double nan_value)
{
    size_t n = v_data.size();
    if(n <= 0)
        return nan_value;

    double sum = 0;

    for(size_t i = 0; i < n; i++)
        sum += v_data[i];

    return sum / n;
}

double D_Stat::MeanWeighted(vector<double> v_data, vector<double> v_weights, double nan_value)
{
    if(v_data.size() != v_weights.size())
        return nan_value;

    size_t n = v_data.size();
    if(n <= 0)
        return nan_value;

    double sum_vals = 0;
    double sum_weights = 0;

    for(size_t i = 0; i < n; i++)
    {
        sum_vals    += v_weights[i] * v_data[i];
        sum_weights += v_weights[i];
    }

    if(sum_weights == 0.0)
        return nan_value;
    else
        return sum_vals / sum_weights;
}

int D_Stat::Calc_Vector2Hist_1(vector<double> *v_hist, vector<double> *v_data, unsigned int class_count, double *min_x_ext, double *max_x_ext, double *max_y_ext, double *step_ext, bool accumulate, bool uniform)
{
    if(class_count < 2)
        class_count = 2;

    if(v_data->empty())
    {
        *min_x_ext = 0.0;
        *max_x_ext = 0.0;
        *max_y_ext = 0.0;
        *step_ext = 0.0;
        *v_hist = vector<double>(class_count, 0.0);
        return ER_empty;
    }

    //find min and max
    double min_x = (*v_data)[0];
    double max_x = (*v_data)[0];
    for(unsigned int elem = 0; elem < v_data->size(); elem++)
    {
        double val = (*v_data)[elem];

        if(val > max_x)
        {
            max_x = val;
            //qDebug() << "new max:" << max_x << "(at set" << set << "elem" << elem << ")";
        }

        if(val < min_x)
        {
            min_x = val;
            //qDebug() << "new min:" << min_x << "(at set" << set << "elem" << elem << ")";
        }
    }

    //range and step
    double range_x = max_x - min_x;
    double step_x = range_x / (class_count - 1);

    //calc hist
    v_hist->resize(class_count, 0.0);
    if(step_x > 0)
        for(unsigned int elem = 0; elem < v_data->size(); elem++)
        {
            double val = (*v_data)[elem];                   //y
            size_t pos = size_t((val - min_x) / step_x);    //x
            (*v_hist)[pos]++;
        }


    //accumulate
    if(accumulate)
        for(unsigned int elem = 1; elem < v_hist->size(); elem++)
            (*v_hist)[elem] += (*v_hist)[elem - 1];

    //uniform
    if(uniform)
        if(v_data->size() > 0)
            for(unsigned int elem = 0; elem < v_hist->size(); elem++)
                (*v_hist)[elem] /= double(v_data->size());

    //max y
    double max_y = 0;
    for(unsigned int elem = 0; elem < v_hist->size(); elem++)
        if(max_y < (*v_hist)[elem])
            max_y = (*v_hist)[elem];

    //export
    *max_y_ext = max_y;
    *min_x_ext = min_x;
    *max_x_ext = max_x;
    *step_ext = step_x;

    return ER_okay;
}

int D_Stat::Calc_Vector2Hist_2(vector<vector<double>> *vv_hist, vector<vector<double>> *vv_data, unsigned int class_count, double *min_x_ext, double *max_x_ext, double *max_y_ext, double *step_ext, bool accumulate, bool uniform)
{
    //find min and max
    double min_x = (*vv_data)[0][0];
    double max_x = (*vv_data)[0][0];
    for(unsigned int set = 0; set < vv_data->size(); set++)
        for(unsigned int elem = 0; elem < (*vv_data)[set].size(); elem++)
        {
            double val = (*vv_data)[set][elem];

            if(val > max_x)
            {
                max_x = val;
                //qDebug() << "new max:" << max_x << "(at set" << set << "elem" << elem << ")";
            }

            if(val < min_x)
            {
                min_x = val;
                //qDebug() << "new min:" << min_x << "(at set" << set << "elem" << elem << ")";
            }
        }

    //range and step
    double range_x = max_x - min_x;
    double step_x = range_x / (class_count - 1);

    //calc hist
    vv_hist->resize(vv_data->size());
    for(unsigned int set = 0; set < vv_data->size(); set++)
    {
        (*vv_hist)[set].resize(class_count, 0.0);
        for(unsigned int elem = 0; elem < (*vv_data)[set].size(); elem++)
        {
            double val = (*vv_data)[set][elem];     //y
            double pos = (val - min_x) / step_x;    //x
            (*vv_hist)[set][pos]++;
        }
    }

    //accumulate
    if(accumulate)
        for(unsigned int set = 0; set < vv_hist->size(); set++)
        {
            for(unsigned int elem = 1; elem < (*vv_hist)[set].size(); elem++)
                (*vv_hist)[set][elem] += (*vv_hist)[set][elem - 1];
            //qDebug() << "Accumulated last:" << (*vv_hist)[set][(*vv_hist)[set].size() - 1] << "- count:" << (*vv_data)[set].size();
        }

    //uniform
    if(uniform)
        for(unsigned int set = 0; set < vv_hist->size(); set++)
        {
            for(unsigned int elem = 0; elem < (*vv_hist)[set].size(); elem++)
                (*vv_hist)[set][elem] /= (double)((*vv_data)[set].size());
            //qDebug() << "uniformed last:" << (*vv_hist)[set][(*vv_hist)[set].size() - 1] << "- count:" << (*vv_data)[set].size();
        }

    //max y
    double max_y = 0;
    for(unsigned int set = 0; set < vv_hist->size(); set++)
        for(unsigned int elem = 0; elem < (*vv_hist)[set].size(); elem++)
            if(max_y < (*vv_hist)[set][elem])
                max_y = (*vv_hist)[set][elem];

    //export
    *max_y_ext = max_y;
    *min_x_ext = min_x;
    *max_x_ext = max_x;
    *step_ext = step_x;

    return ER_okay;
}

double D_Stat::AxeTrans(double in_val, int trans_index)
{
    switch (trans_index)
    {

    case c_AXE_TRANS_LIN:
        return in_val;

    case c_AXE_TRANS_LOG_2:
        if(in_val == 0)
            return -INFINITY;
        else if (in_val < 0)
            return NAN;
        else
            return log2(in_val);

    case c_AXE_TRANS_LOG_E:
        if(in_val == 0)
            return -INFINITY;
        else if (in_val < 0)
            return NAN;
        else
            return log(in_val);

    case c_AXE_TRANS_LOG_10:
        if(in_val == 0)
            return -INFINITY;
        else if (in_val < 0)
            return NAN;
        else
            return log10(in_val);

    case c_AXE_TRANS_1pX:
        if(in_val == 0)
            return INFINITY;
        else
            return 1.0 / (in_val);

    case c_AXE_TRANS_1pXX:
        if(in_val == 0)
            return INFINITY;
        else
            return 1.0 / (in_val * in_val);

    default:
        return in_val;
    }
}

int D_Stat::Calc_MinMax(double *min, double *max, vector<double> vData)
{
    size_t n = vData.size();
    if(n <= 0)
        return ER_empty;

    //init
    *min = INFINITY;
    *max = -INFINITY;

    //loop data
    for(size_t i = 0; i < n; i++)
    {
        double val = vData[i];

        if(val < *min)  *min = val;
        if(val > *max)  *max = val;
    }

    return ER_okay;
}

int D_Stat::Calc_MinMax(double *min, double *max, vector<double> *vData)
{
    size_t n = vData->size();
    if(n <= 0)
        return ER_empty;

    //init
    *min = INFINITY;
    *max = -INFINITY;

    //loop data
    for(size_t i = 0; i < n; i++)
    {
        double val = (*vData)[i];

        if(val < *min)  *min = val;
        if(val > *max)  *max = val;
    }

    return ER_okay;
}

int D_Stat::Calc_MinMax(vector<double> v_y_data, double *x_min_ext, double *x_max_ext, double *y_min_ext, double *y_max_ext, int x_trans, int y_trans)
{
    //define extrema (uninitalized)
    double x_init = NAN;
    double x_min;
    double x_max;
    double y_init = NAN;
    double y_min;
    double y_max;

    //carefully init x with first not stupid number
    for(size_t x = 0; x < v_y_data.size(); x++)
    {
        double x_val = AxeTrans(x, x_trans);

        if(!isnan(x_val))
            if(isfinite(x_val))
            {
                x_init = x_val;
                x = static_cast<int>(v_y_data.size()); //dirty way of break on init
            }
    }
    x_min = x_init;
    x_max = x_init;

    //carefully init y with first not stupid number
    for(size_t x = 0; x < v_y_data.size(); x++)
    {
        double y_val = AxeTrans(v_y_data[x], y_trans);

        if(!isnan(y_val))
            if(isfinite(y_val))
            {
                y_init = y_val;
                x = static_cast<int>(v_y_data.size()); //dirty way of break on init
            }
    }
    y_min = y_init;
    y_max = y_init;

    //find extrema
    for(size_t x = 0; x < v_y_data.size(); x++)
    {
        double x_val = AxeTrans(x, x_trans);
        double y_val = AxeTrans(v_y_data[x], y_trans);
        if(x_val < x_min)   x_min = x_val;
        if(x_val > x_max)   x_max = x_val;
        if(y_val < y_min)   y_min = y_val;
        if(y_val > y_max)   y_max = y_val;
    }

    //export results
    *x_min_ext = x_min;
    *x_max_ext = x_max;
    *y_min_ext = y_min;
    *y_max_ext = y_max;

    return ER_okay;
}

int D_Stat::Calc_MinMax(vector<vector<double> > vv_sy_data, double *x_min_ext, double *x_max_ext, double *y_min_ext, double *y_max_ext, int x_trans, int y_trans)
{
    //define buffers
    double x_min_tmp = NAN;
    double x_max_tmp = NAN;
    double y_min_tmp = NAN;
    double y_max_tmp = NAN;

    //define & resize extrema of datasets
    vector<double> v_x_min;
    vector<double> v_x_max;
    vector<double> v_y_min;
    vector<double> v_y_max;
    v_x_min.resize(vv_sy_data.size());
    v_x_max.resize(vv_sy_data.size());
    v_y_min.resize(vv_sy_data.size());
    v_y_max.resize(vv_sy_data.size());

    //calc extrema of datasets
    for(size_t s = 0; s < vv_sy_data.size(); s++)
    {
        Calc_MinMax(vv_sy_data[s], &x_min_tmp, &x_max_tmp, &y_min_tmp, &y_max_tmp, x_trans, y_trans);
        v_x_min[s] = x_min_tmp;
        v_x_max[s] = x_max_tmp;
        v_y_min[s] = y_min_tmp;
        v_y_max[s] = y_max_tmp;
    }

    //calc overall extrema & export

    //x_min
    Calc_MinMax(v_x_min, &x_min_tmp, &x_max_tmp, &y_min_tmp, &y_max_tmp);
    *x_min_ext = y_min_tmp;

    //x_max
    Calc_MinMax(v_x_max, &x_min_tmp, &x_max_tmp, &y_min_tmp, &y_max_tmp);
    *x_max_ext = y_max_tmp;

    //y_min
    Calc_MinMax(v_y_min, &x_min_tmp, &x_max_tmp, &y_min_tmp, &y_max_tmp);
    *y_min_ext = y_min_tmp;

    //x_max
    Calc_MinMax(v_y_max, &x_min_tmp, &x_max_tmp, &y_min_tmp, &y_max_tmp);
    *y_max_ext = y_max_tmp;

    return ER_okay;
}


double D_Stat::Quant(vector<double> *v_stats, unsigned int index)
{
    if(v_stats->empty() || index > 20 || v_stats->size() != c_STAT_NUMBER_OF_STATS)
        return 0;

    switch (index) {
    case 0:     return (*v_stats)[c_STAT_MINIMUM];
    case 1:     return (*v_stats)[c_STAT_QUANTIL_05];
    case 2:     return (*v_stats)[c_STAT_QUANTIL_10];
    case 3:     return (*v_stats)[c_STAT_QUANTIL_15];
    case 4:     return (*v_stats)[c_STAT_QUANTIL_20];
    case 5:     return (*v_stats)[c_STAT_QUARTIL_LOW];
    case 6:     return (*v_stats)[c_STAT_QUANTIL_30];
    case 7:     return (*v_stats)[c_STAT_QUANTIL_35];
    case 8:     return (*v_stats)[c_STAT_QUANTIL_40];
    case 9:     return (*v_stats)[c_STAT_QUANTIL_45];
    case 10:    return (*v_stats)[c_STAT_MEDIAN];
    case 11:    return (*v_stats)[c_STAT_QUANTIL_55];
    case 12:    return (*v_stats)[c_STAT_QUANTIL_60];
    case 13:    return (*v_stats)[c_STAT_QUANTIL_65];
    case 14:    return (*v_stats)[c_STAT_QUANTIL_70];
    case 15:    return (*v_stats)[c_STAT_QUARTIL_UP];
    case 16:    return (*v_stats)[c_STAT_QUANTIL_80];
    case 17:    return (*v_stats)[c_STAT_QUANTIL_85];
    case 18:    return (*v_stats)[c_STAT_QUANTIL_90];
    case 19:    return (*v_stats)[c_STAT_QUANTIL_95];
    case 20:    return (*v_stats)[c_STAT_MAXIMUM];
    default:    return 0;
    }
}

double D_Stat::Quant_Norm(vector<double> *v_stats, unsigned int index)
{
    if(v_stats->empty() || v_stats->size() != c_STAT_NUMBER_OF_STATS || (*v_stats)[c_STAT_SPAN] == 0)
        return 0;

    return (Quant(v_stats, index) - (*v_stats)[c_STAT_MINIMUM]) / (*v_stats)[c_STAT_SPAN];
}

double D_Stat::Quant_1stD(vector<double> *v_stats, unsigned int index, unsigned int step_width)
{
    if(v_stats->empty() || v_stats->size() != c_STAT_NUMBER_OF_STATS)
        return 0;

    return Quant(v_stats, index + step_width) - Quant(v_stats, index);
}

double D_Stat::Quant_1stD_Norm(vector<double> *v_stats, unsigned int index, unsigned int step_width)
{
    if(v_stats->empty() || v_stats->size() != c_STAT_NUMBER_OF_STATS)
        return 0;

    return (Quant_Norm(v_stats, index + step_width) - Quant_Norm(v_stats, index));
}

double D_Stat::Dist(vector<double> *v_stats, unsigned int index)
{
    if(v_stats->empty() || index > 9 || v_stats->size() != c_STAT_NUMBER_OF_STATS)
        return 0;

    switch (index) {
    case 0:     return (*v_stats)[c_STAT_DIST_10_0_PRZ];
    case 1:     return (*v_stats)[c_STAT_DIST_20_0_PRZ];
    case 2:     return (*v_stats)[c_STAT_DIST_30_0_PRZ];
    case 3:     return (*v_stats)[c_STAT_DIST_40_0_PRZ];
    case 4:     return (*v_stats)[c_STAT_DIST_QUARTIL];
    case 5:     return (*v_stats)[c_STAT_DIST_60_0_PRZ];
    case 6:     return (*v_stats)[c_STAT_DIST_70_0_PRZ];
    case 7:     return (*v_stats)[c_STAT_DIST_80_0_PRZ];
    case 8:     return (*v_stats)[c_STAT_DIST_90_0_PRZ];
    case 9:     return (*v_stats)[c_STAT_SPAN];
    default:    return 0;
    }
}

double D_Stat::Dist_Norm(vector<double> *v_stats, unsigned int index)
{
    if(v_stats->empty() || v_stats->size() != c_STAT_NUMBER_OF_STATS || (*v_stats)[c_STAT_SPAN] == 0)
        return 0;

    return (Dist(v_stats, index) - (*v_stats)[c_STAT_MINIMUM]) / (*v_stats)[c_STAT_SPAN];
}

double D_Stat::Dist_1stD(vector<double> *v_stats, unsigned int index, unsigned int step_width)
{
    if(v_stats->empty() || v_stats->size() != c_STAT_NUMBER_OF_STATS)
        return 0;

    return Dist(v_stats, index + step_width) - Dist(v_stats, index);
}

double D_Stat::Dist_1stD_Norm(vector<double> *v_stats, unsigned int index, unsigned int step_width)
{
    if(v_stats->empty() || v_stats->size() != c_STAT_NUMBER_OF_STATS)
        return 0;

    return (Dist_Norm(v_stats, index + step_width) - Dist_Norm(v_stats, index));
}

bool D_Stat::Optimize(double val, double *opt, int opt_type)
{
    switch (opt_type) {

    case c_OPT_1D_MINIMUM:
        if(val < *opt)
        {
            *opt = val;
            return true;
        }
        else
            return false;

    case c_OPT_1D_MINIMUM_ABS:
        if(abs(val) < abs(*opt))
        {
            *opt = abs(val);
            return true;
        }
        else
            return false;

    case c_OPT_1D_MAXIMUM:
        if(val > *opt)
        {
            *opt = val;
            return true;
        }
        else
            return false;

    case c_OPT_1D_MAXIMUM_ABS:
        if(abs(val) > abs(*opt))
        {
            *opt = abs(val);
            return true;
        }
        else
            return false;

    default:
            return false;
    }
}

double D_Stat::Optimize_Init(int opt_type)
{
    switch (opt_type) {

    case c_OPT_1D_MINIMUM:      return + INFINITY;
    case c_OPT_1D_MINIMUM_ABS:  return + INFINITY;
    case c_OPT_1D_MAXIMUM:      return - INFINITY;
    case c_OPT_1D_MAXIMUM_ABS:  return - INFINITY;
    default:                    return NAN;}
}

size_t D_Stat::Value2PoolIndex(double val, double min, double range, size_t classes)
{
    if(classes < 2)
        return 0;

    if(range <= 0)
        return 0;

    double rel_pos = (val - min) / range;
    double cla_pos = rel_pos * classes;

    if(cla_pos < 0)
        return 0;
    else if(cla_pos >= double(classes))
        return classes - 1;
    else
        return size_t(cla_pos);
}

double D_Stat::PoolCenter_From_Value(size_t class_index, double min, double range, size_t classes)
{
    if(classes < 2)
        return min + (range / 2.0);

    double rel_pos = double(class_index + 0.5) / double(classes);

    return min + (rel_pos * range);
}

int D_Stat::PoolStat_Data(vector<Point2d>* vData_Out_PoolStat, vector<double> vData_X_Pool, vector<double> vData_Y_Stat, double x_min, double x_max, size_t x_classes, size_t y_stat)
{
    vector<double> vData_Out_x_Pools;
    vector<double> vData_Out_y_Stats;

    int err = PoolStat_Data(
                &vData_Out_x_Pools,
                &vData_Out_y_Stats,
                vData_X_Pool,
                vData_Y_Stat,
                x_min,
                x_max,
                x_classes,
                y_stat);

    if(err != ER_okay)
        return err;

    size_t n = vData_Out_x_Pools.size();
    if(vData_Out_y_Stats.size() != n)
        return ER_size_missmatch;

    vData_Out_PoolStat->clear();
    vData_Out_PoolStat->reserve(n);
    for(size_t c = 0; c < n; c++)
        (*vData_Out_PoolStat)[c] = Point2d(
                    vData_Out_x_Pools[c],
                    vData_Out_y_Stats[c]);

    return ER_okay;
}

int D_Stat::PoolStat_Data(vector<double> *vData_Out_x_Pools, vector<double> *vData_Out_y_Stats, vector<double> vData_X_Pool, vector<double> vData_Y_Stat, double x_min, double x_max, size_t x_classes, size_t y_stat)
{
    //errors
    if(vData_X_Pool.empty())                                            return ER_empty;
    if(vData_Y_Stat.empty())                                            return ER_empty;
    if(vData_X_Pool.size() != vData_Y_Stat.size())                      return ER_size_missmatch;
    if(x_min >= x_max)                                                  return ER_parameter_missmatch;
    if(x_classes < 1)                                                   return ER_parameter_bad;
    if(y_stat >= c_STAT_NUMBER_OF_STATS)                                return ER_parameter_bad;

    //size of data
    size_t n = vData_X_Pool.size();

    //clear out
    vData_Out_x_Pools->clear();
    vData_Out_y_Stats->clear();
    vData_Out_x_Pools->resize(x_classes);
    vData_Out_y_Stats->resize(x_classes);

    //range
    double x_range = x_max - x_min;

    //class sorted data
    vector<vector<double>> vvData_ClaVal(x_classes);
    for(size_t i = 0; i < n; i++)
    {
        double val_x = vData_X_Pool[i];
        double val_y = vData_Y_Stat[i];

        size_t i_x = Value2PoolIndex(
                    val_x,
                    x_min,
                    x_range,
                    x_classes);

        vvData_ClaVal[i_x].push_back(val_y);
    }

    //calc stat
    function<double (vector<double>)> F_Stat = Function_SingleStat(int(y_stat));
    for(size_t c = 0; c < x_classes; c++)
    {
        //qDebug() << c;
        double val_stat_y = F_Stat(vvData_ClaVal[c]);

        (*vData_Out_x_Pools)[c] = PoolCenter_From_Value(c, x_min, x_range, x_classes);
        (*vData_Out_y_Stats)[c] = val_stat_y;
    }

    return ER_okay;
}

double D_Stat::DistCircular_Rad(double angle1, double angle2)
{    
    //input expected:                    [  0,    2PI ]

    double diff = angle1 - angle2;  //   [ -2PI,  2PI ]

    if (diff < -PI)                 //   [ -2PI, -PI  )
        return PI_2_0 + diff;       //-> [  0,    PI  )
    else if(diff < 0)               //   [ -PI,   0   )
        return -diff;               //-> (  0,    PI  ]
    else if(diff > PI)              //   (  PI,   2PI ]
        return PI_2_0 - diff;       //-> [  0,    PI  )
    else                            //   [  0,    PI  ]
        return diff;                //-> [  0,    PI  ]
}

double D_Stat::DistCircular_Grad(double angle1, double angle2)
{
    double diff = angle1 - angle2;
    if (diff < -180)
        return 360 + diff;
    else if(diff < 0)
        return -diff;
    else if(diff > 180)
        return 360 - diff;
    else
        return diff;
}

void D_Stat::DistCircular_Rad_Sum(double *sum_abs, double *sum_sqr, vector<double> v_angles, size_t index_start, size_t index_end)
{
    size_t n = v_angles.size();

    *sum_abs = 0.0;
    *sum_sqr = 0.0;
    if(index_start < 0 || index_start > n || index_end < 0 || index_end > n || index_start >= index_end)
        return;

    for(size_t i = index_start; i < index_end; i++)
        for(size_t j = 0; j < n; j++)
        {
            double diff = DistCircular_Rad(v_angles[i], v_angles[j]);
            *sum_abs += abs(diff);
            *sum_sqr += diff * diff;
        }
}

void D_Stat::DistCircular_Grad_Sum(double *sum_abs, double *sum_sqr, vector<double> v_angles, size_t index_start, size_t index_end)
{
    size_t n = v_angles.size();

    *sum_abs = 0.0;
    *sum_sqr = 0.0;
    if(index_start < 0 || index_start > n || index_end < 0 || index_end > n || index_start >= index_end)
        return;

    *sum_abs = 0.0;
    *sum_sqr = 0.0;
    for(size_t i = index_start; i < index_end; i++)
        for(size_t j = 0; j < n; j++)
        {
            double diff = DistCircular_Grad(v_angles[i], v_angles[j]);
            *sum_abs += abs(diff);
            *sum_sqr += diff * diff;
        }
}

vector<double> D_Stat::Convert_Rad2Grad(vector<double> v_data_a_rad)
{
    vector<double> v_grad(v_data_a_rad.size());
    for(size_t i = 0; i < v_data_a_rad.size(); i++)
        v_grad[i] = v_data_a_rad[i] * Rad2Grad;

    return v_grad;
}

vector<double> D_Stat::Convert_Grad2Rad(vector<double> v_data_a_grad)
{
    vector<double> v_rad(v_data_a_grad.size());
    for(size_t i = 0; i < v_data_a_grad.size(); i++)
        v_rad[i] = v_data_a_grad[i] * Grad2Rad;

    return v_rad;
}
