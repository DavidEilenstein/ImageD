#include "d_visdat_obj.h"

D_VisDat_Obj::D_VisDat_Obj()
{
    Init();
}

D_VisDat_Obj::D_VisDat_Obj(double init_val)
{
    Init(init_val);
}

D_VisDat_Obj::D_VisDat_Obj(D_VisDat_Dim dim, int mat_typ)
{
    VD_Dim = dim;
    MA_Type = mat_typ;

    Init();
}

D_VisDat_Obj::D_VisDat_Obj(D_VisDat_Dim dim, int mat_typ, double init_val)
{
    VD_Dim = dim;
    MA_Type = mat_typ;

    Init(init_val);
}

D_VisDat_Obj::D_VisDat_Obj(D_VisDat_Header Header)
{
    VD_Dim = D_VisDat_Dim(Header);
    MA_Type = Header.Type_of_mat();
    QS_Name = Header.SaveTime();

    Init();
}

Mat D_VisDat_Obj::MA_2dMat(D_VisDat_Slice_2D Slice_2d)
{
    Slice_2d.forceToBeInRangeOf(VD_Dim);                                    //Force slice to be in range of this object and to be still 2D

    D_VisDat_Range RG_Cut2d(Slice_2d);                                      //Create Range from slice in this object

    Mat MA_tmp_6D_with2extended = MA_SubMat(RG_Cut2d);                      //Cut a sub Mat (technically still 6D)

    int size_2d[] = {VD_Dim.size_Dim(Slice_2d.extended_Dim(0)), VD_Dim.size_Dim(Slice_2d.extended_Dim(1))};  //size of requested sub mat

    return Mat(2, size_2d, MA_Type, MA_tmp_6D_with2extended.ptr());        //reinterpret data as 2D mat
}

Mat D_VisDat_Obj::MA_SubMat(D_VisDat_Range RG)
{
    //return new submat with range RG safe in Dim of this object
    //if a range outranges, full availiable range is used instead
    //the returned mat uses the same memory as this object
    //returned memory has same number of dimensions as this object

    return MA_Data(RG.Ranges(VD_Dim));
}

int D_VisDat_Obj::size_PixelCount()
{
    return VD_Dim.size_PixelCount();
}

int D_VisDat_Obj::size_BitPerPixel()
{
    int bit_p_px = 0;

    switch (MA_Type) {
    case CV_8UC1:   bit_p_px = 8;   break;
    case CV_8SC1:   bit_p_px = 8;   break;
    case CV_16UC1:  bit_p_px = 16;  break;
    case CV_16SC1:  bit_p_px = 16;  break;
    case CV_32SC1:  bit_p_px = 32;  break;
    case CV_32FC1:  bit_p_px = 32;  break;
    case CV_64FC1:  bit_p_px = 64;  break;
    case CV_8UC2:   bit_p_px = 16;  break;
    case CV_8SC2:   bit_p_px = 16;  break;
    case CV_16UC2:  bit_p_px = 32;  break;
    case CV_16SC2:  bit_p_px = 32;  break;
    case CV_32SC2:  bit_p_px = 64;  break;
    case CV_32FC2:  bit_p_px = 64;  break;
    case CV_64FC2:  bit_p_px = 128; break;
    case CV_8UC3:   bit_p_px = 24;  break;
    case CV_8SC3:   bit_p_px = 24;  break;
    case CV_16UC3:  bit_p_px = 48;  break;
    case CV_16SC3:  bit_p_px = 48;  break;
    case CV_32SC3:  bit_p_px = 96;  break;
    case CV_32FC3:  bit_p_px = 96;  break;
    case CV_64FC3:  bit_p_px = 192; break;
    case CV_8UC4:   bit_p_px = 32;  break;
    case CV_8SC4:   bit_p_px = 32;  break;
    case CV_16UC4:  bit_p_px = 64;  break;
    case CV_16SC4:  bit_p_px = 64;  break;
    case CV_32SC4:  bit_p_px = 128; break;
    case CV_32FC4:  bit_p_px = 128; break;
    case CV_64FC4:  bit_p_px = 256; break;
    default:                        break;}

    return bit_p_px;
}

int D_VisDat_Obj::size_Bit()
{
    return size_PixelCount() * size_BitPerPixel();
}

int D_VisDat_Obj::size_Byte()
{
    return size_Bit() / 8;
}

QString D_VisDat_Obj::info()
{
    return "OBJ_INFO: " + Info_Type(true);
}

QString D_VisDat_Obj::info_short()
{
    QString QS_dims;

    int     ch = 1;     //channel
    int     bd = 8;     //bit depth
    QString tp = "U";   //sign/type

    switch (MA_Type) {

    case CV_8UC1:   bd = 8;     ch = 1;     tp = "U";   break;
    case CV_8SC1:   bd = 8;     ch = 1;     tp = "S";   break;
    case CV_16UC1:  bd = 16;    ch = 1;     tp = "U";   break;
    case CV_16SC1:  bd = 16;    ch = 1;     tp = "S";   break;
    case CV_32SC1:  bd = 32;    ch = 1;     tp = "S";   break;
    case CV_32FC1:  bd = 32;    ch = 1;     tp = "F";   break;
    case CV_64FC1:  bd = 64;    ch = 1;     tp = "F";   break;
    case CV_8UC2:   bd = 8;     ch = 2;     tp = "U";   break;
    case CV_8SC2:   bd = 8;     ch = 2;     tp = "S";   break;
    case CV_16UC2:  bd = 16;    ch = 2;     tp = "U";   break;
    case CV_16SC2:  bd = 16;    ch = 2;     tp = "S";   break;
    case CV_32SC2:  bd = 32;    ch = 2;     tp = "S";   break;
    case CV_32FC2:  bd = 32;    ch = 2;     tp = "F";   break;
    case CV_64FC2:  bd = 64;    ch = 2;     tp = "F";   break;
    case CV_8UC3:   bd = 8;     ch = 3;     tp = "U";   break;
    case CV_8SC3:   bd = 8;     ch = 3;     tp = "S";   break;
    case CV_16UC3:  bd = 16;    ch = 3;     tp = "U";   break;
    case CV_16SC3:  bd = 16;    ch = 3;     tp = "S";   break;
    case CV_32SC3:  bd = 32;    ch = 3;     tp = "S";   break;
    case CV_32FC3:  bd = 32;    ch = 3;     tp = "F";   break;
    case CV_64FC3:  bd = 64;    ch = 3;     tp = "F";   break;
    case CV_8UC4:   bd = 8;     ch = 4;     tp = "U";   break;
    case CV_8SC4:   bd = 8;     ch = 4;     tp = "S";   break;
    case CV_16UC4:  bd = 16;    ch = 4;     tp = "U";   break;
    case CV_16SC4:  bd = 16;    ch = 4;     tp = "S";   break;
    case CV_32SC4:  bd = 32;    ch = 4;     tp = "S";   break;
    case CV_32FC4:  bd = 32;    ch = 4;     tp = "F";   break;
    case CV_64FC4:  bd = 64;    ch = 4;     tp = "F";   break;
    default:                                            return QSL_Errors[ER_type_bad];}

    QS_dims.append(QString::number(bd));
    QS_dims.append(tp);

    if(ch > 1)                  QS_dims.append("_C" + QString::number(ch));
    if(VD_Dim.size_X() > 1)     QS_dims.append("_X" + QString::number(VD_Dim.size_X()));
    if(VD_Dim.size_Y() > 1)     QS_dims.append("_Y" + QString::number(VD_Dim.size_Y()));
    if(VD_Dim.size_Z() > 1)     QS_dims.append("_Z" + QString::number(VD_Dim.size_Z()));
    if(VD_Dim.size_T() > 1)     QS_dims.append("_T" + QString::number(VD_Dim.size_T()));
    if(VD_Dim.size_S() > 1)     QS_dims.append("_S" + QString::number(VD_Dim.size_S()));
    if(VD_Dim.size_P() > 1)     QS_dims.append("_P" + QString::number(VD_Dim.size_P()));

    return QS_dims;
}

QString D_VisDat_Obj::Info_Dims()
{
    QString QS_dims;

    int     ch = 1;     //channel
    int     bd = 8;     //bit depth
    QString tp = "U";   //sign/type

    switch (MA_Type) {

    case CV_8UC1:   bd = 8;     ch = 1;     tp = "U";   break;
    case CV_8SC1:   bd = 8;     ch = 1;     tp = "S";   break;
    case CV_16UC1:  bd = 16;    ch = 1;     tp = "U";   break;
    case CV_16SC1:  bd = 16;    ch = 1;     tp = "S";   break;
    case CV_32SC1:  bd = 32;    ch = 1;     tp = "S";   break;
    case CV_32FC1:  bd = 32;    ch = 1;     tp = "F";   break;
    case CV_64FC1:  bd = 64;    ch = 1;     tp = "F";   break;
    case CV_8UC2:   bd = 8;     ch = 2;     tp = "U";   break;
    case CV_8SC2:   bd = 8;     ch = 2;     tp = "S";   break;
    case CV_16UC2:  bd = 16;    ch = 2;     tp = "U";   break;
    case CV_16SC2:  bd = 16;    ch = 2;     tp = "S";   break;
    case CV_32SC2:  bd = 32;    ch = 2;     tp = "S";   break;
    case CV_32FC2:  bd = 32;    ch = 2;     tp = "F";   break;
    case CV_64FC2:  bd = 64;    ch = 2;     tp = "F";   break;
    case CV_8UC3:   bd = 8;     ch = 3;     tp = "U";   break;
    case CV_8SC3:   bd = 8;     ch = 3;     tp = "S";   break;
    case CV_16UC3:  bd = 16;    ch = 3;     tp = "U";   break;
    case CV_16SC3:  bd = 16;    ch = 3;     tp = "S";   break;
    case CV_32SC3:  bd = 32;    ch = 3;     tp = "S";   break;
    case CV_32FC3:  bd = 32;    ch = 3;     tp = "F";   break;
    case CV_64FC3:  bd = 64;    ch = 3;     tp = "F";   break;
    case CV_8UC4:   bd = 8;     ch = 4;     tp = "U";   break;
    case CV_8SC4:   bd = 8;     ch = 4;     tp = "S";   break;
    case CV_16UC4:  bd = 16;    ch = 4;     tp = "U";   break;
    case CV_16SC4:  bd = 16;    ch = 4;     tp = "S";   break;
    case CV_32SC4:  bd = 32;    ch = 4;     tp = "S";   break;
    case CV_32FC4:  bd = 32;    ch = 4;     tp = "F";   break;
    case CV_64FC4:  bd = 64;    ch = 4;     tp = "F";   break;
    default:                                            return QSL_Errors[ER_type_bad];}

    QS_dims.append("B" + QString::number(bd));
    QS_dims.append(tp);
    QS_dims.append("_C" + QString::number(ch));
    QS_dims.append("_X" + QString::number(VD_Dim.size_X()));
    QS_dims.append("_Y" + QString::number(VD_Dim.size_Y()));
    QS_dims.append("_Z" + QString::number(VD_Dim.size_Z()));
    QS_dims.append("_T" + QString::number(VD_Dim.size_T()));
    QS_dims.append("_S" + QString::number(VD_Dim.size_S()));
    QS_dims.append("_P" + QString::number(VD_Dim.size_P()));

    return QS_dims;
}

QString D_VisDat_Obj::Info_Type(bool more_detail)
{
    QString QS_type = QS_Name + ": ";

    int     ch; //channel
    int     bd; //bit depth
    QString tp; //sign/type

    switch (MA_Type) {

    case CV_8UC1:   bd = 8;     ch = 1;     tp = "U";   break;
    case CV_8SC1:   bd = 8;     ch = 1;     tp = "S";   break;
    case CV_16UC1:  bd = 16;    ch = 1;     tp = "U";   break;
    case CV_16SC1:  bd = 16;    ch = 1;     tp = "S";   break;
    case CV_32SC1:  bd = 32;    ch = 1;     tp = "S";   break;
    case CV_32FC1:  bd = 32;    ch = 1;     tp = "F";   break;
    case CV_64FC1:  bd = 64;    ch = 1;     tp = "F";   break;
    case CV_8UC2:   bd = 8;     ch = 2;     tp = "U";   break;
    case CV_8SC2:   bd = 8;     ch = 2;     tp = "S";   break;
    case CV_16UC2:  bd = 16;    ch = 2;     tp = "U";   break;
    case CV_16SC2:  bd = 16;    ch = 2;     tp = "S";   break;
    case CV_32SC2:  bd = 32;    ch = 2;     tp = "S";   break;
    case CV_32FC2:  bd = 32;    ch = 2;     tp = "F";   break;
    case CV_64FC2:  bd = 64;    ch = 2;     tp = "F";   break;
    case CV_8UC3:   bd = 8;     ch = 3;     tp = "U";   break;
    case CV_8SC3:   bd = 8;     ch = 3;     tp = "S";   break;
    case CV_16UC3:  bd = 16;    ch = 3;     tp = "U";   break;
    case CV_16SC3:  bd = 16;    ch = 3;     tp = "S";   break;
    case CV_32SC3:  bd = 32;    ch = 3;     tp = "S";   break;
    case CV_32FC3:  bd = 32;    ch = 3;     tp = "F";   break;
    case CV_64FC3:  bd = 64;    ch = 3;     tp = "F";   break;
    case CV_8UC4:   bd = 8;     ch = 4;     tp = "U";   break;
    case CV_8SC4:   bd = 8;     ch = 4;     tp = "S";   break;
    case CV_16UC4:  bd = 16;    ch = 4;     tp = "U";   break;
    case CV_16SC4:  bd = 16;    ch = 4;     tp = "S";   break;
    case CV_32SC4:  bd = 32;    ch = 4;     tp = "S";   break;
    case CV_32FC4:  bd = 32;    ch = 4;     tp = "F";   break;
    case CV_64FC4:  bd = 64;    ch = 4;     tp = "F";   break;
    default:
        break;
    }

    //stack?
    if(VD_Dim.size_S() > 1)
    {
        QS_type.append("Stack of ");
        if(more_detail)
            QS_type.append(QString::number(VD_Dim.size_S()) + " ");
    }

    //Space
    int dim = 0;
    if(VD_Dim.size_X() > 1)  dim++;
    if(VD_Dim.size_Y() > 1)  dim++;
    if(VD_Dim.size_Z() > 1)  dim++;
    if(more_detail)
    {
        QS_type.append(QString::number(VD_Dim.size_X()) + "x" + QString::number(VD_Dim.size_Y()));
        if(VD_Dim.size_Z() > 1 || VD_Dim.size_T() > 1)
            QS_type.append("x" + QString::number(VD_Dim.size_Z()));
        if(VD_Dim.size_T() > 1)
            QS_type.append("x" + QString::number(VD_Dim.size_T()));
    }
    QS_type.append(" " + QString::number(dim) + "D-");

    //Time
    if(VD_Dim.size_T() > 1)
        QS_type.append("Video");
    else
        QS_type.append("Image");
    if(VD_Dim.size_S() > 1)
        QS_type.append("s");

    //Bit
    if(more_detail)
        QS_type.append(" in " + QString::number(bd) + "bit");

    //pages & channels
    if(more_detail)
    {
        QS_type.append(" with " + QString::number(VD_Dim.size_P()) + " pages");
        QS_type.append(" and " + QString::number(ch) + " channels.");
    }

    return QS_type;
}

void D_VisDat_Obj::Init(double val)
{
    //Dim in Mat needed format
    int dim_size[] =
    {
        VD_Dim.size_X(),
        VD_Dim.size_Y(),
        VD_Dim.size_Z(),
        VD_Dim.size_T(),
        VD_Dim.size_S(),
        VD_Dim.size_P()
    };

    //remove eventually old content
    MA_Data.release();

    //get init value
    Scalar init_scalar(val);
    switch (MA_Type) {

    case CV_8UC1:
    case CV_8SC1:
    case CV_16UC1:
    case CV_16SC1:
    case CV_32SC1:
    case CV_32FC1:
    case CV_64FC1:
        init_scalar = Scalar(val);
        break;

    case CV_8UC2:
    case CV_8SC2:
    case CV_16UC2:
    case CV_16SC2:
    case CV_32SC2:
    case CV_32FC2:
    case CV_64FC2:
        init_scalar = Scalar(val, val);
        break;

    case CV_8UC3:
    case CV_8SC3:
    case CV_16UC3:
    case CV_16SC3:
    case CV_32SC3:
    case CV_32FC3:
    case CV_64FC3:
        init_scalar = Scalar(val, val, val);
        break;

    case CV_8UC4:
    case CV_8SC4:
    case CV_16UC4:
    case CV_16SC4:
    case CV_32SC4:
    case CV_32FC4:
    case CV_64FC4:
        init_scalar = Scalar(val, val, val, val);
        break;

    default:
        break;
    }

    //create new Mat of fitting size
    MA_Data = Mat(
                c_DIM_NUMBER_OF,        //Number of Dimensions
                dim_size,               //Sizes in Dimensions
                MA_Type,                //Contained DataType
                init_scalar);
}
