/************************************
 *   added:     08.11.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_popup_plot.h"
#include "ui_d_popup_plot.h"

D_Popup_Plot::D_Popup_Plot(QString Title, QString nameX, QString nameY, QString namePlot, QString nameSeries, vector<double> vX, vector<double> vY, int plot_mode, bool as_exec, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::D_Popup_Plot)
{
    QS_NamePlot = namePlot;
    QS_Name_X = nameX;
    QS_Name_Y = nameY;
    QSL_NamesSeries.append(nameSeries);
    vvData_X.push_back(vX);
    vvData_Y.push_back(vY);

    Init_Ui(Title, plot_mode, as_exec);
}

D_Popup_Plot::D_Popup_Plot(QString Title, QString nameX, QString nameY, QString namePlot, QString nameSeries, vector<double> vY, int plot_mode, bool as_exec, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::D_Popup_Plot)
{
    QS_NamePlot = namePlot;
    QS_Name_X = nameX;
    QS_Name_Y = nameY;
    QSL_NamesSeries.append(nameSeries);

    vvData_X.reserve(vY.size());
    for(size_t i = 0; i < vY.size(); i++)
        vvData_X[0][i] = i;

    vvData_Y.push_back(vY);

    Init_Ui(Title, plot_mode, as_exec);
}

D_Popup_Plot::D_Popup_Plot(QString Title, QString nameX, QString nameY, QString namePlot, QStringList namesSeries, vector<vector<double> > vvX, vector<vector<double> > vvY, int plot_mode, bool as_exec, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::D_Popup_Plot)
{
    QS_NamePlot = namePlot;
    QS_Name_X = nameX;
    QS_Name_Y = nameY;
    QSL_NamesSeries = namesSeries;
    vvData_X = vvX;
    vvData_Y = vvY;

    Init_Ui(Title, plot_mode, as_exec);
}

D_Popup_Plot::D_Popup_Plot(QString Title, QString nameX, QString nameY, QString namePlot, QStringList namesSeries, vector<vector<double> > vvY, int plot_mode, bool as_exec, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::D_Popup_Plot)
{
    QS_NamePlot = namePlot;
    QS_Name_X = nameX;
    QS_Name_Y = nameY;
    QSL_NamesSeries = namesSeries;

    vvData_X.reserve(vvY.size());
    for(size_t i = 0; i < vvY.size(); i++)
    {
        vvData_X[i].reserve(vvY.size());
        for(size_t j = 0; j < vvY.size(); j++)
        vvData_X[i][j] = j;
    }

    vvData_Y = vvY;

    Init_Ui(Title, plot_mode, as_exec);
}

D_Popup_Plot::~D_Popup_Plot()
{
    qDebug() << "D_Popup_Plot::~D_Popup_Plot" << "end of sad life of this pop up";
    delete ui;
}

void D_Popup_Plot::Init_Ui(QString QS_Titel, int init_PlotMode, bool as_exec)
{
    qDebug() << "D_Popup_Plot::Init_Ui" << "start";
    ui->setupUi(this);

    /*
    qDebug() << "D_Popup_Plot::Init_Ui" << "exec/show";
    if(as_exec)
        exec();
    else
        show();
    */

    qDebug() << "D_Popup_Plot::Init_Ui" << "title/icon";
    setWindowTitle(QS_Titel);
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));

    qDebug() << "D_Popup_Plot::Init_Ui" << "init GV";
    pChartView = new QChartView();
    ui->gridLayout_Plot->addWidget(pChartView);
    pChartView->setRenderHint(QPainter::Antialiasing);
    pChartView->setRubberBand(QChartView::RectangleRubberBand);
    pChartView->setInteractive(true);

    qDebug() << "D_Popup_Plot::Init_Ui" << "connect";
    connect(ui->comboBox_ModePlot,              SIGNAL(currentIndexChanged(int)),   this,   SLOT(Plot()));
    connect(ui->comboBox_ModeCrop_X,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Plot()));
    connect(ui->comboBox_ModeCrop_Y,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Plot()));
    connect(ui->comboBox_ModeTrafo_X,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Plot()));
    connect(ui->comboBox_ModeTrafo_Y,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Plot()));
    connect(ui->doubleSpinBox_CropMax_X,        SIGNAL(valueChanged(double)),       this,   SLOT(Plot()));
    connect(ui->doubleSpinBox_CropMax_Y,        SIGNAL(valueChanged(double)),       this,   SLOT(Plot()));
    connect(ui->doubleSpinBox_CropMin_X,        SIGNAL(valueChanged(double)),       this,   SLOT(Plot()));
    connect(ui->doubleSpinBox_CropMin_Y,        SIGNAL(valueChanged(double)),       this,   SLOT(Plot()));
    connect(ui->doubleSpinBox_TrafoGamma_X,     SIGNAL(valueChanged(double)),       this,   SLOT(Plot()));
    connect(ui->doubleSpinBox_TrafoGamma_Y,     SIGNAL(valueChanged(double)),       this,   SLOT(Plot()));
    connect(ui->doubleSpinBox_TrafoCenter_X,    SIGNAL(valueChanged(double)),       this,   SLOT(Plot()));
    connect(ui->doubleSpinBox_TrafoCenter_Y,    SIGNAL(valueChanged(double)),       this,   SLOT(Plot()));
    connect(ui->doubleSpinBox_TrafoDivisor_X,   SIGNAL(valueChanged(double)),       this,   SLOT(Plot()));
    connect(ui->doubleSpinBox_TrafoDivisor_Y,   SIGNAL(valueChanged(double)),       this,   SLOT(Plot()));

    qDebug() << "D_Popup_Plot::Init_Ui" << "populate";
    Populate_CB_Single(ui->comboBox_ModePlot,       QSL_PLOT_SIMPLE,        init_PlotMode);
    Populate_CB_Single(ui->comboBox_ModeCrop_X,     QSL_VisTrafo_Crop,      c_VIS_TRAFO_CROP_FIXED);
    Populate_CB_Single(ui->comboBox_ModeCrop_Y,     QSL_VisTrafo_Crop,      c_VIS_TRAFO_CROP_FIXED);
    Populate_CB_Single(ui->comboBox_ModeTrafo_X,    QSL_VisTrafo,           c_VIS_TRAFO_LINEAR);
    Populate_CB_Single(ui->comboBox_ModeTrafo_Y,    QSL_VisTrafo,           c_VIS_TRAFO_LINEAR);

    qDebug() << "D_Popup_Plot::Init_Ui" << "plot";
    Plot();

    qDebug() << "D_Popup_Plot::Init_Ui" << "end";
}

void D_Popup_Plot::Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(index_init);
    CB->blockSignals(false);
}

void D_Popup_Plot::Plot()
{

    qDebug() << "D_Popup_Plot::Plot" << "start";
    qDebug() << "D_Popup_Plot::Plot" << "X" << vvData_X[0];
    qDebug() << "D_Popup_Plot::Plot" << "Y" << vvData_Y[0];
    ERR(
                D_Plot::Plot_AnyReal(
                    pChartView,
                    &vvData_X,
                    &vvData_Y,
                    QS_NamePlot,
                    QSL_NamesSeries,
                    QS_Name_X,
                    QS_Name_Y,
                    ui->comboBox_ModePlot->currentIndex(),
                    ui->comboBox_ModeCrop_Y->currentIndex(),
                    ui->doubleSpinBox_CropMin_Y->value(),
                    ui->doubleSpinBox_CropMax_Y->value(),
                    ui->comboBox_ModeTrafo_Y->currentIndex(),
                    ui->doubleSpinBox_TrafoGamma_Y->value(),
                    ui->doubleSpinBox_TrafoCenter_Y->value(),
                    ui->doubleSpinBox_TrafoDivisor_Y->value(),
                    ui->comboBox_ModeCrop_X->currentIndex(),
                    ui->doubleSpinBox_CropMin_X->value(),
                    ui->doubleSpinBox_CropMax_X->value(),
                    ui->comboBox_ModeTrafo_X->currentIndex(),
                    ui->doubleSpinBox_TrafoGamma_X->value(),
                    ui->doubleSpinBox_TrafoCenter_X->value(),
                    ui->doubleSpinBox_TrafoDivisor_X->value()));

    qDebug() << "D_Popup_Plot::Plot" << "end";
}

void D_Popup_Plot::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_Popup_Plot", func, detail);
}
