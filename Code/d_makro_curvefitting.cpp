/************************************
 *   added:     08.08.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_makro_curvefitting.h"
#include "ui_d_makro_curvefitting.h"

D_MAKRO_CurveFitting::D_MAKRO_CurveFitting(D_Storage *pStorage ,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_CurveFitting)
{
    ui->setupUi(this);

    //Store
    pStore = pStorage;

    //Drop Down Menus & param ui
    Populate_CB();
    ParamInitUiVectors();
    DataInitUiVectors();

    //Plot
    pChartView = new QChartView();
    ui->gridLayout_Plot->addWidget(pChartView);
    pChartView->setRenderHint(QPainter::Antialiasing);
    pChartView->setRubberBand(QChartView::RectangleRubberBand);
    pChartView->setInteractive(true);
    D_Plot::Plot_Empty(pChartView);

    //Viewer
    View_ParamSpace.set_GV(ui->graphicsView_VisParamSpace);
    MA_ParamSpaceSlice = Mat::zeros(100, 100, CV_64FC1);
    View_ParamSpace.Set_Transformation_Mode(false);

    //Connects
    connect(ui->pushButton_Fit,                 SIGNAL(clicked(bool)),                  this,       SLOT(FittingStart()));
    connect(ui->doubleSpinBox_Test_d1,          SIGNAL(valueChanged(double)),           this,       SLOT(PlotTest_PbBi()));
    connect(ui->doubleSpinBox_Test_w1,          SIGNAL(valueChanged(double)),           this,       SLOT(PlotTest_PbBi()));
    connect(ui->doubleSpinBox_Test_d2,          SIGNAL(valueChanged(double)),           this,       SLOT(PlotTest_PbBi()));
    connect(ui->doubleSpinBox_Test_w2,          SIGNAL(valueChanged(double)),           this,       SLOT(PlotTest_PbBi()));
    connect(ui->doubleSpinBox_range_a_max,      SIGNAL(valueChanged(double)),           this,       SLOT(PlotTest_PbBi()));
    connect(ui->doubleSpinBox_range_t_max,      SIGNAL(valueChanged(double)),           this,       SLOT(PlotTest_PbBi()));
    connect(ui->spinBox_VisDispPlane_d1,        SIGNAL(valueChanged(int)),              this,       SLOT(ParameterSpaceShow()));
    connect(ui->spinBox_VisDispPlane_w1,        SIGNAL(valueChanged(int)),              this,       SLOT(ParameterSpaceShow()));
    connect(ui->spinBox_VisDispPlane_d2,        SIGNAL(valueChanged(int)),              this,       SLOT(ParameterSpaceShow()));
    connect(ui->spinBox_VisDispPlane_w2,        SIGNAL(valueChanged(int)),              this,       SLOT(ParameterSpaceShow()));
    connect(ui->comboBox_VisDispPlane_Plane,    SIGNAL(currentIndexChanged(int)),       this,       SLOT(ParameterSpaceShow()));


    //on start
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    setWindowTitle("ImageD - Curve Fitting");
    this->showMaximized();

    //Test DGL
    //PlotTest_PbBi();
    qDebug() << "Test Pb(65)";
    qDebug() << static_cast<double>(Franzi_Pb_Combi(65, 5000000, 0.4, 1000000, 0.1));
    qDebug() << "Test Bi(65)";
    qDebug() << static_cast<double>(Franzi_Bi_Combi(65, 5000000, 0.4, 1000000, 0.1));
}

D_MAKRO_CurveFitting::~D_MAKRO_CurveFitting()
{
    delete ui;
}

void D_MAKRO_CurveFitting::closeEvent(QCloseEvent *event)
{
    if(ClosingPossible)
    {
        delete ui;
        event->accept();
    }
    else
    {
        event->ignore();
        this->showMinimized();
    }
}

void D_MAKRO_CurveFitting::resizeEvent(QResizeEvent *event)
{
    event->accept();
    Update_View();
}

void D_MAKRO_CurveFitting::UpdateUi()
{
    this->setEnabled(false);
    this->repaint();
    qApp->processEvents();
    this->setEnabled(true);
}

void D_MAKRO_CurveFitting::Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(index_init);
    CB->blockSignals(false);
}

void D_MAKRO_CurveFitting::Populate_CB()
{
    Populate_CB_Single(ui->comboBox_VisDispPlane_Plane, QSL_PlanesDW,      c_PLANE_DW_D1_W1);
    Populate_CB_Single(ui->comboBox_FitStat,            QSL_StatList2D,    c_STAT_2D_DIFF_REL_MEAN);
    Populate_CB_Single(ui->comboBox_FitOptimization,    QSL_Optimize_1D,   c_OPT_1D_MINIMUM);
}

void D_MAKRO_CurveFitting::ParamInitUiVectors()
{
    qDebug() << "ParamInitUiVectors" << "start";

    //current
    v_param_cur.clear();
    v_param_cur.resize(c_PARAM_NUMBER_OF, 0);
    v_param_cur_ui.clear();
    v_param_cur_ui.resize(c_PARAM_NUMBER_OF);
    v_param_cur_ui[c_PARAM_D1] = ui->label_ResCur_d1;
    v_param_cur_ui[c_PARAM_W1] = ui->label_ResCur_w1;
    v_param_cur_ui[c_PARAM_D2] = ui->label_ResCur_d2;
    v_param_cur_ui[c_PARAM_W2] = ui->label_ResCur_w2;

    //optimum
    v_param_opt.clear();
    v_param_opt.resize(c_PARAM_NUMBER_OF, 0);
    v_param_opt_ui.clear();
    v_param_opt_ui.resize(c_PARAM_NUMBER_OF);
    v_param_opt_ui[c_PARAM_D1] = ui->label_ResOpt_d1;
    v_param_opt_ui[c_PARAM_W1] = ui->label_ResOpt_w1;
    v_param_opt_ui[c_PARAM_D2] = ui->label_ResOpt_d2;
    v_param_opt_ui[c_PARAM_W2] = ui->label_ResOpt_w2;

    //min
    v_param_min.clear();
    v_param_min.resize(c_PARAM_NUMBER_OF, 0);
    v_param_min_ui.clear();
    v_param_min_ui.resize(c_PARAM_NUMBER_OF);
    v_param_min_ui[c_PARAM_D1] = ui->doubleSpinBox_min_d1;
    v_param_min_ui[c_PARAM_W1] = ui->doubleSpinBox_min_w1;
    v_param_min_ui[c_PARAM_D2] = ui->doubleSpinBox_min_d2;
    v_param_min_ui[c_PARAM_W2] = ui->doubleSpinBox_min_w2;

    //max
    v_param_max.clear();
    v_param_max.resize(c_PARAM_NUMBER_OF, 0);
    v_param_max_ui.clear();
    v_param_max_ui.resize(c_PARAM_NUMBER_OF);
    v_param_max_ui[c_PARAM_D1] = ui->doubleSpinBox_max_d1;
    v_param_max_ui[c_PARAM_W1] = ui->doubleSpinBox_max_w1;
    v_param_max_ui[c_PARAM_D2] = ui->doubleSpinBox_max_d2;
    v_param_max_ui[c_PARAM_W2] = ui->doubleSpinBox_max_w2;

    //step
    v_param_step.clear();
    v_param_step.resize(c_PARAM_NUMBER_OF, 0);
    v_param_step_ui.clear();
    v_param_step_ui.resize(c_PARAM_NUMBER_OF);
    v_param_step_ui[c_PARAM_D1] = ui->doubleSpinBox_step_d1;
    v_param_step_ui[c_PARAM_W1] = ui->doubleSpinBox_step_w1;
    v_param_step_ui[c_PARAM_D2] = ui->doubleSpinBox_step_d2;
    v_param_step_ui[c_PARAM_W2] = ui->doubleSpinBox_step_w2;

    qDebug() << "ParamInitUiVectors" << "end";
}

void D_MAKRO_CurveFitting::DataInitUiVectors()
{
    //data
    v_Data_ui.clear();
    v_Data_ui.resize(c_DATA_NUMBER_OF);
    v_Data_ui[c_DATA_PB_295]    = ui->plainTextEdit_Data_Pb_295;
    v_Data_ui[c_DATA_PB_352]    = ui->plainTextEdit_Data_Pb_352;
    v_Data_ui[c_DATA_BI]        = ui->plainTextEdit_Data_Bi;

    //data weights
    v_data_score_weights.clear();
    v_data_score_weights.resize(c_DATA_NUMBER_OF, 0);
    v_data_score_weights_ui.clear();
    v_data_score_weights_ui.resize(c_DATA_NUMBER_OF);
    v_data_score_weights_ui[c_DATA_PB_295]    = ui->spinBox_Data_Weight_Pb_295;
    v_data_score_weights_ui[c_DATA_PB_352]    = ui->spinBox_Data_Weight_Pb_352;
    v_data_score_weights_ui[c_DATA_BI]        = ui->spinBox_Data_Weight_Bi;
}

void D_MAKRO_CurveFitting::FittingStart()
{
    DataRead();
    DataWeightsRead();
    ParametersRead();
    ParametersCount();
    ParameterSpaceInit();

    FittingLoop();

    ParameterSpaceShow();
}



void D_MAKRO_CurveFitting::DataRead()
{
    qDebug() << "DataRead" << "start";

    //resize data vector
    vvv_Data_Set_TA.clear();
    vvv_Data_Set_TA.resize(c_DATA_NUMBER_OF);

    //resize sizes vector
    v_number_of_points.clear();
    v_number_of_points.resize(c_DATA_NUMBER_OF, 0);

    //loop data sets (isotops)
    for(int s = 0; s < c_DATA_NUMBER_OF; s++)
    {
        qDebug() << "DataRead" << "DataSet" << s;

        //read data to text
        QString QS_Data = v_Data_ui[s]->toPlainText();
        QStringList QSL_DataPairsXY = QS_Data.split("\n");
        v_number_of_points[s] = QSL_DataPairsXY.size();

        //transform text data to numbers
        vvv_Data_Set_TA[s].clear();
        vvv_Data_Set_TA[s].resize(v_number_of_points[s]);
        for(int d = 0; d < v_number_of_points[s]; d++)
        {
            qDebug() << "DataRead" << "DataSet" << s << "Point" << d;

            vvv_Data_Set_TA[s][d].resize(c_KOORD_NUMBER_OF, 0);    //T, A -> 2 Koordinates of data points
            QStringList QSL_CurrentPoint = QSL_DataPairsXY[d].split(",");

            if(QSL_CurrentPoint.size() != c_KOORD_NUMBER_OF)
            {
                QMessageBox::warning(
                            this,
                            "Data invalid",
                            "Something is wrong with datapoint " + QString::number(d + 1) + "/" + QString::number(v_number_of_points[s]) + ".<br>Datapoints are needed in the format \"T.T, A.A\"<br>Wrong number of \",\" Maybe there is an empty line?");
                return;
            }

            bool ok;

            //T
            vvv_Data_Set_TA[s][d][c_KOORD_T] = QSL_CurrentPoint[c_KOORD_T].toDouble(&ok);
            if(!ok)
            {
                QMessageBox::warning(
                            this,
                            "Data invalid",
                            "Something is wrong with datapoint " + QString::number(d + 1) + "/" + QString::number(v_number_of_points[s]) + ".<br>Datapoints are needed in the format \"T.T, A.A\"<br>Bad T format.");
                return;
            }

            //Y
            vvv_Data_Set_TA[s][d][c_KOORD_A] = QSL_CurrentPoint[c_KOORD_A].toDouble(&ok);
            if(!ok)
            {
                QMessageBox::warning(
                            this,
                            "Data invalid",
                            "Something is wrong with datapoint " + QString::number(d + 1) + "/" + QString::number(v_number_of_points[s]) + ".<br>Datapoints are needed in the format \"T.T, A.A\"<br>Bad A format.");
                return;
            }
        }
    }

    state_data_read = true;
    qDebug() << "DataRead" << "end";
}

void D_MAKRO_CurveFitting::DataWeightsRead()
{
    qDebug() << "DataWeightsRead" << "start";

    double sum = 0;
    for(int set = 0; set < c_DATA_NUMBER_OF; set++)
    {
        v_data_score_weights[set] = static_cast<double>(v_data_score_weights_ui[set]->value());
        sum += v_data_score_weights[set];
    }

    //realive weights (scale factors)
    for(int set = 0; set < c_DATA_NUMBER_OF; set++)
        v_data_score_weights[set] /= sum;

    qDebug() << "DataWeightsRead" << "end";
}

void D_MAKRO_CurveFitting::ParametersRead()
{
    for(int p = 0; p < c_PARAM_NUMBER_OF; p++)
    {
        v_param_min[p] = v_param_min_ui[p]->value();
        v_param_max[p] = v_param_max_ui[p]->value();
        v_param_step[p] = v_param_step_ui[p]->value();
    }

    state_parameters_read = true;
}

void D_MAKRO_CurveFitting::ParametersCount()
{
    v_param_count.clear();
    v_param_count.resize(c_PARAM_NUMBER_OF, 0);

    for(int p = 0; p < c_PARAM_NUMBER_OF; p++)
        for(double v = v_param_min[p]; v <= v_param_max[p]; v += v_param_step[p])
            (v_param_count[p])++;

    param_space_size = 1;
    for(int p = 0; p < c_PARAM_NUMBER_OF; p++)
        if(v_param_count[p] > 0)
            param_space_size *= v_param_count[p];

    ui->spinBox_VisDispPlane_d1->setMaximum(v_param_count[c_PARAM_D1] - 1);
    ui->spinBox_VisDispPlane_w1->setMaximum(v_param_count[c_PARAM_W1] - 1);
    ui->spinBox_VisDispPlane_d2->setMaximum(v_param_count[c_PARAM_D2] - 1);
    ui->spinBox_VisDispPlane_w2->setMaximum(v_param_count[c_PARAM_W2] - 1);
}

void D_MAKRO_CurveFitting::ParameterSpaceInit()
{
    //dim
    D_VisDat_Dim Dim_ParamSpace;
    Dim_ParamSpace.set_size_X(v_param_count[c_PARAM_D1]);
    Dim_ParamSpace.set_size_Y(v_param_count[c_PARAM_W1]);
    Dim_ParamSpace.set_size_Z(v_param_count[c_PARAM_D2]);
    Dim_ParamSpace.set_size_T(v_param_count[c_PARAM_W2]);
    Dim_ParamSpace.set_size_S(1);
    Dim_ParamSpace.set_size_P(1);

    //param space 4D img
    VD_ParamSpace = D_VisDat_Obj(Dim_ParamSpace, CV_64FC1);
}

void D_MAKRO_CurveFitting::FittingLoop()
{
    qDebug() << "FittingLoop" << "start";

    //confrim tries by user
    qDebug() << "FittingLoop" << "start";
    if(QMessageBox::question(
                this,
                "Start Fitting?",
                "This will try " + QString::number(param_space_size) + " parameter combinations.<br>It may take some time.<br>Start now?",
                QMessageBox::Yes | QMessageBox::No)
            != QMessageBox::Yes)
        return;

    //save?
    QDir DIR_Save;
    bool save = QMessageBox::question(
                this,
                "Save Results?",
                "Do you wan to save the results?"
                "<br>Each time a better fit is found is will be saved in selected folder.",
                QMessageBox::Yes | QMessageBox::No)
        == QMessageBox::Yes;
    if(save)
    {
        QString save_path = QFileDialog::getExistingDirectory(
                    this,
                    "Select Save Directory",
                    pStore->dir_M_RadonCurveFit()->path());
        if(save_path == 0)
            save = false;

        if(save)
        {
            DIR_Save.setPath(save_path);
            if(!DIR_Save.exists())
                QDir().mkdir(DIR_Save.path());

            pStore->set_dir_M_RadonCurveFit(DIR_Save.path());
        }
    }

    //stuff from ui
    bool    live_update = ui->action_Live_Preview->isChecked();
    int     opt_type    = ui->comboBox_FitOptimization->currentIndex();
    int     opt_stat    = ui->comboBox_FitStat->currentIndex();
    QString QS_opt_stat = ui->comboBox_FitStat->currentText();
    ui->label_out_score->setText(QS_opt_stat);

    //fit data points container
    qDebug() << "FittingLoop" << "fit data container";
    vector<vector<vector<double>>> vvv_data_fit;
    //data sets
    vvv_data_fit.resize(c_DATA_NUMBER_OF);
    for(int set = 0; set < c_DATA_NUMBER_OF; set++)
    {
        //points in data set
        vvv_data_fit[set].resize(v_number_of_points[set]);
        for(int p = 0; p < v_number_of_points[set]; p++)
        {
            //koordinates in point
            vvv_data_fit[set][p].resize(c_KOORD_NUMBER_OF, 0);
        }
    }

    //scores
    vector<double> v_measure;
    vector<double> v_fitting;
    vector<double> v_stat;
    double score_cur = D_Stat::Optimize_Init(opt_type);
    double score_opt = D_Stat::Optimize_Init(opt_type);

    //loop params
    qDebug() << "FittingLoop" << "start loop param sets";
    ui->action_Brealk_Loop->setChecked(false);
    unsigned long int try_counter = 0;
    for(            double d1 = v_param_min[c_PARAM_D1], i_d1 = 0; d1 <= v_param_max[c_PARAM_D1]; d1 += v_param_step[c_PARAM_D1], i_d1++)
        for(        double w1 = v_param_min[c_PARAM_W1], i_w1 = 0; w1 <= v_param_max[c_PARAM_W1]; w1 += v_param_step[c_PARAM_W1], i_w1++)
            for(    double d2 = v_param_min[c_PARAM_D2], i_d2 = 0; d2 <= v_param_max[c_PARAM_D2]; d2 += v_param_step[c_PARAM_D2], i_d2++)
                for(double w2 = v_param_min[c_PARAM_W2], i_w2 = 0; w2 <= v_param_max[c_PARAM_W2]; w2 += v_param_step[c_PARAM_W2], i_w2++)
                {
                    if(ui->action_Brealk_Loop->isChecked())
                        return;

                    try_counter++;
                    //qDebug() << "FittingLoop" << "ParamSet:" << "w1" << w1 << "- d1" << d1 << "- w2" << w2 << "- d2" << d2;

                    //new parameters set -> new fit
                    score_cur = 0;

                    //loop data sets
                    for(int set = 0; set < c_DATA_NUMBER_OF; set++)
                    {
                        v_measure.clear();
                        v_measure.resize(v_number_of_points[set]);
                        v_fitting.clear();
                        v_fitting.resize(v_number_of_points[set]);

                        //loop data points
                        for(int p = 0; p < v_number_of_points[set]; p++)
                        {
                            //koordinates measure/fit
                            double t            = vvv_Data_Set_TA[set][p][c_KOORD_T];
                            double a_measure    = vvv_Data_Set_TA[set][p][c_KOORD_A];
                            double a_fitting    = Franzi_Combi(t, w1, d1, w2, d2, set, true);

                            //save fit points for plot
                            vvv_data_fit[set][p][c_KOORD_T] = t;
                            vvv_data_fit[set][p][c_KOORD_A] = a_fitting;

                            //save points for calc score
                            v_fitting[p] = a_fitting;
                            v_measure[p] = a_measure;
                        }

                        //calc score
                        D_Stat::Calc_Stats_2D(
                                    &v_stat,
                                    v_fitting,
                                    v_measure);

                        //selecetd stat to cumulate to score
                        score_cur += v_stat[opt_stat] * v_data_score_weights[set];
                    }

                    //show current
                    v_param_cur_ui[c_PARAM_W1]->setText(QString::number(w1));
                    v_param_cur_ui[c_PARAM_D1]->setText(QString::number(d1));
                    v_param_cur_ui[c_PARAM_W2]->setText(QString::number(w2));
                    v_param_cur_ui[c_PARAM_D2]->setText(QString::number(d2));
                    ui->label_ResCur_SuReSq->setText(QString::number(static_cast<double>(score_cur)));

                    //export to param space
                    ParameterSpaceWrite(i_d1, i_w1, i_d2, i_w2, score_cur);

                    //new best score?
                    if(D_Stat::Optimize(score_cur, &score_opt, opt_type))
                    {
                        //remeber best pos in visualaization 4D
                        ui->spinBox_VisDispPlane_d1->setValue(i_d1);
                        ui->spinBox_VisDispPlane_w1->setValue(i_w1);
                        ui->spinBox_VisDispPlane_d2->setValue(i_d2);
                        ui->spinBox_VisDispPlane_w2->setValue(i_w2);

                        //show param & score
                        v_param_opt_ui[c_PARAM_W1]->setText(QString::number(w1));
                        v_param_opt_ui[c_PARAM_D1]->setText(QString::number(d1));
                        v_param_opt_ui[c_PARAM_W2]->setText(QString::number(w2));
                        v_param_opt_ui[c_PARAM_D2]->setText(QString::number(d2));
                        ui->label_ResOpt_SuReSq->setText(QString::number(static_cast<double>(score_cur)));

                        //adapt manual plot param to avoid confusion
                        ui->doubleSpinBox_Test_d1->blockSignals(true);
                        ui->doubleSpinBox_Test_w1->blockSignals(true);
                        ui->doubleSpinBox_Test_d2->blockSignals(true);
                        ui->doubleSpinBox_Test_w2->blockSignals(true);
                        ui->doubleSpinBox_Test_d1->setValue(d1);
                        ui->doubleSpinBox_Test_w1->setValue(w1);
                        ui->doubleSpinBox_Test_d2->setValue(d2);
                        ui->doubleSpinBox_Test_w2->setValue(w2);
                        ui->doubleSpinBox_Test_d1->blockSignals(false);
                        ui->doubleSpinBox_Test_w1->blockSignals(false);
                        ui->doubleSpinBox_Test_d2->blockSignals(false);
                        ui->doubleSpinBox_Test_w2->blockSignals(false);

                        //data for plot
                        vector<vector<vector<double>>> vvv_data_fit_plot;
                        vvv_data_fit_plot.resize(c_DATA_NUMBER_OF);
                        for(int set = 0; set < c_DATA_NUMBER_OF; set++)
                        {
                            for(int t = t_min; t <= t_max; t++)
                            {
                                bool past = true;
                                if(t <= 60)
                                    past = false;

                                //new point
                                vector<double> v_point;
                                v_point.resize(c_KOORD_NUMBER_OF);

                                //data of point
                                v_point[c_KOORD_T] = static_cast<double>(t);
                                v_point[c_KOORD_A] = Franzi_Combi(t, w1, d1, w2, d2, set, past);

                                //add point
                                vvv_data_fit_plot[set].push_back(v_point);
                            }
                        }

                        //plot
                        D_Plot::Plot_XY_Fit(
                                    pChartView,
                                    vvv_Data_Set_TA,
                                    vvv_data_fit_plot,
                                    "<b>Fit Visualization</b>"
                                    "<br>d1 = " + QString::number(d1) +
                                    "<br>w1 = " + QString::number(w1) +
                                    "<br>d2 = " + QString::number(d2) +
                                    "<br>w2 = " + QString::number(w2) +
                                    "<br>" + QS_opt_stat +  " = " + QString::number(static_cast<double>(score_cur)),
                                    QSL_DataSet,
                                    "Time (min)",
                                    "Activity");

                        pChartView->chart()->axisX()->setMin(t_min);
                        pChartView->chart()->axisX()->setMax(t_max);
                        pChartView->chart()->axisY()->setMax(a_display_min_max);

                        if(save)
                            pChartView->grab().save(DIR_Save.path() + "/Fit - Score_" + QString::number(score_cur, 'f', 6) + ".jpg");
                    }

                    //Update Ui
                    ui->progressBar_ParamLoop->setValue((static_cast<double>(try_counter) / static_cast<double>(param_space_size)) * ui->progressBar_ParamLoop->maximum());
                    if(live_update)
                        UpdateUi();
                }

    //save img of param space
    for(int pl = 0; pl < c_PLANE_DW_NUMBER_OF; pl++)
    {
        ui->comboBox_VisDispPlane_Plane->setCurrentIndex(pl);
        View_ParamSpace.Save_Image(DIR_Save.path() + "/ParamSpace PlaneAtBest " + QSL_PlanesDW[pl] + ".png");
    }

}

void D_MAKRO_CurveFitting::ParameterSpaceShow()
{
    //qDebug() << "ParameterSpaceShow";

    //dim pos
    vector<int> v_dim_pos;
    v_dim_pos.resize(c_DIM_NUMBER_OF, 0);
    v_dim_pos[c_PARAM_D1] = ui->spinBox_VisDispPlane_d1->value();
    v_dim_pos[c_PARAM_W1] = ui->spinBox_VisDispPlane_w1->value();
    v_dim_pos[c_PARAM_D2] = ui->spinBox_VisDispPlane_d2->value();
    v_dim_pos[c_PARAM_W2] = ui->spinBox_VisDispPlane_w2->value();

    //get extended dims
    int ext_dim_1;
    int ext_dim_2;

    switch (ui->comboBox_VisDispPlane_Plane->currentIndex()) {
    case c_PLANE_DW_D1_W1:    ext_dim_1 = c_PARAM_D1;    ext_dim_2 = c_PARAM_W1;    break;
    case c_PLANE_DW_D1_D2:    ext_dim_1 = c_PARAM_D1;    ext_dim_2 = c_PARAM_D2;    break;
    case c_PLANE_DW_D1_W2:    ext_dim_1 = c_PARAM_D1;    ext_dim_2 = c_PARAM_W2;    break;
    case c_PLANE_DW_W1_D2:    ext_dim_1 = c_PARAM_W1;    ext_dim_2 = c_PARAM_D2;    break;
    case c_PLANE_DW_W1_W2:    ext_dim_1 = c_PARAM_W1;    ext_dim_2 = c_PARAM_W2;    break;
    case c_PLANE_DW_D2_W2:    ext_dim_1 = c_PARAM_D2;    ext_dim_2 = c_PARAM_W2;    break;
    default:                                                                        break;}

    //extended or fixed position?
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(d == ext_dim_1 || d == ext_dim_2)
            v_dim_pos[d] = -1;

    //Crop 2D Plane from VD and put it to mat
    D_VisDat_Slice_2D Slice2d(v_dim_pos);
    ERR(D_VisDat_Proc::Read_2D_Plane(
                &MA_ParamSpaceSlice,
                &VD_ParamSpace,
                Slice2d),
        "ParameterSpaceShow",
        "Crop " + Slice2d.info() + " from " + VD_ParamSpace.Info_Dims());

    qDebug() << "ParameterSpaceShow" << Slice2d.info();

    //display Mat
    View_ParamSpace.Update_Image(&MA_ParamSpaceSlice);
    Update_View();
}

void D_MAKRO_CurveFitting::ParameterSpaceWrite(int i_d1, int i_w1, int i_d2, int i_w2, double val)
{
    Vec<int, 6> v_pos = {i_d1, i_w1, i_d2, i_w2, 0, 0};
    VD_ParamSpace.pMA_full()->at<double>(v_pos) = val;
}

void D_MAKRO_CurveFitting::Update_View()
{
    View_ParamSpace.Update_View();
}

void D_MAKRO_CurveFitting::PlotTest_PbBi()
{
    DataRead();

    //param from ui
    double w1 = ui->doubleSpinBox_Test_w1->value();
    double d1 = ui->doubleSpinBox_Test_d1->value();
    double w2 = ui->doubleSpinBox_Test_w2->value();
    double d2 = ui->doubleSpinBox_Test_d2->value();

    //data for plot
    vector<vector<vector<double>>> vvv_data_fit_plot;
    vvv_data_fit_plot.resize(c_DATA_NUMBER_OF);
    for(int set = 0; set < c_DATA_NUMBER_OF; set++)
    {
        for(int t = t_min; t <= t_max; t++)
        {
            bool past = true;
            if(t <= 60)
                past = false;

            //new point
            vector<double> v_point;
            v_point.resize(c_KOORD_NUMBER_OF);

            //data of point
            v_point[c_KOORD_T] = static_cast<double>(t);
            v_point[c_KOORD_A] = Franzi_Combi(t, w1, d1, w2, d2, set, past);

            //add point
            vvv_data_fit_plot[set].push_back(v_point);
        }
    }

    //plot
    D_Plot::Plot_XY_Fit(
                pChartView,
                vvv_Data_Set_TA,
                vvv_data_fit_plot,
                "<b>Fit Visualization</b>"
                "<br>d1 = " + QString::number(d1) +
                "<br>w1 = " + QString::number(w1) +
                "<br>d2 = " + QString::number(d2) +
                "<br>w2 = " + QString::number(w2),
                QSL_DataSet,
                "Time (min)",
                "Activity");

    pChartView->chart()->axisX()->setMin(t_min);
    pChartView->chart()->axisX()->setMax(t_max);
    pChartView->chart()->axisY()->setMax(a_display_min_max);
}

//-------------------------------------------------------------------------------------- Test

long double D_MAKRO_CurveFitting::Test_Combi(long double t, long double w1, long double d1, long double w2, long double d2, int set)
{
    switch (set) {

    case c_DATA_PB_295:     return Test_F3_Pb(t, w1, d1, w2, d2);
    case c_DATA_PB_352:     return Test_F3_Pb(t, w1, d1, w2, d2);
    case c_DATA_BI:         return Test_F4_Bi(t, w1, d1, w2, d2);
    default:                return NAN;}
}

long double D_MAKRO_CurveFitting::Test_F3_Pb(long double t, long double w1, long double d1, long double w2, long double d2)
{
    w2;
    d2;
    t -= d1;
    return w1 * t * t;
}

long double D_MAKRO_CurveFitting::Test_F4_Bi(long double t, long double w1, long double d1, long double w2, long double d2)
{
    w1;
    d1;
    t -= d2;
    return w2 * t * t;
}

//-------------------------------------------------------------------------------------- Franzi

long double D_MAKRO_CurveFitting::Franzi_Combi(long double t, long double w1, long double d1, long double w2, long double d2, int set, bool past)
{
    //this is called

    //t^-1

    if(past)
    {
        t = t - 60;

        switch (set) {

        case c_DATA_PB_295:     return Franzi_Pb_Combi(t, w1, d1, w2, d2);
        case c_DATA_PB_352:     return Franzi_Pb_Combi(t, w1, d1, w2, d2);
        case c_DATA_BI:         return Franzi_Bi_Combi(t, w1, d1, w2, d2);
        default:                return NAN;}
    }
    else
    {
        //return 0;

        switch (set) {

        case c_DATA_PB_295:     return l3 * (w1 * Franzi_n3_Pb_pre60min(t, d1) + w2 * Franzi_n3_Pb_pre60min(t, d2));
        case c_DATA_PB_352:     return l3 * (w1 * Franzi_n3_Pb_pre60min(t, d1) + w2 * Franzi_n3_Pb_pre60min(t, d2));
        case c_DATA_BI:         return l4 * (w1 * Franzi_n4_Bi_pre60min(t, d1) + w2 * Franzi_n4_Bi_pre60min(t, d2));
        default:                return NAN;}
    }
}

long double D_MAKRO_CurveFitting::Franzi_Pb_Combi(long double t, long double w1, long double d1, long double w2, long double d2)
{
    //t^-1
    return
            l3 *
            (w1 * Franzi_n3_Pb_past60min_single(t, d1) +
             w2 * Franzi_n3_Pb_past60min_single(t, d2));
}

long double D_MAKRO_CurveFitting::Franzi_Bi_Combi(long double t, long double w1, long double d1, long double w2, long double d2)
{
    //t^-1
    return
            l4 *
            (w1 * Franzi_n4_Bi_past60min_single(t, d1) +
             w2 * Franzi_n4_Bi_past60min_single(t, d2));
}

long double D_MAKRO_CurveFitting::Franzi_n1_Rn_pre60min(long double t, long double ld)
{
    //t
    return
            (1 - expl(-1 * ((l1 + ld) * (t))))
            /
            (l1 + ld);
}

long double D_MAKRO_CurveFitting::Franzi_n2_Po_pre60min(long double t, long double ld)
{
    //t
    return
            (expl(-(l1 + (l2) + ld) * t) * l1 * (expl(l2 * t) * (l2) - expl((l1 + ld) * t) * (l1 + ld) +  expl((l1 + (l2) + ld) * t) * (l1 - (l2) + ld)))
            /
            (l2 * (l1 + ld) * (l1 - (l2) + ld));
}

long double D_MAKRO_CurveFitting::Franzi_n3_Pb_pre60min(long double t, long double ld)
{
    //t
    return (
            expl(-(l1 + (l2) + (l3) + ld) * t)   * l1 *
           (-expl((l2 + (l3)) * t)               * (l2)              * (l2 - (l3))           * (l3) +
            expl((l1 + (l2) + (l3) + ld) * t)    * (l2 - (l3))       * (-l1 + (l2) - ld)     * (-l1 + (l3) - ld) +
            expl((l1 + (l2) + ld) * t)           * (l2)              * (-l1 + (l2) - ld)     * (l1 + ld) -
            expl((l1 + (l3) + ld) * t)           * (l3)              * (-l1 + (l3) - ld)     * (l1 + ld)))
            /
            (((l2) - (l3)) * (l3) * (-l1 + (l2) - ld) * (-l1 + (l3) - ld) * (l1 + ld));
}

long double D_MAKRO_CurveFitting::Franzi_n4_Bi_pre60min(long double t, long double ld)
{
    //t
    return (
             expl(-( l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))                                                                  * l1 *
          (- expl((           l2 +   (l3) +  (l4))       * (t))      * (l2 * l2 * l2)    * (l3 * l3)         * (l4) +
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2 * l2 * l2)    * (l3 * l3)         * (l4) +
             expl((          (l2) +  (l3) +  (l4))       * (t))      * (l2 * l2)         * (l3 * l3 * l3)    * (l4) -
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2 * l2)         * (l3 * l3 * l3)    * (l4) +
             expl((          (l2) +  (l3) +  (l4))       * (t))      * (l2 * l2 * l2)    * (l3)              * (l4 * l4) -
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2 * l2 * l2)    * (l3)              * (l4 * l4) -
             expl((          (l2) +  (l3) +  (l4))       * (t))      * (l2)              * (l3 * l3 * l3)    * (l4 * l4) +
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2)              * (l3 * l3 * l3)    * (l4 * l4) -
             expl((          (l2) +  (l3) +  (l4))       * (t))      * (l2 * l2)         * (l3)              * (l4 * l4 * l4) +
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2 * l2)         * (l3)              * (l4 * l4 * l4) +
             expl((          (l2) +  (l3) +  (l4))       * (t))      * (l2)              * (l3 * l3)         * (l4 * l4 * l4) -
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2)              * (l3 * l3)         * (l4 * l4 * l4) +
             expl((  l1 +    (l2) +  (l3) +          ld) * (t))      * (l2 * l2 * l2)    * (l3 * l3)                             * (l1 + ld) -
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2 * l2 * l2)    * (l3 * l3)                             * (l1 + ld) -
             expl((  l1 +    (l2) +  (l3) +          ld) * (t))      * (l2 * l2)         * (l3 * l3 * l3)                        * (l1 + ld) +
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2 * l2)         * (l3 * l3 * l3)                        * (l1 + ld) -
             expl((  l1 +    (l2) +          (l4) +  ld) * (t))      * (l2 * l2 * l2)                        * (l4 * l4)         * (l1 + ld) +
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2 * l2 * l2)                        * (l4 * l4)         * (l1 + ld) +
             expl((  l1 +            (l3) +  (l4) +  ld) * (t))                          * (l3 * l3 * l3)    * (l4 * l4)         * (l1 + ld) -
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))                          * (l3 * l3 * l3)    * (l4 * l4)         * (l1 + ld) +
             expl((  l1 +    (l2) +          (l4) +  ld) * (t))      * (l2 * l2)                             * (l4 * l4 * l4)    * (l1 + ld) -
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2 * l2)                             * (l4 * l4 * l4)    * (l1 + ld) -
             expl((  l1 +            (l3) +  (l4) +  ld) * (t))                          * (l3 * l3)         * (l4 * l4 * l4)    * (l1 + ld) +
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))                          * (l3 * l3)         * (l4 * l4 * l4)    * (l1 + ld) -
             expl((  l1 +    (l2) +  (l3) +          ld) * (t))      * (l2 * l2 * l2)    * (l3)                                  * (l1 + ld) * (l1 + ld) +
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2 * l2 * l2)    * (l3)                                  * (l1 + ld) * (l1 + ld) +
             expl((  l1 +    (l2) +  (l3) +          ld) * (t))      * (l2)              * (l3 * l3 * l3)                        * (l1 + ld) * (l1 + ld) -
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2)              * (l3 * l3 * l3)                        * (l1 + ld) * (l1 + ld) +
             expl((  l1 +    (l2) +          (l4) +  ld) * (t))      * (l2 * l2 * l2)                        * (l4)              * (l1 + ld) * (l1 + ld) -
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2 * l2 * l2)                        * (l4)              * (l1 + ld) * (l1 + ld) -
             expl((  l1 +            (l3) +  (l4) +  ld) * (t))                          * (l3 * l3 * l3)    * (l4)              * (l1 + ld) * (l1 + ld) +
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))                          * (l3 * l3 * l3)    * (l4)              * (l1 + ld) * (l1 + ld) -
             expl((  l1 +    (l2) +          (l4) +  ld) * (t))      * (l2)                                  * (l4 * l4 * l4)    * (l1 + ld) * (l1 + ld) +
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2)                                  * (l4 * l4 * l4)    * (l1 + ld) * (l1 + ld) +
             expl((  l1 +            (l3) +  (l4) +  ld) * (t))                          * (l3)              *(l4 * l4 * l4)     * (l1 + ld) * (l1 + ld) -
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))                          * (l3)              * (l4 * l4 * l4)    * (l1 + ld) * (l1 + ld) +
             expl((  l1 +    (l2) +  (l3) +          ld) * (t))      * (l2 * l2)         * (l3)                                  * (l1 + ld) * (l1 + ld) * (l1 + ld) -
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2 * l2)         * (l3)                                  * (l1 + ld) * (l1 + ld) * (l1 + ld) -
             expl((  l1 +    (l2) +  (l3) +          ld) * (t))      * (l2)              * (l3 * l3)                             * (l1 + ld) * (l1 + ld) * (l1 + ld) +
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2)              * (l3 * l3)                             * (l1 + ld) * (l1 + ld) * (l1 + ld) -
             expl((  l1 +    (l2) +          (l4) +  ld) * (t))      * (l2 * l2)                             * (l4)              * (l1 + ld) * (l1 + ld) * (l1 + ld) +
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2 * l2)                             * (l4)              * (l1 + ld) * (l1 + ld) * (l1 + ld) +
             expl((  l1 +            (l3) +  (l4) +  ld) * (t))                          * (l3 * l3)         * (l4)              * (l1 + ld) * (l1 + ld) * (l1 + ld) -
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))                          * (l3 * l3)         * (l4)              * (l1 + ld) * (l1 + ld) * (l1 + ld) +
             expl((  l1 +    (l2) +          (l4) +  ld) * (t))      * (l2)                                  * (l4 * l4)         * (l1 + ld) * (l1 + ld) * (l1 + ld) -
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l2)                                  * (l4 * l4)         * (l1 + ld) * (l1 + ld) * (l1 + ld) -
             expl((  l1 +            (l3) +  (l4) +  ld) * (t))      * (l3)                                  * (l4 * l4)         * (l1 + ld) * (l1 + ld) * (l1 + ld) +
             expl((  l1 +    (l2) +  (l3) +  (l4) +  ld) * (t))      * (l3)                                  * (l4 * l4)         * (l1 + ld) * (l1 + ld) * (l1 + ld)))
            /
            (
                (l2 - (l3)) *
                (l2 - (l4)) *
                (l3 - (l4)) *
                (l4) *
                (-l1 + (l2) - ld) *
                (-l1 + (l3) - ld) *
                (-l1 + (l4) - ld) *
                (l1 + ld)
            );
}

long double D_MAKRO_CurveFitting::Franzi_n1_Rn_past60min(long double t, long double ld, long double n10)
{
    return expl(-(l1 + ld) * t) * (n10);
}

long double D_MAKRO_CurveFitting::Franzi_n2_Po_past60min(long double t, long double ld, long double n10, long double n20)
{
    return
    (expl(-l2 * t - (l1 + ld) * t) * (expl(l2 * t) * l1 * (n10) -
     expl((l1 + ld) * t) * l1 * (n10) +
     expl((l1 + ld) * t) * (l2) * (n20) -
     expl((l1 + ld) * t) *(l1 + ld) * (n20)))
     /
     (-l1 + (l2) - ld);
}

long double D_MAKRO_CurveFitting::Franzi_n3_Pb_past60min(long double t, long double ld, long double n10, long double n20, long double n30)
{
    return
            (1
            /
            ((l2 - (l3)) * (-(l1) + (l2) - ld) * (-(l1) + (l3) - ld)))
            *
            expl(-l2 * (t) - (l3) * (t) - ((l1) + ld) * (t)) * (expl(l2 * (t) + (l3) * (t)) * (l1) * (l2 * l2) * (n10) -
            expl(l2 * (t) + ((l1) + ld) * (t)) * (l1) * (l2 * l2) * (n10) -
            expl(l2 * (t) + (l3) * (t)) * (l1) * (l2) * (l3) * (n10) +
            expl(l3 * (t) + ((l1) + ld) * (t)) * (l1) * (l2) * (l3) * (n10) +
            expl(l2 * (t) + ((l1) + ld) * (t)) * (l1) * (l2) * ((l1) + ld) * (n10) -
            expl(l3 * (t) + ((l1) + ld) * (t)) * (l1) * (l2) * ((l1) + ld) * (n10) +
            expl(l2 * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3) * (n20) -
            expl(l3 * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3) * (n20) -
            expl(l2 * (t) + ((l1) + ld) * (t)) * (l2 * l2) * ((l1) + ld) * (n20) +
            expl(l3 * (t) + ((l1) + ld) * (t)) * (l2 * l2) * ((l1) + ld) * (n20) -
            expl(l2 * (t) + ((l1) + ld) * (t)) * (l2) * (l3) * ((l1) + ld) * (n20) +
            expl(l3 * (t) + ((l1) + ld) * (t)) * (l2) * (l3) * ((l1) + ld) * (n20) +
            expl(l2 * (t) + ((l1) + ld) * (t)) * (l2) * ((l1 + ld) * (l1 + ld)) * (n20) -
            expl(l3 * (t) + ((l1) + ld) * (t)) * (l2) * ((l1 + ld) * (l1 + ld)) * (n20) +
            expl(l2 * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3) * (n30) -
            expl(l2 * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3) * (n30) -
            expl(l2 * (t) + ((l1) + ld) * (t)) * (l2 * l2) * ((l1) + ld) * (n30) +
            expl(l2 * (t) + ((l1) + ld) * (t)) * (l3 * l3) * ((l1) + ld) * (n30) +
            expl(l2 * (t) + ((l1) + ld) * (t)) * (l2) * ((l1 + ld) * (l1 + ld)) * (n30) -
            expl(l2 * (t) + ((l1) + ld) * (t)) * (l3) * ((l1 + ld) * (l1 + ld)) * (n30));
}

long double D_MAKRO_CurveFitting::Franzi_n4_Bi_past60min(long double t, long double ld, long double n10, long double n20, long double n30, long double n40)
{
    return
           (expl(-l2 * (t) - (l3) * (t) - (l4) * (t) - ((l1) + ld) * (t))
            *
           (expl(l2 * (t) + (l3) * (t) + (l4) * (t)) * (l1) * (l2 * l2 * l2) * (l3 * l3) * (n10) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l1) * (l2 * l2 * l2) * (l3 * l3) * (n10) -
            expl(l2 * (t) + (l3) * (t) + (l4) * (t)) * (l1) * (l2 * l2) * (l3 * l3 * l3) * (n10) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l1) * (l2 * l2) * (l3 * l3 * l3) * (n10) -
            expl(l2 * (t) + (l3) * (t) + (l4) * (t)) * (l1) * (l2 * l2 * l2) * (l3) * (l4) * (n10) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l1) * (l2 * l2 * l2) * (l3) * (l4) * (n10) +
            expl(l2 * (t) + (l3) * (t) + (l4) * (t)) * (l1) * (l2) * (l3 * l3 * l3) * (l4) * (n10) -
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l1) * (l2) * (l3 * l3 * l3) * (l4) * (n10) +
            expl(l2 * (t) + (l3) * (t) + (l4) * (t)) * (l1) * (l2 * l2) * (l3) * (l4 * l4) * (n10) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l1) * (l2 * l2) * (l3) * (l4 * l4) * (n10) -
            expl(l2 * (t) + (l3) * (t) + (l4) * (t)) * (l1) * (l2) * (l3 * l3) * (l4 * l4) * (n10) +
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l1) * (l2) * (l3 * l3) * (l4 * l4) * (n10) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l1) * (l2 * l2 * l2) * (l3) * ((l1) + ld) * (n10) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l1) * (l2 * l2 * l2) * (l3) * ((l1) + ld) * (n10) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l1) * (l2) * (l3 * l3 * l3) * ((l1) + ld) * (n10) +
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l1) * (l2) * (l3 * l3 * l3) * ((l1) + ld) * (n10) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l1) * (l2) * (l3) * (l4 * l4) * ((l1) + ld) * (n10) -
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l1) * (l2) * (l3) * (l4 * l4) * ((l1) + ld) * (n10) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l1) * (l2 * l2) * (l3) * ((l1 + ld) * (l1 + ld)) * (n10) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l1) * (l2 * l2) * (l3) * ((l1 + ld) * (l1 + ld)) * (n10) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l1) * (l2) * (l3 * l3) * ((l1 + ld) * (l1 + ld)) * (n10) -
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l1) * (l2) * (l3 * l3) * ((l1 + ld) * (l1 + ld)) * (n10) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l1) * (l2) * (l3) * (l4) * ((l1 + ld) * (l1 + ld)) * (n10) +
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l1) * (l2) * (l3) * (l4) * ((l1 + ld) * (l1 + ld)) * (n10) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3 * l3) * (l4) * (n20) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3 * l3) * (l4) * (n20) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3 * l3) * (l4) * (n20) +
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3 * l3) * (l4) * (n20) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3) * (l4 * l4) * (n20) -
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3) * (l4 * l4) * (n20) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3 * l3) * ((l1) + ld) * (n20) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3 * l3) * ((l1) + ld) * (n20) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3 * l3) * ((l1) + ld) * (n20) -
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3 * l3) * ((l1) + ld) * (n20) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3) * (l4) * ((l1) + ld) * (n20) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3) * (l4) * ((l1) + ld) * (n20) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3 * l3) * (l4) * ((l1) + ld) * (n20) -
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3 * l3) * (l4) * ((l1) + ld) * (n20) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3) * (l4 * l4) * ((l1) + ld) * (n20) +
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3) * (l4 * l4) * ((l1) + ld) * (n20) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3) * (l4 * l4) * ((l1) + ld) * (n20) +
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3) * (l4 * l4) * ((l1) + ld) * (n20) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3) * ((l1 + ld) * (l1 + ld)) * (n20) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3) * ((l1 + ld) * (l1 + ld)) * (n20) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3) * ((l1 + ld) * (l1 + ld)) * (n20) +
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3) * ((l1 + ld) * (l1 + ld)) * (n20) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3 * l3) * ((l1 + ld) * (l1 + ld)) * (n20) +
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3 * l3) * ((l1 + ld) * (l1 + ld)) * (n20) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3) * (l4) * ((l1 + ld) * (l1 + ld)) * (n20) -
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3) * (l4) * ((l1 + ld) * (l1 + ld)) * (n20) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3) * (l4) * ((l1 + ld) * (l1 + ld)) * (n20) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3) * (l4) * ((l1 + ld) * (l1 + ld)) * (n20) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2) * (l3) * (l4 * l4) * ((l1 + ld) * (l1 + ld)) * (n20) -
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2) * (l3) * (l4 * l4) * ((l1 + ld) * (l1 + ld)) * (n20) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n20) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n20) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n20) -
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n20) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2) * (l3) * (l4) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n20) +
            expl(l3 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2) * (l3) * (l4) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n20) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3 * l3) * (l4) * (n30) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3 * l3) * (l4) * (n30) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3 * l3) * (l4) * (n30) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3 * l3) * (l4) * (n30) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3) * (l4 * l4) * (n30) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3) * (l4 * l4) * (n30) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3 * l3) * (l4 * l4) * (n30) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3 * l3) * (l4 * l4) * (n30) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3 * l3) * ((l1) + ld) * (n30) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3 * l3) * ((l1) + ld) * (n30) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3 * l3) * ((l1) + ld) * (n30) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3 * l3) * ((l1) + ld) * (n30) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3) * (l4) * ((l1) + ld) * (n30) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3) * (l4) * ((l1) + ld) * (n30) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3) * (l4) * ((l1) + ld) * (n30) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3) * (l4) * ((l1) + ld) * (n30) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3) * (l4 * l4) * ((l1) + ld) * (n30) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3) * (l4 * l4) * ((l1) + ld) * (n30) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l3 * l3 * l3) * (l4 * l4) * ((l1) + ld) * (n30) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l3 * l3 * l3) * (l4 * l4) * ((l1) + ld) * (n30) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3) * ((l1 + ld) * (l1 + ld)) * (n30) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3) * ((l1 + ld) * (l1 + ld)) * (n30) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3 * l3) * ((l1 + ld) * (l1 + ld)) * (n30) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3 * l3) * ((l1 + ld) * (l1 + ld)) * (n30) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3) * (l4) * ((l1 + ld) * (l1 + ld)) * (n30) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3) * (l4) * ((l1 + ld) * (l1 + ld)) * (n30) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l3 * l3 * l3) * (l4) * ((l1 + ld) * (l1 + ld)) * (n30) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l3 * l3 * l3) * (l4) * ((l1 + ld) * (l1 + ld)) * (n30) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2) * (l3) * (l4 * l4) * ((l1 + ld) * (l1 + ld)) * (n30) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2) * (l3) * (l4 * l4) * ((l1 + ld) * (l1 + ld)) * (n30) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l3 * l3) * (l4 * l4) * ((l1 + ld) * (l1 + ld)) * (n30) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l3 * l3) * (l4 * l4) * ((l1 + ld) * (l1 + ld)) * (n30) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n30) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n30) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n30) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n30) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2) * (l3) * (l4) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n30) -
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l2) * (l3) * (l4) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n30) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l3 * l3) * (l4) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n30) +
            expl(l2 * (t) + (l4) * (t) + ((l1) + ld) * (t)) * (l3 * l3) * (l4) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n30) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3 * l3) * (l4) * (n40) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3 * l3) * (l4) * (n40) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3) * (l4 * l4) * (n40) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3 * l3) * (l4 * l4) * (n40) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3) * (l4 * l4 * l4) * (n40) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3) * (l4 * l4 * l4) * (n40) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3 * l3) * ((l1) + ld) * (n40) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3 * l3 * l3) * ((l1) + ld) * (n40) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l4 * l4) * ((l1) + ld) * (n40) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l3 * l3 * l3) * (l4 * l4) * ((l1) + ld) * (n40) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l4 * l4 * l4) * ((l1) + ld) * (n40) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l3 * l3) * (l4 * l4 * l4) * ((l1) + ld) * (n40) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l3) * ((l1 + ld) * (l1 + ld)) * (n40) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3 * l3) * ((l1 + ld) * (l1 + ld)) * (n40) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2 * l2) * (l4) * ((l1 + ld) * (l1 + ld)) * (n40) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l3 * l3 * l3) * (l4) * ((l1 + ld) * (l1 + ld)) * (n40) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2) * (l4 * l4 * l4) * ((l1 + ld) * (l1 + ld)) * (n40) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l3) * (l4 * l4 * l4) * ((l1 + ld) * (l1 + ld)) * (n40) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l3) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n40) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2) * (l3 * l3) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n40) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2 * l2) * (l4) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n40) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l3 * l3) * (l4) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n40) -
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l2) * (l4 * l4) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n40) +
            expl(l2 * (t) + (l3) * (t) + ((l1) + ld) * (t)) * (l3) * (l4 * l4) * ((l1 + ld) * (l1 + ld) * (l1 + ld)) * (n40)))
            /
            ((l2 - (l3)) * (l2 - (l4)) * (l3 - (l4)) * (-(l1) + (l2) - ld) * (-(l1) + (l3) - ld) * (-(l1) + (l4) - ld));
}

long double D_MAKRO_CurveFitting::Franzi_n1_Rn_past60min_single(long double t, long double ld)
{
    return Franzi_n1_Rn_past60min(
                t,
                ld,
                Franzi_n10_Rn_60min_single(ld));
}

long double D_MAKRO_CurveFitting::Franzi_n2_Po_past60min_single(long double t, long double ld)
{
    return Franzi_n2_Po_past60min(
                t,
                ld,
                Franzi_n10_Rn_60min_single(ld),
                Franzi_n20_Po_60min_single(ld));
}

long double D_MAKRO_CurveFitting::Franzi_n3_Pb_past60min_single(long double t, long double ld)
{
    return Franzi_n3_Pb_past60min(
                t,
                ld,
                Franzi_n10_Rn_60min_single(ld),
                Franzi_n20_Po_60min_single(ld),
                Franzi_n30_Pb_60min_single(ld));
}

long double D_MAKRO_CurveFitting::Franzi_n4_Bi_past60min_single(long double t, long double ld)
{
    return Franzi_n4_Bi_past60min(
                t,
                ld,
                Franzi_n10_Rn_60min_single(ld),
                Franzi_n20_Po_60min_single(ld),
                Franzi_n30_Pb_60min_single(ld),
                Franzi_n40_Bi_60min_single(ld));
}

long double D_MAKRO_CurveFitting::Franzi_n10_Rn_60min(long double w1, long double d1, long double w2, long double d2)
{
    //1
    return
            w1 * Franzi_n1_Rn_pre60min(t_fix, d1) +
            w2 * Franzi_n1_Rn_pre60min(t_fix, d2);
}

long double D_MAKRO_CurveFitting::Franzi_n20_Po_60min(long double w1, long double d1, long double w2, long double d2)
{
    //1
    return
            w1 * Franzi_n2_Po_pre60min(t_fix, d1) +
            w2 * Franzi_n2_Po_pre60min(t_fix, d2);
}

long double D_MAKRO_CurveFitting::Franzi_n30_Pb_60min(long double w1, long double d1, long double w2, long double d2)
{
    //1
    return
            w1 * Franzi_n3_Pb_pre60min(t_fix, d1) +
            w2 * Franzi_n3_Pb_pre60min(t_fix, d2);
}

long double D_MAKRO_CurveFitting::Franzi_n40_Bi_60min(long double w1, long double d1, long double w2, long double d2)
{
    //1
    return
            w1 * Franzi_n4_Bi_pre60min(t_fix, d1) +
            w2 * Franzi_n4_Bi_pre60min(t_fix, d2);
}

long double D_MAKRO_CurveFitting::Franzi_n10_Rn_60min_single(long double ld)
{
    //1
    return Franzi_n1_Rn_pre60min(t_fix, ld);
}

long double D_MAKRO_CurveFitting::Franzi_n20_Po_60min_single(long double ld)
{
    //1
    return Franzi_n2_Po_pre60min(t_fix, ld);
}

long double D_MAKRO_CurveFitting::Franzi_n30_Pb_60min_single(long double ld)
{
    //1
    return Franzi_n3_Pb_pre60min(t_fix, ld);
}

long double D_MAKRO_CurveFitting::Franzi_n40_Bi_60min_single(long double ld)
{
    //1
    return Franzi_n4_Bi_pre60min(t_fix, ld);
}

//-------------------------------------------------------------------------------------- Error handling

void D_MAKRO_CurveFitting::ERR(int err, QString func, QString detail)
{
    ER.ERR(
                err,
                "D_MAKRO_DnaFibers",
                func,
                detail);
}

void D_MAKRO_CurveFitting::on_doubleSpinBox_step_d1_valueChanged(double arg1)
{
    ui->doubleSpinBox_max_d1->setSingleStep(arg1);
    ui->doubleSpinBox_min_d1->setSingleStep(arg1);
    ui->doubleSpinBox_Test_d1->setSingleStep(arg1);
}

void D_MAKRO_CurveFitting::on_doubleSpinBox_step_w1_valueChanged(double arg1)
{
    ui->doubleSpinBox_max_w1->setSingleStep(arg1);
    ui->doubleSpinBox_min_w1->setSingleStep(arg1);
    ui->doubleSpinBox_Test_w1->setSingleStep(arg1);
}

void D_MAKRO_CurveFitting::on_doubleSpinBox_step_d2_valueChanged(double arg1)
{
    ui->doubleSpinBox_max_d2->setSingleStep(arg1);
    ui->doubleSpinBox_min_d2->setSingleStep(arg1);
    ui->doubleSpinBox_Test_d2->setSingleStep(arg1);
}

void D_MAKRO_CurveFitting::on_doubleSpinBox_step_w2_valueChanged(double arg1)
{
    ui->doubleSpinBox_max_w2->setSingleStep(arg1);
    ui->doubleSpinBox_min_w2->setSingleStep(arg1);
    ui->doubleSpinBox_Test_w2->setSingleStep(arg1);
}



void D_MAKRO_CurveFitting::on_doubleSpinBox_range_t_max_valueChanged(double arg1)
{
    t_max = arg1;
}

void D_MAKRO_CurveFitting::on_doubleSpinBox_range_a_max_valueChanged(double arg1)
{
    a_display_min_max = arg1;
}

void D_MAKRO_CurveFitting::on_spinBox_VisDispPlane_d1_valueChanged(int arg1)
{
    ui->spinBox_VisDispPlane_d1->setSuffix(" (" + QString::number(v_param_min[c_PARAM_D1] + v_param_step[c_PARAM_D1] * arg1, 'g', 6) + ")");
}

void D_MAKRO_CurveFitting::on_spinBox_VisDispPlane_w1_valueChanged(int arg1)
{
    ui->spinBox_VisDispPlane_w1->setSuffix(" (" + QString::number(v_param_min[c_PARAM_W1] + v_param_step[c_PARAM_W1] * arg1, 'g', 6) + ")");
}

void D_MAKRO_CurveFitting::on_spinBox_VisDispPlane_d2_valueChanged(int arg1)
{
    ui->spinBox_VisDispPlane_d2->setSuffix(" (" + QString::number(v_param_min[c_PARAM_D2] + v_param_step[c_PARAM_D2] * arg1, 'g', 6) + ")");
}

void D_MAKRO_CurveFitting::on_spinBox_VisDispPlane_w2_valueChanged(int arg1)
{
    ui->spinBox_VisDispPlane_w2->setSuffix(" (" + QString::number(v_param_min[c_PARAM_W2] + v_param_step[c_PARAM_W2] * arg1, 'g', 6) + ")");
}

void D_MAKRO_CurveFitting::on_comboBox_VisDispPlane_Plane_currentIndexChanged(int index)
{
    switch (index) {

    case c_PLANE_DW_D1_W1:
        ui->spinBox_VisDispPlane_d1->setEnabled(false);
        ui->spinBox_VisDispPlane_w1->setEnabled(false);
        ui->spinBox_VisDispPlane_d2->setEnabled(true);
        ui->spinBox_VisDispPlane_w2->setEnabled(true);
        break;

    case c_PLANE_DW_D1_D2:
        ui->spinBox_VisDispPlane_d1->setEnabled(false);
        ui->spinBox_VisDispPlane_w1->setEnabled(true);
        ui->spinBox_VisDispPlane_d2->setEnabled(false);
        ui->spinBox_VisDispPlane_w2->setEnabled(true);
        break;

    case c_PLANE_DW_D1_W2:
        ui->spinBox_VisDispPlane_d1->setEnabled(false);
        ui->spinBox_VisDispPlane_w1->setEnabled(true);
        ui->spinBox_VisDispPlane_d2->setEnabled(true);
        ui->spinBox_VisDispPlane_w2->setEnabled(false);
        break;

    case c_PLANE_DW_W1_D2:
        ui->spinBox_VisDispPlane_d1->setEnabled(true);
        ui->spinBox_VisDispPlane_w1->setEnabled(false);
        ui->spinBox_VisDispPlane_d2->setEnabled(false);
        ui->spinBox_VisDispPlane_w2->setEnabled(true);
        break;

    case c_PLANE_DW_W1_W2:
        ui->spinBox_VisDispPlane_d1->setEnabled(true);
        ui->spinBox_VisDispPlane_w1->setEnabled(false);
        ui->spinBox_VisDispPlane_d2->setEnabled(true);
        ui->spinBox_VisDispPlane_w2->setEnabled(false);
        break;

    case c_PLANE_DW_D2_W2:
        ui->spinBox_VisDispPlane_d1->setEnabled(true);
        ui->spinBox_VisDispPlane_w1->setEnabled(true);
        ui->spinBox_VisDispPlane_d2->setEnabled(false);
        ui->spinBox_VisDispPlane_w2->setEnabled(false);
        break;

    default:
        break;
    }
}
