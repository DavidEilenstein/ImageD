/************************************
 *   added:     ??.10.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_makro_ciliaspheretracker.h"
#include "ui_d_makro_ciliaspheretracker.h"

D_MAKRO_CiliaSphereTracker::D_MAKRO_CiliaSphereTracker(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_CiliaSphereTracker)
{
    //Ui
    ui->setupUi(this);

    //Storeage
    pStore = pStorage;

    //Viewer
    View_Proc.set_GV(ui->graphicsView_Proc);
    View_Results.set_GV(ui->graphicsView_Results);
    View_Results.Set_Transformation_Mode(true);
    View_Proc.connect_Zoom(&View_Results);

    //Plot
    pChartView_Results_Line = new QChartView();
    D_Plot::Plot_Empty(pChartView_Results_Line, "Plot Initialized (Line)");
    ui->gridLayout_ResPlotLine->addWidget(pChartView_Results_Line);
    pChartView_Results_Line->setRenderHint(QPainter::Antialiasing);
    pChartView_Results_Line->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Results_Line->setInteractive(true);

    pChartView_Results_Poincare = new QChartView();
    D_Plot::Plot_Empty(pChartView_Results_Poincare, "Plot Initialized (Poincare)");
    ui->gridLayout_ResPlotPoincare->addWidget(pChartView_Results_Poincare);
    pChartView_Results_Poincare->setRenderHint(QPainter::Antialiasing);
    pChartView_Results_Poincare->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Results_Poincare->setInteractive(true);

    pChartView_Results_Overview_SpeedLine = new QChartView();
    D_Plot::Plot_Empty(pChartView_Results_Overview_SpeedLine, "Plot Initialized (Overview, Speed, Line)");
    ui->gridLayout_Res_Overview_SpeedLine->addWidget(pChartView_Results_Overview_SpeedLine);
    pChartView_Results_Overview_SpeedLine->setRenderHint(QPainter::Antialiasing);
    pChartView_Results_Overview_SpeedLine->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Results_Overview_SpeedLine->setInteractive(true);

    pChartView_Results_Overview_SpeedPoincare = new QChartView();
    D_Plot::Plot_Empty(pChartView_Results_Overview_SpeedPoincare, "Plot Initialized (Overview, Speed, Poincare)");
    ui->gridLayout_Res_Overview_SpeedPoincare->addWidget(pChartView_Results_Overview_SpeedPoincare);
    pChartView_Results_Overview_SpeedPoincare->setRenderHint(QPainter::Antialiasing);
    pChartView_Results_Overview_SpeedPoincare->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Results_Overview_SpeedPoincare->setInteractive(true);
    pChartView_Results_Overview_SpeedPoincare->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);


    pChartView_Results_Overview_AngleLine = new QChartView();
    D_Plot::Plot_Empty(pChartView_Results_Overview_AngleLine, "Plot Initialized (Overview, Angle, Line)");
    ui->gridLayout_Res_Overview_AngleLine->addWidget(pChartView_Results_Overview_AngleLine);
    pChartView_Results_Overview_AngleLine->setRenderHint(QPainter::Antialiasing);
    pChartView_Results_Overview_AngleLine->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Results_Overview_AngleLine->setInteractive(true);

    pChartView_Results_Overview_AnglePoincare = new QChartView();
    D_Plot::Plot_Empty(pChartView_Results_Overview_AnglePoincare, "Plot Initialized (Overview, Angle, Poincare)");
    ui->gridLayout_Res_Overview_AnglePoincare->addWidget(pChartView_Results_Overview_AnglePoincare);
    pChartView_Results_Overview_AnglePoincare->setRenderHint(QPainter::Antialiasing);
    pChartView_Results_Overview_AnglePoincare->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Results_Overview_AnglePoincare->setInteractive(true);
    pChartView_Results_Overview_AnglePoincare->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    //Table
    Table_Results.set_TW(ui->tableWidget_Results);

    //Images
    vMA_ProcSteps.resize(STEP_NUMBER_OF);
    for(size_t s = 0; s < STEP_NUMBER_OF; s++)
        vMA_ProcSteps[s] = pStore->get_Adress(0)->clone();
    MA_TimeProject_Sum = pStore->get_Adress(0)->clone();
    MA_TimeProject_LastBinary = pStore->get_Adress(0)->clone();
    MA_TimeProject_Show = pStore->get_Adress(0)->clone();
    MA_Result = pStore->get_Adress(0)->clone();

    //Populate
    Populate_CB_Start();

    //Connects
    //data
    connect(ui->pushButton_Data_Add,                                SIGNAL(clicked(bool)),                      this,                   SLOT(Data_Add()));
    connect(ui->action_Data_Add,                                    SIGNAL(triggered()),                        this,                   SLOT(Data_Add()));
    connect(ui->pushButton_Data_Clear,                              SIGNAL(clicked(bool)),                      this,                   SLOT(Data_Clear()));
    connect(ui->action_Data_Clear,                                  SIGNAL(triggered()),                        this,                   SLOT(Data_Clear()));
    //update
    connect(ui->pushButton_Proc_FullVideo,                          SIGNAL(clicked(bool)),                      this,                   SLOT(Update_VideoProc_All()));
    connect(ui->action_Save_Analysis_All,                           SIGNAL(triggered()),                        this,                   SLOT(Save_AnalysisAll()));
    //graphics
    connect(ui->checkBox_Res_TimeProjSum_ColorHigh,                 SIGNAL(stateChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->checkBox_Res_TimeProjSum_ColorLow,                  SIGNAL(stateChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->checkBox_Res_TimeProjSum_Gamma,                     SIGNAL(stateChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_TimeProjSum_Gamma,                SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_TimeProjSum_ColorLow,             SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_TimeProjSum_ColorHigh,            SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    //Vector field
    connect(ui->comboBox_Res_VectorFieldParam_Length_Value,         SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_VectorFieldParam_Length_Error,         SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_VectorFieldParam_Angle_Value,          SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_VectorFieldParam_Angle_Error,          SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->spinBox_Res_VectorFieldParam_KindeySteps,           SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->spinBox_Res_VectorFieldParam_Thickness_Vector,      SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->spinBox_Res_VectorFieldParam_Thickness_Error,       SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds, SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_VectorFieldParam_ScaleLength,     SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    //grid
    //connect(ui->spinBox_ParamGridHorizontal,                      SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));    treated separatly in slot
    //connect(ui->spinBox_ParamGridVertical,                        SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));    treated separatly in slot
    connect(ui->spinBox_ParamGrid_CellStart,                        SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->spinBox_ParamGrid_CellEnd,                          SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    //grid vis
    connect(ui->checkBox_Res_GridVisParam_Grid,                     SIGNAL(stateChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->checkBox_Res_GridVisParam_Labels,                   SIGNAL(stateChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->spinBox_Res_GridVisParam_Thickness_Grid,            SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->spinBox_Res_GridVisParam_Thickness_Label,           SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_GridVisParam_Label_Scaling,       SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    //custom analysis
    connect(ui->comboBox_Res_SpeedCustom_Stat_Value,                SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_SpeedCustom_Stat_Uncertanty,           SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_AngleCustom_Stat_Value,                SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_AngleCustom_Stat_Uncertanty,           SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    //moving average (mostly treated separatly)
    connect(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect,           SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    //plot ranges
    connect(ui->comboBox_Res_PlotLine_FixRange_T,                   SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->checkBox_Res_PlotLine_FixRange_S,                   SIGNAL(stateChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->checkBox_Res_PlotLine_FixRange_A,                   SIGNAL(stateChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_PlotLine_FixRange_T_min,          SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_PlotLine_FixRange_T_max,          SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min,          SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_PlotLine_FixRange_S_max,          SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_PlotLine_FixRange_A_min,          SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_PlotLine_FixRange_A_max,          SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    //heatmap
    connect(ui->comboBox_Res_Heat_Mode,                             SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));


    //on start
    this->showMaximized();
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    setWindowTitle("ImageD - Cilia Microsphere Tracker");
    Update_Images();

    //hide not needed params for results
    Update_Ui_ResParam();

    //Load stuff on startup
    Data_Add();
}

D_MAKRO_CiliaSphereTracker::~D_MAKRO_CiliaSphereTracker()
{
    delete ui;
}

void D_MAKRO_CiliaSphereTracker::closeEvent(QCloseEvent *event)
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

void D_MAKRO_CiliaSphereTracker::resizeEvent(QResizeEvent *event)
{
    event->accept();
    Update_Views();
}

void D_MAKRO_CiliaSphereTracker::Update_Ui()
{
    bool en_in = this->isEnabled();
    if(en_in)
        this->setEnabled(false);

    this->repaint();
    qApp->processEvents();

    if(en_in)
        this->setEnabled(true);
}

void D_MAKRO_CiliaSphereTracker::Update_Views()
{
    View_Proc.Update_View();
    View_Results.Update_View();

    pChartView_Results_Overview_SpeedPoincare->setBaseSize(pChartView_Results_Overview_SpeedPoincare->height(), pChartView_Results_Overview_SpeedPoincare->height());
    pChartView_Results_Overview_AnglePoincare->setBaseSize(pChartView_Results_Overview_AnglePoincare->height(), pChartView_Results_Overview_AnglePoincare->height());
}

void D_MAKRO_CiliaSphereTracker::Update_Images()
{
    Update_Image_Proc();
    Update_Image_Results();
}

void D_MAKRO_CiliaSphereTracker::Update_Image_Proc()
{
    int step_cur = ui->comboBox_Proc_Step->currentIndex();
    View_Proc.Set_Transformation_Mode(step_cur < STEP_BINARY);
    View_Proc.Update_Image(&(vMA_ProcSteps[static_cast<size_t>(step_cur)]));
}

void D_MAKRO_CiliaSphereTracker::Update_Image_Results()
{
    View_Results.Update_Image(&MA_Result);
}

void D_MAKRO_CiliaSphereTracker::Update_ImgProc_All()
{
    if(!state_VideosLoaded || !state_VideoSelected)
        return;

    Update_ImgProc(0);
}

void D_MAKRO_CiliaSphereTracker::Update_ImgProc(int step_start)
{
    if(!state_VideosLoaded || !state_VideoSelected)
        return;

    for(int s = step_start; s < STEP_NUMBER_OF; s++)
        Update_ImgProc_Step(s);

    Update_Images();
}

void D_MAKRO_CiliaSphereTracker::Update_ImgProc_Step(int step)
{
    if(!state_VideosLoaded || !state_VideoSelected)
        return;

    //state_GridSamplingSplit = false;
    //state_ImgProcUp2date = false;
    //state_set_VidProcUp2date(false);

    //current img
    //int vid = ui->comboBox_Data_Videos->currentIndex();

    switch (step) {

    case STEP_LOAD:
    {
        ERR(VS_InputVideo.get_FramePos(
                &(vMA_ProcSteps[STEP_LOAD]),
                ui->horizontalSlider_Proc_Frame->value()),
            "Update_ImgProc_Step",
            "STEP_LOAD ");
    }
        break;

    case STEP_GRAY:
    {
        ERR(D_Img_Proc::Convert_Color2Mono(
                &(vMA_ProcSteps[STEP_GRAY]),
                &(vMA_ProcSteps[STEP_LOAD]),
                c_COL2MONO_GREEN),
            "Update_ImgProc_Step",
            "STEP_GRAY");
    }
        break;

    case STEP_CROP:
    {
        ERR(D_Img_Proc::Crop_Rect_Abs(
                &(vMA_ProcSteps[STEP_CROP]),
                &(vMA_ProcSteps[STEP_GRAY]),
                ui->spinBox_Param_Crop_Left->value(),
                ui->spinBox_Param_Crop_Top->value(),
                spatial_roi_width,
                spatial_roi_height),
            "Update_ImgProc_Step",
            "STEP_CROP");
    }
        break;

    case STEP_BLUR:
    {
        ERR(D_Img_Proc::Filter_Gauss(
                &(vMA_ProcSteps[STEP_BLUR]),
                &(vMA_ProcSteps[STEP_CROP]),
                ui->spinBox_Param_Blur_Size->value(),
                ui->spinBox_Param_Blur_Size->value(),
                BORDER_DEFAULT,
                ui->doubleSpinBox_Param_Blur_Sigma->value(),
                ui->doubleSpinBox_Param_Blur_Sigma->value()),
            "Update_ImgProc_Step",
            "STEP_BLUR");
    }
        break;

    case STEP_BINARY:
    {
        ERR(D_Img_Proc::Threshold_Auto(
                &(vMA_ProcSteps[STEP_BINARY]),
                &(vMA_ProcSteps[STEP_BLUR]),
                CV_THRESH_BINARY,
                255,
                CV_THRESH_OTSU),
            "Update_ImgProc_Step",
            "STEP_BINARY");

        state_ImgProcUp2date = true;
    }
        break;

    default:
        break;
    }
}

void D_MAKRO_CiliaSphereTracker::Update_VideoProc_All()
{
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected)
        return;

    state_VidProcActive = true;
    state_TimeProjectInit = false;
    state_GridSamplingSplit = false;

    //trigger frame update by ui
    ui->spinBox_Proc_Frame->setValue(ui->spinBox_Proc_Frame->maximum()); //move to end at the beginning to make sure forst iteration is a change of value -> update

    //init time projection
    TimeProjectSum_Init();
    ui->comboBox_Res_Type->setCurrentIndex(RES_GRAPHICS_TIME_SUM_PROJ);

    //displayed step
    ui->comboBox_Proc_Step->setCurrentIndex(STEP_BINARY);

    //memory for frames for smoothing (init with black ones)
    int frames_smooth_count = ui->spinBox_Param_FrameCountSmooth->value();
    vector<Mat> vMA_tmp_MemoryFrames(
                frames_smooth_count,
                Mat::zeros(vMA_ProcSteps[STEP_BINARY].size(), CV_8UC1));

    //memory for centroids
    vector<vector<Point2f>> vvCentroidsMemory(
                frames_smooth_count,
                vector<Point2f>(0));

    //frames range
    int frame_cur = ui->spinBox_Proc_Frame->minimum();
    int frame_max = ui->spinBox_Proc_Frame->maximum();
    //int frame_range = frame_max - frame_cur;
    //int frame_range_smooth = frame_range - frames_smooth_count + 1;

    //clear containers for results
    vv_FrmObjPositions.clear();
    vv_FrmObjShifts.clear();
    vv_FrmObjAngles.clear();

    //loop frames
    int frame_index_effective = 0;
    while(frame_cur <= frame_max)
    {
        //index of new frame in circular list
        int index_NewImg = frame_index_effective % frames_smooth_count;
        qDebug() << "==================================================================" << "frame" << frame_cur << "/" << frame_index_effective << "index_NewImg =" << index_NewImg;

        //triggers image processing update
        ui->spinBox_Proc_Frame->setValue(frame_cur);

        //Time Projection Sum
        TimeProjectSum_Add();
        Update_Result_GraphicsTimeProjectSum();

        //get current binary frame
        vMA_tmp_MemoryFrames[index_NewImg] = vMA_ProcSteps[STEP_BINARY];

        //Tracking
        if(frame_index_effective < frames_smooth_count - 1)
        {
            //Fill centroid buffer
            ERR(D_Img_Proc::Calc_Centroids(
                        &((vvCentroidsMemory)[index_NewImg]),
                        &((vMA_tmp_MemoryFrames)[index_NewImg]),
                        8),
                "Update_VideoProc_All",
                "Calc_Centroids");
        }
        else
        {
            //Tracking (img and centroid buffer full)

            //result containers for this frame
            vector<Point2f> vPositions;
            vector<double> vShifts_PxPerFrm;
            vector<double> vShifts;
            vector<double> vAngles;

            //test parameters:
            //qDebug() << "vMA_tmp_MemoryFrames.size() =" << vMA_tmp_MemoryFrames.size();
            //qDebug() << "vvCentroidsMemory.size() =" << vvCentroidsMemory.size();

            //Track
            int ER = D_Img_Proc::ObjectsMovement(
                        &vShifts,
                        &vAngles,
                        &vPositions,
                        &vMA_tmp_MemoryFrames,
                        &vvCentroidsMemory,
                        ui->doubleSpinBox_Param_MaxSpeed->value(),
                        index_NewImg,
                        8);
            ERR(ER,
                "Update_VideoProc_All",
                "D_Img_Proc::ObjectsMovement");
            if(ER != ER_okay)
            {
                state_set_VidProcUp2date(false);
                state_VidProcActive = false;
                return;
            }

            //Save Results in Container describing whole video
            vv_FrmObjPositions.push_back(vPositions);
            vv_FrmObjShifts.push_back(vShifts);
            vv_FrmObjAngles.push_back(vAngles);



            //--------------------------------------
            //test stats
            /*
            //qDebug() << "vShifts" << vShifts;
            vector<double> vShifts_Stats;
            ERR(D_Stat::Calc_Stats(
                    &vShifts_Stats,
                    vShifts,
                    false),
                "Update_VideoProc_All",
                "D_Stat::Calc_Stats");
            qDebug() << "Stats Shifts: Mean" << vShifts_Stats[c_STAT_MEAN_ARITMETIC] << "- SD" << vShifts_Stats[c_STAT_STAN_DEV_SAMPLE] << "- SEM" << vShifts_Stats[c_STAT_SEM_ABS_SAMPLE];

            //qDebug() << "vAngles" << vAngles;
            vector<double> vAngles_Stats;
            ERR(D_Stat::Calc_Stats_Circ_Rad(
                    &vAngles_Stats,
                    vAngles),
                "Update_VideoProc_All",
                "D_Stat::Calc_Stats_Circ_Rad");
            qDebug() << "Stats Angles: Mean" << vAngles_Stats[c_STAT_CIRC_MEAN_ANG] << "- Err (0,1)" << vAngles_Stats[c_STAT_CIRC_BALANCE] << "- Err (1 Sigma / Full Circle)" << vAngles_Stats[c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA];
            */
            //--------------------------------------

        }

        //show and increment
        Update_Ui();
        frame_index_effective++;
        frame_cur++;
    }

    state_set_VidProcUp2date(true);

    Data_CalcFullVideoStats();

    state_VidProcActive = false;

    //split data to grid
    Data_Split2GridSampling();
    Update_Results();
}

void D_MAKRO_CiliaSphereTracker::TimeProjectSum_Init()
{
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_ImgProcUp2date)
        return;

    MA_TimeProject_Sum.release();
    MA_TimeProject_Show.release();
    MA_TimeProject_LastBinary.release();
    MA_Result.release();

    MA_Result = Mat::zeros(vMA_ProcSteps[STEP_CROP].size(), CV_32SC1);
    MA_TimeProject_Sum = Mat::zeros(vMA_ProcSteps[STEP_CROP].size(), CV_32SC1);
    MA_TimeProject_Show = Mat::zeros(vMA_ProcSteps[STEP_CROP].size(), CV_32SC1);
    MA_TimeProject_LastBinary = Mat(vMA_ProcSteps[STEP_CROP].size(), CV_8UC1, Scalar(255));

    state_TimeProjectInit = true;
}

void D_MAKRO_CiliaSphereTracker::TimeProjectSum_Add()
{
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_ImgProcUp2date || !state_TimeProjectInit)
        return;

    //get regions of change
    Mat MA_tmp_Difference;
    ERR(D_Img_Proc::Math_ImgImg_Diff(
            &MA_tmp_Difference,
            &(vMA_ProcSteps[STEP_BINARY]),
            &MA_TimeProject_LastBinary),
        "TimeProjectSum_Add",
        "Math_ImgImg_Diff");
    MA_tmp_Difference = vMA_ProcSteps[STEP_BINARY].clone();

    //accumulate
    ERR(D_Img_Proc::Math_Special_IncreaseIfSet(
            &MA_TimeProject_Sum,
            &MA_tmp_Difference),
        "TimeProjectSum_Add",
        "Math_Special_IncreaseIfSet");

    //save current binary as last binary for next frame
    MA_TimeProject_LastBinary.release();
    MA_TimeProject_LastBinary = vMA_ProcSteps[STEP_BINARY].clone();

    MA_tmp_Difference.release();
}

void D_MAKRO_CiliaSphereTracker::Update_Results()
{
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_ImgProcUp2date)
        return;

    if(!state_VidProcUp2date && ui->comboBox_Res_Type->currentIndex() != RES_GRAPHICS_TIME_SUM_PROJ)
        return;

    switch (ui->comboBox_Res_Type->currentIndex()) {
    case RES_GRAPHICS_TIME_SUM_PROJ:        Update_Result_GraphicsTimeProjectSum();     break;
    case RES_GRAPHICS_VECTORS:              Update_Result_GraphicsVectors();            break;
    case RES_GRAPHICS_HEATMAP:              Update_Result_GraphicsHeatmap();            break;
    case RES_SPEED_STAT_CUSTOM:             Update_Result_SpeedStatCustom();            break;
    case RES_ANGLE_STAT_CUSTOM:             Update_Result_AngleStatCustom();            break;
    case RES_SPEED_ANALYSIS:                Update_Result_SpeedAnalysis();              break;
    case RES_ANGLE_ANALYSIS:                Update_Result_AngleAnalysis();              break;
    case RES_OVERVIEW:
    {
        Update_Result_SpeedAnalysis();
        Update_Result_AngleAnalysis();
    }
        break;
    default:                                                                            return;}
}

void D_MAKRO_CiliaSphereTracker::Update_Result_GraphicsTimeProjectSum()
{
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_ImgProcUp2date)
        return;

    bool    color_low       = ui->checkBox_Res_TimeProjSum_ColorLow->isChecked();
    bool    color_high      = ui->checkBox_Res_TimeProjSum_ColorHigh->isChecked();
    bool    gamma_correct   = ui->checkBox_Res_TimeProjSum_Gamma->isChecked();
    double  gamma           = ui->doubleSpinBox_Res_TimeProjSum_Gamma->value();
    double  rel_thresh_low  = ui->doubleSpinBox_Res_TimeProjSum_ColorLow->value() / 100.0;
    double  rel_thresh_high = ui->doubleSpinBox_Res_TimeProjSum_ColorHigh->value() / 100.0;

    if(!gamma_correct)
        gamma = 1.0;

    MA_TimeProject_Show.release();
    ERR(D_Img_Proc::ExtremeValuesColor(
            &MA_TimeProject_Show,
            &MA_TimeProject_Sum,
            rel_thresh_low,
            rel_thresh_high,
            gamma,
            color_low,
            color_high,
            true),
        "Update_Result_TimeProjectSum",
        "ExtremeValuesColor");

    //copy to image to show
    //MA_TimeProject_Show is recyclet by other graphics results functions
    MA_Result.release();
    MA_Result = MA_TimeProject_Show.clone();

    Update_Image_Results();
}

void D_MAKRO_CiliaSphereTracker::Update_Result_GraphicsVectors()
{
    //Check requirements
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_ImgProcUp2date || !state_GridSamplingSplit || !state_VidProcUp2date)
    {
        qDebug() << "Update_Result_GraphicsVectors" << "requirements not met";
        return;
    }

    //Update background img
    if(ui->comboBox_Res_MovAv_TimeWindow->currentIndex() == TIME_WINDOW_FULL_VIDEO || ui->comboBox_Res_MovAv_Background->currentIndex() == BACKGR_PROJECTION)
    {
        Update_Result_GraphicsTimeProjectSum();
    }
    else
    {
        Mat MA_tmp_SelectedFrame = VS_InputVideo.get_FramePos(ui->horizontalSlider_Res_MovAv_CurrentEnd->value()).clone();

        Mat MA_tmp_FrameGreenChannel;
        ERR(
                    D_Img_Proc::Convert_Color2Mono(
                        &MA_tmp_FrameGreenChannel,
                        &MA_tmp_SelectedFrame,
                        c_COL2MONO_GREEN),
                    "Update_Result_GraphicsVectors",
                    "Convert_Color2Mono");
        MA_tmp_SelectedFrame.release();

        Mat MA_tmp_Cropped;
        ERR(D_Img_Proc::Crop_Rect_Abs(
                &MA_tmp_Cropped,
                &MA_tmp_FrameGreenChannel,
                ui->spinBox_Param_Crop_Left->value(),
                ui->spinBox_Param_Crop_Top->value(),
                spatial_roi_width,
                spatial_roi_height),
            "Update_Result_GraphicsVectors",
            "Crop_Rect_Abs");
        MA_tmp_FrameGreenChannel.release();

        ERR(
                    D_Img_Proc::Convert_Color(
                        &MA_TimeProject_Show,
                        &MA_tmp_Cropped,
                        CV_GRAY2BGR),
                    "Update_Result_GraphicsVectors",
                    "Convert_Color - 1ch->3ch");
        MA_tmp_Cropped.release();
    }

    //stats selected
    int stat_length_val = ui->comboBox_Res_VectorFieldParam_Length_Value->currentIndex();
    int stat_length_err = ui->comboBox_Res_VectorFieldParam_Length_Error->currentIndex();
    int stat_angle_val  = ui->comboBox_Res_VectorFieldParam_Angle_Value->currentIndex();
    int stat_angle_err  = ui->comboBox_Res_VectorFieldParam_Angle_Error->currentIndex();

    //time window
    size_t it_start     = ui->horizontalSlider_Res_MovAv_CurrentStart->value() - frame_start_ana;
    size_t it_end       = ui->horizontalSlider_Res_MovAv_CurrentEnd->value()   - frame_start_ana;
    if(ui->comboBox_Res_MovAv_TimeWindow->currentIndex() == TIME_WINDOW_FULL_VIDEO)
    {
        it_start = 0;
        it_end = frame_end - frame_start_ana;
    }
    //qDebug() << "Update_Result_GraphicsVectors" << "it_start" << it_start << "it_end" << it_end;

    //grid size
    size_t nx = vvvv_XYFrmObjShifts.size();
    size_t ny = vvvv_XYFrmObjShifts[0].size();

    //length scaling
    double shift_scale = ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->value() * VS_InputVideo.get_FrameRateFps();    //before stats calcs
    double radius_scale = ui->doubleSpinBox_Res_VectorFieldParam_ScaleLength->value();                                          //visualization only

    //containers of data to be shown

    vector<vector<double>> vv_XY_LengthValues(nx);
    vector<vector<double>> vv_XY_LengthErrors(nx);
    vector<vector<double>> vv_XY_AngleValues(nx);
    vector<vector<double>> vv_XY_AngleErrors(nx);
    for(size_t gx = 0; gx < nx; gx++)
    {
        vv_XY_LengthValues[gx].resize(ny);
        vv_XY_LengthErrors[gx].resize(ny);
        vv_XY_AngleValues[gx].resize(ny);
        vv_XY_AngleErrors[gx].resize(ny);
    }

    //loop grid cells
    for(size_t gx = 0; gx < nx; gx++)
    {
        for(size_t gy = 0; gy < ny; gy++)
        {
            //group all needed elements in 1D container
            vector<double> v_ShiftsInCell;
            vector<double> v_AnglesInCell;

            //loop time window
            for(size_t it = it_start; it < it_end; it++)
            {
                //number of objects in cell and frame
                size_t no = vvvv_XYFrmObjShifts[gx][gy][it].size();

                //loop, extract and rescale lengths
                for(size_t obj = 0; obj < no; obj++)
                {
                    v_ShiftsInCell.push_back(vvvv_XYFrmObjShifts[gx][gy][it][obj] * shift_scale);
                    v_AnglesInCell.push_back(vvvv_XYFrmObjAngles[gx][gy][it][obj]);
                }
            }

            //calc stats
            vector<double> v_Shifts_Stats;
            vector<double> v_Angles_Stats(c_STAT_CIRC_NUMBER_OF, 2);

            D_Stat::Calc_Stats(
                        &v_Shifts_Stats,
                        v_ShiftsInCell,
                        true);

            D_Stat::Calc_Stats_Circ_Rad(
                        &v_Angles_Stats,
                        v_AnglesInCell);

            //Export needed stats
            vv_XY_LengthValues[gx][gy] = v_Shifts_Stats[stat_length_val] * radius_scale;
            vv_XY_LengthErrors[gx][gy] = v_Shifts_Stats[stat_length_err] * radius_scale;
            vv_XY_AngleValues[gx][gy] = v_Angles_Stats[stat_angle_val];
            vv_XY_AngleErrors[gx][gy] = v_Angles_Stats[stat_angle_err];

            //Test Output
            //qDebug() << "Update_Result_GraphicsVectors at gx/gy" << gx << gy << "length:" << vv_XY_LengthValues[gx][gy] << vv_XY_LengthErrors[gx][gy] << "angle:" << vv_XY_AngleValues[gx][gy] << vv_XY_AngleErrors[gx][gy];

            //clear
            v_ShiftsInCell.clear();
            v_AnglesInCell.clear();
            v_Shifts_Stats.clear();
            v_Angles_Stats.clear();
        }
    }

    //draw vector field
    Mat MA_tmp_overlay = Mat::zeros(MA_TimeProject_Show.size(), CV_8UC1);
    //qDebug() << "Update_Result_GraphicsVectors" << "Draw_VectorField";
    ERR(D_Img_Proc::Draw_VectorField(
            &MA_tmp_overlay,
            vv_XY_LengthValues,
            vv_XY_AngleValues,
            vv_XY_LengthErrors,
            vv_XY_AngleErrors,
            255,
            ui->spinBox_Res_VectorFieldParam_Thickness_Vector->value(),
            ui->spinBox_Res_VectorFieldParam_KindeySteps->value(),
            ui->spinBox_Res_VectorFieldParam_Thickness_Error->value(),
            ui->checkBox_Res_GridVisParam_Grid->isChecked(),
            ui->spinBox_Res_GridVisParam_Thickness_Grid->value(),
            ui->checkBox_Res_GridVisParam_Labels->isChecked(),
            ui->spinBox_Res_GridVisParam_Thickness_Label->value(),
            ui->doubleSpinBox_Res_GridVisParam_Label_Scaling->value()),
        "Update_Result_GraphicsVectors",
        "Draw_VectorField");

    //add overlay to image
    //qDebug() << "Update_Result_GraphicsVectors" << "OverlayOverwrite";
    ERR(D_Img_Proc::OverlayOverwrite(
            &MA_Result,
            &MA_TimeProject_Show,
            &MA_tmp_overlay,
            0, 255, 0,
            1.0,
            1.0),
        "Update_Result_GraphicsVectors",
        "OverlayOverwrite");
    MA_tmp_overlay.release();
    qDebug() << "check";

    //clear
    vv_XY_LengthValues.clear();
    vv_XY_LengthErrors.clear();
    vv_XY_AngleValues.clear();
    vv_XY_AngleErrors.clear();

    //show result
    Update_Image_Results();
}

void D_MAKRO_CiliaSphereTracker::Update_Result_GraphicsHeatmap()
{
    //Check requirements
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_ImgProcUp2date || !state_GridSamplingSplit || !state_VidProcUp2date)
        return;

    //update graphics background
    Update_Result_GraphicsTimeProjectSum();

    //only use red channel (red is value in interval, below it is 0 and above it is max)
    Mat MA_tmp_Value_Gray;
    int ER = D_Img_Proc::Split(
                &MA_tmp_Value_Gray,
                &MA_TimeProject_Show,
                2);
    if(ER != ER_okay)
    {
        ERR(
                    ER,
                    "Update_Result_GraphicsHeatmap",
                    "Split (Color->Red)");
        MA_tmp_Value_Gray.release();
        return;
    }

    //max movements detected
    double value_min, value_max;
    ER = D_Img_Proc::MinMax_of_Mat(
                &MA_TimeProject_Sum,
                &value_min,
                &value_max);
    if(ER != ER_okay)
    {
        ERR(
                    ER,
                    "Update_Result_GraphicsHeatmap",
                    "MinMax_of_Mat");
        MA_tmp_Value_Gray.release();
        return;
    }

    //Heatmap
    ER = D_Img_Proc::ObjectsMovement_Heatmap(
                &MA_Result,
                &MA_Result_HeatmapLegend,
                &MA_tmp_Value_Gray,
                vv_FrmObjPositions,
                vv_FrmObjShifts,
                vv_FrmObjAngles,
                conv_px2um * VS_InputVideo.get_FrameRateFps(),  // px/frm -> um/sec (as a factor to be applied to px/frm value)
                value_max / 255.0,                              // factor for 8bit gray value to movements count
                5, 5,                                           //blur
                ui->comboBox_Res_Heat_Mode->currentIndex(),     //what to show
                1500, 99,                                       //legend size
                1.0, 1,                                         //font size
                5,                                              //examples on legend count
                0.1, 0.9);                                      //quantile range dor values to be shown
    if(ER != ER_okay)
    {
        ERR(
                    ER,
                    "Update_Result_GraphicsHeatmap",
                    "ObjectsMovement_Heatmap");
        MA_tmp_Value_Gray.release();
        return;
    }

    //Show result
    Update_Image_Results();

    MA_tmp_Value_Gray.release();
}

void D_MAKRO_CiliaSphereTracker::Update_Result_SpeedStatCustom()
{
    //Check requirements
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_GridSamplingSplit || !state_VidProcUp2date)
    {
        D_Plot::Plot_Empty(pChartView_Results_Line, "Reqirements for Update_Result_SpeedStatCustom failed");
        D_Plot::Plot_Empty(pChartView_Results_Poincare, "Reqirements for Update_Result_SpeedStatCustom failed");
        Table_Results.clear_data();
        return;
    };

    //error checker
    int ER;

    //stat selected
    size_t stat = static_cast<size_t>(ui->comboBox_Res_SpeedCustom_Stat_Value->currentIndex());

    //time window
    size_t nt_all = frame_end - frame_start_ana - movav_window_frames;
    size_t nt_win = movav_window_frames;
    double rel_FramesWithDetReq = ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value() / 100.0;
    double abs_FramesWithDetReq = nt_win * rel_FramesWithDetReq;

    //selected range
    size_t cell_start = static_cast<size_t>(ui->spinBox_ParamGrid_CellStart->value());
    size_t cell_end = static_cast<size_t>(ui->spinBox_ParamGrid_CellEnd->value());
    if(cell_end < cell_start)
    {
        D_Plot::Plot_Empty(pChartView_Results_Line, "cell_end < cell_start");
        D_Plot::Plot_Empty(pChartView_Results_Poincare, "cell_end < cell_start");
        Table_Results.clear_data();
        return;
    }

    //grid size & selection
    size_t ngx_all = vvvv_XYFrmObjShifts.size();
    size_t ngy_all = vvvv_XYFrmObjShifts[0].size();
    size_t ng_all = ngx_all * ngy_all;
    //size_t n_sub = cell_end - cell_start;
    if(cell_end > ng_all)
    {
        //correct invalid cell selection to a working one
        ui->spinBox_ParamGrid_CellEnd->blockSignals(true);
        ui->spinBox_ParamGrid_CellEnd->setValue(static_cast<int>(ng_all));
        ui->spinBox_ParamGrid_CellEnd->blockSignals(false);
        cell_end = static_cast<size_t>(ui->spinBox_ParamGrid_CellEnd->value());
    }

    //shift scaling (shift/frame -> shift/second)
    double conv_perFrame2perSecond = VS_InputVideo.get_FrameRateFps();  //before stats calcs
    double conv_Frame2Second = VS_InputVideo.get_FrameTimeSec();        //for x axis

    //containers of data to be shown
    vector<vector<double>> vv_ValuesX;
    vector<vector<double>> vv_ValuesY;
    QStringList QSL_SeriesNames;

    //loop grid cells
    size_t cell_index_all = 0;
    size_t cell_index_sub = 0;
    for(size_t gy = 0; gy < ngy_all; gy++)
        for(size_t gx = 0; gx < ngx_all; gx++)
        {
            //check cell index
            if(cell_index_all >= cell_start && cell_index_all < cell_end)
            {
                //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy;

                //containers for time series in selected cell
                vector<double> v_CellTimeSeries_X;
                vector<double> v_CellTimeSeries_Y;

                //loop time (each t gives a result = point on the line to plot)
                for(size_t it_start = 0; it_start < nt_all; it_start++)
                {
                    //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy << "Frame start at:" << it_start << "start loop time window";

                    //group all needed elements in 1D container (in cell and time window at current it_start)
                    vector<double> v_Shifts_InCellInTimeWindow;

                    //loop time window for current start time
                    size_t count_DetectionsInARow = 0;
                    size_t it_end = it_start + nt_win;
                    for(size_t it_cur = it_start; it_cur < it_end; it_cur++)
                    {
                        //number of objects in cell and frame
                        size_t no = vvvv_XYFrmObjShifts[gx][gy][it_cur].size();

                        //count frames in a row with at least one detetction
                        if(no)
                            count_DetectionsInARow++;
                        else
                            count_DetectionsInARow = 0;

                        //loop objects
                        for(size_t obj = 0; obj < no; obj++)
                        {
                            //scale to shift/second and export
                            v_Shifts_InCellInTimeWindow.push_back(vvvv_XYFrmObjShifts[gx][gy][it_cur][obj] * conv_perFrame2perSecond * conv_px2um);
                        }
                    }

                    //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy << "Frame start at:" << it_start << "loop time window success. Elements:" << v_Shifts_InCellInTimeWindow.size();

                    if(count_DetectionsInARow >= abs_FramesWithDetReq)
                    {
                        //calc stats
                        vector<double> v_Stats;
                        ER = D_Stat::Calc_Stats(
                                    &v_Stats,
                                    v_Shifts_InCellInTimeWindow,
                                    true);

                        if(ER == ER_okay)
                        {
                            //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy << "Frame start at:" << it_start << "point added:" << it_start * conv_perFrame2perSecond << v_Stats[stat] << "TRY";

                            //save result in container
                            v_CellTimeSeries_X.push_back((it_start + frame_start_ana) * conv_Frame2Second);
                            v_CellTimeSeries_Y.push_back(v_Stats[stat]);

                            //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy << "Frame start at:" << it_start << "point added:" << it_start * conv_perFrame2perSecond << v_Stats[stat];
                        }
                    }
                }

                //append/pushback results for cell
                QSL_SeriesNames.append("GridCell_" + QString::number(cell_index_all));
                vv_ValuesX.push_back(v_CellTimeSeries_X);
                vv_ValuesY.push_back(v_CellTimeSeries_Y);

                //increase cell index (only chosen cells)
                cell_index_sub++;
            }

            //increase cell index (all cells)
            cell_index_all++;
        }

    //Plot Line
    ER = D_Plot::Plot_Line_XY_Multi(
                pChartView_Results_Line,
                vv_ValuesX,
                vv_ValuesY,
                "<b>" + QSL_StatList[static_cast<int>(stat)] + " of Speed</b>"
                "<br>" + ui->comboBox_Data_Videos->currentText() +
                "<br>"
                "<br>Moving average over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + "s"
                "<br>Considered time windows with at least one detetction in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of frames",
                QSL_SeriesNames,
                "Time/s",
                QSL_StatList[static_cast<int>(stat)] + " of Speed um/s",
                true,
                true,
                true,
            Qt::AlignLeft);
    if(ER != ER_okay)
    {
        D_Plot::Plot_Empty(pChartView_Results_Line, "Calc worked, Plot failed");
        D_Plot::Plot_Empty(pChartView_Results_Poincare, "Calc worked, Plot failed");
        Table_Results.clear_data();
        return;
    }


    //cosmetic stuff for the plot

    if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_CUSTOM)
        pChartView_Results_Line->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_T_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_T_max->value());
    else if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_VIDEO_LENGTH)
        pChartView_Results_Line->chart()->axes(Qt::Horizontal).back()->setRange(0, VS_InputVideo.get_DurationSec());

    if(ui->checkBox_Res_PlotLine_FixRange_S->isChecked())
            pChartView_Results_Line->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max->value());

    //pChartView_Results_Line->chart()->legend()->setAlignment(Qt::AlignLeft);
}

void D_MAKRO_CiliaSphereTracker::Update_Result_AngleStatCustom()
{
    //Check requirements
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_GridSamplingSplit || !state_VidProcUp2date || !state_StatSummaryCalced)
    {
        D_Plot::Plot_Empty(pChartView_Results_Line, "Reqirements for Update_Result_AngleStatCustom failed");
        D_Plot::Plot_Empty(pChartView_Results_Poincare, "Reqirements for Update_Result_AngleStatCustom failed");
        Table_Results.clear_data();
        return;
    };

    //error checker
    int ER;

    //stat selected
    size_t stat = static_cast<size_t>(ui->comboBox_Res_AngleCustom_Stat_Value->currentIndex());

    //time window
    size_t nt_all = frame_end - frame_start_ana - movav_window_frames;
    size_t nt_win = movav_window_frames;
    double rel_FramesWithDetReq = ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value() / 100.0;
    double abs_FramesWithDetReq = nt_win * rel_FramesWithDetReq;

    //selected range
    size_t cell_start = static_cast<size_t>(ui->spinBox_ParamGrid_CellStart->value());
    size_t cell_end = static_cast<size_t>(ui->spinBox_ParamGrid_CellEnd->value());
    if(cell_end < cell_start)
    {
        D_Plot::Plot_Empty(pChartView_Results_Line, "cell_end < cell_start");
        D_Plot::Plot_Empty(pChartView_Results_Poincare, "cell_end < cell_start");
        Table_Results.clear_data();
        return;
    }

    //grid size & selection
    size_t ngx_all = vvvv_XYFrmObjAngles.size();
    size_t ngy_all = vvvv_XYFrmObjAngles[0].size();
    size_t ng_all = ngx_all * ngy_all;
    //size_t n_sub = cell_end - cell_start;
    if(cell_end > ng_all)
    {
        //correct invalid cell selection to a working one
        ui->spinBox_ParamGrid_CellEnd->blockSignals(true);
        ui->spinBox_ParamGrid_CellEnd->setValue(static_cast<int>(ng_all));
        ui->spinBox_ParamGrid_CellEnd->blockSignals(false);
        cell_end = static_cast<size_t>(ui->spinBox_ParamGrid_CellEnd->value());
    }

    //time scaling (frame -> second)
    double conv_Frame2Second = VS_InputVideo.get_FrameTimeSec();        //for x axis

    //angle offset
    double angle_mean_full_video = v_VideoStats_Angles_Rad[c_STAT_CIRC_MEAN_ANG];

    //containers of data to be shown
    vector<vector<double>> vv_ValuesX;
    vector<vector<double>> vv_ValuesY;
    QStringList QSL_SeriesNames;

    //loop grid cells
    size_t cell_index_all = 0;
    size_t cell_index_sub = 0;
    for(size_t gy = 0; gy < ngy_all; gy++)
        for(size_t gx = 0; gx < ngx_all; gx++)
        {
            //check cell index
            if(cell_index_all >= cell_start && cell_index_all < cell_end)
            {
                //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy;

                //containers for time series in selected cell
                vector<double> v_CellTimeSeries_X;
                vector<double> v_CellTimeSeries_Y;

                //loop time (each t gives a result = point on the line to plot)
                for(size_t it_start = 0; it_start < nt_all; it_start++)
                {
                    //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy << "Frame start at:" << it_start << "start loop time window";

                    //group all needed elements in 1D container (in cell and time window at current it_start)
                    vector<double> v_Angles_InCellInTimeWindow;

                    //loop time window for current start time
                    size_t count_DetectionsInARow = 0;
                    size_t it_end = it_start + nt_win;
                    for(size_t it_cur = it_start; it_cur < it_end; it_cur++)
                    {
                        //number of objects in cell and frame
                        size_t no = vvvv_XYFrmObjAngles[gx][gy][it_cur].size();

                        //count frames in a row with at least one detetction
                        if(no)
                            count_DetectionsInARow++;
                        else
                            count_DetectionsInARow = 0;

                        //loop objects
                        for(size_t obj = 0; obj < no; obj++)
                        {
                            //HERE THE DATA COMES FROM
                            //scale to shift/second and export
                            v_Angles_InCellInTimeWindow.push_back(
                                        D_Math::Distance_AngleRad_Shortest_Signed(
                                            vvvv_XYFrmObjAngles[gx][gy][it_cur][obj],
                                            angle_mean_full_video)
                                        * Rad2Grad);
                        }
                    }

                    //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy << "Frame start at:" << it_start << "loop time window success. Elements:" << v_Shifts_InCellInTimeWindow.size();

                    if(count_DetectionsInARow >= abs_FramesWithDetReq)
                    {
                        //calc stats
                        vector<double> v_Stats;
                        ER = D_Stat::Calc_Stats_Circ_Grad(
                                    &v_Stats,
                                    v_Angles_InCellInTimeWindow);

                        if(ER == ER_okay)
                        {
                            //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy << "Frame start at:" << it_start << "point added:" << it_start * conv_perFrame2perSecond << v_Stats[stat] << "TRY";

                            //save result in container
                            v_CellTimeSeries_X.push_back((it_start + frame_start_ana) * conv_Frame2Second);
                            v_CellTimeSeries_Y.push_back(v_Stats[stat]);

                            //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy << "Frame start at:" << it_start << "point added:" << it_start * conv_perFrame2perSecond << v_Stats[stat];
                        }
                    }
                }

                //append/pushback results for cell
                QSL_SeriesNames.append("GridCell_" + QString::number(cell_index_all));
                vv_ValuesX.push_back(v_CellTimeSeries_X);
                vv_ValuesY.push_back(v_CellTimeSeries_Y);

                //increase cell index (only chosen cells)
                cell_index_sub++;
            }

            //increase cell index (all cells)
            cell_index_all++;
        }

    //Plot Line
    ER = D_Plot::Plot_Line_XY_Multi(
                pChartView_Results_Line,
                vv_ValuesX,
                vv_ValuesY,
                "<b>" + QSL_StatListCirc[static_cast<int>(stat)] + " of Angles</b>"
                "<br>" + ui->comboBox_Data_Videos->currentText() +
                "<br>"
                "<br>Moving average over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + "s"
                "<br>Considered time windows with at least one detetction in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of frames"
                "<br>Normed to difference to mean angle of full video",
                QSL_SeriesNames,
                "Time/s",
                QSL_StatListCirc[static_cast<int>(stat)] + " of Angle/°",
                true,
                true,
                true,
            Qt::AlignLeft);
    if(ER != ER_okay)
    {
        D_Plot::Plot_Empty(pChartView_Results_Line, "Calc worked, Plot failed");
        D_Plot::Plot_Empty(pChartView_Results_Poincare, "Calc worked, Plot failed");
        Table_Results.clear_data();
        return;
    }


    //cosmetic stuff for the plot

    if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_CUSTOM)
        pChartView_Results_Line->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_T_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_T_max->value());
    else if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_VIDEO_LENGTH)
        pChartView_Results_Line->chart()->axes(Qt::Horizontal).back()->setRange(0, VS_InputVideo.get_DurationSec());

    if(ui->checkBox_Res_PlotLine_FixRange_A->isChecked())
            pChartView_Results_Line->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_A_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_A_max->value());

    //pChartView_Results_Line->chart()->legend()->setAlignment(Qt::AlignLeft);
}

void D_MAKRO_CiliaSphereTracker::Update_Result_SpeedAnalysis()
{
    //Check requirements
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_GridSamplingSplit || !state_VidProcUp2date)
    {
        D_Plot::Plot_Empty(pChartView_Results_Line, "Reqirements for Update_Result_SpeedAnalysis failed");
        D_Plot::Plot_Empty(pChartView_Results_Poincare, "Reqirements for Update_Result_SpeedAnalysis failed");
        Table_Results.clear_data();

        if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW)
        {
            D_Plot::Plot_Empty(pChartView_Results_Overview_SpeedLine, "Reqirements for Update_Result_SpeedAnalysis failed");
            D_Plot::Plot_Empty(pChartView_Results_Overview_SpeedPoincare, "Reqirements for Update_Result_SpeedAnalysis failed");
        }

        return;
    };

    //error checker
    int ER;

    //time window
    size_t nt_all = frame_end - frame_start_ana - movav_window_frames;
    size_t nt_win = movav_window_frames;
    double rel_FramesWithDetReq = ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value() / 100.0;
    double abs_FramesWithDetReq = nt_win * rel_FramesWithDetReq;

    //shift scaling (shift/frame -> shift/second)
    double conv_perFrame2perSecond = VS_InputVideo.get_FrameRateFps();  //before stats calcs
    double conv_Frame2Second = VS_InputVideo.get_FrameTimeSec();        //for x axis

    //selected stats
    size_t stat_val = ui->comboBox_Res_SpeedCustom_Stat_Value->currentIndex();
    size_t stat_unc = ui->comboBox_Res_SpeedCustom_Stat_Uncertanty->currentIndex();

    //containers of data to be shown
    vector<double> v_ValuesX;
    vector<vector<double>> vv_ValuesY(PLOT_SUMMARY_NUMBER_OF);
    QStringList QSL_SeriesNames = {
        ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + " - " + ui->comboBox_Res_SpeedCustom_Stat_Uncertanty->currentText(),
        ui->comboBox_Res_SpeedCustom_Stat_Value->currentText(),
        ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + " + " + ui->comboBox_Res_SpeedCustom_Stat_Uncertanty->currentText()
    };

    //loop time (each t gives a result = point on the line to plot)
    for(size_t it_start = 0; it_start < nt_all; it_start++)
    {
        //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy << "Frame start at:" << it_start << "start loop time window";

        //group all needed elements in 1D container (in time window at current it_start)
        vector<double> v_Shifts_InTimeWindow;

        //loop time window for current start time
        size_t count_DetectionsInARow = 0;
        size_t it_end = it_start + nt_win;
        for(size_t it_cur = it_start; it_cur < it_end; it_cur++)
        {
            //number of objects in cell and frame
            size_t no = vv_FrmObjShifts[it_cur].size();

            //count frames in a row with at least one detetction
            if(no)
                count_DetectionsInARow++;
            else
                count_DetectionsInARow = 0;

            //loop objects
            for(size_t obj = 0; obj < no; obj++)
            {
                //scale to shift/second and export
                v_Shifts_InTimeWindow.push_back(vv_FrmObjShifts[it_cur][obj] * conv_perFrame2perSecond * conv_px2um);
            }
        }

        //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy << "Frame start at:" << it_start << "loop time window success. Elements:" << v_Shifts_InCellInTimeWindow.size();

        if(count_DetectionsInARow >= abs_FramesWithDetReq)
        {
            //calc stats
            vector<double> v_Stats;
            ER = D_Stat::Calc_Stats(
                        &v_Stats,
                        v_Shifts_InTimeWindow,
                        true);

            if(ER == ER_okay)
            {
                //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy << "Frame start at:" << it_start << "point added:" << it_start * conv_perFrame2perSecond << v_Stats[stat] << "TRY";

                //save result in container
                v_ValuesX.push_back((it_start + frame_start_ana) * conv_Frame2Second);
                vv_ValuesY[PLOT_SUMMARY_LOW].push_back(v_Stats[stat_val] - v_Stats[stat_unc]);
                vv_ValuesY[PLOT_SUMMARY_MID].push_back(v_Stats[stat_val]);
                vv_ValuesY[PLOT_SUMMARY_HIGH].push_back(v_Stats[stat_val] + v_Stats[stat_unc]);

                //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy << "Frame start at:" << it_start << "point added:" << it_start * conv_perFrame2perSecond << v_Stats[stat];
            }
        }
    }

    if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW)
    {
        //Plot Line
        ER = D_Plot::Plot_Line_XY_Multi(
                    pChartView_Results_Overview_SpeedLine,
                    v_ValuesX,
                    vv_ValuesY,
                    "<b>Speed, Line</b>"
                    "<br>" + ui->comboBox_Data_Videos->currentText() +
                    "<br>"
                    "<br>Moving average over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + "s"
                    "<br>Considered time windows with at least one detetction in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of frames",
                    QSL_SeriesNames,
                    "Time/s",
                    "Stats of speed /(um/s)",
                    true,
                    true,
                    true,
                    Qt::AlignTop);

        //Plot Poincare
        ER = D_Plot::Plot_Poincare_XY_Single(
                    pChartView_Results_Overview_SpeedPoincare,
                    vv_ValuesY[PLOT_SUMMARY_MID],
                    "<b>Speed, Poincare</b>"
                    "<br>" + ui->comboBox_Data_Videos->currentText() +
                    "<br>"
                    "<br>Moving average over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + "s"
                    "<br>Considered time windows with at least one detetction in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of frames",
                    QSL_SeriesNames[PLOT_SUMMARY_MID],
                    QSL_SeriesNames[PLOT_SUMMARY_MID] + " of Speed /(um/s) at t",
                    QSL_SeriesNames[PLOT_SUMMARY_MID] + "<br>of Speed /(um/s)<br>at t+" + QString::number(ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->value()) + "s",
                    ui->spinBox_Res_PlotPoincare_Shift_Frames->value(),
                    true,
                    true,
                    true,
                    Qt::AlignTop);

        pChartView_Results_Overview_SpeedPoincare->setFixedSize(pChartView_Results_Overview_SpeedPoincare->height(), pChartView_Results_Overview_SpeedPoincare->height());
    }
    else
    {
        //Plot Line
        ER = D_Plot::Plot_Line_XY_Multi(
                    pChartView_Results_Line,
                    v_ValuesX,
                    vv_ValuesY,
                    "<b>Main Speed Analysis</b>"
                    "<br>" + ui->comboBox_Data_Videos->currentText() +
                    "<br>"
                    "<br>Moving average over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + "s"
                    "<br>Considered time windows with at least one detetction in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of frames",
                    QSL_SeriesNames,
                    "Time/s",
                    "Stats of speed /(um/s)",
                    true,
                    true,
                    true,
                    Qt::AlignTop);

        //Plot Poincare
        ER = D_Plot::Plot_Poincare_XY_Single(
                    pChartView_Results_Poincare,
                    vv_ValuesY[PLOT_SUMMARY_MID],
                    "<b>Main Speed Analysis</b>"
                    "<br>" + ui->comboBox_Data_Videos->currentText() +
                    "<br>"
                    "<br>Moving average over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + "s"
                    "<br>Considered time windows with at least one detetction in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of frames",
                    QSL_SeriesNames[PLOT_SUMMARY_MID],
                    QSL_SeriesNames[PLOT_SUMMARY_MID] + " of Speed /(um/s) at t",
                    QSL_SeriesNames[PLOT_SUMMARY_MID] + " of Speed /(um/s) at t+" + QString::number(ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->value()) + "s",
                    ui->spinBox_Res_PlotPoincare_Shift_Frames->value(),
                    true,
                    true,
                    true,
                    Qt::AlignTop);
    }

    if(ER != ER_okay)
    {
        D_Plot::Plot_Empty(pChartView_Results_Line, "Calc worked, Plot failed");
        D_Plot::Plot_Empty(pChartView_Results_Poincare, "Calc worked, Plot failed");
        Table_Results.clear_data();

        if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW)
        {
            D_Plot::Plot_Empty(pChartView_Results_Overview_SpeedLine, "Calc worked, Plot failed");
            D_Plot::Plot_Empty(pChartView_Results_Overview_SpeedPoincare, "Calc worked, Plot failed");
        }
        return;
    }

    //cosmetic stuff for the plot
    if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW)
    {
        if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_CUSTOM)
            pChartView_Results_Overview_SpeedLine->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_T_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_T_max->value());
        else if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_VIDEO_LENGTH)
            pChartView_Results_Overview_SpeedLine->chart()->axes(Qt::Horizontal).back()->setRange(0, VS_InputVideo.get_DurationSec());

        if(ui->checkBox_Res_PlotLine_FixRange_S->isChecked())
        {
            pChartView_Results_Overview_SpeedLine->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max->value());
            pChartView_Results_Overview_SpeedPoincare->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max->value());
            pChartView_Results_Overview_SpeedPoincare->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max->value());
        }
    }
    else
    {
        if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_CUSTOM)
            pChartView_Results_Line->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_T_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_T_max->value());
        else if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_VIDEO_LENGTH)
            pChartView_Results_Line->chart()->axes(Qt::Horizontal).back()->setRange(0, VS_InputVideo.get_DurationSec());

        if(ui->checkBox_Res_PlotLine_FixRange_S->isChecked())
        {
            pChartView_Results_Line->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max->value());
            pChartView_Results_Poincare->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max->value());
            pChartView_Results_Poincare->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max->value());
        }
    }



    //pChartView_Results_Line->chart()->legend()->setAlignment(Qt::AlignLeft);
}

void D_MAKRO_CiliaSphereTracker::Update_Result_AngleAnalysis()
{
    //Check requirements
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_GridSamplingSplit || !state_VidProcUp2date)
    {
        D_Plot::Plot_Empty(pChartView_Results_Line, "Reqirements for Update_Result_AngleAnalysis failed");
        D_Plot::Plot_Empty(pChartView_Results_Poincare, "Reqirements for Update_Result_AngleAnalysis failed");
        Table_Results.clear_data();

        if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW)
        {
            D_Plot::Plot_Empty(pChartView_Results_Overview_AngleLine, "Reqirements for Update_Result_AngleAnalysis failed");
            D_Plot::Plot_Empty(pChartView_Results_Overview_AnglePoincare, "Reqirements for Update_Result_AngleAnalysis failed");
        }

        return;
    };

    //error checker
    int ER;

    //time window
    size_t nt_all = frame_end - frame_start_ana - movav_window_frames;
    size_t nt_win = movav_window_frames;
    double rel_FramesWithDetReq = ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value() / 100.0;
    double abs_FramesWithDetReq = nt_win * rel_FramesWithDetReq;

    //time scaling (frame -> second)
    double conv_Frame2Second = VS_InputVideo.get_FrameTimeSec();        //for x axis

    //angle offset
    double angle_mean_full_video = v_VideoStats_Angles_Rad[c_STAT_CIRC_MEAN_ANG];

    //selected stats
    size_t stat_val = ui->comboBox_Res_AngleCustom_Stat_Value->currentIndex();
    size_t stat_unc = ui->comboBox_Res_AngleCustom_Stat_Uncertanty->currentIndex();

    //containers of data to be shown
    vector<double> v_ValuesX;
    vector<vector<double>> vv_ValuesY(PLOT_SUMMARY_NUMBER_OF);
    QStringList QSL_SeriesNames = {
        ui->comboBox_Res_AngleCustom_Stat_Value->currentText() + " - " + ui->comboBox_Res_AngleCustom_Stat_Uncertanty->currentText(),
        ui->comboBox_Res_AngleCustom_Stat_Value->currentText(),
        ui->comboBox_Res_AngleCustom_Stat_Value->currentText() + " + " + ui->comboBox_Res_AngleCustom_Stat_Uncertanty->currentText()
    };

    //loop time (each t gives a result = point on the line to plot)
    for(size_t it_start = 0; it_start < nt_all; it_start++)
    {
        //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy << "Frame start at:" << it_start << "start loop time window";

        //group all needed elements in 1D container (in time window at current it_start)
        vector<double> v_Angles_InTimeWindow;

        //loop time window for current start time
        size_t count_DetectionsInARow = 0;
        size_t it_end = it_start + nt_win;
        for(size_t it_cur = it_start; it_cur < it_end; it_cur++)
        {
            //number of objects in cell and frame
            size_t no = vv_FrmObjAngles[it_cur].size();

            //count frames in a row with at least one detetction
            if(no)
                count_DetectionsInARow++;
            else
                count_DetectionsInARow = 0;

            //loop objects
            for(size_t obj = 0; obj < no; obj++)
            {
                //norm and export
                v_Angles_InTimeWindow.push_back(
                            D_Math::Distance_AngleRad_Shortest_Signed(
                                vv_FrmObjAngles[it_cur][obj],
                                angle_mean_full_video)
                            * Rad2Grad);
            }
        }

        if(count_DetectionsInARow >= abs_FramesWithDetReq)
        {
            //calc stats
            vector<double> v_Stats;
            ER = D_Stat::Calc_Stats_Circ_Grad(
                        &v_Stats,
                        v_Angles_InTimeWindow);

            if(ER == ER_okay)
            {
                //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy << "Frame start at:" << it_start << "point added:" << it_start * conv_perFrame2perSecond << v_Stats[stat] << "TRY";

                //save result in container
                v_ValuesX.push_back((it_start + frame_start_ana) * conv_Frame2Second);
                vv_ValuesY[PLOT_SUMMARY_LOW].push_back(v_Stats[stat_val] - v_Stats[stat_unc]);
                vv_ValuesY[PLOT_SUMMARY_MID].push_back(v_Stats[stat_val]);
                vv_ValuesY[PLOT_SUMMARY_HIGH].push_back(v_Stats[stat_val] + v_Stats[stat_unc]);

                //qDebug() << "cell accepted:" << cell_index_all << "gx/gy" << gx << gy << "Frame start at:" << it_start << "point added:" << it_start * conv_perFrame2perSecond << v_Stats[stat];
            }
        }
    }

    if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW)
    {
        //Plot Line
        ER = D_Plot::Plot_Line_XY_Multi(
                    pChartView_Results_Overview_AngleLine,
                    v_ValuesX,
                    vv_ValuesY,
                    "<b>Angle, Line</b>"
                    "<br>" + ui->comboBox_Data_Videos->currentText() +
                    "<br>"
                    "<br>Moving average over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + "s"
                    "<br>Considered time windows with at least one detetction in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of frames"
                    "<br>Normed to difference to mean angle of full video",
                    QSL_SeriesNames,
                    "Time/s",
                    "Stats of angles/°",
                    true,
                    true,
                    true,
                    Qt::AlignTop);

        //Plot Poincare
        ER = D_Plot::Plot_Poincare_XY_Single(
                    pChartView_Results_Overview_AnglePoincare,
                    vv_ValuesY[PLOT_SUMMARY_MID],
                    "<b>Angle, Poincare</b>"
                    "<br>" + ui->comboBox_Data_Videos->currentText() +
                    "<br>"
                    "<br>Moving average over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + "s"
                    "<br>Considered time windows with at least one detetction in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of frames"
                    "<br>Normed to difference to mean angle of full video",
                    QSL_SeriesNames[PLOT_SUMMARY_MID],
                    QSL_SeriesNames[PLOT_SUMMARY_MID] + " of Angle /° at t",
                    QSL_SeriesNames[PLOT_SUMMARY_MID] + "<br>of Angle /°<br>at t+" + QString::number(ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->value()) + "s",
                    ui->spinBox_Res_PlotPoincare_Shift_Frames->value(),
                    true,
                    true,
                    true,
                    Qt::AlignTop);

        pChartView_Results_Overview_AnglePoincare->setFixedSize(pChartView_Results_Overview_AnglePoincare->height(), pChartView_Results_Overview_AnglePoincare->height());
    }
    else
    {
        //Plot Line
        ER = D_Plot::Plot_Line_XY_Multi(
                    pChartView_Results_Line,
                    v_ValuesX,
                    vv_ValuesY,
                    "<b>Main Angle Analysis</b>"
                    "<br>" + ui->comboBox_Data_Videos->currentText() +
                    "<br>"
                    "<br>Moving average over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + "s"
                    "<br>Considered time windows with at least one detetction in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of frames"
                    "<br>Normed to difference to mean angle of full video",
                    QSL_SeriesNames,
                    "Time/s",
                    "Stats of angles/°",
                    true,
                    true,
                    true,
                    Qt::AlignTop);

        //Plot Poincare
        ER = D_Plot::Plot_Poincare_XY_Single(
                    pChartView_Results_Poincare,
                    vv_ValuesY[PLOT_SUMMARY_MID],
                    "<b>Main Angle Analysis</b>"
                    "<br>" + ui->comboBox_Data_Videos->currentText() +
                    "<br>"
                    "<br>Moving average over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + "s"
                    "<br>Considered time windows with at least one detetction in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of frames"
                    "<br>Normed to difference to mean angle of full video",
                    QSL_SeriesNames[PLOT_SUMMARY_MID],
                    QSL_SeriesNames[PLOT_SUMMARY_MID] + " of Angle /° at t",
                    QSL_SeriesNames[PLOT_SUMMARY_MID] + " of Angle /° at t+" + QString::number(ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->value()) + "s",
                    ui->spinBox_Res_PlotPoincare_Shift_Frames->value(),
                    true,
                    true,
                    true,
                    Qt::AlignTop);
    }



    if(ER != ER_okay)
    {
        D_Plot::Plot_Empty(pChartView_Results_Line, "Calc worked, Plot failed");
        D_Plot::Plot_Empty(pChartView_Results_Poincare, "Calc worked, Plot failed");
        Table_Results.clear_data();

        if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW)
        {
            D_Plot::Plot_Empty(pChartView_Results_Overview_AngleLine, "Calc worked, Plot failed");
            D_Plot::Plot_Empty(pChartView_Results_Overview_AnglePoincare, "Calc worked, Plot failed");
        }

        return;
    }


    //cosmetic stuff for the plot
    if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW)
    {
        if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_CUSTOM)
            pChartView_Results_Overview_AngleLine->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_T_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_T_max->value());
        else if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_VIDEO_LENGTH)
            pChartView_Results_Overview_AngleLine->chart()->axes(Qt::Horizontal).back()->setRange(0, VS_InputVideo.get_DurationSec());

        if(ui->checkBox_Res_PlotLine_FixRange_A->isChecked())
        {
            pChartView_Results_Overview_AngleLine->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_A_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_A_max->value());
            pChartView_Results_Overview_AnglePoincare->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_A_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_A_max->value());
            pChartView_Results_Overview_AnglePoincare->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_A_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_A_max->value());
        }
    }
    else
    {
        if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_CUSTOM)
            pChartView_Results_Line->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_T_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_T_max->value());
        else if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_VIDEO_LENGTH)
            pChartView_Results_Line->chart()->axes(Qt::Horizontal).back()->setRange(0, VS_InputVideo.get_DurationSec());

        if(ui->checkBox_Res_PlotLine_FixRange_A->isChecked())
        {
            pChartView_Results_Line->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_A_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_A_max->value());
            pChartView_Results_Poincare->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_A_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_A_max->value());
            pChartView_Results_Poincare->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_A_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_A_max->value());
        }
    }
}

void D_MAKRO_CiliaSphereTracker::Save_AnalysisAll()
{
    if(!state_VideosLoaded)
        return;

    //path
    QString save_path = QFileDialog::getExistingDirectory(
                this,
                "Select folder to stream the output to.",
                pStore->dir_M_CiliaSphereTracker()->path());

    if(save_path == 0)
        return;

    //create subfolder for output
    unsigned int count = 0;
    QString QS_Folder_Out_Sub = save_path + "/Results_0";
    while(QDir(QS_Folder_Out_Sub).exists())
    {
        count++;
        QS_Folder_Out_Sub = save_path + "/Results_" + QString::number(count);
    }

    //masterfolder

    DIR_SaveMaster.setPath(QS_Folder_Out_Sub);
    QDir().mkdir(DIR_SaveMaster.path());

    //subfolders

    //stack
    //master
    DIR_SaveStack.setPath(DIR_SaveMaster.path() + "/Stack");                            QDir().mkdir(DIR_SaveStack.path());
    //graphics
    DIR_SaveStackGraphics.setPath(DIR_SaveStack.path() + "/Graphics");                  QDir().mkdir(DIR_SaveStackGraphics.path());
    DIR_SaveStackGraphics_Heatmap.setPath(DIR_SaveStackGraphics.path() + "/Heatmap");   QDir().mkdir(DIR_SaveStackGraphics_Heatmap.path());
    DIR_SaveStackGraphics_Vector.setPath(DIR_SaveStackGraphics.path() + "/Vector");     QDir().mkdir(DIR_SaveStackGraphics_Vector.path());
    DIR_SaveStackGraphics_Speed.setPath(DIR_SaveStackGraphics.path() + "/Speed");       QDir().mkdir(DIR_SaveStackGraphics_Speed.path());
    DIR_SaveStackGraphics_Angle.setPath(DIR_SaveStackGraphics.path() + "/Angle");       QDir().mkdir(DIR_SaveStackGraphics_Angle.path());
    DIR_SaveStackGraphics_Video.setPath(DIR_SaveStackGraphics.path() + "/Video");       QDir().mkdir(DIR_SaveStackGraphics_Video.path());
    //plot
    DIR_SaveStackPlot.setPath(DIR_SaveStack.path() + "/Plot");                          QDir().mkdir(DIR_SaveStackPlot.path());
    DIR_SaveStackPlot_Speed.setPath(DIR_SaveStackPlot.path() + "/Speed");               QDir().mkdir(DIR_SaveStackPlot_Speed.path());
    DIR_SaveStackPlot_Angle.setPath(DIR_SaveStackPlot.path() + "/Angle");               QDir().mkdir(DIR_SaveStackPlot_Angle.path());
    DIR_SaveStackPlot_Overview.setPath(DIR_SaveStackPlot.path() + "/Overview");         QDir().mkdir(DIR_SaveStackPlot_Overview.path());
    //overview
    DIR_SaveStackOverview.setPath(DIR_SaveStack.path() + "/Overview");                  QDir().mkdir(DIR_SaveStackOverview.path());
    //single
    DIR_SaveSingles.setPath(DIR_SaveMaster.path() + "/SingleVideos");                   QDir().mkdir(DIR_SaveSingles.path());

    //Create tables for stats
    ofstream OS_SaveStats_Speed;
    ofstream OS_SaveStats_Angle;
    OS_SaveStats_Speed.open((DIR_SaveStackOverview.path() + "/StackStats_Speed.csv").toStdString());
    OS_SaveStats_Angle.open((DIR_SaveStackOverview.path() + "/StackStats_Angle.csv").toStdString());

    //init stat tables
    OS_SaveStats_Speed
            << "File,"      << "StackStats_Speed.csv" << "\n"
            << "Path,"      << DIR_SaveStackOverview.path().toStdString() << "\n"
            << "DateTime,"  << QDateTime::currentDateTime().toString().toStdString() << "\n"
            << "\n"
            << "Base unit," << "um/s"
            << "\n";
    OS_SaveStats_Angle
            << "File,"      << "StackStats_Angle.csv" << "\n"
            << "Path,"      << DIR_SaveStackOverview.path().toStdString() << "\n"
            << "DateTime,"  << QDateTime::currentDateTime().toString().toStdString() << "\n"
            << "\n"
            << "Base unit," << "grad"
            << "\n";

    //stats as header of columns
    for(int s = 0; s < c_STAT_NUMBER_OF_STATS; s++)
        OS_SaveStats_Speed << "," << QSL_StatList[s].toStdString();
    for(int s = 0; s < c_STAT_CIRC_NUMBER_OF; s++)
        OS_SaveStats_Angle << "," << QSL_StatList[s].toStdString();

    state_StackProcessing = true;

    //loop single videos
    for(int v = 0; v < FIL_Videos.size(); v++)
    {
        //load current video
        ui->comboBox_Data_Videos->setCurrentIndex(v);

        //update, save, etc.
        Save_AnalysisSingle();

        //stream to stat tables
        OS_SaveStats_Speed << "\n" << QSL_Videos_Names[v].toStdString();
        OS_SaveStats_Angle << "\n" << QSL_Videos_Names[v].toStdString();
        for(size_t s = 0; s < v_VideoStats_Shifts_um_s.size(); s++)
            OS_SaveStats_Speed << "," << v_VideoStats_Shifts_um_s[s];
        for(size_t s = 0; s < v_VideoStats_Angles_Grad.size(); s++)
            OS_SaveStats_Angle << "," << v_VideoStats_Angles_Grad[s];
    }

    //close filestreams
    OS_SaveStats_Speed.close();
    OS_SaveStats_Angle.close();

    state_StackProcessing = false;
}

void D_MAKRO_CiliaSphereTracker::Save_AnalysisSingle()
{
    //current video name
    QString name_current = ui->comboBox_Data_Videos->currentText();

    //update needed DIRs
    DIR_SaveCurrent.setPath(DIR_SaveSingles.path() + "/" + name_current);       QDir().mkdir(DIR_SaveCurrent.path());
    DIR_SaveCurrentGraphics.setPath(DIR_SaveCurrent.path() + "/Graphics");      QDir().mkdir(DIR_SaveCurrentGraphics.path());
    DIR_SaveCurrentPlot.setPath(DIR_SaveCurrent.path() + "/Plot");              QDir().mkdir(DIR_SaveCurrentPlot.path());

    //do the analysis
    Update_VideoProc_All();

    //Save the results======================================================

    //create sumary PDF
    D_PDF_Writer PDF_Overview(DIR_SaveStackOverview.path() + "/Overview_" + name_current + ".pdf");
    D_PDF_Writer PDF_Summary(DIR_SaveStackOverview.path() + "/Summary" + name_current + ".pdf");
    PDF_Summary.set_Margins(0, 0, 0, 0);

    //header of summary
    PDF_Summary.add_Text(
                name_current,
                0.05, 0.95, 0.05, 0.10,
                20,
                Qt::AlignCenter);
    PDF_Summary.add_Text("Video analysis summary by ImageD " + D_QS_Version + " (" + D_QS_Release + ") done at " + QDateTime::currentDateTime().toString(),
                0.05, 0.95, 0.10, 0.13,
                10,
                Qt::AlignCenter);

    //percent of detection required
    ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setValue(75);

    //Graphics---------------------------------------------------------------

    //movement tracks only
    ui->comboBox_Res_Type->setCurrentIndex(RES_GRAPHICS_TIME_SUM_PROJ);
    PDF_Overview.add_Image(
                View_Results.QI(),
                name_current + "\n"
                "Video analysis overview\n"
                "\n"
                "ImageD version " + D_QS_Version + " (" + D_QS_Release + ")\n"
                "Analysis done " + QDateTime::currentDateTime().toString(),
                20,
                Qt::AlignCenter);

    //Heatmap
    ui->comboBox_Res_Type->setCurrentIndex(RES_GRAPHICS_HEATMAP);

    ui->comboBox_Res_Heat_Mode->setCurrentIndex(0);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Heatmap.path() + "/HeatmapSpeed - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - HeatmapSpeed.png");

    PDF_Summary.add_Image(
                View_Results.QI(),
                0.51, 0.95, 0.25, 0.50);
    PDF_Summary.add_Image(
                &MA_Result_HeatmapLegend,
                0.51, 0.95, 0.51, 0.54);
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Image(
                View_Results.QI(),
                "Heatmap (Speed)\n"
                "\n"
                "Color: Speed (red <= 10%-quantil, blue => 90%-quantil)\n"
                "Saturation: 100% (no information)\n"
                "Value: Default tracks-graphics"
                "\n"
                "Color map is realative to video content.\n"
                "\n"
                "Useful to get an overview of the spatial speed distribution.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackGraphics_Heatmap.path() + "/HeatmapSpeed - " + name_current + ".png\n" +
                DIR_SaveCurrentGraphics.path() + "/" + name_current + " - HeatmapSpeed.png");

    ui->comboBox_Res_Heat_Mode->setCurrentIndex(1);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Heatmap.path() + "/HeatmapAngle - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - HeatmapAngle.png");
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Image(
                View_Results.QI(),
                "Heatmap (Angle)\n"
                "\n"
                "Color: Angle (red=0°, yellow=60°, green=120°, cyan=180°, blue=240°, magenta=300°)\n"
                "Saturation: 100% (no information)\n"
                "Value: Default tracks-graphics"
                "\n"
                "Useful to get an overview of the spatial angle distribution.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackGraphics_Heatmap.path() + "/HeatmapAngle - " + name_current + ".png\n" +
                DIR_SaveCurrentGraphics.path() + "/" + name_current + " - HeatmapAngle.png");

    ui->comboBox_Res_Heat_Mode->setCurrentIndex(2);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Heatmap.path() + "/HeatmapSpeedAngle - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - HeatmapSpeedAngle.png");
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Image(
                View_Results.QI(),
                "Heatmap (Spped and Angle)\n"
                "\n"
                "Color: Angle (red=0°, yellow=60°, green=120°, cyan=180°, blue=240°, magenta=300°)\n"
                "Saturation: Speed (gray <= 10%-Quantil, intense color >= 90%-Quantil\n"
                "Value: Default tracks-graphics"
                "\n"
                "Useful to get an overview of the spatial speed and angle distribution.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackGraphics_Heatmap.path() + "/HeatmapSpeedAngle - " + name_current + ".png\n" +
                DIR_SaveCurrentGraphics.path() + "/" + name_current + " - HeatmapSpeedAngle.png");

    //stat list
    //Speed
    //long
    QString QS_Stats_Speed = "Statistics of speed in full video:\n"
                             "\n"
                             "Base speed unit is um/s.\n";
    for(size_t s = 0; s < v_VideoStats_Shifts_um_s.size(); s++)
        QS_Stats_Speed.append("\n" + QSL_StatList[static_cast<int>(s)] + ": " + QString::number(v_VideoStats_Shifts_um_s[s]));
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Text(QS_Stats_Speed);
    //short
    PDF_Summary.add_Text(
                "Speed Stats:\n"
                "Average " + QString::number(v_VideoStats_Shifts_um_s[c_STAT_MEAN_ARITMETIC], 'g', 4) + "um/s\n"
                "STD " + QString::number(v_VideoStats_Shifts_um_s[c_STAT_STAN_DEV_SAMPLE], 'g', 4) + "um/s\n"
                "10%-Quantil " + QString::number(v_VideoStats_Shifts_um_s[c_STAT_QUANTIL_10], 'g', 4) + "um/s\n"
                "Median " + QString::number(v_VideoStats_Shifts_um_s[c_STAT_MEDIAN], 'g', 4) + "um/s\n"
                "90%-Quantil " + QString::number(v_VideoStats_Shifts_um_s[c_STAT_QUANTIL_90], 'g', 4) + "um/s",
                0.35, 0.65, 0.13, 0.25,
                10,
                Qt::AlignCenter);
    //Angle
    //long
    QString QS_Stats_Angle = "Statistics of angle in full video:\n"
                             "\n"
                             "Base angle unit is grad.\n";
    for(size_t s = 0; s < v_VideoStats_Angles_Grad.size(); s++)
        QS_Stats_Angle.append("\n" + QSL_StatListCirc[static_cast<int>(s)] + ": " + QString::number(v_VideoStats_Angles_Grad[s]));
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Text(QS_Stats_Angle);
    //short
    PDF_Summary.add_Text(
                "Angle Stats:\n"
                "Average " + QString::number(v_VideoStats_Angles_Grad[c_STAT_CIRC_MEAN_ANG], 'g', 4) + "°\n"
                "Balance " + QString::number(v_VideoStats_Angles_Grad[c_STAT_CIRC_BALANCE] * 100.0, 'g', 4) + "%\n"
                "STD Equivalent " + QString::number(v_VideoStats_Angles_Grad[c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA], 'g', 4) + "°",
                0.65, 0.95, 0.13, 0.25,
                10,
                Qt::AlignCenter);

    //vector field
    ui->comboBox_Res_Type->setCurrentIndex(RES_GRAPHICS_VECTORS);

    //setting 5x4
    ui->comboBox_Res_MovAv_TimeWindow->setCurrentIndex(TIME_WINDOW_FULL_VIDEO);
    ui->comboBox_Res_VectorFieldParam_Length_Value->setCurrentIndex(c_STAT_MEAN_ARITMETIC);
    ui->comboBox_Res_VectorFieldParam_Length_Error->setCurrentIndex(c_STAT_STAN_DEV_SAMPLE);
    ui->comboBox_Res_VectorFieldParam_Angle_Value->setCurrentIndex(c_STAT_CIRC_MEAN_ANG);
    ui->comboBox_Res_VectorFieldParam_Angle_Error->setCurrentIndex(c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA);
    ui->spinBox_ParamGridHorizontal->setValue(5);
    ui->spinBox_ParamGridVertical->setValue(4);
    ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setValue(1.0);
    ui->doubleSpinBox_Res_VectorFieldParam_ScaleLength->setValue(1.0);
    ui->checkBox_Res_GridVisParam_Grid->setChecked(true);
    ui->checkBox_Res_GridVisParam_Labels->setChecked(true);
    ui->spinBox_Res_VectorFieldParam_Thickness_Vector->setValue(3);
    ui->spinBox_Res_VectorFieldParam_Thickness_Error->setValue(2);
    View_Results.Save_Image(DIR_SaveStackGraphics_Vector.path() + "/VectorField4x5 - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorField4x5.png");
    ui->groupBox_Res->grab().save(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorField4x5_Settings.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Image(
                View_Results.QI(),
                "Vector Field 4x5\n"
                "\n"
                "Vector length: " + ui->comboBox_Res_VectorFieldParam_Length_Value->currentText() + " +/- " + ui->comboBox_Res_VectorFieldParam_Length_Error->currentText() + "\n"
                "Vector angle: " + ui->comboBox_Res_VectorFieldParam_Angle_Value->currentText() + " +/- " + ui->comboBox_Res_VectorFieldParam_Angle_Error->currentText() + "\n"
                "\n"
                "Length unit is shift per " + QString::number(ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->value()) + " seconds(s).\n"
                "Image size: (" + QString::number(vMA_ProcSteps[STEP_CROP].cols * conv_px2um) + " x " + QString::number(vMA_ProcSteps[STEP_CROP].rows * conv_px2um) + ")um)\n"
                "\n"
                "The bent ellipse around the vector head can be interpreted as a circular 2D  equivalent of the standard deviation.\n"
                "Useful to get an overview of the movements happening.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackGraphics_Vector.path() + "/VectorField4x5 - " + name_current + ".png\n" +
                DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorField4x5.png");
    //basic info for interpretation
    PDF_Summary.add_Text(
                "Image size: (" + QString::number(vMA_ProcSteps[STEP_CROP].cols * conv_px2um, 'g', 4) + " x " + QString::number(vMA_ProcSteps[STEP_CROP].rows * conv_px2um) + ")um\n"
                "Time analysed: " + QString::number(vv_FrmObjPositions.size() * VS_InputVideo.get_FrameTimeSec(), 'g', 4) + "s\n"
                "Vector length refers to shift/" + QString::number(ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->value(), 'g', 4) + "s\n"
                "Base speed unit: um/s\n"
                "Base angle unit: °\n",
                0.05, 0.35, 0.13, 0.25,
                10,
                Qt::AlignCenter);
    //same img to summary
    PDF_Summary.add_Image(
                View_Results.QI(),
                0.05, 0.49, 0.25, 0.50);
    /*PDF_Summary.add_Text(
                "Vector length refers to shift/" + QString::number(ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->value(), 'g', 4) + "s",
                0.05, 0.49, 0.51, 0.58,
                10,
                Qt::AlignCenter);*/

    //save motion vector field video
    Save_ResultVectorFieldVideo(
                DIR_SaveStackGraphics_Video.path() + "/MotionVectorField4x5 - " + name_current + ".avi",
                5,
                4,
                10,
                BACKGR_VIDEO);

    //setting 10x8
    ui->comboBox_Res_MovAv_TimeWindow->setCurrentIndex(TIME_WINDOW_FULL_VIDEO);
    ui->comboBox_Res_VectorFieldParam_Length_Value->setCurrentIndex(c_STAT_MEAN_ARITMETIC);
    ui->comboBox_Res_VectorFieldParam_Length_Error->setCurrentIndex(c_STAT_STAN_DEV_SAMPLE);
    ui->comboBox_Res_VectorFieldParam_Angle_Value->setCurrentIndex(c_STAT_CIRC_MEAN_ANG);
    ui->comboBox_Res_VectorFieldParam_Angle_Error->setCurrentIndex(c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA);
    ui->spinBox_ParamGridHorizontal->setValue(10);
    ui->spinBox_ParamGridVertical->setValue(8);
    ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setValue(0.5);
    ui->doubleSpinBox_Res_VectorFieldParam_ScaleLength->setValue(1.0);
    ui->checkBox_Res_GridVisParam_Grid->setChecked(true);
    ui->checkBox_Res_GridVisParam_Labels->setChecked(true);
    ui->spinBox_Res_VectorFieldParam_Thickness_Vector->setValue(3);
    ui->spinBox_Res_VectorFieldParam_Thickness_Error->setValue(1);
    View_Results.Save_Image(DIR_SaveStackGraphics_Vector.path() + "/VectorField10x8 - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorField10x8.png");
    ui->groupBox_Res->grab().save(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorField10x8_Settings.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Image(
                View_Results.QI(),
                "Vector Field 10x8\n"
                "\n"
                "Vector length: " + ui->comboBox_Res_VectorFieldParam_Length_Value->currentText() + " +/- " + ui->comboBox_Res_VectorFieldParam_Length_Error->currentText() + "\n"
                "Vector angle: " + ui->comboBox_Res_VectorFieldParam_Angle_Value->currentText() + " +/- " + ui->comboBox_Res_VectorFieldParam_Angle_Error->currentText() + "\n"
                "\n"
                "Length unit is shift per " + QString::number(ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->value()) + " seconds(s).\n"
                "Image size: (" + QString::number(vMA_ProcSteps[STEP_CROP].cols * conv_px2um) + " x " + QString::number(vMA_ProcSteps[STEP_CROP].rows * conv_px2um) + ")um)\n"
                "\n"
                "The bent ellipse around the vector head can be interpreted as a circular 2D  equivalent of the standard deviation.\n"
                "Useful to see smaller detail of the movements happening.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackGraphics_Vector.path() + "/VectorField10x8 - " + name_current + ".png\n" +
                DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorField10x8.png");

    //setting 20x16
    ui->comboBox_Res_MovAv_TimeWindow->setCurrentIndex(TIME_WINDOW_FULL_VIDEO);
    ui->comboBox_Res_VectorFieldParam_Length_Value->setCurrentIndex(c_STAT_MEAN_ARITMETIC);
    ui->comboBox_Res_VectorFieldParam_Length_Error->setCurrentIndex(c_STAT_STAN_DEV_SAMPLE);
    ui->comboBox_Res_VectorFieldParam_Angle_Value->setCurrentIndex(c_STAT_CIRC_MEAN_ANG);
    ui->comboBox_Res_VectorFieldParam_Angle_Error->setCurrentIndex(c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA);
    ui->spinBox_ParamGridHorizontal->setValue(20);
    ui->spinBox_ParamGridVertical->setValue(16);
    ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setValue(0.25);
    ui->doubleSpinBox_Res_VectorFieldParam_ScaleLength->setValue(1.0);
    ui->checkBox_Res_GridVisParam_Grid->setChecked(true);
    ui->checkBox_Res_GridVisParam_Labels->setChecked(false);
    ui->spinBox_Res_VectorFieldParam_Thickness_Vector->setValue(3);
    ui->spinBox_Res_VectorFieldParam_Thickness_Error->setValue(1);
    View_Results.Save_Image(DIR_SaveStackGraphics_Vector.path() + "/VectorField20x16 - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorField20x16.png");
    ui->groupBox_Res->grab().save(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorField20x16_Settings.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Image(
                View_Results.QI(),
                "Vector Field 20x16\n"
                "\n"
                "Vector length: " + ui->comboBox_Res_VectorFieldParam_Length_Value->currentText() + " +/- " + ui->comboBox_Res_VectorFieldParam_Length_Error->currentText() + "\n"
                "Vector angle: " + ui->comboBox_Res_VectorFieldParam_Angle_Value->currentText() + " +/- " + ui->comboBox_Res_VectorFieldParam_Angle_Error->currentText() + "\n"
                "\n"
                "Length unit is shift per " + QString::number(ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->value()) + " seconds(s).\n"
                "Image size: (" + QString::number(vMA_ProcSteps[STEP_CROP].cols * conv_px2um) + " x " + QString::number(vMA_ProcSteps[STEP_CROP].rows * conv_px2um) + ")um)\n"
                "\n"
                "The bent ellipse around the vector head can be interpreted as a circular 2D  equivalent of the standard deviation.\n"
                "Useful to see fine detail of the movements happening.\n"
                "Nothing to see in a grid cell means there are no detections.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackGraphics_Vector.path() + "/VectorField20x16 - " + name_current + ".png\n" +
                DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorField20x16.png");

    //setting angle
    ui->comboBox_Res_MovAv_TimeWindow->setCurrentIndex(TIME_WINDOW_FULL_VIDEO);
    ui->comboBox_Res_VectorFieldParam_Length_Value->setCurrentIndex(c_STAT_CONST_1);
    ui->comboBox_Res_VectorFieldParam_Length_Error->setCurrentIndex(c_STAT_CONST_0);
    ui->comboBox_Res_VectorFieldParam_Angle_Value->setCurrentIndex(c_STAT_CIRC_MEAN_ANG);
    ui->comboBox_Res_VectorFieldParam_Angle_Error->setCurrentIndex(c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA);
    ui->spinBox_ParamGridHorizontal->setValue(20);
    ui->spinBox_ParamGridVertical->setValue(16);
    ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setValue(0.25);
    ui->doubleSpinBox_Res_VectorFieldParam_ScaleLength->setValue(25);
    ui->checkBox_Res_GridVisParam_Grid->setChecked(false);
    ui->checkBox_Res_GridVisParam_Labels->setChecked(false);
    ui->spinBox_Res_VectorFieldParam_Thickness_Vector->setValue(2);
    ui->spinBox_Res_VectorFieldParam_Thickness_Error->setValue(2);
    View_Results.Save_Image(DIR_SaveStackGraphics_Angle.path() + "/VectorFieldAngle - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorFieldAngle.png");
    ui->groupBox_Res->grab().save(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorFieldAngle_Settings.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Image(
                View_Results.QI(),
                "Vector Field Angle\n"
                "\n"
                "Vector length: " + ui->comboBox_Res_VectorFieldParam_Length_Value->currentText() + " +/- " + ui->comboBox_Res_VectorFieldParam_Length_Error->currentText() + "\n"
                "Vector angle: " + ui->comboBox_Res_VectorFieldParam_Angle_Value->currentText() + " +/- " + ui->comboBox_Res_VectorFieldParam_Angle_Error->currentText() + "\n"
                "\n"
                "Length unit is shift per " + QString::number(ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->value()) + " seconds(s).\n"
                "Image size: (" + QString::number(vMA_ProcSteps[STEP_CROP].cols * conv_px2um) + " x " + QString::number(vMA_ProcSteps[STEP_CROP].rows * conv_px2um) + ")um)\n"
                "\n"
                "The vector length is normed and shows no information.\n"
                "The angle and its circular equivalent to the standard deviation is shown.\n"
                "Useful to see the spatially resolved angle distribution independently of speed.\n"
                "Nothing to see in a grid cell means there are no detections.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackGraphics_Vector.path() + "/VectorFieldAngle - " + name_current + ".png\n" +
                DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorFieldAngle.png");

    //setting speed
    ui->comboBox_Res_MovAv_TimeWindow->setCurrentIndex(TIME_WINDOW_FULL_VIDEO);
    ui->comboBox_Res_VectorFieldParam_Length_Value->setCurrentIndex(c_STAT_MEAN_ARITMETIC);
    ui->comboBox_Res_VectorFieldParam_Length_Error->setCurrentIndex(c_STAT_STAN_DEV_SAMPLE);
    ui->comboBox_Res_VectorFieldParam_Angle_Value->setCurrentIndex(c_STAT_CIRC_CONST_0);
    ui->comboBox_Res_VectorFieldParam_Angle_Error->setCurrentIndex(c_STAT_CIRC_CONST_PI);
    ui->spinBox_ParamGridHorizontal->setValue(20);
    ui->spinBox_ParamGridVertical->setValue(16);
    ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setValue(0.25);
    ui->doubleSpinBox_Res_VectorFieldParam_ScaleLength->setValue(1);
    ui->checkBox_Res_GridVisParam_Grid->setChecked(false);
    ui->checkBox_Res_GridVisParam_Labels->setChecked(false);
    ui->spinBox_Res_VectorFieldParam_Thickness_Vector->setValue(1);
    ui->spinBox_Res_VectorFieldParam_Thickness_Error->setValue(2);
    View_Results.Save_Image(DIR_SaveStackGraphics_Speed.path() + "/VectorFieldSpeed - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorFieldSpeed.png");
    ui->groupBox_Res->grab().save(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorFieldSpeed_Settings.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Image(
                View_Results.QI(),
                "Vector Field Speed\n"
                "\n"
                "Vector length: " + ui->comboBox_Res_VectorFieldParam_Length_Value->currentText() + " +/- " + ui->comboBox_Res_VectorFieldParam_Length_Error->currentText() + "\n"
                "Vector angle: " + ui->comboBox_Res_VectorFieldParam_Angle_Value->currentText() + " +/- " + ui->comboBox_Res_VectorFieldParam_Angle_Error->currentText() + "\n"
                "\n"
                "Length unit is shift per " + QString::number(ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->value()) + " seconds(s).\n"
                "Image size: (" + QString::number(vMA_ProcSteps[STEP_CROP].cols * conv_px2um) + " x " + QString::number(vMA_ProcSteps[STEP_CROP].rows * conv_px2um) + ")um)\n"
                "\n"
                "The 'circle' radii shows the speed and its standard deviation."
                "The angle is set to zero and shows no information.\n"
                "Useful to see the spatially resolved speed distribution independently of angle.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackGraphics_Vector.path() + "/VectorField20x16 - " + name_current + ".png\n" +
                DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorField20x16.png");


    //plots---------------------------------------------------------------

    QImage QI_ImgSave_tmp;

    //time axis
    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_LINE);
    ui->comboBox_Res_PlotLine_FixRange_T->setCurrentIndex(PLOT_TIME_VIDEO_LENGTH);

    //speed stat
    ui->comboBox_Res_Type->setCurrentIndex(RES_SPEED_STAT_CUSTOM);
    ui->checkBox_Res_PlotLine_FixRange_S->setChecked(true);
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_min->setValue(0);
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_max->setValue(120);

    //means
    ui->comboBox_Res_SpeedCustom_Stat_Value->setCurrentIndex(c_STAT_MEAN_ARITMETIC);

    //speed mean 1x1 1s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(1.0);
    ui->spinBox_ParamGridHorizontal->setValue(1);
    ui->spinBox_ParamGridVertical->setValue(1);
    ui->spinBox_ParamGrid_CellStart->setValue(0);
    ui->spinBox_ParamGrid_CellEnd->setValue(2);
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Speed_Mean_01x01_01s.png");
    Update_Ui();

    //speed mean 1x1 10s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(10.0);
    ui->spinBox_ParamGridHorizontal->setValue(1);
    ui->spinBox_ParamGridVertical->setValue(1);
    ui->spinBox_ParamGrid_CellStart->setValue(0);
    ui->spinBox_ParamGrid_CellEnd->setValue(2);
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Speed_Mean_01x01_10s.png");
    Update_Ui();

    //speed mean 4x5 1s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(1.0);
    ui->spinBox_ParamGridHorizontal->setValue(5);
    ui->spinBox_ParamGridVertical->setValue(4);
    ui->spinBox_ParamGrid_CellStart->setValue(0);
    ui->spinBox_ParamGrid_CellEnd->setValue(20);
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Speed_Mean_04x05_01s.png");
    Update_Ui();

    //speed mean 4x5 10s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(10.0);
    ui->spinBox_ParamGridHorizontal->setValue(5);
    ui->spinBox_ParamGridVertical->setValue(4);
    ui->spinBox_ParamGrid_CellStart->setValue(0);
    ui->spinBox_ParamGrid_CellEnd->setValue(20);
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Speed_StanDev_04x05_10s.png");
    Update_Ui();

    //SDs
    ui->comboBox_Res_SpeedCustom_Stat_Value->setCurrentIndex(c_STAT_STAN_DEV_SAMPLE);

    //speed SD 1x1 1s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(1.0);
    ui->spinBox_ParamGridHorizontal->setValue(1);
    ui->spinBox_ParamGridVertical->setValue(1);
    ui->spinBox_ParamGrid_CellStart->setValue(0);
    ui->spinBox_ParamGrid_CellEnd->setValue(2);
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Speed_StanDev_01x01_01s.png");
    Update_Ui();

    //speed SD 1x1 10s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(10.0);
    ui->spinBox_ParamGridHorizontal->setValue(1);
    ui->spinBox_ParamGridVertical->setValue(1);
    ui->spinBox_ParamGrid_CellStart->setValue(0);
    ui->spinBox_ParamGrid_CellEnd->setValue(2);
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Speed_StanDev_01x01_10s.png");
    Update_Ui();

    //speed SD 4x5 1s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(1.0);
    ui->spinBox_ParamGridHorizontal->setValue(5);
    ui->spinBox_ParamGridVertical->setValue(4);
    ui->spinBox_ParamGrid_CellStart->setValue(0);
    ui->spinBox_ParamGrid_CellEnd->setValue(20);
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Speed_StanDev_04x05_01s.png");
    Update_Ui();

    //speed SD 4x5 10s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(10.0);
    ui->spinBox_ParamGridHorizontal->setValue(5);
    ui->spinBox_ParamGridVertical->setValue(4);
    ui->spinBox_ParamGrid_CellStart->setValue(0);
    ui->spinBox_ParamGrid_CellEnd->setValue(20);
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Speed_StanDev_04x05_10s.png");
    Update_Ui();


    //....................


    //angle stat
    ui->comboBox_Res_Type->setCurrentIndex(RES_ANGLE_STAT_CUSTOM);
    ui->checkBox_Res_PlotLine_FixRange_A->setChecked(true);
    ui->doubleSpinBox_Res_PlotLine_FixRange_A_min->setValue(-180);
    ui->doubleSpinBox_Res_PlotLine_FixRange_A_max->setValue(180);

    //means
    ui->comboBox_Res_SpeedCustom_Stat_Value->setCurrentIndex(c_STAT_CIRC_MEAN_ANG);

    //angle mean 1x1 1s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(1.0);
    ui->spinBox_ParamGridHorizontal->setValue(1);
    ui->spinBox_ParamGridVertical->setValue(1);
    ui->spinBox_ParamGrid_CellStart->setValue(0);
    ui->spinBox_ParamGrid_CellEnd->setValue(2);
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Angle_Mean_01x01_01s.png");
    Update_Ui();

    //angle mean 1x1 10s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(10.0);
    ui->spinBox_ParamGridHorizontal->setValue(1);
    ui->spinBox_ParamGridVertical->setValue(1);
    ui->spinBox_ParamGrid_CellStart->setValue(0);
    ui->spinBox_ParamGrid_CellEnd->setValue(2);
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Angle_Mean_01x01_10s.png");
    Update_Ui();

    //angle mean 4x5 1s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(1.0);
    ui->spinBox_ParamGridHorizontal->setValue(5);
    ui->spinBox_ParamGridVertical->setValue(4);
    ui->spinBox_ParamGrid_CellStart->setValue(0);
    ui->spinBox_ParamGrid_CellEnd->setValue(20);
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Angle_Mean_04x05_01s.png");
    Update_Ui();

    //angle mean 4x5 10s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(10.0);
    ui->spinBox_ParamGridHorizontal->setValue(5);
    ui->spinBox_ParamGridVertical->setValue(4);
    ui->spinBox_ParamGrid_CellStart->setValue(0);
    ui->spinBox_ParamGrid_CellEnd->setValue(20);
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Angle_StanDev_04x05_10s.png");
    Update_Ui();

    //errors
    ui->comboBox_Res_SpeedCustom_Stat_Value->setCurrentIndex(c_STAT_CIRC_MEAN_ANG);

    //angle Variation 1x1 1s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(1.0);
    ui->spinBox_ParamGridHorizontal->setValue(1);
    ui->spinBox_ParamGridVertical->setValue(1);
    ui->spinBox_ParamGrid_CellStart->setValue(0);
    ui->spinBox_ParamGrid_CellEnd->setValue(2);
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Angle_Variation_01x01_01s.png");
    Update_Ui();

    //angle Variation 1x1 10s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(10.0);
    ui->spinBox_ParamGridHorizontal->setValue(1);
    ui->spinBox_ParamGridVertical->setValue(1);
    ui->spinBox_ParamGrid_CellStart->setValue(0);
    ui->spinBox_ParamGrid_CellEnd->setValue(2);
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Angle_Variation_01x01_10s.png");
    Update_Ui();

    //angle Variation 4x5 1s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(1.0);
    ui->spinBox_ParamGridHorizontal->setValue(5);
    ui->spinBox_ParamGridVertical->setValue(4);
    ui->spinBox_ParamGrid_CellStart->setValue(0);
    ui->spinBox_ParamGrid_CellEnd->setValue(20);
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Angle_Variation_04x05_01s.png");
    Update_Ui();

    //angle Variation 4x5 10s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(10.0);
    ui->spinBox_ParamGridHorizontal->setValue(5);
    ui->spinBox_ParamGridVertical->setValue(4);
    ui->spinBox_ParamGrid_CellStart->setValue(0);
    ui->spinBox_ParamGrid_CellEnd->setValue(20);
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Angle_Variation_04x05_10s.png");
    Update_Ui();

    //.....................................................................

    //speed analysis
    ui->comboBox_Res_Type->setCurrentIndex(RES_SPEED_ANALYSIS);
    ui->checkBox_Res_PlotLine_FixRange_S->setChecked(true);
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_min->setValue(0);
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_max->setValue(120);

    //mean+-SD
    ui->comboBox_Res_SpeedCustom_Stat_Value->setCurrentIndex(c_STAT_MEAN_ARITMETIC);
    ui->comboBox_Res_SpeedCustom_Stat_Uncertanty->setCurrentIndex(c_STAT_STAN_DEV_SAMPLE);

    //mean+-SD 1s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(1.0);
    ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setValue(1.0);
    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_LINE);
    pChartView_Results_Line->grab().save(DIR_SaveStackPlot_Speed.path() + "/PlotLine_SpeedAnalysis_MeanSD_01s - " + name_current + ".png");
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_SpeedAnalysis_MeanSD_01s.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Line->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Speed vs Time 1x1 1s\n"
                "\n"
                "X-axis: Full time axis of video in seconds\n"
                "Y-Axis: Speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + " +/- " + ui->comboBox_Res_SpeedCustom_Stat_Uncertanty->currentText() + ")\n"
                "\n"
                "Unit is shift in um per second.\n"
                "Data is smoothed over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + " second(s) and full frame.\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "No spatial information contained.\n"
                "Useful to see speed vs time in full video considering short termed variation.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/PlotLine_SpeedAnalysis_MeanSD_01s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_SpeedAnalysis_MeanSD_01s.png");

    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_POINCARE);
    pChartView_Results_Poincare->grab().save(DIR_SaveStackPlot_Speed.path() + "/PlotPoincare_SpeedAnalysis_MeanSD_01s - " + name_current + ".png");
    pChartView_Results_Poincare->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotPoincare_SpeedAnalysis_MeanSD_01s.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Poincare->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Speed Variation 1x1 1s\n"
                "\n"
                "X-axis: Speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + ") at t+1s\n"
                "Y-Axis: Speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + ") at t\n"
                "\n"
                "Unit is shift in um per second.\n"
                "Data is smoothed over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + " second(s) and full frame.\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "No spatial information contained.\n"
                "Expansion in main diagonal (gray line) shows long term variation.\n"
                "Expansion in other diagonal shows short term variation.\n"
                "Useful to see different types of variation of speed.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/PlotPoincare_SpeedAnalysis_MeanSD_01s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotPoincare_SpeedAnalysis_MeanSD_01s.png");

    //mean+-SD 10s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(10.0);
    ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setValue(10.0);
    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_LINE);
    pChartView_Results_Line->grab().save(DIR_SaveStackPlot_Speed.path() + "/PlotLine_SpeedAnalysis_MeanSD_10s - " + name_current + ".png");
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_SpeedAnalysis_MeanSD_10s.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Line->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Speed vs Time 1x1 10s\n"
                "\n"
                "X-axis: Full time axis of video in seconds\n"
                "Y-Axis: Speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + " +/- " + ui->comboBox_Res_SpeedCustom_Stat_Uncertanty->currentText() + ")\n"
                "\n"
                "Unit is shift in um per second.\n"
                "Data is smoothed over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + " second(s) and full frame.\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "No spatial information contained.\n"
                "Useful to get an overview of speed vs time in full video.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/PlotLine_SpeedAnalysis_MeanSD_10s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_SpeedAnalysis_MeanSD_10s.png");

    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_POINCARE);
    pChartView_Results_Poincare->grab().save(DIR_SaveStackPlot_Speed.path() + "/PlotPoincare_SpeedAnalysis_MeanSD_10s - " + name_current + ".png");
    pChartView_Results_Poincare->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotPoincare_SpeedAnalysis_MeanSD_10s.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Poincare->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Speed Variation 1x1 1s\n"
                "\n"
                "X-axis: Speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + ") at t+1s\n"
                "Y-Axis: Speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + ") at t\n"
                "\n"
                "Unit is shift in um per second.\n"
                "Data is smoothed over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + " second(s) and full frame.\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "No spatial information contained.\n"
                "Expansion in main diagonal (gray line) shows long term variation.\n"
                "Expansion in other diagonal shows short term variation.\n"
                "Useful to see different types of variation of speed.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/PlotPoincare_SpeedAnalysis_MeanSD_10s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotPoincare_SpeedAnalysis_MeanSD_10s.png");



    //........

    //angle analysis
    ui->comboBox_Res_Type->setCurrentIndex(RES_ANGLE_ANALYSIS);
    ui->checkBox_Res_PlotLine_FixRange_A->setChecked(true);
    ui->doubleSpinBox_Res_PlotLine_FixRange_A_min->setValue(-180);
    ui->doubleSpinBox_Res_PlotLine_FixRange_A_max->setValue(180);

    //mean+-SD
    ui->comboBox_Res_AngleCustom_Stat_Value->setCurrentIndex(c_STAT_CIRC_MEAN_ANG);
    ui->comboBox_Res_AngleCustom_Stat_Uncertanty->setCurrentIndex(c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA);

    //mean+-SD 1s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(1.0);
    ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setValue(1.0);
    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_LINE);
    pChartView_Results_Line->grab().save(DIR_SaveStackPlot_Angle.path() + "/PlotLine_AngleAnalysis_MeanSD_01s - " + name_current + ".png");
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_AngleAnalysis_MeanSD_01s.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Line->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Angle vs Time 1x1 1s\n"
                "\n"
                "X-axis: Full time axis of video in seconds\n"
                "Y-Axis: Angle (" + ui->comboBox_Res_AngleCustom_Stat_Value->currentText() + " +/- " + ui->comboBox_Res_AngleCustom_Stat_Uncertanty->currentText() + ")\n"
                "\n"
                "Unit variation around average moving angle in full video in degree.\n"
                "Data is smoothed over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + " second(s) and full frame.\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "No spatial information contained.\n"
                "Useful to see angle vs time in full video considering short termed variation.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Angle.path() + "/PlotLine_AngleAnalysis_MeanSD_01s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_AngleAnalysis_MeanSD_01s.png");

    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_POINCARE);
    pChartView_Results_Poincare->grab().save(DIR_SaveStackPlot_Angle.path() + "/PlotPoincare_AngleAnalysis_MeanSD_01s - " + name_current + ".png");
    pChartView_Results_Poincare->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotPoincare_AngleAnalysis_MeanSD_01s.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Poincare->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Angle Variation 1x1 1s\n"
                "\n"
                "X-axis: Angle (" + ui->comboBox_Res_AngleCustom_Stat_Value->currentText() + ") at t+1s\n"
                "Y-Axis: Angle (" + ui->comboBox_Res_AngleCustom_Stat_Value->currentText() + ") at t\n"
                "\n"
                "Unit variation around average moving angle in full video in degree.\n"
                "Data is smoothed over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + " second(s) and full frame.\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "No spatial information contained.\n"
                "Expansion in main diagonal (gray line) shows long term variation.\n"
                "Expansion in other diagonal shows short term variation.\n"
                "Useful to see different types of variation of angle.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Angle.path() + "/PlotPoincare_AngleAnalysis_MeanSD_01s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotPoincare_AngleAnalysis_MeanSD_01s.png");

    //mean+-SD 10s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(10.0);
    ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setValue(10.0);
    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_LINE);
    pChartView_Results_Line->grab().save(DIR_SaveStackPlot_Angle.path() + "/PlotLine_AngleAnalysis_MeanSD_10s - " + name_current + ".png");
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_AngleAnalysis_MeanSD_10s.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Line->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Angle vs Time 1x1 10s\n"
                "\n"
                "X-axis: Full time axis of video in seconds\n"
                "Y-Axis: Angle (" + ui->comboBox_Res_AngleCustom_Stat_Value->currentText() + " +/- " + ui->comboBox_Res_AngleCustom_Stat_Uncertanty->currentText() + ")\n"
                "\n"
                "Unit variation around average moving angle in full video in degree.\n"
                "Data is smoothed over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + " second(s) and full frame.\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "No spatial information contained.\n"
                "Useful to get an overview of angle vs time in full video.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/PlotLine_AngleAnalysis_MeanSD_10s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_AngleAnalysis_MeanSD_10s.png");

    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_POINCARE);
    pChartView_Results_Poincare->grab().save(DIR_SaveStackPlot_Angle.path() + "/PlotPoincare_AngleAnalysis_MeanSD_10s - " + name_current + ".png");
    pChartView_Results_Poincare->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotPoincare_AngleAnalysis_MeanSD_10s.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Poincare->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Angle Variation 1x1 10s\n"
                "\n"
                "X-axis: Angle (" + ui->comboBox_Res_AngleCustom_Stat_Value->currentText() + ") at t+1s\n"
                "Y-Axis: Angle (" + ui->comboBox_Res_AngleCustom_Stat_Value->currentText() + ") at t\n"
                "\n"
                "Unit variation around average moving angle in full video in degree.\n"
                "Data is smoothed over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + " second(s) and full frame.\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "No spatial information contained.\n"
                "Expansion in main diagonal (gray line) shows long term variation.\n"
                "Expansion in other diagonal shows short term variation.\n"
                "Useful to see different types of variation of angle.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Angle.path() + "/PlotPoincare_AngleAnalysis_MeanSD_10s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotPoincare_AngleAnalysis_MeanSD_10s.png");

    //......................

    //overview
    ui->comboBox_Res_Type->setCurrentIndex(RES_OVERVIEW);

    //1s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(1.0);
    ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setValue(1.0);
    Update_Ui();
    ui->page_Res_Overview->grab().save(DIR_SaveStackPlot_Overview.path() + "/Overview_01s - " + name_current + ".png");
    ui->page_Res_Overview->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - Overview_01s.png");
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = ui->page_Res_Overview->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Overview 1s\n"
                "\n"
                "Shows a summuary of other plots from this analysis (on previous pages).\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Overview.path() + "/Overview_01s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - Overview_01s.png");

    //10s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(10.0);
    ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setValue(10.0);
    Update_Ui();
    ui->page_Res_Overview->grab().save(DIR_SaveStackPlot_Overview.path() + "/Overview_10s - " + name_current + ".png");
    ui->page_Res_Overview->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - Overview_10s.png");
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = ui->page_Res_Overview->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Overview 10s\n"
                "\n"
                "Shows a summuary of other plots from this analysis (on previous pages).\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Overview.path() + "/Overview_10s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - Overview_10s.png");
    PDF_Summary.add_Image(
                &QI_ImgSave_tmp,
                0.05, 0.95, 0.55, 0.97);

    //reset
    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_LINE);

    //save pdf
    PDF_Overview.save_PDF();
    PDF_Summary.save_PDF();
}

void D_MAKRO_CiliaSphereTracker::Save_ResultVectorFieldVideo(QString Path_Out, int gridCellsHorizontal, int gridCellsVertical, double timeWindowSeconds, int backgroundMode)
{
    //Check requirements
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_ImgProcUp2date || !state_GridSamplingSplit || !state_VidProcUp2date)
    {
        qDebug() << "Save_ResultVectorFieldVideo quit because:" << "Requirements not met";
        return;
    }

    //remember settings before
    int old_WindowMode      = ui->comboBox_Res_MovAv_TimeWindow->currentIndex();
    int old_BackgroundMode  = ui->comboBox_Res_MovAv_Background->currentIndex();
    int old_gridHorizontal  = ui->spinBox_ParamGridHorizontal->value();
    int old_gridVertical    = ui->spinBox_ParamGridVertical->value();
    int old_TimeWindowSize  = ui->spinBox_Res_MovAv_WindowFrames->value();

    //Show correct results type
    ui->comboBox_Res_Type->setCurrentIndex(RES_GRAPHICS_VECTORS);

    //apply passed settings
    ui->comboBox_Res_MovAv_TimeWindow->setCurrentIndex(TIME_WINDOW_MOVING_AVERAGE);
    ui->comboBox_Res_MovAv_Background->setCurrentIndex(backgroundMode);
    ui->spinBox_ParamGridHorizontal->setValue(gridCellsHorizontal);
    ui->spinBox_ParamGridVertical->setValue(gridCellsVertical);
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(timeWindowSeconds);

    //frame range
    int frame_start = ui->spinBox_Res_MovAv_CurrentFrame->minimum();
    int frame_end   = ui->spinBox_Res_MovAv_CurrentFrame->maximum();

    //show last vector field (to make sure update happens at 1st frame selection
    ui->spinBox_Res_MovAv_CurrentFrame->setValue(frame_end);

    //Init Video Writer
    D_VideoWriter VW_Out;
    VW_Out.set_isColor(true);
    VW_Out.set_Size(MA_Result.size());
    VW_Out.set_FPS(VS_InputVideo.get_FrameRateFps());
    VW_Out.set_PathOut(Path_Out);
    VW_Out.init_VideoWriter();
    if(!VW_Out.is_Init())
    {
        qDebug() << "Save_ResultVectorFieldVideo quit because:" << "!VW_Out.is_Init()";
        return;
    }

    //loop video
    for(int frame = frame_start; frame <= frame_end; frame++)
    {
        qDebug() << "Save_ResultVectorFieldVideo - Frame" << frame;

        //update
        ui->spinBox_Res_MovAv_CurrentFrame->setValue(frame);
        Update_Results();
        //imshow("test", MA_Result);

        //show
        Update_Ui();

        //write
        VW_Out.AddFrame(MA_Result);
    }

    //close writer
    VW_Out.EndVideoWriting();

    //recover settings before
    ui->comboBox_Res_MovAv_TimeWindow->setCurrentIndex(old_WindowMode);
    ui->comboBox_Res_MovAv_Background->setCurrentIndex(old_BackgroundMode);
    ui->spinBox_ParamGridHorizontal->setValue(old_gridHorizontal);
    ui->spinBox_ParamGridVertical->setValue(old_gridVertical);
    ui->spinBox_Res_MovAv_WindowFrames->setValue(old_TimeWindowSize);
}


void D_MAKRO_CiliaSphereTracker::Data_Add()
{
    //get filepaths
    QStringList QSl_Paths = QFileDialog::getOpenFileNames(
                this,
                "Load Videos",
                pStore->dir_M_CiliaSphereTracker()->path(),
                "Video Files (*.avi *.mp4 *.mpg *.mkv *flv *.mpeg *.3gp)");
    if(QSl_Paths.empty())
        return;

    //set default dir
    pStore->set_dir_M_CiliaSphereTracker(QSl_Paths.first());

    //number of loaded videos
    int vid_count_old = FIL_Videos.size();

    //fill listst for easy access
    for(int f = 0; f < QSl_Paths.size(); f++)
    {
        //basics
        QString QS_Path = QSl_Paths[f];
        QFileInfo FI_Img = QFileInfo(QS_Path);
        QString QS_Name = FI_Img.baseName();
        QString QS_Suffix = FI_Img.suffix();

        //lists
        QSL_Videos_Paths.append(QS_Path);
        QSL_Videos_Names.append(FI_Img.baseName());
        QSL_Videos_Suffix.append(FI_Img.suffix());
        FIL_Videos.append(FI_Img);
    }

    //video names to ui
    int index_old_max = vid_count_old - 1;
    if(index_old_max < 0)
        index_old_max = 0;
    Populate_CB_Single(ui->comboBox_Data_Videos, QSL_Videos_Names, index_old_max);

    //update ui accesibility
    ui->groupBox_Res->setEnabled(true);
    ui->groupBox_Proc->setEnabled(true);
    ui->groupBox_Param->setEnabled(true);
    ui->pushButton_Data_Clear->setEnabled(true);
    ui->comboBox_Data_Videos->setEnabled(true);

    //update states
    state_VideosLoaded = true;
    state_VideoSelected = false;
    state_ImgProcUp2date = false;
    state_set_VidProcUp2date(false);
    state_RoiTimeSelected = false;
    state_RoiSpaceSelected = false;
    state_TimeProjectInit = false;
    state_GridSamplingSplit = false;

    Data_SelectVideo();
    Update_ImgProc_All();
}

void D_MAKRO_CiliaSphereTracker::Data_Clear()
{
    //clear listst
    FIL_Videos.clear();
    QSL_Videos_Names.clear();
    QSL_Videos_Paths.clear();
    QSL_Videos_Suffix.clear();

    //update ui accesibility
    ui->groupBox_Res->setEnabled(false);
    ui->groupBox_Proc->setEnabled(false);
    ui->groupBox_Param->setEnabled(false);
    ui->pushButton_Data_Clear->setEnabled(false);
    ui->comboBox_Data_Videos->setEnabled(false);

    //update states
    state_VideosLoaded = false;
    state_VideoSelected = false;
    state_ImgProcUp2date = false;
    state_set_VidProcUp2date(false);
    state_RoiTimeSelected = false;
    state_RoiSpaceSelected = false;
    state_TimeProjectInit = false;
    state_GridSamplingSplit = false;
}

void D_MAKRO_CiliaSphereTracker::Data_SelectVideo()
{
    state_VideoSelected = false;
    state_RoiTimeSelected = false;
    state_RoiSpaceSelected = false;
    state_TimeProjectInit = false;
    state_set_VidProcUp2date(false);
    state_GridSamplingSplit = false;


    ERR(
            VS_InputVideo.set_VideoPath(FIL_Videos[ui->comboBox_Data_Videos->currentIndex()]),
            "Data_SelectVideo",
            "VS_InputVideo.set_VideoPath(...)");

    Data_SelectRoiTime();
    Data_SelectRoiSpace();

    state_VideoSelected = true;

    //moving average position at start
    movav_current_start = frame_start_ana;
    movav_window_frames = (ui->doubleSpinBox_Res_MovAv_WindowTime->value() + 0.5 * VS_InputVideo.get_FrameTimeSec()) * VS_InputVideo.get_FrameRateFps();
    Update_Ui_ResMovAv();
}

void D_MAKRO_CiliaSphereTracker::Data_SelectRoiTime()
{
    state_RoiTimeSelected = false;
    state_set_VidProcUp2date(false);

    frame_start     = static_cast<int>(ui->doubleSpinBox_Param_Crop_Start->value() / VS_InputVideo.get_FrameTimeSec());
    frame_start_ana = frame_start + ui->spinBox_Param_FrameCountSmooth->value();
    frame_end       = static_cast<int>(VS_InputVideo.get_FrameCount() - 1 - (ui->doubleSpinBox_Param_Crop_End->value() / VS_InputVideo.get_FrameTimeSec()));

    BlockSignals_FrameSelection(true);

    ui->horizontalSlider_Proc_Frame->setMinimum(frame_start);
    ui->horizontalSlider_Proc_Frame->setMaximum(frame_end);
    ui->horizontalSlider_Proc_Frame->setValue(frame_start);

    ui->spinBox_Proc_Frame->setMinimum(frame_start);
    ui->spinBox_Proc_Frame->setMaximum(frame_end);
    ui->spinBox_Proc_Frame->setValue(frame_start);
    ui->spinBox_Proc_Frame->setSuffix(" / " + QString::number(VS_InputVideo.get_FrameCount()));

    ui->doubleSpinBox_Proc_Time->setMinimum(frame_start * VS_InputVideo.get_FrameTimeSec());
    ui->doubleSpinBox_Proc_Time->setMaximum(frame_end * VS_InputVideo.get_FrameTimeSec());
    ui->doubleSpinBox_Proc_Time->setValue(frame_start * VS_InputVideo.get_FrameTimeSec());
    ui->doubleSpinBox_Proc_Time->setSuffix(" / " + QString::number(static_cast<int>(VS_InputVideo.get_DurationSec() * 100) / 100.0));

    BlockSignals_FrameSelection(false);

    Update_Ui_Roi();

    state_RoiTimeSelected = true;

    Update_Ui_ResMovAv();
}

void D_MAKRO_CiliaSphereTracker::Data_SelectRoiSpace()
{
    state_RoiSpaceSelected = false;

    spatial_roi_width = VS_InputVideo.get_Width() - ui->spinBox_Param_Crop_Left->value() - ui->spinBox_Param_Crop_Right->value();
    spatial_roi_height = VS_InputVideo.get_Height() - ui->spinBox_Param_Crop_Top->value() - ui->spinBox_Param_Crop_Bottom->value();

    Update_Ui_Roi();

    state_RoiSpaceSelected = true;
}

void D_MAKRO_CiliaSphereTracker::Data_CalcFullVideoStats()
{
    state_StatSummaryCalced = false;

    //shift scaling (shift/frame -> shift/second)
    double conv_perFrame2perSecond = VS_InputVideo.get_FrameRateFps();  //before stats calcs
    double conv_px_per_frm_2_um_per_s = conv_perFrame2perSecond * conv_px2um;

    //gathered containers
    vector<double> vShiftsAll_px_frm;
    vector<double> vShiftsAll_um_s;
    vector<double> vAnglesAll_Rad;
    vector<double> vAnglesAll_Grad;

    //gather
    for(size_t frm = 0; frm < vv_FrmObjShifts.size(); frm++)
        for(size_t obj = 0; obj < vv_FrmObjShifts[frm].size(); obj++)
        {
            vShiftsAll_px_frm.push_back(vv_FrmObjShifts[frm][obj]);
            vShiftsAll_um_s.push_back(vv_FrmObjShifts[frm][obj] * conv_px_per_frm_2_um_per_s);
            vAnglesAll_Rad.push_back(vv_FrmObjAngles[frm][obj]);
            vAnglesAll_Grad.push_back(vv_FrmObjAngles[frm][obj] * Rad2Grad);
        }

    //calc stats
    ERR(D_Stat::Calc_Stats(
            &v_VideoStats_Shifts_px_frm,
            vShiftsAll_px_frm,
            true),
        "Data_CalcFullVideoStats",
        "Calc_Stats (px/frm)");

    ERR(D_Stat::Calc_Stats(
            &v_VideoStats_Shifts_um_s,
            vShiftsAll_um_s,
            true),
        "Data_CalcFullVideoStats",
        "Calc_Stats (um/s)");

    ERR(D_Stat::Calc_Stats_Circ_Rad(
            &v_VideoStats_Angles_Rad,
            vAnglesAll_Rad),
        "Data_CalcFullVideoStats",
        "Calc_Stats_Circ_Rad");

    ERR(D_Stat::Calc_Stats_Circ_Grad(
            &v_VideoStats_Angles_Grad,
            vAnglesAll_Grad),
        "Data_CalcFullVideoStats",
        "Calc_Stats_Circ_Grad");

    state_StatSummaryCalced = true;
}

void D_MAKRO_CiliaSphereTracker::Data_Split2GridSampling()
{
    //check reqiurements
    if(!state_VidProcUp2date)
        return;

    //state
    state_GridSamplingSplit = false;

    //grid size
    size_t nx = ui->spinBox_ParamGridHorizontal->value();
    size_t ny = ui->spinBox_ParamGridVertical->value();
    size_t nt = vv_FrmObjShifts.size();

    //adapt ui
    ui->spinBox_ParamGrid_CellStart->setMaximum(static_cast<int>(nx * ny - 1));
    ui->spinBox_ParamGrid_CellEnd->setMaximum(static_cast<int>(nx * ny));

    //clear
    vvvv_XYFrmObjShifts.clear();
    vvvv_XYFrmObjPositions.clear();
    vvvv_XYFrmObjAngles.clear();
    vvv_XYObjShifts.clear();
    vvv_XYObjPositions.clear();
    vvv_XYObjAngles.clear();

    //resize
    vvvv_XYFrmObjShifts.resize(nx);
    vvvv_XYFrmObjPositions.resize(nx);
    vvvv_XYFrmObjAngles.resize(nx);
    vvv_XYObjShifts.resize(nx);
    vvv_XYObjPositions.resize(nx);
    vvv_XYObjAngles.resize(nx);

    for(size_t ix = 0; ix < nx; ix++)
    {
        vvvv_XYFrmObjShifts[ix].resize(ny);
        vvvv_XYFrmObjPositions[ix].resize(ny);
        vvvv_XYFrmObjAngles[ix].resize(ny);
        vvv_XYObjShifts[ix].resize(ny);
        vvv_XYObjPositions[ix].resize(ny);
        vvv_XYObjAngles[ix].resize(ny);

        for(size_t iy = 0; iy < ny; iy++)
        {
            vvvv_XYFrmObjShifts[ix][iy].resize(nt);
            vvvv_XYFrmObjPositions[ix][iy].resize(nt);
            vvvv_XYFrmObjAngles[ix][iy].resize(nt);
        }
    }

    //split and fill
    //loop frames
    for(size_t it = 0; it < nt; it++)
    {
        //loop deteceted object movements in current frame
        size_t no = static_cast<size_t>(vv_FrmObjShifts[it].size());
        for(size_t io = 0; io < no; io++)
        {
            //position of movement
            float x = vv_FrmObjPositions[it][io].x;
            float y = vv_FrmObjPositions[it][io].y;

            //grid cell
            size_t gx = static_cast<size_t>((x / spatial_roi_width) * nx);
            size_t gy = static_cast<size_t>((y / spatial_roi_height) * ny);
            if(gx >= nx)    gx = nx - 1;
            if(gy >= ny)    gy = ny - 1;

            //export
            vvvv_XYFrmObjShifts[gx][gy][it].push_back(vv_FrmObjShifts[it][io]);
            vvvv_XYFrmObjAngles[gx][gy][it].push_back(vv_FrmObjAngles[it][io]);
            vvvv_XYFrmObjPositions[gx][gy][it].push_back(vv_FrmObjPositions[it][io]);
            vvv_XYObjShifts[gx][gy].push_back(vv_FrmObjShifts[it][io]);
            vvv_XYObjAngles[gx][gy].push_back(vv_FrmObjAngles[it][io]);
            vvv_XYObjPositions[gx][gy].push_back(vv_FrmObjPositions[it][io]);
        }
    }

    state_GridSamplingSplit = true;

    Update_Results();
}

void D_MAKRO_CiliaSphereTracker::Update_Ui_Roi()
{
    ui->label_Param_CropTime->setText("Crop Time (" + QString::number(VS_InputVideo.get_DurationSec() - ui->doubleSpinBox_Param_Crop_End->value() - ui->doubleSpinBox_Param_Crop_Start->value()) + "s)");
    ui->label_Param_CropHeight->setText("Crop Height (" + QString::number(spatial_roi_height) + "px)");
    ui->label_Param_CropWidth->setText("Crop Width (" + QString::number(spatial_roi_width) + "px)");

    ui->spinBox_ParamGridVertical->setMaximum(spatial_roi_height);
    ui->spinBox_ParamGridHorizontal->setMaximum(spatial_roi_width);
    ui->spinBox_ParamGridVertical->setSuffix(" (height: " + QString::number(spatial_roi_height / ui->spinBox_ParamGridVertical->value()) + "px each)");
    ui->spinBox_ParamGridHorizontal->setSuffix(" (width: " + QString::number(spatial_roi_width / ui->spinBox_ParamGridHorizontal->value()) + "px each)");
}

void D_MAKRO_CiliaSphereTracker::Update_Ui_ResParam()
{
    int res_type = ui->comboBox_Res_Type->currentIndex();

    //groups
    ui->groupBox_Res_GraphicsParam->setVisible      (res_type == RES_GRAPHICS_TIME_SUM_PROJ                                                                                 || res_type == RES_GRAPHICS_VECTORS);
    ui->groupBox_Res_GridSamplingParam->setVisible  (                                           res_type == RES_SPEED_STAT_CUSTOM   || res_type == RES_ANGLE_STAT_CUSTOM    || res_type == RES_GRAPHICS_VECTORS);
    ui->groupBox_Res_GridVisParam->setVisible       (                                                                                                                          res_type == RES_GRAPHICS_VECTORS);
    ui->groupBox_Res_VectorFieldParam->setVisible   (                                                                                                                          res_type == RES_GRAPHICS_VECTORS);
    ui->groupBox_Res_TimeAxis->setVisible           (                                           res_type == RES_SPEED_STAT_CUSTOM   || res_type == RES_ANGLE_STAT_CUSTOM                                                                                || res_type == RES_SPEED_ANALYSIS   || res_type == RES_ANGLE_ANALYSIS   || res_type == RES_OVERVIEW);
    ui->groupBox_Res_SpeedCustom->setVisible        (                                           res_type == RES_SPEED_STAT_CUSTOM                                                                                                                       || res_type == RES_SPEED_ANALYSIS                                       || res_type == RES_OVERVIEW);
    ui->groupBox_Res_AngleCustom->setVisible        (                                                                                  res_type == RES_ANGLE_STAT_CUSTOM                                                                                                                    || res_type == RES_ANGLE_ANALYSIS   || res_type == RES_OVERVIEW);
    ui->groupBox_Res_MovAv->setVisible              (                                           res_type == RES_SPEED_STAT_CUSTOM   || res_type == RES_ANGLE_STAT_CUSTOM    || res_type == RES_GRAPHICS_VECTORS                                         || res_type == RES_SPEED_ANALYSIS   || res_type == RES_ANGLE_ANALYSIS   || res_type == RES_OVERVIEW);
    ui->groupBox_Res_Heat->setVisible(                                                                                                                                                                              res_type == RES_GRAPHICS_HEATMAP);

    //subelements
    ui->spinBox_ParamGrid_CellStart->setEnabled     (                                           res_type == RES_SPEED_STAT_CUSTOM   || res_type == RES_ANGLE_STAT_CUSTOM);
    ui->spinBox_ParamGrid_CellEnd->setEnabled       (                                           res_type == RES_SPEED_STAT_CUSTOM   || res_type == RES_ANGLE_STAT_CUSTOM);
    ui->spinBox_Res_MovAv_CurrentFrame->setEnabled  (                                                                                                                          res_type == RES_GRAPHICS_VECTORS);
    ui->doubleSpinBox_Res_MovAv_CurrentTime->setEnabled(                                                                                                                       res_type == RES_GRAPHICS_VECTORS);
    ui->spinBox_Res_MovAv_WindowFrames->setEnabled  (                                           res_type == RES_SPEED_STAT_CUSTOM   || res_type == RES_ANGLE_STAT_CUSTOM    || res_type == RES_GRAPHICS_VECTORS                                         || res_type == RES_SPEED_ANALYSIS   || res_type == RES_ANGLE_ANALYSIS   || res_type == RES_OVERVIEW);
    ui->doubleSpinBox_Res_MovAv_WindowTime->setEnabled(                                         res_type == RES_SPEED_STAT_CUSTOM   || res_type == RES_ANGLE_STAT_CUSTOM    || res_type == RES_GRAPHICS_VECTORS                                         || res_type == RES_SPEED_ANALYSIS   || res_type == RES_ANGLE_ANALYSIS   || res_type == RES_OVERVIEW);
    ui->comboBox_Res_MovAv_Background->setEnabled   (                                                                                                                          res_type == RES_GRAPHICS_VECTORS);
    ui->comboBox_Res_MovAv_TimeWindow->setEnabled   (                                                                                                                          res_type == RES_GRAPHICS_VECTORS);
    ui->horizontalSlider_Res_MovAv_CurrentStart->setEnabled(                                                                                                                   res_type == RES_GRAPHICS_VECTORS);
    ui->horizontalSlider_Res_MovAv_CurrentEnd->setEnabled(                                                                                                                     res_type == RES_GRAPHICS_VECTORS);

    //plot range
    ui->checkBox_Res_PlotLine_FixRange_S->setEnabled(res_type == RES_SPEED_STAT_CUSTOM || res_type == RES_SPEED_ANALYSIS || res_type == RES_OVERVIEW);
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_min->setEnabled((res_type == RES_SPEED_STAT_CUSTOM || res_type == RES_SPEED_ANALYSIS || res_type == RES_OVERVIEW) && ui->checkBox_Res_PlotLine_FixRange_S->isChecked());
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_max->setEnabled((res_type == RES_SPEED_STAT_CUSTOM || res_type == RES_SPEED_ANALYSIS || res_type == RES_OVERVIEW) && ui->checkBox_Res_PlotLine_FixRange_S->isChecked());
    ui->checkBox_Res_PlotLine_FixRange_A->setEnabled(res_type == RES_ANGLE_STAT_CUSTOM || res_type == RES_ANGLE_ANALYSIS || res_type == RES_OVERVIEW);
    ui->doubleSpinBox_Res_PlotLine_FixRange_A_min->setEnabled((res_type == RES_ANGLE_STAT_CUSTOM || res_type == RES_ANGLE_ANALYSIS || res_type == RES_OVERVIEW) && ui->checkBox_Res_PlotLine_FixRange_A->isChecked());
    ui->doubleSpinBox_Res_PlotLine_FixRange_A_max->setEnabled((res_type == RES_ANGLE_STAT_CUSTOM || res_type == RES_ANGLE_ANALYSIS || res_type == RES_OVERVIEW) && ui->checkBox_Res_PlotLine_FixRange_A->isChecked());

    //moving average
    if(res_type == RES_GRAPHICS_VECTORS)
    {
        bool movav_in_use = ui->comboBox_Res_MovAv_TimeWindow->currentIndex() == TIME_WINDOW_MOVING_AVERAGE;
        ui->spinBox_Res_MovAv_CurrentFrame->setEnabled(movav_in_use);
        ui->spinBox_Res_MovAv_WindowFrames->setEnabled(movav_in_use);
        ui->doubleSpinBox_Res_MovAv_CurrentTime->setEnabled(movav_in_use);
        ui->doubleSpinBox_Res_MovAv_WindowTime->setEnabled(movav_in_use);
        ui->horizontalSlider_Res_MovAv_CurrentStart->setEnabled(movav_in_use);
        ui->horizontalSlider_Res_MovAv_CurrentEnd->setEnabled(movav_in_use);
        ui->comboBox_Res_MovAv_Background->setEnabled(movav_in_use);
    }

    //speed uncertantiy stat plot
    if(res_type == RES_SPEED_STAT_CUSTOM || res_type == RES_SPEED_ANALYSIS || res_type == RES_OVERVIEW)
    {
        ui->label_Res_SpeedCustom_Stat_Uncertanty->setEnabled(res_type == RES_SPEED_ANALYSIS || res_type == RES_OVERVIEW);
        ui->comboBox_Res_SpeedCustom_Stat_Uncertanty->setEnabled(res_type == RES_SPEED_ANALYSIS || res_type == RES_OVERVIEW);
    }

    //angle uncertantiy stat plot
    if(res_type == RES_ANGLE_STAT_CUSTOM || res_type == RES_ANGLE_ANALYSIS || res_type == RES_OVERVIEW)
    {
        ui->label_Res_AngleCustom_Stat_Uncertanty->setEnabled(res_type == RES_ANGLE_ANALYSIS || res_type == RES_OVERVIEW);
        ui->comboBox_Res_AngleCustom_Stat_Uncertanty->setEnabled(res_type == RES_ANGLE_ANALYSIS || res_type == RES_OVERVIEW);
    }
}


void D_MAKRO_CiliaSphereTracker::Update_Ui_ResMovAv()
{
    qDebug() << "Update_Ui_ResMovAv" << "try" << "frame_start_ana" << frame_start_ana << "frame_end" << frame_end << "movav_current_start" << movav_current_start << "movav_window_frames" << movav_window_frames;

    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected)
        return;

    qDebug() << "Update_Ui_ResMovAv" << "start" << "frame_start_ana" << frame_start_ana << "frame_end" << frame_end << "movav_current_start" << movav_current_start << "movav_window_frames" << movav_window_frames;

    //checks and helping vars
    int frame_count_effective = frame_end - frame_start_ana;
    if(movav_window_frames > frame_count_effective)     movav_window_frames = frame_count_effective;
    if(movav_current_start < frame_start_ana)           movav_current_start = frame_start_ana;
    int max_start = frame_end - movav_window_frames;
    if(movav_current_start > max_start)                 movav_current_start = max_start;

    qDebug() << "Update_Ui_ResMovAv" << "corrected" << "frame_start_ana" << frame_start_ana << "frame_end" << frame_end << "movav_current_start" << movav_current_start << "movav_window_frames" << movav_window_frames;

    //block
    BlockSignals_FrameSelection_MovingAverage(true);

    //set boundaries for pos in vid
    //window
    ui->spinBox_Res_MovAv_WindowFrames->setMaximum(frame_end - frame_start_ana);
    ui->doubleSpinBox_Res_MovAv_WindowTime->setMaximum((frame_end - frame_start_ana) * VS_InputVideo.get_FrameTimeSec());
    ui->doubleSpinBox_Res_MovAv_WindowTime->setMinimum(VS_InputVideo.get_FrameTimeSec());
    //min
    ui->spinBox_Res_MovAv_CurrentFrame->setMinimum(frame_start_ana);
    ui->doubleSpinBox_Res_MovAv_CurrentTime->setMinimum(frame_start_ana * VS_InputVideo.get_FrameTimeSec());
    ui->horizontalSlider_Res_MovAv_CurrentStart->setMinimum(frame_start_ana);
    ui->horizontalSlider_Res_MovAv_CurrentEnd->setMinimum(frame_start_ana);
    //max
    ui->spinBox_Res_MovAv_CurrentFrame->setMaximum(max_start);
    ui->doubleSpinBox_Res_MovAv_CurrentTime->setMaximum(max_start * VS_InputVideo.get_FrameTimeSec());
    ui->horizontalSlider_Res_MovAv_CurrentStart->setMaximum(frame_end);
    ui->horizontalSlider_Res_MovAv_CurrentEnd->setMaximum(frame_end);

    //set window size
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(movav_window_frames * VS_InputVideo.get_FrameTimeSec());
    ui->spinBox_Res_MovAv_WindowFrames->setValue(movav_window_frames);

    //set current position
    ui->spinBox_Res_MovAv_CurrentFrame->setValue(movav_current_start);
    ui->horizontalSlider_Res_MovAv_CurrentStart->setValue(movav_current_start);
    ui->doubleSpinBox_Res_MovAv_CurrentTime->setValue(static_cast<int>(movav_current_start * VS_InputVideo.get_FrameTimeSec() * 100) / 100.0);
    ui->horizontalSlider_Res_MovAv_CurrentEnd->setValue(movav_current_start + movav_window_frames);
    ui->spinBox_Res_MovAv_CurrentFrame->setSuffix(" to " + QString::number(movav_current_start + movav_window_frames));
    ui->doubleSpinBox_Res_MovAv_CurrentTime->setSuffix(" to " + QString::number(static_cast<int>((movav_current_start + movav_window_frames) * VS_InputVideo.get_FrameTimeSec() * 100) / 100.0));

    //unblock
    BlockSignals_FrameSelection_MovingAverage(false);

    qDebug() << "Update_Ui_ResMovAv" << "end" << "frame_start_ana" << frame_start_ana << "frame_end" << frame_end << "movav_current_start" << movav_current_start << "movav_window_frames" << movav_window_frames;
}

void D_MAKRO_CiliaSphereTracker::Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(index_init);
    CB->blockSignals(false);
}

void D_MAKRO_CiliaSphereTracker::Populate_CB_Start()
{
    //specific
    Populate_CB_Single(ui->comboBox_Proc_Step,                              QSL_ProcSteps,      STEP_LOAD);
    Populate_CB_Single(ui->comboBox_Res_Type,                               QSL_ResTypes,       RES_GRAPHICS_TIME_SUM_PROJ);
    Populate_CB_Single(ui->comboBox_Res_MovAv_Background,                   QSL_Background,     BACKGR_PROJECTION);
    Populate_CB_Single(ui->comboBox_Res_MovAv_TimeWindow,                   QSL_TimeWindow,     TIME_WINDOW_FULL_VIDEO);
    Populate_CB_Single(ui->comboBox_Res_PlotLine_FixRange_T,                QSL_PlotTime,       PLOT_TIME_VIDEO_LENGTH);

    //stats
    Populate_CB_Single(ui->comboBox_Res_VectorFieldParam_Length_Value,      QSL_StatList,       c_STAT_MEAN_ARITMETIC);
    Populate_CB_Single(ui->comboBox_Res_VectorFieldParam_Length_Error,      QSL_StatList,       c_STAT_STAN_DEV_SAMPLE);
    Populate_CB_Single(ui->comboBox_Res_SpeedCustom_Stat_Value,             QSL_StatList,       c_STAT_MEAN_ARITMETIC);
    Populate_CB_Single(ui->comboBox_Res_SpeedCustom_Stat_Uncertanty,        QSL_StatList,       c_STAT_STAN_DEV_SAMPLE);
    Populate_CB_Single(ui->comboBox_Res_VectorFieldParam_Angle_Value,       QSL_StatListCirc,   c_STAT_CIRC_MEAN_ANG);
    Populate_CB_Single(ui->comboBox_Res_VectorFieldParam_Angle_Error,       QSL_StatListCirc,   c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA);
    Populate_CB_Single(ui->comboBox_Res_AngleCustom_Stat_Value,             QSL_StatListCirc,   c_STAT_CIRC_MEAN_ANG);
    Populate_CB_Single(ui->comboBox_Res_AngleCustom_Stat_Uncertanty,        QSL_StatListCirc,   c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA);
}

void D_MAKRO_CiliaSphereTracker::BlockSignals_FrameSelection(bool block)
{
    ui->horizontalSlider_Proc_Frame->blockSignals(block);
    ui->spinBox_Proc_Frame->blockSignals(block);
    ui->doubleSpinBox_Proc_Time->blockSignals(block);
}

void D_MAKRO_CiliaSphereTracker::BlockSignals_FrameSelection_MovingAverage(bool block)
{
    ui->horizontalSlider_Res_MovAv_CurrentStart->blockSignals(block);
    ui->horizontalSlider_Res_MovAv_CurrentEnd->blockSignals(block);
    ui->spinBox_Res_MovAv_CurrentFrame->blockSignals(block);
    ui->spinBox_Res_MovAv_WindowFrames->blockSignals(block);
    ui->doubleSpinBox_Res_MovAv_CurrentTime->blockSignals(block);
    ui->doubleSpinBox_Res_MovAv_WindowTime->blockSignals(block);
}

void D_MAKRO_CiliaSphereTracker::on_horizontalSlider_Proc_Frame_valueChanged(int value)
{
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected)
        return;

    BlockSignals_FrameSelection(true);
    ui->spinBox_Proc_Frame->setValue(value);
    ui->horizontalSlider_Proc_Frame->setValue(value);
    ui->doubleSpinBox_Proc_Time->setValue(static_cast<int>(value * VS_InputVideo.get_FrameTimeSec() * 100) / 100.0);
    BlockSignals_FrameSelection(false);

    Update_ImgProc_All();
}

void D_MAKRO_CiliaSphereTracker::on_spinBox_Proc_Frame_valueChanged(int arg1)
{
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected)
        return;

    BlockSignals_FrameSelection(true);
    ui->horizontalSlider_Proc_Frame->setValue(arg1);
    ui->doubleSpinBox_Proc_Time->setValue(static_cast<int>(arg1 * VS_InputVideo.get_FrameTimeSec() * 100) / 100.0);
    BlockSignals_FrameSelection(false);

    Update_ImgProc_All();
}

void D_MAKRO_CiliaSphereTracker::on_doubleSpinBox_Proc_Time_valueChanged(double arg1)
{
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected)
        return;

    BlockSignals_FrameSelection(true);
    ui->spinBox_Proc_Frame->setValue(static_cast<int>(arg1 / VS_InputVideo.get_FrameTimeSec()));
    ui->horizontalSlider_Proc_Frame->setValue(static_cast<int>(arg1 / VS_InputVideo.get_FrameTimeSec()));
    BlockSignals_FrameSelection(false);

    Update_ImgProc_All();
}

void D_MAKRO_CiliaSphereTracker::on_comboBox_Data_Videos_currentIndexChanged(int index)
{
    index;

    Data_SelectVideo();
    Update_ImgProc_All();
}

void D_MAKRO_CiliaSphereTracker::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_MAKRO_CiliaSphereTracker", func, detail);
}

void D_MAKRO_CiliaSphereTracker::on_comboBox_Proc_Step_currentIndexChanged(int index)
{
    index;
    Update_Image_Proc();
}

void D_MAKRO_CiliaSphereTracker::on_doubleSpinBox_Param_Scale_Px_valueChanged(double arg1)
{
    conv_px2um = (1000 * ui->doubleSpinBox_Param_Scale_mm->value()) / arg1;
    conv_um2px = 1.0 / conv_px2um;
    state_set_VidProcUp2date(false);
    Update_ImgProc_All();
}

void D_MAKRO_CiliaSphereTracker::on_doubleSpinBox_Param_Scale_mm_valueChanged(double arg1)
{
    conv_px2um = (1000 * arg1) / ui->doubleSpinBox_Param_Scale_Px->value();
    conv_um2px = 1.0 / conv_px2um;
    state_set_VidProcUp2date(false);
    Update_ImgProc_All();
}

void D_MAKRO_CiliaSphereTracker::on_doubleSpinBox_Param_Crop_Start_valueChanged(double arg1)
{
    arg1;
    state_set_VidProcUp2date(false);
    Data_SelectRoiTime();
    Update_ImgProc_All();
}

void D_MAKRO_CiliaSphereTracker::on_doubleSpinBox_Param_Crop_End_valueChanged(double arg1)
{
    arg1;
    state_set_VidProcUp2date(false);
    Data_SelectRoiTime();
    Update_ImgProc_All();
}

void D_MAKRO_CiliaSphereTracker::on_spinBox_Param_Crop_Top_valueChanged(int arg1)
{
    arg1;
    state_set_VidProcUp2date(false);
    Data_SelectRoiSpace();
    Update_ImgProc(STEP_CROP);
}

void D_MAKRO_CiliaSphereTracker::on_spinBox_Param_Crop_Bottom_valueChanged(int arg1)
{
    arg1;
    state_set_VidProcUp2date(false);
    Data_SelectRoiSpace();
    Update_ImgProc(STEP_CROP);
}

void D_MAKRO_CiliaSphereTracker::on_spinBox_Param_Crop_Left_valueChanged(int arg1)
{
    arg1;
    state_set_VidProcUp2date(false);
    Data_SelectRoiSpace();
    Update_ImgProc(STEP_CROP);
}

void D_MAKRO_CiliaSphereTracker::on_spinBox_Param_Crop_Right_valueChanged(int arg1)
{
    arg1;
    state_set_VidProcUp2date(false);
    Data_SelectRoiSpace();
    Update_ImgProc(STEP_CROP);
}

void D_MAKRO_CiliaSphereTracker::on_spinBox_Param_Blur_Size_valueChanged(int arg1)
{
    arg1;
    state_set_VidProcUp2date(false);
    Update_ImgProc(STEP_BLUR);
}

void D_MAKRO_CiliaSphereTracker::on_doubleSpinBox_Param_Blur_Sigma_valueChanged(double arg1)
{
    arg1;
    state_set_VidProcUp2date(false);
    Update_ImgProc(STEP_BLUR);
}

void D_MAKRO_CiliaSphereTracker::state_set_VidProcUp2date(bool is_up2date)
{
    state_VidProcUp2date = is_up2date;
    ui->pushButton_Proc_FullVideo->setEnabled(!is_up2date);

    if(!is_up2date)
        state_StatSummaryCalced = false;
}

void D_MAKRO_CiliaSphereTracker::on_checkBox_Res_TimeProjSum_Gamma_stateChanged(int arg1)
{
    ui->doubleSpinBox_Res_TimeProjSum_Gamma->setEnabled(arg1);
}

void D_MAKRO_CiliaSphereTracker::on_doubleSpinBox_Res_TimeProjSum_ColorLow_valueChanged(double arg1)
{
    if(arg1 > ui->doubleSpinBox_Res_TimeProjSum_ColorHigh->value())
        ui->doubleSpinBox_Res_TimeProjSum_ColorHigh->setValue(arg1);
}

void D_MAKRO_CiliaSphereTracker::on_doubleSpinBox_Res_TimeProjSum_ColorHigh_valueChanged(double arg1)
{
    if(arg1 < ui->doubleSpinBox_Res_TimeProjSum_ColorLow->value())
        ui->doubleSpinBox_Res_TimeProjSum_ColorLow->setValue(arg1);
}

void D_MAKRO_CiliaSphereTracker::on_checkBox_Res_TimeProjSum_ColorLow_stateChanged(int arg1)
{
    if(arg1)
        ui->doubleSpinBox_Res_TimeProjSum_ColorLow->setSuffix("% (blue)");
    else
        ui->doubleSpinBox_Res_TimeProjSum_ColorLow->setSuffix("% (black)");
}

void D_MAKRO_CiliaSphereTracker::on_checkBox_Res_TimeProjSum_ColorHigh_stateChanged(int arg1)
{
    if(arg1)
        ui->doubleSpinBox_Res_TimeProjSum_ColorHigh->setSuffix("% (red)");
    else
        ui->doubleSpinBox_Res_TimeProjSum_ColorHigh->setSuffix("% (white)");
}

void D_MAKRO_CiliaSphereTracker::on_spinBox_Param_FrameCountSmooth_valueChanged(int arg1)
{
    frame_start_ana = frame_start + arg1;
    state_set_VidProcUp2date(false);
}

void D_MAKRO_CiliaSphereTracker::on_comboBox_Res_Type_currentIndexChanged(int index)
{
    //show fitting viewer
    if(index == RES_GRAPHICS_TIME_SUM_PROJ || index == RES_GRAPHICS_VECTORS || index == RES_GRAPHICS_HEATMAP)
        ui->stackedWidget_Res_Type->setCurrentIndex(0);
    else if(index == RES_OVERVIEW)
        ui->stackedWidget_Res_Type->setCurrentIndex(2);
    else
        ui->stackedWidget_Res_Type->setCurrentIndex(1);

    //Show needed params
    Update_Ui_ResParam();

    //update results
    Update_Results();
}

void D_MAKRO_CiliaSphereTracker::on_spinBox_ParamGridVertical_valueChanged(int arg1)
{
    arg1;
    Data_SelectRoiSpace();
    Data_Split2GridSampling();
}

void D_MAKRO_CiliaSphereTracker::on_spinBox_ParamGridHorizontal_valueChanged(int arg1)
{
    arg1;
    Data_SelectRoiSpace();
    Data_Split2GridSampling();
}

void D_MAKRO_CiliaSphereTracker::on_spinBox_Res_MovAv_WindowFrames_valueChanged(int arg1)
{
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected)
        return;

    movav_window_frames = arg1;
    Update_Ui_ResMovAv();

    if(state_VidProcUp2date)
        Update_Results();
}

void D_MAKRO_CiliaSphereTracker::on_doubleSpinBox_Res_MovAv_WindowTime_valueChanged(double arg1)
{
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected)
        return;

    movav_window_frames = (arg1 + 0.5 * VS_InputVideo.get_FrameTimeSec()) * VS_InputVideo.get_FrameRateFps();
    Update_Ui_ResMovAv();

    if(state_VidProcUp2date)
        Update_Results();
}



void D_MAKRO_CiliaSphereTracker::on_spinBox_Res_MovAv_CurrentFrame_valueChanged(int arg1)
{
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected)
        return;

    movav_current_start = arg1;
    Update_Ui_ResMovAv();

    if(state_VidProcUp2date)
        Update_Results();
}

void D_MAKRO_CiliaSphereTracker::on_doubleSpinBox_Res_MovAv_CurrentTime_valueChanged(double arg1)
{
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected)
        return;

    movav_current_start = (arg1 + 0.5 * VS_InputVideo.get_FrameTimeSec()) * VS_InputVideo.get_FrameRateFps();
    Update_Ui_ResMovAv();

    if(state_VidProcUp2date)
        Update_Results();
}

void D_MAKRO_CiliaSphereTracker::on_horizontalSlider_Res_MovAv_CurrentStart_valueChanged(int value)
{
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected)
        return;

    movav_current_start = value;
    Update_Ui_ResMovAv();

    if(state_VidProcUp2date)
        Update_Results();
}

void D_MAKRO_CiliaSphereTracker::on_horizontalSlider_Res_MovAv_CurrentEnd_valueChanged(int value)
{
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected)
        return;

    movav_current_start = value - movav_window_frames;
    Update_Ui_ResMovAv();

    if(state_VidProcUp2date)
        Update_Results();
}

void D_MAKRO_CiliaSphereTracker::on_comboBox_Res_MovAv_TimeWindow_currentIndexChanged(int index)
{
    index;
    Update_Ui_ResParam();

    if(state_VidProcUp2date)
        Update_Results();
}

void D_MAKRO_CiliaSphereTracker::on_comboBox_Res_MovAv_Background_currentIndexChanged(int index)
{
    index;
    Update_Ui_ResParam();

    if(state_VidProcUp2date)
        Update_Results();
}

void D_MAKRO_CiliaSphereTracker::on_spinBox_ParamGrid_CellStart_valueChanged(int arg1)
{
    if(arg1 >= ui->spinBox_ParamGrid_CellEnd->value())
        ui->spinBox_ParamGrid_CellEnd->setValue(arg1 + 1);

    if(state_VidProcUp2date)
        Update_Results();
}

void D_MAKRO_CiliaSphereTracker::on_spinBox_ParamGrid_CellEnd_valueChanged(int arg1)
{
    if(arg1 <= ui->spinBox_ParamGrid_CellStart->value())
        ui->spinBox_ParamGrid_CellStart->setValue(arg1 - 1);

    if(state_VidProcUp2date)
        Update_Results();
}

void D_MAKRO_CiliaSphereTracker::on_comboBox_Res_PlotLine_FixRange_T_currentIndexChanged(int index)
{
    ui->doubleSpinBox_Res_PlotLine_FixRange_T_min->setEnabled(index == PLOT_TIME_CUSTOM);
    ui->doubleSpinBox_Res_PlotLine_FixRange_T_max->setEnabled(index == PLOT_TIME_CUSTOM);
}

void D_MAKRO_CiliaSphereTracker::on_checkBox_Res_PlotLine_FixRange_S_stateChanged(int arg1)
{
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_min->setEnabled(arg1);
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_max->setEnabled(arg1);
}

void D_MAKRO_CiliaSphereTracker::on_checkBox_Res_PlotLine_FixRange_A_stateChanged(int arg1)
{
    ui->doubleSpinBox_Res_PlotLine_FixRange_A_min->setEnabled(arg1);
    ui->doubleSpinBox_Res_PlotLine_FixRange_A_max->setEnabled(arg1);
}

void D_MAKRO_CiliaSphereTracker::on_spinBox_Res_PlotPoincare_Shift_Frames_valueChanged(int arg1)
{
    ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->blockSignals(true);
    ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setValue(arg1 * VS_InputVideo.get_frame_2_timeSec());
    ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->blockSignals(false);
    Update_Results();
}

void D_MAKRO_CiliaSphereTracker::on_doubleSpinBox_Res_PlotPoincare_Shift_Seconds_valueChanged(double arg1)
{
    ui->spinBox_Res_PlotPoincare_Shift_Frames->blockSignals(true);
    ui->spinBox_Res_PlotPoincare_Shift_Frames->setValue(arg1 / VS_InputVideo.get_frame_2_timeSec());
    ui->spinBox_Res_PlotPoincare_Shift_Frames->blockSignals(false);
    Update_Results();
}
