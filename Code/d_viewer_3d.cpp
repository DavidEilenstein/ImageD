/************************************
 *   added:     27.07.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_viewer_3d.h"

D_Viewer_3D::D_Viewer_3D()
{

}

D_Viewer_3D::D_Viewer_3D(QGridLayout *target_layout)
{
    init(target_layout);
}

D_Viewer_3D::~D_Viewer_3D()
{

}

void D_Viewer_3D::init(QGridLayout *target_layout)
{
    if(state_ui_init)
        return;

    //-------------------------------------------------------------- layouts and groupboxes

    //target layout
    ui_layout_target = target_layout;

    //groupboxes

    //graph
    ui_GroupBox_3D_graph = new QGroupBox("3D Volume", this);
    ui_GroupBox_3D_graph->setLayout(new QGridLayout(this));
    ui_layout_target->addWidget(ui_GroupBox_3D_graph, 0, 0);
    QSizePolicy sizepol_factor2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    sizepol_factor2.setHorizontalStretch(2);
    ui_GroupBox_3D_graph->setSizePolicy(sizepol_factor2);
    ui_GroupBox_3D_graph->layout()->setSpacing(1);
    ui_GroupBox_3D_graph->layout()->setContentsMargins(1, 1, 1, 1);

    //slices
    ui_GroupBox_2D_slices = new QGroupBox("2D Sices", this);
    ui_GroupBox_2D_slices->setLayout(new QGridLayout(this));
    ui_layout_target->addWidget(ui_GroupBox_2D_slices, 0, 1);
    QSizePolicy sizepol_factor1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    sizepol_factor1.setHorizontalStretch(1);
    ui_GroupBox_2D_slices->setSizePolicy(sizepol_factor1);
    ui_GroupBox_2D_slices->layout()->setSpacing(1);
    ui_GroupBox_2D_slices->layout()->setContentsMargins(1, 1, 1, 1);
    ui_GroupBox_2D_slices->setVisible(false);

    //settings
    ui_GroupBox_Settings = new QGroupBox("Settings", this);
    ui_GroupBox_Settings->setLayout(new QVBoxLayout(this));
    ui_layout_target->addWidget(ui_GroupBox_Settings, 0, 2);
    ui_GroupBox_Settings->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
    ui_GroupBox_Settings->layout()->setSpacing(3);
    ui_GroupBox_Settings->layout()->setContentsMargins(1, 1, 1, 1);

    //volume
    ui_GroupBox_Settings_Volume = new QGroupBox("Volume", this);
    ui_GroupBox_Settings_Volume->setLayout(new QVBoxLayout(this));
    ui_GroupBox_Settings->layout()->addWidget(ui_GroupBox_Settings_Volume);
    ui_GroupBox_Settings_Volume->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    ui_GroupBox_Settings_Volume->layout()->setSpacing(1);
    ui_GroupBox_Settings_Volume->layout()->setContentsMargins(1, 1, 1, 1);

    //draw condition
    /*
    ui_GroupBox_Settings_DrawCondition = new QGroupBox("Draw Condition", this);
    ui_GroupBox_Settings_DrawCondition->setLayout(new QVBoxLayout(this));
    ui_GroupBox_Settings->layout()->addWidget(ui_GroupBox_Settings_DrawCondition);
    ui_GroupBox_Settings_DrawCondition->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    ui_GroupBox_Settings_DrawCondition->layout()->setSpacing(1);
    ui_GroupBox_Settings_DrawCondition->layout()->setContentsMargins(1, 1, 1, 1);
    */

    //alpha
    ui_GroupBox_Settings_Alpha = new QGroupBox("Alpha", this);
    ui_GroupBox_Settings_Alpha->setLayout(new QVBoxLayout(this));
    ui_GroupBox_Settings->layout()->addWidget(ui_GroupBox_Settings_Alpha);
    ui_GroupBox_Settings_Alpha->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    ui_GroupBox_Settings_Alpha->layout()->setSpacing(1);
    ui_GroupBox_Settings_Alpha->layout()->setContentsMargins(1, 1, 1, 1);

    //appearance

    //slices
    ui_GroupBox_Settings_Graphics = new QGroupBox("Graphics", this);
    ui_GroupBox_Settings_Graphics->setLayout(new QVBoxLayout(this));
    ui_GroupBox_Settings->layout()->addWidget(ui_GroupBox_Settings_Graphics);
    ui_GroupBox_Settings_Graphics->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    ui_GroupBox_Settings_Graphics->layout()->setSpacing(1);
    ui_GroupBox_Settings_Graphics->layout()->setContentsMargins(1, 1, 1, 1);

    //animations
    ui_GroupBox_SaveAnimationVideo = new QGroupBox("Save animation video", this);
    ui_GroupBox_SaveAnimationVideo->setLayout(new QHBoxLayout(this));
    ui_GroupBox_Settings->layout()->addWidget(ui_GroupBox_SaveAnimationVideo);
    ui_GroupBox_SaveAnimationVideo->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
    ui_GroupBox_SaveAnimationVideo->layout()->setSpacing(3);
    ui_GroupBox_SaveAnimationVideo->layout()->setContentsMargins(1, 1, 1, 1);

    //save as video button
    //rotate
    ui_PushButton_SaveAnimationVideo_Rotation = new QPushButton("Rotation", this);
    ui_GroupBox_SaveAnimationVideo->layout()->addWidget(ui_PushButton_SaveAnimationVideo_Rotation);
    ui_PushButton_SaveAnimationVideo_Rotation->setFixedHeight(17);
    connect(ui_PushButton_SaveAnimationVideo_Rotation, SIGNAL(clicked()), this, SLOT(SaveVideo_CameraRotationFull()));
    //slice
    ui_PushButton_SaveAnimationVideo_Slice = new QPushButton("Slicing", this);
    ui_GroupBox_SaveAnimationVideo->layout()->addWidget(ui_PushButton_SaveAnimationVideo_Slice);
    ui_PushButton_SaveAnimationVideo_Slice->setFixedHeight(17);
    connect(ui_PushButton_SaveAnimationVideo_Slice, SIGNAL(clicked()), this, SLOT(SaveVideo_SliceDim()));

    //spacer
    ui_spacer_Settings = new QSpacerItem(1, 1, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
    ui_GroupBox_Settings->layout()->addItem(ui_spacer_Settings);

    //-------------------------------------------------------------- control elements

    //volume & dim indices

    //volume
    ui_ComboBox_Volume = new QComboBox(this);
    ui_GroupBox_Settings_Volume->layout()->addWidget(ui_ComboBox_Volume);
    Populate_CB_Single(ui_ComboBox_Volume, QSL_Volumes, c_VOLUME_XYZ);
    connect(ui_ComboBox_Volume, SIGNAL(currentIndexChanged(int)), this, SLOT(on_VolumeCurrent_Changed(int)));
    connect(ui_ComboBox_Volume, SIGNAL(currentIndexChanged(int)), this, SLOT(Update_Graph()));

    //dims
    vui_SpinBox_DimIndices.reserve(c_DIM_NUMBER_OF);
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
    {
        vui_SpinBox_DimIndices[d] = new QSpinBox(this);
        vui_SpinBox_DimIndices[d]->setPrefix(QSL_DimIndices[d] + "=");
        vui_SpinBox_DimIndices[d]->setButtonSymbols(QSpinBox::ButtonSymbols::NoButtons);
        ui_GroupBox_Settings_Volume->layout()->addWidget(vui_SpinBox_DimIndices[d]);        
        connect(vui_SpinBox_DimIndices[d], SIGNAL(valueChanged(int)), this, SLOT(check_volume_changes_and_trigger_slots()));
    }

    //Slices
    vui_GraphicsView_Slices2D.reserve(SLICE_2D_NUMBER_OF);
    vViewer_Slices2D = {&Viewer_Slice2D_X, &Viewer_Slice2D_Y, &Viewer_Slice2D_Z};
    for(int i = 0; i < SLICE_2D_NUMBER_OF; i++)
    {
        vui_GraphicsView_Slices2D[i] = new QGraphicsView(this);
        ui_GroupBox_2D_slices->layout()->addWidget(vui_GraphicsView_Slices2D[i]);
        vViewer_Slices2D[i]->set_GV(vui_GraphicsView_Slices2D[i]);
        vui_GraphicsView_Slices2D[i]->setSizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        vui_GraphicsView_Slices2D[i]->setStyleSheet("background-color: " + D_Img_Proc::Color2Text4StyleSheet(Qt::darkGreen) + ";");
        vui_GraphicsView_Slices2D[i]->setMouseTracking(true);
    }

    //Slices
    /*
    ui_Label_2dSlice_XY = new QLabel(this);
    ui_Label_2dSlice_XZ = new QLabel(this);
    ui_Label_2dSlice_YZ = new QLabel(this);
    vui_Label_2dSlices = {ui_Label_2dSlice_YZ, ui_Label_2dSlice_XZ, ui_Label_2dSlice_XY};
    for(int i = 0; i < 3; i++)
    {
        ui_GroupBox_2D_slices->layout()->addWidget(vui_Label_2dSlices[i]);
        vui_Label_2dSlices[i]->setSizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        vui_Label_2dSlices[i]->setStyleSheet("background-color: " + D_Img_Proc::Color2Text4StyleSheet(Qt::darkGreen) + ";");
    }*/

    //settings

    //alpha

    //mode
    ui_ComboBox_AlphaMode = new QComboBox(this);
    ui_GroupBox_Settings_Alpha->layout()->addWidget(ui_ComboBox_AlphaMode);
    Populate_CB_Single(ui_ComboBox_AlphaMode, QSL_Viewer3D_Alpha, c_VIEWER_3D_ALPHA_CHANNEL_MEAN);
    connect(ui_ComboBox_AlphaMode, SIGNAL(currentIndexChanged(int)), this, SLOT(Update_Graph()));

    //multiplier
    ui_DoubleSpinBox_AlphaMultiplier = new QDoubleSpinBox(this);
    ui_GroupBox_Settings_Alpha->layout()->addWidget(ui_DoubleSpinBox_AlphaMultiplier);
    ui_DoubleSpinBox_AlphaMultiplier->setDecimals(3);
    ui_DoubleSpinBox_AlphaMultiplier->setRange(0, 100);
    ui_DoubleSpinBox_AlphaMultiplier->setValue(1);
    ui_DoubleSpinBox_AlphaMultiplier->setSingleStep(0.1);
    ui_DoubleSpinBox_AlphaMultiplier->setButtonSymbols(QDoubleSpinBox::ButtonSymbols::NoButtons);
    ui_DoubleSpinBox_AlphaMultiplier->setPrefix("multiplier=");
    connect(ui_DoubleSpinBox_AlphaMultiplier, SIGNAL(valueChanged(double)), this, SLOT(adapt_alpha_multiplier_step(double)));
    connect(ui_DoubleSpinBox_AlphaMultiplier, SIGNAL(valueChanged(double)), this, SLOT(set_alpha_multiplier(double)));

    //appearance

    //background color
    ui_PushButton_BackgroundColor = new QPushButton("Background Color", this);
    ui_GroupBox_Settings_Graphics->layout()->addWidget(ui_PushButton_BackgroundColor);
    ui_PushButton_BackgroundColor->setFixedHeight(17);
    ui_PushButton_BackgroundColor->setStyleSheet("background-color: " + D_Img_Proc::Color2Text4StyleSheet(Qt::darkGreen) + ";\ncolor: " + D_Img_Proc::Color2Text4StyleSheet(D_Img_Proc::Contrast_Color(QColor(Qt::darkGreen))) + ";");
    connect(ui_PushButton_BackgroundColor, SIGNAL(clicked()), this, SLOT(change_graph_background_color()));

    //multiplier
    ui_DoubleSpinBox_ScaleDepth = new QDoubleSpinBox(this);
    ui_GroupBox_Settings_Graphics->layout()->addWidget(ui_DoubleSpinBox_ScaleDepth);
    ui_DoubleSpinBox_ScaleDepth->setDecimals(3);
    ui_DoubleSpinBox_ScaleDepth->setRange(0.001, 100);
    ui_DoubleSpinBox_ScaleDepth->setValue(1);
    ui_DoubleSpinBox_ScaleDepth->setSingleStep(0.1);
    ui_DoubleSpinBox_ScaleDepth->setButtonSymbols(QDoubleSpinBox::ButtonSymbols::NoButtons);
    ui_DoubleSpinBox_ScaleDepth->setPrefix("Z scale = ");
    connect(ui_DoubleSpinBox_ScaleDepth, SIGNAL(valueChanged(double)), this, SLOT(adapt_depth_scale_step(double)));
    connect(ui_DoubleSpinBox_ScaleDepth, SIGNAL(valueChanged(double)), this, SLOT(set_VolumeScalingAndPosition()));

    //shadow quality
    ui_ComboBox_ShadowQuality = new QComboBox(this);
    ui_GroupBox_Settings_Graphics->layout()->addWidget(ui_ComboBox_ShadowQuality);
    Populate_CB_Single(ui_ComboBox_ShadowQuality, QSL_ShadowQuality_3D_ShadowInName, c_VIEWER_PLOT_3D_SHADOW_MEDIUM);
    connect(ui_ComboBox_ShadowQuality, SIGNAL(currentIndexChanged(int)), this, SLOT(set_shadow_quality(int)));

    //heat color
    ui_CheckBox_HeatColor = new QCheckBox("Heat Color", this);
    ui_GroupBox_Settings_Graphics->layout()->addWidget(ui_CheckBox_HeatColor);
    connect(ui_CheckBox_HeatColor, SIGNAL(toggled(bool)), this, SLOT(Update_Graph()));

    //shader
    ui_CheckBox_Shader_HD = new QCheckBox("Use HD Shader", this);
    //ui_GroupBox_Settings_Graphics->layout()->addWidget(ui_CheckBox_Shader_HD);
    connect(ui_CheckBox_Shader_HD, SIGNAL(toggled(bool)), this, SLOT(set_HD_shader(bool)));

    //opacity
    ui_CheckBox_OpacityPreserve = new QCheckBox("Preserve Opacity", this);
    //ui_GroupBox_Settings_Graphics->layout()->addWidget(ui_CheckBox_OpacityPreserve);
    connect(ui_CheckBox_OpacityPreserve, SIGNAL(toggled(bool)), this, SLOT(set_preserve_opacity(bool)));




    //slices

    //show
    ui_CheckBox_Slices_Show = new QCheckBox("Show Slices", this);
    ui_GroupBox_Settings_Graphics->layout()->addWidget(ui_CheckBox_Slices_Show);
    connect(ui_CheckBox_Slices_Show, SIGNAL(toggled(bool)), ui_GroupBox_2D_slices, SLOT(setVisible(bool)));
    connect(ui_CheckBox_Slices_Show, SIGNAL(toggled(bool)), this, SLOT(set_draw_slices(bool)));
    connect(ui_CheckBox_Slices_Show, SIGNAL(toggled(bool)), this, SLOT(Update_Slices()));

    //slice volume
    ui_CheckBox_Slices_SliceVolume = new QCheckBox("Cut Volume", this);
    ui_GroupBox_Settings_Graphics->layout()->addWidget(ui_CheckBox_Slices_SliceVolume);
    ui_CheckBox_Slices_SliceVolume->setEnabled(false);
    connect(ui_CheckBox_Slices_SliceVolume, SIGNAL(toggled(bool)), this, SLOT(Update_Slices()));
    connect(ui_CheckBox_Slices_Show, SIGNAL(toggled(bool)), ui_CheckBox_Slices_SliceVolume, SLOT(setEnabled(bool)));

    //slice volume
    ui_CheckBox_Slices_KeepAspectRatio = new QCheckBox("Keep Aspect Ratio", this);
    ui_GroupBox_Settings_Graphics->layout()->addWidget(ui_CheckBox_Slices_KeepAspectRatio);
    ui_CheckBox_Slices_KeepAspectRatio->setChecked(true);
    ui_CheckBox_Slices_KeepAspectRatio->setEnabled(false);
    connect(ui_CheckBox_Slices_KeepAspectRatio, SIGNAL(toggled(bool)), &Viewer_Slice2D_X, SLOT(Set_Aspect_Mode(bool)));
    connect(ui_CheckBox_Slices_KeepAspectRatio, SIGNAL(toggled(bool)), &Viewer_Slice2D_Y, SLOT(Set_Aspect_Mode(bool)));
    connect(ui_CheckBox_Slices_KeepAspectRatio, SIGNAL(toggled(bool)), &Viewer_Slice2D_Z, SLOT(Set_Aspect_Mode(bool)));
    connect(ui_CheckBox_Slices_Show, SIGNAL(toggled(bool)), ui_CheckBox_Slices_KeepAspectRatio, SLOT(setEnabled(bool)));

    //-------------------------------------------------------------- graph

    //graph
    graph_scatter = new Q3DScatter();

    //graph container
    container_widget_scatter = createWindowContainer(graph_scatter);
    ui_GroupBox_3D_graph->layout()->addWidget(container_widget_scatter);



    //-------------------------------------------------------------- other

    //defaults for visuals

    //graph
    graph_scatter->setOrthoProjection(true);
    graph_scatter->setShadowQuality(QAbstract3DGraph::ShadowQualityMedium);
    graph_scatter->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetIsometricRightHigh);
    //graph_scatter->scene()->activeCamera()->setMaxZoomLevel(200.0f);
    graph_scatter->activeTheme()->setType(Q3DTheme::ThemeEbony);
    graph_scatter->activeTheme()->setBackgroundColor(Qt::darkGreen);
    graph_scatter->activeTheme()->setWindowColor(Qt::darkGreen);
    graph_scatter->activeTheme()->setLabelBackgroundEnabled(false);
    graph_scatter->activeTheme()->setLabelTextColor(Qt::black);

    //volume dim index selectors
    on_VolumeCurrent_Changed(c_VOLUME_XYZ);

    //-------------------------------------------------------------- volume

    //volume
    volume_item = new QCustom3DVolume;
    graph_scatter->addCustomItem(volume_item);
    volume_item->setScalingAbsolute(false);
    volume_item->setTextureFormat(QImage::Format_ARGB32);
    volume_item->setSliceFrameGaps(QVector3D(0.01f, 0.02f, 0.01f));
    volume_item->setSliceFrameThicknesses(QVector3D(0.0025f, 0.005f, 0.0025f));
    volume_item->setSliceFrameWidths(QVector3D(0.0025f, 0.005f, 0.0025f));
    volume_item->setDrawSliceFrames(true);

    //-------------------------------------------------------------- states

    state_ui_init = true;
}

void D_Viewer_3D::clear_graph()
{
    while(!graph_scatter->seriesList().isEmpty())
    {
        QScatter3DSeries *series = graph_scatter->seriesList().at(0);
        graph_scatter->removeSeries(series);
        series->dataProxy()->deleteLater();
        series->deleteLater();
    }
}

int D_Viewer_3D::set_VisDat(D_VisDat_Obj *pVD_toShow)
{
    //qDebug() << "D_Viewer_3D::set_VisDat" << "start";

    //qDebug() << "D_Viewer_3D::set_VisDat" << "error checks";
    if(!state_ui_init)                                  return ER_UiNotInit;
    if(pVD_toShow->pDim()->size_PixelCount() <= 0)      return ER_empty;

    //save pointer to VD
    //qDebug() << "D_Viewer_3D::set_VisDat" << "save pointer to VD";
    pVD_Data = pVD_toShow;
    state_VD_set = true;

    //apply dim to ui
    //qDebug() << "D_Viewer_3D::set_VisDat" << "loop dims to adapt ui";
    for(size_t d = 0; d < c_DIM_NUMBER_OF; d++)
    {
        vui_SpinBox_DimIndices[d]->blockSignals(true);
        vui_SpinBox_DimIndices[d]->setMaximum(pVD_Data->pDim()->size_Dim(d) - 1);
        vui_SpinBox_DimIndices[d]->setEnabled(vui_SpinBox_DimIndices[d]->maximum() > 0);
        vui_SpinBox_DimIndices[d]->blockSignals(false);
    }

    //heat color option
    if(ui_CheckBox_HeatColor)
        ui_CheckBox_HeatColor->setEnabled(pVD_Data->channels() == 1);

    //update graph
    //qDebug() << "D_Viewer_3D::set_VisDat" << "update graph";
    Update_Graph();

    //qDebug() << "D_Viewer_3D::set_VisDat" << "end";
    return ER_okay;
}

int D_Viewer_3D::SaveVideo_SliceDim()
{
    if(!state_VD_set || v_dims_extended.empty())
        return ER_empty;

    //set ui
    ui_CheckBox_Slices_Show->setChecked(true);
    ui_CheckBox_Slices_SliceVolume->setChecked(true);
    Update_Ui();

    //get most biggest dim that is extended as suggestion
    D_VisDat_Dim Dim = pVD_Data->Dim();
    int dim_loop = v_dims_extended[0];
    for(size_t d = 0; d < v_dims_extended.size(); d++)
        if(Dim.size_Dim(d) < Dim.size_Dim(dim_loop))
            dim_loop = d;

    //get dim to loop
    D_Popup_ListSelect pop(
                "Select dim to loop",
                &dim_loop,
                QSL_DimIndices,
                dim_loop,
                this);
    pop.exec();
    if(dim_loop < 0 || dim_loop >= c_DIM_NUMBER_OF)
        return ER_index_out_of_range;

    //get video length
    bool ok;
    int length_s = QInputDialog::getInt(
                this,
                "Video length",
                "Please select the video length in seconds",
                5,
                1,
                300,
                1,
                &ok);
    if(!ok)
        return ER_parameter_bad;

    //loop and take screenshots
    vector<Mat> vMA_Screenshots;
    int err = TakeFrames_SliceDim(&vMA_Screenshots, dim_loop);
    if(err != ER_okay)
        return err;
    if(vMA_Screenshots.empty())
        return ER_empty;
    if(vMA_Screenshots[0].empty())
        return ER_empty;

    //calc video information
    size_t n_frames = vMA_Screenshots.size();
    double fps = double(n_frames) / double(length_s);
    qDebug() << n_frames << length_s << fps;

    //get save path for video
    QString QS_DefaultPath = state_default_dir ? pStore->dir_byIndex(default_dir_index)->path() : QDir().homePath();
    QS_DefaultPath.append("/ImageD_3D_Video.avi");
    QString QS_PathOut = QFileDialog::getSaveFileName(
                this,
                "Save Video",
                QS_DefaultPath,
                tr("*.avi *.AVI"));
    qDebug() << "dialog end";
    if(QS_PathOut.isEmpty())
    {
        qDebug() << "path empty";
        return ER_empty;
    }
    qDebug() << "path not empty" << QS_PathOut;
    pStore->set_dir_byIndex(QFileInfo(QS_PathOut).dir().path(), default_dir_index);

    //prepare video
    qDebug() << "init";
    D_VideoWriter VideoWriter;
    VideoWriter.set_FPS(fps);
    VideoWriter.set_Size(vMA_Screenshots[0].size());
    VideoWriter.set_isColor(true);
    VideoWriter.set_PathOut(QS_PathOut);
    VideoWriter.init_VideoWriter();
    if(!VideoWriter.is_Init())
        return ER_StreamNotOpen;

    //write video
    qDebug() << "start";
    for(size_t f = 0; f < vMA_Screenshots.size(); f++)
        VideoWriter.AddFrame(vMA_Screenshots[f]);
    qDebug() << "end";
    VideoWriter.EndVideoWriting();

    //tell succsess
    qDebug() << "sucess";
    QMessageBox::information(
                this,
                "Saved video",
                "Your video was saved as \n" + QS_PathOut);

    qDebug() << "finish";
    return ER_okay;
}

int D_Viewer_3D::SaveVideo_CameraRotationFull()
{
    bool ok;

    int length_s = QInputDialog::getInt(
                this,
                "Video length",
                "Please select the video length in seconds",
                30,
                1,
                300,
                1,
                &ok);
    if(!ok)
        return ER_parameter_bad;

    int fps = QInputDialog::getInt(
                this,
                "Video framerate",
                "Please select the framerate in frames per second",
                48,
                1,
                100,
                1,
                &ok);
    if(!ok)
        return ER_parameter_bad;

    int n_frames = fps * length_s;

    vector<Mat> vMA_Screenshots;
    int err = TakeFrames_CameraRotationFull(&vMA_Screenshots, n_frames);
    if(err != ER_okay)
        return err;

    if(vMA_Screenshots.empty())
        return ER_empty;

    if(vMA_Screenshots[0].empty())
        return ER_empty;

    QString QS_DefaultPath = state_default_dir ? pStore->dir_byIndex(default_dir_index)->path() : QDir().homePath();
    QS_DefaultPath.append("/ImageD_3D_Video.avi");
    QString QS_PathOut = QFileDialog::getSaveFileName(
                this,
                "Save Video",
                QS_DefaultPath,
                tr("*.avi *.AVI"));
    if(QS_PathOut.isEmpty())
        return ER_empty;
    pStore->set_dir_byIndex(QFileInfo(QS_PathOut).dir().path(), default_dir_index);

    D_VideoWriter VideoWriter;
    VideoWriter.set_FPS(fps);
    VideoWriter.set_Size(vMA_Screenshots[0].size());
    VideoWriter.set_isColor(true);
    VideoWriter.set_PathOut(QS_PathOut);
    VideoWriter.init_VideoWriter();
    if(!VideoWriter.is_Init())
        return ER_StreamNotOpen;

    for(size_t f = 0; f < vMA_Screenshots.size(); f++)
        VideoWriter.AddFrame(vMA_Screenshots[f]);

    VideoWriter.EndVideoWriting();

    QMessageBox::information(
                this,
                "Saved video",
                "Your video was saved as \n" + QS_PathOut);

    return ER_okay;
}

int D_Viewer_3D::TakeFrames_SliceDim(vector<Mat> *pvMA_ViewsOut, int dim2loop)
{
    pvMA_ViewsOut->clear();
    if(!state_graph_up2date)
        return ER_empty;

    size_t n_frames = pVD_Data->pDim()->size_Dim(dim2loop);
    pvMA_ViewsOut->resize(n_frames);

    for(size_t i = 0; i < n_frames; i++)
    {
        //set pos in dim
        vui_SpinBox_DimIndices[dim2loop]->setValue(i);

        //update ui
        Update_Ui();

        //take screenshot
        //qDebug() << "take";
        QImage QI_Screenshot = graph_scatter->renderToImage(4);

        //qDebug() << "convert";
        int h = QI_Screenshot.height();
        int w = QI_Screenshot.width();
        Mat MA_Screenshot(h, w, CV_8UC3);
        for(int y = 0; y < h; y++)
            for(int x = 0; x < w; x++)
            {
                QColor col_px = QColor(QI_Screenshot.pixel(x, y));
                MA_Screenshot.at<Vec3b>(y, x) = Vec3b(
                            uchar(col_px.blue()),
                            uchar(col_px.green()),
                            uchar(col_px.red()));
            }

        //qDebug() << "save";
        (*pvMA_ViewsOut)[i] = MA_Screenshot.clone();
    }

    return ER_okay;
}

int D_Viewer_3D::TakeFrames_CameraRotationFull(vector<Mat> *pvMA_ViewsOut, size_t n_frames)
{
    pvMA_ViewsOut->clear();
    pvMA_ViewsOut->resize(n_frames);

    if(!state_graph_up2date)
        return ER_empty;

    int n_rot_x = 2;
    double y_amplitude = 2.0 / 3.0;

    for(size_t i = 0; i < n_frames; i++)
    {
        //rotate camera
        double rel_pos = double(i) / double(n_frames);

        double angle_x = rel_pos * 360.0 * n_rot_x;
        angle_x -= floor(angle_x / 360.0) * 360;

        //double rel_pos_y = rel_pos < 0.5 ? rel_pos : -rel_pos + 1;
        //double angle_y = 90.0 * y_amplitude * (rel_pos_y * 4 - 1);
        double angle_y = 90.0 * y_amplitude * (cos(rel_pos * PI_2_0));

        //qDebug() << angle_x << angle_y;
        graph_scatter->scene()->activeCamera()->setXRotation(float(angle_x));
        graph_scatter->scene()->activeCamera()->setYRotation(float(angle_y));

        //update ui
        Update_Ui();

        //take screenshot
        //qDebug() << "take";
        QImage QI_Screenshot = graph_scatter->renderToImage(4);

        //qDebug() << "convert";
        int h = QI_Screenshot.height();
        int w = QI_Screenshot.width();
        Mat MA_Screenshot(h, w, CV_8UC3);
        for(int y = 0; y < h; y++)
            for(int x = 0; x < w; x++)
            {
                QColor col_px = QColor(QI_Screenshot.pixel(x, y));
                MA_Screenshot.at<Vec3b>(y, x) = Vec3b(
                            uchar(col_px.blue()),
                            uchar(col_px.green()),
                            uchar(col_px.red()));
            }

        //qDebug() << "save";
        (*pvMA_ViewsOut)[i] = MA_Screenshot.clone();
    }

    return ER_okay;
}

void D_Viewer_3D::Update_Ui()
{
    this->setEnabled(false);
    this->repaint();
    qApp->processEvents();
    this->setEnabled(true);
}

void D_Viewer_3D::on_VolumeCurrent_Changed(int vol)
{
    //save current volume
    volume_index_current = vol;

    //get ext dims
    v_dims_extended = D_VisDat_Proc::VolumeDims(volume_index_current);

    //calc fix dims
    v_dims_fix.clear();
    for(int dcheck = 0; dcheck < c_DIM_NUMBER_OF; dcheck++)
    {
        bool is_ext = false;
        for(size_t dext = 0; !is_ext && dext < v_dims_extended.size(); dext++)
            if(dcheck == v_dims_extended[dext])
                is_ext = true;

        if(!is_ext)
            v_dims_fix.push_back(dcheck);
    }

    //adapt ui
    //extedned dims (2D slice pos)
    for(size_t i = 0; i < v_dims_extended.size(); i++)
    {
        size_t d = v_dims_extended[i];
        vui_SpinBox_DimIndices[d]->setSuffix(" (shown)");
    }
    //fixed dims (3D vol pos)
    for(size_t i = 0; i < v_dims_fix.size(); i++)
    {
        size_t d = v_dims_fix[i];
        vui_SpinBox_DimIndices[d]->setSuffix(" (fix)");
    }

    //depth scaling
    if(ui_DoubleSpinBox_ScaleDepth)
        ui_DoubleSpinBox_ScaleDepth->setPrefix(QSL_DimIndices[Dim_extended2()] + " scale = ");
}

int D_Viewer_3D::Update_Graph()
{
    //qDebug() << "D_Viewer_3D::Update_Graph" << "start-----------------------------------";

    //errors
    //if(state_graph_updating)    return ER_ThreadIssue;
    if(!state_ui_init)          return ER_UiNotInit;
    if(!state_VD_set)           return ER_empty;
    //qDebug() << "D_Viewer_3D::Update_Graph" << "error checks passed";

    //update states
    state_graph_updating = true;
    state_texture_set = false;
    state_graph_up2date = false;

    //clear old
    //qDebug() << "D_Viewer_3D::Update_Graph" << "clear graph";
    clear_graph();

    //update the texture
    //qDebug() << "D_Viewer_3D::Update_Graph" << "calc texture";
    int err = TextureData_CalcNew();
    if(err != ER_okay)
    {
        ERR(err, "Update_Graph", "TextureData_CalcNew");
        state_graph_updating = false;
        return err;
    }

    //show texture in graph
    //qDebug() << "D_Viewer_3D::Update_Graph" << "show texture";
    Show_Texture();

    //update slices
    //qDebug() << "D_Viewer_3D::Update_Graph" << "slice";
    Update_Slices();

    //update states and finish
    //qDebug() << "D_Viewer_3D::Update_Graph" << "finish";
    state_graph_up2date = true;
    state_graph_updating = false;
    return ER_okay;
}

int D_Viewer_3D::Update_Slices()
{
    //errors
    if(!state_ui_init)                          return ER_UiNotInit;
    if(!state_VD_set)                           return ER_empty;
    if(!ui_CheckBox_Slices_Show->isChecked())   return ER_okay;

    bool slice_vol = ui_CheckBox_Slices_SliceVolume->isChecked();

    int slice_index_x = vui_SpinBox_DimIndices[Dim_extended0()]->value();
    int slice_index_y = vui_SpinBox_DimIndices[Dim_extended1()]->value();
    int slice_index_z = vui_SpinBox_DimIndices[Dim_extended2()]->value();

    slice_index_x = max(0, min(slice_index_x, volume_item->textureWidth() - 1));
    slice_index_y = max(0, min(slice_index_y, volume_item->textureHeight() - 1));
    slice_index_z = max(0, min(slice_index_z, volume_item->textureDepth() - 1));

    volume_item->setDrawSlices(true);

    volume_item->setSliceIndexX(slice_vol ? slice_index_x : -1);
    volume_item->setSliceIndexY(slice_vol ? slice_index_y : -1);
    volume_item->setSliceIndexZ(slice_vol ? slice_index_z : -1);

    //loop 2D slices
    for(int i = 0; i < SLICE_2D_NUMBER_OF; i++)
    {
        //get dim indices of slice plane dims
        int plane_dim_0, plane_dim_1;
        switch (i) {
        case SLICE_2D_X:    plane_dim_0 = Dim_extended1();  plane_dim_1 = Dim_extended2();  break;
        case SLICE_2D_Y:    plane_dim_0 = Dim_extended0();  plane_dim_1 = Dim_extended2();  break;
        case SLICE_2D_Z:    plane_dim_0 = Dim_extended0();  plane_dim_1 = Dim_extended1();  break;
        default:                                                                            return ER_parameter_bad;}

        //loop dims to set slice indices
        Vec<int, c_DIM_NUMBER_OF> slice_pos;
        for(int d = 0; d < c_DIM_NUMBER_OF; d++)
            slice_pos[d] = (d == plane_dim_0 || d == plane_dim_1) ? (-1) : (vui_SpinBox_DimIndices[d]->value());

        //get 2D slice
        Mat MA_tmp_slice_2D;
        int err = D_VisDat_Proc::Read_2D_Plane(
                    &MA_tmp_slice_2D,
                    pVD_Data,
                    D_VisDat_Slice_2D(slice_pos));
        if(err != ER_okay)
        {
            MA_tmp_slice_2D.release();
            return err;
        }

        //show 2D slice
        vViewer_Slices2D[i]->Update_Image(&MA_tmp_slice_2D);

        //free img
        MA_tmp_slice_2D.release();
    }

    //ui_Label_2dSlice_YZ->setPixmap(QPixmap::fromImage(volume_item->renderSlice(Qt::XAxis, slice_index_x)).scaled(ui_Label_2dSlice_YZ->width() - 2, ui_Label_2dSlice_YZ->height() - 2, Qt::KeepAspectRatio, Qt::FastTransformation));
    //ui_Label_2dSlice_XZ->setPixmap(QPixmap::fromImage(volume_item->renderSlice(Qt::YAxis, slice_index_y)).scaled(ui_Label_2dSlice_XZ->width() - 2, ui_Label_2dSlice_XZ->height() - 2, Qt::KeepAspectRatio, Qt::FastTransformation));
    //ui_Label_2dSlice_XY->setPixmap(QPixmap::fromImage(volume_item->renderSlice(Qt::ZAxis, slice_index_z)).scaled(ui_Label_2dSlice_XY->width() - 2, ui_Label_2dSlice_XY->height() - 2, Qt::KeepAspectRatio, Qt::FastTransformation));

    return ER_okay;
}

int D_Viewer_3D::TextureData_CalcNew()
{
    //qDebug() << "D_Viewer_3D::TextureData_CalcNew" << "start";

    //clear old texture
    vTextureData.clear();
    state_texture_set = false;

    //relevant dims
    int dim_plane_1 = Dim_extended0();
    int dim_plane_2 = Dim_extended1();
    int dim_loop    = Dim_extended2();
    if(dim_plane_1 < 0 || dim_plane_1 >= c_DIM_NUMBER_OF)   return ER_dim_missmatch;
    if(dim_plane_2 < 0 || dim_plane_2 >= c_DIM_NUMBER_OF)   return ER_dim_missmatch;
    if(dim_loop    < 0 || dim_loop    >= c_DIM_NUMBER_OF)   return ER_dim_missmatch;

    //sizes
    int size_plane_1 = pVD_Data->pDim()->size_Dim(dim_plane_1);
    int size_plane_2 = pVD_Data->pDim()->size_Dim(dim_plane_2);
    int size_loop    = pVD_Data->pDim()->size_Dim(dim_loop);
    int pixel_volume = size_plane_1 * size_plane_2 * size_loop;

    //range of data
    double min_global =  INFINITY;
    double max_global = -INFINITY;
    int err = D_VisDat_Proc::Calc_MinMax(
                pVD_Data,
                &min_global,
                &max_global);
    if(err != ER_okay)
    {
        ERR(err, "TextureData_CalcNew", "D_VisDat_Proc::Calc_MinMax");
        return err;
    }

    //texture size in bytes
    size_t n_bytes = pixel_volume * 4;  //4 bytes per pixel
    if(n_bytes >= 2147483648)           //2^31 bytes = 2147483648 bytes = 2GB = max size of QVector
    {
        qDebug() << "D_Viewer_3D::TextureData_CalcNew" << QString::number(n_bytes / 1000000) << "MB is too large. max:" << 2147483648 / 1000000 << "MB";
        return ER_MemSizeToBig;
    }

    //resize texture
    vTextureData.reserve(n_bytes);

    //Buffer Mat
    Mat MA_tmp_Slice;

    //loop VD planes
    for(int i_plane = 0; i_plane < size_loop; i_plane++)
    {
        //2D slice
        D_VisDat_Slice_2D slice;
        slice.set_Pos_Dim(dim_plane_1, -1);
        slice.set_Pos_Dim(dim_plane_2, -1);
        slice.set_Pos_Dim(dim_loop, i_plane);

        //calc target img
        //QImage QI_tmp_Slice;
        err = Slice_2D_Mat_from_VD(&MA_tmp_Slice, slice, min_global, max_global);
        if(err != ER_okay)
        {
            MA_tmp_Slice.release();
            ERR(err, "TextureData_CalcNew", "Slice_2D_Mat_from_VD");
            return err;
        }

        //append img data to texture
        err = TextureData_AppendSlice(&MA_tmp_Slice, i_plane);
        if(err != ER_okay)
        {
            MA_tmp_Slice.release();
            ERR(err, "TextureData_CalcNew", "TextureData_AppendSlice");
            return err;
        }

        //save color table
        //vColorTable = QI_tmp_Slice.colorTable();
    }

    state_texture_set = true;
    MA_tmp_Slice.release();
    return ER_okay;
}

int D_Viewer_3D::Slice_2D_Mat_from_VD(Mat *pMA_SliceOut, D_VisDat_Slice_2D slice, double min_global, double max_global)
{
    //qDebug() << "D_Viewer_3D::Slice_2D_QImage_from_VD" << "start";

    if(!state_VD_set)
        return ER_empty;

    //extract 2D mat from VD
    Mat MA_tmp_slice;
    int err = D_VisDat_Proc::Read_2D_Plane(
                &MA_tmp_slice,
                pVD_Data,
                slice);
    if(err != ER_okay)
    {
        MA_tmp_slice.release();
        ERR(err, "Slice_2D_Mat_from_VD", "D_VisDat_Proc::Read_2D_Plane");
        return err;
    }

    //apply vis trafo
    Mat MA_tmp_slice_vistrafo = MA_tmp_slice.clone();
    err = D_Img_Proc::Visualize_to8bit(
                &MA_tmp_slice_vistrafo,
                &MA_tmp_slice,
                vis_trafo_active ? vis_trafo_mode_crop : c_VIS_TRAFO_CROP_FIXED,
                vis_trafo_active ? vis_trafo_mode_trafo : c_VIS_TRAFO_LINEAR,
                vis_trafo_active ? vis_trafo_mode_anchor : c_VIS_TRAFO_ANCHOR_DYNAMIC,
                vis_trafo_active ? vis_trafo_mode_range : c_VIS_TRAFO_RANGE_DYNAMIC,
                vis_trafo_active ? vis_trafo_anchor : 0.0,
                vis_trafo_active ? vis_trafo_range : 1.0,
                vis_trafo_active ? (vis_trafo_mode_crop == c_VIS_TRAFO_CROP_FIXED ? vis_trafo_in_min : min_global) : min_global,
                vis_trafo_active ? (vis_trafo_mode_crop == c_VIS_TRAFO_CROP_FIXED ? vis_trafo_in_max : max_global) : max_global,
                vis_trafo_active ? vis_trafo_gamma : 1.0,
                vis_trafo_active ? vis_trafo_center : 0.0,
                vis_trafo_active ? vis_trafo_divisor : 1.0,
                true,
                vis_trafo_active ? vis_trafo_mode_complex : c_COMPLEX2REAL_RE_IM);
    if(err != ER_okay)
    {
        MA_tmp_slice.release();
        MA_tmp_slice_vistrafo.release();
        ERR(err, "Slice_2D_Mat_from_VD", "D_Img_Proc::Visualize_to8bit");
        return err;
    }

    //convert to 4ch
    err = D_Img_Proc::Convert_toMat4Ch_8bit(
                pMA_SliceOut,
                &MA_tmp_slice_vistrafo,
                ui_ComboBox_AlphaMode->currentIndex(),
                pVD_Data->channels() == 1 ? ui_CheckBox_HeatColor->isChecked() : false,
                false);

    //release and return
    MA_tmp_slice.release();
    MA_tmp_slice_vistrafo.release();
    return err;
}

int D_Viewer_3D::TextureData_AppendSlice(Mat *pMA_toAppend, size_t slice_number)
{
    //qDebug() << "D_Viewer_3D::TextureData_AppendSlice" << "start";

    if(pMA_toAppend->type() != CV_8UC4)
        return ER_type_missmatch;

    //img size
    int w = pMA_toAppend->cols;                 //width
    int h = pMA_toAppend->rows;                 //height
    int area = w * h;                           //area
    //qDebug() << w << h << area << byte_depth << n;

    //data offset from prevoius image slices
    size_t data_offset_byte = slice_number * area * 4;


    //qDebug() << "---------------------------------- new image -----------------------------------";
    //img data
    Vec4b* ptr_data = reinterpret_cast<Vec4b*>(pMA_toAppend->data);
    for(int px = 0; px < area; px++, ptr_data++)
    {
        //get channels
        uchar b = (*ptr_data)[0];
        uchar g = (*ptr_data)[1];
        uchar r = (*ptr_data)[2];
        uchar a = (*ptr_data)[3];

        //add data to texture
        int pixel_offset_byte = data_offset_byte + (px * 4);
        vTextureData[pixel_offset_byte + 0] = b;
        vTextureData[pixel_offset_byte + 1] = g;
        vTextureData[pixel_offset_byte + 2] = r;
        vTextureData[pixel_offset_byte + 3] = a;
    }

    //debug info
    //qDebug() << "vTextureData.size()" << vTextureData.size() << vTextureData.size() / 4.0 << (vTextureData.size() / 4.0) / area;

    return ER_okay;
}

int D_Viewer_3D::Show_Texture()
{
    if(!state_texture_set)
        return ER_empty;

    //qDebug() << "D_Viewer_3D::Show_Texture" << "start";

    //graph axis title
    //qDebug() << "D_Viewer_3D::Show_Texture" << "axis title";
    graph_scatter->axisX()->setTitle(QSL_DimIndices[Dim_extended0()]);
    graph_scatter->axisY()->setTitle(QSL_DimIndices[Dim_extended1()]);
    graph_scatter->axisZ()->setTitle(QSL_DimIndices[Dim_extended2()]);
    graph_scatter->axisX()->setTitleVisible(true);
    graph_scatter->axisY()->setTitleVisible(true);
    graph_scatter->axisZ()->setTitleVisible(true);
    graph_scatter->axisY()->setReversed(true);

    //sacling to fit axis range
    //qDebug() << "D_Viewer_3D::Show_Texture" << "scale and pos";
    set_VolumeScalingAndPosition();

    //texture size
    //qDebug() << "D_Viewer_3D::Show_Texture" << "texture size";
    set_TextureSize();

    //set texture data
    //qDebug() << "D_Viewer_3D::Show_Texture" << "set texture data";
    volume_item->setTextureData(new QVector<uchar>(vTextureData));

    //qDebug() << "D_Viewer_3D::Show_Texture" << "end";
    return ER_okay;
}

void D_Viewer_3D::set_VolumeScalingAndPosition()
{
    //scale
    float depth_scale = ui_DoubleSpinBox_ScaleDepth ? float(ui_DoubleSpinBox_ScaleDepth->value()) : 1.f;

    //graph axis range
    //qDebug() << "D_Viewer_3D::Show_Texture" << "axis range";
    graph_scatter->axisX()->setRange(0, pVD_Data->pDim()->size_Dim(Dim_extended0()));
    graph_scatter->axisY()->setRange(0, pVD_Data->pDim()->size_Dim(Dim_extended1()));
    graph_scatter->axisZ()->setRange(0, pVD_Data->pDim()->size_Dim(Dim_extended2()) * depth_scale);

    //scaling
    volume_item->setScaling(
                QVector3D(
                    graph_scatter->axisX()->max() - graph_scatter->axisX()->min(),
                    graph_scatter->axisY()->max() - graph_scatter->axisY()->min(),
                    (graph_scatter->axisZ()->max() - graph_scatter->axisZ()->min())));

    //set position in center of axis ranges
    volume_item->setPosition(
                QVector3D(
                    (graph_scatter->axisX()->max() + graph_scatter->axisX()->min()) / 2.0f,
                    (graph_scatter->axisY()->max() + graph_scatter->axisY()->min()) / 2.0f,
                    (graph_scatter->axisZ()->max() + graph_scatter->axisZ()->min()) / 2.0f));
}

void D_Viewer_3D::set_TextureSize()
{
    if(!state_texture_set)
        return;

    //texture size
    volume_item->setTextureWidth (pVD_Data->pDim()->size_Dim(Dim_extended0()));
    volume_item->setTextureHeight(pVD_Data->pDim()->size_Dim(Dim_extended1()));
    volume_item->setTextureDepth (pVD_Data->pDim()->size_Dim(Dim_extended2()));
}

void D_Viewer_3D::set_HD_shader(bool hd)
{
    if(!state_ui_init)
        return;

    volume_item->setUseHighDefShader(hd);
}

void D_Viewer_3D::set_preserve_opacity(bool preserve)
{
    if(!state_ui_init)
        return;

    volume_item->setPreserveOpacity(preserve);
}

void D_Viewer_3D::set_draw_slices(bool draw)
{
    if(!state_ui_init)
        return;

    volume_item->setDrawSlices(draw);
}

void D_Viewer_3D::set_alpha_multiplier(double factor)
{
    if(!ui_DoubleSpinBox_AlphaMultiplier || !state_ui_init)
        return;

    volume_item->setAlphaMultiplier(float(factor));
    Update_Slices();
}

void D_Viewer_3D::set_shadow_quality(int shadow_quality_id)
{
    if(!graph_scatter)
        return;

    graph_scatter->setShadowQuality(QAbstract3DGraph::ShadowQuality(shadow_quality_id));
}

void D_Viewer_3D::change_graph_background_color()
{
    if(!state_ui_init)
        return;

    QColor color = QColorDialog::getColor(
                graph_scatter->activeTheme()->backgroundColor(),
                this,
                "Change graph background color");

    graph_scatter->activeTheme()->setBackgroundColor(color);
    graph_scatter->activeTheme()->setWindowColor(color);

    ui_PushButton_BackgroundColor->setStyleSheet("background-color: " + D_Img_Proc::Color2Text4StyleSheet(color) + ";\ncolor: " + D_Img_Proc::Color2Text4StyleSheet(D_Img_Proc::Contrast_Color(color)) + ";");

    for(int i = 0; i < SLICE_2D_NUMBER_OF; i++)
        vui_GraphicsView_Slices2D[i]->setStyleSheet("background-color: " + D_Img_Proc::Color2Text4StyleSheet(color) + ";");

    /*
    ui_Label_2dSlice_XY->setStyleSheet("background-color: " + D_Img_Proc::Color2Text4StyleSheet(color) + ";");
    ui_Label_2dSlice_XZ->setStyleSheet("background-color: " + D_Img_Proc::Color2Text4StyleSheet(color) + ";");
    ui_Label_2dSlice_YZ->setStyleSheet("background-color: " + D_Img_Proc::Color2Text4StyleSheet(color) + ";");
    */
}

void D_Viewer_3D::check_volume_changes_and_trigger_slots()
{
    //check changes
    bool changed_volume = false;
    bool changed_slice = false;
    for(int d = 0; d < int(v_dim_indeces_last.size()); d++)
    {
        int i_old = v_dim_indeces_last[d];
        int i_new = vui_SpinBox_DimIndices[d]->value();
        v_dim_indeces_last[d] = i_new;
        bool extended = Dim_is_extended(d);
        bool changed = i_old != i_new;
        if(changed)
        {
            if(extended)
                changed_slice = true;
            else
                changed_volume = true;
        }
    }

    //updated
    if(changed_volume)
        Update_Graph(); //and slices (called internal)
    else if(changed_slice)
        Update_Slices();
}

void D_Viewer_3D::adapt_alpha_multiplier_step(double value)
{
    if(ui_DoubleSpinBox_AlphaMultiplier)
        ui_DoubleSpinBox_AlphaMultiplier->setSingleStep(max(0.01, value * 0.1));
}

void D_Viewer_3D::adapt_depth_scale_step(double value)
{
    if(ui_DoubleSpinBox_ScaleDepth)
        ui_DoubleSpinBox_ScaleDepth->setSingleStep(max(0.01, value * 0.1));
}

void D_Viewer_3D::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_Viewer_3D", func, detail);
}

void D_Viewer_3D::Populate_CB_Single(QComboBox *CB, QStringList QSL, int init_index)
{
    CB->blockSignals(true);
    CB->clear();
    CB->addItems(QSL);
    CB->setCurrentIndex(init_index);
    CB->blockSignals(false);
}


