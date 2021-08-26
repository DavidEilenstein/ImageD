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
    for(size_t s = 0; s < STEP_NUMBER_OF; s++)
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

    ///set label for image reward system
    RewardSystem.set_target_label(ui->label_ImageReward);

    ///connects
    //viewer
    ConnectViewersVisTrafo(&Viewer_Main);
    ConnectViewersVisTrafo(&Viewer_OverviewSmall);
    ConnectViewersVisTrafo(&Viewer_OverviewBig);

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
    connect(ui->comboBox_OverviewBig_Type,                  SIGNAL(currentIndexChanged(int)),           this,               SLOT(Update_Images_OverviewBig()));

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
    StatusSet("Setting ui defaults to avoid confusion");
    ui->groupBox_Dataset->setEnabled(true);
    ui->groupBox_VisTrafo->setEnabled(false);
    ui->groupBox_View->setEnabled(false);
    ui->groupBox_Control->setEnabled(false);

    ///set default indices
    ui->tabWidget_Control->setCurrentIndex(TAB_CONTROL_VIEWPORT);
    ui->stackedWidget_View->setCurrentIndex(VIEW_PAGE_IMG_PROC);
    ui->stackedWidget_StepMajor->setCurrentIndex(MODE_MAJOR_0_DATASET_DIM);

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
    StatusSet("Please define the dimensions of your dataset. Unless you like random stuff to happen, this should stay the same for full analysis ;-)");
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

    switch (mode_major_current) {
    case MODE_MAJOR_1_AUTO_DETECTION:               Update_Views();         break;
    case MODE_MAJOR_2_MANU_CORRECT_DETECTION:       MS2_UpdateViews();      break;
    case MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI:                            break;
    case MODE_MAJOR_4_AUTO_RECONSTRUCT_PEDIGREE:                            break;
    case MODE_MAJOR_5_MANU_CORRECT_PEDIGREE:                                break;
    case MODE_MAJOR_6_EPIC_ANALYSIS:                                        break;
    default:                                                                break;}
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
    Update_Images_Proc();

    if(ui->tabWidget_Control->currentIndex() == TAB_CONTROL_OVERVIEW_BIG)
        Update_Images_OverviewBig();
}

void D_MAKRO_MegaFoci::Update_Images_Proc()
{
    //proc step index
    size_t proc_step_index = 0;
    if(mode_major_current == MODE_MAJOR_1_AUTO_DETECTION)
        proc_step_index = ui->comboBox_ImgProc_StepShow->currentIndex();
    else if(mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
        proc_step_index = ui->comboBox_MS3_ImgProc_StepShow->currentIndex();
    else
        return;

    //get inidices to show
    int z = ui->spinBox_Viewport_Z->value();
    int p = ui->spinBox_Viewport_P->value();

    //make sure indices fit
    if(z >= vVD_ImgProcSteps[proc_step_index].pDim()->size_Z())   z = 0;
    if(p >= vVD_ImgProcSteps[proc_step_index].pDim()->size_P())   p = 0;

    //2D plane to show
    D_VisDat_Slice_2D Slice2d(-1, -1, z, 0, 0, p);

    //Crop 2D plane from VD
    ERR(D_VisDat_Proc::Read_2D_Plane(
                &MA_Show,
                &(vVD_ImgProcSteps[proc_step_index]),
                Slice2d),
        "Update_Images_Proc",
        "D_VisDat_Proc::Read_2D_Plane - Crop " + Slice2d.info() + " from " + vVD_ImgProcSteps[proc_step_index].info());

    //display Mat
    Viewer_Main.Update_Image(&MA_Show);
}

void D_MAKRO_MegaFoci::Update_Images_OverviewSmall()
{
    ///get position in dataset
    int pos_x = ui->spinBox_Viewport_X->value();
    int pos_y = ui->spinBox_Viewport_Y->value();
    int pos_t = ui->spinBox_Viewport_T->value();

    ////make sure indices fit
    if(pos_t >= VD_Overview_Save.pDim()->size_T())   pos_t = 0;

    ///2D plane to show
    D_VisDat_Slice_2D Slice2d(-1, -1, 0, pos_t, 0, 0);

    ///Crop 2D plane from VD
    ERR(D_VisDat_Proc::Read_2D_Plane(
                &MA_OverviewSmall_Show,
                &VD_Overview_Save,
                Slice2d),
        "Update_Images_Proc",
        "D_VisDat_Proc::Read_2D_Plane - Crop " + Slice2d.info() + " from " + VD_Overview_Save.info());

    ///get max of overview as intensity for grid
    double min, max;
    ERR(D_Img_Proc::MinMax_of_Mat(
            &MA_OverviewSmall_Show,
            &min,
            &max),
        "Update_Images_Overview",
        "D_Img_Proc::MinMax_of_Mat");
    //scale max down to ignore very high values
    max /= 2.0;
    if(max < 1)
        max = 1;

    ///draw grid
    ERR(D_Img_Proc::Draw_GridSimple(
            &MA_OverviewSmall_Show,
            static_cast<int>(dataset_dim_mosaic_x),
            static_cast<int>(dataset_dim_mosaic_y),
            Scalar(max, max, max),
            5),
        "Update_Images_Overview",
        "D_Img_Proc::Draw_Grid");

    ///get overlap in px
    size_t overlap_px_x = ui->spinBox_ImgProc_Stitch_Overlap_x->value();
    size_t overlap_px_y = ui->spinBox_ImgProc_Stitch_Overlap_y->value();

    ///get border in %
    double border_prz = ui->doubleSpinBox_ImgProc_Stitch_Border->value() / 100.0;

    ///offset of current pos
    int offset_x = pos_x * (dataset_dim_img_x - overlap_px_x) * overview_scale;
    int offset_y = pos_y * (dataset_dim_img_y - overlap_px_y) * overview_scale;

    ///size of subimage including border stitching in overview
    int sub_img_size_x = (dataset_dim_img_x * (1.0 + border_prz)) * overview_scale;
    int sub_img_size_y = (dataset_dim_img_y * (1.0 + border_prz)) * overview_scale;

    ///draw rect at current viewport (including border stitching)
    ERR(D_Img_Proc::Draw_Rect(
            &MA_OverviewSmall_Show,
            static_cast<int>(offset_x),
            static_cast<int>(offset_y),
            static_cast<int>(offset_x + sub_img_size_x),
            static_cast<int>(offset_y + sub_img_size_y),
            11,
            max),
        "Update_Images_Overview",
        "D_Img_Proc::Draw_Grid");

    ///display Mat
    Viewer_OverviewSmall.Update_Image(&MA_OverviewSmall_Show);
    StatusSet("Show fancy overview");
}

void D_MAKRO_MegaFoci::Update_Images_OverviewBig()
{
    ///get overview type (channels, overlay)
    //qDebug() << "D_MAKRO_MegaFoci::Update_Images_OverviewBig" << "start";
    size_t overview_type = ui->comboBox_OverviewBig_Type->currentIndex();
    StatusSet("Update mosaik " + QSL_OverviewTypes[overview_type]);

    ///get inidices to show
    int t = ui->spinBox_OverviewBig_T->value();

    ///make sure indices fit
    if(t >= VD_Overview_Save.pDim()->size_T())   t = 0;

    ///calc 2D plane to show
    D_VisDat_Slice_2D Slice2d(-1, -1, 0, t, 0, 0);

    ///crop 2D plane from VD
    //qDebug() << "D_MAKRO_MegaFoci::Update_Images_OverviewBig" << "extract plane";
    Mat MA_tmp_plane;
    ERR(D_VisDat_Proc::Read_2D_Plane(
                &MA_tmp_plane,
                &VD_Overview_Save,
                Slice2d),
        "Update_Images_OverviewBig",
        "D_VisDat_Proc::Read_2D_Plane - Crop<br>" + Slice2d.info() + "<br>from<br>" + VD_Overview_Save.info());

    ///extract needed channels
    //qDebug() << "D_MAKRO_MegaFoci::Update_Images_OverviewBig" << "select channels";
    bool use_b = (overview_type == OVERVIEW_TYPE_RFP) || (overview_type == OVERVIEW_TYPE_COLOR)     || (overview_type >= OVERVIEW_TYPE_INFO_FOCI);
    bool use_g = (overview_type == OVERVIEW_TYPE_GFP) || (overview_type == OVERVIEW_TYPE_COLOR)     || (overview_type >= OVERVIEW_TYPE_INFO_FOCI);
    bool use_r = (overview_type == OVERVIEW_TYPE_DIC)                                               || (overview_type >= OVERVIEW_TYPE_INFO_VALUE_MEAN);
    ERR(D_Img_Proc::Channel_Supression(
                &MA_OverviewBig_Show,
                &MA_tmp_plane,
                use_r,
                use_g,
                use_b,
                false),
        "Update_Images_OverviewBig",
        "D_Img_Proc::Channel_Supression - " + QSL_OverviewTypes[overview_type]);
    MA_tmp_plane.release();

    ///if results shall be shown, create contour/text overlay in image
    //qDebug() << "D_MAKRO_MegaFoci::Update_Images_OverviewBig" << "add overlay";
    if(overview_type >= OVERVIEW_TYPE_INFO_FOCI)
    {
        //qDebug() << "D_MAKRO_MegaFoci::Update_Images_OverviewBig" << "overview_type >= OVERVIEW_TYPE_INFO_FOCI";
        ///create containers for info describing detected nuclei and foci
        QStringList QSl_Info;
        vector<vector<Point>> vContoursScaled;
        vector<Point2f> vCentroids;
        for(size_t y = 0; y < dataset_dim_mosaic_y; y++)
        {
            for(size_t x = 0; x < dataset_dim_mosaic_x; x++)
            {
                //qDebug() << "D_MAKRO_MegaFoci::Update_Images_OverviewBig" << "x/y" << x << y;
                if(vvvImageDecompCalced_TYX[t][y][x])
                {
                    //extract needed nucleus image
                    //qDebug() << "D_MAKRO_MegaFoci::Update_Images_OverviewBig" << "get nucimg";
                    D_Bio_NucleusImage NucImg = vvvImageDecomp_TYX[t][y][x];
                    //qDebug() << "D_MAKRO_MegaFoci::Update_Images_OverviewBig" << NucImg.info();

                    //remove duplicates if needed
                    //qDebug() << "D_MAKRO_MegaFoci::Update_Images_OverviewBig" << "check mode";
                    //qDebug() << "D_MAKRO_MegaFoci::Update_Images_OverviewBig" << "mode:" << QSL_ModeMajor[mode_major_current];
                    if(mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
                    {
                        //qDebug() << "D_MAKRO_MegaFoci::Update_Images_OverviewBig" << "mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI";

                        //valid neighbor images
                        vector<D_Bio_NucleusImage> vNeighborNucImg;
                        if(x < dataset_dim_mosaic_x - 1)
                            vNeighborNucImg.push_back(vv_MS3_NucImg_InCorrected_mosaikXY[x + 1][y   ]);
                        if(y < dataset_dim_mosaic_y - 1)
                            vNeighborNucImg.push_back(vv_MS3_NucImg_InCorrected_mosaikXY[x    ][y + 1]);
                        if(x < dataset_dim_mosaic_x - 1 && y < dataset_dim_mosaic_y - 1)
                            vNeighborNucImg.push_back(vv_MS3_NucImg_InCorrected_mosaikXY[x + 1][y + 1]);

                        //remove duplicates
                        if(!vNeighborNucImg.empty())
                                NucImg.remove_nuclei_dulicates(vNeighborNucImg, ui->doubleSpinBox_MS3_ImgProc_DuplicateRelThres->value() / 100.0);
                    }

                    ///Nucleus position and contour info
                    //qDebug() << "D_MAKRO_MegaFoci::Update_Images_OverviewBig" << "append centers and contours";
                    NucImg.get_Contours_append(&vContoursScaled, overview_scale);
                    NucImg.get_Centroids_append(&vCentroids, overview_scale);

                    ///additional info to be displayed as text on image
                    //qDebug() << "D_MAKRO_MegaFoci::Update_Images_OverviewBig" << "append info";
                    switch (overview_type) {
                    case OVERVIEW_TYPE_INFO_FOCI:           NucImg.get_FociCount_append(&QSl_Info);                                 break;
                    case OVERVIEW_TYPE_INFO_SHAPE:          NucImg.get_ShapeInfo_append(&QSl_Info);                                 break;
                    case OVERVIEW_TYPE_INFO_VALUE_MEAN:     NucImg.get_ChannelStat_append(&QSl_Info, VAL_STAT_MEAN);                break;
                    case OVERVIEW_TYPE_INFO_VALUE_STD:      NucImg.get_ChannelStat_append(&QSl_Info, VAL_STAT_STD);                 break;
                    case OVERVIEW_TYPE_INFO_VALUE_SKEWNESS: NucImg.get_ChannelStat_append(&QSl_Info, VAL_STAT_SKEW);                break;
                    case OVERVIEW_TYPE_INFO_VALUE_KURTOSIS: NucImg.get_ChannelStat_append(&QSl_Info, VAL_STAT_KURTOSIS);            break;
                    case OVERVIEW_TYPE_INFO_VALUE_MEDIAN:   NucImg.get_ChannelStat_append(&QSl_Info, VAL_STAT_MEDIAN);              break;
                    case OVERVIEW_TYPE_INFO_VALUE_MED_DEV:  NucImg.get_ChannelStat_append(&QSl_Info, VAL_STAT_MEDIAN_DEVIATION);    break;
                    default:                                                                                                        return;}
                }
            }
        }

        ///draw info on image to display
        //qDebug() << "D_MAKRO_MegaFoci::Update_Images_OverviewBig" << "Draw Text:" << QSl_Info;
        ERR(D_Img_Proc::Draw_ContourText(
                    &MA_OverviewBig_Show,
                    vContoursScaled,
                    QSl_Info,
                    vCentroids,
                    1,
                    1,
                    0.75,
                    255),
            "Update_Images_OverviewBig",
            "D_Img_Proc::Draw_ContourText");
    }

    ///display Mat
    //qDebug() << "D_MAKRO_MegaFoci::Update_Images_OverviewBig" << "display";
    Viewer_OverviewBig.Update_Image(&MA_OverviewBig_Show);

    //qDebug() << "D_MAKRO_MegaFoci::Update_Images_OverviewBig" << "finish";
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_CurrentImage()
{
    if(!state_dataset_img_list_loaded)
        return;

    //start time measurement
    QElapsedTimer timer_img_proc;
    timer_img_proc.start();

    //proc all steps
    if(mode_major_current == MODE_MAJOR_1_AUTO_DETECTION)
        Update_ImageProcessing_StepFrom_MS1(0);
    else if(mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
        Update_ImageProcessing_StepFrom_MS3(0);

    //measure time
    time_LastSingleImgProc = timer_img_proc.elapsed();
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepFrom(size_t step_start)
{
    if(mode_major_current == MODE_MAJOR_1_AUTO_DETECTION)
        return Update_ImageProcessing_StepFrom_MS1(step_start);
    else if(mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
        return Update_ImageProcessing_StepFrom_MS3(step_start);
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepFrom_MS1(size_t step_start)
{
    if(!state_dataset_img_list_loaded)
        return;

    //reset states
    if(step_start <= STEP_FOC_BOTH_SELECT_AREA)
        state_image_decomposed = false;

    for(size_t s = step_start; s < STEP_NUMBER_OF; s++)
    {
        Update_ImageProcessing_StepSingle_MS1(s);

        if(state_stack_processing || state_first_proc_on_start)
        {
            ui->comboBox_ImgProc_StepShow->setCurrentIndex(static_cast<int>(s));
            Update_Ui();
        }
    }

    Update_Images_Proc();
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepFrom_MS3(size_t step_start)
{
    if(!state_dataset_img_list_loaded)
        return;

    //reset states
    if(step_start <= STEP_MS3_VIS_REGIONS)
        state_image_decomposed = false;

    for(size_t s = step_start; s < STEP_MS3_NUMBER_OF; s++)
    {
        Update_ImageProcessing_StepSingle_MS3(s);

        if(state_stack_processing || state_first_proc_on_start)
        {
            ui->comboBox_ImgProc_StepShow->setCurrentIndex(static_cast<int>(s));
            Update_Ui();
        }
    }

    Update_Images_Proc();
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepSingle(size_t step)
{
    if(mode_major_current == MODE_MAJOR_1_AUTO_DETECTION)
        return Update_ImageProcessing_StepSingle_MS1(step);
    else if(mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
        return Update_ImageProcessing_StepSingle_MS3(step);
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepSingle_MS1(size_t step)
{
    if(!state_dataset_img_list_loaded)
        return;

    //current position in dataset
    int dataset_pos_x = ui->spinBox_Viewport_X->value();
    int dataset_pos_y = ui->spinBox_Viewport_Y->value();
    int dataset_pos_t = ui->spinBox_Viewport_T->value();

    //select step to do
    StatusSet("ImgProcMS1: " + QSL_Steps[static_cast<int>(step)]);
    switch (step) {

    //Preparation -------------------------------------------------------------------------------------------------------

    case STEP_PRE_LOAD_MAIN:
    {
        ERR(Load_Image(
                &(vVD_ImgProcSteps[STEP_PRE_LOAD_MAIN]),
                dataset_pos_x,
                dataset_pos_y,
                dataset_pos_t),
            "Update_ImageProcessing_StepSingle",
            "STEP_PRE_LOAD_MAIN - Load main image");
    }
        break;

    case STEP_PRE_LOAD_RIGHT:
    {
        ERR(Load_Image(
                &(vVD_ImgProcSteps[STEP_PRE_LOAD_RIGHT]),
                dataset_pos_x + 1,
                dataset_pos_y,
                dataset_pos_t),
            "Update_ImageProcessing_StepSingle",
            "STEP_PRE_LOAD_RIGHT - Load border image right");
    }
        break;

    case STEP_PRE_LOAD_BOTTOM:
    {
        ERR(Load_Image(
                &(vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM]),
                dataset_pos_x,
                dataset_pos_y + 1,
                dataset_pos_t),
            "Update_ImageProcessing_StepSingle",
            "STEP_PRE_LOAD_BOTTOM - Load border image bottom");
    }
        break;

    case STEP_PRE_LOAD_BOTTOM_RIGHT:
    {
        ERR(Load_Image(
                &(vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM_RIGHT]),
                dataset_pos_x + 1,
                dataset_pos_y + 1,
                dataset_pos_t),
            "Update_ImageProcessing_StepSingle",
            "STEP_PRE_LOAD_BOTTOM_RIGHT - Load border image bottom right");
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
                ui->spinBox_ImgProc_Stitch_Overlap_x->value() / static_cast<double>(dataset_dim_img_x),
                ui->spinBox_ImgProc_Stitch_Overlap_y->value() / static_cast<double>(dataset_dim_img_y)),
            "Update_ImageProcessing_StepSingle",
            "STEP_PRE_STITCH - Stitching 4 images"
            "<br>VD Main: " + vVD_ImgProcSteps[STEP_PRE_LOAD_MAIN].info() +
            "<br>VD Right: " + vVD_ImgProcSteps[STEP_PRE_LOAD_RIGHT].info() +
            "<br>VD Bottom: " + vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM].info() +
            "<br>VD Bottom Right: " + vVD_ImgProcSteps[STEP_PRE_LOAD_BOTTOM_RIGHT].info() +
            "<br>VD Stitched: " + vVD_ImgProcSteps[STEP_PRE_STITCH].info());
    }
        break;

    case STEP_PRE_BLUR_GAUSS:
    {
        ERR(D_VisDat_Proc::Filter_Gauss(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_PRE_BLUR_GAUSS]),
                &(vVD_ImgProcSteps[STEP_PRE_STITCH]),
                ui->spinBox_ImgProc_Pre_Blur_Size->value(),
                ui->spinBox_ImgProc_Pre_Blur_Size->value(),
                BORDER_DEFAULT,
                ui->doubleSpinBox_ImgProc_Pre_Blur_Sigma->value(),
                ui->doubleSpinBox_ImgProc_Pre_Blur_Sigma->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_PRE_BLUR_GAUSS");
    }
        break;

    case STEP_PRE_PROJECT_Z:
    {
        ERR(D_VisDat_Proc::Dim_Project(
                &(vVD_ImgProcSteps[STEP_PRE_PROJECT_Z]),
                &(vVD_ImgProcSteps[STEP_PRE_BLUR_GAUSS]),
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

    case STEP_VIS_OTHER:
    {
        ERR(D_VisDat_Proc::GammaSpread(
                &(vVD_ImgProcSteps[STEP_VIS_OTHER]),
                &(vVD_ImgProcSteps[STEP_PCK_OTHER]),
                ui->doubleSpinBox_ImgProc_Vis_Other_Gamma->value(),
                ui->spinBox_ImgProc_Vis_Other_Min->value(),
                ui->spinBox_ImgProc_Vis_Other_Max->value(),
                0,
                255,
                true),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_OTHER");
    }
        break;

    case STEP_VIS_GFP:
    {
        ERR(D_VisDat_Proc::GammaSpread(
                &(vVD_ImgProcSteps[STEP_VIS_GFP]),
                &(vVD_ImgProcSteps[STEP_PCK_GFP]),
                ui->doubleSpinBox_ImgProc_Vis_GFP_Gamma->value(),
                ui->spinBox_ImgProc_Vis_GFP_Min->value(),
                ui->spinBox_ImgProc_Vis_GFP_Max->value(),
                0,
                255,
                true),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_GFP");
    }
        break;

    case STEP_VIS_RFP:
    {
        ERR(D_VisDat_Proc::GammaSpread(
                &(vVD_ImgProcSteps[STEP_VIS_RFP]),
                &(vVD_ImgProcSteps[STEP_PCK_RFP]),
                ui->doubleSpinBox_ImgProc_Vis_RFP_Gamma->value(),
                ui->spinBox_ImgProc_Vis_RFP_Min->value(),
                ui->spinBox_ImgProc_Vis_RFP_Max->value(),
                0,
                255,
                true),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_RFP");
    }
        break;

    case STEP_VIS_PAGES_AS_COLOR_GFP_RFP:
    {
        bool use_channels[4] = {true, true, false, false};
        ERR(D_VisDat_Proc::Channels_Merge(
                &(vVD_ImgProcSteps[STEP_VIS_PAGES_AS_COLOR_GFP_RFP]),
                &(vVD_ImgProcSteps[STEP_VIS_RFP]),
                &(vVD_ImgProcSteps[STEP_VIS_GFP]),
                &(vVD_ImgProcSteps[STEP_VIS_OTHER]),
                &(vVD_ImgProcSteps[STEP_VIS_RFP]),
                3,
                use_channels),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_PAGES_AS_COLOR_GFP_RFP - Visualize signals in color");
    }
        break;

    case STEP_VIS_PAGES_AS_COLOR_ALL:
    {
        bool use_channels[4] = {true, true, true, false};
        ERR(D_VisDat_Proc::Channels_Merge(
                &(vVD_ImgProcSteps[STEP_VIS_PAGES_AS_COLOR_ALL]),
                &(vVD_ImgProcSteps[STEP_VIS_RFP]),
                &(vVD_ImgProcSteps[STEP_VIS_GFP]),
                &(vVD_ImgProcSteps[STEP_VIS_OTHER]),
                &(vVD_ImgProcSteps[STEP_VIS_OTHER]),
                3,
                use_channels),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_PAGES_AS_COLOR_ALL - Visualize signals in color");

        Overview_Update();
    }
        break;


    //Find Nuclei -------------------------------------------------------------------------------------------------------

    case STEP_NUC_GFP_RANK_ORDER:
    {
        ERR(D_VisDat_Proc::Filter_RankOrder_Circular(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_RANK_ORDER]),
                &(vVD_ImgProcSteps[STEP_PCK_GFP]),
                ui->doubleSpinBox_ImgProc_RankOrder_Quantil->value() / 100.0,
                ui->doubleSpinBox_ImgProc_RankOrder_Size->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_RANK_ORDER");
    }
        break;

    case STEP_NUC_GFP_SEG0_THRES:
    {
        ERR(D_VisDat_Proc::Threshold_Absolute(
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0_THRES]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_RANK_ORDER]),
                ui->doubleSpinBox_ImgProc_Seg0_Thresh->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG0_THRES");
    }
        break;

    case STEP_NUC_GFP_SEG0_MORPH_OPENING:
    {
        ERR(D_VisDat_Proc::MorphSimple_Circ_Opening(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0_MORPH_OPENING]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0_THRES]),
                ui->spinBox_ImgProc_Seg0_ClosingSize->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG0_MORPH_OPENING");
    }
        break;

    case STEP_NUC_GFP_SEG0_FILL_HOLES:
    {
        ERR(D_VisDat_Proc::Fill_Holes(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0_FILL_HOLES]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0_MORPH_OPENING])),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG0_FILL_HOLES");
    }
        break;

    case STEP_NUC_GFP_SEG0_SELECT_AREA:
    {
        ERR(D_VisDat_Proc::Feature_Select(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0_SELECT_AREA]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0_FILL_HOLES]),
                c_FEAT_AREA,
                ui->doubleSpinBox_ImgProc_Seg0_Area_Min->value(),
                ui->doubleSpinBox_ImgProc_Seg0_Area_Max->value(),
                8),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG0_SELECT_AREA");
    }
        break;

    case STEP_NUC_GFP_SEG1_DISTANCE:
    {
        ERR(D_VisDat_Proc::Transformation_Distance(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG1_DISTANCE]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0_SELECT_AREA]),
                DIST_L2,
                DIST_MASK_PRECISE),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG1_DISTANCE");
    }
        break;

    case STEP_NUC_GFP_SEG1_SEEDS:
    {
        ERR(D_VisDat_Proc::Threshold_Absolute(
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG1_SEEDS]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG1_DISTANCE]),
                ui->doubleSpinBox_ImgProc_Seg1_DistThresh->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG1_SEEDS");
    }
        break;

    case STEP_NUC_GFP_SEG1_SEEDS_CLEAR:
    {
        ERR(D_VisDat_Proc::MorphSimple_Circ_Opening(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG1_SEEDS_CLEAR]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG1_SEEDS]),
                ui->spinBox_ImgProc_Seg1_OpenSeeds->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG1_SEEDS_CLEAR");
    }
        break;

    case STEP_NUC_GFP_SEG1_WATERSHED:
    {
        ERR(D_VisDat_Proc::Transformation_Watershed_Auto(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG1_WATERSHED]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0_SELECT_AREA]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG1_SEEDS_CLEAR]),
                true,
                false,
                false),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG1_WATERSHED\nROI:\n" + vVD_ImgProcSteps[STEP_NUC_GFP_SEG0_SELECT_AREA].info_short() + "\nSeeds:\n" + vVD_ImgProcSteps[STEP_NUC_GFP_SEG1_SEEDS_CLEAR].info_short());
    }
        break;

    case STEP_NUC_GFP_SEG1_BINARY_SEGMENTS:
    {
        ERR(D_VisDat_Proc::Threshold_Absolute(
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG1_BINARY_SEGMENTS]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG1_WATERSHED]),
                0),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG1_BINARY_SEGMENTS");
    }
        break;

    case STEP_NUC_GFP_SEG2_DISTANCE:
    {
        ERR(D_VisDat_Proc::Transformation_Distance(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG2_DISTANCE]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG1_BINARY_SEGMENTS]),
                DIST_L2,
                DIST_MASK_PRECISE),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG2_DISTANCE");
    }
        break;

    case STEP_NUC_GFP_SEG2_SEEDS:
    {
        ERR(D_VisDat_Proc::Threshold_Absolute(
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG2_SEEDS]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG2_DISTANCE]),
                ui->doubleSpinBox_ImgProc_Seg2_DistThresh->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG2_SEEDS");
    }
        break;

    case STEP_NUC_GFP_SEG2_SEEDS_CLEAR:
    {
        ERR(D_VisDat_Proc::MorphSimple_Circ_Opening(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG2_SEEDS_CLEAR]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG2_SEEDS]),
                ui->spinBox_ImgProc_Seg2_OpenSeeds->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG2_SEEDS_CLEAR");
    }
        break;

    case STEP_NUC_GFP_SEG2_WATERSHED:
    {
        ERR(D_VisDat_Proc::Transformation_Watershed_Auto(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG2_WATERSHED]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG1_BINARY_SEGMENTS]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG2_SEEDS_CLEAR]),
                true,
                false,
                true),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG2_WATERSHED");
    }
        break;

    case STEP_NUC_GFP_SEG2_SELECT_AREA:
    {
        ERR(D_VisDat_Proc::Feature_Select(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG2_SELECT_AREA]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG2_WATERSHED]),
                c_FEAT_AREA,
                ui->doubleSpinBox_ImgProc_Seg2_Area_Min->value(),
                ui->doubleSpinBox_ImgProc_Seg2_Area_Max->value(),
                8),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG2_SELECT_AREA");
    }
        break;

    case STEP_NUC_GFP_SEG3_CONVEX_HULL:
    {
        //contour of convex hull
        D_VisDat_Obj VD_tmp_ConvexHullContour;
        ERR(D_VisDat_Proc::Geometric_Reduce(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &VD_tmp_ConvexHullContour,
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG2_SELECT_AREA]),
                c_GEO_CONVEX_HULL,
                4,
                1,
                255),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG3_CONVEX_HULL - hull contour");

        //fill contour
        ERR(D_VisDat_Proc::Fill_Holes(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG3_CONVEX_HULL]),
                &VD_tmp_ConvexHullContour),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG3_CONVEX_HULL - fill contour");
    }
        break;

    case STEP_NUC_GFP_SEG3_WATERSHED_SEGMENTS:
    {
        ERR(D_VisDat_Proc::Transformation_Watershed_Auto(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG3_WATERSHED_SEGMENTS]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG3_CONVEX_HULL]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG2_SEEDS_CLEAR]),
                true,
                false,
                true),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG3_WATERSHED_SEGMENTS");
    }
        break;

    case STEP_NUC_GFP_SEG3_BINARY_SEGMENTS:
    {
        ERR(D_VisDat_Proc::Threshold_Absolute(
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG3_BINARY_SEGMENTS]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG3_WATERSHED_SEGMENTS]),
                0),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG3_BINARY_SEGMENTS");
    }
        break;


    case STEP_VIS_NUC_BORDERS:
    {
        ERR(D_VisDat_Proc::Geometric_Reduce(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_VIS_NUC_BORDERS]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG3_BINARY_SEGMENTS]),
                c_GEO_CONTOUR,
                4,
                2,
                255),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_NUC_BORDERS");
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

    case STEP_FOC_GFP_SELECT_AREA:
    {
        ERR(D_VisDat_Proc::Feature_Select(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_FOC_GFP_SELECT_AREA]),
                &(vVD_ImgProcSteps[STEP_FOC_GFP_BINARY_THRES]),
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

    case STEP_FOC_RFP_SELECT_AREA:
    {
        ERR(D_VisDat_Proc::Feature_Select(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_FOC_RFP_SELECT_AREA]),
                &(vVD_ImgProcSteps[STEP_FOC_RFP_BINARY_THRES]),
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

        Update_ImageDecomposition();

        if(ui->tabWidget_Control->currentIndex() == TAB_CONTROL_OVERVIEW_BIG)
            Update_Images_OverviewBig();
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
        //color code:
        //R: Nuclei Borders
        //G: GFP Foci
        //M: RFP Foci
        //W: GFP Foci + RFP Foci

        //merge to red channel
        D_VisDat_Obj VD_tmp_red;
        ERR(D_VisDat_Proc::Math_2img_Maximum(
                &VD_tmp_red,
                &(vVD_ImgProcSteps[STEP_VIS_NUC_BORDERS]),
                &(vVD_ImgProcSteps[STEP_FOC_RFP_SELECT_AREA])),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_REGIONS - Math_2img_Maximum calc red channel");

        //merge to rgb image
        ERR(D_VisDat_Proc::Channels_Merge(
                &(vVD_ImgProcSteps[STEP_VIS_REGIONS]),          //out
                &(vVD_ImgProcSteps[STEP_FOC_RFP_SELECT_AREA]),  //B
                &(vVD_ImgProcSteps[STEP_FOC_GFP_SELECT_AREA]),  //G
                &VD_tmp_red),                                   //R
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_REGIONS - Channels_Merge Nuclei and foci area as color");
    }
        break;

    case STEP_VIS_REGIONS_BACKGROUND:
    {
        ERR(D_VisDat_Proc::OverlayOverwrite(
                &(vVD_ImgProcSteps[STEP_VIS_REGIONS_BACKGROUND]),
                &(vVD_ImgProcSteps[STEP_VIS_PAGES_AS_COLOR_ALL]),
                &(vVD_ImgProcSteps[STEP_VIS_REGIONS]),
                ui->doubleSpinBox_ImgProc_Vis_Intensity_Overlay->value() / 100.0,
                ui->doubleSpinBox_ImgProc_Vis_Intensity_Background->value() / 100.0),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_REGIONS_BACKGROUND - OverlayOverwrite");
    }
        break;

    case STEP_VIS_REGIONS_FOCI_COUNT:
    {
        if(!state_image_decomposed)
        {
            ERR(ER_other, "Update_ImageProcessing_StepSingle", "STEP_VIS_REGIONS_FOCI_COUNT tried to acces unsuccesfull image decomp");
            return;
        }

        //get pos in dataset
        int pos_x = ui->spinBox_Viewport_X->value();
        int pos_y = ui->spinBox_Viewport_Y->value();
        int pos_t = ui->spinBox_Viewport_T->value();

        //get foci counts as QStringList
        QStringList QSL_LabelTexts = QStringList();
        vvvImageDecomp_TYX[pos_t][pos_y][pos_x].get_FociCount_append(&QSL_LabelTexts);

        int ER = D_VisDat_Proc::Draw_Label_Text(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &(vVD_ImgProcSteps[STEP_VIS_REGIONS_FOCI_COUNT]),
                    &(vVD_ImgProcSteps[STEP_VIS_REGIONS_BACKGROUND]),
                    &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG3_BINARY_SEGMENTS]),
                    QSL_LabelTexts,
                    false,
                    1, 2,
                    true,
                    255, 255, 255,
                    4);
        ERR(ER, "Update_ImageProcessing_StepSingle", "STEP_VIS_REGIONS_FOCI_COUNT - put numbers on image");
        if(ER != ER_okay)
            return;
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

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepSingle_MS3(size_t step)
{
    if(!state_dataset_img_list_loaded)
        return;

    //select step to do
    StatusSet("ImgProcMS3: " + QSL_Steps_MS3[static_cast<int>(step)]);

    //chose method for proc step style
    if(step <= STEP_MS3_VIS_PAGES_AS_COLOR_QUANTILS_ALL)
        return Update_ImageProcessing_StepSingle_MS1(step);
    else if(step <= STEP_MS3_VIS_FOCI_BOTH)
        return Update_ImageProcessing_StepSingle_MS3_DrawDetections(step);
    else
        return Update_ImageProcessing_StepSingle_MS3_VisualizeResults(step);
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepSingle_MS3_DrawDetections(size_t step)
{
    if(step < STEP_MS3_VIS_NUCLEI_BORDERS_NO_REMOVE || step > STEP_MS3_VIS_FOCI_BOTH)
    {
        ERR(ER_index_out_of_range,
            "Update_ImageProcessing_StepSingle_MS3_DrawDetections",
            "Index " + QSL_Steps_MS3[step] + " does not fit to this function");
        return;
    }

    //init black background (VD)
    vVD_ImgProcSteps[step] = D_VisDat_Obj(vVD_ImgProcSteps[STEP_MS3_PCK_GFP].Dim(), CV_8UC1, 0);

    //mosaic coordinates
    size_t mx = ui->spinBox_Viewport_X->value();
    size_t my = ui->spinBox_Viewport_Y->value();

    //check if coordinates are valid
    if(mx >= dataset_dim_mosaic_x || my >= dataset_dim_mosaic_y)
    {
        qDebug() << "Update_ImageProcessing_StepSingle_MS3_DrawDetections - mx" << mx << "or my" << my << "out of range";
        return;
    }

    if(vv_MS3_NucImg_InCorrected_States_mosaikXY[mx][my] == MS2_IMG_STATE_NOT_FOUND)
    {
        StatusSet("No detections found for grid cell " + QString::number(mx) + "/" + QString::number(my));
        return;
    }

    //calc offset
    Point P_Offset(
                mx * (dataset_dim_img_x - ui->spinBox_ImgProc_Stitch_Overlap_x->value()),
                my * (dataset_dim_img_y - ui->spinBox_ImgProc_Stitch_Overlap_y->value()));

    //get detections
    D_Bio_NucleusImage NucImg = vv_MS3_NucImg_InCorrected_mosaikXY[mx][my];
    //qDebug() << "Update_ImageProcessing_StepSingle_MS3_DrawDetections" << "Found NucImg" << NucImg.info();

    //remove duplicates if needed
    if(step != STEP_MS3_VIS_NUCLEI_BORDERS_NO_REMOVE)
    {
        //valid neighbor images
        vector<D_Bio_NucleusImage> vNeighborNucImg;
        if(mx < dataset_dim_mosaic_x - 1)
            vNeighborNucImg.push_back(vv_MS3_NucImg_InCorrected_mosaikXY[mx + 1][my   ]);
        if(my < dataset_dim_mosaic_y - 1)
            vNeighborNucImg.push_back(vv_MS3_NucImg_InCorrected_mosaikXY[mx    ][my + 1]);
        if(mx < dataset_dim_mosaic_x - 1 && my < dataset_dim_mosaic_y - 1)
            vNeighborNucImg.push_back(vv_MS3_NucImg_InCorrected_mosaikXY[mx + 1][my + 1]);

        //remove duplicates
        if(!vNeighborNucImg.empty())
                NucImg.remove_nuclei_dulicates(vNeighborNucImg, ui->doubleSpinBox_MS3_ImgProc_DuplicateRelThres->value() / 100.0);
    }

    //init empty background
    Mat MA_tmp_target = Mat::zeros(vVD_ImgProcSteps[STEP_MS3_PCK_GFP].pDim()->size_Y(), vVD_ImgProcSteps[STEP_MS3_PCK_GFP].pDim()->size_X(), CV_8UC1);

    //step switch
    switch (step) {

    case STEP_MS3_VIS_NUCLEI_BORDERS_NO_REMOVE:
    case STEP_MS3_VIS_NUCLEI_BORDERS:
    {
        //draw nuclei
        ERR(D_Img_Proc::Draw_Contours(
                &MA_tmp_target,
                NucImg.get_nuclei_contours(1, -P_Offset),
                2,
                255),
            "Update_ImageProcessing_StepSingle_MS3_DrawDetections",
            QSL_Steps_MS3[step] + " - D_Img_Proc::Draw_Contours");
    }
        break;

    case STEP_MS3_VIS_NUCLEI_FILLED:
    {
        //draw nuclei
        ERR(D_Img_Proc::Draw_Contours(
                &MA_tmp_target,
                NucImg.get_nuclei_contours(1, -P_Offset),
                -1,
                255),
            "Update_ImageProcessing_StepSingle_MS3_DrawDetections",
            "STEP_MS3_VIS_NUCLEI_FILLED - D_Img_Proc::Draw_Contours");
    }
        break;

    case STEP_MS3_VIS_FOCI_GFP:
    case STEP_MS3_VIS_FOCI_RFP:
    case STEP_MS3_VIS_FOCI_BOTH:
    {
        //foci index
        size_t i_foci;
        switch (step) {
        case STEP_MS3_VIS_FOCI_GFP:     i_foci = FOCI_GFP;      break;
        case STEP_MS3_VIS_FOCI_RFP:     i_foci = FOCI_RFP;      break;
        case STEP_MS3_VIS_FOCI_BOTH:    i_foci = FOCI_BOTH;     break;
        default:                        i_foci = 0;             break;}

        //draw foci
        ERR(D_Img_Proc::Draw_Dots(
                &MA_tmp_target,
                NucImg.get_foci_centers(i_foci, 1.0, -P_Offset),
                NucImg.get_foci_diameters(i_foci, 1.0),
                255),
            "Update_ImageProcessing_StepSingle_MS3_DrawDetections",
            QSL_Steps_MS3[step] + " - D_Img_Proc::Draw_Contours");
    }
        break;

    default:
        break;
    }

    //convert to VD
    vVD_ImgProcSteps[step] = D_VisDat_Obj(vVD_ImgProcSteps[STEP_MS3_PCK_GFP].Dim(), CV_8UC1, 0);
    ERR(D_VisDat_Proc::Write_2D_Plane(
            &(vVD_ImgProcSteps[step]),
            &MA_tmp_target,
            D_VisDat_Slice_2D(-1, -1, 0, 0, 0, 0)),
        "Update_ImageProcessing_StepSingle_MS3_DrawDetections",
        "D_VisDat_Proc::Write_2D_Plane");
    MA_tmp_target.release();

    //update image decomposition when all foci are drawn
    if(step == STEP_MS3_VIS_FOCI_BOTH)
        Update_ImageDecomposition();
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepSingle_MS3_VisualizeResults(size_t step)
{
    if(step < STEP_MS3_VIS_REGIONS || step > STEP_MS3_VIS_REGIONS_FOCI_COUNT)
    {
        ERR(ER_index_out_of_range,
            "Update_ImageProcessing_StepSingle_MS3_VisualizeResults",
            "Index " + QSL_Steps_MS3[step] + " does not fit to this function");
        return;
    }

    switch (step) {

    case STEP_MS3_VIS_REGIONS:
    {
        //color code:
        //R: Nuclei Borders
        //G: GFP Foci
        //M: RFP Foci
        //W: GFP Foci + RFP Foci

        //merge to red channel
        D_VisDat_Obj VD_tmp_red;
        ERR(D_VisDat_Proc::Math_2img_Maximum(
                &VD_tmp_red,
                &(vVD_ImgProcSteps[STEP_MS3_VIS_NUCLEI_BORDERS]),
                &(vVD_ImgProcSteps[STEP_MS3_VIS_FOCI_RFP])),
            "Update_ImageProcessing_StepSingle_MS3_VisualizeResults",
            "STEP_MS3_VIS_NUCLEI_FILLED - Math_2img_Maximum calc red channel");

        //merge to rgb image
        ERR(D_VisDat_Proc::Channels_Merge(
                &(vVD_ImgProcSteps[STEP_MS3_VIS_REGIONS]),      //out
                &(vVD_ImgProcSteps[STEP_MS3_VIS_FOCI_RFP]),     //B
                &(vVD_ImgProcSteps[STEP_MS3_VIS_FOCI_GFP]),     //G
                &VD_tmp_red),                                   //R
            "Update_ImageProcessing_StepSingle_MS3_VisualizeResults",
            "STEP_MS3_VIS_NUCLEI_FILLED - Channels_Merge Nuclei and foci area as color");
    }
        break;

    case STEP_MS3_VIS_REGIONS_BACKGROUND:
    {
        ERR(D_VisDat_Proc::OverlayOverwrite(
                &(vVD_ImgProcSteps[STEP_MS3_VIS_REGIONS_BACKGROUND]),
                &(vVD_ImgProcSteps[STEP_MS3_VIS_PAGES_AS_COLOR_QUANTILS_GFP_RFP]),
                &(vVD_ImgProcSteps[STEP_MS3_VIS_REGIONS]),
                ui->doubleSpinBox_MS3_ImgProc_Vis_Intensity_Overlay->value() / 100.0,
                ui->doubleSpinBox_MS3_ImgProc_Vis_Intensity_Background->value() / 100.0),
            "Update_ImageProcessing_StepSingle_MS3_VisualizeResults",
            "STEP_MS3_VIS_REGIONS_BACKGROUND - OverlayOverwrite");
    }
        break;

    case STEP_MS3_VIS_REGIONS_FOCI_COUNT:
    {
        if(!state_image_decomposed)
        {
            ERR(ER_other, "Update_ImageProcessing_StepSingle", "STEP_VIS_REGIONS_FOCI_COUNT tried to acces unsuccesfull image decomp");
            vVD_ImgProcSteps[STEP_MS3_VIS_REGIONS_FOCI_COUNT] = vVD_ImgProcSteps[STEP_MS3_VIS_REGIONS_BACKGROUND];
            return;
        }

        //get pos in dataset
        int pos_x = ui->spinBox_Viewport_X->value();
        int pos_y = ui->spinBox_Viewport_Y->value();
        int pos_t = ui->spinBox_Viewport_T->value();

        //get foci counts as QStringList
        QStringList QSL_LabelTexts = QStringList();
        vvvImageDecomp_TYX[pos_t][pos_y][pos_x].get_FociCount_append(&QSL_LabelTexts);

        int ER = D_VisDat_Proc::Draw_Label_Text(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &(vVD_ImgProcSteps[STEP_MS3_VIS_REGIONS_FOCI_COUNT]),
                    &(vVD_ImgProcSteps[STEP_MS3_VIS_REGIONS_BACKGROUND]),
                    &(vVD_ImgProcSteps[STEP_MS3_VIS_NUCLEI_FILLED]),
                    QSL_LabelTexts,
                    false,
                    1.0, 2,
                    true,
                    255, 255, 255,
                    4);
        ERR(ER, "Update_ImageProcessing_StepSingle_MS3_VisualizeResults", "STEP_MS3_VIS_REGIONS_FOCI_COUNT - put numbers on image");
        if(ER != ER_okay)
            return;
    }
        break;

    default:
        return;
    }


}

void D_MAKRO_MegaFoci::ImageDecomp_Init()
{
    vvvImageDecomp_TYX.clear();
    vector<D_Bio_NucleusImage> vImageDecomp_Init_X(dataset_dim_mosaic_x, D_Bio_NucleusImage());
    vector<vector<D_Bio_NucleusImage>> vvImageDecomp_Init_YX(dataset_dim_mosaic_y, vImageDecomp_Init_X);
    vvvImageDecomp_TYX.resize(dataset_dim_t, vvImageDecomp_Init_YX);

    vvvImageDecompCalced_TYX.clear();
    vector<int> vImageDecompCalced_Init_X(dataset_dim_mosaic_x, 0);
    vector<vector<int>> vvImageDecompCacled_Init_YX(dataset_dim_mosaic_y, vImageDecompCalced_Init_X);
    vvvImageDecompCalced_TYX.resize(dataset_dim_t, vvImageDecompCacled_Init_YX);

    state_image_decomposition_init = true;
}

void D_MAKRO_MegaFoci::Update_ImageDecomposition()
{
    state_image_decomposed = false;
    if(!state_image_decomposition_init)
        return;

    ///vector of foci segmentation images indices
    vector<size_t> vIndices_FociBinary(FOCI_NUMBER_OF);
    if(mode_major_current == MODE_MAJOR_1_AUTO_DETECTION)
    {
        vIndices_FociBinary[FOCI_GFP]   = STEP_FOC_GFP_SELECT_AREA;
        vIndices_FociBinary[FOCI_RFP]   = STEP_FOC_RFP_SELECT_AREA;
        vIndices_FociBinary[FOCI_BOTH]  = STEP_FOC_BOTH_SELECT_AREA;
    }
    else if(mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
    {
        vIndices_FociBinary[FOCI_GFP]   = STEP_MS3_VIS_FOCI_GFP;
        vIndices_FociBinary[FOCI_RFP]   = STEP_MS3_VIS_FOCI_RFP;
        vIndices_FociBinary[FOCI_BOTH]  = STEP_MS3_VIS_FOCI_BOTH;
    }
    else
        return;

    ///list of value image indices (GFP and RFP)
    vector<size_t> vIndices_Values(3);
    if(mode_major_current == MODE_MAJOR_1_AUTO_DETECTION)
    {
        vIndices_Values[0] = STEP_PCK_OTHER;
        vIndices_Values[1] = STEP_PCK_GFP;
        vIndices_Values[2] = STEP_PCK_RFP;
    }
    else if(mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
    {
        vIndices_Values[0] = STEP_MS3_PCK_OTHER;
        vIndices_Values[1] = STEP_MS3_PCK_GFP;
        vIndices_Values[2] = STEP_MS3_PCK_RFP;
    }

    ///get position in dataset
    int pos_x = ui->spinBox_Viewport_X->value();
    int pos_y = ui->spinBox_Viewport_Y->value();
    int pos_t = ui->spinBox_Viewport_T->value();

    ///geometric moisaik offset in pixels
    Point MosaikOffset_Coordinates(
                pos_x * (dataset_dim_img_x - ui->spinBox_ImgProc_Stitch_Overlap_x->value()),
                pos_y * (dataset_dim_img_y - ui->spinBox_ImgProc_Stitch_Overlap_y->value()));
    Point MosaikOffset_Grid(pos_x, pos_y);

    ///get index of nuclei segmentation image
    size_t index_nuclei;
    if(mode_major_current == MODE_MAJOR_1_AUTO_DETECTION)
        index_nuclei = STEP_NUC_GFP_SEG3_BINARY_SEGMENTS;
    else if(mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
        index_nuclei = STEP_MS3_VIS_NUCLEI_FILLED;
    else
        return;

    ///calculate image decomposition to bio info format
    StatusSet("Nuclei image decomposition");
    int ER = vvvImageDecomp_TYX[pos_t][pos_y][pos_x].calc_NucleiDecomposition(
                &vVD_ImgProcSteps,
                index_nuclei,
                vIndices_FociBinary,
                vIndices_Values,
                MosaikOffset_Coordinates,
                MosaikOffset_Grid,
                ui->spinBox_Viewport_T->value(),
                4,
                true,
                MosaikOffset_Coordinates.x + dataset_dim_img_x,
                MosaikOffset_Coordinates.y + dataset_dim_img_y);
    ERR(
                ER,
                "Update_ImageDecomposition",
                "ImageDecomp.calc_NucleiDecomposition");
    if(ER != ER_okay)
        return;

    ///remember current pos as calced
    vvvImageDecompCalced_TYX[pos_t][pos_y][pos_x] = static_cast<int>(true);
    state_image_decomposed = true;

    ///save data in files if stack processing is running
    if(state_stack_processing)
    {
        //mode
        StatusSet("Save decomposition in files");
        if(mode_major_current == MODE_MAJOR_1_AUTO_DETECTION)
        {
            ERR(
                    vvvImageDecomp_TYX[pos_t][pos_y][pos_x].save(
                            DIR_SaveDetections.path(),  //path to save to
                            false,                      //don't save foci matched to nuclei
                            true,                       //save foci as separate file
                            true),                      //mosaic grid coordinates in names instead of global pixel coordinates
                    "Update_ImageDecomposition",
                    "MS1 - ImageDecomp.save(DIR_SaveDetections.path())");
        }
        else if(mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
        {
            ERR(
                    vvvImageDecomp_TYX[pos_t][pos_y][pos_x].save(
                            DIR_SaveDetections.path(),              //path to save to
                            true,                                   //save foci matched to nuclei
                            false,                                  //don't save foci as separate file
                            true),                                  //mosaic grid coordinates in names instead of global pixel coordinates
                    "Update_ImageDecomposition",
                    "MS3 - ImageDecomp.save(DIR_MS3_Out_DetectionsAssigned.path())");
        }
        else
        {
            return;
        }
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
                "<br>This will take long. Up to <b>" + QString::number(dataset_dim_t * dataset_dim_mosaic_x * dataset_dim_mosaic_y) + "</b> images will be processed."
                "<br>This number can be reduced in the next dialog."
                "<br>Do you want to continue?")
            != QMessageBox::Yes)
        return;

    ///get processing range
    StatusSet("Get processing range");
    Vec<int, c_DIM_NUMBER_OF> proc_range_min    = {0, 0, 0, 0, 0, 0};
    Vec<int, c_DIM_NUMBER_OF> proc_range_max    = {static_cast<int>(dataset_dim_mosaic_x - 1), static_cast<int>(dataset_dim_mosaic_y - 1), 0, static_cast<int>(dataset_dim_t - 1), 0, 0};
    Vec<int, c_DIM_NUMBER_OF> proc_range_start  = proc_range_min;
    Vec<int, c_DIM_NUMBER_OF> proc_range_end    = proc_range_max;
    D_PopUp_RangeSelector pop_range_select(
                &proc_range_start,
                &proc_range_end,
                proc_range_min,
                proc_range_max,
                "Enter processing range (XY: mosaic segments, T: Frames)",
                true, true, false, true, false, false,
                this);
    pop_range_select.exec();

    ///get save location
    StatusSet("Get save dir");
    QString QS_SavePath = QFileDialog::getExistingDirectory(
                this,
                "Select save directory for results of stack processing",
                pStore->dir_M_MegaFoci_Results()->path());

    ///check if save location is valid
    if(QS_SavePath.isEmpty())
    {
        StatusSet("Quit because no dir was selected");
        return;
    }
    pStore->set_dir_M_MegaFoci_Results(QS_SavePath);

    ///current mode to string
    QString QS_ModeString;
    if(mode_major_current == MODE_MAJOR_1_AUTO_DETECTION)
        QS_ModeString = "Step1";
    else if (mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
        QS_ModeString = "Step3";
    else
        return;

    ///Create new save dir
    size_t count = 0;
    QString QS_Folder_Out_Sub = QS_SavePath + "/Results_" + QS_ModeString + "_0";
    while(QDir(QS_Folder_Out_Sub).exists())
    {
        count++;
        QS_Folder_Out_Sub = QS_SavePath + "/Results_" + QS_ModeString + "_" + QString::number(count);
    }

    ///masterfolder
    DIR_SaveMaster.setPath(QS_Folder_Out_Sub);
    QDir().mkdir(DIR_SaveMaster.path());

    ///Save subfolders
    if(mode_major_current == MODE_MAJOR_1_AUTO_DETECTION)
    {
        DIR_SaveMosaik_All.setPath(DIR_SaveMaster.path() + "/Mosaik");                      QDir().mkdir(DIR_SaveMosaik_All.path());
        DIR_SaveMosaik_Color.setPath(DIR_SaveMosaik_All.path() + "/Color");                 QDir().mkdir(DIR_SaveMosaik_Color.path());
        DIR_SaveMosaik_DIC.setPath(DIR_SaveMosaik_All.path() + "/DIC");                     QDir().mkdir(DIR_SaveMosaik_DIC.path());
        DIR_SaveMosaik_GFP.setPath(DIR_SaveMosaik_All.path() + "/GFP");                     QDir().mkdir(DIR_SaveMosaik_GFP.path());
        DIR_SaveMosaik_RFP.setPath(DIR_SaveMosaik_All.path() + "/RFP");                     QDir().mkdir(DIR_SaveMosaik_RFP.path());
        DIR_SaveMosaik_Info_Foci.setPath(DIR_SaveMosaik_All.path() + "/AutoDetections");    QDir().mkdir(DIR_SaveMosaik_Info_Foci.path());
        DIR_SaveDetections.setPath(DIR_SaveMaster.path() + "/Detections");                  QDir().mkdir(DIR_SaveDetections.path());
    }
    else if (mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
    {
        DIR_SaveMosaik_All.setPath(DIR_SaveMaster.path() + "/Mosaik");                                              QDir().mkdir(DIR_SaveMosaik_All.path());
        DIR_SaveMosaik_Info_Foci.setPath(DIR_SaveMosaik_All.path() + "/AssignedFoci");                              QDir().mkdir(DIR_SaveMosaik_Info_Foci.path());
        DIR_SaveMosaik_Info_Shape.setPath(DIR_SaveMosaik_All.path() + "/NucleiShape");                              QDir().mkdir(DIR_SaveMosaik_Info_Shape.path());
        DIR_SaveMosaik_Info_Value_Mean.setPath(DIR_SaveMosaik_All.path() + "/Value_Mean");                          QDir().mkdir(DIR_SaveMosaik_Info_Value_Mean.path());
        DIR_SaveMosaik_Info_Value_STD.setPath(DIR_SaveMosaik_All.path() + "/Value_STD");                            QDir().mkdir(DIR_SaveMosaik_Info_Value_STD.path());
        DIR_SaveMosaik_Info_Value_Skewness.setPath(DIR_SaveMosaik_All.path() + "/Value_Skewness");                  QDir().mkdir(DIR_SaveMosaik_Info_Value_Skewness.path());
        DIR_SaveMosaik_Info_Value_Kurtosis.setPath(DIR_SaveMosaik_All.path() + "/Value_Kurtosis");                  QDir().mkdir(DIR_SaveMosaik_Info_Value_Kurtosis.path());
        DIR_SaveMosaik_Info_Value_Median.setPath(DIR_SaveMosaik_All.path() + "/Value_Median");                      QDir().mkdir(DIR_SaveMosaik_Info_Value_Median.path());
        DIR_SaveMosaik_Info_Value_MedianDeviation.setPath(DIR_SaveMosaik_All.path() + "/Value_MedianDeviation");    QDir().mkdir(DIR_SaveMosaik_Info_Value_MedianDeviation.path());
        DIR_SaveDetections.setPath(DIR_SaveMaster.path() + "/DetectionsAssigned");                                  QDir().mkdir(DIR_SaveDetections.path());
    }
    else
        return;

    //make error handler stream to file instead of showing popups
    StatusSet("Disabling error popups. Error log can be found in:" + DIR_SaveMaster.path() + "/ErrorLog.csv");
    ER.set_Popup_active(false);
    ER.set_FileStream_path_csv(DIR_SaveMaster.path() + "/ErrorLog.csv");

    //set ui
    ui->tabWidget_Control->setCurrentIndex(TAB_CONTROL_VIEWPORT);

    //start the stack processing :-)
    StatusSet("Start to loop all viewports");
    StatusSet("Time to get a (lot of) cofee.");
    state_stack_processing = true;
    this->setEnabled(false);

    //finish time prognosis
    D_FinishTimePrognosis TimePrognosis(
                ui->progressBar_StackLoop,
                (proc_range_end[c_DIM_X] - proc_range_start[c_DIM_X] + 1) *
                (proc_range_end[c_DIM_Y] - proc_range_start[c_DIM_Y] + 1) *
                (proc_range_end[c_DIM_T] - proc_range_start[c_DIM_T] + 1));

    //loop viewports
    TimePrognosis.start();
    for(int t = proc_range_start[c_DIM_T]; t <= proc_range_end[c_DIM_T]; t++)
    {
        if(mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
            if(!MS3_LoadDetections(t))
            {
                StatusSet("MS3_LoadDetections(" + QString::number(t) + ") failed " + QS_Fun_Sad);
                ERR(
                            ER_file_not_exist,
                            "Stack_Process_All",
                            "MS3_LoadDetections(" + QString::number(t) + ") failed to load detections");
            }

        for(int y = proc_range_start[c_DIM_Y]; y <= proc_range_end[c_DIM_Y]; y++)
        {
            for(int x = proc_range_start[c_DIM_X]; x <= proc_range_end[c_DIM_X]; x++)
            {                
                StatusSet("STACK PROC T" + QString::number(t) + " Y" + QString::number(y) + " X" + QString::number(x));

                //change position in ui
                //block signals
                ui->spinBox_Viewport_T->blockSignals(true);
                ui->spinBox_Viewport_Y->blockSignals(true);
                ui->spinBox_Viewport_X->blockSignals(true);
                ui->spinBox_OverviewBig_T->blockSignals(true);
                //change ui
                ui->spinBox_Viewport_T->setValue(t);
                ui->spinBox_Viewport_Y->setValue(y);
                ui->spinBox_Viewport_X->setValue(x);
                ui->spinBox_OverviewBig_T->setValue(t);
                //unblock signals
                ui->spinBox_Viewport_T->blockSignals(false);
                ui->spinBox_Viewport_Y->blockSignals(false);
                ui->spinBox_Viewport_X->blockSignals(false);
                ui->spinBox_OverviewBig_T->blockSignals(false);

                //trigger proc at current pos
                Stack_Porcess_Single_XYT_Viewport();

                //update finish time prognosis
                TimePrognosis.step();
            }
        }
    }

    TimePrognosis.end();
    StatusSet("STACK PROC FINISHED :-)");

    //enable error popups
    ER.set_Popup_active(true);
    ER.set_FileStream_active(false);

    this->setEnabled(true);
    state_stack_processing = false;
}

/*!
 * \brief D_MAKRO_MegaFoci::Stack_Porcess_Single_XYT_Viewport update stack processing step for single vieport position step1/step3
 */
void D_MAKRO_MegaFoci::Stack_Porcess_Single_XYT_Viewport()
{
    ///Update image processing
    Update_ImageProcessing_CurrentImage();

    ///Overwrite and update mosaik
    ui->comboBox_OverviewBig_Type->blockSignals(true);

    ///step1 mosaiks
    if(mode_major_current == MODE_MAJOR_1_AUTO_DETECTION)
    {
        ///Mosaik dic
        ui->comboBox_OverviewBig_Type->setCurrentIndex(OVERVIEW_TYPE_DIC);
        Update_Images_OverviewBig();
        Viewer_OverviewBig.Save_Image(DIR_SaveMosaik_DIC.path() + "/Mosaik_DIC_T" + QString::number(ui->spinBox_Viewport_T->value()) + ".png");

        ///Mosaik gfp
        ui->comboBox_OverviewBig_Type->setCurrentIndex(OVERVIEW_TYPE_GFP);
        Update_Images_OverviewBig();
        Viewer_OverviewBig.Save_Image(DIR_SaveMosaik_GFP.path() + "/Mosaik_GFP_T" + QString::number(ui->spinBox_Viewport_T->value()) + ".png");

        ///Mosaik rfp
        ui->comboBox_OverviewBig_Type->setCurrentIndex(OVERVIEW_TYPE_RFP);
        Update_Images_OverviewBig();
        Viewer_OverviewBig.Save_Image(DIR_SaveMosaik_RFP.path() + "/Mosaik_RFP_T" + QString::number(ui->spinBox_Viewport_T->value()) + ".png");

        ///Mosaik color
        ui->comboBox_OverviewBig_Type->setCurrentIndex(OVERVIEW_TYPE_COLOR);
        Update_Images_OverviewBig();
        Viewer_OverviewBig.Save_Image(DIR_SaveMosaik_Color.path() + "/Mosaik_Color_T" + QString::number(ui->spinBox_Viewport_T->value()) + ".png");

        ///Mosaik foci
        ui->comboBox_OverviewBig_Type->setCurrentIndex(OVERVIEW_TYPE_INFO_FOCI);
        Update_Images_OverviewBig();
        Viewer_OverviewBig.Save_Image(DIR_SaveMosaik_Info_Foci.path() + "/Mosaik_AutoDetections_T" + QString::number(ui->spinBox_Viewport_T->value()) + ".png");
    }
    ///step3 mosaiks
    else if(mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
    {
        ///mandatory mosaiks
        ///Mosaik foci
        ui->comboBox_OverviewBig_Type->setCurrentIndex(OVERVIEW_TYPE_INFO_FOCI);
        Update_Images_OverviewBig();
        Viewer_OverviewBig.Save_Image(DIR_SaveMosaik_Info_Foci.path() + "/Mosaik_Foci_T" + QString::number(ui->spinBox_Viewport_T->value()) + ".png");

        ///optional mosaiks
        if(ui->checkBox_MS3_StackProc_SaveAdditionalMosaics->isChecked())
        {
            ///Mosaik shape
            ui->comboBox_OverviewBig_Type->setCurrentIndex(OVERVIEW_TYPE_INFO_SHAPE);
            Update_Images_OverviewBig();
            Viewer_OverviewBig.Save_Image(DIR_SaveMosaik_Info_Shape.path() + "/Mosaik_Shape_T" + QString::number(ui->spinBox_Viewport_T->value()) + ".png");

            ///Mosaik value mean
            ui->comboBox_OverviewBig_Type->setCurrentIndex(OVERVIEW_TYPE_INFO_VALUE_MEAN);
            Update_Images_OverviewBig();
            Viewer_OverviewBig.Save_Image(DIR_SaveMosaik_Info_Value_Mean.path() + "/Mosaik_Value_Mean_T" + QString::number(ui->spinBox_Viewport_T->value()) + ".png");

            ///Mosaik value std
            ui->comboBox_OverviewBig_Type->setCurrentIndex(OVERVIEW_TYPE_INFO_VALUE_STD);
            Update_Images_OverviewBig();
            Viewer_OverviewBig.Save_Image(DIR_SaveMosaik_Info_Value_STD.path() + "/Mosaik_Value_STD_T" + QString::number(ui->spinBox_Viewport_T->value()) + ".png");

            ///Mosaik value skewness
            ui->comboBox_OverviewBig_Type->setCurrentIndex(OVERVIEW_TYPE_INFO_VALUE_SKEWNESS);
            Update_Images_OverviewBig();
            Viewer_OverviewBig.Save_Image(DIR_SaveMosaik_Info_Value_Skewness.path() + "/Mosaik_Value_Skewness_T" + QString::number(ui->spinBox_Viewport_T->value()) + ".png");

            ///Mosaik value kurtosis
            ui->comboBox_OverviewBig_Type->setCurrentIndex(OVERVIEW_TYPE_INFO_VALUE_KURTOSIS);
            Update_Images_OverviewBig();
            Viewer_OverviewBig.Save_Image(DIR_SaveMosaik_Info_Value_Kurtosis.path() + "/Mosaik_Value_Kurtosis_T" + QString::number(ui->spinBox_Viewport_T->value()) + ".png");

            ///Mosaik value median
            ui->comboBox_OverviewBig_Type->setCurrentIndex(OVERVIEW_TYPE_INFO_VALUE_MEDIAN);
            Update_Images_OverviewBig();
            Viewer_OverviewBig.Save_Image(DIR_SaveMosaik_Info_Value_Median.path() + "/Mosaik_Value_Median_T" + QString::number(ui->spinBox_Viewport_T->value()) + ".png");

            ///Mosaik value median deviation
            ui->comboBox_OverviewBig_Type->setCurrentIndex(OVERVIEW_TYPE_INFO_VALUE_MED_DEV);
            Update_Images_OverviewBig();
            Viewer_OverviewBig.Save_Image(DIR_SaveMosaik_Info_Value_MedianDeviation.path() + "/Mosaik_Value_MedianDeviation_T" + QString::number(ui->spinBox_Viewport_T->value()) + ".png");
        }
    }

    ui->comboBox_OverviewBig_Type->blockSignals(false);
}

void D_MAKRO_MegaFoci::Populate_CB_AtStart()
{
    StatusSet("Populate the dropdown menus");

    Populate_CB_Single(ui->comboBox_VisTrafo_CropMode,                      QSL_VisTrafo_Crop,      c_VIS_TRAFO_CROP_DYNAMIC);
    Populate_CB_Single(ui->comboBox_VisTrafo_TransformationMode,            QSL_VisTrafo,           c_VIS_TRAFO_LOG);
    Populate_CB_Single(ui->comboBox_VisTrafo_AnchorMode,                    QSL_VisTrafo_Anchor,    c_VIS_TRAFO_ANCHOR_DYNAMIC);
    Populate_CB_Single(ui->comboBox_VisTrafo_RangeMode,                     QSL_VisTrafo_Range,     c_VIS_TRAFO_RANGE_DYNAMIC);

    Populate_CB_Single(ui->comboBox_ImgProc_StepShow,                       QSL_Steps,              STEP_VIS_REGIONS_FOCI_COUNT);

    Populate_CB_Single(ui->comboBox_ImgProc_ProjectZ_Stat,                  QSL_StatList,           c_STAT_QUANTIL_95);

    Populate_CB_Single(ui->comboBox_OverviewBig_Type,                       QSL_OverviewTypes,      OVERVIEW_TYPE_COLOR);
}

void D_MAKRO_MegaFoci::Populate_CB_Single(QComboBox *CB, QStringList QSL, int init_index)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(init_index);
    CB->blockSignals(false);
}

void D_MAKRO_MegaFoci::ConnectViewersVisTrafo(D_Viewer *view)
{
    connect(ui->groupBox_VisTrafo,                          SIGNAL(clicked(bool)),                      view,   SLOT(Set_VisTrafo_ActiveBool(bool)));
    connect(ui->doubleSpinBox_VisTrafo_CropMin,             SIGNAL(valueChanged(double)),               view,   SLOT(Set_VisTrafo_SpreadInMin(double)));
    connect(ui->doubleSpinBox_VisTrafo_CropMax,             SIGNAL(valueChanged(double)),               view,   SLOT(Set_VisTrafo_SpreadInMax(double)));
    connect(ui->doubleSpinBox_VisTrafo_Gamma,               SIGNAL(valueChanged(double)),               view,   SLOT(Set_VisTrafo_Gamma(double)));
    connect(ui->doubleSpinBox_VisTrafo_LogCenter,           SIGNAL(valueChanged(double)),               view,   SLOT(Set_VisTrafo_Center(double)));
    connect(ui->doubleSpinBox_VisTrafo_LogDivisor,          SIGNAL(valueChanged(double)),               view,   SLOT(Set_VisTrafo_Divisor(double)));
    connect(ui->doubleSpinBox_VisTrafo_Anchor,              SIGNAL(valueChanged(double)),               view,   SLOT(Set_VisTrafo_Anchor(double)));
    connect(ui->doubleSpinBox_VisTrafo_Range,               SIGNAL(valueChanged(double)),               view,   SLOT(Set_VisTrafo_Range(double)));
    connect(ui->comboBox_VisTrafo_CropMode,                 SIGNAL(currentIndexChanged(int)),           view,   SLOT(Set_VisTrafo_Mode_Crop(int)));
    connect(ui->comboBox_VisTrafo_TransformationMode,       SIGNAL(currentIndexChanged(int)),           view,   SLOT(Set_VisTrafo_Mode_Trafo(int)));
    connect(ui->comboBox_VisTrafo_AnchorMode,               SIGNAL(currentIndexChanged(int)),           view,   SLOT(Set_VisTrafo_Mode_Anchor(int)));
    connect(ui->comboBox_VisTrafo_RangeMode,                SIGNAL(currentIndexChanged(int)),           view,   SLOT(Set_VisTrafo_Mode_Range(int)));
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
                    "<br>B) 3 exist, 2 used, other@0, GFP@1, RFP@2 (other just for visualization)",
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
                "Load images (Should be " + QString::number(dataset_dim_xyt) + " .tif files)",
                pStore->dir_M_MegaFoci_Images()->path(),
                "Image files (*.tif *.TIF *.tiff *.TIFF)");
    if(QSl_Paths.empty())
        return false;

    //set default dir
    pStore->set_dir_M_MegaFoci_Images(QSl_Paths.first());

    //check image count vs definition of data set
    if(static_cast<size_t>(QSl_Paths.size()) != dataset_dim_xyt)
    {
        ERR(
                    ER_dim_missmatch,
                    "Load_Dataset",
                    "Dataset defined mosaic image count: " + QString::number(dataset_dim_mosaic_x) + "x * " + QString::number(dataset_dim_mosaic_y) + "y * " + QString::number(dataset_dim_t) + "t = <b>" + QString::number(dataset_dim_xyt) + "</b>."
                    "<br>Count of images tried to load: <b>" + QString::number(QSl_Paths.size()) + "</b>."
                    "<br>These values should match."
                    "<br>Please try again with an image list of fitting size"
                    "<br>or adjust expected xy mosaik dimension."
                    "<br>"
                    "<br>Typical image name:"
                    "<br><I>Firewoodrental_m000042_t000069.tif</I>"
                    "<br>Where m is the serialised yx index and t ist the t index.");
        return false;
    }

    //update state
    state_dataset_dim_set = true;
    state_first_proc_on_start = true;

    //clear old lists
    QSL_ImagesYXT_Paths.clear();
    QSL_ImagesYXT_Names.clear();
    QSL_ImagesYXT_Suffix.clear();
    FIL_ImagesYXT.clear();

    //fill listst for easy access
    for(int f = 0; f < QSl_Paths.size(); f++)
    {
        //basics
        QString QS_Path = QSl_Paths[f];
        QFileInfo FI_Img = QFileInfo(QS_Path);
        QString QS_Name = FI_Img.baseName();
        QString QS_Suffix = FI_Img.suffix();

        //lists
        QSL_ImagesYXT_Paths.append(QS_Path);
        QSL_ImagesYXT_Names.append(FI_Img.baseName());
        QSL_ImagesYXT_Suffix.append(FI_Img.suffix());
        FIL_ImagesYXT.append(FI_Img);
    }

    //img size
    StatusSet("Get base image size");
    Mat MA_tmp_SizeGetter;
    ERR(
                D_Img_Proc::Load_From_Path(
                    &MA_tmp_SizeGetter,
                    FIL_ImagesYXT[0]),
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
    ui->pushButton_DataLoad->setEnabled(false);
    ui->groupBox_VisTrafo->setEnabled(true);
    ui->groupBox_View->setEnabled(true);
    ui->groupBox_Control->setEnabled(true);
    ui->tabWidget_Control->setCurrentIndex(TAB_CONTROL_VIEWPORT);

    //update states
    state_dataset_img_list_loaded = true;
    StatusSet("Dataset is valid :-)");

    //Init Overview
    Overview_Init();

    //init image decomp
    StatusSet("Initializing nuclei imgae decomposition\n(fancy thing that reduces images to relevant nuclei/foci info)");
    ImageDecomp_Init();

    //init img buffer
    StatusSet("Initializing image buffer");
    ImgBuffer_Init();

    //if MS3, load detections from step 2
    if(mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
    {
        if(!MS3_LoadDirs())
            return false;

        if(!MS3_LoadDetections(0))
            return false;
    }

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

    ///get overlap in px
    size_t overlap_px_x = ui->spinBox_ImgProc_Stitch_Overlap_x->value();
    size_t overlap_px_y = ui->spinBox_ImgProc_Stitch_Overlap_y->value();

    ///init overview normal
    VD_Overview_Save = D_VisDat_Obj(
                D_VisDat_Dim(
                    static_cast<int>(((dataset_dim_mosaic_x * dataset_dim_img_x) - ((dataset_dim_mosaic_x - 1) * overlap_px_x)) * overview_scale),
                    static_cast<int>(((dataset_dim_mosaic_y * dataset_dim_img_y) - ((dataset_dim_mosaic_y - 1) * overlap_px_y)) * overview_scale),
                    1,
                    static_cast<int>(dataset_dim_t),
                    1,
                    1),
                CV_8UC3,
                0);

    state_overview_init = true;
}

void D_MAKRO_MegaFoci::Overview_Update()
{
    if(!state_overview_init || !state_dataset_dim_set)
        return;

    ///get overlap in px
    size_t overlap_px_x = ui->spinBox_ImgProc_Stitch_Overlap_x->value();
    size_t overlap_px_y = ui->spinBox_ImgProc_Stitch_Overlap_y->value();

    ///get border in %
    double border_prz = ui->doubleSpinBox_ImgProc_Stitch_Border->value() / 100.0;

    ///scale down
    D_VisDat_Obj VD_tmp_CurrentColorScaled;
    ERR(D_VisDat_Proc::Scale_ToSize(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &VD_tmp_CurrentColorScaled,
                &(vVD_ImgProcSteps[STEP_VIS_PAGES_AS_COLOR_ALL]),
                static_cast<int>((dataset_dim_img_x * (1.0 + border_prz)) * overview_scale),
                static_cast<int>((dataset_dim_img_y * (1.0 + border_prz)) * overview_scale)),
        "Overview_Update",
        "D_VisDat_Proc::Scale_ToSize");

    ///get position in dataset
    int pos_x = ui->spinBox_Viewport_X->value();
    int pos_y = ui->spinBox_Viewport_Y->value();
    int pos_t = ui->spinBox_Viewport_T->value();

    ///calc target offset
    vector<int> vOffset(c_DIM_NUMBER_OF, 0);
    vOffset[c_DIM_X] = pos_x * (dataset_dim_img_x - overlap_px_x) * overview_scale;
    vOffset[c_DIM_Y] = pos_y * (dataset_dim_img_y - overlap_px_y) * overview_scale;
    vOffset[c_DIM_T] = pos_t;

    //insert in overview
    ERR(D_VisDat_Proc::Insert_atPos(
                &VD_Overview_Save,
                &VD_tmp_CurrentColorScaled,
                vOffset),
        "Overview_Update",
        "D_VisDat_Proc::Instert_atPos"
        "<br>VD_Overview_Normal_Save " + VD_Overview_Save.info() +
        "<br>VD_tmp_CurrentColorScaled " + VD_tmp_CurrentColorScaled.info());

    Update_Images_OverviewSmall();
    if(ui->tabWidget_Control->currentIndex() == TAB_CONTROL_OVERVIEW_BIG && ui->comboBox_OverviewBig_Type->currentIndex() < OVERVIEW_TYPE_INFO_FOCI)
        Update_Images_OverviewBig();
}

void D_MAKRO_MegaFoci::set_dataset_dim_x(int x)
{
    if(!state_dataset_dim_set)
    {
        dataset_dim_mosaic_x = x;
        dataset_dim_mosaic_xy = dataset_dim_mosaic_x * dataset_dim_mosaic_y;
        set_LoadButton_FilelistSize();
    }
}

void D_MAKRO_MegaFoci::set_dataset_dim_y(int y)
{
    if(!state_dataset_dim_set)
    {
        dataset_dim_mosaic_y = y;
        dataset_dim_mosaic_xy = dataset_dim_mosaic_x * dataset_dim_mosaic_y;
        dataset_dim_xyt = dataset_dim_mosaic_xy * dataset_dim_t;
        set_LoadButton_FilelistSize();
    }
}

void D_MAKRO_MegaFoci::set_dataset_dim_t(int t)
{
    if(!state_dataset_dim_set)
    {
        dataset_dim_t = t;
        dataset_dim_tzp_used = dataset_dim_t * dataset_dim_z * dataset_dim_p_used;
        dataset_dim_tzp_exist = dataset_dim_t * dataset_dim_z * dataset_dim_p_exist;
        dataset_dim_xyt = dataset_dim_mosaic_xy * dataset_dim_t;
        set_LoadButton_FilelistSize();
    }
}

void D_MAKRO_MegaFoci::set_dataset_dim_z(int z)
{
    if(!state_dataset_dim_set)
    {
        dataset_dim_z = z;
        dataset_dim_tzp_used = dataset_dim_t * dataset_dim_z * dataset_dim_p_used;
        dataset_dim_tzp_exist = dataset_dim_t * dataset_dim_z * dataset_dim_p_exist;
    }
}

void D_MAKRO_MegaFoci::set_LoadButton_FilelistSize()
{
    ui->pushButton_DataLoad->setText("Load Dataset (" + QString::number(dataset_dim_xyt) + " Files)");
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

size_t D_MAKRO_MegaFoci::get_index_of_image(size_t x, size_t y, size_t t)
{
    size_t idx_yxt = (dataset_dim_t * dataset_dim_mosaic_x * y) + (dataset_dim_t * x) + (t);
    return idx_yxt < dataset_dim_xyt ? idx_yxt : 0;
}

size_t D_MAKRO_MegaFoci::get_index_of_page(size_t z, size_t p)
{
    size_t idx_zp = (dataset_dim_p_exist * z) + (p);
    return idx_zp < dataset_dim_p_exist * dataset_dim_z ? idx_zp : 0;
}

void D_MAKRO_MegaFoci::ImgBuffer_Init()
{
    ///buffer size
    //☐ ☐ ☐ ☐ ☐ ☐
    //☐ ☐ ■ ■ ■ ■
    //■ ■ ■ ☐ ☐ ☐
    //☐ ☐ ☐ ☐ ☐ ☐
    ImgLoadBuffer_BufferSize = dataset_dim_mosaic_x + 1;

    ///init img buffer
    vVD_ImgLoadBuffer.resize(
                ImgLoadBuffer_BufferSize,
                D_VisDat_Obj(
                    D_VisDat_Dim(
                        dataset_dim_img_x,
                        dataset_dim_img_y,
                        dataset_dim_z,
                        1,
                        1,
                        dataset_dim_p_exist),
                    dataset_type_mat,
                    0));

    ///init indices in dataset of images in buffer
    vv_ImgLoadBuffer_XYT_Index.resize(3, vector<int>(ImgLoadBuffer_BufferSize, -1));
}

void D_MAKRO_MegaFoci::ImgBuffer_Write(D_VisDat_Obj *img, int x_img, int y_img, int t_img)
{
    ///find oldest
    int value_min_t = INFINITY;
    vector<size_t> v_index_min_t;
    for(size_t i = 0; i < ImgLoadBuffer_BufferSize; i++)
    {
        int t = vv_ImgLoadBuffer_XYT_Index[2][i];
        if(t <= value_min_t)
        {
            if(t < value_min_t)
            {
                v_index_min_t.clear();
                value_min_t = t;
            }

            v_index_min_t.push_back(i);
        }
    }

    ///find topmost among oldest
    int value_min_y = INFINITY;
    vector<size_t> v_index_min_y;
    for(size_t j = 0; j < v_index_min_t.size(); j++)
    {
        int i = v_index_min_t[j];
        int y = vv_ImgLoadBuffer_XYT_Index[1][i];
        if(y <= value_min_y)
        {
            if(y < value_min_y)
            {
                v_index_min_y.clear();
                value_min_y = y;
            }

            v_index_min_y.push_back(i);
        }
    }

    ///find find leftmost among topmost among oldest (target position for overwriting)
    int value_min_x = INFINITY;
    size_t target_index = 0;
    for(size_t j = 0; j < v_index_min_y.size(); j++)
    {
        int i = v_index_min_y[j];
        int x = vv_ImgLoadBuffer_XYT_Index[0][i];
        if(x < value_min_x)
        {
            value_min_x = x;
            target_index = i;
        }
    }

    ///overwrite oldest img in buffer
    StatusSet("Write image to buffer");
    vVD_ImgLoadBuffer[target_index] = *img;

    ///save position of new img
    vv_ImgLoadBuffer_XYT_Index[0][target_index] = x_img;
    vv_ImgLoadBuffer_XYT_Index[1][target_index] = y_img;
    vv_ImgLoadBuffer_XYT_Index[2][target_index] = t_img;
}

int D_MAKRO_MegaFoci::ImgBuffer_Find(int x, int y, int t)
{
    ///check if img is in buffer
    for(size_t i = 0; i < vv_ImgLoadBuffer_XYT_Index[0].size(); i++)
        if(x == vv_ImgLoadBuffer_XYT_Index[0][i])
            if(y == vv_ImgLoadBuffer_XYT_Index[1][i])
                if(t == vv_ImgLoadBuffer_XYT_Index[2][i])
                    return static_cast<int>(i);

    return -1;
}

bool D_MAKRO_MegaFoci::ImgBuffer_Read(D_VisDat_Obj *img, size_t i)
{
    ///copy img to pointer if index fits
    if(i >= 0 && i < vVD_ImgLoadBuffer.size())
    {
        StatusSet("Load image from buffer");
        *img = vVD_ImgLoadBuffer[i];
        return true;
    }
    else
    {
        return false;
    }
}

int D_MAKRO_MegaFoci::Load_Image(D_VisDat_Obj *img, size_t x, size_t y, size_t t)
{
    ///Check, if image's index in dataset's range
    if((t >= 0 && t < dataset_dim_t) && (y >= 0 && y < dataset_dim_mosaic_y) && (x >= 0 && x < dataset_dim_mosaic_x))
    {
        ///If in range:
        ///try loading img from buffer
        if(ImgBuffer_Read(img, ImgBuffer_Find(x, y, t)))
            return ER_okay;

        ///if img not in buffer, load it from file
        StatusSet("Load image from file");
        D_VisDat_Obj VD_ImgLoaded_ZP_asPages;
        int ER = D_VisDat_Proc::Create_VD_SinglePaged(
                    &VD_ImgLoaded_ZP_asPages,
                    FIL_ImagesYXT[get_index_of_image(x, y, t)],
                c_DIM_P,
                c_DIM_X,
                c_DIM_Y);
        if(ER != ER_okay)
        {
            StatusSet("Create zero image (error)");
            CreateZero_Image(img);
            return ER;
        }

        ///deserialise Z from combined ZP
        ER = D_VisDat_Proc::Dim_Deserialise(
                    img,
                    &VD_ImgLoaded_ZP_asPages,
                    c_DIM_P,
                    c_DIM_Z,
                    dataset_dim_p_exist);
        if(ER != ER_okay)
        {
            StatusSet("Create zero image (error)");
            CreateZero_Image(img);
            return ER;
        }

        ///if successful, write img to buffer
        ImgBuffer_Write(img, x, y, t);
        return ER_okay;
    }
    else
    {
        ///if not in range -> pad with empty image
        StatusSet("Create zero image (padding mosaik border)");
        CreateZero_Image(img);
        return ER_okay;
    }
}

void D_MAKRO_MegaFoci::CreateZero_Image(D_VisDat_Obj *img)
{
    ///create a zero image in size fitting to dataset
    *img = D_VisDat_Obj(
        D_VisDat_Dim(
            dataset_dim_img_x,
            dataset_dim_img_y,
            dataset_dim_z,
            1,
            1,
            dataset_dim_p_exist),
        dataset_type_mat,
                0);
}

void D_MAKRO_MegaFoci::set_ModeMajor_Current(size_t mode)
{
    if(mode >= MODE_MAJOR_NUMBER_OF)
        return;

    mode_major_current = mode;
    ui->stackedWidget_StepMajor->setCurrentIndex(mode_major_current);

    StatusSet("MAJOR MODE:\n" + QSL_ModeMajor[mode_major_current]);

    if(mode == MODE_MAJOR_2_MANU_CORRECT_DETECTION)
    {
        MS2_init_ui();
    }

    if(mode == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
    {
        MS3_UiInit();
    }
}

void D_MAKRO_MegaFoci::MS2_SetComboboxColor(QComboBox *CB_R, QComboBox *CB_G, QComboBox *CB_B, bool color_background_not_text)
{
    int n = 3;

    //color comboboxes in vector
    vector<QComboBox*> vCB(n);
    vCB[0] = CB_R;
    vCB[1] = CB_G;
    vCB[2] = CB_B;

    //indices of CBs in vector
    vector<int> vIndices(n);
    for(int i = 0; i < n; i++)
        vIndices[i] = vCB[i]->currentIndex();

    //calc color and set it to ui
    for(int i = 0; i < n; i++)
    {
        //calc channels if not empty
        vector<uchar> vChannel(n, 0);
        if(vIndices[i] != 0)
            for(int c = 0; c < n; c++)
                vChannel[c] = (vIndices[c] == vIndices[i]) ? 255 : 0;

        //calc color
        QColor color(vChannel[0], vChannel[1], vChannel[2]);
        QColor color_contrast = D_Img_Proc::Contrast_Color(color);

        //foreground or background?
        if(color_background_not_text)
            vCB[i]->setStyleSheet("background-color: " + D_Img_Proc::Color2Text4StyleSheet(color) + ";\n" + "color: " + D_Img_Proc::Color2Text4StyleSheet(color_contrast) + ";");
        else
            vCB[i]->setStyleSheet("background-color: " + D_Img_Proc::Color2Text4StyleSheet(color_contrast) + ";\n" + "color: " + D_Img_Proc::Color2Text4StyleSheet(color) + ";");
    }
}

void D_MAKRO_MegaFoci::MS2_SetComboboxColor_Image(size_t viewer_id)
{
    if(viewer_id >= vv_MS2_COB_ViewerChannel_Image_viewer_bgr.size())
        return;

    MS2_SetComboboxColor(
                vv_MS2_COB_ViewerChannel_Image_viewer_bgr[viewer_id][2],
                vv_MS2_COB_ViewerChannel_Image_viewer_bgr[viewer_id][1],
                vv_MS2_COB_ViewerChannel_Image_viewer_bgr[viewer_id][0],
                true);
}

void D_MAKRO_MegaFoci::MS2_SetComboboxColor_Overlay(size_t viewer_id)
{
    if(viewer_id >= vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr.size())
        return;

    MS2_SetComboboxColor(
                vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[viewer_id][2],
                vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[viewer_id][1],
                vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[viewer_id][0],
                false);
}

void D_MAKRO_MegaFoci::MS2_SetComboboxColor_ImageAll()
{
    for(size_t v = 0; v < MS2_ViewersCount; v++)
        MS2_SetComboboxColor_Image(v);
}

void D_MAKRO_MegaFoci::MS2_SetComboboxColor_OverlayAll()
{
    for(size_t v = 0; v < MS2_ViewersCount; v++)
        MS2_SetComboboxColor_Overlay(v);
}

void D_MAKRO_MegaFoci::MS2_SetComboboxColor_All()
{
    MS2_SetComboboxColor_ImageAll();
    MS2_SetComboboxColor_OverlayAll();
}

void D_MAKRO_MegaFoci::MS2_init_ui()
{
    //fill vectors

    //viewers
    //editing viewers
    MS2_Viewer1.set_GV(ui->graphicsView_MS2_Viewer_1);
    MS2_Viewer2.set_GV(ui->graphicsView_MS2_Viewer_2);
    MS2_Viewer3.set_GV(ui->graphicsView_MS2_Viewer_3);
    MS2_Viewer4.set_GV(ui->graphicsView_MS2_Viewer_4);
    v_MS2_Viewer.resize(MS2_ViewersCount);
    v_MS2_Viewer[0] = &MS2_Viewer1;
    v_MS2_Viewer[1] = &MS2_Viewer2;
    v_MS2_Viewer[2] = &MS2_Viewer3;
    v_MS2_Viewer[3] = &MS2_Viewer4;
    //viewport viewer
    MS2_Viewer_Viewport.set_GV(ui->graphicsView_MS2_Viewport);
    //viewer names
    for(size_t v = 0; v < MS2_ViewersCount; v++)
        v_MS2_Viewer[v]->set_Name("D_MAKRO_MegaFoci MS2_Viewer_" + QString::number(v));

    //maximizers
    v_MS2_PUB_Viewer_Maximize.resize(MS2_ViewersCount);
    v_MS2_PUB_Viewer_Maximize[0] = ui->pushButton_MS2_ViewerMaximize_1;
    v_MS2_PUB_Viewer_Maximize[1] = ui->pushButton_MS2_ViewerMaximize_2;
    v_MS2_PUB_Viewer_Maximize[2] = ui->pushButton_MS2_ViewerMaximize_3;
    v_MS2_PUB_Viewer_Maximize[3] = ui->pushButton_MS2_ViewerMaximize_4;

    //point color selectors
    v_MS2_PUB_Viewer_PointColor.resize(MS2_ViewersCount);
    v_MS2_PUB_Viewer_PointColor[0] = ui->pushButton_MS2_ViewerSettings_PointColor_1;
    v_MS2_PUB_Viewer_PointColor[1] = ui->pushButton_MS2_ViewerSettings_PointColor_2;
    v_MS2_PUB_Viewer_PointColor[2] = ui->pushButton_MS2_ViewerSettings_PointColor_3;
    v_MS2_PUB_Viewer_PointColor[3] = ui->pushButton_MS2_ViewerSettings_PointColor_4;

    //channels image
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr.resize(MS2_ViewersCount, vector<QComboBox*>(MS2_ViewersChannels));

    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[0][0] = ui->comboBox_MS2_ViewerSettings_Image_B_1;
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[0][1] = ui->comboBox_MS2_ViewerSettings_Image_G_1;
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[0][2] = ui->comboBox_MS2_ViewerSettings_Image_R_1;

    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[1][0] = ui->comboBox_MS2_ViewerSettings_Image_B_2;
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[1][1] = ui->comboBox_MS2_ViewerSettings_Image_G_2;
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[1][2] = ui->comboBox_MS2_ViewerSettings_Image_R_2;

    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[2][0] = ui->comboBox_MS2_ViewerSettings_Image_B_3;
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[2][1] = ui->comboBox_MS2_ViewerSettings_Image_G_3;
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[2][2] = ui->comboBox_MS2_ViewerSettings_Image_R_3;

    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[3][0] = ui->comboBox_MS2_ViewerSettings_Image_B_4;
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[3][1] = ui->comboBox_MS2_ViewerSettings_Image_G_4;
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[3][2] = ui->comboBox_MS2_ViewerSettings_Image_R_4;


    //connect image channel selector CBs to color change of themselves
    for(size_t v = 0; v < MS2_ViewersCount; v++)
        for(size_t c = 0; c < MS2_ViewersChannels; c++)
            connect(vv_MS2_COB_ViewerChannel_Image_viewer_bgr[v][c], SIGNAL(currentIndexChanged(int)), this, SLOT(MS2_SetComboboxColor_ImageAll()));

    //channels overlay
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr.resize(MS2_ViewersCount, vector<QComboBox*>(MS2_ViewersChannels));
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[0][0] = ui->comboBox_MS2_ViewerSettings_Overlay_B_1;
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[0][1] = ui->comboBox_MS2_ViewerSettings_Overlay_G_1;
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[0][2] = ui->comboBox_MS2_ViewerSettings_Overlay_R_1;
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[1][0] = ui->comboBox_MS2_ViewerSettings_Overlay_B_2;
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[1][1] = ui->comboBox_MS2_ViewerSettings_Overlay_G_2;
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[1][2] = ui->comboBox_MS2_ViewerSettings_Overlay_R_2;
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[2][0] = ui->comboBox_MS2_ViewerSettings_Overlay_B_3;
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[2][1] = ui->comboBox_MS2_ViewerSettings_Overlay_G_3;
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[2][2] = ui->comboBox_MS2_ViewerSettings_Overlay_R_3;
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[3][0] = ui->comboBox_MS2_ViewerSettings_Overlay_B_4;
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[3][1] = ui->comboBox_MS2_ViewerSettings_Overlay_G_4;
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[3][2] = ui->comboBox_MS2_ViewerSettings_Overlay_R_4;

    //connect overlay channel selector CBs to color change of themselves
    for(size_t v = 0; v < MS2_ViewersCount; v++)
        for(size_t c = 0; c < MS2_ViewersChannels; c++)
            connect(vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[v][c], SIGNAL(currentIndexChanged(int)), this, SLOT(MS2_SetComboboxColor_OverlayAll()));

    //transforms
    v_MS2_CHB_Viewer_Transform.resize(MS2_ViewersCount);
    v_MS2_CHB_Viewer_Transform[0] = ui->checkBox_MS2_ViewerSettings_ViewTransform_1;
    v_MS2_CHB_Viewer_Transform[1] = ui->checkBox_MS2_ViewerSettings_ViewTransform_2;
    v_MS2_CHB_Viewer_Transform[2] = ui->checkBox_MS2_ViewerSettings_ViewTransform_3;
    v_MS2_CHB_Viewer_Transform[3] = ui->checkBox_MS2_ViewerSettings_ViewTransform_4;

    //connect zooms
    v_MS2_CHB_Viewer_ConnectZoom.resize(MS2_ViewersCount);
    v_MS2_CHB_Viewer_ConnectZoom[0] = ui->checkBox_MS2_ViewerSettings_ConnectZoom_1;
    v_MS2_CHB_Viewer_ConnectZoom[1] = ui->checkBox_MS2_ViewerSettings_ConnectZoom_2;
    v_MS2_CHB_Viewer_ConnectZoom[2] = ui->checkBox_MS2_ViewerSettings_ConnectZoom_3;
    v_MS2_CHB_Viewer_ConnectZoom[3] = ui->checkBox_MS2_ViewerSettings_ConnectZoom_4;

    //group boxes
    v_MS2_GRB_Viewer_GroupAll.resize(MS2_ViewersCount);
    v_MS2_GRB_Viewer_GroupAll[0] = ui->groupBox_MS2_Viewer_1;
    v_MS2_GRB_Viewer_GroupAll[1] = ui->groupBox_MS2_Viewer_2;
    v_MS2_GRB_Viewer_GroupAll[2] = ui->groupBox_MS2_Viewer_3;
    v_MS2_GRB_Viewer_GroupAll[3] = ui->groupBox_MS2_Viewer_4;

    //group boxes settings
    v_MS2_GRB_Viewer_GroupSettings.resize(MS2_ViewersCount);
    v_MS2_GRB_Viewer_GroupSettings[0] = ui->groupBox_MS2_ViewerControls_1;
    v_MS2_GRB_Viewer_GroupSettings[1] = ui->groupBox_MS2_ViewerControls_2;
    v_MS2_GRB_Viewer_GroupSettings[2] = ui->groupBox_MS2_ViewerControls_3;
    v_MS2_GRB_Viewer_GroupSettings[3] = ui->groupBox_MS2_ViewerControls_4;

    //draw modi
    v_MS2_PUB_DrawModi.resize(MS2_DRAW_MODE_NUMBER_OF);
    v_MS2_PUB_DrawModi[MS2_DRAW_MODE_NUCLEI] = ui->pushButton_MS2_Tools_Channel_Nuclei;
    v_MS2_PUB_DrawModi[MS2_DRAW_MODE_FOCI_GFP] = ui->pushButton_MS2_Tools_Channel_GFPonly;
    v_MS2_PUB_DrawModi[MS2_DRAW_MODE_FOCI_RFP] = ui->pushButton_MS2_Tools_Channel_RFPonly;
    v_MS2_PUB_DrawModi[MS2_DRAW_MODE_FOCI_BOTH] = ui->pushButton_MS2_Tools_Channel_GFPandRFP;

    //inital sates

    //point colors
    v_MS2_COL_Viewer_PointColor.resize(MS2_ViewersCount, Qt::white);

    //connect zooms
    for(size_t i = 0; i < MS2_ViewersCount; i++)
        for(size_t j = 0; j < MS2_ViewersCount; j++)
            v_MS2_Viewer[i]->connect_Zoom(v_MS2_Viewer[j]);

    //set view transformations
    for(size_t v = 0; v < MS2_ViewersCount; v++)
    {
        v_MS2_Viewer[v]->Set_VisTrafo_ActiveBool(false);
        v_MS2_Viewer[v]->Set_VisTrafo_Mode_Trafo(c_VIS_TRAFO_LOG);
        v_MS2_Viewer[v]->Set_VisTrafo_Divisor(5);
        v_MS2_Viewer[v]->Set_VisTrafo_Center(0);
    }
    MS2_Viewer_Viewport.Set_VisTrafo_ActiveBool(false);
    MS2_Viewer_Viewport.Set_VisTrafo_Mode_Trafo(c_VIS_TRAFO_LOG);
    MS2_Viewer_Viewport.Set_VisTrafo_Divisor(5);
    MS2_Viewer_Viewport.Set_VisTrafo_Center(0);

    //point size
    for(size_t v = 0; v < MS2_ViewersCount; v++)
        v_MS2_Viewer[v]->ClickRecord_ChangeOverlayPointDiameter(4);

    //inital images
    v_MS2_MA_Images2Show.resize(MS2_ViewersCount, pStore->get_Adress(0)->clone());
    MA_MS2_ViewportShow = pStore->get_Adress(0)->clone();
    v_MS2_MA_ChannelsImage_Full.resize(MS2_CH_IMG_NUMBER_OF, Mat(3, 3, CV_8UC1, Scalar(128)));
    v_MS2_MA_ChannelsImage_Croped.resize(MS2_CH_IMG_NUMBER_OF, Mat(3, 3, CV_8UC1, Scalar(128)));
    v_MS2_MA_ChannelsOverlay_Croped.resize(MS2_CH_IMG_NUMBER_OF, Mat(3, 3, CV_8UC1, Scalar(128)));

    //populate CBs
    MS2_ViewersPopulateCBs();

    //range of viewport selectors
    ui->spinBox_MS2_Viewport_X->setMaximum(dataset_dim_mosaic_x - 1);
    ui->spinBox_MS2_Viewport_Y->setMaximum(dataset_dim_mosaic_y - 1);
    ui->spinBox_MS2_Viewport_T->setMaximum(dataset_dim_t - 1);

    //range of progress bar
    ui->progressBar_MS2_CorrectionProgress->setMaximum(dataset_dim_mosaic_xy);
    ui->progressBar_MS2_CorrectionProgress->setValue(0);

    //connects------------------------------------------------------------------------------

    //viewers vis trafo
    for(size_t v = 0; v < MS2_ViewersCount; v++)
        ConnectViewersVisTrafo(v_MS2_Viewer[v]);

    //update viewer images
    connect(ui->comboBox_MS2_ViewerSettings_Image_R_1,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage1()));
    connect(ui->comboBox_MS2_ViewerSettings_Image_G_1,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage1()));
    connect(ui->comboBox_MS2_ViewerSettings_Image_B_1,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage1()));
    connect(ui->comboBox_MS2_ViewerSettings_Overlay_R_1,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage1()));
    connect(ui->comboBox_MS2_ViewerSettings_Overlay_G_1,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage1()));
    connect(ui->comboBox_MS2_ViewerSettings_Overlay_B_1,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage1()));
    connect(ui->comboBox_MS2_ViewerSettings_Image_R_2,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage2()));
    connect(ui->comboBox_MS2_ViewerSettings_Image_G_2,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage2()));
    connect(ui->comboBox_MS2_ViewerSettings_Image_B_2,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage2()));
    connect(ui->comboBox_MS2_ViewerSettings_Overlay_R_2,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage2()));
    connect(ui->comboBox_MS2_ViewerSettings_Overlay_G_2,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage2()));
    connect(ui->comboBox_MS2_ViewerSettings_Overlay_B_2,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage2()));
    connect(ui->comboBox_MS2_ViewerSettings_Image_R_3,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage3()));
    connect(ui->comboBox_MS2_ViewerSettings_Image_G_3,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage3()));
    connect(ui->comboBox_MS2_ViewerSettings_Image_B_3,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage3()));
    connect(ui->comboBox_MS2_ViewerSettings_Overlay_R_3,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage3()));
    connect(ui->comboBox_MS2_ViewerSettings_Overlay_G_3,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage3()));
    connect(ui->comboBox_MS2_ViewerSettings_Overlay_B_3,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage3()));
    connect(ui->comboBox_MS2_ViewerSettings_Image_R_4,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage4()));
    connect(ui->comboBox_MS2_ViewerSettings_Image_G_4,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage4()));
    connect(ui->comboBox_MS2_ViewerSettings_Image_B_4,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage4()));
    connect(ui->comboBox_MS2_ViewerSettings_Overlay_R_4,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage4()));
    connect(ui->comboBox_MS2_ViewerSettings_Overlay_G_4,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage4()));
    connect(ui->comboBox_MS2_ViewerSettings_Overlay_B_4,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS2_UpdateImage4()));

    //range selection
    connect(ui->spinBox_MS2_Viewport_X,                     SIGNAL(valueChanged(int)),          this,   SLOT(MS2_UpdateViewportPos()));
    connect(ui->spinBox_MS2_Viewport_Y,                     SIGNAL(valueChanged(int)),          this,   SLOT(MS2_UpdateViewportPos()));
    connect(ui->spinBox_MS2_Viewport_T,                     SIGNAL(valueChanged(int)),          this,   SLOT(MS2_LoadData_TimeSelected()));

    //click recording
    for(size_t v = 0; v < MS2_ViewersCount; v++)
    {
        v_MS2_Viewer[0]->connect_PointRecord(v_MS2_Viewer[v]);
        connect(v_MS2_Viewer[v], SIGNAL(ClickRecordSignal_RecordedPointsCount(size_t)), this, SLOT(MS2_Draw_RecordedClicksChanged(size_t)));
    }

    //show
    MS2_UpdateImages();
}

void D_MAKRO_MegaFoci::MS2_Draw_Save()
{
    if(!state_MS2_data_loaded || !state_MS2_detections_loaded)
        return;

    size_t ix = ui->spinBox_MS2_Viewport_X->value();
    size_t iy = ui->spinBox_MS2_Viewport_Y->value();
    size_t it = ui->spinBox_MS2_Viewport_T->value();
    if(ix >= dataset_dim_mosaic_x || iy >= dataset_dim_mosaic_y || it >= dataset_dim_t)
        return;

    //time dir
    QDir DIR_Time(DIR_MS2_Out_DetectionsCorrected.path() + "/Time_" + QString::number(it));
    if(!DIR_Time.exists())
        QDir().mkdir(DIR_Time.path());
    if(!DIR_Time.exists())
        return;

    //target dir
    QDir DIR_Target(DIR_Time.path() + "/Image_T" + QString::number(it) + "_Y" + QString::number(iy) + "_X" + QString::number(ix));
    qDebug() << "D_MAKRO_MegaFoci::MS2_Draw_Save" << DIR_Target.path();
    if(DIR_Target.exists())
    {
        DIR_Target.setNameFilters(QStringList() << "*.*");
        DIR_Target.setFilter(QDir::Files);
        foreach(QString dirFile, DIR_Target.entryList())
        {
            DIR_Target.remove(dirFile);
        }
    }
    else
    {
        QDir().mkdir(DIR_Target.path());
    }

    //save
    vv_MS2_NucImg_Out_mosaikXY[ix][iy].save_PathExactDir(DIR_Target.path(), false, true, ix, iy, it);
}

void D_MAKRO_MegaFoci::MS2_Draw_Clear()
{
    if(!state_MS2_data_loaded || !state_MS2_detections_loaded)
        return;

    size_t ix = ui->spinBox_MS2_Viewport_X->value();
    size_t iy = ui->spinBox_MS2_Viewport_Y->value();
    size_t it = ui->spinBox_MS2_Viewport_T->value();
    if(ix >= dataset_dim_mosaic_x || iy >= dataset_dim_mosaic_y || it >= dataset_dim_t)
        return;

    //backup and clear
    vv_MS2_NucImg_Out_mosaikXY[ix][iy].remove_nuclei_foci_all();
    MS2_DetOutBackup_Save();
    StatusSet("Draw: Clear all nuclei and foci");

    //change state
    vv_MS2_NucImg_State_Out_mosaikXY[ix][iy] = MS2_IMG_STATE_TO_PROCESS;

    //show image
    MS2_UpdateOverlays();
    MS2_UpdateImages();
    MS2_Draw_UpdateUi();
}

void D_MAKRO_MegaFoci::MS2_Draw_Reset()
{
    if(!state_MS2_data_loaded || !state_MS2_detections_loaded)
        return;

    size_t ix = ui->spinBox_MS2_Viewport_X->value();
    size_t iy = ui->spinBox_MS2_Viewport_Y->value();
    if(ix >= dataset_dim_mosaic_x || iy >= dataset_dim_mosaic_y)
        return;

    //backup and clear
    vv_MS2_NucImg_Out_mosaikXY[ix][iy] = vv_MS2_NucImg_In_mosaikXY[ix][iy];
    MS2_DetOutBackup_Save();
    StatusSet("Draw: Reset to input initially loaded");

    //change state
    vv_MS2_NucImg_State_Out_mosaikXY[ix][iy] = MS2_IMG_STATE_TO_PROCESS;

    //show image
    MS2_UpdateOverlays();
    MS2_UpdateImages();
    MS2_Draw_UpdateUi();
}

void D_MAKRO_MegaFoci::MS2_Draw_SetProcessed()
{
    if(!state_MS2_data_loaded || !state_MS2_detections_loaded)
        return;

    size_t ix = ui->spinBox_MS2_Viewport_X->value();
    size_t iy = ui->spinBox_MS2_Viewport_Y->value();
    if(ix >= dataset_dim_mosaic_x || iy >= dataset_dim_mosaic_y)
        return;

    //save image
    MS2_Draw_Save();
    StatusSet("Viewport x=" + QString::number(ix) + "/y=" + QString::number(iy) + "finished");

    //change state
    vv_MS2_NucImg_State_Out_mosaikXY[ix][iy] = MS2_IMG_STATE_PROCESSED;

    //update image
    MS2_UpdateImage_Viewport();
    MS2_Draw_UpdateUi();

    //reward user for finishing another image
    RewardSystem.get_reward();
    StatusSet("Look! The cat likes your work " + QS_Fun_Cat);

    if(ui->checkBox_MS2_Params_AutoGoToNextOnFinish->isChecked())
        MS2_MoveToNextViewportToProcess();
}

void D_MAKRO_MegaFoci::MS2_Draw_SetToProcess()
{
    if(!state_MS2_data_loaded || !state_MS2_detections_loaded)
        return;

    size_t ix = ui->spinBox_MS2_Viewport_X->value();
    size_t iy = ui->spinBox_MS2_Viewport_Y->value();
    if(ix >= dataset_dim_mosaic_x || iy >= dataset_dim_mosaic_y)
        return;

    //change state
    vv_MS2_NucImg_State_Out_mosaikXY[ix][iy] = MS2_IMG_STATE_TO_PROCESS;

    //update image
    MS2_UpdateImage_Viewport();
    MS2_Draw_UpdateUi();
}

void D_MAKRO_MegaFoci::MS2_Draw_UpdateUi()
{
    if(!state_MS2_data_loaded || !state_MS2_detections_loaded)
        return;

    size_t ix = ui->spinBox_MS2_Viewport_X->value();
    size_t iy = ui->spinBox_MS2_Viewport_Y->value();
    if(ix >= dataset_dim_mosaic_x || iy >= dataset_dim_mosaic_y)
        return;

    //state
    size_t state = vv_MS2_NucImg_State_Out_mosaikXY[ix][iy];
    ui->pushButton_MS2_Tools_Progress_Corrected->setEnabled(state != MS2_IMG_STATE_PROCESSED);
    ui->pushButton_MS2_Tools_Progress_ToCorrect->setEnabled(state != MS2_IMG_STATE_TO_PROCESS);
}

void D_MAKRO_MegaFoci::MS2_Draw_RecordingStart()
{
    MS2_Viewer1.ClickRecord_Start();
    ui->pushButton_MS2_Tools_RecordPoints_Start->setEnabled(false);
    ui->pushButton_MS2_Tools_RecordPoints_Cancel->setEnabled(true);
}

void D_MAKRO_MegaFoci::MS2_Draw_RecordingEnd()
{
    MS2_Viewer1.ClickRecord_Quit();
    ui->pushButton_MS2_Tools_RecordPoints_Start->setEnabled(true);
    ui->pushButton_MS2_Tools_RecordPoints_Cancel->setEnabled(false);
}

void D_MAKRO_MegaFoci::MS2_Draw_Ellipse()
{
    StatusSet("Draw: Ellipse");
    return MS2_Draw_Contour(MS2_Viewer1.ClickRecord_GetPoints_Ellipse(1.0 / MS2_MosaikImageScale, MS2_ViewportOffset_NotScaled));
}

void D_MAKRO_MegaFoci::MS2_Draw_Polygon()
{
    StatusSet("Draw: Polygon");
    return MS2_Draw_Contour(MS2_Viewer1.ClickRecord_GetPoints_Polygon(1.0 / MS2_MosaikImageScale, MS2_ViewportOffset_NotScaled));
}

void D_MAKRO_MegaFoci::MS2_Draw_ConvexHull()
{
    StatusSet("Draw: Convex hull");
    return MS2_Draw_Contour(MS2_Viewer1.ClickRecord_GetPoints_ConvexHull(1.0 / MS2_MosaikImageScale, MS2_ViewportOffset_NotScaled));
}

void D_MAKRO_MegaFoci::MS2_Draw_Points()
{
    //check state
    if(!state_MS2_backups_init)
        return;

    //check mode
    if(MS2_draw_mode != MS2_DRAW_MODE_FOCI_GFP && MS2_draw_mode != MS2_DRAW_MODE_FOCI_RFP && MS2_draw_mode != MS2_DRAW_MODE_FOCI_BOTH)
        return;

    //get pos
    size_t ix = ui->spinBox_MS2_Viewport_X->value();
    size_t iy = ui->spinBox_MS2_Viewport_Y->value();
    size_t it = ui->spinBox_MS2_Viewport_T->value();
    if(ix >= dataset_dim_mosaic_x || iy >= dataset_dim_mosaic_y || it >= dataset_dim_t)
        return;

    //point size
    double r = ui->spinBox_MS2_Tools_AllplyPoints_PointSize->value();

    //get countours of circles
    vector<vector<Point>> vContours = MS2_Viewer1.ClickRecord_GetPoints_Circles(r, 1.0 / MS2_MosaikImageScale, MS2_ViewportOffset_NotScaled);
    size_t n = vContours.size();

    //create foci
    vector<D_Bio_Focus> vFoc(n);
    for(size_t i = 0; i < n; i++)
        vFoc[i] = D_Bio_Focus(vContours[i]);

    //edit
    switch (MS2_draw_mode) {
    case MS2_DRAW_MODE_FOCI_GFP:    vv_MS2_NucImg_Out_mosaikXY[ix][iy].add_foci(FOCI_GFP,  vFoc);   break;
    case MS2_DRAW_MODE_FOCI_RFP:    vv_MS2_NucImg_Out_mosaikXY[ix][iy].add_foci(FOCI_RFP,  vFoc);   break;
    case MS2_DRAW_MODE_FOCI_BOTH:   vv_MS2_NucImg_Out_mosaikXY[ix][iy].add_foci(FOCI_BOTH, vFoc);   break;
    default:                                                                                        return;}

    //status
    StatusSet("Draw: Points/Circles");

    //backup
    MS2_DetOutBackup_Save();

    //change state
    vv_MS2_NucImg_State_Out_mosaikXY[ix][iy] = MS2_IMG_STATE_TO_PROCESS;

    //update ui
    MS2_DetOutBackup_UpdateUi();
    MS2_UpdateOverlays();
    MS2_UpdateImages_Editing();
    MS2_Draw_UpdateUi();

    //end click recording
    MS2_Draw_RecordingEnd();
}

void D_MAKRO_MegaFoci::MS2_Draw_Contour(vector<Point> contour)
{
    //check state
    if(!state_MS2_backups_init)
        return;

    //check mode
    if(MS2_draw_mode != MS2_DRAW_MODE_NUCLEI)
        return;

    //get pos
    size_t ix = ui->spinBox_MS2_Viewport_X->value();
    size_t iy = ui->spinBox_MS2_Viewport_Y->value();
    size_t it = ui->spinBox_MS2_Viewport_T->value();
    if(ix >= dataset_dim_mosaic_x || iy >= dataset_dim_mosaic_y || it >= dataset_dim_t)
        return;

    //edit
    D_Bio_NucleusBlob Nuc(contour, it);
    vv_MS2_NucImg_Out_mosaikXY[ix][iy].add_nucleus(Nuc);

    //backup
    MS2_DetOutBackup_Save();

    //change state
    vv_MS2_NucImg_State_Out_mosaikXY[ix][iy] = MS2_IMG_STATE_TO_PROCESS;

    //update ui
    MS2_DetOutBackup_UpdateUi();
    MS2_UpdateOverlays();
    MS2_UpdateImages_Editing();
    MS2_Draw_UpdateUi();

    //end click recording
    MS2_Draw_RecordingEnd();
}

void D_MAKRO_MegaFoci::MS2_Draw_Remove()
{
    //check state
    if(!state_MS2_backups_init)
        return;

    //get pos
    size_t ix = ui->spinBox_MS2_Viewport_X->value();
    size_t iy = ui->spinBox_MS2_Viewport_Y->value();
    if(ix >= dataset_dim_mosaic_x || iy >= dataset_dim_mosaic_y)
        return;

    //get points
    vector<Point> vP = MS2_Viewer1.ClickRecord_GetPoints(1.0 / MS2_MosaikImageScale, MS2_ViewportOffset_NotScaled);

    //click precision
    double click_precision_margin = ui->doubleSpinBox_MS2_Params_ClickPrecisionMargin->value();

    //edit
    switch (MS2_draw_mode) {
    case MS2_DRAW_MODE_NUCLEI:      vv_MS2_NucImg_Out_mosaikXY[ix][iy].remove_nuclei(vP,            click_precision_margin);    break;
    case MS2_DRAW_MODE_FOCI_GFP:    vv_MS2_NucImg_Out_mosaikXY[ix][iy].remove_foci(  vP, FOCI_GFP,  click_precision_margin);    break;
    case MS2_DRAW_MODE_FOCI_RFP:    vv_MS2_NucImg_Out_mosaikXY[ix][iy].remove_foci(  vP, FOCI_RFP,  click_precision_margin);    break;
    case MS2_DRAW_MODE_FOCI_BOTH:   vv_MS2_NucImg_Out_mosaikXY[ix][iy].remove_foci(  vP, FOCI_BOTH, click_precision_margin);    break;
    default:                                                                                                                    return;}

    //status
    StatusSet("Draw: Remove " + QString(MS2_draw_mode == MS2_DRAW_MODE_NUCLEI ? "nuclei" : "foci"));

    //backup
    MS2_DetOutBackup_Save();

    //change state
    vv_MS2_NucImg_State_Out_mosaikXY[ix][iy] = MS2_IMG_STATE_TO_PROCESS;

    //update ui
    MS2_DetOutBackup_UpdateUi();
    MS2_UpdateOverlays();
    MS2_UpdateImages_Editing();
    MS2_Draw_UpdateUi();

    //end click recording
    MS2_Draw_RecordingEnd();
}

bool D_MAKRO_MegaFoci::MS2_DetOutBackup_Init()
{
    if(!state_MS2_detections_loaded)
        return false;

    //init containers
    vvv_MS2_DetectionsOutBackups_XYI.resize(dataset_dim_mosaic_x, vector<vector<D_Bio_NucleusImage>>(dataset_dim_mosaic_y, vector<D_Bio_NucleusImage>(MS2_DetOutBackup_Count, D_Bio_NucleusImage())));
    vvv_MS2_DetectionsOut_BackupCursor.resize(dataset_dim_mosaic_x, vector<size_t>(dataset_dim_mosaic_y, 0));
    vvv_MS2_DetectionsOut_BackupValidMax.resize(dataset_dim_mosaic_x, vector<size_t>(dataset_dim_mosaic_y, 0));

    //save current as 1st backup
    for(size_t ix = 0; ix < dataset_dim_mosaic_x; ix++)
    {
        for(size_t iy = 0; iy < dataset_dim_mosaic_y; iy++)
        {
            vvv_MS2_DetectionsOutBackups_XYI[ix][iy][0] = vv_MS2_NucImg_Out_mosaikXY[ix][iy];
        }
    }

    //update state
    state_MS2_backups_init = true;

    //update ui
    MS2_DetOutBackup_UpdateUi();

    return true;
}

/*!
 * \brief D_MAKRO_MegaFoci::MS2_DetOutBackup_Save saves a backup in the backup stack for editing images
 * \details Use this AFTER changeing the image
 */
void D_MAKRO_MegaFoci::MS2_DetOutBackup_Save()
{    
    if(!state_MS2_backups_init)
        return;

    size_t ix = ui->spinBox_MS2_Viewport_X->value();
    size_t iy = ui->spinBox_MS2_Viewport_Y->value();
    if(ix >= dataset_dim_mosaic_x || iy >= dataset_dim_mosaic_y)
        return;

    //target index
    size_t target = vvv_MS2_DetectionsOut_BackupCursor[ix][iy] + 1;

    //check range and shift backups if needed
    if(target >= MS2_DetOutBackup_Count)
    {
        //shift backups
        for(size_t ib = 1; ib < MS2_DetOutBackup_Count; ib++)
            vvv_MS2_DetectionsOutBackups_XYI[ix][iy][ib - 1] = vvv_MS2_DetectionsOutBackups_XYI[ix][iy][ib];

        //apply shift to target index
        target--;
    }

    //save backup
    vvv_MS2_DetectionsOutBackups_XYI[ix][iy][target] = vv_MS2_NucImg_Out_mosaikXY[ix][iy];
    vvv_MS2_DetectionsOut_BackupCursor[ix][iy] = target;
    vvv_MS2_DetectionsOut_BackupValidMax[ix][iy] = target;
    //StatusSet("Save:" + QString::number(target) + vvv_MS2_DetectionsOutBackups_XYI[ix][iy][target].info());

    //update ui
    MS2_DetOutBackup_UpdateUi();
}

bool D_MAKRO_MegaFoci::MS2_DetOutBackup_Undo()
{
    if(!state_MS2_backups_init)
        return false;

    size_t ix = ui->spinBox_MS2_Viewport_X->value();
    size_t iy = ui->spinBox_MS2_Viewport_Y->value();
    if(ix >= dataset_dim_mosaic_x || iy >= dataset_dim_mosaic_y)
        return false;

    //check range
    size_t cursor = vvv_MS2_DetectionsOut_BackupCursor[ix][iy];
    if(cursor <= 0)
        return false;

    //source index
    size_t source = cursor - 1;

    //load backup
    vv_MS2_NucImg_Out_mosaikXY[ix][iy] = vvv_MS2_DetectionsOutBackups_XYI[ix][iy][source];
    vvv_MS2_DetectionsOut_BackupCursor[ix][iy] = source;
    //StatusSet("Undo:" + QString::number(source) + vvv_MS2_DetectionsOutBackups_XYI[ix][iy][source].info());

    //update ui
    MS2_DetOutBackup_UpdateUi();
    MS2_UpdateOverlays();
    MS2_UpdateImages_Editing();

    return true;
}

bool D_MAKRO_MegaFoci::MS2_DetOutBackup_Redo()
{
    if(!state_MS2_backups_init)
        return false;

    size_t ix = ui->spinBox_MS2_Viewport_X->value();
    size_t iy = ui->spinBox_MS2_Viewport_Y->value();
    if(ix >= dataset_dim_mosaic_x || iy >= dataset_dim_mosaic_y)
        return false;

    //check range
    size_t cursor = vvv_MS2_DetectionsOut_BackupCursor[ix][iy];
    if(cursor >= MS2_DetOutBackup_Count - 1 || cursor >= vvv_MS2_DetectionsOut_BackupValidMax[ix][iy])
        return false;

    //source index
    size_t source = cursor + 1;

    //load backup
    vv_MS2_NucImg_Out_mosaikXY[ix][iy] = vvv_MS2_DetectionsOutBackups_XYI[ix][iy][source];
    vvv_MS2_DetectionsOut_BackupCursor[ix][iy] = source;
    //StatusSet("Redo:" + QString::number(source) + vvv_MS2_DetectionsOutBackups_XYI[ix][iy][source].info());

    //update ui
    MS2_DetOutBackup_UpdateUi();
    MS2_UpdateOverlays();
    MS2_UpdateImages_Editing();

    return true;
}

void D_MAKRO_MegaFoci::MS2_DetOutBackup_UpdateUi()
{
    if(!state_MS2_backups_init)
        return;

    size_t ix = ui->spinBox_MS2_Viewport_X->value();
    size_t iy = ui->spinBox_MS2_Viewport_Y->value();
    if(ix >= dataset_dim_mosaic_x || iy >= dataset_dim_mosaic_y)
        return;

    size_t cursor = vvv_MS2_DetectionsOut_BackupCursor[ix][iy];
    ui->pushButton_MS2_Tools_History_Undo->setEnabled(cursor > 0);
    ui->pushButton_MS2_Tools_History_Redo->setEnabled(cursor < MS2_DetOutBackup_Count - 1 && cursor < vvv_MS2_DetectionsOut_BackupValidMax[ix][iy]);
}

void D_MAKRO_MegaFoci::MS3_UiInit()
{
    //porc steps
    Populate_CB_Single(ui->comboBox_MS3_ImgProc_StepShow, QSL_Steps_MS3, STEP_MS3_VIS_REGIONS_FOCI_COUNT);

    //stats
    Populate_CB_Single(ui->comboBox_MS3_ImgProc_ProjectZ_Stat, QSL_StatList, c_STAT_QUANTIL_95);

    //proc images
    vVD_ImgProcSteps.resize(STEP_MS3_NUMBER_OF);
    for(int s = 0; s < STEP_MS3_NUMBER_OF; s++)
        vVD_ImgProcSteps[s] = pStore->get_VD(0);

    //additional mosaics on stack proc
    ui->checkBox_MS3_StackProc_SaveAdditionalMosaics->setEnabled(true);
    ui->checkBox_MS3_StackProc_SaveAdditionalMosaics->setChecked(true);

}

bool D_MAKRO_MegaFoci::MS3_LoadDirs()
{
    if(mode_major_current != MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
        return false;

    StatusSet("Please select results directory from step 2.");
    QString QS_MasterOut = QFileDialog::getExistingDirectory(
                this,
                "Please select results folder of step 2 you want to load (must beginn with 'Results_Step2_').",
                pStore->dir_M_MegaFoci_Results()->path());

    //check if dir was selected
    if(QS_MasterOut.isEmpty())
    {
        StatusSet("Didn't you find your data? A clean file system is a nice thing, right?");
        return false;
    }

    //check, if dir is results from step 2
    if(!QS_MasterOut.contains("Results_Step2"))
    {
        StatusSet("You should selct results from step 2...\n" + QS_Fun_TableFlip);
        return false;
    }

    //master dir in
    DIR_MS3_In_Master.setPath(QS_MasterOut);
    if(!DIR_MS3_In_Master.exists())
    {
        StatusSet("With unknown dark magic you selected a not existing directory. " + QS_Fun_Confused);
        return false;
    }

    //dir in: detections
    DIR_MS3_In_DetectionsCorrected.setPath(DIR_MS3_In_Master.path() + "/DetectionsCorrected");
    if(!DIR_MS3_In_DetectionsCorrected.exists())
    {
        StatusSet("Your selected reults folder does not contain a detections folder... That won't work.");
        return false;
    }

    //correct input data selected
    StatusSet("Input valid:\n" + DIR_MS3_In_Master.path());

    //save input dir
    QDir DIR_parent(DIR_MS3_In_Master);
    DIR_parent.cdUp();
    pStore->set_dir_M_MegaFoci_Results(DIR_parent.path());

    state_MS3_data_loaded = true;
    return true;
}

bool D_MAKRO_MegaFoci::MS3_LoadDetections(size_t t)
{
    state_MS3_detections_loaded = MS2_LoadData_Detections(
                t,
                false,
                &vv_MS3_NucImg_InCorrected_mosaikXY,
                DIR_MS3_In_DetectionsCorrected,
                &vv_MS3_NucImg_InCorrected_States_mosaikXY,
                MS2_IMG_STATE_LOADED,
                MS2_IMG_STATE_NOT_FOUND);

    return state_MS3_detections_loaded;
}

/*
void D_MAKRO_MegaFoci::MS3_ProcessStack()
{
    if(mode_major_current != MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI || !state_MS3_data_loaded)
        return;

    ui->groupBox_MS3_Process->setEnabled(false);
    ui->groupBox_MS3_Progress->setEnabled(true);
    state_MS3_stack_processing = true;



    state_MS3_stack_processing = false;
    ui->groupBox_MS3_Progress->setEnabled(false);
}
*/

void D_MAKRO_MegaFoci::MS2_ViewerMaximize(int v2max)
{
    if(v2max < 0 || v2max >= static_cast<int>(MS2_ViewersCount))
        return;

    if(v2max == MS2_ViewerMaximized)
    {
        for(size_t v = 0; v < v_MS2_GRB_Viewer_GroupAll.size(); v++)
        {
            v_MS2_GRB_Viewer_GroupAll[v]->setVisible(true);
            v_MS2_PUB_Viewer_Maximize[v]->setStyleSheet("font-weight: normal");
        }
        MS2_ViewerMaximized = -1;
    }
    else
    {
        for(size_t v = 0; v < v_MS2_GRB_Viewer_GroupAll.size(); v++)
        {
            bool max_this_one = static_cast<int>(v) == v2max;
            v_MS2_GRB_Viewer_GroupAll[v]->setVisible(max_this_one);
            v_MS2_PUB_Viewer_Maximize[v]->setStyleSheet(max_this_one ? "font-weight: bold" : "font-weight: normal");
        }
        MS2_ViewerMaximized = v2max;
    }

    Update_Ui();
    Update_Views();
}

void D_MAKRO_MegaFoci::MS2_ViewerPointColor(size_t v2col)
{
    if(v2col < 0 || v2col >= MS2_ViewersCount)
        return;

    //get color
    QColor col = QColorDialog::getColor(
                v_MS2_COL_Viewer_PointColor[v2col],
                this,
                "Select point color to display in viewer");

    //set color to button
    QString QS_Style = "background-color: " + D_Img_Proc::Color2Text4StyleSheet(D_Img_Proc::Contrast_Color(col)) + ";\n" + "color: " + D_Img_Proc::Color2Text4StyleSheet(col) + ";";
    v_MS2_PUB_Viewer_PointColor[v2col]->setStyleSheet(QS_Style);

    //save color
    v_MS2_COL_Viewer_PointColor[v2col] = col;
    v_MS2_Viewer[v2col]->ClickRecord_ChangeOverlayColor(col);

    //update_image
    MS2_UpdateImage(v2col);
}

void D_MAKRO_MegaFoci::MS2_ViewerPointDiameter(size_t v, double d)
{
    v_MS2_Viewer[v]->ClickRecord_ChangeOverlayPointDiameter(d);
}

void D_MAKRO_MegaFoci::MS2_ViewerConnectZooms(size_t v2con, bool con)
{
    v_MS2_Viewer[v2con]->set_zoom_connection_active(con);
}

void D_MAKRO_MegaFoci::MS2_ViewerSetVisTrafoActive(size_t v2tra)
{
    v_MS2_Viewer[v2tra]->Set_VisTrafo_ActiveBool(v_MS2_CHB_Viewer_Transform[v2tra]->isChecked() && ui->groupBox_VisTrafo->isChecked());
}

void D_MAKRO_MegaFoci::MS2_ViewerSetVisTrafoActive_All()
{
    for(size_t v = 0; v < MS2_ViewersCount; v++)
        MS2_ViewerSetVisTrafoActive(v);
}

void D_MAKRO_MegaFoci::MS2_ViewersPopulateCBs()
{
    Populate_CB_Single(ui->comboBox_MS2_ViewportBackground,     QSL_MS2_ChannelsImage,      MS2_CH_IMG_DIC);

    for(size_t v = 0; v < MS2_ViewersCount; v++)
        for(size_t c = 0; c < MS2_ViewersChannels; c++)
        {
            Populate_CB_Single(vv_MS2_COB_ViewerChannel_Image_viewer_bgr[v][c],     QSL_MS2_ChannelsImage,      MS2_CH_IMG_EMPTY);
            Populate_CB_Single(vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[v][c],   QSL_MS2_ChannelsOverlay,    MS2_CH_OVR_EMPTY);
        }   
}

void D_MAKRO_MegaFoci::MS2_ViewersSelectDefaultCBs()
{
    //viewer 1
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[0][0]->setCurrentIndex(MS2_CH_IMG_RFP);
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[0][1]->setCurrentIndex(MS2_CH_IMG_GFP);
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[0][2]->setCurrentIndex(MS2_CH_IMG_DIC);
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[0][0]->setCurrentIndex(MS2_CH_OVR_NUCLEI);
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[0][1]->setCurrentIndex(MS2_CH_OVR_NUCLEI);
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[0][2]->setCurrentIndex(MS2_CH_OVR_NUCLEI);

    //viewer 2
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[1][0]->setCurrentIndex(MS2_CH_IMG_DIC);
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[1][1]->setCurrentIndex(MS2_CH_IMG_DIC);
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[1][2]->setCurrentIndex(MS2_CH_IMG_DIC);
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[1][2]->setCurrentIndex(MS2_CH_OVR_FOCI_BOTH);

    //viewer 3
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[2][0]->setCurrentIndex(MS2_CH_IMG_GFP);
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[2][1]->setCurrentIndex(MS2_CH_IMG_GFP);
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[2][2]->setCurrentIndex(MS2_CH_IMG_GFP);
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[2][1]->setCurrentIndex(MS2_CH_OVR_FOCI_GFP);

    //viewer 4
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[3][0]->setCurrentIndex(MS2_CH_IMG_RFP);
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[3][1]->setCurrentIndex(MS2_CH_IMG_RFP);
    vv_MS2_COB_ViewerChannel_Image_viewer_bgr[3][2]->setCurrentIndex(MS2_CH_IMG_RFP);
    vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[3][0]->setCurrentIndex(MS2_CH_OVR_FOCI_RFP);
}

void D_MAKRO_MegaFoci::MS2_UpdateViews()
{
    for(size_t v = 0; v < MS2_ViewersCount; v++)
        v_MS2_Viewer[v]->Update_View();
}

void D_MAKRO_MegaFoci::MS2_UpdateImages()
{
    MS2_UpdateImages_Editing();
    MS2_UpdateImage_Viewport();
}

void D_MAKRO_MegaFoci::MS2_UpdateImage1()
{
    MS2_UpdateImage(0);
}

void D_MAKRO_MegaFoci::MS2_UpdateImage2()
{
    MS2_UpdateImage(1);
}

void D_MAKRO_MegaFoci::MS2_UpdateImage3()
{
    MS2_UpdateImage(2);
}

void D_MAKRO_MegaFoci::MS2_UpdateImage4()
{
    MS2_UpdateImage(3);
}

void D_MAKRO_MegaFoci::MS2_UpdateImage(size_t img2update)
{
    ERR(D_Img_Proc::OverlayImage(
            &(v_MS2_MA_Images2Show[img2update]),
            &(v_MS2_MA_ChannelsImage_Croped[vv_MS2_COB_ViewerChannel_Image_viewer_bgr[img2update][2]->currentIndex()]),
            &(v_MS2_MA_ChannelsImage_Croped[vv_MS2_COB_ViewerChannel_Image_viewer_bgr[img2update][1]->currentIndex()]),
            &(v_MS2_MA_ChannelsImage_Croped[vv_MS2_COB_ViewerChannel_Image_viewer_bgr[img2update][0]->currentIndex()]),
            &(v_MS2_MA_ChannelsOverlay_Croped[vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[img2update][2]->currentIndex()]),
            &(v_MS2_MA_ChannelsOverlay_Croped[vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[img2update][1]->currentIndex()]),
            &(v_MS2_MA_ChannelsOverlay_Croped[vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[img2update][0]->currentIndex()])));

    v_MS2_Viewer[img2update]->Update_Image(&(v_MS2_MA_Images2Show[img2update]));
}

void D_MAKRO_MegaFoci::MS2_UpdateImages_Editing()
{
    for(size_t v = 0; v < MS2_ViewersCount; v++)
        MS2_UpdateImage(v);
}

void D_MAKRO_MegaFoci::MS2_UpdateImage_Viewport()
{
    size_t i_channel_viewport = ui->comboBox_MS2_ViewportBackground->currentIndex();

    if(i_channel_viewport >= v_MS2_MA_ChannelsImage_Full.size())
        return;

    //base image
    int ER = D_Img_Proc::Duplicate2Channels(
                &MA_MS2_ViewportShow,
                &(v_MS2_MA_ChannelsImage_Full[i_channel_viewport]),
                3);
    if(ER != ER_okay)
    {
        ERR(ER, "MS2_UpdateImage_Viewport", "D_Img_Proc::Duplicate2Channels to MA_MS2_ViewportShow");
        return;
    }

    //draw status symbols on img
    if(state_MS2_detections_loaded)
    {
        size_t processed_counter = 0;

        //qDebug() << "D_MAKRO_MegaFoci::MS2_UpdateImage_Viewport" << "try to draw state symbols";
        for(size_t ix = 0; ix < vv_MS2_NucImg_State_Out_mosaikXY.size(); ix++)
        {
            for(size_t iy = 0; iy < vv_MS2_NucImg_State_Out_mosaikXY[ix].size(); iy++)
            {
                //rect
                int x1 = max(0.0,                           (static_cast<double>(ix    ) / dataset_dim_mosaic_x) * MS2_MosaikImageWidth);
                int y1 = max(0.0,                           (static_cast<double>(iy    ) / dataset_dim_mosaic_y) * MS2_MosaikImageHeight);
                int x2 = min(MS2_MosaikImageWidth  - 1.0,   (static_cast<double>(ix + 1) / dataset_dim_mosaic_x) * MS2_MosaikImageWidth);
                int y2 = min(MS2_MosaikImageHeight - 1.0,   (static_cast<double>(iy + 1) / dataset_dim_mosaic_y) * MS2_MosaikImageHeight);
                //qDebug() << "D_MAKRO_MegaFoci::MS2_UpdateImage_Viewport" << "darw to x1/x2/y1/y2" << x1 << x2 << y1 << y2;

                //select style
                bool known_state = true;
                int symbol;
                uchar r = 0;
                uchar g = 0;
                uchar b = 0;

                switch (vv_MS2_NucImg_State_Out_mosaikXY[ix][iy]) {
                case MS2_IMG_STATE_PROCESSED:   symbol = c_MARKER_SYMBOL_TICK;      g = 255;    processed_counter++;    break;
                case MS2_IMG_STATE_TO_PROCESS:  symbol = c_MARKER_SYMBOL_3DOTS;     b = 255;                            break;
                case MS2_IMG_STATE_NOT_FOUND:   symbol = c_MARKER_SYMBOL_CROSS;     r = 255;                            break;
                default:                        known_state = false;                                                    break;}

                if(known_state && ui->checkBox_MS2_ViewportOverlay->isChecked())
                {
                    ERR(D_Img_Proc::Draw_MarkerSymbol(
                            &MA_MS2_ViewportShow,
                            x1, y1, x2, y2,
                            symbol,
                            r, g, b,
                            0.8),
                        "MS2_UpdateImage_Viewport",
                        "D_Img_Proc::Draw_MarkerSymbol - State");
                }
            }
        }

        //show progress
        ui->progressBar_MS2_CorrectionProgress->setValue(processed_counter);
    }
    else
    {
        //show unknown progress
        ui->progressBar_MS2_CorrectionProgress->setValue(0);


        //qDebug() << "D_MAKRO_MegaFoci::MS2_UpdateImage_Viewport" << "can't draw state symbols, states not calced yet";
    }

    //draw viewport on overview
    int mx = ui->spinBox_MS2_Viewport_X->value();
    int my = ui->spinBox_MS2_Viewport_Y->value();
    int l = max(0.0,                           (static_cast<double>(mx                          ) / dataset_dim_mosaic_x) * MS2_MosaikImageWidth);
    int t = max(0.0,                           (static_cast<double>(my                          ) / dataset_dim_mosaic_y) * MS2_MosaikImageHeight);
    int r = min(MS2_MosaikImageWidth  - 1.0,   (static_cast<double>(mx + 1 + MS2_MosaikBorderPrz) / dataset_dim_mosaic_x) * MS2_MosaikImageWidth);
    int b = min(MS2_MosaikImageHeight - 1.0,   (static_cast<double>(my + 1 + MS2_MosaikBorderPrz) / dataset_dim_mosaic_y) * MS2_MosaikImageHeight);
    ERR(D_Img_Proc::Draw_MarkerSymbol(
            &MA_MS2_ViewportShow,
            l, t, r, b,
            c_MARKER_SYMBOL_RECT,
            255, 255, 255,
            1),
        "MS2_UpdateImage_Viewport",
        "D_Img_Proc::Draw_MarkerSymbol - Viewport");

    //show img
    MS2_Viewer_Viewport.Update_Image(&MA_MS2_ViewportShow);
}

void D_MAKRO_MegaFoci::MS2_MoveToNextViewportToProcess()
{
    if(!state_MS2_detections_loaded)
        return;

    size_t ix = ui->spinBox_MS2_Viewport_X->value();
    size_t iy = ui->spinBox_MS2_Viewport_Y->value();
    size_t it = ui->spinBox_MS2_Viewport_T->value();

    for(size_t t = 0; t < dataset_dim_t; t++)
        for(size_t y = 0; y < dataset_dim_mosaic_x; y++)
            for(size_t x = 0; x < dataset_dim_mosaic_y; x++)
            {
                if(x != ix || y != iy || t != it)
                    if(vv_MS2_NucImg_State_Out_mosaikXY[x][y] != MS2_IMG_STATE_PROCESSED)
                    {
                        ui->spinBox_MS2_Viewport_X->setValue(x);
                        ui->spinBox_MS2_Viewport_Y->setValue(y);
                        ui->spinBox_MS2_Viewport_T->setValue(t);
                        return;
                    }
            }
}

void D_MAKRO_MegaFoci::MS2_UpdateViewportPos()
{
    //mosaic coordinates
    size_t mx = ui->spinBox_MS2_Viewport_X->value();
    size_t my = ui->spinBox_MS2_Viewport_Y->value();

    //check if coordinates are valid
    if(mx >= dataset_dim_mosaic_x || my >= dataset_dim_mosaic_y)
        return;

    //status
    StatusSet("Move viewport to x=" + QString::number(mx) + "/y=" + QString::number(my));

    //relative border pos
    double l = static_cast<double>(mx) / dataset_dim_mosaic_x;
    double r = min(1.0, static_cast<double>(mx + 1 + MS2_MosaikBorderPrz) / dataset_dim_mosaic_x);
    double t = static_cast<double>(my) / dataset_dim_mosaic_y;
    double b = min(1.0, static_cast<double>(my + 1 + MS2_MosaikBorderPrz) / dataset_dim_mosaic_y);

    //crop channel images
    for(size_t ch = 0; ch < MS2_CH_IMG_NUMBER_OF; ch++)
        ERR(D_Img_Proc::Crop_Rect_Rel(
                &(v_MS2_MA_ChannelsImage_Croped[ch]),
                &(v_MS2_MA_ChannelsImage_Full[ch]),
                l, t, r, b));

    //calc offsets
    MS2_ViewportOffset_Scaled = Point(l * MS2_MosaikImageWidth, t * MS2_MosaikImageHeight);
    MS2_ViewportOffset_NotScaled = MS2_ViewportOffset_Scaled * (1.0 / MS2_MosaikImageScale);

    //calc overlays
    MS2_InitOverlays();
    MS2_UpdateOverlays();

    //update ui
    MS2_DetOutBackup_UpdateUi();
    MS2_Draw_UpdateUi();

    //quit drawing
    MS2_Draw_RecordingEnd();

    //show
    MS2_UpdateImages();
}

void D_MAKRO_MegaFoci::MS2_InitOverlays()
{
    //qDebug() << "MS2_InitOverlays" << "start";

    Mat MA_tmp_black = Mat::zeros(v_MS2_MA_ChannelsImage_Croped[0].size(), CV_8UC1);

    v_MS2_MA_ChannelsOverlay_Croped.resize(MS2_CH_OVR_NUMBER_OF);
    for(size_t ovr = 0; ovr < MS2_CH_OVR_NUMBER_OF; ovr++)
        v_MS2_MA_ChannelsOverlay_Croped[ovr] = MA_tmp_black.clone();

    MA_tmp_black.release();

    //qDebug() << "MS2_InitOverlays" << "finish";
}

void D_MAKRO_MegaFoci::MS2_UpdateOverlays()
{
    //qDebug() << "MS2_UpdateOverlays" << "start";

    for(size_t ovr = 0; ovr < MS2_CH_OVR_NUMBER_OF; ovr++)
        MS2_UpdateOverlay(ovr);

    //qDebug() << "MS2_UpdateOverlays" << "finish";
}

void D_MAKRO_MegaFoci::MS2_UpdateOverlay(size_t overlay_index)
{
    //qDebug() << "MS2_UpdateOverlay" << overlay_index << "start";
    if(overlay_index >= v_MS2_MA_ChannelsOverlay_Croped.size())
        return;

    //mosaic coordinates
    size_t mx = ui->spinBox_MS2_Viewport_X->value();
    size_t my = ui->spinBox_MS2_Viewport_Y->value();

    //check if coordinates are valid
    if(mx >= dataset_dim_mosaic_x || my >= dataset_dim_mosaic_y)
    {
        return;
        qDebug() << "MS2_UpdateOverlay - mx" << mx << "or my" << my << "out of range";
    }

    //detections out
    D_Bio_NucleusImage NucImg = vv_MS2_NucImg_Out_mosaikXY[mx][my];

    //init empty overlay
    Mat MA_tmp_black = Mat::zeros(v_MS2_MA_ChannelsOverlay_Croped[overlay_index].size(), CV_8UC1);
    v_MS2_MA_ChannelsOverlay_Croped[overlay_index] = MA_tmp_black.clone();
    MA_tmp_black.release();

    switch (overlay_index) {

    case MS2_CH_OVR_NUCLEI:
    {
        ERR(D_Img_Proc::Draw_Contours(
                &(v_MS2_MA_ChannelsOverlay_Croped[overlay_index]),
                NucImg.get_nuclei_contours(MS2_MosaikImageScale, - MS2_ViewportOffset_Scaled),
                ui->doubleSpinBox_MS2_Params_NucleusBorderThickness->value(),
                255));
    }
        break;

    case MS2_CH_OVR_FOCI_GFP:
    case MS2_CH_OVR_FOCI_RFP:
    case MS2_CH_OVR_FOCI_BOTH:
    {
        size_t foc_index;
        switch (overlay_index) {
        case MS2_CH_OVR_FOCI_GFP:   foc_index = FOCI_GFP;   break;
        case MS2_CH_OVR_FOCI_RFP:   foc_index = FOCI_RFP;   break;
        case MS2_CH_OVR_FOCI_BOTH:  foc_index = FOCI_BOTH;  break;
        default:                                            return;}

        for(size_t f = 0; f < NucImg.get_foci_count(foc_index); f++)
        {
            D_Bio_Focus Foc = NucImg.get_focus(foc_index, f);

            ERR(D_Img_Proc::Draw_Dot(
                    &(v_MS2_MA_ChannelsOverlay_Croped[overlay_index]),
                    (Foc.centroid().x * MS2_MosaikImageScale) - MS2_ViewportOffset_Scaled.x,
                    (Foc.centroid().y * MS2_MosaikImageScale) - MS2_ViewportOffset_Scaled.y,
                    max(
                        ui->doubleSpinBox_MS2_Params_FociMinRadius->value(),
                        sqrt(Foc.area() / PI) * MS2_MosaikImageScale * (ui->doubleSpinBox_MS2_Params_FociScale->value() / 100.0)),
                    255));
        }
    }
        break;

    default:
    {
        //do nothing
    }
        break;
    }

    //qDebug() << "MS2_UpdateOverlay" << overlay_index << "finish";
}

void D_MAKRO_MegaFoci::MS2_DrawMode_Set(size_t mode)
{
    if(mode >= MS2_DRAW_MODE_NUMBER_OF)
        return;

    MS2_draw_mode = mode;
    StatusSet("Changed draw mode to " + QSL_MS2_DrawMode[mode]);

    for(size_t m = 0; m < MS2_DRAW_MODE_NUMBER_OF; m++)
        v_MS2_PUB_DrawModi[m]->setStyleSheet(m == mode ? "font-weight: bold" : "");
}

void D_MAKRO_MegaFoci::MS2_Draw_RecordedClicks_UpdateAvailiableDrawModi()
{
    MS2_Draw_RecordedClicksChanged(MS2_Viewer1.ClickRecord_RecordedPointsCount());
}

void D_MAKRO_MegaFoci::MS2_Draw_RecordedClicksChanged(size_t point_count)
{
    bool draw_points = MS2_draw_mode == MS2_DRAW_MODE_NUCLEI;

    ui->pushButton_MS2_Tools_ApplyPoints_Remove->setEnabled             (point_count >= 1                );
    ui->pushButton_MS2_Tools_ApplyPoints_Ellipse->setEnabled            (point_count >= 5 && draw_points );
    ui->pushButton_MS2_Tools_ApplyPoints_Polygon->setEnabled            (point_count >= 3 && draw_points );
    ui->pushButton_MS2_Tools_ApplyPoints_ConvexHull->setEnabled         (point_count >= 2 && draw_points );
    ui->pushButton_MS2_Tools_ApplyPoints_Points->setEnabled             (point_count >= 1 && !draw_points);
    ui->pushButton_MS2_Tools_ApplyPointsParam_PointsSmaller->setEnabled (point_count >= 1 && !draw_points);
    ui->pushButton_MS2_Tools_ApplyPointsParam_PointsBigger->setEnabled  (point_count >= 1 && !draw_points);
    ui->spinBox_MS2_Tools_AllplyPoints_PointSize->setEnabled            (point_count >= 1 && !draw_points);
}

bool D_MAKRO_MegaFoci::MS2_CalcMosaik_Size()
{
    MS2_MosaikImageScale = ui->doubleSpinBox_OverviewQuality->value() / 100.0;
    MS2_MosaikBorderPrz = ui->doubleSpinBox_ImgProc_Stitch_Border->value() / 100.0;

    for(size_t c = 0; c < vDIR_MS2_In_MosaikChannels.size(); c++)
    {
        QFileInfoList FIL_Entrys = vDIR_MS2_In_MosaikChannels[c].entryInfoList();
        for(int f = 0; f < FIL_Entrys.size(); f++)
        {
            if(FIL_Entrys[f].suffix() == "png")
            {
                Mat MA_tmp_dummy4size;
                int ER = D_Img_Proc::Load_From_Path(
                                 &MA_tmp_dummy4size,
                                 FIL_Entrys[f]);

                if(ER == ER_okay)
                {
                    MS2_MosaikImageHeight = MA_tmp_dummy4size.rows;
                    MS2_MosaikImageWidth = MA_tmp_dummy4size.cols;
                    MA_tmp_dummy4size.release();
                    return true;
                }

                MA_tmp_dummy4size.release();
            }
        }
    }

    StatusSet("Your mosaik folder contains no images... want too fool me?");
    return false;
}

bool D_MAKRO_MegaFoci::MS2_LoadData()
{
    state_MS2_data_loaded = false;

    if(!MS2_LoadData_DirsIn())
    {
        StatusSet("Load ERROR: Dirs in");
        return false;
    }

    Update_Ui();
    if(!MS2_LoadData_DirsOut())
    {
        StatusSet("Load ERROR: dirs out");
        return false;
    }

    Update_Ui();
    if(!MS2_CalcMosaik_Size())
    {
        StatusSet("Load ERROR: get mosaik size");
        return false;
    }

    Update_Ui();
    if(!MS2_LoadData_Time(0))
    {
        StatusSet("Load ERROR: data time 0");
        return false;
    }

    //show inital images
    MS2_ViewersSelectDefaultCBs();
    MS2_UpdateImages();

    state_MS2_data_loaded = true;
    return true;
}

bool D_MAKRO_MegaFoci::MS2_LoadData_DirsIn()
{
    StatusSet("I need a results folder of step 1. now!");
    QString QS_MasterIn = QFileDialog::getExistingDirectory(
                this,
                "Please select results folder of step 1 as input for step 2 (must beginn with 'Results_Step1_').",
                pStore->dir_M_MegaFoci_Results()->path());

    //check if dir was selected
    if(QS_MasterIn.isEmpty())
    {
        StatusSet("Listen here... if u dont gimme data, i cant work...");
        return false;
    }

    //check, if dir is results from step 1
    if(!QS_MasterIn.contains("Results_Step1"))
    {
        StatusSet("You should selct results from step 1...\n" + QS_Fun_TableFlip);
        return false;
    }

    //master dir in
    DIR_MS2_In_Master.setPath(QS_MasterIn);
    if(!DIR_MS2_In_Master.exists())
    {
        StatusSet("With unknown dark magic you selected a not existing directory. " + QS_Fun_Confused);
        return false;
    }

    //dir in: detections
    DIR_MS2_In_Detections.setPath(DIR_MS2_In_Master.path() + "/Detections");
    if(!DIR_MS2_In_Detections.exists())
    {
        StatusSet("Your selected reults folder does not contain a detections folder... That won't work.");
        return false;
    }

    //dir in: mosaik
    DIR_MS2_In_Mosaik.setPath(DIR_MS2_In_Master.path() + "/Mosaik");
    if(!DIR_MS2_In_Mosaik.exists())
    {
        StatusSet("Your selected reults folder does not contain a mosaik folder... That won't work.");
        return false;
    }

    //dir in: mosaik channels
    vDIR_MS2_In_MosaikChannels.resize(MS2_CH_MOSAIK_NUMBER_OF);
    for(size_t ch = 0; ch < MS2_CH_MOSAIK_NUMBER_OF; ch++)
    {
        vDIR_MS2_In_MosaikChannels[ch].setPath(DIR_MS2_In_Mosaik.path() + "/" + QSL_MS2_ChannelsMosaik[ch]);
        if(!vDIR_MS2_In_MosaikChannels[ch].exists())
        {
            StatusSet("Your selected reults folder does not contain a " + QSL_MS2_ChannelsMosaik[ch] + " mosaik folder... " + QS_Fun_Sad);
            return false;
        }
    }

    //correct input data selected
    StatusSet("Input valid:\n" + DIR_MS2_In_Master.path());

    //save input dir
    QDir DIR_parent(DIR_MS2_In_Master);
    DIR_parent.cdUp();
    pStore->set_dir_M_MegaFoci_Results(DIR_parent.path());

    return true;
}

bool D_MAKRO_MegaFoci::MS2_LoadData_DirsOut()
{
    StatusSet("Want to start a new step 2 editing or want to continue with an existing one?");

    switch(QMessageBox::question(
                this,
                "Output directory selection",
                "New editing or continue with existing step 2 output?",
                "Create new output",                        //0
                "Continue with existing output",            //1
                "Cancel",                                   //2
                0))
    {
    case 0: //.................................... new output ....................................
    {
        StatusSet("Please select the dir you want to store your results to.");
        QString QS_MasterOut = QFileDialog::getExistingDirectory(
                    this,
                    "Please select the master results folder where your step 2 results shall be stored.",
                    pStore->dir_M_MegaFoci_Results()->path());

        //check if dir was selected
        if(QS_MasterOut.isEmpty())
        {
            StatusSet("If u dont give me a folder name, i cant work...");
            return false;
        }

        size_t count = 0;
        QString QS_Folder_Out_Sub = QS_MasterOut + "/Results_Step2_0";
        while(QDir(QS_Folder_Out_Sub).exists())
        {
            count++;
            QS_Folder_Out_Sub = QS_MasterOut + "/Results_Step2_" + QString::number(count);
        }

        //master dir out
        DIR_MS2_Out_Master.setPath(QS_Folder_Out_Sub);
        QDir().mkdir(DIR_MS2_Out_Master.path());
        if(!DIR_MS2_Out_Master.exists())
        {
            StatusSet("Your results folder creation failed. Maybe you have no permission to write to the selected folder?");
            return false;
        }

        //correct input data selected
        StatusSet("Your results will be saved in: " + DIR_MS2_Out_Master.path());

        //save results dir
        QDir DIR_parent(DIR_MS2_Out_Master);
        DIR_parent.cdUp();
        pStore->set_dir_M_MegaFoci_Results(DIR_parent.path());

        //create corrected detections dir
        DIR_MS2_Out_DetectionsCorrected.setPath(DIR_MS2_Out_Master.path() + "/DetectionsCorrected");
        QDir().mkdir(DIR_MS2_Out_DetectionsCorrected.path());
        if(!DIR_MS2_Out_DetectionsCorrected.exists())
        {
            StatusSet("Failed to create corrected detections folder. Maybe you have no permission to write to the selected folder?");
            return false;
        }
    }
    return true;

    case 1: //.................................... existing output ....................................
    {
        StatusSet("Please select results directory to edit.");
        QString QS_MasterOut = QFileDialog::getExistingDirectory(
                    this,
                    "Please select results folder of step 2 you want to edit (must beginn with 'Results_Step2_').",
                    pStore->dir_M_MegaFoci_Results()->path());

        //check if dir was selected
        if(QS_MasterOut.isEmpty())
        {
            StatusSet("Didn't you find your data? A clean file system is a nice thing, right?");
            return false;
        }

        //check, if dir is results from step 2
        if(!QS_MasterOut.contains("Results_Step2"))
        {
            StatusSet("You should selct results from step 2...\n" + QS_Fun_TableFlip);
            return false;
        }

        //master dir out
        DIR_MS2_Out_Master.setPath(QS_MasterOut);
        if(!DIR_MS2_Out_Master.exists())
        {
            StatusSet("With unknown dark magic you selected a not existing directory. " + QS_Fun_Confused);
            return false;
        }

        //dir out: detections
        DIR_MS2_Out_DetectionsCorrected.setPath(DIR_MS2_Out_Master.path() + "/DetectionsCorrected");
        if(!DIR_MS2_Out_DetectionsCorrected.exists())
        {
            StatusSet("Your selected reults folder does not contain a detections folder... That won't work.");
            return false;
        }

        //correct input data selected
        StatusSet("Output valid:\n" + DIR_MS2_Out_Master.path());

        //save output dir
        QDir DIR_parent(DIR_MS2_Out_Master);
        DIR_parent.cdUp();
        pStore->set_dir_M_MegaFoci_Results(DIR_parent.path());
    }
    return true;

    default: //.................................... esc or cancel ....................................
    {
        StatusSet("You quit the step 2 output selection.");
    }
    return false;

    }
}

bool D_MAKRO_MegaFoci::MS2_LoadData_TimeSelected()
{
    return MS2_LoadData_Time(ui->spinBox_MS2_Viewport_T->value());
}

bool D_MAKRO_MegaFoci::MS2_LoadData_Time(size_t t)
{
    if(t >= dataset_dim_t)
        return false;

    if(!MS2_LoadData_Mosaiks_In(t))
        return false;

    if(!MS2_LoadData_Detections_In(t, false))
        return false;

    if(!MS2_LoadData_Detections_Out(t))
        return false;

    if(!MS2_DetOutBackup_Init())
        return false;

    MS2_UpdateViewportPos();

    StatusSet("Data for t=" + QString::number(t) + " succsessfully loaded");

    //quit drawing
    MS2_Draw_RecordingEnd();

    return true;
}

bool D_MAKRO_MegaFoci::MS2_LoadData_Mosaiks_In(size_t t)
{
    if(t >= dataset_dim_t)
        return false;

    StatusSet("Load mosaiks from step 1");

    //resize img vector
    Mat MA_tmp_black = Mat::zeros(
                MS2_MosaikImageHeight,
                MS2_MosaikImageWidth,
                CV_8UC1);

    v_MS2_MA_ChannelsImage_Full.resize(MS2_CH_IMG_NUMBER_OF);
    for(size_t ch = 0; ch < MS2_CH_IMG_NUMBER_OF; ch++)
        v_MS2_MA_ChannelsImage_Full[ch] = MA_tmp_black.clone();

    MA_tmp_black.release();

    //loop channels
    for(size_t ch = 0; ch < MS2_CH_MOSAIK_NUMBER_OF; ch++)
    {
        QFileInfo FI(vDIR_MS2_In_MosaikChannels[ch].path() + "/Mosaik_" + QSL_MS2_ChannelsMosaik[ch] + "_T" + QString::number(t) + ".png");
        Mat MA_tmp_channel;
        int ER = ER_okay;

        //try loading existing img
        if(FI.exists())
        {
            ER = D_Img_Proc::Load_From_Path(
                        &(v_MS2_MA_ChannelsImage_Full[ch+1]),
                        FI);
            ERR(
                        ER,
                        "MS2_LoadData_Mosaiks_In",
                        "Failed to load " + FI.absoluteFilePath() + ".\nAn empty channel image is created instead");
        }
    }

    return true;
}

bool D_MAKRO_MegaFoci::MS2_LoadData_Detections_In(size_t t, bool error_when_no_dir)
{
    if(t >= dataset_dim_t)
        return false;

    qDebug() << "Load input detections from step 1";
    StatusSet("Load input detections from step 1");

    return MS2_LoadData_Detections(
                t,
                error_when_no_dir,
                &vv_MS2_NucImg_In_mosaikXY,
                DIR_MS2_In_Detections,
                &vv_MS2_NucImg_State_In_mosaikXY,
                MS2_IMG_STATE_LOADED,
                MS2_IMG_STATE_NOT_FOUND);
}

bool D_MAKRO_MegaFoci::MS2_LoadData_Detections_Out(size_t t)
{
    if(t >= dataset_dim_t)
        return false;

    qDebug() << "Load output detections from step 2";
    StatusSet("Load output detections from step 2");

    if(!MS2_LoadData_Detections(
                t,
                false,
                &vv_MS2_NucImg_Out_mosaikXY,
                DIR_MS2_Out_DetectionsCorrected,
                &vv_MS2_NucImg_State_Out_mosaikXY,
                MS2_IMG_STATE_PROCESSED,
                MS2_IMG_STATE_NOT_FOUND))
    {
        qDebug() << "Load output detections from step 2 - ERROR";
        StatusSet("Load output detections from step 2 - ERROR");
        return false;
    }

    //copy loaded input detections if no output detections were found
    for(size_t ix = 0; ix < vv_MS2_NucImg_State_In_mosaikXY.size(); ix++)
    {
        for(size_t iy = 0; iy < vv_MS2_NucImg_State_In_mosaikXY.size(); iy++)
        {
            if(vv_MS2_NucImg_State_Out_mosaikXY[ix][iy] != MS2_IMG_STATE_PROCESSED)
            {
                if(vv_MS2_NucImg_State_In_mosaikXY[ix][iy] == MS2_IMG_STATE_LOADED)
                {
                    vv_MS2_NucImg_Out_mosaikXY[ix][iy] = vv_MS2_NucImg_In_mosaikXY[ix][iy];
                    vv_MS2_NucImg_State_Out_mosaikXY[ix][iy] = MS2_IMG_STATE_TO_PROCESS;
                    //qDebug() << "MS2_LoadData_Detections_Out" << "time" << t << "x/y" << ix << iy << "copy in to out";
                }
                else
                {
                    vv_MS2_NucImg_State_Out_mosaikXY[ix][iy] = MS2_IMG_STATE_NOT_FOUND;
                    //qDebug() << "MS2_LoadData_Detections_Out" << "time" << t << "x/y" << ix << iy << "no in found to copy to out";
                }
            }
        }
    }

    state_MS2_detections_loaded = true;
    //MS2_UpdateImage_Viewport();

    return true;
}

bool D_MAKRO_MegaFoci::MS2_LoadData_Detections(size_t t, bool error_when_no_dir, vector<vector<D_Bio_NucleusImage>> *vvNucleiTarget, QDir DIR_Source, vector<vector<size_t>> *vvState, size_t state_found, size_t state_not_found)
{
    if(t >= dataset_dim_t)
        return false;

    //resize mosaic detections container
    vvNucleiTarget->clear();
    vvNucleiTarget->resize(dataset_dim_mosaic_x, vector<D_Bio_NucleusImage>(dataset_dim_mosaic_y, D_Bio_NucleusImage()));

    //init with correct offsets
    for(size_t y = 0; y < dataset_dim_mosaic_y; y++)
        for(size_t x = 0; x < dataset_dim_mosaic_x; x++)
        {
            //relative border pos
            double left_rel = static_cast<double>(x) / dataset_dim_mosaic_x;
            double top_rel = static_cast<double>(y) / dataset_dim_mosaic_y;

            //calc offset
            Point P_Offset = Point(left_rel * MS2_MosaikImageWidth, top_rel * MS2_MosaikImageHeight) * (1.0 / MS2_MosaikImageScale);

            //generate img with correct offsets
            (*vvNucleiTarget)[x][y] = D_Bio_NucleusImage(P_Offset, Point(x, y), t);
        }

    //resize state containers
    vvState->clear();
    vvState->resize(dataset_dim_mosaic_x, vector<size_t>(dataset_dim_mosaic_y, state_not_found));

    //detections dir time t
    QDir DIR_t(DIR_Source.path() + "/Time_" + QString::number(t));
    if(!DIR_t.exists() && error_when_no_dir)
        return false;

    //get image directories
    QStringList QSL_ImageDirs = DIR_t.entryList(QDir::Dirs | QDir::NoDot | QDir::NoDotDot);

    //loop image dirs
    for(int d = 0; d < QSL_ImageDirs.size(); d++)
    {
        bool img_loaded = false;

        //image dir
        QString QS_ImageDirName = QSL_ImageDirs[d];
        QDir DIR_ImageTYX(DIR_t.path() + "/" + QS_ImageDirName);

      //qDebug() << "D_MAKRO_MegaFoci::MS2_LoadData_Detections" << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << QS_ImageDirName;
      //qDebug() << "D_MAKRO_MegaFoci::MS2_LoadData_Detections" << "DIR" << DIR_ImageTYX.path();
        if(DIR_ImageTYX.exists())
        {
            //qDebug() << "D_MAKRO_MegaFoci::MS2_LoadData_Detections" << "dir exists";

            //check if indicatros contained
            if(QS_ImageDirName.contains("_X") && QS_ImageDirName.contains("_Y") && QS_ImageDirName.contains("Image_T" + QString::number(t)))
            {
                //qDebug() << "D_MAKRO_MegaFoci::MS2_LoadData_Detections" << "indicator strings contained" << QS_ImageDirName;

                //blocks in dir name
                QStringList QSL_ImageDirBlocks = QS_ImageDirName.split("_");
                if(QSL_ImageDirBlocks.size() == 4)//Image_T*_Y*_X*
                {
                    //qDebug() << "D_MAKRO_MegaFoci::MS2_LoadData_Detections" << "correct block count of name" << QSL_ImageDirBlocks;

                    //get x
                    bool ok_x;
                    QString QS_BlockX = QSL_ImageDirBlocks[3];
                    QS_BlockX = QS_BlockX.remove(0, 1);
                    int dir_x = QS_BlockX.toInt(&ok_x);

                    //get y
                    bool ok_y;
                    QString QS_BlockY = QSL_ImageDirBlocks[2];
                    QS_BlockY = QS_BlockY.remove(0, 1);
                    int dir_y = QS_BlockY.toInt(&ok_y);

                    //qDebug() << "D_MAKRO_MegaFoci::MS2_LoadData_Detections" << "read x/y" << QSL_ImageDirBlocks[3] << QSL_ImageDirBlocks[2] << "reduced to" << QS_BlockX << QS_BlockY;

                    //conversion to numbers worked?
                    if(ok_x && ok_y)
                    {
                        //calc indices (results from step 1 saved with mosaic coordiantes in name not pixel coordinates)
                        size_t ix = dir_x; //floor(((static_cast<double>(dir_x) / (MS2_MosaikImageWidth  / MS2_MosaikImageScale)) * dataset_dim_mosaic_x) + 0.5);
                        size_t iy = dir_y; //floor(((static_cast<double>(dir_y) / (MS2_MosaikImageHeight / MS2_MosaikImageScale)) * dataset_dim_mosaic_y) + 0.5);

                        //qDebug() << "D_MAKRO_MegaFoci::MS2_LoadData_Detections" << "map coordinates x/y" << dir_x << dir_y << "to mosaic ix/iy" << ix << iy;

                        //indices in range?
                        if(ix < dataset_dim_mosaic_x && iy < dataset_dim_mosaic_y)
                        {
                            //qDebug() << "D_MAKRO_MegaFoci::MS2_LoadData_Detections" << "mosaix coordinates in range";

                            //calc rel pos
                            double left_rel = static_cast<double>(ix) / dataset_dim_mosaic_x;
                            double top_rel = static_cast<double>(iy) / dataset_dim_mosaic_y;

                            //calc offsets
                            Point P_OffsetNotScaled;
                            if(mode_major_current == MODE_MAJOR_2_MANU_CORRECT_DETECTION)
                            {
                                Point P_OffsetScaled = Point(left_rel * MS2_MosaikImageWidth, top_rel * MS2_MosaikImageHeight);
                                P_OffsetNotScaled = P_OffsetScaled * (1.0 / MS2_MosaikImageScale);
                            }
                            else if(mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
                            {
                                P_OffsetNotScaled = Point(
                                            ix * (dataset_dim_img_x - ui->spinBox_ImgProc_Stitch_Overlap_x->value()),
                                            iy * (dataset_dim_img_y - ui->spinBox_ImgProc_Stitch_Overlap_y->value()));
                            }
                            else
                                return false;


                            //load nucleus image
                            D_Bio_NucleusImage NucImg;
                            int ER = NucImg.load(DIR_ImageTYX.path());
                            ERR(ER, "MS2_LoadData_Detections", "Load nucleus image");

                            //succsess?
                            if(ER == ER_okay)
                            {
                                //set offsets
                                NucImg.set_OffsetPixels(P_OffsetNotScaled);
                                NucImg.set_OffsetMosaicGrid(Point(ix, iy));

                                //save nucleus image
                                (*vvNucleiTarget)[ix][iy] = NucImg;

                                //mark image as found
                                (*vvState)[ix][iy] = state_found;

                                img_loaded = true;

                                //test
                                //qDebug() << "D_MAKRO_MegaFoci::MS2_LoadData_Detections" << "Loaded x/y" << ix << iy << NucImg.info();
                            }
                        }
                    }
                }
            }
        }
    }

    return true;
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
    /*
    //pre
    //ui->label_pre_4->setStyleSheet(index == STEP_PRE_STITCH ? QS_StyleActive : QS_StyleNormal);
    ui->label_pre_5->setStyleSheet(index == STEP_PRE_PROJECT_Z ? QS_StyleActive : QS_StyleNormal);
    //vis
    ui->label_vis_1_3->setStyleSheet((index == STEP_VIS_PAGES_AS_COLOR_QUANTILS_ALL || index == STEP_VIS_PAGES_AS_COLOR_QUANTILS_GFP_RFP) ? QS_StyleActive : QS_StyleNormal);
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
    //vis
    ui->label_vis_6->setStyleSheet(index == STEP_VIS_REGIONS_BACKGROUND ? QS_StyleActive : QS_StyleNormal);
    */
}

void D_MAKRO_MegaFoci::on_spinBox_Viewport_P_valueChanged(int arg1)
{
    if(static_cast<size_t>(arg1) < dataset_dim_p_exist)
        ui->spinBox_Viewport_P->setSuffix(" (" + QSL_Pages[arg1] + ")");
}

void D_MAKRO_MegaFoci::on_tabWidget_Control_currentChanged(int index)
{
    //MS1 -> MS3
    if(index == TAB_CONTROL_IMG_PROC_MS1 && mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
    {
        ui->tabWidget_Control->setCurrentIndex(TAB_CONTROL_IMG_PROC_MS3);
        return;
    }

    //MS3 -> MS1
    if(index == TAB_CONTROL_IMG_PROC_MS3 && mode_major_current == MODE_MAJOR_1_AUTO_DETECTION)
    {
        ui->tabWidget_Control->setCurrentIndex(TAB_CONTROL_IMG_PROC_MS1);
        return;
    }

    //run methods requested
    switch (index) {

    case TAB_CONTROL_IMG_PROC_MS1:
    case TAB_CONTROL_IMG_PROC_MS3:
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
    Update_ImageProcessing_StepFrom_MS1(STEP_PRE_STITCH);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Pre_Blur_Size_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_PRE_BLUR_GAUSS);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Pre_Blur_Sigma_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_PRE_BLUR_GAUSS);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_comboBox_ImgProc_ProjectZ_Stat_currentIndexChanged(int index)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_PRE_PROJECT_Z);
    index++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Vis_Other_Min_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_VIS_OTHER);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Vis_Other_Max_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_VIS_OTHER);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Vis_Other_Gamma_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_VIS_OTHER);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Vis_GFP_Min_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_VIS_GFP);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Vis_GFP_Max_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_VIS_GFP);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Vis_GFP_Gamma_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_VIS_GFP);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Vis_RFP_Min_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_VIS_RFP);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Vis_RFP_Max_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_VIS_RFP);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Vis_RFP_Gamma_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_VIS_RFP);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_RankOrder_Size_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_RANK_ORDER);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_RankOrder_Quantil_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG0_THRES);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0_Thresh_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG0_THRES);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Seg0_ClosingSize_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG0_MORPH_OPENING);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0_Area_Min_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG0_SELECT_AREA);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0_Area_Max_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG0_FILL_HOLES);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg1_DistThresh_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG1_SEEDS);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Seg1_OpenSeeds_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG1_SEEDS_CLEAR);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg2_DistThresh_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG2_SEEDS);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Seg2_OpenSeeds_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG2_SEEDS_CLEAR);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg2_Area_Min_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG2_SELECT_AREA);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg2_Area_Max_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG2_SELECT_AREA);
    arg1++;//useless opration to supress warning
}


void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Foc_GFP_BlurMedianSize_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_FOC_GFP_BLUR_MEDIAN);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Foc_GFP_BinarySize_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_FOC_GFP_BINARY_THRES);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_GFP_BinarySigma_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_FOC_GFP_BINARY_THRES);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_GFP_BinaryOffset_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_FOC_GFP_BINARY_THRES);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_GFP_AreaMin_valueChanged(double arg1)
{
    if(arg1 > ui->doubleSpinBox_ImgProc_Foc_GFP_AreaMax->value())
        ui->doubleSpinBox_ImgProc_Foc_GFP_AreaMax->setValue(arg1);
    else
        Update_ImageProcessing_StepFrom_MS1(STEP_FOC_GFP_SELECT_AREA);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_GFP_AreaMax_valueChanged(double arg1)
{
    if(arg1 < ui->doubleSpinBox_ImgProc_Foc_GFP_AreaMin->value())
        ui->doubleSpinBox_ImgProc_Foc_GFP_AreaMin->setValue(arg1);
    else
        Update_ImageProcessing_StepFrom_MS1(STEP_FOC_GFP_SELECT_AREA);
}





void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Foc_RFP_BlurMedianSize_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_FOC_RFP_BLUR_MEDIAN);
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Foc_RFP_BinarySize_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_FOC_RFP_BINARY_THRES);

    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_RFP_BinarySigma_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_FOC_RFP_BINARY_THRES);

    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_RFP_BinaryOffset_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_FOC_RFP_BINARY_THRES);

    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_RFP_AreaMin_valueChanged(double arg1)
{
    if(arg1 > ui->doubleSpinBox_ImgProc_Foc_RFP_AreaMax->value())
        ui->doubleSpinBox_ImgProc_Foc_RFP_AreaMax->setValue(arg1);
    else
        Update_ImageProcessing_StepFrom_MS1(STEP_FOC_RFP_SELECT_AREA);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_RFP_AreaMax_valueChanged(double arg1)
{
    if(arg1 < ui->doubleSpinBox_ImgProc_Foc_RFP_AreaMin->value())
        ui->doubleSpinBox_ImgProc_Foc_RFP_AreaMin->setValue(arg1);
    else
        Update_ImageProcessing_StepFrom_MS1(STEP_FOC_RFP_SELECT_AREA);
}



void D_MAKRO_MegaFoci::on_spinBox_DataDim_P_exist_valueChanged(int arg1)
{
    ui->spinBox_PageIndex_Other->setEnabled(arg1 > 2);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_Both_AreaMin_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_FOC_BOTH_SELECT_AREA);

    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Foc_Both_AreaMax_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_FOC_BOTH_SELECT_AREA);

    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Stitch_Overlap_x_valueChanged(int arg1)
{
    ui->spinBox_ImgProc_Stitch_Overlap_x->setSuffix("px (" + QString::number((100.0 * arg1) / static_cast<double>(dataset_dim_img_x), 'g', 4) + "%)");
    Update_ImageProcessing_StepFrom_MS1(STEP_PRE_STITCH);
    Overview_Init();
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Stitch_Overlap_y_valueChanged(int arg1)
{
    ui->spinBox_ImgProc_Stitch_Overlap_y->setSuffix("px (" + QString::number((100.0 * arg1) / static_cast<double>(dataset_dim_img_y), 'g', 4) + "%)");
    Update_ImageProcessing_StepFrom_MS1(STEP_PRE_STITCH);
    Overview_Init();
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Vis_Intensity_Background_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_VIS_REGIONS_BACKGROUND);

    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Vis_Intensity_Overlay_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_VIS_REGIONS_BACKGROUND);

    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_pushButton_StepMajor_1_clicked()
{
    set_ModeMajor_Current(MODE_MAJOR_1_AUTO_DETECTION);
    StatusSet("I'm hungry. Please feed dataset.");
    StatusSet("(See button in the upper right)");
}

void D_MAKRO_MegaFoci::on_pushButton_StepMajor_2_clicked()
{
    set_ModeMajor_Current(MODE_MAJOR_2_MANU_CORRECT_DETECTION);
    StatusSet("Time to tell the PC where it messed up");
    StatusSet("Nothing can replace an expert like you " + QS_Fun_Happy);
    StatusSet("Start by loading precalculated data from step 1");
}

void D_MAKRO_MegaFoci::on_pushButton_StepMajor_3_clicked()
{
    set_ModeMajor_Current(MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI);
    StatusSet("Time for monkey work again. Lean back and watch the show.");
}

void D_MAKRO_MegaFoci::on_pushButton_StepMajor_4_clicked()
{
    set_ModeMajor_Current(MODE_MAJOR_4_AUTO_RECONSTRUCT_PEDIGREE);
    StatusSet("Try to figure out which potato is the mother of another");
}

void D_MAKRO_MegaFoci::on_pushButton_StepMajor_5_clicked()
{
    set_ModeMajor_Current(MODE_MAJOR_5_MANU_CORRECT_PEDIGREE);
    StatusSet("Time for potato family therapy");
}

void D_MAKRO_MegaFoci::on_pushButton_StepMajor_6_clicked()
{
    set_ModeMajor_Current(MODE_MAJOR_6_EPIC_ANALYSIS);
    StatusSet("Time to harvest the fruits of all the work <3");
}

void D_MAKRO_MegaFoci::on_horizontalSlider_OverviewBig_T_valueChanged(int value)
{
    ui->spinBox_OverviewBig_T->setValue(value);
}

void D_MAKRO_MegaFoci::on_checkBox_MS2_ViewerShowSettings_clicked(bool checked)
{
    for(size_t v = 0; v < v_MS2_GRB_Viewer_GroupSettings.size(); v++)
        v_MS2_GRB_Viewer_GroupSettings[v]->setVisible(checked);

    Update_Ui();
    MS2_UpdateViews();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_FileDialog_clicked()
{
    if(MS2_LoadData())
    {
        ui->groupBox_MS2_Files->setEnabled(false);
        ui->groupBox_MS2_Viewers->setEnabled(true);
        ui->groupBox_VisTrafo->setEnabled(true);
        ui->groupBox_MS2_Viewport->setEnabled(true);
        ui->groupBox_MS2_Tools->setEnabled(true);
        ui->groupBox_MS2_ViewerControls->setEnabled(true);
        MS2_SetComboboxColor_All();
    }
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_ViewerMaximize_1_clicked()
{
    MS2_ViewerMaximize(0);
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_ViewerMaximize_2_clicked()
{
    MS2_ViewerMaximize(1);
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_ViewerMaximize_3_clicked()
{
    MS2_ViewerMaximize(2);
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_ViewerMaximize_4_clicked()
{
    MS2_ViewerMaximize(3);
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_ViewerSettings_PointColor_1_clicked()
{
    MS2_ViewerPointColor(0);
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_ViewerSettings_PointColor_2_clicked()
{
    MS2_ViewerPointColor(1);
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_ViewerSettings_PointColor_3_clicked()
{
    MS2_ViewerPointColor(2);
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_ViewerSettings_PointColor_4_clicked()
{
    MS2_ViewerPointColor(3);
}

void D_MAKRO_MegaFoci::on_checkBox_MS2_ViewerSettings_ConnectZoom_1_clicked(bool checked)
{
    MS2_ViewerConnectZooms(0, checked);
}

void D_MAKRO_MegaFoci::on_checkBox_MS2_ViewerSettings_ConnectZoom_2_clicked(bool checked)
{
    MS2_ViewerConnectZooms(1, checked);
}

void D_MAKRO_MegaFoci::on_checkBox_MS2_ViewerSettings_ConnectZoom_3_clicked(bool checked)
{
    MS2_ViewerConnectZooms(2, checked);
}

void D_MAKRO_MegaFoci::on_checkBox_MS2_ViewerSettings_ConnectZoom_4_clicked(bool checked)
{
    MS2_ViewerConnectZooms(3, checked);
}

void D_MAKRO_MegaFoci::on_checkBox_MS2_ViewerSettings_ViewTransform_1_clicked(bool checked)
{
    MS2_ViewerSetVisTrafoActive(0);

    checked=true;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_checkBox_MS2_ViewerSettings_ViewTransform_2_clicked(bool checked)
{
    MS2_ViewerSetVisTrafoActive(1);

    checked=true;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_checkBox_MS2_ViewerSettings_ViewTransform_3_clicked(bool checked)
{
    MS2_ViewerSetVisTrafoActive(2);

    checked=true;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_checkBox_MS2_ViewerSettings_ViewTransform_4_clicked(bool checked)
{
    MS2_ViewerSetVisTrafoActive(3);

    checked=true;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_Channel_Nuclei_clicked()
{
    MS2_DrawMode_Set(MS2_DRAW_MODE_NUCLEI);
    MS2_Draw_RecordedClicks_UpdateAvailiableDrawModi();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_Channel_GFPonly_clicked()
{
    MS2_DrawMode_Set(MS2_DRAW_MODE_FOCI_GFP);
    MS2_Draw_RecordedClicks_UpdateAvailiableDrawModi();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_Channel_RFPonly_clicked()
{
    MS2_DrawMode_Set(MS2_DRAW_MODE_FOCI_RFP);
    MS2_Draw_RecordedClicks_UpdateAvailiableDrawModi();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_Channel_GFPandRFP_clicked()
{
    MS2_DrawMode_Set(MS2_DRAW_MODE_FOCI_BOTH);
    MS2_Draw_RecordedClicks_UpdateAvailiableDrawModi();
}

void D_MAKRO_MegaFoci::on_comboBox_MS2_ViewportBackground_currentIndexChanged(int index)
{
    if(state_MS2_data_loaded)
        MS2_UpdateImage_Viewport();

    index++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_groupBox_VisTrafo_clicked()
{
    if(mode_major_current == MODE_MAJOR_2_MANU_CORRECT_DETECTION)
        MS2_ViewerSetVisTrafoActive_All();
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_MS2_Params_NucleusBorderThickness_valueChanged(double arg1)
{
    MS2_UpdateOverlay(MS2_CH_OVR_NUCLEI);
    MS2_UpdateImages_Editing();

    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_MS2_Params_FociMinRadius_valueChanged(double arg1)
{
    MS2_UpdateOverlay(MS2_CH_OVR_FOCI_GFP);
    MS2_UpdateOverlay(MS2_CH_OVR_FOCI_RFP);
    MS2_UpdateOverlay(MS2_CH_OVR_FOCI_BOTH);
    MS2_UpdateImages_Editing();

    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Viewport_Left_clicked()
{
    ui->spinBox_MS2_Viewport_X->setValue(ui->spinBox_MS2_Viewport_X->value() - 1);
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Viewport_Right_clicked()
{
    ui->spinBox_MS2_Viewport_X->setValue(ui->spinBox_MS2_Viewport_X->value() + 1);
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Viewport_Up_clicked()
{
    ui->spinBox_MS2_Viewport_Y->setValue(ui->spinBox_MS2_Viewport_Y->value() - 1);
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Viewport_Down_clicked()
{
    ui->spinBox_MS2_Viewport_Y->setValue(ui->spinBox_MS2_Viewport_Y->value() + 1);
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Viewport_Next_clicked()
{
    ui->spinBox_MS2_Viewport_T->setValue(ui->spinBox_MS2_Viewport_T->value() + 1);
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Viewport_Previous_clicked()
{
    ui->spinBox_MS2_Viewport_T->setValue(ui->spinBox_MS2_Viewport_T->value() - 1);
}

void D_MAKRO_MegaFoci::on_checkBox_MS2_ViewportOverlay_clicked()
{
    MS2_UpdateImage_Viewport();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_Progress_Clear_clicked()
{
    MS2_Draw_Clear();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_Progress_Reset_clicked()
{
    MS2_Draw_Reset();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_Progress_ToCorrect_clicked()
{
    MS2_Draw_SetToProcess();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_Progress_Corrected_clicked()
{
    MS2_Draw_SetProcessed();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_History_Undo_clicked()
{
    MS2_DetOutBackup_Undo();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_History_Redo_clicked()
{
    MS2_DetOutBackup_Redo();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_RecordPoints_Start_clicked()
{
    MS2_Draw_RecordingStart();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_RecordPoints_Cancel_clicked()
{
    MS2_Draw_RecordingEnd();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_ApplyPoints_Polygon_clicked()
{
    MS2_Draw_Polygon();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_ApplyPoints_Ellipse_clicked()
{
    MS2_Draw_Ellipse();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_ApplyPoints_Remove_clicked()
{
    MS2_Draw_Remove();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_ApplyPoints_ConvexHull_clicked()
{
    MS2_Draw_ConvexHull();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_ApplyPoints_Points_clicked()
{
    MS2_Draw_Points();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_ApplyPointsParam_PointsBigger_clicked()
{
    ui->spinBox_MS2_Tools_AllplyPoints_PointSize->setValue(ui->spinBox_MS2_Tools_AllplyPoints_PointSize->value() + 1);
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_ApplyPointsParam_PointsSmaller_clicked()
{
    ui->spinBox_MS2_Tools_AllplyPoints_PointSize->setValue(ui->spinBox_MS2_Tools_AllplyPoints_PointSize->value() - 1);
}

void D_MAKRO_MegaFoci::on_spinBox_MS2_ViewerSettings_PointDiameter_1_valueChanged(int arg1)
{
    MS2_ViewerPointDiameter(0, arg1);
}

void D_MAKRO_MegaFoci::on_spinBox_MS2_ViewerSettings_PointDiameter_2_valueChanged(int arg1)
{
    MS2_ViewerPointDiameter(1, arg1);
}

void D_MAKRO_MegaFoci::on_spinBox_MS2_ViewerSettings_PointDiameter_3_valueChanged(int arg1)
{
    MS2_ViewerPointDiameter(2, arg1);
}

void D_MAKRO_MegaFoci::on_spinBox_MS2_ViewerSettings_PointDiameter_4_valueChanged(int arg1)
{
    MS2_ViewerPointDiameter(3, arg1);
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Viewport_NextToCorrect_clicked()
{
    MS2_MoveToNextViewportToProcess();
}

void D_MAKRO_MegaFoci::on_spinBox_MS2_Viewport_X_valueChanged(int arg1)
{
    ui->pushButton_MS2_Viewport_Left->setEnabled(arg1 > 0);
    ui->pushButton_MS2_Viewport_Right->setEnabled(arg1 < static_cast<int>(dataset_dim_mosaic_x) - 1);
}

void D_MAKRO_MegaFoci::on_spinBox_MS2_Viewport_Y_valueChanged(int arg1)
{
    ui->pushButton_MS2_Viewport_Up->setEnabled(arg1 > 0);
    ui->pushButton_MS2_Viewport_Down->setEnabled(arg1 < static_cast<int>(dataset_dim_mosaic_y) - 1);
}

void D_MAKRO_MegaFoci::on_spinBox_MS2_Viewport_T_valueChanged(int arg1)
{
    ui->pushButton_MS2_Viewport_Previous->setEnabled(arg1 > 0);
    ui->pushButton_MS2_Viewport_Next->setEnabled(arg1 < static_cast<int>(dataset_dim_t) - 1);
}

void D_MAKRO_MegaFoci::on_progressBar_MS2_CorrectionProgress_valueChanged(int value)
{
    ui->pushButton_MS2_Viewport_NextToCorrect->setEnabled(value < ui->progressBar_MS2_CorrectionProgress->maximum());
}

void D_MAKRO_MegaFoci::on_stackedWidget_StepMajor_currentChanged(int arg1)
{
    if(arg1 == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
        ui->stackedWidget_StepMajor->setCurrentIndex(MODE_MAJOR_1_AUTO_DETECTION);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_MS3_ImgProc_Vis_BackgroundQuantil_high_valueChanged(double arg1)
{
    arg1++;//useless opration to supress warning
    Update_ImageProcessing_StepFrom_MS3(STEP_MS3_PRE_PROJECT_Z);
}

void D_MAKRO_MegaFoci::on_comboBox_MS3_ImgProc_ProjectZ_Stat_currentIndexChanged(int index)
{
    index++;//useless opration to supress warning
    Update_ImageProcessing_StepFrom_MS3(STEP_MS3_VIS_PAGES_AS_COLOR_GFP_RFP);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_MS3_ImgProc_Vis_BackgroundQuantil_low_valueChanged(double arg1)
{
    arg1++;//useless opration to supress warning
    Update_ImageProcessing_StepFrom_MS3(STEP_MS3_VIS_PAGES_AS_COLOR_GFP_RFP);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_MS3_ImgProc_Vis_Intensity_Overlay_valueChanged(double arg1)
{
    arg1++;//useless opration to supress warning
    Update_ImageProcessing_StepFrom_MS3(STEP_MS3_VIS_REGIONS);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_MS3_ImgProc_Vis_Intensity_Background_valueChanged(double arg1)
{
    arg1++;//useless opration to supress warning
    Update_ImageProcessing_StepFrom_MS3(STEP_MS3_VIS_REGIONS);
}

void D_MAKRO_MegaFoci::on_comboBox_MS3_ImgProc_StepShow_currentIndexChanged(int index)
{
    ///enable/disable viewport plane and page selection
    ui->spinBox_Viewport_Z->setEnabled(index < STEP_MS3_PRE_PROJECT_Z);
    ui->spinBox_Viewport_P->setEnabled(index < STEP_MS3_PCK_OTHER);

    ///update data dimension info in statusbar
    L_SB_InfoVD->setText(vVD_ImgProcSteps[index].info_short());

    ///show image from proc chain
    Update_Images_Proc();
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_MS3_ImgProc_DuplicateRelThres_valueChanged(double arg1)
{
    arg1++;//useless opration to supress warning
    Update_ImageProcessing_StepFrom_MS3(STEP_MS3_VIS_NUCLEI_BORDERS);
}


