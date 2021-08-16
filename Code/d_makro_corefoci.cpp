/************************************
 *   added:     26.09.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_makro_corefoci.h"
#include "ui_d_makro_corefoci.h"

D_MAKRO_CoreFoci::D_MAKRO_CoreFoci(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_CoreFoci)
{
    ui->setupUi(this);

    //connect stuff with parent
    pStore = pStorage;

    //allocate memory for images
    vMA_Cores.resize(c_ST_C_NUMBER_OF);
    for(unsigned int i = 0; i < vMA_Cores.size(); i++)
        vMA_Cores[i] = pStore->get_Adress(0)->clone();

    vMA_Plasma.resize(c_ST_P_NUMBER_OF);
    for(unsigned int i = 0; i < vMA_Plasma.size(); i++)
        vMA_Plasma[i] = pStore->get_Adress(0)->clone();

    vMA_Foci.resize(c_ST_F_NUMBER_OF);
    for(unsigned int i = 0; i < vMA_Foci.size(); i++)
        vMA_Foci[i] = pStore->get_Adress(0)->clone();

    vMA_Results.resize(c_ST_R_NUMBER_OF);
    for(unsigned int i = 0; i < vMA_Results.size(); i++)
        vMA_Results[i] = pStore->get_Adress(0)->clone();

    MA_Result = pStore->get_Adress(0)->clone();

    //ComboBoxes
    Populate_CB();

    //GraphicsView
    V_Nuclei.set_GV(ui->graphicsView_Cores);
    V_Plasma.set_GV(ui->graphicsView_Cyto);
    V_Foci.set_GV(ui->graphicsView_Foci);
    V_Results.set_GV(ui->graphicsView_Result);

    //Table
    Table_CellStat.set_TW(ui->tableWidget_Cells);
    Table_ImageStat.set_TW(ui->tableWidget_Image);
    Table_Summary_Single.set_TW(ui->tableWidget_Summary_CurrentCell_Single);
    Table_Summary_Quotients.set_TW(ui->tableWidget_Summary_CurrentCell_Quotients);

    //Plot
    //Init chart and chartview
    Chart_Cells = new QChart();
    ChartView_Cells = new QChartView(this);
    ChartView_Cells->setChart(Chart_Cells);
    ui->gridLayout_ResPlo_Cells->addWidget(ChartView_Cells);
    ChartView_Cells->setRenderHint(QPainter::Antialiasing);
    ChartView_Cells->setRubberBand(QChartView::RectangleRubberBand);
    ChartView_Cells->setInteractive(true);

    Chart_Image = new QChart();
    ChartView_Image = new QChartView(this);
    ChartView_Image->setChart(Chart_Image);
    ui->gridLayout_ResPlo_Image->addWidget(ChartView_Image);
    ChartView_Image->setRenderHint(QPainter::Antialiasing);
    ChartView_Image->setRubberBand(QChartView::RectangleRubberBand);
    ChartView_Image->setInteractive(true);

    //STATUSBAR
    unsigned int LabelWidth = 75;
    L_SB_PixVal = new QLabel(this);
    L_SB_PixVal->setFixedWidth(LabelWidth * 2);
    L_SB_PixVal->setToolTip("Pixelvalue (Mouse hovered).");
    ui->statusbar->addPermanentWidget(L_SB_PixVal);

    //CONNECTS
    connect(ui->action_Load_Images,                 SIGNAL(triggered(bool)),            this,   SLOT(Load_Images()));
    connect(ui->action_Update_All,                  SIGNAL(triggered(bool)),            this,   SLOT(Update_ImgProc_All()));
    connect(ui->action_Update_View,                 SIGNAL(triggered(bool)),            this,   SLOT(Update_Views()));
    connect(ui->action_Process_Stack,               SIGNAL(triggered(bool)),            this,   SLOT(Stack_Attributes_Process()));
  //connect(ui->pushButton_Stack_Next,              SIGNAL(clicked(bool)),              this,   SLOT(Next_Image()));
    connect(ui->action_Next_Image,                  SIGNAL(triggered(bool)),            this,   SLOT(Next_Image()));
    connect(ui->action_Clear_Images,                SIGNAL(triggered(bool)),            this,   SLOT(Clear_Images()));
    //View
    connect(ui->comboBox_View_Cores,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_View_Cores()));
    connect(ui->comboBox_View_Cyto,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_View_Plasma()));
    connect(ui->comboBox_View_Foci,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_View_Foci()));
    connect(ui->action_Smooth_Transformation,       SIGNAL(triggered(bool)),            this,   SLOT(Update_Views()));
    connect(ui->action_Keep_Aspect_Ratio,           SIGNAL(triggered(bool)),            this,   SLOT(Update_Views()));

    //Results
    connect(ui->tabWidget_View_Results,                     SIGNAL(currentChanged(int)),        this,   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_Cells_Type,                 SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_Img_Type,                   SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results()));

    //image
    //Update color image
    connect(ui->comboBox_View_Result_B,                     SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results()));
    connect(ui->comboBox_View_Result_G,                     SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results()));
    connect(ui->comboBox_View_Result_R,                     SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results()));

    //cell plot
    //att
    connect(ui->comboBox_ResPlo_Cells_Att_Att,              SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results()));
    //att hist
    connect(ui->comboBox_ResPlo_Cells_Att_Hist_Att,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results()));
    connect(ui->spinBox_ResPlo_Cells_Att_Hist_Classes,      SIGNAL(valueChanged(int)),          this,   SLOT(Update_Results()));
    connect(ui->checkBox_ResPlo_Cells_Att_Hist_Uni,         SIGNAL(clicked(bool)),              this,   SLOT(Update_Results()));
    connect(ui->checkBox_ResPlo_Cells_Att_Hist_Acc,         SIGNAL(clicked(bool)),              this,   SLOT(Update_Results()));
    //att scatter
    connect(ui->comboBox_ResPlo_Cells_Att_Scatter_Att_X,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_Cells_Att_Scatter_Att_Y,    SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results()));

    //image plot
    //att
    connect(ui->comboBox_ResPlo_Img_Att_Att,                SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results()));
    //att hist
    connect(ui->comboBox_ResPlo_Img_Att_Hist_Att,           SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results()));
    connect(ui->spinBox_ResPlo_Img_Att_Hist_Classes,        SIGNAL(valueChanged(int)),          this,   SLOT(Update_Results()));
    connect(ui->checkBox_ResPlo_Img_Att_Hist_Uni,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Results()));
    connect(ui->checkBox_ResPlo_Img_Att_Hist_Acc,           SIGNAL(clicked(bool)),              this,   SLOT(Update_Results()));
    //att scatter
    connect(ui->comboBox_ResPlo_Img_Att_Scatter_Att_X,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_Img_Att_Scatter_Att_Y,      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results()));

    //Tables
    connect(ui->comboBox_TabCell_Type,                      SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results()));
    connect(ui->comboBox_TabImg_Type,                       SIGNAL(currentIndexChanged(int)),   this,   SLOT(Update_Results()));

    //Save
    connect(ui->action_Save_Image_Cores,            SIGNAL(triggered(bool)),                    this,   SLOT(Save_Image_Cores()));
    connect(ui->action_Save_image_cytoplasma,       SIGNAL(triggered(bool)),                    this,   SLOT(Save_Image_Plasma()));
    connect(ui->action_Save_Image_Foci,             SIGNAL(triggered(bool)),                    this,   SLOT(Save_Image_Foci()));
    connect(ui->action_Save_Image_Results,          SIGNAL(triggered(bool)),                    this,   SLOT(Save_Image_Results()));
    connect(ui->action_Save_plot_image,             SIGNAL(triggered(bool)),                    this,   SLOT(Save_Plot_Cells()));
    connect(ui->action_Save_plot_stack,             SIGNAL(triggered(bool)),                    this,   SLOT(Save_Plot_Image()));
    //Types
    connect(&V_Nuclei,                              SIGNAL(TypeChanged_MA(QString)),            ui->label_View_Cores_MA_Format,     SLOT(setText(QString)));
    connect(&V_Nuclei,                              SIGNAL(TypeChanged_QI(QString)),            ui->label_View_Cores_QI_Format,     SLOT(setText(QString)));
    connect(&V_Plasma,                              SIGNAL(TypeChanged_MA(QString)),            ui->label_View_Cyto_Format_MA,      SLOT(setText(QString)));
    connect(&V_Plasma,                              SIGNAL(TypeChanged_QI(QString)),            ui->label_View_Cyto_Format_QI,      SLOT(setText(QString)));
    connect(&V_Foci,                                SIGNAL(TypeChanged_MA(QString)),            ui->label_View_Foci_MA_Format,      SLOT(setText(QString)));
    connect(&V_Foci,                                SIGNAL(TypeChanged_QI(QString)),            ui->label_View_Foci_QI_Format,      SLOT(setText(QString)));
    //Statusbar
    connect(&V_Nuclei,                              SIGNAL(MouseMoved_Value(QString)),          L_SB_PixVal,                        SLOT(setText(QString)));
    connect(&V_Foci,                                SIGNAL(MouseMoved_Value(QString)),          L_SB_PixVal,                        SLOT(setText(QString)));
    connect(&V_Plasma,                              SIGNAL(MouseMoved_Value(QString)),          L_SB_PixVal,                        SLOT(setText(QString)));
    connect(&V_Results,                             SIGNAL(MouseMoved_Value(QString)),          L_SB_PixVal,                        SLOT(setText(QString)));

    //Viewer Zoom connect
    V_Nuclei.connect_Zoom(&V_Foci);
    V_Nuclei.connect_Zoom(&V_Plasma);
    V_Nuclei.connect_Zoom(&V_Results);

    //Initial Stuff
    Parameters_Init();
    Parameters_ActivatePreset();
    Update_Views();
    //ui->groupBox_View_Result->setVisible(false);
    //ui->groupBox_Results->setVisible(false);

    //icon & title
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    setWindowTitle("ImageD - Foci-Cytoplasm-Nuclei Detector");

    //init indicies
    View_BlockSignals(true);
    ui->comboBox_View_Cores->setCurrentIndex(c_ST_C_INPUT_CONV_8BIT);
    ui->comboBox_View_Cyto->setCurrentIndex(c_ST_P_INPUT_CONV_8BIT);
    ui->comboBox_View_Foci->setCurrentIndex(c_ST_F_INPUT_CONV_8BIT);
    ui->comboBox_View_Result_R->setCurrentIndex(c_ST_R_P_INPUT);
    ui->comboBox_View_Result_G->setCurrentIndex(c_ST_R_F_INPUT);
    ui->comboBox_View_Result_B->setCurrentIndex(c_ST_R_C_INPUT);
    View_BlockSignals(false);

    this->showMaximized();
}

D_MAKRO_CoreFoci::~D_MAKRO_CoreFoci()
{
    delete ui;
}

void D_MAKRO_CoreFoci::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    Update_Views();
}

void D_MAKRO_CoreFoci::closeEvent(QCloseEvent *event)
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

Mat *D_MAKRO_CoreFoci::get_pMA_Substep(unsigned int vec_number, unsigned int pos)
{
    if(QSL_Input_Images.empty())
        return pStore->get_Adress(0);

    switch (vec_number) {
    case 0:     if(pos < vMA_Cores.size())      return &(vMA_Cores[pos]);       break;
    case 1:     if(pos < vMA_Foci.size())       return &(vMA_Foci[pos]);        break;
    case 2:     if(pos < vMA_Results.size())    return &(vMA_Results[pos]);     break;
    default:                                                                    break;}

    return &(vMA_Cores[0]);
}

void D_MAKRO_CoreFoci::Update_Views()
{
    if(FIL_Input_Images.empty())
        return;

    if(stack_processing)
        return;

    //qDebug() << "Update_Images";
    Update_View_Cores();
    Update_View_Plasma();
    Update_View_Foci();
    Update_View_Results();
}

void D_MAKRO_CoreFoci::Update_View_Cores()
{
    if(FIL_Input_Images.empty())
        return;

    V_Nuclei.Update_Image(&(vMA_Cores[ui->comboBox_View_Cores->currentIndex()]));
}

void D_MAKRO_CoreFoci::Update_View_Plasma()
{
    if(FIL_Input_Images.empty())
        return;

    V_Plasma.Update_Image(&(vMA_Plasma[ui->comboBox_View_Cyto->currentIndex()]));
}

void D_MAKRO_CoreFoci::Update_View_Foci()
{
    if(FIL_Input_Images.empty())
        return;

    V_Foci.Update_Image(&(vMA_Foci[ui->comboBox_View_Foci->currentIndex()]));
}

void D_MAKRO_CoreFoci::Update_View_Results()
{
    if(FIL_Input_Images.empty())
        return;

    V_Results.Update_Image(&(MA_Result));
}

void D_MAKRO_CoreFoci::Update_Ui()
{
    if(this->isEnabled())
        return;

    this->repaint();
    qApp->processEvents();
}


void D_MAKRO_CoreFoci::Update_ImgProc_All()
{
    if(FIL_Input_Images.empty())
        return;

    //qDebug() << "Update_ImgProc_All";

    Update_ImgProc_Cores(0);
    //All other procs amd views are called in the called mathods
}

void D_MAKRO_CoreFoci::Update_ImgProc_Cores(unsigned int start_step)
{
    if(FIL_Input_Images.empty())
        return;

    //qDebug() << "Update_ImgProc_Cores" << start_step;

    for(unsigned int s = start_step; s < vMA_Cores.size(); s++)
        Update_Step_Cores(s);
    Update_View_Cores();

    Update_ImgProc_Plasma(0);
}

void D_MAKRO_CoreFoci::Update_ImgProc_Plasma(unsigned int start_step)
{
    if(FIL_Input_Images.empty())
        return;

    for(unsigned int s = start_step; s < vMA_Plasma.size(); s++)
        Update_Step_Plasma(s);
    Update_View_Plasma();

    Update_ImgProc_Foci(0);
}

void D_MAKRO_CoreFoci::Update_ImgProc_Foci(unsigned int start_step)
{
    if(FIL_Input_Images.empty())
        return;

    for(unsigned int s = start_step; s < vMA_Foci.size(); s++)
        Update_Step_Foci(s);
    Update_View_Foci();

    Calc_All();
    stack_processed = false;

    Update_ImgProc_Results(0);
}

void D_MAKRO_CoreFoci::Update_ImgProc_Results(unsigned int start_step)
{
    if(FIL_Input_Images.empty())
        return;

    for(unsigned int s = start_step; s < vMA_Results.size(); s++)
        Update_Step_Results(s);
    Update_View_Results();

    Update_Results();
}

void D_MAKRO_CoreFoci::Update_Step_Cores(unsigned int step)
{
    if(FIL_Input_Images.empty())
        return;

    //qDebug() << "Update_Step_Cores" << step;

    switch (step) {

    case c_ST_C_LOAD:
    {
        ERR(D_Img_Proc::Load_From_Path_Multi(
                    &(vMA_Cores[c_ST_C_LOAD]),
                    FIL_Input_Images[ui->comboBox_FileName->currentIndex()].absoluteFilePath(),
                    ui->spinBox_IndexNuclei->value()),
                "Update_Step_Cores",
                "c_ST_C_LOAD");

    }
        break;

    case c_ST_C_INPUT_CONV_8BIT:
    {
        ERR(D_Img_Proc::Normalize(
                &(vMA_Cores[c_ST_C_INPUT_CONV_8BIT]),
                &(vMA_Cores[c_ST_C_LOAD]),
                CV_MINMAX,
                CV_8UC1,
                0,
                255),
            "Update_Step_Cores",
            "c_ST_C_INPUT_CONV_8BIT");
    }
        break;

    case c_ST_C_INPUT_CONTRAST:
    {
        ERR(D_Img_Proc::Histo_Equal(
                &(vMA_Cores[c_ST_C_INPUT_CONTRAST]),
                &(vMA_Cores[c_ST_C_INPUT_CONV_8BIT])),
            "Update_Step_Cores",
            "c_ST_C_INPUT_CONTRAST");
    }
        break;


    case c_ST_C_INPUT_BLUR:
    {
        ERR(D_Img_Proc::Filter_Gauss(
                &(vMA_Cores[c_ST_C_INPUT_BLUR]),
                &(vMA_Cores[c_ST_C_INPUT_CONV_8BIT]),
                ui->spinBox_SetCore_02_Gauss_Size->value() / 2,
                ui->spinBox_SetCore_02_Gauss_Size->value() / 2,
                BORDER_DEFAULT,
                ui->doubleSpinBox_SetCore_02_Gauss_Sigma->value(),
                ui->doubleSpinBox_SetCore_02_Gauss_Sigma->value()),
            "Update_Step_Cores",
            "c_ST_C_INPUT_BLUR");
    }
        break;

    case c_ST_C_BIN_THRES:
    {
        ERR(D_Img_Proc::Threshold_Adaptive(
                &(vMA_Cores[c_ST_C_BIN_THRES]),
                &(vMA_Cores[c_ST_C_INPUT_BLUR]),
                CV_THRESH_BINARY_INV,
                255,
                CV_ADAPTIVE_THRESH_GAUSSIAN_C,
                ui->spinBox_SetCore_04_Thres_Size->value() / 2,
                ui->doubleSpinBox_SetCore_04_Thres_Offset->value()),
            "Update_Step_Cores",
            "c_ST_C_BIN_THRES");
    }
        break;

    case c_ST_C_BIN_AREA:
    {
        ERR(D_Img_Proc::Select_Area(
                &(vMA_Cores[c_ST_C_BIN_AREA]),
                &(vMA_Cores[c_ST_C_BIN_THRES]),
                ui->spinBox_SetCore_05_Fill_Area->value(),
                100000000,
                8),
            "Update_Step_Cores",
            "c_ST_C_BIN_AREA");
    }
        break;

    case c_ST_C_BIN_INV:
    {
        ERR(D_Img_Proc::Math_ImgSelf_Not(
                &(vMA_Cores[c_ST_C_BIN_INV]),
                &(vMA_Cores[c_ST_C_BIN_AREA])),
            "Update_Step_Cores",
            "c_ST_C_BIN_INV");
    }
        break;

    case c_ST_C_DIST_TRANSFORM:
    {
        ERR(D_Img_Proc::Transformation_Distance(
                &(vMA_Cores[c_ST_C_DIST_TRANSFORM]),
                &(vMA_Cores[c_ST_C_BIN_INV]),
                CV_DIST_L2,
                CV_DIST_MASK_PRECISE),
            "Update_Step_Cores",
            "c_ST_C_DIST_TRANSFORM");
    }
        break;

    case c_ST_C_RANK_EILENSTEIN:
    {
        //Mean mask
        Mat MA_mask(
                    ui->spinBox_SetCore_09_Eilenstein_Size->value(),
                    ui->spinBox_SetCore_09_Eilenstein_Size->value(),
                    CV_64FC1,
                    Scalar(1));
        double offset = ui->doubleSpinBox_Set_Core_09_Eilenstein_Offset->value();

        ERR(D_Img_Proc::Filter_Function(
                &(vMA_Cores[c_ST_C_RANK_EILENSTEIN]),
                &(vMA_Cores[c_ST_C_DIST_TRANSFORM]),
                &MA_mask,
                D_Math::Function_2D_to_1D(                                      //F1
                    c_MATH_2D_TO_1D_X_greater_Y,
                    1, offset,
                    1, 0,
                    0, 0, 0, 0),
                D_Math::Function_2D_to_1D(                                      //F2
                    c_MATH_2D_TO_1D_X,
                    1, 0,
                    1, 0,
                    0, 0, 0, 0),
                D_Stat::Function_SingleStat(                                    //F3
                    c_STAT_SUM),
                D_Math::Function_2D_to_1D(                                      //F4
                    c_MATH_2D_TO_1D_X,
                    1, 0,
                    1, 0,
                    0, 0, 0, 0),
                BORDER_REFLECT),
            "Update_Step_Cores",
            "c_ST_C_RANK_EILENSTEIN");

        MA_mask.release();

        /*
        ERR(D_Img_Proc::Filter_Eilenstein(
                &(vMA_Cores[c_ST_C_RANK_EILENSTEIN]),
                &(vMA_Cores[c_ST_C_DIST_TRANSFORM]),
                1,
                ui->spinBox_SetCore_09_Eilenstein_Size->value() / 2,
                ui->spinBox_SetCore_09_Eilenstein_Size->value() / 2,
                false,
                ui->doubleSpinBox_Set_Core_09_Eilenstein_Offset->value()),
            "Update_Step_Cores",
            "c_ST_C_RANK_EILENSTEIN");
            */
    }
        break;

    case c_ST_C_RANK_CONV_8BIT:
    {
        ERR(D_Img_Proc::Normalize(
                &(vMA_Cores[c_ST_C_RANK_CONV_8BIT]),
                &(vMA_Cores[c_ST_C_RANK_EILENSTEIN]),
                CV_MINMAX,
                CV_8UC1,
                0,
                255),
            "Update_Step_Cores",
            "c_ST_C_RANK_CONV_8BIT");
    }
        break;

    case c_ST_C_LMAX_BIN:
    {
        ERR(D_Img_Proc::Threshold_Value(
                &(vMA_Cores[c_ST_C_LMAX_BIN]),
                &(vMA_Cores[c_ST_C_RANK_CONV_8BIT]),
                CV_THRESH_BINARY,
                255,
                ui->spinBox_SetCore_11_Thresh_Thres->value()),
            "Update_Step_Cores",
            "c_ST_C_LMAX_BIN");
    }
        break;

    case c_ST_C_LMAX_OPEN:
    {
        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_Cores[c_ST_C_LMAX_OPEN]),
                &(vMA_Cores[c_ST_C_LMAX_BIN]),
                MORPH_OPEN,
                MORPH_ELLIPSE,
                ui->spinBox_SetCore_12_Open_Area->value() / 2,
                ui->spinBox_SetCore_12_Open_Area->value() / 2,
                BORDER_DEFAULT,
                1),
            "Update_Step_Cores",
            "c_ST_C_LMAX_OPEN");
    }
        break;

    case c_ST_C_LMAX_DILATION:
    {
        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_Cores[c_ST_C_LMAX_DILATION]),
                &(vMA_Cores[c_ST_C_LMAX_OPEN]),
                MORPH_DILATE,
                MORPH_ELLIPSE,
                ui->spinBox_SetCore_13_Dilation_Size->value() / 2,
                ui->spinBox_SetCore_13_Dilation_Size->value() / 2,
                BORDER_DEFAULT,
                1),
            "Update_Step_Cores",
            "c_ST_C_LMAX_DILATION");
    }
        break;

    case c_ST_C_SEGM_WATERSHADE:
    {
        ERR(D_Img_Proc::Transformation_Watershed_Auto(
                &(vMA_Cores[c_ST_C_SEGM_WATERSHADE]),
                &(vMA_Cores[c_ST_C_BIN_INV]),
                &(vMA_Cores[c_ST_C_LMAX_DILATION]),
                false,
                false,
                ui->checkBox_SetCore_13_ExcludeBordered->isChecked()),
            "Update_Step_Cores",
            "c_ST_C_SEGM_WATERSHADE");
    }
        break;

    case c_ST_C_SEGM_BINARY:
    {
        ERR(D_Img_Proc::Threshold_Absolute(
                &(vMA_Cores[c_ST_C_SEGM_BINARY]),
                &(vMA_Cores[c_ST_C_SEGM_WATERSHADE]),
                0),
            "Update_Step_Cores",
            "c_ST_C_SEGM_BINARY");
    }
        break;

    case c_ST_C_SEGM_AREA_CONNECT:
    {
        ERR(D_Img_Proc::Feature_Connect(
                &(vMA_Cores[c_ST_C_SEGM_AREA_CONNECT]),
                &(vMA_Cores[c_ST_C_SEGM_BINARY]),
                c_COMPDIST_CONTOUR,
                c_COMPDIST_CONTOUR,
                ui->spinBox_SetCore_14_AreaDistMin->value(),
                ui->spinBox_SetCore_14_AreaDistMax->value(),
                c_FEAT_AREA,
                c_FEAT_AREA,
                D_Math::Condition_2D(
                    c_COND_INTERVALS_IN_INCL_AND,
                    1, 0,   //Scale/Offset Small
                    1, 0,   //Scale/Offset Big
                    0,      //Area Intervals
                    ui->spinBox_SetCore_14_AreaMaxOfSmall->value(),
                    ui->spinBox_SetCore_14_AreaMinOfBig->value(),
                    vMA_Cores[c_ST_C_SEGM_BINARY].rows * vMA_Cores[c_ST_C_SEGM_BINARY].cols + 1),
                c_CONNECT_IN_RANGE,
                4,
                1),
            "Update_Step_Cores",
            "c_ST_C_SEGM_AREA_CONNECT");
    }
        break;

    case c_ST_C_SEGM_LABELS_FINAL:
    {
        ERR(D_Img_Proc::Labeling(
                &(vMA_Cores[c_ST_C_SEGM_LABELS_FINAL]),
                &(vMA_Cores[c_ST_C_SEGM_AREA_CONNECT]),
                4,
                CV_16UC1),
            "Update_Step_Cores",
            "c_ST_C_SEGM_LABELS_FINAL");
    }
        break;

    case c_ST_C_SEGM_EDGES:
    {
        ERR(D_Img_Proc::Reduce_Geometric(
                &(vMA_Cores[c_ST_C_SEGM_EDGES]),
                &(vMA_Cores[c_ST_C_SEGM_AREA_CONNECT]),
                c_GEO_CONTOUR,
                4,
                2,
                255),
            "Update_Step_Cores",
            "c_ST_C_SEGM_EDGES");
    }
        break;

    default:
        break;
    }
}

void D_MAKRO_CoreFoci::Update_Step_Plasma(unsigned int step)
{
    if(FIL_Input_Images.empty())
        return;

    switch (step) {
    case c_ST_P_LOAD:
    {
        int ER = D_Img_Proc::Load_From_Path_Multi(
                    &(vMA_Plasma[c_ST_P_LOAD]),
                    FIL_Input_Images[ui->comboBox_FileName->currentIndex()].absoluteFilePath(),
                    ui->spinBox_IndexCytoplasm->value());

        //catch if only nuclei and foci channel exists (treat cytoplasma as beeing everywhere then)
        if(ER == ER_empty)
            vMA_Plasma[c_ST_P_LOAD] = Mat(vMA_Cores[c_ST_C_LOAD].size(), vMA_Cores[c_ST_C_LOAD].type(), Scalar(255));
        else
            ERR(ER,
                "Update_Step_Plasma",
                "c_ST_P_LOAD");
    }
        break;

    case c_ST_P_INPUT_CONV_8BIT:
    {
        ERR(D_Img_Proc::Normalize(
                &(vMA_Plasma[c_ST_P_INPUT_CONV_8BIT]),
                &(vMA_Plasma[c_ST_P_LOAD]),
                CV_MINMAX,
                CV_8UC1,
                0,
                255),
            "Update_Step_Plasma",
            "c_ST_P_INPUT_CONV_8BIT");
    }
        break;

    case c_ST_P_INPUT_CONTRAST:
    {
        ERR(D_Img_Proc::Histo_Equal(
                &(vMA_Plasma[c_ST_P_INPUT_CONTRAST]),
                &(vMA_Plasma[c_ST_P_INPUT_CONV_8BIT])),
            "Update_Step_Plasma",
            "c_ST_P_INPUT_CONTRAST");
    }
        break;

    case c_ST_P_INPUT_BLUR:
    {
        ERR(D_Img_Proc::Filter_Gauss(
                &(vMA_Plasma[c_ST_P_INPUT_BLUR]),
                &(vMA_Plasma[c_ST_P_INPUT_CONV_8BIT]),
                ui->spinBox_SetCyto_Gauss_Size->value(),
                ui->spinBox_SetCyto_Gauss_Size->value(),
                BORDER_DEFAULT,
                ui->doubleSpinBox_SetCyto_Gauss_Sigma->value(),
                ui->doubleSpinBox_SetCyto_Gauss_Sigma->value()),
            "Update_Step_Plasma",
            "c_ST_P_INPUT_BLUR");
    }
        break;

    case c_ST_P_BIN_THRES:
    {
        ERR(D_Img_Proc::Threshold_Adaptive(
                &(vMA_Plasma[c_ST_P_BIN_THRES]),
                &(vMA_Plasma[c_ST_P_INPUT_BLUR]),
                CV_THRESH_BINARY,
                255,
                CV_ADAPTIVE_THRESH_MEAN_C,
                ui->spinBox_SetCyto_Thresh_Size->value() / 2,
                ui->doubleSpinBox_SetCyto_Thresh_Offset->value()),
            "Update_Step_Plasma",
            "c_ST_P_BIN_THRES");
    }
        break;

    case c_ST_P_MORPH_CLOSE:
    {
        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_Plasma[c_ST_P_MORPH_CLOSE]),
                &(vMA_Plasma[c_ST_P_BIN_THRES]),
                MORPH_CLOSE,
                MORPH_ELLIPSE,
                ui->spinBox_SetCyto_Closing_Size->value() / 2,
                ui->spinBox_SetCyto_Closing_Size->value() / 2,
                BORDER_DEFAULT,
                1),
            "Update_Step_Plasma",
            "c_ST_P_MORPH_CLOSE");
    }
        break;

    case c_ST_P_MORPH_DILATE:
    {
        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_Plasma[c_ST_P_MORPH_DILATE]),
                &(vMA_Plasma[c_ST_P_MORPH_CLOSE]),
                MORPH_DILATE,
                MORPH_ELLIPSE,
                ui->spinBox_SetCyto_Dilation_Size->value() / 2,
                ui->spinBox_SetCyto_Dilation_Size->value() / 2,
                BORDER_DEFAULT,
                1),
            "Update_Step_Plasma",
            "c_ST_P_MORPH_DILATE");
    }
        break;

    case c_ST_P_REG_PLASMA:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Plasma[c_ST_P_REG_PLASMA]),
                &(vMA_Plasma[c_ST_P_MORPH_DILATE])),
            "Update_Step_Plasma",
            "c_ST_P_REG_PLASMA");
    }
        break;

    case c_ST_P_REG_PLASMA_EDGES:
    {
        ERR(D_Img_Proc::Filter_Laplace(
                &(vMA_Plasma[c_ST_P_REG_PLASMA_EDGES]),
                &(vMA_Plasma[c_ST_P_REG_PLASMA]),
                11,
                BORDER_DEFAULT,
                CV_8U,
                1,
                0),
            "Update_Step_Plasma",
            "c_ST_P_REG_PLASMA_EDGES");
    }
        break;

    default:
        break;
    }
}

void D_MAKRO_CoreFoci::Update_Step_Foci(unsigned int step)
{
    if(FIL_Input_Images.empty())
        return;

    switch (step) {
    case c_ST_F_LOAD:
    {
        ERR(D_Img_Proc::Load_From_Path_Multi(
                &(vMA_Foci[c_ST_F_LOAD]),
                FIL_Input_Images[ui->comboBox_FileName->currentIndex()].absoluteFilePath(),
                ui->spinBox_IndexFoci->value()),
            "Update_Step_Foci",
            "c_ST_F_LOAD");
    }
        break;

    case c_ST_F_INPUT_CONV_8BIT:
    {
        ERR(D_Img_Proc::Normalize(
                &(vMA_Foci[c_ST_F_INPUT_CONV_8BIT]),
                &(vMA_Foci[c_ST_F_LOAD]),
                CV_MINMAX,
                CV_8UC1,
                0,
                255),
            "Update_Step_Foci",
            "c_ST_F_INPUT_CONV_8BIT");
    }
        break;

    case c_ST_F_INPUT_CONTRAST:
    {
        ERR(D_Img_Proc::Histo_Equal(
                &(vMA_Foci[c_ST_F_INPUT_CONTRAST]),
                &(vMA_Foci[c_ST_F_INPUT_CONV_8BIT])),
            "Update_Step_Foci",
            "c_ST_F_INPUT_CONTRAST");
    }
        break;

    case c_ST_F_INPUT_BLUR:
    {
        ERR(D_Img_Proc::Filter_Gauss(
                &(vMA_Foci[c_ST_F_INPUT_BLUR]),
                &(vMA_Foci[c_ST_F_INPUT_CONV_8BIT]),
                ui->spinBox_SetFoci_02_Size->value() / 2,
                ui->spinBox_SetFoci_02_Size->value() / 2,
                BORDER_DEFAULT,
                ui->doubleSpinBox_SetFoci_02_Sigma->value(),
                ui->doubleSpinBox_SetFoci_02_Sigma->value()),
            "Update_Step_Foci",
            "c_ST_F_INPUT_BLUR");
    }
        break;

    case c_ST_F_BIN_THRES:
    {
        ERR(D_Img_Proc::Threshold_Adaptive(
                &(vMA_Foci[c_ST_F_BIN_THRES]),
                &(vMA_Foci[c_ST_F_INPUT_BLUR]),
                CV_THRESH_BINARY,
                255,
                CV_ADAPTIVE_THRESH_GAUSSIAN_C,
                ui->spinBox_SetFoci_03_Size->value() / 2,
                ui->doubleSpinBox_SetFoci_03_Offset->value()),
            "Update_Step_Foci",
            "c_ST_F_BIN_THRES");
    }
        break;

    case c_ST_F_ROI_NUC_MARGIN:
    {
        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_Foci[c_ST_F_ROI_NUC_MARGIN]),
                &(vMA_Cores[c_ST_C_BIN_INV]),
                MORPH_DILATE,
                MORPH_ELLIPSE,
                ui->spinBox_SetFoci_04_Size->value() / 2,
                ui->spinBox_SetFoci_04_Size->value() / 2,
                BORDER_DEFAULT,
                1),
            "Update_Step_Foci",
            "c_ST_F_ROI_NUC_MARGIN");
    }
        break;

    case c_ST_F_ROI:
    {
        ERR(D_Img_Proc::Math_ImgImg_Diff(
                &(vMA_Foci[c_ST_F_ROI]),
                &(vMA_Plasma[c_ST_P_REG_PLASMA]),
                &(vMA_Foci[c_ST_F_ROI_NUC_MARGIN])),
            "Update_Step_Foci",
            "c_ST_F_ROI");
    }
        break;

    case c_ST_F_ROI_EDEGS:
    {
        ERR(D_Img_Proc::Filter_Laplace(
                &(vMA_Foci[c_ST_F_ROI_EDEGS]),
                &(vMA_Foci[c_ST_F_ROI]),
                5,
                BORDER_DEFAULT,
                CV_8U,
                1,
                0),
            "Update_Step_Foci",
            "c_ST_F_ROI_EDEGS");
    }
        break;

    case c_ST_F_OUT_CORES:
    {
        ERR(D_Img_Proc::Math_ImgImg_BitAnd(
                &(vMA_Foci[c_ST_F_OUT_CORES]),
                &(vMA_Foci[c_ST_F_ROI]),
                &(vMA_Foci[c_ST_F_BIN_THRES])),
            "Update_Step_Foci",
            "c_ST_F_OUT_CORES");
    }
        break;

    case c_ST_F_OUT_CORES_CLOSE:
    {
        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_Foci[c_ST_F_OUT_CORES_CLOSE]),
                &(vMA_Foci[c_ST_F_OUT_CORES]),
                MORPH_CLOSE,
                MORPH_ELLIPSE,
                ui->spinBox_SetFoci_05_Size->value() / 2,
                ui->spinBox_SetFoci_05_Size->value() / 2,
                BORDER_DEFAULT,
                1),
            "Update_Step_Foci",
            "c_ST_F_OUT_CORES_CLOSE");
    }
        break;

    case c_ST_F_OUT_CORES_AREA:
    {
        ERR(D_Img_Proc::Select_Area(
                &(vMA_Foci[c_ST_F_OUT_CORES_AREA]),
                &(vMA_Foci[c_ST_F_OUT_CORES_CLOSE]),
                ui->spinBox_SetFoci_06_Size_Min->value(),
                ui->spinBox_SetFoci_06_Size_Max->value(),
                8),
            "Update_Step_Foci",
            "c_ST_F_OUT_CORES_AREA");
    }
        break;

    case c_ST_F_CENTROID:
    {
        ERR(D_Img_Proc::Reduce_Centroid(
                &(vMA_Foci[c_ST_F_CENTROID]),
                &(vMA_Foci[c_ST_F_OUT_CORES_AREA]),
                1),
            "Update_Step_Foci",
            "c_ST_F_CENTROID");
    }
        break;

    case c_ST_F_REGIONS_NUCLEI:
    {
        ERR(D_Img_Proc::Threshold_Absolute_1C(
                &(vMA_Foci[c_ST_F_REGIONS_NUCLEI]),
                &(vMA_Cores[c_ST_C_SEGM_LABELS_FINAL]),
                0),
            "Update_Step_Foci",
            "c_ST_F_REGIONS_NUCLEI - Threshold_Absolute_1C");
    }
        break;

    case c_ST_F_REGIONS_SEEDS:
    {
        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_Foci[c_ST_F_REGIONS_SEEDS]),
                &(vMA_Foci[c_ST_F_REGIONS_NUCLEI]),
                MORPH_ERODE,
                MORPH_RECT,
                1,
                1,
                BORDER_DEFAULT,
                1),
            "Update_Step_Foci",
            "c_ST_F_REGIONS_SEEDS - Morphology_Elemental");
    }
        break;

    case c_ST_F_REGIONS_ROI2LABEL:
    {
        ERR(D_Img_Proc::Math_ImgImg_BitOr(
                &(vMA_Foci[c_ST_F_REGIONS_ROI2LABEL]),
                &(vMA_Foci[c_ST_F_ROI]),
                &(vMA_Foci[c_ST_F_ROI_NUC_MARGIN])),
            "Update_Step_Foci",
            "c_ST_F_REGIONS_ROI2LABEL - Math_ImgImg_BitOr");
    }
        break;

    case c_ST_F_REGIONS_CELLS_APPROX:
    {
        //qDebug() << "Segmentation and Labeling";
        ERR(D_Img_Proc::Transformation_Watershed_Auto(
                &(vMA_Foci[c_ST_F_REGIONS_CELLS_APPROX]),
                &(vMA_Foci[c_ST_F_REGIONS_ROI2LABEL]),
                &(vMA_Foci[c_ST_F_REGIONS_SEEDS]),
                false,
                false,
                ui->checkBox_SetFoci_13_ExcludeBordered->isChecked()),
            "Update_Step_Foci",
            "c_ST_F_REGIONS_CELLS_APPROX - Transformation_Watershed_Auto");
    }
        break;

    case c_ST_F_REGIONS_8BIT:
    {
        //qDebug() << "Normalization to 8bit";
        ERR(D_Img_Proc::Normalize(
                &(vMA_Foci[c_ST_F_REGIONS_8BIT]),
                &(vMA_Foci[c_ST_F_REGIONS_CELLS_APPROX]),
                CV_MINMAX,
                CV_8U,
                0,
                255),
            "Update_Step_Foci",
            "c_ST_F_REGIONS_8BIT");
    }
        break;

    case c_ST_F_CENTROID_CORES:
    {
        ERR(D_Img_Proc::Math_ImgImg_BitAnd(
                &(vMA_Foci[c_ST_F_CENTROID_CORES]),
                &(vMA_Foci[c_ST_F_CENTROID]),
                &(vMA_Foci[c_ST_F_REGIONS_8BIT])),
            "Update_Step_Foci",
            "c_ST_F_CENTROID_CORES");
    }
        break;

    default:
        break;
    }
}

void D_MAKRO_CoreFoci::Update_Step_Results(unsigned int step)
{
    if(FIL_Input_Images.empty())
        return;

    switch (step) {

    case c_ST_R_EMPTY:
    {
        vMA_Results[c_ST_R_EMPTY] = Mat(vMA_Cores[0].size(), CV_8UC1, Scalar(0));
    }
        break;

    case c_ST_R_C_INPUT:
    {
        if(vMA_Cores[c_ST_C_LOAD].type() == CV_16UC1)
            ERR(D_Img_Proc::Spread_16_bit_to_8bit(
                    &(vMA_Results[c_ST_R_C_INPUT]),
                    &(vMA_Cores[c_ST_C_LOAD]),
                    ui->spinBox_Results_SpreadMax->value(),
                    255),
                "Update_Step_Results",
                "c_ST_R_C_INPUT - Spread");
        else
            ERR(D_Img_Proc::Duplicate(
                    &(vMA_Results[c_ST_R_C_INPUT]),
                    &(vMA_Cores[c_ST_C_INPUT_CONV_8BIT])),
                "Update_Step_Results",
                "c_ST_R_C_INPUT - Copy");
    }
        break;

    case c_ST_R_C_CONTRAST:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_R_C_CONTRAST]),
                &(vMA_Cores[c_ST_C_INPUT_CONTRAST])),
            "Update_Step_Results",
            "c_ST_R_C_CONTRAST");
    }
        break;

    case c_ST_R_C_BINARY:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_R_C_BINARY]),
                &(vMA_Cores[c_ST_C_BIN_INV])),
            "Update_Step_Results",
            "c_ST_R_C_BINARY");
    }
        break;

    case c_ST_R_C_SEEDS:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_R_C_SEEDS]),
                &(vMA_Cores[c_ST_C_LMAX_DILATION])),
            "Update_Step_Results",
            "c_ST_R_C_SEEDS");
    }
        break;

    case c_ST_R_C_EDGES:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_R_C_EDGES]),
                &(vMA_Cores[c_ST_C_SEGM_EDGES])),
            "Update_Step_Results",
            "c_ST_R_C_EDGES");
    }
        break;

    case c_ST_R_P_INPUT:
    {
        if(vMA_Plasma[c_ST_P_LOAD].type() == CV_16UC1)
            ERR(D_Img_Proc::Spread_16_bit_to_8bit(
                    &(vMA_Results[c_ST_R_P_INPUT]),
                    &(vMA_Plasma[c_ST_P_LOAD]),
                    ui->spinBox_Results_SpreadMax->value(),
                    255),
                "Update_Step_Results",
                "c_ST_R_P_INPUT - Spread");
        else
            ERR(D_Img_Proc::Duplicate(
                    &(vMA_Results[c_ST_R_P_INPUT]),
                    &(vMA_Plasma[c_ST_P_INPUT_CONV_8BIT])),
                "Update_Step_Results",
                "c_ST_R_P_INPUT - Copy");
    }
        break;

    case c_ST_R_P_CONTRAST:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_R_P_CONTRAST]),
                &(vMA_Plasma[c_ST_P_INPUT_CONTRAST])),
            "Update_Step_Results",
            "c_ST_R_P_CONTRAST");
    }
        break;

    case c_ST_R_P_BINARY:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_R_P_BINARY]),
                &(vMA_Plasma[c_ST_P_REG_PLASMA])),
            "Update_Step_Results",
            "c_ST_R_P_BINARY");
    }
        break;

    case c_ST_R_P_EDGES:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_R_P_EDGES]),
                &(vMA_Plasma[c_ST_P_REG_PLASMA_EDGES])),
            "Update_Step_Results",
            "c_ST_R_P_EDGES");
    }
        break;

    case c_ST_R_F_INPUT:
    {
        if(vMA_Foci[c_ST_F_LOAD].type() == CV_16UC1)
            ERR(D_Img_Proc::Spread_16_bit_to_8bit(
                    &(vMA_Results[c_ST_R_F_INPUT]),
                    &(vMA_Foci[c_ST_F_LOAD]),
                    ui->spinBox_Results_SpreadMax->value(),
                    255),
                "Update_Step_Results",
                "c_ST_R_F_INPUT - Spread");
        else
            ERR(D_Img_Proc::Duplicate(
                    &(vMA_Results[c_ST_R_F_INPUT]),
                    &(vMA_Foci[c_ST_F_INPUT_CONV_8BIT])),
                "Update_Step_Results",
                "c_ST_R_F_INPUT - Copy");
    }
        break;

    case c_ST_R_F_CONTRAST:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_R_F_CONTRAST]),
                &(vMA_Foci[c_ST_F_INPUT_CONTRAST])),
            "Update_Step_Results",
            "c_ST_R_F_CONTRAST");
    }
        break;

    case c_ST_R_F_BINARY:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_R_F_BINARY]),
                &(vMA_Foci[c_ST_F_BIN_THRES])),
            "Update_Step_Results",
            "c_ST_R_F_BINARY");
    }
        break;

    case c_ST_R_F_SELECTED:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_R_F_SELECTED]),
                &(vMA_Foci[c_ST_F_OUT_CORES_AREA])),
            "Update_Step_Results",
            "c_ST_R_F_SELECTED");
    }
        break;

    case c_ST_R_F_DOT:
    {
        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_Results[c_ST_R_F_DOT]),
                &(vMA_Foci[c_ST_F_CENTROID]),
                MORPH_DILATE,
                MORPH_ELLIPSE,
                15,
                15,
                BORDER_DEFAULT,
                1),
            "Update_Step_Results",
            "c_ST_R_F_DOT");
    }
        break;

    case c_ST_R_R_ROI:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_R_R_ROI]),
                &(vMA_Foci[c_ST_F_ROI])),
            "Update_Step_Results",
            "c_ST_R_R_ROI");
    }
        break;

    case c_ST_R_R_ROI_EDGES:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_R_R_ROI_EDGES]),
                &(vMA_Foci[c_ST_F_ROI_EDEGS])),
            "Update_Step_Results",
            "c_ST_R_R_ROI_EDGES");
    }
        break;

    case c_ST_R_R_EDGES:
    {
        ERR(D_Img_Proc::Filter_Laplace(
                &(vMA_Results[c_ST_R_R_EDGES]),
                &(vMA_Foci[c_ST_F_REGIONS_8BIT]),
                5,
                BORDER_DEFAULT,
                CV_8UC1,
                1,
                0),
            "Update_Step_Results",
            "c_ST_R_R_EDGES");
    }
        break;

    default:
        break;
    }
}


void D_MAKRO_CoreFoci::Update_Combi_Results()
{
    if(FIL_Input_Images.empty())
        return;

    bool channels_use[4];
    channels_use[0] = true;
    channels_use[1] = true;
    channels_use[2] = true;
    channels_use[3] = false;

    ERR(D_Img_Proc::Merge(
            &(MA_Result),
            &(vMA_Results[ui->comboBox_View_Result_B->currentIndex()]),
            &(vMA_Results[ui->comboBox_View_Result_G->currentIndex()]),
            &(vMA_Results[ui->comboBox_View_Result_R->currentIndex()]),
            &(vMA_Results[0]),
            3,
            channels_use),
        "Update_Combi_Results",
        "Merge");

    Update_View_Results();
}

void D_MAKRO_CoreFoci::Update_Combi_Results_Preset(int preset)
{
    int r = 0;
    int g = 0;
    int b = 0;

    switch (preset) {

    case c_RES_COLOR_NORMAL:
        r = c_ST_R_P_INPUT;
        g = c_ST_R_F_INPUT;
        b = c_ST_R_C_INPUT;
        break;

    case c_RES_COLOR_CONTRAST:
        r = c_ST_R_P_CONTRAST;
        g = c_ST_R_F_CONTRAST;
        b = c_ST_R_C_CONTRAST;
        break;

    case c_RES_COLOR_NUCLEI:
        r = c_ST_R_C_CONTRAST;
        g = c_ST_R_C_EDGES;
        b = c_ST_R_C_SEEDS;
        break;

    case c_RES_COLOR_PLASMA:
        r = c_ST_R_P_CONTRAST;
        g = c_ST_R_P_EDGES;
        b = c_ST_R_C_BINARY;
        break;

    case c_RES_COLOR_FOCI:
        r = c_ST_R_F_CONTRAST;
        g = c_ST_R_R_EDGES;
        b = c_ST_R_F_DOT;
        break;

    case c_RES_COLOR_REGIONS:
        r = c_ST_R_R_ROI;
        g = c_ST_R_F_BINARY;
        b = c_ST_R_R_EDGES;
        break;

    default:
        break;
    }

    ui->tabWidget_View_Results->setCurrentIndex(0);
    View_BlockSignals(true);
    ui->comboBox_View_Result_R->setCurrentIndex(r);
    ui->comboBox_View_Result_G->setCurrentIndex(g);
    View_BlockSignals(false);
    ui->comboBox_View_Result_B->setCurrentIndex(b);
}

void D_MAKRO_CoreFoci::Update_Results()
{
    switch (ui->tabWidget_View_Results->currentIndex()) {

    case c_RES_IMAGE://=======================  image
        if(!calced_AttCel_cel)
            return;
        Update_Combi_Results();
        break;

    case c_RES_PLOT_CELLS://=======================  plot cells
    {
        if(!calced_AttSta_cel)
            return;

        switch (ui->comboBox_ResPlo_Cells_Type->currentIndex()) {

        case c_RESPLOCEL_ATT:
            Plot_Cells_Attribute();
            break;

        case c_RESPLOCEL_ATT_HIST:
            Plot_Cells_Attribute_Hist();
            break;

        case c_RESPLOCEL_ATT_SCATTER:
            Plot_Cells_Attribute_Scatter();
            break;

        default:
            break;
        }
    }
        break;

    case c_RES_TABLE_CELLS:

        switch (ui->comboBox_TabCell_Type->currentIndex()) {

        case c_TAB_BASIC:
            Table_Cells_AttCel();
            break;

        case c_TAB_STAT:
            Table_Cells_AttSta();
            break;

        default:
            break;
        }

        break;

    case c_RES_PLOT_IMAGE://=======================  plot image
    {
        Stack_Attributes_AskUpdate();

        switch (ui->comboBox_ResPlo_Img_Type->currentIndex()) {

        case c_RESPLOIMG_ATT:
            Plot_Image_Attribute();
            break;

        case c_RESPLOIMG_ATT_HIST:
            Plot_Image_Attribute_Hist();
            break;

        case c_RESPLOIMG_ATT_SCATTER:
            Plot_Image_Attribute_Scatter();
            break;

        default:
            break;
        }
    }
        break;

    case c_RES_TABLE_IMAGE:
        Stack_Attributes_AskUpdate();

        switch (ui->comboBox_TabImg_Type->currentIndex()) {

        case c_TAB_BASIC:
            Table_Image_AttImg();
            break;

        case c_TAB_STAT:
            Table_Image_AttSta();
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


void D_MAKRO_CoreFoci::Plot_Cells_Attribute()
{
    QStringList QSL_NucNames;
    for(size_t nuc = 0; nuc < vvd_AttCel_cel[ui->comboBox_ResPlo_Cells_Att_Att->currentIndex()].size(); nuc++)
        QSL_NucNames.append(QString::number(nuc));

    ERR(D_Plot::Plot_BarCore_Single(
                ChartView_Cells,
                vvd_AttCel_cel[ui->comboBox_ResPlo_Cells_Att_Att->currentIndex()],
                "Attributes of Cells",
                "Cells",
                QSL_NucNames,
                "Cells",
                ui->comboBox_ResPlo_Cells_Att_Att->currentText()),
            "Plot_Cells_Attribute",
            "Plot_BarCore_Single");
}

void D_MAKRO_CoreFoci::Plot_Cells_Attribute_Hist()
{
    //basic variables
    vector<double> v_hist;
    double x_min, x_max, y_max, step;

    //calc
    ERR(D_Stat::Calc_Vector2Hist_1(
            &v_hist,
            &(vvd_AttCel_cel[ui->comboBox_ResPlo_Cells_Att_Hist_Att->currentIndex()]),
            ui->spinBox_ResPlo_Cells_Att_Hist_Classes->value(),
            &x_min,
            &x_max,
            &y_max,
            &step,
            ui->checkBox_ResPlo_Cells_Att_Hist_Acc->isChecked(),
            ui->checkBox_ResPlo_Cells_Att_Hist_Uni->isChecked()),
        "Plot_Cells_Attribute_Hist",
        "Claculate Histogram");

    //plot
    ERR(D_Plot::Plot_Hist_Single_Classes(
            ChartView_Cells,
            &v_hist,
            x_min,
            step,
            "Histogram",
            "Cells",
            ui->comboBox_ResPlo_Cells_Att_Hist_Att->currentText(),
            "Amount of Cells",
            false),
        "Plot_Cells_Attribute_Hist",
        "Plot Histogram");
}

void D_MAKRO_CoreFoci::Plot_Cells_Attribute_Scatter()
{
    ERR(D_Plot::Plot_Scatter_2D_Single_Y(
            ChartView_Cells,
            &(vvd_AttCel_cel[ui->comboBox_ResPlo_Cells_Att_Scatter_Att_X->currentIndex()]),
            &(vvd_AttCel_cel[ui->comboBox_ResPlo_Cells_Att_Scatter_Att_Y->currentIndex()]),
            "Cell Attributes Scatter",
            "Cells",
            ui->comboBox_ResPlo_Cells_Att_Scatter_Att_X->currentText() + " of Cells",
            ui->comboBox_ResPlo_Cells_Att_Scatter_Att_Y->currentText() + " of Cells"),
        "Plot_Cells_Attribute_Scatter",
        "Plot_Scatter_2D_Single_Y");
}

void D_MAKRO_CoreFoci::Plot_Image_Attribute()
{
    if(!stack_processed)
    {
        D_Plot::Plot_Empty(ChartView_Image);
        return;
    }

    QStringList QSl_CellsStack;
    for(size_t cel = 0; cel < vvd_AttCel_cel_stack[0].size(); cel++)
        QSl_CellsStack.append("Cell_" + QString::number(cel));

    ERR(D_Plot::Plot_BarCore_Single(
                ChartView_Image,
                vvd_AttCel_cel_stack[ui->comboBox_ResPlo_Img_Att_Att->currentIndex()],
                "Attributes of Cells",
                "Cells (in stack)",
                QSl_CellsStack,
                "Cells (in stack)",
                ui->comboBox_ResPlo_Img_Att_Att->currentText()),
            "Plot_Image_Attribute",
            "Plot_BarCore_Single");
}

void D_MAKRO_CoreFoci::Plot_Image_Attribute_Hist()
{
    if(!stack_processed)
    {
        D_Plot::Plot_Empty(ChartView_Image);
        return;
    }

    //basic variables
    vector<double> v_hist;
    double x_min, x_max, y_max, step;

    //calc
    ERR(D_Stat::Calc_Vector2Hist_1(
            &v_hist,
            &(vvd_AttCel_cel_stack[ui->comboBox_ResPlo_Img_Att_Hist_Att->currentIndex()]),
            ui->spinBox_ResPlo_Img_Att_Hist_Classes->value(),
            &x_min,
            &x_max,
            &y_max,
            &step,
            ui->checkBox_ResPlo_Img_Att_Hist_Acc->isChecked(),
            ui->checkBox_ResPlo_Img_Att_Hist_Uni->isChecked()),
        "Plot_Image_Attribute_Hist",
        "Claculate Histogram");

    //plot
    ERR(D_Plot::Plot_Hist_Single_Classes(
            ChartView_Image,
            &v_hist,
            x_min,
            step,
            "Histogram",
            "Cells (in stack)",
            ui->comboBox_ResPlo_Img_Att_Hist_Att->currentText(),
            "Amount of Cells",
            false),
        "Plot_Image_Attribute_Hist",
        "Plot Histogram");
}

void D_MAKRO_CoreFoci::Plot_Image_Attribute_Scatter()
{
    if(!stack_processed)
    {
        D_Plot::Plot_Empty(ChartView_Image);
        return;
    }

    ERR(D_Plot::Plot_Scatter_2D_Single_Y(
            ChartView_Image,
            &(vvd_AttCel_cel_stack[ui->comboBox_ResPlo_Img_Att_Scatter_Att_X->currentIndex()]),
            &(vvd_AttCel_cel_stack[ui->comboBox_ResPlo_Img_Att_Scatter_Att_Y->currentIndex()]),
            "Cell Attributes Scatter (Stack)",
            "Cells (in stack)",
            ui->comboBox_ResPlo_Img_Att_Scatter_Att_X->currentText() + " of Cells (in stack)",
            ui->comboBox_ResPlo_Img_Att_Scatter_Att_Y->currentText() + " of Cells (in stack)"),
        "Plot_Image_Attribute_Scatter",
            "Plot_Scatter_2D_Single_Y");
}

void D_MAKRO_CoreFoci::Table_Cells_AttCel()
{
    if(!calced_AttCel_cel)
        return;

    Table_CellStat.set_data_d_2D_qsl_count(
                vvd_AttCel_cel,
                QSL_AttCel);
}

void D_MAKRO_CoreFoci::Table_Cells_AttSta()
{
    if(!calced_AttSta_cel)
        return;

    Table_CellStat.set_data_d_2D_qsl_qsl(
                vvd_AttSta_cel,
                QSL_AttCel,
                QSL_StatList);
}

void D_MAKRO_CoreFoci::Table_Image_AttImg()
{
    if(!calced_AttCel_cel_stack)
        return;

    QStringList QSl_CellsStack;
    for(size_t cel = 0; cel < vvd_AttCel_cel_stack[0].size(); cel++)
        QSl_CellsStack.append("Cell_" + QString::number(cel));

    Table_ImageStat.set_data_d_2D_qsl_qsl(
                vvd_AttCel_cel_stack,
                QSL_AttCel,
                QSl_CellsStack);
}

void D_MAKRO_CoreFoci::Table_Image_AttSta()
{
    if(!calced_AttSta_cel_stack)
        return;

    Table_ImageStat.set_data_d_2D_qsl_qsl(
                vvd_AttSta_cel_stack,
                QSL_AttCel,
                QSL_StatList);
}

void D_MAKRO_CoreFoci::Table_Summary()
{
    if(!calced_AttSta_cel)
        return;

    //single
    QStringList QSL_Summary_Single =
    {
        "Nuclei Number",
        "Nuclei Area",
        "Cytoplasma Area",
        "Foci Number"
    };

    vector<double> vd_Summary_Single;
    vd_Summary_Single.resize(QSL_Summary_Single.size());
    vd_Summary_Single[0] = vvd_AttSta_cel[c_ATT_CELL_NUCLEUS_AREA][c_STAT_COUNT];
    vd_Summary_Single[1] = vvd_AttSta_cel[c_ATT_CELL_NUCLEUS_AREA][c_STAT_SUM];
    vd_Summary_Single[2] = vvd_AttSta_cel[c_ATT_CELL_CYTO_AREA][c_STAT_SUM];
    vd_Summary_Single[3] = vvd_AttSta_cel[c_ATT_CELL_FOCI_COUNT][c_STAT_SUM];

    Table_Summary_Single.set_data_d_1D_qs_qsl(
                vd_Summary_Single,
                "Simple",
                QSL_Summary_Single);

    //quotients
    QStringList QSL_Summary_Quotients =
    {
        "Nuclei Area / Nuclei Number",
        "Nuclei Area / Cytoplasma Area",
        "Cytoplasma Area / Nuclei Number",
        "Cytoplasma Area / Nuclei Area",
        "Foci Number / Nuclei Number",
        "Foci Number / Nuclei Area",
        "Foci Number / Cytoplasma Area"
    };

    vector<double> vd_Summary_Quotients;
    vd_Summary_Quotients.resize(QSL_Summary_Quotients.size());
    vd_Summary_Quotients[0] = vd_Summary_Single[1] / vd_Summary_Single[0];
    vd_Summary_Quotients[1] = vd_Summary_Single[1] / vd_Summary_Single[2];
    vd_Summary_Quotients[2] = vd_Summary_Single[2] / vd_Summary_Single[0];
    vd_Summary_Quotients[3] = vd_Summary_Single[2] / vd_Summary_Single[1];
    vd_Summary_Quotients[4] = vd_Summary_Single[3] / vd_Summary_Single[0];
    vd_Summary_Quotients[5] = vd_Summary_Single[3] / vd_Summary_Single[1];
    vd_Summary_Quotients[6] = vd_Summary_Single[3] / vd_Summary_Single[2];

    Table_Summary_Quotients.set_data_d_1D_qs_qsl(
                vd_Summary_Quotients,
                "Quotients",
                QSL_Summary_Quotients);
}

void D_MAKRO_CoreFoci::Parameters_Init()
{
    vvd_ParameterPresets_SetPar.clear();
    vvd_ParameterPresets_SetPar.resize(c_PRESET_NUMBER_OF);

    //NIKON
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON].clear();
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON].resize(c_PAR_NUMBER_OF);

    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_NUC_BLUR_SIZE]             = 33.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_NUC_BLUR_SIGMA]            = 26.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_NUC_THRES_SIZE]            = 401.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_NUC_THRES_OFFSET]          = -2.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_NUC_AREA_FILL]             = 450000.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_NUC_EILENSTEIN_SIZE]       = 25.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_NUC_EILENSTEIN_OFFSET]     = 0.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_NUC_LOCMAX_THRES]          = 208.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_NUC_REMOVE_SMALL]          = 5.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_NUC_CONNECT_NEAR]          = 29.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_NUC_EXCULDE_BORDER]        = 0.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_NUC_AREA_DIST_MIN]         = 1;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_NUC_AREA_DIST_MAX]         = 2;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_NUC_AREA_MAX_SMALL]        = 2500;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_NUC_AREA_MIN_BIG]          = 4000;

    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_CYT_BLUR_SIZE]             = 15.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_CYT_BLUR_SIGMA]            = 7.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_CTT_THRES_SIZE]            = 31;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_CYT_THRES_SIGMA]           = -2.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_CYT_CLOSE_HOLES]           = 105.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_CYT_MARGIN]                = 27.0;

    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_FOCI_BLUR_SIZE]            = 13.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_FOCI_BLUR_SIGMA]           = 6.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][c_PAR_FOCI_THRES_SIZE]           = 51.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][C_PAR_FOCI_THRES_SIGMA]          = 0.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][C_PAR_FOCI_MARGIN]               = 25.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][C_PAR_FOCI_CONNECT_NEAR]         = 3.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][C_PAR_FOCI_AREA_MIN]             = 5.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][C_PAR_FOCI_AREA_MAX]             = 1000.0;
    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][C_PAR_FOCI_EXCLUDE_BORDER]       = 1.0;

    vvd_ParameterPresets_SetPar[c_PRESET_NIKON][C_PAR_FOCI_RES_MAX_EXPECTED]     = 15000.0;



    //LEICA
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA].clear();
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA].resize(c_PAR_NUMBER_OF);

    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_NUC_BLUR_SIZE]           = 3.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_NUC_BLUR_SIGMA]          = 18.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_NUC_THRES_SIZE]          = 201.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_NUC_THRES_OFFSET]        = -2.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_NUC_AREA_FILL]           = 100000.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_NUC_EILENSTEIN_SIZE]     = 25.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_NUC_EILENSTEIN_OFFSET]   = 0.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_NUC_LOCMAX_THRES]        = 208.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_NUC_REMOVE_SMALL]        = 5.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_NUC_CONNECT_NEAR]        = 5.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_NUC_EXCULDE_BORDER]      = 0.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_NUC_AREA_DIST_MIN]       = 1;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_NUC_AREA_DIST_MAX]       = 2;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_NUC_AREA_MAX_SMALL]      = 250;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_NUC_AREA_MIN_BIG]        = 500;

    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_CYT_BLUR_SIZE]           = 7.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_CYT_BLUR_SIGMA]          = 7.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_CTT_THRES_SIZE]          = 15.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_CYT_THRES_SIGMA]         = -2.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_CYT_CLOSE_HOLES]         = 43.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_CYT_MARGIN]              = 15.0;

    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_FOCI_BLUR_SIZE]          = 7.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_FOCI_BLUR_SIGMA]         = 6.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][c_PAR_FOCI_THRES_SIZE]         = 31.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][C_PAR_FOCI_THRES_SIGMA]        = -13.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][C_PAR_FOCI_MARGIN]             = 11.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][C_PAR_FOCI_CONNECT_NEAR]       = 3.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][C_PAR_FOCI_AREA_MIN]           = 2.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][C_PAR_FOCI_AREA_MAX]           = 250.0;
    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][C_PAR_FOCI_EXCLUDE_BORDER]     = 1.0;

    vvd_ParameterPresets_SetPar[c_PRESET_LEICA][C_PAR_FOCI_RES_MAX_EXPECTED]   = 255.0;
}

void D_MAKRO_CoreFoci::Parameters_ActivatePreset()
{
    int preset_index = ui->comboBox_Preset->currentIndex();

    if(preset_index >= c_PRESET_NUMBER_OF)
        return;

    Proc_BlocSignals(true);

    //Nuclei
    ui->spinBox_SetCore_02_Gauss_Size->setValue(                static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_NUC_BLUR_SIZE]));
    ui->doubleSpinBox_SetCore_02_Gauss_Sigma->setValue(         static_cast<double>(vvd_ParameterPresets_SetPar[preset_index][c_PAR_NUC_BLUR_SIGMA]));
    ui->spinBox_SetCore_04_Thres_Size->setValue(                static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_NUC_THRES_SIZE]));
    ui->doubleSpinBox_SetCore_04_Thres_Offset->setValue(        static_cast<double>(vvd_ParameterPresets_SetPar[preset_index][c_PAR_NUC_THRES_OFFSET]));
    ui->spinBox_SetCore_05_Fill_Area->setValue(                 static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_NUC_AREA_FILL]));
    ui->spinBox_SetCore_09_Eilenstein_Size->setValue(           static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_NUC_EILENSTEIN_SIZE]));
    ui->doubleSpinBox_Set_Core_09_Eilenstein_Offset->setValue(  static_cast<double>(vvd_ParameterPresets_SetPar[preset_index][c_PAR_NUC_EILENSTEIN_OFFSET]));
    ui->spinBox_SetCore_11_Thresh_Thres->setValue(              static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_NUC_LOCMAX_THRES]));
    ui->spinBox_SetCore_12_Open_Area->setValue(                 static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_NUC_REMOVE_SMALL]));
    ui->spinBox_SetCore_13_Dilation_Size->setValue(             static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_NUC_CONNECT_NEAR]));
    ui->checkBox_SetCore_13_ExcludeBordered->setChecked(        static_cast<bool>(  vvd_ParameterPresets_SetPar[preset_index][c_PAR_NUC_EXCULDE_BORDER]));
    ui->spinBox_SetCore_14_AreaDistMin->setValue(               static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_NUC_AREA_DIST_MIN]));
    ui->spinBox_SetCore_14_AreaDistMax->setValue(               static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_NUC_AREA_DIST_MAX]));
    ui->spinBox_SetCore_14_AreaMaxOfSmall->setValue(            static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_NUC_AREA_MAX_SMALL]));
    ui->spinBox_SetCore_14_AreaMinOfBig->setValue(              static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_NUC_AREA_MIN_BIG]));

    //Cytoplasm
    ui->spinBox_SetCyto_Gauss_Size->setValue(                   static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_CYT_BLUR_SIZE]));
    ui->doubleSpinBox_SetCyto_Gauss_Sigma->setValue(            static_cast<double>(vvd_ParameterPresets_SetPar[preset_index][c_PAR_CYT_BLUR_SIGMA]));
    ui->spinBox_SetCyto_Thresh_Size->setValue(                  static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_CTT_THRES_SIZE]));
    ui->doubleSpinBox_SetCyto_Thresh_Offset->setValue(          static_cast<double>(vvd_ParameterPresets_SetPar[preset_index][c_PAR_CYT_THRES_SIGMA]));
    ui->spinBox_SetCyto_Closing_Size->setValue(                 static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_CYT_CLOSE_HOLES]));
    ui->spinBox_SetCyto_Dilation_Size->setValue(                static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_CYT_MARGIN]));

    //Foci
    ui->spinBox_SetFoci_02_Size->setValue(                      static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_FOCI_BLUR_SIZE]));
    ui->doubleSpinBox_SetFoci_02_Sigma->setValue(               static_cast<double>(vvd_ParameterPresets_SetPar[preset_index][c_PAR_FOCI_BLUR_SIGMA]));
    ui->spinBox_SetFoci_03_Size->setValue(                      static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][c_PAR_FOCI_THRES_SIZE]));
    ui->doubleSpinBox_SetFoci_03_Offset->setValue(              static_cast<double>(vvd_ParameterPresets_SetPar[preset_index][C_PAR_FOCI_THRES_SIGMA]));
    ui->spinBox_SetFoci_04_Size->setValue(                      static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][C_PAR_FOCI_MARGIN]));
    ui->spinBox_SetFoci_05_Size->setValue(                      static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][C_PAR_FOCI_CONNECT_NEAR]));
    ui->spinBox_SetFoci_06_Size_Min->setValue(                  static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][C_PAR_FOCI_AREA_MIN]));
    ui->spinBox_SetFoci_06_Size_Max->setValue(                  static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][C_PAR_FOCI_AREA_MAX]));
    ui->checkBox_SetFoci_13_ExcludeBordered->setChecked(        static_cast<bool>(  vvd_ParameterPresets_SetPar[preset_index][C_PAR_FOCI_EXCLUDE_BORDER]));

    //Results
    ui->spinBox_Results_SpreadMax->setValue(                    static_cast<int>(   vvd_ParameterPresets_SetPar[preset_index][C_PAR_FOCI_RES_MAX_EXPECTED]));

    Proc_BlocSignals(false);
}

void D_MAKRO_CoreFoci::Calc_All()
{
    qDebug() << "Calc_All";
    Calc_Cells_Attrib();
    Calc_Cells_Stats();

    Update_Results();
    Table_Summary();
}

void D_MAKRO_CoreFoci::Calc_Cells_Attrib()
{
    calced_AttCel_cel = false;
    //qDebug() << "Calc_Cells_Attrib";

    //qDebug() << "Clear - (old size:" << vvd_AttCel_cel.size() << ")";
    vvd_AttCel_cel.clear();
    //qDebug() << "Resize";
    vvd_AttCel_cel.resize(c_ATT_CELL_NUMBER_OF);
    //qDebug() << "new vectors";
    vector<double> v_area;
    vector<double> v_objects;

    //qDebug() << "Calc_Cells_Attrib - Split_ObjectAreas - Nuclei";
    v_area.clear();
    v_objects.clear();
    ERR(D_Img_Proc::Split_ObjectAreas(
                &(v_objects),                           //Nuclei count
                &(v_area),                              //Nuclei area
                &(vMA_Foci[c_ST_F_REGIONS_CELLS_APPROX]),            //Regions
                &(vMA_Cores[c_ST_C_BIN_INV]),           //Nuclei binary
                4),
        "Calc_Cells_Attrib",
        "Nuclei");
    vvd_AttCel_cel[c_ATT_CELL_NUCLEUS_AREA] = v_area;

    //qDebug() << "Calc_Cells_Attrib - Split_ObjectAreas - Cytoplasma";
    v_area.clear();
    v_objects.clear();
    ERR(D_Img_Proc::Split_ObjectAreas(
                &(v_objects),                           //Cytoplasma count
                &(v_area),                              //Cytoplasma area
                &(vMA_Foci[c_ST_F_REGIONS_CELLS_APPROX]),            //Regions
                &(vMA_Foci[c_ST_F_ROI]),                //Cytoplasma binary
                4),
        "Calc_Cells_Attrib",
        "Cytoplasma");
    vvd_AttCel_cel[c_ATT_CELL_CYTO_AREA] = v_area;

    //qDebug() << "Calc_Cells_Attrib - Split_ObjectAreas - Foci";
    v_area.clear();
    v_objects.clear();
    ERR(D_Img_Proc::Split_ObjectAreas(
                &(v_objects),                           //Foci count
                &(v_area),                              //Foci area
                &(vMA_Foci[c_ST_F_REGIONS_CELLS_APPROX]),            //Regions
                &(vMA_Foci[c_ST_F_OUT_CORES_AREA]),     //Foci binary
                4),
        "Calc_Cells_Attrib",
        "Foci");
    vvd_AttCel_cel[c_ATT_CELL_FOCI_AREA] = v_area;
    vvd_AttCel_cel[c_ATT_CELL_FOCI_COUNT] = v_objects;

    //---------------------------------------------------------------------- statistical attributes

    //Mask the roi-label-cell image with nuclei (get nuclei areas of interest)
    Mat MA_MaskedLabels;
    ERR(D_Img_Proc::Mask_1C(
                &(MA_MaskedLabels),             //nuclei labels (gaps possible)
                &(vMA_Foci[c_ST_F_REGIONS_CELLS_APPROX]),    //labels (cells)
                &(vMA_Cores[c_ST_C_BIN_INV])),  //mask (nuclei)
        "Calc_Cells_Attrib",
        "Mask_1C - mask cells with nuclei (crop nuc area of interest with cell label numbers)");

    //extract values by components
    vector<vector<double>> vv_NucVal;
    ERR(D_Img_Proc::Split_img2vv_value(
                &vv_NucVal,
                &(vMA_Cores[c_ST_C_LOAD]),
                &(MA_MaskedLabels),
                true),
        "Calc_Cells_Attrib",
        "Split_img2vv_value (nuclei)");

    //calc stats of values in components
    vector<vector<double>> vv_NucSta;
    vv_NucSta.resize(vv_NucVal.size());
    for(size_t c = 0; c < vv_NucVal.size(); c++)
        ERR(D_Stat::Calc_Stats(
                    &(vv_NucSta[c]),
                    vv_NucVal[c],
                    true),
            "Calc_Cells_Attrib",
            "Calc_Stats - Nucleus " + QString::number(c));

    //extract statistical attributes
    vector<double> v_NucMean;
    //vector<double> v_NucSumI;
    v_NucMean.resize(vv_NucSta.size());
    //v_NucSumI.resize(vv_NucSta.size());
    for(size_t c = 0; c < vv_NucVal.size(); c++)
    {
        v_NucMean[c] = vv_NucSta[c][c_STAT_MEAN_ARITMETIC];
        //v_NucSumI[c] = vv_NucSta[c][c_STAT_SUM];
    }
    vvd_AttCel_cel[c_ATT_CELL_NUCLEUS_MEAN_I] = v_NucMean;
    //vvd_AttCel_cel[C_ATT_CELL_NUCLEUS_SUM_I] = v_NucSumI;

    MA_MaskedLabels.release();
    calced_AttCel_cel = true;
}

void D_MAKRO_CoreFoci::Calc_Cells_Stats()
{
    if(!calced_AttCel_cel)
        return;
    calced_AttSta_cel = false;
    qDebug() << "Calc_Cells_Stats";

    //clear & resize
    vvd_AttSta_cel.clear();
    vvd_AttSta_cel.resize(vvd_AttCel_cel.size());

    for(size_t att = 0; att < vvd_AttSta_cel.size(); att++)
        ERR(D_Stat::Calc_Stats(
                &(vvd_AttSta_cel[att]),
                vvd_AttCel_cel[att],
                true),
            "Calc_Cells_Stats",
            "Calc_Stats");

    calced_AttSta_cel = true;
}

void D_MAKRO_CoreFoci::Load_Images()
{
    //qDebug() << "Load_Images";

    QStringList QSL_Paths = QFileDialog::getOpenFileNames(
                this,
                "Load Images",
                pStore->dir_M_dsDNA()->path(),
                tr("Image Files - 16bit, 3 Page (Nuclei, Foci, Cytoplasma), Grayscale (*.tif *.tiff *.TIF *.TIFF)"));

    if(QSL_Paths.empty())
        return;

    //append stack
    QSL_Input_Images.append(QSL_Paths);

    //get filenames
    FIL_Input_Images.clear();
    QSL_BaseNames.clear();
    QSL_FileNames.clear();
    for(int i = 0; i < QSL_Input_Images.size(); i++)
    {
        QFileInfo FI_Img_In(QSL_Input_Images[i]);

        if(FI_Img_In.exists())
        {
            FIL_Input_Images.append(FI_Img_In);
            QSL_BaseNames.append(FI_Img_In.baseName());
            QSL_FileNames.append(FI_Img_In.fileName());
        }
    }

    //add to ui
    ui->comboBox_FileName->blockSignals(true);
    ui->comboBox_FileName->clear();
    for(int i = 0; i < QSL_Input_Images.size(); i++)
        ui->comboBox_FileName->addItem(FIL_Input_Images[i].fileName());
    ui->comboBox_FileName->blockSignals(false);

    if(QSL_BaseNames.size() != 0)
        QS_BaseName_Current = QSL_BaseNames[0];
    if(QSL_FileNames.size() != 0)
        QS_FileName_Current = QSL_FileNames[0];

    //export file
    pStore->set_dir_M_dsDNA(QSL_Input_Images.first());

    //update
    Update_ImgProc_All();
    ui->tabWidget->setCurrentIndex(1);//settings
}

void D_MAKRO_CoreFoci::Next_Image()
{
    if(ui->comboBox_FileName->currentIndex() >= (FIL_Input_Images.size() - 1))
    {
        QMessageBox MSG;
        MSG.setText("End of queue.");
        MSG.setInformativeText("Please load new images or select another image.");
        MSG.exec();
    }
    else
    {
        ui->comboBox_FileName->setCurrentIndex(ui->comboBox_FileName->currentIndex() + 1);
    }
}

void D_MAKRO_CoreFoci::Clear_Images()
{
    stack_processed = false;
    stack_processing = false;
    calced_AttCel_cel = false;
    calced_AttSta_cel = false;
    calced_AttCel_cel_stack = false;
    calced_AttSta_cel_stack = false;
    QSL_Input_Images.clear();
    FIL_Input_Images.clear();
    ui->comboBox_FileName->blockSignals(true);
    ui->comboBox_FileName->clear();
    ui->comboBox_FileName->blockSignals(false);
    Table_ImageStat.clear_data();
    Table_CellStat.clear_data();
    Table_Summary_Single.clear_data();
    Table_Summary_Quotients.clear_data();
    V_Nuclei.clear_Image();
    V_Plasma.clear_Image();
    V_Foci.clear_Image();
    V_Results.clear_Image();
    D_Plot::Plot_Empty(ChartView_Cells);
    D_Plot::Plot_Empty(ChartView_Image);
}


void D_MAKRO_CoreFoci::Stack_Attributes_AskUpdate()
{
    if(stack_processed)
        return;

    if(stack_processing)
        return;

    if(FIL_Input_Images.empty())
        return;

    if(QMessageBox::question(
                this,
                "Stack processing not updated!",
                "Do you want to <b>update stack processing</b> now?"
                "<br><br>This may take some time, depending on your system and stack size."
                "<br>Stack size: <b>" + QString::number(FIL_Input_Images.size()) + "</b> images."
                "<br><br>If it is not updated, plots and table for images won't make sence."
                "<br><br><I>This question is asked because you tried to watch image results, change results tab to avoid it.</I>",
                QMessageBox::Yes,
                QMessageBox::No)
            == QMessageBox::Yes)
        Stack_Attributes_Process();
}

void D_MAKRO_CoreFoci::Stack_Attributes_Process()
{
    stack_processed = false;
    stack_processing = true;
    calced_AttCel_cel_stack = false;
    this->setEnabled(false);

    Stack_Attributes_Stream_Init();

    Stack_Attributes_Init();
    Stack_Attributes_Stream_Parameters();

    for(int img = 0; img < FIL_Input_Images.size(); img++)
    {
        qDebug() << "========================= Stack Processing:  " << img + 1 << "out of" << FIL_Input_Images.size();

        //for acces out of this method:
        stack_img_curent = img;

        ui->comboBox_FileName->setCurrentIndex(img);    //Update img proc and calc automatically triggered (if it is not updated anyway)

        Stack_Attributes_Calc();
        Stack_Attributes_Stream_Cells();
    }

    calced_AttCel_cel_stack = true;
    stack_processing = false;
    stack_processed = true;

    Stack_Attributes_Calc_Stats();
    Stack_Attributes_Stream_Images();

    Update_Results();
    this->setEnabled(true);

    qDebug() << "========================= Stack Processing:  FINISHED :-)";
}

void D_MAKRO_CoreFoci::Stack_Attributes_Init()
{
    vvd_AttCel_cel_stack.clear();
    vvd_AttSta_cel_stack.clear();
    vvd_AttCel_cel_stack.resize(c_ATT_CELL_NUMBER_OF);
    vvd_AttSta_cel_stack.resize(c_ATT_CELL_NUMBER_OF);
}

void D_MAKRO_CoreFoci::Stack_Attributes_Calc()
{
    if(!calced_AttSta_cel)
    {
        ERR(ER_empty, "Stack_Attributes_Calc", "Stats of cells in image is not calculated yet.");
        return;
    }

    //extend list of cell attribs in stack with all cell attribs in current img
    for(size_t att = 0; att < c_ATT_CELL_NUMBER_OF; att++)
        for(size_t cel = 0; cel < vvd_AttCel_cel[att].size(); cel++)
            vvd_AttCel_cel_stack  [att].push_back(vvd_AttCel_cel[att][cel]);
}

void D_MAKRO_CoreFoci::Stack_Attributes_Calc_Stats()
{
    //check
    if(!calced_AttCel_cel_stack)
    {
        ERR(ER_empty, "Stack_Attributes_Stream", "Attributes of images are not calculated yet.");
        return;
    }
    calced_AttSta_cel_stack = false;

    //clear & resize
    vvd_AttSta_cel_stack.clear();
    vvd_AttSta_cel_stack.resize(vvd_AttCel_cel_stack.size());

    for(size_t att = 0; att < vvd_AttSta_cel_stack.size(); att++)
        ERR(D_Stat::Calc_Stats(
                &(vvd_AttSta_cel_stack[att]),
                vvd_AttCel_cel_stack[att],
                true),
            "Stack_Attributes_Calc_Stats",
            "Calc_Stats");

    calced_AttSta_cel_stack = true;
}

void D_MAKRO_CoreFoci::Stack_Attributes_Stream_Init()
{
    QString ST_Dir = QFileDialog::getExistingDirectory(
                this,
                "Select folder to stream the output to.",
                pStore->dir_M_dsDNA()->path());

    if(ST_Dir == 0)
    {
        dont_stream = true;
        return;
    }
    else
    {
        dont_stream = false;
    }

    //create subfolder for output
    unsigned int count = 0;
    QString QS_Folder_Out_Main = ST_Dir + "/Results_0";
    while(QDir(QS_Folder_Out_Main).exists())
    {
        count++;
        QS_Folder_Out_Main = ST_Dir + "/Results_" + QString::number(count);
    }

    //DIRs

    //main
    QDir().mkdir(QS_Folder_Out_Main);
    DIR_Stream_Main.setPath(QS_Folder_Out_Main);

    //stack/image
    QDir().mkdir(QS_Folder_Out_Main + "/Stack");
    DIR_Stream_Stack.setPath(QS_Folder_Out_Main + "/Stack");
    QDir().mkdir(QS_Folder_Out_Main + "/Images");
    DIR_Stream_Images.setPath(QS_Folder_Out_Main + "/Images");

    //stack
    DIR_Stream_Stack_Images.setPath(DIR_Stream_Stack.path() + "/Images");
    QDir().mkdir(DIR_Stream_Stack_Images.path());
    DIR_Stream_Stack_Tables.setPath(DIR_Stream_Stack.path() + "/Tables");
    QDir().mkdir(DIR_Stream_Stack_Tables.path());
    DIR_Stream_Stack_Plots.setPath(DIR_Stream_Stack.path() + "/Plots");
    QDir().mkdir(DIR_Stream_Stack_Plots.path());

    //Other
    DIR_Stream_Other.setPath(DIR_Stream_Main.path() + "/Other");
    QDir().mkdir(DIR_Stream_Other.path());

    //get vectors of output choises

    //img - img
    v_StreamImage_Images.clear();
    v_StreamImage_Images.resize(c_RES_COLOR_NUMBER_OF, 0);
    v_StreamImage_Images[c_RES_COLOR_NORMAL]                = static_cast<int>(ui->checkBox_OutImg_Img_Normal->checkState());
    v_StreamImage_Images[c_RES_COLOR_CONTRAST]              = static_cast<int>(ui->checkBox_OutImg_Img_Contrast->checkState());
    v_StreamImage_Images[c_RES_COLOR_NUCLEI]                = static_cast<int>(ui->checkBox_OutImg_Img_Nuclei->checkState());
    v_StreamImage_Images[c_RES_COLOR_PLASMA]                = static_cast<int>(ui->checkBox_OutImg_Img_Plasma->checkState());
    v_StreamImage_Images[c_RES_COLOR_FOCI]                  = static_cast<int>(ui->checkBox_OutImg_Img_Foci->checkState());
    v_StreamImage_Images[c_RES_COLOR_REGIONS]               = static_cast<int>(ui->checkBox_OutImg_Img_Regions->checkState());

    //img - attributes
    v_StreamImage_PlotAttrib.clear();
    v_StreamImage_PlotAttrib.resize(c_ATT_CELL_NUMBER_OF, 0);
    v_StreamImage_PlotAttrib[c_ATT_CELL_NUCLEUS_AREA]       = static_cast<int>(ui->checkBox_OutImg_Plots_NucArea->checkState());
    v_StreamImage_PlotAttrib[c_ATT_CELL_CYTO_AREA]          = static_cast<int>(ui->checkBox_OutImg_Plots_CytArea->checkState());
    v_StreamImage_PlotAttrib[c_ATT_CELL_FOCI_COUNT]         = static_cast<int>(ui->checkBox_OutImg_Plots_FocNumber->checkState());
    v_StreamImage_PlotAttrib[c_ATT_CELL_FOCI_AREA]          = static_cast<int>(ui->checkBox_OutImg_Plots_FocArea->checkState());
    v_StreamImage_PlotAttrib[c_ATT_CELL_NUCLEUS_MEAN_I]     = static_cast<int>(ui->checkBox_OutImg_Plots_NucMeanInt->checkState());

    //stack - img
    v_StreamStack_Images.clear();
    v_StreamStack_Images.resize(c_RES_COLOR_NUMBER_OF, 0);
    v_StreamStack_Images[c_RES_COLOR_NORMAL]                = static_cast<int>(ui->checkBox_OutStack_Img_Normal->checkState());
    v_StreamStack_Images[c_RES_COLOR_CONTRAST]              = static_cast<int>(ui->checkBox_OutStack_Img_Contrast->checkState());
    v_StreamStack_Images[c_RES_COLOR_NUCLEI]                = static_cast<int>(ui->checkBox_OutStack_Img_Nuclei->checkState());
    v_StreamStack_Images[c_RES_COLOR_PLASMA]                = static_cast<int>(ui->checkBox_OutStack_Img_Plasma->checkState());
    v_StreamStack_Images[c_RES_COLOR_FOCI]                  = static_cast<int>(ui->checkBox_OutStack_Img_Foci->checkState());
    v_StreamStack_Images[c_RES_COLOR_REGIONS]               = static_cast<int>(ui->checkBox_OutStack_Img_Regions->checkState());

    //stack - attributes
    v_StreamStack_PlotAttrib.clear();
    v_StreamStack_PlotAttrib.resize(c_ATT_CELL_NUMBER_OF, 0);
    v_StreamStack_PlotAttrib[c_ATT_CELL_NUCLEUS_AREA]       = static_cast<int>(ui->checkBox_OutImg_Plots_NucArea->checkState());
    v_StreamStack_PlotAttrib[c_ATT_CELL_CYTO_AREA]          = static_cast<int>(ui->checkBox_OutImg_Plots_CytArea->checkState());
    v_StreamStack_PlotAttrib[c_ATT_CELL_FOCI_COUNT]         = static_cast<int>(ui->checkBox_OutImg_Plots_FocNumber->checkState());
    v_StreamStack_PlotAttrib[c_ATT_CELL_FOCI_AREA]          = static_cast<int>(ui->checkBox_OutImg_Plots_FocArea->checkState());
    v_StreamStack_PlotAttrib[c_ATT_CELL_NUCLEUS_MEAN_I]     = static_cast<int>(ui->checkBox_OutImg_Plots_NucMeanInt->checkState());

    //stack stream img subfolders
    for(size_t i = 0; i < v_StreamStack_Images.size(); i++)
        if(v_StreamStack_Images[i])
            QDir().mkdir(DIR_Stream_Stack_Images.path() + "/" + QSL_ResColor_Presets[static_cast<int>(i)]);
}

void D_MAKRO_CoreFoci::Stack_Attributes_Stream_Parameters()
{
    if(dont_stream)
        return;

    ofstream OS_Parameters;
    OS_Parameters.open(DIR_Stream_Other.path().toStdString() + "/Parameters.csv");

    OS_Parameters
            << "File,"          << "Parameters.csv" << "\n"
            << "DateTime,"      << QDateTime::currentDateTime().toString().toStdString() << "\n"
            << "\n"
            << "NUCLEI" << "\n"
            << "\n"
            << "03,"    << "Size/Sigma,"    << ui->spinBox_SetCore_02_Gauss_Size->value()           << "," << ui->doubleSpinBox_SetCore_02_Gauss_Sigma->value() << "\n"
            << "04,"    << "Size/Offset,"   << ui->spinBox_SetCore_04_Thres_Size->value()           << "," << ui->doubleSpinBox_SetCore_04_Thres_Offset->value() << "\n"
            << "05,"    << "Area,"          << ui->spinBox_SetCore_05_Fill_Area->value()            << "\n"
            << "08,"    << "Size/Offset,"   << ui->spinBox_SetCore_09_Eilenstein_Size->value()      << "," << ui->doubleSpinBox_Set_Core_09_Eilenstein_Offset->value() << "\n"
            << "10,"    << "Threshold,"     << ui->spinBox_SetCore_11_Thresh_Thres->value()         << "\n"
            << "11,"    << "Size,"          << ui->spinBox_SetCore_12_Open_Area->value()            << "\n"
            << "12,"    << "Size,"          << ui->spinBox_SetCore_13_Dilation_Size->value()        << "\n"
            << "13,"    << "Options,"       << static_cast<int>(ui->checkBox_SetCore_13_ExcludeBordered->isChecked())   << "\n"
            << "\n"
            << "CYTOPLASMA" << "\n"
            << "\n"
            << "03,"    << "Size/Sigma,"    << ui->spinBox_SetCyto_Gauss_Size->value()              << "," << ui->doubleSpinBox_SetCyto_Gauss_Sigma->value() << "\n"
            << "04,"    << "Size/Offset,"   << ui->spinBox_SetCyto_Thresh_Size->value()             << "," << ui->doubleSpinBox_SetCyto_Thresh_Offset->value() << "\n"
            << "05,"    << "Size,"          << ui->spinBox_SetCyto_Closing_Size->value()            << "\n"
            << "06,"    << "Size,"          << ui->spinBox_SetCyto_Dilation_Size->value()           << "\n"
            << "\n"
            << "FOCI" << "\n"
            << "\n"
            << "03,"    << "Size/Sigma,"    << ui->spinBox_SetFoci_02_Size->value()                 << "," << ui->doubleSpinBox_SetFoci_02_Sigma->value() << "\n"
            << "04,"    << "Size/Offset,"   << ui->spinBox_SetFoci_03_Size->value()                 << "," << ui->doubleSpinBox_SetFoci_03_Offset->value() << "\n"
            << "05,"    << "Size,"          << ui->spinBox_SetFoci_04_Size->value()                 << "\n"
            << "09,"    << "Size,"          << ui->spinBox_SetFoci_05_Size->value()                 << "\n"
            << "10,"    << "Area Min/Max,"  << ui->spinBox_SetFoci_06_Size_Min->value()             << "," << ui->spinBox_SetFoci_06_Size_Max->value() << "\n"
            << "12,"    << "Options,"       << static_cast<int>(ui->checkBox_SetFoci_13_ExcludeBordered->isChecked())   << "\n"
            << "\n"
            << "RESULTS" << "\n"
            << "\n"
            << "Col,"   << "Max Expected,"  << ui->spinBox_Results_SpreadMax->value()               << "\n";

    ui->tabWidget->setCurrentIndex(1); //show settings
    this->setEnabled(true);
    ui->tabWidget->grab().save(DIR_Stream_Other.path() + "/Parameters.jpg", 0, -1);
    this->setEnabled(false);

    OS_Parameters.close();
}

void D_MAKRO_CoreFoci::Stack_Attributes_Stream_Cells()
{
    if(dont_stream)
        return;

    //create folder for image
    DIR_Stream_Images_Sub.setPath(DIR_Stream_Images.path() + "/" + QS_FileName_Current);
    QDir().mkdir(DIR_Stream_Images_Sub.path());

    //Stream
    Stack_Attributes_Stream_Cells_Images();
    Stack_Attributes_Stream_Cells_Tables();
    Stack_Attributes_Stream_Cells_Plots();
}

void D_MAKRO_CoreFoci::Stack_Attributes_Stream_Cells_Images()
{
    if(dont_stream)
        return;

    //create folder for images
    QString QS_BaseSavePath_img = DIR_Stream_Images_Sub.path() + "/Images";
    QDir().mkdir(QS_BaseSavePath_img);

    for(size_t i = 0; i < v_StreamImage_Images.size(); i++)
    {
        if(v_StreamImage_Images[i])
        {
            Update_Combi_Results_Preset(static_cast<int>(i));
            V_Results.Save_Image(QS_BaseSavePath_img + "/" + QSL_ResColor_Presets[static_cast<int>(i)] + ".jpg");
        }

        if(v_StreamStack_Images[i])
        {
            Update_Combi_Results_Preset(static_cast<int>(i));
            V_Results.Save_Image(DIR_Stream_Stack_Images.path() + "/" + QSL_ResColor_Presets[static_cast<int>(i)] + "/" + QSL_ResColor_Presets[static_cast<int>(i)] + " - " + QSL_FileNames[stack_img_curent] + ".jpg");
        }
    }

    //proc steps
    if(ui->checkBox_OutImg_Img_ProcSteps->isChecked())
    {
        //create folder for proc steps
        QString QS_BaseSavePath_proc_steps = QS_BaseSavePath_img + "/Image_Processing_Steps";
        QDir().mkdir(QS_BaseSavePath_proc_steps);

        //nuclei
        QString QS_BaseSavePath_proc_steps_nuclei = QS_BaseSavePath_proc_steps + "/1 - Nuclei";
        QDir().mkdir(QS_BaseSavePath_proc_steps_nuclei);
        for(int i = 0; i < c_ST_C_NUMBER_OF; i++)
        {
            ui->comboBox_View_Cores->setCurrentIndex(i);
            V_Nuclei.Save_Image(QS_BaseSavePath_proc_steps_nuclei + "/" + ui->comboBox_View_Cores->currentText() + ".jpg");
        }

        //cytoplasma
        QString QS_BaseSavePath_proc_steps_cyto = QS_BaseSavePath_proc_steps + "/2 - Cytoplasma";
        QDir().mkdir(QS_BaseSavePath_proc_steps_cyto);
        for(int i = 0; i < c_ST_P_NUMBER_OF; i++)
        {
            ui->comboBox_View_Cyto->setCurrentIndex(i);
            V_Plasma.Save_Image(QS_BaseSavePath_proc_steps_cyto + "/" + ui->comboBox_View_Cyto->currentText() + ".jpg");
        }

        //nuclei
        QString QS_BaseSavePath_proc_steps_foci = QS_BaseSavePath_proc_steps + "/3 - Foci";
        QDir().mkdir(QS_BaseSavePath_proc_steps_foci);
        for(int i = 0; i < c_ST_F_NUMBER_OF; i++)
        {
            ui->comboBox_View_Foci->setCurrentIndex(i);
            V_Foci.Save_Image(QS_BaseSavePath_proc_steps_foci + "/" + ui->comboBox_View_Foci->currentText() + ".jpg");
        }
    }
}

void D_MAKRO_CoreFoci::Stack_Attributes_Stream_Cells_Tables()
{
    if(dont_stream)
        return;

    //create folder for tables
    QString QS_BaseSavePath_tab = DIR_Stream_Images_Sub.path() + "/Tables";
    QDir().mkdir(QS_BaseSavePath_tab);

    if(ui->checkBox_OutImg_Table_Raw->isChecked())
    {
        Table_Cells_AttCel();
        Table_CellStat.Save_Table(QS_BaseSavePath_tab + "/Attributes_Raw.csv");
    }

    if(ui->checkBox_OutImg_Table_Stat->isChecked())
    {
        Table_Cells_AttSta();
        Table_CellStat.Save_Table(QS_BaseSavePath_tab + "/Attributes_Statistics.csv");
    }
}

void D_MAKRO_CoreFoci::Stack_Attributes_Stream_Cells_Plots()
{
    if(dont_stream)
        return;

    ui->groupBox_View_Cores->setVisible(false);
    ui->groupBox_View_Cyto->setVisible(false);
    ui->groupBox_View_Foci->setVisible(false);
    ui->groupBox_View_Result->setVisible(true);

    ui->tabWidget_View_Results->setCurrentIndex(c_RES_PLOT_CELLS);

    //create folder for plots
    QString QS_BaseSavePath_plot = DIR_Stream_Images_Sub.path() + "/Plots";
    QDir().mkdir(QS_BaseSavePath_plot);

    //attributes
    if(ui->checkBox_OutImg_Plots_Bar->isChecked())
    {
        QString QS_BaseSavePath_plot_bar = QS_BaseSavePath_plot + "/Barplot";
        QDir().mkdir(QS_BaseSavePath_plot_bar);
        ui->comboBox_ResPlo_Cells_Type->setCurrentIndex(c_RESPLOCEL_ATT);

        for(size_t att = 0; att < v_StreamImage_PlotAttrib.size(); att++)
            if(v_StreamImage_PlotAttrib[att])
            {
                ui->comboBox_ResPlo_Cells_Att_Att->setCurrentIndex(static_cast<int>(att));
                Save_Plot(
                            ChartView_Cells,
                            QS_BaseSavePath_plot_bar + "/Barplot - " + QSL_AttCel[static_cast<int>(att)] + ".jpg");
            }
    }

    //attributes histogram
    if(ui->checkBox_OutImg_Plots_Hist->isChecked())
    {
        QString QS_BaseSavePath_plot_hist = QS_BaseSavePath_plot + "/Histogram";
        QDir().mkdir(QS_BaseSavePath_plot_hist);
        ui->comboBox_ResPlo_Cells_Type->setCurrentIndex(c_RESPLOCEL_ATT_HIST);

        for(size_t att = 0; att < v_StreamImage_PlotAttrib.size(); att++)
            if(v_StreamImage_PlotAttrib[att])
            {
                ui->comboBox_ResPlo_Cells_Att_Hist_Att->setCurrentIndex(static_cast<int>(att));
                Save_Plot(
                            ChartView_Cells,
                            QS_BaseSavePath_plot_hist + "/Histogram - " + QSL_AttCel[static_cast<int>(att)] + ".jpg");
            }
    }

    //attributes scatter
    if(ui->checkBox_OutImg_Plots_Scatter->isChecked())
    {
        QString QS_BaseSavePath_plot_scatter = QS_BaseSavePath_plot + "/Scatter";
        QDir().mkdir(QS_BaseSavePath_plot_scatter);
        ui->comboBox_ResPlo_Cells_Type->setCurrentIndex(c_RESPLOCEL_ATT_SCATTER);

        for(size_t att_x = 0; att_x < v_StreamImage_PlotAttrib.size(); att_x++)                            //att x
            for(size_t att_y = 0; att_y < v_StreamImage_PlotAttrib.size(); att_y++)                        //att y
                if(att_x < att_y)                                                                       //only one way
                    if(v_StreamImage_PlotAttrib[att_x] > 1)                                             //tick
                        if(v_StreamImage_PlotAttrib[att_y] > 1)                                         //tick
                        {
                            ui->comboBox_ResPlo_Cells_Att_Scatter_Att_X->setCurrentIndex(static_cast<int>(att_x));
                            ui->comboBox_ResPlo_Cells_Att_Scatter_Att_Y->setCurrentIndex(static_cast<int>(att_y));
                            Save_Plot(
                                        ChartView_Cells,
                                        QS_BaseSavePath_plot_scatter + "/Scatter - " + QSL_AttCel[static_cast<int>(att_y)] + " vs " + QSL_AttCel[static_cast<int>(att_x)] + ".jpg");
                        }
    }

    ui->groupBox_View_Cores->setVisible(true);
    ui->groupBox_View_Cyto->setVisible(true);
    ui->groupBox_View_Foci->setVisible(true);
    ui->groupBox_View_Result->setVisible(true);
    Update_Ui();
}

void D_MAKRO_CoreFoci::Stack_Attributes_Stream_Images()
{
    if(dont_stream)
        return;

    //Stack_Attributes_Stream_Images_Images();
    Stack_Attributes_Stream_Images_Tables();
    Stack_Attributes_Stream_Images_Plots();
}

void D_MAKRO_CoreFoci::Stack_Attributes_Stream_Images_Images()
{
    if(dont_stream)
        return;

    //done in: Stack_Attributes_Stream_Cells_Images
}

void D_MAKRO_CoreFoci::Stack_Attributes_Stream_Images_Tables()
{
    if(dont_stream)
        return;

    if(ui->checkBox_OutStack_Table_Raw->isChecked())
    {
        Table_Image_AttImg();
        Table_ImageStat.Save_Table(DIR_Stream_Stack_Tables.path() + "/Attributes_Raw - stack.csv");
    }

    if(ui->checkBox_OutStack_Table_Stat->isChecked())
    {
        Table_Image_AttSta();
        Table_ImageStat.Save_Table(DIR_Stream_Stack_Tables.path() + "/Attributes_Statistics - stack.csv");
    }
}

void D_MAKRO_CoreFoci::Stack_Attributes_Stream_Images_Plots()
{
    if(dont_stream)
        return;

    ui->groupBox_View_Cores->setVisible(false);
    ui->groupBox_View_Cyto->setVisible(false);
    ui->groupBox_View_Foci->setVisible(false);
    ui->groupBox_View_Result->setVisible(true);

    ui->tabWidget_View_Results->setCurrentIndex(c_RES_PLOT_IMAGE);

    //attributes
    if(ui->checkBox_OutImg_Plots_Bar->isChecked())
    {
        QString QS_BaseSavePath_plot_bar = DIR_Stream_Stack_Plots.path() + "/Barplot";
        QDir().mkdir(QS_BaseSavePath_plot_bar);
        ui->comboBox_ResPlo_Img_Type->setCurrentIndex(c_RESPLOIMG_ATT);

        for(size_t att = 0; att < v_StreamStack_PlotAttrib.size(); att++)
            if(v_StreamStack_PlotAttrib[att])
            {
                ui->comboBox_ResPlo_Img_Att_Att->setCurrentIndex(static_cast<int>(att));
                Save_Plot(
                            ChartView_Image,
                            QS_BaseSavePath_plot_bar + "/Barplot - " + QSL_AttCel[static_cast<int>(att)] + " - stack.jpg");
            }
    }

    //attributes histogram
    if(ui->checkBox_OutImg_Plots_Hist->isChecked())
    {
        QString QS_BaseSavePath_plot_hist = DIR_Stream_Stack_Plots.path() + "/Histogram";
        QDir().mkdir(QS_BaseSavePath_plot_hist);
        ui->comboBox_ResPlo_Img_Type->setCurrentIndex(c_RESPLOIMG_ATT_HIST);

        for(size_t att = 0; att < v_StreamStack_PlotAttrib.size(); att++)
            if(v_StreamStack_PlotAttrib[att])
            {
                ui->comboBox_ResPlo_Img_Att_Hist_Att->setCurrentIndex(static_cast<int>(att));
                Save_Plot(
                            ChartView_Image,
                            QS_BaseSavePath_plot_hist + "/Histogram - " + QSL_AttCel[static_cast<int>(att)] + " - stack.jpg");
            }
    }

    //attributes scatter
    if(ui->checkBox_OutImg_Plots_Scatter->isChecked())
    {
        QString QS_BaseSavePath_plot_scatter = DIR_Stream_Stack_Plots.path() + "/Scatter";
        QDir().mkdir(QS_BaseSavePath_plot_scatter);
        ui->comboBox_ResPlo_Img_Type->setCurrentIndex(c_RESPLOIMG_ATT_SCATTER);

        for(size_t att_x = 0; att_x < v_StreamStack_PlotAttrib.size(); att_x++)                            //att x
            for(size_t att_y = 0; att_y < v_StreamStack_PlotAttrib.size(); att_y++)                        //att y
                if(att_x < att_y)                                                                       //only one way
                    if(v_StreamStack_PlotAttrib[att_x] > 1)                                             //tick
                        if(v_StreamStack_PlotAttrib[att_y] > 1)                                         //tick
                        {
                            ui->comboBox_ResPlo_Img_Att_Scatter_Att_X->setCurrentIndex(static_cast<int>(att_x));
                            ui->comboBox_ResPlo_Img_Att_Scatter_Att_Y->setCurrentIndex(static_cast<int>(att_y));
                            Save_Plot(
                                        ChartView_Image,
                                        QS_BaseSavePath_plot_scatter + "/Scatter - " + QSL_AttCel[static_cast<int>(att_y)] + " vs " + QSL_AttCel[static_cast<int>(att_x)] + " - stack.jpg");
                        }
    }

    ui->groupBox_View_Cores->setVisible(true);
    ui->groupBox_View_Cyto->setVisible(true);
    ui->groupBox_View_Foci->setVisible(true);
    ui->groupBox_View_Result->setVisible(true);
    Update_Ui();
}

void D_MAKRO_CoreFoci::Save_Image_Cores()
{
    if(FIL_Input_Images.empty())
        return;

    QString name_default =
            pStore->dir_M_dsDNA()->absolutePath() + "/" +
            QS_FileName_Current + " - " +
            ui->comboBox_View_Cores->currentText() +
            ".jpg";

    if(B_Stream_Out)
        V_Nuclei.Save_Image();
    else
    {
        QString save_path = V_Nuclei.Save_Image_Dialog(name_default);
        if(save_path != 0)
            pStore->set_dir_M_dsDNA(save_path);
    }
}

void D_MAKRO_CoreFoci::Save_Image_Plasma()
{
    if(FIL_Input_Images.empty())
        return;

    QString name_default =
            pStore->dir_M_dsDNA()->absolutePath() + "/" +
            QS_FileName_Current + " - " +
            ui->comboBox_View_Cyto->currentText() +
            ".jpg";

    if(B_Stream_Out)
        V_Plasma.Save_Image();
    else
    {
        QString save_path = V_Plasma.Save_Image_Dialog(name_default);
        if(save_path != 0)
            pStore->set_dir_M_dsDNA(save_path);
    }
}

void D_MAKRO_CoreFoci::Save_Image_Foci()
{
    if(FIL_Input_Images.empty())
        return;

    QString name_default =
            pStore->dir_M_dsDNA()->absolutePath() + "/" +
            QS_FileName_Current + " - " +
            ui->comboBox_View_Foci->currentText() +
            ".jpg";

    if(B_Stream_Out)
        V_Foci.Save_Image();
    else
    {
        QString save_path = V_Foci.Save_Image_Dialog(name_default);
        if(save_path != 0)
            pStore->set_dir_M_dsDNA(save_path);
    }
}

void D_MAKRO_CoreFoci::Save_Image_Results()
{
    if(FIL_Input_Images.empty())
        return;

    QString name_default =
            pStore->dir_M_dsDNA()->absolutePath() + "/" +
            QS_FileName_Current +
            " - R " + ui->comboBox_View_Result_R->currentText() +
            " - G " + ui->comboBox_View_Result_G->currentText() +
            " - B " + ui->comboBox_View_Result_B->currentText() +
            ".jpg";

    if(B_Stream_Out)
        V_Results.Save_Image();
    else
    {
        QString save_path = V_Results.Save_Image_Dialog(name_default);
        if(save_path != 0)
            pStore->set_dir_M_dsDNA(save_path);
    }
}

void D_MAKRO_CoreFoci::Save_Plot_Cells()
{
    QString name_save = QFileDialog::getSaveFileName(this,
                                                 tr("Save plot as image"),
                                                 pStore->dir_M_dsDNA()->path() + "/plot_cells.jpg",
                                                 tr("Images (*.png *.jpg *.bmp *.tif)"));
    if(name_save == 0)
        return;

    QPixmap pixmap_save = ChartView_Cells->grab();
    pixmap_save.save(name_save, 0, -1);
}

void D_MAKRO_CoreFoci::Save_Plot_Image()
{
    QString name_save = QFileDialog::getSaveFileName(this,
                                                 tr("Save plot as image"),
                                                 pStore->dir_M_dsDNA()->path() + "/plot_cells.jpg",
                                                 tr("Images (*.png *.jpg *.bmp *.tif)"));
    if(name_save == 0)
        return;

    QPixmap pixmap_save = ChartView_Image->grab();
    pixmap_save.save(name_save, 0, -1);
}

void D_MAKRO_CoreFoci::Save_Plot(QChartView *pCV, QString path)
{
    if(path == 0)
        return;

    QPixmap pixmap_save = pCV->grab();
    pixmap_save.save(path, 0, -1);
}

void D_MAKRO_CoreFoci::Populate_CB()
{
    Populate_CB(ui->comboBox_View_Cores, QSL_StepNuclei);
    Populate_CB(ui->comboBox_View_Cyto, QSL_StepPlasma);
    Populate_CB(ui->comboBox_View_Foci, QSL_StepFoci);

    Populate_CB(ui->comboBox_ResPlo_Cells_Type, QSL_ResPloCel);

    Populate_CB(ui->comboBox_ResPlo_Cells_Att_Att, QSL_AttCel);
    Populate_CB(ui->comboBox_ResPlo_Cells_Att_Hist_Att, QSL_AttCel);
    Populate_CB(ui->comboBox_ResPlo_Cells_Att_Scatter_Att_X, QSL_AttCel);
    Populate_CB(ui->comboBox_ResPlo_Cells_Att_Scatter_Att_Y, QSL_AttCel);

    Populate_CB(ui->comboBox_ResPlo_Img_Type, QSL_ResPloCel);

    Populate_CB(ui->comboBox_ResPlo_Img_Att_Att, QSL_AttCel);
    Populate_CB(ui->comboBox_ResPlo_Img_Att_Hist_Att, QSL_AttCel);
    Populate_CB(ui->comboBox_ResPlo_Img_Att_Scatter_Att_X, QSL_AttCel);
    Populate_CB(ui->comboBox_ResPlo_Img_Att_Scatter_Att_Y, QSL_AttCel);

    Populate_CB(ui->comboBox_TabCell_Type, QSL_TabeleTypes);
    Populate_CB(ui->comboBox_TabImg_Type, QSL_TabeleTypes);

    Populate_CB(ui->comboBox_Preset, QSL_PresetNames);
}

void D_MAKRO_CoreFoci::Populate_CB(QComboBox *CB, QStringList QSL)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->blockSignals(false);
}

void D_MAKRO_CoreFoci::View_BlockSignals(bool block)
{
    ui->comboBox_View_Cores->blockSignals(block);
    ui->comboBox_View_Cyto->blockSignals(block);
    ui->comboBox_View_Foci->blockSignals(block);
    ui->comboBox_View_Result_R->blockSignals(block);
    ui->comboBox_View_Result_G->blockSignals(block);
    ui->comboBox_View_Result_B->blockSignals(block);
}

void D_MAKRO_CoreFoci::Proc_BlocSignals(bool block)
{
    //Nuclei
    ui->spinBox_SetCore_02_Gauss_Size->blockSignals(block);
    ui->doubleSpinBox_SetCore_02_Gauss_Sigma->blockSignals(block);
    ui->spinBox_SetCore_04_Thres_Size->blockSignals(block);
    ui->doubleSpinBox_SetCore_04_Thres_Offset->blockSignals(block);
    ui->spinBox_SetCore_05_Fill_Area->blockSignals(block);
    ui->spinBox_SetCore_09_Eilenstein_Size->blockSignals(block);
    ui->doubleSpinBox_Set_Core_09_Eilenstein_Offset->blockSignals(block);
    ui->spinBox_SetCore_11_Thresh_Thres->blockSignals(block);
    ui->spinBox_SetCore_12_Open_Area->blockSignals(block);
    ui->spinBox_SetCore_13_Dilation_Size->blockSignals(block);
    ui->checkBox_SetCore_13_ExcludeBordered->blockSignals(block);

    //Cytoplasm
    ui->spinBox_SetCyto_Gauss_Size->blockSignals(block);
    ui->doubleSpinBox_SetCyto_Gauss_Sigma->blockSignals(block);
    ui->spinBox_SetCyto_Thresh_Size->blockSignals(block);
    ui->doubleSpinBox_SetCyto_Thresh_Offset->blockSignals(block);
    ui->spinBox_SetCyto_Closing_Size->blockSignals(block);
    ui->spinBox_SetCyto_Dilation_Size->blockSignals(block);

    //Foci
    ui->spinBox_SetFoci_02_Size->blockSignals(block);
    ui->doubleSpinBox_SetFoci_02_Sigma->blockSignals(block);
    ui->spinBox_SetFoci_03_Size->blockSignals(block);
    ui->doubleSpinBox_SetFoci_03_Offset->blockSignals(block);
    ui->spinBox_SetFoci_04_Size->blockSignals(block);
    ui->spinBox_SetFoci_05_Size->blockSignals(block);
    ui->spinBox_SetFoci_06_Size_Min->blockSignals(block);
    ui->spinBox_SetFoci_06_Size_Max->blockSignals(block);
    ui->checkBox_SetFoci_13_ExcludeBordered->blockSignals(block);

    //Results
    ui->spinBox_Results_SpreadMax->blockSignals(block);
}

void D_MAKRO_CoreFoci::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_MAKRO_dsDNA", func, detail);
}





void D_MAKRO_CoreFoci::on_spinBox_SetFoci_02_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Foci(c_ST_F_INPUT_BLUR);
}

void D_MAKRO_CoreFoci::on_doubleSpinBox_SetFoci_02_Sigma_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Foci(c_ST_F_INPUT_BLUR);
}

void D_MAKRO_CoreFoci::on_spinBox_SetFoci_03_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Foci(c_ST_F_BIN_THRES);
}

void D_MAKRO_CoreFoci::on_doubleSpinBox_SetFoci_03_Offset_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Foci(c_ST_F_BIN_THRES);
}

void D_MAKRO_CoreFoci::on_spinBox_SetFoci_04_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Foci(c_ST_F_ROI_NUC_MARGIN);
}

void D_MAKRO_CoreFoci::on_spinBox_SetFoci_05_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Foci(c_ST_F_OUT_CORES_CLOSE);
}

void D_MAKRO_CoreFoci::on_spinBox_SetFoci_06_Size_Min_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Foci(c_ST_F_OUT_CORES_AREA);
}

void D_MAKRO_CoreFoci::on_spinBox_SetFoci_06_Size_Max_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Foci(c_ST_F_OUT_CORES_AREA);
}

void D_MAKRO_CoreFoci::on_checkBox_SetFoci_13_ExcludeBordered_clicked()
{
    Update_ImgProc_Foci(c_ST_F_REGIONS_CELLS_APPROX);
}

void D_MAKRO_CoreFoci::on_spinBox_SetCore_02_Gauss_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cores(c_ST_C_INPUT_BLUR);
}

void D_MAKRO_CoreFoci::on_doubleSpinBox_SetCore_02_Gauss_Sigma_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Cores(c_ST_C_INPUT_BLUR);
}

void D_MAKRO_CoreFoci::on_spinBox_SetCore_04_Thres_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cores(c_ST_C_BIN_THRES);
}

void D_MAKRO_CoreFoci::on_doubleSpinBox_SetCore_04_Thres_Offset_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Cores(c_ST_C_BIN_THRES);
}

void D_MAKRO_CoreFoci::on_spinBox_SetCore_05_Fill_Area_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cores(c_ST_C_BIN_AREA);
}

void D_MAKRO_CoreFoci::on_spinBox_SetCore_09_Eilenstein_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cores(c_ST_C_RANK_EILENSTEIN);
}

void D_MAKRO_CoreFoci::on_doubleSpinBox_Set_Core_09_Eilenstein_Offset_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Cores(c_ST_C_RANK_EILENSTEIN);
}

void D_MAKRO_CoreFoci::on_spinBox_SetCore_11_Thresh_Thres_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cores(c_ST_C_LMAX_BIN);
}

void D_MAKRO_CoreFoci::on_spinBox_SetCore_12_Open_Area_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cores(c_ST_C_LMAX_OPEN);
}

void D_MAKRO_CoreFoci::on_spinBox_SetCore_13_Dilation_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cores(c_ST_C_LMAX_DILATION);
}

void D_MAKRO_CoreFoci::on_checkBox_SetCore_13_ExcludeBordered_clicked()
{
    Update_ImgProc_Cores(c_ST_C_SEGM_WATERSHADE);
}

void D_MAKRO_CoreFoci::on_doubleSpinBox_SetCyto_Gauss_Sigma_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Plasma(c_ST_P_INPUT_BLUR);
}

void D_MAKRO_CoreFoci::on_spinBox_SetCyto_Gauss_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Plasma(c_ST_P_INPUT_BLUR);
}

void D_MAKRO_CoreFoci::on_spinBox_SetCyto_Thresh_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Plasma(c_ST_P_BIN_THRES);
}

void D_MAKRO_CoreFoci::on_doubleSpinBox_SetCyto_Thresh_Offset_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Plasma(c_ST_P_BIN_THRES);
}

void D_MAKRO_CoreFoci::on_spinBox_SetCyto_Closing_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Plasma(c_ST_P_MORPH_CLOSE);
}

void D_MAKRO_CoreFoci::on_spinBox_SetCyto_Dilation_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Plasma(c_ST_P_MORPH_DILATE);
}

void D_MAKRO_CoreFoci::on_spinBox_Results_SpreadMax_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Results(c_ST_R_C_INPUT);
}

void D_MAKRO_CoreFoci::on_pushButton_ResCol_Preset_ContrastAll_clicked()
{
    Update_Combi_Results_Preset(c_RES_COLOR_CONTRAST);
}

void D_MAKRO_CoreFoci::on_pushButton_ResCol_Preset_NormalAll_clicked()
{
    Update_Combi_Results_Preset(c_RES_COLOR_NORMAL);
}

void D_MAKRO_CoreFoci::on_pushButton_ResCol_Preset_NucSegmentation_clicked()
{
    Update_Combi_Results_Preset(c_RES_COLOR_NUCLEI);
}

void D_MAKRO_CoreFoci::on_pushButton_ResCol_Preset_Regions_clicked()
{
    Update_Combi_Results_Preset(c_RES_COLOR_REGIONS);
}

void D_MAKRO_CoreFoci::on_pushButton_ResCol_Preset_Foci_clicked()
{
    Update_Combi_Results_Preset(c_RES_COLOR_FOCI);
}

void D_MAKRO_CoreFoci::on_pushButton_ResCol_Preset_Plasma_clicked()
{
    Update_Combi_Results_Preset(c_RES_COLOR_PLASMA);
}

void D_MAKRO_CoreFoci::on_comboBox_FileName_currentIndexChanged(int index)
{
    QS_BaseName_Current = FIL_Input_Images[index].baseName();
    QS_FileName_Current = FIL_Input_Images[index].fileName();
    Update_ImgProc_All();
}

void D_MAKRO_CoreFoci::on_pushButton_PresetActivate_clicked()
{
    Parameters_ActivatePreset();
    Update_ImgProc_All();
}

void D_MAKRO_CoreFoci::on_spinBox_SetCore_14_AreaDistMin_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Results(c_ST_C_SEGM_AREA_CONNECT);
}

void D_MAKRO_CoreFoci::on_spinBox_SetCore_14_AreaDistMax_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Results(c_ST_C_SEGM_AREA_CONNECT);
}

void D_MAKRO_CoreFoci::on_spinBox_SetCore_14_AreaMaxOfSmall_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Results(c_ST_C_SEGM_AREA_CONNECT);
}

void D_MAKRO_CoreFoci::on_spinBox_SetCore_14_AreaMinOfBig_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Results(c_ST_C_SEGM_AREA_CONNECT);
}
