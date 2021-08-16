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
    ui_GroupBox_3D_graph->layout()->setContentsMargins(3, 3, 3, 3);

    //slices
    ui_GroupBox_2D_slices = new QGroupBox("2D Sices", this);
    ui_GroupBox_2D_slices->setLayout(new QGridLayout(this));
    ui_layout_target->addWidget(ui_GroupBox_2D_slices, 0, 1);
    QSizePolicy sizepol_factor1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    sizepol_factor1.setHorizontalStretch(1);
    ui_GroupBox_2D_slices->setSizePolicy(sizepol_factor1);
    ui_GroupBox_2D_slices->layout()->setSpacing(1);
    ui_GroupBox_2D_slices->layout()->setContentsMargins(3, 3, 3, 3);
    ui_GroupBox_2D_slices->setVisible(false);

    //settings
    ui_GroupBox_Settings = new QGroupBox("Settings", this);
    ui_GroupBox_Settings->setLayout(new QVBoxLayout(this));
    ui_layout_target->addWidget(ui_GroupBox_Settings, 0, 2);
    ui_GroupBox_Settings->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
    ui_GroupBox_Settings->layout()->setSpacing(3);
    ui_GroupBox_Settings->layout()->setContentsMargins(3, 3, 3, 3);

    //volume
    ui_GroupBox_Settings_Volume = new QGroupBox("Volume", this);
    ui_GroupBox_Settings_Volume->setLayout(new QVBoxLayout(this));
    ui_GroupBox_Settings->layout()->addWidget(ui_GroupBox_Settings_Volume);
    ui_GroupBox_Settings_Volume->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    ui_GroupBox_Settings_Volume->layout()->setSpacing(1);
    ui_GroupBox_Settings_Volume->layout()->setContentsMargins(3, 3, 3, 3);

    //draw condition
    ui_GroupBox_Settings_DrawCondition = new QGroupBox("Draw Condition", this);
    ui_GroupBox_Settings_DrawCondition->setLayout(new QVBoxLayout(this));
    ui_GroupBox_Settings->layout()->addWidget(ui_GroupBox_Settings_DrawCondition);
    ui_GroupBox_Settings_DrawCondition->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    ui_GroupBox_Settings_DrawCondition->layout()->setSpacing(1);
    ui_GroupBox_Settings_DrawCondition->layout()->setContentsMargins(3, 3, 3, 3);

    //alpha
    ui_GroupBox_Settings_Alpha = new QGroupBox("Alpha", this);
    ui_GroupBox_Settings_Alpha->setLayout(new QVBoxLayout(this));
    ui_GroupBox_Settings->layout()->addWidget(ui_GroupBox_Settings_Alpha);
    ui_GroupBox_Settings_Alpha->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    ui_GroupBox_Settings_Alpha->layout()->setSpacing(1);
    ui_GroupBox_Settings_Alpha->layout()->setContentsMargins(3, 3, 3, 3);

    //appearance
    ui_GroupBox_Settings_Graphics_Appearance = new QGroupBox("Appearance", this);
    ui_GroupBox_Settings_Graphics_Appearance->setLayout(new QVBoxLayout(this));
    ui_GroupBox_Settings->layout()->addWidget(ui_GroupBox_Settings_Graphics_Appearance);
    ui_GroupBox_Settings_Graphics_Appearance->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    ui_GroupBox_Settings_Graphics_Appearance->layout()->setSpacing(1);
    ui_GroupBox_Settings_Graphics_Appearance->layout()->setContentsMargins(3, 3, 3, 3);

    //slices
    ui_GroupBox_Settings_Graphics_Slices = new QGroupBox("2D Slices", this);
    ui_GroupBox_Settings_Graphics_Slices->setLayout(new QVBoxLayout(this));
    ui_GroupBox_Settings->layout()->addWidget(ui_GroupBox_Settings_Graphics_Slices);
    ui_GroupBox_Settings_Graphics_Slices->setCheckable(true);
    ui_GroupBox_Settings_Graphics_Slices->setChecked(false);
    ui_GroupBox_Settings_Graphics_Slices->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    ui_GroupBox_Settings_Graphics_Slices->layout()->setSpacing(1);
    ui_GroupBox_Settings_Graphics_Slices->layout()->setContentsMargins(3, 3, 3, 3);
    connect(ui_GroupBox_Settings_Graphics_Slices, SIGNAL(toggled(bool)), ui_GroupBox_2D_slices, SLOT(setVisible(bool)));

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
    }


    //settings

    //appearance
    //shader
    ui_CheckBox_Shader_HD = new QCheckBox("Use HD Shader", this);
    ui_GroupBox_Settings_Graphics_Appearance->layout()->addWidget(ui_CheckBox_Shader_HD);
    //opacity
    ui_CheckBox_OpacityPreserve = new QCheckBox("Preserve Opacity", this);
    ui_GroupBox_Settings_Graphics_Appearance->layout()->addWidget(ui_CheckBox_OpacityPreserve);

    //slices
    //slice frames
    ui_CheckBox_Slices_ShowFrames = new QCheckBox("Slice Frames", this);
    ui_GroupBox_Settings_Graphics_Slices->layout()->addWidget(ui_CheckBox_Slices_ShowFrames);
    ui_CheckBox_Slices_ShowFrames->setEnabled(false);
    connect(ui_GroupBox_Settings_Graphics_Slices, SIGNAL(toggled(bool)), ui_CheckBox_Slices_ShowFrames, SLOT(setEnabled(bool)));
    //slice volume
    //X
    ui_CheckBox_Slices_SliceX = new QCheckBox("Slice Vol X", this);
    ui_GroupBox_Settings_Graphics_Slices->layout()->addWidget(ui_CheckBox_Slices_SliceX);
    ui_CheckBox_Slices_SliceX->setEnabled(false);
    connect(ui_GroupBox_Settings_Graphics_Slices, SIGNAL(toggled(bool)), ui_CheckBox_Slices_SliceX, SLOT(setEnabled(bool)));
    //Y
    ui_CheckBox_Slices_SliceY = new QCheckBox("Slice Vol Y", this);
    ui_GroupBox_Settings_Graphics_Slices->layout()->addWidget(ui_CheckBox_Slices_SliceY);
    ui_CheckBox_Slices_SliceY->setEnabled(false);
    connect(ui_GroupBox_Settings_Graphics_Slices, SIGNAL(toggled(bool)), ui_CheckBox_Slices_SliceY, SLOT(setEnabled(bool)));
    //Z
    ui_CheckBox_Slices_SliceZ = new QCheckBox("Slice Vol Z", this);
    ui_GroupBox_Settings_Graphics_Slices->layout()->addWidget(ui_CheckBox_Slices_SliceZ);
    ui_CheckBox_Slices_SliceZ->setEnabled(false);
    connect(ui_GroupBox_Settings_Graphics_Slices, SIGNAL(toggled(bool)), ui_CheckBox_Slices_SliceZ, SLOT(setEnabled(bool)));


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
    graph_scatter->setShadowQuality(QAbstract3DGraph::ShadowQualityNone);
    graph_scatter->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetIsometricRightHigh);
    graph_scatter->activeTheme()->setBackgroundEnabled(false);
    graph_scatter->scene()->activeCamera()->setMaxZoomLevel(200.0f);
    graph_scatter->activeTheme()->setType(Q3DTheme::ThemeEbony);

    //volume dim index selectors
    on_VolumeCurrent_Changed(c_VOLUME_XYZ);

    //-------------------------------------------------------------- volume

    //volume
    volume_item = new QCustom3DVolume;
    graph_scatter->addCustomItem(volume_item);

    volume_item->setScaling(
                QVector3D(
                    graph_scatter->axisX()->max() - graph_scatter->axisX()->min(),
                    graph_scatter->axisY()->max() - graph_scatter->axisY()->min(),// * 0.91f,
                    graph_scatter->axisZ()->max() - graph_scatter->axisZ()->min()));

    //set position in center of axis ranges
    //qDebug() << "D_Viewer_3D::Show_Texture" << "position";
    volume_item->setPosition(
                QVector3D(
                    (graph_scatter->axisX()->max() + graph_scatter->axisX()->min()) / 2.0f,
                    (graph_scatter->axisY()->max() + graph_scatter->axisY()->min()) / 2.0f,// - (0.045f * (graph_scatter->axisY()->max() - graph_scatter->axisY()->min())),    //WTF? why?
                    (graph_scatter->axisZ()->max() + graph_scatter->axisZ()->min()) / 2.0f));

    //make scaling follow changes in data range
    volume_item->setScalingAbsolute(false);

    //slicing and frames
    volume_item->setSliceFrameGaps(QVector3D(0.01f, 0.02f, 0.01f));
    volume_item->setSliceFrameThicknesses(QVector3D(0.0025f, 0.005f, 0.0025f));
    volume_item->setSliceFrameWidths(QVector3D(0.0025f, 0.005f, 0.0025f));
    volume_item->setDrawSliceFrames(false);

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

    //update graph
    //qDebug() << "D_Viewer_3D::set_VisDat" << "update graph";
    Update_Graph();

    //qDebug() << "D_Viewer_3D::set_VisDat" << "end";
    return ER_okay;
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
    //disconnect old connects (if any)
    for(size_t d = 0; d < vui_SpinBox_DimIndices.size(); d++)
    {
        disconnect(vui_SpinBox_DimIndices[d], SIGNAL(valueChanged(int)), this, SLOT(Update_Graph()));
    }
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
        connect(vui_SpinBox_DimIndices[d], SIGNAL(valueChanged(int)), this, SLOT(Update_Graph()));
    }
}

int D_Viewer_3D::Update_Graph()
{
    //qDebug() << "D_Viewer_3D::Update_Graph" << "start";

    //errors
    if(!state_ui_init)          return ER_UiNotInit;
    if(!state_VD_set)           return ER_empty;
    int err = ER_okay;

    //update states
    state_texture_set = false;
    state_graph_up2date = false;

    //clear old
    clear_graph();

    //update the texture
    err = TextureData_CalcNew();
    if(err != ER_okay)
        return err;

    //show texture in graph
    Show_Texture();

    //update states and finish
    state_graph_up2date = true;
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

    //resize texture
    vTextureData.reserve(pixel_volume * 4); //4 bits per pixel

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
        int err = Slice_2D_Mat_from_VD(&MA_tmp_Slice, slice);
        if(err != ER_okay)
        {
            MA_tmp_Slice.release();
            return err;
        }

        //append img data to texture
        err = TextureData_AppendSlice(&MA_tmp_Slice, i_plane);
        if(err != ER_okay)
        {
            MA_tmp_Slice.release();
            return err;
        }

        //save color table
        //vColorTable = QI_tmp_Slice.colorTable();
    }

    state_texture_set = true;
    MA_tmp_Slice.release();
    return ER_okay;
}

int D_Viewer_3D::Slice_2D_Mat_from_VD(Mat *pMA_SliceOut, D_VisDat_Slice_2D slice)
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
        return err;
    }

    //apply vis trafo
    Mat MA_tmp_slice_vistrafo = MA_tmp_slice.clone();
    err = D_Img_Proc::Visualize_to8bit(
                &MA_tmp_slice_vistrafo,
                &MA_tmp_slice,
                vis_trafo_mode_crop,
                vis_trafo_mode_trafo,
                vis_trafo_mode_anchor,
                vis_trafo_mode_range,
                vis_trafo_anchor,
                vis_trafo_range,
                vis_trafo_in_min,
                vis_trafo_in_max,
                vis_trafo_gamma,
                vis_trafo_center,
                vis_trafo_divisor,
                false,
                vis_trafo_mode_complex);
    if(err != ER_okay)
    {
        MA_tmp_slice.release();
        MA_tmp_slice_vistrafo.release();
        return err;
    }

    //create dummy alpha img (TODO: replace with real alpha)
    Mat MA_tmp_alpha = Mat(MA_tmp_slice_vistrafo.size(), CV_8UC1, Scalar(255));

    //convert to 4ch
    err = D_Img_Proc::Convert_toMat4Ch_8bit(
                pMA_SliceOut,
                &MA_tmp_slice_vistrafo,
                &MA_tmp_alpha,
                false);

    //release and return
    MA_tmp_slice.release();
    MA_tmp_slice_vistrafo.release();
    MA_tmp_alpha.release();
    return err;
}

int D_Viewer_3D::Slice_2D_QImage_from_VD(QImage *pQI_SliceOut, D_VisDat_Slice_2D slice)
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
        return err;
    }

    //apply vis trafo
    Mat MA_tmp_slice_vistrafo = MA_tmp_slice.clone();
    err = D_Img_Proc::Visualize_to8bit(
                &MA_tmp_slice_vistrafo,
                &MA_tmp_slice,
                vis_trafo_mode_crop,
                vis_trafo_mode_trafo,
                vis_trafo_mode_anchor,
                vis_trafo_mode_range,
                vis_trafo_anchor,
                vis_trafo_range,
                vis_trafo_in_min,
                vis_trafo_in_max,
                vis_trafo_gamma,
                vis_trafo_center,
                vis_trafo_divisor,
                false,
                vis_trafo_mode_complex);
    if(err != ER_okay)
    {
        MA_tmp_slice.release();
        MA_tmp_slice_vistrafo.release();
        return err;
    }

    //create dummy alpha img (TODO: replace with real alpha)
    Mat MA_tmp_alpha = Mat(MA_tmp_slice_vistrafo.size(), CV_8UC1, Scalar(255));

    //convert to QI
    QImage QI_Buffer;
    err = D_Img_Proc::Convert_toQImage4Ch_8bit(
                &QI_Buffer,
                &MA_tmp_slice_vistrafo,
                &MA_tmp_alpha,
                false);

    //convert
    *pQI_SliceOut = QI_Buffer.convertToFormat(QImage::Format_Indexed8);

    /*
    //show (just for testing)
    QLabel label;
    label.setPixmap(QPixmap::fromImage(*pQI_SliceOut));
    label.show();
    QMessageBox::information(
                this,
                "test img",
                slice.info());
                */

    //release and return
    MA_tmp_slice.release();
    MA_tmp_slice_vistrafo.release();
    MA_tmp_alpha.release();
    return ER_okay;
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


    qDebug() << "---------------------------------- new image -----------------------------------";
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
        size_t pixel_offset_byte = data_offset_byte + (px * 4);
        vTextureData[pixel_offset_byte + 0] = a;
        vTextureData[pixel_offset_byte + 1] = r;
        vTextureData[pixel_offset_byte + 2] = g;
        vTextureData[pixel_offset_byte + 3] = b;
    }

    //debug info
    //qDebug() << "vTextureData.size()" << vTextureData.size() << vTextureData.size() / 4.0 << (vTextureData.size() / 4.0) / area;

    return ER_okay;
}

int D_Viewer_3D::TextureData_AppendSlice(QImage *pQI_toAppend)
{
    //qDebug() << "D_Viewer_3D::TextureData_AppendSlice" << "start";

    if(pQI_toAppend->format() != QImage::Format_Indexed8)
        return ER_type_missmatch;

    //img size
    int w = pQI_toAppend->width();              //width
    int h = pQI_toAppend->height();             //height
    int area = w * h;                           //area
    int byte_depth = pQI_toAppend->depth() / 8; //byte per pixel
    int n = area * byte_depth;                  //byte/uchars to loop
    //qDebug() << w << h << area << byte_depth << n;

    qDebug() << "---------------------------------- new image -----------------------------------";
    for(int y = 0; y < h; y++)
    {
        qDebug() << "y" << y << "---------------------------------- new line";
        QRgb* line = reinterpret_cast<QRgb*>(pQI_toAppend->scanLine(y));
        for(int x = 0; x < w; x++)
        {
            //get pixel
            QRgb pixel = line[x];

            uchar r =  (pixel & 0x000000ff);
            uchar g = ((pixel & 0x0000ff00) >> 8);
            uchar b = ((pixel & 0x00ff0000) >> 16);
            uchar a = ((pixel & 0xff000000) >> 24);
            qDebug() << "x" << x << "rgba" << pixel << r << g << b << a;

            vTextureData.append(r);
            vTextureData.append(g);
            vTextureData.append(b);
            vTextureData.append(a);
        }
    }

    /*
    for(int y = 0; y < h; y++)
    {
        QRgb* line = reinterpret_cast<QRgb*>(pQI_toAppend->scanLine(y));
        for(int x = 0; x < w; x++)
        {
            //get pixel
            uchar* pixel = reinterpret_cast<uchar*>(line);
            vTextureData.append(pixel[0]);
            vTextureData.append(pixel[1]);
            vTextureData.append(pixel[2]);
            vTextureData.append(pixel[3]);

            //next pixel
            line++;
        }
    }
    */

    /*
    //img data
    uchar* ptr_data = reinterpret_cast<uchar*>(pQI_toAppend->bits());
    for(int i = 0; i < n; i++, ptr_data++)
        vTextureData.append(*ptr_data);
        */

    //debug info
    qDebug() << "vTextureData.size()" << vTextureData.size() << vTextureData.size() / 4.0 << (vTextureData.size() / 4.0) / area;

    return ER_okay;
}

int D_Viewer_3D::Show_Texture()
{
    if(!state_texture_set)
        return ER_empty;

    //qDebug() << "D_Viewer_3D::Show_Texture" << "start";

    //graph axis range
    //qDebug() << "D_Viewer_3D::Show_Texture" << "axis range";
    graph_scatter->axisX()->setRange(0, pVD_Data->pDim()->size_Dim(Dim_extended0()));
    graph_scatter->axisY()->setRange(0, pVD_Data->pDim()->size_Dim(Dim_extended1()));
    graph_scatter->axisZ()->setRange(0, pVD_Data->pDim()->size_Dim(Dim_extended2()));

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
    //qDebug() << "D_Viewer_3D::Show_Texture" << "scaling";
    volume_item->setScaling(
                QVector3D(
                    graph_scatter->axisX()->max() - graph_scatter->axisX()->min(),
                    graph_scatter->axisY()->max() - graph_scatter->axisY()->min(),// * 0.91f,
                    graph_scatter->axisZ()->max() - graph_scatter->axisZ()->min()));

    //set position in center of axis ranges
    //qDebug() << "D_Viewer_3D::Show_Texture" << "position";
    volume_item->setPosition(
                QVector3D(
                    (graph_scatter->axisX()->max() + graph_scatter->axisX()->min()) / 2.0f,
                    (graph_scatter->axisY()->max() + graph_scatter->axisY()->min()) / 2.0f,// - (0.045f * (graph_scatter->axisY()->max() - graph_scatter->axisY()->min())),    //WTF? why?
                    (graph_scatter->axisZ()->max() + graph_scatter->axisZ()->min()) / 2.0f));

    //absolute sacling off (why?)
    //pVolumeCustom->setScalingAbsolute(false);

    //set texture dimension
    //qDebug() << "D_Viewer_3D::Show_Texture" << "trexture dimension";
    volume_item->setTextureWidth (pVD_Data->pDim()->size_Dim(Dim_extended0()));
    volume_item->setTextureHeight(pVD_Data->pDim()->size_Dim(Dim_extended1()));
    volume_item->setTextureDepth (pVD_Data->pDim()->size_Dim(Dim_extended2()));
    volume_item->setTextureFormat(QImage::Format_ARGB32);

    //set texture data
    //qDebug() << "D_Viewer_3D::Show_Texture" << "set texture data";
    volume_item->setTextureData(new QVector<uchar>(vTextureData));

    //set color table
    //volume_item->setColorTable(vColorTable);

    //slicing and frames
    //qDebug() << "D_Viewer_3D::Show_Texture" << "slicing and frames";
    //volume_item->setSliceFrameGaps(QVector3D(0.01f, 0.02f, 0.01f));
    //volume_item->setSliceFrameThicknesses(QVector3D(0.0025f, 0.005f, 0.0025f));
    //volume_item->setSliceFrameWidths(QVector3D(0.0025f, 0.005f, 0.0025f));
    //volume_item->setDrawSliceFrames(false);



    //qDebug() << "D_Viewer_3D::Show_Texture" << "end";
    return ER_okay;
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


