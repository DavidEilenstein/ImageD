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
    //target layout
    ui_layout_target = target_layout;

    //main layout
    ui_layoutH_main = new QHBoxLayout(this);
    ui_layout_target->addLayout(ui_layoutH_main, 0, 0);

    //groupboxes
    ui_GroupBox_3D_graph = new QGroupBox("3D Volume", this);
    ui_GroupBox_3D_graph->setLayout(new QGridLayout(this));

    //graph
    graph_scatter = new Q3DScatter();

    //graph container
    container_widget_scatter = createWindowContainer(graph_scatter);
    ui_GroupBox_3D_graph->layout()->addWidget(container_widget_scatter);

    //defaults for visuals
    graph_scatter->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetFrontHigh);

    state_ui_init = true;
}

void D_Viewer_3D::ERR(int err, QString func, QString detail)
{
    ER.ERR(err, "D_Viewer_3D", func, detail);
}


