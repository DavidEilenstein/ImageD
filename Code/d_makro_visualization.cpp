/************************************
 *   added:     30.01.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_makro_visualization.h"
#include "ui_d_makro_visualization.h"

D_MAKRO_Visualization::D_MAKRO_Visualization(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_Visualization)
{
    //ui
    ui->setupUi(this);
    Populate_All();

    //store
    pStore = pStorage;

    //Viewer
    View_Page.set_GV(ui->graphicsView_Page);
    View_Output.set_GV(ui->graphicsView_Output);
    View_Page.connect_Zoom(&View_Output);

    //CONNECTS

    //Images
    connect(ui->pushButton_Add,                         SIGNAL(clicked(bool)),                      this,                           SLOT(Images_Add()));
    connect(ui->pushButton_Clear,                       SIGNAL(clicked(bool)),                      this,                           SLOT(Images_Clear()));
    connect(ui->action_Add_Images,                      SIGNAL(triggered(bool)),                    this,                           SLOT(Images_Add()));
    connect(ui->action_Clear_Stack,                     SIGNAL(triggered(bool)),                    this,                           SLOT(Images_Clear()));
    //Save
    connect(ui->pushButton_SaveSingle,                  SIGNAL(clicked(bool)),                      this,                           SLOT(Save_Single()));
    connect(ui->pushButton_SaveStack,                   SIGNAL(clicked(bool)),                      this,                           SLOT(Save_Stack()));
    connect(ui->action_Save_Single,                     SIGNAL(triggered(bool)),                    this,                           SLOT(Save_Single()));
    connect(ui->action_Save_Stack,                      SIGNAL(triggered(bool)),                    this,                           SLOT(Save_Stack()));
    //Makro
    connect(ui->action_AutoValRange,                    SIGNAL(triggered(bool)),                    this,                           SLOT(GammaSpread_MinMax()));
    //Color
    connect(ui->pushButton_ColorSet,                    SIGNAL(clicked(bool)),                      this,                           SLOT(ColorDialog()));
    //Info
    connect(&View_Page,                                 SIGNAL(MouseMoved_Value(QString)),          ui->label_PageInfo_ValAtCursor, SLOT(setText(QString)));
    //Paint
    connect(&View_Page,                                 SIGNAL(MouseClicked_Pos(int,int)),          this,                           SLOT(Paint_GetClickPos(int,int)));
    connect(&View_Output,                               SIGNAL(MouseClicked_Pos(int,int)),          this,                           SLOT(Paint_GetClickPos(int,int)));

    this->showMaximized();

    setWindowTitle("ImageD - Visualization");
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
}

D_MAKRO_Visualization::~D_MAKRO_Visualization()
{
    delete ui;
}

void D_MAKRO_Visualization::resizeEvent(QResizeEvent *event)
{
    event->accept();
    Update_Views();
}

void D_MAKRO_Visualization::mousePressEvent(QMouseEvent *event)
{
    //start new line on right click
    if(event->button() == Qt::RightButton)
        if(paint_initialized)
            Paint_NewLine = true;
}

void D_MAKRO_Visualization::closeEvent(QCloseEvent *event)
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

void D_MAKRO_Visualization::Images_Add()
{
    if(!defined_dataSet)
        Images_DefineDialog();
    if(!defined_dataSet)
        return;

    qDebug() << "Load_Images";

    QStringList QSL_Paths = QFileDialog::getOpenFileNames(
                this,
                tr("Add images to stack"),
                pStore->dir_M_Visualization()->path(),
                tr("Image files (*.tif *.tiff *.TIF *.TIFF)"));

    if(QSL_Paths.empty())
        return;

    //clear stack
    QSL_Images_Path.clear();
    FIL_Images.clear();
    QSL_Images_BaseNames.clear();
    QSL_Images_FileNames.clear();

    //laod stack (filepaths)
    QSL_Images_Path.append(QSL_Paths);

    //process filenames
    for(int i = 0; i < QSL_Images_Path.size(); i++)
    {
        QFileInfo FI_Img_In(QSL_Images_Path[i]);

        if(FI_Img_In.exists())
        {
            FIL_Images.append(FI_Img_In);
            QString QS_FileName = FI_Img_In.fileName().replace(".", "_");
            QSL_Images_FileNames.append(QS_FileName);
            QSL_Images_BaseNames.append(FI_Img_In.baseName());
        }
    }

    //populate/enable ui
    Populate_Images();
    ui->groupBox_Page->setEnabled(true);
    ui->groupBox_Output->setEnabled(true);
    ui->pushButton_Clear->setEnabled(true);
    ui->comboBox_Image->setEnabled(true);
    ui->action_Clear_Stack->setEnabled(true);
    ui->action_Save_Single->setEnabled(true);
    ui->action_Save_Stack->setEnabled(true);
    ui->groupBox_Scalebar->setEnabled(true);

    //export file
    pStore->set_dir_M_Visualization(QSL_Images_Path.first());

    //check/create settings dir and page subdirs
    DIR_Settings.setPath(FIL_Images.first().absoluteDir().path() + "/ImageD_Visualization_Settings");
    if(!DIR_Settings.exists())
        QDir().mkdir(DIR_Settings.path());
    for(int page = 0; page < pages_number; page++)
    {
        QDir DIR_tmp_Page(DIR_Settings.path() + "/page_" + QString::number(page));
        if(!DIR_tmp_Page.exists())
            QDir().mkdir(DIR_tmp_Page.path());
    }

    //update
    ImgProc_Load();

    //on first useful images, set useful ranges
    if(firstRealImages)
        GammaSpread_MinMax();
    firstRealImages = false;
}

void D_MAKRO_Visualization::Images_Clear()
{
    defined_dataSet = false;
    firstRealImages = true;

    QSL_Pages.clear();
    QSL_Images_BaseNames.clear();
    QSL_Images_Path.clear();
    FIL_Images.clear();

    ui->comboBox_Image->blockSignals(true);
    ui->comboBox_Image->clear();
    ui->comboBox_Image->blockSignals(false);

    ui->comboBox_Page->blockSignals(true);
    ui->comboBox_Page->clear();
    ui->comboBox_Page->blockSignals(false);

    ui->groupBox_Page->setEnabled(false);
    ui->groupBox_Output->setEnabled(false);
    ui->pushButton_Clear->setEnabled(false);
    ui->comboBox_Image->setEnabled(false);
    ui->action_Clear_Stack->setEnabled(false);
    ui->action_Save_Single->setEnabled(false);
    ui->action_Save_Stack->setEnabled(false);
}

void D_MAKRO_Visualization::Images_DefineDialog()
{
    if(defined_dataSet)
        return;

    bool ok;

    pages_number = QInputDialog::getInt(
                this,
                tr("Define Dataset"),
                tr("Number of pages expected in input images:<br>"),
                3,
                1,
                99999999,
                1,
                &ok);
    if(!ok)
        return;

    QSL_Pages.clear();
    for(int p = 0; p < pages_number; p++)
    {
        QString page_name = QInputDialog::getText(
                    this,
                    tr("Define Dataset"),
                    tr("Name of page:<br>"),
                    QLineEdit::Normal,
                    QString("Page_" + QString::number(p)),
                    &ok);
        if(!ok)
            return;
        QSL_Pages.append(page_name);
    }

    defined_dataSet = true;

    Populate_Pages();
    Parameters_Init();
    Images_Init(); 
}

void D_MAKRO_Visualization::Save_Single()
{
    if(FIL_Images.empty())
        return;

    if(!stackProcActive)
    {
        QString QS_SaveDir = QFileDialog::getExistingDirectory(
                    this,
                    tr("Save Results (Single)"),
                    pStore->dir_M_Visualization()->path());

        if(QS_SaveDir == 0)
        {
            return;
        }
        else
        {
            DIR_SaveCurrentImage.setPath(QS_SaveDir);
            if(!DIR_SaveCurrentImage.exists())
                QDir().mkdir(DIR_SaveCurrentImage.path());
        }
    }

    pStore->set_dir_M_Visualization(
                View_Output.Save_Image(
                    DIR_SaveCurrentImage.path() + "/Result - " + QSL_Images_FileNames[current_image] + ".jpg"));

    ui->comboBox_ViewImgType->setCurrentIndex(c_IMG_OUT_COLOR);
    for(int page = 0; page < pages_number; page++)
    {
        ui->comboBox_Page->setCurrentIndex(page);
        View_Page.Save_Image(
                    DIR_SaveCurrentImage.path() + "/" + QSL_Pages[page] + " - " + QSL_Images_FileNames[current_image] + ".jpg");
    }
}

void D_MAKRO_Visualization::Save_Stack()
{
    if(FIL_Images.empty())
        return;

    QString QS_SaveDir = QFileDialog::getExistingDirectory(
                this,
                tr("Save Results (Stack)"),
                pStore->dir_M_Visualization()->path());

    if(QS_SaveDir == 0)
        return;

    stackProcActive = true;
    this->setEnabled(false);

    //create subfolder for output
    unsigned int count = 0;
    QString QS_Folder_Out_Main = QS_SaveDir + "/Results_0";
    while(QDir(QS_Folder_Out_Main).exists())
    {
        count++;
        QS_Folder_Out_Main = QS_SaveDir + "/Results_" + QString::number(count);
    }

    DIR_SaveMaster.setPath(QS_Folder_Out_Main);
    QDir().mkdir(DIR_SaveMaster.path());

    DIR_SaveStack.setPath(DIR_SaveMaster.path() + "/Stack");
    QDir().mkdir(DIR_SaveStack.path());

    DIR_SaveImages.setPath(DIR_SaveMaster.path() + "/Images");
    QDir().mkdir(DIR_SaveImages.path());

    for(int img = 0; img < FIL_Images.size(); img++)
    {
        DIR_SaveCurrentImage.setPath(DIR_SaveImages.path() + "/" + QSL_Images_FileNames[img]);
        QDir().mkdir(DIR_SaveCurrentImage.path());

        ui->comboBox_Image->setCurrentIndex(img);
        Save_Single();

        View_Output.Save_Image(DIR_SaveStack.path() + "/Result - " + QSL_Images_FileNames[current_image] + ".jpg");
    }

    this->setEnabled(true);
    stackProcActive = false;
}

void D_MAKRO_Visualization::Populate_All()
{
    Populate_Proc();
    Populate_Geometrics();
    Populate_ViewImgType();
    Populate_Paint();
}

void D_MAKRO_Visualization::Populate_Single(QComboBox *CB, QStringList QSL)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->blockSignals(false);
}

void D_MAKRO_Visualization::Populate_Images()
{
    Populate_Single(ui->comboBox_Image, QSL_Images_FileNames);
}

void D_MAKRO_Visualization::Populate_Pages()
{
    Populate_Single(ui->comboBox_Page, QSL_Pages);
}

void D_MAKRO_Visualization::Populate_Proc()
{
    Populate_Single(ui->comboBox_Processing, QSL_ProcTypes);
}

void D_MAKRO_Visualization::Populate_ViewImgType()
{
    Populate_Single(ui->comboBox_ViewImgType, QSL_ImgType);
}

void D_MAKRO_Visualization::Populate_Geometrics()
{
    Populate_Single(ui->comboBox_Bin_Geometric, QSL_GeometricsList);
}

void D_MAKRO_Visualization::Populate_Paint()
{
    Populate_Single(ui->comboBox_Bin_Paint_FG_BG, QSL_Paint_Color);
    Populate_Single(ui->comboBox_Bin_Paint_Type, QSL_Paint_Type);
}

void D_MAKRO_Visualization::BlockSignals_Ui(bool block)
{
    ui->groupBox_Bin_Smooth->blockSignals(block);
    ui->spinBox_Bin_Size->blockSignals(block);
    ui->doubleSpinBox_Bin_Sigma->blockSignals(block);
    ui->doubleSpinBox_Bin_Threshold->blockSignals(block);
    ui->groupBox_Bin_Segmentation->blockSignals(block);
    ui->doubleSpinBox_Bin_Distance->blockSignals(block);
    ui->checkBox_Bin_InclNonSeed->blockSignals(block);
    ui->checkBox_Bin_InclBorder->blockSignals(block);
    ui->groupBox_Reduce->blockSignals(block);
    ui->comboBox_Bin_Geometric->blockSignals(block);

    ui->doubleSpinBox_Val_In_Min->blockSignals(block);
    ui->doubleSpinBox_Val_In_Max->blockSignals(block);
    ui->doubleSpinBox_Val_Out_Min->blockSignals(block);
    ui->doubleSpinBox_Val_Out_Max->blockSignals(block);
    ui->doubleSpinBox_Val_Gamma->blockSignals(block);

    ui->spinBox_Color_Red->blockSignals(block);
    ui->spinBox_Color_Green->blockSignals(block);
    ui->spinBox_Color_Blue->blockSignals(block);
    ui->spinBox_Color_Alpha->blockSignals(block);

    ui->groupBox_Bin_Paint->blockSignals(block);
    ui->comboBox_Bin_Paint_FG_BG->blockSignals(block);
    ui->comboBox_Bin_Paint_Type->blockSignals(block);
    ui->spinBox_Bin_Paint_Width->blockSignals(block);

    ui->comboBox_Processing->blockSignals(block);
    ui->stackedWidget_Processing->blockSignals(block);
    ui->comboBox_Image->blockSignals(block);
    ui->comboBox_Page->blockSignals(block);
}

void D_MAKRO_Visualization::ProcSet_SetToUi()
{
    if(!defined_dataSet)
        return;

    BlockSignals_Ui(true);

    ui->groupBox_Bin_Smooth->setChecked(            static_cast<bool>   (vvd_Parameter_PagePar[current_page][c_PAR_BIN_BLUR_DO]));
    ui->spinBox_Bin_Size->setValue(                 static_cast<int>    (vvd_Parameter_PagePar[current_page][c_PAR_BIN_BLUR_SIZE]));
    ui->doubleSpinBox_Bin_Sigma->setValue(          static_cast<double> (vvd_Parameter_PagePar[current_page][c_PAR_BIN_BLUR_SIGMA]));
    ui->doubleSpinBox_Bin_Threshold->setValue(      static_cast<double> (vvd_Parameter_PagePar[current_page][c_PAR_BIN_BIN_THRES]));
    ui->groupBox_Bin_Segmentation->setChecked(      static_cast<bool>   (vvd_Parameter_PagePar[current_page][c_PAR_BIN_SEG_DO]));
    ui->doubleSpinBox_Bin_Distance->setValue(       static_cast<double> (vvd_Parameter_PagePar[current_page][c_PAR_BIN_SEG_DISTANCE]));
    ui->checkBox_Bin_InclNonSeed->setChecked(       static_cast<bool>   (vvd_Parameter_PagePar[current_page][c_PAR_BIN_SEG_INCLNONSEED]));
    ui->checkBox_Bin_InclBorder->setChecked(        static_cast<bool>   (vvd_Parameter_PagePar[current_page][c_PAR_BIN_SEG_INCLBORDER]));
    ui->groupBox_Reduce->setChecked(                static_cast<bool>   (vvd_Parameter_PagePar[current_page][c_PAR_BIN_GEO_DO]));
    ui->comboBox_Bin_Geometric->setCurrentIndex(    static_cast<int>    (vvd_Parameter_PagePar[current_page][c_PAR_BIN_GEO_GEOMETRIC]));

    ui->doubleSpinBox_Val_In_Min->setValue(         static_cast<double> (vvd_Parameter_PagePar[current_page][c_PAR_VAL_IN_MIN]));
    ui->doubleSpinBox_Val_In_Max->setValue(         static_cast<double> (vvd_Parameter_PagePar[current_page][c_PAR_VAL_IN_MAX]));
    ui->doubleSpinBox_Val_Out_Min->setValue(        static_cast<double> (vvd_Parameter_PagePar[current_page][c_PAR_VAL_OUT_MIN]));
    ui->doubleSpinBox_Val_Out_Max->setValue(        static_cast<double> (vvd_Parameter_PagePar[current_page][c_PAR_VAL_OUT_MAX]));
    ui->doubleSpinBox_Val_Gamma->setValue(          static_cast<double> (vvd_Parameter_PagePar[current_page][c_PAR_VAL_GAMMA]));

    ui->spinBox_Color_Red->setValue(                static_cast<int>    (vvd_Parameter_PagePar[current_page][c_PAR_COL_RED]));
    ui->spinBox_Color_Green->setValue(              static_cast<int>    (vvd_Parameter_PagePar[current_page][c_PAR_COL_GREEN]));
    ui->spinBox_Color_Blue->setValue(               static_cast<int>    (vvd_Parameter_PagePar[current_page][c_PAR_COL_BLUE]));
    ui->spinBox_Color_Alpha->setValue(              static_cast<int>    (vvd_Parameter_PagePar[current_page][c_PAR_COL_ALPHA]));

    ui->groupBox_Bin_Paint->setChecked(             static_cast<bool>   (vvd_Parameter_PagePar[current_page][c_PAR_PAINT_DO]));
    ui->comboBox_Bin_Paint_FG_BG->setCurrentIndex(  static_cast<int>    (vvd_Parameter_PagePar[current_page][c_PAR_PAINT_COLOR]));
    ui->comboBox_Bin_Paint_Type->setCurrentIndex(   static_cast<int>    (vvd_Parameter_PagePar[current_page][c_PAR_PAINT_TYPE]));
    ui->spinBox_Bin_Paint_Width->setValue(          static_cast<int>    (vvd_Parameter_PagePar[current_page][c_PAR_PAINT_WIDTH]));

    ui->comboBox_Processing->setCurrentIndex(       static_cast<int>    (vvd_Parameter_PagePar[current_page][c_PAR_TYPE]));
    ui->stackedWidget_Processing->setCurrentIndex(  static_cast<int>    (vvd_Parameter_PagePar[current_page][c_PAR_TYPE]));

    switch (static_cast<int>(vvd_Parameter_PagePar[current_page][c_PAR_PAINT_TYPE])) {
    case c_PAINT_LINE:      ui->spinBox_Bin_Paint_Width->setEnabled(true);      break;
    case c_PAINT_FILL:      ui->spinBox_Bin_Paint_Width->setEnabled(false);     break;
    default:                                                                    break;}

    BlockSignals_Ui(false);
}

void D_MAKRO_Visualization::GammaSpread_MinMax()
{
    for(int page = 0; page < pages_number; page++)
    {
        double min, max;
        ERR(D_Img_Proc::MinMax_of_Mat(
                &(vMA_Image_Pages_In[page]),
                &min,
                &max),
            "ImgProc_Load",
            "MinMax_of_Mat");

        vvd_Parameter_PagePar[page][c_PAR_VAL_IN_MIN] = min;
        vvd_Parameter_PagePar[page][c_PAR_VAL_IN_MAX] = max;
        vvd_Parameter_PagePar[page][c_PAR_VAL_GAMMA] = 1.0;
    }

    ProcSet_SetToUi();
    Update_ImgProc();
}

void D_MAKRO_Visualization::Parameters_Init()
{
    vvd_Parameter_PagePar.clear();
    vvd_Parameter_PagePar.resize(pages_number);
    for(int page = 0; page < vvd_Parameter_PagePar.size(); page++)
    {
        vvd_Parameter_PagePar[page].resize(c_PAR_NUMBER_OF, 0.0);

        vvd_Parameter_PagePar[page][c_PAR_TYPE]                 = c_PROC_VALUES;

        vvd_Parameter_PagePar[page][c_PAR_BIN_BLUR_DO]          = 1.0;
        vvd_Parameter_PagePar[page][c_PAR_BIN_BLUR_SIZE]        = 3.0;
        vvd_Parameter_PagePar[page][c_PAR_BIN_BLUR_SIGMA]       = 1.0;
        vvd_Parameter_PagePar[page][c_PAR_BIN_BIN_THRES]        = 127.0;

        vvd_Parameter_PagePar[page][c_PAR_BIN_SEG_DO]           = 1.0;
        vvd_Parameter_PagePar[page][c_PAR_BIN_SEG_DISTANCE]     = 20.0;
        vvd_Parameter_PagePar[page][c_PAR_BIN_SEG_INCLNONSEED]  = 1.0;
        vvd_Parameter_PagePar[page][c_PAR_BIN_SEG_INCLBORDER]   = 1.0;

        vvd_Parameter_PagePar[page][c_PAR_BIN_GEO_DO]           = 1.0;
        vvd_Parameter_PagePar[page][c_PAR_BIN_GEO_GEOMETRIC]    = c_GEO_CONTOUR;

        vvd_Parameter_PagePar[page][c_PAR_VAL_IN_MIN]           = 0.0;
        vvd_Parameter_PagePar[page][c_PAR_VAL_IN_MAX]           = 255.0;
        vvd_Parameter_PagePar[page][c_PAR_VAL_OUT_MIN]          = 0.0;
        vvd_Parameter_PagePar[page][c_PAR_VAL_OUT_MAX]          = 255.0;
        vvd_Parameter_PagePar[page][c_PAR_VAL_GAMMA]            = 1.0;

        double r = 255.0;
        double g = 255.0;
        double b = 255.0;
        switch (page) {
        case 0:     r = 255;    g = 0;      b = 0;      break;  //red
        case 1:     r = 0;      g = 255;    b = 0;      break;  //green
        case 2:     r = 0;      g = 0;      b = 255;    break;  //blue
        case 3:     r = 255;    g = 255;    b = 0;      break;  //yellow
        case 4:     r = 255;    g = 0;      b = 255;    break;  //magenta
        case 5:     r = 0;      g = 255;    b = 255;    break;  //cyan
        case 6:     r = 255;    g = 255;    b = 255;    break;  //white
        default:                                        break;}
        vvd_Parameter_PagePar[page][c_PAR_COL_RED]              = r;
        vvd_Parameter_PagePar[page][c_PAR_COL_GREEN]            = g;
        vvd_Parameter_PagePar[page][c_PAR_COL_BLUE]             = b;

        double alpha = 255.0;
        switch (pages_number) {

        case 1:
        case 2:
        case 3:
            alpha = 255;
            break;

        case 4:
        case 5:
        case 6:
            alpha = 85;

        case 7:
            alpha = 63;
            break;

        default:
            alpha = 255.0 / (pages_number + 2);
            break;
        }
        vvd_Parameter_PagePar[page][c_PAR_COL_ALPHA]            = alpha;

        vvd_Parameter_PagePar[page][c_PAR_PAINT_DO]             = 1.0;
        vvd_Parameter_PagePar[page][c_PAR_PAINT_TYPE]           = c_PAINT_LINE;
        vvd_Parameter_PagePar[page][c_PAR_PAINT_WIDTH]          = 3.0;
        vvd_Parameter_PagePar[page][c_PAR_PAINT_COLOR]          = c_PAINT_FG;
    }

    ProcSet_SetToUi();
}

void D_MAKRO_Visualization::Images_Init()
{
    vMA_Image_Pages_In.clear();
    vMA_Image_Pages_In.resize(pages_number);
    for(int page = 0; page < pages_number; page++)
        ERR(D_Img_Proc::Convert_Color(
                &(vMA_Image_Pages_In[page]),
                pStore->get_Adress(0),
                CV_BGR2GRAY));

    vMA_Image_Pages_Out_Gray.clear();
    vMA_Image_Pages_Out_Gray.resize(pages_number);
    for(int page = 0; page < pages_number; page++)
        ERR(D_Img_Proc::Convert_Color(
                &(vMA_Image_Pages_Out_Gray[page]),
                pStore->get_Adress(0),
                CV_BGR2GRAY));

    vMA_Image_Pages_Out_Color.clear();
    vMA_Image_Pages_Out_Color.resize(pages_number);
    for(int page = 0; page < pages_number; page++)
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Image_Pages_Out_Color[page]),
                pStore->get_Adress(0)));

    MA_Output = pStore->get_Adress(0)->clone();
}

void D_MAKRO_Visualization::Paint_GetClickPos(int x, int y)
{
    //paint?
    if(!vvd_Parameter_PagePar[current_page][c_PAR_PAINT_DO])
        return;
    if(static_cast<int>(vvd_Parameter_PagePar[current_page][c_PAR_TYPE]) != c_PROC_BINARY)
        return;

    if(!paint_initialized)
        Paint_Init();

    //Save last point
    if(Paint_NewLine)
    {
        Paint_PtLast = Point(x, y);
        Paint_NewLine = false;
    }
    else
    {
        Paint_PtLast = Paint_PtCurr;
    }

    //save current point
    Paint_PtCurr = Point(x, y);

    //paint
    switch (static_cast<int>(vvd_Parameter_PagePar[current_page][c_PAR_PAINT_TYPE])) {
    case c_PAINT_LINE:  Paint_Line();   break;
    case c_PAINT_FILL:  Paint_Fill();   break;
    default:                            break;}

    //Export painted
    Paint_Export();
    Update_ImgProc();
}

void D_MAKRO_Visualization::Paint_Init()
{
    if(paint_initialized)
        return;
    qDebug() << "Paint_Init";

    //Foreground
    FI_Paint_FG.setFile(DIR_Settings.path() + "/page_" + QString::number(current_page) + "/" + QSL_Images_FileNames[current_image] + " - CustomPainted_FG.png");
    if(!FI_Paint_FG.exists())
    {
        MA_Paint_FG = Mat::zeros(vMA_Image_Pages_In[current_page].size(), CV_8UC1);
    }
    else
    {
        ERR(D_Img_Proc::Load_From_Path(
                &MA_Paint_FG,
                FI_Paint_FG.absoluteFilePath()),
            "Paint_Init",
            "Load FG");
    }

    //Background
    FI_Paint_BG.setFile(DIR_Settings.path() + "/page_" + QString::number(current_page) + "/" + QSL_Images_FileNames[current_image] + " - CustomPainted_BG.png");
    if(!FI_Paint_BG.exists())
    {
        MA_Paint_BG = Mat::zeros(vMA_Image_Pages_In[current_page].size(), CV_8UC1);
    }
    else
    {
        ERR(D_Img_Proc::Load_From_Path(
                &MA_Paint_BG,
                FI_Paint_BG.absoluteFilePath()),
            "Paint_Init",
            "Load BG");
    }

    Paint_NewLine = true;
    paint_initialized = true;

    Paint_Export();
    Update_ImgProc();
}

void D_MAKRO_Visualization::Paint_Export()
{
    if(!paint_initialized)
        return;
    qDebug() << "Paint_Export";

    //Foreground
    QImage QI_tmp_save_FG;
    ERR(D_Img_Proc::Convert_Mat_to_QImage(
            &QI_tmp_save_FG,
            &MA_Paint_FG),
        "Paint_Export",
        "D_Img_Proc::Convert_Mat_to_QImage - FG");
    QI_tmp_save_FG.save(FI_Paint_FG.absoluteFilePath(), 0, -1);
    qDebug() << "Export:" << FI_Paint_FG.absoluteFilePath();

    //Background
    QImage QI_tmp_save_BG;
    ERR(D_Img_Proc::Convert_Mat_to_QImage(
            &QI_tmp_save_BG,
            &MA_Paint_BG),
        "Paint_Export",
        "D_Img_Proc::Convert_Mat_to_QImage - BG");
    QI_tmp_save_BG.save(FI_Paint_BG.absoluteFilePath(), 0, -1);
    qDebug() << "Export:" << FI_Paint_BG.absoluteFilePath();
}

void D_MAKRO_Visualization::Paint_Line()
{
    if(!paint_initialized)
        return;
    qDebug() << "Paint_Line";

    switch (static_cast<int>(vvd_Parameter_PagePar[current_page][c_PAR_PAINT_COLOR])) {

    case c_PAINT_FG:
    {
        ERR(D_Img_Proc::Draw_Line(
                &MA_Paint_FG,
                Paint_PtLast.x,
                Paint_PtLast.y,
                Paint_PtCurr.x,
                Paint_PtCurr.y,
                vvd_Parameter_PagePar[current_page][c_PAR_PAINT_WIDTH],
                255),
            "Paint_Line",
            "Draw_Line");

        ERR(D_Img_Proc::Draw_Line(
                &MA_Paint_BG,
                Paint_PtLast.x,
                Paint_PtLast.y,
                Paint_PtCurr.x,
                Paint_PtCurr.y,
                vvd_Parameter_PagePar[current_page][c_PAR_PAINT_WIDTH],
                0),
            "Paint_Line",
            "Draw_Line");
    }
        break;

    case c_PAINT_BG:
    {
        ERR(D_Img_Proc::Draw_Line(
                &MA_Paint_BG,
                Paint_PtLast.x,
                Paint_PtLast.y,
                Paint_PtCurr.x,
                Paint_PtCurr.y,
                vvd_Parameter_PagePar[current_page][c_PAR_PAINT_WIDTH],
                255),
            "Paint_Line",
            "Draw_Line");

        ERR(D_Img_Proc::Draw_Line(
                &MA_Paint_FG,
                Paint_PtLast.x,
                Paint_PtLast.y,
                Paint_PtCurr.x,
                Paint_PtCurr.y,
                vvd_Parameter_PagePar[current_page][c_PAR_PAINT_WIDTH],
                0),
            "Paint_Line",
            "Draw_Line");
    }
        break;

    default:
        break;
    }
}

void D_MAKRO_Visualization::Paint_Fill()
{
    if(!paint_initialized)
        return;
    qDebug() << "Paint_Fill";

    switch (static_cast<int>(vvd_Parameter_PagePar[current_page][c_PAR_PAINT_COLOR])) {

    case c_PAINT_FG:
    {
        ERR(D_Img_Proc::Floodfill(
                &MA_Paint_FG,
                Paint_PtCurr.x,
                Paint_PtCurr.y,
                255),
            "Paint_Fill",
            "Floodfill");

        ERR(D_Img_Proc::Floodfill(
                &MA_Paint_BG,
                Paint_PtCurr.x,
                Paint_PtCurr.y,
                0),
            "Paint_Fill",
            "Floodfill");
    }
        break;

    case c_PAINT_BG:
    {
        ERR(D_Img_Proc::Floodfill(
                &MA_Paint_BG,
                Paint_PtCurr.x,
                Paint_PtCurr.y,
                255),
            "Paint_Fill",
            "Floodfill");

        ERR(D_Img_Proc::Floodfill(
                &MA_Paint_FG,
                Paint_PtCurr.x,
                Paint_PtCurr.y,
                0),
            "Paint_Fill",
            "Floodfill");
    }
        break;

    default:
        break;
    }
}

void D_MAKRO_Visualization::Paint_Reset()
{
    if(!paint_initialized)
        return;
    qDebug() << "Paint_Reset";

    MA_Paint_FG = Mat::zeros(vMA_Image_Pages_In[current_page].size(), CV_8UC1);
    MA_Paint_BG = Mat::zeros(vMA_Image_Pages_In[current_page].size(), CV_8UC1);

    Paint_Export();
    Update_ImgProc();
}

void D_MAKRO_Visualization::Update_Views()
{
    if(FIL_Images.empty())
        return;

    switch (ui->comboBox_ViewImgType->currentIndex()) {

    case c_IMG_IN:
        View_Page.Update_Image(&(vMA_Image_Pages_In[current_page]));
        break;

    case c_IMG_OUT_GRAY:
        View_Page.Update_Image(&(vMA_Image_Pages_Out_Gray[current_page]));
        break;

    case c_IMG_OUT_COLOR:
        View_Page.Update_Image(&(vMA_Image_Pages_Out_Color[current_page]));
        break;

    default:
        break;
    }

    View_Output.Update_Image(&MA_Output);

    Update_Ui();
}

void D_MAKRO_Visualization::Update_ImgProc()
{
    if(FIL_Images.empty())
        return;

    for(int page = 0; page < pages_number; page++)
    {
        ImgProc_PageProc(page);
        ImgProc_PseudoColor(page);
    }

    ImgProc_Merge_Output();
    ImgProc_Scalebar();

    Update_Views();
}

void D_MAKRO_Visualization::Update_ImageInfo()
{
    switch (ui->comboBox_ViewImgType->currentIndex()) {

    case c_IMG_IN:
    {
        ui->label_PageInfo_Size->setText(QString::number(vMA_Image_Pages_In[current_page].cols) + "x" + QString::number(vMA_Image_Pages_In[current_page].rows));

        double min, max;
        ERR(D_Img_Proc::MinMax_of_Mat(
                &(vMA_Image_Pages_In[current_page]),
                &min,
                &max),
            "ImgProc_Load",
            "MinMax_of_Mat");
        ui->label_PageInfo_Range->setText(QString::number(min) + "-" + QString::number(max));
    }
        break;

    case c_IMG_OUT_GRAY:
    {
        ui->label_PageInfo_Size->setText(QString::number(vMA_Image_Pages_Out_Gray[current_page].cols) + "x" + QString::number(vMA_Image_Pages_Out_Gray[current_page].rows));

        double min, max;
        ERR(D_Img_Proc::MinMax_of_Mat(
                &(vMA_Image_Pages_Out_Gray[current_page]),
                &min,
                &max),
            "ImgProc_Load",
            "MinMax_of_Mat");
        ui->label_PageInfo_Range->setText(QString::number(min) + "-" + QString::number(max));
    }
        break;

    case c_IMG_OUT_COLOR:
    {
        ui->label_PageInfo_Size->setText(QString::number(vMA_Image_Pages_Out_Color[current_page].cols) + "x" + QString::number(vMA_Image_Pages_Out_Color[current_page].rows));

        double min, max;
        ERR(D_Img_Proc::MinMax_of_Mat(
                &(vMA_Image_Pages_Out_Color[current_page]),
                &min,
                &max),
            "ImgProc_Load",
            "MinMax_of_Mat");
        ui->label_PageInfo_Range->setText(QString::number(min) + "-" + QString::number(max));
    }
        break;

    default:
        break;
    }


}

void D_MAKRO_Visualization::Update_ColorPreview()
{
    ui->label_Color_Preview->setStyleSheet("background-color: rgba(" +
                                           QString::number(vvd_Parameter_PagePar[current_page][c_PAR_COL_RED])  + ", " +
                                           QString::number(vvd_Parameter_PagePar[current_page][c_PAR_COL_GREEN]) + ", " +
                                           QString::number(vvd_Parameter_PagePar[current_page][c_PAR_COL_BLUE]) + ", " +
                                           QString::number(vvd_Parameter_PagePar[current_page][c_PAR_COL_ALPHA]) + ");");
}

void D_MAKRO_Visualization::Update_Ui()
{
    if(this->isEnabled())
        return;

    this->repaint();
    qApp->processEvents();
}

void D_MAKRO_Visualization::ColorDialog()
{
    QColor color_current(qRgba(
                             vvd_Parameter_PagePar[current_page][c_PAR_COL_RED],
                             vvd_Parameter_PagePar[current_page][c_PAR_COL_GREEN],
                             vvd_Parameter_PagePar[current_page][c_PAR_COL_BLUE],
                             vvd_Parameter_PagePar[current_page][c_PAR_COL_ALPHA]));


    QColor color_new = color_current;
    color_new = QColorDialog::getColor(
                color_current,
                this,
                tr("Select color"));

    if(color_new.isValid())
    {
        vvd_Parameter_PagePar[current_page][c_PAR_COL_RED] = color_new.red();
        vvd_Parameter_PagePar[current_page][c_PAR_COL_GREEN] = color_new.green();
        vvd_Parameter_PagePar[current_page][c_PAR_COL_BLUE] = color_new.blue();
        vvd_Parameter_PagePar[current_page][c_PAR_COL_ALPHA] = color_new.alpha();
        ui->spinBox_Color_Red->setValue(vvd_Parameter_PagePar[current_page][c_PAR_COL_RED]);
        ui->spinBox_Color_Green->setValue(vvd_Parameter_PagePar[current_page][c_PAR_COL_GREEN]);
        ui->spinBox_Color_Blue->setValue(vvd_Parameter_PagePar[current_page][c_PAR_COL_BLUE]);
        ui->spinBox_Color_Alpha->setValue(vvd_Parameter_PagePar[current_page][c_PAR_COL_ALPHA]);
    }

    Update_ColorPreview();
    Update_ImgProc();
}

void D_MAKRO_Visualization::ImgProc_Load()
{
    for(int page = 0; page < vMA_Image_Pages_In.size(); page++)
    {
        qDebug() << "load" << page << FIL_Images[current_image].absoluteFilePath();
        Mat MA_tmp_in;
        ERR(D_Img_Proc::Load_From_Path_Multi(
                &MA_tmp_in,
                FIL_Images[current_image].absoluteFilePath(),
                page + 1),
            "ImgProc_Load",
            "Load_From_Path_Multi");

        ERR(D_Img_Proc::Convert_Depth_NoScaling(
                &(vMA_Image_Pages_In[page]),
                &MA_tmp_in,
                CV_64F),
            "ImgProc_Load",
            "Convert_Depth_NoScaling");

        MA_tmp_in.release();
    }

    Update_ImgProc();
    Update_ImageInfo();
    Update_ColorPreview();
}

void D_MAKRO_Visualization::ImgProc_PageProc(int page)
{
    switch (static_cast<int>(vvd_Parameter_PagePar[page][c_PAR_TYPE])) {

    case c_PROC_SKIP:
    {
        vMA_Image_Pages_Out_Gray[page] = Mat::zeros(vMA_Image_Pages_In[page].size(), vMA_Image_Pages_In[page].type());
    }
        break;

    case c_PROC_COPY:
    {
        ERR(D_Img_Proc::Duplicate(
                &(vMA_Image_Pages_Out_Gray[page]),
                &(vMA_Image_Pages_In[page])),
            "ImgProc_PageProc",
            "c_PROC_COPY - Duplicate");
    }
        break;   

    case c_PROC_BINARY:
    {
        //Blur
        Mat MA_tmp_blur;
        if(vvd_Parameter_PagePar[page][c_PAR_BIN_BLUR_DO])
        {
            ERR(D_Img_Proc::Filter_Gauss(
                    &MA_tmp_blur,
                    &(vMA_Image_Pages_In[page]),
                    static_cast<int>(vvd_Parameter_PagePar[page][c_PAR_BIN_BLUR_SIZE] / 2),
                    static_cast<int>(vvd_Parameter_PagePar[page][c_PAR_BIN_BLUR_SIZE] / 2),
                    BORDER_DEFAULT,
                    vvd_Parameter_PagePar[page][c_PAR_BIN_BLUR_SIGMA],
                    vvd_Parameter_PagePar[page][c_PAR_BIN_BLUR_SIGMA]),
                "ImgProc_PageProc",
                "c_PROC_BINARY - Blur - Filter_Gauss");
        }
        else
        {
            ERR(D_Img_Proc::Duplicate(
                    &MA_tmp_blur,
                    &(vMA_Image_Pages_In[page])),
                "ImgProc_PageProc",
                "c_PROC_BINARY - Don't Blur - Duplicate");
        }

        //Thres
        Mat MA_tmp_thres;
        ERR(D_Img_Proc::Threshold_Absolute_1C(
                &MA_tmp_thres,
                &MA_tmp_blur,
                vvd_Parameter_PagePar[page][c_PAR_BIN_BIN_THRES]),
            "ImgProc_PageProc",
            "c_PROC_BINARY - Thres - Threshold_Absolute_1C");

        //Segmentation
        Mat MA_tmp_segmentation;
        if(vvd_Parameter_PagePar[page][c_PAR_BIN_SEG_DO])
        {
            ERR(D_Img_Proc::Transformation_Watershed_Auto(
                    &MA_tmp_segmentation,
                    &MA_tmp_thres,
                    vvd_Parameter_PagePar[page][c_PAR_BIN_SEG_DISTANCE],
                    vvd_Parameter_PagePar[page][c_PAR_BIN_SEG_INCLNONSEED],
                    false,
                    !vvd_Parameter_PagePar[page][c_PAR_BIN_SEG_INCLBORDER]),
                "ImgProc_PageProc",
                "c_PROC_BINARY - Segmentation - Transformation_Watershed_Auto");
        }
        else
        {
            ERR(D_Img_Proc::Duplicate(
                    &MA_tmp_segmentation,
                    &MA_tmp_thres),
                "ImgProc_PageProc",
                "c_PROC_BINARY - No Segmentation - Duplicate");
        }

        //Reduce
        Mat MA_tmp_geo;
        if(vvd_Parameter_PagePar[page][c_PAR_BIN_GEO_DO])
        {
            ERR(D_Img_Proc::Reduce_Geometric(
                    &MA_tmp_geo,
                    &MA_tmp_segmentation,
                    vvd_Parameter_PagePar[page][c_PAR_BIN_GEO_GEOMETRIC],
                    8,
                    2,
                    255),
                "ImgProc_PageProc",
                "c_PROC_BINARY - reduce - Reduce_Geometric");
        }
        else
        {
            ERR(D_Img_Proc::Threshold_Relative_1C(
                    &MA_tmp_geo,
                    &MA_tmp_segmentation,
                    1,
                    0),
                "ImgProc_PageProc",
                "c_PROC_BINARY - don't reduce - Threshold_Relative_1C");
        }

        //Paint
        Mat MA_tmp_paint;
        if(vvd_Parameter_PagePar[page][c_PAR_PAINT_DO] && paint_initialized)
        {
            Mat MA_tmp_PaintFG;
            ERR(D_Img_Proc::Math_ImgImg_Add(
                    &MA_tmp_PaintFG,
                    &MA_tmp_geo,
                    &MA_Paint_FG),
                "ImgProc_PageProc",
                "c_PROC_BINARY - paint FG - Math_ImgImg_Add");

            ERR(D_Img_Proc::Math_ImgImg_Diff(
                    &MA_tmp_paint,
                    &MA_tmp_PaintFG,
                    &MA_Paint_BG),
                "ImgProc_PageProc",
                "c_PROC_BINARY - paint BG - Math_ImgImg_Diff");

            MA_tmp_PaintFG.release();
        }
        else
        {
            ERR(D_Img_Proc::Duplicate(
                    &MA_tmp_paint,
                    &MA_tmp_geo),
                "ImgProc_PageProc",
                "c_PROC_BINARY - don't paint - Duplicate");
        }

        //Double
        ERR(D_Img_Proc::Convert_Depth_NoScaling(
                &(vMA_Image_Pages_Out_Gray[page]),
                &MA_tmp_paint,
                CV_64F),
            "ImgProc_PageProc",
            "c_PROC_BINARY - Convert_Depth_NoScaling");

        MA_tmp_blur.release();
        MA_tmp_thres.release();
        MA_tmp_segmentation.release();
        MA_tmp_geo.release();
        MA_tmp_paint.release();
    }
        break;

    case c_PROC_VALUES:
    {
        ERR(D_Img_Proc::GammaSpread_1C(
                &(vMA_Image_Pages_Out_Gray[page]),
                &(vMA_Image_Pages_In[page]),
                vvd_Parameter_PagePar[page][c_PAR_VAL_GAMMA],
                vvd_Parameter_PagePar[page][c_PAR_VAL_IN_MIN],
                vvd_Parameter_PagePar[page][c_PAR_VAL_IN_MAX],
                vvd_Parameter_PagePar[page][c_PAR_VAL_OUT_MIN],
                vvd_Parameter_PagePar[page][c_PAR_VAL_OUT_MAX]),
            "ImgProc_PageProc",
            "c_PROC_VALUES");
    }
        break;

    default:
        break;
    }
}

void D_MAKRO_Visualization::ImgProc_PseudoColor(int page)
{
    ERR(D_Img_Proc::Convert_Color_RGBA(
            &(vMA_Image_Pages_Out_Color[page]),
            &(vMA_Image_Pages_Out_Gray[page]),
            vvd_Parameter_PagePar[page][c_PAR_COL_RED],
            vvd_Parameter_PagePar[page][c_PAR_COL_GREEN],
            vvd_Parameter_PagePar[page][c_PAR_COL_BLUE],
            vvd_Parameter_PagePar[page][c_PAR_COL_ALPHA]),
        "ImgProc_PseudoColor",
        "Convert_Color_RGBA");
}

void D_MAKRO_Visualization::ImgProc_Merge_Output()
{
    qDebug() << "ImgProc_Merge_Output";
    //temporary store data
    vector<int> vR, vG, vB, vA;
    vR.resize(pages_number);
    vG.resize(pages_number);
    vB.resize(pages_number);
    vA.resize(pages_number);

    for(int page = 0; page < pages_number; page++)
    {
        vR[page] = static_cast<int>(vvd_Parameter_PagePar[page][c_PAR_COL_RED]);
        vG[page] = static_cast<int>(vvd_Parameter_PagePar[page][c_PAR_COL_GREEN]);
        vB[page] = static_cast<int>(vvd_Parameter_PagePar[page][c_PAR_COL_BLUE]);
        vA[page] = static_cast<int>(vvd_Parameter_PagePar[page][c_PAR_COL_ALPHA]);
    }

    ERR(D_Img_Proc::Merge(
            &MA_Output,
            vMA_Image_Pages_Out_Gray,
            vR,
            vG,
            vB,
            vA),
        "ImgProc_Merge_Output",
        "Merge");
}

void D_MAKRO_Visualization::ImgProc_Scalebar()
{
    if(!ui->groupBox_Scalebar->isChecked())
        return;

    int bar_length_px = static_cast<int>(Scalebar_Barsize / Scalebar_Pixelsize);

    Point bar_start_point(
                MA_Output.cols - 10,
                MA_Output.rows - 10);

    Point bar_end_point(
                bar_start_point.x - bar_length_px,
                bar_start_point.y);

    ERR(D_Img_Proc::Draw_Line(
            &MA_Output,
            bar_start_point.x,
            bar_start_point.y,
            bar_end_point.x,
            bar_end_point.y,
            5,
            255),
        "ImgProc_Scalebar",
        "Draw_Line");

    ERR(D_Img_Proc::Draw_Text(
            &MA_Output,
            QString::number(Scalebar_Barsize) + Scalebar_Unit,
            bar_end_point.x,
            bar_end_point.y - 15,
            1,
            0.7,
            255),
        "ImgProc_Scalebar",
        "Draw_Line");
}

void D_MAKRO_Visualization::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_MAKRO_Visualization", func, detail);
}

void D_MAKRO_Visualization::on_comboBox_Image_currentIndexChanged(int index)
{
    current_image = index;
    paint_initialized = false;
    ImgProc_Load();
    Update_Views();
    ui->label_PageInfo_ValAtCursor->setText("ValueAtCursor");
}

void D_MAKRO_Visualization::on_comboBox_Page_currentIndexChanged(int index)
{
    current_page = index;
    ProcSet_SetToUi();
    Update_Views();
    Update_ImageInfo();
    Update_ColorPreview();
    ui->label_PageInfo_ValAtCursor->setText("ValueAtCursor");
}

void D_MAKRO_Visualization::on_comboBox_ViewImgType_currentIndexChanged(int index)
{
    index;
    Update_Views();
    Update_ImageInfo();
}

void D_MAKRO_Visualization::on_comboBox_Processing_currentIndexChanged(int index)
{
    vvd_Parameter_PagePar[current_page][c_PAR_TYPE] = static_cast<double>(index);
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_groupBox_Bin_Smooth_clicked(bool checked)
{
    vvd_Parameter_PagePar[current_page][c_PAR_BIN_BLUR_DO] = static_cast<double>(checked);
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_spinBox_Bin_Size_valueChanged(int arg1)
{
    vvd_Parameter_PagePar[current_page][c_PAR_BIN_BLUR_SIZE] = static_cast<double>(arg1);
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_doubleSpinBox_Bin_Sigma_valueChanged(double arg1)
{
    vvd_Parameter_PagePar[current_page][c_PAR_BIN_BLUR_SIGMA] = arg1;
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_doubleSpinBox_Bin_Threshold_valueChanged(double arg1)
{
    vvd_Parameter_PagePar[current_page][c_PAR_BIN_BIN_THRES] = arg1;
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_groupBox_Bin_Segmentation_clicked(bool checked)
{
    vvd_Parameter_PagePar[current_page][c_PAR_BIN_SEG_DO] = static_cast<double>(checked);
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_doubleSpinBox_Bin_Distance_valueChanged(double arg1)
{
    vvd_Parameter_PagePar[current_page][c_PAR_BIN_SEG_DISTANCE] = arg1;
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_checkBox_Bin_InclNonSeed_clicked(bool checked)
{
    vvd_Parameter_PagePar[current_page][c_PAR_BIN_SEG_INCLNONSEED] = static_cast<double>(checked);
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_checkBox_Bin_InclBorder_clicked(bool checked)
{
    vvd_Parameter_PagePar[current_page][c_PAR_BIN_SEG_INCLBORDER] = static_cast<double>(checked);
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_groupBox_Reduce_clicked(bool checked)
{
    vvd_Parameter_PagePar[current_page][c_PAR_BIN_GEO_DO] = static_cast<double>(checked);
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_comboBox_Bin_Geometric_currentIndexChanged(int index)
{
    vvd_Parameter_PagePar[current_page][c_PAR_BIN_GEO_GEOMETRIC] = static_cast<double>(index);
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_doubleSpinBox_Val_Out_Min_valueChanged(double arg1)
{
    vvd_Parameter_PagePar[current_page][c_PAR_VAL_OUT_MIN] = arg1;
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_doubleSpinBox_Val_Out_Max_valueChanged(double arg1)
{
    vvd_Parameter_PagePar[current_page][c_PAR_VAL_OUT_MAX] = arg1;
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_doubleSpinBox_Val_In_Min_valueChanged(double arg1)
{
    vvd_Parameter_PagePar[current_page][c_PAR_VAL_IN_MIN] = arg1;
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_doubleSpinBox_Val_In_Max_valueChanged(double arg1)
{
    vvd_Parameter_PagePar[current_page][c_PAR_VAL_IN_MAX] = arg1;
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_doubleSpinBox_Val_Gamma_valueChanged(double arg1)
{
    vvd_Parameter_PagePar[current_page][c_PAR_VAL_GAMMA] = arg1;
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_spinBox_Color_Red_valueChanged(int arg1)
{
    vvd_Parameter_PagePar[current_page][c_PAR_COL_RED] = static_cast<double>(arg1);
    Update_ColorPreview();
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_spinBox_Color_Green_valueChanged(int arg1)
{
    vvd_Parameter_PagePar[current_page][c_PAR_COL_GREEN] = static_cast<double>(arg1);
    Update_ColorPreview();
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_spinBox_Color_Blue_valueChanged(int arg1)
{
    vvd_Parameter_PagePar[current_page][c_PAR_COL_BLUE] = static_cast<double>(arg1);
    Update_ColorPreview();
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_spinBox_Color_Alpha_valueChanged(int arg1)
{
    vvd_Parameter_PagePar[current_page][c_PAR_COL_ALPHA] = static_cast<double>(arg1);
    Update_ColorPreview();
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_groupBox_Bin_Paint_clicked(bool checked)
{
    vvd_Parameter_PagePar[current_page][c_PAR_PAINT_DO] = static_cast<double>(checked);
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_comboBox_Bin_Paint_Type_currentIndexChanged(int index)
{
    ui->spinBox_Bin_Paint_Width->setEnabled(index == c_PAINT_LINE);

    vvd_Parameter_PagePar[current_page][c_PAR_PAINT_TYPE] = static_cast<double>(index);
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_comboBox_Bin_Paint_FG_BG_currentIndexChanged(int index)
{
    vvd_Parameter_PagePar[current_page][c_PAR_PAINT_COLOR] = static_cast<double>(index);
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_spinBox_Bin_Paint_Width_valueChanged(int arg1)
{
    vvd_Parameter_PagePar[current_page][c_PAR_PAINT_WIDTH] = static_cast<double>(arg1);
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_pushButton_Bin_Paint_Reset_clicked()
{
    Paint_Reset();
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_lineEdit_Scalebar_Unit_textChanged(const QString &arg1)
{
    Scalebar_Unit = arg1;
    ui->doubleSpinBox_Scalebar_Barsize->setSuffix(Scalebar_Unit);
    ui->doubleSpinBox_Scalebar_Pixelsize->setSuffix(Scalebar_Unit);
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_doubleSpinBox_Scalebar_Pixelsize_valueChanged(double arg1)
{
    Scalebar_Pixelsize = arg1;
    ui->doubleSpinBox_Scalebar_Barsize->setMinimum(arg1);
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_doubleSpinBox_Scalebar_Barsize_valueChanged(double arg1)
{
    Scalebar_Barsize = arg1;
    Update_ImgProc();
}

void D_MAKRO_Visualization::on_groupBox_Scalebar_clicked()
{
    Update_ImgProc();
}
