/************************************
 *   added:     12.01.2022          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_bio_attribute_filter.h"

D_Bio_Attribute_Filter::D_Bio_Attribute_Filter() : QWidget()
{

}

D_Bio_Attribute_Filter::D_Bio_Attribute_Filter(QGroupBox* ui_box) : QWidget()
{
    set_ui_groupbox(ui_box);
}

bool D_Bio_Attribute_Filter::set_ui_groupbox(QGroupBox* ui_box)
{
    qDebug() << "D_Bio_Attribute_Filter::set_ui_groupbox" << "start";

    //no grp box?
    if(ui_box == nullptr)
        return false;

    /*
    //box not empty?
    if(!ui_box->layout()->isEmpty())
        return false;
        */

    qDebug() << "D_Bio_Attribute_Filter::set_ui_groupbox" << "checks passed";

    //set box
    ui_grpbox_master = ui_box;
    state_grpbox_set = true;

    qDebug() << "D_Bio_Attribute_Filter::set_ui_groupbox" << "finisehd";
    return Ui_Init();
}

bool D_Bio_Attribute_Filter::Ui_Init()
{
    qDebug() << "D_Bio_Attribute_Filter::Ui_Init" << "start";

    if(!state_grpbox_set)
        return false;

    qDebug() << "D_Bio_Attribute_Filter::Ui_Init" << "checks passed";

    //------------------------------------------------------ layouts
    qDebug() << "D_Bio_Attribute_Filter::Ui_Init" << "layouts";

    //CONTINUE HERE

    //master
    qDebug() << "master";
    ui_layoutH_master = new QHBoxLayout(this);
    ui_layoutH_master->setSpacing(1);
    ui_layoutH_master->setContentsMargins(0, 0, 0, 0);

    //left
    qDebug() << "l";
    ui_layoutV_l = new QVBoxLayout(this);
    ui_layoutV_l->setSpacing(1);
    ui_layoutV_l->setContentsMargins(0, 0, 0, 0);
    ui_layoutH_master->addLayout(ui_layoutV_l, 0);

    //line
    qDebug() << "line";
    ui_line_v = new QFrame(this);
    ui_line_v->setFrameShape(QFrame::VLine);
    ui_line_v->setFrameShadow(QFrame::Sunken);
    ui_line_v->setLineWidth(3);
    ui_layoutH_master->addWidget(ui_line_v, 1);

    //right
    qDebug() << "r";
    ui_layoutV_r = new QVBoxLayout(this);
    ui_layoutV_r->setSpacing(1);
    ui_layoutV_r->setContentsMargins(0, 0, 0, 0);
    ui_layoutH_master->addLayout(ui_layoutV_r, 2);

    //left top
    qDebug() << "lt";
    ui_layoutH_lt = new QHBoxLayout(this);
    ui_layoutH_lt->setSpacing(1);
    ui_layoutH_lt->setContentsMargins(1, 1, 1, 1);
    ui_layoutV_l->addLayout(ui_layoutH_lt, 0);

    //left bottom
    qDebug() << "lb";
    ui_layoutH_lb = new QHBoxLayout(this);
    ui_layoutH_lb->setSpacing(1);
    ui_layoutH_lb->setContentsMargins(1, 1, 1, 1);
    ui_layoutV_l->addLayout(ui_layoutH_lb, 1);

    //right top
    qDebug() << "t";
    ui_layoutH_rt = new QHBoxLayout(this);
    ui_layoutH_rt->setSpacing(1);
    ui_layoutH_rt->setContentsMargins(1, 1, 1, 1);
    ui_layoutV_r->addLayout(ui_layoutH_rt, 0);

    //right bottom
    qDebug() << "rb";
    ui_layoutH_rb = new QHBoxLayout(this);
    ui_layoutH_rb->setSpacing(1);
    ui_layoutH_rb->setContentsMargins(1, 1, 1, 1);
    ui_layoutV_r->addLayout(ui_layoutH_rb, 1);

    //------------------------------------------------------ elements



    //------------------------------------------------------ finish

    qDebug() << "D_Bio_Attribute_Filter::Ui_Init" << "finished";
    state_ui_init = true;
    return true;
}
