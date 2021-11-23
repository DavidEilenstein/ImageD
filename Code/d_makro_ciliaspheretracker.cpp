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

    /*
    //task bar progress
    pTaskBarButton = new QWinTaskbarButton(this);
    pTaskBarButton->setWindow(windowHandle());
    pTaskBarButton->setOverlayIcon(QIcon(":/logo/ImageD_Logo.png"));
    pTaskBarProgress = pTaskBarButton->progress();
    pTaskBarProgress->setVisible(true);
    */

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



    pChartView_Results_Overview1_SpeedLine = new QChartView();
    D_Plot::Plot_Empty(pChartView_Results_Overview1_SpeedLine, "Plot Initialized (Overview, Speed, Line)");
    ui->gridLayout_Res_Overview_SpeedLine->addWidget(pChartView_Results_Overview1_SpeedLine);
    pChartView_Results_Overview1_SpeedLine->setRenderHint(QPainter::Antialiasing);
    pChartView_Results_Overview1_SpeedLine->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Results_Overview1_SpeedLine->setInteractive(true);

    pChartView_Results_Overview1_SpeedPoincare = new QChartView();
    D_Plot::Plot_Empty(pChartView_Results_Overview1_SpeedPoincare, "Plot Initialized (Overview, Speed, Poincare)");
    ui->gridLayout_Res_Overview_SpeedPoincare->addWidget(pChartView_Results_Overview1_SpeedPoincare);
    pChartView_Results_Overview1_SpeedPoincare->setRenderHint(QPainter::Antialiasing);
    pChartView_Results_Overview1_SpeedPoincare->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Results_Overview1_SpeedPoincare->setInteractive(true);
    pChartView_Results_Overview1_SpeedPoincare->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    pChartView_Results_Overview1_AngleLine = new QChartView();
    D_Plot::Plot_Empty(pChartView_Results_Overview1_AngleLine, "Plot Initialized (Overview, Angle, Line)");
    ui->gridLayout_Res_Overview_AngleLine->addWidget(pChartView_Results_Overview1_AngleLine);
    pChartView_Results_Overview1_AngleLine->setRenderHint(QPainter::Antialiasing);
    pChartView_Results_Overview1_AngleLine->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Results_Overview1_AngleLine->setInteractive(true);

    pChartView_Results_Overview1_AnglePoincare = new QChartView();
    D_Plot::Plot_Empty(pChartView_Results_Overview1_AnglePoincare, "Plot Initialized (Overview, Angle, Poincare)");
    ui->gridLayout_Res_Overview_AnglePoincare->addWidget(pChartView_Results_Overview1_AnglePoincare);
    pChartView_Results_Overview1_AnglePoincare->setRenderHint(QPainter::Antialiasing);
    pChartView_Results_Overview1_AnglePoincare->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Results_Overview1_AnglePoincare->setInteractive(true);
    pChartView_Results_Overview1_AnglePoincare->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);



    pChartView_Results_Overview2_SpeedLinear_Line = new QChartView();
    D_Plot::Plot_Empty(pChartView_Results_Overview2_SpeedLinear_Line, "Plot Initialized (Overview2, linear speed, Line)");
    ui->gridLayout_Res_OverviewNew_Line_LinearSpeed->addWidget(pChartView_Results_Overview2_SpeedLinear_Line);
    pChartView_Results_Overview2_SpeedLinear_Line->setRenderHint(QPainter::Antialiasing);
    pChartView_Results_Overview2_SpeedLinear_Line->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Results_Overview2_SpeedLinear_Line->setInteractive(true);

    pChartView_Results_Overview2_SpeedAngular_Line = new QChartView();
    D_Plot::Plot_Empty(pChartView_Results_Overview2_SpeedAngular_Line, "Plot Initialized (Overview2, angular speed, Line)");
    ui->gridLayout_Res_OverviewNew_Line_AngularSpeed->addWidget(pChartView_Results_Overview2_SpeedAngular_Line);
    pChartView_Results_Overview2_SpeedAngular_Line->setRenderHint(QPainter::Antialiasing);
    pChartView_Results_Overview2_SpeedAngular_Line->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Results_Overview2_SpeedAngular_Line->setInteractive(true);

    pChartView_Results_Overview2_SpeedLinear_Hist = new QChartView();
    D_Plot::Plot_Empty(pChartView_Results_Overview2_SpeedLinear_Hist, "Plot Initialized (Overview2, linear speed, hist)");
    ui->gridLayout_Res_OverviewNew_Hist_LinearSpeed->addWidget(pChartView_Results_Overview2_SpeedLinear_Hist);
    pChartView_Results_Overview2_SpeedLinear_Hist->setRenderHint(QPainter::Antialiasing);
    pChartView_Results_Overview2_SpeedLinear_Hist->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Results_Overview2_SpeedLinear_Hist->setInteractive(true);

    pChartView_Results_Overview2_SpeedAngular_Hist = new QChartView();
    D_Plot::Plot_Empty(pChartView_Results_Overview2_SpeedAngular_Hist, "Plot Initialized (Overview2, angular speed, hist)");
    ui->gridLayout_Res_OverviewNew_Hist_AngularSpeed->addWidget(pChartView_Results_Overview2_SpeedAngular_Hist);
    pChartView_Results_Overview2_SpeedAngular_Hist->setRenderHint(QPainter::Antialiasing);
    pChartView_Results_Overview2_SpeedAngular_Hist->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Results_Overview2_SpeedAngular_Hist->setInteractive(true);

    pChartView_Results_Overview2_DistCenterIntersections_Hist = new QChartView();
    D_Plot::Plot_Empty(pChartView_Results_Overview2_DistCenterIntersections_Hist, "Plot Initialized (Overview2, distance intersections to center, hist)");
    ui->gridLayout_Res_OverviewNew_Hist_DistanceCenterIntersections->addWidget(pChartView_Results_Overview2_DistCenterIntersections_Hist);
    pChartView_Results_Overview2_DistCenterIntersections_Hist->setRenderHint(QPainter::Antialiasing);
    pChartView_Results_Overview2_DistCenterIntersections_Hist->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Results_Overview2_DistCenterIntersections_Hist->setInteractive(true);

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

    //status bar
    L_SB_ValAtPos = new QLabel(this);
    L_SB_ValAtPos->setToolTip("Pixelvalue (Mouse hovered)");
    ui->statusbar->addPermanentWidget(L_SB_ValAtPos);

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
    connect(ui->comboBox_Res_VectorFieldParam_ShiftType,            SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_VectorFieldParam_Length_Value,         SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_VectorFieldParam_Length_Error,         SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_VectorFieldParam_Angle_Value,          SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_VectorFieldParam_Angle_Error,          SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->spinBox_Res_VectorFieldParam_KindeySteps,           SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->spinBox_Res_VectorFieldParam_Thickness_Vector,      SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->spinBox_Res_VectorFieldParam_Thickness_Error,       SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds, SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_VectorFieldParam_ScaleLength,     SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    //histogram
    connect(ui->doubleSpinBox_Res_Histo_MaxSpeedLinear,             SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_Histo_MaxSpeedAngular,            SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_Histo_MaxDistCenterIntersections, SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->spinBox_Res_Histo_Classes_Speed,                    SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->spinBox_Res_Histo_Classes_Dist,                     SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->checkBox_Res_Histo_Acc,                             SIGNAL(stateChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->checkBox_Res_Histo_Uni,                             SIGNAL(stateChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->checkBox_Res_Histo_VariationAsColorValue,           SIGNAL(stateChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_Histo_Type,                            SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
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
    connect(ui->comboBox_Res_SpeedCustom_ShiftType,                 SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
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
    connect(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_linear,   SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_linear,   SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_angular,  SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_angular,  SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_PlotLine_FixRange_A_min,          SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_PlotLine_FixRange_A_max,          SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    //heatmap
    connect(ui->comboBox_Res_Heat_Mode,                             SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    //vortex center
    connect(ui->doubleSpinBox_Res_VortexCenter_WellDiameter,        SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_VortexCenter_Resolution_Rel,      SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize,    SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->spinBox_Res_VortexCenter_Thickness,                 SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->spinBox_Res_VortexCenter_RansacIterations,          SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->checkBox_Res_VortexCenter_Ransac,                   SIGNAL(stateChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->checkBox_Res_VortexCenter_MovingAverage,            SIGNAL(stateChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines,     SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    //vortex center file name interpretation
    connect(ui->doubleSpinBox_Res_VortexCenter_RelPos_H_Use,        SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_Res_VortexCenter_RelPos_H_Set1,       SIGNAL(valueChanged(double)),               this,                   SLOT(Data_GetSetVideoPos_Current()));
    connect(ui->doubleSpinBox_Res_VortexCenter_RelPos_H_Set2,       SIGNAL(valueChanged(double)),               this,                   SLOT(Data_GetSetVideoPos_Current()));
    connect(ui->lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set1,SIGNAL(editingFinished()),                  this,                   SLOT(Data_GetSetVideoPos_Current()));
    connect(ui->lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set2,SIGNAL(editingFinished()),                  this,                   SLOT(Data_GetSetVideoPos_Current()));
    //field summary
    connect(ui->comboBox_Res_FieldSumary_StatType,                  SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_FieldSumary_StatIndex_Grid,            SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_FieldSumary_StatIndex_Cells_Linear,    SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_FieldSumary_StatIndex_Cells_Angular,   SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    //status bar
    connect(&View_Results,                                          SIGNAL(MouseMoved_Value(QString)),          L_SB_ValAtPos,          SLOT(setText(QString)));
    connect(&View_Proc,                                             SIGNAL(MouseMoved_Value(QString)),          L_SB_ValAtPos,          SLOT(setText(QString)));


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

    pChartView_Results_Overview1_SpeedPoincare->setBaseSize(pChartView_Results_Overview1_SpeedPoincare->height(), pChartView_Results_Overview1_SpeedPoincare->height());
    pChartView_Results_Overview1_AnglePoincare->setBaseSize(pChartView_Results_Overview1_AnglePoincare->height(), pChartView_Results_Overview1_AnglePoincare->height());
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
        //qDebug() << "==================================================================" << "frame" << frame_cur << "/" << frame_index_effective << "index_NewImg =" << index_NewImg;

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

    if(state_blockResultUpdate)
        return;

    switch (ui->comboBox_Res_Type->currentIndex()) {
    case RES_GRAPHICS_TIME_SUM_PROJ:        Update_Result_GraphicsTimeProjectSum();     break;
    case RES_GRAPHICS_VECTORS:              Update_Result_GraphicsVectors();            break;
    case RES_GRAPHICS_HEATMAP:              Update_Result_GraphicsHeatmap();            break;
    case RES_GRAPHICS_FIELD_SUMMARY:        Update_Result_GridSummary();                break;
    case RES_GRAPHICS_VORTEX_CENTER:        Update_Result_GraphicsVortexCenter();       break;
    case RES_SPEED_STAT_CUSTOM:             Update_Result_SpeedStatCustom();            break;
    case RES_ANGLE_STAT_CUSTOM:             Update_Result_AngleStatCustom();            break;
    case RES_SPEED_ANALYSIS:                Update_Result_SpeedAnalysis();              break;
    case RES_ANGLE_ANALYSIS:                Update_Result_AngleAnalysis();              break;
    case RES_HISTOGRAM:                     Update_Result_Histogram();                  break;

    case RES_OVERVIEW1:
    {
        Update_Result_SpeedAnalysis();
        Update_Result_AngleAnalysis();
    }
        break;

    case RES_OVERVIEW2:
    {
        ui->comboBox_Res_SpeedCustom_ShiftType->blockSignals(true);
        size_t index_old = ui->comboBox_Res_SpeedCustom_ShiftType->currentIndex();
        ui->comboBox_Res_SpeedCustom_ShiftType->setCurrentIndex(SHIFT_TYPE_LINEAR);
        Update_Result_SpeedAnalysis();
        ui->comboBox_Res_SpeedCustom_ShiftType->setCurrentIndex(SHIFT_TYPE_ANGULAR);
        Update_Result_SpeedAnalysis();
        ui->comboBox_Res_SpeedCustom_ShiftType->setCurrentIndex(index_old);
        ui->comboBox_Res_SpeedCustom_ShiftType->blockSignals(false);

        ui->comboBox_Res_Histo_Type->blockSignals(true);
        index_old = ui->comboBox_Res_Histo_Type->currentIndex();
        ui->comboBox_Res_Histo_Type->setCurrentIndex(HIST_LINEAR_SPEED);
        Update_Result_Histogram();
        ui->comboBox_Res_Histo_Type->setCurrentIndex(HIST_ANGULAR_SPEED);
        Update_Result_Histogram();
        ui->comboBox_Res_Histo_Type->setCurrentIndex(HIST_DIST_CENTER_INTERSECTIONS);
        Update_Result_Histogram();
        ui->comboBox_Res_Histo_Type->setCurrentIndex(index_old);
        ui->comboBox_Res_Histo_Type->blockSignals(false);
    }
        break;

    default:
        return;
    }
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

    //shift type
    int shift_type = ui->comboBox_Res_VectorFieldParam_ShiftType->currentIndex();

    //calc center, if needed
    if(!state_vortex_center_calced)
        Update_Result_GraphicsVortexCenter();
    if(!state_vortex_center_calced && shift_type == SHIFT_TYPE_ANGULAR)
        return;

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
    vector<vector<size_t>> vv_XY_DetectionCounts(nx);
    for(size_t gx = 0; gx < nx; gx++)
    {
        vv_XY_LengthValues[gx].resize(ny, 0);
        vv_XY_LengthErrors[gx].resize(ny, 0);
        vv_XY_AngleValues[gx].resize(ny, 0);
        vv_XY_AngleErrors[gx].resize(ny, 0);
        vv_XY_DetectionCounts[gx].resize(ny, 0);
    }

    //loop grid cells
    for(size_t gx = 0; gx < nx; gx++)
    {
        for(size_t gy = 0; gy < ny; gy++)
        {
            //group all needed elements in 1D container
            vector<double> v_ShiftsInCell;
            vector<double> v_AnglesInCell;

            //calc dist2center if needed
            D_Geo_Point_2D P_GridCellCenter(
                        ((gx + 0.5) / static_cast<double>(nx)) * spatial_roi_width,
                        ((gy + 0.5) / static_cast<double>(ny)) * spatial_roi_height);
            double dist2center = state_vortex_center_calced ? P_VortexCenter.distance(P_GridCellCenter) : 0.0;

            //loop time window
            for(size_t it = it_start; it < it_end; it++)
            {
                //number of objects in cell and frame
                size_t no = vvvv_XYFrmObjShifts[gx][gy][it].size();
                vv_XY_DetectionCounts[gx][gy] += no;

                //loop, extract and rescale lengths
                for(size_t obj = 0; obj < no; obj++)
                {
                    //linear or angular shift
                    if(shift_type == SHIFT_TYPE_LINEAR)
                    {
                        v_ShiftsInCell.push_back(vvvv_XYFrmObjShifts[gx][gy][it][obj] * shift_scale);
                        v_AnglesInCell.push_back(vvvv_XYFrmObjAngles[gx][gy][it][obj]);//angle of movement
                    }
                    else
                    {
                        //linear shift --> angular shift in rad
                        v_ShiftsInCell.push_back(dist2center > 0 ? ((vvvv_XYFrmObjShifts[gx][gy][it][obj] * shift_scale) / (dist2center)) : 0.0);

                        //calc angel that is 90° to movement direction and points away from vortex center
                        double a_movement = vvvv_XYFrmObjAngles[gx][gy][it][obj];
                        double a_orthogonal_1 = a_movement + 3 * PI_0_5;
                        double a_orthogonal_2 = a_movement + 1 * PI_0_5;
                        D_Geo_Point_2D P_d1(a_orthogonal_1);
                        D_Geo_Point_2D P_d2(a_orthogonal_2);
                        double dist_1 = P_VortexCenter.distance(P_GridCellCenter.add_inhomo(P_d1));
                        double dist_2 = P_VortexCenter.distance(P_GridCellCenter.add_inhomo(P_d2));
                        v_AnglesInCell.push_back(dist_1 > dist_2 ? a_orthogonal_1 : a_orthogonal_2);
                    }
                }
            }

            //calc grid cell representing data if there are any
            if(vv_XY_DetectionCounts[gx][gy] > 0)
            {
                //calc stats
                vector<double> v_Shifts_Stats(c_STAT_NUMBER_OF_STATS, 0);
                vector<double> v_Angles_Stats(c_STAT_CIRC_NUMBER_OF, 0);

                D_Stat::Calc_Stats(
                            &v_Shifts_Stats,
                            v_ShiftsInCell,
                            true);

                D_Stat::Calc_Stats_Circ_Rad(
                            &v_Angles_Stats,
                            v_AnglesInCell);

                //Export needed stats
                //shift
                if(shift_type == SHIFT_TYPE_LINEAR)
                {
                    vv_XY_LengthValues[gx][gy] = v_Shifts_Stats[stat_length_val] * radius_scale;
                    vv_XY_LengthErrors[gx][gy] = v_Shifts_Stats[stat_length_err] * radius_scale;
                }
                else
                {
                    vv_XY_LengthValues[gx][gy] = v_Shifts_Stats[stat_length_val];
                    vv_XY_LengthErrors[gx][gy] = v_Shifts_Stats[stat_length_err];
                }
                //angles
                vv_XY_AngleValues[gx][gy] = v_Angles_Stats[stat_angle_val];
                vv_XY_AngleErrors[gx][gy] = v_Angles_Stats[stat_angle_err];

                //Test Output
                //qDebug() << "Update_Result_GraphicsVectors at gx/gy" << gx << gy << "length:" << vv_XY_LengthValues[gx][gy] << vv_XY_LengthErrors[gx][gy] << "angle:" << vv_XY_AngleValues[gx][gy] << vv_XY_AngleErrors[gx][gy];
            }
            else
            {
                vv_XY_LengthValues[gx][gy] = 0;
                vv_XY_LengthErrors[gx][gy] = 0;
                vv_XY_AngleValues[gx][gy] = 0;
                vv_XY_AngleErrors[gx][gy] = 0;
            }
        }
    }

    //=========================================================================================================== draw results ===================

    //draw vector field
    Mat MA_tmp_overlay_field = Mat::zeros(MA_TimeProject_Show.size(), CV_8UC1);
    //qDebug() << "Update_Result_GraphicsVectors" << "Draw_VectorField";
    if(shift_type == SHIFT_TYPE_LINEAR)
    {
        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: linear shifts

        //check, if vectors or circles shall be drawn
        if(ui->comboBox_Res_VectorFieldParam_Angle_Value ->currentIndex() == c_STAT_CIRC_CONST_0 && ui->comboBox_Res_VectorFieldParam_Angle_Error->currentIndex() == c_STAT_CIRC_CONST_PI)
        {
            ERR(D_Img_Proc::Draw_CircleField(
                    &MA_tmp_overlay_field,
                    vv_XY_LengthValues,
                    vv_XY_LengthErrors,
                    255,
                    ui->spinBox_Res_VectorFieldParam_Thickness_Vector->value(),
                    false,
                    ui->checkBox_Res_GridVisParam_Grid->isChecked(),
                    ui->spinBox_Res_GridVisParam_Thickness_Grid->value(),
                    ui->checkBox_Res_GridVisParam_Labels->isChecked(),
                    ui->spinBox_Res_GridVisParam_Thickness_Label->value(),
                    ui->doubleSpinBox_Res_GridVisParam_Label_Scaling->value()),
                "Update_Result_GraphicsVectors",
                "Draw_CircleField");
        }
        else
        {
            ERR(D_Img_Proc::Draw_VectorField(
                    &MA_tmp_overlay_field,
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
        }

        //add overlay to image
        ERR(D_Img_Proc::OverlayOverwrite(
                &MA_Result,
                &MA_TimeProject_Show,
                &MA_tmp_overlay_field,
                0, 255, 0,
                1.0,
                1.0),
            "Update_Result_GraphicsVectors",
            "OverlayOverwrite - Vectorfield");
    }
    else
    {
        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: angular shifts

        //------------------------ lines ---------------------------

        //draw lines from grid cell centers to vortex center
        Mat MA_tmp_overlay_lines = Mat::zeros(MA_TimeProject_Show.size(), CV_8UC1);
        for(size_t gx = 0; gx < nx; gx++)
        {
            for(size_t gy = 0; gy < ny; gy++)
            {
                if(vv_XY_DetectionCounts[gx][gy] > 0)
                {
                    //grid cell center
                    D_Geo_Point_2D P_GridCellCenter(
                                ((gx + 0.5) / static_cast<double>(nx)) * spatial_roi_width,
                                ((gy + 0.5) / static_cast<double>(ny)) * spatial_roi_height);

                    //line from center of grid cell to center of vortex
                    D_Geo_Line_2D L_GridCenter_VortexCenter(P_GridCellCenter, P_VortexCenter);

                    //check, if vortex center is in image or not
                    if(P_VortexCenter.in_rect(&MA_tmp_overlay_lines))
                    {
                        //.................. vortex center in image ..............................

                        ERR(D_Img_Proc::Draw_Line(
                                &MA_tmp_overlay_lines,
                                P_GridCellCenter.x(),
                                P_GridCellCenter.y(),
                                P_VortexCenter.x(),
                                P_VortexCenter.y(),
                                max(2.0 , ui->spinBox_Res_VectorFieldParam_Thickness_Vector->value() / 2.0),
                                255),
                            "Update_Result_GraphicsVortexCenter",
                            "Draw_Line - center vortex to center grid cell");
                    }
                    else
                    {
                        //.................... vortex center out of image ...........................

                        //calc 2 points on line that intersect image border
                        D_Geo_Point_2D P1_Border, P2_Border;
                        if(L_GridCenter_VortexCenter.intersection_rect(&P1_Border, &P2_Border, &MA_tmp_overlay_lines))
                        {
                            //find point on border between grid cell center and vortex center
                            double dist_sum_p1 = P1_Border.distance(P_VortexCenter) + P1_Border.distance(P_GridCellCenter);
                            double dist_sum_p2 = P2_Border.distance(P_VortexCenter) + P2_Border.distance(P_GridCellCenter);
                            D_Geo_Point_2D P_Border2Use = dist_sum_p1 < dist_sum_p2 ? P1_Border : P2_Border;

                            //draw line
                            ERR(D_Img_Proc::Draw_Line(
                                    &MA_tmp_overlay_lines,
                                    P_GridCellCenter.x(),
                                    P_GridCellCenter.y(),
                                    P_Border2Use.x(),
                                    P_Border2Use.y(),
                                    max(2.0 , ui->spinBox_Res_VectorFieldParam_Thickness_Vector->value() / 2.0),
                                    255),
                                "Update_Result_GraphicsVortexCenter",
                                "Draw_Line - center vortex to center grid cell");
                        }
                    }
                }
            }
        }

        //add line overlay to image
        Mat MA_tmp_LinesAdded;
        ERR(D_Img_Proc::OverlayOverwrite(
                &MA_tmp_LinesAdded,
                &MA_TimeProject_Show,
                &MA_tmp_overlay_lines,
                0, 0, 255,
                1.0,
                1.0),
            "Update_Result_GraphicsVectors",
            "OverlayOverwrite - Lines");

        //------------------------ arcs ---------------------------

        //radii of arcs
        double arc_radius = (min(spatial_roi_width / nx, spatial_roi_height / ny) / 3.0) * radius_scale;
        vector<vector<double>> vv_arc_radii(nx, vector<double>(ny, arc_radius));

        //draw arc field
        ERR(D_Img_Proc::Draw_ArcField(
                &MA_tmp_overlay_field,
                vv_XY_LengthValues,
                vv_XY_LengthErrors,
                vv_XY_AngleValues,
                vv_arc_radii,
                vv_XY_DetectionCounts,
                255,
                ui->spinBox_Res_VectorFieldParam_Thickness_Vector->value(),
                ui->spinBox_Res_VectorFieldParam_KindeySteps->value(),
                ui->checkBox_Res_GridVisParam_Grid->isChecked(),
                ui->spinBox_Res_GridVisParam_Thickness_Grid->value(),
                ui->checkBox_Res_GridVisParam_Labels->isChecked(),
                ui->spinBox_Res_GridVisParam_Thickness_Label->value(),
                ui->doubleSpinBox_Res_GridVisParam_Label_Scaling->value()),
            "Update_Result_GraphicsVectors",
            "Draw_ArcField");

        //add overlay to image
        ERR(D_Img_Proc::OverlayOverwrite(
                &MA_Result,
                &MA_tmp_LinesAdded,
                &MA_tmp_overlay_field,
                0, 255, 0,
                1.0,
                1.0),
            "Update_Result_GraphicsVectors",
            "OverlayOverwrite - Vectorfield");
        MA_tmp_LinesAdded.release();
    }




    //clear
    MA_tmp_overlay_field.release();
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

    //calc center if needed and not done yet
    if(!state_vortex_center_calced && ui->comboBox_Res_Heat_Mode->currentIndex() == HEAT_SPEED_ANGULAR)
        Update_Result_GraphicsVortexCenter();
    if(!state_vortex_center_calced && ui->comboBox_Res_Heat_Mode->currentIndex() == HEAT_SPEED_ANGULAR)
    {
        ERR(ER_other, "Update_Result_GraphicsHeatmap", "Unable to show angular speed heatmap because no valid vortex center was found");
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
                P_VortexCenter.CV_Point2f(),
                conv_px2um * VS_InputVideo.get_FrameRateFps(),  //px/frm -> um/sec (as a factor to be applied to px/frm value)
                value_max / 255.0,                              //factor for 8bit gray value to movements count
                5, 5,                                           //blur
                ui->comboBox_Res_Heat_Mode->currentIndex(),     //what to show
                1500, 99,                                       //legend size
                1.0, 1,                                         //font size
                5,                                              //examples on legend count
                0.1, 0.9,                                       //quantile range dor values to be shown
                VS_InputVideo.get_FrameTimeSec());              //frame time to scale frames to times
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

void D_MAKRO_CiliaSphereTracker::Update_Result_GridSummary()
{
    //Check requirements
    qDebug() << "Update_Result_StatFilter" << "check requirements";
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_ImgProcUp2date || !state_GridSamplingSplit || !state_VidProcUp2date)
        return;

    //data type and stat
    qDebug() << "Update_Result_StatFilter" << "type and stat";
    int data_type = ui->comboBox_Res_FieldSumary_StatType->currentIndex();
    bool angular = data_type == DATA_TYPE_ANGLE;
    int stat_cell = angular ? ui->comboBox_Res_FieldSumary_StatIndex_Cells_Angular->currentIndex() : ui->comboBox_Res_FieldSumary_StatIndex_Cells_Linear->currentIndex();
    int stat_grid = ui->comboBox_Res_FieldSumary_StatIndex_Grid->currentIndex();

    //shift type
    if(data_type == DATA_TYPE_SPEED_LINEAR)
    {
        ui->comboBox_Res_VectorFieldParam_ShiftType->blockSignals(true);
        ui->comboBox_Res_VectorFieldParam_ShiftType->setCurrentIndex(SHIFT_TYPE_LINEAR);
        ui->comboBox_Res_VectorFieldParam_ShiftType->blockSignals(false);
    }
    if(data_type == DATA_TYPE_SPEED_ANGULAR)
    {
        ui->comboBox_Res_VectorFieldParam_ShiftType->blockSignals(true);
        ui->comboBox_Res_VectorFieldParam_ShiftType->setCurrentIndex(SHIFT_TYPE_ANGULAR);
        ui->comboBox_Res_VectorFieldParam_ShiftType->blockSignals(false);
    }
    int shift_type = ui->comboBox_Res_VectorFieldParam_ShiftType->currentIndex();

    //calc center, if needed
    if(!state_vortex_center_calced)
        Update_Result_GraphicsVortexCenter();
    if(!state_vortex_center_calced && shift_type == SHIFT_TYPE_ANGULAR)
        return;

    //Update background img
    ui->comboBox_Res_MovAv_TimeWindow->blockSignals(true);
    ui->comboBox_Res_MovAv_TimeWindow->setCurrentIndex(TIME_WINDOW_FULL_VIDEO);
    ui->comboBox_Res_MovAv_TimeWindow->blockSignals(false);
    ui->comboBox_Res_MovAv_Background->blockSignals(true);
    ui->comboBox_Res_MovAv_Background->setCurrentIndex(BACKGR_PROJECTION);
    ui->comboBox_Res_MovAv_Background->blockSignals(false);
    Update_Result_GraphicsTimeProjectSum();

    //stats selected
    int stat_length_val = ui->comboBox_Res_VectorFieldParam_Length_Value->currentIndex();
    int stat_length_err = ui->comboBox_Res_VectorFieldParam_Length_Error->currentIndex();
    int stat_angle_val  = ui->comboBox_Res_VectorFieldParam_Angle_Value->currentIndex();
    int stat_angle_err  = ui->comboBox_Res_VectorFieldParam_Angle_Error->currentIndex();

    //time window
    size_t it_start     = 0;
    size_t it_end       = frame_end - frame_start_ana;
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
    vector<vector<size_t>> vv_XY_DetectionCounts(nx);
    for(size_t gx = 0; gx < nx; gx++)
    {
        vv_XY_LengthValues[gx].resize(ny, 0);
        vv_XY_LengthErrors[gx].resize(ny, 0);
        vv_XY_AngleValues[gx].resize(ny, 0);
        vv_XY_AngleErrors[gx].resize(ny, 0);
        vv_XY_DetectionCounts[gx].resize(ny, 0);
    }

    //stat to summarize
    vector<double> v_StatToSummarize;

    //loop grid cells
    for(size_t gx = 0; gx < nx; gx++)
    {
        for(size_t gy = 0; gy < ny; gy++)
        {
            //group all needed elements in 1D container
            vector<double> v_ShiftsLinearInCell;
            vector<double> v_ShiftsAngularInCell;
            vector<double> v_AnglesLinearInCell;
            vector<double> v_AnglesAngularInCell;

            //calc dist2center if needed
            D_Geo_Point_2D P_GridCellCenter(
                        ((gx + 0.5) / static_cast<double>(nx)) * spatial_roi_width,
                        ((gy + 0.5) / static_cast<double>(ny)) * spatial_roi_height);
            double dist2center = state_vortex_center_calced ? P_VortexCenter.distance(P_GridCellCenter) : 0.0;

            //loop time window
            for(size_t it = it_start; it < it_end; it++)
            {
                //number of objects in cell and frame
                size_t no = vvvv_XYFrmObjShifts[gx][gy][it].size();
                vv_XY_DetectionCounts[gx][gy] += no;

                //loop, extract and rescale lengths
                for(size_t obj = 0; obj < no; obj++)
                {
                    //linear

                    v_ShiftsLinearInCell.push_back(vvvv_XYFrmObjShifts[gx][gy][it][obj] * shift_scale);
                    v_AnglesLinearInCell.push_back(vvvv_XYFrmObjAngles[gx][gy][it][obj]);//angle of movement

                    //angular

                    //linear shift --> angular shift in rad
                    v_ShiftsAngularInCell.push_back(dist2center > 0 ? ((vvvv_XYFrmObjShifts[gx][gy][it][obj] * shift_scale) / (dist2center)) : 0.0);

                    //calc angel that is 90° to movement direction and points away from vortex center
                    double a_movement = vvvv_XYFrmObjAngles[gx][gy][it][obj];
                    double a_orthogonal_1 = a_movement + 3 * PI_0_5;
                    double a_orthogonal_2 = a_movement + 1 * PI_0_5;
                    D_Geo_Point_2D P_d1(a_orthogonal_1);
                    D_Geo_Point_2D P_d2(a_orthogonal_2);
                    double dist_1 = P_VortexCenter.distance(P_GridCellCenter.add_inhomo(P_d1));
                    double dist_2 = P_VortexCenter.distance(P_GridCellCenter.add_inhomo(P_d2));
                    v_AnglesAngularInCell.push_back(dist_1 > dist_2 ? a_orthogonal_1 : a_orthogonal_2);
                }
            }

            //calc grid cell representing data if there are any
            if(vv_XY_DetectionCounts[gx][gy] > 0)
            {
                //calc stats
                vector<double> v_Shifts_lin_Stats(c_STAT_NUMBER_OF_STATS, 0);
                vector<double> v_Shifts_ang_Stats(c_STAT_NUMBER_OF_STATS, 0);
                vector<double> v_Angles_lin_Stats(c_STAT_CIRC_NUMBER_OF, 0);
                vector<double> v_Angles_ang_Stats(c_STAT_CIRC_NUMBER_OF, 0);

                D_Stat::Calc_Stats(
                            &v_Shifts_lin_Stats,
                            v_ShiftsLinearInCell,
                            true);

                D_Stat::Calc_Stats_Circ_Rad(
                            &v_Angles_lin_Stats,
                            v_AnglesLinearInCell);

                D_Stat::Calc_Stats(
                            &v_Shifts_ang_Stats,
                            v_ShiftsAngularInCell,
                            true);

                D_Stat::Calc_Stats_Circ_Rad(
                            &v_Angles_ang_Stats,
                            v_AnglesAngularInCell);

                //Export needed stats
                if(shift_type == SHIFT_TYPE_LINEAR)
                {
                    //shifts
                    vv_XY_LengthValues[gx][gy] = v_Shifts_lin_Stats[stat_length_val] * radius_scale;
                    vv_XY_LengthErrors[gx][gy] = v_Shifts_lin_Stats[stat_length_err] * radius_scale;

                    //angles
                    vv_XY_AngleValues[gx][gy] = v_Angles_lin_Stats[stat_angle_val];
                    vv_XY_AngleErrors[gx][gy] = v_Angles_lin_Stats[stat_angle_err];
                }
                else
                {
                    //shifts
                    vv_XY_LengthValues[gx][gy] = v_Shifts_ang_Stats[stat_length_val];
                    vv_XY_LengthErrors[gx][gy] = v_Shifts_ang_Stats[stat_length_err];

                    //angles
                    vv_XY_AngleValues[gx][gy] = v_Angles_ang_Stats[stat_angle_val];
                    vv_XY_AngleErrors[gx][gy] = v_Angles_ang_Stats[stat_angle_err];
                }

                if(data_type == DATA_TYPE_SPEED_LINEAR)                                     v_StatToSummarize.push_back(v_Shifts_lin_Stats[stat_cell]);
                else if(data_type == DATA_TYPE_SPEED_ANGULAR)                               v_StatToSummarize.push_back(v_Shifts_ang_Stats[stat_cell]);
                else if(data_type == DATA_TYPE_ANGLE && shift_type == SHIFT_TYPE_LINEAR)    v_StatToSummarize.push_back(v_Angles_lin_Stats[stat_cell]);
                else                                                                        v_StatToSummarize.push_back(v_Angles_ang_Stats[stat_cell]);

                //Test Output
                //qDebug() << "Update_Result_GraphicsVectors at gx/gy" << gx << gy << "length:" << vv_XY_LengthValues[gx][gy] << vv_XY_LengthErrors[gx][gy] << "angle:" << vv_XY_AngleValues[gx][gy] << vv_XY_AngleErrors[gx][gy];
            }
            else
            {
                vv_XY_LengthValues[gx][gy] = 0;
                vv_XY_LengthErrors[gx][gy] = 0;
                vv_XY_AngleValues[gx][gy] = 0;
                vv_XY_AngleErrors[gx][gy] = 0;
            }
        }
    }

    //=========================================================================================================== summarize stat ===================

    vector<double> v_StatSummarized(c_STAT_NUMBER_OF_STATS, 0);

    D_Stat::Calc_Stats(
                    &v_StatSummarized,
                    v_StatToSummarize,
                    true);

    ui->doubleSpinBox_FieldSumary_StatResult->setValue(v_StatToSummarize[stat_grid]);

    //=========================================================================================================== draw results ===================

    //draw vector field
    Mat MA_tmp_overlay_field = Mat::zeros(MA_TimeProject_Show.size(), CV_8UC1);
    //qDebug() << "Update_Result_GraphicsVectors" << "Draw_VectorField";
    if(shift_type == SHIFT_TYPE_LINEAR)
    {
        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: linear shifts

        //check, if vectors or circles shall be drawn
        if(ui->comboBox_Res_VectorFieldParam_Angle_Value ->currentIndex() == c_STAT_CIRC_CONST_0 && ui->comboBox_Res_VectorFieldParam_Angle_Error->currentIndex() == c_STAT_CIRC_CONST_PI)
        {
            ERR(D_Img_Proc::Draw_CircleField(
                    &MA_tmp_overlay_field,
                    vv_XY_LengthValues,
                    vv_XY_LengthErrors,
                    255,
                    ui->spinBox_Res_VectorFieldParam_Thickness_Vector->value(),
                    false,
                    ui->checkBox_Res_GridVisParam_Grid->isChecked(),
                    ui->spinBox_Res_GridVisParam_Thickness_Grid->value(),
                    ui->checkBox_Res_GridVisParam_Labels->isChecked(),
                    ui->spinBox_Res_GridVisParam_Thickness_Label->value(),
                    ui->doubleSpinBox_Res_GridVisParam_Label_Scaling->value()),
                "Update_Result_GraphicsVectors",
                "Draw_CircleField");
        }
        else
        {
            ERR(D_Img_Proc::Draw_VectorField(
                    &MA_tmp_overlay_field,
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
        }

        //add overlay to image
        ERR(D_Img_Proc::OverlayOverwrite(
                &MA_Result,
                &MA_TimeProject_Show,
                &MA_tmp_overlay_field,
                0, 255, 0,
                1.0,
                1.0),
            "Update_Result_GraphicsVectors",
            "OverlayOverwrite - Vectorfield");
    }
    else
    {
        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: angular shifts

        //------------------------ lines ---------------------------

        //draw lines from grid cell centers to vortex center
        Mat MA_tmp_overlay_lines = Mat::zeros(MA_TimeProject_Show.size(), CV_8UC1);
        for(size_t gx = 0; gx < nx; gx++)
        {
            for(size_t gy = 0; gy < ny; gy++)
            {
                if(vv_XY_DetectionCounts[gx][gy] > 0)
                {
                    //grid cell center
                    D_Geo_Point_2D P_GridCellCenter(
                                ((gx + 0.5) / static_cast<double>(nx)) * spatial_roi_width,
                                ((gy + 0.5) / static_cast<double>(ny)) * spatial_roi_height);

                    //line from center of grid cell to center of vortex
                    D_Geo_Line_2D L_GridCenter_VortexCenter(P_GridCellCenter, P_VortexCenter);

                    //check, if vortex center is in image or not
                    if(P_VortexCenter.in_rect(&MA_tmp_overlay_lines))
                    {
                        //.................. vortex center in image ..............................

                        ERR(D_Img_Proc::Draw_Line(
                                &MA_tmp_overlay_lines,
                                P_GridCellCenter.x(),
                                P_GridCellCenter.y(),
                                P_VortexCenter.x(),
                                P_VortexCenter.y(),
                                max(2.0 , ui->spinBox_Res_VectorFieldParam_Thickness_Vector->value() / 2.0),
                                255),
                            "Update_Result_GraphicsVortexCenter",
                            "Draw_Line - center vortex to center grid cell");
                    }
                    else
                    {
                        //.................... vortex center out of image ...........................

                        //calc 2 points on line that intersect image border
                        D_Geo_Point_2D P1_Border, P2_Border;
                        if(L_GridCenter_VortexCenter.intersection_rect(&P1_Border, &P2_Border, &MA_tmp_overlay_lines))
                        {
                            //find point on border between grid cell center and vortex center
                            double dist_sum_p1 = P1_Border.distance(P_VortexCenter) + P1_Border.distance(P_GridCellCenter);
                            double dist_sum_p2 = P2_Border.distance(P_VortexCenter) + P2_Border.distance(P_GridCellCenter);
                            D_Geo_Point_2D P_Border2Use = dist_sum_p1 < dist_sum_p2 ? P1_Border : P2_Border;

                            //draw line
                            ERR(D_Img_Proc::Draw_Line(
                                    &MA_tmp_overlay_lines,
                                    P_GridCellCenter.x(),
                                    P_GridCellCenter.y(),
                                    P_Border2Use.x(),
                                    P_Border2Use.y(),
                                    max(2.0 , ui->spinBox_Res_VectorFieldParam_Thickness_Vector->value() / 2.0),
                                    255),
                                "Update_Result_GraphicsVortexCenter",
                                "Draw_Line - center vortex to center grid cell");
                        }
                    }
                }
            }
        }

        //add line overlay to image
        Mat MA_tmp_LinesAdded;
        ERR(D_Img_Proc::OverlayOverwrite(
                &MA_tmp_LinesAdded,
                &MA_TimeProject_Show,
                &MA_tmp_overlay_lines,
                0, 0, 255,
                1.0,
                1.0),
            "Update_Result_GraphicsVectors",
            "OverlayOverwrite - Lines");

        //------------------------ arcs ---------------------------

        //radii of arcs
        double arc_radius = (min(spatial_roi_width / nx, spatial_roi_height / ny) / 3.0) * radius_scale;
        vector<vector<double>> vv_arc_radii(nx, vector<double>(ny, arc_radius));

        //draw arc field
        ERR(D_Img_Proc::Draw_ArcField(
                &MA_tmp_overlay_field,
                vv_XY_LengthValues,
                vv_XY_LengthErrors,
                vv_XY_AngleValues,
                vv_arc_radii,
                vv_XY_DetectionCounts,
                255,
                ui->spinBox_Res_VectorFieldParam_Thickness_Vector->value(),
                ui->spinBox_Res_VectorFieldParam_KindeySteps->value(),
                ui->checkBox_Res_GridVisParam_Grid->isChecked(),
                ui->spinBox_Res_GridVisParam_Thickness_Grid->value(),
                ui->checkBox_Res_GridVisParam_Labels->isChecked(),
                ui->spinBox_Res_GridVisParam_Thickness_Label->value(),
                ui->doubleSpinBox_Res_GridVisParam_Label_Scaling->value()),
            "Update_Result_GraphicsVectors",
            "Draw_ArcField");

        //add overlay to image
        ERR(D_Img_Proc::OverlayOverwrite(
                &MA_Result,
                &MA_tmp_LinesAdded,
                &MA_tmp_overlay_field,
                0, 255, 0,
                1.0,
                1.0),
            "Update_Result_GraphicsVectors",
            "OverlayOverwrite - Vectorfield");
        MA_tmp_LinesAdded.release();
    }




    //clear
    MA_tmp_overlay_field.release();
    vv_XY_LengthValues.clear();
    vv_XY_LengthErrors.clear();
    vv_XY_AngleValues.clear();
    vv_XY_AngleErrors.clear();

    //show result
    Update_Image_Results();



    qDebug() << "Update_Result_StatFilter" << "finish";
}

D_Geo_Point_2D D_MAKRO_CiliaSphereTracker::CalcVortexCenter(D_Geo_LineSet_2D *lines, double *deviation, vector<double> *v_residuals_all, vector<double> *v_residuals_used, double well_diameter_px, Point P_VideoOffset, int t_start, int t_end)
{
    //qDebug() << "D_MAKRO_CiliaSphereTracker::CalcVortexCenter" << "check";

    //Check requirements
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_ImgProcUp2date || !state_GridSamplingSplit || !state_VidProcUp2date)
    {
        qDebug() << "CalcVortexCenter" << "requirements not met";
        return D_Geo_Point_2D(0, 0, 0);
    }

    //qDebug() << "D_MAKRO_CiliaSphereTracker::CalcVortexCenter" << "start";

    //time window
    if(t_end >= frame_end - frame_start_ana)        t_end   = frame_end - frame_start_ana;
    if(t_start >= frame_end - frame_start_ana - 1)  t_start = frame_end - frame_start_ana - 1;
    if(t_start < 0)                                 t_start = 0;
    if(t_end < 0)                                   t_end   = frame_end - frame_start_ana;
    //qDebug() << "Update_Result_GraphicsVectors" << "it_start" << it_start << "it_end" << it_end;

    //well size
    int well_radius_px = well_diameter_px / 2.0;

    //----------------------------------------------------------------- calculate angle field -----------------------------------------

    //lines normal to movement vectors are stored in *lines

    //grid size
    size_t nx = vvvv_XYFrmObjShifts.size();
    size_t ny = vvvv_XYFrmObjShifts[0].size();

    //loop grid cells
    for(size_t gx = 0; gx < nx; gx++)
    {
        for(size_t gy = 0; gy < ny; gy++)
        {
            //calc mean angle -----------------------------

            //group all needed elements in 1D container
            vector<double> v_AnglesInCell;

            //detections in grid cell all times
            size_t no_all_times = 0;

            //loop time window
            for(int t = t_start; t < t_end; t++)
            {
                //number of objects in cell and frame
                size_t no_in_frame = vvvv_XYFrmObjShifts[gx][gy][t].size();
                no_all_times += no_in_frame;

                //loop, and extract angles
                for(size_t obj = 0; obj < no_in_frame; obj++)
                    v_AnglesInCell.push_back(vvvv_XYFrmObjAngles[gx][gy][t][obj]);
            }

            //only use this grid cell if there is at least one detection
            if(no_all_times > 0)
            {
                //calc stats
                vector<double> v_Angles_Stats(c_STAT_CIRC_NUMBER_OF);
                D_Stat::Calc_Stats_Circ_Rad(
                            &v_Angles_Stats,
                            v_AnglesInCell);

                //add line -----------------------------

                //grid cell center is support vector
                D_Geo_Point_2D P_support(
                            P_VideoOffset.x + ((gx + 0.5) / static_cast<double>(nx)) * spatial_roi_width,
                            P_VideoOffset.y + ((gy + 0.5) / static_cast<double>(ny)) * spatial_roi_height);

                //direction vector is 90° to measured direction of movement
                double line_angle = v_Angles_Stats[c_STAT_CIRC_MEAN_ANG] - PI_0_5; //-angle because some orientation incoherencies

                //line that goes approx through vortex center
                lines->add_line_point_angle(P_support, line_angle);
            }
        }
    }

    //----------------------------------------------------------------- calc center -----------------------------------------

    //options
    bool clustering = false; //ui->checkBox_Res_VortexCenter_kMeans->isChecked();
    bool ransac = ui->checkBox_Res_VortexCenter_Ransac->isChecked();

    //approx intersection of line set is calculated

    //prepare containers
    *deviation = INFINITY;
    D_Geo_Point_2D P_center(well_radius_px , well_radius_px);//init in center of well
    D_Geo_PointSet_2D PS_IntersectionsUsed;

    //calc all intersections
    D_Geo_PointSet_2D PS_IntersectionsAll = lines->intersections_pairwise();

    //choose method and calc center, std and residuals
    if(!clustering && !ransac)
    {
        P_center = lines->intersection(
                    deviation,
                    v_residuals_used);
        PS_IntersectionsUsed = PS_IntersectionsAll;
        *v_residuals_all = *v_residuals_used;
    }
    else if(!clustering && ransac)
    {
        P_center = lines->intersection_ransac(
                    deviation,
                    &PS_IntersectionsUsed,
                    v_residuals_used,
                    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->value() / 100.0,
                    ui->spinBox_Res_VortexCenter_RansacIterations->value(),
                    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->currentIndex() == 0);

        //calc all distances to center
        size_t n_intersections_all = PS_IntersectionsAll.size();
        v_residuals_all->resize(n_intersections_all);
        for(size_t i = 0; i < n_intersections_all; i++)
        {
            double dx = P_center.x() - PS_IntersectionsAll.point(i).x();
            double dy = P_center.y() - PS_IntersectionsAll.point(i).y();
            (*v_residuals_all)[i] = sqrt(dx * dx + dy * dy);
        }
    }
    else
    {
        ERR(ER_other, "CalcVortexCenter", "not implemented yet");
        return D_Geo_Point_2D(0, 0, 0);
    }

    //return vortex center
    //qDebug() << "D_MAKRO_CiliaSphereTracker::CalcVortexCenter" << "end";
    return P_center;
}

void D_MAKRO_CiliaSphereTracker::Update_Result_GraphicsVortexCenter()
{
    //qDebug() << "D_MAKRO_CiliaSphereTracker::Update_Result_GraphicsVortexCenter" << "check";

    //Check requirements
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_ImgProcUp2date || !state_GridSamplingSplit || !state_VidProcUp2date)
    {
        //qDebug() << "Update_Result_GraphicsVortexCenter" << "requirements not met";
        return;
    }

    //qDebug() << "D_MAKRO_CiliaSphereTracker::Update_Result_GraphicsVortexCenter" << "start";

    //scaled unit conversions
    double res_scale = ui->doubleSpinBox_Res_VortexCenter_Resolution_Rel->value() / 100.0;
    //double conv_scaled_um2px = conv_um2px * res_scale;
    //double conv_scaled_px2um = 1.0 / conv_scaled_um2px;
    //double conv_scaled_px2mm = conv_scaled_px2um * 1000;


    //----------------------------------------------------------------- prepare background -----------------------------------------

    //well size
    double well_diameter_um = ui->doubleSpinBox_Res_VortexCenter_WellDiameter->value();
    int well_diameter_px = well_diameter_um * conv_um2px;
    int well_diameter_px_scaled = well_diameter_px * res_scale;
    int well_radius_px = well_diameter_px / 2.0;
    int well_radius_px_scaled = well_diameter_px_scaled / 2.0;
    //create well image (white background)
    Mat MA_tmp_Well = Mat(
                well_diameter_px_scaled,
                well_diameter_px_scaled,
                CV_8UC3,
                Scalar(255, 255, 255));
    //draw well (black)
    ERR(D_Img_Proc::Draw_Dot(
            &MA_tmp_Well,
            well_radius_px_scaled, well_radius_px_scaled,
            well_diameter_px_scaled,
            0, 0, 0),
        "Update_Result_GraphicsVortexCenter",
        "Draw_Circle - Well diameter");

    //calc pos in well
    double pos_offset_x_px = spatial_roi_width / 2.0;
    double pos_offset_y_px = spatial_roi_height / 2.0;
    double pos_in_well_rel = ui->doubleSpinBox_Res_VortexCenter_RelPos_H_Use->value() / 100;
    Point P_VideoOffset(
                pos_in_well_rel * well_diameter_px - pos_offset_x_px,
                well_radius_px - pos_offset_y_px);

    /*
    //make sure area is in well
    P_VideoOffset.x = max(P_VideoOffset.x, 0);
    P_VideoOffset.y = max(P_VideoOffset.y, 0);
    P_VideoOffset.x = min(P_VideoOffset.x, static_cast<int>(well_diameter_px - spatial_roi_width - 1));
    P_VideoOffset.y = min(P_VideoOffset.y, static_cast<int>(well_diameter_px - spatial_roi_height - 1));
    */

    //projection graphics as basis for video area
    Update_Result_GraphicsTimeProjectSum();

    //----------------------------------------------------------------- calculate and show -----------------------------------------

    int thickness = ui->spinBox_Res_VortexCenter_Thickness->value();

    //scale offset
    D_Geo_Point_2D P_Offset_scaled = D_Geo_Point_2D(P_VideoOffset.x * res_scale, P_VideoOffset.y * res_scale);

    //mode
    int mode = ui->checkBox_Res_VortexCenter_MovingAverage->checkState();

    if(mode == 0 || mode == 1)                //.................................................................................................... full video
    {
        //grid size
        size_t nx = vvvv_XYFrmObjShifts.size();
        size_t ny = vvvv_XYFrmObjShifts[0].size();

        //-------------------- calc ---------------------

        //calc normal lines and center lines
        double center_deviation = INFINITY;
        vector<double> v_residuals_all;
        vector<double> v_residuals_used;
        D_Geo_LineSet_2D Lines_NormalsOfMovementVectors;
        D_Geo_Point_2D P_Center = CalcVortexCenter(
                    &Lines_NormalsOfMovementVectors,
                    &center_deviation,
                    &v_residuals_all,
                    &v_residuals_used,
                    well_diameter_px,
                    P_VideoOffset,
                    0, -1); //full video

        //return if center is vanishing (would lead to infinite distances)
        if(P_Center.vanishing())
            return;

        //save center for more calculations
        P_VortexCenter = P_Center.add_inhomo(D_Geo_Point_2D(-P_VideoOffset.x, -P_VideoOffset.y));
        v_VortexCenterResiduals_All = v_residuals_all;
        v_VortexCenterResiduals_Used = v_residuals_used;
        state_vortex_center_calced = true;

        //scale
        D_Geo_Point_2D P_Center_scaled = P_Center.scale(res_scale);
        double center_deviation_scaled = center_deviation * res_scale;

        //get center
        int center_x_scaled = P_Center_scaled.x();
        int center_y_scaled = P_Center_scaled.y();

        //check center position in img?
        bool x_ok = center_x_scaled >= 0 && center_x_scaled < well_diameter_px_scaled;
        bool y_ok = center_y_scaled >= 0 && center_y_scaled < well_diameter_px_scaled;

        //-------------------- draw ---------------------

        //deviation dot
        if(x_ok && y_ok)
            D_Img_Proc::Draw_Dot(
                    &MA_tmp_Well,
                    P_Center_scaled.x(),
                    P_Center_scaled.y(),
                    center_deviation_scaled * 2,
                    100, 0, 100);

        //draw well as black circle again (in case deviaition is so huge that well can't be seen anymore)
        D_Img_Proc::Draw_Circle(
                &MA_tmp_Well,
                well_radius_px_scaled, well_radius_px_scaled,
                well_radius_px_scaled,
                0, 0, 0,
                thickness * 3);

        //insert video backgound graphic
        D_Img_Proc::Insert(
                    &MA_tmp_Well,
                    &MA_TimeProject_Show,
                    P_Offset_scaled.x(),
                    P_Offset_scaled.y(),
                    res_scale);

        //normal lines
        for(size_t i = 0; i < Lines_NormalsOfMovementVectors.size(); i++)
        {
            D_Geo_Point_2D P1, P2;
            if(Lines_NormalsOfMovementVectors.line(i).intersection_rect(&P1, &P2, 0, well_diameter_px, 0, well_diameter_px))
                D_Img_Proc::Draw_Line(
                        &MA_tmp_Well,
                        P1.scale(res_scale).CV_Point(),
                        P2.scale(res_scale).CV_Point(),
                        max(2.0 , ceil(thickness / 4.0)),
                        128, 0, 128);
        }

        //anchors of normal lines
        for(size_t gx = 0; gx < nx; gx++)
            for(size_t gy = 0; gy < ny; gy++)
                D_Img_Proc::Draw_Dot(
                        &MA_tmp_Well,
                        P_Offset_scaled.x() + ((gx + 0.5) / static_cast<double>(nx)) * spatial_roi_width * res_scale,
                        P_Offset_scaled.y() + ((gy + 0.5) / static_cast<double>(ny)) * spatial_roi_height * res_scale,
                        thickness * 2,
                        128, 0, 128);

        //center y
        if(y_ok)
            D_Img_Proc::Draw_Line(
                    &MA_tmp_Well,
                    0, center_y_scaled,
                    well_diameter_px_scaled - 1, center_y_scaled,
                    thickness,
                    255, 0, 255);

        //center x
        if(x_ok)
            D_Img_Proc::Draw_Line(
                    &MA_tmp_Well,
                    center_x_scaled, 0,
                    center_x_scaled, well_diameter_px_scaled - 1,
                    thickness,
                    255, 0, 255);

        //center dot and deviation circle
        if(x_ok && y_ok)
        {
            D_Img_Proc::Draw_Dot(
                    &MA_tmp_Well,
                    center_x_scaled, center_y_scaled,
                    thickness * 5,
                    255, 0, 255);

            D_Img_Proc::Draw_Circle(
                    &MA_tmp_Well,
                    center_x_scaled, center_y_scaled,
                    center_deviation_scaled,
                    255, 0, 255,
                    thickness);
        }
    }

    if(mode == 2 || mode == 1)    //.................................................................. moving average
    {
        //-------------------- calc ---------------------

        //make sure time window is valid
        double t_window_sec = ui->doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec->value();
        ui->spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm->blockSignals(true);
        ui->spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm->setValue(t_window_sec / VS_InputVideo.get_frame_2_timeSec());
        ui->spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm->blockSignals(false);
        double t_window_frm = ui->spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm->value();
        ui->doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec->blockSignals(true);
        ui->doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec->setValue(t_window_frm * VS_InputVideo.get_frame_2_timeSec());
        ui->doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec->blockSignals(false);
        t_window_sec = ui->doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec->value();

        //looping params
        size_t t_start_frm = 0;
        size_t t_end_frm = t_window_frm;
        size_t t_max_frm = frame_end - frame_start_ana;
        size_t t_setp_frm = max(1.0, t_window_frm / 10.0);

        //calc centers over time
        vector<D_Geo_Point_2D> v_CentersScaled;
        vector<double> v_DeviationsScaled;
        while(t_end_frm < t_max_frm)
        {
            //alloc results
            double center_deviation = INFINITY;
            D_Geo_LineSet_2D Lines_NormalsOfMovementVectors;
            vector<double> v_residuals_all;
            vector<double> v_residuals_used;

            //calc centers
            D_Geo_Point_2D P_Center = CalcVortexCenter(
                        &Lines_NormalsOfMovementVectors,
                        &center_deviation,
                        &v_residuals_all,
                        &v_residuals_used,
                        well_diameter_px,
                        P_VideoOffset,
                        t_start_frm, t_end_frm);

            //append results container
            v_CentersScaled.push_back(P_Center.scale(res_scale));
            v_DeviationsScaled.push_back(center_deviation * res_scale);

            //increment by time step
            t_start_frm += t_setp_frm;
            t_end_frm += t_setp_frm;
        }


        //-------------------- draw ---------------------


        //insert video background graphic
        if(mode == 2)
            D_Img_Proc::Insert(
                        &MA_tmp_Well,
                        &MA_TimeProject_Show,
                        P_Offset_scaled.x(),
                        P_Offset_scaled.y(),
                        res_scale);

        size_t n = v_CentersScaled.size();
        D_Geo_Point_2D P_last;
        for(size_t i = 0; i < n; i++)
        {
            //calc color
            double i_rel = n > 1 ? static_cast<double>(i) / (n - 1) : 0;
            QColor color;
            color.setHsv((1 - i_rel) * 240, 255, 255);

            //get center
            D_Geo_Point_2D P_Center_scaled = v_CentersScaled[i];

            //draw center as dot
            if(P_Center_scaled.in_rect(0, well_diameter_px_scaled, 0, well_diameter_px_scaled))
            {
                D_Img_Proc::Draw_Dot(
                        &MA_tmp_Well,
                        P_Center_scaled.x(), P_Center_scaled.y(),
                        thickness * 3,
                        color.red(), color.green(), color.blue());
            }

            //draw center connection as line for later centers
            if(i >= 1)
            {
                D_Geo_Line_2D L_CenterConnect(P_Center_scaled, P_last);
                D_Geo_Point_2D P1;
                D_Geo_Point_2D P2;
                if(L_CenterConnect.intersection_rect(&P1, &P2, 0, well_diameter_px_scaled, 0, well_diameter_px_scaled))
                    D_Img_Proc::Draw_Line(
                            &MA_tmp_Well,
                            P_Center_scaled.x(), P_Center_scaled.y(),
                            P_last.x(), P_last.y(),
                            1,
                            color.red(), color.green(), color.blue());
            }

            //save current center as last center for next center
            P_last = P_Center_scaled;
        }
    }

    //show result & release tmp mats
    MA_Result = MA_tmp_Well.clone();
    MA_tmp_Well.release();
    Update_Image_Results();

    //qDebug() << "D_MAKRO_CiliaSphereTracker::Update_Result_GraphicsVortexCenter" << "end";
}

void D_MAKRO_CiliaSphereTracker::Update_Result_SpeedStatCustom()
{
    bool reqirements_ok = true;
    int shift_type = ui->comboBox_Res_SpeedCustom_ShiftType->currentIndex();

    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_GridSamplingSplit || !state_VidProcUp2date)
        reqirements_ok = false;

    //check stat summary
    if(reqirements_ok)
    {
        if(!state_StatSummaryCalced)
            Data_CalcFullVideoStats();
        if(!state_StatSummaryCalced)
            reqirements_ok = false;
    }

    //check center calc
    if(reqirements_ok && shift_type == SHIFT_TYPE_ANGULAR)
    {
        if(!state_vortex_center_calced || !state_StatSummaryCalced_angularSpeed)
            Data_CalcFullVideoStats_AngularSpeed();
        if(!state_vortex_center_calced || !state_StatSummaryCalced_angularSpeed)
            reqirements_ok = false;
    }

    if(!reqirements_ok)
    {
        D_Plot::Plot_Empty(pChartView_Results_Line, "Reqirements for Update_Result_SpeedStatCustom failed");
        return;
    }

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
                            //scale and export data
                            if(shift_type == SHIFT_TYPE_LINEAR)
                            {
                                //linear shift
                                v_Shifts_InCellInTimeWindow.push_back(vv_FrmObjShifts[it_cur][obj] * conv_perFrame2perSecond * conv_px2um);
                            }
                            else
                            {
                                //angular shift

                                //dist to center
                                double dx = vv_FrmObjPositions[it_cur][obj].x - P_VortexCenter.x();
                                double dy = vv_FrmObjPositions[it_cur][obj].y - P_VortexCenter.y();
                                double dist = sqrt(dx * dx + dy * dy);

                                double shift_linear = vv_FrmObjShifts[it_cur][obj];

                                v_Shifts_InCellInTimeWindow.push_back(dist > 0 ? (shift_linear / dist) * Rad2Grad : 0);
                            }
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
    {
        if(shift_type == SHIFT_TYPE_LINEAR)
            pChartView_Results_Line->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_T_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_T_max->value());
        else
            pChartView_Results_Line->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_T_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_T_max->value());
    }
    else if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_VIDEO_LENGTH)
    {
        if(shift_type == SHIFT_TYPE_LINEAR)
            pChartView_Results_Line->chart()->axes(Qt::Horizontal).back()->setRange(0, VS_InputVideo.get_DurationSec());
        else
            pChartView_Results_Line->chart()->axes(Qt::Horizontal).back()->setRange(0, VS_InputVideo.get_DurationSec());
    }

    if(ui->checkBox_Res_PlotLine_FixRange_S->isChecked())
    {
        if(shift_type == SHIFT_TYPE_LINEAR)
            pChartView_Results_Line->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->value());
        else
            pChartView_Results_Line->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->value());
    }
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
    bool reqirements_ok = true;
    int shift_type = ui->comboBox_Res_SpeedCustom_ShiftType->currentIndex();

    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_GridSamplingSplit || !state_VidProcUp2date)
        reqirements_ok = false;

    //check stat summary
    if(reqirements_ok)
    {
        if(!state_StatSummaryCalced)
            Data_CalcFullVideoStats();
        if(!state_StatSummaryCalced)
            reqirements_ok = false;
    }

    //check center calc
    if(reqirements_ok && shift_type == SHIFT_TYPE_ANGULAR)
    {
        if(!state_vortex_center_calced || !state_StatSummaryCalced_angularSpeed)
            Data_CalcFullVideoStats_AngularSpeed();
        if(!state_vortex_center_calced || !state_StatSummaryCalced_angularSpeed)
            reqirements_ok = false;
    }

    //Check requirements
    if(!reqirements_ok)
    {
        D_Plot::Plot_Empty(pChartView_Results_Line, "Reqirements for Update_Result_SpeedAnalysis failed");
        D_Plot::Plot_Empty(pChartView_Results_Poincare, "Reqirements for Update_Result_SpeedAnalysis failed");
        Table_Results.clear_data();

        if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW1)
        {
            D_Plot::Plot_Empty(pChartView_Results_Overview1_SpeedLine, "Reqirements for Update_Result_SpeedAnalysis failed");
            D_Plot::Plot_Empty(pChartView_Results_Overview1_SpeedPoincare, "Reqirements for Update_Result_SpeedAnalysis failed");
        }
        if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW2)
        {
            if(shift_type == SHIFT_TYPE_LINEAR)
            {
                D_Plot::Plot_Empty(pChartView_Results_Overview2_SpeedLinear_Line, "Reqirements for Update_Result_SpeedAnalysis failed");
            }
            else
            {
                D_Plot::Plot_Empty(pChartView_Results_Overview2_SpeedAngular_Line, "Reqirements for Update_Result_SpeedAnalysis failed");
            }
        }

        return;
    }

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
                //scale and export data
                if(shift_type == SHIFT_TYPE_LINEAR)
                {
                    //linear shift
                    v_Shifts_InTimeWindow.push_back(vv_FrmObjShifts[it_cur][obj] * conv_perFrame2perSecond * conv_px2um);
                }
                else
                {
                    //angular shift

                    //dist to center
                    double dx = vv_FrmObjPositions[it_cur][obj].x - P_VortexCenter.x();
                    double dy = vv_FrmObjPositions[it_cur][obj].y - P_VortexCenter.y();
                    double dist = sqrt(dx * dx + dy * dy);

                    double shift_linear = vv_FrmObjShifts[it_cur][obj];

                    v_Shifts_InTimeWindow.push_back(dist > 0 ? (shift_linear / dist) * Rad2Grad : 0);
                }
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


    //Plot title
    QString QS_Title_Line = shift_type == SHIFT_TYPE_LINEAR ? "<b>Linear speed vs Time</b>" : "<b>Angular speed vs Time</b>";
    QS_Title_Line.append("<br>" + ui->comboBox_Data_Videos->currentText() +
                    "<br>"
                    "<br>Moving average over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + "s"
                    "<br>Considered time windows with at least one detetction in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of frames");

    QString QS_Title_Poincare = shift_type == SHIFT_TYPE_LINEAR ? "<b>Linear speed poincare</b>" : "<b>Angular speed poincare</b>";
    QS_Title_Poincare.append("<br>" + ui->comboBox_Data_Videos->currentText() +
                             "<br>"
                             "<br>Moving average over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + "s"
                             "<br>Considered time windows with at least one detetction in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of frames");


    //Speed unit
    QString QS_Unit = shift_type == SHIFT_TYPE_LINEAR ? "(um/s)" : "(°/s)";

    if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW1)
    {
        //Plot Line
        ER = D_Plot::Plot_Line_XY_Multi(
                    pChartView_Results_Overview1_SpeedLine,
                    v_ValuesX,
                    vv_ValuesY,
                    QS_Title_Line,
                    QSL_SeriesNames,
                    "Time/s",
                    "Stats of speed /" + QS_Unit,
                    true,
                    true,
                    true,
                    Qt::AlignTop);

        //Plot Poincare
        ER = D_Plot::Plot_Poincare_XY_Single(
                    pChartView_Results_Overview1_SpeedPoincare,
                    vv_ValuesY[PLOT_SUMMARY_MID],
                    QS_Title_Poincare,
                    QSL_SeriesNames[PLOT_SUMMARY_MID],
                    QSL_SeriesNames[PLOT_SUMMARY_MID] + " of Speed /" + QS_Unit + " at t",
                    QSL_SeriesNames[PLOT_SUMMARY_MID] + "<br>of Speed /" + QS_Unit + "<br>at t+" + QString::number(ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->value()) + "s",
                    ui->spinBox_Res_PlotPoincare_Shift_Frames->value(),
                    true,
                    true,
                    true,
                    Qt::AlignTop);

        pChartView_Results_Overview1_SpeedPoincare->setFixedSize(pChartView_Results_Overview1_SpeedPoincare->height(), pChartView_Results_Overview1_SpeedPoincare->height());
    }
    else if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW2)
    {
        if(shift_type == SHIFT_TYPE_LINEAR)
            ER = D_Plot::Plot_Line_XY_Multi(
                        pChartView_Results_Overview2_SpeedLinear_Line,
                        v_ValuesX,
                        vv_ValuesY,
                        QS_Title_Line,
                        QSL_SeriesNames,
                        "Time /s",
                        "Stats of linear speed /" + QS_Unit,
                        true,
                        true,
                        true,
                        Qt::AlignTop);
        else
            ER = D_Plot::Plot_Line_XY_Multi(
                        pChartView_Results_Overview2_SpeedAngular_Line,
                        v_ValuesX,
                        vv_ValuesY,
                        QS_Title_Line,
                        QSL_SeriesNames,
                        "Time /s",
                        "Stats of linear speed /" + QS_Unit,
                        true,
                        true,
                        true,
                        Qt::AlignTop);
    }
    else
    {
        //Plot Line
        ER = D_Plot::Plot_Line_XY_Multi(
                    pChartView_Results_Line,
                    v_ValuesX,
                    vv_ValuesY,
                    QS_Title_Line,
                    QSL_SeriesNames,
                    "Time/s",
                    "Stats of speed /" + QS_Unit,
                    true,
                    true,
                    true,
                    Qt::AlignTop);

        //Plot Poincare
        ER = D_Plot::Plot_Poincare_XY_Single(
                    pChartView_Results_Poincare,
                    vv_ValuesY[PLOT_SUMMARY_MID],
                    QS_Title_Poincare,
                    QSL_SeriesNames[PLOT_SUMMARY_MID],
                    QSL_SeriesNames[PLOT_SUMMARY_MID] + " of Speed /" + QS_Unit + " at t",
                    QSL_SeriesNames[PLOT_SUMMARY_MID] + " of Speed /" + QS_Unit + " at t+" + QString::number(ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->value()) + "s",
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

        if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW1)
        {
            D_Plot::Plot_Empty(pChartView_Results_Overview1_SpeedLine, "Calc worked, Plot failed");
            D_Plot::Plot_Empty(pChartView_Results_Overview1_SpeedPoincare, "Calc worked, Plot failed");
        }

        if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW2)
        {
            if(shift_type == SHIFT_TYPE_LINEAR)
                D_Plot::Plot_Empty(pChartView_Results_Overview2_SpeedLinear_Line, "Calc worked, Plot failed");
            else
                D_Plot::Plot_Empty(pChartView_Results_Overview2_SpeedAngular_Line, "Calc worked, Plot failed");
        }

        return;
    }

    //cosmetic stuff for the plot
    if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW1)
    {
        if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_CUSTOM)
            pChartView_Results_Overview1_SpeedLine->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_T_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_T_max->value());
        else if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_VIDEO_LENGTH)
            pChartView_Results_Overview1_SpeedLine->chart()->axes(Qt::Horizontal).back()->setRange(0, VS_InputVideo.get_DurationSec());

        if(ui->checkBox_Res_PlotLine_FixRange_S->isChecked())
        {
            if(shift_type == SHIFT_TYPE_LINEAR)
            {
                pChartView_Results_Overview1_SpeedLine->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->value());
                pChartView_Results_Overview1_SpeedPoincare->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->value());
                pChartView_Results_Overview1_SpeedPoincare->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->value());
            }
            else
            {
                pChartView_Results_Overview1_SpeedLine->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->value());
                pChartView_Results_Overview1_SpeedPoincare->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->value());
                pChartView_Results_Overview1_SpeedPoincare->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->value());
            }
        }
    }
    else if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW2)
    {
        if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_CUSTOM)
        {
            if(shift_type == SHIFT_TYPE_LINEAR)
                pChartView_Results_Overview2_SpeedLinear_Line->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_T_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_T_max->value());
            else
                pChartView_Results_Overview2_SpeedAngular_Line->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_T_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_T_max->value());
        }
        else if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_VIDEO_LENGTH)
        {
            if(shift_type == SHIFT_TYPE_LINEAR)
                pChartView_Results_Overview2_SpeedLinear_Line->chart()->axes(Qt::Horizontal).back()->setRange(0, VS_InputVideo.get_DurationSec());
            else
                pChartView_Results_Overview2_SpeedAngular_Line->chart()->axes(Qt::Horizontal).back()->setRange(0, VS_InputVideo.get_DurationSec());
        }

        if(ui->checkBox_Res_PlotLine_FixRange_S->isChecked())
        {
            if(shift_type == SHIFT_TYPE_LINEAR)
                pChartView_Results_Overview2_SpeedLinear_Line->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->value());
            else
                pChartView_Results_Overview2_SpeedAngular_Line->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->value());
        }
    }
    else
    {
        if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_CUSTOM)
        {
            pChartView_Results_Line->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_T_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_T_max->value());
        }
        else if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_VIDEO_LENGTH)
        {
            pChartView_Results_Line->chart()->axes(Qt::Horizontal).back()->setRange(0, VS_InputVideo.get_DurationSec());
        }

        if(ui->checkBox_Res_PlotLine_FixRange_S->isChecked())
        {
            if(shift_type == SHIFT_TYPE_LINEAR)
            {
                pChartView_Results_Line->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->value());
                pChartView_Results_Poincare->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->value());
                pChartView_Results_Poincare->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->value());
            }
            else
            {
                pChartView_Results_Line->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->value());
                pChartView_Results_Poincare->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->value());
                pChartView_Results_Poincare->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->value());
            }

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

        if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW1)
        {
            D_Plot::Plot_Empty(pChartView_Results_Overview1_AngleLine, "Reqirements for Update_Result_AngleAnalysis failed");
            D_Plot::Plot_Empty(pChartView_Results_Overview1_AnglePoincare, "Reqirements for Update_Result_AngleAnalysis failed");
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

    if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW1)
    {
        //Plot Line
        ER = D_Plot::Plot_Line_XY_Multi(
                    pChartView_Results_Overview1_AngleLine,
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
                    pChartView_Results_Overview1_AnglePoincare,
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

        pChartView_Results_Overview1_AnglePoincare->setFixedSize(pChartView_Results_Overview1_AnglePoincare->height(), pChartView_Results_Overview1_AnglePoincare->height());
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

        if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW1)
        {
            D_Plot::Plot_Empty(pChartView_Results_Overview1_AngleLine, "Calc worked, Plot failed");
            D_Plot::Plot_Empty(pChartView_Results_Overview1_AnglePoincare, "Calc worked, Plot failed");
        }

        return;
    }


    //cosmetic stuff for the plot
    if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW1)
    {
        if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_CUSTOM)
            pChartView_Results_Overview1_AngleLine->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_T_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_T_max->value());
        else if(ui->comboBox_Res_PlotLine_FixRange_T->currentIndex() == PLOT_TIME_VIDEO_LENGTH)
            pChartView_Results_Overview1_AngleLine->chart()->axes(Qt::Horizontal).back()->setRange(0, VS_InputVideo.get_DurationSec());

        if(ui->checkBox_Res_PlotLine_FixRange_A->isChecked())
        {
            pChartView_Results_Overview1_AngleLine->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_A_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_A_max->value());
            pChartView_Results_Overview1_AnglePoincare->chart()->axes(Qt::Vertical).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_A_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_A_max->value());
            pChartView_Results_Overview1_AnglePoincare->chart()->axes(Qt::Horizontal).back()->setRange(ui->doubleSpinBox_Res_PlotLine_FixRange_A_min->value(), ui->doubleSpinBox_Res_PlotLine_FixRange_A_max->value());
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

void D_MAKRO_CiliaSphereTracker::Update_Result_Histogram()
{
    bool reqirements_ok = true;
    int mode = ui->comboBox_Res_Histo_Type->currentIndex();

    //Check general requirements
    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected || !state_VidProcUp2date)
        reqirements_ok = false;

    //check stat summary
    if(reqirements_ok)
    {
        if(!state_StatSummaryCalced)
            Data_CalcFullVideoStats();
        if(!state_StatSummaryCalced)
            reqirements_ok = false;
    }

    //check center calc
    if(reqirements_ok)
    {
        if(!state_vortex_center_calced || !state_StatSummaryCalced_angularSpeed)
            Data_CalcFullVideoStats_AngularSpeed();
        if(!state_vortex_center_calced || !state_StatSummaryCalced_angularSpeed)
            reqirements_ok = false;
    }

    //Check requirements
    if(!reqirements_ok)
    {
        D_Plot::Plot_Empty(pChartView_Results_Line, "Reqirements for Update_Result_Histogram failed");
        D_Plot::Plot_Empty(pChartView_Results_Poincare, "Reqirements for Update_Result_Histogram failed");
        Table_Results.clear_data();

        if(ui->comboBox_Res_Type->currentIndex() == RES_OVERVIEW2)
        {
            switch (mode) {

            case HIST_LINEAR_SPEED:
            {
                D_Plot::Plot_Empty(pChartView_Results_Overview2_SpeedLinear_Hist, "Reqirements for Update_Result_Histogram failed");
                D_Plot::Plot_Empty(pChartView_Results_Overview2_SpeedLinear_Hist, "Reqirements for Update_Result_Histogram failed");
            }
                break;

            case HIST_ANGULAR_SPEED:
            {
                D_Plot::Plot_Empty(pChartView_Results_Overview2_SpeedAngular_Hist, "Reqirements for Update_Result_Histogram failed");
                D_Plot::Plot_Empty(pChartView_Results_Overview2_SpeedAngular_Hist, "Reqirements for Update_Result_Histogram failed");
            }
                break;

            case HIST_DIST_CENTER_INTERSECTIONS:
            {
                D_Plot::Plot_Empty(pChartView_Results_Overview2_DistCenterIntersections_Hist, "Reqirements for Update_Result_Histogram failed");
                D_Plot::Plot_Empty(pChartView_Results_Overview2_DistCenterIntersections_Hist, "Reqirements for Update_Result_Histogram failed");
            }
                break;
            default:
                break;
            }
        }

        return;
    }

    //calc range of distances to vortex center
    double dist_to_center_min;
    double dist_to_center_max;
    P_VortexCenter.in_rect(0, spatial_roi_height, 0, spatial_roi_width, &dist_to_center_min, &dist_to_center_max);

    //color coding description
    bool color_value_as_var = ui->checkBox_Res_Histo_VariationAsColorValue->isChecked();
    QString QS_ColorDescription;
    if(color_value_as_var)
        QS_ColorDescription = "<br>Hue: Mean Distance to vortex center<br>Value: Variation of distances to vortex center";
    else
        QS_ColorDescription = "<br>Hue: Mean Distance to vortex center<br>Value: Maximum (no information)";

    //dictance variation if equally distributed
    //double mean_if_equal = (dist_to_center_max - dist_to_center_min) / 2;
    double var_if_equal = ((dist_to_center_max - dist_to_center_min) * (dist_to_center_max - dist_to_center_min)) / 12.0;
    double std_if_equal = sqrt(var_if_equal);
    //double cv_if_equal = std_if_equal / mean_if_equal;

    switch (mode) {

    case HIST_LINEAR_SPEED:
    {
        if(ui->comboBox_Res_Type->currentIndex() == RES_HISTOGRAM)
            ERR(D_Plot::Plot_Hist_WithStats_Color(
                        pChartView_Results_Line,
                        vShiftsAll_um_s,
                        vDistancesToVortexCenter_All_um,
                        D_Stat::Function_SingleStat(c_STAT_MEAN_ARITMETIC),
                        color_value_as_var ? D_Stat::Function_SingleStat(c_STAT_STAN_DEV_SAMPLE) : D_Stat::Function_SingleStat(c_STAT_CONST_0),
                        0, ui->doubleSpinBox_Res_Histo_MaxSpeedLinear->value(),
                        dist_to_center_min, dist_to_center_max,
                        0, std_if_equal,
                        ui->spinBox_Res_Histo_Classes_Speed->value(),
                        v_VideoStats_Shifts_um_s[c_STAT_MEAN_ARITMETIC],
                        v_VideoStats_Shifts_um_s[c_STAT_STAN_DEV_TOTAL],
                        "<b>Linear shifts histogram</b><br>" + QSL_Videos_Names[ui->comboBox_Data_Videos->currentIndex()] + QS_ColorDescription,
                        "linear shift um/s",
                        ui->checkBox_Res_Histo_Uni->isChecked(),
                        ui->checkBox_Res_Histo_Acc->isChecked()),
                    "Update_Result_Histogram",
                    "D_Plot::Plot_Hist_WithStats_Color - Linear Speed");
        else
            ERR(D_Plot::Plot_Hist_WithStats_Color(
                        pChartView_Results_Overview2_SpeedLinear_Hist,
                        vShiftsAll_um_s,
                        vDistancesToVortexCenter_All_um,
                        D_Stat::Function_SingleStat(c_STAT_MEAN_ARITMETIC),
                        color_value_as_var ? D_Stat::Function_SingleStat(c_STAT_STAN_DEV_SAMPLE) : D_Stat::Function_SingleStat(c_STAT_CONST_0),
                        0, ui->doubleSpinBox_Res_Histo_MaxSpeedLinear->value(),
                        dist_to_center_min, dist_to_center_max,
                        0, std_if_equal,
                        ui->spinBox_Res_Histo_Classes_Speed->value(),
                        v_VideoStats_Shifts_um_s[c_STAT_MEAN_ARITMETIC],
                        v_VideoStats_Shifts_um_s[c_STAT_STAN_DEV_TOTAL],
                        "<b>Linear shifts histogram</b><br>" + QSL_Videos_Names[ui->comboBox_Data_Videos->currentIndex()] + QS_ColorDescription,
                        "linear shift um/s",
                        ui->checkBox_Res_Histo_Uni->isChecked(),
                        ui->checkBox_Res_Histo_Acc->isChecked(),
                        5),
                    "Update_Result_Histogram",
                    "D_Plot::Plot_Hist_WithStats_Color - Linear Speed");
    }
        break;

    case HIST_ANGULAR_SPEED:
    {
        if(ui->comboBox_Res_Type->currentIndex() == RES_HISTOGRAM)
            ERR(D_Plot::Plot_Hist_WithStats_Color(
                        pChartView_Results_Line,
                        vShiftsAll_grad_s,
                        vDistancesToVortexCenter_All_um,
                        D_Stat::Function_SingleStat(c_STAT_MEAN_ARITMETIC),
                        color_value_as_var ? D_Stat::Function_SingleStat(c_STAT_STAN_DEV_SAMPLE) : D_Stat::Function_SingleStat(c_STAT_CONST_0),
                        0, ui->doubleSpinBox_Res_Histo_MaxSpeedAngular->value(),
                        dist_to_center_min, dist_to_center_max,
                        0, std_if_equal,
                        ui->spinBox_Res_Histo_Classes_Speed->value(),
                        v_VideoStats_Shifts_grad_s[c_STAT_MEAN_ARITMETIC],
                        v_VideoStats_Shifts_grad_s[c_STAT_STAN_DEV_TOTAL],
                        "<b>Angular shifts histogram</b><br>" + QSL_Videos_Names[ui->comboBox_Data_Videos->currentIndex()] + QS_ColorDescription,
                        "angular shift °/s",
                        ui->checkBox_Res_Histo_Uni->isChecked(),
                        ui->checkBox_Res_Histo_Acc->isChecked()),
                    "Update_Result_Histogram",
                    "D_Plot::Plot_Hist_WithStats_Color - Angular Speed");
        else
            ERR(D_Plot::Plot_Hist_WithStats_Color(
                        pChartView_Results_Overview2_SpeedAngular_Hist,
                        vShiftsAll_grad_s,
                        vDistancesToVortexCenter_All_um,
                        D_Stat::Function_SingleStat(c_STAT_MEAN_ARITMETIC),
                        color_value_as_var ? D_Stat::Function_SingleStat(c_STAT_STAN_DEV_SAMPLE) : D_Stat::Function_SingleStat(c_STAT_CONST_0),
                        0, ui->doubleSpinBox_Res_Histo_MaxSpeedAngular->value(),
                        dist_to_center_min, dist_to_center_max,
                        0, std_if_equal,
                        ui->spinBox_Res_Histo_Classes_Speed->value(),
                        v_VideoStats_Shifts_grad_s[c_STAT_MEAN_ARITMETIC],
                        v_VideoStats_Shifts_grad_s[c_STAT_STAN_DEV_TOTAL],
                        "<b>Angular shifts histogram</b><br>" + QSL_Videos_Names[ui->comboBox_Data_Videos->currentIndex()] + QS_ColorDescription,
                        "angular shift °/s",
                        ui->checkBox_Res_Histo_Uni->isChecked(),
                        ui->checkBox_Res_Histo_Acc->isChecked(),
                        5),
                    "Update_Result_Histogram",
                    "D_Plot::Plot_Hist_WithStats_Color - Angular Speed");
    }
        break;

    case HIST_DIST_CENTER_INTERSECTIONS:
    {
        vector<vector<double>> vv_data(2);
        vv_data[0] = v_VortexCenterResiduals_All;
        vv_data[1] = v_VortexCenterResiduals_Used;

        if(ui->comboBox_Res_Type->currentIndex() == RES_HISTOGRAM)
            ERR(D_Plot::Plot_Hist_WithStats(
                        pChartView_Results_Line,
                        vv_data,
                        0,
                        ui->doubleSpinBox_Res_Histo_MaxDistCenterIntersections->value(),
                        ui->spinBox_Res_Histo_Classes_Dist->value(),
                        "<b>Distance from line intersections to approximate center histogram</b><br>" + QSL_Videos_Names[ui->comboBox_Data_Videos->currentIndex()] + "<br>blue: used intersections, red: all intersections",
                        "distance um",
                        ui->checkBox_Res_Histo_Uni->isChecked(),
                        ui->checkBox_Res_Histo_Acc->isChecked()),
                    "Update_Result_Histogram",
                    "D_Plot::Plot_Hist_WithStats - Distance");
        else
            ERR(D_Plot::Plot_Hist_WithStats(
                        pChartView_Results_Overview2_DistCenterIntersections_Hist,
                        vv_data,
                        0,
                        ui->doubleSpinBox_Res_Histo_MaxDistCenterIntersections->value(),
                        ui->spinBox_Res_Histo_Classes_Dist->value(),
                        "<b>Distance from line intersections<br>to approximate center histogram</b><br>" + QSL_Videos_Names[ui->comboBox_Data_Videos->currentIndex()] + "<br>blue: used intersections, red: all intersections",
                        "distance um",
                        ui->checkBox_Res_Histo_Uni->isChecked(),
                        ui->checkBox_Res_Histo_Acc->isChecked(),
                        5),
                    "Update_Result_Histogram",
                    "D_Plot::Plot_Hist_WithStats - Distance");
    }
        break;

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
    DIR_SaveStackGraphics_Vortex.setPath(DIR_SaveStackGraphics.path() + "/Vortex");     QDir().mkdir(DIR_SaveStackGraphics_Vortex.path());
    DIR_SaveStackGraphics_Vector.setPath(DIR_SaveStackGraphics.path() + "/Vector");     QDir().mkdir(DIR_SaveStackGraphics_Vector.path());
    DIR_SaveStackGraphics_Speed.setPath(DIR_SaveStackGraphics.path() + "/Speed");       QDir().mkdir(DIR_SaveStackGraphics_Speed.path());
    DIR_SaveStackGraphics_Angle.setPath(DIR_SaveStackGraphics.path() + "/Angle");       QDir().mkdir(DIR_SaveStackGraphics_Angle.path());
    DIR_SaveStackGraphics_Video.setPath(DIR_SaveStackGraphics.path() + "/Video");       QDir().mkdir(DIR_SaveStackGraphics_Video.path());
    //plot
    DIR_SaveStackPlot.setPath(DIR_SaveStack.path() + "/Plot");                          QDir().mkdir(DIR_SaveStackPlot.path());
    DIR_SaveStackPlot_Speed.setPath(DIR_SaveStackPlot.path() + "/Speed");               QDir().mkdir(DIR_SaveStackPlot_Speed.path());
    DIR_SaveStackPlot_Angle.setPath(DIR_SaveStackPlot.path() + "/Angle");               QDir().mkdir(DIR_SaveStackPlot_Angle.path());
    DIR_SaveStackPlot_Vortex.setPath(DIR_SaveStackPlot.path() + "/Vortex");             QDir().mkdir(DIR_SaveStackPlot_Vortex.path());
    DIR_SaveStackPlot_Overview.setPath(DIR_SaveStackPlot.path() + "/Overview");         QDir().mkdir(DIR_SaveStackPlot_Overview.path());
    //overview
    DIR_SaveStackOverview.setPath(DIR_SaveStack.path() + "/Overview");                  QDir().mkdir(DIR_SaveStackOverview.path());
    //single
    DIR_SaveSingles.setPath(DIR_SaveMaster.path() + "/SingleVideos");                   QDir().mkdir(DIR_SaveSingles.path());

    //Create tables for stats
    ofstream OS_SaveStats_SpeedLinear;
    ofstream OS_SaveStats_SpeedAngular;
    ofstream OS_SaveStats_Angle;
    OS_SaveStats_SpeedLinear.open((DIR_SaveStackOverview.path() + "/StackStats_SpeedLinear.csv").toStdString());
    OS_SaveStats_SpeedAngular.open((DIR_SaveStackOverview.path() + "/StackStats_SpeedAngular.csv").toStdString());
    OS_SaveStats_Angle.open((DIR_SaveStackOverview.path() + "/StackStats_Angle.csv").toStdString());

    //init stat tables
    OS_SaveStats_SpeedLinear
            << "File,"      << "StackStats_SpeedLinear.csv" << "\n"
            << "Path,"      << DIR_SaveStackOverview.path().toStdString() << "\n"
            << "DateTime,"  << QDateTime::currentDateTime().toString().toStdString() << "\n"
            << "\n"
            << "Base unit," << "um/s"
            << "\n";
    OS_SaveStats_SpeedAngular
            << "File,"      << "StackStats_SpeedLinear.csv" << "\n"
            << "Path,"      << DIR_SaveStackOverview.path().toStdString() << "\n"
            << "DateTime,"  << QDateTime::currentDateTime().toString().toStdString() << "\n"
            << "\n"
            << "Base unit," << "°/s"
            << "\n";
    OS_SaveStats_Angle
            << "File,"      << "StackStats_Angle.csv" << "\n"
            << "Path,"      << DIR_SaveStackOverview.path().toStdString() << "\n"
            << "DateTime,"  << QDateTime::currentDateTime().toString().toStdString() << "\n"
            << "\n"
            << "Base unit," << "°"
            << "\n";

    //stats as header of columns
    for(int s = 0; s < c_STAT_NUMBER_OF_STATS; s++)
        OS_SaveStats_SpeedLinear << "," << QSL_StatList[s].toStdString();
    for(int s = 0; s < c_STAT_NUMBER_OF_STATS; s++)
        OS_SaveStats_SpeedAngular << "," << QSL_StatList[s].toStdString();
    for(int s = 0; s < c_STAT_CIRC_NUMBER_OF; s++)
        OS_SaveStats_Angle << "," << QSL_StatListCirc[s].toStdString();

    state_StackProcessing = true;

    //start taskbar progress
    //pTaskBarProgress->show();
    //pTaskBarProgress->setRange(0, FIL_Videos.size());
    //pTaskBarProgress->setValue(0);

    //loop single videos
    for(int v = 0; v < FIL_Videos.size(); v++)
    {
        //set taskbar progress
        //pTaskBarProgress->setValue(v);
        //Update_Ui();

        //load current video
        ui->comboBox_Data_Videos->setCurrentIndex(v);

        //update, save, etc.
        Save_AnalysisSingle();

        //stream to stat tables
        OS_SaveStats_SpeedLinear << "\n" << QSL_Videos_Names[v].toStdString();
        OS_SaveStats_SpeedAngular << "\n" << QSL_Videos_Names[v].toStdString();
        OS_SaveStats_Angle << "\n" << QSL_Videos_Names[v].toStdString();
        for(size_t s = 0; s < v_VideoStats_Shifts_um_s.size(); s++)
            OS_SaveStats_SpeedLinear << "," << v_VideoStats_Shifts_um_s[s];
        if(state_StatSummaryCalced_angularSpeed)
            for(size_t s = 0; s < v_VideoStats_Shifts_grad_s.size(); s++)
                OS_SaveStats_SpeedAngular << "," << v_VideoStats_Shifts_grad_s[s];
        for(size_t s = 0; s < v_VideoStats_Angles_Grad.size(); s++)
            OS_SaveStats_Angle << "," << v_VideoStats_Angles_Grad[s];
    }

    //close filestreams
    OS_SaveStats_SpeedLinear.close();
    OS_SaveStats_SpeedAngular.close();
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

    //relative layout params for summary
    /*
    double gap_border       = 0.03;
    double gap_within       = 0.01;
    double gap_within_small = gap_within / 2.0;
    double line_big         = 0.0425;
    double line_small       = 0.0225;
    double image_height     = 0.255;
    double legend_height    = 0.02;
    double x_border_left    = 0 + gap_border;
    double x_border_right   = 1 - gap_border;
    double y_border_top     = 0 + gap_border;
    double y_border_bottom  = 1 - gap_border;
    double x_mid_right      = 0.5 + gap_within_small;
    double x_mid_left       = 0.5 - gap_within_small;
    double x_left_mid       = (x_mid_left + x_border_left) / 2.0;
    double y_head_1         = y_border_top + line_big;
    double y_head_2         = y_head_1 + line_small;
    double y_img_1_above    = y_head_2;
    double y_img_1_under    = y_img_1_above + image_height;
    double y_img_1_mid      = (y_img_1_above + y_img_1_under) / 2.0;
    double y_img_2_above    = y_img_1_under + gap_within;
    double y_img_2_under    = y_img_2_above + image_height;
    double y_legend_above   = y_img_2_under + gap_within_small;
    double y_legend_under   = y_legend_above + legend_height;
    double y_graph_above    = y_legend_under + gap_within;
    */

    //relative layout params for summary
    double gap_border       = 0.02;
    double gap_within       = 0.01;
    double gap_within_half  = gap_within / 2.0;
    double text_big         = 0.0425;
    double text_small       = 0.0225;
    double image_height     = 0.17;
    double legend_height    = 0.014;
    double textblock_height = 0.1;

    double x_border_left    = 0 + gap_border;
    double x_border_right   = 1 - gap_border;
    double y_border_top     = 0 + gap_border;
    double y_border_bottom  = 1 - gap_border;

    double x_width_eff      = x_border_right - x_border_left;
    //double y_height_eff     = y_border_bottom - y_border_top;

    double x_3elem_step     = x_width_eff / 3.0;
    double x_3elem_0l       = x_border_left + x_3elem_step * 0 + gap_within_half;
    double x_3elem_0r       = x_border_left + x_3elem_step * 1 - gap_within_half;
    double x_3elem_1l       = x_border_left + x_3elem_step * 1 + gap_within_half;
    double x_3elem_1r       = x_border_left + x_3elem_step * 2 - gap_within_half;
    double x_3elem_2l       = x_border_left + x_3elem_step * 2 + gap_within_half;
    double x_3elem_2r       = x_border_left + x_3elem_step * 3 - gap_within_half;
    double x_4elem_step     = x_width_eff / 4.0;
    double x_4elem_0l       = x_border_left + x_4elem_step * 0 + gap_within_half;
    double x_4elem_0r       = x_border_left + x_4elem_step * 1 - gap_within_half;
    double x_4elem_1l       = x_border_left + x_4elem_step * 1 + gap_within_half;
    double x_4elem_1r       = x_border_left + x_4elem_step * 2 - gap_within_half;
    double x_4elem_2l       = x_border_left + x_4elem_step * 2 + gap_within_half;
    double x_4elem_2r       = x_border_left + x_4elem_step * 3 - gap_within_half;
    double x_4elem_3l       = x_border_left + x_4elem_step * 3 + gap_within_half;
    double x_4elem_3r       = x_border_left + x_4elem_step * 4 - gap_within_half;

    double y_head_1         = y_border_top + text_big;
    double y_head_2         = y_head_1 + text_small;

    double y_text_t         = y_head_2 + gap_within;
    double y_text_b         = y_text_t + textblock_height;
    double y_img_heat_t     = y_text_b + gap_within;
    double y_img_heat_b     = y_img_heat_t + image_height;
    double y_img_leg_t      = y_img_heat_b + gap_within_half;
    double y_img_leg_b      = y_img_leg_t + legend_height;
    double y_img_oth_t      = y_img_leg_b + gap_within;
    double y_img_oth_b      = y_img_oth_t + image_height;
    double y_plot_t         = y_img_oth_b + gap_within;
    double y_plot_b         = y_border_bottom;

    //header of summary
    PDF_Summary.add_Text(
                name_current,
                x_border_left, x_border_right, y_border_top, y_head_1,
                20,
                Qt::AlignCenter);
    PDF_Summary.add_Text("Video analysis summary by ImageD " + D_QS_Version + " (" + D_QS_Release + ") done at " + QDateTime::currentDateTime().toString(),
                x_border_left, x_border_right, y_head_1, y_head_2,
                10,
                Qt::AlignCenter);

    //percent of detection required
    ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->setValue(75);

    //Graphics---------------------------------------------------------------

    //gamma strong for diff img projectiona na heatmaps
    ui->doubleSpinBox_Res_TimeProjSum_Gamma->setValue(0.33);

    //movement tracks only
    ui->comboBox_Res_Type->setCurrentIndex(RES_GRAPHICS_TIME_SUM_PROJ);
    PDF_Overview.add_Image(
                View_Results.pQI(),
                name_current + "\n"
                "Video analysis overview\n"
                "\n"
                "ImageD version " + D_QS_Version + " (" + D_QS_Release + ")\n"
                "Analysis done " + QDateTime::currentDateTime().toString(),
                20,
                Qt::AlignCenter);
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - DifferenceImages_SumProjection" + ".png");

    //Stats--------------------------------------------------------------- (Graphics will be continued)

    //track coordination
    ui->comboBox_Res_Type->setCurrentIndex(RES_GRAPHICS_FIELD_SUMMARY);
    ui->comboBox_Res_FieldSumary_StatType->setCurrentIndex(DATA_TYPE_ANGLE);
    ui->comboBox_Res_FieldSumary_StatIndex_Grid->setCurrentIndex(c_STAT_MEAN_ARITMETIC);
    ui->comboBox_Res_FieldSumary_StatIndex_Cells_Angular->setCurrentIndex(c_STAT_CIRC_UNBALANCE);
    ui->spinBox_ParamGridHorizontal->setValue(10);
    ui->spinBox_ParamGridVertical->setValue(8);
    ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setValue(0.5);
    ui->doubleSpinBox_Res_VectorFieldParam_ScaleLength->setValue(1.0);
    Update_Results();
    Update_Ui();
    double track_coordination = ui->doubleSpinBox_FieldSumary_StatResult->value();


    //simple stats

    //stat list

    //Speed linear
    //long
    QString QS_Stats_SpeedLinear = "Statistics of linear speed in full video:\n"
                             "\n"
                             "Base speed unit is um/s.\n";
    for(size_t s = 0; s < v_VideoStats_Shifts_um_s.size(); s++)
        QS_Stats_SpeedLinear.append("\n" + QSL_StatList[static_cast<int>(s)] + ": " + QString::number(v_VideoStats_Shifts_um_s[s]));
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Text(QS_Stats_SpeedLinear);
    //short
    PDF_Summary.add_Text(
                "Linear speed stats:\n"
                "Average " + QString::number(v_VideoStats_Shifts_um_s[c_STAT_MEAN_ARITMETIC], 'g', 4) + "um/s\n"
                "STD " + QString::number(v_VideoStats_Shifts_um_s[c_STAT_STAN_DEV_SAMPLE], 'g', 4) + "um/s\n"
                "10%-Quantil " + QString::number(v_VideoStats_Shifts_um_s[c_STAT_QUANTIL_10], 'g', 4) + "um/s\n"
                "Median " + QString::number(v_VideoStats_Shifts_um_s[c_STAT_MEDIAN], 'g', 4) + "um/s\n"
                "90%-Quantil " + QString::number(v_VideoStats_Shifts_um_s[c_STAT_QUANTIL_90], 'g', 4) + "um/s",
                x_4elem_1l, x_4elem_1r, y_text_t, y_text_b,
                10,
                Qt::AlignCenter);

    //Speed angular
    if(!state_StatSummaryCalced_angularSpeed)
        Data_CalcFullVideoStats_AngularSpeed();
    if(state_StatSummaryCalced_angularSpeed)
    {
        //long
        QString QS_Stats_SpeedAngular = "Statistics of angular speed in full video:\n"
                                 "\n"
                                 "Base speed unit is °/s.\n";
        for(size_t s = 0; s < v_VideoStats_Shifts_grad_s.size(); s++)
            QS_Stats_SpeedAngular.append("\n" + QSL_StatList[static_cast<int>(s)] + ": " + QString::number(v_VideoStats_Shifts_grad_s[s]));
        PDF_Overview.add_NewPage();
        PDF_Overview.add_Text(QS_Stats_SpeedAngular);
        //short
        PDF_Summary.add_Text(
                    "Angular speed stats:\n"
                    "Average " + QString::number(v_VideoStats_Shifts_grad_s[c_STAT_MEAN_ARITMETIC], 'g', 4) + "°/s\n"
                    "STD " + QString::number(v_VideoStats_Shifts_grad_s[c_STAT_STAN_DEV_SAMPLE], 'g', 4) + "°/s\n"
                    "10%-Quantil " + QString::number(v_VideoStats_Shifts_grad_s[c_STAT_QUANTIL_10], 'g', 4) + "°/s\n"
                    "Median " + QString::number(v_VideoStats_Shifts_grad_s[c_STAT_MEDIAN], 'g', 4) + "°/s\n"
                    "90%-Quantil " + QString::number(v_VideoStats_Shifts_grad_s[c_STAT_QUANTIL_90], 'g', 4) + "°/s",
                    x_4elem_2l, x_4elem_2r, y_text_t, y_text_b,
                    10,
                    Qt::AlignCenter);
    }

    //Angle
    //long
    QString QS_Stats_Angle = "Statistics of angle in full video:\n"
                             "\n"
                             "Base angle unit is degree.\n";
    for(size_t s = 0; s < v_VideoStats_Angles_Grad.size(); s++)
        QS_Stats_Angle.append("\n" + QSL_StatListCirc[static_cast<int>(s)] + ": " + QString::number(v_VideoStats_Angles_Grad[s]));
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Text(QS_Stats_Angle);
    //short
    PDF_Summary.add_Text(
                "Angle Stats:\n"
                "Average " + QString::number(v_VideoStats_Angles_Grad[c_STAT_CIRC_MEAN_ANG], 'g', 4) + "°\n"
                "Balance " + QString::number(v_VideoStats_Angles_Grad[c_STAT_CIRC_BALANCE] * 100.0, 'g', 4) + "%\n"
                "STD Equivalent " + QString::number(v_VideoStats_Angles_Grad[c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA], 'g', 4) + "°\n"
                "Track coord. " + QString::number(int(track_coordination * 10000) / 100.0) + "%",
                x_4elem_3l, x_4elem_3r, y_text_t, y_text_b,
                10,
                Qt::AlignCenter);

    //Graphics (again)---------------------------------------------------------------

    //vortex center graphic

    ui->comboBox_Res_Type->setCurrentIndex(RES_GRAPHICS_VORTEX_CENTER);
    ui->spinBox_ParamGridHorizontal->setValue(5);
    ui->spinBox_ParamGridVertical->setValue(4);
    ui->checkBox_Res_VortexCenter_MovingAverage->setCheckState(Qt::CheckState::PartiallyChecked);
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(0); //0=points, 1=lines
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(75);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(100000);
    //other settings on default

    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_Ransac75przOfPoints_grid4x5_iters100k - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_Ransac75przOfPoints_grid4x5_iters100k.png");

    PDF_Summary.add_Image(
                View_Results.pQI(),
                x_3elem_2l, x_3elem_2r, y_img_oth_t, y_img_oth_b);

    /*
    //4x5, no ransac
    ui->spinBox_ParamGridHorizontal->setValue(5);
    ui->spinBox_ParamGridVertical->setValue(4);
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(false);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_4x5_RansacOff - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_4x5_RansacOff.png");

    //4x5, ransac points 50%, 1M
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(0);
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(50);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(1000000);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_4x5_RansacPoints_50prz_1M_iters - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_4x5_RansacPoints_50prz_1M_iters.png");

    //4x5, ransac lines 50%, 1M
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(1);
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(50);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(1000000);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_4x5_RansacLines_50prz_1M_iters - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_4x5_RansacLines_50prz_1M_iters.png");
    PDF_Summary.add_Image(
                View_Results.pQI(),
                x_3elem_2l, x_3elem_2r, y_img_oth_t, y_img_oth_b);

    //4x5, ransac points 75%, 1M
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(0);
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(75);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(1000000);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_4x5_RansacPoints_75prz_1M_iters - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_4x5_RansacPoints_75prz_1M_iters.png");

    //4x5, ransac lines 75%, 1M
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(1);
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(75);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(1000000);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_4x5_RansacLines_75prz_1M_iters - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_4x5_RansacLines_75prz_1M_iters.png");

    //4x5, ransac points 50%, 100k
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(0);
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(50);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(100000);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_4x5_RansacPoints_50prz_100k_iters - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_4x5_RansacPoints_50prz_100k_iters.png");

    //4x5, ransac lines 50%, 100k
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(1);
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(50);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(100000);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_4x5_RansacLines_50prz_100k_iters - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_4x5_RansacLines_50prz_100k_iters.png");

    //4x5, ransac points 75%, 100k
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(0);
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(75);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(100000);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_4x5_RansacPoints_75prz_100k_iters - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_4x5_RansacPoints_75prz_100k_iters.png");

    //4x5, ransac lines 75%, 100k
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(1);
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(75);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(100000);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_4x5_RansacLines_75prz_100k_iters - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_4x5_RansacLines_75prz_100k_iters.png");
    */
    /*
    //8x10, no ransac
    ui->spinBox_ParamGridHorizontal->setValue(8);
    ui->spinBox_ParamGridVertical->setValue(10);
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(false);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_8x10_RansacOff - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_8x10_RansacOff.png");

    //8x10, ransac points 50%, 1M
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(0);
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(50);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(1000000);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_8x10_RansacPoints_50prz_1M_iters - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_8x10_RansacPoints_50prz_1M_iters.png");

    //8x10, ransac lines 50%, 1M
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(1);
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(50);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(1000000);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_8x10_RansacLines_50prz_1M_iters - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_8x10_RansacLines_50prz_1M_iters.png");

    //8x10, ransac points 75%, 1M
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(0);
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(75);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(1000000);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_8x10_RansacPoints_75prz_1M_iters - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_8x10_RansacPoints_75prz_1M_iters.png");

    //8x10, ransac lines 75%, 1M
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(1);
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(75);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(1000000);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_8x10_RansacLines_75prz_1M_iters - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_8x10_RansacLines_75prz_1M_iters.png");

    //8x10, ransac points 50%, 100k
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(0);
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(50);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(100000);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_8x10_RansacPoints_50prz_100k_iters - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_8x10_RansacPoints_50prz_100k_iters.png");

    //8x10, ransac lines 50%, 100k
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(1);
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(50);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(100000);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_8x10_RansacLines_50prz_100k_iters - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_8x10_RansacLines_50prz_100k_iters.png");

    //8x10, ransac points 75%, 100k
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(0);
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(75);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(100000);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_8x10_RansacPoints_75prz_100k_iters - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_8x10_RansacPoints_75prz_100k_iters.png");

    //8x10, ransac lines 75%, 100k
    ui->checkBox_Res_VortexCenter_Ransac->setChecked(true);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setCurrentIndex(1);
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setValue(75);
    ui->spinBox_Res_VortexCenter_RansacIterations->setValue(100000);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Vortex.path() + "/VortexCenter_8x10_RansacLines_75prz_100k_iters - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VortexCenter_8x10_RansacLines_75prz_100k_iters.png");
    */

    //---------------------------------------------------- heatmaps -----------------

    //Heatmap
    ui->comboBox_Res_Type->setCurrentIndex(RES_GRAPHICS_HEATMAP);

    ui->comboBox_Res_Heat_Mode->setCurrentIndex(HEAT_SPEED_LINEAR);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Heatmap.path() + "/HeatmapSpeedLinear - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - HeatmapSpeedLinear.png");
    PDF_Summary.add_Image(
                View_Results.pQI(),
                x_3elem_0l, x_3elem_0r, y_img_heat_t, y_img_heat_b);
    PDF_Summary.add_Image(
                &MA_Result_HeatmapLegend,
                x_3elem_0l, x_3elem_0r, y_img_leg_t, y_img_leg_b);
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Image(
                View_Results.pQI(),
                "Heatmap (linear speed)\n"
                "\n"
                "Color: Linear speed (red <= 10%-quantil, blue => 90%-quantil)\n"
                "Saturation: 100% (no information)\n"
                "Value: Default tracks-graphics"
                "\n"
                "Color map is realative to video content.\n"
                "\n"
                "Useful to get an overview of the spatial linear speed distribution.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackGraphics_Heatmap.path() + "/HeatmapSpeedLinear - " + name_current + ".png\n" +
                DIR_SaveCurrentGraphics.path() + "/" + name_current + " - HeatmapSpeedLinear.png");
    PDF_Overview.add_Image(
                &MA_Result_HeatmapLegend,
                0.05, 0.95, 0.85, 0.95);

    ui->comboBox_Res_Heat_Mode->setCurrentIndex(HEAT_SPEED_ANGULAR);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Heatmap.path() + "/HeatmapSpeedAngular - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - HeatmapSpeedAngular.png");
    PDF_Summary.add_Image(
                View_Results.pQI(),
                x_3elem_1l, x_3elem_1r, y_img_heat_t, y_img_heat_b);
    PDF_Summary.add_Image(
                &MA_Result_HeatmapLegend,
                x_3elem_1l, x_3elem_1r, y_img_leg_t, y_img_leg_b);
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Image(
                View_Results.pQI(),
                "Heatmap (angular speed)\n"
                "\n"
                "Color: Speed (red <= 10%-quantil, blue => 90%-quantil)\n"
                "Saturation: 100% (no information)\n"
                "Value: Default tracks-graphics"
                "\n"
                "Color map is realative to video content.\n"
                "\n"
                "Useful to get an overview of the spatial angular speed distribution.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackGraphics_Heatmap.path() + "/HeatmapSpeedAngular - " + name_current + ".png\n" +
                DIR_SaveCurrentGraphics.path() + "/" + name_current + " - HeatmapSpeedAngular.png");
    PDF_Overview.add_Image(
                &MA_Result_HeatmapLegend,
                0.05, 0.95, 0.85, 0.95);

    ui->comboBox_Res_Heat_Mode->setCurrentIndex(HEAT_ANGLE);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Heatmap.path() + "/HeatmapAngle - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - HeatmapAngle.png");
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Image(
                View_Results.pQI(),
                "Heatmap (Angle)\n"
                "\n"
                "Color: Angle (See legend at the bottom of this page)\n"
                "Saturation: 100% (no information)\n"
                "Value: Default tracks-graphics"
                "\n"
                "Useful to get an overview of the spatial angle distribution.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackGraphics_Heatmap.path() + "/HeatmapAngle - " + name_current + ".png\n" +
                DIR_SaveCurrentGraphics.path() + "/" + name_current + " - HeatmapAngle.png");
    PDF_Overview.add_Image(
                &MA_Result_HeatmapLegend,
                0.05, 0.95, 0.85, 0.95);

    ui->comboBox_Res_Heat_Mode->setCurrentIndex(HEAT_SPEED_LINEAR_AND_ANGLE);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Heatmap.path() + "/HeatmapSpeedAngle - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - HeatmapSpeedAngle.png");
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Image(
                View_Results.pQI(),
                "Heatmap (Spped and Angle)\n"
                "\n"
                "Color: Angle (see legend at the bottom of this page)\n"
                "Saturation: Speed (gray <= 10%-Quantil, intense color >= 90%-Quantil\n"
                "Value: Default tracks-graphics"
                "\n"
                "Useful to get an overview of the spatial speed and angle distribution.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackGraphics_Heatmap.path() + "/HeatmapSpeedAngle - " + name_current + ".png\n" +
                DIR_SaveCurrentGraphics.path() + "/" + name_current + " - HeatmapSpeedAngle.png");
    PDF_Overview.add_Image(
                &MA_Result_HeatmapLegend,
                0.05, 0.95, 0.85, 0.95);

    ui->comboBox_Res_Heat_Mode->setCurrentIndex(HEAT_TIME);
    Update_Ui();
    View_Results.Save_Image(DIR_SaveStackGraphics_Heatmap.path() + "/HeatmapTime - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - HeatmapTime.png");
    PDF_Summary.add_Image(
                View_Results.pQI(),
                x_3elem_2l, x_3elem_2r, y_img_heat_t, y_img_heat_b);
    PDF_Summary.add_Image(
                &MA_Result_HeatmapLegend,
                x_3elem_2l, x_3elem_2r, y_img_leg_t, y_img_leg_b);
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Image(
                View_Results.pQI(),
                "Heatmap (Time)\n"
                "\n"
                "Color: Time (red=new, blue=old)\n"
                "Saturation: 100% (no information)\n"
                "Value: Default tracks-graphics"
                "\n"
                "Color map is realative to video content.\n"
                "\n"
                "Useful to get an overview of timely behaviour.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackGraphics_Heatmap.path() + "/HeatmapTime - " + name_current + ".png\n" +
                DIR_SaveCurrentGraphics.path() + "/" + name_current + " - HeatmapTime.png");
    PDF_Overview.add_Image(
                &MA_Result_HeatmapLegend,
                0.05, 0.95, 0.85, 0.95);





    //----------------------------------------------------------------------vector fields

    //gamma softer for vector field backgrounds
    ui->doubleSpinBox_Res_TimeProjSum_Gamma->setValue(0.5);

    //vector field
    ui->comboBox_Res_Type->setCurrentIndex(RES_GRAPHICS_VECTORS);
    ui->comboBox_Res_VectorFieldParam_ShiftType->setCurrentIndex(SHIFT_TYPE_LINEAR);

    //setting 5x4 (for high resolution use)
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
                View_Results.pQI(),
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

    //same img to summary (basic vector graphic)
    PDF_Summary.add_Image(
                View_Results.pQI(),
                x_3elem_0l, x_3elem_0r, y_img_oth_t, y_img_oth_b);

    //basic info for interpretation
    QString QS_VecField_Interpretation = "";
    QS_VecField_Interpretation.append(
                "Image size: (" + QString::number(vMA_ProcSteps[STEP_CROP].cols * conv_px2um, 'g', 4) + " x " + QString::number(vMA_ProcSteps[STEP_CROP].rows * conv_px2um) + ")um\n"
                "Time analysed: " + QString::number(vv_FrmObjPositions.size() * VS_InputVideo.get_FrameTimeSec(), 'g', 4) + "s\n"
                "Vectors length: linear shift/" + QString::number(ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->value(), 'g', 4) + "s\n");

    //save motion vector field video
    Save_ResultVectorFieldVideo(
                DIR_SaveStackGraphics_Video.path() + "/MotionVectorField4x5 - " + name_current + ".avi",
                5, 4,
                10,
                BACKGR_VIDEO);


    //setting 5x4 (for low resolution use)
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
    ui->spinBox_Res_VectorFieldParam_Thickness_Vector->setValue(6);
    ui->spinBox_Res_VectorFieldParam_Thickness_Error->setValue(4);
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorField4x5_ForLowResolutionUse.png");
    Update_Ui();

    //setting 10x8 (for high resolution use)
    //qDebug() << "Save_AnalysisSingle" << "vector 10x8 high res";
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
                View_Results.pQI(),
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

    //setting 10x8 (for low resolution use)
    //qDebug() << "Save_AnalysisSingle" << "vector 10x8 low res";
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
    ui->spinBox_Res_VectorFieldParam_Thickness_Vector->setValue(6);
    ui->spinBox_Res_VectorFieldParam_Thickness_Error->setValue(2);
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorField10x8_ForLowResolutionUse.png");
    Update_Ui();

    //setting 20x16
    //qDebug() << "Save_AnalysisSingle" << "vector 20x16";
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
                View_Results.pQI(),
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

    //angle only (for high resolution use)
    //qDebug() << "Save_AnalysisSingle" << "angle high res";
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
                View_Results.pQI(),
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

    //angle only (for low resolution use)
    //qDebug() << "Save_AnalysisSingle" << "angle low res";
    ui->comboBox_Res_MovAv_TimeWindow->setCurrentIndex(TIME_WINDOW_FULL_VIDEO);
    ui->comboBox_Res_VectorFieldParam_Length_Value->setCurrentIndex(c_STAT_CONST_1);
    ui->comboBox_Res_VectorFieldParam_Length_Error->setCurrentIndex(c_STAT_CONST_0);
    ui->comboBox_Res_VectorFieldParam_Angle_Value->setCurrentIndex(c_STAT_CIRC_MEAN_ANG);
    ui->comboBox_Res_VectorFieldParam_Angle_Error->setCurrentIndex(c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA);
    ui->spinBox_ParamGridHorizontal->setValue(10);
    ui->spinBox_ParamGridVertical->setValue(8);
    ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setValue(0.5);
    ui->doubleSpinBox_Res_VectorFieldParam_ScaleLength->setValue(50);
    ui->checkBox_Res_GridVisParam_Grid->setChecked(false);
    ui->checkBox_Res_GridVisParam_Labels->setChecked(false);
    ui->spinBox_Res_VectorFieldParam_Thickness_Vector->setValue(4);
    ui->spinBox_Res_VectorFieldParam_Thickness_Error->setValue(4);
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorFieldAngle_ForLowResolutionUse.png");
    Update_Ui();

    //setting speed (for high resolution use)
    //qDebug() << "Save_AnalysisSingle" << "speed high res";
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
    ui->spinBox_Res_VectorFieldParam_Thickness_Error->setValue(1);
    View_Results.Save_Image(DIR_SaveStackGraphics_Speed.path() + "/VectorFieldSpeed - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorFieldSpeed.png");
    ui->groupBox_Res->grab().save(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorFieldSpeed_Settings.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Image(
                View_Results.pQI(),
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

    //setting speed (for low resolution use)
    //qDebug() << "Save_AnalysisSingle" << "speed low res";
    ui->comboBox_Res_MovAv_TimeWindow->setCurrentIndex(TIME_WINDOW_FULL_VIDEO);
    ui->comboBox_Res_VectorFieldParam_Length_Value->setCurrentIndex(c_STAT_MEAN_ARITMETIC);
    ui->comboBox_Res_VectorFieldParam_Length_Error->setCurrentIndex(c_STAT_STAN_DEV_SAMPLE);
    ui->comboBox_Res_VectorFieldParam_Angle_Value->setCurrentIndex(c_STAT_CIRC_CONST_0);
    ui->comboBox_Res_VectorFieldParam_Angle_Error->setCurrentIndex(c_STAT_CIRC_CONST_PI);
    ui->spinBox_ParamGridHorizontal->setValue(10);
    ui->spinBox_ParamGridVertical->setValue(8);
    ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setValue(0.5);
    ui->doubleSpinBox_Res_VectorFieldParam_ScaleLength->setValue(1);
    ui->checkBox_Res_GridVisParam_Grid->setChecked(false);
    ui->checkBox_Res_GridVisParam_Labels->setChecked(false);
    ui->spinBox_Res_VectorFieldParam_Thickness_Vector->setValue(3);
    ui->spinBox_Res_VectorFieldParam_Thickness_Error->setValue(3);
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - VectorFieldSpeed_ForLowResolutionUse.png");
    Update_Ui();

    //angular shift arc field -----------------------------------------

    state_blockResultUpdate = true;

    //qDebug() << "Save_AnalysisSingle" << "arcs change to angular" << SHIFT_TYPE_ANGULAR;
    ui->comboBox_Res_VectorFieldParam_ShiftType->setCurrentIndex(SHIFT_TYPE_ANGULAR);

    //setting 5x4 (for high resolution use)
    //qDebug() << "Save_AnalysisSingle" << "arcs start param changes";
    ui->comboBox_Res_MovAv_TimeWindow->setCurrentIndex(TIME_WINDOW_FULL_VIDEO);
    ui->comboBox_Res_VectorFieldParam_Length_Value->setCurrentIndex(c_STAT_MEAN_ARITMETIC);
    ui->comboBox_Res_VectorFieldParam_Length_Error->setCurrentIndex(c_STAT_STAN_DEV_SAMPLE);
    ui->comboBox_Res_VectorFieldParam_Angle_Value->setCurrentIndex(c_STAT_CIRC_MEAN_ANG);
    ui->comboBox_Res_VectorFieldParam_Angle_Error->setCurrentIndex(c_STAT_CIRC_BALANCE_PI_OR_180);
    ui->spinBox_ParamGridHorizontal->setValue(5);
    ui->spinBox_ParamGridVertical->setValue(4);
    ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->setValue(15);
    ui->doubleSpinBox_Res_VectorFieldParam_ScaleLength->setValue(1.0);
    ui->checkBox_Res_GridVisParam_Grid->setChecked(true);
    ui->checkBox_Res_GridVisParam_Labels->setChecked(true);
    ui->spinBox_Res_VectorFieldParam_Thickness_Vector->setValue(3);
    //qDebug() << "Save_AnalysisSingle" << "arcs update results";
    state_blockResultUpdate = false;
    Update_Results();
    //qDebug() << "Save_AnalysisSingle" << "arcs update ui";
    Update_Ui();
    //qDebug() << "Save_AnalysisSingle" << "arcs save img";
    View_Results.Save_Image(DIR_SaveStackGraphics_Vector.path() + "/ArcField4x5 - " + name_current + ".png");
    View_Results.Save_Image(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - ArcField4x5.png");
    ui->groupBox_Res->grab().save(DIR_SaveCurrentGraphics.path() + "/" + name_current + " - ArcField4x5_Settings.png");

    //qDebug() << "Save_AnalysisSingle" << "arcs overview";
    PDF_Overview.add_NewPage();
    PDF_Overview.add_Image(
                View_Results.pQI(),
                "Arc Field 4x5\n"
                "\n"
                "Arc angle: " + ui->comboBox_Res_VectorFieldParam_Length_Value->currentText() + " +/- " + ui->comboBox_Res_VectorFieldParam_Length_Error->currentText() + "\n"
                "\n"
                "Length unit is angular shift per " + QString::number(ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->value()) + " seconds(s).\n"
                "Image size: (" + QString::number(vMA_ProcSteps[STEP_CROP].cols * conv_px2um) + " x " + QString::number(vMA_ProcSteps[STEP_CROP].rows * conv_px2um) + ")um)\n"
                "\n"
                "Blue lines connect grid cell center and approximated vortex center.\n"
                "Orientation of arcs is 90° to movemnet vector pointing away from center.\n"
                "If orientations of arcs and lines doesn't match, center estimation is bad."
                "\n"
                "Useful to get an overview of the angular movemnets.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackGraphics_Vector.path() + "/ArcField4x5 - " + name_current + ".png\n" +
                DIR_SaveCurrentGraphics.path() + "/" + name_current + " - ArcField4x5.png");

    //same img to summary (basic vector graphic)
    //qDebug() << "Save_AnalysisSingle" << "arcs summary";
    PDF_Summary.add_Image(
                View_Results.pQI(),
                x_3elem_1l, x_3elem_1r, y_img_oth_t, y_img_oth_b);

    //basic info for interpretation
    //qDebug() << "Save_AnalysisSingle" << "arcs interpretation text append";
    QS_VecField_Interpretation.append(
                "Arc angles: angular shift/" + QString::number(ui->doubleSpinBox_Res_VectorFieldParam_ShiftPerSeconds->value(), 'g', 4) + "s\n"
                "Base speed unit: um/s\n"
                "Base angle unit: °");
    //qDebug() << "Save_AnalysisSingle" << "arcs interpretaton text add";
    PDF_Summary.add_Text(
                QS_VecField_Interpretation,
                x_4elem_0l, x_4elem_0r, y_text_t, y_text_b,
                10,
                Qt::AlignCenter);

    //plots---------------------------------------------------------------

    //qDebug() << "Save_AnalysisSingle" << "plots";

    QImage QI_ImgSave_tmp;

    //time axis
    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_LINE);
    ui->comboBox_Res_PlotLine_FixRange_T->setCurrentIndex(PLOT_TIME_VIDEO_LENGTH);

    //speed stat
    ui->comboBox_Res_Type->setCurrentIndex(RES_SPEED_STAT_CUSTOM);
    ui->comboBox_Res_SpeedCustom_ShiftType->setCurrentIndex(SHIFT_TYPE_LINEAR);
    ui->checkBox_Res_PlotLine_FixRange_S->setChecked(true);
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->setValue(0);
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->setValue(120);

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
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Speed_Mean_04x05_10s.png");
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
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_Angle_Mean_04x05_10s.png");
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

    //linear speed analysis
    ui->comboBox_Res_Type->setCurrentIndex(RES_SPEED_ANALYSIS);
    ui->comboBox_Res_SpeedCustom_ShiftType->setCurrentIndex(SHIFT_TYPE_LINEAR);
    ui->checkBox_Res_PlotLine_FixRange_S->setChecked(true);
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->setValue(0);
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->setValue(120);

    //mean+-SD
    ui->comboBox_Res_SpeedCustom_Stat_Value->setCurrentIndex(c_STAT_MEAN_ARITMETIC);
    ui->comboBox_Res_SpeedCustom_Stat_Uncertanty->setCurrentIndex(c_STAT_STAN_DEV_SAMPLE);

    //mean+-SD 1s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(1.0);
    ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setValue(1.0);
    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_LINE);
    pChartView_Results_Line->grab().save(DIR_SaveStackPlot_Speed.path() + "/PlotLine_SpeedAnalysis_Linear_MeanSD_01s - " + name_current + ".png");
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_SpeedAnalysis_Linear_MeanSD_01s.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Line->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Linear speed vs Time 1x1 1s\n"
                "\n"
                "X-axis: Full time axis of video in seconds\n"
                "Y-Axis: Linear speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + " +/- " + ui->comboBox_Res_SpeedCustom_Stat_Uncertanty->currentText() + ")\n"
                "\n"
                "Unit is shift in um per second.\n"
                "Data is smoothed over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + " second(s) and full frame.\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "No spatial information contained.\n"
                "Useful to see linear speed vs time in full video considering short termed variation.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/PlotLine_SpeedAnalysis_Linear_MeanSD_01s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_SpeedAnalysis_Linear_MeanSD_01s.png");

    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_POINCARE);
    pChartView_Results_Poincare->grab().save(DIR_SaveStackPlot_Speed.path() + "/PlotPoincare_SpeedAnalysis_Linear_MeanSD_01s - " + name_current + ".png");
    pChartView_Results_Poincare->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotPoincare_SpeedAnalysis_Linear_MeanSD_01s.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Poincare->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Linear speed Variation 1x1 1s\n"
                "\n"
                "X-axis: Linear speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + ") at t+1s\n"
                "Y-Axis: Linear speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + ") at t\n"
                "\n"
                "Unit is shift in um per second.\n"
                "Data is smoothed over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + " second(s) and full frame.\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "No spatial information contained.\n"
                "Expansion in main diagonal (gray line) shows long term variation.\n"
                "Expansion in other diagonal shows short term variation.\n"
                "Useful to see different types of variation of linear speed.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/PlotPoincare_SpeedAnalysis_Linear_MeanSD_01s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotPoincare_SpeedAnalysis_Linear_MeanSD_01s.png");

    //mean+-SD 10s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(10.0);
    ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setValue(10.0);
    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_LINE);
    pChartView_Results_Line->grab().save(DIR_SaveStackPlot_Speed.path() + "/PlotLine_SpeedAnalysis_Linear_MeanSD_10s - " + name_current + ".png");
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_SpeedAnalysis_Linear_MeanSD_10s.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Line->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Linear speed vs Time 1x1 10s\n"
                "\n"
                "X-axis: Full time axis of video in seconds\n"
                "Y-Axis: Linear speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + " +/- " + ui->comboBox_Res_SpeedCustom_Stat_Uncertanty->currentText() + ")\n"
                "\n"
                "Unit is shift in um per second.\n"
                "Data is smoothed over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + " second(s) and full frame.\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "No spatial information contained.\n"
                "Useful to get an overview of linear speed vs time in full video.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/PlotLine_SpeedAnalysis_Linear_MeanSD_10s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_SpeedAnalysis_Linear_MeanSD_10s.png");

    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_POINCARE);
    pChartView_Results_Poincare->grab().save(DIR_SaveStackPlot_Speed.path() + "/PlotPoincare_SpeedAnalysis_Linear_MeanSD_10s - " + name_current + ".png");
    pChartView_Results_Poincare->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotPoincare_SpeedAnalysis_Linear_MeanSD_10s.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Poincare->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Linear speed variation 1x1 1s\n"
                "\n"
                "X-axis: Linear speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + ") at t+1s\n"
                "Y-Axis: Linear speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + ") at t\n"
                "\n"
                "Unit is shift in um per second.\n"
                "Data is smoothed over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + " second(s) and full frame.\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "No spatial information contained.\n"
                "Expansion in main diagonal (gray line) shows long term variation.\n"
                "Expansion in other diagonal shows short term variation.\n"
                "Useful to see different types of variation of linear speed.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/PlotPoincare_SpeedAnalysis_Linear_MeanSD_10s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotPoincare_SpeedAnalysis_Linear_MeanSD_10s.png");





    //angular speed analysis
    ui->comboBox_Res_Type->setCurrentIndex(RES_SPEED_ANALYSIS);
    ui->comboBox_Res_SpeedCustom_ShiftType->setCurrentIndex(SHIFT_TYPE_ANGULAR);
    ui->checkBox_Res_PlotLine_FixRange_S->setChecked(true);

    //mean+-SD
    ui->comboBox_Res_SpeedCustom_Stat_Value->setCurrentIndex(c_STAT_MEAN_ARITMETIC);
    ui->comboBox_Res_SpeedCustom_Stat_Uncertanty->setCurrentIndex(c_STAT_STAN_DEV_SAMPLE);

    //mean+-SD 1s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(1.0);
    ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setValue(1.0);
    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_LINE);
    pChartView_Results_Line->grab().save(DIR_SaveStackPlot_Speed.path() + "/PlotLine_SpeedAnalysis_Angular_MeanSD_01s - " + name_current + ".png");
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_SpeedAnalysis_Angular_MeanSD_01s.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Line->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Angular speed vs Time 1x1 1s\n"
                "\n"
                "X-axis: Full time axis of video in seconds\n"
                "Y-Axis: Angular speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + " +/- " + ui->comboBox_Res_SpeedCustom_Stat_Uncertanty->currentText() + ")\n"
                "\n"
                "Unit is shift in um per second.\n"
                "Data is smoothed over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + " second(s) and full frame.\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "No spatial information contained.\n"
                "Useful to see angular speed vs time in full video considering short termed variation.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/PlotLine_SpeedAnalysis_Angular_MeanSD_01s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_SpeedAnalysis_Angular_MeanSD_01s.png");

    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_POINCARE);
    pChartView_Results_Poincare->grab().save(DIR_SaveStackPlot_Speed.path() + "/PlotPoincare_SpeedAnalysis_Angular_MeanSD_01s - " + name_current + ".png");
    pChartView_Results_Poincare->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotPoincare_SpeedAnalysis_Angular_MeanSD_01s.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Poincare->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Angular speed Variation 1x1 1s\n"
                "\n"
                "X-axis: Angular speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + ") at t+1s\n"
                "Y-Axis: Angular speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + ") at t\n"
                "\n"
                "Unit is shift in um per second.\n"
                "Data is smoothed over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + " second(s) and full frame.\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "No spatial information contained.\n"
                "Expansion in main diagonal (gray line) shows long term variation.\n"
                "Expansion in other diagonal shows short term variation.\n"
                "Useful to see different types of variation of angular speed.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/PlotPoincare_SpeedAnalysis_Angular_MeanSD_01s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotPoincare_SpeedAnalysis_Angular_MeanSD_01s.png");

    //mean+-SD 10s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(10.0);
    ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setValue(10.0);
    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_LINE);
    pChartView_Results_Line->grab().save(DIR_SaveStackPlot_Speed.path() + "/PlotLine_SpeedAnalysis_Angular_MeanSD_10s - " + name_current + ".png");
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_SpeedAnalysis_Angular_MeanSD_10s.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Line->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Angular speed vs Time 1x1 10s\n"
                "\n"
                "X-axis: Full time axis of video in seconds\n"
                "Y-Axis: Angular speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + " +/- " + ui->comboBox_Res_SpeedCustom_Stat_Uncertanty->currentText() + ")\n"
                "\n"
                "Unit is shift in um per second.\n"
                "Data is smoothed over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + " second(s) and full frame.\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "No spatial information contained.\n"
                "Useful to get an overview of angular speed vs time in full video.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/PlotLine_SpeedAnalysis_Angular_MeanSD_10s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotLine_SpeedAnalysis_Angular_MeanSD_10s.png");

    ui->tabWidget_ResType->setCurrentIndex(RES_TYPE_POINCARE);
    pChartView_Results_Poincare->grab().save(DIR_SaveStackPlot_Speed.path() + "/PlotPoincare_SpeedAnalysis_Angular_MeanSD_10s - " + name_current + ".png");
    pChartView_Results_Poincare->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotPoincare_SpeedAnalysis_Angular_MeanSD_10s.png");
    Update_Ui();
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Poincare->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Angular speed variation 1x1 1s\n"
                "\n"
                "X-axis: Angular speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + ") at t+1s\n"
                "Y-Axis: Angular speed (" + ui->comboBox_Res_SpeedCustom_Stat_Value->currentText() + ") at t\n"
                "\n"
                "Unit is shift in um per second.\n"
                "Data is smoothed over " + QString::number(ui->doubleSpinBox_Res_MovAv_WindowTime->value()) + " second(s) and full frame.\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point.\n"
                "\n"
                "No spatial information contained.\n"
                "Expansion in main diagonal (gray line) shows long term variation.\n"
                "Expansion in other diagonal shows short term variation.\n"
                "Useful to see different types of variation of angular speed.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/PlotPoincare_SpeedAnalysis_Angular_MeanSD_10s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - PlotPoincare_SpeedAnalysis_Angular_MeanSD_10s.png");






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

    //histograms
    ui->comboBox_Res_Type->setCurrentIndex(RES_HISTOGRAM);
    ui->checkBox_Res_Histo_Uni->setChecked(true);
    ui->checkBox_Res_Histo_VariationAsColorValue->setChecked(true);

    //non accumulated
    ui->checkBox_Res_Histo_Acc->setChecked(false);

    //linear speed
    ui->comboBox_Res_Histo_Type->setCurrentIndex(HIST_LINEAR_SPEED);
    Update_Ui();
    pChartView_Results_Line->grab().save(DIR_SaveStackPlot_Speed.path() + "/Plot_Histogram_NonAccumulated_LinearSpeed - " + name_current + ".png");
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - Plot_Histogram_NonAccumulated_LinearSpeed.png");
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Line->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Linear speed histogram\n"
                "\n"
                "X-axis: Linear speed (separated in " + QString::number(ui->spinBox_Res_Histo_Classes_Speed->value()) + " classes)\n"
                "Y-Axis: Realtive amount\n"
                "Not accumulated\n"
                "\n"
                "Base analysis data: Linear speed\n"
                "Color codes mean distance to vortex center of elements in speed class (blue = near, red = far).\n"
                "\n"
                "No spatial or time information contained.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/Plot_Histogram_NonAccumulated_LinearSpeed - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - Plot_Histogram_NonAccumulated_LinearSpeed.png");

    //angular speed
    ui->comboBox_Res_Histo_Type->setCurrentIndex(HIST_ANGULAR_SPEED);
    Update_Ui();
    pChartView_Results_Line->grab().save(DIR_SaveStackPlot_Speed.path() + "/Plot_Histogram_NonAccumulated_AngularSpeed - " + name_current + ".png");
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - Plot_Histogram_NonAccumulated_AngularSpeed.png");
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Line->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Angular speed histogram\n"
                "\n"
                "X-axis: Angular speed (separated in " + QString::number(ui->spinBox_Res_Histo_Classes_Speed->value()) + " classes)\n"
                "Y-Axis: Realtive amount\n"
                "Not accumulated\n"
                "\n"
                "Base analysis data: Angular speed\n"
                "Color codes mean distance to vortex center of elements in speed class (blue = near, red = far).\n"
                "\n"
                "No spatial or time information contained.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/Plot_Histogram_NonAccumulated_AngularSpeed - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - Plot_Histogram_NonAccumulated_AngularSpeed.png");


    //distance to vortex center speed
    ui->comboBox_Res_Histo_Type->setCurrentIndex(HIST_DIST_CENTER_INTERSECTIONS);
    Update_Ui();
    pChartView_Results_Line->grab().save(DIR_SaveStackPlot_Vortex.path() + "/Plot_Histogram_NonAccumulated_DistanceVortexCenterToIntersections - " + name_current + ".png");
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - Plot_Histogram_NonAccumulated_DistanceVortexCenterToIntersections.png");
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Line->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Distance from vortex center to intersections histogram\n"
                "\n"
                "X-axis: Distance from vortex center to intersections (separated in " + QString::number(ui->spinBox_Res_Histo_Classes_Speed->value()) + " classes)\n"
                "Y-Axis: Realtive amount\n"
                "Not accumulated\n"
                "\n"
                "Base analysis data: Distance from vortex center to intersections\n"
                "Color codes mean distance to vortex center of elements in speed class (blue = near, red = far).\n"
                "\n"
                "No spatial or time information contained.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Vortex.path() + "/Plot_Histogram_NonAccumulated_DistanceVortexCenterToIntersections - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - Plot_Histogram_NonAccumulated_DistanceVortexCenterToIntersections.png");


    //accumulated
    ui->checkBox_Res_Histo_Acc->setChecked(true);

    //linear speed
    ui->comboBox_Res_Histo_Type->setCurrentIndex(HIST_LINEAR_SPEED);
    Update_Ui();
    pChartView_Results_Line->grab().save(DIR_SaveStackPlot_Speed.path() + "/Plot_Histogram_Accumulated_LinearSpeed - " + name_current + ".png");
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - Plot_Histogram_Accumulated_LinearSpeed.png");
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Line->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Linear speed histogram\n"
                "\n"
                "X-axis: Linear speed (separated in " + QString::number(ui->spinBox_Res_Histo_Classes_Speed->value()) + " classes)\n"
                "Y-Axis: Realtive amount\n"
                "Accumulated\n"
                "\n"
                "Base analysis data: Linear speed\n"
                "Color codes mean distance to vortex center of elements in speed class (blue = near, red = far).\n"
                "\n"
                "No spatial or time information contained.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/Plot_Histogram_Accumulated_LinearSpeed - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - Plot_Histogram_Accumulated_LinearSpeed.png");

    //angular speed
    ui->comboBox_Res_Histo_Type->setCurrentIndex(HIST_ANGULAR_SPEED);
    Update_Ui();
    pChartView_Results_Line->grab().save(DIR_SaveStackPlot_Speed.path() + "/Plot_Histogram_Accumulated_AngularSpeed - " + name_current + ".png");
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - Plot_Histogram_Accumulated_AngularSpeed.png");
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Line->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Angular speed histogram\n"
                "\n"
                "X-axis: Angular speed (separated in " + QString::number(ui->spinBox_Res_Histo_Classes_Speed->value()) + " classes)\n"
                "Y-Axis: Realtive amount\n"
                "Accumulated\n"
                "\n"
                "Base analysis data: Angular speed\n"
                "Color codes mean distance to vortex center of elements in speed class (blue = near, red = far).\n"
                "\n"
                "No spatial or time information contained.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Speed.path() + "/Plot_Histogram_Accumulated_AngularSpeed - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - Plot_Histogram_Accumulated_AngularSpeed.png");


    //distance to vortex center speed
    ui->comboBox_Res_Histo_Type->setCurrentIndex(HIST_DIST_CENTER_INTERSECTIONS);
    Update_Ui();
    pChartView_Results_Line->grab().save(DIR_SaveStackPlot_Vortex.path() + "/Plot_Histogram_Accumulated_DistanceVortexCenterToIntersections - " + name_current + ".png");
    pChartView_Results_Line->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - Plot_Histogram_Accumulated_DistanceVortexCenterToIntersections.png");
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = pChartView_Results_Line->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Distance from vortex center to intersections histogram\n"
                "\n"
                "X-axis: Distance from vortex center to intersections (separated in " + QString::number(ui->spinBox_Res_Histo_Classes_Speed->value()) + " classes)\n"
                "Y-Axis: Realtive amount\n"
                "Accumulated\n"
                "\n"
                "Base analysis data: Distance from vortex center to intersections\n"
                "Color codes mean distance to vortex center of elements in speed class (blue = near, red = far).\n"
                "\n"
                "No spatial or time information contained.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Vortex.path() + "/Plot_Histogram_Accumulated_DistanceVortexCenterToIntersections - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - Plot_Histogram_Accumulated_DistanceVortexCenterToIntersections.png");

    ui->checkBox_Res_Histo_Acc->setChecked(false);

    //......................

    //overview old
    ui->comboBox_Res_Type->setCurrentIndex(RES_OVERVIEW1);

    ui->comboBox_Res_SpeedCustom_ShiftType->setCurrentIndex(SHIFT_TYPE_LINEAR);

    //1s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(1.0);
    ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setValue(1.0);
    Update_Ui();
    ui->page_Res_Overview->grab().save(DIR_SaveStackPlot_Overview.path() + "/Overview_LinePoincare_01s - " + name_current + ".png");
    ui->page_Res_Overview->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - Overview_LinePoincare_01s.png");
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
                DIR_SaveStackPlot_Overview.path() + "/Overview_LinePoincare_01s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - Overview_LinePoincare_01s.png");

    //10s
    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(10.0);
    ui->doubleSpinBox_Res_PlotPoincare_Shift_Seconds->setValue(10.0);
    Update_Ui();
    ui->page_Res_Overview->grab().save(DIR_SaveStackPlot_Overview.path() + "/Overview_LinePoincare_10s - " + name_current + ".png");
    ui->page_Res_Overview->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - Overview_LinePoincare_10s.png");
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
                DIR_SaveStackPlot_Overview.path() + "/Overview_LinePoincare_10s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - Overview_LinePoincare_10s.png");



    //overview new
    ui->comboBox_Res_Type->setCurrentIndex(RES_OVERVIEW2);

    ui->doubleSpinBox_Res_MovAv_WindowTime->setValue(10.0);
    Update_Ui();
    ui->page_Res_OverviewNew->grab().save(DIR_SaveStackPlot_Overview.path() + "/Overview_LineHist_10s - " + name_current + ".png");
    ui->page_Res_OverviewNew->grab().save(DIR_SaveCurrentPlot.path() + "/" + name_current + " - Overview_LineHist_10s.png");
    PDF_Overview.add_NewPage();
    QI_ImgSave_tmp = ui->page_Res_OverviewNew->grab().toImage();
    PDF_Overview.add_Image(
                &QI_ImgSave_tmp,
                "Overview 10s (histograms and linear plots)\n"
                "\n"
                "Shows a summuary of other plots from this analysis (on previous pages).\n"
                "Only chunks with at least one movement detetction per frame in at least " + QString::number(ui->doubleSpinBox_Res_MovAv_ReqFrmWithDetect->value()) + "% of candidate frames generate a data point in linear plots.\n"
                "\n"
                "Image can be found in:\n" +
                DIR_SaveStackPlot_Overview.path() + "/Overview_LineHist_10s - " + name_current + ".png" +
                DIR_SaveCurrentPlot.path() + "/" + name_current + " - Overview_LineHist_10s.png");
    PDF_Summary.add_Image(
                &QI_ImgSave_tmp,
                x_border_left, x_border_right, y_plot_t, y_plot_b);


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
        //qDebug() << "Save_ResultVectorFieldVideo quit because:" << "Requirements not met";
        return;
    }

    if(!ui->action_Save_vectorfield_videos_on_analysis->isChecked())
        return;

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
        //qDebug() << "Save_ResultVectorFieldVideo quit because:" << "!VW_Out.is_Init()";
        return;
    }

    //loop video
    for(int frame = frame_start; frame <= frame_end; frame++)
    {
        //qDebug() << "Save_ResultVectorFieldVideo - Frame" << frame;

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

    //fill lists for easy access
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
    state_vortex_center_calced = false;

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
    state_vortex_center_calced = false;
}

void D_MAKRO_CiliaSphereTracker::Data_SelectVideo()
{
    state_VideoSelected = false;
    state_RoiTimeSelected = false;
    state_RoiSpaceSelected = false;
    state_TimeProjectInit = false;
    state_set_VidProcUp2date(false);
    state_GridSamplingSplit = false;
    state_vortex_center_calced = false;


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

    Data_GetSetVideoPos_Current();
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

double D_MAKRO_CiliaSphereTracker::Data_GetVideoPos(QFileInfo FI_Video)
{
    //analyse file name to find position in well
    QString QS_Name = FI_Video.baseName();

    //check if ends with 3 character number
    bool ok;
    double rel_pos = QS_Name.right(3).toDouble(&ok) / 100.0;
    if(ok)
        return rel_pos;

    //check set 1
    QStringList QSL_Set1 = ui->lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set1->text().split(",");
    for(int i = 0; i < QSL_Set1.size(); i++)
        if(QS_Name.endsWith(QSL_Set1[i]))
            return ui->doubleSpinBox_Res_VortexCenter_RelPos_H_Set1->value() / 100.0;

    //check set 2
    QStringList QSL_Set2 = ui->lineEdit_Res_VortexCenter_VideoPos_FilenameEnd_Set2->text().split(",");
    for(int i = 0; i < QSL_Set2.size(); i++)
        if(QS_Name.endsWith(QSL_Set2[i]))
            return ui->doubleSpinBox_Res_VortexCenter_RelPos_H_Set2->value() / 100.0;

    //default
    return 0.5;
}

double D_MAKRO_CiliaSphereTracker::Data_GetSetVideoPos_Current()
{
    double index = ui->comboBox_Data_Videos->currentIndex();
    double pos = index < FIL_Videos.size() ? Data_GetVideoPos(FIL_Videos[index]) : 0.5;
    ui->doubleSpinBox_Res_VortexCenter_RelPos_H_Use->setValue(pos * 100);
    return pos;
}

void D_MAKRO_CiliaSphereTracker::Data_CalcFullVideoStats()
{
    state_StatSummaryCalced = false;

    //shift scaling (shift/frame -> shift/second)
    double conv_perFrame2perSecond = VS_InputVideo.get_FrameRateFps();  //before stats calcs
    double conv_px_per_frm_2_um_per_s = conv_perFrame2perSecond * conv_px2um;

    //gathered containers
    vShiftsAll_px_frm.clear();
    vShiftsAll_um_s.clear();
    vAnglesAll_Rad.clear();
    vAnglesAll_Grad.clear();

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
    if(!vShiftsAll_px_frm.empty())
        ERR(D_Stat::Calc_Stats(
                &v_VideoStats_Shifts_px_frm,
                vShiftsAll_px_frm,
                true),
            "Data_CalcFullVideoStats",
            "Calc_Stats (px/frm)");
    else
        v_VideoStats_Shifts_px_frm.resize(c_STAT_NUMBER_OF_STATS, 0);

    if(!vShiftsAll_um_s.empty())
        ERR(D_Stat::Calc_Stats(
                &v_VideoStats_Shifts_um_s,
                vShiftsAll_um_s,
                true),
            "Data_CalcFullVideoStats",
            "Calc_Stats (um/s)");
    else
        v_VideoStats_Shifts_um_s.resize(c_STAT_NUMBER_OF_STATS, 0);

    if(!vAnglesAll_Rad.empty())
        ERR(D_Stat::Calc_Stats_Circ_Rad(
                &v_VideoStats_Angles_Rad,
                vAnglesAll_Rad),
            "Data_CalcFullVideoStats",
            "Calc_Stats_Circ_Rad");
    else
        v_VideoStats_Angles_Rad.resize(c_STAT_CIRC_NUMBER_OF, 0);

    if(!vAnglesAll_Grad.empty())
        ERR(D_Stat::Calc_Stats_Circ_Grad(
                &v_VideoStats_Angles_Grad,
                vAnglesAll_Grad),
            "Data_CalcFullVideoStats",
            "Calc_Stats_Circ_Grad");
    else
        v_VideoStats_Angles_Grad.resize(c_STAT_CIRC_NUMBER_OF, 0);

    state_StatSummaryCalced = true;
    qDebug() << "D_MAKRO_CiliaSphereTracker::Data_CalcFullVideoStats" << "start";
}

void D_MAKRO_CiliaSphereTracker::Data_CalcFullVideoStats_AngularSpeed()
{
    state_StatSummaryCalced_angularSpeed = false;

    if(!state_vortex_center_calced)
        Update_Result_GraphicsVortexCenter();
    if(!state_vortex_center_calced)
        return;

    //clear
    vShiftsAll_grad_s.clear();
    vDistancesToVortexCenter_All_um.clear();

    //gather
    for(size_t frm = 0; frm < vv_FrmObjShifts.size(); frm++)
        for(size_t obj = 0; obj < vv_FrmObjShifts[frm].size(); obj++)
        {
            double dx = vv_FrmObjPositions[frm][obj].x - P_VortexCenter.x();
            double dy = vv_FrmObjPositions[frm][obj].y - P_VortexCenter.y();
            double dist = sqrt(dx * dx + dy * dy);

            vDistancesToVortexCenter_All_um.push_back(dist);
            vShiftsAll_grad_s.push_back(dist > 0 ? (vv_FrmObjShifts[frm][obj] / dist) * Rad2Grad : 0);
        }

    if(!vShiftsAll_grad_s.empty())
        ERR(D_Stat::Calc_Stats(
                &v_VideoStats_Shifts_grad_s,
                vShiftsAll_grad_s,
                true),
            "Data_CalcFullVideoStats_AngularSpeed",
            "Calc_Stats (shift °/s)");
    else
        v_VideoStats_Shifts_grad_s.resize(c_STAT_NUMBER_OF_STATS, 0);

    if(!vDistancesToVortexCenter_All_um.empty())
        ERR(D_Stat::Calc_Stats(
                &v_VideoStats_DistancesToVortexCenter_All_um,
                vDistancesToVortexCenter_All_um,
                true),
            "Data_CalcFullVideoStats_AngularSpeed",
            "Calc_Stats (dist um)");
    else
        v_VideoStats_DistancesToVortexCenter_All_um.resize(c_STAT_NUMBER_OF_STATS, 0);

    state_StatSummaryCalced_angularSpeed = true;
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
    ui->groupBox_Res_GraphicsParam->setVisible      (res_type == RES_GRAPHICS_FIELD_SUMMARY     || res_type == RES_GRAPHICS_TIME_SUM_PROJ                                                                                || res_type == RES_GRAPHICS_VECTORS);
    ui->groupBox_Res_GridSamplingParam->setVisible  (res_type == RES_GRAPHICS_FIELD_SUMMARY     ||                                           res_type == RES_SPEED_STAT_CUSTOM   || res_type == RES_ANGLE_STAT_CUSTOM    || res_type == RES_GRAPHICS_VECTORS     || res_type == RES_GRAPHICS_VORTEX_CENTER);
    ui->groupBox_Res_GridVisParam->setVisible       (res_type == RES_GRAPHICS_FIELD_SUMMARY     ||                                                                                                                          res_type == RES_GRAPHICS_VECTORS);
    ui->groupBox_Res_VectorFieldParam->setVisible   (res_type == RES_GRAPHICS_FIELD_SUMMARY     ||                                                                                                                          res_type == RES_GRAPHICS_VECTORS);
    ui->groupBox_Res_TimeAxis->setVisible           (                                                                                        res_type == RES_SPEED_STAT_CUSTOM   || res_type == RES_ANGLE_STAT_CUSTOM                                                                                || res_type == RES_SPEED_ANALYSIS   || res_type == RES_ANGLE_ANALYSIS   || res_type == RES_OVERVIEW1 || res_type == RES_OVERVIEW2);
    ui->groupBox_Res_SpeedCustom->setVisible        (                                           res_type == RES_SPEED_STAT_CUSTOM                                                                                                                       || res_type == RES_SPEED_ANALYSIS                                       || res_type == RES_OVERVIEW1 || res_type == RES_OVERVIEW2);
    ui->groupBox_Res_AngleCustom->setVisible        (                                                                                                                               res_type == RES_ANGLE_STAT_CUSTOM                                                                                                                    || res_type == RES_ANGLE_ANALYSIS   || res_type == RES_OVERVIEW1);
    ui->groupBox_Res_MovAv->setVisible              (                                                                                        res_type == RES_SPEED_STAT_CUSTOM   || res_type == RES_ANGLE_STAT_CUSTOM    || res_type == RES_GRAPHICS_VECTORS                                         || res_type == RES_SPEED_ANALYSIS   || res_type == RES_ANGLE_ANALYSIS   || res_type == RES_OVERVIEW1 || res_type == RES_OVERVIEW2 || (res_type == RES_GRAPHICS_VORTEX_CENTER && ui->checkBox_Res_VortexCenter_MovingAverage->isChecked()));
    ui->groupBox_Res_Heat->setVisible               (                                                                                                                                                               res_type == RES_GRAPHICS_HEATMAP);
    ui->groupBox_Res_Histo->setVisible              (                                                                                                                                                                                                            res_type == RES_HISTOGRAM);
    ui->groupBox_Res_VortexCenter->setVisible       (                                                                                                                                                                                                            res_type == RES_GRAPHICS_VORTEX_CENTER);
    ui->groupBox_Res_FieldSumary->setVisible        (res_type == RES_GRAPHICS_FIELD_SUMMARY);

    //subelements
    ui->spinBox_ParamGrid_CellStart->setEnabled     (                                           res_type == RES_SPEED_STAT_CUSTOM   || res_type == RES_ANGLE_STAT_CUSTOM);
    ui->spinBox_ParamGrid_CellEnd->setEnabled       (                                           res_type == RES_SPEED_STAT_CUSTOM   || res_type == RES_ANGLE_STAT_CUSTOM);
    ui->spinBox_Res_MovAv_CurrentFrame->setEnabled  (                                                                                                                          res_type == RES_GRAPHICS_VECTORS);
    ui->doubleSpinBox_Res_MovAv_CurrentTime->setEnabled(                                                                                                                       res_type == RES_GRAPHICS_VECTORS);
    ui->spinBox_Res_MovAv_WindowFrames->setEnabled  (                                           res_type == RES_SPEED_STAT_CUSTOM   || res_type == RES_ANGLE_STAT_CUSTOM    || res_type == RES_GRAPHICS_VECTORS                                         || res_type == RES_SPEED_ANALYSIS   || res_type == RES_ANGLE_ANALYSIS   || res_type == RES_OVERVIEW1 || res_type == RES_OVERVIEW2);
    ui->doubleSpinBox_Res_MovAv_WindowTime->setEnabled(                                         res_type == RES_SPEED_STAT_CUSTOM   || res_type == RES_ANGLE_STAT_CUSTOM    || res_type == RES_GRAPHICS_VECTORS                                         || res_type == RES_SPEED_ANALYSIS   || res_type == RES_ANGLE_ANALYSIS   || res_type == RES_OVERVIEW1 || res_type == RES_OVERVIEW2);
    ui->comboBox_Res_MovAv_Background->setEnabled   (                                                                                                                          res_type == RES_GRAPHICS_VECTORS);
    ui->comboBox_Res_MovAv_TimeWindow->setEnabled   (                                                                                                                          res_type == RES_GRAPHICS_VECTORS);
    ui->horizontalSlider_Res_MovAv_CurrentStart->setEnabled(                                                                                                                   res_type == RES_GRAPHICS_VECTORS);
    ui->horizontalSlider_Res_MovAv_CurrentEnd->setEnabled(                                                                                                                     res_type == RES_GRAPHICS_VECTORS);

    //plot range
    ui->checkBox_Res_PlotLine_FixRange_S->setEnabled(res_type == RES_SPEED_STAT_CUSTOM || res_type == RES_SPEED_ANALYSIS || res_type == RES_OVERVIEW1 || res_type == RES_OVERVIEW2);
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->setEnabled((res_type == RES_SPEED_STAT_CUSTOM || res_type == RES_SPEED_ANALYSIS || res_type == RES_OVERVIEW1 || res_type == RES_OVERVIEW2) && ui->checkBox_Res_PlotLine_FixRange_S->isChecked());
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->setEnabled((res_type == RES_SPEED_STAT_CUSTOM || res_type == RES_SPEED_ANALYSIS || res_type == RES_OVERVIEW1 || res_type == RES_OVERVIEW2) && ui->checkBox_Res_PlotLine_FixRange_S->isChecked());
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->setEnabled((res_type == RES_SPEED_STAT_CUSTOM || res_type == RES_SPEED_ANALYSIS || res_type == RES_OVERVIEW1 || res_type == RES_OVERVIEW2) && ui->checkBox_Res_PlotLine_FixRange_S->isChecked());
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->setEnabled((res_type == RES_SPEED_STAT_CUSTOM || res_type == RES_SPEED_ANALYSIS || res_type == RES_OVERVIEW1 || res_type == RES_OVERVIEW2) && ui->checkBox_Res_PlotLine_FixRange_S->isChecked());
    ui->checkBox_Res_PlotLine_FixRange_A->setEnabled(res_type == RES_ANGLE_STAT_CUSTOM || res_type == RES_ANGLE_ANALYSIS || res_type == RES_OVERVIEW1);
    ui->doubleSpinBox_Res_PlotLine_FixRange_A_min->setEnabled((res_type == RES_ANGLE_STAT_CUSTOM || res_type == RES_ANGLE_ANALYSIS || res_type == RES_OVERVIEW1) && ui->checkBox_Res_PlotLine_FixRange_A->isChecked());
    ui->doubleSpinBox_Res_PlotLine_FixRange_A_max->setEnabled((res_type == RES_ANGLE_STAT_CUSTOM || res_type == RES_ANGLE_ANALYSIS || res_type == RES_OVERVIEW1) && ui->checkBox_Res_PlotLine_FixRange_A->isChecked());

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
    if(res_type == RES_SPEED_STAT_CUSTOM || res_type == RES_SPEED_ANALYSIS || res_type == RES_OVERVIEW1 || res_type == RES_OVERVIEW2)
    {
        ui->label_Res_SpeedCustom_Stat_Uncertanty->setEnabled(res_type == RES_SPEED_ANALYSIS || res_type == RES_OVERVIEW1 || res_type == RES_OVERVIEW2);
        ui->comboBox_Res_SpeedCustom_Stat_Uncertanty->setEnabled(res_type == RES_SPEED_ANALYSIS || res_type == RES_OVERVIEW1 || res_type == RES_OVERVIEW2);
    }

    //angle uncertantiy stat plot
    if(res_type == RES_ANGLE_STAT_CUSTOM || res_type == RES_ANGLE_ANALYSIS || res_type == RES_OVERVIEW1)
    {
        ui->label_Res_AngleCustom_Stat_Uncertanty->setEnabled(res_type == RES_ANGLE_ANALYSIS || res_type == RES_OVERVIEW1);
        ui->comboBox_Res_AngleCustom_Stat_Uncertanty->setEnabled(res_type == RES_ANGLE_ANALYSIS || res_type == RES_OVERVIEW1);
    }
}


void D_MAKRO_CiliaSphereTracker::Update_Ui_ResMovAv()
{
    //qDebug() << "Update_Ui_ResMovAv" << "try" << "frame_start_ana" << frame_start_ana << "frame_end" << frame_end << "movav_current_start" << movav_current_start << "movav_window_frames" << movav_window_frames;

    if(!state_VideosLoaded || !state_VideoSelected || !state_RoiTimeSelected)
        return;

    //qDebug() << "Update_Ui_ResMovAv" << "start" << "frame_start_ana" << frame_start_ana << "frame_end" << frame_end << "movav_current_start" << movav_current_start << "movav_window_frames" << movav_window_frames;

    //checks and helping vars
    int frame_count_effective = frame_end - frame_start_ana;
    if(movav_window_frames > frame_count_effective)     movav_window_frames = frame_count_effective;
    if(movav_current_start < frame_start_ana)           movav_current_start = frame_start_ana;
    int max_start = frame_end - movav_window_frames;
    if(movav_current_start > max_start)                 movav_current_start = max_start;

    //qDebug() << "Update_Ui_ResMovAv" << "corrected" << "frame_start_ana" << frame_start_ana << "frame_end" << frame_end << "movav_current_start" << movav_current_start << "movav_window_frames" << movav_window_frames;

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

    //qDebug() << "Update_Ui_ResMovAv" << "end" << "frame_start_ana" << frame_start_ana << "frame_end" << frame_end << "movav_current_start" << movav_current_start << "movav_window_frames" << movav_window_frames;
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
    Populate_CB_Single(ui->comboBox_Proc_Step,                                  QSL_ProcSteps,      STEP_LOAD);
    Populate_CB_Single(ui->comboBox_Res_Type,                                   QSL_ResTypes,       RES_GRAPHICS_TIME_SUM_PROJ);
    Populate_CB_Single(ui->comboBox_Res_MovAv_Background,                       QSL_Background,     BACKGR_PROJECTION);
    Populate_CB_Single(ui->comboBox_Res_MovAv_TimeWindow,                       QSL_TimeWindow,     TIME_WINDOW_FULL_VIDEO);
    Populate_CB_Single(ui->comboBox_Res_PlotLine_FixRange_T,                    QSL_PlotTime,       PLOT_TIME_VIDEO_LENGTH);
    Populate_CB_Single(ui->comboBox_Res_Heat_Mode,                              QSL_HeatmapTypes,   HEAT_SPEED_LINEAR);
    Populate_CB_Single(ui->comboBox_Res_FieldSumary_StatType,                   QSL_DataTypes,      DATA_TYPE_ANGLE);

    //stats
    Populate_CB_Single(ui->comboBox_Res_VectorFieldParam_Length_Value,          QSL_StatList,       c_STAT_MEAN_ARITMETIC);
    Populate_CB_Single(ui->comboBox_Res_VectorFieldParam_Length_Error,          QSL_StatList,       c_STAT_STAN_DEV_SAMPLE);
    Populate_CB_Single(ui->comboBox_Res_SpeedCustom_Stat_Value,                 QSL_StatList,       c_STAT_MEAN_ARITMETIC);
    Populate_CB_Single(ui->comboBox_Res_SpeedCustom_Stat_Uncertanty,            QSL_StatList,       c_STAT_STAN_DEV_SAMPLE);
    Populate_CB_Single(ui->comboBox_Res_VectorFieldParam_Angle_Value,           QSL_StatListCirc,   c_STAT_CIRC_MEAN_ANG);
    Populate_CB_Single(ui->comboBox_Res_VectorFieldParam_Angle_Error,           QSL_StatListCirc,   c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA);
    Populate_CB_Single(ui->comboBox_Res_AngleCustom_Stat_Value,                 QSL_StatListCirc,   c_STAT_CIRC_MEAN_ANG);
    Populate_CB_Single(ui->comboBox_Res_AngleCustom_Stat_Uncertanty,            QSL_StatListCirc,   c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA);

    Populate_CB_Single(ui->comboBox_Res_FieldSumary_StatIndex_Cells_Linear,     QSL_StatList,       c_STAT_STAN_DEV_SAMPLE);
    Populate_CB_Single(ui->comboBox_Res_FieldSumary_StatIndex_Cells_Angular,    QSL_StatListCirc,   c_STAT_CIRC_UNBALANCE);
    Populate_CB_Single(ui->comboBox_Res_FieldSumary_StatIndex_Grid,             QSL_StatList,       c_STAT_MEAN_ARITMETIC);
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
    /*
    //pause task bar on error during stack processing
    if(state_StackProcessing)
        if(err != ER_okay)
            pTaskBarProgress->pause();
            */

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
    {
        state_StatSummaryCalced = false;
        state_StatSummaryCalced_angularSpeed = false;
    }
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
    if(index == RES_GRAPHICS_TIME_SUM_PROJ || index == RES_GRAPHICS_VECTORS || index == RES_GRAPHICS_HEATMAP || index == RES_GRAPHICS_VORTEX_CENTER || index == RES_GRAPHICS_FIELD_SUMMARY)
        ui->stackedWidget_Res_Type->setCurrentIndex(0);
    else if(index == RES_OVERVIEW1)
        ui->stackedWidget_Res_Type->setCurrentIndex(2);
    else if(index == RES_OVERVIEW2)
        ui->stackedWidget_Res_Type->setCurrentIndex(3);
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
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_linear->setEnabled(arg1);
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_linear->setEnabled(arg1);
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_min_angular->setEnabled(arg1);
    ui->doubleSpinBox_Res_PlotLine_FixRange_S_max_angular->setEnabled(arg1);
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

void D_MAKRO_CiliaSphereTracker::on_checkBox_Res_VortexCenter_MovingAverage_stateChanged(int arg1)
{
    ui->groupBox_Res_MovAv->setVisible(arg1);
}

void D_MAKRO_CiliaSphereTracker::on_checkBox_Res_VortexCenter_Ransac_stateChanged(int arg1)
{
    ui->doubleSpinBox_Res_VortexCenter_RansacSubsetSize->setEnabled(arg1);
    ui->spinBox_Res_VortexCenter_RansacIterations->setEnabled(arg1);
    ui->comboBox_Res_VortexCenter_Ransac_PointsOrLines->setEnabled(arg1);
}

void D_MAKRO_CiliaSphereTracker::on_checkBox_Res_VortexCenter_kMeans_stateChanged(int arg1)
{
    //ui->spinBox_Res_VortexCenter_kMeans_k->setEnabled(arg1);
    //ui->spinBox_Res_VortexCenter_kMeans_Iterations->setEnabled(arg1);
}

void D_MAKRO_CiliaSphereTracker::on_doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec_valueChanged(double arg1)
{
    ui->spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm->blockSignals(true);
    ui->spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm->setValue(arg1 / VS_InputVideo.get_frame_2_timeSec());
    ui->spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm->blockSignals(false);
    Update_Results();
}

void D_MAKRO_CiliaSphereTracker::on_spinBox_Res_VortexCenter_MoveingAverage_TimeWindow_frm_valueChanged(int arg1)
{
    ui->doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec->blockSignals(true);
    ui->doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec->setValue(arg1 * VS_InputVideo.get_frame_2_timeSec());
    ui->doubleSpinBox_Res_VortexCenter_MoveingAverage_TimeWindow_sec->blockSignals(false);
    Update_Results();
}

void D_MAKRO_CiliaSphereTracker::on_comboBox_Res_VectorFieldParam_ShiftType_currentIndexChanged(int index)
{
    ui->comboBox_Res_VectorFieldParam_Angle_Value->setEnabled(index == SHIFT_TYPE_LINEAR);
    ui->comboBox_Res_VectorFieldParam_Angle_Error->setEnabled(index == SHIFT_TYPE_LINEAR);
    ui->label_Res_VectorFieldParam_Angle->setEnabled(index == SHIFT_TYPE_LINEAR);
}

void D_MAKRO_CiliaSphereTracker::on_comboBox_Res_Histo_Type_currentIndexChanged(int index)
{
    if(index == HIST_DIST_CENTER_INTERSECTIONS)
        ui->stackedWidget_HistClasses->setCurrentIndex(1);
    else
        ui->stackedWidget_HistClasses->setCurrentIndex(0);
}


void D_MAKRO_CiliaSphereTracker::on_pushButton_Param_CropTime_To1s_clicked()
{
    ui->doubleSpinBox_Param_Crop_End->setValue(VS_InputVideo.get_DurationSec() - ui->doubleSpinBox_Param_Crop_Start->value() - 1);
}

void D_MAKRO_CiliaSphereTracker::on_comboBox_Res_FieldSumary_StatType_currentIndexChanged(int index)
{
    ui->stackedWidget_Res_FieldSumary_StatType->setCurrentIndex(index == DATA_TYPE_ANGLE ? 1 : 0);
}
