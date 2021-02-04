/****************************************************
 *   added:     10.12.2020                          *
 *   author:    David Eilenstein                    *
 *   contact:   David.Eilenstein@stud.h-da.de.de    *
 *   project:   ImageD                              *
 *   facility:  Hochschule Darmstadt, Ger           *
 ****************************************************/


#include "d_makro_huangvisualization.h"
#include "ui_d_makro_huangvisualization.h"

D_MAKRO_HuangVisualization::D_MAKRO_HuangVisualization(D_Storage *pStorage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::D_MAKRO_HuangVisualization)
{
    ui->setupUi(this);

    //storage
    pStore = pStorage;

    //Viewer
    Viewer_In.set_GV(ui->graphicsView_In);
    Viewer_Out.set_GV(ui->graphicsView_Out);
    Viewer_Mask_Binary.set_GV(ui->graphicsView_Mask_BinaryAndPos);
    Viewer_Mask_InColor.set_GV(ui->graphicsView_Mask_ZoomInput_Color);
    Viewer_Mask_InGray.set_GV(ui->graphicsView_Mask_ZoomInput_Gray);
    Viewer_Mask_Out.set_GV(ui->graphicsView_Mask_ZoomOutput);
    Viewer_Hist.set_GV(ui->graphicsView_Hist);
    Viewer_Hist_Legend.set_GV(ui->graphicsView_HistLegend);
    Viewer_Mass.set_GV(ui->graphicsView_Mass);
    Viewer_In.Set_Transformation_Mode(false);
    Viewer_Out.Set_Transformation_Mode(false);
    Viewer_Mask_Binary.Set_Transformation_Mode(false);
    Viewer_Mask_InColor.Set_Transformation_Mode(false);
    Viewer_Mask_InGray.Set_Transformation_Mode(false);
    Viewer_Mask_Out.Set_Transformation_Mode(false);
    Viewer_In.connect_Zoom(&Viewer_Out);
    Viewer_Hist.Set_Transformation_Mode(false);
    Viewer_Hist.Set_Aspect_Mode(false);
    Viewer_Hist_Legend.Set_Transformation_Mode(false);
    Viewer_Hist_Legend.Set_Aspect_Mode(false);
    Viewer_Mass.Set_Transformation_Mode(false);
    Viewer_Mass.Set_Aspect_Mode(false);

    //Plot

    //status
    pLabelStatus = new QLabel(this);
    pLabelStatus->setText("Status");
    ui->statusbar->addPermanentWidget(pLabelStatus);

    //connect
    connect(ui->actionLoad_Image,           SIGNAL(triggered(bool)),        this,       SLOT(Load_Image()));
    connect(ui->actionSet_Mask,             SIGNAL(triggered(bool)),        this,       SLOT(Get_Mask()));
    connect(ui->actionChoose_new_quantile,  SIGNAL(triggered(bool)),        this,       SLOT(Get_Quantil()));
    connect(ui->actionStep_Detail,          SIGNAL(triggered(bool)),        this,       SLOT(Proc_StepDetail()));
    connect(ui->actionStep_Value,           SIGNAL(triggered(bool)),        this,       SLOT(Proc_StepValue()));
    connect(ui->actionStep_Pixel,           SIGNAL(triggered(bool)),        this,       SLOT(Proc_StepPixel()));
    connect(ui->actionStep_Line,            SIGNAL(triggered(bool)),        this,       SLOT(Proc_StepLine()));
    connect(ui->actionProc_All,             SIGNAL(triggered(bool)),        this,       SLOT(Proc_Full()));

    //show
    this->showMaximized();
    setWindowIcon(QIcon(":/logo/ImageD_Logo.png"));
    setWindowTitle("ImageD - Huang rank order filtering visualization");

    //init images and params
    Load_Image();
    Get_Mask();
    Get_Quantil();
}

D_MAKRO_HuangVisualization::~D_MAKRO_HuangVisualization()
{
    delete ui;
}

void D_MAKRO_HuangVisualization::closeEvent(QCloseEvent *event)
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

void D_MAKRO_HuangVisualization::resizeEvent(QResizeEvent *event)
{
    event->accept();
    //Update_Views();
}

void D_MAKRO_HuangVisualization::Update_Ui()
{
    ui->actionLoad_Image->setEnabled(false);
    ui->actionSet_Mask->setEnabled(false);
    ui->actionChoose_new_quantile->setEnabled(false);
    ui->actionStep_Detail->setEnabled(false);
    ui->actionStep_Value->setEnabled(false);
    ui->actionStep_Pixel->setEnabled(false);
    ui->actionStep_Line->setEnabled(false);
    ui->actionProc_All->setEnabled(false);

    this->repaint();
    qApp->processEvents();

    ui->actionLoad_Image->setEnabled(true);
    ui->actionSet_Mask->setEnabled(true);
    ui->actionChoose_new_quantile->setEnabled(true);
    ui->actionStep_Detail->setEnabled(true);
    ui->actionStep_Value->setEnabled(true);
    ui->actionStep_Pixel->setEnabled(true);
    ui->actionStep_Line->setEnabled(true);
    ui->actionProc_All->setEnabled(true);
}

void D_MAKRO_HuangVisualization::Update_Image_Out()
{
    if(!state_img_out_init)
        return;

    //show
    Viewer_Out.Update_Image(&MA_ImgOut_Gray);
    Viewer_Mask_Out.Update_Image(&MA_MaskShow_Out);
}

void D_MAKRO_HuangVisualization::Update_Image_In()
{
    if(!state_img_padded || !state_img_loaded || !state_mask_loaded)
        return;

    //reset image
    MA_ImgIn_Show = MA_ImgIn_GrayPadded3Ch.clone();

    //mask in image in
    if(step_next == STEP_INIT_POSITION || step_next == STEP_POINT_CHANGE_ADD_REM || step_next == STEP_PIXEL_CHANGE_POS)
    {
        //mask (green)
        for(int y = 0; y < mask_sy; y++)
            for(int x = 0; x < mask_sx; x++)
                if(MA_MaskBinary.at<uchar>(y, x) > 0)
                {
                    Vec3b val_3ch = MA_ImgIn_Show.at<Vec3b>(pos_y + y, pos_x + x);
                    val_3ch[0] = 0;                     //b
                    val_3ch[1] = 50 + val_3ch[1] * 0.67;//g
                    val_3ch[2] = 0;                     //r
                    MA_ImgIn_Show.at<Vec3b>(pos_y + y, pos_x + x) = val_3ch;
                }

        //center
        MA_ImgIn_Show.at<Vec3b>(pos_y + mask_cy, pos_x + mask_cx) = Vec3b(0, 255, 0);
    }

    //highlight add (blue) and remove (red)
    if(step_next == STEP_POINT_CHANGE_ADD_REM)
    {
        //add
        MA_ImgIn_Show.at<Vec3b>(pos_y + mask_cy + (*vBorderAdd)[i_add_rem].y, pos_x + mask_cx + (*vBorderAdd)[i_add_rem].x) = Vec3b(255, 0, 0);

        //rem
        MA_ImgIn_Show.at<Vec3b>(pos_y + mask_cy + (*vBorderRem)[i_add_rem].y + dy_to_prev_pos, pos_x + mask_cx + (*vBorderRem)[i_add_rem].x + dx_to_prev_pos) = Vec3b(0, 0, 255);
    }

    //copy in data under mask to zoomed view (gray)
    for(int y = 0; y < MA_MaskShow_In_Gray.rows; y++)
        for(int x = 0; x < MA_MaskShow_In_Gray.cols; x++)
            if(MA_MaskBinary.at<uchar>(y, x) > 0)
                MA_MaskShow_In_Gray.at<uchar>(y, x) = MA_ImgIn_GrayPadded.at<uchar>(y + pos_y, x + pos_x);

    //copy in data under mask to zoomed view (color)
    for(int y = 0; y < MA_MaskShow_In_Color.rows; y++)
        for(int x = 0; x < MA_MaskShow_In_Color.cols; x++)
            MA_MaskShow_In_Color.at<Vec3b>(y, x) = MA_ImgIn_Show.at<Vec3b>(y + pos_y, x + pos_x);

    //show
    Viewer_In.Update_Image(&MA_ImgIn_Show);
    Viewer_Mask_InColor.Update_Image(&MA_MaskShow_In_Color);
    Viewer_Mask_InGray.Update_Image(&MA_MaskShow_In_Gray);
}

void D_MAKRO_HuangVisualization::Update_Image_Mask()
{
    if(!state_mask_loaded)
        return;

    //reset binary
    MA_MaskShow_Binary = MA_MaskBinary_3C.clone();

    //highlight add/remove list
    if(step_next == STEP_INIT_POINT_LISTS || step_next == STEP_PIXEL_CHANGE_POINT_LISTS || step_next == STEP_POINT_CHANGE_ADD_REM)// || step_next == STEP_INIT_POINT_LISTS)
    {
        //central pixel
        //MA_MaskShow_Binary.at<Vec3b>(mask_cy, mask_cx) = Vec3b(0, 255, 0);

        //add
        for(size_t i = 0; i < vBorderAdd->size(); i++)
            MA_MaskShow_Binary.at<Vec3b>((*vBorderAdd)[i].y + mask_cy, (*vBorderAdd)[i].x + mask_cx) = Vec3b(128, 0, 0);

        //remove
        for(size_t i = 0; i < vBorderRem->size(); i++)
        {
            Vec3b px_val = MA_MaskShow_Binary.at<Vec3b>((*vBorderRem)[i].y + mask_cy, (*vBorderRem)[i].x + mask_cx);

            if(px_val == Vec3b(128, 0, 0))
                MA_MaskShow_Binary.at<Vec3b>((*vBorderRem)[i].y + mask_cy, (*vBorderRem)[i].x + mask_cx) = Vec3b(128, 0, 128);
            else
                MA_MaskShow_Binary.at<Vec3b>((*vBorderRem)[i].y + mask_cy, (*vBorderRem)[i].x + mask_cx) = Vec3b(0, 0, 128);
        }
    }

    //highlight add/remove value
    if(step_next == STEP_POINT_CHANGE_ADD_REM)
    {
        //val
        Vec3b px_val;

        //add
        px_val = MA_MaskShow_Binary.at<Vec3b>((*vBorderAdd)[i_add_rem].y + mask_cy, (*vBorderAdd)[i_add_rem].x + mask_cx);
        if(px_val == Vec3b(128, 0, 0))
            MA_MaskShow_Binary.at<Vec3b>((*vBorderAdd)[i_add_rem].y + mask_cy, (*vBorderAdd)[i_add_rem].x + mask_cx) = Vec3b(255, 0, 0);
        else if(px_val == Vec3b(128, 0, 128))
            MA_MaskShow_Binary.at<Vec3b>((*vBorderAdd)[i_add_rem].y + mask_cy, (*vBorderAdd)[i_add_rem].x + mask_cx) = Vec3b(255, 0, 128);

        //remove
        px_val = MA_MaskShow_Binary.at<Vec3b>((*vBorderRem)[i_add_rem].y + mask_cy, (*vBorderRem)[i_add_rem].x + mask_cx);
        if(px_val == Vec3b(0, 0, 128))
            MA_MaskShow_Binary.at<Vec3b>((*vBorderRem)[i_add_rem].y + mask_cy, (*vBorderRem)[i_add_rem].x + mask_cx) = Vec3b(0, 0, 255);
        else if(px_val == Vec3b(128, 0, 128))
            MA_MaskShow_Binary.at<Vec3b>((*vBorderRem)[i_add_rem].y + mask_cy, (*vBorderRem)[i_add_rem].x + mask_cx) = Vec3b(128, 0, 255);
        else if(px_val == Vec3b(255, 0, 128))
            MA_MaskShow_Binary.at<Vec3b>((*vBorderRem)[i_add_rem].y + mask_cy, (*vBorderRem)[i_add_rem].x + mask_cx) = Vec3b(255, 0, 255);
    }

    //show
    Viewer_Mask_Binary.Update_Image(&MA_MaskShow_Binary);
}

void D_MAKRO_HuangVisualization::Update_Plot_Hist()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //init
    MA_Hist = Mat::zeros(mask_relevant_px_count, 256, CV_8UC3);

    //quantil value
    size_t q = static_cast<size_t>(quantil_val);

    //smaller
    for(size_t i = 0; i < q; i++)
        for(size_t j = 0; j < hist[i]; j++)
            MA_Hist.at<Vec3b>(mask_relevant_px_count - 1 - j, i) = Vec3b(255, 0, 255);

    //quantil
    for(size_t j = 0; j < hist[q]; j++)
        MA_Hist.at<Vec3b>(mask_relevant_px_count - 1 - j, q) = Vec3b(0, 255, 255);

    //greater
    if(q + 1 < 256)
        for(size_t i = q + 1; i < 256; i++)
            for(size_t j = 0; j < hist[i]; j++)
                MA_Hist.at<Vec3b>(mask_relevant_px_count - 1 - j, i) = Vec3b(255, 255, 0);

    //show
    Viewer_Hist.Update_Image(&MA_Hist);
}

void D_MAKRO_HuangVisualization::Update_Plot_Mass()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //init
    size_t sx = 4 * mask_relevant_px_count; //x2 to match thresh resolution, x2 to be safe for mass addition
    size_t sy = 8;
    MA_Mass = Mat::zeros(sy, sx, CV_8UC3);

    //thresh: smaller or quantil
    for(size_t y = 0; y < 4; y++)
        for(size_t x = 0; x < 2 * mass_smaller_or_equal_needed; x++)
            MA_Mass.at<Vec3b>(y, x) = Vec3b(64, 0, 64);

    //thresh: greater or quantil
    for(size_t y = 4; y < 8; y++)
        for(size_t x = 0; x < 2 * mass_greater_or_equal_needed; x++)
            MA_Mass.at<Vec3b>(y, x) = Vec3b(64, 64, 0);

    //mass: smaller
    for(size_t y = 1; y < 3; y++)
        for(size_t x = 0; x < 2 * mass_smaller; x++)
            MA_Mass.at<Vec3b>(y, x) = Vec3b(255, 0, 255);

    //mass: quantil (append to smaller)
    for(size_t y = 1; y < 3; y++)
        for(size_t x = 2 * mass_smaller; x < 2 * (mass_smaller + mass_quantil); x++)
            MA_Mass.at<Vec3b>(y, x) = Vec3b(0, 255, 255);

    //mass: greater
    for(size_t y = 5; y < 7; y++)
        for(size_t x = 0; x < 2 * mass_greater; x++)
            MA_Mass.at<Vec3b>(y, x) = Vec3b(255, 255, 0);

    //mass: quantil (append to greater)
    for(size_t y = 5; y < 7; y++)
        for(size_t x = 2 * mass_greater; x < 2 * (mass_greater + mass_quantil); x++)
            MA_Mass.at<Vec3b>(y, x) = Vec3b(0, 255, 255);

    //show
    Viewer_Mass.Update_Image(&MA_Mass);
}

void D_MAKRO_HuangVisualization::Load_Image()
{
    QString QS_path_load = QFileDialog::getOpenFileName(
                this,
                "Load Image",
                pStore->dir_M_Huang()->path(),
                "Video Files (*.png *.jpg *.asc *.tif *tiff *.bmp)");

    if(QS_path_load.isEmpty())
        return;

    QFileInfo FI_Load(QS_path_load);
    if(!FI_Load.exists())
        return;

    //set default dir
    pStore->set_dir_M_Huang(FI_Load.path());

    state_img_loaded = false;
    state_img_out_init = false;
    state_img_padded = false;

    //reset proc chain
    step_next = STEP_INIT_POSITION;

    //load
    if(D_Img_Proc::Load_From_Path_Gray(
                &MA_ImgIn_Load,
                FI_Load)
            != ER_okay)
        return;

    //force 1 channel
    if(D_Img_Proc::Convert_8UC1(
               &MA_ImgIn_Gray,
               &MA_ImgIn_Load)
           != ER_okay)
       return;

    //state
    state_img_loaded = true;

    //show non padded image
    Viewer_In.Update_Image(&MA_ImgIn_Gray);
    Update_Ui();

    //get params (img size)
    img_in_sy = MA_ImgIn_Gray.rows;
    img_in_sx = MA_ImgIn_Gray.cols;

    //status
    pLabelStatus->setText("Image loaded");

    Pad_Image();
}

void D_MAKRO_HuangVisualization::Get_Mask()
{
    state_mask_loaded = false;
    state_img_padded = false;

    //reset proc chain
    step_next = STEP_INIT_POSITION;

    if(QMessageBox::question(
                this,
                "Mask selection",
                "Do you want to generate a mask instead of loading one?")
            == QMessageBox::Yes)
        Generate_Mask();
    else
        Load_Mask();

    if(!state_mask_loaded)
        return;

    if(D_Img_Proc::Convert_Color(
                &MA_MaskBinary_3C,
                &MA_MaskBinary,
                CV_GRAY2BGR)
            != ER_okay)
        return;

    //mask parameters
    //sizes
    mask_sx = MA_MaskBinary.cols;
    mask_sy = MA_MaskBinary.rows;
    //centers
    mask_cx = mask_sx / 2;
    mask_cy = mask_sy / 2;
    //center to border
    mask_c2l = 0 - mask_cx;
    mask_c2r = mask_sx - mask_cx - 1;
    mask_c2t = 0 - mask_cy;
    mask_c2b = mask_sy - mask_cy - 1;
    //area non zero
    mask_relevant_px_count = countNonZero(MA_MaskBinary);

    //init and show
    MA_MaskShow_Binary = MA_MaskBinary_3C.clone();
    MA_MaskShow_In_Color = MA_MaskBinary_3C.clone();
    MA_MaskShow_In_Gray = MA_MaskBinary.clone();
    MA_MaskShow_Out = Mat::zeros(MA_MaskBinary.size(), CV_8UC1);
    Update_Image_Mask();

    //status
    pLabelStatus->setText("Mask set");

    Pad_Image();
}

void D_MAKRO_HuangVisualization::Load_Mask()
{
    QString QS_path_load = QFileDialog::getOpenFileName(
                this,
                "Load Mask",
                pStore->dir_M_Huang()->path(),
                "Video Files (*.png *.jpg *.asc *.tif *tiff *.bmp)");

    if(QS_path_load.isEmpty())
        return;

    QFileInfo FI_Load(QS_path_load);
    if(!FI_Load.exists())
        return;

    //set default dir
    pStore->set_dir_M_Huang(FI_Load.path());

    state_mask_loaded = false;
    int ER = D_Img_Proc::Load_From_Path_Gray(
                &MA_MaskLoad,
                FI_Load);
   if(ER != ER_okay)
        return;

   //thresh
   Mat MA_tmp;
   ER = D_Img_Proc::Threshold_Relative_1C(
               &MA_tmp,
               &MA_MaskLoad,
               255,
               0.5);
   if(ER != ER_okay)
       return;

   //pading (just for visualization purposes
   if(D_Img_Proc::Padding(
               &MA_MaskBinary,
               &MA_tmp,
               1,
               1,
               1,
               1,
               BORDER_CONSTANT)
           != ER_okay)
   {
       MA_tmp.release();
       return;
   }

   MA_tmp.release();
   state_mask_loaded = true;
}


void D_MAKRO_HuangVisualization::Generate_Mask()
{
    if(QMessageBox::question(
                this,
                "Mask generation",
                "Do you want to genrate a circular mask?\n(yes=circle, no=square)")
            == QMessageBox::Yes)
    {
        bool ok;
        double radius = QInputDialog::getDouble(
                    this,
                    "Get Radius",
                    "Please enter radius of circular mask",
                    2,
                    0.5,
                    999,
                    1,
                    &ok);
        if(!ok)
            return;

        //mask img size must be an odd int
        int mask_img_size = 2 * static_cast<int>(radius) + 1;

        state_mask_loaded = false;

        //generate circle (+2 / +1 to pad with 1 layer of 0)
        D_Img_Proc::Generate_byValueFunction(
                    &MA_MaskLoad,
                    mask_img_size + 2,
                    mask_img_size + 2,
                    D_Math::Function_2D_to_1D(
                        c_MATH_2D_TO_1D_ELLIPSE,
                        radius,
                        mask_img_size / 2 + 1,
                        radius,
                        mask_img_size / 2 + 1,
                        255,
                        0,
                        0,
                        0));

        //binarize
        int ER = D_Img_Proc::Threshold_Relative_1C(
                    &MA_MaskBinary,
                    &MA_MaskLoad,
                    255,
                    0.5);
        if(ER != ER_okay)
            return;
    }
    else
    {
        bool ok;
        int size = QInputDialog::getInt(
                    this,
                    "Get size",
                    "Please enter s of circular mask",
                    3,
                    1,
                    999,
                    2,
                    &ok);
        if(!ok)
            return;

        //square
        Mat MA_tmp_rect(size, size, CV_8UC1, Scalar(255));

        //pading (just for visualization purposes
        if(D_Img_Proc::Padding(
                    &MA_MaskLoad,
                    &MA_tmp_rect,
                    1,
                    1,
                    1,
                    1,
                    BORDER_CONSTANT)
                != ER_okay)
        {
            MA_tmp_rect.release();
            return;
        }
        MA_tmp_rect.release();

        MA_MaskBinary = MA_MaskLoad.clone();
    }

    state_mask_loaded = true;
}

void D_MAKRO_HuangVisualization::Get_Quantil()
{
    //reset proc chain
    step_next = STEP_INIT_POSITION;

    quantil_relPos = QInputDialog::getDouble(
                this,
                "Quantil selection",
                "Plese choose a quantile value from 0 to 1",
                0.5,
                0,
                1,
                2,
                &state_quantil_rel_set);

    if(!state_quantil_rel_set)
        return;

    //status
    pLabelStatus->setText("Quantil set: " + QString::number(quantil_relPos));
    if(quantil_relPos == 0.0)
        ui->label_quantil_description->setText("Minimum:");
    else if(quantil_relPos == 0.25)
        ui->label_quantil_description->setText("Lower quartil:");
    else if(quantil_relPos == 0.5)
        ui->label_quantil_description->setText("Median:");
    else if(quantil_relPos == 0.75)
        ui->label_quantil_description->setText("Upper quartil:");
    else if(quantil_relPos == 1.0)
        ui->label_quantil_description->setText("Maximum:");
    else
        ui->label_quantil_description->setText(QString::number(quantil_relPos * 100.0) + "%-Quantil:");

    //ready to go?
    if(state_img_loaded || state_img_padded || state_mask_loaded || state_img_out_init || state_quantil_rel_set)
    {
        pLabelStatus->setText("NEXT: Init Position");
        step_next = STEP_INIT_POSITION;
    }
}

void D_MAKRO_HuangVisualization::Pad_Image()
{    state_img_padded = false;
    if(!state_img_loaded || !state_mask_loaded)
        return;

    //reset proc chain
    step_next = STEP_INIT_POSITION;

    //init output
    Init_ImgOut();

    //pad
    if(D_Img_Proc::Padding(
                &MA_ImgIn_GrayPadded,
                &MA_ImgIn_Gray,
                abs(mask_c2r),
                abs(mask_c2l),
                abs(mask_c2t),
                abs(mask_c2b),
                BORDER_REPLICATE)
            != ER_okay)
        return;

    //pseudo 3 channel image
    if(D_Img_Proc::Convert_Color(
               &MA_ImgIn_GrayPadded3Ch,
               &MA_ImgIn_GrayPadded,
               CV_GRAY2BGR)
           != ER_okay)
       return;

    //image to show
    MA_ImgIn_Show = MA_ImgIn_GrayPadded3Ch.clone();

    //status
    pLabelStatus->setText("Image in padded");

    state_img_padded = true;

    //show
    Viewer_In.Update_Image(&MA_ImgIn_Show);

    //ready to go?
    if(state_img_loaded || state_img_padded || state_mask_loaded || state_img_out_init || state_quantil_rel_set)
    {
        pLabelStatus->setText("NEXT: Init Position");
        step_next = STEP_INIT_POSITION;
    }
}

void D_MAKRO_HuangVisualization::Init_ImgOut()
{
    state_img_out_init = false;
    if(!state_img_loaded)
        return;

    //reset proc chain
    step_next = STEP_INIT_POSITION;

    //init out
    MA_ImgOut_Gray = Mat::zeros(
                img_in_sy + abs(mask_c2b) + abs(mask_c2t),
                img_in_sx + abs(mask_c2r) + abs(mask_c2l),
                CV_8UC1);
    state_img_out_init = true;

    //show
    Update_Image_Out();

    //status
    pLabelStatus->setText("Image out init");
}

void D_MAKRO_HuangVisualization::Proc_StepDetail()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    switch (step_next) {

    case STEP_INIT_POSITION:                                Init_Position();                                        break;
    case STEP_INIT_QUANTILE:                                Init_Quantile();                                        break;
    case STEP_INIT_HIST:                                    Init_Hist();                                            break;
    case STEP_INIT_MASSES:                                  Init_Masses();                                          break;
    case STEP_INIT_POINT_LISTS:                             Init_PointLists();                                      break;

    case STEP_SAVE_LINE_BEGIN:                              Step_SaveLineBegin();                                   break;
    case STEP_LOAD_LINE_BEGIN:                              Step_LoadLineBegin();                                   break;

    case STEP_PIXEL_CHANGE_POS:                             Step_Pixel_ChangePos();                                 break;
    case STEP_PIXEL_CHANGE_POINT_LISTS:                     Step_Pixel_ChangePointLists();                          break;

    case STEP_POINT_CHANGE_ADD_REM:                         Step_Point_ChangeAddRem();                              break;
    case STEP_POINT_CHANGE_HIST:                            Step_Point_Change_Hist();                               break;
    case STEP_POINT_CHANGE_MASSES_ADD:                      Step_Point_Change_Masses_Add();                         break;
    case STEP_POINT_CHANGE_MASSES_REM:                      Step_Point_Change_Masses_Rem();                         break;
    case STEP_POINT_CHECK_MASSES:                           Step_Point_Check_Masses();                              break;

    case STEP_POINT_QUANTIL_DECREASE_CHANGE_MASS_GREATER:   Step_Point_Quantil_Decrease_Change_Mass_Greater();      break;
    case STEP_POINT_QUANTIL_DECREASE_CHANGE_QUANTIL:        Step_Point_Quantil_Decrease_Change_Quantil();           break;
    case STEP_POINT_QUANTIL_DECREASE_CHANGE_MASS_QUANTIL:   Step_Point_Quantil_Decrease_Change_Mass_Quantil();      break;
    case STEP_POINT_QUANTIL_DECREASE_CHANGE_MASS_SMALLER:   Step_Point_Quantil_Decrease_Change_Mass_Smaller();      break;

    case STEP_POINT_QUANTIL_INCREASE_CHANGE_MASS_SMALLER:   Step_Point_Quantil_Increase_Change_Mass_Smaller();      break;
    case STEP_POINT_QUANTIL_INCREASE_CHANGE_QUANTIL:        Step_Point_Quantil_Increase_Change_Quantil();           break;
    case STEP_POINT_QUANTIL_INCREASE_CHANGE_MASS_QUANTILE:  Step_Point_Quantil_Increase_Change_Mass_Quantil();      break;
    case STEP_POINT_QUANTIL_INCREASE_CHANGE_MASS_GREATER:   Step_Point_Quantil_Increase_Change_Mass_Greater();      break;

    case STEP_POINT_END:                                    Step_Point_End();                                       break;

    case STEP_PIXEL_WRITE_OUT:                              Step_Pixel_WriteOut();                                  break;
    case STEP_PIXEL_CHANGE_DIRECTION:                       Step_Pixel_Change_Direction();                          break;

    default:                                                                                                        break;}

    //show what happened
    Update_Ui();
}

void D_MAKRO_HuangVisualization::Proc_StepValue()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    do Proc_StepDetail();
    while(step_next != STEP_POINT_END && !ui->actionProcStop->isChecked());
    ui->actionProcStop->setChecked(false);
}

void D_MAKRO_HuangVisualization::Proc_StepPixel()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    do Proc_StepDetail();
    while(step_next != STEP_PIXEL_CHANGE_POS && !ui->actionProcStop->isChecked());
    ui->actionProcStop->setChecked(false);
}

void D_MAKRO_HuangVisualization::Proc_StepLine()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    do Proc_StepDetail();
    while(step_next != STEP_LOAD_LINE_BEGIN && !ui->actionProcStop->isChecked());
    ui->actionProcStop->setChecked(false);
}

void D_MAKRO_HuangVisualization::Proc_Full()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    do Proc_StepDetail();
    while(step_next != STEP_END && !ui->actionProcStop->isChecked());
    ui->actionProcStop->setChecked(false);
}




void D_MAKRO_HuangVisualization::Init_Position()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //init pos and direction
    at_end = false;
    pos_x = 0;
    pos_y = 0;
    direction = c_DIR2D_R;

    //show
    ui->label_x->setText(QString::number(pos_x));
    ui->label_y->setText(QString::number(pos_y));
    ui->label_direction->setText("right");
    Update_Image_In();

    //next step is:
    pLabelStatus->setText("NEXT: Init - Quantil at start position");
    step_next = STEP_INIT_QUANTILE;
}

void D_MAKRO_HuangVisualization::Init_Quantile()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //list of mask congruent pixel values at start position
    vector<uchar> values_init;

    //get the values of inital value list
    for(int y = 0; y < mask_sy; y++)
        for(int x = 0; x < mask_sx; x++)
            if(MA_MaskBinary.at<uchar>(y, x) > 0)
                values_init.push_back(MA_ImgIn_GrayPadded.at<uchar>(y, x));

    //init quantil value
    sort(values_init.begin(), values_init.end());
    quantil_val = values_init[(values_init.size() - 1) * quantil_relPos];

    //write to image
    MA_ImgOut_Gray.at<uchar>(0 + mask_cy, 0 + mask_cx) = static_cast<uchar>(quantil_val);

    //copy out data under mask to zoomed view
    for(int y = 0; y < MA_MaskShow_Out.rows; y++)
        for(int x = 0; x < MA_MaskShow_Out.cols; x++)
            MA_MaskShow_Out.at<uchar>(y, x) = MA_ImgOut_Gray.at<uchar>(y + pos_y, x + pos_x);

    //show
    Viewer_Out.Update_Image(&MA_ImgOut_Gray);
    Viewer_Mask_Out.Update_Image(&MA_MaskShow_Out);


    //show
    ui->label_quantil->setText(QString::number(quantil_val));

    //next step is:
    pLabelStatus->setText("NEXT: Init - Histogram at start position");
    step_next = STEP_INIT_HIST;
}

void D_MAKRO_HuangVisualization::Init_Hist()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //init hist legend
    Init_HistLegend();

    //create histogram
    hist.clear();
    hist.resize(256, 0);

    //init hist
    for(int y = 0; y < mask_sy; y++)
        for(int x = 0; x < mask_sx; x++)
            if(MA_MaskBinary.at<uchar>(y, x) > 0)
                hist[MA_ImgIn_GrayPadded.at<uchar>(y, x)]++;

    //init hist plot
    Update_Plot_Hist();

    //next step is:
    pLabelStatus->setText("NEXT: Init - Masses at start position");
    step_next = STEP_INIT_MASSES;
}

void D_MAKRO_HuangVisualization::Init_Masses()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //count of values smaller than quantil value
    mass_smaller = 0;
    for(size_t i = 0; i < static_cast<size_t>(quantil_val); i++)
        mass_smaller += hist[i];

    //count of values equal to quantil value
    mass_quantil = hist[static_cast<size_t>(quantil_val)];

    //count of values greater than quantil value
    mass_greater = 0;
    for(size_t i = static_cast<size_t>(quantil_val) + 1; i < hist.size(); i++)
        mass_greater += hist[i];

    //comparison value of needed absolute count for quantil determination
    mass_smaller_or_equal_needed = quantil_relPos * static_cast<double>(mask_relevant_px_count);
    mass_greater_or_equal_needed = (1.0 - quantil_relPos) * static_cast<double>(mask_relevant_px_count);

    //quantil == min
    if(quantil_relPos == 0)
    {
        mass_smaller_or_equal_needed = 0.5;
        mass_greater_or_equal_needed = mask_relevant_px_count - 0.5;
    }
    //quantil == max
    if(quantil_relPos == 1)
    {
        mass_smaller_or_equal_needed = mask_relevant_px_count - 0.5;
        mass_greater_or_equal_needed = 0.5;
    }

    //show
    ui->label_mass_smaller->setText(QString::number(mass_smaller));
    ui->label_mass_quantil->setText(QString::number(mass_quantil));
    ui->label_mass_greater->setText(QString::number(mass_greater));

    //show
    Update_Plot_Mass();

    //next step is:
    pLabelStatus->setText("NEXT: Init - Point lists needed for mask looping");
    step_next = STEP_INIT_POINT_LISTS;
}

void D_MAKRO_HuangVisualization::Init_PointLists()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //clear
    vBorderL.clear();
    vBorderR.clear();
    vBorderT.clear();
    vBorderB.clear();

    //init shift inidices
    for(int y = 0; y < mask_sy; y++)
        for(int x = 0; x < mask_sx; x++)
        {
            //current point (relative corrdinates) & value
            Point P_rel = Point(x - mask_cx, y - mask_cy);
            uchar Val_Mask = MA_MaskBinary.at<uchar>(y, x);

            //if position is at border of possible relevant mask
            //covered area or next to a mask background pixel in
            //relation to current "moving direction",
            //it is added to list of relative border corrdinates

            //check left border
            if(x == 0)
            {
                if(Val_Mask > 0)
                    vBorderL.push_back(P_rel);
            }
            else
            {
                if(Val_Mask > MA_MaskBinary.at<uchar>(y, x-1))
                    vBorderL.push_back(P_rel);
            }

            //check right border
            if(x == mask_sx - 1)
            {
                if(Val_Mask > 0)
                    vBorderR.push_back(P_rel);
            }
            else
            {
                if(Val_Mask > MA_MaskBinary.at<uchar>(y, x+1))
                    vBorderR.push_back(P_rel);
            }

            //check top border
            if(y == 0)
            {
                if(Val_Mask > 0)
                    vBorderT.push_back(P_rel);
            }
            else
            {
                if(Val_Mask > MA_MaskBinary.at<uchar>(y-1, x))
                    vBorderT.push_back(P_rel);
            }

            //check bottom border
            if(y == mask_sy - 1)
            {
                if(Val_Mask > 0)
                    vBorderB.push_back(P_rel);
            }
            else
            {
                if(Val_Mask > MA_MaskBinary.at<uchar>(y+1, x))
                    vBorderB.push_back(P_rel);
            }
        }

    //init adresses of add/rem point lists (updated later, just done here to be safe)
    vBorderAdd = &vBorderR;
    vBorderRem = &vBorderL;

    //show
    Update_Image_Mask();

    //next step is:
    pLabelStatus->setText("NEXT: Save current data as line begin (needed to reset on new line)");
    step_next = STEP_SAVE_LINE_BEGIN;
}

void D_MAKRO_HuangVisualization::Init_HistLegend()
{
    MA_Hist_Legend = Mat(1, 256, CV_8UC1);

    //axis
    for(int v = 0; v < 256; v++)
        MA_Hist_Legend.at<uchar>(0, v) = v;

    //show
    Viewer_Hist_Legend.Update_Image(&MA_Hist_Legend);
}

void D_MAKRO_HuangVisualization::Step_SaveLineBegin()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //histo and masses at start of line
    hist_line_begin         = hist;
    mass_smaller_line_begin = mass_smaller;
    mass_quantil_line_begin = mass_quantil;
    mass_greater_line_begin = mass_greater;
    quantil_val_line_begin  = quantil_val;

    //next step is:
    pLabelStatus->setText("NEXT: Pixel - Change position");
    step_next = STEP_PIXEL_CHANGE_POS;
}

void D_MAKRO_HuangVisualization::Step_LoadLineBegin()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //jump back to leftmost position
    pos_x = 0;
    hist = hist_line_begin;
    mass_smaller = mass_smaller_line_begin;
    mass_quantil = mass_quantil_line_begin;
    mass_greater = mass_greater_line_begin;
    quantil_val  = quantil_val_line_begin;

    //show
    ui->label_mass_smaller->setText(QString::number(mass_smaller));
    ui->label_mass_quantil->setText(QString::number(mass_quantil));
    ui->label_mass_greater->setText(QString::number(mass_greater));
    Update_Image_In();
    Update_Image_Mask();
    Update_Plot_Hist();
    Update_Plot_Mass();

    //next step is:
    pLabelStatus->setText("NEXT: Pixel - Change position");
    step_next = STEP_PIXEL_CHANGE_POS;
}

void D_MAKRO_HuangVisualization::Step_Pixel_ChangePos()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //change indices based on direction
    switch (direction) {
    case c_DIR2D_R:     pos_x++;    break;
    case c_DIR2D_D:     pos_y++;    break;
    default:                        break;}

    //show
    ui->label_x->setText(QString::number(pos_x));
    ui->label_y->setText(QString::number(pos_y));
    Update_Image_In();

    //next step is:
    pLabelStatus->setText("NEXT: Pixel - Change point lists to get add/remove values");
    step_next = STEP_PIXEL_CHANGE_POINT_LISTS;
}

void D_MAKRO_HuangVisualization::Step_Pixel_ChangePointLists()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    dx_to_prev_pos = 0;
    dy_to_prev_pos = 0;
    switch (direction) {
    case c_DIR2D_R:     vBorderAdd = &vBorderR;     vBorderRem = &vBorderL;     dx_to_prev_pos = -1;    break;
    case c_DIR2D_D:     vBorderAdd = &vBorderB;     vBorderRem = &vBorderT;     dy_to_prev_pos = -1;    break;
    default:                                                                                            break;}

    //reset pos in points list
    i_add_rem = 0;

    //show
    Update_Image_Mask();

    //next step is:
    pLabelStatus->setText("NEXT: Value - Get values to add/remove");
    step_next = STEP_POINT_CHANGE_ADD_REM;
}

void D_MAKRO_HuangVisualization::Step_Point_ChangeAddRem()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //get values to add/remove
    val_add = MA_ImgIn_GrayPadded.at<uchar>(pos_y + mask_cy + (*vBorderAdd)[i_add_rem].y,                  pos_x + mask_cx + (*vBorderAdd)[i_add_rem].x);
    val_rem = MA_ImgIn_GrayPadded.at<uchar>(pos_y + mask_cy + (*vBorderRem)[i_add_rem].y + dy_to_prev_pos, pos_x + mask_cx + (*vBorderRem)[i_add_rem].x + dx_to_prev_pos);

    //show
    ui->label_add->setText(QString::number(val_add));
    ui->label_rem->setText(QString::number(val_rem));
    Update_Image_In();
    Update_Image_Mask();

    //next step is:
    pLabelStatus->setText("NEXT: Value - Update histogram");
    step_next = STEP_POINT_CHANGE_HIST;
}

void D_MAKRO_HuangVisualization::Step_Point_Change_Hist()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //update histogram
    hist[val_add]++;
    hist[val_rem]--;

    //show
    Update_Plot_Hist();

    //next step is:
    pLabelStatus->setText("NEXT: Value - Add add-value to mass");
    step_next = STEP_POINT_CHANGE_MASSES_ADD;
}

void D_MAKRO_HuangVisualization::Step_Point_Change_Masses_Add()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //update masses
    //add
    if(val_add > quantil_val)           mass_greater++;
    else if (val_add < quantil_val)     mass_smaller++;
    else                                mass_quantil++;

    //show
    ui->label_mass_smaller->setText(QString::number(mass_smaller));
    ui->label_mass_quantil->setText(QString::number(mass_quantil));
    ui->label_mass_greater->setText(QString::number(mass_greater));

    //show
    Update_Plot_Mass();

    //next step is:
    pLabelStatus->setText("NEXT: Value - Remove remove-values from mass");
    step_next = STEP_POINT_CHANGE_MASSES_REM;
}

void D_MAKRO_HuangVisualization::Step_Point_Change_Masses_Rem()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //update masses
    //remove
    if(val_rem > quantil_val)           mass_greater--;
    else if (val_rem < quantil_val)     mass_smaller--;
    else                                mass_quantil--;

    //show
    ui->label_mass_smaller->setText(QString::number(mass_smaller));
    ui->label_mass_quantil->setText(QString::number(mass_quantil));
    ui->label_mass_greater->setText(QString::number(mass_greater));

    //show
    Update_Plot_Mass();

    //next step is:
    pLabelStatus->setText("NEXT: Value - Check, if masses match threshold or if quantile must be changed");
    step_next = STEP_POINT_CHECK_MASSES;
}

void D_MAKRO_HuangVisualization::Step_Point_Check_Masses()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //mass checks
    check_smaller = mass_smaller + mass_quantil >= mass_smaller_or_equal_needed;
    check_greater = mass_greater + mass_quantil >= mass_greater_or_equal_needed;

    //next step is:
    if(check_smaller && !check_greater)
    {
        //decrease quantil value
        pLabelStatus->setText("NEXT: Value - Decrease quantil - Change mass greater");
        step_next = STEP_POINT_QUANTIL_DECREASE_CHANGE_MASS_GREATER;
    }
    else if(!check_smaller && check_greater)
    {
        //increase quantil value
        pLabelStatus->setText("NEXT: Value - Increase quantil - Change mass smaller");
        step_next = STEP_POINT_QUANTIL_INCREASE_CHANGE_MASS_SMALLER;
    }
    else
    {
        //don't change quantile
        pLabelStatus->setText("NEXT: Value - Don't change quantil - Go to next Value");
        step_next = STEP_POINT_END;
    }
}

void D_MAKRO_HuangVisualization::Step_Point_Quantil_Decrease_Change_Mass_Greater()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //update mass greater
    mass_greater += mass_quantil;

    //show
    ui->label_mass_greater->setText(QString::number(mass_greater));
    Update_Plot_Mass();

    //next step is:
    pLabelStatus->setText("NEXT: Value - Decrease quantil - Change quantil");
    step_next = STEP_POINT_QUANTIL_DECREASE_CHANGE_QUANTIL;
}

void D_MAKRO_HuangVisualization::Step_Point_Quantil_Decrease_Change_Quantil()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //search new quantile
    do
        quantil_val--;
    while (hist[static_cast<size_t>(quantil_val)] == 0);

    //show
    ui->label_quantil->setText(QString::number(quantil_val));
    Update_Plot_Hist();

    //next step is:
    pLabelStatus->setText("NEXT: Value - Decrease quantil - Change mass quantil");
    step_next = STEP_POINT_QUANTIL_DECREASE_CHANGE_MASS_QUANTIL;
}

void D_MAKRO_HuangVisualization::Step_Point_Quantil_Decrease_Change_Mass_Quantil()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //update mass quantile
    mass_quantil = hist[static_cast<size_t>(quantil_val)];

    //show
    ui->label_mass_quantil->setText(QString::number(mass_quantil));
    Update_Plot_Mass();

    //next step is:
    pLabelStatus->setText("NEXT: Value - Decrease quantil - Change mass smaller");
    step_next = STEP_POINT_QUANTIL_DECREASE_CHANGE_MASS_SMALLER;
}

void D_MAKRO_HuangVisualization::Step_Point_Quantil_Decrease_Change_Mass_Smaller()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //update mass smaller
    mass_smaller -= mass_quantil;

    //show
    ui->label_mass_smaller->setText(QString::number(mass_smaller));
    Update_Plot_Mass();

    //next step is:
    pLabelStatus->setText("NEXT: Value - Go to next value");
    step_next = STEP_POINT_END;
}

void D_MAKRO_HuangVisualization::Step_Point_Quantil_Increase_Change_Mass_Smaller()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //update mass smaller
    mass_smaller += mass_quantil;

    //show
    ui->label_mass_smaller->setText(QString::number(mass_smaller));
    Update_Plot_Mass();

    //next step is:
    pLabelStatus->setText("NEXT: Value - Increase quantil - Change quantil");
    step_next = STEP_POINT_QUANTIL_INCREASE_CHANGE_QUANTIL;
}

void D_MAKRO_HuangVisualization::Step_Point_Quantil_Increase_Change_Quantil()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;
    //search new quantile
    do
        quantil_val++;
    while (hist[static_cast<size_t>(quantil_val)] == 0);

    //show
    ui->label_quantil->setText(QString::number(quantil_val));
    Update_Plot_Hist();

    //next step is:
    pLabelStatus->setText("NEXT: Value - Increase quantil - Change mass quantil");
    step_next = STEP_POINT_QUANTIL_INCREASE_CHANGE_MASS_QUANTILE;
}

void D_MAKRO_HuangVisualization::Step_Point_Quantil_Increase_Change_Mass_Quantil()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //update mass quantile
    mass_quantil = hist[static_cast<size_t>(quantil_val)];

    //show
    ui->label_mass_quantil->setText(QString::number(mass_quantil));
    Update_Plot_Mass();

    //next step is:
    pLabelStatus->setText("NEXT: Value - Increase quantil - Change mass greater");
    step_next = STEP_POINT_QUANTIL_INCREASE_CHANGE_MASS_GREATER;
}

void D_MAKRO_HuangVisualization::Step_Point_Quantil_Increase_Change_Mass_Greater()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //update mass greater
    mass_greater -= mass_quantil;

    //show
    ui->label_mass_greater->setText(QString::number(mass_greater));
    Update_Plot_Mass();

    //next step is:
    pLabelStatus->setText("NEXT: Value - Go to next value");
    step_next = STEP_POINT_END;
}

void D_MAKRO_HuangVisualization::Step_Point_End()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //increment add/remove point index
    i_add_rem++;

    //next step is:

    //more points in list to proc?
    if(i_add_rem < vBorderAdd->size())
    {
        pLabelStatus->setText("NEXT: Value - Get values to add/remove");
        step_next = STEP_POINT_CHANGE_ADD_REM;
    }
    else
    {
        pLabelStatus->setText("NEXT: Pixel - Write Result");
        step_next = STEP_PIXEL_WRITE_OUT;
    }
}

void D_MAKRO_HuangVisualization::Step_Pixel_WriteOut()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //write quantil value to output image
    MA_ImgOut_Gray.at<uchar>(pos_y + mask_cy, pos_x + mask_cx) = quantil_val;

    //copy out data under mask to zoomed view
    for(int y = 0; y < MA_MaskShow_Out.rows; y++)
        for(int x = 0; x < MA_MaskShow_Out.cols; x++)
            MA_MaskShow_Out.at<uchar>(y, x) = MA_ImgOut_Gray.at<uchar>(y + pos_y, x + pos_x);

    //show
    Update_Image_Out();

    //next step is:
    pLabelStatus->setText("NEXT: Pixel - Check, if direction must change");
    step_next = STEP_PIXEL_CHANGE_DIRECTION;
}

void D_MAKRO_HuangVisualization::Step_Pixel_Change_Direction()
{
    if(!state_img_loaded || !state_img_padded || !state_mask_loaded || !state_img_out_init || !state_quantil_rel_set)
        return;

    //check for direction change or end
    switch (direction) {

    case c_DIR2D_R:
    {
        if(pos_x >= img_in_sx - 1)          //at right border from left
        {
            if(pos_y >= img_in_sy - 1)
            {
                at_end = true;              //at right and bottom border
                pLabelStatus->setText("NEXT: Finished :-)");
                step_next = STEP_END;
            }
            else
            {
                direction = c_DIR2D_D;      //at right but not at bottom border

                //jump back to leftmost position
                //next step:
                pLabelStatus->setText("NEXT: Load data from and jump back to line begin");
                step_next = STEP_LOAD_LINE_BEGIN;
            }
        }
        else
        {
            //"normal step" to the right
            //next step:
            pLabelStatus->setText("NEXT: Pixel - Change position");
            step_next = STEP_PIXEL_CHANGE_POS;
        }
    }
        break;

    case c_DIR2D_D:
    {
        direction = c_DIR2D_R;

        //update to new line begin (one line lower than old line begin)
        //next step:
        pLabelStatus->setText("NEXT: Save current data as line begin (needed to reset on new line)");
        step_next = STEP_SAVE_LINE_BEGIN;
    }
        break;

    default:
        break;
    }

    //show
    if(direction == c_DIR2D_R)
        ui->label_direction->setText("right");
    else
        ui->label_direction->setText("down");
}


void D_MAKRO_HuangVisualization::on_pushButton_VideoGuide_clicked()
{
    QDesktopServices::openUrl(QUrl("https://youtu.be/j_3wfKGABgQ"));
}
