/************************************
 *   added:     20.01.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_makro_manuelsegmentation.h"
#include "ui_d_makro_manuelsegmentation.h"

D_MAKRO_ManuelSegmentation::D_MAKRO_ManuelSegmentation(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_ManuelSegmentation)
{
    //ui
    ui->setupUi(this);

    //Storeage
    pStore = pStorage;

    //Viewer
    View_Draw.set_GV(ui->graphicsView_Draw);
    View_Segments.set_GV(ui->graphicsView_Res_Gra_Seg);

    //Tables
    Table_Current_Feats.set_TW(ui->tableWidget_Res_Current_Feats);
    Table_Current_Stats.set_TW(ui->tableWidget_Res_Current_Stats);
    Table_All_Feats.set_TW(ui->tableWidget_Res_All_Feats);
    Table_All_Stats.set_TW(ui->tableWidget_Res_All_Stats);

    //Images
    vMA_ProcSteps.resize(STEP_NUMBER_OF);
    for(size_t s = 0; s < STEP_NUMBER_OF; s++)
        vMA_ProcSteps[s] = pStore->get_Adress(0)->clone();
    VD_LoadAny = pStore->get_VD(0);
    VD_LoadAny_8bit = pStore->get_VD(0);

    //feats and stats
    QSL_FeatsMaster.append(QS_AreaScaled);
    for(size_t i = 0; i < v_FeatsOfInterest.size(); i++)
        QSL_FeatsOfInterest.append(QSL_FeatsMaster[v_FeatsOfInterest[i]]);
    for(size_t i = 0; i < v_StatsOfInterest.size(); i++)
        QSL_StatsOfInterest.append(QSL_StatList[v_StatsOfInterest[i]]);



    //statusbar
    pL_SB_DrawInfo_Selected = new QLabel(this);
    pL_SB_DrawInfo_Selected->setToolTip("Currently selected drawing mode");
    ui->statusbar->addPermanentWidget(pL_SB_DrawInfo_Selected);
    pL_SB_DrawInfo_HowTo = new QLabel(this);
    pL_SB_DrawInfo_HowTo->setText("      Leftclick: Draw / Rightclick: Draw new object");
    pL_SB_DrawInfo_HowTo->setToolTip("How to Draw. Trust me, it is very simple ;-)");
    ui->statusbar->addPermanentWidget(pL_SB_DrawInfo_HowTo);

    //Populate
    Populate_CB_Start();
    ShowList(ui->plainTextEdit_Feats, QSL_FeatsMaster, &v_FeatsOfInterest);
    ShowList(ui->plainTextEdit_Stats, QSL_StatList, &v_StatsOfInterest);

    //Connects
    connect(ui->pushButton_Results_SaveAnalysis,    SIGNAL(clicked(bool)),                      this,                   SLOT(Save_Analysis()));
    connect(ui->pushButton_Select_Feats,            SIGNAL(clicked(bool)),                      this,                   SLOT(Edit_FeatsOfInterest()));
    connect(ui->pushButton_Select_Stats,            SIGNAL(clicked(bool)),                      this,                   SLOT(Edit_StatsOfInterest()));
    connect(ui->pushButton_Data_Load,               SIGNAL(clicked(bool)),                      this,                   SLOT(Data_Load()));
    connect(ui->pushButton_Data_Clear,              SIGNAL(clicked(bool)),                      this,                   SLOT(Data_Clear()));
    connect(ui->pushButton_Data_Next,               SIGNAL(clicked(bool)),                      this,                   SLOT(Data_Next()));
    connect(ui->pushButton_Data_Previous,           SIGNAL(clicked(bool)),                      this,                   SLOT(Data_Previous()));
    connect(ui->pushButton_DrawTool_Line_FG,        SIGNAL(clicked(bool)),                      this,                   SLOT(Draw_Set_Tool_LineForeground()));
    connect(ui->pushButton_DrawTool_Line_BG,        SIGNAL(clicked(bool)),                      this,                   SLOT(Draw_Set_Tool_LineBackground()));
    connect(ui->pushButton_DrawTool_Floodfill,      SIGNAL(clicked(bool)),                      this,                   SLOT(Draw_Set_Tool_FillFlood()));
    connect(ui->pushButton_Draw_FillHoles,          SIGNAL(clicked(bool)),                      this,                   SLOT(Draw_FillHoles()));
    connect(ui->pushButton_Draw_Undo,               SIGNAL(clicked(bool)),                      this,                   SLOT(Draw_Undo()));
    connect(ui->pushButton_Draw_Clear,              SIGNAL(clicked(bool)),                      this,                   SLOT(Draw_Reset()));
    connect(ui->pushButton_Overlay_Color,           SIGNAL(clicked(bool)),                      this,                   SLOT(Overlay_Set_Color()));
    connect(ui->comboBox_Data,                      SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_ImgProc_All()));
    connect(ui->comboBox_StepsDraw,                 SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Image_Draw()));
    connect(ui->comboBox_Results,                   SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(&View_Draw,                             SIGNAL(MouseClickedLeft_Pos(int,int)),      this,                   SLOT(Draw_RecieveClickLeft(int,int)));
    connect(&View_Draw,                             SIGNAL(MouseClickedRight_Pos(int,int)),     this,                   SLOT(Draw_RecieveClickRight(int,int)));

    //Draw info
    Draw_vPoints.resize(Draw_ClickMemoryCount, Point(0, 0));

    //on start
    this->showMaximized();
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    setWindowTitle("ImageD - Manual Segmentation");
    Update_Images();
    Update_SB_DrawInfo();

    //Overlay Button color
    QPalette pal = ui->pushButton_Overlay_Color->palette();
    pal.setColor(QPalette::Button, Draw_OverlayColor);
    ui->pushButton_Overlay_Color->setAutoFillBackground(true);
    ui->pushButton_Overlay_Color->setPalette(pal);
    ui->pushButton_Overlay_Color->update();

    //Load stuff on startup
    Data_Load();
}

D_MAKRO_ManuelSegmentation::~D_MAKRO_ManuelSegmentation()
{
    delete ui;
}

void D_MAKRO_ManuelSegmentation::closeEvent(QCloseEvent *event)
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

void D_MAKRO_ManuelSegmentation::resizeEvent(QResizeEvent *event)
{
    event->accept();
    Update_Views();
}

void D_MAKRO_ManuelSegmentation::Data_Load()
{
    //Clear old content
    Data_Clear();

    //get filepath
    QStringList QSl_Paths = QFileDialog::getOpenFileNames(
                this,
                "Load Images",
                pStore->dir_M_ManualSegmentation()->path(),
                "Image Files (*.png *.jpg *.bmp *.tif *.tiff *.asc)");
    if(QSl_Paths.empty())
        return;

    //set default dir
    pStore->set_dir_M_ManualSegmentation(QSl_Paths.first());

    //number of loaded images
    int img_count_old = FIL_Images.size();

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
        FIL_DrawFiles.append(FI_Img.absoluteDir().path() + "/ImageD_ManualSegmentation/" + QS_Name + "_Draw.tif");
        FIL_Param.append(FI_Img.absoluteDir().path() + "/ImageD_ManualSegmentation/" + QS_Name + "_Parameters.txt");

        //make sure dir exists
        QString QS_SubDir_Path = FIL_DrawFiles.last().path();
        if(!QDir(QS_SubDir_Path).exists())
            QDir().mkdir(QS_SubDir_Path);
    }

    //image names to ui
    int index_old_max = img_count_old - 1;
    if(index_old_max < 0)
        index_old_max = 0;
    Populate_CB_Single(ui->comboBox_Data, QSL_Images_Names, index_old_max);

    state_Images_Loaded = true;

    Data_CalcContainers_Init();
    Update_ImgProc_All();
}

void D_MAKRO_ManuelSegmentation::Data_Clear()
{
    state_Images_Loaded = false;
    state_LoadMode_Pages_Calibrated = false;
    state_CalcContainers_CorrectSize = false;
    state_Current_ImgProc_Done = false;
    state_All_Calc_Done = false;
    state_Selections_Calc = false;
    state_Current_Calc_Done = false;

    QSL_Images_Names.clear();
    QSL_Images_Paths.clear();
    QSL_Images_Suffix.clear();

    FIL_Images.clear();
    FIL_DrawFiles.clear();
    FIL_Param.clear();

    vv_FeatComp_Current.clear();
    vv_FeatStat_Current.clear();
    vvv_ImgFeatComp_All.clear();
    vvv_ImgFeatStat_All.clear();
    vv_FeatComp_All.clear();
    vv_FeatStat_All.clear();

    View_Draw.Update_Image(pStore->get_Adress(0));
    View_Segments.Update_Image(pStore->get_Adress(0));
}

void D_MAKRO_ManuelSegmentation::Data_Next()
{
    if(!state_Images_Loaded)
        return;

    int cur = ui->comboBox_Data->currentIndex();
    if(cur < FIL_Images.size() - 2)
        ui->comboBox_Data->setCurrentIndex(cur + 1);
}

void D_MAKRO_ManuelSegmentation::Data_Previous()
{
    if(!state_Images_Loaded)
        return;

    int cur = ui->comboBox_Data->currentIndex();
    if(cur > 0)
        ui->comboBox_Data->setCurrentIndex(cur - 1);
}

void D_MAKRO_ManuelSegmentation::Data_CalcContainers_Init()
{
    //current and stack pooled
    vv_FeatComp_Current.resize(FEAT_CUSTOM_NUMBER_OF);
    vv_FeatStat_Current.resize(FEAT_CUSTOM_NUMBER_OF);
    vv_FeatComp_All.resize(FEAT_CUSTOM_NUMBER_OF);
    vv_FeatStat_All.resize(FEAT_CUSTOM_NUMBER_OF);
    for(size_t feat = 0; feat < FEAT_CUSTOM_NUMBER_OF; feat++)
    {
        vv_FeatStat_Current[feat].resize(vv_FeatStat_Current.size(), 0);
        vv_FeatStat_All[feat].resize(vv_FeatStat_Current.size(), 0);
    }

    //stack singles
    size_t img_count = static_cast<size_t>(FIL_Images.size());
    Scale_vFactor.resize(img_count, ScaleInit_Factor);
    Scale_vCalib_Px.resize(img_count, ScaleInit_Calib_Px);
    Scale_vCalib_CustomUnit.resize(img_count, ScaleInit_Calib_CustomUnit);
    v_ImgAnalysed.resize(img_count, 0);
    vvv_ImgFeatComp_All.resize(img_count);
    vvv_ImgFeatStat_All.resize(img_count);
    for(size_t img = 0; img < img_count; img++)
    {
        vvv_ImgFeatComp_All[img].resize(FEAT_CUSTOM_NUMBER_OF);
        vvv_ImgFeatStat_All[img].resize(FEAT_CUSTOM_NUMBER_OF);
        for(size_t feat = 0; feat < FEAT_CUSTOM_NUMBER_OF; feat++)
            vvv_ImgFeatStat_All[img][feat].resize(c_STAT_NUMBER_OF_STATS, 0);
    }

    state_CalcContainers_CorrectSize = true;
}

void D_MAKRO_ManuelSegmentation::LoadMode_Calib()
{
    //existing pages in currently loaded
    int page_count = VD_LoadAny_8bit.pDim()->size_P();

    //list of page names
    QStringList QSL_PageNames;
    vLoadMode_PagesOfInterest_Indices.clear();
    for(int p = 0; p < page_count; p++)
    {
        QSL_PageNames.append("Page_" + QString::number(p));
        vLoadMode_PagesOfInterest_Indices.push_back(p);
    }

    //edit selection
    D_Popup_ListEdit pop("Select pages to show in pseduo color", &vLoadMode_PagesOfInterest_Indices, QSL_PageNames, 0, this);
    pop.exec();

    //pages of interest count
    size_t page_count_interest = vLoadMode_PagesOfInterest_Indices.size();
    vLoadMode_Colors.resize(page_count_interest);
    vLoadMode_Colors_R.resize(page_count_interest);
    vLoadMode_Colors_G.resize(page_count_interest);
    vLoadMode_Colors_B.resize(page_count_interest);
    vLoadMode_Colors_A.resize(page_count_interest);
    vLoadMode_PagesOfInterest.resize(page_count_interest);

    //open color dialogues
    for(size_t pi = 0; pi < page_count_interest; pi++)
    {
        //init color
        QColor Col_Init;
        switch (pi) {
        case 0:     Col_Init = Qt::red;     break;
        case 1:     Col_Init = Qt::green;   break;
        case 2:     Col_Init = Qt::blue;    break;
        case 3:     Col_Init = Qt::yellow;  break;
        case 4:     Col_Init = Qt::cyan;    break;
        case 5:     Col_Init = Qt::magenta; break;
        default:    Col_Init = Qt::gray;    break;}

        //select color
        vLoadMode_Colors[pi] = QColorDialog::getColor(
                    Col_Init,
                    this,
                    "Please select color of page " + QString::number(vLoadMode_PagesOfInterest_Indices[pi]) + " (original) / " + QString::number(pi) + " (selected)");

        //get values from color
        vLoadMode_Colors_R[pi] = vLoadMode_Colors[pi].red();
        vLoadMode_Colors_G[pi] = vLoadMode_Colors[pi].green();
        vLoadMode_Colors_B[pi] = vLoadMode_Colors[pi].blue();
        vLoadMode_Colors_A[pi] = vLoadMode_Colors[pi].alpha();
    }

    state_LoadMode_Pages_Calibrated = true;
}

void D_MAKRO_ManuelSegmentation::Save_Analysis()
{
    if(!state_All_Calc_Done)
        return;

    //get path and create dir
    QString QS_SavePath = QFileDialog::getExistingDirectory(
                this,
                "Please select Directory to save analysis in",
                pStore->dir_M_ManualSegmentation()->path());

    if(QS_SavePath.isNull())
        return;

    DIR_SaveMaster.setPath(QS_SavePath + "/Results_0");
    int count = 0;
    while(DIR_SaveMaster.exists())
    {
        count++;
        DIR_SaveMaster.setPath(QS_SavePath + "/Results_" + QString::number(count));
    }
    QDir().mkdir(DIR_SaveMaster.path());

    //create subdirs
    QDir DIR_SaveSingle(DIR_SaveMaster.path() + "/Single");
    QDir DIR_SaveStack(DIR_SaveMaster.path() + "/Stack");
    QDir().mkdir(DIR_SaveSingle.path());
    QDir().mkdir(DIR_SaveStack.path());

    //loop images and save single analysis
    for(int img = 0; img < FIL_Images.size(); img++)
    {
        //select current img and trigger calc
        ui->comboBox_Data->setCurrentIndex(img);
        Update_Ui();

        //save screenshot
        this->grab().save(DIR_SaveSingle.path() + "/Screenshot_Parameters_" + QSL_Images_Names[img] + ".png");

        //Save Image (in stack summary too)
        ui->comboBox_Results->setCurrentIndex(RES_GRAPHIC_SEG);
        Update_Ui();
        View_Segments.Save_Image(DIR_SaveSingle.path() + "/Image_Segmentation_" + QSL_Images_Names[img] + ".png");

        //Save tables
        ui->comboBox_Results->setCurrentIndex(RES_TAB_CUR_FEAT);
        Update_Ui();
        Table_Current_Feats.Save_Table(DIR_SaveSingle.path() + "/Table_FeaturesOfComponents_" + QSL_Images_Names[img] + ".csv");
        ui->comboBox_Results->setCurrentIndex(RES_TAB_CUR_STAT);
        Update_Ui();
        Table_Current_Stats.Save_Table(DIR_SaveSingle.path() + "/Table_StatisticsOfFeatures_" + QSL_Images_Names[img] + ".csv");
    }

    //save stack summary
    ui->comboBox_Results->setCurrentIndex(RES_TAB_ALL_FEAT);
    Update_Ui();
    Table_All_Feats.Save_Table(DIR_SaveStack.path() + "/Table_Stack_FeaturesOfComponents.csv");
    ui->comboBox_Results->setCurrentIndex(RES_TAB_ALL_STAT);
    Update_Ui();
    Table_All_Stats.Save_Table(DIR_SaveStack.path() + "/Table_Stack_StatisticsOfFeatures.csv");
}

void D_MAKRO_ManuelSegmentation::Update_Ui()
{
    bool en_in = this->isEnabled();
    if(en_in)
        this->setEnabled(false);

    this->repaint();
    qApp->processEvents();

    if(en_in)
        this->setEnabled(true);
}

void D_MAKRO_ManuelSegmentation::Update_Views()
{
    View_Draw.Update_View();
    View_Segments.Update_View();
}

void D_MAKRO_ManuelSegmentation::Update_Images()
{
    Update_Image_Draw();
    Update_Image_Seg();
}

void D_MAKRO_ManuelSegmentation::Update_Image_Draw()
{
    View_Draw.Update_Image(&(vMA_ProcSteps[static_cast<size_t>(ui->comboBox_StepsDraw->currentIndex())]));
}

void D_MAKRO_ManuelSegmentation::Update_Image_Seg()
{
    View_Segments.Update_Image(&(vMA_ProcSteps[STEP_SEGMENTATION_NUMBERS]));
}

void D_MAKRO_ManuelSegmentation::Update_SB_DrawInfo()
{
    pL_SB_DrawInfo_Selected->setText("Draw " + QSL_DrawTool[Draw_ActiveTool] + "     ");
}

void D_MAKRO_ManuelSegmentation::Update_ImgProc_All()
{
    Update_ImgProc(0);
}

void D_MAKRO_ManuelSegmentation::Update_ImgProc(int step_start)
{
    if(!state_Images_Loaded)
        return;

    for(int s = step_start; s < STEP_NUMBER_OF; s++)
        Update_ImgProc_Step(s);

    Update_Images();
}

void D_MAKRO_ManuelSegmentation::Update_ImgProc_Step(int step)
{
    if(!state_Images_Loaded)
        return;

    //current img
    int img = ui->comboBox_Data->currentIndex();

    //states
    state_Current_ImgProc_Done = false;
    state_All_Calc_Done = false;
    state_Current_Calc_Done = false;
    state_Selections_Calc = false;
    v_ImgAnalysed[static_cast<size_t>(img)] = 0;

    switch (step) {

    case STEP_LOAD:
    {
        ERR(D_VisDat_Proc::Create_VD_SinglePaged(
                &VD_LoadAny,
                FIL_Images[img],
                c_DIM_P,
                c_DIM_X,
                c_DIM_Y),
            "Update_ImgProc_Step",
            "STEP_LOAD - D_VisDat_Proc::Create_VD_SinglePaged");

        if(VD_LoadAny.pMA_full()->depth() == CV_8U)
            ERR(D_VisDat_Proc::Copy(
                    &VD_LoadAny_8bit,
                    &VD_LoadAny),
                "Update_ImgProc_Step",
                "STEP_LOAD - D_VisDat_Proc::Copy");
        else
            ERR(D_VisDat_Proc::Normalize(
                    &VD_LoadAny_8bit,
                    &VD_LoadAny,
                    CV_MINMAX,
                    CV_8U,
                    0,
                    255),
                "Update_ImgProc_Step",
                "STEP_LOAD - D_VisDat_Proc::Normalize");

        ERR(D_VisDat_Proc::Read_2D_Plane(
                &(vMA_ProcSteps[STEP_LOAD]),
                &VD_LoadAny_8bit,
                D_VisDat_Slice_2D(-1, -1, 0, 0, 0, 0)), //XY, first page, all colors
            "Update_ImgProc_Step",
            "STEP_LOAD - D_VisDat_Proc::Read_2D_Plane");

        //forget all clicks on old images
        Draw_RememberedClicks = 0;
    }
        break;

    case STEP_CONVERT_COLOR:
    {


        //determin input type
        if(VD_LoadAny_8bit.pDim()->size_P() > 1)
        {
            if(VD_LoadAny_8bit.pMA_full()->channels() > 1)
                LoadMode_Current = LOAD_PAGES_COLOR;
            else
                LoadMode_Current = LOAD_PAGES_GRAY;
        }
        else
        {
            if(VD_LoadAny_8bit.pMA_full()->channels() > 1)
                LoadMode_Current = LOAD_COLOR;
            else
                LoadMode_Current = LOAD_GRAY;
        }



        //select how to convert to color
        switch (LoadMode_Current) {

        case LOAD_COLOR:
            ERR(D_Img_Proc::Duplicate(
                    &(vMA_ProcSteps[STEP_CONVERT_COLOR]),
                    &(vMA_ProcSteps[STEP_LOAD])),
                "Update_ImgProc_Step",
                "STEP_CONVERT_COLOR - LOAD_COLOR - D_Img_Proc::Duplicate");
            break;

        case LOAD_GRAY:
            ERR(D_Img_Proc::Convert_Color(
                    &(vMA_ProcSteps[STEP_CONVERT_COLOR]),
                    &(vMA_ProcSteps[STEP_LOAD]),
                    CV_GRAY2BGR),
                "Update_ImgProc_Step",
                "STEP_CONVERT_COLOR - LOAD_GRAY - D_Img_Proc::Convert_Color");
            break;

        case LOAD_PAGES_GRAY:
        {
            //Calibrate Mode
            if(!state_LoadMode_Pages_Calibrated)
                LoadMode_Calib();
            if(!state_LoadMode_Pages_Calibrated)
                return;

            //Get Pages of interest
            for(size_t p = 0; p < vLoadMode_PagesOfInterest_Indices.size(); p++)
                ERR(D_VisDat_Proc::Read_2D_Plane(
                        &(vLoadMode_PagesOfInterest[p]),
                        &VD_LoadAny_8bit,
                        D_VisDat_Slice_2D(-1, -1, 0, 0, 0, vLoadMode_PagesOfInterest_Indices[p])), //XY, page of interest, all colors
                    "Update_ImgProc_Step",
                    "STEP_CONVERT_COLOR - D_VisDat_Proc::Read_2D_Plane - Page: " + QString::number(vLoadMode_PagesOfInterest_Indices[p]));

            //Merge pages of interest to color image
            ERR(D_Img_Proc::Merge(
                    &(vMA_ProcSteps[STEP_CONVERT_COLOR]),
                    vLoadMode_PagesOfInterest,
                    vLoadMode_Colors_R,
                    vLoadMode_Colors_G,
                    vLoadMode_Colors_B,
                    vLoadMode_Colors_A),
                "Update_ImgProc_Step",
                "STEP_CONVERT_COLOR - LOAD_PAGES_GRAY - D_Img_Proc::Merge"
                "<br>Counts Img/R/G/B/A: " +
                QString::number(vLoadMode_PagesOfInterest.size()) + "/" +
                QString::number(vLoadMode_Colors_R.size()) + "/" +
                QString::number(vLoadMode_Colors_G.size()) + "/" +
                QString::number(vLoadMode_Colors_B.size()) + "/" +
                QString::number(vLoadMode_Colors_A.size()) +
                "<br>Type: " + D_Img_Proc::Type_of_Mat(&(vLoadMode_PagesOfInterest[0])));
        }
            break;

        case LOAD_PAGES_COLOR:
            ERR(ER_channel_bad,
                "Update_ImgProc_Step",
                "STEP_CONVERT_COLOR - LOAD_PAGES_COLOR - Multiapged and multichanneled image currently not supported");
            return;

        default:
            return;
        }
    }
        break;

    case STEP_DRAW_BINARY:
    {
        if(FIL_DrawFiles[img].exists())
        {
            ERR(D_Img_Proc::Load_From_Path_Gray(
                    &(vMA_ProcSteps[STEP_DRAW_BINARY]),
                    FIL_DrawFiles[img]),
                "Update_ImgProc_Step",
                "STEP_DRAW - D_Img_Proc::Load_From_Path");
        }
        else
        {
            vMA_ProcSteps[STEP_DRAW_BINARY] = Mat(
                        vMA_ProcSteps[STEP_LOAD].rows,
                        vMA_ProcSteps[STEP_LOAD].cols,
                        CV_8UC1,
                        Scalar(0));
            Draw_WriteFile();
        }
    }
        break;

    case STEP_DRAW_EDGES:
    {
        ERR(D_Img_Proc::Reduce_Outlines(
                &(vMA_ProcSteps[STEP_DRAW_EDGES]),
                &(vMA_ProcSteps[STEP_DRAW_BINARY])),
            "Update_ImgProc_Step",
            "STEP_DRAW_EDGES - D_Img_Proc::OverlayOverwrite");
    }
        break;

    case STEP_DRAW_OVERLAY:
    {
        ERR(D_Img_Proc::OverlayOverwrite(
                &(vMA_ProcSteps[STEP_DRAW_OVERLAY]),
                &(vMA_ProcSteps[STEP_CONVERT_COLOR]),
                &(vMA_ProcSteps[STEP_DRAW_EDGES]),
                Draw_OverlayColor,
                ui->doubleSpinBox_Intensity_Overlay->value() / 100.0,
                ui->doubleSpinBox_Intensity_Backgrouond->value() / 100.0),
            "Update_ImgProc_Step",
            "STEP_DRAW_OVERLAY - D_Img_Proc::OverlayOverwrite - type_overlay"
            " " + D_Img_Proc::Type_of_Mat(&(vMA_ProcSteps[STEP_CONVERT_COLOR])) + " type_edges " + D_Img_Proc::Type_of_Mat(&(vMA_ProcSteps[STEP_DRAW_EDGES])));
    }
        break;

    case STEP_LABELING:
    {
        ERR(D_Img_Proc::Labeling(
                &(vMA_ProcSteps[STEP_LABELING]),
                &(vMA_ProcSteps[STEP_DRAW_BINARY]),
                8,
                CV_16U),
            "Update_ImgProc_Step",
            "STEP_LABELING - D_Img_Proc::Labeling");
    }
        break;

    case STEP_SEGMENTATION_NUMBERS:
    {
        Mat MA_tmp_BinaryLabelNumber;
        ERR(D_Img_Proc::Draw_Label_Numbers(
                &MA_tmp_BinaryLabelNumber,
                &(vMA_ProcSteps[STEP_LABELING]),
                2,
                2,
                true),
            "Update_ImgProc_Step",
            "STEP_SEGMENTATION_NUMBERS - D_Img_Proc::Draw_Label_Numbers");

        Mat MA_tmp_BinaryLabelNumberAndEdges;
        ERR(D_Img_Proc::Math_ImgImg_BitOr(
                &MA_tmp_BinaryLabelNumberAndEdges,
                &MA_tmp_BinaryLabelNumber,
                &(vMA_ProcSteps[STEP_DRAW_EDGES])),
            "Update_ImgProc_Step",
            "STEP_SEGMENTATION_NUMBERS - D_Img_Proc::Math_ImgScal_Add");

        ERR(D_Img_Proc::OverlayOverwrite(
                &(vMA_ProcSteps[STEP_SEGMENTATION_NUMBERS]),
                &(vMA_ProcSteps[STEP_CONVERT_COLOR]),
                &MA_tmp_BinaryLabelNumberAndEdges,
                Draw_OverlayColor,
                ui->doubleSpinBox_Intensity_Overlay->value() / 100.0,
                ui->doubleSpinBox_Intensity_Backgrouond->value() / 100.0),
            "Update_ImgProc_Step",
            "STEP_SEGMENTATION_NUMBERS - D_Img_Proc::OverlayOverwrite");

        MA_tmp_BinaryLabelNumber.release();
        MA_tmp_BinaryLabelNumberAndEdges.release();

        //this is the last step
        state_Current_ImgProc_Done = true;

        //trigger calculation after last step
        Update_Calc_All();
    }
        break;

    default:
        break;
    }
}

void D_MAKRO_ManuelSegmentation::Update_Calc_All()
{
    if(!state_Current_ImgProc_Done)
        return;

    //current img
    Update_Calc_Current_Feats();
    Update_Calc_Current_Stats();

    //pool
    Update_Calc_Pool();

    //stack
    Update_Calc_All_Stats();

    //Selections
    Update_Calc_Selections();

    //show results
    Update_Results();
}

void D_MAKRO_ManuelSegmentation::Update_Calc_Current_Feats()
{
    //current img
    int img = ui->comboBox_Data->currentIndex();

    //Get settings if there are any saved ones
    Scale_GetFromFile();

    //calc feats
    D_Component_List CompList(&(vMA_ProcSteps[STEP_LABELING]), 8);

    //remember feats
    vv_FeatComp_Current.resize(FEAT_CUSTOM_NUMBER_OF);
    for(int feat = 0; feat < FEAT_CUSTOM_NUMBER_OF; feat++)
    {
        vv_FeatComp_Current[feat].resize(CompList.size());
        for(int comp = 0; comp < CompList.size(); comp++)
        {
            if(feat < FEAT_CUSTOM_AREA_SCALED)
                vv_FeatComp_Current[feat][comp] = CompList.get_Feature(comp, feat);
            else if(feat == FEAT_CUSTOM_AREA_SCALED)
                vv_FeatComp_Current[FEAT_CUSTOM_AREA_SCALED][comp] = vv_FeatComp_Current[c_FEAT_AREA][comp] * Scale_vFactor[img];
        }
    }
}

void D_MAKRO_ManuelSegmentation::Update_Calc_Current_Stats()
{
    for(int feat = 0; feat < FEAT_CUSTOM_NUMBER_OF; feat++)
        D_Stat::Calc_Stats(&(vv_FeatStat_Current[feat]), vv_FeatComp_Current[feat], true);

    //current img analysed
    v_ImgAnalysed[ui->comboBox_Data->currentIndex()] = 1;
    state_Current_Calc_Done = true;
}

void D_MAKRO_ManuelSegmentation::Update_Calc_Pool()
{
    int img_current = ui->comboBox_Data->currentIndex();

    //stack single analysis
    vvv_ImgFeatComp_All[img_current] = vv_FeatComp_Current;
    vvv_ImgFeatStat_All[img_current] = vv_FeatStat_Current;

    //stack pooled analysis
    for(int feat = 0; feat < FEAT_CUSTOM_NUMBER_OF; feat++)
    {
        vv_FeatComp_All[feat].clear();
        for(int img = 0; img < FIL_Images.size(); img++)
            if(v_ImgAnalysed[img])
                for(int comp = 0; comp < vvv_ImgFeatComp_All[img][feat].size(); comp++)
                    vv_FeatComp_All[feat].push_back(vvv_ImgFeatComp_All[img][feat][comp]);
    }
}

void D_MAKRO_ManuelSegmentation::Update_Calc_All_Stats()
{
    for(int feat = 0; feat < FEAT_CUSTOM_NUMBER_OF; feat++)
        D_Stat::Calc_Stats(&(vv_FeatStat_All[feat]), vv_FeatComp_All[feat], true);

    state_All_Calc_Done = true;
}

void D_MAKRO_ManuelSegmentation::Update_Calc_Selections()
{
    size_t feat_count_selected = v_FeatsOfInterest.size();
    size_t stat_count_selected = v_StatsOfInterest.size();

    vv_FeatComp_Current_Selection.resize(feat_count_selected);
    vv_FeatStat_Current_Selection.resize(feat_count_selected);
    vv_FeatComp_All_Selection.resize(feat_count_selected);
    vv_FeatStat_All_Selection.resize(feat_count_selected);

    for(int feat_selected = 0; feat_selected < feat_count_selected; feat_selected++)
    {
        //current
        vv_FeatComp_Current_Selection[feat_selected] = vv_FeatComp_Current[v_FeatsOfInterest[feat_selected]];

        //stack
        vv_FeatComp_All_Selection[feat_selected] = vv_FeatComp_All[v_FeatsOfInterest[feat_selected]];

        //stats
        vv_FeatStat_Current_Selection[feat_selected].resize(stat_count_selected);
        vv_FeatStat_All_Selection[feat_selected].resize(stat_count_selected);
        for(int stat_selected = 0; stat_selected < stat_count_selected; stat_selected++)
        {
            vv_FeatStat_Current_Selection[feat_selected][stat_selected] = vv_FeatStat_Current   [v_FeatsOfInterest[feat_selected]]  [v_StatsOfInterest[stat_selected]];
            vv_FeatStat_All_Selection[feat_selected][stat_selected]     = vv_FeatStat_All       [v_FeatsOfInterest[feat_selected]]  [v_StatsOfInterest[stat_selected]];
        }
    }

    state_Selections_Calc = true;

    /*
    qDebug() << "--------------------------------------------";
    qDebug() << "size v_ImgAnalysed" << v_ImgAnalysed.size();
    qDebug() << "size vv_FeatComp_Current" << vv_FeatComp_Current.size() << vv_FeatComp_Current[0].size();
    qDebug() << "size vv_FeatStat_Current" << vv_FeatStat_Current.size() << vv_FeatStat_Current[0].size();
    qDebug() << "size vvv_ImgFeatComp_All" << vvv_ImgFeatComp_All.size() << vvv_ImgFeatComp_All[0].size() << vvv_ImgFeatComp_All[0][0].size();
    qDebug() << "size vvv_ImgFeatStat_All" << vvv_ImgFeatStat_All.size() << vvv_ImgFeatStat_All[0].size() << vvv_ImgFeatStat_All[0][0].size();
    qDebug() << "size vv_FeatComp_All" << vv_FeatComp_All.size() << vv_FeatComp_All[0].size();
    qDebug() << "size vv_FeatStat_All" << vv_FeatStat_All.size() << vv_FeatStat_All[0].size();
    qDebug() << "size vv_FeatComp_Current_Selection" << vv_FeatComp_Current_Selection.size() << vv_FeatComp_Current_Selection[0].size();
    qDebug() << "size vv_FeatStat_Current_Selection" << vv_FeatStat_Current_Selection.size() << vv_FeatStat_Current_Selection[0].size();
    qDebug() << "size vv_FeatComp_All_Selection" << vv_FeatComp_All_Selection.size() << vv_FeatComp_All_Selection[0].size();
    qDebug() << "size vv_FeatStat_All_Selection" << vv_FeatStat_All_Selection.size() << vv_FeatStat_All_Selection[0].size();
    qDebug() << "--------------------------------------------";
    */
}

void D_MAKRO_ManuelSegmentation::Draw_RecieveClickLeft(int x, int y)
{
    if(!state_Images_Loaded)
        return;

    //Remember old Points
    for(size_t pt = Draw_vPoints.size() - 1; pt > 0; pt--)
        Draw_vPoints[pt] = Draw_vPoints[pt - 1];

    //Set new point
    Draw_vPoints[0] = Point(x, y);

    //increase remembered clicks
    if(Draw_RememberedClicks < Draw_ClickMemoryCount)
        Draw_RememberedClicks++;

    //Trigger draw action
    switch (Draw_ActiveTool) {
    case DRAW_TOOL_LINE_FG:     Draw_ConsecutiveLine_FG();  break;
    case DRAW_TOOL_LINE_BG:     Draw_ConsecutiveLine_BG();  break;
    case DRAW_TOOL_FLOODFILL:   Draw_Floodfill();           break;
    default:                                                return;}

    //save drawing in file
    Draw_WriteFile();

    //Update img proc chain
    Update_ImgProc(STEP_DRAW_EDGES);
}

void D_MAKRO_ManuelSegmentation::Draw_RecieveClickRight(int x, int y)
{
    x;y;//not needed at the moment
    Draw_RememberedClicks = 0;
}

void D_MAKRO_ManuelSegmentation::Draw_ConsecutiveLine_FG()
{
    if(Draw_RememberedClicks < 2)
        return;
    Draw_BackupCreate();

    ERR(D_Img_Proc::Draw_Line(
                &(vMA_ProcSteps[STEP_DRAW_BINARY]),
                Draw_vPoints[0].x,
                Draw_vPoints[0].y,
                Draw_vPoints[1].x,
                Draw_vPoints[1].y,
                1,
                255),
            "Draw_ConsecutiveLine_FG",
            "D_Img_Proc::Draw_Line");
}

void D_MAKRO_ManuelSegmentation::Draw_ConsecutiveLine_BG()
{
    if(Draw_RememberedClicks < 2)
        return;
    Draw_BackupCreate();

    ERR(D_Img_Proc::Draw_Line(
                &(vMA_ProcSteps[STEP_DRAW_BINARY]),
                Draw_vPoints[0].x,
                Draw_vPoints[0].y,
                Draw_vPoints[1].x,
                Draw_vPoints[1].y,
                2,
                0),
            "Draw_ConsecutiveLine_BG",
            "D_Img_Proc::Draw_Line");
}

void D_MAKRO_ManuelSegmentation::Draw_Floodfill()
{
    if(Draw_RememberedClicks < 1)
        return;
    Draw_BackupCreate();

    ERR(D_Img_Proc::Floodfill(
                &(vMA_ProcSteps[STEP_DRAW_BINARY]),
                Draw_vPoints[0].x,
                Draw_vPoints[0].y,
                255),
            "Draw_Floodfill",
            "D_Img_Proc::Floodfill");
}

void D_MAKRO_ManuelSegmentation::Draw_Reset()
{
    Draw_BackupCreate();
    vMA_ProcSteps[STEP_DRAW_BINARY] = Mat::zeros(vMA_ProcSteps[STEP_DRAW_BINARY].size(), CV_8UC1);

    //save drawing in file
    Draw_WriteFile();

    //Update img proc chain
    Update_ImgProc(STEP_DRAW_EDGES);
}

void D_MAKRO_ManuelSegmentation::Draw_Undo()
{
    vMA_ProcSteps[STEP_DRAW_BINARY] = Draw_MA_Backup.clone();
    ui->pushButton_Draw_Undo->setEnabled(false);

    //save drawing in file
    Draw_WriteFile();

    //Update img proc chain
    Update_ImgProc(STEP_DRAW_EDGES);
}

void D_MAKRO_ManuelSegmentation::Draw_FillHoles()
{
    Draw_BackupCreate();

    Mat MA_tmp_Input = vMA_ProcSteps[STEP_DRAW_BINARY].clone();
    ERR(D_Img_Proc::Fill_Holes(
                &(vMA_ProcSteps[STEP_DRAW_BINARY]),
                &MA_tmp_Input),
            "Draw_FillHoles",
            "D_Img_Proc::Fill_Holes");

    MA_tmp_Input.release();

    //save drawing in file
    Draw_WriteFile();

    //Update img proc chain
    Update_ImgProc(STEP_DRAW_EDGES);
}

void D_MAKRO_ManuelSegmentation::Draw_BackupCreate()
{
    Draw_MA_Backup = vMA_ProcSteps[STEP_DRAW_BINARY].clone();
    ui->pushButton_Draw_Undo->setEnabled(true);
}

void D_MAKRO_ManuelSegmentation::Draw_WriteFile()
{
    imwrite(FIL_DrawFiles[ui->comboBox_Data->currentIndex()].absoluteFilePath().toStdString(),
            vMA_ProcSteps[STEP_DRAW_BINARY]);
}

void D_MAKRO_ManuelSegmentation::Update_Results()
{
    if(!state_Selections_Calc || !state_All_Calc_Done)
        return;

    switch (ui->comboBox_Results->currentIndex()) {
    case RES_GRAPHIC_SEG:       Update_Image_Seg();             break;
    case RES_TAB_CUR_FEAT:      Update_Table_Current_Feat();    break;
    case RES_TAB_CUR_STAT:      Update_Table_Current_Stat();    break;
    case RES_TAB_ALL_FEAT:      Update_Table_All_Feat();        break;
    case RES_TAB_ALL_STAT:      Update_Table_All_Stat();        break;
    default:                                                    return;}
}

void D_MAKRO_ManuelSegmentation::Update_Table_Current_Feat()
{
    QStringList QSl_CompNames;
    for(int comp = 0; comp < vv_FeatComp_Current_Selection[0].size(); comp++)
        QSl_CompNames.append("Obj_" + QString::number(comp));

    Table_Current_Feats.set_data_d_2D_qsl_qsl(
                vv_FeatComp_Current_Selection,
                QSL_FeatsOfInterest,
                QSl_CompNames);
}

void D_MAKRO_ManuelSegmentation::Update_Table_Current_Stat()
{
    Table_Current_Stats.set_data_d_2D_qsl_qsl(
                vv_FeatStat_Current_Selection,
                QSL_FeatsOfInterest,
                QSL_StatsOfInterest);
}

void D_MAKRO_ManuelSegmentation::Update_Table_All_Feat()
{
    QStringList QSl_CompNames;
    for(int img = 0; img < vvv_ImgFeatComp_All.size(); img++)
        if(v_ImgAnalysed[img])
            for(int comp = 0; comp < vvv_ImgFeatComp_All[img][0].size(); comp++)
                QSl_CompNames.append("Img" + QString::number(img) + "_Obj_" + QString::number(comp));

    Table_All_Feats.set_data_d_2D_qsl_qsl(
                vv_FeatComp_All_Selection,
                QSL_FeatsOfInterest,
                QSl_CompNames);
}

void D_MAKRO_ManuelSegmentation::Update_Table_All_Stat()
{
    Table_All_Stats.set_data_d_2D_qsl_qsl(
                vv_FeatStat_All_Selection,
                QSL_FeatsOfInterest,
                QSL_StatsOfInterest);
}

void D_MAKRO_ManuelSegmentation::Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(index_init);
    CB->blockSignals(false);
}

void D_MAKRO_ManuelSegmentation::Populate_CB_Start()
{
    Populate_CB_Single(ui->comboBox_Results,    QSL_Results,    RES_GRAPHIC_SEG);
    Populate_CB_Single(ui->comboBox_StepsDraw,  QSL_ProcSteps,  STEP_DRAW_OVERLAY);
}

void D_MAKRO_ManuelSegmentation::ShowList(QPlainTextEdit *text_edit, QStringList QSL_ParentList, vector<int> *vSelection)
{
    text_edit->clear();

    QString QS_ToPlainTextEdit;
    for(int i = 0; i < vSelection->size(); i++)
    {
        if(i != 0)
            QS_ToPlainTextEdit.append("\n");
        QS_ToPlainTextEdit.append(QSL_ParentList[(*vSelection)[i]]);
    }

    text_edit->setPlainText(QS_ToPlainTextEdit);
}

void D_MAKRO_ManuelSegmentation::Edit_FeatsOfInterest()
{
    D_Popup_ListEdit pop_dim("Please select features of interest", &v_FeatsOfInterest, QSL_FeatsMaster, 0);
    pop_dim.exec();

    QSL_FeatsOfInterest.clear();

    for(int i = 0; i < v_FeatsOfInterest.size(); i++)
        QSL_FeatsOfInterest.append(QSL_FeatsMaster[v_FeatsOfInterest[i]]);

    ShowList(ui->plainTextEdit_Feats, QSL_FeatsMaster, &v_FeatsOfInterest);

    Update_Calc_All();
}

void D_MAKRO_ManuelSegmentation::Edit_StatsOfInterest()
{
    D_Popup_ListEdit pop_dim("Please select statistics of interest", &v_StatsOfInterest, QSL_StatList, 0);
    pop_dim.exec();

    QSL_StatsOfInterest.clear();

    for(int i = 0; i < v_StatsOfInterest.size(); i++)
        QSL_StatsOfInterest.append(QSL_StatList[v_StatsOfInterest[i]]);

    ShowList(ui->plainTextEdit_Stats, QSL_StatList, &v_StatsOfInterest);

    Update_Calc_All();
}

void D_MAKRO_ManuelSegmentation::Draw_Set_Tool_LineForeground()
{
    Draw_ActiveTool = DRAW_TOOL_LINE_FG;
    Draw_RememberedClicks = 0;
    Update_SB_DrawInfo();

    ui->pushButton_DrawTool_Line_FG->setFlat(false);
    ui->pushButton_DrawTool_Line_BG->setFlat(true);
    ui->pushButton_DrawTool_Floodfill->setFlat(true);
}

void D_MAKRO_ManuelSegmentation::Draw_Set_Tool_LineBackground()
{
    Draw_ActiveTool = DRAW_TOOL_LINE_BG;
    Draw_RememberedClicks = 0;
    Update_SB_DrawInfo();

    ui->pushButton_DrawTool_Line_FG->setFlat(true);
    ui->pushButton_DrawTool_Line_BG->setFlat(false);
    ui->pushButton_DrawTool_Floodfill->setFlat(true);
}

void D_MAKRO_ManuelSegmentation::Draw_Set_Tool_FillFlood()
{
    Draw_ActiveTool = DRAW_TOOL_FLOODFILL;
    Draw_RememberedClicks = 0;
    Update_SB_DrawInfo();

    ui->pushButton_DrawTool_Line_FG->setFlat(true);
    ui->pushButton_DrawTool_Line_BG->setFlat(true);
    ui->pushButton_DrawTool_Floodfill->setFlat(false);
}

bool D_MAKRO_ManuelSegmentation::Scale_GetFromFile()
{
    if(!state_CalcContainers_CorrectSize || !state_Images_Loaded)
        return false;

    //current img
    int img = ui->comboBox_Data->currentIndex();

    if(FIL_Param[img].exists())
    {
        ifstream is_param;
        is_param.open(FIL_Param[img].absoluteFilePath().toStdString());
        string st_line;

        while(getline(is_param, st_line))
        {
            QString QS_Line = QString::fromStdString(st_line);
            QStringList QSL_Words = QS_Line.split(" ");
            if(QSL_Words.size() == 2)
                for(int p = 0; p < PARAM_NUMBER_OF; p++)
                    if(QSL_Words[0] == QSL_Param[p])
                    {
                        switch (p) {

                        case PARAM_SCALE_PX:
                        {
                            bool ok;
                            int val = QSL_Words[1].toInt(&ok);
                            if(ok)
                                Scale_vCalib_Px[img] = val;
                        }
                            break;

                        case PARAM_SCALE_CUSTOM_UNIT:
                        {
                            bool ok;
                            double val = QSL_Words[1].toDouble(&ok);
                            if(ok)
                                Scale_vCalib_CustomUnit[img] = val;
                        }
                            break;

                        default:
                            break;
                        }
                    }
        }

        Scale_ToUi();
        return true;
    }
    else
    {
        Scale_SetToDefault();
        Scale_WriteToFile();
        return false;
    }
}

void D_MAKRO_ManuelSegmentation::Scale_WriteToFile()
{
    if(!state_CalcContainers_CorrectSize || !state_Images_Loaded)
        return;

    //current img
    int img = ui->comboBox_Data->currentIndex();

    //open stream
    ofstream os_param;
    os_param.open(FIL_Param[ui->comboBox_Data->currentIndex()].absoluteFilePath().toStdString());

    os_param << QSL_Param[PARAM_SCALE_PX].toStdString() << " " << Scale_vCalib_Px[img] << "\n";
    os_param << QSL_Param[PARAM_SCALE_CUSTOM_UNIT].toStdString() << " " << Scale_vCalib_CustomUnit[img] << "\n";

    //close
    os_param.close();
}

void D_MAKRO_ManuelSegmentation::Scale_SetToDefault()
{
    if(!state_CalcContainers_CorrectSize || !state_Images_Loaded)
        return;

    //current img
    int img = ui->comboBox_Data->currentIndex();

    Scale_vCalib_Px[img] = ScaleInit_Calib_Px;
    Scale_vCalib_CustomUnit[img] = ScaleInit_Calib_CustomUnit;
    Scale_vFactor[img] = ScaleInit_Factor;

    Scale_ToUi();
}

void D_MAKRO_ManuelSegmentation::Scale_ToUi()
{
    if(!state_CalcContainers_CorrectSize || !state_Images_Loaded)
        return;

    int img = ui->comboBox_Data->currentIndex();

    ui->label_Scale_Factor->setText(QString::number(Scale_vFactor[img], 'g', 6) + Scale_CustomUnit + "²");
    ui->spinBox_Scale_Px->setValue(Scale_vCalib_Px[img]);
    ui->doubleSpinBox_Scale_CutomUnit->setValue(Scale_vCalib_CustomUnit[img]);
}

void D_MAKRO_ManuelSegmentation::Scale_UpdateFactor()
{
    if(!state_CalcContainers_CorrectSize || !state_Images_Loaded)
    {
        //if no data is loaded and containers are not init -> don't change anything
        ui->spinBox_Scale_Px->setValue(ScaleInit_Calib_Px);
        ui->doubleSpinBox_Scale_CutomUnit->setValue(ScaleInit_Calib_CustomUnit);
        return;
    }

    //update scaling factor
    int img = ui->comboBox_Data->currentIndex();
    Scale_vFactor[img] = (Scale_vCalib_CustomUnit[img] / Scale_vCalib_Px[img]) * (Scale_vCalib_CustomUnit[img] / Scale_vCalib_Px[img]);
    ui->label_Scale_Factor->setText(QString::number(Scale_vFactor[img], 'g', 6) + Scale_CustomUnit + "²");
    QSL_FeatsMaster[FEAT_CUSTOM_AREA_SCALED] = "Area in " + Scale_CustomUnit + "²";
    ShowList(ui->plainTextEdit_Feats, QSL_FeatsMaster, &v_FeatsOfInterest);

    //recalculate scaled feats
    Scale_UpdateFactor_Recalculate();

    //save for next use on same image
    Scale_WriteToFile();
}

void D_MAKRO_ManuelSegmentation::Scale_UpdateFactor_Recalculate()
{
    //curreng img
    int img_cur = ui->comboBox_Data->currentIndex();

    //current
    for(int comp = 0; comp < vv_FeatComp_Current[0].size(); comp++)
        vv_FeatComp_Current[FEAT_CUSTOM_AREA_SCALED][comp] = vv_FeatComp_Current[c_FEAT_AREA][comp] * Scale_vFactor[img_cur];
    Update_Calc_Current_Stats();

    //stacked single analysis
    //should not be needed, but to be safe after some changes this code is kept
    for(int img = 0; img < FIL_Images.size(); img++)
        if(v_ImgAnalysed[img])
        {
            for(int comp = 0; comp < vvv_ImgFeatComp_All[img][0].size(); comp++)
                vvv_ImgFeatComp_All[img][FEAT_CUSTOM_AREA_SCALED][comp] = vvv_ImgFeatComp_All[img][c_FEAT_AREA][comp] * Scale_vFactor[img];

            D_Stat::Calc_Stats(&(vvv_ImgFeatStat_All[img][FEAT_CUSTOM_AREA_SCALED]), vvv_ImgFeatComp_All[img][FEAT_CUSTOM_AREA_SCALED], true);
        }

    //pool
    Update_Calc_Pool();

    //stats
    Update_Calc_All_Stats();

    //selections
    Update_Calc_Selections();

    //show results
    Update_Results();
}

void D_MAKRO_ManuelSegmentation::Overlay_Set_Color()
{
    Draw_OverlayColor = QColorDialog::getColor(
                Draw_OverlayColor,
                this,
                "Please Select Overlay Color (no effect but visuals)");
    Update_ImgProc(STEP_DRAW_OVERLAY);

    QPalette pal = ui->pushButton_Overlay_Color->palette();
    pal.setColor(QPalette::Button, Draw_OverlayColor);
    ui->pushButton_Overlay_Color->setAutoFillBackground(true);
    ui->pushButton_Overlay_Color->setPalette(pal);
    ui->pushButton_Overlay_Color->update();
}


void D_MAKRO_ManuelSegmentation::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_MAKRO_ManuelSegmentation", func, detail);
}

void D_MAKRO_ManuelSegmentation::on_doubleSpinBox_Intensity_Overlay_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc(STEP_DRAW_OVERLAY);
}

void D_MAKRO_ManuelSegmentation::on_doubleSpinBox_Intensity_Backgrouond_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc(STEP_DRAW_OVERLAY);
}

void D_MAKRO_ManuelSegmentation::on_spinBox_Scale_Px_valueChanged(int arg1)
{
    Scale_vCalib_Px[ui->comboBox_Data->currentIndex()] = arg1;
    Scale_UpdateFactor();
}

void D_MAKRO_ManuelSegmentation::on_doubleSpinBox_Scale_CutomUnit_valueChanged(double arg1)
{
    Scale_vCalib_CustomUnit[ui->comboBox_Data->currentIndex()] = arg1;
    Scale_UpdateFactor();
}

void D_MAKRO_ManuelSegmentation::on_lineEdit_Scale_CustomUnit_textChanged(const QString &arg1)
{
    Scale_CustomUnit = arg1;
    Scale_UpdateFactor();
}
