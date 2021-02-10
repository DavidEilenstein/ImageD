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
    ///Setup Ui
    ui->setupUi(this);

    ///Pointer to storeage
    pStore = pStorage;

    ///Init images
    MA_Show = pStore->get_Adress(0)->clone();
    MA_OverviewSmall_Show = pStore->get_Adress(0)->clone();
    MA_OverviewBig_Show = pStore->get_Adress(0)->clone();
    VD_Show = pStore->get_VD(0);
    VD_Overview_Save = pStore->get_VD(0);

    //img proc
    vVD_ImgProcSteps.resize(STEP_NUMBER_OF);
    for(int s = 0; s < STEP_NUMBER_OF; s++)
        vVD_ImgProcSteps[s] = pStore->get_VD(0);

    ///init GraphicsView
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

    ///set up statusbar
    L_SB_ValueAtCursor = new QLabel(this);
    L_SB_ValueAtCursor->setToolTip("Value under current cursor position");
    ui->statusbar->addPermanentWidget(L_SB_ValueAtCursor);

    L_SB_InfoVD = new QLabel(this);
    L_SB_InfoVD->setToolTip("Info about current VisDat");
    ui->statusbar->addPermanentWidget(L_SB_InfoVD);

    ///connects
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
    connect(ui->spinBox_DataDim_P_used,                     SIGNAL(valueChanged(int)),                  this,               SLOT(Update_PagesConfig()));
    connect(ui->spinBox_DataDim_P_exist,                    SIGNAL(valueChanged(int)),                  this,               SLOT(Update_PagesConfig()));
    connect(ui->spinBox_PageIndex_GFP,                      SIGNAL(valueChanged(int)),                  this,               SLOT(Update_PagesConfig()));
    connect(ui->spinBox_PageIndex_RFP,                      SIGNAL(valueChanged(int)),                  this,               SLOT(Update_PagesConfig()));
    connect(ui->spinBox_PageIndex_Other,                    SIGNAL(valueChanged(int)),                  this,               SLOT(Update_PagesConfig()));
    //overview big
    connect(ui->spinBox_OverviewBig_T,                      SIGNAL(valueChanged(int)),                  this,               SLOT(Update_Images_OverviewBig()));

    //stack
    connect(ui->pushButton_ProcFullStack,                   SIGNAL(clicked(bool)),                      this,               SLOT(Stack_Process_All()));


    ///do stuff to do on start
    this->showMaximized();
    StatusSet("Started this awesome piece of software");
    Update_Views();
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    setWindowTitle("ImageD - Monster Image Handler and Foci Detector (suggestions for a better name are welcome)");
    Populate_CB_AtStart();

    ///update ui accesibility
    ui->groupBox_Dataset->setEnabled(true);
    ui->groupBox_Viewport->setEnabled(false);
    ui->groupBox_VisTrafo->setEnabled(false);
    ui->groupBox_View->setEnabled(false);
    ui->groupBox_Control->setEnabled(false);

    ///set default indices
    ui->tabWidget_Control->setCurrentIndex(TAB_CONTROL_IMG_PROC);
    ui->stackedWidget_View->setCurrentIndex(VIEW_PAGE_IMG_PROC);

    ///get dataset attributes
    /*
    set_dataset_dim_x(ui->spinBox_DataDim_X->value());
    set_dataset_dim_y(ui->spinBox_DataDim_Y->value());
    set_dataset_dim_z(ui->spinBox_DataDim_Z->value());
    set_dataset_dim_t(ui->spinBox_DataDim_T->value());
    set_dataset_dim_p_used(ui->spinBox_DataDim_P_used->value());
    set_dataset_dim_p_exist(ui->spinBox_DataDim_P_exist->value());
    set_index_GFP(ui->spinBox_PageIndex_GFP->value());
    set_index_RFP(ui->spinBox_PageIndex_RFP->value());
    Update_PageIndexNames();
    */

    ///start status
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

    //start time measurement
    QElapsedTimer timer_img_proc;
    timer_img_proc.start();

    //proc all steps
    Update_ImageProcessing_StepFrom(0);

    //measure time
    time_LastSingleImgProc = timer_img_proc.elapsed();
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepFrom(size_t step_start)
{
    if(!state_dataset_img_list_loaded)
        return;

    for(size_t s = step_start; s < STEP_NUMBER_OF; s++)
    {
        Update_ImageProcessing_StepSingle(s);

        if(state_stack_processing || state_first_proc_on_start)
        {
            ui->comboBox_ImgProc_StepShow->setCurrentIndex(static_cast<int>(s));
            Update_Ui();
        }
    }

    Update_ImageDecomposition();

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

    //reset states
    state_image_decomposed = false;

    //select step to do
    StatusSet("ImgProc: " + QSL_Steps[static_cast<int>(step)]);
    switch (step) {

    //Preparation -------------------------------------------------------------------------------------------------------

    case STEP_PRE_LOAD_MAIN:
    {
        size_t index_source_x = dataset_pos_x;
        size_t index_source_y = dataset_pos_y;
        size_t index_source_t = dataset_pos_t;

        if(index_source_x == index_old_TR_x_mosaic && index_source_y == index_old_TR_y_mosaic && index_source_t == index_old_TR_t)
            vVD_ImgProcSteps[STEP_PRE_LOAD_MAIN] = vVD_ImgProcSteps[STEP_PRE_LOAD_RIGHT];
        else if(index_source_x == index_old_BR_x_mosaic && index_source_y == index_old_BR_y_mosaic && index_source_t == index_old_BR_t)
            vVD_ImgProcSteps[STEP_PRE_LOAD_MAIN] = vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM_RIGHT];
        else if(index_source_x == index_old_TL_x_mosaic && index_source_y == index_old_TL_y_mosaic && index_source_t == index_old_TL_t)
            break;
        else if(index_source_x == index_old_BL_x_mosaic && index_source_y == index_old_BL_y_mosaic && index_source_t == index_old_BL_t)
            vVD_ImgProcSteps[STEP_PRE_LOAD_MAIN] = vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM];
        else
            ERR(Load_Image_full_ZP(
                    &(vVD_ImgProcSteps[STEP_PRE_LOAD_MAIN]),
                    index_source_x,
                    index_source_y,
                    index_source_t),
                "Update_ImageProcessing_StepSingle",
                "STEP_PRE_LOAD_MAIN - Load main image");

        //remember this image's position to maybe use it in next iteration if indeces fit
        index_old_TL_x_mosaic   = index_source_x;
        index_old_TL_y_mosaic   = index_source_y;
        index_old_TL_t          = index_source_t;
    }
        break;

    case STEP_PRE_LOAD_RIGHT:
    {
        size_t index_source_x = dataset_pos_x + 1;
        size_t index_source_y = dataset_pos_y;
        size_t index_source_t = dataset_pos_t;

        if(index_source_x == index_old_TR_x_mosaic && index_source_y == index_old_TR_y_mosaic && index_source_t == index_old_TR_t)
            break;
        else if(index_source_x == index_old_BR_x_mosaic && index_source_y == index_old_BR_y_mosaic && index_source_t == index_old_BR_t)
            vVD_ImgProcSteps[STEP_PRE_LOAD_MAIN] = vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM_RIGHT];
        else if(index_source_x == index_old_BL_x_mosaic && index_source_y == index_old_BL_y_mosaic && index_source_t == index_old_BL_t)
            vVD_ImgProcSteps[STEP_PRE_LOAD_MAIN] = vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM];
        else
            ERR(Load_Image_full_ZP(
                    &(vVD_ImgProcSteps[STEP_PRE_LOAD_RIGHT]),
                    index_source_x,
                    index_source_y,
                    index_source_t),
                "Update_ImageProcessing_StepSingle",
                "STEP_PRE_LOAD_RIGHT - Load border image right");

        //remember this image's position to maybe use it in next iteration if indeces fit
        index_old_TR_x_mosaic   = index_source_x;
        index_old_TR_y_mosaic   = index_source_y;
        index_old_TR_t          = index_source_t;
    }
        break;

    case STEP_PRE_LOAD_BOTTOM:
    {
        size_t index_source_x = dataset_pos_x;
        size_t index_source_y = dataset_pos_y + 1;
        size_t index_source_t = dataset_pos_t;

        if(index_source_x == index_old_BR_x_mosaic && index_source_y == index_old_BR_y_mosaic && index_source_t == index_old_BR_t)
            vVD_ImgProcSteps[STEP_PRE_LOAD_MAIN] = vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM_RIGHT];
        else if(index_source_x == index_old_BL_x_mosaic && index_source_y == index_old_BL_y_mosaic && index_source_t == index_old_BL_t)
            break;
        else
            ERR(Load_Image_full_ZP(
                    &(vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM]),
                    index_source_x,
                    index_source_y,
                    index_source_t),
                "Update_ImageProcessing_StepSingle",
                "STEP_PRE_LOAD_BOTTOM - Load border image bottom");

        //remember this image's position to maybe use it in next iteration if indeces fit
        index_old_BL_x_mosaic   = index_source_x;
        index_old_BL_y_mosaic   = index_source_y;
        index_old_BL_t          = index_source_t;
    }
        break;

    case STEP_PRE_LOAD_BOTTOM_RIGHT:
    {
        size_t index_source_x = dataset_pos_x + 1;
        size_t index_source_y = dataset_pos_y + 1;
        size_t index_source_t = dataset_pos_t;

        if(index_source_x == index_old_BR_x_mosaic && index_source_y == index_old_BR_y_mosaic && index_source_t == index_old_BR_t)
            break;
        else
            ERR(Load_Image_full_ZP(
                    &(vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM_RIGHT]),
                    index_source_x,
                    index_source_y,
                    index_source_t),
                "Update_ImageProcessing_StepSingle",
                "STEP_PRE_LOAD_BOTTOM_RIGHT - Load border image bottom right");

        //remember this image's position to maybe use it in next iteration if indeces fit
        index_old_BR_x_mosaic   = index_source_x;
        index_old_BR_y_mosaic   = index_source_y;
        index_old_BR_t          = index_source_t;
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
            "STEP_PRE_STITCH - Stitching 4 images"
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
                ui->comboBox_ImgProc_ProjectZ_Stat->currentIndex(),
                CV_16UC1),
            "Update_ImageProcessing_StepSingle",
            "STEP_PRE_PROJECT_Z - Project Z-dimension to get a 2D image");
    }
        break;

    //Pick channels -------------------------------------------------------------------------------------------------------

    case STEP_PCK_OTHER:
    {
        if(dataset_dim_p_exist > 2)
        {
            vector<int> v_pick_dims(c_DIM_NUMBER_OF, -1);
            v_pick_dims[c_DIM_P] = index_page_other;
            ERR(D_VisDat_Proc::Dim_Pick(
                    &(vVD_ImgProcSteps[STEP_PCK_OTHER]),
                    &(vVD_ImgProcSteps[STEP_PRE_PROJECT_Z]),
                    v_pick_dims),
                "Update_ImageProcessing_StepSingle",
                "STEP_PCK_OTHER - Pick other signal");
        }
        else
        {
            //size
            D_VisDat_Dim dim = vVD_ImgProcSteps[STEP_PRE_PROJECT_Z].Dim();
            dim.set_size_P(1);

            //zeros
            ERR(D_VisDat_Proc::Create_VD_Single_Constant(
                    &(vVD_ImgProcSteps[STEP_PCK_OTHER]),
                    dim,
                    vVD_ImgProcSteps[STEP_PRE_PROJECT_Z].type(),
                    0),
                "Update_ImageProcessing_StepSingle",
                "STEP_PCK_OTHER - Init with 0");
        }
    }
        break;

    case STEP_PCK_GFP:
    {
        vector<int> v_pick_dims(c_DIM_NUMBER_OF, -1);
        v_pick_dims[c_DIM_P] = index_GFP;
        ERR(D_VisDat_Proc::Dim_Pick(
                &(vVD_ImgProcSteps[STEP_PCK_GFP]),
                &(vVD_ImgProcSteps[STEP_PRE_PROJECT_Z]),
                v_pick_dims),
            "Update_ImageProcessing_StepSingle",
            "STEP_PCK_GFP - Pick GFP signal");
    }
        break;

    case STEP_PCK_RFP:
    {
        vector<int> v_pick_dims(c_DIM_NUMBER_OF, -1);
        v_pick_dims[c_DIM_P] = index_RFP;
        ERR(D_VisDat_Proc::Dim_Pick(
                &(vVD_ImgProcSteps[STEP_PCK_RFP]),
                &(vVD_ImgProcSteps[STEP_PRE_PROJECT_Z]),
                v_pick_dims),
            "Update_ImageProcessing_StepSingle",
            "STEP_PCK_RFP - Pick RFP signal");
    }
        break;

    //Visualtsation -------------------------------------------------------------------------------------------------------

    case STEP_VIS_PAGES_AS_COLOR:
    {
        bool use_channels[4] = {true, true, false, false};
        ERR(D_VisDat_Proc::Channels_Merge(
                &(vVD_ImgProcSteps[STEP_VIS_PAGES_AS_COLOR]),
                &(vVD_ImgProcSteps[STEP_PCK_RFP]),
                &(vVD_ImgProcSteps[STEP_PCK_GFP]),
                &(vVD_ImgProcSteps[STEP_PCK_RFP]),
                &(vVD_ImgProcSteps[STEP_PCK_RFP]),
                3,
                use_channels),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_PAGES_AS_COLOR - Visualize signals in color");

        Overview_Update();
    }
        break;

    //Find Nuclei -------------------------------------------------------------------------------------------------------

    case STEP_NUC_GFP_BLUR_MEDIAN:
    {
        ERR(D_VisDat_Proc::Filter_Median_Circular(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_BLUR_MEDIAN]),
                &(vVD_ImgProcSteps[STEP_PCK_GFP]),
                ui->spinBox_ImgProc_Nuc_GFP_BlurMedianSize->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_BLUR_MEDIAN - Strong median blur GFP to get nuclei\n" + vVD_ImgProcSteps[STEP_PCK_GFP].info());
    }
        break;

    case STEP_NUC_GFP_EDGE_CV:
    {
        ERR(D_VisDat_Proc::Filter_Stat_Circular(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_EDGE_CV]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_BLUR_MEDIAN]),
                ui->spinBox_ImgProc_Nuc_GFP_EdgeCVSize->value(),
                c_STAT_VAR_COEF_TOTAL,
                BORDER_REPLICATE),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_EDGE_CV - Calc local coefficient of variance to get borders");
    }
        break;

    case STEP_NUC_GFP_BINARY_THRES:
    {
        ERR(D_VisDat_Proc::Threshold_Relative(
                &(vVD_ImgProcSteps[STEP_NUC_GFP_BINARY_THRES]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_EDGE_CV]),
                100.0,
                ui->doubleSpinBox_ImgProc_Nuc_GFP_ThresEdges->value() / 100.0),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_BINARY_THRES - Threshold coefficient of variance to get binary borders");
    }
        break;

    case STEP_NUC_GFP_BINARY_FILL_HOLES:
    {
        ERR(D_VisDat_Proc::Fill_Holes(
                &(vVD_ImgProcSteps[STEP_NUC_GFP_BINARY_FILL_HOLES]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_BINARY_THRES])),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_BINARY_FILL_HOLES - Fill holes to make borders become approximate nuclei areas");
    }
        break;

    case STEP_NUC_GFP_BINARY_MORPH_ERODE:
    {
        ERR(D_VisDat_Proc::Morphology_Elemental(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_BINARY_MORPH_ERODE]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_BINARY_FILL_HOLES]),
                MORPH_ERODE,
                MORPH_ELLIPSE,
                ui->spinBox_ImgProc_Nuc_ErodeBorder->value(),
                ui->spinBox_ImgProc_Nuc_ErodeBorder->value(),
                BORDER_DEFAULT,
                1),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_BINARY_MORPH_ERODE - Erode border caused by previous filters");
    }
        break;

    case STEP_NUC_DISTANCE:
    {
        ERR(D_VisDat_Proc::Transformation_Distance(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_DISTANCE]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_BINARY_MORPH_ERODE]),
                CV_DIST_L2,
                CV_DIST_MASK_PRECISE),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_DISTANCE - Distance transform of nuclei candidates");
    }
        break;

    case STEP_NUC_SEEDS:
    {
        ERR(D_VisDat_Proc::Threshold_Relative(
                &(vVD_ImgProcSteps[STEP_NUC_SEEDS]),
                &(vVD_ImgProcSteps[STEP_NUC_DISTANCE]),
                1000.0,
                ui->doubleSpinBox_ImgProc_Nuc_GFP_DistThres->value() / 1000.0),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_SEEDS - Threshold nuclei distance image to get nuclei segmentation seeds");
    }
        break;

    case STEP_NUC_WATERSHED:
    {
        ERR(D_VisDat_Proc::Transformation_Watershed_Auto(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_WATERSHED]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_BINARY_MORPH_ERODE]),
                &(vVD_ImgProcSteps[STEP_NUC_SEEDS]),
                ui->checkBox_ImgProc_Nuc_Watershed_NonSeed->isChecked(),
                false,
                ui->checkBox_ImgProc_Nuc_Watershed_ExBordered->isChecked()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_WATERSHED - Watershed transformation to separate nuclei candidates");
    }
        break;

    case STEP_NUC_SELECT_AREA:
    {
        ERR(D_VisDat_Proc::Feature_Select(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_SELECT_AREA]),
                &(vVD_ImgProcSteps[STEP_NUC_WATERSHED]),
                c_FEAT_AREA,
                ui->doubleSpinBox_ImgProc_Nuc_AreaMin->value(),
                ui->doubleSpinBox_ImgProc_Nuc_AreaMax->value(),
                8),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_SELECT_AREA - Select nuclei candidates by area");
    }
        break;

    case STEP_NUC_SELECT_ROUNDNESS:
    {
        ERR(D_VisDat_Proc::Feature_Select(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_SELECT_ROUNDNESS]),
                &(vVD_ImgProcSteps[STEP_NUC_SELECT_AREA]),
                c_FEAT_AREA,
                ui->doubleSpinBox_ImgProc_Nuc_AreaMin->value(),
                ui->doubleSpinBox_ImgProc_Nuc_AreaMax->value(),
                8),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_SELECT_ROUNDNESS - Select nuclei candidates by roundness");
    }
        break;

    case STEP_NUC_RFP_SELECT_MEAN:
    {
        ERR(D_VisDat_Proc::Copy( // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! TO DO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Replace with value in blob filter function
                &(vVD_ImgProcSteps[STEP_NUC_RFP_SELECT_MEAN]),
                &(vVD_ImgProcSteps[STEP_NUC_SELECT_ROUNDNESS])),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_RFP_SELECT_MEAN - Select only nuclei with high enough signal in RFP");
    }
        break;

    case STEP_VIS_NUC_BORDERS:
    {
        ERR(D_VisDat_Proc::Geometric_Reduce(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_VIS_NUC_BORDERS]),
                &(vVD_ImgProcSteps[STEP_NUC_RFP_SELECT_MEAN]),
                c_GEO_OUTLINE,
                4,
                3,
                255),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_NUC_BORDERS - Reduce nulei to borders");
    }
        break;

    //Find Foci GFP -------------------------------------------------------------------------------------------------------

    case STEP_FOC_GFP_BLUR_MEDIAN:
    {
        ERR(D_VisDat_Proc::Filter_Median_Circular(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_FOC_GFP_BLUR_MEDIAN]),
                &(vVD_ImgProcSteps[STEP_PCK_GFP]),
                ui->spinBox_ImgProc_Foc_GFP_BlurMedianSize->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_FOC_GFP_BLUR_MEDIAN - Median blur GFP in order to get foci");
    }
        break;

    case STEP_FOC_GFP_BINARY_THRES:
    {
        ERR(D_VisDat_Proc::Threshold_Adaptive_Gauss(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_FOC_GFP_BINARY_THRES]),
                &(vVD_ImgProcSteps[STEP_FOC_GFP_BLUR_MEDIAN]),
                ui->spinBox_ImgProc_Foc_GFP_BinarySize->value(),
                ui->doubleSpinBox_ImgProc_Foc_GFP_BinarySigma->value(),
                ui->doubleSpinBox_ImgProc_Foc_GFP_BinaryOffset->value(),
                ui->doubleSpinBox_ImgProc_Foc_GFP_BinaryScale->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_FOC_GFP_BINARY_THRES - Locally adaptive gaussian threshold to blured GFP image to get possible foci");
    }
        break;

    case STEP_FOC_GFP_MASK_IN_NUC:
    {
        ERR(D_VisDat_Proc::Math_2img_BitwiseAnd(
                &(vVD_ImgProcSteps[STEP_FOC_GFP_MASK_IN_NUC]),
                &(vVD_ImgProcSteps[STEP_FOC_GFP_BINARY_THRES]),
                &(vVD_ImgProcSteps[STEP_NUC_RFP_SELECT_MEAN])),
            "Update_ImageProcessing_StepSingle",
            "STEP_FOC_GFP_MASK_IN_NUC - (GFP) Select foci candidates that are inside nuclei");
    }
        break;

    case STEP_FOC_GFP_SELECT_AREA:
    {
        ERR(D_VisDat_Proc::Feature_Select(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_FOC_GFP_SELECT_AREA]),
                &(vVD_ImgProcSteps[STEP_FOC_GFP_MASK_IN_NUC]),
                c_FEAT_AREA,
                ui->doubleSpinBox_ImgProc_Foc_GFP_AreaMin->value(),
                ui->doubleSpinBox_ImgProc_Foc_GFP_AreaMax->value(),
                8),
            "Update_ImageProcessing_StepSingle",
            "STEP_FOC_GFP_SELECT_AREA - (GFP) Select foci candidates by area");
    }
        break;


    //Find Foci RFP -------------------------------------------------------------------------------------------------------

    case STEP_FOC_RFP_BLUR_MEDIAN:
    {
        ERR(D_VisDat_Proc::Filter_Median_Circular(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_FOC_RFP_BLUR_MEDIAN]),
                &(vVD_ImgProcSteps[STEP_PCK_RFP]),
                ui->spinBox_ImgProc_Foc_RFP_BlurMedianSize->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_FOC_RFP_BLUR_MEDIAN - Median blur GFP in order to get foci");
    }
        break;

    case STEP_FOC_RFP_BINARY_THRES:
    {
        ERR(D_VisDat_Proc::Threshold_Adaptive_Gauss(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_FOC_RFP_BINARY_THRES]),
                &(vVD_ImgProcSteps[STEP_FOC_RFP_BLUR_MEDIAN]),
                ui->spinBox_ImgProc_Foc_RFP_BinarySize->value(),
                ui->doubleSpinBox_ImgProc_Foc_RFP_BinarySigma->value(),
                ui->doubleSpinBox_ImgProc_Foc_RFP_BinaryOffset->value(),
                ui->doubleSpinBox_ImgProc_Foc_RFP_BinaryScale->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_FOC_RFP_BINARY_THRES - Locally adaptive gaussian threshold to blured GFP image to get possible foci");
    }
        break;

    case STEP_FOC_RFP_MASK_IN_NUC:
    {
        ERR(D_VisDat_Proc::Math_2img_BitwiseAnd(
                &(vVD_ImgProcSteps[STEP_FOC_RFP_MASK_IN_NUC]),
                &(vVD_ImgProcSteps[STEP_FOC_RFP_BINARY_THRES]),
                &(vVD_ImgProcSteps[STEP_NUC_RFP_SELECT_MEAN])),
            "Update_ImageProcessing_StepSingle",
            "STEP_FOC_RFP_MASK_IN_NUC - (GFP) Select foci candidates that are inside nuclei");
    }
        break;

    case STEP_FOC_RFP_SELECT_AREA:
    {
        ERR(D_VisDat_Proc::Feature_Select(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_FOC_RFP_SELECT_AREA]),
                &(vVD_ImgProcSteps[STEP_FOC_RFP_MASK_IN_NUC]),
                c_FEAT_AREA,
                ui->doubleSpinBox_ImgProc_Foc_RFP_AreaMin->value(),
                ui->doubleSpinBox_ImgProc_Foc_RFP_AreaMax->value(),
                8),
            "Update_ImageProcessing_StepSingle",
            "STEP_FOC_RFP_SELECT_AREA - (GFP) Select foci candidates by area");
    }
        break;

    //Match Foci GFP & RFP -------------------------------------------------------------------------------------------------------

    case STEP_FOC_BOTH_INTERSECT:
    {
        ERR(D_VisDat_Proc::Math_2img_BitwiseAnd(
                &(vVD_ImgProcSteps[STEP_FOC_BOTH_INTERSECT]),
                &(vVD_ImgProcSteps[STEP_FOC_GFP_SELECT_AREA]),
                &(vVD_ImgProcSteps[STEP_FOC_RFP_SELECT_AREA])),
            "Update_ImageProcessing_StepSingle",
            "STEP_FOC_BOTH_INTERSECT - Get intersect area of GFP and RFP foci");
    }
        break;

    case STEP_FOC_BOTH_SELECT_AREA:
    {
        ERR(D_VisDat_Proc::Feature_Select(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_FOC_BOTH_SELECT_AREA]),
                &(vVD_ImgProcSteps[STEP_FOC_BOTH_INTERSECT]),
                c_FEAT_AREA,
                ui->doubleSpinBox_ImgProc_Foc_RFP_AreaMin->value(),
                ui->doubleSpinBox_ImgProc_Foc_RFP_AreaMax->value(),
                8),
            "Update_ImageProcessing_StepSingle",
            "STEP_FOC_BOTH_SELECT_AREA - Select by area");
    }
    break;

    //Classification -------------------------------------------------------------------------------------------------------

    case STEP_CLA_FOC_ALL:
    {
        ERR(D_VisDat_Proc::Math_2img_BitwiseOr(
                &(vVD_ImgProcSteps[STEP_CLA_FOC_ALL]),
                &(vVD_ImgProcSteps[STEP_FOC_GFP_SELECT_AREA]),
                &(vVD_ImgProcSteps[STEP_FOC_RFP_SELECT_AREA])),
            "Update_ImageProcessing_StepSingle",
            "STEP_CLA_FOC_ALL - Foci that are in at least in GFP or RFP");
    }
        break;

    case STEP_CLA_FOC_IN_ONE_ONLY:
    {
        ERR(D_VisDat_Proc::Math_2img_SubtractionAbsolute(
                &(vVD_ImgProcSteps[STEP_CLA_FOC_IN_ONE_ONLY]),
                &(vVD_ImgProcSteps[STEP_CLA_FOC_ALL]),
                &(vVD_ImgProcSteps[STEP_FOC_BOTH_SELECT_AREA])),
            "Update_ImageProcessing_StepSingle",
            "STEP_CLA_FOC_IN_ONE_ONLY - Foci that are in exactly one out of GFP and RFP");
    }
        break;

    case STEP_CLA_FOC_IN_GFP_ONLY:
    {
        ERR(D_VisDat_Proc::Math_2img_BitwiseAnd(
                &(vVD_ImgProcSteps[STEP_CLA_FOC_IN_GFP_ONLY]),
                &(vVD_ImgProcSteps[STEP_CLA_FOC_IN_ONE_ONLY]),
                &(vVD_ImgProcSteps[STEP_FOC_GFP_SELECT_AREA])),
            "Update_ImageProcessing_StepSingle",
            "STEP_CLA_FOC_IN_GFP_ONLY - Foci in GFP only");
    }
        break;

    case STEP_CLA_FOC_IN_RFP_ONLY:
    {
        ERR(D_VisDat_Proc::Math_2img_BitwiseAnd(
                &(vVD_ImgProcSteps[STEP_CLA_FOC_IN_RFP_ONLY]),
                &(vVD_ImgProcSteps[STEP_CLA_FOC_IN_ONE_ONLY]),
                &(vVD_ImgProcSteps[STEP_FOC_RFP_SELECT_AREA])),
            "Update_ImageProcessing_StepSingle",
            "STEP_CLA_FOC_IN_RFP_ONLY - Foci in RFP only");
    }
        break;

    //Visualization -------------------------------------------------------------------------------------------------------

    case STEP_VIS_REGIONS:
    {
        ERR(D_VisDat_Proc::Channels_Merge(
                &(vVD_ImgProcSteps[STEP_VIS_REGIONS]),
                &(vVD_ImgProcSteps[STEP_FOC_GFP_SELECT_AREA]),
                &(vVD_ImgProcSteps[STEP_FOC_RFP_SELECT_AREA]),
                &(vVD_ImgProcSteps[STEP_VIS_NUC_BORDERS])),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_REGIONS - Nuclei and foci area as color");
    }
        break;

    case STEP_VIS_REGIONS_BACKGROUND:
    {
        D_VisDat_Obj VD_tmp_ColorBackground8bit;
        ERR(D_VisDat_Proc::Normalize(
                &VD_tmp_ColorBackground8bit,
                &(vVD_ImgProcSteps[STEP_VIS_PAGES_AS_COLOR]),
                NORM_MINMAX,
                CV_8U,
                0,
                255),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_REGIONS_BACKGROUND - convert 8 bit");

        ERR(D_VisDat_Proc::Math_2img_Addition(
                &(vVD_ImgProcSteps[STEP_VIS_REGIONS_BACKGROUND]),
                &VD_tmp_ColorBackground8bit,
                &(vVD_ImgProcSteps[STEP_VIS_REGIONS])),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_REGIONS_BACKGROUND - add");

    }
        break;

    default:
    {
        ERR(
                    ER_parameter_bad,
                    "Update_ImageProcessing_StepSingle",
                    "default case reached - step parameter out of range");
        return;
    }

    }


}

void D_MAKRO_MegaFoci::Update_ImageDecomposition()
{
    state_image_decomposed = false;

    ///vector od foci segmentation images indices
    vector<size_t> vIndices_FociBinary(FOCI_NUMBER_OF);
    vIndices_FociBinary[FOCI_GFP]   = STEP_FOC_GFP_SELECT_AREA;
    vIndices_FociBinary[FOCI_RFP]   = STEP_FOC_RFP_SELECT_AREA;
    vIndices_FociBinary[FOCI_BOTH]  = STEP_FOC_BOTH_SELECT_AREA;

    ///list of value image indices (GFP and RFP)
    vector<size_t> vIndices_Values(2);
    vIndices_Values[0] = STEP_PCK_GFP;
    vIndices_Values[1] = STEP_PCK_RFP;

    ///geometric moisaik offset in pixels
    Point MosaikOffset(
                ui->spinBox_Viewport_X->value() * static_cast<int>(dataset_dim_img_x * (1 - ui->doubleSpinBox_ImgProc_Stitch_Overlap->value() / 100.0)),
                ui->spinBox_Viewport_Y->value() * static_cast<int>(dataset_dim_img_y * (1 - ui->doubleSpinBox_ImgProc_Stitch_Overlap->value() / 100.0)));

    ///calculate image decomposition to bio info format
    StatusSet("Nuclei image decomposition");
    D_Bio_NucleusImage ImageDecomp;
    int ER = ImageDecomp.calc_NucleiDecomposition(
                &vVD_ImgProcSteps,
                STEP_NUC_RFP_SELECT_MEAN,
                vIndices_FociBinary,
                vIndices_Values,
                MosaikOffset,
                ui->spinBox_Viewport_T->value(),
                4,
                true,
                MosaikOffset.x + dataset_dim_img_x,
                MosaikOffset.y + dataset_dim_img_y);
    ERR(ER, "Update_ImageDecomposition", "ImageDecomp.calc_NucleiDecomposition");
    if(ER != ER_okay)
        return;

    state_image_decomposed = true;

    ///save data in files
    if(state_stack_processing)
    {
        StatusSet("Save decomposition in files");
        ERR(
                ImageDecomp.save(DIR_SaveDetections.path()),
                "Update_ImageDecomposition",
                "ImageDecomp.save(DIR_SaveDetections.path())");
    }
}

void D_MAKRO_MegaFoci::Stack_Process_All()
{
    //confirmation by user
    StatusSet("Are you sure you want to process full stack?");
    if(QMessageBox::question(
                this,
                "Confirm Stack Processing",
                "You are about to process the whole stack of iamges with the current settings."
                "<br>This will take some time (meaning days)."
                "<br>Do you want to continue?")
            != QMessageBox::Yes)
        return;

    //get save location
    StatusSet("Get save dir");
    QString QS_SavePath = QFileDialog::getExistingDirectory(
                this,
                "Select save directory for results of stack processing",
                pStore->dir_M_MegaFoci()->path());

    //check if save location is valid
    if(QS_SavePath.isEmpty())
    {
        StatusSet("Quit because no dir was selected");
        return;
    }
    pStore->set_dir_M_MegaFoci(QS_SavePath);

    //Create new save dir
    unsigned int count = 0;
    QString QS_Folder_Out_Sub = QS_SavePath + "/Results_0";
    while(QDir(QS_Folder_Out_Sub).exists())
    {
        count++;
        QS_Folder_Out_Sub = QS_SavePath + "/Results_" + QString::number(count);
    }

    //masterfolder
    DIR_SaveMaster.setPath(QS_Folder_Out_Sub);
    QDir().mkdir(DIR_SaveMaster.path());

    //Save subfolders
    DIR_SaveMosaik.setPath(DIR_SaveMaster.path() + "/Mosaik");
    QDir().mkdir(DIR_SaveMosaik.path());

    DIR_SaveDetections.setPath(DIR_SaveMaster.path() + "/Detections");
    QDir().mkdir(DIR_SaveDetections.path());

    //set ui
    ui->tabWidget_Control->setCurrentIndex(TAB_CONTROL_IMG_PROC);

    //start the stack processing :-)
    StatusSet("Start to loop all viewports");
    StatusSet("Time to get a cofee");
    state_stack_processing = true;

    //finish time prognosis
    D_FinishTimePrognosis TimePrognosis(
                ui->progressBar_StackLoop,
                dataset_dim_t * dataset_dim_mosaic_x * dataset_dim_mosaic_y);

    //loop viewports
    TimePrognosis.start();
    for(size_t t = 0; t < dataset_dim_t; t++)
        for(size_t y = 0; y < dataset_dim_mosaic_y; y++)
            for(size_t x = 0; x < dataset_dim_mosaic_x; x++)
            {                
                StatusSet("STACK PROC T" + QString::number(t) + " Y" + QString::number(y) + " X" + QString::number(x));

                //trigger img proc update by ui
                ui->spinBox_Viewport_T->blockSignals(true);
                ui->spinBox_Viewport_Y->blockSignals(true);
                ui->spinBox_Viewport_X->blockSignals(true);
                ui->spinBox_OverviewBig_T->blockSignals(true);
                ui->spinBox_Viewport_T->setValue(t);
                ui->spinBox_Viewport_Y->setValue(y);
                ui->spinBox_Viewport_X->setValue(x);
                ui->spinBox_OverviewBig_T->setValue(t);
                ui->spinBox_Viewport_T->blockSignals(false);
                ui->spinBox_Viewport_Y->blockSignals(false);
                ui->spinBox_Viewport_X->blockSignals(false);
                ui->spinBox_OverviewBig_T->blockSignals(false);

                Stack_Porcess_Single_XYT_Viewport();

                TimePrognosis.step();
            }

    TimePrognosis.end();
    StatusSet("STACK PROC FINISHED :-)");

    state_stack_processing = false;
}

void D_MAKRO_MegaFoci::Stack_Porcess_Single_XYT_Viewport()
{
    Update_ImageProcessing_CurrentImage();

    //Overwrite and update mosaik
    Update_Images_OverviewBig();
    Viewer_OverviewBig.Save_Image(DIR_SaveMosaik.path() + "/Mosaik_T" + QString::number(ui->spinBox_Viewport_T->value()) + ".png");
}

void D_MAKRO_MegaFoci::Populate_CB_AtStart()
{
    StatusSet("Populate the dropdown menus");

    Populate_CB_Single(ui->comboBox_VisTrafo_CropMode,                      QSL_VisTrafo_Crop,  c_VIS_TRAFO_CROP_DYNAMIC);
    Populate_CB_Single(ui->comboBox_VisTrafo_TransformationMode,            QSL_VisTrafo,       c_VIS_TRAFO_LOG);
    Populate_CB_Single(ui->comboBox_VisTrafo_AnchorMode,                    QSL_VisTrafo_Anchor,c_VIS_TRAFO_ANCHOR_DYNAMIC);
    Populate_CB_Single(ui->comboBox_VisTrafo_RangeMode,                     QSL_VisTrafo_Range, c_VIS_TRAFO_RANGE_DYNAMIC);

    Populate_CB_Single(ui->comboBox_ImgProc_StepShow,                       QSL_Steps,          STEP_VIS_REGIONS_BACKGROUND);

    Populate_CB_Single(ui->comboBox_ImgProc_ProjectZ_Stat,                  QSL_StatList,       c_STAT_QUANTIL_95);
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
    if(!state_page_indices_consistent)
    {
        StatusSet("Indices of pages not constistent");
        StatusSet("Remember: Indices in n count from 0 to n-1");
        StatusSet("And of course they should not double :-P");

        switch(QMessageBox::warning(
                    this,
                    "Dataset indices invalid",
                    "There is something wrong with the indices and/or count of pages."
                    "<br>Remember: Indices in n count from 0 to n-1"
                    "<br>And of course they should not double :-P"
                    "<br>"
                    "<br>Popular settings are:"
                    "<br>A) 2 exist, 2 used, GFP@0, RFP@1"
                    "<br>B) 3 exist, 2 used, other@0, GFP@1, RFP@2",
                    "Enter new settings",
                    "Try A",
                    "Try B"))
        {

            case 0:
            StatusSet("You thing you can do it better this time, right?");
            return false;

            case 1:
            ui->spinBox_DataDim_P_exist->setValue(2);
            ui->spinBox_PageIndex_GFP->setValue(0);
            ui->spinBox_PageIndex_RFP->setValue(1);
            StatusSet("Try standard setting A instead");
            return Load_Dataset();

            case 2:
            ui->spinBox_DataDim_P_exist->setValue(3);
            ui->spinBox_PageIndex_GFP->setValue(1);
            ui->spinBox_PageIndex_RFP->setValue(2);
            ui->spinBox_PageIndex_Other->setValue(0);
            StatusSet("Try standard setting B instead");
            return Load_Dataset();

            default:
            return false;
        }
    }

    StatusSet("Waiting exitedly for your selection");

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
    state_first_proc_on_start = true;

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
    ui->spinBox_Viewport_P->setMaximum(static_cast<int>(dataset_dim_p_exist - 1));

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
    state_first_proc_on_start = false;

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
                CV_16UC3,
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
    ///vector of needed slices
    vector<D_VisDat_Slice_2D> v2D_SlicesTarget;
    vector<int> vI_PageSource;

    ///Loop z and p to get indices of all needed images
    for(size_t z = 0; z < dataset_dim_z; z++)
        for(size_t p = 0; p < dataset_dim_p_exist; p++)
        {
            v2D_SlicesTarget.push_back(D_VisDat_Slice_2D(-1, -1, static_cast<int>(z), 0, 0, static_cast<int>(p)));
            vI_PageSource.push_back(static_cast<int>(get_index_of_page(static_cast<int>(z), static_cast<int>(t), static_cast<int>(p))));
        }

    ///Create sub VisDat from needed page vector
    return D_VisDat_Proc::Create_VD_PageVector_or0(
                pVD_Target,
                FIL_Images[static_cast<int>(get_index_of_image(x, y))],
                D_VisDat_Dim(
                    static_cast<int>(dataset_dim_img_x),
                    static_cast<int>(dataset_dim_img_y),
                    static_cast<int>(dataset_dim_z),
                    1,
                    1,
                    static_cast<int>(dataset_dim_p_exist)),
                vI_PageSource,
                v2D_SlicesTarget,
                c_DIM_X,
                c_DIM_Y,
                x >= dataset_dim_mosaic_x || y >= dataset_dim_mosaic_y || t >= dataset_dim_t,
                dataset_type_mat);
}

int D_MAKRO_MegaFoci::Load_Image_full_ZP_Stitched(D_VisDat_Obj *pVD_Target, size_t x, size_t y, size_t t)
{
    ///Load Top Left
    D_VisDat_Obj VD_tmp_TL;
    if(Load_Image_full_ZP(&VD_tmp_TL, x, y, t) != ER_okay)
        return false;

    ///Load Top Right
    D_VisDat_Obj VD_tmp_TR;
    if(x < dataset_dim_mosaic_x)
    {
        if(Load_Image_full_ZP(&VD_tmp_TR, x + 1, y, t) != ER_okay)
            return false;
    }
    else
        VD_tmp_TR = D_VisDat_Obj(VD_tmp_TL.Dim(), VD_tmp_TL.type(), 0);

    ///Load Bottom Left
    D_VisDat_Obj VD_tmp_BL;
    if(y < dataset_dim_mosaic_y)
    {
        if(Load_Image_full_ZP(&VD_tmp_BL, x, y + 1, t) != ER_okay)
            return false;
    }
    else
        VD_tmp_BL = D_VisDat_Obj(VD_tmp_TL.Dim(), VD_tmp_TL.type(), 0);

    ///Load Bottom Right
    D_VisDat_Obj VD_tmp_BR;
    if(x < dataset_dim_mosaic_x || y < dataset_dim_mosaic_y)
    {
        if(Load_Image_full_ZP(&VD_tmp_BR, x + 1, y + 1, t) != ER_okay)
            return false;
    }
    else
        VD_tmp_BR = D_VisDat_Obj(VD_tmp_TL.Dim(), VD_tmp_TL.type(), 0);

    ///Stitching
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

bool D_MAKRO_MegaFoci::Update_PagesConfig(bool give_2nd_try)
{
    ///ignore if dataset is loaded
    if(state_dataset_dim_set)
        return false;

    ///reset page consistent state
    state_page_indices_consistent = true;

    ///get indices
    index_GFP = ui->spinBox_PageIndex_GFP->value();
    index_RFP = ui->spinBox_PageIndex_RFP->value();
    index_page_other = ui->spinBox_PageIndex_Other->value();

    ///get pages count
    dataset_dim_p_exist = ui->spinBox_DataDim_P_exist->value();
    dataset_dim_p_used = ui->spinBox_DataDim_P_used->value();

    ///set existent pages - 1 as maximum for indices
    ui->spinBox_PageIndex_GFP->setMaximum(dataset_dim_p_exist - 1);
    ui->spinBox_PageIndex_RFP->setMaximum(dataset_dim_p_exist - 1);
    ui->spinBox_PageIndex_Other->setMaximum(dataset_dim_p_exist - 1);

    ///calc dataset size
    dataset_dim_tzp_used = dataset_dim_t * dataset_dim_z * dataset_dim_p_used;
    dataset_dim_tzp_exist = dataset_dim_t * dataset_dim_z * dataset_dim_p_exist;

    ///check index range
    if(index_GFP >= dataset_dim_p_exist)
        state_page_indices_consistent = false;
    if(index_RFP >= dataset_dim_p_exist)
        state_page_indices_consistent = false;
    if(dataset_dim_p_exist > 2)
        if(index_page_other >= dataset_dim_p_exist)
            state_page_indices_consistent = false;

    ///check index doubles
    if(index_GFP == index_RFP)
        state_page_indices_consistent = false;
    if(dataset_dim_p_exist > 2)
    {
        if(index_page_other == index_GFP)
            state_page_indices_consistent = false;
        if(index_page_other == index_RFP)
            state_page_indices_consistent = false;
    }

    ///Reset names list
    QSL_Pages.clear();
    for(size_t i = 0; i < dataset_dim_p_exist; i++)
        QSL_Pages.append("bullshit");

    ///set channel names if valid
    if(state_page_indices_consistent)
    {
        QSL_Pages[index_GFP] = "GFP";
        QSL_Pages[index_RFP] = "RFP";
        if(dataset_dim_p_exist > 2)
            QSL_Pages[index_page_other] = "Other";
    }

    ///try again one time if invalid (maxima settings could have changed it)
    if(!state_page_indices_consistent)
        if(give_2nd_try)
            Update_PagesConfig(false);

    ///show correct page name in ui if valid
    if(state_page_indices_consistent)
        if(ui->spinBox_Viewport_P->value() < QSL_Pages.size())
            ui->spinBox_Viewport_P->setSuffix(" (" + QSL_Pages[ui->spinBox_Viewport_P->value()] + ")");

    ///return state of success
    return state_page_indices_consistent;
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
        StatusSet("ERROR " + QSL_Errors[err] + ", Function:" + func + ", Detail: " + detail);
}

size_t D_MAKRO_MegaFoci::get_index_of_image(size_t x, size_t y)
{
    size_t idx_yx = dataset_dim_mosaic_x * y + x;
    return idx_yx < dataset_dim_mosaic_xy ? idx_yx : 0;
}

size_t D_MAKRO_MegaFoci::get_index_of_page(size_t z, size_t t, size_t p)
{
    size_t idx_tzp = t * dataset_dim_z * dataset_dim_p_exist + z * dataset_dim_p_exist + p;
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
    ///enable/disable viewport plane and page selection
    ui->spinBox_Viewport_Z->setEnabled(index < STEP_PRE_PROJECT_Z);
    ui->spinBox_Viewport_P->setEnabled(index < STEP_PCK_OTHER);

    ///update data dimension info in statusbar
    L_SB_InfoVD->setText(vVD_ImgProcSteps[index].info_short());

    ///show image from proc chain
    Update_Images_Proc();

    ///highlight settings relevant for this step
    QString QS_StyleActive = "font-weight: bold;";
    QString QS_StyleNormal = "font-weight: normal;";
    //pre
    ui->label_pre_4->setStyleSheet(index == STEP_PRE_STITCH ? QS_StyleActive : QS_StyleNormal);
    ui->label_pre_5->setStyleSheet(index == STEP_PRE_PROJECT_Z ? QS_StyleActive : QS_StyleNormal);
    //nuc
    ui->label_nuc_0->setStyleSheet(index == STEP_NUC_GFP_BLUR_MEDIAN ? QS_StyleActive : QS_StyleNormal);
    ui->label_nuc_1->setStyleSheet(index == STEP_NUC_GFP_EDGE_CV ? QS_StyleActive : QS_StyleNormal);
    ui->label_nuc_2->setStyleSheet(index == STEP_NUC_GFP_BINARY_THRES ? QS_StyleActive : QS_StyleNormal);
    ui->label_nuc_4->setStyleSheet(index == STEP_NUC_GFP_BINARY_MORPH_ERODE ? QS_StyleActive : QS_StyleNormal);
    ui->label_nuc_6->setStyleSheet(index == STEP_NUC_SEEDS ? QS_StyleActive : QS_StyleNormal);
    ui->label_nuc_7->setStyleSheet(index == STEP_NUC_WATERSHED ? QS_StyleActive : QS_StyleNormal);
    ui->label_nuc_8->setStyleSheet(index == STEP_NUC_SELECT_AREA ? QS_StyleActive : QS_StyleNormal);
    ui->label_nuc_9->setStyleSheet(index == STEP_NUC_SELECT_ROUNDNESS ? QS_StyleActive : QS_StyleNormal);
    ui->label_nuc_10->setStyleSheet(index == STEP_NUC_RFP_SELECT_MEAN ? QS_StyleActive : QS_StyleNormal);
    //foci gfp
    ui->label_foc_gfp_0->setStyleSheet(index == STEP_FOC_GFP_BLUR_MEDIAN ? QS_StyleActive : QS_StyleNormal);
    ui->label_foc_gfp_1->setStyleSheet(index == STEP_FOC_GFP_BINARY_THRES ? QS_StyleActive : QS_StyleNormal);
    ui->label_foc_gfp_3->setStyleSheet(index == STEP_FOC_GFP_SELECT_AREA ? QS_StyleActive : QS_StyleNormal);
    //foci rfp
    ui->label_foc_rfp_0->setStyleSheet(index == STEP_FOC_RFP_BLUR_MEDIAN ? QS_StyleActive : QS_StyleNormal);
    ui->label_foc_rfp_1->setStyleSheet(index == STEP_FOC_RFP_BINARY_THRES ? QS_StyleActive : QS_StyleNormal);
    ui->label_foc_rfp_3->setStyleSheet(index == STEP_FOC_RFP_SELECT_AREA ? QS_StyleActive : QS_StyleNormal);
    //foci both
    ui->label_foc_both_1->setStyleSheet(index == STEP_FOC_BOTH_SELECT_AREA ? QS_StyleActive : QS_StyleNormal);
}

void D_MAKRO_MegaFoci::on_spinBox_Viewport_P_valueChanged(int arg1)
{
    if(static_cast<size_t>(arg1) < dataset_dim_p_exist)
        ui->spinBox_Viewport_P->setSuffix(" (" + QSL_Pages[arg1] + ")");
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



void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Stitch_Border_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom(STEP_PRE_STITCH);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Stitch_Overlap_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom(STEP_PRE_STITCH);
}

void D_MAKRO_MegaFoci::on_comboBox_ImgProc_ProjectZ_Stat_currentIndexChanged(int index)
{
    Update_ImageProcessing_StepFrom(STEP_PRE_PROJECT_Z);
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

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Nuc_RoundnesMin_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom(STEP_NUC_SELECT_ROUNDNESS);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Nuc_RFP_SignalMeanMin_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom(STEP_NUC_RFP_SELECT_MEAN);
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Nuc_GFP_BlurMedianSize_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom(STEP_NUC_GFP_BLUR_MEDIAN);
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Nuc_GFP_EdgeCVSize_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom(STEP_NUC_GFP_EDGE_CV);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Nuc_GFP_ThresEdges_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom(STEP_NUC_GFP_BINARY_THRES);
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Nuc_ErodeBorder_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom(STEP_NUC_GFP_BINARY_MORPH_ERODE);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Nuc_GFP_DistThres_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom(STEP_NUC_DISTANCE);
}

void D_MAKRO_MegaFoci::on_checkBox_ImgProc_Nuc_Watershed_NonSeed_stateChanged(int arg1)
{
    Update_ImageProcessing_StepFrom(STEP_NUC_WATERSHED);
}

void D_MAKRO_MegaFoci::on_checkBox_ImgProc_Nuc_Watershed_ExBordered_stateChanged(int arg1)
{
    Update_ImageProcessing_StepFrom(STEP_NUC_WATERSHED);
}





void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Foc_GFP_BlurMedianSize_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom(STEP_FOC_GFP_BLUR_MEDIAN);
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Foc_GFP_BinarySize_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom(STEP_FOC_GFP_BINARY_THRES);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_GFP_BinarySigma_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom(STEP_FOC_GFP_BINARY_THRES);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_GFP_BinaryOffset_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom(STEP_FOC_GFP_BINARY_THRES);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_GFP_AreaMin_valueChanged(double arg1)
{
    if(arg1 > ui->doubleSpinBox_ImgProc_Foc_GFP_AreaMax->value())
        ui->doubleSpinBox_ImgProc_Foc_GFP_AreaMax->setValue(arg1);
    else
        Update_ImageProcessing_StepFrom(STEP_FOC_GFP_SELECT_AREA);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_GFP_AreaMax_valueChanged(double arg1)
{
    if(arg1 < ui->doubleSpinBox_ImgProc_Foc_GFP_AreaMin->value())
        ui->doubleSpinBox_ImgProc_Foc_GFP_AreaMin->setValue(arg1);
    else
        Update_ImageProcessing_StepFrom(STEP_FOC_GFP_SELECT_AREA);
}





void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Foc_RFP_BlurMedianSize_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom(STEP_FOC_RFP_BLUR_MEDIAN);
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Foc_RFP_BinarySize_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom(STEP_FOC_RFP_BINARY_THRES);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_RFP_BinarySigma_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom(STEP_FOC_RFP_BINARY_THRES);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_RFP_BinaryOffset_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom(STEP_FOC_RFP_BINARY_THRES);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_RFP_AreaMin_valueChanged(double arg1)
{
    if(arg1 > ui->doubleSpinBox_ImgProc_Foc_RFP_AreaMax->value())
        ui->doubleSpinBox_ImgProc_Foc_RFP_AreaMax->setValue(arg1);
    else
        Update_ImageProcessing_StepFrom(STEP_FOC_RFP_SELECT_AREA);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_RFP_AreaMax_valueChanged(double arg1)
{
    if(arg1 < ui->doubleSpinBox_ImgProc_Foc_RFP_AreaMin->value())
        ui->doubleSpinBox_ImgProc_Foc_RFP_AreaMin->setValue(arg1);
    else
        Update_ImageProcessing_StepFrom(STEP_FOC_RFP_SELECT_AREA);
}



void D_MAKRO_MegaFoci::on_action_Process_full_stack_triggered()
{
    Stack_Process_All();
}

void D_MAKRO_MegaFoci::on_spinBox_DataDim_P_exist_valueChanged(int arg1)
{
    ui->spinBox_PageIndex_Other->setEnabled(arg1 > 2);
}
