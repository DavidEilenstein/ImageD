/************************************
 *   added:     ??.01.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_makro_iontracks.h"
#include "ui_d_makro_iontracks.h"

D_MAKRO_IonTracks::D_MAKRO_IonTracks(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_IonTracks)
{
    qDebug() << "D_MAKRO_IonTracks" << "D_MAKRO_IonTracks";

    ui->setupUi(this);

    //Storage
    pStore = pStorage;
    Update_Dimensions(); //plus vector init

    //Comboboxes
    Populate_CB_All();

    //Viewer
    View_Proc.set_GV(ui->graphicsView_ProcView);
    View_Results.set_GV(ui->graphicsView_ResImg);
    View_Proc.connect_Zoom(&View_Results);

    //Plot
    pChartView_Plot = new QChartView();
    ui->gridLayout_ResPlo->addWidget(pChartView_Plot);
    pChartView_Plot->setRenderHint(QPainter::Antialiasing);
    pChartView_Plot->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Plot->setInteractive(true);

    //Table
    Table_Tracks.set_TW(ui->tableWidget_ResTab);

    //CONNECTS

    //dimensions
    connect(ui->spinBox_Dimension_Dimension_X_Lateral,  SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Dimensions()));
    connect(ui->spinBox_Dimension_Dimension_Y_Lateral,  SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Dimensions()));
    connect(ui->spinBox_Dimension_Dimension_Z_Depth,    SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Dimensions()));
    connect(ui->doubleSpinBox_Dimension_Step_X_Lateral, SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Dimensions()));
    connect(ui->doubleSpinBox_Dimension_Step_Y_Lateral, SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Dimensions()));
    connect(ui->doubleSpinBox_Dimension_Step_Z_Depth,   SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Dimensions()));
    connect(ui->lineEdit_Dimension_Unit,                SIGNAL(textChanged(QString)),               this,                   SLOT(Update_Dimensions()));
    //load
    connect(ui->action_Open_Files,                      SIGNAL(triggered(bool)),                    this,                   SLOT(Load_DirectoriesList()));
    //save
    connect(ui->action_Save_Analysis,                   SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Analysis()));
    connect(ui->action_Save_Plot,                       SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Plot()));
    connect(ui->action_Save_Table,                      SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Table()));
    //proc
    connect(ui->action_Update_Processing,               SIGNAL(triggered(bool)),                    this,                   SLOT(Update_ImgProc()));
    //current analysis
    connect(ui->comboBox_CurAna_DataSet,                SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Load_Directoty()));
    connect(ui->comboBox_ProcView_Depth,                SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_View_Proc()));
    connect(ui->comboBox_ProcView_Lateral,              SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_View_Proc()));
    //porc view
    connect(ui->comboBox_ProcView_ProcStep,             SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_View_Proc()));
    //results
    connect(ui->tabWidget_Results,                      SIGNAL(currentChanged(int)),                this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_AxeTrans_X,             SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_AxeTrans_Y,             SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->checkBox_ResPlo_DisplayPoints,          SIGNAL(clicked(bool)),                      this,                   SLOT(Update_Results()));

    //plot
    connect(ui->comboBox_ResPlo_Type,                   SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_StatSingle,             SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_Group,                  SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_Lateral,                SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_Depth,                  SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_SaR_StatTracks,         SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_Grp_SaR_StatTracks,     SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));

    //table
    connect(ui->comboBox_ResTab_Type,                   SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResTab_StatSingle,             SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResTab_Group,                  SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResTab_Lateral,                SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResTab_Depth,                  SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));

    //image
    connect(ui->comboBox_ResImg_B,                      SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResImg_G,                      SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResImg_Depth,                  SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResImg_Lateral,                SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->checkBox_ResImg_Edge_G,                 SIGNAL(clicked(bool)),                      this,                   SLOT(Update_Results()));
    connect(ui->checkBox_ResImg_Edge_B,                 SIGNAL(clicked(bool)),                      this,                   SLOT(Update_Results()));

    //Stuff on Start
    Update_Max_Radius();
    setWindowTitle("ImageD - Ion Tracks Plugin");
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));

    this->showMaximized();
}

D_MAKRO_IonTracks::~D_MAKRO_IonTracks()
{
    //qDebug() << "D_MAKRO_IonTracks" << "~D_MAKRO_IonTracks";

    delete ui;
}

void D_MAKRO_IonTracks::closeEvent(QCloseEvent *event)
{
    if(ClosingPossible)
    {
        //qDebug() << "D_MAKRO_IonTracks" << "closeEvent";
        vvMA_Proc_ImgStep.clear();
        delete ui;
        event->accept();
    }
    else
    {
        event->ignore();
        this->showMinimized();
    }
}

void D_MAKRO_IonTracks::resizeEvent(QResizeEvent *event)
{
    event->accept();
    if(!FIL_InputCurrentSet.empty())
        Update_Views();
}

void D_MAKRO_IonTracks::Update_Views()
{
    qDebug() << "D_MAKRO_IonTracks" << "Update_Views";

    Update_View_Proc();
    View_Results.Update_View();
}

void D_MAKRO_IonTracks::Update_View_Proc()
{
    qDebug() << "D_MAKRO_IonTracks" << "Update_View_Proc" << Index_CurrentView() << ui->comboBox_ProcView_ProcStep->currentIndex();

    //checks
    if(Index_CurrentView() >= FIL_InputCurrentSet.size())
    {
        ERR(
                    ER_index_out_of_range,
                    "Update_View_Proc",
                    "Image index " + QString::number(Index_CurrentView()) + " out of range of current datasets filelist " + QString::number(FIL_InputCurrentSet.size()) + ".");
        return;
    }
    if(Index_CurrentView() >= vvMA_Proc_ImgStep.size())
    {
        ERR(
                    ER_index_out_of_range,
                    "Update_View_Proc",
                    "Image index " + QString::number(Index_CurrentView()) + " out of range of current datasets imagevector " + QString::number(vvMA_Proc_ImgStep.size()) + ".");
        return;
    }
    if(ui->comboBox_ProcView_ProcStep->currentIndex() >= vvMA_Proc_ImgStep[Index_CurrentView()].size())
    {
        ERR(
                    ER_index_out_of_range,
                    "Update_View_Proc",
                    "Step index " + QString::number(ui->comboBox_ProcView_ProcStep->currentIndex()) + " out of range of possible steps " + QString::number(vvMA_Proc_ImgStep[Index_CurrentView()].size()) + ".");
        return;
    }

    View_Proc.Update_Image(&(vvMA_Proc_ImgStep[Index_CurrentView()][ui->comboBox_ProcView_ProcStep->currentIndex()]));
}

void D_MAKRO_IonTracks::Update_Ui()
{
    if(this->isEnabled())
        return;

    this->repaint();
    qApp->processEvents();
}

void D_MAKRO_IonTracks::Update_ImgProc()
{
    if(ui->action_Block_Processing_Update->isChecked())
        return;

    qDebug() << "D_MAKRO_IonTracks" << "Update_ImgProc";

    Update_ImgProc_Proc(0);
}

void D_MAKRO_IonTracks::Update_ImgProc_Proc(int start_step)
{
    if(ui->action_Block_Processing_Update->isChecked())
        return;
    if(FIL_InputCurrentSet.empty())
        return;
    qDebug() << "D_MAKRO_IonTracks" << "Update_ImgProc_Proc" << "start_step:" << QSL_ProcStepSingle[start_step];

    calced_ImgProc = false;
    calced_ValDist = false;
    calced_StaTra = false;
    calced_StaSta = false;

    for(int img = 0; img < vvMA_Proc_ImgStep.size(); img++)
        for(int step = start_step; step < vvMA_Proc_ImgStep[img].size(); step++)
            Update_Step_Proc(img, step);


    calced_ImgProc = true;

    Update_View_Proc();
    Calc_All();
}

void D_MAKRO_IonTracks::Update_Step_Proc(int img, int step)
{
    if(ui->action_Block_Processing_Update->isChecked())
        return;

    //qDebug() << "D_MAKRO_IonTracks" << "Update_Step_Proc" << img << step;
    //checks
    if(img >= FIL_InputCurrentSet.size())
    {
        ERR(ER_index_out_of_range, "Update_Step_Proc", "Image index " + QString::number(img) + " out of range of current datasets filelist " + QString::number(FIL_InputCurrentSet.size()) + ".");
        return;
    }
    if(img >= vvMA_Proc_ImgStep.size())
    {
        ERR(ER_index_out_of_range, "Update_Step_Proc", "Image index " + QString::number(img) + " out of range of current datasets imagevector " + QString::number(vvMA_Proc_ImgStep.size()) + ".");
        return;
    }
    if(step >= vvMA_Proc_ImgStep[img].size())
    {
        ERR(ER_index_out_of_range, "Update_Step_Proc", "Step index " + QString::number(step) + " out of range of possible steps " + QString::number(vvMA_Proc_ImgStep[img].size()) + ".");
        return;
    }

    //switch for chosen img & step
    switch (step) {

    case c_STEP_LOAD:
    {
        ERR(D_Img_Proc::Load_From_Path(
                &(vvMA_Proc_ImgStep[img][c_STEP_LOAD]),
                FIL_InputCurrentSet[img].absoluteFilePath().toStdString()),
            "Update_Step_Proc",
            "c_STEP_LOAD");
    }
        break;

    case c_STEP_BLUR:
    {
        ERR(D_Img_Proc::Filter_Gauss(
                &(vvMA_Proc_ImgStep[img][c_STEP_BLUR]),
                &(vvMA_Proc_ImgStep[img][c_STEP_LOAD]),
                ui->spinBox_ProcSet_Blur_Size->value(),
                ui->spinBox_ProcSet_Blur_Size->value(),
                BORDER_DEFAULT,
                ui->doubleSpinBox_ProcSet_Blur_Sigma->value(),
                ui->doubleSpinBox_ProcSet_Blur_Sigma->value()),
            "Update_Step_Proc",
            "c_STEP_BLUR");
    }
        break;

    case c_STEP_BIN:
    {
        ERR(D_Img_Proc::Threshold_Relative_1C(
                &(vvMA_Proc_ImgStep[img][c_STEP_BIN]),
                &(vvMA_Proc_ImgStep[img][c_STEP_BLUR]),
                100.0,
                ui->doubleSpinBox_ProcSet_Binarization_Thres->value() / 100.0),
            "Update_Step_Proc",
            "c_STEP_BIN");
    }
        break;

    case c_STEP_EX_LARGE:
    {
        ERR(D_Img_Proc::Feature_Select(
                &(vvMA_Proc_ImgStep[img][c_STEP_EX_LARGE]),
                &(vvMA_Proc_ImgStep[img][c_STEP_BIN]),
                c_FEAT_AREA,
                0.0,
                ui->doubleSpinBox_ProcSet_ExLarge_MaxArea->value(),
                8),
            "Update_Step_Proc",
            "c_STEP_EX_LARGE");
    }
        break;

    case c_STEP_EX_ASPHERES:
    {
        ERR(D_Img_Proc::Feature_Select(
                &(vvMA_Proc_ImgStep[img][c_STEP_EX_ASPHERES]),
                &(vvMA_Proc_ImgStep[img][c_STEP_EX_LARGE]),
                c_FEAT_SPHERICITY,
                ui->doubleSpinBox_ProcSet_ExAsphere_MinSphere->value(),
                1.0,
                8),
            "Update_Step_Proc",
            "c_STEP_EX_ASPHERES");
    }
        break;

    case c_STEP_SAFETY_DIST:
    {
        ERR(D_Img_Proc::Morphology_Elemental(
                &(vvMA_Proc_ImgStep[img][c_STEP_SAFETY_DIST]),
                &(vvMA_Proc_ImgStep[img][c_STEP_BIN]),
                MORPH_DILATE,
                MORPH_ELLIPSE,
                ui->spinBox_ProcSet_SafetyDist_MinRadius->value(),
                ui->spinBox_ProcSet_SafetyDist_MinRadius->value(),
                BORDER_DEFAULT,
                1),
            "Update_Step_Proc",
            "c_STEP_SAFETY_DIST");
    }
        break;

    case c_STEP_EX_CONNECTED:
    {
        ERR(D_Img_Proc::Feature_Select(
                &(vvMA_Proc_ImgStep[img][c_STEP_EX_CONNECTED]),
                &(vvMA_Proc_ImgStep[img][c_STEP_SAFETY_DIST]),
                c_FEAT_SPHERICITY,
                ui->doubleSpinBox_ProcSet_ExConn_MinSphere->value(),
                1.0,
                8),
            "Update_Step_Proc",
            "c_STEP_EX_CONNECTED");
    }
        break;

    case c_STEP_TOI_ORIGINAL:
    {
        ERR(D_Img_Proc::Math_ImgImg_BitAnd(
                &(vvMA_Proc_ImgStep[img][c_STEP_TOI_ORIGINAL]),
                &(vvMA_Proc_ImgStep[img][c_STEP_EX_CONNECTED]),
                &(vvMA_Proc_ImgStep[img][c_STEP_EX_ASPHERES])),
            "Update_Step_Proc",
            "c_STEP_TOI_ORIGINAL");
    }
        break;

    case c_STEP_TOI_CENTROID:
    {
        ERR(D_Img_Proc::Reduce_Geometric(
                &(vvMA_Proc_ImgStep[img][c_STEP_TOI_CENTROID]),
                &(vvMA_Proc_ImgStep[img][c_STEP_TOI_ORIGINAL]),
                c_GEO_CENTROID,
                8,
                1,
                255),
            "Update_Step_Proc",
            "c_STEP_TOI_CENTROID");
    }
        break;

    case c_STEP_TOI_AREA:
    {
        ERR(D_Img_Proc::Morphology_Elemental(
                &(vvMA_Proc_ImgStep[img][c_STEP_TOI_AREA]),
                &(vvMA_Proc_ImgStep[img][c_STEP_TOI_CENTROID]),
                MORPH_DILATE,
                MORPH_ELLIPSE,
                max_radius,
                max_radius,
                BORDER_DEFAULT,
                1),
            "Update_Step_Proc",
            "c_STEP_TOI_AREA");
    }
        break;

    case c_STEP_TOI_LABEL:
    {
        ERR(D_Img_Proc::Labeling(
                &(vvMA_Proc_ImgStep[img][c_STEP_TOI_LABEL]),
                &(vvMA_Proc_ImgStep[img][c_STEP_TOI_AREA]),
                8,
                CV_16U),
            "Update_Step_Proc",
            "c_STEP_BLUR");
    }
        break;

    default:
        break;
    }
}

void D_MAKRO_IonTracks::Calc_All()
{
    Calc_ValueDistribution();
    Calc_Track_Stats();
    Calc_Stack_Stats_All();

    Update_Results();
}

void D_MAKRO_IonTracks::Calc_ValueDistribution()
{
    //create value distribution lists and calc distributions on axis in them

    if(!calced_ImgProc)
        return;
    calced_ValDist = false;
    calced_StaTra = false;
    calced_StaSta = false;

    vVD_ValDistLists_Img.clear();
    vVD_ValDistLists_Img.resize(vvMA_Proc_ImgStep.size());
    for(int img = 0; img < vVD_ValDistLists_Img.size(); img++)
    {
        vVD_ValDistLists_Img[img].set_Mats(
                    &(vvMA_Proc_ImgStep[img][c_STEP_TOI_LABEL]),
                    &(vvMA_Proc_ImgStep[img][c_STEP_LOAD]),
                    8);

        vVD_ValDistLists_Img[img].calc_All();
    }

    calced_ValDist = true;
}

void D_MAKRO_IonTracks::Calc_Track_Stats()
{
    //sort stats on radii in vectors

    if(!calced_ValDist)
        return;
    calced_StaTra = false;
    calced_StaSta = false;


    //clear & resize all
    vvvd_All_StaRadTra.clear();
    vvvd_All_StaRadTra.resize(c_STAT_NUMBER_OF_STATS);

    //clear & resize lateral
    vvvvd_Lat_DimStaRadTra.clear();
    vvvvd_Lat_DimStaRadTra.resize(Dim_Lat_Dim);
    for(int lat = 0; lat < Dim_Lat_Dim; lat++)
    {
        vvvvd_Lat_DimStaRadTra[lat].clear();
        vvvvd_Lat_DimStaRadTra[lat].resize(c_STAT_NUMBER_OF_STATS);
        for(int sta = 0; sta < c_STAT_NUMBER_OF_STATS; sta++)
        {
            vvvvd_Lat_DimStaRadTra[lat][sta].clear();
            vvvvd_Lat_DimStaRadTra[lat][sta].resize(max_radius + 1);
        }
    }

    //clear & resize depth
    vvvvd_Dep_DimStaRadTra.clear();
    vvvvd_Dep_DimStaRadTra.resize(Dim_ZDep_Dim);
    for(int dep = 0; dep < Dim_ZDep_Dim; dep++)
    {
        vvvvd_Dep_DimStaRadTra[dep].clear();
        vvvvd_Dep_DimStaRadTra[dep].resize(c_STAT_NUMBER_OF_STATS);
        for(int sta = 0; sta < c_STAT_NUMBER_OF_STATS; sta++)
        {
            vvvvd_Dep_DimStaRadTra[dep][sta].clear();
            vvvvd_Dep_DimStaRadTra[dep][sta].resize(max_radius + 1);
        }
    }


    //loop stats
    for(int sta = 0; sta < vvvd_All_StaRadTra.size(); sta++)
    {
        //set r max
        vvvd_All_StaRadTra[sta].clear();
        vvvd_All_StaRadTra[sta].resize(max_radius + 1);

        //loop images
        for(int img = 0; img < vVD_ValDistLists_Img.size(); img++)
        {
            //calc pos in stack
            int lat = img / Dim_ZDep_Dim;
            int dep = img % Dim_ZDep_Dim;

            //get axe stat for image
            vector<vector<double>> vvd_tmp_TraRad = vVD_ValDistLists_Img[img].get_Axe(c_AXE_POLAR_RADIUS, sta);

            //loop tracks in image
            for(int tra = 0; tra < vvd_tmp_TraRad.size(); tra++)
            {
                //check radii match
                if(max_radius + 1 == vvd_tmp_TraRad[tra].size())
                {
                    //loop radii, transpose, sort in resolution groups
                    for(int rad = 0; rad < max_radius + 1; rad++)
                    {
                        vvvd_All_StaRadTra          [sta][rad].push_back(vvd_tmp_TraRad[tra][rad]);
                        vvvvd_Lat_DimStaRadTra [lat][sta][rad].push_back(vvd_tmp_TraRad[tra][rad]);
                        vvvvd_Dep_DimStaRadTra [dep][sta][rad].push_back(vvd_tmp_TraRad[tra][rad]);
                    }
                }
                else
                {
                    qDebug() << "Radius mismatch";
                }
            }
        }   
    }

    //get track number
    tracks_count =  static_cast<int>(vvvd_All_StaRadTra[0][0].size());

    calced_StaTra = true;
}

void D_MAKRO_IonTracks::Calc_Stack_Stats_All()
{
    //clac stats of radii in stack

    if(!calced_StaTra)
        return;
    calced_StaSta = false;

    //ALL
    qDebug() << "Calc_Stack_Stats_All" << "start all";

    //clear & resize all
    vvvd_All_StaStaRad.clear();
    vvvd_All_StaStaRad.resize(vvvd_All_StaRadTra.size());

    //loop stats (of pixels at radii in single tracks)
    for(int sta_single = 0; sta_single < vvvd_All_StaStaRad.size(); sta_single++)
    {
        vvvd_All_StaStaRad[sta_single].clear();
        vvvd_All_StaStaRad[sta_single].resize(c_STAT_NUMBER_OF_STATS);

        //loop stats (of radii in all tracks)
        for(int sta_tracks = 0; sta_tracks < vvvd_All_StaStaRad[sta_single].size(); sta_tracks++)
            vvvd_All_StaStaRad[sta_single][sta_tracks].resize(max_radius + 1);

        //loop radii
        for(int rad = 0; rad < max_radius + 1; rad++)
        {
            //qDebug() << rad;
            //calc stats of all tracks at a given radius
            vector<double> vd_tmp_StatsAtRadius;
            D_Stat::Calc_Stats(
                    &vd_tmp_StatsAtRadius,
                    vvvd_All_StaRadTra[sta_single][rad],
                    true);

            //put the stats of all tracks at given radius in the needed format
            for(int sta_tracks = 0; sta_tracks < vd_tmp_StatsAtRadius.size(); sta_tracks++)
                vvvd_All_StaStaRad[sta_single][sta_tracks][rad] = vd_tmp_StatsAtRadius[sta_tracks];
        }
    }


    //LATERAL
    qDebug() << "Calc_Stack_Stats_All" << "start lateral";

    //clear & resize lateral
    vvvvd_Lat_DimStaStaRad.clear();
    vvvvd_Lat_DimStaStaRad.resize(Dim_Lat_Dim);

    for(int lat = 0; lat < vvvvd_Lat_DimStaStaRad.size(); lat++)
    {
        vvvvd_Lat_DimStaStaRad[lat].resize(c_STAT_NUMBER_OF_STATS);

        //loop stats (of pixels at radii in single tracks)
        for(int sta_single = 0; sta_single < vvvvd_Lat_DimStaStaRad[lat].size(); sta_single++)
        {
            vvvvd_Lat_DimStaStaRad[lat][sta_single].clear();
            vvvvd_Lat_DimStaStaRad[lat][sta_single].resize(c_STAT_NUMBER_OF_STATS);

            //loop stats (of radii in all tracks)
            for(int sta_tracks = 0; sta_tracks < vvvvd_Lat_DimStaStaRad[lat][sta_single].size(); sta_tracks++)
                vvvvd_Lat_DimStaStaRad[lat][sta_single][sta_tracks].resize(max_radius + 1);

            //loop radii
            for(int rad = 0; rad < max_radius + 1; rad++)
            {
                //qDebug() << rad;
                //calc stats of all tracks at a given radius
                vector<double> vd_tmp_StatsAtRadius;
                D_Stat::Calc_Stats(
                        &vd_tmp_StatsAtRadius,
                        vvvvd_Lat_DimStaRadTra[lat][sta_single][rad],
                        true);

                //put the stats of all tracks at given radius in the needed format
                for(int sta_tracks = 0; sta_tracks < vd_tmp_StatsAtRadius.size(); sta_tracks++)
                    vvvvd_Lat_DimStaStaRad[lat][sta_single][sta_tracks][rad] = vd_tmp_StatsAtRadius[sta_tracks];
            }
        }
    }


    //DEPTH
    qDebug() << "Calc_Stack_Stats_All" << "start depth";

    //clear & resize depth
    vvvvd_Dep_DimStaStaRad.clear();
    vvvvd_Dep_DimStaStaRad.resize(Dim_ZDep_Dim);

    for(int dep = 0; dep < vvvvd_Dep_DimStaStaRad.size(); dep++)
    {
        vvvvd_Dep_DimStaStaRad[dep].resize(c_STAT_NUMBER_OF_STATS);

        //loop stats (of pixels at radii in single tracks)
        for(int sta_single = 0; sta_single < vvvvd_Dep_DimStaStaRad[dep].size(); sta_single++)
        {
            vvvvd_Dep_DimStaStaRad[dep][sta_single].clear();
            vvvvd_Dep_DimStaStaRad[dep][sta_single].resize(c_STAT_NUMBER_OF_STATS);

            //loop stats (of radii in all tracks)
            for(int sta_tracks = 0; sta_tracks < vvvvd_Dep_DimStaStaRad[dep][sta_single].size(); sta_tracks++)
                vvvvd_Dep_DimStaStaRad[dep][sta_single][sta_tracks].resize(max_radius + 1);

            //loop radii
            for(int rad = 0; rad < max_radius + 1; rad++)
            {
                //qDebug() << rad;
                //calc stats of all tracks at at given radius
                vector<double> vd_tmp_StatsAtRadius;
                D_Stat::Calc_Stats(
                        &vd_tmp_StatsAtRadius,
                        vvvvd_Dep_DimStaRadTra[dep][sta_single][rad],
                        true);

                //put the stats of all tracks a given radius in the needed format
                for(int sta_tracks = 0; sta_tracks < vd_tmp_StatsAtRadius.size(); sta_tracks++)
                    vvvvd_Dep_DimStaStaRad[dep][sta_single][sta_tracks][rad] = vd_tmp_StatsAtRadius[sta_tracks];
            }
        }
    }

    qDebug() << "Calc_Stack_Stats_All" << "finished";

    calced_StaSta = true;
}


void D_MAKRO_IonTracks::Update_Results()
{
    qDebug() << "Update_Results";
    if(!calced_StaSta)
        return;

    switch (ui->tabWidget_Results->currentIndex()) {

    case c_RES_IMG:
        Image_ColorRGB_Info();
        break;

    case c_RES_TABLE:

        switch (ui->comboBox_ResTab_Type->currentIndex()) {

        case c_TAB_RAW:
            Table_SingleTrack();
            break;

        case c_TAB_STAT:
            Table_TrackStats();
            break;

        default:
            Table_Tracks.clear_data();
            break;
        }

        break;

    case c_RES_PLOT:

        switch (ui->comboBox_ResPlo_Type->currentIndex()) {

        case c_PLO_STAT_AT_RADIUS:
            Plot_StatAtRadius_All();
            break;

        case c_PLO_MEAN_SD:
            Plot_MeanSD_All();
            break;

        case c_PLO_MEDIAN_ADM:
            Plot_MedianADM_All();
            break;

        case c_PLO_QUANTILES:
            Plot_Quantiles_All();
            break;

        case c_PLO_STAT_AT_RADIUS_ALL:
            Plot_StatAtRadius_All_Group();
            break;

        default:
            break;
        }

        break;

    default:
        break;
    }

    Update_Ui();
}

void D_MAKRO_IonTracks::Plot_StatAtRadius_All()
{
    int dep = ui->comboBox_ResPlo_Depth->currentIndex();
    int lat = ui->comboBox_ResPlo_Lateral->currentIndex();
    int stat_single = ui->comboBox_ResPlo_StatSingle->currentIndex();
    int stat_tracks = ui->comboBox_ResPlo_SaR_StatTracks->currentIndex();
    int trans_x = ui->comboBox_ResPlo_AxeTrans_X->currentIndex();
    int trans_y = ui->comboBox_ResPlo_AxeTrans_Y->currentIndex();
    bool display_points = ui->checkBox_ResPlo_DisplayPoints->isChecked();
    QString QS_stat_single = ui->comboBox_ResPlo_StatSingle->currentText();
    QString QS_stat_tracks = ui->comboBox_ResPlo_SaR_StatTracks->currentText();

    switch (ui->comboBox_ResPlo_Group->currentIndex()) {

    case c_GRP_ALL:
        D_Plot::Plot_Line_XY_Single(
                    pChartView_Plot,
                    vvvd_All_StaStaRad[stat_single][stat_tracks],
                    "<b>Intensity at Radius</b><br>" + QString::number(max_radius) + "px distance between tracks<br>" + QString::number(tracks_count) + " tracks"
                    "<br>tracks all",
                    "Tracks",
                    "Radius in px",
                    QS_stat_tracks + " of " + QS_stat_single + " of intesities at radii in tracks",
                    trans_x,
                    trans_y,
                    display_points);
        break;

    case c_GRP_LATERAL:
        D_Plot::Plot_Line_XY_Single(
                    pChartView_Plot,
                    vvvvd_Lat_DimStaStaRad[lat][stat_single][stat_tracks],
                    "<b>Intensity at Radius</b>"
                    "<br>" + QString::number(max_radius) + "px distance between tracks"
                    "<br>" + QString::number(vvvvd_Lat_DimStaStaRad[lat][stat_single][stat_tracks].size()) + " tracks"
                    "<br>tracks at " + QSL_Dim_Lat[lat],
                    "Tracks",
                    "Radius in px",
                    QS_stat_tracks + " of " + QS_stat_single + " of intesities at radii in tracks",
                    trans_x,
                    trans_y,
                    display_points);
        break;

    case c_GRP_DEPTH:
        D_Plot::Plot_Line_XY_Single(
                    pChartView_Plot,
                    vvvvd_Dep_DimStaStaRad[dep][stat_single][stat_tracks],
                    "<b>Intensity at Radius</b>"
                    "<br>" + QString::number(max_radius) + "px distance between tracks"
                    "<br>" + QString::number(vvvvd_Dep_DimStaStaRad[dep][stat_single][stat_tracks].size()) + " tracks"
                    "<br>tracks at " + QSL_Dim_Dep[dep],
                    "Tracks",
                    "Radius in px",
                    QS_stat_tracks + " of " + QS_stat_single + " of intesities at radii in tracks",
                    trans_x,
                    trans_y,
                    display_points);
        break;

    default:
        break;
    }
}

void D_MAKRO_IonTracks::Plot_StatAtRadius_All_Group()
{
    //indices
    int stat_single = ui->comboBox_ResPlo_StatSingle->currentIndex();
    int stat_tracks = ui->comboBox_ResPlo_Grp_SaR_StatTracks->currentIndex();
    int trans_x = ui->comboBox_ResPlo_AxeTrans_X->currentIndex();
    int trans_y = ui->comboBox_ResPlo_AxeTrans_Y->currentIndex();
    bool display_points = ui->checkBox_ResPlo_DisplayPoints->isChecked();
    QString QS_stat_single = ui->comboBox_ResPlo_StatSingle->currentText();
    QString QS_stat_tracks = ui->comboBox_ResPlo_Grp_SaR_StatTracks->currentText();
    QString QS_GroupDescription;
    QStringList QSL_Series;

    //basic data
    vector<vector<double>> vvd_tmp_DimRad;



    //data
    switch (ui->comboBox_ResPlo_Group->currentIndex()) {

    case c_GRP_ALL:
    {
        D_Plot::Plot_Empty(pChartView_Plot);
        return;
    }
        break;

    case c_GRP_LATERAL:
    {
        vvd_tmp_DimRad.resize(Dim_Lat_Dim);
        for(int lat = 0; lat < Dim_Lat_Dim; lat++)
            vvd_tmp_DimRad[lat] = vvvvd_Lat_DimStaStaRad[lat][stat_single][stat_tracks];

        QSL_Series = QSL_Dim_Lat;
        QS_GroupDescription = "tracks grouped: lateral";
    }
        break;

    case c_GRP_DEPTH:
    {
        vvd_tmp_DimRad.resize(Dim_ZDep_Dim);
        for(int dep = 0; dep < Dim_ZDep_Dim; dep++)
            vvd_tmp_DimRad[dep] = vvvvd_Dep_DimStaStaRad[dep][stat_single][stat_tracks];

        QSL_Series = QSL_Dim_Dep;
        QS_GroupDescription = "tracks grouped: depth";
    }
        break;

    default:
        break;
    }



    //plot
    D_Plot::Plot_Line_XY_Multi(
                pChartView_Plot,
                vvd_tmp_DimRad,
                "<b>Arithmetic mean at Radius</b>"
                "<br>" + QString::number(max_radius) + "px distance between tracks"
                "<br>" + QString::number(tracks_count) + " tracks"
                "<br>" + QS_GroupDescription,
                QSL_Series,
                "Radius in px",
                QS_stat_tracks + " of " + QS_stat_single + " of intesities at radii in tracks",
                trans_x,
                trans_y,
                display_points,
                true);

    pChartView_Plot->chart()->legend()->setAlignment(Qt::AlignLeft);
}

void D_MAKRO_IonTracks::Plot_MeanSD_All()
{
    //indices
    int dep = ui->comboBox_ResPlo_Depth->currentIndex();
    int lat = ui->comboBox_ResPlo_Lateral->currentIndex();
    int stat_single = ui->comboBox_ResPlo_StatSingle->currentIndex();
    int trans_x = ui->comboBox_ResPlo_AxeTrans_X->currentIndex();
    int trans_y = ui->comboBox_ResPlo_AxeTrans_Y->currentIndex();
    int track_count_group;
    bool display_points = ui->checkBox_ResPlo_DisplayPoints->isChecked();
    QString QS_stat_single = ui->comboBox_ResPlo_StatSingle->currentText();
    QString QS_GroupDescription;

    //basic data
    vector<vector<double>> vvd_tmp_StatRad;
    vvd_tmp_StatRad.resize(3);

    //series name
    QStringList QSL_Series =
    {
        "Arithmetic mean - standard deviation (total)",
        "Arithmetic mean",
        "Arithmetic mean + standard deviation (total)"
    };



    switch (ui->comboBox_ResPlo_Group->currentIndex()) {

    case c_GRP_ALL:
    {
        for(int sta = 0; sta < vvd_tmp_StatRad.size(); sta++)
            vvd_tmp_StatRad[sta] = vvvd_All_StaStaRad[stat_single][c_STAT_MEAN_ARITMETIC];

        //loop radii and calc mean +/- SD
        for(int rad = 0; rad < max_radius + 1; rad++)
        {
            vvd_tmp_StatRad[0][rad] = vvd_tmp_StatRad[1][rad] - vvvd_All_StaStaRad[stat_single][c_STAT_STAN_DEV_TOTAL][rad];
            vvd_tmp_StatRad[2][rad] = vvd_tmp_StatRad[1][rad] + vvvd_All_StaStaRad[stat_single][c_STAT_STAN_DEV_TOTAL][rad];
        }

        QS_GroupDescription = "tracks all";
        track_count_group = tracks_count;
    }
        break;

    case c_GRP_LATERAL:
    {
        for(int sta = 0; sta < vvd_tmp_StatRad.size(); sta++)
            vvd_tmp_StatRad[sta] = vvvvd_Lat_DimStaStaRad[lat][stat_single][c_STAT_MEAN_ARITMETIC];

        //loop radii and calc mean +/- SD
        for(int rad = 0; rad < max_radius + 1; rad++)
        {
            vvd_tmp_StatRad[0][rad] = vvd_tmp_StatRad[1][rad] - vvvvd_Lat_DimStaStaRad[lat][stat_single][c_STAT_STAN_DEV_TOTAL][rad];
            vvd_tmp_StatRad[2][rad] = vvd_tmp_StatRad[1][rad] + vvvvd_Lat_DimStaStaRad[lat][stat_single][c_STAT_STAN_DEV_TOTAL][rad];
        }

        QS_GroupDescription = "tracks at " + QSL_Dim_Lat[lat];
        track_count_group = static_cast<int>(vvvvd_Lat_DimStaStaRad[lat][stat_single][0].size());
    }
        break;

    case c_GRP_DEPTH:
    {
        for(int sta = 0; sta < vvd_tmp_StatRad.size(); sta++)
            vvd_tmp_StatRad[sta] = vvvvd_Dep_DimStaStaRad[dep][stat_single][c_STAT_MEAN_ARITMETIC];

        //loop radii and calc mean +/- SD
        for(int rad = 0; rad < max_radius + 1; rad++)
        {
            vvd_tmp_StatRad[0][rad] = vvd_tmp_StatRad[1][rad] - vvvvd_Dep_DimStaStaRad[dep][stat_single][c_STAT_STAN_DEV_TOTAL][rad];
            vvd_tmp_StatRad[2][rad] = vvd_tmp_StatRad[1][rad] + vvvvd_Dep_DimStaStaRad[dep][stat_single][c_STAT_STAN_DEV_TOTAL][rad];
        }

        QS_GroupDescription = "tracks at " + QSL_Dim_Dep[dep];
        track_count_group = static_cast<int>(vvvvd_Dep_DimStaStaRad[dep][stat_single][0].size());
    }
        break;

    default:
        break;
    }



    //plot
    D_Plot::Plot_Line_XY_Multi(
                pChartView_Plot,
                vvd_tmp_StatRad,
                "<b>Arithmetic mean at Radius</b>"
                "<br>" + QString::number(max_radius) + "px distance between tracks"
                "<br>" + QString::number(track_count_group) + " tracks"
                "<br>" + QS_GroupDescription,
                QSL_Series,
                "Radius in px",
                "Statistical quantity of " + QS_stat_single + " of intesities at radii in tracks",
                trans_x,
                trans_y,
                display_points);
}

void D_MAKRO_IonTracks::Plot_MedianADM_All()
{
    //indices
    int dep = ui->comboBox_ResPlo_Depth->currentIndex();
    int lat = ui->comboBox_ResPlo_Lateral->currentIndex();
    int stat_single = ui->comboBox_ResPlo_StatSingle->currentIndex();
    int trans_x = ui->comboBox_ResPlo_AxeTrans_X->currentIndex();
    int trans_y = ui->comboBox_ResPlo_AxeTrans_Y->currentIndex();
    int track_count_group;
    bool display_points = ui->checkBox_ResPlo_DisplayPoints->isChecked();
    QString QS_stat_single = ui->comboBox_ResPlo_StatSingle->currentText();
    QString QS_GroupDescription;

    //basic data
    vector<vector<double>> vvd_tmp_StatRad;
    vvd_tmp_StatRad.resize(3);

    //series name
    QStringList QSL_Series =
    {
        "Median - average absolute deviation from median",
        "Median",
        "Median + average absolute deviation from median"
    };



    switch (ui->comboBox_ResPlo_Group->currentIndex()) {

    case c_GRP_ALL:
    {
        for(int sta = 0; sta < vvd_tmp_StatRad.size(); sta++)
            vvd_tmp_StatRad[sta] = vvvd_All_StaStaRad[stat_single][c_STAT_MEDIAN];

        //loop radii and calc mean +/- SD
        for(int rad = 0; rad < max_radius + 1; rad++)
        {
            vvd_tmp_StatRad[0][rad] = vvd_tmp_StatRad[1][rad] - vvvd_All_StaStaRad[stat_single][c_STAT_ABS_DEV_MED][rad];
            vvd_tmp_StatRad[2][rad] = vvd_tmp_StatRad[1][rad] + vvvd_All_StaStaRad[stat_single][c_STAT_ABS_DEV_MED][rad];
        }

        QS_GroupDescription = "tracks all";
        track_count_group = tracks_count;
    }
        break;

    case c_GRP_LATERAL:
    {
        for(int sta = 0; sta < vvd_tmp_StatRad.size(); sta++)
            vvd_tmp_StatRad[sta] = vvvvd_Lat_DimStaStaRad[lat][stat_single][c_STAT_MEDIAN];

        //loop radii and calc mean +/- SD
        for(int rad = 0; rad < max_radius + 1; rad++)
        {
            vvd_tmp_StatRad[0][rad] = vvd_tmp_StatRad[1][rad] - vvvvd_Lat_DimStaStaRad[lat][stat_single][c_STAT_ABS_DEV_MED][rad];
            vvd_tmp_StatRad[2][rad] = vvd_tmp_StatRad[1][rad] + vvvvd_Lat_DimStaStaRad[lat][stat_single][c_STAT_ABS_DEV_MED][rad];
        }

        QS_GroupDescription = "tracks at " + QSL_Dim_Lat[lat];
        track_count_group = static_cast<int>(vvvvd_Lat_DimStaStaRad[lat][stat_single][0].size());
    }
        break;

    case c_GRP_DEPTH:
    {
        for(int sta = 0; sta < vvd_tmp_StatRad.size(); sta++)
            vvd_tmp_StatRad[sta] = vvvvd_Dep_DimStaStaRad[dep][stat_single][c_STAT_MEDIAN];

        //loop radii and calc mean +/- SD
        for(int rad = 0; rad < max_radius + 1; rad++)
        {
            vvd_tmp_StatRad[0][rad] = vvd_tmp_StatRad[1][rad] - vvvvd_Dep_DimStaStaRad[dep][stat_single][c_STAT_ABS_DEV_MED][rad];
            vvd_tmp_StatRad[2][rad] = vvd_tmp_StatRad[1][rad] + vvvvd_Dep_DimStaStaRad[dep][stat_single][c_STAT_ABS_DEV_MED][rad];
        }

        QS_GroupDescription = "tracks at " + QSL_Dim_Dep[dep];
        track_count_group = static_cast<int>(vvvvd_Dep_DimStaStaRad[dep][stat_single][0].size());
    }
        break;

    default:
        break;
    }


    //plot
    D_Plot::Plot_Line_XY_Multi(
                pChartView_Plot,
                vvd_tmp_StatRad,
                "<b>Median at Radius</b>"
                "<br>" + QString::number(max_radius) + "px distance between tracks"
                "<br>" + QString::number(track_count_group) + " tracks"
                "<br>" + QS_GroupDescription,
                QSL_Series,
                "Radius in px",
                "Statistical quantity of " + QS_stat_single + " of intesities at radii in tracks",
                trans_x,
                trans_y,
                display_points);
}

void D_MAKRO_IonTracks::Plot_Quantiles_All()
{
    //indices
    int dep = ui->comboBox_ResPlo_Depth->currentIndex();
    int lat = ui->comboBox_ResPlo_Lateral->currentIndex();
    int stat_single = ui->comboBox_ResPlo_StatSingle->currentIndex();
    int trans_x = ui->comboBox_ResPlo_AxeTrans_X->currentIndex();
    int trans_y = ui->comboBox_ResPlo_AxeTrans_Y->currentIndex();
    int track_count_group;
    bool display_points = ui->checkBox_ResPlo_DisplayPoints->isChecked();
    QString QS_stat_single = ui->comboBox_ResPlo_StatSingle->currentText();
    QString QS_GroupDescription;

    //basic data
    vector<vector<double>> vvd_tmp_StatRad;
    vvd_tmp_StatRad.resize(6);

    //series name
    QStringList QSL_Series =
    {
        "Minimum",
        "20%",
        "40%",
        "60%",
        "80%",
        "Maximum",
    };


    switch (ui->comboBox_ResPlo_Group->currentIndex()) {

    case c_GRP_ALL:
    {
        vvd_tmp_StatRad[0] = vvvd_All_StaStaRad[stat_single][c_STAT_MINIMUM];
        vvd_tmp_StatRad[1] = vvvd_All_StaStaRad[stat_single][c_STAT_QUANTIL_20];
        vvd_tmp_StatRad[2] = vvvd_All_StaStaRad[stat_single][c_STAT_QUANTIL_40];
        vvd_tmp_StatRad[3] = vvvd_All_StaStaRad[stat_single][c_STAT_QUANTIL_60];
        vvd_tmp_StatRad[4] = vvvd_All_StaStaRad[stat_single][c_STAT_QUANTIL_80];
        vvd_tmp_StatRad[5] = vvvd_All_StaStaRad[stat_single][c_STAT_MAXIMUM];

        QS_GroupDescription = "tracks all";
        track_count_group = tracks_count;
    }
        break;

    case c_GRP_LATERAL:
    {
        vvd_tmp_StatRad[0] = vvvvd_Lat_DimStaStaRad[lat][stat_single][c_STAT_MINIMUM];
        vvd_tmp_StatRad[1] = vvvvd_Lat_DimStaStaRad[lat][stat_single][c_STAT_QUANTIL_20];
        vvd_tmp_StatRad[2] = vvvvd_Lat_DimStaStaRad[lat][stat_single][c_STAT_QUANTIL_40];
        vvd_tmp_StatRad[3] = vvvvd_Lat_DimStaStaRad[lat][stat_single][c_STAT_QUANTIL_60];
        vvd_tmp_StatRad[4] = vvvvd_Lat_DimStaStaRad[lat][stat_single][c_STAT_QUANTIL_80];
        vvd_tmp_StatRad[5] = vvvvd_Lat_DimStaStaRad[lat][stat_single][c_STAT_MAXIMUM];

        QS_GroupDescription = "tracks at " + QSL_Dim_Lat[lat];
        track_count_group = static_cast<int>(vvvvd_Lat_DimStaStaRad[lat][stat_single][0].size());
    }
        break;

    case c_GRP_DEPTH:
    {
        vvd_tmp_StatRad[0] = vvvvd_Dep_DimStaStaRad[dep][stat_single][c_STAT_MINIMUM];
        vvd_tmp_StatRad[1] = vvvvd_Dep_DimStaStaRad[dep][stat_single][c_STAT_QUANTIL_20];
        vvd_tmp_StatRad[2] = vvvvd_Dep_DimStaStaRad[dep][stat_single][c_STAT_QUANTIL_40];
        vvd_tmp_StatRad[3] = vvvvd_Dep_DimStaStaRad[dep][stat_single][c_STAT_QUANTIL_60];
        vvd_tmp_StatRad[4] = vvvvd_Dep_DimStaStaRad[dep][stat_single][c_STAT_QUANTIL_80];
        vvd_tmp_StatRad[5] = vvvvd_Dep_DimStaStaRad[dep][stat_single][c_STAT_MAXIMUM];

        QS_GroupDescription = "tracks at " + QSL_Dim_Dep[dep];
        track_count_group = static_cast<int>(vvvvd_Dep_DimStaStaRad[dep][stat_single][0].size());
    }
        break;

    default:
        break;
    }


    //plot
    D_Plot::Plot_Line_XY_Multi(
                pChartView_Plot,
                vvd_tmp_StatRad,
                "<b>Quantiles at Radius</b>"
                "<br>" + QString::number(max_radius) + "px distance between tracks"
                "<br>" + QString::number(track_count_group) + " tracks"
                "<br>" + QS_GroupDescription,
                QSL_Series,
                "Radius in px",
                "Statistical quantity of " + QS_stat_single + " of intesities at radii in tracks",
                trans_x,
                trans_y,
                display_points);
}

void D_MAKRO_IonTracks::Table_SingleTrack()
{
    int dep = ui->comboBox_ResTab_Depth->currentIndex();
    int lat = ui->comboBox_ResTab_Lateral->currentIndex();
    int sta = ui->comboBox_ResTab_StatSingle->currentIndex();

    QStringList QSl_Tracks;

    switch (ui->comboBox_ResTab_Group->currentIndex()) {

    case c_GRP_ALL:
        for(int t = 0; t < tracks_count; t++)
            QSl_Tracks.append("track_" + QString::number(t));

        Table_Tracks.set_data_d_2D_qsl_qsl(
                    vvvd_All_StaRadTra[sta],
                    QSL_Radius,
                    QSl_Tracks);
        break;

    case c_GRP_LATERAL:
        for(int t = 0; t < vvvvd_Lat_DimStaRadTra[lat][sta][0].size(); t++)
            QSl_Tracks.append("track_" + QString::number(t));

        Table_Tracks.set_data_d_2D_qsl_qsl(
                    vvvvd_Lat_DimStaRadTra[lat][sta],
                    QSL_Radius,
                    QSl_Tracks);
        break;

    case c_GRP_DEPTH:
        for(int t = 0; t < vvvvd_Dep_DimStaRadTra[dep][sta][0].size(); t++)
            QSl_Tracks.append("track_" + QString::number(t));

        Table_Tracks.set_data_d_2D_qsl_qsl(
                    vvvvd_Dep_DimStaRadTra[dep][sta],
                    QSL_Radius,
                    QSl_Tracks);
        break;

    default:
        break;
    }
}

void D_MAKRO_IonTracks::Table_TrackStats()
{
    int dep = ui->comboBox_ResTab_Depth->currentIndex();
    int lat = ui->comboBox_ResTab_Lateral->currentIndex();
    int sta = ui->comboBox_ResTab_StatSingle->currentIndex();

    switch (ui->comboBox_ResTab_Group->currentIndex()) {

    case c_GRP_ALL:
        Table_Tracks.set_data_d_2D_qsl_qsl(
                    vvvd_All_StaStaRad[sta],
                    QSL_StatList,
                    QSL_Radius);
        break;

    case c_GRP_LATERAL:

        qDebug() << "lateral:" << lat << "/" << vvvvd_Lat_DimStaStaRad.size();
        qDebug() << "sta_sng:" << sta << "/" << vvvvd_Lat_DimStaStaRad[lat].size();
        qDebug() << "sta_stc:" << "sta" << "/" << vvvvd_Lat_DimStaStaRad[lat][sta].size();
        qDebug() << "r_radii:" << "rad" << "/" << vvvvd_Lat_DimStaStaRad[lat][sta][0].size();

        Table_Tracks.set_data_d_2D_qsl_qsl(
                    vvvvd_Lat_DimStaStaRad[lat][sta],
                    QSL_StatList,
                    QSL_Radius);
        break;

    case c_GRP_DEPTH:
        Table_Tracks.set_data_d_2D_qsl_qsl(
                    vvvvd_Dep_DimStaStaRad[dep][sta],
                    QSL_StatList,
                    QSL_Radius);

        break;

    default:
        break;
    }
}

void D_MAKRO_IonTracks::Image_ColorRGB_Info()
{
    //image index
    int index_img = 0;
    if(!QSL_Dim_Dep.empty() && !QSL_Dim_Lat.empty())
        index_img = ui->comboBox_ResImg_Depth->currentIndex() + ui->comboBox_ResImg_Lateral->currentIndex() * Dim_ZDep_Dim;

    int step_g;
    switch (ui->comboBox_ResImg_G->currentIndex()) {
    case c_IMG_BINARY:          step_g = c_STEP_BIN;            break;
    case c_IMG_TOI:             step_g = c_STEP_TOI_ORIGINAL;   break;
    case c_IMG_ROI:             step_g = c_STEP_TOI_AREA;       break;
    case c_IMG_EX_LARGE:        step_g = c_STEP_EX_LARGE;       break;
    case c_IMG_EX_ASPHERE:      step_g = c_STEP_EX_ASPHERES;    break;
    case c_IMG_SAPHETY_RADIUS:  step_g = c_STEP_SAFETY_DIST;    break;
    case c_IMG_EX_CONNECTED:    step_g = c_STEP_EX_CONNECTED;   break;
    default:                    step_g = 0;                     break;}

    int step_b;
    switch (ui->comboBox_ResImg_B->currentIndex()) {
    case c_IMG_BINARY:          step_b = c_STEP_BIN;            break;
    case c_IMG_TOI:             step_b = c_STEP_TOI_ORIGINAL;   break;
    case c_IMG_ROI:             step_b = c_STEP_TOI_AREA;       break;
    case c_IMG_EX_LARGE:        step_b = c_STEP_EX_LARGE;       break;
    case c_IMG_EX_ASPHERE:      step_b = c_STEP_EX_ASPHERES;    break;
    case c_IMG_SAPHETY_RADIUS:  step_b = c_STEP_SAFETY_DIST;    break;
    case c_IMG_EX_CONNECTED:    step_b = c_STEP_EX_CONNECTED;   break;
    default:                    step_b = 0;                     break;}

    //images
    Mat MA_tmp_R;
    Mat MA_tmp_G;
    Mat MA_tmp_B;
    Mat MA_tmp_Merge;

    //RED
    ERR(D_Img_Proc::Normalize(
            &MA_tmp_R,
            &(vvMA_Proc_ImgStep[index_img][c_STEP_LOAD]),
            CV_MINMAX,
            CV_8UC1,
            0,
            255),
        "Image_ColorRGB_Info",
        "Red");

    //GREEN
    if(ui->checkBox_ResImg_Edge_G->isChecked())
        ERR(D_Img_Proc::Reduce_Outlines(
                &MA_tmp_G,
                &(vvMA_Proc_ImgStep[index_img][step_g]),
                8,
                1),
            "Image_ColorRGB_Info",
            "Green - Outlines");
    else
        ERR(D_Img_Proc::Duplicate(
                &MA_tmp_G,
                &(vvMA_Proc_ImgStep[index_img][step_g])),
            "Image_ColorRGB_Info",
            "Green - Duplicate");

    //BLUE
    if(ui->checkBox_ResImg_Edge_B->isChecked())
        ERR(D_Img_Proc::Reduce_Outlines(
                &MA_tmp_B,
                &(vvMA_Proc_ImgStep[index_img][step_b]),
                8,
                1),
            "Image_ColorRGB_Info",
            "Blue - Outlines");
    else
        ERR(D_Img_Proc::Duplicate(
                &MA_tmp_B,
                &(vvMA_Proc_ImgStep[index_img][step_b])),
            "Image_ColorRGB_Info",
            "Blue - Duplicate");

    //MERGE
    ERR(D_Img_Proc::Merge(
            &MA_tmp_Merge,
            &MA_tmp_B,
            &MA_tmp_G,
            &MA_tmp_R),
        "Image_ColorRGB_Info",
        "Merge");

    //Show
    View_Results.Update_Image(&MA_tmp_Merge);

    //free memory
    MA_tmp_R.release();
    MA_tmp_G.release();
    MA_tmp_B.release();
    MA_tmp_Merge.release();
}

void D_MAKRO_IonTracks::Update_Dimensions()
{
    Dim_Unit = ui->lineEdit_Dimension_Unit->text();

    Dim_XLat_Dim = ui->spinBox_Dimension_Dimension_X_Lateral->value();
    Dim_XLat_Step = ui->doubleSpinBox_Dimension_Step_X_Lateral->value();

    Dim_YLat_Dim = ui->spinBox_Dimension_Dimension_Y_Lateral->value();
    Dim_YLat_Step = ui->doubleSpinBox_Dimension_Step_Y_Lateral->value();

    Dim_ZDep_Dim = ui->spinBox_Dimension_Dimension_Z_Depth->value();
    Dim_ZDep_Step = ui->doubleSpinBox_Dimension_Step_Z_Depth->value();

    Dim_Lat_Dim = Dim_XLat_Dim * Dim_YLat_Dim;
    Dim_All = Dim_Lat_Dim * Dim_ZDep_Dim;

    QSL_Dim_Lat.clear();
    for(int x = 0; x < Dim_XLat_Dim; x++)
        for(int y = 0; y < Dim_YLat_Dim; y++)
            QSL_Dim_Lat.append("X" + QString::number(x) + "_Y" + QString::number(y));

    QSL_Dim_Dep.clear();
    for(int z = 0; z < Dim_ZDep_Dim; z++)
        QSL_Dim_Dep.append("Depth_" + QString::number(z * Dim_ZDep_Step) + Dim_Unit);

    ui->label_Dimension_Size_X_Lateral->setText(QString::number(Dim_XLat_Dim * Dim_XLat_Step) + Dim_Unit);
    ui->label_Dimension_Size_Y_Lateral->setText(QString::number(Dim_YLat_Dim * Dim_YLat_Step) + Dim_Unit);
    ui->label_Dimension_Size_Z_Depth->setText(QString::number(Dim_ZDep_Dim * Dim_ZDep_Step) + Dim_Unit);

    Populate_CB_Dimensions();
}

void D_MAKRO_IonTracks::Init_ImageVectors()
{
    qDebug() << "D_MAKRO_IonTracks" << "Init_ImageVectors" << "Planned size:" << Dim_All << "x" << c_STEP_NUMBER_OF;

    vvMA_Proc_ImgStep.clear();
    vvMA_Proc_ImgStep.resize(Dim_All);
    for(int img = 0; img < vvMA_Proc_ImgStep.size(); img++)
    {
        vvMA_Proc_ImgStep[img].clear();
        vvMA_Proc_ImgStep[img].resize(c_STEP_NUMBER_OF);
        for(int step = 0; step < vvMA_Proc_ImgStep[img].size(); step++)
            vvMA_Proc_ImgStep[img][step] = pStore->get_Adress(0)->clone();
    }

    //qDebug() << "D_MAKRO_IonTracks" << "Init_ImageVectors" << "Actual size:" << Dim_All << "x" << c_STEP_NUMBER_OF;
}

void D_MAKRO_IonTracks::Populate_CB_Single(QComboBox *CB, QStringList QSL)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->blockSignals(false);
}

void D_MAKRO_IonTracks::Populate_CB_All()
{
    Populate_CB_ProcSteps();
    Populate_CB_Stats();
    Populate_CB_AxeTrans();
    Populate_CB_PlotTypes();
    Populate_CB_TableTypes();
    Populate_CB_Groups();
    Populate_CB_ImageRGB_Info();
}

void D_MAKRO_IonTracks::Populate_CB_Stats()
{
    Populate_CB_Single(ui->comboBox_ResPlo_StatSingle,          QSL_StatList);
    Populate_CB_Single(ui->comboBox_ResPlo_SaR_StatTracks,      QSL_StatList);
    Populate_CB_Single(ui->comboBox_ResPlo_Grp_SaR_StatTracks,  QSL_StatList);
    Populate_CB_Single(ui->comboBox_ResTab_StatSingle,          QSL_StatList);

    ui->comboBox_ResPlo_StatSingle->blockSignals(true);
    ui->comboBox_ResPlo_StatSingle->setCurrentIndex(c_STAT_MEAN_ARITMETIC);
    ui->comboBox_ResPlo_StatSingle->blockSignals(false);

    ui->comboBox_ResPlo_Grp_SaR_StatTracks->blockSignals(true);
    ui->comboBox_ResPlo_Grp_SaR_StatTracks->setCurrentIndex(c_STAT_MEAN_ARITMETIC);
    ui->comboBox_ResPlo_Grp_SaR_StatTracks->blockSignals(false);

    ui->comboBox_ResPlo_SaR_StatTracks->blockSignals(true);
    ui->comboBox_ResPlo_SaR_StatTracks->setCurrentIndex(c_STAT_MEAN_ARITMETIC);
    ui->comboBox_ResPlo_SaR_StatTracks->blockSignals(false);

    ui->comboBox_ResTab_StatSingle->blockSignals(true);
    ui->comboBox_ResTab_StatSingle->setCurrentIndex(c_STAT_MEAN_ARITMETIC);
    ui->comboBox_ResTab_StatSingle->blockSignals(false);
}

void D_MAKRO_IonTracks::Populate_CB_AxeTrans()
{
    Populate_CB_Single(ui->comboBox_ResPlo_AxeTrans_X, QSL_AxeTrans_x);
    Populate_CB_Single(ui->comboBox_ResPlo_AxeTrans_Y, QSL_AxeTrans_y);
}

void D_MAKRO_IonTracks::Populate_CB_PlotTypes()
{
    Populate_CB_Single(ui->comboBox_ResPlo_Type, QSL_PlotTypes);
}

void D_MAKRO_IonTracks::Populate_CB_TableTypes()
{
    Populate_CB_Single(ui->comboBox_ResTab_Type, QSL_TableTypes);
}

void D_MAKRO_IonTracks::Populate_CB_Dimensions()
{
    Populate_CB_Single(ui->comboBox_ProcView_Depth, QSL_Dim_Dep);
    Populate_CB_Single(ui->comboBox_ProcView_Lateral, QSL_Dim_Lat);

    Populate_CB_Single(ui->comboBox_ResImg_Depth, QSL_Dim_Dep);
    Populate_CB_Single(ui->comboBox_ResImg_Lateral, QSL_Dim_Lat);

    Populate_CB_Single(ui->comboBox_ResTab_Depth, QSL_Dim_Dep);
    Populate_CB_Single(ui->comboBox_ResTab_Lateral, QSL_Dim_Lat);

    Populate_CB_Single(ui->comboBox_ResPlo_Depth, QSL_Dim_Dep);
    Populate_CB_Single(ui->comboBox_ResPlo_Lateral, QSL_Dim_Lat);
}

void D_MAKRO_IonTracks::Populate_CB_Groups()
{
    Populate_CB_Single(ui->comboBox_ResPlo_Group, QSL_GroupsResolution);
    Populate_CB_Single(ui->comboBox_ResTab_Group, QSL_GroupsResolution);
}

void D_MAKRO_IonTracks::Populate_CB_ProcSteps()
{
    //qDebug() << "D_MAKRO_IonTracks" << "Index_CurrentView";

    Populate_CB_Single(ui->comboBox_ProcView_ProcStep, QSL_ProcStepSingle);
}

void D_MAKRO_IonTracks::Populate_CB_ImageRGB_Info()
{
    Populate_CB_Single(ui->comboBox_ResImg_B, QSL_ImageInfoRGB);
    Populate_CB_Single(ui->comboBox_ResImg_G, QSL_ImageInfoRGB);

    ui->comboBox_ResImg_G->blockSignals(true);
    ui->comboBox_ResImg_G->setCurrentIndex(c_IMG_ROI);
    ui->comboBox_ResImg_G->blockSignals(false);

    ui->comboBox_ResImg_B->blockSignals(true);
    ui->comboBox_ResImg_B->setCurrentIndex(c_IMG_BINARY);
    ui->comboBox_ResImg_B->blockSignals(false);
}

void D_MAKRO_IonTracks::Load_DirectoriesList()
{
    QString QS_MasterDirectory = QFileDialog::getExistingDirectory(
                this,
                "Load master directory containing image directories",
                pStore->dir_M_IonTracks()->path());

    if(QS_MasterDirectory == 0)
        return;

    //get subdirs with img
    DIR_MasterDirectory.setPath(QS_MasterDirectory);
    qDebug() << "Master Dir:" << DIR_MasterDirectory.path();
    QSL_ImageDirectories_Names = DIR_MasterDirectory.entryList(QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot);
    Populate_CB_Single(ui->comboBox_CurAna_DataSet, QSL_ImageDirectories_Names);

    //get subdir path
    QSL_ImageDirectories.clear();
    for(int p = 0; p < QSL_ImageDirectories_Names.size(); p++)
        QSL_ImageDirectories.append(QS_MasterDirectory + "/" + QSL_ImageDirectories_Names[p]);


    if(QSL_ImageDirectories.empty())
        return;

    //save master dir and apply first load
    pStore->set_dir_M_IonTracks(QS_MasterDirectory);
    Update_Dimensions();
    Init_ImageVectors();
    Load_Directoty();
}

void D_MAKRO_IonTracks::Load_Directoty()
{
    //get current pathes and save it
    DIR_Input.setPath(QSL_ImageDirectories[ui->comboBox_CurAna_DataSet->currentIndex()]);
    qDebug() << "Current dir:" << DIR_Input.path();
    QS_CurrentSetName = DIR_Input.dirName();

    //search input elememnts for tif images
    FIL_InputCurrentSet.clear();
    QFileInfoList FIL_InputElements = DIR_Input.entryInfoList();
    for(int f = 0; f < FIL_InputElements.size(); f++)
        if(
                FIL_InputElements[f].absoluteFilePath().endsWith(".tif") ||
                FIL_InputElements[f].absoluteFilePath().endsWith(".tiff") ||
                FIL_InputElements[f].absoluteFilePath().endsWith(".TIF") ||
                FIL_InputElements[f].absoluteFilePath().endsWith(".TIFF"))
            FIL_InputCurrentSet.append(FIL_InputElements[f]);

    //check if dimensions fit
    if(FIL_InputCurrentSet.size() != Dim_All)
    {
        ERR(
                    ER_size_missmatch,
                    "Load_Directoty",
                    "Dimension " + QString::number(Dim_XLat_Dim) + "x" + QString::number(Dim_YLat_Dim) + "x" + QString::number(Dim_ZDep_Dim) + "=" + QString::number(Dim_All) + " expected, "
                    "dimension " + QString::number(FIL_InputCurrentSet.size()) + " found.");
        return;
    }

    //update ui
    ui->groupBox_CurAna->setEnabled(true);
    ui->groupBox_ProcSet->setEnabled(true);
    ui->groupBox_ProcView->setEnabled(true);
    ui->tabWidget_Results->setEnabled(true);
    ui->groupBox_Dimension->setEnabled(false);

    //Update
    ui->action_Block_Processing_Update->setChecked(false);
    Update_ImgProc();
}

void D_MAKRO_IonTracks::Save_Analysis()
{
    QString QS_SavePath = QFileDialog::getExistingDirectory(
                this,
                tr("Save Analysis"),
                DIR_Input.path());
    if(QS_SavePath == 0)
        return;

    bool ok;
    int radius_start = QInputDialog::getInt(
                this,
                "Analysis Parameters",
                "Please enter radius to start with:<br>",
                15,
                1,
                2147483647,
                1,
                &ok);
    if(!ok)
        return;

    int radius_end = QInputDialog::getInt(
                this,
                "Analysis Parameters",
                "Please enter radius to end with:<br>",
                25,
                radius_start + 1,
                2147483647,
                1,
                &ok);
    if(!ok)
        return;

    int radius_step = QInputDialog::getInt(
                this,
                "Analysis Parameters",
                "Please enter radius steps:<br>",
                1,
                1,
                radius_end - radius_start,
                1,
                &ok);
    if(!ok)
        return;

    QString QS_AnalysisInfo = "Radii<br>";
    int radius_counter = 0;
    for(int r = radius_start; r <= radius_end; r += radius_step)
    {
        if(r != radius_start)
            QS_AnalysisInfo.append(", ");
        QS_AnalysisInfo.append("<b>" + QString::number(r) + "</b>");
        radius_counter++;
    }
    QS_AnalysisInfo.append("<br>will be analyzed for data sets");
    for(int s = 0; s < QSL_ImageDirectories_Names.size(); s++)
    {
        QS_AnalysisInfo.append("<br><b>" + QSL_ImageDirectories_Names[s] + "</b>");
        radius_counter++;
    }
    QS_AnalysisInfo.append("<br> and saved in<br>");
    QS_AnalysisInfo.append("<I>" + QS_SavePath + "/Results_" + DIR_MasterDirectory.dirName() + "</I><br>");
    QS_AnalysisInfo.append("<br>" + QString::number(c_STEP_NUMBER_OF * Dim_All * radius_counter * QSL_ImageDirectories_Names.size()) + " Image processing steps will be performed.");

    if(QMessageBox::question(
                this,
                "Analyze now?",
                QS_AnalysisInfo,
                QMessageBox::Ok,
                QMessageBox::Cancel)
            == QMessageBox::Cancel)
        return;

    //SAVE ANALYSIS

    //Make ui non responsive
    ui->action_Block_Processing_Update->setChecked(false);
    this->setEnabled(false);

    //timer
    QElapsedTimer timer;
    timer.start();

    //Save Dir Master
    DIR_SaveAnalysis_Master.setPath(QS_SavePath + "/" + "Results_" + DIR_MasterDirectory.dirName());
    if(!DIR_SaveAnalysis_Master.exists())
        QDir().mkdir(DIR_SaveAnalysis_Master.path());


    //loop data sets
    for(int set = 0; set < QSL_ImageDirectories.size(); set++)
    {
        ui->comboBox_CurAna_DataSet->setCurrentIndex(set);

        //Save Dir Current
        DIR_SaveAnalysis_Current.setPath(DIR_SaveAnalysis_Master.path() + "/" + QS_CurrentSetName);
        if(!DIR_SaveAnalysis_Current.exists())
            QDir().mkdir(DIR_SaveAnalysis_Current.path());



        //Loop radii
        for(int r = radius_start; r <= radius_end; r += radius_step)
        {
            QDir DIR_SaveRadius(DIR_SaveAnalysis_Current.path() + "/radius_" + QString::number(r));
            QDir().mkdir(DIR_SaveRadius.path());

            ui->spinBox_ProcSet_SafetyDist_MinRadius->setValue(r);

            //Parameters
            ui->groupBox_ProcSet->grab().save(DIR_SaveRadius.path() + "/Settings.jpg", 0, -1);

            //Images

            QDir DIR_SaveImages(DIR_SaveRadius.path() + "/Images");
            QDir().mkdir(DIR_SaveImages.path());

            ui->tabWidget_Results->setCurrentIndex(c_RES_IMG);
            ui->comboBox_ResImg_B->setCurrentIndex(c_IMG_BINARY);
            ui->comboBox_ResImg_G->setCurrentIndex(c_IMG_ROI);
            ui->checkBox_ResImg_Edge_B->setChecked(true);
            ui->checkBox_ResImg_Edge_G->setChecked(true);
            for(int l = 0; l < Dim_Lat_Dim; l++)
            {
                ui->comboBox_ResImg_Lateral->setCurrentIndex(l);
                for(int d = 0; d < Dim_ZDep_Dim; d++)
                {
                    ui->comboBox_ResImg_Depth->setCurrentIndex(d);
                    View_Results.Save_Image(DIR_SaveImages.path() + "/" + ui->comboBox_ResImg_Lateral->currentText() + " - " + ui->comboBox_ResImg_Depth->currentText() + ".jpg");
                }
            }

            //Tables

            ui->comboBox_ResTab_Group->setCurrentIndex(c_GRP_ALL);

            QDir DIR_SaveTable(DIR_SaveRadius.path() + "/Tables");
            QDir().mkdir(DIR_SaveTable.path());

            ui->tabWidget_Results->setCurrentIndex(c_RES_TABLE);

            ui->comboBox_ResTab_Type->setCurrentIndex(c_TAB_RAW);
            Table_Tracks.Save_Table(DIR_SaveTable.path() + "/SingleTracks - (of " + ui->comboBox_ResTab_StatSingle->currentText() + ").csv");

            ui->comboBox_ResTab_Type->setCurrentIndex(c_TAB_STAT);
            Table_Tracks.Save_Table(DIR_SaveTable.path() + "/StatsOfTracks - (of " + ui->comboBox_ResTab_StatSingle->currentText() + ").csv");

            //Plots

            ui->comboBox_ResPlo_Group->setCurrentIndex(c_GRP_ALL);

            QDir DIR_SavePlot(DIR_SaveRadius.path() + "/Plots");
            QDir().mkdir(DIR_SavePlot.path());

            this->showMaximized();
            ui->tabWidget_Results->setCurrentIndex(c_RES_PLOT);

            for(int axe_mode = 0; axe_mode < 2; axe_mode++)
            {
                QString QS_AxeMode = "";
                switch (axe_mode) {

                case 0:
                    ui->comboBox_ResPlo_AxeTrans_X->setCurrentIndex(c_AXE_TRANS_LIN);
                    ui->comboBox_ResPlo_AxeTrans_Y->setCurrentIndex(c_AXE_TRANS_LIN);
                    QS_AxeMode = "linear";
                    break;

                case 1:
                    ui->comboBox_ResPlo_AxeTrans_X->setCurrentIndex(c_AXE_TRANS_LOG_10);
                    ui->comboBox_ResPlo_AxeTrans_Y->setCurrentIndex(c_AXE_TRANS_LOG_10);
                    QS_AxeMode = "double_log_10";
                    break;

                case 2:
                    ui->comboBox_ResPlo_AxeTrans_X->setCurrentIndex(c_AXE_TRANS_LIN);
                    ui->comboBox_ResPlo_AxeTrans_Y->setCurrentIndex(c_AXE_TRANS_1pXX);
                    QS_AxeMode = "1pRR";
                    break;

                default:
                    break;
                }

                ui->comboBox_ResPlo_Type->setCurrentIndex(c_PLO_STAT_AT_RADIUS);
                Save_Plot(DIR_SavePlot.path() + "/" + ui->comboBox_ResPlo_SaR_StatTracks->currentText() + " - (of " + ui->comboBox_ResTab_StatSingle->currentText() + ") - " + QS_AxeMode + ".jpg");

                ui->comboBox_ResPlo_Type->setCurrentIndex(c_PLO_MEAN_SD);
                Save_Plot(DIR_SavePlot.path() + "/Mean_SD - (of " + ui->comboBox_ResTab_StatSingle->currentText() + ") - " + QS_AxeMode + ".jpg");

                ui->comboBox_ResPlo_Type->setCurrentIndex(c_PLO_MEDIAN_ADM);
                Save_Plot(DIR_SavePlot.path() + "/Median_ADM - (of " + ui->comboBox_ResTab_StatSingle->currentText() + ") - " + QS_AxeMode + ".jpg");

                ui->comboBox_ResPlo_Type->setCurrentIndex(c_PLO_QUANTILES);
                Save_Plot(DIR_SavePlot.path() + "/Quantiles_20Prz - (of " + ui->comboBox_ResTab_StatSingle->currentText() + ") - " + QS_AxeMode + ".jpg");
            }
        }
    }



    QMessageBox::information(
                this,
                "Analysis finished",
                "Analysis and saving of " + QString::number(radius_counter) + " radii in " + QSL_ImageDirectories_Names.size() + " data sets took " + QString::number(timer.elapsed() / 60000.0) + " minutes.<br>"
                "(" + QString::number(timer.elapsed() / (1000.0 * radius_counter * QSL_ImageDirectories_Names.size())) + " seconds per radius and data set)");

    //Make ui responsive again
    this->setEnabled(true);
}

void D_MAKRO_IonTracks::Save_Table()
{
    Table_Tracks.Save_Table_Dialog(DIR_Input.path());
}

void D_MAKRO_IonTracks::Save_Plot()
{
    QString QS_SavePath = QFileDialog::getSaveFileName(
                this,
                "Save Plot as Image",
                DIR_Input.path(),
                tr("Images (*.png *.jpg *.bmp *.tif)"));
    if(QS_SavePath == 0)
        return;

    Save_Plot(QS_SavePath);
}

void D_MAKRO_IonTracks::Save_Plot(QString path)
{
    QPixmap pixmap_save = pChartView_Plot->grab();
    pixmap_save.save(path, 0, -1);
}

int D_MAKRO_IonTracks::Index_CurrentView()
{
    if(QSL_Dim_Dep.empty() || QSL_Dim_Lat.empty())
    {
        qDebug() << "D_MAKRO_IonTracks" << "Index_CurrentView" << "BAD CALL";
        return 0;
    }
    else
    {
        //qDebug() << "D_MAKRO_IonTracks" << "Index_CurrentView";
        return ui->comboBox_ProcView_Depth->currentIndex() + ui->comboBox_ProcView_Lateral->currentIndex() * Dim_ZDep_Dim;
    }
}

void D_MAKRO_IonTracks::Update_Max_Radius()
{
    max_radius = static_cast<int>((ui->doubleSpinBox_ProcSet_TOI_RelRadius->value() / 100.0) * ui->spinBox_ProcSet_SafetyDist_MinRadius->value());
    //qDebug() << "Max Radius: " << max_radius;

    QSL_Radius.clear();
    for(int r = 0; r <= max_radius; r++)
        QSL_Radius.append("r=" + QString::number(r));
}

void D_MAKRO_IonTracks::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_MAKRO_IonTracks", func, detail);
}

void D_MAKRO_IonTracks::on_spinBox_ProcSet_Blur_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Proc(c_STEP_BLUR);
}

void D_MAKRO_IonTracks::on_doubleSpinBox_ProcSet_Blur_Sigma_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Proc(c_STEP_BLUR);
}

void D_MAKRO_IonTracks::on_doubleSpinBox_ProcSet_Binarization_Thres_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Proc(c_STEP_BIN);
}

void D_MAKRO_IonTracks::on_doubleSpinBox_ProcSet_ExLarge_MaxArea_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Proc(c_STEP_EX_LARGE);
}

void D_MAKRO_IonTracks::on_doubleSpinBox_ProcSet_ExAsphere_MinSphere_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Proc(c_STEP_EX_ASPHERES);
}

void D_MAKRO_IonTracks::on_spinBox_ProcSet_SafetyDist_MinRadius_valueChanged(int arg1)
{
    arg1;
    Update_Max_Radius();
    Update_ImgProc_Proc(c_STEP_SAFETY_DIST);
}

void D_MAKRO_IonTracks::on_doubleSpinBox_ProcSet_ExConn_MinSphere_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Proc(c_STEP_EX_CONNECTED);
}

void D_MAKRO_IonTracks::on_doubleSpinBox_ProcSet_TOI_RelRadius_valueChanged(double arg1)
{
    arg1;
    Update_Max_Radius();
    Update_ImgProc_Proc(c_STEP_TOI_AREA);
}

void D_MAKRO_IonTracks::on_comboBox_ResTab_Group_currentIndexChanged(int index)
{
    switch (index) {

    case c_GRP_ALL:
        ui->comboBox_ResTab_Lateral->setEnabled(false);
        ui->comboBox_ResTab_Depth->setEnabled(false);
        break;

    case c_GRP_LATERAL:
        ui->comboBox_ResTab_Lateral->setEnabled(true);
        ui->comboBox_ResTab_Depth->setEnabled(false);
        break;

    case c_GRP_DEPTH:
        ui->comboBox_ResTab_Lateral->setEnabled(false);
        ui->comboBox_ResTab_Depth->setEnabled(true);
        break;

    default:
        break;
    }
}

void D_MAKRO_IonTracks::on_comboBox_ResPlo_Group_currentIndexChanged(int index)
{
    switch (index) {

    case c_GRP_ALL:
        ui->comboBox_ResPlo_Lateral->setEnabled(false);
        ui->comboBox_ResPlo_Depth->setEnabled(false);
        break;

    case c_GRP_LATERAL:
        ui->comboBox_ResPlo_Lateral->setEnabled(true);
        ui->comboBox_ResPlo_Depth->setEnabled(false);
        break;

    case c_GRP_DEPTH:
        ui->comboBox_ResPlo_Lateral->setEnabled(false);
        ui->comboBox_ResPlo_Depth->setEnabled(true);
        break;

    default:
        break;
    }
}
