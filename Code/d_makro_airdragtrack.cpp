/************************************************
 *   added:     05.06.2020                      *
 *   author:    David Eilenstein                *
 *   contact:   David.Eilenstein@stud.h-da.de   *
 *   project:   ImageD                          *
 *   facility:  Hochschule Darmstadt, Ger       *
 ************************************************/

#include "d_makro_airdragtrack.h"
#include "ui_d_makro_airdragtrack.h"

D_MAKRO_AirDragTrack::D_MAKRO_AirDragTrack(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_AirDragTrack)
{
    ui->setupUi(this);

    //Storeage
    pStore = pStorage;

    //Viewer
    Viewer_Proc_Crop.set_GV(ui->graphicsView_Proc_Crop);
    Viewer_Proc_Gray.set_GV(ui->graphicsView_Proc_Gray);
    Viewer_Proc_Blur.set_GV(ui->graphicsView_Proc_Blur);
    Viewer_Proc_Thresh.set_GV(ui->graphicsView_Proc_Thres);
    Viewer_Proc_ExBorder.set_GV(ui->graphicsView_Proc_ExBorder);

    //plot
    vPLot_Grids_S.reserve(S_Count);
    vPlot_ChartViews_S.reserve(S_Count);
    vPLot_Grids_S[0] = ui->gridLayout_S0;
    vPLot_Grids_S[1] = ui->gridLayout_S1;
    vPLot_Grids_S[2] = ui->gridLayout_S2;
    vPLot_Grids_S[3] = ui->gridLayout_S3;
    vPLot_Grids_S[4] = ui->gridLayout_S4;
    for(size_t s = 0; s < S_Count; s++)
    {
        delete vPLot_Grids_S[s]->takeAt(0);
        vPlot_ChartViews_S[s] = new QChartView();
        vPLot_Grids_S[s]->addWidget(vPlot_ChartViews_S[s]);
        vPlot_ChartViews_S[s]->setRenderHint(QPainter::Antialiasing);
        vPlot_ChartViews_S[s]->setRubberBand(QChartView::RectangleRubberBand);
        vPlot_ChartViews_S[s]->setInteractive(true);
    }
    Plot_Results = new QChartView();
    ui->gridLayout_ResultsAll->addWidget(Plot_Results);
    Plot_Results->setRenderHint(QPainter::Antialiasing);
    Plot_Results->setRubberBand(QChartView::RectangleRubberBand);
    Plot_Results->setInteractive(true);

    //Images
    vMA_ProcSteps.resize(STEP_NUMBER_OF);
    for(size_t s = 0; s < STEP_NUMBER_OF; s++)
        vMA_ProcSteps[s] = pStore->get_Adress(0)->clone();

    //Populate
    Populate_CB_Start();

    //Connects
    //data
    connect(ui->action_Data_Add,                                    SIGNAL(triggered()),                        this,                   SLOT(Data_Add()));
    connect(ui->action_Data_Clear,                                  SIGNAL(triggered()),                        this,                   SLOT(Data_Clear()));
    connect(ui->comboBox_DataInput,                                 SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Data_SelectVideo()));
    //proc frame
    connect(ui->spinBox_BlurFrames,                                 SIGNAL(valueChanged(int)),                  this,                   SLOT(CalcAll()));
    connect(ui->spinBox_FramesInARow,                               SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_ImgProc_All()));
    connect(ui->spinBox_AreaMax,                                    SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_ImgProc_All()));
    connect(ui->spinBox_AreaMin,                                    SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_ImgProc_All()));
    connect(ui->spinBox_BlurSize,                                   SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_ImgProc_All()));
    connect(ui->spinBox_CropStart,                                  SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_ImgProc_All()));
    connect(ui->spinBox_CropEnd,                                    SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_ImgProc_All()));
    connect(ui->spinBox_CropLeft,                                   SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_ImgProc_All()));
    connect(ui->spinBox_CropHeight,                                 SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_ImgProc_All()));
    connect(ui->spinBox_CropTop,                                    SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_ImgProc_All()));
    connect(ui->spinBox_CropWidth,                                  SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_ImgProc_All()));
    connect(ui->doubleSpinBox_Thresh,                               SIGNAL(valueChanged(double)),               this,                   SLOT(Update_ImgProc_All()));
    connect(ui->doubleSpinBox_BlurSigma,                            SIGNAL(valueChanged(double)),               this,                   SLOT(Update_ImgProc_All()));
    connect(ui->comboBox_Color2Mono,                                SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_ImgProc_All()));
    //results all
    connect(ui->comboBox_Results,                                   SIGNAL(currentIndexChanged(int)),           this,                   SLOT(PlotAllVideos()));

    //on start
    this->showMaximized();
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    setWindowTitle("ImageD - Air Drag Detector");

    //Load stuff on startup
    Data_Add();
}

D_MAKRO_AirDragTrack::~D_MAKRO_AirDragTrack()
{
    delete ui;
}

void D_MAKRO_AirDragTrack::closeEvent(QCloseEvent *event)
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

void D_MAKRO_AirDragTrack::resizeEvent(QResizeEvent *event)
{
    event->accept();
    Update_Views();
}

void D_MAKRO_AirDragTrack::Data_Add()
{
    //get filepaths
    QStringList QSl_Paths = QFileDialog::getOpenFileNames(
                this,
                "Load Videos",
                pStore->dir_M_CiliaSphereTracker()->path(),
                "Image Files (*.avi *.mp4 *.mpg *.mkv *flv *.mpeg *.3gp)");
    if(QSl_Paths.empty())
        return;

    //set default dir
    pStore->set_dir_M_CiliaSphereTracker(QSl_Paths.first());

    //number of loaded videos
    int vid_count_old = FIL_Videos.size();

    //fill listst for easy access
    for(int f = 0; f < QSl_Paths.size(); f++)
    {
        //basics
        QString QS_Path = QSl_Paths[f];
        QFileInfo FI_Img = QFileInfo(QS_Path);
        QString QS_Name = FI_Img.baseName();
        QString QS_Suffix = FI_Img.suffix();

        //lists
        QSL_Videos_Paths.append(QS_Path);
        QSL_Videos_Names.append(FI_Img.baseName());
        QSL_Videos_Suffix.append(FI_Img.suffix());
        FIL_Videos.append(FI_Img);

        //data containers
        vector<Point2f> v_P2f;
        vv_CentersVF.push_back(v_P2f);
        vector<vector<double>> vv_d;
        vvv_PositionsVSF.push_back(vv_d);
    }

    //video names to ui
    int index_old_max = vid_count_old - 1;
    if(index_old_max < 0)
        index_old_max = 0;
    Populate_CB_Single(ui->comboBox_DataInput, QSL_Videos_Names, index_old_max);
/*
    //update ui accesibility
    ui->groupBox_Res->setEnabled(true);
    ui->groupBox_Proc->setEnabled(true);
    ui->groupBox_Param->setEnabled(true);
    ui->pushButton_Data_Clear->setEnabled(true);
    ui->comboBox_Data_Videos->setEnabled(true);
*/
    //update states
    state_video_analysed = false;

    Data_SelectVideo();
    Update_ImgProc_All();
}

void D_MAKRO_AirDragTrack::Data_Clear()
{
    //clear listst
    FIL_Videos.clear();
    QSL_Videos_Names.clear();
    QSL_Videos_Paths.clear();
    QSL_Videos_Suffix.clear();

    vv_CentersVF.clear();
    vvv_PositionsVSF.clear();

    //update ui accesibility
    /*
    ui->groupBox_Res->setEnabled(false);
    ui->groupBox_Proc->setEnabled(false);
    ui->groupBox_Param->setEnabled(false);
    ui->pushButton_Data_Clear->setEnabled(false);
    ui->comboBox_Data_Videos->setEnabled(false);
    */

    //update states
    state_video_valid = false;
    state_video_analysed = false;
    state_frame_img_proc_ready = false;
}

void D_MAKRO_AirDragTrack::Data_SelectVideo()
{
    state_video_analysed = false;

    int vid = ui->comboBox_DataInput->currentIndex();

    int ER = VS_Video.set_VideoPath(FIL_Videos[ui->comboBox_DataInput->currentIndex()]);

    ERR(
            ER,
            "Data_SelectVideo",
            "VS_InputVideo.set_VideoPath(...)");

    if(ER != ER_okay)
        return;

    //set contorls
    ui->horizontalSlider_T_Frame->setMaximum(VS_Video.get_FrameCount() - 3);
    ui->horizontalSlider_T_Frame->setTickInterval(VS_Video.get_FrameRateFps());
    ui->horizontalSlider_T_Frame->setValue(0);
    ui->spinBox_T_Frame->setMaximum(VS_Video.get_FrameCount() - 3);
    ui->spinBox_T_Frame->setValue(0);
    ui->doubleSpinBox_T_Sec->setMaximum(VS_Video.get_DurationSec());
    ui->doubleSpinBox_T_Sec->setValue(0);

    ui->spinBox_CropStart->setMaximum(VS_Video.get_FrameCount() - 4);
    ui->spinBox_CropEnd->setMaximum(VS_Video.get_FrameCount() - 3);
    ui->spinBox_CropEnd->setValue(VS_Video.get_FrameCount() - 3);

    ui->spinBox_CropLeft->setMaximum(VS_Video.get_Width() - 2);
    ui->spinBox_CropWidth->setMaximum(VS_Video.get_Width());
    ui->spinBox_CropTop->setMaximum(VS_Video.get_Height() - 2);
    ui->spinBox_CropHeight->setMaximum(VS_Video.get_Height());

    ui->spinBox_CropEnd->setMaximum(VS_Video.get_FrameCount() - 3);
    ui->spinBox_CropEnd->setValue(VS_Video.get_FrameCount() - 3);

    state_video_valid = true;
    state_frame_img_proc_ready = false;

    //show previous calcs
    if(!vvv_PositionsVSF[vid].empty())
    {
        PlotAll();
    }
    else
    {
        qDebug() << QSL_Videos_Names[vid] << " is not analysed yet -> empty plots are shown";
        for(size_t i = 0; i < S_Count; i++)
        {
            D_Plot::Plot_Empty(
                        vPlot_ChartViews_S[i],
                        "This calculation is not done yet ;-)");
        }
    }
}

void D_MAKRO_AirDragTrack::Update_Ui()
{
    bool en_in = this->isEnabled();
    if(en_in)
        this->setEnabled(false);

    this->repaint();
    qApp->processEvents();

    if(en_in)
        this->setEnabled(true);
}

void D_MAKRO_AirDragTrack::Update_Views()
{
    Viewer_Proc_Crop.Update_View();
    Viewer_Proc_Gray.Update_View();
    Viewer_Proc_Blur.Update_View();
    Viewer_Proc_Thresh.Update_View();
    Viewer_Proc_ExBorder.Update_View();
}

void D_MAKRO_AirDragTrack::Update_Images()
{
    Update_Image_Proc();
}

void D_MAKRO_AirDragTrack::Update_Image_Proc()
{
    Viewer_Proc_Crop.Update_Image(&(vMA_ProcSteps[STEP_CROP]));
    Viewer_Proc_Gray.Update_Image(&(vMA_ProcSteps[STEP_GRAY]));
    Viewer_Proc_Blur.Update_Image(&(vMA_ProcSteps[STEP_BLUR]));
    Viewer_Proc_Thresh.Update_Image(&(vMA_ProcSteps[STEP_BINARY]));
    Viewer_Proc_ExBorder.Update_Image(&(vMA_ProcSteps[STEP_EXCLUDE_BORDER]));
}

void D_MAKRO_AirDragTrack::Update_ImgProc_All()
{
    if(!state_video_valid)
        return;

    Update_ImgProc(0);
}

void D_MAKRO_AirDragTrack::Update_ImgProc(int step_start)
{
    if(!state_video_valid)
        return;

    for(int s = step_start; s < STEP_NUMBER_OF; s++)
        Update_ImgProc_Step(s);

    Update_Images();
}

void D_MAKRO_AirDragTrack::Update_ImgProc_Step(int step)
{
    if(!state_video_valid)
        return;


    switch (step) {

    case STEP_LOAD:
    {
        ERR(VS_Video.get_FramePos(
                &(vMA_ProcSteps[STEP_LOAD]),
                ui->horizontalSlider_T_Frame->value()),
            "Update_ImgProc_Step",
            "STEP_LOAD ");
    }
        break;

    case STEP_CROP:
    {
        ERR(D_Img_Proc::Crop_Rect_Abs(
                &(vMA_ProcSteps[STEP_CROP]),
                &(vMA_ProcSteps[STEP_LOAD]),
                ui->spinBox_CropLeft->value(),
                ui->spinBox_CropTop->value(),
                ui->spinBox_CropWidth->value(),
                ui->spinBox_CropHeight->value()),
            "Update_ImgProc_Step",
            "STEP_CROP");
    }
        break;

    case STEP_GRAY:
    {
        ERR(D_Img_Proc::Convert_Color2Mono(
                &(vMA_ProcSteps[STEP_GRAY]),
                &(vMA_ProcSteps[STEP_CROP]),
                ui->comboBox_Color2Mono->currentIndex()),
            "Update_ImgProc_Step",
            "STEP_GRAY");
    }
        break;

    case STEP_BLUR:
    {
        ERR(D_Img_Proc::Filter_Gauss(
                &(vMA_ProcSteps[STEP_BLUR]),
                &(vMA_ProcSteps[STEP_GRAY]),
                ui->spinBox_BlurSize->value(),
                ui->spinBox_BlurSize->value(),
                BORDER_DEFAULT,
                ui->doubleSpinBox_BlurSigma->value(),
                ui->doubleSpinBox_BlurSigma->value()),
            "Update_ImgProc_Step",
            "STEP_BLUR");
    }
        break;

    case STEP_BINARY:
    {
        ERR(D_Img_Proc::Threshold_Absolute_1C(
                &(vMA_ProcSteps[STEP_BINARY]),
                &(vMA_ProcSteps[STEP_BLUR]),
                ui->doubleSpinBox_Thresh->value()),
            "Update_ImgProc_Step",
            "STEP_BINARY");
    }
        break;

    case STEP_EXCLUDE_BORDER:
    {
        ERR(D_Img_Proc::Exclude_BorderConnected(
                &(vMA_ProcSteps[STEP_EXCLUDE_BORDER]),
                &(vMA_ProcSteps[STEP_BINARY])),
            "Update_ImgProc_Step",
            "STEP_EXCLUDE_BORDER");

        state_frame_img_proc_ready = true;
    }
        break;

    default:
        break;
    }

}

void D_MAKRO_AirDragTrack::Update_ImgProc_FullVideo()
{
    if(F_start > F_end)
        return;

    int vid = ui->comboBox_DataInput->currentIndex();
    qDebug() << QSL_Videos_Names[vid] << "Update_ImgProc_FullVideo" << "Start";

    vv_CentersVF[vid].clear();
    ui->horizontalSlider_T_Frame->setValue(F_start + 1);

    int area_thres_low = ui->spinBox_AreaMin->value();
    int area_thres_high = ui->spinBox_AreaMax->value();

    //counting and state in tracking
    int frames_in_a_row_needed = ui->spinBox_FramesInARow->value();
    bool tracking_started = false;
    int frames_in_a_row_obj = 0;
    int frames_in_a_row_no_obj = 0;

    //loop frames
    for(int f = F_start; f < F_end; f++)
    {
        ui->horizontalSlider_T_Frame->setValue(f);
        Update_Ui();

        //get components
        D_Component_List Comps(&(vMA_ProcSteps[STEP_EXCLUDE_BORDER]));

        //find biggest
        vector<double> v_areas = Comps.get_FeatureVector(c_FEAT_AREA);
        if(!v_areas.empty())
        {
            double area_biggest = 0;
            size_t index_biggest = 0;
            for(size_t c = 0; c < v_areas.size(); c++)
                if(v_areas[c] > area_biggest)
                {
                    area_biggest = v_areas[c];
                    index_biggest = c;
                }

            //area in range?
            if(area_biggest < area_thres_high && area_biggest > area_thres_low)
            {
                frames_in_a_row_obj++;
                if(frames_in_a_row_obj > 2)
                {
                    tracking_started = true;
                    frames_in_a_row_no_obj = 0;
                }

                //get centroid of biggest
                vv_CentersVF[vid].push_back(Comps.get_Centroid(index_biggest));
            }
            else
            {
                frames_in_a_row_no_obj++;
                if(frames_in_a_row_no_obj > 2)
                    frames_in_a_row_obj = 0;
            }
        }
        else
        {
            frames_in_a_row_no_obj++;
            if(frames_in_a_row_no_obj > 2)
                frames_in_a_row_obj = 0;
        }

        qDebug() << "obj" << frames_in_a_row_obj << "no obj" << frames_in_a_row_no_obj;

        if(tracking_started && (frames_in_a_row_no_obj > frames_in_a_row_needed))
        {
            f = F_end;
            qDebug() << "QUIT ANALYSIS";
        }
    }

    qDebug() << QSL_Videos_Names[vid] << "Update_ImgProc_FullVideo" << "End";

    CalcAll();
}

void D_MAKRO_AirDragTrack::CalcAll()
{
    int vid = ui->comboBox_DataInput->currentIndex();
    qDebug() << QSL_Videos_Names[vid] << "CalcAll" << "Start";

    int blur_frames = ui->spinBox_BlurFrames->value();
    int blur_frames_offset = blur_frames / 2;

    vvv_PositionsVSF[vid].resize(S_Count);

    //get S
    vvv_PositionsVSF[vid][0].clear();
    for(size_t f = 0; f < vv_CentersVF[vid].size(); f++)
        vvv_PositionsVSF[vid][0].push_back(- vv_CentersVF[vid][f].y);

    qDebug() << QSL_Videos_Names[vid] << "CalcAll" << "Diff";


    for(size_t i = 1; i < S_Count; i++)
    {
        qDebug() << QSL_Videos_Names[vid] << "CalcAll" << "Diff" << QSL_S_Names[i-1] << "(size:" + QString::number(vvv_PositionsVSF[vid][i-1].size()) +  ") to" << QSL_S_Names[i];

        if(vvv_PositionsVSF[vid][i-1].size() > blur_frames)
        {
            //smooth
            vector<double> v_smooth;
            for(int f = blur_frames_offset; f < static_cast<int>(vvv_PositionsVSF[vid][i-1].size()) - blur_frames_offset; f++)
            {
                double sum = 0;
                for(int m = -blur_frames_offset; m <= blur_frames_offset; m++)
                    sum += vvv_PositionsVSF[vid][i-1][f+m];
                v_smooth.push_back(sum/blur_frames);
            }

            //differenciate
            vvv_PositionsVSF[vid][i].clear();
            for(size_t f = 0; f < v_smooth.size() - 1; f++)
                vvv_PositionsVSF[vid][i].push_back(v_smooth[f+1] - v_smooth[f]);
        }
        else
        {
            qDebug() << QSL_Videos_Names[vid] << "CalcAll" << "Diff" << "Signal to short";
            vvv_PositionsVSF[vid][i].clear();
            vvv_PositionsVSF[vid][i].push_back(0);
        }
    }

    qDebug() << QSL_Videos_Names[vid] << "CalcAll" << "End";

    PlotAll();
}

void D_MAKRO_AirDragTrack::PlotAll()
{
    int vid = ui->comboBox_DataInput->currentIndex();
    qDebug() << QSL_Videos_Names[vid] << "PlotAll" << "Start";

    for(size_t i = 0; i < S_Count; i++)
    {
        vector<double> vFrames;
        for(size_t f = 0; f < vvv_PositionsVSF[vid][i].size(); f++)
            vFrames.push_back(f + (ui->spinBox_BlurFrames->value()/2) * i);

        D_Plot::Plot_Line_XY_Single(
                    vPlot_ChartViews_S[i],
                    vFrames,
                    vvv_PositionsVSF[vid][i],
                    QSL_S_Names[i],
                    "Biggest detected Object",
                    "Frame",
                    QSL_S_Names[i]);

        vPlot_ChartViews_S[i]->chart()->legend()->setVisible(false);

        if(i == 0)
        {
            vPlot_ChartViews_S[i]->chart()->axisY()->setMin(-1000);
            vPlot_ChartViews_S[i]->chart()->axisY()->setMax(0);
            vPlot_ChartViews_S[i]->chart()->axisX()->setMax(0);
            vPlot_ChartViews_S[i]->chart()->axisX()->setMax(100);
        }
        else if(i == 1)
        {
            vPlot_ChartViews_S[i]->chart()->axisY()->setMin(-20);
            vPlot_ChartViews_S[i]->chart()->axisY()->setMax(0);
            vPlot_ChartViews_S[i]->chart()->axisX()->setMax(0);
            vPlot_ChartViews_S[i]->chart()->axisX()->setMax(100);
        }
        else if(i == 2)
        {
            vPlot_ChartViews_S[i]->chart()->axisY()->setMin(-0.4);
            vPlot_ChartViews_S[i]->chart()->axisY()->setMax(0);
            vPlot_ChartViews_S[i]->chart()->axisX()->setMax(0);
            vPlot_ChartViews_S[i]->chart()->axisX()->setMax(100);
        }
        else if(i == 3)
        {
            vPlot_ChartViews_S[i]->chart()->axisY()->setMin(-0.004);
            vPlot_ChartViews_S[i]->chart()->axisY()->setMax(0.004);
            vPlot_ChartViews_S[i]->chart()->axisX()->setMax(0);
            vPlot_ChartViews_S[i]->chart()->axisX()->setMax(100);
        }
        else if(i == 4)
        {
            vPlot_ChartViews_S[i]->chart()->axisY()->setMin(-0.001);
            vPlot_ChartViews_S[i]->chart()->axisY()->setMax(0.001);
            vPlot_ChartViews_S[i]->chart()->axisX()->setMax(0);
            vPlot_ChartViews_S[i]->chart()->axisX()->setMax(100);
        }
    }

    qDebug() << QSL_Videos_Names[vid] << "PlotAll" << "End";
    PlotAllVideos();//if possible
}

void D_MAKRO_AirDragTrack::PlotAllVideos()
{
    for(size_t v = 0; v < vvv_PositionsVSF.size(); v++)
        if(vvv_PositionsVSF[v].empty())
            return;

    int s = ui->comboBox_Results->currentIndex();

    //data
    vector<vector<double>> vvX(vvv_PositionsVSF.size());
    vector<vector<double>> vvY(vvv_PositionsVSF.size());

    //loop videos to get data
    for(size_t v = 0; v < vvv_PositionsVSF.size(); v++)
        for(size_t f = 0; f < vvv_PositionsVSF[v][s].size(); f++)
        {
            vvX[v].push_back(f + (ui->spinBox_BlurFrames->value()/2) * s);
            vvY[v].push_back(vvv_PositionsVSF[v][s][f]);
        }

    //plot
    D_Plot::Plot_Line_XY_Multi(
                Plot_Results,
                vvX,
                vvY,
                QSL_S_Names[s],
                QSL_Videos_Names,
                "Frame",
                QSL_S_Names[s]);

    if(s == 0)
    {
        Plot_Results->chart()->axisY()->setMin(-1000);
        Plot_Results->chart()->axisY()->setMax(0);
        Plot_Results->chart()->axisX()->setMax(0);
        Plot_Results->chart()->axisX()->setMax(100);
    }
    else if(s == 1)
    {
        Plot_Results->chart()->axisY()->setMin(-20);
        Plot_Results->chart()->axisY()->setMax(0);
        Plot_Results->chart()->axisX()->setMax(0);
        Plot_Results->chart()->axisX()->setMax(100);
    }
    else if(s == 2)
    {
        Plot_Results->chart()->axisY()->setMin(-0.4);
        Plot_Results->chart()->axisY()->setMax(0);
        Plot_Results->chart()->axisX()->setMax(0);
        Plot_Results->chart()->axisX()->setMax(100);
    }
    else if(s == 3)
    {
        Plot_Results->chart()->axisY()->setMin(-0.004);
        Plot_Results->chart()->axisY()->setMax(0.004);
        Plot_Results->chart()->axisX()->setMax(0);
        Plot_Results->chart()->axisX()->setMax(100);
    }
    else if(s == 4)
    {
        Plot_Results->chart()->axisY()->setMin(-0.001);
        Plot_Results->chart()->axisY()->setMax(0.001);
        Plot_Results->chart()->axisX()->setMax(0);
        Plot_Results->chart()->axisX()->setMax(100);
    }
}


void D_MAKRO_AirDragTrack::Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(index_init);
    CB->blockSignals(false);
}

void D_MAKRO_AirDragTrack::Populate_CB_Start()
{
    Populate_CB_Single(ui->comboBox_Color2Mono,     QSL_Color2Mono,     c_COL2MONO_RED);
    Populate_CB_Single(ui->comboBox_Results,        QSL_S_Names,        0);
}

void D_MAKRO_AirDragTrack::BlockSignals_FrameSelection(bool block)
{
    ui->horizontalSlider_T_Frame->blockSignals(block);
    ui->spinBox_T_Frame->blockSignals(block);
    ui->doubleSpinBox_T_Sec->blockSignals(block);
}

void D_MAKRO_AirDragTrack::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_MAKRO_AirDragTrack", func, detail);
}


void D_MAKRO_AirDragTrack::on_horizontalSlider_T_Frame_valueChanged(int value)
{
    BlockSignals_FrameSelection(true);
    ui->spinBox_T_Frame->setValue(value);
    ui->horizontalSlider_T_Frame->setValue(value);
    ui->doubleSpinBox_T_Sec->setValue(static_cast<int>(value * VS_Video.get_FrameTimeSec() * 100) / 100.0);
    BlockSignals_FrameSelection(false);

    Update_ImgProc_All();
}

void D_MAKRO_AirDragTrack::on_spinBox_T_Frame_valueChanged(int arg1)
{
    BlockSignals_FrameSelection(true);
    ui->horizontalSlider_T_Frame->setValue(arg1);
    ui->doubleSpinBox_T_Sec->setValue(static_cast<int>(arg1 * VS_Video.get_FrameTimeSec() * 100) / 100.0);
    BlockSignals_FrameSelection(false);

    Update_ImgProc_All();
}

void D_MAKRO_AirDragTrack::on_doubleSpinBox_T_Sec_valueChanged(double arg1)
{
    BlockSignals_FrameSelection(true);
    ui->spinBox_T_Frame->setValue(static_cast<int>(arg1 / VS_Video.get_FrameTimeSec()));
    ui->horizontalSlider_T_Frame->setValue(static_cast<int>(arg1 / VS_Video.get_FrameTimeSec()));
    BlockSignals_FrameSelection(false);

    Update_ImgProc_All();
}

void D_MAKRO_AirDragTrack::on_comboBox_ProcStep_currentIndexChanged(int index)
{
    index;
    Update_Images();
}

void D_MAKRO_AirDragTrack::on_spinBox_CropStart_valueChanged(int arg1)
{
    F_start = arg1;
}

void D_MAKRO_AirDragTrack::on_spinBox_CropEnd_valueChanged(int arg1)
{
    F_end = arg1;
}

void D_MAKRO_AirDragTrack::on_pushButton_ProcVideo_clicked()
{
    Update_ImgProc_FullVideo();
}

void D_MAKRO_AirDragTrack::on_pushButton_ProcAllVideos_clicked()
{
    for(size_t v = 0; v < vvv_PositionsVSF.size(); v++)
    {
        ui->comboBox_DataInput->setCurrentIndex(v);
        Update_ImgProc_FullVideo();
    }
}

void D_MAKRO_AirDragTrack::on_action_View_Results_Big_triggered(bool checked)
{
    ui->groupBox_S0->setVisible(!checked);
    ui->groupBox_S1->setVisible(!checked);
    ui->groupBox_S2->setVisible(!checked);
    ui->groupBox_S3->setVisible(!checked);
    ui->groupBox_S4->setVisible(!checked);
    ui->groupBox_Results->setVisible(checked);
}

void D_MAKRO_AirDragTrack::on_action_Save_Screenshot_Full_Window_triggered()
{
    QString name_default =
            pStore->dir_Save()->path() + "/Screenshot " +
            this->windowTitle();

    QFileInfo FI_save(name_default + ".jpg");
    int count = 1;
    while(FI_save.exists())
        FI_save.setFile(name_default + "_" + QString::number(count) + ".jpg");

    QString save_name = QFileDialog::getSaveFileName(
                        this,
                        tr("Save Screenshot"),
                        FI_save.absoluteFilePath(),
                        tr("Images (*.png *.jpg *.bmp *.tif)"));

    if(save_name != 0)
    {
        this->grab().save(save_name);
        pStore->set_dir_Save(save_name);
    }
}
