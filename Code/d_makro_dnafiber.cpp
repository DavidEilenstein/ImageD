#include "d_makro_dnafiber.h"
#include "ui_d_makro_dnafiber.h"

D_MAKRO_DnaFiber::D_MAKRO_DnaFiber(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_DnaFiber)
{
    //ui
    ui->setupUi(this);
    Populate_CB();
    Init_Images();

    //Store
    pStore = pStorage;

    //Param
    vParam.resize(PARAM_NUMBER_OF, 0);

    //Dirs
    DIR_SaveDefault.setPath(pStore->dir_M_DnaFibre()->path());

    //Viewer
    View_Proc.set_GV(ui->graphicsView_ImgProc);
    View_Results.set_GV(ui->graphicsView_ResVis);
    View_Proc.connect_Zoom(&View_Results);

    //Plot
    pChartView_DiameterHist = new QChartView();
    ui->gridLayout_ResAna_DiaHist->addWidget(pChartView_DiameterHist);
    pChartView_DiameterHist->setRenderHint(QPainter::Antialiasing);
    pChartView_DiameterHist->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_DiameterHist->setInteractive(true);

    pChartView_InputHist = new QChartView();
    ui->gridLayout_ResAna_InputHist->addWidget(pChartView_InputHist);
    pChartView_InputHist->setRenderHint(QPainter::Antialiasing);
    pChartView_InputHist->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_InputHist->setInteractive(true);

    //Table
    Table_DiameterStat.set_TW(ui->tableWidget_ResAna_DiaStat);
    Table_Euler.set_TW(ui->tableWidget_ResAna_Euler);
    Table_PixelRatio.set_TW(ui->tableWidget_ResAna_PixelRatio);

    //Connects
    connect(ui->action_Load_Images,                     SIGNAL(triggered(bool)),                    this,       SLOT(Load_Images()));
    connect(ui->action_Save_Analysis_Single,            SIGNAL(triggered(bool)),                    this,       SLOT(UpdateSave_AllSingle()));
    connect(ui->action_Save_Analysis_Stack,             SIGNAL(triggered(bool)),                    this,       SLOT(UpdateSave_AllStack()));
    connect(ui->action_Save_Image_Proc,                 SIGNAL(triggered(bool)),                    this,       SLOT(Save_Image_Proc()));
    connect(ui->action_Save_Image_Visualize,            SIGNAL(triggered(bool)),                    this,       SLOT(Save_Image_Vis()));
    connect(ui->action_Save_Plot_Diameter_Histogram,    SIGNAL(triggered(bool)),                    this,       SLOT(Save_Plot_DiaHist()));
    connect(ui->action_Save_Plot_Input_Gray_Values,     SIGNAL(triggered(bool)),                    this,       SLOT(Save_Plot_InputHist()));
    connect(ui->action_Save_Table_Diameter_Statistics,  SIGNAL(triggered(bool)),                    this,       SLOT(Save_Table_DiaStat()));
    connect(ui->action_Save_Table_Euler_Characteristic, SIGNAL(triggered(bool)),                    this,       SLOT(Save_Table_Euler()));
    connect(ui->action_Save_Table_Pixel_Ratios,         SIGNAL(triggered(bool)),                    this,       SLOT(Save_Table_PixelRatio()));
    connect(ui->checkBox_ResAna_DiaHist_Acc,            SIGNAL(clicked(bool)),                      this,       SLOT(Update_Results()));
    connect(ui->checkBox_ResAna_DiaHist_Uni,            SIGNAL(clicked(bool)),                      this,       SLOT(Update_Results()));
    connect(ui->spinBox_ResAna_DiaHist_Classes,         SIGNAL(valueChanged(int)),                  this,       SLOT(Update_Results()));
    connect(ui->comboBox_ResAna_DiaHist_PoolingWeights, SIGNAL(currentIndexChanged(int)),           this,       SLOT(Update_Results()));
    connect(ui->comboBox_ResAna_SingleStack,            SIGNAL(currentIndexChanged(int)),           this,       SLOT(Update_Results()));
    connect(ui->comboBox_ResAna_Type,                   SIGNAL(currentIndexChanged(int)),           this,       SLOT(Update_Results()));
    connect(ui->tabWidget_Results,                      SIGNAL(currentChanged(int)),                this,       SLOT(Update_Results()));


    //on start
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    setWindowTitle("ImageD - DNA Fibre Thickness Measurement");
    this->showMaximized();
    Param_SetToDefault();
    Load_Images();
}

D_MAKRO_DnaFiber::~D_MAKRO_DnaFiber()
{
    delete ui;
}

void D_MAKRO_DnaFiber::closeEvent(QCloseEvent *event)
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

void D_MAKRO_DnaFiber::resizeEvent(QResizeEvent *event)
{
    event->accept();
    Update_Views();
}

void D_MAKRO_DnaFiber::Load_Images()
{
    //get paths of images
    QSL_InputImages = QFileDialog::getOpenFileNames(
                this,
                "Load Images",
                pStore->dir_M_DnaFibre()->path(),
                tr("Images (*.tif *.TIF *.tiff *.TIFF)"));

    //files chosen?
    if(QSL_InputImages.empty())
        return;

    //states change
    state_cur_img_loaded        = false;
    state_cur_img_processed     = false;
    state_cur_img_visualization = false;
    state_cur_res_calced        = false;
    state_stack_processed       = false;
    state_stack_res_calced      = false;
    state_analyse_single        = false;
    state_analyse_stack         = false;

    //default path for next use
    pStore->set_dir_M_DnaFibre(QSL_InputImages.first());

    //File Infos & img names & rois & params
    FIL_InputImages.clear();
    FIL_RoiImages.clear();
    FIL_Parameters.clear();
    QSL_InputImages_Names.clear();
    for(int f = 0; f < QSL_InputImages.size(); f++)
    {
        //names
        FIL_InputImages.append(QFileInfo(QSL_InputImages[f]));
        QSL_InputImages_Names.append(FIL_InputImages[f].baseName());

        //ROIs
        FIL_RoiImages.append(
                    QFileInfo(
                        FIL_InputImages[f].absoluteFilePath().left(
                            FIL_InputImages[f].absoluteFilePath().lastIndexOf("."))
                        + "_mask." + FIL_InputImages[f].suffix()));
        if(!FIL_RoiImages[f].exists())
            if(QMessageBox::question(
                        this,
                        "ROI Missing",
                        "No Roi image is found."
                        "<br>Roi images are expected to be in the same folder as the images to be analyzed."
                        "<br>Expected filename:"
                        "<br><I>" + FIL_RoiImages[f].absoluteFilePath() + "</I>"
                        "<br><br>'Full image = Roi' is assumed. Is that, what you want?"
                        "<br>(If you press no, loading process will be canceled.)",
                        QMessageBox::Yes,
                        QMessageBox::No)
                    != QMessageBox::Yes)
                return;

        //Params
        FIL_Parameters.append(
                    QFileInfo(
                        FIL_InputImages[f].absoluteFilePath().left(
                            FIL_InputImages[f].absoluteFilePath().lastIndexOf("."))
                        + "_param.txt"));
    }

    //resize containers
    Calc_DiaHist_ClassCount();
    vv_hist_diameters_single.resize(QSL_InputImages.size());
    vv_hist_diameters_single_acc.resize(QSL_InputImages.size());
    v_hist_diameters_stack_equal.resize(hist_diameters_class_count, 0);
    v_hist_diameters_stack_equal_acc.resize(hist_diameters_class_count, 0);
    v_hist_diameters_stack_vol.resize(hist_diameters_class_count, 0);
    v_hist_diameters_stack_vol_acc.resize(hist_diameters_class_count, 0);
    for(int i = 0; i < QSL_InputImages.size(); i++)
    {
        vv_hist_diameters_single[i].resize(hist_diameters_class_count, 0);
        vv_hist_diameters_single_acc[i].resize(hist_diameters_class_count, 0);
    }

    //ui
    Populate_CB_Single(ui->comboBox_ImgProc_Img, QSL_InputImages_Names, 0);

    //Update
    Update_ImgProc_Step(c_ST_LOAD);
    Update_View_ImgProc();
}

void D_MAKRO_DnaFiber::Param_SetToDefault()
{
    vParam[PARAM_Spacing_Size_XY] = 2.0;
    vParam[PARAM_Spacing_Size_Z] = 3.0;
    vParam[PARAM_Blur_Size_XY] = 11;
    vParam[PARAM_Blur_Size_Z] = 9;
    vParam[PARAM_Binary_Thresh] = 80;
    vParam[PARAM_Eilenstein_Size_XY] = 3;
    vParam[PARAM_Eilenstein_Size_Z] = 3;
    vParam[PARAM_Skelleton_Thresh] = 23;

    Param_ToUi();
}

bool D_MAKRO_DnaFiber::Param_LoadFromFile()
{
    if(FIL_Parameters[ui->comboBox_ImgProc_Img->currentIndex()].exists())
    {
        ifstream is_param;
        is_param.open(FIL_Parameters[ui->comboBox_ImgProc_Img->currentIndex()].absoluteFilePath().toStdString());
        string st_line;

        while(getline(is_param, st_line))
        {
            QString QS_Line = QString::fromStdString(st_line);
            QStringList QSL_Words = QS_Line.split(" ");
            if(QSL_Words.size() == 2)
                for(int p = 0; p < PARAM_NUMBER_OF; p++)
                    if(QSL_Words[0] == QSL_PARAM[p])
                    {
                        bool ok;
                        double val = QSL_Words[1].toDouble(&ok);
                        if(ok)
                            vParam[p] = val;
                    }
        }

        Param_ToUi();
        return true;
    }
    else
    {
        Param_SetToDefault();
        Param_SaveInFile();
        return false;
    }
}

void D_MAKRO_DnaFiber::Param_SaveInFile()
{
    //open stream
    ofstream os_param;
    os_param.open(FIL_Parameters[ui->comboBox_ImgProc_Img->currentIndex()].absoluteFilePath().toStdString());

    for(int p = 0; p < PARAM_NUMBER_OF; p++)
        os_param << QSL_PARAM[p].toStdString() << " " << vParam[p] << "\n";

    //close
    os_param.close();
}

void D_MAKRO_DnaFiber::Param_FromUi()
{
    vParam[PARAM_Spacing_Size_XY]       = ui->doubleSpinBox_Controls_Spacing_XY->value();
    vParam[PARAM_Spacing_Size_Z]        = ui->doubleSpinBox_Controls_Spacing_Z->value();
    vParam[PARAM_Blur_Size_XY]          = ui->spinBox_Controls_Median_Size_XY->value();
    vParam[PARAM_Blur_Size_Z]           = ui->spinBox_Controls_Median_Size_Z->value();
    vParam[PARAM_Binary_Thresh]         = ui->spinBox_Controls_Binary_Thres->value();
    vParam[PARAM_Eilenstein_Size_XY]    = ui->spinBox_Controls_Eilenstein_XY->value();
    vParam[PARAM_Eilenstein_Size_Z]     = ui->spinBox_Controls_Eilenstein_Z->value();
    vParam[PARAM_Skelleton_Thresh]      = ui->spinBox_Controls_Skelleton_Thres->value();
}

void D_MAKRO_DnaFiber::Param_ToUi()
{
    ui->doubleSpinBox_Controls_Spacing_XY   ->setValue(vParam[PARAM_Spacing_Size_XY]);
    ui->doubleSpinBox_Controls_Spacing_Z    ->setValue(vParam[PARAM_Spacing_Size_Z]);
    ui->spinBox_Controls_Median_Size_XY     ->setValue(vParam[PARAM_Blur_Size_XY]);
    ui->spinBox_Controls_Median_Size_Z      ->setValue(vParam[PARAM_Blur_Size_Z]);
    ui->spinBox_Controls_Binary_Thres       ->setValue(vParam[PARAM_Binary_Thresh]);
    ui->spinBox_Controls_Eilenstein_XY      ->setValue(vParam[PARAM_Eilenstein_Size_XY]);
    ui->spinBox_Controls_Eilenstein_Z       ->setValue(vParam[PARAM_Eilenstein_Size_Z]);
    ui->spinBox_Controls_Skelleton_Thres    ->setValue(vParam[PARAM_Skelleton_Thresh]);
}

void D_MAKRO_DnaFiber::Update_Views()
{
    Update_View_ImgProc();
    Update_View_Results();
}

void D_MAKRO_DnaFiber::Update_View_ImgProc()
{
    D_VisDat_Slice_2D slice = Slice2D_fromUI();
    if(ui->comboBox_ImgProc_Step->currentIndex() == c_ST_ROI_LOAD && ui->comboBox_ImgProc_View_Plane->currentIndex() == c_PL_XY)
        slice = D_VisDat_Slice_2D(-1, -1, 0, 0, 0, 0);

    D_VisDat_Proc::Read_2D_Plane(
                &MA_Proc_Show,
                &(vVD_ProcSteps[ui->comboBox_ImgProc_Step->currentIndex()]),
                slice);

    View_Proc.Update_Image(&MA_Proc_Show);
}

void D_MAKRO_DnaFiber::Update_View_Results()
{
    D_VisDat_Proc::Read_2D_Plane(
                &MA_ResultsVis,
                &VD_ResultsVis,
                Slice2D_fromUI());

    View_Results.Update_Image(&MA_ResultsVis);
}

void D_MAKRO_DnaFiber::Update_Ui()
{
    Update_Views();
    this->repaint();
    qApp->processEvents();
}

void D_MAKRO_DnaFiber::Update_ImgProc(int step_start)
{
    if(!state_cur_img_loaded && step_start != c_ST_LOAD)
    {
        qDebug() << "Update_ImgProc" << "No image loaded -> can't update starting from step other than c_ST_LOAD";
        return;
    }

    //proc steps
    for(int s = step_start; s < c_ST_NUMBER_OF; s++)
        Update_ImgProc_Step(s);

    //calc results and show
    Update_ImgProc_Visualization();
    Calc_Results_All();
    Update_Views();
}

void D_MAKRO_DnaFiber::Update_ImgProc_Step(int step)
{
    this->setEnabled(false);
    qDebug() << "Update Step:" << QSL_ProcSteps[step] << "start";

    switch (step) {

    case c_ST_LOAD:
    {
        state_cur_img_loaded = false;

        //get param preset. If it does not exist: create and use default one
        Param_LoadFromFile();

        D_VisDat_Obj VD_Tmp;
        int ER = D_VisDat_Proc::Create_VD_SinglePaged(
                    &VD_Tmp,
                    FIL_InputImages[ui->comboBox_ImgProc_Img->currentIndex()],
                    c_DIM_Z,
                    c_DIM_X,
                    c_DIM_Y);

        ERR(
                    ER,
                    "Update_ImgProc_Step",
                    "c_ST_LOAD - Create_VD_SinglePaged");

        ER = D_VisDat_Proc::Normalize(
                    &(vVD_ProcSteps[c_ST_LOAD]),
                    &VD_Tmp,
                    CV_MINMAX,
                    CV_8U,
                    0,
                    255);

        ERR(
                    ER,
                    "Update_ImgProc_Step",
                    "c_ST_LOAD - Normalize");

        if(ER != ER_okay)
            return;

        state_cur_img_loaded = true;
        state_cur_img_processed = false;
        SizeAdapt();
     }
        break;

    case c_ST_INVERT:
    {
        ERR(D_VisDat_Proc::Math_1img_Inversion(
                &(vVD_ProcSteps[c_ST_INVERT]),
                &(vVD_ProcSteps[c_ST_LOAD])),
            "Update_ImgProc_Step",
            "c_ST_INVERT");

         state_cur_img_processed = false;
     }
        break;

    case c_ST_BLUR:
    {
        ERR(D_VisDat_Proc::Filter_Median(
                ProcSlicing,
                &(vVD_ProcSteps[c_ST_BLUR]),
                &(vVD_ProcSteps[c_ST_INVERT]),
                ui->spinBox_Controls_Median_Size_XY->value() / 2,
                ui->spinBox_Controls_Median_Size_XY->value() / 2,
                ui->spinBox_Controls_Median_Size_Z->value() / 2),
            "Update_ImgProc_Step",
            "c_ST_BLUR");

         state_cur_img_processed = false;
     }
        break;

    case c_ST_ROI_LOAD:
    {
        int ER;

        //Roi img exists?
        if(FIL_RoiImages[ui->comboBox_ImgProc_Img->currentIndex()].exists())
        {
            //load roi
            ER = D_VisDat_Proc::Create_VD_Single(
                        &(vVD_ProcSteps[c_ST_ROI_LOAD]),
                        FIL_RoiImages[ui->comboBox_ImgProc_Img->currentIndex()],
                        c_DIM_X,
                        c_DIM_Y);

            ERR(
                        ER,
                        "Update_ImgProc_Step",
                        "c_ST_ROI_LOAD");

            if(ER != ER_okay)
                return;
        }
        else
        {
            //create 100%-roi
            vVD_ProcSteps[c_ST_ROI_LOAD] =
                    D_VisDat_Obj(
                        D_VisDat_Dim(
                            vVD_ProcSteps[c_ST_LOAD].Dim().size_X(),
                            vVD_ProcSteps[c_ST_LOAD].Dim().size_Y(),
                            1,
                            1,
                            1,
                            1),
                        vVD_ProcSteps[c_ST_LOAD].type());

            //roi as Mat (255 all px -> full img is roi)
            Mat MA_tmp_roi_all =
                    Mat(
                        vVD_ProcSteps[c_ST_ROI_LOAD].Dim().size_Y(),
                        vVD_ProcSteps[c_ST_ROI_LOAD].Dim().size_X(),
                        vVD_ProcSteps[c_ST_ROI_LOAD].type(),
                        Scalar(255));

            //push MA to VD
            ER = D_VisDat_Proc::Write_2D_Plane(
                        &(vVD_ProcSteps[c_ST_ROI_LOAD]),
                        &MA_tmp_roi_all,
                        D_VisDat_Slice_2D(
                            -1,
                            -1,
                            0,
                            0,
                            0,
                            0));

            ERR(
                        ER,
                        "Update_ImgProc_Step",
                        "c_ST_ROI_LOAD");

            if(ER != ER_okay)
                return;
        }

        state_cur_img_processed = false;
     }
        break;

    case c_ST_ROI_CROP:
    {
        ERR(D_VisDat_Proc::Math_2img_Function_UnequalSize_8bit(
                &(vVD_ProcSteps[c_ST_ROI_CROP]),
                &(vVD_ProcSteps[c_ST_BLUR]),
                &(vVD_ProcSteps[c_ST_ROI_LOAD]),
                D_Math::Function_2D_to_1D_8bit(
                    c_MATH_2D_TO_1D_X_times_Y,
                    1,
                    0,
                    1.0/255.0,  //255->1 for multiplication
                    0,
                    0,
                    0,
                    0,
                    0)),
            "Update_ImgProc_Step",
            "c_ST_ROI_CROP");

         state_cur_img_processed = false;
     }

    case c_ST_BINARY:
    {
        ERR(D_VisDat_Proc::Threshold_Absolute(
                &(vVD_ProcSteps[c_ST_BINARY]),
                &(vVD_ProcSteps[c_ST_ROI_CROP]),
                ui->spinBox_Controls_Binary_Thres->value()),
            "Update_ImgProc_Step",
            "c_ST_BINARY");

         state_cur_img_processed = false;
     }
        break;

    case c_ST_DISTANCE:
    {
        ERR(D_VisDat_Proc::Transformation_Distance(
                ProcSlicing,
                &(vVD_ProcSteps[c_ST_DISTANCE]),
                &(vVD_ProcSteps[c_ST_BINARY]),
                0,
                0,
                ui->doubleSpinBox_Controls_Spacing_XY->value(),
                ui->doubleSpinBox_Controls_Spacing_XY->value(),
                ui->doubleSpinBox_Controls_Spacing_Z->value()),
            "Update_ImgProc_Step",
            "c_ST_DISTANCE");

         state_cur_img_processed = false;
     }
        break;

    case c_ST_EILENSTEIN:
    {
        ERR(D_VisDat_Proc::Filter_Eilenstein_Greater_Sum(
                ProcSlicing,
                &(vVD_ProcSteps[c_ST_EILENSTEIN]),
                &(vVD_ProcSteps[c_ST_DISTANCE]),
                ui->spinBox_Controls_Eilenstein_XY->value(),
                ui->spinBox_Controls_Eilenstein_XY->value(),
                ui->spinBox_Controls_Eilenstein_Z->value()),
            "Update_ImgProc_Step",
            "c_ST_EILENSTEIN");

         state_cur_img_processed = false;
     }
        break;

    case c_ST_SKELLETON:
    {
        ERR(D_VisDat_Proc::Threshold_Absolute(
                &(vVD_ProcSteps[c_ST_SKELLETON]),
                &(vVD_ProcSteps[c_ST_EILENSTEIN]),
                ui->spinBox_Controls_Skelleton_Thres->value()),
            "Update_ImgProc_Step",
            "c_ST_SKELLETON");

         state_cur_img_processed = false;
     }
        break;

    case c_ST_DIAMETERS:
    {
        int ER = D_VisDat_Proc::Math_2img_Function(
                    &(vVD_ProcSteps[c_ST_DIAMETERS]),
                    &(vVD_ProcSteps[c_ST_SKELLETON]),
                    &(vVD_ProcSteps[c_ST_DISTANCE]),
                    D_Math::Function_2D_to_1D(
                        c_MATH_2D_TO_1D_X_times_Y,
                        2, 0, (1.0/255.0), 0, 0, 0, 0, 0));

        ERR(
                    ER,
                    "Update_ImgProc_Step",
                    "c_ST_DIAMETERS");

        if(ER != ER_okay)
            return;

         state_cur_img_processed = true;
     }
        break;

    default:
        break;
    }

    ui->comboBox_ImgProc_Step->setCurrentIndex(step);
    Update_View_ImgProc();
    Update_Ui();
    this->setEnabled(true);

    qDebug() << "Update Step:" << QSL_ProcSteps[step] << "stop";
}

void D_MAKRO_DnaFiber::Update_ImgProc_Visualization()
{
    if(!state_cur_img_processed)
        return;

    //B: Surfaces

    //dialteion
    D_VisDat_Obj VD_dilation_double_tmp;
    ERR(D_VisDat_Proc::Morphology_Dilation(
            ProcSlicing,
            &VD_dilation_double_tmp,
            &(vVD_ProcSteps[c_ST_BINARY]),
            3,
            3,
            3),
        "Update_ImgProc_Visualization",
        "Morphology_Dilation");

    //-> 8bit
    D_VisDat_Obj VD_dilation_uchar_tmp;
    ERR(D_VisDat_Proc::Normalize(
            &VD_dilation_uchar_tmp,
            &VD_dilation_double_tmp,
            NORM_MINMAX,
            CV_8UC1,
            0,
            255),
        "Update_ImgProc_Visualization",
        "Convert_Double");

    //surfaces = morphological gradient
    D_VisDat_Obj VD_double_morphgrad_tmp;
    ERR(D_VisDat_Proc::Math_2img_SubtractionAbsolute(
            &VD_double_morphgrad_tmp,
            &VD_dilation_uchar_tmp,
            &(vVD_ProcSteps[c_ST_BINARY])),
        "Update_ImgProc_Visualization",
        "Math_2img_SubtractionAbsolute");

    //Merge
    bool ch_use[] = {true, true, true, false};
    ERR(D_VisDat_Proc::Channels_Merge(
            &VD_ResultsVis,
            &VD_double_morphgrad_tmp,
            &(vVD_ProcSteps[c_ST_SKELLETON]),
            &(vVD_ProcSteps[c_ST_LOAD]),
            &(vVD_ProcSteps[c_ST_LOAD]),
            3,
            ch_use),
        "Update_ImgProc_Visualization",
        "Channels_Merge");

    //free mem
    VD_dilation_double_tmp.pMA_full()->release();
    VD_dilation_uchar_tmp.pMA_full()->release();
    VD_double_morphgrad_tmp.pMA_full()->release();

    state_cur_img_visualization = true;
}

void D_MAKRO_DnaFiber::UpdateSave_AllSingle()
{
    state_analyse_single = true;

    //chose output dir (only if it is a "real" single analysis)
    if(!state_analyse_stack)
    {
        //ask user
        QString QS_save_single = QFileDialog::getExistingDirectory(
                    this,
                    "Save Analysis Single",
                    pStore->dir_M_DnaFibre()->path());

        //selected?
        if(QS_save_single == 0)
        {
            state_analyse_single = true;
            return;
        }

        //generate new out dir path
        QString QS_save_single_sub = QS_save_single + "/Results_" + ui->comboBox_ImgProc_Img->currentText() + "_0";
        unsigned int count = 0;
        while(QDir(QS_save_single_sub).exists())
        {
            count++;
            QS_save_single_sub = QS_save_single + "/Results_" + ui->comboBox_ImgProc_Img->currentText() + "_" + QString::number(count);
        }
        DIR_SaveSingle.setPath(QS_save_single_sub);
    }

    //current img index
    int img = ui->comboBox_ImgProc_Img->currentIndex();

    //create dir
    QDir().mkdir(DIR_SaveSingle.path());


    //avoid user interaction-----------------------------------------------------------------------------
    this->setEnabled(false);

    //set ui--------------------------------------------------------------------------------------------------
    //this->showMaximized();
    ui->tabWidget_Results->setCurrentIndex(c_RES_STYLE_VIS);
    ui->comboBox_ResAna_SingleStack->setCurrentIndex(c_RES_POOL_SINGLE);
    ui->spinBox_ImgProc_View_X->setValue(ui->spinBox_ImgProc_View_X->maximum() / 2);
    ui->spinBox_ImgProc_View_Y->setValue(ui->spinBox_ImgProc_View_Y->maximum() / 2);
    ui->spinBox_ImgProc_View_Z->setValue(ui->spinBox_ImgProc_View_Z->maximum() / 2);
    ui->comboBox_ImgProc_View_Plane->setCurrentIndex(c_PL_XY);
    ui->comboBox_ImgProc_Step->setCurrentIndex(0);

    //Update proc if needed--------------------------------------------------------------------------------
    if(!state_cur_img_loaded)           Update_ImgProc_Step(c_ST_LOAD);
    if(!state_cur_img_processed)        Update_ImgProc(0);
    if(!state_cur_img_visualization)    Update_ImgProc_Visualization();
    if(!state_cur_res_calced)           Calc_Results_All();



    //Image processing----------------------------------------------------------------------------------
    ui->groupBox_ImgProc->setVisible(true);
    ui->groupBox_Controls->setVisible(false);
    ui->tabWidget_Results->setVisible(false);

    //Img Proc Steps save dir
    QDir DIR_SaveSingle_BV;
    DIR_SaveSingle_BV.setPath(DIR_SaveSingle.path() + "/Image_Processing_Steps");
    QDir().mkdir(DIR_SaveSingle_BV.path());

    //loop steps
    for(int step = 0; step < c_ST_NUMBER_OF; step++)
    {
        ui->comboBox_ImgProc_Step->setCurrentIndex(step);
        for(int plane = 0; plane < c_PL_NUMBER_OF; plane++)
        {
            ui->comboBox_ImgProc_View_Plane->setCurrentIndex(plane);
            Update_View_ImgProc();
            Save_Image_Proc(DIR_SaveSingle_BV.path() + "/" + QSL_XYZ_Planes[plane] +" - " + QSL_ProcSteps[step] + ".png");
        }
    }



    //Visualization-----------------------------------------------------------------------------------------------
    ui->groupBox_ImgProc->setVisible(true);
    ui->groupBox_Controls->setVisible(true);
    ui->tabWidget_Results->setVisible(true);
    ui->tabWidget_Results->setCurrentIndex(c_RES_STYLE_VIS);

    //Visualization for each plane
    for(int plane = 0; plane < c_PL_NUMBER_OF; plane++)
    {
        ui->comboBox_ImgProc_View_Plane->setCurrentIndex(plane);
        Save_Image_Vis(DIR_SaveSingle.path() + "/Visualization_" + QSL_XYZ_Planes[plane] + ".png");
    }

    //Plots & Tables-----------------------------------------------------------------------------------------------
    ui->groupBox_ImgProc->setVisible(false);
    ui->groupBox_Controls->setVisible(false);
    ui->tabWidget_Results->setVisible(true);
    ui->tabWidget_Results->setCurrentIndex(c_RES_STYLE_PLOT);

    //single pool mode
    ui->comboBox_ResAna_SingleStack->setCurrentIndex(c_RES_POOL_SINGLE);

    //diameter hist plot
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_DIAMETER_HIST);
    ui->checkBox_ResAna_DiaHist_Acc->setChecked(false);
    Update_Results();
    Update_Ui();
    Save_Plot_DiaHist(DIR_SaveSingle.path() + "/Diameter_Histogram.png");
    ui->checkBox_ResAna_DiaHist_Acc->setChecked(true);
    Update_Results();
    Update_Ui();
    Save_Plot_DiaHist(DIR_SaveSingle.path() + "/Diameter_Histogram_Acc.png");

    //diameter hist data
    //file
    ofstream OS_HistDia;
    OS_HistDia.open(QString(DIR_SaveSingle.path() + "/Diameter_Histogram.csv").toStdString());
    //stream
    OS_HistDia << "Diameter Histogram" << "\n";
    OS_HistDia << QSL_InputImages_Names[img].toStdString() << "\n";
    OS_HistDia << "\n";
    //headers
    OS_HistDia << "Diameter";
    double val = hist_diameters_min;
    while(val < hist_diameters_max)
    {
        OS_HistDia << "," << val;
        val += hist_diameters_step;
    }
    OS_HistDia << "\n";
    //non accumulated
    OS_HistDia << "Non-Accumulated";
    for(int v = 0; v < vv_hist_diameters_single[img].size(); v++)
        OS_HistDia << "," << vv_hist_diameters_single[img][v];
    OS_HistDia << "\n";
    //accumulated
    OS_HistDia << "Accumulated";
    for(int v = 0; v < vv_hist_diameters_single_acc[img].size(); v++)
        OS_HistDia << "," << vv_hist_diameters_single_acc[img][v];
    OS_HistDia.close();

    //input hist
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_INPUT_HIST);
    Update_Results();
    Update_Ui();
    Save_Plot_InputHist(DIR_SaveSingle.path() + "/InputGrayValue_Histogram.png");

    //save dia stat
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_DIAMETER_STAT);
    Update_Results();
    Update_Ui();
    Save_Table_DiaStat(DIR_SaveSingle.path() + "/Diameter_Stats.csv");

    //save euler
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_EULER);
    Update_Results();
    Update_Ui();
    Save_Table_Euler(DIR_SaveSingle.path() + "/Euler_Number.csv");

    //save pixel ratio
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_PIXEL_RATIO);
    Update_Results();
    Update_Ui();
    Save_Table_PixelRatio(DIR_SaveSingle.path() + "/Pixel_Ratio_Number.csv");

    //Parameters-----------------------------------------------------------------------------------------------
    ui->groupBox_ImgProc->setVisible(true);
    ui->groupBox_Controls->setVisible(true);
    ui->tabWidget_Results->setVisible(true);
    QPixmap px_param = ui->groupBox_Controls->grab();
    px_param.save(DIR_SaveSingle.path() + "/Parameters.png", 0, -1);

    //allow user interaction again-----------------------------------------------------------------------------------
    this->setEnabled(true);

    state_analyse_single = false;
}

void D_MAKRO_DnaFiber::UpdateSave_AllStack()
{
    ui->comboBox_ResAna_SingleStack->setCurrentIndex(c_RES_POOL_SINGLE);
    state_analyse_stack = true;

    //dir---------------------------------------------------------------------------------------------------

    //ask user for save dir
    QString QS_save_single = QFileDialog::getExistingDirectory(
                this,
                "Save Analysis Stack",
                pStore->dir_M_DnaFibre()->path());

    //selected?
    if(QS_save_single == 0)
    {
        state_analyse_stack = false;
        return;
    }

    //generate new out dir path
    QString QS_save_single_sub = QS_save_single + "/Results_Stack_0";
    unsigned int count = 0;
    while(QDir(QS_save_single_sub).exists())
    {
        count++;
        QS_save_single_sub = QS_save_single + "/Results_Stack_" + QString::number(count);
    }

    //create dir
    DIR_SaveStack.setPath(QS_save_single_sub);
    QDir().mkdir(DIR_SaveStack.path());

    //clear stack data--------------------------------------------------------------------------------------------
    v_Data_Stack.clear();
    v_euler_number_stack.clear();
    v_Volume.clear();
    v_hist_input_stack.clear();
    v_hist_input_stack.resize(256, 0);
    count_pixels_stack = 0;
    count_zeros_stack = 0;

    //loop images for single analysis-----------------------------------------------------------------------------
    for(int img = 0; img < QSL_InputImages.size(); img++)
    {
        //make sure that single result is shown to avoid anoying popups
        ui->comboBox_ResAna_SingleStack->setCurrentIndex(c_RES_POOL_SINGLE);

        //set current img & sub dir for single analysis
        ui->comboBox_ImgProc_Img->setCurrentIndex(img);
        DIR_SaveSingle.setPath(DIR_SaveStack.path() + "/Single_Analysis_" + QSL_InputImages_Names[img]);

        //Do single analysis
        UpdateSave_AllSingle();

        //append results to stack
        count_pixels_stack += count_pixels_single;
        count_zeros_stack += count_zeros_single;
        v_euler_number_stack.push_back(euler_number_single);
        v_Volume.push_back(count_pixels_single);
        v_Data_Stack.insert(v_Data_Stack.end(), v_Data_Single.begin(), v_Data_Single.end());

        for(int v = 0; v < v_hist_input_stack.size(); v++)
            v_hist_input_stack[v] += v_hist_input_single[v];
    }

    //calc stack stats/hist---------------------------------------------------------------------------------------------
    Calc_DiaHist_Stack();

    ERR(D_Stat::Calc_Stats(
            &v_Stat_Stack,
            v_Data_Stack,
            true),
        "UpdateSave_AllStack",
        "D_Stat::Calc_Stats (of Stack)");

    state_stack_res_calced = true;
    state_stack_processed = true;

    //save stack stuff--------------------------------------------------------------------------------------------

    //avoid user interaction
    this->setEnabled(false);

    //Analysis-----------------------------------------------------------------------
    ui->groupBox_ImgProc->setVisible(false);
    ui->groupBox_Controls->setVisible(false);
    ui->tabWidget_Results->setVisible(true);

    //stack plots
    ui->comboBox_ResAna_SingleStack->setCurrentIndex(c_RES_POOL_STACK);
    ui->tabWidget_Results->setCurrentIndex(c_RES_STYLE_PLOT);

    //save dia hist (pooled equally)
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_DIAMETER_HIST);
    ui->checkBox_ResAna_DiaHist_Acc->setChecked(false);
    ui->comboBox_ResAna_DiaHist_PoolingWeights->setCurrentIndex(c_POOL_WEIGHT_EQUAL);
    Update_Results();
    Update_Ui();
    Save_Plot_DiaHist(DIR_SaveStack.path() + "/Diameter_Histogram_Stack_WeightEqual.png");
    ui->comboBox_ResAna_DiaHist_PoolingWeights->setCurrentIndex(c_POOL_WEIGHT_VOLUME);
    Update_Results();
    Update_Ui();
    Save_Plot_DiaHist(DIR_SaveStack.path() + "/Diameter_Histogram_Stack_WeightVolume.png");
    ui->checkBox_ResAna_DiaHist_Acc->setChecked(true);
    ui->comboBox_ResAna_DiaHist_PoolingWeights->setCurrentIndex(c_POOL_WEIGHT_EQUAL);
    Update_Results();
    Update_Ui();
    Save_Plot_DiaHist(DIR_SaveStack.path() + "/Diameter_Histogram_Stack_WeightEqual_Acc.png");
    ui->comboBox_ResAna_DiaHist_PoolingWeights->setCurrentIndex(c_POOL_WEIGHT_VOLUME);
    Update_Results();
    Update_Ui();
    Save_Plot_DiaHist(DIR_SaveStack.path() + "/Diameter_Histogram_Stack_WeightVolume_Acc.png");

    //diameter hist data
    //file
    ofstream OS_HistDia;
    OS_HistDia.open(QString(DIR_SaveStack.path() + "/Diameter_Histogram_Stack.csv").toStdString());
    //stream
    OS_HistDia << "Diameter Histogram" << "\n";
    for(int img = 0; img < QSL_InputImages.size(); img++)
        OS_HistDia << QSL_InputImages_Names[img].toStdString() << "\n";
    OS_HistDia << "\n";

    //headers
    OS_HistDia << "Diameter";
    double val = hist_diameters_min;
    while(val < hist_diameters_max)
    {
        OS_HistDia << "," << val;
        val += hist_diameters_step;
    }
    OS_HistDia << "\n";

    //equal, non accumulated
    OS_HistDia << "Weighted equally - not accumulated";
    for(int v = 0; v < v_hist_diameters_stack_equal.size(); v++)
        OS_HistDia << "," << v_hist_diameters_stack_equal[v];
    OS_HistDia << "\n";

    //equal, accumulated
    OS_HistDia << "Weighted equally - accumulated";
    for(int v = 0; v < v_hist_diameters_stack_equal_acc.size(); v++)
        OS_HistDia << "," << v_hist_diameters_stack_equal_acc[v];
    OS_HistDia << "\n";

    //volume, non accumulated
    OS_HistDia << "Weighted by analyzed volume - not accumulated";
    for(int v = 0; v < v_hist_diameters_stack_vol.size(); v++)
        OS_HistDia << "," << v_hist_diameters_stack_vol[v];
    OS_HistDia << "\n";

    //volume, accumulated
    OS_HistDia << "Weighted by analyzed volume - accumulated";
    for(int v = 0; v < v_hist_diameters_stack_vol_acc.size(); v++)
        OS_HistDia << "," << v_hist_diameters_stack_vol_acc[v];
    OS_HistDia << "\n";

    OS_HistDia.close();

    //input hist
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_INPUT_HIST);
    Update_Results();
    Update_Ui();
    Save_Plot_InputHist(DIR_SaveStack.path() + "/InputGrayValue_Histogram_Stack.png");

    //save dia stat
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_DIAMETER_STAT);
    Update_Results();
    Update_Ui();
    Save_Table_DiaStat(DIR_SaveStack.path() + "/Diameter_Stats_Stack.csv");

    //save euler
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_EULER);
    Update_Results();
    Update_Ui();
    Save_Table_Euler(DIR_SaveStack.path() + "/Euler_Number_Stack.csv");

    //save px ratio
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_PIXEL_RATIO);
    Update_Results();
    Update_Ui();
    Save_Table_PixelRatio(DIR_SaveStack.path() + "/Pixel_Ratio_Stack.csv");

    //reset ui (show all)
    ui->groupBox_ImgProc->setVisible(true);
    ui->groupBox_Controls->setVisible(true);
    ui->tabWidget_Results->setVisible(true);

    //allow user interaction again
    this->setEnabled(true);

    state_analyse_stack = false;
}

void D_MAKRO_DnaFiber::Calc_DiaHist_Single()
{
    qDebug() << "Calc_DiaHist_Single" << "start";

    int img = ui->comboBox_ImgProc_Img->currentIndex();

    //resize and init with 0
    vv_hist_diameters_single    [img].resize(hist_diameters_class_count, 0);
    vv_hist_diameters_single_acc[img].resize(hist_diameters_class_count, 0);

    //loop dataset & count values
    for(int v = 0; v < v_Data_Single.size(); v++)
    {
        double val = v_Data_Single[v];
        int pos = static_cast<int>((val - hist_diameters_min) / hist_diameters_step);
        vv_hist_diameters_single[img][pos]++;
    }

    //accumulate
    vv_hist_diameters_single_acc[img] = vv_hist_diameters_single[img];
    for(int v = 1; v < vv_hist_diameters_single_acc[img].size(); v++)
        vv_hist_diameters_single_acc[img][v] += vv_hist_diameters_single_acc[img][v-1];

    //normalize
    double sum = vv_hist_diameters_single_acc[img][vv_hist_diameters_single_acc[img].size() - 1];
    for(int v = 0; v < vv_hist_diameters_single[img].size(); v++)
    {
        vv_hist_diameters_single    [img][v] /= sum;
        vv_hist_diameters_single_acc[img][v] /= sum;
    }

    qDebug() << "Calc_DiaHist_Single" << "end";
}

void D_MAKRO_DnaFiber::Calc_DiaHist_Stack()
{
    //weighted equal
    v_hist_diameters_stack_equal.resize(hist_diameters_class_count, 0.0);
    v_hist_diameters_stack_equal_acc.resize(hist_diameters_class_count, 0.0);
    double weights_sum = 0;
    for(int img = 0; img < vv_hist_diameters_single.size(); img++)
    {
        //weight
        double weight = 1.0;
        weights_sum += weight;

        //data
        for(int val = 0; val < vv_hist_diameters_single[img].size(); val++)
        {
            v_hist_diameters_stack_equal    [val] += weight * vv_hist_diameters_single[img][val];
            v_hist_diameters_stack_equal_acc[val] += weight * vv_hist_diameters_single_acc[img][val];
        }
    }
    //norm to 1
    for(int val = 0; val < v_hist_diameters_stack_equal.size(); val++)
    {
        v_hist_diameters_stack_equal    [val] /= weights_sum;
        v_hist_diameters_stack_equal_acc[val] /= weights_sum;
    }

    //weighted per volume analyzed
    v_hist_diameters_stack_vol.resize(hist_diameters_class_count, 0.0);
    v_hist_diameters_stack_vol_acc.resize(hist_diameters_class_count, 0.0);
    weights_sum = 0;
    for(int img = 0; img < vv_hist_diameters_single.size(); img++)
    {
        //weight
        double weight = v_Volume[img];
        weights_sum += weight;

        //data
        for(int val = 0; val < vv_hist_diameters_single[img].size(); val++)
        {
            v_hist_diameters_stack_vol    [val] += weight * vv_hist_diameters_single    [img][val];
            v_hist_diameters_stack_vol_acc[val] += weight * vv_hist_diameters_single_acc[img][val];
        }
    }
    //norm to 1
    for(int val = 0; val < v_hist_diameters_stack_vol.size(); val++)
    {
        v_hist_diameters_stack_vol    [val] /= weights_sum;
        v_hist_diameters_stack_vol_acc[val] /= weights_sum;
    }
}

void D_MAKRO_DnaFiber::Calc_DiaHist_ClassCount()
{
    hist_diameters_class_count = static_cast<size_t>((hist_diameters_max - hist_diameters_min) / hist_diameters_step);
}

void D_MAKRO_DnaFiber::Calc_Results_All()
{
    if(!state_cur_img_processed)
        return;

    Calc_Results_InputHist();
    Calc_Results_DataVector();
    Calc_DiaHist_Single();
    Calc_Results_EulerNumber();
    Calc_Results_StatVector();

    state_cur_res_calced = true;

    Update_Results();
}

void D_MAKRO_DnaFiber::Calc_Results_InputHist()
{
    if(!state_cur_img_loaded)
        return;

    ERR(D_VisDat_Proc::Calc_Hist_1C_8bit(
                &v_hist_input_single,
                &(vVD_ProcSteps[c_ST_LOAD]),
                false,
                false),
        "Update_Results_InputHist",
        "D_VisDat_Proc::Calc_Hist_1C_8bit");
}

void D_MAKRO_DnaFiber::Calc_Results_DataVector()
{
    if(!state_cur_img_processed)
        return;

    ERR(D_VisDat_Proc::Calc_DataVector_1C(
                &v_Data_Single,
                &(vVD_ProcSteps[c_ST_DIAMETERS]),
                true),
        "Calc_Results_DataVector",
        "D_VisDat_Proc::Calc_DataVector_1C");

    count_pixels_single = vVD_ProcSteps[c_ST_BINARY].pDim()->size_Z() * static_cast<size_t>(countNonZero(vVD_ProcSteps[c_ST_ROI_LOAD].MA_full()));
    count_zeros_single = count_pixels_single -  static_cast<size_t>(countNonZero(vVD_ProcSteps[c_ST_BINARY].MA_full()));
}

void D_MAKRO_DnaFiber::Calc_Results_EulerNumber()
{
    if(!state_cur_img_processed)
        return;

    D_VisDat_Obj VD_tmp_euler;
    ERR(D_VisDat_Proc::Euler_Number(
                ProcSlicing,
                &VD_tmp_euler,
                &euler_number_single,
                &(vVD_ProcSteps[c_ST_BINARY])),
        "Calc_Results_EulerNumber",
        "D_VisDat_Proc::Euler_Number");
}

void D_MAKRO_DnaFiber::Calc_Results_StatVector()
{
    if(!state_cur_img_processed)
        return;

    ERR(D_Stat::Calc_Stats(
            &v_Stat_Single,
            v_Data_Single,
            true),
        "Calc_Results_StatVector",
        "D_Stat::Calc_Stats");
}

void D_MAKRO_DnaFiber::Update_Results()
{
    if(!state_cur_res_calced)
        return;

    if(ui->comboBox_ResAna_SingleStack->currentIndex() == c_RES_POOL_STACK && !state_stack_processed)
    {
        QMessageBox::warning(
                    this,
                    "Error",
                    "Requested thing is only availiable, if stack is analyzed.<br>Go to: <I>Menu > Save > Save Analysis Stack</I><br>");
        ui->comboBox_ResAna_SingleStack->setCurrentIndex(c_RES_POOL_SINGLE);
        return;
    }

    switch (ui->comboBox_ResAna_Type->currentIndex()) {
    case c_RES_TYPE_INPUT_HIST:         Update_Results_InputHist();         break;
    case c_RES_TYPE_DIAMETER_HIST:      Update_Results_DiameterHist();      break;
    case c_RES_TYPE_DIAMETER_STAT:      Update_Results_DiameterStat();      break;
    case c_RES_TYPE_EULER:              Update_Results_Euler();             break;
    case c_RES_TYPE_PIXEL_RATIO:        Update_Results_PixelRatio();        break;
    default:                                                                break;}
}

void D_MAKRO_DnaFiber::Update_Results_Visualization()
{
    Update_View_Results();
}

void D_MAKRO_DnaFiber::Update_Results_InputHist()
{
    if(!state_cur_res_calced)
        return;

    if(ui->comboBox_ResAna_SingleStack->currentIndex() == c_RES_POOL_SINGLE)
    {
        ERR(D_Plot::Plot_Line_XY_Single(
                    pChartView_InputHist,
                    v_hist_input_single,
                    "Gray Value Histogram",
                    ui->comboBox_ImgProc_Img->currentText(),
                    "Gray Value",
                    "Absolute Amount of Pixels"),
            "Update_Results_InputHist",
            "D_Plot::Plot_Line_XY_Single");
    }
    else if(ui->comboBox_ResAna_SingleStack->currentIndex() == c_RES_POOL_STACK)
    {
        if(!state_stack_res_calced)
        {
            QMessageBox::warning(
                        this,
                        "Error",
                        "This plot is only availiable, if stack is analyzed. <br>Go to: <I>Menu > Save > Save Analysis Stack</I><br>");
            ui->comboBox_ResAna_SingleStack->setCurrentIndex(c_RES_POOL_SINGLE);
            return;
        }
        else
        {
            ERR(D_Plot::Plot_Line_XY_Single(
                        pChartView_InputHist,
                        v_hist_input_stack,
                        "Gray Value Histogram",
                        "All Images of Stack",
                        "Gray Value",
                        "Absolute Amount of Pixels"),
                "Update_Results_InputHist",
                "D_Plot::Plot_Line_XY_Single");
        }
    }
}

void D_MAKRO_DnaFiber::Update_Results_DiameterHist()
{
    if(!state_cur_res_calced)
        return;

    //variables needed
    int             img         = ui->comboBox_ImgProc_Img->currentIndex();
    int             pool        = ui->comboBox_ResAna_SingleStack->currentIndex();
    bool            stack       = (pool == c_RES_POOL_STACK);
    bool            acc         = ui->checkBox_ResAna_DiaHist_Acc->isChecked();
    int             weight      = ui->comboBox_ResAna_DiaHist_PoolingWeights->currentIndex();
    bool            vol         = (weight == c_POOL_WEIGHT_VOLUME);
    QString         title       = "Histogram of diameters of fibers";
    QString         series      = ui->comboBox_ImgProc_Img->currentText();
    if(stack)       series      = "Stacked " + QString::number(QSL_InputImages.size()) + " images (equally weighted)";
    if(stack && vol)series      = "Stacked " + QString::number(QSL_InputImages.size()) + " images (weighted by analyzed volume)";
    QString         axis_x      = "Diameter in nm";
    if(acc)         axis_x      = "Diameter in nm (up to)";
    QString         axis_y      = "Realtive amount of pixels counted";

    if(stack && !state_stack_res_calced)
    {
        QMessageBox::warning(
                    this,
                    "Error",
                    "This plot is only availiable, if stack is analyzed. <br>Go to: <I>Menu > Save > Save Analysis Stack</I><br>");
        ui->comboBox_ResAna_SingleStack->setCurrentIndex(c_RES_POOL_SINGLE);
        return;
    }

    //select
    vector<double> v_hist;
    if(!stack && !acc)
        v_hist = vv_hist_diameters_single[img];
    else if(!stack && acc)
        v_hist = vv_hist_diameters_single_acc[img];
    else if(stack && !acc && !vol)
        v_hist = v_hist_diameters_stack_equal;
    else if(stack && acc && !vol)
        v_hist = v_hist_diameters_stack_equal_acc;
    else if(stack && !acc && vol)
        v_hist = v_hist_diameters_stack_vol;
    else if(stack && acc && vol)
        v_hist = v_hist_diameters_stack_vol_acc;
    else
        return;

    //plot
    D_Plot::Plot_Hist_Single_Classes(
                pChartView_DiameterHist,
                &v_hist,
                hist_diameters_min,
                hist_diameters_step,
                title,
                series,
                axis_x,
                axis_y,
                false);

    /*
    //variables needed
    int             pool        = ui->comboBox_ResAna_SingleStack->currentIndex();
    bool            stack       = (pool == c_RES_POOL_STACK);
    vector<double>  v_hist;
    double          min_x;
    double          max_x;
    double          max_y;
    double          step;
    double          classes     = ui->spinBox_ResAna_DiaHist_Classes->value();
    bool            acc         = ui->checkBox_ResAna_DiaHist_Acc->isChecked();
    bool            uni         = ui->checkBox_ResAna_DiaHist_Uni->isChecked();
    QString         title       = "Histogram of diameters of fibers";
    QString         series      = ui->comboBox_ImgProc_Img->currentText();
    if(stack)       series      = "Stacked " + QString::number(QSL_InputImages.size()) + " images";

    QString         axis_x      = "Diameter in nm";
    if(acc)         axis_x      = "Diameter in nm (up to)";
    QString         axis_y      = "Amount of pixels counted";
    if(uni)         axis_y      = "Realtive amount of pixels counted";

    //calc
    if(pool == c_RES_POOL_SINGLE)
    {
        ERR(D_Stat::Calc_Vector2Hist_1(
                &v_hist,
                &v_Data_Single,
                classes,
                &min_x,
                &max_x,
                &max_y,
                &step,
                acc,
                uni),
            "Update_Results_DiameterHist",
            "D_Stat::Calc_Vector2Hist_1");
    }
    else if(pool == c_RES_POOL_STACK)
    {
        if(!state_stack_res_calced)
        {
            QMessageBox::warning(
                        this,
                        "Error",
                        "This plot is only availiable, if stack is analyzed. <br>Go to: <I>Menu > Save > Save Analysis Stack</I><br>");
            ui->comboBox_ResAna_SingleStack->setCurrentIndex(c_RES_POOL_SINGLE);
            return;
        }
        else
        {
            ERR(D_Stat::Calc_Vector2Hist_1(
                    &v_hist,
                    &v_Data_Stack,
                    classes,
                    &min_x,
                    &max_x,
                    &max_y,
                    &step,
                    acc,
                    uni),
                "Update_Results_DiameterHist",
                "D_Stat::Calc_Vector2Hist_1");
        }
    }

    //plot
    ERR(D_Plot::Plot_Hist_Single_Classes(
            pChartView_DiameterHist,
            &v_hist,
            min_x,
            step,
            title,
            series,
            axis_x,
            axis_y,
            false),
        "Update_Results_DiameterHist",
        "D_Plot::Plot_Hist_Single_Classes");

    //range x axis
    pChartView_DiameterHist->chart()->axisX()->setMin(0);
    pChartView_DiameterHist->chart()->axisX()->setMax(120);

    //range y axis
    if(acc && uni)
    {
        pChartView_DiameterHist->chart()->axisY()->setMin(0.0);
        pChartView_DiameterHist->chart()->axisY()->setMax(1.0);
    }
    */
}

void D_MAKRO_DnaFiber::Update_Results_DiameterStat()
{
    if(!state_cur_res_calced)
        return;

    if(ui->comboBox_ResAna_SingleStack->currentIndex() == c_RES_POOL_SINGLE)
    {
        Table_DiameterStat.set_data_d_1D_qs_qsl(
                    v_Stat_Single,
                    "Stats of fibre diameter in " + ui->comboBox_ImgProc_Img->currentText(),
                    QSL_StatList);
    }
    else if(ui->comboBox_ResAna_SingleStack->currentIndex() == c_RES_POOL_STACK)
    {
        if(!state_stack_res_calced)
        {
            QMessageBox::warning(
                        this,
                        "Error",
                        "This table is only availiable, if stack is analyzed. <br>Go to: <I>Menu > Save > Save Analysis Stack</I><br>");
            ui->comboBox_ResAna_SingleStack->setCurrentIndex(c_RES_POOL_SINGLE);
            return;
        }
        else
        {
            Table_DiameterStat.set_data_d_1D_qs_qsl(
                        v_Stat_Stack,
                        "Stats of fibre diameters in images",
                        QSL_StatList);
        }
    }
}

void D_MAKRO_DnaFiber::Update_Results_Euler()
{
    if(!state_cur_res_calced)
        return;

    if(ui->comboBox_ResAna_SingleStack->currentIndex() == c_RES_POOL_SINGLE)
    {
        vector<double> v_euler;
        v_euler.resize(c_RES_EULER_NUMBER_OF, 0);
        v_euler[c_RES_EULER_NUM]            = euler_number_single;
        v_euler[c_RES_EULER_NUM_PER_VX]     = v_euler[c_RES_EULER_NUM] / static_cast<double>(count_pixels_single);
        v_euler[c_RES_EULER_KN4_PER_LN_VX]  = v_euler[c_RES_EULER_NUM_PER_VX] / (1.0 - (euler_average_edges_per_knot / 2.0));
        v_euler[c_RES_EULER_KN4]            = v_euler[c_RES_EULER_KN4_PER_LN_VX] * static_cast<double>(count_pixels_single);

        Table_Euler.set_data_d_1D_qs_qsl(
                    v_euler,
                    ui->comboBox_ImgProc_Img->currentText(),
                    QSL_Euler);
    }
    else if(ui->comboBox_ResAna_SingleStack->currentIndex() == c_RES_POOL_STACK)
    {
        if(!state_stack_res_calced)
        {
            QMessageBox::warning(
                        this,
                        "Error",
                        "This table is only availiable, if stack is analyzed. <br>Go to: <I>Menu > Save > Save Analysis Stack</I><br>");
            ui->comboBox_ResAna_SingleStack->setCurrentIndex(c_RES_POOL_SINGLE);
            return;
        }
        else
        {
            vector<vector<double>> vv_euler;
            vv_euler.resize(QSL_InputImages_Names.size());

            for(int i = 0; i < QSL_InputImages_Names.size(); i++)
            {
                vv_euler[i].resize(c_RES_EULER_NUMBER_OF, 0);
                vv_euler[i][c_RES_EULER_NUM]            = v_euler_number_stack[i];
                vv_euler[i][c_RES_EULER_NUM_PER_VX]     = vv_euler[i][c_RES_EULER_NUM] / v_Volume[i];
                vv_euler[i][c_RES_EULER_KN4_PER_LN_VX]  = vv_euler[i][c_RES_EULER_NUM_PER_VX]  / (1.0 - (euler_average_edges_per_knot / 2));
                vv_euler[i][c_RES_EULER_KN4]            = vv_euler[i][c_RES_EULER_KN4_PER_LN_VX] * v_Volume[i];
            }

            Table_Euler.set_data_d_2D_qsl_qsl(
                        vv_euler,
                        QSL_InputImages_Names,
                        QSL_Euler);
        }
    }
}

void D_MAKRO_DnaFiber::Update_Results_PixelRatio()
{
    if(!state_cur_res_calced)
        return;

    if(ui->comboBox_ResAna_SingleStack->currentIndex() == c_RES_POOL_SINGLE)
    {
        vector<double> v_px_ratio;
        v_px_ratio.resize(c_RES_PX_RATIO_NUMBER_OF, 0);
        v_px_ratio[c_RES_PX_RATIO_ALL]      = static_cast<double>(count_pixels_single);
        v_px_ratio[c_RES_PX_RATIO_BG]       = static_cast<double>(count_zeros_single);
        v_px_ratio[c_RES_PX_RATIO_FG]       = v_px_ratio[c_RES_PX_RATIO_ALL] - v_px_ratio[c_RES_PX_RATIO_BG];
        v_px_ratio[c_RES_PX_RATIO_FG_ALL]   = v_px_ratio[c_RES_PX_RATIO_FG] / v_px_ratio[c_RES_PX_RATIO_ALL];
        v_px_ratio[c_RES_PX_RATIO_FG_BG]    = v_px_ratio[c_RES_PX_RATIO_FG] / v_px_ratio[c_RES_PX_RATIO_BG];
        v_px_ratio[c_RES_PX_RATIO_BG_ALL]   = v_px_ratio[c_RES_PX_RATIO_BG] / v_px_ratio[c_RES_PX_RATIO_ALL];
        v_px_ratio[c_RES_PX_RATIO_BG_FG]    = v_px_ratio[c_RES_PX_RATIO_BG] / v_px_ratio[c_RES_PX_RATIO_FG];

        Table_PixelRatio.set_data_d_1D_qs_qsl(
                    v_px_ratio,
                    ui->comboBox_ImgProc_Img->currentText(),
                    QSL_PixelRatio);
    }
    else if(ui->comboBox_ResAna_SingleStack->currentIndex() == c_RES_POOL_STACK)
    {
        if(!state_stack_res_calced)
        {
            QMessageBox::warning(
                        this,
                        "Error",
                        "This table is only availiable, if stack is analyzed. <br>Go to: <I>Menu > Save > Save Analysis Stack</I><br>");
            ui->comboBox_ResAna_SingleStack->setCurrentIndex(c_RES_POOL_SINGLE);
            return;
        }
        else
        {
            vector<double> v_px_ratio;
            v_px_ratio.resize(c_RES_PX_RATIO_NUMBER_OF, 0);
            v_px_ratio[c_RES_PX_RATIO_ALL]      = static_cast<double>(count_pixels_stack);
            v_px_ratio[c_RES_PX_RATIO_BG]       = static_cast<double>(count_zeros_stack);
            v_px_ratio[c_RES_PX_RATIO_FG]       = v_px_ratio[c_RES_PX_RATIO_ALL] - v_px_ratio[c_RES_PX_RATIO_BG];
            v_px_ratio[c_RES_PX_RATIO_FG_ALL]   = v_px_ratio[c_RES_PX_RATIO_FG] / v_px_ratio[c_RES_PX_RATIO_ALL];
            v_px_ratio[c_RES_PX_RATIO_FG_BG]    = v_px_ratio[c_RES_PX_RATIO_FG] / v_px_ratio[c_RES_PX_RATIO_BG];
            v_px_ratio[c_RES_PX_RATIO_BG_ALL]   = v_px_ratio[c_RES_PX_RATIO_BG] / v_px_ratio[c_RES_PX_RATIO_ALL];
            v_px_ratio[c_RES_PX_RATIO_BG_FG]    = v_px_ratio[c_RES_PX_RATIO_BG] / v_px_ratio[c_RES_PX_RATIO_FG];

            Table_PixelRatio.set_data_d_1D_qs_qsl(
                        v_px_ratio,
                        "Stack of Images",
                        QSL_PixelRatio);
        }
    }
}

void D_MAKRO_DnaFiber::Save_Image_Proc()
{
    QString saved = View_Proc.Save_Image_Dialog(DIR_SaveSingle.path());
    if(saved != 0)
        DIR_SaveDefault.setPath(saved);
}

void D_MAKRO_DnaFiber::Save_Image_Vis()
{
    ui->tabWidget_Results->setCurrentIndex(c_RES_STYLE_VIS);

    QString saved = View_Results.Save_Image_Dialog(DIR_SaveSingle.path());
    if(saved != 0)
        DIR_SaveDefault.setPath(saved);
}

void D_MAKRO_DnaFiber::Save_Plot_DiaHist()
{
    QString path = QFileDialog::getSaveFileName(
                    this,
                    "Save Diameter Histogram",
                    DIR_SaveSingle.path(),
                    "Plot as image (*.png *.bmp *.tif)");
    if(path == 0)
        return;

    Save_Plot_DiaHist(path);
    DIR_SaveDefault.setPath(path);
}

void D_MAKRO_DnaFiber::Save_Plot_InputHist()
{
    QString path = QFileDialog::getSaveFileName(
                    this,
                    "Save Input Gray Value Histogram",
                    DIR_SaveSingle.path(),
                    "Plot as image (*.png *.bmp *.tif)");
    if(path == 0)
        return;

    Save_Plot_InputHist(path);
    DIR_SaveDefault.setPath(path);
}

void D_MAKRO_DnaFiber::Save_Table_DiaStat()
{
    ui->tabWidget_Results->setCurrentIndex(c_RES_STYLE_PLOT);
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_DIAMETER_STAT);
    Update_Results();
    QString saved = Table_DiameterStat.Save_Table_Dialog(DIR_SaveSingle.path());
    if(saved != 0)
        DIR_SaveDefault.setPath(saved);
}

void D_MAKRO_DnaFiber::Save_Table_Euler()
{
    ui->tabWidget_Results->setCurrentIndex(c_RES_STYLE_PLOT);
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_EULER);
    Update_Results();
    QString saved = Table_Euler.Save_Table_Dialog(DIR_SaveSingle.path());
    if(saved != 0)
        DIR_SaveDefault.setPath(saved);
}

void D_MAKRO_DnaFiber::Save_Table_PixelRatio()
{
    ui->tabWidget_Results->setCurrentIndex(c_RES_STYLE_PLOT);
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_PIXEL_RATIO);
    Update_Results();
    QString saved = Table_PixelRatio.Save_Table_Dialog(DIR_SaveSingle.path());
    if(saved != 0)
        DIR_SaveDefault.setPath(saved);
}

void D_MAKRO_DnaFiber::Save_Image_Proc(QString path)
{
    View_Proc.Save_Image(path);
}

void D_MAKRO_DnaFiber::Save_Image_Vis(QString path)
{
    ui->tabWidget_Results->setCurrentIndex(c_RES_STYLE_VIS);
    Update_View_Results();
    View_Results.Save_Image(path);
}

void D_MAKRO_DnaFiber::Save_Plot_DiaHist(QString path)
{
    ui->tabWidget_Results->setCurrentIndex(c_RES_STYLE_PLOT);
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_DIAMETER_HIST);
    Update_Results();
    QPixmap pixmap_save = pChartView_DiameterHist->grab();
    pixmap_save.save(path, 0, -1);
}

void D_MAKRO_DnaFiber::Save_Plot_InputHist(QString path)
{
    ui->tabWidget_Results->setCurrentIndex(c_RES_STYLE_PLOT);
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_INPUT_HIST);
    Update_Results();
    QPixmap pixmap_save = pChartView_InputHist->grab();
    pixmap_save.save(path, 0, -1);
}

void D_MAKRO_DnaFiber::Save_Table_DiaStat(QString path)
{
    ui->tabWidget_Results->setCurrentIndex(c_RES_STYLE_PLOT);
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_DIAMETER_STAT);
    Update_Results();
    Table_DiameterStat.Save_Table(path);
}

void D_MAKRO_DnaFiber::Save_Table_Euler(QString path)
{
    ui->tabWidget_Results->setCurrentIndex(c_RES_STYLE_PLOT);
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_EULER);
    Update_Results();
    Table_Euler.Save_Table(path);
}

void D_MAKRO_DnaFiber::Save_Table_PixelRatio(QString path)
{
    ui->tabWidget_Results->setCurrentIndex(c_RES_STYLE_PLOT);
    ui->comboBox_ResAna_Type->setCurrentIndex(c_RES_TYPE_PIXEL_RATIO);
    Update_Results();
    Table_PixelRatio.Save_Table(path);
}

D_VisDat_Slice_2D D_MAKRO_DnaFiber::Slice2D_fromUI()
{
    D_VisDat_Slice_2D slice;

    switch (ui->comboBox_ImgProc_View_Plane->currentIndex()) {

    case c_PL_XY:
        slice = D_VisDat_Slice_2D(
                    -1,
                    -1,
                    ui->spinBox_ImgProc_View_Z->value(),
                    0,
                    0,
                    0);
        break;

    case c_PL_XZ:
        slice = D_VisDat_Slice_2D(
                    -1,
                    ui->spinBox_ImgProc_View_Y->value(),
                    -1,
                    0,
                    0,
                    0);
        break;

    case c_PL_YZ:
        slice = D_VisDat_Slice_2D(
                    ui->spinBox_ImgProc_View_X->value(),
                    -1,
                    -1,
                    0,
                    0,
                    0);
        break;

    default:
        break;
    }

    return slice;
}

void D_MAKRO_DnaFiber::Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(index_init);
    CB->blockSignals(false);
}

void D_MAKRO_DnaFiber::Populate_CB()
{
    Populate_CB_Single(ui->comboBox_ImgProc_Step,                   QSL_ProcSteps,      c_ST_LOAD);
    Populate_CB_Single(ui->comboBox_ImgProc_View_Plane,             QSL_XYZ_Planes,     c_PL_XY);
    Populate_CB_Single(ui->comboBox_ResAna_SingleStack,             QSL_ResultsPool,    c_RES_POOL_SINGLE);
    Populate_CB_Single(ui->comboBox_ResAna_Type,                    QSL_ResultsTypes,   c_RES_TYPE_INPUT_HIST);
    Populate_CB_Single(ui->comboBox_ResAna_DiaHist_PoolingWeights,  QSL_PoolingWeights, c_POOL_WEIGHT_EQUAL);
}

void D_MAKRO_DnaFiber::Init_Images()
{
    vVD_ProcSteps.clear();
    vVD_ProcSteps.resize(
                c_ST_NUMBER_OF,
                D_VisDat_Obj(
                    D_VisDat_Dim(
                        10,
                        10,
                        10,
                        1,
                        1,
                        1),
                    CV_8UC1));

    MA_Proc_Show    = Mat::zeros(3, 3, CV_8UC1);
    MA_ResultsVis   = Mat::zeros(3, 3, CV_8UC1);
}

void D_MAKRO_DnaFiber::BlockSignals_ImgProc(bool block)
{
    ui->doubleSpinBox_Controls_Spacing_XY->blockSignals(block);
    ui->doubleSpinBox_Controls_Spacing_XY->blockSignals(block);
    ui->spinBox_Controls_Median_Size_XY->blockSignals(block);
    ui->spinBox_Controls_Median_Size_Z->blockSignals(block);
    ui->spinBox_Controls_Binary_Thres->blockSignals(block);
    ui->spinBox_Controls_Eilenstein_XY->blockSignals(block);
    ui->spinBox_Controls_Eilenstein_Z->blockSignals(block);
    ui->spinBox_Controls_Skelleton_Thres->blockSignals(block);
}

void D_MAKRO_DnaFiber::BlockSignals_Viewer(bool block)
{
    ui->comboBox_ImgProc_Img->blockSignals(block);
    ui->comboBox_ImgProc_Step->blockSignals(block);
    ui->comboBox_ImgProc_View_Plane->blockSignals(block);
    ui->spinBox_ImgProc_View_X->blockSignals(block);
    ui->spinBox_ImgProc_View_Y->blockSignals(block);
    ui->spinBox_ImgProc_View_Z->blockSignals(block);
}

void D_MAKRO_DnaFiber::SpacingAdapt_XY_to_Z()
{
    BlockSignals_ImgProc(true);
    ui->spinBox_Controls_Median_Size_Z->setValue(2 * (static_cast<int>((static_cast<double>(ui->spinBox_Controls_Median_Size_XY->value()) * (1 / Spacing_XY_to_Z)) / 2.0)) + 1);
    BlockSignals_ImgProc(false);
}

void D_MAKRO_DnaFiber::SpacingAdapt_Z_to_XY()
{
    BlockSignals_ImgProc(true);
    ui->spinBox_Controls_Median_Size_XY->setValue(2 * (static_cast<int>((static_cast<double>(ui->spinBox_Controls_Median_Size_Z->value()) * (1 / Spacing_Z_to_XY)) / 2.0)) + 1);
    BlockSignals_ImgProc(false);
}

void D_MAKRO_DnaFiber::SpacingAdapt_Viewer()
{
    BlockSignals_Viewer(true);
    ui->spinBox_ImgProc_View_X->setSuffix("px (" + QString::number(ui->spinBox_ImgProc_View_X->value() * Spacing_XY_nm, 'g', 3) + "nm)");
    ui->spinBox_ImgProc_View_Y->setSuffix("px (" + QString::number(ui->spinBox_ImgProc_View_Y->value() * Spacing_XY_nm, 'g', 3) + "nm)");
    ui->spinBox_ImgProc_View_Z->setSuffix("px (" + QString::number(ui->spinBox_ImgProc_View_Z->value() * Spacing_Z_nm, 'g', 3) + "nm)");
    BlockSignals_Viewer(false);
}

void D_MAKRO_DnaFiber::Skelleton_ThresOfVol_Adapt()
{
    int vol     = ui->spinBox_Controls_Eilenstein_XY->value() * ui->spinBox_Controls_Eilenstein_XY->value() * ui->spinBox_Controls_Eilenstein_Z->value();
    int thres   = ui->spinBox_Controls_Skelleton_Thres->value();
    double rel  = static_cast<double>(thres) / static_cast<double>(vol);
    double prz  = rel * 100.0;

    BlockSignals_ImgProc(true);
    ui->spinBox_Controls_Skelleton_Thres->setMaximum(vol);
    ui->label_Controls_Skelleton_ThreshOfVol->setText("/ " + QString::number(vol) + " vx = " + QString::number(prz, 'g', 3) + "%");
    BlockSignals_ImgProc(false);
}

void D_MAKRO_DnaFiber::SizeAdapt()
{
    BlockSignals_Viewer(true);
    ui->spinBox_ImgProc_View_X->setMaximum(vVD_ProcSteps[c_ST_LOAD].Dim().size_X() - 1);
    ui->spinBox_ImgProc_View_Y->setMaximum(vVD_ProcSteps[c_ST_LOAD].Dim().size_Y() - 1);
    ui->spinBox_ImgProc_View_Z->setMaximum(vVD_ProcSteps[c_ST_LOAD].Dim().size_Z() - 1);
    BlockSignals_Viewer(false);
}

void D_MAKRO_DnaFiber::on_doubleSpinBox_Controls_Spacing_XY_valueChanged(double arg1)
{
    state_cur_img_processed     = false;
    state_cur_img_visualization = false;
    state_cur_res_calced        = false;
    state_stack_processed       = false;
    state_stack_res_calced      = false;

    Spacing_XY_nm   = arg1;
    Spacing_XY_to_Z = Spacing_Z_nm / Spacing_XY_nm;
    Spacing_Z_to_XY = Spacing_XY_nm / Spacing_Z_nm;
    SpacingAdapt_XY_to_Z();
    SpacingAdapt_Viewer();

    Param_FromUi();
    Param_SaveInFile();
}

void D_MAKRO_DnaFiber::on_doubleSpinBox_Controls_Spacing_Z_valueChanged(double arg1)
{
    state_cur_img_processed     = false;
    state_cur_img_visualization = false;
    state_cur_res_calced        = false;
    state_stack_processed       = false;
    state_stack_res_calced      = false;

    Spacing_Z_nm   = arg1;
    Spacing_XY_to_Z = Spacing_Z_nm / Spacing_XY_nm;
    Spacing_Z_to_XY = Spacing_XY_nm / Spacing_Z_nm;
    SpacingAdapt_Z_to_XY();
    SpacingAdapt_Viewer();

    Param_FromUi();
    Param_SaveInFile();
}

void D_MAKRO_DnaFiber::on_spinBox_Controls_Median_Size_XY_valueChanged(int arg1)
{
    state_cur_img_processed     = false;
    state_cur_img_visualization = false;
    state_cur_res_calced        = false;
    state_stack_processed       = false;
    state_stack_res_calced      = false;

    arg1;
    SpacingAdapt_XY_to_Z();

    Param_FromUi();
    Param_SaveInFile();
}

void D_MAKRO_DnaFiber::on_spinBox_Controls_Median_Size_Z_valueChanged(int arg1)
{
    state_cur_img_processed     = false;
    state_cur_img_visualization = false;
    state_cur_res_calced        = false;
    state_stack_processed       = false;
    state_stack_res_calced      = false;

    arg1;
    SpacingAdapt_Z_to_XY();

    Param_FromUi();
    Param_SaveInFile();
}

void D_MAKRO_DnaFiber::on_spinBox_Controls_Binary_Thres_valueChanged(int arg1)
{
    state_cur_img_processed     = false;
    state_cur_img_visualization = false;
    state_cur_res_calced        = false;
    state_stack_processed       = false;
    state_stack_res_calced      = false;

    arg1;

    Param_FromUi();
    Param_SaveInFile();
}

void D_MAKRO_DnaFiber::on_spinBox_Controls_Eilenstein_XY_valueChanged(int arg1)
{
    state_cur_img_processed     = false;
    state_cur_img_visualization = false;
    state_cur_res_calced        = false;
    state_stack_processed       = false;
    state_stack_res_calced      = false;

    arg1;
    Skelleton_ThresOfVol_Adapt();

    Param_FromUi();
    Param_SaveInFile();
}

void D_MAKRO_DnaFiber::on_spinBox_Controls_Eilenstein_Z_valueChanged(int arg1)
{
    state_cur_img_processed     = false;
    state_cur_img_visualization = false;
    state_cur_res_calced        = false;
    state_stack_processed       = false;
    state_stack_res_calced      = false;

    arg1;
    Skelleton_ThresOfVol_Adapt();

    Param_FromUi();
    Param_SaveInFile();
}

void D_MAKRO_DnaFiber::on_spinBox_Controls_Skelleton_Thres_valueChanged(int arg1)
{
    state_cur_img_processed     = false;
    state_cur_img_visualization = false;
    state_cur_res_calced        = false;
    state_stack_processed       = false;
    state_stack_res_calced      = false;

    arg1;
    Skelleton_ThresOfVol_Adapt();

    Param_FromUi();
    Param_SaveInFile();
}

void D_MAKRO_DnaFiber::on_comboBox_ImgProc_View_Plane_currentIndexChanged(int index)
{
    switch (index) {

    case c_PL_XY:
        ViewPlane = c_PLANE_XY;
        ui->spinBox_ImgProc_View_X->setEnabled(false);
        ui->spinBox_ImgProc_View_Y->setEnabled(false);
        ui->spinBox_ImgProc_View_Z->setEnabled(true);
        break;

    case c_PL_XZ:
        ViewPlane = c_PLANE_XZ;
        ui->spinBox_ImgProc_View_X->setEnabled(false);
        ui->spinBox_ImgProc_View_Y->setEnabled(true);
        ui->spinBox_ImgProc_View_Z->setEnabled(false);
        break;

    case c_PL_YZ:
        ViewPlane = c_PLANE_YZ;
        ui->spinBox_ImgProc_View_X->setEnabled(true);
        ui->spinBox_ImgProc_View_Y->setEnabled(false);
        ui->spinBox_ImgProc_View_Z->setEnabled(false);
        break;

    default:
        break;
    }

    Update_Views();
}

void D_MAKRO_DnaFiber::on_spinBox_ImgProc_View_X_valueChanged(int arg1)
{
    arg1;
    SpacingAdapt_Viewer();
    Update_Views();
}

void D_MAKRO_DnaFiber::on_spinBox_ImgProc_View_Y_valueChanged(int arg1)
{
    arg1;
    SpacingAdapt_Viewer();
    Update_Views();
}

void D_MAKRO_DnaFiber::on_spinBox_ImgProc_View_Z_valueChanged(int arg1)
{
    arg1;
    SpacingAdapt_Viewer();
    Update_Views();
}

void D_MAKRO_DnaFiber::on_comboBox_ImgProc_Img_currentIndexChanged(int index)
{
    state_cur_img_processed     = false;
    state_cur_img_visualization = false;
    state_cur_res_calced        = false;
    state_stack_processed       = false;
    state_stack_res_calced      = false;

    index;
    Update_ImgProc_Step(c_ST_LOAD);
    Update_View_ImgProc();
}

void D_MAKRO_DnaFiber::on_comboBox_ImgProc_Step_currentIndexChanged(int index)
{
    index;
    Update_View_ImgProc();
}

void D_MAKRO_DnaFiber::ERR(int err, QString func, QString detail)
{
    ER.ERR(
                err,
                "D_MAKRO_DnaFibers",
                func,
                detail);
}

void D_MAKRO_DnaFiber::on_action_Update_Image_Processing_triggered()
{
    Update_ImgProc(0);
}

void D_MAKRO_DnaFiber::on_action_Update_Results_triggered()
{
    Update_Results();
}

void D_MAKRO_DnaFiber::on_pushButton_Controls_SaveParam_clicked()
{
    Param_FromUi();
    Param_SaveInFile();
}

void D_MAKRO_DnaFiber::on_comboBox_ResAna_SingleStack_currentIndexChanged(int index)
{
    ui->comboBox_ResAna_DiaHist_PoolingWeights->setEnabled(index == c_RES_POOL_STACK);
}
