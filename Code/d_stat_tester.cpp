/************************************
 *   added:     30.10.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_stat_tester.h"
#include "ui_d_stat_tester.h"

D_stat_tester::D_stat_tester(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_stat_tester)
{
    ui->setupUi(this);

    TableCircOut.set_TW(ui->tableWidget_Output);

    ui->graphicsView_Hist->setScene(&SC_Hist);

    x_min = ui->spinBox_Init_X_Min->value();
    x_max = ui->spinBox_Init_X_Max->value();
    y_min = 0;
    y_max = ui->spinBox_Init_Y_Max->value();
    y_pos_clk = y_max;


    connect(ui->pushButton_Init_Hist,   SIGNAL(clicked(bool)),          this,   SLOT(Init_ImageHist()));
    connect(&SC_Hist,                   SIGNAL(mouseMoved(int,int)),    this,   SLOT(Position_Clicked(int,int)));
    connect(ui->plainTextEdit_Input,    SIGNAL(textChanged()),          this,   SLOT(Update_CircStats()));


    setWindowTitle("ImageD - Stat Tester");
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    Init_ImageHist();


    Update_CircStats();
}

D_stat_tester::~D_stat_tester()
{
    delete ui;
}

void D_stat_tester::Init_ImageHist()
{
    y_pos_clk = y_max;
    x_pos_clk = 0;

    w_hist = x_max - x_min + 1;
    h_hist = y_max + 1;

    QI_Hist = QImage(
                w_hist,
                h_hist,
                QImage::Format_Grayscale8);

    QI_Hist.fill(0);
    uchar *line = QI_Hist.scanLine(y_max);
    for(int x = 0; x < w_hist; x++)
        line[x] = 255;

    v_hist.clear();
    v_hist.resize(w_hist, 0);

    ui->label_View_X_Min->setText(QString::number(x_min));
    ui->label_View_X_Max->setText(QString::number(x_max));
    ui->label_View_Y_Max->setText(QString::number(y_max));

    v_data.clear();
    Update_Data2Stats();
    Update_View_Image();
}

void D_stat_tester::Position_Clicked(int x, int y)
{
    //scale
    x /= x_factor;
    y /= y_factor;

    //in range?
    if(x < 0 || x >= w_hist || y < 0 || y >= h_hist)
        return;

    //pos changed?
    if(x == x_pos_clk && y == y_pos_clk)
        return;

    //position
    x_pos_clk = x;
    y_pos_clk = y;

    //value
    x_val_clk = x + x_min;
    y_val_clk = y_max - y;

    Update_ImageHist();
}

void D_stat_tester::Update_ImageHist()
{
    Update_Image();
    Update_Hist();
}

void D_stat_tester::Update_Image()
{
    uchar *line;
    for(int y = 0; y < h_hist; y++)
    {
        line = QI_Hist.scanLine(y);
        if(y < y_pos_clk)
            line[x_pos_clk] = 0;
        else
            line[x_pos_clk] = 255;
    }

    Update_View_Image();
}

void D_stat_tester::Update_Hist()
{
    v_hist[x_pos_clk] = y_val_clk;

    Update_Hist2Data();
}

void D_stat_tester::Update_Hist2Data()
{
    v_data.clear();
    for(int v = 0; v < v_hist.size(); v++)
        for(int i = 0; i < v_hist[v]; i++)
            v_data.push_back(v + x_min);

    Update_Data2Stats();
}

void D_stat_tester::Update_Data2Stats()
{
    D_Stat::Calc_Stats(
                &v_stat,
                v_data,
                true);

    Update_View_Stats();
}

void D_stat_tester::Update_View_Image()
{
    Qt::TransformationMode Trans_Mode = Qt::FastTransformation;
    Qt::AspectRatioMode Aspect_Mode = Qt::IgnoreAspectRatio;

    PX_Hist = QPixmap::fromImage(QI_Hist);
    PX_Hist = PX_Hist.scaled(
                ui->graphicsView_Hist->width() - 2,
                ui->graphicsView_Hist->height() - 2,
                Aspect_Mode,
                Trans_Mode);

    SC_Hist.clear();
    SC_Hist.addPixmap(PX_Hist);

    Set_Scale_Factor_View(&QI_Hist, ui->graphicsView_Hist);
}

void D_stat_tester::Set_Scale_Factor_View(QImage *QI, QGraphicsView *GV)
{
    double W_QI = QI->width();
    double H_QI = QI->height();
    double W_GV = GV->width() - 2;
    double H_GV = GV->height() - 2;
    x_factor = W_GV / W_QI;
    y_factor = H_GV / H_QI;
}

void D_stat_tester::Update_View_Stats()
{
    ui->label_Out_Value_Mean_S->setText(QString::number(v_stat[c_STAT_MEAN_ARITMETIC]));
    ui->label_Out_Value_Variance_S->setText(QString::number(v_stat[c_STAT_VARIANCE_SAMPLE]));
    ui->label_Out_Value_Skewness_S->setText(QString::number(v_stat[c_STAT_SKEWNESS_SAMPLE]));
    ui->label_Out_Value_Kurtosis_S->setText(QString::number(v_stat[c_STAT_KURTOSIS_SAMPLE]));
    ui->label_Out_Value_StanDev_S->setText(QString::number(v_stat[c_STAT_STAN_DEV_SAMPLE]));
    ui->label_Out_Value_VarCoeff_S->setText(QString::number(v_stat[c_STAT_VAR_COEF_SAMPLE]));

    ui->label_Out_Value_Mean_T->setText(QString::number(v_stat[c_STAT_MEAN_ARITMETIC]));
    ui->label_Out_Value_Variance_T->setText(QString::number(v_stat[c_STAT_VARIANCE_TOTAL]));
    ui->label_Out_Value_Skewness_T->setText(QString::number(v_stat[c_STAT_SKEWNESS_TOTAL]));
    ui->label_Out_Value_Kurtosis_T->setText(QString::number(v_stat[c_STAT_KURTOSIS_TOTAL]));
    ui->label_Out_Value_StanDev_T->setText(QString::number(v_stat[c_STAT_STAN_DEV_TOTAL]));
    ui->label_Out_Value_VarCoeff_T->setText(QString::number(v_stat[c_STAT_VAR_COEF_TOTAL]));

    ui->label_Out_Value_Q_00->setText(QString::number(v_stat[c_STAT_MINIMUM]));
    ui->label_Out_Value_Q_05->setText(QString::number(v_stat[c_STAT_QUANTIL_05]));
    ui->label_Out_Value_Q_10->setText(QString::number(v_stat[c_STAT_QUANTIL_10]));
    ui->label_Out_Value_Q_15->setText(QString::number(v_stat[c_STAT_QUANTIL_15]));
    ui->label_Out_Value_Q_20->setText(QString::number(v_stat[c_STAT_QUANTIL_20]));
    ui->label_Out_Value_Q_25->setText(QString::number(v_stat[c_STAT_QUARTIL_LOW]));
    ui->label_Out_Value_Q_30->setText(QString::number(v_stat[c_STAT_QUANTIL_30]));
    ui->label_Out_Value_Q_35->setText(QString::number(v_stat[c_STAT_QUANTIL_35]));
    ui->label_Out_Value_Q_40->setText(QString::number(v_stat[c_STAT_QUANTIL_40]));
    ui->label_Out_Value_Q_45->setText(QString::number(v_stat[c_STAT_QUANTIL_45]));
    ui->label_Out_Value_Q_50->setText(QString::number(v_stat[c_STAT_MEDIAN]));
    ui->label_Out_Value_Q_55->setText(QString::number(v_stat[c_STAT_QUANTIL_55]));
    ui->label_Out_Value_Q_60->setText(QString::number(v_stat[c_STAT_QUANTIL_60]));
    ui->label_Out_Value_Q_65->setText(QString::number(v_stat[c_STAT_QUANTIL_65]));
    ui->label_Out_Value_Q_70->setText(QString::number(v_stat[c_STAT_QUANTIL_70]));
    ui->label_Out_Value_Q_75->setText(QString::number(v_stat[c_STAT_QUARTIL_UP]));
    ui->label_Out_Value_Q_80->setText(QString::number(v_stat[c_STAT_QUANTIL_80]));
    ui->label_Out_Value_Q_85->setText(QString::number(v_stat[c_STAT_QUANTIL_85]));
    ui->label_Out_Value_Q_90->setText(QString::number(v_stat[c_STAT_QUANTIL_90]));
    ui->label_Out_Value_Q_95->setText(QString::number(v_stat[c_STAT_QUANTIL_95]));
    ui->label_Out_Value_Q_100->setText(QString::number(v_stat[c_STAT_MAXIMUM]));

    ui->label_Out_Value_D_10->setText(QString::number(v_stat[c_STAT_DIST_10_0_PRZ]));
    ui->label_Out_Value_D_20->setText(QString::number(v_stat[c_STAT_DIST_20_0_PRZ]));
    ui->label_Out_Value_D_30->setText(QString::number(v_stat[c_STAT_DIST_30_0_PRZ]));
    ui->label_Out_Value_D_40->setText(QString::number(v_stat[c_STAT_DIST_40_0_PRZ]));
    ui->label_Out_Value_D_50->setText(QString::number(v_stat[c_STAT_DIST_QUARTIL]));
    ui->label_Out_Value_D_60->setText(QString::number(v_stat[c_STAT_DIST_60_0_PRZ]));
    ui->label_Out_Value_D_70->setText(QString::number(v_stat[c_STAT_DIST_70_0_PRZ]));
    ui->label_Out_Value_D_80->setText(QString::number(v_stat[c_STAT_DIST_80_0_PRZ]));
    ui->label_Out_Value_D_90->setText(QString::number(v_stat[c_STAT_DIST_90_0_PRZ]));
    ui->label_Out_Value_D_100->setText(QString::number(v_stat[c_STAT_SPAN]));

    ui->label_Out_Value_Count->setText(QString::number(v_stat[c_STAT_COUNT]));
    ui->label_Out_Value_Sum->setText(QString::number(v_stat[c_STAT_SUM]));
    ui->label_Out_Value_ADM->setText(QString::number(v_stat[c_STAT_ABS_DEV_MED]));
}

void D_stat_tester::Update_CircStats()
{
    //data
    vector<double> v_data_circ_rad;
    vector<double> v_data_circ_grad;

    //read
    QStringList QSL_AllLines = ui->plainTextEdit_Input->toPlainText().split("\n");
    for(int l = 0; l < QSL_AllLines.size(); l++)
    {
        QStringList QSL_Line = QSL_AllLines[l].split("-");
        if(QSL_Line.size() == 2)
        {
            bool ok;
            double value = QSL_Line[0].toDouble(&ok);
            if(ok)
            {
                int count = QSL_Line[1].toDouble(&ok);
                if(ok)
                {
                    for(int i = 0; i < count; i++)
                    {
                        v_data_circ_grad.push_back(value);
                        v_data_circ_rad.push_back(value * Grad2Rad);
                    }
                }
            }
        }
    }
    //qDebug() << "D_stat_tester::Update_CircStats read data (rad):" << v_data_circ_rad;
    //qDebug() << "D_stat_tester::Update_CircStats read data (grad):" << v_data_circ_grad;

    //calc
    vector<vector<double>> vv_stats_circ(2);
    QStringList QSL_RadGrad = {"Rad", "Grad"};

    QElapsedTimer timer_stats;
    timer_stats.start();
    D_Stat::Calc_Stats_Circ_Rad(
                &(vv_stats_circ[0]),
                v_data_circ_rad);
    qDebug() << "D_stat_tester::Update_CircStats - D_Stat::Calc_Stats_Circ_Rad time in s:" << timer_stats.elapsed() / 1000.0;

    D_Stat::Calc_Stats_Circ_Grad(
                &(vv_stats_circ[1]),
                v_data_circ_grad);

    //show
    TableCircOut.set_data_d_2D_qsl_qsl(
                vv_stats_circ,
                QSL_RadGrad,
                QSL_StatListCirc);
}

void D_stat_tester::on_spinBox_Init_X_Min_valueChanged(int arg1)
{
    if(arg1 >= ui->spinBox_Init_X_Max->value())
        ui->spinBox_Init_X_Max->setValue(arg1);

    x_min = arg1;
}

void D_stat_tester::on_spinBox_Init_X_Max_valueChanged(int arg1)
{
    if(arg1 <= ui->spinBox_Init_X_Min->value())
        ui->spinBox_Init_X_Min->setValue(arg1);

    x_max = arg1;
}

void D_stat_tester::on_spinBox_Init_Y_Max_valueChanged(int arg1)
{
    y_max = arg1;
}

void D_stat_tester::on_pushButton_DistributionUniform_clicked()
{
    bool ok;

    double angle_start = QInputDialog::getDouble(
                this,
                "Uniform Distribution Parameters",
                "Start at (including):",
                0,
                0,
                360,
                3,
                &ok);
    if(!ok)
        return;

    double angle_end = QInputDialog::getDouble(
                this,
                "Uniform Distribution Parameters",
                "End at (excluding):",
                360,
                0,
                360,
                3,
                &ok);
    if(!ok)
        return;

    double angle_resolution = QInputDialog::getDouble(
                this,
                "Uniform Distribution Parameters",
                "Resolution:",
                0.1,
                0.0000001,
                360.0,
                6,
                &ok);
    if(!ok)
        return;

    int count_per_angle = QInputDialog::getInt(
                this,
                "Uniform Distribution Parameters",
                "Count per Value:",
                1,
                1,
                1000,
                1,
                &ok);
    if(!ok)
        return;

    QString QS_DistibutionAsText;
    double angle = angle_start;
    while(angle < angle_end)
    {
        QS_DistibutionAsText.append(QString::number(angle) + "-" + QString::number(count_per_angle) + "\n");
        angle += angle_resolution;
    }

    ui->plainTextEdit_Input->setPlainText(QS_DistibutionAsText);
}
