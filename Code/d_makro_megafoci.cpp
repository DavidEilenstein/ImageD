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
    connect(ui->spinBox_Viewport_Z,                         SIGNAL(valueChanged(int)),                  this,               SLOT(Update_Images_Proc()));
    connect(ui->spinBox_Viewport_P,                         SIGNAL(valueChanged(int)),                  this,               SLOT(Update_Images_Proc()));
    connect(ui->spinBox_Viewport_S,                         SIGNAL(valueChanged(int)),                  this,               SLOT(Update_Images_Proc()));
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
    setWindowTitle("ImageD - Mega foci tracker");
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
    case MODE_MAJOR_6_EPIC_ANALYSIS:                MS6_UpdateViews();      break;
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
    int s = ui->spinBox_Viewport_S->value();

    //make sure indices fit
    if(z >= vVD_ImgProcSteps[proc_step_index].pDim()->size_Z())   z = 0;
    if(p >= vVD_ImgProcSteps[proc_step_index].pDim()->size_P())   p = 0;
    if(s >= vVD_ImgProcSteps[proc_step_index].pDim()->size_S())   s = 0;

    //2D plane to show
    D_VisDat_Slice_2D Slice2d(-1, -1, z, 0, s, p);

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
                        if(x > 0         )  vNeighborNucImg.push_back(vv_MS3_NucImg_InCorrected_mosaikXY[x - 1][y    ]);
                        if(         y > 0)  vNeighborNucImg.push_back(vv_MS3_NucImg_InCorrected_mosaikXY[x    ][y - 1]);
                        if(x > 0 && y > 0)  vNeighborNucImg.push_back(vv_MS3_NucImg_InCorrected_mosaikXY[x - 1][y - 1]);

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

    if(state_block_img_proc_update)
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
    if(state_block_img_proc_update)
        return;

    if(mode_major_current == MODE_MAJOR_1_AUTO_DETECTION)
        return Update_ImageProcessing_StepFrom_MS1(step_start);
    else if(mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
        return Update_ImageProcessing_StepFrom_MS3(step_start);
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepFrom_MS1(size_t step_start)
{
    if(state_block_img_proc_update)
        return;

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
    if(state_block_img_proc_update)
        return;

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
            //qDebug() << "Update_ImageProcessing_StepFrom_MS3" << "select currecnt BV step in ui";
            ui->comboBox_MS3_ImgProc_StepShow->setCurrentIndex(static_cast<int>(s));

            //qDebug() << "Update_ImageProcessing_StepFrom_MS3" << "updatre ui";
            Update_Ui();
        }
    }

    Update_Images_Proc();
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepSingle(size_t step)
{
    if(state_block_img_proc_update)
        return;

    if(mode_major_current == MODE_MAJOR_1_AUTO_DETECTION)
        return Update_ImageProcessing_StepSingle_MS1(step);
    else if(mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
        return Update_ImageProcessing_StepSingle_MS3(step);
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepSingle_MS1(size_t step)
{
    if(state_block_img_proc_update)
        return;

    if(!state_dataset_img_list_loaded)
        return;

    //current position in dataset
    int dataset_pos_x = ui->spinBox_Viewport_X->value();
    int dataset_pos_y = ui->spinBox_Viewport_Y->value();
    int dataset_pos_t = ui->spinBox_Viewport_T->value();

    //major step 1?
    bool ms1 = (mode_major_current == MODE_MAJOR_1_AUTO_DETECTION);

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
                ms1 ? ui->spinBox_ImgProc_Pre_Blur_Size->value() : ui->spinBox_MS3_ImgProc_Pre_Blur_Size->value(),
                ms1 ? ui->spinBox_ImgProc_Pre_Blur_Size->value() : ui->spinBox_MS3_ImgProc_Pre_Blur_Size->value(),
                BORDER_DEFAULT,
                ms1 ? ui->doubleSpinBox_ImgProc_Pre_Blur_Sigma->value() : ui->doubleSpinBox_ImgProc_Pre_Blur_Sigma->value(),
                ms1 ? ui->doubleSpinBox_ImgProc_Pre_Blur_Sigma->value() : ui->doubleSpinBox_ImgProc_Pre_Blur_Sigma->value()),
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
                ms1 ? ui->comboBox_ImgProc_ProjectZ_Stat->currentIndex() : ui->comboBox_MS3_ImgProc_ProjectZ_Stat->currentIndex(),
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
                ms1 ? ui->doubleSpinBox_ImgProc_Vis_Other_Gamma->value() : ui->doubleSpinBox_MS3_ImgProc_Vis_Other_Gamma->value(),
                ms1 ? ui->spinBox_ImgProc_Vis_Other_Min->value() : ui->spinBox_MS3_ImgProc_Vis_Other_Min->value(),
                ms1 ? ui->spinBox_ImgProc_Vis_Other_Max->value() : ui->spinBox_MS3_ImgProc_Vis_Other_Max->value(),
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
                ms1 ? ui->doubleSpinBox_ImgProc_Vis_GFP_Gamma->value() : ui->doubleSpinBox_MS3_ImgProc_Vis_GFP_Gamma->value(),
                ms1 ? ui->spinBox_ImgProc_Vis_GFP_Min->value() : ui->spinBox_MS3_ImgProc_Vis_GFP_Min->value(),
                ms1 ? ui->spinBox_ImgProc_Vis_GFP_Max->value() : ui->spinBox_MS3_ImgProc_Vis_GFP_Max->value(),
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
                ms1 ? ui->doubleSpinBox_ImgProc_Vis_RFP_Gamma->value() : ui->doubleSpinBox_MS3_ImgProc_Vis_RFP_Gamma->value(),
                ms1 ? ui->spinBox_ImgProc_Vis_RFP_Min->value() : ui->spinBox_MS3_ImgProc_Vis_RFP_Min->value(),
                ms1 ? ui->spinBox_ImgProc_Vis_RFP_Max->value() : ui->spinBox_MS3_ImgProc_Vis_RFP_Max->value(),
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

    //Nuclei segmentation 0a ......................................... OTHER

    case STEP_NUC_OTHER_SEG0A_BLUR_GAUSS:
    {
        if(ui->groupBox_Seg0A_OTHER->isChecked())
            ERR(D_VisDat_Proc::Filter_Gauss(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BLUR_GAUSS]),
                    &(vVD_ImgProcSteps[STEP_PCK_OTHER]),
                    int(ui->doubleSpinBox_ImgProc_Seg0A_Blur_GaussSize->value()),
                    int(ui->doubleSpinBox_ImgProc_Seg0A_Blur_GaussSize->value()),
                    BORDER_DEFAULT,
                    ui->doubleSpinBox_ImgProc_Seg0A_Blur_GaussSigma->value(),
                    ui->doubleSpinBox_ImgProc_Seg0A_Blur_GaussSigma->value()),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_OTHER_SEG0A_BLUR_GAUSS");
        else
            vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BLUR_GAUSS] = D_VisDat_Obj(vVD_ImgProcSteps[STEP_PCK_OTHER].Dim(), vVD_ImgProcSteps[STEP_PCK_OTHER].type(), 0);
    }
        break;

    case STEP_NUC_OTHER_SEG0A_BASEBIN_BG_REFERENCE:
    {
        //create out VD
        vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BASEBIN_BG_REFERENCE] =
                D_VisDat_Obj(
                    vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BLUR_GAUSS].Dim(),
                    vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BLUR_GAUSS].type());

        //corners of the 4 subimges
        int x0 = 0;
        int x1 = dataset_dim_img_x;
        int x2 = vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BLUR_GAUSS].pDim()->size_X();
        int y0 = 0;
        int y1 = dataset_dim_img_y;
        int y2 = vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BLUR_GAUSS].pDim()->size_Y();
        vector<Point> vP_TL = {Point(x0, y0), Point(x1, y0), Point(x0, y1), Point(x1, y1)};
        vector<Point> vP_BR = {Point(x1, y1), Point(x2, y1), Point(x1, y2), Point(x2, y2)};

        //crop, filter and insert sub images - treat mosaik segments separatly
        for(size_t i = 0; i < 4; i++)
        {
            //crop
            D_VisDat_Obj VD_tmp_Croped;
            ERR(D_VisDat_Proc::Crop_Rect_Abs(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &VD_tmp_Croped,
                    &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BLUR_GAUSS]),
                    vP_TL[i].x,
                    vP_TL[i].y,
                    vP_BR[i].x - vP_TL[i].x,
                    vP_BR[i].y - vP_TL[i].y),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_OTHER_SEG0A_BASEBIN_BG_REFERENCE - Crop_Rect_Abs (sub img " + QString::number(i) + ")");

            //rank order filter
            D_VisDat_Obj VD_tmp_Filtered;
            ERR(D_VisDat_Proc::Filter_RankOrder_Circular(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &VD_tmp_Filtered,
                    &VD_tmp_Croped,
                    ui->doubleSpinBox_ImgProc_Seg0A_BaseBin_Quantil->value() / 100.0,
                    ui->doubleSpinBox_ImgProc_Seg0A_BaseBin_FilterRadius->value()),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_OTHER_SEG0A_BASEBIN_BG_REFERENCE - Filter_RankOrder_Circular (sub img " + QString::number(i) + ")");

            //insert
            ERR(D_VisDat_Proc::Insert_atPos(
                    &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BASEBIN_BG_REFERENCE]),
                    &VD_tmp_Filtered,
                    vector<int>{
                        vP_TL[i].x,
                        vP_TL[i].y,
                        0,
                        0,
                        0,
                        0}),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_OTHER_SEG0A_BASEBIN_BG_REFERENCE - Insert_atPos (sub img " + QString::number(i) + ")");
        }
    }
        break;

    case STEP_NUC_OTHER_SEG0A_BASEBIN_REF_CORRECTED:
    {
        ERR(D_VisDat_Proc::Math_2img_Function(
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BASEBIN_REF_CORRECTED]),
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BLUR_GAUSS]),
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BASEBIN_BG_REFERENCE]),
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_X_minus_Y,
                    1, 0,
                    1, 0)),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_OTHER_SEG0A_BASEBIN_REF_CORRECTED");
    }
        break;

    case STEP_NUC_OTHER_SEG0A_BASEBIN_THRESH_INDICATOR:
    {
        ERR(D_VisDat_Proc::Threshold_Absolute(
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BASEBIN_THRESH_INDICATOR]),
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BASEBIN_REF_CORRECTED]),
                ui->doubleSpinBox_ImgProc_Seg0A_BaseBin_ThresIndicator->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_OTHER_SEG0A_BASEBIN_THRESH_INDICATOR");
    }
        break;

    case STEP_NUC_OTHER_SEG0A_BASEBIN_THRESH_HYSTERESIS:
    {
        ERR(D_VisDat_Proc::Threshold_Absolute(
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BASEBIN_THRESH_HYSTERESIS]),
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BASEBIN_REF_CORRECTED]),
                ui->doubleSpinBox_ImgProc_Seg0A_BaseBin_ThresHysteresis->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_OTHER_SEG0A_BASEBIN_THRESH_HYSTERESIS");
    }
        break;

    case STEP_NUC_OTHER_SEG0A_BASEBIN_HYSTERESIS:
    {
        ERR(D_VisDat_Proc::Hysteresis(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BASEBIN_HYSTERESIS]),
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BASEBIN_THRESH_INDICATOR]),
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BASEBIN_THRESH_HYSTERESIS]),
                false),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_OTHER_SEG0A_BASEBIN_HYSTERESIS");
    }
        break;

    case STEP_NUC_OTHER_SEG0A_MORPH_CLOSEING:
    {
        ERR(D_VisDat_Proc::MorphSimple_Circ_Closing(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_MORPH_CLOSEING]),
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BASEBIN_HYSTERESIS]),
                ui->spinBox_ImgProc_Seg0A_ClosingSize->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_OTHER_SEG0A_MORPH_CLOSEING");
    }
        break;

    case STEP_NUC_OTHER_SEG0A_FILL_HOLES:
    {
        ERR(D_VisDat_Proc::Fill_Holes(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_FILL_HOLES]),
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_MORPH_CLOSEING])),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG0_FILL_HOLES");
    }
        break;

    case STEP_NUC_OTHER_SEG0A_EXCLUDE_DIRT_BY_STAT:
    {
        ERR(D_VisDat_Proc::ValueStat_Select(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_EXCLUDE_DIRT_BY_STAT]),
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_FILL_HOLES]),
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_BASEBIN_REF_CORRECTED]),
                ui->comboBox_ImgProc_Seg0A_IgnoreDirt_Stat->currentIndex(),
                0,
                ui->doubleSpinBox_ImgProc_Seg0A_IgnoreDirt_Thres->value(),
                8),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_OTHER_SEG0A_EXCLUDE_DIRT_BY_STAT");
    }
        break;

        //Nuclei segmentation 0b ......................................... GFP

        case STEP_NUC_GFP_SEG0B_BLUR_GAUSS:
        {
            if(ui->groupBox_Seg0B_GFP->isChecked())
                ERR(D_VisDat_Proc::Filter_Gauss(
                        D_VisDat_Slicing(c_SLICE_2D_XY),
                        &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BLUR_GAUSS]),
                        &(vVD_ImgProcSteps[STEP_PCK_GFP]),
                        int(ui->doubleSpinBox_ImgProc_Seg0B_Blur_GaussSize->value()),
                        int(ui->doubleSpinBox_ImgProc_Seg0B_Blur_GaussSize->value()),
                        BORDER_DEFAULT,
                        ui->doubleSpinBox_ImgProc_Seg0B_Blur_GaussSigma->value(),
                        ui->doubleSpinBox_ImgProc_Seg0B_Blur_GaussSigma->value()),
                    "Update_ImageProcessing_StepSingle",
                    "STEP_NUC_GFP_SEG0B_BLUR_GAUSS");
            else
                vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BLUR_GAUSS] = D_VisDat_Obj(vVD_ImgProcSteps[STEP_PCK_GFP].Dim(), vVD_ImgProcSteps[STEP_PCK_GFP].type(), 0);
        }
            break;

        case STEP_NUC_GFP_SEG0B_BASEBIN_BG_REFERENCE:
        {
            //create out VD
            vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BASEBIN_BG_REFERENCE] =
                    D_VisDat_Obj(
                        vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BLUR_GAUSS].Dim(),
                        vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BLUR_GAUSS].type());

            //corners of the 4 subimges
            int x0 = 0;
            int x1 = dataset_dim_img_x;
            int x2 = vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BLUR_GAUSS].pDim()->size_X();
            int y0 = 0;
            int y1 = dataset_dim_img_y;
            int y2 = vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BLUR_GAUSS].pDim()->size_Y();
            vector<Point> vP_TL = {Point(x0, y0), Point(x1, y0), Point(x0, y1), Point(x1, y1)};
            vector<Point> vP_BR = {Point(x1, y1), Point(x2, y1), Point(x1, y2), Point(x2, y2)};

            //crop, filter and insert sub images - treat mosaik segments separatly
            for(size_t i = 0; i < 4; i++)
            {
                //crop
                D_VisDat_Obj VD_tmp_Croped;
                ERR(D_VisDat_Proc::Crop_Rect_Abs(
                        D_VisDat_Slicing(c_SLICE_2D_XY),
                        &VD_tmp_Croped,
                        &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BLUR_GAUSS]),
                        vP_TL[i].x,
                        vP_TL[i].y,
                        vP_BR[i].x - vP_TL[i].x,
                        vP_BR[i].y - vP_TL[i].y),
                    "Update_ImageProcessing_StepSingle",
                    "STEP_NUC_GFP_SEG0B_BASEBIN_BG_REFERENCE - Crop_Rect_Abs (sub img " + QString::number(i) + ")");

                //rank order filter
                D_VisDat_Obj VD_tmp_Filtered;
                ERR(D_VisDat_Proc::Filter_RankOrder_Circular(
                        D_VisDat_Slicing(c_SLICE_2D_XY),
                        &VD_tmp_Filtered,
                        &VD_tmp_Croped,
                        ui->doubleSpinBox_ImgProc_Seg0B_BaseBin_Quantil->value() / 100.0,
                        ui->doubleSpinBox_ImgProc_Seg0B_BaseBin_FilterRadius->value()),
                    "Update_ImageProcessing_StepSingle",
                    "STEP_NUC_GFP_SEG0B_BASEBIN_BG_REFERENCE - Filter_RankOrder_Circular (sub img " + QString::number(i) + ")");

                //insert
                ERR(D_VisDat_Proc::Insert_atPos(
                        &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BASEBIN_BG_REFERENCE]),
                        &VD_tmp_Filtered,
                        vector<int>{
                            vP_TL[i].x,
                            vP_TL[i].y,
                            0,
                            0,
                            0,
                            0}),
                    "Update_ImageProcessing_StepSingle",
                    "STEP_NUC_GFP_SEG0B_BASEBIN_BG_REFERENCE - Insert_atPos (sub img " + QString::number(i) + ")");
            }
        }
            break;

        case STEP_NUC_GFP_SEG0B_BASEBIN_REF_CORRECTED:
        {
            ERR(D_VisDat_Proc::Math_2img_Function(
                    &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BASEBIN_REF_CORRECTED]),
                    &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BLUR_GAUSS]),
                    &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BASEBIN_BG_REFERENCE]),
                    D_Math::Function_2D_to_1D(
                        c_MATH_2D_TO_1D_X_minus_Y,
                        1, 0,
                        1, 0)),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_GFP_SEG0B_BASEBIN_REF_CORRECTED");
        }
            break;

        case STEP_NUC_GFP_SEG0B_BASEBIN_THRESH_INDICATOR:
        {
            ERR(D_VisDat_Proc::Threshold_Absolute(
                    &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BASEBIN_THRESH_INDICATOR]),
                    &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BASEBIN_REF_CORRECTED]),
                    ui->doubleSpinBox_ImgProc_Seg0B_BaseBin_ThresIndicator->value()),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_GFP_SEG0B_BASEBIN_THRESH_INDICATOR");
        }
            break;

        case STEP_NUC_GFP_SEG0B_BASEBIN_THRESH_HYSTERESIS:
        {
            ERR(D_VisDat_Proc::Threshold_Absolute(
                    &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BASEBIN_THRESH_HYSTERESIS]),
                    &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BASEBIN_REF_CORRECTED]),
                    ui->doubleSpinBox_ImgProc_Seg0B_BaseBin_ThresHysteresis->value()),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_GFP_SEG0B_BASEBIN_THRESH_HYSTERESIS");
        }
            break;

        case STEP_NUC_GFP_SEG0B_BASEBIN_HYSTERESIS:
        {
            ERR(D_VisDat_Proc::Hysteresis(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BASEBIN_HYSTERESIS]),
                    &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BASEBIN_THRESH_INDICATOR]),
                    &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BASEBIN_THRESH_HYSTERESIS]),
                    false),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_GFP_SEG0B_BASEBIN_HYSTERESIS");
        }
            break;

        case STEP_NUC_GFP_SEG0B_MORPH_CLOSEING:
        {
            ERR(D_VisDat_Proc::MorphSimple_Circ_Closing(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_MORPH_CLOSEING]),
                    &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BASEBIN_HYSTERESIS]),
                    ui->spinBox_ImgProc_Seg0B_ClosingSize->value()),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_GFP_SEG0B_MORPH_CLOSEING");
        }
            break;

        case STEP_NUC_GFP_SEG0B_FILL_HOLES:
        {
            ERR(D_VisDat_Proc::Fill_Holes(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_FILL_HOLES]),
                    &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_MORPH_CLOSEING])),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_GFP_SEG0_FILL_HOLES");
        }
            break;

    case STEP_NUC_GFP_SEG0B_EXCLUDE_DIRT_BY_STAT:
    {
        ERR(D_VisDat_Proc::ValueStat_Select(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_EXCLUDE_DIRT_BY_STAT]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_FILL_HOLES]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_BASEBIN_REF_CORRECTED]),
                ui->comboBox_ImgProc_Seg0B_IgnoreDirt_Stat->currentIndex(),
                0,
                ui->doubleSpinBox_ImgProc_Seg0B_IgnoreDirt_Thres->value(),
                8),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_GFP_SEG0B_EXCLUDE_DIRT_BY_STAT");
    }
        break;

    //Nuclei segmentation 0 .........................................

    case STEP_NUC_BOTH_SEG0_ADD_GFP_OTHER:
    {
        ERR(D_VisDat_Proc::Math_2img_Addition(
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG0_ADD_GFP_OTHER]),
                &(vVD_ImgProcSteps[STEP_NUC_OTHER_SEG0A_EXCLUDE_DIRT_BY_STAT]),
                &(vVD_ImgProcSteps[STEP_NUC_GFP_SEG0B_EXCLUDE_DIRT_BY_STAT])),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG0_ADD_GFP_OTHER");
    }
        break;

    case STEP_NUC_BOTH_SEG0_CLOSE_GAPS:
    {
        ERR(D_VisDat_Proc::MorphSimple_Circ_Closing(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG0_CLOSE_GAPS]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG0_ADD_GFP_OTHER]),
                ui->spinBox_ImgProc_Seg0_CloseGaps_Size->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG0_CLOSE_GAPS");
    }
        break;

    case STEP_NUC_BOTH_SEG0_SELECT_AREA_SMALL:
    {
        ERR(D_VisDat_Proc::Feature_Select(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG0_SELECT_AREA_SMALL]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG0_CLOSE_GAPS]),
                c_FEAT_CONVEX_AREA,
                ui->doubleSpinBox_ImgProc_Seg0_GetSmall_Area_Min->value(),
                ui->doubleSpinBox_ImgProc_Seg0_GetSmall_Area_Max->value(),
                8),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG0_SELECT_AREA_SMALL");
    }
        break;

    case STEP_NUC_BOTH_SEG0_MORPH_CLOSE_SMALL:
    {
        ERR(D_VisDat_Proc::MorphSimple_Circ_Closing(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG0_MORPH_CLOSE_SMALL]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG0_SELECT_AREA_SMALL]),
                ui->doubleSpinBox_ImgProc_ConnectSmall_CloseSize->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG0_MORPH_CLOSE_SMALL");
    }
        break;

    case STEP_NUC_BOTH_SEG0_ADD_CLOSED_SMALL:
    {
        ERR(D_VisDat_Proc::Math_2img_Addition(
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG0_ADD_CLOSED_SMALL]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG0_MORPH_CLOSE_SMALL]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG0_CLOSE_GAPS])),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG0_ADD_CLOSED_SMALL");
    }
        break;

    case STEP_NUC_BOTH_SEG0_SELECT_AREA_BIG:
    {
        ERR(D_VisDat_Proc::Feature_Select(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG0_SELECT_AREA_BIG]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG0_ADD_CLOSED_SMALL]),
                c_FEAT_CONVEX_AREA,
                ui->doubleSpinBox_ImgProc_Seg0_Area_Min->value(),
                ui->doubleSpinBox_ImgProc_Seg0_Area_Max->value(),
                8),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG0_SELECT_AREA_BIG");
    }
        break;

    //Nuclei segmentation 1 .........................................

    case STEP_NUC_BOTH_SEG1_DISTANCE:
    {
        ERR(D_VisDat_Proc::Transformation_Distance(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG1_DISTANCE]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG0_SELECT_AREA_BIG]),
                DIST_L2,
                DIST_MASK_PRECISE),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG1_DISTANCE");
    }
        break;

    case STEP_NUC_BOTH_SEG1_SEEDS:
    {
        ERR(D_VisDat_Proc::Threshold_Absolute(
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG1_SEEDS]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG1_DISTANCE]),
                ui->doubleSpinBox_ImgProc_Seg1_DistThresh->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG1_SEEDS");
    }
        break;

    case STEP_NUC_BOTH_SEG1_SEEDS_CLEAR:
    {
        ERR(D_VisDat_Proc::MorphSimple_Circ_Opening(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG1_SEEDS_CLEAR]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG1_SEEDS]),
                ui->spinBox_ImgProc_Seg1_OpenSeeds->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG1_SEEDS_CLEAR");
    }
        break;

    case STEP_NUC_BOTH_SEG1_WATERSHED:
    {
        ERR(D_VisDat_Proc::Transformation_Watershed_Auto(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG1_WATERSHED]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG0_SELECT_AREA_BIG]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG1_SEEDS_CLEAR]),
                true,
                false,
                false),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG1_WATERSHED\nROI:\n" + vVD_ImgProcSteps[STEP_NUC_BOTH_SEG0_SELECT_AREA_BIG].info_short() + "\nSeeds:\n" + vVD_ImgProcSteps[STEP_NUC_BOTH_SEG1_SEEDS_CLEAR].info_short());
    }
        break;

    case STEP_NUC_BOTH_SEG1_BINARY_SEGMENTS:
    {
        ERR(D_VisDat_Proc::Threshold_Absolute(
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG1_BINARY_SEGMENTS]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG1_WATERSHED]),
                0),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG1_BINARY_SEGMENTS");
    }
        break;

    //Nuclei segmentation 2 .........................................

    case STEP_NUC_BOTH_SEG2_DISTANCE:
    {
        ERR(D_VisDat_Proc::Transformation_Distance(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG2_DISTANCE]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG1_BINARY_SEGMENTS]),
                DIST_L2,
                DIST_MASK_PRECISE),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG2_DISTANCE");
    }
        break;

    case STEP_NUC_BOTH_SEG2_SEEDS:
    {
        ERR(D_VisDat_Proc::Threshold_Absolute(
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG2_SEEDS]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG2_DISTANCE]),
                ui->doubleSpinBox_ImgProc_Seg2_DistThresh->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG2_SEEDS");
    }
        break;

    case STEP_NUC_BOTH_SEG2_SEEDS_CLEAR:
    {
        ERR(D_VisDat_Proc::MorphSimple_Circ_Opening(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG2_SEEDS_CLEAR]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG2_SEEDS]),
                ui->spinBox_ImgProc_Seg2_OpenSeeds->value()),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG2_SEEDS_CLEAR");
    }
        break;

    case STEP_NUC_BOTH_SEG2_WATERSHED:
    {
        ERR(D_VisDat_Proc::Transformation_Watershed_Auto(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG2_WATERSHED]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG1_BINARY_SEGMENTS]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG2_SEEDS_CLEAR]),
                true,
                false,
                true),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG2_WATERSHED");
    }
        break;

    case STEP_NUC_BOTH_SEG2_SELECT_AREA:
    {
        ERR(D_VisDat_Proc::Feature_Select(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG2_SELECT_AREA]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG2_WATERSHED]),
                c_FEAT_CONVEX_AREA,
                ui->doubleSpinBox_ImgProc_Seg2_Area_Min->value(),
                ui->doubleSpinBox_ImgProc_Seg2_Area_Max->value(),
                8),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG2_SELECT_AREA");
    }
        break;

    //Nuclei segmentation 3 .........................................

    case STEP_NUC_BOTH_SEG3_BORDERS_ORIGINAL:
    {
        ERR(D_VisDat_Proc::Geometric_Reduce(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3_BORDERS_ORIGINAL]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG2_SELECT_AREA]),
                c_GEO_CONTOUR,
                4,
                2,
                255),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_NUC_BORDERS_ORIGINAL");
    }
        break;

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . Convex Hull
    case STEP_NUC_BOTH_SEG3A_CONVEX_HULL:
    {
        //contour of convex hull
        D_VisDat_Obj VD_tmp_ConvexHullContour;
        ERR(D_VisDat_Proc::Geometric_Reduce(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &VD_tmp_ConvexHullContour,
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG2_SELECT_AREA]),
                c_GEO_CONVEX_HULL,
                4,
                2,
                255),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG3A_CONVEX_HULL - hull contour");

        //fill contour
        ERR(D_VisDat_Proc::Fill_Holes(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3A_CONVEX_HULL]),
                &VD_tmp_ConvexHullContour),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG3A_CONVEX_HULL - fill contour");
    }
        break;

    case STEP_NUC_BOTH_SEG3A_CONVEX_HULL_WATERSHED_SEGMENTS:
    {
        ERR(D_VisDat_Proc::Transformation_Watershed_Auto(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3A_CONVEX_HULL_WATERSHED_SEGMENTS]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3A_CONVEX_HULL]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG2_SEEDS_CLEAR]),
                true,
                false,
                true),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG3A_CONVEX_HULL_WATERSHED_SEGMENTS");
    }
        break;

    case STEP_NUC_BOTH_SEG3A_CONVEX_HULL_BINARY_SEGMENTS:
    {
        ERR(D_VisDat_Proc::Threshold_Absolute(
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3A_CONVEX_HULL_BINARY_SEGMENTS]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3A_CONVEX_HULL_WATERSHED_SEGMENTS]),
                0),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG3A_CONVEX_HULL_BINARY_SEGMENTS");
    }
        break;

    case STEP_NUC_BOTH_SEG3A_BORDERS_CONVEX_HULL:
    {
        ERR(D_VisDat_Proc::Geometric_Reduce(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3A_BORDERS_CONVEX_HULL]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3A_CONVEX_HULL_BINARY_SEGMENTS]),
                c_GEO_CONTOUR,
                4,
                2,
                255),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG3A_BORDERS_CONVEX_HULL");
    }
        break;


        //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . Ellipse
        case STEP_NUC_BOTH_SEG3B_ELLIPSE:
        {
            //contour of convex hull
            D_VisDat_Obj VD_tmp_EllipseContour;
            ERR(D_VisDat_Proc::Geometric_Reduce(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &VD_tmp_EllipseContour,
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3_BORDERS_ORIGINAL]),
                    c_GEO_ELLIPSE_FIT,
                    4,
                    2,
                    255),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_BOTH_SEG3B_ELLIPSE - ellipse contour");

            //fill contour
            ERR(D_VisDat_Proc::Fill_Holes(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3B_ELLIPSE]),
                    &VD_tmp_EllipseContour),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_BOTH_SEG3B_ELLIPSE - fill contour");
        }
            break;

        case STEP_NUC_BOTH_SEG3B_ELLIPSE_WATERSHED_SEGMENTS:
        {
            ERR(D_VisDat_Proc::Transformation_Watershed_Auto(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3B_ELLIPSE_WATERSHED_SEGMENTS]),
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3B_ELLIPSE]),
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG2_SEEDS_CLEAR]),
                    true,
                    false,
                    true),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_BOTH_SEG3B_ELLIPSE_WATERSHED_SEGMENTS");
        }
            break;

        case STEP_NUC_BOTH_SEG3B_ELLIPSE_BINARY_SEGMENTS:
        {
            ERR(D_VisDat_Proc::Threshold_Absolute(
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3B_ELLIPSE_BINARY_SEGMENTS]),
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3B_ELLIPSE_WATERSHED_SEGMENTS]),
                    0),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_BOTH_SEG3B_ELLIPSE_BINARY_SEGMENTS");
        }
            break;

    case STEP_NUC_BOTH_SEG3B_BORDERS_ELLIPSE:
    {
        ERR(D_VisDat_Proc::Geometric_Reduce(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3B_BORDERS_ELLIPSE]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3B_ELLIPSE_BINARY_SEGMENTS]),
                c_GEO_CONTOUR,
                4,
                2,
                255),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG3B_BORDERS_ELLIPSE");
    }
        break;


        //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . opened
        case STEP_NUC_BOTH_SEG3C_OPEND:
        {
            //contour of convex hull
            D_VisDat_Obj VD_tmp_OpenedContour;
            ERR(D_VisDat_Proc::MorphSimple_Circ_Opening(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &VD_tmp_OpenedContour,
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG2_SELECT_AREA]),
                    ui->spinBox_ImgProc_Seg3_Open->value()),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_BOTH_SEG3C_OPEND - opened contour");

            //fill contour
            ERR(D_VisDat_Proc::Fill_Holes(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3C_OPEND]),
                    &VD_tmp_OpenedContour),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_BOTH_SEG3C_OPEND - fill contour");
        }
            break;

        case STEP_NUC_BOTH_SEG3C_OPEND_WATERSHED_SEGMENTS:
        {
            ERR(D_VisDat_Proc::Transformation_Watershed_Auto(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3C_OPEND_WATERSHED_SEGMENTS]),
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3C_OPEND]),
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG2_SEEDS_CLEAR]),
                    true,
                    false,
                    true),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_BOTH_SEG3C_OPEND_WATERSHED_SEGMENTS");
        }
            break;

        case STEP_NUC_BOTH_SEG3C_OPEND_BINARY_SEGMENTS:
        {
            ERR(D_VisDat_Proc::Threshold_Absolute(
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3C_OPEND_BINARY_SEGMENTS]),
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3C_OPEND_WATERSHED_SEGMENTS]),
                    0),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_BOTH_SEG3C_OPEND_BINARY_SEGMENTS");
        }
            break;

    case STEP_NUC_BOTH_SEG3C_BORDERS_OPENED:
    {
        ERR(D_VisDat_Proc::Geometric_Reduce(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3C_BORDERS_OPENED]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3C_OPEND_BINARY_SEGMENTS]),
                c_GEO_CONTOUR,
                4,
                2,
                255),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG3C_BORDERS_OPENED");
    }
        break;


        //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . opened ellipse
        case STEP_NUC_BOTH_SEG3D_OPEND_ELLIPSE:
        {
            //contour of convex hull
            D_VisDat_Obj VD_tmp_ConvexHullContour;
            ERR(D_VisDat_Proc::Geometric_Reduce(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &VD_tmp_ConvexHullContour,
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3C_BORDERS_OPENED]),
                    c_GEO_ELLIPSE_FIT,
                    4,
                    2,
                    255),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_BOTH_SEG3D_OPEND_ELLIPSE - ellipse contour");

            //fill contour
            ERR(D_VisDat_Proc::Fill_Holes(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3D_OPEND_ELLIPSE]),
                    &VD_tmp_ConvexHullContour),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_BOTH_SEG3D_OPEND_ELLIPSE - fill contour");
        }
            break;

        case STEP_NUC_BOTH_SEG3D_OPEND_ELLIPSE_WATERSHED_SEGMENTS:
        {
            ERR(D_VisDat_Proc::Transformation_Watershed_Auto(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3D_OPEND_ELLIPSE_WATERSHED_SEGMENTS]),
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3D_OPEND_ELLIPSE]),
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG2_SEEDS_CLEAR]),
                    true,
                    false,
                    true),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_BOTH_SEG3D_OPEND_ELLIPSE_WATERSHED_SEGMENTS");
        }
            break;

        case STEP_NUC_BOTH_SEG3D_OPEND_ELLIPSE_BINARY_SEGMENTS:
        {
            ERR(D_VisDat_Proc::Threshold_Absolute(
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3D_OPEND_ELLIPSE_BINARY_SEGMENTS]),
                    &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3D_OPEND_ELLIPSE_WATERSHED_SEGMENTS]),
                    0),
                "Update_ImageProcessing_StepSingle",
                "STEP_NUC_BOTH_SEG3D_OPEND_ELLIPSE_BINARY_SEGMENTS");
        }
            break;

    case STEP_NUC_BOTH_SEG3D_BORDERS_OPENED_ELLIPSE:
    {
        ERR(D_VisDat_Proc::Geometric_Reduce(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3D_BORDERS_OPENED_ELLIPSE]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3D_OPEND_ELLIPSE_BINARY_SEGMENTS]),
                c_GEO_CONTOUR,
                4,
                2,
                255),
            "Update_ImageProcessing_StepSingle",
            "STEP_NUC_BOTH_SEG3D_BORDERS_OPENED_ELLIPSE");
    }
        break;

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . select
    case STEP_NUC_BOTH_SEG3_BINARY_SEGMENTS_USED:
    {
        vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3_BINARY_SEGMENTS_USED] = vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3C_OPEND_BINARY_SEGMENTS];
    }
        break;

    case STEP_NUC_BOTH_SEG3_BORDERS_USED:
    {
        ERR(D_VisDat_Proc::Geometric_Reduce(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3_BORDERS_USED]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3C_BORDERS_OPENED]),
                c_GEO_CONTOUR,
                4,
                2,
                255),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_NUC_BORDERS_USED");
    }
        break;

    //Nuclei segmentation vis .........................................



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

    case STEP_VIS_REGIONS_NUCLEI:
    {
        //color code:
        //STEP_NUC_BOTH_SEG3_BORDERS_ORIGINAL           //red       R
        //STEP_NUC_BOTH_SEG3A_BORDERS_CONVEX_HULL       //blue              B
        //STEP_NUC_BOTH_SEG3B_BORDERS_ELLIPSE           //yellow    R   G
        //STEP_NUC_BOTH_SEG3C_BORDERS_OPENED            //magenta   R       B
        //STEP_NUC_BOTH_SEG3D_BORDERS_OPENED_ELLIPSE    //cyan          G   B
        //STEP_NUC_BOTH_SEG3_BORDERS_USED               //white     R   G   B

        //dummy VD
        D_VisDat_Obj VD_tmp_dummy;

        //black BG
        vVD_ImgProcSteps[STEP_VIS_REGIONS_NUCLEI] =
                D_VisDat_Obj(
                    vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3_BORDERS_ORIGINAL].Dim(),
                    CV_8UC3,
                    0);

        //qDebug() << vVD_ImgProcSteps[STEP_VIS_REGIONS_NUCLEI].info_short();

        //nuclei original
        ERR(D_VisDat_Proc::OverlayOverwrite(
                &VD_tmp_dummy,
                &(vVD_ImgProcSteps[STEP_VIS_REGIONS_NUCLEI]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3_BORDERS_ORIGINAL]),
                255.0, 0.0, 0.0,
                1.0, 1.0),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_REGIONS_NUCLEI - OverlayOverwrite - original");

        //nuclei convex hull
        ERR(D_VisDat_Proc::OverlayOverwrite(
                &(vVD_ImgProcSteps[STEP_VIS_REGIONS_NUCLEI]),
                &VD_tmp_dummy,
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3A_BORDERS_CONVEX_HULL]),
                0.0, 0.0, 255.0,
                1.0, 1.0),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_REGIONS_NUCLEI - OverlayOverwrite - convex hull");

        //nuclei ellipse
        ERR(D_VisDat_Proc::OverlayOverwrite(
                &VD_tmp_dummy,
                &(vVD_ImgProcSteps[STEP_VIS_REGIONS_NUCLEI]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3B_BORDERS_ELLIPSE]),
                255.0, 255.0, 0.0,
                1.0, 1.0),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_REGIONS_NUCLEI - OverlayOverwrite - ellipse");

        //nuclei opened
        ERR(D_VisDat_Proc::OverlayOverwrite(
                &(vVD_ImgProcSteps[STEP_VIS_REGIONS_NUCLEI]),
                &VD_tmp_dummy,
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3C_BORDERS_OPENED]),
                255.0, 0.0, 255.0,
                1.0, 1.0),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_REGIONS_NUCLEI - OverlayOverwrite - opened");

        //nuclei opened ellipse
        ERR(D_VisDat_Proc::OverlayOverwrite(
                &VD_tmp_dummy,
                &(vVD_ImgProcSteps[STEP_VIS_REGIONS_NUCLEI]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3D_BORDERS_OPENED_ELLIPSE]),
                0.0, 255.0, 255.0,
                1.0, 1.0),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_REGIONS_NUCLEI - OverlayOverwrite - opened ellipse");

        //nuclei used
        ERR(D_VisDat_Proc::OverlayOverwrite(
                &(vVD_ImgProcSteps[STEP_VIS_REGIONS_NUCLEI]),
                &VD_tmp_dummy,
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3_BORDERS_USED]),
                255, 255, 255,
                1.0, 1.0),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_REGIONS_NUCLEI - OverlayOverwrite - used");
    }
        break;

    case STEP_VIS_REGIONS_FOCI:
    {
        //foci
        D_VisDat_Obj VD_tmp_Foci;
        ERR(D_VisDat_Proc::Channels_Merge(
                &(vVD_ImgProcSteps[STEP_VIS_REGIONS_FOCI]),     //out
                &(vVD_ImgProcSteps[STEP_FOC_RFP_SELECT_AREA]),  //B
                &(vVD_ImgProcSteps[STEP_FOC_GFP_SELECT_AREA]),  //G
                &(vVD_ImgProcSteps[STEP_FOC_RFP_SELECT_AREA])), //R
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_REGIONS_FOCI - Channels_Merge foci");
    }
        break;

    case STEP_VIS_REGIONS_BACKGROUND_NUCLEI_ALL:
    {
        ERR(D_VisDat_Proc::OverlayOverwrite(
                &(vVD_ImgProcSteps[STEP_VIS_REGIONS_BACKGROUND_NUCLEI_ALL]),
                &(vVD_ImgProcSteps[STEP_VIS_PAGES_AS_COLOR_ALL]),
                &(vVD_ImgProcSteps[STEP_VIS_REGIONS_NUCLEI]),
                ui->doubleSpinBox_ImgProc_Vis_Intensity_Overlay->value() / 100.0,
                ui->doubleSpinBox_ImgProc_Vis_Intensity_Background->value() / 100.0),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_REGIONS_BACKGROUND_NUCLEI_ALL - OverlayOverwrite");
    }
        break;

    case STEP_VIS_REGIONS_BACKGROUND_NUCLEI_USED:
    {
        ERR(D_VisDat_Proc::OverlayOverwrite(
                &(vVD_ImgProcSteps[STEP_VIS_REGIONS_BACKGROUND_NUCLEI_USED]),
                &(vVD_ImgProcSteps[STEP_VIS_PAGES_AS_COLOR_ALL]),
                &(vVD_ImgProcSteps[STEP_NUC_BOTH_SEG3_BORDERS_USED]),
                255, 255, 255,
                ui->doubleSpinBox_ImgProc_Vis_Intensity_Overlay->value() / 100.0,
                ui->doubleSpinBox_ImgProc_Vis_Intensity_Background->value() / 100.0),
            "Update_ImageProcessing_StepSingle",
            "STEP_VIS_REGIONS_BACKGROUND_NUCLEI_USED - OverlayOverwrite");
    }
        break;

    /*
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

        //img decomp
        D_Bio_NucleusImage NucImg = vvvImageDecomp_TYX[pos_t][pos_y][pos_x];

        //get foci counts as QStringList
        QStringList QSL_LabelTexts = QStringList();
        NucImg.get_FociCount_append(&QSL_LabelTexts);

        ///geometric moisaik offset in pixels
        Point MosaikOffset_Coordinates(
                    pos_x * (dataset_dim_img_x - ui->spinBox_ImgProc_Stitch_Overlap_x->value()),
                    pos_y * (dataset_dim_img_y - ui->spinBox_ImgProc_Stitch_Overlap_y->value()));
        Point MosaikOffset_Grid(pos_x, pos_y);

        int ER = D_VisDat_Proc::Draw_ContourText(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &(vVD_ImgProcSteps[STEP_VIS_REGIONS_FOCI_COUNT]),
                    &(vVD_ImgProcSteps[STEP_VIS_REGIONS_BACKGROUND]),
                    NucImg.get_nuclei_contours(1, -MosaikOffset_Coordinates),
                    NucImg.get_FociCounts(),
                    NucImg.get_Centroids(1, -MosaikOffset_Coordinates),
                    2,
                    1,
                    1,
                    255);
        ERR(ER, "Update_ImageProcessing_StepSingle", "STEP_VIS_REGIONS_FOCI_COUNT - put numbers on image");
        if(ER != ER_okay)
            return;
    }
        break;
    */

    default:
    {
        ERR(
                    ER_parameter_bad,
                    "Update_ImageProcessing_StepSingle",
                    "default case reached - step parameter out of range");
        StatusSet("ImgProcMS1: Error - No matching step parameter found");
        return;
    }

    }
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepSingle_MS3(size_t step)
{
    if(state_block_img_proc_update)
        return;

    if(!state_dataset_img_list_loaded)
        return;

    //select step to do
    StatusSet("ImgProcMS3: " + QSL_Steps_MS3[int(step)]);

    //chose method for proc step style
    if(step <= STEP_MS3_VIS_PAGES_AS_COLOR_ALL)
        return Update_ImageProcessing_StepSingle_MS1(step);
    else if(step <= STEP_MS3_VIS_FOCI_BOTH)
        return Update_ImageProcessing_StepSingle_MS3_DrawDetections(step);
    else
        return Update_ImageProcessing_StepSingle_MS3_VisualizeResults(step);
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepSingle_MS3_DrawDetections(size_t step)
{
    if(state_block_img_proc_update)
        return;

    if(MS3_current_loaded_detections_T != ui->spinBox_Viewport_T->value())
        MS3_LoadDetections(ui->spinBox_Viewport_T->value());
    if(MS3_current_loaded_detections_T != ui->spinBox_Viewport_T->value())
        return;

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
        if(mx > 0          )  vNeighborNucImg.push_back(vv_MS3_NucImg_InCorrected_mosaikXY[mx - 1][my    ]);
        if(          my > 0)  vNeighborNucImg.push_back(vv_MS3_NucImg_InCorrected_mosaikXY[mx    ][my - 1]);
        if(mx > 0 && my > 0)  vNeighborNucImg.push_back(vv_MS3_NucImg_InCorrected_mosaikXY[mx - 1][my - 1]);

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

        //convert to VD
        vVD_ImgProcSteps[step] = D_VisDat_Obj(vVD_ImgProcSteps[STEP_MS3_PCK_GFP].Dim(), CV_8UC1, 0);
        ERR(D_VisDat_Proc::Write_2D_Plane(
                &(vVD_ImgProcSteps[step]),
                &MA_tmp_target,
                D_VisDat_Slice_2D(-1, -1, 0, 0, 0, 0)),
            "Update_ImageProcessing_StepSingle_MS3_DrawDetections",
            "D_VisDat_Proc::Write_2D_Plane");
    }
        break;

    case STEP_MS3_VIS_NUCLEI_FILLED_STACK:
    {
        //nuclei count
        size_t n_nuc = NucImg.get_nuclei_count();

        //dim of stacked img
        D_VisDat_Dim dim_stacked = vVD_ImgProcSteps[STEP_MS3_PCK_GFP].Dim();
        dim_stacked.set_size_S(n_nuc);

        //init black VD with stacked dim
        vVD_ImgProcSteps[STEP_MS3_VIS_NUCLEI_FILLED_STACK] = D_VisDat_Obj(dim_stacked, CV_8UC1, 0);
        //qDebug() << "Update_ImageProcessing_StepSingle_MS3_DrawDetections" << "STEP_MS3_VIS_NUCLEI_FILLED_STACK" << "init VD:" << vVD_ImgProcSteps[STEP_MS3_VIS_NUCLEI_FILLED_STACK].info_short();

        for(size_t nuc = 0; nuc < n_nuc; nuc++)
        {
            //qDebug() << "loop nuclei" << nuc << "of" << n_nuc;

            //Mat to draw to
            Mat MA_tmp_OneNucOnly = MA_tmp_target.clone();

            //draw nucleus
            ERR(D_Img_Proc::Draw_Contour(
                    &MA_tmp_OneNucOnly,
                    NucImg.get_nuclei_contours(1, -P_Offset)[nuc],
                    -1,
                    255),
                "Update_ImageProcessing_StepSingle_MS3_DrawDetections",
                "STEP_MS3_VIS_NUCLEI_FILLED_STACK - D_Img_Proc::Draw_Contour");

            //put Mat into VD
            ERR(D_VisDat_Proc::Write_2D_Plane(
                    &(vVD_ImgProcSteps[STEP_MS3_VIS_NUCLEI_FILLED_STACK]),
                    &MA_tmp_OneNucOnly,
                    D_VisDat_Slice_2D(-1, -1, 0, 0, nuc, 0)),
                "Update_ImageProcessing_StepSingle_MS3_DrawDetections",
                "D_VisDat_Proc::Write_2D_Plane");

            MA_tmp_OneNucOnly.release();
        }
    }
        break;

        case STEP_MS3_VIS_NUCLEI_FILLED_ALL:
    {
        ERR(D_VisDat_Proc::Dim_Project(
                &(vVD_ImgProcSteps[STEP_MS3_VIS_NUCLEI_FILLED_ALL]),
                &(vVD_ImgProcSteps[STEP_MS3_VIS_NUCLEI_FILLED_STACK]),
                c_DIM_S,
                c_STAT_MAXIMUM,
                CV_8UC1),
            "Update_ImageProcessing_StepSingle_MS3_DrawDetections",
            "D_VisDat_Proc::Dim_Project");
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

        //convert to VD
        vVD_ImgProcSteps[step] = D_VisDat_Obj(vVD_ImgProcSteps[STEP_MS3_PCK_GFP].Dim(), CV_8UC1, 0);
        ERR(D_VisDat_Proc::Write_2D_Plane(
                &(vVD_ImgProcSteps[step]),
                &MA_tmp_target,
                D_VisDat_Slice_2D(-1, -1, 0, 0, 0, 0)),
            "Update_ImageProcessing_StepSingle_MS3_DrawDetections",
            "D_VisDat_Proc::Write_2D_Plane");
    }
        break;

    default:
        break;
    }

    MA_tmp_target.release();

    //update image decomposition when all foci are drawn
    if(step == STEP_MS3_VIS_FOCI_BOTH)
        Update_ImageDecomposition();
}

void D_MAKRO_MegaFoci::Update_ImageProcessing_StepSingle_MS3_VisualizeResults(size_t step)
{
    //qDebug() << "Update_ImageProcessing_StepSingle_MS3_VisualizeResults" << "start";

    if(state_block_img_proc_update)
        return;

    if(step < STEP_MS3_VIS_REGIONS || step > STEP_MS3_VIS_REGIONS_BACKGROUND)
    {
        ERR(ER_index_out_of_range,
            "Update_ImageProcessing_StepSingle_MS3_VisualizeResults",
            "Index " + QSL_Steps_MS3[int(step)] + " does not fit to this function");
        return;
    }

    //qDebug() << step;
    //qDebug() << QSL_Steps_MS3[int(step)];

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
            "STEP_MS3_VIS_REGIONS - Math_2img_Maximum calc red channel");

        //merge to rgb image
        ERR(D_VisDat_Proc::Channels_Merge(
                &(vVD_ImgProcSteps[STEP_MS3_VIS_REGIONS]),      //out
                &(vVD_ImgProcSteps[STEP_MS3_VIS_FOCI_RFP]),     //B
                &(vVD_ImgProcSteps[STEP_MS3_VIS_FOCI_GFP]),     //G
                &VD_tmp_red),                                   //R
            "Update_ImageProcessing_StepSingle_MS3_VisualizeResults",
            "STEP_MS3_VIS_REGIONS - Channels_Merge Nuclei and foci area as color");
    }
        break;

    case STEP_MS3_VIS_REGIONS_BACKGROUND:
    {
        ERR(D_VisDat_Proc::OverlayOverwrite(
                &(vVD_ImgProcSteps[STEP_MS3_VIS_REGIONS_BACKGROUND]),
                &(vVD_ImgProcSteps[STEP_MS3_VIS_PAGES_AS_COLOR_ALL]),
                &(vVD_ImgProcSteps[STEP_MS3_VIS_REGIONS]),
                ui->doubleSpinBox_MS3_ImgProc_Vis_Intensity_Overlay->value() / 100.0,
                ui->doubleSpinBox_MS3_ImgProc_Vis_Intensity_Background->value() / 100.0),
            "Update_ImageProcessing_StepSingle_MS3_VisualizeResults",
            "STEP_MS3_VIS_REGIONS_BACKGROUND - OverlayOverwrite");
    }
        break;

        /*
    case STEP_MS3_VIS_REGIONS_FOCI_COUNT:
    {
        //qDebug() << "STEP_MS3_VIS_REGIONS_FOCI_COUNT" << "start";
        if(!state_image_decomposed)
        {
            //qDebug() << "STEP_MS3_VIS_REGIONS_FOCI_COUNT" << "no decomp";
            ERR(ER_other, "Update_ImageProcessing_StepSingle", "STEP_MS3_VIS_REGIONS_FOCI_COUNT tried to acces unsuccesfull image decomp");
            vVD_ImgProcSteps[STEP_MS3_VIS_REGIONS_FOCI_COUNT] = vVD_ImgProcSteps[STEP_MS3_VIS_REGIONS_BACKGROUND];
            return;
        }

        //get pos in dataset
        //qDebug() << "STEP_MS3_VIS_REGIONS_FOCI_COUNT" << "get pos";
        int pos_x = ui->spinBox_Viewport_X->value();
        int pos_y = ui->spinBox_Viewport_Y->value();
        int pos_t = ui->spinBox_Viewport_T->value();

        //get foci counts as QStringList
        //qDebug() << "STEP_MS3_VIS_REGIONS_FOCI_COUNT" << "get labels";
        QStringList QSL_LabelTexts = QStringList();
        vvvImageDecomp_TYX[pos_t][pos_y][pos_x].get_FociCount_append(&QSL_LabelTexts);

        //geometric moisaik offset in pixels and scale
        Point MosaikOffset_Coordinates(
                    int(pos_x * (dataset_dim_img_x - ui->spinBox_ImgProc_Stitch_Overlap_x->value())),
                    int(pos_y * (dataset_dim_img_y - ui->spinBox_ImgProc_Stitch_Overlap_y->value())));

        //qDebug() << vvvImageDecomp_TYX[pos_t][pos_y][pos_x].get_nuclei_contours(1, MosaikOffset_Coordinates).size();
        //qDebug() << vvvImageDecomp_TYX[pos_t][pos_y][pos_x].get_nuclei_centers(1, MosaikOffset_Coordinates).size();
        //qDebug() << QSL_LabelTexts.size();

        //draw contours with texts
        int err = D_VisDat_Proc::Draw_ContourText(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    &(vVD_ImgProcSteps[STEP_MS3_VIS_REGIONS_FOCI_COUNT]),
                    &(vVD_ImgProcSteps[STEP_MS3_VIS_REGIONS_BACKGROUND]),
                    vvvImageDecomp_TYX[pos_t][pos_y][pos_x].get_nuclei_contours(1, MosaikOffset_Coordinates),
                    QSL_LabelTexts,
                    vvvImageDecomp_TYX[pos_t][pos_y][pos_x].get_nuclei_centers(1, MosaikOffset_Coordinates),
                    2,
                    2,
                    1,
                    255);
        ERR(err, "Update_ImageProcessing_StepSingle_MS3_VisualizeResults", "STEP_MS3_VIS_REGIONS_FOCI_COUNT - put numbers on image");
        if(err != ER_okay)
        {
            qDebug() << "STEP_MS3_VIS_REGIONS_FOCI_COUNT" << "failes";
            return;
        }

        //qDebug() << "STEP_MS3_VIS_REGIONS_FOCI_COUNT" << "finish";
    }
        break;
        */

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

    ///get position in dataset
    int pos_x = ui->spinBox_Viewport_X->value();
    int pos_y = ui->spinBox_Viewport_Y->value();
    int pos_t = ui->spinBox_Viewport_T->value();

    ///geometric moisaik offset in pixels
    Point MosaikOffset_Coordinates(
                pos_x * (dataset_dim_img_x - ui->spinBox_ImgProc_Stitch_Overlap_x->value()),
                pos_y * (dataset_dim_img_y - ui->spinBox_ImgProc_Stitch_Overlap_y->value()));
    Point MosaikOffset_Grid(pos_x, pos_y);

    ///Proc different, dependend on major mode
    if(mode_major_current == MODE_MAJOR_1_AUTO_DETECTION)
    {
        ///vector of foci segmentation images indices
        vector<size_t> vIndices_FociBinary(FOCI_NUMBER_OF);
        vIndices_FociBinary[FOCI_GFP]   = STEP_FOC_GFP_SELECT_AREA;
        vIndices_FociBinary[FOCI_RFP]   = STEP_FOC_RFP_SELECT_AREA;
        vIndices_FociBinary[FOCI_BOTH]  = STEP_FOC_BOTH_SELECT_AREA;

        ///list of value image indices (GFP and RFP)
        vector<size_t> vIndices_Values(3);
        vIndices_Values[0] = STEP_PCK_OTHER;
        vIndices_Values[1] = STEP_PCK_GFP;
        vIndices_Values[2] = STEP_PCK_RFP;

        ///calculate image decomposition to bio info format
        StatusSet("Nuclei image decomposition");
        int err = vvvImageDecomp_TYX[pos_t][pos_y][pos_x].calc_NucleiDecomposition(
                    &vVD_ImgProcSteps,
                    STEP_NUC_BOTH_SEG3_BINARY_SEGMENTS_USED,
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
                    err,
                    "Update_ImageDecomposition",
                    "ImageDecomp.calc_NucleiDecomposition");
        if(err != ER_okay)
            return;
    }
    else if(mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
    {
        ///vector of foci segmentation images indices
        vector<size_t> vIndices_FociBinary(FOCI_NUMBER_OF);
        vIndices_FociBinary[FOCI_GFP]   = STEP_MS3_VIS_FOCI_GFP;
        vIndices_FociBinary[FOCI_RFP]   = STEP_MS3_VIS_FOCI_RFP;
        vIndices_FociBinary[FOCI_BOTH]  = STEP_MS3_VIS_FOCI_BOTH;

        ///list of value image indices (GFP and RFP)
        vector<size_t> vIndices_Values(3);
        vIndices_Values[0] = STEP_MS3_PCK_OTHER;
        vIndices_Values[1] = STEP_MS3_PCK_GFP;
        vIndices_Values[2] = STEP_MS3_PCK_RFP;

        ///calculate image decomposition to bio info format
        StatusSet("Nuclei image decomposition");

        ///independed nuclei image decompositions to be merged afterwards (1 decomp per nucleus to avoid overlapping errors)
        size_t n_nuc = vVD_ImgProcSteps[STEP_MS3_VIS_NUCLEI_FILLED_STACK].Dim().size_S();
        vector<D_Bio_NucleusImage> v_NucImgs_ToBeMergedLater(n_nuc);

        ///adapt ui
        int proc_step_shown_before = ui->comboBox_MS3_ImgProc_StepShow->currentIndex();
        if(state_stack_processing)
            ui->comboBox_MS3_ImgProc_StepShow->setCurrentIndex(STEP_MS3_VIS_NUCLEI_FILLED_STACK);
        ui->spinBox_Viewport_S->setMaximum(n_nuc - 1);

        ///loop nuclei (in stack dim) and make independed decompositions to be merged afterwards
        //qDebug() << "D_MAKRO_MegaFoci::Update_ImageDecomposition" << "loop nuclei";
        for(size_t nuc = 0; nuc < n_nuc; nuc++)
        {
            if(state_stack_processing)
                ui->spinBox_Viewport_S->setValue(nuc);

            ///put selected nucleus in a container fitting to the functions parameters list (a bit unelegant, but fastes solution to get)
            //qDebug() << "Pick nucleus" << nuc;
            vector<int> vPosPick(c_DIM_NUMBER_OF, -1);
            vPosPick[c_DIM_S] = nuc;
            int err = D_VisDat_Proc::Dim_Pick(
                        &(vVD_ImgProcSteps[STEP_MS3_VIS_NUCLEI_FILLED_PICKED]),
                        &(vVD_ImgProcSteps[STEP_MS3_VIS_NUCLEI_FILLED_STACK]),
                        vPosPick);

            ///do the decomp of the selected nuc
            //qDebug() << "calc decomp";
            err = v_NucImgs_ToBeMergedLater[nuc].calc_NucleiDecomposition(
                        &vVD_ImgProcSteps,
                        STEP_MS3_VIS_NUCLEI_FILLED_PICKED,
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
                        err,
                        "Update_ImageDecomposition",
                        "ImageDecomp.calc_NucleiDecomposition");
            if(err != ER_okay)
                return;
        }

        ///adapt ui
        if(state_stack_processing)
            ui->comboBox_MS3_ImgProc_StepShow->setCurrentIndex(proc_step_shown_before);

        ///merge nuclei decomps
        //qDebug() << "merge decomps";
        vvvImageDecomp_TYX[pos_t][pos_y][pos_x] = D_Bio_NucleusImage(
                    v_NucImgs_ToBeMergedLater, MosaikOffset_Coordinates,
                    MosaikOffset_Grid,
                    ui->spinBox_Viewport_T->value());
    }
    else
        return;

    ///remember current pos as calced
    //qDebug() << "save as demcoped";
    vvvImageDecompCalced_TYX[pos_t][pos_y][pos_x] = static_cast<int>(true);
    state_image_decomposed = true;

    ///remove duplicates
    //qDebug() << "remove duplicates";
    if(mode_major_current == MODE_MAJOR_1_AUTO_DETECTION || mode_major_current == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
    {
        //valid neighbor images
        vector<D_Bio_NucleusImage> vNeighborNucImg;
        if(pos_x > 0             )  vNeighborNucImg.push_back(vvvImageDecomp_TYX[pos_t][pos_y    ][pos_x - 1]);
        if(             pos_y > 0)  vNeighborNucImg.push_back(vvvImageDecomp_TYX[pos_t][pos_y - 1][pos_x    ]);
        if(pos_x > 0 && pos_y > 0)  vNeighborNucImg.push_back(vvvImageDecomp_TYX[pos_t][pos_y - 1][pos_x - 1]);

        //relative area overlap needed to trigger remove
        double rel_overlap_thresh = mode_major_current == MODE_MAJOR_1_AUTO_DETECTION ? ui->doubleSpinBox_MS1_ImgProc_DuplicateRelThres->value() / 100.0 : ui->doubleSpinBox_MS3_ImgProc_DuplicateRelThres->value() / 100.0;

        //remove nuclei that were detected in left/top/topleft image previously
        vvvImageDecomp_TYX[pos_t][pos_y][pos_x].remove_nuclei_dulicates(vNeighborNucImg, rel_overlap_thresh);
    }

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

    Populate_CB_Single(ui->comboBox_ImgProc_StepShow,                       QSL_Steps,              STEP_VIS_REGIONS_BACKGROUND_NUCLEI_USED);

    Populate_CB_Single(ui->comboBox_ImgProc_ProjectZ_Stat,                  QSL_StatList,           c_STAT_QUANTIL_95);
    Populate_CB_Single(ui->comboBox_ImgProc_Seg0A_IgnoreDirt_Stat,          QSL_StatList,           c_STAT_QUANTIL_95);
    Populate_CB_Single(ui->comboBox_ImgProc_Seg0B_IgnoreDirt_Stat,          QSL_StatList,           c_STAT_QUANTIL_95);

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

    //load params if existent
    Params_Load_CurrentDir();

    //update proc and image
    //StatusSet("Now updating ImgProc for the 1st time");
    //Update_ImageProcessing_CurrentImage();
    state_first_proc_on_start = false;

    //return
    return true;
}

bool D_MAKRO_MegaFoci::Params_Load_CurrentDir()
{
    if(FIL_ImagesYXT.empty())
        return false;

    if(!state_dataset_img_list_loaded)
        return false;

    QString QS_Mandatory = "Parameters_" + QString::number(mode_major_current);

    QDir DIR_ImageDir = FIL_ImagesYXT.first().dir();

    QFileInfoList FIL_InImgDir = DIR_ImageDir.entryInfoList();

    for(int i = 0; i < FIL_InImgDir.size(); i++)
        if(FIL_InImgDir[i].suffix() == "csv" || FIL_InImgDir[i].suffix() == "CSV")
            if(FIL_InImgDir[i].baseName().contains(QS_Mandatory))
                if(Params_Load(FIL_InImgDir[i].absoluteFilePath()))
                    return true;

    return false;
}

bool D_MAKRO_MegaFoci::Params_Load()
{
    QString QS_Mandatory = "Parameters_" + QString::number(mode_major_current);

    QString QS_LoadPath = QFileDialog::getOpenFileName(this,
                                                       tr("Load param file"),
                                                       pStore->dir_M_dsDNA()->path() + "/" + QS_Mandatory + "_blablabla.csv",
                                                       tr("csv-file (*.csv)"));
    if(QS_LoadPath.isEmpty())
        return false;

    if(!QFileInfo(QS_LoadPath).exists())
        return false;

    if(!QFileInfo(QS_LoadPath).baseName().contains(QS_Mandatory))
    {
        ERR(
                    ER_type_missmatch,
                    "Params_Load",
                    "Load File must contain '" + QS_Mandatory + "' in its base name and it does not.\n" + QS_LoadPath);
        return false;
    }

    return Params_Load(QS_LoadPath);
}

bool D_MAKRO_MegaFoci::Params_Load(QString QS_FileName)
{
    QString QS_Mandatory = "Parameters_" + QString::number(mode_major_current);

    if(!QFileInfo(QS_FileName).exists())
        return false;

    pStore->dir_M_dsDNA()->setPath(QS_FileName);

    state_block_img_proc_update = true;

    ifstream is_param;
    is_param.open(QS_FileName.toStdString());

    string st_line;

    while(getline(is_param, st_line))
    {
        QString QS_Line = QString::fromStdString(st_line);
        //qDebug() << QS_Line << "---------------------------------";
        QStringList QSL_Blocks = QS_Line.split(",");
        if(QSL_Blocks.size() == 3) //index, value, name
        {
            //qDebug() << "3 blocks";
            bool ok;
            int param_index = QSL_Blocks[0].toInt(&ok);
            if(ok)
            {
                double param_value = QSL_Blocks[1].toDouble(&ok);
                if(ok)
                {
                    switch (mode_major_current)
                    {

                    case MODE_MAJOR_1_AUTO_DETECTION:
                    {

                        switch (param_index)
                        {
                        case MS1_PARAM_PRE5_BLUR_SIZE:              ui->spinBox_ImgProc_Pre_Blur_Size->setValue(int(param_value));                          break;
                        case MS1_PARAM_PRE5_BLUR_SIGMA:             ui->doubleSpinBox_ImgProc_Pre_Blur_Sigma->setValue(param_value);                        break;
                        case MS1_PARAM_PRE6_STAT:                   ui->comboBox_ImgProc_ProjectZ_Stat->setCurrentIndex(int(param_value));                  break;

                        case MS1_PARAM_VIS0_NUC_MIN:                ui->spinBox_ImgProc_Vis_Other_Min->setValue(int(param_value));                          break;
                        case MS1_PARAM_VIS0_NUC_MAX:                ui->spinBox_ImgProc_Vis_Other_Max->setValue(int(param_value));                          break;
                        case MS1_PARAM_VIS0_NUC_GAMMA:              ui->doubleSpinBox_ImgProc_Vis_Other_Gamma->setValue(param_value);                       break;
                        case MS1_PARAM_VIS1_GFP_MIN:                ui->spinBox_ImgProc_Vis_GFP_Min->setValue(int(param_value));                            break;
                        case MS1_PARAM_VIS1_GFP_MAX:                ui->spinBox_ImgProc_Vis_GFP_Max->setValue(int(param_value));                            break;
                        case MS1_PARAM_VIS1_GFP_GAMMA:              ui->doubleSpinBox_ImgProc_Vis_GFP_Gamma->setValue(param_value);                         break;
                        case MS1_PARAM_VIS2_RFP_MIN:                ui->spinBox_ImgProc_Vis_RFP_Min->setValue(int(param_value));                            break;
                        case MS1_PARAM_VIS2_RFP_MAX:                ui->spinBox_ImgProc_Vis_RFP_Max->setValue(int(param_value));                            break;
                        case MS1_PARAM_VIS2_RFP_GAMMA:              ui->doubleSpinBox_ImgProc_Vis_RFP_Gamma->setValue(param_value);                         break;

                        case MS1_PARAM_NUC0_IN_USE:                 ui->groupBox_Seg0A_OTHER->setChecked(bool(param_value));                                break;
                        case MS1_PARAM_NUC0_BLUR_SIZE:              ui->doubleSpinBox_ImgProc_Seg0A_Blur_GaussSize->setValue(param_value);                  break;
                        case MS1_PARAM_NUC0_BLUR_SIGMA:             ui->doubleSpinBox_ImgProc_Seg0A_Blur_GaussSize->setValue(param_value);                  break;
                        case MS1_PARAM_NUC1_QUANTIL:                ui->doubleSpinBox_ImgProc_Seg0A_BaseBin_Quantil->setValue(param_value);                 break;
                        case MS1_PARAM_NUC1_RADIUS:                 ui->doubleSpinBox_ImgProc_Seg0A_BaseBin_FilterRadius->setValue(param_value);            break;
                        case MS1_PARAM_NUC3_THRES_INDICATOR:        ui->doubleSpinBox_ImgProc_Seg0A_BaseBin_ThresIndicator->setValue(param_value);          break;
                        case MS1_PARAM_NUC4_THRES_HYSTERESIS:       ui->doubleSpinBox_ImgProc_Seg0A_BaseBin_ThresHysteresis->setValue(param_value);         break;
                        case MS1_PARAM_NUC6_CLOSE_SIZE:             ui->spinBox_ImgProc_Seg0A_ClosingSize->setValue(int(param_value));                      break;
                        case MS1_PARAM_NUC8_STAT:                   ui->comboBox_ImgProc_Seg0A_IgnoreDirt_Stat->setCurrentIndex(int(param_value));          break;
                        case MS1_PARAM_NUC8_THRESH_DIRT:            ui->doubleSpinBox_ImgProc_Seg0A_IgnoreDirt_Thres->setValue(param_value);                break;

                        case MS1_PARAM_NUC9_IN_USE:                 ui->groupBox_Seg0B_GFP->setChecked(bool(param_value));                                  break;
                        case MS1_PARAM_NUC9_BLUR_SIZE:              ui->doubleSpinBox_ImgProc_Seg0B_Blur_GaussSize->setValue(param_value);                  break;
                        case MS1_PARAM_NUC9_BLUR_SIGMA:             ui->doubleSpinBox_ImgProc_Seg0B_Blur_GaussSigma->setValue(param_value);                 break;
                        case MS1_PARAM_NUC10_QUANTIL:               ui->doubleSpinBox_ImgProc_Seg0B_BaseBin_Quantil->setValue(param_value);                 break;
                        case MS1_PARAM_NUC10_RADIUS:                ui->doubleSpinBox_ImgProc_Seg0B_BaseBin_FilterRadius->setValue(param_value);            break;
                        case MS1_PARAM_NUC12_THRES_INDICATOR:       ui->doubleSpinBox_ImgProc_Seg0B_BaseBin_ThresIndicator->setValue(param_value);          break;
                        case MS1_PARAM_NUC13_THRES_HYSTERESIS:      ui->doubleSpinBox_ImgProc_Seg0B_BaseBin_ThresHysteresis->setValue(param_value);         break;
                        case MS1_PARAM_NUC15_CLOSE_SIZE:            ui->spinBox_ImgProc_Seg0B_ClosingSize->setValue(int(param_value));                      break;
                        case MS1_PARAM_NUC17_STAT:                  ui->comboBox_ImgProc_Seg0B_IgnoreDirt_Stat->setCurrentIndex(int(param_value));          break;
                        case MS1_PARAM_NUC17_THRESH_DIRT:           ui->doubleSpinBox_ImgProc_Seg0B_IgnoreDirt_Thres->setValue(param_value);                break;

                        case MS1_PARAM_NUC19_CLOSE_SIZE:            ui->spinBox_ImgProc_Seg0_CloseGaps_Size->setValue(int(param_value));                    break;
                        case MS1_PARAM_NUC21_AREA_MIN:              ui->doubleSpinBox_ImgProc_Seg0_GetSmall_Area_Min->setValue(param_value);                break;
                        case MS1_PARAM_NUC21_AREA_MAX:              ui->doubleSpinBox_ImgProc_Seg0_GetSmall_Area_Max->setValue(param_value);                break;
                        case MS1_PARAM_NUC22_CLOSE_SIZE:            ui->spinBox_ImgProc_Seg0_CloseGaps_Size->setValue(int(param_value));                    break;
                        case MS1_PARAM_NUC23_AREA_MIN:              ui->doubleSpinBox_ImgProc_Seg0_Area_Min->setValue(param_value);                         break;
                        case MS1_PARAM_NUC23_AREA_MAX:              ui->doubleSpinBox_ImgProc_Seg0_Area_Max->setValue(param_value);                         break;

                        case MS1_PARAM_NUC25_DISTANCE:              ui->doubleSpinBox_ImgProc_Seg1_DistThresh->setValue(param_value);                       break;
                        case MS1_PARAM_NUC26_OPEN_SIZE:             ui->spinBox_ImgProc_Seg1_OpenSeeds->setValue(int(param_value));                         break;

                        case MS1_PARAM_NUC30_DISTANCE:              ui->doubleSpinBox_ImgProc_Seg2_DistThresh->setValue(param_value);                       break;
                        case MS1_PARAM_NUC31_OPEN_SIZE:             ui->spinBox_ImgProc_Seg2_OpenSeeds->setValue(int(param_value));                         break;
                        case MS1_PARAM_NUC33_AREA_MIN:              ui->doubleSpinBox_ImgProc_Seg2_Area_Min->setValue(param_value);                         break;
                        case MS1_PARAM_NUC33_AREA_MAX:              ui->doubleSpinBox_ImgProc_Seg2_Area_Max->setValue(param_value);                         break;

                        case MS1_PARAM_NUC40_OPEN_SIZE:             ui->spinBox_ImgProc_Seg3_Open->setValue(int(param_value));                              break;

                        case MS1_PARAM_FOCGFP0_RADIUS:              ui->spinBox_ImgProc_Foc_GFP_BlurMedianSize->setValue(int(param_value));                 break;
                        case MS1_PARAM_FOCGFP1_SIZE:                ui->spinBox_ImgProc_Foc_GFP_BinarySize->setValue(int(param_value));                     break;
                        case MS1_PARAM_FOCGFP1_SIGMA:               ui->doubleSpinBox_ImgProc_Foc_GFP_BinarySigma->setValue(param_value);                   break;
                        case MS1_PARAM_FOCGFP1_SCALE:               ui->doubleSpinBox_ImgProc_Foc_GFP_BinaryScale->setValue(param_value);                   break;
                        case MS1_PARAM_FOCGFP1_OFFSET:              ui->doubleSpinBox_ImgProc_Foc_GFP_BinaryOffset->setValue(param_value);                  break;
                        case MS1_PARAM_FOCGFP3_AREA_MIN:            ui->doubleSpinBox_ImgProc_Foc_GFP_AreaMin->setValue(param_value);                       break;
                        case MS1_PARAM_FOCGFP3_AREA_MAX:            ui->doubleSpinBox_ImgProc_Foc_GFP_AreaMax->setValue(param_value);                       break;

                        case MS1_PARAM_FOCRFP0_RADIUS:              ui->spinBox_ImgProc_Foc_RFP_BlurMedianSize->setValue(int(param_value));                 break;
                        case MS1_PARAM_FOCRFP1_SIZE:                ui->spinBox_ImgProc_Foc_RFP_BinarySize->setValue(int(param_value));                     break;
                        case MS1_PARAM_FOCRFP1_SIGMA:               ui->doubleSpinBox_ImgProc_Foc_RFP_BinarySigma->setValue(param_value);                   break;
                        case MS1_PARAM_FOCRFP1_SCALE:               ui->doubleSpinBox_ImgProc_Foc_RFP_BinaryScale->setValue(param_value);                   break;
                        case MS1_PARAM_FOCRFP1_OFFSET:              ui->doubleSpinBox_ImgProc_Foc_RFP_BinaryOffset->setValue(param_value);                  break;
                        case MS1_PARAM_FOCRFP3_AREA_MIN:            ui->doubleSpinBox_ImgProc_Foc_RFP_AreaMin->setValue(param_value);                       break;
                        case MS1_PARAM_FOCRFP3_AREA_MAX:            ui->doubleSpinBox_ImgProc_Foc_RFP_AreaMax->setValue(param_value);                       break;

                        case MS1_PARAM_FOCBOTH1_AREA_MIN:           ui->doubleSpinBox_ImgProc_Foc_Both_AreaMin->setValue(param_value);                      break;
                        case MS1_PARAM_FOCBOTH1_AREA_MAX:           ui->doubleSpinBox_ImgProc_Foc_Both_AreaMax->setValue(param_value);                      break;

                        case MS1_PARAM_VIS8_INTENSITY_OVERLAY:      ui->doubleSpinBox_ImgProc_Vis_Intensity_Overlay->setValue(param_value);                 break;
                        case MS1_PARAM_VIS8_INTENSITY_BACKGROUND:   ui->doubleSpinBox_ImgProc_Vis_Intensity_Background->setValue(param_value);              break;

                        case MS1_PARAM_OTHER_DUPLICATE_OVERLAP:     ui->doubleSpinBox_MS1_ImgProc_DuplicateRelThres->setValue(param_value);                 break;

                        default:                                                                                                                            break;
                        }
                    }
                    break;

                    case MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI:
                    {
                        switch (param_index)
                        {
                        case MS3_PARAM_PRE5_BLUR_SIZE:              ui->spinBox_MS3_ImgProc_Pre_Blur_Size->setValue(int(param_value));                          break;
                        case MS3_PARAM_PRE5_BLUR_SIGMA:             ui->doubleSpinBox_MS3_ImgProc_Pre_Blur_Sigma->setValue(param_value);                        break;
                        case MS3_PARAM_PRE6_STAT:                   ui->comboBox_MS3_ImgProc_ProjectZ_Stat->setCurrentIndex(int(param_value));                  break;

                        case MS3_PARAM_VIS0_NUC_MIN:                ui->spinBox_MS3_ImgProc_Vis_Other_Min->setValue(int(param_value));                          break;
                        case MS3_PARAM_VIS0_NUC_MAX:                ui->spinBox_MS3_ImgProc_Vis_Other_Max->setValue(int(param_value));                          break;
                        case MS3_PARAM_VIS0_NUC_GAMMA:              ui->doubleSpinBox_MS3_ImgProc_Vis_Other_Gamma->setValue(param_value);                       break;
                        case MS3_PARAM_VIS1_GFP_MIN:                ui->spinBox_MS3_ImgProc_Vis_GFP_Min->setValue(int(param_value));                            break;
                        case MS3_PARAM_VIS1_GFP_MAX:                ui->spinBox_MS3_ImgProc_Vis_GFP_Max->setValue(int(param_value));                            break;
                        case MS3_PARAM_VIS1_GFP_GAMMA:              ui->doubleSpinBox_MS3_ImgProc_Vis_GFP_Gamma->setValue(param_value);                         break;
                        case MS3_PARAM_VIS2_RFP_MIN:                ui->spinBox_MS3_ImgProc_Vis_RFP_Min->setValue(int(param_value));                            break;
                        case MS3_PARAM_VIS2_RFP_MAX:                ui->spinBox_MS3_ImgProc_Vis_RFP_Max->setValue(int(param_value));                            break;
                        case MS3_PARAM_VIS2_RFP_GAMMA:              ui->doubleSpinBox_MS3_ImgProc_Vis_RFP_Gamma->setValue(param_value);                         break;

                        case MS1_PARAM_VIS8_INTENSITY_OVERLAY:      ui->doubleSpinBox_MS3_ImgProc_Vis_Intensity_Overlay->setValue(param_value);                 break;
                        case MS1_PARAM_VIS8_INTENSITY_BACKGROUND:   ui->doubleSpinBox_MS3_ImgProc_Vis_Intensity_Background->setValue(param_value);              break;

                        case MS1_PARAM_OTHER_DUPLICATE_OVERLAP:     ui->doubleSpinBox_MS3_ImgProc_DuplicateRelThres->setValue(param_value);                     break;

                        default:                                                                                                                                break;
                        }
                    }
                    break;

                    default:
                        is_param.close();
                        state_block_img_proc_update = false;
                        return false;
                    }
                }
            }
        }
    }

    is_param.close();

    state_block_img_proc_update = false;
    Update_ImageProcessing_StepFrom(0);
    return true;
}

void D_MAKRO_MegaFoci::Params_Save()
{
    QString QS_Mandatory = "Parameters_" + QString::number(mode_major_current);

    QString QS_SavePath = QFileDialog::getSaveFileName(this,
                                                       "Save param file (must contain '" + QS_Mandatory + "' to be reloaded automatically)",
                                                       pStore->dir_M_MegaFoci_Images()->path() + "/" + QS_Mandatory + " " + QDateTime::currentDateTime().toString().replace(":", "x") + ".csv",
                                                       tr("csv-file (*.csv)"));
    if(QS_SavePath.isEmpty())
        return;

    //force to contain QS_Mandatory
    QFileInfo FI_SavePath(QS_SavePath);
    if(!FI_SavePath.baseName().contains(QS_Mandatory))
        QS_SavePath = FI_SavePath.dir().path() + "/" + QS_Mandatory + "_" + FI_SavePath.baseName() + ".csv";

    pStore->dir_M_MegaFoci_Images()->setPath(QS_SavePath);

    ofstream os_param;
    os_param.open(QS_SavePath.toStdString());

    //header
    os_param
            << "Path,"                  << QS_SavePath.toStdString() << "\n"
            << "DateTime of Analysis,"  << QDateTime::currentDateTime().toString().toStdString() << "\n"
            << "Version,"               << D_QS_Version.toStdString() << "\n"
            << "Release Date,"          << D_QS_Release.toStdString() << "\n"
            << "Major Mode,"            << QSL_ModeMajor[mode_major_current].toStdString() << "\n";

    switch (mode_major_current) {

    case MODE_MAJOR_1_AUTO_DETECTION:
    {
        //Params
        os_param
                << MS1_PARAM_PRE5_BLUR_SIZE             << "," << ui->spinBox_ImgProc_Pre_Blur_Size->value()                            << "," << QSL_MS1_Params[MS1_PARAM_PRE5_BLUR_SIZE].toStdString() << "\n"
                << MS1_PARAM_PRE5_BLUR_SIGMA            << "," << ui->doubleSpinBox_ImgProc_Pre_Blur_Sigma->value()                     << "," << QSL_MS1_Params[MS1_PARAM_PRE5_BLUR_SIGMA].toStdString() << "\n"
                << MS1_PARAM_PRE6_STAT                  << "," << ui->comboBox_ImgProc_ProjectZ_Stat->currentIndex()                    << "," << QSL_MS1_Params[MS1_PARAM_PRE6_STAT].toStdString() << "\n"

                << MS1_PARAM_VIS0_NUC_MIN               << "," << ui->spinBox_ImgProc_Vis_Other_Min->value()                            << "," << QSL_MS1_Params[MS1_PARAM_VIS0_NUC_MIN].toStdString() << "\n"
                << MS1_PARAM_VIS0_NUC_MAX               << "," << ui->spinBox_ImgProc_Vis_Other_Max->value()                            << "," << QSL_MS1_Params[MS1_PARAM_VIS0_NUC_MAX].toStdString() << "\n"
                << MS1_PARAM_VIS0_NUC_GAMMA             << "," << ui->doubleSpinBox_ImgProc_Vis_Other_Gamma->value()                    << "," << QSL_MS1_Params[MS1_PARAM_VIS0_NUC_GAMMA].toStdString() << "\n"
                << MS1_PARAM_VIS1_GFP_MIN               << "," << ui->spinBox_ImgProc_Vis_GFP_Min->value()                              << "," << QSL_MS1_Params[MS1_PARAM_VIS1_GFP_MIN].toStdString() << "\n"
                << MS1_PARAM_VIS1_GFP_MAX               << "," << ui->spinBox_ImgProc_Vis_GFP_Max->value()                              << "," << QSL_MS1_Params[MS1_PARAM_VIS1_GFP_MAX].toStdString() << "\n"
                << MS1_PARAM_VIS1_GFP_GAMMA             << "," << ui->doubleSpinBox_ImgProc_Vis_GFP_Gamma->value()                      << "," << QSL_MS1_Params[MS1_PARAM_VIS1_GFP_GAMMA].toStdString() << "\n"
                << MS1_PARAM_VIS2_RFP_MIN               << "," << ui->spinBox_ImgProc_Vis_RFP_Min->value()                              << "," << QSL_MS1_Params[MS1_PARAM_VIS2_RFP_MIN].toStdString() << "\n"
                << MS1_PARAM_VIS2_RFP_MAX               << "," << ui->spinBox_ImgProc_Vis_RFP_Max->value()                              << "," << QSL_MS1_Params[MS1_PARAM_VIS2_RFP_MAX].toStdString() << "\n"
                << MS1_PARAM_VIS2_RFP_GAMMA             << "," << ui->doubleSpinBox_ImgProc_Vis_RFP_Gamma->value()                      << "," << QSL_MS1_Params[MS1_PARAM_VIS2_RFP_GAMMA].toStdString() << "\n"

                << MS1_PARAM_NUC0_IN_USE                << "," << ui->groupBox_Seg0A_OTHER->isChecked()                                 << "," << QSL_MS1_Params[MS1_PARAM_NUC0_IN_USE].toStdString() << "\n"
                << MS1_PARAM_NUC0_BLUR_SIZE             << "," << ui->doubleSpinBox_ImgProc_Seg0A_Blur_GaussSize->value()               << "," << QSL_MS1_Params[MS1_PARAM_NUC0_BLUR_SIZE].toStdString() << "\n"
                << MS1_PARAM_NUC0_BLUR_SIGMA            << "," << ui->doubleSpinBox_ImgProc_Seg0A_Blur_GaussSize->value()               << "," << QSL_MS1_Params[MS1_PARAM_NUC0_BLUR_SIGMA].toStdString() << "\n"
                << MS1_PARAM_NUC1_QUANTIL               << "," << ui->doubleSpinBox_ImgProc_Seg0A_BaseBin_Quantil->value()              << "," << QSL_MS1_Params[MS1_PARAM_NUC1_QUANTIL].toStdString() << "\n"
                << MS1_PARAM_NUC1_RADIUS                << "," << ui->doubleSpinBox_ImgProc_Seg0A_BaseBin_FilterRadius->value()         << "," << QSL_MS1_Params[MS1_PARAM_NUC1_RADIUS].toStdString() << "\n"
                << MS1_PARAM_NUC3_THRES_INDICATOR       << "," << ui->doubleSpinBox_ImgProc_Seg0A_BaseBin_ThresIndicator->value()       << "," << QSL_MS1_Params[MS1_PARAM_NUC3_THRES_INDICATOR].toStdString() << "\n"
                << MS1_PARAM_NUC4_THRES_HYSTERESIS      << "," << ui->doubleSpinBox_ImgProc_Seg0A_BaseBin_ThresHysteresis->value()      << "," << QSL_MS1_Params[MS1_PARAM_NUC4_THRES_HYSTERESIS].toStdString() << "\n"
                << MS1_PARAM_NUC6_CLOSE_SIZE            << "," << ui->spinBox_ImgProc_Seg0A_ClosingSize->value()                        << "," << QSL_MS1_Params[MS1_PARAM_NUC6_CLOSE_SIZE].toStdString() << "\n"
                << MS1_PARAM_NUC8_STAT                  << "," << ui->comboBox_ImgProc_Seg0A_IgnoreDirt_Stat->currentIndex()            << "," << QSL_MS1_Params[MS1_PARAM_NUC8_STAT].toStdString() << "\n"
                << MS1_PARAM_NUC8_THRESH_DIRT           << "," << ui->doubleSpinBox_ImgProc_Seg0A_IgnoreDirt_Thres->value()             << "," << QSL_MS1_Params[MS1_PARAM_NUC8_THRESH_DIRT].toStdString() << "\n"

                << MS1_PARAM_NUC9_IN_USE                << "," << ui->groupBox_Seg0B_GFP->isChecked()                                   << "," << QSL_MS1_Params[MS1_PARAM_NUC9_IN_USE].toStdString() << "\n"
                << MS1_PARAM_NUC9_BLUR_SIZE             << "," << ui->doubleSpinBox_ImgProc_Seg0B_Blur_GaussSize->value()               << "," << QSL_MS1_Params[MS1_PARAM_NUC9_BLUR_SIZE].toStdString() << "\n"
                << MS1_PARAM_NUC9_BLUR_SIGMA            << "," << ui->doubleSpinBox_ImgProc_Seg0B_Blur_GaussSigma->value()              << "," << QSL_MS1_Params[MS1_PARAM_NUC9_BLUR_SIGMA].toStdString() << "\n"
                << MS1_PARAM_NUC10_QUANTIL              << "," << ui->doubleSpinBox_ImgProc_Seg0B_BaseBin_Quantil->value()              << "," << QSL_MS1_Params[MS1_PARAM_NUC10_QUANTIL].toStdString() << "\n"
                << MS1_PARAM_NUC10_RADIUS               << "," << ui->doubleSpinBox_ImgProc_Seg0B_BaseBin_FilterRadius->value()         << "," << QSL_MS1_Params[MS1_PARAM_NUC10_RADIUS].toStdString() << "\n"
                << MS1_PARAM_NUC12_THRES_INDICATOR      << "," << ui->doubleSpinBox_ImgProc_Seg0B_BaseBin_ThresIndicator->value()       << "," << QSL_MS1_Params[MS1_PARAM_NUC12_THRES_INDICATOR].toStdString() << "\n"
                << MS1_PARAM_NUC13_THRES_HYSTERESIS     << "," << ui->doubleSpinBox_ImgProc_Seg0B_BaseBin_ThresHysteresis->value()      << "," << QSL_MS1_Params[MS1_PARAM_NUC13_THRES_HYSTERESIS].toStdString() << "\n"
                << MS1_PARAM_NUC15_CLOSE_SIZE           << "," << ui->spinBox_ImgProc_Seg0B_ClosingSize->value()                        << "," << QSL_MS1_Params[MS1_PARAM_NUC15_CLOSE_SIZE].toStdString() << "\n"
                << MS1_PARAM_NUC17_STAT                 << "," << ui->comboBox_ImgProc_Seg0B_IgnoreDirt_Stat->currentIndex()            << "," << QSL_MS1_Params[MS1_PARAM_NUC17_STAT].toStdString() << "\n"
                << MS1_PARAM_NUC17_THRESH_DIRT          << "," << ui->doubleSpinBox_ImgProc_Seg0B_IgnoreDirt_Thres->value()             << "," << QSL_MS1_Params[MS1_PARAM_NUC17_THRESH_DIRT].toStdString() << "\n"

                << MS1_PARAM_NUC19_CLOSE_SIZE           << "," << ui->spinBox_ImgProc_Seg0_CloseGaps_Size->value()                      << "," << QSL_MS1_Params[MS1_PARAM_NUC19_CLOSE_SIZE].toStdString() << "\n"
                << MS1_PARAM_NUC21_AREA_MIN             << "," << ui->doubleSpinBox_ImgProc_Seg0_GetSmall_Area_Min->value()             << "," << QSL_MS1_Params[MS1_PARAM_NUC21_AREA_MIN].toStdString() << "\n"
                << MS1_PARAM_NUC21_AREA_MAX             << "," << ui->doubleSpinBox_ImgProc_Seg0_GetSmall_Area_Max->value()             << "," << QSL_MS1_Params[MS1_PARAM_NUC21_AREA_MAX].toStdString() << "\n"
                << MS1_PARAM_NUC22_CLOSE_SIZE           << "," << ui->spinBox_ImgProc_Seg0_CloseGaps_Size->value()                      << "," << QSL_MS1_Params[MS1_PARAM_NUC22_CLOSE_SIZE].toStdString() << "\n"
                << MS1_PARAM_NUC23_AREA_MIN             << "," << ui->doubleSpinBox_ImgProc_Seg0_Area_Min->value()                      << "," << QSL_MS1_Params[MS1_PARAM_NUC23_AREA_MIN].toStdString() << "\n"
                << MS1_PARAM_NUC23_AREA_MAX             << "," << ui->doubleSpinBox_ImgProc_Seg0_Area_Max->value()                      << "," << QSL_MS1_Params[MS1_PARAM_NUC23_AREA_MAX].toStdString() << "\n"

                << MS1_PARAM_NUC25_DISTANCE             << "," << ui->doubleSpinBox_ImgProc_Seg1_DistThresh->value()                    << "," << QSL_MS1_Params[MS1_PARAM_NUC25_DISTANCE].toStdString() << "\n"
                << MS1_PARAM_NUC26_OPEN_SIZE            << "," << ui->spinBox_ImgProc_Seg1_OpenSeeds->value()                           << "," << QSL_MS1_Params[MS1_PARAM_NUC26_OPEN_SIZE].toStdString() << "\n"

                << MS1_PARAM_NUC30_DISTANCE             << "," << ui->doubleSpinBox_ImgProc_Seg2_DistThresh->value()                    << "," << QSL_MS1_Params[MS1_PARAM_NUC30_DISTANCE].toStdString() << "\n"
                << MS1_PARAM_NUC31_OPEN_SIZE            << "," << ui->spinBox_ImgProc_Seg2_OpenSeeds->value()                           << "," << QSL_MS1_Params[MS1_PARAM_NUC31_OPEN_SIZE].toStdString() << "\n"
                << MS1_PARAM_NUC33_AREA_MIN             << "," << ui->doubleSpinBox_ImgProc_Seg2_Area_Min->value()                      << "," << QSL_MS1_Params[MS1_PARAM_NUC33_AREA_MIN].toStdString() << "\n"
                << MS1_PARAM_NUC33_AREA_MAX             << "," << ui->doubleSpinBox_ImgProc_Seg2_Area_Max->value()                      << "," << QSL_MS1_Params[MS1_PARAM_NUC33_AREA_MAX].toStdString() << "\n"

                << MS1_PARAM_NUC40_OPEN_SIZE            << "," << ui->spinBox_ImgProc_Seg3_Open->value()                                << "," << QSL_MS1_Params[MS1_PARAM_NUC40_OPEN_SIZE].toStdString() << "\n"

                << MS1_PARAM_FOCGFP0_RADIUS             << "," << ui->spinBox_ImgProc_Foc_GFP_BlurMedianSize->value()                   << "," << QSL_MS1_Params[MS1_PARAM_FOCGFP0_RADIUS].toStdString() << "\n"
                << MS1_PARAM_FOCGFP1_SIZE               << "," << ui->spinBox_ImgProc_Foc_GFP_BinarySize->value()                       << "," << QSL_MS1_Params[MS1_PARAM_FOCGFP1_SIZE].toStdString() << "\n"
                << MS1_PARAM_FOCGFP1_SIGMA              << "," << ui->doubleSpinBox_ImgProc_Foc_GFP_BinarySigma->value()                << "," << QSL_MS1_Params[MS1_PARAM_FOCGFP1_SIGMA].toStdString() << "\n"
                << MS1_PARAM_FOCGFP1_SCALE              << "," << ui->doubleSpinBox_ImgProc_Foc_GFP_BinaryScale->value()                << "," << QSL_MS1_Params[MS1_PARAM_FOCGFP1_SCALE].toStdString() << "\n"
                << MS1_PARAM_FOCGFP1_OFFSET             << "," << ui->doubleSpinBox_ImgProc_Foc_GFP_BinaryOffset->value()               << "," << QSL_MS1_Params[MS1_PARAM_FOCGFP1_OFFSET].toStdString() << "\n"
                << MS1_PARAM_FOCGFP3_AREA_MIN           << "," << ui->doubleSpinBox_ImgProc_Foc_GFP_AreaMin->value()                    << "," << QSL_MS1_Params[MS1_PARAM_FOCGFP3_AREA_MIN].toStdString() << "\n"
                << MS1_PARAM_FOCGFP3_AREA_MAX           << "," << ui->doubleSpinBox_ImgProc_Foc_GFP_AreaMax->value()                    << "," << QSL_MS1_Params[MS1_PARAM_FOCGFP3_AREA_MAX].toStdString() << "\n"

                << MS1_PARAM_FOCRFP0_RADIUS             << "," << ui->spinBox_ImgProc_Foc_RFP_BlurMedianSize->value()                   << "," << QSL_MS1_Params[MS1_PARAM_FOCRFP0_RADIUS].toStdString() << "\n"
                << MS1_PARAM_FOCRFP1_SIZE               << "," << ui->spinBox_ImgProc_Foc_RFP_BinarySize->value()                       << "," << QSL_MS1_Params[MS1_PARAM_FOCRFP1_SIZE].toStdString() << "\n"
                << MS1_PARAM_FOCRFP1_SIGMA              << "," << ui->doubleSpinBox_ImgProc_Foc_RFP_BinarySigma->value()                << "," << QSL_MS1_Params[MS1_PARAM_FOCRFP1_SIGMA].toStdString() << "\n"
                << MS1_PARAM_FOCRFP1_SCALE              << "," << ui->doubleSpinBox_ImgProc_Foc_RFP_BinaryScale->value()                << "," << QSL_MS1_Params[MS1_PARAM_FOCRFP1_SCALE].toStdString() << "\n"
                << MS1_PARAM_FOCRFP1_OFFSET             << "," << ui->doubleSpinBox_ImgProc_Foc_RFP_BinaryOffset->value()               << "," << QSL_MS1_Params[MS1_PARAM_FOCRFP1_OFFSET].toStdString() << "\n"
                << MS1_PARAM_FOCRFP3_AREA_MIN           << "," << ui->doubleSpinBox_ImgProc_Foc_RFP_AreaMin->value()                    << "," << QSL_MS1_Params[MS1_PARAM_FOCRFP3_AREA_MIN].toStdString() << "\n"
                << MS1_PARAM_FOCRFP3_AREA_MAX           << "," << ui->doubleSpinBox_ImgProc_Foc_RFP_AreaMax->value()                    << "," << QSL_MS1_Params[MS1_PARAM_FOCRFP3_AREA_MAX].toStdString() << "\n"

                << MS1_PARAM_FOCBOTH1_AREA_MIN          << "," << ui->doubleSpinBox_ImgProc_Foc_Both_AreaMin->value()                   << "," << QSL_MS1_Params[MS1_PARAM_FOCBOTH1_AREA_MIN].toStdString() << "\n"
                << MS1_PARAM_FOCBOTH1_AREA_MAX          << "," << ui->doubleSpinBox_ImgProc_Foc_Both_AreaMax->value()                   << "," << QSL_MS1_Params[MS1_PARAM_FOCBOTH1_AREA_MAX].toStdString() << "\n"

                << MS1_PARAM_VIS8_INTENSITY_OVERLAY     << "," << ui->doubleSpinBox_ImgProc_Vis_Intensity_Overlay->value()              << "," << QSL_MS1_Params[MS1_PARAM_VIS8_INTENSITY_OVERLAY].toStdString() << "\n"
                << MS1_PARAM_VIS8_INTENSITY_BACKGROUND  << "," << ui->doubleSpinBox_ImgProc_Vis_Intensity_Background->value()           << "," << QSL_MS1_Params[MS1_PARAM_VIS8_INTENSITY_BACKGROUND].toStdString() << "\n"

                << MS1_PARAM_OTHER_DUPLICATE_OVERLAP    << "," << ui->doubleSpinBox_MS1_ImgProc_DuplicateRelThres->value()              << "," << QSL_MS1_Params[MS1_PARAM_OTHER_DUPLICATE_OVERLAP].toStdString() << "\n";

        os_param.close();
    }
        break;

    case MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI:
    {
        //Params
        os_param
                << MS3_PARAM_PRE5_BLUR_SIZE             << "," << ui->spinBox_MS3_ImgProc_Pre_Blur_Size->value()                            << "," << QSL_MS3_Params[MS3_PARAM_PRE5_BLUR_SIZE].toStdString() << "\n"
                << MS3_PARAM_PRE5_BLUR_SIGMA            << "," << ui->doubleSpinBox_MS3_ImgProc_Pre_Blur_Sigma->value()                     << "," << QSL_MS3_Params[MS3_PARAM_PRE5_BLUR_SIGMA].toStdString() << "\n"
                << MS3_PARAM_PRE6_STAT                  << "," << ui->comboBox_MS3_ImgProc_ProjectZ_Stat->currentIndex()                    << "," << QSL_MS3_Params[MS3_PARAM_PRE6_STAT].toStdString() << "\n"

                << MS3_PARAM_VIS0_NUC_MIN               << "," << ui->spinBox_MS3_ImgProc_Vis_Other_Min->value()                            << "," << QSL_MS3_Params[MS3_PARAM_VIS0_NUC_MIN].toStdString() << "\n"
                << MS3_PARAM_VIS0_NUC_MAX               << "," << ui->spinBox_MS3_ImgProc_Vis_Other_Max->value()                            << "," << QSL_MS3_Params[MS3_PARAM_VIS0_NUC_MAX].toStdString() << "\n"
                << MS3_PARAM_VIS0_NUC_GAMMA             << "," << ui->doubleSpinBox_MS3_ImgProc_Vis_Other_Gamma->value()                    << "," << QSL_MS3_Params[MS3_PARAM_VIS0_NUC_GAMMA].toStdString() << "\n"
                << MS3_PARAM_VIS1_GFP_MIN               << "," << ui->spinBox_MS3_ImgProc_Vis_GFP_Min->value()                              << "," << QSL_MS3_Params[MS3_PARAM_VIS1_GFP_MIN].toStdString() << "\n"
                << MS3_PARAM_VIS1_GFP_MAX               << "," << ui->spinBox_MS3_ImgProc_Vis_GFP_Max->value()                              << "," << QSL_MS3_Params[MS3_PARAM_VIS1_GFP_MAX].toStdString() << "\n"
                << MS3_PARAM_VIS1_GFP_GAMMA             << "," << ui->doubleSpinBox_MS3_ImgProc_Vis_GFP_Gamma->value()                      << "," << QSL_MS3_Params[MS3_PARAM_VIS1_GFP_GAMMA].toStdString() << "\n"
                << MS3_PARAM_VIS2_RFP_MIN               << "," << ui->spinBox_MS3_ImgProc_Vis_RFP_Min->value()                              << "," << QSL_MS3_Params[MS3_PARAM_VIS2_RFP_MIN].toStdString() << "\n"
                << MS3_PARAM_VIS2_RFP_MAX               << "," << ui->spinBox_MS3_ImgProc_Vis_RFP_Max->value()                              << "," << QSL_MS3_Params[MS3_PARAM_VIS2_RFP_MAX].toStdString() << "\n"
                << MS3_PARAM_VIS2_RFP_GAMMA             << "," << ui->doubleSpinBox_MS3_ImgProc_Vis_RFP_Gamma->value()                      << "," << QSL_MS3_Params[MS3_PARAM_VIS2_RFP_GAMMA].toStdString() << "\n"

                << MS3_PARAM_VIS6_INTENSITY_OVERLAY     << "," << ui->doubleSpinBox_MS3_ImgProc_Vis_Intensity_Overlay->value()              << "," << QSL_MS3_Params[MS3_PARAM_VIS6_INTENSITY_OVERLAY].toStdString() << "\n"
                << MS3_PARAM_VIS6_INTENSITY_BACKGROUND  << "," << ui->doubleSpinBox_MS3_ImgProc_Vis_Intensity_Background->value()           << "," << QSL_MS3_Params[MS3_PARAM_VIS6_INTENSITY_BACKGROUND].toStdString() << "\n"

                << MS3_PARAM_OTHER_DUPLICATE_OVERLAP    << "," << ui->doubleSpinBox_MS3_ImgProc_DuplicateRelThres->value()                  << "," << QSL_MS3_Params[MS3_PARAM_OTHER_DUPLICATE_OVERLAP].toStdString() << "\n";

        os_param.close();
    }
        break;

    default:
        return;

    }
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
        StatusSet("ERROR:\n" +
                  QSL_Errors[err] + ",\n"
                  "Function: " + func + ",\n"
                  "Detail:   " + detail);
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
    int value_min_t = INT_MAX;
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
    int value_min_y = INT_MAX;
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
    int value_min_x = INT_MAX;
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
    if(i < vVD_ImgLoadBuffer.size())
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
    if((t < dataset_dim_t) && (y < dataset_dim_mosaic_y) && (x < dataset_dim_mosaic_x))
    {
        ///If in range:
        ///try loading img from buffer
        if(ImgBuffer_Read(img, ImgBuffer_Find(x, y, t)))
            return ER_okay;

        ///if img not in buffer, load it from file
        StatusSet("Load image from file");
        D_VisDat_Obj VD_ImgLoaded_ZP_asPages;
        int err = D_VisDat_Proc::Create_VD_SinglePaged(
                    &VD_ImgLoaded_ZP_asPages,
                    FIL_ImagesYXT[get_index_of_image(x, y, t)],
                    c_DIM_P,
                    c_DIM_X,
                    c_DIM_Y);
        if(err != ER_okay)
        {
            StatusSet("Create zero image (error)");
            CreateZero_Image(img);
            return err;
        }

        ///deserialise Z from combined ZP
        err = D_VisDat_Proc::Dim_Deserialise(
                    img,
                    &VD_ImgLoaded_ZP_asPages,
                    c_DIM_P,
                    c_DIM_Z,
                    dataset_dim_p_exist);
        if(err != ER_okay)
        {
            StatusSet("Create zero image (error)");
            CreateZero_Image(img);
            return err;
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

    switch (mode) {

    case MODE_MAJOR_2_MANU_CORRECT_DETECTION:       MS2_init_ui();  break;
    case MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI:    MS3_UiInit();   break;
    case MODE_MAJOR_4_AUTO_RECONSTRUCT_PEDIGREE:    MS4_UiInit();   break;
    case MODE_MAJOR_5_MANU_CORRECT_PEDIGREE:        MS5_UiInit();   break;
    case MODE_MAJOR_6_EPIC_ANALYSIS:                MS6_UiInit();   break;
    default:                                                        return;}
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
    MS2_Viewer_ToDo.set_GV(ui->graphicsView_MS2_Viewer_ToDo);
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

    //segment boxes
    v_MS2_CHB_Viewer_SegmentBox.resize(MS2_ViewersCount);
    v_MS2_CHB_Viewer_SegmentBox[0] = ui->checkBox_MS2_ViewerSettings_SegmentBox_1;
    v_MS2_CHB_Viewer_SegmentBox[1] = ui->checkBox_MS2_ViewerSettings_SegmentBox_2;
    v_MS2_CHB_Viewer_SegmentBox[2] = ui->checkBox_MS2_ViewerSettings_SegmentBox_3;
    v_MS2_CHB_Viewer_SegmentBox[3] = ui->checkBox_MS2_ViewerSettings_SegmentBox_4;

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

    MS2_Viewer_ToDo.Set_VisTrafo_ActiveBool(false);
    MS2_Viewer_ToDo.Set_VisTrafo_Mode_Trafo(c_VIS_TRAFO_LOG);
    MS2_Viewer_ToDo.Set_VisTrafo_Divisor(5);
    MS2_Viewer_ToDo.Set_VisTrafo_Center(0);

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
    connect(ui->spinBox_MS2_Viewport_T,                     SIGNAL(valueChanged(int)),          this,   SLOT(MS2_UpdateImage_ToDo_Static()));

    //highlighting frames in to do list
    connect(&MS2_Viewer_ToDo,                               SIGNAL(MouseMoved_Pos(int, int)),   this,   SLOT(MS2_UpdateImage_ToDo_Highlight(int, int)));

    //click recording
    for(size_t v = 0; v < MS2_ViewersCount; v++)
    {
        v_MS2_Viewer[0]->connect_PointRecord(v_MS2_Viewer[v]);
        connect(v_MS2_Viewer[v], SIGNAL(ClickRecordSignal_RecordedPointsCount(size_t)), this, SLOT(MS2_Draw_RecordedClicksChanged(size_t)));
    }

    //show
    MS2_UpdateImages();
    MS2_ChangeMode(MS2_MODE_DETAILED);
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

    //change state to "to process";
    MS2_Draw_SetToProcess();

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

    //change state to "to process";
    MS2_Draw_SetToProcess();

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
    return MS2_Draw_Contour(MS2_Viewer1.ClickRecord_GetPoints_Ellipse(1.0 / MS2_MosaikImageScale, MS2_ViewportOffset_NotScaled, true));
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
    double r = ui->spinBox_MS2_Tools_AllplyPoints_DrawSize->value();

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

    //change state to "to process";
    MS2_Draw_SetToProcess();

    //update ui
    MS2_DetOutBackup_UpdateUi();
    MS2_UpdateOverlays();
    MS2_UpdateImages_Editing();
    MS2_Draw_UpdateUi();

    //end click recording
    MS2_Draw_RecordingEnd();
}

void D_MAKRO_MegaFoci::MS2_Draw_SeparateObject()
{
    /*
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

    //point size
    double size = ui->spinBox_MS2_Tools_AllplyPoints_DrawSize->value();

    //get countours of circles
    vector<Point> vPoints = MS2_Viewer1.ClickRecord_GetPoints(MS2_MosaikImageScale, MS2_ViewportOffset_NotScaled);
    size_t n = vPoints.size();

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

    //change state to "to process";
    MS2_Draw_SetToProcess();

    //update ui
    MS2_DetOutBackup_UpdateUi();
    MS2_UpdateOverlays();
    MS2_UpdateImages_Editing();
    MS2_Draw_UpdateUi();

    //end click recording
    MS2_Draw_RecordingEnd();
    */
}

void D_MAKRO_MegaFoci::MS2_Draw_MergeObjects()
{

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

    //change state to "to process";
    MS2_Draw_SetToProcess();

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

    //change state to "to process";
    MS2_Draw_SetToProcess();

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

void D_MAKRO_MegaFoci::MS2_ToDo_SetFinished()
{
    return MS2_ToDo_SetFinished(
                MS2_Viewer_ToDo.MousePos_X(),
                MS2_Viewer_ToDo.MousePos_Y());
}

void D_MAKRO_MegaFoci::MS2_ToDo_SetFinished(int x, int y)
{
    if(!state_MS2_data_loaded || !state_MS2_detections_loaded)
        return;

    if(!ui->radioButton_MS2_Mode_ToDo->isChecked())
        return;

    if(!state_MS2_todo_static_img_created)
        return;

    //size
    int w = MA_MS2_ToDo_Static.cols;
    int h = MA_MS2_ToDo_Static.rows;

    if(x < 0 || x >= w || y < 0 || y >= h)
        return;

    //calc mosaik pos
    int ix = max(0, min(int(dataset_dim_mosaic_x - 1), int((x / double(w)) * dataset_dim_mosaic_x)));
    int iy = max(0, min(int(dataset_dim_mosaic_y - 1), int((y / double(h)) * dataset_dim_mosaic_y)));
    int it = ui->spinBox_MS2_Viewport_T->value();


    //time dir
    QDir DIR_Time(DIR_MS2_Out_DetectionsCorrected.path() + "/Time_" + QString::number(it));
    if(!DIR_Time.exists())
        QDir().mkdir(DIR_Time.path());
    if(!DIR_Time.exists())
        return;

    //target dir
    QDir DIR_Target(DIR_Time.path() + "/Image_T" + QString::number(it) + "_Y" + QString::number(iy) + "_X" + QString::number(ix));
    //qDebug() << "D_MAKRO_MegaFoci::MS2_ToDo_SetFinished" << DIR_Target.path();
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
    StatusSet("Viewport x=" + QString::number(ix) + "/y=" + QString::number(iy) + " kicked from to do list");

    //change state
    vv_MS2_NucImg_State_Out_mosaikXY[ix][iy] = MS2_IMG_STATE_PROCESSED;

    //update image
    MS2_UpdateImage_ToDo_Static();
    MS2_UpdateImage_Viewport();
}

void D_MAKRO_MegaFoci::MS2_ToDo_SetToBeEdited()
{
    return MS2_ToDo_SetToBeEdited(
                MS2_Viewer_ToDo.MousePos_X(),
                MS2_Viewer_ToDo.MousePos_Y());
}

void D_MAKRO_MegaFoci::MS2_ToDo_SetToBeEdited(int x, int y)
{
    if(!state_MS2_data_loaded || !state_MS2_detections_loaded)
        return;

    if(!ui->radioButton_MS2_Mode_ToDo->isChecked())
        return;

    if(!state_MS2_todo_static_img_created)
        return;

    //size
    int w = MA_MS2_ToDo_Static.cols;
    int h = MA_MS2_ToDo_Static.rows;

    if(x < 0 || x >= w || y < 0 || y >= h)
        return;

    //calc mosaik pos
    int ix = max(0, min(int(dataset_dim_mosaic_x - 1), int((x / double(w)) * dataset_dim_mosaic_x)));
    int iy = max(0, min(int(dataset_dim_mosaic_y - 1), int((y / double(h)) * dataset_dim_mosaic_y)));

    //change state
    vv_MS2_NucImg_State_Out_mosaikXY[ix][iy] = MS2_IMG_STATE_TO_PROCESS;
    StatusSet("Viewport x=" + QString::number(ix) + "/y=" + QString::number(iy) + " set on to do list");

    //update image
    MS2_UpdateImage_ToDo_Static();
    MS2_UpdateImage_Viewport();
}

void D_MAKRO_MegaFoci::MS3_UiInit()
{
    //porc steps
    Populate_CB_Single(ui->comboBox_MS3_ImgProc_StepShow, QSL_Steps_MS3, STEP_MS3_VIS_REGIONS_BACKGROUND);

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

    MS3_current_loaded_detections_T = state_MS3_detections_loaded ? int(t) : -1;

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
                &(v_MS2_MA_ChannelsOverlay_Croped[vv_MS2_COB_ViewerChannel_Overlay_viewer_bgr[img2update][0]->currentIndex()])),
            "MS2_UpdateImage",
            "D_Img_Proc::OverlayImage");

    //Box
    if(v_MS2_CHB_Viewer_SegmentBox[img2update]->isChecked())
    {
        double overlap = ui->doubleSpinBox_ImgProc_Stitch_Border->value() / 100.0;
        double rel_segment_start = 1.0 - (1.0 / (1.0 + overlap));

        int w = v_MS2_MA_Images2Show[img2update].cols;
        int h = v_MS2_MA_Images2Show[img2update].rows;

        int x1 = ui->spinBox_MS2_Viewport_X->value() == 0 ? 0 : int(w * rel_segment_start);
        int y1 = ui->spinBox_MS2_Viewport_Y->value() == 0 ? 0 : int(h * rel_segment_start);
        int x2 = w - 1;
        int y2 = h - 1;

        ERR(D_Img_Proc::Draw_Rect(
                &(v_MS2_MA_Images2Show[img2update]),
                x1,
                y1,
                x2,
                y2,
                2,
                196),
            "MS2_UpdateImage",
            "D_Img_Proc::Draw_Rect - segment box");
    }

    //draw events, if active
    if(MS2_EventList_FileSet)
    {
        //mosaic coordinates
        size_t mx = ui->spinBox_MS2_Viewport_X->value();
        size_t my = ui->spinBox_MS2_Viewport_Y->value();

        //size x/y
        int sx_full = int(v_MS2_MA_ChannelsImage_Full[0].cols * (1.0 / MS2_MosaikImageScale));
        int sy_full = int(v_MS2_MA_ChannelsImage_Full[0].rows * (1.0 / MS2_MosaikImageScale));

        //min viewport
        int vp_min_x_px = (double(mx) / double(dataset_dim_mosaic_x)) * sx_full;
        int vp_min_y_px = (double(my) / double(dataset_dim_mosaic_y)) * sy_full;

        //max viewport
        int vp_max_x_px = min(double(sx_full - 1), vp_min_x_px + (v_MS2_MA_Images2Show[img2update].cols / MS2_MosaikImageScale));
        int vp_max_y_px = min(double(sy_full - 1), vp_min_y_px + (v_MS2_MA_Images2Show[img2update].rows / MS2_MosaikImageScale));

        for(int l = MS2_EventList_CursorOffset; l < MS2_EventList_Events.size(); l++)
        {
            bool ok;
            int et = MS2_EventList_Decode_Number(l, 't', &ok);

            if(ok)
            {
                if(et == ui->spinBox_MS2_Viewport_T->value())
                {
                    int ey = MS2_EventList_Decode_Number(l, 'y', &ok);
                    if(ok)
                    {
                        int ex = MS2_EventList_Decode_Number(l, 'x', &ok);
                        if(ok)
                        {
                            int er = MS2_EventList_Decode_Number(l, 'r', &ok);
                            if(ok)
                            {
                                bool es = MS2_EventList_Decode_Status(l, &ok);
                                if(ok)
                                {
                                    //x and y in range?
                                    if(ex >= vp_min_x_px && ex <= vp_max_x_px && ey >= vp_min_y_px && ey <= vp_max_y_px)
                                    {
                                        //event is in range of displayed viewport

                                        //color
                                        QColor e_col = es ? QColor(0, 255, 255) : QColor(255, 0, 0);

                                        //px coordinates in img
                                        int ex_px_viewport = min(v_MS2_MA_Images2Show[img2update].cols - 1, max(0, int((ex - MS2_ViewportOffset_NotScaled.x) * MS2_MosaikImageScale)));
                                        int ey_px_viewport = min(v_MS2_MA_Images2Show[img2update].rows - 1, max(0, int((ey - MS2_ViewportOffset_NotScaled.y) * MS2_MosaikImageScale)));

                                        //event active
                                        bool ea = (ex == ui->spinBox_MS2_EventList_Event_X->value()) && (ey == ui->spinBox_MS2_EventList_Event_Y->value() && (er == ui->spinBox_MS2_EventList_Event_R->value()));

                                        //draw cirlce
                                        ERR(D_Img_Proc::Draw_Circle(
                                                &(v_MS2_MA_Images2Show[img2update]),
                                                ex_px_viewport, ey_px_viewport,
                                                int(er * MS2_MosaikImageScale),
                                                e_col.red(), e_col.green(), e_col.blue(),
                                                ea ? 2 : 1));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    v_MS2_Viewer[img2update]->Update_Image(&(v_MS2_MA_Images2Show[img2update]));
}

void D_MAKRO_MegaFoci::MS2_UpdateImages_Editing()
{
    for(size_t v = 0; v < MS2_ViewersCount; v++)
        MS2_UpdateImage(v);
}

void D_MAKRO_MegaFoci::MS2_UpdateImage_ToDo_Static()
{
    if(!ui->radioButton_MS2_Mode_ToDo->isChecked())
        return;

    //base image
    int err = D_Img_Proc::Merge(
                &MA_MS2_ToDo_Static,
                &(v_MS2_MA_ChannelsImage_Full[MS2_CH_IMG_RFP]),
                &(v_MS2_MA_ChannelsImage_Full[MS2_CH_IMG_GFP]),
                &(v_MS2_MA_ChannelsImage_Full[MS2_CH_IMG_DIC]));
    if(err != ER_okay)
    {
        ERR(err, "MS2_UpdateImage_ToDo", "D_Img_Proc::Merge to MA_MS2_ToDo_Static");
        return;
    }

    state_MS2_todo_static_img_created = true;

    //draw status symbols on img
    if(state_MS2_detections_loaded)
    {
        //qDebug() << "D_MAKRO_MegaFoci::MS2_UpdateImage_Viewport" << "try to draw state symbols";
        for(size_t ix = 0; ix < vv_MS2_NucImg_State_Out_mosaikXY.size(); ix++)
        {
            for(size_t iy = 0; iy < vv_MS2_NucImg_State_Out_mosaikXY[ix].size(); iy++)
            {
                //border stitching
                double overlap = ui->doubleSpinBox_ImgProc_Stitch_Border->value() / 100.0;

                //rect
                int x1 = int(max(0.0,                           (double(ix              ) / dataset_dim_mosaic_x) * MS2_MosaikImageWidth));
                int y1 = int(max(0.0,                           (double(iy              ) / dataset_dim_mosaic_y) * MS2_MosaikImageHeight));
                int x2 = int(min(MS2_MosaikImageWidth  - 1.0,   (double(ix + 1          ) / dataset_dim_mosaic_x) * MS2_MosaikImageWidth));
                int y2 = int(min(MS2_MosaikImageHeight - 1.0,   (double(iy + 1          ) / dataset_dim_mosaic_y) * MS2_MosaikImageHeight));
                int x3 = int(min(MS2_MosaikImageWidth  - 1.0,   (double(ix + 1 + overlap) / dataset_dim_mosaic_x) * MS2_MosaikImageWidth));
                int y3 = int(min(MS2_MosaikImageHeight - 1.0,   (double(iy + 1 + overlap) / dataset_dim_mosaic_y) * MS2_MosaikImageHeight));
                //qDebug() << "D_MAKRO_MegaFoci::MS2_UpdateImage_ToDo" << "draw to x1/x2/y1/y2/x3/y3" << x1 << x2 << y1 << y2 << x3 << y3;

                //select style
                bool known_state = true;
                int symbol = c_MARKER_SYMBOL_DOT;
                uchar r = 0;
                uchar g = 0;
                uchar b = 0;

                switch (vv_MS2_NucImg_State_Out_mosaikXY[ix][iy]) {
                case MS2_IMG_STATE_PROCESSED:   symbol = c_MARKER_SYMBOL_TICK;      g = 255;    break;
                case MS2_IMG_STATE_TO_PROCESS:  symbol = c_MARKER_SYMBOL_3DOTS;     b = 255;    break;
                case MS2_IMG_STATE_NOT_FOUND:   symbol = c_MARKER_SYMBOL_CROSS;     r = 255;    break;
                default:                        known_state = false;                            break;}

                if(known_state)
                {
                    if(ui->checkBox_MS2_ToDo_SegmentBorders->isChecked())
                    {
                        uchar val = 128;

                        ERR(D_Img_Proc::Draw_Line(
                                &MA_MS2_ToDo_Static,
                                x3,
                                y1,
                                x3,
                                y3,
                                2,
                                val, val, val),
                            "MS2_UpdateImage_ToDo",
                            "D_Img_Proc::Draw_Line - segment border");

                        ERR(D_Img_Proc::Draw_Line(
                                &MA_MS2_ToDo_Static,
                                x1, y3, x3, y3,
                                2,
                                val, val, val),
                            "MS2_UpdateImage_ToDo",
                            "D_Img_Proc::Draw_Line - segment border");
                    }

                    if(ui->checkBox_MS2_ToDo_StateBorders->isChecked())
                    {
                        int shift = 2;
                        int thickness = 2;

                        //left
                        ERR(D_Img_Proc::Draw_Line(
                                &MA_MS2_ToDo_Static,
                                x1+shift, y1+shift, x1+shift, y2-shift,
                                thickness,
                                r, g, b),
                            "MS2_UpdateImage_ToDo",
                            "D_Img_Proc::Draw_Line - State");

                        //top
                        ERR(D_Img_Proc::Draw_Line(
                                &MA_MS2_ToDo_Static,
                                x1+shift, y1+shift, x2-shift, y1+shift,
                                thickness,
                                r, g, b),
                            "MS2_UpdateImage_ToDo",
                            "D_Img_Proc::Draw_Line - State");

                        //right
                        ERR(D_Img_Proc::Draw_Line(
                                &MA_MS2_ToDo_Static,
                                x2-shift, y1+shift, x2-shift, y2-shift,
                                thickness,
                                r, g, b),
                            "MS2_UpdateImage_ToDo",
                            "D_Img_Proc::Draw_Line - State");

                        //bottom
                        ERR(D_Img_Proc::Draw_Line(
                                &MA_MS2_ToDo_Static,
                                x1+shift, y2-shift, x2-shift, y2-shift,
                                thickness,
                                r, g, b),
                            "MS2_UpdateImage_ToDo",
                            "D_Img_Proc::Draw_Line - State");
                    }

                    if(ui->checkBox_MS2_ToDo_StateMarkers->isChecked())
                        ERR(D_Img_Proc::Draw_MarkerSymbol(
                                &MA_MS2_ToDo_Static,
                                x1, y1, x2, y2,
                                symbol,
                                r, g, b,
                                0.2),
                            "MS2_UpdateImage_ToDo",
                            "D_Img_Proc::Draw_MarkerSymbol - State");
                }
            }
        }
    }

    //add overlay for detections
    if(ui->checkBox_MS2_ToDo_DetectionsOverlay->isChecked())
        D_Img_Proc::OverlayOverwrite(
                    &MA_MS2_ToDo_Static,
                    &MA_MS2_ToDo_Static,
                    &(v_MS2_MA_ChannelsImage_Full[MS2_CH_IMG_DET_IN]),
                    255, 255, 255,
                    1, 1);

    //show img
    MS2_Viewer_ToDo.Update_Image(&MA_MS2_ToDo_Static);

    //try to highlight frame of hovered segment
    MS2_UpdateImage_ToDo_Highlight();
}

void D_MAKRO_MegaFoci::MS2_UpdateImage_ToDo_Highlight(int x, int y)
{
    if(!ui->radioButton_MS2_Mode_ToDo->isChecked())
        return;

    if(!state_MS2_todo_static_img_created)
        return;

    //size
    int w = MA_MS2_ToDo_Static.cols;
    int h = MA_MS2_ToDo_Static.rows;

    if(x < 0 || x >= w || y < 0 || y >= h)
        return;

    //calc mosaik pos
    int ix = max(0, min(int(dataset_dim_mosaic_x - 1), int((x / double(w)) * dataset_dim_mosaic_x)));
    int iy = max(0, min(int(dataset_dim_mosaic_y - 1), int((y / double(h)) * dataset_dim_mosaic_y)));

    //base img
    MA_MS2_ToDo_Highlight = MA_MS2_ToDo_Static.clone();

    //calc frame of current img in mosaic

    //border stitching
    double overlap = ui->doubleSpinBox_ImgProc_Stitch_Border->value() / 100.0;

    //rect
    int x1 = int(max(0.0,                           (double(ix              ) / dataset_dim_mosaic_x) * MS2_MosaikImageWidth));
    int y1 = int(max(0.0,                           (double(iy              ) / dataset_dim_mosaic_y) * MS2_MosaikImageHeight));
    int x3 = int(min(MS2_MosaikImageWidth  - 1.0,   (double(ix + 1 + overlap) / dataset_dim_mosaic_x) * MS2_MosaikImageWidth));
    int y3 = int(min(MS2_MosaikImageHeight - 1.0,   (double(iy + 1 + overlap) / dataset_dim_mosaic_y) * MS2_MosaikImageHeight));

    int shift_px = 0;
    int thickness = 2;

    //draw highlight frame outer
    if(ui->checkBox_MS2_ToDo_SegmentBorders)
        ERR(D_Img_Proc::Draw_Rect(
                &MA_MS2_ToDo_Highlight,
                max(0, min(MS2_MosaikImageWidth  - 1, x1 - shift_px)),
                max(0, min(MS2_MosaikImageHeight - 1, y1 - shift_px)),
                max(0, min(MS2_MosaikImageWidth  - 1, x3 + shift_px)),
                max(0, min(MS2_MosaikImageHeight - 1, y3 + shift_px)),
                thickness,
                255),
            "MS2_UpdateImage_ToDo_Highlight",
            "D_Img_Proc::Draw_Rect - highlight frame outer");

    if(ui->checkBox_MS2_ToDo_SegmentNuclei->isChecked())
        ERR(D_Img_Proc::Draw_Contours(
                &MA_MS2_ToDo_Highlight,
                vv_MS2_NucImg_In_mosaikXY[ix][iy].get_nuclei_contours(ui->doubleSpinBox_OverviewQuality->value() / 100.0, Point(0, 0)),
                5,
                255),
            "MS2_UpdateImage_ToDo_Highlight",
            "D_Img_Proc::Draw_Contours - Segment nuclei");

    //show img
    MS2_Viewer_ToDo.Update_Image(&MA_MS2_ToDo_Highlight);
}

void D_MAKRO_MegaFoci::MS2_UpdateImage_ToDo_Highlight()
{
    return MS2_UpdateImage_ToDo_Highlight(
                MS2_Viewer_ToDo.MousePos_X(),
                MS2_Viewer_ToDo.MousePos_Y());
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

    for(size_t y = 0; y < dataset_dim_mosaic_x; y++)
        for(size_t x = 0; x < dataset_dim_mosaic_y; x++)
        {
            if(x != ix || y != iy)
                if(vv_MS2_NucImg_State_Out_mosaikXY[x][y] != MS2_IMG_STATE_PROCESSED)
                {
                    if(y != iy)
                        ui->spinBox_MS2_Viewport_X->blockSignals(true);
                    ui->spinBox_MS2_Viewport_X->setValue(x);
                    if(y != iy)
                        ui->spinBox_MS2_Viewport_X->blockSignals(false);

                    ui->spinBox_MS2_Viewport_Y->setValue(y);
                    return;
                }
        }
}

void D_MAKRO_MegaFoci::MS2_MoveToNextViewport()
{
    if(!state_MS2_detections_loaded)
        return;

    int ix = ui->spinBox_MS2_Viewport_X->value();
    int iy = ui->spinBox_MS2_Viewport_Y->value();
    int it = ui->spinBox_MS2_Viewport_T->value();

    if(ix < ui->spinBox_MS2_Viewport_X->maximum())
    {
        ix++;

        ui->spinBox_MS2_Viewport_X->setValue(ix);
    }
    else if(iy < ui->spinBox_MS2_Viewport_Y->maximum())
    {
        ix = 0;
        iy++;

        ui->spinBox_MS2_Viewport_X->blockSignals(true);
        ui->spinBox_MS2_Viewport_X->setValue(ix);
        ui->spinBox_MS2_Viewport_X->blockSignals(false);

        ui->spinBox_MS2_Viewport_Y->setValue(iy);
    }
    else if(it < ui->spinBox_MS2_Viewport_T->maximum())
    {
        ix = 0;
        iy = 0;
        it++;

        ui->spinBox_MS2_Viewport_X->blockSignals(true);
        ui->spinBox_MS2_Viewport_X->setValue(ix);
        ui->spinBox_MS2_Viewport_X->blockSignals(false);

        ui->spinBox_MS2_Viewport_Y->blockSignals(true);
        ui->spinBox_MS2_Viewport_Y->setValue(iy);
        ui->spinBox_MS2_Viewport_Y->blockSignals(false);

        ui->spinBox_MS2_Viewport_T->setValue(it);
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
    ui->spinBox_MS2_Tools_AllplyPoints_DrawSize->setEnabled             (point_count >= 1 && !draw_points);
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

    //enable ui
    ui->groupBox_MS2_EventList->setEnabled(true);
    ui->groupBox_MS2_Viewport->setEnabled(true);
    ui->tabWidget_MS2_Control->setEnabled(true);
    ui->pushButton_MS2_EventList_Load->setEnabled(true);

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
    this->setEnabled(false);
    bool ok = MS2_LoadData_Time(ui->spinBox_MS2_Viewport_T->value());
    this->setEnabled(true);
    return ok;
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
        int err = ER_okay;

        //try loading existing img
        if(FI.exists())
        {
            err = D_Img_Proc::Load_From_Path(
                        &(v_MS2_MA_ChannelsImage_Full[ch+1]),
                        FI);
            ERR(
                        err,
                        "MS2_LoadData_Mosaiks_In",
                        "Failed to load " + FI.absoluteFilePath() + ".\nAn empty channel image is created instead");
        }
    }

    //load input detetcion overlay
    QFileInfo FI_DetIn(DIR_MS2_In_Mosaik.path() + "/AutoDetections/Mosaik_AutoDetections_T" + QString::number(t) + ".png");
    int err = ER_okay;

    //try loading existing img
    if(FI_DetIn.exists())
    {
        Mat MA_tmp_DetIn;
        err = D_Img_Proc::Load_From_Path(
                    &MA_tmp_DetIn,
                    FI_DetIn);
        ERR(
                    err,
                    "MS2_LoadData_Mosaiks_In",
                    "Failed to load " + FI_DetIn.absoluteFilePath() + ".\nAn empty channel image is created instead");

        if(err == ER_okay)
        {
            Mat MA_tmp_DetIn_Gray;
            err = D_Img_Proc::Convert_Color2Mono(
                        &MA_tmp_DetIn_Gray,
                        &MA_tmp_DetIn,
                        c_COL2MONO_GRAY);
            ERR(
                        err,
                        "MS2_LoadData_Mosaiks_In",
                        "D_Img_Proc::Convert_Color2Mono");

            if(err == ER_okay)
            {
                err = D_Img_Proc::Threshold_Absolute(
                            &(v_MS2_MA_ChannelsImage_Full[MS2_CH_IMG_DET_IN]),
                            &MA_tmp_DetIn_Gray,
                            254);
                ERR(
                            err,
                            "MS2_LoadData_Mosaiks_In",
                            "D_Img_Proc::Threshold_Absolute");
            }

            MA_tmp_DetIn_Gray.release();
        }

        MA_tmp_DetIn.release();
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

    StatusSet("Start loading detections for T=" + QString::number(t));

    if(t >= dataset_dim_t)
    {
        StatusSet("Failed loading detections for T=" + QString::number(t) + ". (T out of range)");
        return false;
    }

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
    {
        StatusSet("Failed loading detections for T=" + QString::number(t) + ". Dir does not exists.");
        return false;
    }

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
                            {
                                StatusSet("Failed loading detections for T=" + QString::number(t) + ". non comaptible step MS=" + QString::number(mode_major_current) + ".");
                                return false;
                            }


                            //load nucleus image
                            D_Bio_NucleusImage NucImg;
                            int ER = NucImg.load(DIR_ImageTYX.path(), false);
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

    StatusSet("Finished loading detections for T=" + QString::number(t));
    return true;
}

void D_MAKRO_MegaFoci::MS2_ChangeMode(int mode)
{
    ui->groupBox_MS2_Viewer_ToDoList->setVisible(mode == MS2_MODE_TO_DO);

    ui->groupBox_MS2_Viewer_1->setVisible(mode == MS2_MODE_DETAILED);
    ui->groupBox_MS2_Viewer_2->setVisible(mode == MS2_MODE_DETAILED);
    ui->groupBox_MS2_Viewer_3->setVisible(mode == MS2_MODE_DETAILED);
    ui->groupBox_MS2_Viewer_4->setVisible(mode == MS2_MODE_DETAILED);

    ui->tabWidget_MS2_Control->setEnabled(mode == MS2_MODE_DETAILED);
    ui->groupBox_MS2_EventList->setEnabled(mode == MS2_MODE_DETAILED);
    ui->spinBox_MS2_Viewport_X->setEnabled(mode == MS2_MODE_DETAILED);
    ui->spinBox_MS2_Viewport_Y->setEnabled(mode == MS2_MODE_DETAILED);
    ui->pushButton_MS2_Viewport_Up->setEnabled(mode == MS2_MODE_DETAILED);
    ui->pushButton_MS2_Viewport_Down->setEnabled(mode == MS2_MODE_DETAILED);
    ui->pushButton_MS2_Viewport_Left->setEnabled(mode == MS2_MODE_DETAILED);
    ui->pushButton_MS2_Viewport_Right->setEnabled(mode == MS2_MODE_DETAILED);
    ui->pushButton_MS2_Viewport_NextToCorrect->setEnabled(mode == MS2_MODE_DETAILED);

    if(mode == MS2_MODE_TO_DO)
        MS2_UpdateImage_ToDo_Static();
}

void D_MAKRO_MegaFoci::MS2_EventList_Load()
{
    if(MS2_EventList_FileSet)
        return;

    //get file path
    QString QS_Load = QFileDialog::getOpenFileName(
                this,
                "Load event list",
                pStore->dir_M_MegaFoci_Results()->path(),
                "Textfiles (*.txt)");

    if(QS_Load.isEmpty())
        return;

    //save file info
    MS2_EventList_File.setFile(QS_Load);
    if(!MS2_EventList_File.exists())
    {
        StatusSet("Selected file does not exist:\n" + MS2_EventList_File.absoluteFilePath());
        return;
    }

    //read file
    QFile F_EventList(MS2_EventList_File.absoluteFilePath());
    if(!F_EventList.open(QIODevice::ReadOnly))
        return;
    QTextStream TS_EventList(&F_EventList);
    MS2_EventList_Events.clear();
    while(!TS_EventList.atEnd())
        MS2_EventList_Events.append(TS_EventList.readLine());

    pStore->set_dir_M_MegaFoci_Results(QS_Load);
    MS2_EventList_FileSet = true;
    ui->spinBox_MS2_EventList_Event_Line->setMaximum(MS2_EventList_Events.size() - 1);
    ui->spinBox_MS2_EventList_Event_Line->setValue(MS2_EventList_CursorOffset);
    StatusSet("Event list file read:\n" + MS2_EventList_File.absoluteFilePath());
    Update_Ui();

    MS2_EventList_Sort();

    ui->pushButton_MS2_EventList_Load->setEnabled(false);
    ui->pushButton_MS2_EventList_Close->setEnabled(true);
    ui->pushButton_MS2_EventList_ToBegin->setEnabled(true);
    ui->pushButton_MS2_EventList_ToEnd->setEnabled(true);
    ui->pushButton_MS2_EventList_Move->setEnabled(true);
    ui->groupBox_MS2_EventList_Event->setEnabled(true);
    ui->groupBox_MS2_EventList_MovementDirection->setEnabled(true);
    ui->groupBox_MS2_EventList_SolveOnMove->setEnabled(true);
    ui->groupBox_MS2_EventList_MoveToEvent->setEnabled(true);

    MS2_EventList_ReadAtCursor();
    MS2_EventList_MoveToEvent();
}

void D_MAKRO_MegaFoci::MS2_EventList_Close()
{
    if(!MS2_EventList_FileSet)
        return;

    MS2_EventList_Events.clear();
    MS2_EventList_FileSet = false;

    ui->pushButton_MS2_EventList_Load->setEnabled(true);
    ui->pushButton_MS2_EventList_Close->setEnabled(false);
    ui->pushButton_MS2_EventList_ToBegin->setEnabled(false);
    ui->pushButton_MS2_EventList_ToEnd->setEnabled(false);
    ui->pushButton_MS2_EventList_Move->setEnabled(false);
    ui->groupBox_MS2_EventList_Event->setEnabled(false);
    ui->groupBox_MS2_EventList_MovementDirection->setEnabled(false);
    ui->groupBox_MS2_EventList_SolveOnMove->setEnabled(false);
    ui->groupBox_MS2_EventList_MoveToEvent->setEnabled(false);

    MS2_UpdateImages_Editing();
}

bool D_MAKRO_MegaFoci::MS2_EventList_Sort()
{
    if(!MS2_EventList_FileSet)
        return false;

    if(MS2_EventList_Events.size() <= MS2_EventList_CursorOffset)
    {
        ui->label_MS2_EventList_Event_Comment->setText("Event list empty");
        ERR(ER_empty, "MS2_EventList_Sort", "Event list empty");
        return false;
    }

    //buffer list
    QStringList QLS_SortedList;

    //copy header
    for(int l = 0; l < MS2_EventList_CursorOffset; l++)
        QLS_SortedList.append(MS2_EventList_Events[l]);

    //sort
    int n_l_sort = MS2_EventList_Events.size();
    for(int l_sort = MS2_EventList_CursorOffset; l_sort < n_l_sort; l_sort++)
    {
        QString QS_Event2Sort = MS2_EventList_Events[l_sort];

        bool ok;

        //read t
        int t_sort = MS2_EventList_Decode_Number(MS2_EventList_Events, l_sort, 't', &ok);
        if(!ok)
            return false;

        //read y
        int y_sort = MS2_EventList_Decode_Number(MS2_EventList_Events, l_sort, 'y', &ok);
        if(!ok)
            return false;

        //read x
        int x_sort = MS2_EventList_Decode_Number(MS2_EventList_Events, l_sort, 'x', &ok);
        if(!ok)
            return false;

        int n_l_check           = QLS_SortedList.size();
        bool found_insert_pos   = false;
        int insert_pos          = 0;
        for(int l_check = MS2_EventList_CursorOffset; l_check < n_l_check && !found_insert_pos; l_check++)
        {
            //read t
            int t_check = MS2_EventList_Decode_Number(QLS_SortedList, l_check, 't', &ok);
            if(!ok)
                return false;

            //read y
            int y_check = MS2_EventList_Decode_Number(QLS_SortedList, l_check, 'y', &ok);
            if(!ok)
                return false;

            //read x
            int x_check = MS2_EventList_Decode_Number(QLS_SortedList, l_check, 'x', &ok);
            if(!ok)
                return false;

            //compare t
            if(t_sort < t_check)
            {
                insert_pos = l_check;
                found_insert_pos = true;
            }
            else if(t_sort == t_check)
            {
                //compare y
                if(y_sort < y_check)
                {
                    insert_pos = l_check;
                    found_insert_pos = true;
                }
                else if(y_sort == y_check)
                {
                    //compare x
                    if(x_sort <= x_check)
                    {
                        insert_pos = l_check;
                        found_insert_pos = true;
                    }
                }
            }
        }

        //insert event to sorted list
        if(found_insert_pos)
            QLS_SortedList.insert(insert_pos, QS_Event2Sort);
        else
            QLS_SortedList.append(QS_Event2Sort);
    }

    StatusSet("Sorted event list by t>y>x (increasing)");

    //save sorted list
    MS2_EventList_Events = QLS_SortedList;
    MS2_EventList_SaveList();
    Update_Ui();
    return true;
}

void D_MAKRO_MegaFoci::MS2_EventList_SaveList()
{
    if(!MS2_EventList_FileSet)
        return;

    ofstream OS;
    OS.open(MS2_EventList_File.absoluteFilePath().toStdString());
    if(!OS.is_open())
        return;
    for(int l = 0; l < MS2_EventList_Events.size(); l++)
    {
        if(l > 0)
            OS << "\n";
        OS << MS2_EventList_Events[l].toStdString();
    }
    OS.close();
}

void D_MAKRO_MegaFoci::MS2_EventList_SaveCurrent()
{
    if(!MS2_EventList_FileSet)
        return;

    if(ui->spinBox_MS2_EventList_Event_Line->value() >= MS2_EventList_Events.size() || ui->spinBox_MS2_EventList_Event_Line->value() < MS2_EventList_CursorOffset)
        return;

    MS2_EventList_Events[ui->spinBox_MS2_EventList_Event_Line->value()] = QString(
            QString::number(ui->spinBox_MS2_EventList_Event_T->value()) + ";" +
            QString::number(ui->spinBox_MS2_EventList_Event_Y->value()) + ";" +
            QString::number(ui->spinBox_MS2_EventList_Event_X->value()) + ";" +
            QString::number(ui->spinBox_MS2_EventList_Event_R->value()) + ";" +
            ui->label_MS2_EventList_Event_Comment->text() + ";" +
            QString(ui->checkBox_MS2_EventList_Event_Solved->isChecked() ? "Done" : "ToDo"));

    MS2_EventList_SaveList();
}

bool D_MAKRO_MegaFoci::MS2_EventList_ReadAtCursor()
{
    MS2_EventList_ReadEventValid = false;

    bool ok;

    //t
    int t = MS2_EventList_Decode_Number_Current('t', &ok);
    if(!ok)
        return false;
    ui->spinBox_MS2_EventList_Event_T->setValue(t);

    //y
    int y = MS2_EventList_Decode_Number_Current('y', &ok);
    if(!ok)
        return false;
    ui->spinBox_MS2_EventList_Event_Y->setValue(y);

    //x
    int x = MS2_EventList_Decode_Number_Current('x', &ok);
    if(!ok)
        return false;
    ui->spinBox_MS2_EventList_Event_X->setValue(x);

    //r
    int r = MS2_EventList_Decode_Number_Current('r', &ok);
    if(!ok)
        return false;
    ui->spinBox_MS2_EventList_Event_R->setValue(r);

    //comment
    QString QS_Comment = MS2_EventList_Decode_Comment_Current(&ok);
    if(!ok)
        return false;
    ui->label_MS2_EventList_Event_Comment->setText(QS_Comment);

    //status
    bool status = MS2_EventList_Decode_Status_Current(&ok);
    if(!ok)
        return false;
    ui->checkBox_MS2_EventList_Event_Solved->blockSignals(true);
    ui->checkBox_MS2_EventList_Event_Solved->setChecked(status);
    ui->checkBox_MS2_EventList_Event_Solved->blockSignals(false);

    Update_Ui();
    MS2_EventList_ReadEventValid = true;
    return true;
}

bool D_MAKRO_MegaFoci::MS2_EventList_MoveToEvent()
{
    if(MS2_EventList_Events.size() <= MS2_EventList_CursorOffset)
    {
        ui->label_MS2_EventList_Event_Comment->setText("Event list empty");
        ERR(ER_empty, "MS2_EventList_MoveToEvent", "Event list empty");
        return false;
    }

    if(ui->spinBox_MS2_EventList_Event_Line->value() >= MS2_EventList_Events.size())
    {
        ui->label_MS2_EventList_Event_Comment->setText("Cursor behind event list");
        ERR(ER_index_out_of_range, "MS2_EventList_MoveToEvent", "Event cursor behind end of event list");
        return false;
    }

    //size x/y
    size_t sx_full = size_t(v_MS2_MA_ChannelsImage_Full[0].cols * (1.0 / MS2_MosaikImageScale));
    size_t sy_full = size_t(v_MS2_MA_ChannelsImage_Full[0].rows * (1.0 / MS2_MosaikImageScale));

    //event pos
    int event_x = ui->spinBox_MS2_EventList_Event_X->value();
    int event_y = ui->spinBox_MS2_EventList_Event_Y->value();

    //offest to editable area
    double overlap_rel  = ui->doubleSpinBox_ImgProc_Stitch_Border->value() / 100.0;
    int overlap_abs_x   = int(overlap_rel * (double(sx_full) / double(dataset_dim_mosaic_x)));
    int overlap_abs_y   = int(overlap_rel * (double(sy_full) / double(dataset_dim_mosaic_y)));

    //dummy target pos
    int target_x = max(0, event_x - overlap_abs_x);
    int target_y = max(0, event_y - overlap_abs_y);

    //rel pos of event
    double rel_pos_x = double(target_x) / double(sx_full);
    double rel_pos_y = double(target_y) / double(sy_full);

    //mosaik pos of event
    int mosaic_x = min(int(dataset_dim_mosaic_x - 1), int(rel_pos_x * dataset_dim_mosaic_x));
    int mosaic_y = min(int(dataset_dim_mosaic_y - 1), int(rel_pos_y * dataset_dim_mosaic_y));

    //move to viewport
    ui->spinBox_MS2_Viewport_T->setValue(ui->spinBox_MS2_EventList_Event_T->value());
    ui->spinBox_MS2_Viewport_Y->setValue(mosaic_y);
    ui->spinBox_MS2_Viewport_X->setValue(mosaic_x);

    MS2_UpdateImages_Editing();
    return true;
}

void D_MAKRO_MegaFoci::MS2_EventList_Move()
{
    if(!MS2_EventList_FileSet)
        return;

    //params
    bool move_forward   = ui->radioButton_MS2_EventList_Direction_Forward->isChecked();
    bool unsolved_only  = ui->radioButton_MS2_EventList_Events_Unsolved->isChecked();
    bool solve_on_move  = ui->radioButton_MS2_EventList_SolveOnMove_Yes->isChecked();

    //solve on move
    if(solve_on_move)
    {
        ui->checkBox_MS2_EventList_Event_Solved->blockSignals(true);
        ui->checkBox_MS2_EventList_Event_Solved->setChecked(true);
        ui->checkBox_MS2_EventList_Event_Solved->blockSignals(false);
        Update_Ui();
        MS2_EventList_SaveCurrent();
    }


    //direction
    if(move_forward)
    {
        //FORWARD
        do
        {
            ui->spinBox_MS2_EventList_Event_Line->setValue(ui->spinBox_MS2_EventList_Event_Line->value() + 1);
            MS2_EventList_ReadAtCursor();
        }
        while(unsolved_only && ui->checkBox_MS2_EventList_Event_Solved->isChecked() && ui->spinBox_MS2_EventList_Event_Line->value() < MS2_EventList_Events.size() - 1);
    }
    else
    {
        //BACKWARD
        do
        {
            ui->spinBox_MS2_EventList_Event_Line->setValue(ui->spinBox_MS2_EventList_Event_Line->value() - 1);
            MS2_EventList_ReadAtCursor();
        }
        while(unsolved_only && ui->checkBox_MS2_EventList_Event_Solved->isChecked() && ui->spinBox_MS2_EventList_Event_Line->value() > MS2_EventList_CursorOffset);
    }

    MS2_EventList_MoveToEvent();
}

void D_MAKRO_MegaFoci::MS2_EventList_Move_ToBegin()
{
    ui->spinBox_MS2_EventList_Event_Line->setValue(MS2_EventList_CursorOffset);
    MS2_EventList_ReadAtCursor();
    MS2_EventList_MoveToEvent();
}

void D_MAKRO_MegaFoci::MS2_EventList_Move_ToEnd()
{
    ui->spinBox_MS2_EventList_Event_Line->setValue(MS2_EventList_Events.size() - 1);
    MS2_EventList_ReadAtCursor();
    MS2_EventList_MoveToEvent();
}

int D_MAKRO_MegaFoci::MS2_EventList_Decode_Number_Current(char number_name, bool *ok)
{
    return MS2_EventList_Decode_Number(
                ui->spinBox_MS2_EventList_Event_Line->value(),
                number_name,
                ok);
}

int D_MAKRO_MegaFoci::MS2_EventList_Decode_Number(int line, char number_name, bool* ok)
{
    return MS2_EventList_Decode_Number(
                MS2_EventList_Events,
                line,
                number_name,
                ok);
}

int D_MAKRO_MegaFoci::MS2_EventList_Decode_Number(QStringList QSL_List, int line, char number_name, bool *ok)
{
    *ok = false;

    size_t i;
    if(number_name == 't' || number_name == 'T')
        i = 0;
    else if(number_name == 'y' || number_name == 'Y')
        i = 1;
    else if(number_name == 'x' || number_name == 'X')
        i = 2;
    else if(number_name == 'r' || number_name == 'R')
        i = 3;
    else
        return 0;

    if(QSL_List.size() <= MS2_EventList_CursorOffset)
    {
        ERR(ER_empty, "MS2_EventList_Decode_Number", "Event list empty");
        return false;
    }

    if(line >= QSL_List.size())
    {
        ERR(ER_index_out_of_range, "MS2_EventList_Decode_Number", "Event cursor behind end of event list");
        return false;
    }

    QString QS_Event = QSL_List[line];
    QStringList QSL_Blocks = QS_Event.split(";");
    if(QSL_Blocks.size() != 6)
    {
        ERR(ER_size_missmatch, "MS2_EventList_Decode_Number", "Event has wrong number of text elements to be decoded");
        return 0;
    }

    int val = QSL_Blocks[i].toInt(ok);

    if(!(*ok))
    {
        ERR(ER_type_bad, "MS2_EventList_Decode_Number", "Failed reading " + QString(number_name));
        return 0;
    }

    *ok = true;
    return val;
}

QString D_MAKRO_MegaFoci::MS2_EventList_Decode_Comment_Current(bool *ok)
{
    return MS2_EventList_Decode_Comment(
                ui->spinBox_MS2_EventList_Event_Line->value(),
                ok);
}

QString D_MAKRO_MegaFoci::MS2_EventList_Decode_Comment(int line, bool* ok)
{
    *ok = false;

    if(MS2_EventList_Events.size() <= MS2_EventList_CursorOffset)
    {
        ERR(ER_empty, "MS2_EventList_Decode_Comment", "Event list empty");
        return "";
    }

    if(line >= MS2_EventList_Events.size())
    {
        ERR(ER_index_out_of_range, "MS2_EventList_Decode_Comment", "Event cursor behind end of event list");
        return "";
    }

    QString QS_Event = MS2_EventList_Events[line];
    QStringList QSL_Blocks = QS_Event.split(";");
    if(QSL_Blocks.size() != 6)
    {
        ERR(ER_size_missmatch, "MS2_EventList_Decode_Comment", "Event has wrong number of text elements to be decoded");
        return "";
    }

    *ok = true;
    return QSL_Blocks[4];
}

bool D_MAKRO_MegaFoci::MS2_EventList_Decode_Status_Current(bool *ok)
{
    return MS2_EventList_Decode_Status(
                ui->spinBox_MS2_EventList_Event_Line->value(),
                ok);
}

bool D_MAKRO_MegaFoci::MS2_EventList_Decode_Status(int line, bool* ok)
{
    *ok = false;

    if(MS2_EventList_Events.size() <= MS2_EventList_CursorOffset)
    {
        ui->label_MS2_EventList_Event_Comment->setText("Event list empty");
        ERR(ER_empty, "MS2_EventList_Decode_Status", "Event list empty");
        return false;
    }

    if(line >= MS2_EventList_Events.size())
    {
        ui->label_MS2_EventList_Event_Comment->setText("Cursor behind event list");
        ERR(ER_index_out_of_range, "MS2_EventList_Decode_Status", "Event cursor behind end of event list");
        return false;
    }

    QString QS_Event = MS2_EventList_Events[line];
    QStringList QSL_Blocks = QS_Event.split(";");
    if(QSL_Blocks.size() != 6)
    {
        ui->label_MS2_EventList_Event_Comment->setText("Ivalid number of elements in event");
        ERR(ER_size_missmatch, "MS2_EventList_Decode_Status", "Event has wrong number of text elements to be decoded");
        return false;
    }

    QString QS_Status = QSL_Blocks[5];
    if(QS_Status == "ToDo")
    {
        *ok = true;
        return false;
    }
    else if(QS_Status == "Done")
    {
        *ok = true;
        return true;
    }
    else
    {
        ERR(ER_type_bad, "MS2_EventList_Decode_Status", "Failed reading status: " + QS_Status);
        return false;
    }
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

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0A_BaseBin_FilterRadius_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_OTHER_SEG0A_BASEBIN_BG_REFERENCE);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0A_BaseBin_Quantil_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_OTHER_SEG0A_BASEBIN_BG_REFERENCE);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0A_BaseBin_ThresHysteresis_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_OTHER_SEG0A_BASEBIN_THRESH_HYSTERESIS);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0A_BaseBin_ThresIndicator_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_OTHER_SEG0A_BASEBIN_THRESH_INDICATOR);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0A_Blur_GaussSigma_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_OTHER_SEG0A_BLUR_GAUSS);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0A_Blur_GaussSize_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_OTHER_SEG0A_BLUR_GAUSS);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Seg0A_ClosingSize_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_OTHER_SEG0A_MORPH_CLOSEING);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_comboBox_ImgProc_Seg0A_IgnoreDirt_Stat_currentIndexChanged(int index)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_OTHER_SEG0A_EXCLUDE_DIRT_BY_STAT);
    index++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0A_IgnoreDirt_Thres_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_OTHER_SEG0A_EXCLUDE_DIRT_BY_STAT);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0B_BaseBin_FilterRadius_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG0B_BASEBIN_BG_REFERENCE);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0B_BaseBin_Quantil_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG0B_BASEBIN_BG_REFERENCE);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0B_BaseBin_ThresHysteresis_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG0B_BASEBIN_THRESH_HYSTERESIS);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0B_BaseBin_ThresIndicator_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG0B_BASEBIN_THRESH_INDICATOR);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0B_Blur_GaussSigma_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG0B_BLUR_GAUSS);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0B_Blur_GaussSize_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG0B_BLUR_GAUSS);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Seg0B_ClosingSize_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG0B_MORPH_CLOSEING);
    arg1++;//useless opration to supress warning
}


void D_MAKRO_MegaFoci::on_comboBox_ImgProc_Seg0B_IgnoreDirt_Stat_activated(int index)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG0B_EXCLUDE_DIRT_BY_STAT);
    index++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0B_IgnoreDirt_Thres_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG0B_EXCLUDE_DIRT_BY_STAT);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Seg0_CloseGaps_Size_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_BOTH_SEG0_CLOSE_GAPS);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0_GetSmall_Area_Min_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_BOTH_SEG0_SELECT_AREA_SMALL);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0_GetSmall_Area_Max_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_BOTH_SEG0_SELECT_AREA_SMALL);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_ConnectSmall_CloseSize_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_BOTH_SEG0_MORPH_CLOSE_SMALL);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0_Area_Min_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_BOTH_SEG0_SELECT_AREA_BIG);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg0_Area_Max_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_BOTH_SEG0_SELECT_AREA_BIG);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg1_DistThresh_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_BOTH_SEG1_SEEDS);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Seg1_OpenSeeds_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_BOTH_SEG1_SEEDS_CLEAR);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg2_DistThresh_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_BOTH_SEG2_SEEDS);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Seg2_OpenSeeds_valueChanged(int arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_BOTH_SEG2_SEEDS_CLEAR);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg2_Area_Min_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_BOTH_SEG2_SELECT_AREA);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Seg2_Area_Max_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_BOTH_SEG2_SELECT_AREA);
    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_spinBox_ImgProc_Seg3_Open_valueChanged(int arg1)
{
    arg1++;//useless opration to supress warning
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_BOTH_SEG3C_OPEND);
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
    Update_ImageProcessing_StepFrom_MS1(STEP_VIS_REGIONS_BACKGROUND_NUCLEI_USED);

    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_ImgProc_Vis_Intensity_Overlay_valueChanged(double arg1)
{
    Update_ImageProcessing_StepFrom_MS1(STEP_VIS_REGIONS_BACKGROUND_NUCLEI_USED);

    arg1++;//useless opration to supress warning
}

void D_MAKRO_MegaFoci::on_groupBox_Seg0A_OTHER_clicked()
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_OTHER_SEG0A_BLUR_GAUSS);
}

void D_MAKRO_MegaFoci::on_groupBox_Seg0B_GFP_clicked()
{
    Update_ImageProcessing_StepFrom_MS1(STEP_NUC_GFP_SEG0B_BLUR_GAUSS);
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

void D_MAKRO_MegaFoci::on_pushButton_ParamLoad_clicked()
{
    Params_Load();
}

void D_MAKRO_MegaFoci::on_pushButton_ParamSave_clicked()
{
    Params_Save();
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
        ui->groupBox_MS2_Mode->setEnabled(true);
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

void D_MAKRO_MegaFoci::on_pushButton_MS2_EventList_Load_clicked()
{
    MS2_EventList_Load();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_EventList_Close_clicked()
{
    MS2_EventList_Close();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_EventList_Move_clicked()
{
    MS2_EventList_Move();
}

void D_MAKRO_MegaFoci::on_checkBox_MS2_EventList_Event_Solved_stateChanged(int arg1)
{
    MS2_EventList_SaveCurrent();
    MS2_UpdateImages_Editing();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_EventList_ToBegin_clicked()
{
    MS2_EventList_Move_ToBegin();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_EventList_ToEnd_clicked()
{
    MS2_EventList_Move_ToEnd();
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



void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_ApplyPoints_Merge_clicked()
{
    MS2_Draw_MergeObjects();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_ApplyPointsParam_PointsBigger_clicked()
{
    ui->spinBox_MS2_Tools_AllplyPoints_DrawSize->setValue(ui->spinBox_MS2_Tools_AllplyPoints_DrawSize->value() + 1);
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_ApplyPointsParam_PointsSmaller_clicked()
{
    ui->spinBox_MS2_Tools_AllplyPoints_DrawSize->setValue(ui->spinBox_MS2_Tools_AllplyPoints_DrawSize->value() - 1);
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_Tools_ApplyPoints_Separate_clicked()
{

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

void D_MAKRO_MegaFoci::on_pushButton_MS2_Viewport_NextSegment_clicked()
{
    MS2_MoveToNextViewport();
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
    ui->pushButton_MS2_Viewport_NextToCorrect->setEnabled(value < ui->progressBar_MS2_CorrectionProgress->maximum() && ui->radioButton_MS2_Mode_Detailed->isChecked());
}

void D_MAKRO_MegaFoci::on_radioButton_MS2_Mode_ToDo_clicked(bool checked)
{
    MS2_ChangeMode(MS2_MODE_TO_DO);
}

void D_MAKRO_MegaFoci::on_radioButton_MS2_Mode_Detailed_clicked(bool checked)
{
    MS2_ChangeMode(MS2_MODE_DETAILED);
}

void D_MAKRO_MegaFoci::on_checkBox_MS2_ToDo_StateBorders_clicked()
{
    MS2_UpdateImage_ToDo_Static();
}

void D_MAKRO_MegaFoci::on_checkBox_MS2_ToDo_StateMarkers_clicked()
{
    MS2_UpdateImage_ToDo_Static();
}

void D_MAKRO_MegaFoci::on_checkBox_MS2_ToDo_SegmentBorders_clicked()
{
    MS2_UpdateImage_ToDo_Static();
}

void D_MAKRO_MegaFoci::on_checkBox_MS2_ToDo_DetectionsOverlay_clicked()
{
    MS2_UpdateImage_ToDo_Static();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_ToDo_HoveredToOk_clicked()
{
    MS2_ToDo_SetFinished();
}

void D_MAKRO_MegaFoci::on_pushButton_MS2_ToDo_HoveredToUnknown_clicked()
{
    MS2_ToDo_SetToBeEdited();
}

void D_MAKRO_MegaFoci::on_stackedWidget_StepMajor_currentChanged(int arg1)
{
    if(arg1 == MODE_MAJOR_3_AUTO_MATCHING_FOCI_NUCLEI)
        ui->stackedWidget_StepMajor->setCurrentIndex(MODE_MAJOR_1_AUTO_DETECTION);
}

void D_MAKRO_MegaFoci::on_comboBox_MS3_ImgProc_ProjectZ_Stat_currentIndexChanged(int index)
{
    index++;//useless opration to supress warning
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
    ui->spinBox_Viewport_S->setEnabled(index == STEP_MS3_VIS_NUCLEI_FILLED_STACK);

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

void D_MAKRO_MegaFoci::on_spinBox_MS3_ImgProc_Vis_Other_Min_valueChanged(int arg1)
{
    arg1++;//useless opration to supress warning
    Update_ImageProcessing_StepFrom_MS3(STEP_MS3_VIS_OTHER);
}

void D_MAKRO_MegaFoci::on_spinBox_MS3_ImgProc_Vis_Other_Max_valueChanged(int arg1)
{
    arg1++;//useless opration to supress warning
    Update_ImageProcessing_StepFrom_MS3(STEP_MS3_VIS_OTHER);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_MS3_ImgProc_Vis_Other_Gamma_valueChanged(double arg1)
{
    arg1++;//useless opration to supress warning
    Update_ImageProcessing_StepFrom_MS3(STEP_MS3_VIS_OTHER);
}

void D_MAKRO_MegaFoci::on_spinBox_MS3_ImgProc_Vis_GFP_Min_valueChanged(int arg1)
{
    arg1++;//useless opration to supress warning
    Update_ImageProcessing_StepFrom_MS3(STEP_MS3_VIS_GFP);
}

void D_MAKRO_MegaFoci::on_spinBox_MS3_ImgProc_Vis_GFP_Max_valueChanged(int arg1)
{
    arg1++;//useless opration to supress warning
    Update_ImageProcessing_StepFrom_MS3(STEP_MS3_VIS_GFP);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_MS3_ImgProc_Vis_GFP_Gamma_valueChanged(double arg1)
{
    arg1++;//useless opration to supress warning
    Update_ImageProcessing_StepFrom_MS3(STEP_MS3_VIS_GFP);
}

void D_MAKRO_MegaFoci::on_spinBox_MS3_ImgProc_Vis_RFP_Min_valueChanged(int arg1)
{
    arg1++;//useless opration to supress warning
    Update_ImageProcessing_StepFrom_MS3(STEP_MS3_VIS_RFP);
}

void D_MAKRO_MegaFoci::on_spinBox_MS3_ImgProc_Vis_RFP_Max_valueChanged(int arg1)
{
    arg1++;//useless opration to supress warning
    Update_ImageProcessing_StepFrom_MS3(STEP_MS3_VIS_RFP);
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_MS3_ImgProc_Vis_RFP_Gamma_valueChanged(double arg1)
{
    arg1++;//useless opration to supress warning
    Update_ImageProcessing_StepFrom_MS3(STEP_MS3_VIS_RFP);
}


void D_MAKRO_MegaFoci::on_spinBox_DataDim_X_valueChanged(int arg1)
{
    ui->groupBox_Dataset->setTitle("Dataset (" + QString::number(ui->spinBox_DataDim_X->value() * ui->spinBox_DataDim_Y->value() * ui->spinBox_DataDim_T->value()) + "Files)");
}

void D_MAKRO_MegaFoci::on_spinBox_DataDim_Y_valueChanged(int arg1)
{
    ui->groupBox_Dataset->setTitle("Dataset (" + QString::number(ui->spinBox_DataDim_X->value() * ui->spinBox_DataDim_Y->value() * ui->spinBox_DataDim_T->value()) + "Files)");
}

void D_MAKRO_MegaFoci::on_spinBox_DataDim_T_valueChanged(int arg1)
{
    ui->groupBox_Dataset->setTitle("Dataset (" + QString::number(ui->spinBox_DataDim_X->value() * ui->spinBox_DataDim_Y->value() * ui->spinBox_DataDim_T->value()) + "Files)");
}

void D_MAKRO_MegaFoci::MS4_UiInit()
{
    MS4_Viewer_Pedigree_Plot3D.init(ui->gridLayout_MS4_Pedigree_Plot3D);
    MS4_Viewer_Pedigree_Volumetric.init(ui->gridLayout_MS4_Pedigree_Volumetric3D);
    MS4_Viewer_Pedigree_Volumetric.Set_StoragePointer(pStore, dir_M_MEGAFOCI_RES);

    connect(ui->doubleSpinBox_MS4_Score_Weight_Shift,       SIGNAL(valueChanged(double)),          this,   SLOT(MS4_DisplayRelativeScoreWeights()));
    connect(ui->doubleSpinBox_MS4_Score_Weight_Area,        SIGNAL(valueChanged(double)),          this,   SLOT(MS4_DisplayRelativeScoreWeights()));
    connect(ui->doubleSpinBox_MS4_Score_Weight_Convexity,   SIGNAL(valueChanged(double)),          this,   SLOT(MS4_DisplayRelativeScoreWeights()));
    connect(ui->doubleSpinBox_MS4_Score_Weight_Compactness, SIGNAL(valueChanged(double)),          this,   SLOT(MS4_DisplayRelativeScoreWeights()));
    connect(ui->doubleSpinBox_MS4_Score_Weight_Mean_NUC,    SIGNAL(valueChanged(double)),          this,   SLOT(MS4_DisplayRelativeScoreWeights()));
    connect(ui->doubleSpinBox_MS4_Score_Weight_Mean_GFP,    SIGNAL(valueChanged(double)),          this,   SLOT(MS4_DisplayRelativeScoreWeights()));
    connect(ui->doubleSpinBox_MS4_Score_Weight_Mean_RFP,    SIGNAL(valueChanged(double)),          this,   SLOT(MS4_DisplayRelativeScoreWeights()));
    connect(ui->doubleSpinBox_MS4_Score_Weight_Std_NUC,     SIGNAL(valueChanged(double)),          this,   SLOT(MS4_DisplayRelativeScoreWeights()));
    connect(ui->doubleSpinBox_MS4_Score_Weight_Std_GFP,     SIGNAL(valueChanged(double)),          this,   SLOT(MS4_DisplayRelativeScoreWeights()));
    connect(ui->doubleSpinBox_MS4_Score_Weight_Std_RFP,     SIGNAL(valueChanged(double)),          this,   SLOT(MS4_DisplayRelativeScoreWeights()));

    MS4_DisplayRelativeScoreWeights();
    MS4_CalcOriginalMosaicSize();
    MS4_CalcVolumetricView_Memory();
}

bool D_MAKRO_MegaFoci::MS4_LoadData()
{
    if(mode_major_current != MODE_MAJOR_4_AUTO_RECONSTRUCT_PEDIGREE)
        return false;

    ui->pushButton_MS4_LoadData->setEnabled(false);

    if(!MS4_LoadDirs())
    {
        ui->pushButton_MS4_LoadData->setEnabled(true);
        return false;
    }

    if(!MS4_LoadDetectionsToPedigree())
    {
        ui->pushButton_MS4_LoadData->setEnabled(true);
        return false;
    }

    ui->groupBox_MS4_Matching->setEnabled(true);
    ui->groupBox_MS4_ScoreFeats->setEnabled(true);
    ui->groupBox_MS4_ScoreNoGoThres->setEnabled(true);
    ui->groupBox_MS4_Pedigree->setEnabled(true);
    ui->groupBox_MS4_PedigreePropertys->setEnabled(true);
    ui->groupBox_MS4_PedigreeView_General->setEnabled(true);
    ui->groupBox_MS4_PedigreeView_Plot3D->setEnabled(true);
    ui->groupBox_MS4_PedigreeView_Volumetric->setEnabled(true);

    if(!MS4_InitPedigree())
        return false;

    return true;
}

bool D_MAKRO_MegaFoci::MS4_LoadDirs()
{
    if(mode_major_current != MODE_MAJOR_4_AUTO_RECONSTRUCT_PEDIGREE)
        return false;

    StatusSet("Please select results directory from step 3.");
    QString QS_MasterIn = QFileDialog::getExistingDirectory(
                this,
                "Please select results folder of step 3 you want to load (must beginn with 'Results_Step3_').",
                pStore->dir_M_MegaFoci_Results()->path());

    //check if dir was selected
    if(QS_MasterIn.isEmpty())
    {
        StatusSet("Didn't you find your data? A clean file system is a nice thing, right?");
        return false;
    }

    //check, if dir is results from step 3
    if(!QS_MasterIn.contains("Results_Step3"))
    {
        StatusSet("You should selct results from step 3...\n" + QS_Fun_TableFlip);
        return false;
    }

    //master dir in
    DIR_MS4_In_Master.setPath(QS_MasterIn);
    if(!DIR_MS4_In_Master.exists())
    {
        StatusSet("With unknown dark magic you selected a not existing directory. " + QS_Fun_Confused);
        return false;
    }

    //dir in: detections
    DIR_MS4_In_DetectionsAssigned.setPath(DIR_MS4_In_Master.path() + "/DetectionsAssigned");
    if(!DIR_MS4_In_DetectionsAssigned.exists())
    {
        StatusSet("Your selected reults folder does not contain a detections folder... That won't work.");
        return false;
    }

    //correct input data selected
    StatusSet("Input valid:\n" + DIR_MS4_In_Master.path());

    //save input dir
    QDir DIR_parent(DIR_MS4_In_Master);
    DIR_parent.cdUp();
    pStore->set_dir_M_MegaFoci_Results(DIR_parent.path());

    state_MS4_dirs_loaded = true;
    return true;
}

bool D_MAKRO_MegaFoci::MS4_LoadDetectionsToPedigree()
{
    if(mode_major_current != MODE_MAJOR_4_AUTO_RECONSTRUCT_PEDIGREE)
        return false;

    /*
    //load backup instead of loading, if any exists
    bool backup_loaded = MS4_PedigreeBackup_Load();
    if(backup_loaded)
        return true;
        */

    if(!state_MS4_dirs_loaded)
        return false;

    state_MS4_detections_loaded_to_pedigree = false;
    state_MS4_pedigree_reconstructed = false;
    StatusSet("Start loading nuclei data from step 3");

    //load data
    MS4_NucPedigree_AutoReconstruct.load_nuclei_data(
                DIR_MS4_In_Master.path(),
                DIR_MS4_In_DetectionsAssigned.path(),
                dataset_dim_t, dataset_dim_mosaic_y, dataset_dim_mosaic_x,
                true,
                true);

    state_MS4_detections_loaded_to_pedigree = true;
    StatusSet("Finished loading nuclei data from step 3");

    /*
    //create backup
    MS4_PedigreeBackup_Create();
    */

    return true;
}

/*
bool D_MAKRO_MegaFoci::MS4_PedigreeBackup_Create()
{
    if(!state_MS4_detections_loaded_to_pedigree)
        return false;

    StatusSet("Create clean pedigree backup");
    MS4_NucPedigree_CleanBackup = MS4_NucPedigree_AutoReconstruct;
    state_MS4_pedigree_backup_created = true;
    return true;
}

bool D_MAKRO_MegaFoci::MS4_PedigreeBackup_Load()
{
    if(!state_MS4_pedigree_backup_created)
        return false;

    StatusSet("Load clean pedigree backup");
    MS4_NucPedigree_AutoReconstruct = MS4_NucPedigree_CleanBackup;
    state_MS4_pedigree_reconstructed = false;
    state_MS4_detections_loaded_to_pedigree = true;
    return true;
}
*/

bool D_MAKRO_MegaFoci::MS4_SaveData()
{
    if(mode_major_current != MODE_MAJOR_4_AUTO_RECONSTRUCT_PEDIGREE)
        return false;

    StatusSet("Please select directory to save step 4 results in");
    QString QS_Save = QFileDialog::getExistingDirectory(
                this,
                "Please select directory to save step 4 results in ('Results_4_* folder is created automatically')",
                pStore->dir_M_MegaFoci_Results()->path());

    //check if dir was selected
    if(QS_Save.isEmpty())
    {
        StatusSet("If you don't select a folder, i can't save the results i worked so hard for... " + QS_Fun_Sad);
        return false;
    }

    //set master save dir and cehck existance
    QDir DIR_Save(QS_Save);
    if(!DIR_Save.exists())
    {
        StatusSet("With unknown dark magic you managed to select a non existent directory " +  QS_Fun_Confused);
        return false;
    }

    //create sub dir
    size_t count = 0;
    do
    {
        DIR_MS4_Out_NucleiLifes.setPath(DIR_Save.path() + "/Results_Step4_" + QString::number(count));
        count++;
    }
    while(DIR_MS4_Out_NucleiLifes.exists());
    QDir().mkdir(DIR_MS4_Out_NucleiLifes.path());
    StatusSet("Set as save directory:\n" + DIR_MS4_Out_NucleiLifes.path());

    //save data
    StatusSet("Start saving data");
    bool ok = MS4_NucPedigree_AutoReconstruct.match_save_results(DIR_MS4_Out_NucleiLifes.path());
    if(ok)
        StatusSet("Saved data successfully " + QS_Fun_Happy);
    else
        StatusSet("Failed saving data " + QS_Fun_Sad);

    return ok;
}



void D_MAKRO_MegaFoci::MS4_DisplayRelativeScoreWeights()
{
    double sum = 0;
    sum += ui->doubleSpinBox_MS4_Score_Weight_Shift->value();
    sum += ui->doubleSpinBox_MS4_Score_Weight_Area->value();
    sum += ui->doubleSpinBox_MS4_Score_Weight_Convexity->value();
    sum += ui->doubleSpinBox_MS4_Score_Weight_Compactness->value();
    sum += ui->doubleSpinBox_MS4_Score_Weight_Mean_NUC->value();
    sum += ui->doubleSpinBox_MS4_Score_Weight_Mean_GFP->value();
    sum += ui->doubleSpinBox_MS4_Score_Weight_Mean_RFP->value();
    sum += ui->doubleSpinBox_MS4_Score_Weight_Std_NUC->value();
    sum += ui->doubleSpinBox_MS4_Score_Weight_Std_GFP->value();
    sum += ui->doubleSpinBox_MS4_Score_Weight_Std_RFP->value();

    double to_prz = 100.0 / sum;
    ui->doubleSpinBox_MS4_Score_Weight_Shift->setSuffix(" (" + QString::number(int(ui->doubleSpinBox_MS4_Score_Weight_Shift->value() * to_prz)) + "%)");
    ui->doubleSpinBox_MS4_Score_Weight_Area->setSuffix(" (" + QString::number(int(ui->doubleSpinBox_MS4_Score_Weight_Area->value() * to_prz)) + "%)");
    ui->doubleSpinBox_MS4_Score_Weight_Convexity->setSuffix(" (" + QString::number(int(ui->doubleSpinBox_MS4_Score_Weight_Convexity->value() * to_prz)) + "%)");
    ui->doubleSpinBox_MS4_Score_Weight_Compactness->setSuffix(" (" + QString::number(int(ui->doubleSpinBox_MS4_Score_Weight_Compactness->value() * to_prz)) + "%)");
    ui->doubleSpinBox_MS4_Score_Weight_Mean_NUC->setSuffix(" (" + QString::number(int(ui->doubleSpinBox_MS4_Score_Weight_Mean_NUC->value() * to_prz)) + "%)");
    ui->doubleSpinBox_MS4_Score_Weight_Mean_GFP->setSuffix(" (" + QString::number(int(ui->doubleSpinBox_MS4_Score_Weight_Mean_GFP->value() * to_prz)) + "%)");
    ui->doubleSpinBox_MS4_Score_Weight_Mean_RFP->setSuffix(" (" + QString::number(int(ui->doubleSpinBox_MS4_Score_Weight_Mean_RFP->value() * to_prz)) + "%)");
    ui->doubleSpinBox_MS4_Score_Weight_Std_NUC->setSuffix(" (" + QString::number(int(ui->doubleSpinBox_MS4_Score_Weight_Std_NUC->value() * to_prz)) + "%)");
    ui->doubleSpinBox_MS4_Score_Weight_Std_GFP->setSuffix(" (" + QString::number(int(ui->doubleSpinBox_MS4_Score_Weight_Std_GFP->value() * to_prz)) + "%)");
    ui->doubleSpinBox_MS4_Score_Weight_Std_RFP->setSuffix(" (" + QString::number(int(ui->doubleSpinBox_MS4_Score_Weight_Std_RFP->value() * to_prz)) + "%)");
}

bool D_MAKRO_MegaFoci::MS4_InitPedigree()
{
    state_MS4_pedigree_init = false;

    ///check, if data are loaded (reload if needed)
    if(!state_MS4_detections_loaded_to_pedigree)
    {
        StatusSet("Data missing -> Load data first");
        MS4_LoadDetectionsToPedigree();

        if(!state_MS4_detections_loaded_to_pedigree)
        {
            StatusSet("Failed loading missing data");
            return false;
        }
    }

    ///check, if reconstruction is finished (clean if needed)
    if(state_MS4_pedigree_reconstructed)
    {
        StatusSet("Reload data to get a clean pedigree");
        MS4_LoadDetectionsToPedigree();

        if(!state_MS4_detections_loaded_to_pedigree)
        {
            StatusSet("Failed reloading data");
            return false;
        }
    }
    state_MS4_pedigree_reconstructed = false;

    ///start pedigree reconstruction
    StatusSet("Init pedigree with reconstruction params");

    ///set scaling
    MS4_NucPedigree_AutoReconstruct.set_scale_T2h(ui->doubleSpinBox_MS4_Scale_T2h->value());
    MS4_NucPedigree_AutoReconstruct.set_scale_px2um(ui->doubleSpinBox_MS4_Scale_px2um->value());
    MS4_NucPedigree_AutoReconstruct.set_scale_nodes(ui->doubleSpinBox_MS4_Scale_Nodes->value() / 100.0);
    MS4_NucPedigree_AutoReconstruct.set_scale_edges(ui->doubleSpinBox_MS4_Scale_Edges->value() / 100.0);

    ///set border
    int border_px = ui->spinBox_MS4_PedigreeProp_TrackingBorderWidth->value();
    MS4_NucPedigree_AutoReconstruct.set_FrameInMargin_XY(
                border_px, ui->spinBox_MS4_PedigreeProp_OriginalImgSize_Full_X->value() - border_px,
                border_px, ui->spinBox_MS4_PedigreeProp_OriginalImgSize_Full_Y->value() - border_px);

    ///set mitoses starting rule
    MS4_NucPedigree_AutoReconstruct.set_earliest_mitoses_allowed(ui->spinBox_MS4_PedigreeProp_EarliestMitosisT->value());

    ///get maxima for norming from ui
    vector<double> vScoreMax(SCORE_NUMBER_OF, 1);
    vScoreMax[SCORE_SHIFT] = ui->doubleSpinBox_MS4_Score_Max_Shift->value();
    vScoreMax[SCORE_AREA] = ui->doubleSpinBox_MS4_Score_Max_Area->value();
    vScoreMax[SCORE_CONVEXITY] = ui->doubleSpinBox_MS4_Score_Max_Convexity->value();
    vScoreMax[SCORE_COMPACTNESS] = ui->doubleSpinBox_MS4_Score_Max_Compactness->value();
    vScoreMax[SCORE_MEAN_CH0] = ui->doubleSpinBox_MS4_Score_Max_Mean_NUC->value();
    vScoreMax[SCORE_MEAN_CH1] = ui->doubleSpinBox_MS4_Score_Max_Mean_GFP->value();
    vScoreMax[SCORE_MEAN_CH2] = ui->doubleSpinBox_MS4_Score_Max_Mean_RFP->value();
    vScoreMax[SCORE_STD_CH0] = ui->doubleSpinBox_MS4_Score_Max_Std_NUC->value();
    vScoreMax[SCORE_STD_CH1] = ui->doubleSpinBox_MS4_Score_Max_Std_GFP->value();
    vScoreMax[SCORE_STD_CH2] = ui->doubleSpinBox_MS4_Score_Max_Std_RFP->value();

    ///get weights from ui
    vector<double> vScoreWeight(SCORE_NUMBER_OF, 0);
    vScoreWeight[SCORE_SHIFT] = ui->doubleSpinBox_MS4_Score_Weight_Shift->value();
    vScoreWeight[SCORE_AREA] = ui->doubleSpinBox_MS4_Score_Weight_Area->value();
    vScoreWeight[SCORE_CONVEXITY] = ui->doubleSpinBox_MS4_Score_Weight_Convexity->value();
    vScoreWeight[SCORE_COMPACTNESS] = ui->doubleSpinBox_MS4_Score_Weight_Compactness->value();
    vScoreWeight[SCORE_MEAN_CH0] = ui->doubleSpinBox_MS4_Score_Weight_Mean_NUC->value();
    vScoreWeight[SCORE_MEAN_CH1] = ui->doubleSpinBox_MS4_Score_Weight_Mean_GFP->value();
    vScoreWeight[SCORE_MEAN_CH2] = ui->doubleSpinBox_MS4_Score_Weight_Mean_RFP->value();
    vScoreWeight[SCORE_STD_CH0] = ui->doubleSpinBox_MS4_Score_Weight_Std_NUC->value();
    vScoreWeight[SCORE_STD_CH1] = ui->doubleSpinBox_MS4_Score_Weight_Std_GFP->value();
    vScoreWeight[SCORE_STD_CH2] = ui->doubleSpinBox_MS4_Score_Weight_Std_RFP->value();

    ///init pedigree scores
    if(!MS4_NucPedigree_AutoReconstruct.initMatching(
                vScoreWeight,
                vScoreMax,
                ui->checkBox_MS4_Match_Thresh_Shift->isChecked() ? ui->doubleSpinBox_MS4_Match_Thres_Shift->value() : INFINITY,
                ui->checkBox_MS4_Match_Thresh_Area->isChecked() ? ui->doubleSpinBox_MS4_Match_Thres_MaxAreaIncrease->value() / 100 : INFINITY,
                ui->checkBox_MS4_Match_Thresh_Area->isChecked() ? ui->doubleSpinBox_MS4_Match_Thres_MaxAreaDecrease->value() / 100 : 0,
                35,
                ui->doubleSpinBox_MS4_Match_Thresh_Score_Tm1_Go1->value() / 100,
                ui->doubleSpinBox_MS4_Match_Thresh_Score_Tm2_Go1->value() / 100,
                ui->doubleSpinBox_MS4_Match_Thresh_Score_Tm3_Go1->value() / 100,
                ui->doubleSpinBox_MS4_Match_Thresh_Score_Tm1_Go2->value() / 100,
                ui->doubleSpinBox_MS4_Match_Thresh_Score_Tm2_Go2->value() / 100,
                ui->doubleSpinBox_MS4_Match_Thresh_Score_Tm3_Go2->value() / 100,
                ui->doubleSpinBox_MS4_Match_ScoreMultiplier_MitosisCorrection_Go1->value() / 100,
                ui->doubleSpinBox_MS4_Match_ScoreMultiplier_MitosisCorrection_Go2->value() / 100))
        return false;

    ///set plot viewer
    MS4_NucPedigree_AutoReconstruct.setPedigreeViewer_Plot3D(&MS4_Viewer_Pedigree_Plot3D);
    MS4_NucPedigree_AutoReconstruct.setPedigreeViewer_Volumetric(&MS4_Viewer_Pedigree_Volumetric);
    StatusSet("Successfully init nuclei pedigree");

    ///show peddigree plot
    if(!state_MS4_pedigree_init_1st_time)
        MS4_UpdatePedigreePlot();

    state_MS4_pedigree_init_1st_time = true;
    state_MS4_pedigree_init = true;
    ui->pushButton_MS4_SaveData->setEnabled(false);
    return true;
}

bool D_MAKRO_MegaFoci::MS4_ReconstructPedigree()
{
    this->setEnabled(false);

    StatusSet("Start reconstruction------------------------------");

    if(!MS4_InitPedigree())
    {
        StatusSet("Failed pedigree initialization");
        return false;
    }

    state_MS4_pedigree_reconstructed = false;

    size_t nt = MS4_NucPedigree_AutoReconstruct.size_T();

    //matching go 1
    StatusSet("Reconstruction start GO1 . . . . . . . . . . . .");
    for(size_t t = 1; t < nt; t++)
    {
        if(MS4_NucPedigree_AutoReconstruct.nuclei_blob_count(t) > 0)
        {
            StatusSet("Reconstruction GO1 (T=" + QString::number(t) + ")");
            MS4_NucPedigree_AutoReconstruct.match_time_go1(t);
            if(ui->radioButton_MS4_PedigreePlotUpdate_EachStep->isChecked())
                MS4_UpdatePedigreePlot();
        }
        else
        {
            //StatusSet("Reconstruction GO1 for (T=" + QString::number(t) + ") empty->skipped");
        }
    }

    if(ui->radioButton_MS4_PedigreePlotUpdate_GosAndCorrection->isChecked())
        MS4_UpdatePedigreePlot();

    //matching go 2
    StatusSet("Reconstruction start GO2 . . . . . . . . . . . .");
    for(size_t t = 1; t < nt; t++)
    {
        if(MS4_NucPedigree_AutoReconstruct.nuclei_blob_count(t) > 0)
        {
            StatusSet("Reconstruction GO2 (T=" + QString::number(t) + ")");
            MS4_NucPedigree_AutoReconstruct.match_time_go2(t);
            if(ui->radioButton_MS4_PedigreePlotUpdate_EachStep->isChecked())
                MS4_UpdatePedigreePlot();
        }
        else
        {
            //StatusSet("Reconstruction GO2 (T=" + QString::number(t) + ") empty->skipped");
        }
    }

    if(ui->radioButton_MS4_PedigreePlotUpdate_GosAndCorrection->isChecked())
        MS4_UpdatePedigreePlot();

    //matching correct mitosis go1
    StatusSet("Reconstruction start mitoses elimination . . . . . . . . .");
    for(size_t t = 1; t < nt; t++)
    {
        if(MS4_NucPedigree_AutoReconstruct.nuclei_blob_count(t) > 0)
        {
            StatusSet("Reconstruction mitoses elimination (T=" + QString::number(t) + ")");
            MS4_NucPedigree_AutoReconstruct.match_time_correct_mitosis_go1(t);
            if(ui->radioButton_MS4_PedigreePlotUpdate_EachStep->isChecked())
                MS4_UpdatePedigreePlot();
        }
        else
        {
            //StatusSet("Recon. correct mitoses (T=" + QString::number(t) + ") empty->skipped");
        }
    }

    /*
    //matching correct mitosis go2
    StatusSet("Reconstruction start mitoses changing . . . . . . . . .");
    for(size_t t = 1; t < nt; t++)
    {
        if(MS4_NucPedigree_AutoReconstruct.nuclei_blob_count(t) > 0)
        {
            StatusSet("Reconstruction mitoses changing (T=" + QString::number(t) + ")");
            MS4_NucPedigree_AutoReconstruct.match_time_correct_mitosis_go2(t);
            if(ui->radioButton_MS4_PedigreePlotUpdate_EachStep->isChecked())
                MS4_UpdatePedigreePlot();
        }
        else
        {
            //StatusSet("Recon. correct mitoses (T=" + QString::number(t) + ") empty->skipped");
        }
    }
    */

    if(ui->radioButton_MS4_PedigreePlotUpdate_GosAndCorrection->isChecked() || ui->radioButton_MS4_PedigreePlotUpdate_Finished->isChecked())
        MS4_UpdatePedigreePlot();

    StatusSet("Finish reconstruction------------------------------");
    state_MS4_pedigree_reconstructed = true;
    ui->pushButton_MS4_SaveData->setEnabled(true);
    this->setEnabled(true);

    return true;
}

bool D_MAKRO_MegaFoci::MS4_UpdatePedigreePlot()
{
    ///check conditions
    if(!state_MS4_detections_loaded_to_pedigree)
    {
        StatusSet("Failed plotting pedigree (no data)");
        return false;
    }
    StatusSet("Start plotting pedigree");

    ///set plot params
    MS4_NucPedigree_AutoReconstruct.set_scale_nodes(ui->doubleSpinBox_MS4_Scale_Nodes->value() / 100.0);
    MS4_NucPedigree_AutoReconstruct.set_scale_edges(ui->doubleSpinBox_MS4_Scale_Edges->value() / 100.0);

    ///plot
    int err;
    if(ui->tabWidget_MS4_PedigreeViewers->currentIndex() == 0)
    {
        err = MS4_NucPedigree_AutoReconstruct.updatePedigreeView_Plot3D(
                    ui->spinBox_MS4_PedigreeView_Param_Plot3D_DotsPerEdge->value(),
                    size_t(ui->doubleSpinBox_MS4_PedigreeView_Param_Plot3D_ROI_T_min->value()),
                    size_t(ui->doubleSpinBox_MS4_PedigreeView_Param_Plot3D_ROI_T_max->value()),
                    ui->doubleSpinBox_MS4_PedigreeView_Param_Plot3D_ROI_Y_min->value(),
                    ui->doubleSpinBox_MS4_PedigreeView_Param_Plot3D_ROI_Y_max->value(),
                    ui->doubleSpinBox_MS4_PedigreeView_Param_Plot3D_ROI_X_min->value(),
                    ui->doubleSpinBox_MS4_PedigreeView_Param_Plot3D_ROI_X_max->value());
    }
    else
    {
        MS4_CalcVolumetricView_Memory();
        err = MS4_NucPedigree_AutoReconstruct.updatePedigreeView_Volumetric(
                    ui->spinBox_MS4_PedigreeView_Param_Volumetric_AllVolumeSize_T->value(),
                    ui->spinBox_MS4_PedigreeView_Param_Volumetric_AllVolumeSize_Y->value(),
                    ui->spinBox_MS4_PedigreeView_Param_Volumetric_AllVolumeSize_X->value(),
                    ui->spinBox_MS4_PedigreeView_Param_Volumetric_ObjectSize_Node->value(),
                    ui->spinBox_MS4_PedigreeView_Param_Volumetric_ObjectSize_Edge->value(),
                    ui->spinBox_MS4_PedigreeProp_OriginalImgSize_Full_Y->value(),
                    ui->spinBox_MS4_PedigreeProp_OriginalImgSize_Full_X->value());
    }

    if(err != ER_okay)
    {
        StatusSet("failed plotting pedigree");
        return false;
    }

    ///finish
    StatusSet("Successfully plotted pedigree");
    return true;
}

void D_MAKRO_MegaFoci::MS4_CalcVolumetricView_Memory()
{
    int sub_t = ui->spinBox_MS4_PedigreeView_Param_Volumetric_SubVolumeSize_T->value();
    int sub_y = ui->spinBox_MS4_PedigreeView_Param_Volumetric_SubVolumeSize_Y->value();
    int sub_x = ui->spinBox_MS4_PedigreeView_Param_Volumetric_SubVolumeSize_X->value();

    int all_t = int(sub_t * dataset_dim_t);
    int all_y = int(sub_y * dataset_dim_mosaic_y);
    int all_x = int(sub_x * dataset_dim_mosaic_x);

    ui->spinBox_MS4_PedigreeView_Param_Volumetric_AllVolumeSize_T->setValue(all_t);
    ui->spinBox_MS4_PedigreeView_Param_Volumetric_AllVolumeSize_Y->setValue(all_y);
    ui->spinBox_MS4_PedigreeView_Param_Volumetric_AllVolumeSize_X->setValue(all_x);

    int all_px = all_t * all_y * all_x;
    double all_B = all_px * 4.0;
    double all_KB = all_B / 1024;
    double all_MB = all_KB / 1024;

    ui->doubleSpinBox_MS4_PedigreeView_Param_Memory->setValue(all_MB);
}

void D_MAKRO_MegaFoci::MS4_CalcOriginalMosaicSize()
{
    ui->spinBox_MS4_PedigreeProp_OriginalImgSize_Full_X->setValue(ui->spinBox_MS4_PedigreeProp_OriginalImgSize_Single_X->value() * dataset_dim_mosaic_x);
    ui->spinBox_MS4_PedigreeProp_OriginalImgSize_Full_Y->setValue(ui->spinBox_MS4_PedigreeProp_OriginalImgSize_Single_Y->value() * dataset_dim_mosaic_y);
}

void D_MAKRO_MegaFoci::on_pushButton_MS4_LoadData_clicked()
{
    MS4_LoadData();
}

void D_MAKRO_MegaFoci::on_pushButton_MS4_SaveData_clicked()
{
    MS4_SaveData();
}

void D_MAKRO_MegaFoci::on_pushButton_MS4_StartPedigreeReconstruction_clicked()
{
    MS4_ReconstructPedigree();
}

void D_MAKRO_MegaFoci::on_pushButton_MS4_UpdatePedigreeView_clicked()
{
    MS4_UpdatePedigreePlot();
}

void D_MAKRO_MegaFoci::on_spinBox_MS4_PedigreeView_Param_Volumetric_SubVolumeSize_X_valueChanged(int arg1)
{
    MS4_CalcVolumetricView_Memory();
}

void D_MAKRO_MegaFoci::on_spinBox_MS4_PedigreeView_Param_Volumetric_SubVolumeSize_Y_valueChanged(int arg1)
{
    MS4_CalcVolumetricView_Memory();
}

void D_MAKRO_MegaFoci::on_spinBox_MS4_PedigreeView_Param_Volumetric_SubVolumeSize_T_valueChanged(int arg1)
{
    MS4_CalcVolumetricView_Memory();
}

void D_MAKRO_MegaFoci::on_spinBox_MS4_PedigreeProp_OriginalImgSize_Single_X_valueChanged(int arg1)
{
    MS4_CalcOriginalMosaicSize();
}

void D_MAKRO_MegaFoci::on_spinBox_MS4_PedigreeProp_OriginalImgSize_Single_Y_valueChanged(int arg1)
{
    MS4_CalcOriginalMosaicSize();
}

void D_MAKRO_MegaFoci::on_checkBox_MS4_Score_AdvancedSettings_clicked(bool checked)
{
    ui->doubleSpinBox_MS4_Score_Max_Area->setEnabled(checked);
    ui->doubleSpinBox_MS4_Score_Max_Convexity->setEnabled(checked);
    ui->doubleSpinBox_MS4_Score_Max_Compactness->setEnabled(checked);
    ui->doubleSpinBox_MS4_Score_Max_Mean_NUC->setEnabled(checked);
    ui->doubleSpinBox_MS4_Score_Max_Mean_GFP->setEnabled(checked);
    ui->doubleSpinBox_MS4_Score_Max_Mean_RFP->setEnabled(checked);
    ui->doubleSpinBox_MS4_Score_Max_Std_NUC->setEnabled(checked);
    ui->doubleSpinBox_MS4_Score_Max_Std_GFP->setEnabled(checked);
    ui->doubleSpinBox_MS4_Score_Max_Std_RFP->setEnabled(checked);

    ui->doubleSpinBox_MS4_Score_Weight_Area->setEnabled(checked);
    ui->doubleSpinBox_MS4_Score_Weight_Convexity->setEnabled(checked);
    ui->doubleSpinBox_MS4_Score_Weight_Compactness->setEnabled(checked);
    ui->doubleSpinBox_MS4_Score_Weight_Mean_NUC->setEnabled(checked);
    ui->doubleSpinBox_MS4_Score_Weight_Mean_GFP->setEnabled(checked);
    ui->doubleSpinBox_MS4_Score_Weight_Mean_RFP->setEnabled(checked);
    ui->doubleSpinBox_MS4_Score_Weight_Std_NUC->setEnabled(checked);
    ui->doubleSpinBox_MS4_Score_Weight_Std_GFP->setEnabled(checked);
    ui->doubleSpinBox_MS4_Score_Weight_Std_RFP->setEnabled(checked);
}




void D_MAKRO_MegaFoci::MS5_UiInit()
{
    if(mode_major_current != MODE_MAJOR_5_MANU_CORRECT_PEDIGREE)
        return;

    //viewers
    MS5_Viewer_T0.set_GV(ui->graphicsView_MS5_ViewT0);
    MS5_Viewer_T1.set_GV(ui->graphicsView_MS5_ViewT1);
    MS5_Viewer_T2.set_GV(ui->graphicsView_MS5_ViewT2);
    MS5_Viewer_T3.set_GV(ui->graphicsView_MS5_ViewT3);
    MS5_Viewer_T4.set_GV(ui->graphicsView_MS5_ViewT4);
    //vieer vectors
    v_MS5_Viewers_T.resize(MS5_ViewersCount);
    v_MS5_Viewers_T[0] = &MS5_Viewer_T0;
    v_MS5_Viewers_T[1] = &MS5_Viewer_T1;
    v_MS5_Viewers_T[2] = &MS5_Viewer_T2;
    v_MS5_Viewers_T[3] = &MS5_Viewer_T3;
    v_MS5_Viewers_T[4] = &MS5_Viewer_T4;

    //labels
   v_MS5_ViewerLabels_T.resize(MS5_ViewersCount);
   v_MS5_ViewerLabels_T[0] = ui->label_MS5_ViewT0;
   v_MS5_ViewerLabels_T[1] = ui->label_MS5_ViewT1;
   v_MS5_ViewerLabels_T[2] = ui->label_MS5_ViewT2;
   v_MS5_ViewerLabels_T[3] = ui->label_MS5_ViewT3;
   v_MS5_ViewerLabels_T[4] = ui->label_MS5_ViewT4;

   //imgs to show
   v_MS5_MAs_ShowBasic.resize(MS5_ViewersCount, Mat::zeros(1, 1, CV_8UC1));
   v_MS5_MAs_ShowHighlight.resize(MS5_ViewersCount, Mat::zeros(1, 1, CV_8UC1));

   //connects

   //show img (basic change)
   connect(ui->spinBox_MS5_T_start,                 SIGNAL(valueChanged(int)),              this,   SLOT(MS5_UpdateImages_Basic()));
   connect(ui->spinBox_MS5_T_size,                  SIGNAL(valueChanged(int)),              this,   SLOT(MS5_UpdateImages_Basic()));
   connect(ui->spinBox_MS5_Y_start,                 SIGNAL(valueChanged(int)),              this,   SLOT(MS5_UpdateImages_Basic()));
   connect(ui->spinBox_MS5_Y_size,                  SIGNAL(valueChanged(int)),              this,   SLOT(MS5_UpdateImages_Basic()));
   connect(ui->spinBox_MS5_X_start,                 SIGNAL(valueChanged(int)),              this,   SLOT(MS5_UpdateImages_Basic()));
   connect(ui->spinBox_MS5_X_size,                  SIGNAL(valueChanged(int)),              this,   SLOT(MS5_UpdateImages_Basic()));
   connect(ui->spinBox_MS5_Viewers_Thickness,       SIGNAL(valueChanged(int)),              this,   SLOT(MS5_UpdateImages_Basic()));
   connect(ui->checkBox_MS5_Viewer_DIC,             SIGNAL(clicked(bool)),                  this,   SLOT(MS5_UpdateImages_Basic()));
   connect(ui->checkBox_MS5_Viewer_GFP,             SIGNAL(clicked(bool)),                  this,   SLOT(MS5_UpdateImages_Basic()));
   connect(ui->checkBox_MS5_Viewer_RFP,             SIGNAL(clicked(bool)),                  this,   SLOT(MS5_UpdateImages_Basic()));
   connect(ui->checkBox_MS5_Viewer_ContoursParent,  SIGNAL(clicked(bool)),                  this,   SLOT(MS5_UpdateImages_Basic()));
   connect(ui->checkBox_MS5_Viewer_ContoursCurrent, SIGNAL(clicked(bool)),                  this,   SLOT(MS5_UpdateImages_Basic()));
   connect(ui->checkBox_MS5_Viewer_ContoursChilds,  SIGNAL(clicked(bool)),                  this,   SLOT(MS5_UpdateImages_Basic()));
   connect(ui->checkBox_MS5_Viewer_ShiftsParent,    SIGNAL(clicked(bool)),                  this,   SLOT(MS5_UpdateImages_Basic()));
   connect(ui->checkBox_MS5_Viewer_ShiftsChilds,    SIGNAL(clicked(bool)),                  this,   SLOT(MS5_UpdateImages_Basic()));
   connect(ui->checkBox_MS5_Viewer_AgeText,         SIGNAL(clicked(bool)),                  this,   SLOT(MS5_UpdateImages_Basic()));
   connect(ui->checkBox_MS5_Viewer_ColorInfo,       SIGNAL(clicked(bool)),                  this,   SLOT(MS5_UpdateImages_Basic()));

   //show img (change highlighting)
   connect(&MS5_Viewer_T0,                          SIGNAL(MouseClicked_Pos(int, int)),     this,   SLOT(MS5_NucleiHighlight_Select_Viewer0(int, int)));
   connect(&MS5_Viewer_T1,                          SIGNAL(MouseClicked_Pos(int, int)),     this,   SLOT(MS5_NucleiHighlight_Select_Viewer1(int, int)));
   connect(&MS5_Viewer_T2,                          SIGNAL(MouseClicked_Pos(int, int)),     this,   SLOT(MS5_NucleiHighlight_Select_Viewer2(int, int)));
   connect(&MS5_Viewer_T3,                          SIGNAL(MouseClicked_Pos(int, int)),     this,   SLOT(MS5_NucleiHighlight_Select_Viewer3(int, int)));
   connect(&MS5_Viewer_T4,                          SIGNAL(MouseClicked_Pos(int, int)),     this,   SLOT(MS5_NucleiHighlight_Select_Viewer4(int, int)));
   connect(&MS5_Viewer_T0,                          SIGNAL(MouseMoved_Pos(int, int)),       this,   SLOT(MS5_NucleiHighlight_Hover_Viewer0(int, int)));
   connect(&MS5_Viewer_T1,                          SIGNAL(MouseMoved_Pos(int, int)),       this,   SLOT(MS5_NucleiHighlight_Hover_Viewer1(int, int)));
   connect(&MS5_Viewer_T2,                          SIGNAL(MouseMoved_Pos(int, int)),       this,   SLOT(MS5_NucleiHighlight_Hover_Viewer2(int, int)));
   connect(&MS5_Viewer_T3,                          SIGNAL(MouseMoved_Pos(int, int)),       this,   SLOT(MS5_NucleiHighlight_Hover_Viewer3(int, int)));
   connect(&MS5_Viewer_T4,                          SIGNAL(MouseMoved_Pos(int, int)),       this,   SLOT(MS5_NucleiHighlight_Hover_Viewer4(int, int)));

   //event recording
   connect(&MS5_Viewer_T0,                          SIGNAL(MouseClicked_Pos(int, int)),     this,   SLOT(MS5_EventToS2_GetClick_v0(int, int)));
   connect(&MS5_Viewer_T1,                          SIGNAL(MouseClicked_Pos(int, int)),     this,   SLOT(MS5_EventToS2_GetClick_v1(int, int)));
   connect(&MS5_Viewer_T2,                          SIGNAL(MouseClicked_Pos(int, int)),     this,   SLOT(MS5_EventToS2_GetClick_v2(int, int)));
   connect(&MS5_Viewer_T3,                          SIGNAL(MouseClicked_Pos(int, int)),     this,   SLOT(MS5_EventToS2_GetClick_v3(int, int)));
   connect(&MS5_Viewer_T4,                          SIGNAL(MouseClicked_Pos(int, int)),     this,   SLOT(MS5_EventToS2_GetClick_v4(int, int)));

   //connected zoom in viewers
   for(size_t v = 1; v < MS5_ViewersCount; v++)
       v_MS5_Viewers_T[0]->connect_Zoom(v_MS5_Viewers_T[v]);

   //highlighted nuclei
   v_MS5_pNuc_Highlighted.resize(MS5_NUC_HIGHLIGHT_NUMBER_OF, nullptr);
}

bool D_MAKRO_MegaFoci::MS5_LoadAll()
{
    if(mode_major_current != MODE_MAJOR_5_MANU_CORRECT_PEDIGREE)
        return false;

    if(!MS5_LoadDirs())
    {
        StatusSet("Failed loading directories " + QS_Fun_Sad);
        return false;
    }

    if(!MS5_LoadMosaics())
    {
        StatusSet("Failed loading mosaics " + QS_Fun_Sad);
        return false;
    }

    if(!MS5_LoadNucleiData())
    {
        StatusSet("Failed loading nuclei data " + QS_Fun_Sad);
        return false;
    }

    if(!MS5_LoadNucleiLifes())
    {
        StatusSet("Failed loading nuclei lifes " + QS_Fun_Sad);
        return false;
    }

    //states
    MS5_state_loaded_all = true;
    StatusSet("Loaded all needed data " + QS_Fun_Happy);

    //ui
    ui->pushButton_MS5_DataLoad->setEnabled(false);
    ui->pushButton_MS5_DataSave->setEnabled(true);
    ui->pushButton_MS5_SaveViewportImageStack->setEnabled(true);
    ui->groupBox_MS5_Viewport->setEnabled(true);
    ui->groupBox_MS5_Events_toS2->setEnabled(true);
    ui->groupBox_MS5_Events_S5intern->setEnabled(true);
    ui->groupBox_MS5_Editing->setEnabled(true);
    ui->groupBox_MS5_ViewersSettings->setEnabled(true);

    //show
    MS5_UpdateImages_Basic();

    //count events
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();

    //finish
    return true;
}

bool D_MAKRO_MegaFoci::MS5_LoadDirs()
{
    if(mode_major_current != MODE_MAJOR_5_MANU_CORRECT_PEDIGREE)
        return false;

    //------------------ mosaics ------------------------------------------------

    StatusSet("Please select results directory from step 1 (for mosaics).");
    QString QS_LoadMS1 = QFileDialog::getExistingDirectory(
                this,
                "Please select results folder of step 1 you want to load mosaics from (must beginn with 'Results_Step1_').",
                pStore->dir_M_MegaFoci_Results()->path());

    //check if dir was selected
    if(QS_LoadMS1.isEmpty())
    {
        StatusSet("Well, you should select a folder... Wasn't that clear?");
        return false;
    }

    //check, if dir is results from step 1
    if(!QS_LoadMS1.contains("Results_Step1"))
    {
        StatusSet("You should selct results from step 1...\n" + QS_Fun_TableFlip);
        return false;
    }

    //master dir in
    DIR_MS5_Load_Mosaics.setPath(QS_LoadMS1 + "/Mosaik");
    if(!DIR_MS5_Load_Mosaics.exists())
    {
        StatusSet("The selected directory doesn't contain a 'Mosaik' directory. " + QS_Fun_Confused);
        return false;
    }

    //save input dir
    QDir DIR_parent(QS_LoadMS1);
    DIR_parent.cdUp();
    pStore->set_dir_M_MegaFoci_Results(DIR_parent.path());

    //------------------ nuclei data ------------------------------------------------

    StatusSet("Please select results directory from step 3 (for nuclei data).");
    QString QS_LoadMS3 = QFileDialog::getExistingDirectory(
                this,
                "Please select results folder of step 3 you want to load nuclei data from (must beginn with 'Results_Step3_').",
                pStore->dir_M_MegaFoci_Results()->path());

    //check if dir was selected
    if(QS_LoadMS3.isEmpty())
    {
        StatusSet("Well, you should select a folder... Wasn't that clear?");
        return false;
    }

    //check, if dir is results from step 3
    if(!QS_LoadMS3.contains("Results_Step3"))
    {
        StatusSet("You should selct results from step 3...\n" + QS_Fun_TableFlip);
        return false;
    }

    //master dir in
    DIR_MS5_Load_NucleiData.setPath(QS_LoadMS3 + "/DetectionsAssigned");
    if(!DIR_MS5_Load_NucleiData.exists())
    {
        StatusSet("The selected directory doesn't contain a 'DetectionsAssigned' directory. " + QS_Fun_Confused);
        return false;
    }

    //save input dir
    DIR_parent.setPath(QS_LoadMS3);
    DIR_parent.cdUp();
    pStore->set_dir_M_MegaFoci_Results(DIR_parent.path());

    //------------------ nuclei lifes ------------------------------------------------

    StatusSet("Please select results directory from step 4 or 5 (for nuclei lifes).");
    QString QS_LoadMS4_5 = QFileDialog::getExistingDirectory(
                this,
                "Please select results folder of step 4 or 5 you want to load nuclei lifes from (must beginn with 'Results_Step4_' or 'Results_Step5_').",
                pStore->dir_M_MegaFoci_Results()->path());

    //check if dir was selected
    if(QS_LoadMS4_5.isEmpty())
    {
        StatusSet("Well, you should select a folder... Wasn't that clear?");
        return false;
    }

    //check, if dir is results from step 4 or 5
    if(!QS_LoadMS4_5.contains("Results_Step4") && !QS_LoadMS4_5.contains("Results_Step5"))
    {
        StatusSet("You should selct results from step 4 or 5...\n" + QS_Fun_TableFlip);
        return false;
    }

    //master dir in
    DIR_MS5_Load_NucleiLifes.setPath(QS_LoadMS4_5);
    if(!DIR_MS5_Load_NucleiLifes.exists())
    {
        StatusSet("With unknown dark magic you selected a not existing directory. " + QS_Fun_Confused);
        return false;
    }

    //save input dir
    DIR_parent.setPath(QS_LoadMS4_5);
    DIR_parent.cdUp();
    pStore->set_dir_M_MegaFoci_Results(DIR_parent.path());

    //------------------ finished ------------------------------------------------

    MS5_state_loaded_dirs = true;
    return true;
}

bool D_MAKRO_MegaFoci::MS5_LoadMosaics()
{
    if(mode_major_current != MODE_MAJOR_5_MANU_CORRECT_PEDIGREE)
        return false;
    if(!MS5_state_loaded_dirs)
        return false;

    StatusSet("Start loading mosaics");

    //clear and resize container
    vv_MS5_Mosaics_CT.clear();
    vv_MS5_Mosaics_CT.resize(MS5_MOSAIC_CH_NUMBER_OF);

    //loop mosaic channels
    for(size_t c = 0; c < MS5_MOSAIC_CH_NUMBER_OF; c++)
    {
        //channel name
        QString QS_ChName = QSL_MS5_MosaicChannels[int(c)];

        //dir
        QDir DIR_MosaicChannel(DIR_MS5_Load_Mosaics.path() + "/" + QS_ChName);
        if(!DIR_MosaicChannel.exists())
        {
            StatusSet("Mosaic directory not found:\n" + DIR_MosaicChannel.path());
            return false;
        }

        //imgs in dir
        QFileInfoList FIL_Imgs = DIR_MosaicChannel.entryInfoList();
        for(int i = 0; i < FIL_Imgs.size(); i++)
        {
            //img
            QFileInfo FI_Img = FIL_Imgs[i];
            //qDebug() << "------------------------------------------------";
            //qDebug() << FI_Img;

            //is png
            if(FI_Img.suffix() == "png")
            {
                //qDebug() << "is .png";

                //contains correct text in file name
                if(FI_Img.baseName().contains("Mosaik_" + QS_ChName + "_T"))
                {
                    //qDebug() << "base name fits" << FI_Img.baseName();

                    //get time index
                    bool ok;
                    //qDebug() << "looking for t index" << FI_Img.baseName().right(FI_Img.baseName().size() - 9 - QS_ChName.length());
                    int t = FI_Img.baseName().right(FI_Img.baseName().size() - 9 - QS_ChName.length()).toInt(&ok);
                    if(ok)
                    {
                        //qDebug() << "got t" << t;

                        //correct size of container
                        while(t >= int(vv_MS5_Mosaics_CT[c].size()))
                            vv_MS5_Mosaics_CT[c].push_back(Mat::zeros(1, 1, CV_8UC1));

                        //read img
                        D_Img_Proc::Load_From_Path(
                                    &(vv_MS5_Mosaics_CT[c][t]),
                                    FI_Img.absoluteFilePath());

                        //qDebug() << "read" << FI_Img;
                    }
                }
            }
        }
    }

    MS5_state_loaded_mosaics = true;
    StatusSet("Successfully loaded mosaics");
    return true;
}

bool D_MAKRO_MegaFoci::MS5_LoadNucleiData()
{
    if(mode_major_current != MODE_MAJOR_5_MANU_CORRECT_PEDIGREE)
        return false;

    if(!MS5_state_loaded_dirs)
        return false;

    StatusSet("Start loading nuclei data from step 3");

    //parent dir of detections
    QDir DIR_ParentMS3(DIR_MS5_Load_NucleiData);
    DIR_ParentMS3.cdUp();

    //load data
    bool ok = MS5_NucPedigree_Editing.load_nuclei_data(
                DIR_ParentMS3.path(),
                DIR_MS5_Load_NucleiData.path(),
                dataset_dim_t, dataset_dim_mosaic_y, dataset_dim_mosaic_x,
                false,
                true);

    if(ok)
    {
        StatusSet("Finished loading nuclei data from step 3");
        MS5_state_loaded_nuc_data = true;
        return true;
    }
    else
    {
        StatusSet("FAILED loading nuclei data from step 3");
        MS5_state_loaded_nuc_data = false;
        return false;
    }
}

bool D_MAKRO_MegaFoci::MS5_LoadNucleiLifes()
{
    if(mode_major_current != MODE_MAJOR_5_MANU_CORRECT_PEDIGREE)
        return false;
    if(!MS5_state_loaded_dirs || !MS5_state_loaded_nuc_data)
        return false;

    StatusSet("Start loading nuclei matches from step 4/5");

    //load data
    bool ok = MS5_NucPedigree_Editing.match_load_matches(DIR_MS5_Load_NucleiLifes.path());


    if(ok)
    {
        StatusSet("Finished loading nuclei matches from step 4/5");
        MS5_state_loaded_nuc_lifes = true;
        return true;
    }
    else
    {
        StatusSet("FAILED loading nuclei matches from step 4/5");
        MS5_state_loaded_nuc_lifes = false;
        return false;
    }
}

bool D_MAKRO_MegaFoci::MS5_SaveData()
{
    if(mode_major_current != MODE_MAJOR_5_MANU_CORRECT_PEDIGREE)
        return false;

    StatusSet("Please select directory to save step 5 results in");
    QString QS_Save = QFileDialog::getExistingDirectory(
                this,
                "Please select directory to save step 5 results in ('Results_5_*' folder is created automatically)",
                pStore->dir_M_MegaFoci_Results()->path());

    //check if dir was selected
    if(QS_Save.isEmpty())
    {
        StatusSet("If you don't select a folder, i can't save the results we worked so hard for... " + QS_Fun_Sad);
        return false;
    }

    //set master save dir and cehck existance
    QDir DIR_Save(QS_Save);
    if(!DIR_Save.exists())
    {
        StatusSet("With unknown dark magic you managed to select a non existent directory " +  QS_Fun_Confused);
        return false;
    }

    //create sub dir
    size_t count = 0;
    do
    {
        DIR_MS5_Out_NucleiLifes.setPath(DIR_Save.path() + "/Results_Step5_" + QString::number(count));
        count++;
    }
    while(DIR_MS5_Out_NucleiLifes.exists());
    QDir().mkdir(DIR_MS5_Out_NucleiLifes.path());
    StatusSet("Set as save directory:\n" + DIR_MS5_Out_NucleiLifes.path());

    //save data
    StatusSet("Start saving data");
    bool ok = MS5_NucPedigree_Editing.match_save_results(DIR_MS5_Out_NucleiLifes.path());
    if(ok)
        StatusSet("Saved data successfully " + QS_Fun_Happy);
    else
        StatusSet("Failed saving data " + QS_Fun_Sad);

    return ok;
}

bool D_MAKRO_MegaFoci::MS5_SaveImgStack()
{
    if(!MS5_state_imgs_shown_at_lesast_once)
        return false;

    if(mode_major_current != MODE_MAJOR_5_MANU_CORRECT_PEDIGREE)
        return false;

    StatusSet("Please select directory to save image stack in");
    QString QS_Save = QFileDialog::getExistingDirectory(
                this,
                "Please select directory to save image stack in (subfolder is created automatically)",
                pStore->dir_M_MegaFoci_Results()->path());

    //check if dir was selected
    if(QS_Save.isEmpty())
    {
        StatusSet("If you don't select a folder, i can't save the results i worked so hard for... " + QS_Fun_Sad);
        return false;
    }

    //name of subfolder
    QString QS_Name = QInputDialog::getText(
                this,
                "Name of Sunfolder",
                "Please enter name of subfolder to save images in ('MosaikStack_Step5_' will be appended at the beginnig)",
                QLineEdit::Normal,
                "Name");
    QS_Name = "MosaikStack_Step5_" + QS_Name;
    QString QS_NameWithNumber = QS_Name;

    //create sub dir
    QDir DIR_Save(QS_Save + "/" + QS_Name);
    size_t count = 1;
    while(DIR_Save.exists())
    {
        QS_NameWithNumber = QS_Name + "_" + QString::number(count);
        DIR_Save.setPath(QS_Save + "/" + QS_NameWithNumber);
        count++;
    }
    while(DIR_Save.exists());
    QDir().mkdir(DIR_Save.path());

    //save data
    StatusSet("Start saving image mosaic");
    for(int t = 0; t <= ui->spinBox_MS5_T_start->maximum(); t++)
    {
        ui->spinBox_MS5_T_start->setValue(t);
        Update_Ui();
        MS5_Viewer_T0.Save_Image(DIR_Save.path() + "/" + QS_NameWithNumber + "_T" + QString::number(t) + ".png");
    }
    MS5_Viewer_T1.Save_Image(DIR_Save.path() + "/" + QS_NameWithNumber + "_T" + QString::number(ui->spinBox_MS5_T_start->maximum() + 1) + ".png");
    MS5_Viewer_T2.Save_Image(DIR_Save.path() + "/" + QS_NameWithNumber + "_T" + QString::number(ui->spinBox_MS5_T_start->maximum() + 2) + ".png");
    MS5_Viewer_T3.Save_Image(DIR_Save.path() + "/" + QS_NameWithNumber + "_T" + QString::number(ui->spinBox_MS5_T_start->maximum() + 3) + ".png");
    MS5_Viewer_T4.Save_Image(DIR_Save.path() + "/" + QS_NameWithNumber + "_T" + QString::number(ui->spinBox_MS5_T_start->maximum() + 4) + ".png");
    StatusSet("Saved image mosaic");

    return true;
}

void D_MAKRO_MegaFoci::MS5_UpdateImages_Basic()
{
    if(mode_major_current != MODE_MAJOR_5_MANU_CORRECT_PEDIGREE)
        return;

    if(!MS5_state_loaded_all)
        return;

    //show images in diffrent threads
    vector<std::thread> vThreadsMatch(MS5_ViewersCount);
    for(size_t v = 0; v < MS5_ViewersCount; v++)
        vThreadsMatch[v] = std::thread(
                    MS5_CalcImage_Thread,
                    &(v_MS5_MAs_ShowBasic[v]),
                    &vv_MS5_Mosaics_CT,
                    &MS5_NucPedigree_Editing,
                    size_t(ui->spinBox_MS5_T_start->value() + v),
                    size_t(ui->spinBox_MS5_Y_start->value()),
                    size_t(ui->spinBox_MS5_Y_size->value()),
                    size_t(ui->spinBox_MS5_X_start->value()),
                    size_t(ui->spinBox_MS5_X_size->value()),
                    ui->checkBox_MS5_Viewer_DIC->isChecked(),
                    ui->checkBox_MS5_Viewer_GFP->isChecked(),
                    ui->checkBox_MS5_Viewer_RFP->isChecked(),
                    ui->checkBox_MS5_Viewer_ContoursParent->isChecked(),
                    ui->checkBox_MS5_Viewer_ContoursCurrent->isChecked(),
                    ui->checkBox_MS5_Viewer_ContoursChilds->isChecked(),
                    ui->checkBox_MS5_Viewer_ShiftsParent->isChecked(),
                    ui->checkBox_MS5_Viewer_ShiftsChilds->isChecked(),
                    ui->checkBox_MS5_Viewer_AgeText->isChecked(),
                    ui->checkBox_MS5_Viewer_ColorInfo->isChecked(),
                    dataset_dim_mosaic_y,
                    dataset_dim_mosaic_x,
                    ui->spinBox_MS5_Viewers_Thickness->value(),
                    ui->doubleSpinBox_OverviewQuality->value() / 100.0);

    //join and show
    for(size_t v = 0; v < MS5_ViewersCount; v++)
    {
        vThreadsMatch[v].join();
        v_MS5_Viewers_T[v]->Update_Image();
        v_MS5_ViewerLabels_T[v]->setText("T=" + QString::number(ui->spinBox_MS5_T_start->value() + v));
    }

    MS5_state_imgs_shown_at_lesast_once = true;
    MS5_UpdateImages_Highlight();
}

void D_MAKRO_MegaFoci::MS5_UpdateImages_Highlight()
{
    //qDebug() << "MS5_UpdateImages_Highlight" << "start";

    if(!MS5_state_imgs_shown_at_lesast_once)    return;
    if(v_MS5_MAs_ShowBasic.empty())             return;
    if(v_MS5_MAs_ShowBasic[0].empty())          return;
    //qDebug() << "MS5_UpdateImages_Highlight" << "error checks passed";

    //copy base img
    for(size_t i = 0; i < v_MS5_MAs_ShowBasic.size(); i++)
        v_MS5_MAs_ShowHighlight[i] = v_MS5_MAs_ShowBasic[i].clone();

    //image size params
    size_t w_full_px    = vv_MS5_Mosaics_CT[0][0].cols;
    size_t h_full_px    = vv_MS5_Mosaics_CT[0][0].rows;
    double x_mosaic2px  = double(w_full_px) / double(dataset_dim_mosaic_x);
    double y_mosaic2px  = double(h_full_px) / double(dataset_dim_mosaic_y);
    size_t x_start_px   = ui->spinBox_MS5_X_start->value() * x_mosaic2px;
    size_t y_start_px   = ui->spinBox_MS5_Y_start->value() * y_mosaic2px;

    //scale and offset
    double scale = ui->doubleSpinBox_OverviewQuality->value() / 100.0;
    Point P_Offset_px_scaled(x_start_px, y_start_px);

    //drawing thickness
    int thickness = ui->spinBox_MS5_Viewers_Thickness->value();
    int thick1 = max(1, thickness / 2);
    int thick2 = max(thick1 + 1, thickness);

    //highlight selected nuclei
    for(size_t h = 0; h < MS5_NUC_HIGHLIGHT_NUMBER_OF; h++)
    {
        //nuc
        D_Bio_NucleusBlob* pNucHightlight = v_MS5_pNuc_Highlighted[h];

        //found nuc to highlight?
        if(pNucHightlight != nullptr)
        {
            //calc time and viewer index
            int t_main = pNucHightlight->time_index();
            int v_main = t_main - ui->spinBox_MS5_T_start->value();
            //qDebug() << "MS5_UpdateImages_Highlight" << "hovered v/t" << v_main << t_main;

            //hovered or selected
            if(h == MS5_NUC_HIGHLIGHT_HOVERED)
            {
                //qDebug() << "hovered";
                //hovered -----------------------------------------------------------------

                //color
                QColor col_bright = QColor(192, 192, 0  );
                QColor col_dark = QColor(0,   0,   0  );

                //qDebug() << "MS5_UpdateImages_Highlight" << "found a nuc to highlight here :-) center x/y" << pNucHovered->centroid(scale, -P_Offset_px_scaled).x << pNucDraw->centroid(scale, -P_Offset_px_scaled).y;

                //time window
                size_t t_min = ui->spinBox_MS5_T_start->value();
                size_t t_max = int(t_min) + ui->spinBox_MS5_T_size->value() - 1;

                //nucs to draw
                vector<D_Bio_NucleusBlob*> vpNucsToDraw;
                vector<size_t> vKinshipDegrees;
                MS5_FindConnectedNucsToDraw(
                            &vpNucsToDraw,
                            &vKinshipDegrees,
                            pNucHightlight,
                            0, dataset_dim_t,
                            0);

                //draw nucs
                for(size_t i = 0; i < vpNucsToDraw.size(); i++)
                {
                    //Nuc
                    D_Bio_NucleusBlob* pNucDraw = vpNucsToDraw[i];
                    size_t kinship_degree = vKinshipDegrees[i];

                    //time and viewer
                    int t = int(pNucDraw->time_index());
                    int v = t - ui->spinBox_MS5_T_start->value();

                    //seen in viewer?
                    if(v >= 0 && v < int(MS5_ViewersCount))
                    {
                        switch (kinship_degree) {

                        case 0:
                        {
                            //draw nuc outer
                            D_Img_Proc::Draw_Contour(
                                        &(v_MS5_MAs_ShowHighlight[v]),
                                        vpNucsToDraw[i]->contour(scale, -P_Offset_px_scaled),
                                        thick1 * 5,
                                        col_bright.red(), col_bright.green(), col_bright.blue());
                        }
                            break;

                        case 1:
                        {
                            //draw nuc outer
                            D_Img_Proc::Draw_Contour(
                                        &(v_MS5_MAs_ShowHighlight[v]),
                                        vpNucsToDraw[i]->contour(scale, -P_Offset_px_scaled),
                                        thick1 * 5,
                                        col_bright.red(), col_bright.green(), col_bright.blue());

                            //draw nuc inner
                            D_Img_Proc::Draw_Contour(
                                        &(v_MS5_MAs_ShowHighlight[v]),
                                        vpNucsToDraw[i]->contour(scale, -P_Offset_px_scaled),
                                        thick1 * 2,
                                        col_dark.red(), col_dark.green(), col_dark.blue());
                        }
                            break;

                        default:
                        {
                            //draw nuc outer
                            D_Img_Proc::Draw_Contour(
                                        &(v_MS5_MAs_ShowHighlight[v]),
                                        vpNucsToDraw[i]->contour(scale, -P_Offset_px_scaled),
                                        thick1 * 5,
                                        col_bright.red(), col_bright.green(), col_bright.blue());

                            //draw nuc middle
                            D_Img_Proc::Draw_Contour(
                                        &(v_MS5_MAs_ShowHighlight[v]),
                                        vpNucsToDraw[i]->contour(scale, -P_Offset_px_scaled),
                                        thick1 * 3,
                                        col_dark.red(), col_dark.green(), col_dark.blue());

                            //draw nuc inner
                            D_Img_Proc::Draw_Contour(
                                        &(v_MS5_MAs_ShowHighlight[v]),
                                        vpNucsToDraw[i]->contour(scale, -P_Offset_px_scaled),
                                        thick1 * 1,
                                        col_bright.red(), col_bright.green(), col_bright.blue());
                        }
                            break;
                        }
                    }
                }

                //qDebug() << "hoverd" << "end";
            }
            else
            {
                //qDebug() << "selected/other";
                //selected/other -----------------------------------------------------------------

                //color
                QColor col = QColor(255, 255, 0);

                //seen in viewer?
                if(v_main >= 0 && v_main < int(MS5_ViewersCount))
                {
                    //draw nuc
                    //qDebug() << "MS5_UpdateImages_Highlight" << "draw main";
                    D_Img_Proc::Draw_Contour(
                                &(v_MS5_MAs_ShowHighlight[v_main]),
                                pNucHightlight->contour(scale, -P_Offset_px_scaled),
                                thick2 * 2,
                                col.red(), col.green(), col.blue());
                }

                //highlight parent
                if(pNucHightlight->matching_foundParent())
                {
                    //calc time and viewer index
                    int t = int(pNucHightlight->matching_Parent()->time_index());
                    int v = t - ui->spinBox_MS5_T_start->value();
                    //qDebug() << "MS5_UpdateImages_Highlight" << "parent v/t" << v << t;

                    //seen in viewer?
                    if(v >= 0 && v < int(MS5_ViewersCount))
                    {
                        //draw nuc
                        //qDebug() << "MS5_UpdateImages_Highlight" << "draw parent";
                        D_Img_Proc::Draw_Contour(
                                    &(v_MS5_MAs_ShowHighlight[v]),
                                    pNucHightlight->contour(scale, -P_Offset_px_scaled),
                                    thick1,
                                    col.red(), col.green(), col.blue());
                    }
                }

                //highlight child1
                if(pNucHightlight->matching_foundChild1())
                {
                    //calc time and viewer index
                    int t = int(pNucHightlight->matching_Child1()->time_index());
                    int v = t - ui->spinBox_MS5_T_start->value();
                    //qDebug() << "MS5_UpdateImages_Highlight" << "child1 v/t" << v << t;

                    //seen in viewer?
                    if(v >= 0 && v < int(MS5_ViewersCount))
                    {
                        //draw nuc
                        //qDebug() << "MS5_UpdateImages_Highlight" << "draw child1";
                        D_Img_Proc::Draw_Contour(
                                    &(v_MS5_MAs_ShowHighlight[v]),
                                    pNucHightlight->contour(scale, -P_Offset_px_scaled),
                                    thick1,
                                    col.red(), col.green(), col.blue());
                    }
                }

                //highlight child2
                if(pNucHightlight->matching_foundChild2())
                {
                    //calc time and viewer index
                    int t = int(pNucHightlight->matching_Child2()->time_index());
                    int v = t - ui->spinBox_MS5_T_start->value();
                    //qDebug() << "MS5_UpdateImages_Highlight" << "child2 v/t" << v << t;

                    //seen in viewer?
                    if(v >= 0 && v < int(MS5_ViewersCount))
                    {
                        //draw nuc
                        //qDebug() << "MS5_UpdateImages_Highlight" << "draw child2";
                        D_Img_Proc::Draw_Contour(
                                    &(v_MS5_MAs_ShowHighlight[v]),
                                    pNucHightlight->contour(scale, -P_Offset_px_scaled),
                                    thick1,
                                    col.red(), col.green(), col.blue());
                    }
                }

                //qDebug() << "selected/other" << "end";
            }
        }
    }

    //Event
    if(MS5_EventS5intern_EventActive)
    {
        //qDebug() << "---------------------------------------------";

        //draw params
        QColor event_color(
                    ui->spinBox_MS5_Events_S5intern_Draw_Red->value(),
                    ui->spinBox_MS5_Events_S5intern_Draw_Green->value(),
                    ui->spinBox_MS5_Events_S5intern_Draw_Blue->value());
        int event_radius = ui->spinBox_MS5_Events_S5intern_Draw_Radius->value();
        int event_thickness = ui->spinBox_MS5_Events_S5intern_Draw_Thickness->value();

        //event pos
        int event_t_h           = ui->spinBox_MS5_Events_S5intern_Pos_T->value();
        int event_y_px_original = ui->spinBox_MS5_Events_S5intern_Pos_Y->value();
        int event_x_px_original = ui->spinBox_MS5_Events_S5intern_Pos_X->value();
        //qDebug() << "event pos" << event_x_px_original << event_y_px_original;

        //size mosaic
        int sx_mosaic = vv_MS5_Mosaics_CT[0][0].cols;
        int sy_mosaic = vv_MS5_Mosaics_CT[0][0].rows;
        //qDebug() << "size mosaic" << sx_mosaic << sy_mosaic;

        //size original
        int sx_original = int(sx_mosaic / scale);
        int sy_original = int(sy_mosaic / scale);
        //qDebug() << "size original" << sx_original << sy_original;

        //event pos rel
        double event_x_rel = double(event_x_px_original) / double(sx_original);
        double event_y_rel = double(event_y_px_original) / double(sy_original);
        //qDebug() << "event pos rel" << event_x_rel << event_y_rel;

        //event mosaic coords
        int event_mx = min(int(event_x_rel * dataset_dim_mosaic_x), int(dataset_dim_mosaic_x));
        int event_my = min(int(event_y_rel * dataset_dim_mosaic_y), int(dataset_dim_mosaic_y));
        //qDebug() << "event mosaic coords" << event_mx << event_my;

        //vp min
        int vp_min_mx = ui->spinBox_MS5_X_start->value();
        int vp_min_my = ui->spinBox_MS5_Y_start->value();
        //qDebug() << "vp min" << vp_min_mx << vp_min_my;

        //vp size
        int vp_size_mx = ui->spinBox_MS5_X_size->value();
        int vp_size_my = ui->spinBox_MS5_Y_size->value();
        //qDebug() << "vp size" << vp_size_mx << vp_size_my;

        //vp max
        int vp_max_mx = vp_min_mx + vp_size_mx - 1;
        int vp_max_my = vp_min_my + vp_size_my - 1;
        //qDebug() << "vp max" << vp_max_mx << vp_max_my;

        if(event_mx >= vp_min_mx && event_mx <= vp_max_mx)
        {
            if(event_my >= vp_min_my && event_my <= vp_max_my)
            {
                for(size_t v = 0; v < MS5_ViewersCount; v++)
                {
                    //viewer time
                    int viewer_t = ui->spinBox_MS5_T_start->value() + v;

                    if(viewer_t == event_t_h)
                    {
                        //event pos in mosaic px coordinates
                        int event_x_px_mosaic = int(event_x_rel * sx_mosaic);
                        int event_y_px_mosaic = int(event_y_rel * sy_mosaic);
                        //qDebug() << "event pos in mosaic px coordinates" << event_x_px_mosaic << event_y_px_mosaic;

                        //offset vp
                        int vp_px_offset_x = int((double(vp_min_mx) / double(dataset_dim_mosaic_x)) * sx_mosaic);
                        int vp_px_offset_y = int((double(vp_min_my) / double(dataset_dim_mosaic_y)) * sy_mosaic);
                        //qDebug() << "offset vp" << vp_px_offset_x << vp_px_offset_y;

                        //event pos in vp
                        int event_x_px_vp = min(v_MS5_MAs_ShowHighlight[v].cols - 1, max(0, event_x_px_mosaic - vp_px_offset_x));
                        int event_y_px_vp = min(v_MS5_MAs_ShowHighlight[v].rows - 1, max(0, event_y_px_mosaic - vp_px_offset_y));
                        //qDebug() << "event pos in vp" << event_x_px_vp << event_y_px_vp;

                        D_Img_Proc::Draw_Circle(
                                    &(v_MS5_MAs_ShowHighlight[v]),
                                    event_x_px_vp,
                                    event_y_px_vp,
                                    event_radius,
                                    event_color.red(),
                                    event_color.green(),
                                    event_color.blue(),
                                    event_thickness,
                                    false);

                        //qDebug() << "---------------------------------------------";
                    }
                }
            }
        }
    }

    //show
    //qDebug() << "MS5_UpdateImages_Highlight" << "show";
    for(size_t v = 0; v < MS5_ViewersCount; v++)
    {
        v_MS5_Viewers_T[v]->Update_Image(&(v_MS5_MAs_ShowHighlight[v]));
    }

    //qDebug() << "MS5_UpdateImages_Highlight" << "end";

    MS5_Editing_SelectionCheck();
    MS5_Editing_ConnectionCheck();
}

void D_MAKRO_MegaFoci::MS5_FindConnectedNucsToDraw(vector<D_Bio_NucleusBlob *> *pvpNucs, vector<size_t> *pvKinshipDegrees, D_Bio_NucleusBlob *pNucCheck, size_t t_min, size_t t_max, size_t kinship_degree)
{
    //invalid?
    if(pNucCheck == nullptr)
        return;

    //allready added?
    for(size_t i = 0; i < pvpNucs->size(); i++)
        if(pNucCheck == (*pvpNucs)[i])
            return;

    //out of time window?
    size_t t_check = pNucCheck->time_index();
    if(t_check < t_min || t_check > t_max)
        return;

    //add
    pvpNucs->push_back(pNucCheck);
    pvKinshipDegrees->push_back(kinship_degree);

    //parent?
    if(pNucCheck->matching_foundParent())
        MS5_FindConnectedNucsToDraw(
                    pvpNucs,
                    pvKinshipDegrees,
                    pNucCheck->matching_Parent(),
                    t_min,
                    t_max,
                    pNucCheck->matching_Parent()->matching_isMitosis() ? kinship_degree + 1 : kinship_degree);

    //child1?
    if(pNucCheck->matching_foundChild1())
        MS5_FindConnectedNucsToDraw(
                    pvpNucs,
                    pvKinshipDegrees,
                    pNucCheck->matching_Child1(),
                    t_min,
                    t_max,
                    pNucCheck->matching_isMitosis() ? kinship_degree + 1 : kinship_degree);

    //child2?
    if(pNucCheck->matching_foundChild2())
        MS5_FindConnectedNucsToDraw(
                    pvpNucs,
                    pvKinshipDegrees,
                    pNucCheck->matching_Child2(),
                    t_min,
                    t_max,
                    pNucCheck->matching_isMitosis() ? kinship_degree + 1 : kinship_degree);
}

bool D_MAKRO_MegaFoci::MS5_CoordTransform_MosaicPx_2_OriginalPx(int *x, int *y)
{
    //qDebug() << "MS5_CoordTransform_MosaicPx_2_OriginalPx" << "x/y in" << *x << *y;

    if(!MS5_state_imgs_shown_at_lesast_once)
        return false;

    if(vv_MS5_Mosaics_CT.empty())
        return false;

    if(vv_MS5_Mosaics_CT[0].empty())
        return false;

    //mosaic pos
    int x_min_mosaic = ui->spinBox_MS5_X_start->value();
    int y_min_mosaic = ui->spinBox_MS5_Y_start->value();

    //image size params
    size_t w_full_px    = vv_MS5_Mosaics_CT[0][0].cols;
    size_t h_full_px    = vv_MS5_Mosaics_CT[0][0].rows;
    double x_mosaic2px  = double(w_full_px) / double(dataset_dim_mosaic_x);
    double y_mosaic2px  = double(h_full_px) / double(dataset_dim_mosaic_y);
    size_t x_start_px   = x_min_mosaic * x_mosaic2px;
    size_t y_start_px   = y_min_mosaic * y_mosaic2px;

    //scale and offset
    double scale = ui->doubleSpinBox_OverviewQuality->value() / 100.0;
    //qDebug() << "MS5_CoordTransform_MosaicPx_2_OriginalPx" << "scale" << scale;
    Point P_Offset_px_scaled(x_start_px, y_start_px);
    //qDebug() << "MS5_CoordTransform_MosaicPx_2_OriginalPx" << "x/y offset" << x_start_px << y_start_px;

    if(scale == 0.0)
        return false;

    //shift x/y
    *x += P_Offset_px_scaled.x;
    *y += P_Offset_px_scaled.y;

    //scale x/y
    *x /= scale;
    *y /= scale;

    //qDebug() << "MS5_CoordTransform_MosaicPx_2_OriginalPx" << "x/y out" << *x << *y;
    return true;
}

void D_MAKRO_MegaFoci::MS5_NucleiHighlight_Select_Viewer0(int x, int y)
{
    MS5_NucleiHighlight_Select(x, y, ui->spinBox_MS5_T_start->value() + 0);
}

void D_MAKRO_MegaFoci::MS5_NucleiHighlight_Select_Viewer1(int x, int y)
{
    MS5_NucleiHighlight_Select(x, y, ui->spinBox_MS5_T_start->value() + 1);
}

void D_MAKRO_MegaFoci::MS5_NucleiHighlight_Select_Viewer2(int x, int y)
{
    MS5_NucleiHighlight_Select(x, y, ui->spinBox_MS5_T_start->value() + 2);
}

void D_MAKRO_MegaFoci::MS5_NucleiHighlight_Select_Viewer3(int x, int y)
{
    MS5_NucleiHighlight_Select(x, y, ui->spinBox_MS5_T_start->value() + 3);
}

void D_MAKRO_MegaFoci::MS5_NucleiHighlight_Select_Viewer4(int x, int y)
{
    MS5_NucleiHighlight_Select(x, y, ui->spinBox_MS5_T_start->value() + 4);
}

void D_MAKRO_MegaFoci::MS5_NucleiHighlight_Hover_Viewer0(int x, int y)
{
    MS5_NucleiHighlight_Hover(x, y, ui->spinBox_MS5_T_start->value() + 0);
}

void D_MAKRO_MegaFoci::MS5_NucleiHighlight_Hover_Viewer1(int x, int y)
{
    MS5_NucleiHighlight_Hover(x, y, ui->spinBox_MS5_T_start->value() + 1);
}

void D_MAKRO_MegaFoci::MS5_NucleiHighlight_Hover_Viewer2(int x, int y)
{
    MS5_NucleiHighlight_Hover(x, y, ui->spinBox_MS5_T_start->value() + 2);
}

void D_MAKRO_MegaFoci::MS5_NucleiHighlight_Hover_Viewer3(int x, int y)
{
    MS5_NucleiHighlight_Hover(x, y, ui->spinBox_MS5_T_start->value() + 3);
}

void D_MAKRO_MegaFoci::MS5_NucleiHighlight_Hover_Viewer4(int x, int y)
{
    MS5_NucleiHighlight_Hover(x, y, ui->spinBox_MS5_T_start->value() + 4);
}

void D_MAKRO_MegaFoci::MS5_NucleiHighlight_Select(int x, int y, size_t t)
{
    if(!MS5_state_imgs_shown_at_lesast_once)
        return;

    if(MS5_EventToS2_Recording)
        return;

    if(!MS5_CoordTransform_MosaicPx_2_OriginalPx(&x, &y))
        return;

    D_Bio_NucleusBlob* pNucSelected = MS5_NucPedigree_Editing.get_pNucleus(
                t,
                max(0, int(ui->spinBox_MS5_Y_start->value()) - 1),
                max(0, int(ui->spinBox_MS5_X_start->value()) - 1),
                ui->spinBox_MS5_Y_start->value() + ui->spinBox_MS5_Y_size->value(),
                ui->spinBox_MS5_X_start->value() + ui->spinBox_MS5_X_size->value(),
                y,
                x);

    if(pNucSelected != nullptr)
    {
        if(v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT1] == nullptr)
        {
            v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT1] = pNucSelected;
        }
        else
        {
            if(v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT1]->time_index() != pNucSelected->time_index())
            {
                v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT2] = pNucSelected;
            }
            else
            {
                StatusSet("Can't select nucleus (both at T=" + QString::number(pNucSelected->time_index()) + ")");
            }
        }
    }

    MS5_UpdateImages_Highlight();
}

void D_MAKRO_MegaFoci::MS5_NucleiHighlight_Hover(int x, int y, size_t t)
{
    if(!MS5_state_imgs_shown_at_lesast_once)
        return;

    if(!MS5_CoordTransform_MosaicPx_2_OriginalPx(&x, &y))
        return;

    v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_HOVERED] = MS5_NucPedigree_Editing.get_pNucleus(
                t,
                max(0, int(ui->spinBox_MS5_Y_start->value()) - 1),
                max(0, int(ui->spinBox_MS5_X_start->value()) - 1),
                ui->spinBox_MS5_Y_start->value() + ui->spinBox_MS5_Y_size->value(),
                ui->spinBox_MS5_X_start->value() + ui->spinBox_MS5_X_size->value(),
                y,
                x);

    MS5_UpdateImages_Highlight();
}

bool D_MAKRO_MegaFoci::MS5_Editing_SelectionCheck()
{
    if(!MS5_state_imgs_shown_at_lesast_once)
        return false;

    bool selected = v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT1] != nullptr || v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT2] != nullptr;

    ui->pushButton_MS5_Editing_ForgetSelection->setEnabled(selected);
    return selected;
}

void D_MAKRO_MegaFoci::MS5_Editing_SelectionForget()
{
    if(!MS5_state_imgs_shown_at_lesast_once)
        return;

    v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT1] = nullptr;
    v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT2] = nullptr;

    MS5_Editing_SelectionCheck();
    MS5_Editing_ConnectionCheck();

    MS5_UpdateImages_Highlight();
}

void D_MAKRO_MegaFoci::MS5_Editing_ConnectionCheck()
{
    if(!MS5_state_imgs_shown_at_lesast_once)
        return;

    D_Bio_NucleusBlob* pNuc1        = v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT1];
    D_Bio_NucleusBlob* pNuc2        = v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT2];

    size_t selected_nucs = 0;
    if(pNuc1 != nullptr)    selected_nucs++;
    if(pNuc2 != nullptr)    selected_nucs++;

    if(selected_nucs == 1)
    {
        D_Bio_NucleusBlob* pNucSelected = pNuc1 != nullptr ? pNuc1 : pNuc2;
        ui->pushButton_MS5_Editing_Include->setEnabled(pNucSelected->matching_excluded_this());
        ui->pushButton_MS5_Editing_Exclude->setEnabled(!pNucSelected->matching_excluded_life());
    }
    else
    {
        ui->pushButton_MS5_Editing_Exclude->setEnabled(false);
        ui->pushButton_MS5_Editing_Include->setEnabled(false);
    }

    if(selected_nucs < 2)
    {
        ui->pushButton_MS5_Editing_ConnectionCreate->setEnabled(false);
        ui->pushButton_MS5_Editing_ConnectionDelete->setEnabled(false);
        return;
    }

    D_Bio_NucleusBlob* pNucOlder    = pNuc1->time_index() < pNuc2->time_index() ? pNuc1 : pNuc2;
    D_Bio_NucleusBlob* pNucYounger  = pNuc1->time_index() > pNuc2->time_index() ? pNuc1 : pNuc2;

    bool connected = pNuc1->matching_isConnectedTo(pNuc2);
    bool connection_possible = pNucOlder->matching_foundAtMostOneChild() && pNucYounger->matching_foundNoParent();

    ui->pushButton_MS5_Editing_ConnectionCreate->setEnabled(!connected && connection_possible);
    ui->pushButton_MS5_Editing_ConnectionDelete->setEnabled(connected);
}

bool D_MAKRO_MegaFoci::MS5_Editing_ConnectionCreate()
{
    if(!MS5_state_imgs_shown_at_lesast_once)
        return false;

    D_Bio_NucleusBlob* pNuc1 = v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT1];
    D_Bio_NucleusBlob* pNuc2 = v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT2];

    if(pNuc1 == nullptr || pNuc2 == nullptr)
        return false;

    D_Bio_NucleusBlob* pNucOlder    = pNuc1->time_index() < pNuc2->time_index() ? pNuc1 : pNuc2;
    D_Bio_NucleusBlob* pNucYounger  = pNuc1->time_index() > pNuc2->time_index() ? pNuc1 : pNuc2;

    bool connected = pNuc1->matching_isConnectedTo(pNuc2);
    bool connection_possible = !connected && pNucOlder->matching_foundAtMostOneChild() && pNucYounger->matching_foundNoParent();

    if(!connection_possible)
        return false;

    pNucYounger->matching_SetAsParent(pNucOlder, 1);

    MS5_Editing_SelectionForget();
    MS5_UpdateImages_Basic();

    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();

    return true;
}

bool D_MAKRO_MegaFoci::MS5_Editing_ConnectionDelete()
{
    if(!MS5_state_imgs_shown_at_lesast_once)
        return false;

    D_Bio_NucleusBlob* pNuc1 = v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT1];
    D_Bio_NucleusBlob* pNuc2 = v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT2];

    if(pNuc1 == nullptr || pNuc2 == nullptr)
        return false;

    D_Bio_NucleusBlob* pNucOlder    = pNuc1->time_index() < pNuc2->time_index() ? pNuc1 : pNuc2;
    D_Bio_NucleusBlob* pNucYounger  = pNuc1->time_index() > pNuc2->time_index() ? pNuc1 : pNuc2;

    bool connected = pNucOlder->matching_isConnectedTo(pNucYounger);

    if(!connected)
        return false;

    pNucOlder->matching_RemoveChild(pNucYounger);
    pNucYounger->matching_RemoveParent(pNucOlder);

    MS5_Editing_SelectionForget();
    MS5_UpdateImages_Basic();

    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();

    return true;
}

bool D_MAKRO_MegaFoci::MS5_Editing_Include()
{
    if(!MS5_state_imgs_shown_at_lesast_once)
        return false;

    D_Bio_NucleusBlob* pNuc1        = v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT1];
    D_Bio_NucleusBlob* pNuc2        = v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT2];

    size_t selected_nucs = 0;
    if(pNuc1 != nullptr)    selected_nucs++;
    if(pNuc2 != nullptr)    selected_nucs++;

    if(selected_nucs != 1)
        return false;

    D_Bio_NucleusBlob* pNucSelected = pNuc1 != nullptr ? pNuc1 : pNuc2;

    if(!pNucSelected->matching_excluded_this())
        return false;

    pNucSelected->matching_set_excluded(false);

    MS5_Editing_SelectionForget();
    MS5_UpdateImages_Basic();

    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();

    return true;
}

bool D_MAKRO_MegaFoci::MS5_Editing_Exclude()
{
    if(!MS5_state_imgs_shown_at_lesast_once)
        return false;

    D_Bio_NucleusBlob* pNuc1        = v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT1];
    D_Bio_NucleusBlob* pNuc2        = v_MS5_pNuc_Highlighted[MS5_NUC_HIGHLIGHT_SELECT2];

    size_t selected_nucs = 0;
    if(pNuc1 != nullptr)    selected_nucs++;
    if(pNuc2 != nullptr)    selected_nucs++;

    if(selected_nucs != 1)
        return false;

    D_Bio_NucleusBlob* pNucSelected = pNuc1 != nullptr ? pNuc1 : pNuc2;

    if(pNucSelected->matching_excluded_life())
        return false;

    pNucSelected->matching_set_excluded(true);

    MS5_Editing_SelectionForget();
    MS5_UpdateImages_Basic();

    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();

    return true;
}

void D_MAKRO_MegaFoci::MS5_EventToS2_SetList()
{
    if(MS5_EventToS2_FileSet)
        return;

    QString QS_Save = QFileDialog::getSaveFileName(
                this,
                "Save location event list",
                pStore->dir_M_MegaFoci_Results()->path() + "/EventList_S5toS2_" + QDateTime::currentDateTime().toString(QS_DateTimeFormat_YearToSec) + ".txt",
                "Textfiles (*.txt)");

    if(QS_Save.isEmpty())
        return;

    pStore->set_dir_M_MegaFoci_Results(QS_Save);
    MS5_EventToS2_File.setFile(QS_Save);
    MS5_EventToS2_FileSet = true;

    MS5_EventToS2_Events.clear();

    if(MS5_EventToS2_File.exists())
    {
        QFile F_EventList(MS5_EventToS2_File.absoluteFilePath());
        if(!F_EventList.open(QIODevice::ReadOnly))
            return;

        QTextStream TS_EventList(&F_EventList);

        while(!TS_EventList.atEnd())
            MS5_EventToS2_Events.append(TS_EventList.readLine());

        StatusSet("Event list file read:\n" + MS5_EventToS2_File.absoluteFilePath());
    }
    else
    {
        //init
        MS5_EventToS2_Events.append("Event list S5->S2");                                               //0
        MS5_EventToS2_Events.append("Path;"             + MS5_EventToS2_File.absoluteFilePath());       //1
        MS5_EventToS2_Events.append("ImageD version;"   + D_QS_Version + "(" + D_QS_Release + ")");     //2
        MS5_EventToS2_Events.append("Saved;"            + QDateTime::currentDateTime().toString());     //3
        MS5_EventToS2_Events.append("");                                                                //4
        MS5_EventToS2_Events.append("t;y;x;r;comment;status");                                          //5

        StatusSet("Event list file set:\n" + MS5_EventToS2_File.absoluteFilePath());
    }
}

void D_MAKRO_MegaFoci::MS5_EventToS2_Start()
{
    if(!MS5_EventToS2_FileSet)
        MS5_EventToS2_SetList();
    if(!MS5_EventToS2_FileSet)
        return;

    if(MS5_EventToS2_Recording)
        return;

    MS5_EventToS2_Recording = true;
    MS5_EventToS2_ClicksRecorded = 0;
    ui->pushButton_MS5_EventS2_RecordStart->setEnabled(false);
    ui->pushButton_MS5_EventS2_RecordStop->setEnabled(true);

     StatusSet("Click to select event center");
}

void D_MAKRO_MegaFoci::MS5_EventToS2_Stop()
{
    if(!MS5_EventToS2_FileSet)
        return;

    MS5_EventToS2_Recording = false;
    MS5_EventToS2_ClicksRecorded = 0;
    ui->pushButton_MS5_EventS2_RecordStart->setEnabled(true);
    ui->pushButton_MS5_EventS2_RecordStop->setEnabled(false);
}

void D_MAKRO_MegaFoci::MS5_EventToS2_GetClick_v0(int x, int y)
{
    MS5_EventToS2_GetClick(x, y, ui->spinBox_MS5_T_start->value() + 0);
}

void D_MAKRO_MegaFoci::MS5_EventToS2_GetClick_v1(int x, int y)
{
    MS5_EventToS2_GetClick(x, y, ui->spinBox_MS5_T_start->value() + 1);
}

void D_MAKRO_MegaFoci::MS5_EventToS2_GetClick_v2(int x, int y)
{
    MS5_EventToS2_GetClick(x, y, ui->spinBox_MS5_T_start->value() + 2);
}

void D_MAKRO_MegaFoci::MS5_EventToS2_GetClick_v3(int x, int y)
{
    MS5_EventToS2_GetClick(x, y, ui->spinBox_MS5_T_start->value() + 3);
}

void D_MAKRO_MegaFoci::MS5_EventToS2_GetClick_v4(int x, int y)
{
    MS5_EventToS2_GetClick(x, y, ui->spinBox_MS5_T_start->value() + 4);
}

void D_MAKRO_MegaFoci::MS5_EventToS2_GetClick(int x, int y, size_t t)
{
    if(!MS5_EventToS2_FileSet)
        return;

    if(!MS5_EventToS2_Recording)
        return;

    if(!MS5_CoordTransform_MosaicPx_2_OriginalPx(&x, &y))
        return;

    if(MS5_EventToS2_ClicksRecorded == 0)
    {
        MS5_EventToS2_Click_Point       = Point(x, y);
        MS5_EventToS2_Click_Time        = t;
        MS5_EventToS2_ClicksRecorded    = 1;
        StatusSet("Click to select event radius");
    }
    else if(MS5_EventToS2_ClicksRecorded == 1)
    {
        MS5_EventToS2_Click_Radius      = D_Math::Distance(Point(x, y), MS5_EventToS2_Click_Point);
        MS5_EventToS2_ClicksRecorded    = 2;
        MS5_EventToS2_AddEvent();
    }
}

void D_MAKRO_MegaFoci::MS5_EventToS2_AddEvent()
{
    if(!MS5_EventToS2_FileSet)
        MS5_EventToS2_SetList();
    if(!MS5_EventToS2_FileSet)
        return;

    if(!MS5_EventToS2_Recording)
        return;

    QString QS_Comment = "S5_manually_recorded";
    if(ui->checkBox_MS5_EventS2_AddComment->isChecked())
        QS_Comment = QInputDialog::getText(
                    this,
                    "Enter event comment",
                    "Comment:",
                    QLineEdit::EchoMode::Normal,
                    QS_Comment);

    MS5_EventToS2_Events.append(
                QString::number(MS5_EventToS2_Click_Time) + ";" +
                QString::number(MS5_EventToS2_Click_Point.y) + ";" +
                QString::number(MS5_EventToS2_Click_Point.x) + ";" +
                QString::number(int(MS5_EventToS2_Click_Radius)) + ";" +
                QS_Comment + ";" +
                "ToDo");

    MS5_EventToS2_SaveEventList();
    MS5_EventToS2_Stop();

    StatusSet("Event saved:\n"
              "T=" + QString::number(MS5_EventToS2_Click_Time) +
              " Y=" + QString::number(MS5_EventToS2_Click_Point.y) +
              " X=" + QString::number(MS5_EventToS2_Click_Point.x) +
              " R=" + QString::number(int(MS5_EventToS2_Click_Radius)) +
              " " + QS_Comment);
}

void D_MAKRO_MegaFoci::MS5_EventToS2_SaveEventList()
{
    if(!MS5_EventToS2_FileSet)
        MS5_EventToS2_SetList();
    if(!MS5_EventToS2_FileSet)
        return;

    if(!MS5_EventToS2_Recording)
        return;

    ofstream OS;
    OS.open(MS5_EventToS2_File.absoluteFilePath().toStdString());
    if(!OS.is_open())
        return;

    for(int l = 0; l < MS5_EventToS2_Events.size(); l++)
    {
        if(l > 0)
            OS << "\n";
        OS << MS5_EventToS2_Events[l].toStdString();
    }

    OS.close();
}

void D_MAKRO_MegaFoci::MS5_EventS5intern_JumpToNext()
{
    vector<int> vType_Search = {
        ui->checkBox_MS5_Events_S5intern_LargeDist->isChecked()                     ? 1 : 0,
        ui->checkBox_MS5_Events_S5intern_Mitosis->isChecked()                       ? 1 : 0,
        ui->checkBox_MS5_Events_S5intern_Excluded->isChecked()                      ? 1 : 0,
        ui->checkBox_MS5_Events_S5intern_ShortTracking_Isolated->isChecked()        ? 1 : 0,
        ui->checkBox_MS5_Events_S5intern_ShortTracking_LooseStart->isChecked()      ? 1 : 0,
        ui->checkBox_MS5_Events_S5intern_ShortTracking_LooseEnd->isChecked()        ? 1 : 0,
        ui->checkBox_MS5_Events_S5intern_ShortTracking_BetweenMitoses->isChecked()  ? 1 : 0
    };

    vector<int> vType_Param = {
        ui->spinBox_MS5_Events_S5intern_LargeDist_Dist->value(),
        0,
        0,
        ui->spinBox_MS5_Events_S5intern_ShortTracking_Isolated_Duration->value(),
        ui->spinBox_MS5_Events_S5intern_ShortTracking_LooseStart_Duration->value(),
        ui->spinBox_MS5_Events_S5intern_ShortTracking_LooseEnd_Duration->value(),
        ui->spinBox_MS5_Events_S5intern_ShortTracking_BetweenMitoses_Duration->value()
    };

    bool filter_use_t_after         = ui->checkBox_Events_S5intern_EventConstraints_AfterT->isChecked();
    int  filter_param_t_after       = ui->spinBox_Events_S5intern_EventConstraints_AfterT_Time->value();
    bool filter_use_t_before        = ui->checkBox_Events_S5intern_EventConstraints_BeforeT->isChecked();
    int  filter_param_t_before      = ui->spinBox_Events_S5intern_EventConstraints_BeforeT_Time->value();
    bool filter_use_border          = ui->checkBox_Events_S5intern_EventConstraints_NotBorder->isChecked();
    int  filter_param_border        = ui->spinBox_Events_S5intern_EventConstraints_NotBorder_Size->value();
    bool filter_use_mosaic          = ui->checkBox_Events_S5intern_EventConstraints_Mosaik->isChecked();
    int  filter_param_mosaic_x      = ui->spinBox_Events_S5intern_EventConstraints_Mosaik_MaxX->value();
    int  filter_param_mosaic_y      = ui->spinBox_Events_S5intern_EventConstraints_Mosaik_MaxY->value();
    bool filter_no_excluded         = ui->checkBox_Events_S5intern_EventConstraints_NoExcluded->isChecked();

    bool filter_use_range           = filter_use_border || filter_use_mosaic;
    int filter_param_x_min          = 0;
    int filter_param_y_min          = 0;
    int filter_param_x_max          = int(double(vv_MS5_Mosaics_CT[0][0].cols) / (ui->doubleSpinBox_OverviewQuality->value() / 100.0));
    int filter_param_y_max          = int(double(vv_MS5_Mosaics_CT[0][0].rows) / (ui->doubleSpinBox_OverviewQuality->value() / 100.0));
    if(filter_use_mosaic)
    {
        filter_param_x_max          = int(filter_param_x_max * (double(filter_param_mosaic_x) / double(dataset_dim_mosaic_x)));
        filter_param_y_max          = int(filter_param_y_max * (double(filter_param_mosaic_y) / double(dataset_dim_mosaic_y)));
    }
    if(filter_use_border)
    {
        filter_param_x_min          += filter_param_border;
        filter_param_y_min          += filter_param_border;
        filter_param_x_max          -= filter_param_border;
        filter_param_y_max          -= filter_param_border;
    }

    int search_t = ui->spinBox_MS5_Events_S5intern_Pos_T->value();
    int search_y = ui->spinBox_MS5_Events_S5intern_Pos_Y->value();
    int search_x = ui->spinBox_MS5_Events_S5intern_Pos_X->value();

    //search for event
    QString QS_EventText;
    int pos_t;
    int pos_y;
    int pos_x;
    MS5_EventS5intern_EventActive = MS5_NucPedigree_Editing.event_find(
                &QS_EventText,
                &pos_t,
                &pos_y,
                &pos_x,
                vType_Search,
                vType_Param,
                search_t,
                search_y,
                search_x,
                filter_use_t_after,
                filter_param_t_after,
                filter_use_t_before,
                filter_param_t_before,
                filter_use_range,
                filter_param_x_min,
                filter_param_x_max,
                filter_param_y_min,
                filter_param_y_max,
                filter_no_excluded);

    if(!MS5_EventS5intern_EventActive)
    {
        QMessageBox::information(
                    this,
                    "No event found",
                    "No more events found after"
                    "<br>t=" + QString::number(search_t) + "h"
                    "<br>y=" + QString::number(search_y) + "px"
                    "<br>x=" + QString::number(search_x) + "px");
        return;
    }

    //set pos to ui
    ui->spinBox_MS5_Events_S5intern_Pos_T->setValue(pos_t);
    ui->spinBox_MS5_Events_S5intern_Pos_Y->setValue(pos_y);
    ui->spinBox_MS5_Events_S5intern_Pos_X->setValue(pos_x);
    ui->label_MS5_Events_S5intern_EventTypeText->setText(QS_EventText);

    //jump to viewport
    MS5_EventS5intern_MoveToVP();

}

void D_MAKRO_MegaFoci::MS5_EventS5intern_MoveToVP()
{
    if(!MS5_EventS5intern_EventActive)
        return;

    //event pos
    int event_t_h           = ui->spinBox_MS5_Events_S5intern_Pos_T->value();
    int event_y_px_original = ui->spinBox_MS5_Events_S5intern_Pos_Y->value();
    int event_x_px_original = ui->spinBox_MS5_Events_S5intern_Pos_X->value();

    //size mosaic
    int sx_mosaic = vv_MS5_Mosaics_CT[0][0].cols;
    int sy_mosaic = vv_MS5_Mosaics_CT[0][0].rows;

    //size original
    double scale = ui->doubleSpinBox_OverviewQuality->value() / 100.0;
    int sx_original = int(sx_mosaic / scale);
    int sy_original = int(sy_mosaic / scale);

    //event pos rel
    double event_x_rel = double(event_x_px_original) / double(sx_original);
    double event_y_rel = double(event_y_px_original) / double(sy_original);

    //event pos in mosaic px coordinates
    //int event_x_px_mosaic = int(event_x_rel * sx_mosaic);
    //int event_x_py_mosaic = int(event_y_rel * sy_mosaic);

    //event mosaic coords
    int event_mx = min(int(event_x_rel * dataset_dim_mosaic_x), int(dataset_dim_mosaic_x));
    int event_my = min(int(event_y_rel * dataset_dim_mosaic_y), int(dataset_dim_mosaic_y));

    //vp size
    int vp_size_x = ui->spinBox_MS5_X_size->value();
    int vp_size_y = ui->spinBox_MS5_Y_size->value();
    int vp_size_t = int(MS5_ViewersCount);

    //vp offset to center
    int vp_offset_x = vp_size_x / 2;
    int vp_offset_y = vp_size_y / 2;
    int vp_offset_t = vp_size_t / 2;

    //target event pos
    int target_start_mx = min(max(event_mx  - vp_offset_x, 0), int(dataset_dim_mosaic_x - vp_size_x));
    int target_start_my = min(max(event_my  - vp_offset_y, 0), int(dataset_dim_mosaic_y - vp_size_y));
    int target_start_t  = min(max(event_t_h - vp_offset_t, 0), int(dataset_dim_t        - vp_size_t));

    //move to vp
    ui->spinBox_MS5_X_start->setValue(target_start_mx);
    ui->spinBox_MS5_Y_start->setValue(target_start_my);
    ui->spinBox_MS5_T_start->setValue(target_start_t);

    //update image
    MS5_UpdateImages_Basic();

    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::MS5_EventS5intern_CountEvents()
{
    vector<int> vType_Search = {
        ui->checkBox_MS5_Events_S5intern_LargeDist->isChecked()                     ? 1 : 0,
        ui->checkBox_MS5_Events_S5intern_Mitosis->isChecked()                       ? 1 : 0,
        ui->checkBox_MS5_Events_S5intern_Excluded->isChecked()                      ? 1 : 0,
        ui->checkBox_MS5_Events_S5intern_ShortTracking_Isolated->isChecked()        ? 1 : 0,
        ui->checkBox_MS5_Events_S5intern_ShortTracking_LooseStart->isChecked()      ? 1 : 0,
        ui->checkBox_MS5_Events_S5intern_ShortTracking_LooseEnd->isChecked()        ? 1 : 0,
        ui->checkBox_MS5_Events_S5intern_ShortTracking_BetweenMitoses->isChecked()  ? 1 : 0
    };

    vector<int> vType_Param = {
        ui->spinBox_MS5_Events_S5intern_LargeDist_Dist->value(),
        0,
        0,
        ui->spinBox_MS5_Events_S5intern_ShortTracking_Isolated_Duration->value(),
        ui->spinBox_MS5_Events_S5intern_ShortTracking_LooseStart_Duration->value(),
        ui->spinBox_MS5_Events_S5intern_ShortTracking_LooseEnd_Duration->value(),
        ui->spinBox_MS5_Events_S5intern_ShortTracking_BetweenMitoses_Duration->value()
    };

    bool filter_use_t_after         = ui->checkBox_Events_S5intern_EventConstraints_AfterT->isChecked();
    int  filter_param_t_after       = ui->spinBox_Events_S5intern_EventConstraints_AfterT_Time->value();
    bool filter_use_t_before        = ui->checkBox_Events_S5intern_EventConstraints_BeforeT->isChecked();
    int  filter_param_t_before      = ui->spinBox_Events_S5intern_EventConstraints_BeforeT_Time->value();
    bool filter_use_border          = ui->checkBox_Events_S5intern_EventConstraints_NotBorder->isChecked();
    int  filter_param_border        = ui->spinBox_Events_S5intern_EventConstraints_NotBorder_Size->value();
    bool filter_use_mosaic          = ui->checkBox_Events_S5intern_EventConstraints_Mosaik->isChecked();
    int  filter_param_mosaic_x      = ui->spinBox_Events_S5intern_EventConstraints_Mosaik_MaxX->value();
    int  filter_param_mosaic_y      = ui->spinBox_Events_S5intern_EventConstraints_Mosaik_MaxY->value();
    bool filter_no_excluded         = ui->checkBox_Events_S5intern_EventConstraints_NoExcluded->isChecked();

    bool filter_use_range           = filter_use_border || filter_use_mosaic;
    int filter_param_x_min          = 0;
    int filter_param_y_min          = 0;
    int filter_param_x_max          = int(double(vv_MS5_Mosaics_CT[0][0].cols) / (ui->doubleSpinBox_OverviewQuality->value() / 100.0));
    int filter_param_y_max          = int(double(vv_MS5_Mosaics_CT[0][0].rows) / (ui->doubleSpinBox_OverviewQuality->value() / 100.0));
    if(filter_use_mosaic)
    {
        filter_param_x_max          = int(filter_param_x_max * (double(filter_param_mosaic_x) / double(dataset_dim_mosaic_x)));
        filter_param_y_max          = int(filter_param_y_max * (double(filter_param_mosaic_y) / double(dataset_dim_mosaic_y)));
    }
    if(filter_use_border)
    {
        filter_param_x_min          += filter_param_border;
        filter_param_y_min          += filter_param_border;
        filter_param_x_max          -= filter_param_border;
        filter_param_y_max          -= filter_param_border;
    }

    int start_t = ui->spinBox_MS5_Events_S5intern_Pos_T->value();
    int start_y = ui->spinBox_MS5_Events_S5intern_Pos_Y->value();
    int start_x = ui->spinBox_MS5_Events_S5intern_Pos_X->value();

    vector<size_t> vEventCounts_ToGo = MS5_NucPedigree_Editing.event_counts(
                vType_Param,
                start_t,
                start_y,
                start_x,
                filter_use_t_after,
                filter_param_t_after,
                filter_use_t_before,
                filter_param_t_before,
                filter_use_range,
                filter_param_x_min,
                filter_param_x_max,
                filter_param_y_min,
                filter_param_y_max,
                filter_no_excluded);

    vector<size_t> vEventCounts_All = MS5_NucPedigree_Editing.event_counts(
                vType_Param,
                0,
                0,
                0,
                filter_use_t_after,
                filter_param_t_after,
                filter_use_t_before,
                filter_param_t_before,
                filter_use_range,
                filter_param_x_min,
                filter_param_x_max,
                filter_param_y_min,
                filter_param_y_max,
                filter_no_excluded);

    vector<size_t> vEventCounts_Done(vEventCounts_All.size());
    for(size_t i = 0; i < vEventCounts_All.size(); i++)
        vEventCounts_Done[i] = vEventCounts_All[i] - vEventCounts_ToGo[i];

    ui->spinBox_MS5_Events_S5intern_LargeDist_Count                     ->setSuffix("/" + QString::number(vEventCounts_All[D_Bio_NucleusPedigree::EVENT_TYPE_LARGE_DIST_BETWEEN_NUC]));
    ui->spinBox_MS5_Events_S5intern_Mitosis_Count                       ->setSuffix("/" + QString::number(vEventCounts_All[D_Bio_NucleusPedigree::EVENT_TYPE_MITOSIS]));
    ui->spinBox_MS5_Events_S5intern_Excluded_Count                      ->setSuffix("/" + QString::number(vEventCounts_All[D_Bio_NucleusPedigree::EVENT_TYPE_EXCLUDED]));
    ui->spinBox_MS5_Events_S5intern_ShortTracking_Isolated_Count        ->setSuffix("/" + QString::number(vEventCounts_All[D_Bio_NucleusPedigree::EVENT_TYPE_SHORT_LIFE_ISOLATED]));
    ui->spinBox_MS5_Events_S5intern_ShortTracking_LooseStart_Count      ->setSuffix("/" + QString::number(vEventCounts_All[D_Bio_NucleusPedigree::EVENT_TYPE_SHORT_LIFE_LOOSE_START]));
    ui->spinBox_MS5_Events_S5intern_ShortTracking_LooseEnd_Count        ->setSuffix("/" + QString::number(vEventCounts_All[D_Bio_NucleusPedigree::EVENT_TYPE_SHORT_LIFE_LOOSE_END]));
    ui->spinBox_MS5_Events_S5intern_ShortTracking_BetweenMitoses_Count  ->setSuffix("/" + QString::number(vEventCounts_All[D_Bio_NucleusPedigree::EVENT_TYPE_SHORT_LIFE_BETWEEN_MITOSES]));

    ui->spinBox_MS5_Events_S5intern_LargeDist_Count                     ->setValue(int(vEventCounts_Done[D_Bio_NucleusPedigree::EVENT_TYPE_LARGE_DIST_BETWEEN_NUC]));
    ui->spinBox_MS5_Events_S5intern_Mitosis_Count                       ->setValue(int(vEventCounts_Done[D_Bio_NucleusPedigree::EVENT_TYPE_MITOSIS]));
    ui->spinBox_MS5_Events_S5intern_Excluded_Count                      ->setValue(int(vEventCounts_Done[D_Bio_NucleusPedigree::EVENT_TYPE_EXCLUDED]));
    ui->spinBox_MS5_Events_S5intern_ShortTracking_Isolated_Count        ->setValue(int(vEventCounts_Done[D_Bio_NucleusPedigree::EVENT_TYPE_SHORT_LIFE_ISOLATED]));
    ui->spinBox_MS5_Events_S5intern_ShortTracking_LooseStart_Count      ->setValue(int(vEventCounts_Done[D_Bio_NucleusPedigree::EVENT_TYPE_SHORT_LIFE_LOOSE_START]));
    ui->spinBox_MS5_Events_S5intern_ShortTracking_LooseEnd_Count        ->setValue(int(vEventCounts_Done[D_Bio_NucleusPedigree::EVENT_TYPE_SHORT_LIFE_LOOSE_END]));
    ui->spinBox_MS5_Events_S5intern_ShortTracking_BetweenMitoses_Count  ->setValue(int(vEventCounts_Done[D_Bio_NucleusPedigree::EVENT_TYPE_SHORT_LIFE_BETWEEN_MITOSES]));

    size_t events_active_count_all = 0;
    for(size_t e = 0; e < vEventCounts_All.size(); e++)
        if(vType_Search[e])
            events_active_count_all += vEventCounts_All[e];

    size_t events_active_count_done = 0;
    for(size_t e = 0; e < vEventCounts_Done.size(); e++)
        if(vType_Search[e])
            events_active_count_done += vEventCounts_Done[e];

    double events_done_rel = events_active_count_all > 0 ? double(events_active_count_done) / double(events_active_count_all) : 1;
    ui->progressBar_MS5_Events_AllEvents->setValue(int(events_done_rel * ui->progressBar_MS5_Events_AllEvents->maximum()));
}

void D_MAKRO_MegaFoci::MS5_CalcImage_Thread(Mat* pMA_out, vector<vector<Mat>>* pvv_imgs_ct, D_Bio_NucleusPedigree *pPedigree, size_t t, size_t y_min_mosaic, size_t y_size_mosaic, size_t x_min_mosaic, size_t x_size_mosaic, bool use_DIC, bool use_GFP, bool use_RFP, bool draw_contour_parent, bool draw_contour_current, bool draw_contour_childs, bool draw_shift_parent, bool draw_shift_childs, bool age_text, bool color_info, size_t ny_mosaic, size_t nx_mosaic, int thickness, double scale)
{
    //qDebug() << "scale" << scale;

    if(pvv_imgs_ct->size() != MS5_MOSAIC_CH_NUMBER_OF)
        return;

    if(t >= (*pvv_imgs_ct)[0].size())
        return;

    //drawing thickness
    int thick1 = max(1, thickness / 2);
    int thick2 = max(thick1 + 1, thickness);

    //channels
    bool channels_use[4] = {use_RFP, use_GFP, use_DIC, false};
    int channel_count = 0;
    if(use_DIC) channel_count++;
    if(use_GFP) channel_count++;
    if(use_RFP) channel_count++;

    //crop
    size_t w_full_px    = (*pvv_imgs_ct)[0][0].cols;
    size_t h_full_px    = (*pvv_imgs_ct)[0][0].rows;
    double x_mosaic2px  = double(w_full_px) / double(nx_mosaic);
    double y_mosaic2px  = double(h_full_px) / double(ny_mosaic);
    size_t w_crop_px    = x_size_mosaic * x_mosaic2px;
    size_t h_crop_px    = y_size_mosaic * y_mosaic2px;
    size_t x_start_px   = x_min_mosaic * x_mosaic2px;
    size_t y_start_px   = y_min_mosaic * y_mosaic2px;
    vector<Mat> vMA_Croped(MS5_MOSAIC_CH_NUMBER_OF);
    for(size_t c = 0; c < MS5_MOSAIC_CH_NUMBER_OF; c++)
    {
        D_Img_Proc::Crop_Rect_Abs(
                    &(vMA_Croped[c]),
                    &((*pvv_imgs_ct)[c][t]),
                    x_start_px,
                    y_start_px,
                    w_crop_px,
                    h_crop_px);
    }

    //Offset
    Point P_Offset_px_scaled(x_start_px, y_start_px);

    //merge
    if(channel_count == 0)
    {
        *pMA_out = Mat::zeros(h_crop_px, w_crop_px, CV_8UC3);
    }
    else if(channel_count == 1)
    {
        for(size_t c = 0; c < MS5_MOSAIC_CH_NUMBER_OF; c++)
        {
            if(channels_use[c])
            {
                D_Img_Proc::Duplicate2Channels(
                            pMA_out,
                            &(vMA_Croped[c]),
                            3);
            }
        }
    }
    else
    {
        D_Img_Proc::Merge(
                    pMA_out,
                    &(vMA_Croped[MS5_MOSAIC_CH_RFP]),
                    &(vMA_Croped[MS5_MOSAIC_CH_GFP]),
                    &(vMA_Croped[MS5_MOSAIC_CH_DIC]),
                    &(vMA_Croped[MS5_MOSAIC_CH_DIC]),
                    3,
                    channels_use);
    }

    //draw contours and movement
    for(size_t y = max(0, int(y_min_mosaic) - 1); y < y_min_mosaic + y_size_mosaic; y++)
    {
        for(size_t x = max(0, int(x_min_mosaic) - 1); x < x_min_mosaic + x_size_mosaic; x++)
        {
            size_t ni = pPedigree->nuclei_blob_count(t, y, x);
            for(size_t i = 0; i < ni; i++)
            {
                D_Bio_NucleusBlob* pNucDraw = pPedigree->get_pNucleus(t, y, x, i);

                //------------------------------------- exclude marker ----------------------------

                QColor col_exclude(226, 0, 116);

                if(pNucDraw->matching_excluded_this())
                {
                    //draw
                    D_Img_Proc::Draw_Contour(
                                pMA_out,
                                pNucDraw->contour(scale, -P_Offset_px_scaled),
                                -1,
                                col_exclude.red(), col_exclude.green(), col_exclude.blue());
                }

                if(pNucDraw->matching_excluded_life())
                {
                    //draw
                    D_Img_Proc::Draw_Contour(
                                pMA_out,
                                pNucDraw->contour(scale, -P_Offset_px_scaled),
                                thick2 * 7,
                                col_exclude.red(), col_exclude.green(), col_exclude.blue());
                }

                //------------------------------------- contour of itself ----------------------------

                if(draw_contour_current)
                {
                    //color
                    QColor col = color_info ? pNucDraw->matching_TypeColor(pPedigree->rect_RegularRange_px(), 0, pPedigree->size_T() - 1) : QColor(255, 255, 255);
                    col = col == QColor(0, 0, 0) ? QColor(255, 255, 255) : col; //linear tracking to white for better contrast

                    //draw
                    D_Img_Proc::Draw_Contour(
                                pMA_out,
                                pNucDraw->contour(scale, -P_Offset_px_scaled),
                                thick2,
                                col.red(), col.green(), col.blue());
                }

                //------------------------------------- contour of parent/childs ----------------------------

                //qDebug() << "draw parent contour" << pNucDraw->matching_foundParent();
                if(draw_contour_parent && pNucDraw->matching_foundParent())
                {
                    D_Img_Proc::Draw_Contour(
                                pMA_out,
                                pNucDraw->matching_Parent()->contour(scale, -P_Offset_px_scaled),
                                thick1,
                                0, 0, 255);
                }

                //qDebug() << "draw child 1 contour" << pNucDraw->matching_foundChild1();
                if(draw_contour_childs && pNucDraw->matching_foundChild1())
                {
                    D_Img_Proc::Draw_Contour(
                                pMA_out,
                                pNucDraw->matching_Child1()->contour(scale, -P_Offset_px_scaled),
                                thick1,
                                255, 0, 0);
                }

                //qDebug() << "draw child 2 contour" << pNucDraw->matching_foundChild2();
                if(draw_contour_childs && pNucDraw->matching_foundChild2())
                {
                    D_Img_Proc::Draw_Contour(
                                pMA_out,
                                pNucDraw->matching_Child2()->contour(scale, -P_Offset_px_scaled),
                                thick1,
                                255, 0, 0);
                }

                //------------------------------------- shifts ----------------------------

                //qDebug() << "draw parent shift" << pNucDraw->matching_foundParent();
                if(draw_shift_parent && pNucDraw->matching_foundParent())
                {
                    D_Img_Proc::Draw_Line(
                                pMA_out,
                                pNucDraw->centroid(scale, -P_Offset_px_scaled),
                                pNucDraw->matching_Parent()->centroid(scale, -P_Offset_px_scaled),
                                thick1,
                                0, 0, 255);
                }

                //qDebug() << "draw child 1 shift" << pNucDraw->matching_foundChild1();
                if(draw_shift_childs && pNucDraw->matching_foundChild1())
                {
                    D_Img_Proc::Draw_Line(
                                pMA_out,
                                pNucDraw->centroid(scale, -P_Offset_px_scaled),
                                pNucDraw->matching_Child1()->centroid(scale, -P_Offset_px_scaled),
                                thick1,
                                255, 0, 0);
                }

                //qDebug() << "draw child 2 shift" << pNucDraw->matching_foundChild2();
                if(draw_shift_childs && pNucDraw->matching_foundChild2())
                {
                    D_Img_Proc::Draw_Line(
                                pMA_out,
                                pNucDraw->centroid(scale, -P_Offset_px_scaled),
                                pNucDraw->matching_Child2()->centroid(scale, -P_Offset_px_scaled),
                                thick1,
                                255, 0, 0);
                }

                //------------------------------------- info text ----------------------------

                //qDebug() << "age text";
                if(age_text)
                {
                    //color
                    //qDebug() << "calc colors";
                    QColor col_source       = color_info ? pNucDraw->matching_Source()->matching_TypeColor(pPedigree->rect_RegularRange_px(), 0, pPedigree->size_T() - 1) : QColor(255, 255, 255);
                    QColor col_destination  = color_info ? pNucDraw->matching_Destinantion()->matching_TypeColor(pPedigree->rect_RegularRange_px(), 0, pPedigree->size_T() - 1) : QColor(255, 255, 255);

                    col_source              = col_source == QColor(0, 0, 0) ? QColor(0, 255, 0) : col_source;               //leads back to 1 after mitosis
                    col_destination         = col_destination == QColor(0, 0, 0) ? QColor(255, 255, 255) : col_destination; //should never happen

                    //ages
                    //qDebug() << "calc ages";
                    size_t age_source       = pNucDraw->matching_Age();
                    size_t age_destination  = pNucDraw->matching_AgeToGo();

                    //centroid
                    //qDebug() << "get centroid";
                    Point center = pNucDraw->centroid(scale, -P_Offset_px_scaled);

                    //write source text
                    //qDebug() << "draw aget text source";
                    D_Img_Proc::Draw_Text(
                                pMA_out,
                                QString::number(age_source),
                                center.x,
                                center.y,
                                thick1,
                                0.5,
                                col_source.red(),
                                col_source.green(),
                                col_source.blue());

                    //write dest text
                    //qDebug() << "draw age text dest";
                    D_Img_Proc::Draw_Text(
                                pMA_out,
                                QString::number(age_destination),
                                center.x,
                                center.y + 15,
                                thick1,
                                0.5,
                                col_destination.red(),
                                col_destination.green(),
                                col_destination.blue());

                    //qDebug() << "text complete---------------------";
                }

                //------------------------------------- end of drawing ----------------------------
            }
        }
    }
}

void D_MAKRO_MegaFoci::on_pushButton_MS5_DataLoad_clicked()
{
    MS5_LoadAll();
}

void D_MAKRO_MegaFoci::on_spinBox_MS5_Y_size_valueChanged(int arg1)
{
    ui->spinBox_MS5_X_size->blockSignals(true);
    ui->spinBox_MS5_X_size->setValue(arg1);
    ui->spinBox_MS5_X_size->blockSignals(false);
}

void D_MAKRO_MegaFoci::on_spinBox_MS5_X_size_valueChanged(int arg1)
{
    ui->spinBox_MS5_Y_size->blockSignals(true);
    ui->spinBox_MS5_Y_size->setValue(arg1);
    ui->spinBox_MS5_Y_size->blockSignals(false);
}

void D_MAKRO_MegaFoci::on_pushButton_MS5_DataSave_clicked()
{
    MS5_SaveData();
}

void D_MAKRO_MegaFoci::on_pushButton_MS5_Editing_ConnectionCreate_clicked()
{
    MS5_Editing_ConnectionCreate();
}

void D_MAKRO_MegaFoci::on_pushButton_MS5_Editing_ConnectionDelete_clicked()
{
    MS5_Editing_ConnectionDelete();
}

void D_MAKRO_MegaFoci::on_pushButton_MS5_Editing_Exclude_clicked()
{
    MS5_Editing_Exclude();
}

void D_MAKRO_MegaFoci::on_pushButton_MS5_Editing_Include_clicked()
{
    MS5_Editing_Include();
}

void D_MAKRO_MegaFoci::on_pushButton_MS5_Editing_ForgetSelection_clicked()
{
    MS5_Editing_SelectionForget();
}

void D_MAKRO_MegaFoci::on_pushButton_MS5_SaveViewportImageStack_clicked()
{
    MS5_SaveImgStack();
}

void D_MAKRO_MegaFoci::on_pushButton_MS5_EventS2_RecordStart_clicked()
{
    MS5_EventToS2_Start();
}

void D_MAKRO_MegaFoci::on_pushButton_MS5_EventS2_RecordStop_clicked()
{
    MS5_EventToS2_Start();
}

void D_MAKRO_MegaFoci::on_spinBox_MS5_Events_S5intern_Pos_T_valueChanged(int arg1)
{
    ui->label_MS5_Events_S5intern_EventTypeText->setText("manually changed T");
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_spinBox_MS5_Events_S5intern_Pos_Y_valueChanged(int arg1)
{
    ui->label_MS5_Events_S5intern_EventTypeText->setText("manually changed Y");
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_spinBox_MS5_Events_S5intern_Pos_X_valueChanged(int arg1)
{
    ui->label_MS5_Events_S5intern_EventTypeText->setText("manually changed X");
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_pushButton_MS5_Events_S5intern_JumpToNextEvent_clicked()
{
    MS5_EventS5intern_JumpToNext();
}

void D_MAKRO_MegaFoci::on_spinBox_MS5_Events_S5intern_Draw_Radius_valueChanged(int arg1)
{
    MS5_UpdateImages_Highlight();
}

void D_MAKRO_MegaFoci::on_spinBox_MS5_Events_S5intern_Draw_Thickness_valueChanged(int arg1)
{
    MS5_UpdateImages_Highlight();
}

void D_MAKRO_MegaFoci::on_spinBox_MS5_Events_S5intern_Draw_Red_valueChanged(int arg1)
{
    QColor col(
                ui->spinBox_MS5_Events_S5intern_Draw_Red->value(),
                ui->spinBox_MS5_Events_S5intern_Draw_Green->value(),
                ui->spinBox_MS5_Events_S5intern_Draw_Blue->value());

    ui->pushButton_MS5_Events_S5intern_Draw_SelectColor->setStyleSheet("background-color: rgb(" + QString::number(col.red()) + "," + QString::number(col.green()) + "," +QString::number(col.blue()) + ");");

    MS5_UpdateImages_Highlight();
}

void D_MAKRO_MegaFoci::on_spinBox_MS5_Events_S5intern_Draw_Green_valueChanged(int arg1)
{
    QColor col(
                ui->spinBox_MS5_Events_S5intern_Draw_Red->value(),
                ui->spinBox_MS5_Events_S5intern_Draw_Green->value(),
                ui->spinBox_MS5_Events_S5intern_Draw_Blue->value());

    ui->pushButton_MS5_Events_S5intern_Draw_SelectColor->setStyleSheet("background-color: rgb(" + QString::number(col.red()) + "," + QString::number(col.green()) + "," +QString::number(col.blue()) + ");");

    MS5_UpdateImages_Highlight();
}

void D_MAKRO_MegaFoci::on_spinBox_MS5_Events_S5intern_Draw_Blue_valueChanged(int arg1)
{
    QColor col(
                ui->spinBox_MS5_Events_S5intern_Draw_Red->value(),
                ui->spinBox_MS5_Events_S5intern_Draw_Green->value(),
                ui->spinBox_MS5_Events_S5intern_Draw_Blue->value());

    ui->pushButton_MS5_Events_S5intern_Draw_SelectColor->setStyleSheet("background-color: rgb(" + QString::number(col.red()) + "," + QString::number(col.green()) + "," +QString::number(col.blue()) + ");");

    MS5_UpdateImages_Highlight();
}

void D_MAKRO_MegaFoci::on_pushButton_MS5_Events_S5intern_Draw_SelectColor_clicked()
{
    QColor col(
                ui->spinBox_MS5_Events_S5intern_Draw_Red->value(),
                ui->spinBox_MS5_Events_S5intern_Draw_Green->value(),
                ui->spinBox_MS5_Events_S5intern_Draw_Blue->value());

    col = QColorDialog::getColor(
                col,
                this,
                "Select event highlight color");

    ui->spinBox_MS5_Events_S5intern_Draw_Red->setValue(col.red());
    ui->spinBox_MS5_Events_S5intern_Draw_Green->setValue(col.green());
    ui->spinBox_MS5_Events_S5intern_Draw_Blue->setValue(col.blue());

    ui->pushButton_MS5_Events_S5intern_Draw_SelectColor->setStyleSheet("background-color: rgb(" + QString::number(col.red()) + "," + QString::number(col.green()) + "," +QString::number(col.blue()) + ");");
}

void D_MAKRO_MegaFoci::on_pushButton_MS5_Events_S5intern_BackToZero_clicked()
{
    if(QMessageBox::question(
                this,
                "Back to 0?",
                "Are you sure you want to reset to 0/0/0?")
            != QMessageBox::Yes)
        return;

    MS5_EventS5intern_EventActive = false;
    ui->spinBox_MS5_T_start->setValue(0);
    ui->spinBox_MS5_Y_start->setValue(0);
    ui->spinBox_MS5_X_start->setValue(0);

    ui->spinBox_MS5_Events_S5intern_Pos_T->setValue(0);
    ui->spinBox_MS5_Events_S5intern_Pos_Y->setValue(0);
    ui->spinBox_MS5_Events_S5intern_Pos_X->setValue(0);
    ui->label_MS5_Events_S5intern_EventTypeText->setText("reseted to 0/0/0");

    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_pushButton_MS5_Events_S5intern_CountEvents_clicked()
{
    MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_checkBox_MS5_Events_S5intern_AutoUpdateCount_stateChanged(int arg1)
{
    ui->pushButton_MS5_Events_S5intern_CountEvents->setEnabled(arg1 == 0);
}

void D_MAKRO_MegaFoci::on_spinBox_MS5_Events_S5intern_LargeDist_Dist_valueChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_spinBox_MS5_Events_S5intern_ShortTracking_Isolated_Duration_valueChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_spinBox_MS5_Events_S5intern_ShortTracking_LooseStart_Duration_valueChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_spinBox_MS5_Events_S5intern_ShortTracking_LooseEnd_Duration_valueChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_spinBox_MS5_Events_S5intern_ShortTracking_BetweenMitoses_Duration_valueChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_checkBox_Events_S5intern_EventConstraints_AfterT_clicked()
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_spinBox_Events_S5intern_EventConstraints_AfterT_Time_valueChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_checkBox_Events_S5intern_EventConstraints_BeforeT_clicked()
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_spinBox_Events_S5intern_EventConstraints_BeforeT_Time_valueChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_checkBox_Events_S5intern_EventConstraints_NotBorder_stateChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_spinBox_Events_S5intern_EventConstraints_NotBorder_Size_valueChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_checkBox_Events_S5intern_EventConstraints_Mosaik_stateChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_spinBox_Events_S5intern_EventConstraints_Mosaik_MaxX_valueChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_spinBox_Events_S5intern_EventConstraints_Mosaik_MaxY_valueChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_checkBox_Events_S5intern_EventConstraints_NoExcluded_stateChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_checkBox_MS5_Events_S5intern_LargeDist_stateChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_checkBox_MS5_Events_S5intern_Mitosis_stateChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_checkBox_MS5_Events_S5intern_ShortTracking_Isolated_stateChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_checkBox_MS5_Events_S5intern_ShortTracking_LooseStart_stateChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_checkBox_MS5_Events_S5intern_ShortTracking_LooseEnd_stateChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_checkBox_MS5_Events_S5intern_ShortTracking_BetweenMitoses_stateChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}

void D_MAKRO_MegaFoci::on_checkBox_MS5_Events_S5intern_Excluded_stateChanged(int arg1)
{
    if(ui->checkBox_MS5_Events_S5intern_AutoUpdateCount->isChecked())
        MS5_EventS5intern_CountEvents();
}




void D_MAKRO_MegaFoci::on_pushButton_MS6_LoadData_clicked()
{
    MS6_LoadAll();
}

void D_MAKRO_MegaFoci::MS6_UiInit()
{
    if(mode_major_current != MODE_MAJOR_6_EPIC_ANALYSIS)
        return;

    //-------------------------------------------------------------------------------------- pedigree

    //time range for irradiation time
    ui->doubleSpinBox_MS6_IrradiationTime->setMaximum(dataset_dim_t - 1);

    //show channel name selectors
    ui->lineEdit_MS6_ValueChannel_Name_0->setEnabled(dataset_dim_p_exist > 0);
    ui->lineEdit_MS6_ValueChannel_Name_1->setEnabled(dataset_dim_p_exist > 1);
    ui->lineEdit_MS6_ValueChannel_Name_2->setEnabled(dataset_dim_p_exist > 2);

    //init pedigree filter ui
    MS6_NucPedigree_Results.set_attrib_filter_ui(
                ui->groupBox_MS6_Control_Filters_Foci,
                ui->groupBox_MS6_Control_Filters_NucBlobs,
                ui->groupBox_MS6_Control_Filters_NucLifes);

    //save dir of attrib filters
    MS6_NucPedigree_Results.set_attrib_filter_path(pStore->dir_M_MegaFoci_Results());

    //-------------------------------------------------------------------------------------- result type controls

    //res type
    Populate_CB_Single(ui->comboBox_MS6_ResultTypes, QSL_MS6_ResultTypes, MS6_RES_TYP_HIST_SIMPLE);
    connect(ui->comboBox_MS6_ResultTypes, SIGNAL(currentIndexChanged(int)), this, SLOT(MS6_ResAxis_UpdateModi()));

    //datapoint level
    Populate_CB_Single(ui->comboBox_MS6_ResultDatapointLevel, QSL_DatapointLevel, DATAPOINT_LEVEL_NUCLIFE);
    connect(ui->comboBox_MS6_ResultDatapointLevel, SIGNAL(currentIndexChanged(int)), this, SLOT(MS6_ResAxis_UpdateModi()));


    //-------------------------------------------------------------------------------------- results viewer axis controls

    //containers for axis description
    MS6_vL_ResAxis_Description          = {ui->label_MS6_Res_AxisDescription_0,         ui->label_MS6_Res_AxisDescription_1,        ui->label_MS6_Res_AxisDescription_2};

    //containers for axis control comboboxes
    MS6_vCB_ResAxis_Stat_low            = {ui->comboBox_MS6_ResAxis_Stat_low_0,             ui->comboBox_MS6_ResAxis_Stat_low_1,            ui->comboBox_MS6_ResAxis_Stat_low_2};
    MS6_vCB_ResAxis_Stat_high           = {ui->comboBox_MS6_ResAxis_Stat_high_0,            ui->comboBox_MS6_ResAxis_Stat_high_1,           ui->comboBox_MS6_ResAxis_Stat_high_2};
    MS6_vCB_ResAxis_Level_Foc           = {ui->comboBox_MS6_ResAxis_Level_Foc_0,            ui->comboBox_MS6_ResAxis_Level_Foc_1,           ui->comboBox_MS6_ResAxis_Level_Foc_2};
    MS6_vCB_ResAxis_Level_NucBlob       = {ui->comboBox_MS6_ResAxis_Level_NucBlob_0,        ui->comboBox_MS6_ResAxis_Level_NucBlob_1,       ui->comboBox_MS6_ResAxis_Level_NucBlob_2};
    MS6_vCB_ResAxis_Level_NucLife       = {ui->comboBox_MS6_ResAxis_Level_NucLife_0,        ui->comboBox_MS6_ResAxis_Level_NucLife_1,       ui->comboBox_MS6_ResAxis_Level_NucLife_2};
    MS6_vCB_ResAxis_Attrib_Foc          = {ui->comboBox_MS6_ResAxis_Attrib_Foc_0,           ui->comboBox_MS6_ResAxis_Attrib_Foc_1,          ui->comboBox_MS6_ResAxis_Attrib_Foc_2};
    MS6_vCB_ResAxis_Attrib_NucBlob      = {ui->comboBox_MS6_ResAxis_Attrib_NucBlob_0,       ui->comboBox_MS6_ResAxis_Attrib_NucBlob_1,      ui->comboBox_MS6_ResAxis_Attrib_NucBlob_2};
    MS6_vCB_ResAxis_Attrib_NucLife      = {ui->comboBox_MS6_ResAxis_Attrib_NucLife_0,       ui->comboBox_MS6_ResAxis_Attrib_NucLife_1,      ui->comboBox_MS6_ResAxis_Attrib_NucLife_2};
    MS6_vCB_ResAxis_FocChannel          = {ui->comboBox_MS6_ResParam_FocChannel_0,          ui->comboBox_MS6_ResParam_FocChannel_1,         ui->comboBox_MS6_ResParam_FocChannel_2};
    MS6_vCB_ResAxis_AttribChannel_Val   = {ui->comboBox_MS6_ResParam_AttribChannel_Val_0,   ui->comboBox_MS6_ResParam_AttribChannel_Val_1,  ui->comboBox_MS6_ResParam_AttribChannel_Val_2};
    MS6_vCB_ResAxis_AttribChannel_Foc   = {ui->comboBox_MS6_ResParam_AttribChannel_Foc_0,   ui->comboBox_MS6_ResParam_AttribChannel_Foc_1,  ui->comboBox_MS6_ResParam_AttribChannel_Foc_2};

    //populate comboboxes
    for(size_t i = 0; i < MS6_ResAxis_Count; i++)
    {
        Populate_CB_Single(MS6_vCB_ResAxis_Stat_low[i],         QSL_StatList,               c_STAT_MEAN_ARITMETIC);
        Populate_CB_Single(MS6_vCB_ResAxis_Stat_high[i],        QSL_StatList,               c_STAT_MEAN_ARITMETIC);

        Populate_CB_Single(MS6_vCB_ResAxis_Level_Foc[i],        QSL_DataLevel_Foc,          DATA_LEVEL_FOC_ATTRIB);
        Populate_CB_Single(MS6_vCB_ResAxis_Level_NucBlob[i],    QSL_DataLevel_NucBlob,      DATA_LEVEL_NUCBLOB_ATTRIB);
        Populate_CB_Single(MS6_vCB_ResAxis_Level_NucLife[i],    QSL_DataLevel_NucLife,      DATA_LEVEL_NUCLIFE_ATTRIB);

        Populate_CB_Single(MS6_vCB_ResAxis_Attrib_Foc[i],       QSL_Attrib_Foc,             ATTRIB_FOC_AREA_UM);
        Populate_CB_Single(MS6_vCB_ResAxis_Attrib_NucBlob[i],   QSL_Attrib_Nuc,             ATTRIB_NUC_FOCI_COUNT_ALL);
        Populate_CB_Single(MS6_vCB_ResAxis_Attrib_NucLife[i],   QSL_Attrib_NucLife,         ATTRIB_NUCLIFE_AGE);

        connect(MS6_vCB_ResAxis_Attrib_Foc[i],      SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS6_ResAxis_UpdateModi()));
        connect(MS6_vCB_ResAxis_Level_NucBlob[i],   SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS6_ResAxis_UpdateModi()));
        connect(MS6_vCB_ResAxis_Level_NucLife[i],   SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS6_ResAxis_UpdateModi()));
        connect(MS6_vCB_ResAxis_Attrib_Foc[i],      SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS6_ResAxis_UpdateModi()));
        connect(MS6_vCB_ResAxis_Attrib_NucBlob[i],  SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS6_ResAxis_UpdateModi()));
        connect(MS6_vCB_ResAxis_Attrib_NucLife[i],  SIGNAL(currentIndexChanged(int)),   this,   SLOT(MS6_ResAxis_UpdateModi()));
    }

    //containers for axis control stacked widgets
    MS6_cSW_ResAxis_Stat_low        = {ui->stackedWidget_MS6_ResAxis_Stat_low_0,        ui->stackedWidget_MS6_ResAxis_Stat_low_1,       ui->stackedWidget_MS6_ResAxis_Stat_low_2};
    MS6_cSW_ResAxis_Stat_high       = {ui->stackedWidget_MS6_ResAxis_Stat_high_0,       ui->stackedWidget_MS6_ResAxis_Stat_high_1,      ui->stackedWidget_MS6_ResAxis_Stat_high_2};
    MS6_cSW_ResAxis_Level           = {ui->stackedWidget_MS6_ResAxis_Level_0,           ui->stackedWidget_MS6_ResAxis_Level_1,          ui->stackedWidget_MS6_ResAxis_Level_2};
    MS6_cSW_ResAxis_Attrib          = {ui->stackedWidget_MS6_ResAxis_Attrib_0,          ui->stackedWidget_MS6_ResAxis_Attrib_1,         ui->stackedWidget_MS6_ResAxis_Attrib_2};
    MS6_cSW_ResAxis_FocChannel      = {ui->stackedWidget_MS6_ResParam_FocChannel_0,     ui->stackedWidget_MS6_ResParam_FocChannel_1,    ui->stackedWidget_MS6_ResParam_FocChannel_2};
    MS6_cSW_ResAxis_AttribChannel   = {ui->stackedWidget_MS6_ResParam_AttribChannel_0,  ui->stackedWidget_MS6_ResParam_AttribChannel_1, ui->stackedWidget_MS6_ResParam_AttribChannel_2};

    //init axis controls
    MS6_ResAxis_UpdateModi();


    //-------------------------------------------------------------------------------------- viewers

    //plot 2D
    MS6_pChartView_Plot_2D = new QChartView();
    D_Plot::Plot_Empty(MS6_pChartView_Plot_2D, "Load data, if you want to see something cooler here ;-)");
    ui->gridLayout_MS6_ResView_Plot_2D->addWidget(MS6_pChartView_Plot_2D);
    MS6_pChartView_Plot_2D->setRenderHint(QPainter::Antialiasing);
    MS6_pChartView_Plot_2D->setRubberBand(QChartView::RectangleRubberBand);
    MS6_pChartView_Plot_2D->setInteractive(true);

    //plot 3D
    MS6_Viewer_Plot_3D.init(ui->gridLayout_MS6_ResView_Plot_3D);

    //img 2D
    MS6_Viewer_Img_2D.set_GV(ui->graphicsView_MS6_ResView_Image_2D);
    MS6_Viewer_Img_2D.Set_Transformation_Mode(true);

    //img 3D
    MS6_Viewer_Img_3D.init(ui->gridLayout_MS6_ResView_Image_3D);
    MS6_Viewer_Img_3D.Set_StoragePointer(pStore, dir_SAVE);

    //table
    MS6_Viewer_Table.set_TW(ui->tableWidget_MS6_ResView_Table);


    //-------------------------------------------------------------------------------------- Results

    Populate_CB_Single(ui->comboBox_MS6_ResType_Param_PoolStatLine_Stat,                    QSL_StatList,   c_STAT_MEAN_ARITMETIC);
    Populate_CB_Single(ui->comboBox_MS6_ResType_Param_PoolStatLine_DualErr_Stat_1stVal,     QSL_StatList,   c_STAT_MEAN_ARITMETIC);
    Populate_CB_Single(ui->comboBox_MS6_ResType_Param_PoolStatLine_DualErr_Stat_1stErr,     QSL_StatList,   c_STAT_SEM_ABS_TOTAL);
    Populate_CB_Single(ui->comboBox_MS6_ResType_Param_PoolStatLine_DualErr_Stat_2ndVal,     QSL_StatList,   c_STAT_COUNT);
    Populate_CB_Single(ui->comboBox_MS6_ResType_Params_ScatterHeatmap_Stat,                 QSL_StatList,   c_STAT_MEAN_ARITMETIC);

    connect(ui->pushButton_MS6_UpdateResults,       SIGNAL(clicked(bool)),      this,       SLOT(MS6_Update_Results()));

    //-------------------------------------------------------------------------------------- end

    //change state
    MS6_state_ui_init = true;
}

void D_MAKRO_MegaFoci::MS6_UpdateViews()
{
    MS6_Viewer_Img_2D.Update_View();
}

bool D_MAKRO_MegaFoci::MS6_LoadAll()
{
    //qDebug() << "D_MAKRO_MegaFoci::MS6_LoadAll" << "start ::::::::::::::::::::::::::::::::::::::::::::::::";
    if(mode_major_current != MODE_MAJOR_6_EPIC_ANALYSIS)
        return false;

    //qDebug() << "D_MAKRO_MegaFoci::MS6_LoadAll" << "MS6_LoadDirs";
    if(!MS6_LoadDirs())
    {
        StatusSet("Failed loading directories " + QS_Fun_Sad);
        return false;
    }

    if(!MS6_LoadMosaics())
    {
        StatusSet("Failed loading mosaics " + QS_Fun_Sad);
        return false;
    }

    //qDebug() << "D_MAKRO_MegaFoci::MS6_LoadAll" << "MS6_LoadNucleiData";
    if(!MS6_LoadNucleiData())
    {
        StatusSet("Failed loading nuclei data " + QS_Fun_Sad);
        return false;
    }
    MS6_NucPedigree_Results.info_debug();

    //channels list and irradiation time
    //qDebug() << "D_MAKRO_MegaFoci::MS6_LoadAll" << "MS6_GetChannelsFromUi";
    MS6_GetChannelsFromUi();
    //qDebug() << "D_MAKRO_MegaFoci::MS6_LoadAll" << "MS6_GetIrradiationTimeFromUi";
    MS6_GetIrradiationTimeFromUi();
    //qDebug() << "D_MAKRO_MegaFoci::MS6_LoadAll" << "MS6_GetRangeXYFromUi";
    MS6_GetRangeXYFromUi();

    //qDebug() << "D_MAKRO_MegaFoci::MS6_LoadAll" << "MS6_LoadNucleiLifes";
    if(!MS6_LoadNucleiLifes())
    {
        StatusSet("Failed loading nuclei lifes " + QS_Fun_Sad);
        return false;
    }

    //states
    MS6_state_loaded_all = true;

    //ui
    //qDebug() << "D_MAKRO_MegaFoci::MS6_LoadAll" << "Ui";
    ui->groupBox_MS6_Control_Data->setEnabled(false);
    ui->groupBox_MS6_View->setEnabled(true);
    ui->groupBox_MS6_Control_Filters->setEnabled(true);
    ui->groupBox_MS6_Control_Results->setEnabled(true);
    ui->groupBox_MS6_Save->setEnabled(true);
    ui->groupBox_MS6_DefaultPlots->setEnabled(true);

    //split to nuc lifes
    //qDebug() << "D_MAKRO_MegaFoci::MS6_LoadAll" << "split to nuc lifes";
    StatusSet("Start spearating linked nucleui into nucleus lifes");
    MS6_NucPedigree_Results.calc_NucLifes();
    StatusSet("Finished separating linked nucleui into nucleus lifes");

    //finish
    //qDebug() << "D_MAKRO_MegaFoci::MS6_LoadAll" << "finish ::::::::::::::::::::::::::::::::::::::::::::::::";
    StatusSet("Loaded all needed data " + QS_Fun_Happy);
    //StatusSet(MS6_NucPedigree_Results.info());
    //MS6_NucPedigree_Results.info_debug();
    return true;
}

bool D_MAKRO_MegaFoci::MS6_LoadDirs()
{
    if(mode_major_current != MODE_MAJOR_6_EPIC_ANALYSIS)
        return false;

    //------------------ mosaics ------------------------------------------------

    StatusSet("Please select results directory from step 1 (for mosaics).");
    QString QS_LoadMS1 = QFileDialog::getExistingDirectory(
                this,
                "Please select results folder of step 1 you want to load mosaics from (must beginn with 'Results_Step1_').",
                pStore->dir_M_MegaFoci_Results()->path());

    //check if dir was selected
    if(QS_LoadMS1.isEmpty())
    {
        StatusSet("Well, you should select a folder... Wasn't that clear?");
        return false;
    }

    //check, if dir is results from step 1
    if(!QS_LoadMS1.contains("Results_Step1"))
    {
        StatusSet("You should selct results from step 1...\n" + QS_Fun_TableFlip);
        return false;
    }

    //master dir in
    QString QS_Path_S1 = QS_LoadMS1.split("/").last();
    DIR_MS6_Load_Mosaics.setPath(QS_LoadMS1 + "/Mosaik");
    if(!DIR_MS6_Load_Mosaics.exists())
    {
        StatusSet("The selected directory doesn't contain a 'Mosaik' directory. " + QS_Fun_Confused);
        return false;
    }

    //save input dir
    QDir DIR_parent(QS_LoadMS1);
    DIR_parent.cdUp();
    pStore->set_dir_M_MegaFoci_Results(DIR_parent.path());

    //------------------ nuclei data ------------------------------------------------

    StatusSet("Please select results directory from step 3 (for nuclei data).");
    QString QS_LoadMS3 = QFileDialog::getExistingDirectory(
                this,
                "Please select results folder of step 3 you want to load nuclei data from (must beginn with 'Results_Step3_').",
                pStore->dir_M_MegaFoci_Results()->path());

    //check if dir was selected
    if(QS_LoadMS3.isEmpty())
    {
        StatusSet("Well, you should select a folder... Wasn't that clear?");
        return false;
    }

    //check, if dir is results from step 3
    if(!QS_LoadMS3.contains("Results_Step3"))
    {
        StatusSet("You should selct results from step 3...\n" + QS_Fun_TableFlip);
        return false;
    }

    //master dir in
    QString QS_Path_S3 = QS_LoadMS3.split("/").last();
    DIR_MS6_Load_NucleiData.setPath(QS_LoadMS3 + "/DetectionsAssigned");
    if(!DIR_MS6_Load_NucleiData.exists())
    {
        StatusSet("The selected directory doesn't contain a 'DetectionsAssigned' directory. " + QS_Fun_Confused);
        return false;
    }

    //save input dir
    DIR_parent.setPath(QS_LoadMS3);
    DIR_parent.cdUp();
    pStore->set_dir_M_MegaFoci_Results(DIR_parent.path());

    //------------------ nuclei lifes ------------------------------------------------

    StatusSet("Please select results directory from step 4 or 5 (for nuclei lifes).");
    QString QS_LoadMS4_5 = QFileDialog::getExistingDirectory(
                this,
                "Please select results folder of step 4 or 5 you want to load nuclei lifes from (must beginn with 'Results_Step4_' or 'Results_Step5_').",
                pStore->dir_M_MegaFoci_Results()->path());

    //check if dir was selected
    if(QS_LoadMS4_5.isEmpty())
    {
        StatusSet("Well, you should select a folder... Wasn't that clear?");
        return false;
    }

    //check, if dir is results from step 4 or 5
    if(!QS_LoadMS4_5.contains("Results_Step4") && !QS_LoadMS4_5.contains("Results_Step5"))
    {
        StatusSet("You should selct results from step 4 or 5...\n" + QS_Fun_TableFlip);
        return false;
    }

    //master dir in
    QString QS_Path_S5 = QS_LoadMS4_5.split("/").last();
    DIR_MS6_Load_NucleiLifes.setPath(QS_LoadMS4_5);
    if(!DIR_MS6_Load_NucleiLifes.exists())
    {
        StatusSet("With unknown dark magic you selected a not existing directory. " + QS_Fun_Confused);
        return false;
    }

    //save input dir
    DIR_parent.setPath(QS_LoadMS4_5);
    DIR_parent.cdUp();
    pStore->set_dir_M_MegaFoci_Results(DIR_parent.path());

    //------------------ finished ------------------------------------------------

    StatusSet("Load Folders:\n.../" + QS_Path_S1 + "\n.../" + QS_Path_S3 + "\n.../" + QS_Path_S5);
    MS6_state_loaded_dirs = true;
    return true;
}

bool D_MAKRO_MegaFoci::MS6_LoadMosaics()
{
    if(mode_major_current != MODE_MAJOR_6_EPIC_ANALYSIS)
        return false;
    if(!MS6_state_loaded_dirs)
        return false;

    StatusSet("Start loading mosaics");

    //clear and resize container
    vv_MS6_Mosaics_CT.clear();
    vv_MS6_Mosaics_CT.resize(MS6_MOSAIC_CH_NUMBER_OF);

    //loop mosaic channels
    for(size_t c = 0; c < MS6_MOSAIC_CH_NUMBER_OF; c++)
    {
        //channel name
        QString QS_ChName = QSL_MS6_MosaicChannels[int(c)];

        //dir
        QDir DIR_MosaicChannel(DIR_MS6_Load_Mosaics.path() + "/" + QS_ChName);
        if(!DIR_MosaicChannel.exists())
        {
            StatusSet("Mosaic directory not found:\n" + DIR_MosaicChannel.path());
            return false;
        }

        //imgs in dir
        QFileInfoList FIL_Imgs = DIR_MosaicChannel.entryInfoList();
        for(int i = 0; i < FIL_Imgs.size(); i++)
        {
            //img
            QFileInfo FI_Img = FIL_Imgs[i];
            //qDebug() << "------------------------------------------------";
            //qDebug() << FI_Img;

            //is png
            if(FI_Img.suffix() == "png")
            {
                //qDebug() << "is .png";

                //contains correct text in file name
                if(FI_Img.baseName().contains("Mosaik_" + QS_ChName + "_T"))
                {
                    //qDebug() << "base name fits" << FI_Img.baseName();

                    //get time index
                    bool ok;
                    //qDebug() << "looking for t index" << FI_Img.baseName().right(FI_Img.baseName().size() - 9 - QS_ChName.length());
                    int t = FI_Img.baseName().right(FI_Img.baseName().size() - 9 - QS_ChName.length()).toInt(&ok);
                    if(ok)
                    {
                        //qDebug() << "got t" << t;

                        //correct size of container
                        while(t >= int(vv_MS6_Mosaics_CT[c].size()))
                            vv_MS6_Mosaics_CT[c].push_back(Mat::zeros(1, 1, CV_8UC1));

                        //read img
                        D_Img_Proc::Load_From_Path(
                                    &(vv_MS6_Mosaics_CT[c][t]),
                                    FI_Img.absoluteFilePath());

                        //qDebug() << "read" << FI_Img;
                    }
                }
            }
        }
    }

    MS6_state_loaded_mosaics = true;
    StatusSet("Successfully loaded mosaics");
    return true;
}

bool D_MAKRO_MegaFoci::MS6_LoadNucleiData()
{
    if(mode_major_current != MODE_MAJOR_6_EPIC_ANALYSIS)
        return false;
    if(!MS6_state_loaded_dirs)
        return false;

    StatusSet("Start loading nuclei data from step 3");

    //parent dir of detections
    QDir DIR_ParentMS3(DIR_MS6_Load_NucleiData);
    DIR_ParentMS3.cdUp();

    //load data
    bool ok = MS6_NucPedigree_Results.load_nuclei_data(
                DIR_ParentMS3.path(),
                DIR_MS6_Load_NucleiData.path(),
                dataset_dim_t, dataset_dim_mosaic_y, dataset_dim_mosaic_x,
                false,
                true);

    if(ok)
    {
        StatusSet("Finished loading nuclei data from step 3");
        MS6_state_loaded_nuc_data = true;
        return true;
    }
    else
    {
        StatusSet("FAILED loading nuclei data from step 3");
        MS6_state_loaded_nuc_data = false;
        return false;
    }
}

bool D_MAKRO_MegaFoci::MS6_LoadNucleiLifes()
{
    if(mode_major_current != MODE_MAJOR_6_EPIC_ANALYSIS)
        return false;
    if(!MS6_state_loaded_dirs || !MS6_state_loaded_nuc_data)
        return false;

    //load data
    StatusSet("Start loading nuclei matches from step 4/5");
    bool ok = MS6_NucPedigree_Results.match_load_matches(DIR_MS6_Load_NucleiLifes.path());

    if(ok)
    {
        StatusSet("Finished loading nuclei matches from step 4/5");
        MS6_state_loaded_nuc_lifes = true;
        return true;
    }
    else
    {
        StatusSet("FAILED loading nuclei matches from step 4/5");
        MS6_state_loaded_nuc_lifes = false;
        return false;
    }
}

bool D_MAKRO_MegaFoci::MS6_GetChannelsFromUi()
{
    if(!MS6_state_ui_init)
        return false;

    //----------------- values

    MS6_QSL_Channels_Values.clear();

    if(dataset_dim_p_exist > 0)
        MS6_QSL_Channels_Values.append(ui->lineEdit_MS6_ValueChannel_Name_0->text());
    if(dataset_dim_p_exist > 1)
        MS6_QSL_Channels_Values.append(ui->lineEdit_MS6_ValueChannel_Name_1->text());
    if(dataset_dim_p_exist > 2)
        MS6_QSL_Channels_Values.append(ui->lineEdit_MS6_ValueChannel_Name_2->text());

    //----------------- foci

    MS6_QSL_Channels_Foci.clear();
    MS6_QSL_Channels_Foci.append(ui->lineEdit_MS6_FociChannel_Name_0->text());
    MS6_QSL_Channels_Foci.append(ui->lineEdit_MS6_FociChannel_Name_1->text());
    MS6_QSL_Channels_Foci.append(ui->lineEdit_MS6_FociChannel_Name_2->text());

    //----------------- pedigree in gerenal

    MS6_NucPedigree_Results.set_channels(MS6_QSL_Channels_Foci, MS6_QSL_Channels_Values);

    //----------------- attrib filters

    MS6_NucPedigree_Results.set_attrib_filter_channels(MS6_QSL_Channels_Foci, MS6_QSL_Channels_Values);

    MS6_NucPedigree_Results.set_attrib_filter(ATTRIB_FILTER_MODE_NUC_LIFE,  0,   true,     ATTRIB_NUCLIFE_IN_RANGE_PERMANENT,   c_COMPARE_EQUAL,    0,   1.0);
    MS6_NucPedigree_Results.set_attrib_filter(ATTRIB_FILTER_MODE_NUC_LIFE,  1,   true,     ATTRIB_NUCLIFE_AGE,                  c_COMPARE_GREATER,  0,   0.0);
    MS6_NucPedigree_Results.set_attrib_filter(ATTRIB_FILTER_MODE_NUC_LIFE,  2,   true,     ATTRIB_NUCLIFE_START,                c_COMPARE_GREATER,  0,   0.0);
    MS6_NucPedigree_Results.set_attrib_filter(ATTRIB_FILTER_MODE_NUC_LIFE,  3,   true,     ATTRIB_NUCLIFE_MITOSIS_STARTS_WITH,  c_COMPARE_EQUAL,    0,   1.0);
    MS6_NucPedigree_Results.set_attrib_filter(ATTRIB_FILTER_MODE_NUC_LIFE,  4,   true,     ATTRIB_NUCLIFE_EXCLUDED,             c_COMPARE_EQUAL,    0,   0.0); //included in nuc life filtering in pedigree by default

    //----------------- populate dropdowns

    for(size_t i = 0; i < MS6_ResAxis_Count; i++)
    {
        Populate_CB_Single(MS6_vCB_ResAxis_FocChannel[i],           MS6_QSL_Channels_Foci,      0);
        Populate_CB_Single(MS6_vCB_ResAxis_AttribChannel_Foc[i],    MS6_QSL_Channels_Foci,      0);
        Populate_CB_Single(MS6_vCB_ResAxis_AttribChannel_Val[i],    MS6_QSL_Channels_Values,    MS6_QSL_Channels_Values.size() > 1 ? 1 : 0);
    }

    return true;
}

bool D_MAKRO_MegaFoci::MS6_GetIrradiationTimeFromUi()
{
    if(!MS6_state_ui_init)
        return false;

    MS6_NucPedigree_Results.set_time_irradiation(ui->doubleSpinBox_MS6_IrradiationTime->value());
    MS6_NucPedigree_Results.set_scale_px2um(ui->doubleSpinBox_MS6_Scale_px2um->value());
    MS6_NucPedigree_Results.set_scale_T2h(ui->doubleSpinBox_MS6_Scale_T2h->value());
    MS6_NucPedigree_Results.set_attrib_filter_scaling();

    return true;
}

bool D_MAKRO_MegaFoci::MS6_GetRangeXYFromUi()
{
    if(!MS6_state_ui_init)
        return false;

    //base size
    size_t base_img_x = ui->spinBox_MS6_BaseImgSize_x->value();
    size_t base_img_y = ui->spinBox_MS6_BaseImgSize_y->value();

    //overlap
    size_t overlap_x = ui->spinBox_ImgProc_Stitch_Overlap_x->value();
    size_t overlap_y = ui->spinBox_ImgProc_Stitch_Overlap_y->value();

    //stitching
    double stitch_border_rel = ui->doubleSpinBox_ImgProc_Stitch_Border->value() / 100.0;

    //index range
    size_t ix_min = MS6_NucPedigree_Results.mosaik_index_non_empty_min_x();
    size_t ix_max = MS6_NucPedigree_Results.mosaik_index_non_empty_max_x();
    size_t iy_min = MS6_NucPedigree_Results.mosaik_index_non_empty_min_y();
    size_t iy_max = MS6_NucPedigree_Results.mosaik_index_non_empty_max_y();

    //img area
    size_t x_min_px = ix_min * base_img_x;
    if(ix_min > 0)
        x_min_px -= overlap_x * ix_min;

    size_t y_min_px = iy_min * base_img_y;
    if(iy_min > 0)
        y_min_px -= overlap_y * iy_min;

    size_t x_max_px = (ix_max + 1) * base_img_x;
    if(ix_max > 0)
        x_max_px -= overlap_x * ix_max;
    if(ix_max < dataset_dim_mosaic_x - 1)
        x_max_px += size_t(stitch_border_rel * base_img_x);

    size_t y_max_px = (iy_max + 1) * base_img_y;
    if(iy_max > 0)
        y_max_px -= overlap_y * iy_max;
    if(iy_max < dataset_dim_mosaic_y - 1)
        y_max_px += size_t(stitch_border_rel * base_img_y);

    //margin
    size_t margin_px = ui->spinBox_MS6_MarginToBorder->value();

    //set full range
    MS6_NucPedigree_Results.set_FrameBorder_XY(Rect(
                int(x_min_px),
                int(y_min_px),
                int(x_max_px - x_min_px),
                int(y_max_px - y_min_px)));

    //set frame for in range with margin to border
    MS6_NucPedigree_Results.set_FrameInMargin_XY(
                int(x_min_px + margin_px),
                int(x_max_px - margin_px),
                int(y_min_px + margin_px),
                int(y_max_px - margin_px));

    //finish
    return true;
}

void D_MAKRO_MegaFoci::MS6_ResAxis_UpdateModi()
{
    //axis data level
    int axis_data_level;
    switch (ui->comboBox_MS6_ResultDatapointLevel->currentIndex()) {
    case DATAPOINT_LEVEL_NUCLIFE:   axis_data_level = MS6_RES_AXIS_MODE_NUCLIFE;    break;
    case DATAPOINT_LEVEL_NUCBLOB:   axis_data_level = MS6_RES_AXIS_MODE_NUCBLOB;    break;
    case DATAPOINT_LEVEL_FOC:       axis_data_level = MS6_RES_AXIS_MODE_FOC;        break;
    default:                        axis_data_level = MS6_RES_AXIS_MODE_NONE;       return;}

    //defaults
    ui->stackedWidget_MS6_ResView->setCurrentIndex(MS6_RES_VIEW_TYPE_ERROR);
    MS6_ResAxis_SetMode(0, "-", MS6_RES_AXIS_MODE_NONE);
    MS6_ResAxis_SetMode(1, "-", MS6_RES_AXIS_MODE_NONE);
    MS6_ResAxis_SetMode(2, "-", MS6_RES_AXIS_MODE_NONE);

    switch (ui->comboBox_MS6_ResultTypes->currentIndex()) {

    case MS6_RES_TYP_HIST_SIMPLE:
        ui->stackedWidget_MS6_ResView->setCurrentIndex(MS6_RES_VIEW_TYPE_PLOT_2D);
        MS6_ResAxis_SetMode(0, "X", axis_data_level);
        break;

    case MS6_RES_TYP_POOL_STAT_LINE_SINGLE:
    case MS6_RES_TYP_POOL_STAT_LINE_DUAL_WITH_ERROR:
        ui->stackedWidget_MS6_ResView->setCurrentIndex(MS6_RES_VIEW_TYPE_PLOT_2D);
        MS6_ResAxis_SetMode(0, "X Pool", axis_data_level);
        MS6_ResAxis_SetMode(1, "Y Stat", axis_data_level);
        break;

    case MS6_RES_TYP_SCATTER_2D_SIMPLE:
        ui->stackedWidget_MS6_ResView->setCurrentIndex(MS6_RES_VIEW_TYPE_PLOT_2D);
        MS6_ResAxis_SetMode(0, "X", axis_data_level);
        MS6_ResAxis_SetMode(1, "Y", axis_data_level);
        break;

    case MS6_RES_TYP_SCATTER_HEATMAP_2D:
        ui->stackedWidget_MS6_ResView->setCurrentIndex(MS6_RES_VIEW_TYPE_PLOT_2D);
        MS6_ResAxis_SetMode(0, "X", axis_data_level);
        MS6_ResAxis_SetMode(1, "Y", axis_data_level);
        MS6_ResAxis_SetMode(2, "Color", axis_data_level);
        break;

    case MS6_RES_TYP_SCATTER_HEATMAP_3D:
        ui->stackedWidget_MS6_ResView->setCurrentIndex(MS6_RES_VIEW_TYPE_PLOT_3D);
        MS6_ResAxis_SetMode(0, "X", axis_data_level);
        MS6_ResAxis_SetMode(1, "Y", axis_data_level);
        MS6_ResAxis_SetMode(2, "Color/Height", axis_data_level);
        break;

    case MS6_RES_TYP_DATA_TABLE_3D:
        ui->stackedWidget_MS6_ResView->setCurrentIndex(MS6_RES_VIEW_TYPE_TABLE);
        MS6_ResAxis_SetMode(0, "Col1", axis_data_level);
        MS6_ResAxis_SetMode(1, "Col2", axis_data_level);
        MS6_ResAxis_SetMode(2, "Col3", axis_data_level);
        break;

    case MS6_RES_TYP_MOSAIC_DATA:
        ui->stackedWidget_MS6_ResView->setCurrentIndex(MS6_RES_VIEW_TYPE_IMAGE_2D);
        break;

    case MS6_RES_TYP_NUC_LIFE_IMG:
        ui->stackedWidget_MS6_ResView->setCurrentIndex(MS6_RES_VIEW_TYPE_IMAGE_2D);
        break;

    default:
        return;
    }
}

void D_MAKRO_MegaFoci::MS6_ResAxis_SetMode(size_t i_axis, QString axis_description, size_t i_mode)
{
    if(i_mode >= MS6_RES_AXIS_MODE_NUMBER_OF)
        return;

    if(i_axis >= MS6_ResAxis_Count)
        return;

    MS6_vL_ResAxis_Description[i_axis]->setText(axis_description);

    MS6_cSW_ResAxis_Level[i_axis]->setCurrentIndex(int(i_mode));

    switch (i_mode)
    {

    case MS6_RES_AXIS_MODE_NONE://-------------------------------------------------------------------------------
    {
        MS6_cSW_ResAxis_Stat_high[i_axis]->setCurrentIndex(MS6_RES_AXIS_STAT_OFF);
        MS6_cSW_ResAxis_Stat_low[i_axis]->setCurrentIndex(MS6_RES_AXIS_STAT_OFF);
        MS6_cSW_ResAxis_Attrib[i_axis]->setCurrentIndex(MS6_RES_AXIS_ATTRIB_EMPTY);
        MS6_cSW_ResAxis_FocChannel[i_axis]->setCurrentIndex(MS6_RES_AXIS_CHANNEL_FOC_OFF);
        MS6_cSW_ResAxis_AttribChannel[i_axis]->setCurrentIndex(MS6_RES_AXIS_CHANNEL_ATTRIB_OFF);
    }
        break;

    case MS6_RES_AXIS_MODE_NUCLIFE://-------------------------------------------------------------------------------
    {
        switch (MS6_vCB_ResAxis_Level_NucLife[i_axis]->currentIndex()) {

        case DATA_LEVEL_NUCLIFE_ATTRIB:
        {
            int att_ch_dependency;
            if(D_Bio_NucleusLife::attribute_is_focus_channel_dependent(MS6_vCB_ResAxis_Attrib_NucLife[i_axis]->currentIndex()))
                att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_ON_FOC;
            else if(D_Bio_NucleusLife::attribute_is_value_channel_dependent(MS6_vCB_ResAxis_Attrib_NucLife[i_axis]->currentIndex()))
                att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_ON_VAL;
            else
                att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_OFF;

            MS6_cSW_ResAxis_Stat_high[i_axis]->setCurrentIndex(MS6_RES_AXIS_STAT_OFF);
            MS6_cSW_ResAxis_Stat_low[i_axis]->setCurrentIndex(MS6_RES_AXIS_STAT_OFF);
            MS6_cSW_ResAxis_Attrib[i_axis]->setCurrentIndex(MS6_RES_AXIS_ATTRIB_NUCLIFE);
            MS6_cSW_ResAxis_FocChannel[i_axis]->setCurrentIndex(MS6_RES_AXIS_CHANNEL_FOC_OFF);
            MS6_cSW_ResAxis_AttribChannel[i_axis]->setCurrentIndex(att_ch_dependency);
        }
            break;

        case DATA_LEVEL_NUCLIFE_STAT_NUCBLOB:
        {
            int att_ch_dependency;
            if(D_Bio_NucleusBlob::attribute_is_focus_channel_dependent(MS6_vCB_ResAxis_Attrib_NucBlob[i_axis]->currentIndex()))
                att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_ON_FOC;
            else if(D_Bio_NucleusBlob::attribute_is_value_channel_dependent(MS6_vCB_ResAxis_Attrib_NucBlob[i_axis]->currentIndex()))
                att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_ON_VAL;
            else
                att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_OFF;

            MS6_cSW_ResAxis_Stat_high[i_axis]->setCurrentIndex(MS6_RES_AXIS_STAT_OFF);
            MS6_cSW_ResAxis_Stat_low[i_axis]->setCurrentIndex(MS6_RES_AXIS_STAT_ON);
            MS6_cSW_ResAxis_Attrib[i_axis]->setCurrentIndex(MS6_RES_AXIS_ATTRIB_NUCBLOB);
            MS6_cSW_ResAxis_FocChannel[i_axis]->setCurrentIndex(MS6_RES_AXIS_CHANNEL_FOC_OFF);
            MS6_cSW_ResAxis_AttribChannel[i_axis]->setCurrentIndex(att_ch_dependency);
        }
            break;

        case DATA_LEVEL_NUCLIFE_STAT_STAT_FOC:
        {
            int att_ch_dependency;
            if(D_Bio_Focus::attribute_is_focus_channel_dependent(MS6_vCB_ResAxis_Attrib_Foc[i_axis]->currentIndex()))
                att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_ON_FOC;
            else if(D_Bio_Focus::attribute_is_value_channel_dependent(MS6_vCB_ResAxis_Attrib_Foc[i_axis]->currentIndex()))
                att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_ON_VAL;
            else
                att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_OFF;

            MS6_cSW_ResAxis_Stat_high[i_axis]->setCurrentIndex(MS6_RES_AXIS_STAT_ON);
            MS6_cSW_ResAxis_Stat_low[i_axis]->setCurrentIndex(MS6_RES_AXIS_STAT_ON);
            MS6_cSW_ResAxis_Attrib[i_axis]->setCurrentIndex(MS6_RES_AXIS_ATTRIB_FOC);
            MS6_cSW_ResAxis_FocChannel[i_axis]->setCurrentIndex(MS6_RES_AXIS_CHANNEL_FOC_ON);
            MS6_cSW_ResAxis_AttribChannel[i_axis]->setCurrentIndex(att_ch_dependency);
        }
            break;

        default:
            return;
        }
    }
        break;

    case MS6_RES_AXIS_MODE_NUCBLOB://-------------------------------------------------------------------------------
    {
        switch (MS6_vCB_ResAxis_Level_NucBlob[i_axis]->currentIndex()) {

        case DATA_LEVEL_NUCBLOB_ATTRIB:
        {
            int att_ch_dependency;
            if(D_Bio_NucleusBlob::attribute_is_focus_channel_dependent(MS6_vCB_ResAxis_Attrib_NucBlob[i_axis]->currentIndex()))
                att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_ON_FOC;
            else if(D_Bio_NucleusBlob::attribute_is_value_channel_dependent(MS6_vCB_ResAxis_Attrib_NucBlob[i_axis]->currentIndex()))
                att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_ON_VAL;
            else
                att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_OFF;

            MS6_cSW_ResAxis_Stat_high[i_axis]->setCurrentIndex(MS6_RES_AXIS_STAT_OFF);
            MS6_cSW_ResAxis_Stat_low[i_axis]->setCurrentIndex(MS6_RES_AXIS_STAT_OFF);
            MS6_cSW_ResAxis_Attrib[i_axis]->setCurrentIndex(MS6_RES_AXIS_ATTRIB_NUCBLOB);
            MS6_cSW_ResAxis_FocChannel[i_axis]->setCurrentIndex(MS6_RES_AXIS_CHANNEL_FOC_OFF);
            MS6_cSW_ResAxis_AttribChannel[i_axis]->setCurrentIndex(att_ch_dependency);
        }
            break;

        case DATA_LEVEL_NUCBLOB_STAT_FOC:
        {
            int att_ch_dependency;
            if(D_Bio_Focus::attribute_is_focus_channel_dependent(MS6_vCB_ResAxis_Attrib_Foc[i_axis]->currentIndex()))
                att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_ON_FOC;
            else if(D_Bio_Focus::attribute_is_value_channel_dependent(MS6_vCB_ResAxis_Attrib_Foc[i_axis]->currentIndex()))
                att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_ON_VAL;
            else
                att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_OFF;

            MS6_cSW_ResAxis_Stat_high[i_axis]->setCurrentIndex(MS6_RES_AXIS_STAT_OFF);
            MS6_cSW_ResAxis_Stat_low[i_axis]->setCurrentIndex(MS6_RES_AXIS_STAT_ON);
            MS6_cSW_ResAxis_Attrib[i_axis]->setCurrentIndex(MS6_RES_AXIS_ATTRIB_FOC);
            MS6_cSW_ResAxis_FocChannel[i_axis]->setCurrentIndex(MS6_RES_AXIS_CHANNEL_FOC_ON);
            MS6_cSW_ResAxis_AttribChannel[i_axis]->setCurrentIndex(att_ch_dependency);
        }
            break;

        default:
            return;
        }
    }
        break;

    case MS6_RES_AXIS_MODE_FOC://----------------------------------------------------------------------------------
    {
        int att_ch_dependency;
        if(D_Bio_Focus::attribute_is_focus_channel_dependent(MS6_vCB_ResAxis_Attrib_Foc[i_axis]->currentIndex()))
            att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_ON_FOC;
        else if(D_Bio_Focus::attribute_is_value_channel_dependent(MS6_vCB_ResAxis_Attrib_Foc[i_axis]->currentIndex()))
            att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_ON_VAL;
        else
            att_ch_dependency = MS6_RES_AXIS_CHANNEL_ATTRIB_OFF;

        MS6_cSW_ResAxis_Stat_high[i_axis]->setCurrentIndex(MS6_RES_AXIS_STAT_OFF);
        MS6_cSW_ResAxis_Stat_low[i_axis]->setCurrentIndex(MS6_RES_AXIS_STAT_OFF);
        MS6_cSW_ResAxis_Attrib[i_axis]->setCurrentIndex(MS6_RES_AXIS_ATTRIB_FOC);
        MS6_cSW_ResAxis_FocChannel[i_axis]->setCurrentIndex(MS6_RES_AXIS_CHANNEL_FOC_ON);
        MS6_cSW_ResAxis_AttribChannel[i_axis]->setCurrentIndex(att_ch_dependency);
    }
        break;

    default://------------------------------------------------------------------------------------------------------
        return;
    }
}

vector<double> D_MAKRO_MegaFoci::MS6_DataForAxis(size_t i_axis)
{
    return MS6_NucPedigree_Results.attrib_data(
                ui->comboBox_MS6_ResultDatapointLevel->currentIndex(),
                MS6_vCB_ResAxis_Level_NucLife[i_axis]->currentIndex(),
                MS6_vCB_ResAxis_Level_NucBlob[i_axis]->currentIndex(),
                //MS6_vCB_ResAxis_Level_Foc[i_axis]->currentIndex(),
                MS6_vCB_ResAxis_Attrib_NucLife[i_axis]->currentIndex(),
                MS6_vCB_ResAxis_Attrib_NucBlob[i_axis]->currentIndex(),
                MS6_vCB_ResAxis_Attrib_Foc[i_axis]->currentIndex(),
                MS6_Data_ChannelIndex(i_axis),
                MS6_vCB_ResAxis_FocChannel[i_axis]->currentIndex(),
                MS6_vCB_ResAxis_Stat_low[i_axis]->currentIndex(),
                MS6_vCB_ResAxis_Stat_high[i_axis]->currentIndex());
}

size_t D_MAKRO_MegaFoci::MS6_Data_ChannelIndex(size_t i_axis)
{
    //ui knows what type it is because it is set in D_MAKRO_MegaFoci::MS6_ResAxis_SetMode
    size_t axis_channel_mode = MS6_cSW_ResAxis_AttribChannel[i_axis]->currentIndex();

    switch (axis_channel_mode) {
    case MS6_RES_AXIS_CHANNEL_ATTRIB_OFF:       return 0;
    case MS6_RES_AXIS_CHANNEL_ATTRIB_ON_VAL:    return MS6_vCB_ResAxis_AttribChannel_Val[i_axis]->currentIndex();
    case MS6_RES_AXIS_CHANNEL_ATTRIB_ON_FOC:    return MS6_vCB_ResAxis_AttribChannel_Foc[i_axis]->currentIndex();
    default:                                    return 0;}
}

QString D_MAKRO_MegaFoci::MS6_Data_ChannelSuffix(size_t i_axis)
{
    //ui knows what type it is because it is set in D_MAKRO_MegaFoci::MS6_ResAxis_SetMode
    size_t axis_channel_mode = MS6_cSW_ResAxis_AttribChannel[i_axis]->currentIndex();

    switch (axis_channel_mode) {
    case MS6_RES_AXIS_CHANNEL_ATTRIB_OFF:       return "";
    case MS6_RES_AXIS_CHANNEL_ATTRIB_ON_VAL:    return " in " + MS6_vCB_ResAxis_AttribChannel_Val[i_axis]->currentText();
    case MS6_RES_AXIS_CHANNEL_ATTRIB_ON_FOC:    return " in " + MS6_vCB_ResAxis_AttribChannel_Foc[i_axis]->currentText();
    default:                                    return "";}
}

QString D_MAKRO_MegaFoci::MS6_DefaultTitle_Result()
{
    //qDebug() << "MS6_DefaultTitle_Result--------------------------------------------------------------";
    if(ui->checkBox_S6_SytleGeneral_CustomTitle->isChecked())
        return ui->lineEdit_S6_StyleGeneral_CustomTitle->text();
    else
        return ui->comboBox_MS6_ResultDatapointLevel->currentText() + " " + ui->comboBox_MS6_ResultTypes->currentText();
}

QString D_MAKRO_MegaFoci::MS6_DefaultTitle_Series()
{
    //qDebug() << "MS6_DefaultTitle_Series";
    if(ui->checkBox_S6_SytleGeneral_CustomSeries->isChecked())
        return ui->lineEdit_S6_StyleGeneral_CustomSeries->text();
    else
        return ui->comboBox_MS6_ResultDatapointLevel->currentText();
}

QString D_MAKRO_MegaFoci::MS6_DefaultTitle_Axis_NoChanelSuffix(size_t i_axis)
{
    //qDebug() << "MS6_DefaultTitle_Axis_NoChanelSuffix" << i_axis;

    switch (MS6_cSW_ResAxis_Level[i_axis]->currentIndex()) {

    case MS6_RES_AXIS_MODE_NONE:
        return "empty axis - smells like an error!";

    case MS6_RES_AXIS_MODE_NUCLIFE:
    {
        switch (MS6_vCB_ResAxis_Level_NucLife[i_axis]->currentIndex()) {
        case DATA_LEVEL_NUCLIFE_ATTRIB:                 return MS6_vCB_ResAxis_Attrib_NucLife[i_axis]->currentText() + " of (" + MS6_vCB_ResAxis_Level_NucLife[i_axis]->currentText() + ")";
        case DATA_LEVEL_NUCLIFE_STAT_NUCBLOB:           return MS6_vCB_ResAxis_Stat_low[i_axis]->currentText()       + " of (" + MS6_vCB_ResAxis_Attrib_NucBlob[i_axis]->currentText() + " of (" + MS6_vCB_ResAxis_Level_NucLife[i_axis]->currentText() + "))";
        case DATA_LEVEL_NUCLIFE_STAT_STAT_FOC:          return MS6_vCB_ResAxis_Stat_high[i_axis]->currentText()      + " of (" + MS6_vCB_ResAxis_Stat_low[i_axis]->currentText()       + " of (" + MS6_vCB_ResAxis_Attrib_NucBlob[i_axis]->currentText() + " of (" + MS6_vCB_ResAxis_Level_NucLife[i_axis]->currentText() + ")))";
        default:                                        return "Error: MS6_RES_AXIS_MODE_NUCLIFE + default";}
    }

    case MS6_RES_AXIS_MODE_NUCBLOB:
    {
        switch (MS6_vCB_ResAxis_Level_NucBlob[i_axis]->currentIndex()) {
        case DATA_LEVEL_NUCBLOB_ATTRIB:                 return MS6_vCB_ResAxis_Attrib_NucBlob[i_axis]->currentText() + " of (" + MS6_vCB_ResAxis_Level_NucBlob[i_axis]->currentText() + ")";
        case DATA_LEVEL_NUCBLOB_STAT_FOC:               return MS6_vCB_ResAxis_Stat_low[i_axis]->currentText() + " of (" + MS6_vCB_ResAxis_Attrib_Foc[i_axis]->currentText() + " of (" + MS6_vCB_ResAxis_Level_NucBlob[i_axis]->currentText() + "))";
        default:                                        return "Error: MS6_RES_AXIS_MODE_NUCBLOB + default";}
    }

    case MS6_RES_AXIS_MODE_FOC:
    {
        return MS6_vCB_ResAxis_Attrib_Foc[i_axis]->currentText() + " of (" + MS6_vCB_ResAxis_Level_Foc[i_axis]->currentText() + ")";
    }

    default:
        return "Error: default case";
    }
}

QString D_MAKRO_MegaFoci::MS6_DefaultTitle_Axis(size_t i_axis)
{
    bool custom = false;
    switch(i_axis) {
    case 0:     custom = ui->checkBox_S6_StyleAxis_CustomTitle_X->isChecked();  break;
    case 1:     custom = ui->checkBox_S6_StyleAxis_CustomTitle_Y->isChecked();  break;
    case 2:     custom = ui->checkBox_S6_StyleAxis_CustomTitle_Z->isChecked();  break;
    default:                                                                    break;}

    if(custom)
    {
        switch(i_axis) {
        case 0:     return ui->lineEdit_S6_StyleAxis_CustomTitle_X->text();
        case 1:     return ui->lineEdit_S6_StyleAxis_CustomTitle_Y->text();
        case 2:     return ui->lineEdit_S6_StyleAxis_CustomTitle_Z->text();
        default:    return "invalid axis, no default text";}
    }
    else
    {
        return MS6_DefaultTitle_Axis_NoChanelSuffix(i_axis) + MS6_Data_ChannelSuffix(i_axis);
    }
}

void D_MAKRO_MegaFoci::MS6_Update_Results()
{
    //qDebug() << "MS6_Update_Results--------------------------------------------------------------";

    switch (ui->comboBox_MS6_ResultTypes->currentIndex())
    {
    case MS6_RES_TYP_HIST_SIMPLE:                       MS6_Update_Result_HistSimple();                 break;
    case MS6_RES_TYP_POOL_STAT_LINE_SINGLE:             MS6_Update_Result_PoolStatLine_Single();        break;
    case MS6_RES_TYP_POOL_STAT_LINE_DUAL_WITH_ERROR:    MS6_Update_Result_PoolStatLine_DualWithError(); break;
    case MS6_RES_TYP_SCATTER_2D_SIMPLE:                 MS6_Update_Result_Scatter_2D();                 break;
    case MS6_RES_TYP_SCATTER_HEATMAP_2D:                MS6_Update_Result_Heatmap_2D();                 break;
    case MS6_RES_TYP_SCATTER_HEATMAP_3D:                MS6_Update_Result_Heatmap_3D();                 break;
    case MS6_RES_TYP_DATA_TABLE_3D:                     MS6_Update_Result_DataTable_3Axis();            break;
    case MS6_RES_TYP_MOSAIC_DATA:                       MS6_Update_Result_MosaicData();                 break;
    case MS6_RES_TYP_NUC_LIFE_IMG:                      MS6_Update_Result_NucLifeImg();                 break;
    default:                                                                                            break;
    }

    //plot modify
}

void D_MAKRO_MegaFoci::MS6_Update_Result_HistSimple()
{
    ERR(D_Plot::Plot_Hist_WithStats(
                MS6_pChartView_Plot_2D,
                MS6_DataForAxis(0),
                ui->spinBox_MS6_ResType_Param_Hist_Classes->value(),
                MS6_DefaultTitle_Result(),
                MS6_DefaultTitle_Axis(0),
                ui->checkBox_MS6_ResType_Param_Hist_Uni->isChecked(),
                ui->checkBox_MS6_ResType_Param_Hist_Acc->isChecked(),
                AXE_TICK_COUNT_MAJOR_DEFAULT),
        "MS6_Update_Result_HistSimple",
        "D_Plot::Plot_Hist_WithStats");
}

void D_MAKRO_MegaFoci::MS6_Update_Result_PoolStatLine_Single()
{
    ERR(D_Plot::Plot_Line_PoolStat_Single(
                MS6_pChartView_Plot_2D,
                MS6_DataForAxis(0),
                MS6_DataForAxis(1),
                ui->doubleSpinBox_MS6_ResType_Param_PoolStatLine_MinX->value(),
                ui->doubleSpinBox_MS6_ResType_Param_PoolStatLine_StepX->value(),
                ui->spinBox_MS6_ResType_Param_PoolStatLine_Classes->value(),
                ui->comboBox_MS6_ResType_Param_PoolStatLine_Stat->currentIndex(),
                MS6_DefaultTitle_Result(),
                MS6_DefaultTitle_Series(),
                MS6_DefaultTitle_Axis(0),
                MS6_DefaultTitle_Axis(1),
                ui->checkBox_MS6_ResType_Param_PoolStatLine_AutoRange->isChecked(),
                ui->checkBox_S6_StyleAxis_CustomRange_X->isChecked(),
                ui->checkBox_S6_StyleAxis_CustomRange_Y->isChecked(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMin_X->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMax_X->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMin_Y->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMax_Y->value(),
                ui->spinBox_S6_StyleAxis_CustomTick_X->value(),
                ui->spinBox_S6_StyleAxis_CustomTick_Y->value()),
        "MS6_Update_Result_PoolStatLine_Single",
        "D_Plot::Plot_Line_PoolStat_Single");
}

void D_MAKRO_MegaFoci::MS6_Update_Result_PoolStatLine_DualWithError()
{
    ERR(D_Plot::Plot_Line_PoolStat_DualErr(
                MS6_pChartView_Plot_2D,
                MS6_DataForAxis(0),
                MS6_DataForAxis(1),
                ui->doubleSpinBox_MS6_ResType_Param_PoolStatLine_DualErr_MinX->value(),
                ui->doubleSpinBox_MS6_ResType_Param_PoolStatLine_DualErr_StepX->value(),
                ui->spinBox_MS6_ResType_Param_PoolStatLine_DualErr_Classes->value(),
                ui->comboBox_MS6_ResType_Param_PoolStatLine_DualErr_Stat_1stVal->currentIndex(),
                ui->comboBox_MS6_ResType_Param_PoolStatLine_DualErr_Stat_1stErr->currentIndex(),
                ui->comboBox_MS6_ResType_Param_PoolStatLine_DualErr_Stat_2ndVal->currentIndex(),
                MS6_DefaultTitle_Result(),
                MS6_DefaultTitle_Series(),
                MS6_DefaultTitle_Axis(0),
                MS6_DefaultTitle_Axis(1),
                ui->checkBox_MS6_ResType_Param_PoolStatLine_DualErr_AutoRange->isChecked(),
                c_AXE_TRANS_LIN,
                c_AXE_TRANS_LIN,
                c_AXE_TRANS_LIN,
                false,
                ui->checkBox_S6_StyleAxis_CustomRange_X->isChecked(),
                ui->checkBox_S6_StyleAxis_CustomRange_Y->isChecked(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMin_X->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMax_X->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMin_Y->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMax_Y->value(),
                ui->spinBox_S6_StyleAxis_CustomTick_X->value(),
                ui->spinBox_S6_StyleAxis_CustomTick_Y->value()),
        "MS6_Update_Result_PoolStatLine_DualWithError",
        "D_Plot::Plot_Line_PoolStat_DualErr");
}

void D_MAKRO_MegaFoci::MS6_Update_Result_Scatter_2D()
{
    ERR(D_Plot::Plot_Scatter_2D_Single_Y(
                MS6_pChartView_Plot_2D,
                MS6_DataForAxis(0),
                MS6_DataForAxis(1),
                MS6_DefaultTitle_Result(),
                MS6_DefaultTitle_Series(),
                MS6_DefaultTitle_Axis(0),
                MS6_DefaultTitle_Axis(1),
                ui->checkBox_S6_StyleAxis_CustomRange_X->isChecked(),
                ui->checkBox_S6_StyleAxis_CustomRange_Y->isChecked(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMin_X->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMax_X->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMin_Y->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMax_Y->value(),
                ui->spinBox_S6_StyleAxis_CustomTick_X->value(),
                ui->spinBox_S6_StyleAxis_CustomTick_Y->value()),
        "MS6_Update_Result_Scatter_2D",
        "D_Plot::Plot_Hist_WithStats");
}

void D_MAKRO_MegaFoci::MS6_Update_Result_Heatmap_2D()
{
    ERR(D_Plot::Plot_Scatter_Heatmap(
                MS6_pChartView_Plot_2D,
                MS6_DataForAxis(0),
                ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Min_x->value(),
                ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Step_x->value(),
                ui->checkBox_MS6_ResType_Params_ScatterHeatmap_ManuelRange_x->isChecked(),
                ui->spinBox_MS6_ResType_Params_ScatterHeatmap_Classes_x->value(),
                MS6_DefaultTitle_Axis(0),
                MS6_DataForAxis(1),
                ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Min_y->value(),
                ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Step_y->value(),
                ui->checkBox_MS6_ResType_Params_ScatterHeatmap_ManuelRange_y->isChecked(),
                ui->spinBox_MS6_ResType_Params_ScatterHeatmap_Classes_y->value(),
                MS6_DefaultTitle_Axis(1),
                MS6_DataForAxis(2),
                ui->comboBox_MS6_ResType_Params_ScatterHeatmap_Stat->currentIndex(),
                MS6_DefaultTitle_Axis(2),
                MS6_DefaultTitle_Result(),
                ui->checkBox_S6_StyleAxis_CustomRange_X->isChecked(),
                ui->checkBox_S6_StyleAxis_CustomRange_Y->isChecked(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMin_X->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMax_X->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMin_Y->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMax_Y->value(),
                ui->spinBox_S6_StyleAxis_CustomTick_X->value(),
                ui->spinBox_S6_StyleAxis_CustomTick_Y->value()),
        "MS6_Update_Result_Heatmap_2D",
        "D_Plot::Plot_Scatter_Heatmap");
}

void D_MAKRO_MegaFoci::MS6_Update_Result_Heatmap_3D()
{
    ERR(MS6_Viewer_Plot_3D.plot_Heatmap(
                MS6_DataForAxis(0),
                ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Min_x->value(),
                ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Step_x->value(),
                ui->checkBox_MS6_ResType_Params_ScatterHeatmap_ManuelRange_x->isChecked(),
                ui->spinBox_MS6_ResType_Params_ScatterHeatmap_Classes_x->value(),
                MS6_DefaultTitle_Axis(0),
                MS6_DataForAxis(1),
                ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Min_y->value(),
                ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Step_y->value(),
                ui->checkBox_MS6_ResType_Params_ScatterHeatmap_ManuelRange_y->isChecked(),
                ui->spinBox_MS6_ResType_Params_ScatterHeatmap_Classes_y->value(),
                MS6_DefaultTitle_Axis(1),
                MS6_DataForAxis(2),
                ui->comboBox_MS6_ResType_Params_ScatterHeatmap_Stat->currentIndex(),
                MS6_DefaultTitle_Axis(2),
                ui->checkBox_MS6_ResType_Params_ScatterHeatmap_Height->isChecked(),
                ui->checkBox_MS6_ResType_Params_ScatterHeatmap_Wireframe->isChecked(),
                ui->checkBox_S6_StyleAxis_CustomRange_X->isChecked(),
                ui->checkBox_S6_StyleAxis_CustomRange_Y->isChecked(),
                ui->checkBox_S6_StyleAxis_CustomRange_Z->isChecked(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMin_X->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMax_X->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMin_Y->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMax_Y->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMin_Z->value(),
                ui->doubleSpinBox_S6_StyleAxis_CustomMax_Z->value(),
                false),
        "MS6_Update_Result_Heatmap_3D",
        "MS6_Viewer_Plot_3D.plot_Heatmap");
}

void D_MAKRO_MegaFoci::MS6_Update_Result_DataTable_3Axis()
{
    vector<vector<double>> vvData(3);
    vvData[0] = MS6_DataForAxis(0);
    vvData[1] = MS6_DataForAxis(1);
    vvData[2] = MS6_DataForAxis(2);

    QStringList QSL_cols = {MS6_DefaultTitle_Axis(0), MS6_DefaultTitle_Axis(1), MS6_DefaultTitle_Axis(2)};

    size_t n_rows = vvData[0].size();
    vector<double> vRows(n_rows);
    for(size_t i = 0; i <= n_rows; i++)
        vRows[i] = i;

    MS6_Viewer_Table.set_data_d_2D_qsl_vd(
            vvData,
            QSL_cols,
                vRows);
}

void D_MAKRO_MegaFoci::MS6_Update_Result_MosaicData()
{
    //t
    ui->spinBox_MS6_ResType_Params_MosaicData_T->setMaximum(int(dataset_dim_t - 1));
    size_t t = ui->spinBox_MS6_ResType_Params_MosaicData_T->value();

    //size
    ui->spinBox_MS6_ResType_Params_MosaicData_X_size->setMaximum(int(dataset_dim_mosaic_x - 1));
    size_t x_size_mosaic = ui->spinBox_MS6_ResType_Params_MosaicData_X_size->value();

    ui->spinBox_MS6_ResType_Params_MosaicData_Y_size->setMaximum(int(dataset_dim_mosaic_y - 1));
    size_t y_size_mosaic = ui->spinBox_MS6_ResType_Params_MosaicData_Y_size->value();

    //offset
    ui->spinBox_MS6_ResType_Params_MosaicData_X_min->setMaximum(max(0, int(dataset_dim_mosaic_x - 1 - x_size_mosaic)));
    size_t x_min_mosaic = ui->spinBox_MS6_ResType_Params_MosaicData_X_min->value();

    ui->spinBox_MS6_ResType_Params_MosaicData_Y_min->setMaximum(max(0, int(dataset_dim_mosaic_y - 1 - y_size_mosaic)));
    size_t y_min_mosaic = ui->spinBox_MS6_ResType_Params_MosaicData_Y_min->value();

    //channels
    bool use_RFP = ui->checkBox_MS6_ResType_Params_MosaicData_Ch_RFP->isChecked();
    bool use_GFP = ui->checkBox_MS6_ResType_Params_MosaicData_Ch_GFP->isChecked();
    bool use_DIC = ui->checkBox_MS6_ResType_Params_MosaicData_Ch_DIC->isChecked();
    bool channels_use[4] = {use_RFP, use_GFP, use_DIC, false};
    int channel_count = 0;
    if(use_DIC) channel_count++;
    if(use_GFP) channel_count++;
    if(use_RFP) channel_count++;

    //drawing thickness
    int thickness = ui->spinBox_MS6_ResType_Params_MosaicData_Thickness->value();
    int thick1 = max(1, thickness / 2);
    int thick2 = max(thick1 + 1, thickness);

    //text scale
    double scale_text = ui->doubleSpinBox_MS6_ResType_Params_MosaicData_TextScale->value() / 100.0;

    //scale
    double scale_full2mosaic = ui->doubleSpinBox_OverviewQuality->value() / 100.0;

    //errors
    if(vv_MS6_Mosaics_CT.size() != MS6_MOSAIC_CH_NUMBER_OF)     return;
    if(t >= vv_MS6_Mosaics_CT[0].size())                        return;

    //crop
    size_t w_full_px    = vv_MS6_Mosaics_CT[0][0].cols;
    size_t h_full_px    = vv_MS6_Mosaics_CT[0][0].rows;
    double x_mosaic2px  = double(w_full_px) / double(dataset_dim_mosaic_x);
    double y_mosaic2px  = double(h_full_px) / double(dataset_dim_mosaic_y);
    size_t w_crop_px    = x_size_mosaic * x_mosaic2px;
    size_t h_crop_px    = y_size_mosaic * y_mosaic2px;
    size_t x_start_px   = x_min_mosaic * x_mosaic2px;
    size_t y_start_px   = y_min_mosaic * y_mosaic2px;
    vector<Mat> vMA_Croped(MS5_MOSAIC_CH_NUMBER_OF);
    for(size_t c = 0; c < MS5_MOSAIC_CH_NUMBER_OF; c++)
    {
        D_Img_Proc::Crop_Rect_Abs(
                    &(vMA_Croped[c]),
                    &(vv_MS6_Mosaics_CT[c][t]),
                    x_start_px,
                    y_start_px,
                    w_crop_px,
                    h_crop_px);
    }

    //Offset
    Point P_Offset_px_scaled(x_start_px, y_start_px);

    //merge
    if(channel_count == 0)
    {
        MS6_ResultImgShow = Mat::zeros(h_crop_px, w_crop_px, CV_8UC3);
    }
    else if(channel_count == 1)
    {
        for(size_t c = 0; c < MS5_MOSAIC_CH_NUMBER_OF; c++)
        {
            if(channels_use[c])
            {
                D_Img_Proc::Duplicate2Channels(
                            &MS6_ResultImgShow,
                            &(vMA_Croped[c]),
                            3);
            }
        }
    }
    else
    {
        D_Img_Proc::Merge(
                    &MS6_ResultImgShow,
                    &(vMA_Croped[MS5_MOSAIC_CH_RFP]),
                    &(vMA_Croped[MS5_MOSAIC_CH_GFP]),
                    &(vMA_Croped[MS5_MOSAIC_CH_DIC]),
                    &(vMA_Croped[MS5_MOSAIC_CH_DIC]),
                    3,
                    channels_use);
    }

    //draw stuff

    //darw nuc contours (all)
    vector<D_Bio_NucleusBlob*> vpNucBlobs_all = MS6_NucPedigree_Results.get_pNuclei_FromNucLifes(false);
    size_t nb_all = vpNucBlobs_all.size();
    for(size_t b = 0; b < nb_all; b++)
    {
        //nuc
        D_Bio_NucleusBlob* pNucDraw = vpNucBlobs_all[b];

        if(pNucDraw->time_index() == t)
        {
            /*
            //draw dark gray big
            D_Img_Proc::Draw_Contour(
                        &MS6_MosaicImgShow,
                        pNucDraw->contour(scale_full2mosaic, -P_Offset_px_scaled),
                        thick2,
                        64, 64, 64);
                        */

            //draw light gray small
            D_Img_Proc::Draw_Contour(
                        &MS6_ResultImgShow,
                        pNucDraw->contour(scale_full2mosaic, -P_Offset_px_scaled),
                        thick1,
                        192, 192, 192);
        }
    }

    //darw nuc contours and foci count (filter passed or all)
    vector<D_Bio_NucleusBlob*> vpNucBlobs_ok = MS6_NucPedigree_Results.get_pNuclei_FromNucLifes(ui->checkBox_MS6_ResType_Params_MosaicData_Filtered->isChecked());
    size_t nb_ok = vpNucBlobs_ok.size();
    for(size_t b = 0; b < nb_ok; b++)
    {
        //nuc
        D_Bio_NucleusBlob* pNucDraw = vpNucBlobs_ok[b];

        if(pNucDraw->time_index() == t)
        {
            //color
            QColor col = pNucDraw->matching_TypeColor(MS6_NucPedigree_Results.rect_RegularRange_px(), 0, MS6_NucPedigree_Results.size_T() - 1);
            if(col.red() == 0 && col.green() == 0 && col.blue() == 0)
                col = Qt::white;

            //draw
            D_Img_Proc::Draw_Contour(
                        &MS6_ResultImgShow,
                        pNucDraw->contour(scale_full2mosaic, -P_Offset_px_scaled),
                        thick2,
                        col.red(), col.green(), col.blue());

            //foci count
            QString QS_FociCount;
            size_t nch = MS6_QSL_Channels_Foci.size();
            for(size_t ch = 0; ch < nch; ch++)
            {
                if(ch != 0)
                    QS_FociCount.append("/");
                QS_FociCount.append(QString::number(pNucDraw->get_FociCount(ch)));
            }

            //write foci count
            D_Img_Proc::Draw_Text(
                        &MS6_ResultImgShow,
                        QS_FociCount,
                        int(pNucDraw->centroid(scale_full2mosaic, -P_Offset_px_scaled).x),
                        int(pNucDraw->centroid(scale_full2mosaic, -P_Offset_px_scaled).y),
                        thick1,
                        scale_text,
                        col.red(), col.green(), col.blue());
        }
    }

    //show
    MS6_Viewer_Img_2D.Update_Image(&MS6_ResultImgShow);
}

void D_MAKRO_MegaFoci::MS6_Update_Result_NucLifeImg()
{
    if(mode_major_current != MODE_MAJOR_6_EPIC_ANALYSIS)
        return;

    //adapt ui (set max)
    size_t nl = MS6_NucPedigree_Results.get_NucleusLifesCount(true);
    if(nl <= 0)
    {
        ERR(ER_empty, "D_MAKRO_MegaFoci::MS6_Update_Result_NucLifeImg", "No nucleus lifes");
        return;
    }
    ui->spinBox_MS6_ResType_Params_NucLifeImg_NucLife->setMaximum(nl - 1);

    //get params
    size_t l                    = ui->spinBox_MS6_ResType_Params_NucLifeImg_NucLife->value();
    double scale_px2um          = ui->doubleSpinBox_MS6_Scale_px2um->value();
    double scale_t2h            = ui->doubleSpinBox_MS6_Scale_T2h->value();

    bool use_R                  = ui->checkBox_MS6_ResType_Params_NucLifeImg_R->isChecked();
    bool use_G                  = ui->checkBox_MS6_ResType_Params_NucLifeImg_G->isChecked();
    bool use_B                  = ui->checkBox_MS6_ResType_Params_NucLifeImg_B->isChecked();
    size_t frame_thickness      = ui->spinBox_MS6_ResType_Params_NucLifeImg_FrameThickness->value();
    size_t contour_thickness    = ui->spinBox_MS6_ResType_Params_NucLifeImg_ContourThickness->value();
    uchar contour_value         = 255;

    size_t text_thickness       = ui->spinBox_MS6_ResType_Params_NucLifeImg_TextThickness->value();
    double text_scale           = ui->doubleSpinBox_MS6_ResType_Params_NucLifeImg_TextScale->value() / 100.0;
    size_t text_height          = ui->spinBox_MS6_ResType_Params_NucLifeImg_TextHeight->value();
    double mosaic_scale         = ui->doubleSpinBox_OverviewQuality->value() / 100.0;

    bool text_time              = ui->checkBox_MS6_ResType_Params_NucLifeImg_Info_Time->isChecked();
    bool text_pos               = ui->checkBox_MS6_ResType_Params_NucLifeImg_Info_Position->isChecked();
    bool text_spatial           = ui->checkBox_MS6_ResType_Params_NucLifeImg_Info_SizeShift->isChecked();
    bool text_foci              = ui->checkBox_MS6_ResType_Params_NucLifeImg_Info_Foci->isChecked();

    int maxImgPerRow            = ui->spinBox_MS6_ResType_Params_NucLifeImg_maxImgsPerRow->value();

    //line counts for texts
    size_t line_count_time      = text_time     ? 3 + 1 : 0;
    size_t line_count_pos       = text_pos      ? 2 + 1 : 0;
    size_t line_count_spatial   = text_spatial  ? 2 + 1 : 0;
    size_t line_count_foci      = text_foci     ? 2 + 1 : 0;
    size_t line_count_all       = line_count_time + line_count_pos + line_count_spatial + line_count_foci;

    //nuc life
    D_Bio_NucleusLife* pNucLife = MS6_NucPedigree_Results.get_pNucleusLife(l, true);
    if(pNucLife == nullptr)
    {
        ERR(ER_empty, "D_MAKRO_MegaFoci::MS6_Update_Result_NucLifeImg", "pNucLife == nullptr");
        return;
    }

    //img stack (blobs) and texts
    size_t nb = pNucLife->members_count();
    if(nb <= 0)
    {
        ERR(ER_empty, "D_MAKRO_MegaFoci::MS6_Update_Result_NucLifeImg", "No nucleus blobs in nucleus life");
        return;
    }

    //age
    size_t t_first = pNucLife->pNuc_member(0)->time_index();
    size_t t_last = pNucLife->pNuc_member(nb - 1)->time_index();
    size_t nt = t_last - t_first + 1;

    Mat MA_tmp_MosaicSizedBlack = Mat::zeros(vv_MS6_Mosaics_CT[0][0].size(), vv_MS6_Mosaics_CT[0][0].type());
    vector<vector<QString>> vvQS_Texts(nt, vector<QString>(line_count_all));
    vector<Mat> vMA_Cropped(nt);
    for(size_t it = 0; it < nt; it++)
    {
        size_t t_tuc = t_first + it;
        D_Bio_NucleusBlob* pNuc = pNucLife->pNuc_member_byTime(t_tuc);

        if(pNuc == nullptr)
        {
            D_Contour C_before;
            D_Contour C_after;

            //seek contour before
            bool found_b = false;
            for(int it_b = int(it) - 1; it_b >= 0 && !found_b; it_b--)
            {
                size_t t_tuc_b = t_first + it_b;
                D_Bio_NucleusBlob* pNuc_b = pNucLife->pNuc_member_byTime(t_tuc_b);
                if(pNuc_b != nullptr)
                {
                    found_b = true;
                    C_before.set_contour(pNuc_b->contour(mosaic_scale, Point(0, 0)));
                }
            }

            //seek contour after
            bool found_a = false;
            for(int it_a = int(it) + 1; it_a < int(nt) && !found_a; it_a--)
            {
                size_t t_tuc_a = t_first + it_a;
                D_Bio_NucleusBlob* pNuc_a = pNucLife->pNuc_member_byTime(t_tuc_a);
                if(pNuc_a != nullptr)
                {
                    found_a = true;
                    C_after.set_contour(pNuc_a->contour(mosaic_scale, Point(0, 0)));
                }
            }

            //bounding box of merging
            D_Contour C_box;
            if(found_a && found_b)
                C_box = D_Contour(C_before.bounding_box(C_after));
            else if(found_a)
                C_box = D_Contour(C_after.bounding_box());
            else if(found_b)
                C_box = D_Contour(C_before.bounding_box());

            if(found_a || found_b)
            {
                //img and contour
                int err = D_Img_Proc::Draw_ContourCrop(
                            &(vMA_Cropped[it]),
                            use_B ? &(vv_MS6_Mosaics_CT[MS6_MOSAIC_CH_RFP][t_tuc]) : &MA_tmp_MosaicSizedBlack,
                            use_G ? &(vv_MS6_Mosaics_CT[MS6_MOSAIC_CH_GFP][t_tuc]) : &MA_tmp_MosaicSizedBlack,
                            use_R ? &(vv_MS6_Mosaics_CT[MS6_MOSAIC_CH_DIC][t_tuc]) : &MA_tmp_MosaicSizedBlack,
                            C_box.contour(),
                            contour_thickness,
                            contour_value, contour_value, contour_value,
                            false);
                if(err != ER_okay)
                {
                    ERR(err, "D_MAKRO_MegaFoci::MS6_Update_Result_NucLifeImg", "D_Img_Proc::Draw_ContourCrop - gap");
                    return;
                }
            }
            else
            {
                //no img (should never happen)
                vMA_Cropped[it] = Mat::zeros(1, 1, D_Img_Proc::TypeIndex_of_Mat(3, vv_MS6_Mosaics_CT[0][0].depth()));
            }

            //text
            if(line_count_all >= 3)
            {
                vvQS_Texts[it][0] = "invisible";
                vvQS_Texts[it][1] = "ninja";
                vvQS_Texts[it][2] = "nucleus";
            }
            else if(line_count_all >= 1)
            {
                vvQS_Texts[it][0] = "???";
            }
        }
        else
        {
            //img and contour
            int err = D_Img_Proc::Draw_ContourCrop(
                        &(vMA_Cropped[it]),
                        use_B ? &(vv_MS6_Mosaics_CT[MS6_MOSAIC_CH_RFP][t_tuc]) : &MA_tmp_MosaicSizedBlack,
                        use_G ? &(vv_MS6_Mosaics_CT[MS6_MOSAIC_CH_GFP][t_tuc]) : &MA_tmp_MosaicSizedBlack,
                        use_R ? &(vv_MS6_Mosaics_CT[MS6_MOSAIC_CH_DIC][t_tuc]) : &MA_tmp_MosaicSizedBlack,
                        pNuc->contour(mosaic_scale, Point(0, 0)),
                        contour_thickness,
                        contour_value, contour_value, contour_value);
            if(err != ER_okay)
            {
                ERR(err, "D_MAKRO_MegaFoci::MS6_Update_Result_NucLifeImg", "D_Img_Proc::Draw_ContourCrop - nuc");
                return;
            }
            //qDebug() << "croped img size x/y" << vMA_Cropped[b].cols << vMA_Cropped[b].rows;

            //texts
            int line = 0;

            if(text_time)
            {
                vvQS_Texts[it][line] = "age=" + QString::number(int(pNuc->attribute(ATTRIB_NUC_TIME_AGE_PAST, 0, scale_px2um))) + "h";
                line++;

                vvQS_Texts[it][line] = "t=" + QString::number(t_tuc * scale_t2h, 'g', 2) + "h";
                line++;

                double t_irr_diff = pNuc->attribute(ATTRIB_NUC_TIME_DIFF_TO_IRRADIATION, 0, scale_px2um);
                if(abs(t_irr_diff) <= 0.5)
                    vvQS_Texts[it][line] = "bzzzt";
                else
                    vvQS_Texts[it][line] = "(" + QString::number(int(t_irr_diff * 10) / 10.0) + "h)";
                line++;

                line++;
            }

            if(text_pos)
            {
                vvQS_Texts[it][line] = "x=" + QString::number(int(pNuc->centroid().x)) + "px";
                line++;

                vvQS_Texts[it][line] = "y=" + QString::number(int(pNuc->centroid().y)) + "px";
                line++;

                line++;
            }

            if(text_spatial)
            {
                vvQS_Texts[it][line] = QString::number(int(pNuc->attribute(ATTRIB_NUC_AREA_UM, 0, scale_px2um))) + "um^2";
                line++;

                vvQS_Texts[it][line] = "s=" + QString::number(int(pNuc->attribute(ATTRIB_NUC_SHIFT_UM, 0, scale_px2um))) + "um";
                line++;

                line++;
            }

            if(text_foci)
            {
                if(MS6_QSL_Channels_Foci.size() >= 1)
                {
                    vvQS_Texts[it][line] = MS6_QSL_Channels_Foci[0] + ": " + QString::number(pNuc->get_FociCount(0));
                    line++;
                }

                if(MS6_QSL_Channels_Foci.size() >= 2)
                {
                    vvQS_Texts[it][line] = MS6_QSL_Channels_Foci[1] + ": " + QString::number(pNuc->get_FociCount(1));
                    line++;
                }

                line++;
            }
        }
    }
    MA_tmp_MosaicSizedBlack.release();

    //merge stack to out img
    int err = D_Img_Proc::ImgStackToGrid(
                &MS6_ResultImgShow,
                &vMA_Cropped,
                vvQS_Texts,
                maxImgPerRow,
                text_thickness,
                text_scale,
                text_height,
                frame_thickness);
    if(err != ER_okay)
    {
        ERR(err, "D_MAKRO_MegaFoci::MS6_Update_Result_NucLifeImg", "D_Img_Proc::ImgStackToRow");
        return;
    }

    //show
    MS6_Viewer_Img_2D.Update_Image(&MS6_ResultImgShow);
}

bool D_MAKRO_MegaFoci::MS6_Save_Result_Current()
{
    QString QS_Save_Suffix;
    switch (ui->stackedWidget_MS6_ResView->currentIndex())
    {
    case MS6_RES_VIEW_TYPE_PLOT_2D:
    case MS6_RES_VIEW_TYPE_PLOT_3D:
    case MS6_RES_VIEW_TYPE_IMAGE_2D:
    case MS6_RES_VIEW_TYPE_IMAGE_3D:
        QS_Save_Suffix = "png";
        break;

    case MS6_RES_VIEW_TYPE_TABLE:
        QS_Save_Suffix = "csv";
        break;

    default:
        return false;
    }

    QString QS_Save_Default =
            pStore->dir_M_MegaFoci_Results()->path() +
            "/" + QDateTime::currentDateTime().toString(QS_DateTimeFormat_YearToSec).replace(".", "_").replace(":", "_") + " " + MS6_DefaultTitle_Result() + "." + QS_Save_Suffix;

    //get save name
    QString QS_Save = QFileDialog::getSaveFileName(
                this,
                "Please select save file name for result",
                QS_Save_Default,
                "(*." + QS_Save_Suffix + ")");

    //check, if save name is valid
    if(QS_Save.isEmpty())
        return false;
    else
        pStore->set_dir_M_MegaFoci_Results(QS_Save);

    //save
    switch (ui->stackedWidget_MS6_ResView->currentIndex()) {
    case MS6_RES_VIEW_TYPE_PLOT_2D:     MS6_pChartView_Plot_2D->grab().save(QS_Save);       break;
    case MS6_RES_VIEW_TYPE_PLOT_3D:     MS6_Viewer_Plot_3D.save(QS_Save);                   break;
    case MS6_RES_VIEW_TYPE_IMAGE_2D:    MS6_Viewer_Img_2D.Save_Image(QS_Save);              break;
    case MS6_RES_VIEW_TYPE_IMAGE_3D:    MS6_Viewer_Img_3D.Save(QS_Save);                    break;
    case MS6_RES_VIEW_TYPE_TABLE:       MS6_Viewer_Table.Save_Table(QS_Save);               break;
    default:                                                                                return false;}

    return true;
}

bool D_MAKRO_MegaFoci::MS6_Save_NucLifes()
{
    //get save name
    QString QS_Save = QFileDialog::getExistingDirectory(
                this,
                "Please select directory to save nuc life images in ('NucLifeImgs <DateTime>' Folder is automatically created)",
                pStore->dir_M_MegaFoci_Results()->path());

    //check, if save name is valid
    if(QS_Save.isEmpty())
        return false;
    else
        pStore->set_dir_M_MegaFoci_Results(QS_Save);

    //main save dir
    QDir DIR_SaveMain(QS_Save + "/NucLifeImgs " + QDateTime::currentDateTime().toString(QS_DateTimeFormat_YearToSec));
    if(!DIR_SaveMain.exists())
        QDir().mkdir(DIR_SaveMain.path());
    if(!DIR_SaveMain.exists())
        return false;

    //loop all nuclifes
    this->setEnabled(false);
    ui->comboBox_MS6_ResultTypes->setCurrentIndex(MS6_RES_TYP_NUC_LIFE_IMG);
    ui->spinBox_MS6_ResType_Params_NucLifeImg_NucLife->blockSignals(true);
    size_t nl = MS6_NucPedigree_Results.get_NucleusLifesCount(true);
    for(size_t l = 0; l < nl; l++)
    {
        ui->spinBox_MS6_ResType_Params_NucLifeImg_NucLife->setValue(l);
        MS6_Update_Results();
        Update_Ui();

        D_Bio_NucleusLife* pNucLife = MS6_NucPedigree_Results.get_pNucleusLife(l, true);
        if(pNucLife != nullptr)
        {
            D_Bio_NucleusBlob* pNucFirst = pNucLife->pNuc_member(0);
            if(pNucFirst != nullptr)
            {
                size_t nuc_t    = pNucFirst->time_index();
                int nuc_x       = int(pNucFirst->centroid().x);
                int nuc_y       = int(pNucFirst->centroid().y);
                MS6_Viewer_Img_2D.Save_Image(DIR_SaveMain.path() + "/NucLifeImg_T" + QString::number(nuc_t) + "_Y" + QString::number(nuc_y) + "_X" + QString::number(nuc_x) + ".png");
            }
        }
    }
    ui->spinBox_MS6_ResType_Params_NucLifeImg_NucLife->blockSignals(false);

    this->setEnabled(true);
    return ER_okay;
}

bool D_MAKRO_MegaFoci::MS6_Save_StatisticAnalysis()
{
    if(mode_major_current != MODE_MAJOR_6_EPIC_ANALYSIS)
        return false;

    //get save name
    QString QS_Save = QFileDialog::getExistingDirectory(
                this,
                "Please select directory to save statistical analysis in ('StatisticAnalysis <DateTime>' Folder is automatically created)",
                pStore->dir_M_MegaFoci_Results()->path());

    //check, if save name is valid
    if(QS_Save.isEmpty())
    {
        StatusSet("If you don't select a folder, i can't save the results we worked so hard for... " + QS_Fun_Sad);
        return false;
    }

    pStore->set_dir_M_MegaFoci_Results(QS_Save);

    //main save dir
    DIR_MS6_Out_SaveAnalysisMaster.setPath(QS_Save + "/StatisticAnalysis " + QDateTime::currentDateTime().toString(QS_DateTimeFormat_YearToSec));
    if(!DIR_MS6_Out_SaveAnalysisMaster.exists())
        QDir().mkdir(DIR_MS6_Out_SaveAnalysisMaster.path());
    if(!DIR_MS6_Out_SaveAnalysisMaster.exists())
        return false;

    //save data
    StatusSet("Start saving data");
    bool ok = MS6_NucPedigree_Results.save_analysis(DIR_MS6_Out_SaveAnalysisMaster.path());

    //success?
    if(ok)
        StatusSet("Saved data successfully " + QS_Fun_Happy);
    else
        StatusSet("Failed saving data " + QS_Fun_Sad);

    //finish
    return ok;
}

void D_MAKRO_MegaFoci::on_checkBox_MS6_ResType_Param_PoolStatLine_AutoRange_clicked(bool checked)
{
    ui->doubleSpinBox_MS6_ResType_Param_PoolStatLine_MinX->setEnabled(!checked);
    ui->doubleSpinBox_MS6_ResType_Param_PoolStatLine_StepX->setEnabled(!checked);
}

void D_MAKRO_MegaFoci::on_checkBox_MS6_ResType_Params_ScatterHeatmap_ManuelRange_x_clicked(bool checked)
{
    ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Min_x->setEnabled(!checked);
    ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Step_x->setEnabled(!checked);
}

void D_MAKRO_MegaFoci::on_checkBox_MS6_ResType_Params_ScatterHeatmap_ManuelRange_y_clicked(bool checked)
{
    ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Min_y->setEnabled(!checked);
    ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Step_y->setEnabled(!checked);
}

void D_MAKRO_MegaFoci::on_spinBox_MS6_MarginToBorder_valueChanged(int arg1)
{
    ui->spinBox_MS6_MarginToBorder->setSuffix("px (=" + QString::number(int(arg1 * ui->doubleSpinBox_MS6_Scale_px2um->value())) + "um)");
}

void D_MAKRO_MegaFoci::on_doubleSpinBox_MS6_Scale_px2um_valueChanged(double arg1)
{
    ui->spinBox_MS6_MarginToBorder->setSuffix("px (=" + QString::number(int(ui->spinBox_MS6_MarginToBorder->value() * arg1)) + "um)");
}

void D_MAKRO_MegaFoci::on_comboBox_MS6_ResultTypes_currentIndexChanged(int index)
{
    if(index == MS6_RES_TYP_SCATTER_HEATMAP_2D)
    {
        ui->stackedWidget_MS6_ResType_Params->setCurrentIndex(MS6_RES_TYP_SCATTER_HEATMAP_3D);
        ui->checkBox_MS6_ResType_Params_ScatterHeatmap_Height->setEnabled(false);
        ui->checkBox_MS6_ResType_Params_ScatterHeatmap_Wireframe->setEnabled(false);
    }

    if(index == MS6_RES_TYP_SCATTER_HEATMAP_3D)
    {
        ui->checkBox_MS6_ResType_Params_ScatterHeatmap_Height->setEnabled(true);
        ui->checkBox_MS6_ResType_Params_ScatterHeatmap_Wireframe->setEnabled(true);
    }
}

void D_MAKRO_MegaFoci::on_pushButton_MS6_SaveAnalysis_clicked()
{
    MS6_Save_StatisticAnalysis();
}

void D_MAKRO_MegaFoci::on_spinBox_MS6_ResType_Params_MosaicData_T_valueChanged(int arg1)
{
    MS6_Update_Results();
}

void D_MAKRO_MegaFoci::on_spinBox_MS6_ResType_Params_NucLifeImg_NucLife_valueChanged(int arg1)
{
    MS6_Update_Results();
}

void D_MAKRO_MegaFoci::on_pushButton_MS6_SaveResult_clicked()
{
    MS6_Save_Result_Current();
}

void D_MAKRO_MegaFoci::on_pushButton_MS6_SaveNucLifes_clicked()
{
    MS6_Save_NucLifes();
}

void D_MAKRO_MegaFoci::on_checkBox_S6_StyleAxis_CustomRange_X_clicked(bool checked)
{
    ui->doubleSpinBox_S6_StyleAxis_CustomMin_X->setEnabled(checked);
    ui->doubleSpinBox_S6_StyleAxis_CustomMax_X->setEnabled(checked);
    ui->spinBox_S6_StyleAxis_CustomTick_X->setEnabled(checked);
}

void D_MAKRO_MegaFoci::on_checkBox_S6_StyleAxis_CustomRange_Y_clicked(bool checked)
{
    ui->doubleSpinBox_S6_StyleAxis_CustomMin_Y->setEnabled(checked);
    ui->doubleSpinBox_S6_StyleAxis_CustomMax_Y->setEnabled(checked);
    ui->spinBox_S6_StyleAxis_CustomTick_Y->setEnabled(checked);
}

void D_MAKRO_MegaFoci::on_checkBox_S6_StyleAxis_CustomRange_Z_clicked(bool checked)
{
    ui->doubleSpinBox_S6_StyleAxis_CustomMin_Z->setEnabled(checked);
    ui->doubleSpinBox_S6_StyleAxis_CustomMax_Z->setEnabled(checked);
    ui->spinBox_S6_StyleAxis_CustomTick_Z->setEnabled(checked);
}


void D_MAKRO_MegaFoci::on_checkBox_S6_StyleAxis_CustomTitle_X_clicked(bool checked)
{
    ui->lineEdit_S6_StyleAxis_CustomTitle_X->setEnabled(checked);
}

void D_MAKRO_MegaFoci::on_checkBox_S6_StyleAxis_CustomTitle_Y_clicked(bool checked)
{
    ui->lineEdit_S6_StyleAxis_CustomTitle_Y->setEnabled(checked);
}

void D_MAKRO_MegaFoci::on_checkBox_S6_StyleAxis_CustomTitle_Z_clicked(bool checked)
{
    ui->lineEdit_S6_StyleAxis_CustomTitle_Z->setEnabled(checked);
}

void D_MAKRO_MegaFoci::on_checkBox_S6_SytleGeneral_CustomTitle_clicked(bool checked)
{
    ui->lineEdit_S6_StyleGeneral_CustomTitle->setEnabled(checked);
}

void D_MAKRO_MegaFoci::on_checkBox_S6_SytleGeneral_CustomSeries_clicked(bool checked)
{
    ui->lineEdit_S6_StyleGeneral_CustomSeries->setEnabled(checked);
}

void D_MAKRO_MegaFoci::on_verticalSlider_MS6_ResSize_valueChanged(int value)
{
    if(value >= 100)
        ui->label_MS6_ResSize_Height->setFixedHeight(int(ui->verticalSlider_MS6_ResSize->height() * (1.0 - (value /  1000.0))));
    else
        ui->verticalSlider_MS6_ResSize->setValue(100);
}

void D_MAKRO_MegaFoci::on_horizontalSlider_MS6_ResSize_valueChanged(int value)
{
    if(value >= 100)
        ui->label_MS6_ResSize_Width->setFixedWidth(int(ui->horizontalSlider_MS6_ResSize->width() * (1.0 - (value / 1000.0))));
    else
        ui->horizontalSlider_MS6_ResSize->setValue(100);
}

void D_MAKRO_MegaFoci::on_checkBox_MS6_ResType_Param_PoolStatLine_DualErr_AutoRange_clicked(bool checked)
{
    ui->doubleSpinBox_MS6_ResType_Param_PoolStatLine_DualErr_MinX->setEnabled(!checked);
    ui->doubleSpinBox_MS6_ResType_Param_PoolStatLine_DualErr_StepX->setEnabled(!checked);
}

void D_MAKRO_MegaFoci::on_pushButton_MS6_DefaultPlot_FociVsTime_clicked()
{
    //main
    ui->comboBox_MS6_ResultTypes->setCurrentIndex(MS6_RES_TYP_POOL_STAT_LINE_SINGLE);
    ui->comboBox_MS6_ResultDatapointLevel->setCurrentIndex(DATAPOINT_LEVEL_NUCBLOB);

    //x
    ui->comboBox_MS6_ResAxis_Level_NucBlob_0->setCurrentIndex(DATA_LEVEL_NUCBLOB_ATTRIB);
    ui->comboBox_MS6_ResAxis_Attrib_NucBlob_0->setCurrentIndex(ATTRIB_NUC_TIME_DIFF_TO_IRRADIATION);

    //y
    ui->comboBox_MS6_ResAxis_Level_NucBlob_1->setCurrentIndex(DATA_LEVEL_NUCBLOB_ATTRIB);
    ui->comboBox_MS6_ResAxis_Attrib_NucBlob_1->setCurrentIndex(ATTRIB_NUC_FOCI_COUNT_CHX);

    //plot type specific
    ui->checkBox_MS6_ResType_Param_PoolStatLine_AutoRange->setChecked(false);
    ui->doubleSpinBox_MS6_ResType_Param_PoolStatLine_MinX->setEnabled(true);
    ui->doubleSpinBox_MS6_ResType_Param_PoolStatLine_MinX->setValue(-30.5);
    ui->doubleSpinBox_MS6_ResType_Param_PoolStatLine_StepX->setEnabled(true);
    ui->doubleSpinBox_MS6_ResType_Param_PoolStatLine_StepX->setValue(1);
    ui->spinBox_MS6_ResType_Param_PoolStatLine_Classes->setEnabled(true);
    ui->spinBox_MS6_ResType_Param_PoolStatLine_Classes->setValue(61);
    ui->comboBox_MS6_ResType_Param_PoolStatLine_Stat->setCurrentIndex(c_STAT_MEAN_ARITMETIC);

    //style x
    //range
    ui->checkBox_S6_StyleAxis_CustomRange_X->setChecked(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMin_X->setEnabled(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMin_X->setValue(-30);
    ui->doubleSpinBox_S6_StyleAxis_CustomMax_X->setEnabled(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMax_X->setValue(+30);
    ui->spinBox_S6_StyleAxis_CustomTick_X->setEnabled(true);
    ui->spinBox_S6_StyleAxis_CustomTick_X->setValue(11);
    //title
    ui->checkBox_S6_StyleAxis_CustomTitle_X->setChecked(true);
    ui->lineEdit_S6_StyleAxis_CustomTitle_X->setEnabled(true);
    ui->lineEdit_S6_StyleAxis_CustomTitle_X->setText("Time(irradiation) / h");

    //style y
    //range
    ui->checkBox_S6_StyleAxis_CustomRange_Y->setChecked(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMin_Y->setEnabled(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMin_Y->setValue(0);
    ui->doubleSpinBox_S6_StyleAxis_CustomMax_Y->setEnabled(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMax_Y->setValue(15);
    ui->spinBox_S6_StyleAxis_CustomTick_Y->setEnabled(true);
    ui->spinBox_S6_StyleAxis_CustomTick_Y->setValue(16);
    //title
    ui->checkBox_S6_StyleAxis_CustomTitle_Y->setChecked(true);
    ui->lineEdit_S6_StyleAxis_CustomTitle_Y->setEnabled(true);
    ui->lineEdit_S6_StyleAxis_CustomTitle_Y->setText(MS6_vCB_ResAxis_AttribChannel_Foc[1]->currentText() + " foci");

    //style general
    ui->checkBox_S6_SytleGeneral_CustomTitle->setChecked(true);
    ui->lineEdit_S6_StyleGeneral_CustomTitle->setText(MS6_vCB_ResAxis_AttribChannel_Foc[1]->currentText() + " foci vs time");

    //update
    MS6_Update_Results();
}

void D_MAKRO_MegaFoci::on_pushButton_MS6_DefaultPlot_FociVsTime_WithError_clicked()
{
    //main
    ui->comboBox_MS6_ResultTypes->setCurrentIndex(MS6_RES_TYP_POOL_STAT_LINE_DUAL_WITH_ERROR);
    ui->comboBox_MS6_ResultDatapointLevel->setCurrentIndex(DATAPOINT_LEVEL_NUCBLOB);

    //x
    ui->comboBox_MS6_ResAxis_Level_NucBlob_0->setCurrentIndex(DATA_LEVEL_NUCBLOB_ATTRIB);
    ui->comboBox_MS6_ResAxis_Attrib_NucBlob_0->setCurrentIndex(ATTRIB_NUC_TIME_DIFF_TO_IRRADIATION);

    //y
    ui->comboBox_MS6_ResAxis_Level_NucBlob_1->setCurrentIndex(DATA_LEVEL_NUCBLOB_ATTRIB);
    ui->comboBox_MS6_ResAxis_Attrib_NucBlob_1->setCurrentIndex(ATTRIB_NUC_FOCI_COUNT_CHX);

    //plot type specific
    ui->checkBox_MS6_ResType_Param_PoolStatLine_DualErr_AutoRange->setChecked(false);
    ui->doubleSpinBox_MS6_ResType_Param_PoolStatLine_DualErr_MinX->setEnabled(true);
    ui->doubleSpinBox_MS6_ResType_Param_PoolStatLine_DualErr_MinX->setValue(-30.5);
    ui->doubleSpinBox_MS6_ResType_Param_PoolStatLine_DualErr_StepX->setEnabled(true);
    ui->doubleSpinBox_MS6_ResType_Param_PoolStatLine_DualErr_StepX->setValue(1);
    ui->spinBox_MS6_ResType_Param_PoolStatLine_DualErr_Classes->setEnabled(true);
    ui->spinBox_MS6_ResType_Param_PoolStatLine_DualErr_Classes->setValue(61);
    ui->comboBox_MS6_ResType_Param_PoolStatLine_DualErr_Stat_1stVal->setCurrentIndex(c_STAT_MEAN_ARITMETIC);
    ui->comboBox_MS6_ResType_Param_PoolStatLine_DualErr_Stat_1stErr->setCurrentIndex(c_STAT_SEM_ABS_TOTAL);
    ui->comboBox_MS6_ResType_Param_PoolStatLine_DualErr_Stat_2ndVal->setCurrentIndex(c_STAT_COUNT);

    //style x
    //range
    ui->checkBox_S6_StyleAxis_CustomRange_X->setChecked(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMin_X->setEnabled(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMin_X->setValue(-30);
    ui->doubleSpinBox_S6_StyleAxis_CustomMax_X->setEnabled(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMax_X->setValue(+30);
    ui->spinBox_S6_StyleAxis_CustomTick_X->setEnabled(true);
    ui->spinBox_S6_StyleAxis_CustomTick_X->setValue(11);
    //title
    ui->checkBox_S6_StyleAxis_CustomTitle_X->setChecked(true);
    ui->lineEdit_S6_StyleAxis_CustomTitle_X->setEnabled(true);
    ui->lineEdit_S6_StyleAxis_CustomTitle_X->setText("Time(irradiation) / h");

    //style y
    //range
    ui->checkBox_S6_StyleAxis_CustomRange_Y->setChecked(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMin_Y->setEnabled(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMin_Y->setValue(0);
    ui->doubleSpinBox_S6_StyleAxis_CustomMax_Y->setEnabled(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMax_Y->setValue(15);
    ui->spinBox_S6_StyleAxis_CustomTick_Y->setEnabled(true);
    ui->spinBox_S6_StyleAxis_CustomTick_Y->setValue(16);
    //title
    ui->checkBox_S6_StyleAxis_CustomTitle_Y->setChecked(true);
    ui->lineEdit_S6_StyleAxis_CustomTitle_Y->setEnabled(true);
    ui->lineEdit_S6_StyleAxis_CustomTitle_Y->setText(MS6_vCB_ResAxis_AttribChannel_Foc[1]->currentText() + " foci");

    //style general
    ui->checkBox_S6_SytleGeneral_CustomTitle->setChecked(true);
    ui->lineEdit_S6_StyleGeneral_CustomTitle->setText(MS6_vCB_ResAxis_AttribChannel_Foc[1]->currentText() + " foci vs time");

    //update
    MS6_Update_Results();
}

void D_MAKRO_MegaFoci::on_pushButton_MS6_DefaultPlot_FociVsTimeAndCellCycle_clicked()
{
    //main
    ui->comboBox_MS6_ResultTypes->setCurrentIndex(MS6_RES_TYP_SCATTER_HEATMAP_2D);
    ui->comboBox_MS6_ResultDatapointLevel->setCurrentIndex(DATAPOINT_LEVEL_NUCBLOB);

    //x
    ui->comboBox_MS6_ResAxis_Level_NucBlob_0->setCurrentIndex(DATA_LEVEL_NUCBLOB_ATTRIB);
    ui->comboBox_MS6_ResAxis_Attrib_NucBlob_0->setCurrentIndex(ATTRIB_NUC_TIME_DIFF_TO_IRRADIATION);

    //y
    ui->comboBox_MS6_ResAxis_Level_NucBlob_1->setCurrentIndex(DATA_LEVEL_NUCBLOB_ATTRIB);
    ui->comboBox_MS6_ResAxis_Attrib_NucBlob_1->setCurrentIndex(ATTRIB_NUC_TIME_AGE_PAST);

    //color
    ui->comboBox_MS6_ResAxis_Level_NucBlob_2->setCurrentIndex(DATA_LEVEL_NUCBLOB_ATTRIB);
    ui->comboBox_MS6_ResAxis_Attrib_NucBlob_2->setCurrentIndex(ATTRIB_NUC_FOCI_COUNT_CHX);

    //plot type specific
    //x
    ui->checkBox_MS6_ResType_Params_ScatterHeatmap_ManuelRange_x->setChecked(false);
    ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Min_x->setEnabled(true);
    ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Min_x->setValue(-30);
    ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Step_x->setEnabled(true);
    ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Step_x->setValue(1);
    ui->spinBox_MS6_ResType_Params_ScatterHeatmap_Classes_x->setEnabled(true);
    ui->spinBox_MS6_ResType_Params_ScatterHeatmap_Classes_x->setValue(61);
    //y
    ui->checkBox_MS6_ResType_Params_ScatterHeatmap_ManuelRange_y->setChecked(false);
    ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Min_y->setEnabled(true);
    ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Min_y->setValue(0);
    ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Step_y->setEnabled(true);
    ui->doubleSpinBox_MS6_ResType_Params_ScatterHeatmap_Step_y->setValue(1);
    ui->spinBox_MS6_ResType_Params_ScatterHeatmap_Classes_y->setEnabled(true);
    ui->spinBox_MS6_ResType_Params_ScatterHeatmap_Classes_y->setValue(61);
    //color
    ui->comboBox_MS6_ResType_Params_ScatterHeatmap_Stat->setCurrentIndex(c_STAT_MEAN_ARITMETIC);

    //style x
    //range
    ui->checkBox_S6_StyleAxis_CustomRange_X->setChecked(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMin_X->setEnabled(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMin_X->setValue(-30);
    ui->doubleSpinBox_S6_StyleAxis_CustomMax_X->setEnabled(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMax_X->setValue(+30);
    ui->spinBox_S6_StyleAxis_CustomTick_X->setEnabled(true);
    ui->spinBox_S6_StyleAxis_CustomTick_X->setValue(11);
    //title
    ui->checkBox_S6_StyleAxis_CustomTitle_X->setChecked(true);
    ui->lineEdit_S6_StyleAxis_CustomTitle_X->setEnabled(true);
    ui->lineEdit_S6_StyleAxis_CustomTitle_X->setText("Time(irradiation) / h");

    //style y
    //range
    ui->checkBox_S6_StyleAxis_CustomRange_Y->setChecked(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMin_Y->setEnabled(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMin_Y->setValue(0);
    ui->doubleSpinBox_S6_StyleAxis_CustomMax_Y->setEnabled(true);
    ui->doubleSpinBox_S6_StyleAxis_CustomMax_Y->setValue(60);
    ui->spinBox_S6_StyleAxis_CustomTick_Y->setEnabled(true);
    ui->spinBox_S6_StyleAxis_CustomTick_Y->setValue(11);
    //title
    ui->checkBox_S6_StyleAxis_CustomTitle_Y->setChecked(true);
    ui->lineEdit_S6_StyleAxis_CustomTitle_Y->setEnabled(true);
    ui->lineEdit_S6_StyleAxis_CustomTitle_Y->setText("Time(cell cycle) / h");

    //style general
    ui->checkBox_S6_SytleGeneral_CustomTitle->setChecked(true);
    ui->lineEdit_S6_StyleGeneral_CustomTitle->setText(MS6_vCB_ResAxis_AttribChannel_Foc[1]->currentText() + " foci vs irradiation time and cell cycle");

    //update
    MS6_Update_Results();
}
