/************************************
 *   added:     27.07.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_VIEWER_PLOT_3D_H
#define D_VIEWER_PLOT_3D_H

//own
#include <d_enum.h>
#include <d_error_handler.h>
#include <d_visdat_obj.h>
#include <d_visdat_proc.h>

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
#include <QFileInfo>
#include <QDir>
#include <QElapsedTimer>
#include <QScrollBar>
#include <QGridLayout>
#include <QWidget>
#include <QtCore/qmath.h>
#include <QtCore/qrandom.h>
#include <QtWidgets/QComboBox>
#include <QLabel>

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

class D_Viewer_Plot_3D : public QWidget
{
    Q_OBJECT
public:
    D_Viewer_Plot_3D();
    D_Viewer_Plot_3D(QGridLayout *target_layout);
    ~D_Viewer_Plot_3D();

    //init basic stuff and ui
    int init(QGridLayout *target_layout);

    //clear
    void    clear_graph_all();
    void    clear_graph_scatter();
    void    clear_graph_heightmap();

    //plot cool
    int     plot_VD_custom(D_VisDat_Obj *pVD, size_t mode, size_t cond, size_t val_handle, size_t axis_x, size_t axis_y, size_t axis_z, size_t axis_v, size_t plane_index_xy, size_t dim_index_surfaces, size_t surface_mode, size_t texture_mode, size_t marker, size_t shadow, bool background, bool grid, bool smooth, bool draw_surface, bool draw_wireframe);
    int     plot_VD_Scatter(D_VisDat_Obj *pVD, size_t cond, size_t val_handle, size_t axis_x, size_t axis_y, size_t axis_z, size_t axis_v, size_t marker, size_t shadow, bool background, bool grid, bool smooth, bool called_internally = false);
    int     plot_VD_Heightmap(D_VisDat_Obj *pVD, size_t plane_index_xy, size_t dim_index_surfaces, size_t axis_z, size_t axis_v, size_t surface_mode, size_t texture_mode, size_t shadow, bool background, bool grid, bool draw_surface, bool draw_wireframe, bool called_internally = false);

    int     plot_ScatterData_Color(vector<double> vX, vector<double> vY, vector<double> vZ, vector<double> vV, size_t color_handle, size_t marker, size_t shadow, bool background, bool grid, bool smooth, QString axis_x, QString axis_y, QString axis_z, QString axis_v, bool called_internally = false);
    int     plot_Tree(vector<Point3d> vNodesCoord, vector<Point3d> vEdgeCoordBegins, vector<Point3d> vEdgeCoordEnds, vector<QColor> vNodeColor, vector<QColor> vEdgeColor, size_t shadow, bool background, bool grid, bool smooth, QString axis_x, QString axis_y, QString axis_z, size_t points_per_edge = 5, double size_nodes = 0.1, double size_edge = 0.05, bool called_internally = false);
    int     plot_Heightmap(vector<Mat> *pvMA_Height, vector<QImage> *pvQI_Texture, size_t shadow, bool background, bool grid, QString axis_x = "X", QString axis_y = "Y", QString axis_z = "Z", bool draw_surface = true, bool draw_wireframe = false, bool called_internally = false);

signals:


private:

    QAbstract3DSeries::Mesh     marker_from_id(int marker_id);
    size_t                      series_count_from_color_handle_id(size_t color_handle_id);
    QColor                      series_color(size_t series_count, size_t series_index, size_t color_handle);

    void    show_graph_type(size_t graph_type_id);

    void    clear_layout();

    int     dimIndex_FromAxisIndex(size_t axis_index);

    int     ValueAxisMat(Mat *pMA_Out, Mat *pMA_In, size_t axis_index, Vec<int, c_DIM_NUMBER_OF> slice_pos, double default_value = 0, bool force_double = false);
    int     SurfaceTextureImage(QImage *pQI_Out, Mat *pMA_In, size_t texture_mode, size_t axis_index_value, Vec<int, c_DIM_NUMBER_OF> slice_pos, double default_value = 0, bool use_fix_crop_range = false, double in_min = 0, double in_max = 1);

    //error handler
    D_Error_Handler ER;
    void ERR(int err, QString func, QString detail);

    //ui
    QGridLayout *layout_in_ui;
    QWidget     *container_widget_scatter;
    QWidget     *container_widget_heightmap;

    //data
    Q3DScatter  *graph_scatter;
    Q3DSurface  *graph_heightmap;

    //states
    bool state_ui_init = false;
    bool state_container_widget_exists = false;
    bool state_plot_active = false;
    bool state_plotting = false;
};

#endif // D_VIEWER_PLOT_3D_H
