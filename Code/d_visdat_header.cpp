#include "d_visdat_header.h"

D_VisDat_Header::D_VisDat_Header()
{
    t_year      = QDateTime::currentDateTime().date().year();
    t_month     = QDateTime::currentDateTime().date().month();
    t_day       = QDateTime::currentDateTime().date().day();
    t_hour      = QDateTime::currentDateTime().time().hour();
    t_minute    = QDateTime::currentDateTime().time().minute();
    t_second    = QDateTime::currentDateTime().time().second();
}

D_VisDat_Header::D_VisDat_Header(vector<int> v_sizes, int type)
{
    if(v_sizes.size() == c_DIM_NUMBER_OF)
    {
        dim_size_x = v_sizes[c_DIM_X];
        dim_size_y = v_sizes[c_DIM_Y];
        dim_size_z = v_sizes[c_DIM_Z];
        dim_size_t = v_sizes[c_DIM_T];
        dim_size_s = v_sizes[c_DIM_S];
        dim_size_p = v_sizes[c_DIM_P];
    }

    type_of_mat = type;

    t_year      = QDateTime::currentDateTime().date().year();
    t_month     = QDateTime::currentDateTime().date().month();
    t_day       = QDateTime::currentDateTime().date().day();
    t_hour      = QDateTime::currentDateTime().time().hour();
    t_minute    = QDateTime::currentDateTime().time().minute();
    t_second    = QDateTime::currentDateTime().time().second();
}

QString D_VisDat_Header::SaveTime()
{
    return "This VisDat_Obj was saved on " +
            QString::number(t_year) + "/" +
            QString::number(t_month) + "/" +
            QString::number(t_day) + " at " +
            QString::number(t_hour) + ":" +
            QString::number(t_minute) + ":" +
            QString::number(t_second);
}

int D_VisDat_Header::set_Size(vector<int> v_sizes)
{
    if(v_sizes.size() != c_DIM_NUMBER_OF)
        return ER_dim_missmatch;

    dim_size_x = v_sizes[c_DIM_X];
    dim_size_y = v_sizes[c_DIM_Y];
    dim_size_z = v_sizes[c_DIM_Z];
    dim_size_t = v_sizes[c_DIM_T];
    dim_size_s = v_sizes[c_DIM_S];
    dim_size_p = v_sizes[c_DIM_P];

    return ER_okay;
}
