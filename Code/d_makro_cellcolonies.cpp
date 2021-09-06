/************************************
 *   added:     20.11.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_makro_cellcolonies.h"
#include "ui_d_makro_cellcolonies.h"

D_MAKRO_CellColonies::D_MAKRO_CellColonies(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_CellColonies)
{
    ui->setupUi(this);

    //get storage
    pStore = pStorage;

    vMA_Cells.resize(c_CELLS_STEPS);
    for(unsigned int i = 0; i < vMA_Cells.size(); i++)
        vMA_Cells[i] = pStore->get_Adress(0)->clone();

    vMA_Results.resize(c_RESULTS_STEPS);
    for(unsigned int i = 0; i < vMA_Results.size(); i++)
        vMA_Results[i] = pStore->get_Adress(0)->clone();

    MA_Reference = pStore->get_Adress(0)->clone();
    MA_Result_Color = pStore->get_Adress(0)->clone();
    MA_Result_Surrival = pStore->get_Adress(0)->clone();
    MA_Result_Segmentation = pStore->get_Adress(0)->clone();

    //viewer
    Viewer_Cells.set_GV(ui->graphicsView_Cells);
    Viewer_Results.set_GV(ui->graphicsView_ResImg);
    Viewer_Surrival.set_GV(ui->graphicsView_Surrival);
    Viewer_Segmentation.set_GV(ui->graphicsView_Segmentation);
    Viewer_Attribute.set_GV(ui->graphicsView_Attribute);
    ui->comboBox_ProcView_Step->setCurrentIndex(c_ST_INPUT_CROP);
    ui->comboBox_ResImg_Binary->setCurrentIndex(c_ST_B_EDGES_NUMBERS - 7);

    Viewer_Cells.connect_Zoom(&Viewer_Results);
    Viewer_Cells.connect_Zoom(&Viewer_Surrival);
    Viewer_Cells.connect_Zoom(&Viewer_Segmentation);
    Viewer_Cells.connect_Zoom(&Viewer_Attribute);

    //plot
    Init_Plot();
    Populate_CB_Stat();
    Populate_CB_Attribute();
    Populate_CB_Typ();

    //Statusbar
    L_SB_ValAtPos = new QLabel(this);
    //L_SB_ValAtPos->setFixedWidth();
    L_SB_ValAtPos->setToolTip("Value at Mouse Position.");
    ui->statusbar->addPermanentWidget(L_SB_ValAtPos);

    //CONNECT
    //settings
    connect(ui->action_SettingsReset,                   SIGNAL(triggered(bool)),                    this,                   SLOT(Settings_Reset()));
    //load
    connect(ui->comboBox_ProcView_Image,                SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_ImgProc()));
    connect(ui->action_Load_Images,                     SIGNAL(triggered(bool)),                    this,                   SLOT(Load_Images()));
    //save
    connect(ui->action_Save_whole_Analysis,             SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Analysis_Dialog()));
    connect(ui->action_Analyze_Stack,                   SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Stack()));
    connect(ui->action_Save_Image_Cells,                SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Image_Cells()));
    connect(ui->action_Save_Image_Color,                SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Image_Results_Color()));
    connect(ui->action_Save_Image_Segmentation,         SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Image_Results_Segmentation()));
    connect(ui->action_Save_Image_Surrival,             SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Image_Results_Surrival()));
    connect(ui->action_Save_Image_Attribute,            SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Image_Results_Attribute()));
    connect(ui->action_Save_Plot_Colony_in_Image,       SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Plot_Colony()));
    connect(ui->action_Save_Plot_Surrival,              SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Plot_Image()));
    connect(ui->action_Save_Plot_Value_in_Colony,       SIGNAL(triggered(bool)),                    this,                   SLOT(Save_Plot_Surrival()));
    //View
    connect(ui->comboBox_ProcView_Step,                 SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Image_Cells()));
    connect(ui->comboBox_ResImg_Color,                  SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Image_Results()));
    connect(ui->comboBox_ResImg_Binary,                 SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Image_Results()));
    //Viewer Cells
    connect(&Viewer_Cells,                              SIGNAL(MouseMoved_Value(QString)),          L_SB_ValAtPos,          SLOT(setText(QString)));
    connect(&Viewer_Cells,                              SIGNAL(TypeChanged_MA(QString)),            ui->label_ProcView_MA,  SLOT(setText(QString)));
    connect(&Viewer_Cells,                              SIGNAL(TypeChanged_QI(QString)),            ui->label_ProcView_QI,  SLOT(setText(QString)));
    connect(ui->action_Smooth_Transformation,           SIGNAL(triggered(bool)),                    &Viewer_Cells,          SLOT(Set_Transformation_Mode(bool)));
    connect(ui->action_Keep_Aspect_Ratio,               SIGNAL(triggered(bool)),                    &Viewer_Cells,          SLOT(Set_Aspect_Mode(bool)));
    //Viewer Results
    connect(&Viewer_Results,                            SIGNAL(MouseMoved_Value(QString)),          L_SB_ValAtPos,          SLOT(setText(QString)));
    connect(&Viewer_Results,                            SIGNAL(TypeChanged_MA(QString)),            ui->label_ProcView_MA,  SLOT(setText(QString)));
    connect(&Viewer_Results,                            SIGNAL(TypeChanged_QI(QString)),            ui->label_ProcView_QI,  SLOT(setText(QString)));
    connect(ui->action_Smooth_Transformation,           SIGNAL(triggered(bool)),                    &Viewer_Results,        SLOT(Set_Transformation_Mode(bool)));
    connect(ui->action_Keep_Aspect_Ratio,               SIGNAL(triggered(bool)),                    &Viewer_Results,        SLOT(Set_Aspect_Mode(bool)));
    //Update
    connect(ui->action_Update_View,                     SIGNAL(triggered(bool)),                    this,                   SLOT(Update_Views()));
    connect(ui->action_Update_ImgProc,                  SIGNAL(triggered(bool)),                    this,                   SLOT(Update_ImgProc()));
    connect(ui->tabWidget_Res,                          SIGNAL(currentChanged(int)),                this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_PlotType,                  SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->spinBox_ResPlo_HisCol_ClassCount,       SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->checkBox_ResPlo_HisCol_Accumulate,      SIGNAL(clicked(bool)),                      this,                   SLOT(Update_Results()));
    connect(ui->checkBox_ResPlo_HisCol_Uniform,         SIGNAL(clicked(bool)),                      this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_HisCol_Typ,             SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_StatComp_X_Stat,        SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_StatComp_Y_Stat,        SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_StatComp_X_Typ,         SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_StatComp_Y_Typ,         SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->checkBox_ResPlo_MM_Mean,                SIGNAL(clicked(bool)),                      this,                   SLOT(Update_Results()));
    connect(ui->checkBox_ResPlo_MM_SD,                  SIGNAL(clicked(bool)),                      this,                   SLOT(Update_Results()));
    connect(ui->checkBox_ResPlo_MM_Median,              SIGNAL(clicked(bool)),                      this,                   SLOT(Update_Results()));
    connect(ui->checkBox_ResPlo_MM_ADM,                 SIGNAL(clicked(bool)),                      this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_MM_Typ,                 SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->checkBox_ResPlo_CSK_CV,                 SIGNAL(clicked(bool)),                      this,                   SLOT(Update_Results()));
    connect(ui->checkBox_ResPlo_CSK_Skewness,           SIGNAL(clicked(bool)),                      this,                   SLOT(Update_Results()));
    connect(ui->checkBox_ResPlo_CSK_Kurtosis,           SIGNAL(clicked(bool)),                      this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_CSK_Typ,                SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_Quant_Steps,            SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_Quant_Typ,              SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_Res_PlotType_Img,              SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_HisImg_Attribute,       SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->spinBox_ResPlo_HisImg_ClassCount,       SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->checkBox_ResPlo_HisImg_Accumulate,      SIGNAL(clicked(bool)),                      this,                   SLOT(Update_Results()));
    connect(ui->checkBox_ResPlo_HisImg_Uniform,         SIGNAL(clicked(bool)),                      this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_StatComp_Img_X_Attribute,SIGNAL(currentIndexChanged(int)),          this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResPlo_StatComp_Img_Y_Attribute,SIGNAL(currentIndexChanged(int)),          this,                   SLOT(Update_Results()));
    connect(ui->checkBox_ResAtt_Border,                 SIGNAL(clicked(bool)),                      this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResAtt_Attribute,              SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->comboBox_ResAtt_BaseImage,              SIGNAL(currentIndexChanged(int)),           this,                   SLOT(Update_Results()));
    connect(ui->doubleSpinBox_ResAtt_Scale,             SIGNAL(valueChanged(double)),               this,                   SLOT(Update_Results()));
    connect(ui->spinBox_ResAtt_Precision,               SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));
    connect(ui->spinBox_ResAtt_Tickness,                SIGNAL(valueChanged(int)),                  this,                   SLOT(Update_Results()));


    //show
    //this->showMaximized();

    setWindowTitle("ImageD - Plugin - Cellcoloy Statistics");
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
}


D_MAKRO_CellColonies::~D_MAKRO_CellColonies()
{
    delete ui;
}

void D_MAKRO_CellColonies::closeEvent(QCloseEvent *event)
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

void D_MAKRO_CellColonies::Load_Images()
{
    //get DIR
    QString ST_Dir = QFileDialog::getExistingDirectory(
                this,
                "Select folder with .jpg files to be analyzed and reference.jpg",
                pStore->dir_M_CellColonies()->path());

    //check if DIR was selected by user
    if(ST_Dir.isEmpty())
        return;

    //save paths
    DIR_Input_Dir.setPath(ST_Dir);
    pStore->set_dir_M_CellColonies(ST_Dir);
    DIR_Stream.setPath(ST_Dir);

    //get list of things in dir
    QStringList QSL_Input_Images = DIR_Input_Dir.entryList();
    qDebug() << QSL_Input_Images;

    //clear old content
    Loaded_FileInfos = false;
    ui->comboBox_ProcView_Image->clear();
    FIL_Input_Images.clear();

    //find jpg images
    for(int i = 0; i < QSL_Input_Images.size(); i++)
    {
        QString ST_File =  QSL_Input_Images.at(i);

        if(ST_File.endsWith(".jpg") || ST_File.endsWith(".JPG"))
        {
            if(ST_File.contains("reference") || ST_File.contains("Reference"))
            {
                //reference image found
                FI_Reference_Image = QFileInfo(ST_Dir + "/" + ST_File);
                qDebug() << "Reference image found:" << FI_Reference_Image.absoluteFilePath();
            }
            else
            {
                //other image found
                FIL_Input_Images.append(QFileInfo(ST_Dir + "/" + ST_File));
                ui->comboBox_ProcView_Image->addItem(FIL_Input_Images.last().baseName());
                qDebug() << "Image found:" << FIL_Input_Images.last().absoluteFilePath();
            }
        }
        else
        {
            qDebug() << "Rubbish found:" << ST_File;
        }
    }

    //Update Proc
    if(!FIL_Input_Images.isEmpty())
        Loaded_FileInfos = true;
    Update_ImgProc();

    qDebug() << "Load_Images end";
}

void D_MAKRO_CellColonies::Save_Stack()
{
    if(!Loaded_FileInfos || !Calced_AttSta_new)
        return;

    QString ST_Dir = QFileDialog::getExistingDirectory(
                this,
                "Select folder to stream the output to.",
                DIR_Input_Dir.path());

    if(ST_Dir == 0)
        return;

    //create subfolder for output
    unsigned int count = 0;
    QString QS_Folder_Out_Sub = ST_Dir + "/Results_Stack_0";
    while(QDir(QS_Folder_Out_Sub).exists())
    {
        count++;
        QS_Folder_Out_Sub = ST_Dir + "/Results_Stack_" + QString::number(count);
    }

    //create (sub)dirs
    DIR_Stream_Stack.setPath(QS_Folder_Out_Sub);
    QDir().mkdir(DIR_Stream_Stack.path());

    DIR_Stream_Stack_Labeling.setPath(QS_Folder_Out_Sub + "/Labeling");
    QDir().mkdir(DIR_Stream_Stack_Labeling.path());

    DIR_Stream_Stack_Surrival.setPath(QS_Folder_Out_Sub + "/Surrival");
    QDir().mkdir(DIR_Stream_Stack_Surrival.path());

    DIR_Stream_Stack_Attribute.setPath(QS_Folder_Out_Sub + "/Attributes");
    QDir().mkdir(DIR_Stream_Stack_Attribute.path());

    //start proc
    stack_proc_active = true;
    stream_active = true;

    OS_Stack.open((DIR_Stream_Stack.path() + "/stack_stats.csv").toStdString());
    OS_Stack_Summary.open((DIR_Stream_Stack.path() + "/stack_summary.csv").toStdString());

    //Stream init
    OS_Stack
            << "File,"          << "stack_stats.csv" << "\n"
            << "Path,"          << DIR_Input_Dir.path().toStdString() << "\n"
            << "DateTime,"      << QDateTime::currentDateTime().toString().toStdString() << "\n"
            << "\n"
            << "IMAGE,"         << ",,"         << "DETECTED,"  << "SURRIVAL,"  << ","          << "DEAD,"      <<  ",,"        << "AREA,"  << ","      << ",,"     << "ABSORBTION,"<< ","      << ",,"     << "APPROX_CELL_COUNT," << ","      << ","      << "\n"
            << "name,"          << "number,,"   << "absolute,"  << "absolute,"  << "relative,"  << "absolute,"  << "relative,," << "mean,"  << "median,"<< "SD,,"   << "mean,"      << "median,"<< "SD,,"   << "mean,"              << "median,"<< "SD,"    << "\n"
            << "\n";

    OS_Stack_Summary
            << "File,"          << "stack_summary.csv" << "\n"
            << "Path,"          << DIR_Input_Dir.path().toStdString() << "\n"
            << "DateTime,"      << QDateTime::currentDateTime().toString().toStdString() << "\n"
            << "\n"
            << "IMAGE,"         << "ATTRIBUTE,," << "COLONIES->," << "\n"
            << "\n";

    //Stream Images related stuff
    for(int i = 0; i < FIL_Input_Images.size(); i++)
    {
        ui->comboBox_ProcView_Image->setCurrentIndex(i);
        DIR_Stream.setPath(DIR_Stream_Stack.path() + "/" + QString::number(i) + " - " + QS_BaseName_Current);
        QDir().mkdir(DIR_Stream.path());
        Save_Analysis();

        OS_Stack
                << QS_BaseName_Current.toStdString() << ","
                << i << ",,"

                << count_detected << ","
                << count_surrival << ","
                << prz_surrival << ","
                << count_dead << ","
                << prz_dead << ",,"

                << vvd_AttSta_new[c_ATT_SIZE_AREA][c_STAT_MEAN_ARITMETIC] << ","
                << vvd_AttSta_new[c_ATT_SIZE_AREA][c_STAT_MEDIAN] << ","
                << vvd_AttSta_new[c_ATT_SIZE_AREA][c_STAT_STAN_DEV_SAMPLE] << ",,"

                << vvd_AttSta_new[c_ATT_ABSORB_SUM][c_STAT_MEAN_ARITMETIC] << ","
                << vvd_AttSta_new[c_ATT_ABSORB_SUM][c_STAT_MEDIAN] << ","
                << vvd_AttSta_new[c_ATT_ABSORB_SUM][c_STAT_STAN_DEV_SAMPLE] << ",,"

                << vvd_AttSta_new[c_ATT_CELL_DENSITY_SUM][c_STAT_MEAN_ARITMETIC] << ","
                << vvd_AttSta_new[c_ATT_CELL_DENSITY_SUM][c_STAT_MEDIAN] << ","
                << vvd_AttSta_new[c_ATT_CELL_DENSITY_SUM][c_STAT_STAN_DEV_SAMPLE] << ","

                << "\n";

        //stack summary

        //sizes
        OS_Stack_Summary << QS_BaseName_Current.toStdString() << "," << "Pixel_Count" << ",";
        for(int col = 0; col < vvvd_TypColSta[0].size(); col++)
        {
            OS_Stack_Summary << "," << vvvd_TypColSta[0][col][c_STAT_COUNT];
        }
        OS_Stack_Summary << "\n";

        //types
        for(int typ = 0; typ < c_TYP_NUMBER_OF; typ++)
        {
            if(typ != c_TYP_TRANS_RADIAL)   //skip, because nearly useless
            {
                OS_Stack_Summary << QS_BaseName_Current.toStdString() << "," << "accumulated " << QSL_Types[typ].toStdString() << ",";
                for(int col = 0; col < vvvd_TypColSta[typ].size(); col++)
                {
                    OS_Stack_Summary << "," << vvvd_TypColSta[typ][col][c_STAT_SUM];
                }
                OS_Stack_Summary << "\n";
            }
        }
        OS_Stack_Summary << "\n";
    }

    OS_Stack.close();
    OS_Stack_Summary.close();
    stream_active = false;
    stack_proc_active = false;
}

void D_MAKRO_CellColonies::Save_Analysis_Dialog()
{
    if(!Calced_AttSta_new)
        return;

    QString ST_Dir = QFileDialog::getExistingDirectory(
                this,
                "Select folder to stream the output to.",
                DIR_Input_Dir.path());

    if(ST_Dir == 0)
        return;

    //create subfolder for output
    unsigned int count = 0;
    QString QS_Folder_Out_Sub = ST_Dir + "/Results_Image_" + QS_BaseName_Current + "_0";
    while(QDir(QS_Folder_Out_Sub).exists())
    {
        count++;
        QS_Folder_Out_Sub = ST_Dir + "/Results_Image_" + QS_BaseName_Current + "_" + QString::number(count);
    }
    QDir().mkdir(QS_Folder_Out_Sub);
    DIR_Stream.setPath(QS_Folder_Out_Sub);

    stream_active = true;
    Save_Analysis();
    stream_active = false;
}

void D_MAKRO_CellColonies::Save_Analysis()
{
    if(!Calced_AttSta_new)
        return;

    this->setEnabled(false);

    QString QS_Base_SavePath = DIR_Stream.path() + "/";

    //--------------------------------------------------    Tables
    if(ui->checkBox_Output_CSV_Parameter->isChecked())
        Save_Parameters();

    if(ui->checkBox_Output_CSV_Results->isChecked())
        Save_Results();

    if(ui->checkBox_Output_CSV_RawData->isChecked())
        Save_Raw_Data();

    //--------------------------------------------------    Processing Chain

    ui->groupBox_ProcView->setVisible(true);
    ui->groupBox_Results->setVisible(false);
    ui->groupBox_Control->setVisible(false);

    if(ui->checkBox_Output_ProcSteps->isChecked())
        Save_Processing_Chain();

    //--------------------------------------------------    Images

    ui->groupBox_ProcView->setVisible(false);
    ui->groupBox_Results->setVisible(true);
    ui->groupBox_Control->setVisible(false);
    Update_Views();
    Update_Ui();

    //Labeling
    if(ui->checkBox_Output_Labeling->isChecked())
    {
        ui->tabWidget_Res->setCurrentIndex(0);
        ui->comboBox_ResImg_Color->setCurrentIndex(c_ST_C_RGB);
        ui->comboBox_ResImg_Binary->setCurrentIndex(c_ST_B_EDGES_NUMBERS - 7);
        Save_Image(&Viewer_Results, QS_Base_SavePath + "Image_Labeling.png");
        if(stack_proc_active)
            Save_Image(&Viewer_Results, DIR_Stream_Stack_Labeling.path() + "/Image_Labeling - " + QS_BaseName_Current + ".png");
    }

    //Surrival
    if(ui->checkBox_Output_Surrival->isChecked())
    {
        ui->tabWidget_Res->setCurrentIndex(3);
        Save_Image(&Viewer_Surrival, QS_Base_SavePath + "Image_Surrival.png");
        if(stack_proc_active)
            Save_Image(&Viewer_Surrival, DIR_Stream_Stack_Surrival.path() + "/Image_Surrival - " + QS_BaseName_Current + ".png");
    }

    //Segmentation
    if(ui->checkBox_Output_Segmentation->isChecked())
    {
        ui->tabWidget_Res->setCurrentIndex(4);
        Save_Image(&Viewer_Segmentation, QS_Base_SavePath + "Image_Segmentation.png");
        if(stack_proc_active)
            Save_Image(&Viewer_Segmentation, DIR_Stream_Stack_Labeling.path() + "/Image_Segmentation - " + QS_BaseName_Current + ".png");
    }

    //Area
    if(ui->checkBox_Output_Area->isChecked())
    {
        ui->tabWidget_Res->setCurrentIndex(5);
        ui->comboBox_ResAtt_Attribute->setCurrentIndex(c_ATT_SIZE_AREA);
        Save_Image(&Viewer_Attribute, QS_Base_SavePath + "Image_AreaInPx.png");
        if(stack_proc_active)
            Save_Image(&Viewer_Attribute, DIR_Stream_Stack_Attribute.path() + "/Image_AreaInPx - " + QS_BaseName_Current + ".png");
    }

    //Cell Cont
    if(ui->checkBox_Output_CellCount->isChecked())
    {
        ui->tabWidget_Res->setCurrentIndex(5);
        ui->comboBox_ResAtt_Attribute->setCurrentIndex(c_ATT_CELL_DENSITY_SUM);
        Save_Image(&Viewer_Attribute, QS_Base_SavePath + "Image_CellCountApprox.png");
        if(stack_proc_active)
            Save_Image(&Viewer_Attribute, DIR_Stream_Stack_Attribute.path() + "/Image_CellCountApprox - " + QS_BaseName_Current + ".png");
    }

    //--------------------------------------------------    Plots

    ui->groupBox_ProcView->setVisible(false);
    ui->groupBox_Results->setVisible(false);
    ui->groupBox_Control->setVisible(true);

    //Surrival Plot
    if(ui->checkBox_Output_Plot_Img_Surrival->isChecked())
    {
        Save_Plot(
                    pChartView_Surrival,
                    QS_Base_SavePath + "Plot_Surrival - Pie.png");
        if(stack_proc_active)
            Save_Plot(
                        pChartView_Surrival,
                        DIR_Stream_Stack_Surrival.path() + "/Plot_Surrival - " + QS_BaseName_Current + ".png");
    }


    //Image Plots--------------------------------------------------------------------
    ui->groupBox_ProcView->setVisible(false);
    ui->groupBox_Results->setVisible(true);
    ui->groupBox_Control->setVisible(false);

    ui->tabWidget_Res->setCurrentIndex(2);

    //Histograms
    if(ui->checkBox_Output_Plot_Img_Hist->isChecked())
    {
        ui->comboBox_Res_PlotType_Img->setCurrentIndex(0);
        ui->spinBox_ResPlo_HisImg_ClassCount->setValue(1000);
        ui->checkBox_ResPlo_HisImg_Accumulate->setChecked(true);
        ui->checkBox_ResPlo_HisImg_Uniform->setChecked(true);
        for(int a = 0; a < 6; a++)
        {
            ui->comboBox_ResPlo_HisImg_Attribute->setCurrentIndex(a);
            Save_Plot(
                        pChartView_Image,
                        QS_Base_SavePath + "Plot_Image - Histogram - " + ui->comboBox_ResPlo_HisImg_Attribute->currentText() + ".png");
        }
    }

    //Attribute Compare
    if(ui->checkBox_Output_Plot_Img_Scatter->isChecked())
    {
        ui->comboBox_Res_PlotType_Img->setCurrentIndex(1);
        ui->comboBox_ResPlo_StatComp_Img_X_Attribute->setCurrentIndex(0);
        for(int a = 3; a < 6; a++)
        {
            ui->comboBox_ResPlo_StatComp_Img_Y_Attribute->setCurrentIndex(a);
            Save_Plot(
                        pChartView_Image,
                        QS_Base_SavePath + "Plot_Image - Scatter - " + ui->comboBox_ResPlo_StatComp_Img_X_Attribute->currentText() + " - " + ui->comboBox_ResPlo_StatComp_Img_Y_Attribute->currentText() + ".png");
        }
    }

    //Colony Plots---------------------------------------------------------------------------
    ui->tabWidget_Res->setCurrentIndex(1);

    bool output_type[c_TYP_NUMBER_OF];
    output_type[c_TYP_ABS]          = ui->checkBox_Output_Absorbtion->isChecked();
    output_type[c_TYP_TRANS]        = ui->checkBox_Output_Transmission->isChecked();
    output_type[c_TYP_TRANS_RADIAL] = ui->checkBox_Output_TransmissionRadial->isChecked();
    output_type[c_TYP_CELL_DENSITY] = ui->checkBox_Output_CellDensity->isChecked();

    for(int t = 0; t < c_TYP_NUMBER_OF; t++)
        if(output_type[t])
        {
            //Histogram
            if(ui->checkBox_Output_Plot_Col_Hist->isChecked())
            {
                ui->comboBox_Res_PlotType->setCurrentIndex(0);
                ui->comboBox_ResPlo_HisCol_Typ->setCurrentIndex(t);

                ui->spinBox_ResPlo_HisCol_ClassCount->setValue(256);
                ui->checkBox_ResPlo_HisCol_Uniform->setChecked(true);
                ui->checkBox_ResPlo_HisCol_Accumulate->setChecked(true);
                Save_Plot(
                            pChartView_Colony,
                            QS_Base_SavePath + "Plot_Colony - Histogram - " + QSL_Types[t] + ".png");
            }

            //Mean/SD/Median/ADM
            ui->comboBox_Res_PlotType->setCurrentIndex(2);
            ui->comboBox_ResPlo_MM_Typ->setCurrentIndex(t);

            //Mean
            if(ui->checkBox_Output_Plot_Col_Mean->isChecked())
            {
                ui->checkBox_ResPlo_MM_Mean->setChecked(true);
                ui->checkBox_ResPlo_MM_SD->setChecked(false);
                ui->checkBox_ResPlo_MM_Median->setChecked(false);
                ui->checkBox_ResPlo_MM_ADM->setChecked(false);
                Update_Results();
                Save_Plot(
                            pChartView_Colony,
                            QS_Base_SavePath + "Plot_Colony - Bar - Mean - " + QSL_Types[t] + ".png");
            }

            //SD
            if(ui->checkBox_Output_Plot_Col_SD->isChecked())
            {
                ui->checkBox_ResPlo_MM_Mean->setChecked(false);
                ui->checkBox_ResPlo_MM_SD->setChecked(true);
                ui->checkBox_ResPlo_MM_Median->setChecked(false);
                ui->checkBox_ResPlo_MM_ADM->setChecked(false);
                Update_Results();
                Save_Plot(
                            pChartView_Colony,
                            QS_Base_SavePath + "Plot_Colony - Bar - SD - " + QSL_Types[t] + ".png");
            }

            //Median
            if(ui->checkBox_Output_Plot_Col_Median->isChecked())
            {
                ui->checkBox_ResPlo_MM_Mean->setChecked(false);
                ui->checkBox_ResPlo_MM_SD->setChecked(false);
                ui->checkBox_ResPlo_MM_Median->setChecked(true);
                ui->checkBox_ResPlo_MM_ADM->setChecked(false);
                Update_Results();
                Save_Plot(
                            pChartView_Colony,
                            QS_Base_SavePath + "Plot_Colony - Bar - Median - " + QSL_Types[t] + ".png");
            }

            //ADM
            if(ui->checkBox_Output_Plot_Col_ADM->isChecked())
            {
                ui->checkBox_ResPlo_MM_Mean->setChecked(false);
                ui->checkBox_ResPlo_MM_SD->setChecked(false);
                ui->checkBox_ResPlo_MM_Median->setChecked(false);
                ui->checkBox_ResPlo_MM_ADM->setChecked(true);
                Update_Results();
                Save_Plot(
                            pChartView_Colony,
                            QS_Base_SavePath + "Plot_Colony - Bar - ADM - " + QSL_Types[t] + ".png");
            }

            //CSK
            ui->comboBox_Res_PlotType->setCurrentIndex(3);
            ui->comboBox_ResPlo_CSK_Typ->setCurrentIndex(t);

            //Coefficient of Variance
            if(ui->checkBox_Output_Plot_Col_CV->isChecked())
            {
                ui->checkBox_ResPlo_CSK_CV->setChecked(true);
                ui->checkBox_ResPlo_CSK_Skewness->setChecked(false);
                ui->checkBox_ResPlo_CSK_Kurtosis->setChecked(false);
                Update_Results();
                Save_Plot(
                            pChartView_Colony,
                            QS_Base_SavePath + "Plot_Colony - Bar - CV - " + QSL_Types[t] + ".png");
            }

            //Skewness
            if(ui->checkBox_Output_Plot_Col_Skewness->isChecked())
            {
                ui->checkBox_ResPlo_CSK_CV->setChecked(false);
                ui->checkBox_ResPlo_CSK_Skewness->setChecked(true);
                ui->checkBox_ResPlo_CSK_Kurtosis->setChecked(false);
                Update_Results();
                Save_Plot(
                            pChartView_Colony,
                            QS_Base_SavePath + "Plot_Colony - Bar - Skewness - " + QSL_Types[t] + ".png");
            }

            //Kurtosis
            if(ui->checkBox_Output_Plot_Col_Kurtosis->isChecked())
            {
                ui->checkBox_ResPlo_CSK_CV->setChecked(false);
                ui->checkBox_ResPlo_CSK_Skewness->setChecked(false);
                ui->checkBox_ResPlo_CSK_Kurtosis->setChecked(true);
                Update_Results();
                Save_Plot(
                            pChartView_Colony,
                            QS_Base_SavePath + "Plot_Colony - Bar - Kurtosis - " + QSL_Types[t] + ".png");
            }

            //Quantiles
            if(ui->checkBox_Output_Plot_Col_Quantiles->isChecked())
            {
                ui->comboBox_Res_PlotType->setCurrentIndex(4);
                ui->comboBox_ResPlo_Quant_Typ->setCurrentIndex(t);

                ui->comboBox_ResPlo_Quant_Steps->setCurrentIndex(3);
                Save_Plot(
                            pChartView_Colony,
                            QS_Base_SavePath + "Plot_Colony - Stacked_Bar - Quantiles - " + QSL_Types[t] + ".png");
            }
        }


    //Trans radial
    if(ui->checkBox_Output_TransRad->isChecked())
    {
        ui->comboBox_Res_PlotType->setCurrentIndex(5);
        Save_Plot(
                    pChartView_Colony,
                    QS_Base_SavePath + "Plot_Colony - XY - Radial_Transmission.png");
    }

    ui->groupBox_ProcView->setVisible(true);
    ui->groupBox_Results->setVisible(true);
    ui->groupBox_Control->setVisible(true);

    this->setEnabled(true);
}

void D_MAKRO_CellColonies::Save_Processing_Chain()
{
    if(vMA_Cells.empty())
        return;

    DIR_Stream_Processing.setPath(DIR_Stream.path() + "/Image_Processing_Steps");
    QDir().mkdir(DIR_Stream_Processing.path());

    for(int s = 0; s < vMA_Cells.size(); s++)
    {
        ui->comboBox_ProcView_Step->setCurrentIndex(s);
        Save_Image(&Viewer_Cells, DIR_Stream_Processing.path() + "/" + ui->comboBox_ProcView_Step->currentText() + ".png");
    }
}

void D_MAKRO_CellColonies::Save_Image(D_Viewer *viewer, QString name_default)
{
    if(stream_active)
        viewer->Save_Image(name_default);
    else
        viewer->Save_Image_Dialog(name_default);
}

void D_MAKRO_CellColonies::Save_Image_Cells()
{
    Save_Image(&Viewer_Cells, pStore->dir_M_CellColonies()->path());
}

void D_MAKRO_CellColonies::Save_Image_Results_Color()
{
    Save_Image(&Viewer_Results, pStore->dir_M_CellColonies()->path());
}

void D_MAKRO_CellColonies::Save_Image_Results_Surrival()
{
    Save_Image(&Viewer_Surrival, pStore->dir_M_CellColonies()->path());
}

void D_MAKRO_CellColonies::Save_Image_Results_Segmentation()
{
    Save_Image(&Viewer_Segmentation, pStore->dir_M_CellColonies()->path());
}

void D_MAKRO_CellColonies::Save_Image_Results_Attribute()
{
    Save_Image(&Viewer_Attribute, pStore->dir_M_CellColonies()->path());
}

void D_MAKRO_CellColonies::Save_Plot(QChartView *pCV_Save, QString name_default)
{
    QString name_save;

    if(stream_active)
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

void D_MAKRO_CellColonies::Save_Plot_Colony()
{
    Save_Plot(pChartView_Colony, pStore->dir_M_CellColonies()->path());
}

void D_MAKRO_CellColonies::Save_Plot_Image()
{
    Save_Plot(pChartView_Image, pStore->dir_M_CellColonies()->path());
}

void D_MAKRO_CellColonies::Save_Plot_Surrival()
{
    Save_Plot(pChartView_Surrival, pStore->dir_M_CellColonies()->path());
}

void D_MAKRO_CellColonies::Save_Parameters()
{
    QString QS_Stream_Parameters = DIR_Stream.path() + "/table_parameters_used.csv";
    OS_Parameters.open(QS_Stream_Parameters.toStdString());

    OS_Parameters
            << "File,"          << "table_parameters_used.csv" << "\n"
            << "Image,"         << QS_BaseName_Current.toStdString() << "\n"
            << "Path,"          << DIR_Input_Dir.path().toStdString() << "\n"
            << "DateTime,"      << QDateTime::currentDateTime().toString().toStdString() << "\n"
            << "\n"
            << "Reference,"     << "Size/Sigma,"    << ui->spinBox_ProcCon_Ref_Blur_Size->value()           << "," << ui->doubleSpinBox_ProcCon_Ref_Blur_Sigma->value() << "\n"
            << "ROI,"           << "Min X/Y,"       << ui->doubleSpinBox_ProcCon_ROI_X1->value()            << "," << ui->doubleSpinBox_ProcCon_ROI_Y1->value()         << "\n"
            << "ROI,"           << "Max X/Y,"       << ui->doubleSpinBox_ProcCon_ROI_X2->value()            << "," << ui->doubleSpinBox_ProcCon_ROI_Y2->value()         << "\n"
            << "Colonies,"      << "Min H/S/V,"     << ui->spinBox_ProcCon_ColGrab_H_Min->value()           << "," << ui->spinBox_ProcCon_ColGrab_S_Min->value()        << "," << ui->spinBox_ProcCon_ColGrab_V_Min->value()    << "\n"
            << "Colonies,"      << "Max H/S/V,"     << ui->spinBox_ProcCon_ColGrab_H_Max->value()           << "," << ui->spinBox_ProcCon_ColGrab_S_Max->value()        << "," << ui->spinBox_ProcCon_ColGrab_V_Max->value()    << "\n"
            << "Colonies,"      << "Size,"          << ui->spinBox_ProcCon_CellCol_Black_Noise->value()     << "\n"
            << "Colonies,"      << "Size,"          << ui->spinBox_ProcCon_CellCol_White_Noise->value()     << "\n"
            << "Seeds,"         << "Size/Sigma,"    << ui->spinBox_ProcCon_Seed_Blur_Size->value()          << "," << ui->doubleSpinBox_ProcCon_Seed_Blur_Sigma->value()<< "\n"
            << "Seeds,"         << "Size/Sigma,"    << ui->spinBox_ProcCon_Thres_Size->value()              << "," << ui->doubleSpinBox_ProcCon_Thres_Offset->value()   << "\n"
            << "Seeds,"         << "Size,"          << ui->spinBox_ProcCon_Seed_Open_Size->value()          << "\n"
            << "Seeds,"         << "Threshold,"     << ui->doubleSpinBox_Extract_Asphere_Thres->value()     << "\n"
            << "Seeds,"         << "Threshold,"     << ui->doubleSpinBox_Separtate_Asphere_Thres->value()   << "\n"
            << "Segmentation,"  << "at Border,"     << ui->checkBox_ProcCon_Watershed_Border->isChecked()   << "\n"
            << "Segmentation,"  << "not seeded,"    << ui->checkBox_ProcCon_Watershed_nSeed->isChecked()    << "\n"
            << "Surrival,"      << "Cell Number,"   << ui->doubleSpinBox_Sur_CellCount->value()             << "\n";

    OS_Parameters.close();

    ui->tabWidget_Control->setCurrentIndex(0);//show settings
    this->setEnabled(true);
    ui->tabWidget_Control->grab().save(DIR_Stream.path() + "/Parameters_Used.png");
    this->setEnabled(false);
}

void D_MAKRO_CellColonies::Save_Results()
{
    if(!Calced_AttSta_new)
        return;

    bool output_type[c_TYP_NUMBER_OF];
    output_type[c_TYP_ABS]          = ui->checkBox_Output_Absorbtion->isChecked();
    output_type[c_TYP_TRANS]        = ui->checkBox_Output_Transmission->isChecked();
    output_type[c_TYP_TRANS_RADIAL] = ui->checkBox_Output_TransmissionRadial->isChecked();
    output_type[c_TYP_CELL_DENSITY] = ui->checkBox_Output_CellDensity->isChecked();

    for(int t = 0; t < c_TYP_NUMBER_OF; t++)
        if(output_type[t])
        {
            QString QS_Stream_Results = DIR_Stream.path() + "/table_result_stats - " + QSL_Types[t] + ".csv";
            OS_Results.open(QS_Stream_Results.toStdString());

            //HEADER-------------------------------------------------------------
            OS_Results
                    << "File,"          << "table_results_stats - " + QSL_Types[t].toStdString() + ".csv" << "\n"
                    << "Image,"         << QS_BaseName_Current.toStdString() << "\n"
                    << "Path,"          << DIR_Input_Dir.path().toStdString() << "\n"
                    << "DateTime,"      << QDateTime::currentDateTime().toString().toStdString() << "\n"
                    << "\n\n";

            //SURRIVAL------------------------------------------------------------
            OS_Results
                    << "SURRIVAL,"       << "\n\n"
                    << "Type,"          << "colonies"       << ","  << "relative,"  << "\n"
                    << "Detected,"      << count_detected   << "\n"
                    << "Surrival,"      << count_surrival   << "," << prz_surrival  << "\n"
                    << "Dead,"          << count_dead       << "," << prz_dead      << "\n"
                    << "\n\n";

            //ATTRIBUTES------------------------------------------------------------
            OS_Results << "ATTRIBUTES," << "(Colony-Attributes)" << "\n\n";

            //Stat Name
            OS_Results << "Attribute";
            for(int s = 0; s < QSL_StatList.size(); s++)
                OS_Results << "," << QSL_StatList[s].toStdString();
            OS_Results << "\n";

            //Stat Value per Attribute
            for(int a = 0; a < QSL_Attrib.size(); a++)
            {
                OS_Results << QSL_Attrib[a].toStdString();

                for(int s = 0; s < vvd_AttSta_new[a].size(); s++)
                    OS_Results << "," << vvd_AttSta_new[a][s];

                OS_Results << "\n";
            }

            OS_Results << "\n\n";

            //COLONIES----------------------------------------------------------------
            OS_Results << "COLONIES," << "(Pixel-Values: " + QSL_Types[t].toStdString() + ")" << "\n\n";

            //Stat Name
            OS_Results << "Colony_Number";
            for(int s = 0; s < QSL_StatList.size(); s++)
                OS_Results << "," << QSL_StatList[s].toStdString();
            OS_Results << "\n";

            //Stat Value per Colony
            for(int c = 0; c < vvvd_TypColSta[t].size(); c++)
            {
                OS_Results << "Colony_" << c;

                for(int s = 0; s < vvvd_TypColSta[t][c].size(); s++)
                    OS_Results << "," << vvvd_TypColSta[t][c][s];

                OS_Results << "\n";
            }

            OS_Results.close();
        }
}

void D_MAKRO_CellColonies::Save_Raw_Data()
{
    if(!Calced_ColSur_new)
        return;

    bool output_type[c_TYP_NUMBER_OF];
    output_type[c_TYP_ABS]          = ui->checkBox_Output_Absorbtion->isChecked();
    output_type[c_TYP_TRANS]        = ui->checkBox_Output_Transmission->isChecked();
    output_type[c_TYP_TRANS_RADIAL] = ui->checkBox_Output_TransmissionRadial->isChecked();
    output_type[c_TYP_CELL_DENSITY] = ui->checkBox_Output_CellDensity->isChecked();

    for(int t = 0; t < c_TYP_NUMBER_OF; t++)
        if(output_type[t])
        {
            QString QS_Stream_RawData = DIR_Stream.path() + "/table_raw_data - " + QSL_Types[t] + ".csv";
            OS_Raw_Data.open(QS_Stream_RawData.toStdString());

            //HEADER-------------------------------------------------------------
            OS_Raw_Data
                    << "File,"          << "table_raw_data - " + QSL_Types[t].toStdString() + ".csv" << "\n"
                    << "Image,"         << QS_BaseName_Current.toStdString() << "\n"
                    << "Path,"          << DIR_Input_Dir.path().toStdString() << "\n"
                    << "DateTime,"      << QDateTime::currentDateTime().toString().toStdString() << "\n"
                    << "\n\n";

            //DATA-------------------------------------------------------------

            //Colonies
            OS_Raw_Data << "Colony,";
            for(int c = 0; c < vvvd_TypColVal[t].size(); c++)
                OS_Raw_Data << c << ",";
            OS_Raw_Data << "\n";

            //Area
            OS_Raw_Data << "Area,";
            for(int c = 0; c < vvvd_TypColSta[t].size(); c++)
                OS_Raw_Data << vvvd_TypColSta[t][c][c_STAT_COUNT] << ",";
            OS_Raw_Data << "\n";

            //Sum of Values
            OS_Raw_Data << "Intensity,";
            for(int c = 0; c < vvvd_TypColSta[t].size(); c++)
                OS_Raw_Data << vvvd_TypColSta[t][c][c_STAT_SUM] << ",";
            OS_Raw_Data << "\n";

            //Surrival
            OS_Raw_Data << "Surrival,";
            for(int c = 0; c < vi_ColSur_new.size(); c++)
            {
                if(vi_ColSur_new[c])
                    OS_Raw_Data << ":-)" << ",";
                else
                    OS_Raw_Data << "RIP" << ",";
            }
            OS_Raw_Data << "\n";

            //Data
            OS_Raw_Data << "\n";
            int value_exist = 1;
            int v = 0;
            while(value_exist)
            {
                value_exist = 0;

                OS_Raw_Data << "Pixel_" << v + 1 << ",";

                for(int c = 0; c < vvvd_TypColVal[t].size(); c++)
                {
                    if(v < vvvd_TypColVal[t][c].size())
                    {
                        OS_Raw_Data << vvvd_TypColVal[t][c][v] << ",";
                        value_exist++;
                    }
                    else
                    {
                        OS_Raw_Data << ",";
                    }
                }

                OS_Raw_Data << "\n";
                v++;
            }

            OS_Raw_Data.close();
        }
}

void D_MAKRO_CellColonies::Update_Views()
{
    Update_View_Cells();
    Update_View_Results();
    Update_View_Surrival();
    Update_View_Segmentation();
    Update_View_Attribute();
}

void D_MAKRO_CellColonies::Update_View_Cells()
{
    Viewer_Cells.Update_View();
}

void D_MAKRO_CellColonies::Update_View_Results()
{
    Viewer_Results.Update_View();
}

void D_MAKRO_CellColonies::Update_View_Surrival()
{
    Viewer_Surrival.Update_View();
}

void D_MAKRO_CellColonies::Update_View_Segmentation()
{
    Viewer_Segmentation.Update_View();
}

void D_MAKRO_CellColonies::Update_View_Attribute()
{
    Viewer_Attribute.Update_View();
}

void D_MAKRO_CellColonies::Update_Ui()
{
    if(this->isEnabled())
        return;

    this->repaint();
    qApp->processEvents();
}

void D_MAKRO_CellColonies::Update_Images()
{
    Update_Image_Cells();
    Update_Image_Results();
    Update_Image_Surrival();
    Update_Image_Segmentation();
    Update_Image_Attribute();
}

void D_MAKRO_CellColonies::Update_Image_Cells()
{
    if(!Loaded_FileInfos)
        return;

    Viewer_Cells.Update_Image(&(vMA_Cells[ui->comboBox_ProcView_Step->currentIndex()]));
}

void D_MAKRO_CellColonies::Update_Image_Results()
{
    if(!Loaded_FileInfos)
        return;

    ERR(D_Img_Proc::Math_ImgImg_Diff(
            &(MA_Result_Color),
            &(vMA_Results[ui->comboBox_ResImg_Color->currentIndex()]),
            &(vMA_Results[ui->comboBox_ResImg_Binary->currentIndex() + 7])),
        "Update_Image_Results",
        "Calculating color image.");

    Viewer_Results.Update_Image(&MA_Result_Color);
}

void D_MAKRO_CellColonies::Update_Image_Surrival()
{
    if(!Calced_ColSur_new)
        return;

    int ER;

    //Get green/red Edges
    qDebug() << "Update_Image_Surrival - Red/Green";

    //create LUT (shifted +1, beacuse index_0->BG)
    vector<int> vLUT;
    vLUT.push_back(0);//BG
    vLUT.insert(end(vLUT), begin(vi_ColSur_new), end(vi_ColSur_new));

    //Aplly LUT to color edges
    ER = D_Img_Proc::LUT_Apply_to_Label_Color(
                &MA_Result_Surrival,
                &(vMA_Cells[c_ST_INPUT_CROP]),
                &(vMA_Cells[c_ST_SEGM_WATERSHED]),
                vLUT,
                0,                                  //true->blue
                2,                                  //false->red
                true);
    ERR(ER,
        "Update_Image_Surrival",
        "Checking, if a Colony is a Surrivor.");
    if(ER != ER_okay)   return;

    //Show resulting image
    qDebug() << "Update_Image_Surrival - Show";
    Viewer_Surrival.Update_Image(&MA_Result_Surrival);

    qDebug() << "Update_Image_Surrival - End";
}

void D_MAKRO_CellColonies::Update_Image_Segmentation()
{
    if(!Loaded_FileInfos)
        return;

    Mat MA_edges;
    ERR(D_Img_Proc::Convert_Color(
            &MA_edges,
            &(vMA_Results[c_ST_B_EDGES]),
            CV_BGR2GRAY),
        "Update_Image_Segmentation",
        "convert inverted edges to gray");

    Mat MA_seeds;
    ERR(D_Img_Proc::Math_ImgImg_BitAnd(
            &MA_seeds,
            &(vMA_Cells[c_ST_SEED_ALL_SEEDS]),
            &(vMA_Cells[c_ST_SEGM_BINARY])),
        "Update_Image_Segmentation",
        "mask seeds");

    Mat MA_empty = Mat::zeros(vMA_Cells[c_ST_INPUT_CROP].size(), CV_8UC1);

    ERR(D_Img_Proc::Math_Special_Add_Color(
            &MA_Result_Segmentation,
            &(vMA_Cells[c_ST_INPUT_CROP]),
            &MA_empty,
            &MA_edges,
            &MA_seeds),
        "Update_Image_Segmentation",
        "add to color image");

    Viewer_Segmentation.Update_Image(&MA_Result_Segmentation);
}

void D_MAKRO_CellColonies::Update_Image_Attribute()
{
    if(!Loaded_FileInfos)   return;
    if(!Calced_AttSta_new)  return;

    ERR(D_Img_Proc::Draw_Label_Numbers_LUT(
            &MA_Result_Attribute,
            &(vMA_Results[ui->comboBox_ResAtt_BaseImage->currentIndex()]),
            &(vMA_Cells[c_ST_SEGM_WATERSHED]),
            vvd_AttCol_new[ui->comboBox_ResAtt_Attribute->currentIndex()],
            ui->checkBox_ResAtt_Border->isChecked(),
            ui->doubleSpinBox_ResAtt_Scale->value(),
            ui->spinBox_ResAtt_Tickness->value(),
            true,
            ui->spinBox_ResAtt_Precision->value()),
        "Update_Image_Attribute",
        "Draw numbers on image");

    Viewer_Attribute.Update_Image(&MA_Result_Attribute);
}

void D_MAKRO_CellColonies::Update_Results()
{
    if(!Loaded_FileInfos || !Calced_ColSur_new)
        return;

    QS_BaseName_Current = FIL_Input_Images[ui->comboBox_ProcView_Image->currentIndex()].baseName();

    switch (ui->tabWidget_Res->currentIndex()) {


    case 0://image
    {
        Update_Image_Results();
    }
        break;


    case 1://plot colony
    {
        switch (ui->comboBox_Res_PlotType->currentIndex()) {

        case 0://hist per colony
            Plot_Histogram_Colonies();
            break;

        case 1://stat compare
            Plot_Stat_Compare();
            break;

        case 2://mean median
            Plot_MM_Colonies();
            break;

        case 3://csk
            Plot_CSK_Colonies();
            break;

        case 4://quantiles
            Plot_Quantiles_Colonies();
            break;

        case 5://radial transmission
            Plot_Radial_Transmission_Colony();
            break;

        default:
            break;
        }
    }
        break;


    case 2://plot image
    {
        switch (ui->comboBox_Res_PlotType_Img->currentIndex()) {

        case 0://hist
            Plot_Histogram_Image();
            break;

        case 1://compare
            Plot_Attribute_Compare();
            break;

        default:
            break;
        }
    }
        break;

    case 3:
        Update_Image_Surrival();
        break;

    case 4:
        Update_Image_Segmentation();
        break;

    case 5:
        Update_Image_Attribute();
        break;

    default:
        break;
    }

    Update_Ui();
}

void D_MAKRO_CellColonies::Settings_Reset()
{
    //Reference
    ui->groupBox_Reference_Input->setChecked(true);
    ui->spinBox_ProcCon_Ref_Blur_Size->setValue(31);
    ui->doubleSpinBox_ProcCon_Ref_Blur_Sigma->setValue(10);
    ui->doubleSpinBox_ProcCon_ROI_X1->setValue(22);
    ui->doubleSpinBox_ProcCon_ROI_Y1->setValue(20);
    ui->doubleSpinBox_ProcCon_ROI_X2->setValue(84);
    ui->doubleSpinBox_ProcCon_ROI_Y2->setValue(83);

    //Foreground
    ui->spinBox_ProcCon_ColGrab_H_Min->setValue(110);
    ui->spinBox_ProcCon_ColGrab_S_Min->setValue(11);
    ui->spinBox_ProcCon_ColGrab_V_Min->setValue(0);
    ui->spinBox_ProcCon_ColGrab_H_Max->setValue(135);
    ui->spinBox_ProcCon_ColGrab_S_Max->setValue(255);
    ui->spinBox_ProcCon_ColGrab_V_Max->setValue(255);
    ui->spinBox_ProcCon_CellCol_Black_Noise->setValue(7);
    ui->spinBox_ProcCon_CellCol_White_Noise->setValue(5);

    //Seeds
    ui->spinBox_ProcCon_Seed_Blur_Size->setValue(7);
    ui->doubleSpinBox_ProcCon_Seed_Blur_Sigma->setValue(5);
    ui->spinBox_ProcCon_Thres_Size->setValue(11);
    ui->doubleSpinBox_ProcCon_Thres_Offset->setValue(-4);
    ui->spinBox_ProcCon_Seed_Open_Size->setValue(7);
    ui->doubleSpinBox_Extract_Asphere_Thres->setValue(4);
    ui->doubleSpinBox_Separtate_Asphere_Thres->setValue(4);

    //Segmentation
    ui->checkBox_ProcCon_Watershed_Border->setChecked(false);
    ui->checkBox_ProcCon_Watershed_nSeed->setChecked(true);

    //Measure
    ui->doubleSpinBox_Measure_Base->setValue(0.92);
    ui->doubleSpinBox_Measure_Factor->setValue(1.8);

    //Survival
    ui->doubleSpinBox_Sur_CellCount->setValue(50);
}

void D_MAKRO_CellColonies::Update_ImgProc()
{
    Update_ImgProc_Cells(0);
}

void D_MAKRO_CellColonies::Update_ImgProc_Cells(int start_step)
{
    if(!Loaded_FileInfos)
        return;

    QS_BaseName_Current = FIL_Input_Images[ui->comboBox_ProcView_Image->currentIndex()].baseName();

    for(int s = start_step; s < c_CELLS_STEPS; s++)
    {
        //qDebug() << "proc step:" << s;
        Update_Step_Cells(s);
    }

    Update_ImgProc_Results(0);
    Update_Image_Cells();
}

void D_MAKRO_CellColonies::Update_ImgProc_Results(int start_step)
{
    if(!Loaded_FileInfos)
        return;

    QS_BaseName_Current = FIL_Input_Images[ui->comboBox_ProcView_Image->currentIndex()].baseName();

    for(int s = start_step; s < c_RESULTS_STEPS; s++)
    {
        //qDebug() << "proc step:" << s;
        Update_Step_Results(s);
    }

    Calc_All();
    Update_Results();
    Update_Image_Results();
}

void D_MAKRO_CellColonies::Update_Step_Cells(int step)
{
    if(!Loaded_FileInfos)
        return;

    switch (step) {

    //==========================================================================    REFERENCE

    case c_ST_REFERENCE_LOAD:
    {
        if(FI_Reference_Image.exists())
        {
            ERR(D_Img_Proc::Load_From_Path(
                    &(vMA_Cells[c_ST_REFERENCE_LOAD]),
                    FI_Reference_Image.absoluteFilePath().toStdString()),
                "Update_Step_Cells",
                "c_ST_REFERENCE_LOAD");

            qDebug() << FI_Reference_Image.absoluteFilePath();
        }
        else
        {
            QMessageBox MSG;
            MSG.setText("No reference image found!");
            MSG.setInformativeText("This is needed for measurement without a terrible offset. You should know that ;-) \n"
                                   "Just put an image of an empty flask with 'reference' in its name in the input directory. \n"
                                   "It should be taken under the same circumstances as the images with the cell-colonies.");
            MSG.exec();
        }
    }
        break;

    case c_ST_REFERENCE_CROP:
    {
        ERR(D_Img_Proc::Crop_Rect_Rel(
                &(vMA_Cells[c_ST_REFERENCE_CROP]),
                &(vMA_Cells[c_ST_REFERENCE_LOAD]),
                ui->doubleSpinBox_ProcCon_ROI_X1->value() / 100.0,
                ui->doubleSpinBox_ProcCon_ROI_Y1->value() / 100.0,
                ui->doubleSpinBox_ProcCon_ROI_X2->value() / 100.0,
                ui->doubleSpinBox_ProcCon_ROI_Y2->value() / 100.0),
            "Update_Step_Cells",
            "c_ST_REFERENCE_CROP");
    }
        break;

    case c_ST_REFERENCE_BLUR:
    {
        ERR(D_Img_Proc::Filter_Gauss(
                &(vMA_Cells[c_ST_REFERENCE_BLUR]),
                &(vMA_Cells[c_ST_REFERENCE_CROP]),
                ui->spinBox_ProcCon_Ref_Blur_Size->value(),
                ui->spinBox_ProcCon_Ref_Blur_Size->value(),
                BORDER_DEFAULT,
                ui->doubleSpinBox_ProcCon_Ref_Blur_Sigma->value(),
                ui->doubleSpinBox_ProcCon_Ref_Blur_Sigma->value()),
            "Update_Step_Cells",
            "c_ST_REFERENCE_BLUR");
    }
        break;

    //==========================================================================    INPUT

    case c_ST_INPUT_LOAD:
    {
        qDebug() << "LOADING:" << FIL_Input_Images[ui->comboBox_ProcView_Image->currentIndex()].absoluteFilePath();
        ERR(D_Img_Proc::Load_From_Path(
                &(vMA_Cells[c_ST_INPUT_LOAD]),
                FIL_Input_Images[ui->comboBox_ProcView_Image->currentIndex()].absoluteFilePath().toStdString()),
                "Update_Step_Cells",
                "c_ST_INPUT_LOAD");
    }
        break;

    case c_ST_INPUT_CROP:
    {
        ERR(D_Img_Proc::Crop_Rect_Rel(
                &(vMA_Cells[c_ST_INPUT_CROP]),
                &(vMA_Cells[c_ST_INPUT_LOAD]),
                ui->doubleSpinBox_ProcCon_ROI_X1->value() / 100.0,
                ui->doubleSpinBox_ProcCon_ROI_Y1->value() / 100.0,
                ui->doubleSpinBox_ProcCon_ROI_X2->value() / 100.0,
                ui->doubleSpinBox_ProcCon_ROI_Y2->value() / 100.0),
            "Update_Step_Cells",
            "c_ST_ROI_CROP_RECT");
    }
        break;

    case c_ST_INPUT_ANTI_SHADE:
    {
        ERR(D_Img_Proc::Shading_Correct(
                &(vMA_Cells[c_ST_INPUT_ANTI_SHADE]),
                &(vMA_Cells[c_ST_INPUT_CROP]),
                &(vMA_Cells[c_ST_REFERENCE_BLUR])),
            "Update_Step_Cells",
            "c_ST_INPUT_ANTI_SHADE");
    }
        break;

    //==========================================================================    CELL-COLONIES

    case c_ST_CELLS_GRAB_COLOR:
    {
        vector<uchar> min;
        vector<uchar> max;
        min.push_back((uchar) ui->spinBox_ProcCon_ColGrab_H_Min->value());
        min.push_back((uchar) ui->spinBox_ProcCon_ColGrab_S_Min->value());
        min.push_back((uchar) ui->spinBox_ProcCon_ColGrab_V_Min->value());
        max.push_back((uchar) ui->spinBox_ProcCon_ColGrab_H_Max->value());
        max.push_back((uchar) ui->spinBox_ProcCon_ColGrab_S_Max->value());
        max.push_back((uchar) ui->spinBox_ProcCon_ColGrab_V_Max->value());

        qDebug () << "min/max" << min << max;

        ERR(D_Img_Proc::Color_Grab(
                &(vMA_Cells[c_ST_CELLS_GRAB_COLOR]),
                &(vMA_Cells[c_ST_INPUT_ANTI_SHADE]),
                3,
                1,
                min,
                max),
            "Update_Step_Cells",
            "c_ST_CELLS_GRAB_COLOR");
    }
        break;

    case c_ST_CELLS_BINARY:
    {
        ERR(D_Img_Proc::Convert_Color(
                &(vMA_Cells[c_ST_CELLS_BINARY]),
                &(vMA_Cells[c_ST_CELLS_GRAB_COLOR]),
                CV_BGR2GRAY),
            "Update_Step_Cells",
            "c_ST_CELLS_BINARY");

        ERR(D_Img_Proc::Threshold_Value(
                &(vMA_Cells[c_ST_CELLS_BINARY]),
                &(vMA_Cells[c_ST_CELLS_BINARY]),
                CV_THRESH_BINARY,
                255,
                1),
            "Update_Step_Cells",
            "c_ST_CELLS_BINARY");
    }
        break;

    case c_ST_CELLS_NOISE_BLACK:
    {
        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_Cells[c_ST_CELLS_NOISE_BLACK]),
                &(vMA_Cells[c_ST_CELLS_BINARY]),
                MORPH_CLOSE,
                MORPH_ELLIPSE,
                ui->spinBox_ProcCon_CellCol_Black_Noise->value() / 2,
                ui->spinBox_ProcCon_CellCol_Black_Noise->value() / 2,
                BORDER_DEFAULT,
                1),
            "Update_Step_Cells",
            "c_ST_CELLS_NOISE_BLACK");
    }
        break;

    case c_ST_CELLS_NOISE_WHITE:
    {
        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_Cells[c_ST_CELLS_NOISE_WHITE]),
                &(vMA_Cells[c_ST_CELLS_NOISE_BLACK]),
                MORPH_OPEN,
                MORPH_ELLIPSE,
                ui->spinBox_ProcCon_CellCol_White_Noise->value() / 2,
                ui->spinBox_ProcCon_CellCol_White_Noise->value() / 2,
                BORDER_DEFAULT,
                1),
            "Update_Step_Cells",
            "c_ST_CELLS_NOISE_WHITE");
    }
        break;

    //==========================================================================    SEED

    case c_ST_SEED_HSV:
    {
        ERR(D_Img_Proc::Convert_Color(
                &(vMA_Cells[c_ST_SEED_HSV]),
                &(vMA_Cells[c_ST_INPUT_ANTI_SHADE]),
                CV_BGR2HSV_FULL),
            "Update_Step_Cells",
            "c_ST_SEED_HSV");
    }
        break;

    case c_ST_SEED_SATURATION:
    {
        ERR(D_Img_Proc::Split(
                &(vMA_Cells[c_ST_SEED_SATURATION]),
                &(vMA_Cells[c_ST_SEED_HSV]),
                1),
            "Update_Step_Cells",
            "c_ST_SEED_SATURATION");
    }
        break;

    case c_ST_SEED_BLUR:
    {
        ERR(D_Img_Proc::Filter_Gauss(
                &(vMA_Cells[c_ST_SEED_BLUR]),
                &(vMA_Cells[c_ST_SEED_SATURATION]),
                ui->spinBox_ProcCon_Seed_Blur_Size->value() / 2,
                ui->spinBox_ProcCon_Seed_Blur_Size->value() / 2,
                BORDER_DEFAULT,
                ui->doubleSpinBox_ProcCon_Seed_Blur_Sigma->value(),
                ui->doubleSpinBox_ProcCon_Seed_Blur_Sigma->value()),
            "Update_Step_Cells",
            "c_ST_SEED_BLUR");
    }
        break;

    case c_ST_SEED_THRESH:
    {
        ERR(D_Img_Proc::Threshold_Adaptive(
                &(vMA_Cells[c_ST_SEED_THRESH]),
                &(vMA_Cells[c_ST_SEED_BLUR]),
                CV_THRESH_BINARY,
                255,
                CV_ADAPTIVE_THRESH_MEAN_C,
                ui->spinBox_ProcCon_Thres_Size->value() / 2,
                ui->doubleSpinBox_ProcCon_Thres_Offset->value()),
            "Update_Step_Cells",
            "c_ST_SEED_THRESH");
    }
        break;

    case c_ST_SEED_OPEN:
    {
        ERR(D_Img_Proc::Morphology_Elemental(
                &(vMA_Cells[c_ST_SEED_OPEN]),
                &(vMA_Cells[c_ST_SEED_THRESH]),
                MORPH_OPEN,
                MORPH_ELLIPSE,
                ui->spinBox_ProcCon_Seed_Open_Size->value() / 2,
                ui->spinBox_ProcCon_Seed_Open_Size->value() / 2,
                BORDER_DEFAULT,
                1),
            "Update_Step_Cells",
            "c_ST_SEED_OPEN");
    }
        break;

    case c_ST_SEED_SPHERICITY_INV:
    {
        ERR(D_Img_Proc::Feature_Value(
                &(vMA_Cells[c_ST_SEED_SPHERICITY_INV]),
                &(vMA_Cells[c_ST_SEED_OPEN]),
                c_FEAT_SPHERICITY_INV,
                4),
            "Update_Step_Cells",
            "c_ST_SEED_SPHERICITY_INV");
    }
        break;

    case c_ST_SEED_ASPH_EXTRACT:
    {
        ERR(D_Img_Proc::Threshold_Relative_1C(
                &(vMA_Cells[c_ST_SEED_ASPH_EXTRACT]),
                &(vMA_Cells[c_ST_SEED_SPHERICITY_INV]),
                1,
                ui->doubleSpinBox_Extract_Asphere_Thres->value()),
            "Update_Step_Cells",
            "c_ST_SEED_ASPH_EXTRACT");
    }
        break;

    case c_ST_SEED_ASPH_DISTANCE:
    {
        ERR(D_Img_Proc::Transformation_Distance(
                &(vMA_Cells[c_ST_SEED_ASPH_DISTANCE]),
                &(vMA_Cells[c_ST_SEED_ASPH_EXTRACT]),
                DIST_L2,
                DIST_MASK_PRECISE),
            "Update_Step_Cells",
            "c_ST_SEED_ASPH_DISTANCE");
    }
        break;

    case c_ST_SEED_ASPH_SEPARATE:
    {
        ERR(D_Img_Proc::Threshold_Relative_1C(
                &(vMA_Cells[c_ST_SEED_ASPH_SEPARATE]),
                &(vMA_Cells[c_ST_SEED_ASPH_DISTANCE]),
                1,
                ui->doubleSpinBox_Separtate_Asphere_Thres->value()),
            "Update_Step_Cells",
            "c_ST_SEED_ASPH_SEPARATE");
    }
        break;

    case c_ST_SEED_SPHERE_EXTRACT:
    {
        ERR(D_Img_Proc::Math_ImgImg_Diff(
                &(vMA_Cells[c_ST_SEED_SPHERE_EXTRACT]),
                &(vMA_Cells[c_ST_SEED_OPEN]),
                &(vMA_Cells[c_ST_SEED_ASPH_EXTRACT])),
            "Update_Step_Cells",
            "c_ST_SEED_SPHERE_EXTRACT");
    }
        break;

    case c_ST_SEED_ALL_SEEDS:
    {
        ERR(D_Img_Proc::Math_ImgImg_Add(
                &(vMA_Cells[c_ST_SEED_ALL_SEEDS]),
                &(vMA_Cells[c_ST_SEED_SPHERE_EXTRACT]),
                &(vMA_Cells[c_ST_SEED_ASPH_SEPARATE])),
            "Update_Step_Cells",
            "c_ST_SEED_");
    }
        break;
    //==========================================================================    SEGMENTATION

    case c_ST_SEGM_WATERSHED:
    {
        ERR(D_Img_Proc::Transformation_Watershed_Auto(
                &(vMA_Cells[c_ST_SEGM_WATERSHED]),
                &(vMA_Cells[c_ST_CELLS_NOISE_WHITE]),
                &(vMA_Cells[c_ST_SEED_ALL_SEEDS]),
                ui->checkBox_ProcCon_Watershed_nSeed->isChecked(),
                false,
                !(ui->checkBox_ProcCon_Watershed_Border->isChecked())),
            "Update_Step_Cells",
            "c_ST_SEGM_WATERSHED");
    }
        break;

    case c_ST_SEGM_BINARY:
    {
        ERR(D_Img_Proc::Threshold_Relative(
                &(vMA_Cells[c_ST_SEGM_BINARY]),
                &(vMA_Cells[c_ST_SEGM_WATERSHED]),
                0,
                0),
            "Update_Step_Cells",
            "c_ST_SEGM_8BIT");
    }
        break;

    //==========================================================================    MEASURE

    case c_ST_MEASURE_DIFF:
    {
        ERR(D_Img_Proc::Math_ImgImg_Diff(
                &(vMA_Cells[c_ST_MEASURE_DIFF]),
                &(vMA_Cells[c_ST_REFERENCE_CROP]),
                &(vMA_Cells[c_ST_INPUT_CROP])),
            "Update_Step_Cells",
            "c_ST_MEASURE_DIFF");
    }
        break;

    case c_ST_MEASURE_HSV:
    {
        ERR(D_Img_Proc::Convert_Color(
                &(vMA_Cells[c_ST_MEASURE_HSV]),
                &(vMA_Cells[c_ST_MEASURE_DIFF]),
                CV_BGR2HSV_FULL),
            "Update_Step_Cells",
            "c_ST_MEASURE_HSV");
    }
        break;

    case c_ST_MEASURE_VALUE:
    {
        ERR(D_Img_Proc::Split(
                &(vMA_Cells[c_ST_MEASURE_VALUE]),
                &(vMA_Cells[c_ST_MEASURE_HSV]),
                2),
            "Update_Step_Cells",
            "c_ST_MEASURE_VALUE");
    }
        break;

    case c_ST_MEASURE_VALUE_MASK:
    {
        ERR(D_Img_Proc::Math_ImgImg_BitAnd(
                &(vMA_Cells[c_ST_MEASURE_VALUE_MASK]),
                &(vMA_Cells[c_ST_MEASURE_VALUE]),
                &(vMA_Cells[c_ST_SEGM_BINARY])),
            "Update_Step_Cells",
            "c_ST_MEASURE_VALUE_MASK");
    }
        break;

    case c_ST_MEASURE_ABSORPTION:
    {
        ERR(D_Img_Proc::Spread_8bit_to_float01(
                &(vMA_Cells[c_ST_MEASURE_ABSORPTION]),
                &(vMA_Cells[c_ST_MEASURE_VALUE_MASK])),
            "Update_Step_Cells",
            "c_ST_MEASURE_ABSORPTION");
    }
        break;

    case c_ST_MEASURE_TRANSMISSON:
    {
        qDebug() << "Update_Step_Cells" << "c_ST_MEASURE_TRANSMISSON";
        ERR(D_Img_Proc::Math_ScalImg_Sub(
                &(vMA_Cells[c_ST_MEASURE_TRANSMISSON]),
                &(vMA_Cells[c_ST_MEASURE_ABSORPTION]),
                1.0),
            "Update_Step_Cells",
            "c_ST_MEASURE_TRANSMISSON");
    }
        break;

    case c_ST_MEASURE_CELL_COUNT:
    {
        qDebug() << "Update_Step_Cells" << "c_ST_MEASURE_CELL_COUNT" << "START================================";
/*
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Cells[c_ST_MEASURE_CELL_COUNT]),
                &(vMA_Cells[c_ST_MEASURE_TRANSMISSON])),
            "Update_Step_Cells",
            "c_ST_MEASURE_TRANSMISSON");
*/
        ERR(D_Img_Proc::Math_Special_Trans2Count(
                &(vMA_Cells[c_ST_MEASURE_CELL_COUNT]),
                &(vMA_Cells[c_ST_MEASURE_TRANSMISSON]),
                ui->doubleSpinBox_Measure_Base->value(),
                ui->doubleSpinBox_Measure_Factor->value()),
            "Update_Step_Cells",
            "c_ST_MEASURE_CELL_COUNT");

        qDebug() << "Update_Step_Cells" << "c_ST_MEASURE_CELL_COUNT" << "END==================================";
    }
        break;

    default:
        break;
    }
}

void D_MAKRO_CellColonies::Update_Step_Results(int step)
{
    if(!Loaded_FileInfos)
        return;

    switch (step) {

    case c_ST_C_RGB:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_C_RGB]),
                &(vMA_Cells[c_ST_INPUT_CROP])),
            "Update_Step_Results",
            "c_ST_C_RGB");
    }
        break;

    case c_ST_C_RGB_ANTISHADE:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_C_RGB_ANTISHADE]),
                &(vMA_Cells[c_ST_INPUT_ANTI_SHADE])),
            "Update_Step_Results",
            "c_ST_C_RGB_ANTISHADE");
    }
        break;

    case c_ST_C_RGB_DIFFERENCE:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_C_RGB_DIFFERENCE]),
                &(vMA_Cells[c_ST_MEASURE_DIFF])),
            "Update_Step_Results",
            "c_ST_C_RGB_DIFFERENCE");
    }
        break;

    case c_ST_C_HSV_INPUT:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_C_HSV_INPUT]),
                &(vMA_Cells[c_ST_SEED_HSV])),
            "Update_Step_Results",
            "c_ST_C_HSV_INPUT");
    }
        break;

    case c_ST_C_HSV_DIFFERENCE:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Results[c_ST_C_HSV_DIFFERENCE]),
                &(vMA_Cells[c_ST_MEASURE_HSV])),
            "Update_Step_Results",
            "c_ST_C_HSV_DIFFERENCE");
    }
        break;

    case c_ST_G_INPUT_SAT:
    {
        ERR(D_Img_Proc::Convert_Color(
                &(vMA_Results[c_ST_G_INPUT_SAT]),
                &(vMA_Cells[c_ST_SEED_SATURATION]),
                CV_GRAY2BGR),
            "Update_Step_Results",
            "c_ST_G_INPUT_SAT");
    }
        break;

    case c_ST_G_DIFF_VAL:
    {
        ERR(D_Img_Proc::Convert_Color(
                &(vMA_Results[c_ST_G_DIFF_VAL]),
                &(vMA_Cells[c_ST_MEASURE_VALUE]),
                CV_GRAY2BGR),
            "Update_Step_Results",
            "c_ST_G_DIFF_VAL");
    }
        break;

    case c_ST_B_EDGES:
    {
        ERR(D_Img_Proc::Reduce_Outlines(
                 &(vMA_Results[c_ST_B_EDGES]),
                 &(vMA_Cells[c_ST_SEGM_BINARY])),
            "Update_Step_Cells",
            "c_ST_SEGM_EDGES");

        ERR(D_Img_Proc::Convert_Color(
                &(vMA_Results[c_ST_B_EDGES]),
                &(vMA_Results[c_ST_B_EDGES]),
                CV_GRAY2BGR),
            "Update_Step_Results",
            "c_ST_B_EDGES");
    }
        break;

    case c_ST_B_NUMBERS:
    {
        ERR(D_Img_Proc::Draw_Label_Numbers(
                &(vMA_Results[c_ST_B_NUMBERS]),
                &(vMA_Cells[c_ST_SEGM_WATERSHED]),
                0.75,
                1,
                true));

        ERR(D_Img_Proc::Convert_Color(
                &(vMA_Results[c_ST_B_NUMBERS]),
                &(vMA_Results[c_ST_B_NUMBERS]),
                CV_GRAY2BGR),
            "Update_Step_Results",
            "c_ST_B_NUMBERS");
    }
        break;

    case c_ST_B_EDGES_NUMBERS:
    {
        ERR(D_Img_Proc::Math_ImgImg_BitOr(
                &(vMA_Results[c_ST_B_EDGES_NUMBERS]),
                &(vMA_Results[c_ST_B_EDGES]),
                &(vMA_Results[c_ST_B_NUMBERS])),
            "Update_Step_Results",
            "c_ST_B_EDGES_NUMBERS");
    }
        break;

    case c_ST_B_ROI_OUT:
    {
        ERR(D_Img_Proc::Convert_Color(
                &(vMA_Results[c_ST_B_ROI_OUT]),
                &(vMA_Cells[c_ST_SEGM_BINARY]),
                CV_GRAY2BGR),
            "Update_Step_Results",
            "c_ST_B_ROI");
    }
        break;

    case c_ST_B_ROI_IN:
    {
        ERR(D_Img_Proc::Math_ImgSelf_Not(
                &(vMA_Results[c_ST_B_ROI_IN]),
                &(vMA_Results[c_ST_B_ROI_OUT])),
            "Update_Step_Results",
            "c_ST_B_ROI_INV");
    }
        break;

    default:
        break;
    }
}

void D_MAKRO_CellColonies::Calc_All()
{
    if(!Loaded_FileInfos)
        return;

    Calc_Colony_Values_Split();
    Calc_Colony_Stats();
    Calc_Colony_Attributes();
    Calc_Image_Stats();
    Calc_Colony_Survival();
}

void D_MAKRO_CellColonies::Calc_Colony_Values_Split()
{
    if(!Loaded_FileInfos)
        return;

    //clear & resize
    Calced_TypColVal = false;
    vvvd_TypColVal.clear();
    vvvd_TypColVal.resize(c_TYP_NUMBER_OF);

    //Absorption---------------------------------------------------

    vector<vector<double>> ColAbs;

    ERR(D_Img_Proc::Split_img2vv_value(
                &ColAbs,
                &(vMA_Cells[c_ST_MEASURE_ABSORPTION]),
                &(vMA_Cells[c_ST_SEGM_WATERSHED]),
                false),
        "Calc_Colony_Values_Split",
        "Absorption");

    vvvd_TypColVal[c_TYP_ABS] = ColAbs;

    //Transmission---------------------------------------------------

    vector<vector<double>> ColTra;

    ERR(D_Img_Proc::Split_img2vv_value(
                &ColTra,
                &(vMA_Cells[c_ST_MEASURE_TRANSMISSON]),
                &(vMA_Cells[c_ST_SEGM_WATERSHED]),
                false),
        "Calc_Colony_Values_Split",
        "Transmission");

    vvvd_TypColVal[c_TYP_TRANS] = ColTra;


    //Transmssion radial----------------------------------------------

    D_Value_Distribution_List DistrList;

    ERR(DistrList.set_Mats(
            &(vMA_Cells[c_ST_SEGM_WATERSHED]),
            &(vMA_Cells[c_ST_MEASURE_TRANSMISSON])),
        "Calc_Colony_Values_Split",
        "Transmission Radial");

    DistrList.calc_All();

    //qDebug() << "Transmission Radial start export";
    vvvd_TypColVal[c_TYP_TRANS_RADIAL] = DistrList.get_Axe(c_AXE_POLAR_RADIUS, c_STAT_MEAN_ARITMETIC);
    //qDebug() << "Transmission Radial exported";

    //Cell Density-----------------------------------------------------

    vector<vector<double>> ColCel;

    ERR(D_Img_Proc::Split_img2vv_value(
                &ColCel,
                &(vMA_Cells[c_ST_MEASURE_CELL_COUNT]),
                &(vMA_Cells[c_ST_SEGM_WATERSHED]),
                false),
        "Calc_Colony_Values_Split",
        "Cell Density");


/*
    //qDebug() << "split cell count size" << ColCel.size();
    imshow("cell count image", vMA_Cells[c_ST_MEASURE_CELL_COUNT]);
    qDebug() << "v_ColCel size_col:" << ColCel.size();
    for(int col = 0; col < ColCel.size(); col++)
        qDebug() << "c_ColCel size_cel:" << ColCel[col].size();
*/

    vvvd_TypColVal[c_TYP_CELL_DENSITY] = ColCel;

    Calced_TypColVal = true;
}

void D_MAKRO_CellColonies::Calc_Colony_Stats()
{
    Calced_TypColSta = false;
    if(!Calced_TypColVal)
        return;

    //clear old content
    vvvd_TypColSta.clear();

    //types
    vvvd_TypColSta.resize(vvvd_TypColVal.size());
    for(int typ = 0; typ < vvvd_TypColSta.size(); typ++)
    {
        //colonies
        //qDebug() << "vvvd_TypColSta[typ].resize(vvvd_TypColVal[typ].size());" << "typ" << typ << vvvd_TypColVal[typ].size();
        vvvd_TypColSta[typ].resize(vvvd_TypColVal[typ].size());
        for(int col = 0; col < vvvd_TypColSta[typ].size(); col++)
        {
            //stats
            //vector<double> v_stats_single;

            int ER = D_Stat::Calc_Stats(
                        &vvvd_TypColSta[typ][col],
                        vvvd_TypColVal[typ][col],
                        true);

            if(ER != ER_okay)   qDebug() << "Calc_Colony_Stats: D_Stat::Calc_Stats error!" << "typ" << typ << "col" << col;

            //vvvd_TypColSta[typ][col] = v_stats_single;
        }
    }

    Calced_TypColSta = true;
}

void D_MAKRO_CellColonies::Calc_Colony_Attributes()
{
    Calced_AttCol_new = false;
    if(!Calced_TypColSta)
        return;

    //clear old content
    vvd_AttCol_new.clear();

    //attributes resize
    vvd_AttCol_new.resize(c_ATT_COUNT);
    for(int a = 0; a < c_ATT_COUNT; a++)
        vvd_AttCol_new[a].resize(vvvd_TypColSta[0].size());

    //colonies loop
    for(int c = 0; c < vvvd_TypColSta[0].size(); c++)
    {
        //qDebug() << "coloy" << c;
        double A = vvvd_TypColSta[c_TYP_ABS][c][c_STAT_COUNT];
        double R = sqrt(A / PI_2_0);
        double D = 2 * R;

        //qDebug() << "size";
        vvd_AttCol_new[c_ATT_SIZE_AREA][c]          = A;
        vvd_AttCol_new[c_ATT_SIZE_RADIUS][c]        = R;
        vvd_AttCol_new[c_ATT_SIZE_DIAMETER][c]      = D;

        //qDebug() << "abs";
        vvd_AttCol_new[c_ATT_ABSORB_MEAN][c]        = vvvd_TypColSta[c_TYP_ABS][c][c_STAT_MEAN_ARITMETIC];
        vvd_AttCol_new[c_ATT_ABSORB_MEDIAN][c]      = vvvd_TypColSta[c_TYP_ABS][c][c_STAT_MEDIAN];
        vvd_AttCol_new[c_ATT_ABSORB_SUM][c]         = vvvd_TypColSta[c_TYP_ABS][c][c_STAT_SUM];

        //qDebug() << "trans";
        vvd_AttCol_new[c_ATT_TRANS_MEAN][c]         = vvvd_TypColSta[c_TYP_TRANS][c][c_STAT_MEAN_ARITMETIC];
        vvd_AttCol_new[c_ATT_TRANS_MEDIAN][c]       = vvvd_TypColSta[c_TYP_TRANS][c][c_STAT_MEDIAN];
        vvd_AttCol_new[c_ATT_TRANS_SUM][c]          = vvvd_TypColSta[c_TYP_TRANS][c][c_STAT_SUM];

        //qDebug() << "trans_radial";
        vvd_AttCol_new[c_ATT_TRANS_RADIAL_MEAN][c]  = vvvd_TypColSta[c_TYP_TRANS_RADIAL][c][c_STAT_MEAN_ARITMETIC];
        vvd_AttCol_new[c_ATT_TRANS_RADIAL_MEDIAN][c]= vvvd_TypColSta[c_TYP_TRANS_RADIAL][c][c_STAT_MEDIAN];
        vvd_AttCol_new[c_ATT_TRANS_RADIAL_SUM][c]   = vvvd_TypColSta[c_TYP_TRANS_RADIAL][c][c_STAT_SUM];

        //qDebug() << "density";
        //qDebug() << "size typ"  << vvvd_TypColSta.size();
        //qDebug() << "size col"  << vvvd_TypColSta[c_TYP_CELL_DENSITY].size();
        //qDebug() << "size stat" << vvvd_TypColSta[c_TYP_CELL_DENSITY][c].size();
        vvd_AttCol_new[c_ATT_CELL_DENSITY_MEAN][c]  = vvvd_TypColSta[c_TYP_CELL_DENSITY][c][c_STAT_MEAN_ARITMETIC];
        vvd_AttCol_new[c_ATT_CELL_DENSITY_MEDIAN][c]= vvvd_TypColSta[c_TYP_CELL_DENSITY][c][c_STAT_MEDIAN];
        vvd_AttCol_new[c_ATT_CELL_DENSITY_SUM][c]   = vvvd_TypColSta[c_TYP_CELL_DENSITY][c][c_STAT_SUM];

        //qDebug() << "finish";
    }

    Calced_AttCol_new = true;
}

void D_MAKRO_CellColonies::Calc_Image_Stats()
{
    Calced_AttSta_new = false;
    if(!Calced_AttCol_new)
        return;

    //clear & resize
    vvd_AttSta_new.clear();
    vvd_AttSta_new.resize(vvd_AttCol_new.size());

    //loop attributes and calc stats
    for(int att = 0; att < vvd_AttSta_new.size(); att++)
        D_Stat::Calc_Stats(
                    &vvd_AttSta_new[att],
                    vvd_AttCol_new[att],
                    true);

    Calced_AttSta_new = true;
}

void D_MAKRO_CellColonies::Calc_Colony_Survival()
{
    Calced_ColSur_new = false;
    if(!Calced_AttCol_new)
        return;

    //clear & resize
    count_detected = 0;
    count_surrival = 0;
    vi_ColSur_new.clear();
    vi_ColSur_new.resize(vvvd_TypColSta[0].size());

    //loop colonies
    for(int col = 0; col < vi_ColSur_new.size(); col++)
    {
        vi_ColSur_new[col] = static_cast<int>(vvd_AttCol_new[c_ATT_CELL_DENSITY_SUM][col] >= ui->doubleSpinBox_Sur_CellCount->value());

        count_detected++;
        if(vi_ColSur_new[col])
            count_surrival++;
    }

    count_dead = count_detected - count_surrival;
    prz_surrival = static_cast<double>(count_surrival) / static_cast<double>(count_detected);
    prz_dead = 1.0 - prz_surrival;

    Calced_ColSur_new = true;

    Plot_Colony_Surrival();
}

void D_MAKRO_CellColonies::Plot_Histogram_Colonies()
{
    if(!Calced_TypColVal)
        return;

    vector<vector<double>>  vv_hist;
    double                  min_x;
    double                  max_x;
    double                  max_y;
    double                  step;

    ERR(D_Stat::Calc_Vector2Hist_2(
            &vv_hist,
            &(vvvd_TypColVal[ui->comboBox_ResPlo_HisCol_Typ->currentIndex()]),
            ui->spinBox_ResPlo_HisCol_ClassCount->value(),
            &min_x,
            &max_x,
            &max_y,
            &step,
            ui->checkBox_ResPlo_HisCol_Accumulate->isChecked(),
            ui->checkBox_ResPlo_HisCol_Uniform->isChecked()));

    ERR(D_Plot::Plot_Hist_Multi_Classes(
            pChartView_Colony,
            &vv_hist,
            min_x,
            max_x,
            max_y,
            step,
            "<b>" + QS_BaseName_Current + "</b><br>" + ui->comboBox_ResPlo_HisCol_Typ->currentText(),
            "Colony_",
            "Value",
            "Amount",
            false));

    pChartView_Colony->chart()->legend()->setAlignment(Qt::AlignLeft);

    qDebug() << "Plot_Histogram_Colonies";
}

void D_MAKRO_CellColonies::Plot_Stat_Compare()
{
    if(!Calced_TypColSta)
        return;

    //Init_Plot();

    //get parameters
    QString         name_title  = QS_BaseName_Current;
    QString         x_name      = ui->comboBox_ResPlo_StatComp_X_Typ->currentText() + " - " + ui->comboBox_ResPlo_StatComp_X_Stat->currentText();
    QString         y_name      = ui->comboBox_ResPlo_StatComp_Y_Typ->currentText() + " - " + ui->comboBox_ResPlo_StatComp_Y_Stat->currentText();
    unsigned int    x_par       = ui->comboBox_ResPlo_StatComp_X_Typ->currentIndex();
    unsigned int    y_par       = ui->comboBox_ResPlo_StatComp_Y_Typ->currentIndex();
    unsigned int    x_stat      = ui->comboBox_ResPlo_StatComp_X_Stat->currentIndex();
    unsigned int    y_stat      = ui->comboBox_ResPlo_StatComp_Y_Stat->currentIndex();

    //plot
    int ER = D_Plot::Plot_Stat_Multi_Custom(
                pChartView_Colony,
                &vvvd_TypColSta,
                x_par,
                y_par,
                x_stat,
                y_stat,
                name_title,
                "Cell-Colonies",
                x_name,
                y_name);

    ERR(ER, "Plot_Stat_Compare", "Plot_Stat_Multi_Custom");
}

void D_MAKRO_CellColonies::Plot_MM_Colonies()
{
    if(!Calced_TypColSta)
        return;

    ERR(D_Plot::Plot_Stat_Multi_MeanMedian(
            pChartView_Colony,
            &(vvvd_TypColSta[ui->comboBox_ResPlo_MM_Typ->currentIndex()]),
            ui->checkBox_ResPlo_MM_Mean->isChecked(),
            ui->checkBox_ResPlo_MM_SD->isChecked(),
            ui->checkBox_ResPlo_MM_Median->isChecked(),
            ui->checkBox_ResPlo_MM_ADM->isChecked(),
            "<b>" + QS_BaseName_Current + "</b><br>" + ui->comboBox_ResPlo_MM_Typ->currentText(),
            "Cell-Colonies",
            "Intensitiy (0 to 1)"));
}

void D_MAKRO_CellColonies::Plot_CSK_Colonies()
{
    if(!Calced_TypColSta)
        return;

    ERR(D_Plot::Plot_Stat_Multi_CvSkewKurt(
            pChartView_Colony,
            &(vvvd_TypColSta[ui->comboBox_ResPlo_CSK_Typ->currentIndex()]),
            ui->checkBox_ResPlo_CSK_CV->isChecked(),
            ui->checkBox_ResPlo_CSK_Skewness->isChecked(),
            ui->checkBox_ResPlo_CSK_Kurtosis->isChecked(),
            "<b>" + QS_BaseName_Current + "</b><br>" + ui->comboBox_ResPlo_CSK_Typ->currentText(),
            "Cell-Colonies",
            "1"));
}

void D_MAKRO_CellColonies::Plot_Quantiles_Colonies()
{
    if(!Calced_TypColSta)
        return;

    ERR(D_Plot::Plot_Stat_Multi_Quantiles(
            pChartView_Colony,
            &(vvvd_TypColSta[ui->comboBox_ResPlo_Quant_Typ->currentIndex()]),
            ui->comboBox_ResPlo_Quant_Steps->currentIndex(),
            "<b>" + QS_BaseName_Current + "</b><br>" + ui->comboBox_ResPlo_Quant_Typ->currentText(),
            "Cell-Colonies",
        "Relative Position in Value Range"));
}

void D_MAKRO_CellColonies::Plot_Histogram_Image()
{
    if(!Calced_AttCol_new)
        return;

    vector<double>  v_hist;
    double          min_x;
    double          max_x;
    double          max_y;
    double          step;

     int ER = D_Stat::Calc_Vector2Hist_1(
            &v_hist,
            &(vvd_AttCol_new[ui->comboBox_ResPlo_HisImg_Attribute->currentIndex()]),
            ui->spinBox_ResPlo_HisImg_ClassCount->value(),
            &min_x,
            &max_x,
            &max_y,
            &step,
            ui->checkBox_ResPlo_HisImg_Accumulate->isChecked(),
            ui->checkBox_ResPlo_HisImg_Uniform->isChecked());

    ERR(ER);
    if(ER != ER_okay)
        return;

    D_Plot::Plot_Hist_Single_Classes(
                pChartView_Image,
                &v_hist,
                min_x,
                step,
                QS_BaseName_Current,
                ui->comboBox_ResPlo_HisImg_Attribute->currentText(),
                "Value (Attribute of colony: " + ui->comboBox_ResPlo_HisImg_Attribute->currentText() + ")",
                "Amount (of Colonies)",
                false);

    qDebug() << "Plot_Histogram_Image";
}

void D_MAKRO_CellColonies::Plot_Attribute_Compare()
{
    if(!Calced_AttCol_new)
        return;

    QString         series_name = "Cell-Colonies";
    QString         x_name      = ui->comboBox_ResPlo_StatComp_Img_X_Attribute->currentText();
    QString         y_name      = ui->comboBox_ResPlo_StatComp_Img_Y_Attribute->currentText();
    unsigned int    x_att       = ui->comboBox_ResPlo_StatComp_Img_X_Attribute->currentIndex();
    unsigned int    y_att       = ui->comboBox_ResPlo_StatComp_Img_Y_Attribute->currentIndex();

    ERR(D_Plot::Plot_Scatter_2D_Parameter(
                pChartView_Image,
                &vvd_AttCol_new,
                x_att,
                y_att,
                QS_BaseName_Current,
                series_name,
                x_name,
                y_name),
        "Plot_Attribute_Compare",
        "Plot_Scatter_2D_Parameter");
}

void D_MAKRO_CellColonies::Plot_Colony_Surrival()
{
    if(!Calced_ColSur_new)
        return;

    QS_BaseName_Current = FIL_Input_Images[ui->comboBox_ProcView_Image->currentIndex()].baseName();

    ui->label_ResPloSur_count_detected->setText(QString::number(count_detected));
    ui->label_ResPloSur_count_surrival->setText(QString::number(count_surrival));
    ui->label_ResPloSur_count_dead->setText(QString::number(count_dead));
    ui->label_ResPloSur_prz_surrival->setText(QString::number(prz_surrival * 100, 'g', 4) + "%");
    ui->label_ResPloSur_prz_dead->setText(QString::number(prz_dead * 100, 'g', 4) + "%");

    ERR(D_Plot::Plot_Pie_Surrival(
            pChartView_Surrival,
            count_surrival,
            count_dead,
            QS_BaseName_Current));
}

void D_MAKRO_CellColonies::Plot_Radial_Transmission_Colony()
{
    if(!Calced_TypColVal)
        return;

    ERR(D_Plot::Plot_Line_XY_Multi(
            pChartView_Colony,
            vvvd_TypColVal[c_TYP_TRANS_RADIAL],
            QS_BaseName_Current,
            "Mean Transmission vs Radius",
            "Radius",
            "Mean Transmission"),
        "Plot_Radial_Transmission_Colony",
        "PLotting");

    pChartView_Colony->chart()->legend()->setAlignment(Qt::AlignLeft);
    pChartView_Colony->chart()->axisY()->setMin(0);
    pChartView_Colony->chart()->axisY()->setMax(1);
}

void D_MAKRO_CellColonies::Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(index_init);
    CB->blockSignals(false);
}

void D_MAKRO_CellColonies::Populate_CB_Stat()
{
    Populate_CB_Single(ui->comboBox_ResPlo_StatComp_X_Stat, QSL_StatList, c_STAT_MEAN_ARITMETIC);
    Populate_CB_Single(ui->comboBox_ResPlo_StatComp_Y_Stat, QSL_StatList, c_STAT_MEAN_ARITMETIC);
}

void D_MAKRO_CellColonies::Populate_CB_Attribute()
{
    ui->comboBox_ResPlo_HisImg_Attribute->clear();
    ui->comboBox_ResPlo_StatComp_Img_X_Attribute->clear();
    ui->comboBox_ResPlo_StatComp_Img_Y_Attribute->clear();

    ui->comboBox_ResPlo_HisImg_Attribute->addItems(QSL_Attrib);
    ui->comboBox_ResPlo_StatComp_Img_X_Attribute->addItems(QSL_Attrib);
    ui->comboBox_ResPlo_StatComp_Img_Y_Attribute->addItems(QSL_Attrib);
    ui->comboBox_ResAtt_Attribute->addItems(QSL_Attrib);
}

void D_MAKRO_CellColonies::Populate_CB_Typ()
{
    ui->comboBox_ResPlo_HisCol_Typ->addItems(QSL_Types);
    ui->comboBox_ResPlo_StatComp_X_Typ->addItems(QSL_Types);
    ui->comboBox_ResPlo_StatComp_Y_Typ->addItems(QSL_Types);
    ui->comboBox_ResPlo_MM_Typ->addItems(QSL_Types);
    ui->comboBox_ResPlo_CSK_Typ->addItems(QSL_Types);
    ui->comboBox_ResPlo_Quant_Typ->addItems(QSL_Types);
}

void D_MAKRO_CellColonies::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_MAKRO_CellColonies", func, detail);
}

void D_MAKRO_CellColonies::on_doubleSpinBox_ProcCon_ROI_X1_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_REFERENCE_CROP);
}

void D_MAKRO_CellColonies::on_doubleSpinBox_ProcCon_ROI_Y1_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_REFERENCE_CROP);
}

void D_MAKRO_CellColonies::on_doubleSpinBox_ProcCon_ROI_X2_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_REFERENCE_CROP);
}

void D_MAKRO_CellColonies::on_doubleSpinBox_ProcCon_ROI_Y2_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_REFERENCE_CROP);
}

void D_MAKRO_CellColonies::on_spinBox_ProcCon_ColGrab_H_Min_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_CELLS_GRAB_COLOR);
}

void D_MAKRO_CellColonies::on_spinBox_ProcCon_ColGrab_S_Min_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_CELLS_GRAB_COLOR);
}

void D_MAKRO_CellColonies::on_spinBox_ProcCon_ColGrab_V_Min_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_CELLS_GRAB_COLOR);
}

void D_MAKRO_CellColonies::on_spinBox_ProcCon_ColGrab_H_Max_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_CELLS_GRAB_COLOR);
}

void D_MAKRO_CellColonies::on_spinBox_ProcCon_ColGrab_S_Max_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_CELLS_GRAB_COLOR);
}

void D_MAKRO_CellColonies::on_spinBox_ProcCon_ColGrab_V_Max_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_CELLS_GRAB_COLOR);
}

void D_MAKRO_CellColonies::on_spinBox_ProcCon_CellCol_Black_Noise_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_CELLS_NOISE_BLACK);
}

void D_MAKRO_CellColonies::on_spinBox_ProcCon_CellCol_White_Noise_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_CELLS_NOISE_WHITE);
}

void D_MAKRO_CellColonies::on_spinBox_ProcCon_Seed_Blur_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_SEED_BLUR);
}

void D_MAKRO_CellColonies::on_doubleSpinBox_ProcCon_Seed_Blur_Sigma_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_SEED_BLUR);
}

void D_MAKRO_CellColonies::on_spinBox_ProcCon_Thres_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_SEED_THRESH);
}

void D_MAKRO_CellColonies::on_doubleSpinBox_ProcCon_Thres_Offset_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_SEED_THRESH);
}

void D_MAKRO_CellColonies::on_spinBox_ProcCon_Seed_Open_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_SEED_OPEN);
}

void D_MAKRO_CellColonies::on_checkBox_ProcCon_Watershed_Border_stateChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_SEGM_WATERSHED);
}

void D_MAKRO_CellColonies::on_checkBox_ProcCon_Watershed_nSeed_stateChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_SEGM_WATERSHED);
}

void D_MAKRO_CellColonies::on_action_Last_Image_triggered()
{
    if(!Loaded_FileInfos)
        return;

    int index = ui->comboBox_ProcView_Image->currentIndex();

    if(index > 0)
        ui->comboBox_ProcView_Image->setCurrentIndex(index - 1);
}

void D_MAKRO_CellColonies::on_action_Next_Image_triggered()
{
    if(!Loaded_FileInfos)
        return;

    int index = ui->comboBox_ProcView_Image->currentIndex();

    if(index < FIL_Input_Images.size() - 1)
        ui->comboBox_ProcView_Image->setCurrentIndex(index + 1);
}

void D_MAKRO_CellColonies::Init_Plot()
{
    delete ui->gridLayout_ResPlo->takeAt(0);
    pChartView_Colony = new QChartView();
    ui->gridLayout_ResPlo->addWidget(pChartView_Colony);
    pChartView_Colony->setRenderHint(QPainter::Antialiasing);
    pChartView_Colony->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Colony->setInteractive(true);

    delete ui->gridLayout_ResPlo_Img->takeAt(0);
    pChartView_Image = new QChartView();
    ui->gridLayout_ResPlo_Img->addWidget(pChartView_Image);
    pChartView_Image->setRenderHint(QPainter::Antialiasing);
    pChartView_Image->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Image->setInteractive(true);

    delete ui->gridLayout_ResPlo_Surrival->takeAt(0);
    pChartView_Surrival = new QChartView();
    ui->gridLayout_ResPlo_Surrival->addWidget(pChartView_Surrival);
    pChartView_Surrival->setRenderHint(QPainter::Antialiasing);
    //pChartView_Surrival->setRubberBand(QChartView::RectangleRubberBand);
    //pChartView_Surrival->setInteractive(true);
}

void D_MAKRO_CellColonies::on_comboBox_ProcView_Image_currentIndexChanged(const QString &arg1)
{
    QS_BaseName_Current = arg1;
}

void D_MAKRO_CellColonies::on_spinBox_ProcCon_Ref_Blur_Size_valueChanged(int arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_REFERENCE_BLUR);
}

void D_MAKRO_CellColonies::on_doubleSpinBox_ProcCon_Ref_Blur_Sigma_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_REFERENCE_BLUR);
}

void D_MAKRO_CellColonies::on_doubleSpinBox_Extract_Asphere_Thres_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_SEED_ASPH_EXTRACT);
}

void D_MAKRO_CellColonies::on_doubleSpinBox_Separtate_Asphere_Thres_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_SEED_ASPH_SEPARATE);
}

void D_MAKRO_CellColonies::on_doubleSpinBox_Measure_Base_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_MEASURE_CELL_COUNT);
}

void D_MAKRO_CellColonies::on_doubleSpinBox_Measure_Factor_valueChanged(double arg1)
{
    arg1;
    Update_ImgProc_Cells(c_ST_MEASURE_CELL_COUNT);
}

void D_MAKRO_CellColonies::on_doubleSpinBox_Sur_CellCount_valueChanged(double arg1)
{
    arg1;
    Calc_Colony_Survival();
    Update_Results();
}

