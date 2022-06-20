/************************************
 *   added:     05.07.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_img_proc_3d.h"

D_Img_Proc_3D::D_Img_Proc_3D()
{
    //never use it
}

int D_Img_Proc_3D::Duplicate(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->dims != 3)
        return ER_dim_3D_only;

    *pMA_Out = pMA_In->clone();

    return ER_okay;
}

int D_Img_Proc_3D::Convert_Uchar_1C(Mat *pMA_Out, Mat *pMA_In)
{
    //qDebug() << "Convert_Uchar_1C" << "start";
    if(pMA_In->channels() != 1)     return ER_channel_bad;
    if(pMA_In->dims != 3)           return ER_dim_3D_only;

    //size
    //qDebug() << "Convert_Uchar_1C" << "size";
    int sz_x = pMA_In->size[0];
    int sz_y = pMA_In->size[1];
    int sz_z = pMA_In->size[2];
    int vol = sz_x * sz_y * sz_z;
    int sz[] = {sz_x, sz_y, sz_z};
    //qDebug() << "Convert_Uchar_1C" << "in size (x/y/z):" << *sz << "vol:" << vol;

    //out img
    //qDebug() << "Convert_Uchar_1C" << "allocate out";
    *pMA_Out = Mat::zeros(3, sz, CV_8UC1);
    uchar* ptr_out = reinterpret_cast<uchar*>(pMA_Out->data);
    //qDebug() << "Convert_Uchar_1C" << "out size (x/y/z):" << pMA_Out->size[0] << pMA_Out->size[1] << pMA_Out->size[2] << "vol:" << vol;

    //in img
    //qDebug() << "Convert_Uchar_1C" << "switch types";
    switch (pMA_In->type()) {

    case CV_8UC1:
    {
        uchar* ptr_in = reinterpret_cast<uchar*>(pMA_In->data);
        for(int px = 0; px < vol; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(*ptr_in);
    }
        break;

    case CV_8SC1:
    {
        char* ptr_in = reinterpret_cast<char*>(pMA_In->data);
        for(int px = 0; px < vol; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(*ptr_in);
    }
        break;

    case CV_16UC1:
    {
        ushort* ptr_in = reinterpret_cast<ushort*>(pMA_In->data);
        for(int px = 0; px < vol; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(*ptr_in);
    }
        break;

    case CV_16SC1:
    {
        short* ptr_in = reinterpret_cast<short*>(pMA_In->data);
        for(int px = 0; px < vol; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(*ptr_in);
    }
        break;

    case CV_32SC1:
    {
        int* ptr_in = reinterpret_cast<int*>(pMA_In->data);
        for(int px = 0; px < vol; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(*ptr_in);
    }
        break;

    case CV_32FC1:
    {
        float* ptr_in = reinterpret_cast<float*>(pMA_In->data);
        for(int px = 0; px < vol; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(*ptr_in);
    }
        break;

    case CV_64FC1:
    {
        double* ptr_in = reinterpret_cast<double*>(pMA_In->data);
        for(int px = 0; px < vol; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(*ptr_in);
    }
        break;

    default:
        return ER_bitdepth_bad;
    }

    return ER_okay;
}

int D_Img_Proc_3D::Convert_Double_1C(Mat *pMA_Out, Mat *pMA_In)
{
    //qDebug() << "Convert_Double_1C" << "start";
    if(pMA_In->channels() != 1)     return ER_channel_bad;
    if(pMA_In->dims != 3)           return ER_dim_3D_only;

    //size
    //qDebug() << "Convert_Double_1C" << "size";
    int sz_x = pMA_In->size[0];
    int sz_y = pMA_In->size[1];
    int sz_z = pMA_In->size[2];
    int vol = sz_x * sz_y * sz_z;
    int sz[] = {sz_x, sz_y, sz_z};
    //qDebug() << "Convert_Double_1C" << "in size (x/y/z):" << *sz << "vol:" << vol;

    //out img
    //qDebug() << "Convert_Double_1C" << "allocate out";
    *pMA_Out = Mat::zeros(3, sz, CV_64FC1);
    double* ptr_out = reinterpret_cast<double*>(pMA_Out->data);
    //qDebug() << "Convert_Double_1C" << "out size (x/y/z):" << pMA_Out->size[0] << pMA_Out->size[1] << pMA_Out->size[2] << "vol:" << vol;

    //in img
    //qDebug() << "Convert_Double_1C" << "switch types";
    switch (pMA_In->type()) {

    case CV_8UC1:
    {
        uchar* ptr_in = reinterpret_cast<uchar*>(pMA_In->data);
        for(int px = 0; px < vol; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<double>(*ptr_in);
    }
        break;

    case CV_8SC1:
    {
        char* ptr_in = reinterpret_cast<char*>(pMA_In->data);
        for(int px = 0; px < vol; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<double>(*ptr_in);
    }
        break;

    case CV_16UC1:
    {
        ushort* ptr_in = reinterpret_cast<ushort*>(pMA_In->data);
        for(int px = 0; px < vol; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<double>(*ptr_in);
    }
        break;

    case CV_16SC1:
    {
        short* ptr_in = reinterpret_cast<short*>(pMA_In->data);
        for(int px = 0; px < vol; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<double>(*ptr_in);
    }
        break;

    case CV_32SC1:
    {
        int* ptr_in = reinterpret_cast<int*>(pMA_In->data);
        for(int px = 0; px < vol; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<double>(*ptr_in);
    }
        break;

    case CV_32FC1:
    {
        float* ptr_in = reinterpret_cast<float*>(pMA_In->data);
        for(int px = 0; px < vol; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<double>(*ptr_in);
    }
        break;

    case CV_64FC1:
    {
        double* ptr_in = reinterpret_cast<double*>(pMA_In->data);
        for(int px = 0; px < vol; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<double>(*ptr_in);
    }
        break;

    default:
        return ER_bitdepth_bad;
    }

    return ER_okay;
}

int D_Img_Proc_3D::Convert_Double(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty())     return ER_okay;
    if(pMA_In->dims != 3)   return ER_dim_3D_only;

    switch (pMA_In->channels()) {

    case 1:
    {
        int ER = Convert_Double_1C(
                    pMA_Out,
                    pMA_In);
        if(ER != ER_okay)   return ER;
    }
        break;

    case 2:
    {
        Mat MA_tmp_in[2];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_double[2];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Convert_Double_1C(
                        &(MA_tmp_double[c]),
                        &(MA_tmp_in[c]));
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_double,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_double[c].release();
        }
    }
        break;

    case 3:
    {
        Mat MA_tmp_in[3];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_double[3];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Convert_Double_1C(
                        &(MA_tmp_double[c]),
                        &(MA_tmp_in[c]));
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_double,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_double[c].release();
        }
    }
        break;

    case 4:
    {
        Mat MA_tmp_in[4];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_double[4];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Convert_Double_1C(
                        &(MA_tmp_double[c]),
                        &(MA_tmp_in[c]));
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_double,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_double[c].release();
        }
    }
        break;

    default:
        break;
    }

    return ER_okay;
}

int D_Img_Proc_3D::Pad_Border(Mat *pMA_Out, Mat *pMA_In, int border_size_x, int border_size_y, int border_size_z, int border_type, double border_val)
{
    //Erorrs
    if(pMA_In->empty())                                                                                     return ER_empty;
    if(pMA_In->dims != 3)                                                                                   return ER_dim_3D_only;
    if(border_size_x < 0 || border_size_y < 0 || border_size_z < 0)                                         return ER_parameter_bad;
    if(border_type != BORDER_CONSTANT && border_type != BORDER_REPLICATE && border_type != BORDER_DEFAULT)  return ER_parameter_bad;

    //sizes
    int sz_in_x     = pMA_In->size[0];
    int sz_in_y     = pMA_In->size[1];
    int sz_in_z     = pMA_In->size[2];
    int sz_out_x    = sz_in_x + 2 * border_size_x;
    int sz_out_y    = sz_in_y + 2 * border_size_y;
    int sz_out_z    = sz_in_z + 2 * border_size_z;
    int sz_out[]    = {sz_out_x, sz_out_y, sz_out_z};
    int offset_x    = border_size_x;
    int offset_y    = border_size_y;
    int offset_z    = border_size_z;

    //Allocate Out
    *pMA_Out        = Mat(3, sz_out, pMA_In->type());

    //loop positions
    Vec<int, 3> v_pos_in    = {offset_x, offset_y, offset_z};
    Vec<int, 3> v_pos_out   = {0, 0, 0};

    //default -> constant
    if(border_type == BORDER_DEFAULT)
        border_type = BORDER_CONSTANT;

    switch (border_type) {

    case BORDER_CONSTANT:   //==============================================================================================

        switch (pMA_In->type()) {

        case CV_8UC1:
            for(int z = 0; z < sz_out_z; z++)                                                   //loop x_out
                for(int y = 0; y < sz_out_y; y++)                                               //loop y_out
                    for(int x = 0; x < sz_out_x; x++)                                           //loop z_out
                    {
                        v_pos_out = {x, y, z};                                                  //pos out

                        if( x >= offset_x && x < (sz_in_x + offset_x) &&                        //x in range?
                            y >= offset_y && y < (sz_in_y + offset_y) &&                        //y in range?
                            z >= offset_z && z < (sz_in_z + offset_z))                          //z in range?
                        {
                            v_pos_in = {x - offset_x, y - offset_y, z - offset_z};              //pos in
                            pMA_Out->at<uchar>(v_pos_out) = pMA_In->at<uchar>(v_pos_in);        //copy pixel
                        }
                        else
                        {
                            pMA_Out->at<uchar>(v_pos_out) = static_cast<uchar>(border_val);     //set to const value
                        }
                    }
            break;

        case CV_8SC1:
            for(int z = 0; z < sz_out_z; z++)                                                   //loop x_out
                for(int y = 0; y < sz_out_y; y++)                                               //loop y_out
                    for(int x = 0; x < sz_out_x; x++)                                           //loop z_out
                    {
                        v_pos_out = {x, y, z};                                                  //pos out

                        if( x >= offset_x && x < (sz_in_x + offset_x) &&                        //x in range?
                            y >= offset_y && y < (sz_in_y + offset_y) &&                        //y in range?
                            z >= offset_z && z < (sz_in_z + offset_z))                          //z in range?
                        {
                            v_pos_in = {x - offset_x, y - offset_y, z - offset_z};              //pos in
                            pMA_Out->at<char>(v_pos_out) = pMA_In->at<char>(v_pos_in);          //copy pixel
                        }
                        else
                        {
                            pMA_Out->at<char>(v_pos_out) = static_cast<char>(border_val);       //set to const value
                        }
                    }
            break;

        case CV_16UC1:
            for(int z = 0; z < sz_out_z; z++)                                                   //loop x_out
                for(int y = 0; y < sz_out_y; y++)                                               //loop y_out
                    for(int x = 0; x < sz_out_x; x++)                                           //loop z_out
                    {
                        v_pos_out = {x, y, z};                                                  //pos out

                        if( x >= offset_x && x < (sz_in_x + offset_x) &&                        //x in range?
                            y >= offset_y && y < (sz_in_y + offset_y) &&                        //y in range?
                            z >= offset_z && z < (sz_in_z + offset_z))                          //z in range?
                        {
                            v_pos_in = {x - offset_x, y - offset_y, z - offset_z};              //pos in
                            pMA_Out->at<ushort>(v_pos_out) = pMA_In->at<ushort>(v_pos_in);      //copy pixel
                        }
                        else
                        {
                            pMA_Out->at<ushort>(v_pos_out) = static_cast<ushort>(border_val);   //set to const value
                        }
                    }
            break;

        case CV_16SC1:
            for(int z = 0; z < sz_out_z; z++)                                                   //loop x_out
                for(int y = 0; y < sz_out_y; y++)                                               //loop y_out
                    for(int x = 0; x < sz_out_x; x++)                                           //loop z_out
                    {
                        v_pos_out = {x, y, z};                                                  //pos out

                        if( x >= offset_x && x < (sz_in_x + offset_x) &&                        //x in range?
                            y >= offset_y && y < (sz_in_y + offset_y) &&                        //y in range?
                            z >= offset_z && z < (sz_in_z + offset_z))                          //z in range?
                        {
                            v_pos_in = {x - offset_x, y - offset_y, z - offset_z};              //pos in
                            pMA_Out->at<short>(v_pos_out) = pMA_In->at<short>(v_pos_in);        //copy pixel
                        }
                        else
                        {
                            pMA_Out->at<short>(v_pos_out) = static_cast<short>(border_val);     //set to const value
                        }
                    }
            break;

        case CV_32SC1:
            for(int z = 0; z < sz_out_z; z++)                                                   //loop x_out
                for(int y = 0; y < sz_out_y; y++)                                               //loop y_out
                    for(int x = 0; x < sz_out_x; x++)                                           //loop z_out
                    {
                        v_pos_out = {x, y, z};                                                  //pos out

                        if( x >= offset_x && x < (sz_in_x + offset_x) &&                        //x in range?
                            y >= offset_y && y < (sz_in_y + offset_y) &&                        //y in range?
                            z >= offset_z && z < (sz_in_z + offset_z))                          //z in range?
                        {
                            v_pos_in = {x - offset_x, y - offset_y, z - offset_z};              //pos in
                            pMA_Out->at<int>(v_pos_out) = pMA_In->at<int>(v_pos_in);            //copy pixel
                        }
                        else
                        {
                            pMA_Out->at<int>(v_pos_out) = static_cast<int>(border_val);         //set to const value
                        }
                    }
            break;

        case CV_32FC1:
            for(int z = 0; z < sz_out_z; z++)                                                   //loop x_out
                for(int y = 0; y < sz_out_y; y++)                                               //loop y_out
                    for(int x = 0; x < sz_out_x; x++)                                           //loop z_out
                    {
                        v_pos_out = {x, y, z};                                                  //pos out

                        if( x >= offset_x && x < (sz_in_x + offset_x) &&                        //x in range?
                            y >= offset_y && y < (sz_in_y + offset_y) &&                        //y in range?
                            z >= offset_z && z < (sz_in_z + offset_z))                          //z in range?
                        {
                            v_pos_in = {x - offset_x, y - offset_y, z - offset_z};              //pos in
                            pMA_Out->at<float>(v_pos_out) = pMA_In->at<float>(v_pos_in);        //copy pixel
                        }
                        else
                        {
                            pMA_Out->at<float>(v_pos_out) = static_cast<float>(border_val);     //set to const value
                        }
                    }
            break;

        case CV_64FC1:
            for(int z = 0; z < sz_out_z; z++)                                                   //loop x_out
                for(int y = 0; y < sz_out_y; y++)                                               //loop y_out
                    for(int x = 0; x < sz_out_x; x++)                                           //loop z_out
                    {
                        v_pos_out = {x, y, z};                                                  //pos out

                        if( x >= offset_x && x < (sz_in_x + offset_x) &&                        //x in range?
                            y >= offset_y && y < (sz_in_y + offset_y) &&                        //y in range?
                            z >= offset_z && z < (sz_in_z + offset_z))                          //z in range?
                        {
                            v_pos_in = {x - offset_x, y - offset_y, z - offset_z};              //pos in
                            pMA_Out->at<double>(v_pos_out) = pMA_In->at<double>(v_pos_in);      //copy pixel
                        }
                        else
                        {
                            pMA_Out->at<double>(v_pos_out) = static_cast<double>(border_val);   //set to const value
                        }
                    }
            break;

        default:
            return ER_type_bad;
            break;
        }

        break;              //==============================================================================================

    case BORDER_REPLICATE:  //==============================================================================================

        switch (pMA_In->type()) {

        case CV_8UC1:
            for(int z = 0; z < sz_out_z; z++)                                                   //loop x_out
                for(int y = 0; y < sz_out_y; y++)                                               //loop y_out
                    for(int x = 0; x < sz_out_x; x++)                                           //loop z_out
                    {
                        v_pos_out   = {x, y, z};                                                //pos out
                        v_pos_in    = {x - offset_x, y - offset_y, z - offset_z};               //pos in default (in img)

                        if(x < offset_x)                v_pos_in[0] = 0;                        //x out low
                        if(y < offset_y)                v_pos_in[1] = 0;                        //y out low
                        if(z < offset_z)                v_pos_in[2] = 0;                        //z out low
                        if(x >= sz_in_x + offset_x)     v_pos_in[0] = sz_in_x - 1;              //x out high
                        if(y >= sz_in_y + offset_y)     v_pos_in[1] = sz_in_y - 1;              //y out high
                        if(z >= sz_in_z + offset_z)     v_pos_in[2] = sz_in_z - 1;              //z out high

                        pMA_Out->at<uchar>(v_pos_out) = pMA_In->at<uchar>(v_pos_in);            //copy pixel
                    }
            break;

        case CV_8SC1:
            for(int z = 0; z < sz_out_z; z++)                                                   //loop x_out
                for(int y = 0; y < sz_out_y; y++)                                               //loop y_out
                    for(int x = 0; x < sz_out_x; x++)                                           //loop z_out
                    {
                        v_pos_out   = {x, y, z};                                                //pos out
                        v_pos_in    = {x - offset_x, y - offset_y, z - offset_z};               //pos in default (in img)

                        if(x < offset_x)                v_pos_in[0] = 0;                        //x out low
                        if(y < offset_y)                v_pos_in[1] = 0;                        //y out low
                        if(z < offset_z)                v_pos_in[2] = 0;                        //z out low
                        if(x >= sz_in_x + offset_x)     v_pos_in[0] = sz_in_x - 1;              //x out high
                        if(y >= sz_in_y + offset_y)     v_pos_in[1] = sz_in_y - 1;              //y out high
                        if(z >= sz_in_z + offset_z)     v_pos_in[2] = sz_in_z - 1;              //z out high

                        pMA_Out->at<char>(v_pos_out) = pMA_In->at<char>(v_pos_in);              //copy pixel
                    }
            break;

        case CV_16UC1:
            for(int z = 0; z < sz_out_z; z++)                                                   //loop x_out
                for(int y = 0; y < sz_out_y; y++)                                               //loop y_out
                    for(int x = 0; x < sz_out_x; x++)                                           //loop z_out
                    {
                        v_pos_out   = {x, y, z};                                                //pos out
                        v_pos_in    = {x - offset_x, y - offset_y, z - offset_z};               //pos in default (in img)

                        if(x < offset_x)                v_pos_in[0] = 0;                        //x out low
                        if(y < offset_y)                v_pos_in[1] = 0;                        //y out low
                        if(z < offset_z)                v_pos_in[2] = 0;                        //z out low
                        if(x >= sz_in_x + offset_x)     v_pos_in[0] = sz_in_x - 1;              //x out high
                        if(y >= sz_in_y + offset_y)     v_pos_in[1] = sz_in_y - 1;              //y out high
                        if(z >= sz_in_z + offset_z)     v_pos_in[2] = sz_in_z - 1;              //z out high

                        pMA_Out->at<ushort>(v_pos_out) = pMA_In->at<ushort>(v_pos_in);          //copy pixel
                    }
            break;

        case CV_16SC1:
            for(int z = 0; z < sz_out_z; z++)                                                   //loop x_out
                for(int y = 0; y < sz_out_y; y++)                                               //loop y_out
                    for(int x = 0; x < sz_out_x; x++)                                           //loop z_out
                    {
                        v_pos_out   = {x, y, z};                                                //pos out
                        v_pos_in    = {x - offset_x, y - offset_y, z - offset_z};               //pos in default (in img)

                        if(x < offset_x)                v_pos_in[0] = 0;                        //x out low
                        if(y < offset_y)                v_pos_in[1] = 0;                        //y out low
                        if(z < offset_z)                v_pos_in[2] = 0;                        //z out low
                        if(x >= sz_in_x + offset_x)     v_pos_in[0] = sz_in_x - 1;              //x out high
                        if(y >= sz_in_y + offset_y)     v_pos_in[1] = sz_in_y - 1;              //y out high
                        if(z >= sz_in_z + offset_z)     v_pos_in[2] = sz_in_z - 1;              //z out high

                        pMA_Out->at<short>(v_pos_out) = pMA_In->at<short>(v_pos_in);            //copy pixel
                    }
            break;

        case CV_32SC1:
            for(int z = 0; z < sz_out_z; z++)                                                   //loop x_out
                for(int y = 0; y < sz_out_y; y++)                                               //loop y_out
                    for(int x = 0; x < sz_out_x; x++)                                           //loop z_out
                    {
                        v_pos_out   = {x, y, z};                                                //pos out
                        v_pos_in    = {x - offset_x, y - offset_y, z - offset_z};               //pos in default (in img)

                        if(x < offset_x)                v_pos_in[0] = 0;                        //x out low
                        if(y < offset_y)                v_pos_in[1] = 0;                        //y out low
                        if(z < offset_z)                v_pos_in[2] = 0;                        //z out low
                        if(x >= sz_in_x + offset_x)     v_pos_in[0] = sz_in_x - 1;              //x out high
                        if(y >= sz_in_y + offset_y)     v_pos_in[1] = sz_in_y - 1;              //y out high
                        if(z >= sz_in_z + offset_z)     v_pos_in[2] = sz_in_z - 1;              //z out high

                        pMA_Out->at<int>(v_pos_out) = pMA_In->at<int>(v_pos_in);                //copy pixel
                    }
            break;

        case CV_32FC1:
            for(int z = 0; z < sz_out_z; z++)                                                   //loop x_out
                for(int y = 0; y < sz_out_y; y++)                                               //loop y_out
                    for(int x = 0; x < sz_out_x; x++)                                           //loop z_out
                    {
                        v_pos_out   = {x, y, z};                                                //pos out
                        v_pos_in    = {x - offset_x, y - offset_y, z - offset_z};               //pos in default (in img)

                        if(x < offset_x)                v_pos_in[0] = 0;                        //x out low
                        if(y < offset_y)                v_pos_in[1] = 0;                        //y out low
                        if(z < offset_z)                v_pos_in[2] = 0;                        //z out low
                        if(x >= sz_in_x + offset_x)     v_pos_in[0] = sz_in_x - 1;              //x out high
                        if(y >= sz_in_y + offset_y)     v_pos_in[1] = sz_in_y - 1;              //y out high
                        if(z >= sz_in_z + offset_z)     v_pos_in[2] = sz_in_z - 1;              //z out high

                        pMA_Out->at<float>(v_pos_out) = pMA_In->at<float>(v_pos_in);            //copy pixel
                    }
            break;

        case CV_64FC1:
            for(int z = 0; z < sz_out_z; z++)                                                   //loop x_out
                for(int y = 0; y < sz_out_y; y++)                                               //loop y_out
                    for(int x = 0; x < sz_out_x; x++)                                           //loop z_out
                    {
                        v_pos_out   = {x, y, z};                                                //pos out
                        v_pos_in    = {x - offset_x, y - offset_y, z - offset_z};               //pos in default (in img)

                        if(x < offset_x)                v_pos_in[0] = 0;                        //x out low
                        if(y < offset_y)                v_pos_in[1] = 0;                        //y out low
                        if(z < offset_z)                v_pos_in[2] = 0;                        //z out low
                        if(x >= sz_in_x + offset_x)     v_pos_in[0] = sz_in_x - 1;              //x out high
                        if(y >= sz_in_y + offset_y)     v_pos_in[1] = sz_in_y - 1;              //y out high
                        if(z >= sz_in_z + offset_z)     v_pos_in[2] = sz_in_z - 1;              //z out high

                        pMA_Out->at<double>(v_pos_out) = pMA_In->at<double>(v_pos_in);          //copy pixel
                    }
            break;

        default:
            return ER_type_bad;
            break;
        }

        break;              //==============================================================================================

    default:
        return ER_parameter_bad;
        break;
    }

    //sucess
    return ER_okay;
}

int D_Img_Proc_3D::Filter_Function(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<double (double, double)> F1_CenterImage, function<double (double, double)> F2_f1mask, function<double (vector<double>)> F3_Combine, function<double (double, double)> F4_f3center, int border_type, bool DoNonZeroMaskOnly)
{
    //qDebug() << "Filter_Function" << "start";
    if(pMA_In->empty())                             return ER_okay;
    if(pMA_In->channels() != pMA_Mask->channels())  return ER_channel_missmatch;
    if(pMA_In->dims != 3)                           return ER_dim_3D_only;
    if(pMA_Mask->dims != 3)                         return ER_dim_3D_only;

    int ER;

    //convert to double
    //in
    //qDebug() << "Filter_Function" << "convert to double in";
    Mat MA_tmp_double_in;
    ER = Convert_Double(
                &MA_tmp_double_in,
                pMA_In);
    if(ER != ER_okay)   return ER;

    //mask
    //qDebug() << "Filter_Function" << "convert to double mask";
    Mat MA_tmp_double_mask;
    ER = Convert_Double(
                &MA_tmp_double_mask,
                pMA_Mask);
    if(ER != ER_okay)   return ER;

    switch (pMA_In->channels()) {

    case 1:
    {
        //qDebug() << "Filter_Function" << "ch 1";
        int ER = Filter_Function_1C(
                    pMA_Out,
                    &MA_tmp_double_in,
                    &MA_tmp_double_mask,
                    F1_CenterImage,
                    F2_f1mask,
                    F3_Combine,
                    F4_f3center,
                    border_type,
                    cv::getNumberOfCPUs(),
                    DoNonZeroMaskOnly);
        if(ER != ER_okay)   return ER;
    }
        break;

    case 2:
    {
        //qDebug() << "Filter_Function" << "ch 2";
        static const int ch = 2;

        //in
        Mat MA_tmp_in[ch];
        split(
                    MA_tmp_double_in,
                    MA_tmp_in);

        //mask
        Mat MA_tmp_mask[ch];
        split(
                    MA_tmp_double_mask,
                    MA_tmp_mask);

        //out
        Mat MA_tmp_filtered[ch];
        for(int c = 0; c < ch; c++)
        {
            int ER = Filter_Function_1C(
                        &(MA_tmp_filtered[c]),
                        &(MA_tmp_in[c]),
                        &(MA_tmp_mask[c]),
                        F1_CenterImage,
                        F2_f1mask,
                        F3_Combine,
                        F4_f3center,
                        border_type,
                        cv::getNumberOfCPUs(),
                        DoNonZeroMaskOnly);
            if(ER != ER_okay)   return ER;
        }

        //merge
        merge(
                    MA_tmp_filtered,
                    pMA_In->channels(),
                    *pMA_Out);

        //release
        for(int c = 0; c < ch; c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_filtered[c].release();
        }
    }
        break;

    case 3:
    {
        //qDebug() << "Filter_Function" << "ch 3";
        static const int ch = 3;

        //in
        Mat MA_tmp_in[ch];
        split(
                    MA_tmp_double_in,
                    MA_tmp_in);

        //mask
        Mat MA_tmp_mask[ch];
        split(
                    MA_tmp_double_mask,
                    MA_tmp_mask);

        //out
        Mat MA_tmp_filtered[ch];
        for(int c = 0; c < ch; c++)
        {
            int ER = Filter_Function_1C(
                        &(MA_tmp_filtered[c]),
                        &(MA_tmp_in[c]),
                        &(MA_tmp_mask[c]),
                        F1_CenterImage,
                        F2_f1mask,
                        F3_Combine,
                        F4_f3center,
                        border_type,
                        cv::getNumberOfCPUs(),
                        DoNonZeroMaskOnly);
            if(ER != ER_okay)   return ER;
        }

        //merge
        merge(
                    MA_tmp_filtered,
                    pMA_In->channels(),
                    *pMA_Out);

        //release
        for(int c = 0; c < ch; c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_filtered[c].release();
        }
    }
        break;

    case 4:
    {
        //qDebug() << "Filter_Function" << "ch 4";
        static const int ch = 4;

        //in
        Mat MA_tmp_in[ch];
        split(
                    MA_tmp_double_in,
                    MA_tmp_in);

        //mask
        Mat MA_tmp_mask[ch];
        split(
                    MA_tmp_double_mask,
                    MA_tmp_mask);

        //out
        Mat MA_tmp_filtered[ch];
        for(int c = 0; c < ch; c++)
        {
            int ER = Filter_Function_1C(
                        &(MA_tmp_filtered[c]),
                        &(MA_tmp_in[c]),
                        &(MA_tmp_mask[c]),
                        F1_CenterImage,
                        F2_f1mask,
                        F3_Combine,
                        F4_f3center,
                        border_type,
                        cv::getNumberOfCPUs(),
                        DoNonZeroMaskOnly);
            if(ER != ER_okay)   return ER;
        }

        //merge
        merge(
                    MA_tmp_filtered,
                    pMA_In->channels(),
                    *pMA_Out);

        //release
        for(int c = 0; c < ch; c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_filtered[c].release();
        }
    }
        break;

    default:
        break;
    }

    //qDebug() << "Filter_Function" << "end";
    MA_tmp_double_in.release();
    MA_tmp_double_mask.release();
    return ER_okay;
}

int D_Img_Proc_3D::Filter_Function_1C(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<double (double, double)> F1_CenterImage, function<double (double, double)> F2_f1mask, function<double (vector<double>)> F3_Combine, function<double (double, double)> F4_f3center, int border_type, int thread_number, bool DoNonZeroMaskOnly)
{
    //qDebug() << "Filter_Function_1C" << "start";
    //======================================================================    Error Checks

    if(pMA_In->empty())                         return ER_empty;
    if(pMA_In->dims != 3)                       return ER_dim_3D_only;
    if(pMA_In->channels() != 1)                 return ER_channel_bad;
    if(pMA_In->depth() != CV_64F)               return ER_bitdepth_bad;
    if(pMA_Mask->dims != 3)                     return ER_dim_3D_only;
    if(pMA_Mask->channels() != 1)               return ER_channel_bad;
    if(pMA_Mask->depth() != CV_64F)             return ER_bitdepth_bad;
    if(pMA_Mask->size[0] % 2 != 1)              return ER_size_bad;
    if(pMA_Mask->size[1] % 2 != 1)              return ER_size_bad;
    if(pMA_Mask->size[2] % 2 != 1)              return ER_size_bad;
    int ER = ER_okay;

    //======================================================================    Dimensions

    //image dimension
    int sz_in_x     = pMA_In->size[0];              //image width
    int sz_in_y     = pMA_In->size[1];              //image heigth
    int sz_in_z     = pMA_In->size[2];              //image planes
    int sz_in[]     = {sz_in_x, sz_in_y, sz_in_z};

    //mask dimension
    int sz_mask_x   = pMA_Mask->size[0];            //mask width
    int sz_mask_y   = pMA_Mask->size[1];            //mask height
    int sz_mask_z   = pMA_Mask->size[2];            //mask height

    //max shifts
    int shift_x     = static_cast<int>(sz_mask_x / 2); //mask  shift x (center to border, rounded down)
    int shift_y     = static_cast<int>(sz_mask_y / 2); //mask  shift y (center to border, rounded down)
    int shift_z     = static_cast<int>(sz_mask_z / 2); //mask  shift z (center to border, rounded down)

    //======================================================================    pad & init

    //init out
    *pMA_Out        = Mat::zeros(3, sz_in, CV_64FC1);

    //padding in
    Mat MA_tmp_in_padded;
    ER = Pad_Border(
                &MA_tmp_in_padded,
                pMA_In,
                shift_x,
                shift_y,
                shift_z,
                border_type);
    if(ER != ER_okay)
    {
        //qDebug() << "Error in Pad_Border 3D";
        MA_tmp_in_padded.release();
        return ER;
    }

    //======================================================================    thread & synch

    //x and y range (threads only in z)
    int y_start     = 0         +   shift_y;
    int y_end       = sz_in_y   +   shift_y;
    int x_start     = 0         +   shift_x;
    int x_end       = sz_in_x   +   shift_x;
    //qDebug() << "start threads in img dim x/y/z:" << sz_in_x << sz_in_y << sz_in_z;
    //qDebug() << "start threads each x-range from" << x_start << "to" << x_end << "y-range from" << y_start << "to" << y_end;

    //threads
    if(thread_number > sz_in_z)
        thread_number = sz_in_z;        //make sure each thread has something to do
    vector<thread>     v_threads;
    vector<int>        v_ER;
    v_threads.resize(thread_number);
    v_ER.resize(thread_number);

    for(int t = 0; t < thread_number; t++)
    {
        //qDebug() << "thread" << t;
        //range for thread
        int z_start = ((t    ) / static_cast<double>(thread_number)) * sz_in_z + shift_z;
        int z_end   = ((t + 1) / static_cast<double>(thread_number)) * sz_in_z + shift_z;


        //start thread
        //qDebug() << "start thread" << t << "of" << thread_number << "- z-range from" << z_start << "to" << z_end;
        v_threads[t] = thread(
                    Filter_Function_1C_Thread,
                    pMA_Out,
                    &MA_tmp_in_padded,
                    pMA_Mask,
                    F1_CenterImage,
                    F2_f1mask,
                    F3_Combine,
                    F4_f3center,
                    z_start,
                    z_end,
                    y_start,
                    y_end,
                    x_start,
                    x_end,
                    DoNonZeroMaskOnly);
    }

    for(int t = 0; t < thread_number; t++)
    {
        v_threads[t].join();
        //qDebug() << "join thread" << t << "of" << thread_number;
    }

    MA_tmp_in_padded.release();

    //qDebug() << "Filter_Function_1C" << "end";
    return ER;
}

int D_Img_Proc_3D::Filter_Function_1C_Thread(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<double (double, double)> F1_CenterImage, function<double (double, double)> F2_f1mask, function<double (vector<double>)> F3_Combine, function<double (double, double)> F4_f3center, int z_start, int z_end, int y_start, int y_end, int x_start, int x_end, bool DoNonZeroMaskOnly)
{
    //qDebug() << "Filter_Function_1C_Thread" << "start";
    //======================================================================    Error Checks

    if(pMA_In->empty())                                     return ER_empty;
    if(pMA_In->channels() != 1)                             return ER_channel_bad;
    if(pMA_In->depth() != CV_64F)                           return ER_bitdepth_bad;
    if(pMA_In->dims != 3)                                   return ER_dim_3D_only;
    if(pMA_Mask->dims != 3)                                 return ER_dim_3D_only;

    if(pMA_Mask->channels() != 1)                           return ER_channel_bad;
    if(pMA_Mask->depth() != CV_64F)                         return ER_bitdepth_bad;

    if(pMA_Mask->size[0] >= pMA_In->size[0])                return ER_size_missmatch;
    if(x_start < 0 || x_start >= pMA_In->size[0])           return ER_size_missmatch;
    if(x_end < 0 || x_end >= pMA_In->size[0])               return ER_size_missmatch;
    if(x_start >= x_end)                                    return ER_parameter_missmatch;
    if(pMA_Mask->size[0] % 2 != 1)                          return ER_size_bad;

    if(pMA_Mask->size[1] >= pMA_In->size[1])                return ER_size_missmatch;
    if(y_start < 0 || y_start >= pMA_In->size[1])           return ER_size_missmatch;
    if(y_end < 0 || y_end >= pMA_In->size[1])               return ER_size_missmatch;
    if(y_start >= y_end)                                    return ER_parameter_missmatch;
    if(pMA_Mask->size[1] % 2 != 1)                          return ER_size_bad;

    if(pMA_Mask->size[2] >= pMA_In->size[2])                return ER_size_missmatch;
    if(z_start < 0 || z_start >= pMA_In->size[2])           return ER_size_missmatch;
    if(z_end < 0 || z_end >= pMA_In->size[2])               return ER_size_missmatch;
    if(z_start >= z_end)                                    return ER_parameter_missmatch;
    if(pMA_Mask->size[2] % 2 != 1)                          return ER_size_bad;

    //======================================================================    Dimensions & Positions

    //mask dimension
    int sz_mask_x = pMA_Mask->size[0];                  //mask width
    int sz_mask_y = pMA_Mask->size[1];                  //mask height
    int sz_mask_z = pMA_Mask->size[2];                  //mask planes
    int sz_mask_v = sz_mask_x * sz_mask_y * sz_mask_z;  //mask volume

    //max shifts
    int shift_x = static_cast<int>(sz_mask_x / 2);      //mask  shift x (center to border, rounded down)
    int shift_y = static_cast<int>(sz_mask_y / 2);      //mask  shift y (center to border, rounded down)
    int shift_z = static_cast<int>(sz_mask_z / 2);      //mask  shift z (center to border, rounded down)

    //looping & convoluting
    int Xi = 0;                                         //image         position x
    int Yi = 0;                                         //image         position y
    int Zi = 0;                                         //image         position z
    int Xn = 0;                                         //neighborhood  position x
    int Yn = 0;                                         //neighborhood  position y
    int Zn = 0;                                         //neighborhood  position z
    int Xm = 0;                                         //mask          position x
    int Ym = 0;                                         //mask          position y
    int Zm = 0;                                         //mask          position z

    Vec<int, 3> pos_i = {0, 0, 0};                      //image in
    Vec<int, 3> pos_m = {0, 0, 0};                      //mask
    Vec<int, 3> pos_n = {0, 0, 0};                      //neighborhood
    Vec<int, 3> pos_o = {0, 0, 0};                      //image out

    //======================================================================  Init Results

    //pMA_Out is already initilazied by Filter_Function_1C (careing for therads and init)

    //results
    vector<double> v_results;

    //======================================================================  Loop Image


    for(Zi = z_start; Zi < z_end; Zi++)                                     //loop part of IMAGE: Z
    {
        for(Yi = y_start; Yi < y_end; Yi++)                                 //loop part of IMAGE: Y
        {
            for(Xi = x_start; Xi < x_end; Xi++)                             //loop part of IMAGE: X
            {
                //---------------------------------------------------------  proc per pixel  ---------------------------------------------

                pos_i   = {Xi, Yi, Zi};                                     //pos in image in

                                                                            //loop MASK: Z
                for(Zn = Zi - shift_z, Zm = 0, v_results.clear();           //start:        mask@0 & neighboorhod@mask@0, reset pos in results vector
                    Zn <= (Zi + shift_z);                                   //check:        neighboorhood@mask
                    Zn++, Zm++)                                             //end:          next pos in mask & neighborhood
                {
                                                                            //loop MASK: Y
                    for(Yn = Yi - shift_y, Ym = 0;                          //start:        mask@0 & neighboorhod@mask@0
                        Yn <= (Yi + shift_y);                               //check:        neighboorhood@mask
                        Yn++, Ym++)                                         //end:          next pos in mask & neighborhood
                    {
                                                                            //loop MAK: X
                        for(Xn = Xi - shift_x, Xm = 0;                      //start:        mask@0 & neighboorhod@mask@0
                            Xn <= (Xi + shift_x);                           //check:        neighboorhood@mask
                            Xn++, Xm++)                                     //end:          next pos in mask & neighborhood & results vector
                        {
                            pos_m = {Xm, Ym, Zm};                           //pos in mask
                            pos_n = {Xn, Yn, Zn};                           //pos in neighborhood congruent to mask

                            //calculate position value
                            double val_mask = pMA_Mask->at<double>(pos_m);
                            if(!DoNonZeroMaskOnly || val_mask != 0)
                            {
                                v_results.push_back(
                                        F2_f1mask(
                                            F1_CenterImage(
                                                pMA_In->at<double>(pos_i),
                                                pMA_In->at<double>(pos_n)),
                                            val_mask));
                            }
                        }
                    }
                }

                //pos out
                pos_o = {Xi - shift_x, Yi - shift_y, Zi - shift_z};         //pos to write in out coordinates (shifted by border width/height to ignore padded border of input)

                pMA_Out->at<double>(pos_o) =                                //write result for current pixel
                        F4_f3center(                                        //F4 of(
                            F3_Combine(v_results),                          //F3 of results of F2 of F1
                            pMA_In->at<double>(pos_i));                     //and In)

                //---------------------------------------------------------  proc per pixel  ---------------------------------------------
            }
        }
    }

    //======================================================================  End
    //qDebug() << "Filter_Function_1C_Thread" << "end";
    return ER_okay;
}

int D_Img_Proc_3D::Filter_Function_8bit(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<uchar (double, double)> F1_CenterImage, function<uchar (double, double)> F2_f1mask, function<uchar (vector<double>)> F3_Combine, function<uchar (double, double)> F4_f3center, int border_type, bool DoNonZeroMaskOnly)
{
    //qDebug() << "Filter_Function_8bit" << "start";
    if(pMA_In->empty())                             return ER_okay;
    if(pMA_In->channels() != pMA_Mask->channels())  return ER_channel_missmatch;
    if(pMA_In->depth() != CV_8UC1)                  return ER_bitdepth_bad;
    if(pMA_Mask->depth() != CV_8UC1)                return ER_bitdepth_bad;
    if(pMA_In->dims != 3)                           return ER_dim_3D_only;
    if(pMA_Mask->dims != 3)                         return ER_dim_3D_only;

    switch (pMA_In->channels()) {

    case 1:
    {
        //qDebug() << "Filter_Function_8bit" << "ch 1";
        int ER = Filter_Function_8bit_1C(
                    pMA_Out,
                    pMA_In,
                    pMA_Mask,
                    F1_CenterImage,
                    F2_f1mask,
                    F3_Combine,
                    F4_f3center,
                    border_type,
                    cv::getNumberOfCPUs(),
                    DoNonZeroMaskOnly);
        if(ER != ER_okay)   return ER;
    }
        break;

    case 2:
    {
        //qDebug() << "Filter_Function_8bit" << "ch 2";
        static const int ch = 2;

        //in
        Mat MA_tmp_in[ch];
        split(
                    *pMA_In,
                    MA_tmp_in);

        //mask
        Mat MA_tmp_mask[ch];
        split(
                    *pMA_Mask,
                    MA_tmp_mask);

        //out
        Mat MA_tmp_filtered[ch];
        for(int c = 0; c < ch; c++)
        {
            int ER = Filter_Function_8bit_1C(
                        &(MA_tmp_filtered[c]),
                        &(MA_tmp_in[c]),
                        &(MA_tmp_mask[c]),
                        F1_CenterImage,
                        F2_f1mask,
                        F3_Combine,
                        F4_f3center,
                        border_type,
                        cv::getNumberOfCPUs(),
                        DoNonZeroMaskOnly);
            if(ER != ER_okay)   return ER;
        }

        //merge
        merge(
                    MA_tmp_filtered,
                    pMA_In->channels(),
                    *pMA_Out);

        //release
        for(int c = 0; c < ch; c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_filtered[c].release();
        }
    }
        break;

    case 3:
    {
        //qDebug() << "Filter_Function_8bit" << "ch 3";
        static const int ch = 3;

        //in
        Mat MA_tmp_in[ch];
        split(
                    *pMA_In,
                    MA_tmp_in);

        //mask
        Mat MA_tmp_mask[ch];
        split(
                    *pMA_Mask,
                    MA_tmp_mask);

        //out
        Mat MA_tmp_filtered[ch];
        for(int c = 0; c < ch; c++)
        {
            int ER = Filter_Function_8bit_1C(
                        &(MA_tmp_filtered[c]),
                        &(MA_tmp_in[c]),
                        &(MA_tmp_mask[c]),
                        F1_CenterImage,
                        F2_f1mask,
                        F3_Combine,
                        F4_f3center,
                        border_type,
                        cv::getNumberOfCPUs(),
                        DoNonZeroMaskOnly);
            if(ER != ER_okay)   return ER;
        }

        //merge
        merge(
                    MA_tmp_filtered,
                    pMA_In->channels(),
                    *pMA_Out);

        //release
        for(int c = 0; c < ch; c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_filtered[c].release();
        }
    }
        break;

    case 4:
    {
        //qDebug() << "Filter_Function_8bit" << "ch 4";
        static const int ch = 4;

        //in
        Mat MA_tmp_in[ch];
        split(
                    *pMA_In,
                    MA_tmp_in);

        //mask
        Mat MA_tmp_mask[ch];
        split(
                    *pMA_Mask,
                    MA_tmp_mask);

        //out
        Mat MA_tmp_filtered[ch];
        for(int c = 0; c < ch; c++)
        {
            int ER = Filter_Function_8bit_1C(
                        &(MA_tmp_filtered[c]),
                        &(MA_tmp_in[c]),
                        &(MA_tmp_mask[c]),
                        F1_CenterImage,
                        F2_f1mask,
                        F3_Combine,
                        F4_f3center,
                        border_type,
                        cv::getNumberOfCPUs(),
                        DoNonZeroMaskOnly);
            if(ER != ER_okay)   return ER;
        }

        //merge
        merge(
                    MA_tmp_filtered,
                    pMA_In->channels(),
                    *pMA_Out);

        //release
        for(int c = 0; c < ch; c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_filtered[c].release();
        }
    }
        break;

    default:
        break;
    }

    //qDebug() << "Filter_Function_8bit" << "end";
    return ER_okay;
}

int D_Img_Proc_3D::Filter_Function_8bit_1C(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<uchar (double, double)> F1_CenterImage, function<uchar (double, double)> F2_f1mask, function<uchar (vector<double>)> F3_Combine, function<uchar (double, double)> F4_f3center, int border_type, int thread_number, bool DoNonZeroMaskOnly)
{
    //qDebug() << "Filter_Function_8bit_1C" << "start";
    //======================================================================    Error Checks

    if(pMA_In->empty())                         return ER_empty;
    if(pMA_In->dims != 3)                       return ER_dim_3D_only;
    if(pMA_In->channels() != 1)                 return ER_channel_bad;
    if(pMA_In->depth() != CV_8U)                return ER_bitdepth_bad;
    if(pMA_Mask->dims != 3)                     return ER_dim_3D_only;
    if(pMA_Mask->channels() != 1)               return ER_channel_bad;
    if(pMA_Mask->depth() != CV_8U)              return ER_bitdepth_bad;
    if(pMA_Mask->size[0] % 2 != 1)              return ER_size_bad;
    if(pMA_Mask->size[1] % 2 != 1)              return ER_size_bad;
    if(pMA_Mask->size[2] % 2 != 1)              return ER_size_bad;
    int ER = ER_okay;


    //======================================================================    Dimensions

    //image dimension
    int sz_in_x     = pMA_In->size[0];              //image width
    int sz_in_y     = pMA_In->size[1];              //image heigth
    int sz_in_z     = pMA_In->size[2];              //image planes
    int sz_in[]     = {sz_in_x, sz_in_y, sz_in_z};

    //mask dimension
    int sz_mask_x   = pMA_Mask->size[0];            //mask width
    int sz_mask_y   = pMA_Mask->size[1];            //mask height
    int sz_mask_z   = pMA_Mask->size[2];            //mask planes

    //max shifts
    int shift_x     = static_cast<int>(sz_mask_x / 2); //mask  shift x (center to border, rounded down)
    int shift_y     = static_cast<int>(sz_mask_y / 2); //mask  shift y (center to border, rounded down)
    int shift_z     = static_cast<int>(sz_mask_z / 2); //mask  shift z (center to border, rounded down)


    //======================================================================    pad & init

    //init out
    *pMA_Out        = Mat::zeros(3, sz_in, CV_8UC1);

    //padding in
    Mat MA_tmp_in_padded;
    ER = Pad_Border(
                &MA_tmp_in_padded,
                pMA_In,
                shift_x,
                shift_y,
                shift_z,
                border_type);
    if(ER != ER_okay)
    {
        //qDebug() << "Error in Pad_Border 3D";
        MA_tmp_in_padded.release();
        return ER;
    }


    //======================================================================    thread & synch

    //x and y range (threads only in z)
    int y_start     = 0         +   shift_y;
    int y_end       = sz_in_y   +   shift_y;
    int x_start     = 0         +   shift_x;
    int x_end       = sz_in_x   +   shift_x;
    qDebug() << "start threads in img dim x/y/z:" << sz_in_x << sz_in_y << sz_in_z;
    qDebug() << "start threads each x-range from" << x_start << "to" << x_end << "y-range from" << y_start << "to" << y_end;

    //threads
    if(thread_number > sz_in_z)
        thread_number = sz_in_z;        //make sure each thread has something to do
    vector<thread>     v_threads;
    vector<int>        v_ER;
    v_threads.resize(thread_number);
    v_ER.resize(thread_number);

    for(int t = 0; t < thread_number; t++)
    {
        //qDebug() << "start thread" << t << "of" << thread_number;
        //range for thread
        int z_start = ((t    ) / static_cast<double>(thread_number)) * sz_in_z + shift_z;
        int z_end   = ((t + 1) / static_cast<double>(thread_number)) * sz_in_z + shift_z;


        //start thread
        qDebug() << "start thread" << t << "of" << thread_number << "- z-range from" << z_start << "to" << z_end;
        v_threads[t] = thread(
                    Filter_Function_8bit_1C_Thread,
                    pMA_Out,
                    &MA_tmp_in_padded,
                    pMA_Mask,
                    F1_CenterImage,
                    F2_f1mask,
                    F3_Combine,
                    F4_f3center,
                    z_start,
                    z_end,
                    y_start,
                    y_end,
                    x_start,
                    x_end,
                    DoNonZeroMaskOnly);
    }

    for(int t = 0; t < thread_number; t++)
    {
        v_threads[t].join();
        qDebug() << "join thread" << t << "of" << thread_number;
    }

    MA_tmp_in_padded.release();

    qDebug() << "Filter_Function_8bit_1C" << "end";
    return ER;
}

int D_Img_Proc_3D::Filter_Function_8bit_1C_Thread(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<uchar (double, double)> F1_CenterImage, function<uchar (double, double)> F2_f1mask, function<uchar (vector<double>)> F3_Combine, function<uchar (double, double)> F4_f3center, int z_start, int z_end, int y_start, int y_end, int x_start, int x_end, bool DoNonZeroMaskOnly)
{
    qDebug() << "Filter_Function_8bit_1C_Thread" << "start" << D_Img_Proc::Type_of_Mat(pMA_In) << D_Img_Proc::Type_of_Mat(pMA_Mask) << "Z-range:" << z_start << "to" << z_end;
    //======================================================================    Error Checks

    if(pMA_In->empty())                                     return ER_empty;
    if(pMA_In->channels() != 1)                             return ER_channel_bad;
    if(pMA_In->depth() != CV_8U)                            return ER_bitdepth_bad;
    if(pMA_In->dims != 3)                                   return ER_dim_3D_only;
    if(pMA_Mask->dims != 3)                                 return ER_dim_3D_only;

    if(pMA_Mask->channels() != 1)                           return ER_channel_bad;
    if(pMA_Mask->depth() != CV_8U)                          return ER_bitdepth_bad;

    if(pMA_Mask->size[0] >= pMA_In->size[0])                return ER_size_missmatch;
    if(x_start < 0 || x_start >= pMA_In->size[0])           return ER_size_missmatch;
    if(x_end < 0 || x_end >= pMA_In->size[0])               return ER_size_missmatch;
    if(x_start >= x_end)                                    return ER_parameter_missmatch;
    if(pMA_Mask->size[0] % 2 != 1)                          return ER_size_bad;

    if(pMA_Mask->size[1] >= pMA_In->size[1])                return ER_size_missmatch;
    if(y_start < 0 || y_start >= pMA_In->size[1])           return ER_size_missmatch;
    if(y_end < 0 || y_end >= pMA_In->size[1])               return ER_size_missmatch;
    if(y_start >= y_end)                                    return ER_parameter_missmatch;
    if(pMA_Mask->size[1] % 2 != 1)                          return ER_size_bad;

    if(pMA_Mask->size[2] >= pMA_In->size[2])                return ER_size_missmatch;
    if(z_start < 0 || z_start >= pMA_In->size[2])           return ER_size_missmatch;
    if(z_end < 0 || z_end >= pMA_In->size[2])               return ER_size_missmatch;
    if(z_start >= z_end)                                    return ER_parameter_missmatch;
    if(pMA_Mask->size[2] % 2 != 1)                          return ER_size_bad;

    //======================================================================    Dimensions & Positions

    //mask dimension
    int sz_mask_x = pMA_Mask->size[0];                  //mask width
    int sz_mask_y = pMA_Mask->size[1];                  //mask height
    int sz_mask_z = pMA_Mask->size[2];                  //mask planes
    int sz_mask_v = sz_mask_x * sz_mask_y * sz_mask_z;  //mask volume

    //max shifts
    int shift_x = static_cast<int>(sz_mask_x / 2);      //mask  shift x (center to border, rounded down)
    int shift_y = static_cast<int>(sz_mask_y / 2);      //mask  shift y (center to border, rounded down)
    int shift_z = static_cast<int>(sz_mask_z / 2);      //mask  shift z (center to border, rounded down)

    //looping & convoluting
    int Xi = 0;                                         //image         position x
    int Yi = 0;                                         //image         position y
    int Zi = 0;                                         //image         position z
    int Xn = 0;                                         //neighborhood  position x
    int Yn = 0;                                         //neighborhood  position y
    int Zn = 0;                                         //neighborhood  position z
    int Xm = 0;                                         //mask          position x
    int Ym = 0;                                         //mask          position y
    int Zm = 0;                                         //mask          position z

    Vec<int, 3> pos_i = {0, 0, 0};                      //image in
    Vec<int, 3> pos_m = {0, 0, 0};                      //mask
    Vec<int, 3> pos_n = {0, 0, 0};                      //neighborhood
    Vec<int, 3> pos_o = {0, 0, 0};                      //image out

    //======================================================================  Init Results

    //pMA_Out is already initilazied by Filter_Function_8bit_1C (careing for therads and init)

    //results
    vector<double> v_results;

    //======================================================================  Loop Image


    for(Zi = z_start; Zi < z_end; Zi++)                                     //loop part of IMAGE: Z
    {
        for(Yi = y_start; Yi < y_end; Yi++)                                 //loop part of IMAGE: Y
        {
            for(Xi = x_start; Xi < x_end; Xi++)                             //loop part of IMAGE: X
            {
                //---------------------------------------------------------  proc per pixel  ---------------------------------------------
                //qDebug() << "Filter_Function_8bit_1C_Thread" << "pixel" << "X/Y/Z" << Xi << Yi << Zi;

                pos_i   = {Xi, Yi, Zi};                                     //pos in image in

                                                                            //loop MASK: Z
                for(Zn = Zi - shift_z, Zm = 0, v_results.clear();           //start:        mask@0 & neighboorhod@mask@0, reset pos in results vector
                    Zn <= (Zi + shift_z);                                   //check:        neighboorhood@mask
                    Zn++, Zm++)                                             //end:          next pos in mask & neighborhood
                {
                                                                            //loop MASK: Y
                    for(Yn = Yi - shift_y, Ym = 0;                          //start:        mask@0 & neighboorhod@mask@0
                        Yn <= (Yi + shift_y);                               //check:        neighboorhood@mask
                        Yn++, Ym++)                                         //end:          next pos in mask & neighborhood
                    {
                                                                            //loop MAK: X
                        for(Xn = Xi - shift_x, Xm = 0;                      //start:        mask@0 & neighboorhod@mask@0
                            Xn <= (Xi + shift_x);                           //check:        neighboorhood@mask
                            Xn++, Xm++)                                     //end:          next pos in mask & neighborhood & results vector
                        {
                            pos_m = {Xm, Ym, Zm};                           //pos in mask
                            pos_n = {Xn, Yn, Zn};                           //pos in neighborhood congruent to mask

                            //calculate position value
                            double val_mask = pMA_Mask->at<double>(pos_m);
                            if(!DoNonZeroMaskOnly || val_mask != 0.0)
                            {
                                v_results.push_back(
                                        F2_f1mask(
                                            F1_CenterImage(
                                                pMA_In->at<double>(pos_i),
                                                pMA_In->at<double>(pos_n)),
                                            val_mask));
                            }
                        }
                    }
                }

                //pos out
                pos_o = {Xi - shift_x, Yi - shift_y, Zi - shift_z};         //pos to write in out coordinates (shifted by border width/height to ignore padded border of input)

                pMA_Out->at<uchar>(pos_o) =                                 //write result for current pixel
                        F4_f3center(                                        //F4 of(
                            F3_Combine(v_results),                          //F3 of results of F2 of F1
                            pMA_In->at<uchar>(pos_i));                      //and In)

                //---------------------------------------------------------  proc per pixel  ---------------------------------------------
            }
        }
    }

    //======================================================================  End
    //qDebug() << "Filter_Function_8bit_1C_Thread" << "end";
    return ER_okay;
}

int D_Img_Proc_3D::Filter_Median(Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y, int size_z)
{
    //correct sizes to be consistent with 2D median from openCV
    size_x = size_x * 2 + 1;
    size_y = size_y * 2 + 1;
    size_z = size_z * 2 + 1;

    qDebug() << "D_Img_Proc_3D::Filter_Median" << "sizes x/y/z" << size_x << size_y << size_z;

    //Errors
    if(pMA_In->empty())                         return ER_empty;
    if((size_x < 1) || (size_x % 2 != 1))       return ER_parameter_bad;
    if((size_y < 1) || (size_y % 2 != 1))       return ER_parameter_bad;
    if((size_z < 1) || (size_z % 2 != 1))       return ER_parameter_bad;
    if(size_x > pMA_In->size[0])                return ER_size_missmatch;
    if(size_y > pMA_In->size[1])                return ER_size_missmatch;
    if(size_z > pMA_In->size[2])                return ER_size_missmatch;

    //mask
    int sz[] = {size_x, size_y, size_z};
    Mat MA_Mask_tmp;
    if(pMA_In->depth() == CV_8U)
        switch (pMA_In->channels()) {
        case 1:     MA_Mask_tmp = Mat(3, sz, CV_8UC1, Scalar(1));       break;
        case 2:     MA_Mask_tmp = Mat(3, sz, CV_8UC2, Scalar(1));       break;
        case 3:     MA_Mask_tmp = Mat(3, sz, CV_8UC3, Scalar(1));       break;
        case 4:     MA_Mask_tmp = Mat(3, sz, CV_8UC4, Scalar(1));       break;
        default:                                                        return ER_channel_bad;}
    else
        switch (pMA_In->channels()) {
        case 1:     MA_Mask_tmp = Mat(3, sz, CV_64FC1, Scalar(1));      break;
        case 2:     MA_Mask_tmp = Mat(3, sz, CV_64FC2, Scalar(1));      break;
        case 3:     MA_Mask_tmp = Mat(3, sz, CV_64FC3, Scalar(1));      break;
        case 4:     MA_Mask_tmp = Mat(3, sz, CV_64FC4, Scalar(1));      break;
        default:                                                        return ER_channel_bad;}

    //Filter
    int ER;
    if(pMA_In->depth() == CV_8U)
    {
        ER = D_Img_Proc_3D::Filter_Function_8bit(
                pMA_Out,
                pMA_In,
                &MA_Mask_tmp,
                D_Math::Function_2D_to_1D_8bit(
                    c_MATH_2D_TO_1D_Y,
                    1, 0, 1, 0, 0, 0, 0, 0),
                D_Math::Function_2D_to_1D_8bit(
                    c_MATH_2D_TO_1D_X,
                    1, 0, 1, 0, 0, 0, 0, 0),
                D_Stat::Function_SingleStat_8bit(
                    c_STAT_MEDIAN),
                D_Math::Function_2D_to_1D_8bit(
                    c_MATH_2D_TO_1D_X,
                    1, 0, 1, 0, 0, 0, 0, 0),
                BORDER_REPLICATE);
    }
    else
    {
        ER = D_Img_Proc_3D::Filter_Function(
                pMA_Out,
                pMA_In,
                &MA_Mask_tmp,
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_Y,
                    1, 0, 1, 0, 0, 0, 0, 0),
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_X,
                    1, 0, 1, 0, 0, 0, 0, 0),
                D_Stat::Function_SingleStat(
                    c_STAT_MEDIAN),
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_X,
                    1, 0, 1, 0, 0, 0, 0, 0),
                BORDER_REPLICATE);
    }

    //end
    MA_Mask_tmp.release();
    return ER;
}

int D_Img_Proc_3D::Filter_Eilenstein_Greater_Sum(Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y, int size_z)
{
    //qDebug() << "D_Img_Proc_3D::Filter_Eilenstein_Greater_Sum" << "sizes x/y/z" << size_x << size_y << size_z;

    //Errors
    if(pMA_In->empty())                         return ER_empty;
    if((size_x < 1) || (size_x % 2 != 1))       return ER_parameter_bad;
    if((size_y < 1) || (size_y % 2 != 1))       return ER_parameter_bad;
    if((size_z < 1) || (size_z % 2 != 1))       return ER_parameter_bad;
    if(size_x > pMA_In->size[0])                return ER_size_missmatch;
    if(size_y > pMA_In->size[1])                return ER_size_missmatch;
    if(size_z > pMA_In->size[2])                return ER_size_missmatch;

    //mask
    int sz[] = {size_x, size_y, size_z};
    Mat MA_Mask_tmp;
    switch (pMA_In->channels()) {
    case 1:     MA_Mask_tmp = Mat(3, sz, CV_64FC1, Scalar(1));      break;
    case 2:     MA_Mask_tmp = Mat(3, sz, CV_64FC2, Scalar(1));      break;
    case 3:     MA_Mask_tmp = Mat(3, sz, CV_64FC3, Scalar(1));      break;
    case 4:     MA_Mask_tmp = Mat(3, sz, CV_64FC4, Scalar(1));      break;
    default:                                                        return ER_channel_bad;}

    //Filter
    int ER = D_Img_Proc_3D::Filter_Function(
                pMA_Out,
                pMA_In,
                &MA_Mask_tmp,
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_X_greater_Y,
                    1, 0, 1, 0, 0, 0, 0, 0),
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_X_times_Y,
                    1, 0, 1, 0, 0, 0, 0, 0),
                D_Stat::Function_SingleStat(
                    c_STAT_SUM),
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_X,
                    1, 0, 1, 0, 0, 0, 0, 0),
                BORDER_REPLICATE);

    //end
    MA_Mask_tmp.release();
    return ER;
}

int D_Img_Proc_3D::Morphology_Dilation(Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y, int size_z)
{
    //qDebug() << "D_Img_Proc_3D::Morphology_Dilation" << "sizes x/y/z" << size_x << size_y << size_z;

    //Errors
    if(pMA_In->empty())                         return ER_empty;
    if((size_x < 1) || (size_x % 2 != 1))       return ER_parameter_bad;
    if((size_y < 1) || (size_y % 2 != 1))       return ER_parameter_bad;
    if((size_z < 1) || (size_z % 2 != 1))       return ER_parameter_bad;
    if(size_x > pMA_In->size[0])                return ER_size_missmatch;
    if(size_y > pMA_In->size[1])                return ER_size_missmatch;
    if(size_z > pMA_In->size[2])                return ER_size_missmatch;

    //mask
    int sz[] = {size_x, size_y, size_z};
    Mat MA_Mask_tmp;
    if(pMA_In->depth() == CV_8U)
        switch (pMA_In->channels()) {
        case 1:     MA_Mask_tmp = Mat(3, sz, CV_8UC1, Scalar(1));       break;
        case 2:     MA_Mask_tmp = Mat(3, sz, CV_8UC2, Scalar(1));       break;
        case 3:     MA_Mask_tmp = Mat(3, sz, CV_8UC3, Scalar(1));       break;
        case 4:     MA_Mask_tmp = Mat(3, sz, CV_8UC4, Scalar(1));       break;
        default:                                                        return ER_channel_bad;}
    else
        switch (pMA_In->channels()) {
        case 1:     MA_Mask_tmp = Mat(3, sz, CV_64FC1, Scalar(1));      break;
        case 2:     MA_Mask_tmp = Mat(3, sz, CV_64FC2, Scalar(1));      break;
        case 3:     MA_Mask_tmp = Mat(3, sz, CV_64FC3, Scalar(1));      break;
        case 4:     MA_Mask_tmp = Mat(3, sz, CV_64FC4, Scalar(1));      break;
        default:                                                        return ER_channel_bad;}

    //Filter
    int ER;
    if(pMA_In->depth() == CV_8U)
        ER = D_Img_Proc_3D::Filter_Function_8bit(
                pMA_Out,
                pMA_In,
                &MA_Mask_tmp,
                D_Math::Function_2D_to_1D_8bit(
                    c_MATH_2D_TO_1D_Y,
                    1, 0, 1, 0, 0, 0, 0, 0),
                D_Math::Function_2D_to_1D_8bit(
                    c_MATH_2D_TO_1D_X,
                    1, 0, 1, 0, 0, 0, 0, 0),
                D_Stat::Function_SingleStat_8bit(
                    c_STAT_MAXIMUM),
                D_Math::Function_2D_to_1D_8bit(
                    c_MATH_2D_TO_1D_X,
                    1, 0, 1, 0, 0, 0, 0, 0),
                BORDER_REPLICATE);
    else
        ER = D_Img_Proc_3D::Filter_Function(
                pMA_Out,
                pMA_In,
                &MA_Mask_tmp,
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_Y,
                    1, 0, 1, 0, 0, 0, 0, 0),
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_X,
                    1, 0, 1, 0, 0, 0, 0, 0),
                D_Stat::Function_SingleStat(
                    c_STAT_MAXIMUM),
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_X,
                    1, 0, 1, 0, 0, 0, 0, 0),
                BORDER_REPLICATE);

    //end
    MA_Mask_tmp.release();
    return ER;
}

int D_Img_Proc_3D::Morphology_Erosion(Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y, int size_z)
{
    //qDebug() << "D_Img_Proc_3D::Morphology_Erosion" << "sizes x/y/z" << size_x << size_y << size_z;

    //Errors
    if(pMA_In->empty())                         return ER_empty;
    if((size_x < 1) || (size_x % 2 != 1))       return ER_parameter_bad;
    if((size_y < 1) || (size_y % 2 != 1))       return ER_parameter_bad;
    if((size_z < 1) || (size_z % 2 != 1))       return ER_parameter_bad;
    if(size_x > pMA_In->size[0])                return ER_size_missmatch;
    if(size_y > pMA_In->size[1])                return ER_size_missmatch;
    if(size_z > pMA_In->size[2])                return ER_size_missmatch;

    //mask
    int sz[] = {size_x, size_y, size_z};
    Mat MA_Mask_tmp;
    if(pMA_In->depth() == CV_8U)
        switch (pMA_In->channels()) {
        case 1:     MA_Mask_tmp = Mat(3, sz, CV_8UC1, Scalar(1));       break;
        case 2:     MA_Mask_tmp = Mat(3, sz, CV_8UC2, Scalar(1));       break;
        case 3:     MA_Mask_tmp = Mat(3, sz, CV_8UC3, Scalar(1));       break;
        case 4:     MA_Mask_tmp = Mat(3, sz, CV_8UC4, Scalar(1));       break;
        default:                                                        return ER_channel_bad;}
    else
        switch (pMA_In->channels()) {
        case 1:     MA_Mask_tmp = Mat(3, sz, CV_64FC1, Scalar(1));      break;
        case 2:     MA_Mask_tmp = Mat(3, sz, CV_64FC2, Scalar(1));      break;
        case 3:     MA_Mask_tmp = Mat(3, sz, CV_64FC3, Scalar(1));      break;
        case 4:     MA_Mask_tmp = Mat(3, sz, CV_64FC4, Scalar(1));      break;
        default:                                                        return ER_channel_bad;}

    //Filter
    int ER;
    if(pMA_In->depth() == CV_8U)
        ER = D_Img_Proc_3D::Filter_Function_8bit(
                pMA_Out,
                pMA_In,
                &MA_Mask_tmp,
                D_Math::Function_2D_to_1D_8bit(
                    c_MATH_2D_TO_1D_Y,
                    1, 0, 1, 0, 0, 0, 0, 0),
                D_Math::Function_2D_to_1D_8bit(
                    c_MATH_2D_TO_1D_X,
                    1, 0, 1, 0, 0, 0, 0, 0),
                D_Stat::Function_SingleStat_8bit(
                    c_STAT_MINIMUM),
                D_Math::Function_2D_to_1D_8bit(
                    c_MATH_2D_TO_1D_X,
                    1, 0, 1, 0, 0, 0, 0, 0),
                BORDER_REPLICATE);
    else
        ER = D_Img_Proc_3D::Filter_Function(
                pMA_Out,
                pMA_In,
                &MA_Mask_tmp,
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_Y,
                    1, 0, 1, 0, 0, 0, 0, 0),
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_X,
                    1, 0, 1, 0, 0, 0, 0, 0),
                D_Stat::Function_SingleStat(
                    c_STAT_MINIMUM),
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_X,
                    1, 0, 1, 0, 0, 0, 0, 0),
                BORDER_REPLICATE);

    //end
    MA_Mask_tmp.release();
    return ER;
}

int D_Img_Proc_3D::Neighborhood_Configs(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->type() != CV_8UC1)   return ER_type_bad;
    if(pMA_In->size[0] <= 1)        return ER_size_bad;
    if(pMA_In->size[1] <= 1)        return ER_size_bad;
    if(pMA_In->size[2] <= 1)        return ER_size_bad;

    //create & init kernel
    //3x3x3 for being able to use function filterig (2x2x2 is needed, but this way it is easier to implement. but slower... 27px loop instead of 8px loop)
    int sz_kernel[] = {3, 3, 3};
    Mat MA_Kernel_tmp = Mat::zeros(3, sz_kernel, CV_8UC1);
    Vec<int, 3> pos = {0, 0, 0};

    int val = 1;
    for(int z = 0; z < 2; z++)
        for(int x = 0; x < 2; x++)
            for(int y = 0; y < 2; y++)
            {
                pos = {x, y, z};
                //qDebug() << "val:" << val << "at x/y/z:" << x << y << z;
                MA_Kernel_tmp.at<uchar>(pos) = val;
                val *= 2;
            }

    //tmp output
    Mat MA_out_double_tmp;

    //Filter
    int ER = D_Img_Proc_3D::Filter_Function(
                &MA_out_double_tmp,
                pMA_In,
                &MA_Kernel_tmp,
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_Y,                  //norm to 0 or 1 (binary)
                    1, 0, (1.0/255.0), 0, 0, 0, 0, 0),
                D_Math::Function_2D_to_1D(              //multiply
                    c_MATH_2D_TO_1D_X_times_Y,
                    1, 0, 1, 0, 0, 0, 0, 0),
                D_Stat::Function_SingleStat(            //accumulate
                    c_STAT_SUM),
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_X,                  //non relfexive
                    1, 0, 1, 0, 0, 0, 0, 0),
                BORDER_REPLICATE);                      //with replicated border

    //check sucess & free
    MA_Kernel_tmp.release();
    if(ER != ER_okay)
    {
        MA_out_double_tmp.release();
        return ER;
    }

    //Convert to 8bit
    ER = D_Img_Proc_3D::Convert_Uchar_1C(
                pMA_Out,
                &MA_out_double_tmp);

    MA_out_double_tmp.release();
    return ER;
}

int D_Img_Proc_3D::Distance_Transformation_EDT(Mat *pMA_Out, Mat *pMA_In, double spacing_x, double spacing_y, double spacing_z)
{
    //Algorithm:
    //
    //T. Saito and J. Toriwaki
    //New algorithms for Euclidean distance transformations of an n-dimensional digitised picture with applications
    //Pattern Recognition
    //27(11):1551–1565
    //1994

    //Implementation ispired by:
    //
    //Joachim Ohser
    //Hochschule Darmstadt
    //3D-Bildverarbeitung - Konzepte und Algorithmen
    //Pages 96-107
    //07.07.2016

    //Errors
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->channels() != 1)     return ER_channel_bad;
    if(pMA_In->depth() != CV_8U)    return ER_bitdepth_bad;

    //sizes
    int sz_x        = pMA_In->size[0];
    int sz_y        = pMA_In->size[1];
    int sz_z        = pMA_In->size[2];
    int sz[]        = {sz_x, sz_y, sz_z};

    //pos
    int x, y, z;
    Vec<int, 3> pos = {0, 0, 0};

    //output
    *pMA_Out        = Mat(3, sz, CV_64FC1);

    //tmp distance
    Mat MA_dist_tmp = Mat(3, sz, CV_64FC1);
    vector<double> v_line;
    vector<double> v_dist;

    //init
    for(z = 0; z < sz_z; z++)
        for(y = 0; y < sz_y; y++)
            for(x = 0; x < sz_x; x++)
            {
                pos = {x, y, z};

                if(pMA_In->at<uchar>(pos))
                    MA_dist_tmp.at<double>(pos) = DBL_MAX;
                else
                    MA_dist_tmp.at<double>(pos) = 0.0;
            }

    //x-direction
    v_line.resize(sz_x);
    for(y = 0; y < sz_y; y++)
        for(z = 0; z < sz_z; z++)
        {
            //read line
            for(x = 0; x < sz_x; x++)
            {
                pos = {x, y, z};
                v_line[x] = MA_dist_tmp.at<double>(pos);
            }

            //distance transform line
            D_Math::Distance_Transformation_1D(
                        &v_dist,
                        v_line,
                        spacing_x);

            //write line
            for(x = 0; x < sz_x; x++)
            {
                pos = {x, y, z};
                MA_dist_tmp.at<double>(pos) = v_dist[x];
            }
        }

    //y-direction
    v_line.resize(sz_y);
    for(x = 0; x < sz_x; x++)
        for(z = 0; z < sz_z; z++)
        {
            //read line
            for(y = 0; y < sz_y; y++)
            {
                pos = {x, y, z};
                v_line[y] = MA_dist_tmp.at<double>(pos);
            }

            //distance transform line
            D_Math::Distance_Transformation_1D(
                        &v_dist,
                        v_line,
                        spacing_y);

            //write line
            for(y = 0; y < sz_y; y++)
            {
                pos = {x, y, z};
                MA_dist_tmp.at<double>(pos) = v_dist[y];
            }
        }

    //z-direction
    v_line.resize(sz_z);
    for(x = 0; x < sz_x; x++)
        for(y = 0; y < sz_y; y++)
        {
            //read line
            for(z = 0; z < sz_z; z++)
            {
                pos = {x, y, z};
                v_line[z] = MA_dist_tmp.at<double>(pos);
            }

            //distance transform line
            D_Math::Distance_Transformation_1D(
                        &v_dist,
                        v_line,
                        spacing_z);

            //write line
            for(z = 0; z < sz_z; z++)
            {
                pos = {x, y, z};
                MA_dist_tmp.at<double>(pos) = v_dist[z];
            }
        }

    for(z = 0; z < sz_z; z++)
        for(y = 0; y < sz_y; y++)
            for(x = 0; x < sz_x; x++)
            {
                pos = {x, y, z};

                pMA_Out->at<double>(pos) = sqrt(MA_dist_tmp.at<double>(pos));
            }

    return ER_okay;
}

int D_Img_Proc_3D::EulerNumber(double *euler_number, Mat *pMA_In)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->type() != CV_8UC1)   return ER_type_bad;

    int ER;

    //pixel neighborhood configs
    Mat MA_tmp_PxConfigs;
    ER = Neighborhood_Configs(
                &MA_tmp_PxConfigs,
                pMA_In);
    if(ER != ER_okay)
    {
        MA_tmp_PxConfigs.release();
        return ER;
    }

    //calc hist
    vector<double> v_hist;
    ER = Calc_Hist_8bit_1C(
                &v_hist,
                &MA_tmp_PxConfigs,
                false,
                false);
    MA_tmp_PxConfigs.release();
    if(ER != ER_okay)
        return ER;

    //weights
    vector<double> v_weights =
    {
        0,  1,  1,  0,  1,  0, -2, -1,
        1, -2,  0, -1,  0, -1, -1,  0,
        1,  0, -2, -1, -2, -1, -1, -2,
       -6, -3, -3, -2, -3, -2,  0, -1,

        1, -2,  0, -1, -6, -3, -3, -2,
       -2, -1, -1, -2, -3,  0, -2, -1,
        0, -1, -1,  0, -3, -2,  0, -1,
       -3,  0, -2, -1,  0,  1,  1,  0,

        1, -2, -6, -3,  0, -1, -3, -2,
       -2, -1, -3,  0, -1, -2, -2, -1,
        0, -1, -3, -2, -1,  0,  0, -1,
       -3,  0,  0,  1, -2, -1,  1,  0,

       -2, -1, -3,  0, -3,  0,  0,  1,
       -1,  4,  0,  3,  0,  3,  1,  2,
       -1, -2, -2, -1, -2, -1,  1,  0,
        0,  3,  1,  2,  1,  2,  2,  1,


        1, -6, -2, -3, -2, -3, -1,  0,
        0, -3, -1, -2, -1, -2, -2, -1,
       -2, -3, -1,  0, -1,  0,  4,  3,
       -3,  0,  0,  1,  0,  1,  3,  2,

        0, -3, -1, -2, -3,  0,  0,  1,
       -1,  0,  0, -1, -2,  1, -1,  0,
       -1, -2, -2, -1,  0,  1,  3,  2,
       -2,  1, -1,  0,  1,  2,  2,  1,

        0, -3, -3,  0, -1, -2,  0,  1,
       -1,  0, -2,  1,  0, -1, -1,  0,
       -1, -2,  0,  1, -2, -1,  3,  2,
       -2,  1,  1,  2, -1,  0,  2,  1,

       -1,  0, -2,  1, -2,  1,  1,  2,
       -2,  3, -1,  2, -1,  2,  0,  1,
        0, -1, -1,  0, -1,  0,  2,  1,
       -1,  2,  0,  1,  0,  1,  1,  0
    };

    //euler number
    *euler_number = 0;
    for(size_t i = 0; i < v_hist.size(); i++)
        *euler_number += (v_hist[i] * v_weights[i] * (1.0/8.0));

    return ER_okay;
}

int D_Img_Proc_3D::EulerNumber(double *euler_number, Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->type() != CV_8UC1)   return ER_type_bad;

    int ER;

    //pixel neighborhood configs
    ER = Neighborhood_Configs(
                pMA_Out,
                pMA_In);
    if(ER != ER_okay)
        return ER;

    //calc hist
    vector<double> v_hist;
    ER = Calc_Hist_8bit_1C(
                &v_hist,
                pMA_Out,
                false,
                false);
    if(ER != ER_okay)
        return ER;

    //weights
    vector<double> v_weights =
    {
        0,  1,  1,  0,  1,  0, -2, -1,
        1, -2,  0, -1,  0, -1, -1,  0,
        1,  0, -2, -1, -2, -1, -1, -2,
       -6, -3, -3, -2, -3, -2,  0, -1,

        1, -2,  0, -1, -6, -3, -3, -2,
       -2, -1, -1, -2, -3,  0, -2, -1,
        0, -1, -1,  0, -3, -2,  0, -1,
       -3,  0, -2, -1,  0,  1,  1,  0,

        1, -2, -6, -3,  0, -1, -3, -2,
       -2, -1, -3,  0, -1, -2, -2, -1,
        0, -1, -3, -2, -1,  0,  0, -1,
       -3,  0,  0,  1, -2, -1,  1,  0,

       -2, -1, -3,  0, -3,  0,  0,  1,
       -1,  4,  0,  3,  0,  3,  1,  2,
       -1, -2, -2, -1, -2, -1,  1,  0,
        0,  3,  1,  2,  1,  2,  2,  1,


        1, -6, -2, -3, -2, -3, -1,  0,
        0, -3, -1, -2, -1, -2, -2, -1,
       -2, -3, -1,  0, -1,  0,  4,  3,
       -3,  0,  0,  1,  0,  1,  3,  2,

        0, -3, -1, -2, -3,  0,  0,  1,
       -1,  0,  0, -1, -2,  1, -1,  0,
       -1, -2, -2, -1,  0,  1,  3,  2,
       -2,  1, -1,  0,  1,  2,  2,  1,

        0, -3, -3,  0, -1, -2,  0,  1,
       -1,  0, -2,  1,  0, -1, -1,  0,
       -1, -2,  0,  1, -2, -1,  3,  2,
       -2,  1,  1,  2, -1,  0,  2,  1,

       -1,  0, -2,  1, -2,  1,  1,  2,
       -2,  3, -1,  2, -1,  2,  0,  1,
        0, -1, -1,  0, -1,  0,  2,  1,
       -1,  2,  0,  1,  0,  1,  1,  0
    };

    //euler number
    *euler_number = 0;
    for(size_t i = 0; i < v_hist.size(); i++)
        *euler_number += (v_hist[i] * v_weights[i] * (1.0/8.0));

    return ER_okay;
}

int D_Img_Proc_3D::Calc_Hist_8bit_1C(vector<double> *v_hist, Mat *pMA_In, bool uniform, bool accum)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->type() != CV_8UC1)   return ER_type_bad;

    //size
    int vol = pMA_In->size[0] * pMA_In->size[1] * pMA_In->size[2];

    //clear, resize, init hist
    v_hist->clear();
    v_hist->resize(256, 0);

    //loop img and count
    uchar* ptr = reinterpret_cast<uchar*>(pMA_In->data);
    for(int px = 0; px < vol; px++, ptr++)
        (*v_hist)[*ptr]++;

    //accumulate?
    if(accum)
        for(size_t v = 1; v < v_hist->size(); v++)
            (*v_hist)[v] += (*v_hist)[v - 1];

    //uniform?
    if(uniform)
        for(size_t v = 0; v < v_hist->size(); v++)
            (*v_hist)[v] /= static_cast<double>(vol);

    return ER_okay;
}

int D_Img_Proc_3D::InterferometerMichelson(Mat *pMA_Out, int scene_size_x_px, int scene_size_y_px, int scene_size_z_px, double scale_px2um, double wavelength_um, double dist_source_um, double dist_detector_um, double dist_mirror1_um, double dist_mirror2_um, double angle_mirror1_x, double angle_mirror1_y, double angle_mirror2_x, double angle_mirror2_y, bool intensity_notfield, bool beam_atSO_SO, bool beam_atSO_M1_SO, bool beam_atSO_SP_M2_SP_SO, bool beam_atM1_SO, bool beam_atM1_M1_SO, bool beam_atM2_SP_SO, bool beam_atM2_M2_SP_SO, bool beam_atDE_SP_M1_SO, bool beam_atDE_M2_SP_SO)
{
    //errors
    if(scene_size_x_px < 3)                                 return ER_size_bad;
    if(scene_size_y_px < 3)                                 return ER_size_bad;
    if(scene_size_z_px < 1)                                 return ER_size_bad;
    if(wavelength_um <= 0)                                  return ER_parameter_bad;
    if(scale_px2um <= 0)                                    return ER_parameter_bad;
    if(dist_source_um < 0)                                  return ER_parameter_bad;
    if(dist_detector_um < 0)                                return ER_parameter_bad;
    if(dist_mirror1_um < 0)                                 return ER_parameter_bad;
    if(dist_mirror2_um < 0)                                 return ER_parameter_bad;
    if(angle_mirror1_x <= -PI || angle_mirror1_x >= PI)     return ER_parameter_bad;
    if(angle_mirror2_x <= -PI || angle_mirror2_x >= PI)     return ER_parameter_bad;
    if(angle_mirror1_y <= -PI || angle_mirror1_y >= PI)     return ER_parameter_bad;
    if(angle_mirror2_y <= -PI || angle_mirror2_y >= PI)     return ER_parameter_bad;

    //sizes
    int nx              = scene_size_x_px;
    int ny              = scene_size_y_px;
    int nz              = scene_size_z_px;
    int scene_size[]    = {nx, ny, nz};


    //output
    *pMA_Out            = Mat::zeros(3, scene_size, CV_64FC1);

    //pos
    Vec<int, 3> pos_px  = {0, 0, 0};

    //mirrors & source ----------------------------------------------------------

    //max field strength
    double E_max = 1;

    //source
    int y_source_px = ny/2 + dist_source_um / scale_px2um;
    for(int z = 0; z < nz; z++)
        for(int y = max((2*ny)/3, y_source_px); y < ny; y++)
        {
            for(int x = (2*nx)/9; x < (3*nx)/9; x++)
            {
                //pixel pos
                pos_px[0] = x;
                pos_px[1] = y;
                pos_px[2] = z;

                pMA_Out->at<double>(pos_px) = E_max;
            }

            for(int x = (6*nx)/9; x < (7*nx)/9; x++)
            {
                //pixel pos
                pos_px[0] = x;
                pos_px[1] = y;
                pos_px[2] = z;

                pMA_Out->at<double>(pos_px) = E_max;
            }
        }

    //mirror 1
    int y_mirror1_px = ny/2 - dist_mirror1_um / scale_px2um;
    for(int z = 0; z < nz; z++)
        for(int y = 0; y < min(ny/3, y_mirror1_px); y++)
        {
            for(int x = (2*nx)/9; x < (3*nx)/9; x++)
            {
                //pixel pos
                pos_px[0] = x;
                pos_px[1] = y;
                pos_px[2] = z;

                pMA_Out->at<double>(pos_px) = E_max;
            }

            for(int x = (6*nx)/9; x < (7*nx)/9; x++)
            {
                //pixel pos
                pos_px[0] = x;
                pos_px[1] = y;
                pos_px[2] = z;

                pMA_Out->at<double>(pos_px) = E_max;
            }
        }

    //source
    int x_mirror2_px = nx/2 + dist_mirror2_um / scale_px2um;
    for(int z = 0; z < nz; z++)
        for(int x = max(nx/3, x_mirror2_px); x < nx; x++)
        {
            for(int y = (2*ny)/9; y < (3*ny)/9; y++)
            {
                //pixel pos
                pos_px[0] = x;
                pos_px[1] = y;
                pos_px[2] = z;

                pMA_Out->at<double>(pos_px) = E_max;
            }

            for(int y = (6*ny)/9; y < (7*ny)/9; y++)
            {
                //pixel pos
                pos_px[0] = x;
                pos_px[1] = y;
                pos_px[2] = z;

                pMA_Out->at<double>(pos_px) = E_max;
            }
        }


    //waves----------------------------------------------------------------------

    //slope of diagonal
    double slope_inverse = static_cast<double>(nx) / static_cast<double>(ny);

    //SO = Source (bottom)
    //DE = Detector (left)
    //M1 = Mirror 1 (top)
    //M2 = Mirrror 2 (right)
    //SP = Splitter (center)

    //Splitter is center of image and center of coordinate system

    //coordinates of objects (metric, homogenious)
    //                                          x                   y                   z       object
    Mat Obj_sp_h_SP = D_Math::Homogenious_3D(   0,                  0,                  0);     //Splitter
    Mat Obj_sp_h_M1 = D_Math::Homogenious_3D(   0,                  -dist_mirror1_um,   0);     //Mirror 1
    Mat Obj_sp_h_M2 = D_Math::Homogenious_3D(   dist_mirror2_um,    0,                  0);     //Mirror 2
    Mat Obj_sp_h_SO = D_Math::Homogenious_3D(   0,                  dist_source_um,     0);     //Source
    Mat Obj_sp_h_DE = D_Math::Homogenious_3D(   -dist_detector_um,  0,                  0);     //Detector



    //visible light source from regions

    //region SO
    // 1/1 SO
    // 1/4 M1 SO
    // 1/4 SP M2 SP SO

    //region DE
    // 1/4 SP M1 SO
    // 1/4 M2 SP SO

    //region M1
    // 1/2 SO
    // 1/2 M1 SO

    //region M2
    // 1/2 SP SO
    // 1/2 M2 SP SO



    //light source relevant at a point
    vector<Mat>     vSource;
    vector<double>  vPhaseOffset;
    vector<double>  vFieldstrength;



    //region SO ------------------------------------------------------------------------------------------------

    //visible sources
    // 1/1 SO
    // 1/4 M1 SO
    // 1/4 SP M2 SP SO

    //clear sources
    vSource.clear();
    vPhaseOffset.clear();
    vFieldstrength.clear();


    // 1/1 SO
    if(beam_atSO_SO)
    {
        vSource.push_back(D_Math::Inhomogenious_3D(Obj_sp_h_SO));
        vPhaseOffset.push_back(0);
        vFieldstrength.push_back(1);
    }

    // 1/4 M1 SO
    if(beam_atSO_M1_SO)
    {
        vSource.push_back(D_Math::Inhomogenious_3D(
                    D_Math::Shift_3D_h(0, -dist_mirror1_um, 0) *
                    D_Math::Rotation_3D_h_rad(0, 2 * angle_mirror1_y, 2 * angle_mirror1_x + PI) *
                    D_Math::Shift_3D_h(0, +dist_mirror1_um, 0) *
                    Obj_sp_h_SO));
        vPhaseOffset.push_back(PI);
        vFieldstrength.push_back(0.25);
    }

    // 1/4 SP M2 SP SO
    if(beam_atSO_SP_M2_SP_SO)
    {
        vSource.push_back(D_Math::Inhomogenious_3D(
                    D_Math::Rotation_3D_h_rad(0, 0, -PI_0_5) *                                      //Reflection Splitter
                    D_Math::Shift_3D_h(+dist_mirror2_um, 0, 0) *                                        //Center: Mirror2 -> Splitter
                    D_Math::Rotation_3D_h_rad(0, 2 * angle_mirror2_y, 0) *                              //Reflection Mirror2 (mirror orientation y) !!!FIXME!!! rotation has no effect
                    D_Math::Rotation_3D_h_rad(0, 0, 2 * angle_mirror2_x) *                              //Reflection Mirror2 (mirror orientation x)
                    D_Math::Rotation_3D_h_rad(0, 0, PI) *                                               //Reflection Mirror2 (basic reflection)
                    D_Math::Shift_3D_h(-dist_mirror2_um, 0, 0) *                                        //Center: Splitter -> Mirror2
                    D_Math::Rotation_3D_h_rad(0, 0, PI_0_5) *                                       //Reflection Splitter
                    Obj_sp_h_SO));                                                                  //Source
        vPhaseOffset.push_back(3 * PI);
        vFieldstrength.push_back(0.25);
    }

    //loop region and calc interference
    for(int z = 0; z < nz; z++)
        for(int y = ny/3; y < ny; y++)
            for(int x = max(nx/3, static_cast<int>((ny-y-1) * slope_inverse)); x < (nx*2)/3; x++)
            {
                //pixel pos
                pos_px[0] = x;
                pos_px[1] = y;
                pos_px[2] = z;

                //world coordiante pos
                Mat pos_world = D_Math::Inhomogenious_3D(
                            (x - nx/2) * scale_px2um,
                            (y - ny/2) * scale_px2um,
                            (z - nz/2) * scale_px2um);

                //loop sources
                for(size_t s = 0; s < vSource.size(); s++)
                    pMA_Out->at<double>(pos_px) += D_Physics::FieldStrength(
                                pos_world,
                                vSource[s],
                                vFieldstrength[s],
                                vPhaseOffset[s],
                                wavelength_um);
            }

    //region M2 ------------------------------------------------------------------------------------------------

    //region M2
    // 1/2 SP SO
    // 1/2 M2 SP SO

    //resize sources
    vSource.clear();
    vPhaseOffset.clear();
    vFieldstrength.clear();

    // 1/2 SP SO
    if(beam_atM2_SP_SO)
    {
        vSource.push_back(D_Math::Inhomogenious_3D(
                    D_Math::Rotation_3D_h_rad(0, 0, PI_0_5) *       //Reflection Splitter
                    Obj_sp_h_SO));                                  //Source
        vPhaseOffset.push_back(PI);
        vFieldstrength.push_back(0.5);
    }


    // 1/2 M2 SP SO
    if(beam_atM2_M2_SP_SO)
    {
        vSource.push_back(D_Math::Inhomogenious_3D(
                    D_Math::Shift_3D_h(+dist_mirror2_um, 0, 0) *                                        //Center: Mirror2 -> Splitter
                    D_Math::Rotation_3D_h_rad(0, 2 * angle_mirror2_y, 0) *                              //Reflection Mirror2 (mirror orientation y) !!!FIXME!!! rotation has no effect
                    D_Math::Rotation_3D_h_rad(0, 0, 2 * angle_mirror2_x) *                              //Reflection Mirror2 (mirror orientation x)
                    D_Math::Rotation_3D_h_rad(0, 0, PI) *                                               //Reflection Mirror2 (basic reflection)
                    D_Math::Shift_3D_h(-dist_mirror2_um, 0, 0) *                                        //Center: Splitter -> Mirror2
                    D_Math::Rotation_3D_h_rad(0, 0, PI_0_5) *                                       //Reflection Splitter
                    Obj_sp_h_SO));                                                                  //Source
        vPhaseOffset.push_back(2 * PI);
        vFieldstrength.push_back(0.5);
    }


    //loop region and calc interference
    for(int z = 0; z < nz; z++)
        for(int y = ny/3; y < (ny*2)/3; y++)
            for(int x = max(nx/3, static_cast<int>((ny-y-1) * slope_inverse)); x < nx; x++)
            {
                //pixel pos
                pos_px[0] = x;
                pos_px[1] = y;
                pos_px[2] = z;

                //world coordiante pos
                Mat pos_world = D_Math::Inhomogenious_3D(
                            (x - nx/2) * scale_px2um,
                            (y - ny/2) * scale_px2um,
                            (z - nz/2) * scale_px2um);

                //loop sources
                for(size_t s = 0; s < vSource.size(); s++)
                    pMA_Out->at<double>(pos_px) += D_Physics::FieldStrength(
                                pos_world,
                                vSource[s],
                                vFieldstrength[s],
                                vPhaseOffset[s],
                                wavelength_um);
            }

    //region M1 ------------------------------------------------------------------------------------------------

    //region M1
    // 1/2 SO
    // 1/2 M1 SO

    //clear sources
    vSource.clear();
    vPhaseOffset.clear();
    vFieldstrength.clear();

    // 1/2 SO
    if(beam_atM1_SO)
    {
        vSource.push_back(D_Math::Inhomogenious_3D(Obj_sp_h_SO));
        vPhaseOffset.push_back(0);
        vFieldstrength.push_back(0.5);
    }

    // 1/2 M1 SO
    if(beam_atM1_M1_SO)
    {
        vSource.push_back(D_Math::Inhomogenious_3D(
                    D_Math::Shift_3D_h(0, -dist_mirror1_um, 0) *
                    D_Math::Rotation_3D_h_rad(0, 2 * angle_mirror1_y, 2 * angle_mirror1_x + PI) *
                    D_Math::Shift_3D_h(0, +dist_mirror1_um, 0) *
                    Obj_sp_h_SO));
        vPhaseOffset.push_back(PI);
        vFieldstrength.push_back(0.5);
    }

    //loop region and calc interference
    for(int z = 0; z < nz; z++)
        for(int y = 0; y < (ny*2)/3; y++)
            for(int x = nx/3; x < min((nx*2)/3, static_cast<int>((ny-y-1) * slope_inverse)); x++)
            {
                //pixel pos
                pos_px[0] = x;
                pos_px[1] = y;
                pos_px[2] = z;

                //world coordiante pos
                Mat pos_world = D_Math::Inhomogenious_3D(
                            (x - nx/2) * scale_px2um,
                            (y - ny/2) * scale_px2um,
                            (z - nz/2) * scale_px2um);

                //loop sources
                for(size_t s = 0; s < vSource.size(); s++)
                    pMA_Out->at<double>(pos_px) += D_Physics::FieldStrength(
                                pos_world,
                                vSource[s],
                                vFieldstrength[s],
                                vPhaseOffset[s],
                                wavelength_um);
            }

    //region DE ------------------------------------------------------------------------------------------------

    //region DE
    // 1/4 SP M1 SO
    // 1/4 M2 SP SO

    //resize sources
    vSource.clear();
    vPhaseOffset.clear();
    vFieldstrength.clear();

    // 1/4 M2 SP SO
    if(beam_atDE_M2_SP_SO)
    {
        vSource.push_back(D_Math::Inhomogenious_3D(
                    D_Math::Shift_3D_h(+dist_mirror2_um, 0, 0) *                                        //Center: Mirror2 -> Splitter
                    D_Math::Rotation_3D_h_rad(0, 2 * angle_mirror2_y, 0) *                              //Reflection Mirror2 (mirror orientation y) !!!FIXME!!! rotation has no effect
                    D_Math::Rotation_3D_h_rad(0, 0, 2 * angle_mirror2_x) *                              //Reflection Mirror2 (mirror orientation x)
                    D_Math::Rotation_3D_h_rad(0, 0, PI) *                                               //Reflection Mirror2 (basic reflection)
                    D_Math::Shift_3D_h(-dist_mirror2_um, 0, 0) *                                        //Center: Splitter -> Mirror2
                    D_Math::Rotation_3D_h_rad(0, 0, PI_0_5) *                                       //Reflection Splitter
                    Obj_sp_h_SO));                                                                  //Source
        vPhaseOffset.push_back(2 * PI);
        vFieldstrength.push_back(0.25);
    }

    // 1/4 SP M1 SO
    if(beam_atDE_SP_M1_SO)
    {
        vSource.push_back(D_Math::Inhomogenious_3D(
                    D_Math::Rotation_3D_h_rad(0, 0, PI_0_5) *
                    D_Math::Shift_3D_h(0, -dist_mirror1_um, 0) *
                    D_Math::Rotation_3D_h_rad(0, 2 * angle_mirror1_y, 2 * angle_mirror1_x + PI) *
                    D_Math::Shift_3D_h(0, +dist_mirror1_um, 0) *
                    Obj_sp_h_SO));
        vPhaseOffset.push_back(PI); //2 reflections, but one reflection at n'<n on upper side of splitter (no phaseshift) -> 1 phaseshift
        vFieldstrength.push_back(0.25);
    }

    //loop region and calc interference
    for(int z = 0; z < nz; z++)
        for(int y = ny/3; y < (ny*2)/3; y++)
            for(int x = 0; x < static_cast<int>((ny-y-1) * slope_inverse); x++)
            {
                //pixel pos
                pos_px[0] = x;
                pos_px[1] = y;
                pos_px[2] = z;

                //world coordiante pos
                Mat pos_world = D_Math::Inhomogenious_3D(
                            (x - nx/2) * scale_px2um,
                            (y - ny/2) * scale_px2um,
                            (z - nz/2) * scale_px2um);

                //loop sources
                for(size_t s = 0; s < vSource.size(); s++)
                    pMA_Out->at<double>(pos_px) += D_Physics::FieldStrength(
                                pos_world,
                                vSource[s],
                                vFieldstrength[s],
                                vPhaseOffset[s],
                                wavelength_um);
            }

    //fieldstrength -> intensity
    if(intensity_notfield)
    {
        double* ptr = reinterpret_cast<double*>(pMA_Out->data);
        int px_count = nx * ny * nz;
        for(int px = 0; px < px_count; px++, ptr++)
            *ptr = (*ptr) * (*ptr);
    }

    Obj_sp_h_SP.release();
    Obj_sp_h_SO.release();
    Obj_sp_h_DE.release();
    Obj_sp_h_M1.release();
    Obj_sp_h_M2.release();
    return ER_okay;
}















