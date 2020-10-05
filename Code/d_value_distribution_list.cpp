/************************************
 *   added:     12.12.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_value_distribution_list.h"

D_Value_Distribution_List::D_Value_Distribution_List()
{

}

D_Value_Distribution_List::D_Value_Distribution_List(Mat *pMA_Label, Mat *pMA_Value, int connectivity)
{
    set_Mats(pMA_Label, pMA_Value, connectivity);
}

int D_Value_Distribution_List::set_Mats(Mat *pMA_Label, Mat *pMA_Value, int connectivity)
{
    if((pMA_Label->type() != CV_16UC1) && (pMA_Label->type() != CV_32SC1))      return ER_type_bad;
    if(pMA_Label->size != pMA_Value->size)                                      return ER_size_missmatch;
    if(pMA_Value->channels() != 1)                                              return ER_channel_bad;

    //comp list
    m_CompList.set_Mat(pMA_Label, connectivity);

    //size
    int area = pMA_Value->rows * pMA_Value->cols;

    //value img
    MA_Values = Mat::zeros(pMA_Value->size(), CV_64FC1);
    double* ptr_val = reinterpret_cast<double*>(MA_Values.data);

    //in img -> val img
    switch (pMA_Value->type()) {

    case CV_8UC1:
    {
        uchar* ptr_in = reinterpret_cast<uchar*>(pMA_Value->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_val++)
            *ptr_val = static_cast<double>(*ptr_in);
    }
        break;

    case CV_8SC1:
    {
        char* ptr_in = reinterpret_cast<char*>(pMA_Value->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_val++)
            *ptr_val = static_cast<double>(*ptr_in);
    }
        break;

    case CV_16UC1:
    {
        ushort* ptr_in = reinterpret_cast<ushort*>(pMA_Value->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_val++)
            *ptr_val = static_cast<double>(*ptr_in);
    }
        break;

    case CV_16SC1:
    {
        short* ptr_in = reinterpret_cast<short*>(pMA_Value->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_val++)
            *ptr_val = static_cast<double>(*ptr_in);
    }
        break;

    case CV_32SC1:
    {
        int* ptr_in = reinterpret_cast<int*>(pMA_Value->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_val++)
            *ptr_val = static_cast<double>(*ptr_in);
    }
        break;

    case CV_32FC1:
    {
        float* ptr_in = reinterpret_cast<float*>(pMA_Value->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_val++)
            *ptr_val = static_cast<double>(*ptr_in);
    }
        break;

    case CV_64FC1:
    {
        double* ptr_in = reinterpret_cast<double*>(pMA_Value->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_val++)
            *ptr_val = static_cast<double>(*ptr_in);
    }
        break;

    default:
        return ER_bitdepth_bad;
    }


    m_Mats_Set = true;
    return ER_okay;
}

double D_Value_Distribution_List::get_Values(int comp, int axe, int cla, int val)
{
    if(!Calced_All)
        calc_All();

    if(comp >= vvvv_ComAxeClaVal.size())                    comp = 0;
    if(axe  >= vvvv_ComAxeClaVal[comp].size())              axe  = 0;
    if(cla  >= vvvv_ComAxeClaVal[comp][axe].size())         cla  = 0;
    if(val  >= vvvv_ComAxeClaVal[comp][axe][cla].size())    val  = 0;

    return vvvv_ComAxeClaVal[comp][axe][cla][val];
}

vector<double> D_Value_Distribution_List::get_Values(int comp, int axe, int cla)
{
    if(!Calced_All)
        calc_All();

    if(comp >= vvvv_ComAxeClaVal.size())                    comp = 0;
    if(axe  >= vvvv_ComAxeClaVal[comp].size())              axe  = 0;
    if(cla  >= vvvv_ComAxeClaVal[comp][axe].size())         cla  = 0;

    return vvvv_ComAxeClaVal[comp][axe][cla];
}

vector<vector<double>> D_Value_Distribution_List::get_Values(int comp, int axe)
{
    if(!Calced_All)
        calc_All();

    if(comp >= vvvv_ComAxeClaVal.size())                    comp = 0;
    if(axe  >= vvvv_ComAxeClaVal[comp].size())              axe  = 0;

    return vvvv_ComAxeClaVal[comp][axe];
}

vector<vector<vector<double>>> D_Value_Distribution_List::get_Values(int comp)
{
    if(!Calced_All)
        calc_All();

    if(comp >= vvvv_ComAxeClaVal.size())                    comp = 0;

    return vvvv_ComAxeClaVal[comp];
}

vector<vector<vector<vector<double>>>> D_Value_Distribution_List::get_Values()
{
    if(!Calced_All)
        calc_All();

    return vvvv_ComAxeClaVal;
}

double D_Value_Distribution_List::get_Stat(int comp, int axe, int cla, int stat)
{
    if(!Calced_All)
        calc_All();

    if(comp >= vvvv_ComAxeClaSta.size())                    comp = 0;
    if(axe  >= vvvv_ComAxeClaSta[comp].size())              axe  = 0;
    if(cla  >= vvvv_ComAxeClaSta[comp][axe].size())         cla  = 0;
    if(stat >= vvvv_ComAxeClaSta[comp][axe][cla].size())    stat = 0;

    return vvvv_ComAxeClaSta[comp][axe][cla][stat];
}

vector<double> D_Value_Distribution_List::get_Stat(int comp, int axe, int cla)
{
    if(!Calced_All)
        calc_All();

    if(comp >= vvvv_ComAxeClaSta.size())                    comp = 0;
    if(axe  >= vvvv_ComAxeClaSta[comp].size())              axe  = 0;
    if(cla  >= vvvv_ComAxeClaSta[comp][axe].size())         cla  = 0;

    return vvvv_ComAxeClaSta[comp][axe][cla];
}

vector<vector<double>> D_Value_Distribution_List::get_Stat(int comp, int axe)
{
    if(!Calced_All)
        calc_All();

    if(comp >= vvvv_ComAxeClaSta.size())                    comp = 0;
    if(axe  >= vvvv_ComAxeClaSta[comp].size())              axe  = 0;

    return vvvv_ComAxeClaSta[comp][axe];
}

vector<vector<vector<double>>> D_Value_Distribution_List::get_Stat(int comp)
{
    if(!Calced_All)
        calc_All();

    if(comp >= vvvv_ComAxeClaSta.size())                    comp = 0;

    return vvvv_ComAxeClaSta[comp];
}

vector<vector<vector<vector<double>>>> D_Value_Distribution_List::get_Stat()
{
    if(!Calced_All)
        calc_All();

    return vvvv_ComAxeClaSta;
}

vector<vector<double> > D_Value_Distribution_List::get_Axe(int axe, int stat)
{
    if(!Calced_All)
        calc_All();

    if(axe  >= c_AXE_NUMBER_OF)         axe  = 0;
    if(stat >= c_STAT_NUMBER_OF_STATS)  stat = 0;

    //allocate
    vector<vector<double>> vvd_ComCla;

    //component
    vvd_ComCla.resize(vvvv_ComAxeClaSta.size());
    for(int com = 0; com < vvd_ComCla.size(); com++)
    {
        //class on axe
        vvd_ComCla[com].resize(vvvv_ComAxeClaSta[com][axe].size());
        for(int cla = 0; cla < vvd_ComCla[com].size(); cla++)
        {
            vvd_ComCla[com][cla] = vvvv_ComAxeClaSta[com][axe][cla][stat];
        }
    }

    return vvd_ComCla;
}

void D_Value_Distribution_List::calc_All()
{
    if(!m_Mats_Set)
        return;

    Calced_All = false;

    //qDebug() << "calc_ComAxeClaVal";
    calc_ComAxeClaVal();
    //qDebug() << "calc_ComAxeClaSta";
    calc_ComAxeClaSta();
    //qDebug() << "calced all!!! :-)";

    Calced_All = true;
}

void D_Value_Distribution_List::calc_ComAxeClaVal()
{
    if(!m_Mats_Set)
        return;

    Calced_ComAxeClaVal = false;

    //clear old content
    vvvv_ComAxeClaVal.clear();

    //Components
    vvvv_ComAxeClaVal.resize(m_CompList.size());
    for(int com = 0; com < m_CompList.size(); com++)
    {
        //qDebug() << "com" << com << "==============================================================";

        //Axe

        //number of axes
        vvvv_ComAxeClaVal[com].resize(c_AXE_NUMBER_OF);

        //classes on axe
        int size_x = m_CompList.get_Feature(com, c_FEAT_RECT_AXEPAR_WIDTH);
        int size_y = m_CompList.get_Feature(com, c_FEAT_RECT_AXEPAR_HEIGHT);
        int size_r = m_CompList.get_Feature(com, c_FEAT_CIRC_CIRCUMS_RADIUS) + 1;
        int size_a = 360;

        //ensure there will be no vectors of size 0
        if(size_x < 1)  size_x = 1;
        if(size_y < 1)  size_y = 1;
        if(size_r < 1)  size_r = 1;
        if(size_a < 1)  size_a = 1;

        //resize axe
        vvvv_ComAxeClaVal[com][c_AXE_CARTESIAN_X ].resize(size_x);
        vvvv_ComAxeClaVal[com][c_AXE_CARTESIAN_Y ].resize(size_y);
        vvvv_ComAxeClaVal[com][c_AXE_POLAR_RADIUS].resize(size_r);
        vvvv_ComAxeClaVal[com][c_AXE_POLAR_ANGLE ].resize(size_a);

        //stuff describing component
        Point2f         center  = m_CompList.get_Centroid(com);
        vector<Point>   v_coord = m_CompList.get_Coordinates(com);
        Point2f         offset  = m_CompList.get_Offset(com);

        //member pixels of component
        for(int px = 0; px < v_coord.size(); px++)
        {
            //qDebug() << "px" << px << "start---------------------------";

            //pos
            Point2f pos     = v_coord[px];
            Point2f pos2off = pos - offset;
            Point2f pos2cen = pos - center;
            //qDebug() << "pos calced";

            //axe position (=class)
            int x           = static_cast<int>(pos2off.x);
            int y           = static_cast<int>(pos2off.y);
            int r           = static_cast<int>(norm(pos2cen));
            int a           = static_cast<int>(atan2(pos2cen.y, pos2cen.x) * Rad2Grad + 179);
            //qDebug() << "x/y/r/a" << x << y << r << a;

            //val
            double val      = MA_Values.at<double>(v_coord[px]);
            //qDebug() << "val" << val;

            //check for indices in range:
            if(x >= size_x) {x = size_x - 1;}
            if(x < 0)       {x = 0;}
            if(y >= size_y) {y = size_y - 1;}
            if(y < 0)       {y = 0;}
            if(r >= size_r) {r = size_r - 1;}
            if(r < 0)       {r = 0;}
            if(a >= size_a) {a = size_a - 1;}
            if(a < 0)       {a = 0;}

            //export
            vvvv_ComAxeClaVal[com][c_AXE_CARTESIAN_X ][x].push_back(val);
            vvvv_ComAxeClaVal[com][c_AXE_CARTESIAN_Y ][y].push_back(val);
            vvvv_ComAxeClaVal[com][c_AXE_POLAR_RADIUS][r].push_back(val);
            vvvv_ComAxeClaVal[com][c_AXE_POLAR_ANGLE ][a].push_back(val);
            //qDebug() << "export";

            //qDebug() << "px" << px << "end-----------------------------";
        }
    }

    Calced_ComAxeClaVal = true;
}

void D_Value_Distribution_List::calc_ComAxeClaSta()
{
    if(!Calced_ComAxeClaVal)
        return;

    Calced_ComAxeClaSta = false;

    //clear old content
    vvvv_ComAxeClaSta.clear();

    //Components
    vvvv_ComAxeClaSta.resize(vvvv_ComAxeClaVal.size());
    for(int com = 0; com < vvvv_ComAxeClaSta.size(); com++)
    {
        //Axe
        vvvv_ComAxeClaSta[com].resize(vvvv_ComAxeClaVal[com].size());
        for(int axe = 0; axe < vvvv_ComAxeClaSta[com].size(); axe++)
        {
            //class
            vvvv_ComAxeClaSta[com][axe].resize(vvvv_ComAxeClaVal[com][axe].size());
            for(int cla = 0; cla < vvvv_ComAxeClaSta[com][axe].size(); cla++)
            {
                D_Stat::Calc_Stats(
                            &(vvvv_ComAxeClaSta[com][axe][cla]),
                            vvvv_ComAxeClaVal[com][axe][cla],
                            true);
            }
        }
    }

    Calced_ComAxeClaSta = true;
}
