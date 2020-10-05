/************************************
 *   added:     24.09.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_makro_segmentationassistant.h"
#include "ui_d_makro_segmentationassistant.h"

D_MAKRO_SegmentationAssistant::D_MAKRO_SegmentationAssistant(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_SegmentationAssistant)
{
    //ui
    ui->setupUi(this);
    Populate_CB();

    //Store
    pStore = pStorage;

    //Viewer
    Viewer_Proc.set_GV(ui->graphicsView_Proc);

    //Init
    Init();

    //CONNECTS
    connect(ui->action_Data_Add,            SIGNAL(triggered(bool)),        this,       SLOT(Images_Add()));
    connect(ui->pushButton_In_Add,          SIGNAL(clicked(bool)),          this,       SLOT(Images_Add()));
    connect(ui->action_Data_Clear,          SIGNAL(triggered(bool)),        this,       SLOT(Images_Clear()));
    connect(ui->pushButton_In_Clear,        SIGNAL(clicked(bool)),          this,       SLOT(Images_Clear()));
    connect(ui->action_Data_Next,           SIGNAL(triggered(bool)),        this,       SLOT(Images_Next()));
    connect(ui->action_Data_Previous,       SIGNAL(triggered(bool)),        this,       SLOT(Images_Previous()));

    //on start
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    setWindowTitle("ImageD - Segmentation Assistant");
    //this->showMaximized();
}

D_MAKRO_SegmentationAssistant::~D_MAKRO_SegmentationAssistant()
{
    delete ui;
}

void D_MAKRO_SegmentationAssistant::closeEvent(QCloseEvent *event)
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

void D_MAKRO_SegmentationAssistant::resizeEvent(QResizeEvent *event)
{
    event->accept();
    Update_Views();
}

void D_MAKRO_SegmentationAssistant::Init()
{
    vVD_Steps.clear();
    vVD_Steps.resize(c_ST_NUMBER_OF);

    D_Img_Proc::Load_From_Path(
                &MA_ShowProc,
                pStore->default_img()->absoluteFilePath());
}

void D_MAKRO_SegmentationAssistant::Populate_CB_Single(QComboBox *CB, QStringList QSL, int index_init)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(index_init);
    CB->blockSignals(false);
}

void D_MAKRO_SegmentationAssistant::Populate_CB()
{
    Populate_CB_Single(ui->comboBox_Step,           QSL_Steps,          c_ST_IN);
    Populate_CB_Single(ui->comboBox_Select_Mono,    QSL_Color2Mono,     c_COL2MONO_GRAY);
}

void D_MAKRO_SegmentationAssistant::Update_Views()
{
    Viewer_Proc.Update_View();
}

void D_MAKRO_SegmentationAssistant::Update_Images()
{
    int page = 0;
    if(ui->comboBox_Step->currentIndex() == c_ST_IN)
        page = ui->spinBox_In_PageDisplay->value();

    D_VisDat_Slice_2D slice = D_VisDat_Slice_2D(-1, -1, 0, 0, 0, page);

    D_VisDat_Proc::Read_2D_Plane(
                &MA_ShowProc,
                &(vVD_Steps[ui->comboBox_Step->currentIndex()]),
                slice);

    Viewer_Proc.Update_Image(&MA_ShowProc);
}

void D_MAKRO_SegmentationAssistant::Update_ProcSetps(int step_start)
{
    if(state_no_img)
        return;

    for(int s = step_start; s < c_ST_NUMBER_OF; s++)
        Update_ProcStep(s);
}

void D_MAKRO_SegmentationAssistant::Update_ProcStep(int step)
{
    if(state_no_img)
        return;

    switch (step) {

    case c_ST_IN:
    {
        state_cur_img_loaded = false;

        int ER = D_VisDat_Proc::Create_VD_SinglePaged(
                    &(vVD_Steps[c_ST_IN]),
                    FIL_Images[ui->comboBox_In_Images->currentIndex()]);

        ERR(ER,
            "Create_VD_SinglePaged",
            "c_ST_IN");

        if(ER != ER_okay)
            return;

        state_cur_img_loaded = true;
        state_img_proc_done = false;
    }
        break;

    case c_ST_SEL_PAGE:
    {
        if(vVD_Steps[c_ST_IN].pDim()->size_P() > 1)
        {
            vector<int> dim_pick = {-1, -1, -1, -1, -1, ui->spinBox_Select_Page->value()};

            ERR(D_VisDat_Proc::Dim_Pick(
                    &(vVD_Steps[c_ST_SEL_PAGE]),
                    &(vVD_Steps[c_ST_IN]),
                    dim_pick),
                "Dim_Pick",
                "c_ST_SEL_PAGE");
        }
        else
        {
            ERR(D_VisDat_Proc::Copy(
                    &(vVD_Steps[c_ST_SEL_PAGE]),
                    &(vVD_Steps[c_ST_IN])),
                "Copy",
                "c_ST_SEL_PAGE");
        }

        state_img_proc_done = false;
    }
        break;

    case c_ST_SEL_CHANNEL:
    {
        if(vVD_Steps[c_ST_IN].pMA_full()->channels() > 1)
        {
            ERR(D_VisDat_Proc::Convert_Color2Mono(
                    &(vVD_Steps[c_ST_SEL_CHANNEL]),
                    &(vVD_Steps[c_ST_SEL_PAGE]),
                    ui->comboBox_Select_Mono->currentIndex()),
                "Convert_Color2Mono",
                "c_ST_SEL_CHANNEL");
        }
        else
        {
            ERR(D_VisDat_Proc::Copy(
                    &(vVD_Steps[c_ST_SEL_CHANNEL]),
                    &(vVD_Steps[c_ST_SEL_PAGE])),
                "Copy",
                "c_ST_SEL_CHANNEL");
        }

        state_img_proc_done = false;
    }
        break;

    case c_ST_BLUR:
    {
        ERR(D_VisDat_Proc::Filter_Gauss(
                ProcSlicing,
                &(vVD_Steps[c_ST_BLUR]),
                &(vVD_Steps[c_ST_SEL_CHANNEL]),
                ui->spinBox_Blur_Size->value() / 2,
                ui->spinBox_Blur_Size->value() / 2,
                BORDER_DEFAULT,
                ui->doubleSpinBox_Blur_Sigma->value(),
                ui->doubleSpinBox_Blur_Sigma->value()),
            "Filter_Gauss",
            "c_ST_BLUR");

        state_img_proc_done = false;
    }
        break;

    case c_ST_THRES:
    {
        ERR(D_VisDat_Proc::Threshold_Absolute(
                &(vVD_Steps[c_ST_THRES]),
                &(vVD_Steps[c_ST_BLUR]),
                ui->doubleSpinBox_Binary_Thres->value()),
            "Threshold_Absolute",
            "c_ST_THRES");

        state_img_proc_done = false;
    }
        break;

    case c_ST_WATERSHED:
    {
        ERR(D_VisDat_Proc::Transformation_Watershed_Auto(
                ProcSlicing,
                &(vVD_Steps[c_ST_WATERSHED]),
                &(vVD_Steps[c_ST_THRES]),
                ui->spinBox_Seg_Size->value(),
                ui->doubleSpinBox_Seg_Sigma->value(),
                ui->checkBox_Seg_InclNonSeed->isChecked(),
                false,
                ui->checkBox_Seg_ExclBorder->isChecked()),
            "Transformation_Watershed_Auto",
            "c_ST_WATERSHED");

        state_img_proc_done = false;
    }
        break;

    case c_ST_TRAIN_RECOVER:
    {
        ERR(D_VisDat_Proc::Draw_Label_Numbers(
                ProcSlicing,
                &(vVD_Steps[c_ST_TRAIN_RECOVER]),
                &(vVD_Steps[c_ST_SEL_CHANNEL]),
                &(vVD_Steps[c_ST_WATERSHED]),
                1.0,
                2,
                true),
            "Draw_Label_Numbers",
            "c_ST_TRAIN_RECOVER");

        state_img_proc_done = false;
    }
        break;

    case c_ST_TRAIN_MERGE:
    {
        ERR(D_VisDat_Proc::Copy(
                &(vVD_Steps[c_ST_TRAIN_MERGE]),
                &(vVD_Steps[c_ST_TRAIN_RECOVER])),
            "Copy",
            "c_ST_TRAIN_MERGE");

        state_img_proc_done = false;
    }
        break;

    case c_ST_TRAIN_SEPARATE:
    {
        ERR(D_VisDat_Proc::Copy(
                &(vVD_Steps[c_ST_TRAIN_SEPARATE]),
                &(vVD_Steps[c_ST_TRAIN_MERGE])),
            "Copy",
            "c_ST_TRAIN_SEPARATE");

        state_img_proc_done = false;
    }
        break;

    case c_ST_TRAIN_KICK:
    {
        ERR(D_VisDat_Proc::Copy(
                &(vVD_Steps[c_ST_TRAIN_KICK]),
                &(vVD_Steps[c_ST_TRAIN_SEPARATE])),
            "Copy",
            "c_ST_TRAIN_KICK");

        state_img_proc_done = false;
    }
        break;

    case c_ST_OUT:
    {
        ERR(D_VisDat_Proc::Copy(
                &(vVD_Steps[c_ST_OUT]),
                &(vVD_Steps[c_ST_TRAIN_KICK])),
            "Copy",
            "c_ST_OUT");

        state_img_proc_done = true;
    }
        break;

    default:
        break;
    }

    Update_Images();
}

void D_MAKRO_SegmentationAssistant::Images_Add()
{
    //remember currently selected img
    int img_cur = 0;
    if(!state_no_img)
        img_cur = ui->comboBox_In_Images->currentIndex();

    //get paths of images to add
    QStringList QSL_InputImages2Add = QFileDialog::getOpenFileNames(
                this,
                "Add Images",
                pStore->dir_M_SegmentationAssistant()->path(),
                tr("Images (*.tif *.TIF *.tiff *.TIFF *.bmp *.png *.jpg)"));

    //files chosen?
    if(QSL_InputImages2Add.empty())
        return;

    //default path for next use
    pStore->set_dir_M_SegmentationAssistant(QSL_InputImages2Add.first());

    //File Infos & img names
    for(int f = 0; f < QSL_InputImages2Add.size(); f++)
    {
        QFileInfo FI_Img2Add = QFileInfo(QSL_InputImages2Add[f]);

        if(FI_Img2Add.exists())
        {
            FIL_Images.append(FI_Img2Add);
            QSL_Images_Paths.append(FI_Img2Add.absoluteFilePath());
            QSL_Images_Names.append(FI_Img2Add.baseName());
            state_no_img = false;
        }
    }

    //ui
    Populate_CB_Single(ui->comboBox_In_Images, QSL_Images_Names, img_cur);

    //Update
    Update_ProcSetps(0);
}

void D_MAKRO_SegmentationAssistant::Images_Clear()
{
    state_no_img = true;
    state_cur_img_loaded = false;
    state_img_proc_done = false;
    FIL_Images.clear();
    QSL_Images_Names.clear();
    QSL_Images_Paths.clear();
    ui->comboBox_In_Images->clear();
    Init();
    Update_Images();
}

void D_MAKRO_SegmentationAssistant::Images_Next()
{
    if(state_no_img)
        return;

    int i = ui->comboBox_In_Images->currentIndex();
    if(i < FIL_Images.size() - 1)
        ui->comboBox_In_Images->setCurrentIndex(i + 1);
    else
        QMessageBox::information(
                    this,
                    "End of Stack",
                    "You have reached the end of the stack :-)");
}

void D_MAKRO_SegmentationAssistant::Images_Previous()
{
    if(state_no_img)
        return;

    int i = ui->comboBox_In_Images->currentIndex();
    if(i > 0)
        ui->comboBox_In_Images->setCurrentIndex(i - 1);
}

void D_MAKRO_SegmentationAssistant::ERR(int err, QString func, QString detail)
{
    ER.ERR(
                err,
                "D_MAKRO_SegmentationAssistant",
                func,
                detail);
}

void D_MAKRO_SegmentationAssistant::on_comboBox_In_Images_currentIndexChanged(int index)
{
    index;
    Update_ProcSetps(c_ST_IN);
}

void D_MAKRO_SegmentationAssistant::on_spinBox_In_PageDisplay_valueChanged(int arg1)
{
    arg1;
    Update_Images();
}

void D_MAKRO_SegmentationAssistant::on_spinBox_Select_Page_valueChanged(int arg1)
{
    arg1;
    Update_ProcSetps(c_ST_SEL_PAGE);
}

void D_MAKRO_SegmentationAssistant::on_comboBox_Select_Mono_currentIndexChanged(int index)
{
    index;
    Update_ProcSetps(c_ST_SEL_CHANNEL);
}

void D_MAKRO_SegmentationAssistant::on_doubleSpinBox_Blur_Sigma_valueChanged(double arg1)
{
    arg1;
    Update_ProcSetps(c_ST_BLUR);
}

void D_MAKRO_SegmentationAssistant::on_spinBox_Blur_Size_valueChanged(int arg1)
{
    arg1;
    Update_ProcSetps(c_ST_BLUR);
}

void D_MAKRO_SegmentationAssistant::on_doubleSpinBox_Seg_Sigma_valueChanged(double arg1)
{
    arg1;
    Update_ProcSetps(c_ST_WATERSHED);
}

void D_MAKRO_SegmentationAssistant::on_spinBox_Seg_Size_valueChanged(int arg1)
{
    arg1;
    Update_ProcSetps(c_ST_WATERSHED);
}

void D_MAKRO_SegmentationAssistant::on_comboBox_Step_currentIndexChanged(int index)
{
    index;
    Update_Images();
}

void D_MAKRO_SegmentationAssistant::on_checkBox_Seg_InclNonSeed_stateChanged(int arg1)
{
    arg1;
    Update_ProcSetps(c_ST_WATERSHED);
}

void D_MAKRO_SegmentationAssistant::on_checkBox_Seg_ExclBorder_stateChanged(int arg1)
{
    arg1;
    Update_ProcSetps(c_ST_WATERSHED);
}

void D_MAKRO_SegmentationAssistant::on_doubleSpinBox_Binary_Thres_valueChanged(double arg1)
{
    arg1;
    Update_ProcSetps(c_ST_THRES);
}
