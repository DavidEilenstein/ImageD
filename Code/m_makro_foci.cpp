/************************************
 *   added:     13.11.2018          *
 *   author:    Manon Nickler       *
 *   contact:   M.Nickler@gsi.de    *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "m_makro_foci.h"
#include "ui_m_makro_foci.h"

m_makro_foci::m_makro_foci(D_Storage *pStorage,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::m_makro_foci)
{
    ui->setupUi(this);

    pStore = pStorage;

    Flag_selected_Bckgd = false;
    Flag_loaded_image=false;

    ui->tabWidget->setTabEnabled(e_TAB_CURVES,false);
    ui->tabWidget->setTabEnabled(e_TAB_SAVE,false);
    ui->tabWidget->setTabToolTip(3,QString("First you need to select background areas"));
    ui->tabWidget->setTabToolTip(4,QString("First you need to select background areas"));

    //GraphicsView

    V_Nuclei_tab_Average.set_GV(ui->graphicsView_average);
    V_Nuclei_tab_Average.set_Name("Average image");

    V_Nuclei_img_proc.set_GV(ui->graphicsView_img_proc);
    V_Nuclei_img_proc.set_Name("Processing");

    V_Nuclei_Label_Foci.set_GV(ui->graphicsView_label_foci);
    V_Nuclei_Label_Foci.set_Name("Label foci");

    V_Nuclei_tab_Results.set_GV(ui->graphicsView_detected_foci);
    V_Nuclei_tab_Results.set_Name("Results ");

    V_Nuclei_tab_Add_focus.set_GV(ui->graphicsView_add_focus);
    V_Nuclei_tab_Add_focus.set_Name("Add focus ");

    V_Nuclei_tab_Curves.set_GV(ui->graphicsView_curves);
    V_Nuclei_tab_Curves.set_Name("Curves ");



    //HIST
    //Init chart and chartview
    Chart_Hist = new QChart();
    //Chart_Hist->createDefaultAxes();
    ChartView_Hist = new QChartView(this);
    ChartView_Hist->setChart(Chart_Hist);
    ui->gridLayout_hist->addWidget(ChartView_Hist);
    ChartView_Hist->setRenderHint(QPainter::Antialiasing);
    ChartView_Hist->setRubberBand(QChartView::RectangleRubberBand);
    ChartView_Hist->setInteractive(true);

    Size_image_in_time = ui->spinBox_size_t->value();

   //allocate memory for images
    vMA_Nuclei.resize(Size_image_in_time);
    for(unsigned int i = 0; i < vMA_Nuclei.size(); i++)
        vMA_Nuclei[i] = pStore->get_Adress(0)->clone();

    vMA_Average.resize(c_SC_NUCLEI);//
    for(unsigned int i = 0; i < vMA_Average.size(); i++)
        vMA_Average[i] = pStore->get_Adress(0)->clone();

    vvMA_Nuclei.resize(c_SC_NUCLEI);
    for(unsigned int i = 0; i < vvMA_Nuclei.size(); i++)
    {vvMA_Nuclei[i].resize(Size_image_in_time);
        for(unsigned int j = 0; j < vvMA_Nuclei[i].size(); j++)
             vvMA_Nuclei[i][j] = pStore->get_Adress(0)->clone();
    }

    MA_Average_area_without_bckgd = pStore->get_Adress(0)->clone();

    //STATUSBAR
    int LabelWidth = 75;

    L_SB_ValAtPos = new QLabel(this);
    L_SB_ValAtPos->setFixedWidth(LabelWidth * 2);
    L_SB_ValAtPos->setToolTip("Pixelvalue (Mouse hovered).");
    ui->statusbar->addPermanentWidget(L_SB_ValAtPos);

    L_SB_Path = new QLabel(this);
    L_SB_Path->setFixedWidth(LabelWidth * 10);
    ui->statusbar->addPermanentWidget(L_SB_Path);
    L_SB_Path->setWordWrap(true);

/*    label_state_currentL_SB_State = new QLabel(this);
    L_SB_State->setFixedWidth(LabelWidth * 3);
    ui->statusbar->addPermanentWidget(L_SB_State);
*/

    //CONNECTS

    //General
    //Statusbar Updates and other info
    connect(&V_Nuclei_tab_Average,                      SIGNAL(MouseMoved_Value(QString)),          L_SB_ValAtPos,  SLOT(setText(QString)));
    connect(&V_Nuclei_img_proc,                         SIGNAL(MouseMoved_Value(QString)),          L_SB_ValAtPos,  SLOT(setText(QString)));
    connect(&V_Nuclei_Label_Foci,                       SIGNAL(MouseMoved_Value(QString)),          L_SB_ValAtPos,  SLOT(setText(QString)));
    connect(&V_Nuclei_tab_Results,                      SIGNAL(MouseMoved_Value(QString)),          L_SB_ValAtPos,  SLOT(setText(QString)));
    connect(&V_Nuclei_tab_Curves,                      SIGNAL(MouseMoved_Value(QString)),          L_SB_ValAtPos,  SLOT(setText(QString)));

    //Update view
    connect(ui->comboBox_step_av,                       SIGNAL(currentIndexChanged(int)),           this,   SLOT(Update_View()));
    connect(ui->comboBox_step_img_proc,                 SIGNAL(currentIndexChanged(int)),           this,   SLOT(Update_View()));
    connect(ui->comboBox_step_results,                  SIGNAL(currentIndexChanged(int)),           this,   SLOT(Update_View()));
    connect(ui->tabWidget,                              SIGNAL(currentChanged(int)),                this,   SLOT(Update_View()));

    connect(ui->horizontalSlider_Image_in_Time,         SIGNAL(valueChanged(int)),                  this,   SLOT(Update_View()));
    connect(ui->horizontalSlider_Image_in_Time_img_proc,SIGNAL(valueChanged(int)),                  this,   SLOT(Update_View()));
    connect(ui->horizontalSlider_Image_in_Time_label_foci,  SIGNAL(valueChanged(int)),              this,   SLOT(Update_View()));
    connect(ui->horizontalSlider_Image_in_Time_results,     SIGNAL(valueChanged(int)),              this,   SLOT(Update_View()));
    connect(ui->horizontalSlider_Image_in_Time_curves,      SIGNAL(valueChanged(int)),              this,   SLOT(Update_View()));
    connect(ui->horizontalSlider_Image_in_Time_curves,      SIGNAL(valueChanged(int)),              this,   SLOT(Update_displayed_time()));
    connect(ui->horizontalSlider_Image_in_Time_curves,      SIGNAL(valueChanged(int)),              this,   SLOT(Update_Curves()));

    //Background
    connect(ui->checkBox_select_area,                   SIGNAL(stateChanged(int)),                  this,   SLOT(Enable_disable_select_area()));
    connect(ui->checkBox_show_area,                     SIGNAL(stateChanged(int)),                  this,   SLOT(Update_View()));
    connect(ui->pushButton_remove_area,                 SIGNAL(clicked()),                          this,   SLOT(Delete_bckgd_area()));
    connect(ui->pushButton_confirm_area,                SIGNAL(clicked()),                          this,   SLOT(Confirm_bckgd_area()));


    // TAB Images settings

    //Load image
    connect(ui->comboBox_Load_Mode,                     SIGNAL(currentIndexChanged(int)),           this,   SLOT(Update_SimpleOrMulti_Page()));
    connect(ui->pushButton_Insert_Path,                 SIGNAL(clicked(bool)),                      this,   SLOT(Update_ImgProc_Results()));

    //Time Scale
    connect(ui->spinBox_size_t,                         SIGNAL(valueChanged(int)),                  this,   SLOT(Update_size_t()));
    connect(ui->spinBox_nb_intervals,                   SIGNAL(valueChanged(int)),                  this,   SLOT(Update_nb_interval()));
    connect(ui->spinBox_time_interval_from,             SIGNAL(valueChanged(int)),                  this,   SLOT(Update_time_interval_values()));
    connect(ui->spinBox_time_interval_to,               SIGNAL(valueChanged(int)),                  this,   SLOT(Update_time_interval_values()));
    connect(ui->spinBox_time_interval_value,            SIGNAL(valueChanged(int)),                  this,   SLOT(Update_time_interval_values()));
    connect(ui->comboBox_time_intervals,                SIGNAL(currentIndexChanged(int)),           this,   SLOT(Update_ComboBox_index_changes()));
    connect(ui->pushButton_generate_Time_Scale,         SIGNAL(clicked()),                          this,   SLOT(Update_Time_scale()));
    //Options images
    connect(ui->checkBox_blur_images,                   SIGNAL(stateChanged(int)),                  this,   SLOT(Settings_parameters_changed()));
    connect(ui->doubleSpinBox_gamma,                    SIGNAL(stateChanged(int)),                  this,   SLOT(Settings_parameters_changed()));

    // TAB image processing

    //threshold
    connect(ui->spinBox_03_Mask_size,                   SIGNAL(valueChanged(int)),                  this,   SLOT(Threshold_parameters_changed()));
    connect(ui->spinBox_03_Offset,                      SIGNAL(valueChanged(int)),                  this,   SLOT(Threshold_parameters_changed()));
    connect(ui->checkBox_nucleus_contour,               SIGNAL(stateChanged(int)),                  this,   SLOT(Threshold_parameters_changed()));

    //Options images
    connect(ui->spinBox_radius_circle_move,             SIGNAL(valueChanged(int)),                  this,   SLOT(Foci_tracking_parameters_changed()));
    connect(ui->spinBox_radius_circle_intensity,        SIGNAL(valueChanged(int)),                  this,   SLOT(Foci_feature_parameters_changed()));

    //Update processing
    connect(ui->pushButton_update,                      SIGNAL(clicked()),                          this,   SLOT(Update_ImgProc_Results()));
    connect(ui->pushButton_Update_all_from_convert,     SIGNAL(clicked()),                          this,   SLOT(Update_ImgProc_Results()));

    //Update view labeled
    connect(ui->doubleSpinBox_size_font,                SIGNAL(valueChanged(double)),               this,   SLOT(Update_ImgProc_Results()));
    connect(ui->checkBox_Circled_foci_with_label,       SIGNAL(stateChanged(int)),                  this,   SLOT(Update_ImgProc_Results()));
    connect(ui->pushButton_delete_foci_tab_results,     SIGNAL(clicked()),                          this,   SLOT(Unselect_non_pertinent_Foci_User()));


    //Tab curves

    // curves
    connect(ui->horizontalSlider_curve_label,           SIGNAL(valueChanged(int)),                  this,   SLOT(Update_Curves()));
    connect(ui->horizontalSlider_curve_label,           SIGNAL(valueChanged(int)),                  this,   SLOT(Update_detail_Values()));
    connect(ui->horizontalSlider_curve_label,           SIGNAL(valueChanged(int)),                  this,   SLOT(Update_View()));

    connect(ui->checkBox_selected_foci,                 SIGNAL(stateChanged(int)),                  this,   SLOT(Update_Curves()));
    connect(ui->checkBox_selected_foci,                 SIGNAL(stateChanged(int)),                  this,   SLOT(Update_Step_Results_feature()));

    connect(ui->checkBox_scale_curve,                   SIGNAL(stateChanged(int)),                  this,   SLOT(Update_Curves()));
    connect(ui->checkBox_filtered_values,               SIGNAL(stateChanged(int)),                  this,   SLOT(Update_Curves()));
    connect(ui->checkBox_first_deriv,                   SIGNAL(stateChanged(int)),                  this,   SLOT(Update_Curves()));
    connect(ui->checkBox_2nd_deriv,                     SIGNAL(stateChanged(int)),                  this,   SLOT(Update_Curves()));

    //Selection foci

    connect(ui->pushButton_delete_foci,                 SIGNAL(clicked()),                          this,   SLOT(Unselect_non_pertinent_Foci_User()));
    connect(ui->doubleSpinBox_Select_pertinent_Foci_Std_dev,SIGNAL(valueChanged(double)),           this,   SLOT(Select_pertinent_Foci()));
    connect(ui->checkBox_selection_foci_decreasing_curves,SIGNAL(stateChanged(int)),                this,   SLOT(Select_pertinent_Foci()));
    connect(ui->checkBox_selection_foci_too_close,      SIGNAL(stateChanged(int)),                  this,   SLOT(Select_pertinent_Foci()));
    connect(ui->checkBox_selection_not_enough_time,     SIGNAL(stateChanged(int)),                  this,   SLOT(Select_pertinent_Foci()));

    //emergence time
    connect(ui->spinBox_time_window,                    SIGNAL(valueChanged(int)),                  this,   SLOT(Update_Step_Results_feature()));
    connect(ui->doubleSpinBox_coeff_std_dev,            SIGNAL(valueChanged(double)),               this,   SLOT(Update_Step_Results_feature()));

    connect(ui->spinBox_Emergence_time,                 SIGNAL(valueChanged(int)),                  this,   SLOT(Set_emergence_time_by_user()));
    connect(ui->spinBox_emergence_time_offset,          SIGNAL(valueChanged(int)),                  this,   SLOT(Condition_emergence_time()));
    connect(ui->spinBox_emergence_time_offset,          SIGNAL(valueChanged(int)),                  this,   SLOT(Update_Curves()));
    connect(ui->spinBox_emergence_time_offset,          SIGNAL(valueChanged(int)),                  this,   SLOT(Update_detail_Values()));

    // TAB Save
    connect(ui->pushButton_save_in_file,                SIGNAL(clicked()),                          this,   SLOT(Save_csv_file()));
//    connect(ui->pushButton_save_in_file,                SIGNAL(clicked()),                          this,   SLOT(Save_csv_file_full()));


    connect(&V_Nuclei_tab_Add_focus,                    SIGNAL(MouseClicked_Pos(int,int)),          this,   SLOT(Add_focus_user(int, int)));

    connect(ui->pushButton_delete_added_foci,           SIGNAL(clicked()),                          this,   SLOT(Delete_added_foci_user()));
    connect(ui->pushButton_added_foci_confirm,          SIGNAL(clicked()),                          this,   SLOT(Confirm_Added_focus_user()));



    Update_nb_interval();
    Update_time_interval_values();
    Ititialise_time_interval();
    Enable_disable_select_area();
    Update_SimpleOrMulti_Page();
    Update_View();

    FeatureFoci_nb_label=0;
    ui->label_state_current->setText("Ready");
}

m_makro_foci::~m_makro_foci()
{
    delete ui;
}

void m_makro_foci::closeEvent(QCloseEvent *event)
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

void m_makro_foci::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "Makro_foci", func, detail);
}

void m_makro_foci::Update_View()
{
 //   qDebug()<<"start Up view";
   switch(ui->tabWidget->currentIndex())
   {
   case e_TAB_AVERAGE:{
       switch(ui->comboBox_step_av->currentIndex()){
            case c_ST_N_LOAD:
                V_Nuclei_tab_Average.Update_Image(&(vvMA_Nuclei[ui->comboBox_step_av->currentIndex()][ui->horizontalSlider_Image_in_Time->value()]));
            break;

            case c_ST_N_INPUT_CONV_8BIT:
                V_Nuclei_tab_Average.Update_Image(&(vvMA_Nuclei[c_ST_N_INPUT_CONV_16BIT][ui->horizontalSlider_Image_in_Time->value()]));
            break;

            case c_sT_N_AVERAGE_IMAGE:
                if(ui->checkBox_show_area->isChecked())
                   V_Nuclei_tab_Average.Update_Image(&MA_Average_area);
                else
                   V_Nuclei_tab_Average.Update_Image(&vMA_Average[0]);
            break;

            case c_sT_N_THRESHOLD_AVERAGE_IMG:
                V_Nuclei_tab_Average.Update_Image(&vMA_Average[1]); //
            break;

            case c_sT_N_REDUCTION_AVERAGE_IMG:
                V_Nuclei_tab_Average.Update_Image(&vMA_Average[2]);
            break;

       default: break;
        }
    }
    break;

    case (e_TAB_IMG_PROC):{
        switch(ui->comboBox_step_img_proc->currentIndex()){
            case c_ST_N_INPUT_CONV_8BIT_VIEW:
                V_Nuclei_img_proc.Update_Image(&(vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][ui->horizontalSlider_Image_in_Time_img_proc->value()]));
            break;

            case c_sT_N_THRESHOLD_VIEW:
                V_Nuclei_img_proc.Update_Image(&(vvMA_Nuclei[c_sT_N_THRESHOLD][ui->horizontalSlider_Image_in_Time_img_proc->value()]));
            break;

            case c_sT_N_REDUCTION_VIEW:
                V_Nuclei_img_proc.Update_Image(&(vvMA_Nuclei[c_sT_N_REDUCTION][ui->horizontalSlider_Image_in_Time_img_proc->value()]));
            break;
            case c_sT_N_CIRCLED_NUCLEUS:
                V_Nuclei_img_proc.Update_Image(&vvMA_Nuclei[c_ST_N_Contour_nuclei][ui->horizontalSlider_Image_in_Time_img_proc->value()]);
            break;
            default:
            break;
            //   V_Nuclei_img_proc.Update_Image(&(vvMA_Nuclei[ui->comboBox_step_img_proc->currentIndex()][ui->horizontalSlider_Image_in_Time_tab2->value()]));
        }
    }
    break;
    case(e_TAB_SAVE):{
       V_Nuclei_Label_Foci.Update_Image(&(vvMA_Nuclei[c_sT_N_Label_in_time_dilated][ui->horizontalSlider_Image_in_Time_label_foci->value()]));
   }
   break;

    case(e_TAB_RESULTS):{
       int time = ui->horizontalSlider_Image_in_Time_results->value();

        switch(ui->comboBox_step_results->currentIndex()){

            case c_sT_N_CIRCLED_FOCI_VIEW:
            {
            if(ui->checkBox_Circled_foci_with_label->isChecked())
                V_Nuclei_tab_Results.Update_Image(&(vvMA_Nuclei[c_sT_N_Label_in_time_CIRCLED_with_labels][time]));
            else
                V_Nuclei_tab_Results.Update_Image(&(vvMA_Nuclei[c_sT_N_Label_in_time_CIRCLED_without_labels][time]));
            break;
            }

            case c_sT_N_ADD_FOCUS:
            {
            V_Nuclei_tab_Add_focus.Update_Image(&(MA_Max_proj_add_focus));

            break;
            }
        default:
            break;
       }
    }
    break;

    case (e_TAB_CURVES):{
        int label;
        if(ui->checkBox_selected_foci->checkState()){
//            qDebug()<<"update view label :"<<ui->horizontalSlider_curve_label->value();
            if (ui->horizontalSlider_curve_label->value()<LabelFociSelected_To_LabelFoci.size())
                label = LabelFociSelected_To_LabelFoci[ui->horizontalSlider_curve_label->value()];
        }
        else
            label =ui->horizontalSlider_curve_label->value();

        if(ui->horizontalSlider_Image_in_Time_curves->value()<vMA_Circled_Focus.size())
            V_Nuclei_tab_Curves.Update_Image(&(vMA_Circled_Focus[ui->horizontalSlider_Image_in_Time_curves->value()]));

        break;
       }
    }
     Update_Ui();
//       qDebug()<<"end Up view";
}

void m_makro_foci::Update_Ui()
{
    if(this->isEnabled())
        return;

    qApp->processEvents();
    this->repaint();

}

//------------------------------------------------------------------------------------
// ----------------------------------  Updates  --------------------------------------
//------------------------------------------------------------------------------------

void m_makro_foci::Update_SimpleOrMulti_Page()
{
    if (ui->comboBox_Load_Mode->currentIndex() == c_ST_single_page){
        Ititialise_time_interval();
        ui->spinBox_size_t->setValue(1);
    }
    else
    {
        Ititialise_time_interval();
        ui->spinBox_size_t->setValue(80);
    }
   ui->horizontalSlider_Image_in_Time->setMaximum(Size_image_in_time-1);
   ui->horizontalSlider_Image_in_Time_img_proc->setMaximum(Size_image_in_time-1);
   ui->horizontalSlider_Image_in_Time_label_foci->setMaximum(Size_image_in_time-1);
   ui->horizontalSlider_Image_in_Time_results->setMaximum(Size_image_in_time-1);
   ui->horizontalSlider_Image_in_Time_curves->setMaximum(Size_image_in_time-1);

   ui->horizontalSlider_Image_in_Time->setValue(0);
   ui->horizontalSlider_Image_in_Time_img_proc->setValue(0);
   ui->horizontalSlider_Image_in_Time_label_foci->setValue(0);
   ui->horizontalSlider_Image_in_Time_results->setValue(0);
   ui->horizontalSlider_Image_in_Time_curves->setValue(0);

}

void m_makro_foci::Update_ImgProc_Results()
{
    this->setEnabled(true);
    ui->label_state_current->setText("Busy");
    qApp->processEvents();
    this->repaint();
    this->setEnabled(false);

    int start_step;
    switch (ui->tabWidget->currentIndex()) {

    case e_TAB_AVERAGE:
    {
        start_step = ui->comboBox_step_av->currentIndex();
        for(int s = start_step; s <c_SC_NUCLEI; s++){
                 Update_Step_Results_av(s);
                 if (Flag_loaded_image == false) break;

        }

        for(int s = 0; s <c_SC_NUCLEI; s++){
                 Update_Step_Results_all(s);
        if (Flag_loaded_image == false) break;
        }
   }
        break;
    case e_TAB_IMG_PROC:
    {
        int start_step=0;
        if (Flag_loaded_image == false) break;
 //       start_step = ui->comboBox_step_img_proc->currentIndex();
        switch (ui->comboBox_step_img_proc->currentIndex()){
            case e_IMG_PROC_ORIGINAL:
                start_step=c_sT_N_THRESHOLD;
            break;
            case e_IMG_PROC_THRESHOLD:
                start_step=c_sT_N_THRESHOLD;
            break;
            case e_IMG_PROC_REDUCE:
                start_step=c_sT_N_REDUCTION+1;
            break;
        }

        for(int s = start_step; s <c_SC_NUCLEI; s++){
                 Update_Step_Results_all(s);
        }
        Update_Step_Results_feature();
    }
        break;

    case e_TAB_RESULTS:
    {
        if (Flag_loaded_image == false) break;
        qDebug()<<"Update_ImgProc_Results e_TAB_RESULTS : Circled_selected_centroid";
        Circled_selected_centroid();
        break;
    }

    default:
        break;

    }

    ui->pushButton_update->setAutoFillBackground(true);
    ui->pushButton_update->setStyleSheet("background-color: rgb(240, 240, 240)");
    ui->pushButton_update->show();
    ui->pushButton_Update_all_from_convert->setAutoFillBackground(true);
    ui->pushButton_Update_all_from_convert->setStyleSheet("background-color: rgb(240, 240, 240)");
    ui->pushButton_Update_all_from_convert->show();

    this->setEnabled(true);
    Update_View();
    qDebug()<<"--->end Update_ImgProc_Results";
    ui->label_state_current->setText("Ready");
}

void m_makro_foci::Update_Step_Results_av(int step)
{
    if(step != c_ST_N_LOAD)
        this->setEnabled(false);

    switch (step) {
    case c_ST_N_LOAD:
    {
        ui->label_state_current->setText("Loading image");
        step_load();
        ui->label_state_current->setText("Busy");
    }
        break;

    case c_ST_N_INPUT_CONV_8BIT:
        Convert();
         break;

    case c_sT_N_AVERAGE_IMAGE:
        step_average();
         break;

    default:
          break;
    }

    this->setEnabled(true);
}

void m_makro_foci::Update_Step_Results_all(int step)
{
    this->setEnabled(false);
    switch (step) {

    case c_ST_N_INPUT_CONV_8BIT:
            Convert();
             break;

    case c_sT_N_THRESHOLD:
    {
        qDebug()<<"Threshold:";
        Threshold();
         qDebug()<<"NUCLEUS EDGES:";
        Nucleus_edges();
        break;
    }

    case c_sT_N_REDUCTION:
    {
        qDebug()<<"reduction:";
        Reduction();
        break;
    }

    case c_sT_N_DILATATION_WITHOUT_LABEL:
    {
        qDebug()<<"dilatation:";
        Dilatation();
        break;
    }

    case c_sT_N_FOCI_NO_BKGRD:
        Finaladd();
        break;

    case c_sT_N_Label_in_time:
    {

        qDebug()<<"Label_in_time:";
        Label_Foci_in_time();
        qDebug()<<"     Interpolation_Feature_Foci:";
        Interpolation_Feature_Foci();
//        qDebug()<<"     Single_Circled_Focus:";
//        Single_Circled_Focus();

        break;
    }

    case c_sT_N_CENTROID_SELECTED:
    {
        qDebug()<<"     Update_selected_centroid:";
        Update_selected_centroid();
        break;
    }

    case c_sT_N_Label_in_time_dilated:
    {
        qDebug()<<"Label_in_time_dilated:";
        Dilatation_centroid_labeled();
        Black_Bckgd_2_white(c_sT_N_Label_in_time_dilated);
        break;
    }
    case c_sT_N_Label_in_time_CIRCLED_without_labels:
    {
        qDebug()<<"c_sT_N_Label_in_time_CIRCLED:";
        Circled_selected_centroid();
        break;
    }

    default:
            break;
    } 

    this->setEnabled(true);
}

void m_makro_foci::Update_Step_Results_feature()
{
    ui->label_state_current->setText("Busy");
    this->setEnabled(false);
    qDebug()<<"FeatureFoci:";
    Feature_Foci();
    qDebug()<<"Normalization_Feature_Foci:";
    Normalization_Feature_Foci();
    qDebug()<<"Filter_Intensity_values:";
    Filter_Intensity_values();
    qDebug()<<"Get_Average_Feature_Foci:";
    Get_Average_Feature_Foci();
    qDebug()<<"Calc_Curves:";
    Calc_Curves();
    qDebug()<<"variance time window:";
    Variance_in_time_window();
    qDebug()<<"Condition_emergence_time:";
    Condition_emergence_time();

    for(int label=0;label<FeatureFoci_nb_label;label++)
        for (int t=0;t<Size_image_in_time;t++){
                vvvFeatureFoci[label][t][c_sT_Feature_Foci_selected] = true;
            }

    qDebug()<<"Select_pertinent_Foci:";
    Select_pertinent_Foci();

    Update_selected_centroid();
    Circled_selected_centroid();

    Init_add_focus_user();

    this->setEnabled(true);

    Update_View();

    ui->label_state_current->setText("Ready");
}

//------------------------------------------------------------------------------------
// ----------------------------------  Time intervals  --------------------------------------
//------------------------------------------------------------------------------------
void m_makro_foci::Ititialise_time_interval()
{
    if(ui->comboBox_Load_Mode->currentIndex()==c_ST_single_page){
        ui->spinBox_size_t->setValue(1);
        ui->spinBox_size_t->setDisabled(true);
        ui->spinBox_nb_intervals->setValue(1);
        ui->spinBox_nb_intervals->setDisabled(true);
        ui->comboBox_time_intervals->clear();
        ui->comboBox_time_intervals->setDisabled(true);
        ui->spinBox_time_interval_value->setDisabled(true);
        ui->spinBox_initial_time->setValue(0);
        ui->spinBox_initial_time->setDisabled(true);
    }
    else {
        ui->spinBox_size_t->setDisabled(false);
        ui->spinBox_nb_intervals->setDisabled(false);
        ui->comboBox_time_intervals->setDisabled(false);
        ui->spinBox_time_interval_value->setDisabled(false);
        ui->spinBox_initial_time->setDisabled(false);
        ui->spinBox_initial_time->setValue(-30);
        ui->spinBox_nb_intervals->setValue(2);
        ui->comboBox_time_intervals->clear();
        ui->comboBox_time_intervals->insertItem(0,QString::number(1));
        ui->comboBox_time_intervals->insertItem(1,QString::number(2));
        vv_Interval_info[c_sT_Interval_info_To][1]=60;
        vv_Interval_info[c_sT_Interval_info_Value][1]=10;
        vv_Interval_info[c_sT_Interval_info_From][2]=60;
        vv_Interval_info[c_sT_Interval_info_Value][2]=30;
    }


        Update_ComboBox_index_changes();
        Update_Time_scale();
}

void m_makro_foci::Update_size_t()
{
     Size_image_in_time = ui->spinBox_size_t->value();
    //allocate memory for images
     vMA_Nuclei.resize(Size_image_in_time);
     for(unsigned int i = 0; i < vMA_Nuclei.size(); i++)
         vMA_Nuclei[i] = pStore->get_Adress(0)->clone();

     vvMA_Nuclei.resize(c_SC_NUCLEI);
     for(unsigned int i = 0; i < vvMA_Nuclei.size(); i++)
     {vvMA_Nuclei[i].resize(Size_image_in_time);
         for(unsigned int j = 0; j < vvMA_Nuclei[i].size(); j++)
              vvMA_Nuclei[i][j] = pStore->get_Adress(0)->clone();
     }

    Update_nb_interval();
    Update_Time_scale();

    ui->horizontalSlider_Image_in_Time->setMaximum(Size_image_in_time-1);
    ui->horizontalSlider_Image_in_Time_img_proc->setMaximum(Size_image_in_time-1);
    ui->horizontalSlider_Image_in_Time_label_foci->setMaximum(Size_image_in_time-1);
    ui->horizontalSlider_Image_in_Time_results->setMaximum(Size_image_in_time-1);
    ui->horizontalSlider_Image_in_Time_curves->setMaximum(Size_image_in_time-1);

//    Update_SimpleOrMulti_Page();
}

void m_makro_foci::Update_nb_interval()
{
    nb_time_interval=ui->spinBox_nb_intervals->value();

    vv_Interval_info.resize(c_sT_interval_info_number);
        vv_Interval_info[c_sT_Interval_info_From].resize(nb_time_interval+1);
        vv_Interval_info[c_sT_Interval_info_To].resize(nb_time_interval+1);
        vv_Interval_info[c_sT_Interval_info_Value].resize(nb_time_interval+1);

    ui->comboBox_time_intervals->clear();
    nb_combo_time_interval =1;
    while(nb_combo_time_interval<=nb_time_interval){
        ui->comboBox_time_intervals->insertItem(nb_combo_time_interval,QString::number(nb_combo_time_interval));
        nb_combo_time_interval++;
    }


   vv_Interval_info[c_sT_Interval_info_To][nb_time_interval]=ui->spinBox_size_t->value();

   ui->spinBox_time_interval_to->setMaximum(ui->spinBox_size_t->value());
   ui->spinBox_time_interval_from->setMaximum(ui->spinBox_size_t->value());

   Update_ComboBox_index_changes();
   Update_time_interval_values();
}

void m_makro_foci::Update_time_interval_values()
{
    // Because index begin at 0 et interval begin at 1
    int interval = ui->comboBox_time_intervals->currentIndex()+1;
    int previous_interval=interval-1;
    int next_interval= interval+1;

    vv_Interval_info[c_sT_Interval_info_From][interval] =ui->spinBox_time_interval_from->value();
    vv_Interval_info[c_sT_Interval_info_To][interval]   =ui->spinBox_time_interval_to->value();
    vv_Interval_info[c_sT_Interval_info_Value][interval]=ui->spinBox_time_interval_value->value();

    //Update previous to

    while((previous_interval)>0){ // if the current interval is not the first one
        vv_Interval_info[c_sT_Interval_info_To][previous_interval]=vv_Interval_info[c_sT_Interval_info_From][previous_interval+1];
        if (vv_Interval_info[c_sT_Interval_info_From][previous_interval]>vv_Interval_info[c_sT_Interval_info_To][previous_interval])
            vv_Interval_info[c_sT_Interval_info_From][previous_interval]=vv_Interval_info[c_sT_Interval_info_To][previous_interval];

            previous_interval--;
    }
    //Update next from
    while ((next_interval)<=nb_time_interval) { // if the current interval is not the last one
        vv_Interval_info[c_sT_Interval_info_From][next_interval]=vv_Interval_info[c_sT_Interval_info_To][next_interval-1];
        if (vv_Interval_info[c_sT_Interval_info_To][next_interval]<vv_Interval_info[c_sT_Interval_info_From][next_interval])
            vv_Interval_info[c_sT_Interval_info_To][next_interval]=vv_Interval_info[c_sT_Interval_info_From][next_interval];
        next_interval++;
    }

  ui->spinBox_time_interval_to->setMinimum(ui->spinBox_time_interval_from->value());

}

void m_makro_foci::Update_ComboBox_index_changes()
{

    ui->spinBox_time_interval_from->setEnabled(true);
    ui->spinBox_time_interval_to->setEnabled(true);

    disconnect(ui->spinBox_time_interval_from,             SIGNAL(valueChanged(int)),              this,   SLOT(Update_time_interval_values()));
    disconnect(ui->spinBox_time_interval_to,               SIGNAL(valueChanged(int)),              this,   SLOT(Update_time_interval_values()));
    disconnect(ui->spinBox_time_interval_value,            SIGNAL(valueChanged(int)),              this,   SLOT(Update_time_interval_values()));

    int interval = ui->comboBox_time_intervals->currentIndex()+1;

    ui->spinBox_time_interval_from->    setValue(vv_Interval_info[c_sT_Interval_info_From][interval]);
    ui->spinBox_time_interval_to->      setValue(vv_Interval_info[c_sT_Interval_info_To][interval]);
    ui->spinBox_time_interval_value->   setValue(vv_Interval_info[c_sT_Interval_info_Value][interval]);

    connect(ui->spinBox_time_interval_from,             SIGNAL(valueChanged(int)),              this,   SLOT(Update_time_interval_values()));
    connect(ui->spinBox_time_interval_to,               SIGNAL(valueChanged(int)),              this,   SLOT(Update_time_interval_values()));
    connect(ui->spinBox_time_interval_value,            SIGNAL(valueChanged(int)),              this,   SLOT(Update_time_interval_values()));

    if(interval==1)
        ui->spinBox_time_interval_from->setEnabled(false);// ;

    if(interval==ui->spinBox_nb_intervals->value()){
        ui->spinBox_time_interval_to->setEnabled(false);
    }

    ui->spinBox_time_interval_to->setMinimum(ui->spinBox_time_interval_from->value());

}

void m_makro_foci::Update_Time_scale()
{
    v_Time_scale.resize(ui->spinBox_size_t->value());
    for(int t=0;t<v_Time_scale.size();t++)
        v_Time_scale[t]=0;
    v_Time_scale[0]=ui->spinBox_initial_time->value();

//    qDebug()<<"v_Time_Scale["<<0<<"] = "<< v_Time_scale[0];

    int Time_scale_t=0;
    int current_t=2;

    for(int interval=1;interval<=ui->spinBox_nb_intervals->value();interval++){
 //       qDebug()<<"interval "<<interval;
 //       qDebug()<<"current_t "<<current_t<<"< "<<vv_Interval_info[c_sT_Interval_info_To][interval];
        while(current_t<vv_Interval_info[c_sT_Interval_info_To][interval]){
            Time_scale_t=current_t-1;
            v_Time_scale[Time_scale_t]=v_Time_scale[Time_scale_t-1]+vv_Interval_info[c_sT_Interval_info_Value][interval];
 //           qDebug()<<"v_Time_Scale["<<Time_scale_t<<"] = "<< v_Time_scale[Time_scale_t];
            current_t++;
        }
   }

    //Add the last value
    v_Time_scale[current_t-1]=v_Time_scale[current_t-2]+vv_Interval_info[c_sT_Interval_info_Value][ui->spinBox_nb_intervals->value()];
//    qDebug()<<"v_Time_Scale["<<current_t-1<<"] = "<< v_Time_scale[current_t-1];

/*    for(int t=0;t<ui->spinBox_size_t->value();t++)
        qDebug()<<"v_Time_Scale["<<t<<"] = "<< v_Time_scale[t];
*/
}

//------------------------------------------------------------------------------------
// ----------------------------------  Step all images  ------------------------------
//------------------------------------------------------------------------------------

void m_makro_foci::step_load()
{
    Flag_loaded_image=false;
    QString path_img;

    switch(ui->comboBox_Load_Mode->currentIndex()) {
        case 0:
         {
            path_img = QFileDialog::getOpenFileName(
                        this,
                        tr("Load image - Single Page"),
                        pStore->dir_Load()->path(),
                        tr("Image files (*.png *.jpg *.bmp *.tif *:asc)"));
            if(path_img == 0) return;
            break;
         }
        case 1:
        {
           path_img=QFileDialog::getOpenFileName(
                        this,
                        tr("Load Image - Multi Page"),
                        pStore->dir_Load()->path(),
                        tr("Image files (*.tif)"));
            if(path_img == 0)     return;
            break;
        }
    }

    if(path_img.isEmpty())
        return;

    L_SB_Path->setText(path_img);
    L_SB_Path->setToolTip(path_img);

    FI_Load_File.setFile(path_img);
    pStore->set_dir_Load(path_img);

    switch(ui->comboBox_Load_Mode->currentIndex()) {
    case 0:
        D_Img_Proc::Load_From_Path(
                  &(vvMA_Nuclei[c_ST_N_LOAD][0]),
                  path_img.toStdString());
        break;
    case 1: {
        vector<Mat> vMA_Load;
//        vMA_Load.reserve(Size_image_in_time);                                                             //get enough memory
        imreadmulti(path_img.toStdString(),
                    vMA_Load,
                    IMREAD_ANYDEPTH|IMREAD_ANYCOLOR); //read image pages

        for(int i=0;i<Size_image_in_time;i++){
            if(i+1> vMA_Load.size()){
                QMessageBox msgBox2;
                msgBox2.setText("Either :number total of images too high\n or a greek letter in your path.\n Please change it ");
                msgBox2.exec();
                return;
            }

            if(vMA_Load[i].type()==CV_32FC1){
                QMessageBox msgBox;
                msgBox.setText("Cannot read 32 bits TIFF images \n Please choose another image ");
                msgBox.exec();
                qDebug()<<"Cannot read 32 bits TIFF images";
                return ;
            }

              vvMA_Nuclei[c_ST_N_LOAD][i]=vMA_Load[i];
              vMA_Nuclei[i]=vMA_Load[i];

//              ui->tabWidget->setCurrentIndex(e_TAB_AVERAGE);
//              ui->comboBox_step_av->setCurrentIndex(e_AV_IMG_ORIGINAL);
//              ui->horizontalSlider_Image_in_Time->setValue(i);
          }
          break;
     }
   }

    ui->tabWidget->setTabEnabled(e_TAB_CURVES,false);
    ui->tabWidget->setTabEnabled(e_TAB_SAVE,false);
    ui->tabWidget->setTabToolTip(3,QString("First you need to select background areas"));
    ui->tabWidget->setTabToolTip(4,QString("First you need to select background areas"));

    Flag_loaded_image=true;
    Flag_selected_Bckgd = false;
    Update_View();
}

void m_makro_foci::Convert()
{         
    unsigned int type = CV_8U;
    int min_value=0;
    int max_value=255;
   for(int t=0;t<Size_image_in_time;t++){
        if(ui->checkBox_blur_images->isChecked()){
            int depth = -1;
            bool norm = true;

            ERR(D_Img_Proc::Filter_Box(
                    &vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][t],
                    &vvMA_Nuclei[c_ST_N_LOAD][t],
                    1,
                    1,
                    BORDER_DEFAULT,
                    depth,
                    norm));

            ERR(D_Img_Proc::Normalize(
                        &vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][t],
                        &vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][t],
                        NORM_MINMAX,
                        type,
                        min_value,
                        max_value)
                    );
        }
        else {
            ERR(D_Img_Proc::Normalize(
                            &vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][t],
                            &vvMA_Nuclei[c_ST_N_LOAD][t],
                            NORM_MINMAX,
                            type,
                            min_value,
                            max_value)
                        );
        }

        ERR(D_Img_Proc::GammaSpread(
                &vvMA_Nuclei[c_ST_N_TEMP][t],
                &vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][t],// c_ST_N_INPUT_CONV_16BIT
                ui->doubleSpinBox_gamma->value(),
                0,
                255,
                0,
                255));

        ERR(D_Img_Proc::Normalize(
                &vvMA_Nuclei[c_ST_N_INPUT_CONV_16BIT][t],
                &vvMA_Nuclei[c_ST_N_TEMP][t],
                NORM_MINMAX,
                CV_16U,
                0,
                65535
                ));

        ERR(D_Img_Proc::Normalize(
                &vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][t],
                &vvMA_Nuclei[c_ST_N_TEMP][t],
                NORM_MINMAX,
                type,
                min_value,
                max_value)
            );

        vMA_Nuclei[t]=vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][t];

//                ui->tabWidget->setCurrentIndex(e_TAB_AVERAGE);
//                ui->comboBox_step->setCurrentIndex(e_AV_IMG_BLUR);
//                ui->horizontalSlider_Image_in_Time->setValue(t);

    }
}

void m_makro_foci::Threshold()
{
    int out_mode = CV_THRESH_BINARY;
    double max_val = 255 ;

    int mask_size;
    mask_size = ui->spinBox_03_Mask_size->value();
    double offset;
    offset = ui->spinBox_03_Offset->value();

    for(int t=0;t<Size_image_in_time;t++)
    {
        ERR(D_Img_Proc::Threshold_Adaptive(
                 &vvMA_Nuclei[c_sT_N_THRESHOLD][t],
                 &vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][t],
                out_mode,
                max_val,
                ADAPTIVE_THRESH_GAUSSIAN_C, //ADAPTIVE_THRESH_MEAN_C
                mask_size,
                offset));

//                ui->tabWidget->setCurrentIndex(e_TAB_IMG_PROC);
//                ui->comboBox_step_img_proc->setCurrentIndex(e_IMG_PROC_THRESHOLD);
//                ui->horizontalSlider_Image_in_Time_tab2->setValue(t);
    }

}

void m_makro_foci::Reduction()
{
    int thickness;
    thickness = c_sT_thickness_centroid;

    for(int t=0;t<Size_image_in_time;t++){
        ERR(D_Img_Proc::Reduce_Centroid(
                &vvMA_Nuclei[c_sT_N_REDUCTION][t],
                &vvMA_Nuclei[c_sT_N_THRESHOLD][t],
                thickness));

//      ui->tabWidget->setCurrentIndex(e_TAB_IMG_PROC);
//      ui->comboBox_step_img_proc->setCurrentIndex(e_IMG_PROC_REDUCE);
//      ui->horizontalSlider_Image_in_Time_tab2->setValue(t);
    }

}

void m_makro_foci::Dilatation()
{
    int             morph_type = MORPH_DILATE;
    int             elem_type = MORPH_ELLIPSE;
    unsigned int    size_x      = 3;
    unsigned int    size_y      = 3;
    unsigned int    iterations =1;
    int             border_type =BORDER_CONSTANT;

    for(int t=0;t<Size_image_in_time;t++)
    {
        ERR(D_Img_Proc::Morphology_Elemental(
                &vvMA_Nuclei[c_sT_N_DILATATION_WITHOUT_LABEL][t],
                &vvMA_Nuclei[c_sT_N_REDUCTION][t],
                morph_type,
                elem_type,
                size_x,
                size_y,
                border_type,
                iterations));
    }

}

void m_makro_foci::Finaladd()
{
    for(int t=0;t<Size_image_in_time;t++){
        ERR(D_Img_Proc::Math_ImgImg_BitAnd(
                &vvMA_Nuclei[c_sT_N_FOCI_NO_BKGRD][t],
                &vvMA_Nuclei[c_sT_N_DILATATION_WITHOUT_LABEL][t],
                &vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][t]));
    }
}

void m_makro_foci::Circled_selected_centroid()
{
    qDebug()<<"start Circled_selected_centroid ";

    for(int t=0;t<Size_image_in_time;t++){
       vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][t].copyTo( vvMA_Nuclei[c_sT_N_Label_in_time_CIRCLED_without_labels][t]); //pMA_In->type()
        cv::resize(vvMA_Nuclei[c_sT_N_Label_in_time_CIRCLED_without_labels][t],vvMA_Nuclei[c_sT_N_Label_in_time_CIRCLED_without_labels][t],Size(),2,2,INTER_LINEAR);
        cv::cvtColor(vvMA_Nuclei[c_sT_N_Label_in_time_CIRCLED_without_labels][t],vvMA_Nuclei[c_sT_N_Label_in_time_CIRCLED_without_labels][t],CV_GRAY2BGR); // source, dest

        ERR(draw_circle(&vvMA_Nuclei[c_sT_N_Label_in_time_CIRCLED_without_labels][t],
                    &vvMA_Nuclei[c_sT_N_Label_in_time_CIRCLED_with_labels][t],
                    &vvMA_Nuclei[c_sT_N_CENTROID_SELECTED][t],
                    &vvMA_Nuclei[c_sT_N_CENTROID_SELECTED][t])
            ); //
    }

    qDebug()<<"end Circled_selected_centroid ";
}

int m_makro_foci::draw_circle(Mat *pMA_Out,Mat *pMA_Out2, Mat *pMA_In,Mat *pMA_label)
{
    if(pMA_In->empty())                                         return ER_empty;
    if((pMA_In->channels() != 1) && (pMA_In->channels() != 3))  return ER_channel_bad;

    //Sizes & variables
    int Wi = pMA_In->cols; //image width
    int Hi = pMA_In->rows; //image heigth
    int Yi;                //image position y
    int Xi;                //image position x

    int radius      = (ui->spinBox_radius_circle_intensity->value())*2;
    int color       = 255;
    int thickness   = 1;

    pMA_Out->copyTo(*pMA_Out2);

    for(Yi=0;Yi<Hi;Yi++)
         for(Xi=0; Xi<Wi; Xi++)
            if(pMA_In->at<uchar>(Yi,Xi) !=0 )
            {
                //   D_Img_Proc::Draw_Circle(pMA_Out,Xi*2, Yi*2,radius, color, thickness);

                circle(
                            *pMA_Out,
                            Point(Xi*2,Yi*2),
                            radius,
                            Scalar(color),
                            thickness,
                            LINE_8,
                            0);

                   //   D_Img_Proc::Draw_Text(pMA_Out,QString::number(pMA_label->at<uchar>(Yi,Xi)), Xi*2, Yi*2, thickness, ui->doubleSpinBox_size_font->value(), 200);

                circle(
                            *pMA_Out2,
                            Point(Xi*2,Yi*2),
                            radius,
                            Scalar(color),
                            thickness,
                            LINE_8,
                            0);

                   putText(
                               *pMA_Out2,
                               QString::number(pMA_label->at<uchar>(Yi,Xi)).toStdString(),
                               Point(Xi*2, Yi*2),
                               FONT_HERSHEY_TRIPLEX,
                               ui->doubleSpinBox_size_font->value(),
                               Scalar(0, 0, color),
                               thickness,
                               CV_AA);
            }
    return 0;
}

int m_makro_foci::draw_circle_2(Mat *pMA_Out,Mat *pMA_Out2, Mat *pMA_In,Mat *pMA_label, int t)
{
    if(pMA_In->empty())                                         return ER_empty;
    if((pMA_In->channels() != 1) && (pMA_In->channels() != 3))  return ER_channel_bad;

    //Sizes & variables
    int Wi = pMA_In->cols; //image width
    int Hi = pMA_In->rows; //image heigth
    int Yi;                //image position y
    int Xi;                //image position x

    Wi;
    Hi;

    int radius      = (ui->spinBox_radius_circle_intensity->value())*2;
    int color       = 255;
    int thickness   = 1;

    pMA_Out->copyTo(*pMA_Out2);

    for(int label=1;label<FeatureFoci_nb_label;label++){
        Xi = vvvFeatureFoci[label][t][c_sT_Feature_Foci_coordX];
        Yi = vvvFeatureFoci[label][t][c_sT_Feature_Foci_coordY];

        circle(
                    *pMA_Out,
                    Point(Xi*2,Yi*2),
                    radius,
                    Scalar(color),
                    thickness,
                    LINE_8,
                    0);

        circle(
                    *pMA_Out2,
                    Point(Xi*2,Yi*2),
                    radius,
                    Scalar(color),
                    thickness,
                    LINE_8,
                    0);

        putText(
                    *pMA_Out2,
                    QString::number(pMA_label->at<uchar>(Yi,Xi)).toStdString(),
                    Point(Xi*2, Yi*2),
                    FONT_HERSHEY_TRIPLEX,
                    ui->doubleSpinBox_size_font->value(),
                    Scalar(0, 0, color),
                    thickness,
                    CV_AA);
            }
    return 0;
}

int m_makro_foci::draw_circle(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty())                                         return ER_empty;
    if((pMA_In->channels() != 1) && (pMA_In->channels() != 3))  return ER_channel_bad;

    //Sizes & variables
    int Wi = pMA_In->cols; //image width
    int Hi = pMA_In->rows; //image heigth
    int Yi;                //image position y
    int Xi;                //image position x

    int radius      = ui->spinBox_radius_circle_intensity->value();
    int color = 250;
    int thickness   = 1;

    *pMA_Out = Mat::zeros(pMA_In->size(), pMA_In->type());

    for(Yi=0;Yi<Hi;Yi++)
         for(Xi=0; Xi<Wi; Xi++)
            if(pMA_In->at<uchar>(Yi,Xi) !=0 )
            {
                   D_Img_Proc::Draw_Circle(pMA_Out,Xi, Yi,radius, color, thickness);
            }

    return 0;
}

void m_makro_foci::Update_selected_centroid()
{
    LabelFoci_To_LabelFociSelected.resize(FeatureFoci_nb_label);
   // A mettre a jour a quand des foci ont ete supprimes dans onglet curves
    qDebug()<<"start Update_selected_centroid ";
    for(int t=0;t<Size_image_in_time;t++){
        vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][t].copyTo(vvMA_Nuclei[c_sT_N_CENTROID_SELECTED][t]);
        vvMA_Nuclei[c_sT_N_CENTROID_SELECTED][t]= Scalar(0);
    }

//    qDebug()<<"foci from 1 to "<<FeatureFoci_nb_label;
    for(int foci=1;foci<FeatureFoci_nb_label;foci++)
        for (int t=0;t<Size_image_in_time;t++)
            if(vvvFeatureFoci[foci][t][c_sT_Feature_Foci_selected] /*==true*/){     //D: == true is not needed
 //               qDebug()<<"("<<vvvFeatureFoci[foci][t][c_sT_Feature_Foci_coordY]<<","<<vvvFeatureFoci[foci][t][c_sT_Feature_Foci_coordX]<<") = 255";
                vvMA_Nuclei[c_sT_N_CENTROID_SELECTED][t].at<uchar>(
                            vvvFeatureFoci[foci][t][c_sT_Feature_Foci_coordY],
                            vvvFeatureFoci[foci][t][c_sT_Feature_Foci_coordX])
                        = LabelFoci_To_LabelFociSelected[foci] ; //foci;
            }
    qDebug()<<"end Update_selected_centroid ";
}

//------------------------------------------------------------------------------------
// ----------------------------------  Step average image  ---------------------------
//------------------------------------------------------------------------------------

void m_makro_foci::step_average()
{
    //AVERAGE

    if (ui->comboBox_Load_Mode->currentIndex()==c_ST_single_page){
        vMA_Nuclei[0].copyTo(vMA_Average[c_sT_Max_Proj]);
        vMA_Nuclei[0].copyTo(MA_Average_area);
    }
        else{
        // AVERAGE
//            ERR(Image_average(vMA_Nuclei,&vMA_Average[c_sT_Max_Proj]));
        // MAXIMUM INTENSITY
            ERR(Image_proj_max_intensity(vMA_Nuclei,&vMA_Average[c_sT_Max_Proj]));
            ERR(Image_proj_max_intensity_t_positif(vMA_Nuclei,&vMA_Average[c_sT_Max_Proj_T_positives]));
        }

    Init_add_focus_user();

    ui->tabWidget->setCurrentIndex(e_TAB_AVERAGE);
    ui->comboBox_step_av->setCurrentIndex(e_AV_IMG_AVERAGE_IMAGE);
}

int m_makro_foci::Image_average(vector<Mat> vMA_In, Mat *pMA_Out)
{

    if(vMA_In.empty()) return ER_empty;

        Mat Average(vMA_In[0].rows, vMA_In[0].cols, CV_64F);
        Average.setTo(Scalar(0,0,0,0));

        Mat temp(vMA_In[0].rows, vMA_In[0].cols, CV_64F);

        for(unsigned int t=0;t<vMA_In.size();t++)
        {
            vMA_In[t].convertTo(temp,CV_64F);
            D_Img_Proc::Math_ImgImg_Add(&Average,&Average,&temp);
        }

        D_Img_Proc::Math_ImgScal_Div(&Average,&Average,vMA_In.size());

        D_Img_Proc::Normalize(
                            pMA_Out,
                            &Average,
                            NORM_MINMAX,
                            CV_8U,
                            0,
                            255);

        MA_Average_area = pMA_Out->clone();

        ui->tabWidget->setCurrentIndex(e_TAB_AVERAGE);
        ui->comboBox_step_av->setCurrentIndex(e_AV_IMG_AVERAGE_IMAGE);
    return 0;
}

int m_makro_foci::Image_proj_max_intensity(vector<Mat> vMA_In, Mat *pMA_Out)
{
    if(vMA_In.empty()) return ER_empty;

    *pMA_Out=vMA_In[0].clone();
    *pMA_Out=Scalar(0);

    for(int Yi=0;Yi<vMA_In[0].rows;Yi++)
        for(int Xi=0;Xi<vMA_In[0].cols;Xi++)
            for(unsigned int t=0;t<vMA_In.size();t++)
            {
                if (vMA_In[t].at<uchar>(Yi,Xi)>pMA_Out->at<uchar>(Yi,Xi))
                    pMA_Out->at<uchar>(Yi,Xi)= vMA_In[t].at<uchar>(Yi,Xi);
            }


        MA_Average_area = pMA_Out->clone();

        ui->tabWidget->setCurrentIndex(e_TAB_AVERAGE);
        ui->comboBox_step_av->setCurrentIndex(e_AV_IMG_AVERAGE_IMAGE);
    return 0;
}

int m_makro_foci::Image_proj_max_intensity_t_positif(vector<Mat> vMA_In, Mat *pMA_Out)
{
    if(vMA_In.empty()) return ER_empty;

    *pMA_Out=vMA_In[0].clone();
    *pMA_Out=Scalar(0);

    for(int Yi=0;Yi<vMA_In[0].rows;Yi++)
        for(int Xi=0;Xi<vMA_In[0].cols;Xi++)
            for(unsigned int t=0;t<vMA_In.size();t++)
            {
                if (v_Time_scale[t]>0)
                    if (vMA_In[t].at<uchar>(Yi,Xi)>pMA_Out->at<uchar>(Yi,Xi))
                        pMA_Out->at<uchar>(Yi,Xi)= vMA_In[t].at<uchar>(Yi,Xi);
            }

    return 0;
}

void m_makro_foci::Threshold_av()
{
    int out_mode = CV_THRESH_BINARY;
    double max_val = 255 ;

    int mask_size;
    mask_size = ui->spinBox_03_Mask_size->value();
    double offset;
    offset = ui->spinBox_03_Offset->value();


    ERR(D_Img_Proc::Threshold_Adaptive(
            &vMA_Average[c_sT_Max_Proj_Threshold],
            &vMA_Average[c_sT_Max_Proj],
            out_mode,
            max_val,
            ADAPTIVE_THRESH_MEAN_C,
            mask_size,
            offset));

//    ui->tabWidget->setCurrentIndex(e_TAB_AVERAGE);
//    ui->comboBox_step_av->setCurrentIndex(e_AV_IMG_THRESHOLD);
}

void m_makro_foci::Reduction_av()
{
    int thickness;
    thickness = 1;

    ERR(D_Img_Proc::Reduce_Centroid(
            &vMA_Average[c_sT_Max_Proj_Reducted],
            &vMA_Average[c_sT_Max_Proj_Threshold],
            thickness));

//    ui->tabWidget->setCurrentIndex(e_TAB_AVERAGE);
//    ui->comboBox_step_av->setCurrentIndex(e_AV_IMG_REDUCE_CENTROID);
}

void m_makro_foci::Watershed_av()
{
/*    unsigned int type = CV_8U;
    unsigned int depth_min = 0;
    unsigned int depth_max = 255;

    ERR(D_Img_Proc::Transformation_Watershed_Auto(
            &vMA_Average[c_sT_Max_Proj_Watershed],           // dest
            &vMA_temp[0],          // source 1
            &vMA_Average[c_sT_Max_Proj_Reducted],           // source 2 marker
            true,
            false,
            false));

    ERR(D_Img_Proc::Normalize(
            &vMA_Average[c_sT_Max_Proj_Watershed],
            &vMA_Average[c_sT_Max_Proj_Watershed],
            NORM_MINMAX,
            type,
            depth_min,
            depth_max));
*/
//    ui->tabWidget->setCurrentIndex(e_TAB_AVERAGE);
//    ui->comboBox_step_av->setCurrentIndex(e_AV_IMG_LABEL_MASK);

 }

//------------------------------------------------------------------------------------
// ----------------------------------  Feature Foci ----------------------------------
//------------------------------------------------------------------------------------

void m_makro_foci::Feature_Foci()
{
    qDebug()<<"START Feature_Foci";
    int Wi = vvMA_Nuclei[c_ST_N_LOAD][0].cols; //image width
    int Hi = vvMA_Nuclei[c_ST_N_LOAD][0].rows; //image heigth
    int Yi;                //image position y
    int Xi;                //image position x

    // Calulation of the average intensity of each foci
    // Through the Feature_Foci array

    //RESET the following parameters: nb_pixel, intensity & intensity norm, selected

    for(int t=0;t<Size_image_in_time;t++){
        for(int label = 0; label < FeatureFoci_nb_label; label++){
            vvvFeatureFoci[label][t][c_ST_Feature_Foci_Nb_pixels]       =0;
            vvvFeatureFoci[label][t][c_ST_Feature_Foci_Intensity]       =0;
            vvvFeatureFoci[label][t][c_ST_Feature_Foci_Intensity_norm]  =0;
            vvvFeatureFoci[label][t][c_sT_Feature_Foci_selected]        =true;
        }
    }
/*
    Mat Temp_image;
    Temp_image = Mat(vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][0].size(),CV_16U, Scalar(0)); //vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][0].type()

    for(int t=0;t<Size_image_in_time;t++){
        for(int current_label = 1; current_label < FeatureFoci_nb_label; current_label ++){
            Temp_image = Scalar(c_sT_Value_bckgd_foci_labeled);
            D_Img_Proc::Draw_Circle
                    (&Temp_image,
                     vvvFeatureFoci[current_label][t][c_sT_Feature_Foci_coordX],
                     vvvFeatureFoci[current_label][t][c_sT_Feature_Foci_coordY],
                     ui->spinBox_radius_circle_intensity->value(), //c_sT_radius_circle
                     current_label,
                     FILLED);
            switch (vvMA_Nuclei[c_ST_N_LOAD][t].type()) {
            case CV_8U:
            {
                for(Yi=0;Yi<Hi;Yi++)
                     for(Xi=0; Xi<Wi; Xi++)
                        if( Temp_image.at<ushort>(Yi,Xi) == current_label){ //if there is a label
                            vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Nb_pixels]=
                                     vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Nb_pixels]+1;

                                vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Intensity] = vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Intensity] + (vvMA_Nuclei[c_ST_N_LOAD][t].at<uchar>(Yi,Xi)) ;
                            }
            }
                break;
            case CV_16U:
            {
                for(Yi=0;Yi<Hi;Yi++)
                     for(Xi=0; Xi<Wi; Xi++)
                        if( Temp_image.at<ushort>(Yi,Xi) == current_label){ //if there is a label
                            vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Nb_pixels]=
                                     vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Nb_pixels]+1;

                                vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Intensity] = vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Intensity] + (vvMA_Nuclei[c_ST_N_LOAD][t].at<ushort>(Yi,Xi)) ;

                            }
            }
                break;


            }


            if (vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Nb_pixels] > 1)
                 vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Intensity]=vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Intensity]/vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Nb_pixels];
        }
    }

*/

    int focus_x;
    int focus_y;
    float dist;
    int radius = ui->spinBox_radius_circle_intensity->value();
    switch (vvMA_Nuclei[c_ST_N_LOAD][0].type()) {
    case CV_8U:
    {
        for(int t=0;t<Size_image_in_time;t++){

            for(int current_label = 1; current_label < FeatureFoci_nb_label; current_label ++){
                focus_x=vvvFeatureFoci[current_label][t][c_sT_Feature_Foci_coordX];
                focus_y=vvvFeatureFoci[current_label][t][c_sT_Feature_Foci_coordY];

                for(Yi=focus_y-radius;Yi<Hi && Yi>=0 && Yi<(focus_y+radius);Yi++)
                    for(Xi=focus_x-radius; Xi<Wi && Xi>=0 && Xi<(focus_x+radius) ; Xi++){
                        dist = (focus_y-Yi)*(focus_y-Yi) + (focus_x-Xi)*(focus_x-Xi);
                            if(dist<(radius*radius)){
                                if (vvMA_Nuclei[c_ST_N_Convex_hull][t].at<uchar>(Yi,Xi)==255){
                                vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Nb_pixels]=
                                        vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Nb_pixels]+1;

                                vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Intensity] =
                                        vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Intensity] + (vvMA_Nuclei[c_ST_N_LOAD][t].at<uchar>(Yi,Xi)) ;

                                }
                            }
                        }

                if (vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Nb_pixels] > 1)
                    vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Intensity]=
                            vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Intensity]/vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Nb_pixels];
            }
        }

    }

    break;
    case CV_16U:
    {
        for(int t=0;t<Size_image_in_time;t++){

            for(int current_label = 1; current_label < FeatureFoci_nb_label; current_label ++){
                focus_x=vvvFeatureFoci[current_label][t][c_sT_Feature_Foci_coordX];
                focus_y=vvvFeatureFoci[current_label][t][c_sT_Feature_Foci_coordY];

                for(Yi=focus_y-radius;Yi<Hi && Yi>=0 && Yi<(focus_y+radius);Yi++)
                    for(Xi=focus_x-radius; Xi<Wi && Xi>=0 && Xi<(focus_x+radius) ; Xi++){
                        dist = (focus_y-Yi)*(focus_y-Yi) + (focus_x-Xi)*(focus_x-Xi);
                                if(dist<(radius*radius)){
                                    if (vvMA_Nuclei[c_ST_N_Convex_hull][t].at<ushort>(Yi,Xi)==255){
                                        vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Nb_pixels]=
                                                vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Nb_pixels]+1;

                                        vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Intensity] =
                                                vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Intensity] + (vvMA_Nuclei[c_ST_N_LOAD][t].at<ushort>(Yi,Xi)) ;
                                }
                            }
                        }

                if (vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Nb_pixels] > 1)
                    vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Intensity]=
                            vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Intensity]/vvvFeatureFoci[current_label][t][c_ST_Feature_Foci_Nb_pixels];
            }
        }

    }
    break;
    }
}

void m_makro_foci::Interpolation_Feature_Foci()
{
    qDebug()<<"Beginning of interpolation";
    vector<int> TabIndex;
    TabIndex.resize(Size_image_in_time);
    int index=0, t_temp, t_temp_max, t_temp_min;
    bool Next_assigned_found,Previous_assigned_found ;

    for(int label=1;label<FeatureFoci_nb_label;label++){
        index=0;
//        qDebug()<<"/n label : "<<label;
        for(int t=0;t<Size_image_in_time;t++){
            t_temp=t;
//            t_temp_max=t;
//            t_temp_min=t;
            Next_assigned_found = false;
            Previous_assigned_found = false;
//            qDebug()<<" t= "<<t;

            // ------------------- UNASSIGNED STATE -------------
            if(static_cast<int>(vvvFeatureFoci[label][t][c_sT_Feature_Foci_state])==c_sT_state_unassigned){
                while(
                      (static_cast<int>(vvvFeatureFoci[label][t_temp][c_sT_Feature_Foci_state]==c_sT_state_unassigned)||(vvvFeatureFoci[label][t_temp][c_sT_Feature_Foci_state]==c_sT_state_interpolated))
                       && t_temp<Size_image_in_time-1){//---<!><!><!<!>----------------------------------------------------------------
                    t_temp++;
                }
                t_temp_max = t_temp;

                if (static_cast<int>(vvvFeatureFoci[label][t_temp_max][c_sT_Feature_Foci_state])==c_sT_state_assigned)
                    Next_assigned_found = true;
            }
            if(Next_assigned_found){ // if there is a next one --> assign the next coordinates
                for(int t_unassigned=t; t_unassigned < t_temp_max; t_unassigned++){
                    vvvFeatureFoci[label][t_unassigned][c_sT_Feature_Foci_state]=c_sT_state_interpolated; //---<!><!><!<!>----------------------------------------------------------------
                    vvvFeatureFoci[label][t_unassigned][c_sT_Feature_Foci_coordX]= vvvFeatureFoci[label][t_temp_max][c_sT_Feature_Foci_coordX];
                    vvvFeatureFoci[label][t_unassigned][c_sT_Feature_Foci_coordY]= vvvFeatureFoci[label][t_temp_max][c_sT_Feature_Foci_coordY];
//                    vvMA_Nuclei[c_sT_N_Label_in_time][t_unassigned].at<ushort>(vvvFeatureFoci[label][t_unassigned][c_sT_Feature_Foci_coordY],vvvFeatureFoci[label][t_unassigned][c_sT_Feature_Foci_coordX])=label;

                }

            }
            else { // if there is no next one --> assign the last coordinates
                while(static_cast<int>(vvvFeatureFoci[label][t_temp][c_sT_Feature_Foci_state])==c_sT_state_unassigned && t_temp>1){
                    t_temp--;
                }
                t_temp_min = t_temp;
                if ((static_cast<int>(vvvFeatureFoci[label][t_temp_min][c_sT_Feature_Foci_state])==c_sT_state_assigned)
                        ||(static_cast<int>(vvvFeatureFoci[label][t_temp][c_sT_Feature_Foci_state])==c_sT_state_interpolated))
                    Previous_assigned_found = true;
            }

            if(Previous_assigned_found){ // if there is a previous one --> assign the  coordinates
                for(int t_unassigned=t; t_unassigned > t_temp_min; t_unassigned--){
                    vvvFeatureFoci[label][t_unassigned][c_sT_Feature_Foci_state]=c_sT_state_interpolated;
                    vvvFeatureFoci[label][t_unassigned][c_sT_Feature_Foci_coordX]= vvvFeatureFoci[label][t_temp_min][c_sT_Feature_Foci_coordX];
                    vvvFeatureFoci[label][t_unassigned][c_sT_Feature_Foci_coordY]= vvvFeatureFoci[label][t_temp_min][c_sT_Feature_Foci_coordY];
//                    vvMA_Nuclei[c_sT_N_Label_in_time][t_unassigned].at<ushort>(vvvFeatureFoci[label][t_unassigned][c_sT_Feature_Foci_coordY],vvvFeatureFoci[label][t_unassigned][c_sT_Feature_Foci_coordX])=label;

                }

            }
            t_temp=t;
            Next_assigned_found = false;

            // ------------------- LOST STATE --------------------------
            if(static_cast<int>(vvvFeatureFoci[label][t][c_sT_Feature_Foci_state])==c_sT_state_lost){
//                qDebug()<<"need to be maj";
                while(static_cast<int>(vvvFeatureFoci[label][t_temp][c_sT_Feature_Foci_state])==c_sT_state_lost
                      && (t_temp-t)<c_ST_interval_time && t_temp<(Size_image_in_time-1)){
                    t_temp++;
                }
                t_temp_max = t_temp;
                if ((static_cast<int>(vvvFeatureFoci[label][t_temp_max][c_sT_Feature_Foci_state])==c_sT_state_assigned)
                        ||(static_cast<int>(vvvFeatureFoci[label][t_temp_max][c_sT_Feature_Foci_state])==c_sT_state_interpolated))
                    Next_assigned_found = true;

                t_temp=t;

                if(Next_assigned_found){
                      while(t_temp<t_temp_max){
                            vvvFeatureFoci[label][t_temp][c_sT_Feature_Foci_state]=c_sT_state_interpolated;
                            vvvFeatureFoci[label][t_temp][c_sT_Feature_Foci_coordX]=
                                     (vvvFeatureFoci[label][t-1][c_sT_Feature_Foci_coordX]+ vvvFeatureFoci[label][t_temp_max][c_sT_Feature_Foci_coordX])/2.;
                            vvvFeatureFoci[label][t_temp][c_sT_Feature_Foci_coordY]=
                                      (vvvFeatureFoci[label][t-1][c_sT_Feature_Foci_coordY]+ vvvFeatureFoci[label][t_temp_max][c_sT_Feature_Foci_coordY])/2.;

                            vvMA_Nuclei[c_sT_N_Label_in_time][t_temp].at<ushort>(vvvFeatureFoci[label][t_temp][c_sT_Feature_Foci_coordY],vvvFeatureFoci[label][t_temp][c_sT_Feature_Foci_coordX])=label;
//                            qDebug()<<"maj de image c_sT_N_Label_in_time ("<<vvvFeatureFoci[label][t_temp][c_sT_Feature_Foci_coordY]<<" , "<<vvvFeatureFoci[label][t_temp][c_sT_Feature_Foci_coordX]<< " = "<<label;
                            t_temp++;
                    }
                }
                else {
                    for(int t_unassigned = t ; t_unassigned < Size_image_in_time; t_unassigned ++ ){

                        vvvFeatureFoci[label][t_unassigned][c_sT_Feature_Foci_state]=c_sT_state_interpolated;
                        vvvFeatureFoci[label][t_unassigned][c_sT_Feature_Foci_coordX]=vvvFeatureFoci[label][t-1][c_sT_Feature_Foci_coordX];
                        vvvFeatureFoci[label][t_unassigned][c_sT_Feature_Foci_coordY]=vvvFeatureFoci[label][t-1][c_sT_Feature_Foci_coordY];

//                        vvMA_Nuclei[c_sT_N_Label_in_time][t_unassigned].at<ushort>(vvvFeatureFoci[label][t_unassigned][c_sT_Feature_Foci_coordY],vvvFeatureFoci[label][t_unassigned][c_sT_Feature_Foci_coordX])=label;
                    }
                }
            }

        }
    }


    Sort_label();

    for(int t=0;t<Size_image_in_time;t++)
        for(int feature =0; feature <c_sT_Feature_Foci;feature++){
            vvvFeatureFoci[0][t][feature]=0;
            vvvFeatureFoci[0][t][c_sT_Feature_Foci_selected]=true;
        }

//    Update_selected_Foci_array();

    qDebug()<<"     End Interpolation FeatureFoci ";
}

void m_makro_foci::Sort_label()
{
    // Sort the foci by position
    int time_0 =0; // sorted only on the first image !
    int Wi = vvMA_Nuclei[c_ST_N_LOAD][0].cols; //image width

    int position,position_next;
    for(int label=1;label<FeatureFoci_nb_label;label++){ //FeatureFoci_nb_label
        position = vvvFeatureFoci[label][time_0][c_sT_Feature_Foci_coordY]*Wi+vvvFeatureFoci[label][time_0][c_sT_Feature_Foci_coordX];
//        qDebug()<<"label ="<<label;
//        qDebug()<<"X ="<<vvvFeatureFoci[label][time_0][c_sT_Feature_Foci_coordX]<<" Y= "<<vvvFeatureFoci[label][time_0][c_sT_Feature_Foci_coordY] ;
//        qDebug()<<"position premier label ="<<position;
        for(int label_next=label+1;label_next<FeatureFoci_nb_label;label_next++){
//            qDebug()<<"label_next ="<<label_next;
//            qDebug()<<"X ="<<vvvFeatureFoci[label_next][time_0][c_sT_Feature_Foci_coordX]<<" Y= "<<vvvFeatureFoci[label_next][time][c_sT_Feature_Foci_coordY] ;
            position_next = vvvFeatureFoci[label_next][time_0][c_sT_Feature_Foci_coordY]*Wi+vvvFeatureFoci[label_next][time_0][c_sT_Feature_Foci_coordX];
//            qDebug()<<"position 2eme label ="<<position_next;
            if (position_next<position){
//                qDebug()<<"Maj foci position";
                for(int t=0;t<Size_image_in_time;t++){
                    Swap_foci_to_sort_label(label,0,t);
                    Swap_foci_to_sort_label(label_next,label,t);
                    Swap_foci_to_sort_label(0,label_next, t);
                }
                position = vvvFeatureFoci[label][time_0][c_sT_Feature_Foci_coordY]*Wi+vvvFeatureFoci[label][time_0][c_sT_Feature_Foci_coordX];

//                qDebug()<<"For label = "<< label;
//                qDebug()<<"Now X= "<<vvvFeatureFoci[label][time_0][c_sT_Feature_Foci_coordX]<<" and  Y= "<<vvvFeatureFoci[label][time][c_sT_Feature_Foci_coordY] ;

//                qDebug()<<"For label_next = "<< label_next;
//                qDebug()<<"Now X= "<<vvvFeatureFoci[label_next][time_0][c_sT_Feature_Foci_coordX]<<" and  Y= "<<vvvFeatureFoci[label_next][time][c_sT_Feature_Foci_coordY] ;

          }
        }
    }
}

void m_makro_foci::Swap_foci_to_sort_label(int labelIn, int labelOut, int t)
{
    vvvFeatureFoci[labelOut][t][c_sT_Feature_Foci_label]=
            vvvFeatureFoci[labelIn][t][c_sT_Feature_Foci_label];
    vvvFeatureFoci[labelOut][t][c_sT_Feature_Foci_coordX]=
            vvvFeatureFoci[labelIn][t][c_sT_Feature_Foci_coordX];
    vvvFeatureFoci[labelOut][t][c_sT_Feature_Foci_coordY]=
            vvvFeatureFoci[labelIn][t][c_sT_Feature_Foci_coordY];
    vvvFeatureFoci[labelOut][t][c_ST_Feature_Foci_Nb_pixels]=
            vvvFeatureFoci[labelIn][t][c_ST_Feature_Foci_Nb_pixels];
    vvvFeatureFoci[labelOut][t][c_ST_Feature_Foci_Intensity]=
            vvvFeatureFoci[labelIn][t][c_ST_Feature_Foci_Intensity];
    vvvFeatureFoci[labelOut][t][c_ST_Feature_Foci_Intensity_norm]=
            vvvFeatureFoci[labelIn][t][c_ST_Feature_Foci_Intensity_norm];
    vvvFeatureFoci[labelOut][t][c_sT_Feature_Foci_state]=
            vvvFeatureFoci[labelIn][t][c_sT_Feature_Foci_state];
    vvvFeatureFoci[labelOut][t][c_sT_Feature_Foci_selected]=
            vvvFeatureFoci[labelIn][t][c_sT_Feature_Foci_selected];
}

void m_makro_foci::Normalization_Feature_Foci()
{
//    qDebug()<<"Norm 1";
    for (int label=1;label<FeatureFoci_nb_label;label++){
      for(int t=0;t<vvvFeatureFoci[label].size();t++){
          vvvFeatureFoci[label][t][c_ST_Feature_Foci_Intensity_norm]=
                  (vvvFeatureFoci[label][t][c_ST_Feature_Foci_Intensity]-Bckgd_out_nuclei[t])
                  /(Bckgd_in_nuclei[t]-Bckgd_out_nuclei[t]);
      }
    }

//    qDebug()<<"Norm 2";
    (v_labels).resize(FeatureFoci_nb_label);
    (vv_intensity).resize(FeatureFoci_nb_label);
    (v_temps).resize(Size_image_in_time);//----

//    qDebug()<<"Norm 3";
    for(int label=0; label<FeatureFoci_nb_label;label++){
        vv_intensity[label].resize(Size_image_in_time);//-----

    }

//    qDebug()<<"Norm 4";
    for (int label=1;label<FeatureFoci_nb_label;label++){
        for(int t=0;t<Size_image_in_time;t++){
            v_temps[t]=v_Time_scale[t];
            vv_intensity[label][t]=vvvFeatureFoci[label][t][c_ST_Feature_Foci_Intensity_norm];
        }
    }

}

void m_makro_foci::Get_Average_Feature_Foci()
{
    // -------- Resize of array of feature vvFeatureFoci_Average
   vvFeatureFoci_Average.resize(FeatureFoci_nb_label);
    for(unsigned int lab = 0; lab <vvFeatureFoci_Average.size(); lab++){
        vvFeatureFoci_Average[lab].resize(c_sT_Feature_Foci_Average);
        for(unsigned int feature =0;feature <c_sT_Feature_Foci_Average; feature++)
            vvFeatureFoci_Average[lab][feature] = 0;
    }

    vector<double> vIntensity_label_temp;
    vIntensity_label_temp.resize(Size_image_in_time);

   resize_array(&vvvv_stat_intensity,c_nb_Array_intensity,FeatureFoci_nb_label,Size_image_in_time);

   for(int array=0;array<c_nb_Array_intensity;array++){
       for (int label=1;label<FeatureFoci_nb_label;label++){
           for(int t=0;t<Size_image_in_time;t++){
               switch(array){
               case 0:
               vIntensity_label_temp[t]=vv_intensity[label][t];
                   break;
               case 1:
               vIntensity_label_temp[t]=vv_intensity_filtered[label][t];
                   break;
               case 2:
               vIntensity_label_temp[t]=vv_intensity_filter_1st_deriv[label][t];
                   break;
               case 3:
               vIntensity_label_temp[t]=vv_intensity_filter_2nd_deriv[label][t];
                   break;
               }
            }

       D_Stat::Calc_Stats(&vvvv_stat_intensity[array][label], vIntensity_label_temp,1);
       }
   }


    if(FeatureFoci_nb_label==1){
        IntensityMin=0;
        IntensityMax=0;
        return;
    }

   //init values
   IntensityMin=vvvv_stat_intensity[c_sT_Array_intensity_normalized][1][c_STAT_MINIMUM];
//   Intensity_filter_Min=vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][1][c_STAT_MINIMUM];
   IntensityMax=vvvv_stat_intensity[c_sT_Array_intensity_normalized][1][c_STAT_MAXIMUM];
 //  Intensity_filter_Max=vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][1][c_STAT_MAXIMUM];


   for(int label=1;label<FeatureFoci_nb_label;label++)
   {
/*       qDebug()<<"label "<<label;
       qDebug()<<"          "<<vvvv_stat_intensity[c_sT_Array_intensity_normalized][label][c_STAT_MINIMUM];
       qDebug()<<"          "<<vvvv_stat_intensity[c_sT_Array_intensity_normalized][label][c_STAT_MAXIMUM];
*/
       if (vvvv_stat_intensity[c_sT_Array_intensity_normalized][label][c_STAT_MINIMUM]<IntensityMin)
           IntensityMin=vvvv_stat_intensity[c_sT_Array_intensity_normalized][label][c_STAT_MINIMUM];

//       if (vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][label][c_STAT_MINIMUM]<Intensity_filter_Min)
 //          Intensity_filter_Min=vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][label][c_STAT_MINIMUM];

       if (vvvv_stat_intensity[c_sT_Array_intensity_normalized][label][c_STAT_MAXIMUM]>IntensityMax)
           IntensityMax=vvvv_stat_intensity[c_sT_Array_intensity_normalized][label][c_STAT_MAXIMUM];

//       if (vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][label][c_STAT_MAXIMUM]>Intensity_filter_Max)
 //          Intensity_filter_Max=vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][label][c_STAT_MAXIMUM];

   }
}


//----------------------------Select pertinent foci-----------------------------------

void m_makro_foci::Select_pertinent_Foci()
{
    for(int label=1; label<FeatureFoci_nb_label;label++)
        for(int t=0;t<Size_image_in_time;t++)
             vvvFeatureFoci[label][t][c_sT_Feature_Foci_selected]=true;

    Select_pertinent_Foci_Std_dev();

    Select_pertinent_Foci_first_images();
    if (ui->checkBox_selection_not_enough_time->isChecked())
        Unselect_occasional_detected_foci();
    if (ui->checkBox_selection_foci_decreasing_curves->isChecked())
        Unselect_decreasing_curves();
    if (ui->checkBox_selection_foci_too_close->isChecked())
        Select_pertinent_Foci_to_unify();

    // Re select added foci by user
    int label_focus_added;
    for(int label =0; label <nb_Foci_added_by_user; label++){
        label_focus_added=vFoci_added[label];
        qDebug()<<"label reselected = "<<label_focus_added;
        for(int t=0;t<Size_image_in_time;t++){
            vvvFeatureFoci[label_focus_added][t][c_sT_Feature_Foci_selected]=true;
        }
    }

    Update_selected_Foci_array();
    Update_Curves();
}

void m_makro_foci::Select_pertinent_Foci_Std_dev()
{
    if (ui->comboBox_Load_Mode->currentIndex()==c_ST_single_page)
        return;

    float diff_Intensity_Max_Min;
    FeatureFoci_nb_label_selected =1;
    for(int label =1; label <FeatureFoci_nb_label; label++){
        diff_Intensity_Max_Min=vvFeatureFoci_Average[label][c_sT_Feature_Foci_Average_max_value]-vvFeatureFoci_Average[label][c_sT_Feature_Foci_Average_min_value];
        if( vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][label][c_STAT_STAN_DEV_TOTAL] >ui->doubleSpinBox_Select_pertinent_Foci_Std_dev->value()) //BEFORE:  (0.20*diff_Intensity_Max_Min)   ui->doubleSpinBox_choice_Variance->value()
            //vvFeatureFoci_Average[label][c_sT_Feature_Foci_Average_variance]
            FeatureFoci_nb_label_selected++;
    }


    resize_array(&vvvFeatureFoci_selected,FeatureFoci_nb_label_selected,Size_image_in_time,c_sT_Feature_Foci);

    for(int label =1; label <FeatureFoci_nb_label; label++){
        diff_Intensity_Max_Min=vvFeatureFoci_Average[label][c_sT_Feature_Foci_Average_max_value]-vvFeatureFoci_Average[label][c_sT_Feature_Foci_Average_min_value];

        if(vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][label][c_STAT_STAN_DEV_TOTAL]<ui->doubleSpinBox_Select_pertinent_Foci_Std_dev->value()){//(0.20*diff_Intensity_Max_Min)      //vvFeatureFoci_Average[label][c_sT_Feature_Foci_Average_variance]
            qDebug()<<"label "<<label<<" has a too low variance";
            for(int t=0;t<Size_image_in_time;t++){
                vvvFeatureFoci[label][t][c_sT_Feature_Foci_selected]=false;
            }
        }
        else {
            for(int t=0;t<Size_image_in_time;t++)
                vvvFeatureFoci[label][t][c_sT_Feature_Foci_selected]=true;
        }
    }
}

void m_makro_foci::Select_pertinent_Foci_to_unify()
{
    double distance_sq;
    int cpt=0;
    int Minimum_average_dist = ui->spinBox_radius_circle_intensity->value()*1.5;
    for(int label=1;label<FeatureFoci_nb_label;label++){

        for(int label_bis=label+1;label_bis<FeatureFoci_nb_label;label_bis++){
            //eventuellement rajouter une condition sur seleted == true
            distance_sq = 0;
            cpt=0;
            for(int t=0;t<Size_image_in_time;t++){
                if(vvvFeatureFoci[label][t][c_sT_Feature_Foci_state]==c_sT_state_assigned || vvvFeatureFoci[label_bis][t][c_sT_Feature_Foci_state]==c_sT_state_assigned)
                {
                    cpt++;
                    distance_sq+=sqrt(
                             (vvvFeatureFoci[label][t][c_sT_Feature_Foci_coordX]-vvvFeatureFoci[label_bis][t][c_sT_Feature_Foci_coordX])
                            *(vvvFeatureFoci[label][t][c_sT_Feature_Foci_coordX]-vvvFeatureFoci[label_bis][t][c_sT_Feature_Foci_coordX])
                            +(vvvFeatureFoci[label][t][c_sT_Feature_Foci_coordY]-vvvFeatureFoci[label_bis][t][c_sT_Feature_Foci_coordY])
                            *(vvvFeatureFoci[label][t][c_sT_Feature_Foci_coordY]-vvvFeatureFoci[label_bis][t][c_sT_Feature_Foci_coordY])
                                );
                }
            }
            distance_sq /= cpt;
            if (distance_sq < Minimum_average_dist){
                qDebug()<<"Label "<<label<<"et label "<<label_bis<<" are too close ";
                // We take the label with the highest std dev
                if ((static_cast<bool>(vvvFeatureFoci[label][0][c_sT_Feature_Foci_selected])==true) && (static_cast<bool>(vvvFeatureFoci[label_bis][0][c_sT_Feature_Foci_selected])==true)){                //casted double->bool to avoid message telling to not compare bool and double
                        if(vvvv_stat_intensity[c_sT_Array_intensity_normalized][label][c_STAT_MEAN_ARITMETIC]>vvvv_stat_intensity[c_sT_Array_intensity_normalized][label_bis][c_STAT_MEAN_ARITMETIC]){
                            for(int t=0;t<Size_image_in_time;t++){
                                vvvFeatureFoci[label_bis][t][c_sT_Feature_Foci_selected]=false;
                            }
                          qDebug()<<"Label "<<label<<" chose ";
                         }
                         else {
                            for(int t=0;t<Size_image_in_time;t++){
                                vvvFeatureFoci[label][t][c_sT_Feature_Foci_selected]=false;
                            }
                            qDebug()<<"Label "<<label_bis <<" chose ";
                         }
                }
            }
        }
    }
}

void m_makro_foci::Select_pertinent_Foci_first_images()
{
    qDebug()<<"Select_pertinent_Foci_first_images";
    if (ui->comboBox_Load_Mode->currentIndex()==c_ST_single_page)
        return;

    float Average_intensity_3_first_images=0, Average_intensity_background_nuclei_3_first_images=0;
    for(int label=1;label<FeatureFoci_nb_label;label++){
    Average_intensity_3_first_images =
            vvvFeatureFoci[label][0][c_ST_Feature_Foci_Intensity]+
            vvvFeatureFoci[label][1][c_ST_Feature_Foci_Intensity]+
            vvvFeatureFoci[label][2][c_ST_Feature_Foci_Intensity];
    Average_intensity_3_first_images/=3;
    Average_intensity_background_nuclei_3_first_images =
            (Bckgd_in_nuclei[0]+Bckgd_in_nuclei[1]+Bckgd_in_nuclei[2])/3;
        if(Average_intensity_3_first_images>1.5*Average_intensity_background_nuclei_3_first_images){ // 2*normalized backgroung in the nucleus
            for(int t=0;t<Size_image_in_time;t++)
                vvvFeatureFoci[label][t][c_sT_Feature_Foci_selected]=false;
        qDebug()<<"Label "<<label<<"deleted because already there at the first images";

        }
    }
}

void m_makro_foci::Unselect_occasional_detected_foci()
{
    int count=0;
    for(int label=1;label<FeatureFoci_nb_label;label++){
        count =0;
        for(int t=0;t<Size_image_in_time;t++){
            if (vvvFeatureFoci[label][t][c_sT_Feature_Foci_state] == c_sT_state_assigned)
                count ++;
        }
        if (count <c_sT_Minimum_count_foci ){
            if (vvvFeatureFoci[label][Size_image_in_time-1][c_sT_Feature_Foci_state] != c_sT_state_assigned
                    && vvvFeatureFoci[label][Size_image_in_time-2][c_sT_Feature_Foci_state] != c_sT_state_assigned){
                qDebug()<<"label "<<label<<" unselected because detected less than "<<c_sT_Minimum_count_foci<<" times";
                for (int t = 0; t < Size_image_in_time; t++) {
                    vvvFeatureFoci[label][t][c_sT_Feature_Foci_selected]=false;
                }
            }
        }
    }

}

void m_makro_foci::Unselect_decreasing_curves()
{
    float sum;
    for(int label=1;label<FeatureFoci_nb_label;label++){
        sum=0;
        for(int t=0;t<Size_image_in_time-1;t++){
            sum+= (vv_intensity_filtered[label][t+1] - vv_intensity_filtered[label][t]);
        }
        if(sum<vvFeatureFoci_Average[label][c_sT_Feature_Foci_Average_intensity]){
            qDebug()<<"label "<<label<< "unselected because of decreasing curve";
            for (int t = 0; t < Size_image_in_time; t++)
                vvvFeatureFoci[label][t][c_sT_Feature_Foci_selected]=false;
        }
    }
}

void m_makro_foci::Update_selected_Foci_array()
{
        qDebug()<<"beginning Update_selected_Foci_array";
        qDebug()<<"FeatureFoci_nb_label_selected = "<<FeatureFoci_nb_label_selected;
    FeatureFoci_nb_label_selected = 1;

    qDebug()<<"nb_Foci_unselect_by_user = "<<nb_Foci_unselect_by_user;

    for(int label=0;label<nb_Foci_unselect_by_user;label++)
        for (int t=0;t<Size_image_in_time;t++){
                vvvFeatureFoci[Foci_unselect_by_user[label]][t][c_sT_Feature_Foci_selected] = false;
            }

    for(int label =1; label <FeatureFoci_nb_label; label++)
        if(vvvFeatureFoci[label][0][c_sT_Feature_Foci_selected] /*== true*/)        //D: == true is not needed
            FeatureFoci_nb_label_selected++;

    LabelFociSelected_To_LabelFoci.resize(FeatureFoci_nb_label_selected);
    LabelFoci_To_LabelFociSelected.resize(FeatureFoci_nb_label);

    for(int label=0;label<FeatureFoci_nb_label;label++)
        LabelFoci_To_LabelFociSelected[label]=-1;

    int label_selected=1;
    for(int label =1; label <FeatureFoci_nb_label; label++){
        if(vvvFeatureFoci[label][0][c_sT_Feature_Foci_selected] /*== true*/){       //D: == true is not needed
            LabelFociSelected_To_LabelFoci[label_selected]=label;
            LabelFoci_To_LabelFociSelected[label]=label_selected;
            qDebug()<<"LabelFociSelected_To_LabelFoci["<<label_selected<<"]="<<label;
            qDebug()<<"LabelFoci_To_LabelFociSelected["<<label<<"]="<<label_selected;
            label_selected++;
        }

    }
        qDebug()<<"FeatureFoci_nb_label_selected = "<<FeatureFoci_nb_label_selected;
        qDebug()<<"end Update_selected_Foci_array";

        Update_selected_centroid();
        Circled_selected_centroid();
}

void m_makro_foci::Unselect_non_pertinent_Foci_User()
{
    qDebug()<<"beginning Delete_pertinent_Foci_User";
    int current_Label=0;
    if(ui->tabWidget->currentIndex()==e_TAB_RESULTS){
        current_Label=LabelFociSelected_To_LabelFoci[ui->spinBox_delete_foci_tab_results->value()];
        ui->spinBox_delete_foci_tab_results->setMinimum(1);
        ui->spinBox_delete_foci_tab_results->setMaximum(FeatureFoci_nb_label_selected-1);

    }
    if(ui->tabWidget->currentIndex()==e_TAB_CURVES){
        current_Label=ui->horizontalSlider_curve_label->value();
        if(ui->checkBox_selected_foci->checkState()){
            current_Label=LabelFociSelected_To_LabelFoci[current_Label];
        }
    }

    if(current_Label>=0 && current_Label<FeatureFoci_nb_label){
    Foci_unselect_by_user.resize(nb_Foci_unselect_by_user+1);
    Foci_unselect_by_user[nb_Foci_unselect_by_user]=current_Label;
    nb_Foci_unselect_by_user++;

    bool Foci_added_by_user_unselect =false;
    for (int label=0;label<nb_Foci_added_by_user;label++)
        if (current_Label == vFoci_added[label]){
            if (label+1<nb_Foci_added_by_user){
                vFoci_added[label]=vFoci_added[label+1];
            }
            Foci_added_by_user_unselect=true;
        }
    if (Foci_added_by_user_unselect==true)
        nb_Foci_added_by_user--;

    qDebug()<<"end Unselect_non_pertinent_Foci_User";

    Update_selected_Foci_array();
    Init_add_focus_user();
    Update_Curves();
    Update_View();
    }
}


//----------------------------Emergence time of foci-----------------------------------

void m_makro_foci::Condition_emergence_time()
{
    bool found = false;
    int count ;
    float diff_max_min;
    vEmergence_time.resize(FeatureFoci_nb_label);
    for (int size=0 ;size<vEmergence_time.size();size++) {
        vEmergence_time[size]=-999999;
    }
    float coeff=ui->doubleSpinBox_coeff_std_dev->value();
    for (int label = 1; label < FeatureFoci_nb_label; label++) {
        // Check the first times
        count=0;
        diff_max_min=vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][label][c_STAT_MAXIMUM]-vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][label][c_STAT_MINIMUM];
        for (int t= 0;t<10 && t<Size_image_in_time;t++)
            if(vv_intensity_filtered[label][t+1]>vv_intensity_filtered[label][t])
                count++;
        if(Size_image_in_time>10)
            if (count >8 && (vv_intensity_filtered[label][10]>1.1*vv_intensity_filtered[label][1]))
                if ((vv_intensity_filtered[label][5]
                        -vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][label][c_STAT_MINIMUM] )>
                        0.1 * (diff_max_min))
                {
                    found = true;
                    vEmergence_time[label] =v_Time_scale[5];
            }

        for(int t=6; t< Size_image_in_time-3 && found == false;t++){
            if (vv_intensity_std_dev[label][t]>coeff*vv_intensity_std_dev[label][t-3])
               if (vv_intensity_std_dev[label][t+1]>coeff*vv_intensity_std_dev[label][t-2])
                   if (vv_intensity_std_dev[label][t+2]>coeff*vv_intensity_std_dev[label][t-1])
                        if (vv_intensity_std_dev[label][t+3]>coeff*vv_intensity_std_dev[label][t])
                                if(vv_intensity_filtered[label][t+3]>vv_intensity_filtered[label][t-3]){
  //                                  qDebug() <<"label "<<label<<" time "<<t;
                                        int t_int = t;
                                        while (t_int<Size_image_in_time && found == false){
                                            if ((vv_intensity_filtered[label][t_int])
                                             > ( 0.1 * diff_max_min
                                             +vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][label][c_STAT_MINIMUM]))
                                            {
                                                vEmergence_time[label] =v_Time_scale[t_int]-ui->spinBox_emergence_time_offset->value();
 //                                               qDebug()<<"vv_intensity_filtered[label][t_int]"<<vv_intensity_filtered[label][t_int]<<"  > "<< "0.1*"<<diff_max_min<<"+"<<vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][label][c_STAT_MINIMUM];
                                                found=true;
 //                                               qDebug()<<"time found at "<<t_int;
                                            }
                                        t_int++;
                                        }
                                    }
        }
        found=false;
    }
}

void m_makro_foci::Set_emergence_time_by_user()
{
    int label;
    if(ui->checkBox_selected_foci->checkState())
        label = LabelFociSelected_To_LabelFoci[ui->horizontalSlider_curve_label->value()];
    else
        label = ui->horizontalSlider_curve_label->value();

     vEmergence_time[label]=ui->spinBox_Emergence_time->value();
    Update_Curves();
}

void m_makro_foci::Variance_in_time_window()
{
    vv_intensity_std_dev.resize(FeatureFoci_nb_label);
    for (int size=0 ;size<vv_intensity_std_dev.size();size++){
        vv_intensity_std_dev[size].resize(Size_image_in_time);
    }

    float moving_average=0;
    int cpt=0;
    int time_window=ui->spinBox_time_window->value();
    float variance=0;
    for (int label = 1; label < FeatureFoci_nb_label; label++) {
        cpt=0;
        moving_average=0;
        variance=0;
        for(int t=0; t< Size_image_in_time-1;t++){
            cpt =0;
            variance=0;
            moving_average=0;
             // Calcul de la moyenne pour un nombre de valeurs donnes
            for (int t2 = t-time_window/2; t2<t+time_window/2;t2++){
                if (t2<Size_image_in_time && t2>=0){
                moving_average += vv_intensity_filtered[label][t2];
                cpt++;
                }
            }
            moving_average /= cpt;
//            qDebug()<<"moving average "<<moving_average;
        // Calcul de la variance pour ces valeurs
            cpt =0;
            for (int t2 = t-time_window/2; t2<t+time_window/2;t2++){
                if (t2<Size_image_in_time && t2>=0){
                    variance+=
                            (vv_intensity_filtered[label][t2] - moving_average)
                            *(vv_intensity_filtered[label][t2] - moving_average);
                    cpt++;
                }
                else
                {

                }
            }
            variance = sqrt(variance/cpt);
            vv_intensity_std_dev[label][t]=variance;
//            qDebug()<<"vv_intensity_std_dev["<<label<<"]["<<t<<"]="<<vv_intensity_std_dev[label][t];
        }
    }
}

void m_makro_foci::Mean_Filter_intensity()
{
    int depth =-1;
    int norm = 1;
/*    D_Img_Proc::Filter_Box(
                            &M_foci_intensity,
                            &M_foci_intensity_filtered,
                            1,
                            1,
                            BORDER_DEFAULT,
                            depth,
                            norm);

*/
        boxFilter(
                M_foci_intensity,
                M_foci_intensity_filtered,
                depth,
                Size(10, 1),
                Point(-1, -1),
                norm,
                BORDER_DEFAULT);

        boxFilter(
                M_foci_intensity_filtered,
                M_foci_intensity_filtered,
                depth,
                Size(5, 1),
                Point(-1, -1),
                norm,
                BORDER_DEFAULT);
}

void m_makro_foci::Derivativ()
{
    int scale =1;
    int delta =0;
    int depth       = -1;
    int norm = 1;


    qDebug()<<"first derivative";
    Sobel(
                M_foci_intensity_filtered,
                M_foci_intensity_filter_1st_deriv,
                depth,
                1,
                0,
                3,
                scale,
                delta,
                BORDER_DEFAULT);                   


/*    spatialGradient(
            M_foci_intensity_filtered,
            M_foci_intensity_filter_1st_deriv,
            0,
            3,
            BORDER_DEFAULT);
*/
    qDebug()<<"2nd derivative";

    boxFilter(
            M_foci_intensity_filter_1st_deriv,
            M_foci_intensity_filter_1st_deriv,
            depth,
            Size(10, 1),
            Point(-1, -1),
            norm,
            BORDER_DEFAULT);

    Sobel(
                M_foci_intensity_filter_1st_deriv,
                M_foci_intensity_filter_2nd_deriv,
                depth,
                1,
                0,
                3,
                scale,
                delta,
                BORDER_DEFAULT);



    qDebug()<<"end derivative";

/*    boxFilter(
            M_foci_intensity_filter_2nd_deriv,
            M_foci_intensity_filter_2nd_deriv,
            depth,
            Size(10, 1),
            Point(-1, -1),
            norm,
            BORDER_DEFAULT);
*/
}

void m_makro_foci::Filter_Intensity_values()
{
    qDebug()<<"     init";
    M_foci_intensity.create(FeatureFoci_nb_label,Size_image_in_time,CV_64FC1);
    M_foci_intensity_filtered.create(FeatureFoci_nb_label,Size_image_in_time,CV_64FC1);
    M_foci_intensity_filter_1st_deriv.create(FeatureFoci_nb_label,Size_image_in_time,CV_64FC1);
    M_foci_intensity_filter_2nd_deriv.create(FeatureFoci_nb_label,Size_image_in_time,CV_64FC1);

    qDebug()<<"     resize";
    resize_array(&vv_intensity_filtered,FeatureFoci_nb_label,Size_image_in_time);
    resize_array(&vv_intensity_filter_1st_deriv,FeatureFoci_nb_label,Size_image_in_time);
    resize_array(&vv_intensity_filter_2nd_deriv,FeatureFoci_nb_label,Size_image_in_time);

    qDebug()<<"     Vector_2_Mat";
    Vector_2_Mat(&vv_intensity,&M_foci_intensity);
    qDebug()<<"     Mean_Filter_intensity";
    Mean_Filter_intensity();
    qDebug()<<"     Mat_2_vector";
    Mat_2_vector(&M_foci_intensity_filtered,&vv_intensity_filtered);
    qDebug()<<"     Derivativ";
    Derivativ();
    qDebug()<<"Mat_2_vector first";
    Mat_2_vector(&M_foci_intensity_filter_1st_deriv,&vv_intensity_filter_1st_deriv);
    qDebug()<<"Mat_2_vector 2nd";
    Mat_2_vector(&M_foci_intensity_filter_2nd_deriv,&vv_intensity_filter_2nd_deriv);

}

void m_makro_foci::Vector_2_Mat(vector<vector<double>> *p_vvIn, Mat *pM_Out)
{
    for(int label=0;label<FeatureFoci_nb_label;label++){
        for(int t=0;t<Size_image_in_time;t++){
            pM_Out->at<double>(label,t)=(*p_vvIn)[label][t];
        }
    }
}

void m_makro_foci::Mat_2_vector( Mat *pM_In, vector<vector<double>> *p_vvOut)
{
    for(int label=0;label<FeatureFoci_nb_label;label++){
        for(int t=0;t<Size_image_in_time;t++){
            (*p_vvOut)[label][t]=pM_In->at<double>(label,t);
        }
    }
}

//------------------------------------------------------------------------------------
// ----------------------------------  Curves -----------------------------------------
//------------------------------------------------------------------------------------

void m_makro_foci::Update_Curves()
{
    int Corresponding_Label, time_cursor;
    time_cursor=v_Time_scale[ui->horizontalSlider_Image_in_Time_curves->value()];
     if(ui->checkBox_selected_foci->checkState()){
        ui->horizontalSlider_curve_label->setMaximum(FeatureFoci_nb_label_selected-1);
        if (FeatureFoci_nb_label_selected-1>0){
            ui->horizontalSlider_curve_label->setMinimum(1);
            ui->spinBox_label->setMinimum(1);
        }
        ui->spinBox_label->setMaximum(FeatureFoci_nb_label_selected-1);
        ui->spinBox_delete_foci_tab_results->setMaximum(FeatureFoci_nb_label_selected-1);
        Corresponding_Label=LabelFociSelected_To_LabelFoci[ui->horizontalSlider_curve_label->value()];
     }
     else{
        ui->horizontalSlider_curve_label->setMaximum(FeatureFoci_nb_label-1);
        if (FeatureFoci_nb_label-1>0){
            ui->horizontalSlider_curve_label->setMinimum(1);
            ui->spinBox_label->setMinimum(1);
        }
        ui->spinBox_label->setMaximum(FeatureFoci_nb_label-1);
        Corresponding_Label=ui->horizontalSlider_curve_label->value();
     }


    if(ui->checkBox_filtered_values->isChecked()){
        Plot_Curves_Single_Classes(ChartView_Hist,
                                           &v_temps,
                                           &vv_intensity_filtered[Corresponding_Label], //
                                           0,0,vEmergence_time[Corresponding_Label],time_cursor,"foci intensity",  "label ", "time", "intensity", 0);
    }
    else if(ui->checkBox_first_deriv->isChecked()){
    Plot_Curves_Single_Classes(ChartView_Hist,
                                       &v_temps,
                                       &vv_intensity_filter_1st_deriv[Corresponding_Label], //
                                       0,0,vEmergence_time[Corresponding_Label],time_cursor,"foci intensity",  "label ", "time", "intensity", 0);
    }
    else if(ui->checkBox_2nd_deriv->isChecked()){
    Plot_Curves_Single_Classes(ChartView_Hist,
                                       &v_temps,
                                       &vv_intensity_filter_2nd_deriv[Corresponding_Label], //
                                       0,0,vEmergence_time[Corresponding_Label],time_cursor,"foci intensity",  "label ", "time", "intensity", 0);
    }
    else {
        Plot_Curves_Single_Classes(ChartView_Hist,
                                           &v_temps,
                                           &vv_intensity[Corresponding_Label], //
                                           0,0,vEmergence_time[Corresponding_Label],time_cursor,"foci intensity",  "label ", "time", "intensity", 0);
        }

    Single_Circled_Focus(Corresponding_Label);

    Update_Ui();
}

void m_makro_foci::Calc_Curves()
{
/*    (v_labels).resize(FeatureFoci_nb_label);
    (vv_intensity).resize(v_labels.size());
    (vv_intensity_filtered).resize(v_labels.size());
    (v_temps).resize(vvvFeatureFoci[0].size());//----

    for(unsigned int i=0; i<v_labels.size();i++){
        vv_intensity[i].resize(vvvFeatureFoci[i].size());//-----
        vv_intensity_filtered[i].resize(vvvFeatureFoci[i].size());//----
    }
*/
/*
    IntensityMax=vvvFeatureFoci[1][0][c_ST_Feature_Foci_Intensity_norm]; // the first value
    for (int label=1;label<FeatureFoci_nb_label;label++){
        for(int t=0;t<vvvFeatureFoci[label].size();t++){
            v_temps[t]=t;
            vv_intensity[label][t]=vvvFeatureFoci[label][t][c_ST_Feature_Foci_Intensity_norm];
            if (IntensityMax<vvvFeatureFoci[label][t][c_ST_Feature_Foci_Intensity_norm])
                IntensityMax=vvvFeatureFoci[label][t][c_ST_Feature_Foci_Intensity_norm];
            if (IntensityMin>vvvFeatureFoci[label][t][c_ST_Feature_Foci_Intensity_norm])
                IntensityMin=vvvFeatureFoci[label][t][c_ST_Feature_Foci_Intensity_norm];
        }
    }

*/

}

int m_makro_foci::Plot_Curves_Single_Classes(QChartView *pChartView, vector<double> *v_histx,vector<double> *v_histy, double min, double step, double emergence_time, double time_cursor, QString name_title, QString name_series, QString name_x, QString name_y, bool ignore_first)
{
    pChartView->chart()->deleteLater();

    step;
    min;

    //Chart
    //qDebug() << "==================================Chart";
    QChart *pChart = new QChart();
    //chart->createDefaultAxes();
    pChart->setTitle(name_title);
    //chart->legend()->setVisible(false);
    //chart->legend()->setAlignment(Qt::AlignBottom);

    //Axis
    //qDebug() << "Axis";
    QValueAxis *x_axis = new QValueAxis();
    x_axis->setTitleText(name_x);
    pChart->setAxisX(x_axis);

    QValueAxis *y_axis = new QValueAxis();
    y_axis->setTitleText(name_y);
    if (ui->checkBox_scale_curve->isChecked()){
            y_axis->setMin(IntensityMin);
            y_axis->setMax(IntensityMax+0.5);
    }

    pChart->setAxisY(y_axis);


    //Series
    //qDebug() << "Series";
//    QLineSeries *series  = new QLineSeries();
    QScatterSeries *series  = new QScatterSeries();
    series->setMarkerSize(10);
    series->setName(name_series);

    QLineSeries *Serie_emergence_time = new QLineSeries(); //QLineSeries
    Serie_emergence_time->setColor(QColor(255,0,0));
    Serie_emergence_time->setName("Emergence time");
    Serie_emergence_time->append(emergence_time,0);
    Serie_emergence_time->append(emergence_time,IntensityMax);

    QLineSeries *Serie_time_cursor = new QLineSeries(); //QLineSeries
    Serie_time_cursor->setColor(QColor(0,255,0));
    Serie_time_cursor->setName("Time cursor");
    Serie_time_cursor->append(time_cursor,0);
    Serie_time_cursor->append(time_cursor,IntensityMax);

    //Check if v_histx et v_histy have the same size
    if (v_histx->size() != v_histy->size())
        return ER_size_missmatch;

    //start
    unsigned int start = 0;
    if(ignore_first)
        start = 1;

    //Data
    //qDebug() << "Data";
    for(unsigned int c = start; c < v_histx->size(); c++)
    {
        double value = (*v_histx)[c];
        double count = (*v_histy)[c];

        //qDebug() << "class:" << c << " - " << value << count;

        series->append(value, count);
    }
    //qDebug() << "series count:" << series->count();


    //Attach
    pChart->addSeries(series);
    pChart->addSeries(Serie_emergence_time);
    pChart->addSeries(Serie_time_cursor);
    series->attachAxis(x_axis);
    series->attachAxis(y_axis);
    Serie_emergence_time->attachAxis(x_axis);
    Serie_emergence_time->attachAxis(y_axis);
    Serie_time_cursor->attachAxis(x_axis);
    Serie_time_cursor->attachAxis(y_axis);
    pChartView->setChart(pChart);


    //qDebug() << "Plot Sucess===============================";


    return ER_okay;
}

void m_makro_foci::Update_detail_Values()
{
    float diff;
    int label;
    if(ui->checkBox_selected_foci->checkState())
        label = LabelFociSelected_To_LabelFoci[ui->horizontalSlider_curve_label->value()];
    else
        label = ui->horizontalSlider_curve_label->value();

    if(ui->checkBox_filtered_values->checkState()){

        ui->lineEdit_Average_intensity  ->setText(QString::number(vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][label][c_STAT_MEAN_ARITMETIC]));
        ui->lineEdit_Std_dev            ->setText(QString::number(vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][label][c_STAT_STAN_DEV_TOTAL]));
        diff = vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][label][c_STAT_MAXIMUM]
                -vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter][label][c_STAT_MINIMUM];
        ui->lineEdit_diff_min_max       ->setText(QString::number(diff));


    }
    else if(ui->checkBox_filtered_values->checkState()) {

        ui->lineEdit_Average_intensity  ->setText(QString::number(vvvv_stat_intensity[c_sT_Array_intensity_normalized][label][c_STAT_MEAN_ARITMETIC]));
        ui->lineEdit_Std_dev            ->setText(QString::number(vvvv_stat_intensity[c_sT_Array_intensity_normalized][label][c_STAT_STAN_DEV_TOTAL]));
        diff = vvvv_stat_intensity[c_sT_Array_intensity_normalized][label][c_STAT_MAXIMUM]
             -vvvv_stat_intensity[c_sT_Array_intensity_normalized][label][c_STAT_MINIMUM];
        ui->lineEdit_diff_min_max       ->setText(QString::number(diff));

    }
    else if(ui->checkBox_first_deriv->checkState()) {

        ui->lineEdit_Average_intensity  ->setText(QString::number(vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter_1st_deriv][label][c_STAT_MEAN_ARITMETIC]));
        ui->lineEdit_Std_dev            ->setText(QString::number(vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter_1st_deriv][label][c_STAT_STAN_DEV_TOTAL]));
        diff = vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter_1st_deriv][label][c_STAT_MAXIMUM]
             -vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter_1st_deriv][label][c_STAT_MINIMUM];
        ui->lineEdit_diff_min_max       ->setText(QString::number(diff));

    }
    else if(ui->checkBox_2nd_deriv->checkState()) {

        ui->lineEdit_Average_intensity  ->setText(QString::number(vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter_2nd_deriv][label][c_STAT_MEAN_ARITMETIC]));
        ui->lineEdit_Std_dev            ->setText(QString::number(vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter_2nd_deriv][label][c_STAT_STAN_DEV_TOTAL]));
        diff = vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter_2nd_deriv][label][c_STAT_MAXIMUM]
             -vvvv_stat_intensity[c_sT_Array_intensity_normalized_filter_2nd_deriv][label][c_STAT_MINIMUM];
        ui->lineEdit_diff_min_max       ->setText(QString::number(diff));

    }

    ui->spinBox_Emergence_time->setValue(vEmergence_time[label]);
}

//------------------------------------------------------------------------------------
// ----------------------------------- Label Foci ------------------------------------
//------------------------------------------------------------------------------------

void m_makro_foci::Label_Foci_in_time()
{
    int Wi = vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][0].cols; //image width
    int Hi = vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][0].rows; //image heigth
    int Yi;                //image position y
    int Xi;                //image position x

    int label, labeltemp;
    int nblabel=1; // first label =1
    int coordX_found_foci, coordY_found_foci, coordX_found_foci_check, coordY_found_foci_check;

    vv_label_state.resize(c_sT_Nb_label_max);
    for(int i=0;i<vv_label_state.size();i++){
        vv_label_state[i].resize(Size_image_in_time);
        for(int t=0;t<Size_image_in_time;t++){
            vv_label_state[i][t]=c_sT_state_unassigned;
        }
     }
    vvvFeatureFoci.clear();
    // -------- Resize of array of feature vvvFeatureFoci
   vvvFeatureFoci.resize(c_sT_Nb_label_max);
    for(int lab = 0; lab <vvvFeatureFoci.size(); lab++){
        vvvFeatureFoci[lab].resize(Size_image_in_time);
       for(int t=0;t<Size_image_in_time;t++){
           vvvFeatureFoci[lab][t].resize(c_sT_Feature_Foci);
            for(int j = 0; j <vvvFeatureFoci[lab][t].size(); j++)
               vvvFeatureFoci[lab][t][j] = 0;
            vvvFeatureFoci[lab][t][c_sT_Feature_Foci_selected]=true;
       }
    }

//   resize_array(&vvvFeatureFoci,c_sT_Nb_label_max,Size_image_in_time,c_sT_Feature_Foci);


    for(int t=0; t < Size_image_in_time; t++) // init image
        vvMA_Nuclei[c_sT_N_Label_in_time][t] = Mat(vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][0].size(),CV_16U, Scalar(c_sT_Value_bckgd_foci_labeled)); //vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][0].type()

//*---------------------------------------------------------------------------------------------------------------
    int t_temp;
    bool next_foci_labeled =0;
    for(int t=0; t < Size_image_in_time; t++){ //
//        qDebug()<<"--------------------------- t= "<<t;
        for(Yi=0;Yi<Hi;Yi++)
             for(Xi=0; Xi<Wi; Xi++){
                 next_foci_labeled=0;

                 label = vvMA_Nuclei[c_sT_N_Label_in_time][t].at<ushort>(Yi,Xi);
                if(vvMA_Nuclei[c_sT_N_REDUCTION][t].at<uchar>(Yi,Xi) ==c_sT_Value_centroid){ // there is a centroid
                    if(label == c_sT_Value_bckgd_foci_labeled){ //there is no centroid in the labeled foci image
                    //if there is a non labeled foci
//                    qDebug()<<"there is a non labeled foci"<<"x= "<<Xi<<" y="<<Yi;

                    Assigne_label_to_Foci(&vvMA_Nuclei[c_sT_N_Label_in_time][t],nblabel,t,&Xi,&Yi);
                    label = vvMA_Nuclei[c_sT_N_Label_in_time][t].at<ushort>(Yi,Xi);
//                    qDebug()<<"label = "<<nblabel;
                    Update_label_state(nblabel,t,c_sT_state_assigned);
                    nblabel++;
                    }
                }
                if(label != c_sT_Value_bckgd_foci_labeled ){ //if there is a labeled foci
//                    qDebug()<<"Analyse t+1 for label = " <<vvMA_Nuclei[c_sT_N_Label_in_time][t].at<ushort>(Yi,Xi);
                    for(int next_t=1; next_t<c_ST_interval_time;next_t++){
                        t_temp=t+next_t;
                        if (t_temp<Size_image_in_time && next_foci_labeled ==0){
//                            qDebug()<<"analyse a t ="<<t_temp;
                            if (Check_Foci_in_Circle(&vvMA_Nuclei[c_sT_N_REDUCTION][t_temp],&Xi,&Yi,&coordX_found_foci,&coordY_found_foci,&labeltemp)){
                                // check if the foci found(coordX_found,coorYfound)
                                // has as closer foci the previous foci in (Yi,Xi)
                                // if not : don't assign the label from (Yi,Xi) at time t to (coordX_found,coordY_found) a time t+1
                                Check_Foci_in_Circle(&vvMA_Nuclei[c_sT_N_REDUCTION][t],&coordX_found_foci,&coordY_found_foci,&coordX_found_foci_check,&coordY_found_foci_check,&labeltemp);
//                                qDebug()<<"Xi = "<<Xi<<" coordX_found_foci_check = "<<coordX_found_foci_check<<" Yi = "<<Yi<<" coordY_found_foci_check = "<<coordY_found_foci_check ;
                                if (Xi == coordX_found_foci_check && Yi == coordY_found_foci_check){
//                                    qDebug()<<"Xi= "<<Xi<<" Yi= "<<Yi<<" deviennent : Xi'= "<<coordX_found_foci<<" Yi= "<<coordY_found_foci;
                                        Assigne_label_to_Foci(&vvMA_Nuclei[c_sT_N_Label_in_time][t_temp],label,t_temp,&coordX_found_foci,&coordY_found_foci);

    //                                    Pour verifier que le label a bien ete maj dans temps +1
    //                                    qDebug()<<"vvMA_Nuclei[c_sT_N_Label_in_time]["<<t_temp<<"].at<ushort>("<<coordX_found_foci <<" , "<<coordY_found_foci<< ")";
    //                                    qDebug()<<vvMA_Nuclei[c_sT_N_Label_in_time][t_temp].at<ushort>(coordX_found_foci,coordY_found_foci);

                                        next_foci_labeled=1;
                                        Update_label_state(label,t_temp,c_sT_state_assigned);
                                }
                                else {
//                                    qDebug()<<"LABEL LOST";
                                    Update_label_state(label,t_temp,c_sT_state_lost);
                                }
                            }
                            else{
//                                qDebug()<<"LABEL LOST 2";
                                Update_label_state(label,t_temp,c_sT_state_lost);
                            }

                        }
                    }
                }
                if (nblabel+1>vvvFeatureFoci.size())
                {
                    // -------- Resize of array of feature vvvFeatureFoci
                   vvvFeatureFoci.resize(vvvFeatureFoci.size()+1);
                        vvvFeatureFoci[vvvFeatureFoci.size()].resize(Size_image_in_time);
                       for(int t=0;t<Size_image_in_time;t++){
                           vvvFeatureFoci[vvvFeatureFoci.size()][t].resize(c_sT_Feature_Foci);
                            for(int j = 0; j <vvvFeatureFoci[vvvFeatureFoci.size()][t].size(); j++)
                               vvvFeatureFoci[vvvFeatureFoci.size()][t][j] = 0;
                            vvvFeatureFoci[vvvFeatureFoci.size()][t][c_sT_Feature_Foci_selected]=true;

                       }
                }
          }      
    }
    FeatureFoci_nb_label = nblabel;

//--------------------------------------------------------------------------------------------------------------*/

/*
    int t_temp;
    bool next_foci_labeled =0;
    for(int t=0; t < Size_image_in_time; t++){ //
//        qDebug()<<"--------------------------- t= "<<t;
        for(Yi=0;Yi<Hi;Yi++)
             for(Xi=0; Xi<Wi; Xi++){
                if(vvMA_Nuclei[c_sT_N_REDUCTION][t].at<uchar>(Yi,Xi) ==c_sT_Value_centroid){ // there is a centroid
                    vvv

                    nblabel++;
                    }
                }
             }
    }


                if(label != c_sT_Value_bckgd_foci_labeled ){ //if there is a labeled foci
//                    qDebug()<<"Analyse t+1 for label = " <<vvMA_Nuclei[c_sT_N_Label_in_time][t].at<ushort>(Yi,Xi);
                    for(int next_t=1; next_t<c_ST_interval_time;next_t++){
                        t_temp=t+next_t;
                        if (t_temp<Size_image_in_time && next_foci_labeled ==0){
//                            qDebug()<<"analyse a t ="<<t_temp;
                            if (Check_Foci_in_Circle(&vvMA_Nuclei[c_sT_N_REDUCTION][t_temp],&Xi,&Yi,&coordX_found_foci,&coordY_found_foci,&labeltemp)){
                                // check if the foci found(coordX_found,coorYfound)
                                // has as closer foci the previous foci in (Yi,Xi)
                                // if not : don't assign the label from (Yi,Xi) at time t to (coordX_found,coordY_found) a time t+1
                                Check_Foci_in_Circle(&vvMA_Nuclei[c_sT_N_REDUCTION][t],&coordX_found_foci,&coordY_found_foci,&coordX_found_foci_check,&coordY_found_foci_check,&labeltemp);
//                                qDebug()<<"Xi = "<<Xi<<" coordX_found_foci_check = "<<coordX_found_foci_check<<" Yi = "<<Yi<<" coordY_found_foci_check = "<<coordY_found_foci_check ;
                                if (Xi == coordX_found_foci_check && Yi == coordY_found_foci_check){
//                                    qDebug()<<"Xi= "<<Xi<<" Yi= "<<Yi<<" deviennent : Xi'= "<<coordX_found_foci<<" Yi= "<<coordY_found_foci;
                                        Assigne_label_to_Foci(&vvMA_Nuclei[c_sT_N_Label_in_time][t_temp],label,t_temp,&coordX_found_foci,&coordY_found_foci);

    //                                    Pour verifier que le label a bien ete maj dans temps +1
    //                                    qDebug()<<"vvMA_Nuclei[c_sT_N_Label_in_time]["<<t_temp<<"].at<ushort>("<<coordX_found_foci <<" , "<<coordY_found_foci<< ")";
    //                                    qDebug()<<vvMA_Nuclei[c_sT_N_Label_in_time][t_temp].at<ushort>(coordX_found_foci,coordY_found_foci);

                                        next_foci_labeled=1;
                                        Update_label_state(label,t_temp,c_sT_state_assigned);
                                }
                                else {
//                                    qDebug()<<"LABEL LOST";
                                    Update_label_state(label,t_temp,c_sT_state_lost);
                                }
                            }
                            else{
//                                qDebug()<<"LABEL LOST 2";
                                Update_label_state(label,t_temp,c_sT_state_lost);
                            }

                        }
                    }
                }
                if (nblabel+1>vvvFeatureFoci.size())
                {
                    // -------- Resize of array of feature vvvFeatureFoci
                   vvvFeatureFoci.resize(vvvFeatureFoci.size()+1);
                        vvvFeatureFoci[vvvFeatureFoci.size()].resize(Size_image_in_time);
                       for(int t=0;t<Size_image_in_time;t++){
                           vvvFeatureFoci[vvvFeatureFoci.size()][t].resize(c_sT_Feature_Foci);
                            for(int j = 0; j <vvvFeatureFoci[vvvFeatureFoci.size()][t].size(); j++)
                               vvvFeatureFoci[vvvFeatureFoci.size()][t][j] = 0;
                            vvvFeatureFoci[vvvFeatureFoci.size()][t][c_sT_Feature_Foci_selected]=true;

                       }
                }
          }
    }
    FeatureFoci_nb_label = nblabel;

*/



    qDebug()<<"***> FeatureFoci_nb_label"<<FeatureFoci_nb_label;
}
/*
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//RAPPEL STRUCTURE
    // boucle sur te temps des images
    // Parcours de l'image des centroid non labele à un temps t
        //if value==1 // foci non labelé (bckgrd =0)
                //verifier aux temps precedents (combien avant :definir une cste)
                    //pour chaque temps
                    // y a t'il un label predu dans le perimetre ?
                    // si oui --> on reattribue le meme label, on sort de la boucle
                    // si non à la fin . attribue un nouveau label
                        // update nb label (nb_label++)
                        // set label  : attributed
       //else if value !=0 // foci avec label
            //regarder a t+1 s'il y a un foci à labeler
                //si oui
                        // un seul ->le labeler
                        // plusieurs : prendre le plus proche
                //si non : mettre etat label : lost

*/

int m_makro_foci::Check_Foci_in_Circle(Mat* pIn, int* CoordX_In, int* CoordY_In, int* CoordX_Out, int* CoordY_Out,int* label_Out)
{
    int Wi = pIn->cols; //image width
    int Hi = pIn->rows; //image heigth
    int Yi;                //image position y
    int Xi;                //image position x

    float dist=0;
    float min_dist=100;
    bool update=0;
    //Par la suite : ne pas parcourir toute l'image, mais seulement utiliser le tableau de caracteristique sur les foci de l'image precedente
    // --> gain de temps
    //--> mais pas sur que ce soit possible : tableau vraiment fini si on l'utilise ici ?
    for(Yi=0;Yi<Hi;Yi++)
         for(Xi=0; Xi<Wi; Xi++){
             if (pIn->at<uchar>(Yi,Xi) == 255){
                 dist = (Xi- *CoordX_In)*(Xi- *CoordX_In) + (Yi- *CoordY_In)*(Yi- *CoordY_In);
                 if(dist < (ui->spinBox_radius_circle_move->value())*(ui->spinBox_radius_circle_move->value())){
                    if (dist<min_dist){
                        min_dist=dist;
//                        qDebug()<<"min dist = "<<min_dist;
//                        qDebug()<<"maj coord";
                        update=1;
                        *CoordX_Out=Xi;
                        *CoordY_Out=Yi;
                        *label_Out=pIn->at<uchar>(Yi,Xi);
                    }
                 }
              }
         }
    return update;
}

void m_makro_foci::Assigne_label_to_Foci(Mat * pIn, int label, int t, int* CoordX, int* CoordY)
{
    pIn->at<ushort>(*CoordY,*CoordX)=label;
    vvvFeatureFoci[label][t][c_sT_Feature_Foci_coordX]=*CoordX;
    vvvFeatureFoci[label][t][c_sT_Feature_Foci_coordY]=*CoordY;
}

void m_makro_foci::Update_label_state(int label, int t, const int state)
{
    vv_label_state[label][t]=state;
    vvvFeatureFoci[label][t][c_sT_Feature_Foci_state]=state;

}

void m_makro_foci::Single_Circled_Focus(int label)
{
//    qDebug()<<"circled foci";
    vMA_Circled_Focus.resize(Size_image_in_time);
    for(int t=0;t<Size_image_in_time;t++){
        vMA_Circled_Focus[t]=vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][t].clone();
    }

    int coordX, coordY;
    int radius =ui->spinBox_radius_circle_intensity->value();
    int color=255;
    int thickness=1;
    for(int t=0;t<Size_image_in_time;t++){
            coordX= vvvFeatureFoci[label][t][c_sT_Feature_Foci_coordX];
            coordY= vvvFeatureFoci[label][t][c_sT_Feature_Foci_coordY];

            D_Img_Proc::Draw_Circle(&vMA_Circled_Focus[t],coordX, coordY,radius, color, thickness);
        }

//   qDebug()<<"fin circled foci";
}

//------------------------------------------------------------------------------------
// ----------------------------------  Write in cvs file  ----------------------------
//------------------------------------------------------------------------------------

void m_makro_foci::Stream_Open_foci_in_time()
{
    if(Stream_Open_Foci) //if already open
        return;

    QString QS_try = pStore->dir_M_FociTimeNuclei()->path();
    qDebug()<<"path = "<<QS_try;
    QString QS_Directory = QFileDialog::getExistingDirectory(
                this,
                tr("Select folder to stream the output to."),
                QS_try // QFileDialog::DontUseNativeDialog
                );//pStore->dir_Save()->path()

    if(QS_Directory.isEmpty())
        return;

    //create subfolder for output
    unsigned int count = 0;
    QString QS_Folder_Out_Sub = QS_Directory + "/Results_0";
    while(QDir(QS_Folder_Out_Sub).exists()){
        count++;
        QS_Folder_Out_Sub = QS_Directory + "/Results_" + QString::number(count);
    }
    QDir().mkdir(QS_Folder_Out_Sub);

    DIR_Stream_Foci.setPath(QS_Folder_Out_Sub);

    //=========================start stream

    QString ST_Stream_Summary = DIR_Stream_Foci.path() + "/FociTracking.csv";
    OS_Stream_Foci_Info.open(ST_Stream_Summary.toStdString());
    OS_Stream_Foci_Info << fixed << setprecision(6) << showpoint;

    Stream_Open_Foci = true;

}

void m_makro_foci::Stream_Init_foci_in_time()
{
    OS_Stream_Foci_Info <<"t,";
    for (int label=1;label<FeatureFoci_nb_label_selected;label++)
        OS_Stream_Foci_Info <<"label "<<label<<",";
    OS_Stream_Foci_Info <<" Nuclei ,"<<"Background \n";
}

void m_makro_foci::Save_info()
{
    int corresponding_label=0;
    for(int t=0;t<Size_image_in_time;t++){
        OS_Stream_Foci_Info <<v_Time_scale[t]<<",";
        for(int label = 1; label < FeatureFoci_nb_label_selected; label++){
            corresponding_label = LabelFociSelected_To_LabelFoci[label];
            OS_Stream_Foci_Info << vvvFeatureFoci[corresponding_label][t][c_ST_Feature_Foci_Intensity_norm]<<",";
        }
        OS_Stream_Foci_Info << Bckgd_in_nuclei[t]<<","<<Bckgd_out_nuclei[t]<<"\n";
    }
}

void m_makro_foci::Save_emergence_time()
{
    OS_Stream_Foci_Info <<"emergence time :,";
    for (int label=1;label<FeatureFoci_nb_label_selected;label++)  {
        OS_Stream_Foci_Info <<vEmergence_time[LabelFociSelected_To_LabelFoci[label]]<<",";
    }
}

void m_makro_foci::Stream_End_foci_in_time()
{
    if(!Stream_Open_Foci)
        return;

    OS_Stream_Foci_Info.close();

    Stream_Open_Foci = false;
}

int m_makro_foci::Save_csv_file()
{
    qDebug()<<"Start save_csv_file";
    qDebug()<<"Stream_Open_foci_in_time :";
    Stream_Open_foci_in_time();
    qDebug()<<"Stream_Init_foci_in_time";
    Stream_Init_foci_in_time();
    if(ui->checkBox_save_image->isChecked()){
        qDebug()<<"Save_Picture_of_Circled_Foci";
        Save_Picture_of_Circled_Foci();
    }
    qDebug()<<"Save_info";
    Save_info();
    if(ui->checkBox_save_emergence_time->isChecked()){
        qDebug()<<"Save_emergence_time";
        Save_emergence_time();
    }
    qDebug()<<"Save_Parameters ";
    Save_Parameters();
    qDebug()<<"Stream_End_foci_in_time";
    Stream_End_foci_in_time();
    qDebug()<<"end Save_csv_file";

  return 0;
}

void m_makro_foci::Save_Parameters()
{
    //Save Blur or not
    OS_Stream_Foci_Info<<"\n\n\n Parameters used before detection :\n";
    if(ui->checkBox_blur_images->isChecked())
        OS_Stream_Foci_Info<<",Images blured before processing \n";
    OS_Stream_Foci_Info<<",Gamma value :,"<< ui->doubleSpinBox_gamma->value()<<"\n";
    OS_Stream_Foci_Info<<"Threshold (local) parameters : \n";
    OS_Stream_Foci_Info<<",Mask size :,"<<ui->spinBox_03_Mask_size->value()<<"\n";
    OS_Stream_Foci_Info<<",Offset :,"<<ui->spinBox_03_Offset->value()<<"\n";
    OS_Stream_Foci_Info<<"\nParameters used for detection :\n";
    OS_Stream_Foci_Info<<"Maximum distance that a focus can travel between two images :, circle of radius " <<ui->spinBox_radius_circle_move->value() <<"(pixels) \n";
    OS_Stream_Foci_Info<<"Foci parameters :\n"<<", radius circle :,"<<ui->spinBox_radius_circle_intensity->value()<<"\n";
    OS_Stream_Foci_Info<<"Parameters used for selection of foci :\n"<<", Standart deviation minimum :,"<<ui->doubleSpinBox_Select_pertinent_Foci_Std_dev->value()<<"\n";
    OS_Stream_Foci_Info<<"Parameters used for emergence time detection :\n"<<", Standart deviation limit :,"<<ui->doubleSpinBox_coeff_std_dev->value()<<"\n";
    OS_Stream_Foci_Info<<",\n Time Window :,"<<ui->spinBox_time_window->value()<<"\n, Emergence time offset :,"<<ui->spinBox_emergence_time_offset->value()<<"\n";

}

void m_makro_foci::Save_Picture_of_Circled_Foci()
{
    QString name_picture_circled_foci_path = DIR_Stream_Foci.path()+"/Circled_foci.png";

    ui->tabWidget->setCurrentIndex(e_TAB_RESULTS);
    ui->comboBox_step_results->setCurrentIndex(c_sT_N_CIRCLED_FOCI_VIEW);
    V_Nuclei_tab_Results.Update_Image(&(vvMA_Nuclei[c_sT_N_Label_in_time_CIRCLED_with_labels][0]));

//    QPixmap* pixmap_save = V_Nuclei_tab_Results.PX();
//    pixmap_save->save(name_picture_circled_foci_path, 0, -1);

    imwrite(name_picture_circled_foci_path.toStdString(),vvMA_Nuclei[c_sT_N_Label_in_time_CIRCLED_with_labels][0]);
}

// Full means with informations about all foci (not only selected) + info about coord of the foci and statut (interpolated) etc
void m_makro_foci::Stream_Open_foci_in_time_full()
{
/*    if(Stream_Open_Foci) //if already open
        return;

    QString ST_Dir = QFileDialog::getExistingDirectory(
                this,
                "Select folder to stream the output to.",
                pStore->dir_Save()->path());

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

    DIR_Stream_Foci.setPath(QS_Folder_Out_Sub);

    //=========================start stream

    QString ST_Stream_Summary = DIR_Stream_Foci.path() + "/Summary.csv";
    OS_Stream_Foci_Info.open(ST_Stream_Summary.toStdString());
    OS_Stream_Foci_Info << fixed << setprecision(6) << showpoint;

*/
/*    QString ST_Stream_Par_BasePath = DIR_Stream_Foci.path() + "/Parameter_";
    OS_Stream_Parameters_Foci.clear();
    OS_Stream_Parameters_Foci.resize(PARAMETERS);
    for(unsigned int p = 0; p < PARAMETERS; p++)
    {
        OS_Stream_Parameters_Foci[p] << fixed << setprecision(6) << showpoint;
        QString ST_Stream_Par_Current = ST_Stream_Par_BasePath + QSL_Parameter_Suffixes[p] + ".csv";
        OS_Stream_Parameters[p].open(ST_Stream_Par_Current.toStdString());
    }
*/

/*    Stream_Open_Foci = true;

    Stream_Init_foci_in_time();
*/
}

void m_makro_foci::Stream_Init_foci_in_time_full()
{
    OS_Stream_Foci_Info << "labeled foci info\n";
    OS_Stream_Foci_Info << "\n";
}

void m_makro_foci::Save_info_full()
{
    for(unsigned int label = 0; label < static_cast<unsigned int>(FeatureFoci_nb_label); label++){
//        qDebug()<<"\nlabel ="<<label;
        OS_Stream_Foci_Info << "label : ," << label;
        OS_Stream_Foci_Info << "\n,, time :,";
        for(int t=0;t<Size_image_in_time;t++)
            OS_Stream_Foci_Info <<t<<",";
        OS_Stream_Foci_Info << "\n,, Intensity :,";
        for(int t=0;t<Size_image_in_time;t++)
            OS_Stream_Foci_Info << vvvFeatureFoci[label][t][c_ST_Feature_Foci_Intensity] <<",";
        OS_Stream_Foci_Info << "\n,, state :,";
        for(int t=0;t<Size_image_in_time;t++)
            OS_Stream_Foci_Info << vvvFeatureFoci[label][t][c_sT_Feature_Foci_state] <<",";
        OS_Stream_Foci_Info << "\n,, Coord X :,";
        for(int t=0;t<Size_image_in_time;t++)
            OS_Stream_Foci_Info << vvvFeatureFoci[label][t][c_sT_Feature_Foci_coordX] <<",";
        OS_Stream_Foci_Info << "\n,, Coord Y :,";
        for(int t=0;t<Size_image_in_time;t++)
            OS_Stream_Foci_Info << vvvFeatureFoci[label][t][c_sT_Feature_Foci_coordY] <<",";
        OS_Stream_Foci_Info << "\n";
    }
}

void m_makro_foci::Stream_End_foci_in_time_full()
{
    if(!Stream_Open_Foci)
        return;

    OS_Stream_Foci_Info.close();

    Stream_Open_Foci = false;
}

int m_makro_foci::Save_csv_file_full()
{
    Stream_Open_foci_in_time();
    Stream_Init_foci_in_time();

    Save_info_full();

    Stream_End_foci_in_time();


  return 0;
}

//------------------------------------------------------------------------------------
// ----------------------------------  Select Bckgd area -----------------------------
//------------------------------------------------------------------------------------

void m_makro_foci::Enable_disable_select_area()
{
    if(ui->checkBox_select_area->isChecked()){
        connect(&V_Nuclei_tab_Average,                            SIGNAL(MouseClicked_Pos(int,int)),          this,           SLOT(Select_bckgd_area(int, int)));
        qDebug()<<"connect";
    }
    else{
        disconnect(&V_Nuclei_tab_Average,                            SIGNAL(MouseClicked_Pos(int,int)),          this,           SLOT(Select_bckgd_area(int, int)));
        qDebug()<<"disconnect";
    }
    Update_View();
}

void m_makro_foci::Select_bckgd_area(int x, int y)
{
    if(ui->comboBox_step_av->currentIndex()==2){
//        qDebug()<<"nb_area_bckgd : "<<nb_area_bckgd;

  //      qDebug()<<"CREATION DU RECTANGLE a x= "<<x<<" y= "<<y;

        int color_circle;

        if(ui->comboBox_backgd_area->currentIndex()==0)
            color_circle = c_sT_label_bckgd_foci;
        else
            color_circle = c_sT_label_bckgd_nuclei;

        int r;
        r=ui->spinBox_size_circle_bckgd_area->value();

        int thickness =1;
//         qDebug()<<
         D_Img_Proc::Draw_Circle(&MA_Average_area,x,y,r,color_circle,thickness);

         //sauvegarder dans un tableau (x,y,r);

        vv_Feature_area_bckgd.resize(nb_area_bckgd+1);
        vv_Feature_area_bckgd[nb_area_bckgd].resize(c_sT_nb_Feature_area_bckgd);

        vv_Feature_area_bckgd[nb_area_bckgd][c_sT_area_bckgd_coord_X]=x;
        vv_Feature_area_bckgd[nb_area_bckgd][c_sT_area_bckgd_coord_Y]=y;
        vv_Feature_area_bckgd[nb_area_bckgd][c_sT_area_bckgd_radius]=r;

        if(ui->comboBox_backgd_area->currentIndex()==0)
           vv_Feature_area_bckgd[nb_area_bckgd][c_sT_area_bckgd_label]=c_sT_label_bckgd_foci;
        else
           vv_Feature_area_bckgd[nb_area_bckgd][c_sT_area_bckgd_label]=c_sT_label_bckgd_nuclei;


       nb_area_bckgd++;

       Update_View();

       //    D_Viewer::MouseClicked_Pos(PosX,PosY);

    /*    QPoint coord(x,y);
        QSize size(10,10);
        coord = mapToGlobal(coord);
        rubberBand = new QRubberBand(QRubberBand::Rectangle, this);

    //    rubberBand->setGeometry(x,y,10,10);
        rubberBand->setGeometry(QRect(coord,size));
        rubberBand->show();
    */
    }
}

void m_makro_foci::Delete_bckgd_area()
{
    vv_Feature_area_bckgd.clear();
    nb_area_bckgd=0;
    MA_Average_area = vMA_Average[0].clone();

   qDebug()<<"delete";
   Update_View();
}

void m_makro_foci::Confirm_bckgd_area()
{
    Set_MA_area_bckgd();
    Get_values_backgd();
    Update_View();

    nb_Foci_unselect_by_user=0;
    Update_Step_Results_feature();

    qDebug()<<"++++ end Confirm bckgd area";
}

void m_makro_foci::Set_MA_area_bckgd()
{
    MA_Average_area_without_bckgd=vMA_Average[0].clone();
    MA_Average_area_without_bckgd=Scalar(0);
    for(int i =0; i<nb_area_bckgd;i++)                 //D: comparing signed and unsigned is unsafe (high values of unsigned change the same bit as the sign of signed. You know what i mean?^^)
        D_Img_Proc::Draw_Circle
                (&MA_Average_area_without_bckgd,
                 vv_Feature_area_bckgd[i][c_sT_area_bckgd_coord_X],
                 vv_Feature_area_bckgd[i][c_sT_area_bckgd_coord_Y],
                 vv_Feature_area_bckgd[i][c_sT_area_bckgd_radius],
                 vv_Feature_area_bckgd[i][c_sT_area_bckgd_label],
                 FILLED);

}

void m_makro_foci::Get_values_backgd()
{
    int Wi = MA_Average_area_without_bckgd.cols; //image width
    int Hi = MA_Average_area_without_bckgd.rows; //image heigth
    int Yi;                //image position y
    int Xi;                //image position x

    int nb_pixels_Bckgd_in_nuclei=0;
    int nb_pixels_Bckgd_out_nuclei=0;

    Bckgd_in_nuclei.resize(Size_image_in_time);
    Bckgd_out_nuclei.resize(Size_image_in_time);


    for(int t=0;t<Size_image_in_time;t++){
       nb_pixels_Bckgd_in_nuclei=0;
       nb_pixels_Bckgd_out_nuclei=0;
       Bckgd_in_nuclei[t]=0;
       Bckgd_out_nuclei[t]=0;
        for(Yi=0;Yi<Hi;Yi++)
            for(Xi=0; Xi<Wi; Xi++){

                    switch (vvMA_Nuclei[c_ST_N_LOAD][t].type()) {
                    case CV_8U:
                    {
                        if(MA_Average_area_without_bckgd.at<uchar>(Yi,Xi) == c_sT_label_bckgd_foci){
                            nb_pixels_Bckgd_in_nuclei++;
                            Bckgd_in_nuclei[t] += vvMA_Nuclei[c_ST_N_LOAD][t].at<uchar>(Yi,Xi);
        //                    qDebug()<<Bckgd_in_nuclei[t]<<" ";
                        }
                        else if (MA_Average_area_without_bckgd.at<uchar>(Yi,Xi) == c_sT_label_bckgd_nuclei){
                            nb_pixels_Bckgd_out_nuclei++;
                            Bckgd_out_nuclei[t] += vvMA_Nuclei[c_ST_N_LOAD][t].at<uchar>(Yi,Xi);
        //                    Bckgd_out_nuclei[t] += vMA_Average[0].at<uchar>(Yi,Xi);
                        }

                        if(MA_Average_area_without_bckgd.at<uchar>(Yi,Xi) == c_sT_label_bckgd_foci){
                            nb_pixels_Bckgd_in_nuclei++;
                            Bckgd_in_nuclei[t] += vvMA_Nuclei[c_ST_N_LOAD][t].at<uchar>(Yi,Xi);
        //                    qDebug()<<Bckgd_in_nuclei[t]<<" ";

                        }
                        else if (MA_Average_area_without_bckgd.at<uchar>(Yi,Xi) == c_sT_label_bckgd_nuclei){
                            nb_pixels_Bckgd_out_nuclei++;
                            Bckgd_out_nuclei[t] += vvMA_Nuclei[c_ST_N_LOAD][t].at<uchar>(Yi,Xi);
        //                    Bckgd_out_nuclei[t] += vMA_Average[0].at<uchar>(Yi,Xi);
                        }

                    }
                    break;
                    case CV_16U:
                    {
                        if(MA_Average_area_without_bckgd.at<uchar>(Yi,Xi) == c_sT_label_bckgd_foci){
                            nb_pixels_Bckgd_in_nuclei++;
                            Bckgd_in_nuclei[t] += vvMA_Nuclei[c_ST_N_LOAD][t].at<ushort>(Yi,Xi);
        //                    qDebug()<<Bckgd_in_nuclei[t]<<" ";
                        }
                        else if (MA_Average_area_without_bckgd.at<uchar>(Yi,Xi) == c_sT_label_bckgd_nuclei){
                            nb_pixels_Bckgd_out_nuclei++;
                            Bckgd_out_nuclei[t] += vvMA_Nuclei[c_ST_N_LOAD][t].at<ushort>(Yi,Xi);
        //                    Bckgd_out_nuclei[t] += vMA_Average[0].at<uchar>(Yi,Xi);
                        }

                        if(MA_Average_area_without_bckgd.at<uchar>(Yi,Xi) == c_sT_label_bckgd_foci){
                            nb_pixels_Bckgd_in_nuclei++;
                            Bckgd_in_nuclei[t] += vvMA_Nuclei[c_ST_N_LOAD][t].at<ushort>(Yi,Xi);
        //                    qDebug()<<Bckgd_in_nuclei[t]<<" ";

                        }
                        else if (MA_Average_area_without_bckgd.at<uchar>(Yi,Xi) == c_sT_label_bckgd_nuclei){
                            nb_pixels_Bckgd_out_nuclei++;
                            Bckgd_out_nuclei[t] += vvMA_Nuclei[c_ST_N_LOAD][t].at<ushort>(Yi,Xi);
        //                    Bckgd_out_nuclei[t] += vMA_Average[0].at<uchar>(Yi,Xi);
                        }

                    }
                        break;
                }


            }
        if (nb_pixels_Bckgd_in_nuclei != 0)
            Bckgd_in_nuclei[t] = Bckgd_in_nuclei[t] / nb_pixels_Bckgd_in_nuclei;
        if (nb_pixels_Bckgd_out_nuclei != 0)
            Bckgd_out_nuclei[t] = Bckgd_out_nuclei[t]  / nb_pixels_Bckgd_out_nuclei;

//            qDebug()<<"Bckgd_out_nuclei = "<<Bckgd_out_nuclei[t];
//            qDebug()<<"Bckgd_in_nuclei = "<<Bckgd_in_nuclei[t];

//            qDebug()<<"nb_pixels_Bckgd_out_nuclei = "<< nb_pixels_Bckgd_out_nuclei;
//            qDebug()<<"nb_pixels_Bckgd_in_nuclei = "<< nb_pixels_Bckgd_in_nuclei;
    }
    qDebug()<<Bckgd_in_nuclei.size();
    qDebug()<<D_Stat::Calc_Stats(&v_stats_bckgd_in,Bckgd_in_nuclei,1);
    qDebug()<<"variance = "<< v_stats_bckgd_in[c_STAT_VARIANCE_TOTAL];

    Flag_selected_Bckgd = true;
    Enable_Foci_Features_Tab();
}

void m_makro_foci::Enable_Foci_Features_Tab()
{
    ui->tabWidget->setTabEnabled(3,true);
    ui->tabWidget->setTabEnabled(4,true);

    ui->tabWidget->setTabToolTip(3,QString(""));
    ui->tabWidget->setTabToolTip(4,QString(""));

}

//------------------------------------------------------------------------------------
// ----------------------------------  Add foci user   -------------------------------
//------------------------------------------------------------------------------------

void m_makro_foci::Init_add_focus_user()
{
    qDebug()<<"Init_add_focus_user() 1";
    MA_Max_proj_add_focus = vMA_Average[c_sT_Max_Proj_T_positives].clone();
    cvtColor(MA_Max_proj_add_focus,MA_Max_proj_add_focus,CV_GRAY2BGR); // source, dest

    int label_selected;
    for (int label=1;label<FeatureFoci_nb_label_selected;label++){
        label_selected=LabelFociSelected_To_LabelFoci[label];
 /*       ERR(D_Img_Proc::Draw_Circle(&MA_Max_proj_add_focus,
                                vvvFeatureFoci[label_selected][Size_image_in_time-1][c_sT_Feature_Foci_coordX],
                                vvvFeatureFoci[label_selected][Size_image_in_time-1][c_sT_Feature_Foci_coordY],
                                ui->spinBox_radius_circle_intensity->value(),
                                255,
                                1));
 */

        circle(
                    MA_Max_proj_add_focus,
                    Point(vvvFeatureFoci[label_selected][Size_image_in_time-1][c_sT_Feature_Foci_coordX]
                    ,vvvFeatureFoci[label_selected][Size_image_in_time-1][c_sT_Feature_Foci_coordY]),
                    ui->spinBox_radius_circle_intensity->value(),
                    Scalar(255,0,0),
                    1,
                    LINE_8,
                    0);
   }
    qDebug()<<"Init_add_focus_user() 2";
    for (int label=0;label<nb_Foci_added_by_user;label++){
/*       ERR( D_Img_Proc::Draw_Circle(&MA_Max_proj_add_focus,
                                Foci_added_by_user[label][0],
                                Foci_added_by_user[label][1],
                                Foci_added_by_user[label][2],
                                127,
                                1));
*/        circle(
                    MA_Max_proj_add_focus,
                    Point(Foci_added_by_user[label][0]
                    ,Foci_added_by_user[label][1]),
                    ui->spinBox_radius_circle_intensity->value(),
                    Scalar(0,255,0),
                    1,
                    LINE_8,
                    0);
    }
    qDebug()<<"Init_add_focus_user() 3";

}

void m_makro_foci::Delete_added_foci_user()
{
    qDebug()<<"     -----> Delete_added_foci_user";

    // Un select added foci by user
    int label_focus_added;
    for(int label =0; label <nb_Foci_added_by_user; label++){
        label_focus_added=vFoci_added[label];
        qDebug()<<"label unselected = "<<label_focus_added;
        for(int t=0;t<Size_image_in_time;t++){
            vvvFeatureFoci[label_focus_added][t][c_sT_Feature_Foci_selected]=false;

        }
    }
    Foci_added_by_user.resize(0);
    FeatureFoci_nb_label-=nb_Foci_added_by_user;
//    vvvFeatureFoci.resize(FeatureFoci_nb_label);
    nb_Foci_added_by_user=0;

    Update_Step_Results_feature();
    Update_selected_centroid();
    Circled_selected_centroid();

    MA_Max_proj_add_focus = vMA_Average[c_sT_Max_Proj_T_positives].clone();
    cvtColor(MA_Max_proj_add_focus,MA_Max_proj_add_focus,CV_GRAY2BGR); // source, dest
    int label_selected;
    for (int label=1;label<FeatureFoci_nb_label_selected;label++){
        label_selected=LabelFociSelected_To_LabelFoci[label];
/*        ERR(D_Img_Proc::Draw_Circle(&MA_Max_proj_add_focus,
                                vvvFeatureFoci[label_selected][Size_image_in_time-1][c_sT_Feature_Foci_coordX],
                                vvvFeatureFoci[label_selected][Size_image_in_time-1][c_sT_Feature_Foci_coordY],
                                ui->spinBox_radius_circle_intensity->value(),
                                255,
                                1));
*/
        circle(
                    MA_Max_proj_add_focus,
                    Point(vvvFeatureFoci[label_selected][Size_image_in_time-1][c_sT_Feature_Foci_coordX]
                    ,vvvFeatureFoci[label_selected][Size_image_in_time-1][c_sT_Feature_Foci_coordY]),
                    ui->spinBox_radius_circle_intensity->value(),
                    Scalar(255,0,0),
                    1,
                    LINE_8,
                    0);
    }

    Update_View();
}

void m_makro_foci::Add_focus_user(int x, int y)
{
    qDebug()<<"Focus coordinate x= "<<x<<" y= "<<y;
    int color_circle = 127;
    int r;
    r=ui->spinBox_radius_circle_intensity->value();

    color_circle;
    // After confirmation : resize
    //Nb foci +1;
    //

    Foci_added_by_user.resize(nb_Foci_added_by_user+1);
    Foci_added_by_user[nb_Foci_added_by_user].resize(3);
    Foci_added_by_user[nb_Foci_added_by_user][0]=x;
    Foci_added_by_user[nb_Foci_added_by_user][1]=y;
    Foci_added_by_user[nb_Foci_added_by_user][2]=r;
    nb_Foci_added_by_user++;

    int thickness =1;
    thickness;
    qDebug()<<"nb_Foci_added_by_user="<<nb_Foci_added_by_user;
//     D_Img_Proc::Draw_Circle(&MA_Max_proj_add_focus,Foci_added_by_user[nb_Foci_added_by_user-1][0],y,r,color_circle,thickness);
    circle(
                MA_Max_proj_add_focus,
                Point(x,y),
                ui->spinBox_radius_circle_intensity->value(),
                Scalar(0,255,0),
                1,
                LINE_8,
                0);

    Update_View();

}

void m_makro_foci::Confirm_Added_focus_user()
{
//    qDebug()<<"Size of FeatureFoci_nb_label :"<<;
//    vvvFeatureFoci.resize(FeatureFoci_nb_label+nb_Foci_added_by_user);
    qDebug()<<"FeatureFoci_nb_label"<<FeatureFoci_nb_label;
    qDebug()<<"nb_Foci_added_by_user"<<nb_Foci_added_by_user;
//    vvvFeatureFoci.resize(FeatureFoci_nb_label+nb_Foci_added_by_user+1);
    int cpt=0;
    vFoci_added.resize(nb_Foci_added_by_user);
    for(int label=FeatureFoci_nb_label;label<FeatureFoci_nb_label+nb_Foci_added_by_user;label++){
            qDebug()<<"label "<<label <<"< "<< FeatureFoci_nb_label+nb_Foci_added_by_user;
        vvvFeatureFoci[label].resize(Size_image_in_time);
        for (int t=0;t<Size_image_in_time;t++){
            qDebug()<<"t "<<t;
            qDebug()<<"vvvFeatureFoci[label][t][c_sT_Feature_Foci_coordX]="<<vvvFeatureFoci[label][t][c_sT_Feature_Foci_coordX];
            qDebug()<<"Foci_added_by_user[cpt][0]"<<Foci_added_by_user[cpt][0];

            vvvFeatureFoci[label][t][c_sT_Feature_Foci_coordX]=Foci_added_by_user[cpt][0];//nb_Foci_added_by_user-1
            vvvFeatureFoci[label][t][c_sT_Feature_Foci_coordY]=Foci_added_by_user[cpt][1];
        }
         vFoci_added[cpt]=label;
         cpt++;
        qDebug()<<"vvvFeatureFoci["<<label<<"][0][c_sT_Feature_Foci_coordX]="<<vvvFeatureFoci[label][0][c_sT_Feature_Foci_coordX];//nb_Foci_added_by_user-1

    }
    FeatureFoci_nb_label+=nb_Foci_added_by_user;
    Update_Step_Results_feature();
    Update_selected_centroid();
    Circled_selected_centroid();

}
//------------------------------------------------------------------------------------
// ----------------------------------  Update patameters  ----------------------------
//------------------------------------------------------------------------------------

void m_makro_foci::on_pushButton_02_default_values_clicked()
{
    ui->spinBox_03_Mask_size->setValue(2);
    ui->spinBox_03_Offset->setValue(-13);
}

//------------------------------------------------------------------------------------
// ----------------------------------  Others ----------------------------------------
//------------------------------------------------------------------------------------

void m_makro_foci::Dilatation_centroid_labeled()
{
    int             morph_type = MORPH_DILATE;
    int             elem_type = MORPH_ELLIPSE;
    unsigned int    size_x      = ui->spinBox_radius_circle_intensity->value(); //c_sT_radius_circle;
    unsigned int    size_y      = ui->spinBox_radius_circle_intensity->value(); //c_sT_radius_circle;
    unsigned int    iterations =1;
    int             border_type =BORDER_CONSTANT;

    for(int t=0;t<Size_image_in_time;t++){
        ERR(D_Img_Proc::Morphology_Elemental(

                &vvMA_Nuclei[c_sT_N_Label_in_time_dilated][t],
                &vvMA_Nuclei[c_sT_N_Label_in_time][t],
                morph_type,
                elem_type,
                size_x,
                size_y,
                border_type,
                iterations));
    }
}

void m_makro_foci::Black_Bckgd_2_white(int step)
{
    for(int t=0;t<Size_image_in_time;t++){
        for(int Yi=0; Yi<vvMA_Nuclei[step][t].rows;Yi++)
            for(int Xi=0; Xi<vvMA_Nuclei[step][t].cols;Xi++)
                if(vvMA_Nuclei[step][t].at<uchar>(Yi,Xi)==0){
                vvMA_Nuclei[step][t].at<uchar>(Yi,Xi)=255;
                }

    }
}

void m_makro_foci::on_comboBox_step_av_currentIndexChanged(int index)
{
    qDebug()<<"ui->horizontalSlider_Image_in_Time->set";
    switch(index){
    case e_AV_IMG_ORIGINAL:
        ui->horizontalSlider_Image_in_Time->setEnabled(true);
        break;
    case e_AV_IMG_BLUR:
        ui->horizontalSlider_Image_in_Time->setEnabled(true);
        break;
    case e_AV_IMG_AVERAGE_IMAGE:
        ui->horizontalSlider_Image_in_Time->setEnabled(false);
        break;
    case e_AV_IMG_THRESHOLD:
        ui->horizontalSlider_Image_in_Time->setEnabled(false);
        break;
    case e_AV_IMG_REDUCE_CENTROID:
        ui->horizontalSlider_Image_in_Time->setEnabled(false);
        break;
    case e_AV_IMG_LABEL_MASK:
        ui->horizontalSlider_Image_in_Time->setEnabled(false);
        break;
    }
}

void m_makro_foci::Update_displayed_time()
{
    ui->spinBox_displayed_time->setValue(v_Time_scale[ui->horizontalSlider_Image_in_Time_curves->value()]);
}


//------------------------------------------------------------------------------------
// ----------------------------------  Nucleus edges ---------------------------------
//------------------------------------------------------------------------------------

void m_makro_foci::Nucleus_edges()
{
    for(int t=0;t<Size_image_in_time;t++){

        if (ui->checkBox_nucleus_contour->isChecked()==false){        // if user doesn't want to use the coutour because it is not accurate
            vvMA_Nuclei[c_ST_N_Convex_hull][t]=255;
            vvMA_Nuclei[c_ST_N_Contour_nuclei][t]=vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][t].clone();
        }

        else {
            // Gamma spread

            ERR(D_Img_Proc::GammaSpread(
                    &vvMA_Nuclei[c_ST_N_Otsu_threshold][t],
                    &vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][t],// c_ST_N_INPUT_CONV_16BIT
                    0.5,
                    0,
                    255,
                    0,
                    255));


            // threshold Automatic Otsu
        ERR(D_Img_Proc::Combi_8UC1_binary(&vvMA_Nuclei[c_ST_N_Otsu_threshold][t],
                                          &vvMA_Nuclei[c_ST_N_Otsu_threshold][t]));
            // Reduce to Convex Hull
        ERR(D_Img_Proc::Reduce_Geometric(&vvMA_Nuclei[c_ST_N_Convex_hull][t],
                                         &vvMA_Nuclei[c_ST_N_Otsu_threshold][t],
                                         c_GEO_CONVEX_HULL,
                                         4,
                                         1,
                                         1)); //value pixel =1
            // Fill holes
        ERR(D_Img_Proc::Fill_Holes(&vvMA_Nuclei[c_ST_N_Convex_hull][t], &vvMA_Nuclei[c_ST_N_Convex_hull][t]));


        // --> take the component with the bigger area

        ERR(Feature_biggest_area(&vvMA_Nuclei[c_ST_N_Convex_hull][t],
                                &vvMA_Nuclei[c_ST_N_Convex_hull][t],
                                c_FEAT_CONVEX_AREA));
        // --> create an image with this component.
            // if component, value = 255
            // if not, value =0
        // Contour
        ERR(D_Img_Proc::Reduce_Contours(&vvMA_Nuclei[c_ST_N_Contour_nuclei][t],
                                    &vvMA_Nuclei[c_ST_N_Convex_hull][t],
                                    1));




    // Add contour + image --> plot this image to have a visual check

        ERR(D_Img_Proc::Math_ImgImg_Add(&vvMA_Nuclei[c_ST_N_Contour_nuclei][t], &vvMA_Nuclei[c_ST_N_Contour_nuclei][t], &vvMA_Nuclei[c_ST_N_INPUT_CONV_8BIT][t]));
        }
    }
}

int m_makro_foci::Feature_biggest_area(Mat *pMA_Out, Mat *pMA_In, int feature)
{
    if(pMA_In->empty())                                                                             return ER_empty;
    if(pMA_In->channels() != 1)                                                                     return ER_channel_bad;
    if((pMA_In->depth() != CV_8U) && (pMA_In->depth() != CV_32S) && (pMA_In->depth() != CV_16U))    return ER_bitdepth_bad;
    if(feature >= c_FEAT_NUMBER_OF_FEATS || feature < 0)                                            return ER_parameter_bad;
    int connectivity = 4;

    int ER;

    //split
    D_Component_List CompList;
    ER = CompList.set_Mat(pMA_In, connectivity);
    if(ER != ER_okay)   return ER;

    //get Features
    vector<double> v_Features = CompList.get_FeatureVector_BG(feature);

    //create LUT
    vector<int> v_LUT;
    v_LUT.resize(v_Features.size(), 0);

    //add false(0) for background
    v_LUT[0] = 0;

    //calc LUT (but not for background -> start at 1 not 0)
    float nb_pixel = 0;
    int Component_choose = 1;
    for(int i = 1; i < v_Features.size(); i++){
        if((nb_pixel < v_Features[i])){
            Component_choose=i;
            nb_pixel = v_Features[i];
        }
        qDebug() << "feature" << feature << QSL_FeatureList[feature] << "number" << i << "value" << v_Features[i] << "result" << v_LUT[i];
    }

    v_LUT[Component_choose] = 255;

    //apply LUT
    ER = D_Img_Proc::LUT_Apply_to_Label_Binary(
                pMA_Out,
                CompList.get_pMatLabels(),
                v_LUT);
    if(ER != ER_okay)   return ER;

    return ER_okay;
}


//------------------------------------------------------------------------------------
// -------------------------------  Parameters changed  ------------------------------
//------------------------------------------------------------------------------------


void m_makro_foci::Threshold_parameters_changed()
{
    this->setEnabled(true);
    ui->label_state_current->setText("Busy");
    this->repaint();
    this->setEnabled(false);
    Threshold();
    Reduction();

    this->setEnabled(true);
    ui->label_state_current->setText("Ready");
    Update_View();

    ui->pushButton_update->setAutoFillBackground(true);
    ui->pushButton_update->setStyleSheet("background-color: rgb(97, 255, 24)");
    ui->pushButton_update->show();
}

void m_makro_foci::Settings_parameters_changed()
{
    Convert();
    Update_View();

    ui->pushButton_Update_all_from_convert->setAutoFillBackground(true);
    ui->pushButton_Update_all_from_convert->setStyleSheet("background-color: rgb(97, 255, 24)");
    ui->pushButton_Update_all_from_convert->show();
}

void m_makro_foci::Foci_tracking_parameters_changed()
{
    Update_View();

    ui->pushButton_update->setAutoFillBackground(true);
    ui->pushButton_update->setStyleSheet("background-color: rgb(97, 255, 24)");
    ui->pushButton_update->show();
}

void m_makro_foci::Foci_feature_parameters_changed()
{
    Update_View();
    ui->pushButton_update->setAutoFillBackground(true);
    ui->pushButton_update->setStyleSheet("background-color: rgb(97, 255, 24)");
    ui->pushButton_update->show();
}

void m_makro_foci::resize_array(vector<double> *v_value, int size)
{
    v_value->resize(size);
}

void m_makro_foci::resize_array(vector<vector<double>> *vv_value, int size1, int size2)
{
    vv_value->resize(size1);
    for(int i=0;i<size1;i++)
        (*vv_value)[i].resize(size2);
}

void m_makro_foci::resize_array(vector<vector<vector<double>>> *vvv_value, int size1, int size2, int size3)
{
    vvv_value->resize(size1);
    for(int i=0;i<size1;i++){
        (*vvv_value)[i].resize(size2);
            for(int j=0;j<size2;j++)
                (*vvv_value)[i][j].resize(size3);

    }
}
