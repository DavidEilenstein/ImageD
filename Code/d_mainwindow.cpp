/************************************
 *   added:     11.09.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_mainwindow.h"
#include "ui_d_mainwindow.h"

D_MainWindow::D_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MainWindow)
{
    ui->setupUi(this);

    //INITILAZE

    //Plugins
    vPluginActive.resize(c_PL_NUMBER_OF, 0);
    Populate_CB_Plugins();

    //Init Steps vector with one useless pointer to avoid confusion with indicies missmatch (store <-> steps)
    vSW_Steps.resize(1);

    //Graphics View
    ui->graphicsView_Viewer->setScene(&SC_Step_Image);
    ui->graphicsView_Viewer->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_Viewer->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Statusbar
    QString QS_SpacerFront = " ";
    QString QS_SpacerBack  = "  ";
    SB_L_Author     = new QLabel(this);
    SB_L_Facility   = new QLabel(this);
    SB_L_Version    = new QLabel(this);
    SB_L_Date       = new QLabel(this);
    SB_L_Status     = new QLabel(this);
    //SB_L_UseCounter = new QLabel(this);
    //SB_L_UseCounter->setText(QS_SpacerFront + QString::number(Store.get_UseCounter()) + " uses" + QS_SpacerBack);
    SB_L_Author->setText(   QS_SpacerFront + D_QS_Author    + QS_SpacerBack);
    SB_L_Facility->setText( QS_SpacerFront + D_QS_Facility  + QS_SpacerBack);
    SB_L_Version->setText(  QS_SpacerFront + D_QS_Version   + QS_SpacerBack);
    SB_L_Date->setText(     QS_SpacerFront + D_QS_Release   + QS_SpacerBack);
    SB_L_Status->setText(   QS_SpacerFront + D_QS_State     + QS_SpacerBack);
    ui->statusBar->addPermanentWidget(SB_L_Author);
    ui->statusBar->addPermanentWidget(SB_L_Facility);
    ui->statusBar->addPermanentWidget(SB_L_Status);
    ui->statusBar->addPermanentWidget(SB_L_Date);
    ui->statusBar->addPermanentWidget(SB_L_Version);
    //ui->statusBar->addPermanentWidget(SB_L_UseCounter);

    //TIMES
    //Init chart and chartview
    Chart_Times = new QChart();
    ChartView_Times = new QChartView(this);
    ChartView_Times->setChart(Chart_Times);
    ui->gridLayout_Times->addWidget(ChartView_Times);
    ChartView_Times->setRenderHint(QPainter::Antialiasing);
    ChartView_Times->setInteractive(true);


    //CONNECTS

    //View
    connect(ui->action_Smooth_Transformation,               SIGNAL(triggered(bool)),            this,   SLOT(Update_Image()));
    connect(ui->action_Keep_Aspect_Ratio,                   SIGNAL(triggered(bool)),            this,   SLOT(Update_Image()));
    connect(ui->spinBox_Viewer_Image_Number,                SIGNAL(valueChanged(int)),          this,   SLOT(Update_Image()));
    //Update Steps
    connect(ui->pushButton_Steps_Update,                    SIGNAL(clicked(bool)),              this,   SLOT(Update_All_Steps()));
    connect(ui->action_Update_All_Steps,                    SIGNAL(triggered(bool)),            this,   SLOT(Update_All_Steps()));
    //Update Times
    connect(ui->pushButton_Update_Times,                    SIGNAL(clicked(bool)),              this,   SLOT(Update_Times()));
    connect(ui->action_Update_Times,                        SIGNAL(triggered(bool)),            this,   SLOT(Update_Times()));
    connect(ui->action_Autoupdate_Times_on_TimesSettings,   SIGNAL(triggered(bool)),            this,   SLOT(Connect_TimesSettings_2_UpdateTimes(bool)));

    //ON START
    //Window
    setWindowTitle("ImageD - MainWindow");
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    this->show();
    set_Position();
    Connect_TimesSettings_2_UpdateTimes(true);
    Update_Image();
    Update_View();

    //feedback request
    if(Store.get_ReminderCountdown() <= 0 && !Store.get_FeedbackIsSent())
    {
        D_Popup_FeedbackRequest Pop(&Store);
        Pop.exec();
    }

    //Reference button icons
    QSize RefIconSize(40, 20);
    ui->pushButton_Ref_Licence->setIcon(QIcon(":Icon/icon_C.png"));
    ui->pushButton_Ref_Licence->setIconSize(RefIconSize);
    ui->pushButton_Ref_Citation->setIcon(QIcon(":Icon/icon_quote.png"));
    ui->pushButton_Ref_Citation->setIconSize(RefIconSize);
    ui->pushButton_Ref_Contact->setIcon(QIcon(":Icon/icon_mail.png"));
    ui->pushButton_Ref_Contact->setIconSize(RefIconSize);
    ui->pushButton_Ref_GSI->setIcon(QIcon(":Icon/icon_gsi.png"));
    ui->pushButton_Ref_GSI->setIconSize(RefIconSize);
    ui->pushButton_Ref_Biophysics->setIcon(QIcon(":Icon/icon_dna.png"));
    ui->pushButton_Ref_Biophysics->setIconSize(RefIconSize);
    ui->pushButton_Ref_hda->setIcon(QIcon(":Icon/icon_hda.png"));
    ui->pushButton_Ref_hda->setIconSize(RefIconSize);
    ui->pushButton_Ref_OBV->setIcon(QIcon(":Icon/icon_aperture.png"));
    ui->pushButton_Ref_OBV->setIconSize(RefIconSize);
    ui->pushButton_Ref_OpenCV->setIcon(QIcon(":Icon/icon_opencv.png"));
    ui->pushButton_Ref_OpenCV->setIconSize(RefIconSize);
    ui->pushButton_Ref_Qt->setIcon(QIcon(":Icon/icon_qt.png"));
    ui->pushButton_Ref_Qt->setIconSize(RefIconSize);
    ui->pushButton_Ref_Docs->setIcon(QIcon(":Icon/icon_docs.png"));
    ui->pushButton_Ref_Docs->setIconSize(RefIconSize);
    ui->pushButton_Ref_Github->setIcon(QIcon(":Icon/icon_github.png"));
    ui->pushButton_Ref_Github->setIconSize(RefIconSize);
}

D_MainWindow::~D_MainWindow()
{
    delete ui;
}

void D_MainWindow::ERR(unsigned int er, QString func, QString detail)
{
    ER.ERR(er, "D_Mainwindow", func, detail);
}

void D_MainWindow::Update_Image()
{
    ERR(D_Img_Proc::Convert_Mat_to_QImage(&QI_Step_Image, Store.get_Adress(current_step)));
    Update_View();
}

void D_MainWindow::Update_View()
{
    Qt::TransformationMode Trans_Mode = Qt::FastTransformation;
    if(ui->action_Smooth_Transformation->isChecked())
        Trans_Mode = Qt::SmoothTransformation;

    Qt::AspectRatioMode Aspect_Mode = Qt::IgnoreAspectRatio;
    if(ui->action_Keep_Aspect_Ratio->isChecked())
        Aspect_Mode = Qt::KeepAspectRatio;

    PX_Step_Image = QPixmap::fromImage(QI_Step_Image);
    PX_Step_Image = PX_Step_Image.scaled(
                ui->graphicsView_Viewer->width() - 2,
                ui->graphicsView_Viewer->height() - 2,
                Aspect_Mode,
                Trans_Mode);

    SC_Step_Image.clear();
    SC_Step_Image.addPixmap(PX_Step_Image);
}

void D_MainWindow::Update_Times()
{
    bool plot_time[4];
    plot_time[c_TIME_IMG_PROC]  = ui->checkBox_Times_Processing->isChecked();
    plot_time[c_TIME_IMG_CONV]  = ui->checkBox_Times_Conversion->isChecked();
    plot_time[c_TIME_IMG_SHOW]  = ui->checkBox_Times_Show->isChecked();
    plot_time[c_TIME_HIST]      = ui->checkBox_Times_Hist->isChecked();

    ERR(D_Plot::Plot_Times_All(
            ChartView_Times,
            &Store,
            plot_time,
            ui->label_Times_Total));
}

void D_MainWindow::Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(index_init);
    CB->blockSignals(false);
}

void D_MainWindow::Populate_CB_Plugins()
{
    Populate_CB_Single(ui->comboBox_PluginList, QSL_Plugins);
}

void D_MainWindow::Connect_TimesSettings_2_UpdateTimes(bool con)
{
    if(con)
    {
        connect(ui->checkBox_Times_Processing,      SIGNAL(toggled(bool)),     this,   SLOT(Update_Times()));
        connect(ui->checkBox_Times_Conversion,      SIGNAL(toggled(bool)),     this,   SLOT(Update_Times()));
        connect(ui->checkBox_Times_Show,            SIGNAL(toggled(bool)),     this,   SLOT(Update_Times()));
        connect(ui->checkBox_Times_Hist,            SIGNAL(toggled(bool)),     this,   SLOT(Update_Times()));
    }
    else
    {
        disconnect(ui->checkBox_Times_Processing,   SIGNAL(toggled(bool)),     this,   SLOT(Update_Times()));
        disconnect(ui->checkBox_Times_Conversion,   SIGNAL(toggled(bool)),     this,   SLOT(Update_Times()));
        disconnect(ui->checkBox_Times_Show,         SIGNAL(toggled(bool)),     this,   SLOT(Update_Times()));
        disconnect(ui->checkBox_Times_Hist,         SIGNAL(toggled(bool)),     this,   SLOT(Update_Times()));
    }
}

void D_MainWindow::Add_Step()
{
    vector<int> vDefaults(c_SD_NUMBER_OF, 0);
    vDefaults[c_SD_AUTOUPDATE_ON_SETTINGS]          = ui->action_StepDefault_Autoupdate_Steps_on_Settings_changed->isChecked();
    vDefaults[c_SD_AUTOUPDATE_SKIP]                 = ui->action_StepDefault_Skip_when_all_Steps_are_updated->isChecked();
    vDefaults[c_SD_CONNECT_PLANE]                   = ui->action_StepDefault_Connect_Plane_Position->isChecked();
    vDefaults[c_SD_CONNECT_ZOOM]                    = ui->action_StepDefault_Connect_Steps_Zoom->isChecked();
    vDefaults[c_SD_VIEWER_ASPECT_KEEP]              = ui->action_StepDefault_Viewer_Keep_Aspect_Ratio->isChecked();
    vDefaults[c_SD_VIEWER_TRANSFORMATION_SMOOTH]    = ui->action_StepDefault_Viewer_Smooth_Transformation->isChecked();

    D_StepWindow* pStepW = new D_StepWindow(&Store, &vSW_Steps, vDefaults);     //create new Stepwindow
    vSW_Steps.push_back(pStepW);                                                //store its adress in vector
    pStepW->show();                                                             //show it
}

void D_MainWindow::Add_Analysis()
{
    D_AnalysisWindow* pAnalysisW = new D_AnalysisWindow(&Store);
    vAW_Analysis.push_back(pAnalysisW);
    pAnalysisW->show();
}

void D_MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    Update_View();
}

void D_MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton btn = QMessageBox::question(
                this,
                tr("Close ImageD"),
                tr("Do you want to close all ImageD windows?"),
                QMessageBox::No | QMessageBox::Yes,
                QMessageBox::Yes);

    if(btn == QMessageBox::Yes)
    {
        for(unsigned int s = 1; s < vSW_Steps.size(); s++)
            vSW_Steps[s]->      set_ClosingPossible(true);

        if(vPluginActive[c_PL_FOCI_CYTO_NUCLEI])
            pCoreFoci->         set_ClosingPossible(true);
        if(vPluginActive[c_PL_MITOCHONDRIA])
            pMitochondrien->    set_ClosingPossible(true);
        if(vPluginActive[c_PL_EILENSTEIN])
            pEilenstein->       set_ClosingPossible(true);
        if(vPluginActive[c_PL_CELL_COLONIES])
            pCellColonies->     set_ClosingPossible(true);
        if(vPluginActive[c_PL_FOCI_TRACKING])
            pFociNucleiTime->   set_ClosingPossible(true);
        if(vPluginActive[c_PL_ION_TRACKS])
            pIonTracks->        set_ClosingPossible(true);
        if(vPluginActive[c_PL_TIF_VISUALIZER])
            pVisualization->    set_ClosingPossible(true);
        if(vPluginActive[c_PL_OSTEOCLASTS])
            pOsteoclasts->      set_ClosingPossible(true);
        if(vPluginActive[c_PL_DNA_FIBERS])
            pDnaFibers->        set_ClosingPossible(true);
        if(vPluginActive[c_PL_RADON_CURVE_FITTING])
            pCurveFitting->     set_ClosingPossible(true);
        if(vPluginActive[c_PL_SEGMENTATION_ASSISTANT])
            pSegAssi->          set_ClosingPossible(true);
        if(vPluginActive[c_PL_CEREBRAL_ORGANOIDS])
            pCerebOrga->        set_ClosingPossible(true);
        if(vPluginActive[c_PL_CILIA_SPHERE_TRACKER])
            pCilTrack->         set_ClosingPossible(true);
        if(vPluginActive[c_PL_FOURIER_TRANSFORMATOR])
            pFourierTrans->     set_ClosingPossible(true);
        if(vPluginActive[c_PL_AIR_DRAG_DETECT])
            pAirDrag->          set_ClosingPossible(true);
        if(vPluginActive[c_PL_MEGA_FOCI])
            pMegaFoci->         set_ClosingPossible(true);
        if(vPluginActive[c_PL_HUANG_VIS])
            pHuang->           set_ClosingPossible(true);

        event->accept();
        qApp->closeAllWindows();
    }
    else
    {
        event->ignore();
    }
}

void D_MainWindow::set_Position()
{
    QRect rec = QApplication::desktop()->screenGeometry();
    unsigned int width = rec.width() - this->width() - 15;

    this->move(width, 0);
}

void D_MainWindow::Update_All_Steps()
{
    for(unsigned int s = 1; s < vSW_Steps.size(); s++)                          //loop all steps by number: 1, 2, ...
        vSW_Steps[s]->set_need_Update(true);                                    //and tell them, they need an update

    unsigned int pos_in_chain = 0;
    for(unsigned int s = 1; s < vSW_Steps.size(); s++)                          //loop all steps by number: 1, 2, ...
        while(vSW_Steps[s]->needs_Update())                                     //while the step is not updated
        {
            pos_in_chain++;
            unsigned int step2update = vSW_Steps[s]->get_root_toUpdate();       //find root
            qDebug() << "Chain Update: Step" << step2update;
            vSW_Steps[step2update]->Update_from_extern();                       //and update it until step is updated
            vSW_Steps[step2update]->set_chain_pos(pos_in_chain);
        }

    if(ui->tabWidget_Overview->currentIndex() == 1 || ui->action_Autoupdate_Times_on_Steps->isChecked())
        Update_Times();
}


void D_MainWindow::on_spinBox_Viewer_Image_Number_valueChanged(int arg1)
{
    if(arg1 < Store.size())
        current_step = arg1;
    else
        ui->spinBox_Viewer_Image_Number->setValue(current_step);

    if(arg1 == 0)
        ui->graphicsView_Viewer->setToolTip("Initialization image by Bahar Djouiai, GSI Darmstadt");
    else
        ui->graphicsView_Viewer->setToolTip("");
}



void D_MainWindow::on_pushButton_Step_Add_clicked()
{
    Add_Step();
}

void D_MainWindow::on_pushButton_Analysis_Add_clicked()
{
    Add_Analysis();
}

void D_MainWindow::on_tabWidget_Overview_currentChanged(int index)
{
    if(index == 1)
        Update_Times();
}

void D_MainWindow::on_action_Set_Step_Pos_triggered()
{
    for(unsigned int s = 1; s < vSW_Steps.size(); s++)
        vSW_Steps[s]->set_Position();
}

void D_MainWindow::on_action_Test_Statistic_Function_triggered()
{
    vector<double> v_test_data = {-1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2};
    vector<double> v_test_stat;

    D_Stat::Calc_Stats(&v_test_stat, v_test_data, true);

    QMessageBox MSG;

    MSG.setText("Statistics calculated for:\n{-1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2}");

    QString QS_msg;

    QS_msg.append("Count:\t\t"      + QString::number(v_test_stat[c_STAT_COUNT]) +  "\n");
    QS_msg.append("Sum:\t\t"        + QString::number(v_test_stat[c_STAT_SUM]) +  "\n\n");

    QS_msg.append("Mean:\t\t"       + QString::number(v_test_stat[c_STAT_MEAN_ARITMETIC]) +  "\n");
    QS_msg.append("Mean (abs):\t"   + QString::number(v_test_stat[c_STAT_MEAN_ARITMETIC_OF_ABS]) +  "\n");
    QS_msg.append("Mean (!=0):\t"   + QString::number(v_test_stat[c_STAT_MEAN_ARITMETIC_OF_NON_ZERO]) +  "\n");
    QS_msg.append("Variance t:\t"   + QString::number(v_test_stat[c_STAT_VARIANCE_TOTAL]) +  "\n");
    QS_msg.append("Variance s:\t"   + QString::number(v_test_stat[c_STAT_VARIANCE_SAMPLE]) +  "\n");
    QS_msg.append("Stan. Dev. t:\t" + QString::number(v_test_stat[c_STAT_STAN_DEV_TOTAL]) +  "\n");
    QS_msg.append("Stan. Dev. s:\t" + QString::number(v_test_stat[c_STAT_STAN_DEV_SAMPLE]) +  "\n");
    QS_msg.append("Var. Coeff t:\t" + QString::number(v_test_stat[c_STAT_VAR_COEF_TOTAL]) +  "\n");
    QS_msg.append("Var. Coeff s:\t" + QString::number(v_test_stat[c_STAT_VAR_COEF_SAMPLE]) +  "\n");
    QS_msg.append("Skewness t:\t"   + QString::number(v_test_stat[c_STAT_SKEWNESS_TOTAL]) +  "\n");
    QS_msg.append("Skewness s:\t"   + QString::number(v_test_stat[c_STAT_SKEWNESS_SAMPLE]) +  "\n");
    QS_msg.append("Kurtosis t:\t"   + QString::number(v_test_stat[c_STAT_KURTOSIS_TOTAL]) +  "\n");
    QS_msg.append("Kurtosis s:\t"   + QString::number(v_test_stat[c_STAT_KURTOSIS_SAMPLE]) +  "\n\n");

    QS_msg.append("Minimum:\t"      + QString::number(v_test_stat[c_STAT_MINIMUM]) +     "\n");
    QS_msg.append("Quantil 5%:\t"   + QString::number(v_test_stat[c_STAT_QUANTIL_05]) +  "\n");
    QS_msg.append("Quantil 10%:\t"  + QString::number(v_test_stat[c_STAT_QUANTIL_10]) +  "\n");
    QS_msg.append("Quantil 15%:\t"  + QString::number(v_test_stat[c_STAT_QUANTIL_15]) +  "\n");
    QS_msg.append("Quantil 20%:\t"  + QString::number(v_test_stat[c_STAT_QUANTIL_20]) +  "\n");
    QS_msg.append("Qurtil Low:\t"   + QString::number(v_test_stat[c_STAT_QUARTIL_LOW]) + "\n");
    QS_msg.append("Quantil 30%:\t"  + QString::number(v_test_stat[c_STAT_QUANTIL_30]) +  "\n");
    QS_msg.append("Quantil 35%:\t"  + QString::number(v_test_stat[c_STAT_QUANTIL_35]) +  "\n");
    QS_msg.append("Quantil 40%:\t"  + QString::number(v_test_stat[c_STAT_QUANTIL_40]) +  "\n");
    QS_msg.append("Quantil 45%:\t"  + QString::number(v_test_stat[c_STAT_QUANTIL_45]) +  "\n");
    QS_msg.append("Median:\t"       + QString::number(v_test_stat[c_STAT_MEDIAN]) +  "\n");
    QS_msg.append("Quantil 55%:\t"  + QString::number(v_test_stat[c_STAT_QUANTIL_55]) +  "\n");
    QS_msg.append("Quantil 60%:\t"  + QString::number(v_test_stat[c_STAT_QUANTIL_60]) +  "\n");
    QS_msg.append("Quantil 65%:\t"  + QString::number(v_test_stat[c_STAT_QUANTIL_65]) +  "\n");
    QS_msg.append("Quantil 70%:\t"  + QString::number(v_test_stat[c_STAT_QUANTIL_70]) +  "\n");
    QS_msg.append("Quartil 75%:\t"  + QString::number(v_test_stat[c_STAT_QUARTIL_UP]) +  "\n");
    QS_msg.append("Quantil 80%:\t"  + QString::number(v_test_stat[c_STAT_QUANTIL_80]) +  "\n");
    QS_msg.append("Quantil 85%:\t"  + QString::number(v_test_stat[c_STAT_QUANTIL_85]) +  "\n");
    QS_msg.append("Quantil 90%:\t"  + QString::number(v_test_stat[c_STAT_QUANTIL_90]) +  "\n");
    QS_msg.append("Quantil 95%:\t"  + QString::number(v_test_stat[c_STAT_QUANTIL_95]) +  "\n");
    QS_msg.append("Maximum:\t"      + QString::number(v_test_stat[c_STAT_MAXIMUM]) +  "\n\n");

    QS_msg.append("Abs.Dev.Med:\t"  + QString::number(v_test_stat[c_STAT_ABS_DEV_MED]) +  "\n\n");

    QS_msg.append("Span:\t\t"       + QString::number(v_test_stat[c_STAT_SPAN]) +  "\n");
    QS_msg.append("Dist 3 Sigma:\t" + QString::number(v_test_stat[c_STAT_DIST_99_7_PRZ]) +  "\n");
    QS_msg.append("Dist 2 Sigma:\t" + QString::number(v_test_stat[c_STAT_DIST_95_4_PRZ]) +  "\n");
    QS_msg.append("Dist 90%:\t"     + QString::number(v_test_stat[c_STAT_DIST_90_0_PRZ]) +  "\n");
    QS_msg.append("Dist 80%:\t"     + QString::number(v_test_stat[c_STAT_DIST_80_0_PRZ]) +  "\n");
    QS_msg.append("Dist 70%:\t"     + QString::number(v_test_stat[c_STAT_DIST_70_0_PRZ]) +  "\n");
    QS_msg.append("Dist 1 Sigma:\t" + QString::number(v_test_stat[c_STAT_DIST_68_3_PRZ]) +  "\n");
    QS_msg.append("Dist 60%:\t"     + QString::number(v_test_stat[c_STAT_DIST_60_0_PRZ]) +  "\n");
    QS_msg.append("Dist 50%:\t"     + QString::number(v_test_stat[c_STAT_DIST_QUARTIL]) +  "\n");
    QS_msg.append("Dist 40%:\t"     + QString::number(v_test_stat[c_STAT_DIST_40_0_PRZ]) +  "\n");
    QS_msg.append("Dist 30%:\t"     + QString::number(v_test_stat[c_STAT_DIST_30_0_PRZ]) +  "\n");
    QS_msg.append("Dist 20%:\t"     + QString::number(v_test_stat[c_STAT_DIST_20_0_PRZ]) +  "\n");
    QS_msg.append("Dist 10%:\t"     + QString::number(v_test_stat[c_STAT_DIST_10_0_PRZ]) +  "\n");

    MSG.setInformativeText(QS_msg);

    MSG.exec();
}

void D_MainWindow::on_action_Test_Quatile_Access_triggered()
{
    vector<double> v_test_data = {-15, -14, -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    vector<double> v_test_stat;

    D_Stat::Calc_Stats(&v_test_stat, v_test_data, true);

    QMessageBox MSG;

    MSG.setText("Statistics calculated for:\n{-15, -14, -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5}");

    QString QS_msg;

    QS_msg.append("Quantiles:\n");
    for(int i = 0; i < 21; i++)
        QS_msg.append(QString::number(D_Stat::Quant(&v_test_stat, i)) + "   ");
    QS_msg.append("\n\n");

    QS_msg.append("Quantiles, norm:\n");
    for(int i = 0; i < 21; i++)
        QS_msg.append(QString::number(D_Stat::Quant_Norm(&v_test_stat, i)) + "   ");
    QS_msg.append("\n\n");

    QS_msg.append("Quantiles, 1st Diff:\n");
    for(int i = 0; i < 20; i++)
        QS_msg.append(QString::number(D_Stat::Quant_1stD(&v_test_stat, i, 1)) + "   ");
    QS_msg.append("\n\n");

    QS_msg.append("Quantiles, 1st Diff, norm:\n");
    for(int i = 0; i < 20; i++)
        QS_msg.append(QString::number(D_Stat::Quant_1stD_Norm(&v_test_stat, i, 1)) + "   ");
    QS_msg.append("\n\n");

    QS_msg.append("Dist:\n");
    for(int i = 0; i < 10; i++)
        QS_msg.append(QString::number(D_Stat::Dist(&v_test_stat, i)) + "   ");
    QS_msg.append("\n\n");

    QS_msg.append("Dist, norm:\n");
    for(int i = 0; i < 10; i++)
        QS_msg.append(QString::number(D_Stat::Dist_Norm(&v_test_stat, i)) + "   ");
    QS_msg.append("\n\n");

    QS_msg.append("Dist, 1st Diff:\n");
    for(int i = 0; i < 9; i++)
        QS_msg.append(QString::number(D_Stat::Dist_1stD(&v_test_stat, i, 1)) + "   ");
    QS_msg.append("\n\n");

    QS_msg.append("Dist, 1st Diff, norm:\n");
    for(int i = 0; i < 9; i++)
        QS_msg.append(QString::number(D_Stat::Dist_1stD_Norm(&v_test_stat, i, 1)) + "   ");
    QS_msg.append("\n\n");

    MSG.setInformativeText(QS_msg);

    MSG.exec();
}

void D_MainWindow::on_action_Stat_Tester_triggered()
{
    D_stat_tester* pStatTestW = new D_stat_tester();
    pStatTestW->show();
}

void D_MainWindow::on_action_Steps_Normal_Size_triggered()
{
    for(unsigned int s = 1; s < vSW_Steps.size(); s++)
        vSW_Steps[s]->setGeometry(
                    vSW_Steps[s]->x(),
                    vSW_Steps[s]->y(),
                    602,
                    700);
}

void D_MainWindow::on_pushButton_Steps_Save_clicked()
{
    QString QS_Dir = QFileDialog::getExistingDirectory(
                this,
                "Select folder to stream steps to.",
                Store.dir_Steps()->path());

    if(QS_Dir == 0)
        return;

    //Save selected dir
    DIR_Steps_Stream.setPath(QS_Dir);
    Store.set_dir_Steps(QS_Dir);

    //create subfolder for output
    unsigned int count = 0;
    QString QS_Folder_Out_Sub = QS_Dir + "/ImageD_ProcChain_0";
    while(QDir(QS_Folder_Out_Sub).exists())
    {
        count++;
        QS_Folder_Out_Sub = QS_Dir + "/ImageD_ProcChain_" + QString::number(count);
    }
    QDir().mkdir(QS_Folder_Out_Sub);
    QDir DIR_SubDir(QS_Folder_Out_Sub);

    //loop steps and stream data (csv table)
    QString QS_Stream_csv = QS_Folder_Out_Sub + "/Steps_Info.csv";
    OS_Steps_Stream.open(QS_Stream_csv.toStdString());
    stream_init();
    for(unsigned int s = 1; s < vSW_Steps.size(); s++)
        vSW_Steps[s]->Save_Steps(&DIR_SubDir, &OS_Steps_Stream);
    OS_Steps_Stream.close();

    //Screenshots of stepwindows
    QDir DIR_Screenshots(QS_Folder_Out_Sub + "/Screenshots");
    QDir().mkdir(DIR_Screenshots.path());
    for(unsigned int s = 1; s < vSW_Steps.size(); s++)
        vSW_Steps[s]->grab().save(DIR_Screenshots.path() + "/" + vSW_Steps[s]->get_Title() + ".jpg");
 }

void D_MainWindow::stream_init()
{
    OS_Steps_Stream << "Number,"
                    << "PosInChain,"
                    << "Sources,"
                    << "Destinations,"
                    << ","
                    << "Title,"
                    << "Width,"
                    << "Height,"
                    << "MatFomat,"
                    << "QImageFormat,"
                    << ","
                    << "ValMin,"
                    << "ValMax,"
                    << "ValRange,"
                    << ","
                    << "Type,"
                    << "Subtype,"
                    << "S1,"
                    << "S2,"
                    << "S3,"
                    << "S4,"
                    << ","
                    << "Parameters,"
                    << "\n\n";
}

void D_MainWindow::on_action_Test_D_VisDat_triggered()
{
    //input list
    QStringList QSL_TestLoad =
    {
        "D:/David_Eilenstein/ImageD/Images/motiv_chrysanthemum.jpg",
        "D:/David_Eilenstein/ImageD/Images/motiv_desert.jpg",
        "D:/David_Eilenstein/ImageD/Images/motiv_hydrangeas.jpg"
    };

    //create
    D_VisDat_Obj VD_test;
    ERR(D_VisDat_Proc::Create_VD_List(&VD_test, QSL_TestLoad));

    //show
    Mat MA_tmp_show;
    ERR(D_VisDat_Proc::Read_2D_Plane(&MA_tmp_show, &VD_test, D_VisDat_Slice_2D(0, -1, 0, 0, -1, 0)));
    imshow("test", MA_tmp_show);

    //wait & clean
    waitKey();
    MA_tmp_show.release();

    /*
    qDebug() << "test qsl";

    QStringList QSL_TestLoad =
    {
        "D:/David_Eilenstein/ImageD/Images/test_col_5_1 - Kopie.bmp",
        "D:/David_Eilenstein/ImageD/Images/test_col_5_2 - Kopie.bmp",
        "D:/David_Eilenstein/ImageD/Images/test_col_5_3 - Kopie.bmp"
    };


    QStringList QSL_TestLoad3 =
    {
        "D:/David_Eilenstein/ImageD/Images/test_bin5x5_0.bmp",
        "D:/David_Eilenstein/ImageD/Images/test_bin5x5_1.bmp",
        "D:/David_Eilenstein/ImageD/Images/test_bin5x5_2.bmp"
    };

    QStringList QSL_TestLoad1 =
    {
        "D:/David_Eilenstein/ImageD/Images/test_col_5_1.bmp",
        "D:/David_Eilenstein/ImageD/Images/test_col_5_2.bmp",
        "D:/David_Eilenstein/ImageD/Images/test_col_5_3.bmp"
    };

    QStringList QSL_TestLoad2 =
    {
        "D:/David_Eilenstein/ImageD/Images/motiv_chrysanthemum.jpg",
        "D:/David_Eilenstein/ImageD/Images/motiv_desert.jpg",
        "D:/David_Eilenstein/ImageD/Images/motiv_hydrangeas.jpg"
    };

    //size def
    Mat MA_tmp_size_def = imread(QSL_TestLoad.first().toStdString(), IMREAD_ANYCOLOR | IMREAD_ANYDEPTH);

    qDebug() << "test dim";
    D_VisDat_Dim Dim_test(
                MA_tmp_size_def.cols,   //X
                MA_tmp_size_def.rows,   //Y
                1,                      //Z
                1,                      //T
                QSL_TestLoad.size(),    //S
                1);                     //P

    qDebug() << "test obj";
    D_VisDat_Obj VD_test(Dim_test, MA_tmp_size_def.type());

    vector<Mat> vMA_tmp_in;
    vMA_tmp_in.resize(VD_test.Dim().size_S());

    for(int i = 0; i < QSL_TestLoad.size(); i++)
    {
        //define slice
        D_VisDat_Slice_2D VD_slice(-1, -1, 0, 0, i, 0);

        //write
        qDebug() << "test loop - write:" << QSL_TestLoad[i];
        ERR(D_VisDat_Proc::Write_2D_Plane(
                    &VD_test,
                    QSL_TestLoad[i],
                    VD_slice),
            "on_action_Test_D_VisDat_triggered",
            "Write_2D_Plane");

        //read
        Mat MA_tmp_read;
        ERR(D_VisDat_Proc::Read_2D_Plane(
                    &MA_tmp_read,
                    &VD_test,
                    VD_slice),
            "on_action_Test_D_VisDat_triggered",
            "Read_2D_Plane");;

        //copy & show
        cv::resize(MA_tmp_read, vMA_tmp_in[i], Size(), 100, 100, cv::INTER_NEAREST);
        //ERR(D_Img_Proc::Duplicate(&(vMA_tmp_in[i]), &MA_tmp_read), "on_action_Test_D_VisDat_triggered", "Duplicate");
        imshow(QString("Out: " + QSL_DimNames[DIM_INDEX_S] + QString::number(i)).toStdString(), vMA_tmp_in[i]);

        //free memory
        MA_tmp_read.release();
    }

    //scan dim
    //y
    int scan_index = DIM_INDEX_Y;
    int scanDimSize = VD_test.Dim().size_Dim(scan_index);

    vector<Mat> vMA_tmp_out;
    vMA_tmp_out.resize(scanDimSize);
    for(int i = 0; i < scanDimSize; i++)
    {
        //define slice
        D_VisDat_Slice_2D VD_slice(-1, i, 0, 0, -1, 0);
        qDebug() << VD_slice.info();

        //read
        Mat MA_tmp_read;
        ERR(D_VisDat_Proc::Read_2D_Plane(
                    &MA_tmp_read,
                    &VD_test,
                    VD_slice),
            "on_action_Test_D_VisDat_triggered",
            "Read_2D_Plane");;

        //copy & show
        cv::resize(MA_tmp_read, vMA_tmp_out[i], Size(), 100, 100, cv::INTER_NEAREST);
        //ERR(D_Img_Proc::Duplicate(&(vMA_tmp_in[i]), &MA_tmp_read), "on_action_Test_D_VisDat_triggered", "Duplicate");
        imshow(QString("Out: " + QSL_DimNames[scan_index] + QString::number(i)).toStdString(), vMA_tmp_out[i]);

        //free memory
        MA_tmp_read.release();
    }
    waitKey();

    vMA_tmp_in.clear();
    vMA_tmp_out.clear();
    MA_tmp_size_def.release();
*/
    /*
    //Create VD
    D_VisDat VD_Test(CV_8UC3, 1024, 768, 1, 1, 3, 1);

    //Load and push to VD
    Mat MA_tmp_input;
    Mat MA_tmp_reshaped;
    Mat MA_tmp_target;

    MA_tmp_input = imread("D:/David_Eilenstein/ImageD/Images/motiv_chrysanthemum.jpg", cv::IMREAD_ANYDEPTH|cv::IMREAD_ANYCOLOR);
    imshow("MA_tmp_input", MA_tmp_input);
    qDebug() << "Adress of Data of MA_tmp_input" << MA_tmp_input.ptr();

    MA_tmp_target = VD_Test.mat_2D(-1, -1, 0, 0, 0, 0);
    qDebug() << "Adress of Data of MA_tmp_target" << MA_tmp_target.ptr();

    int size6D[] = {1, 1, 1, 1, 768, 1024};
    MA_tmp_reshaped = MA_tmp_input.reshape(0, 6, size6D);
    qDebug() << "Adress of Data of MA_tmp_reshaped" << MA_tmp_reshaped.ptr();

    MA_tmp_reshaped.copyTo(MA_tmp_target);
    qDebug() << "Adress of Data of MA_tmp_target after copyTo" << MA_tmp_target.ptr();


    //Get 2D plane Mat to display (full x and y, 1 from stack) - Mat is technically still 6D
    int s = QInputDialog::getInt(this, "get stack_index", "s= ", 0, 0, 2, 1);
    MA_vdTest = VD_Test.mat_2D(-1, -1, 0, 0, s, 0).clone();
    //imshow("MA_vdTest", MA_vdTest);
    qDebug() << "Adress of Data of MA_vdTest" << MA_vdTest.ptr();

    //New real 2D Mat with same data field as 6D Mat with 2D content
    int size2[] = {768, 1024};
    MA_vdTest2 = Mat(2, size2, CV_8UC3, MA_vdTest.ptr());
    imshow("MA_vdTest2", MA_vdTest2);
    qDebug() << "Adress of Data of MA_vdTest2" << MA_vdTest2.ptr();

    //imshow("test VD", MA_VD_Test2);
    ERR(D_Img_Proc::Convert_Mat_to_QImage(&QI_Step_Image, &MA_vdTest2));
    Update_View();

    //info that
    QMessageBox::information(this,"Test", "D_VisDat s:" + QString::number(s));
    */
}

void D_MainWindow::on_actionTest_ND_Mat_load_and_display_triggered()
{
    //3D main-mat where data shall be stored in
    int size_3D_main[] = {3, 768, 1024};
    Mat MA_3D_main(3, size_3D_main, CV_8UC3);

    //2D input mats (from files, each 1024x768 color)
    Mat MA_2Da_inp[3];
    MA_2Da_inp[0] = imread("D:/David_Eilenstein/ImageD/Images/motiv_chrysanthemum.jpg");
    MA_2Da_inp[1] = imread("D:/David_Eilenstein/ImageD/Images/motiv_desert.jpg");
    MA_2Da_inp[2] = imread("D:/David_Eilenstein/ImageD/Images/motiv_hydrangeas.jpg");

    //Put input-2D mats into 3D-main mat using target mat
    for(int z = 0; z < 3; z++)
    {
        vector<Range> vRG_trgt = {Range(z, z+1), Range::all(), Range::all()};
        Mat MA_2D_trgt = MA_3D_main(vRG_trgt);
        MA_2Da_inp[z].copyTo(MA_2D_trgt);
    }

    //Extract one plane/img (technically still 3D) - read 2nd plane
    vector<Range> vRG_extr = {Range(0, 1), Range::all(), Range::all()};
    Mat MA_3D_extr = MA_3D_main(vRG_extr);

    //3D-extr mat reinterpreted as 2D
    int size_2D_show[] = {768, 1024};
    Mat MA_2D_show(2, size_2D_show, CV_8UC3, MA_3D_extr.ptr());

    //show 2D-show mat
    imshow("test if it worked", MA_2D_show);
}

void D_MainWindow::on_action_Test_1D_EDT_triggered()
{
    double v = 9999;

    vector<double> v_line = {v, v, 0, 0, v, v, v, v, 0, v, v, v};
    vector<double> v_dist;

    D_Math::Distance_Transformation_1D(&v_dist, v_line, 1);

    qDebug() << "\n";
    qDebug() << "line" << v_line;
    qDebug() << "dist" << v_dist;
}









void D_MainWindow::on_comboBox_PluginList_currentIndexChanged(int index)
{
    ui->pushButton_PluginLaunch->setEnabled(!vPluginActive[index]);
}

void D_MainWindow::on_pushButton_PluginLaunch_clicked()
{
    size_t index = ui->comboBox_PluginList->currentIndex();
    vPluginActive[index] = 1;
    ui->pushButton_PluginLaunch->setEnabled(false);

    switch (index) {

    case c_PL_FOCI_CYTO_NUCLEI:
        pCoreFoci = new D_MAKRO_CoreFoci(&Store);
        pCoreFoci->show();
        break;

    case c_PL_MITOCHONDRIA:
        pMitochondrien = new D_MAKRO_Mitochondrien(&Store);
        pMitochondrien->show();
        break;

    case c_PL_EILENSTEIN:
        pEilenstein = new D_MAKRO_Eilenstein(&Store);
        pEilenstein->show();
        break;

    case c_PL_CELL_COLONIES:
        pCellColonies = new D_MAKRO_CellColonies(&Store);
        pCellColonies->show();
        break;

    case c_PL_FOCI_TRACKING:
        pFociNucleiTime = new m_makro_foci(&Store);
        pFociNucleiTime->show();
        break;

    case c_PL_ION_TRACKS:
        pIonTracks = new D_MAKRO_IonTracks(&Store);
        pIonTracks->show();
        break;

    case c_PL_TIF_VISUALIZER:
        pVisualization = new D_MAKRO_Visualization(&Store);
        pVisualization->show();
        break;

    case c_PL_OSTEOCLASTS:
        pOsteoclasts = new D_MAKRO_Osteoclasts(&Store);
        pOsteoclasts->show();
        break;

    case c_PL_DNA_FIBERS:
        pDnaFibers = new D_MAKRO_DnaFiber(&Store);
        pDnaFibers->show();
        break;

    case c_PL_RADON_CURVE_FITTING:
        pCurveFitting = new D_MAKRO_CurveFitting(&Store);
        pCurveFitting->show();
        break;

    case c_PL_SEGMENTATION_ASSISTANT:
        pSegAssi = new D_MAKRO_SegmentationAssistant(&Store);
        pSegAssi->show();
        break;

    case c_PL_CEREBRAL_ORGANOIDS:
        pCerebOrga = new D_MAKRO_CerebralOrganoids(&Store);
        pCerebOrga->show();
        break;

    case c_PL_MANUEL_SEGMANTATION:
        pManSeg = new D_MAKRO_ManuelSegmentation(&Store);
        pManSeg->show();
        break;

    case c_PL_CILIA_SPHERE_TRACKER:
        pCilTrack = new D_MAKRO_CiliaSphereTracker(&Store);
        pCilTrack->show();
        break;

    case c_PL_FOURIER_TRANSFORMATOR:
        pFourierTrans = new D_MAKRO_FourierTransformator();
        pFourierTrans->show();
        break;

    case c_PL_AIR_DRAG_DETECT:
        pAirDrag = new D_MAKRO_AirDragTrack(&Store);
        pAirDrag->show();
        break;

    case c_PL_MEGA_FOCI:
        pMegaFoci = new D_MAKRO_MegaFoci(&Store);
        pMegaFoci->show();
        break;

    case c_PL_HUANG_VIS:
        pHuang = new D_MAKRO_HuangVisualization(&Store);
        pHuang->show();
        break;

    default:
        break;
    }
}

void D_MainWindow::on_pushButton_Ref_Licence_clicked()
{
    QDesktopServices::openUrl(QUrl("file:///" + QCoreApplication::applicationDirPath() + "/LICENCE.txt"));
}

void D_MainWindow::on_pushButton_Ref_Citation_clicked()
{
    QString QS_Year = QString::number(QDateTime::currentDateTime().date().year());

    if(QMessageBox::information(
                this,
                "Citation",
                "Please cite as follows:"
                "<br>"
                "<br><I>ImageD version " + D_QS_Version + ","
                "<br>" + D_QS_Author + ","
                "<br>Gesellschaft fuer Schwerionenforschung Darmstadt,"
                "<br>"+ QS_Year + "</I>",
                "Ok: copy to clipboard",
                "Quit")
            == 0)
        Store.clipboard()->setText("ImageD version " + D_QS_Version + ", " + D_QS_Author + ", Gesellschaft fuer Schwerionenforschung Darmstadt, " + QS_Year);
}

void D_MainWindow::on_pushButton_Ref_Contact_clicked()
{
    QStringList QSL_Topics = {
        "Other",
        "Base Program",
        "Something is missing",
        "Algorithm",
        "Concept",
        "Design",
        "Analysis Tool",
        "Main Window",
        "Step Window"
    };
    for(int p = 0; p < QSL_Plugins.size(); p++)
        QSL_Topics.append("Plugin: " + QSL_Plugins[p]);
    int index = 1;
    D_Popup_ListSelect pop(
                "Please select the Topic",
                &index,
                QSL_Topics,
                1);
    pop.exec();

    QString QS_Topic = QSL_Topics[index];

    QSysInfo SI;

    QString QS_Username = qgetenv("USER");
        if (QS_Username.isEmpty())
            QS_Username = qgetenv("USERNAME");

    QString QS_MailAdress   = "D.Eilenstein@gsi.de";
    QString QS_Subject      = "ImageD - " + QS_Topic;
    QString QS_Body         =
            "Hello David Eilenstein,"
            "\ni have a question about ImageD (" + QS_Topic + "):"
            "\n"
            "\n"
            "\n"
            "\n ____________________________"
            "\n Version:      " + D_QS_Version +
            "\n Release:      " + D_QS_Release +
            "\n Time:         " + QDateTime::currentDateTime().date().toString(Qt::SystemLocaleShortDate) +
            "\n User:         " + QS_Username +
            "\n Machine:      " + SI.machineHostName() +
            "\n System:       " + SI.productType() +
            "\n Version:      " + SI.productVersion() +
            "\n CPU build:    " + SI.buildCpuArchitecture() +
            "\n CPU current:  " + SI.currentCpuArchitecture();

    QString QS_HTML_Magic   = "mailto:?to=" + QS_MailAdress + "&subject=" + QS_Subject + "&body=" + QS_Body;

    QDesktopServices::openUrl(QUrl(QS_HTML_Magic, QUrl::TolerantMode));
}

void D_MainWindow::on_pushButton_Ref_GSI_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.gsi.de/en/start/news.htm"));
}

void D_MainWindow::on_pushButton_Ref_Biophysics_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.gsi.de/en/work/research/biophysics.htm"));
}

void D_MainWindow::on_pushButton_Ref_hda_clicked()
{
    QDesktopServices::openUrl(QUrl("https://h-da.com/"));
}

void D_MainWindow::on_pushButton_Ref_OBV_clicked()
{
    QDesktopServices::openUrl(QUrl("https://fbmn.h-da.de/index.php/Studienangebote/OBV"));
}

void D_MainWindow::on_pushButton_Ref_OpenCV_clicked()
{
    QDesktopServices::openUrl(QUrl("https://opencv.org/"));
}

void D_MainWindow::on_pushButton_Ref_Qt_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.qt.io/"));
}

void D_MainWindow::on_pushButton_Ref_Docs_clicked()
{
    QDesktopServices::openUrl(QUrl("https://davideilenstein.github.io/ImageD/index.html"));
}

void D_MainWindow::on_pushButton_Ref_Github_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/DavidEilenstein/ImageD"));
}
void D_MainWindow::on_actionTest_DPF_Writer_triggered()
{
    QString QS_Path = QFileDialog::getSaveFileName(
                this,
                "Select target PDF path",
                Store.dir_Test()->path() + "/Test.PDF",
                "(*PDF)");
    if(QS_Path.isEmpty())
        return;

    Store.set_dir_Test(QS_Path);

    D_PDF_Writer pdf_writer(QS_Path);
    pdf_writer.add_Image(
                &QI_Step_Image,
                "A photon walks into a bar and it doesn't.\n"
                "ImageD version " + D_QS_Version + " (" + D_QS_Release + ")\n"
                "Execution Date " + QDateTime::currentDateTime().toString(),
                20,
                Qt::AlignLeft);
    pdf_writer.add_NewPage();
    pdf_writer.add_Headline("epsilon < 0");
    pdf_writer.add_NewPage();
    pdf_writer.add_Text("Boring block of text.");
    pdf_writer.add_NewPage();
    pdf_writer.add_Image(&QI_Step_Image, "Awesome testing text:\n\nDas Quark sich gern im Hadron tummelt,\nwenn es durch die Gegend bummelt.");
    pdf_writer.add_NewPage();
    pdf_writer.add_Text("Top left quater",  0, 0.5, 0, 0.5, 20, Qt::AlignCenter);
    pdf_writer.add_Text("Bottom right quater", 0.5, 1, 0.5, 1, 20, Qt::AlignCenter);
    pdf_writer.add_Image(&QI_Step_Image, 0.5, 1, 0, 0.5);
    pdf_writer.add_Image(&QI_Step_Image, 0, 0.5, 0.5, 1);
    pdf_writer.save_PDF();
}



void D_MainWindow::on_actionTest_Running_Median_triggered()
{
    //data
    qDebug() << "D_MainWindow::on_actionTest_Running_Median_triggered" << "get data";
    vector<double> vDataInit = {1, 2, 3, 4, 5, 10, 0, 10, 0, 1, 3, 5, 7, 100, 1, 100, 100, 100, 1, 1, 100, 1, 1};
    D_Popup_ListEdit_Numbers pop_edit(&vDataInit, "Plese enter values to be filtered", this);
    pop_edit.exec();
    vector<uchar> vDataIn = pop_edit.vData_UChar();


    //filter
    qDebug() << "D_MainWindow::on_actionTest_Running_Median_triggered" << "filter";
    vector<uchar> vDataOut;
    D_Math::MedianRunning(
                &vDataOut,
                vDataIn,
                3);

    //show
    QString QS_in;
    for(size_t i = 0; i <  vDataIn.size(); i++)
        QS_in.append(QString::number(vDataIn[i]) + " ");
    QString QS_out;
    for(size_t i = 0; i <  vDataOut.size(); i++)
        QS_out.append(QString::number(vDataOut[i]) + " ");
    QMessageBox::information(
                this,
                "Running median result",
                "in\n" + QS_in + "\nout\n" + QS_out);

    /*
    //combined results
    qDebug() << "D_MainWindow::on_actionTest_Running_Median_triggered" << "combine";
    vector<vector<double>> vvInOut(2);
    vvInOut[0].reserve(vDataIn.size());
    for(size_t i = 0; i < vDataIn.size(); i++)
        vvInOut[0][i] = vDataIn[i];
    vvInOut[0].reserve(vDataIn.size());
    for(size_t i = 0; i < vDataIn.size(); i++)
        vvInOut[0][i] = vDataIn[i];
    QStringList QSL_SeriesNames = {"In", "Out"};

    //show results
    qDebug() << "D_MainWindow::on_actionTest_Running_Median_triggered" << "show plot";
    D_Popup_Plot pop_plot(
                "Median Filtering Results",
                "order",
                "value",
                "Running median filtering",
                QSL_SeriesNames,
                vvInOut,
                c_PLOT_SIMPLE_LINE_POINT,
                true,
                this);
    pop_plot.exec();
*/

    qDebug() << "D_MainWindow::on_actionTest_Running_Median_triggered" << "end";
}

void D_MainWindow::on_actionTest_Maximum_Gil_triggered()
{
    //data
    qDebug() << "D_MainWindow::on_actionTest_Maximum_Gil_triggered" << "get data";
    //vector<double> vDataIn = {1, 2, 3, 4, 5, 4, 3, 2, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 9, 5, 5, 5, 5, 1, 5, 5, 5, 5};
    vector<double> vDataIn = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1, 5, 5, 5, 4, 4, 3, 4, 3, 4, 5, 6, 7};
    //vector<double> vDataIn = {6, 9, 5, 2, 5, 3, 7, 2, 9, 8, 0, 8, 7, 6, 0, 0, 8, 8, 4, 3, 6, 2, 1, 4, 3, 6, 8, 7};
    D_Popup_ListEdit_Numbers pop_edit(&vDataIn, "Please enter values to be filtered", this);
    pop_edit.exec();
    vDataIn = pop_edit.vData_Double();


    //filter
    qDebug() << "D_MainWindow::on_actionTest_Maximum_Gil_triggered" << "filter";
    vector<double> vDataOut;
    size_t mask_size = 11;
    D_Math::Maximum_Gil(
                &vDataOut,
                &vDataIn,
                mask_size);

    //show
    QString QS_Data;
    for(size_t i = 0; i <  vDataIn.size() && i <  vDataOut.size(); i++)
    {
        if(i % mask_size == 0)
            QS_Data.append("----------\n");
        QS_Data.append(QString::number(vDataIn[i]) + " -> " + QString::number(vDataOut[i]) + "\n");
    }

    QMessageBox::information(
                this,
                "maximum gil result",
                QS_Data);
}
