#include "d_makro_osteoclasts.h"
#include "ui_d_makro_osteoclasts.h"

D_MAKRO_Osteoclasts::D_MAKRO_Osteoclasts(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_Osteoclasts)
{
    //if(MessageOnFunctionStart)        qDebug() << "D_MAKRO_Osteoclasts Constructor";

    state_Startup = true;

    ui->setupUi(this);

    pStore = pStorage;

    Populate_CB_All_onStartUp();
    Images_VisVPin_init();

    //Viewer
    View_Proc.set_GV(ui->graphicsView_Proc);

    //CONNECTS

    //next image
    connect(ui->comboBox_Viewport,                          SIGNAL(currentIndexChanged(int)),           this,                           SLOT(Update_newViewport()));
    //View
    connect(ui->action_Update_Views,                        SIGNAL(triggered(bool)),                    this,                           SLOT(Update_Views()));
    connect(&View_Proc,                                     SIGNAL(MouseMoved_Pos(int,int)),            this,                           SLOT(VisVP_MouseMovedOnScene(int,int)));
    connect(ui->comboBox_SegAuto_Step,                      SIGNAL(currentIndexChanged(int)),           this,                           SLOT(Update_Image_ProcView()));
    connect(ui->comboBox_SegMan_SegmentationType,           SIGNAL(currentIndexChanged(int)),           this,                           SLOT(Update_Image_ProcView()));
    //Draw
    connect(&View_Proc,                                     SIGNAL(MouseClicked_Pos(int,int)),          this,                           SLOT(SegmentationManual_TriggerDraw(int,int)));
    connect(ui->pushButton_SegMan_Reset,                    SIGNAL(clicked(bool)),                      this,                           SLOT(SegmentationManual_Reset()));
    connect(ui->pushButton_SegMan_Undo,                     SIGNAL(clicked(bool)),                      this,                           SLOT(SegmentationManual_Undo()));
    //Image
    connect(ui->tabWidget_Proc_Settings,                    SIGNAL(currentChanged(int)),                this,                           SLOT(Update_Image_ProcView()));
    //VisVP
    connect(ui->comboBox_VisVP_ProjectionStat,              SIGNAL(currentIndexChanged(int)),           this,                           SLOT(Update_Image_ProcView()));
    connect(ui->checkBox_VisVP_Show_B,                      SIGNAL(clicked(bool)),                      this,                           SLOT(Update_Image_ProcView()));
    connect(ui->checkBox_VisVP_Show_G,                      SIGNAL(clicked(bool)),                      this,                           SLOT(Update_Image_ProcView()));
    connect(ui->checkBox_VisVP_Show_R,                      SIGNAL(clicked(bool)),                      this,                           SLOT(Update_Image_ProcView()));
    connect(ui->checkBox_VisVP_ZProject_B,                  SIGNAL(clicked(bool)),                      this,                           SLOT(Update_Image_ProcView()));
    connect(ui->checkBox_VisVP_ZProject_G,                  SIGNAL(clicked(bool)),                      this,                           SLOT(Update_Image_ProcView()));
    connect(ui->checkBox_VisVP_ZProject_R,                  SIGNAL(clicked(bool)),                      this,                           SLOT(Update_Image_ProcView()));
    connect(ui->spinBox_VisVP_ZLayer,                       SIGNAL(valueChanged(int)),                  this,                           SLOT(Update_Image_ProcView()));
    connect(ui->doubleSpinBox_VisVP_Range_Min_B,            SIGNAL(valueChanged(double)),               this,                           SLOT(Update_Image_ProcView()));
    connect(ui->doubleSpinBox_VisVP_Range_Min_G,            SIGNAL(valueChanged(double)),               this,                           SLOT(Update_Image_ProcView()));
    connect(ui->doubleSpinBox_VisVP_Range_Min_R,            SIGNAL(valueChanged(double)),               this,                           SLOT(Update_Image_ProcView()));
    connect(ui->doubleSpinBox_VisVP_Range_Max_B,            SIGNAL(valueChanged(double)),               this,                           SLOT(Update_Image_ProcView()));
    connect(ui->doubleSpinBox_VisVP_Range_Max_G,            SIGNAL(valueChanged(double)),               this,                           SLOT(Update_Image_ProcView()));
    connect(ui->doubleSpinBox_VisVP_Range_Max_R,            SIGNAL(valueChanged(double)),               this,                           SLOT(Update_Image_ProcView()));
    connect(ui->doubleSpinBox_VisVP_Gamma_B,                SIGNAL(valueChanged(double)),               this,                           SLOT(Update_Image_ProcView()));
    connect(ui->doubleSpinBox_VisVP_Gamma_G,                SIGNAL(valueChanged(double)),               this,                           SLOT(Update_Image_ProcView()));
    connect(ui->doubleSpinBox_VisVP_Gamma_R,                SIGNAL(valueChanged(double)),               this,                           SLOT(Update_Image_ProcView()));
    connect(ui->checkBox_VisVP_Auto,                        SIGNAL(clicked(bool)),                      this,                           SLOT(Update_Image_ProcView()));

    //Data
    connect(ui->action_Load_Dataset,                        SIGNAL(triggered(bool)),                    this,                           SLOT(Load_Platelet()));
    //Segmentation
    connect(ui->pushButton_SegMan_NextSegmentation,         SIGNAL(clicked(bool)),                      this,                           SLOT(Segmentation_Next()));



    //Stuff on Start
    setWindowTitle("ImageD - Osteoclasts Plugin");
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));

    Extrema_Init();

    this->showMaximized();
    state_Startup = false;


    Load_Platelet();
}

D_MAKRO_Osteoclasts::~D_MAKRO_Osteoclasts()
{
    //if(MessageOnFunctionStart)        qDebug() << "D_MAKRO_Osteoclasts Destructor";
    delete ui;
}

void D_MAKRO_Osteoclasts::closeEvent(QCloseEvent *event)
{
    //if(MessageOnFunctionStart)        qDebug() << "D_MAKRO_Osteoclasts closeEvent";

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

void D_MAKRO_Osteoclasts::resizeEvent(QResizeEvent *event)
{
    //if(MessageOnFunctionStart)        qDebug() << "D_MAKRO_Osteoclasts resizeEvent";

    event->accept();
    Update_Views();
}

void D_MAKRO_Osteoclasts::mousePressEvent(QMouseEvent *event)
{
    //start new line on right click
    if(event->button() == Qt::RightButton)
    {
        //if(MessageOnFunctionStart)        qDebug() << "D_MAKRO_Osteoclasts mousePressEvent";

        state_SegMan_Draw_NewLine = true;
    }
}

void D_MAKRO_Osteoclasts::Update_Views()
{
    if(state_Startup)
    {
        ERR_StatesCheck("Update_Views");
        return;
    }

    //if(MessageOnFunctionStart)        qDebug() << "D_MAKRO_Osteoclasts Update_Views";

    Update_View_Proc();
}

void D_MAKRO_Osteoclasts::Update_View_Proc()
{
    if(state_Startup)
    {
        ERR_StatesCheck("Update_View_Proc");
        return;
    }

    //if(MessageOnFunctionStart)        qDebug() << "D_MAKRO_Osteoclasts Update_View_Proc";

    View_Proc.Update_View();
}

void D_MAKRO_Osteoclasts::Update_Images()
{
    if(state_Startup)
    {
        ERR_StatesCheck("Update_Images");
        return;
    }

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Update_Images";

    Update_Image_ProcView();
}

void D_MAKRO_Osteoclasts::Update_Image_ProcView()
{
    if(state_Startup)
    {
        ERR_StatesCheck("Update_Image_ProcView");
        return;
    }

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Update_Image_ProcView";

    switch (ui->tabWidget_Proc_Settings->currentIndex()) {
    case c_PROC_VIEW_STACK:         Update_Image_ProcView_Visualize();          break;
    case c_PROC_VIEW_SEG_AUTO:      Update_Image_ProcView_SegmentationAuto();   break;
    case c_PROC_VIEW_SEG_MANUAL:    Update_Image_ProcView_SegmentationManual(); break;
    default:                                                                    break;}
}

void D_MAKRO_Osteoclasts::Update_Image_ProcView_Visualize()
{
    if(state_Startup)
    {
        ERR_StatesCheck("Update_Image_ProcView_Visualize");
        return;
    }

    //Update Vis
    Visualize_DataSet();

    if(!state_VisVp_Done)
        return;

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Update_Image_ProcView_Visualize";

    //Show
    View_Proc.Update_Image(&MA_VisVP_3ch);
}

void D_MAKRO_Osteoclasts::Update_Image_ProcView_SegmentationAuto()
{
    if(!state_SegAuto_Done)
        Update_NucleiSegmentation_Auto();
    if(!state_SegAuto_Done)
    {
        ERR_StatesCheck("Update_Image_ProcView_SegmentationAuto");
        return;
    }

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Update_Image_ProcView_SegmentationAuto";

    View_Proc.Update_Image(&(vvMA_VpStep_NucAutoSeg[VP_current][ui->comboBox_SegAuto_Step->currentIndex()]));
}

void D_MAKRO_Osteoclasts::Update_Image_ProcView_SegmentationManual()
{
    if(!state_VisVp_Done)
        Visualize_DataSet();
    if(!state_SegAuto_Done)
        Update_NucleiSegmentation_Auto();
    if(!state_SegMan_Combined)
        Segmentations_Combine();

    if(!state_VisVp_Done || !state_SegMan_Combined || !state_SegAuto_Done)
    {
        ERR_StatesCheck("Update_Image_ProcView_SegmentationManual");
        return;
    }

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Update_Image_ProcView_SegmentationManual";

    int index_seg_current = ui->comboBox_SegMan_SegmentationType->currentIndex();

    //segmentations combination
    Mat MA_tmp_seg_current;
    Mat MA_tmp_seg_other;
    Mat MA_tmp_seg_combi;

    //define current and other segmentations
    switch (index_seg_current) {

    case c_SEG_CELLS:
    {
        ERR(D_Img_Proc::Reduce_Outlines(
                &MA_tmp_seg_current,
                &(vvMA_VpSeg_Manual_Combined[VP_current][c_SEG_CELLS])),
            "Update_Image_ProcView_SegmentationManual",
            "c_SEG_CELLS - Reduce_Outlines - c_SEG_CELLS");

        Mat MA_tmp_seg_zones;
        ERR(D_Img_Proc::Reduce_Outlines(
                &MA_tmp_seg_zones,
                &(vvMA_VpSeg_Manual_Combined[VP_current][c_SEG_ZONES])),
            "Update_Image_ProcView_SegmentationManual",
            "c_SEG_CELLS - Reduce_Outlines - c_SEG_ZONES");

        Mat MA_tmp_seg_nuclei;
        ERR(D_Img_Proc::Reduce_Outlines(
                &MA_tmp_seg_nuclei,
                &(vvMA_VpSeg_Manual_Combined[VP_current][c_SEG_NUCLEI])),
            "Update_Image_ProcView_SegmentationManual",
            "c_SEG_CELLS - Reduce_Outlines - c_SEG_NUCLEI");

        ERR(D_Img_Proc::Math_ImgImg_Add(
                &MA_tmp_seg_other,
                &MA_tmp_seg_zones,
                &MA_tmp_seg_nuclei),
            "Update_Image_ProcView_SegmentationManual",
            "c_SEG_CELLS - Math_ImgImg_Add - combine other segmentations");

        MA_tmp_seg_nuclei.release();
        MA_tmp_seg_zones.release();
    }
        break;

    case c_SEG_ZONES:
    {
        ERR(D_Img_Proc::Reduce_Outlines(
                &MA_tmp_seg_current,
                &(vvMA_VpSeg_Manual_Combined[VP_current][c_SEG_ZONES])),
            "Update_Image_ProcView_SegmentationManual",
            "c_SEG_ZONES - Reduce_Outlines - c_SEG_ZONES");

        Mat MA_tmp_seg_cells;
        ERR(D_Img_Proc::Reduce_Outlines(
                &MA_tmp_seg_cells,
                &(vvMA_VpSeg_Manual_Combined[VP_current][c_SEG_CELLS])),
            "Update_Image_ProcView_SegmentationManual",
            "c_SEG_ZONES - Reduce_Outlines - c_SEG_CELLS");

        Mat MA_tmp_seg_nuclei;
        ERR(D_Img_Proc::Reduce_Outlines(
                &MA_tmp_seg_nuclei,
                &(vvMA_VpSeg_Manual_Combined[VP_current][c_SEG_NUCLEI])),
            "Update_Image_ProcView_SegmentationManual",
            "c_SEG_ZONES - Reduce_Outlines - c_SEG_NUCLEI");

        ERR(D_Img_Proc::Math_ImgImg_Add(
                &MA_tmp_seg_other,
                &MA_tmp_seg_cells,
                &MA_tmp_seg_nuclei),
            "Update_Image_ProcView_SegmentationManual",
            "c_SEG_ZONES - Math_ImgImg_Add - combine other segmentations");

        MA_tmp_seg_nuclei.release();
        MA_tmp_seg_cells.release();
    }
        break;

    case c_SEG_NUCLEI:
    {
        ERR(D_Img_Proc::Reduce_Outlines(
                &MA_tmp_seg_current,
                &(vvMA_VpSeg_Manual_Combined[VP_current][c_SEG_NUCLEI])),
            "Update_Image_ProcView_SegmentationManual",
            "c_SEG_NUCLEI - Reduce_Outlines - c_SEG_NUCLEI");

        Mat MA_tmp_seg_cells;
        ERR(D_Img_Proc::Reduce_Outlines(
                &MA_tmp_seg_cells,
                &(vvMA_VpSeg_Manual_Combined[VP_current][c_SEG_CELLS])),
            "Update_Image_ProcView_SegmentationManual",
            "c_SEG_NUCLEI - Reduce_Outlines - c_SEG_CELLS");

        Mat MA_tmp_seg_zones;
        ERR(D_Img_Proc::Reduce_Outlines(
                &MA_tmp_seg_zones,
                &(vvMA_VpSeg_Manual_Combined[VP_current][c_SEG_ZONES])),
            "Update_Image_ProcView_SegmentationManual",
            "c_SEG_NUCLEI - Reduce_Outlines - c_SEG_ZONES");

        ERR(D_Img_Proc::Math_ImgImg_Add(
                &MA_tmp_seg_other,
                &MA_tmp_seg_cells,
                &MA_tmp_seg_zones),
            "Update_Image_ProcView_SegmentationManual",
            "c_SEG_NUCLEI - Math_ImgImg_Add - combine other segmentations");

        MA_tmp_seg_cells.release();
        MA_tmp_seg_zones.release();
    }
        break;

    default:
        break;
    }

    //combine segmentations to black/gray/white image
    ERR(D_Img_Proc::Math_ImgImg_AddWeighted(
            &MA_tmp_seg_combi,
            &MA_tmp_seg_current,
            &MA_tmp_seg_other,
            1,
            0.5,
            1),
        "Update_Image_ProcView_SegmentationManual",
        "Math_ImgImg_Add - combine segmentations to black/gray/white image");

    //3-ch version of segmentations
    Mat MA_tmp_seg_combi_3ch;
    ERR(D_Img_Proc::Merge(
            &MA_tmp_seg_combi_3ch,
            &MA_tmp_seg_combi,
            &MA_tmp_seg_combi,
            &MA_tmp_seg_combi),
        "Update_Image_ProcView_SegmentationManual",
        "Merge - 3channel version of segmentations");

    Mat MA_tmp_coloredBackground;
    ERR(D_Img_Proc::Normalize(
            &MA_tmp_coloredBackground,
            &MA_VisVP_3ch,
            CV_MINMAX,
            CV_8UC1,
            0,
            255),
        "Update_Image_ProcView_SegmentationManual",
        "Normalize - colored background from visualizer normalize to 8bit");

    Mat MA_tmp_display;
    ERR(D_Img_Proc::Math_ImgImg_Add(
            &MA_tmp_display,
            &MA_tmp_seg_combi_3ch,
            &MA_tmp_coloredBackground),
        "Update_Image_ProcView_SegmentationManual",
        "Math_ImgImg_Add - segmentations + colored background = displayed image");

    View_Proc.Update_Image(&MA_tmp_display);

    MA_tmp_seg_current.release();
    MA_tmp_seg_other.release();
    MA_tmp_seg_combi.release();
    MA_tmp_seg_combi_3ch.release();
    MA_tmp_coloredBackground.release();
    MA_tmp_display.release();
}

void D_MAKRO_Osteoclasts::Update_newViewport()
{
    if(!state_Platelet_Loaded)
    {
        ERR_StatesCheck("Update_newViewport");
        return;
    }

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Update_newViewport";

    state_Viewport_New = true;
    state_VisVp_Done = false;
    state_Viewport_Loaded = false;
    state_SegAuto_Done = false;
    state_SegMan_Init = false;
    state_SegMan_Scanned = false;
    state_SegMan_Combined = false;

    //current index
    VP_current = ui->comboBox_Viewport->currentIndex();

    //Value ranges
    Extrema_Viewport();

    //VisVP
    Visualize_DataSet();

    //automatic segmentatuion
    Update_NucleiSegmentation_Auto();

    //manual segmentation
    SegmentationManual_Scan();
  //Segmentations_Combine();                    is done in: SegmentationManual_Scan();
    SegmentationManual_AdaptUi2BackupState();

    state_Viewport_New = false;
    state_Viewport_Loaded = true;

    //Viewer
    Update_Image_ProcView();
}

void D_MAKRO_Osteoclasts::Update_NucleiSegmentation_Auto()
{    
    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Update_NucleiSegmentation_Auto";

    state_SegAuto_Done = false;
    state_SegAuto_Updating = true;

    Update_NucleiSegmentation_Auto_Steps(0);
}

void D_MAKRO_Osteoclasts::Update_NucleiSegmentation_Auto_Steps(int start_step)
{
    if(!state_Platelet_Loaded || state_Startup || !state_SegAuto_Init)
        return;

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Update_NucleiSegmentation_Auto_Steps" << "start_at:" << QSL_ProcSteps[start_step];

    switch (start_step) {

    case c_STEP_PROJECT:
    {
        //form z stack
        vector<Mat> vMA_tmp_zStack;
        vMA_tmp_zStack.resize(DIM_Depths);
        for(int z = 0; z < DIM_Depths; z++)
            vMA_tmp_zStack[z] = vvvMA_VpZCh_Stacks[VP_current][z][c_CH_B_DAPI].clone();

        ERR(D_Img_Proc::Math_ImgStack_Project(
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_PROJECT]),
                &vMA_tmp_zStack,
                c_STAT_MEAN_ARITMETIC),
            "Update_NucleiSegmentation_Auto_Steps",
            "c_STEP_PROJECT - stack project nuclei images");

        vMA_tmp_zStack.clear();
    }

    case c_STEP_8BIT:
    {
        ERR(D_Img_Proc::Normalize(
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_8BIT]),
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_PROJECT]),
                CV_MINMAX,
                CV_8UC1,
                0,
                255),
            "Update_NucleiSegmentation_Auto_Steps",
            "c_STEP_8BIT - normalize projected image (->8bit)");
    }

    case c_STEP_BLUR:
    {
        ERR(D_Img_Proc::Filter_Gauss(
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_BLUR]),
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_8BIT]),
                ui->spinBox_SegAuto_Blur_Size->value(),
                ui->spinBox_SegAuto_Blur_Size->value(),
                BORDER_DEFAULT,
                ui->doubleSpinBox_SegAuto_Blur_Sigma->value(),
                ui->doubleSpinBox_SegAuto_Blur_Sigma->value()),
            "Update_NucleiSegmentation_Auto_Steps",
            "c_STEP_BLUR - despecle projected image");
    }

    case c_STEP_THRES:
    {
        ERR(D_Img_Proc::Threshold_Adaptive(
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_THRES]),
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_BLUR]),
                CV_THRESH_BINARY,
                255,
                CV_ADAPTIVE_THRESH_GAUSSIAN_C,
                ui->spinBox_SegAuto_Thres_Size->value(),
                ui->doubleSpinBox_SegAuto_Thres_Offset->value()),
            "Update_NucleiSegmentation_Auto_Steps",
            "c_STEP_THRES - find foreground, possible nuclei");
    }

    case c_STEP_DISTANCE:
    {
        ERR(D_Img_Proc::Transformation_Distance(
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_DISTANCE]),
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_THRES]),
                CV_DIST_L2,
                CV_DIST_MASK_PRECISE),
            "Update_NucleiSegmentation_Auto_Steps",
            "c_STEP_DISTANCE - euclidean distance transfrom");
    }

    case c_STEP_SEEDS:
    {
        ERR(D_Img_Proc::Threshold_Absolute_1C(
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_SEEDS]),
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_DISTANCE]),
                ui->doubleSpinBox_SegAuto_Distance_Thres->value()),
            "Update_NucleiSegmentation_Auto_Steps",
            "c_STEP_SEEDS - filter by distance to get centers");
    }

    case c_STEP_WATERSHED:
    {
        ERR(D_Img_Proc::Transformation_Watershed_Auto(
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_WATERSHED]),
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_THRES]),
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_SEEDS]),
                ui->checkBox_SegAuto_Watershed_nSeeded->isChecked(),
                false,
                !(ui->checkBox_SegAuto_Watershed_Bordered->isChecked())),
            "Update_NucleiSegmentation_Auto_Steps",
            "c_STEP_WATERSHED - segmentation");
    }

    case c_STEP_AREA:
    {
        ERR(D_Img_Proc::Feature_Select(
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_AREA]),
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_WATERSHED]),
                c_FEAT_AREA,
                ui->spinBox_SegAuto_Area_Min->value(),
                ui->spinBox_SegAuto_Area_Max->value(),
                4),
            "Update_NucleiSegmentation_Auto_Steps",
            "c_STEP_AREA - filter by area");
    }

    case c_STEP_ROUNDNESS:
    {
        ERR(D_Img_Proc::Feature_Select(
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_ROUNDNESS]),
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_AREA]),
                c_FEAT_ROUNDNESS,
                ui->doubleSpinBox_SegAuto_Roundness_Thres->value(),
                1),
            "Update_NucleiSegmentation_Auto_Steps",
            "c_STEP_ROUNDNESS - filter by roundness");
    }

    case c_STEP_OUTLINES:
    {
        ERR(D_Img_Proc::Reduce_Geometric(
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_OUTLINES]),
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_ROUNDNESS]),
                c_GEO_OUTLINE,
                4,
                1,
                255),
            "Update_NucleiSegmentation_Auto_Steps",
            "c_STEP_OUTLINES - reduce to outlines");
    }

    case c_STEP_CONTROL:
    {
        ERR(D_Img_Proc::Math_ImgImg_Add(
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_CONTROL]),
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_OUTLINES]),
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_8BIT])),
            "Update_NucleiSegmentation_Auto_Steps",
            "c_STEP_CONTROL - control viewer");
    }

    default:
        break;
    }

    state_SegAuto_Done = true;
    state_SegAuto_Updating = false;

    Update_Image_ProcView();
}


void D_MAKRO_Osteoclasts::Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init)
{
    //if(MessageOnFunctionStart)        qDebug() << "D_MAKRO_Osteoclasts Populate_CB_Single";

    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(index_init);
    CB->blockSignals(false);
}

void D_MAKRO_Osteoclasts::Populate_CB_All_onStartUp()
{
    if(!state_Startup)
    {
        ERR_StatesCheck("Populate_CB_All_onStartUp");
        return;
    }

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Populate_CB_All_onStartUp";

    Populate_CB_Stats();
    Populate_CB_ProcSteps();
    Populate_CB_Segmentations();
    Populate_CB_AxeTrans();
    Populate_CB_Draw();
}

void D_MAKRO_Osteoclasts::Populate_CB_All_onImgInit()
{
    if(state_Startup)
    {
        ERR_StatesCheck("Populate_CB_All_onImgInit");
        return;
    }

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Populate_CB_All_onImgInit";

    Populate_CB_Dimensions();
}

void D_MAKRO_Osteoclasts::Populate_CB_Stats()
{
    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Populate_CB_Stats";

    Populate_CB_Single(ui->comboBox_VisVP_ProjectionStat, QSL_StatList, c_STAT_MEAN_ARITMETIC);
}

void D_MAKRO_Osteoclasts::Populate_CB_AxeTrans()
{
    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Populate_CB_AxeTrans";

}

void D_MAKRO_Osteoclasts::Populate_CB_Dimensions()
{
    if(!state_Platelet_Loaded)
    {
        ERR_StatesCheck("Populate_CB_Dimensions");
        return;
    }

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Populate_CB_Dimensions";

    Populate_CB_Single(ui->comboBox_Viewport, QSL_Viewport_Names);
}

void D_MAKRO_Osteoclasts::Populate_CB_Draw()
{
    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Populate_CB_Draw";

    Populate_CB_Single(ui->comboBox_SegMan_Draw_Color, QSL_SegmentationColor, c_SEG_COLOR_FOREGROUND);
    Populate_CB_Single(ui->comboBox_SegMan_Draw_Type, QSL_SegmentationPen, c_SEG_PEN_LINE);
}

void D_MAKRO_Osteoclasts::Populate_CB_ProcSteps()
{
    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Populate_CB_ProcSteps";

    Populate_CB_Single(ui->comboBox_SegAuto_Step, QSL_ProcSteps, c_STEP_CONTROL);
}

void D_MAKRO_Osteoclasts::Populate_CB_Segmentations()
{
    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Populate_CB_Segmentations";

    Populate_CB_Single(ui->comboBox_SegMan_SegmentationType, QSL_Segmentations);
}

void D_MAKRO_Osteoclasts::Images_NucleiSegmentation_Init()
{
    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Images_NucleiSegmentation_Init";

    state_SegAuto_Init = false;

    Mat MA_init = Mat::zeros(vvvMA_VpZCh_Stacks[0][0][0].size(), CV_8UC1);
    ERR(D_Img_Proc::Draw_Boundaries(
            &MA_init,
            1,
            255),
        "Images_NucleiSegmentation_Init",
        "Draw_Boundaries");

    vvMA_VpStep_NucAutoSeg.clear();
    vvMA_VpStep_NucAutoSeg.resize(Dim_Viewports);
    for(int vp = 0; vp < Dim_Viewports; vp++)
    {
        vvMA_VpStep_NucAutoSeg[vp].resize(c_STEP_NUMBER_OF);
        for(int step = 0; step < c_STEP_NUMBER_OF; step++)
            vvMA_VpStep_NucAutoSeg[vp][step] = MA_init.clone();
    }

    MA_init.release();

    state_SegAuto_Init = true;
}

void D_MAKRO_Osteoclasts::Images_VisVPin_init()
{
    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Images_VisVPin_init";

    state_VisVP_Init = false;

    Mat MA_init = Mat::zeros(50, 50, CV_8UC1);

    vMA_Ch_VisVP_in.clear();
    vMA_Ch_VisVP_in.resize(c_CH_NUMBER_OF);
    for(int ch = 0; ch < c_CH_NUMBER_OF; ch++)
        vMA_Ch_VisVP_in[ch] = MA_init.clone();

    MA_init.release();

    state_VisVP_Init = true;
}

void D_MAKRO_Osteoclasts::Load_Platelet()
{
    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Load_Platelet";

    //define z-depths------------------------------------------------------------------------------------   z
    bool ok;
    DIM_Depths = QInputDialog::getInt(
                this,
                tr("Define Dataset"),
                tr("Number of z-layers expected:<br>"),
                6,
                1,
                99999999,
                1,
                &ok);
    ui->spinBox_VisVP_ZLayer->setMaximum(DIM_Depths - 1);
    if(!ok)
        return;
    qDebug() << "\n" << "DIM_Depths" << DIM_Depths;

    //Get Folder
    QString QS_Path_InputPlatelet = QFileDialog::getExistingDirectory(
                this,
                "Select platelet folder to be analyzed",
                pStore->dir_M_Osteoclasts()->path());
    if(QS_Path_InputPlatelet == 0)
        return;
    qDebug() << "\n" << "QS_Path_InputPlatelet" << QS_Path_InputPlatelet;

    state_Platelet_New = true;
    state_Platelet_Loaded = false;
    state_Viewport_Loaded = false;
    state_Viewport_New = true;
    state_VisVp_Done = false;
    state_SegMan_Init = false;
    state_SegMan_Scanned = false;
    state_SegMan_Combined = false;
    state_SegPath_Init = false;

    //save folder
    pStore->set_dir_M_Osteoclasts(QS_Path_InputPlatelet);
    DIR_InputPlatelet.setPath(QS_Path_InputPlatelet);
    QS_PlateletName = DIR_InputPlatelet.dirName();
    qDebug() << "\n" << "QS_PlateletName" << QS_PlateletName;

    //Elements in Folder
    QStringList QSL_InputElements = DIR_InputPlatelet.entryList();
    qDebug() << "\n" << "Elements Detected:" << QSL_InputElements.size();
    qDebug() << "QSL_InputElements" << QSL_InputElements;

    //find images that match in terms of file name and type
    QStringList QSL_InputImages;
    for(int elem = 0; elem < QSL_InputElements.size(); elem++)
        if(QSL_InputElements[elem].contains("_z") && QSL_InputElements[elem].contains("_Series") && QSL_InputElements[elem].endsWith(".tif"))
            QSL_InputImages.append(QSL_InputElements[elem]);
    qDebug() << "\n" << "Images Detected:" << QSL_InputImages.size();
    qDebug() << "QSL_InputImages" << QSL_InputImages;

    //find 1st images of stacks & base paths
    QSL_Viewport_Path.clear();
    for(int img = 0; img < QSL_InputImages.size(); img++)
        if(QSL_InputImages[img].endsWith("_z0.tif"))
        {
            int lastPosOf_z = QSL_InputImages[img].lastIndexOf("_z");
            QSL_Viewport_Path.append(DIR_InputPlatelet.path() + "/" + QSL_InputImages[img].left(lastPosOf_z + 2));
            QSL_Viewport_Names.append(QSL_InputImages[img].right(16).left(9));
        }
    qDebug() << "\n" << "Viewports Detected:" << QSL_Viewport_Path.size();
    qDebug() << "QSL_Viewport_Path" << QSL_Viewport_Path;

    //Series/viewport count
    Dim_Viewports = QSL_InputImages.size() / (DIM_Depths );  //divide by z

    //load expected images
    vvvMA_VpZCh_Stacks.clear();
    vvvMA_VpZCh_Stacks.resize(Dim_Viewports);

    if(Dim_Viewports != QSL_Viewport_Path.size())
    {
        QMessageBox::warning(
                    this,
                    "Load_Platelet",
                    "Dim_Viewports = " + QString::number(Dim_Viewports) + "<br>QSL_Viewport_Path.size = " + QString::number(QSL_Viewport_Path.size()) + "<br>These should match!");
        return;
    }

    for(int vp = 0; vp < Dim_Viewports; vp++)
    {
        vvvMA_VpZCh_Stacks[vp].resize(DIM_Depths);
        for(int z = 0; z < DIM_Depths; z++)
        {
            //path
            QString QS_LoadPath = QSL_Viewport_Path[vp];
            if(DIM_Depths >= 10 && z < 10)
                QS_LoadPath.append("0");
            QS_LoadPath.append(QString::number(z) + ".tif");

            //file
            QFileInfo FI_LoadImg(QS_LoadPath);
            if(!FI_LoadImg.exists())
            {
                QMessageBox::warning(
                            this,
                            "Dataset broken!",
                            "<I>" + FI_LoadImg.absoluteFilePath() + "</I>"
                            "<br>"
                            "<br>...is missing! Loading process is quit."
                            "<br>"
                            "<br>Viewport: " + QString::number(vp) + " (" + QSL_Viewport_Names[vp] +")" +
                            "<br>Z-Layer: " + QString::number(z) +
                            "<br>"
                            "<br>Don't be sad, shat hippens... But where is that file? O.o");
                return;
            }

            //load all channels
            Mat MA_tmp_in;
            int ER = D_Img_Proc::Load_From_Path(
                        &MA_tmp_in,
                        FI_LoadImg.absoluteFilePath());
            if(ER != ER_okay)
            {
                ERR(
                            ER,
                            "Load_Platelet",
                            "Something went wrong while loading the image<br><I>" + FI_LoadImg.absoluteFilePath() + "</I>"
                            "<br><br>Viewport: " + QString::number(vp) +
                            "<br>Z-Layer: " + QString::number(z) +
                            "<br><br>Maybe the file is empty or has the wrong format or size?"
                            );
                return;
            }

            //split channels
            vvvMA_VpZCh_Stacks[vp][z].resize(c_CH_NUMBER_OF);
            for(int ch = 0; ch < c_CH_NUMBER_OF; ch++)
            {
                qDebug() << "vp/z/ch" << vp << z << ch << FI_LoadImg.absoluteFilePath();
                int ER = D_Img_Proc::Split(
                            &(vvvMA_VpZCh_Stacks[vp][z][ch]),
                            &MA_tmp_in,
                            ch);
                if(ER != ER_okay)
                {
                    ERR(
                                ER,
                                "Load_Platelet",
                                "Something went wrong while channel-splitting the image<br><I>" + FI_LoadImg.absoluteFilePath() + "</I>"
                                "<br><br>Viewport:" + QString::number(vp) + QSL_Viewport_Names[vp] +
                                "<br>Z-Layer: " + QString::number(z) +
                                "<br>Channel: " + QString::number(ch) + " - " + QSL_Channels[ch] +
                                "<br><br>Maybe the file has only one channel?"
                                );
                    return;
                }
            }

            MA_tmp_in.release();
        }
    }

    if(ui->action_Prompt_Load_Platelet_Dimension->isChecked())
        if(QMessageBox::question(
                    this,
                    "Dimension Check",
                    "Images in following Dimension found:"
                    "<br><b>Z-Layers:  </b>" + QString::number(DIM_Depths) +
                    "<br><b>Viewports: </b>" + QString::number(Dim_Viewports) +
                    "<br><b>Images:    </b>" + QString::number(QSL_InputImages.size()) +
                    "<br>"
                    "<br>Is that as expected?",
                    QMessageBox::Yes | QMessageBox::No)
                != QMessageBox::Yes)
            return;

    state_Platelet_Loaded = true;

    ui->groupBox_Proc->setEnabled(true);
    //Projection_Init();
    SegmentationManual_DIR_Init();
    Images_NucleiSegmentation_Init();
    Extrema_Viewport();
    Populate_CB_All_onImgInit();

    state_Platelet_New = false;

    Update_newViewport();
}

void D_MAKRO_Osteoclasts::Visualize_DataSet()
{
    if(state_Startup || !state_Platelet_Loaded || !state_Viewport_Loaded || !state_VisVP_Init)
    {
        ERR_StatesCheck("Visualize_DataSet");
        return;
    }

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Visualize_DataSet";

    state_VisVP_Updating = true;
    state_VisVp_Done = false;

    //single channel proccessing
    //Mat MA_tmp_out_channel_merged;
    vector<Mat> vMA_tmp_out_all_channels;
    vMA_tmp_out_all_channels.resize(c_CH_NUMBER_OF);

    //read parameters
    vector<vector<double>> vvd_ChPar_Parameters;
    vvd_ChPar_Parameters.resize(c_CH_NUMBER_OF);
    for(int ch = 0; ch < c_CH_NUMBER_OF; ch++)
        vvd_ChPar_Parameters[ch].resize(c_VIS_PAR_NUMBER_OF);

    //get projection relevant parameters
    vvd_ChPar_Parameters    [c_CH_B_DAPI]   [c_VIS_PAR_DISPLAY]     = static_cast<double>(ui->checkBox_VisVP_Show_B->isChecked());
    vvd_ChPar_Parameters    [c_CH_G_FACTIN] [c_VIS_PAR_DISPLAY]     = static_cast<double>(ui->checkBox_VisVP_Show_G->isChecked());
    vvd_ChPar_Parameters    [c_CH_R_TRAP]   [c_VIS_PAR_DISPLAY]     = static_cast<double>(ui->checkBox_VisVP_Show_R->isChecked());
    vvd_ChPar_Parameters    [c_CH_B_DAPI]   [c_VIS_PAR_PROJECT]     = static_cast<double>(ui->checkBox_VisVP_ZProject_B->isChecked());
    vvd_ChPar_Parameters    [c_CH_G_FACTIN] [c_VIS_PAR_PROJECT]     = static_cast<double>(ui->checkBox_VisVP_ZProject_G->isChecked());
    vvd_ChPar_Parameters    [c_CH_R_TRAP]   [c_VIS_PAR_PROJECT]     = static_cast<double>(ui->checkBox_VisVP_ZProject_R->isChecked());
    vvd_ChPar_Parameters    [c_CH_B_DAPI]   [c_VIS_PAR_Z_LAYER]     = static_cast<double>(ui->spinBox_VisVP_ZLayer->value());
    vvd_ChPar_Parameters    [c_CH_G_FACTIN] [c_VIS_PAR_Z_LAYER]     = static_cast<double>(ui->spinBox_VisVP_ZLayer->value());
    vvd_ChPar_Parameters    [c_CH_R_TRAP]   [c_VIS_PAR_Z_LAYER]     = static_cast<double>(ui->spinBox_VisVP_ZLayer->value());

    int vp = ui->comboBox_Viewport->currentIndex();

    for(int ch = 0; ch < c_CH_NUMBER_OF; ch++)
    {

        if(vvd_ChPar_Parameters[ch][c_VIS_PAR_DISPLAY])
        {
            if(vvd_ChPar_Parameters[ch][c_VIS_PAR_PROJECT])
            {
                //form z stack
                vector<Mat> vMA_tmp_zStack;
                vMA_tmp_zStack.resize(DIM_Depths);
                for(int z = 0; z < DIM_Depths; z++)
                    vMA_tmp_zStack[z] = vvvMA_VpZCh_Stacks[vp][z][ch].clone();

                //projection
                ERR(D_Img_Proc::Math_ImgStack_Project(
                        &(vMA_Ch_VisVP_in[ch]),
                        &vMA_tmp_zStack,
                        ui->comboBox_VisVP_ProjectionStat->currentIndex()),
                    "Visualize_DataSet",
                    "Math_ImgStack_Project"
                    "<br>Viewport: " + QString::number(vp) + " - " + QSL_Viewport_Names[vp] +
                    "<br>Channel: " + QString::number(ch) + " - " + QSL_Channels[ch]);

                vMA_tmp_zStack.clear();

                //range (in case auto range is used)
                double min, max;
                ERR(D_Img_Proc::MinMax_of_Mat(
                            &(vMA_Ch_VisVP_in[ch]),
                            &min,
                            &max),
                        "Visualize_DataSet",
                        "MinMax_of_Mat - get extreme values of dataset for automatic range");
                vvvd_ProjExtCh_Extrema[c_PROJ_CURRENT_PROJECTION][c_EXTREMA_MIN][ch] = min;
                vvvd_ProjExtCh_Extrema[c_PROJ_CURRENT_PROJECTION][c_EXTREMA_MAX][ch] = max;
            }
            else
            {
                vMA_Ch_VisVP_in[ch] = vvvMA_VpZCh_Stacks[vp][vvd_ChPar_Parameters[ch][c_VIS_PAR_Z_LAYER]][ch].clone();
            }
        }
        else
        {
            vMA_Ch_VisVP_in[ch] = Mat::zeros(vvvMA_VpZCh_Stacks[vp][0][ch].size(), CV_64FC1);
        }

        //Save VisVP images in (real data) for display value under cursor correctly
        //vMA_Ch_VisVP_in[ch] =


        //Auto Range
        if(ui->checkBox_VisVP_Auto->isChecked())
            Extrema_2ui();

        //get range relevant parameters after auto range is set
        vvd_ChPar_Parameters    [c_CH_B_DAPI]   [c_VIS_PAR_RANGE_MIN]   = ui->doubleSpinBox_VisVP_Range_Min_B->value();
        vvd_ChPar_Parameters    [c_CH_G_FACTIN] [c_VIS_PAR_RANGE_MIN]   = ui->doubleSpinBox_VisVP_Range_Min_G->value();
        vvd_ChPar_Parameters    [c_CH_R_TRAP]   [c_VIS_PAR_RANGE_MIN]   = ui->doubleSpinBox_VisVP_Range_Min_R->value();
        vvd_ChPar_Parameters    [c_CH_B_DAPI]   [c_VIS_PAR_RANGE_MAX]   = ui->doubleSpinBox_VisVP_Range_Max_B->value();
        vvd_ChPar_Parameters    [c_CH_G_FACTIN] [c_VIS_PAR_RANGE_MAX]   = ui->doubleSpinBox_VisVP_Range_Max_G->value();
        vvd_ChPar_Parameters    [c_CH_R_TRAP]   [c_VIS_PAR_RANGE_MAX]   = ui->doubleSpinBox_VisVP_Range_Max_R->value();
        vvd_ChPar_Parameters    [c_CH_B_DAPI]   [c_VIS_PAR_GAMMA]       = ui->doubleSpinBox_VisVP_Gamma_B->value();
        vvd_ChPar_Parameters    [c_CH_G_FACTIN] [c_VIS_PAR_GAMMA]       = ui->doubleSpinBox_VisVP_Gamma_G->value();
        vvd_ChPar_Parameters    [c_CH_R_TRAP]   [c_VIS_PAR_GAMMA]       = ui->doubleSpinBox_VisVP_Gamma_R->value();

        ERR(D_Img_Proc::GammaSpread_1C(
                &(vMA_tmp_out_all_channels[ch]),
                &(vMA_Ch_VisVP_in[ch]),
                vvd_ChPar_Parameters[ch][c_VIS_PAR_GAMMA],
                vvd_ChPar_Parameters[ch][c_VIS_PAR_RANGE_MIN],
                vvd_ChPar_Parameters[ch][c_VIS_PAR_RANGE_MAX]),
            "Visualize_DataSet",
            "GammaSpread_1C"
            "<br>Viewport: " + QString::number(vp) + " - " + QSL_Viewport_Names[vp] +
            "<br>Channel: " + QString::number(ch) + " - " + QSL_Channels[ch]);
    }

    //Merge
    ERR(D_Img_Proc::Merge(
            &(MA_VisVP_3ch),
            &(vMA_tmp_out_all_channels[c_CH_B_DAPI]),
            &(vMA_tmp_out_all_channels[c_CH_G_FACTIN]),
            &(vMA_tmp_out_all_channels[c_CH_R_TRAP])),
        "Visualize_DataSet",
        "Merge channels");

    state_VisVp_Done = true;
    state_VisVP_Updating = false;

    //Free memory
    vMA_tmp_out_all_channels.clear();

    //Update_Image_ProcView();
}

void D_MAKRO_Osteoclasts::Segmentation_Next()
{
    if(!state_Viewport_Loaded)
        Update_newViewport();
    if(!state_Viewport_Loaded || !state_Platelet_Loaded)
    {
        ERR_StatesCheck("Segmentation_Next");
        return;
    }

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Segmentation_Next";

    int index_vp = ui->comboBox_Viewport->currentIndex();
    int index_seg = ui->comboBox_SegMan_SegmentationType->currentIndex();

    if(index_vp >= QSL_Viewport_Names.size() - 1 && index_seg >= c_SEG_NUMBER_OF - 1)
    {
        QMessageBox::information(
                    this,
                    "End of Stack",
                    "All segmentations done, congratulations :-)<br>"
                    "(At least you have reached the end of the viewport-stack)");
    }
    else
    {
        if(index_seg < c_SEG_NUMBER_OF - 1)
        {
            ui->comboBox_SegMan_SegmentationType->setCurrentIndex(index_seg + 1);
        }
        else
        {
            ui->comboBox_Viewport->setCurrentIndex(index_vp + 1);
            ui->comboBox_SegMan_SegmentationType->setCurrentIndex(0);
        }
    }
}

void D_MAKRO_Osteoclasts::SegmentationManual_DIR_Init()
{
    if(state_Startup || !state_Platelet_Loaded)
    {
        ERR_StatesCheck("SegmentationManual_DIR_Init");
        return;
    }

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts SegmentationManual_DIR_Init";

    state_SegPath_Init = false;
    state_SegMan_Init = false;

    //dir where to expect segmentations - make sure dir exists
    DIR_Segmentations.setPath(DIR_InputPlatelet.path() + "/ImageD_Segmentations");
    if(!DIR_Segmentations.exists())
        QDir().mkdir(DIR_Segmentations.path());

    //segmentations to export
    FIL_Segmentations_current.clear();
    for(int seg = 0; seg < c_SEG_SAVE_NUMBER_OF; seg++)
        FIL_Segmentations_current.append(DIR_Segmentations.path() + "/" + QSL_Viewport_Names[VP_current] + "_" + QSL_SegmentationsSave[seg] + ".png");

    //init segmentations (save)
    vvMA_VpSeg_Manual_Saved.clear();
    vvMA_VpSeg_Manual_Saved.resize(Dim_Viewports);
    for(int vp = 0; vp < Dim_Viewports; vp++)
        vvMA_VpSeg_Manual_Saved[vp].resize(c_SEG_SAVE_NUMBER_OF);

    //init segmentations (combi)
    vvMA_VpSeg_Manual_Combined.clear();
    vvMA_VpSeg_Manual_Combined.resize(Dim_Viewports);
    for(int vp = 0; vp < Dim_Viewports; vp++)
        vvMA_VpSeg_Manual_Combined[vp].resize(c_SEG_NUMBER_OF);

    //init segmentations (backup)
    vvvMA_VpSegStep_Manual_Backup.clear();
    vvvMA_VpSegStep_Manual_Backup.resize(Dim_Viewports);
    vvI_VpSeg_ActionsCount.clear();
    vvI_VpSeg_ActionsCount.resize(Dim_Viewports);
    vvI_VpSeg_UndoCount.clear();
    vvI_VpSeg_UndoCount.resize(Dim_Viewports);
    for(int vp = 0; vp < Dim_Viewports; vp++)
    {
        vvvMA_VpSegStep_Manual_Backup[vp].resize(c_SEG_SAVE_NUMBER_OF);
        for(int seg = 0; seg < c_SEG_SAVE_NUMBER_OF; seg++)
            vvvMA_VpSegStep_Manual_Backup[vp][seg].resize(c_SEG_MAN_BACKUPS);

        vvI_VpSeg_ActionsCount[vp].resize(c_SEG_SAVE_NUMBER_OF, 0);
        vvI_VpSeg_UndoCount[vp].resize(c_SEG_SAVE_NUMBER_OF, 0);
    }

    state_SegMan_Init = true;
    state_SegPath_Init = true;
}

void D_MAKRO_Osteoclasts::SegmentationManual_Scan()
{
    if(!state_SegPath_Init)
        SegmentationManual_DIR_Init();
    if(!state_SegPath_Init || !state_Platelet_Loaded)
    {
        ERR_StatesCheck("SegmentationManual_Scan");
        return;
    }

    state_SegMan_Scanned = false;

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts SegmentationManual_Scan";

    int segs = 0;
    int seg_loads = 0;
    int seg_inits = 0;
    for(int seg = 0; seg < c_SEG_SAVE_NUMBER_OF; seg++)
    {
        segs++;
       //qDebug() << "SegmentationManual_Scan" << seg << "/" << FIL_Segmentations_current.size() << DIR_Segmentations.path() + "/" + QSL_Viewport_Names[VP_current] + "_" + QSL_SegmentationsSave[seg] + ".png";

       FIL_Segmentations_current[seg] = QFileInfo(DIR_Segmentations.path() + "/" + QSL_Viewport_Names[VP_current] + "_" + QSL_SegmentationsSave[seg] + ".png");

       if(FIL_Segmentations_current[seg].exists())
       {
           SegmentationManual_Load(seg);
           seg_loads++;
       }
       else
       {
           SegmentationManual_Init(seg);
           seg_inits++;
       }
    }

    if(ui->action_Prompt_Scan_Segmentations->isChecked())
        QMessageBox::information(
                    this,
                    "Segmentations Scan",
                    "Scanned for Segmentations in Directory:"
                    "<br>"
                    "<br><I>" + DIR_Segmentations.path() + "</I>"
                    "<br>"
                    "<br><b>Loaded: </b>" + QString::number(seg_loads) +
                    "<br><b>Created: </b>" + QString::number(seg_inits) +
                    "<br>-->"
                    "<br><b>Total: </b>" + QString::number(segs));

    state_SegMan_Scanned = true;
    Segmentations_Combine();
}

void D_MAKRO_Osteoclasts::SegmentationManual_Load(int seg_type)
{
    if(!state_SegPath_Init)
        SegmentationManual_DIR_Init();
    if(!state_SegPath_Init)
    {
        ERR_StatesCheck("SegmentationManual_Load - " + QSL_SegmentationsSave[seg_type]);
        return;
    }

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts SegmentationManual_Load" << "type:" << QSL_SegmentationsSave[seg_type] << "index:" << seg_type << "Filename_size:" << FIL_Segmentations_current.size() << "Imgvector_size:" << vvMA_VpSeg_Manual_Saved[VP_current].size();

    ERR(D_Img_Proc::Load_From_Path(
            &(vvMA_VpSeg_Manual_Saved[VP_current][seg_type]),
            FIL_Segmentations_current[seg_type].absoluteFilePath()),
        "SegmentationManual_Load",
        "Load_From_Path"
        "<br>Segmentation:" + QSL_SegmentationsSave[seg_type] +
        "<br>Filename:" + FIL_Segmentations_current[seg_type].absoluteFilePath());
}

void D_MAKRO_Osteoclasts::SegmentationManual_Init(int seg_type)
{
    if(!state_SegPath_Init)
        SegmentationManual_DIR_Init();
    if(!state_SegPath_Init)
    {
        ERR_StatesCheck("SegmentationManual_Init - " + QSL_SegmentationsSave[seg_type]);
        return;
    }

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts SegmentationManual_Init" << "type:" << QSL_SegmentationsSave[seg_type];

    vvMA_VpSeg_Manual_Saved[VP_current][seg_type] = Mat(vvvMA_VpZCh_Stacks[0][0][0].size(), CV_8UC1, Scalar(0)).clone();
    SegmentationManual_Save(seg_type);
}

void D_MAKRO_Osteoclasts::SegmentationManual_Save(int seg_type)
{
    if(!state_SegPath_Init)
        SegmentationManual_DIR_Init();
    if(!state_SegPath_Init)
    {
        ERR_StatesCheck("SegmentationManual_Save - " + QSL_SegmentationsSave[seg_type]);
        return;
    }

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts SegmentationManual_Save" << "type:" << QSL_SegmentationsSave[seg_type];

    QImage QI_tmp_save;

    ERR(D_Img_Proc::Convert_Mat_to_QImage(
            &(QI_tmp_save),
            &(vvMA_VpSeg_Manual_Saved[VP_current][seg_type])),
        "SegmentationManual_Save",
        "Convert_Mat_to_QImage"
        "<br>Segmentation:" + QSL_SegmentationsSave[seg_type]);

    QI_tmp_save.save(FIL_Segmentations_current[seg_type].absoluteFilePath());
}

void D_MAKRO_Osteoclasts::SegmentationManual_Reset()
{
    int answer = QMessageBox::question(
                this,
                "Reset Segmentations?",
                "Please chose how many segmentations of current viewport you want to reset:",
                "None",
                "One",
                "All");

    switch (answer) {

    case 0://None
        return;
        break;

    case 1://One
        SegmentationManual_Init(ui->comboBox_SegMan_SegmentationType->currentIndex());
        break;

    case 2://All
        for(int seg = 0; seg < c_SEG_SAVE_NUMBER_OF; seg++)
            SegmentationManual_Init(seg);
        break;

    default:
        break;
    }

    state_SegMan_Draw_NewLine = true;
    Segmentations_Combine();
    Update_Image_ProcView();
}

void D_MAKRO_Osteoclasts::SegmentationManual_Backup()
{
    //segmentation type
    int seg = ui->comboBox_SegMan_SegmentationType->currentIndex();

    //position of latest backup in vector
    unsigned int index_backup = vvI_VpSeg_ActionsCount[VP_current][seg] % (c_SEG_MAN_BACKUPS);

    //save current image as backup
    vvvMA_VpSegStep_Manual_Backup[VP_current][seg][index_backup] = vvMA_VpSeg_Manual_Saved[VP_current][seg].clone();

    //increase actions counter
    vvI_VpSeg_ActionsCount[VP_current][seg]++;

    //break undo chain on new backup to avoid tree structure of backups
    vvI_VpSeg_UndoCount[VP_current][seg] = 0;

    SegmentationManual_AdaptUi2BackupState();
}

void D_MAKRO_Osteoclasts::SegmentationManual_Undo()
{
    //segmentation type
    int seg = ui->comboBox_SegMan_SegmentationType->currentIndex();

    //position of latest backup in vector
    unsigned int index_backup = vvI_VpSeg_ActionsCount[VP_current][seg] % (c_SEG_MAN_BACKUPS);

    //position of requested backup
    unsigned int index_backup2load = (index_backup + c_SEG_MAN_BACKUPS - vvI_VpSeg_UndoCount[VP_current][seg] - 1) % c_SEG_MAN_BACKUPS;

    //load backup
    qDebug() << "latest_backup: " << vvI_VpSeg_ActionsCount[VP_current][seg] << "%" << c_SEG_MAN_BACKUPS << "=" << index_backup;
    qDebug() << "request_backup:(" << index_backup << "+" << c_SEG_MAN_BACKUPS << "-" << vvI_VpSeg_UndoCount[VP_current][seg] << " - 1 ) %" << c_SEG_MAN_BACKUPS << "=" << index_backup2load;
    vvMA_VpSeg_Manual_Saved[VP_current][seg] = vvvMA_VpSegStep_Manual_Backup[VP_current][seg][index_backup2load];

    //increase undo counter
    vvI_VpSeg_UndoCount[VP_current][seg]++;

    state_SegMan_Draw_NewLine = true;
    SegmentationManual_AdaptUi2BackupState();
    Segmentations_Combine();
    Update_Image_ProcView();
}

void D_MAKRO_Osteoclasts::SegmentationManual_AdaptUi2BackupState()
{
    //segmentation type
    int seg = ui->comboBox_SegMan_SegmentationType->currentIndex();

    //Undo possible?
    ui->pushButton_SegMan_Undo->setEnabled(
                vvI_VpSeg_ActionsCount[VP_current][seg] &&
                vvI_VpSeg_UndoCount[VP_current][seg] < c_SEG_MAN_BACKUPS &&
                vvI_VpSeg_UndoCount[VP_current][seg] < vvI_VpSeg_ActionsCount[VP_current][seg]);
}

void D_MAKRO_Osteoclasts::SegmentationManual_TriggerDraw(int x, int y)
{
    //Segmentation initilazied?
    if(!state_SegPath_Init || !state_SegMan_Scanned)
    {
        ERR_StatesCheck("SegmentationManual_TriggerDraw");
        return;
    }

    //manuell segmentation active?
    if(ui->tabWidget_Proc_Settings->currentIndex() != c_PROC_VIEW_SEG_MANUAL)
        return;

    if(MessageOnFunctionStart)        qDebug() << "D_MAKRO_Osteoclasts" << "x/y" << x << y;

    SegmentationManual_Backup();

    //Save click pos in point
    PT_Draw_Current = Point(x, y);

    //indices from ui
    int index_seg_type = ui->comboBox_SegMan_SegmentationType->currentIndex();
    int index_color = ui->comboBox_SegMan_Draw_Color->currentIndex();
    int index_pen = ui->comboBox_SegMan_Draw_Type->currentIndex();

    //what/where to draw
    if(index_seg_type == c_SEG_NUCLEI)
    {
        //Color
        uchar color_fg = 255;
        uchar color_bg = 0;
        if(index_color == c_SEG_COLOR_BACKGROUND)
        {
            color_fg = 0;
            color_bg = 255;
        }

        //execute draw line/fill
        if(index_pen == c_SEG_PEN_LINE)
        {
            if(state_SegMan_Draw_NewLine)
            {
                state_SegMan_Draw_NewLine = false;
            }
            else
            {
                ERR(D_Img_Proc::Draw_Line(
                        &(vvMA_VpSeg_Manual_Saved[VP_current][c_SEG_SAVE_NUCLEI_FG]),
                        PT_Draw_Last.x,
                        PT_Draw_Last.y,
                        PT_Draw_Current.x,
                        PT_Draw_Current.y,
                        ui->spinBox_SegMan_Line_Width->value(),
                        color_fg),
                    "SegmentationManual_TriggerDraw",
                    "c_SEG_NUCLEI - Draw_Line - Foreground");

                ERR(D_Img_Proc::Draw_Line(
                        &(vvMA_VpSeg_Manual_Saved[VP_current][c_SEG_SAVE_NUCLEI_BG]),
                        PT_Draw_Last.x,
                        PT_Draw_Last.y,
                        PT_Draw_Current.x,
                        PT_Draw_Current.y,
                        ui->spinBox_SegMan_Line_Width->value(),
                        color_bg),
                    "SegmentationManual_TriggerDraw",
                    "c_SEG_NUCLEI - Draw_Line - Background");
            }
        }
        else
        {
            ERR(D_Img_Proc::Floodfill(
                    &(vvMA_VpSeg_Manual_Saved[VP_current][c_SEG_SAVE_NUCLEI_FG]),
                    PT_Draw_Current.x,
                    PT_Draw_Current.y,
                    color_fg),
                "SegmentationManual_TriggerDraw",
                "c_SEG_NUCLEI - Floodfill - Foreground");

            ERR(D_Img_Proc::Floodfill(
                    &(vvMA_VpSeg_Manual_Saved[VP_current][c_SEG_SAVE_NUCLEI_BG]),
                    PT_Draw_Current.x,
                    PT_Draw_Current.y,
                    color_bg),
                "SegmentationManual_TriggerDraw",
                "c_SEG_NUCLEI - Floodfill - Background");

            state_SegMan_Draw_NewLine = true;
        }
    }
    else
    {
        //color for cells/zones
        uchar color_draw = 255;
        if(index_color == c_SEG_COLOR_BACKGROUND)
            color_draw = 0;

        //index cells/zones
        int index_seg_save_type = c_SEG_SAVE_CELLS;
        if(index_seg_type == c_SEG_ZONES)
            index_seg_save_type = c_SEG_SAVE_ZONES;

        //execute draw line/fill
        if(index_pen == c_SEG_PEN_LINE)
        {
            if(state_SegMan_Draw_NewLine)
            {
                state_SegMan_Draw_NewLine = false;
            }
            else
            {
                ERR(D_Img_Proc::Draw_Line(
                        &(vvMA_VpSeg_Manual_Saved[VP_current][index_seg_save_type]),
                        PT_Draw_Last.x,
                        PT_Draw_Last.y,
                        PT_Draw_Current.x,
                        PT_Draw_Current.y,
                        ui->spinBox_SegMan_Line_Width->value(),
                        color_draw),
                    "SegmentationManual_TriggerDraw",
                    QSL_Segmentations[index_seg_type] + " - Draw_Line");
            }
        }
        else
        {
            ERR(D_Img_Proc::Floodfill(
                    &(vvMA_VpSeg_Manual_Saved[VP_current][index_seg_save_type]),
                    PT_Draw_Current.x,
                    PT_Draw_Current.y,
                    color_draw),
                "SegmentationManual_TriggerDraw",
                QSL_Segmentations[index_seg_type] + " - Floodfill");

            state_SegMan_Draw_NewLine = true;
        }
    }

    //Save Point as old point and save file
    PT_Draw_Last = PT_Draw_Current;

    switch (index_seg_type) {

    case c_SEG_CELLS:
        SegmentationManual_Save(c_SEG_SAVE_CELLS);
        break;

    case c_SEG_ZONES:
        SegmentationManual_Save(c_SEG_SAVE_ZONES);
        break;

    case c_SEG_NUCLEI:
        SegmentationManual_Save(c_SEG_SAVE_NUCLEI_FG);
        SegmentationManual_Save(c_SEG_SAVE_NUCLEI_BG);
        break;

    default:
        break;
    }

    //combine segmentations
    Segmentations_Combine(index_seg_type);
    Update_Image_ProcView_SegmentationManual();

}

void D_MAKRO_Osteoclasts::Segmentations_Combine()
{
    //Segmentation initilazied?
    if(!state_SegMan_Scanned)
    {
        ERR_StatesCheck("Segmentations_Combine");
        return;
    }

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Segmentations_Combine";

    for(int seg = 0; seg < c_SEG_NUMBER_OF; seg++)
        Segmentations_Combine(seg);

    state_SegMan_Combined = true;
}

void D_MAKRO_Osteoclasts::Segmentations_Combine(int seg_type)
{
    //Segmentation initilazied?
    if(!state_SegMan_Scanned)
    {
        ERR_StatesCheck("Segmentations_Combine" + QSL_Segmentations[seg_type]);
        return;
    }

    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Segmentations_Combine" << "type:" << QSL_Segmentations[seg_type];

    switch (seg_type) {

    case c_SEG_CELLS:
        ERR(D_Img_Proc::Fill_Holes(
                &(vvMA_VpSeg_Manual_Combined[VP_current][c_SEG_CELLS]),
                &(vvMA_VpSeg_Manual_Saved[VP_current][c_SEG_SAVE_CELLS])),
            "Segmentations_Combine - " + QSL_Segmentations[seg_type],
            "c_SEG_CELLS - Fill_Holes in cells");
        break;

    case c_SEG_ZONES:
        ERR(D_Img_Proc::Fill_Holes(
                &(vvMA_VpSeg_Manual_Combined[VP_current][c_SEG_ZONES]),
                &(vvMA_VpSeg_Manual_Saved[VP_current][c_SEG_SAVE_ZONES])),
            "Segmentations_Combine - " + QSL_Segmentations[seg_type],
            "c_SEG_ZONES - Fill_Holes in zones");
        break;

    case c_SEG_NUCLEI:
    {
        Mat MA_tmp_holes_filled;
        ERR(D_Img_Proc::Fill_Holes(
                &MA_tmp_holes_filled,
                &(vvMA_VpSeg_Manual_Saved[VP_current][c_SEG_SAVE_NUCLEI_FG])),
            "Segmentations_Combine - " + QSL_Segmentations[seg_type],
            "c_SEG_NUCLEI - Fill_Holes in manuel nuclei segmentation foreground");

        Mat MA_tmp_withFG;
        ERR(D_Img_Proc::Math_ImgImg_Add(
                &MA_tmp_withFG,
                &(vvMA_VpStep_NucAutoSeg[VP_current][c_STEP_ROUNDNESS]),
                &MA_tmp_holes_filled),
            "Segmentations_Combine - " + QSL_Segmentations[seg_type],
            "c_SEG_NUCLEI - Math_ImgImg_Add manual foreground segmentation and automatic segmantation");

        ERR(D_Img_Proc::Math_ImgImg_Diff(
                &(vvMA_VpSeg_Manual_Combined[VP_current][c_SEG_NUCLEI]),
                &MA_tmp_withFG,
                &(vvMA_VpSeg_Manual_Saved[VP_current][c_SEG_SAVE_NUCLEI_BG])),
            "Segmentations_Combine - " + QSL_Segmentations[seg_type],
            "c_SEG_NUCLEI - Math_ImgImg_Diff foreground combined segmentation and background");

        MA_tmp_withFG.release();
        MA_tmp_holes_filled.release();
    }
        break;

    default:
        break;
    }
}

void D_MAKRO_Osteoclasts::Extrema_Init()
{
    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Extrema_Init";

    vvvd_ProjExtCh_Extrema.clear();
    vvvd_ProjExtCh_Extrema.resize(c_PROJ_NUMBER_OF);
    for(int p = 0; p < c_PROJ_NUMBER_OF; p++)
    {
        vvvd_ProjExtCh_Extrema[p].resize(c_EXTREMA_NUMBER_OF);
        for(int e = 0; e < c_EXTREMA_NUMBER_OF; e++)
            vvvd_ProjExtCh_Extrema[p][e].resize(c_CH_NUMBER_OF, 0.0);
    }
}

void D_MAKRO_Osteoclasts::Extrema_Viewport()
{
    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Extrema_Viewport";

    //current vp
    int vp = ui->comboBox_Viewport->currentIndex();

    for(int ch = 0; ch < c_CH_NUMBER_OF; ch++)
    {
        //extrema for channels
        double min, max;

        //find example min/max
        ERR(D_Img_Proc::MinMax_of_Mat(
                    &(vvvMA_VpZCh_Stacks[vp][0][ch]),
                    &min,
                    &max),
                "Extrema_Viewport",
                "MinMax_of_Mat - init");
        vvvd_ProjExtCh_Extrema[c_PROJ_SINGLE_IMAGES][c_EXTREMA_MIN][ch] = min;
        vvvd_ProjExtCh_Extrema[c_PROJ_SINGLE_IMAGES][c_EXTREMA_MAX][ch] = max;


        // compare min/max in z stack
        for(int z = 1; z < DIM_Depths; z++)
        {
            ERR(D_Img_Proc::MinMax_of_Mat(
                        &(vvvMA_VpZCh_Stacks[vp][z][ch]),
                        &min,
                        &max),
                    "Extrema_Viewport",
                    "MinMax_of_Mat - compare");
            if(min < vvvd_ProjExtCh_Extrema[c_PROJ_SINGLE_IMAGES][c_EXTREMA_MIN][ch])   vvvd_ProjExtCh_Extrema[c_PROJ_SINGLE_IMAGES][c_EXTREMA_MIN][ch] = min;
            if(max > vvvd_ProjExtCh_Extrema[c_PROJ_SINGLE_IMAGES][c_EXTREMA_MAX][ch])   vvvd_ProjExtCh_Extrema[c_PROJ_SINGLE_IMAGES][c_EXTREMA_MAX][ch] = max;
        }
    }
}

void D_MAKRO_Osteoclasts::Extrema_2ui()
{
    if(MessageOnFunctionStart)
        qDebug() << "D_MAKRO_Osteoclasts Extrema_2ui";

    //set min/max to ui
    ui->doubleSpinBox_VisVP_Range_Min_B->blockSignals(true);
    ui->doubleSpinBox_VisVP_Range_Min_G->blockSignals(true);
    ui->doubleSpinBox_VisVP_Range_Min_R->blockSignals(true);
    ui->doubleSpinBox_VisVP_Range_Max_B->blockSignals(true);
    ui->doubleSpinBox_VisVP_Range_Max_G->blockSignals(true);
    ui->doubleSpinBox_VisVP_Range_Max_R->blockSignals(true);


    if(ui->checkBox_VisVP_ZProject_B->isChecked())
        ui->doubleSpinBox_VisVP_Range_Min_B->setValue(vvvd_ProjExtCh_Extrema[c_PROJ_CURRENT_PROJECTION][c_EXTREMA_MIN][c_CH_B_DAPI]);
    else
        ui->doubleSpinBox_VisVP_Range_Min_B->setValue(vvvd_ProjExtCh_Extrema[c_PROJ_SINGLE_IMAGES][c_EXTREMA_MIN][c_CH_B_DAPI]);

    if(ui->checkBox_VisVP_ZProject_G->isChecked())
        ui->doubleSpinBox_VisVP_Range_Min_G->setValue(vvvd_ProjExtCh_Extrema[c_PROJ_CURRENT_PROJECTION][c_EXTREMA_MIN][c_CH_G_FACTIN]);
    else
        ui->doubleSpinBox_VisVP_Range_Min_G->setValue(vvvd_ProjExtCh_Extrema[c_PROJ_SINGLE_IMAGES][c_EXTREMA_MIN][c_CH_G_FACTIN]);

    if(ui->checkBox_VisVP_ZProject_R->isChecked())
        ui->doubleSpinBox_VisVP_Range_Min_R->setValue(vvvd_ProjExtCh_Extrema[c_PROJ_CURRENT_PROJECTION][c_EXTREMA_MIN][c_CH_R_TRAP]);
    else
        ui->doubleSpinBox_VisVP_Range_Min_R->setValue(vvvd_ProjExtCh_Extrema[c_PROJ_SINGLE_IMAGES][c_EXTREMA_MIN][c_CH_R_TRAP]);


    if(ui->checkBox_VisVP_ZProject_B->isChecked())
        ui->doubleSpinBox_VisVP_Range_Max_B->setValue(vvvd_ProjExtCh_Extrema[c_PROJ_CURRENT_PROJECTION][c_EXTREMA_MAX][c_CH_B_DAPI]);
    else
        ui->doubleSpinBox_VisVP_Range_Max_B->setValue(vvvd_ProjExtCh_Extrema[c_PROJ_SINGLE_IMAGES][c_EXTREMA_MAX][c_CH_B_DAPI]);

    if(ui->checkBox_VisVP_ZProject_G->isChecked())
        ui->doubleSpinBox_VisVP_Range_Max_G->setValue(vvvd_ProjExtCh_Extrema[c_PROJ_CURRENT_PROJECTION][c_EXTREMA_MAX][c_CH_G_FACTIN]);
    else
        ui->doubleSpinBox_VisVP_Range_Max_G->setValue(vvvd_ProjExtCh_Extrema[c_PROJ_SINGLE_IMAGES][c_EXTREMA_MAX][c_CH_G_FACTIN]);

    if(ui->checkBox_VisVP_ZProject_R->isChecked())
        ui->doubleSpinBox_VisVP_Range_Max_R->setValue(vvvd_ProjExtCh_Extrema[c_PROJ_CURRENT_PROJECTION][c_EXTREMA_MAX][c_CH_R_TRAP]);
    else
        ui->doubleSpinBox_VisVP_Range_Max_R->setValue(vvvd_ProjExtCh_Extrema[c_PROJ_SINGLE_IMAGES][c_EXTREMA_MAX][c_CH_R_TRAP]);


    ui->doubleSpinBox_VisVP_Range_Min_B->blockSignals(false);
    ui->doubleSpinBox_VisVP_Range_Min_G->blockSignals(false);
    ui->doubleSpinBox_VisVP_Range_Min_R->blockSignals(false);
    ui->doubleSpinBox_VisVP_Range_Max_B->blockSignals(false);
    ui->doubleSpinBox_VisVP_Range_Max_G->blockSignals(false);
    ui->doubleSpinBox_VisVP_Range_Max_R->blockSignals(false);
}

void D_MAKRO_Osteoclasts::VisVP_MouseMovedOnScene(int x, int y)
{
    //if(MessageOnFunctionStart)        qDebug() << "D_MAKRO_Osteoclasts VisVP_MouseMovedOnScene" << "x/y" << x << y;

    for(int ch = 0; ch < c_CH_NUMBER_OF; ch++)
    {
        QString QS_ValAtPix;
        D_Img_Proc::ValAtPix(
                    &QS_ValAtPix,
                    &(vMA_Ch_VisVP_in[ch]),
                    x,
                    y);

        if(ch == c_CH_R_TRAP)   ui->label_VisVP_ValAtCur_R->setText(QS_ValAtPix);
        if(ch == c_CH_G_FACTIN) ui->label_VisVP_ValAtCur_G->setText(QS_ValAtPix);
        if(ch == c_CH_B_DAPI)   ui->label_VisVP_ValAtCur_B->setText(QS_ValAtPix);
    }
}

void D_MAKRO_Osteoclasts::ERR(int err, QString func, QString detail)
{
    ER.ERR(
                err,
                "D_MAKRO_Osteoclasts",
                func,
                detail);
}

void D_MAKRO_Osteoclasts::ERR_StatesCheck(QString func)
{
    if(!MessageOnBreakFromState)
        return;

    QString QS_States;

    QS_States.append("<br>");
    QS_States.append("Constructor\t Startup:\t"             + QString::number(state_Startup) + "<br>");
    QS_States.append("<br>");
    QS_States.append("Platelet\t        New:\t"             + QString::number(state_Platelet_New) + "<br>");
    QS_States.append("Platelet\t        Loaded:\t"          + QString::number(state_Platelet_Loaded) + "<br>");
    QS_States.append("<br>");
    QS_States.append("SegmentPath\t     Init:\t"            + QString::number(state_SegPath_Init) + "<br>");
    QS_States.append("<br>");
    QS_States.append("Viewport\t        New:\t"             + QString::number(state_Viewport_New) + "<br>");
    QS_States.append("Viewport\t        Loaded:\t"          + QString::number(state_Viewport_Loaded) + "<br>");
    QS_States.append("<br>");
    QS_States.append("VisualizeVP\t     Init:\t"            + QString::number(state_VisVP_Init) + "<br>");
    QS_States.append("VisualizeVP\t     Updating:\t"        + QString::number(state_VisVP_Updating) + "<br>");
    QS_States.append("VisualizeVP\t     Done:\t"            + QString::number(state_VisVp_Done) + "<br>");
    QS_States.append("<br>");
    QS_States.append("SegmentAuto\t     Init:\t"            + QString::number(state_SegAuto_Init) + "<br>");
    QS_States.append("SegmentAuto\t     Updating:\t"        + QString::number(state_SegAuto_Updating) + "<br>");
    QS_States.append("SegmentAuto\t     Done:\t"            + QString::number(state_SegAuto_Done) + "<br>");
    QS_States.append("<br>");
    QS_States.append("SegmentMauel\t    Init:\t"           + QString::number(state_SegMan_Init) + "<br>");
    QS_States.append("SegmentMauel\t    Scanned:\t"        + QString::number(state_SegMan_Scanned) + "<br>");
    QS_States.append("SegmentMauel\t    Combined:\t"       + QString::number(state_SegMan_Combined) + "<br>");
    QS_States.append("SegmentMauel\t    Draw Active:\t"    + QString::number(state_SegMan_Draw_Active) + "<br>");
    QS_States.append("SegmentMauel\t    Draw New Line:\t"  + QString::number(state_SegMan_Draw_NewLine) + "<br>");

    ER.ERR(
                ER_other,
                "D_MAKRO_Osteoclasts",
                func,
                QS_States);
}


void D_MAKRO_Osteoclasts::on_comboBox_Viewport_currentIndexChanged(int index)
{
    VP_current = index;

    Update_newViewport();
}


void D_MAKRO_Osteoclasts::on_spinBox_SegAuto_Blur_Size_valueChanged(int arg1)
{
    arg1;
    Update_NucleiSegmentation_Auto_Steps(c_STEP_BLUR);
    Update_Image_ProcView();
}

void D_MAKRO_Osteoclasts::on_doubleSpinBox_SegAuto_Blur_Sigma_valueChanged(double arg1)
{
    arg1;
    Update_NucleiSegmentation_Auto_Steps(c_STEP_BLUR);
    Update_Image_ProcView();
}

void D_MAKRO_Osteoclasts::on_spinBox_SegAuto_Thres_Size_valueChanged(int arg1)
{
    arg1;
    Update_NucleiSegmentation_Auto_Steps(c_STEP_THRES);
    Update_Image_ProcView();
}

void D_MAKRO_Osteoclasts::on_doubleSpinBox_SegAuto_Thres_Offset_valueChanged(double arg1)
{
    arg1;
    Update_NucleiSegmentation_Auto_Steps(c_STEP_THRES);
    Update_Image_ProcView();
}

void D_MAKRO_Osteoclasts::on_doubleSpinBox_SegAuto_Distance_Thres_valueChanged(double arg1)
{
    arg1;
    Update_NucleiSegmentation_Auto_Steps(c_STEP_SEEDS);
    Update_Image_ProcView();
}

void D_MAKRO_Osteoclasts::on_checkBox_SegAuto_Watershed_Bordered_stateChanged(int arg1)
{
    arg1;
    Update_NucleiSegmentation_Auto_Steps(c_STEP_WATERSHED);
    Update_Image_ProcView();
}

void D_MAKRO_Osteoclasts::on_checkBox_SegAuto_Watershed_nSeeded_stateChanged(int arg1)
{
    arg1;
    Update_NucleiSegmentation_Auto_Steps(c_STEP_WATERSHED);
    Update_Image_ProcView();
}

void D_MAKRO_Osteoclasts::on_spinBox_SegAuto_Area_Min_valueChanged(int arg1)
{
    if(arg1 > ui->spinBox_SegAuto_Area_Max->value())
        ui->spinBox_SegAuto_Area_Max->setValue(arg1);

    Update_NucleiSegmentation_Auto_Steps(c_STEP_AREA);
    Update_Image_ProcView();
}

void D_MAKRO_Osteoclasts::on_spinBox_SegAuto_Area_Max_valueChanged(int arg1)
{
    if(arg1 < ui->spinBox_SegAuto_Area_Min->value())
        ui->spinBox_SegAuto_Area_Min->setValue(arg1);

    Update_NucleiSegmentation_Auto_Steps(c_STEP_AREA);
    Update_Image_ProcView();
}

void D_MAKRO_Osteoclasts::on_doubleSpinBox_SegAuto_Roundness_Thres_valueChanged(double arg1)
{
    arg1;
    Update_NucleiSegmentation_Auto_Steps(c_STEP_ROUNDNESS);
    Update_Image_ProcView();
}

void D_MAKRO_Osteoclasts::on_comboBox_SegMan_SegmentationType_currentIndexChanged(int index)
{
    index;

    state_SegMan_Draw_NewLine = true;
}

void D_MAKRO_Osteoclasts::on_comboBox_SegMan_Draw_Type_currentIndexChanged(int index)
{
    ui->spinBox_SegMan_Line_Width->setEnabled(index == c_SEG_PEN_LINE);
    ui->label_SegMan_NewLine_Description->setEnabled(index == c_SEG_PEN_LINE);

    state_SegMan_Draw_NewLine = true;
}
