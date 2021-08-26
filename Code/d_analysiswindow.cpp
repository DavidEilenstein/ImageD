/************************************
 *   added:     17.12.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_analysiswindow.h"
#include "ui_d_analysiswindow.h"

/*!
 * \brief D_AnalysisWindow::D_AnalysisWindow Constructor.
 * \param pStorage Pointer to D_Storage Object where image of D_StepWindow are saved. Used to get images from.
 * \param parent
 */
D_AnalysisWindow::D_AnalysisWindow(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_AnalysisWindow)
{
    //Ui
    ui->setupUi(this);
    Populate_CB();

    //share storage
    pStore = pStorage;

    //Storage init
    vMA_Images.resize(1);
    for(int i = 0; i < vMA_Images.size(); i++)
        vMA_Images[i] = pStore->get_Adress(0)->clone();

    vMA_Images_8bit.resize(1);
    for(int i = 0; i < vMA_Images_8bit.size(); i++)
        vMA_Images_8bit[i] = pStore->get_Adress(0)->clone();

    MA_Binary   = pStore->get_Adress(0)->clone();
    MA_Features = pStore->get_Adress(0)->clone();
    MA_Label    = pStore->get_Adress(0)->clone();
    MA_Stats    = pStore->get_Adress(0)->clone();


    //Viewer
    Viewer_Image.set_GV(ui->graphicsView_Image);
    Viewer_Image.set_Name("Label");
    Viewer_Image.Set_Transformation_Mode(true);

    //Table
    Table_PlottedData.set_TW(ui->tableWidget_PlottedData);

    //Plot
    Init_Plot();

    //CONNECTS
    //Rename
    connect(ui->action_Rename_Image,                            SIGNAL(triggered(bool)),                    this,                       SLOT(Rename_Image()));
    connect(ui->action_Rename_Component,                        SIGNAL(triggered(bool)),                    this,                       SLOT(Rename_Component()));

    //Get Images
    connect(ui->pushButton_ImgLab_GetImage,                     SIGNAL(clicked(bool)),                      this,                       SLOT(Image_Label_Get()));
    connect(ui->pushButton_ImgVal_AddImage,                     SIGNAL(clicked(bool)),                      this,                       SLOT(Image_Value_Add_Dialog()));
    connect(ui->pushButton_ImgVal_Clear,                        SIGNAL(clicked(bool)),                      this,                       SLOT(Image_Value_Clear()));

    //Save
    connect(ui->action_Save_Image,                              SIGNAL(triggered(bool)),                    this,                       SLOT(Save_Image()));
    connect(ui->action_Save_Plot,                               SIGNAL(triggered(bool)),                    this,                       SLOT(Save_Plot()));
    connect(ui->action_Save_Table,                              SIGNAL(triggered(bool)),                    this,                       SLOT(Save_Table()));
    connect(ui->action_Save_Image_Plot_Table,                   SIGNAL(triggered(bool)),                    this,                       SLOT(Save_ImagePlotTable()));

    //View
    connect(ui->action_Update_Views,                            SIGNAL(triggered(bool)),                    this,                       SLOT(Update_Views()));
    connect(&Viewer_Image,                                      SIGNAL(TypeChanged_MA(QString)),            ui->label_Img_Type_MA,      SLOT(setText(QString)));
    connect(&Viewer_Image,                                      SIGNAL(TypeChanged_QI(QString)),            ui->label_Img_Type_QI,      SLOT(setText(QString)));
    connect(&Viewer_Image,                                      SIGNAL(Scaled_Factor_Prz(QString)),         ui->label_Img_Scale,        SLOT(setText(QString)));
    connect(&Viewer_Image,                                      SIGNAL(MouseMoved_Value(QString)),          ui->label_Img_ValueAtPos,   SLOT(setText(QString)));
    connect(&Viewer_Image,                                      SIGNAL(Image_Size_Changed(QString)),        ui->label_Img_Size,         SLOT(setText(QString)));
    connect(ui->action_Smooth_Transformation,                   SIGNAL(triggered(bool)),                    &Viewer_Image,              SLOT(Set_Transformation_Mode(bool)));
    connect(ui->action_Keep_Aspect_Ratio,                       SIGNAL(triggered(bool)),                    &Viewer_Image,              SLOT(Set_Aspect_Mode(bool)));
    connect(ui->checkBox_Plot_X_Range,                          SIGNAL(clicked(bool)),                      this,                       SLOT(Update_View_Plot()));
    connect(ui->checkBox_Plot_Y_Range,                          SIGNAL(clicked(bool)),                      this,                       SLOT(Update_View_Plot()));
    connect(ui->doubleSpinBox_Plot_X_Min,                       SIGNAL(valueChanged(double)),               this,                       SLOT(Update_View_Plot()));
    connect(ui->doubleSpinBox_Plot_X_Max,                       SIGNAL(valueChanged(double)),               this,                       SLOT(Update_View_Plot()));
    connect(ui->doubleSpinBox_Plot_Y_Min,                       SIGNAL(valueChanged(double)),               this,                       SLOT(Update_View_Plot()));
    connect(ui->doubleSpinBox_Plot_Y_Max,                       SIGNAL(valueChanged(double)),               this,                       SLOT(Update_View_Plot()));

    //Images
    connect(ui->tabWidget_Images,                               SIGNAL(currentChanged(int)),                this,                       SLOT(Update_Images()));
    //Label
    //Value
    connect(ui->comboBox_ImgVal_Image,                          SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Image_Value()));
    //Feature
    connect(ui->comboBox_ImgFea_BaseImage,                      SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Image_Feature()));
    connect(ui->comboBox_ImgFea_Feature,                        SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Image_Feature()));
    connect(ui->comboBox_ImgFea_Geometric,                      SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Image_Feature()));
    connect(ui->spinBox_ImgFea_Precision,                       SIGNAL(valueChanged(int)),                  this,                       SLOT(Update_Image_Feature()));
    connect(ui->spinBox_ImgFea_Thickness,                       SIGNAL(valueChanged(int)),                  this,                       SLOT(Update_Image_Feature()));
    connect(ui->doubleSpinBox_ImgFea_Scale,                     SIGNAL(valueChanged(double)),               this,                       SLOT(Update_Image_Feature()));
    //Stat
    connect(ui->comboBox_ImgSta_Image,                          SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Image_Stat()));
    connect(ui->comboBox_ImgSta_Stat,                           SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Image_Stat()));
    connect(ui->comboBox_ImgSta_Geometric,                      SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Image_Stat()));
    connect(ui->spinBox_ImgSta_Precision,                       SIGNAL(valueChanged(int)),                  this,                       SLOT(Update_Image_Stat()));
    connect(ui->spinBox_ImgSta_Thickness,                       SIGNAL(valueChanged(int)),                  this,                       SLOT(Update_Image_Stat()));
    connect(ui->doubleSpinBox_ImgSta_Scale,                     SIGNAL(valueChanged(double)),               this,                       SLOT(Update_Image_Stat()));


    //Plot
    connect(ui->tabWidget_Plots,                                SIGNAL(currentChanged(int)),                this,                       SLOT(Update_Plot()));

    //Pixel-Plot
    connect(ui->comboBox_PlotPixel_Type,                        SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    //Pixel-Plot Hist
    connect(ui->comboBox_PlotPixel_Hist_Mode,                   SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_Hist_Image,                  SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_Hist_Component,              SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->checkBox_PlotPixel_Hist_Accumulate,             SIGNAL(clicked(bool)),                      this,                       SLOT(Update_Plot()));
    connect(ui->checkBox_PlotPixel_Hist_Uniform,                SIGNAL(clicked(bool)),                      this,                       SLOT(Update_Plot()));
    connect(ui->spinBox_PlotPixel_Hist_Classes,                 SIGNAL(valueChanged(int)),                  this,                       SLOT(Update_Plot()));
    //Pixel-Plot Axis
    connect(ui->comboBox_PlotPixel_Axe_Mode,                    SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_Axe_Axis,                    SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_Axe_Component,               SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_Axe_Image,                   SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_Axe_Stat,                    SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    //Pixel-Plot Scatter Values
    connect(ui->comboBox_PlotPixel_ScatterValue_Mode,           SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_ScatterValue_Image_X,        SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_ScatterValue_Image_Y,        SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_ScatterValue_Component,      SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    //Pixel-Plot Scatter Hist
    connect(ui->comboBox_PlotPixel_ScatterHist_Mode,            SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_ScatterHist_Image_X,         SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_ScatterHist_Image_Y,         SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_ScatterHist_Component_X,     SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_ScatterHist_Component_Y,     SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->checkBox_PlotPixel_ScatterHist_Uniform,         SIGNAL(clicked(bool)),                      this,                       SLOT(Update_Plot()));
    connect(ui->checkBox_PlotPixel_ScatterHist_Accumulate,      SIGNAL(clicked(bool)),                      this,                       SLOT(Update_Plot()));
    connect(ui->spinBox_PlotPixel_ScatterHist_Classes,          SIGNAL(valueChanged(int)),                  this,                       SLOT(Update_Plot()));
    //Pixel-Plot Scatter Axe
    connect(ui->comboBox_PlotPixel_ScatterAxe_Mode,             SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_ScatterAxe_Image_X,          SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_ScatterAxe_Image_Y,          SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_ScatterAxe_Component,        SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_ScatterAxe_Stat_X,           SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_ScatterAxe_Stat_Y,           SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotPixel_ScatterAxe_Axis,             SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));   

    //Component-Plot
    connect(ui->comboBox_PlotComp_Type,                         SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    //Component-Plot Feature
    connect(ui->comboBox_PlotComp_Feat_Feature,                 SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    //Component-Plot Feature Histogram
    connect(ui->comboBox_PlotComp_FeatHist_Feature,             SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->checkBox_PlotComp_FeatHist_Uniform,             SIGNAL(clicked(bool)),                      this,                       SLOT(Update_Plot()));
    connect(ui->checkBox_PlotComp_FeatHist_Accumulate,          SIGNAL(clicked(bool)),                      this,                       SLOT(Update_Plot()));
    connect(ui->spinBox_PlotComp_FeatHist_Classes,              SIGNAL(valueChanged(int)),                  this,                       SLOT(Update_Plot()));
    //Component-Plot Feature
    connect(ui->comboBox_PlotComp_FeatScatter_Feature_X,        SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotComp_FeatScatter_Feature_Y,        SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    //Component-Plot Statistics
    connect(ui->comboBox_PlotComp_Stat_Mode,                    SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotComp_Stat_Image,                   SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotComp_Stat_Stat,                    SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    //Component-Plot Statistics Histogram
    connect(ui->comboBox_PlotComp_StatHist_Mode,                SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotComp_StatHist_Image,               SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotComp_StatHist_Stat,                SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->checkBox_PlotComp_StatHist_Uniform,             SIGNAL(clicked(bool)),                      this,                       SLOT(Update_Plot()));
    connect(ui->checkBox_PlotComp_StatHist_Accumulate,          SIGNAL(clicked(bool)),                      this,                       SLOT(Update_Plot()));
    connect(ui->spinBox_PlotComp_StatHist_Classes,              SIGNAL(valueChanged(int)),                  this,                       SLOT(Update_Plot()));
    //Component-Plot Statistics Scatter
    connect(ui->comboBox_PlotComp_StatScatter_Mode,             SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotComp_StatScatter_Image_X,          SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotComp_StatScatter_Image_Y,          SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotComp_StatScatter_Stat_X,           SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotComp_StatScatter_Stat_Y,           SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    //Component-Plot Statistics-Feature Scatter
    connect(ui->comboBox_PlotComp_StatFeatScatter_Mode,         SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotComp_StatFeatScatter_Feature_X,    SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotComp_StatFeatScatter_Image_Y,      SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotComp_StatFeatScatter_Stat_Y,       SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));

    //Image-Plot
    connect(ui->comboBox_PlotImg_Type,                          SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    //Component-Plot Feature Histogram
    connect(ui->comboBox_PlotImg_FeatHist_Feature,              SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->checkBox_PlotImg_FeatHist_Uni,                  SIGNAL(clicked(bool)),                      this,                       SLOT(Update_Plot()));
    connect(ui->checkBox_PlotImg_FeatHist_Acc,                  SIGNAL(clicked(bool)),                      this,                       SLOT(Update_Plot()));
    connect(ui->spinBox_PlotImg_FeatHist_Classes,               SIGNAL(valueChanged(int)),                  this,                       SLOT(Update_Plot()));
    //Component-Plot Statistics
    connect(ui->comboBox_PlotImg_Stat_StatImg,                  SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotImg_Stat_StatComp,                 SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    //Component-Plot Statistics Histogram
    connect(ui->comboBox_PlotImg_StatHist_StatImg,              SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotImg_StatHist_StatComp,             SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->checkBox_PlotImg_StatHist_Uni,                  SIGNAL(clicked(bool)),                      this,                       SLOT(Update_Plot()));
    connect(ui->checkBox_PlotImg_StatHist_Acc,                  SIGNAL(clicked(bool)),                      this,                       SLOT(Update_Plot()));
    connect(ui->spinBox_PlotImg_StatHist_Classes,               SIGNAL(valueChanged(int)),                  this,                       SLOT(Update_Plot()));
    //Component-Plot Statistics Scatter
    connect(ui->comboBox_PlotImg_StatScatter_StatImg_X,         SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotImg_StatScatter_StatImg_Y,         SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotImg_StatScatter_StatComp_X,        SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotImg_StatScatter_StatComp_Y,        SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    //Component-Plot Statistics-Feature Scatter
    connect(ui->comboBox_PlotImg_StatFeatScatter_FeatComp_X,    SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotImg_StatFeatScatter_StatImg_X,     SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotImg_StatFeatScatter_StatImg_Y,     SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotImg_StatFeatScatter_StatComp_Y,    SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));

    //Stack-Plot
    connect(ui->comboBox_PlotStack_Type,                        SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    //Stats
    connect(ui->comboBox_PlotStack_Stat_StatComp,               SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));
    connect(ui->comboBox_PlotStack_Stat_StatImg,                SIGNAL(currentIndexChanged(int)),           this,                       SLOT(Update_Plot()));


    //Stuff on start up
    Update_Images();
    Image_Label_Get();

    setWindowTitle("ImageD - Analyzer");
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
}

/*!
 * \brief D_AnalysisWindow::~D_AnalysisWindow Destructor
 */
D_AnalysisWindow::~D_AnalysisWindow()
{
    delete ui;
}

/*!
 * \brief D_AnalysisWindow::resizeEvent called when window is resized and resizes the D_Viewer s.
 * \param event
 */
void D_AnalysisWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    Update_Views();
}

/*!
 * \brief D_AnalysisWindow::Image_Label_Get Opens a dialog to select the label image for the analysis. This image is used to determine where the blobs are.
 */
void D_AnalysisWindow::Image_Label_Get()
{
    bool ok;
    int lab_pos = QInputDialog::getInt(
                this,
                tr("Get Label Image"),
                tr("Chose the step with the labels (CV_16UC1 or CV_32SC1) you want to use:<br>"),
                pStore->size() - 1,
                0,
                pStore->size() - 1,
                1,
                &ok);
    if(!ok)
        return;

    if((pStore->get_Adress(lab_pos)->type() != CV_16UC1) && (pStore->get_Adress(lab_pos)->type() != CV_32SC1))
    {
        ERR(
                    ER_type_bad,
                    "Image_Label_Get",
                    "Please chose a CV_16UC1 or CV_32SC1 as label image instead");
        return;
    }

    int ER = D_Img_Proc::Duplicate(
                &MA_Label,
                pStore->get_Adress(lab_pos));
    ERR(
                ER,
                "Image_Label_Get",
                "Copy label image");
    if(ER != ER_okay) return;

    b_LabelLoaded = true;

    Init_ComponentNames();
    Populate_CB_ComponentNames();
    Update_Image_Label();
    Image_Value_Clear();

    //if succsessfull, automatically ask for value images
    ui->tabWidget_Images->setCurrentIndex(1);
    Image_Value_Add_Dialog();
}

void D_AnalysisWindow::Image_Binary_Add()
{
    if(!b_LabelLoaded)
        return;

    int ER;

    ER = D_Img_Proc::Threshold_Relative_1C(
                &MA_Binary,
                &MA_Label,
                0,
                0);
    ERR(
                ER,
                "Get_Images",
                "Create Binary");
    if(ER != ER_okay) return;

    ER = D_Img_Proc::Math_ImgScal_Div(
                &MA_Binary,
                &MA_Binary,
                255);
    ERR(
                ER,
                "Get_Images",
                "Make Foreground 1");
    if(ER != ER_okay) return;

    Image_Value_Add(&MA_Binary, "Binary");
}

void D_AnalysisWindow::Image_Value_Add_Dialog()
{
    if(!b_LabelLoaded)
    {
        ERR(
                    ER_empty,
                    "Image_Value_Add_Dialog",
                    "Please add a label image first");
        return;
    }

    //--------------------------------------------------------------------------------------
    bool ok;

    int val_pos = QInputDialog::getInt(
                this,
                tr("Get Value Image"),
                tr("Chose the step with the value image you want to add:<br>"),
                pStore->size() - 1,
                0,
                pStore->size() - 1,
                1,
                &ok);
    if(!ok)
        return;

    QString val_name = QInputDialog::getText(
                this,
                tr("Name Value Image"),
                tr("Chose a name for the chosen image"),
                QLineEdit::Normal,
                QString("Image_" + QString::number(vMA_Images.size())),
                &ok);
    if(!ok)
        return;

    //error handler
    int ER;

    //add all channels----------------------------------------------------------------

    for(int ch = 0; ch < pStore->get_Adress(val_pos)->channels(); ch++)
    {
        Mat MA_tmp_channel;
        ER = D_Img_Proc::Split(
                    &MA_tmp_channel,
                    pStore->get_Adress(val_pos),
                    ch);
        ERR(
                    ER,
                    "Image_Value_Add_Dialog",
                    "Split channels");
        if(ER != ER_okay) return;

        if(pStore->get_Adress(val_pos)->channels() == 1)
        {
            Image_Value_Add(
                        &MA_tmp_channel,
                        val_name);
        }
        else
        {
            Image_Value_Add(
                        &MA_tmp_channel,
                        val_name + "_" + QString::number(ch));
        }
    }
}

void D_AnalysisWindow::Image_Value_Add(Mat *pMA_add, QString name)
{
    if(!b_LabelLoaded)
        return;

    if(pMA_add->channels() != 1)
    {
        ERR(
                    ER_channel_bad,
                    "Image_Value_Add",
                    "Please don't add multi channel images to value vector of images.");
        return;
    }

    if(pMA_add->size != MA_Label.size)
    {
        ERR(
                    ER_size_missmatch,
                    "Image_Value_Add",
                    "Sizes of added value image and label image missmatch.");
        return;
    }

    //error code
    int ER;

    //convert to double
    Mat MA_tmp_double;
    ER = D_Img_Proc::Convert_Depth_NoScaling(
                &MA_tmp_double,
                pMA_add,
                CV_64F);
    ERR(
                ER,
                "Image_Value_Add",
                "Convert added image to double");
    if(ER != ER_okay) return;


    //convert to 8bit
    Mat MA_tmp_8bit;
    ER = D_Img_Proc::Normalize(
                &MA_tmp_8bit,
                pMA_add,
                CV_MINMAX,
                CV_8U,
                0,
                255);
    ERR(
                ER,
                "Image_Value_Add",
                "Convert added image to 8bit");
    if(ER != ER_okay) return;

    //if conv sucsessful, add stuff
    vMA_Images.push_back(MA_tmp_double);
    vMA_Images_8bit.push_back(MA_tmp_8bit);
    QSL_ImageNames.push_back(name);
    if(QSL_ImageNames.size() != 1)
        QSL_ImageNames_noBinary.push_back(name);

    //update ui
    Populate_CB_ImageNames();
    Calc_All();
    Update_Images();
    Update_Plot();

    //show last added image
    ui->comboBox_ImgVal_Image->setCurrentIndex(static_cast<int>(vMA_Images.size()) -  1);
}


void D_AnalysisWindow::Image_Value_Clear()
{
    //clear all
    QSL_ImageNames.clear();
    QSL_ImageNames_noBinary.clear();
    vMA_Images.clear();
    vMA_Images_8bit.clear();

    //then add binary to avoid empty vectors
    Image_Binary_Add();
}

void D_AnalysisWindow::Save_ImagePlotTable()
{
    QString QS_Dir_Save = QFileDialog::getExistingDirectory(
                this,
                tr("Choose folder to save in."),
                pStore->dir_Analyzer()->path());

    if(QS_Dir_Save == 0)
        return;
    else
        pStore->set_dir_Analyzer(QS_Dir_Save);

    AutoSave = true;
    Save_Image();
    Save_Plot();
    Save_Table();
    AutoSave = false;
}

void D_AnalysisWindow::Save_Image()
{
    QString SaveName;

    if(AutoSave)
        SaveName = Viewer_Image.Save_Image(pStore->dir_Analyzer()->path() + "/Image.jpg");
    else
        SaveName = Viewer_Image.Save_Image_Dialog(pStore->dir_Analyzer()->path() + "/Image.jpg");

    if(SaveName != 0)
        pStore->set_dir_Analyzer(SaveName.left(SaveName.lastIndexOf("/")));
}

void D_AnalysisWindow::Save_Plot()
{
    QString SaveName;

    if(AutoSave)
        SaveName = pStore->dir_Analyzer()->path() + "/Plot.jpg";
    else
        SaveName = QFileDialog::getSaveFileName(this,
                                                 tr("Save plot as image"),
                                                 pStore->dir_Analyzer()->path(),
                                                 tr("Images (*.png *.jpg *.bmp *.tif)"));
    if(SaveName == 0)
        return;
    else
        pStore->set_dir_Analyzer(SaveName.left(SaveName.lastIndexOf("/")));

    QPixmap pixmap_save = pChartView_Plot->grab();
    pixmap_save.save(SaveName, 0, -1);
}

void D_AnalysisWindow::Save_Table()
{
    QString SaveName;

    if(AutoSave)
        SaveName = Table_PlottedData.Save_Table(pStore->dir_Analyzer()->path() + "/Table.csv");
    else
        SaveName = Table_PlottedData.Save_Table_Dialog(pStore->dir_Analyzer()->path() + "/Table.csv");

    if(SaveName != 0)
        pStore->set_dir_Analyzer(SaveName.left(SaveName.lastIndexOf("/")));
}

void D_AnalysisWindow::Calc_All()
{
    if(!b_LabelLoaded)
        return;

    //Value distribution lists
    Calc_ValDistr();

    //Pixels
    Calc_ImgComVal();
    Calc_ImgComAxeClaSta();

    //Components
    Calc_ImgComSta();
    Calc_ComFea();

    //image
    Calc_ImgStaSta();
    Calc_FeaSta();

    //stack
    Calc_StaStaSta();

    Update_Plot();
}


void D_AnalysisWindow::Calc_ValDistr()
{
    //check needs
    if(!b_LabelLoaded)
        return;
    b_Calced_ValDistr = false;

    //clear & resize
    v_ValDistList.clear();
    v_ValDistList.resize(vMA_Images.size());

    //loop value images
    for(int i = 0; i < vMA_Images.size(); i++)
    {
        ERR(v_ValDistList[i].set_Mats(
                    &MA_Label,
                    &(vMA_Images[i]),
                    connectivity),
            "Calc_ValDistr",
            "Hand Images to ValDistList");

        v_ValDistList[i].calc_All();
    }

    b_Calced_ValDistr = true;
}

void D_AnalysisWindow::Calc_ImgComVal()
{
    //check needs
    if(!b_LabelLoaded || !b_Calced_ValDistr)
        return;
    b_Calced_ImgComVal = false;

    //clear & resize
    vvvd_ImgComVal_val.clear();
    vvvd_ImgComVal_val.resize(vMA_Images.size());

    //split image -> vectors
    for(int img = 0; img < vMA_Images.size(); img++)
    {
        ERR(D_Img_Proc::Split_img2vv_value(
                &(vvvd_ImgComVal_val[img]),
                &(vMA_Images[img]),
                &MA_Label,
                false),
            "Calc_ImgComVal",
            "Spliting value images to vectors of vectors of pixel values resoluted after components");
    }

    b_Calced_ImgComVal = true;
}

void D_AnalysisWindow::Calc_ImgComAxeClaSta()
{
    //check needs
    if(!b_LabelLoaded || !b_Calced_ImgComVal)
        return;
    b_Calced_ImgComAxeClaSta = false;

    //clear & resize
    vvvvvd_ImgComAxeClaSta_val.clear();
    vvvvvd_ImgComAxeClaSta_val.resize(v_ValDistList.size());

    //get axe resoluted statistics
    for(int img = 0; img < v_ValDistList.size(); img++)
        vvvvvd_ImgComAxeClaSta_val[img] = v_ValDistList[img].get_Stat();

    //transpose 4th <-> 5th dimension to get easier acces with indices
    //loop images
    vvvvvd_ImgComAxeStaCla_val.clear();
    vvvvvd_ImgComAxeStaCla_val.resize(vvvvvd_ImgComAxeClaSta_val.size());
    for(int img = 0; img < vvvvvd_ImgComAxeStaCla_val.size(); img++)
    {
        //loop components
        vvvvvd_ImgComAxeStaCla_val[img].resize(vvvvvd_ImgComAxeClaSta_val[img].size());
        for(int com = 0; com < vvvvvd_ImgComAxeStaCla_val[img].size(); com++)
        {
            //loop axe
            vvvvvd_ImgComAxeStaCla_val[img][com].resize(vvvvvd_ImgComAxeClaSta_val[img][com].size());
            for(int axe = 0; axe < vvvvvd_ImgComAxeStaCla_val[img][com].size(); axe++)
            {
                //loop statistics
                vvvvvd_ImgComAxeStaCla_val[img][com][axe].resize(c_STAT_NUMBER_OF_STATS);
                for(int sta = 0; sta < vvvvvd_ImgComAxeStaCla_val[img][com][axe].size(); sta++)
                {
                    //copy data (class representors)
                    vvvvvd_ImgComAxeStaCla_val[img][com][axe][sta].resize(vvvvvd_ImgComAxeClaSta_val[img][com][axe].size());
                    for(int cla = 0; cla < vvvvvd_ImgComAxeStaCla_val[img][com][axe][sta].size(); cla++)
                    {
                        vvvvvd_ImgComAxeStaCla_val[img][com][axe][sta][cla] = vvvvvd_ImgComAxeClaSta_val[img][com][axe][cla][sta];
                    }
                }
            }
        }
    }

    b_Calced_ImgComAxeClaSta = true;
}

void D_AnalysisWindow::Calc_ImgComSta()
{
    //check needs
    if(!b_LabelLoaded || !b_Calced_ImgComVal)
        return;
    b_Calced_ImgComSta = false;

    //clear & resize
    vvvd_ImgComSta_val.clear();
    vvvd_ImgComSta_val.resize(vvvd_ImgComVal_val.size());
    vvvd_ImgStaCom_val.clear();
    vvvd_ImgStaCom_val.resize(vvvd_ImgComVal_val.size());

    //loop
    for(int img = 0; img < vvvd_ImgComVal_val.size(); img++)
    {
        //IMG > COM > STA
        //calc stats
        vvvd_ImgComSta_val[img].resize(vvvd_ImgComVal_val[img].size());
        for(int com = 0; com < vvvd_ImgComVal_val[img].size(); com++)
        {
            vvvd_ImgComSta_val[img][com].resize(c_STAT_NUMBER_OF_STATS, 0.0);
            ERR(D_Stat::Calc_Stats(
                        &(vvvd_ImgComSta_val[img][com]),
                        vvvd_ImgComVal_val[img][com],
                        true),
                "Calc_ImgComSta",
                "Calculating stats of pixel values resloved after components for each image");
        }

        //IMG > STA > COM
        //kind of transpose this thing, to get difrent index order
        vvvd_ImgStaCom_val[img].resize(c_STAT_NUMBER_OF_STATS);
        for(int sta = 0; sta < vvvd_ImgStaCom_val[img].size(); sta++)
        {
            vvvd_ImgStaCom_val[img][sta].resize(vvvd_ImgComSta_val[img].size());
            for(int com = 0; com < vvvd_ImgStaCom_val[img][sta].size(); com++)
                vvvd_ImgStaCom_val[img][sta][com] = vvvd_ImgComSta_val[img][com][sta];
        }
    }

    b_Calced_ImgComSta = true;
}

void D_AnalysisWindow::Calc_ComFea()
{
    qDebug() << "Calc_ComFea";
    //check needs
    if(!b_LabelLoaded || !b_Calced_ValDistr)
        return;
    b_Calced_ComFea = false;

    //clear & resize
    vvd_ComFea_fea.clear();
    vvd_ComFea_fea.resize(v_ValDistList[0].get_CompList()->size());

    //loop
    //components
    for(int com = 0; com < vvd_ComFea_fea.size(); com++)
    {
        //features
        vvd_ComFea_fea[com].resize(c_FEAT_NUMBER_OF_FEATS);
        for(int fea = 0; fea < vvd_ComFea_fea[com].size(); fea++)
        {
            //get feature
            vvd_ComFea_fea[com][fea] = v_ValDistList[0].get_CompList()->get_Feature(com, fea);
        }
    }

    b_Calced_ComFea = true;
}

void D_AnalysisWindow::Calc_ImgStaSta()
{
    qDebug() << "Calc_ImgStaSta";

    //check needs
    if(!b_LabelLoaded || !b_Calced_ImgComSta)
        return;
    b_Calced_ImgStaSta = false;

    //clear & resize
    vvvd_ImgStaSta_val.clear();
    vvvd_ImgStaSta_val.resize(vvvd_ImgStaCom_val.size());

    //loop
    //images
    for(int img = 0; img < vvvd_ImgStaSta_val.size(); img++)
    {
        //stats
        vvvd_ImgStaSta_val[img].resize(c_STAT_NUMBER_OF_STATS);
        for(int sta_com = 0; sta_com < vvvd_ImgStaSta_val[img].size(); sta_com++)
        {
            ERR(D_Stat::Calc_Stats(
                    &(vvvd_ImgStaSta_val[img][sta_com]),    //out:  Stats of
                    vvvd_ImgStaCom_val[img][sta_com],       //in:   The same stat for every Component   (Example: Mean of Variances of Pixelvalues in Components)
                    true),
                "Calc_ImgStaSta",
                "Calculating stats (img) of stats (comp) of values (pixels)");
        }
    }

    b_Calced_ImgStaSta = true;
}

void D_AnalysisWindow::Calc_FeaSta()
{
    qDebug() << "Calc_FeaSta";

    //check needs
    if(!b_LabelLoaded || !b_Calced_ComFea)
        return;
    b_Calced_FeaSta = false;

    //clear & resize
    vvd_FeaCom_fea.clear();
    vvd_FeaCom_fea.resize(c_FEAT_NUMBER_OF_FEATS);
    vvd_FeaSta_fea.clear();
    vvd_FeaSta_fea.resize(c_FEAT_NUMBER_OF_FEATS);

    //loop
    //features
    for(int fea = 0; fea < vvd_FeaSta_fea.size(); fea++)
    {
        //get same feature for each component
        vvd_FeaCom_fea[fea].resize(vvd_ComFea_fea.size());
        for(int com = 0; com < vvd_FeaCom_fea[fea].size(); com++)
            vvd_FeaCom_fea[fea][com] = vvd_ComFea_fea[com][fea];

        ERR(D_Stat::Calc_Stats(
                &(vvd_FeaSta_fea[fea]),
                vvd_FeaCom_fea[fea],
                true),
            "Calc_FeaSta",
            "Calculating the stats of features in components");
    }

    b_Calced_FeaSta = true;
}

void D_AnalysisWindow::Calc_StaStaSta()
{
    qDebug() << "Calc_StaStaSta";

    //check needs
    if(!b_LabelLoaded || !b_Calced_ImgStaSta)
        return;
    b_Calced_StaStaSta = false;

    //clear
    vvvd_StaStaSta_val.clear();

    //resize
    //stats of pixel-values in components (com)
    vvvd_StaStaSta_val.resize(c_STAT_NUMBER_OF_STATS);
    for(int sta_com = 0; sta_com < c_STAT_NUMBER_OF_STATS; sta_com++)
        vvvd_StaStaSta_val[sta_com].resize(c_STAT_NUMBER_OF_STATS);

    //loop & calc
     for(int sta_com = 0; sta_com < c_STAT_NUMBER_OF_STATS; sta_com++)
        for(int sta_img = 0; sta_img < c_STAT_NUMBER_OF_STATS; sta_img++)
        {
            //get stats (comp in img) of stats (px in comp) for each image
            vector<double> vd_STA;
            vd_STA.resize(vvvd_ImgStaSta_val.size() - 1);
            for(int img = 1; img < vvvd_ImgStaSta_val.size(); img++)        //ignore binary
                vd_STA[img - 1] = vvvd_ImgStaSta_val[img][sta_com][sta_img];

            //calc stats(stats(stats(pixels))) [com][img][stack]
            D_Stat::Calc_Stats(
                        &(vvvd_StaStaSta_val[sta_com][sta_img]),
                        vd_STA,
                        true);
        }

    b_Calced_StaStaSta = true;
}



void D_AnalysisWindow::Update_Images()
{
    if(!b_LabelLoaded)
        return;

    switch (ui->tabWidget_Images->currentIndex()) {
    case IMAGE_LABEL:   Update_Image_Label();   break;
    case IMAGE_VALUE:   Update_Image_Value();   break;
    case IMAGE_FEATURE: Update_Image_Feature(); break;
    case IMAGE_STATS:   Update_Image_Stat();    break;
    default:                                    break;}
}

void D_AnalysisWindow::Update_Image_Label()
{
    if(!b_LabelLoaded)
        return;

    Viewer_Image.Update_Image(&MA_Label);
}

void D_AnalysisWindow::Update_Image_Value()
{
    if(!b_LabelLoaded)
        return;

    Viewer_Image.Update_Image(&(vMA_Images[ui->comboBox_ImgVal_Image->currentIndex()]));
}

void D_AnalysisWindow::Update_Image_Stat()
{
    if(!b_LabelLoaded || !b_Calced_ImgComSta)
        return;

    ERR(D_Img_Proc::Draw_Label_Numbers_LUT_Gray(
            &MA_Stats,
            &(vMA_Images[ui->comboBox_ImgSta_Image->currentIndex()]),
            &MA_Label,
            vvvd_ImgStaCom_val[ui->comboBox_ImgSta_Image->currentIndex()][ui->comboBox_ImgSta_Stat->currentIndex()],
            ui->comboBox_ImgSta_Geometric->currentIndex(),
            ui->doubleSpinBox_ImgSta_Scale->value(),
            ui->spinBox_ImgSta_Thickness->value(),
            true,
            ui->spinBox_ImgSta_Precision->value()),
        "Update_Image_Stat",
        "Draw_Label_Numbers_LUT_Gray");

    Viewer_Image.Update_Image(&MA_Stats);
}

void D_AnalysisWindow::Update_Image_Feature()
{
    if(!b_LabelLoaded || !b_Calced_FeaSta)
        return;

    ERR(D_Img_Proc::Draw_Label_Numbers_LUT_Gray(
            &MA_Features,
            &(vMA_Images[ui->comboBox_ImgFea_BaseImage->currentIndex()]),
            &MA_Label,
            vvd_FeaCom_fea[ui->comboBox_ImgFea_Feature->currentIndex()],
            ui->comboBox_ImgFea_Geometric->currentIndex(),
            ui->doubleSpinBox_ImgFea_Scale->value(),
            ui->spinBox_ImgFea_Thickness->value(),
            true,
            ui->spinBox_ImgFea_Precision->value()),
        "Update_Image_Feature",
        "Draw_Label_Numbers_LUT_Gray");

    Viewer_Image.Update_Image(&MA_Features);
}

void D_AnalysisWindow::Update_Views()
{
    Update_View_Label();
    Update_View_Value();
    Update_View_Stat();
    Update_View_Feature();
    Update_View_Plot();
}

void D_AnalysisWindow::Update_View_Label()
{
    Viewer_Image.Update_View();
}

void D_AnalysisWindow::Update_View_Value()
{
    Viewer_Image.Update_View();
}

void D_AnalysisWindow::Update_View_Stat()
{
    Viewer_Image.Update_View();
}

void D_AnalysisWindow::Update_View_Feature()
{
    Viewer_Image.Update_View();
}

void D_AnalysisWindow::Update_View_Plot()
{
    if(ui->checkBox_Plot_X_Range->isChecked())
    {
        pChartView_Plot->chart()->axisX()->setMin(ui->doubleSpinBox_Plot_X_Min->value());
        pChartView_Plot->chart()->axisX()->setMax(ui->doubleSpinBox_Plot_X_Max->value());
    }

    if(ui->checkBox_Plot_Y_Range->isChecked())
    {
        pChartView_Plot->chart()->axisY()->setMin(ui->doubleSpinBox_Plot_Y_Min->value());
        pChartView_Plot->chart()->axisY()->setMax(ui->doubleSpinBox_Plot_Y_Max->value());
    }
}

void D_AnalysisWindow::Update_Plot()
{
    if(!b_LabelLoaded)
        return;

    //clear old stuff
    ui->tableWidget_PlottedData->clear();
    ui->tableWidget_PlottedData->setRowCount(1);
    ui->tableWidget_PlottedData->setColumnCount(1);

    //start timer
    QElapsedTimer timer;
    timer.start();

    //plot
    switch (ui->tabWidget_Plots->currentIndex()) {


    case PLOT_PIXEL://======================================

        switch (ui->comboBox_PlotPixel_Type->currentIndex()) {

        case PLOT_PIXEL_HIST://--------------------------------
            Plot_Pixel_Histogram();
            break;

        case PLOT_PIXEL_AXE://--------------------------------
            Plot_Pixel_Values_on_Axis();
            break;

        case PLOT_PIXEL_SCATTER_VALUE://--------------------------------
            Plot_Pixel_ScatterValue();
            break;

        case PLOT_PIXEL_SCATTER_HIST://--------------------------------
            Plot_Pixel_ScatterHist();
            break;

        case PLOT_PIXEL_SCATTER_AXE://--------------------------------
            Plot_Pixel_ScatterAxe();
            break;

        default://------------------------------------------
            break;
        }

        break;


    case PLOT_COMP://======================================

        switch (ui->comboBox_PlotComp_Type->currentIndex()) {

        case PLOT_COMP_FEAT_BAR://--------------------------------
            Plot_Comp_Feature();
            break;

        case PLOT_COMP_FEAT_HIST://--------------------------------
            Plot_Comp_FeatureHist();
            break;

        case PLOT_COMP_FEAT_SCATTER://--------------------------------
            Plot_Comp_FeatureScatter();
            break;

        case PLOT_COMP_STAT_BAR://--------------------------------
            Plot_Comp_Stat();
            break;

        case PLOT_COMP_STAT_HIST://--------------------------------
            Plot_Comp_StatHist();
            break;

        case PLOT_COMP_STAT_SCATTER://--------------------------------
            Plot_Comp_StatScatter();
            break;

        case PLOT_COMP_STATFEAT_SCATTER://--------------------------------
            Plot_Comp_StatFeatScatter();
            break;

        default://------------------------------------------
            break;
        }

        break;


    case PLOT_IMAGE://======================================

        switch (ui->comboBox_PlotImg_Type->currentIndex()) {

        case PLOT_IMAGE_STAT://--------------------------------
            Plot_Img_Stat();
            break;

        case PLOT_IMAGE_STAT_HIST://--------------------------------
            Plot_Img_StatHist();
            break;

        case PLOT_IMAGE_STAT_SCATTER://--------------------------------
            Plot_Img_StatScatter();
            break;
/*
        case PLOT_IMAGE_STATFEAT_SCATTER://--------------------------------
            Plot_Img_StatFeatScatter();
            break;
*/
        case PLOT_IMAGE_FEAT://--------------------------------
            Plot_Img_Feature();
            break;
/*
        case PLOT_IMAGE_FEAT_HIST://--------------------------------
            Plot_Img_FeatureHist();
            break;
*/
        default://------------------------------------------
            break;
        }

        break;


    case PLOT_STACK://======================================

        switch (ui->comboBox_PlotStack_Type->currentIndex()) {

        case PLOT_STACK_STAT://--------------------------------
            Plot_Stack_Stat();
            break;

        default://------------------------------------------
            break;
        }

        break;


    default://==============================================
        break;
    }

    //apply cosmetics, range, etc
    Update_View_Plot();

    //show timer
    ui->label_Plot_Time->setText("Plot time: " + QString::number(timer.elapsed() / 1000.0, 'g', 4) + "s");
}

void D_AnalysisWindow::Plot_Pixel_Histogram()
{


    switch (ui->comboBox_PlotPixel_Hist_Mode->currentIndex()) {

    case PLOT_MODE_PIXEL_SINGLE://-----------------------------------------
    {
        //get basic indices
        int img = ui->comboBox_PlotPixel_Hist_Image->currentIndex();
        int com = ui->comboBox_PlotPixel_Hist_Component->currentIndex();

        //basic variables
        vector<double> v_hist;
        double x_min, x_max, y_max, step;

        //calc
        ERR(D_Stat::Calc_Vector2Hist_1(
                &v_hist,
                &(vvvd_ImgComVal_val[img][com]),
                ui->spinBox_PlotPixel_Hist_Classes->value(),
                &x_min,
                &x_max,
                &y_max,
                &step,
                ui->checkBox_PlotPixel_Hist_Accumulate->isChecked(),
                ui->checkBox_PlotPixel_Hist_Uniform->isChecked()),
            "Plot_Pixel_Histogram",
            "Single - Claculate Histogram");

        //plot
        ERR(D_Plot::Plot_Hist_Single_Classes(
                pChartView_Plot,
                &v_hist,
                x_min,
                step,
                "<b>Histogram</b><br>" + ui->comboBox_PlotPixel_Hist_Image->currentText(),
                ui->comboBox_PlotPixel_Hist_Component->currentText(),
                "Pixel Value",
                "Amount of Pixels",
                false),
            "Plot_Pixel_Histogram",
            "Single - Plot Histogram");

        //table
        Table_PlottedData.set_data_d_1D_qs_step(
                    v_hist,
                    "",
                    x_min,
                    step);
    }
        break;

    case PLOT_MODE_PIXEL_ALL_COMP://-----------------------------------------
    {
        //get basic indices
        int img = ui->comboBox_PlotPixel_Hist_Image->currentIndex();

        //basic variables
        vector<vector<double>> vvd_tmp_ComVal;
        vector<vector<double>> vvd_hist;
        double x_min, x_max, y_max, step;

        //get data in needed format
        vvd_tmp_ComVal.resize(vvvd_ImgComVal_val[img].size());
        for(int com = 0; com < vvd_tmp_ComVal.size(); com++)
            vvd_tmp_ComVal[com] = vvvd_ImgComVal_val[img][com];

        //calc
        ERR(D_Stat::Calc_Vector2Hist_2(
                &vvd_hist,
                &vvd_tmp_ComVal,
                ui->spinBox_PlotPixel_Hist_Classes->value(),
                &x_min,
                &x_max,
                &y_max,
                &step,
                ui->checkBox_PlotPixel_Hist_Accumulate->isChecked(),
                ui->checkBox_PlotPixel_Hist_Uniform->isChecked()),
            "Plot_Pixel_Histogram",
            "All Comp - Claculate Histogram");

        //plot
        ERR(D_Plot::Plot_Hist_Multi_Classes(
                pChartView_Plot,
                &vvd_hist,
                x_min,
                x_max,
                y_max,
                step,
                "<b>Histogram</b><br>" + ui->comboBox_PlotPixel_Hist_Image->currentText(),
                QSL_ComponentNames,
                "Pixel Value",
                "Amount of Pixels",
                false),
            "Plot_Pixel_Histogram",
            "All Comp - Plot Histogram");

        //table
        Table_PlottedData.set_data_d_2D_qsl_step(
                    vvd_hist,
                    QSL_ComponentNames,
                    x_min,
                    step);

        pChartView_Plot->chart()->legend()->setAlignment(Qt::AlignLeft);
    }
        break;

    case PLOT_MODE_PIXEL_ALL_IMG://-----------------------------------------
    {
        if(vvvd_ImgComVal_val.size() <= 1)
            return;

        //get basic indices
        int com = ui->comboBox_PlotPixel_Hist_Component->currentIndex();

        //basic variables
        vector<vector<double>> vvd_tmp_ImgVal;
        vector<vector<double>> vvd_hist;
        double x_min, x_max, y_max, step;

        //get data in needed format
        vvd_tmp_ImgVal.resize(vvvd_ImgComVal_val.size() - 1);
        for(int img = 1; img < vvvd_ImgComVal_val.size(); img++)        //start at 1 to ignore binary, because its histogram is boring
            vvd_tmp_ImgVal[img - 1] = vvvd_ImgComVal_val[img][com];

        //calc
        ERR(D_Stat::Calc_Vector2Hist_2(
                &vvd_hist,
                &vvd_tmp_ImgVal,
                ui->spinBox_PlotPixel_Hist_Classes->value(),
                &x_min,
                &x_max,
                &y_max,
                &step,
                ui->checkBox_PlotPixel_Hist_Accumulate->isChecked(),
                ui->checkBox_PlotPixel_Hist_Uniform->isChecked()),
            "Plot_Pixel_Histogram",
            "All Comp - Claculate Histogram");

        //plot
        ERR(D_Plot::Plot_Hist_Multi_Classes(
                pChartView_Plot,
                &vvd_hist,
                x_min,
                x_max,
                y_max,
                step,
                "<b>Histogram</b><br>" + ui->comboBox_PlotPixel_Hist_Component->currentText(),
                QSL_ImageNames_noBinary,
                "Pixel Value",
                "Amount of Pixels",
                false),
            "Plot_Pixel_Histogram",
            "All Comp - Plot Histogram");

        //table
        Table_PlottedData.set_data_d_2D_qsl_step(
                    vvd_hist,
                    QSL_ImageNames_noBinary,
                    x_min,
                    step);

        pChartView_Plot->chart()->legend()->setAlignment(Qt::AlignLeft);
    }
        break;

    default:
        break;
    }
}

void D_AnalysisWindow::Plot_Pixel_Values_on_Axis()
{
    //basic indices
    int axe = ui->comboBox_PlotPixel_Axe_Axis->currentIndex();
    int sta = ui->comboBox_PlotPixel_Axe_Stat->currentIndex();


    switch (ui->comboBox_PlotPixel_Axe_Mode->currentIndex()) {

    case PLOT_MODE_PIXEL_SINGLE:
    {
        int img = ui->comboBox_PlotPixel_Axe_Image->currentIndex();
        int com = ui->comboBox_PlotPixel_Axe_Component->currentIndex();

        //plot
        ERR(D_Plot::Plot_Line_XY_Single(
                pChartView_Plot,
                vvvvvd_ImgComAxeStaCla_val[img][com][axe][sta],
                "<b>Valuedistribution</b><br>" + ui->comboBox_PlotPixel_Axe_Image->currentText(),
                ui->comboBox_PlotPixel_Axe_Component->currentText(),
                "Position on " + ui->comboBox_PlotPixel_Axe_Axis->currentText(),
                ui->comboBox_PlotPixel_Axe_Stat->currentText() + " of Pixel Values"),
            "Plot_Pixel_Values_on_Axis",
            "Single - Plot XY-Line");

        //table
        Table_PlottedData.set_data_d_1D_qs_count(
                    vvvvvd_ImgComAxeStaCla_val[img][com][axe][sta],
                    "");
    }
        break;


    case PLOT_MODE_PIXEL_ALL_COMP:
    {
        int img = ui->comboBox_PlotPixel_Axe_Image->currentIndex();

        //create tmp vector in needed format
        vector<vector<double>> vvd_tmp_ComCla;
        vvd_tmp_ComCla.resize(vvvvvd_ImgComAxeStaCla_val[img].size());
        for(int com = 0; com < vvd_tmp_ComCla.size(); com++)
            vvd_tmp_ComCla[com] = vvvvvd_ImgComAxeStaCla_val[img][com][axe][sta];

        //plot
        ERR(D_Plot::Plot_Line_XY_Multi(
                pChartView_Plot,
                vvd_tmp_ComCla,
                "<b>Valuedistribution</b><br>" + ui->comboBox_PlotPixel_Axe_Image->currentText(),
                QSL_ComponentNames,
                "Position on " + ui->comboBox_PlotPixel_Axe_Axis->currentText(),
                ui->comboBox_PlotPixel_Axe_Stat->currentText() + " of Pixel Values"),
            "Plot_Pixel_Values_on_Axis",
            "All Components - Plot XY-Line");

        pChartView_Plot->chart()->legend()->setAlignment(Qt::AlignLeft);

        //table
        Table_PlottedData.set_data_d_2D_qsl_count(
                    vvd_tmp_ComCla,
                    QSL_ComponentNames);
    }
        break;


    case PLOT_MODE_PIXEL_ALL_IMG:
    {
        int com = ui->comboBox_PlotPixel_Axe_Component->currentIndex();

        //create tmp vector in needed format
        vector<vector<double>> vvd_tmp_ImgCla;
        vvd_tmp_ImgCla.resize(vvvvvd_ImgComAxeStaCla_val.size() - 1);   //skip binary
        for(int img = 1; img < vvvvvd_ImgComAxeStaCla_val.size(); img++)
            vvd_tmp_ImgCla[img - 1] = vvvvvd_ImgComAxeStaCla_val[img][com][axe][sta];

        //plot
        ERR(D_Plot::Plot_Line_XY_Multi(
                pChartView_Plot,
                vvd_tmp_ImgCla,
                "<b>Valuedistribution</b><br>" + ui->comboBox_PlotPixel_Axe_Component->currentText(),
                QSL_ImageNames_noBinary,
                "Position on " + ui->comboBox_PlotPixel_Axe_Axis->currentText(),
                ui->comboBox_PlotPixel_Axe_Stat->currentText() + " of Pixel Values"),
            "Plot_Pixel_Values_on_Axis",
            "All Images - Plot XY-Line");

        pChartView_Plot->chart()->legend()->setAlignment(Qt::AlignLeft);

        //table
        Table_PlottedData.set_data_d_2D_qsl_count(
                    vvd_tmp_ImgCla,
                    QSL_ImageNames_noBinary);
    }
        break;

    default:
        break;
    }
}

void D_AnalysisWindow::Plot_Pixel_ScatterValue()
{
    switch (ui->comboBox_PlotPixel_ScatterValue_Mode->currentIndex()) {

    case PLOT_MODE_PIXEL_SINGLE://----------------------------------------------------------
    {
        int img_x = ui->comboBox_PlotPixel_ScatterValue_Image_X->currentIndex();
        int img_y = ui->comboBox_PlotPixel_ScatterValue_Image_Y->currentIndex();
        int com = ui->comboBox_PlotPixel_ScatterValue_Component->currentIndex();

        //plot
        ERR(D_Plot::Plot_Scatter_2D_Single_Y(
                pChartView_Plot,
                &(vvvd_ImgComVal_val[img_x][com]),
                &(vvvd_ImgComVal_val[img_y][com]),
                "<b>Compare Values</b>",
                ui->comboBox_PlotPixel_ScatterValue_Component->currentText(),
                "Pixel Values of " + ui->comboBox_PlotPixel_ScatterValue_Image_X->currentText(),
                "Pixel Values of " + ui->comboBox_PlotPixel_ScatterValue_Image_Y->currentText()),
            "Plot_Pixel_ScatterValue",
            "Single - Plot_Scatter_2D_Single_Y");

        //table
        Table_PlottedData.set_data_d_1D_qs_vd(
                    vvvd_ImgComVal_val[img_y][com],
                    "",
                    vvvd_ImgComVal_val[img_x][com]);
    }
        break;

    case PLOT_MODE_PIXEL_ALL_COMP://--------------------------------------------------------
    {
        int img_x = ui->comboBox_PlotPixel_ScatterValue_Image_X->currentIndex();
        int img_y = ui->comboBox_PlotPixel_ScatterValue_Image_Y->currentIndex();

        ERR(D_Plot::Plot_Scatter_2D_Multi_XY(
                pChartView_Plot,
                &(vvvd_ImgComVal_val[img_x]),
                &(vvvd_ImgComVal_val[img_y]),
                "<b>Compare Values</b>",
                QSL_ComponentNames,
                "Pixel Values of " + ui->comboBox_PlotPixel_ScatterValue_Image_X->currentText(),
                "Pixel Values of " + ui->comboBox_PlotPixel_ScatterValue_Image_Y->currentText()),
            "Plot_Pixel_ScatterValue",
            "All Components - Plot_Scatter_2D_Multi_XY");

        pChartView_Plot->chart()->legend()->setAlignment(Qt::AlignLeft);

        //table
        //to be done
    }
        break;

    case PLOT_MODE_PIXEL_ALL_IMG://---------------------------------------------------------
    {
        int img_x = ui->comboBox_PlotPixel_ScatterValue_Image_X->currentIndex();
        int com = ui->comboBox_PlotPixel_ScatterValue_Component->currentIndex();

        //get data in needed format
        vector<vector<double>> vvd_tmp_ImgVal;
        vvd_tmp_ImgVal.resize(vvvd_ImgComVal_val.size() - 1);
        for(int img = 1; img < vvvd_ImgComVal_val.size(); img++)        //start at 1 to ignore binary, because it is boring
            vvd_tmp_ImgVal[img - 1] = vvvd_ImgComVal_val[img][com];

        ERR(D_Plot::Plot_Scatter_2D_Multi_Y(
                pChartView_Plot,
                &(vvvd_ImgComVal_val[img_x][com]),
                &(vvd_tmp_ImgVal),
                "<b>Compare Values</b><br>" + ui->comboBox_PlotPixel_ScatterValue_Component->currentText(),
                QSL_ImageNames_noBinary,
                "Pixel Values of " + ui->comboBox_PlotPixel_ScatterValue_Image_X->currentText(),
                "Pixel Values of Images"),
            "Plot_Pixel_ScatterValue",
            "All Images - Plot_Scatter_2D_Multi_Y");

        pChartView_Plot->chart()->legend()->setAlignment(Qt::AlignLeft);

        //table
        Table_PlottedData.set_data_d_2D_qsl_vd(
                    vvd_tmp_ImgVal,
                    QSL_ImageNames_noBinary,
                    vvvd_ImgComVal_val[img_x][com]);
    }
        break;

    default://------------------------------------------------------------------------------
        break;
    }
}

void D_AnalysisWindow::Plot_Pixel_ScatterHist()
{
    switch (ui->comboBox_PlotPixel_ScatterHist_Mode->currentIndex()) {

    case PLOT_MODE_PIXEL_SINGLE://----------------------------------------------------------
    {
        //get basic indices
        int img_x = ui->comboBox_PlotPixel_ScatterHist_Image_X->currentIndex();
        int img_y = ui->comboBox_PlotPixel_ScatterHist_Image_Y->currentIndex();
        int com_x = ui->comboBox_PlotPixel_ScatterHist_Component_X->currentIndex();
        int com_y = ui->comboBox_PlotPixel_ScatterHist_Component_Y->currentIndex();

        //basic variables
        vector<double> v_hist_X;
        vector<double> v_hist_Y;
        double min_x, max_x, max_y, step; //no one cares about these, but the arguments are needed

        //calc
        ERR(D_Stat::Calc_Vector2Hist_1(
                &v_hist_X,
                &(vvvd_ImgComVal_val[img_x][com_x]),
                ui->spinBox_PlotPixel_ScatterHist_Classes->value(),
                &min_x,
                &max_x,
                &max_y,
                &step,
                ui->checkBox_PlotPixel_ScatterHist_Accumulate->isChecked(),
                ui->checkBox_PlotPixel_ScatterHist_Uniform->isChecked()),
            "Plot_Pixel_ScatterHist",
            "Single - Calc_Vector2Hist_1 - X");
        ERR(D_Stat::Calc_Vector2Hist_1(
                &v_hist_Y,
                &(vvvd_ImgComVal_val[img_y][com_y]),
                ui->spinBox_PlotPixel_ScatterHist_Classes->value(),
                &min_x,
                &max_x,
                &max_y,
                &step,
                ui->checkBox_PlotPixel_ScatterHist_Accumulate->isChecked(),
                ui->checkBox_PlotPixel_ScatterHist_Uniform->isChecked()),
            "Plot_Pixel_ScatterHist",
            "Single - Calc_Vector2Hist_1 - Y");

        //plot
        ERR(D_Plot::Plot_Scatter_2D_Single_Y(
                pChartView_Plot,
                &v_hist_X,
                &v_hist_Y,
                "<b>Compare Histograms</b>",
                "Classes of Pixel Values",
                "Amount of Pixels in " + ui->comboBox_PlotPixel_ScatterHist_Image_X->currentText() + " in " + ui->comboBox_PlotPixel_ScatterHist_Component_X->currentText(),
                "Amount of Pixels in " + ui->comboBox_PlotPixel_ScatterHist_Image_Y->currentText() + " in " + ui->comboBox_PlotPixel_ScatterHist_Component_Y->currentText()),
            "Plot_Pixel_ScatterHist",
            "Single - Plot_Scatter_2D_Single_Y");

        //table
        Table_PlottedData.set_data_d_1D_qs_vd(
                    v_hist_Y,
                    "",
                    v_hist_X);
    }
        break;

    case PLOT_MODE_PIXEL_ALL_COMP://--------------------------------------------------------
    {
        //get basic indices
        int img_x = ui->comboBox_PlotPixel_ScatterHist_Image_X->currentIndex();
        int img_y = ui->comboBox_PlotPixel_ScatterHist_Image_Y->currentIndex();
        int com_x = ui->comboBox_PlotPixel_ScatterHist_Component_X->currentIndex();

        //basic variables
        vector<double> v_hist_X;
        vector<vector<double>> vv_hist_Y;
        double min_x, max_x, max_y, step; //no one cares about these, but the arguments are needed

        //calc
        ERR(D_Stat::Calc_Vector2Hist_1(
                &v_hist_X,
                &(vvvd_ImgComVal_val[img_x][com_x]),
                ui->spinBox_PlotPixel_ScatterHist_Classes->value(),
                &min_x,
                &max_x,
                &max_y,
                &step,
                ui->checkBox_PlotPixel_ScatterHist_Accumulate->isChecked(),
                ui->checkBox_PlotPixel_ScatterHist_Uniform->isChecked()),
            "Plot_Pixel_ScatterHist",
            "All Components - Calc_Vector2Hist_1 - X");
        ERR(D_Stat::Calc_Vector2Hist_2(
                &vv_hist_Y,
                &(vvvd_ImgComVal_val[img_y]),
                ui->spinBox_PlotPixel_ScatterHist_Classes->value(),
                &min_x,
                &max_x,
                &max_y,
                &step,
                ui->checkBox_PlotPixel_ScatterHist_Accumulate->isChecked(),
                ui->checkBox_PlotPixel_ScatterHist_Uniform->isChecked()),
            "Plot_Pixel_ScatterHist",
            "All Components - Calc_Vector2Hist_2 - Y");

        ERR(D_Plot::Plot_Scatter_2D_Multi_Y(
                pChartView_Plot,
                &v_hist_X,
                &vv_hist_Y,
                "<b>Compare Histograms</b>",
                QSL_ComponentNames,
                "Amount of Pixels in " + ui->comboBox_PlotPixel_ScatterHist_Image_X->currentText() + " in " + ui->comboBox_PlotPixel_ScatterHist_Component_X->currentText(),
                "Amount of Pixels in " + ui->comboBox_PlotPixel_ScatterHist_Image_Y->currentText() + " in Components"),
            "Plot_Pixel_ScatterHist",
            "All Components - Plot_Scatter_2D_Multi_Y");

        //table
        Table_PlottedData.set_data_d_2D_qsl_vd(
                    vv_hist_Y,
                    QSL_ComponentNames,
                    v_hist_X);

        pChartView_Plot->chart()->legend()->setAlignment(Qt::AlignLeft);
    }
        break;

    case PLOT_MODE_PIXEL_ALL_IMG://---------------------------------------------------------
    {
        //get basic indices
        int img_x = ui->comboBox_PlotPixel_ScatterHist_Image_X->currentIndex();
        int com_x = ui->comboBox_PlotPixel_ScatterHist_Component_X->currentIndex();
        int com_y = ui->comboBox_PlotPixel_ScatterHist_Component_Y->currentIndex();

        //basic variables
        vector<double> v_hist_X;
        vector<vector<double>> vvd_tmp_ImgVal_Y;
        vector<vector<double>> vv_hist_Y;
        double min_x, max_x, max_y, step; //no one cares about these, but the arguments are needed

        //get data in needed format
        vvd_tmp_ImgVal_Y.resize(vvvd_ImgComVal_val.size() - 1);
        for(int img = 1; img < vvvd_ImgComVal_val.size(); img++)        //start at 1 to ignore binary, because its histogram is boring
            vvd_tmp_ImgVal_Y[img - 1] = vvvd_ImgComVal_val[img][com_y];

        //calc
        ERR(D_Stat::Calc_Vector2Hist_1(
                &v_hist_X,
                &(vvvd_ImgComVal_val[img_x][com_x]),
                ui->spinBox_PlotPixel_ScatterHist_Classes->value(),
                &min_x,
                &max_x,
                &max_y,
                &step,
                ui->checkBox_PlotPixel_ScatterHist_Accumulate->isChecked(),
                ui->checkBox_PlotPixel_ScatterHist_Uniform->isChecked()),
            "Plot_Pixel_ScatterHist",
            "All Images - Calc_Vector2Hist_1 - X");
        ERR(D_Stat::Calc_Vector2Hist_2(
                &vv_hist_Y,
                &vvd_tmp_ImgVal_Y,
                ui->spinBox_PlotPixel_ScatterHist_Classes->value(),
                &min_x,
                &max_x,
                &max_y,
                &step,
                ui->checkBox_PlotPixel_ScatterHist_Accumulate->isChecked(),
                ui->checkBox_PlotPixel_ScatterHist_Uniform->isChecked()),
            "Plot_Pixel_ScatterHist",
            "All Images - Calc_Vector2Hist_2 - Y");

        ERR(D_Plot::Plot_Scatter_2D_Multi_Y(
                pChartView_Plot,
                &v_hist_X,
                &vv_hist_Y,
                "<b>Compare Histograms</b>",
                QSL_ImageNames_noBinary,
                "Amount of Pixels in " + ui->comboBox_PlotPixel_ScatterHist_Image_X->currentText() + " in " + ui->comboBox_PlotPixel_ScatterHist_Component_X->currentText(),
                "Amount of Pixels in Images in " + ui->comboBox_PlotPixel_ScatterHist_Component_Y->currentText()),
            "Plot_Pixel_ScatterHist",
            "Single - Plot_Scatter_2D_Multi_Y");

        //table
        Table_PlottedData.set_data_d_2D_qsl_vd(
                    vv_hist_Y,
                    QSL_ImageNames_noBinary,
                    v_hist_X);

        pChartView_Plot->chart()->legend()->setAlignment(Qt::AlignLeft);
    }
        break;

    default://------------------------------------------------------------------------------
        break;
    }
}

void D_AnalysisWindow::Plot_Pixel_ScatterAxe()
{
    switch (ui->comboBox_PlotPixel_ScatterAxe_Mode->currentIndex()) {

    case PLOT_MODE_PIXEL_SINGLE://----------------------------------------------------------
    {
        int img_x = ui->comboBox_PlotPixel_ScatterAxe_Image_X->currentIndex();
        int img_y = ui->comboBox_PlotPixel_ScatterAxe_Image_Y->currentIndex();
        int sta_x = ui->comboBox_PlotPixel_ScatterAxe_Stat_X->currentIndex();
        int sta_y = ui->comboBox_PlotPixel_ScatterAxe_Stat_Y->currentIndex();
        int com = ui->comboBox_PlotPixel_ScatterAxe_Component->currentIndex();
        int axe = ui->comboBox_PlotPixel_ScatterAxe_Axis->currentIndex();

        ERR(D_Plot::Plot_Scatter_2D_Single_Y(
                pChartView_Plot,
                &(vvvvvd_ImgComAxeStaCla_val[img_x][com][axe][sta_x]),
                &(vvvvvd_ImgComAxeStaCla_val[img_y][com][axe][sta_y]),
                "<b>Compare Values on Axis</b><br>" + ui->comboBox_PlotPixel_ScatterAxe_Axis->currentText(),
                ui->comboBox_PlotPixel_ScatterAxe_Component->currentText(),
                ui->comboBox_PlotPixel_ScatterAxe_Stat_X->currentText() + " of Pixel Values in " + ui->comboBox_PlotPixel_ScatterAxe_Image_X->currentText(),
                ui->comboBox_PlotPixel_ScatterAxe_Stat_Y->currentText() + " of Pixel Values in " + ui->comboBox_PlotPixel_ScatterAxe_Image_Y->currentText()),
            "Plot_Pixel_ScatterAxe",
            "Single - Plot_Scatter_2D_Single_Y");

        //table
        Table_PlottedData.set_data_d_1D_qs_vd(
                    vvvvvd_ImgComAxeStaCla_val[img_y][com][axe][sta_y],
                    "",
                    vvvvvd_ImgComAxeStaCla_val[img_x][com][axe][sta_x]);
    }
        break;

    case PLOT_MODE_PIXEL_ALL_COMP://--------------------------------------------------------
    {
        int img_x = ui->comboBox_PlotPixel_ScatterAxe_Image_X->currentIndex();
        int img_y = ui->comboBox_PlotPixel_ScatterAxe_Image_Y->currentIndex();
        int sta_x = ui->comboBox_PlotPixel_ScatterAxe_Stat_X->currentIndex();
        int sta_y = ui->comboBox_PlotPixel_ScatterAxe_Stat_Y->currentIndex();
        int axe = ui->comboBox_PlotPixel_ScatterAxe_Axis->currentIndex();

        //create tmp vector in needed format
        vector<vector<double>> vvd_tmp_ComCla_X;
        vector<vector<double>> vvd_tmp_ComCla_Y;
        vvd_tmp_ComCla_X.resize(vvvvvd_ImgComAxeStaCla_val[img_x].size());
        vvd_tmp_ComCla_Y.resize(vvvvvd_ImgComAxeStaCla_val[img_y].size());
        for(int com = 0; com < vvd_tmp_ComCla_X.size(); com++)
        {
            vvd_tmp_ComCla_X[com] = vvvvvd_ImgComAxeStaCla_val[img_x][com][axe][sta_x];
            vvd_tmp_ComCla_Y[com] = vvvvvd_ImgComAxeStaCla_val[img_y][com][axe][sta_y];
        }

        ERR(D_Plot::Plot_Scatter_2D_Multi_XY(
                pChartView_Plot,
                &(vvd_tmp_ComCla_X),
                &(vvd_tmp_ComCla_Y),
                "<b>Compare Values on Axis</b><br>" + ui->comboBox_PlotPixel_ScatterAxe_Axis->currentText(),
                QSL_ComponentNames,
                ui->comboBox_PlotPixel_ScatterAxe_Stat_X->currentText() + " of Pixel Values in " + ui->comboBox_PlotPixel_ScatterAxe_Image_X->currentText(),
                ui->comboBox_PlotPixel_ScatterAxe_Stat_Y->currentText() + " of Pixel Values in " + ui->comboBox_PlotPixel_ScatterAxe_Image_Y->currentText()),
            "Plot_Pixel_ScatterAxe",
            "All Components - Plot_Scatter_2D_Multi_XY");

        pChartView_Plot->chart()->legend()->setAlignment(Qt::AlignLeft);

        //table
        //to be done
    }
        break;

    case PLOT_MODE_PIXEL_ALL_IMG://---------------------------------------------------------
    {
        int img_x = ui->comboBox_PlotPixel_ScatterAxe_Image_X->currentIndex();
        int sta_x = ui->comboBox_PlotPixel_ScatterAxe_Stat_X->currentIndex();
        int sta_y = ui->comboBox_PlotPixel_ScatterAxe_Stat_Y->currentIndex();
        int com = ui->comboBox_PlotPixel_ScatterAxe_Component->currentIndex();
        int axe = ui->comboBox_PlotPixel_ScatterAxe_Axis->currentIndex();

        //create tmp vector in needed format
        vector<vector<double>> vvd_tmp_ImgCla_Y;
        vvd_tmp_ImgCla_Y.resize(vvvvvd_ImgComAxeStaCla_val.size() - 1);
        for(int img = 1; img < vvvvvd_ImgComAxeStaCla_val.size(); img++)     //start at 1 to ignore binary, because it is boring
            vvd_tmp_ImgCla_Y[img - 1] = vvvvvd_ImgComAxeStaCla_val[img][com][axe][sta_y];

        ERR(D_Plot::Plot_Scatter_2D_Multi_Y(
                pChartView_Plot,
                &(vvvvvd_ImgComAxeStaCla_val[img_x][com][axe][sta_x]),
                &(vvd_tmp_ImgCla_Y),
                "<b>Compare Values on Axis</b><br>" + ui->comboBox_PlotPixel_ScatterAxe_Axis->currentText(),
                QSL_ImageNames_noBinary,
                ui->comboBox_PlotPixel_ScatterAxe_Stat_X->currentText() + " of Pixel Values in " + ui->comboBox_PlotPixel_ScatterAxe_Image_X->currentText(),
                ui->comboBox_PlotPixel_ScatterAxe_Stat_Y->currentText() + " of Pixel Values in Images"),
            "Plot_Pixel_ScatterAxe",
            "All Images - Plot_Scatter_2D_Multi_Y");

        pChartView_Plot->chart()->legend()->setAlignment(Qt::AlignLeft);

        //table
        Table_PlottedData.set_data_d_2D_qsl_vd(
                    vvd_tmp_ImgCla_Y,
                    QSL_ImageNames_noBinary,
                    vvvvvd_ImgComAxeStaCla_val[img_x][com][axe][sta_x]);
    }
        break;

    default://------------------------------------------------------------------------------
        break;
    }
}

void D_AnalysisWindow::Plot_Comp_Feature()
{
    ERR(D_Plot::Plot_BarCore_Single(
            pChartView_Plot,
            vvd_FeaCom_fea[ui->comboBox_PlotComp_Feat_Feature->currentIndex()],
            "<b>Feature</b>",
            "SeriesName",
            QSL_ComponentNames,
            "Components",
            ui->comboBox_PlotComp_Feat_Feature->currentText()),
        "Plot_Comp_Feature",
        "Plot_BarCore_Single");

    pChartView_Plot->chart()->legend()->setVisible(false);

    //table
    Table_PlottedData.set_data_d_1D_qs_qsl(
                vvd_FeaCom_fea[ui->comboBox_PlotComp_Feat_Feature->currentIndex()],
                ui->comboBox_PlotComp_Feat_Feature->currentText(),
                QSL_ComponentNames);
}

void D_AnalysisWindow::Plot_Comp_FeatureHist()
{
    //basic variables
    vector<double> v_hist;
    double x_min, x_max, y_max, step;

    //calc
    ERR(D_Stat::Calc_Vector2Hist_1(
            &v_hist,
            &(vvd_FeaCom_fea[ui->comboBox_PlotComp_FeatHist_Feature->currentIndex()]),
            ui->spinBox_PlotComp_FeatHist_Classes->value(),
            &x_min,
            &x_max,
            &y_max,
            &step,
            ui->checkBox_PlotComp_FeatHist_Accumulate->isChecked(),
            ui->checkBox_PlotComp_FeatHist_Uniform->isChecked()),
        "Plot_Comp_FeatureHist",
        "Calc_Vector2Hist_1");

    //plot
    ERR(D_Plot::Plot_Hist_Single_Classes(
            pChartView_Plot,
            &v_hist,
            x_min,
            step,
            "<b>Histogram</b>",
            "Components",
            ui->comboBox_PlotComp_FeatHist_Feature->currentText(),
            "Amount of Components",
            false),
        "Plot_Comp_FeatureHist",
        "Plot_Hist_Single_Classes");

    //table
    Table_PlottedData.set_data_d_1D_qs_step(
                v_hist,
                "",
                x_min,
                step);
}

void D_AnalysisWindow::Plot_Comp_FeatureScatter()
{
    ERR(D_Plot::Plot_Scatter_2D_Single_Y(
            pChartView_Plot,
            &(vvd_FeaCom_fea[ui->comboBox_PlotComp_FeatScatter_Feature_X->currentIndex()]),
            &(vvd_FeaCom_fea[ui->comboBox_PlotComp_FeatScatter_Feature_Y->currentIndex()]),
            "<b>Compare Features</b>",
            "Components",
            ui->comboBox_PlotComp_FeatScatter_Feature_X->currentText(),
            ui->comboBox_PlotComp_FeatScatter_Feature_Y->currentText()),
        "Plot_Comp_FeatureScatter",
        "Plot_Scatter_2D_Single_Y");

    //table
    Table_PlottedData.set_data_d_1D_qs_vd(
                vvd_FeaCom_fea[ui->comboBox_PlotComp_FeatScatter_Feature_Y->currentIndex()],
                "",
                vvd_FeaCom_fea[ui->comboBox_PlotComp_FeatScatter_Feature_X->currentIndex()]);
}

void D_AnalysisWindow::Plot_Comp_Stat()
{
    switch (ui->comboBox_PlotComp_Stat_Mode->currentIndex()) {

    case PLOT_MODE_COMP_SINGLE:
    {
        //basic indices
        int img = ui->comboBox_PlotComp_Stat_Image->currentIndex();
        int sta = ui->comboBox_PlotComp_Stat_Stat->currentIndex();

        ERR(D_Plot::Plot_BarCore_Single(
                pChartView_Plot,
                vvvd_ImgStaCom_val[img][sta],
                "<b>Statistical Quantity</b><br>" + ui->comboBox_PlotComp_Stat_Image->currentText(),
                "SeriesName",
                QSL_ComponentNames,
                "Components",
                ui->comboBox_PlotComp_Stat_Stat->currentText()),
            "Plot_Comp_Stat",
            "Single - Plot_BarCore_Single");

        pChartView_Plot->chart()->legend()->setVisible(false);

        //table
        Table_PlottedData.set_data_d_1D_qs_qsl(
                    vvvd_ImgStaCom_val[img][sta],
                    "",
                    QSL_ComponentNames);
    }
        break;

    case PLOT_MODE_COMP_ALL_IMG:
    {
        //basic indices
        int sta = ui->comboBox_PlotComp_Stat_Stat->currentIndex();

        //basic variables
        vector<vector<double>> vvd_tmp_ImgCom;
        vvd_tmp_ImgCom.resize(vvvd_ImgStaCom_val.size() - 1);       //skip binary because its stats are boring
        for(int img = 1; img < vvvd_ImgStaCom_val.size(); img++)
            vvd_tmp_ImgCom[img - 1] = vvvd_ImgStaCom_val[img][sta];

        ERR(D_Plot::Plot_BarCore_Multi(
                pChartView_Plot,
                vvd_tmp_ImgCom,
                "<b>Statistical Quantity</b>",
                QSL_ImageNames_noBinary,
                QSL_ComponentNames,
                "Components",
                ui->comboBox_PlotComp_Stat_Stat->currentText()),
            "Plot_Comp_Stat",
            "All Images - Plot_BarCore_Multi");

        //table
        Table_PlottedData.set_data_d_2D_qsl_qsl(
                    vvd_tmp_ImgCom,
                    QSL_ImageNames_noBinary,
                    QSL_ComponentNames);
    }
        break;

    default:
        break;
    }
}

void D_AnalysisWindow::Plot_Comp_StatHist()
{
    switch (ui->comboBox_PlotComp_StatHist_Mode->currentIndex()) {

    case PLOT_MODE_COMP_SINGLE:
    {
        //get basic indices
        int img = ui->comboBox_PlotComp_StatHist_Image->currentIndex();
        int sta = ui->comboBox_PlotComp_StatHist_Stat->currentIndex();

        //basic variables
        vector<double> v_hist;
        double x_min, x_max, y_max, step;

        //calc
        ERR(D_Stat::Calc_Vector2Hist_1(
                &v_hist,
                &(vvvd_ImgStaCom_val[img][sta]),
                ui->spinBox_PlotComp_StatHist_Classes->value(),
                &x_min,
                &x_max,
                &y_max,
                &step,
                ui->checkBox_PlotComp_StatHist_Accumulate->isChecked(),
                ui->checkBox_PlotComp_StatHist_Uniform->isChecked()),
            "Plot_Comp_StatHist",
            "Single - Calc_Vector2Hist_1");

        //plot
        ERR(D_Plot::Plot_Hist_Single_Classes(
                pChartView_Plot,
                &v_hist,
                x_min,
                step,
                "<b>Histogram</b>",
                ui->comboBox_PlotComp_StatHist_Image->currentText(),
                ui->comboBox_PlotComp_StatHist_Stat->currentText(),
                "Amount of Components",
                false),
            "Plot_Comp_StatHist",
            "Single - Plot_Hist_Single_Classes");

        //table
        Table_PlottedData.set_data_d_1D_qs_step(
                    v_hist,
                    "",
                    x_min,
                    step);
    }
        break;

    case PLOT_MODE_COMP_ALL_IMG:
    {
        //get basic indices
        int sta = ui->comboBox_PlotComp_StatHist_Stat->currentIndex();

        //basic variables
        vector<vector<double>> vvd_tmp_ImgCom;
        vvd_tmp_ImgCom.resize(vvvd_ImgStaCom_val.size() - 1);       //skip binary because its stats are boring
        for(int img = 1; img < vvvd_ImgStaCom_val.size(); img++)
            vvd_tmp_ImgCom[img - 1] = vvvd_ImgStaCom_val[img][sta];

        vector<vector<double>> vvd_hist;
        double x_min, x_max, y_max, step;

        //calc
        ERR(D_Stat::Calc_Vector2Hist_2(
                &vvd_hist,
                &(vvd_tmp_ImgCom),
                ui->spinBox_PlotComp_StatHist_Classes->value(),
                &x_min,
                &x_max,
                &y_max,
                &step,
                ui->checkBox_PlotComp_StatHist_Accumulate->isChecked(),
                ui->checkBox_PlotComp_StatHist_Uniform->isChecked()),
            "Plot_Comp_StatHist",
            "All Images - Calc_Vector2Hist_2");

        //plot
        ERR(D_Plot::Plot_Hist_Multi_Classes(
                pChartView_Plot,
                &vvd_hist,
                x_min,
                x_max,
                y_max,
                step,
                "<b>Histogram</b>",
                QSL_ImageNames_noBinary,
                ui->comboBox_PlotComp_StatHist_Stat->currentText(),
                "Amount of Components",
                false),
            "Plot_Comp_StatHist",
            "All Images - Plot_Hist_Multi_Classes");

        //table
        Table_PlottedData.set_data_d_2D_qsl_step(
                    vvd_hist,
                    QSL_ImageNames_noBinary,
                    x_min,
                    step);
    }
        break;

    default:
        break;
    }
}

void D_AnalysisWindow::Plot_Comp_StatScatter()
{
    switch (ui->comboBox_PlotComp_StatScatter_Mode->currentIndex()) {

    case PLOT_MODE_COMP_SINGLE:
    {
        //get basic indices
        int img_x = ui->comboBox_PlotComp_StatScatter_Image_X->currentIndex();
        int img_y = ui->comboBox_PlotComp_StatScatter_Image_Y->currentIndex();
        int sta_x = ui->comboBox_PlotComp_StatScatter_Stat_X->currentIndex();
        int sta_y = ui->comboBox_PlotComp_StatScatter_Stat_Y->currentIndex();

        //plot
        ERR(D_Plot::Plot_Scatter_2D_Single_Y(
                pChartView_Plot,
                &(vvvd_ImgStaCom_val[img_x][sta_x]),
                &(vvvd_ImgStaCom_val[img_y][sta_y]),
                "<b>Compare Statistical Quantities</b>",
                "Components",
                ui->comboBox_PlotComp_StatScatter_Stat_X->currentText() + " of Values in Components in " + ui->comboBox_PlotComp_StatScatter_Image_X->currentText(),
                ui->comboBox_PlotComp_StatScatter_Stat_Y->currentText() + " of Values in Components in " + ui->comboBox_PlotComp_StatScatter_Image_Y->currentText()),
            "Plot_Comp_StatScatter",
            "Single - Plot_Scatter_2D_Single_Y");

        //table
        Table_PlottedData.set_data_d_1D_qs_vd(
                    vvvd_ImgStaCom_val[img_y][sta_y],
                    "",
                    vvvd_ImgStaCom_val[img_x][sta_x]);
    }
        break;

    case PLOT_MODE_COMP_ALL_IMG:
    {
        //get basic indices
        int img_x = ui->comboBox_PlotComp_StatScatter_Image_X->currentIndex();
        int sta_x = ui->comboBox_PlotComp_StatScatter_Stat_X->currentIndex();
        int sta_y = ui->comboBox_PlotComp_StatScatter_Stat_Y->currentIndex();

        //get data in needed format
        vector<vector<double>> vvd_tmp_ImgSta_y;
        vvd_tmp_ImgSta_y.resize(vvvd_ImgStaCom_val.size() - 1);
        for(int img_y = 1; img_y < vvvd_ImgStaCom_val.size(); img_y++)        //start at 1 to ignore binary, because it is boring
            vvd_tmp_ImgSta_y[img_y - 1] = vvvd_ImgStaCom_val[img_y][sta_y];

        //plot
        ERR(D_Plot::Plot_Scatter_2D_Multi_Y(
                pChartView_Plot,
                &(vvvd_ImgStaCom_val[img_x][sta_x]),
                &(vvd_tmp_ImgSta_y),
                "<b>Compare Statistical Quantities</b>",
                QSL_ImageNames_noBinary,
                ui->comboBox_PlotComp_StatScatter_Stat_X->currentText() + " of Values in Components in " + ui->comboBox_PlotComp_StatScatter_Image_X->currentText(),
                ui->comboBox_PlotComp_StatScatter_Stat_Y->currentText() + " of Values in Components in Images"),
            "Plot_Comp_StatScatter",
            "Single - Plot_Scatter_2D_Single_Y");

        //table
        Table_PlottedData.set_data_d_2D_qsl_vd(
                    vvd_tmp_ImgSta_y,
                    QSL_ImageNames_noBinary,
                    vvvd_ImgStaCom_val[img_x][sta_x]);
    }
        break;

    default:
        break;
    }
}

void D_AnalysisWindow::Plot_Comp_StatFeatScatter()
{
    switch (ui->comboBox_PlotComp_StatFeatScatter_Mode->currentIndex()) {

    case PLOT_MODE_COMP_SINGLE:
    {
        //get basic indices
        int fea_x = ui->comboBox_PlotComp_StatFeatScatter_Feature_X->currentIndex();
        int img_y = ui->comboBox_PlotComp_StatFeatScatter_Image_Y->currentIndex();
        int sta_y = ui->comboBox_PlotComp_StatFeatScatter_Stat_Y->currentIndex();

        //plot
        ERR(D_Plot::Plot_Scatter_2D_Single_Y(
                pChartView_Plot,
                &(vvd_FeaCom_fea[fea_x]),
                &(vvvd_ImgStaCom_val[img_y][sta_y]),
                "<b>Scatter Statistical Quantity vs Feature</b>",
                "Components",
                ui->comboBox_PlotComp_StatFeatScatter_Feature_X->currentText() + " of Components",
                ui->comboBox_PlotComp_StatFeatScatter_Stat_Y->currentText() + " of Values in Components in " + ui->comboBox_PlotComp_StatFeatScatter_Image_Y->currentText()),
            "Plot_Comp_StatFeatScatter",
            "Single - Plot_Scatter_2D_Single_Y");

        //table
        Table_PlottedData.set_data_d_1D_qs_vd(
                    vvvd_ImgStaCom_val[img_y][sta_y],
                    "",
                    vvd_FeaCom_fea[fea_x]);
    }
        break;

    case PLOT_MODE_COMP_ALL_IMG:
    {
        //get basic indices
        int fea_x = ui->comboBox_PlotComp_StatFeatScatter_Feature_X->currentIndex();
        int sta_y = ui->comboBox_PlotComp_StatFeatScatter_Stat_Y->currentIndex();

        //get data in needed format
        vector<vector<double>> vvd_tmp_ImgSta_y;
        vvd_tmp_ImgSta_y.resize(vvvd_ImgStaCom_val.size() - 1);
        for(int img_y = 1; img_y < vvvd_ImgStaCom_val.size(); img_y++)        //start at 1 to ignore binary, because it is boring
            vvd_tmp_ImgSta_y[img_y - 1] = vvvd_ImgStaCom_val[img_y][sta_y];

        //plot
        ERR(D_Plot::Plot_Scatter_2D_Multi_Y(
                pChartView_Plot,
                &(vvd_FeaCom_fea[fea_x]),
                &(vvd_tmp_ImgSta_y),
                "<b>Scatter Statistical Quantity vs Feature</b>",
                QSL_ImageNames_noBinary,
                ui->comboBox_PlotComp_StatFeatScatter_Feature_X->currentText() + " of Components",
                ui->comboBox_PlotComp_StatFeatScatter_Stat_Y->currentText() + " of Values in Components in Images"),
            "Plot_Comp_StatFeatScatter",
            "Single - Plot_Scatter_2D_Single_Y");

        //table
        Table_PlottedData.set_data_d_2D_qsl_vd(
                    vvd_tmp_ImgSta_y,
                    QSL_ImageNames_noBinary,
                    vvd_FeaCom_fea[fea_x]);
    }
        break;

    default:
        break;
    }
}

void D_AnalysisWindow::Plot_Img_Feature()
{
    //empty plot
    D_Plot::Plot_Empty(pChartView_Plot);

    //table
    Table_PlottedData.set_data_d_2D_qsl_qsl(
                vvd_FeaSta_fea,
                QSL_FeatureList,
                QSL_StatList);
}

void D_AnalysisWindow::Plot_Img_FeatureHist()
{
    //boooring... only 1 value -.-
    return;
}

void D_AnalysisWindow::Plot_Img_Stat()
{
    //basic indices
    int sta_img = ui->comboBox_PlotImg_Stat_StatImg->currentIndex();
    int sta_com = ui->comboBox_PlotImg_Stat_StatComp->currentIndex();

    //basic variables
    vector<double> vd_tmp_ImgSTA;
    vd_tmp_ImgSTA.resize(vvvd_ImgStaSta_val.size() - 1);       //skip binary because its stats are boring
    for(int img = 1; img < vvvd_ImgStaSta_val.size(); img++)
        vd_tmp_ImgSTA[img - 1] = vvvd_ImgStaSta_val[img][sta_com][sta_img];

    ERR(D_Plot::Plot_BarCore_Single(
            pChartView_Plot,
            vd_tmp_ImgSTA,
            "<b>Statistical Quantity</b>",
            "Series Name",
            QSL_ImageNames_noBinary,
            "Images",
            ui->comboBox_PlotImg_Stat_StatImg->currentText() +  " of " + ui->comboBox_PlotImg_Stat_StatComp->currentText() + " of Pixel-Values in Components"),
        "Plot_Img_Stat",
        "Plot_BarCore_Single");

    pChartView_Plot->chart()->legend()->setVisible(false);

    //table
    Table_PlottedData.set_data_d_1D_qs_qsl(
                vd_tmp_ImgSTA,
                "",
                QSL_ImageNames_noBinary);
}

void D_AnalysisWindow::Plot_Img_StatHist()
{
    //basic indices
    int sta_img = ui->comboBox_PlotImg_StatHist_StatImg->currentIndex();
    int sta_com = ui->comboBox_PlotImg_StatHist_StatComp->currentIndex();

    //basic variables
    vector<double> vd_tmp_ImgSTA;
    vd_tmp_ImgSTA.resize(vvvd_ImgStaSta_val.size() - 1);       //skip binary because its stats are boring
    for(int img = 1; img < vvvd_ImgStaSta_val.size(); img++)
        vd_tmp_ImgSTA[img - 1] = vvvd_ImgStaSta_val[img][sta_com][sta_img];

    vector<double> v_hist;
    double x_min, x_max, y_max, step;

    //calc
    ERR(D_Stat::Calc_Vector2Hist_1(
            &v_hist,
            &vd_tmp_ImgSTA,
            ui->spinBox_PlotImg_StatHist_Classes->value(),
            &x_min,
            &x_max,
            &y_max,
            &step,
            ui->checkBox_PlotImg_StatHist_Acc->isChecked(),
            ui->checkBox_PlotImg_StatHist_Uni->isChecked()),
        "Plot_Img_StatHist",
        "Single - Calc_Vector2Hist_1");

    //plot
    ERR(D_Plot::Plot_Hist_Single_Classes(
            pChartView_Plot,
            &v_hist,
            x_min,
            step,
            "<b>Histogram of Image-Statistics</b>",
            "Images",
            ui->comboBox_PlotImg_StatHist_StatImg->currentText() + " of " + ui->comboBox_PlotImg_StatHist_StatComp->currentText() + " of Pixel-Values in Components",
            "Amount of Images",
            false),
        "Plot_Img_StatHist",
        "Plot_Hist_Single_Classes");

    //table
    Table_PlottedData.set_data_d_1D_qs_step(
                v_hist,
                "",
                x_min,
                step);
}

void D_AnalysisWindow::Plot_Img_StatScatter()
{
    //basic indices
    int sta_img_x = ui->comboBox_PlotImg_StatScatter_StatImg_X->currentIndex();
    int sta_img_y = ui->comboBox_PlotImg_StatScatter_StatImg_Y->currentIndex();
    int sta_com_x = ui->comboBox_PlotImg_StatScatter_StatComp_X->currentIndex();
    int sta_com_y = ui->comboBox_PlotImg_StatScatter_StatComp_Y->currentIndex();

    //basic variables
    vector<double> vd_tmp_ImgSTA_X;
    vd_tmp_ImgSTA_X.resize(vvvd_ImgStaSta_val.size() - 1);       //skip binary because its stats are boring
    for(int img = 1; img < vvvd_ImgStaSta_val.size(); img++)
        vd_tmp_ImgSTA_X[img - 1] = vvvd_ImgStaSta_val[img][sta_com_x][sta_img_x];

    vector<double> vd_tmp_ImgSTA_Y;
    vd_tmp_ImgSTA_Y.resize(vvvd_ImgStaSta_val.size() - 1);       //skip binary because its stats are boring
    for(int img = 1; img < vvvd_ImgStaSta_val.size(); img++)
        vd_tmp_ImgSTA_Y[img - 1] = vvvd_ImgStaSta_val[img][sta_com_y][sta_img_y];

    //plot
    ERR(D_Plot::Plot_Scatter_2D_Single_Y(
            pChartView_Plot,
            &vd_tmp_ImgSTA_X,
            &vd_tmp_ImgSTA_Y,
            "<b>Compare Statistical Quantities</b>",
            "Images",
            ui->comboBox_PlotImg_StatScatter_StatImg_X->currentText() + " of " + ui->comboBox_PlotImg_StatScatter_StatComp_X->currentText() + " of Pixel-Values in Components",
            ui->comboBox_PlotImg_StatScatter_StatImg_Y->currentText() + " of " + ui->comboBox_PlotImg_StatScatter_StatComp_Y->currentText() + " of Pixel-Values in Components"),
        "Plot_Img_StatScatter",
        "Plot_Scatter_2D_Single_Y");

    //table
    Table_PlottedData.set_data_d_1D_qs_vd(
                vd_tmp_ImgSTA_Y,
                "",
                vd_tmp_ImgSTA_X);
}

void D_AnalysisWindow::Plot_Img_StatFeatScatter()
{
    //boooring... only 1 value -.-
    return;
}

void D_AnalysisWindow::Plot_Stack_Stat()
{
    //empty plot
    D_Plot::Plot_Empty(pChartView_Plot);

    //table
    Table_PlottedData.set_data_d_1D_qs_qsl(
                vvvd_StaStaSta_val[ui->comboBox_PlotStack_Stat_StatComp->currentIndex()][ui->comboBox_PlotStack_Stat_StatImg->currentIndex()],
                "",
                QSL_StatList);
}

void D_AnalysisWindow::Populate_CB()
{    
    Populate_CB_Stats();
    Populate_CB_Feature();
    Populate_CB_Geometrics();
    Populate_CB_Axe();
    Populate_CB_PlotTypes();
    Populate_CB_PlotModePixel();
    Populate_CB_PlotModeComp();
}

void D_AnalysisWindow::Populate_CB_Stats()
{
    ui->comboBox_ImgSta_Stat->addItems(QSL_StatList);
    ui->comboBox_PlotPixel_Axe_Stat->addItems(QSL_StatList);
    ui->comboBox_PlotPixel_ScatterAxe_Stat_X->addItems(QSL_StatList);
    ui->comboBox_PlotPixel_ScatterAxe_Stat_Y->addItems(QSL_StatList);

    ui->comboBox_PlotComp_Stat_Stat->addItems(QSL_StatList);
    ui->comboBox_PlotComp_StatHist_Stat->addItems(QSL_StatList);
    ui->comboBox_PlotComp_StatScatter_Stat_X->addItems(QSL_StatList);
    ui->comboBox_PlotComp_StatScatter_Stat_Y->addItems(QSL_StatList);
    ui->comboBox_PlotComp_StatFeatScatter_Stat_Y->addItems(QSL_StatList);

    ui->comboBox_PlotImg_FeatHist_Stat->addItems(QSL_StatList);
    ui->comboBox_PlotImg_Stat_StatImg->addItems(QSL_StatList);
    ui->comboBox_PlotImg_Stat_StatComp->addItems(QSL_StatList);
    ui->comboBox_PlotImg_StatHist_StatImg->addItems(QSL_StatList);
    ui->comboBox_PlotImg_StatHist_StatComp->addItems(QSL_StatList);
    ui->comboBox_PlotImg_StatScatter_StatImg_X->addItems(QSL_StatList);
    ui->comboBox_PlotImg_StatScatter_StatImg_Y->addItems(QSL_StatList);
    ui->comboBox_PlotImg_StatScatter_StatComp_X->addItems(QSL_StatList);
    ui->comboBox_PlotImg_StatScatter_StatComp_Y->addItems(QSL_StatList);
    ui->comboBox_PlotImg_StatFeatScatter_StatImg_X->addItems(QSL_StatList);
    ui->comboBox_PlotImg_StatFeatScatter_StatImg_Y->addItems(QSL_StatList);
    ui->comboBox_PlotImg_StatFeatScatter_StatComp_Y->addItems(QSL_StatList);

    ui->comboBox_PlotStack_Stat_StatComp->addItems(QSL_StatList);
    ui->comboBox_PlotStack_Stat_StatImg->addItems(QSL_StatList);
}

void D_AnalysisWindow::Populate_CB_Feature()
{
    ui->comboBox_ImgFea_Feature->addItems(QSL_FeatureList);

    ui->comboBox_PlotComp_Feat_Feature->addItems(QSL_FeatureList);
    ui->comboBox_PlotComp_FeatHist_Feature->addItems(QSL_FeatureList);
    ui->comboBox_PlotComp_FeatScatter_Feature_X->addItems(QSL_FeatureList);
    ui->comboBox_PlotComp_FeatScatter_Feature_Y->addItems(QSL_FeatureList);
    ui->comboBox_PlotComp_StatFeatScatter_Feature_X->addItems(QSL_FeatureList);

    ui->comboBox_PlotImg_FeatHist_Feature->addItems(QSL_FeatureList);
    ui->comboBox_PlotImg_StatFeatScatter_FeatComp_X->addItems(QSL_FeatureList);
}

void D_AnalysisWindow::Populate_CB_ImageNames()
{
    Populate_CB_ImageNames_Single(ui->comboBox_ImgFea_BaseImage);
    Populate_CB_ImageNames_Single(ui->comboBox_ImgVal_Image);
    Populate_CB_ImageNames_Single(ui->comboBox_ImgSta_Image);
    Populate_CB_ImageNames_Single(ui->comboBox_PlotPixel_Hist_Image);
    Populate_CB_ImageNames_Single(ui->comboBox_PlotPixel_Axe_Image);
    Populate_CB_ImageNames_Single(ui->comboBox_PlotPixel_ScatterValue_Image_X);
    Populate_CB_ImageNames_Single(ui->comboBox_PlotPixel_ScatterValue_Image_Y);
    Populate_CB_ImageNames_Single(ui->comboBox_PlotPixel_ScatterHist_Image_X);
    Populate_CB_ImageNames_Single(ui->comboBox_PlotPixel_ScatterHist_Image_Y);
    Populate_CB_ImageNames_Single(ui->comboBox_PlotPixel_ScatterAxe_Image_X);
    Populate_CB_ImageNames_Single(ui->comboBox_PlotPixel_ScatterAxe_Image_Y);

    Populate_CB_ImageNames_Single(ui->comboBox_PlotComp_Stat_Image);
    Populate_CB_ImageNames_Single(ui->comboBox_PlotComp_StatHist_Image);
    Populate_CB_ImageNames_Single(ui->comboBox_PlotComp_StatScatter_Image_X);
    Populate_CB_ImageNames_Single(ui->comboBox_PlotComp_StatScatter_Image_Y);
    Populate_CB_ImageNames_Single(ui->comboBox_PlotComp_StatFeatScatter_Image_Y);
}

void D_AnalysisWindow::Populate_CB_ImageNames_Single(QComboBox *CB)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL_ImageNames);
    CB->blockSignals(false);
}

void D_AnalysisWindow::Populate_CB_ComponentNames()
{
    Populate_CB_ComponentNames_Single(ui->comboBox_PlotPixel_Hist_Component);
    Populate_CB_ComponentNames_Single(ui->comboBox_PlotPixel_Axe_Component);
    Populate_CB_ComponentNames_Single(ui->comboBox_PlotPixel_ScatterValue_Component);
    Populate_CB_ComponentNames_Single(ui->comboBox_PlotPixel_ScatterHist_Component_X);
    Populate_CB_ComponentNames_Single(ui->comboBox_PlotPixel_ScatterHist_Component_Y);
    Populate_CB_ComponentNames_Single(ui->comboBox_PlotPixel_ScatterAxe_Component);
}

void D_AnalysisWindow::Populate_CB_ComponentNames_Single(QComboBox *CB)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL_ComponentNames);
    CB->blockSignals(false);
}

void D_AnalysisWindow::Populate_CB_Geometrics()
{
    Populate_CB_Geometrics_Single(ui->comboBox_ImgFea_Geometric);
    Populate_CB_Geometrics_Single(ui->comboBox_ImgSta_Geometric);
}

void D_AnalysisWindow::Populate_CB_Geometrics_Single(QComboBox *CB)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL_GeometricsList);
    CB->setCurrentIndex(c_GEO_CONTOUR);
    CB->blockSignals(false);
}

void D_AnalysisWindow::Populate_CB_Axe()
{
    Populate_CB_Single(ui->comboBox_PlotPixel_Axe_Axis, QSL_Axe);
    Populate_CB_Single(ui->comboBox_PlotPixel_ScatterAxe_Axis, QSL_Axe);
}

void D_AnalysisWindow::Populate_CB_PlotTypes()
{
    Populate_CB_Single(ui->comboBox_PlotPixel_Type, QSL_PlotTypes_Pixel);
    Populate_CB_Single(ui->comboBox_PlotComp_Type,  QSL_PlotTypes_Component);
    Populate_CB_Single(ui->comboBox_PlotImg_Type,   QSL_PlotTypes_Image);
    Populate_CB_Single(ui->comboBox_PlotStack_Type, QSL_PlotTypes_Stack);
}

void D_AnalysisWindow::Populate_CB_Single(QComboBox *CB, QStringList QSL)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->blockSignals(false);
}

void D_AnalysisWindow::Populate_CB_PlotModePixel()
{
    ui->comboBox_PlotPixel_Hist_Mode->addItems(QSL_PlotModes_Pixel);
    ui->comboBox_PlotPixel_Axe_Mode->addItems(QSL_PlotModes_Pixel);
    ui->comboBox_PlotPixel_ScatterValue_Mode->addItems(QSL_PlotModes_Pixel);
    ui->comboBox_PlotPixel_ScatterHist_Mode->addItems(QSL_PlotModes_Pixel);
    ui->comboBox_PlotPixel_ScatterAxe_Mode->addItems(QSL_PlotModes_Pixel);
}

void D_AnalysisWindow::Populate_CB_PlotModeComp()
{
    ui->comboBox_PlotComp_Stat_Mode->addItems(QSL_PlotModes_Comp);
    ui->comboBox_PlotComp_StatHist_Mode->addItems(QSL_PlotModes_Comp);
    ui->comboBox_PlotComp_StatScatter_Mode->addItems(QSL_PlotModes_Comp);
    ui->comboBox_PlotComp_StatFeatScatter_Mode->addItems(QSL_PlotModes_Comp);
}

void D_AnalysisWindow::Init_ComponentNames()
{
    if(!b_LabelLoaded)
        return;

    //get label number and check if there is at least one
    double lab_count;
    minMaxLoc(
                MA_Label,
                NULL,
                &lab_count);
    if(lab_count < 1)
    {
        b_LabelLoaded = false;
        return;
    }

    QSL_ComponentNames.clear();
    for(int c = 0; c < lab_count; c++)
        QSL_ComponentNames.append("Component_" + QString::number(c));
}

void D_AnalysisWindow::Rename_Image()
{
    if(QSL_ImageNames_noBinary.empty())
        return;

    bool ok;

    int img_pos = QInputDialog::getInt(
                this,
                tr("Rename Image"),
                tr("Chose the image number you want to rename:<br>"),
                QSL_ImageNames_noBinary.size(),
                1,
                QSL_ImageNames_noBinary.size(),
                1,
                &ok);
    if(!ok)
        return;

    QString img_name = QInputDialog::getText(
                this,
                tr("Rename Image"),
                tr("Chose a name for the chosen image"),
                QLineEdit::Normal,
                QSL_ImageNames[img_pos],
                &ok);
    if(!ok)
        return;

    QSL_ImageNames[img_pos] = img_name;
    QSL_ImageNames_noBinary[img_pos - 1] = img_name;

    Populate_CB_ImageNames();
    Update_Plot();
    Update_Images();
}

void D_AnalysisWindow::Rename_Component()
{
    if(QSL_ComponentNames.empty())
        return;

    bool ok;

    int com_pos = QInputDialog::getInt(
                this,
                tr("Rename Component"),
                tr("Chose the component number you want to rename:<br>"),
                0,
                0,
                QSL_ComponentNames.size(),
                1,
                &ok);
    if(!ok)
        return;

    QString com_name = QInputDialog::getText(
                this,
                tr("Rename Component"),
                tr("Chose a name for the chosen component"),
                QLineEdit::Normal,
                QSL_ComponentNames[com_pos],
                &ok);
    if(!ok)
        return;

    QSL_ComponentNames[com_pos] = com_name;

    Populate_CB_ComponentNames();
    Update_Plot();
    Update_Images();
}

void D_AnalysisWindow::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_AnalysisWindow", func, detail);
}

void D_AnalysisWindow::on_comboBox_ImgLab_Connectivity_currentIndexChanged(int index)
{
    if(index == 0)
        connectivity = 8;
    else
        connectivity = 4;
}

void D_AnalysisWindow::Init_Plot()
{
    delete ui->gridLayout_Plot->takeAt(0);
    pChartView_Plot = new QChartView();
    ui->gridLayout_Plot->addWidget(pChartView_Plot);
    pChartView_Plot->setRenderHint(QPainter::Antialiasing);
    pChartView_Plot->setRubberBand(QChartView::RectangleRubberBand);
    pChartView_Plot->setInteractive(true);
}

void D_AnalysisWindow::on_comboBox_PlotPixel_Hist_Mode_currentIndexChanged(int index)
{
    ui->comboBox_PlotPixel_Hist_Image->blockSignals(true);
    ui->comboBox_PlotPixel_Hist_Component->blockSignals(true);

    switch (index) {

    case PLOT_MODE_PIXEL_SINGLE:
        ui->comboBox_PlotPixel_Hist_Image->setEnabled(true);
        ui->comboBox_PlotPixel_Hist_Component->setEnabled(true);
        break;

    case PLOT_MODE_PIXEL_ALL_COMP:
        ui->comboBox_PlotPixel_Hist_Image->setEnabled(true);
        ui->comboBox_PlotPixel_Hist_Component->setEnabled(false);
        break;

    case PLOT_MODE_PIXEL_ALL_IMG:
        ui->comboBox_PlotPixel_Hist_Image->setEnabled(false);
        ui->comboBox_PlotPixel_Hist_Component->setEnabled(true);
        break;

    default:
        break;
    }

    ui->comboBox_PlotPixel_Hist_Image->blockSignals(false);
    ui->comboBox_PlotPixel_Hist_Component->blockSignals(false);
}

void D_AnalysisWindow::on_comboBox_PlotPixel_Axe_Mode_currentIndexChanged(int index)
{
    ui->comboBox_PlotPixel_Axe_Image->blockSignals(true);
    ui->comboBox_PlotPixel_Axe_Component->blockSignals(true);

    switch (index) {

    case PLOT_MODE_PIXEL_SINGLE:
        ui->comboBox_PlotPixel_Axe_Image->setEnabled(true);
        ui->comboBox_PlotPixel_Axe_Component->setEnabled(true);
        break;

    case PLOT_MODE_PIXEL_ALL_COMP:
        ui->comboBox_PlotPixel_Axe_Image->setEnabled(true);
        ui->comboBox_PlotPixel_Axe_Component->setEnabled(false);
        break;

    case PLOT_MODE_PIXEL_ALL_IMG:
        ui->comboBox_PlotPixel_Axe_Image->setEnabled(false);
        ui->comboBox_PlotPixel_Axe_Component->setEnabled(true);
        break;

    default:
        break;
    }

    ui->comboBox_PlotPixel_Axe_Image->blockSignals(false);
    ui->comboBox_PlotPixel_Axe_Component->blockSignals(false);
}

void D_AnalysisWindow::on_comboBox_PlotPixel_ScatterValue_Mode_currentIndexChanged(int index)
{
    ui->comboBox_PlotPixel_ScatterValue_Image_Y->blockSignals(true);
    ui->comboBox_PlotPixel_ScatterValue_Component->blockSignals(true);

    switch (index) {

    case PLOT_MODE_PIXEL_SINGLE:
        ui->comboBox_PlotPixel_ScatterValue_Image_Y->setEnabled(true);
        ui->comboBox_PlotPixel_ScatterValue_Component->setEnabled(true);
        break;

    case PLOT_MODE_PIXEL_ALL_COMP:
        ui->comboBox_PlotPixel_ScatterValue_Image_Y->setEnabled(true);
        ui->comboBox_PlotPixel_ScatterValue_Component->setEnabled(false);
        break;

    case PLOT_MODE_PIXEL_ALL_IMG:
        ui->comboBox_PlotPixel_ScatterValue_Image_Y->setEnabled(false);
        ui->comboBox_PlotPixel_ScatterValue_Component->setEnabled(true);
        break;

    default:
        break;
    }

    ui->comboBox_PlotPixel_ScatterValue_Image_Y->blockSignals(false);
    ui->comboBox_PlotPixel_ScatterValue_Component->blockSignals(false);
}

void D_AnalysisWindow::on_comboBox_PlotPixel_ScatterHist_Mode_currentIndexChanged(int index)
{
    ui->comboBox_PlotPixel_ScatterHist_Image_Y->blockSignals(true);
    ui->comboBox_PlotPixel_ScatterHist_Component_Y->blockSignals(true);

    switch (index) {

    case PLOT_MODE_PIXEL_SINGLE:
        ui->comboBox_PlotPixel_ScatterHist_Image_Y->setEnabled(true);
        ui->comboBox_PlotPixel_ScatterHist_Component_Y->setEnabled(true);
        break;

    case PLOT_MODE_PIXEL_ALL_COMP:
        ui->comboBox_PlotPixel_ScatterHist_Image_Y->setEnabled(true);
        ui->comboBox_PlotPixel_ScatterHist_Component_Y->setEnabled(false);
        break;

    case PLOT_MODE_PIXEL_ALL_IMG:
        ui->comboBox_PlotPixel_ScatterHist_Image_Y->setEnabled(false);
        ui->comboBox_PlotPixel_ScatterHist_Component_Y->setEnabled(true);
        break;

    default:
        break;
    }

    ui->comboBox_PlotPixel_ScatterHist_Image_Y->blockSignals(false);
    ui->comboBox_PlotPixel_ScatterHist_Component_Y->blockSignals(false);
}

void D_AnalysisWindow::on_comboBox_PlotPixel_ScatterAxe_Mode_currentIndexChanged(int index)
{
    ui->comboBox_PlotPixel_ScatterAxe_Image_Y->blockSignals(true);
    ui->comboBox_PlotPixel_ScatterAxe_Component->blockSignals(true);

    switch (index) {

    case PLOT_MODE_PIXEL_SINGLE:
        ui->comboBox_PlotPixel_ScatterAxe_Image_Y->setEnabled(true);
        ui->comboBox_PlotPixel_ScatterAxe_Component->setEnabled(true);
        break;

    case PLOT_MODE_PIXEL_ALL_COMP:
        ui->comboBox_PlotPixel_ScatterAxe_Image_Y->setEnabled(true);
        ui->comboBox_PlotPixel_ScatterAxe_Component->setEnabled(false);
        break;

    case PLOT_MODE_PIXEL_ALL_IMG:
        ui->comboBox_PlotPixel_ScatterAxe_Image_Y->setEnabled(false);
        ui->comboBox_PlotPixel_ScatterAxe_Component->setEnabled(true);
        break;

    default:
        break;
    }

    ui->comboBox_PlotPixel_ScatterAxe_Image_Y->blockSignals(false);
    ui->comboBox_PlotPixel_ScatterAxe_Component->blockSignals(false);
}

void D_AnalysisWindow::on_comboBox_PlotComp_Stat_Mode_currentIndexChanged(int index)
{
    ui->comboBox_PlotComp_Stat_Image->blockSignals(true);

    switch (index) {

    case PLOT_MODE_COMP_SINGLE:
        ui->comboBox_PlotComp_Stat_Image->setEnabled(true);
        break;

    case PLOT_MODE_COMP_ALL_IMG:
        ui->comboBox_PlotComp_Stat_Image->setEnabled(false);
        break;

    default:
        break;
    }

    ui->comboBox_PlotComp_Stat_Image->blockSignals(false);
}

void D_AnalysisWindow::on_comboBox_PlotComp_StatHist_Mode_currentIndexChanged(int index)
{
    ui->comboBox_PlotComp_StatHist_Image->blockSignals(true);

    switch (index) {

    case PLOT_MODE_COMP_SINGLE:
        ui->comboBox_PlotComp_StatHist_Image->setEnabled(true);
        break;

    case PLOT_MODE_COMP_ALL_IMG:
        ui->comboBox_PlotComp_StatHist_Image->setEnabled(false);
        break;

    default:
        break;
    }

    ui->comboBox_PlotComp_StatHist_Image->blockSignals(false);
}

void D_AnalysisWindow::on_comboBox_PlotComp_StatScatter_Mode_currentIndexChanged(int index)
{
    ui->comboBox_PlotComp_StatScatter_Image_Y->blockSignals(true);

    switch (index) {

    case PLOT_MODE_COMP_SINGLE:
        ui->comboBox_PlotComp_StatScatter_Image_Y->setEnabled(true);
        break;

    case PLOT_MODE_COMP_ALL_IMG:
        ui->comboBox_PlotComp_StatScatter_Image_Y->setEnabled(false);
        break;

    default:
        break;
    }

    ui->comboBox_PlotComp_StatScatter_Image_Y->blockSignals(false);
}

void D_AnalysisWindow::on_comboBox_PlotComp_StatFeatScatter_Mode_currentIndexChanged(int index)
{
    ui->comboBox_PlotComp_StatFeatScatter_Image_Y->blockSignals(true);

    switch (index) {

    case PLOT_MODE_COMP_SINGLE:
        ui->comboBox_PlotComp_StatFeatScatter_Image_Y->setEnabled(true);
        break;

    case PLOT_MODE_COMP_ALL_IMG:
        ui->comboBox_PlotComp_StatFeatScatter_Image_Y->setEnabled(false);
        break;

    default:
        break;
    }

    ui->comboBox_PlotComp_StatFeatScatter_Image_Y->blockSignals(false);
}

void D_AnalysisWindow::on_checkBox_Plot_X_Range_clicked(bool checked)
{
    if(checked)
        Update_View_Plot();
    else
        Update_Plot();
}

void D_AnalysisWindow::on_checkBox_Plot_Y_Range_clicked(bool checked)
{
    if(checked)
        Update_View_Plot();
    else
        Update_Plot();
}
