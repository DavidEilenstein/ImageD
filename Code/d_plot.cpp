/************************************
 *   added:     20.09.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_plot.h"

D_Plot::D_Plot()
{

}

int D_Plot::Plot_Empty(QChartView *pChartView, QString QS_Text)
{
    //clear old content
    //Free_Memory(pChartView);

    //chart
    QChart *chart = new QChart();
    chart->setTitle(
                "<b>Nothing to see here, move along!</b>"
                "<br>(This means that the displayed plot makes no sense or isn't implemented yet.)"
                "<br>"
                "<br><I>" + QS_Text + "</I>");

    //Axis
    QValueAxis *X_axis = new QValueAxis();
    X_axis->setTitleText("imagination");
    X_axis->setTickCount(2);
    X_axis->setLabelFormat("%f");
    chart->setAxisX(X_axis);

    QValueAxis *Y_axis = new QValueAxis();
    Y_axis->setTitleText("house of nikolaus");
    Y_axis->setTickCount(2);
    Y_axis->setLabelFormat("%d");
    chart->setAxisY(Y_axis);

    //Series
    QLineSeries* series = new QLineSeries;
    series->setName("childhood memories");

    //Data
    double x_scale = PI_0_5;
    double y_sacle = 42 / 3.0;
    series->append(x_scale * 0, y_sacle * 0);
    series->append(x_scale * 2, y_sacle * 0);
    series->append(x_scale * 2, y_sacle * 2);
    series->append(x_scale * 1, y_sacle * 3);
    series->append(x_scale * 0, y_sacle * 2);
    series->append(x_scale * 0, y_sacle * 0);
    series->append(x_scale * 2, y_sacle * 2);
    series->append(x_scale * 0, y_sacle * 2);
    series->append(x_scale * 2, y_sacle * 0);

    //Attach
    chart->addSeries(series);
    series->attachAxis(X_axis);
    series->attachAxis(Y_axis);
    pChartView->setChart(chart);

    return ER_okay;
}


int D_Plot::Plot_AnyReal(QChartView *pChartView, vector<vector<double> > *vvX, vector<vector<double> > *vvY, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y, int plot_mode, int mode_crop_y, double in_min_y, double in_max_y, int mode_trafo_y, double gamma_y, double center_y, double divisor_y, int mode_crop_x, double in_min_x, double in_max_x, int mode_trafo_x, double gamma_x, double center_x, double divisor_x)
{
    if(vvX->empty())                                                        return ER_empty;
    if(vvY->empty())                                                        return ER_empty;
    if((*vvY)[0].empty())                                                   return ER_empty;
    if((*vvX)[0].empty())                                                   return ER_empty;
    if(vvX->size() != vvY->size())                                          return ER_size_missmatch;
    if(static_cast<size_t>(qsl_name_series.size()) != vvX->size())          return ER_size_missmatch;

    //min/max & size check
    //qDebug() << "min/max";
    double x_min = (*vvX)[0][0];
    double x_max = (*vvX)[0][0];
    double y_min = (*vvY)[0][0];
    double y_max = (*vvY)[0][0];
    for(size_t s = 0; s < vvY->size(); s++)
    {
        if((*vvX)[s].size() != (*vvY)[s].size())  return ER_size_missmatch;

        for(size_t i = 0; i < (*vvX)[s].size(); i++)
        {
            //cehck min/max x
            double x = (*vvX)[s][i];
            if(x < x_min)   x_min = x;
            if(x > x_max)   x_max = x;

            //cehck min/max y
            double y = (*vvY)[s][i];
            if(y < y_min)   y_min = y;
            if(y > y_max)   y_max = y;
        }
    }

    //min max used (croped or not)
    if(mode_crop_y == c_VIS_TRAFO_CROP_FIXED)
    {
        y_min = in_min_y;
        y_max = in_max_y;
    }
    if(mode_crop_x == c_VIS_TRAFO_CROP_FIXED)
    {
        x_min = in_min_x;
        x_max = in_max_x;
    }

    //Trafo y---------------------------------------------------------------------
    function<double(double)> F_Trafo_y = D_Math::CopyValue();
    QString QS_TrafoDescription_y = "Showed linear";
    switch (mode_trafo_y) {

    case c_VIS_TRAFO_LINEAR:
        F_Trafo_y = D_Math::CopyValue();
        QS_TrafoDescription_y = "Showed linear";
        break;

    case c_VIS_TRAFO_GAMMA:
        F_Trafo_y = D_Math::GammaCorrect_to01(y_min, y_max, gamma_y);
        if(mode_crop_y == c_VIS_TRAFO_CROP_FIXED)
            QS_TrafoDescription_y = "Showed gamma (" + QString::number(gamma_y) + ") corrected in range " +  QString::number(y_min) + " to " + QString::number(y_max);
        else
            QS_TrafoDescription_y = "Showed gamma (" + QString::number(gamma_y) + ") corrected";
        break;

    case c_VIS_TRAFO_LOG:
        F_Trafo_y = D_Math::Log_Centered(y_min, y_max, center_y, divisor_y);
        if(mode_crop_y == c_VIS_TRAFO_CROP_FIXED)
            QS_TrafoDescription_y = "Showed logarithmic (divisor=" + QString::number(divisor_y) + ", center=" + QString::number(center_y) + ") in range " +  QString::number(y_min) + " to " + QString::number(y_max);
        else
            QS_TrafoDescription_y = "Showed logarithmic (divisor=" + QString::number(divisor_y) + ", center=" + QString::number(center_y) + ")";
        break;

    default:
        return ER_parameter_bad;
    }

    //Trafo x---------------------------------------------------------------------
    function<double(double)> F_Trafo_x = D_Math::CopyValue();
    QString QS_TrafoDescription_x = "Showed linear";
    switch (mode_trafo_x) {

    case c_VIS_TRAFO_LINEAR:
        F_Trafo_x = D_Math::CopyValue();
        QS_TrafoDescription_x = "Showed linear";
        break;

    case c_VIS_TRAFO_GAMMA:
        F_Trafo_x = D_Math::GammaCorrect_to01(x_min, x_max, gamma_x);
        if(mode_crop_x == c_VIS_TRAFO_CROP_FIXED)
            QS_TrafoDescription_x = "Showed gamma (" + QString::number(gamma_x) + ") corrected in range " +  QString::number(x_min) + " to " + QString::number(x_max);
        else
            QS_TrafoDescription_x = "Showed gamma (" + QString::number(gamma_x) + ") corrected";
        break;

    case c_VIS_TRAFO_LOG:
        F_Trafo_x = D_Math::Log_Centered(x_min, x_max, center_x, divisor_x);
        if(mode_crop_x == c_VIS_TRAFO_CROP_FIXED)
            QS_TrafoDescription_x = "Showed logarithmic (divisor=" + QString::number(divisor_x) + ", center=" + QString::number(center_x) + ") in range " +  QString::number(x_min) + " to " + QString::number(x_max);
        else
            QS_TrafoDescription_x = "Showed logarithmic (divisor=" + QString::number(divisor_x) + ", center=" + QString::number(center_x) + ")";
        break;

    default:
        return ER_parameter_bad;
    }

    //clear old content
    Free_Memory(pChartView);

    //Chart
    //qDebug() << "==================================Chart";
    QChart *chart = new QChart();
    chart->setTitle(name_title);

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x + "\n" + QS_TrafoDescription_x);
    x_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisX(x_axis);
    x_axis->setMin(F_Trafo_x(x_min));
    x_axis->setMax(F_Trafo_x(x_max));

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y + "\n" + QS_TrafoDescription_y);
    y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisY(y_axis);
    y_axis->setMin(F_Trafo_y(y_min));
    y_axis->setMax(F_Trafo_y(y_max));


    switch (plot_mode) {

    case c_PLOT_SIMPLE_POINT://========================================Point
    {
        //series (for all img types)
        vector<QScatterSeries*> v_series(vvX->size());
        for(size_t s = 0; s < vvX->size(); s++)
        {
            //create series
            v_series[s] = new QScatterSeries;
            v_series[s]->setName(qsl_name_series[static_cast<int>(s)]);
            //v_series[s]->setUseOpenGL(true);

            //color series
            QColor series_color;
            series_color.setHsv(static_cast<uchar>(255 * (s / static_cast<double>(v_series.size() - 1))), 255, 255);
            v_series[s]->setColor(series_color);

            //add data
            for(size_t i = 0; i < (*vvX)[s].size(); i++)
                v_series[s]->append(
                            F_Trafo_x((*vvX)[s][i]),
                            F_Trafo_y((*vvY)[s][i]));

            //other stuff
            chart->addSeries(v_series[s]);
            v_series[s]->attachAxis(x_axis);
            v_series[s]->attachAxis(y_axis);
            //v_series[s]->setUseOpenGL(false);
        }
    }

    case c_PLOT_SIMPLE_LINE://========================================Line
    case c_PLOT_SIMPLE_LINE_POINT:
    {
        //series (for all img types)
        vector<QLineSeries*> v_series(vvX->size());
        for(size_t s = 0; s < vvX->size(); s++)
        {
            //create series
            v_series[s] = new QLineSeries;
            v_series[s]->setName(qsl_name_series[static_cast<int>(s)]);
            //v_series[s]->setUseOpenGL(true);
            if(plot_mode == c_PLOT_SIMPLE_LINE_POINT)
                v_series[s]->setPointsVisible(true);

            //color series
            QColor series_color;
            series_color.setHsv(static_cast<uchar>(255 * (s / static_cast<double>(v_series.size() - 1))), 255, 255);
            v_series[s]->setColor(series_color);

            //add data
            for(size_t i = 0; i < (*vvX)[s].size(); i++)
                v_series[s]->append(
                            F_Trafo_x((*vvX)[s][i]),
                            F_Trafo_y((*vvY)[s][i]));

            //other stuff
            chart->addSeries(v_series[s]);
            v_series[s]->attachAxis(x_axis);
            v_series[s]->attachAxis(y_axis);
            //v_series[s]->setUseOpenGL(false);
        }
    }

    case c_PLOT_SIMPLE_SPLINE://========================================Spline
    case c_PLOT_SIMPLE_SPLINE_POINT:
    {
        //series (for all img types)
        vector<QSplineSeries*> v_series(vvX->size());
        for(size_t s = 0; s < vvX->size(); s++)
        {
            //create series
            v_series[s] = new QSplineSeries;
            v_series[s]->setName(qsl_name_series[static_cast<int>(s)]);
            //v_series[s]->setUseOpenGL(true);
            if(plot_mode == c_PLOT_SIMPLE_LINE_POINT)
                v_series[s]->setPointsVisible(true);

            //color series
            QColor series_color;
            series_color.setHsv(static_cast<uchar>(255 * (s / static_cast<double>(v_series.size() - 1))), 255, 255);
            v_series[s]->setColor(series_color);

            //add data
            for(size_t i = 0; i < (*vvX)[s].size(); i++)
                v_series[s]->append(
                            F_Trafo_x((*vvX)[s][i]),
                            F_Trafo_y((*vvY)[s][i]));

            //other stuff
            chart->addSeries(v_series[s]);
            v_series[s]->attachAxis(x_axis);
            v_series[s]->attachAxis(y_axis);
            //v_series[s]->setUseOpenGL(false);
        }
    }

    default:
        return ER_parameter_bad;
    }

    //cosmetic
    chart->legend()->setVisible(true);
    //chart->legend()->setAlignment(legend_pos);

    //attach chart
    pChartView->setChart(chart);

    return  ER_okay;
}



int D_Plot::Plot_Hist(QChartView *pChartView, Mat *pMA_In, bool plot_ch[4], bool uniform, bool accum, double* max_occured)
{
    //clear old content
    Free_Memory(pChartView);

    //calc histo
    vector<vector<double>> vv_hist;
    //qDebug() << "calc hist (plot)";
    int ER = D_Img_Proc::Calc_Hist(
                &vv_hist,
                pMA_In,
                uniform,
                accum);

    //if hist calc failed, return error
    if(ER != ER_okay)   return ER;

    unsigned int ch  = (unsigned int)(vv_hist.size());
    unsigned int max = (unsigned int)(vv_hist[0].size());


    //Chart
    QChart *chart = new QChart();
    chart->setTitle("histogram");

    //Axis
    QValueAxis *X_axis = new QValueAxis();
    X_axis->setTitleText("value");
    X_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisX(X_axis);

    QValueAxis *Y_axis = new QValueAxis();
    Y_axis->setTitleText("amount");
    Y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisY(Y_axis);

    //Series
    //qDebug() << "create series";
    vector<QLineSeries*> series;
    series.resize(ch);
    //series->setName("value");

    //Data
    //qDebug() << "add data";
    double val;
    double max_val_occured = 0;
    for(unsigned int c = 0; c < ch; c++)
    {
        if(plot_ch[c])
        {
            series[c] = new QLineSeries;
            series[c]->setName("Channel " + QString::number(c));

            if(ch == 1)
                series[c]->setColor(Qt::darkGray);
            else
                switch (c) {
                case 0:     series[c]->setColor(Qt::blue);      break;
                case 1:     series[c]->setColor(Qt::green);     break;
                case 2:     series[c]->setColor(Qt::red);       break;
                case 3:     series[c]->setColor(Qt::darkGray);  break;
                default:                                        break;}

            for(unsigned int v = 0; v < max; v++)
            {
                //qDebug() << "Channel:" << c << "Value:" << v;
                val = vv_hist[c][v];
                if(val > max_val_occured)
                    max_val_occured = val;
                series[c]->append(v, val);
            }

            chart->addSeries(series[c]);
            series[c]->attachAxis(X_axis);
            series[c]->attachAxis(Y_axis);
        }
    }

    //Attach
    *max_occured = max_val_occured;
    pChartView->setChart(chart);

    //qDebug() << "plot finished";
    return ER_okay;
}

int D_Plot::Plot_Hist_WithStats(QChartView *pChartView, vector<double> v_Data, size_t n_classes, QString name_title, QString name_x, bool uni, bool acc, size_t axe_tick_count)
{
    vector<vector<double>> vvData(1, v_Data);

    double min = INFINITY;
    double max = -INFINITY;
    size_t n = v_Data.size();
    for(size_t i = 0; i < n; i++)
    {
        double val = v_Data[i];
        if(val > max)   max = val;
        if(val < min)   min = val;
    }

    return Plot_Hist_WithStats(
                pChartView,
                vvData,
                min,
                max,
                n_classes,
                name_title,
                name_x,
                uni,
                acc,
                axe_tick_count);
}

int D_Plot::Plot_Hist_WithStats(QChartView *pChartView, vector<vector<double> > vv_Data, double min_x, double max_x, size_t n_classes, QString name_title, QString name_x, bool uni, bool acc, size_t axe_tick_count)
{
    function<double(vector<double>)> F_mean = D_Stat::Function_SingleStat(c_STAT_MEAN_ARITMETIC);
    function<double(vector<double>)> F_std  = D_Stat::Function_SingleStat(c_STAT_CIRC_STAN_DEV_TOTAL);

    size_t n = vv_Data.size();

    vector<double> v_means(n);
    vector<double> v_std(n);
    for(size_t i = 0; i < n; i++)
    {
        v_means[i] = F_mean(vv_Data[i]);
        v_std[i] = F_std(vv_Data[i]);
    }

    return Plot_Hist_WithStats(
                pChartView,
                vv_Data,
                min_x,
                max_x,
                n_classes,
                v_means,
                v_std,
                name_title,
                name_x,
                uni,
                acc,
                axe_tick_count);
}

int D_Plot::Plot_Hist_WithStats(QChartView *pChartView, vector<vector<double> > vv_Data, double min_x, double max_x, size_t n_classes, vector<double> v_mean, vector<double> v_std, QString name_title, QString name_x, bool uni, bool acc, size_t axe_tick_count)
{
    //error checks
    if(vv_Data.empty())             return ER_empty;
    size_t n_sets = vv_Data.size();
    for(size_t i = 0; i < n_sets; i++)
        if(vv_Data.empty())
            return ER_empty;
    if(v_mean.size() != n_sets)     return ER_size_missmatch;
    if(v_std.size() != n_sets)      return ER_size_missmatch;
    if(min_x >= max_x)              return ER_parameter_missmatch;
    if(n_classes <= 1)              return ER_parameter_bad;

    //clear old content
    Free_Memory(pChartView);

    //Chart
    QChart *chart = new QChart();
    chart->setTitle(name_title);

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(acc ? name_x + " (up to)" : name_x);
    x_axis->setTickCount(axe_tick_count);
    chart->setAxisX(x_axis);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(uni ? "relative amount" : "absolute amount");
    y_axis->setTickCount(axe_tick_count);
    chart->setAxisY(y_axis);

    //calc hist
    vector<vector<double>> vv_hist(n_classes, vector<double>());
    double range_x = max_x - min_x;
    double step_x = range_x / (n_classes - 1);
    size_t n_data_max = 0;
    for(size_t i_set = 0; i_set < n_sets; i_set++)
    {
        vv_hist[i_set].resize(n_classes);
        size_t n_data = vv_Data[i_set].size();
        n_data_max = max(n_data_max, n_data);
        for(size_t i_data = 0; i_data < n_data; i_data++)
        {
            size_t i_hist =  min(static_cast<double>(n_classes - 1), max(0.0, ((vv_Data[i_set][i_data] - min_x) / step_x)));
            vv_hist[i_set][i_hist]++;
        }
    }

    //tune hist
    if(uni)
        for(size_t i_set = 0; i_set < n_sets; i_set++)
            for(size_t i_hist = 0; i_hist < n_classes; i_hist++)
                vv_hist[i_set][i_hist] /= n_data_max;
    if(acc)
        for(size_t i_set = 0; i_set < n_sets; i_set++)
            for(size_t i_hist = 0; i_hist < n_classes; i_hist++)
                vv_hist[i_set][i_hist] += vv_hist[i_set][i_hist - 1];

    //Series hist
    double y_max = 0;
    vector<QLineSeries*> v_series_hist(n_sets);
    for(size_t i_set = 0; i_set < n_sets; i_set++)
    {
        //relative position
        double rel_pos = n_sets <= 1 ? 0 : static_cast<double>(i_set) / (n_sets - 1);

        //series
        v_series_hist[i_set] = new QLineSeries;

        //data
        for(size_t i_hist = 0; i_hist < n_classes; i_hist++)
        {
            if(min_x + i_hist * step_x != 0.0)
            {
                v_series_hist[i_set]->append(min_x + i_hist * step_x, vv_hist[i_set][i_hist]);
                y_max = max(y_max, vv_hist[i_set][i_hist]);
            }
        }

        //attach
        chart->addSeries(v_series_hist[i_set]);
        v_series_hist[i_set]->attachAxis(x_axis);
        v_series_hist[i_set]->attachAxis(y_axis);

        //calc color
        if(n_sets == 1)
        {
            v_series_hist[i_set]->setColor(Qt::black);
        }
        else
        {
            QColor color;
            color.setHsv(rel_pos * 240, 255, 255);
            v_series_hist[i_set]->setColor(color);
        }
    }

    //Series std
    vector<QLineSeries*> v_series_std(n_sets);
    for(size_t i_set = 0; i_set < n_sets; i_set++)
    {
        //relative position
        double rel_pos = n_sets <= 1 ? 0 : static_cast<double>(i_set) / (n_sets - 1);

        //series
        v_series_std[i_set] = new QLineSeries;

        double dev_low = v_mean[i_set] - v_std[i_set];
        double dev_high = v_mean[i_set] + v_std[i_set];
        if((dev_low >= min_x && dev_low <= max_x) || (dev_high >= min_x && dev_high <= max_x) || (dev_low < min_x && dev_high > max_x))
        {
            v_series_std[i_set]->append(max(min_x, dev_low) , y_max * rel_pos);
            v_series_std[i_set]->append(min(max_x, dev_high) , y_max * rel_pos);
        }

        //attach
        chart->addSeries(v_series_std[i_set]);
        v_series_std[i_set]->attachAxis(x_axis);
        v_series_std[i_set]->attachAxis(y_axis);

        //calc color
        if(n_sets == 1)
        {
            v_series_std[i_set]->setColor(Qt::black);
        }
        else
        {
            QColor color;
            color.setHsv(rel_pos * 240, 255, 255);
            v_series_std[i_set]->setColor(color);
        }
    }

    //Series mean
    vector<QScatterSeries*> v_series_mean(n_sets);
    for(size_t i_set = 0; i_set < n_sets; i_set++)
    {
        //relative position
        double rel_pos = n_sets <= 1 ? 0 : static_cast<double>(i_set) / (n_sets - 1);

        //series
        v_series_mean[i_set] = new QScatterSeries;

        //data
        if(v_mean[i_set] >= min_x && v_mean[i_set] <= max_x)
            v_series_mean[i_set]->append(v_mean[i_set] , y_max * rel_pos);

        //attach
        chart->addSeries(v_series_mean[i_set]);
        v_series_mean[i_set]->attachAxis(x_axis);
        v_series_mean[i_set]->attachAxis(y_axis);
        v_series_mean[i_set]->setMarkerSize(15);

        //calc color
        if(n_sets == 1)
        {
            v_series_mean[i_set]->setColor(Qt::black);
        }
        else
        {
            QColor color;
            color.setHsv(rel_pos * 240, 255, 255);
            v_series_mean[i_set]->setColor(color);
        }
    }

    //show in plot
    chart->legend()->hide();
    pChartView->setChart(chart);
    y_axis->setMin(0.0);
    y_axis->setMax(y_max);

    return ER_okay;
}

int D_Plot::Plot_Hist_WithStats_Color(QChartView *pChartView, vector<double> v_DataHist, vector<double> v_DataColor, function<double (vector<double>)> F_ColorStat_Hue, function<double (vector<double>)> F_ColorStat_Value, double min_x_hist, double max_x_hist, double min_x_color_hue, double max_x_color_hue, double min_x_color_value, double max_x_color_value, size_t n_classes, double mean_hist, double std_hist, QString name_title, QString name_x, bool uni, bool acc, size_t axe_tick_count)
{
    if(v_DataHist.empty())                          return ER_empty;
    if(v_DataColor.empty())                         return ER_empty;
    if(v_DataHist.size() != v_DataColor.size())     return ER_size_missmatch;
    if(min_x_hist >= max_x_hist)                    return ER_parameter_missmatch;
    if(min_x_color_hue >= max_x_color_hue)          return ER_parameter_missmatch;
    if(min_x_color_value >= max_x_color_value)      return ER_parameter_missmatch;
    if(n_classes <= 1)                              return ER_parameter_bad;

    //clear old content
    Free_Memory(pChartView);

    //data count
    size_t n = v_DataHist.size();

    //Chart
    QChart *chart = new QChart();
    chart->setTitle(name_title + "<br>n=" + QString::number(n));

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(acc ? name_x + " (up to)" : name_x);
    x_axis->setTickCount(axe_tick_count);
    chart->setAxisX(x_axis);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(uni ? "relative amount" : "absolute amount");
    y_axis->setTickCount(axe_tick_count);
    y_axis->setMin(0.0);
    chart->setAxisY(y_axis);

    //data ranges and steps
    double range_x_hist = max_x_hist - min_x_hist;
    double step_x_hist = range_x_hist / (n_classes - 1);
    double range_x_color_hue = max_x_color_hue - min_x_color_hue;
    double range_x_color_value = max_x_color_value - min_x_color_value;

    //calc hist and save color calc values
    vector<double> v_hist(n_classes, 0);
    vector<vector<double>> vv_hist_ColorDataRaw(n_classes, vector<double>());
    for(size_t i_data = 0; i_data < n; i_data++)
    {
        size_t i_hist = static_cast<size_t>(min(static_cast<double>(n_classes - 1), max(0.0, ((v_DataHist[i_data] - min_x_hist) / step_x_hist))));
        v_hist[i_hist]++;
        vv_hist_ColorDataRaw[i_hist].push_back(v_DataColor[i_data]);
    }

    //tune hist
    if(uni)
        for(size_t i = 0; i < n_classes; i++)
            v_hist[i] /= n;
    if(acc)
        for(size_t i = 1; i < n_classes; i++)
            v_hist[i] += v_hist[i - 1];

    //Series hist
    double max_y = 0;
    vector<QLineSeries*> v_series_hist(n_classes - 1);
    for(size_t i_hist = 0; i_hist < n_classes - 1; i_hist++)
    {
        //init series
        v_series_hist[i_hist] = new QLineSeries();

        //add data
        v_series_hist[i_hist]->append(min_x_hist + (i_hist * step_x_hist), v_hist[i_hist]);
        v_series_hist[i_hist]->append(min_x_hist + ((i_hist + 1) * step_x_hist), v_hist[i_hist + 1]);

        //calc max of all series
        max_y = max(max_y, max(v_hist[i_hist], v_hist[i_hist + 1]));

        //attach
        chart->addSeries(v_series_hist[i_hist]);
        v_series_hist[i_hist]->attachAxis(x_axis);
        v_series_hist[i_hist]->attachAxis(y_axis);

        //calc and set color
        if(vv_hist_ColorDataRaw[i_hist].empty())
        {
            v_series_hist[i_hist]->setColor(Qt::darkGray);
        }
        else
        {
            double hue_stat = max(min_x_color_hue, min(max_x_color_hue, F_ColorStat_Hue(vv_hist_ColorDataRaw[i_hist])));
            double hue = (1 - ((hue_stat - min_x_color_hue) / range_x_color_hue)) * 240;

            double value_stat = max(min_x_color_value, min(max_x_color_value, F_ColorStat_Value(vv_hist_ColorDataRaw[i_hist])));
            double value = (1 - ((value_stat - min_x_color_value) / range_x_color_value)) * 255;

            //qDebug() << "hue/value" << hue << value;

            QColor color;
            color.setHsv(hue, 255, value);
            v_series_hist[i_hist]->setColor(color);
        }
    }

    //Series std
    QLineSeries *series_std  = new QLineSeries();
    double dev_low = mean_hist - std_hist;
    double dev_high = mean_hist + std_hist;
    if((dev_low >= min_x_hist && dev_low <= max_x_hist) || (dev_high >= min_x_hist && dev_high <= max_x_hist) || (dev_low < min_x_hist && dev_high > max_x_hist))
    {
        series_std->append(max(min_x_hist, dev_low) , 0.0);
        series_std->append(min(max_x_hist, dev_high) , 0.0);
    }
    //attach
    chart->addSeries(series_std);
    series_std->setColor(Qt::black);
    series_std->attachAxis(x_axis);
    series_std->attachAxis(y_axis);

    //Series mean
    QScatterSeries *series_mean  = new QScatterSeries();
    if(mean_hist >= min_x_hist && mean_hist <= max_x_hist)
    {
        series_mean->append(mean_hist , 0.0);
    }
    //attach
    chart->addSeries(series_mean);
    series_mean->setMarkerSize(15);
    series_mean->setColor(Qt::black);
    series_mean->attachAxis(x_axis);
    series_mean->attachAxis(y_axis);

    //show in plot
    chart->legend()->hide();
    pChartView->setChart(chart);
    x_axis->setMin(min_x_hist);
    x_axis->setMax(max_x_hist);
    y_axis->setMin(0.0);
    y_axis->setMax(max_y);

    return ER_okay;
}

int D_Plot::Plot_Hist_Single_Classes(QChartView *pChartView, vector<double> *v_hist, double min, double step, QString name_title, QString name_series, QString name_x, QString name_y, bool ignore_first)
{
    //clear old content
    Free_Memory(pChartView);

    //Chart
    //qDebug() << "==================================Chart";
    QChart *chart = new QChart();
    //chart->createDefaultAxes();
    chart->setTitle(name_title);
    //chart->legend()->setVisible(false);
    //chart->legend()->setAlignment(Qt::AlignBottom);

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    x_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisX(x_axis);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisY(y_axis);


    //Series
    //qDebug() << "Series";
    QLineSeries *series  = new QLineSeries();
    series->setName(name_series);


    //start
    unsigned int start = 0;
    if(ignore_first)
        start = 1;


    //Data
    //qDebug() << "Data";
    for(unsigned int c = start; c < v_hist->size(); c++)
    {
        double value = min + (c * step);
        double count = (*v_hist)[c];

        //qDebug() << "class:" << c << " - " << value << count;

        series->append(value, count);
    }
    //qDebug() << "series count:" << series->count();


    //Attach
    chart->addSeries(series);
    series->attachAxis(x_axis);
    series->attachAxis(y_axis);
    pChartView->setChart(chart);

    //qDebug() << "Plot Sucess===============================";
    return ER_okay;
}

int D_Plot::Plot_Hist_Multi_Classes(QChartView *pChartView, vector<vector<double> > *vv_hist, double min_x, double max_x, double max_y, double step, QString name_title, QString name_series, QString name_x, QString name_y, bool ignore_first)
{
    QStringList QSL_name_series;
    for(size_t s = 0; s < vv_hist->size(); s++)
        QSL_name_series.append(name_series + QString::number(s));

    return Plot_Hist_Multi_Classes(
                pChartView,
                vv_hist,
                min_x,
                max_x,
                max_y,
                step,
                name_title,
                QSL_name_series,
                name_x,
                name_y,
                ignore_first);
}

int D_Plot::Plot_Hist_Multi_Classes(QChartView *pChartView, vector<vector<double> > *vv_hist, double min_x, double max_x, double max_y, double step, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y, bool ignore_first)
{
    if(vv_hist->empty())                                                    return ER_empty;
    if(vv_hist->size() != static_cast<size_t>(qsl_name_series.size()))      return ER_size_missmatch;

    //clear old content
    Free_Memory(pChartView);

    //Chart
    //qDebug() << "==================================Chart";
    QChart *chart = new QChart();
    chart->setTitle(name_title);


    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    x_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisX(x_axis);
    x_axis->setMin(min_x);
    x_axis->setMax(max_x);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisY(y_axis);
    y_axis->setMin(0);
    y_axis->setMax(max_y);


    //Series
    vector<QLineSeries*> series;
    series.resize(vv_hist->size());

    //start
    unsigned int start = 0;
    if(ignore_first)
        start = 1;

    for(unsigned int s = 0; s < vv_hist->size(); s++)
    {
        series[s] = new QLineSeries();
        series[s]->setName(qsl_name_series[s]);

        //Data
        for(unsigned int c = start; c < (*vv_hist)[s].size(); c++)
        {
            double value = (c * step) + min_x;  //x
            double count = (*vv_hist)[s][c];    //y
            series[s]->append(value, count);
        }

        chart->addSeries(series[s]);
        series[s]->attachAxis(x_axis);
        series[s]->attachAxis(y_axis);
    }

    //Attach
    pChartView->setChart(chart);

    //qDebug() << "Axis Range - set - " << "x:" << min_x << max_x << "y:" << 0 << max_y;
    //qDebug() << "Axis Range - end - " << "x:" << x_axis->min() << x_axis->max() << "y:" << y_axis->min() << y_axis->max();

    //qDebug() << "Plot Sucess===============================";
    return ER_okay;
}

int D_Plot::Plot_Hist_Any(QChartView *pChartView, Mat *pMA_In, int classes, QString name_title, QString qs_name_series, QString name_x, QString name_y, bool uniform, bool accum, bool ignore_first)
{
    QStringList QSL_name_series;
    for(int s = 0; s < pMA_In->channels(); s++)
        QSL_name_series.append(qs_name_series + QString::number(s));

    return Plot_Hist_Any(
                pChartView,
                pMA_In,
                classes,
                name_title,
                QSL_name_series,
                name_x,
                name_y,
                uniform,
                accum,
                ignore_first);
}

int D_Plot::Plot_Hist_Any(QChartView *pChartView, Mat *pMA_In, int classes, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y, bool uniform, bool accum, bool ignore_first)
{
    if(pMA_In->empty())                                 return ER_empty;
    if(classes < 1)                                     return ER_parameter_bad;
    if(pMA_In->channels() > 4)                          return ER_channel_bad;
    if(pMA_In->channels() != qsl_name_series.size())    return ER_size_missmatch;


    //error handler
    int ER;

    //clear old content
    Free_Memory(pChartView);

    //base data containers
    vector<vector<double>> vv_hist;
    vector<double> v_min;
    vector<double> v_max;
    vector<double> v_step;

    //calc hist
    ER = D_Img_Proc::Calc_Hist_Multi(
                &vv_hist,
                pMA_In,
                uniform,
                accum,
                classes,
                &v_min,
                &v_max,
                &v_step);
    if(ER != ER_okay)   return ER;


    //find overall min/max x/y
    double min_x = v_min[0];
    double max_x = v_max[0];
    double min_y = vv_hist[0][0];
    double max_y = vv_hist[0][0];
    for(int c = 0; c < pMA_In->channels(); c++)
    {
        if(v_min[c] < min_x)  min_x = v_min[c];
        if(v_max[c] > max_x)  max_x = v_max[c];

        for(int v = 0; v < classes; v++)
        {
            if(vv_hist[c][v] < min_y)   min_y = vv_hist[c][v];
            if(vv_hist[c][v] > max_y)   max_y = vv_hist[c][v];
        }
    }

    //Chart
    QChart *chart = new QChart();
    chart->setTitle(name_title);


    //Axis
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    x_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisX(x_axis);
    x_axis->setMin(min_x);
    x_axis->setMax(max_x);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisY(y_axis);
    y_axis->setMin(min_y);
    y_axis->setMax(max_y);


    //Series
    vector<QLineSeries*> series;
    series.resize(vv_hist.size());

    //start
    unsigned int start = 0;
    if(ignore_first)
        start = 1;

    //loop data
    for(unsigned int ch = 0; ch < vv_hist.size(); ch++)
    {
        series[ch] = new QLineSeries();
        series[ch]->setName(qsl_name_series[ch]);

        //Data
        for(unsigned int cla = start; cla < vv_hist[ch].size(); cla++)
        {
            double value = (cla * v_step[ch]) + v_min[ch];  //x
            double count = vv_hist[ch][cla];                //y
            series[ch]->append(value, count);
        }

        //color
        switch (ch) {
        case 0:     series[ch]->setColor(Qt::blue);     break;
        case 1:     series[ch]->setColor(Qt::green);    break;
        case 2:     series[ch]->setColor(Qt::red);      break;
        case 3:     series[ch]->setColor(Qt::gray);     break;
        default:                                        break;}

        chart->addSeries(series[ch]);
        series[ch]->attachAxis(x_axis);
        series[ch]->attachAxis(y_axis);
    }

    //Attach
    pChartView->setChart(chart);


    return ER_okay;
}

int D_Plot::Plot_Hist_Any(QChartView *pChartView, D_VisDat_Obj *pVD_In, int classes, QString name_title, QString qs_name_series, QString name_x, QString name_y, bool uniform, bool accum, bool ignore_first)
{
    QStringList QSL_name_series;
    for(int s = 0; s < pVD_In->pMA_full()->channels(); s++)
        QSL_name_series.append(qs_name_series + QString::number(s));

    return Plot_Hist_Any(
                pChartView,
                pVD_In,
                classes,
                name_title,
                QSL_name_series,
                name_x,
                name_y,
                uniform,
                accum,
                ignore_first);
}

int D_Plot::Plot_Hist_Any(QChartView *pChartView, D_VisDat_Obj *pVD_In, int classes, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y, bool uniform, bool accum, bool ignore_first)
{
    if(pVD_In->pMA_full()->empty())                                 return ER_empty;
    if(classes < 1)                                                 return ER_parameter_bad;
    if(pVD_In->pMA_full()->channels() > 4)                          return ER_channel_bad;
    if(pVD_In->pMA_full()->channels() != qsl_name_series.size())    return ER_size_missmatch;

    //error handler
    int ER;

    //clear old content
    Free_Memory(pChartView);

    //base data containers
    vector<vector<double>> vv_hist;
    vector<double> v_min;
    vector<double> v_max;
    vector<double> v_step;

    //calc hist
    ER = D_VisDat_Proc::Calc_Hist_Multi(
                &vv_hist,
                pVD_In,
                uniform,
                accum,
                classes,
                &v_min,
                &v_max,
                &v_step);
    if(ER != ER_okay)   return ER;


    //find overall min/max x/y
    double min_x = v_min[0];
    double max_x = v_max[0];
    double min_y = vv_hist[0][0];
    double max_y = vv_hist[0][0];
    for(int c = 0; c < pVD_In->pMA_full()->channels(); c++)
    {
        if(v_min[c] < min_x)  min_x = v_min[c];
        if(v_max[c] > max_x)  max_x = v_max[c];

        for(int v = 0; v < classes; v++)
        {
            if(vv_hist[c][v] < min_y)   min_y = vv_hist[c][v];
            if(vv_hist[c][v] > max_y)   max_y = vv_hist[c][v];
        }
    }

    //Chart
    QChart *chart = new QChart();
    chart->setTitle(name_title);


    //Axis
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    x_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisX(x_axis);
    x_axis->setMin(min_x);
    x_axis->setMax(max_x);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisY(y_axis);
    y_axis->setMin(min_y);
    y_axis->setMax(max_y);


    //Series
    vector<QLineSeries*> series;
    series.resize(vv_hist.size());

    //start
    unsigned int start = 0;
    if(ignore_first)
        start = 1;

    //loop data
    for(unsigned int ch = 0; ch < vv_hist.size(); ch++)
    {
        series[ch] = new QLineSeries();
        series[ch]->setName(qsl_name_series[ch]);

        //Data
        for(unsigned int cla = start; cla < vv_hist[ch].size(); cla++)
        {
            double value = (cla * v_step[ch]) + v_min[ch];  //x
            double count = vv_hist[ch][cla];                //y
            series[ch]->append(value, count);
        }

        //color
        switch (ch) {
        case 0:     series[ch]->setColor(Qt::blue);     break;
        case 1:     series[ch]->setColor(Qt::green);    break;
        case 2:     series[ch]->setColor(Qt::red);      break;
        case 3:     series[ch]->setColor(Qt::gray);     break;
        default:                                        break;}

        chart->addSeries(series[ch]);
        series[ch]->attachAxis(x_axis);
        series[ch]->attachAxis(y_axis);
    }

    //Attach
    pChartView->setChart(chart);


    return ER_okay;
}



int D_Plot::Plot_Times_Step(QChartView *pChartView, unsigned int *times, bool plot_time[4])
{
    //clear old content
    Free_Memory(pChartView);

    //series
    QPieSeries *series = new QPieSeries;
    if(plot_time[c_TIME_IMG_PROC])  series->append("Processing",        times[c_TIME_IMG_PROC]);
    if(plot_time[c_TIME_IMG_CONV])  series->append("Conversion",        times[c_TIME_IMG_CONV]);
    if(plot_time[c_TIME_IMG_SHOW])  series->append("Show",              times[c_TIME_IMG_SHOW]);
    if(plot_time[c_TIME_HIST])      series->append("Histogram",         times[c_TIME_HIST]);
    series->setLabelsVisible();

    //add times in labels and set fix colors
    for(auto slice : series->slices())
    {
        QString label = slice->label();

        if(label == "Processing")   slice->setColor(Qt::red);
        if(label == "Conversion")   slice->setColor(Qt::blue);
        if(label == "Show")         slice->setColor(Qt::green);
        if(label == "Histogram")    slice->setColor(Qt::gray);

        double t = slice->value();//ms by default
        if(t < 1000.0)
            label = label + ": " + QString::number(t,           'g', 3) + "ms";
        else if(t < 60000.0)
            label = label + ": " + QString::number(t / 1000.0,    'g', 3) + "s";
        else if(t < 3600000.0)
            label = label + ": " + QString::number(t / 60000.0,   'g', 3) + "min";
        else
            label = label + ": " + QString::number(t / 3600000.0, 'g', 3) + "h";
        slice->setLabel(label);
    }

    QChart *pChart = new QChart();
    pChart->addSeries(series);
    pChart->setTitle("Time Measurement");

    pChartView->setChart(pChart);

    return ER_okay;
}

int D_Plot::Plot_Times_All(QChartView *pChartView, D_Storage *pStore, bool plot_time[], QLabel *L_total)
{
    //clear old content
    Free_Memory(pChartView);

    //max time per step
    unsigned int cur_time_ms = 0;
    unsigned int max_time_ms = 0;
    for(int pos = 1; pos < pStore->size(); pos++)
    {
        cur_time_ms = 0;
        for(unsigned int set = 0; set < 4; set++)
            cur_time_ms += pStore->time(pos, set);
        if(cur_time_ms > max_time_ms)
            max_time_ms = cur_time_ms;
    }

    //time unit
    double time_div = 1.0;
    QString time_unit = "ms";
    if(max_time_ms < 1000.0)
    {
        time_div = 1.0;
        time_unit = "ms";
    }
    else if(max_time_ms < 60000.0)
    {
        time_div = 1000.0;
        time_unit = "s";
    }
    else if(max_time_ms < 3600000.0)
    {
        time_div = 60000.0;
        time_unit = "min";
    }
    else
    {
        time_div = 3600000.0;
        time_unit = "h";
    }




    //Sets, Series, Data
    QBarSet *sets[4];
    QStackedBarSeries *series = new QStackedBarSeries();
    double time_total = 0;

    for(unsigned int set = 0; set < 4; set++)
    {
        if(plot_time[set])
        {
            sets[set] = new QBarSet("");

            switch (set) {
            case c_TIME_IMG_PROC:   sets[set]->setLabel("Processing");      sets[set]->setColor(Qt::red);   break;
            case c_TIME_IMG_CONV:   sets[set]->setLabel("Conversion");      sets[set]->setColor(Qt::blue);  break;
            case c_TIME_IMG_SHOW:   sets[set]->setLabel("Show");            sets[set]->setColor(Qt::green); break;
            case c_TIME_HIST:       sets[set]->setLabel("Histogram");       sets[set]->setColor(Qt::gray);  break;
            default:                                                                                        break;}

            for(int pos = 1; pos < pStore->size(); pos++)
            {
                double t = pStore->time(pos, set) / time_div;
                sets[set]->append(t);
                time_total += t;
            }
            series->append(sets[set]);
        }
    }

    //Chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Times");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    //Categories (->x_axis)
    QStringList categories;
    for(int pos = 1; pos < pStore->size(); pos++)
        categories.append(QString::number(pos));

    //Axis
    QBarCategoryAxis *x_axis = new QBarCategoryAxis();
    x_axis->append(categories);
    x_axis->setTitleText("Steps");

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText("time /" + time_unit);

    //Attach
    chart->createDefaultAxes();
    chart->setAxisX(x_axis, series);
    chart->setAxisY(y_axis, series);
    pChartView->setChart(chart);

    L_total->setText("Total of displayed times: " + QString::number(time_total) + time_unit);

    return ER_okay;
}

int D_Plot::Plot_BarCore_Single(QChartView *pChartView, vector<double> v_data, QString name_title, QString name_series, QStringList name_categories,QString name_x, QString name_y)
{
    if(v_data.empty())                                                  return ER_empty;
    if(name_categories.empty())                                         return ER_empty;
    if(v_data.size() != static_cast<size_t>(name_categories.size()))    return ER_size_missmatch;

    //clear old content
    Free_Memory(pChartView);

    //Set, Series
    QBarSet *set        = new QBarSet(name_series);
    QBarSeries *series  = new QBarSeries();

    //Data
    for(size_t st = 0; st < v_data.size(); st++)
        set->append(v_data[st]);
    series->append(set);

    //Chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(name_title + "<br>n=" + QString::number(v_data.size()));

    //Axis
    QBarCategoryAxis *x_axis = new QBarCategoryAxis();
    x_axis->append(name_categories);
    x_axis->setTitleText(name_x);
    x_axis->setLabelsAngle(90);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);

    //Attach
    chart->createDefaultAxes();
    chart->setAxisX(x_axis, series);
    chart->setAxisY(y_axis, series);
    pChartView->setChart(chart);

    return ER_okay;
}

int D_Plot::Plot_BarCore_Multi(QChartView *pChartView, vector<vector<double> > vv_data_SetVal, QString name_title, QStringList qsl_name_sets, QStringList name_categories, QString name_x, QString name_y)
{
    qDebug() << "Plot_BarCore_Multi" << "errors";
    if(vv_data_SetVal.empty())                                                      return ER_empty;
    if(vv_data_SetVal[0].empty())                                                   return ER_empty;
    if(name_categories.empty())                                                     return ER_empty;
    if(qsl_name_sets.empty())                                                       return ER_empty;
    if(vv_data_SetVal.size() != static_cast<size_t>(qsl_name_sets.size()))          return ER_size_missmatch;
    if(vv_data_SetVal[0].size() != static_cast<size_t>(name_categories.size()))     return ER_size_missmatch;
    for(size_t st = 0; st < vv_data_SetVal.size(); st++)
        if(vv_data_SetVal[st].size() != vv_data_SetVal[0].size()) return ER_size_missmatch;

    //clear old content
    Free_Memory(pChartView);

    //Set, Series
    qDebug() << "Plot_BarCore_Multi" << "set/series";
    vector<QBarSet*> v_set;
    v_set.resize(vv_data_SetVal.size());
    QBarSeries *series  = new QBarSeries();

    //Chart
    qDebug() << "Plot_BarCore_Multi" << "chart";
    QChart *chart = new QChart();
    chart->setTitle(name_title);

    //Axis
    qDebug() << "Plot_BarCore_Multi" << "axis";
    QBarCategoryAxis *x_axis = new QBarCategoryAxis();
    x_axis->append(name_categories);
    x_axis->setTitleText(name_x);
    x_axis->setLabelsAngle(90);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);

    //Data
    qDebug() << "Plot_BarCore_Multi" << "data";
    for(size_t st = 0; st < v_set.size(); st++)
    {
        qDebug() << "Plot_BarCore_Multi" << "data-set" << st;
        v_set[st] = new QBarSet(qsl_name_sets[static_cast<int>(st)]);

        for(size_t v = 0; v < vv_data_SetVal[st].size(); v++)
        {
            qDebug() << "Plot_BarCore_Multi" << "data-set" << st << "data-point" << v;
            v_set[st]->append(vv_data_SetVal[st][v]);
        }

        qDebug() << "Plot_BarCore_Multi" << "data-set" << st << "append to series";
        series->append(v_set[st]);
    }

    //Attach
    qDebug() << "Plot_BarCore_Multi" << "attach";
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setAxisX(x_axis, series);
    chart->setAxisY(y_axis, series);
    pChartView->setChart(chart);

    return ER_okay;
}

int D_Plot::Plot_BarCore_Start1_Single(QChartView *pChartView, vector<double> *v_hist, QString name_title, QString name_series, QString name_x, QString name_y)
{
    //clear old content
    Free_Memory(pChartView);

    //Set, Series
    QBarSet *set        = new QBarSet(name_series);
    QBarSeries *series  = new QBarSeries();

    //Data
    for(unsigned int core = 0; core < v_hist->size(); core++)
        set->append((*v_hist)[core]);
    series->append(set);

    //Chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(name_title + "<br>n=" + QString::number(v_hist->size()));
    chart->legend()->setVisible(false);
    chart->legend()->setAlignment(Qt::AlignBottom);

    //Categories (->x_axis)
    QStringList categories;
    for(unsigned int core = 1; core < v_hist->size(); core++)
        categories.append(QString::number(core));

    //Axis
    QBarCategoryAxis *x_axis = new QBarCategoryAxis();
    x_axis->append(categories);
    x_axis->setTitleText(name_x);
    x_axis->setLabelsAngle(90);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);

    //Attach
    chart->createDefaultAxes();
    chart->setAxisX(x_axis, series);
    chart->setAxisY(y_axis, series);
    pChartView->setChart(chart);

    return ER_okay;
}

int D_Plot::Plot_Scatter_2D_Parameter(QChartView *pChartView, vector<vector<vector<double> > > *vvv_ParSetVal, unsigned int set, unsigned int par_x, unsigned int par_y, QString name_title, QString name_series, QString name_x, QString name_y)
{
    if(vvv_ParSetVal->empty())                                                          return ER_empty;
    if(par_x >= vvv_ParSetVal->size())                                                  return ER_index_out_of_range;
    if(par_y >= vvv_ParSetVal->size())                                                  return ER_index_out_of_range;
    if((*vvv_ParSetVal)[par_x].size() != (*vvv_ParSetVal)[par_y].size())                return ER_size_missmatch;
    if(set >= (*vvv_ParSetVal)[par_x].size())                                           return ER_index_out_of_range;
    if(set >= (*vvv_ParSetVal)[par_y].size())                                           return ER_index_out_of_range;
    if((*vvv_ParSetVal)[par_x][set].size() != (*vvv_ParSetVal)[par_y][set].size())      return ER_size_missmatch;

    //this method only exists to make older code work
    //use general scatter plot instead
    return Plot_Scatter_2D_Single_Y(
                pChartView,
                &((*vvv_ParSetVal)[par_x][set]),
                &((*vvv_ParSetVal)[par_y][set]),
                name_title,
                name_series,
                name_x,
                name_y);

    /*
    //clear old content
    Free_Memory(pChartView);

    //Chart
    //qDebug() << "==================================Chart";
    QChart *chart = new QChart();
    chart->setTitle(name_title);

    //Range (only x - needed for fit display)
    double x_min = (*vvv_ParSetVal)[par_x][set][0];
    double x_max = (*vvv_ParSetVal)[par_x][set][0];
    for(int ix = 0; ix < (*vvv_ParSetVal)[par_x][set].size(); ix++)
    {
        double x = (*vvv_ParSetVal)[par_x][set][ix];
        if(x < x_min)   x_min = x;
        if(x > x_max)   x_max = x;
    }

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    chart->setAxisX(x_axis);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    chart->setAxisY(y_axis);

    //2D Stats
    vector<double> v_stats_2D;
    int ER = D_Stat::Calc_Stats_2D(
                &v_stats_2D,
                (*vvv_ParSetVal)[par_x][set],
                (*vvv_ParSetVal)[par_y][set]);
    if(ER != ER_okay)
    {
        //Free_Memory(pChartView);
        return ER;
    }

    //Series
    //qDebug() << "Series";
    QScatterSeries *series  = new QScatterSeries();
    series->setName(name_series);
    series->setUseOpenGL(true);
    series->setMarkerSize(8);


    //Data
    //qDebug() << "Data";
    for(unsigned int v = 0; (v < (*vvv_ParSetVal)[par_x][set].size()) && (v < (*vvv_ParSetVal)[par_y][set].size()); v++)
        series->append(
                    (*vvv_ParSetVal)[par_x][set][v],
                    (*vvv_ParSetVal)[par_y][set][v]);

    //Fit-Series
    QLineSeries *series_fit = new QLineSeries;
    series_fit->setName(
                "f(x)=" + QString::number(v_stats_2D[c_STAT_2D_LINEAR_FIT_SLOPE], 'g', 3) + "x+" + QString::number(v_stats_2D[c_STAT_2D_LINEAR_FIT_Y_AXIS_SECTION], 'g', 3) +
                "<br>R²: " + QString::number(v_stats_2D[c_STAT_2D_R_SQUARE_SAMPLE], 'g', 3));
    series_fit->setColor(series->color());

    //Fit data
    double x_range = x_max - x_min;
    double x1 = x_min - 10 * x_range;
    double x2 = x_max + 10 * x_range;
    double a = v_stats_2D[c_STAT_2D_LINEAR_FIT_SLOPE];
    double b = v_stats_2D[c_STAT_2D_LINEAR_FIT_Y_AXIS_SECTION];
    series_fit->append(x1, a * x1 + b);
    series_fit->append(x2, a * x2 + b);

    //Attach
    chart->addSeries(series);
    series->attachAxis(x_axis);
    series->attachAxis(y_axis);
    series->setUseOpenGL(false);
    pChartView->setChart(chart);

    //stuff to do at end of series
    chart->addSeries(series_fit);
    series_fit->attachAxis(x_axis);
    series_fit->attachAxis(y_axis);

    if((*vvv_ParSetVal)[par_x][set].size() != (*vvv_ParSetVal)[par_y][set].size())  return ER_size_missmatch;
    return ER_okay;*/
}

int D_Plot::Plot_Scatter_2D_Parameter(QChartView *pChartView, vector<vector<double> > *vv_ParVal, unsigned int par_x, unsigned int par_y, QString name_title, QString name_series, QString name_x, QString name_y)
{
    //this method only exists to make older code work
    //use general scatter plot instead
    return Plot_Scatter_2D_Single_Y(
                pChartView,
                &((*vv_ParVal)[par_x]),
                &((*vv_ParVal)[par_y]),
                name_title,
                name_series,
                name_x,
                name_y);

    /*
    //clear old content
    Free_Memory(pChartView);

    //Chart
    //qDebug() << "==================================Chart";
    QChart *chart = new QChart();
    chart->setTitle(name_title);

    //Range (only x - needed for fit display)
    double x_min = (*vv_ParVal)[par_x][0];
    double x_max = (*vv_ParVal)[par_x][0];
    for(int ix = 0; ix < (*vv_ParVal)[par_x].size(); ix++)
    {
        double x = (*vv_ParVal)[par_x][ix];
        if(x < x_min)   x_min = x;
        if(x > x_max)   x_max = x;
    }

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    chart->setAxisX(x_axis);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    chart->setAxisY(y_axis);

    //2D Stats
    vector<double> v_stats_2D;
    int ER = D_Stat::Calc_Stats_2D(
                &v_stats_2D,
                (*vv_ParVal)[par_x],
                (*vv_ParVal)[par_y]);
    if(ER != ER_okay)
        return ER;

    //Series
    //qDebug() << "Series";
    QScatterSeries *series  = new QScatterSeries();
    series->setName(name_series);
    series->setUseOpenGL(true);
    series->setMarkerSize(8);


    //Data
    //qDebug() << "Data";
    for(int v = 0; (v < (*vv_ParVal)[par_x].size()) && (v < (*vv_ParVal)[par_y].size()); v++)
        series->append(
                    (*vv_ParVal)[par_x][v],
                    (*vv_ParVal)[par_y][v]);

    //Fit-Series
    QLineSeries *series_fit = new QLineSeries;
    series_fit->setName(
                "f(x)=" + QString::number(v_stats_2D[c_STAT_2D_LINEAR_FIT_SLOPE], 'g', 3) + "x+" + QString::number(v_stats_2D[c_STAT_2D_LINEAR_FIT_Y_AXIS_SECTION], 'g', 3) +
                "<br>R²: " + QString::number(v_stats_2D[c_STAT_2D_R_SQUARE_SAMPLE], 'g', 3));
    series_fit->setColor(series->color());

    //Fit data
    double x_range = x_max - x_min;
    double x1 = x_min - 10 * x_range;
    double x2 = x_max + 10 * x_range;
    double a = v_stats_2D[c_STAT_2D_LINEAR_FIT_SLOPE];
    double b = v_stats_2D[c_STAT_2D_LINEAR_FIT_Y_AXIS_SECTION];
    series_fit->append(x1, a * x1 + b);
    series_fit->append(x2, a * x2 + b);

    //Attach
    chart->addSeries(series);
    series->attachAxis(x_axis);
    series->attachAxis(y_axis);
    series->setUseOpenGL(false);
    pChartView->setChart(chart);

    //stuff to do at end of series
    chart->addSeries(series_fit);
    series_fit->attachAxis(x_axis);
    series_fit->attachAxis(y_axis);

    if((*vv_ParVal)[par_x].size() != (*vv_ParVal)[par_y].size())  return ER_size_missmatch;
    return ER_okay;
    */
}

int D_Plot::Plot_Scatter_2D_Single_Y(QChartView *pChartView, vector<double> v_X_Val, vector<double> v_Y_Val, QString name_title, QString name_series, QString name_x, QString name_y, bool man_axis_style_x, bool man_axis_style_y, double man_min_x, double man_max_x, double man_min_y, double man_max_y, int ticks_x, int ticks_y)
{
    return Plot_Scatter_2D_Single_Y(
                pChartView,
                &v_X_Val,
                &v_Y_Val,
                name_title,
                name_series,
                name_x,
                name_y,
                man_axis_style_x,
                man_axis_style_y,
                man_min_x,
                man_max_x,
                man_min_y,
                man_max_y,
                ticks_x,
                ticks_y);
}

int D_Plot::Plot_Scatter_2D_Single_Y(QChartView *pChartView, vector<double> *v_X_Val, vector<double> *v_Y_Val, QString name_title, QString name_series, QString name_x, QString name_y, bool man_axis_style_x, bool man_axis_style_y, double man_min_x, double man_max_x, double man_min_y, double man_max_y, int ticks_x, int ticks_y)
{
    if(v_X_Val->empty())                        return ER_empty;
    if(v_Y_Val->empty())                        return ER_empty;
    if(v_X_Val->size() != v_Y_Val->size())      return ER_size_missmatch;

    //clear old content
    Free_Memory(pChartView);

    //Chart
    //qDebug() << "==================================Chart";
    QChart *chart = new QChart();
    chart->setTitle(name_title + "<br>n=" + QString::number(v_X_Val->size()));

    //Range (only x - needed for fit display)
    double x_min = (*v_X_Val)[0];
    double x_max = (*v_X_Val)[0];
    for(size_t ix = 0; ix < v_X_Val->size(); ix++)
    {
        double x = (*v_X_Val)[ix];
        if(x < x_min)   x_min = x;
        if(x > x_max)   x_max = x;
    }


    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    x_axis->setTickCount(man_axis_style_x ? ticks_x : AXE_TICK_COUNT_MAJOR_DEFAULT);
    if(man_axis_style_x)
        x_axis->setRange(man_min_x, man_max_x);
    chart->setAxisX(x_axis);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    y_axis->setTickCount(man_axis_style_y ? ticks_y : AXE_TICK_COUNT_MAJOR_DEFAULT);
    if(man_axis_style_y)
        y_axis->setRange(man_min_y, man_max_y);
    chart->setAxisY(y_axis);

    //2D Stats
    vector<double> v_stats_2D;
    int ER = D_Stat::Calc_Stats_2D(
                &v_stats_2D,
                *v_X_Val,
                *v_Y_Val);
    if(ER != ER_okay)
        return ER;

    //Series
    //qDebug() << "Series";
    QScatterSeries *series = new QScatterSeries;
    series->setName(name_series);
    series->setUseOpenGL(true);
    series->setMarkerSize(6);

    //data
    for(size_t x = 0; x < v_X_Val->size(); x++)
        series->append(
                    (*v_X_Val)[x],
                    (*v_Y_Val)[x]);

    //stuff to do at end of series
    chart->addSeries(series);
    series->attachAxis(x_axis);
    series->attachAxis(y_axis);
    series->setUseOpenGL(false);

    //Fit-Series
    QLineSeries *series_fit = new QLineSeries;
    series_fit->setName(
                "f(x)=" + QString::number(v_stats_2D[c_STAT_2D_LINEAR_FIT_SLOPE], 'g', 3) + "x+" + QString::number(v_stats_2D[c_STAT_2D_LINEAR_FIT_Y_AXIS_SECTION], 'g', 3) +
                "<br>R²: " + QString::number(v_stats_2D[c_STAT_2D_R_SQUARE_SAMPLE], 'g', 3));
    series_fit->setColor(series->color());

    //Fit data
    double x_range = x_max - x_min;
    double x1 = x_min - 10 * x_range;
    double x2 = x_max + 10 * x_range;
    double a = v_stats_2D[c_STAT_2D_LINEAR_FIT_SLOPE];
    double b = v_stats_2D[c_STAT_2D_LINEAR_FIT_Y_AXIS_SECTION];
    series_fit->append(x1, a * x1 + b);
    series_fit->append(x2, a * x2 + b);

    //stuff to do at end of series
    chart->addSeries(series_fit);
    series_fit->attachAxis(x_axis);
    series_fit->attachAxis(y_axis);


    //attach
    //qDebug() << "attach";
    pChartView->setChart(chart);

    return ER_okay;
}

int D_Plot::Plot_Scatter_2D_Multi_Y(QChartView *pChartView, vector<double> *v_X_Val, vector<vector<double> > *vv_Y_SerVal, QString name_title, QString name_series, QString name_x, QString name_y)
{
    QStringList QSL_name_series;
    for(size_t s = 0; s < vv_Y_SerVal->size(); s++)
        QSL_name_series.append(name_series + QString::number(s));

    return Plot_Scatter_2D_Multi_Y(
                pChartView,
                v_X_Val,
                vv_Y_SerVal,
                name_title,
                QSL_name_series,
                name_x,
                name_y);
}

int D_Plot::Plot_Scatter_2D_Multi_Y(QChartView *pChartView, vector<double> *v_X_Val, vector<vector<double> > *vv_Y_SerVal, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y)
{
    if(v_X_Val->empty())                                                        return ER_empty;
    if(vv_Y_SerVal->empty())                                                    return ER_empty;
    if((*vv_Y_SerVal)[0].empty())                                               return ER_empty;
    if(static_cast<size_t>(qsl_name_series.size()) != vv_Y_SerVal->size())      return ER_size_missmatch;

    //clear old content
    Free_Memory(pChartView);

    //Chart
    //qDebug() << "==================================Chart";
    QChart *chart = new QChart();
    chart->setTitle(name_title + "<br>n=" + QString::number(v_X_Val->size()));

    //min/max & size check
    //qDebug() << "min/max";
    double x_min = (*v_X_Val)[0];
    double x_max = (*v_X_Val)[0];
    double y_min = (*vv_Y_SerVal)[0][0];
    double y_max = (*vv_Y_SerVal)[0][0];

    for(size_t xi = 0; xi < v_X_Val->size(); xi++)
    {
        double x = (*v_X_Val)[xi];
        if(x < x_min)   x_min = x;
        if(x > x_max)   x_max = x;
    }

    for(size_t s = 0; s < vv_Y_SerVal->size(); s++)
    {
        //qDebug() << "Series" << s << "x-size" << v_X_Val->size() << "y-size" << (*vv_Y_SerVal)[s].size();
        if(v_X_Val->size() != (*vv_Y_SerVal)[s].size())  return ER_size_missmatch;

        for(size_t xi = 0; xi < (*vv_Y_SerVal)[s].size(); xi++)
        {
            //cehck min/max y
            double y = (*vv_Y_SerVal)[s][xi];
            if(y < y_min)   y_min = y;
            if(y > y_max)   y_max = y;
        }
    }

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    x_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisX(x_axis);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisY(y_axis);
    y_axis->setMin(y_min);
    y_axis->setMax(y_max);

    //2D Stats
    vector<vector<double>> vv_stats_2D(vv_Y_SerVal->size());
    int ER;
    for(size_t s = 0; s < vv_Y_SerVal->size(); s++)
    {
        ER = D_Stat::Calc_Stats_2D(
                    &(vv_stats_2D[s]),
                    *v_X_Val,
                    (*vv_Y_SerVal)[s]);
        if(ER != ER_okay)
            return ER;
    }

    //Series
    //qDebug() << "Series";
    vector<QScatterSeries*> v_series;
    v_series.resize(vv_Y_SerVal->size());

    for(size_t s = 0; s < vv_Y_SerVal->size(); s++)
    {
        //qDebug() << "series" << s;

        //name
        v_series[s] = new QScatterSeries;
        v_series[s]->setName(qsl_name_series[static_cast<int>(s)]);
        v_series[s]->setUseOpenGL(true);
        v_series[s]->setMarkerSize(6);

        //data
        for(size_t x = 0; x < (*vv_Y_SerVal)[s].size(); x++)
            v_series[s]->append(
                        (*v_X_Val)[x],
                        (*vv_Y_SerVal)[s][x]);

        //stuff to do at end of series
        chart->addSeries(v_series[s]);
        v_series[s]->attachAxis(x_axis);
        v_series[s]->attachAxis(y_axis);
        v_series[s]->setUseOpenGL(false);
    }

    //Fit-Series
    vector<QLineSeries*> v_series_fit(vv_Y_SerVal->size());
    for(size_t s = 0; s < vv_Y_SerVal->size(); s++)
    {
        //linear fit equation
        double a = vv_stats_2D[s][c_STAT_2D_LINEAR_FIT_SLOPE];
        double b = vv_stats_2D[s][c_STAT_2D_LINEAR_FIT_Y_AXIS_SECTION];

        //name
        v_series_fit[s] = new QLineSeries;
        v_series_fit[s]->setName(
                    "f(x)=" + QString::number(a, 'g', 3) + "x+" + QString::number(b, 'g', 3) +
                    "<br>R²: " + QString::number(vv_stats_2D[s][c_STAT_2D_R_SQUARE_SAMPLE], 'g', 3));
        v_series_fit[s]->setColor(v_series[s]->color());

        //data
        double x_range = x_max - x_min;
        double x1 = x_min - 10 * x_range;
        double x2 = x_max + 10 * x_range;
        v_series_fit[s]->append(x1, a * x1 + b);
        v_series_fit[s]->append(x2, a * x2 + b);

        //stuff to do at end of series
        chart->addSeries(v_series_fit[s]);
        v_series_fit[s]->attachAxis(x_axis);
        v_series_fit[s]->attachAxis(y_axis);
    }

    //attach
    //qDebug() << "attach";
    pChartView->setChart(chart);

    return ER_okay;
}

int D_Plot::Plot_Scatter_2D_Multi_XY(QChartView *pChartView, vector<vector<double> > *vv_X_SerVal, vector<vector<double> > *vv_Y_SerVal, QString name_title, QString name_series, QString name_x, QString name_y)
{
    QStringList QSL_name_series;
    for(size_t s = 0; s < vv_Y_SerVal->size(); s++)
        QSL_name_series.append(name_series + QString::number(s));

    return Plot_Scatter_2D_Multi_XY(
                pChartView,
                vv_X_SerVal,
                vv_Y_SerVal,
                name_title,
                QSL_name_series,
                name_x,
                name_y);
}

int D_Plot::Plot_Scatter_2D_Multi_XY(QChartView *pChartView, vector<vector<double> > *vv_X_SerVal, vector<vector<double> > *vv_Y_SerVal, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y)
{
    if(vv_X_SerVal->empty())                                                return ER_empty;
    if(vv_Y_SerVal->empty())                                                return ER_empty;
    if((*vv_Y_SerVal)[0].empty())                                           return ER_empty;
    if((*vv_X_SerVal)[0].empty())                                           return ER_empty;
    if(vv_X_SerVal->size() != vv_Y_SerVal->size())                          return ER_size_missmatch;
    if(static_cast<size_t>(qsl_name_series.size()) != vv_X_SerVal->size())  return ER_size_missmatch;

    //clear old content
    Free_Memory(pChartView);

    //Chart
    //qDebug() << "==================================Chart";
    QChart *chart = new QChart();
    chart->setTitle(name_title);

    //min/max & size check
    //qDebug() << "min/max";
    double x_min = (*vv_X_SerVal)[0][0];
    double x_max = (*vv_X_SerVal)[0][0];
    double y_min = (*vv_Y_SerVal)[0][0];
    double y_max = (*vv_Y_SerVal)[0][0];
    for(size_t s = 0; s < vv_Y_SerVal->size(); s++)
    {
        if((*vv_X_SerVal)[s].size() != (*vv_Y_SerVal)[s].size())  return ER_size_missmatch;

        for(size_t i = 0; i < (*vv_X_SerVal)[s].size(); i++)
        {
            //cehck min/max x
            double x = (*vv_X_SerVal)[s][i];
            if(x < x_min)   x_min = x;
            if(x > x_max)   x_max = x;

            //cehck min/max y
            double y = (*vv_Y_SerVal)[s][i];
            if(y < y_min)   y_min = y;
            if(y > y_max)   y_max = y;
        }
    }

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    x_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisX(x_axis);
    x_axis->setMin(x_min);
    x_axis->setMax(x_max);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisY(y_axis);
    y_axis->setMin(y_min);
    y_axis->setMax(y_max);

    //2D Stats
    vector<vector<double>> vv_stats_2D(vv_X_SerVal->size());
    int ER;
    for(size_t s = 0; s < vv_X_SerVal->size(); s++)
    {
        ER = D_Stat::Calc_Stats_2D(
                    &(vv_stats_2D[s]),
                    (*vv_X_SerVal)[s],
                    (*vv_Y_SerVal)[s]);
        if(ER != ER_okay)
            return ER;
    }

    //Series
    //qDebug() << "Series";
    vector<QScatterSeries*> v_series;
    v_series.resize(vv_X_SerVal->size());

    for(size_t s = 0; s < vv_X_SerVal->size(); s++)
    {
        //qDebug() << "series" << s;

        //name
        v_series[s] = new QScatterSeries;
        v_series[s]->setName(qsl_name_series[static_cast<int>(s)] + "<br>R²: " + QString::number(vv_stats_2D[s][c_STAT_2D_R_SQUARE_SAMPLE], 'g', 3));
        v_series[s]->setUseOpenGL(true);
        v_series[s]->setMarkerSize(6);

        //data
        for(size_t i = 0; i < (*vv_Y_SerVal)[s].size(); i++)
            v_series[s]->append(
                        (*vv_X_SerVal)[s][i],
                        (*vv_Y_SerVal)[s][i]);

        //stuff to do at end of series
        chart->addSeries(v_series[s]);
        v_series[s]->attachAxis(x_axis);
        v_series[s]->attachAxis(y_axis);
        //v_series[s]->setUseOpenGL(false);
    }

    //Fit-Series
    vector<QLineSeries*> v_series_fit(vv_X_SerVal->size());
    for(size_t s = 0; s < vv_Y_SerVal->size(); s++)
    {
        //linear fit equation
        double a = vv_stats_2D[s][c_STAT_2D_LINEAR_FIT_SLOPE];
        double b = vv_stats_2D[s][c_STAT_2D_LINEAR_FIT_Y_AXIS_SECTION];

        //name
        v_series_fit[s] = new QLineSeries;
        v_series_fit[s]->setName(
                    "f(x)=" + QString::number(a, 'g', 3) + "x+" + QString::number(b, 'g', 3) +
                    "<br>R²: " + QString::number(vv_stats_2D[s][c_STAT_2D_R_SQUARE_SAMPLE], 'g', 3));
        v_series_fit[s]->setColor(v_series[s]->color());

        //data
        double x_range = x_max - x_min;
        double x1 = x_min - 10 * x_range;
        double x2 = x_max + 10 * x_range;
        v_series_fit[s]->append(x1, a * x1 + b);
        v_series_fit[s]->append(x2, a * x2 + b);

        //stuff to do at end of series
        chart->addSeries(v_series_fit[s]);
        v_series_fit[s]->attachAxis(x_axis);
        v_series_fit[s]->attachAxis(y_axis);
    }

    //attach
    //qDebug() << "attach";
    pChartView->setChart(chart);

    for(size_t s = 0; s < v_series.size(); s++)
        v_series[s]->setUseOpenGL(false);

    return ER_okay;
}

int D_Plot::Plot_Scatter_Heatmap(QChartView *pChartView, vector<double> vData_X, double min_x, double step_x, bool auto_range_x, size_t classes_x, QString name_x, vector<double> vData_Y, double min_y, double step_y, bool auto_range_y, size_t classes_y, QString name_y, vector<double> vData_Z, size_t stat_z, QString name_z, QString name_title, bool man_axis_style_x, bool man_axis_style_y, double man_min_x, double man_max_x, double man_min_y, double man_max_y, int ticks_x, int ticks_y)
{
    //---------------------------------------------------------- errors

    //errors
    if(vData_X.empty())                             return ER_empty;
    if(vData_Y.empty())                             return ER_empty;
    if(vData_Z.empty())                             return ER_empty;
    if(vData_X.size() != vData_Y.size())            return ER_size_missmatch;
    if(vData_X.size() != vData_Z.size())            return ER_size_missmatch;
    if(step_x <= 0)                                 return ER_parameter_bad;
    if(step_y <= 0)                                 return ER_parameter_bad;
    if(classes_x <= 1)                              return ER_parameter_bad;
    if(classes_y <= 1)                              return ER_parameter_bad;
    if(stat_z >= c_STAT_NUMBER_OF_STATS)            return ER_index_out_of_range;


    //---------------------------------------------------------- size and scale

    //sizes
    size_t n_data = vData_X.size();
    size_t n_x = classes_x;
    size_t n_y = classes_y;
    //qDebug() << "size data/x/y" << n_data << n_x << n_y;

    double range_x = step_x * classes_x;
    double range_y = step_y * classes_y;
    double max_x = min_x + range_x;
    double max_y = min_y + range_y;

    //calc min/max x/y
    if(auto_range_x)
    {
        min_x = INFINITY;
        max_x = -INFINITY;
        for(size_t i = 0; i < n_data; i++)
        {
            double val = vData_X[i];
            if(val < min_x)     min_x = val;
            if(val > max_x)     max_x = val;
        }

        range_x = max_x - min_x;
        step_x = range_x / classes_x;
        if(range_x <= 0)
            return ER_size_bad;
    }

    if(auto_range_y)
    {
        min_y = INFINITY;
        max_y = -INFINITY;
        for(size_t i = 0; i < n_data; i++)
        {
            double val = vData_Y[i];
            if(val < min_y)     min_y = val;
            if(val > max_y)     max_y = val;
        }

        range_y = max_y - min_y;
        step_y = range_y / classes_y;
        if(range_y <= 0)
            return ER_size_bad;
    }

    //---------------------------------------------------------- data calculation

    //3D stacked data field
    vector<vector<vector<double>>> vvvData_XYI(n_x, vector<vector<double>>(n_y, vector<double>(0)));

    //pooling
    for(size_t i = 0; i < n_data; i++)
    {
        size_t i_x = D_Stat::Value2PoolIndex(vData_X[i], min_x, range_x, n_x);
        size_t i_y = D_Stat::Value2PoolIndex(vData_Y[i], min_y, range_y, n_y);
        double val = vData_Z[i];

        vvvData_XYI[i_x][i_y].push_back(val);
    }

    //2D data field result
    Mat MA_tmp_value = Mat::zeros(n_y, n_x, CV_64FC1);

    //min/max
    double val_min = INFINITY;
    double val_max = -INFINITY;

    //calc stat
    function<double (vector<double>)> F_Stat = D_Stat::Function_SingleStat(int(stat_z));
    for(size_t x = 0; x < n_x; x++)
        for(size_t y = 0; y < n_y; y++)
            if(!vvvData_XYI[x][y].empty())
            {
                //qDebug() << "x/y/val" << y << x << F_Stat(vvvData_XYI[x][y]);
                double val = F_Stat(vvvData_XYI[x][y]);
                MA_tmp_value.at<double>(y, x) = val;

                if(val < val_min)
                    val_min = val;

                if(val > val_max)
                    val_max = val;
            }


    //---------------------------------------------------------- texture heatmap

    //texture img
    QImage QI_tmp_texture;

    //calc texture as color heatmap
    Mat MA_tmp_useless_alpha_img = Mat::zeros(MA_tmp_value.size(), CV_8UC1);
    int err = D_Img_Proc::Convert_toQImage4Ch(
                &QI_tmp_texture,
                &MA_tmp_value,
                &MA_tmp_useless_alpha_img,
                true);
    MA_tmp_useless_alpha_img.release();
    if(err != ER_okay)
    {
        MA_tmp_value.release();
        return err;
    }

    //pixels with no data to white
    for(size_t x = 0; x < n_x; x++)
        for(size_t y = 0; y < n_y; y++)
            if(vvvData_XYI[x][y].empty())
                QI_tmp_texture.setPixel(int(x), int(y), Qt::white);

    //range and colors
    double val_range    = val_max - val_min;
    double val_step     = val_range / 4.0;
    double val_red      = val_max;
    double val_yellow   = val_red       - val_step;
    double val_green    = val_yellow    - val_step;
    double val_cyan     = val_green     - val_step;
    double val_blue     = val_cyan      - val_step;

    //---------------------------------------------------------- basic plot stuff

    //clear old content
    Free_Memory(pChartView);

    //Chart
    QChart *chart = new QChart();
    chart->setTitle("<b>" + name_title + "</b>"
                    "<br>" + "Color: " + QSL_StatList[int(stat_z)] + " of " + name_z +
                    "<br>Color legend: "
                    "<span style= \"color:#0000ff;\">" + QString::number(val_blue,   'g', 4) + "</span>, "
                    "<span style= \"color:#00ffff;\">" + QString::number(val_cyan,   'g', 4) + "</span>, "
                    "<span style= \"color:#00ff00;\">" + QString::number(val_green,  'g', 4) + "</span>, "
                    "<span style= \"color:#ffff00;\">" + QString::number(val_yellow, 'g', 4) + "</span>, "
                    "<span style= \"color:#ff0000;\">" + QString::number(val_red,    'g', 4) + "</span>"
                    "<br>n=" + QString::number(vData_X.size()));

    //---------------------------------------------------------- axis

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    x_axis->setTickCount(man_axis_style_x ? ticks_x : AXE_TICK_COUNT_MAJOR_DEFAULT);
    x_axis->setMin(man_axis_style_x ? man_min_x : min_x);
    x_axis->setMax(man_axis_style_x ? man_max_x : max_x);
    chart->setAxisX(x_axis);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    y_axis->setTickCount(man_axis_style_y ? ticks_y : AXE_TICK_COUNT_MAJOR_DEFAULT);
    y_axis->setMin(man_axis_style_y ? man_min_y : min_y);
    y_axis->setMax(man_axis_style_y ? man_max_y : max_y);
    //y_axis->setReverse(true);
    chart->setAxisY(y_axis);

    //---------------------------------------------------------- data

    vector<QScatterSeries*> vSeries;

    for(size_t x = 0; x < n_x; x++)
        for(size_t y = 0; y < n_y; y++)
            if(!vvvData_XYI[x][y].empty())
            {
                //calc position
                double x_rel = double(x) / double(n_x);
                double y_rel = double(y) / double(n_y);
                double x_pos = x_rel * range_x + min_x;
                double y_pos = y_rel * range_y + min_y;

                //create series
                vSeries.push_back(new QScatterSeries);
                size_t i = vSeries.size() - 1;

                //set attribs and coords
                vSeries[i]->setColor(QI_tmp_texture.pixelColor(x, y));
                vSeries[i]->setBorderColor(vSeries[i]->color());
                vSeries[i]->setMarkerShape(QScatterSeries::MarkerShapeRectangle);
                vSeries[i]->append(x_pos, y_pos);

                //attach
                chart->addSeries(vSeries[i]);
                vSeries[i]->attachAxis(x_axis);
                vSeries[i]->attachAxis(y_axis);
            }


    /*
    QLineSeries* series = new QLineSeries;
    series->setColor(Qt::black);

    series->append(min_x, min_y);
    series->append(min_x, max_y);
    series->append(max_x, max_y);
    series->append(max_x, min_y);
    series->append(min_x, min_y);

    chart->addSeries(series);
    series->attachAxis(x_axis);
    series->attachAxis(y_axis);
    */

    //---------------------------------------------------------- show

    pChartView->setChart(chart);
    pChartView->chart()->legend()->setVisible(false);

    //---------------------------------------------------------- set heatmap as background image

    /*
    //this section is inspired by: https://forum.qt.io/topic/108046/qchart-background-image

    //Grab the size of the plot and view areas
    int w_pa = static_cast<int>(chart->plotArea().width());
    int h_pa = static_cast<int>(chart->plotArea().height());
    int w_cv = static_cast<int>(pChartView->width());
    int h_cv = static_cast<int>(pChartView->height());

    //scale the image to fit plot area
    QI_tmp_texture = QI_tmp_texture.scaled(QSize(w_pa, h_pa));

    //We have to translate the image because setPlotAreaBackGround
    //starts the image in the top left corner of the view not the
    //plot area. So, to offset we will make a new image the size of
    //view and offset our image within that image with white
    QImage QI_tmp_padded(w_cv, h_cv, QI_tmp_texture.format());
    QI_tmp_padded.fill(Qt::white);
    QPainter painter(&QI_tmp_padded);
    QPointF P_tl = chart->plotArea().topLeft();
    painter.drawImage(P_tl, QI_tmp_texture);

    //Display image in background
    chart->setPlotAreaBackgroundBrush(QI_tmp_padded);
    chart->setPlotAreaBackgroundVisible(true);
    */

    //---------------------------------------------------------- scale markers

    double marker_w = chart->plotArea().width()  / double(n_x);
    double marker_h = chart->plotArea().height() / double(n_y);
    double marker_s = max(marker_w, marker_h);

    for(size_t i = 0; i < vSeries.size(); i++)
        vSeries[i]->setMarkerSize(marker_s);

    //---------------------------------------------------------- end

    MA_tmp_value.release();
    return ER_okay;
}

int D_Plot::Plot_Poincare_XY_Single(QChartView *pChartView, vector<double> v_Data, QString name_title, QString name_series, QString name_x, QString name_y, size_t shift_elements, bool show_dots, bool show_ellipse, bool show_line_YequalX, Qt::Alignment legend_pos)
{
    if(v_Data.empty())                      return ER_empty;
    if(v_Data.size() <= shift_elements)     return ER_size_bad;

    //clear old content
    Free_Memory(pChartView);

    //Chart
    //qDebug() << "==================================Chart";
    QChart *chart = new QChart();
    chart->setTitle(name_title + "<br>n=" + QString::number(v_Data.size()));

    //Range (only x - needed for fit display)
    double min = v_Data[0];
    double max = v_Data[0];
    for(size_t ix = 0; ix < v_Data.size(); ix++)
    {
        double val = v_Data[ix];
        if(val < min) min = val;
        if(val > max) max = val;
    }

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    x_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    x_axis->setRange(min, max);
    chart->setAxisX(x_axis);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    y_axis->setRange(min, max);
    chart->setAxisY(y_axis);

    /*
    //2D Stats
    vector<double> v_stats_2D;
    int ER = D_Stat::Calc_Stats_2D(
                &v_stats_2D,
                *v_X_Val,
                *v_Y_Val);
    if(ER != ER_okay)
        return ER;
    */

    if(show_line_YequalX)
    {
        QLineSeries *series_YisX = new QLineSeries;
        series_YisX->setName("Y=X");

        //data
        double range = max - min;
        series_YisX->append(min - 1000 * range, min - 1000 * range);
        series_YisX->append(max + 1000 * range, max + 1000 * range);

        //cosmetic
        QPen pen = series_YisX->pen();
        pen.setWidth(1);
        pen.setColor(Qt::gray);
        series_YisX->setPen(pen);

        //stuff to do at end of series
        chart->addSeries(series_YisX);
        series_YisX->attachAxis(x_axis);
        series_YisX->attachAxis(y_axis);
    }

    //Series
    //qDebug() << "Series";
    if(show_dots)
    {
        QScatterSeries *series = new QScatterSeries;
        series->setName(name_series);
        series->setUseOpenGL(true);
        series->setMarkerSize(3);
        series->setColor(Qt::green);
        series->setBorderColor(Qt::black);

        //data
        for(size_t i = shift_elements; i < v_Data.size(); i++)
            series->append(
                        v_Data[i - shift_elements],
                        v_Data[i]);

        //stuff to do at end of series
        chart->addSeries(series);
        series->attachAxis(x_axis);
        series->attachAxis(y_axis);
        series->setUseOpenGL(false);
    }

    if(show_ellipse)
    {
        /*
        //Fit-Series
        QLineSeries *series_fit = new QLineSeries;
        series_fit->setName(
                    "f(x)=" + QString::number(v_stats_2D[c_STAT_2D_LINEAR_FIT_SLOPE], 'g', 3) + "x+" + QString::number(v_stats_2D[c_STAT_2D_LINEAR_FIT_Y_AXIS_SECTION], 'g', 3) +
                    "<br>R²: " + QString::number(v_stats_2D[c_STAT_2D_R_SQUARE_SAMPLE], 'g', 3));
        series_fit->setColor(series->color());

        //Fit data
        double x_range = x_max - x_min;
        double x1 = x_min - 10 * x_range;
        double x2 = x_max + 10 * x_range;
        double a = v_stats_2D[c_STAT_2D_LINEAR_FIT_SLOPE];
        double b = v_stats_2D[c_STAT_2D_LINEAR_FIT_Y_AXIS_SECTION];
        series_fit->append(x1, a * x1 + b);
        series_fit->append(x2, a * x2 + b);

        //stuff to do at end of series
        chart->addSeries(series_fit);
        series_fit->attachAxis(x_axis);
        series_fit->attachAxis(y_axis);
        */
    }




    //attach
    //qDebug() << "attach";
    pChartView->chart()->legend()->setAlignment(legend_pos);
    pChartView->setChart(chart);

    return ER_okay;
}


int D_Plot::Plot_Line_XY_Multi(QChartView *pChartView, vector<vector<double> > vv_XY_Data, QString name_title, QString name_series, QString name_x, QString name_y, int x_trans, int y_trans, bool dots_visible, bool heat_color, bool heat_color_AllColors, Qt::Alignment legend_pos)
{
    QStringList QSL_name_series;
    for(size_t s = 0; s < vv_XY_Data.size(); s++)
        QSL_name_series.append(name_series + QString::number(s));

    return Plot_Line_XY_Multi(
                pChartView,
                vv_XY_Data,
                name_title,
                QSL_name_series,
                name_x,
                name_y,
                x_trans,
                y_trans,
                dots_visible,
                heat_color,
                legend_pos);
}

int D_Plot::Plot_Line_XY_Multi(QChartView *pChartView, vector<vector<double> > vv_XY_Data, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y, int x_trans, int y_trans, bool dots_visible, bool heat_color, bool heat_color_AllColors, Qt::Alignment legend_pos)
{
    if(vv_XY_Data.empty())                                                  return ER_empty;
    if(vv_XY_Data[0].empty())                                               return ER_empty;
    if(vv_XY_Data.size() != static_cast<size_t>(qsl_name_series.size()))    return ER_size_missmatch;

    //clear old content
    Free_Memory(pChartView);

    //Chart
    QChart *chart = new QChart();
    chart->setTitle(name_title);

    double x_min, x_max, y_min, y_max;
    D_Stat::Calc_MinMax(
                vv_XY_Data,
                &x_min,
                &x_max,
                &y_min,
                &y_max,
                x_trans,
                y_trans);

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(QSL_AxeTrans_Prefix[x_trans] + name_x + QSL_AxeTrans_Suffix[x_trans]);
    x_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisX(x_axis);
    x_axis->setMin(x_min);
    x_axis->setMax(x_max);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(QSL_AxeTrans_Prefix[y_trans] + name_y + QSL_AxeTrans_Suffix[y_trans]);
    y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisY(y_axis);
    y_axis->setMin(y_min);
    y_axis->setMax(y_max);

    //Series
    //qDebug() << "Series";
    vector<QLineSeries*> v_series;
    v_series.resize(vv_XY_Data.size());

    for(size_t s = 0; s < vv_XY_Data.size(); s++)
    {
        //qDebug() << "series" << s;

        //name
        v_series[s] = new QLineSeries;
        v_series[s]->setName(qsl_name_series[static_cast<int>(s)]);
        v_series[s]->setPointsVisible(dots_visible);
        //v_series[s]->setUseOpenGL(true);
        if(heat_color)
        {
            double series_pos_rel = s / static_cast<double>(v_series.size() - 1);
            QColor series_color;

            if(heat_color_AllColors)
            {
                series_color.setHsv(
                            static_cast<uchar>(255 * series_pos_rel),
                            255,
                            255);
            }
            else
            {
                series_color.setRgb(
                            static_cast<uchar>(255 * series_pos_rel),
                            0,
                            static_cast<uchar>(255 * (1.0 - series_pos_rel)));
            }

            v_series[s]->setColor(series_color);
        }

        //data
        for(size_t x = 0; x < vv_XY_Data[s].size(); x++)
            v_series[s]->append(
                        D_Stat::AxeTrans(x,                 x_trans),
                        D_Stat::AxeTrans(vv_XY_Data[s][x],  y_trans));

        //stuff to do at end of series
        chart->addSeries(v_series[s]);
        v_series[s]->attachAxis(x_axis);
        v_series[s]->attachAxis(y_axis);
        //v_series[s]->setUseOpenGL(false);
    }

    //cosmetic
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(legend_pos);

    //attach
    //qDebug() << "attach";
    pChartView->setChart(chart);

    return ER_okay;
}

int D_Plot::Plot_Line_XY_Multi(QChartView *pChartView, vector<double> v_X_Data, vector<vector<double> > vv_Y_Data, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y, bool dots_visible, bool heat_color, bool heat_color_AllColors, Qt::Alignment legend_pos)
{
    vector<vector<double>> vv_X_Data(vv_Y_Data.size());
    for(size_t s = 0; s < vv_Y_Data.size(); s++)
    {
        //check
        if(v_X_Data.size() != vv_Y_Data[s].size())
            return ER_size_missmatch;

        //copy to be able to recycle function
        vv_X_Data[s].resize(vv_Y_Data[s].size());
        for(size_t ix = 0; ix < vv_Y_Data[s].size(); ix++)
            vv_X_Data[s][ix] = v_X_Data[ix];
    }

    return Plot_Line_XY_Multi(
                pChartView,
                vv_X_Data,
                vv_Y_Data,
                name_title,
                qsl_name_series,
                name_x,
                name_y,
                dots_visible,
                heat_color,
                heat_color_AllColors,
                legend_pos);
}

int D_Plot::Plot_Line_XY_Multi(QChartView *pChartView, vector<vector<double>> vv_X_Data, vector<vector<double>> vv_Y_Data, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y, bool dots_visible, bool heat_color, bool heat_color_AllColors, Qt::Alignment legend_pos)
{
    if(vv_X_Data.empty())                                                   return ER_empty;
    if(vv_Y_Data.empty())                                                   return ER_empty;
    if(vv_Y_Data[0].empty())                                                return ER_empty;
    if((vv_X_Data)[0].empty())                                              return ER_empty;
    if(vv_X_Data.size() != vv_Y_Data.size())                                return ER_size_missmatch;
    if(static_cast<size_t>(qsl_name_series.size()) != vv_X_Data.size())     return ER_size_missmatch;

    //clear old content
    Free_Memory(pChartView);

    //Chart
    //qDebug() << "==================================Chart";
    QChart *chart = new QChart();
    chart->setTitle(name_title);

    //min/max & size check
    //qDebug() << "min/max";
    double x_min = vv_X_Data[0][0];
    double x_max = vv_X_Data[0][0];
    double y_min = vv_Y_Data[0][0];
    double y_max = vv_Y_Data[0][0];
    for(size_t s = 0; s < vv_Y_Data.size(); s++)
    {
        if(vv_X_Data[s].size() != vv_Y_Data[s].size())  return ER_size_missmatch;

        for(size_t i = 0; i < vv_X_Data[s].size(); i++)
        {
            //cehck min/max x
            double x = vv_X_Data[s][i];
            if(x < x_min)   x_min = x;
            if(x > x_max)   x_max = x;

            //cehck min/max y
            double y = vv_Y_Data[s][i];
            if(y < y_min)   y_min = y;
            if(y > y_max)   y_max = y;
        }
    }

    //Axis
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    x_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisX(x_axis);
    x_axis->setMin(x_min);
    x_axis->setMax(x_max);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisY(y_axis);
    y_axis->setMin(y_min);
    y_axis->setMax(y_max);

    //Series
    //qDebug() << "Series";
    vector<QLineSeries*> v_series;
    v_series.resize(vv_X_Data.size());

    for(size_t s = 0; s < vv_X_Data.size(); s++)
    {
        //qDebug() << "series" << s;

        //name
        v_series[s] = new QLineSeries;
        v_series[s]->setName(qsl_name_series[static_cast<int>(s)]);
        v_series[s]->setPointsVisible(dots_visible);
        if(heat_color)
        {
            double series_pos_rel = s / static_cast<double>(v_series.size() - 1);
            QColor series_color;

            if(heat_color_AllColors)
            {
                series_color.setHsv(
                            static_cast<uchar>(255 * series_pos_rel),
                            255,
                            255);
            }
            else
            {
                series_color.setRgb(
                            static_cast<uchar>(255 * series_pos_rel),
                            0,
                            static_cast<uchar>(255 * (1.0 - series_pos_rel)));
            }

            v_series[s]->setColor(series_color);
        }

        //data
        for(size_t i = 0; i < vv_Y_Data[s].size(); i++)
            v_series[s]->append(
                        vv_X_Data[s][i],
                        vv_Y_Data[s][i]);

        //stuff to do at end of series
        chart->addSeries(v_series[s]);

        v_series[s]->attachAxis(x_axis);
        v_series[s]->attachAxis(y_axis);
    }

    //cosmetic
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(legend_pos);

    //attach
    pChartView->setChart(chart);

    return ER_okay;
}

int D_Plot::Plot_Line_XY_Multi(QChartView *pChartView, vector<vector<double> > vv_X_Data, vector<vector<double> > vv_Y_Data, vector<vector<double> > vv_Y_Errors, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y, bool dots_visible, bool heat_color, bool heat_color_AllColors, Qt::Alignment legend_pos)
{
    if(vv_X_Data.empty())                                                   return ER_empty;
    if(vv_Y_Data.empty())                                                   return ER_empty;
    if(vv_Y_Errors.empty())                                                 return ER_empty;
    if(vv_Y_Data[0].empty())                                                return ER_empty;
    if(vv_Y_Errors[0].empty())                                              return ER_empty;
    if((vv_X_Data)[0].empty())                                              return ER_empty;
    if(vv_X_Data.size() != vv_Y_Data.size())                                return ER_size_missmatch;
    if(vv_X_Data.size() != vv_Y_Errors.size())                              return ER_size_missmatch;
    if(static_cast<size_t>(qsl_name_series.size()) != vv_X_Data.size())     return ER_size_missmatch;

    //clear old content
    Free_Memory(pChartView);

    //Chart
    //qDebug() << "==================================Chart";
    QChart *chart = new QChart();
    chart->setTitle(name_title);

    //min/max & size check
    //qDebug() << "min/max";
    double x_min = vv_X_Data[0][0];
    double x_max = vv_X_Data[0][0];
    double y_min = vv_Y_Data[0][0] - vv_Y_Errors[0][0];
    double y_max = vv_Y_Data[0][0] + vv_Y_Errors[0][0];
    for(size_t s = 0; s < vv_Y_Data.size(); s++)
    {
        if(vv_X_Data[s].size() != vv_Y_Data[s].size())      return ER_size_missmatch;
        if(vv_X_Data[s].size() != vv_Y_Errors[s].size())    return ER_size_missmatch;

        for(size_t i = 0; i < vv_X_Data[s].size(); i++)
        {
            //cehck min/max x
            double x = vv_X_Data[s][i];
            if(x < x_min)
                x_min = x;
            if(x > x_max)
                x_max = x;

            //cehck min/max y
            double y = vv_Y_Data[s][i] - vv_Y_Errors[s][i];
            if(y < y_min)
                y_min = y;
            y = vv_Y_Data[s][i] + vv_Y_Errors[s][i];
            if(y > y_max)
                y_max = y;
        }
    }
    //1/2 width error bars
    double w = 0.01 * x_max;

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    x_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisX(x_axis);
    x_axis->setMin(x_min);
    x_axis->setMax(x_max);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisY(y_axis);
    y_axis->setMin(y_min);
    y_axis->setMax(y_max);

    //Series
    vector<QLineSeries*> v_series(vv_X_Data.size());

    //loop series
    for(size_t s = 0; s < vv_X_Data.size(); s++)
    {
        //qDebug() << "series" << s;

        //data
        v_series[s] = new QLineSeries;
        v_series[s]->setName(qsl_name_series[static_cast<int>(s)]);
        v_series[s]->setPointsVisible(dots_visible);

        if(heat_color)
        {
            double series_pos_rel = s / static_cast<double>(v_series.size() - 1);
            QColor series_color;

            if(heat_color_AllColors)
            {
                series_color.setHsv(
                            static_cast<uchar>(255 * series_pos_rel),
                            255,
                            255);
            }
            else
            {
                series_color.setRgb(
                            static_cast<uchar>(255 * series_pos_rel),
                            0,
                            static_cast<uchar>(255 * (1.0 - series_pos_rel)));
            }

            v_series[s]->setColor(series_color);
        }

        //data/errors
        for(size_t i = 0; i < vv_Y_Data[s].size(); i++)
        {
            double x = vv_X_Data[s][i];
            double y = vv_Y_Data[s][i];
            double e = vv_Y_Errors[s][i];
            v_series[s]->append(x,      y);
            v_series[s]->append(x,      y + e);
            v_series[s]->append(x - w,  y + e);
            v_series[s]->append(x + w,  y + e);
            v_series[s]->append(x,      y + e);
            v_series[s]->append(x,      y - e);
            v_series[s]->append(x - w,  y - e);
            v_series[s]->append(x + w,  y - e);
            v_series[s]->append(x,      y - e);
            v_series[s]->append(x,      y);
        }

        //attach axis/series
        chart->addSeries(v_series[s]);
        v_series[s]->attachAxis(x_axis);
        v_series[s]->attachAxis(y_axis);
    }

    //cosmetic
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(legend_pos);

    //attach chart
    pChartView->setChart(chart);

    return ER_okay;
}

int D_Plot::Plot_LineAreaError_XY(QChartView *pChartView, vector<double> v_X_Data, vector<double> v_Y_Data_1stVal, vector<double> v_Y_Data_1stErr, vector<double> v_Y_Data_2ndVal, QString name_title, QString name_series_1stVal, QString name_series_1stErr, QString name_series_2ndVal, QString name_x, QString name_y_1st, QString name_y_2nd, int x_trans, int y_trans_1st, int y_trans_2nd, bool dots_visible, bool man_axis_style_x, bool man_axis_style_y, double man_min_x, double man_max_x, double man_min_y_1st, double man_max_y_1st, int ticks_x, int ticks_y, bool show_n)
{
    if(v_X_Data.empty())                            return ER_empty;
    if(v_Y_Data_1stVal.empty())                     return ER_empty;
    if(v_Y_Data_1stErr.empty())                     return ER_empty;
    if(v_Y_Data_2ndVal.empty())                     return ER_empty;
    if(v_X_Data.size() != v_Y_Data_1stVal.size())   return ER_size_missmatch;
    if(v_X_Data.size() != v_Y_Data_1stErr.size())   return ER_size_missmatch;
    if(v_X_Data.size() != v_Y_Data_2ndVal.size())   return ER_size_missmatch;

    //clear old content
    Free_Memory(pChartView);

    //Chart
    //qDebug() << "==================================Chart";
    QChart *chart = new QChart();
    if(!name_title.isEmpty())
        chart->setTitle(name_title + (show_n ? "<br>n=" + QString::number(v_X_Data.size()) : ""));

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    if(!name_x.isEmpty())
        x_axis->setTitleText(QSL_AxeTrans_Prefix[x_trans] + name_x + QSL_AxeTrans_Suffix[x_trans]);
    x_axis->setTickCount(man_axis_style_x ? ticks_x : AXE_TICK_COUNT_MAJOR_DEFAULT);
    if(man_axis_style_x)
        x_axis->setRange(man_min_x, man_max_x);
    chart->setAxisX(x_axis);

    QValueAxis *y_axis_1st = new QValueAxis();
    if(!name_y_1st.isEmpty())
        y_axis_1st->setTitleText(QSL_AxeTrans_Prefix[y_trans_1st] + name_y_1st + QSL_AxeTrans_Suffix[y_trans_1st]);
    y_axis_1st->setTickCount(man_axis_style_y ? ticks_y : AXE_TICK_COUNT_MAJOR_DEFAULT);
    if(man_axis_style_y)
        y_axis_1st->setRange(man_min_y_1st, man_max_y_1st);
    chart->setAxisY(y_axis_1st);

    QValueAxis *y_axis_2nd = new QValueAxis();
    if(!name_y_2nd.isEmpty())
        y_axis_2nd->setTitleText(QSL_AxeTrans_Prefix[y_trans_2nd] + name_y_2nd + QSL_AxeTrans_Suffix[y_trans_2nd]);
    y_axis_2nd->setTickCount(man_axis_style_y ? ticks_y : AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->addAxis(y_axis_2nd, Qt::AlignRight);

    //Series

    //1st val
    QLineSeries *series_1st_val  = new QLineSeries();
    if(!name_series_1stVal.isEmpty())
        series_1st_val->setName(name_series_1stVal);
    series_1st_val->setColor(QColor(0, 0, 0));
    series_1st_val->setUseOpenGL(true);

    //1st err
    //lower
    QLineSeries *series_1st_err_lower  = new QLineSeries();
    series_1st_err_lower->setColor(QColor(255, 0, 0));
    series_1st_err_lower->setUseOpenGL(true);
    //upper
    QLineSeries *series_1st_err_upper  = new QLineSeries();
    series_1st_err_upper->setColor(QColor(255, 0, 0));
    series_1st_err_upper->setUseOpenGL(true);

    //2nd val
    QLineSeries *series_2nd_val  = new QLineSeries();
    if(!name_series_2ndVal.isEmpty())
        series_2nd_val->setName(name_series_2ndVal);
    series_2nd_val->setColor(QColor(0, 0, 255));
    series_2nd_val->setUseOpenGL(true);


    //Data for line series
    //qDebug() << "Data";
    for(size_t x = 0; x < v_X_Data.size(); x++)
    {
        //1st val
        series_1st_val->append(
                    D_Stat::AxeTrans(v_X_Data[x], x_trans),
                    D_Stat::AxeTrans(v_Y_Data_1stVal[x], y_trans_1st));

        //1st err lower
        series_1st_err_lower->append(
                    D_Stat::AxeTrans(v_X_Data[x], x_trans),
                    D_Stat::AxeTrans(v_Y_Data_1stVal[x] - v_Y_Data_1stErr[x], y_trans_1st));

        //1st err upper
        series_1st_err_upper->append(
                    D_Stat::AxeTrans(v_X_Data[x], x_trans),
                    D_Stat::AxeTrans(v_Y_Data_1stVal[x] + v_Y_Data_1stErr[x], y_trans_1st));

        //2nd val
        series_2nd_val->append(
                    D_Stat::AxeTrans(v_X_Data[x], x_trans),
                    D_Stat::AxeTrans(v_Y_Data_2ndVal[x], y_trans_2nd));
    }

    //area err series
    QAreaSeries *series_1st_err_area  = new QAreaSeries();
    if(!name_series_2ndVal.isEmpty())
        series_1st_err_area->setName(name_series_1stErr);
    series_1st_err_area->setColor(QColor(255, 192, 192));
    series_1st_err_area->setUseOpenGL(true);
    series_1st_err_area->setLowerSeries(series_1st_err_lower);
    series_1st_err_area->setUpperSeries(series_1st_err_upper);

    //Attach
    //err 1st area
    chart->addSeries(series_1st_err_area);
    series_1st_err_area->attachAxis(x_axis);
    series_1st_err_area->attachAxis(y_axis_1st);
    series_1st_err_area->setUseOpenGL(false);
    /*
    //err 1st lower
    series_1st_err_lower->setPointsVisible(dots_visible);
    chart->addSeries(series_1st_err_lower);
    series_1st_err_lower->attachAxis(x_axis);
    series_1st_err_lower->attachAxis(y_axis_1st);
    series_1st_err_lower->setUseOpenGL(false);
    //err 1st upper
    series_1st_err_upper->setPointsVisible(dots_visible);
    chart->addSeries(series_1st_err_upper);
    series_1st_err_upper->attachAxis(x_axis);
    series_1st_err_upper->attachAxis(y_axis_1st);
    series_1st_err_upper->setUseOpenGL(false);
    */
    //val 2nd
    series_2nd_val->setPointsVisible(dots_visible);
    chart->addSeries(series_2nd_val);
    series_2nd_val->attachAxis(x_axis);
    series_2nd_val->attachAxis(y_axis_2nd);
    series_2nd_val->setUseOpenGL(false);
    //val 1st
    series_1st_val->setPointsVisible(dots_visible);
    chart->addSeries(series_1st_val);
    series_1st_val->attachAxis(x_axis);
    series_1st_val->attachAxis(y_axis_1st);
    series_1st_val->setUseOpenGL(false);
    //chart
    pChartView->setChart(chart);
    chart->legend()->setAlignment(Qt::AlignTop);
    //chart->legend()->setVisible(false);

    return ER_okay;
}

int D_Plot::Plot_Line_PoolStat_Single(QChartView *pChartView, vector<double> vData_X_Pool, vector<double> vData_Y_Stat, double x_min, double x_step, size_t x_classes, size_t y_stat, QString name_title, QString qs_name_series, QString name_x, QString name_y, bool auto_range, bool man_axis_style_x, bool man_axis_style_y, double man_min_x, double man_max_x, double man_min_y, double man_max_y, int ticks_x, int ticks_y)
{
    if(auto_range)
        return Plot_Line_PoolStat_Single(
                    pChartView,
                    vData_X_Pool,
                    vData_Y_Stat,
                    x_classes,
                    y_stat,
                    name_title,
                    qs_name_series,
                    name_x,
                    name_y,
                    man_axis_style_x,
                    man_axis_style_y,
                    man_min_x,
                    man_max_x,
                    man_min_y,
                    man_max_y,
                    ticks_x,
                    ticks_y);
    else
        return Plot_Line_PoolStat_Single(
                    pChartView,
                    vData_X_Pool,
                    vData_Y_Stat,
                    x_min,
                    x_step,
                    x_classes,
                    y_stat,
                    name_title,
                    qs_name_series,
                    name_x,
                    name_y,
                    man_axis_style_x,
                    man_axis_style_y,
                    man_min_x,
                    man_max_x,
                    man_min_y,
                    man_max_y,
                    ticks_x,
                    ticks_y);

}

int D_Plot::Plot_Line_PoolStat_Single(QChartView *pChartView, vector<double> vData_X_Pool, vector<double> vData_Y_Stat, size_t x_classes, size_t y_stat, QString name_title, QString qs_name_series, QString name_x, QString name_y, bool man_axis_style_x, bool man_axis_style_y, double man_min_x, double man_max_x, double man_min_y, double man_max_y, int ticks_x, int ticks_y)
{
    //calc x range
    double x_min, x_max;
    int err = D_Stat::Calc_MinMax(&x_min, &x_max, vData_X_Pool);
    if(err != ER_okay)
        return err;

    double x_range = x_max - x_min;
    double x_step = x_range / x_classes;

    return Plot_Line_PoolStat_Single(
                pChartView,
                vData_X_Pool,
                vData_Y_Stat,
                x_min,
                x_step,
                x_classes,
                y_stat,
                name_title,
                qs_name_series,
                name_x,
                name_y,
                man_axis_style_x,
                man_axis_style_y,
                man_min_x,
                man_max_x,
                man_min_y,
                man_max_y,
                ticks_x,
                ticks_y);
}

int D_Plot::Plot_Line_PoolStat_Single(QChartView *pChartView, vector<double> vData_X_Pool, vector<double> vData_Y_Stat, double x_min, double x_step, size_t x_classes, size_t y_stat, QString name_title, QString qs_name_series, QString name_x, QString name_y, bool man_axis_style_x, bool man_axis_style_y, double man_min_x, double man_max_x, double man_min_y, double man_max_y, int ticks_x, int ticks_y)
{
    //qDebug() << "D_Plot::Plot_Line_PoolStat_Single" << "start";

    //Pool data and calc stat
    vector<double> vData_Pooled_x_Pools;
    vector<double> vData_Pooled_y_Stats;
    //qDebug() << "D_Plot::Plot_Line_PoolStat_Single" << "polling and stat calc";
    int err_pooling = D_Stat::PoolStat_Data(
                &vData_Pooled_x_Pools,
                &vData_Pooled_y_Stats,
                vData_X_Pool,
                vData_Y_Stat,
                x_min,
                x_step,
                x_classes,
                y_stat);
    if(err_pooling != ER_okay)
        return err_pooling;

    //errors?
    //qDebug() << "D_Plot::Plot_Line_PoolStat_Single" << "check errors";
    if(vData_Pooled_x_Pools.empty())                                return ER_empty;
    if(vData_Pooled_y_Stats.empty())                                return ER_empty;
    if(vData_Pooled_x_Pools.size() != vData_Pooled_y_Stats.size())  return ER_size_missmatch;

    //plot as line
    //qDebug() << "D_Plot::Plot_Line_PoolStat_Single" << "plot line";
    return Plot_Line_XY_Single(
                pChartView,
                vData_Pooled_x_Pools,
                vData_Pooled_y_Stats,
                name_title + "<br>n=" + QString::number(vData_X_Pool.size()),
                qs_name_series,
                name_x + " (pooled)",
                QSL_StatList[int(y_stat)] + " of " + name_y,
                c_AXE_TRANS_LIN,
                c_AXE_TRANS_LIN,
                false,
                man_axis_style_x,
                man_axis_style_y,
                man_min_x,
                man_max_x,
                man_min_y,
                man_max_y,
                ticks_x,
                ticks_y,
                false);
}

int D_Plot::Plot_Line_PoolStat_DualErr(QChartView *pChartView, vector<double> vData_X_Pool, vector<double> vData_Y_Stat, double x_min, double x_step, size_t x_classes, size_t stat_y_main_val, size_t stat_y_main_err, size_t stat_y_secondary_val, QString name_title, QString name_series, QString name_x, QString name_y, bool auto_range, int x_trans, int y_trans_1st, int y_trans_2nd, bool dots_visible, bool man_axis_style_x, bool man_axis_style_y, double man_min_x, double man_max_x, double man_min_y, double man_max_y, int ticks_x, int ticks_y)
{
    if(auto_range)
        return Plot_Line_PoolStat_DualErr(
                    pChartView,
                    vData_X_Pool,
                    vData_Y_Stat,
                    x_classes,
                    stat_y_main_val,
                    stat_y_main_err,
                    stat_y_secondary_val,
                    name_title,
                    name_series,
                    name_x,
                    name_y,
                    x_trans,
                    y_trans_1st,
                    y_trans_2nd,
                    dots_visible,
                    man_axis_style_x,
                    man_axis_style_y,
                    man_min_x,
                    man_max_x,
                    man_min_y,
                    man_max_y,
                    ticks_x,
                    ticks_y);
    else
        return Plot_Line_PoolStat_DualErr(
                    pChartView,
                    vData_X_Pool,
                    vData_Y_Stat,
                    x_min,
                    x_step,
                    x_classes,
                    stat_y_main_val,
                    stat_y_main_err,
                    stat_y_secondary_val,
                    name_title,
                    name_series,
                    name_x,
                    name_y,
                    x_trans,
                    y_trans_1st,
                    y_trans_2nd,
                    dots_visible,
                    man_axis_style_x,
                    man_axis_style_y,
                    man_min_x,
                    man_max_x,
                    man_min_y,
                    man_max_y,
                    ticks_x,
                    ticks_y);
}

int D_Plot::Plot_Line_PoolStat_DualErr(QChartView *pChartView, vector<double> vData_X_Pool, vector<double> vData_Y_Stat, size_t x_classes, size_t stat_y_main_val, size_t stat_y_main_err, size_t stat_y_secondary_val, QString name_title, QString name_series, QString name_x, QString name_y, int x_trans, int y_trans_1st, int y_trans_2nd, bool dots_visible, bool man_axis_style_x, bool man_axis_style_y, double man_min_x, double man_max_x, double man_min_y, double man_max_y, int ticks_x, int ticks_y)
{
    //calc x range
    double x_min, x_max;
    int err = D_Stat::Calc_MinMax(&x_min, &x_max, vData_X_Pool);
    if(err != ER_okay)
        return err;

    return Plot_Line_PoolStat_DualErr(
                pChartView,
                vData_X_Pool,
                vData_Y_Stat,
                x_min,
                x_max,
                x_classes,
                stat_y_main_val,
                stat_y_main_err,
                stat_y_secondary_val,
                name_title,
                name_series,
                name_x,
                name_y,
                x_trans,
                y_trans_1st,
                y_trans_2nd,
                dots_visible,
                man_axis_style_x,
                man_axis_style_y,
                man_min_x,
                man_max_x,
                man_min_y,
                man_max_y,
                ticks_x,
                ticks_y);
}

int D_Plot::Plot_Line_PoolStat_DualErr(QChartView *pChartView, vector<double> vData_X_Pool, vector<double> vData_Y_Stat, double x_min, double x_step, size_t x_classes, size_t stat_y_main_val, size_t stat_y_main_err, size_t stat_y_secondary_val, QString name_title, QString name_series, QString name_x, QString name_y, int x_trans, int y_trans_1st, int y_trans_2nd, bool dots_visible, bool man_axis_style_x, bool man_axis_style_y, double man_min_x, double man_max_x, double man_min_y, double man_max_y, int ticks_x, int ticks_y)
{
    //qDebug() << "D_Plot::Plot_Line_PoolStat_Single" << "start";

    //semanctics of axis
    enum DATA_INDICES {
        DATA_INDEX_MAIN_VAL,
        DATA_INDEX_MAIN_ERR,
        DATA_INDEX_2ND_VAL,
        DATA_INDEX_NUMBER_OF
    };
    vector<size_t> vStatIndices(DATA_INDEX_NUMBER_OF);
    vStatIndices[DATA_INDEX_MAIN_VAL] = stat_y_main_val;
    vStatIndices[DATA_INDEX_MAIN_ERR] = stat_y_main_err;
    vStatIndices[DATA_INDEX_2ND_VAL] = stat_y_secondary_val;

    //Pooled containers
    vector<double> vData_Pooled_x_Pools;
    vector<vector<double>> vvData_Pooled_y_Stats(DATA_INDEX_NUMBER_OF);

    //calc pooling and stats
    //qDebug() << "D_Plot::Plot_Line_PoolStat_Single" << "polling and stat calc";
    int err_pooling = D_Stat::PoolStat_Data(
                &vData_Pooled_x_Pools,
                &vvData_Pooled_y_Stats,
                vData_X_Pool,
                vData_Y_Stat,
                x_min,
                x_step,
                x_classes,
                vStatIndices);
    if(err_pooling != ER_okay)
        return err_pooling;

    //errors?
    //qDebug() << "D_Plot::Plot_Line_PoolStat_Single" << "check errors";
    if(vData_Pooled_x_Pools.empty())                                return ER_empty;
    if(vvData_Pooled_y_Stats.empty())                               return ER_empty;
    for(size_t s = 0; s < DATA_INDEX_NUMBER_OF; s++)
    {
        if(vvData_Pooled_y_Stats[s].empty())                                return ER_empty;
        if(vData_Pooled_x_Pools.size() != vvData_Pooled_y_Stats[s].size())  return ER_size_missmatch;
    }

    //plot as line
    //qDebug() << "D_Plot::Plot_Line_PoolStat_Single" << "plot line";
    return Plot_LineAreaError_XY(
                pChartView,
                vData_Pooled_x_Pools,
                vvData_Pooled_y_Stats[DATA_INDEX_MAIN_VAL],
                vvData_Pooled_y_Stats[DATA_INDEX_MAIN_ERR],
                vvData_Pooled_y_Stats[DATA_INDEX_2ND_VAL],
                name_title + "<br>n=" + QString::number(vData_X_Pool.size()),
                QSL_StatList[int(vStatIndices[DATA_INDEX_MAIN_VAL])] + " of "  + name_y,
                QSL_StatList[int(vStatIndices[DATA_INDEX_MAIN_ERR])] + " of "  + name_y,
                QSL_StatList[int(vStatIndices[DATA_INDEX_2ND_VAL])] + " of "  + name_y,
                name_x + " (pooled)",
                QSL_StatList[int(vStatIndices[DATA_INDEX_MAIN_VAL])] + " ± " + QSL_StatList[int(vStatIndices[DATA_INDEX_MAIN_ERR])] + " of "  + name_y,
                QSL_StatList[int(vStatIndices[DATA_INDEX_2ND_VAL])] + " of "  + name_y,
                x_trans,
                y_trans_1st,
                y_trans_2nd,
                dots_visible,
                man_axis_style_x,
                man_axis_style_y,
                man_min_x,
                man_max_x,
                man_min_y,
                man_max_y,
                ticks_x,
                ticks_y,
                false);
}

int D_Plot::Plot_XY_Fit(QChartView *pChartView, vector<vector<vector<double> > > vvv_XY_Data_Measure, vector<vector<vector<double> > > vvv_XY_Data_Fit, QString name_title, QStringList qsl_name_series, QString name_x, QString name_y)
{
    if(vvv_XY_Data_Measure.empty())                                                     return ER_empty;
    if(vvv_XY_Data_Measure[0].empty())                                                  return ER_empty;
    if(vvv_XY_Data_Measure[0][0].empty())                                               return ER_empty;
    if(vvv_XY_Data_Measure[0][0].size() != 2)                                           return ER_size_bad;
    if(vvv_XY_Data_Fit.empty())                                                         return ER_empty;
    if(vvv_XY_Data_Fit[0].empty())                                                      return ER_empty;
    if(vvv_XY_Data_Fit[0][0].empty())                                                   return ER_empty;
    if(vvv_XY_Data_Fit[0][0].size() != 2)                                               return ER_size_bad;
    if(vvv_XY_Data_Fit.size() != static_cast<size_t>(qsl_name_series.size()))           return ER_size_missmatch;
    if(vvv_XY_Data_Measure.size() != static_cast<size_t>(qsl_name_series.size()))       return ER_size_missmatch;

    //clear old content
    Free_Memory(pChartView);

    //Chart
    QChart *chart = new QChart();
    chart->setTitle(name_title);

    //indices & sizes
    size_t n_sets      = vvv_XY_Data_Measure.size();
    const int ix    = 0;
    const int iy    = 1;

    //extrema
    double x_min = vvv_XY_Data_Measure[0][0][ix];
    double x_max = vvv_XY_Data_Measure[0][0][ix];
    double y_min = vvv_XY_Data_Measure[0][0][ix];
    double y_max = vvv_XY_Data_Measure[0][0][ix];
    for(size_t set = 0; set < n_sets; set++)
    {
        //measure
        for(size_t p = 0; p < vvv_XY_Data_Measure[set].size(); p++)
        {
            if(vvv_XY_Data_Measure[set][p].size() != 2) return ER_size_bad;
            double x = vvv_XY_Data_Measure[set][p][ix];
            double y = vvv_XY_Data_Measure[set][p][iy];
            if(x < x_min)   x_min = x;
            if(x > x_max)   x_max = x;
            if(y < y_min)   y_min = y;
            if(y > y_max)   y_max = y;

            //fit
            for(size_t p = 0; p < vvv_XY_Data_Fit[set].size(); p++)
            {
                if(vvv_XY_Data_Fit[set][p].size() != 2) return ER_size_bad;
                double x = vvv_XY_Data_Fit[set][p][ix];
                double y = vvv_XY_Data_Fit[set][p][iy];
                if(x < x_min)   x_min = x;
                if(x > x_max)   x_max = x;
                if(y < y_min)   y_min = y;
                if(y > y_max)   y_max = y;
            }
        }
    }

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    x_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisX(x_axis);
    x_axis->setMin(x_min);
    x_axis->setMax(x_max);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisY(y_axis);
    y_axis->setMin(y_min);
    y_axis->setMax(y_max);

    //Series
    //qDebug() << "Series";
    vector<QLineSeries*> v_series_fit;
    v_series_fit.resize(n_sets);
    vector<QScatterSeries*> v_series_measure;
    v_series_measure.resize(n_sets);

    for(size_t s = 0; s < n_sets; s++)
    {
        //FIT

        //name
        v_series_fit[s] = new QLineSeries;
        v_series_fit[s]->setName("");

        //data
        for(size_t p = 0; p < vvv_XY_Data_Fit[s].size(); p++)
            v_series_fit[s]->append(
                        vvv_XY_Data_Fit[s][p][ix],
                        vvv_XY_Data_Fit[s][p][iy]);

        //stuff to do at end of series
        chart->addSeries(v_series_fit[s]);
        v_series_fit[s]->attachAxis(x_axis);
        v_series_fit[s]->attachAxis(y_axis);

        //MEASURE

        //name & color
        v_series_measure[s] = new QScatterSeries;
        v_series_measure[s]->setName(qsl_name_series[static_cast<int>(s)]);
        v_series_measure[s]->setColor(v_series_fit[s]->color());

        //data
        for(size_t p = 0; p < vvv_XY_Data_Measure[s].size(); p++)
            v_series_measure[s]->append(
                        vvv_XY_Data_Measure[s][p][ix],
                        vvv_XY_Data_Measure[s][p][iy]);

        //stuff to do at end of series
        chart->addSeries(v_series_measure[s]);
        v_series_measure[s]->attachAxis(x_axis);
        v_series_measure[s]->attachAxis(y_axis);
    }

    //attach
    //qDebug() << "attach";
    pChartView->setChart(chart);

    return ER_okay;
}

int D_Plot::Plot_Line_XY_Single(QChartView *pChartView, vector<double> v_XY_Data, QString name_title, QString name_series, QString name_x, QString name_y, int x_trans, int y_trans, bool dots_visible, bool man_axis_style_x, bool man_axis_style_y, double man_min_x, double man_max_x, double man_min_y, double man_max_y, int ticks_x, int ticks_y, bool show_n)
{
    if(v_XY_Data.empty())  return ER_empty;

    //clear old content
    Free_Memory(pChartView);

    //Chart
    //qDebug() << "==================================Chart";
    QChart *chart = new QChart();
    chart->setTitle(name_title + (show_n ? "<br>n=" + QString::number(v_XY_Data.size()) : ""));

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(QSL_AxeTrans_Prefix[x_trans] + name_x + QSL_AxeTrans_Suffix[x_trans]);
    x_axis->setTickCount(man_axis_style_x ? ticks_x : AXE_TICK_COUNT_MAJOR_DEFAULT);
    if(man_axis_style_x)
        x_axis->setRange(man_min_x, man_max_x);
    chart->setAxisX(x_axis);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(QSL_AxeTrans_Prefix[y_trans] + name_y + QSL_AxeTrans_Suffix[y_trans]);
    y_axis->setTickCount(man_axis_style_y ? ticks_y : AXE_TICK_COUNT_MAJOR_DEFAULT);
    if(man_axis_style_y)
        y_axis->setRange(man_min_y, man_max_y);
    chart->setAxisY(y_axis);

    //Series
    //qDebug() << "Series";
    QLineSeries *series  = new QLineSeries();
    series->setName(name_series);
    series->setUseOpenGL(true);

    //Data
    //qDebug() << "Data";
    for(size_t x = 0; x < v_XY_Data.size(); x++)
        series->append(
                    D_Stat::AxeTrans(x, x_trans),
                    D_Stat::AxeTrans(v_XY_Data[x], y_trans));

    //Attach
    series->setPointsVisible(dots_visible);
    chart->addSeries(series);
    series->attachAxis(x_axis);
    series->attachAxis(y_axis);
    series->setUseOpenGL(false);
    pChartView->setChart(chart);

    return ER_okay;
}

int D_Plot::Plot_Line_XY_Single(QChartView *pChartView, vector<double> v_X_Data, vector<double> v_Y_Data, QString name_title, QString name_series, QString name_x, QString name_y, int x_trans, int y_trans, bool dots_visible, bool man_axis_style_x, bool man_axis_style_y, double man_min_x, double man_max_x, double man_min_y, double man_max_y, int ticks_x, int ticks_y, bool show_n)
{
    if(v_X_Data.empty())                    return ER_empty;
    if(v_Y_Data.empty())                    return ER_empty;
    if(v_X_Data.size() != v_Y_Data.size())  return ER_size_missmatch;

    //clear old content
    Free_Memory(pChartView);

    //Chart
    //qDebug() << "==================================Chart";
    QChart *chart = new QChart();
    if(!name_title.isEmpty())
        chart->setTitle(name_title + (show_n ? "<br>n=" + QString::number(v_X_Data.size()) : ""));

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    if(!name_x.isEmpty())
        x_axis->setTitleText(QSL_AxeTrans_Prefix[x_trans] + name_x + QSL_AxeTrans_Suffix[x_trans]);
    x_axis->setTickCount(man_axis_style_x ? ticks_x : AXE_TICK_COUNT_MAJOR_DEFAULT);
    if(man_axis_style_x)
        x_axis->setRange(man_min_x, man_max_x);
    chart->setAxisX(x_axis);

    QValueAxis *y_axis = new QValueAxis();
    if(!name_y.isEmpty())
        y_axis->setTitleText(QSL_AxeTrans_Prefix[y_trans] + name_y + QSL_AxeTrans_Suffix[y_trans]);
    y_axis->setTickCount(man_axis_style_y ? ticks_y : AXE_TICK_COUNT_MAJOR_DEFAULT);
    if(man_axis_style_y)
        y_axis->setRange(man_min_y, man_max_y);
    chart->setAxisY(y_axis);


    //Series
    //qDebug() << "Series";
    QLineSeries *series  = new QLineSeries();
    if(!name_series.isEmpty())
        series->setName(name_series);
    series->setUseOpenGL(true);

    //Data
    //qDebug() << "Data";
    for(size_t x = 0; x < v_X_Data.size(); x++)
        series->append(
                    D_Stat::AxeTrans(v_X_Data[x], x_trans),
                    D_Stat::AxeTrans(v_Y_Data[x], y_trans));

    //Attach
    series->setPointsVisible(dots_visible);
    chart->addSeries(series);
    series->attachAxis(x_axis);
    series->attachAxis(y_axis);
    series->setUseOpenGL(false);
    pChartView->setChart(chart);

    if(name_series.isEmpty())
    {
        chart->legend()->setAlignment(Qt::AlignRight);
        chart->legend()->setVisible(false);
    }

    return ER_okay;
}

int D_Plot::Plot_StatPar_Quantiles(QChartView *pChartView, vector<vector<vector<double>>> *vvv_ParSetSta, unsigned int par, QString name_title, QString name_series, QString name_x, QString name_y)
{
    if(par >= vvv_ParSetSta->size()) return ER_size_missmatch;

    //clear old content
    Free_Memory(pChartView);

    //Chart
    qDebug() << "==================================Plot_Stat_Quantiles";
    QChart *chart = new QChart();
    //chart->createDefaultAxes();
    chart->setTitle(name_title);
    //chart->legend()->setVisible(false);
    //chart->legend()->setAlignment(Qt::AlignBottom);

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    x_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisX(x_axis);
    double min = (*vvv_ParSetSta)[par][0][c_STAT_MINIMUM];
    double max = (*vvv_ParSetSta)[par][0][c_STAT_MAXIMUM];

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisY(y_axis);

    //Series
    vector<QLineSeries*> series;
    series.resize((*vvv_ParSetSta)[par].size());

    for(unsigned int s = 0; s < (*vvv_ParSetSta)[par].size(); s++)
    {
        series[s] = new QLineSeries();
        series[s]->setName(name_series + QString::number(s));

        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_MINIMUM], 0.00);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUANTIL_05], 0.05);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUANTIL_10], 0.10);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUANTIL_15], 0.15);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUANTIL_20], 0.20);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUARTIL_LOW], 0.25);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUANTIL_30], 0.30);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUANTIL_35], 0.35);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUANTIL_40], 0.40);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUANTIL_45], 0.45);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_MEDIAN], 0.50);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUANTIL_55], 0.55);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUANTIL_60], 0.60);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUANTIL_65], 0.65);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUANTIL_70], 0.70);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUARTIL_UP], 0.75);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUANTIL_80], 0.80);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUANTIL_85], 0.85);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUANTIL_90], 0.90);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_QUANTIL_95], 0.95);
        series[s]->append((*vvv_ParSetSta)[par][s][c_STAT_MAXIMUM], 1.00);

        if((*vvv_ParSetSta)[par][s][c_STAT_MINIMUM] < min)
            min = (*vvv_ParSetSta)[par][s][c_STAT_MINIMUM];
        if((*vvv_ParSetSta)[par][s][c_STAT_MAXIMUM] > max)
            max = (*vvv_ParSetSta)[par][s][c_STAT_MAXIMUM];

        chart->addSeries(series[s]);
        series[s]->attachAxis(x_axis);
        series[s]->attachAxis(y_axis);
    }

    //min/max
    x_axis->setMin(min);
    x_axis->setMax(max);

    //Attach
    pChartView->setChart(chart);

    //qDebug() << "Plot Sucess===============================";
    return ER_okay;
}

int D_Plot::Plot_Stat_Multi_MeanMedian(QChartView *pChartView, vector<vector<double> > *vv_SetSta, bool pl_mean, bool pl_sd, bool pl_median, bool pl_adm, QString name_title, QString name_categories, QString name_y)
{
    //clear old content
    Free_Memory(pChartView);

    //Chart
    QChart *chart = new QChart();
    chart->setTitle(name_title);

    //Sets
    QBarSet *set_mean = new QBarSet("Mean");
    QBarSet *set_sdev = new QBarSet("Standard Deviation");
    QBarSet *set_medi = new QBarSet("Median");
    QBarSet *set_aadm = new QBarSet("Average Absolute Deviation from Median");

    //Categories
    QStringList categories;

    //Series
    QBarSeries *series = new QBarSeries();
    for(unsigned int set = 0; set < vv_SetSta->size(); set++)
    {
        if(pl_mean)     set_mean->append((*vv_SetSta)[set][c_STAT_MEAN_ARITMETIC]);
        if(pl_sd)       set_sdev->append((*vv_SetSta)[set][c_STAT_STAN_DEV_SAMPLE]);
        if(pl_median)   set_medi->append((*vv_SetSta)[set][c_STAT_MEDIAN]);
        if(pl_adm)      set_aadm->append((*vv_SetSta)[set][c_STAT_ABS_DEV_MED]);

        categories.append(QString::number(set));
    }
    if(pl_mean)     series->append(set_mean);
    if(pl_sd)       series->append(set_sdev);
    if(pl_median)   series->append(set_medi);
    if(pl_adm)      series->append(set_aadm);
    chart->addSeries(series);

    //Axis
    QBarCategoryAxis *X_axis = new QBarCategoryAxis();
    X_axis->append(categories);
    X_axis->setTitleText(name_categories);
    X_axis->setLabelsAngle(90);
    chart->setAxisX(X_axis, series);

    QValueAxis *Y_axis = new QValueAxis();
    Y_axis->setTitleText(name_y);
    Y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisY(Y_axis, series);


    //Showing
    pChartView->setChart(chart);

    return ER_okay;
}

int D_Plot::Plot_Stat_Multi_CvSkewKurt(QChartView *pChartView, vector<vector<double> > *vv_SetSta, bool pl_cv, bool pl_skew, bool pl_kurt, QString name_title, QString name_categories, QString name_y)
{
    //clear old content
    Free_Memory(pChartView);

    //Chart
    QChart *chart = new QChart();
    chart->setTitle(name_title);

    //Sets
    QBarSet *set_varcoeff = new QBarSet("Coeficient of Variance");
    QBarSet *set_skewness = new QBarSet("Skewness");
    QBarSet *set_kurtosis = new QBarSet("Kurtosis");

    //Categories
    QStringList categories;

    //Series
    QBarSeries *series = new QBarSeries();
    for(unsigned int set = 0; set < vv_SetSta->size(); set++)
    {
        if(pl_cv)       set_varcoeff->append((*vv_SetSta)[set][c_STAT_VARIANCE_SAMPLE]);
        if(pl_skew)     set_skewness->append((*vv_SetSta)[set][c_STAT_SKEWNESS_SAMPLE]);
        if(pl_kurt)     set_kurtosis->append((*vv_SetSta)[set][c_STAT_KURTOSIS_SAMPLE]);

        categories.append(QString::number(set));
    }
    if(pl_cv)       series->append(set_varcoeff);
    if(pl_skew)     series->append(set_skewness);
    if(pl_kurt)     series->append(set_kurtosis);
    chart->addSeries(series);

    //Axis
    QBarCategoryAxis *X_axis = new QBarCategoryAxis();
    X_axis->append(categories);
    X_axis->setTitleText(name_categories);
    X_axis->setLabelsAngle(90);
    chart->setAxisX(X_axis, series);

    QValueAxis *Y_axis = new QValueAxis();
    Y_axis->setTitleText(name_y);
    Y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisY(Y_axis, series);


    //Showing
    pChartView->setChart(chart);

    return ER_okay;
}

int D_Plot::Plot_Stat_Multi_Quantiles(QChartView *pChartView, vector<vector<double> > *vv_SetSta, unsigned int steps, QString name_title, QString name_categories, QString name_y)
{
    //clear old content
    Free_Memory(pChartView);

    //Chart
    QChart *chart = new QChart();
    chart->setTitle(name_title);

    //stepwidth
    unsigned int index_cnt = 3;
    unsigned int index_inc = 10;
    switch (steps) {
    case 0:     index_cnt = 20;     index_inc = 1;      break;  //05%   00 05 10 .. 100
    case 1:     index_cnt = 10;     index_inc = 2;      break;  //10%   00 10 20 .. 100
    case 2:     index_cnt = 5;      index_inc = 4;      break;  //20%   00 20 40 .. 100
    case 3:     index_cnt = 4;      index_inc = 5;      break;  //25%   00 25 50 75 100
    case 4:     index_cnt = 2;      index_inc = 10;     break;  //50%   00    50    100
    default:                                            break;}

    //Sets
    vector<QBarSet*> sets;
    sets.resize(index_cnt);

    //Categories
    QStringList categories;
    for(unsigned int sets_in = 0; sets_in < vv_SetSta->size(); sets_in++)
        categories.append(QString::number(sets_in));

    //Series
    QStackedBarSeries *series = new QStackedBarSeries();
    //QBarSeries *series = new QBarSeries();

    //Data
    unsigned int index = 0;
    for(unsigned int set = 0; set < sets.size(); set++)
    {
        sets[set] = new QBarSet(QString::number(set * index_inc * 5) + "-" + QString::number((set + 1) * index_inc * 5) + "%");

        qDebug() << index;
        for(unsigned int sets_in = 0; sets_in < vv_SetSta->size(); sets_in++)
            sets[set]->append(D_Stat::Quant_1stD_Norm(&(*vv_SetSta)[sets_in], index, index_inc));

        series->append(sets[set]);

        index += index_inc;
    }
    chart->addSeries(series);

    //Axis
    QBarCategoryAxis *X_axis = new QBarCategoryAxis();
    X_axis->append(categories);
    X_axis->setTitleText(name_categories);
    X_axis->setLabelsAngle(90);
    chart->setAxisX(X_axis, series);

    QValueAxis *Y_axis = new QValueAxis();
    Y_axis->setTitleText(name_y);
    Y_axis->setTickCount(AXE_TICK_COUNT_MAJOR_DEFAULT);
    chart->setAxisY(Y_axis, series);


    //Showing
    pChartView->setChart(chart);

    return ER_okay;
}

int D_Plot::Plot_Stat_Multi_Custom(QChartView *pChartView, vector<vector<vector<double>>> *vvv_ParSetSta, unsigned int par_x, unsigned int par_y, unsigned int stat_x, unsigned int stat_y, QString name_title, QString name_series, QString name_x, QString name_y)
{
    if(vvv_ParSetSta->empty())                                              return ER_empty;
    if(stat_x >= c_STAT_NUMBER_OF_STATS)                                    return ER_index_out_of_range;
    if(stat_y >= c_STAT_NUMBER_OF_STATS)                                    return ER_index_out_of_range;
    if(par_x >= vvv_ParSetSta->size())                                      return ER_index_out_of_range;
    if(par_y >= vvv_ParSetSta->size())                                      return ER_index_out_of_range;
    if((*vvv_ParSetSta)[par_x].size() != (*vvv_ParSetSta)[par_y].size())    return ER_size_missmatch;

    //size
    size_t sets = (*vvv_ParSetSta)[par_x].size();

    //Data formating...
    vector<double> v_x(sets);
    vector<double> v_y(sets);
    for(size_t s = 0; s < sets; s++)
    {
        if((*vvv_ParSetSta)[par_x][s].size() != c_STAT_NUMBER_OF_STATS || (*vvv_ParSetSta)[par_y][s].size() != c_STAT_NUMBER_OF_STATS)
            return ER_parameter_bad;

        v_x[s] = (*vvv_ParSetSta)[par_x][s][stat_x];
        v_y[s] = (*vvv_ParSetSta)[par_y][s][stat_y];
    }

    //...to use general scatter plot
    return Plot_Scatter_2D_Single_Y(
                pChartView,
                &v_x,
                &v_y,
                name_title,
                name_series,
                name_x,
                name_y);

    /*
    //clear old content
    Free_Memory(pChartView);

    //Chart
    QChart *chart = new QChart();
    chart->setTitle(name_title);

    //Axis
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    chart->setAxisX(x_axis);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    chart->setAxisY(y_axis);


    //Series
    QScatterSeries *series  = new QScatterSeries();
    series->setName(name_series);
    series->setUseOpenGL(true);
    series->setMarkerSize(8);


    //Data
    //qDebug() << "Data start";
    for(unsigned int set = 0; (set < (*vvv_ParSetSta)[par_x].size()) && (set < (*vvv_ParSetSta)[par_y].size()); set++)
    {
        //qDebug() << "Set:" << set;
        series->append(
                    (*vvv_ParSetSta)[par_x][set][stat_x],
                    (*vvv_ParSetSta)[par_y][set][stat_y]);
    }
    //qDebug() << "Data end";

    //Attach
    chart->addSeries(series);
    series->attachAxis(x_axis);
    series->attachAxis(y_axis);
    series->setUseOpenGL(false);
    pChartView->setChart(chart);

    if((*vvv_ParSetSta)[par_x].size() != (*vvv_ParSetSta)[par_y].size())    return ER_size_missmatch;
    return ER_okay;
    */
}

int D_Plot::Plot_Pie_Surrival(QChartView *pChartView, int surrival, int dead, QString name_title)
{
    //clear old content
    Free_Memory(pChartView);

    //series
    QPieSeries *series = new QPieSeries;
    series->append("Surrival",  surrival);
    series->append("Dead",      dead);
    //series->setLabelsVisible();

    //add times in labels and set fix colors
    for(auto slice : series->slices())
    {
        QString label = slice->label();

        if(label == "Dead")         slice->setColor(Qt::red);
        if(label == "Surrival")     slice->setColor(Qt::blue);

        label = label + ": " + QString::number(slice->value()) + " Colonies";
        slice->setLabel(label);
    }

    QChart *pChart = new QChart();
    pChart->addSeries(series);
    pChart->setTitle(
                "<b>Cell-Colony Survival</b><br>" +
                name_title +
                "<br>Detected: " + QString::number(surrival + dead));

    pChartView->setChart(pChart);

    return ER_okay;
}



int D_Plot::Free_Memory(QChartView *pChartView)
{
    /*
    QList<QAbstractAxis*> axes = pChartView->chart()->axes();
    for(int i = 0; i < axes.size(); i++)
        axes.at(i)->deleteLater();

    QList<QAbstractSeries*> series = pChartView->chart()->series();
    for(int i = 0; i < axes.size(); i++)
        series.at(i)->deleteLater();

    pChartView->chart()->legend()->deleteLater();
    */

    pChartView->chart()->removeAllSeries();
    pChartView->chart()->deleteLater();

    return ER_okay;
}
