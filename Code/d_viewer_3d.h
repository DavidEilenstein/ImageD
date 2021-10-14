/************************************
 *   added:     11.08.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VIEWER_3D_H
#define D_VIEWER_3D_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_visdat_obj.h>
#include <d_visdat_proc.h>
#include <d_viewer.h>
#include <d_videowriter.h>

//general
#include <iostream>
#include <vector>

//Qt
#include <QWidget>
#include <QObject>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>
#include <QFileInfo>
#include <QInputDialog>
#include <QDir>
#include <QElapsedTimer>
#include <QScrollBar>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QCheckBox>
#include <QComboBox>
#include <QGraphicsView>
#include <QLabel>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QSpacerItem>
#include <QWidget>
#include <QtCore/qmath.h>
#include <QtCore/qrandom.h>
#include <QtWidgets/QComboBox>
#include <QLabel>
#include <d_popup_listselect.h>
#include <d_storage.h>

//Qt-Datavisualization
#include <QtDataVisualization>
#include <QtDataVisualization/q3dscatter.h>
#include <QtDataVisualization/qabstract3dseries.h>
#include <QtDataVisualization/qscatterdataproxy.h>
#include <QtDataVisualization/qvalue3daxis.h>
#include <QtDataVisualization/q3dscene.h>
#include <QtDataVisualization/q3dcamera.h>
#include <QtDataVisualization/qscatter3dseries.h>
#include <QtDataVisualization/q3dtheme.h>
#include <QtDataVisualization/QSurface3DSeries>
#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QSurfaceDataArray>
#include <QtDataVisualization/QCustom3DVolume>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of ambigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>
using namespace QtDataVisualization;

class D_Viewer_3D : public QWidget
{
    Q_OBJECT

public:
    D_Viewer_3D();
    D_Viewer_3D(QGridLayout *target_layout);
    ~D_Viewer_3D();

    //init
    void init(QGridLayout *target_layout);

public slots:

    //clear
    void        clear_graph();

    //update
    int         Update_Graph();
    int         Update_Slices();

    //set VD
    int         set_VisDat(D_VisDat_Obj *pVD_toShow);

    //vis trafo
    void        Set_VisTrafo_ActiveInt  (int active = 1)                            {Set_VisTrafo_ActiveBool(active);}
    void        Set_VisTrafo_ActiveBool (bool active = true)                        {vis_trafo_active = active;         for(int i = 0; i < SLICE_2D_NUMBER_OF; i++) vViewer_Slices2D[i]->Set_VisTrafo_ActiveBool(active);       Update_Graph();}
    void        Set_VisTrafo_Gamma      (double gamma = 1)                          {vis_trafo_gamma = gamma;           for(int i = 0; i < SLICE_2D_NUMBER_OF; i++) vViewer_Slices2D[i]->Set_VisTrafo_Gamma(gamma);             Update_Graph();}
    void        Set_VisTrafo_SpreadInMin(double spread_min = 0)                     {vis_trafo_in_min = spread_min;     for(int i = 0; i < SLICE_2D_NUMBER_OF; i++) vViewer_Slices2D[i]->Set_VisTrafo_SpreadInMin(spread_min);  Update_Graph();}
    void        Set_VisTrafo_SpreadInMax(double spread_max = 255)                   {vis_trafo_in_max = spread_max;     for(int i = 0; i < SLICE_2D_NUMBER_OF; i++) vViewer_Slices2D[i]->Set_VisTrafo_SpreadInMax(spread_max);  Update_Graph();}
    void        Set_VisTrafo_Center     (double center = 0)                         {vis_trafo_center = center;         for(int i = 0; i < SLICE_2D_NUMBER_OF; i++) vViewer_Slices2D[i]->Set_VisTrafo_Center(center);           Update_Graph();}
    void        Set_VisTrafo_Divisor    (double divisor = 0)                        {vis_trafo_divisor = divisor;       for(int i = 0; i < SLICE_2D_NUMBER_OF; i++) vViewer_Slices2D[i]->Set_VisTrafo_Divisor(divisor);         Update_Graph();}
    void        Set_VisTrafo_Anchor     (double anchor = 127.5)                     {vis_trafo_anchor = anchor;         for(int i = 0; i < SLICE_2D_NUMBER_OF; i++) vViewer_Slices2D[i]->Set_VisTrafo_Anchor(anchor);           Update_Graph();}
    void        Set_VisTrafo_Range      (double range = 127.5)                      {vis_trafo_range = range;           for(int i = 0; i < SLICE_2D_NUMBER_OF; i++) vViewer_Slices2D[i]->Set_VisTrafo_Range(range);             Update_Graph();}
    void        Set_VisTrafo_Mode_Crop  (int mode = c_VIS_TRAFO_CROP_DYNAMIC)       {vis_trafo_mode_crop = mode;        for(int i = 0; i < SLICE_2D_NUMBER_OF; i++) vViewer_Slices2D[i]->Set_VisTrafo_Mode_Crop(mode);          Update_Graph();}
    void        Set_VisTrafo_Mode_Trafo (int mode = c_VIS_TRAFO_LINEAR)             {vis_trafo_mode_trafo = mode;       for(int i = 0; i < SLICE_2D_NUMBER_OF; i++) vViewer_Slices2D[i]->Set_VisTrafo_Mode_Trafo(mode);         Update_Graph();}
    void        Set_VisTrafo_Mode_Anchor(int mode = c_VIS_TRAFO_ANCHOR_DYNAMIC)     {vis_trafo_mode_anchor = mode;      for(int i = 0; i < SLICE_2D_NUMBER_OF; i++) vViewer_Slices2D[i]->Set_VisTrafo_Mode_Anchor(mode);        Update_Graph();}
    void        Set_VisTrafo_Mode_Range (int mode = c_VIS_TRAFO_RANGE_DYNAMIC)      {vis_trafo_mode_range = mode;       for(int i = 0; i < SLICE_2D_NUMBER_OF; i++) vViewer_Slices2D[i]->Set_VisTrafo_Mode_Range(mode);         Update_Graph();}
    void        Set_VisTrafo_Mode_Complex(int mode = c_COMPLEX2REAL_RE_IM)          {vis_trafo_mode_complex = mode;     for(int i = 0; i < SLICE_2D_NUMBER_OF; i++) vViewer_Slices2D[i]->Set_VisTrafo_Mode_Complex(mode);       Update_Graph();}

    void        Set_StoragePointer(D_Storage *pStorage, int index_dir2use)          {pStore = pStorage; default_dir_index = index_dir2use; state_default_dir = true;}

    int         Volume()                                                            {return volume_index_current;}
    int         Dim_extended0()                                                     {return v_dims_extended.size() == 3 ? v_dims_extended[0] : -1;}
    int         Dim_extended1()                                                     {return v_dims_extended.size() == 3 ? v_dims_extended[1] : -1;}
    int         Dim_extended2()                                                     {return v_dims_extended.size() == 3 ? v_dims_extended[2] : -1;}
    vector<int> Dims_extended()                                                     {return v_dims_extended;}
    bool        Dim_is_extended(int d)                                              {return (d == Dim_extended0()) || (d == Dim_extended1()) || (d == Dim_extended2());}
    int         Dim_fix0()                                                          {return v_dims_fix.size() == 3 ? v_dims_fix[0] : -1;}
    int         Dim_fix1()                                                          {return v_dims_fix.size() == 3 ? v_dims_fix[1] : -1;}
    int         Dim_fix2()                                                          {return v_dims_fix.size() == 3 ? v_dims_fix[2] : -1;}
    vector<int> Dims_fix()                                                          {return v_dims_fix;}
    int         Dim_is_fix(int d)                                                   {return !Dim_is_extended(d);}
    int         Plane_SliceXY()                                                     {return D_VisDat_Proc::PlaneFromDims(Dim_extended0(), Dim_extended1());}
    int         Plane_SliceXZ()                                                     {return D_VisDat_Proc::PlaneFromDims(Dim_extended0(), Dim_extended2());}
    int         Plane_SliceYZ()                                                     {return D_VisDat_Proc::PlaneFromDims(Dim_extended1(), Dim_extended2());}

    int         SaveVideo_SliceDim();
    int         SaveVideo_CameraRotationFull();
    int         TakeFrames_CameraRotationFull(vector<Mat> *pvMA_ViewsOut, size_t n_frames = 360);
    int         TakeFrames_SliceDim(vector<Mat> *pvMA_ViewsOut, int dim2loop);

    void        Update_Ui();

private slots:

    void            on_VolumeCurrent_Changed(int vol);

    //texture
    int             TextureData_CalcNew();
    int             Slice_2D_Mat_from_VD(Mat *pMA_SliceOut, D_VisDat_Slice_2D slice, double min_global, double max_global);
    int             TextureData_AppendSlice(Mat *pMA_toAppend, size_t slice_number);
    int             Show_Texture();

    void            set_VolumeScalingAndPosition();
    void            set_TextureSize();

    void            set_HD_shader(bool hd);
    void            set_preserve_opacity(bool preserve);
    void            set_draw_slices(bool draw);
    void            set_alpha_multiplier(double factor);
    void            set_shadow_quality(int shadow_quality_id);

    void            change_graph_background_color();

    void            check_volume_changes_and_trigger_slots();

    void            adapt_alpha_multiplier_step(double value);
    void            adapt_depth_scale_step(double value);

signals:


private:

   //error handler
    D_Error_Handler ER;
    void ERR(int err, QString func, QString detail);

    //Storage (needed for save dir defaults)
    D_Storage *pStore;
    int default_dir_index = 0;

    //populate CB
    void Populate_CB_Single(QComboBox *CB, QStringList QSL, int init_index = 0);

    //ui elements

    //layouts
    QGridLayout             *ui_layout_target;
    QGroupBox               *ui_GroupBox_3D_graph;
    QGroupBox               *ui_GroupBox_2D_slices;
    QGroupBox               *ui_GroupBox_Settings;
    QGroupBox               *ui_GroupBox_Settings_Volume;
  //QGroupBox               *ui_GroupBox_Settings_DrawCondition;
    QGroupBox               *ui_GroupBox_Settings_Alpha;
    QGroupBox               *ui_GroupBox_Settings_Graphics;
    QGroupBox               *ui_GroupBox_SaveAnimationVideo;

    //volume and slicing
    QComboBox               *ui_ComboBox_Volume;
    vector<QSpinBox*>       vui_SpinBox_DimIndices;

    //slices
    /*
    QLabel                  *ui_Label_2dSlice_XY;
    QLabel                  *ui_Label_2dSlice_XZ;
    QLabel                  *ui_Label_2dSlice_YZ;
    vector<QLabel*>         vui_Label_2dSlices;
    */
    vector<QGraphicsView*>  vui_GraphicsView_Slices2D;
    D_Viewer                Viewer_Slice2D_X;
    D_Viewer                Viewer_Slice2D_Y;
    D_Viewer                Viewer_Slice2D_Z;
    vector<D_Viewer*>       vViewer_Slices2D;
    enum SLICE_2D {
        SLICE_2D_X,
        SLICE_2D_Y,
        SLICE_2D_Z,
        SLICE_2D_NUMBER_OF
    };


    //settings

    //draw conditions

    //alpha
    QComboBox               *ui_ComboBox_AlphaMode;
    QDoubleSpinBox          *ui_DoubleSpinBox_AlphaMultiplier;

    //graphics
    QPushButton             *ui_PushButton_BackgroundColor;
    QDoubleSpinBox          *ui_DoubleSpinBox_ScaleDepth;
    QCheckBox               *ui_CheckBox_HeatColor;
    QCheckBox               *ui_CheckBox_Slices_Show;
    QCheckBox               *ui_CheckBox_Slices_SliceVolume;
    QCheckBox               *ui_CheckBox_Slices_KeepAspectRatio;
    QCheckBox               *ui_CheckBox_Shader_HD;
    QCheckBox               *ui_CheckBox_OpacityPreserve;
    QComboBox               *ui_ComboBox_ShadowQuality;
    QSpacerItem             *ui_spacer_Settings;
    QPushButton             *ui_PushButton_SaveAnimationVideo_Rotation;
    QPushButton             *ui_PushButton_SaveAnimationVideo_Slice;

    //VD to be displayed
    D_VisDat_Obj            *pVD_Data;

    //selected volume
    int                     volume_index_current = c_VOLUME_XYZ;
    vector<int>             v_dim_indeces_last = {0, 0, 0, 0, 0, 0};
    vector<int>             v_dims_extended = {c_DIM_X, c_DIM_Y, c_DIM_Z};
    vector<int>             v_dims_fix = {c_DIM_T, c_DIM_S, c_DIM_P};


    //graph elements
    Q3DScatter              *graph_scatter;
    QWidget                 *container_widget_scatter;
    QCustom3DVolume         *volume_item;

    //texture data
    QVector<uchar>          vTextureData;
    QVector<QRgb>           vColorTable;

    //vis trafo
    bool                    vis_trafo_active       = false;
    double                  vis_trafo_in_min       = 0;
    double                  vis_trafo_in_max       = 255;
    double                  vis_trafo_gamma        = 1.0;
    double                  vis_trafo_center       = 0.0;
    double                  vis_trafo_divisor      = 1.0;
    double                  vis_trafo_anchor       = 0;
    double                  vis_trafo_range        = 1;
    int                     vis_trafo_mode_crop    = c_VIS_TRAFO_CROP_DYNAMIC;
    int                     vis_trafo_mode_trafo   = c_VIS_TRAFO_LINEAR;
    int                     vis_trafo_mode_anchor  = c_VIS_TRAFO_ANCHOR_DYNAMIC;
    int                     vis_trafo_mode_range   = c_VIS_TRAFO_RANGE_DYNAMIC;
    int                     vis_trafo_mode_complex = c_COMPLEX2REAL_RE_IM;

    //states
    bool            state_ui_init = false;
    bool            state_VD_set = false;
    bool            state_texture_set = false;
    bool            state_graph_up2date = false;
    bool            state_graph_updating = false;
    bool            state_default_dir = false;
};



#endif // D_VIEWER_3D_H
