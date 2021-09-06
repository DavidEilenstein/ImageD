/************************************
 *   added:     13.11.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_makro_cerebralorganoids.h"
#include "ui_d_makro_cerebralorganoids.h"

D_MAKRO_CerebralOrganoids::D_MAKRO_CerebralOrganoids(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_CerebralOrganoids)
{
    //features extended
    QSL_FeatAll = QSL_FeatureList;
    for(int fc = 0; fc < QSL_FeatCustom.size(); fc++)
        QSL_FeatAll.append(QSL_FeatCustom[fc]);

    //ui
    ui->setupUi(this);
    Populate_CB_Init();

    //Store
    pStore = pStorage;

    //Images
    vMA_ProcSteps.resize(STEP_NUMBER_OF);
    for(int s = 0; s < STEP_NUMBER_OF; s++)
        vMA_ProcSteps[s] = pStore->get_Adress(0)->clone();
    MA_Vis = pStore->get_Adress(0)->clone();

    //status bar
    pL_SB_PxVal = new QLabel();
    ui->statusbar->addPermanentWidget(pL_SB_PxVal);
    pL_SB_PxVal->setText("Pixel value under mouse");
    pL_SB_PxVal->setToolTip("Pixel value under mouse");

    //Viewer
    ViewProc.set_GV(ui->graphicsView_Proc);
    ViewRes.set_GV(ui->graphicsView_Vis);
    ViewProc.connect_Zoom(&ViewRes);

    //Table
    Table_Flask.set_TW(ui->tableWidget_ResFlask);
    Table_TD.set_TW(ui->tableWidget_ResTD);

    //Plot
    delete ui->gridLayout_ResExp->takeAt(0);
    pChartView = new QChartView();
    ui->gridLayout_ResExp->addWidget(pChartView);
    pChartView->setRenderHint(QPainter::Antialiasing);
    pChartView->setRubberBand(QChartView::RectangleRubberBand);
    pChartView->setInteractive(true);

    //Load
    connect(ui->action_Load_Data,                   SIGNAL(triggered(bool)),                    this,                   SLOT(Load_Exp()));
    //save
    connect(ui->action_Save_Image_Processing,       SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Image_Processing()));
    connect(ui->action_Save_Image_Visualization,    SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Image_Visualization()));
    connect(ui->action_Save_Table_Flask,            SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Table_Flask()));
    connect(ui->action_Save_Table_Time_Dose,        SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Table_TD()));
    connect(ui->action_Save_Plot_Experiment,        SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Plot_Experiment()));
    connect(ui->action_Save_Analysis,               SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Analysis_Save()));
    //stack
    connect(ui->action_Process_Stack,               SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Analysis_Update()));
    //view
    connect(ui->comboBox_Proc_Step,                 SIGNAL(currentIndexChanged(int)),           this,                   SLOT(UpdateImage_Proc()));
    //results
    connect(ui->comboBox_VisFeat,                   SIGNAL(currentIndexChanged(int)),           this,                   SLOT(UpdateResults()));
    connect(ui->spinBox_Vis_Precision,              SIGNAL(valueChanged(int)),                  this,                   SLOT(UpdateResults()));
    connect(ui->spinBox_Vis_Thickness,              SIGNAL(valueChanged(int)),                  this,                   SLOT(UpdateResults()));
    connect(ui->doubleSpinBox_Vis_Scale,            SIGNAL(valueChanged(double)),               this,                   SLOT(UpdateResults()));
    connect(ui->comboBox_ResExp_Feat,               SIGNAL(currentIndexChanged(int)),           this,                   SLOT(UpdateResults()));
    connect(ui->comboBox_ResExp_Stat_Line,          SIGNAL(currentIndexChanged(int)),           this,                   SLOT(UpdateResults()));
    connect(ui->comboBox_ResExp_Stat_Errors,        SIGNAL(currentIndexChanged(int)),           this,                   SLOT(UpdateResults()));
    //viewer
    connect(&ViewProc,                              SIGNAL(MouseMoved_Value(QString)),          pL_SB_PxVal,            SLOT(setText(QString)));
    connect(&ViewRes,                               SIGNAL(MouseMoved_Value(QString)),          pL_SB_PxVal,            SLOT(setText(QString)));

    //on start
    px_scale = ui->doubleSpinBox_ProcSet_PixelSize->value();
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    setWindowTitle("ImageD - Cerebral Organoids");
    StyleDefault = this->styleSheet();
}

D_MAKRO_CerebralOrganoids::~D_MAKRO_CerebralOrganoids()
{
    delete ui;
}

void D_MAKRO_CerebralOrganoids::closeEvent(QCloseEvent *event)
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

void D_MAKRO_CerebralOrganoids::resizeEvent(QResizeEvent *event)
{
    event->accept();
    UpdateViews();
}

void D_MAKRO_CerebralOrganoids::Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(index_init);
    CB->blockSignals(false);
}

void D_MAKRO_CerebralOrganoids::Populate_CB_Init()
{
    //Proc Steps
    Populate_CB_Single(ui->comboBox_Proc_Step,          QSL_ProcStep,           STEP_LOAD);

    //Modes
    Populate_CB_Single(ui->comboBox_ResFlask_Mode,      QSL_ResType_Flask,      RES_TYPE_FLASK_STAT);
    Populate_CB_Single(ui->comboBox_ResTD_Mode,         QSL_ResType_TD,         RES_TYPE_TD_STAT);
    Populate_CB_Single(ui->comboBox_ResExp_Mode,        QSL_ResType_Exp,        RES_TYPE_EXP_STATS_LINE);

    //Feat
    Populate_CB_Single(ui->comboBox_ResExp_Feat,        QSL_FeatAll,            FEAT_CUSTOM_AREA_MM);
    Populate_CB_Single(ui->comboBox_VisFeat,            QSL_FeatAll,            c_FEAT_LABEL);

    //Stat
    Populate_CB_Single(ui->comboBox_ResExp_Stat_Line,   QSL_StatList,           c_STAT_MEAN_ARITMETIC);
    Populate_CB_Single(ui->comboBox_ResExp_Stat_Errors, QSL_StatList,           c_STAT_SEM_ABS_TOTAL);
}

bool D_MAKRO_CerebralOrganoids::Populate_CB_LoadExp()
{
    //Time
    if(QSL_Times.empty())
            return false;
    qDebug() << "Populate_CB_LoadExp" << "times";
    Populate_CB_Single(ui->comboBox_Data_Time,      QSL_Times,              0);

    //Dose (updated when time changes)
    if(vQSL_Dose[0].empty())
        return false;
    qDebug() << "Populate_CB_LoadExp" << "dose";
    Populate_CB_Single(ui->comboBox_Data_Dose,      vQSL_Dose[0],           0);

    //Flask (updated when time or dose changes)
    if(vvQSL_Flask[0][0].empty())
        return false;
    qDebug() << "Populate_CB_LoadExp" << "flask";
    Populate_CB_Single(ui->comboBox_Data_Flask,     vvQSL_Flask[0][0],      0);

    return true;
}

void D_MAKRO_CerebralOrganoids::Load_Exp()
{
    //Experiemnt path
    QString QS_ExpPath = QFileDialog::getExistingDirectory(
                this,
                "Load Experiment",
                pStore->dir_M_CerebralOrganoids()->path());
    if(QS_ExpPath == 0)
        return;
    pStore->set_dir_M_CerebralOrganoids(QS_ExpPath);
    DIR_Experiment.setPath(QS_ExpPath);
    QS_ExpName = DIR_Experiment.dirName();
    qDebug() << "Load_Exp" << "path" << QS_ExpPath;

    //states
    state_exp_loaded                = false;
    state_img_loaded_current        = false;
    state_img_proc_up2date_current  = false;
    state_stack_analysed            = false;
    state_calced_stack              = false;
    state_calced_stack_comps        = false;
    state_calced_stack_stats        = false;
    state_calced_current            = false;
    state_calced_current_feats      = false;
    state_calced_current_stats      = false;

    //clear old stuff
    QSL_Times.clear();
    vVAL_Times.clear();
    vDIR_Times.clear();
    vQSL_Dose.clear();
    vvVAL_Dose.clear();
    vvDIR_Dose.clear();
    vvvFI_Flask.clear();
    vvQSL_Flask.clear();

    //find times===================================================================================================================================
    //qDebug() << "Load_Exp" << "times" << "--------------";
    QFileInfoList FIL_inExp = DIR_Experiment.entryInfoList(QDir::AllDirs | QDir::NoSymLinks | QDir::NoDotAndDotDot);
    //qDebug() << "Load_Exp" << "times" << FIL_inExp;
    for(int f = 0; f < FIL_inExp.size(); f++)
    {
        if(FIL_inExp[f].isDir())
        {
            //qDebug() << "Load_Exp" << "is dir";
            QString QS_BaseName = FIL_inExp[f].baseName();

            //count letters
            int letter_count = 0;
            for(int l = 0; l < QSl_AlphabetAll.size(); l++)
                if(QS_BaseName.contains(QSl_AlphabetAll[l]))
                    letter_count++;

            //only 1 letter contained
            if(letter_count == 1)
            {
                //qDebug() << "Load_Exp" << "is 1 letter";
                //only d or D contained?
                if(QS_BaseName.contains('d') || QS_BaseName.contains('D'))
                {
                    //qDebug() << "Load_Exp" << "contains d or D";
                    //letter position
                    int letter_pos = 0;
                    if(QS_BaseName.contains('d'))
                        letter_pos = QS_BaseName.lastIndexOf('d');
                    if(QS_BaseName.contains('D'))
                        letter_pos = QS_BaseName.lastIndexOf('D');
                    if(letter_pos == 0)
                    {
                        //qDebug() << "Load_Exp" << "starts with d or D";

                        //get time value
                        bool time_val_sucess = false;
                        int time_val = QS_BaseName.right(QS_BaseName.size() - 1).toDouble(&time_val_sucess);
                        if(time_val_sucess)
                        {
                            //qDebug() << "Load_Exp" << "time read sucess";
                            //qDebug() << "Load_Exp" << "time" << QS_BaseName << time_val;

                            //time stuff
                            QSL_Times.append(QS_BaseName);
                            vVAL_Times.push_back(time_val);
                            vDIR_Times.push_back(QDir(FIL_inExp[f].absoluteFilePath()));
                        }
                    }
                }
            }
            else
            {
                //reference image?
                if(QS_BaseName.contains("Reference") || QS_BaseName.contains("REFERENCE") || QS_BaseName.contains("reference"))
                {
                    QFileInfoList FIL_inRef = QDir(FIL_inExp[f].absoluteFilePath()).entryInfoList();
                    for(int r = 0; r < FIL_inRef.size(); r++)
                        if(FIL_inRef[r].suffix() == "JPG" || FIL_inRef[r].suffix() == "jpg" || FIL_inRef[r].suffix() == "jpeg" || FIL_inRef[r].suffix() == "JPEG")
                        {
                            FIL_Reference = FIL_inRef[r];
                            qDebug() << "Load_Exp" << "reference found";
                        }
                }
            }
        }
    }

    //find dose===================================================================================================================================
    qDebug() << "Load_Exp" << "doses" << "--------------";
    //resize dose container fitting to times
    size_t t_count = QSL_Times.size();
    vQSL_Dose.resize(t_count);
    vvVAL_Dose.resize(t_count);
    vvDIR_Dose.resize(t_count);
    vvvvTimeDoseFeatComp.resize(t_count);
    vvvvTimeDoseFeatStat.resize(t_count);
    vvvvvTimeDoseFlaskFeatComp.resize(t_count);
    vvvvvTimeDoseFlaskFeatStat.resize(t_count);
    for(int t = 0; t < vDIR_Times.size(); t++)
    {
        QFileInfoList FIL_inTime = vDIR_Times[t].entryInfoList(QDir::AllDirs | QDir::NoSymLinks | QDir::NoDotAndDotDot);
        //qDebug() << "Load_Exp" << "times" << t << FIL_inTime;
        for(int f = 0; f < FIL_inTime.size(); f++)
        {
            if(FIL_inTime[f].isDir())
            {
                //qDebug() << "Load_Exp" << "is dir";
                QString QS_BaseName = FIL_inTime[f].baseName();

                //count letters
                int letter_count = 0;
                for(int l = 0; l < QSl_AlphabetAll.size(); l++)
                    if(QS_BaseName.contains(QSl_AlphabetAll[l]))
                        letter_count++;

                //only 2 letter contained?
                if(letter_count == 2)
                {
                    //qDebug() << "Load_Exp" << "exactly 2 letter";
                    //only GY, Gy or gy contained?
                    if(QS_BaseName.contains("GY") || QS_BaseName.contains("Gy") || QS_BaseName.contains("gy"))
                    {
                        //qDebug() << "Load_Exp" << "contains GY, Gy or gy";
                        //letter position
                        int letter_pos = 0;
                        if(QS_BaseName.contains("GY"))
                            letter_pos = QS_BaseName.lastIndexOf("GY");
                        if(QS_BaseName.contains("Gy"))
                            letter_pos = QS_BaseName.lastIndexOf("Gy");
                        if(QS_BaseName.contains("gy"))
                            letter_pos = QS_BaseName.lastIndexOf("gy");
                        if(letter_pos == QS_BaseName.size() - 2)
                        {
                            //qDebug() << "Load_Exp" << "letter pos == QS_baseName.size() - 2";
                            //get time value
                            bool dose_val_sucess = false;
                            int dose_val = QS_BaseName.left(QS_BaseName.size() - 2).toDouble(&dose_val_sucess);
                            if(dose_val_sucess)
                            {
                                //qDebug() << "Load_Exp" << "time" << t << QS_BaseName << dose_val;

                                //dose stuff
                                vQSL_Dose[t].append(QS_BaseName);
                                vvVAL_Dose[t].push_back(dose_val);
                                vvDIR_Dose[t].push_back(QDir(FIL_inTime[f].absoluteFilePath()));
                            }
                        }
                    }
                }
            }
        }
    }

    //find flasks===================================================================================================================================
    qDebug() << "Load_Exp" << "flasks" << "--------------";
    //resize flask containers fitting to time
    vvQSL_Flask.resize(QSL_Times.size());
    vvvFI_Flask.resize(vDIR_Times.size());
    for(int t = 0; t < vDIR_Times.size(); t++)
    {
        //resize flask containers fitting to dose
        size_t d_count = vQSL_Dose[t].size();
        vvQSL_Flask[t].resize(d_count);
        vvvFI_Flask[t].resize(d_count);
        vvvvTimeDoseFeatComp[t].resize(d_count);
        vvvvTimeDoseFeatStat[t].resize(d_count);
        vvvvvTimeDoseFlaskFeatComp[t].resize(d_count);
        vvvvvTimeDoseFlaskFeatStat[t].resize(d_count);

        for(int d = 0; d < vvDIR_Dose[t].size(); d++)
        {
            QFileInfoList FIL_inDose = vvDIR_Dose[t][d].entryInfoList();
            //qDebug() << "Load_Exp" << "times" << t << "dose" << d << FIL_inDose;
            int f_count = 0;
            for(int f = 0; f < FIL_inDose.size(); f++)
            {
                if(FIL_inDose[f].suffix() == "JPG" || FIL_inDose[f].suffix() == "jpg" || FIL_inDose[f].suffix() == "jpeg" || FIL_inDose[f].suffix() == "JPEG")
                {
                    QString QS_BaseName = FIL_inDose[f].baseName();

                    qDebug() << "Load_Exp" << "time" << t << "dose" << d << "flask" << f_count << ":" << QS_BaseName;

                    //flask stuff
                    vvQSL_Flask[t][d].append(QS_BaseName);
                    vvvFI_Flask[t][d].push_back(FIL_inDose[f]);

                    f_count++;
                }
            }

            vvvvvTimeDoseFlaskFeatComp[t][d].resize(f_count);
            vvvvvTimeDoseFlaskFeatStat[t][d].resize(f_count);
        }
    }

    //resize sizes in feat dimensions
    for(int time = 0; time < vvvvvTimeDoseFlaskFeatComp.size(); time++)
        for(int dose = 0; dose < vvvvvTimeDoseFlaskFeatComp[time].size(); dose++)
        {
            vvvvTimeDoseFeatComp[time][dose].resize(FEAT_CUSTOM_NUMBER_OF);
            vvvvTimeDoseFeatStat[time][dose].resize(FEAT_CUSTOM_NUMBER_OF);
            for(int flask = 0; flask < vvvvvTimeDoseFlaskFeatComp[time][dose].size(); flask++)
            {
                vvvvvTimeDoseFlaskFeatComp[time][dose][flask].resize(FEAT_CUSTOM_NUMBER_OF);
                vvvvvTimeDoseFlaskFeatStat[time][dose][flask].resize(FEAT_CUSTOM_NUMBER_OF);
            }
        }


    //Populate CBs
    qDebug() << "Load_Exp" << "populate" << "--------------";
    state_exp_loaded = Populate_CB_LoadExp();

    //Update Proc
    UpdateImgProc(0);
}

void D_MAKRO_CerebralOrganoids::UpdateViews()
{
    UpdateView_Proc();
    UpdateView_Vis();
}

void D_MAKRO_CerebralOrganoids::UpdateView_Proc()
{
    ViewProc.Update_View();
}

void D_MAKRO_CerebralOrganoids::UpdateView_Vis()
{
    ViewRes.Update_View();
}

void D_MAKRO_CerebralOrganoids::UpdateImages()
{
    UpdateImage_Proc();
    UpdateImage_Vis();
}

void D_MAKRO_CerebralOrganoids::UpdateImage_Proc()
{
    ViewProc.Update_Image(&(vMA_ProcSteps[ui->comboBox_Proc_Step->currentIndex()]));
}

void D_MAKRO_CerebralOrganoids::UpdateImage_Vis()
{
    ViewRes.Update_Image(&MA_Vis);
}

void D_MAKRO_CerebralOrganoids::UpdateUi()
{
    bool en_in = this->isEnabled();
    if(en_in)
        this->setEnabled(false);

    this->repaint();
    qApp->processEvents();

    if(en_in)
        this->setEnabled(true);
}

void D_MAKRO_CerebralOrganoids::UpdateProc_Stack()
{
    if(!state_exp_loaded)
        return;

    state_stack_analysed = false;
    state_stack_processing = true;

    //Show visualization
    ui->tabWidget_Results->setCurrentIndex(RES_VIS);
    ui->comboBox_VisFeat->setCurrentIndex(c_FEAT_LABEL);

    //disable update triggers for data view
    ui->comboBox_Data_Time->blockSignals(true);
    ui->comboBox_Data_Dose->blockSignals(true);
    ui->comboBox_Data_Flask->blockSignals(true);

    //select current pos in data
    int analysis_counter = 0;
    //time
    for(int time = 0; time < vvvvvTimeDoseFlaskFeatComp.size(); time++)
    {
        //dose
        ui->comboBox_Data_Time->setCurrentIndex(time);
        Populate_CB_Single(ui->comboBox_Data_Dose, vQSL_Dose[time], 0);
        for(int dose = 0; dose < vvvvvTimeDoseFlaskFeatComp[time].size(); dose++)
        {
            //flask
            ui->comboBox_Data_Dose->setCurrentIndex(dose);
            Populate_CB_Single(ui->comboBox_Data_Flask, vvQSL_Flask[time][dose], 0);
            for(int flask = 0; flask < vvvvvTimeDoseFlaskFeatComp[time][dose].size(); flask++)
            {
                analysis_counter++;
                qDebug() << "Analysis" << analysis_counter << "Time" << time << "Dose" << dose << "Flask" << flask;

                ui->comboBox_Data_Flask->setCurrentIndex(flask);

                //for each images
                UpdateImgProc(0);   //triggers feat measurement and calc of stats internally
                UpdateUi();

                //save single visualization
                Save_Image(
                            &ViewRes,
                            DIR_Save_Images.path() + "/LabelNumbers_" + vvvFI_Flask[time][dose][flask].baseName() + ".png");
            }
        }
    }

    //enable update triggers for data view
    ui->comboBox_Data_Time->blockSignals(false);
    ui->comboBox_Data_Dose->blockSignals(false);
    ui->comboBox_Data_Flask->blockSignals(false);

    Calc_Stack_All();

    state_stack_processing = false;
    state_stack_analysed = true;
}

void D_MAKRO_CerebralOrganoids::UpdateImgProc(int step_start)
{
    if(!state_exp_loaded)
        return;

    for(int s = step_start; s < STEP_NUMBER_OF; s++)
    {
        UpdateImgProc_Step(s);
        /*if(state_stack_processing)
        {
            ui->comboBox_Proc_Step->setCurrentIndex(s);
            UpdateUi();
        }*/
    }

    UpdateImage_Proc();
    Calc_Single_All();
}

void D_MAKRO_CerebralOrganoids::UpdateImgProc_Step(int step)
{
    state_img_proc_up2date_current = false;
    state_calced_current = false;

    int t = ui->comboBox_Data_Time->currentIndex();
    int d = ui->comboBox_Data_Dose->currentIndex();
    int f = ui->comboBox_Data_Flask->currentIndex();

    int ER = ER_okay;

    switch (step) {

    case STEP_LOAD:
    {
        state_img_loaded_current = false;
        state_img_proc_up2date_current = false;
        ER = D_Img_Proc::Load_From_Path(
                    &(vMA_ProcSteps[STEP_LOAD]),
                    vvvFI_Flask[t][d][f]);
        ERR(
                    ER,
                    "UpdateImgProc_Step",
                    "STEP_LOAD");
        if(ER == ER_okay)
            state_img_loaded_current = true;
    }
        break;

    case STEP_BLUR:
    {
        if(!state_img_loaded_current)
            return;

        ERR(D_Img_Proc::Filter_Gauss(
                &(vMA_ProcSteps[STEP_BLUR]),
                &(vMA_ProcSteps[STEP_LOAD]),
                ui->spinBox_ProcSet_BlurSize->value() / 2,
                ui->spinBox_ProcSet_BlurSize->value() / 2,
                BORDER_DEFAULT,
                ui->doubleSpinBox_ProcSet_BlurSigma->value(),
                ui->doubleSpinBox_ProcSet_BlurSigma->value()),
            "UpdateImgProc_Step",
            "STEP_BLUR");
    }
        break;

    case STEP_COLOR_HSV:
    {
        if(!state_img_loaded_current)
            return;

        ERR(D_Img_Proc::Convert_Color(
                &(vMA_ProcSteps[STEP_COLOR_HSV]),
                &(vMA_ProcSteps[STEP_BLUR]),
                CV_BGR2HSV),
            "UpdateImgProc_Step",
            "STEP_HSV");
    }
        break;

    case STEP_COLOR_HUE:
    {
        if(!state_img_loaded_current)
            return;

        ERR(D_Img_Proc::Split(
                &(vMA_ProcSteps[STEP_COLOR_HUE]),
                &(vMA_ProcSteps[STEP_COLOR_HSV]),
                0),
            "UpdateImgProc_Step",
            "STEP_HUE");
    }
        break;

    case STEP_COLOR_SAT:
    {
        if(!state_img_loaded_current)
            return;

        ERR(D_Img_Proc::Split(
                &(vMA_ProcSteps[STEP_COLOR_SAT]),
                &(vMA_ProcSteps[STEP_COLOR_HSV]),
                1),
            "UpdateImgProc_Step",
            "STEP_SAT");
    }
        break;

    case STEP_COLOR_VAL:
    {
        if(!state_img_loaded_current)
            return;

        ERR(D_Img_Proc::Split(
                &(vMA_ProcSteps[STEP_COLOR_VAL]),
                &(vMA_ProcSteps[STEP_COLOR_HSV]),
                2),
            "UpdateImgProc_Step",
            "STEP_VAL");
    }
        break;

    case STEP_COLOR_GRAB:
    {
        if(!state_img_loaded_current)
            return;

        vector<uchar> min;
        vector<uchar> max;
        min.push_back((uchar) ui->spinBox_ProcSet_ColorSelect_H_Min->value());
        min.push_back((uchar) ui->spinBox_ProcSet_ColorSelect_S_Min->value());
        min.push_back((uchar) ui->spinBox_ProcSet_ColorSelect_V_Min->value());
        max.push_back((uchar) ui->spinBox_ProcSet_ColorSelect_H_Max->value());
        max.push_back((uchar) ui->spinBox_ProcSet_ColorSelect_S_Max->value());
        max.push_back((uchar) ui->spinBox_ProcSet_ColorSelect_V_Max->value());

        ERR(D_Img_Proc::Color_Grab(
                &(vMA_ProcSteps[STEP_COLOR_GRAB]),
                &(vMA_ProcSteps[STEP_BLUR]),
                3,//HSV
                0,//Mask
                min,
                max),
            "UpdateImgProc_Step",
            "STEP_COLOR_GRAB");
    }
        break;

    case STEP_OBJ_CLOSING:
    {
        if(!state_img_loaded_current)
            return;

        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_ProcSteps[STEP_OBJ_CLOSING]),
                &(vMA_ProcSteps[STEP_COLOR_GRAB]),
                MORPH_CLOSE,
                MORPH_ELLIPSE,
                ui->spinBox_ProcSet_ClosingSize->value(),
                ui->spinBox_ProcSet_ClosingSize->value(),
                BORDER_DEFAULT,
                1),
            "UpdateImgProc_Step",
            "STEP_OBJ_CLOSING");
    }
        break;

    case STEP_OBJ_OPENING:
    {
        if(!state_img_loaded_current)
            return;

        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_ProcSteps[STEP_OBJ_OPENING]),
                &(vMA_ProcSteps[STEP_OBJ_CLOSING]),
                MORPH_OPEN,
                MORPH_ELLIPSE,
                ui->spinBox_ProcSet_OpeningSize->value(),
                ui->spinBox_ProcSet_OpeningSize->value(),
                BORDER_DEFAULT,
                1),
            "UpdateImgProc_Step",
            "STEP_OBJ_OPENING");
    }
        break;

    case STEP_OBJ_SELECT_AREA:
    {
        if(!state_img_loaded_current)
            return;

        ERR(D_Img_Proc::Feature_Select(
                &(vMA_ProcSteps[STEP_OBJ_SELECT_AREA]),
                &(vMA_ProcSteps[STEP_OBJ_OPENING]),
                c_FEAT_AREA,
                ui->doubleSpinBox_ProcSet_SelectArea_Min->value(),
                ui->doubleSpinBox_ProcSet_SelectArea_Max->value(),
                8),
            "UpdateImgProc_Step",
            "STEP_OBJ_SELECT_AREA");
    }
        break;

    case STEP_OBJ_SELECT_ROUNDNESS:
    {
        if(!state_img_loaded_current)
            return;

        int ER = D_Img_Proc::Feature_Select(
                    &(vMA_ProcSteps[STEP_OBJ_SELECT_ROUNDNESS]),
                    &(vMA_ProcSteps[STEP_OBJ_SELECT_AREA]),
                    c_FEAT_ROUNDNESS,
                    ui->doubleSpinBox_ProcSet_SelectRoundness_Min->value(),
                    ui->doubleSpinBox_ProcSet_SelectRoundness_Max->value(),
                    8);
        ERR(
                    ER,
                    "UpdateImgProc_Step",
                    "STEP_OBJ_SELECT_ROUNDNESS");
    }
        break;

    case STEP_GRAY:
    {
        if(!state_img_loaded_current)
            return;

        ERR(D_Img_Proc::Convert_Color2Mono(
                &(vMA_ProcSteps[STEP_GRAY]),
                &(vMA_ProcSteps[STEP_BLUR]),
                c_COL2MONO_GRAY),
            "UpdateImgProc_Step",
            "STEP_GRAY");
    }
        break;

    case STEP_ROI_THRES:
    {
        if(!state_img_loaded_current)
            return;

        ERR(D_Img_Proc::Threshold_Absolute(
                &(vMA_ProcSteps[STEP_ROI_THRES]),
                &(vMA_ProcSteps[STEP_GRAY]),
                ui->doubleSpinBox_ProcSet_Thresh->value()),
            "UpdateImgProc_Step",
            "STEP_ROI_THRES");
    }
        break;

    case STEP_ROI_CLOSING:
    {
        if(!state_img_loaded_current)
            return;

        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_ProcSteps[STEP_ROI_CLOSING]),
                &(vMA_ProcSteps[STEP_ROI_THRES]),
                MORPH_CLOSE,
                MORPH_RECT,
                ui->spinBox_ProcSet_ROI_Close->value(),
                ui->spinBox_ProcSet_ROI_Close->value(),
                BORDER_DEFAULT,
                1),
            "UpdateImgProc_Step",
            "STEP_ROI_CLOSING");
    }
        break;

    case STEP_ROI_OPENING:
    {
        if(!state_img_loaded_current)
            return;

        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_ProcSteps[STEP_ROI_OPENING]),
                &(vMA_ProcSteps[STEP_ROI_CLOSING]),
                MORPH_OPEN,
                MORPH_RECT,
                ui->spinBox_ProcSet_ROI_Open->value(),
                ui->spinBox_ProcSet_ROI_Open->value(),
                BORDER_DEFAULT,
                1),
            "UpdateImgProc_Step",
            "STEP_ROI_OPENING");
    }
        break;

    case STEP_ROI_AREA:
    {
        if(!state_img_loaded_current)
            return;

        ERR(D_Img_Proc::Feature_Select(
                &(vMA_ProcSteps[STEP_ROI_AREA]),
                &(vMA_ProcSteps[STEP_ROI_OPENING]),
                c_FEAT_AREA,
                ui->spinBox_ProcSet_ROI_Area->value(),
                INFINITY,
                4),
            "UpdateImgProc_Step",
            "STEP_ROI_AREA");
    }
        break;

    case STEP_ROI_DILATION:
    {
        if(!state_img_loaded_current)
            return;

        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_ProcSteps[STEP_ROI_DILATION]),
                &(vMA_ProcSteps[STEP_ROI_AREA]),
                MORPH_DILATE,
                MORPH_RECT,
                ui->spinBox_ProcSet_ROI_Dilate->value(),
                ui->spinBox_ProcSet_ROI_Dilate->value(),
                BORDER_DEFAULT,
                1),
            "UpdateImgProc_Step",
            "STEP_ROI_DILATION");
    }
        break;

    case STEP_ROI_CONVEX_HULL:
    {
        if(!state_img_loaded_current)
            return;

        ERR(D_Img_Proc::Reduce_Geometric(
                &(vMA_ProcSteps[STEP_ROI_CONVEX_HULL]),
                &(vMA_ProcSteps[STEP_ROI_DILATION]),
                c_GEO_CONVEX_HULL,
                8,
                3,
                255),
            "UpdateImgProc_Step",
            "STEP_ROI_CONVEX_HULL");
    }
        break;

    case STEP_OBJECTS_ACCEPTED:
    {
        if(!state_img_loaded_current)
            return;

        Mat MA_tmp_ROI;
        ERR(D_Img_Proc::Fill_Holes(
                &MA_tmp_ROI,
                &(vMA_ProcSteps[STEP_ROI_CONVEX_HULL])),
            "UpdateImgProc_Step",
            "STEP_OBJECTS_ACCEPTED - Fill_Holes");

        ERR(D_Img_Proc::Mask(
                &(vMA_ProcSteps[STEP_OBJECTS_ACCEPTED]),
                &(vMA_ProcSteps[STEP_OBJ_SELECT_ROUNDNESS]),
                &MA_tmp_ROI),
            "UpdateImgProc_Step",
            "STEP_OBJECTS_ACCEPTED - Mask");

        MA_tmp_ROI.release();

        //img proc completed?
        if(ER == ER_okay)
            state_img_proc_up2date_current = true;
    }
        break;

    default:
        break;
    }

    state_stack_analysed = false;
    state_calced_stack = false;
    state_calced_stack_comps = false;
    state_calced_stack_stats = false;
    state_calced_current = false;
    state_calced_current_feats = false;
    state_calced_current_stats = false;
}

bool D_MAKRO_CerebralOrganoids::Calc_Single_All()
{
    state_calced_current = false;

    if(!Calc_Single_Feats())
        return false;

    if(!Calc_Single_Stats())
        return false;

    state_calced_current = true;
    UpdateResults();

    return true;
}

bool D_MAKRO_CerebralOrganoids::Calc_Single_Feats()
{
    state_calced_current_feats = false;
    if(!state_img_proc_up2date_current)
        return false;

    //Components
    D_Component_List CompList;
    int ER = CompList.set_Mat(&(vMA_ProcSteps[STEP_OBJECTS_ACCEPTED]), 8);
    ERR(ER, "Calc_Single_Feats", "CompList.set_Mat");
    if(ER != ER_okay)   return false;

    vvFeatComp_current.clear();
    vvFeatComp_current.resize(FEAT_CUSTOM_NUMBER_OF);
    for(int f = 0; f < FEAT_CUSTOM_NUMBER_OF; f++)
    {
        vvFeatComp_current[f].resize(CompList.size());
        for(int c = 0; c < CompList.size(); c++)
            vvFeatComp_current[f][c] = CompList.get_Feature(c, f);
    }
    for(int c = 0; c < CompList.size(); c++)
        vvFeatComp_current[FEAT_CUSTOM_AREA_MM][c] = px_scale * px_scale * vvFeatComp_current[c_FEAT_AREA][c];

    //save feats in expereiment results data (for stack)
    if(state_stack_processing)
    {
        int time  = ui->comboBox_Data_Time->currentIndex();
        int dose  = ui->comboBox_Data_Dose->currentIndex();
        int flask = ui->comboBox_Data_Flask->currentIndex();
        for(int feat = 0; feat < FEAT_CUSTOM_NUMBER_OF; feat++)
        {
            vvvvvTimeDoseFlaskFeatComp[time][dose][flask][feat].resize(CompList.size());
            for(int comp = 0; comp < CompList.size(); comp++)
                vvvvvTimeDoseFlaskFeatComp[time][dose][flask][feat][comp] = CompList.get_Feature(comp, feat);
        }
        for(int c = 0; c < CompList.size(); c++)
            vvvvvTimeDoseFlaskFeatComp[time][dose][flask][FEAT_CUSTOM_AREA_MM][c] = px_scale * px_scale * vvvvvTimeDoseFlaskFeatComp[time][dose][flask][c_FEAT_AREA][c];
    }

    state_calced_current_feats = true;
    return true;
}

bool D_MAKRO_CerebralOrganoids::Calc_Single_Stats()
{
    state_calced_current_stats = false;
    if(!state_calced_current_feats)
        return false;

    vvFeatStat_current.clear();
    vvFeatStat_current.resize(FEAT_CUSTOM_NUMBER_OF);
    for(int f = 0; f < FEAT_CUSTOM_NUMBER_OF; f++)
        D_Stat::Calc_Stats(
                &(vvFeatStat_current[f]),
                vvFeatComp_current[f],
                true);

    state_calced_current_stats = true;
    return true;
}

void D_MAKRO_CerebralOrganoids::Calc_Stack_All()
{
    Calc_Stack_TD_Comps();
    state_calced_stack_comps = true;
    Calc_Stack_Flask_Stats();
    Calc_Stack_TD_Stats();
    state_calced_stack_stats = true;
    state_calced_stack = true;

    if(state_stack_processing)
        UpdateResults();
}

void D_MAKRO_CerebralOrganoids::Calc_Stack_TD_Comps()
{
    for(int time = 0; time < vvvvvTimeDoseFlaskFeatComp.size(); time++)
    {
        for(int dose = 0; dose < vvvvvTimeDoseFlaskFeatComp[time].size(); dose++)
        {
            //count comps
            size_t comp_td_count = 0;
            for(int flask = 0; flask < vvvvvTimeDoseFlaskFeatComp[time][dose].size(); flask++)
                comp_td_count += vvvvvTimeDoseFlaskFeatComp[time][dose][flask][0].size();

            //loop feats
            for(int feat = 0; feat < FEAT_CUSTOM_NUMBER_OF; feat++)
            {
                //resize feat vectors using comps_count in TD
                vvvvTimeDoseFeatComp[time][dose][feat].resize(comp_td_count);

                //loop comps in flasks and copy feat values
                int comp_td = 0;
                for(int flask = 0; flask < vvvvvTimeDoseFlaskFeatComp[time][dose].size(); flask++)
                    for(int comp_flask = 0; comp_flask < vvvvvTimeDoseFlaskFeatComp[time][dose][flask][feat].size(); comp_flask++)
                    {
                        vvvvTimeDoseFeatComp[time][dose][feat][comp_td] = vvvvvTimeDoseFlaskFeatComp[time][dose][flask][feat][comp_flask];
                        comp_td++;
                    }
            }

            qDebug() << "Calc_Stack_TD_Comps dose: end   :-)";
        }
    }

    qDebug() << "Calc_Stack_TD_Comps all: end   :-) !!!!!!!!";
}

void D_MAKRO_CerebralOrganoids::Calc_Stack_Flask_Stats()
{
    qDebug() << "Calc_Stack_Flask_Stats";

    for(int time = 0; time < vvvvvTimeDoseFlaskFeatComp.size(); time++)
        for(int dose = 0; dose < vvvvvTimeDoseFlaskFeatComp[time].size(); dose++)
            for(int flask = 0; flask < vvvvvTimeDoseFlaskFeatComp[time][dose].size(); flask++)
                for(int feat = 0; feat < FEAT_CUSTOM_NUMBER_OF; feat++)
                    D_Stat::Calc_Stats(
                            &(vvvvvTimeDoseFlaskFeatStat[time][dose][flask][feat]),
                            vvvvvTimeDoseFlaskFeatComp[time][dose][flask][feat],
                            true);
}

void D_MAKRO_CerebralOrganoids::Calc_Stack_TD_Stats()
{
    qDebug() << "Calc_Stack_TD_Stats";

    for(int time = 0; time < vvvvvTimeDoseFlaskFeatComp.size(); time++)
        for(int dose = 0; dose < vvvvvTimeDoseFlaskFeatComp[time].size(); dose++)
                for(int feat = 0; feat < FEAT_CUSTOM_NUMBER_OF; feat++)
                    D_Stat::Calc_Stats(
                            &(vvvvTimeDoseFeatStat[time][dose][feat]),
                            vvvvTimeDoseFeatComp[time][dose][feat],
                            true);
}

void D_MAKRO_CerebralOrganoids::UpdateResults()
{
    if(!state_img_proc_up2date_current || !state_calced_current)
        return;
    //qDebug() << "....................................UpdateResults...start";

    switch (ui->tabWidget_Results->currentIndex()) {

    case RES_VIS:
        UpdateResults_Visualization();
        break;

    case RES_FLASK:
        UpdateResults_Flask();
        break;

    case RES_TD:
        UpdateResults_TD();
        break;

    case RES_EXP:
        UpdateResults_Exp();
        break;

    default:
        break;
    }

    //qDebug() << "....................................UpdateResults...end";
}

void D_MAKRO_CerebralOrganoids::UpdateResults_Visualization()
{
    if(!state_img_proc_up2date_current)
        return;
    //qDebug() << "UpdateResults_Visualization";

    Mat MA_tmp_label;
    ERR(D_Img_Proc::Labeling(
            &MA_tmp_label,
            &(vMA_ProcSteps[STEP_OBJECTS_ACCEPTED]),
            8,
            CV_16U),
        "UpdateResults_Visualization",
        "Labeling");

    Mat MA_tmp_NumbersOnImg;
    ERR(D_Img_Proc::Draw_Label_Numbers_LUT(
            &MA_tmp_NumbersOnImg,
            &(vMA_ProcSteps[STEP_LOAD]),
            &MA_tmp_label,
            vvFeatComp_current[ui->comboBox_VisFeat->currentIndex()],
            true,
            ui->doubleSpinBox_Vis_Scale->value(),
            ui->spinBox_Vis_Thickness->value(),
            true,
            ui->spinBox_Vis_Precision->value(),
            0,
            0,
            255),
        "UpdateResults_Visualization",
        "Draw_Label_Numbers_LUT - Feat");


    Mat MA_tmp_ConvexHullColor;
    ERR(D_Img_Proc::Convert_Color_RGBA(
            &MA_tmp_ConvexHullColor,
            &(vMA_ProcSteps[STEP_ROI_CONVEX_HULL]),
            0,
            255,
            0,
            255),
        "UpdateResults_Visualization",
        "Convert_Color_RGBA");

    ERR(D_Img_Proc::Math_Add(
            &MA_Vis,
            &MA_tmp_ConvexHullColor,
            &MA_tmp_NumbersOnImg),
        "UpdateResults_Visualization",
        "Convert_Color");

    MA_tmp_label.release();
    MA_tmp_NumbersOnImg.release();
    MA_tmp_ConvexHullColor.release();
    UpdateImage_Vis();
}

void D_MAKRO_CerebralOrganoids::UpdateResults_Flask()
{
    if(!state_img_proc_up2date_current || !state_calced_current)
        return;
    //qDebug() << "UpdateResults_Flask";

    switch (ui->comboBox_ResFlask_Mode->currentIndex()) {

    case RES_TYPE_FLASK_COMP:
        UpdateTable_Flask_Comp();
        break;

    case RES_TYPE_FLASK_STAT:
        UpdateTable_Flask_Stat();
        break;

    default:
        break;
    }
}

void D_MAKRO_CerebralOrganoids::UpdateResults_TD()
{
    if(!state_img_proc_up2date_current || !state_calced_current)
        return;
    //qDebug() << "UpdateResults_TD";

    switch (ui->comboBox_ResTD_Mode->currentIndex()) {

    case RES_TYPE_TD_COMP:
        UpdateTable_TD_Comp();
        break;

    case RES_TYPE_TD_STAT:
        UpdateTable_TD_Stat();
        break;

    default:
        break;
    }
}

void D_MAKRO_CerebralOrganoids::UpdateResults_Exp()
{
    if(!state_stack_analysed || !state_calced_stack)
        return;
    //qDebug() << "UpdateResults_Exp";

    switch (ui->comboBox_ResExp_Mode->currentIndex()) {

    case RES_TYPE_EXP_STATS_LINE:
        UpdatePlot_Exp_Stat_Line();
        break;

    case RES_TYPE_EXP_STATS_LINE_ERR:
        UpdatePlot_Exp_Stat_Line_Errors();
        break;

    default:
        break;
    }
}

void D_MAKRO_CerebralOrganoids::UpdateTable_Flask_Comp()
{
    if(!state_img_proc_up2date_current || !state_calced_current_feats)
        return;
    //qDebug() << "UpdateTable_Flask_Comp";

    int t = ui->comboBox_Data_Time->currentIndex();
    int d = ui->comboBox_Data_Dose->currentIndex();
    int f = ui->comboBox_Data_Flask->currentIndex();

    Table_Flask.set_data_d_2D_qsl_count(
                vvvvvTimeDoseFlaskFeatComp[t][d][f],
                QSL_FeatAll);
}

void D_MAKRO_CerebralOrganoids::UpdateTable_Flask_Stat()
{
    if(!state_img_proc_up2date_current || !state_calced_current_stats)
        return;
    //qDebug() << "UpdateTable_Flask_Stat";

    int t = ui->comboBox_Data_Time->currentIndex();
    int d = ui->comboBox_Data_Dose->currentIndex();
    int f = ui->comboBox_Data_Flask->currentIndex();

    Table_Flask.set_data_d_2D_qsl_qsl(
                vvvvvTimeDoseFlaskFeatStat[t][d][f],
                QSL_FeatAll,
                QSL_StatList);
}

void D_MAKRO_CerebralOrganoids::UpdateTable_TD_Comp()
{
    if(!state_img_proc_up2date_current || !state_calced_current_feats)
        return;
    //qDebug() << "UpdateTable_TD_Comp";

    int t = ui->comboBox_Data_Time->currentIndex();
    int d = ui->comboBox_Data_Dose->currentIndex();

    Table_TD.set_data_d_2D_qsl_count(
                vvvvTimeDoseFeatComp[t][d],
                QSL_FeatAll);
}

void D_MAKRO_CerebralOrganoids::UpdateTable_TD_Stat()
{
    if(!state_img_proc_up2date_current || !state_calced_current_stats)
        return;
    //qDebug() << "UpdateTable_TD_Stat";

    int t = ui->comboBox_Data_Time->currentIndex();
    int d = ui->comboBox_Data_Dose->currentIndex();

    Table_TD.set_data_d_2D_qsl_qsl(
                vvvvTimeDoseFeatStat[t][d],
                QSL_FeatAll,
                QSL_StatList);
}

void D_MAKRO_CerebralOrganoids::UpdatePlot_Exp_Stat_Line()
{
    if(!state_calced_stack || !state_stack_analysed)
        return;

    int feat        = ui->comboBox_ResExp_Feat->currentIndex();
    int stat_line   = ui->comboBox_ResExp_Stat_Line->currentIndex();

    //existing doses
    vector<double> vDoses;
    for(int t = 0; t < vvvvTimeDoseFeatStat.size(); t++)
        for(int d = 0; d < vvvvTimeDoseFeatStat[t].size(); d++)
        {
            double dose = vvVAL_Dose[t][d];
            bool d_contained = false;
            for(int dc = 0; dc < vDoses.size(); dc++)
                if(dose == vDoses[dc])
                    d_contained = true;

            if(!d_contained)
                vDoses.push_back(dose);
        }

    //sort doses & names of doses
    sort(vDoses.begin(), vDoses.end());
    QStringList QSL_Doses;
    for(int d = 0; d < vDoses.size(); d++)
        QSL_Doses.append(QString::number(vDoses[d]) + "Gy");


    //Data
    vector<vector<double>> vvX_Time(vDoses.size());
    vector<vector<double>> vvY_Feat(vDoses.size());

    //get data
    for(int t = 0; t < vvvvTimeDoseFeatStat.size(); t++)
        for(int d = 0; d < vvvvTimeDoseFeatStat[t].size(); d++)
        {
            //time
            double time_val = vVAL_Times[t];

            //dose
            double dose_val = vvVAL_Dose[t][d];
            int dose_idx = 0;
            for(int dc = 0; dc < vDoses.size(); dc++)
               if(dose_val == vDoses[dc])
                   dose_idx = dc;

            //data point
            vvX_Time[dose_idx].push_back(time_val);
            vvY_Feat[dose_idx].push_back(vvvvTimeDoseFeatStat[t][d][feat][stat_line]);
        }

    //plot
    D_Plot::Plot_Line_XY_Multi(
                pChartView,
                vvX_Time,
                vvY_Feat,
                QSL_StatList[stat_line] + " of " + QSL_FeatAll[feat] + " of Cerebral Organoids",
                QSL_Doses,
                "Time/days",
                QSL_FeatAll[feat],
                false,
                false);

    //start at day0
    pChartView->chart()->axisX()->setMin(0);
}

void D_MAKRO_CerebralOrganoids::UpdatePlot_Exp_Stat_Line_Errors()
{
    if(!state_calced_stack || !state_stack_analysed)
        return;

    int feat        = ui->comboBox_ResExp_Feat->currentIndex();
    int stat_line   = ui->comboBox_ResExp_Stat_Line->currentIndex();
    int stat_errors = ui->comboBox_ResExp_Stat_Errors->currentIndex();

    //existing doses
    vector<double> vDoses;
    for(int t = 0; t < vvvvTimeDoseFeatStat.size(); t++)
        for(int d = 0; d < vvvvTimeDoseFeatStat[t].size(); d++)
        {
            double dose = vvVAL_Dose[t][d];
            bool d_contained = false;
            for(int dc = 0; dc < vDoses.size(); dc++)
                if(dose == vDoses[dc])
                    d_contained = true;

            if(!d_contained)
                vDoses.push_back(dose);
        }

    //sort doses & names of doses
    sort(vDoses.begin(), vDoses.end());
    QStringList QSL_Doses;
    for(int d = 0; d < vDoses.size(); d++)
        QSL_Doses.append(QString::number(vDoses[d]) + "Gy");


    //Data
    vector<vector<double>> vvX_Time(vDoses.size());
    vector<vector<double>> vvY_Feat_Val(vDoses.size());
    vector<vector<double>> vvY_Feat_Err(vDoses.size());

    //get data
    for(int t = 0; t < vvvvTimeDoseFeatStat.size(); t++)
        for(int d = 0; d < vvvvTimeDoseFeatStat[t].size(); d++)
        {
            //time
            double time_val = vVAL_Times[t];

            //dose
            double dose_val = vvVAL_Dose[t][d];
            int dose_idx = 0;
            for(int dc = 0; dc < vDoses.size(); dc++)
               if(dose_val == vDoses[dc])
                   dose_idx = dc;

            //data point
            vvX_Time[dose_idx].push_back(time_val);
            vvY_Feat_Val[dose_idx].push_back(vvvvTimeDoseFeatStat[t][d][feat][stat_line]);
            vvY_Feat_Err[dose_idx].push_back(vvvvTimeDoseFeatStat[t][d][feat][stat_errors]);
        }

    //plot
    D_Plot::Plot_Line_XY_Multi(
                pChartView,
                vvX_Time,
                vvY_Feat_Val,
                vvY_Feat_Err,
                QSL_StatList[stat_line] + " of " + QSL_FeatAll[feat] + " of Cerebral Organoids (+/- " + QSL_StatList[stat_errors] + " )",
                QSL_Doses,
                "Time/days",
                QSL_FeatAll[feat],
                false,
                false);

    //start at day0
    pChartView->chart()->axisX()->setMin(0);
}

void D_MAKRO_CerebralOrganoids::Save_Image(D_Viewer *pViewer, QString name_default)
{
    QString name_save;

    if(state_stack_processing)
        name_save = pViewer->Save_Image(name_default);
    else
        name_save = pViewer->Save_Image_Dialog(name_default);

    if(!name_save.isEmpty() && !state_stack_processing)
        pStore->set_dir_M_CerebralOrganoids(name_save);
}

void D_MAKRO_CerebralOrganoids::Save_Plot(QChartView *pCV_Save, QString name_default)
{
    QString name_save;

    if(state_stack_processing)
        name_save = name_default;
    else
        name_save = QFileDialog::getSaveFileName(this,
                                                 tr("Save plot as image"),
                                                 name_default,
                                                 tr("Images (*.png *.bmp *.tif)"));
    if(name_save.isEmpty())
        return;

    if(!name_save.isEmpty() && !state_stack_processing)
        pStore->set_dir_M_CerebralOrganoids(name_save);

    QPixmap pixmap_save = pCV_Save->grab();
    pixmap_save.save(name_save, 0, -1);
}

void D_MAKRO_CerebralOrganoids::Save_Table(D_Table *pTable, QString name_default)
{
    QString name_save;

    if(state_stack_processing)
        name_save = pTable->Save_Table(name_default);
    else
        name_save = pTable->Save_Table_Dialog(name_default);

    if(!name_save.isEmpty() && !state_stack_processing)
        pStore->set_dir_M_CerebralOrganoids(name_save);
}

void D_MAKRO_CerebralOrganoids::Save_Image_Processing()
{
    Save_Image(
                &ViewProc,
                pStore->dir_M_CerebralOrganoids()->path());
}

void D_MAKRO_CerebralOrganoids::Save_Image_Visualization()
{
    Save_Image(
                &ViewRes,
                pStore->dir_M_CerebralOrganoids()->path());
}

void D_MAKRO_CerebralOrganoids::Save_Table_Flask()
{
    Save_Table(
                &Table_Flask,
                pStore->dir_M_CerebralOrganoids()->path());
}

void D_MAKRO_CerebralOrganoids::Save_Table_TD()
{
    Save_Table(
                &Table_TD,
                pStore->dir_M_CerebralOrganoids()->path());
}

void D_MAKRO_CerebralOrganoids::Save_Plot_Experiment()
{
    Save_Plot(
                pChartView,
                pStore->dir_M_CerebralOrganoids()->path());
}

bool D_MAKRO_CerebralOrganoids::Save_Analysis_DoAgainQuestion()
{
    if(!state_stack_analysed)
        return true;

    if(QMessageBox::question(
                this,
                "Analysis still updated",
                "The analysis is updated. Nothing changed. Do you want to update it again just to watch the fancy image flow?")
            != QMessageBox::Yes)
        return false;

    qDebug() << this->styleSheet();
    ui->graphicsView_Proc->setStyleSheet("background-color : #ffdae0;");
    ui->graphicsView_Vis->setStyleSheet("background-color : #ffdae0;");
    state_stack_analysed = false;
    return true;
}

void D_MAKRO_CerebralOrganoids::Save_Analysis()
{
    if(!state_exp_loaded)
        return;
    state_stack_processing = true;

    //Parameters:::::::::::::::::::::::::::::::::::::::
    ui->groupBox_ProcSet->grab().save(DIR_Save_Main.path() + "/Parameters.png", 0, -1);

    //Plots:::::::::::::::::::::::::::::::::::::::
    qDebug() << "Save_Analysis" << "Save Plots ::::::::::::::::::::::::::";

    ui->tabWidget_Results->setCurrentIndex(RES_EXP);
    ui->comboBox_ResExp_Mode->setCurrentIndex(RES_TYPE_EXP_STATS_LINE_ERR);
    for(size_t feat = 0; feat < vFeatsOfInterest.size(); feat++)
    {
        ui->comboBox_ResExp_Feat->blockSignals(true);
        ui->comboBox_ResExp_Feat->setCurrentIndex(vFeatsOfInterest[feat]);
        ui->comboBox_ResExp_Feat->blockSignals(false);

        for(size_t stat_val = 0; stat_val < vStatsOfInterest_Line.size(); stat_val++)
        {
            ui->comboBox_ResExp_Stat_Line->blockSignals(true);
            ui->comboBox_ResExp_Stat_Line->setCurrentIndex(vStatsOfInterest_Line[stat_val]);
            ui->comboBox_ResExp_Stat_Line->blockSignals(false);

            for(size_t stat_err = 0; stat_err < vStatsOfInterest_Errors.size(); stat_err++)
            {
                ui->comboBox_ResExp_Stat_Errors->blockSignals(true);
                ui->comboBox_ResExp_Stat_Errors->setCurrentIndex(vStatsOfInterest_Errors[stat_err]);
                ui->comboBox_ResExp_Stat_Errors->blockSignals(false);

                UpdateResults();
                UpdateUi();
                Save_Plot(
                            pChartView,
                            DIR_Save_Plots.path() +
                            "/" + QS_ExpName +
                            "_" + QSL_FeatAll[vFeatsOfInterest[feat]] +
                            "_" + QSL_StatList[vStatsOfInterest_Line[stat_val]] +
                            "_" + QSL_StatList[vStatsOfInterest_Errors[stat_err]] +
                            ".png");
            }
        }
    }


    //Tables::::::::::::::::::::::::::
    qDebug() << "Save_Analysis" << "Save Tables ::::::::::::::::::::::::::";

    //open streams
    OS_comps.open((DIR_Save_Tables.path() + "/Components.csv").toStdString());
    vvOS_stats.resize(vFeatsOfInterest.size());
    for(size_t feat = 0; feat < vFeatsOfInterest.size(); feat++)
    {
        vvOS_stats[feat].resize(vStatsOfInterest_All.size());
        for(size_t stat = 0; stat < vStatsOfInterest_All.size(); stat++)
        {
            QString QS_path = DIR_Save_Tables.path() + "/Statistics - " + QSL_FeatAll[vFeatsOfInterest[feat]] + " - " + QSL_StatList[vStatsOfInterest_All[stat]] + ".csv";
            vvOS_stats[feat][stat].open(QS_path.toStdString());
        }
    }

    //comps stream......................
    qDebug() << "Save_Analysis" << "comps stream start";

    //header
    OS_comps << QDateTime::currentDateTime().toString().toStdString() << "\n";
    OS_comps << "\n\n";

    //capitals
    OS_comps << "time/d," << "dose/Gy," << "flask/number," << "coresponding image name," << "component/number,";
    for(size_t feat = 0; feat < vFeatsOfInterest.size(); feat++)
        OS_comps << "," << QSL_FeatAll[vFeatsOfInterest[feat]].toStdString();

    //data
    for(size_t time = 0; time < vvvvvTimeDoseFlaskFeatComp.size(); time++)
        for(size_t dose = 0; dose < vvvvvTimeDoseFlaskFeatComp[time].size(); dose++)
        {
            OS_comps << "\n";
            for(size_t flask = 0; flask < vvvvvTimeDoseFlaskFeatComp[time][dose].size(); flask++)
                for(size_t comp = 0; comp < vvvvvTimeDoseFlaskFeatComp[time][dose][flask][0].size(); comp++)
                {
                    OS_comps << "\n"
                             << vVAL_Times[time] << ","
                             << vvVAL_Dose[time][dose] << ","
                             << flask << ","
                             << vvvFI_Flask[time][dose][flask].baseName().toStdString() << ","
                             << comp << ",";

                    for(size_t feat = 0; feat < vFeatsOfInterest.size(); feat++)
                        OS_comps << "," << vvvvvTimeDoseFlaskFeatComp[time][dose][flask][vFeatsOfInterest[feat]][comp];
                }
        }

    //stats stream..........................
    qDebug() << "Save_Analysis" << "stats stream" << "start";

    //init
    qDebug() << "Save_Analysis" << "stats stream" << "headers/capitals";
    for(size_t feat = 0; feat < vFeatsOfInterest.size(); feat++)
        for(size_t stat = 0; stat < vStatsOfInterest_All.size(); stat++)
        {
            //header
            vvOS_stats[feat][stat] << QDateTime::currentDateTime().toString().toStdString() << "\n";
            vvOS_stats[feat][stat] << "\n\n";
            vvOS_stats[feat][stat] << QSL_FeatAll[vFeatsOfInterest[feat]].toStdString() << "\n";
            vvOS_stats[feat][stat] << QSL_StatList[vStatsOfInterest_All[stat]].toStdString() << "\n\n" ;

            //capitals
            vvOS_stats[feat][stat] << "," << "time/d";
            for(size_t time = 0; time < vVAL_Times.size(); time++)
                vvOS_stats[feat][stat] << "," << vVAL_Times[time];
            vvOS_stats[feat][stat] << "\n";
            vvOS_stats[feat][stat] << "dose/Gy" << "\n";
        }

    //existing doses
    qDebug() << "Save_Analysis" << "stats stream" << "get existing doses";
    vector<double> vDoses;
    for(size_t t = 0; t < vvvvTimeDoseFeatStat.size(); t++)
        for(size_t d = 0; d < vvvvTimeDoseFeatStat[t].size(); d++)
        {
            double dose = vvVAL_Dose[t][d];
            bool d_contained = false;
            for(size_t dc = 0; dc < vDoses.size(); dc++)
                if(dose == vDoses[dc])
                    d_contained = true;

            if(!d_contained)
                vDoses.push_back(dose);
        }
    sort(vDoses.begin(), vDoses.end());

    //data
    qDebug() << "Save_Analysis" << "stats stream" << "data";
    for(size_t d = 0; d < vDoses.size(); d++)
    {
        qDebug() << "Save_Analysis" << "stats stream" << "dose" << d;

        //expected dose
        double dose_expected = vDoses[d];

        //1st column: dose value
        for(size_t feat = 0; feat < vFeatsOfInterest.size(); feat++)
            for(size_t stat = 0; stat < vStatsOfInterest_All.size(); stat++)
                    vvOS_stats[feat][stat] << "\n" << vDoses[d] << ",";

        for(size_t t = 0; t < vVAL_Times.size(); t++)
        {
            //dose existis at this time?
            bool td_exists = false;
            size_t d_index = 0;
            for(size_t d_index_search = 0; d_index_search < vvVAL_Dose[t].size(); d_index_search++)
            {
                if(dose_expected == vvVAL_Dose[t][d_index_search])
                {
                    td_exists = true;
                    d_index = d_index_search;
                    //d_index_search = vvVAL_Dose[t].size();
                }
            }

            //stream
            qDebug() << "Save_Analysis" << "stats stream" << "dose" << d << "time" << t << "stream";
            for(size_t feat = 0; feat < vFeatsOfInterest.size(); feat++)
                for(size_t stat = 0; stat < vStatsOfInterest_All.size(); stat++)
                {
                    if(td_exists)
                        vvOS_stats[feat][stat] << "," << vvvvTimeDoseFeatStat[t][d_index][vFeatsOfInterest[feat]][vStatsOfInterest_All[stat]];
                    else
                        vvOS_stats[feat][stat] << ",";
                }
        }
    }


    //close streams........................
    qDebug() << "Save_Analysis" << "streams close";
    OS_comps.close();
    for(size_t feat = 0; feat < vFeatsOfInterest.size(); feat++)
        for(size_t stat = 0; stat < vStatsOfInterest_All.size(); stat++)
            vvOS_stats[feat][stat].close();

    state_stack_processing = false;
}

void D_MAKRO_CerebralOrganoids::Save_Analysis_Save()
{
    if(!state_exp_loaded)
        return;
    if(!Save_Analysis_DoAgainQuestion())
        return;

    //..........................................

    //path
    QString save_path = QFileDialog::getExistingDirectory(
                this,
                "Select folder to stream the output to.",
                pStore->dir_M_CerebralOrganoids()->path());

    if(save_path == 0)
        return;

    //create subfolder for output
    unsigned int count = 0;
    QString QS_Folder_Out_Sub = save_path + "/Results_0";
    while(QDir(QS_Folder_Out_Sub).exists())
    {
        count++;
        QS_Folder_Out_Sub = save_path + "/Results_" + QString::number(count);
    }
    DIR_Save_Main.setPath(QS_Folder_Out_Sub);
    QDir().mkdir(DIR_Save_Main.path());
    DIR_Save_Images.setPath(QS_Folder_Out_Sub + "/Images");
    QDir().mkdir(DIR_Save_Images.path());
    DIR_Save_Tables.setPath(QS_Folder_Out_Sub + "/Tables");
    QDir().mkdir(DIR_Save_Tables.path());
    DIR_Save_Plots.setPath(QS_Folder_Out_Sub + "/Plots");
    QDir().mkdir(DIR_Save_Plots.path());

    //..........................................

    //Feats of interest
    D_Popup_ListEdit pop_feat(
                "Select features of interest to save",
                &vFeatsOfInterest,
                QSL_FeatAll,
                FEAT_CUSTOM_AREA_MM,
                this);
    pop_feat.exec();

    //Stats of interest (line)
    D_Popup_ListEdit pop_stat_line(
                "Select stats of interest: Plot (Line Values)",
                &vStatsOfInterest_Line,
                QSL_StatList,
                c_STAT_MEAN_ARITMETIC,
                this);
    pop_stat_line.exec();

    //Stats of interest (errors)
    D_Popup_ListEdit pop_stat_errors(
                "Select stats of interest: Plot (Error Values)",
                &vStatsOfInterest_Errors,
                QSL_StatList,
                c_STAT_SEM_ABS_TOTAL,
                this);
    pop_stat_errors.exec();

    //Stats of interest (all)
    vStatsOfInterest_All = vStatsOfInterest_Line;
    for(int se = 0; se < vStatsOfInterest_Errors.size(); se++)
    {
        bool allready_contained = false;
        for(size_t sl = 0; sl < vStatsOfInterest_Line.size(); sl++)
            if(vStatsOfInterest_Errors[se] == vStatsOfInterest_Line[sl])
            {
                allready_contained = true;
                sl = vStatsOfInterest_Line.size();
            }

        if(!allready_contained)
            vStatsOfInterest_All.push_back(vStatsOfInterest_Errors[se]);
    }

    //..........................................

    //Update & Save
    UpdateProc_Stack();
    Save_Analysis();
}

void D_MAKRO_CerebralOrganoids::Save_Analysis_Update()
{
    if(!state_exp_loaded)
        return;
    if(!Save_Analysis_DoAgainQuestion())
        return;

    if(QMessageBox::question(
                this,
                "Save Analysis?",
                "You triggered an update of the stack of images. Do you want to save the results afterwards?"
                "<br>"
                "<br>Yes: Update and saving is performed."
                "<br>"
                "<br>No: Only Update is performed. You are able to save the results manually afterwards.")
            == QMessageBox::Yes)
        Save_Analysis_Save();
    else
        UpdateProc_Stack();
}

void D_MAKRO_CerebralOrganoids::Update_SettingsMM()
{
    //get
    px_scale = ui->doubleSpinBox_ProcSet_PixelSize->value();

    //set
    ui->label_ProcSet_Area->setText(
                "Select (" +
                QString::number(ui->doubleSpinBox_ProcSet_SelectArea_Min->value() * px_scale * px_scale, 'g', 3) +
                " to " +
                QString::number(ui->doubleSpinBox_ProcSet_SelectArea_Max->value() * px_scale * px_scale, 'g', 3) +
                ")mm²");
    ui->label_ProcSet_Close->setText(
                "Remove black noise, connect " +
                QString::number(ui->spinBox_ProcSet_ClosingSize->value() * px_scale) +
                "mm");
    ui->label_ProcSet_Open->setText(
                "Remove white noise, separate " +
                QString::number(ui->spinBox_ProcSet_OpeningSize->value() * px_scale) +
                "mm");
}


//============================================= User Interafce Triggers =============================================


void D_MAKRO_CerebralOrganoids::on_comboBox_Data_Time_currentIndexChanged(int index)
{
    ui->comboBox_Data_Dose->blockSignals(true);
    ui->comboBox_Data_Flask->blockSignals(true);

    Populate_CB_Single(
                ui->comboBox_Data_Dose,
                vQSL_Dose[index],
                0);
    Populate_CB_Single(
                ui->comboBox_Data_Flask,
                vvQSL_Flask[index][ui->comboBox_Data_Dose->currentIndex()],
                0);

    ui->comboBox_Data_Dose->blockSignals(false);
    ui->comboBox_Data_Flask->blockSignals(false);
    if(!state_stack_processing)
        UpdateImgProc(0);
}

void D_MAKRO_CerebralOrganoids::on_comboBox_Data_Dose_currentIndexChanged(int index)
{
    ui->comboBox_Data_Flask->blockSignals(true);

    Populate_CB_Single(
                ui->comboBox_Data_Flask,
                vvQSL_Flask[ui->comboBox_Data_Time->currentIndex()][index],
                0);

    ui->comboBox_Data_Flask->blockSignals(false);
    if(!state_stack_processing)
        UpdateImgProc(0);
}

void D_MAKRO_CerebralOrganoids::on_comboBox_Data_Flask_currentIndexChanged(int index)
{
    index;
    if(!state_stack_processing)
        UpdateImgProc(0);
}

void D_MAKRO_CerebralOrganoids::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_MAKRO_CerebralOrganoids", func, detail);
}

void D_MAKRO_CerebralOrganoids::on_doubleSpinBox_ProcSet_PixelSize_valueChanged(double arg1)
{
    arg1;
    Update_SettingsMM();
    UpdateImgProc(STEP_OBJ_SELECT_AREA);
}

void D_MAKRO_CerebralOrganoids::on_spinBox_ProcSet_BlurSize_valueChanged(int arg1)
{
    arg1;
    UpdateImgProc(STEP_BLUR);
}

void D_MAKRO_CerebralOrganoids::on_doubleSpinBox_ProcSet_BlurSigma_valueChanged(double arg1)
{
    arg1;
    UpdateImgProc(STEP_BLUR);
}

void D_MAKRO_CerebralOrganoids::on_spinBox_ProcSet_ColorSelect_H_Min_valueChanged(int arg1)
{
    arg1;
    UpdateImgProc(STEP_COLOR_GRAB);
}

void D_MAKRO_CerebralOrganoids::on_spinBox_ProcSet_ColorSelect_H_Max_valueChanged(int arg1)
{
    arg1;
    UpdateImgProc(STEP_COLOR_GRAB);
}

void D_MAKRO_CerebralOrganoids::on_spinBox_ProcSet_ColorSelect_S_Min_valueChanged(int arg1)
{
    arg1;
    UpdateImgProc(STEP_COLOR_GRAB);
}

void D_MAKRO_CerebralOrganoids::on_spinBox_ProcSet_ColorSelect_S_Max_valueChanged(int arg1)
{
    arg1;
    UpdateImgProc(STEP_COLOR_GRAB);
}

void D_MAKRO_CerebralOrganoids::on_spinBox_ProcSet_ColorSelect_V_Min_valueChanged(int arg1)
{
    arg1;
    UpdateImgProc(STEP_COLOR_GRAB);
}

void D_MAKRO_CerebralOrganoids::on_spinBox_ProcSet_ColorSelect_V_Max_valueChanged(int arg1)
{
    arg1;
    UpdateImgProc(STEP_COLOR_GRAB);
}

void D_MAKRO_CerebralOrganoids::on_spinBox_ProcSet_ClosingSize_valueChanged(int arg1)
{
    arg1;
    Update_SettingsMM();
    UpdateImgProc(STEP_OBJ_CLOSING);
}

void D_MAKRO_CerebralOrganoids::on_spinBox_ProcSet_OpeningSize_valueChanged(int arg1)
{
    arg1;
    Update_SettingsMM();
    UpdateImgProc(STEP_OBJ_OPENING);
}

void D_MAKRO_CerebralOrganoids::on_doubleSpinBox_ProcSet_SelectArea_Min_valueChanged(double arg1)
{
    arg1;
    Update_SettingsMM();
    UpdateImgProc(STEP_OBJ_SELECT_AREA);
}

void D_MAKRO_CerebralOrganoids::on_doubleSpinBox_ProcSet_SelectArea_Max_valueChanged(double arg1)
{
    arg1;
    Update_SettingsMM();
    UpdateImgProc(STEP_OBJ_SELECT_AREA);
}

void D_MAKRO_CerebralOrganoids::on_doubleSpinBox_ProcSet_SelectRoundness_Min_valueChanged(double arg1)
{
    arg1;
    UpdateImgProc(STEP_OBJ_SELECT_ROUNDNESS);
}

void D_MAKRO_CerebralOrganoids::on_doubleSpinBox_ProcSet_SelectRoundness_Max_valueChanged(double arg1)
{
    arg1;
    UpdateImgProc(STEP_OBJ_SELECT_ROUNDNESS);
}

void D_MAKRO_CerebralOrganoids::on_doubleSpinBox_ProcSet_Thresh_valueChanged(double arg1)
{
    arg1;
    UpdateImgProc(STEP_ROI_THRES);
}

void D_MAKRO_CerebralOrganoids::on_spinBox_ProcSet_ROI_Close_valueChanged(int arg1)
{
    arg1;
    UpdateImgProc(STEP_ROI_CLOSING);
}

void D_MAKRO_CerebralOrganoids::on_spinBox_ProcSet_ROI_Open_valueChanged(int arg1)
{
    arg1;
    UpdateImgProc(STEP_ROI_OPENING);
}

void D_MAKRO_CerebralOrganoids::on_spinBox_ProcSet_ROI_Area_valueChanged(int arg1)
{
    arg1;
    UpdateImgProc(STEP_ROI_AREA);
}

void D_MAKRO_CerebralOrganoids::on_spinBox_ProcSet_ROI_Dilate_valueChanged(int arg1)
{
    arg1;
    UpdateImgProc(STEP_ROI_DILATION);
}

void D_MAKRO_CerebralOrganoids::on_tabWidget_Results_currentChanged(int index)
{
    index;
    UpdateResults();
}

void D_MAKRO_CerebralOrganoids::on_comboBox_ResFlask_Mode_currentIndexChanged(int index)
{
    index;
    UpdateResults();
}

void D_MAKRO_CerebralOrganoids::on_comboBox_ResTD_Mode_currentIndexChanged(int index)
{
    index;
    UpdateResults();
}

void D_MAKRO_CerebralOrganoids::on_comboBox_ResExp_Mode_currentIndexChanged(int index)
{
    index;
    UpdateResults();
}


