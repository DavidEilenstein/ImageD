/************************************
 *   added:     11.09.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_stepwindow.h"
#include "ui_d_stepwindow.h"

D_StepWindow::D_StepWindow(D_Storage *pStorage, vector<D_StepWindow *> *pSteps_inMW, vector<int> vDefaults, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_StepWindow)
{
    //Ui
    ui->setupUi(this);

    //VIEWER
    Viewer.set_GV(ui->graphicsView_Viewer);
    Viewer.set_Name("Stepwindow_" + QString::number(pos_Dest));
    Viewer.Set_Transformation_Mode(vDefaults[c_SD_VIEWER_TRANSFORMATION_SMOOTH]);
    Viewer.Set_Aspect_Mode(vDefaults[c_SD_VIEWER_ASPECT_KEEP]);
    pCV_Viewer = new QChartView(this);
    ui->gridLayout_FunctionView->addWidget(pCV_Viewer);
    Viewer.set_CV(pCV_Viewer);

    //3D Viewer
    Viewer_3D.init(ui->gridLayout_Viewer3D_TargetLayout);
    Viewer_3D.Set_StoragePointer(pStorage, dir_SAVE);

    //3D Viewer plot
    ViewerPlot_3D.init(ui->gridLayout_Output_3D);

    //HIST
    //Init chart and chartview
    Chart_Hist = new QChart();
    //Chart_Hist->createDefaultAxes();
    ChartView_Hist = new QChartView(this);
    ChartView_Hist->setChart(Chart_Hist);
    ui->gridLayout_Output_Hist->addWidget(ChartView_Hist);
    ChartView_Hist->setRenderHint(QPainter::Antialiasing);
    ChartView_Hist->setRubberBand(QChartView::RectangleRubberBand);
    ChartView_Hist->setInteractive(true);


    //TIMES
    //Init chart and chartview
    Chart_Times = new QChart();
    ChartView_Times = new QChartView(this);
    ChartView_Times->setChart(Chart_Times);
    ui->gridLayout_Output_Times->addWidget(ChartView_Times);
    ChartView_Times->setRenderHint(QPainter::Antialiasing);
    ChartView_Times->setInteractive(true);


    //STATUSBAR
    int LabelWidth = 25;
    int LabelHeight = 15;

    L_SB_ValAtPos = new QLabel(this);
    L_SB_ValAtPos->setMinimumSize(QSize(LabelWidth * 4, LabelHeight));
    L_SB_ValAtPos->setToolTip("Pixelvalue (Mouse hovered).");
    ui->statusbar->addPermanentWidget(L_SB_ValAtPos);

    L_SB_Pos = new QLabel(this);
    L_SB_Pos->setMinimumSize(QSize(LabelWidth * 4, LabelHeight));
    L_SB_Pos->setToolTip("Mouse hovered at pixel position.");
    ui->statusbar->addPermanentWidget(L_SB_Pos);

    L_SB_Range = new QLabel(this);
    L_SB_Range->setMinimumSize(QSize(LabelWidth * 4, LabelHeight));
    L_SB_Range->setToolTip("Range of image data.");
    ui->statusbar->addPermanentWidget(L_SB_Range);

    L_SB_Zoom = new QLabel(this);
    L_SB_Zoom->setMinimumSize(QSize(LabelWidth * 2, LabelHeight));
    L_SB_Zoom->setToolTip("How much the image is scaled to fit in the viewer (width x height or both).");
    ui->statusbar->addPermanentWidget(L_SB_Zoom);

    L_SB_Memory = new QLabel(this);
    L_SB_Memory->setMinimumSize(QSize(LabelWidth * 2, LabelHeight));
    L_SB_Memory->setToolTip("Memory of the image data (full 6D, not only shown)");
    ui->statusbar->addPermanentWidget(L_SB_Memory);

    L_SB_SizeType = new QLabel(this);
    L_SB_SizeType->setMinimumSize(QSize(LabelWidth * 5, LabelHeight));
    L_SB_SizeType->setToolTip("Size of the image (Bitdepth, signed/unsigned/float, C=Channels, X, Y, Z, T, S, P).");
    ui->statusbar->addPermanentWidget(L_SB_SizeType);

    //Storage handling
    pSteps = pSteps_inMW;
    pStore = pStorage;
    pStore->expand();
    ERR(
                D_Img_Proc::Load_From_Path(
                    pStore->get_Adress(pos_Dest),
                    pStore->default_img()->absoluteFilePath().toStdString())
                );
    pos_Dest = pStore->size() - 1;
    pos_Source1 = pos_Dest - 1;
    pos_Source2 = pos_Dest - 1;
    pos_Source3 = pos_Dest - 1;
    pos_Source4 = pos_Dest - 1;
    ui->spinBox_Source_Pos_1->setValue(pos_Source1);
    ui->spinBox_Source_Pos_2->setValue(pos_Source2);
    ui->spinBox_Source_Pos_3->setValue(pos_Source3);
    ui->spinBox_Source_Pos_4->setValue(pos_Source4);

    //Dims
    vDSB_Dims.clear();
    vDSB_Dims.resize(c_DIM_NUMBER_OF);
    vDSB_Dims[c_DIM_X] = ui->doubleSpinBox_View_Plane_X;
    vDSB_Dims[c_DIM_Y] = ui->doubleSpinBox_View_Plane_Y;
    vDSB_Dims[c_DIM_Z] = ui->doubleSpinBox_View_Plane_Z;
    vDSB_Dims[c_DIM_T] = ui->doubleSpinBox_View_Plane_T;
    vDSB_Dims[c_DIM_S] = ui->doubleSpinBox_View_Plane_S;
    vDSB_Dims[c_DIM_P] = ui->doubleSpinBox_View_Plane_P;
    vCHB_ProcDims.clear();
    vCHB_ProcDims.resize(c_DIM_NUMBER_OF);
    vCHB_ProcDims[c_DIM_X] = ui->checkBox_ProcDims_X_Proc;
    vCHB_ProcDims[c_DIM_Y] = ui->checkBox_ProcDims_Y_Proc;
    vCHB_ProcDims[c_DIM_Z] = ui->checkBox_ProcDims_Z_Proc;
    vCHB_ProcDims[c_DIM_T] = ui->checkBox_ProcDims_T_Proc;
    vCHB_ProcDims[c_DIM_S] = ui->checkBox_ProcDims_S_Proc;
    vCHB_ProcDims[c_DIM_P] = ui->checkBox_ProcDims_P_Proc;


    //Measure points init
    Measure_P1 = Point(0, 0);
    Measure_P2 = Point(0, 0);

    //LOAD FILE
    FI_Load_File.setFile(pStore->default_img()->absoluteFilePath());
    FI_RawFile.setFile(pStore->default_img()->absoluteFilePath());
    FIL_Load_Files = *(pStore->default_img_list());


    //CONNECTS
    //Update
    connect(ui->pushButton_Update_Step,                 SIGNAL(clicked(bool)),                      this,   SLOT(Update_Img_Proc()));
    connect(ui->action_Update_Step,                     SIGNAL(triggered(bool)),                    this,   SLOT(Update_Img_Proc()));
    connect(ui->pushButton_Update_Hist,                 SIGNAL(clicked(bool)),                      this,   SLOT(Update_Hist()));
    connect(ui->action_Update_Hist,                     SIGNAL(triggered(bool)),                    this,   SLOT(Update_Hist()));
    connect(ui->action_Autoupdate_Hist_on_HistSettings, SIGNAL(triggered(bool)),                    this,   SLOT(Connect_HistSettings_2_UpdateHist(bool)));
    connect(ui->pushButton_Update_Times,                SIGNAL(clicked(bool)),                      this,   SLOT(Update_Times()));
    connect(ui->action_Update_Times,                    SIGNAL(triggered(bool)),                    this,   SLOT(Update_Times()));
    connect(ui->action_Autoupdate_Times_on_TimesSettings, SIGNAL(triggered(bool)),                  this,   SLOT(Connect_TimesSettings_2_UpdateTimes(bool)));
    //Show
    connect(ui->action_Smooth_Transformation,           SIGNAL(triggered(bool)),                    this,   SLOT(Update_Image()));
    connect(ui->action_Keep_Aspect_Ratio,               SIGNAL(triggered(bool)),                    this,   SLOT(Update_Image()));
    //Save
    connect(ui->action_Save_Image,                      SIGNAL(triggered(bool)),                    this,   SLOT(Save_Image_Step()));
    connect(ui->action_Save_Image_List,                 SIGNAL(triggered(bool)),                    this,   SLOT(Save_ImageList_Step()));
    connect(ui->action_Save_asBinary,                   SIGNAL(triggered(bool)),                    this,   SLOT(Save_VisDat()));
    connect(ui->action_SaveScreenshot,                  SIGNAL(triggered(bool)),                    this,   SLOT(Save_Screenshot_Step()));
    connect(ui->action_Save_Feature_List,               SIGNAL(triggered(bool)),                    this,   SLOT(Save_Feature_List()));
    connect(ui->action_Save_Analysis,                   SIGNAL(triggered(bool)),                    this,   SLOT(Save_Analysis()));
    //Types
    connect(ui->spinBox_Source_Pos_1,                   SIGNAL(valueChanged(int)),                  this,   SLOT(Update_Type_Descriptions()));
    connect(ui->spinBox_Source_Pos_2,                   SIGNAL(valueChanged(int)),                  this,   SLOT(Update_Type_Descriptions()));
    connect(ui->spinBox_Source_Pos_3,                   SIGNAL(valueChanged(int)),                  this,   SLOT(Update_Type_Descriptions()));
    connect(ui->spinBox_Source_Pos_4,                   SIGNAL(valueChanged(int)),                  this,   SLOT(Update_Type_Descriptions()));
    //Filter
    connect(ui->comboBox_04_Blur_Type,                  SIGNAL(currentIndexChanged(int)),           this,   SLOT(FI_Blur_Adapt_Ui(int)));
    connect(ui->comboBox_04_Edge_Type,                  SIGNAL(currentIndexChanged(int)),           this,   SLOT(FI_Edge_Adapt_Ui(int)));
    connect(ui->comboBox_04_Special_Type,               SIGNAL(currentIndexChanged(int)),           this,   SLOT(FI_Spec_Adapt_Ui(int)));
    //Math
    connect(ui->comboBox_06_1Img_Type,                  SIGNAL(currentIndexChanged(int)),           this,   SLOT(MA_1Img_Adapt_Ui(int)));
    connect(ui->comboBox_06_2Img_Type,                  SIGNAL(currentIndexChanged(int)),           this,   SLOT(MA_2Img_Adapt_Ui(int)));
    //Connect connectors
    connect(ui->action_Autoupdate_ImgProc_on_Settings,  SIGNAL(triggered(bool)),                    this,   SLOT(Connect_ImgProcSettings_2_UpdateImgProc(bool)));
    //Source
    connect(ui->comboBox_Type_Main,                     SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->comboBox_Type_00_Source,                SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->comboBox_Type_01_Edit,                  SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->comboBox_Type_02_Convert,               SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->comboBox_Type_03_Elemental,             SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->comboBox_Type_04_Filter,                SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->comboBox_Type_05_Morphology,            SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->comboBox_Type_06_Math,                  SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->comboBox_Type_07_Transform,             SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->comboBox_Type_08_Feature,               SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->comboBox_Type_09_Other,                 SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->comboBox_Type_10_Dimension,             SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->spinBox_02_Merge_Channels,              SIGNAL(valueChanged(int)),                  this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->comboBox_04_Eilenstein_Type,            SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->comboBox_03_Thres_Type,                 SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->comboBox_04_Blur_Type,                  SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->comboBox_04_Statistic_MaskType,         SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    connect(ui->comboBox_04_RankOrder_MaskType,         SIGNAL(currentIndexChanged(int)),           this,   SLOT(AdaptUi_SourceNumber_ProcDims()));
    //Statusbar Updates and other info
    connect(&Viewer,                                    SIGNAL(MouseMoved_Value(QString)),          L_SB_ValAtPos,  SLOT(setText(QString)));
    connect(&Viewer,                                    SIGNAL(MouseClicked_Pos(int, int)),         this,           SLOT(Measure_SaveClick(int, int)));
    connect(ui->action_Measure_Line_Distance,           SIGNAL(triggered(bool)),                    this,           SLOT(Measure_LineDistance()));
    connect(&Viewer,                                    SIGNAL(Image_Size_Changed(QString)),        this,           SLOT(Update_Size_Info()));
    connect(&Viewer,                                    SIGNAL(Scaled_Factor_Prz(QString)),         L_SB_Zoom,      SLOT(setText(QString)));
    connect(&Viewer,                                    SIGNAL(TypeChanged_MA(QString)),            this,           SLOT(Update_Size_Info()));
    connect(&Viewer,                                    SIGNAL(MouseMoved_Pos(QString)),            L_SB_Pos,       SLOT(setText(QString)));
    connect(ui->action_Smooth_Transformation,           SIGNAL(triggered(bool)),                    &Viewer,        SLOT(Set_Transformation_Mode(bool)));
    connect(ui->action_Keep_Aspect_Ratio,               SIGNAL(triggered(bool)),                    &Viewer,        SLOT(Set_Aspect_Mode(bool)));
    connect(&Viewer,                                    SIGNAL(Time_Image_Cvt(uint)),               this,           SLOT(Update_Time_Img_Cvt(uint)));
    connect(&Viewer,                                    SIGNAL(Time_View_Update(uint)),             this,           SLOT(Update_Time_View_Update(uint)));
    connect(ui->checkBox_View_VisTrafo,                 SIGNAL(stateChanged(int)),                  &Viewer,        SLOT(Set_VisTrafo_ActiveInt(int)));
    connect(ui->doubleSpinBox_View_Min,                 SIGNAL(valueChanged(double)),               &Viewer,        SLOT(Set_VisTrafo_SpreadInMin(double)));
    connect(ui->doubleSpinBox_View_Max,                 SIGNAL(valueChanged(double)),               &Viewer,        SLOT(Set_VisTrafo_SpreadInMax(double)));
    connect(ui->doubleSpinBox_View_Gamma,               SIGNAL(valueChanged(double)),               &Viewer,        SLOT(Set_VisTrafo_Gamma(double)));
    connect(ui->doubleSpinBox_View_Center,              SIGNAL(valueChanged(double)),               &Viewer,        SLOT(Set_VisTrafo_Center(double)));
    connect(ui->doubleSpinBox_View_Divisor,             SIGNAL(valueChanged(double)),               &Viewer,        SLOT(Set_VisTrafo_Divisor(double)));
    connect(ui->doubleSpinBox_View_Anchor,              SIGNAL(valueChanged(double)),               &Viewer,        SLOT(Set_VisTrafo_Anchor(double)));
    connect(ui->doubleSpinBox_View_Range,               SIGNAL(valueChanged(double)),               &Viewer,        SLOT(Set_VisTrafo_Range(double)));
    connect(ui->comboBox_View_Complex,                  SIGNAL(currentIndexChanged(int)),           &Viewer,        SLOT(Set_VisTrafo_Mode_Complex(int)));
    connect(ui->comboBox_View_Crop,                     SIGNAL(currentIndexChanged(int)),           &Viewer,        SLOT(Set_VisTrafo_Mode_Crop(int)));
    connect(ui->comboBox_View_Transform,                SIGNAL(currentIndexChanged(int)),           &Viewer,        SLOT(Set_VisTrafo_Mode_Trafo(int)));
    connect(ui->comboBox_View_Anchor,                   SIGNAL(currentIndexChanged(int)),           &Viewer,        SLOT(Set_VisTrafo_Mode_Anchor(int)));
    connect(ui->comboBox_View_Range,                    SIGNAL(currentIndexChanged(int)),           &Viewer,        SLOT(Set_VisTrafo_Mode_Range(int)));
    connect(ui->comboBox_FunctionView_Mode,             SIGNAL(currentIndexChanged(int)),           &Viewer,        SLOT(Set_PlotType(int)));
    //View-Plane
    connect(ui->doubleSpinBox_View_Plane_X,             SIGNAL(valueChanged(double)),               this,           SLOT(Update_Image()));
    connect(ui->doubleSpinBox_View_Plane_Y,             SIGNAL(valueChanged(double)),               this,           SLOT(Update_Image()));
    connect(ui->doubleSpinBox_View_Plane_Z,             SIGNAL(valueChanged(double)),               this,           SLOT(Update_Image()));
    connect(ui->doubleSpinBox_View_Plane_T,             SIGNAL(valueChanged(double)),               this,           SLOT(Update_Image()));
    connect(ui->doubleSpinBox_View_Plane_S,             SIGNAL(valueChanged(double)),               this,           SLOT(Update_Image()));
    connect(ui->doubleSpinBox_View_Plane_P,             SIGNAL(valueChanged(double)),               this,           SLOT(Update_Image()));
    connect(ui->doubleSpinBox_View_Plane_X,             SIGNAL(valueChanged(double)),               this,           SLOT(Emitter_ViewPlanePosChanged()));
    connect(ui->doubleSpinBox_View_Plane_Y,             SIGNAL(valueChanged(double)),               this,           SLOT(Emitter_ViewPlanePosChanged()));
    connect(ui->doubleSpinBox_View_Plane_Z,             SIGNAL(valueChanged(double)),               this,           SLOT(Emitter_ViewPlanePosChanged()));
    connect(ui->doubleSpinBox_View_Plane_T,             SIGNAL(valueChanged(double)),               this,           SLOT(Emitter_ViewPlanePosChanged()));
    connect(ui->doubleSpinBox_View_Plane_S,             SIGNAL(valueChanged(double)),               this,           SLOT(Emitter_ViewPlanePosChanged()));
    connect(ui->doubleSpinBox_View_Plane_P,             SIGNAL(valueChanged(double)),               this,           SLOT(Emitter_ViewPlanePosChanged()));
    //Zoom
    connect(&Viewer,                                    SIGNAL(Zoomed(double,double,double)),       this,           SLOT(Emitter_ViewZoomChanged()));
    connect(ui->action_Zoom_In,                         SIGNAL(triggered(bool)),                    &Viewer,        SLOT(Zoom_In()));
    connect(ui->action_Zoom_Out,                        SIGNAL(triggered(bool)),                    &Viewer,        SLOT(Zoom_Out()));
    connect(ui->action_Zoom_Reset,                      SIGNAL(triggered(bool)),                    &Viewer,        SLOT(Zoom_Reset()));
    //ProcDims
    connect(ui->checkBox_ProcDims_X_Proc,               SIGNAL(clicked(bool)),                      this,           SLOT(ProcDimCountAdaptUi()));
    connect(ui->checkBox_ProcDims_Y_Proc,               SIGNAL(clicked(bool)),                      this,           SLOT(ProcDimCountAdaptUi()));
    connect(ui->checkBox_ProcDims_Z_Proc,               SIGNAL(clicked(bool)),                      this,           SLOT(ProcDimCountAdaptUi()));
    connect(ui->checkBox_ProcDims_T_Proc,               SIGNAL(clicked(bool)),                      this,           SLOT(ProcDimCountAdaptUi()));
    connect(ui->checkBox_ProcDims_S_Proc,               SIGNAL(clicked(bool)),                      this,           SLOT(ProcDimCountAdaptUi()));
    connect(ui->checkBox_ProcDims_P_Proc,               SIGNAL(clicked(bool)),                      this,           SLOT(ProcDimCountAdaptUi()));
    //Tests
    connect(ui->action_Features_Visualisation,          SIGNAL(triggered(bool)),                    this,           SLOT(Test_Feature_Visualize()));
    //3D plot
    connect(ui->comboBox_3D_Mode,                       SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
    connect(ui->comboBox_3D_Condition,                  SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
    connect(ui->comboBox_3D_ColorHandling,              SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
    connect(ui->comboBox_3D_Axis_X,                     SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
    connect(ui->comboBox_3D_Axis_Y,                     SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
    connect(ui->comboBox_3D_Axis_Z,                     SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
    connect(ui->comboBox_3D_Axis_V,                     SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
    connect(ui->comboBox_3D_Marker,                     SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
    connect(ui->comboBox_3D_ShadowQuality,              SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
    connect(ui->comboBox_3D_TextureMode_Heightmap,      SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
    connect(ui->comboBox_3D_2dPlane_Heightmap,          SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
    connect(ui->comboBox_3D_SurfaceMode,                SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
    connect(ui->comboBox_3D_SurfaceDimension,           SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
    connect(ui->checkBox_3D_Grid,                       SIGNAL(clicked(bool)),                      this,           SLOT(Update_3DPlot()));
    connect(ui->checkBox_3D_Background,                 SIGNAL(clicked(bool)),                      this,           SLOT(Update_3DPlot()));
    connect(ui->checkBox_3D_Smooth,                     SIGNAL(clicked(bool)),                      this,           SLOT(Update_3DPlot()));
    connect(ui->checkBox_3D_Surface,                    SIGNAL(clicked(bool)),                      this,           SLOT(Update_3DPlot()));
    connect(ui->checkBox_3D_Wireframe,                  SIGNAL(clicked(bool)),                      this,           SLOT(Update_3DPlot()));
    //3D viewer
    connect(ui->checkBox_View_VisTrafo,                 SIGNAL(stateChanged(int)),                  &Viewer_3D,     SLOT(Set_VisTrafo_ActiveInt(int)));
    connect(ui->doubleSpinBox_View_Min,                 SIGNAL(valueChanged(double)),               &Viewer_3D,     SLOT(Set_VisTrafo_SpreadInMin(double)));
    connect(ui->doubleSpinBox_View_Max,                 SIGNAL(valueChanged(double)),               &Viewer_3D,     SLOT(Set_VisTrafo_SpreadInMax(double)));
    connect(ui->doubleSpinBox_View_Gamma,               SIGNAL(valueChanged(double)),               &Viewer_3D,     SLOT(Set_VisTrafo_Gamma(double)));
    connect(ui->doubleSpinBox_View_Center,              SIGNAL(valueChanged(double)),               &Viewer_3D,     SLOT(Set_VisTrafo_Center(double)));
    connect(ui->doubleSpinBox_View_Divisor,             SIGNAL(valueChanged(double)),               &Viewer_3D,     SLOT(Set_VisTrafo_Divisor(double)));
    connect(ui->doubleSpinBox_View_Anchor,              SIGNAL(valueChanged(double)),               &Viewer_3D,     SLOT(Set_VisTrafo_Anchor(double)));
    connect(ui->doubleSpinBox_View_Range,               SIGNAL(valueChanged(double)),               &Viewer_3D,     SLOT(Set_VisTrafo_Range(double)));
    connect(ui->comboBox_View_Complex,                  SIGNAL(currentIndexChanged(int)),           &Viewer_3D,     SLOT(Set_VisTrafo_Mode_Complex(int)));
    connect(ui->comboBox_View_Crop,                     SIGNAL(currentIndexChanged(int)),           &Viewer_3D,     SLOT(Set_VisTrafo_Mode_Crop(int)));
    connect(ui->comboBox_View_Transform,                SIGNAL(currentIndexChanged(int)),           &Viewer_3D,     SLOT(Set_VisTrafo_Mode_Trafo(int)));
    connect(ui->comboBox_View_Anchor,                   SIGNAL(currentIndexChanged(int)),           &Viewer_3D,     SLOT(Set_VisTrafo_Mode_Anchor(int)));
    connect(ui->comboBox_View_Range,                    SIGNAL(currentIndexChanged(int)),           &Viewer_3D,     SLOT(Set_VisTrafo_Mode_Range(int)));

    //Default Options from Mainwindow
    ui->action_Autoupdate_ImgProc_on_Settings->setChecked(vDefaults[c_SD_AUTOUPDATE_ON_SETTINGS]);
    ui->action_Skip_Chain_Update->setChecked(vDefaults[c_SD_AUTOUPDATE_SKIP]);
    ui->action_connect_plane_position_to_other_steps->setChecked(vDefaults[c_SD_CONNECT_PLANE]);
    ui->action_Connect_Steps_Zoom->setChecked(vDefaults[c_SD_CONNECT_ZOOM]);
    ui->action_Keep_Aspect_Ratio->setChecked(vDefaults[c_SD_VIEWER_ASPECT_KEEP]);
    ui->action_Smooth_Transformation->setChecked(vDefaults[c_SD_VIEWER_TRANSFORMATION_SMOOTH]);

    //initial connects of autoupdates
    Connect_HistSettings_2_UpdateHist(true);
    Connect_TimesSettings_2_UpdateTimes(true);
    Connect_ImgProcSettings_2_UpdateImgProc(vDefaults[c_SD_AUTOUPDATE_ON_SETTINGS]);
    Connect_OtherSteps();

    //show (beofre cosmetic and other stuff interacting with the displayed window)
    this->show();

    //cosmetic
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    set_Position();
    ui->graphicsView_Viewer->setToolTip("Initialization image by Bahar Djouiai, GSI Darmstadt");


    //Hide stuff not needed by default
    FI_General_Adapt_Ui(0);
    FI_Blur_Adapt_Ui(0);
    FI_Edge_Adapt_Ui(0);
    FI_Spec_Adapt_Ui(0);
    MA_1Img_Adapt_Ui(0);
    MA_2Img_Adapt_Ui(0);
    Populate_CB_All();
    ui->comboBox_View_Crop->setVisible(false);
    ui->comboBox_View_Complex->setVisible(false);
    ui->comboBox_View_Transform->setVisible(false);
    ui->comboBox_View_Anchor->setVisible(false);
    ui->comboBox_View_Range->setVisible(false);
    ui->doubleSpinBox_View_Min->setVisible(false);
    ui->doubleSpinBox_View_Max->setVisible(false);
    ui->doubleSpinBox_View_Gamma->setVisible(false);
    ui->doubleSpinBox_View_Center->setVisible(false);
    ui->doubleSpinBox_View_Divisor->setVisible(false);
    ui->doubleSpinBox_View_Anchor->setVisible(false);
    ui->doubleSpinBox_View_Range->setVisible(false);
    //tab widget
    ui->tabWidget_Output->setCurrentIndex(c_Out_Image_2D);

    //Updates to init stuff
    Dim_GetFromVD();
    Scan_Examples_Dir();
    Update_Image();
    Update_Descriptions();
    Update_HistSettings();
    Update_Hist();
    Update_Times();
}

D_StepWindow::~D_StepWindow()
{
    delete ui;
}

void D_StepWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    Update_View();
    Viewer_3D.Update_Slices();
}

void D_StepWindow::closeEvent(QCloseEvent *event)
{
    if(ClosingPossible)
    {
        event->accept();
    }
    else
    {
        event->ignore();
        this->showMinimized();
    }
}

void D_StepWindow::set_Position()
{
    QRect rec = QApplication::desktop()->screenGeometry();
    unsigned int height = rec.height() - this->height() - 20;
    unsigned int width = rec.width() - this->width() - 20;

    this->move(
                (20 * (pos_Dest-1)) % width,
                (20 * (pos_Dest-1)) % (height - 40)
                );
}

void D_StepWindow::Update_Ui()
{
    this->setEnabled(false);
    this->repaint();
    qApp->processEvents();
    this->setEnabled(true);
}

void D_StepWindow::Update_from_extern()
{
    if(!ui->action_Skip_Chain_Update->isChecked())
    {
        Update_Img_Proc();
        Update_Ui();
    }

    Need_Update = false;
}

void D_StepWindow::set_chain_pos(unsigned int pos)
{
    pos_in_chain = pos;
    ui->label_Chain_Pos_Val->setText(QString::number(pos_in_chain));
}

void D_StepWindow::set_ViewPlanePos(vector<int> pos)
{
    if(!ui->action_connect_plane_position_to_other_steps->isChecked())      return;
    if(pos.size() != c_DIM_NUMBER_OF)                                       return;

    ViewerPlanePosChange_Block(true);
    ui->doubleSpinBox_View_Plane_X->setValue(pos[c_DIM_X]);
    ui->doubleSpinBox_View_Plane_Y->setValue(pos[c_DIM_Y]);
    ui->doubleSpinBox_View_Plane_Z->setValue(pos[c_DIM_Z]);
    ui->doubleSpinBox_View_Plane_T->setValue(pos[c_DIM_T]);
    ui->doubleSpinBox_View_Plane_S->setValue(pos[c_DIM_S]);
    ui->doubleSpinBox_View_Plane_P->setValue(pos[c_DIM_P]);
    ViewerPlanePosChange_Block(false);
    Update_Image();
}

void D_StepWindow::set_ViewZoom(double x_rel, double y_rel, double factor, int plane)
{
    if(!ui->action_Connect_Steps_Zoom->isChecked())         return;
    if(plane != ui->comboBox_View_Plane->currentIndex())    return;

    Viewer.Set_Zoom(x_rel, y_rel, factor);

    //qDebug() << "set_ViewZoom" << "in step:" << pos_Dest << factor << QSL_Planes[plane];
}

void D_StepWindow::Update_Image()
{
    //Time measurement
    QElapsedTimer timer;
    timer.start();

    Dim_GetFromVD();

    //get extended dims
    int ext_dim_1;
    int ext_dim_2;

    switch (ui->comboBox_View_Plane->currentIndex()) {
    case c_PLANE_XY:    ext_dim_1 = c_DIM_X;    ext_dim_2 = c_DIM_Y;    break;
    case c_PLANE_XZ:    ext_dim_1 = c_DIM_X;    ext_dim_2 = c_DIM_Z;    break;
    case c_PLANE_XT:    ext_dim_1 = c_DIM_X;    ext_dim_2 = c_DIM_T;    break;
    case c_PLANE_XS:    ext_dim_1 = c_DIM_X;    ext_dim_2 = c_DIM_S;    break;
    case c_PLANE_XP:    ext_dim_1 = c_DIM_X;    ext_dim_2 = c_DIM_P;    break;
    case c_PLANE_YZ:    ext_dim_1 = c_DIM_Y;    ext_dim_2 = c_DIM_Z;    break;
    case c_PLANE_YT:    ext_dim_1 = c_DIM_Y;    ext_dim_2 = c_DIM_T;    break;
    case c_PLANE_YS:    ext_dim_1 = c_DIM_Y;    ext_dim_2 = c_DIM_S;    break;
    case c_PLANE_YP:    ext_dim_1 = c_DIM_Y;    ext_dim_2 = c_DIM_P;    break;
    case c_PLANE_ZT:    ext_dim_1 = c_DIM_Z;    ext_dim_2 = c_DIM_T;    break;
    case c_PLANE_ZS:    ext_dim_1 = c_DIM_Z;    ext_dim_2 = c_DIM_S;    break;
    case c_PLANE_ZP:    ext_dim_1 = c_DIM_Z;    ext_dim_2 = c_DIM_P;    break;
    case c_PLANE_TS:    ext_dim_1 = c_DIM_T;    ext_dim_2 = c_DIM_S;    break;
    case c_PLANE_TP:    ext_dim_1 = c_DIM_T;    ext_dim_2 = c_DIM_P;    break;
    case c_PLANE_SP:    ext_dim_1 = c_DIM_S;    ext_dim_2 = c_DIM_P;    break;
    default:
        break;
    }

    //extended or fixed position?
    vector<int> vPos;
    vPos.resize(c_DIM_NUMBER_OF);
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
    {
        if(d == ext_dim_1 || d == ext_dim_2)
        {
            vPos[d] = -1;
            vDSB_Dims[d]->setEnabled(false);
        }
        else
        {
            vPos[d] = static_cast<int>(vDSB_Dims[d]->value() / pStore->get_pVD(pos_Dest)->pDim()->step_Dim(d));
            vDSB_Dims[d]->setEnabled(true);
        }
    }

    //Crop 2D Plane from VD and put it to cv::Mat vector in storage
    D_VisDat_Slice_2D Slice2d(vPos);
    //qDebug() << "Crop " + Slice2d.info() + " from " + pStore->get_pVD(pos_Dest)->Info_Dims();
    ERR(D_VisDat_Proc::Read_2D_Plane(
                pStore->get_Adress(pos_Dest),
                pStore->get_pVD(pos_Dest),
                Slice2d),
        "Update_Image",
        "Crop " + Slice2d.info() + " from " + pStore->get_pVD(pos_Dest)->info());

    //display cv::Mat from storage
    Viewer.Update_Image(pStore->get_Adress(pos_Dest));
    Update_Type_Descriptions();

    //time measurement
    times[c_TIME_IMG_CONV] = timer.elapsed();
    pStore->set_times(pos_Dest, c_TIME_IMG_CONV, timer.elapsed());
}

void D_StepWindow::Update_View()
{
    //Time measurement
    QElapsedTimer timer;
    timer.start();

    Viewer.Update_View();

    times[c_TIME_IMG_SHOW] = timer.elapsed();
    pStore->set_times(pos_Dest, c_TIME_IMG_SHOW, timer.elapsed());
}

void D_StepWindow::Update_Img_Proc()
{
    //this->setEnabled(false);

    //Time measurement
    QElapsedTimer timer;
    timer.start();

    switch (ui->comboBox_Type_Main->currentIndex()) {

    case c_T_SOURCE: //==================================================================================================   SOURCE

        switch (ui->comboBox_Type_00_Source->currentIndex()) {

        case c_sT_SO_LOAD:      //-------------------------------------------------------------------   Load
        {
            switch (ui->comboBox_00_Load_Mode->currentIndex()) {

            case c_LOAD_MODE_FILE_IMAGE:
                ERR(D_VisDat_Proc::Create_VD_Single(
                        pStore->get_pVD(pos_Dest),
                        FI_Load_File,
                        ui->comboBox_00_Load_Source_Dim_X->currentIndex(),
                        ui->comboBox_00_Load_Source_Dim_Y->currentIndex()),
                    "Update_Img_Proc",
                    "Create_VD_Single");
                break;

            case c_LOAD_MODE_FILE_IMAGE_PAGED:
                ERR(D_VisDat_Proc::Create_VD_SinglePaged(
                        pStore->get_pVD(pos_Dest),
                        FI_Load_File,
                        ui->comboBox_00_Load_Source_Dim_Pages->currentIndex(),
                        ui->comboBox_00_Load_Source_Dim_X->currentIndex(),
                        ui->comboBox_00_Load_Source_Dim_Y->currentIndex()),
                    "Update_Img_Proc",
                    "Create_VD_SinglePaged");
                break;

            case c_LOAD_MODE_FILE_VIDEO:
                ERR(D_VisDat_Proc::Create_VD_Video(
                        pStore->get_pVD(pos_Dest),
                        FI_Load_File,
                        ui->comboBox_00_Load_Source_Dim_T->currentIndex(),
                        ui->comboBox_00_Load_Source_Dim_X->currentIndex(),
                        ui->comboBox_00_Load_Source_Dim_Y->currentIndex(),
                        ui->checkBox_00_Load_Force8UC1->isChecked()),
                    "Update_Img_Proc",
                    "Create_VD_Video");
                break;

            case c_LOAD_MODE_FILELIST_IMAGE:
                ERR(D_VisDat_Proc::Create_VD_List(
                        pStore->get_pVD(pos_Dest),
                        FIL_Load_Files,
                        ui->comboBox_00_Load_Source_Dim_List->currentIndex(),
                        ui->comboBox_00_Load_Source_Dim_X->currentIndex(),
                        ui->comboBox_00_Load_Source_Dim_Y->currentIndex()),
                    "Update_Img_Proc",
                    "Create_VD_List");
                break;

            case c_LOAD_MODE_FILELIST_IMAGE_PAGED:
                ERR(D_VisDat_Proc::Create_VD_ListPaged(
                        pStore->get_pVD(pos_Dest),
                        FIL_Load_Files,
                        ui->comboBox_00_Load_Source_Dim_List->currentIndex(),
                        ui->comboBox_00_Load_Source_Dim_Pages->currentIndex(),
                        ui->comboBox_00_Load_Source_Dim_X->currentIndex(),
                        ui->comboBox_00_Load_Source_Dim_Y->currentIndex()),
                    "Update_Img_Proc",
                    "Create_VD_ListPaged");
                break;

            case c_LOAD_MODE_FILE_VISDAT:
                ERR(D_VisDat_Proc::Create_VD_FromBinaryFile(
                        pStore->get_pVD(pos_Dest),
                        FI_Load_File.absoluteFilePath()),
                    "Update_Img_Proc",
                    "Create_VD_FromBinaryFile");
                break;

            default:
                break;
            }
        }
            break;

        case c_sT_SO_DUPLICATE: //-------------------------------------------------------------------   Duplictae
            ERR(D_VisDat_Proc::Copy(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1)),
                "Update_Img_Proc",
                "Copy");
            break;

        case c_sT_SO_SAMPLE:    //-------------------------------------------------------------------   Sample
        {
            if(FIL_Examples.isEmpty())
                return;

            ERR(D_VisDat_Proc::Create_VD_Single(
                    pStore->get_pVD(pos_Dest),
                    FIL_Examples[ui->comboBox_00_Sample_Paths->currentIndex()],
                    c_DIM_X,
                    c_DIM_Y),
                "Update_Img_Proc",
                "Create_VD_Single");
        }
            break;

        case c_sT_SO_GENERATE: //-------------------------------------------------------------------   Generate
        {
            if(ui->comboBox_00_Generate_DimVar->currentIndex() == 0)
            {
                ERR(D_VisDat_Proc::Create_VD_ValueFunction(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        D_VisDat_Dim(
                            ui->spinBox_00_Generate_Size_X->value(),
                            ui->spinBox_00_Generate_Size_Y->value(),
                            ui->spinBox_00_Generate_Size_Z->value(),
                            ui->spinBox_00_Generate_Size_T->value(),
                            ui->spinBox_00_Generate_Size_S->value(),
                            ui->spinBox_00_Generate_Size_P->value()),
                        D_Math::Function_2D_to_1D(
                            ui->comboBox_00_Generate_ValueFunction_2D->currentIndex(),
                            ui->doubleSpinBox_00_Generate_2D_a->value(),
                            ui->doubleSpinBox_00_Generate_2D_b->value(),
                            ui->doubleSpinBox_00_Generate_2D_c->value(),
                            ui->doubleSpinBox_00_Generate_2D_d->value(),
                            ui->doubleSpinBox_00_Generate_2D_e->value(),
                            ui->doubleSpinBox_00_Generate_2D_f->value(),
                            ui->doubleSpinBox_00_Generate_2D_nan->value(),
                            ui->doubleSpinBox_00_Generate_2D_inf->value())),
                    "Update_Img_Proc",
                    "Create_VD_ValueFunction");
            }
            if(ui->comboBox_00_Generate_DimVar->currentIndex() == 1)
            {
                ERR(D_VisDat_Proc::Create_VD_ValueFunction_Complex(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        D_VisDat_Dim(
                            ui->spinBox_00_Generate_Size_X->value(),
                            ui->spinBox_00_Generate_Size_Y->value(),
                            ui->spinBox_00_Generate_Size_Z->value(),
                            ui->spinBox_00_Generate_Size_T->value(),
                            ui->spinBox_00_Generate_Size_S->value(),
                            ui->spinBox_00_Generate_Size_P->value()),
                        D_Math::Function_2D_to_1D_Complex(
                            ui->comboBox_00_Generate_ValueFunction_2D_Complex->currentIndex(),
                            ui->doubleSpinBox_00_Generate_2D_Complex_sx->value(),
                            ui->doubleSpinBox_00_Generate_2D_Complex_ox->value(),
                            ui->doubleSpinBox_00_Generate_2D_Complex_sy->value(),
                            ui->doubleSpinBox_00_Generate_2D_Complex_oy->value(),
                            ui->doubleSpinBox_00_Generate_2D_Complex_a->value(),
                            ui->doubleSpinBox_00_Generate_2D_Complex_b->value(),
                            ui->doubleSpinBox_00_Generate_2D_Complex_c->value(),
                            ui->doubleSpinBox_00_Generate_2D_Complex_d->value(),
                            ui->doubleSpinBox_00_Generate_2D_Complex_e->value(),
                            ui->doubleSpinBox_00_Generate_2D_Complex_f->value(),
                            ui->doubleSpinBox_00_Generate_2D_Complex_nan->value(),
                            ui->doubleSpinBox_00_Generate_2D_Complex_inf->value())),
                    "Update_Img_Proc",
                    "Create_VD_ValueFunction_Complex");
            }
            else if(ui->comboBox_00_Generate_DimVar->currentIndex() == 2)
                ERR(D_VisDat_Proc::Create_VD_ValueFunction_6D(
                        pStore->get_pVD(pos_Dest),
                        D_VisDat_Dim(
                            ui->spinBox_00_Generate_Size_X->value(),
                            ui->spinBox_00_Generate_Size_Y->value(),
                            ui->spinBox_00_Generate_Size_Z->value(),
                            ui->spinBox_00_Generate_Size_T->value(),
                            ui->spinBox_00_Generate_Size_S->value(),
                            ui->spinBox_00_Generate_Size_P->value()),
                        D_Math::Function_6D_to_1D(
                            ui->comboBox_00_Generate_ValueFunction_6D->currentIndex(),
                            ui->doubleSpinBox_00_Generate_6D_sx->value(),
                            ui->doubleSpinBox_00_Generate_6D_ox->value(),
                            ui->doubleSpinBox_00_Generate_6D_sy->value(),
                            ui->doubleSpinBox_00_Generate_6D_oy->value(),
                            ui->doubleSpinBox_00_Generate_6D_sz->value(),
                            ui->doubleSpinBox_00_Generate_6D_oz->value(),
                            ui->doubleSpinBox_00_Generate_6D_st->value(),
                            ui->doubleSpinBox_00_Generate_6D_ot->value(),
                            ui->doubleSpinBox_00_Generate_6D_ss->value(),
                            ui->doubleSpinBox_00_Generate_6D_os->value(),
                            ui->doubleSpinBox_00_Generate_6D_sp->value(),
                            ui->doubleSpinBox_00_Generate_6D_op->value(),
                            ui->doubleSpinBox_00_Generate_6D_a->value(),
                            ui->doubleSpinBox_00_Generate_6D_b->value(),
                            ui->doubleSpinBox_00_Generate_6D_c->value(),
                            ui->doubleSpinBox_00_Generate_6D_d->value(),
                            ui->doubleSpinBox_00_Generate_6D_e->value(),
                            ui->doubleSpinBox_00_Generate_6D_f->value(),
                            ui->doubleSpinBox_00_Generate_6D_nan->value(),
                            ui->doubleSpinBox_00_Generate_6D_inf->value())),
                    "Update_Img_Proc",
                    "Create_VD_ValueFunction_6D");
        }
            break;

        case c_sT_SO_RANDOM: //-------------------------------------------------------------------   Random
        {
            ERR(D_VisDat_Proc::Create_VD_Random(
                    pStore->get_pVD(pos_Dest),
                    D_VisDat_Dim(
                        ui->spinBox_00_Random_Size_X->value(),
                        ui->spinBox_00_Random_Size_Y->value(),
                        ui->spinBox_00_Random_Size_Z->value(),
                        ui->spinBox_00_Random_Size_T->value(),
                        ui->spinBox_00_Random_Size_S->value(),
                        ui->spinBox_00_Random_Size_P->value()),
                    ui->comboBox_00_Random_Type->currentIndex(),
                    ui->doubleSpinBox_00_Random_Min->value(),
                    ui->doubleSpinBox_00_Random_Max->value(),
                    ui->doubleSpinBox_00_Random_a->value(),
                    ui->doubleSpinBox_00_Random_b->value(),
                    ui->doubleSpinBox_00_Random_c->value(),
                    ui->doubleSpinBox_00_Random_d->value(),
                    ui->doubleSpinBox_00_Random_e->value(),
                    ui->doubleSpinBox_00_Random_f->value()),
                "Update_Img_Proc",
                "Create_VD_Random");
            break;
        }

        case c_sT_SO_RAW: //-------------------------------------------------------------------   Raw
        {
            int out_type;
            switch (ui->comboBox_00_CastRaw_BitPerPixel->currentIndex()) {
            case 0:     out_type = CV_8UC1;     break;
            case 1:     out_type = CV_8SC1;     break;
            case 2:     out_type = CV_16UC1;    break;
            case 3:     out_type = CV_16SC1;    break;
            case 4:     out_type = CV_32SC1;    break;
            case 5:     out_type = CV_32FC1;    break;
            case 6:     out_type = CV_64FC1;    break;
            default:                            return;}

            ERR(D_VisDat_Proc::Create_VD_Single_Raw(
                    pStore->get_pVD(pos_Dest),
                    FI_RawFile.absoluteFilePath().toStdString(),
                    ui->spinBox_00_CastRaw_Width->value(),
                    ui->spinBox_00_CastRaw_Height->value(),
                    out_type),
                "Update_Img_Proc",
                "Create_VD_Single_Raw");
        }
            break;

        case c_sT_SO_VIDEO_PROC: //-------------------------------------------------------------------   Video Proc
        {
            ERR(D_VisDat_Proc::Create_VD_Video_Proc(
                    pStore->get_pVD(pos_Dest),
                    FI_Load_File,
                    ui->spinBox_00_VideoStream_Blur_Size->value(),
                    ui->doubleSpinBox_00_VideoStream_Blur_Sigma->value(),
                    ui->spinBox_00_VideoStream_T1_Frames->value(),
                    D_Stat::Function_SingleStat(
                        ui->comboBox_00_VideoStream_T1_Stat->currentIndex()),
                    ui->spinBox_00_VideoStream_T2_Frames->value(),
                    D_Stat::Function_SingleStat(
                        ui->comboBox_00_VideoStream_T2_Stat->currentIndex()),
                    ui->spinBox_00_VideoStream_T_Offset->value(),
                    D_Math::Function_2D_to_1D(
                        ui->comboBox_00_VideoStream_CombiFunction->currentIndex(),
                        ui->doubleSpinBox_00_VideoStream_CombiFunction_a->value(),
                        ui->doubleSpinBox_00_VideoStream_CombiFunction_b->value(),
                        ui->doubleSpinBox_00_VideoStream_CombiFunction_c->value(),
                        ui->doubleSpinBox_00_VideoStream_CombiFunction_d->value(),
                        ui->doubleSpinBox_00_VideoStream_CombiFunction_e->value(),
                        ui->doubleSpinBox_00_VideoStream_CombiFunction_f->value(),
                        ui->doubleSpinBox_00_VideoStream_CombiFunction_nan->value(),
                        ui->doubleSpinBox_00_VideoStream_CombiFunction_inf->value()),
                    ui->checkBox_00_VideoStream_Force_8bit->isChecked()),
                "Update_Img_Proc",
                "Create_VD_Video_Proc");
        }
            break;

        default:                //-------------------------------------------------------------------   Default
            break;

        }
        break;

    case c_T_EDIT:  //==================================================================================================   EDIT

        switch (ui->comboBox_Type_01_Edit->currentIndex()) {

        case c_sT_ED_CROP:  //-------------------------------------------------------------------   Crop

            switch (ui->comboBox_01_Crop_Shape->currentIndex()) {

            case 0://Rect Rel
                ERR(D_VisDat_Proc::Crop_Rect_Rel(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        ui->doubleSpinBox_01_Crop_Rect_X1->value() / 100.0,
                        ui->doubleSpinBox_01_Crop_Rect_Y1->value() / 100.0,
                        ui->doubleSpinBox_01_Crop_Rect_X2->value() / 100.0,
                        ui->doubleSpinBox_01_Crop_Rect_Y2->value() / 100.0),
                    "Update_Img_Proc",
                    "Crop_Rect_Rel");
                break;

            case 1://Rect Abs
                ERR(D_VisDat_Proc::Crop_Rect_Abs(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        ui->spinBox_01_Crop_RectAbs_Offset_X->value(),
                        ui->spinBox_01_Crop_RectAbs_Offset_Y->value(),
                        ui->spinBox_01_Crop_RectAbs_Size_X->value(),
                        ui->spinBox_01_Crop_RectAbs_Size_Y->value()),
                    "Update_Img_Proc",
                    "Crop_Rect_Abs");
                break;

            case 2://Rect Rot
                ERR(D_VisDat_Proc::Crop_Rect_Rot(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        ui->spinBox_01_Crop_RectRot_Center_X->value(),
                        ui->spinBox_01_Crop_RectRot_Center_Y->value(),
                        ui->spinBox_01_Crop_RectRot_Width->value(),
                        ui->spinBox_01_Crop_RectRot_Height->value(),
                        ui->doubleSpinBox_01_Crop_RectRot_Rotation->value()),
                    "Update_Img_Proc",
                    "Crop_Rect_Rot");
                break;

            case 3://Circle
                ERR(D_VisDat_Proc::Crop_Circle(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        ui->spinBox_01_Crop_Circle_Center_X->value(),
                        ui->spinBox_01_Crop_Circle_Center_Y->value(),
                        ui->spinBox_01_Crop_Circle_Radius->value()),
                    "Update_Img_Proc",
                    "Crop_Circle");
                break;
                /*
            case 4://Ellipse
                ERR(D_Img_Proc::Crop_Rect_Abs(
                        pStore->get_Adress(pos_Dest),
                        pStore->get_Adress(pos_Source1),
                        ui->spinBox_01_Crop_RectAbs_Offset_X->value(),
                        ui->spinBox_01_Crop_RectAbs_Offset_Y->value(),
                        ui->spinBox_01_Crop_RectAbs_Size_X->value(),
                        ui->spinBox_01_Crop_RectAbs_Size_Y->value()));
                break;
*/
            default:
                break;
            }

            break;

        case c_sT_ED_FLOODFILL:  //-------------------------------------------------------------------   Floodfill
        {
            switch (ui->comboBox_01_Floodfill_Type->currentIndex()) {

            case 0://Boundary
                ERR(D_VisDat_Proc::Floodfill_Border(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        ui->doubleSpinBox_01_Floodfill_Value_Fill->value()),
                    "Update_Img_Proc",
                    "Floodfill_Border");
                break;

            case 1://Delta
                ERR(D_VisDat_Proc::Floodfill_Delta(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        ui->spinBox_01_Floodfill_Delta_SeedX->value(),
                        ui->spinBox_01_Floodfill_Delta_SeedY->value(),
                        ui->doubleSpinBox_01_Floodfill_Value_Fill->value(),
                        ui->doubleSpinBox_01_Floodfill_Delta_Delta->value()),
                    "Update_Img_Proc",
                    "Floodfill_Delta");
                break;

            default:
                break;
            }

        }
            break;

        case c_sT_ED_PADDING:  //-------------------------------------------------------------------   Padding
        {
            int border_type = BORDER_DEFAULT;
            switch (ui->comboBox_01_Padding_Type->currentIndex()) {
            case 0:     border_type = BORDER_DEFAULT;       break;
            case 1:     border_type = BORDER_CONSTANT;      break;
            case 2:     border_type = BORDER_REPLICATE;     break;
            case 3:     border_type = BORDER_REFLECT;       break;
            case 4:     border_type = BORDER_REFLECT_101;   break;
            default:                                        break;}

            ERR(D_VisDat_Proc::Pad_Border(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->spinBox_01_Padding_Width_X->value(),
                    ui->spinBox_01_Padding_Width_Y->value(),
                    ui->spinBox_01_Padding_Width_Z->value(),
                    border_type,
                    ui->doubleSpinBox_01_Padding_Value->value()),
                "Update_Img_Proc",
                "Pad_Border");
        }
            break;

        case c_sT_ED_FORCE_SIZE:  //-------------------------------------------------------------------   Force Size
        {
            int border_type = BORDER_DEFAULT;
            switch (ui->comboBox_01_ForceSize_Border->currentIndex()) {
            case 0:     border_type = BORDER_DEFAULT;       break;
            case 1:     border_type = BORDER_CONSTANT;      break;
            case 2:     border_type = BORDER_REPLICATE;     break;
            case 3:     border_type = BORDER_REFLECT;       break;
            case 4:     border_type = BORDER_REFLECT_101;   break;
            default:                                        break;}

            ERR(D_VisDat_Proc::ForceSize(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->spinBox_01_ForceSize_Width->value(),
                    ui->spinBox_01_ForceSize_Height->value(),
                    border_type),
                "Update_Img_Proc",
                "ForceSize");
        }
            break;

        case c_sT_ED_SCALE:  //-------------------------------------------------------------------   Force Size
        {
            int type_index = ui->comboBox_01_Scale_Type->currentIndex();

            if(type_index == c_SCALE_TYPE_FACTOR)
                ERR(D_VisDat_Proc::Scale_Factor(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        ui->doubleSpinBox_01_Scale_Factor_X->value(),
                        ui->doubleSpinBox_01_Scale_Factor_Y->value()),
                    "Update_Img_Proc",
                    "Scale_Factor");
            else if(type_index == c_SCALE_TYPE_TARGET_SIZE)
                ERR(D_VisDat_Proc::Scale_ToSize(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        ui->spinBox_01_Scale_Size_X->value(),
                        ui->spinBox_01_Scale_Size_Y->value()),
                    "Update_Img_Proc",
                    "Scale_ToSize");
        }
            break;

        default:            //-------------------------------------------------------------------   Default
            break;

        }
        break;


    case c_T_CONV:  //==================================================================================================   CONVERT

        switch (ui->comboBox_Type_02_Convert->currentIndex()) {

        case c_sT_CO_COLOR2MONO:    //-------------------------------------------------------------------   Color 2 Mono
        {
            ERR(D_VisDat_Proc::Convert_Color2Mono(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->comboBox_02_Color2Mono_Reduction->currentIndex()),
                "Update_Img_Proc",
                "Convert_Color2Mono");
        }
            break;

        case c_sT_CO_COLOR:     //-------------------------------------------------------------------   Color
        {
            unsigned int cvt_mode = 0;

            if(ui->comboBox_02_Color_Direction_Top->currentIndex() == 1)
            {
                     if(ui->radioButton_02_Color_RGB_BGR->isChecked())      cvt_mode = CV_BGR2RGB;
                else if(ui->radioButton_02_Color_BGR_RGB->isChecked())      cvt_mode = CV_RGB2BGR;
                else if(ui->radioButton_02_Color_Grey_RGB->isChecked())     cvt_mode = CV_GRAY2RGB;
                else if(ui->radioButton_02_Color_Grey_BGR->isChecked())     cvt_mode = CV_GRAY2BGR;
                else if(ui->radioButton_02_Color_XYZ_RGB->isChecked())      cvt_mode = CV_XYZ2RGB;
                else if(ui->radioButton_02_Color_XYZ_BGR->isChecked())      cvt_mode = CV_XYZ2BGR;
                else if(ui->radioButton_02_Color_YCrCb_RGB->isChecked())    cvt_mode = CV_YCrCb2RGB;
                else if(ui->radioButton_02_Color_YCrCb_BGR->isChecked())    cvt_mode = CV_YCrCb2BGR;
                else if(ui->radioButton_02_Color_HSV_RGB->isChecked())      cvt_mode = CV_HSV2RGB_FULL;
                else if(ui->radioButton_02_Color_HSV_BGR->isChecked())      cvt_mode = CV_HSV2BGR_FULL;
                else if(ui->radioButton_02_Color_HSL_RGB->isChecked())      cvt_mode = CV_HSV2RGB;
                else if(ui->radioButton_02_Color_HSL_BGR->isChecked())      cvt_mode = CV_HSV2BGR;
                else if(ui->radioButton_02_Color_Lab_RGB->isChecked())      cvt_mode = CV_Lab2RGB;
                else if(ui->radioButton_02_Color_Lab_BGR->isChecked())      cvt_mode = CV_Lab2BGR;
                else if(ui->radioButton_02_Color_Luv_RGB->isChecked())      cvt_mode = CV_Luv2RGB;
                else                                                        cvt_mode = CV_Luv2BGR;
            }
            else
            {
                    if(ui->radioButton_02_Color_RGB_BGR->isChecked())      cvt_mode = CV_RGB2BGR;
               else if(ui->radioButton_02_Color_BGR_RGB->isChecked())      cvt_mode = CV_BGR2RGB;
               else if(ui->radioButton_02_Color_Grey_RGB->isChecked())     cvt_mode = CV_RGB2GRAY;
               else if(ui->radioButton_02_Color_Grey_BGR->isChecked())     cvt_mode = CV_BGR2GRAY;
               else if(ui->radioButton_02_Color_XYZ_RGB->isChecked())      cvt_mode = CV_RGB2XYZ;
               else if(ui->radioButton_02_Color_XYZ_BGR->isChecked())      cvt_mode = CV_BGR2XYZ;
               else if(ui->radioButton_02_Color_YCrCb_RGB->isChecked())    cvt_mode = CV_RGB2YCrCb;
               else if(ui->radioButton_02_Color_YCrCb_BGR->isChecked())    cvt_mode = CV_BGR2YCrCb;
               else if(ui->radioButton_02_Color_HSV_RGB->isChecked())      cvt_mode = CV_RGB2HSV_FULL;
               else if(ui->radioButton_02_Color_HSV_BGR->isChecked())      cvt_mode = CV_BGR2HSV_FULL;
               else if(ui->radioButton_02_Color_HSL_RGB->isChecked())      cvt_mode = CV_RGB2HSV;
               else if(ui->radioButton_02_Color_HSL_BGR->isChecked())      cvt_mode = CV_BGR2HSV;
               else if(ui->radioButton_02_Color_Lab_RGB->isChecked())      cvt_mode = CV_RGB2Lab;
               else if(ui->radioButton_02_Color_Lab_BGR->isChecked())      cvt_mode = CV_BGR2Lab;
               else if(ui->radioButton_02_Color_Luv_RGB->isChecked())      cvt_mode = CV_RGB2Luv;
               else                                                        cvt_mode = CV_BGR2Luv;
            }

            ERR(D_VisDat_Proc::Convert_Color(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    cvt_mode),
                "Update_Img_Proc",
                "Convert_Color");
        }
            break;

        case c_sT_CO_DEPTH:     //-------------------------------------------------------------------   Depth
        {
            unsigned int type;

            switch (ui->comboBox_02_Depth_Type->currentIndex()) {
            case 0:     type = CV_8U;   break;
            case 1:     type = CV_8S;   break;
            case 2:     type = CV_16U;  break;
            case 3:     type = CV_16S;  break;
            case 4:     type = CV_32S;  break;
            case 5:     type = CV_32F;  break;
            case 6:     type = CV_64F;  break;
            default:                    return;}

            if(ui->comboBox_02_Depth_Norm->currentIndex() == 0)
            {
                ERR(D_VisDat_Proc::Convert_Depth_NoScaling(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        type),
                    "Update_Img_Proc",
                    "Convert_Depth_NoScaling");
            }
            else
            {
                //CV_8S, CV_16S and CV_32S may cause problems
                //QMessage::b

                ERR(D_VisDat_Proc::Normalize(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        NORM_MINMAX,
                        type,
                        ui->doubleSpinBox_02_Depth_Minimum->value(),
                        ui->doubleSpinBox_02_Depth_Maximum->value()),
                    "Update_Img_Proc",
                    "Normalize");
            }
        }
            break;

        case c_sT_CO_MERGE:     //-------------------------------------------------------------------   Merge
        {
            unsigned int channels   = ui->spinBox_02_Merge_Channels->value();
            bool channels_used[4];
            channels_used[0]        = ui->checkBox_02_Merge_Ch0->isChecked();
            channels_used[1]        = ui->checkBox_02_Merge_Ch1->isChecked();
            channels_used[2]        = ui->checkBox_02_Merge_Ch2->isChecked();
            channels_used[3]        = ui->checkBox_02_Merge_Ch3->isChecked();

            ERR(D_VisDat_Proc::Channels_Merge(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    pStore->get_pVD(pos_Source2),
                    pStore->get_pVD(pos_Source3),
                    pStore->get_pVD(pos_Source4),
                    channels,
                    channels_used),
                "Update_Img_Proc",
                "Channels_Merge");
        }
            break;

        case c_sT_CO_SPLIT:     //-------------------------------------------------------------------   Split
        {
            ERR(D_VisDat_Proc::Channels_Split(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->spinBox_02_Split_Channel->value()),
                "Update_Img_Proc",
                "Channels_Split");
        }
            break;

        case c_sT_CO_COMBI:     //-------------------------------------------------------------------   combi
        {
            ERR(D_VisDat_Proc::Convert_8UC1_binary(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1)),
                "Update_Img_Proc",
                "Convert_8UC1_binary");
        }
            break;

        case c_sT_CO_ANGLE2COLOR:     //-------------------------------------------------------------------   angle 2 color
        {
            ERR(D_VisDat_Proc::Convert_Angle2Color_Rad(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->spinBox_02_Angle2Color_S->value(),
                    ui->spinBox_02_Angle2Color_V->value()),
                "Update_Img_Proc",
                "Convert_Angle2Color_Rad");
        }

        default:                //-------------------------------------------------------------------   Default
            break;

        }
        break;


    case c_T_ELEM: //==================================================================================================   ELEMENTAL

        switch (ui->comboBox_Type_03_Elemental->currentIndex()) {

        case c_sT_EL_THRES:     //-------------------------------------------------------------------   Threshold
        {
            int out_mode = 0;
            switch (ui->comboBox_03_Thres_Output_Mode->currentIndex()) {
            case 0:     out_mode = CV_THRESH_BINARY;        break;
            case 1:     out_mode = CV_THRESH_BINARY_INV;    break;
            case 2:     out_mode = CV_THRESH_TRUNC;         break;
            case 3:     out_mode = CV_THRESH_TOZERO;        break;
            case 4:     out_mode = CV_THRESH_TOZERO_INV;    break;
            default:                                        break;}

            double max_val          = ui->doubleSpinBox_03_Thres_Max_Value_Out->value();

            switch (ui->comboBox_03_Thres_Type->currentIndex()) {

            case 0://------------------Otsu
            {
                ERR(D_VisDat_Proc::Threshold_Auto_Otsu(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        out_mode,
                        max_val),
                    "Update_Img_Proc",
                    "Threshold_Auto_Otsu");
            }
                break;

            case 1://------------------Manual Abs
            {
                ERR(D_VisDat_Proc::Threshold_Absolute_8U(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        out_mode,
                        max_val,
                        ui->spinBox_03_Thres_Thres_Value_Abs->value()),
                    "Update_Img_Proc",
                    "Threshold_Absolute_8U");
            }
                break;

            case 2://------------------Manual Rel
            {
                ERR(D_VisDat_Proc::Threshold_Relative(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        ui->doubleSpinBox_03_Thres_Rel_Base->value(),
                        ui->doubleSpinBox_03_Thres_Rel_Thres_Rel->value() / 100.0),
                    "Update_Img_Proc",
                    "Threshold_Relative");
            }
                break;

            case 3://------------------Local
            {
                int     mask_type;
                switch (ui->comboBox_03_Thres_Adapt_Type->currentIndex()) {
                case 0: mask_type = ADAPTIVE_THRESH_MEAN_C;     break;
                case 1: mask_type = ADAPTIVE_THRESH_GAUSSIAN_C; break;
                default:                                        break;}

                ERR(D_VisDat_Proc::Threshold_Adaptive(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        out_mode,
                        max_val,
                        mask_type,
                        ui->spinBox_03_Thres_Mask_Size->value() / 2,
                        ui->doubleSpinBox_03_Thres_Adapt_Offset->value()),
                    "Update_Img_Proc",
                    "Threshold_Adaptive");
            }
                break;

            case 4://------------------rank order hysteresis
            {
                ERR(D_VisDat_Proc::Threshold_RankOrderOffsetHysteresis(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        ui->doubleSpinBox_03_Thres_RankHysteresis_Radius->value(),
                        ui->doubleSpinBox_03_Thres_RankHysteresis_Quantil->value() / 100.0,
                        ui->doubleSpinBox_03_Thres_RankHysteresis_ThresIndicator->value(),
                        ui->doubleSpinBox_03_Thres_RankHysteresis_ThresHysteresis->value()),
                    "Update_Img_Proc",
                    "Threshold_Adaptive");
            }
                break;

            default:
                break;
            }
        }
            break;

        case c_sT_EL_LABEL:     //-------------------------------------------------------------------   Labeling
        {
            int out_depth;
            switch (ui->comboBox_03_Labeling_Depth->currentIndex()) {
            case 0:     out_depth = CV_32S;         break;
            case 1:     out_depth = CV_16U;         break;
            default:                                break;}

            int connectivity;
            switch (ui->comboBox_03_Labeling_Connectivity->currentIndex()) {
            case 0:     connectivity = 8;           break;
            case 1:     connectivity = 4;           break;
            default:                                break;}

            switch (ui->comboBox_03_Labeling_Type->currentIndex()) {

            case 0:
                ERR(D_VisDat_Proc::Labeling(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        connectivity,
                        out_depth),
                    "Update_Img_Proc",
                    "Labeling");
                break;

            default:
                break;
            }

        }
            break;

        case c_sT_EL_SHADE_CORRECT: //-----------------------------------------------------------   Shade correct
        {
            ERR(D_VisDat_Proc::Shading_Correct(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    pStore->get_pVD(pos_Source2)),
                "Update_Img_Proc",
                "Shading_Correct");
        }
            break;

        case c_sT_EL_COLORGRAB:     //-----------------------------------------------------------   color grab
        {
            vector<uchar> min;
            vector<uchar> max;
            min.push_back((uchar) ui->spinBox_03_GrabColor_Ch1_Min->value());
            min.push_back((uchar) ui->spinBox_03_GrabColor_Ch2_Min->value());
            min.push_back((uchar) ui->spinBox_03_GrabColor_Ch3_Min->value());
            max.push_back((uchar) ui->spinBox_03_GrabColor_Ch1_Max->value());
            max.push_back((uchar) ui->spinBox_03_GrabColor_Ch2_Max->value());
            max.push_back((uchar) ui->spinBox_03_GrabColor_Ch3_Max->value());

            ERR(D_VisDat_Proc::Color_Grab(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->comboBox_03_GrabColor_ColorSpace->currentIndex(),
                    ui->comboBox_03_GrabColor_Output->currentIndex(),
                    min,
                    max),
                "Update_Img_Proc",
                "Color_Grab");
        }
            break;

        case c_sT_EL_FILLHOLES:     //-----------------------------------------------------------   fill holes
        {
            ERR(D_VisDat_Proc::Fill_Holes(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1)),
                "Update_Img_Proc",
                "Fill_Holes");
        }
            break;

        default:            //-------------------------------------------------------------------   Default
            break;

        }
        break;


    case c_T_FILT:  //==================================================================================================   FILTER
    {
        int border_type = BORDER_DEFAULT;
        switch (ui->comboBox_04_Border_Type->currentIndex()) {
        case 0:     border_type = BORDER_DEFAULT;      break;
        case 1:     border_type = BORDER_CONSTANT;      break;
        case 2:     border_type = BORDER_REPLICATE;     break;
        case 3:     border_type = BORDER_REFLECT;       break;
        //case 3:     border_type = BORDER_WRAP;          break;
        case 4:     border_type = BORDER_REFLECT_101;   break;
        //case 4:     border_type = BORDER_TRANSPARENT;   break;
        case 5:     border_type = BORDER_ISOLATED;      break;
        default:                                        break;}

        switch (ui->comboBox_Type_04_Filter->currentIndex()) {

        case c_sT_FI_BLUR: //---------------------------------------------------------------   blur
        {
            int size        = ui->spinBox_04_Blur_Size->value() / 2;
            int size_x      = ui->spinBox_04_Blur_Size_X->value() / 2;
            int size_y      = ui->spinBox_04_Blur_Size_Y->value() / 2;
            double sigma_x  = ui->doubleSpinBox_04_Blur_Sigma_X->value();
            double sigma_y  = ui->doubleSpinBox_04_Blur_Sigma_Y->value();
            bool norm       = ui->checkBox_04_Blur_Normalized->isChecked();
            int depth       = -1;

            switch (ui->comboBox_04_Blur_Type->currentIndex()) {

            case 0://Mean
                ERR(D_VisDat_Proc::Filter_Mean(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        size_x,
                        size_y,
                        border_type,
                        depth,
                        norm),
                    "Update_Img_Proc",
                    "Filter_Mean");
                break;

            case 1://RMS
                ERR(D_VisDat_Proc::Filter_RootMeanSquare(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        size_x,
                        size_y,
                        border_type,
                        depth,
                        norm),
                    "Update_Img_Proc",
                    "Filter_RootMeanSquare");
                break;

            case 2://Gauss
                ERR(D_VisDat_Proc::Filter_Gauss(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        size_x,
                        size_y,
                        border_type,
                        sigma_x,
                        sigma_y),
                    "Update_Img_Proc",
                    "Filter_Gauss");
                break;

            case 3://Median
                ERR(D_VisDat_Proc::Filter_Median(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        size,
                        size,
                        size),
                    "Update_Img_Proc",
                    "Filter_Median");
                break;

            case 4://Median Custom
                ERR(D_VisDat_Proc::Filter_Median(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2)),
                    "Update_Img_Proc",
                    "Filter_Median (Custom)");
                break;

            default:
                break;
            }

        }
            break;

        case c_ST_FI_EDGE: //---------------------------------------------------------------   edge
        {
            int size        = ui->spinBox_04_Edge_Size->value();
            int depth       = -1;
            double scale    = ui->doubleSpinBox_04_Edge_Scale->value();
            double delta    = ui->doubleSpinBox_04_Edge_Delta->value();
            int d_x         = ui->spinBox_04_Edge_dX->value();
            int d_y         = ui->spinBox_04_Edge_dY->value();

            switch (ui->comboBox_04_Edge_Type->currentIndex()) {

            case 0://Laplace
                ERR(D_VisDat_Proc::Filter_Laplace(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        size,
                        border_type,
                        depth,
                        scale,
                        delta),
                    "Update_Img_Proc",
                    "Filter_Laplace");
                break;

            case 1://Sobel
                ERR(D_VisDat_Proc::Filter_Sobel(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        size,
                        border_type,
                        depth,
                        scale,
                        delta,
                        d_x,
                        d_y),
                    "Update_Img_Proc",
                    "Filter_Sobel");
                break;

            case 2://Scharr
            {
                QMessageBox MSG;
                MSG.setText("Temporarily decativated:");
                MSG.setInformativeText("Scharr Filter (assertion failed)");
                MSG.exec();

                /*ERR(D_Img_Proc::Filter_Scharr(
                        pStore->get_Adress(pos_Dest),
                        pStore->get_Adress(pos_Source1),
                        border_type,
                        depth,
                        scale,
                        delta,
                        d_x,
                        d_y));*/
            }
                break;

            case 3://Canny
                ERR(D_VisDat_Proc::Filter_Canny(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        size,
                        ui->spinBox_04_Edge_Thresh_Low->value(),
                        ui->spinBox_04_Edge_Thresh_High->value(),
                        ui->checkBox_04_Edge_L2_Gradient->isChecked()),
                    "Update_Img_Proc",
                    "Filter_Canny");
                break;

            default:
                break;
            }
        }
            break;

        case c_sT_FI_EILENSTEIN: //---------------------------------------------------------------   eilenstein
        {
            if(ui->comboBox_04_Eilenstein_Type->currentIndex() == 00)//Compare
            {
                ERR(D_VisDat_Proc::Filter_Eilenstein(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        ui->comboBox_04_Eilenstein_Comparator->currentIndex(),
                        ui->spinBox_04_Eilenstein_Size_X->value() / 2,
                        ui->spinBox_04_Eilenstein_Size_Y->value() / 2,
                        ui->checkBox_04_Eilenstein_Normalized->isChecked(),
                        ui->doubleSpinBox_04_Eilenstein_Delta->value()),
                    "Update_Img_Proc",
                    "Filter_Eilenstein - comparators");
            }
            else//generalized
            {
                ERR(D_VisDat_Proc::Filter_Eilenstein(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        D_Math::Function_2D_to_1D(
                            ui->comboBox_04_Eilenstein_PixelCenter->currentIndex(),
                            ui->doubleSpinBox_04_Eilenstein_PixelCenter_a->value(),
                            ui->doubleSpinBox_04_Eilenstein_PixelCenter_b->value(),
                            ui->doubleSpinBox_04_Eilenstein_PixelCenter_c->value(),
                            ui->doubleSpinBox_04_Eilenstein_PixelCenter_d->value(),
                            ui->doubleSpinBox_04_Eilenstein_PixelCenter_e->value(),
                            ui->doubleSpinBox_04_Eilenstein_PixelCenter_f->value(),
                            ui->doubleSpinBox_04_Eilenstein_PixelCenter_nan->value(),
                            ui->doubleSpinBox_04_Eilenstein_PixelCenter_inf->value()),
                        D_Math::Function_2D_to_1D(
                            ui->comboBox_04_Eilenstein_PixelMask->currentIndex(),
                            ui->doubleSpinBox_04_Eilenstein_PixelMask_a->value(),
                            ui->doubleSpinBox_04_Eilenstein_PixelMask_b->value(),
                            ui->doubleSpinBox_04_Eilenstein_PixelMask_c->value(),
                            ui->doubleSpinBox_04_Eilenstein_PixelMask_d->value(),
                            ui->doubleSpinBox_04_Eilenstein_PixelMask_e->value(),
                            ui->doubleSpinBox_04_Eilenstein_PixelMask_f->value(),
                            ui->doubleSpinBox_04_Eilenstein_PixelMask_nan->value(),
                            ui->doubleSpinBox_04_Eilenstein_PixelMask_inf->value()),
                        D_Stat::Function_SingleStat(
                            ui->comboBox_04_Eilenstein_Response->currentIndex())),
                    "Update_Img_Proc",
                    "Filter_Eilenstein - generalized");
            }
        }
            break;

        case c_sT_FI_FUNCTION: //---------------------------------------------------------------   function filter
        {
            if(ui->checkBox_04_Force_8bit->isChecked())
                ERR(D_VisDat_Proc::Filter_Function_8bit(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        D_Math::Function_2D_to_1D_8bit(                                      //F1
                            ui->comboBox_04_Function_f1_CenterImage->currentIndex(),
                            ui->doubleSpinBox_04_Function_f1_a->value(),
                            ui->doubleSpinBox_04_Function_f1_b->value(),
                            ui->doubleSpinBox_04_Function_f1_c->value(),
                            ui->doubleSpinBox_04_Function_f1_d->value(),
                            ui->doubleSpinBox_04_Function_f1_e->value(),
                            ui->doubleSpinBox_04_Function_f1_f->value(),
                            ui->doubleSpinBox_04_Function_f1_nan->value(),
                            ui->doubleSpinBox_04_Function_f1_inf->value()),
                        D_Math::Function_2D_to_1D_8bit(                                      //F2
                            ui->comboBox_04_Function_f2_F1Mask->currentIndex(),
                            ui->doubleSpinBox_04_Function_f2_a->value(),
                            ui->doubleSpinBox_04_Function_f2_b->value(),
                            ui->doubleSpinBox_04_Function_f2_c->value(),
                            ui->doubleSpinBox_04_Function_f2_d->value(),
                            ui->doubleSpinBox_04_Function_f2_e->value(),
                            ui->doubleSpinBox_04_Function_f2_f->value(),
                            ui->doubleSpinBox_04_Function_f2_nan->value(),
                            ui->doubleSpinBox_04_Function_f2_inf->value()),
                        D_Stat::Function_SingleStat_8bit(                                    //F3
                            ui->comboBox_04_Function_f3_vF2->currentIndex()),
                        D_Math::Function_2D_to_1D_8bit(                                      //F4
                            ui->comboBox_04_Function_f4_CenterF3->currentIndex(),
                            ui->doubleSpinBox_04_Function_f4_a->value(),
                            ui->doubleSpinBox_04_Function_f4_b->value(),
                            ui->doubleSpinBox_04_Function_f4_c->value(),
                            ui->doubleSpinBox_04_Function_f4_d->value(),
                            ui->doubleSpinBox_04_Function_f4_e->value(),
                            ui->doubleSpinBox_04_Function_f4_f->value(),
                            ui->doubleSpinBox_04_Function_f4_nan->value(),
                            ui->doubleSpinBox_04_Function_f4_inf->value()),
                        border_type,
                        ui->checkBox_04_Function_OnlyNonZero->isChecked()),
                    "Update_Img_Proc",
                    "Filter_Function");
            else
                ERR(D_VisDat_Proc::Filter_Function(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        D_Math::Function_2D_to_1D(                                      //F1
                            ui->comboBox_04_Function_f1_CenterImage->currentIndex(),
                            ui->doubleSpinBox_04_Function_f1_a->value(),
                            ui->doubleSpinBox_04_Function_f1_b->value(),
                            ui->doubleSpinBox_04_Function_f1_c->value(),
                            ui->doubleSpinBox_04_Function_f1_d->value(),
                            ui->doubleSpinBox_04_Function_f1_e->value(),
                            ui->doubleSpinBox_04_Function_f1_f->value(),
                            ui->doubleSpinBox_04_Function_f1_nan->value(),
                            ui->doubleSpinBox_04_Function_f1_inf->value()),
                        D_Math::Function_2D_to_1D(                                      //F2
                            ui->comboBox_04_Function_f2_F1Mask->currentIndex(),
                            ui->doubleSpinBox_04_Function_f2_a->value(),
                            ui->doubleSpinBox_04_Function_f2_b->value(),
                            ui->doubleSpinBox_04_Function_f2_c->value(),
                            ui->doubleSpinBox_04_Function_f2_d->value(),
                            ui->doubleSpinBox_04_Function_f2_e->value(),
                            ui->doubleSpinBox_04_Function_f2_f->value(),
                            ui->doubleSpinBox_04_Function_f2_nan->value(),
                            ui->doubleSpinBox_04_Function_f2_inf->value()),
                        D_Stat::Function_SingleStat(                                    //F3
                            ui->comboBox_04_Function_f3_vF2->currentIndex()),
                        D_Math::Function_2D_to_1D(                                      //F4
                            ui->comboBox_04_Function_f4_CenterF3->currentIndex(),
                            ui->doubleSpinBox_04_Function_f4_a->value(),
                            ui->doubleSpinBox_04_Function_f4_b->value(),
                            ui->doubleSpinBox_04_Function_f4_c->value(),
                            ui->doubleSpinBox_04_Function_f4_d->value(),
                            ui->doubleSpinBox_04_Function_f4_e->value(),
                            ui->doubleSpinBox_04_Function_f4_f->value(),
                            ui->doubleSpinBox_04_Function_f4_nan->value(),
                            ui->doubleSpinBox_04_Function_f4_inf->value()),
                        border_type,
                        ui->checkBox_04_Function_OnlyNonZero->isChecked()),
                    "Update_Img_Proc",
                    "Filter_Function");
        }
            break;

        case c_sT_FI_RANKORDER: //---------------------------------------------------------------   rank order filter
        {
            switch (ui->comboBox_04_RankOrder_MaskType->currentIndex()) {

            case c_MASK_MODE_CIRC:
            {
                ERR(D_VisDat_Proc::Filter_RankOrder_Circular(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        ui->doubleSpinBox_04_RankOrder_Quantil->value() / 100.0,
                        ui->doubleSpinBox_04_RankOrder_Radius->value()),
                    "Update_Img_Proc",
                    "Filter_RankOrder_Circular");
            }
                break;

            case c_MASK_MODE_RECT:
            {
                ERR(D_VisDat_Proc::Filter_RankOrder_Rect(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        ui->doubleSpinBox_04_RankOrder_Quantil->value() / 100.0,
                        ui->spinBox_04_RankOrder_Size_x->value(),
                        ui->spinBox_04_RankOrder_Size_y->value()),
                    "Update_Img_Proc",
                    "Filter_RankOrder_Rect");
            }
                break;

            case c_MASK_MODE_CUSTOM:
            {
                ERR(D_VisDat_Proc::Filter_RankOrder(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        ui->doubleSpinBox_04_RankOrder_Quantil->value() / 100.0),
                    "Update_Img_Proc",
                    "Filter_RankOrder");
            }
                break;

            }
        }
            break;

        case c_sT_FI_STAT: //---------------------------------------------------------------   statistic filter
        {
            switch (ui->comboBox_04_Statistic_MaskType->currentIndex()) {

            case c_MASK_MODE_CIRC:
            {
                ERR(D_VisDat_Proc::Filter_Stat_Circular(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        ui->doubleSpinBox_04_Statistic_Radius->value(),
                        ui->comboBox_04_Statistic_Stat->currentIndex(),
                        border_type),
                    "Update_Img_Proc",
                    "Filter_Stat_Circular");
            }
                break;

            case c_MASK_MODE_RECT:
            {
                ERR(D_VisDat_Proc::Filter_Stat_Rect(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        ui->spinBox_04_Statistic_Size_x->value(),
                        ui->spinBox_04_Statistic_Size_y->value(),
                        ui->comboBox_04_Statistic_Stat->currentIndex(),
                        border_type),
                    "Update_Img_Proc",
                    "Filter_Stat_Rect");
            }
                break;

            case c_MASK_MODE_CUSTOM:
            {
                ERR(D_VisDat_Proc::Filter_Stat(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        ui->comboBox_04_Statistic_Stat->currentIndex(),
                        border_type),
                    "Update_Img_Proc",
                    "Filter_Stat");
            }
                break;

            }
        }
            break;

        case c_sT_FI_SPEC: //---------------------------------------------------------------   special
        {
            switch (ui->comboBox_04_Special_Type->currentIndex()) {

            case 0://Bilateral
            {
                int diameter        = ui->spinBox_04_Special_Diameter->value();
                double sigma_color  = ui->doubleSpinBox_04_Special_Sigma_Color->value();
                double sigma_space  = ui->doubleSpinBox_04_Special_Sigma_Space->value();

                ERR(D_VisDat_Proc::Filter_Bilateral(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        diameter,
                        border_type,
                        sigma_color,
                        sigma_space),
                    "Update_Img_Proc",
                    "Filter_Bilateral");
            }
                break;

            case 1://Gabor
            {
                int size_x          = ui->spinBox_04_Special_Size_X->value() / 2;
                int size_y          = ui->spinBox_04_Special_Size_Y->value() / 2;
                double delta        = ui->doubleSpinBox_04_Special_Delta->value();
                double sigma        = ui->doubleSpinBox_04_Special_Sigma->value();
                double lambda       = ui->doubleSpinBox_04_Special_Lambda->value();
                double gamma        = ui->doubleSpinBox_04_Special_Gamma->value();
                double theta        = ui->doubleSpinBox_04_Special_Theta->value() * Grad2Rad;
                double psi          = ui->doubleSpinBox_04_Special_Psi->value()  * Grad2Rad;

                int out_depth = CV_32F;
                switch (ui->comboBox_04_Special_Depth->currentIndex()) {
                case 0:     out_depth = CV_32F;     break;
                case 1:     out_depth = CV_64F;     break;
                default:                            break;}

                ERR(D_VisDat_Proc::Filter_Gabor(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        size_x,
                        size_y,
                        border_type,
                        out_depth,
                        sigma,
                        theta,
                        lambda,
                        gamma,
                        psi,
                        delta),
                    "Update_Img_Proc",
                    "Filter_Gabor");
            }
                break;

            default:
                break;
            }
        }
            break;

        default:                //--------------------------------------------------------------   Default
            break;

        }
    }
        break;


    case c_T_MORPH: //==================================================================================================   MORPH

        switch (ui->comboBox_Type_05_Morphology->currentIndex()) {

        case c_sT_MO_ELEM:  //-------------------------------------------------------------------   Elemental
        {
            int             morph_type;
            int             elem_type;
            unsigned int    size_x      = ui->spinBox_05_Elem_Elem_Size_X->value() / 2;
            unsigned int    size_y      = ui->spinBox_05_Elem_Elem_Size_Y->value() / 2;
            unsigned int    iterations  = ui->spinBox_05_Elem_Iterations->value();
            int             border_type;

            switch (ui->comboBox_05_Elem_Morph_Type->currentIndex()) {
            case 0:     morph_type = MORPH_ERODE;           break;
            case 1:     morph_type = MORPH_DILATE;          break;
            case 2:     morph_type = MORPH_OPEN;            break;
            case 3:     morph_type = MORPH_CLOSE;           break;
            case 4:     morph_type = MORPH_GRADIENT;        break;
            case 5:     morph_type = MORPH_TOPHAT;          break;
            case 6:     morph_type = MORPH_BLACKHAT;        break;
            default:                                        return;}

            switch (ui->comboBox_05_Elem_Elem_Type->currentIndex()) {
            case 0:     elem_type = MORPH_RECT;             break;
            case 1:     elem_type = MORPH_CROSS;            break;
            case 2:     elem_type = MORPH_ELLIPSE;          break;
            default:                                        return;}

            switch (ui->comboBox_05_Elem_Border_Type->currentIndex()) {
            case 0:     border_type = BORDER_CONSTANT;      break;
            case 1:     border_type = BORDER_REPLICATE;     break;
            case 2:     border_type = BORDER_REFLECT;       break;
            //case 3:     border_type = BORDER_WRAP;          break;
            case 3:     border_type = BORDER_REFLECT_101;   break;
            //case 4:     border_type = BORDER_TRANSPARENT;   break;
            case 4:     border_type = BORDER_ISOLATED;      break;
            default:                                        return;}

            if(ui->comboBox_05_Elem_Morph_Type->currentIndex() <= 6) //basic
            {
                ERR(D_VisDat_Proc::Morphology_Elemental(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        morph_type,
                        elem_type,
                        size_x,
                        size_y,
                        border_type,
                        iterations),
                    "Update_Img_Proc",
                    "Morphology_Elemental");
            }
            else
            {
                ERR(D_VisDat_Proc::Morphology_Skeleton(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        elem_type,
                        size_x,
                        size_y,
                        border_type),
                    "Update_Img_Proc",
                    "Morphology_Skeleton");
            }
        }
            break;

        case c_sT_MO_MINMAXGIL:  //-------------------------------------------------------------------   min max gil
        {
            //min not implemented yet!

            //max
            ERR(D_VisDat_Proc::Filter_Maximum_1C(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->spinBox_05_MinMaxGil_SizeX->value(),
                    ui->spinBox_05_MinMaxGil_SizeY->value()),
                "Update_Img_Proc",
                "Filter_Maximum_1C");
        }
            break;

        case c_sT_MO_RECON:  //-------------------------------------------------------------------   reconstruction
        {
            ERR(D_VisDat_Proc::Morphology_Reconstruction(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    pStore->get_pVD(pos_Source2),
                    pStore->get_pVD(pos_Source3),
                    ui->doubleSpinBox_05_Reconstruction_Quantil->value() / 100.0),
                "Update_Img_Proc",
                "Morphology_Reconstruction");
        }
            break;

        case c_sT_MO_LOC_MAX:  //-------------------------------------------------------------------   min max local
        {
            ERR(D_VisDat_Proc::Morphology_LocMax_Rect(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->spinBox_05_LocalMaxima_Size_X->value(),
                    ui->spinBox_05_LocalMaxima_Size_Y->value()),
                "Update_Img_Proc",
                "Morphology_LocMax_Rect");
        }
            break;

        default:            //-------------------------------------------------------------------   Default
            break;

        }
        break;


    case c_T_MATH: //==================================================================================================   MATH

        switch (ui->comboBox_Type_06_Math->currentIndex()) {

        case c_sT_MA_1IMG:  //-------------------------------------------------------------------   1Img simple
        {
            double arg = ui->doubleSpinBox_06_1Img_Arg->value();

            switch (ui->comboBox_06_1Img_Type->currentIndex()) {

            case 0://not
                ERR(D_VisDat_Proc::Math_1img_Inversion(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1)),
                    "Update_Img_Proc",
                    "Math_1img_Inversion");
                break;

            case 1://add
                ERR(D_VisDat_Proc::Math_1img_Addition(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        arg),
                    "Update_Img_Proc",
                    "Math_1img_Addition");
                break;

            case 2://sub
                ERR(D_VisDat_Proc::Math_1img_Subtraction(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        arg),
                    "Update_Img_Proc",
                    "Math_1img_Subtraction");
                break;

            case 3://mult
                ERR(D_VisDat_Proc::Math_1img_Multiplication(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        arg),
                    "Update_Img_Proc",
                    "Math_1img_Multiplication");
                break;

            case 4://div
                ERR(D_VisDat_Proc::Math_1img_Division(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        arg),
                    "Update_Img_Proc",
                    "Math_1img_Division");
                break;

            case 5://pow
                ERR(D_VisDat_Proc::Math_1img_Power(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        arg),
                    "Update_Img_Proc",
                    "Math_1img_Power");
                break;

            case 6://root
                ERR(D_VisDat_Proc::Math_1img_Root(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1)),
                    "Update_Img_Proc",
                    "Math_1img_Root");
                break;

            case 7://log
                ERR(D_VisDat_Proc::Math_1img_Log(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1)),
                    "Update_Img_Proc",
                    "Math_1img_Log");
                break;

            default:
                break;
            }
        }
            break;

        case c_sT_MA_2IMG:  //-------------------------------------------------------------------   2Img simple
        {
            double weight_1     = ui->doubleSpinBox_06_2Img_Weight_1->value();
            double weight_2     = ui->doubleSpinBox_06_2Img_Weight_2->value();
            double weight_sum   = ui->doubleSpinBox_06_2Img_Weight_Sum->value();
            double scale        = ui->doubleSpinBox_06_2Img_Scale->value();
            int comp_type;

            switch (ui->comboBox_06_2Img_Comparator->currentIndex()) {
            case 0:     comp_type = CMP_EQ;                 break;
            case 1:     comp_type = CMP_GT;                 break;
            case 2:     comp_type = CMP_GE;                 break;
            case 3:     comp_type = CMP_LT;                 break;
            case 4:     comp_type = CMP_LE;                 break;
            case 5:     comp_type = CMP_NE;                 break;
            default:                                        break;}

            switch (ui->comboBox_06_2Img_Type->currentIndex()) {

            case 0://Add
                ERR(D_VisDat_Proc::Math_2img_Addition(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2)),
                    "Update_Img_Proc",
                    "Math_2img_Addition");
                break;

            case 1://Add weighted
                ERR(D_VisDat_Proc::Math_2img_AdditionWeighted(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        weight_1,
                        weight_2,
                        weight_sum),
                    "Update_Img_Proc",
                    "Math_2img_AdditionWeighted");
                break;

            case 2://Diff
                ERR(D_VisDat_Proc::Math_2img_Subtraction(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2)),
                    "Update_Img_Proc",
                    "Math_2img_Subtraction");
                break;

            case 3://Diff abs
                ERR(D_VisDat_Proc::Math_2img_SubtractionAbsolute(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2)),
                    "Update_Img_Proc",
                    "Math_2img_SubtractionAbsolute");
                break;

            case 4://Mult
                ERR(D_VisDat_Proc::Math_2img_Multiplication(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        scale),
                    "Update_Img_Proc",
                    "Math_2img_Multiplication");
                break;

            case 5://Div
                ERR(D_VisDat_Proc::Math_2img_Division(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        scale),
                    "Update_Img_Proc",
                    "Math_2img_Division");
                break;

            case 6://bit and
                ERR(D_VisDat_Proc::Math_2img_BitwiseAnd(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2)),
                    "Update_Img_Proc",
                    "Math_2img_BitwiseAnd");
                break;

            case 7://bit or
                ERR(D_VisDat_Proc::Math_2img_BitwiseOr(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2)),
                    "Update_Img_Proc",
                    "Math_2img_BitwiseOr");
                break;

            case 8://bit xor
                ERR(D_VisDat_Proc::Math_2img_BitwiseXor(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2)),
                    "Update_Img_Proc",
                    "Math_2img_BitwiseXor");
                break;

            case 9://min
                ERR(D_VisDat_Proc::Math_2img_Minimum(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2)),
                    "Update_Img_Proc",
                    "Math_2img_Minimum");
                break;

            case 10://max
                ERR(D_VisDat_Proc::Math_2img_Maximum(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2)),
                    "Update_Img_Proc",
                    "Math_2img_Maximum");
                break;

            case 11://comp
                ERR(D_VisDat_Proc::Math_2img_Compare(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        comp_type),
                    "Update_Img_Proc",
                    "Math_2img_Compare");
                break;

            default:
                break;
            }

        }
            break;

        case c_sT_MA_2IMG_FUNCTION:  //-------------------------------------------------------------------   2Img function
        {
            if(ui->checkBox_06_2ImgFunction_Force_8bit->isChecked())
                ERR(D_VisDat_Proc::Math_2img_Function_8bit(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        D_Math::Function_2D_to_1D_8bit(
                            ui->comboBox_06_2ImgFunction_Function->currentIndex(),
                            ui->doubleSpinBox_06_2ImgFunction_a->value(),
                            ui->doubleSpinBox_06_2ImgFunction_b->value(),
                            ui->doubleSpinBox_06_2ImgFunction_c->value(),
                            ui->doubleSpinBox_06_2ImgFunction_d->value(),
                            ui->doubleSpinBox_06_2ImgFunction_e->value(),
                            ui->doubleSpinBox_06_2ImgFunction_f->value(),
                            ui->doubleSpinBox_06_2ImgFunction_nan->value(),
                            ui->doubleSpinBox_06_2ImgFunction_inf->value())),
                    "Update_Img_Proc",
                    "Math_2img_Function_8bit");
            else
                ERR(D_VisDat_Proc::Math_2img_Function(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        D_Math::Function_2D_to_1D(
                            ui->comboBox_06_2ImgFunction_Function->currentIndex(),
                            ui->doubleSpinBox_06_2ImgFunction_a->value(),
                            ui->doubleSpinBox_06_2ImgFunction_b->value(),
                            ui->doubleSpinBox_06_2ImgFunction_c->value(),
                            ui->doubleSpinBox_06_2ImgFunction_d->value(),
                            ui->doubleSpinBox_06_2ImgFunction_e->value(),
                            ui->doubleSpinBox_06_2ImgFunction_f->value(),
                            ui->doubleSpinBox_06_2ImgFunction_nan->value(),
                            ui->doubleSpinBox_06_2ImgFunction_inf->value())),
                    "Update_Img_Proc",
                    "Math_2img_Function");
        }
            break;

        case c_sT_MA_2IMG_FUNCTION_COMPLEX:  //-------------------------------------------------------------------   2Img function complex
        {
            ERR(D_VisDat_Proc::Math_2img_Function_Complex(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        D_Math::Function_2D_to_1D_Complex(
                            ui->comboBox_06_2ImgFunction_Function->currentIndex(),
                            ui->doubleSpinBox_06_2ImgFunction_Complex_sx->value(),
                            ui->doubleSpinBox_06_2ImgFunction_Complex_ox->value(),
                            ui->doubleSpinBox_06_2ImgFunction_Complex_sy->value(),
                            ui->doubleSpinBox_06_2ImgFunction_Complex_oy->value(),
                            ui->doubleSpinBox_06_2ImgFunction_Complex_a->value(),
                            ui->doubleSpinBox_06_2ImgFunction_Complex_b->value(),
                            ui->doubleSpinBox_06_2ImgFunction_Complex_c->value(),
                            ui->doubleSpinBox_06_2ImgFunction_Complex_d->value(),
                            ui->doubleSpinBox_06_2ImgFunction_Complex_e->value(),
                            ui->doubleSpinBox_06_2ImgFunction_Complex_f->value(),
                            ui->doubleSpinBox_06_2ImgFunction_Complex_nan->value(),
                            ui->doubleSpinBox_06_2ImgFunction_Complex_inf->value())),
                    "Update_Img_Proc",
                    "Math_2img_Function_Complex");
        }
            break;

        case c_sT_MA_3IMG:  //-------------------------------------------------------------------   3Img math
        {
            switch (ui->comboBox_06_3Img_Type->currentIndex()) {

            case c_ssT_MA_3_4_ADD://add
                if(ui->checkBox_06_3Img_Value->isChecked())
                    ERR(D_VisDat_Proc::Math_3img_Addition(
                            pStore->get_pVD(pos_Dest),
                            pStore->get_pVD(pos_Source1),
                            pStore->get_pVD(pos_Source2),
                            pStore->get_pVD(pos_Source3),
                            ui->doubleSpinBox_06_3Img_Value->value()),
                        "Update_Img_Proc",
                        "Math_3img_Addition");
                else
                    ERR(D_VisDat_Proc::Math_3img_Addition(
                            pStore->get_pVD(pos_Dest),
                            pStore->get_pVD(pos_Source1),
                            pStore->get_pVD(pos_Source2),
                            pStore->get_pVD(pos_Source3)),
                        "Update_Img_Proc",
                        "Math_3img_Addition");
                break;

            case c_ssT_MA_3_4_MULT://mult
                if(ui->checkBox_06_3Img_Value->isChecked())
                    ERR(D_VisDat_Proc::Math_3img_Multiplication(
                            pStore->get_pVD(pos_Dest),
                            pStore->get_pVD(pos_Source1),
                            pStore->get_pVD(pos_Source2),
                            pStore->get_pVD(pos_Source3),
                            ui->doubleSpinBox_06_3Img_Value->value()),
                        "Update_Img_Proc",
                        "Math_3img_Multiplication");
                else
                    ERR(D_VisDat_Proc::Math_3img_Multiplication(
                            pStore->get_pVD(pos_Dest),
                            pStore->get_pVD(pos_Source1),
                            pStore->get_pVD(pos_Source2),
                            pStore->get_pVD(pos_Source3)),
                        "Update_Img_Proc",
                        "Math_3img_Multiplication");
                break;

            case c_ssT_MA_3_4_AND://and
                ERR(D_VisDat_Proc::Math_3img_BitwiseAnd(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        pStore->get_pVD(pos_Source3)),
                    "Update_Img_Proc",
                    "Math_3img_BitwiseAnd");
                break;

            case c_ssT_MA_3_4_OR://or
                ERR(D_VisDat_Proc::Math_3img_BitwiseOr(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        pStore->get_pVD(pos_Source3)),
                    "Update_Img_Proc",
                    "Math_3img_BitwiseOr");
                break;

            default:
                break;
            }
        }
            break;

        case c_sT_MA_4IMG:  //-------------------------------------------------------------------   4Img math
        {
            switch (ui->comboBox_06_4Img_Type->currentIndex()) {

            case c_ssT_MA_3_4_ADD://add
                if(ui->checkBox_06_4Img_Value->isChecked())
                    ERR(D_VisDat_Proc::Math_4img_Addition(
                            pStore->get_pVD(pos_Dest),
                            pStore->get_pVD(pos_Source1),
                            pStore->get_pVD(pos_Source2),
                            pStore->get_pVD(pos_Source3),
                            pStore->get_pVD(pos_Source4),
                            ui->doubleSpinBox_06_4Img_Value->value()),
                        "Update_Img_Proc",
                        "Math_4img_Addition");
                else
                    ERR(D_VisDat_Proc::Math_4img_Addition(
                            pStore->get_pVD(pos_Dest),
                            pStore->get_pVD(pos_Source1),
                            pStore->get_pVD(pos_Source2),
                            pStore->get_pVD(pos_Source3),
                            pStore->get_pVD(pos_Source4)),
                        "Update_Img_Proc",
                        "Math_4img_Addition");
                break;

            case c_ssT_MA_3_4_MULT://mult
                if(ui->checkBox_06_4Img_Value->isChecked())
                    ERR(D_VisDat_Proc::Math_4img_Multiplication(
                            pStore->get_pVD(pos_Dest),
                            pStore->get_pVD(pos_Source1),
                            pStore->get_pVD(pos_Source2),
                            pStore->get_pVD(pos_Source3),
                            pStore->get_pVD(pos_Source4),
                            ui->doubleSpinBox_06_4Img_Value->value()),
                        "Update_Img_Proc",
                        "Math_4img_Multiplication");
                else
                    ERR(D_VisDat_Proc::Math_4img_Multiplication(
                            pStore->get_pVD(pos_Dest),
                            pStore->get_pVD(pos_Source1),
                            pStore->get_pVD(pos_Source2),
                            pStore->get_pVD(pos_Source3),
                            pStore->get_pVD(pos_Source4)),
                        "Update_Img_Proc",
                        "Math_4img_Multiplication");
                break;

            case c_ssT_MA_3_4_AND://and
                ERR(D_VisDat_Proc::Math_4img_BitwiseAnd(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        pStore->get_pVD(pos_Source3),
                        pStore->get_pVD(pos_Source4)),
                    "Update_Img_Proc",
                    "Math_4img_BitwiseAnd");
                break;

            case c_ssT_MA_3_4_OR://or
                ERR(D_VisDat_Proc::Math_4img_BitwiseOr(
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        pStore->get_pVD(pos_Source3),
                        pStore->get_pVD(pos_Source4)),
                    "Update_Img_Proc",
                    "Math_4img_BitwiseOr");
                break;

            default:
                break;
            }
        }
            break;

        default:            //-------------------------------------------------------------------   Default
            break;

        }
        break;


    case c_T_TRANS: //==================================================================================================   TRANS

        switch (ui->comboBox_Type_07_Transform->currentIndex()) {

        case c_sT_TR_DIST:  //-------------------------------------------------------------------   Distance
        {
            int metric;
            int precision;

            switch (ui->comboBox_07_Dist_Metric->currentIndex()) {
            case 0:     metric = DIST_L2;               break;
            case 1:     metric = DIST_L1;               break;
            case 2:     metric = DIST_C;                break;
            case 3:     metric = DIST_L12;              break;
            case 4:     metric = DIST_FAIR;             break;
            case 5:     metric = DIST_WELSCH;           break;
            case 6:     metric = DIST_HUBER;            break;
            default:                                    return;}

            switch (ui->comboBox_07_Dist_Precision->currentIndex()) {
            case 0:     precision = DIST_MASK_PRECISE;  break;
            case 1:     precision = DIST_MASK_3;        break;
            case 2:     precision = DIST_MASK_5;        break;
            default:                                    return;}

            ERR(D_VisDat_Proc::Transformation_Distance(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    metric,
                    precision),
                "Update_Img_Proc",
                "Transformation_Distance");
        }
            break;

        case c_sT_TR_WATERSHADE:    //-----------------------------------------------------------   Watershade
        {
            if(ui->comboBox_07_Watershed_Implementation->currentIndex() == 0)//ImageD
            {
                int connectivity = ui->comboBox_07_WatershedCustom_Connectivity->currentIndex() == 0 ? 4 : 8;

                ERR(D_VisDat_Proc::Transformation_Watershed_Custom(
                        SlicingFromUi(),
                        pStore->get_pVD(pos_Dest),
                        pStore->get_pVD(pos_Source1),
                        pStore->get_pVD(pos_Source2),
                        pStore->get_pVD(pos_Source3),
                        connectivity),
                    "Update_Img_Proc",
                    "Transformation_Watershed_Custom");
            }
            else
            {
                if(ui->checkBox_07_Watershed_Auto->isChecked())
                {
                    int connectivity;
                    switch (ui->comboBox_07_Watershed_Connectivity->currentIndex()) {
                    case 0:     connectivity = 8;           break;
                    case 1:     connectivity = 4;           break;
                    default:                                break;}

                    ERR(D_VisDat_Proc::Transformation_Watershed_Auto(
                            SlicingFromUi(),
                            pStore->get_pVD(pos_Dest),
                            pStore->get_pVD(pos_Source1),
                            pStore->get_pVD(pos_Source2),
                            ui->checkBox_07_Watershed_InclNonSeed->isChecked(),
                            ui->checkBox_07_Watershed_8bit->isChecked(),
                            ui->checkBox_07_Watershed_ExclBorder->isChecked()),
                        "Update_Img_Proc",
                        "Transformation_Watershed_Auto");
                }
                else
                {
                    ERR(D_VisDat_Proc::Transformation_Watershed(
                            SlicingFromUi(),
                            pStore->get_pVD(pos_Dest),
                            pStore->get_pVD(pos_Source1),
                            pStore->get_pVD(pos_Source2)),
                        "Update_Img_Proc",
                        "Transformation_Watershed");
                }
            }
        }
            break;

        case c_sT_TR_FOURIER:       //-----------------------------------------------------------   Fourier
        {
            ERR(D_VisDat_Proc::Transformation_Fourier(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    pStore->get_pVD(pos_Source2),
                    ui->checkBox_07_Fourier_Input_Complex->isChecked(),
                    ui->checkBox_07_Fourier_Invers->isChecked(),
                    ui->checkBox_07_Fourier_ForceFFT->isChecked(),
                    ui->checkBox_07_Fourier_Output_RealOnly->isChecked(),
                    ui->comboBox_07_Fourier_Output_ComplexMode->currentIndex(),
                    ui->checkBox_07_Fourier_Output_Scale->isChecked(),
                    ui->checkBox_07_Fourier_Output_Centered->isChecked(),
                    ui->checkBox_07_Fourier_Output_no_f0->isChecked()),
                "Update_Img_Proc",
                "Transformation_Fourier");
        }
            break;

        default:            //-------------------------------------------------------------------   Default
            break;

        }
        break;


    case c_T_FEATURE://==================================================================================================   SELECT

        switch (ui->comboBox_Type_08_Feature->currentIndex()) {

        case c_sT_FE_VALUE:  //-------------------------------------------------------------------   Value
        {
            int connectivity;
            switch (ui->comboBox_08_FeatVal_Connectivity->currentIndex()) {
            case 0:     connectivity = 8;           break;
            case 1:     connectivity = 4;           break;
            default:                                break;}

            ERR(D_VisDat_Proc::Feature_Value(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->comboBox_08_FeatVal_Feature->currentIndex(),
                    connectivity),
                "Update_Img_Proc",
                "Feature_Value");
        }
            break;

        case c_sT_FE_CONTEXT_VALUE:  //-------------------------------------------------------------------   Context Value
        {
            int connectivity;
            switch (ui->comboBox_08_FeatContextVal_Connectivity->currentIndex()) {
            case 0:     connectivity = 8;           break;
            case 1:     connectivity = 4;           break;
            default:                                break;}

            ERR(D_VisDat_Proc::FeatureContext_Value(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->comboBox_08_FeatContextVal_DistPt1->currentIndex(),
                    ui->comboBox_08_FeatContextVal_DistPt2->currentIndex(),
                    ui->doubleSpinBox_08_FeatContextVal_DistMin->value(),
                    ui->doubleSpinBox_08_FeatContextVal_DistMax->value(),
                    ui->comboBox_08_FeatContextVal_Feat->currentIndex(),
                    ui->comboBox_08_FeatContextVal_Stat->currentIndex(),
                    connectivity),
                "Update_Img_Proc",
                "FeatureContext_Value");
        }
            break;

        case c_sT_FE_SELECT:  //-------------------------------------------------------------------   Select
        {
            double feature_min = ui->doubleSpinBox_08_Select_Min->value();
            double feature_max = ui->doubleSpinBox_08_Select_Max->value();

            int connectivity;
            switch (ui->comboBox_08_Select_Connectivity->currentIndex()) {
            case 0:     connectivity = 8;           break;
            case 1:     connectivity = 4;           break;
            default:                                break;}

            ERR(D_VisDat_Proc::Feature_Select(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->comboBox_08_Select_Type->currentIndex(),
                    feature_min,
                    feature_max,
                    connectivity),
                "Update_Img_Proc",
                "Feature_Select");
        }
            break;

        case c_sT_FE_CONTEXT_SELECT:    //-------------------------------------------------------------------   Context Select
        {
            int connectivity;
            switch (ui->comboBox_08_FeatContextVal_Connectivity->currentIndex()) {
            case 0:     connectivity = 8;           break;
            case 1:     connectivity = 4;           break;
            default:                                break;}

            ERR(D_VisDat_Proc::FeatureContext_Select(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->comboBox_08_FeatContextVal_DistPt1->currentIndex(),
                    ui->comboBox_08_FeatContextVal_DistPt2->currentIndex(),
                    ui->doubleSpinBox_08_FeatContextVal_DistMin->value(),
                    ui->doubleSpinBox_08_FeatContextVal_DistMax->value(),
                    ui->comboBox_08_FeatContextVal_Feat->currentIndex(),
                    ui->comboBox_08_FeatContextVal_Stat->currentIndex(),
                    ui->doubleSpinBox_08_FeatContextSelect_ThresMin->value(),
                    ui->doubleSpinBox_08_FeatContextSelect_ThresMax->value(),
                    connectivity),
                "Update_Img_Proc",
                "FeatureContext_Value");
        }
            break;

        case c_sT_FE_CONNECT:    //-------------------------------------------------------------------   Connect
        {
            int connectivity = 8;
            switch (ui->comboBox_08_Connect_Connectivity->currentIndex()) {
            case 0:     connectivity = 8;           break;
            case 1:     connectivity = 4;           break;
            default:                                break;}

            ERR(D_VisDat_Proc::Feature_Connect(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->comboBox_08_Connect_DistPt1->currentIndex(),
                    ui->comboBox_08_Connect_DistPt2->currentIndex(),
                    ui->doubleSpinBox_08_Connect_DistMin->value(),
                    ui->doubleSpinBox_08_Connect_DistMax->value(),
                    ui->comboBox_08_Connect_Feat1->currentIndex(),
                    ui->comboBox_08_Connect_Feat2->currentIndex(),
                    D_Math::Condition_2D(
                        ui->comboBox_08_Connect_Cond->currentIndex(),
                        ui->doubleSpinBox_08_Connect_Cond_a->value(),
                        ui->doubleSpinBox_08_Connect_Cond_b->value(),
                        ui->doubleSpinBox_08_Connect_Cond_c->value(),
                        ui->doubleSpinBox_08_Connect_Cond_d->value(),
                        ui->doubleSpinBox_08_Connect_Cond_e->value(),
                        ui->doubleSpinBox_08_Connect_Cond_f->value(),
                        ui->doubleSpinBox_08_Connect_Cond_g->value(),
                        ui->doubleSpinBox_08_Connect_Cond_h->value()),
                    ui->comboBox_08_Connect_ConnectType->currentIndex(),
                    connectivity,
                    ui->spinBox_08_Connect_Thickness->value()),
                "Update_Img_Proc",
                "Feature_Connect");
        }
            break;

        case c_sT_FE_REDUCE:  //-------------------------------------------------------------------   Reduce
        {
            int     connectivity;
            switch (ui->comboBox_08_Reduce_Connectivity->currentIndex()) {
            case 0: connectivity = 8;    break;
            case 1: connectivity = 4;    break;
            default:                    break;}

            ERR(D_VisDat_Proc::Geometric_Reduce(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->comboBox_08_Reduce_Type->currentIndex(),
                    connectivity,
                    ui->spinBox_08_Reduce_Thickness->value(),
                    ui->spinBox_08_Reduce_Value->value()),
                "Update_Img_Proc",
                "Geometric_Reduce");
        }
            break;

        case c_sT_FE_VISUALIZE: //---------------------------------------------------------------   Visualize
        {
            int connectivity;
            switch (ui->comboBox_08_Visualize_Connectivity->currentIndex()) {
            case 0:     connectivity = 8;           break;
            case 1:     connectivity = 4;           break;
            default:                                return;}

            ERR(D_VisDat_Proc::Feature_Visualize(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->comboBox_08_Visualize_Feature->currentIndex(),
                    connectivity,
                    ui->spinBox_08_Visualize_Thickness->value(),
                    ui->doubleSpinBox_08_Visualize_Scale->value()),
                "Update_Img_Proc",
                "Feature_Visualize");
        }
            break;

        case c_sT_FE_VALUESTAT: //---------------------------------------------------------------   value statistic
        {
            int connectivity;
            switch (ui->comboBox_08_ValueStat_Connectivity->currentIndex()) {
            case 0:     connectivity = 8;           break;
            case 1:     connectivity = 4;           break;
            default:                                return;}

            ERR(D_VisDat_Proc::ValueStat(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    pStore->get_pVD(pos_Source2),
                    ui->comboBox_08_ValueStat_Stat->currentIndex(),
                    connectivity),
                "Update_Img_Proc",
                "ValueStat");
        }
            break;

        case c_sT_FE_VALUESTAT_SELECT: //---------------------------------------------------------------   value statistic
        {
            int connectivity;
            switch (ui->comboBox_08_ValueStatSelect_Connectivity->currentIndex()) {
            case 0:     connectivity = 8;           break;
            case 1:     connectivity = 4;           break;
            default:                                return;}

            ERR(D_VisDat_Proc::ValueStat_Select(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    pStore->get_pVD(pos_Source2),
                    ui->comboBox_08_ValueStatSelect_Stat->currentIndex(),
                    ui->doubleSpinBox_08_ValueStatSelect_Min->value(),
                    ui->doubleSpinBox_08_ValueStatSelect_Max->value(),
                    connectivity),
                "Update_Img_Proc",
                "ValueStat_Select");
        }
            break;

        default:            //-------------------------------------------------------------------   Default
            break;

        }
        break;


    case c_T_OTHER: //==================================================================================================   OTHER

        switch (ui->comboBox_Type_09_Other->currentIndex()) {

        case c_sT_OT_EQUAL_HIST:    //-----------------------------------------------------------   Hist Equal

            ERR(D_VisDat_Proc::Histogram_Equalize(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1)),
                "Update_Img_Proc",
                "Histogram_Equalize");

            break;

        case c_sT_OT_GAMMA_SPREAD:    //-----------------------------------------------------------   Gamma Spread

            ERR(D_VisDat_Proc::GammaSpread(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->doubleSpinBox_09_GammaSpread_Gamma->value(),
                    ui->doubleSpinBox_09_GammaSpread_InMin->value(),
                    ui->doubleSpinBox_09_GammaSpread_InMax->value(),
                    ui->doubleSpinBox_09_GammaSpread_OutMin->value(),
                    ui->doubleSpinBox_09_GammaSpread_OutMax->value(),
                    ui->checkBox_09_GammaSpread_Force8bit->isChecked()),
                "Update_Img_Proc",
                "GammaSpread");

            break;

        case c_sT_OT_LABEL_NUMBER:    //-----------------------------------------------------------   Label Numbers

            ERR(D_VisDat_Proc::Draw_Label_Numbers(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    pStore->get_pVD(pos_Source2),
                    ui->doubleSpinBox_09_LabelNo_Scale->value(),
                    ui->spinBox_09_LabelNo_Thickness->value(),
                    ui->checkBox_09_LabelNo_Position->isChecked()),
                "Update_Img_Proc",
                "Draw_Label_Numbers");

            break;

        case c_sT_OT_NEIGHBORHOOD_CONFIG:    //-----------------------------------------------------------   Neighborhood configs
        {
            double euler_number = 0;

            ERR(D_VisDat_Proc::Euler_Number(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    &euler_number,
                    pStore->get_pVD(pos_Source1)),
                "Update_Img_Proc",
                "Neighborhood_Configs");

            ui->label_09_NeighborhoodConfig_Euler_Number->setText(QString::number(euler_number));
        }
            break;

        case c_sT_OT_MOTION_FIELD:          //-----------------------------------------------------------   Motion Field
        {
            ERR(D_VisDat_Proc::MotionField(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->spinBox_09_MotionField_SizeSpace->value(),
                    ui->spinBox_09_MotionField_SizeTime->value()),
                "Update_Img_Proc",
                "MotionField");
        }
            break;

        case c_sT_OT_CLASS_KNN:          //-----------------------------------------------------------   kNN
        {
            ERR(D_VisDat_Proc::ClassBorder_kNN(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    pStore->get_pVD(pos_Source2),
                    ui->spinBox_09_kNN_n->value()),
                "Update_Img_Proc",
                "ClassBorder_kNN");
        }
            break;

        case c_sT_OT_HDR:          //-----------------------------------------------------------   HDR
        {
            ERR(D_VisDat_Proc::HDR(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->comboBox_09_HDR_Dim->currentIndex(),
                    ui->doubleSpinBox_09_HDR_Exposure_Min->value(),
                    ui->doubleSpinBox_09_HDR_Exposure_Factor->value(),
                    ui->checkBox_09_HDR_Project->isChecked(),
                    ui->comboBox_09_HDR_ProjectStat->currentIndex(),
                    ui->checkBox_09_HDR_Thresh->isChecked(),
                    ui->doubleSpinBox_09_HDR_Thresh_Low->value(),
                    ui->doubleSpinBox_09_HDR_Thresh_High->value()),
                "Update_Img_Proc",
                "HDR");
        }
            break;

        case c_sT_OT_RELATION_STAT:          //-----------------------------------------------------------   relation stat
        {
            ERR(D_VisDat_Proc::DistancesStat(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    D_Stat::Function_SingleStat(
                        ui->comboBox_09_RelationStat_StatDistance->currentIndex())),
                "Update_Img_Proc",
                "DistancesStat");
        }
            break;

        case c_sT_OT_ZERNIKE_STACK:          //-----------------------------------------------------------   zernike stack
        {
            ERR(D_VisDat_Proc::ZernikeStack(
                    pStore->get_pVD(pos_Dest),
                    ui->spinBox_09_ZernikeStack_Radius->value(),
                    ui->spinBox_09_ZernikeStack_J->value()),
                "Update_Img_Proc",
                "ZernikeStack");
        }
            break;

        case c_sT_OT_MICHELSON:          //-----------------------------------------------------------   michelson interferometer
        {
            ERR(D_VisDat_Proc::InterferometerMichelson(
                    pStore->get_pVD(pos_Dest),
                    ui->spinBox_09_Michelson_Scene_Size_X->value(),
                    ui->spinBox_09_Michelson_Scene_Size_Y->value(),
                    ui->spinBox_09_Michelson_Scene_Size_Z->value(),
                    ui->doubleSpinBox_09_Michelson_Scale_um->value() / ui->spinBox_09_Michelson_Scale_px->value(),
                    ui->doubleSpinBox_09_Michelson_Wavelength->value(),
                    ui->doubleSpinBox_09_Michelson_Source_distance->value(),
                    ui->doubleSpinBox_09_Michelson_Detector_distance->value(),
                    ui->doubleSpinBox_09_Michelson_Mirror1_distance->value(),
                    ui->doubleSpinBox_09_Michelson_Mirror2_distance->value(),
                    ui->doubleSpinBox_09_Michelson_Mirror1_angle_x->value() * Grad2Rad,
                    ui->doubleSpinBox_09_Michelson_Mirror1_angle_y->value() * Grad2Rad,
                    ui->doubleSpinBox_09_Michelson_Mirror2_angle_x->value() * Grad2Rad,
                    ui->doubleSpinBox_09_Michelson_Mirror2_angle_y->value() * Grad2Rad,
                    ui->comboBox_09_Michelson_Show_IorE->currentIndex() == 1,
                    ui->checkBox_09_Michelson_Beam_atSO_SO->isChecked(),
                    ui->checkBox_09_Michelson_Beam_atSO_M1_SO->isChecked(),
                    ui->checkBox_09_Michelson_Beam_atSO_SP_M2_SP_SO->isChecked(),
                    ui->checkBox_09_Michelson_Beam_atM1_SO->isChecked(),
                    ui->checkBox_09_Michelson_Beam_atM1_M1_SO->isChecked(),
                    ui->checkBox_09_Michelson_Beam_atM2_SP_SO->isChecked(),
                    ui->checkBox_09_Michelson_Beam_atM2_M2_SP_SO->isChecked(),
                    ui->checkBox_09_Michelson_Beam_atDE_SP_M1_SO->isChecked(),
                    ui->checkBox_09_Michelson_Beam_atDE_M2_SP_SO->isChecked()),
                "Update_Img_Proc",
                "InterferometerMichelson");
        }
            break;

        case c_sT_OT_RADIOMETRIC_STEREO:          //-----------------------------------------------------------   radiometric stereo
        {
            ERR(D_VisDat_Proc::RadiometricStereo(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    pStore->get_pVD(pos_Source2),
                    pStore->get_pVD(pos_Source3),
                    ui->doubleSpinBox_09_RadiometricStereo_X1->value(),
                    ui->doubleSpinBox_09_RadiometricStereo_Y1->value(),
                    ui->doubleSpinBox_09_RadiometricStereo_Z1->value(),
                    ui->doubleSpinBox_09_RadiometricStereo_X2->value(),
                    ui->doubleSpinBox_09_RadiometricStereo_Y2->value(),
                    ui->doubleSpinBox_09_RadiometricStereo_Z2->value(),
                    ui->doubleSpinBox_09_RadiometricStereo_X3->value(),
                    ui->doubleSpinBox_09_RadiometricStereo_Y3->value(),
                    ui->doubleSpinBox_09_RadiometricStereo_Z3->value(),
                    ui->comboBox_09_RadiometricStereo_OutMode->currentIndex()),
                "Update_Img_Proc",
                "RadiometricStereo");
        }
            break;

        default:            //-------------------------------------------------------------------   Default
            break;

        }
        break;

    case c_T_DIM: //==================================================================================================   MAKRO
    {
        switch (ui->comboBox_Type_10_Dimension->currentIndex()) {

        case c_sT_DI_PICK:
        {
            vector<int> pick_pos(c_DIM_NUMBER_OF, -1);//-1 means keep all
            if(ui->checkBox_10_Pick_X->isChecked())     pick_pos[c_DIM_X] = ui->spinBox_10_Pick_X->value();
            if(ui->checkBox_10_Pick_Y->isChecked())     pick_pos[c_DIM_Y] = ui->spinBox_10_Pick_Y->value();
            if(ui->checkBox_10_Pick_Z->isChecked())     pick_pos[c_DIM_Z] = ui->spinBox_10_Pick_Z->value();
            if(ui->checkBox_10_Pick_T->isChecked())     pick_pos[c_DIM_T] = ui->spinBox_10_Pick_T->value();
            if(ui->checkBox_10_Pick_S->isChecked())     pick_pos[c_DIM_S] = ui->spinBox_10_Pick_S->value();
            if(ui->checkBox_10_Pick_P->isChecked())     pick_pos[c_DIM_P] = ui->spinBox_10_Pick_P->value();

            ERR(D_VisDat_Proc::Dim_Pick(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    pick_pos),
                "Update_Img_Proc",
                "Dim_Pick");
        }
            break;

        case c_sT_DI_CROP:
        {
            D_VisDat_Range crop_range;

            if(ui->checkBox_10_Crop_X->isChecked())
                crop_range.set_Range_X(
                            ui->spinBox_10_Crop_Min_X->value(),
                            ui->spinBox_10_Crop_Max_X->value());

            if(ui->checkBox_10_Crop_Y->isChecked())
                crop_range.set_Range_Y(
                            ui->spinBox_10_Crop_Min_Y->value(),
                            ui->spinBox_10_Crop_Max_Y->value());

            if(ui->checkBox_10_Crop_Z->isChecked())
                crop_range.set_Range_Z(
                            ui->spinBox_10_Crop_Min_Z->value(),
                            ui->spinBox_10_Crop_Max_Z->value());

            if(ui->checkBox_10_Crop_T->isChecked())
                crop_range.set_Range_T(
                            ui->spinBox_10_Crop_Min_T->value(),
                            ui->spinBox_10_Crop_Max_T->value());

            if(ui->checkBox_10_Crop_S->isChecked())
                crop_range.set_Range_S(
                            ui->spinBox_10_Crop_Min_S->value(),
                            ui->spinBox_10_Crop_Max_S->value());

            if(ui->checkBox_10_Crop_P->isChecked())
                crop_range.set_Range_P(
                            ui->spinBox_10_Crop_Min_P->value(),
                            ui->spinBox_10_Crop_Max_P->value());

            ERR(D_VisDat_Proc::Dim_Crop(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    crop_range),
                "Update_Img_Proc",
                "Dim_Crop");
        }
            break;

        case c_sT_DI_PROJECT:
        {
            ERR(D_VisDat_Proc::Dim_Project(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->comboBox_10_Project_Dimension->currentIndex(),
                    ui->comboBox_10_Project_Stat->currentIndex(),
                    ui->checkBox_10_Project_8bit->isChecked() ? CV_8UC1 : CV_64FC1),
                "Update_Img_Proc",
                "Dim_Project");
        }
            break;

        case c_sT_DI_DESERIALISE:
        {
            ERR(D_VisDat_Proc::Dim_Deserialise(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->comboBox_10_Deserialise_Dimension_In->currentIndex(),
                    ui->comboBox_10_Deserialise_Dimension_Out->currentIndex(),
                    ui->spinBox_10_Deserialise_Spacing->value()),
                "Update_Img_Proc",
                "Dim_Project");
        }
            break;

        case c_sT_DI_PAGES2COLOR:
        {
            ERR(D_VisDat_Proc::Dim_Pages2Color(
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    ui->spinBox_10_Page2Color_R->value(),
                    ui->spinBox_10_Page2Color_G->value(),
                    ui->spinBox_10_Page2Color_B->value()),
                "Update_Img_Proc",
                "Dim_Project");
        }
            break;

        case c_sT_DI_STITCH_BORDER:
        {
            Stitcher::Mode mode = Stitcher::SCANS;
            if(ui->comboBox_10_Stitching_Mode->currentIndex() != 0)
                mode = Stitcher::PANORAMA;

            ERR(D_VisDat_Proc::Stitch_Border_rel(
                    SlicingFromUi(),
                    pStore->get_pVD(pos_Dest),
                    pStore->get_pVD(pos_Source1),
                    pStore->get_pVD(pos_Source2),
                    pStore->get_pVD(pos_Source3),
                    pStore->get_pVD(pos_Source4),
                    ui->doubleSpinBox_10_Stitching_Border_R->value() / 100.0,
                    ui->doubleSpinBox_10_Stitching_Border_B->value() / 100.0,
                    ui->doubleSpinBox_10_Stitching_Overlap_R->value() / 100.0,
                    ui->doubleSpinBox_10_Stitching_Overlap_B->value() / 100.0,
                    mode),
                "Update_Img_Proc",
                "Stitch_Border_rel");
        }
            break;

        default:
            break;
        }
    }
        break;

    default:        //==================================================================================================   DEFAULT
        break;
    }


    times[c_TIME_IMG_PROC] = timer.elapsed();
    pStore->set_times(pos_Dest, c_TIME_IMG_PROC, timer.elapsed());

    Update_Image();
    Update_Descriptions();
    Update_vSources_vDestinations();
    Update_Destinations_Info();
    Update_HistSettings();
    Update_ParameterList();
    ui->label_Chain_Updated_Val->setText(QDateTime::currentDateTime().toString());

    if(ui->action_Autoupdate_Hist_on_Step->isChecked() || ui->tabWidget_Output->currentIndex() == c_Out_Hist)
        Update_Hist();

    if(ui->action_Autoupdate_Times_on_Step->isChecked() || ui->tabWidget_Output->currentIndex() == c_Out_Time)
        Update_Times();

    if(ui->action_Autoupdate_3D_View->isChecked() || ui->tabWidget_Output->currentIndex() == c_Out_Plot_3D)
        Update_3DPlot();

    if(ui->tabWidget_Output->currentIndex() == c_Out_Image_3D)
        Update_3DImage();

    //check, if complex
    ui->comboBox_View_Complex->setEnabled(pStore->get_Adress(pos_Dest)->channels() == 2);

    for(size_t d = 0; d < vUI_Destinations.size(); d++)
    {
        (*pSteps)[vUI_Destinations[d]]->set_need_Update(true);
        if(ui->action_Autoupdate_Next_Step->isChecked())
            (*pSteps)[vUI_Destinations[d]]->Update_from_extern();
    }

    ui->graphicsView_Viewer->setToolTip("");

    //this->setEnabled(true);
}

void D_StepWindow::Update_ParameterList()
{
    QSL_Parameters.clear();
    QS_Type = "Default";
    QS_Subtype = "Default";

    switch (ui->comboBox_Type_Main->currentIndex()) {

    case c_T_SOURCE: //==================================================================================================   SOURCE
        QS_Type = "Source";

        switch (ui->comboBox_Type_00_Source->currentIndex()) {

        case c_sT_SO_LOAD:      //-------------------------------------------------------------------   Load
        {
            QS_Subtype = "Load";

            /*
            switch (ui->comboBox_00_Load_Mode->currentIndex()) {

            case 0://Single page
                QSL_Parameters.append("mode_single");
                break;

            case 1://multi page
                QSL_Parameters.append("mode_multi");
                QSL_Parameters.append("page_" + QString::number(ui->spinBox_00_Load_Mulit_Page->value()));
                break;

            default:
                break;
            }
            */
        }
            break;

        case c_sT_SO_DUPLICATE: //-------------------------------------------------------------------   Duplictae
            QS_Subtype = "Duplicate";
            break;

        case c_sT_SO_SAMPLE:    //-------------------------------------------------------------------   Sample
        {
            QS_Subtype = "Sample";
            if(FIL_Examples.isEmpty())              return;
            QSL_Parameters.append("sample_" + QString::number(ui->comboBox_00_Sample_Paths->currentIndex()));
        }
            break;

        default:                //-------------------------------------------------------------------   Default
            break;

        }
        break;


    case c_T_EDIT:  //==================================================================================================   EDIT
        QS_Type = "Edit";

        switch (ui->comboBox_Type_01_Edit->currentIndex()) {

        case c_sT_ED_CROP:  //-------------------------------------------------------------------   Crop
            QS_Subtype = "Crop";

            switch (ui->comboBox_01_Crop_Shape->currentIndex()) {

            case 0://Rect Rel
                QSL_Parameters.append("shape_rectRel");
                QSL_Parameters.append("X1_" + QString::number(ui->doubleSpinBox_01_Crop_Rect_X1->value()));
                QSL_Parameters.append("Y1_" + QString::number(ui->doubleSpinBox_01_Crop_Rect_Y1->value()));
                QSL_Parameters.append("X2_" + QString::number(ui->doubleSpinBox_01_Crop_Rect_X2->value()));
                QSL_Parameters.append("Y2_" + QString::number(ui->doubleSpinBox_01_Crop_Rect_Y2->value()));
                break;

            case 1://Rect Rel
                QSL_Parameters.append("shape_rectAbs");
                QSL_Parameters.append("offsetX_" + QString::number(ui->spinBox_01_Crop_RectAbs_Offset_X->value()));
                QSL_Parameters.append("offsetY_" + QString::number(ui->spinBox_01_Crop_RectAbs_Offset_Y->value()));
                QSL_Parameters.append("sizeX_" + QString::number(ui->spinBox_01_Crop_RectAbs_Size_X->value()));
                QSL_Parameters.append("sizeY_" + QString::number(ui->spinBox_01_Crop_RectAbs_Size_Y->value()));
                break;

            default:
                break;
            }

            break;

        case c_sT_ED_FLOODFILL:  //-------------------------------------------------------------------   Floodfill
        {
            QS_Subtype = "Floodfill";
            QSL_Parameters.append("value_" + QString::number(ui->doubleSpinBox_01_Floodfill_Value_Fill->value()));

            switch (ui->comboBox_01_Floodfill_Type->currentIndex()) {

            case 0://Boundary
                break;

            default:
                break;
            }

        }
            break;

        case c_sT_ED_PADDING:  //-------------------------------------------------------------------   Padding
        {
            QS_Subtype = "Padding";
            //QSL_Parameters.append("width_" + QString::number(ui->spinBox_01_Padding_Width->value()));

            QString QS_border = "border_";
            switch (ui->comboBox_01_Padding_Type->currentIndex()) {
            case 0:     QS_border.append("default");        break;
            case 1:     QS_border.append("constant");       break;
            case 2:     QS_border.append("replicate");      break;
            case 3:     QS_border.append("reflect");        break;
            //case 3:   border_type = BORDER_WRAP;          break;
            case 4:     QS_border.append("reflect101");     break;
            //case 4:   border_type = BORDER_TRANSPARENT;   break;
            case 5:     QS_border.append("isolated");       break;
            default:                                        break;}
            QSL_Parameters.append(QS_border);
        }
            break;

        default:            //-------------------------------------------------------------------   Default
            break;

        }
        break;


    case c_T_CONV:  //==================================================================================================   CONVERT
        QS_Type = "Convert";

        switch (ui->comboBox_Type_02_Convert->currentIndex()) {

        case c_sT_CO_COLOR:     //-------------------------------------------------------------------   Color
        {
            QS_Subtype = "Color";
            QString QS_col = "convert_";

            if(ui->comboBox_02_Color_Direction_Top->currentIndex() == 1)
            {
                     if(ui->radioButton_02_Color_RGB_BGR->isChecked())      QS_col.append("BGR2RGB");
                else if(ui->radioButton_02_Color_BGR_RGB->isChecked())      QS_col.append("RGB2BGR");
                else if(ui->radioButton_02_Color_Grey_RGB->isChecked())     QS_col.append("GRAY2RGB");
                else if(ui->radioButton_02_Color_Grey_BGR->isChecked())     QS_col.append("GRAY2BGR");
                else if(ui->radioButton_02_Color_XYZ_RGB->isChecked())      QS_col.append("XYZ2RGB");
                else if(ui->radioButton_02_Color_XYZ_BGR->isChecked())      QS_col.append("XYZ2BGR");
                else if(ui->radioButton_02_Color_YCrCb_RGB->isChecked())    QS_col.append("YCrCb2RGB");
                else if(ui->radioButton_02_Color_YCrCb_BGR->isChecked())    QS_col.append("YCrCb2BGR");
                else if(ui->radioButton_02_Color_HSV_RGB->isChecked())      QS_col.append("HSV2RGBfull");
                else if(ui->radioButton_02_Color_HSV_BGR->isChecked())      QS_col.append("HSV2BGRfull");
                else if(ui->radioButton_02_Color_HSL_RGB->isChecked())      QS_col.append("HSV2RGB");
                else if(ui->radioButton_02_Color_HSL_BGR->isChecked())      QS_col.append("HSV2BGR");
                else if(ui->radioButton_02_Color_Lab_RGB->isChecked())      QS_col.append("Lab2RGB");
                else if(ui->radioButton_02_Color_Lab_BGR->isChecked())      QS_col.append("Lab2BGR");
                else if(ui->radioButton_02_Color_Luv_RGB->isChecked())      QS_col.append("Luv2RGB");
                else                                                        QS_col.append("Luv2BGR");
            }
            else
            {
                    if(ui->radioButton_02_Color_RGB_BGR->isChecked())      QS_col.append("RGB2BGR");
               else if(ui->radioButton_02_Color_BGR_RGB->isChecked())      QS_col.append("BGR2RGB");
               else if(ui->radioButton_02_Color_Grey_RGB->isChecked())     QS_col.append("RGB2GRAY");
               else if(ui->radioButton_02_Color_Grey_BGR->isChecked())     QS_col.append("BGR2GRAY");
               else if(ui->radioButton_02_Color_XYZ_RGB->isChecked())      QS_col.append("RGB2XYZ");
               else if(ui->radioButton_02_Color_XYZ_BGR->isChecked())      QS_col.append("BGR2XYZ");
               else if(ui->radioButton_02_Color_YCrCb_RGB->isChecked())    QS_col.append("RGB2YCrCb");
               else if(ui->radioButton_02_Color_YCrCb_BGR->isChecked())    QS_col.append("BGR2YCrCb");
               else if(ui->radioButton_02_Color_HSV_RGB->isChecked())      QS_col.append("RGB2HSVfull");
               else if(ui->radioButton_02_Color_HSV_BGR->isChecked())      QS_col.append("BGR2HSVfull");
               else if(ui->radioButton_02_Color_HSL_RGB->isChecked())      QS_col.append("RGB2HSV");
               else if(ui->radioButton_02_Color_HSL_BGR->isChecked())      QS_col.append("BGR2HSV");
               else if(ui->radioButton_02_Color_Lab_RGB->isChecked())      QS_col.append("RGB2Lab");
               else if(ui->radioButton_02_Color_Lab_BGR->isChecked())      QS_col.append("BGR2Lab");
               else if(ui->radioButton_02_Color_Luv_RGB->isChecked())      QS_col.append("RGB2Luv");
               else                                                        QS_col.append("BGR2Luv");
            }
            QSL_Parameters.append(QS_col);
        }
            break;

        case c_sT_CO_DEPTH:     //-------------------------------------------------------------------   Depth
        {
            QS_Subtype = "Depth";
            QSL_Parameters.append("bit_");

            switch (ui->comboBox_02_Depth_Type->currentIndex()) {
            case 0:     QSL_Parameters.append("8U");    break;
            case 1:     QSL_Parameters.append("8S");    break;
            case 2:     QSL_Parameters.append("16U");   break;
            case 3:     QSL_Parameters.append("16S");   break;
            case 4:     QSL_Parameters.append("32S");   break;
            case 5:     QSL_Parameters.append("32F");   break;
            case 6:     QSL_Parameters.append("64F");   break;
            default:                                    break;
            }
        }
            break;

        case c_sT_CO_MERGE:     //-------------------------------------------------------------------   Merge
        {
            QS_Subtype = "Merge";

            unsigned int channels   = ui->spinBox_02_Merge_Channels->value();
            bool channels_used[4];
            channels_used[0]        = ui->checkBox_02_Merge_Ch0->isChecked();
            channels_used[1]        = ui->checkBox_02_Merge_Ch1->isChecked();
            channels_used[2]        = ui->checkBox_02_Merge_Ch2->isChecked();
            channels_used[3]        = ui->checkBox_02_Merge_Ch3->isChecked();

            QString QS_Channels = "channels_";
            for(unsigned int c = 0; c < 4; c++)
            {
                if(c < channels)
                {
                    if(channels_used[c])
                        QS_Channels.append("1");
                    else
                        QS_Channels.append("0");
                }
                else
                {
                    QS_Channels.append("X");
                }
            }
            QSL_Parameters.append(QS_Channels);
        }
            break;

        case c_sT_CO_SPLIT:     //-------------------------------------------------------------------   Split
        {
            QS_Subtype = "Split";
            QSL_Parameters.append("channel_" + QString::number(ui->spinBox_02_Split_Channel->value()));
        }
            break;

        case c_sT_CO_COMBI:     //-------------------------------------------------------------------   Split
        {
            QS_Subtype = "Combi";
            QSL_Parameters.append("mode_8UC1bin");
        }
            break;

        default:                //-------------------------------------------------------------------   Default
            break;

        }
        break;



    case c_T_ELEM: //==================================================================================================   ELEMENTAL
        QS_Type = "Elemental";

        switch (ui->comboBox_Type_03_Elemental->currentIndex()) {

        case c_sT_EL_THRES:     //-------------------------------------------------------------------   Threshold
        {
            QS_Subtype = "Threshold";

            QString QS_out = "out_";
            switch (ui->comboBox_03_Thres_Output_Mode->currentIndex()) {
            case 0:     QS_out.append("Binary");        break;
            case 1:     QS_out.append("BinaryInv");     break;
            case 2:     QS_out.append("Trunc");         break;
            case 3:     QS_out.append("TruncToZero");   break;
            case 4:     QS_out.append("ToZeroInv");     break;
            default:                                    break;}

            QString QS_max_val = "maxval_" + QString::number(ui->doubleSpinBox_03_Thres_Max_Value_Out->value());

            switch (ui->comboBox_03_Thres_Type->currentIndex()) {

            case 0://------------------Otsu
            {
                QSL_Parameters.append("mode_otsu");
                QSL_Parameters.append(QS_out);
                QSL_Parameters.append(QS_max_val);
            }
                break;

            case 1://------------------Manual Abs
            {
                QSL_Parameters.append("mode_manualAbs");
                QSL_Parameters.append(QS_out);
                QSL_Parameters.append(QS_max_val);
                QSL_Parameters.append("thres_" + QString::number(ui->spinBox_03_Thres_Thres_Value_Abs->value()));
            }
                break;

            case 2://------------------Manual Rel
            {
                QSL_Parameters.append("mode_manualRel");
                QSL_Parameters.append("base_" + QString::number(ui->doubleSpinBox_03_Thres_Rel_Base->value()));
                QSL_Parameters.append("thres_" + QString::number(ui->doubleSpinBox_03_Thres_Rel_Thres_Rel->value()));
            }
                break;

            case 3://------------------Local
            {
                QSL_Parameters.append("mode_local");
                QSL_Parameters.append(QS_out);
                QSL_Parameters.append(QS_max_val);
                QSL_Parameters.append("size_" + QString::number(ui->spinBox_03_Thres_Mask_Size->value()));
                QSL_Parameters.append("offset_" + QString::number(ui->doubleSpinBox_03_Thres_Adapt_Offset->value()));

                QString QS_mask_type = "mask_";
                switch (ui->comboBox_03_Thres_Adapt_Type->currentIndex()) {
                case 0: QS_mask_type.append("mean");    break;
                case 1: QS_mask_type.append("gauss");   break;
                default:                                break;}
                QSL_Parameters.append(QS_mask_type);
            }
                break;

            default:
                break;
            }
        }
            break;

        case c_sT_EL_LABEL:     //-------------------------------------------------------------------   Labeling
        {
            QS_Subtype = "Label";

            switch (ui->comboBox_03_Labeling_Depth->currentIndex()) {
            case 0:     QSL_Parameters.append("bit_32S");   break;
            case 1:     QSL_Parameters.append("bit_16U");   break;
            default:                                        break;}

            switch (ui->comboBox_03_Labeling_Connectivity->currentIndex()) {
            case 0:     QSL_Parameters.append("connect_8"); break;
            case 1:     QSL_Parameters.append("connect_4"); break;
            default:                                        break;}

            switch (ui->comboBox_03_Labeling_Type->currentIndex()) {

            case 0:
                QSL_Parameters.append("mode_ConComp");
                break;

            default:
                break;
            }
        }
            break;

        case c_sT_EL_SHADE_CORRECT: //-----------------------------------------------------------   Shade correct
        {
            QS_Subtype = "ShadeCorrrect";
        }
            break;

        case c_sT_EL_COLORGRAB:     //-----------------------------------------------------------   color grab
        {
            QS_Subtype = "ColorGrab";

            QString     QS_space = "cspace_";
            switch (ui->comboBox_03_GrabColor_ColorSpace->currentIndex()) {
            case 0:     QS_space.append("bgr");     break;
            case 1:     QS_space.append("xyz");     break;
            case 2:     QS_space.append("ycrcb");   break;
            case 3:     QS_space.append("hsv");     break;
            case 4:     QS_space.append("lab");     break;
            case 5:     QS_space.append("luv");     break;
            default:                                break;}
            QSL_Parameters.append(QS_space);

            QString     QS_out = "out_";
            switch (ui->comboBox_03_GrabColor_ColorSpace->currentIndex()) {
            case 0:     QS_out.append("bin");       break;
            default:                                break;}
            QSL_Parameters.append(QS_out);

            vector<uchar> min;
            vector<uchar> max;
            min.push_back((uchar) ui->spinBox_03_GrabColor_Ch1_Min->value());
            min.push_back((uchar) ui->spinBox_03_GrabColor_Ch2_Min->value());
            min.push_back((uchar) ui->spinBox_03_GrabColor_Ch3_Min->value());
            max.push_back((uchar) ui->spinBox_03_GrabColor_Ch1_Max->value());
            max.push_back((uchar) ui->spinBox_03_GrabColor_Ch2_Max->value());
            max.push_back((uchar) ui->spinBox_03_GrabColor_Ch3_Max->value());
            for(int c = 0; c < 3; c++)
            {
                QSL_Parameters.append("ch" + QString::number(c) + "min_" + QString::number(min[c]));
                QSL_Parameters.append("ch" + QString::number(c) + "max_" + QString::number(max[c]));
            }
        }
            break;

        case c_sT_EL_FILLHOLES:     //-----------------------------------------------------------   fill holes
        {
            QS_Subtype = "FillHoles";
        }
            break;

        default:            //-------------------------------------------------------------------   Default
            break;

        }
        break;


    case c_T_FILT:  //==================================================================================================   FILTER
    {
        QS_Type = "Filter";

        QString QS_border = "border_";
        switch (ui->comboBox_04_Border_Type->currentIndex()) {
        case 0:     QS_border.append("default");        break;
        case 1:     QS_border.append("constant");       break;
        case 2:     QS_border.append("replicate");      break;
        case 3:     QS_border.append("reflect");        break;
        //case 3:   border_type = BORDER_WRAP;          break;
        case 4:     QS_border.append("reflect101");     break;
        //case 4:   border_type = BORDER_TRANSPARENT;   break;
        case 5:     QS_border.append("isolated");       break;
        default:                                        break;}
        QSL_Parameters.append(QS_border);

        switch (ui->comboBox_Type_04_Filter->currentIndex()) {

        case c_sT_FI_BLUR: //---------------------------------------------------------------   blur
        {
            QS_Subtype = "Blur";

            int size        = ui->spinBox_04_Blur_Size->value() / 2;
            int size_x      = ui->spinBox_04_Blur_Size_X->value() / 2;
            int size_y      = ui->spinBox_04_Blur_Size_Y->value() / 2;
            double sigma_x  = ui->doubleSpinBox_04_Blur_Sigma_X->value();
            double sigma_y  = ui->doubleSpinBox_04_Blur_Sigma_Y->value();
            bool norm       = ui->checkBox_04_Blur_Normalized->isChecked();

            switch (ui->comboBox_04_Blur_Type->currentIndex()) {

            case 0://Mean
                QSL_Parameters.append("type_mean");
                QSL_Parameters.append("sizeX_" + QString::number(size_x));
                QSL_Parameters.append("sizeY_" + QString::number(size_y));
                QSL_Parameters.append("normed_" + QString::number((int)norm));
                break;

            case 1://RMS
                QSL_Parameters.append("type_RMS");
                QSL_Parameters.append("sizeX_" + QString::number(size_x));
                QSL_Parameters.append("sizeY_" + QString::number(size_y));
                QSL_Parameters.append("normed_" + QString::number((int)norm));
                break;

            case 2://Gauss
                QSL_Parameters.append("type_gauss");
                QSL_Parameters.append("sizeX_" + QString::number(size_x));
                QSL_Parameters.append("sizeY_" + QString::number(size_y));
                QSL_Parameters.append("sigmaX_" + QString::number(sigma_x));
                QSL_Parameters.append("sigmaY_" + QString::number(sigma_y));
                break;

            case 3://Median
                QSL_Parameters.append("type_median");
                QSL_Parameters.append("size_" + QString::number(size));
                break;

            default:
                break;
            }

        }
            break;

        case c_ST_FI_EDGE: //---------------------------------------------------------------   edge
        {
            QS_Subtype = "Edge";

            int size        = ui->spinBox_04_Edge_Size->value() / 2;
            double scale    = ui->doubleSpinBox_04_Edge_Scale->value();
            double delta    = ui->doubleSpinBox_04_Edge_Delta->value();
            int d_x         = ui->spinBox_04_Edge_dX->value();
            int d_y         = ui->spinBox_04_Edge_dY->value();

            switch (ui->comboBox_04_Edge_Type->currentIndex()) {

            case 0://Laplace
                QSL_Parameters.append("type_laplace");
                QSL_Parameters.append("size_" + QString::number(size));
                QSL_Parameters.append("scale_" + QString::number(scale));
                QSL_Parameters.append("delta_" + QString::number(delta));
                break;

            case 1://Sobel
                QSL_Parameters.append("type_sobel");
                QSL_Parameters.append("size_" + QString::number(size));
                QSL_Parameters.append("scale_" + QString::number(scale));
                QSL_Parameters.append("delta_" + QString::number(delta));
                QSL_Parameters.append("dx_" + QString::number(d_x));
                QSL_Parameters.append("dy_" + QString::number(d_y));
                break;

            case 2://Scharr
            {
                QSL_Parameters.append("type_scharr");
                QSL_Parameters.append("scale_" + QString::number(scale));
                QSL_Parameters.append("delta_" + QString::number(delta));
                QSL_Parameters.append("dx_" + QString::number(d_x));
                QSL_Parameters.append("dy_" + QString::number(d_y));
            }
                break;

            default:
                break;
            }
        }
            break;

        case c_sT_FI_EILENSTEIN: //---------------------------------------------------------------   eilenstein
        {
            QS_Subtype = "Eilenstein";

            QString QS_comp = "comp_";
            switch (ui->comboBox_04_Eilenstein_Comparator->currentIndex()) {
            case 0:     QS_comp.append("eq");   break;
            case 1:     QS_comp.append("gt");   break;
            case 2:     QS_comp.append("ge");   break;
            case 3:     QS_comp.append("lt");   break;
            case 4:     QS_comp.append("le");   break;
            case 5:     QS_comp.append("ne");   break;
            default:                            break;}
            QSL_Parameters.append(QS_comp);

            QSL_Parameters.append("sizeX_" + QString::number(ui->spinBox_04_Eilenstein_Size_X->value()));
            QSL_Parameters.append("sizeY_" + QString::number(ui->spinBox_04_Eilenstein_Size_Y->value()));
            QSL_Parameters.append("normed_" + QString::number((int)ui->checkBox_04_Eilenstein_Normalized->isChecked()));
            QSL_Parameters.append("delta_" + QString::number(ui->doubleSpinBox_04_Eilenstein_Delta->value()));
        }
            break;

        case c_sT_FI_SPEC: //---------------------------------------------------------------   special
        {
            QS_Subtype = "Special";

            switch (ui->comboBox_04_Special_Type->currentIndex()) {

            case 0://Bilateral
            {
                QSL_Parameters.append("type_bilateral");
                QSL_Parameters.append("diameter_" + QString::number(ui->spinBox_04_Special_Diameter->value()));
                QSL_Parameters.append("sigmaColor_" + QString::number(ui->doubleSpinBox_04_Special_Sigma_Color->value()));
                QSL_Parameters.append("sigmaSpace_" + QString::number(ui->doubleSpinBox_04_Special_Sigma_Space->value()));
            }
                break;

            case 1://Gabor
            {
                QSL_Parameters.append("type_gabor");

                QSL_Parameters.append("sizeX_" +    QString::number(ui->spinBox_04_Special_Size_X->value()));
                QSL_Parameters.append("sizeY_" +    QString::number(ui->spinBox_04_Special_Size_Y->value()));
                QSL_Parameters.append("delta_" +    QString::number(ui->doubleSpinBox_04_Special_Delta->value()));
                QSL_Parameters.append("sigma_" +    QString::number(ui->doubleSpinBox_04_Special_Sigma->value()));
                QSL_Parameters.append("lambda_" +   QString::number(ui->doubleSpinBox_04_Special_Lambda->value()));
                QSL_Parameters.append("gamma_" +    QString::number(ui->doubleSpinBox_04_Special_Gamma->value()));
                QSL_Parameters.append("theta_" +    QString::number(ui->doubleSpinBox_04_Special_Theta->value()));
                QSL_Parameters.append("psi_" +      QString::number(ui->doubleSpinBox_04_Special_Psi->value()));

                switch (ui->comboBox_04_Special_Depth->currentIndex()) {
                case 0:     QSL_Parameters.append("bit_32F");   break;
                case 1:     QSL_Parameters.append("bit_64F");   break;
                default:                                        break;}
            }
                break;

            default:
                break;
            }
        }
            break;

        case c_sT_FI_FUNCTION: //---------------------------------------------------------------   custom
        {
            QS_Subtype = "Function";
        }
            break;

        default:                //--------------------------------------------------------------   Default
            break;

        }
    }
        break;


    case c_T_MORPH: //==================================================================================================   MORPH
        QS_Type = "Morphology";

        switch (ui->comboBox_Type_05_Morphology->currentIndex()) {

        case c_sT_MO_ELEM:  //-------------------------------------------------------------------   Elemental
        {
            QS_Subtype = "Elemental";

            QString     QS_morph = "type_";
            switch (ui->comboBox_05_Elem_Morph_Type->currentIndex()) {
            case 0:     QS_morph.append("erode");   break;
            case 1:     QS_morph.append("dilate");  break;
            case 2:     QS_morph.append("open");    break;
            case 3:     QS_morph.append("close");   break;
            case 4:     QS_morph.append("gradient");break;
            case 5:     QS_morph.append("tophat");  break;
            case 6:     QS_morph.append("blackhat");break;
            default:                                break;}
            QSL_Parameters.append(QS_morph);

            QString     QS_elem = "elem_";
            switch (ui->comboBox_05_Elem_Elem_Type->currentIndex()) {
            case 0:     QS_elem.append("rect");     break;
            case 1:     QS_elem.append("cross");    break;
            case 2:     QS_elem.append("ellipse");  break;
            default:                                break;}
            QSL_Parameters.append(QS_elem);

            QString     QS_border = "border_";
            switch (ui->comboBox_05_Elem_Border_Type->currentIndex()) {
            case 0:     QS_border.append("constant");       break;
            case 1:     QS_border.append("replicate");      break;
            case 2:     QS_border.append("reflect");        break;
            //case 3:   border_type = BORDER_WRAP;          break;
            case 3:     QS_border.append("reflect101");     break;
            //case 4:   border_type = BORDER_TRANSPARENT;   break;
            case 4:     QS_border.append("isolated");       break;
            default:                                        break;}
            QSL_Parameters.append(QS_border);

            QSL_Parameters.append("sizeX_" + QString::number(ui->spinBox_05_Elem_Elem_Size_X->value()));
            QSL_Parameters.append("sizeY_" + QString::number(ui->spinBox_05_Elem_Elem_Size_Y->value()));
            QSL_Parameters.append("iteration_" + QString::number(ui->spinBox_05_Elem_Iterations->value()));
        }
            break;

        default:            //-------------------------------------------------------------------   Default
            break;

        }
        break;


    case c_T_MATH: //==================================================================================================   MATH
        QS_Type = "Math";

        switch (ui->comboBox_Type_06_Math->currentIndex()) {

        case c_sT_MA_1IMG:  //-------------------------------------------------------------------   1Img simple
        {
            QS_Subtype = "1Image";

            double arg = ui->doubleSpinBox_06_1Img_Arg->value();

            switch (ui->comboBox_06_1Img_Type->currentIndex()) {

            case 0://not
                QSL_Parameters.append("type_not");
                break;

            case 1://add
                QSL_Parameters.append("type_add");
                QSL_Parameters.append("arg_" + QString::number(arg));
                break;

            case 2://sub
                QSL_Parameters.append("type_sub");
                QSL_Parameters.append("arg_" + QString::number(arg));
                break;

            case 3://mult
                QSL_Parameters.append("type_mult");
                QSL_Parameters.append("arg_" + QString::number(arg));
                break;

            case 4://div
                QSL_Parameters.append("type_div");
                QSL_Parameters.append("arg_" + QString::number(arg));
                break;

            case 5://pow
                QSL_Parameters.append("type_pow");
                QSL_Parameters.append("arg_" + QString::number(arg));
                break;

            case 6://root
                QSL_Parameters.append("type_sqr");
                break;

            case 7://log
                QSL_Parameters.append("type_log");
                break;

            default:
                break;
            }
        }
            break;

        case c_sT_MA_2IMG:  //-------------------------------------------------------------------   2Img simple
        {
            QS_Subtype = "2Images";

            double weight_1     = ui->doubleSpinBox_06_2Img_Weight_1->value();
            double weight_2     = ui->doubleSpinBox_06_2Img_Weight_2->value();
            double weight_sum   = ui->doubleSpinBox_06_2Img_Weight_Sum->value();
            double scale        = ui->doubleSpinBox_06_2Img_Scale->value();

            switch (ui->comboBox_06_2Img_Type->currentIndex()) {

            case 0://Add
                QSL_Parameters.append("type_add");
                break;

            case 1://Add weighted
                QSL_Parameters.append("type_addWeight");
                QSL_Parameters.append("weight1_" + QString::number(weight_1));
                QSL_Parameters.append("weight2_" + QString::number(weight_2));
                QSL_Parameters.append("weightSum_" + QString::number(weight_sum));
                break;

            case 2://Diff
                QSL_Parameters.append("type_sub");
                break;

            case 3://Diff abs
                QSL_Parameters.append("type_subAbs");
                break;

            case 4://Mult
                QSL_Parameters.append("type_mult");
                QSL_Parameters.append("scale_" + QString::number(scale));
                break;

            case 5://Div
                QSL_Parameters.append("type_div");
                QSL_Parameters.append("scale_" + QString::number(scale));
                break;

            case 6://bit and
                QSL_Parameters.append("type_bitAnd");
                break;

            case 7://bit or
                QSL_Parameters.append("type_bitOr");
                break;

            case 8://bit xor
                QSL_Parameters.append("type_bitXor");
                break;

            case 9://min
                QSL_Parameters.append("type_min");

            case 10://max
                QSL_Parameters.append("type_max");
                break;

            case 11://comp
            {
                QSL_Parameters.append("type_comp");

                QString QS_comp = "comp_";
                switch (ui->comboBox_04_Eilenstein_Comparator->currentIndex()) {
                case 0:     QS_comp.append("eq");   break;
                case 1:     QS_comp.append("gt");   break;
                case 2:     QS_comp.append("ge");   break;
                case 3:     QS_comp.append("lt");   break;
                case 4:     QS_comp.append("le");   break;
                case 5:     QS_comp.append("ne");   break;
                default:                            break;}
                QSL_Parameters.append(QS_comp);
            }
                break;

            default:
                break;
            }

        }
            break;

        default:            //-------------------------------------------------------------------   Default
            break;

        }
        break;


    case c_T_TRANS: //==================================================================================================   TRANS
        QS_Type = "Transform";

        switch (ui->comboBox_Type_07_Transform->currentIndex()) {

        case c_sT_TR_DIST:  //-------------------------------------------------------------------   Distance
        {
            QS_Subtype = "Distance";

            QString     QS_metric = "metric_";
            switch (ui->comboBox_07_Dist_Metric->currentIndex()) {
            case 0:     QS_metric.append("euclidean");  break;
            case 1:     QS_metric.append("taxi");       break;
            case 2:     QS_metric.append("maxXY");      break;
            case 3:     QS_metric.append("l12");        break;
            case 4:     QS_metric.append("fair");       break;
            case 5:     QS_metric.append("welsch");     break;
            case 6:     QS_metric.append("huber");      break;
            default:                                    break;}
            QSL_Parameters.append(QS_metric);

            QString     QS_prec = "prec_";
            switch (ui->comboBox_07_Dist_Precision->currentIndex()) {
            case 0:     QS_prec.append("precise");  break;
            case 1:     QS_prec.append("3x3");      break;
            case 2:     QS_prec.append("5x5");      break;
            default:                                break;}
            QSL_Parameters.append(QS_prec);
        }
            break;

        case c_sT_TR_WATERSHADE:    //-----------------------------------------------------------   Watershade
        {
            QS_Subtype = "Watershed";
            QSL_Parameters.append("auto_" + QString::number((int)ui->checkBox_07_Watershed_Auto->isChecked()));

            if(ui->checkBox_07_Watershed_Auto->isChecked())
            {
                int connectivity;
                switch (ui->comboBox_07_Watershed_Connectivity->currentIndex()) {
                case 0:     connectivity = 8;           break;
                case 1:     connectivity = 4;           break;
                default:                                break;}
                QSL_Parameters.append("connectivity_" + QString::number(connectivity));

                QSL_Parameters.append("inclnseed_" + QString::number((int)ui->checkBox_07_Watershed_InclNonSeed->isChecked()));
                QSL_Parameters.append("bit8_" + QString::number((int)ui->checkBox_07_Watershed_8bit->isChecked()));
                QSL_Parameters.append("exclbor_" + QString::number((int)ui->checkBox_07_Watershed_ExclBorder->isChecked()));
            }
        }
            break;

        case c_sT_TR_FOURIER:       //-----------------------------------------------------------   Fourier
        {
            QS_Subtype = "Fourier";
            QSL_Parameters.append("inv_" + QString::number((int)ui->checkBox_07_Fourier_Invers->isChecked()));
        }
            break;

        default:            //-------------------------------------------------------------------   Default
            break;

        }
        break;


    case c_T_FEATURE://==================================================================================================   SELECT
        QS_Type = "Feature";

        switch (ui->comboBox_Type_08_Feature->currentIndex()) {

        case c_sT_FE_VALUE:  //-------------------------------------------------------------------   to Value
        {
            QS_Subtype = "Value";

            QSL_Parameters.append("type_" + ui->comboBox_08_FeatVal_Feature->currentText());

            int connectivity;
            switch (ui->comboBox_08_FeatVal_Connectivity->currentIndex()) {
            case 0:     connectivity = 8;           break;
            case 1:     connectivity = 4;           break;
            default:                                break;}
            QSL_Parameters.append("connectivity_" + QString::number(connectivity));
        }
            break;

        case c_sT_FE_SELECT:  //-------------------------------------------------------------------   Select
        {
            QS_Subtype = "Select";

            QSL_Parameters.append("type_" + ui->comboBox_08_Select_Type->currentText());

            int connectivity;
            switch (ui->comboBox_08_Select_Connectivity->currentIndex()) {
            case 0:     connectivity = 8;           break;
            case 1:     connectivity = 4;           break;
            default:                                break;}
            QSL_Parameters.append("connectivity_" + QString::number(connectivity));

            QSL_Parameters.append("min_" + QString::number(ui->doubleSpinBox_08_Select_Min->value()));
            QSL_Parameters.append("max_" + QString::number(ui->doubleSpinBox_08_Select_Max->value()));
        }
            break;

        case c_sT_FE_REDUCE:  //-------------------------------------------------------------------   Reduce
        {
            QS_Subtype = "Reduce";

            QSL_Parameters.append("geometric_" + ui->comboBox_08_Reduce_Type->currentText());

            int connectivity;
            switch (ui->comboBox_08_Reduce_Connectivity->currentIndex()) {
            case 0:     connectivity = 8;           break;
            case 1:     connectivity = 4;           break;
            default:                                break;}
            QSL_Parameters.append("connectivity_" + QString::number(connectivity));

            QSL_Parameters.append("thick_" + QString::number(ui->spinBox_08_Reduce_Thickness->value()));
            QSL_Parameters.append("value_" + QString::number(ui->spinBox_08_Reduce_Value->value()));
        }
            break;

        case c_sT_FE_VISUALIZE: //---------------------------------------------------------------   Visualize
        {
            QS_Subtype = "Visualize";

            QSL_Parameters.append("type_" + ui->comboBox_08_Visualize_Feature->currentText());

            int connectivity;
            switch (ui->comboBox_08_Visualize_Connectivity->currentIndex()) {
            case 0:     connectivity = 8;           break;
            case 1:     connectivity = 4;           break;
            default:                                break;}
            QSL_Parameters.append("connectivity_" + QString::number(connectivity));

            QSL_Parameters.append("thickness_"  + QString::number(ui->spinBox_08_Visualize_Thickness->value()));
            QSL_Parameters.append("scale_"      + QString::number(ui->doubleSpinBox_08_Visualize_Scale->value()));
        }
            break;

        default:            //-------------------------------------------------------------------   Default
            break;

        }
        break;


    case c_T_OTHER: //==================================================================================================   OTHER
        QS_Type = "Other";

        switch (ui->comboBox_Type_09_Other->currentIndex()) {

        case c_sT_OT_EQUAL_HIST:    //-----------------------------------------------------------   Hist Equal
            QS_Subtype = "EqualHist";
            break;

        case c_sT_OT_GAMMA_SPREAD:    //-----------------------------------------------------------   Gamma Spread
            QS_Subtype = "GammaSpread";
            QSL_Parameters.append("gamma_" + QString::number(ui->doubleSpinBox_09_GammaSpread_Gamma->value()));
            QSL_Parameters.append("inMin" + QString::number(ui->doubleSpinBox_09_GammaSpread_InMin->value()));
            QSL_Parameters.append("inMax_" + QString::number(ui->doubleSpinBox_09_GammaSpread_InMax->value()));
            QSL_Parameters.append("outMin_" + QString::number(ui->doubleSpinBox_09_GammaSpread_OutMin->value()));
            QSL_Parameters.append("outMax_" + QString::number(ui->doubleSpinBox_09_GammaSpread_OutMax->value()));
            break;

        case c_sT_OT_LABEL_NUMBER:    //-----------------------------------------------------------   Hist Equal
            QS_Subtype = "LabelNumber";

            QSL_Parameters.append("scale_" + QString::number(ui->doubleSpinBox_09_LabelNo_Scale->value()));
            QSL_Parameters.append("thick_" + QString::number(ui->spinBox_09_LabelNo_Thickness->value()));
            QSL_Parameters.append("center_" + QString::number((int)ui->checkBox_09_LabelNo_Position->isChecked()));
            break;

        default:            //-------------------------------------------------------------------   Default
            break;

        }
        break;

    case c_T_DIM: //==================================================================================================   DIM
    {
        //Version 1_6 beta (15.2.19): moved to main window
    }
        break;

    default:        //==================================================================================================   DEFAULT
        break;
    }
}

void D_StepWindow::Update_Hist()
{
    //Time measurement
    QElapsedTimer timer;
    timer.start();

    QString QS_AxisX = "Pixel Value (exact)";
    if(ui->checkBox_Output_Hist_Accumulate->isChecked())
        QS_AxisX = "Pixel Value (up to)";

    QString QS_AxisY = "Absolute Amount of Pixels";
    if(ui->checkBox_Output_Hist_Uniform->isChecked())
        QS_AxisY = "Relative Amount of Pixels";

    QString QS_HistTitle = "Histogram of viewed 2D image";
    if(ui->checkBox_Output_Hist_Full6D->isChecked())
        QS_AxisY = "Histogram of full 6D image";

    if(ui->checkBox_Output_Hist_Full6D->isChecked())
    {
        ERR(D_Plot::Plot_Hist_Any(
                ChartView_Hist,
                pStore->get_pVD(pos_Dest),
                ui->spinBox_HistClasses->value(),
                QS_HistTitle,
                "Channel_",
                QS_AxisX,
                QS_AxisY,
                ui->checkBox_Output_Hist_Uniform->isChecked(),
                ui->checkBox_Output_Hist_Accumulate->isChecked(),
                false),
            "Update_Hist",
            "D_Plot::Plot_Hist_Any - VisDat");
    }
    else
    {
        ERR(D_Plot::Plot_Hist_Any(
                ChartView_Hist,
                pStore->get_Adress(pos_Dest),
                ui->spinBox_HistClasses->value(),
                QS_HistTitle,
                "Channel_",
                QS_AxisX,
                QS_AxisY,
                ui->checkBox_Output_Hist_Uniform->isChecked(),
                ui->checkBox_Output_Hist_Accumulate->isChecked(),
                false),
            "Update_Hist",
            "D_Plot::Plot_Hist_Any - Mat");
    }

    times[c_TIME_HIST] = timer.elapsed();
    pStore->set_times(pos_Dest, c_TIME_HIST, timer.elapsed());
}

void D_StepWindow::Update_Title()
{
    QString title =
            "(" +
            QString::number(pos_Dest) +
            ") ";

    QString subtype;

    if(ui->action_Change_Title->isChecked())
    {
        title = title + QS_AlternativeTitle;
    }
    else
    {
        switch (ui->comboBox_Type_Main->currentIndex()) {

        case c_T_SOURCE:
            subtype = ui->comboBox_Type_00_Source->currentText();
            break;

        case c_T_EDIT:
            subtype = ui->comboBox_Type_01_Edit->currentText();
            break;

        case c_T_CONV:
            subtype = ui->comboBox_Type_02_Convert->currentText();
            break;

        case c_T_ELEM:
            subtype = ui->comboBox_Type_03_Elemental->currentText();
            break;

        case c_T_FILT:
            subtype = ui->comboBox_Type_04_Filter->currentText();
            break;

        case c_T_MORPH:
            subtype = ui->comboBox_Type_05_Morphology->currentText();
            break;

        case c_T_MATH:
            subtype = ui->comboBox_Type_06_Math->currentText();
            break;

        case c_T_TRANS:
            subtype = ui->comboBox_Type_07_Transform->currentText();
            break;

        case c_T_FEATURE:
            subtype = ui->comboBox_Type_08_Feature->currentText();
            break;

        case c_T_OTHER:
            subtype = ui->comboBox_Type_09_Other->currentText();
            break;

        case c_T_DIM:
            subtype = ui->comboBox_Type_10_Dimension->currentText();
            break;

        default:
            subtype = "!!!=Error=!!!";
            break;
        }

        title =
                title +
                ui->comboBox_Type_Main->currentText() +
                " - " +
                subtype;
    }

    setWindowTitle(title);
    QS_title = title;
}

void D_StepWindow::Update_Type_Descriptions()
{
    //L_SB_Type_MA->setText(D_Img_Proc::Type_of_Mat(pStore->get_Adress(pos_Dest)));
    //L_SB_Type_QI->setText(D_Img_Proc::Type_of_QImage(&QI_Step_Image));

    ui->label_Source_Type_1->setText(D_Img_Proc::Type_of_Mat(pStore->get_Adress(pos_Source1)));
    ui->label_Source_Type_2->setText(D_Img_Proc::Type_of_Mat(pStore->get_Adress(pos_Source2)));
    ui->label_Source_Type_3->setText(D_Img_Proc::Type_of_Mat(pStore->get_Adress(pos_Source3)));
    ui->label_Source_Type_4->setText(D_Img_Proc::Type_of_Mat(pStore->get_Adress(pos_Source4)));

    Update_Source_Preview();
}

void D_StepWindow::Update_Source_Preview()
{
    //Time measurement
    QElapsedTimer timer;
    timer.start();

    if(pos_Source1 > 0)
    {
        pQI_Source_1 = (*pSteps)[pos_Source1]->get_pQI_Step_Image();
        QImage QI_TT_1 = (*pQI_Source_1).scaledToHeight(300);
        QByteArray data_1;
        QBuffer buffer_1(&data_1);
        QI_TT_1.save(&buffer_1, "JPG", 100);
        ui->spinBox_Source_Pos_1->setToolTip(QString("<img src='data:image/jgp;base64, %0'>").arg(QString(data_1.toBase64())));
    }

    if(pos_Source2 > 0)
    {
        pQI_Source_2 = (*pSteps)[pos_Source2]->get_pQI_Step_Image();
        QImage QI_TT_2 = (*pQI_Source_2).scaledToHeight(300);
        QByteArray data_2;
        QBuffer buffer_2(&data_2);
        QI_TT_2.save(&buffer_2, "JPG", 100);
        ui->spinBox_Source_Pos_2->setToolTip(QString("<img src='data:image/jpg;base64, %0'>").arg(QString(data_2.toBase64())));
    }

    if(pos_Source3 > 0)
    {
        pQI_Source_3 = (*pSteps)[pos_Source3]->get_pQI_Step_Image();
        QImage QI_TT_3 = (*pQI_Source_3).scaledToHeight(300);
        QByteArray data_3;
        QBuffer buffer_3(&data_3);
        QI_TT_3.save(&buffer_3, "JPG", 100);
        ui->spinBox_Source_Pos_3->setToolTip(QString("<img src='data:image/jpg;base64, %0'>").arg(QString(data_3.toBase64())));
    }

    if(pos_Source4 > 0)
    {
        pQI_Source_4 = (*pSteps)[pos_Source4]->get_pQI_Step_Image();
        QImage QI_TT_4 = (*pQI_Source_4).scaledToHeight(300);
        QByteArray data_4;
        QBuffer buffer_4(&data_4);
        QI_TT_4.save(&buffer_4, "JPG", 100);
        ui->spinBox_Source_Pos_4->setToolTip(QString("<img src='data:image/jpg;base64, %0'>").arg(QString(data_4.toBase64())));
    }

    times[c_TIME_SOURCE_VIEW] = timer.elapsed();
    pStore->set_times(pos_Dest, c_TIME_SOURCE_VIEW, timer.elapsed());
}

void D_StepWindow::Update_Descriptions()
{
    Update_Type_Descriptions();
    Update_Title();
    Update_Range_Info();
    Update_Size_Info();
}

void D_StepWindow::Update_HistSettings()
{
    bool ch0 = false;
    bool ch1 = false;
    bool ch2 = false;
    bool ch3 = false;

    switch (pStore->get_Adress(pos_Dest)->channels()) {
    case 4:     ch0 = true;
    case 3:     ch1 = true;
    case 2:     ch2 = true;
    case 1:     ch3 = true;
    default:    break;}

    /*
    ui->checkBox_Output_Hist_Ch3->setEnabled(ch0);
    ui->checkBox_Output_Hist_Ch2->setEnabled(ch1);
    ui->checkBox_Output_Hist_Ch1->setEnabled(ch2);
    ui->checkBox_Output_Hist_Ch0->setEnabled(ch3);
    */
}

void D_StepWindow::Update_vSources_vDestinations()
{
    //qDebug() << "Update_vSources_vDestinations" << " - " << "Stepwindow" << pos_Dest;

    bool S1_in_use = ui->spinBox_Source_Pos_1->isEnabled();
    bool S2_in_use = ui->spinBox_Source_Pos_2->isEnabled();
    bool S3_in_use = ui->spinBox_Source_Pos_3->isEnabled();
    bool S4_in_use = ui->spinBox_Source_Pos_4->isEnabled();

    //Sources
    vUI_Sources.clear();
    if(S1_in_use)                       vUI_Sources.push_back(pos_Source1);
    if(S2_in_use)                       vUI_Sources.push_back(pos_Source2);
    if(S3_in_use)                       vUI_Sources.push_back(pos_Source3);
    if(S4_in_use)                       vUI_Sources.push_back(pos_Source4);

    //remove "is dest" in old sources windows
    if(pos_Source1_last_Update > 0)     (*pSteps)[pos_Source1_last_Update]->pop_destination(pos_Dest);
    if(pos_Source2_last_Update > 0)     (*pSteps)[pos_Source2_last_Update]->pop_destination(pos_Dest);
    if(pos_Source3_last_Update > 0)     (*pSteps)[pos_Source3_last_Update]->pop_destination(pos_Dest);
    if(pos_Source4_last_Update > 0)     (*pSteps)[pos_Source4_last_Update]->pop_destination(pos_Dest);

    //is Destination of
    if(S1_in_use && (pos_Source1 > 0))  (*pSteps)[pos_Source1]->add_destination(pos_Dest);
    if(S2_in_use && (pos_Source2 > 0))  (*pSteps)[pos_Source2]->add_destination(pos_Dest);
    if(S3_in_use && (pos_Source3 > 0))  (*pSteps)[pos_Source3]->add_destination(pos_Dest);
    if(S4_in_use && (pos_Source4 > 0))  (*pSteps)[pos_Source4]->add_destination(pos_Dest);

    //Update ui
    Update_Chain_Info(true);

    //Store current sources used
    pos_Source1_last_Update = pos_Source1;
    pos_Source2_last_Update = pos_Source2;
    pos_Source3_last_Update = pos_Source3;
    pos_Source4_last_Update = pos_Source4;
}

void D_StepWindow::Update_Destinations_Info()
{
    for(unsigned int d = 0; d < vUI_Destinations.size(); d++)
        if(vUI_Destinations[d] > 0)
            (*pSteps)[vUI_Destinations[d]]->Update_Source_Info();
}

void D_StepWindow::Update_Range_Info()
{
    double min;
    double max;

    ERR(D_VisDat_Proc::Calc_MinMax(
            pStore->get_pVD(pos_Dest),
            &min,
            &max),
        "Update_Range_Info",
        "D_VisDat_Proc::Calc_MinMax");

    L_SB_Range->setText(
            QString::number(min, 'g', 3) +
            " to " +
                QString::number(max, 'g', 3));
}

void D_StepWindow::Update_Size_Info()
{
    L_SB_SizeType->setText(pStore->get_pVD(pos_Dest)->info_short());
    L_SB_Memory->setText(pStore->get_pVD(pos_Dest)->Info_Memory());
}

void D_StepWindow::Update_Times()
{
    bool plot_time[4];
    plot_time[c_TIME_IMG_PROC]  = ui->checkBox_Output_Times_Processing->isChecked();
    plot_time[c_TIME_IMG_CONV]  = ui->checkBox_Output_Times_Conversion->isChecked();
    plot_time[c_TIME_IMG_SHOW]  = ui->checkBox_Output_Times_Show->isChecked();
    plot_time[c_TIME_HIST]      = ui->checkBox_Output_Times_Hist->isChecked();

    ERR(D_Plot::Plot_Times_Step(
            ChartView_Times,
            times,
            plot_time));
}

void D_StepWindow::Update_Time_Img_Cvt(unsigned int t)
{
    pStore->set_times(pos_Dest, c_TIME_IMG_CONV, t);
}

void D_StepWindow::Update_Time_View_Update(unsigned int t)
{
    pStore->set_times(pos_Dest, c_TIME_IMG_SHOW, t);
}

void D_StepWindow::Update_3DPlot()
{
    this->setEnabled(false);
    ERR(ViewerPlot_3D.plot_VD_custom(
            pStore->get_pVD(pos_Dest),
            ui->comboBox_3D_Mode->currentIndex(),
            ui->comboBox_3D_Condition->currentIndex(),
            ui->comboBox_3D_ColorHandling->currentIndex(),
            ui->comboBox_3D_Axis_X->currentIndex(),
            ui->comboBox_3D_Axis_Y->currentIndex(),
            ui->comboBox_3D_Axis_Z->currentIndex(),
            ui->comboBox_3D_Axis_V->currentIndex(),
            ui->comboBox_3D_2dPlane_Heightmap->currentIndex(),
            ui->comboBox_3D_SurfaceDimension->currentIndex(),
            ui->comboBox_3D_SurfaceMode->currentIndex(),
            ui->comboBox_3D_TextureMode_Heightmap->currentIndex(),
            ui->comboBox_3D_Marker->currentIndex(),
            ui->comboBox_3D_ShadowQuality->currentIndex(),
            ui->checkBox_3D_Background->isChecked(),
            ui->checkBox_3D_Grid->isChecked(),
            ui->checkBox_3D_Smooth->isChecked(),
            ui->checkBox_3D_Surface->isChecked(),
            ui->checkBox_3D_Wireframe->isChecked()),
        "Update_3DPlot",
        "Viewer_3D.plot_VD_custom");
    this->setEnabled(true);
}

void D_StepWindow::Update_3DImage()
{
    Viewer_3D.set_VisDat(pStore->get_pVD(pos_Dest));
}

void D_StepWindow::Dim_GetFromVD()
{
    //qDebug() << "test1";
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
    {
        //qDebug() << "dim" << d;
        //qDebug() << pStore->get_pVD(0)->pDim()->info();

        vDSB_Dims[d]->setSuffix(    pStore->get_pVD(pos_Dest)->pDim()->unit_Dim(d));
        vDSB_Dims[d]->setSingleStep(pStore->get_pVD(pos_Dest)->pDim()->step_Dim(d));
        vDSB_Dims[d]->setMaximum(   pStore->get_pVD(pos_Dest)->pDim()->size_Dim(d) - 1);
    }
    //qDebug() << "test2";
}

int D_StepWindow::ProcDimCountFromUi()
{
    return SlicingFromUi().ProcDims_Count();
}

void D_StepWindow::ProcDimCountAdaptUi()
{
    //proc dims count
    int n = ProcDimCountFromUi();

    //proc dims
    QStringList QSL_ProcDims;
    if(ui->checkBox_ProcDims_X_Proc->isChecked())   QSL_ProcDims.push_back("X");
    if(ui->checkBox_ProcDims_Y_Proc->isChecked())   QSL_ProcDims.push_back("Y");
    if(ui->checkBox_ProcDims_Z_Proc->isChecked())   QSL_ProcDims.push_back("Z");
    if(ui->checkBox_ProcDims_T_Proc->isChecked())   QSL_ProcDims.push_back("T");
    if(ui->checkBox_ProcDims_S_Proc->isChecked())   QSL_ProcDims.push_back("S");
    if(ui->checkBox_ProcDims_P_Proc->isChecked())   QSL_ProcDims.push_back("P");

    //Crop
    if(n == 2)
    {
        ui->label_01_Crop_Circle_X->setText(QSL_ProcDims[0]);
        ui->label_01_Crop_Ellipse_X->setText(QSL_ProcDims[0]);
        ui->label_01_Crop_RectAbs_X->setText(QSL_ProcDims[0]);
        ui->label_01_Crop_RectRot_X->setText(QSL_ProcDims[0]);
        ui->label_01_Crop_Rect_X->setText(QSL_ProcDims[0]);

        ui->label_01_Crop_Circle_Y->setText(QSL_ProcDims[1]);
        ui->label_01_Crop_Ellipse_Y->setText(QSL_ProcDims[1]);
        ui->label_01_Crop_RectAbs_Y->setText(QSL_ProcDims[1]);
        ui->label_01_Crop_RectRot_Y->setText(QSL_ProcDims[1]);
        ui->label_01_Crop_Rect_Y->setText(QSL_ProcDims[1]);
    }

    //Padding
    ui->label_01_Padding_Width_X->setEnabled(false);
    ui->label_01_Padding_Width_Y->setEnabled(false);
    ui->label_01_Padding_Width_Z->setEnabled(false);
    ui->spinBox_01_Padding_Width_X->setEnabled(false);
    ui->spinBox_01_Padding_Width_Y->setEnabled(false);
    ui->spinBox_01_Padding_Width_Z->setEnabled(false);
    if(n == 2 || n == 3)
    {
        ui->label_01_Padding_Width_X->setEnabled(true);
        ui->label_01_Padding_Width_X->setText("Border " + QSL_ProcDims[0]);
        ui->label_01_Padding_Width_Y->setEnabled(true);
        ui->label_01_Padding_Width_Y->setText("Border " + QSL_ProcDims[1]);
        ui->spinBox_01_Padding_Width_X->setEnabled(true);
        ui->spinBox_01_Padding_Width_Y->setEnabled(true);

        if(n == 3)
        {
            ui->label_01_Padding_Width_Z->setEnabled(true);
            ui->label_01_Padding_Width_Z->setText("Border " + QSL_ProcDims[2]);
            ui->spinBox_01_Padding_Width_Z->setEnabled(true);
        }
    }

    //Scale
    if(n == 2)
    {
        ui->label_01_Scale_Size->setText("Size " + QSL_ProcDims[0] + "/" + QSL_ProcDims[1]);
        ui->label_01_Scale_Factor->setText("Factor " + QSL_ProcDims[0] + "/" + QSL_ProcDims[1]);
    }

    //Filter Blur
    if(n == 2)
    {
        ui->label_04_Blur_Size_XY->setText("Size " + QSL_ProcDims[0] + "/" + QSL_ProcDims[1]);
        ui->label_04_Blur_Sigma_XY->setText("Sigma " + QSL_ProcDims[0] + "/" + QSL_ProcDims[1]);
    }

    //Filter Edge
    if(n == 2)
    {
        ui->label_04_Edge_dXdY->setText("d" + QSL_ProcDims[0] + " / d" + QSL_ProcDims[1]);
    }

    //Filter Special
    if(n == 2)
    {
        ui->label_04_Special_Size_XY->setText("Size " + QSL_ProcDims[0] + "/" + QSL_ProcDims[1]);
    }

    //Filter Eilenstein
    if(n == 2)
    {
        ui->label_04_Eilenstein_Size->setText("Size " + QSL_ProcDims[0] + "/" + QSL_ProcDims[1]);
    }

    //Morphology
    if(n == 2)
    {
        ui->label_05_Elem_Elem_Size->setText("Size " + QSL_ProcDims[0] + "/" + QSL_ProcDims[1]);
        ui->label_05_LocalMaxima_Size->setText("Size " + QSL_ProcDims[0] + "/" + QSL_ProcDims[1]);
    }

    //Distance
    if(n != 2)
    {
        ui->comboBox_07_Dist_Metric->blockSignals(true);
        ui->comboBox_07_Dist_Metric->setCurrentIndex(0);
        ui->comboBox_07_Dist_Metric->blockSignals(false);

        ui->comboBox_07_Dist_Precision->blockSignals(true);
        ui->comboBox_07_Dist_Precision->setCurrentIndex(0);
        ui->comboBox_07_Dist_Precision->blockSignals(false);

        ui->label_07_Dist_Norm->setEnabled(false);
        ui->comboBox_07_Dist_Metric->setEnabled(false);
        ui->label_07_Dist_Precision->setEnabled(false);
        ui->comboBox_07_Dist_Precision->setEnabled(false);
    }
    else
    {
        ui->label_07_Dist_Norm->setEnabled(true);
        ui->comboBox_07_Dist_Metric->setEnabled(true);
        ui->label_07_Dist_Precision->setEnabled(true);
        ui->comboBox_07_Dist_Precision->setEnabled(true);
    }
}

void D_StepWindow::Emitter_ViewPlanePosChanged()
{
    if(!ui->action_connect_plane_position_to_other_steps->isChecked())
        return;

    vector<int> pos(c_DIM_NUMBER_OF);
    pos[c_DIM_X] = ui->doubleSpinBox_View_Plane_X->value();
    pos[c_DIM_Y] = ui->doubleSpinBox_View_Plane_Y->value();
    pos[c_DIM_Z] = ui->doubleSpinBox_View_Plane_Z->value();
    pos[c_DIM_T] = ui->doubleSpinBox_View_Plane_T->value();
    pos[c_DIM_S] = ui->doubleSpinBox_View_Plane_S->value();
    pos[c_DIM_P] = ui->doubleSpinBox_View_Plane_P->value();
    emit ViewPlanePosChanged(pos);
}

void D_StepWindow::Emitter_ViewZoomChanged()
{
    if(!ui->action_Connect_Steps_Zoom->isChecked())
        return;

    emit ViewZoomChanged(
                Viewer.zoom_x_rel(),
                Viewer.zoom_y_rel(),
                Viewer.zoom_fact(),
                ui->comboBox_View_Plane->currentIndex());
}

void D_StepWindow::Update_Chain_Info(bool update_sources)
{
    //qDebug() << "Update_Chain_Info" << " - " << "Stepwindow" << pos_Dest;

    bool S1_in_use = ui->spinBox_Source_Pos_1->isEnabled();
    bool S2_in_use = ui->spinBox_Source_Pos_2->isEnabled();
    bool S3_in_use = ui->spinBox_Source_Pos_3->isEnabled();
    bool S4_in_use = ui->spinBox_Source_Pos_4->isEnabled();

    QString Source_List = "";
    QString Dest_List = "";

    //Update ui

    for(unsigned int s = 0; s < vUI_Sources.size(); s++)
        Source_List.append(QString::number(vUI_Sources[s]) + "   ");
    ui->label_Chain_Sources_Used_List->setText(Source_List);

    for(unsigned int d = 0; d < vUI_Destinations.size(); d++)
        Dest_List.append(QString::number(vUI_Destinations[d]) + "   ");
    ui->label_Chain_Source_of_List->setText(Dest_List);



    //Update Chain Info in other Windows------------------------------------------------
    if(!update_sources)
        return;

    //"is dest" in old sources windows
    if(pos_Source1_last_Update > 0)         (*pSteps)[pos_Source1_last_Update]->Update_Chain_Info(false);
    if(pos_Source2_last_Update > 0)         (*pSteps)[pos_Source2_last_Update]->Update_Chain_Info(false);
    if(pos_Source3_last_Update > 0)         (*pSteps)[pos_Source3_last_Update]->Update_Chain_Info(false);
    if(pos_Source4_last_Update > 0)         (*pSteps)[pos_Source4_last_Update]->Update_Chain_Info(false);

    //is Destination of
    if(S1_in_use && (pos_Source1 > 0))      (*pSteps)[pos_Source1]->Update_Chain_Info(false);
    if(S2_in_use && (pos_Source2 > 0))      (*pSteps)[pos_Source2]->Update_Chain_Info(false);
    if(S3_in_use && (pos_Source3 > 0))      (*pSteps)[pos_Source3]->Update_Chain_Info(false);
    if(S4_in_use && (pos_Source4 > 0))      (*pSteps)[pos_Source4]->Update_Chain_Info(false);
}

size_t D_StepWindow::get_root_toUpdate()
{
    if(vUI_Sources.size() > 0)                                              //Do you have sources?
        for(size_t s = 0; s < vUI_Sources.size(); s++)                      //Loop Sources
            if(vUI_Sources[s] > 0)                                          //if source is not 0
                if((*pSteps)[vUI_Sources[s]]->needs_Update())               //Find first Source not updated
                    return (*pSteps)[vUI_Sources[s]]->get_root_toUpdate();  //get its root
    return pos_Dest;                                                        //return this if root ready/not exist
}

void D_StepWindow::Update_Source_Info()
{
    Update_Type_Descriptions();
    Update_Source_Preview();
}

void D_StepWindow::Save_Steps(QDir *dir_save, ofstream *os_stream)
{
    //create sub dir for image
    QDir DIR_SubDirImg(dir_save->path() + "/" + QS_title);
    if(!DIR_SubDirImg.exists())
        QDir().mkdir(DIR_SubDirImg.path());

    //create sub dir for image
    QDir DIR_AllImg(dir_save->path() + "/Images_in_Chain");
    if(!DIR_AllImg.exists())
        QDir().mkdir(DIR_AllImg.path());

    //save image
    Viewer.Save_Image(DIR_SubDirImg.path() + "/Image_" + QString::number(pos_Dest) + ".bmp");
    Viewer.Save_Image(DIR_AllImg.path() + "/Image_" + QString::number(pos_Dest) + ".bmp");

    //get List of Sources
    QString QS_Sources = "";
    for(size_t i = 0; i < vUI_Sources.size(); i++)
    {
        if(i != 0)
            QS_Sources.append("-");
        QS_Sources.append(QString::number(vUI_Sources[i]));
    }

    //get List of Destinations
    QString QS_Destinations = "";
    for(size_t i = 0; i < vUI_Destinations.size(); i++)
    {
        if(i != 0)
            QS_Destinations.append("-");
        QS_Destinations.append(QString::number(vUI_Destinations[i]));
    }

    //stream info
    *os_stream << pos_Dest << ","
               << pos_in_chain << ","
               << QS_Sources.toStdString() << ","
               << QS_Destinations.toStdString() << ","
               << ","
               << QS_title.toStdString() << ","
               << Viewer.img_width() << ","
               << Viewer.img_height() << ","
               << Viewer.Type_MA().toStdString() << ","
               << Viewer.Type_QI().toStdString() << ","
               << ","
               << Viewer.img_val_min() << ","
               << Viewer.img_val_max() << ","
               << Viewer.img_val_range() << ","
               << ","
               << QS_Type.toStdString() << ","
               << QS_Subtype.toStdString() << ","
               << pos_Source1 << ","
               << pos_Source2 << ","
               << pos_Source3 << ","
               << pos_Source4 << ","
               << ",";

    if(!QSL_Parameters.isEmpty())
        for(int p = 0; p < QSL_Parameters.size(); p++)
        {
            QString QS_ParamInfo = QSL_Parameters[p];
            *os_stream << QS_ParamInfo.toStdString()  << ",";
        }

    *os_stream << "\n";
}


void D_StepWindow::Save_Image_Step()
{
    QString name_default =
            pStore->dir_Save()->path() + "/" +
            this->windowTitle() +
            ".jpg";

    QString save_name = Viewer.Save_Image_Dialog(name_default);

    if(!save_name.isEmpty())
        pStore->set_dir_Save(save_name);
}

void D_StepWindow::Save_ImageList_Step()
{
    QString dir_default = pStore->dir_Save()->path() + "/" + this->windowTitle();

    QString dir = QFileDialog::getExistingDirectory(
                this,
                "Save List of Images (choose directory)",
                dir_default);

    if(dir.isEmpty())
        return;

    bool ok;
    QString name = QInputDialog::getText(
                this,
                "Save List of Images (choose file name)",
                "Please enter file name:<I> [NAME]_PlanePosition.Suffix</I>",
                QLineEdit::Normal,
                this->windowTitle(),
                &ok);
    if(!ok)
        return;

    QString suffix = QInputDialog::getText(
                this,
                "Save List of Images (choose file suffix)",
                "Please enter file suffix:<I> Name_PlanePosition.[SUFFIX]</I>",
                QLineEdit::Normal,
                "tif",
                &ok);
    if(!ok)
        return;

    ERR(D_VisDat_Proc::Save_VD_ListFull(
                pStore->get_pVD(pos_Dest),
                dir,
                name,
                suffix,
                ui->comboBox_View_Plane->currentIndex(),
                ui->checkBox_View_VisTrafo->isChecked(),
                ui->comboBox_View_Crop->currentIndex(),
                ui->comboBox_View_Transform->currentIndex(),
                ui->comboBox_View_Anchor->currentIndex(),
                ui->comboBox_View_Range->currentIndex(),
                ui->doubleSpinBox_View_Anchor->value(),
                ui->doubleSpinBox_View_Range->value(),
                ui->doubleSpinBox_View_Min->value(),
                ui->doubleSpinBox_View_Max->value(),
                ui->doubleSpinBox_View_Gamma->value(),
                ui->doubleSpinBox_View_Center->value(),
                ui->doubleSpinBox_View_Divisor->value()),
        "Save_ImageList_Step",
        "Save_VD_ListFull");

    pStore->set_dir_Save(dir_default);
}

void D_StepWindow::Save_VisDat()
{
    QString path = QFileDialog::getSaveFileName(
                this,
                "Save Full 6D Image as binary .visdat File",
                pStore->dir_Save()->path(),
                "Files (*.visdat)");
    if(path.isEmpty())
        return;

    ERR(
                D_VisDat_Proc::Save_VD_ToBinaryFile(
                    pStore->get_pVD(pos_Dest),
                    path),
                "Save_VisDat",
                "Save_VD_ToBinaryFile");

    pStore->set_dir_Save(path);
}

void D_StepWindow::Save_Screenshot_Step()
{
    QString name_default =
            pStore->dir_Save()->path() +
            "/Screenshot " + this->windowTitle();

    QFileInfo FI_save(name_default + ".png");
    int count = 1;
    while(FI_save.exists())
        FI_save.setFile(name_default + "_" + QString::number(count) + ".png");

    //qDebug() << FI_save;
    QString save_name = QFileDialog::getSaveFileName(
                        this,
                        tr("Save Screenshot"),
                        FI_save.absoluteFilePath(),
                        tr("Images (*.png *.bmp *.tif)"));

    //qDebug() << save_name;
    if(save_name.isEmpty())
        return;

    //no idea why this is needed, but there must ne an existing image to overwrite...
    //Viewer.Save_Image(save_name);

    //now save real screenshot
    this->grab().save(save_name);
    pStore->set_dir_Save(save_name);
}

void D_StepWindow::Save_Feature_List()
{
    if(pStore->get_pVD(pos_Dest)->type() != CV_8UC1 && pStore->get_pVD(pos_Dest)->type() != CV_16UC1 && pStore->get_pVD(pos_Dest)->type() != CV_32SC1)
        {
            ERR(
                        ER_type_bad,
                        "Save_FeatureList",
                        "Only binary or label images supported.<br>You could have guessed that... ;-)");
            return;
        }

        D_Component_List CompList(pStore->get_Adress(pos_Dest));

        QString QS_save_csv = QFileDialog::getSaveFileName(
                    this,
                    "Save Feature-Matrix as .csv file.",
                    pStore->dir_Test()->path(),
                    "Files (*.csv)");
        if(QS_save_csv == 0)
            return;

        pStore->set_dir_Test(QS_save_csv);

        ofstream OS_save_csv(QS_save_csv.toStdString());

        for(int f = 0; f < QSL_FeatureList.size(); f++)
            OS_save_csv << QSL_FeatureList[f].toStdString() << ",";

        for(int c = 0; c < CompList.size(); c++)
        {
            OS_save_csv << "\n";
            for(int f = 0; f < QSL_FeatureList.size(); f++)
                OS_save_csv << CompList.get_Feature(c, f) << ",";
        }

        OS_save_csv.close();
}

void D_StepWindow::Save_Analysis()
{
    //wrong type?
    if(pStore->get_pVD(pos_Dest)->type() != CV_8UC1 && pStore->get_pVD(pos_Dest)->type() != CV_16UC1 && pStore->get_pVD(pos_Dest)->type() != CV_32SC1)
        {
            ERR(
                        ER_type_bad,
                        "Save_Analysis",
                        "Only binary or label images supported.<br>You could have guessed that... ;-)");
            return;
        }

    //extended dimensions
    int ext_dim_count = pStore->get_pVD(pos_Dest)->pDim()->extended_DimsCount();

    //to few dimensions?
    if(ext_dim_count < 2)
    {
        ERR(
                    ER_dim_missmatch,
                    "Save_Analysis",
                    "Less than two dimensions are extended. No feature Analysis is possible.");
        return;
    }

    //shown extended dims
    int ext_dim_1;
    int ext_dim_2;

    switch (ui->comboBox_View_Plane->currentIndex()) {
    case c_PLANE_XY:    ext_dim_1 = c_DIM_X;    ext_dim_2 = c_DIM_Y;    break;
    case c_PLANE_XZ:    ext_dim_1 = c_DIM_X;    ext_dim_2 = c_DIM_Z;    break;
    case c_PLANE_XT:    ext_dim_1 = c_DIM_X;    ext_dim_2 = c_DIM_T;    break;
    case c_PLANE_XS:    ext_dim_1 = c_DIM_X;    ext_dim_2 = c_DIM_S;    break;
    case c_PLANE_XP:    ext_dim_1 = c_DIM_X;    ext_dim_2 = c_DIM_P;    break;
    case c_PLANE_YZ:    ext_dim_1 = c_DIM_Y;    ext_dim_2 = c_DIM_Z;    break;
    case c_PLANE_YT:    ext_dim_1 = c_DIM_Y;    ext_dim_2 = c_DIM_T;    break;
    case c_PLANE_YS:    ext_dim_1 = c_DIM_Y;    ext_dim_2 = c_DIM_S;    break;
    case c_PLANE_YP:    ext_dim_1 = c_DIM_Y;    ext_dim_2 = c_DIM_P;    break;
    case c_PLANE_ZT:    ext_dim_1 = c_DIM_Z;    ext_dim_2 = c_DIM_T;    break;
    case c_PLANE_ZS:    ext_dim_1 = c_DIM_Z;    ext_dim_2 = c_DIM_S;    break;
    case c_PLANE_ZP:    ext_dim_1 = c_DIM_Z;    ext_dim_2 = c_DIM_P;    break;
    case c_PLANE_TS:    ext_dim_1 = c_DIM_T;    ext_dim_2 = c_DIM_S;    break;
    case c_PLANE_TP:    ext_dim_1 = c_DIM_T;    ext_dim_2 = c_DIM_P;    break;
    case c_PLANE_SP:    ext_dim_1 = c_DIM_S;    ext_dim_2 = c_DIM_P;    break;
    default:                                                            break;}

    //change ext dims?
    if(ext_dim_count > 2)
    {
        if(QMessageBox::Yes != QMessageBox::question(
                    this,
                    "Save_Analysis",
                    "Dimensions " + pStore->get_pVD(pos_Dest)->pDim()->extended_DimsString() + " are extended in this dataset."
                    "<br>Feature analysis is only supported for 2D. "
                    "<br>Currently shown extended dimensions " + QSL_DimIndices[ext_dim_1] + " and " + QSL_DimIndices[ext_dim_2] + " are treated as processing dimensions."
                    "<br>Other Dimensions are looped (every position)."
                    "<br><br>Proceed with current settings?"))
        {
            vector<int> vDim = {ext_dim_1, ext_dim_2};
            D_Popup_ListEdit pop_dim("Please select two processing dimensions", &vDim, QSL_DimNames, 0);
            pop_dim.exec();
            if(vDim.size() != 2)
            {
                QMessageBox::warning(
                            this,
                            "Processing dimensions count does not fit",
                            "Processing dimensions must count must be 2 and is " + QString::number(vDim.size()) + "."
                            "<br>Analysis is quit");
                return;
            }
            else
            {
                ext_dim_1 = vDim[0];
                ext_dim_2 = vDim[1];
            }
        }
    }

    //Slicing
    D_VisDat_Slicing Slicing;
    Slicing.set_proc_Dim(ext_dim_1, true);
    Slicing.set_proc_Dim(ext_dim_2, true);

    //get feats of interest
    vector<int> vFeatList = {c_FEAT_AREA};
    D_Popup_ListEdit pop_feat("Select feartures of interest" , &vFeatList, QSL_FeatureList, c_FEAT_AREA);
    pop_feat.exec();
    if(vFeatList.empty())
    {
        QMessageBox::warning(
                    this,
                    "Features missing",
                    "No feature is selected. Analysis is quit.");
        return;
    }

    //calc stats?
    bool calc_stats = QMessageBox::Yes == QMessageBox::question(
                this,
                "Additional statistics",
                "Calculate describing statistical quantities for the selected features?");

    //how to calc stats?
    int stats_mode = -1;
    bool calc_stats_all = false;
    bool calc_stats_sli = false;
    if(calc_stats)
    {
        if(ext_dim_count > 2)
        {
            stats_mode = QMessageBox::question(
                        this,
                        "Statistics mode",
                        "Calculate selected statistical quantities for set(s):",
                        "all slices",
                        "per slice",
                        "both",
                        0,
                        -1);

            if(stats_mode == -1)
            {
                calc_stats = false;
            }
            else
            {
                calc_stats_all = (stats_mode == 0) || (stats_mode == 2);
                calc_stats_sli = (stats_mode == 1) || (stats_mode == 2);
            }
        }
        else
        {
            calc_stats_all = true;
            calc_stats_sli = false;
        }
    }

    //get stats of interest
    vector<int> vStatList = {c_STAT_MEAN_ARITMETIC, c_STAT_STAN_DEV_SAMPLE, c_STAT_SEM_ABS_SAMPLE};
    if(calc_stats)
    {
        D_Popup_ListEdit pop_stat("Select statistics of interest" , &vStatList, QSL_StatList, c_STAT_MEAN_ARITMETIC);
        pop_stat.exec();
        if(vStatList.empty())
            calc_stats = false;
    }

    //Save Dir
    QString QS_save_path = QFileDialog::getExistingDirectory(
                this,
                "Save feature analysis in directory",
                pStore->dir_Test()->path());
    if(QS_save_path == 0)
        return;
    QDir DIR_Save(QS_save_path);
    if(!DIR_Save.exists())
        QDir().mkdir(DIR_Save.path());
    pStore->set_dir_Test(DIR_Save.path());

    //Streams
    //feats
    ofstream OS_feats(QString(DIR_Save.path() +"/FeatureAnalysis_Features.csv").toStdString());
    OS_feats << "X,Y,Z,T,S,P,";
    for(int f = 0; f < vFeatList.size(); f++)
        OS_feats << "," << QSL_FeatureList[vFeatList[f]].toStdString();
    OS_feats << "\n";

    //stats
    ofstream OS_stats;
    if(calc_stats)
    {
        OS_stats.open(QString(DIR_Save.path() +"/FeatureAnalysis_Statistics.csv").toStdString());
        OS_stats << "X,Y,Z,T,S,P,";
        for(int f = 0; f < vFeatList.size(); f++)
        {
            for(int s = 0; s < vStatList.size(); s++)
                OS_stats << "," << QSL_FeatureList[vFeatList[f]].toStdString();
            OS_stats << ",";
        }
        OS_stats << "\n,,,,,,";
        for(int f = 0; f < vFeatList.size(); f++)
        {
            for(int s = 0; s < vStatList.size(); s++)
                OS_stats << "," << QSL_StatList[vStatList[s]].toStdString();
            OS_stats << ",";
        }
        OS_stats << "\n";
    }

    //save feats to calc stats for all components, if needed
    vector<vector<double>> vvFeatsAll(vFeatList.size());

    //Loop------------------------------------------------------------------------------------------------------
    cv::Mat MA_tmp;
    Slicing.loop_Init(pStore->get_pVD(pos_Dest)->Dim());
    do
    {
        //Current position
        D_VisDat_Slice_2D slice = Slicing.loop2D_SliceCurrent();

        //get slice
        int ER = D_VisDat_Proc::Read_2D_Plane(
                    &MA_tmp,
                    pStore->get_pVD(pos_Dest),
                    slice);
        ERR(
                    ER,
                    "Save_Analysis",
                    "Looping throung dimensions(get slice):<br>" + slice.info());
        if(ER != ER_okay)
        {
            OS_feats.close();
            if(OS_stats.is_open())
                OS_stats.close();
            return;
        }

        //calc components
        D_Component_List CompList(&MA_tmp);

        //export feats...............................................................
        for(int c = 0; c < CompList.size(); c++)
        {
            //position
            OS_feats << "\n";
            for(int d = 0; d < c_DIM_NUMBER_OF; d++)
            {
                if(d == ext_dim_1 || d == ext_dim_2)
                    OS_feats << "all,";
                else if(pStore->get_pVD(pos_Dest)->pDim()->size_Dim(d) == 1)
                    OS_feats << "fix,";
                else
                    OS_feats << slice.pos_Dim(d) << ",";
            }
            OS_feats << ",";

            //feats
            for(int f = 0; f < vFeatList.size(); f++)
                OS_feats << CompList.get_Feature(c, vFeatList[f]) << ",";
        }
        OS_feats << "\n";

        //calc & export stats slice..............................................................
        if(calc_stats_sli)
        {
            //position
            OS_stats << "\n";
            for(int d = 0; d < c_DIM_NUMBER_OF; d++)
            {
                if(d == ext_dim_1 || d == ext_dim_2)
                    OS_stats << "all,";
                else if(pStore->get_pVD(pos_Dest)->pDim()->size_Dim(d) == 1)
                    OS_stats << "fix,";
                else
                    OS_stats << slice.pos_Dim(d) << ",";
            }

            for(int f = 0; f < vFeatList.size(); f++)
            {
                //calc stats
                vector<double> vStatsSlice;
                int ER = D_Stat::Calc_Stats(
                            &vStatsSlice,
                            CompList.get_FeatureVector(vFeatList[f]),
                            true);
                if(ER != ER_empty && ER != ER_okay)
                {
                    ERR(
                                ER,
                                "Save_Analysis",
                                "Looping throung dimensions(calc stats):<br>" + slice.info());
                    OS_feats.close();
                    OS_stats.close();
                    return;
                }

                //export stats
                OS_stats << ",";
                for(int s = 0; s < vStatList.size(); s++)
                    OS_stats << vStatsSlice[vStatList[s]] << ",";
            }
        }

        //save stats all.........................................................................
        if(calc_stats_all)
        {
            for(int c = 0; c < CompList.size(); c++)
                for(int f = 0; f < vFeatList.size(); f++)
                    vvFeatsAll[f].push_back(CompList.get_Feature(c, vFeatList[f]));
        }
        //........................................................................................
    }
    while (Slicing.loop_Next());
    //Loop end ------------------------------------------------------------------------------------------------------

    //calc stats all
    if(calc_stats_all)
    {
        //position
        OS_stats << "\n";
        for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        {
            if(pStore->get_pVD(pos_Dest)->pDim()->size_Dim(d) == 1)
                OS_stats << "fix,";
            else
                OS_stats << "all,";
        }

        for(int f = 0; f < vFeatList.size(); f++)
        {
            //calc stats
            vector<double> vStatsAll;
            int ER = D_Stat::Calc_Stats(
                        &vStatsAll,
                        vvFeatsAll[f],
                        true);
            ERR(
                        ER,
                        "Save_Analysis",
                        "Calc stats for all slices.");
            if(ER != ER_okay)
            {
                OS_feats.close();
                OS_stats.close();
                return;
            }

            //export stats
            OS_stats << ",";
            for(int s = 0; s < vStatList.size(); s++)
                OS_stats << vStatsAll[vStatList[s]] << ",";
        }
    }

    //close streams
    OS_feats.close();
    if(OS_stats.is_open())
        OS_stats.close();
}

void D_StepWindow::Connect_HistSettings_2_UpdateHist(bool con)
{
    if(con)
    {
        connect(ui->checkBox_Output_Hist_Uniform,       SIGNAL(toggled(bool)),     this,   SLOT(Update_Hist()));
        connect(ui->checkBox_Output_Hist_Accumulate,    SIGNAL(toggled(bool)),     this,   SLOT(Update_Hist()));
        connect(ui->checkBox_Output_Hist_Full6D,        SIGNAL(toggled(bool)),     this,   SLOT(Update_Hist()));
        connect(ui->spinBox_HistClasses,                SIGNAL(valueChanged(int)), this,   SLOT(Update_Hist()));
        /*
        connect(ui->checkBox_Output_Hist_Ch0,           SIGNAL(toggled(bool)),     this,   SLOT(Update_Hist()));
        connect(ui->checkBox_Output_Hist_Ch1,           SIGNAL(toggled(bool)),     this,   SLOT(Update_Hist()));
        connect(ui->checkBox_Output_Hist_Ch2,           SIGNAL(toggled(bool)),     this,   SLOT(Update_Hist()));
        connect(ui->checkBox_Output_Hist_Ch3,           SIGNAL(toggled(bool)),     this,   SLOT(Update_Hist()));
        */

    }
    else
    {
        disconnect(ui->checkBox_Output_Hist_Uniform,    SIGNAL(toggled(bool)),     this,   SLOT(Update_Hist()));
        disconnect(ui->checkBox_Output_Hist_Accumulate, SIGNAL(toggled(bool)),     this,   SLOT(Update_Hist()));
        disconnect(ui->checkBox_Output_Hist_Full6D,     SIGNAL(toggled(bool)),     this,   SLOT(Update_Hist()));
        disconnect(ui->spinBox_HistClasses,             SIGNAL(valueChanged(int)), this,   SLOT(Update_Hist()));
        /*
        disconnect(ui->checkBox_Output_Hist_Ch0,        SIGNAL(toggled(bool)),     this,   SLOT(Update_Hist()));
        disconnect(ui->checkBox_Output_Hist_Ch1,        SIGNAL(toggled(bool)),     this,   SLOT(Update_Hist()));
        disconnect(ui->checkBox_Output_Hist_Ch2,        SIGNAL(toggled(bool)),     this,   SLOT(Update_Hist()));
        disconnect(ui->checkBox_Output_Hist_Ch3,        SIGNAL(toggled(bool)),     this,   SLOT(Update_Hist()));
        */
    }
}

void D_StepWindow::Connect_TimesSettings_2_UpdateTimes(bool con)
{
    if(con)
    {
        connect(ui->checkBox_Output_Times_Processing,   SIGNAL(toggled(bool)),     this,   SLOT(Update_Times()));
        connect(ui->checkBox_Output_Times_Conversion,   SIGNAL(toggled(bool)),     this,   SLOT(Update_Times()));
        connect(ui->checkBox_Output_Times_Show,         SIGNAL(toggled(bool)),     this,   SLOT(Update_Times()));
        connect(ui->checkBox_Output_Times_Hist,         SIGNAL(toggled(bool)),     this,   SLOT(Update_Times()));
    }
    else
    {
        disconnect(ui->checkBox_Output_Times_Processing,SIGNAL(toggled(bool)),     this,   SLOT(Update_Times()));
        disconnect(ui->checkBox_Output_Times_Conversion,SIGNAL(toggled(bool)),     this,   SLOT(Update_Times()));
        disconnect(ui->checkBox_Output_Times_Show,      SIGNAL(toggled(bool)),     this,   SLOT(Update_Times()));
        disconnect(ui->checkBox_Output_Times_Hist,      SIGNAL(toggled(bool)),     this,   SLOT(Update_Times()));
    }
}

void D_StepWindow::Connect_ImgProcSettings_2_UpdateImgProc(bool con)
{
    if(con)
    {
        //SOURCE
        //Load
        connect(ui->pushButton_00_Load_Image,               SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
      //connect(ui->comboBox_00_Load_Mode,                  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_00_Load_Source_Dim_X,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_00_Load_Source_Dim_Y,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_00_Load_Source_Dim_List,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_00_Load_Source_Dim_Pages,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_00_Load_Force8UC1,             SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //Sample
        connect(ui->comboBox_00_Sample_Paths,               SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //Generate
        connect(ui->comboBox_00_Generate_DimVar,                    SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_00_Generate_ValueFunction_2D,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_00_Generate_ValueFunction_2D_Complex,  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_00_Generate_ValueFunction_6D,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_Generate_Size_X,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_Generate_Size_Y,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_Generate_Size_Z,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_Generate_Size_T,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_Generate_Size_S,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_Generate_Size_P,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_a,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_b,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_c,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_d,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_e,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_f,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_nan,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_inf,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_Complex_sx,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_Complex_ox,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_Complex_sy,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_Complex_oy,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_Complex_a,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_Complex_b,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_Complex_c,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_Complex_d,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_Complex_e,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_Complex_f,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_Complex_nan,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_2D_Complex_inf,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_sx,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_ox,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_sy,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_oy,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_sz,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_oz,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_st,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_ot,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_ss,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_os,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_sp,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_op,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_a,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_b,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_c,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_d,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_e,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_f,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_inf,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Generate_6D_nan,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Random
        connect(ui->comboBox_00_Random_Type,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_Random_Size_X,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_Random_Size_Y,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_Random_Size_Z,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_Random_Size_T,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_Random_Size_S,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_Random_Size_P,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Random_Min,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Random_Max,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Random_a,              SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Random_b,              SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Random_c,              SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Random_d,              SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Random_e,              SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_Random_f,              SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Cast Raw
        connect(ui->comboBox_00_CastRaw_BitPerPixel,        SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_CastRaw_Width,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_CastRaw_Height,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Video Stream
        connect(ui->pushButton_00_VideoStream_Browse,               SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_VideoStream_Blur_Size,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_VideoStream_Blur_Sigma,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_00_VideoStream_T1_Stat,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_VideoStream_T1_Frames,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_00_VideoStream_T2_Stat,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_VideoStream_T2_Frames,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_00_VideoStream_T_Offset,                SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_00_VideoStream_CombiFunction,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_00_VideoStream_Force_8bit,             SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_VideoStream_CombiFunction_a,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_VideoStream_CombiFunction_b,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_VideoStream_CombiFunction_c,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_VideoStream_CombiFunction_d,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_VideoStream_CombiFunction_e,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_VideoStream_CombiFunction_f,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_VideoStream_CombiFunction_nan, SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_00_VideoStream_CombiFunction_inf, SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //EDIT
        //Crop
        connect(ui->comboBox_01_Crop_Shape,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_01_Crop_Rect_X1,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_01_Crop_Rect_Y1,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_01_Crop_Rect_X2,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_01_Crop_Rect_Y2,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Crop_RectAbs_Offset_X,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Crop_RectAbs_Offset_Y,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Crop_RectAbs_Size_X,         SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Crop_RectAbs_Size_Y,         SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Crop_RectRot_Center_X,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Crop_RectRot_Center_Y,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Crop_RectRot_Width,          SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Crop_RectRot_Height,         SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_01_Crop_RectRot_Rotation, SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Crop_Circle_Center_X,        SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Crop_Circle_Center_Y,        SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Crop_Circle_Radius,          SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Crop_Ellipse_Center_X,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Crop_Ellipse_Center_Y,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Crop_Ellipse_Width,          SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Crop_Ellipse_Height,         SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_01_Crop_Ellipse_Rotation, SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Floodfill
        connect(ui->comboBox_01_Floodfill_Type,             SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_01_Floodfill_Value_Fill,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_01_Floodfill_Delta_Delta, SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Floodfill_Delta_SeedX,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Floodfill_Delta_SeedY,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Padding
        connect(ui->spinBox_01_Padding_Width_X,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Padding_Width_Y,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Padding_Width_Z,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_01_Padding_Value,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_01_Padding_Type,               SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //Force Size
        connect(ui->comboBox_01_ForceSize_Border,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_ForceSize_Width,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_ForceSize_Height,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Scale
        connect(ui->comboBox_01_Scale_Type,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_01_Scale_Factor_X,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_01_Scale_Factor_Y,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Scale_Size_X,                SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_01_Scale_Size_Y,                SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //CONVERT
        //Color 2 Mono
        connect(ui->comboBox_02_Color2Mono_Reduction,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //Color
        connect(ui->comboBox_02_Color_Direction_Left,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_02_Color_Direction_Top,        SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_BGR_RGB,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_Grey_BGR,          SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_Grey_RGB,          SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_HSL_BGR,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_HSL_RGB,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_HSV_BGR,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_HSV_RGB,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_Lab_BGR,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_Lab_RGB,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_Luv_BGR,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_Luv_RGB,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_RGB_BGR,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_RGB_RGB,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_XYZ_BGR,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_XYZ_RGB,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_YCrCb_BGR,         SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_02_Color_YCrCb_RGB,         SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //Depth
        connect(ui->comboBox_02_Depth_Norm,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_02_Depth_Type,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_02_Depth_Maximum,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_02_Depth_Minimum,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Merge
        connect(ui->spinBox_02_Merge_Channels,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_02_Merge_Ch0,                  SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_02_Merge_Ch1,                  SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_02_Merge_Ch2,                  SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_02_Merge_Ch3,                  SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //Split
        connect(ui->spinBox_02_Split_Channel,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Combi
        connect(ui->comboBox_02_Combi_Type,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //angle to color
        connect(ui->spinBox_02_Angle2Color_S,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_02_Angle2Color_V,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //ELEMENTAL
        //Threshold
        connect(ui->comboBox_03_Thres_Type,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_03_Thres_Max_Value_Out,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_03_Thres_Output_Mode,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_03_Thres_Thres_Value_Abs,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->horizontalSlider_03_Thres_Abs_Thres_Value,SIGNAL(valueChanged(int)),        this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_03_Thres_Rel_Base,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_03_Thres_Rel_Thres_Rel,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->horizontalSlider_03_Thres_Rel_Thresh_Rel,SIGNAL(valueChanged(int)),         this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_03_Thres_Rel_Thresh_Abs,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_03_Thres_Adapt_Type,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_03_Thres_Adapt_Offset,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_03_Thres_Mask_Size,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_03_Thres_RankHysteresis_Radius,           SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_03_Thres_RankHysteresis_Quantil,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_03_Thres_RankHysteresis_ThresIndicator,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_03_Thres_RankHysteresis_ThresHysteresis,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Labeling
        connect(ui->comboBox_03_Labeling_Connectivity,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_03_Labeling_Depth,             SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_03_Labeling_Type,              SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //Color Grab
        connect(ui->comboBox_03_GrabColor_ColorSpace,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_03_GrabColor_Output,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_03_GrabColor_Ch1_Min,           SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_03_GrabColor_Ch2_Min,           SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_03_GrabColor_Ch3_Min,           SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_03_GrabColor_Ch1_Max,           SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_03_GrabColor_Ch2_Max,           SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_03_GrabColor_Ch3_Max,           SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //FILTER
        connect(ui->comboBox_04_Border_Type,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_04_Force_8bit,                 SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //Blur
        connect(ui->comboBox_04_Blur_Depth,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_04_Blur_Type,                  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_Blur_Size,                   SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_Blur_Size_X,                 SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_Blur_Size_Y,                 SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Blur_Sigma_X,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Blur_Sigma_Y,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_04_Blur_Normalized,            SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //edge
        connect(ui->comboBox_04_Edge_Depth,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_04_Edge_Type,                  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_Edge_dX,                     SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_Edge_dY,                     SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_Edge_Size,                   SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Edge_Delta,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Edge_Scale,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_Edge_Thresh_Low,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_Edge_Thresh_High,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_04_Edge_L2_Gradient,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //Special
        connect(ui->comboBox_04_Special_Depth,              SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_04_Special_Type,               SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_Special_Diameter,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_Special_Size_X,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_Special_Size_Y,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Special_Delta,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Special_Gamma,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Special_Lambda,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Special_Psi,           SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Special_Sigma,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Special_Sigma_Color,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Special_Sigma_Space,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Special_Theta,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Eilenstein
        connect(ui->comboBox_04_Eilenstein_Comparator,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_Eilenstein_Size_X,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_Eilenstein_Size_Y,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_Delta,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_04_Eilenstein_Normalized,          SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_04_Eilenstein_Type,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_04_Eilenstein_PixelMask,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_04_Eilenstein_PixelCenter,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_04_Eilenstein_Response,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_PixelMask_a,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_PixelMask_b,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_PixelMask_c,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_PixelMask_d,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_PixelMask_e,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_PixelMask_f,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_PixelMask_nan,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_PixelMask_inf,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_PixelCenter_a,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_PixelCenter_b,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_PixelCenter_c,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_PixelCenter_d,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_PixelCenter_e,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_PixelCenter_f,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_PixelCenter_nan,SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Eilenstein_PixelCenter_inf,SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Function
        connect(ui->checkBox_04_Function_OnlyNonZero,       SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_04_Function_f1_CenterImage,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_04_Function_f2_F1Mask,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_04_Function_f3_vF2,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_04_Function_f4_CenterF3,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f1_a,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f1_b,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f1_c,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f1_d,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f1_e,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f1_f,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f1_nan,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f1_inf,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f2_a,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f2_b,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f2_c,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f2_d,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f2_e,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f2_f,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f2_nan,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f2_inf,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f4_a,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f4_b,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f4_c,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f4_d,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f4_e,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f4_f,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f4_nan,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Function_f4_inf,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Rank Order
        connect(ui->doubleSpinBox_04_RankOrder_Quantil,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //connect(ui->comboBox_04_RankOrder_MaskType,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_RankOrder_Radius,      SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_RankOrder_Size_x,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_RankOrder_Size_y,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Statistic filter
        connect(ui->comboBox_04_Statistic_Stat,             SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_04_Statistic_MaskType,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_04_Statistic_Radius,      SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_Statistic_Size_x,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_04_Statistic_Size_y,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Custom
        //MORPHOLOGY
        //Elemental
        connect(ui->comboBox_05_Elem_Border_Type,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_05_Elem_Elem_Type,             SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_05_Elem_Morph_Type,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_05_Elem_Elem_Size_X,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_05_Elem_Elem_Size_Y,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_05_Elem_Iterations,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Min/Max Gil
        connect(ui->comboBox_05_MinMaxGil_MinMax,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_05_MinMaxGil_SizeX,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_05_MinMaxGil_SizeY,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Reconstruct
        connect(ui->doubleSpinBox_05_Reconstruction_Quantil,SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Local Maxima
        connect(ui->spinBox_05_LocalMaxima_Size_X,          SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_05_LocalMaxima_Size_Y,          SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //MATH
        //1 Image simple
        connect(ui->comboBox_06_1Img_Type,                  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_1Img_Arg,              SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //2 Images simple
        connect(ui->comboBox_06_2Img_Comparator,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_06_2Img_Type,                  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2Img_Scale,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2Img_Weight_1,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2Img_Weight_2,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2Img_Weight_Sum,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Function
        connect(ui->comboBox_06_2ImgFunction_Function,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_a,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_b,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_c,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_d,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_e,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_f,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_nan,      SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_inf,      SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_06_2ImgFunction_Force_8bit,    SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //Function Complex
        connect(ui->comboBox_06_2ImgFunction_Complex_Function,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_Complex_sx,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_Complex_ox,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_Complex_sy,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_Complex_oy,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_Complex_a,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_Complex_b,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_Complex_c,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_Complex_d,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_Complex_e,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_Complex_f,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_Complex_nan,      SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_2ImgFunction_Complex_inf,      SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //3 Image simple
        connect(ui->comboBox_06_3Img_Type,                  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_3Img_Value,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_06_3Img_Value,                 SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //4 Image simple
        connect(ui->comboBox_06_4Img_Type,                  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_06_4Img_Value,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_06_4Img_Value,                 SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //TRANSFORMATION
        //Distance
        connect(ui->comboBox_07_Dist_Metric,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_07_Dist_Precision,             SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //Watershade
        connect(ui->comboBox_07_Watershed_Connectivity,                     SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_07_Watershed_Auto,                             SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_07_Watershed_8bit,                             SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_07_Watershed_InclNonSeed,                      SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_07_Watershed_ExclBorder,                       SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_07_WatershedCustom_Flood,                      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_07_WatershedCustom_Marker,                     SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_07_WatershedCustom_Mask,                       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_07_WatershedCustom_ExcludeBorder,              SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_07_WatershedCustom_IncludeNonSeed,             SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_07_WatershedCustom_DrawWatershed,              SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_07_WatershedCustom_DrawWatershed_Neighborhood, SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_07_WatershedCustom_Flood_GaussSigma,      SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_07_WatershedCustom_Mask_Thres,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_07_WatershedCustom_Flood_GaussSize,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_07_WatershedCustom_Flood_Morph_Size,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_07_WatershedCustom_Marker_LabelNeighborhood,   SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_07_WatershedCustom_Flood_Morph_Elem,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //Fourier
        connect(ui->checkBox_07_Fourier_Invers,             SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_07_Fourier_ForceFFT,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_07_Fourier_Output_Scale,       SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_07_Fourier_Output_no_f0,       SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_07_Fourier_Input_Complex,      SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_07_Fourier_Output_Centered,    SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_07_Fourier_Output_RealOnly,    SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_07_Fourier_Output_ComplexMode, SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //FEATURE
        //Value
        connect(ui->comboBox_08_FeatVal_Feature,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_FeatVal_Connectivity,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //Value Context
        connect(ui->comboBox_08_FeatContextVal_Connectivity,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_FeatContextVal_DistPt1,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_FeatContextVal_DistPt2,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_FeatContextVal_Feat,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_FeatContextVal_Stat,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_FeatContextVal_DistMin,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_FeatContextVal_DistMax,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_FeatContextSelect_Connectivity, SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_FeatContextSelect_DistPt1,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_FeatContextSelect_DistPt2,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_FeatContextSelect_Feat,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_FeatContextSelect_Stat,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_FeatContextSelect_DistMin, SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_FeatContextSelect_DistMax, SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_FeatContextSelect_ThresMin,SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_FeatContextSelect_ThresMax,SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Select
        connect(ui->comboBox_08_Select_Type,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_Select_Connectivity,        SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_Select_Min,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_Select_Max,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //connect
        connect(ui->comboBox_08_Connect_DistPt1,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_Connect_DistPt2,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_Connect_Feat1,              SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_Connect_Feat2,              SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_Connect_Cond,               SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_Connect_ConnectType,        SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_08_Connect_Thickness,           SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_Connect_DistMin,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_Connect_DistMax,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_Connect_Cond_a,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_Connect_Cond_b,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_Connect_Cond_c,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_Connect_Cond_d,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_Connect_Cond_e,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_Connect_Cond_f,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_Connect_Cond_g,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_Connect_Cond_h,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //reduce
        connect(ui->comboBox_08_Reduce_Type,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_08_Reduce_Thickness,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_08_Reduce_Value,                SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_Reduce_Connectivity,        SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //visualize
        connect(ui->comboBox_08_Visualize_Feature,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_Visualize_Connectivity,     SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_Visualize_Scale,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_08_Visualize_Thickness,         SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //value stat
        connect(ui->comboBox_08_ValueStat_Connectivity,     SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_ValueStat_Stat,             SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //value stat select
        connect(ui->comboBox_08_ValueStatSelect_Connectivity,   SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_08_ValueStatSelect_Stat,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_ValueStatSelect_Min,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_08_ValueStatSelect_Max,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //OTHER
        //gamma spread
        connect(ui->doubleSpinBox_09_GammaSpread_Gamma,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_GammaSpread_InMin,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_GammaSpread_InMax,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_GammaSpread_OutMin,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_GammaSpread_OutMax,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_09_GammaSpread_Force8bit,      SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //label numbers
        connect(ui->spinBox_09_LabelNo_Thickness,           SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_LabelNo_Scale,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_09_LabelNo_Position,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //motion field
        connect(ui->spinBox_09_MotionField_SizeSpace,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_09_MotionField_SizeTime,        SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //class border kNN
        connect(ui->spinBox_09_kNN_n,                       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //HDR
        connect(ui->comboBox_09_HDR_Dim,                    SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_09_HDR_ProjectStat,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_09_HDR_Project,                SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_09_HDR_Thresh,                 SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_HDR_Exposure_Min,      SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_HDR_Exposure_Factor,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_HDR_Thresh_Low,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_HDR_Thresh_High,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Relation Stat
        connect(ui->comboBox_09_RelationStat_StatDistance,  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_09_RelationStat_StatAngle,     SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_09_RelationStat_Distance,   SIGNAL(clicked()),                  this,   SLOT(Update_Img_Proc()));
        connect(ui->radioButton_09_RelationStat_Angle,      SIGNAL(clicked()),                  this,   SLOT(Update_Img_Proc()));
        //Zernike Stack
        connect(ui->spinBox_09_ZernikeStack_Radius,         SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_09_ZernikeStack_J,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Radiometric Stereo
        connect(ui->comboBox_09_RadiometricStereo_OutMode,  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_RadiometricStereo_X1,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_RadiometricStereo_X2,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_RadiometricStereo_X3,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_RadiometricStereo_X4,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_RadiometricStereo_Y1,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_RadiometricStereo_Y2,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_RadiometricStereo_Y3,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_RadiometricStereo_Y4,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_RadiometricStereo_Z1,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_RadiometricStereo_Z2,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_RadiometricStereo_Z3,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_RadiometricStereo_Z4,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Michelson Interferometer
        connect(ui->spinBox_09_Michelson_Scene_Size_X,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_09_Michelson_Scene_Size_Y,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_09_Michelson_Scene_Size_Z,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_09_Michelson_Scale_px,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_Michelson_Scale_um,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_Michelson_Wavelength,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_Michelson_Source_distance,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_Michelson_Detector_distance,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_Michelson_Mirror1_distance,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_Michelson_Mirror2_distance,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_Michelson_Mirror1_angle_x,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_Michelson_Mirror1_angle_y,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_Michelson_Mirror2_angle_x,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_09_Michelson_Mirror2_angle_y,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_09_Michelson_Beam_atSO_SO,             SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_09_Michelson_Beam_atSO_M1_SO,          SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_09_Michelson_Beam_atSO_SP_M2_SP_SO,       SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_09_Michelson_Beam_atM1_SO,             SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_09_Michelson_Beam_atM1_M1_SO,          SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_09_Michelson_Beam_atM2_SP_SO,          SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_09_Michelson_Beam_atM2_M2_SP_SO,       SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_09_Michelson_Beam_atDE_SP_M1_SO,       SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_09_Michelson_Beam_atDE_M2_SP_SO,       SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_09_Michelson_Show_IorE,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //DIMENSION
        //Pick
        connect(ui->checkBox_10_Pick_X,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_10_Pick_Y,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_10_Pick_Z,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_10_Pick_T,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_10_Pick_S,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_10_Pick_P,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Pick_X,                      SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Pick_Y,                      SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Pick_Z,                      SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Pick_T,                      SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Pick_S,                      SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Pick_P,                      SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Crop
        connect(ui->checkBox_10_Crop_X,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_10_Crop_Y,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_10_Crop_Z,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_10_Crop_T,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_10_Crop_S,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_10_Crop_P,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Crop_Min_X,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Crop_Min_Y,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Crop_Min_Z,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Crop_Min_T,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Crop_Min_S,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Crop_Min_P,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Crop_Max_X,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Crop_Max_Y,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Crop_Max_Z,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Crop_Max_S,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Crop_Max_T,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Crop_Max_P,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Project
        connect(ui->comboBox_10_Project_Dimension,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_10_Project_Stat,               SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->checkBox_10_Project_8bit,               SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //Deserialise
        connect(ui->comboBox_10_Deserialise_Dimension_In,   SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->comboBox_10_Deserialise_Dimension_Out,  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Deserialise_Spacing,         SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Pages2Color
        connect(ui->spinBox_10_Page2Color_R,                SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Page2Color_G,                SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        connect(ui->spinBox_10_Page2Color_B,                SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Stitch
        connect(ui->comboBox_10_Stitching_Mode,             SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_10_Stitching_Border_R,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_10_Stitching_Border_B,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_10_Stitching_Overlap_R,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        connect(ui->doubleSpinBox_10_Stitching_Overlap_B,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
    }
    else
    {
        //SOURCE
        //Load
        disconnect(ui->pushButton_00_Load_Image,               SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
      //disconnect(ui->comboBox_00_Load_Mode,                  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_00_Load_Source_Dim_X,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_00_Load_Source_Dim_Y,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_00_Load_Source_Dim_List,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_00_Load_Source_Dim_Pages,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_00_Load_Force8UC1,             SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //Sample
        disconnect(ui->comboBox_00_Sample_Paths,               SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //Generate
        disconnect(ui->comboBox_00_Generate_DimVar,                     SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_00_Generate_ValueFunction_2D,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_00_Generate_ValueFunction_2D_Complex,   SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_00_Generate_ValueFunction_6D,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_Generate_Size_X,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_Generate_Size_Y,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_Generate_Size_Z,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_Generate_Size_T,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_Generate_Size_S,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_Generate_Size_P,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_a,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_b,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_c,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_d,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_e,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_f,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_nan,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_inf,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_Complex_sx,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_Complex_ox,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_Complex_sy,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_Complex_oy,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_Complex_a,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_Complex_b,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_Complex_c,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_Complex_d,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_Complex_e,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_Complex_f,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_Complex_nan,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_2D_Complex_inf,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_sx,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_ox,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_sy,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_oy,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_sz,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_oz,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_st,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_ot,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_ss,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_os,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_sp,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_op,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_a,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_b,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_c,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_d,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_e,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_f,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_inf,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Generate_6D_nan,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Random
        disconnect(ui->comboBox_00_Random_Type,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_Random_Size_X,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_Random_Size_Y,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_Random_Size_Z,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_Random_Size_T,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_Random_Size_S,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_Random_Size_P,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Random_Min,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Random_Max,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Random_a,              SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Random_b,              SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Random_c,              SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Random_d,              SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Random_e,              SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_Random_f,              SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Cast raw
        disconnect(ui->comboBox_00_CastRaw_BitPerPixel,        SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_CastRaw_Width,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_CastRaw_Height,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Video Stream
        disconnect(ui->pushButton_00_VideoStream_Browse,               SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_VideoStream_Blur_Size,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_VideoStream_Blur_Sigma,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_00_VideoStream_T1_Stat,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_VideoStream_T1_Frames,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_00_VideoStream_T2_Stat,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_VideoStream_T2_Frames,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_00_VideoStream_T_Offset,                SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_00_VideoStream_CombiFunction,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_00_VideoStream_Force_8bit,             SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_VideoStream_CombiFunction_a,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_VideoStream_CombiFunction_b,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_VideoStream_CombiFunction_c,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_VideoStream_CombiFunction_d,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_VideoStream_CombiFunction_e,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_VideoStream_CombiFunction_f,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_VideoStream_CombiFunction_nan, SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_00_VideoStream_CombiFunction_inf, SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //EDIT
        //Crop
        disconnect(ui->comboBox_01_Crop_Shape,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_01_Crop_Rect_X1,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_01_Crop_Rect_Y1,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_01_Crop_Rect_X2,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_01_Crop_Rect_Y2,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Crop_RectAbs_Offset_X,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Crop_RectAbs_Offset_Y,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Crop_RectAbs_Size_X,         SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Crop_RectAbs_Size_Y,         SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Crop_RectRot_Center_X,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Crop_RectRot_Center_Y,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Crop_RectRot_Width,          SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Crop_RectRot_Height,         SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_01_Crop_RectRot_Rotation, SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Crop_Circle_Center_X,        SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Crop_Circle_Center_Y,        SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Crop_Circle_Radius,          SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Crop_Ellipse_Center_X,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Crop_Ellipse_Center_Y,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Crop_Ellipse_Width,          SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Crop_Ellipse_Height,         SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_01_Crop_Ellipse_Rotation, SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Floodfill
        disconnect(ui->comboBox_01_Floodfill_Type,             SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_01_Floodfill_Value_Fill,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Padding
        disconnect(ui->spinBox_01_Padding_Width_X,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Padding_Width_Y,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Padding_Width_Z,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_01_Padding_Value,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_01_Padding_Type,               SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //Force Size
        disconnect(ui->comboBox_01_ForceSize_Border,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_ForceSize_Width,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_ForceSize_Height,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Scale
        disconnect(ui->comboBox_01_Scale_Type,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_01_Scale_Factor_X,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_01_Scale_Factor_Y,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Scale_Size_X,                SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_01_Scale_Size_Y,                SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //CONVERT
        //Color 2 Mono
        disconnect(ui->comboBox_02_Color2Mono_Reduction,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //Color
        disconnect(ui->comboBox_02_Color_Direction_Left,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_02_Color_Direction_Top,        SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_BGR_RGB,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_Grey_BGR,          SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_Grey_RGB,          SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_HSL_BGR,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_HSL_RGB,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_HSV_BGR,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_HSV_RGB,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_Lab_BGR,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_Lab_RGB,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_Luv_BGR,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_Luv_RGB,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_RGB_BGR,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_RGB_RGB,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_XYZ_BGR,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_XYZ_RGB,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_YCrCb_BGR,         SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_02_Color_YCrCb_RGB,         SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //Depth
        disconnect(ui->comboBox_02_Depth_Norm,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_02_Depth_Type,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_02_Depth_Maximum,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_02_Depth_Minimum,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Merge
        disconnect(ui->spinBox_02_Merge_Channels,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_02_Merge_Ch0,                  SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_02_Merge_Ch1,                  SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_02_Merge_Ch2,                  SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_02_Merge_Ch3,                  SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //Split
        disconnect(ui->spinBox_02_Split_Channel,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Combi
        disconnect(ui->comboBox_02_Combi_Type,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //angle to color
        disconnect(ui->spinBox_02_Angle2Color_S,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_02_Angle2Color_V,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //ELEMENTAL
        //Threshold
        disconnect(ui->comboBox_03_Thres_Type,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_03_Thres_Max_Value_Out,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_03_Thres_Output_Mode,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_03_Thres_Thres_Value_Abs,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->horizontalSlider_03_Thres_Abs_Thres_Value,SIGNAL(valueChanged(int)),        this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_03_Thres_Rel_Base,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_03_Thres_Rel_Thres_Rel,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->horizontalSlider_03_Thres_Rel_Thresh_Rel,SIGNAL(valueChanged(int)),         this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_03_Thres_Rel_Thresh_Abs,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_03_Thres_Adapt_Type,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_03_Thres_Adapt_Offset,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_03_Thres_Mask_Size,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_03_Thres_RankHysteresis_Radius,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_03_Thres_RankHysteresis_Quantil,           SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_03_Thres_RankHysteresis_ThresIndicator,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_03_Thres_RankHysteresis_ThresHysteresis,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Labeling
        disconnect(ui->comboBox_03_Labeling_Connectivity,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_03_Labeling_Depth,             SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_03_Labeling_Type,              SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //Color Grab
        disconnect(ui->comboBox_03_GrabColor_ColorSpace,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_03_GrabColor_Output,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_03_GrabColor_Ch1_Min,           SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_03_GrabColor_Ch2_Min,           SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_03_GrabColor_Ch3_Min,           SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_03_GrabColor_Ch1_Max,           SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_03_GrabColor_Ch2_Max,           SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_03_GrabColor_Ch3_Max,           SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //FILTER
        disconnect(ui->comboBox_04_Border_Type,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_04_Force_8bit,                 SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //Blur
        disconnect(ui->comboBox_04_Blur_Depth,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_04_Blur_Type,                  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_Blur_Size,                   SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_Blur_Size_X,                 SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_Blur_Size_Y,                 SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Blur_Sigma_X,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Blur_Sigma_Y,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_04_Blur_Normalized,            SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //edge
        disconnect(ui->comboBox_04_Edge_Depth,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_04_Edge_Type,                  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_Edge_dX,                     SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_Edge_dY,                     SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_Edge_Size,                   SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Edge_Delta,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Edge_Scale,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_Edge_Thresh_Low,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_Edge_Thresh_High,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_04_Edge_L2_Gradient,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //Special
        disconnect(ui->comboBox_04_Special_Depth,              SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_04_Special_Type,               SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_Special_Diameter,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_Special_Size_X,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_Special_Size_Y,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Special_Delta,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Special_Gamma,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Special_Lambda,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Special_Psi,           SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Special_Sigma,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Special_Sigma_Color,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Special_Sigma_Space,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Special_Theta,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Eilenstein
        disconnect(ui->comboBox_04_Eilenstein_Comparator,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_Eilenstein_Size_X,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_Eilenstein_Size_Y,               SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_Delta,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_04_Eilenstein_Normalized,          SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_04_Eilenstein_Type,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_04_Eilenstein_PixelMask,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_04_Eilenstein_PixelCenter,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_04_Eilenstein_Response,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_PixelMask_a,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_PixelMask_b,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_PixelMask_c,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_PixelMask_d,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_PixelMask_e,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_PixelMask_f,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_PixelMask_nan,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_PixelMask_inf,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_PixelCenter_a,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_PixelCenter_b,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_PixelCenter_c,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_PixelCenter_d,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_PixelCenter_e,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_PixelCenter_f,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_PixelCenter_nan,SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Eilenstein_PixelCenter_inf,SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Function
        disconnect(ui->checkBox_04_Function_OnlyNonZero,       SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_04_Function_f1_CenterImage,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_04_Function_f2_F1Mask,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_04_Function_f3_vF2,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_04_Function_f4_CenterF3,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f1_a,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f1_b,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f1_c,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f1_d,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f1_e,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f1_f,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f1_nan,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f1_inf,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f2_a,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f2_b,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f2_c,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f2_d,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f2_e,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f2_f,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f2_nan,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f2_inf,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f4_a,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f4_b,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f4_c,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f4_d,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f4_e,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f4_f,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f4_nan,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Function_f4_inf,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Rank Order
        disconnect(ui->doubleSpinBox_04_RankOrder_Quantil,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //disconnect(ui->comboBox_04_RankOrder_MaskType,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_RankOrder_Radius,      SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_RankOrder_Size_x,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_RankOrder_Size_y,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Statistic filter
        disconnect(ui->comboBox_04_Statistic_Stat,             SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_04_Statistic_MaskType,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_04_Statistic_Radius,      SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_Statistic_Size_x,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_04_Statistic_Size_y,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //MORPHOLOGY
        //Elemental
        disconnect(ui->comboBox_05_Elem_Border_Type,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_05_Elem_Elem_Type,             SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_05_Elem_Morph_Type,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_05_Elem_Elem_Size_X,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_05_Elem_Elem_Size_Y,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_05_Elem_Iterations,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Min/Max Gil
        disconnect(ui->comboBox_05_MinMaxGil_MinMax,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_05_MinMaxGil_SizeX,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_05_MinMaxGil_SizeY,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Reconstruct
        disconnect(ui->doubleSpinBox_05_Reconstruction_Quantil,SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Local Maxima
        disconnect(ui->spinBox_05_LocalMaxima_Size_X,          SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_05_LocalMaxima_Size_Y,          SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //MATH
        //1 Image simple
        disconnect(ui->comboBox_06_1Img_Type,                  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_1Img_Arg,              SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //2 Images simple
        disconnect(ui->comboBox_06_2Img_Comparator,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_06_2Img_Type,                  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2Img_Scale,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2Img_Weight_1,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2Img_Weight_2,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2Img_Weight_Sum,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //2 Image Function
        disconnect(ui->comboBox_06_2ImgFunction_Function,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_a,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_b,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_c,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_d,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_e,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_f,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_nan,      SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_inf,      SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_06_2ImgFunction_Force_8bit,    SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //Function Complex
        disconnect(ui->comboBox_06_2ImgFunction_Complex_Function,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_Complex_sx,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_Complex_ox,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_Complex_sy,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_Complex_oy,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_Complex_a,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_Complex_b,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_Complex_c,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_Complex_d,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_Complex_e,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_Complex_f,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_Complex_nan,      SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_2ImgFunction_Complex_inf,      SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //3 Image simple
        disconnect(ui->comboBox_06_3Img_Type,                  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_3Img_Value,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_06_3Img_Value,                 SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //4 Image simple
        disconnect(ui->comboBox_06_4Img_Type,                  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_06_4Img_Value,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_06_4Img_Value,                 SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //TRANSFORMATION
        //Distance
        disconnect(ui->comboBox_07_Dist_Metric,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_07_Dist_Precision,             SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //Watershade
        disconnect(ui->comboBox_07_Watershed_Connectivity,                      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_07_Watershed_Auto,                              SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_07_Watershed_8bit,                              SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_07_Watershed_InclNonSeed,                       SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_07_Watershed_ExclBorder,                        SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_07_WatershedCustom_Flood,                       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_07_WatershedCustom_Marker,                      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_07_WatershedCustom_Mask,                        SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_07_WatershedCustom_ExcludeBorder,               SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_07_WatershedCustom_IncludeNonSeed,              SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_07_WatershedCustom_DrawWatershed,               SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_07_WatershedCustom_DrawWatershed_Neighborhood,  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_07_WatershedCustom_Flood_GaussSigma,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_07_WatershedCustom_Mask_Thres,             SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_07_WatershedCustom_Flood_GaussSize,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_07_WatershedCustom_Flood_Morph_Size,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_07_WatershedCustom_Marker_LabelNeighborhood,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_07_WatershedCustom_Flood_Morph_Elem,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //Fourier
        disconnect(ui->checkBox_07_Fourier_Invers,             SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_07_Fourier_ForceFFT,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_07_Fourier_Output_Scale,       SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_07_Fourier_Output_no_f0,       SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_07_Fourier_Input_Complex,      SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_07_Fourier_Output_Centered,    SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_07_Fourier_Output_RealOnly,    SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_07_Fourier_Output_ComplexMode, SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //FEATURE
        //Value
        disconnect(ui->comboBox_08_FeatVal_Feature,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_FeatVal_Connectivity,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //Value Context
        disconnect(ui->comboBox_08_FeatContextVal_Connectivity,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_FeatContextVal_DistPt1,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_FeatContextVal_DistPt2,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_FeatContextVal_Feat,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_FeatContextVal_Stat,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_FeatContextVal_DistMin,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_FeatContextVal_DistMax,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_FeatContextSelect_Connectivity, SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_FeatContextSelect_DistPt1,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_FeatContextSelect_DistPt2,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_FeatContextSelect_Feat,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_FeatContextSelect_Stat,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_FeatContextSelect_DistMin, SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_FeatContextSelect_DistMax, SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_FeatContextSelect_ThresMin,SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_FeatContextSelect_ThresMax,SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Select
        disconnect(ui->comboBox_08_Select_Type,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_Select_Connectivity,        SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_Select_Min,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_Select_Max,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //connect
        disconnect(ui->comboBox_08_Connect_DistPt1,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_Connect_DistPt2,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_Connect_Feat1,              SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_Connect_Feat2,              SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_Connect_Cond,               SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_Connect_ConnectType,        SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_08_Connect_Thickness,           SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_Connect_DistMin,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_Connect_DistMax,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_Connect_Cond_a,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_Connect_Cond_b,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_Connect_Cond_c,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_Connect_Cond_d,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_Connect_Cond_e,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_Connect_Cond_f,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_Connect_Cond_g,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_Connect_Cond_h,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //reduce
        disconnect(ui->comboBox_08_Reduce_Type,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_08_Reduce_Thickness,            SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_08_Reduce_Value,                SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_Reduce_Connectivity,        SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //visualize
        disconnect(ui->comboBox_08_Visualize_Feature,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_Visualize_Connectivity,     SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_Visualize_Scale,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_08_Visualize_Thickness,         SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Value Stat
        disconnect(ui->comboBox_08_ValueStat_Connectivity,     SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_ValueStat_Stat,             SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //value stat select
        disconnect(ui->comboBox_08_ValueStatSelect_Connectivity,   SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_08_ValueStatSelect_Stat,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_ValueStatSelect_Min,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_08_ValueStatSelect_Max,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //OTHER
        //gamma spread
        disconnect(ui->doubleSpinBox_09_GammaSpread_Gamma,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_GammaSpread_InMin,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_GammaSpread_InMax,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_GammaSpread_OutMin,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_GammaSpread_OutMax,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_09_GammaSpread_Force8bit,      SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //label numbers
        disconnect(ui->spinBox_09_LabelNo_Thickness,           SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_LabelNo_Scale,         SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_09_LabelNo_Position,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //motion field
        disconnect(ui->spinBox_09_MotionField_SizeSpace,       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_09_MotionField_SizeTime,        SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //class border kNN
        disconnect(ui->spinBox_09_kNN_n,                       SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //HDR
        disconnect(ui->comboBox_09_HDR_Dim,                    SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_09_HDR_ProjectStat,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_09_HDR_Project,                SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_09_HDR_Thresh,                 SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_HDR_Exposure_Min,      SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_HDR_Exposure_Factor,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_HDR_Thresh_Low,        SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_HDR_Thresh_High,       SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Relation Stat
        disconnect(ui->comboBox_09_RelationStat_StatDistance,  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_09_RelationStat_StatAngle,     SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_09_RelationStat_Distance,   SIGNAL(clicked()),                  this,   SLOT(Update_Img_Proc()));
        disconnect(ui->radioButton_09_RelationStat_Angle,      SIGNAL(clicked()),                  this,   SLOT(Update_Img_Proc()));
        //Zernike Stack
        disconnect(ui->spinBox_09_ZernikeStack_Radius,         SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_09_ZernikeStack_J,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Radiometric Stereo
        disconnect(ui->comboBox_09_RadiometricStereo_OutMode,  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_RadiometricStereo_X1,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_RadiometricStereo_X2,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_RadiometricStereo_X3,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_RadiometricStereo_X4,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_RadiometricStereo_Y1,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_RadiometricStereo_Y2,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_RadiometricStereo_Y3,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_RadiometricStereo_Y4,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_RadiometricStereo_Z1,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_RadiometricStereo_Z2,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_RadiometricStereo_Z3,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_RadiometricStereo_Z4,  SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        //Michelson Interferometer
        disconnect(ui->spinBox_09_Michelson_Scene_Size_X,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_09_Michelson_Scene_Size_Y,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_09_Michelson_Scene_Size_Z,              SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_09_Michelson_Scale_px,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_Michelson_Scale_um,            SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_Michelson_Wavelength,          SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_Michelson_Source_distance,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_Michelson_Detector_distance,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_Michelson_Mirror1_distance,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_Michelson_Mirror2_distance,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_Michelson_Mirror1_angle_x,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_Michelson_Mirror1_angle_y,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_Michelson_Mirror2_angle_x,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_09_Michelson_Mirror2_angle_y,     SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_09_Michelson_Beam_atSO_SO,             SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_09_Michelson_Beam_atSO_M1_SO,          SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_09_Michelson_Beam_atSO_SP_M2_SP_SO,       SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_09_Michelson_Beam_atM1_SO,             SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_09_Michelson_Beam_atM1_M1_SO,          SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_09_Michelson_Beam_atM2_SP_SO,          SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_09_Michelson_Beam_atM2_M2_SP_SO,       SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_09_Michelson_Beam_atDE_SP_M1_SO,       SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_09_Michelson_Beam_atDE_M2_SP_SO,       SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_09_Michelson_Show_IorE,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        //DIMENSION
        //Pick
        disconnect(ui->checkBox_10_Pick_X,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_10_Pick_Y,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_10_Pick_Z,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_10_Pick_T,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_10_Pick_S,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_10_Pick_P,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Pick_X,                      SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Pick_Y,                      SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Pick_Z,                      SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Pick_T,                      SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Pick_S,                      SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Pick_P,                      SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Crop
        disconnect(ui->checkBox_10_Crop_X,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_10_Crop_Y,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_10_Crop_Z,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_10_Crop_T,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_10_Crop_S,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_10_Crop_P,                     SIGNAL(stateChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Crop_Min_X,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Crop_Min_Y,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Crop_Min_Z,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Crop_Min_T,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Crop_Min_S,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Crop_Min_P,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Crop_Max_X,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Crop_Max_Y,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Crop_Max_Z,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Crop_Max_S,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Crop_Max_T,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Crop_Max_P,                  SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Project
        disconnect(ui->comboBox_10_Project_Dimension,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_10_Project_Stat,               SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->checkBox_10_Project_8bit,               SIGNAL(clicked(bool)),              this,   SLOT(Update_Img_Proc()));
        //Deserialise
        disconnect(ui->comboBox_10_Deserialise_Dimension_In,   SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->comboBox_10_Deserialise_Dimension_Out,  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Deserialise_Spacing,         SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Pages2Color
        disconnect(ui->spinBox_10_Page2Color_R,                SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Page2Color_G,                SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        disconnect(ui->spinBox_10_Page2Color_B,                SIGNAL(valueChanged(int)),          this,   SLOT(Update_Img_Proc()));
        //Stitching
        disconnect(ui->comboBox_10_Stitching_Mode,             SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_10_Stitching_Border_R,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_10_Stitching_Border_B,    SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_10_Stitching_Overlap_R,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
        disconnect(ui->doubleSpinBox_10_Stitching_Overlap_B,   SIGNAL(valueChanged(double)),       this,   SLOT(Update_Img_Proc()));
    }
}

void D_StepWindow::Connect_OtherSteps()
{
    for(size_t s = 1; s < pSteps->size(); s++)
    {
        //viewed plane pos
        connect(this,               SIGNAL(ViewPlanePosChanged(vector<int>)),           (*pSteps)[s],       SLOT(set_ViewPlanePos(vector<int>)));
        connect((*pSteps)[s],       SIGNAL(ViewPlanePosChanged(vector<int>)),           this,               SLOT(set_ViewPlanePos(vector<int>)));

        //zoom
        connect(this,               SIGNAL(ViewZoomChanged(double,double,double,int)),   (*pSteps)[s],       SLOT(set_ViewZoom(double,double,double,int)));
        connect((*pSteps)[s],       SIGNAL(ViewZoomChanged(double,double,double,int)),   this,               SLOT(set_ViewZoom(double,double,double,int)));
    }
}

void D_StepWindow::Activate_Makro()
{
    //Version 1_6 beta (15.2.19): moved to main window
}

void D_StepWindow::CO_Depth_Set_Range(int prec, double min, double max)
{
    ui->doubleSpinBox_02_Depth_Minimum->setDecimals(prec);
    ui->doubleSpinBox_02_Depth_Minimum->setMinimum(min);
    ui->doubleSpinBox_02_Depth_Minimum->setMaximum(max - 1.0);
    ui->doubleSpinBox_02_Depth_Minimum->setValue(min);
    ui->doubleSpinBox_02_Depth_Maximum->setDecimals(prec);
    ui->doubleSpinBox_02_Depth_Maximum->setMinimum(min + 1.0);
    ui->doubleSpinBox_02_Depth_Maximum->setMaximum(max);
    ui->doubleSpinBox_02_Depth_Maximum->setValue(max);
}

void D_StepWindow::FI_General_Adapt_Ui(int index)
{
    ui->checkBox_04_Force_8bit->setEnabled(index == c_sT_FI_FUNCTION);
}

void D_StepWindow::FI_Blur_Adapt_Ui(int index)
{
    ui->label_04_Blur_Size->setVisible(false);
    ui->spinBox_04_Blur_Size->setVisible(false);

    ui->label_04_Blur_Size_XY->setVisible(false);
    ui->spinBox_04_Blur_Size_X->setVisible(false);
    ui->spinBox_04_Blur_Size_Y->setVisible(false);

    ui->label_04_Blur_Sigma_XY->setVisible(false);
    ui->doubleSpinBox_04_Blur_Sigma_X->setVisible(false);
    ui->doubleSpinBox_04_Blur_Sigma_Y->setVisible(false);

    ui->label_04_Border_Type->setEnabled(false);
    ui->comboBox_04_Border_Type->setEnabled(false);

    ui->label_04_Blur_Depth->setVisible(false);
    ui->comboBox_04_Blur_Depth->setVisible(false);

    ui->label_04_Blur_Normalized->setVisible(false);
    ui->checkBox_04_Blur_Normalized->setVisible(false);


    switch (index) {

    case c_ssT_FI_BLUR_MEAN:
    case c_ssT_FI_BLUR_RMS:
    {
        ui->label_04_Blur_Size_XY->setVisible(true);
        ui->spinBox_04_Blur_Size_X->setVisible(true);
        ui->spinBox_04_Blur_Size_Y->setVisible(true);

        ui->label_04_Border_Type->setEnabled(true);
        ui->comboBox_04_Border_Type->setEnabled(true);

        ui->label_04_Blur_Depth->setVisible(true);
        ui->comboBox_04_Blur_Depth->setVisible(true);

        ui->label_04_Blur_Normalized->setVisible(true);
        ui->checkBox_04_Blur_Normalized->setVisible(true);
    }
        break;

    case c_ssT_FI_BLUR_GAUSS:
    {
        ui->label_04_Blur_Size_XY->setVisible(true);
        ui->spinBox_04_Blur_Size_X->setVisible(true);
        ui->spinBox_04_Blur_Size_Y->setVisible(true);

        ui->label_04_Blur_Sigma_XY->setVisible(true);
        ui->doubleSpinBox_04_Blur_Sigma_X->setVisible(true);
        ui->doubleSpinBox_04_Blur_Sigma_Y->setVisible(true);

        ui->label_04_Border_Type->setEnabled(true);
        ui->comboBox_04_Border_Type->setEnabled(true);
    }
        break;

    case c_ssT_FI_BLUR_MEDIAN_BOX:
    {
        ui->label_04_Blur_Size->setVisible(true);
        ui->spinBox_04_Blur_Size->setVisible(true);
    }
        break;

    case c_ssT_FI_BLUR_MEDIAN_CUSTOM:
        break;

    default:
        return;
    }
}

void D_StepWindow::FI_Edge_Adapt_Ui(int index)
{
    ui->label_04_Edge_Size->setEnabled(false);
    ui->spinBox_04_Edge_Size->setEnabled(false);

    ui->label_04_Edge_dXdY->setEnabled(false);
    ui->spinBox_04_Edge_dX->setEnabled(false);
    ui->spinBox_04_Edge_dY->setEnabled(false);

    ui->label_04_Edge_Scale->setEnabled(false);
    ui->label_04_Edge_Delta->setEnabled(false);
    ui->doubleSpinBox_04_Edge_Scale->setEnabled(false);
    ui->doubleSpinBox_04_Edge_Delta->setEnabled(false);

    ui->label_04_Edge_Thesh->setEnabled(false);
    ui->spinBox_04_Edge_Thresh_Low->setEnabled(false);
    ui->spinBox_04_Edge_Thresh_High->setEnabled(false);

    ui->label_04_Edge_Options->setEnabled(false);
    ui->checkBox_04_Edge_L2_Gradient->setEnabled(false);

    ui->label_04_Edge_Depth->setEnabled(false);
    ui->comboBox_04_Edge_Depth->setEnabled(false);

    switch (index) {

    case 0://Laplace
        ui->label_04_Edge_Size->setEnabled(true);
        ui->spinBox_04_Edge_Size->setEnabled(true);

        ui->label_04_Edge_Scale->setEnabled(true);
        ui->label_04_Edge_Delta->setEnabled(true);
        ui->doubleSpinBox_04_Edge_Scale->setEnabled(true);
        ui->doubleSpinBox_04_Edge_Delta->setEnabled(true);
        break;

    case 1://Sobel
        ui->label_04_Edge_Size->setEnabled(true);
        ui->spinBox_04_Edge_Size->setEnabled(true);

        ui->label_04_Edge_dXdY->setEnabled(true);
        ui->spinBox_04_Edge_dX->setEnabled(true);
        ui->spinBox_04_Edge_dY->setEnabled(true);

        ui->label_04_Edge_Scale->setEnabled(true);
        ui->label_04_Edge_Delta->setEnabled(true);
        ui->doubleSpinBox_04_Edge_Scale->setEnabled(true);
        ui->doubleSpinBox_04_Edge_Delta->setEnabled(true);
        break;

    case 3://Canny
        ui->label_04_Edge_Size->setEnabled(true);
        ui->spinBox_04_Edge_Size->setEnabled(true);

        ui->label_04_Edge_Thesh->setEnabled(true);
        ui->spinBox_04_Edge_Thresh_Low->setEnabled(true);
        ui->spinBox_04_Edge_Thresh_High->setEnabled(true);

        ui->label_04_Edge_Options->setEnabled(true);
        ui->checkBox_04_Edge_L2_Gradient->setEnabled(true);
        break;

    default:
        break;
    }
}

void D_StepWindow::FI_Spec_Adapt_Ui(int index)
{
    bool bil = (index == 0);
    bool eil = (index == 2);

    ui->label_04_Special_Diameter->setVisible(bil);
    ui->spinBox_04_Special_Diameter->setVisible(bil);

    ui->label_04_Special_Size_XY->setVisible(!bil);
    ui->spinBox_04_Special_Size_X->setVisible(!bil);
    ui->spinBox_04_Special_Size_Y->setVisible(!bil);

    ui->label_04_Special_Depth->setVisible(!bil || !eil);
    ui->comboBox_04_Special_Depth->setVisible(!bil || !eil);
}

void D_StepWindow::FI_Function_RandomAll()
{
    FI_Func_all_random = true;
    FI_Function_RandomFunction();
    FI_Function_RandomParameters();
    FI_Func_all_random = false;

    if(ui->action_Autoupdate_ImgProc_on_Settings->isChecked())
        Update_Img_Proc();
}

void D_StepWindow::FI_Function_RandomFunction()
{
    bool auto_update = ui->action_Autoupdate_ImgProc_on_Settings->isChecked();
    Connect_ImgProcSettings_2_UpdateImgProc(false);

    //seed random
    mt19937 rng_seeded(time(NULL));

    //rng distributions
    uniform_int_distribution<int> gen_UniInt_2D_to_1D(0, c_MATH_2D_TO_1D_NUMBER_OF - 1);
    uniform_int_distribution<int> gen_UniInt_ND_to_1D(0, c_STAT_NUMBER_OF_STATS - 1);

    //randomize functions
    ui->comboBox_04_Function_f1_CenterImage->setCurrentIndex(gen_UniInt_2D_to_1D(rng_seeded));
    ui->comboBox_04_Function_f2_F1Mask->setCurrentIndex(gen_UniInt_2D_to_1D(rng_seeded));
    ui->comboBox_04_Function_f3_vF2->setCurrentIndex(gen_UniInt_ND_to_1D(rng_seeded));
    ui->comboBox_04_Function_f4_CenterF3->setCurrentIndex(gen_UniInt_2D_to_1D(rng_seeded));

    Connect_ImgProcSettings_2_UpdateImgProc(auto_update);
    if(auto_update && !FI_Func_all_random)
        Update_Img_Proc();
}

void D_StepWindow::FI_Function_RandomParameters()
{
    bool auto_update = ui->action_Autoupdate_ImgProc_on_Settings->isChecked();
    Connect_ImgProcSettings_2_UpdateImgProc(false);

    //seed random
    mt19937 rng_seeded(time(NULL));

    //rng distributions
    normal_distribution<double> gen_scale(0, 3);
    normal_distribution<double> gen_offset(0, 128);
    normal_distribution<double> gen_other(0, 128);

    //randomize parameters
    //f1
    ui->doubleSpinBox_04_Function_f1_a->setValue(gen_scale(rng_seeded));
    ui->doubleSpinBox_04_Function_f1_b->setValue(gen_offset(rng_seeded));
    ui->doubleSpinBox_04_Function_f1_c->setValue(gen_scale(rng_seeded));
    ui->doubleSpinBox_04_Function_f1_d->setValue(gen_offset(rng_seeded));
    ui->doubleSpinBox_04_Function_f1_e->setValue(gen_other(rng_seeded));
    ui->doubleSpinBox_04_Function_f1_f->setValue(gen_other(rng_seeded));
    ui->doubleSpinBox_04_Function_f1_nan->setValue(gen_other(rng_seeded));
    ui->doubleSpinBox_04_Function_f1_inf->setValue(gen_other(rng_seeded));
    //f2
    ui->doubleSpinBox_04_Function_f2_a->setValue(gen_scale(rng_seeded));
    ui->doubleSpinBox_04_Function_f2_b->setValue(gen_offset(rng_seeded));
    ui->doubleSpinBox_04_Function_f2_c->setValue(gen_scale(rng_seeded));
    ui->doubleSpinBox_04_Function_f2_d->setValue(gen_offset(rng_seeded));
    ui->doubleSpinBox_04_Function_f2_e->setValue(gen_other(rng_seeded));
    ui->doubleSpinBox_04_Function_f2_f->setValue(gen_other(rng_seeded));
    ui->doubleSpinBox_04_Function_f2_nan->setValue(gen_other(rng_seeded));
    ui->doubleSpinBox_04_Function_f2_inf->setValue(gen_other(rng_seeded));
    //f4
    ui->doubleSpinBox_04_Function_f4_a->setValue(gen_scale(rng_seeded));
    ui->doubleSpinBox_04_Function_f4_b->setValue(gen_offset(rng_seeded));
    ui->doubleSpinBox_04_Function_f4_c->setValue(gen_scale(rng_seeded));
    ui->doubleSpinBox_04_Function_f4_d->setValue(gen_offset(rng_seeded));
    ui->doubleSpinBox_04_Function_f4_e->setValue(gen_other(rng_seeded));
    ui->doubleSpinBox_04_Function_f4_f->setValue(gen_other(rng_seeded));
    ui->doubleSpinBox_04_Function_f4_nan->setValue(gen_other(rng_seeded));
    ui->doubleSpinBox_04_Function_f4_inf->setValue(gen_other(rng_seeded));

    Connect_ImgProcSettings_2_UpdateImgProc(auto_update);
    if(auto_update && !FI_Func_all_random)
        Update_Img_Proc();
}

void D_StepWindow::MA_1Img_Adapt_Ui(int index)
{
    bool arg_needed     = true;
    unsigned int digits = 6;
    QString arg_name    = "Argument";

    switch (index) {

    case 0://not
    case 6://root
    case 7://log
        arg_needed = false;
        arg_name = "-";
        break;

    case 1://add
        arg_name = "Summand";
        break;

    case 2://sub
        arg_name = "Subtrahend";
        break;

    case 3://mult
        arg_name = "Factor";
        break;

    case 4://div
        arg_name = "Divisor";
        break;

    case 5://pow
        arg_name = "Power";
        digits = 0;
        break;

    case 8://shift l
    case 9://shift r
        arg_name = "Shift";
        digits = 0;
        break;

    case 10://mod
        arg_name = "Divisor";
        digits = 0;
        break;

    default:
        break;
    }

    ui->doubleSpinBox_06_1Img_Arg->setEnabled(arg_needed);
    ui->doubleSpinBox_06_1Img_Arg->setDecimals(digits);
    ui->label_06_1Img_Arg->setEnabled(arg_needed);
    ui->label_06_1Img_Arg->setText(arg_name);
}

void D_StepWindow::MA_2Img_Adapt_Ui(int index)
{
    bool weighted_sum   = (index == 1);
    bool scale          = ((index == 5) || (index == 4));
    bool comp           = (index == 11);

    ui->label_06_2Img_Weight_Source->setVisible(weighted_sum);
    ui->label_06_2Img_Weight_Sum->setVisible(weighted_sum);
    ui->doubleSpinBox_06_2Img_Weight_1->setVisible(weighted_sum);
    ui->doubleSpinBox_06_2Img_Weight_2->setVisible(weighted_sum);
    ui->doubleSpinBox_06_2Img_Weight_Sum->setVisible(weighted_sum);

    ui->label_06_2Img_Scale->setVisible(scale);
    ui->doubleSpinBox_06_2Img_Scale->setVisible(scale);

    ui->label_06_2Img_Comparator->setVisible(comp);
    ui->comboBox_06_2Img_Comparator->setVisible(comp);
}

void D_StepWindow::AdaptUi_SourceNumber_ProcDims()
{
    bool proc_dim = false;
    bool source_1 = true;
    bool source_2 = false;
    bool source_3 = false;
    bool source_4 = false;

    switch (ui->comboBox_Type_Main->currentIndex()) {

    case c_T_SOURCE:    //-------------------------------------------------------
    {
        if(ui->comboBox_Type_00_Source->currentIndex() != c_sT_SO_DUPLICATE)
            source_1 = false;
    }
        break;

    case c_T_EDIT:    //-------------------------------------------------------
    {
        proc_dim = true;
    }
        break;

    case c_T_CONV:    //-------------------------------------------------------
    {
        if(ui->comboBox_Type_02_Convert->currentIndex() == c_sT_CO_MERGE)
        {
            source_1 = false;
            switch (ui->spinBox_02_Merge_Channels->value()) {
            case 4:     source_4 = true;
            case 3:     source_3 = true;
            case 2:     source_2 = true;
            case 1:     source_1 = true;
            default:    break;}
        }
    }
        break;

    case c_T_ELEM:    //-------------------------------------------------------
    {
        if(ui->comboBox_Type_03_Elemental->currentIndex() == c_sT_EL_SHADE_CORRECT)
            source_2 = true;

        if(ui->comboBox_Type_03_Elemental->currentIndex() == c_sT_EL_THRES)
        {
            if(ui->comboBox_03_Thres_Type->currentIndex() == 0)//otsu
                proc_dim = true;
            if(ui->comboBox_03_Thres_Type->currentIndex() == 3)//local adaptive
                proc_dim = true;
        }

        if(ui->comboBox_Type_03_Elemental->currentIndex() == c_sT_EL_LABEL)
            proc_dim = true;

        if(ui->comboBox_Type_03_Elemental->currentIndex() == c_sT_EL_FILLHOLES)
            proc_dim = true;
    }
        break;

    case c_T_FILT:    //-------------------------------------------------------
    {
        proc_dim = true;

        //qDebug() << "filter";
        if(ui->comboBox_Type_04_Filter->currentIndex() == c_sT_FI_BLUR)
            if(ui->comboBox_04_Blur_Type->currentIndex() == c_ssT_FI_BLUR_MEDIAN_CUSTOM)
            {
                qDebug() << "median custom";
                source_2 = true;
            }

        if(ui->comboBox_Type_04_Filter->currentIndex() == c_sT_FI_EILENSTEIN)
            if(ui->comboBox_04_Eilenstein_Type->currentIndex() == 1)//generalized
                source_2 = true;

        if(ui->comboBox_Type_04_Filter->currentIndex() == c_sT_FI_FUNCTION)
            source_2 = true;

        if(ui->comboBox_Type_04_Filter->currentIndex() == c_sT_FI_RANKORDER)
            if(ui->comboBox_04_RankOrder_MaskType->currentIndex() == c_MASK_MODE_CUSTOM)
                source_2 = true;

        if(ui->comboBox_Type_04_Filter->currentIndex() == c_sT_FI_STAT)
            if(ui->comboBox_04_Statistic_MaskType->currentIndex() == c_MASK_MODE_CUSTOM)
                source_2 = true;
    }
        break;

    case c_T_MORPH:    //-------------------------------------------------------
    {
        proc_dim = true;

        if(ui->comboBox_Type_05_Morphology->currentIndex() == c_sT_MO_RECON)
        {
            source_2 = true;
            source_3 = true;
        }
    }
        break;

    case c_T_MATH:    //-------------------------------------------------------
    {
        switch (ui->comboBox_Type_06_Math->currentIndex()) {

        case c_sT_MA_2IMG:
            source_2 = true;
            break;

        case c_sT_MA_2IMG_FUNCTION:
            source_2 = true;
            break;

        case c_sT_MA_2IMG_FUNCTION_COMPLEX:
            source_2 = true;
            break;

        case c_sT_MA_3IMG:
            source_2 = true;
            source_3 = true;
            break;

        case c_sT_MA_4IMG:
            source_2 = true;
            source_3 = true;
            source_4 = true;
            break;

        default:
            break;
        }
    }
        break;

    case c_T_TRANS:    //-------------------------------------------------------
    {
        proc_dim = true;

        if(ui->comboBox_Type_07_Transform->currentIndex() == c_sT_TR_WATERSHADE)
        {
            if(ui->comboBox_07_Watershed_Implementation->currentIndex() == 0)
            {
                if(ui->comboBox_07_WatershedCustom_Flood->currentIndex() == 0)
                    source_1 = true;
                if(ui->comboBox_07_WatershedCustom_Marker->currentIndex() == 0)
                    source_2 = true;
                if(ui->comboBox_07_WatershedCustom_Mask->currentIndex() == 0)
                    source_3 = true;
            }
            else
            {
                source_2 = true;
            }
        }

        if(ui->comboBox_Type_07_Transform->currentIndex() == c_sT_TR_FOURIER && ui->checkBox_07_Fourier_Input_Complex->isChecked())
            source_2 = true;
    }
        break;

    case c_T_FEATURE:    //-------------------------------------------------------
    {
        proc_dim = true;

        if(ui->comboBox_Type_08_Feature->currentIndex() == c_sT_FE_VALUESTAT || ui->comboBox_Type_08_Feature->currentIndex() == c_sT_FE_VALUESTAT_SELECT)
            source_2 = true;
    }
        break;

    case c_T_OTHER:    //-------------------------------------------------------
    {
        if(ui->comboBox_Type_09_Other->currentIndex() != c_sT_OT_GAMMA_SPREAD)
            proc_dim = true;

        if(ui->comboBox_Type_09_Other->currentIndex() == c_sT_OT_LABEL_NUMBER)
            source_2 = true;

        if(ui->comboBox_Type_09_Other->currentIndex() == c_sT_OT_CLASS_KNN)
        {
            proc_dim = true;
            source_2 = true;
        }

        if(ui->comboBox_Type_09_Other->currentIndex() == c_sT_OT_RADIOMETRIC_STEREO)
        {
            proc_dim = true;
            source_2 = true;
            source_3 = true;
        }
    }
        break;

    case c_T_DIM:    //-------------------------------------------------------
    {
        if(ui->comboBox_Type_10_Dimension->currentIndex() == c_sT_DI_STITCH_BORDER)
        {
            proc_dim = true;
            source_2 = true;
            source_3 = true;
            source_4 = true;
        }
    }
        break;

    default:
        break;
    }

    ui->label_Source_1->setEnabled(source_1);
    ui->label_Source_Type_1->setEnabled(source_1);
    ui->spinBox_Source_Pos_1->setEnabled(source_1);

    ui->label_Source_2->setEnabled(source_2);
    ui->label_Source_Type_2->setEnabled(source_2);
    ui->spinBox_Source_Pos_2->setEnabled(source_2);

    ui->label_Source_3->setEnabled(source_3);
    ui->label_Source_Type_3->setEnabled(source_3);
    ui->spinBox_Source_Pos_3->setEnabled(source_3);

    ui->label_Source_4->setEnabled(source_4);
    ui->label_Source_Type_4->setEnabled(source_4);
    ui->spinBox_Source_Pos_4->setEnabled(source_4);

    ui->groupBox_ProcDims->setEnabled(proc_dim);
}

void D_StepWindow::ViewerPlanePosChange_Block(bool block)
{
    ui->doubleSpinBox_View_Plane_X->blockSignals(block);
    ui->doubleSpinBox_View_Plane_Y->blockSignals(block);
    ui->doubleSpinBox_View_Plane_Z->blockSignals(block);
    ui->doubleSpinBox_View_Plane_T->blockSignals(block);
    ui->doubleSpinBox_View_Plane_S->blockSignals(block);
    ui->doubleSpinBox_View_Plane_P->blockSignals(block);
}

void D_StepWindow::Populate_CB_All()
{
    Populate_CB_LoadModes();
    Populate_CB_Dims();
    Populate_CB_Planes();
    Populate_CB_Features();
    Populate_CB_Geometrics();
    Populate_CB_Math();
    Populate_CB_Statistics();
    Populate_CB_Color2Mono();
    Populate_CB_CompDist();
    Populate_CB_VisTrafo();
    Populate_CB_3DViewer();
    Populate_CB_Other();
}

void D_StepWindow::Populate_CB_Single(QComboBox *CB, QStringList QSL, int init_index)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(init_index);
    CB->blockSignals(false);
}

void D_StepWindow::Populate_CB_Statistics()
{
    Populate_CB_Single(ui->comboBox_04_Eilenstein_Response,         QSL_StatList,       c_STAT_MEAN_ARITMETIC);
    Populate_CB_Single(ui->comboBox_04_Function_f3_vF2,             QSL_StatList,       c_STAT_MEAN_ARITMETIC);
    Populate_CB_Single(ui->comboBox_04_Statistic_Stat,              QSL_StatList,       c_STAT_MEAN_ARITMETIC);

    Populate_CB_Single(ui->comboBox_10_Project_Stat,                QSL_StatList,       c_STAT_MEAN_ARITMETIC);

    Populate_CB_Single(ui->comboBox_00_VideoStream_T1_Stat,         QSL_StatList,       c_STAT_MEAN_ARITMETIC);
    Populate_CB_Single(ui->comboBox_00_VideoStream_T2_Stat,         QSL_StatList,       c_STAT_MEAN_ARITMETIC);

    Populate_CB_Single(ui->comboBox_08_FeatContextVal_Stat,         QSL_StatList,       c_STAT_MAXIMUM);
    Populate_CB_Single(ui->comboBox_08_FeatContextSelect_Stat,      QSL_StatList,       c_STAT_MAXIMUM);

    Populate_CB_Single(ui->comboBox_09_HDR_ProjectStat,             QSL_StatList,       c_STAT_MEAN_ARITMETIC);

    Populate_CB_Single(ui->comboBox_09_RelationStat_StatDistance,   QSL_StatList,       c_STAT_MEAN_ARITMETIC);
    Populate_CB_Single(ui->comboBox_09_RelationStat_StatAngle,      QSL_StatListCirc,   c_STAT_CIRC_MEAN_ANG);

    Populate_CB_Single(ui->comboBox_08_ValueStat_Stat,              QSL_StatList,       c_STAT_MEAN_ARITMETIC);
    Populate_CB_Single(ui->comboBox_08_ValueStatSelect_Stat,        QSL_StatList,       c_STAT_MEAN_ARITMETIC);
}

void D_StepWindow::Populate_CB_Features()
{
    Populate_CB_Single(ui->comboBox_08_Select_Type,                 QSL_FeatureList,    c_FEAT_AREA);
    Populate_CB_Single(ui->comboBox_08_FeatVal_Feature,             QSL_FeatureList,    c_FEAT_AREA);
    Populate_CB_Single(ui->comboBox_08_Visualize_Feature,           QSL_FeatureList,    c_FEAT_AREA);
    Populate_CB_Single(ui->comboBox_08_FeatContextVal_Feat,         QSL_FeatureList,    c_FEAT_AREA);
    Populate_CB_Single(ui->comboBox_08_FeatContextSelect_Feat,      QSL_FeatureList,    c_FEAT_AREA);
    Populate_CB_Single(ui->comboBox_08_Connect_Feat1,               QSL_FeatureList,    c_FEAT_AREA);
    Populate_CB_Single(ui->comboBox_08_Connect_Feat2,               QSL_FeatureList,    c_FEAT_AREA);
}

void D_StepWindow::Populate_CB_Geometrics()
{
    Populate_CB_Single(ui->comboBox_08_Reduce_Type,                 QSL_GeometricsList, c_GEO_CONTOUR);
}

void D_StepWindow::Populate_CB_Math()
{
    Populate_CB_Single(ui->comboBox_00_Generate_ValueFunction_2D,           QSL_Math_2D_to_1D,          c_MATH_2D_TO_1D_X_times_Y);
    Populate_CB_Single(ui->comboBox_00_Generate_ValueFunction_2D_Complex,   QSL_Math_2D_to_1D_Complex,  c_MATH_2D_TO_1D_COMPLEX_X_iY);
    Populate_CB_Single(ui->comboBox_00_Generate_ValueFunction_6D,           QSL_Math_6D_to_1D,          c_MATH_6D_TO_1D_const_E);

    Populate_CB_Single(ui->comboBox_04_Eilenstein_PixelMask,        QSL_Math_2D_to_1D,  c_MATH_2D_TO_1D_X_times_Y);
    Populate_CB_Single(ui->comboBox_04_Eilenstein_PixelCenter,      QSL_Math_2D_to_1D,  c_MATH_2D_TO_1D_X_greater_Y);

    Populate_CB_Single(ui->comboBox_04_Function_f1_CenterImage,     QSL_Math_2D_to_1D,  c_MATH_2D_TO_1D_Y);
    Populate_CB_Single(ui->comboBox_04_Function_f2_F1Mask,          QSL_Math_2D_to_1D,  c_MATH_2D_TO_1D_X_times_Y);
    Populate_CB_Single(ui->comboBox_04_Function_f4_CenterF3,        QSL_Math_2D_to_1D,  c_MATH_2D_TO_1D_X);

    Populate_CB_Single(ui->comboBox_06_2ImgFunction_Function,           QSL_Math_2D_to_1D,          c_MATH_2D_TO_1D_X_plus_Y);
    Populate_CB_Single(ui->comboBox_06_2ImgFunction_Complex_Function,   QSL_Math_2D_to_1D_Complex,  c_MATH_2D_TO_1D_COMPLEX_X_PLUS_Y);

    Populate_CB_Single(ui->comboBox_00_VideoStream_CombiFunction,   QSL_Math_2D_to_1D,  c_MATH_2D_TO_1D_X_minus_Y_abs);

    Populate_CB_Single(ui->comboBox_08_Connect_Cond,                QSL_Conditions,     c_COND_GREATER);

    Populate_CB_Single(ui->comboBox_00_Random_Type,                 QSL_Random,         c_RAND_NORMAL);

    Populate_CB_Single(ui->comboBox_07_Fourier_Output_ComplexMode,  QSL_Complex2Real,   c_COMPLEX2REAL_ABS);
}

void D_StepWindow::Populate_CB_Planes()
{
    Populate_CB_Single(ui->comboBox_View_Plane,                     QSL_Planes,         c_PLANE_XY);
}

void D_StepWindow::Populate_CB_Dims()
{
    Populate_CB_Single(ui->comboBox_00_Load_Source_Dim_X,           QSL_DimIndices,     c_DIM_X);
    Populate_CB_Single(ui->comboBox_00_Load_Source_Dim_Y,           QSL_DimIndices,     c_DIM_Y);
    Populate_CB_Single(ui->comboBox_00_Load_Source_Dim_List,        QSL_DimIndices,     c_DIM_S);
    Populate_CB_Single(ui->comboBox_00_Load_Source_Dim_Pages,       QSL_DimIndices,     c_DIM_P);
    Populate_CB_Single(ui->comboBox_00_Load_Source_Dim_T,           QSL_DimIndices,     c_DIM_T);

    Populate_CB_Single(ui->comboBox_10_Project_Dimension,           QSL_DimIndices,     c_DIM_X);

    Populate_CB_Single(ui->comboBox_10_Deserialise_Dimension_In,    QSL_DimIndices,     c_DIM_P);
    Populate_CB_Single(ui->comboBox_10_Deserialise_Dimension_Out,   QSL_DimIndices,     c_DIM_Z);

    Populate_CB_Single(ui->comboBox_09_HDR_Dim,                     QSL_DimIndices,     c_DIM_S);
}

void D_StepWindow::Populate_CB_LoadModes()
{
    Populate_CB_Single(ui->comboBox_00_Load_Mode,                   QSL_LoadMode,       c_LOAD_MODE_FILE_IMAGE);
}

void D_StepWindow::Populate_CB_Color2Mono()
{
    Populate_CB_Single(ui->comboBox_02_Color2Mono_Reduction,        QSL_Color2Mono,     c_COL2MONO_GRAY);
}

void D_StepWindow::Populate_CB_CompDist()
{
    Populate_CB_Single(ui->comboBox_08_FeatContextVal_DistPt1,      QSL_CompDist,       c_COMPDIST_CONTOUR);
    Populate_CB_Single(ui->comboBox_08_FeatContextVal_DistPt2,      QSL_CompDist,       c_COMPDIST_CONTOUR);
    Populate_CB_Single(ui->comboBox_08_FeatContextSelect_DistPt1,   QSL_CompDist,       c_COMPDIST_CONTOUR);
    Populate_CB_Single(ui->comboBox_08_FeatContextSelect_DistPt2,   QSL_CompDist,       c_COMPDIST_CONTOUR);
    Populate_CB_Single(ui->comboBox_08_Connect_DistPt1,             QSL_CompDist,       c_COMPDIST_CONTOUR);
    Populate_CB_Single(ui->comboBox_08_Connect_DistPt2,             QSL_CompDist,       c_COMPDIST_CONTOUR);

    Populate_CB_Single(ui->comboBox_08_Connect_ConnectType,         QSL_ConnectPoints,  c_CONNECT_CLOSEST);
}

void D_StepWindow::Populate_CB_VisTrafo()
{
    Populate_CB_Single(ui->comboBox_View_Crop,                      QSL_VisTrafo_Crop,  c_VIS_TRAFO_CROP_DYNAMIC);
    Populate_CB_Single(ui->comboBox_View_Transform,                 QSL_VisTrafo,       c_VIS_TRAFO_LINEAR);
    Populate_CB_Single(ui->comboBox_View_Anchor,                    QSL_VisTrafo_Anchor,c_VIS_TRAFO_ANCHOR_DYNAMIC);
    Populate_CB_Single(ui->comboBox_View_Range,                     QSL_VisTrafo_Range, c_VIS_TRAFO_RANGE_DYNAMIC);
    Populate_CB_Single(ui->comboBox_FunctionView_Mode,              QSL_PLOT_SIMPLE,    c_PLOT_SIMPLE_LINE);

    Populate_CB_Single(ui->comboBox_View_Complex,                   QSL_Complex2Real_Short, c_COMPLEX2REAL_RE_IM);
}

void D_StepWindow::Populate_CB_3DViewer()
{
    Populate_CB_Single(ui->comboBox_3D_Axis_X,                      QSL_Viewer3D_Axis,          c_VIEWER_PLOT_3D_AXIS_IMG_X);
    Populate_CB_Single(ui->comboBox_3D_Axis_Y,                      QSL_Viewer3D_Axis,          c_VIEWER_PLOT_3D_AXIS_IMG_Y);
    Populate_CB_Single(ui->comboBox_3D_Axis_Z,                      QSL_Viewer3D_Axis,          c_VIEWER_PLOT_3D_AXIS_CHANNEL_0);
    Populate_CB_Single(ui->comboBox_3D_Axis_Z_Heightmap,            QSL_Viewer3D_Axis,          c_VIEWER_PLOT_3D_AXIS_CHANNEL_0);
    Populate_CB_Single(ui->comboBox_3D_Axis_V,                      QSL_Viewer3D_Axis,          c_VIEWER_PLOT_3D_AXIS_CHANNEL_0);
    Populate_CB_Single(ui->comboBox_3D_Axis_V_Heightmap,            QSL_Viewer3D_Axis,          c_VIEWER_PLOT_3D_AXIS_CHANNEL_0);

    Populate_CB_Single(ui->comboBox_3D_Mode,                        QSL_Viewer3D_Mode,          c_VIEWER_PLOT_3D_MODE_HEIGHTMAP);
    Populate_CB_Single(ui->comboBox_3D_Condition,                   QSL_Viewer3D_Condition,     c_VIEWER_PLOT_3D_CONDITION_NOT_ZERO);
    Populate_CB_Single(ui->comboBox_3D_ColorHandling,               QSL_Viewer3D_ValueHandling, c_VIEWER_PLOT_3D_VALUE_HANDLING_MONO);

    Populate_CB_Single(ui->comboBox_3D_TextureMode_Heightmap,       QSL_Viewer3D_Texture,       c_VIEWER_PLOT_3D_TEXTURE_HUE);
    Populate_CB_Single(ui->comboBox_3D_2dPlane_Heightmap,           QSL_Planes,                 c_PLANE_XY);
    Populate_CB_Single(ui->comboBox_3D_SurfaceMode,                 QSL_Viewer_3D_SurfaceMode,  c_VIEWER_PLOT_3D_SURFACE_MODE_SINGLE);
    Populate_CB_Single(ui->comboBox_3D_SurfaceDimension,            QSL_DimIndices,             c_DIM_S);

    Populate_CB_Single(ui->comboBox_3D_Marker,                      QSL_Marker_3D,              c_VIEWER_PLOT_3D_MARKER_POINT);
    Populate_CB_Single(ui->comboBox_3D_ShadowQuality,               QSL_ShadowQuality_3D,       c_VIEWER_PLOT_3D_SHADOW_LOW);
}

void D_StepWindow::Populate_CB_Other()
{
    Populate_CB_Single(ui->comboBox_09_RadiometricStereo_OutMode,   QSL_StereoOutput,   c_STEREO_NORMAL);
    Populate_CB_Single(ui->comboBox_04_Statistic_MaskType,          QSL_MaskMode,       c_MASK_MODE_CIRC);
    Populate_CB_Single(ui->comboBox_04_RankOrder_MaskType,          QSL_MaskMode,       c_MASK_MODE_CIRC);

    Populate_CB_Single(ui->comboBox_07_WatershedCustom_Flood,       QSL_WatershedFill,  c_WATERSHED_FILL_MASK_DIST_INV);
    Populate_CB_Single(ui->comboBox_07_WatershedCustom_Marker,      QSL_WatershedMarker,c_WATERSHED_MARKER_FILL_LOC_MIN);
    Populate_CB_Single(ui->comboBox_07_WatershedCustom_Mask,        QSL_WatershedMask,  c_WATERSHED_MASK_SOURCE_COPY);
}

void D_StepWindow::Test_Feature_Visualize()
{
    //set ui
    ui->comboBox_Type_Main->setCurrentIndex(c_T_FEATURE);
    ui->comboBox_Type_08_Feature->setCurrentIndex(c_sT_FE_VISUALIZE);
    Update_Img_Proc();

    //Get Save path
    QString QS_Dir_Save = QFileDialog::getExistingDirectory(
                this,
                tr("Get Save Directory"),
                pStore->dir_Test()->path());

    if(QS_Dir_Save == 0)
    {
        return;
    }
    else
    {
        QDir().mkdir(QS_Dir_Save);
        pStore->set_dir_Test(QS_Dir_Save);
    }

    //loop features and save image
    for(int f = 0; f < c_FEAT_NUMBER_OF_FEATS; f++)
    {
        ui->comboBox_08_Visualize_Feature->setCurrentIndex(f);
        Viewer.Save_Image(QS_Dir_Save + "/" + QString::number(f) + " - " +  QSL_FeatureList[f] + ".png");
    }
}

void D_StepWindow::Measure_SaveClick(int x, int y)
{
    Measure_P1 = Measure_P2;
    Measure_P2 = Point(x, y);
    Update_Image();
}

void D_StepWindow::Measure_LineDistance()
{
    int x1 = Measure_P1.x;
    int x2 = Measure_P2.x;
    int y1 = Measure_P1.y;
    int y2 = Measure_P2.y;

    cv::Mat MA_tmp_WithLine;
    ERR(D_Img_Proc::Normalize(
            &MA_tmp_WithLine,
            pStore->get_Adress(pos_Dest),
            NORM_MINMAX,
            CV_8U,
            0,
            191),
        "Measure_LineDistance",
        "Duplicate");

    ERR(D_Img_Proc::Draw_Line(
            &MA_tmp_WithLine,
            x1, y1, x2, y2,
            2,
            255),
        "Measure_LineDistance",
        "Draw_Line");

    Viewer.Update_Image(&MA_tmp_WithLine);//displayed until next update

    double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    QMessageBox::information(
                this,
                "Line Distacne",
                "Distance between last two left clicks: " + QString::number(dist) + "px");

    MA_tmp_WithLine.release();
}



void D_StepWindow::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_Stepwindow (" + QString::number(pos_Dest) + ")", func, detail);
}

D_VisDat_Slicing D_StepWindow::SlicingFromUi()
{
    D_VisDat_Slicing Slicing;
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        Slicing.set_proc_Dim(d, vCHB_ProcDims[d]->isChecked());

    return Slicing;
}

void D_StepWindow::on_spinBox_Source_Pos_1_valueChanged(int arg1)
{
    if(arg1 < pStore->size())
        pos_Source1 = arg1;
    else
        ui->spinBox_Source_Pos_1->setValue(pos_Source1);
}

void D_StepWindow::on_spinBox_Source_Pos_2_valueChanged(int arg1)
{
    if(arg1 < pStore->size())
        pos_Source2 = arg1;
    else
        ui->spinBox_Source_Pos_2->setValue(pos_Source2);
}

void D_StepWindow::on_spinBox_Source_Pos_3_valueChanged(int arg1)
{
    if(arg1 < pStore->size())
        pos_Source3 = arg1;
    else
        ui->spinBox_Source_Pos_3->setValue(pos_Source3);
}

void D_StepWindow::on_spinBox_Source_Pos_4_valueChanged(int arg1)
{
    if(arg1 < pStore->size())
        pos_Source4 = arg1;
    else
        ui->spinBox_Source_Pos_4->setValue(pos_Source4);
}

void D_StepWindow::on_comboBox_00_Load_Mode_currentIndexChanged(int index)
{
    switch (index) {

    case c_LOAD_MODE_FILE_IMAGE:
        ui->comboBox_00_Load_Source_Dim_X->setEnabled(true);
        ui->comboBox_00_Load_Source_Dim_Y->setEnabled(true);
        ui->comboBox_00_Load_Source_Dim_List->setEnabled(false);
        ui->comboBox_00_Load_Source_Dim_Pages->setEnabled(false);
        ui->comboBox_00_Load_Source_Dim_T->setEnabled(false);
        ui->checkBox_00_Load_Force8UC1->setEnabled(false);
        ui->pushButton_00_Load_Image->setText("Select Path");
        break;

    case c_LOAD_MODE_FILE_IMAGE_PAGED:
        ui->comboBox_00_Load_Source_Dim_X->setEnabled(true);
        ui->comboBox_00_Load_Source_Dim_Y->setEnabled(true);
        ui->comboBox_00_Load_Source_Dim_List->setEnabled(false);
        ui->comboBox_00_Load_Source_Dim_Pages->setEnabled(true);
        ui->comboBox_00_Load_Source_Dim_T->setEnabled(false);
        ui->checkBox_00_Load_Force8UC1->setEnabled(false);
        ui->pushButton_00_Load_Image->setText("Select Path");
        break;

    case c_LOAD_MODE_FILE_VIDEO:
        ui->comboBox_00_Load_Source_Dim_X->setEnabled(true);
        ui->comboBox_00_Load_Source_Dim_Y->setEnabled(true);
        ui->comboBox_00_Load_Source_Dim_List->setEnabled(false);
        ui->comboBox_00_Load_Source_Dim_Pages->setEnabled(false);
        ui->comboBox_00_Load_Source_Dim_T->setEnabled(true);
        ui->checkBox_00_Load_Force8UC1->setEnabled(true);
        ui->pushButton_00_Load_Image->setText("Select Path");
        break;

    case c_LOAD_MODE_FILELIST_IMAGE:
        ui->comboBox_00_Load_Source_Dim_X->setEnabled(true);
        ui->comboBox_00_Load_Source_Dim_Y->setEnabled(true);
        ui->comboBox_00_Load_Source_Dim_List->setEnabled(true);
        ui->comboBox_00_Load_Source_Dim_Pages->setEnabled(false);
        ui->comboBox_00_Load_Source_Dim_T->setEnabled(false);
        ui->checkBox_00_Load_Force8UC1->setEnabled(false);
        ui->pushButton_00_Load_Image->setText("Select Paths");
        break;

    case c_LOAD_MODE_FILELIST_IMAGE_PAGED:
        ui->comboBox_00_Load_Source_Dim_X->setEnabled(true);
        ui->comboBox_00_Load_Source_Dim_Y->setEnabled(true);
        ui->comboBox_00_Load_Source_Dim_List->setEnabled(true);
        ui->comboBox_00_Load_Source_Dim_Pages->setEnabled(true);
        ui->comboBox_00_Load_Source_Dim_T->setEnabled(false);
        ui->checkBox_00_Load_Force8UC1->setEnabled(false);
        ui->pushButton_00_Load_Image->setText("Select Paths");
        break;

    case c_LOAD_MODE_FILE_VISDAT:
        ui->comboBox_00_Load_Source_Dim_X->setEnabled(false);
        ui->comboBox_00_Load_Source_Dim_Y->setEnabled(false);
        ui->comboBox_00_Load_Source_Dim_List->setEnabled(false);
        ui->comboBox_00_Load_Source_Dim_Pages->setEnabled(false);
        ui->comboBox_00_Load_Source_Dim_T->setEnabled(false);
        ui->checkBox_00_Load_Force8UC1->setEnabled(false);
        ui->pushButton_00_Load_Image->setText("Select Path");
        break;

    default:
        break;
    }
}

void D_StepWindow::on_comboBox_02_Depth_Type_currentIndexChanged(int index)
{
    ui->doubleSpinBox_02_Depth_Minimum->blockSignals(true);
    ui->doubleSpinBox_02_Depth_Maximum->blockSignals(true);

    switch (index) {
    case 0:   CO_Depth_Set_Range(0,   0,            255);           break;
    case 1:   CO_Depth_Set_Range(0,   -128,         127);           break;
    case 2:   CO_Depth_Set_Range(0,   0,            65535);         break;
    case 3:   CO_Depth_Set_Range(0,   -32768,       32767);         break;
    case 4:   CO_Depth_Set_Range(0,   -2147483648,  2147483647);    break;
    case 5:   CO_Depth_Set_Range(7,   0.0,          1.0);           break;
    case 6:   CO_Depth_Set_Range(15,  0.0,          1.0);           break;
    default:                                                        return;}

    ui->doubleSpinBox_02_Depth_Minimum->blockSignals(false);
    ui->doubleSpinBox_02_Depth_Maximum->blockSignals(false);
}

void D_StepWindow::on_comboBox_Type_04_Filter_currentIndexChanged(int index)
{
    FI_General_Adapt_Ui(ui->comboBox_Type_04_Filter->currentIndex());

    if(index != c_sT_FI_BLUR)
    {
        ui->label_04_Border_Type->setEnabled(true);
        ui->comboBox_04_Border_Type->setEnabled(true);

        if(index == c_sT_FI_EILENSTEIN)
        {
            ui->label_04_Border_Type->setEnabled(false);
            ui->comboBox_04_Border_Type->setEnabled(false);
        }
    }
    else
        FI_Blur_Adapt_Ui(ui->comboBox_04_Blur_Type->currentIndex());
}

void D_StepWindow::on_spinBox_04_Edge_dX_valueChanged(int arg1)
{
    arg1;//useless
    if(ui->spinBox_04_Edge_dY->value() == 0)
        ui->spinBox_04_Edge_dY->setValue(1);
}

void D_StepWindow::on_spinBox_04_Edge_dY_valueChanged(int arg1)
{
    arg1;//useless
    if(ui->spinBox_04_Edge_dX->value() == 0)
        ui->spinBox_04_Edge_dX->setValue(1);
}

void D_StepWindow::on_tabWidget_Output_currentChanged(int index)
{
    switch (index) {
    case c_Out_Image_2D:    Viewer.Set_ViewerMode(c_VIEWER_MODE_IMG);   break;
    case c_Out_Image_3D:    Update_3DImage();                           break;
    case c_Out_Hist:        Update_Hist();                              break;
    case c_Out_Time:        Update_Times();                             break;
    case c_Out_Chain:                                                   break;
    case c_Out_Plot_2D:     Viewer.Set_ViewerMode(c_VIEWER_MODE_PLOT);  break;
    case c_Out_Plot_3D:     Update_3DPlot();                            break;
    default:                                                            return;}

    ui->groupBox_View_Plane->setEnabled(index != c_Out_Image_3D);
    ui->groupBox_View_Plane->setVisible(index != c_Out_Plot_3D);
    ui->groupBox_View_Contrast->setVisible(index != c_Out_Plot_3D);
}

void D_StepWindow::on_pushButton_00_Load_Image_clicked()
{
    switch (ui->comboBox_00_Load_Mode->currentIndex()) {

    case c_LOAD_MODE_FILE_IMAGE:
    {
        QString path_img = QFileDialog::getOpenFileName(
                    this,
                    tr("Load Image"),
                    pStore->dir_Load()->path(),
                    tr("Image Files (*.png *.jpg *.bmp *.tif *.tiff *.asc)"));
        if(path_img == 0)   return;

        FI_Load_File.setFile(path_img);
        pStore->set_dir_Load(path_img);
    }
        break;

    case c_LOAD_MODE_FILE_IMAGE_PAGED:
    {
        QString path_img = QFileDialog::getOpenFileName(
                    this,
                    tr("Load Image Paged"),
                    pStore->dir_Load()->path(),
                    tr("Paged Image Files (*.tif *.tiff)"));
        if(path_img == 0)   return;

        FI_Load_File.setFile(path_img);
        pStore->set_dir_Load(path_img);
    }
        break;

    case c_LOAD_MODE_FILE_VIDEO:
    {
        QString path_vid = QFileDialog::getOpenFileName(
                    this,
                    tr("Load Video"),
                    pStore->dir_Load()->path(),
                    tr("Video Files (*.avi *.mp4 *.mpg *.mkv *flv *.mpeg *.3gp)"));
        if(path_vid == 0)   return;

        FI_Load_File.setFile(path_vid);
        pStore->set_dir_Load(path_vid);
    }
        break;

    case c_LOAD_MODE_FILELIST_IMAGE:
    {
        QStringList paths_img = QFileDialog::getOpenFileNames(
                    this,
                    tr("Load Images"),
                    pStore->dir_Load()->path(),
                    tr("Image Files (*.png *.jpg *.bmp *.tif *.tiff *.asc)"));
        if(paths_img.empty())   return;

        FIL_Load_Files.clear();
        for(int i = 0; i < paths_img.size(); i++)
            FIL_Load_Files.append(QFileInfo(paths_img[i]));

        pStore->set_dir_Load(FIL_Load_Files.first().dir().absolutePath());
    }
        break;

    case c_LOAD_MODE_FILELIST_IMAGE_PAGED:
    {
        QStringList paths_img = QFileDialog::getOpenFileNames(
                    this,
                    tr("Load Images Paged"),
                    pStore->dir_Load()->path(),
                    tr("Paged Image Files (*.tif *.tiff)"));
        if(paths_img.empty())   return;

        FIL_Load_Files.clear();
        for(int i = 0; i < paths_img.size(); i++)
            FIL_Load_Files.append(QFileInfo(paths_img[i]));

        pStore->set_dir_Load(FIL_Load_Files.first().dir().absolutePath());
    }
        break;

    case c_LOAD_MODE_FILE_VISDAT:
    {
        QString path_img = QFileDialog::getOpenFileName(
                    this,
                    tr("Load VisDat"),
                    pStore->dir_Load()->path(),
                    tr("VisDat Files (*.visdat)"));
        if(path_img == 0)   return;

        FI_Load_File.setFile(path_img);
        pStore->set_dir_Load(path_img);
    }
        break;

    default:
        break;
    }
}

void D_StepWindow::on_pushButton_00_VideoStream_Browse_clicked()
{
    QString path_vid = QFileDialog::getOpenFileName(
                this,
                tr("Load Video"),
                pStore->dir_Load()->path(),
                tr("Video Files (*.avi *.mp4 *.mpg *.mkv *flv *.mpeg *)"));
    if(path_vid == 0)   return;


    FI_Load_File.setFile(path_vid);
    pStore->set_dir_Load(path_vid);
    ui->label_00_VideoStream_File->setText(path_vid);
}

void D_StepWindow::Scan_Examples_Dir()
{
    FIL_Examples.clear();
    ui->comboBox_00_Sample_Paths->blockSignals(true);
    ui->comboBox_00_Sample_Paths->clear();

    //find images
    QStringList QSL_Example_Images = pStore->dir_Examples()->entryList();
    for(int i = 0; i < QSL_Example_Images.size(); i++)
    {
        QFileInfo FI_Example(pStore->dir_Examples()->absolutePath() + "/" + QSL_Example_Images.at(i));
        QString suf =  FI_Example.suffix();

        if((suf == "asc") || (suf == "png") || (suf == "jpg") || (suf == "bmp") || (suf == "tif"))
        {
            FIL_Examples.append(FI_Example);
            ui->comboBox_00_Sample_Paths->addItem(FI_Example.baseName() + "." + suf);
        }
    }

    ui->comboBox_00_Sample_Paths->blockSignals(false);
    ui->label_00_Sample_Directory->setText(pStore->dir_Examples()->absolutePath());
}




void D_StepWindow::on_spinBox_02_Merge_Channels_valueChanged(int arg1)
{
    bool channels[4] = {false};

    switch (arg1) {
    case 4:     channels[3] = true;
    case 3:     channels[2] = true;
    case 2:     channels[1] = true;
    case 1:     channels[0] = true;
    default:    break;}

    ui->label_02_Merge_Ch0->setEnabled(channels[0]);
    ui->checkBox_02_Merge_Ch0->setEnabled(channels[0]);
    ui->label_02_Merge_Ch1->setEnabled(channels[1]);
    ui->checkBox_02_Merge_Ch1->setEnabled(channels[1]);
    ui->label_02_Merge_Ch2->setEnabled(channels[2]);
    ui->checkBox_02_Merge_Ch2->setEnabled(channels[2]);
    ui->label_02_Merge_Ch3->setEnabled(channels[3]);
    ui->checkBox_02_Merge_Ch3->setEnabled(channels[3]);
}

void D_StepWindow::on_checkBox_07_Watershed_Auto_stateChanged(int arg1)
{
    if(arg1)
    {
        ui->label_07_Watershed_Input_Desciption->setText("CV_8UC1, binary input");
        ui->label_07_Watershed_Markers_Desription->setText("CV_8UC1, binary marker");
    }
    else
    {
        ui->label_07_Watershed_Input_Desciption->setText("CV_8UC3, color input");
        ui->label_07_Watershed_Markers_Desription->setText("CV_32SC1, labeld marker");
    }

    ui->checkBox_07_Watershed_8bit->setEnabled(arg1);
    ui->checkBox_07_Watershed_ExclBorder->setEnabled(arg1);
    ui->checkBox_07_Watershed_InclNonSeed->setEnabled(arg1);
    ui->comboBox_07_Watershed_Connectivity->setEnabled(arg1);
}

void D_StepWindow::on_action_Change_Title_triggered(bool checked)
{
    if(!checked)
    {
        Update_Title();
        return;
    }

    bool ok;
    QS_AlternativeTitle = QInputDialog::getText(
                this,
                tr("Change title"),
                tr("Enter custom title:"),
                QLineEdit::Normal,
                tr("Example_Title"),
                &ok);

    if (!ok || QS_AlternativeTitle.isEmpty())
        ui->action_Change_Title->setChecked(false);

    Update_Title();
}

void D_StepWindow::on_pushButton_00_Sample_Select_Directory_clicked()
{
    QString ST_Dir = QFileDialog::getExistingDirectory(
                this,
                "Select folder with sample images",
                pStore->dir_Examples()->path());

    if(ST_Dir.isEmpty())
       return;

    pStore->set_dir_Examples(ST_Dir);
    Scan_Examples_Dir();
}

void D_StepWindow::on_comboBox_03_GrabColor_ColorSpace_currentIndexChanged(int index)
{
    switch (index) {

    case 0://BRG
        ui->label_03_GrabColor_Ch1->setText("Blue");
        ui->label_03_GrabColor_Ch2->setText("Green");
        ui->label_03_GrabColor_Ch3->setText("Red");
        break;

    case 1://XYZ
        ui->label_03_GrabColor_Ch1->setText("X(R)");
        ui->label_03_GrabColor_Ch2->setText("Y(G)");
        ui->label_03_GrabColor_Ch3->setText("Z(B)");
        break;

    case 2://YCrCb
        ui->label_03_GrabColor_Ch1->setText("Brightness");
        ui->label_03_GrabColor_Ch2->setText("Blue/Yellow");
        ui->label_03_GrabColor_Ch3->setText("Red/Green");
        break;

    case 3://HSV
        ui->label_03_GrabColor_Ch1->setText("Hue");
        ui->label_03_GrabColor_Ch2->setText("Saturation");
        ui->label_03_GrabColor_Ch3->setText("Value");
        break;

    case 4://Lab
        ui->label_03_GrabColor_Ch1->setText("Luminanz");
        ui->label_03_GrabColor_Ch2->setText("Green/Red");
        ui->label_03_GrabColor_Ch3->setText("Blue/Yellow");
        break;

    case 5://Luv
        ui->label_03_GrabColor_Ch1->setText("Luminanz");
        ui->label_03_GrabColor_Ch2->setText("Red/Green");
        ui->label_03_GrabColor_Ch3->setText("Blue/Yellow");
        break;

    default:
        break;
    }
}

void D_StepWindow::on_doubleSpinBox_01_Crop_Rect_X1_valueChanged(double arg1)
{
    if(arg1 > ui->doubleSpinBox_01_Crop_Rect_X2->value())
        ui->doubleSpinBox_01_Crop_Rect_X2->setValue(arg1 + 0.01);
}

void D_StepWindow::on_doubleSpinBox_01_Crop_Rect_Y1_valueChanged(double arg1)
{
    if(arg1 > ui->doubleSpinBox_01_Crop_Rect_Y2->value())
        ui->doubleSpinBox_01_Crop_Rect_Y2->setValue(arg1 + 0.01);
}

void D_StepWindow::on_doubleSpinBox_01_Crop_Rect_X2_valueChanged(double arg1)
{
    if(arg1 < ui->doubleSpinBox_01_Crop_Rect_X1->value())
        ui->doubleSpinBox_01_Crop_Rect_X1->setValue(arg1 - 0.01);
}

void D_StepWindow::on_doubleSpinBox_01_Crop_Rect_Y2_valueChanged(double arg1)
{
    if(arg1 < ui->doubleSpinBox_01_Crop_Rect_Y1->value())
        ui->doubleSpinBox_01_Crop_Rect_Y1->setValue(arg1 - 0.01);
}

void D_StepWindow::block_signals_thres(bool block)
{
    ui->doubleSpinBox_03_Thres_Rel_Base->blockSignals(block);
    ui->doubleSpinBox_03_Thres_Rel_Thresh_Abs->blockSignals(block);
    ui->doubleSpinBox_03_Thres_Rel_Thres_Rel->blockSignals(block);
    ui->horizontalSlider_03_Thres_Rel_Thresh_Rel->blockSignals(block);
}

void D_StepWindow::on_doubleSpinBox_03_Thres_Rel_Base_valueChanged(double arg1)
{
   block_signals_thres(true);

   ui->doubleSpinBox_03_Thres_Rel_Thresh_Abs->setValue(arg1 * (ui->doubleSpinBox_03_Thres_Rel_Thres_Rel->value() / 100.0));

   block_signals_thres(false);
}

void D_StepWindow::on_doubleSpinBox_03_Thres_Rel_Thres_Rel_valueChanged(double arg1)
{
    block_signals_thres(true);

    ui->doubleSpinBox_03_Thres_Rel_Thresh_Abs->setValue((arg1 / 100.0) * ui->doubleSpinBox_03_Thres_Rel_Base->value());
    ui->horizontalSlider_03_Thres_Rel_Thresh_Rel->setValue(arg1 * 10000.0);

    block_signals_thres(false);
}

void D_StepWindow::on_doubleSpinBox_03_Thres_Rel_Thresh_Abs_valueChanged(double arg1)
{
    block_signals_thres(true);

    ui->doubleSpinBox_03_Thres_Rel_Thres_Rel->setValue((arg1 / ui->doubleSpinBox_03_Thres_Rel_Base->value()) * 100.0);
    ui->horizontalSlider_03_Thres_Rel_Thresh_Rel->setValue((arg1 / ui->doubleSpinBox_03_Thres_Rel_Base->value()) * 1000000.0);

    block_signals_thres(false);
}

void D_StepWindow::on_horizontalSlider_03_Thres_Rel_Thresh_Rel_valueChanged(int value)
{
    block_signals_thres(true);

    ui->doubleSpinBox_03_Thres_Rel_Thres_Rel->setValue(value / 10000.0);
    ui->doubleSpinBox_03_Thres_Rel_Thresh_Abs->setValue((value / 1000000.0) * ui->doubleSpinBox_03_Thres_Rel_Base->value());

    block_signals_thres(false);
}

void D_StepWindow::on_comboBox_03_Thres_Type_currentIndexChanged(int index)
{
    bool man_rel = index != 2;
    ui->doubleSpinBox_03_Thres_Max_Value_Out->setEnabled(man_rel);
    ui->comboBox_03_Thres_Output_Mode->setEnabled(man_rel);
}

void D_StepWindow::on_doubleSpinBox_08_Select_Step_valueChanged(double arg1)
{
    ui->doubleSpinBox_08_Select_Min->setSingleStep(arg1);
    ui->doubleSpinBox_08_Select_Max->setSingleStep(arg1);
}

void D_StepWindow::on_spinBox_08_Select_Decimals_valueChanged(int arg1)
{
    ui->doubleSpinBox_08_Select_Step->setDecimals(arg1);
    ui->doubleSpinBox_08_Select_Min->setDecimals(arg1);
    ui->doubleSpinBox_08_Select_Max->setDecimals(arg1);
}

void D_StepWindow::on_spinBox_04_Edge_Thresh_Low_valueChanged(int arg1)
{
    if(arg1 > ui->spinBox_04_Edge_Thresh_High->value())
        ui->spinBox_04_Edge_Thresh_High->setValue(arg1);
}

void D_StepWindow::on_spinBox_04_Edge_Thresh_High_valueChanged(int arg1)
{
    if(arg1 < ui->spinBox_04_Edge_Thresh_Low->value())
        ui->spinBox_04_Edge_Thresh_Low->setValue(arg1);
}

void D_StepWindow::on_pushButton_00_CastRaw_Path_clicked()
{
    QString QS_path = QFileDialog::getOpenFileName(
                this,
                "Select file to cast to image",
                pStore->dir_Load()->path());

    if(QS_path == 0)
        return;

    FI_RawFile.setFile(QS_path);
    pStore->set_dir_Load(QS_path);

    Update_Img_Proc();
}

void D_StepWindow::on_spinBox_10_Crop_Min_X_valueChanged(int arg1)
{
    if(arg1 >= ui->spinBox_10_Crop_Max_X->value())
        ui->spinBox_10_Crop_Max_X->setValue(arg1 + 1);
}

void D_StepWindow::on_spinBox_10_Crop_Min_Y_valueChanged(int arg1)
{
    if(arg1 >= ui->spinBox_10_Crop_Max_Y->value())
        ui->spinBox_10_Crop_Max_Y->setValue(arg1 + 1);
}

void D_StepWindow::on_spinBox_10_Crop_Min_Z_valueChanged(int arg1)
{
    if(arg1 >= ui->spinBox_10_Crop_Max_Z->value())
        ui->spinBox_10_Crop_Max_Z->setValue(arg1 + 1);
}

void D_StepWindow::on_spinBox_10_Crop_Min_T_valueChanged(int arg1)
{
    if(arg1 >= ui->spinBox_10_Crop_Max_T->value())
        ui->spinBox_10_Crop_Max_T->setValue(arg1 + 1);
}

void D_StepWindow::on_spinBox_10_Crop_Min_S_valueChanged(int arg1)
{
    if(arg1 >= ui->spinBox_10_Crop_Max_S->value())
        ui->spinBox_10_Crop_Max_S->setValue(arg1 + 1);
}

void D_StepWindow::on_spinBox_10_Crop_Min_P_valueChanged(int arg1)
{
    if(arg1 >= ui->spinBox_10_Crop_Max_P->value())
        ui->spinBox_10_Crop_Max_P->setValue(arg1 + 1);
}

void D_StepWindow::on_spinBox_10_Crop_Max_X_valueChanged(int arg1)
{
    if(arg1 <= ui->spinBox_10_Crop_Min_X->value())
        ui->spinBox_10_Crop_Min_X->setValue(arg1 - 1);
}

void D_StepWindow::on_spinBox_10_Crop_Max_Y_valueChanged(int arg1)
{
    if(arg1 <= ui->spinBox_10_Crop_Min_Y->value())
        ui->spinBox_10_Crop_Min_Y->setValue(arg1 - 1);
}

void D_StepWindow::on_spinBox_10_Crop_Max_Z_valueChanged(int arg1)
{
    if(arg1 <= ui->spinBox_10_Crop_Min_Z->value())
        ui->spinBox_10_Crop_Min_Z->setValue(arg1 - 1);
}

void D_StepWindow::on_spinBox_10_Crop_Max_T_valueChanged(int arg1)
{
    if(arg1 <= ui->spinBox_10_Crop_Min_T->value())
        ui->spinBox_10_Crop_Min_T->setValue(arg1 - 1);
}

void D_StepWindow::on_spinBox_10_Crop_Max_S_valueChanged(int arg1)
{
    if(arg1 <= ui->spinBox_10_Crop_Min_S->value())
        ui->spinBox_10_Crop_Min_S->setValue(arg1 - 1);
}

void D_StepWindow::on_spinBox_10_Crop_Max_P_valueChanged(int arg1)
{
    if(arg1 <= ui->spinBox_10_Crop_Min_P->value())
        ui->spinBox_10_Crop_Min_P->setValue(arg1 - 1);
}

void D_StepWindow::on_comboBox_05_Elem_Morph_Type_currentIndexChanged(int index)
{
    ui->spinBox_05_Elem_Iterations->setEnabled(index > 6);
}

void D_StepWindow::on_spinBox_00_VideoStream_T_Offset_valueChanged(int arg1)
{
    if(arg1 == 1)
        ui->spinBox_00_VideoStream_T_Offset->setSuffix(" frame (center to center)");
    else
        ui->spinBox_00_VideoStream_T_Offset->setSuffix(" frames (center to center)");
}

void D_StepWindow::on_spinBox_00_VideoStream_T1_Frames_valueChanged(int arg1)
{
    if(arg1 == 1)
        ui->spinBox_00_VideoStream_T1_Frames->setSuffix(" frame");
    else
        ui->spinBox_00_VideoStream_T1_Frames->setSuffix(" frames");
}

void D_StepWindow::on_spinBox_00_VideoStream_T2_Frames_valueChanged(int arg1)
{
    if(arg1 == 1)
        ui->spinBox_00_VideoStream_T2_Frames->setSuffix(" frame");
    else
        ui->spinBox_00_VideoStream_T2_Frames->setSuffix(" frames");
}

void D_StepWindow::on_comboBox_View_Plane_currentIndexChanged(int index)
{
    index;
    Viewer.Set_ZoomReset();
    Update_Image();
}

void D_StepWindow::on_comboBox_08_FeatContextVal_Stat_currentIndexChanged(int index)
{
    ui->comboBox_08_FeatContextVal_Feat->setEnabled(index != c_STAT_COUNT);
}

void D_StepWindow::on_comboBox_08_FeatContextSelect_Stat_currentIndexChanged(int index)
{
    ui->comboBox_08_FeatContextSelect_Feat->setEnabled(index != c_STAT_COUNT);
}

void D_StepWindow::on_checkBox_06_4Img_Value_clicked(bool checked)
{
    ui->doubleSpinBox_06_4Img_Value->setEnabled(checked);
}

void D_StepWindow::on_checkBox_06_3Img_Value_clicked(bool checked)
{
    ui->doubleSpinBox_06_3Img_Value->setEnabled(checked);
}

void D_StepWindow::on_comboBox_06_3Img_Type_currentIndexChanged(int index)
{
    bool val_use = (index == c_ssT_MA_3_4_ADD) || (index == c_ssT_MA_3_4_MULT);
    ui->checkBox_06_3Img_Value->setEnabled(val_use);
    ui->doubleSpinBox_06_3Img_Value->setEnabled(ui->checkBox_06_3Img_Value->isChecked() && val_use);
}

void D_StepWindow::on_comboBox_06_4Img_Type_currentIndexChanged(int index)
{
    bool val_use = (index == c_ssT_MA_3_4_ADD) || (index == c_ssT_MA_3_4_MULT);
    ui->checkBox_06_4Img_Value->setEnabled(val_use);
    ui->doubleSpinBox_06_4Img_Value->setEnabled(ui->checkBox_06_4Img_Value->isChecked() && val_use);
}

void D_StepWindow::on_checkBox_09_HDR_Thresh_stateChanged(int arg1)
{
    ui->doubleSpinBox_09_HDR_Thresh_Low->setEnabled(arg1);
    ui->doubleSpinBox_09_HDR_Thresh_High->setEnabled(arg1);
}

void D_StepWindow::on_checkBox_09_HDR_Project_stateChanged(int arg1)
{
    ui->comboBox_09_HDR_ProjectStat->setEnabled(arg1);
    ui->checkBox_09_HDR_Thresh->setEnabled(arg1);
    ui->doubleSpinBox_09_HDR_Thresh_Low->setEnabled(arg1 && ui->checkBox_09_HDR_Thresh->isChecked());
    ui->doubleSpinBox_09_HDR_Thresh_High->setEnabled(arg1 && ui->checkBox_09_HDR_Thresh->isChecked());
}

void D_StepWindow::on_doubleSpinBox_09_HDR_Thresh_Low_valueChanged(double arg1)
{
    if(arg1 > ui->doubleSpinBox_09_HDR_Thresh_High->value())
        ui->doubleSpinBox_09_HDR_Thresh_High->setValue(arg1);
}

void D_StepWindow::on_doubleSpinBox_09_HDR_Thresh_High_valueChanged(double arg1)
{
    if(arg1 < ui->doubleSpinBox_09_HDR_Thresh_Low->value())
        ui->doubleSpinBox_09_HDR_Thresh_Low->setValue(arg1);
}

void D_StepWindow::on_checkBox_07_Fourier_Output_RealOnly_stateChanged(int arg1)
{
    ui->comboBox_07_Fourier_Output_ComplexMode->setEnabled(!arg1);
    ui->label_07_Fourier_Output_ComplexMode->setEnabled(!arg1);
}

void D_StepWindow::on_comboBox_View_Crop_currentIndexChanged(int index)
{
    ui->doubleSpinBox_View_Min->setEnabled(index != c_VIS_TRAFO_CROP_DYNAMIC);
    ui->doubleSpinBox_View_Max->setEnabled(index != c_VIS_TRAFO_CROP_DYNAMIC);
}

void D_StepWindow::on_comboBox_View_Transform_currentIndexChanged(int index)
{
    ui->doubleSpinBox_View_Gamma->setEnabled(index == c_VIS_TRAFO_GAMMA);
    ui->doubleSpinBox_View_Center->setEnabled(index == c_VIS_TRAFO_LOG);
    ui->doubleSpinBox_View_Divisor->setEnabled(index == c_VIS_TRAFO_LOG);
}

void D_StepWindow::on_comboBox_View_Anchor_currentIndexChanged(int index)
{
    ui->doubleSpinBox_View_Anchor->setEnabled(index != c_VIS_TRAFO_ANCHOR_DYNAMIC);
}

void D_StepWindow::on_comboBox_View_Range_currentIndexChanged(int index)
{
    ui->doubleSpinBox_View_Range->setEnabled(index != c_VIS_TRAFO_RANGE_DYNAMIC);
}

void D_StepWindow::on_checkBox_View_VisTrafo_stateChanged(int arg1)
{
    ui->comboBox_View_Complex->setVisible(arg1);
    ui->comboBox_View_Crop->setVisible(arg1);
    ui->comboBox_View_Transform->setVisible(arg1);
    ui->comboBox_View_Anchor->setVisible(arg1);
    ui->comboBox_View_Range->setVisible(arg1);
    ui->doubleSpinBox_View_Min->setVisible(arg1);
    ui->doubleSpinBox_View_Max->setVisible(arg1);
    ui->doubleSpinBox_View_Gamma->setVisible(arg1);
    ui->doubleSpinBox_View_Center->setVisible(arg1);
    ui->doubleSpinBox_View_Divisor->setVisible(arg1);
    ui->doubleSpinBox_View_Anchor->setVisible(arg1);
    ui->doubleSpinBox_View_Range->setVisible(arg1);
}

void D_StepWindow::on_doubleSpinBox_View_Min_valueChanged(double arg1)
{
    if(arg1 > ui->doubleSpinBox_View_Max->value())
        ui->doubleSpinBox_View_Max->setValue(arg1);
}

void D_StepWindow::on_doubleSpinBox_View_Max_valueChanged(double arg1)
{
    if(arg1 < ui->doubleSpinBox_View_Min->value())
        ui->doubleSpinBox_View_Min->setValue(arg1);
}

void D_StepWindow::on_radioButton_09_RelationStat_Distance_clicked(bool checked)
{
    ui->comboBox_09_RelationStat_StatDistance->setEnabled(checked);
    ui->comboBox_09_RelationStat_StatAngle->setEnabled(!checked);
}

void D_StepWindow::on_radioButton_09_RelationStat_Angle_clicked(bool checked)
{
    ui->comboBox_09_RelationStat_StatDistance->setEnabled(!checked);
    ui->comboBox_09_RelationStat_StatAngle->setEnabled(checked);
}

void D_StepWindow::on_comboBox_04_Statistic_MaskType_currentIndexChanged(int index)
{
    ui->label_04_Statistic_Radius->setEnabled(index == c_MASK_MODE_CIRC);
    ui->doubleSpinBox_04_Statistic_Radius->setEnabled(index == c_MASK_MODE_CIRC);
    ui->label_04_Statistic_Size->setEnabled(index == c_MASK_MODE_RECT);
    ui->spinBox_04_Statistic_Size_x->setEnabled(index == c_MASK_MODE_RECT);
    ui->spinBox_04_Statistic_Size_y->setEnabled(index == c_MASK_MODE_RECT);
}

void D_StepWindow::on_doubleSpinBox_04_RankOrder_Quantil_valueChanged(double arg1)
{
    ui->horizontalSlider_04_RankOrder_Quantil->setValue(arg1 * 100);
}

void D_StepWindow::on_horizontalSlider_04_RankOrder_Quantil_valueChanged(int value)
{
    ui->doubleSpinBox_04_RankOrder_Quantil->setValue(value / 100.0);
}

void D_StepWindow::on_comboBox_04_RankOrder_MaskType_currentIndexChanged(int index)
{
    ui->label_04_RankOrder_Radius->setEnabled(index == c_MASK_MODE_CIRC);
    ui->doubleSpinBox_04_RankOrder_Radius->setEnabled(index == c_MASK_MODE_CIRC);
    ui->label_04_RankOrder_Size->setEnabled(index == c_MASK_MODE_RECT);
    ui->spinBox_04_RankOrder_Size_x->setEnabled(index == c_MASK_MODE_RECT);
    ui->spinBox_04_RankOrder_Size_y->setEnabled(index == c_MASK_MODE_RECT);
}

void D_StepWindow::on_comboBox_07_WatershedCustom_Flood_currentIndexChanged(int index)
{
    if(index == c_WATERSHED_FILL_MASK_DIST || index == c_WATERSHED_FILL_MASK_DIST_INV)
        ui->stackedWidget_07_WatershedCustom_Flood->setCurrentIndex(1);
    else if(index == c_WATERSHED_FILL_SOURCE_MORPH_GRAD)
        ui->stackedWidget_07_WatershedCustom_Flood->setCurrentIndex(2);
    else
        ui->stackedWidget_07_WatershedCustom_Flood->setCurrentIndex(0);
}

void D_StepWindow::on_comboBox_07_WatershedCustom_Marker_currentIndexChanged(int index)
{
    if(index == c_WATERSHED_MARKER_SOURCE_LABELED || index == c_WATERSHED_MARKER_SOURCE_LABELED_INV)
        ui->stackedWidget_07_WatershedCustom_Marker->setCurrentIndex(1);
    else
        ui->stackedWidget_07_WatershedCustom_Marker->setCurrentIndex(0);
}

void D_StepWindow::on_comboBox_07_WatershedCustom_Mask_currentIndexChanged(int index)
{
    if(index == c_WATERSHED_MASK_SOURCE_BINARY_THRES || index == c_WATERSHED_MASK_FILL_BINARY_THRES)
        ui->stackedWidget_07_WatershedCustom_Mask->setCurrentIndex(1);
    else
        ui->stackedWidget_07_WatershedCustom_Mask->setCurrentIndex(0);
}

void D_StepWindow::on_checkBox_07_WatershedCustom_DrawWatershed_stateChanged(int arg1)
{
    if(arg1 != 0)
        ui->stackedWidget_07_WatershedCustom_DrawWatershed->setCurrentIndex(1);
    else
        ui->stackedWidget_07_WatershedCustom_DrawWatershed->setCurrentIndex(0);
}

void D_StepWindow::on_spinBox_09_Michelson_Scene_Size_X_valueChanged(int arg1)
{
    ui->label_09_Michelson_SceneSize_X->setText(QString::number(arg1 * (ui->doubleSpinBox_09_Michelson_Scale_um->value() / ui->spinBox_09_Michelson_Scale_px->value())) + "μm");
}

void D_StepWindow::on_spinBox_09_Michelson_Scene_Size_Y_valueChanged(int arg1)
{
    ui->label_09_Michelson_SceneSize_Y->setText(QString::number(arg1 * (ui->doubleSpinBox_09_Michelson_Scale_um->value() / ui->spinBox_09_Michelson_Scale_px->value())) + "μm");
}

void D_StepWindow::on_spinBox_09_Michelson_Scene_Size_Z_valueChanged(int arg1)
{
    ui->label_09_Michelson_SceneSize_Z->setText(QString::number(arg1 * (ui->doubleSpinBox_09_Michelson_Scale_um->value() / ui->spinBox_09_Michelson_Scale_px->value())) + "μm");
}

void D_StepWindow::on_spinBox_09_Michelson_Scale_px_valueChanged(int arg1)
{
    ui->label_09_Michelson_SceneSize_X->setText(QString::number(ui->spinBox_09_Michelson_Scene_Size_X->value() * (ui->doubleSpinBox_09_Michelson_Scale_um->value() / arg1)) + "μm");
    ui->label_09_Michelson_SceneSize_Y->setText(QString::number(ui->spinBox_09_Michelson_Scene_Size_Y->value() * (ui->doubleSpinBox_09_Michelson_Scale_um->value() / arg1)) + "μm");
    ui->label_09_Michelson_SceneSize_Z->setText(QString::number(ui->spinBox_09_Michelson_Scene_Size_Z->value() * (ui->doubleSpinBox_09_Michelson_Scale_um->value() / arg1)) + "μm");
}

void D_StepWindow::on_doubleSpinBox_09_Michelson_Scale_um_valueChanged(double arg1)
{
    ui->label_09_Michelson_SceneSize_X->setText(QString::number(ui->spinBox_09_Michelson_Scene_Size_X->value() * (arg1 / ui->spinBox_09_Michelson_Scale_px->value())) + "μm");
    ui->label_09_Michelson_SceneSize_Y->setText(QString::number(ui->spinBox_09_Michelson_Scene_Size_Y->value() * (arg1 / ui->spinBox_09_Michelson_Scale_px->value())) + "μm");
    ui->label_09_Michelson_SceneSize_Z->setText(QString::number(ui->spinBox_09_Michelson_Scene_Size_Z->value() * (arg1 / ui->spinBox_09_Michelson_Scale_px->value())) + "μm");
}

void D_StepWindow::on_comboBox_01_Scale_Type_currentIndexChanged(int index)
{
    ui->label_01_Scale_Factor->setEnabled(index == c_SCALE_TYPE_FACTOR);
    ui->doubleSpinBox_01_Scale_Factor_X->setEnabled(index == c_SCALE_TYPE_FACTOR);
    ui->doubleSpinBox_01_Scale_Factor_Y->setEnabled(index == c_SCALE_TYPE_FACTOR);

    ui->label_01_Scale_Size->setEnabled(index == c_SCALE_TYPE_TARGET_SIZE);
    ui->spinBox_01_Scale_Size_X->setEnabled(index == c_SCALE_TYPE_TARGET_SIZE);
    ui->spinBox_01_Scale_Size_Y->setEnabled(index == c_SCALE_TYPE_TARGET_SIZE);
}

/*
void D_StepWindow::on_pushButton_Test_3D_clicked()
{
    Mat MA_gray_tmp;
    ERR(D_VisDat_Proc::Read_2D_Plane(
            &MA_gray_tmp,
            pStore->get_pVD(pos_Dest),
            D_VisDat_Slice_2D(-1, -1, 0, 0, 0, 0)),
        "D_StepWindow::on_pushButton_Test_3D_clicked",
        "D_VisDat_Proc::Read_2D_Plane");

    ERR(Viewer_3D.plot_img2D_gray(&MA_gray_tmp),
        "D_StepWindow::on_pushButton_Test_3D_clicked",
        "Viewer_3D.plot_img2D_gray(&MA_gray_tmp)");

    MA_gray_tmp.release();

    //Viewer_3D.plot_test();
}
*/

void D_StepWindow::on_actionUpdate_3D_triggered()
{
    Update_3DPlot();
}

void D_StepWindow::on_action_Autoupdate_3D_View_triggered(bool checked)
{
    if(checked)
    {
        connect(ui->comboBox_3D_Mode,                       SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        connect(ui->comboBox_3D_Condition,                  SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        connect(ui->comboBox_3D_ColorHandling,              SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        connect(ui->comboBox_3D_Axis_X,                     SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        connect(ui->comboBox_3D_Axis_Y,                     SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        connect(ui->comboBox_3D_Axis_Z,                     SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        connect(ui->comboBox_3D_Axis_V,                     SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        connect(ui->comboBox_3D_Marker,                     SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        connect(ui->comboBox_3D_ShadowQuality,              SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        connect(ui->comboBox_3D_TextureMode_Heightmap,      SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        connect(ui->comboBox_3D_2dPlane_Heightmap,          SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        connect(ui->comboBox_3D_SurfaceMode,                SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        connect(ui->comboBox_3D_SurfaceDimension,           SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        connect(ui->checkBox_3D_Grid,                       SIGNAL(clicked(bool)),                      this,           SLOT(Update_3DPlot()));
        connect(ui->checkBox_3D_Background,                 SIGNAL(clicked(bool)),                      this,           SLOT(Update_3DPlot()));
        connect(ui->checkBox_3D_Smooth,                     SIGNAL(clicked(bool)),                      this,           SLOT(Update_3DPlot()));
        connect(ui->checkBox_3D_Surface,                    SIGNAL(clicked(bool)),                      this,           SLOT(Update_3DPlot()));
        connect(ui->checkBox_3D_Wireframe,                  SIGNAL(clicked(bool)),                      this,           SLOT(Update_3DPlot()));
    }
    else
    {
        disconnect(ui->comboBox_3D_Mode,                    SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        disconnect(ui->comboBox_3D_Condition,               SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        disconnect(ui->comboBox_3D_ColorHandling,           SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        disconnect(ui->comboBox_3D_Axis_X,                  SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        disconnect(ui->comboBox_3D_Axis_Y,                  SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        disconnect(ui->comboBox_3D_Axis_Z,                  SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        disconnect(ui->comboBox_3D_Axis_V,                  SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        disconnect(ui->comboBox_3D_Marker,                  SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        disconnect(ui->comboBox_3D_ShadowQuality,           SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        disconnect(ui->comboBox_3D_TextureMode_Heightmap,   SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        disconnect(ui->comboBox_3D_2dPlane_Heightmap,       SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        disconnect(ui->comboBox_3D_SurfaceMode,             SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        disconnect(ui->comboBox_3D_SurfaceDimension,        SIGNAL(currentIndexChanged(int)),           this,           SLOT(Update_3DPlot()));
        disconnect(ui->checkBox_3D_Grid,                    SIGNAL(clicked(bool)),                      this,           SLOT(Update_3DPlot()));
        disconnect(ui->checkBox_3D_Background,              SIGNAL(clicked(bool)),                      this,           SLOT(Update_3DPlot()));
        disconnect(ui->checkBox_3D_Smooth,                  SIGNAL(clicked(bool)),                      this,           SLOT(Update_3DPlot()));
        disconnect(ui->checkBox_3D_Surface,                 SIGNAL(clicked(bool)),                      this,           SLOT(Update_3DPlot()));
        disconnect(ui->checkBox_3D_Wireframe,               SIGNAL(clicked(bool)),                      this,           SLOT(Update_3DPlot()));
    }
}

void D_StepWindow::on_comboBox_3D_ColorHandling_currentIndexChanged(int index)
{
    ui->comboBox_3D_Axis_V->setEnabled(index != c_VIEWER_PLOT_3D_VALUE_HANDLING_MONO);
}

void D_StepWindow::on_comboBox_3D_TextureMode_Heightmap_currentIndexChanged(int index)
{
    ui->comboBox_3D_Axis_V_Heightmap->setEnabled(index == c_VIEWER_PLOT_3D_TEXTURE_GRAY || index == c_VIEWER_PLOT_3D_TEXTURE_HUE);
}

void D_StepWindow::on_comboBox_3D_SurfaceMode_currentIndexChanged(int index)
{
    ui->comboBox_3D_SurfaceDimension->setEnabled(index == c_VIEWER_PLOT_3D_SURFACE_MODE_DIMENSION);
    ui->comboBox_3D_Axis_Z_Heightmap->setEnabled(index != c_VIEWER_PLOT_3D_SURFACE_MODE_CHANNELS);
    ui->comboBox_3D_TextureMode_Heightmap->setEnabled(index != c_VIEWER_PLOT_3D_SURFACE_MODE_CHANNELS);
    ui->comboBox_3D_Axis_V_Heightmap->setEnabled(index != c_VIEWER_PLOT_3D_SURFACE_MODE_CHANNELS && ui->comboBox_3D_TextureMode_Heightmap->currentIndex() != c_VIEWER_PLOT_3D_TEXTURE_IMAGE);
}

void D_StepWindow::on_comboBox_02_Depth_Norm_currentIndexChanged(int index)
{
    ui->doubleSpinBox_02_Depth_Minimum->setEnabled(index == 1);
    ui->doubleSpinBox_02_Depth_Maximum->setEnabled(index == 1);
}
