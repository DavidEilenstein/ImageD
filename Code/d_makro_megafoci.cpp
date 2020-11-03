/************************************
 *   added:     ??.03.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_makro_megafoci.h"
#include "ui_d_makro_megafoci.h"

D_MAKRO_MegaFoci::D_MAKRO_MegaFoci(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_MegaFoci)
{
    //Ui
    ui->setupUi(this);

    //Storeage
    pStore = pStorage;

    //Image
    MA_Show = pStore->get_Adress(0)->clone();
    MA_OverviewSmall_Show = pStore->get_Adress(0)->clone();
    MA_OverviewBig_Show = pStore->get_Adress(0)->clone();
    VD_Show = pStore->get_VD(0);
    VD_Overview_Save = pStore->get_VD(0);

    //img proc
    vVD_ImgProcSteps.resize(STEP_NUMBER_OF);
    for(int s = 0; s < STEP_NUMBER_OF; s++)
        vVD_ImgProcSteps[s] = pStore->get_VD(0);

    //GraphicsView
    Viewer_Main.set_GV(ui->graphicsView_ImgProc);
    Viewer_Main.Set_VisTrafo_ActiveBool(true);
    Viewer_Main.Set_VisTrafo_Mode_Trafo(c_VIS_TRAFO_LOG);
    Viewer_Main.Set_VisTrafo_Divisor(250.0);
    Viewer_Main.Set_VisTrafo_SpreadInMax(3000.0);
    Viewer_Main.Set_VisTrafo_Range(10000.0);

    Viewer_OverviewSmall.set_GV(ui->graphicsView_OverviewSmall);
    Viewer_OverviewSmall.Set_VisTrafo_ActiveBool(true);
    Viewer_OverviewSmall.Set_VisTrafo_Mode_Trafo(c_VIS_TRAFO_LOG);
    Viewer_OverviewSmall.Set_VisTrafo_Divisor(250.0);
    Viewer_OverviewSmall.Set_VisTrafo_SpreadInMax(3000.0);
    Viewer_OverviewSmall.Set_VisTrafo_Range(10000.0);

    Viewer_OverviewBig.set_GV(ui->graphicsView_OverviewBig);
    Viewer_OverviewBig.Set_VisTrafo_ActiveBool(true);
    Viewer_OverviewBig.Set_VisTrafo_Mode_Trafo(c_VIS_TRAFO_LOG);
    Viewer_OverviewBig.Set_VisTrafo_Divisor(250.0);
    Viewer_OverviewBig.Set_VisTrafo_SpreadInMax(3000.0);
    Viewer_OverviewBig.Set_VisTrafo_Range(10000.0);

    //statusbar
    L_SB_ValueAtCursor = new QLabel(this);
    L_SB_ValueAtCursor->setToolTip("Value under current cursor position");
    ui->statusbar->addPermanentWidget(L_SB_ValueAtCursor);

    L_SB_InfoVD = new QLabel(this);
    L_SB_InfoVD->setToolTip("Info about current VisDat");
    ui->statusbar->addPermanentWidget(L_SB_InfoVD);

    //connects
    //viewer
    connect(ui->groupBox_VisTrafo,                          SIGNAL(clicked(bool)),                      &Viewer_Main,       SLOT(Set_VisTrafo_ActiveBool(bool)));
    connect(ui->doubleSpinBox_VisTrafo_CropMin,             SIGNAL(valueChanged(double)),               &Viewer_Main,       SLOT(Set_VisTrafo_SpreadInMin(double)));
    connect(ui->doubleSpinBox_VisTrafo_CropMax,             SIGNAL(valueChanged(double)),               &Viewer_Main,       SLOT(Set_VisTrafo_SpreadInMax(double)));
    connect(ui->doubleSpinBox_VisTrafo_Gamma,               SIGNAL(valueChanged(double)),               &Viewer_Main,       SLOT(Set_VisTrafo_Gamma(double)));
    connect(ui->doubleSpinBox_VisTrafo_LogCenter,           SIGNAL(valueChanged(double)),               &Viewer_Main,       SLOT(Set_VisTrafo_Center(double)));
    connect(ui->doubleSpinBox_VisTrafo_LogDivisor,          SIGNAL(valueChanged(double)),               &Viewer_Main,       SLOT(Set_VisTrafo_Divisor(double)));
    connect(ui->doubleSpinBox_VisTrafo_Anchor,              SIGNAL(valueChanged(double)),               &Viewer_Main,       SLOT(Set_VisTrafo_Anchor(double)));
    connect(ui->doubleSpinBox_VisTrafo_Range,               SIGNAL(valueChanged(double)),               &Viewer_Main,       SLOT(Set_VisTrafo_Range(double)));
    connect(ui->comboBox_VisTrafo_CropMode,                 SIGNAL(currentIndexChanged(int)),           &Viewer_Main,       SLOT(Set_VisTrafo_Mode_Crop(int)));
    connect(ui->comboBox_VisTrafo_TransformationMode,       SIGNAL(currentIndexChanged(int)),           &Viewer_Main,       SLOT(Set_VisTrafo_Mode_Trafo(int)));
    connect(ui->comboBox_VisTrafo_AnchorMode,               SIGNAL(currentIndexChanged(int)),           &Viewer_Main,       SLOT(Set_VisTrafo_Mode_Anchor(int)));
    connect(ui->comboBox_VisTrafo_RangeMode,                SIGNAL(currentIndexChanged(int)),           &Viewer_Main,       SLOT(Set_VisTrafo_Mode_Range(int)));

    connect(ui->groupBox_VisTrafo,                          SIGNAL(clicked(bool)),                      &Viewer_OverviewSmall,   SLOT(Set_VisTrafo_ActiveBool(bool)));
    connect(ui->doubleSpinBox_VisTrafo_CropMin,             SIGNAL(valueChanged(double)),               &Viewer_OverviewSmall,   SLOT(Set_VisTrafo_SpreadInMin(double)));
    connect(ui->doubleSpinBox_VisTrafo_CropMax,             SIGNAL(valueChanged(double)),               &Viewer_OverviewSmall,   SLOT(Set_VisTrafo_SpreadInMax(double)));
    connect(ui->doubleSpinBox_VisTrafo_Gamma,               SIGNAL(valueChanged(double)),               &Viewer_OverviewSmall,   SLOT(Set_VisTrafo_Gamma(double)));
    connect(ui->doubleSpinBox_VisTrafo_LogCenter,           SIGNAL(valueChanged(double)),               &Viewer_OverviewSmall,   SLOT(Set_VisTrafo_Center(double)));
    connect(ui->doubleSpinBox_VisTrafo_LogDivisor,          SIGNAL(valueChanged(double)),               &Viewer_OverviewSmall,   SLOT(Set_VisTrafo_Divisor(double)));
    connect(ui->doubleSpinBox_VisTrafo_Anchor,              SIGNAL(valueChanged(double)),               &Viewer_OverviewSmall,   SLOT(Set_VisTrafo_Anchor(double)));
    connect(ui->doubleSpinBox_VisTrafo_Range,               SIGNAL(valueChanged(double)),               &Viewer_OverviewSmall,   SLOT(Set_VisTrafo_Range(double)));
    connect(ui->comboBox_VisTrafo_CropMode,                 SIGNAL(currentIndexChanged(int)),           &Viewer_OverviewSmall,   SLOT(Set_VisTrafo_Mode_Crop(int)));
    connect(ui->comboBox_VisTrafo_TransformationMode,       SIGNAL(currentIndexChanged(int)),           &Viewer_OverviewSmall,   SLOT(Set_VisTrafo_Mode_Trafo(int)));
    connect(ui->comboBox_VisTrafo_AnchorMode,               SIGNAL(currentIndexChanged(int)),           &Viewer_OverviewSmall,   SLOT(Set_VisTrafo_Mode_Anchor(int)));
    connect(ui->comboBox_VisTrafo_RangeMode,                SIGNAL(currentIndexChanged(int)),           &Viewer_OverviewSmall,   SLOT(Set_VisTrafo_Mode_Range(int)));

    connect(ui->groupBox_VisTrafo,                          SIGNAL(clicked(bool)),                      &Viewer_OverviewBig,     SLOT(Set_VisTrafo_ActiveBool(bool)));
    connect(ui->doubleSpinBox_VisTrafo_CropMin,             SIGNAL(valueChanged(double)),               &Viewer_OverviewBig,     SLOT(Set_VisTrafo_SpreadInMin(double)));
    connect(ui->doubleSpinBox_VisTrafo_CropMax,             SIGNAL(valueChanged(double)),               &Viewer_OverviewBig,     SLOT(Set_VisTrafo_SpreadInMax(double)));
    connect(ui->doubleSpinBox_VisTrafo_Gamma,               SIGNAL(valueChanged(double)),               &Viewer_OverviewBig,     SLOT(Set_VisTrafo_Gamma(double)));
    connect(ui->doubleSpinBox_VisTrafo_LogCenter,           SIGNAL(valueChanged(double)),               &Viewer_OverviewBig,     SLOT(Set_VisTrafo_Center(double)));
    connect(ui->doubleSpinBox_VisTrafo_LogDivisor,          SIGNAL(valueChanged(double)),               &Viewer_OverviewBig,     SLOT(Set_VisTrafo_Divisor(double)));
    connect(ui->doubleSpinBox_VisTrafo_Anchor,              SIGNAL(valueChanged(double)),               &Viewer_OverviewBig,     SLOT(Set_VisTrafo_Anchor(double)));
    connect(ui->doubleSpinBox_VisTrafo_Range,               SIGNAL(valueChanged(double)),               &Viewer_OverviewBig,     SLOT(Set_VisTrafo_Range(double)));
    connect(ui->comboBox_VisTrafo_CropMode,                 SIGNAL(currentIndexChanged(int)),           &Viewer_OverviewBig,     SLOT(Set_VisTrafo_Mode_Crop(int)));
    connect(ui->comboBox_VisTrafo_TransformationMode,       SIGNAL(currentIndexChanged(int)),           &Viewer_OverviewBig,     SLOT(Set_VisTrafo_Mode_Trafo(int)));
    connect(ui->comboBox_VisTrafo_AnchorMode,               SIGNAL(currentIndexChanged(int)),           &Viewer_OverviewBig,     SLOT(Set_VisTrafo_Mode_Anchor(int)));
    connect(ui->comboBox_VisTrafo_RangeMode,                SIGNAL(currentIndexChanged(int)),           &Viewer_OverviewBig,     SLOT(Set_VisTrafo_Mode_Range(int)));

    //status bar
    connect(&Viewer_Main,                                   SIGNAL(MouseMoved_Value(QString)),          L_SB_ValueAtCursor, SLOT(setText(QString)));
    connect(&Viewer_OverviewSmall,                          SIGNAL(MouseMoved_Value(QString)),          L_SB_ValueAtCursor, SLOT(setText(QString)));
    connect(&Viewer_OverviewBig,                            SIGNAL(MouseMoved_Value(QString)),          L_SB_ValueAtCursor, SLOT(setText(QString)));
    //Viewport (only inside image processing position: fix x, y, t)
    connect(ui->spinBox_Viewport_Z,                         SIGNAL(valueChanged(int)),                  this,               SLOT(Update_Images()));
    connect(ui->spinBox_Viewport_P,                         SIGNAL(valueChanged(int)),                  this,               SLOT(Update_Images()));
    //Image Processing / image proc pos relevant viewport
    connect(ui->spinBox_Viewport_X,                         SIGNAL(valueChanged(int)),                  this,               SLOT(Update_ImageProcessing_CurrentImage()));
    connect(ui->spinBox_Viewport_Y,                         SIGNAL(valueChanged(int)),                  this,               SLOT(Update_ImageProcessing_CurrentImage()));
    connect(ui->spinBox_Viewport_T,                         SIGNAL(valueChanged(int)),                  this,               SLOT(Update_ImageProcessing_CurrentImage()));
    //data set load
    connect(ui->pushButton_DataLoad,                        SIGNAL(clicked(bool)),                      this,               SLOT(Load_Dataset()));
    //data set dimension define
    connect(ui->spinBox_DataDim_X,                          SIGNAL(valueChanged(int)),                  this,               SLOT(set_dataset_dim_x(int)));
    connect(ui->spinBox_DataDim_Y,                          SIGNAL(valueChanged(int)),                  this,               SLOT(set_dataset_dim_y(int)));
    connect(ui->spinBox_DataDim_Z,                          SIGNAL(valueChanged(int)),                  this,               SLOT(set_dataset_dim_z(int)));
    connect(ui->spinBox_DataDim_T,                          SIGNAL(valueChanged(int)),                  this,               SLOT(set_dataset_dim_t(int)));
    //overview big
    connect(ui->spinBox_OverviewBig_T,                      SIGNAL(valueChanged(int)),                  this,               SLOT(Update_Images_OverviewBig()));


    //on start
    this->showMaximized();
    StatusSet("Started this awesome piece of software");
    Update_Views();
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    setWindowTitle("ImageD - Monster Image Handler and Foci Detector (suggestions for a better name are welcome)");
    Populate_CB_AtStart();

    //update ui accesibility
    ui->groupBox_Dataset->setEnabled(true);
    ui->groupBox_Viewport->setEnabled(false);
    ui->groupBox_VisTrafo->setEnabled(false);
    ui->groupBox_View->setEnabled(false);
    ui->groupBox_Control->setEnabled(false);

    //set default indices
    ui->tabWidget_Control->setCurrentIndex(TAB_CONTROL_IMG_PROC);
    ui->stackedWidget_View->setCurrentIndex(VIEW_PAGE_IMG_PROC);
    StatusSet("Ready to serve your will my master");
    StatusSet("I'm hungry, please feed dataset");
}

D_MAKRO_MegaFoci::~D_MAKRO_MegaFoci()
{
    delete ui;
}

void D_MAKRO_MegaFoci::closeEvent(QCloseEvent *event)
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
        StatusSet("I'll minimze instead to save your data");
    }
}

void D_MAKRO_MegaFoci::resizeEvent(QResizeEvent *event)
{
    event->accept();
    Update_Views();
}

void D_MAKRO_MegaFoci::Update_Ui()
{
    bool en_in = this->isEnabled();
    if(en_in)
        this->setEnabled(false);

    this->repaint();
    qApp->processEvents();

    if(en_in)
        this->setEnabled(true);
}

void D_MAKRO_MegaFoci::Update_Views()
{
    Viewer_Main.Update_View();
    Viewer_OverviewSmall.Update_View();
    Viewer_OverviewBig.Update_View();
}

void D_MAKRO_MegaFoci::Update_Images()
{
    Update_Images_OverviewSmall();

    if(ui->tabWidget_Control->currentIndex() == TAB_CONTROL_IMG_PROC)
        Update_Images_Proc();
    else if(ui->tabWidget_Control->currentIndex() == TAB_CONTROL_OVERVIEW_BIG)
        Update_Images_OverviewBig();
}

void D_MAKRO_MegaFoci::Update_Images_Proc()
{
    //get inidices to show
    int z = ui->spinBox_Viewport_Z->value();
    int p = ui->spinBox_Viewport_P->value();

    //make sure indices fit
    if(z >= vVD_ImgProcSteps[ui->comboBox_ImgProc_StepShow->currentIndex()].pDim()->size_Z())   z = 0;
    if(p >= vVD_ImgProcSteps[ui->comboBox_ImgProc_StepShow->currentIndex()].pDim()->size_P())   p = 0;

    //2D plane to show
    D_VisDat_Slice_2D Slice2d(-1, -1, z, 0, 0, p);

    //Crop 2D plane from VD
    ERR(D_VisDat_Proc::Read_2D_Plane(
                &MA_Show,
                &(vVD_ImgProcSteps[ui->comboBox_ImgProc_StepShow->currentIndex()]),
                Slice2d),
        "Update_Images_Proc",
        "D_VisDat_Proc::Read_2D_Plane - Crop " + Slice2d.info() + " from " + vVD_ImgProcSteps[ui->comboBox_ImgProc_StepShow->currentIndex()].info());

    //display Mat
    Viewer_Main.Update_Image(&MA_Show);
}

void D_MAKRO_MegaFoci::Update_Images_OverviewSmall()
{
    //get inidices to show
    int t = ui->spinBox_Viewport_T->value();

    //make sure indices fit
    if(t >= VD_Overview_Save.pDim()->size_T())   t = 0;

    //2D plane to show
    D_VisDat_Slice_2D Slice2d(-1, -1, 0, t, 0, 0);

    //Crop 2D plane from VD
    ERR(D_VisDat_Proc::Read_2D_Plane(
                &MA_OverviewSmall_Show,
                &VD_Overview_Save,
                Slice2d),
        "Update_Images_Proc",
        "D_VisDat_Proc::Read_2D_Plane - Crop " + Slice2d.info() + " from " + VD_Overview_Save.info());

    //get max of overview
    double min, max;
    ERR(D_Img_Proc::MinMax_of_Mat(
            &MA_OverviewSmall_Show,
            &min,
            &max),
        "Update_Images_Overview",
        "D_Img_Proc::MinMax_of_Mat");
    //scale max down to ignore very high values
    max *= 0.5;
    if(max < 1)
        max = 1;

    //draw grid
    ERR(D_Img_Proc::Draw_GridSimple(
            &MA_OverviewSmall_Show,
            static_cast<int>(dataset_dim_mosaic_x),
            static_cast<int>(dataset_dim_mosaic_y),
            Scalar(max, max, max)),
        "Update_Images_Overview",
        "D_Img_Proc::Draw_Grid");

    //draw rect at current
    ERR(D_Img_Proc::Draw_Rect(
            &MA_OverviewSmall_Show,
            static_cast<int>(ui->spinBox_Viewport_X->value() * overview_SubImgSizeX),
            static_cast<int>(ui->spinBox_Viewport_Y->value() * overview_SubImgSizeY),
            static_cast<int>((ui->spinBox_Viewport_X->value() + 1 + ui->doubleSpinBox_ImgProc_Stitch_Border->value() / 100.0) * overview_SubImgSizeX),
            static_cast<int>((ui->spinBox_Viewport_Y->value() + 1 + ui->doubleSpinBox_ImgProc_Stitch_Border->value() / 100.0) * overview_SubImgSizeY),
            3,
            max),
        "Update_Images_Overview",
        "D_Img_Proc::Draw_Grid");

    //display Mat
    Viewer_OverviewSmall.Update_Image(&MA_OverviewSmall_Show);
    StatusSet("Show fancy overview");
}

void D_MAKRO_MegaFoci::Update_Images_OverviewBig()
{
    //get inidices to show
    int t = ui->spinBox_OverviewBig_T->value();

    //make sure indices fit
    if(t >= VD_Overview_Save.pDim()->size_T())   t = 0;

    //2D plane to show
    D_VisDat_Slice_2D Slice2d(-1, -1, 0, t, 0, 0);

    //Crop 2D plane from VD
    ERR(D_VisDat_Proc::Read_2D_Plane(
                &MA_OverviewBig_Show,
                &VD_Overview_Save,
                Slice2d),
        "Update_Images_OverviewBig",
        "D_VisDat_Proc::Read_2D_Plane - Crop " + Slice2d.info() + " from " + VD_Overview_Save.info());

    //display Mat
    Viewer_OverviewBig.Update_Image(&MA_OverviewBig_Show);
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_CurrentImage()
{
    if(!state_dataset_img_list_loaded)
        return;

    Update_ImageProcessing_StepFrom(0);
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepFrom(size_t step_start)
{
    if(!state_dataset_img_list_loaded)
        return;

    for(size_t s = step_start; s < STEP_NUMBER_OF; s++)
        Update_ImageProcessing_StepSingle(s);

    Update_Images_Proc();
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepSingle(size_t step)
{
    if(!state_dataset_img_list_loaded)
        return;

    //current position in dataset
    size_t dataset_pos_x = ui->spinBox_Viewport_X->value();
    size_t dataset_pos_y = ui->spinBox_Viewport_Y->value();
    size_t dataset_pos_t = ui->spinBox_Viewport_T->value();

    //select step to do
    StatusSet("ImgProc: " + QSL_Steps[static_cast<int>(step)]);
    switch (step) {

    case STEP_PRE_LOAD_MAIN:
    {
        ERR(Load_Image_full_ZP(
                &(vVD_ImgProcSteps[STEP_PRE_LOAD_MAIN]),
                dataset_pos_x,
                dataset_pos_y,
                dataset_pos_t),
            "Update_ImageProcessing_StepSingle",
            "STEP_LOAD_MAIN");
    }
        break;

    case STEP_PRE_LOAD_RIGHT:
    {
        ERR(Load_Image_full_ZP(
                &(vVD_ImgProcSteps[STEP_PRE_LOAD_RIGHT]),
                dataset_pos_x + 1,
                dataset_pos_y,
                dataset_pos_t),
            "Update_ImageProcessing_StepSingle",
            "STEP_LOAD_RIGHT");
    }
        break;

    case STEP_PRE_LOAD_BOTTOM:
    {
        ERR(Load_Image_full_ZP(
                &(vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM]),
                dataset_pos_x,
                dataset_pos_y + 1,
                dataset_pos_t),
            "Update_ImageProcessing_StepSingle",
            "STEP_LOAD_BOTTOM");
    }
        break;

    case STEP_PRE_LOAD_BOTTOM_RIGHT:
    {
        ERR(Load_Image_full_ZP(
                &(vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM_RIGHT]),
                dataset_pos_x + 1,
                dataset_pos_y + 1,
                dataset_pos_t),
            "Update_ImageProcessing_StepSingle",
            "STEP_LOAD_BOTTOM_RIGHT");
    }
        break;

    case STEP_PRE_STITCH:
    {
        ERR(D_VisDat_Proc::Stitch_Border_rel_custom(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_PRE_STITCH]),
                &(vVD_ImgProcSteps[STEP_PRE_LOAD_MAIN]),
                &(vVD_ImgProcSteps[STEP_PRE_LOAD_RIGHT]),
                &(vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM]),
                &(vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM_RIGHT]),
                ui->doubleSpinBox_ImgProc_Stitch_Border->value() / 100.0,
                ui->doubleSpinBox_ImgProc_Stitch_Border->value() / 100.0,
                ui->doubleSpinBox_ImgProc_Stitch_Overlap->value() / 100.0,
                ui->doubleSpinBox_ImgProc_Stitch_Overlap->value() / 100.0),
            "Update_ImageProcessing_StepSingle",
            "STEP_STITCH"
            "<br>VD Main: " + vVD_ImgProcSteps[STEP_PRE_LOAD_MAIN].info() +
            "<br>VD Right: " + vVD_ImgProcSteps[STEP_PRE_LOAD_RIGHT].info() +
            "<br>VD Bottom: " + vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM].info() +
            "<br>VD Bottom Right: " + vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM_RIGHT].info() +
            "<br>VD Stitched: " + vVD_ImgProcSteps[STEP_PRE_STITCH].info());
    }
        break;

    case STEP_PRE_PROJECT_Z:
    {
        ERR(D_VisDat_Proc::Dim_Project(
                &(vVD_ImgProcSteps[STEP_PRE_PROJECT_Z]),
                &(vVD_ImgProcSteps[STEP_PRE_STITCH]),
                c_DIM_Z,
                ui->comboBox_ImgProc_ProjectZ_Stat->currentIndex()),
            "Update_ImageProcessing_StepSingle",
            "STEP_PROJECT_Z");
    }
        break;

    case STEP_PCK_P0:
    {
        vector<int> v_pick_dims = {-1, -1, -1, -1, -1, 0};
        ERR(D_VisDat_Proc::Dim_Pick(
                &(vVD_ImgProcSteps[STEP_PCK_P0]),
                &(vVD_ImgProcSteps[STEP_PRE_PROJECT_Z]),
                v_pick_dims),
            "Update_ImageProcessing_StepSingle",
            "STEP_P0_PICK");
    }
        break;

    case STEP_PCK_P1:
    {
        vector<int> v_pick_dims = {-1, -1, -1, -1, -1, 1};
        ERR(D_VisDat_Proc::Dim_Pick(
                &(vVD_ImgProcSteps[STEP_PCK_P1]),
                &(vVD_ImgProcSteps[STEP_PRE_PROJECT_Z]),
                v_pick_dims),
            "Update_ImageProcessing_StepSingle",
            "STEP_P1_PICK");
    }
        break;

    case STEP_VIS_PAGES_AS_COLOR:
    {
        bool use_channels[4] = {true, true, false, false};
        ERR(D_VisDat_Proc::Channels_Merge(
                &(vVD_ImgProcSteps[STEP_VIS_PAGES_AS_COLOR]),
                &(vVD_ImgProcSteps[STEP_PCK_P1]),
                &(vVD_ImgProcSteps[STEP_PCK_P0]),
                &(vVD_ImgProcSteps[STEP_PCK_P1]),
                &(vVD_ImgProcSteps[STEP_PCK_P1]),
                3,
                use_channels),
            "Update_ImageProcessing_StepSingle",
            "STEP_PAGES_AS_COLOR");

        Overview_Update();
    }
        break;

    case STEP_NUC_P0_BLUR_MEDIAN:
    {
        ERR(D_VisDat_Proc::Filter_Stat_Circular(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_P0_BLUR_MEDIAN]),
                &(vVD_ImgProcSteps[STEP_PCK_P0]),
                ui->spinBox_ImgProc_GFP_BlurMedianSize->value(),
                c_STAT_MEDIAN,
                BORDER_REPLICATE),
            "Update_ImageProcessing_StepSingle",
            "STEP_P0_BLUR_MEDIAN");
    }
        break;

    case STEP_NUC_P0_EDGE_CV:
    {
        ERR(D_VisDat_Proc::Filter_Stat_Circular(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_P0_EDGE_CV]),
                &(vVD_ImgProcSteps[STEP_NUC_P0_BLUR_MEDIAN]),
                ui->spinBox_ImgProc_GFP_EdgeCVSize->value(),
                c_STAT_VAR_COEF_TOTAL,
                BORDER_REPLICATE),
            "Update_ImageProcessing_StepSingle",
            "STEP_P0_EDGE_CV");
    }
        break;

    case STEP_NUC_P0_BINARY_THRES:
    {
        ERR(D_VisDat_Proc::Threshold_Relative(
                &(vVD_ImgProcSteps[STEP_NUC_P0_BINARY_THRES]),
                &(vVD_ImgProcSteps[STEP_NUC_P0_EDGE_CV]),
                100.0,
                ui->doubleSpinBox_ImgProc_GFP_ThresEdges->value() / 100.0),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_P0_BINARY_THRES");
    }
        break;

    case STEP_NUC_BINARY_FILL_HOLES:
    {
        ERR(D_VisDat_Proc::Fill_Holes(
                &(vVD_ImgProcSteps[STEP_NUC_BINARY_FILL_HOLES]),
                &(vVD_ImgProcSteps[STEP_NUC_P0_BINARY_THRES])),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BINARY_FILL_HOLES");
    }
        break;

    case STEP_NUC_BINARY_AREA_SELECT:
    {
        ERR(D_VisDat_Proc::Feature_Select(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BINARY_AREA_SELECT]),
                &(vVD_ImgProcSteps[STEP_NUC_BINARY_FILL_HOLES]),
                c_FEAT_AREA,
                ui->doubleSpinBox_ImgProc_GFP_AreaMin->value(),
                ui->doubleSpinBox_ImgProc_GFP_AreaMax->value(),
                8),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BINARY_AREA_SELECT");
    }
        break;

    case STEP_NUC_DISTANCE:
    {
        ERR(D_VisDat_Proc::Transformation_Distance(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_DISTANCE]),
                &(vVD_ImgProcSteps[STEP_NUC_BINARY_AREA_SELECT]),
                CV_DIST_L2,
                CV_DIST_MASK_PRECISE),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_DISTANCE");
    }
        break;

    case STEP_NUC_SEEDS:
    {
        ERR(D_VisDat_Proc::Threshold_Relative(
                &(vVD_ImgProcSteps[STEP_NUC_SEEDS]),
                &(vVD_ImgProcSteps[STEP_NUC_DISTANCE]),
                1000.0,
                ui->doubleSpinBox_ImgProc_GFP_DistThres->value() / 1000.0),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_SEEDS");
    }
        break;

    case STEP_NUC_WATERSHED:
    {
        ERR(D_VisDat_Proc::Transformation_Watershed_Auto(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_WATERSHED]),
                &(vVD_ImgProcSteps[STEP_NUC_BINARY_AREA_SELECT]),
                &(vVD_ImgProcSteps[STEP_NUC_SEEDS]),
                ui->checkBox_ImgProc_NucWatershed_NonSeed->isChecked(),
                false,
                ui->checkBox_ImgProc_NucWatershed_ExBordered->isChecked()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_WATERSHED");
    }
        break;
    }
}

void D_MAKRO_MegaFoci::Populate_CB_AtStart()
{
    StatusSet("Populate the dropdown menus");

    Populate_CB_Single(ui->comboBox_VisTrafo_CropMode,                      QSL_VisTrafo_Crop,  c_VIS_TRAFO_CROP_DYNAMIC);
    Populate_CB_Single(ui->comboBox_VisTrafo_TransformationMode,            QSL_VisTrafo,       c_VIS_TRAFO_LOG);
    Populate_CB_Single(ui->comboBox_VisTrafo_AnchorMode,                    QSL_VisTrafo_Anchor,c_VIS_TRAFO_ANCHOR_DYNAMIC);
    Populate_CB_Single(ui->comboBox_VisTrafo_RangeMode,                     QSL_VisTrafo_Range, c_VIS_TRAFO_RANGE_DYNAMIC);

    Populate_CB_Single(ui->comboBox_ImgProc_StepShow,                       QSL_Steps,          STEP_VIS_PAGES_AS_COLOR);

    Populate_CB_Single(ui->comboBox_ImgProc_ProjectZ_Stat,                  QSL_StatList,       c_STAT_MAXIMUM);
}

void D_MAKRO_MegaFoci::Populate_CB_Single(QComboBox *CB, QStringList QSL, int init_index)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(init_index);
    CB->blockSignals(false);
}

bool D_MAKRO_MegaFoci::Load_Dataset()
{
    StatusSet("Waiting exitedly for your slection");

    //get filepaths
    QStringList QSl_Paths = QFileDialog::getOpenFileNames(
                this,
                "Load Videos",
                pStore->dir_M_MegaFoci()->path(),
                "Image Files (*.tif *.TIF *.tiff *.TIFF)");
    if(QSl_Paths.empty())
        return false;

    //set default dir
    pStore->set_dir_M_MegaFoci(QSl_Paths.first());

    //check image count vs definition of data set
    if(static_cast<size_t>(QSl_Paths.size()) != dataset_dim_mosaic_xy)
    {
        ERR(
                    ER_dim_missmatch,
                    "Load_Dataset",
                    "Dataset defined mosaic image count: " + QString::number(dataset_dim_mosaic_x) + "x" + QString::number(dataset_dim_mosaic_y) + "=<b>" + QString::number(dataset_dim_mosaic_xy) + "</b>."
                    "<br>Count of images tried to load: <b>" + QString::number(QSl_Paths.size()) + "</b>."
                    "<br>These values should match. "
                    "<br>Please try again with an image list of fitting size "
                    "<br>or adjust expected xy mosaik dimension.");
        return false;
    }

    //update state
    state_dataset_dim_set = true;

    //clear old lists
    QSL_Images_Paths.clear();
    QSL_Images_Names.clear();
    QSL_Images_Suffix.clear();
    FIL_Images.clear();

    //fill listst for easy access
    for(int f = 0; f < QSl_Paths.size(); f++)
    {
        //basics
        QString QS_Path = QSl_Paths[f];
        QFileInfo FI_Img = QFileInfo(QS_Path);
        QString QS_Name = FI_Img.baseName();
        QString QS_Suffix = FI_Img.suffix();

        //lists
        QSL_Images_Paths.append(QS_Path);
        QSL_Images_Names.append(FI_Img.baseName());
        QSL_Images_Suffix.append(FI_Img.suffix());
        FIL_Images.append(FI_Img);
    }

    //img size
    Mat MA_tmp_SizeGetter;
    ERR(
                D_Img_Proc::Load_From_Path(
                    &MA_tmp_SizeGetter,
                    FIL_Images[0]),
            "Load_Dataset",
            "Failed to load first of all images as size getter");
    dataset_dim_img_x = MA_tmp_SizeGetter.cols;
    dataset_dim_img_y = MA_tmp_SizeGetter.rows;
    dataset_type_mat = MA_tmp_SizeGetter.type();
    dataset_depth_mat = MA_tmp_SizeGetter.depth();
    MA_tmp_SizeGetter.release();

    //apply dataset ranges to ui
    ui->spinBox_Viewport_X->setMaximum(static_cast<int>(dataset_dim_mosaic_x - 1));
    ui->spinBox_Viewport_Y->setMaximum(static_cast<int>(dataset_dim_mosaic_y - 1));
    ui->spinBox_Viewport_Z->setMaximum(static_cast<int>(dataset_dim_z - 1));
    ui->spinBox_Viewport_T->setMaximum(static_cast<int>(dataset_dim_t - 1));
    ui->spinBox_OverviewBig_T->setMaximum(static_cast<int>(dataset_dim_t - 1));
    ui->horizontalSlider_OverviewBig_T->setMaximum(static_cast<int>(dataset_dim_t - 1));
    ui->spinBox_Viewport_P->setMaximum(static_cast<int>(dataset_dim_p - 1));

    //update ui accesibility
    ui->groupBox_Dataset->setEnabled(false);
    ui->groupBox_Viewport->setEnabled(true);
    ui->groupBox_VisTrafo->setEnabled(true);
    ui->groupBox_View->setEnabled(true);
    ui->groupBox_Control->setEnabled(true);
    ui->tabWidget_Control->setCurrentIndex(TAB_CONTROL_IMG_PROC);

    //update states
    state_dataset_img_list_loaded = true;
    StatusSet("Dataset is valid :-)");

    //Init Overview
    Overview_Init();

    //update proc and image
    StatusSet("Now updating ImgProc for the 1st time");
    Update_ImageProcessing_CurrentImage();

    //return
    return true;
}

void D_MAKRO_MegaFoci::Overview_Init()
{
    if(!state_dataset_dim_set)
        return;

    StatusSet("Init overview for better orientation");

    //get scale of overview
    overview_scale = ui->doubleSpinBox_OverviewQuality->value() / 100.0;
    overview_SubImgSizeX = static_cast<size_t>(dataset_dim_img_x * overview_scale);
    overview_SubImgSizeY = static_cast<size_t>(dataset_dim_img_y * overview_scale);

    if(overview_SubImgSizeX < 1 || overview_SubImgSizeY < 1)
    {
        StatusSet("Failed to init overview (too small)");
        return;
    }

    //init overview
    VD_Overview_Save = D_VisDat_Obj(
                D_VisDat_Dim(
                    static_cast<int>(dataset_dim_mosaic_x * overview_SubImgSizeX),
                    static_cast<int>(dataset_dim_mosaic_x * overview_SubImgSizeY),
                    1,
                    static_cast<int>(dataset_dim_t),
                    1,
                    1),
                CV_64FC3,
                0);
    state_overview_init = true;

}

void D_MAKRO_MegaFoci::Overview_Update()
{
    if(!state_overview_init || !state_dataset_dim_set)
        return;

    //scale down
    D_VisDat_Obj VD_tmp_CurrentColorScaled;
    ERR(D_VisDat_Proc::Scale_ToSize(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &VD_tmp_CurrentColorScaled,
                &(vVD_ImgProcSteps[STEP_VIS_PAGES_AS_COLOR]),
                static_cast<int>(overview_SubImgSizeX * (1.0 + ui->doubleSpinBox_ImgProc_Stitch_Border->value() / 100.0)),
                static_cast<int>(overview_SubImgSizeY * (1.0 + ui->doubleSpinBox_ImgProc_Stitch_Border->value() / 100.0))),
        "Overview_Update",
        "D_VisDat_Proc::Scale_ToSize");

    //calc target offset
    vector<int> vOffset(c_DIM_NUMBER_OF, 0);
    vOffset[c_DIM_X] = static_cast<int>(ui->spinBox_Viewport_X->value() * overview_SubImgSizeX);
    vOffset[c_DIM_Y] = static_cast<int>(ui->spinBox_Viewport_Y->value() * overview_SubImgSizeY);
    vOffset[c_DIM_T] = ui->spinBox_Viewport_T->value();

    //insert in overview
    ERR(D_VisDat_Proc::Instert_atPos(
                &VD_Overview_Save,
                &VD_tmp_CurrentColorScaled,
                vOffset),
        "Overview_Update",
        "D_VisDat_Proc::Instert_atPos"
        "<br>VD_Overview_Save " + VD_Overview_Save.info() +
        "<br>VD_tmp_CurrentColorScaled " + VD_tmp_CurrentColorScaled.info());

    Update_Images_OverviewSmall();
    if(ui->tabWidget_Control->currentIndex() == TAB_CONTROL_OVERVIEW_BIG)
        Update_Images_OverviewBig();
}

bool D_MAKRO_MegaFoci::LoadShow_Image_UiSelected()
{
    qDebug() << "LoadShow_Image_UiSelected";
    if(Load_Image_UiSelected(&MA_Show))
    {
        Update_Images();
        return true;
    }
    else
    {
        qDebug() << "LoadShow_Image_UiSelected" << "Loading Image failed";
        return false;
    }
}

int D_MAKRO_MegaFoci::Load_Image_full_ZP_Stitched_UiSelected(D_VisDat_Obj *pVD_Target)
{
    return Load_Image_full_ZP_Stitched(
                pVD_Target,
                ui->spinBox_Viewport_X->value(),
                ui->spinBox_Viewport_Y->value(),
                ui->spinBox_Viewport_T->value());
}

bool D_MAKRO_MegaFoci::Load_Image_UiSelected(Mat *pMA_Target)
{
    return Load_Image(
                pMA_Target,
                ui->spinBox_Viewport_X->value(),
                ui->spinBox_Viewport_Y->value(),
                ui->spinBox_Viewport_Z->value(),
                ui->spinBox_Viewport_T->value(),
                ui->spinBox_Viewport_P->value());
}

bool D_MAKRO_MegaFoci::Load_Image(Mat *pMA_Target, size_t x, size_t y, size_t z, size_t t, size_t p)
{
    qDebug() << "Load_Image" << "x" << x << "y" << y << "z" << z << "t" << t << "p" << p << "--> file" << get_index_of_image(x, y) << "page" << get_index_of_page(z, t, p);

    int ER = D_Img_Proc::Load_From_Path_Multi(
                pMA_Target,
                FIL_Images[static_cast<int>(get_index_of_image(x, y))].absoluteFilePath(),
                static_cast<int>(get_index_of_page(z, t, p) + 1));

    if(ER != ER_okay)
    {
        ERR(
                    ER,
                    "Load_Image",
                    "D_Img_Proc::Load_From_Path_Multi"
                    "<br>x:    " + QString::number(x) +
                    "<br>y:    " + QString::number(y) +
                    "<br>z:    " + QString::number(z) +
                    "<br>t:    " + QString::number(t) +
                    "<br>p:    " + QString::number(p) +
                    "<br>file: " + QString::number(get_index_of_image(x, y)) +
                    "<br>page: " + QString::number(get_index_of_page(z, t, p)));
        return false;
    }
    else
        return true;
}

int D_MAKRO_MegaFoci::Load_Image_full_ZP(D_VisDat_Obj *pVD_Target, size_t x, size_t y, size_t t)
{
    //slices needed
    vector<D_VisDat_Slice_2D> v2D_SlicesTarget;
    vector<int> vI_PageSource;

    //Loop z and p to get indices of all needed images
    for(size_t z = 0; z < dataset_dim_z; z++)
        for(size_t p = 0; p < dataset_dim_p; p++)
        {
            v2D_SlicesTarget.push_back(D_VisDat_Slice_2D(-1, -1, static_cast<int>(z), 0, 0, static_cast<int>(p)));
            vI_PageSource.push_back(static_cast<int>(get_index_of_page(static_cast<int>(z), static_cast<int>(t), static_cast<int>(p))));
        }

    return D_VisDat_Proc::Create_VD_PageVector_or0(
                pVD_Target,
                FIL_Images[static_cast<int>(get_index_of_image(x, y))],
                D_VisDat_Dim(
                    static_cast<int>(dataset_dim_img_x),
                    static_cast<int>(dataset_dim_img_y),
                    static_cast<int>(dataset_dim_z),
                    1,
                    1,
                    static_cast<int>(dataset_dim_p)),
                vI_PageSource,
                v2D_SlicesTarget,
                c_DIM_X,
                c_DIM_Y,
                x >= dataset_dim_mosaic_x || y >= dataset_dim_mosaic_y || t >= dataset_dim_t,
                dataset_type_mat);
}

int D_MAKRO_MegaFoci::Load_Image_full_ZP_Stitched(D_VisDat_Obj *pVD_Target, size_t x, size_t y, size_t t)
{
    //Load TL
    D_VisDat_Obj VD_tmp_TL;
    if(Load_Image_full_ZP(&VD_tmp_TL, x, y, t) != ER_okay)
        return false;

    //Load TR
    D_VisDat_Obj VD_tmp_TR;
    if(x < dataset_dim_mosaic_x)
    {
        if(Load_Image_full_ZP(&VD_tmp_TR, x + 1, y, t) != ER_okay)
            return false;
    }
    else
        VD_tmp_TR = D_VisDat_Obj(VD_tmp_TL.Dim(), VD_tmp_TL.type(), 0);

    //Load TR
    D_VisDat_Obj VD_tmp_BL;
    if(y < dataset_dim_mosaic_y)
    {
        if(Load_Image_full_ZP(&VD_tmp_BL, x, y + 1, t) != ER_okay)
            return false;
    }
    else
        VD_tmp_BL = D_VisDat_Obj(VD_tmp_TL.Dim(), VD_tmp_TL.type(), 0);

    //Load TR
    D_VisDat_Obj VD_tmp_BR;
    if(x < dataset_dim_mosaic_x || y < dataset_dim_mosaic_y)
    {
        if(Load_Image_full_ZP(&VD_tmp_BR, x + 1, y + 1, t) != ER_okay)
            return false;
    }
    else
        VD_tmp_BR = D_VisDat_Obj(VD_tmp_TL.Dim(), VD_tmp_TL.type(), 0);

    //Stitch
    int ER = D_VisDat_Proc::Stitch_Border_rel(
                D_VisDat_Slicing(c_SLICE_2D_XZ),
                pVD_Target,
                &VD_tmp_TL,
                &VD_tmp_TR,
                &VD_tmp_BL,
                &VD_tmp_BR,
                ui->doubleSpinBox_ImgProc_Stitch_Border->value()/100.0,
                ui->doubleSpinBox_ImgProc_Stitch_Border->value()/100.0,
                ui->doubleSpinBox_ImgProc_Stitch_Overlap->value()/100.0,
                ui->doubleSpinBox_ImgProc_Stitch_Overlap->value()/100.0,
                Stitcher::Mode::SCANS);

    if(ER != ER_okay)
        ERR(ER, "Load_Image_full_ZP_Stitched", "Stitch_Border_rel");

    return ER;
}

void D_MAKRO_MegaFoci::StatusSet(QString NewStatus)
{
    QSL_Status.append("[" + QDateTime::currentDateTime().time().toString() + "] " + NewStatus);
    if(QSL_Status.size() > status_EntryNumber)
        QSL_Status.pop_front();

    QString QS_Status;
    for(int s = 0; s < QSL_Status.size(); s++)
    {
        if(s != 0)
            QS_Status.append("\n");
        QS_Status.append(QSL_Status[s]);
    }

    ui->plainTextEdit_Status->setPlainText(QS_Status);
    ui->plainTextEdit_Status->verticalScrollBar()->setValue(ui->plainTextEdit_Status->verticalScrollBar()->maximum());
    ui->plainTextEdit_Status->repaint();
    qApp->processEvents();
}

void D_MAKRO_MegaFoci::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_MAKRO_MegaFoci", func, detail);
    if(err != ER_okay)
        StatusSet("ERROR " + QSL_Errors[err] + "Function:" + func + "Detail: " + detail);
}

size_t D_MAKRO_MegaFoci::get_index_of_image(size_t x, size_t y)
{
    size_t idx_yx = dataset_dim_mosaic_x * y + x;
    return idx_yx < dataset_dim_mosaic_xy ? idx_yx : 0;
}

size_t D_MAKRO_MegaFoci::get_index_of_page(size_t z, size_t t, size_t p)
{
    size_t idx_tzp = t * dataset_dim_z * dataset_dim_p + z * dataset_dim_p + p;
    return idx_tzp < dataset_dim_mosaic_xy ? idx_tzp : 0;
}


void D_MAKRO_MegaFoci::on_comboBox_VisTrafo_CropMode_currentIndexChanged(int index)
{
    ui->doubleSpinBox_VisTrafo_CropMin->setEnabled(index == c_VIS_TRAFO_CROP_FIXED);
    ui->doubleSpinBox_VisTrafo_CropMax->setEnabled(index == c_VIS_TRAFO_CROP_FIXED);
}

void D_MAKRO_MegaFoci::on_comboBox_VisTrafo_TransformationMode_currentIndexChanged(int index)
{
    ui->doubleSpinBox_VisTrafo_Gamma->setEnabled(index == c_VIS_TRAFO_GAMMA);
    ui->doubleSpinBox_VisTrafo_LogCenter->setEnabled(index == c_VIS_TRAFO_LOG);
    ui->doubleSpinBox_VisTrafo_LogDivisor->setEnabled(index == c_VIS_TRAFO_LOG);
}

void D_MAKRO_MegaFoci::on_comboBox_VisTrafo_AnchorMode_currentIndexChanged(int index)
{
    ui->doubleSpinBox_VisTrafo_Anchor->setEnabled(index != c_VIS_TRAFO_ANCHOR_DYNAMIC);
}

void D_MAKRO_MegaFoci::on_comboBox_VisTrafo_RangeMode_currentIndexChanged(int index)
{
    ui->doubleSpinBox_VisTrafo_Range->setEnabled(index != c_VIS_TRAFO_RANGE_DYNAMIC);
}

void D_MAKRO_MegaFoci::on_comboBox_ImgProc_StepShow_currentIndexChanged(int index)
{
    ui->spinBox_Viewport_Z->setEnabled(index < STEP_PRE_PROJECT_Z);
    ui->spinBox_Viewport_P->setEnabled(index < STEP_PCK_P0);

    L_SB_InfoVD->setText(vVD_ImgProcSteps[index].info_short());
    Update_Images_Proc();
}

void D_MAKRO_MegaFoci::on_spinBox_Viewport_P_valueChanged(int arg1)
{
    if(static_cast<size_t>(arg1) < dataset_dim_p)
        ui->spinBox_Viewport_P->setSuffix(" (" + QSL_Pages[arg1] + ")");
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Stitch_Border_valueChanged(double arg1)
{
    arg1;
    Update_ImageProcessing_StepFrom(STEP_PRE_STITCH);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Stitch_Overlap_valueChanged(double arg1)
{
    arg1;
    Update_ImageProcessing_StepFrom(STEP_PRE_STITCH);
}

void D_MAKRO_MegaFoci::on_comboBox_ImgProc_ProjectZ_Stat_currentIndexChanged(int index)
{
    index;
    Update_ImageProcessing_StepFrom(STEP_PRE_PROJECT_Z);
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_GFP_BlurMedianSize_valueChanged(int arg1)
{
    if(arg1 % 2)
        Update_ImageProcessing_StepFrom(STEP_NUC_P0_BLUR_MEDIAN);
    else
        ui->spinBox_ImgProc_GFP_BlurMedianSize->setValue(arg1 + 1);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_GFP_ThresEdges_valueChanged(double arg1)
{
    arg1;
    Update_ImageProcessing_StepFrom(STEP_NUC_P0_BINARY_THRES);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_GFP_AreaMin_valueChanged(double arg1)
{
    if(arg1 > ui->doubleSpinBox_ImgProc_GFP_AreaMax->value())
        ui->doubleSpinBox_ImgProc_GFP_AreaMax->setValue(arg1);
    else
        Update_ImageProcessing_StepFrom(STEP_NUC_BINARY_AREA_SELECT);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_GFP_AreaMax_valueChanged(double arg1)
{
    if(arg1 < ui->doubleSpinBox_ImgProc_GFP_AreaMin->value())
        ui->doubleSpinBox_ImgProc_GFP_AreaMin->setValue(arg1);
    else
        Update_ImageProcessing_StepFrom(STEP_NUC_BINARY_AREA_SELECT);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_GFP_DistThres_valueChanged(double arg1)
{
    arg1;
    Update_ImageProcessing_StepFrom(STEP_NUC_DISTANCE);
}

void D_MAKRO_MegaFoci::on_checkBox_ImgProc_NucWatershed_NonSeed_clicked()
{
    Update_ImageProcessing_StepFrom(STEP_NUC_WATERSHED);
}

void D_MAKRO_MegaFoci::on_checkBox_ImgProc_NucWatershed_ExBordered_clicked()
{
    Update_ImageProcessing_StepFrom(STEP_NUC_WATERSHED);
}

void D_MAKRO_MegaFoci::on_tabWidget_Control_currentChanged(int index)
{
    switch (index) {

    case TAB_CONTROL_IMG_PROC:
    {
        ui->stackedWidget_View->setCurrentIndex(VIEW_PAGE_IMG_PROC);
        Update_Images_Proc();
        Update_Views();
    }
        break;

    case TAB_CONTROL_OVERVIEW_BIG:
    {
        ui->stackedWidget_View->setCurrentIndex(VIEW_PAGE_OVERVIEW_BIG);
        Update_Images_OverviewBig();
        Update_Views();
    }
        break;

    }
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Nuc_AreaMin_valueChanged(double arg1)
{
    if(arg1 > ui->doubleSpinBox_ImgProc_Nuc_AreaMax->value())
        ui->doubleSpinBox_ImgProc_Nuc_AreaMax->setValue(arg1);
    else
        Update_ImageProcessing_StepFrom(STEP_NUC_SELECT_AREA);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Nuc_AreaMax_valueChanged(double arg1)
{
    if(arg1 < ui->doubleSpinBox_ImgProc_Nuc_AreaMin->value())
        ui->doubleSpinBox_ImgProc_Nuc_AreaMin->setValue(arg1);
    else
        Update_ImageProcessing_StepFrom(STEP_NUC_SELECT_AREA);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Nuc_RFP_SignalMeanMin_valueChanged(double arg1)
{
    arg1;
    Update_ImageProcessing_StepFrom(STEP_NUC_P1_SELECT_MEAN);
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Foc_BlurMedianSize_valueChanged(int arg1)
{
    arg1;
    Update_ImageProcessing_StepFrom(STEP_FOC_P0_BLUR_MEDIAN);
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Foc_BinarySize_valueChanged(int arg1)
{
    arg1;
    Update_ImageProcessing_StepFrom(STEP_FOC_P0_BINARY_THRES);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_BinaryOffset_valueChanged(double arg1)
{
    arg1;
    Update_ImageProcessing_StepFrom(STEP_FOC_P0_BINARY_THRES);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_AreaMin_valueChanged(double arg1)
{
    if(arg1 > ui->doubleSpinBox_ImgProc_Foc_AreaMax->value())
        ui->doubleSpinBox_ImgProc_Foc_AreaMax->setValue(arg1);
    else
        Update_ImageProcessing_StepFrom(STEP_FOC_SELECT_AREA);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_AreaMax_valueChanged(double arg1)
{
    if(arg1 < ui->doubleSpinBox_ImgProc_Foc_AreaMin->value())
        ui->doubleSpinBox_ImgProc_Foc_AreaMin->setValue(arg1);
    else
        Update_ImageProcessing_StepFrom(STEP_FOC_SELECT_AREA);
}
