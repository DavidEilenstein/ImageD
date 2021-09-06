/************************************
 *   added:     09.10.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_makro_mitochondrien.h"
#include "ui_d_makro_mitochondrien.h"

D_MAKRO_Mitochondrien::D_MAKRO_Mitochondrien(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_Mitochondrien)
{
    ui->setupUi(this);

    //connect stuff with parent
    pStore = pStorage;

    //allocate memory for images
    MA_Init = pStore->get_Adress(0)->clone();
    Init_MatVector(&vMA_Photons, c_SC_PHOTONS);
    Init_MatVector(&vMA_Results, c_SC_RESULTS);
    MA_Color = MA_Init.clone();
    MA_Math = MA_Init.clone();
    MA_CellSep_Last = MA_Init.clone();


    //Results & Stat CB
    Init_QSL_Results();
    Populate_CB_Results();
    Populate_CB_Stat();


    //Viewer
    Viewer_Photons.set_GV(ui->graphicsView_Photons);
    Viewer_Parameters.set_GV(ui->graphicsView_Parameter);
    Viewer_Results.set_GV(ui->graphicsView_Results);
    Viewer_Photons.Update_Image(&MA_Init);
    Viewer_Parameters.Update_Image(&MA_Init);
    Viewer_Results.Update_Image(&MA_Init);
    Viewer_Photons.connect_Zoom(&Viewer_Parameters);
    //Viewer_Photons.connect_Zoom(&Viewer_Results);
    //Init GraphicsView
    /*Init_GraphicsView(ui->graphicsView_Photons, &SC_Photons);
    Init_GraphicsView(ui->graphicsView_Parameter, &SC_Parameters);
    Init_GraphicsView(ui->graphicsView_Results, &SC_Results);*/


    //Init Plot
    Init_Plot();
    Populate_CB_Style();

    //STATUSBAR
    unsigned int LabelWidth = 75;

    L_SB_Size = new QLabel(this);
    L_SB_Size->setFixedWidth(LabelWidth * 2);
    L_SB_Size->setToolTip("Size of the current photons image");
    ui->statusbar->addPermanentWidget(L_SB_Size);

    L_SB_ValAtPos = new QLabel(this);
    L_SB_ValAtPos->setFixedWidth(LabelWidth * 2);
    L_SB_ValAtPos->setToolTip("Pixelvalue (Mouse hovered).");
    ui->statusbar->addPermanentWidget(L_SB_ValAtPos);



    //CONNECTS
    //Data
    connect(ui->action_Load,                        SIGNAL(triggered(bool)),            this,   SLOT(Load_Directory()));
    connect(ui->action_Next_Image,                  SIGNAL(triggered(bool)),            this,   SLOT(Next_Image()));
    connect(ui->action_Clear_Queue,                 SIGNAL(triggered(bool)),            this,   SLOT(Clear_Queue()));
    //View
    connect(ui->action_Update_View,                 SIGNAL(triggered(bool)),            this,   SLOT(Update_Views()));
    connect(ui->action_Keep_Aspect_Ratio,           SIGNAL(triggered(bool)),            this,   SLOT(Update_Views()));
    connect(ui->action_Smooth_Transformation,       SIGNAL(triggered(bool)),            this,   SLOT(Update_Views()));
    connect(ui->comboBox_ParVie_Parameter,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_View_Parameters()));
    connect(ui->checkBox_ParVie_RoI_Only,           SIGNAL(clicked(bool)),              this,   SLOT(Update_View_Parameters()));
    connect(ui->checkBox_ParVie_Contrast,           SIGNAL(clicked(bool)),              this,   SLOT(Update_View_Parameters()));
    connect(ui->radioButton_ParVie_0_as_0,          SIGNAL(clicked(bool)),              this,   SLOT(Update_View_Parameters()));
    connect(ui->radioButton_ParVie_0_as_Min,        SIGNAL(clicked(bool)),              this,   SLOT(Update_View_Parameters()));
    connect(ui->radioButton_ParVie_0_as_Max,        SIGNAL(clicked(bool)),              this,   SLOT(Update_View_Parameters()));
    connect(ui->comboBox_PhoVie_Step,               SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_View_Photons()));
    //calc
    connect(ui->checkBox_ResCon_Ignore_Zero,        SIGNAL(clicked(bool)),              this,   SLOT(Calc_Data_All()));
    connect(ui->checkBox_ResCon_RoI_Only,           SIGNAL(clicked(bool)),              this,   SLOT(Calc_Data_All()));

    //Update results image/plot
    connect(ui->tabWidget_Results,                  SIGNAL(currentChanged(int)),        this,   SLOT(Update_Results_Proc()));
    connect(ui->comboBox_ResImg_Type,               SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    connect(ui->comboBox_ResPlo_Type,               SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    connect(ui->checkBox_ResCon_RoI_Only,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Results_Proc()));
    connect(ui->checkBox_ResCon_Ignore_Zero,        SIGNAL(clicked(bool)),              this,   SLOT(Update_Results_Proc()));
    //Update color image
    connect(ui->comboBox_Gra_B,                     SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    connect(ui->comboBox_Gra_G,                     SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    connect(ui->comboBox_Gra_R,                     SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    //Update math image
    connect(ui->comboBox_Math_Operator,             SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    connect(ui->comboBox_Math_Par_1,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    connect(ui->comboBox_Math_Par_2,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    //Update plot hist
    connect(ui->comboBox_His_Image,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    connect(ui->spinBox_His_ClassCount,             SIGNAL(valueChanged(int)),          this,   SLOT(Update_Results_Proc()));
    connect(ui->checkBox_His_Accumulate,            SIGNAL(clicked(bool)),              this,   SLOT(Update_Results_Proc()));
    connect(ui->checkBox_His_Uniform,               SIGNAL(clicked(bool)),              this,   SLOT(Update_Results_Proc()));
    //Update plot parameter dual
    connect(ui->comboBox_Par_Nucleus,               SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    connect(ui->comboBox_Par_X_Parameter,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    connect(ui->comboBox_Par_Y_Parameter,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    //Update plot parameter cell
    connect(ui->comboBox_ParCell_X_Parameter,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    connect(ui->comboBox_ParCell_Y_Parameter,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    connect(ui->comboBox_ParCell_X_Stat,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    connect(ui->comboBox_ParCell_Y_Stat,            SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    //Update plot parameter all
    connect(ui->comboBox_ParAll_Parameter,          SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    connect(ui->spinBox_ParAll_ClassCount,          SIGNAL(valueChanged(int)),          this,   SLOT(Update_Results_Proc()));
    connect(ui->checkBox_ParAll_Accumulate,         SIGNAL(clicked(bool)),              this,   SLOT(Update_Results_Proc()));
    connect(ui->checkBox_ParAll_Uniform,            SIGNAL(clicked(bool)),              this,   SLOT(Update_Results_Proc()));
    //Update plot MM
    connect(ui->comboBox_Stat_MM_Parameter,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    connect(ui->checkBox_Stat_MM_Mean,              SIGNAL(clicked(bool)),              this,   SLOT(Update_Results_Proc()));
    connect(ui->checkBox_Stat_MM_SD,                SIGNAL(clicked(bool)),              this,   SLOT(Update_Results_Proc()));
    connect(ui->checkBox_Stat_MM_Median,            SIGNAL(clicked(bool)),              this,   SLOT(Update_Results_Proc()));
    connect(ui->checkBox_Stat_MM_ADM,               SIGNAL(clicked(bool)),              this,   SLOT(Update_Results_Proc()));
    //Update plot CSK
    connect(ui->comboBox_Stat_CSK_Parameter,        SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    connect(ui->checkBox_Stat_CSK_CV,               SIGNAL(clicked(bool)),              this,   SLOT(Update_Results_Proc()));
    connect(ui->checkBox_Stat_CSK_Skewness,         SIGNAL(clicked(bool)),              this,   SLOT(Update_Results_Proc()));
    connect(ui->checkBox_Stat_CSK_Kurtosis,         SIGNAL(clicked(bool)),              this,   SLOT(Update_Results_Proc()));
    //Update plot Quantiles
    connect(ui->comboBox_Stat_Quantiles_Parameter,  SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    connect(ui->comboBox_Stat_Quantiles_Step,       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results_Proc()));
    //Update
    connect(ui->action_Update_Image_Processing,     SIGNAL(triggered(bool)),            this,   SLOT(Update_ImgProc_All()));
    connect(ui->action_Update_Calculation,          SIGNAL(triggered(bool)),            this,   SLOT(Calc_Data_All()));
    //Draw RoI
    connect(&Viewer_Photons,                        SIGNAL(MouseClickedLeft_Pos(int,int)),this, SLOT(Get_Click_Pos(int,int)));
    connect(ui->pushButton_PhoCon_Paint_Undo,       SIGNAL(clicked(bool)),              this,   SLOT(CellSep_Undo()));
  //connect(ui->pushButton_PhoCon_Paint_Open,       SIGNAL(clicked(bool)),              this,   SLOT(CellSep_Open()));
    connect(ui->pushButton_PhoCon_Paint_Load,       SIGNAL(clicked(bool)),              this,   SLOT(CellSep_Load()));
    connect(ui->pushButton_PhoCon_Paint_Save,       SIGNAL(clicked(bool)),              this,   SLOT(CellSep_Save()));
    //Stream
    connect(ui->action_Stream_Open,                 SIGNAL(triggered(bool)),            this,   SLOT(Stream_Stats_Start()));
    connect(ui->action_Stream_Current,              SIGNAL(triggered(bool)),            this,   SLOT(Stream_Stats()));
    connect(ui->action_Stream_Current,              SIGNAL(triggered(bool)),            this,   SLOT(Stream_ImagesPlots()));
    connect(ui->action_Stream_Current,              SIGNAL(triggered(bool)),            this,   SLOT(Stream_Settings()));
    connect(ui->action_Stream_Close,                SIGNAL(triggered(bool)),            this,   SLOT(Stream_Stats_End()));
    //Save
    connect(ui->action_Save_Photons,                SIGNAL(triggered(bool)),            this,   SLOT(Save_Image_Photons()));
    connect(ui->action_Save_Parameters,             SIGNAL(triggered(bool)),            this,   SLOT(Save_Image_Parameters()));
    connect(ui->action_Save_Results,                SIGNAL(triggered(bool)),            this,   SLOT(Save_Image_Results()));
    connect(ui->action_Save_Plot,                   SIGNAL(triggered(bool)),            this,   SLOT(Save_Plot()));
    //Style
    connect(ui->comboBox_ResCon_Legend,             SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Style()));
    connect(ui->comboBox_ResCon_Theme,              SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Style()));
    connect(ui->checkBox_ResCon_AA,                 SIGNAL(clicked(bool)),              this,   SLOT(Update_Style()));
    //AdaptUI
    connect(ui->comboBox_ResPlo_Type,               SIGNAL(currentIndexChanged(int)),   this,   SLOT(AdaptUI_Results()));
    connect(ui->tabWidget_Results,                  SIGNAL(currentChanged(int)),        this,   SLOT(AdaptUI_Results()));
    //Mouse Moved
    connect(&Viewer_Photons,                        SIGNAL(MouseMoved_Value(QString)),  L_SB_ValAtPos,   SLOT(setText(QString)));
    connect(&Viewer_Parameters,                     SIGNAL(MouseMoved_Value(QString)),  L_SB_ValAtPos,   SLOT(setText(QString)));
    connect(&Viewer_Results,                        SIGNAL(MouseMoved_Value(QString)),  L_SB_ValAtPos,   SLOT(setText(QString)));
    //T2 Handling
    connect(ui->doubleSpinBox_ParCon_T2_Max_Const,  SIGNAL(valueChanged(double)),       this,   SLOT(Calc_T2_Handling()));
    connect(ui->doubleSpinBox_ParCon_T2_Max_Thres,  SIGNAL(valueChanged(double)),       this,   SLOT(Calc_T2_Handling()));
    connect(ui->doubleSpinBox_ParCon_T2_Min_Const,  SIGNAL(valueChanged(double)),       this,   SLOT(Calc_T2_Handling()));
    connect(ui->doubleSpinBox_ParCon_T2_Min_Thres,  SIGNAL(valueChanged(double)),       this,   SLOT(Calc_T2_Handling()));


    //stuff to be done on first show
    //this->showMaximized();
    Update_Views();
    Update_Style();


    //icon & title
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    setWindowTitle("ImageD - Mitochondria Analysis");
}

D_MAKRO_Mitochondrien::~D_MAKRO_Mitochondrien()
{
    delete ui;
}

void D_MAKRO_Mitochondrien::closeEvent(QCloseEvent *event)
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

void D_MAKRO_Mitochondrien::mousePressEvent(QMouseEvent *event)
{
    //start new line on right click
    if(event->button() == Qt::RightButton)
        if(ManSep_Manip)
            ManSep_Line_Begin = true;
}

void D_MAKRO_Mitochondrien::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    Update_Views();
}

void D_MAKRO_Mitochondrien::Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(index_init);
    CB->blockSignals(false);
}

void D_MAKRO_Mitochondrien::Update_ImgProc_All()
{
    Update_ImgProc_Photons(0);
    //All other procs amd views are called in the called mathods
}



void D_MAKRO_Mitochondrien::Update_ImgProc_Photons(unsigned int start_step)
{
    for(unsigned int s = start_step; s < vMA_Photons.size(); s++)
        Update_Step_Photons(s);
    Update_View_Photons();

    Update_ImgProc_Parameters();
}

void D_MAKRO_Mitochondrien::Update_ImgProc_Parameters()
{
    for(unsigned int s = 0; s < vMA_Parameter_All_Float.size(); s++)
    {
        ERR(D_Img_Proc::Mask(
                &(vMA_Parameter_RoI_Float[s]),
                &(vMA_Parameter_All_Float[s]),
                &(vMA_Photons[c_ST_PH_ROI_MITO])),
            "Update_ImgProc_Parameters",
            "D_Img_Proc::Mask - Parameter: " + QSL_Parameter_Suffixes[s]);
    }
    Convert_Parameters_8bit_RoI();


    Update_View_Parameters();

    Update_ImgProc_Results(0);
    //Update_Math_Image();
    Update_Results_Proc();

    if(ui->action_Autoupdate_Calc_on_ImgProc->isChecked())
        Calc_Data_All();
}

void D_MAKRO_Mitochondrien::Convert_Parameters_8bit_All()
{
    for(unsigned int s = 0; s < vMA_Parameter_All_Float.size(); s++)
    {
        ERR(D_Img_Proc::Normalize(
                &(vMA_Parameter_All_8Bit[s]),
                &(vMA_Parameter_All_Float[s]),
                CV_MINMAX,
                CV_8UC1,
                0,
                255),
            "Convert_Parameters_8bit_All",
            "D_Img_Proc::Normalize");
    }
}

void D_MAKRO_Mitochondrien::Convert_Parameters_8bit_RoI()
{
    for(unsigned int s = 0; s < vMA_Parameter_RoI_Float.size(); s++)
    {
        ERR(D_Img_Proc::Normalize(
                &(vMA_Parameter_RoI_8Bit[s]),
                &(vMA_Parameter_RoI_Float[s]),
                CV_MINMAX,
                CV_8UC1,
                0,
                255),
            "Convert_Parameters_8bit_RoI",
            "D_Img_Proc::Normalize");
    }
}

void D_MAKRO_Mitochondrien::Update_ImgProc_Results(unsigned int start_step)
{
    for(unsigned int s = start_step; s < vMA_Results.size(); s++)
        Update_Step_Results(s);
    Update_View_Results();

    Update_Results_Proc();
    /*
    Update_Combi_Results();
    Update_Math_Image();
    Update_Plot_Hist_Img();
    */
}

void D_MAKRO_Mitochondrien::Update_Step_Photons(unsigned int step)
{
    switch (step) {

    case c_ST_PH_LOAD:
    {
        Load_Images();
    }
        break;

    case c_ST_PH_SHADE_CORRECT:
    {
        if(Exist_Refernce)
            ERR(D_Img_Proc::Shading_Correct(
                    &(vMA_Photons[c_ST_PH_SHADE_CORRECT]),
                    &(vMA_Photons[c_ST_PH_LOAD]),
                    &MA_Reference),
                "Update_Step_Photons",
                "c_ST_PH_SHADE_CORRECT - shading correction image found");
        else
            ERR(D_Img_Proc::Duplicate(
                    &(vMA_Photons[c_ST_PH_SHADE_CORRECT]),
                    &(vMA_Photons[c_ST_PH_LOAD])),
                "Update_Step_Photons",
                "c_ST_PH_SHADE_CORRECT - shading correction image NOT found");
    }
        break;

    case c_ST_PH_INPUT_CONV_8bit:
    {
        ERR(D_Img_Proc::Normalize(
                &(vMA_Photons[c_ST_PH_INPUT_CONV_8bit]),
                &(vMA_Photons[c_ST_PH_SHADE_CORRECT]),
                CV_MINMAX,
                CV_8UC1,
                0,
                255),
            "Update_Step_Photons",
            "c_ST_PH_INPUT_CONV_8bit");
    }
        break;

    case c_ST_PH_INPUT_CONTRAST:
    {
        ERR(D_Img_Proc::Histo_Equal(
                &(vMA_Photons[c_ST_PH_INPUT_CONTRAST]),
                &(vMA_Photons[c_ST_PH_INPUT_CONV_8bit])),
            "Update_Step_Photons",
            "c_ST_PH_INPUT_CONTRAST");
    }
        break;

    case c_ST_PH_INPUT_BLUR:
    {
        ERR(D_Img_Proc::Filter_Gauss(
                &(vMA_Photons[c_ST_PH_INPUT_BLUR]),
                &(vMA_Photons[c_ST_PH_INPUT_CONV_8bit]),
                ui->spinBox_PhoCon_Blur_Size->value() / 2,
                ui->spinBox_PhoCon_Blur_Size->value() / 2,
                BORDER_DEFAULT,
                ui->doubleSpinBox_PhoCon_Blur_Sigma->value(),
                ui->doubleSpinBox_PhoCon_Blur_Sigma->value()),
            "Update_Step_Photons",
            "c_ST_PH_INPUT_BLUR");
    }
        break;

    case c_ST_PH_BIN_THRES:
    {
        /*
        int bin_mode;
        if(ui->checkBox_PhoCon_Thresh_Mito->isChecked())
            bin_mode = CV_THRESH_BINARY;        //Mitochondria
        else
            bin_mode = CV_THRESH_BINARY_INV;    //Other stuff
        */

        ERR(D_Img_Proc::Threshold_Adaptive(
                &(vMA_Photons[c_ST_PH_BIN_THRES]),
                &(vMA_Photons[c_ST_PH_INPUT_BLUR]),
                CV_THRESH_BINARY,
                255,
                CV_ADAPTIVE_THRESH_GAUSSIAN_C,
                ui->spinBox_PhoCon_Thres_Size->value() / 2,
                ui->doubleSpinBox_PhoCon_Thres_Offset->value()),
            "Update_Step_Photons",
            "c_ST_PH_BIN_THRES");
    }
        break;

    case c_ST_PH_REGIONS_EDGES:
    {
        //Can only be manipulated with painting with mouse
    }
        break;

    case c_ST_PH_REGIONS_CONNECT:
    {
        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_Photons[c_ST_PH_REGIONS_CONNECT]),
                &(vMA_Photons[c_ST_PH_REGIONS_EDGES]),
                MORPH_CLOSE,
                MORPH_ELLIPSE,
                ui->spinBox_PhoCon_EdgCon_Size->value() / 2,
                ui->spinBox_PhoCon_EdgCon_Size->value() / 2,
                BORDER_DEFAULT,
                1),
            "Update_Step_Photons",
            "c_ST_PH_REGIONS_CONNECT");
    }
        break;

    case c_ST_PH_REGIONS_SEP_VIEW:
    {
        bool channels_use[4];
        channels_use[0] = true;
        channels_use[1] = true;
        channels_use[2] = true;
        channels_use[3] = false;

        ERR(D_Img_Proc::Merge(
                &(vMA_Photons[c_ST_PH_REGIONS_SEP_VIEW]),
                &(vMA_Photons[c_ST_PH_BIN_THRES]),
                &(vMA_Photons[c_ST_PH_REGIONS_CONNECT]),
                &(vMA_Photons[c_ST_PH_INPUT_CONTRAST]),
                &(vMA_Photons[c_ST_PH_INPUT_CONTRAST]),
                3,
                channels_use),
            "Update_Step_Photons",
            "c_ST_PH_REGIONS_SEP_VIEW");
    }
        break;

    case c_ST_PH_REGIONS_LABEL:
    {
        ERR(D_Img_Proc::Math_ImgSelf_Not(
                &(vMA_Photons[c_ST_PH_REGIONS_LABEL]),
                &(vMA_Photons[c_ST_PH_REGIONS_CONNECT])),
            "Update_Step_Photons",
            "c_ST_PH_REGIONS_LABEL - D_Img_Proc::Math_ImgSelf_Not");

        ERR(D_Img_Proc::Labeling(
                &(vMA_Photons[c_ST_PH_REGIONS_LABEL]),
                &(vMA_Photons[c_ST_PH_REGIONS_LABEL]),
                4,
                CV_16U),
            "Update_Step_Photons",
            "c_ST_PH_REGIONS_LABEL - D_Img_Proc::Labeling");
    }
        break;

    case c_ST_PH_ROI_MITO:
    {
        ERR(D_Img_Proc::Math_ImgSelf_Not(
                &(vMA_Photons[c_ST_PH_ROI_MITO]),
                &(vMA_Photons[c_ST_PH_REGIONS_CONNECT])),
            "Update_Step_Photons",
            "c_ST_PH_ROI_MITO - D_Img_Proc::Math_ImgSelf_Not");

        ERR(D_Img_Proc::Math_ImgImg_BitAnd(
                &(vMA_Photons[c_ST_PH_ROI_MITO]),
                &(vMA_Photons[c_ST_PH_ROI_MITO]),
                &(vMA_Photons[c_ST_PH_BIN_THRES])),
            "Update_Step_Photons",
            "c_ST_PH_ROI_MITO - D_Img_Proc::Math_ImgImg_BitAnd");
    }
        break;

    default:
        break;
    }
}

void D_MAKRO_Mitochondrien::Update_Results_Proc()
{
    //check, if auto-update is blocekd (during stream)
    if(!Auto_ResultsProc_blocked)
        Update_Results_Proc_Force();
}

void D_MAKRO_Mitochondrien::Update_Results_Proc_Force()
{
    switch (ui->tabWidget_Results->currentIndex()) {

    case c_RT_IMAGE://================================================== Image
        switch (ui->comboBox_ResImg_Type->currentIndex()) {

        case c_RT_IMAGE_COLOR:
            Update_Combi_Results();
            break;

        case c_RT_IMAGE_MATH:
            Update_Math_Image();
            break;

        default:
            break;
        }
        break;

    case c_RT_PLOT://=================================================== Plot

        //stop when autoupdate plot is not wanted (to avoid solw plots slowing the img proc)
        if(!ui->action_Autoupdate_Plot_on_ImgProc->isChecked())
            return;

        ui->label_ResPlo_Information->setText("-");

        switch (ui->comboBox_ResPlo_Type->currentIndex()) {

        case c_RT_PLOT_HIST_IMG:
            Update_Plot_Hist_Img();
            break;

        case c_RT_PLOT_HIST_CELL:
            Update_Plot_Hist_Cells();
            break;

        case c_RT_PLOT_PAR_PIXEL:
            Update_Plot_Parameter_Pixel();
            break;

        case c_RT_PLOT_PAR_CELL:
            Update_Plot_Parameter_Cells();
            break;

        case c_RT_PLOT_STAT_MM:
            Update_Plot_Stat_MeanMedian();
            break;

        case c_RT_PLOT_STAT_CSK:
            Update_Plot_Stat_CvSkewKurt();
            break;

        case c_RT_PLOT_STAT_QUANT:
            Update_Plot_Stat_Quantiles();
            break;

        default:
            break;
        }

        Update_Style();

        break;

    default:
        break;
    }

    Update_Ui();
}

void D_MAKRO_Mitochondrien::Update_Step_Results(unsigned int step)
{
    switch (step) {

    case c_ST_RE_EMPTY:
    {
        vMA_Results[c_ST_RE_EMPTY] = Mat(vMA_Photons[1].size(), CV_8UC1, Scalar(0)).clone();
    }
        break;

    case c_ST_RE_PH_INPUT:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_RE_PH_INPUT]),
                &(vMA_Photons[c_ST_PH_INPUT_CONV_8bit])),
            "Update_Step_Results",
            "c_ST_RE_PH_INPUT");
    }
        break;

    case c_ST_RE_PH_CONTRAST:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_RE_PH_CONTRAST]),
                &(vMA_Photons[c_ST_PH_INPUT_CONTRAST])),
            "Update_Step_Results",
            "c_ST_RE_PH_CONTRAST");
    }
        break;

    case c_ST_RE_PH_BINARY:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_RE_PH_BINARY]),
                &(vMA_Photons[c_ST_PH_BIN_THRES])),
            "Update_Step_Results",
            "c_ST_RE_PH_BINARY");
    }
        break;

    case c_ST_RE_PH_EDGES:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_RE_PH_EDGES]),
                &(vMA_Photons[c_ST_PH_REGIONS_CONNECT])),
            "Update_Step_Results",
            "c_ST_RE_PH_EDGES");
    }
        break;

    case c_ST_RE_PH_LABEL_NUMBER:
    {
        ERR(D_Img_Proc::Draw_Label_Numbers(
                &(vMA_Results[c_ST_RE_PH_LABEL_NUMBER]),
                &(vMA_Photons[c_ST_PH_REGIONS_LABEL]),
                1,
                1,
                true),
            "Update_Step_Results",
            "c_ST_RE_PH_LABEL_NUMBER");
    }
        break;

    case c_ST_RE_PH_EDGES_NUMBER:
    {
        ERR(D_Img_Proc::Math_ImgImg_BitOr(
                &(vMA_Results[c_ST_RE_PH_EDGES_NUMBER]),
                &(vMA_Results[c_ST_RE_PH_LABEL_NUMBER]),
                &(vMA_Results[c_ST_RE_PH_EDGES])),
            "Update_Step_Results",
            "c_ST_RE_PH_EDGES_NUMBER");
    }
        break;

    default:
        break;
    }
}

void D_MAKRO_Mitochondrien::Update_Combi_Results()
{
    if(!param_set)
        return;
    qDebug() << "Update_Combi_Results";

    bool channels_use[4];
    channels_use[0] = true;
    channels_use[1] = true;
    channels_use[2] = true;
    channels_use[3] = false;

    Mat MA_tmp_B;
    Mat MA_tmp_G;
    Mat MA_tmp_R;

    if(ui->comboBox_Gra_B->currentIndex() < c_SC_RESULTS)
        MA_tmp_B = (vMA_Results[ui->comboBox_Gra_B->currentIndex()]).clone();
    else
    {
        if(ui->checkBox_ResCon_RoI_Only->isChecked())
            MA_tmp_B = (vMA_Parameter_RoI_8Bit[ui->comboBox_Gra_B->currentIndex() - c_SC_RESULTS]).clone();
        else
            MA_tmp_B = (vMA_Parameter_All_8Bit[ui->comboBox_Gra_B->currentIndex() - c_SC_RESULTS]).clone();
    }

    if(ui->comboBox_Gra_G->currentIndex() < c_SC_RESULTS)
        MA_tmp_G = (vMA_Results[ui->comboBox_Gra_G->currentIndex()]).clone();
    else
    {
        if(ui->checkBox_ResCon_RoI_Only->isChecked())
            MA_tmp_G = (vMA_Parameter_RoI_8Bit[ui->comboBox_Gra_G->currentIndex() - c_SC_RESULTS]).clone();
        else
            MA_tmp_G = (vMA_Parameter_All_8Bit[ui->comboBox_Gra_G->currentIndex() - c_SC_RESULTS]).clone();
    }

    if(ui->comboBox_Gra_R->currentIndex() < c_SC_RESULTS)
        MA_tmp_R = (vMA_Results[ui->comboBox_Gra_R->currentIndex()]).clone();
    else
    {
        if(ui->checkBox_ResCon_RoI_Only->isChecked())
            MA_tmp_R = (vMA_Parameter_RoI_8Bit[ui->comboBox_Gra_R->currentIndex() - c_SC_RESULTS]).clone();
        else
            MA_tmp_R = (vMA_Parameter_All_8Bit[ui->comboBox_Gra_R->currentIndex() - c_SC_RESULTS]).clone();
    }

    ERR(D_Img_Proc::Merge(
                &(MA_Color),
                &MA_tmp_B,
                &MA_tmp_G,
                &MA_tmp_R,
                &(vMA_Results[0]),
                3,
                channels_use),
            "Update_Combi_Results",
            "D_Img_Proc::Merge");

    MA_tmp_B.release();
    MA_tmp_G.release();
    MA_tmp_R.release();
    Update_View_Results();
}

void D_MAKRO_Mitochondrien::Update_Math_Image()
{
    if(!param_set)
        return;
    qDebug() << "Update_Math_Image";

    Mat MA_tmp_1;
    Mat MA_tmp_2;

    if(ui->checkBox_ResCon_RoI_Only->isChecked())
    {
        MA_tmp_1 = (vMA_Parameter_RoI_Float[ui->comboBox_Math_Par_1->currentIndex()]).clone();
        MA_tmp_2 = (vMA_Parameter_RoI_Float[ui->comboBox_Math_Par_2->currentIndex()]).clone();
    }
    else
    {
        MA_tmp_1 = (vMA_Parameter_All_Float[ui->comboBox_Math_Par_1->currentIndex()]).clone();
        MA_tmp_2 = (vMA_Parameter_All_Float[ui->comboBox_Math_Par_2->currentIndex()]).clone();
    }

    int comp_type;
    if(ui->comboBox_Math_Operator->currentIndex() > 6)
    switch (ui->comboBox_Math_Operator->currentIndex()) {
    case 7:     comp_type = CMP_EQ;                 break;
    case 8:     comp_type = CMP_GT;                 break;
    case 9:     comp_type = CMP_GE;                 break;
    case 10:    comp_type = CMP_LT;                 break;
    case 11:    comp_type = CMP_LE;                 break;
    case 12:    comp_type = CMP_NE;                 break;
    default:                                        break;}

    switch (ui->comboBox_Math_Operator->currentIndex()) {

    case 0://Add
        ERR(D_Img_Proc::Math_ImgImg_Add(
                &MA_Math,
                &MA_tmp_1,
                &MA_tmp_2),
            "Update_Math_Image",
            "Add");
        break;

    case 1://Diff
        ERR(D_Img_Proc::Math_ImgImg_Diff(
                &MA_Math,
                &MA_tmp_1,
                &MA_tmp_2),
            "Update_Math_Image",
            "Diff");
        break;

    case 2://Diff abs
        ERR(D_Img_Proc::Math_ImgImg_DiffAbs(
                &MA_Math,
                &MA_tmp_1,
                &MA_tmp_2),
            "Update_Math_Image",
            "Diff abs");
        break;

    case 3://Mult
        ERR(D_Img_Proc::Math_ImgImg_Mult(
                &MA_Math,
                &MA_tmp_1,
                &MA_tmp_2,
                1),
            "Update_Math_Image",
            "Mult");
        break;

    case 4://Div
        ERR(D_Img_Proc::Math_ImgImg_Div(
                &MA_Math,
                &MA_tmp_1,
                &MA_tmp_2,
                1),
            "Update_Math_Image",
            "Div");
        break;

    case 5://min
        ERR(D_Img_Proc::Math_ImgImg_Min(
                &MA_Math,
                &MA_tmp_1,
                &MA_tmp_2),
            "Update_Math_Image",
            "Min");
        break;

    case 6://max
        ERR(D_Img_Proc::Math_ImgImg_Max(
                &MA_Math,
                &MA_tmp_1,
                &MA_tmp_2),
            "Update_Math_Image",
            "Max");
        break;

    case 7: // ==
    case 8: // >
    case 9: // >=
    case 10:// <
    case 11:// <=
    case 12:// !=
        ERR(D_Img_Proc::Math_ImgImg_Comp(
                &MA_Math,
                &MA_tmp_1,
                &MA_tmp_2,
                comp_type),
            "Update_Math_Image",
            "Compare");
        break;

    default:
        break;
    }

    MA_tmp_1.release();
    MA_tmp_2.release();
    Update_View_Results();
}

void D_MAKRO_Mitochondrien::Update_Plot_Hist_Img()
{
    if(!param_set)
        return;
    //qDebug() << "Update_Plot_Hist";

    vector<double> v_hist;
    Mat MA_tmp_Hist;
    double min;
    double max;
    double step;

    if(ui->checkBox_ResCon_RoI_Only->isChecked())
        MA_tmp_Hist = (vMA_Parameter_RoI_Float[ui->comboBox_His_Image->currentIndex()]).clone();
    else
        MA_tmp_Hist = (vMA_Parameter_All_Float[ui->comboBox_His_Image->currentIndex()]).clone();


    int ER = D_Img_Proc::Calc_Hist_1C(
            &v_hist,
            &MA_tmp_Hist,
            ui->checkBox_His_Uniform->isChecked(),
            ui->checkBox_His_Accumulate->isChecked(),
            ui->spinBox_His_ClassCount->value(),
            &min,
            &max,
            &step);

    ERR(ER,
        "Update_Plot_Hist_Img",
        "D_Img_Proc::Calc_Hist");
    if(ER != ER_okay)
        return;

    D_Plot::Plot_Hist_Single_Classes(
                ChartView_Plot,
                &v_hist,
                min,
                step,
                QS_Image_BasePath.right(QS_Image_BasePath.lastIndexOf('/')),
                ui->comboBox_His_Image->currentText(),
                "Value in pixel",
                "Amount of pixels",
                true);

    MA_tmp_Hist.release();
}

void D_MAKRO_Mitochondrien::Update_Plot_Hist_Cells()
{
    if(!param_set || !Calc_Done)
        return;

    vector<vector<double>> vv_hist;
    double min_x;
    double max_x;
    double max_y;
    double step;

    ERR(D_Stat::Calc_Vector2Hist_2(
            &vv_hist,
            &(vvv_Data_ParNucPix[ui->comboBox_ParAll_Parameter->currentIndex()]),
            ui->spinBox_ParAll_ClassCount->value(),
            &min_x,
            &max_x,
            &max_y,
            &step,
            ui->checkBox_ParAll_Accumulate->isChecked(),
            ui->checkBox_ParAll_Uniform->isChecked()),
        "Update_Plot_Hist_Cells",
        "D_Stat::Calc_Vector2Hist_2");

    ERR(D_Plot::Plot_Hist_Multi_Classes(
            ChartView_Plot,
            &vv_hist,
            min_x,
            max_x,
            max_y,
            step,
            QS_Image_BasePath.right(QS_Image_BasePath.lastIndexOf('/')) + "<br>" + ui->comboBox_ParAll_Parameter->currentText(),
            "",
            "Value",
            "Amount",
            false),
        "Update_Plot_Hist_Cells",
        "D_Plot::Plot_Hist_Multi_Classes");

    Update_Ui();
}

void D_MAKRO_Mitochondrien::Update_Plot_Parameter_Pixel()
{
    if(!Calc_Done || !CB_Cells_Updated)
        return;
    qDebug() << "Update_Plot_Parameter_Dual";

    //Init_Plot();

    QString         cell_name   = ui->comboBox_Par_Nucleus->currentText();
    QString         x_name      = ui->comboBox_Par_X_Parameter->currentText();
    QString         y_name      = ui->comboBox_Par_Y_Parameter->currentText();

    unsigned int    cell        = ui->comboBox_Par_Nucleus->currentIndex();
    unsigned int    x_par       = ui->comboBox_Par_X_Parameter->currentIndex();
    unsigned int    y_par       = ui->comboBox_Par_Y_Parameter->currentIndex();

    int ER = D_Plot::Plot_Scatter_2D_Parameter(
            ChartView_Plot,
            &vvv_Data_ParNucPix,
            cell,
            x_par,
            y_par,
            QS_Image_BasePath.right(QS_Image_BasePath.lastIndexOf('/')),
            cell_name,
            x_name,
            y_name);

    if(ER == ER_size_missmatch)
    {
        QString error_x = x_name + "-size: " + QString::number(vvv_Data_ParNucPix[x_par][cell].size());
        QString error_y = y_name + "-size: " + QString::number(vvv_Data_ParNucPix[y_par][cell].size());
        ui->label_ResPlo_Information->setText(error_x + " - " + error_y + " - MISSMATCH! (Shown Plot might be incorrect)");
        ERR(
                    ER,
                    "Update_Plot_Parameter_Pixel",
                    "Plot_Scatter_2D_Parameter"
                    "<br>"
                    "<br>" + error_x +
                    "<br>" + error_y +
                    "<br>"
                    "<br>This probably happened, because you have selected 'ignore 0 parameters' and there are pixels in the selceted cell in which the fit resulted in pixel values of 0. Lists of unequal length can't be scattered."
                    "<br>"
                    "<br>In most cases there are two groups that work with themselves but not with members of the other group:"
                    "<br>1)'photons', 'NADH', 'NADPH', NADPHperNADH'"
                    "<br>2) other parameters");
    }
    else
    {
        ERR(
                    ER,
                    "Update_Plot_Parameter_Pixel",
                    "Plot_Scatter_2D_Parameter");
    }

    Update_Ui();
}

void D_MAKRO_Mitochondrien::Update_Plot_Parameter_Cells()
{
    if(!Calc_Done)
        return;

    //Init_Plot();

    QString         name_title  = QS_Image_BaseName;
    QString         x_name      = ui->comboBox_ParCell_X_Parameter->currentText() + " - " + ui->comboBox_ParCell_X_Stat->currentText();
    QString         y_name      = ui->comboBox_ParCell_Y_Parameter->currentText() + " - " + ui->comboBox_ParCell_Y_Stat->currentText();
    unsigned int    x_par       = ui->comboBox_ParCell_X_Parameter->currentIndex();
    unsigned int    y_par       = ui->comboBox_ParCell_Y_Parameter->currentIndex();
    unsigned int    x_stat      = ui->comboBox_ParCell_X_Stat->currentIndex();
    unsigned int    y_stat      = ui->comboBox_ParCell_Y_Stat->currentIndex();

    int ER = D_Plot::Plot_Stat_Multi_Custom(
                ChartView_Plot,
                &vvv_Stat_ParNucSta,
                x_par,
                y_par,
                x_stat,
                y_stat,
                name_title,
                "Cells",
                x_name,
                y_name);

    if(ER == ER_size_missmatch)
        ui->label_ResPlo_Information->setText(
                    x_name + "-size" + " & " +
                    y_name + "-size" +
                    " - MISSMATCH!");

    Update_Ui();
}



void D_MAKRO_Mitochondrien::Update_Plot_Stat_MeanMedian()
{
    if(!param_set || !Calc_Done)
        return;

    ERR(D_Plot::Plot_Stat_Multi_MeanMedian(
                ChartView_Plot,
                &(vvv_Stat_ParNucSta[ui->comboBox_Stat_MM_Parameter->currentIndex()]),
                ui->checkBox_Stat_MM_Mean->isChecked(),
                ui->checkBox_Stat_MM_SD->isChecked(),
                ui->checkBox_Stat_MM_Median->isChecked(),
                ui->checkBox_Stat_MM_ADM->isChecked(),
                QS_Image_BasePath.right(QS_Image_BasePath.lastIndexOf('/')) + "<br>" + ui->comboBox_Stat_MM_Parameter->currentText(),
                "Cells",
                "Unit of parameter"),
            "Update_Plot_Stat_MeanMedian",
            "D_Plot::Plot_Stat_Multi_MeanMedian");

    Update_Ui();
}

void D_MAKRO_Mitochondrien::Update_Plot_Stat_CvSkewKurt()
{
    if(!param_set || !Calc_Done)
        return;

    ERR(D_Plot::Plot_Stat_Multi_CvSkewKurt(
                ChartView_Plot,
                &(vvv_Stat_ParNucSta[ui->comboBox_Stat_CSK_Parameter->currentIndex()]),
                ui->checkBox_Stat_CSK_CV->isChecked(),
                ui->checkBox_Stat_CSK_Skewness->isChecked(),
                ui->checkBox_Stat_CSK_Kurtosis->isChecked(),
                QS_Image_BasePath.right(QS_Image_BasePath.lastIndexOf('/')) + "<br>" + ui->comboBox_Stat_CSK_Parameter->currentText(),
                "Cells",
                "1"),
            "Update_Plot_Stat_CvSkewKurt",
            "D_Plot::Plot_Stat_Multi_CvSkewKurt");

    Update_Ui();
}

void D_MAKRO_Mitochondrien::Update_Plot_Stat_Quantiles()
{
    if(!param_set || !Calc_Done)
        return;

    ERR(D_Plot::Plot_Stat_Multi_Quantiles(
                ChartView_Plot,
                &(vvv_Stat_ParNucSta[ui->comboBox_Stat_Quantiles_Parameter->currentIndex()]),
                ui->comboBox_Stat_Quantiles_Step->currentIndex(),
                QS_Image_BasePath.right(QS_Image_BasePath.lastIndexOf('/')) + "<br>" + ui->comboBox_Stat_Quantiles_Parameter->currentText(),
                "Cells",
                "Relative Position in Value Range"),
            "Update_Plot_Stat_Quantiles",
            "D_Plot::Plot_Stat_Multi_Quantiles");

    Update_Ui();
}


void D_MAKRO_Mitochondrien::Update_Views()
{
    Update_View_Photons();
    Update_View_Parameters();
    Update_View_Results();
    Update_Math_Image();
}

void D_MAKRO_Mitochondrien::Update_View_Photons()
{
    /*Update_View(
            &QI_Photons,
            &(vMA_Photons[ui->comboBox_PhoVie_Step->currentIndex()]),
            &PX_Photons,
            &SC_Photons,
            ui->graphicsView_Photons,
            &scale_factor_x_photons,
            &scale_factor_y_photons);*/

    Viewer_Photons.Update_Image(&(vMA_Photons[ui->comboBox_PhoVie_Step->currentIndex()]));

    ui->label_PhoVie_Format_MA->setText(Viewer_Photons.Type_MA());
    ui->label_PhoVie_Format_QI->setText(Viewer_Photons.Type_QI());

    //Set_Scale_Factor_View(&QI_Photons, ui->graphicsView_Photons);
}

void D_MAKRO_Mitochondrien::Update_View_Parameters()
{
    if(!param_set)
        return;

    Mat MA_ParView_tmp;

    if(ui->checkBox_ParVie_RoI_Only->isChecked())
    {
        MA_ParView_tmp = vMA_Parameter_RoI_Float[ui->comboBox_ParVie_Parameter->currentIndex()].clone();

        ui->label_ParVie_Format_MA->setText(D_Img_Proc::Type_of_Mat(&(vMA_Parameter_RoI_Float[ui->comboBox_ParVie_Parameter->currentIndex()])));
    }
    else
    {
        MA_ParView_tmp = vMA_Parameter_All_Float[ui->comboBox_ParVie_Parameter->currentIndex()].clone();

        ui->label_ParVie_Format_MA->setText(D_Img_Proc::Type_of_Mat(&(vMA_Parameter_All_Float[ui->comboBox_ParVie_Parameter->currentIndex()])));
    }

    if(ui->radioButton_ParVie_0_as_Min->isChecked())
        ERR(D_Img_Proc::Value_to_MinOrMax(
                &MA_ParView_tmp,
                &MA_ParView_tmp,
                0.0,
                true),
            "Update_View_Parameters",
            "D_Img_Proc::Value_to_MinOrMax - 0 as min");

    if(ui->radioButton_ParVie_0_as_Max->isChecked())
        ERR(D_Img_Proc::Value_to_MinOrMax(
                &MA_ParView_tmp,
                &MA_ParView_tmp,
                0.0,
                false),
            "Update_View_Parameters",
            "D_Img_Proc::Value_to_MinOrMax - 0 as max");

    if(ui->checkBox_ParVie_Contrast->isChecked())
    {
        ERR(D_Img_Proc::Normalize(
                &MA_ParView_tmp,
                &MA_ParView_tmp,
                CV_MINMAX,
                CV_8U,
                0,
                255),
            "Update_View_Parameters",
            "D_Img_Proc::Normalize");

        ERR(D_Img_Proc::Histo_Equal(
                &MA_ParView_tmp,
                &MA_ParView_tmp),
            "Update_View_Parameters",
            "D_Img_Proc::Histo_Equal");
    }

    Viewer_Parameters.Update_Image(&MA_ParView_tmp);

    /*Update_View(
            &QI_Parameters,
            &MA_ParView_tmp,
            &PX_Parameters,
            &SC_Parameters,
            ui->graphicsView_Parameter,
            &scale_factor_x_parameters,
            &scale_factor_y_parameters);*/

    MA_ParView_tmp.release();
}

void D_MAKRO_Mitochondrien::Update_View_Results()
{
    switch (ui->tabWidget_Results->currentIndex()) {

    case c_RT_IMAGE://================================================== Image
        switch (ui->comboBox_ResImg_Type->currentIndex()) {

        case c_RT_IMAGE_COLOR:
            Viewer_Results.Update_Image(&MA_Color);
            /*Update_View(
                    &QI_Results,
                    &MA_Color,
                    &PX_Results,
                    &SC_Results,
                    ui->graphicsView_Results,
                    &scale_factor_x_results,
                    &scale_factor_y_results);*/
            break;

        case c_RT_IMAGE_MATH:
            Viewer_Results.Update_Image(&MA_Math);
            /*Update_View(
                    &QI_Results,
                    &MA_Math,
                    &PX_Results,
                    &SC_Results,
                    ui->graphicsView_Results,
                    &scale_factor_x_results,
                    &scale_factor_y_results);*/
            break;

        default:
            break;
        }
        break;

    case c_RT_PLOT://=================================================== Plot
        switch (ui->comboBox_ResPlo_Type->currentIndex()) {

        case c_RT_PLOT_HIST_IMG:
            break;

        case c_RT_PLOT_HIST_CELL:
            break;

        case c_RT_PLOT_PAR_PIXEL:
            break;

        case c_RT_PLOT_PAR_CELL:
            break;

        case c_RT_PLOT_STAT_MM:
            break;

        case c_RT_PLOT_STAT_CSK:
            break;

        case c_RT_PLOT_STAT_QUANT:
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }
}


void D_MAKRO_Mitochondrien::Update_View(QImage *QI_Show, Mat *MA_Show, QPixmap *PX_Show, SceneMouseTrack *SC_Show, QGraphicsView *GV_Show, double *x_factor, double *y_factor)
{
    D_Img_Proc::Convert_Mat_to_QImage(QI_Show, MA_Show);

    Qt::TransformationMode Trans_Mode = Qt::FastTransformation;
    if(ui->action_Smooth_Transformation->isChecked())
        Trans_Mode = Qt::SmoothTransformation;

    Qt::AspectRatioMode Aspect_Mode = Qt::IgnoreAspectRatio;
    if(ui->action_Keep_Aspect_Ratio->isChecked())
        Aspect_Mode = Qt::KeepAspectRatio;

    *PX_Show = QPixmap::fromImage(*QI_Show);
    *PX_Show = PX_Show->scaled(
                GV_Show->width() - 2,
                GV_Show->height() - 2,
                Aspect_Mode,
                Trans_Mode);

    *x_factor = (double) PX_Show->width() / (double) QI_Show->width();
    *y_factor = (double) PX_Show->height() / (double) QI_Show->height();
    //qDebug() << "scale_factor:" << *x_factor << *y_factor;

    SC_Show->clear();
    SC_Show->addPixmap(*PX_Show);

    Update_Ui();
}

void D_MAKRO_Mitochondrien::Update_Ui()
{
    if(this->isEnabled())
        return;

    this->repaint();
    qApp->processEvents();
}

void D_MAKRO_Mitochondrien::Populate_CB_Style()
{
    // add items to theme combobox
    ui->comboBox_ResCon_Theme->addItem("Light", QChart::ChartThemeLight);
    ui->comboBox_ResCon_Theme->addItem("Blue Cerulean", QChart::ChartThemeBlueCerulean);
    ui->comboBox_ResCon_Theme->addItem("Dark", QChart::ChartThemeDark);
    ui->comboBox_ResCon_Theme->addItem("Brown Sand", QChart::ChartThemeBrownSand);
    ui->comboBox_ResCon_Theme->addItem("Blue NCS", QChart::ChartThemeBlueNcs);
    ui->comboBox_ResCon_Theme->addItem("High Contrast", QChart::ChartThemeHighContrast);
    ui->comboBox_ResCon_Theme->addItem("Blue Icy", QChart::ChartThemeBlueIcy);
    ui->comboBox_ResCon_Theme->addItem("Qt", QChart::ChartThemeQt);

    // add items to legend combobox
    ui->comboBox_ResCon_Legend->addItem("Legend Top", Qt::AlignTop);
    ui->comboBox_ResCon_Legend->addItem("Legend Bottom", Qt::AlignBottom);
    ui->comboBox_ResCon_Legend->addItem("Legend Left", Qt::AlignLeft);
    ui->comboBox_ResCon_Legend->addItem("Legend Right", Qt::AlignRight);
    ui->comboBox_ResCon_Legend->addItem("No Legend ", 0);
}

void D_MAKRO_Mitochondrien::Update_Style()
{
    //Get styles from combo boxes
    QChart::ChartTheme      theme       = static_cast<QChart::ChartTheme>       (ui->comboBox_ResCon_Theme->currentData().toInt());
    Qt::Alignment           alignment   = static_cast<Qt::Alignment>            (ui->comboBox_ResCon_Legend->currentData().toInt());

    //Apply styles
    ChartView_Plot->chart()->setTheme(theme);
    ChartView_Plot->chart()->legend()->setAlignment(alignment);

    //Apply Antialising Mode
    switch (ui->checkBox_ResCon_AA->checkState()) {
    case 0:
        ChartView_Plot->setRenderHint(QPainter::Antialiasing, false);
        ChartView_Plot->setRenderHint(QPainter::HighQualityAntialiasing, false);
        break;
    case 1:
        ChartView_Plot->setRenderHint(QPainter::Antialiasing, true);
        ChartView_Plot->setRenderHint(QPainter::HighQualityAntialiasing, false);
        break;
    case 2:
        ChartView_Plot->setRenderHint(QPainter::Antialiasing, false);
        ChartView_Plot->setRenderHint(QPainter::HighQualityAntialiasing, true);
        break;
    default:
        break;
    }
}

void D_MAKRO_Mitochondrien::Load_Directory()
{
    QString ST_Dir = QFileDialog::getExistingDirectory(
                this,
                "Select folder with .asc files to be analyzed",
                pStore->dir_M_Mitochondria()->path());

    if(ST_Dir == 0)
        return;

    DIR_Input_Dir.setPath(ST_Dir);
    pStore->set_dir_M_Mitochondria(ST_Dir);
    DIR_Stream.setPath(ST_Dir);

    QStringList QSL_Input_Images = DIR_Input_Dir.entryList();

    //find photon images
    ui->comboBox_AnalysedImage->clear();
    ui->comboBox_AnalysedImage->blockSignals(true);
    for(int i = 0; i < QSL_Input_Images.size(); i++)
    {
        QString ST_File = QSL_Input_Images.at(i);
        if(ST_File.endsWith("_photons.asc"))
        {
            FIL_Input_Images.append(QFileInfo(ST_Dir + "/" + ST_File));
            ui->comboBox_AnalysedImage->addItem(ST_Dir + "/" + ST_File);
        }
    }
    ui->comboBox_AnalysedImage->blockSignals(false);

    //find reference image
    Load_Reference();

    Init_Parameters();
    Update_ImgProc_All();
}

void D_MAKRO_Mitochondrien::Load_Images()
{
    QMessageBox MSG;
    MSG.setText("Error: Unable to load images.");

    if(FIL_Input_Images.empty())
    {
        MSG.setInformativeText("Image queue is empty.");
        MSG.exec();
        return;
    }

    ERR(D_Img_Proc::Load_From_Path_Text(
            &(vMA_Photons[c_ST_PH_LOAD]),
            FIL_Input_Images[ui->comboBox_AnalysedImage->currentIndex()].absoluteFilePath().toStdString()),
        "Load_Images",
        "D_Img_Proc::Load_From_Path_Text - Photons");

    //set info in statusbar
    L_SB_Size->setText(QString::number(vMA_Photons[c_ST_PH_LOAD].cols) + " x " + QString::number(vMA_Photons[c_ST_PH_LOAD].cols));

    QS_Image_BasePath   = FIL_Input_Images[ui->comboBox_AnalysedImage->currentIndex()].absoluteFilePath();
    QS_Image_BasePath   = QS_Image_BasePath.left(QS_Image_BasePath.lastIndexOf('_') + 1);
    qDebug() << "Base Path:\t" << QS_Image_BasePath;

    QS_Image_BaseName   = FIL_Input_Images[ui->comboBox_AnalysedImage->currentIndex()].baseName();
    QS_Image_BaseName   = QS_Image_BaseName.left(QS_Image_BaseName.lastIndexOf('_') + 1);
    qDebug() << "Base Name:\t" << QS_Image_BaseName;

    //read parameter images
    for(unsigned int p = 0; p < PARAMETERS_only_input; p++)
    {
        QFileInfo FI_Current;
        FI_Current.setFile(QS_Image_BasePath + QSL_Parameter_Suffixes[p] + ".asc");

        if(FI_Current.exists())
            {
                ERR(D_Img_Proc::Load_From_Path_Text(
                        &(vMA_Parameter_All_Float[p]),
                        FI_Current.absoluteFilePath().toStdString()),
                    "Load_Images",
                    "D_Img_Proc::Load_From_Path_Text - Parameters");
            }
            else
            {
                MSG.setInformativeText("Image " + FI_Current.absoluteFilePath() + " does not exist.");
                MSG.exec();
                //return;
            }
    }

    //create Settings dir if it does not exist yet
    DIR_CellSep.setPath(DIR_Input_Dir.path() + "/ImageD_CellSeparation");
    if(!DIR_CellSep.exists())
        QDir().mkdir(DIR_CellSep.path());

    //create cell sep dir for img if it does not exist yet
    DIR_CellSep_Img.setPath(DIR_CellSep.path() + "/" + QS_Image_BaseName);
    if(!DIR_CellSep_Img.exists())
        QDir().mkdir(DIR_CellSep_Img.path());

    //load cel_sep_img if exist
    FI_CellSep.setFile(DIR_CellSep_Img.path() + "/" + QS_Image_BaseName + "CellSeparation.png");
    if(FI_CellSep.exists())
    {
        ERR(D_Img_Proc::Load_From_Path(
                &(vMA_Photons[c_ST_PH_REGIONS_EDGES]),
                FI_CellSep.absoluteFilePath().toStdString()),
            "Load_Images",
            "D_Img_Proc::Load_From_Path - Separation");
        ManSep_FromFile = true;
    }
    else
    {
        ManSep_FromFile = false;
    }

    Norm_Parameters();
    Calc_NADPH_NADH_All();
    Convert_Parameters_8bit_All();
    Init_Cell_Regions();
}

void D_MAKRO_Mitochondrien::Clear_Queue()
{
    FIL_Input_Images.clear();
}

void D_MAKRO_Mitochondrien::Next_Image()
{
    if(ui->comboBox_AnalysedImage->currentIndex() >= (FIL_Input_Images.size() - 1))
    {
        QMessageBox MSG;
        MSG.setText("End of queue.");
        MSG.setInformativeText("Please load new images or select another image.");
        MSG.exec();
    }
    else
    {
        ui->comboBox_AnalysedImage->setCurrentIndex(ui->comboBox_AnalysedImage->currentIndex() + 1);
    }
}

void D_MAKRO_Mitochondrien::Save_Image_Photons()
{
    QString name_default =
            DIR_Stream.absolutePath() + "/" +
            QS_Image_BaseName + " - " +
            ui->comboBox_PhoVie_Step->currentText() +
            ".png";

    Save_Image(&Viewer_Photons, name_default);
}

void D_MAKRO_Mitochondrien::Save_Image_Parameters()
{
    QString name_default =
            QS_Image_BasePath.left(QS_Image_BasePath.lastIndexOf('_')) + " - " +
            ui->comboBox_ParVie_Parameter->currentText() +
            ".png";

    Save_Image(&Viewer_Parameters, name_default);
}

void D_MAKRO_Mitochondrien::Save_Image_Results()
{
    QString name_default;

    if(ui->comboBox_ResImg_Type->currentIndex() == 0)
        name_default =
                    QS_Image_BasePath.left(QS_Image_BasePath.lastIndexOf('_')) +
                    " - R " + ui->comboBox_Gra_R->currentText() +
                    " - G " + ui->comboBox_Gra_G->currentText() +
                    " - B " + ui->comboBox_Gra_B->currentText() +
                    ".png";
    else
        name_default =
                    QS_Image_BasePath.left(QS_Image_BasePath.lastIndexOf('_')) + " - " +
                    ui->comboBox_Math_Par_1->currentText() + " " +
                    ui->comboBox_Math_Operator->currentText() + " " +
                    ui->comboBox_Math_Par_2->currentText() +
                    ".png";

    Save_Image(&Viewer_Results, name_default);
}

void D_MAKRO_Mitochondrien::Save_Image(QImage *QI_Save, QString name_default)
{
    QString name_save;

    if(Auto_SaveName)
        name_save = name_default;
    else
        name_save = QFileDialog::getSaveFileName(this,
                                                 tr("Save image"),
                                                 name_default,
                                                 tr("Images (*.png *.bmp *.tif)"));
    if(name_save == 0)
        return;

    QI_Save->save(name_save);
    qDebug() << "Save File:    " << name_save;

    if(!Auto_SaveName)
        pStore->dir_M_Mitochondria()->setPath(name_save);
}

void D_MAKRO_Mitochondrien::Save_Image(D_Viewer *ViewerSave, QString name_default)
{
    QString name_save;

    if(Auto_SaveName)
        name_save = name_default;
    else
        name_save = QFileDialog::getSaveFileName(this,
                                                 tr("Save image"),
                                                 name_default,
                                                 tr("Images (*.png *.bmp *.tif)"));
    if(name_save == 0)
        return;

    ViewerSave->Save_Image(name_save);
    qDebug() << "Save File:    " << name_save;

    if(!Auto_SaveName)
        pStore->dir_M_Mitochondria()->setPath(name_save);
}

void D_MAKRO_Mitochondrien::Save_Plot()
{
    QString name_default = pStore->dir_M_Mitochondria()->absolutePath() + "/" +
                QS_Image_BasePath.left(QS_Image_BasePath.lastIndexOf('_')) + " - " +
                ui->comboBox_ResPlo_Type->currentText() + " - ";

    switch (ui->comboBox_ResPlo_Type->currentIndex()) {

    case c_RT_PLOT_HIST_IMG:
        name_default.append(
                    ui->comboBox_His_Image->currentText() + ".png");
        break;

    case c_RT_PLOT_HIST_CELL:
        name_default.append(
                    ui->comboBox_ParAll_Parameter->currentText() + ".png");
        break;

    case c_RT_PLOT_PAR_PIXEL:
        name_default.append(
                    ui->comboBox_Par_Nucleus->currentText() + " - " +
                    ui->comboBox_Par_Y_Parameter->currentText() + " vs " +
                    ui->comboBox_Par_X_Parameter->currentText() + ".png");
        break;

    case c_RT_PLOT_PAR_CELL:

        break;

    case c_RT_PLOT_STAT_MM:
        name_default.append(
                    ui->comboBox_Stat_MM_Parameter->currentText() + ".png");
        break;

    case c_RT_PLOT_STAT_CSK:
        name_default.append(
                    ui->comboBox_Stat_CSK_Parameter->currentText() + ".png");
        break;

    case c_RT_PLOT_STAT_QUANT:
        name_default.append(
                    ui->comboBox_Stat_Quantiles_Parameter->currentText() + ".png");
        break;
    default:
        break;
    }

    Save_Plot(ChartView_Plot, name_default);
}

void D_MAKRO_Mitochondrien::Save_Plot(QChartView *pCV_Save, QString name_default)
{
    QString name_save;

    if(Auto_SaveName)
        name_save = name_default;
    else
        name_save = QFileDialog::getSaveFileName(this,
                                                 tr("Save plot as image"),
                                                 name_default,
                                                 tr("Images (*.png *.bmp *.tif)"));
    if(name_save == 0)
        return;

    QPixmap pixmap_save = pCV_Save->grab();
    pixmap_save.save(name_save, 0, -1);
}

void D_MAKRO_Mitochondrien::Get_Click_Pos(int x, int y)
{
    qDebug() << "click at" << x << y;

    //draw?
    if(!ManSep_Manip)
        return;

    //scale
    //x /= ManSep_Scale_Factor;
    //y /= ManSep_Scale_Factor;

    /*//in range of image?
    int W = QI_Photons.width();
    int H = QI_Photons.height();
    if(x < 0 || x >= W || y < 0 || y >= H)
        return;*/

    //Save Points
    if(ManSep_Line_Begin)
    {
        ManSep_Pos_Last = QPoint(x, y);
        ManSep_Line_Begin = false;
    }
    else
    {
        ManSep_Pos_Last = ManSep_Pos_Curr;
    }
    ManSep_Pos_Curr = QPoint(x, y);

    //Draw
    if(ui->radioButton_PhoCon_Paint_Line->isChecked())
        Draw_Line();
    else
        Fill_Background();
}

void D_MAKRO_Mitochondrien::Draw_Line()
{
    qDebug() << "Draw_Line";

    if(!ManSep_Manip)
        return;

    //Backup last step
    MA_CellSep_Last = vMA_Photons[c_ST_PH_REGIONS_EDGES].clone();

    unsigned char val = 255;
    if(ui->comboBox_PhoCon_Paint_Color->currentIndex() != 0)
        val = 0;

    ERR(D_Img_Proc::Draw_Line(
            &(vMA_Photons[c_ST_PH_REGIONS_EDGES]),
            ManSep_Pos_Last.x(),
            ManSep_Pos_Last.y(),
            ManSep_Pos_Curr.x(),
            ManSep_Pos_Curr.y(),
            ui->spinBox_PhoCon_Paint_Thick->value(),
            val),
        "Draw_Line",
        "D_Img_Proc::Draw_Line");

    if(ui->action_Autoupdate_ImgProc_on_Paint->isChecked())
        Update_ImgProc_Photons(c_ST_PH_REGIONS_CONNECT);
    else
    {
        Update_Step_Photons(c_ST_PH_REGIONS_CONNECT);
        Update_Step_Photons(c_ST_PH_REGIONS_SEP_VIEW);
    }

    Export_Cell_Regions();

    Update_View_Photons();
}

void D_MAKRO_Mitochondrien::Fill_Background()
{
    qDebug() << "Fill_Background";

    if(!ManSep_Manip)
        return;

    //Backup last step
    MA_CellSep_Last = vMA_Photons[c_ST_PH_REGIONS_EDGES].clone();

    unsigned char val = 255;
    if(ui->comboBox_PhoCon_Paint_Color->currentIndex() != 0)
        val = 0;

    if(ui->comboBox_PhoCon_Paint_FillStep->currentIndex() == 0)
    {
        //Step 7
        Mat MA_tmp_filled;
        ERR(D_Img_Proc::Floodfill(
                &MA_tmp_filled,
                &(vMA_Photons[c_ST_PH_REGIONS_CONNECT]),
                ManSep_Pos_Curr.x(),
                ManSep_Pos_Curr.y(),
                val),
            "Fill_Background",
            "D_Img_Proc::Floodfill - Fill connected image");

        Mat MA_tmp_change;
        ERR(D_Img_Proc::Math_ImgImg_Diff(
                &MA_tmp_change,
                &MA_tmp_filled,
                &(vMA_Photons[c_ST_PH_REGIONS_CONNECT])),
            "Fill_Background",
            "D_Img_Proc::Floodfill - Get change due to the filling");

        ERR(D_Img_Proc::Math_ImgImg_BitOr(
                &(vMA_Photons[c_ST_PH_REGIONS_EDGES]),
                &(vMA_Photons[c_ST_PH_REGIONS_EDGES]),
                &MA_tmp_change),
            "Fill_Background",
            "D_Img_Proc::Floodfill - Save change in edges and export later");

        MA_tmp_change.release();
        MA_tmp_filled.release();
    }
    else
    {
        //Step 6
        ERR(D_Img_Proc::Floodfill(
                &(vMA_Photons[c_ST_PH_REGIONS_EDGES]),
                &(vMA_Photons[c_ST_PH_REGIONS_EDGES]),
                ManSep_Pos_Curr.x(),
                ManSep_Pos_Curr.y(),
                val),
            "Fill_Background",
            "D_Img_Proc::Floodfill - fill unconnected image");
    }

    if(ui->action_Autoupdate_ImgProc_on_Paint->isChecked())
        Update_ImgProc_Photons(c_ST_PH_REGIONS_CONNECT);
    else
    {
        Update_Step_Photons(c_ST_PH_REGIONS_CONNECT);
        Update_Step_Photons(c_ST_PH_REGIONS_SEP_VIEW);
    }

    Export_Cell_Regions();

    Update_View_Photons();
}

void D_MAKRO_Mitochondrien::CellSep_Undo()
{
    qDebug() << "CellSep_Undo";
    vMA_Photons[c_ST_PH_REGIONS_EDGES] = MA_CellSep_Last.clone();

    if(ui->action_Autoupdate_ImgProc_on_Paint->isChecked())
        Update_ImgProc_Photons(c_ST_PH_REGIONS_CONNECT);
    else
    {
        Update_Step_Photons(c_ST_PH_REGIONS_CONNECT);
        Update_Step_Photons(c_ST_PH_REGIONS_SEP_VIEW);
    }

    Export_Cell_Regions();

    Update_View_Photons();
}

void D_MAKRO_Mitochondrien::CellSep_Load()
{
    QFileInfo FI_Load(
            FI_CellSep.absolutePath() + "/" +
            FI_CellSep.baseName() + "_" +
            ui->lineEdit_PhoCon_Preset->text() + ".png");

    qDebug() << FI_Load.absoluteFilePath();

    if(FI_Load.exists())
    {
        qDebug() << "Load CellSep:\t" << FI_Load.absoluteFilePath();
        QImage QI_tmp_load = QImage(FI_Load.absoluteFilePath());
        QI_tmp_load.save(FI_CellSep.absoluteFilePath(), 0, -1);

        ManSep_FromFile = true;
        Init_Cell_Regions();

        if(ui->action_Autoupdate_ImgProc_on_Paint->isChecked())
            Update_ImgProc_Photons(c_ST_PH_REGIONS_CONNECT);
        else
        {
            Update_Step_Photons(c_ST_PH_REGIONS_CONNECT);
            Update_Step_Photons(c_ST_PH_REGIONS_SEP_VIEW);
        }
    }
    else
    {
        QMessageBox MSG;
        MSG.setText("File does not exist.");
        MSG.setInformativeText(FI_Load.absoluteFilePath());
        MSG.exec();
    }
}

void D_MAKRO_Mitochondrien::CellSep_Save()
{
    QFileInfo FI_Save(
            FI_CellSep.absolutePath() + "/" +
            FI_CellSep.baseName() + "_" +
            ui->lineEdit_PhoCon_Preset->text() + ".png");

    //qDebug() << FI_Save.absoluteFilePath();

    if(FI_Save.exists())
    {
        QMessageBox MSG;
        MSG.setText("Overwrite file?");
        MSG.setInformativeText(FI_Save.absoluteFilePath());
        MSG.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        MSG.setDefaultButton(QMessageBox::No);

        if(MSG.exec() == QMessageBox::No)
            return;
    }

    QImage QI_tmp_save;

    ERR(D_Img_Proc::Convert_Mat_to_QImage(
            &(QI_tmp_save),
            &(vMA_Photons[c_ST_PH_REGIONS_EDGES])),
        "CellSep_Save",
        "D_Img_Proc::Convert_Mat_to_QImage");

    qDebug() << "Save CellSep:\t" << FI_Save.absoluteFilePath();
    QI_tmp_save.save(FI_Save.absoluteFilePath(), 0, -1);
}

void D_MAKRO_Mitochondrien::CellSep_Open()
{
    QString path = FI_CellSep.absolutePath();
    qDebug() << path;
    QDesktopServices::openUrl(path);
}


void D_MAKRO_Mitochondrien::Set_Scale_Factor_View(QImage *QI, QGraphicsView *GV)
{
    double W_QI = QI->width();
    double H_QI = QI->height();
    double W_GV = GV->width() - 2;
    double H_GV = GV->height() - 2;
    double W_scale = W_GV / W_QI;
    double H_scale = H_GV / H_QI;

    if(W_scale < H_scale)
        ManSep_Scale_Factor = W_scale;
    else
        ManSep_Scale_Factor = H_scale;
}

void D_MAKRO_Mitochondrien::Init_Cell_Regions()
{
    ManSep_Line_Begin = true;

    if(ManSep_FromFile)
        ERR(D_Img_Proc::Load_From_Path(
                &(vMA_Photons[c_ST_PH_REGIONS_EDGES]),
                FI_CellSep.absoluteFilePath().toStdString()),
            "Init_Cell_Regions",
            "D_Img_Proc::Load_From_Path");
    else
    {
        vMA_Photons[c_ST_PH_REGIONS_EDGES] = Mat(vMA_Photons[c_ST_PH_LOAD].size(), CV_8UC1, Scalar(0));

        unsigned int w = vMA_Photons[c_ST_PH_REGIONS_EDGES].cols - 1;
        unsigned int h = vMA_Photons[c_ST_PH_REGIONS_EDGES].rows - 1;

        ERR(D_Img_Proc::Draw_Rect(&(vMA_Photons[c_ST_PH_REGIONS_EDGES]), 0, 0, w, h, 1, 255),
            "Init_Cell_Regions",
            "D_Img_Proc::Draw_Rect");
    }

    MA_CellSep_Last = vMA_Photons[c_ST_PH_REGIONS_EDGES];
}

void D_MAKRO_Mitochondrien::Export_Cell_Regions()
{
    if(ui->action_Autosave_CellSep_in_Img->isChecked())
    {
        ui->action_Autoselect_Save_Filename->setChecked(true);
        Auto_SaveName = true;

        QImage QI_tmp_save;

        ERR(D_Img_Proc::Convert_Mat_to_QImage(
                &(QI_tmp_save),
                &(vMA_Photons[c_ST_PH_REGIONS_EDGES])),
            "Export_Cell_Regions",
            "D_Img_Proc::Convert_Mat_to_QImage");

        Save_Image(&QI_tmp_save, DIR_CellSep_Img.path() + "/" + QS_Image_BaseName + "CellSeparation.png");
    }
}

void D_MAKRO_Mitochondrien::Update_SB_ValAtPos(int x, int y, Mat *pMA)
{
    //in range?
    if(x < 0 || x >= pMA->cols || y < 0 || y >= pMA->rows)
        return;

    QString QS_val;

    D_Img_Proc::ValAtPix(
            &QS_val,
            pMA,
            x,
            y);

    L_SB_ValAtPos->setText(QS_val);
}

void D_MAKRO_Mitochondrien::AdaptUI_NADH_p_NADPH_MinMax()
{
    double t2_thres_low     = ui->doubleSpinBox_ParCon_T2_Min_Thres->value();
    double t2_thres_high    = ui->doubleSpinBox_ParCon_T2_Max_Thres->value();

    double t2_const_low     = ui->doubleSpinBox_ParCon_T2_Min_Const->value();
    double t2_const_high    = ui->doubleSpinBox_ParCon_T2_Max_Const->value();

    double result_high      = (t2_thres_high - t2_const_low)/(t2_const_high - t2_thres_high);
    double result_low       = (t2_thres_low  - t2_const_low)/(t2_const_high - t2_thres_low );

    ui->label_ParCon_T2_NADH_NADPH_ValHigh->setText(QString::number(result_high));
    ui->label_ParCon_T2_NADH_NADPH_ValLow->setText(QString::number(result_low));
}

void D_MAKRO_Mitochondrien::AdaptUI_Results()
{
    bool plot = false;
    bool ignore0_ROIonly = false;

    if(ui->tabWidget_Results->currentIndex() == 1)
    {
        plot = true;
        if(ui->comboBox_ResPlo_Type->currentIndex() != 0)
            ignore0_ROIonly = true;
    }

    ui->checkBox_ResCon_Ignore_Zero->setEnabled(ignore0_ROIonly);
    ui->checkBox_ResCon_RoI_Only->setEnabled(ignore0_ROIonly);

    ui->checkBox_ResCon_AA->setEnabled(plot);
    ui->comboBox_ResCon_Theme->setEnabled(plot);
    ui->comboBox_ResCon_Rubberband->setEnabled(plot);
    ui->comboBox_ResCon_Legend->setEnabled(plot);
    ui->label_ResCon_Zoom->setEnabled(plot);
    ui->pushButton_RessCon_Zoom_In->setEnabled(plot);
    ui->pushButton_ResCon_Zoom_Out->setEnabled(plot);
    ui->pushButton_ResCon_Zoom_Reset->setEnabled(plot);
}

void D_MAKRO_Mitochondrien::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_MAKRO_Mitochondria", func, detail);
}

void D_MAKRO_Mitochondrien::Init_Parameters()
{
    if(param_set)
        return;

    Read_Parameters_From_UI();
    Populate_CB_Parameters();
    Init_vMA_Parameter();

    ui->groupBox_ParCon_Suffix->setEnabled(false);
    ui->groupBox_ParCon_View->setEnabled(true);
    ui->groupBox_Photons_Controls->setEnabled(true);
    ui->groupBox_Photons_View->setEnabled(true);

    ui->groupBox_Parameters_View->setEnabled(true);
    ui->groupBox_Results_View->setEnabled(true);
    ui->groupBox_Results_Controls->setEnabled(true);

    ui->stackedWidget_ResImg_Type->setEnabled(true);
    ui->stackedWidget_ResPlo_Type->setEnabled(true);



    param_set = true;
}

void D_MAKRO_Mitochondrien::Read_Parameters_From_UI()
{
    //read from ui
    QString QS_Suffixes = ui->plainTextEdit_ParCon_Suffixes->toPlainText();
    QSL_Parameter_Suffixes = QS_Suffixes.split("\n");

    //add photons as input
    QSL_Parameter_Suffixes.push_front("photons");

    //check if NADH, NADPH and NADH/NADPH can be calced
    PARAMETERS_only_input = QSL_Parameter_Suffixes.size();
    Check_Parameter_Existence();
    PARAMETERS = QSL_Parameter_Suffixes.size();
}

void D_MAKRO_Mitochondrien::Populate_CB_Parameters()
{
    ui->comboBox_ParVie_Parameter->addItems(QSL_Parameter_Suffixes);

    ui->comboBox_Gra_R->addItems(QSL_Parameter_Suffixes);
    ui->comboBox_Gra_G->addItems(QSL_Parameter_Suffixes);
    ui->comboBox_Gra_B->addItems(QSL_Parameter_Suffixes);

    ui->comboBox_His_Image->addItems(QSL_Parameter_Suffixes);

    ui->comboBox_Par_X_Parameter->addItems(QSL_Parameter_Suffixes);
    ui->comboBox_Par_Y_Parameter->addItems(QSL_Parameter_Suffixes);

    ui->comboBox_ParAll_Parameter->addItems(QSL_Parameter_Suffixes);

    ui->comboBox_Math_Par_1->addItems(QSL_Parameter_Suffixes);
    ui->comboBox_Math_Par_2->addItems(QSL_Parameter_Suffixes);

    ui->comboBox_Stat_CSK_Parameter->addItems(QSL_Parameter_Suffixes);
    ui->comboBox_Stat_MM_Parameter->addItems(QSL_Parameter_Suffixes);
    ui->comboBox_Stat_Quantiles_Parameter->addItems(QSL_Parameter_Suffixes);

    ui->comboBox_ParCell_X_Parameter->addItems(QSL_Parameter_Suffixes);
    ui->comboBox_ParCell_Y_Parameter->addItems(QSL_Parameter_Suffixes);
}

void D_MAKRO_Mitochondrien::Init_vMA_Parameter()
{
    Init_MatVector(&vMA_Parameter_All_Float, PARAMETERS);
    Init_MatVector(&vMA_Parameter_All_8Bit, PARAMETERS);
    Init_MatVector(&vMA_Parameter_RoI_Float, PARAMETERS);
    Init_MatVector(&vMA_Parameter_RoI_8Bit, PARAMETERS);
}

void D_MAKRO_Mitochondrien::Load_Reference()
{
    FI_Reference = QFileInfo(DIR_Input_Dir.absolutePath() + "/" + "reference_image.asc");

    if(!FI_Reference.exists())
        FI_Reference.setFile(DIR_Input_Dir.absolutePath() + "/" + "Reference_Image.asc");

    if(!FI_Reference.exists())
        FI_Reference.setFile(DIR_Input_Dir.absolutePath() + "/" + "reference.asc");

    if(!FI_Reference.exists())
        FI_Reference.setFile(DIR_Input_Dir.absolutePath() + "/" + "Reference.asc");

    if(!FI_Reference.exists())
        FI_Reference.setFile(DIR_Input_Dir.absolutePath() + "/" + "ReferenceImage.asc");

    if(!FI_Reference.exists())
        FI_Reference.setFile(
                    QFileDialog::getOpenFileName(
                        this,
                        tr("Please select a refernece_image.asc"),
                        FI_Reference.path(),
                        tr("Text image file (*.asc)")));


    if(!FI_Reference.exists())
    {
        ERR(
                    ER_empty,
                    "Load_Reference",
                    "No Reference Image found!");
        return;
    }

    ERR(D_Img_Proc::Load_From_Path_Text(
            &MA_Reference,
            FI_Reference.absoluteFilePath().toStdString()),
        "Load_Reference",
        "D_Img_Proc::Load_From_Path_Text - Reference Image found");
    Exist_Refernce = true;
}

void D_MAKRO_Mitochondrien::Populate_CB_Cells()
{
    if(!Calc_Done)
        return;
    qDebug() << "Populate_CB_Cells";

    ui->comboBox_Par_Nucleus->clear();

    for(unsigned int c = 0; c < CellCount; c++)
    {
        ui->comboBox_Par_Nucleus->addItem("Cell " + QString::number(c));
    }

    CB_Cells_Updated = true;
}

void D_MAKRO_Mitochondrien::Populate_CB_Stat()
{
    Populate_CB_Single(ui->comboBox_ParCell_X_Stat, QSL_StatList, c_STAT_MEAN_ARITMETIC);
    Populate_CB_Single(ui->comboBox_ParCell_Y_Stat, QSL_StatList, c_STAT_MEAN_ARITMETIC);
}

void D_MAKRO_Mitochondrien::Check_Parameter_Existence()
{
    //check existence
    Exist_photons = QSL_Parameter_Suffixes.contains("photons");
    Exist_a1 = QSL_Parameter_Suffixes.contains("a1[%]");
    Exist_a2 = QSL_Parameter_Suffixes.contains("a2[%]");
    Exist_t1 = QSL_Parameter_Suffixes.contains("t1");
    Exist_t2 = QSL_Parameter_Suffixes.contains("t2");
    Exist_chi = QSL_Parameter_Suffixes.contains("chi");

    //eneable t2-control if needed
    ui->groupBox_ParCon_T2->setEnabled(Exist_t2);

    //read indicies
    if(Exist_photons)   INDEX_PHOTONS   = QSL_Parameter_Suffixes.indexOf("photons");
    if(Exist_a1)        INDEX_A1        = QSL_Parameter_Suffixes.indexOf("a1[%]");
    if(Exist_a2)        INDEX_A2        = QSL_Parameter_Suffixes.indexOf("a2[%]");
    if(Exist_t1)        INDEX_T1        = QSL_Parameter_Suffixes.indexOf("t1");
    if(Exist_t2)        INDEX_T2        = QSL_Parameter_Suffixes.indexOf("t2");
    if(Exist_chi)       INDEX_CHI       = QSL_Parameter_Suffixes.indexOf("chi");
    //qDebug() << "photons:" << INDEX_PHOTONS << "- a2:" << INDEX_A2 << "- t1:" << INDEX_T1 << "- t2:" << INDEX_T2;

    //append more "parameters"
    if(Exist_t2)
    {
        QSL_Parameter_Suffixes.push_back("NADPHperNADH");
        INDEX_NADPH_NADH = QSL_Parameter_Suffixes.size() - 1;
    }

    if(Exist_photons && Exist_a2 && Exist_t1 && Exist_t2)
    {
        QSL_Parameter_Suffixes.push_back("NADPH");
        INDEX_NADPH = QSL_Parameter_Suffixes.size() - 1;

        QSL_Parameter_Suffixes.push_back("NADH");
        INDEX_NADH = QSL_Parameter_Suffixes.size() - 1;
    }
}

void D_MAKRO_Mitochondrien::Norm_Parameters()
{
    if(Exist_a1)
        ERR(D_Img_Proc::Math_ImgScal_Div(
                &(vMA_Parameter_All_Float[INDEX_A1]),
                &(vMA_Parameter_All_Float[INDEX_A1]),
                100.0),
            "Norm_Parameters",
            "a1");

    if(Exist_a2)
        ERR(D_Img_Proc::Math_ImgScal_Div(
                &(vMA_Parameter_All_Float[INDEX_A2]),
                &(vMA_Parameter_All_Float[INDEX_A2]),
                100.0),
            "Norm_Parameters",
            "a2");

    if(Exist_t1)
        ERR(D_Img_Proc::Math_ImgScal_Div(
                &(vMA_Parameter_All_Float[INDEX_T1]),
                &(vMA_Parameter_All_Float[INDEX_T1]),
                1000.0),
            "Norm_Parameters",
            "t1");

    if(Exist_t2)
        ERR(D_Img_Proc::Math_ImgScal_Div(
                &(vMA_Parameter_All_Float[INDEX_T2]),
                &(vMA_Parameter_All_Float[INDEX_T2]),
                1000.0),
            "Norm_Parameters",
            "t2");

    if(Exist_chi)
        ERR(D_Img_Proc::Value_to_Value(
                &(vMA_Parameter_All_Float[INDEX_CHI]),
                &(vMA_Parameter_All_Float[INDEX_CHI]),
                1000000.0,
                0.0),
            "Norm_Parameters",
            "chi");

}

void D_MAKRO_Mitochondrien::Calc_Data_All()
{
    if(!param_set)
        return;
    qDebug() << "Calc_Data_All====================================";

    Calc_Done = false;
    CB_Cells_Updated = false;
    Calced_NADPH_NADH = false;

    int ER;

    ER = Calc_Data_Split_Img2vv();
    ERR(ER,
        "Calc_Data_All",
        "Calc_Data_Split_Img2vv");
    if(ER != ER_okay)
        return;

    Calc_Data_Parameter_Stats();

    //export meta data
    CellCount = (unsigned int)vvv_Data_ParNucPix[0].size();

    //if successfull, set calc_done to true
    Calc_Done = true;

    Populate_CB_Cells();

    Calc_NADPH_NADH();
}

int D_MAKRO_Mitochondrien::Calc_Data_Split_Img2vv()
{
    vvv_Data_ParNucPix.clear();

    for(unsigned int p = 0; p < PARAMETERS; p++)
    {
        //temp vector of current parameter split to cells
        vector<vector<double>> vv_Data_NucPar;

        int ER;

        //qDebug() << "Split Parameter:" << p;
        if(ui->checkBox_ResCon_RoI_Only->isChecked())
            ER = D_Img_Proc::Split_img2vv_value(
                    &vv_Data_NucPar,
                    &(vMA_Parameter_RoI_Float[p]),
                    &(vMA_Photons[c_ST_PH_REGIONS_LABEL]),
                    ui->checkBox_ResCon_Ignore_Zero->isChecked());
        else
            ER = D_Img_Proc::Split_img2vv_value(
                    &vv_Data_NucPar,
                    &(vMA_Parameter_All_Float[p]),
                    &(vMA_Photons[c_ST_PH_REGIONS_LABEL]),
                    ui->checkBox_ResCon_Ignore_Zero->isChecked());

        ERR(ER,
            "Calc_Data_Split_Img2vv",
            "D_Img_Proc::Split_img2vv_value");
        if(ER != ER_okay)
            return ER;

        vvv_Data_ParNucPix.push_back(vv_Data_NucPar);
    }

    return ER_okay;
}


void D_MAKRO_Mitochondrien::Calc_Data_Parameter_Stats()
{
    vvv_Stat_ParNucSta.clear();

    for(unsigned int p = 0; p < PARAMETERS; p++)
    {
        //temp vector of current parameter split to cells
        vector<vector<double>> vv_Stat_NucPar;

        for(unsigned int nuc = 0; nuc < vvv_Data_ParNucPix[0].size(); nuc++)
        {
            //CELL loop
            vector<double> v_Stat_Nuc;

            //qDebug() << "Calc Stats Cell:" << nuc;
            int ER = D_Stat::Calc_Stats(
                        &v_Stat_Nuc,
                        vvv_Data_ParNucPix[p][nuc],
                        true);
            //ERR(ER);
            if(ER != ER_okay)
                qDebug() << "!!!===!!!===!!!===ERROR===!!!===!!!===!!!" << "Cell:" << nuc;

            vv_Stat_NucPar.push_back(v_Stat_Nuc);

        }

        vvv_Stat_ParNucSta.push_back(vv_Stat_NucPar);
    }
}

void D_MAKRO_Mitochondrien::Calc_T2_Handling()
{
    Calc_NADPH_NADH_All();
    Convert_Parameters_8bit_All();
    Update_ImgProc_Parameters();
}

void D_MAKRO_Mitochondrien::Calc_NADPH_NADH_All()
{
    Calc_NADH();
    Calc_NADPH();
    Calc_NADPH_NADH();
}

void D_MAKRO_Mitochondrien::Calc_NADH()
{
    Calced_NADH = false;
    if(!Exist_photons || !Exist_a2 || !Exist_t1 || !Exist_t2)
        return;

    ERR(D_Img_Proc::Math_Special_NADH(
            &(vMA_Parameter_All_Float[INDEX_NADH]),
            &(vMA_Parameter_All_Float[INDEX_PHOTONS]),
            &(vMA_Parameter_All_Float[INDEX_A2]),
            &(vMA_Parameter_All_Float[INDEX_T1]),
            &(vMA_Parameter_All_Float[INDEX_T2]),
            1.0,
            true,
            ui->doubleSpinBox_ParCon_T2_Max_Thres->value(),
            ui->doubleSpinBox_ParCon_T2_Max_Const->value()),
        "Calc_NADH",
        "D_Img_Proc::Math_Special_NADH");

    Calced_NADH = true;
}

void D_MAKRO_Mitochondrien::Calc_NADPH()
{
    Calced_NADPH = false;
    if(!Exist_photons || !Exist_a2 || !Exist_t1 || !Exist_t2)
        return;

    ERR(D_Img_Proc::Math_Special_NADPH(
            &(vMA_Parameter_All_Float[INDEX_NADPH]),
            &(vMA_Parameter_All_Float[INDEX_PHOTONS]),
            &(vMA_Parameter_All_Float[INDEX_A2]),
            &(vMA_Parameter_All_Float[INDEX_T1]),
            &(vMA_Parameter_All_Float[INDEX_T2]),
            1.0,
            true,
            ui->doubleSpinBox_ParCon_T2_Min_Thres->value(),
            ui->doubleSpinBox_ParCon_T2_Min_Const->value()),
        "Calc_NADPH",
        "D_Img_Proc::Math_Special_NADPH");

    Calced_NADPH = true;
}

void D_MAKRO_Mitochondrien::Calc_NADPH_NADH()
{
    Calced_NADPH_NADH = false;
    if(!Exist_t2)
        return;

    ERR(D_Img_Proc::Math_Special_NADPH_NADH(
            &(vMA_Parameter_All_Float[INDEX_NADPH_NADH]),
            &(vMA_Parameter_All_Float[INDEX_T2]),
            true,
            ui->doubleSpinBox_ParCon_T2_Min_Thres->value(),
            ui->doubleSpinBox_ParCon_T2_Max_Thres->value(),
            ui->doubleSpinBox_ParCon_T2_Min_Const->value(),
            ui->doubleSpinBox_ParCon_T2_Max_Const->value()),
        "Calc_NADPH_NADH",
        "D_Img_Proc::Math_Special_NADPH_NADH");

    Calced_NADPH_NADH = true;
}

void D_MAKRO_Mitochondrien::Stream_Stats_Start()
{
    if(Stream_Open || !param_set)
        return;

    QString ST_Dir = QFileDialog::getExistingDirectory(
                this,
                "Select folder to stream the output to.",
                DIR_Input_Dir.path());

    if(ST_Dir == 0)
        return;

    //create subfolder for output
    unsigned int count = 0;
    QString QS_Folder_Out_Sub = ST_Dir + "/Results_0";
    while(QDir(QS_Folder_Out_Sub).exists())
    {
        count++;
        QS_Folder_Out_Sub = ST_Dir + "/Results_" + QString::number(count);
    }
    QDir().mkdir(QS_Folder_Out_Sub);

    DIR_Stream.setPath(QS_Folder_Out_Sub);

    //=========================start stream

    QString ST_Stream_Summary = DIR_Stream.path() + "/Summary.csv";
    OS_Stream_Summary.open(ST_Stream_Summary.toStdString());
    OS_Stream_Summary << fixed << setprecision(6) << showpoint;

    QString ST_Stream_Par_BasePath = DIR_Stream.path() + "/Parameter_";
    OS_Stream_Parameters.clear();
    OS_Stream_Parameters.resize(PARAMETERS);
    for(unsigned int p = 0; p < PARAMETERS; p++)
    {
        OS_Stream_Parameters[p] << fixed << setprecision(6) << showpoint;
        QString ST_Stream_Par_Current = ST_Stream_Par_BasePath + QSL_Parameter_Suffixes[p] + ".csv";
        OS_Stream_Parameters[p].open(ST_Stream_Par_Current.toStdString());
    }

    Stream_Open = true;

    Stream_Init();
}

void D_MAKRO_Mitochondrien::Stream_Init()
{
    //===================Summary

    OS_Stream_Summary << "Summary\n";
    OS_Stream_Summary << "\n";
    OS_Stream_Summary << ",,,Pixels";

    for(unsigned int p = 0; p < PARAMETERS; p++)
    {
        QString ST_Current_Par = QSL_Parameter_Suffixes[p];
        OS_Stream_Summary << ",," << ST_Current_Par.toStdString() << "," << ST_Current_Par.toStdString();
    }

    OS_Stream_Summary << "\n" <<
                         "Image," <<
                         "Cell,," <<

                         "Pixels";

    for(unsigned int p = 0; p < PARAMETERS; p++)
        OS_Stream_Summary << ",,Mean,Median";

    OS_Stream_Summary << "\n";

    //===================Parameters

    for(unsigned int p = 0; p < PARAMETERS; p++)
    {
        QString ST_Current_Suffix = QSL_Parameter_Suffixes[p];
        OS_Stream_Parameters[p] << "Parameter: " << ST_Current_Suffix.toStdString() << "\n\n";

        OS_Stream_Parameters[p] << "Image," <<
                                   "Cell,," <<

                                   "Mean," <<
                                   "Stan_Dev," <<
                                   "Median," <<
                                   "Abs_Dev_Med,"  <<
                                   "Dist 90%,," <<

                                   "Pixels," <<
                                   "Mean," <<
                                   "Variance," <<
                                   "Skewness," <<
                                   "Kurtosis," <<
                                   "Stan_Dev," <<
                                   "Var_Coef,," <<

                                   "Quantil 00%," <<
                                   "Quantil 05%," <<
                                   "Quantil 10%," <<
                                   "Quantil 15%," <<
                                   "Quantil 20%," <<
                                   "Quantil 25%," <<
                                   "Quantil 30%," <<
                                   "Quantil 35%," <<
                                   "Quantil 40%," <<
                                   "Quantil 45%," <<
                                   "Quantil 50%," <<
                                   "Quantil 55%," <<
                                   "Quantil 60%," <<
                                   "Quantil 65%," <<
                                   "Quantil 70%," <<
                                   "Quantil 75%," <<
                                   "Quantil 80%," <<
                                   "Quantil 85%," <<
                                   "Quantil 90%," <<
                                   "Quantil 95%," <<
                                   "Quantil 100%,," <<

                                   "Dist 100%," <<
                                   "Dist 90%," <<
                                   "Dist 80%," <<
                                   "Dist 70%," <<
                                   "Dist 60%," <<
                                   "Dist 50%," <<
                                   "Dist 40%," <<
                                   "Dist 30%," <<
                                   "Dist 20%," <<
                                   "Dist 10%,\n";

        OS_Stream_Parameters[p] << "Name," <<
                                   "Number,," <<

                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U,"  <<
                                   "U,," <<

                                   "1," <<
                                   "U," <<
                                   "U^2," <<
                                   "1," <<
                                   "1," <<
                                   "U," <<
                                   "1,," <<

                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U,," <<

                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U," <<
                                   "U,\n";
    }
}

void D_MAKRO_Mitochondrien::Stream_Stats()
{
    if(!Stream_Open || !param_set || !Calc_Done)
        return;
    //qDebug() << "Stream_Stats====================================";

    this->setEnabled(false);
    this->showMaximized();
    ui->groupBox_Photons_View->setVisible(true);
    ui->groupBox_Photons_Controls->setVisible(true);
    ui->groupBox_Parameters_View->setVisible(true);
    ui->groupBox_Parameters_Controls->setVisible(true);
    ui->groupBox_Results_View->setVisible(true);
    ui->groupBox_Results_Controls->setVisible(true);

    //===================Summary

    OS_Stream_Summary << "\n";

    OS_Stream_Summary << QDateTime::currentDateTime().toString().toStdString() << "\n";

    if(ui->checkBox_ResCon_RoI_Only->isChecked())
        OS_Stream_Summary << "Region of interest active\n";
    else
        OS_Stream_Summary << "Region of interest not active\n";

    if(ui->checkBox_ResCon_Ignore_Zero->isChecked())
        OS_Stream_Summary << "Ignore 0 parameters\n";
    else
        OS_Stream_Summary << "Accept 0 parameters\n";

    OS_Stream_Summary << QString(
                             "T2 Handling: Const " +
                             QString::number(ui->doubleSpinBox_ParCon_T2_Min_Const->value()) +
                             "/" +
                             QString::number(ui->doubleSpinBox_ParCon_T2_Max_Const->value()) +
                             " - Thres " +
                             QString::number(ui->doubleSpinBox_ParCon_T2_Min_Thres->value()) +
                             "/" +
                             QString::number(ui->doubleSpinBox_ParCon_T2_Max_Thres->value()) +
                             "\n"
                                ).toStdString();


    for(unsigned int c = 0; c < CellCount; c++)
    {
        //qDebug() << "Stream - Summary - Cell:" << c;
        OS_Stream_Summary << QS_Image_BaseName.toStdString() << "," <<
                             "Cell_" << c << ",," <<
                             vvv_Data_ParNucPix[0][c].size();   //assuming all parameter images have the same 0 entrys

        for(unsigned int p = 0; p < PARAMETERS; p++)
            OS_Stream_Summary << ",," << vvv_Stat_ParNucSta[p][c][c_STAT_MEAN_ARITMETIC] <<
                                 ","  << vvv_Stat_ParNucSta[p][c][c_STAT_MEDIAN];

        OS_Stream_Summary << "\n";
    }





    //===================Parameters

    for(unsigned int p = 0; p < PARAMETERS; p++)
    {
        OS_Stream_Parameters[p] << "\n";

        OS_Stream_Parameters[p] << QDateTime::currentDateTime().toString().toStdString() << "\n";

        if(ui->checkBox_ResCon_RoI_Only->isChecked())
            OS_Stream_Parameters[p] << "Region of interest active\n";
        else
            OS_Stream_Parameters[p] << "Region of interest not active\n";

        if(ui->checkBox_ResCon_Ignore_Zero->isChecked())
            OS_Stream_Parameters[p] << "Ignore 0 parameters\n";
        else
            OS_Stream_Parameters[p] << "Accept 0 parameters\n";

        OS_Stream_Parameters[p] << QString(
                                 "T2 Handling: Const " +
                                 QString::number(ui->doubleSpinBox_ParCon_T2_Min_Const->value()) +
                                 "/" +
                                 QString::number(ui->doubleSpinBox_ParCon_T2_Max_Const->value()) +
                                 " - Thres " +
                                 QString::number(ui->doubleSpinBox_ParCon_T2_Min_Thres->value()) +
                                 "/" +
                                 QString::number(ui->doubleSpinBox_ParCon_T2_Max_Thres->value()) +
                                 "\n"
                                       ).toStdString();


        //qDebug() << "Stream - Parameter:" << p << "-" << QSL_Parameter_Suffixes[p] << "---------------------------";
        for(unsigned int c = 0; c < CellCount; c++)
        {
            //qDebug() << "Stream - Parameter - Cell:" << c;
            OS_Stream_Parameters[p] << QS_Image_BasePath.right(QS_Image_BasePath.lastIndexOf('/')).toStdString() << "," <<
                                       "Cell_" << c << ",," <<

                                       vvv_Stat_ParNucSta[p][c][c_STAT_MEAN_ARITMETIC] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_STAN_DEV_SAMPLE] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_MEDIAN] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_ABS_DEV_MED] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_DIST_90_0_PRZ] << ",," <<

                                       vvv_Stat_ParNucSta[p][c][c_STAT_COUNT] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_MEAN_ARITMETIC] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_VARIANCE_SAMPLE] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_SKEWNESS_SAMPLE] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_KURTOSIS_SAMPLE] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_STAN_DEV_SAMPLE] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_VAR_COEF_SAMPLE] << ",," <<

                                       vvv_Stat_ParNucSta[p][c][c_STAT_MINIMUM] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUANTIL_05] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUANTIL_10] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUANTIL_15] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUANTIL_20] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUARTIL_LOW] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUANTIL_30] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUANTIL_35] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUANTIL_40] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUANTIL_45] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_MEDIAN] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUANTIL_55] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUANTIL_60] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUANTIL_65] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUANTIL_70] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUARTIL_UP] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUANTIL_80] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUANTIL_85] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUANTIL_90] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_QUANTIL_95] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_MAXIMUM] << ",," <<

                                       vvv_Stat_ParNucSta[p][c][c_STAT_SPAN] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_DIST_90_0_PRZ] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_DIST_80_0_PRZ] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_DIST_70_0_PRZ] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_DIST_60_0_PRZ] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_DIST_QUARTIL] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_DIST_40_0_PRZ] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_DIST_30_0_PRZ] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_DIST_20_0_PRZ] << "," <<
                                       vvv_Stat_ParNucSta[p][c][c_STAT_DIST_10_0_PRZ] << ",\n";
        }
    }

    ui->groupBox_Photons_View->setVisible(true);
    ui->groupBox_Photons_Controls->setVisible(true);
    ui->groupBox_Parameters_View->setVisible(true);
    ui->groupBox_Parameters_Controls->setVisible(true);
    ui->groupBox_Results_View->setVisible(true);
    ui->groupBox_Results_Controls->setVisible(true);
    this->setEnabled(true);
}

void D_MAKRO_Mitochondrien::Stream_ImagesPlots()
{
    if(!Stream_Open || !param_set || !Calc_Done)
        return;

    //save the save mode to be applyed again at the end of this function
    bool Auto_SaveName_Before = Auto_SaveName;
    Auto_SaveName = true;
    Auto_ResultsProc_blocked = true;

    this->setEnabled(false);
    ui->groupBox_Photons_View->setVisible(false);
    ui->groupBox_Photons_Controls->setVisible(false);
    ui->groupBox_Parameters_View->setVisible(false);
    ui->groupBox_Parameters_Controls->setVisible(false);
    ui->groupBox_Results_View->setVisible(true);
    ui->groupBox_Results_Controls->setVisible(true);

    //create subfolder for image in results folder
    unsigned int count = 0;
    QString QS_Folder_Out_Sub_Img = DIR_Stream.path() + "/" + QS_Image_BaseName + " - " + QString::number(count);
    while(QDir(QS_Folder_Out_Sub_Img).exists())
    {
        count++;
        QS_Folder_Out_Sub_Img = DIR_Stream.path() + "/" + QS_Image_BaseName + " - " + QString::number(count);
    }
    QDir().mkdir(QS_Folder_Out_Sub_Img);
    QDir DIR_Stream_CurrentImage(QS_Folder_Out_Sub_Img);

    //summary==============================================================

    //Images
    ui->groupBox_Results_View->setVisible(true);
    ui->tabWidget_Results->setCurrentIndex(0);

    //Save Mito/Cell_Number/Contrast image
    ui->comboBox_Gra_R->setCurrentIndex(c_ST_RE_PH_CONTRAST);
    ui->comboBox_Gra_G->setCurrentIndex(c_ST_RE_PH_EDGES_NUMBER);
    ui->comboBox_Gra_B->setCurrentIndex(c_ST_RE_PH_BINARY);

    Update_Results_Proc_Force();
    Save_Image(&Viewer_Results, QS_Folder_Out_Sub_Img + "/" + QS_Image_BaseName + " - Overview.png");

    //Save NADPH/NADH, if possible
    if(Calced_NADH && Calced_NADPH)
    {
        ui->comboBox_Gra_R->setCurrentIndex(c_SC_RESULTS - 1 + INDEX_NADPH);
        ui->comboBox_Gra_G->setCurrentIndex(c_ST_RE_PH_EDGES);
        ui->comboBox_Gra_B->setCurrentIndex(c_SC_RESULTS - 1 + INDEX_NADH);
        Update_Results_Proc_Force();
        Save_Image(&Viewer_Results, QS_Folder_Out_Sub_Img + "/" + QS_Image_BaseName + " - NADPH_red - NADH_blue.png");
    }

    //parameters============================================================

    ui->checkBox_ParVie_RoI_Only->setCheckState(ui->checkBox_ResCon_RoI_Only->checkState());

    //loop parameters
    for(unsigned int p = 0; p < PARAMETERS; p++)
    {
        //create subfolder for parameter in img subfolder in results folder
        QString QS_CurentPath_ResImgPar = DIR_Stream_CurrentImage.path() + "/" + QSL_Parameter_Suffixes[p];
        QDir().mkdir(QS_CurentPath_ResImgPar);

        //default name begining
        QString QS_ResParImg_SaveName_Begin = QS_CurentPath_ResImgPar + "/" + QS_Image_BaseName + QSL_Parameter_Suffixes[p] + " - ";

        //IMAGES
        ui->groupBox_Results_View->setVisible(true);
        //ui->groupBox_Parameters_View->setVisible(true);
        ui->tabWidget_Results->setCurrentIndex(0);

        ui->comboBox_ParVie_Parameter->setCurrentIndex(p);
        Update_Results_Proc_Force();
        Save_Image(&Viewer_Parameters, QS_ResParImg_SaveName_Begin + "as8bit.png");

        //PLOTS
        ui->tabWidget_Results->setCurrentIndex(1);

        //Histo all
        ui->comboBox_ResPlo_Type->setCurrentIndex(c_RT_PLOT_HIST_IMG);
        ui->comboBox_His_Image->setCurrentIndex(p);
        ui->checkBox_His_Uniform->setChecked(true);

        ui->checkBox_His_Accumulate->setChecked(true);
        ui->spinBox_His_ClassCount->setValue(1000);
        Update_Results_Proc_Force();
        Save_Plot(ChartView_Plot, QS_ResParImg_SaveName_Begin + "Histogram_All - Cumulated.png");

        ui->checkBox_His_Accumulate->setChecked(false);
        ui->spinBox_His_ClassCount->setValue(100);
        Update_Results_Proc_Force();
        Save_Plot(ChartView_Plot, QS_ResParImg_SaveName_Begin + "Histogram_All.png");

        //Histo cells
        ui->comboBox_ResPlo_Type->setCurrentIndex(c_RT_PLOT_HIST_CELL);
        ui->comboBox_ParAll_Parameter->setCurrentIndex(p);
        ui->checkBox_ParAll_Uniform->setChecked(true);

        ui->checkBox_ParAll_Accumulate->setChecked(true);
        ui->spinBox_ParAll_ClassCount->setValue(1000);
        Update_Results_Proc_Force();
        Save_Plot(ChartView_Plot, QS_ResParImg_SaveName_Begin + "Histogram_Cells - Cumulated.png");

        ui->checkBox_ParAll_Accumulate->setChecked(false);
        ui->spinBox_ParAll_ClassCount->setValue(100);
        Update_Results_Proc_Force();
        Save_Plot(ChartView_Plot, QS_ResParImg_SaveName_Begin + "Histogram_Cells.png");

        //Mean/Median
        ui->comboBox_ResPlo_Type->setCurrentIndex(c_RT_PLOT_STAT_MM);
        ui->comboBox_Stat_MM_Parameter->setCurrentIndex(p);

        ui->checkBox_Stat_MM_Mean->setChecked(true);
        ui->checkBox_Stat_MM_SD->setChecked(true);
        ui->checkBox_Stat_MM_Median->setChecked(false);
        ui->checkBox_Stat_MM_ADM->setChecked(false);
        Update_Results_Proc_Force();
        Save_Plot(ChartView_Plot, QS_ResParImg_SaveName_Begin + "Cells - Mean_SD.png");

        ui->checkBox_Stat_MM_Mean->setChecked(false);
        ui->checkBox_Stat_MM_SD->setChecked(false);
        ui->checkBox_Stat_MM_Median->setChecked(true);
        ui->checkBox_Stat_MM_ADM->setChecked(true);
        Update_Results_Proc_Force();
        Save_Plot(ChartView_Plot, QS_ResParImg_SaveName_Begin + "Cells - Median_AbsDevMed.png");

        ui->checkBox_Stat_MM_Mean->setChecked(true);
        ui->checkBox_Stat_MM_SD->setChecked(false);
        ui->checkBox_Stat_MM_Median->setChecked(true);
        ui->checkBox_Stat_MM_ADM->setChecked(false);
        Update_Results_Proc_Force();
        Save_Plot(ChartView_Plot, QS_ResParImg_SaveName_Begin + "Cells - Mean_Median.png");

        //CV/Skewness/Kurtosis
        ui->comboBox_ResPlo_Type->setCurrentIndex(c_RT_PLOT_STAT_CSK);
        ui->comboBox_Stat_CSK_Parameter->setCurrentIndex(p);

        ui->checkBox_Stat_CSK_CV->setChecked(true);
        ui->checkBox_Stat_CSK_Skewness->setChecked(false);
        ui->checkBox_Stat_CSK_Kurtosis->setChecked(false);
        Update_Results_Proc_Force();
        Save_Plot(ChartView_Plot, QS_ResParImg_SaveName_Begin + "Cells - CoefficientOfVariance.png");

        ui->checkBox_Stat_CSK_CV->setChecked(false);
        ui->checkBox_Stat_CSK_Skewness->setChecked(true);
        ui->checkBox_Stat_CSK_Kurtosis->setChecked(true);
        Update_Results_Proc_Force();
        Save_Plot(ChartView_Plot, QS_ResParImg_SaveName_Begin + "Cells - Skewness_Kurtosis.png");

        //Quantiles
        ui->comboBox_ResPlo_Type->setCurrentIndex(c_RT_PLOT_STAT_QUANT);
        ui->comboBox_Stat_Quantiles_Parameter->setCurrentIndex(p);
        ui->comboBox_Stat_Quantiles_Step->setCurrentIndex(3);
        Update_Results_Proc_Force();
        Save_Plot(ChartView_Plot, QS_ResParImg_SaveName_Begin + "Cells - Quantiles.png");
    }

    ui->groupBox_Photons_View->setVisible(true);
    ui->groupBox_Photons_Controls->setVisible(true);
    ui->groupBox_Parameters_View->setVisible(true);
    ui->groupBox_Parameters_Controls->setVisible(true);
    ui->groupBox_Results_View->setVisible(true);
    ui->groupBox_Results_Controls->setVisible(true);
    this->setEnabled(true);

    //Settings
    ui->groupBox_Photons_Controls->grab().save(QS_Folder_Out_Sub_Img + "/" + QS_Image_BaseName + " - SettingsPhotons.png", 0, -1);
    ui->groupBox_Parameters_Controls->grab().save(QS_Folder_Out_Sub_Img + "/" + QS_Image_BaseName + " - SettingsParameters.png", 0, -1);

    Auto_SaveName = Auto_SaveName_Before;
    Auto_ResultsProc_blocked = false;
}

void D_MAKRO_Mitochondrien::Stream_Settings()
{
    if(!Stream_Open || !param_set || !Calc_Done)
        return;


}

void D_MAKRO_Mitochondrien::Stream_Stats_End()
{
    if(!Stream_Open)
        return;

    OS_Stream_Summary.close();

    for(unsigned int p = 0; p < PARAMETERS; p++)
        OS_Stream_Parameters[p].close();
    OS_Stream_Parameters.clear();

    Stream_Open = false;
}



void D_MAKRO_Mitochondrien::Init_QSL_Results()
{
    QSL_Results.append("Empty");
    QSL_Results.append("Photons_Input");
    QSL_Results.append("Photons_Contrast");
    QSL_Results.append("Photons_Binary");
    QSL_Results.append("Photons_Edges");
    QSL_Results.append("Cell_Numbers");
    QSL_Results.append("Edges_and_Numbers");
}

void D_MAKRO_Mitochondrien::Populate_CB_Results()
{
    ui->comboBox_Gra_R->addItems(QSL_Results);
    ui->comboBox_Gra_G->addItems(QSL_Results);
    ui->comboBox_Gra_B->addItems(QSL_Results);

    ui->comboBox_Gra_R->setCurrentIndex(c_ST_RE_PH_CONTRAST);
    ui->comboBox_Gra_G->setCurrentIndex(c_ST_RE_PH_EDGES_NUMBER);
    ui->comboBox_Gra_B->setCurrentIndex(c_ST_RE_PH_BINARY);
}

void D_MAKRO_Mitochondrien::Init_MatVector(vector<Mat> *vec, unsigned int l)
{
    vec->resize(l);
    for(unsigned int i = 0; i < vec->size(); i++)
        (*vec)[i] = pStore->get_Adress(0)->clone();
}

void D_MAKRO_Mitochondrien::Init_Plot()
{
    //remove old plot
    delete ui->gridLayout_Plot->takeAt(0);

    //Chart_Plot = new QChart();
    ChartView_Plot = new QChartView();
    //ChartView_Plot->setChart(Chart_Plot);
    ui->gridLayout_Plot->addWidget(ChartView_Plot);
    ChartView_Plot->setRenderHint(QPainter::Antialiasing);
    ChartView_Plot->setRubberBand(QChartView::RectangleRubberBand);
    ChartView_Plot->setInteractive(true);
}


void D_MAKRO_Mitochondrien::on_spinBox_PhoCon_Blur_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Photons(c_ST_PH_INPUT_BLUR);
}

void D_MAKRO_Mitochondrien::on_doubleSpinBox_PhoCon_Blur_Sigma_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Photons(c_ST_PH_INPUT_BLUR);
}

void D_MAKRO_Mitochondrien::on_spinBox_PhoCon_Thres_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Photons(c_ST_PH_BIN_THRES);
}

void D_MAKRO_Mitochondrien::on_doubleSpinBox_PhoCon_Thres_Offset_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Photons(c_ST_PH_BIN_THRES);
}

void D_MAKRO_Mitochondrien::on_comboBox_PhoVie_Step_currentIndexChanged(int index)
{
    if((index >= c_ST_PH_REGIONS_EDGES) && (index <= c_ST_PH_REGIONS_SEP_VIEW))
        ManSep_Manip = true;
    else
        ManSep_Manip = false;
}

void D_MAKRO_Mitochondrien::on_spinBox_PhoCon_EdgCon_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Photons(c_ST_PH_REGIONS_CONNECT);
}



void D_MAKRO_Mitochondrien::on_pushButton_PhoCon_Paint_Reset_clicked()
{
    Calc_Done = false;
    ManSep_FromFile = false;
    Init_Cell_Regions();
    Update_ImgProc_Photons(c_ST_PH_REGIONS_EDGES);
}

void D_MAKRO_Mitochondrien::on_pushButton_ResCon_Zoom_Reset_clicked()
{
    ChartView_Plot->chart()->zoomReset();
}

void D_MAKRO_Mitochondrien::on_pushButton_RessCon_Zoom_In_clicked()
{
    ChartView_Plot->chart()->zoomIn();
}

void D_MAKRO_Mitochondrien::on_pushButton_ResCon_Zoom_Out_clicked()
{
    ChartView_Plot->chart()->zoomOut();
}

void D_MAKRO_Mitochondrien::on_spinBox_His_ClassCount_valueChanged(int arg1)
{
    if(arg1 <= 10)
        ui->spinBox_His_ClassCount->setSingleStep(1);
    else if(arg1 <= 100)
        ui->spinBox_His_ClassCount->setSingleStep(10);
    else if (arg1 <= 1000)
        ui->spinBox_His_ClassCount->setSingleStep(100);
    else
        ui->spinBox_His_ClassCount->setSingleStep(1000);
}

void D_MAKRO_Mitochondrien::on_spinBox_ParAll_ClassCount_valueChanged(int arg1)
{
    if(arg1 <= 10)
        ui->spinBox_ParAll_ClassCount->setSingleStep(1);
    else if(arg1 <= 100)
        ui->spinBox_ParAll_ClassCount->setSingleStep(10);
    else if (arg1 <= 1000)
        ui->spinBox_ParAll_ClassCount->setSingleStep(100);
    else
        ui->spinBox_ParAll_ClassCount->setSingleStep(1000);
}

void D_MAKRO_Mitochondrien::on_comboBox_ResCon_Rubberband_currentIndexChanged(int index)
{
    switch (index) {
    case 0:     ChartView_Plot->setRubberBand(QChartView::RectangleRubberBand);     break;
    case 1:     ChartView_Plot->setRubberBand(QChartView::HorizontalRubberBand);    break;
    case 2:     ChartView_Plot->setRubberBand(QChartView::VerticalRubberBand);      break;
    case 3:     ChartView_Plot->setRubberBand(QChartView::NoRubberBand);            break;
    default:                                                                        break;}
}





void D_MAKRO_Mitochondrien::on_action_Autoselect_Save_Filename_triggered(bool checked)
{
    Auto_SaveName = checked;
}

void D_MAKRO_Mitochondrien::on_doubleSpinBox_ParCon_T2_Min_Const_valueChanged(double arg1)
{
    if(arg1 > ui->doubleSpinBox_ParCon_T2_Min_Thres->value())
        ui->doubleSpinBox_ParCon_T2_Min_Thres->setValue(arg1);

    AdaptUI_NADH_p_NADPH_MinMax();
}

void D_MAKRO_Mitochondrien::on_doubleSpinBox_ParCon_T2_Min_Thres_valueChanged(double arg1)
{
    if(arg1 < ui->doubleSpinBox_ParCon_T2_Min_Const->value())
        ui->doubleSpinBox_ParCon_T2_Min_Const->setValue(arg1);


    AdaptUI_NADH_p_NADPH_MinMax();
}

void D_MAKRO_Mitochondrien::on_doubleSpinBox_ParCon_T2_Max_Const_valueChanged(double arg1)
{
    if(arg1 < ui->doubleSpinBox_ParCon_T2_Max_Thres->value())
        ui->doubleSpinBox_ParCon_T2_Max_Thres->setValue(arg1);

    AdaptUI_NADH_p_NADPH_MinMax();
}

void D_MAKRO_Mitochondrien::on_doubleSpinBox_ParCon_T2_Max_Thres_valueChanged(double arg1)
{
    if(arg1 > ui->doubleSpinBox_ParCon_T2_Max_Const->value())
        ui->doubleSpinBox_ParCon_T2_Max_Const->setValue(arg1);

    AdaptUI_NADH_p_NADPH_MinMax();
}

void D_MAKRO_Mitochondrien::on_action_Show_Photons_triggered(bool checked)
{
    ui->groupBox_Photons_Controls->setVisible(checked);
    ui->groupBox_Photons_View->setVisible(checked);
    Update_Views();
}

void D_MAKRO_Mitochondrien::on_action_Show_Parameters_triggered(bool checked)
{
    ui->groupBox_Parameters_Controls->setVisible(checked);
    ui->groupBox_Parameters_View->setVisible(checked);
    Update_Views();
}

void D_MAKRO_Mitochondrien::on_action_Show_Results_triggered(bool checked)
{
    ui->groupBox_Results_Controls->setVisible(checked);
    ui->groupBox_Results_View->setVisible(checked);
    Update_Views();
}

void D_MAKRO_Mitochondrien::on_comboBox_AnalysedImage_currentIndexChanged(int index)
{
    index;
    Update_ImgProc_All();
}

void D_MAKRO_Mitochondrien::on_radioButton_PhoCon_Paint_Line_clicked(bool checked)
{
    ui->comboBox_PhoCon_Paint_FillStep->setEnabled(!checked);
    ui->spinBox_PhoCon_Paint_Thick->setEnabled(checked);
    ui->label_PhoCon_Paint_Thick->setEnabled(checked);
}

void D_MAKRO_Mitochondrien::on_comboBox_PhoCon_Paint_FillStep_currentIndexChanged(int index)
{
    ui->spinBox_PhoCon_EdgCon_Size->setEnabled(index != 0);
}

void D_MAKRO_Mitochondrien::on_radioButton_PhoCon_Paint_Fill_clicked(bool checked)
{
    ui->comboBox_PhoCon_Paint_FillStep->setEnabled(checked);
    ui->spinBox_PhoCon_Paint_Thick->setEnabled(!checked);
    ui->label_PhoCon_Paint_Thick->setEnabled(!checked);
}

