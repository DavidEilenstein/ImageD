/************************************
 *   added:     11.09.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_img_proc.h"

D_Img_Proc::D_Img_Proc()
{

}

int D_Img_Proc::Load_From_Path(Mat *pMA_Out, QFileInfo FI_path)
{
    if(!FI_path.exists())
        return ER_file_not_exist;

    QString suf = FI_path.suffix();
    if(suf == "asc" || suf == "ASC")
    {
        return Load_From_Path_Text(
                    pMA_Out,
                    FI_path.absoluteFilePath().toStdString());
    }
    else
    {
        *pMA_Out = imread(
                    FI_path.absoluteFilePath().toStdString(),
                    cv::IMREAD_ANYDEPTH|cv::IMREAD_ANYCOLOR);
        return ER_okay;
    }
}

int D_Img_Proc::Load_From_Path(Mat *pMA_Out, QString path)
{
    return Load_From_Path(
                pMA_Out,
                QFileInfo(path));
}

int D_Img_Proc::Load_From_Path(Mat *pMA_Out, string path)
{
    return Load_From_Path(
                pMA_Out,
                QFileInfo(QString::fromStdString(path)));
}

int D_Img_Proc::Load_From_Path_Gray(Mat *pMA_Out, QFileInfo FI_path)
{
    if(!FI_path.exists())
        return ER_file_not_exist;

    QString suf = FI_path.suffix();
    if(suf == "asc" || suf == "ASC")
    {
        return Load_From_Path_Text(
                    pMA_Out,
                    FI_path.absoluteFilePath().toStdString());
    }
    else
    {
        *pMA_Out = imread(
                    FI_path.absoluteFilePath().toStdString(),
                    cv::IMREAD_ANYDEPTH|cv::IMREAD_GRAYSCALE);
        return ER_okay;
    }
}

int D_Img_Proc::Load_From_Path_Gray(Mat *pMA_Out, QString path)
{
    return Load_From_Path_Gray(
                pMA_Out,
                QFileInfo(path));
}

int D_Img_Proc::Load_From_Path_Gray(Mat *pMA_Out, string path)
{
    return Load_From_Path_Gray(
                pMA_Out,
                QFileInfo(QString::fromStdString(path)));
}

int D_Img_Proc::Load_From_Path_Text(Mat *pMA_Out, string path)
{
    //Variables
    ifstream        IS_File;
    string          ST_Line;
    stringstream    SS_Line;
    unsigned int    rows        = 0;
    unsigned int    cols        = 0;
    unsigned int    y           = 0;
    unsigned int    x           = 0;
    float           F_Value;

    //Get Size
    IS_File.open(path);
    while(getline(IS_File, ST_Line))
    {
        if(cols == 0)
        {
            SS_Line << ST_Line;
            while(SS_Line >> F_Value)
                cols++;
        }

        rows++;
    }
    IS_File.close();

    //Create Image
    *pMA_Out = Mat(rows, cols, CV_32FC1);

    //Get Data
    IS_File.open(path);
    while(getline(IS_File, ST_Line))
    {
        SS_Line.clear();
        SS_Line << ST_Line;
        x = 0;

        while(SS_Line >> F_Value)
        {
            pMA_Out->at<float>(y, x) = F_Value;
            x++;
        }

        y++;
    }
    IS_File.close();

    return ER_okay;
}

int D_Img_Proc::Load_From_Path_Raw(Mat *pMA_Out, string path, int width, int height, int out_type)
{
    //Buffer img
    Mat MA_tmp = Mat(height, width, out_type);
    int pixel_count = width * height;

    //error checks
    if(pMA_Out->channels() != 1)                            return ER_channel_bad;
    if(!QFileInfo(QString::fromStdString(path)).exists())   return ER_file_not_exist;

    //input file
    FILE *p_file = fopen(path.c_str(), "rb");;

    //Supported Types
    switch (out_type) {

    case CV_8UC1:
    {
        uchar *p_buffer = (uchar*) malloc (sizeof(uchar) * pixel_count);    //allocate memory for buffer
        fread(p_buffer, sizeof(uchar), pixel_count, p_file);                //read file from file to buffer
        memcpy(MA_tmp.data, p_buffer, pixel_count);                         //copy data from buffer to mat
        free(p_buffer);                                                     //free buffer
        cvtColor(MA_tmp, *pMA_Out, CV_BayerBG2GRAY);                        //convert
    }
        break;

    case CV_8SC1:
    {
        char *p_buffer = (char*) malloc (sizeof(char) * pixel_count);       //allocate memory for buffer
        fread(p_buffer, sizeof(char), pixel_count, p_file);                 //read file from file to buffer
        memcpy(MA_tmp.data, p_buffer, pixel_count);                         //copy data from buffer to mat
        free(p_buffer);                                                     //free buffer
        *pMA_Out = MA_tmp.clone();                                          //clone (convert not supported)
        //cvtColor(MA_tmp, *pMA_Out, CV_BayerBG2GRAY);                      //convert
    }
        break;

    case CV_16UC1:
    {
        ushort *p_buffer = (ushort*) malloc (sizeof(ushort) * pixel_count); //allocate memory for buffer
        fread(p_buffer, sizeof(ushort), pixel_count, p_file);               //read file from file to buffer
        memcpy(MA_tmp.data, p_buffer, pixel_count);                         //copy data from buffer to mat
        free(p_buffer);                                                     //free buffer
        cvtColor(MA_tmp, *pMA_Out, CV_BayerBG2GRAY);                        //convert
    }
        break;

    case CV_16SC1:
    {
        short *p_buffer = (short*) malloc (sizeof(short) * pixel_count);    //allocate memory for buffer
        fread(p_buffer, sizeof(short), pixel_count, p_file);                //read file from file to buffer
        memcpy(MA_tmp.data, p_buffer, pixel_count);                         //copy data from buffer to mat
        free(p_buffer);                                                     //free buffer
        *pMA_Out = MA_tmp.clone();                                          //clone (convert not supported)
        //cvtColor(MA_tmp, *pMA_Out, CV_BayerBG2GRAY);                      //convert
    }
        break;

    case CV_32SC1:
    {
        int *p_buffer = (int*) malloc (sizeof(int) * pixel_count);          //allocate memory for buffer
        fread(p_buffer, sizeof(int), pixel_count, p_file);                  //read file from file to buffer
        memcpy(MA_tmp.data, p_buffer, pixel_count);                         //copy data from buffer to mat
        free(p_buffer);                                                     //free buffer
        *pMA_Out = MA_tmp.clone();                                          //clone (convert not supported)
        //cvtColor(MA_tmp, *pMA_Out, CV_BayerBG2GRAY);                      //convert
    }
        break;

    default:
        return ER_type_bad;
    }

    fclose(p_file);

    return ER_okay;

    /*
    //Input File Stream
    ifstream IS_File(path, ios::binary);

    //Output Mat (init with 0)
    *pMA_Out = Mat::zeros(width, height, CV_16U);

    vector<uchar> v_buffer(istreambuf_iterator<char>(IS_File), {});

    ushort* ptr_out = reinterpret_cast<ushort*>(pMA_Out->data);


    for(int px = 0; px < (width * height) && px < v_buffer.size(); px++, ptr_out++)
    {
        ushort  buf_bit1    = v_buffer[2 * px    ];
        ushort  buf_bit2    = v_buffer[2 * px + 1];
        ushort  val         = buf_bit1 | (buf_bit2 >> 8);
        *ptr_out = val;
    }





    //buffer -> img
    switch (out_type) {

    case CV_8UC1:
    {
        vector<uchar> v_buffer(istreambuf_iterator<char>(IS_File), {});
        uchar* ptr_out = reinterpret_cast<uchar*>(pMA_Out->data);
        for(int px = 0; px < (width * height) && px < v_buffer.size(); px++, ptr_out++)
            *ptr_out = v_buffer[px];
    }
        break;

    case CV_8SC1:
    {
        vector<char> v_buffer(istreambuf_iterator<char>(IS_File), {});
        char* ptr_out = reinterpret_cast<char*>(pMA_Out->data);
        for(int px = 0; px < (width * height) && px < v_buffer.size(); px++, ptr_out++)
            *ptr_out = v_buffer[px];
    }
        break;

    case CV_16UC1:
    {
        vector<ushort> v_buffer(istreambuf_iterator<short>(IS_File), {});
        ushort* ptr_out = reinterpret_cast<ushort*>(pMA_Out->data);
        for(int px = 0; px < (width * height) && px < v_buffer.size(); px++, ptr_out++)
            *ptr_out = v_buffer[px];
    }
        break;

    case CV_16SC1:
    {
        vector<short> v_buffer(istreambuf_iterator<short>(IS_File), {});
        short* ptr_out = reinterpret_cast<short*>(pMA_Out->data);
        for(int px = 0; px < (width * height) && px < v_buffer.size(); px++, ptr_out++)
            *ptr_out = v_buffer[px];
    }
        break;

    case CV_32SC1:
    {
        vector<int> v_buffer(istreambuf_iterator<int>(IS_File), {});
        int* ptr_out = reinterpret_cast<int*>(pMA_Out->data);
        for(int px = 0; px < (width * height) && px < v_buffer.size(); px++, ptr_out++)
            *ptr_out = v_buffer[px];
    }
        break;

    case CV_32FC1:
    {
        vector<float> v_buffer(istreambuf_iterator<float>(IS_File), {});
        float* ptr_out = reinterpret_cast<float*>(pMA_Out->data);
        for(int px = 0; px < (width * height) && px < v_buffer.size(); px++, ptr_out++)
            *ptr_out = v_buffer[px];
    }
        break;

    case CV_64FC1:
    {
        vector<double> v_buffer(istreambuf_iterator<double>(IS_File), {});
        double* ptr_out = reinterpret_cast<double*>(pMA_Out->data);
        for(int px = 0; px < (width * height) && px < v_buffer.size(); px++, ptr_out++)
            *ptr_out = v_buffer[px];
    }
        break;

    default:
        return ER_type_bad;
    }



    //finish
    IS_File.close();
    */
}

int D_Img_Proc::Load_From_Path_Multi(Mat *pMA_Out, QString path, unsigned int page)
{
    vector<Mat> vMA_Load;
    imreadmulti(
                path.toStdString(),
                vMA_Load,
                cv::IMREAD_ANYDEPTH|cv::IMREAD_ANYCOLOR);

    //qDebug() << "Load_From_Path_Multi - try load" << page << "of" << vMA_Load.size();
    if(page > vMA_Load.size())
        return ER_index_out_of_range;

    *pMA_Out = vMA_Load[page - 1];

    return ER_okay;
}

int D_Img_Proc::Generate_byValueFunction(Mat *pMA_Out, int width, int height, function<double (double, double)> value_function)
{
    if(width < 1)       return ER_parameter_bad;
    if(height < 1)      return ER_parameter_bad;

    *pMA_Out = Mat::zeros(height, width, CV_64FC1);

    for(int y = 0; y < height; y++)
        for(int x = 0; x < width; x++)
            pMA_Out->at<double>(y, x) = value_function(x, y);

    return ER_okay;
}

int D_Img_Proc::Generate_byValueFunction_Complex(Mat *pMA_Out, int width, int height, function<complex<double> (complex<double> x, complex<double> y)> value_function)
{
    if(width < 1)       return ER_parameter_bad;
    if(height < 1)      return ER_parameter_bad;

    *pMA_Out = Mat::zeros(height, width, CV_64FC2);

    for(int y = 0; y < height; y++)
        for(int x = 0; x < width; x++)
        {
            complex<double> val = value_function(x, y);
            pMA_Out->at<Vec2d>(y, x) = Vec2d(val.real(), val.imag());
        }

    return ER_okay;
}

QString D_Img_Proc::Type_of_Mat(Mat *pMA_In)
{
    if(pMA_In->empty())     return "Empty";

    switch (pMA_In->type()) {
    case CV_8UC1:   return "CV_8UC1";   break;
    case CV_8UC2:   return "CV_8UC2";   break;
    case CV_8UC3:   return "CV_8UC3";   break;
    case CV_8UC4:   return "CV_8UC4";   break;
    case CV_8SC1:   return "CV_8SC1";   break;
    case CV_8SC2:   return "CV_8SC2";   break;
    case CV_8SC3:   return "CV_8SC3";   break;
    case CV_8SC4:   return "CV_8SC4";   break;
    case CV_16UC1:  return "CV_16UC1";  break;
    case CV_16UC2:  return "CV_16UC2";  break;
    case CV_16UC3:  return "CV_16UC3";  break;
    case CV_16UC4:  return "CV_16UC4";  break;
    case CV_16SC1:  return "CV_16SC1";  break;
    case CV_16SC2:  return "CV_16SC2";  break;
    case CV_16SC3:  return "CV_16SC3";  break;
    case CV_16SC4:  return "CV_16SC4";  break;
    case CV_32SC1:  return "CV_32SC1";  break;
    case CV_32SC2:  return "CV_32SC2";  break;
    case CV_32SC3:  return "CV_32SC3";  break;
    case CV_32SC4:  return "CV_32SC4";  break;
    case CV_32FC1:  return "CV_32FC1";  break;
    case CV_32FC2:  return "CV_32FC2";  break;
    case CV_32FC3:  return "CV_32FC3";  break;
    case CV_32FC4:  return "CV_32FC4";  break;
    case CV_64FC1:  return "CV_64FC1";  break;
    case CV_64FC2:  return "CV_64FC2";  break;
    case CV_64FC3:  return "CV_64FC3";  break;
    case CV_64FC4:  return "CV_64FC4";  break;
    default:        return "Unknown";   break;
    }
}

QString D_Img_Proc::Type_of_Mat(int channels, int depth)
{
    switch (channels) {

    case 1:
    {
        switch (depth) {
        case CV_8U:     return "CV_8UC1";
        case CV_8S:     return "CV_8SC1";
        case CV_16U:    return "CV_16UC1";
        case CV_16S:    return "CV_16SC1";
        case CV_32S:    return "CV_32SC1";
        case CV_32F:    return "CV_32FC1";
        case CV_64F:    return "CV_64FC1";
        default:        return "Depth Error (1 channels)";}
    }
        break;

    case 2:
    {
        switch (depth) {
        case CV_8U:     return "CV_8UC2";
        case CV_8S:     return "CV_8SC2";
        case CV_16U:    return "CV_16UC2";
        case CV_16S:    return "CV_16SC2";
        case CV_32S:    return "CV_32SC2";
        case CV_32F:    return "CV_32FC2";
        case CV_64F:    return "CV_64FC2";
        default:        return "Depth Error (2 channels)";}
    }
        break;

    case 3:
    {
        switch (depth) {
        case CV_8U:     return "CV_8UC3";
        case CV_8S:     return "CV_8SC3";
        case CV_16U:    return "CV_16UC3";
        case CV_16S:    return "CV_16SC3";
        case CV_32S:    return "CV_32SC3";
        case CV_32F:    return "CV_32FC3";
        case CV_64F:    return "CV_64FC3";
        default:        return "Depth Error (3 channels)";}
    }
        break;

    case 4:
    {
        switch (depth) {
        case CV_8U:     return "CV_8UC4";
        case CV_8S:     return "CV_8SC4";
        case CV_16U:    return "CV_16UC4";
        case CV_16S:    return "CV_16SC4";
        case CV_32S:    return "CV_32SC4";
        case CV_32F:    return "CV_32FC4";
        case CV_64F:    return "CV_64FC4";
        default:        return "Depth Error (4 channels)";}
    }
        break;

    default:
        return "Channel Error";
    }
}

QString D_Img_Proc::Type_of_QImage(QImage *pQI_In)
{     
    switch (pQI_In->format()) {
    case QImage::Format_Invalid:                return "Invalid";           break;
    case QImage::Format_Mono:                   return "Mono";              break;
    case QImage::Format_MonoLSB:                return "MonoLSB";           break;
    case QImage::Format_Indexed8:               return "Indexed8";          break;
    case QImage::Format_ARGB32:                 return "ARGB32";            break;
    case QImage::Format_ARGB32_Premultiplied:   return "ARGB32_Prem.";      break;
    case QImage::Format_RGB16:                  return "RGB16";             break;
    case QImage::Format_ARGB8565_Premultiplied: return "ARGB8565_Prem.";    break;
    case QImage::Format_RGB666:                 return "RGB666";            break;
    case QImage::Format_ARGB6666_Premultiplied: return "ARGB6666_Prem.";    break;
    case QImage::Format_RGB555:                 return "RGB555";            break;
    case QImage::Format_ARGB8555_Premultiplied: return "ARGB8555_Prem.";    break;
    case QImage::Format_RGB888:                 return "RGB888";            break;
    case QImage::Format_RGB444:                 return "RGB444";            break;
    case QImage::Format_ARGB4444_Premultiplied: return "ARGB4444_Prem.";    break;
    case QImage::Format_RGBX8888:               return "RGBX8888";          break;
    case QImage::Format_RGBA8888:               return "RGBA8888";          break;
    case QImage::Format_RGBA8888_Premultiplied: return "RGBA8888_Prem.";    break;
    case QImage::Format_BGR30:                  return "BGR30";             break;
    case QImage::Format_A2BGR30_Premultiplied:  return "A2BGR30_Prem.";     break;
    case QImage::Format_RGB30:                  return "RGB30";             break;
    case QImage::Format_A2RGB30_Premultiplied:  return "A2RGB30_Prem.";     break;
    case QImage::Format_Alpha8:                 return "Alpha8";            break;
    case QImage::Format_Grayscale8:             return "Grayscale8";        break;
    default:                                    return "Unknown";           break;
    }
}

int D_Img_Proc::TypeIndex_of_Mat(int channels, int depth)
{
    switch (channels) {

    case 1:
    {
        switch (depth) {
        case CV_8U:     return CV_8UC1;
        case CV_8S:     return CV_8SC1;
        case CV_16U:    return CV_16UC1;
        case CV_16S:    return CV_16SC1;
        case CV_32S:    return CV_32SC1;
        case CV_32F:    return CV_32FC1;
        case CV_64F:    return CV_64FC1;
        default:        return CV_8UC1;}
    }
        break;

    case 2:
    {
        switch (depth) {
        case CV_8U:     return CV_8UC2;
        case CV_8S:     return CV_8SC2;
        case CV_16U:    return CV_16UC2;
        case CV_16S:    return CV_16SC2;
        case CV_32S:    return CV_32SC2;
        case CV_32F:    return CV_32FC2;
        case CV_64F:    return CV_64FC2;
        default:        return CV_8UC2;}
    }
        break;

    case 3:
    {
        switch (depth) {
        case CV_8U:     return CV_8UC3;
        case CV_8S:     return CV_8SC3;
        case CV_16U:    return CV_16UC3;
        case CV_16S:    return CV_16SC3;
        case CV_32S:    return CV_32SC3;
        case CV_32F:    return CV_32FC3;
        case CV_64F:    return CV_64FC3;
        default:        return CV_8UC3;}
    }
        break;

    case 4:
    {
        switch (depth) {
        case CV_8U:     return CV_8UC4;
        case CV_8S:     return CV_8SC4;
        case CV_16U:    return CV_16UC4;
        case CV_16S:    return CV_16SC4;
        case CV_32S:    return CV_32SC4;
        case CV_32F:    return CV_32FC4;
        case CV_64F:    return CV_64FC4;
        default:        return CV_8UC4;}
    }
        break;

    default:
        return CV_8UC1;
    }
}

int D_Img_Proc::Channels_of_MatType(int type)
{
    switch (type) {

    case CV_8UC1:
    case CV_8SC1:
    case CV_16UC1:
    case CV_16SC1:
    case CV_32SC1:
    case CV_32FC1:
    case CV_64FC1:
        return 1;

    case CV_8UC2:
    case CV_8SC2:
    case CV_16UC2:
    case CV_16SC2:
    case CV_32SC2:
    case CV_32FC2:
    case CV_64FC2:
        return 2;

    case CV_8UC3:
    case CV_8SC3:
    case CV_16UC3:
    case CV_16SC3:
    case CV_32SC3:
    case CV_32FC3:
    case CV_64FC3:
        return 3;

    case CV_8UC4:
    case CV_8SC4:
    case CV_16UC4:
    case CV_16SC4:
    case CV_32SC4:
    case CV_32FC4:
    case CV_64FC4:
        return 4;

    default:
        return 0;
    }
}

Scalar D_Img_Proc::Scalar_EqualInAllChannels(int channels, double value)
{
    switch (channels) {
    case 1: return Scalar(value);
    case 2: return Scalar(value, value);
    case 3: return Scalar(value, value, value);
    case 4: return Scalar(value, value, value, value);
    default: return Scalar(0);}
}

int D_Img_Proc::Stat_ofPixelvalues(double *value, Mat *pMA_In, int stat, bool ignore_zeros)
{
    if(pMA_In->channels() != 1)         return ER_channel_bad;

    //area
    size_t area = pMA_In->rows * pMA_In->cols;
    //qDebug() << "area:" << area;

    //read values
    vector<double> vValues;

    //type switch
    //qDebug() << "Type switch:" << Type_of_Mat(pMA_In);
    switch (pMA_In->type()) {

    case CV_8UC1:
    {
        uchar* ptr_in = reinterpret_cast<uchar*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
            if(*ptr_in != 0 || !ignore_zeros)
                vValues.push_back(static_cast<double>(*ptr_in));
    }
        break;

    case CV_8SC1:
    {
        char* ptr_in = reinterpret_cast<char*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
            if(*ptr_in != 0 || !ignore_zeros)
                vValues.push_back(static_cast<double>(*ptr_in));
    }
        break;

    case CV_16UC1:
    {
        ushort* ptr_in = reinterpret_cast<ushort*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
            if(*ptr_in != 0 || !ignore_zeros)
                vValues.push_back(static_cast<double>(*ptr_in));
    }
        break;

    case CV_16SC1:
    {
        short* ptr_in = reinterpret_cast<short*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
            if(*ptr_in != 0 || !ignore_zeros)
                vValues.push_back(static_cast<double>(*ptr_in));
    }
        break;

    case CV_32SC1:
    {
        int* ptr_in = reinterpret_cast<int*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
            if(*ptr_in != 0 || !ignore_zeros)
                vValues.push_back(static_cast<double>(*ptr_in));
    }
        break;

    case CV_32FC1:
    {
        float* ptr_in = reinterpret_cast<float*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
            if(*ptr_in != 0 || !ignore_zeros)
                vValues.push_back(static_cast<double>(*ptr_in));
    }
        break;

    case CV_64FC1:
    {
        double* ptr_in = reinterpret_cast<double*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
            if(*ptr_in != 0 || !ignore_zeros)
                vValues.push_back(static_cast<double>(*ptr_in));
    }
        break;

    default:
        return ER_type_bad;
    }

    //calc stat
    function<double (vector<double>)> F_stat = D_Stat::Function_SingleStat(stat);
    *value = F_stat(vValues);

    return ER_okay;
}

int D_Img_Proc::Quantiles_ofPixelvalues(double *q_low, double *q_high, Mat *pMA_In, double low_rel, double high_rel, bool ignore_zeros)
{
    if(pMA_In->channels() != 1 && pMA_In->channels() != 3)      return ER_channel_bad;
    if(low_rel  < 0 || low_rel  > 1)                            return ER_parameter_bad;
    if(high_rel < 0 || high_rel > 1)                            return ER_parameter_bad;
    if(low_rel >= high_rel)                                     return ER_parameter_missmatch;

    //area
    size_t area = pMA_In->rows * pMA_In->cols;
    //qDebug() << "area:" << area;

    //read values
    vector<double> vValues;

    //type switch
    //qDebug() << "Type switch:" << Type_of_Mat(pMA_In);
    switch (pMA_In->type()) {

    case CV_8UC1:
    {
        uchar* ptr_in = reinterpret_cast<uchar*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
            if(*ptr_in != 0 || !ignore_zeros)
                vValues.push_back(static_cast<double>(*ptr_in));
    }
        break;

    case CV_8SC1:
    {
        char* ptr_in = reinterpret_cast<char*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
            if(*ptr_in != 0 || !ignore_zeros)
                vValues.push_back(static_cast<double>(*ptr_in));
    }
        break;

    case CV_16UC1:
    {
        ushort* ptr_in = reinterpret_cast<ushort*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
            if(*ptr_in != 0 || !ignore_zeros)
                vValues.push_back(static_cast<double>(*ptr_in));
    }
        break;

    case CV_16SC1:
    {
        short* ptr_in = reinterpret_cast<short*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
            if(*ptr_in != 0 || !ignore_zeros)
                vValues.push_back(static_cast<double>(*ptr_in));
    }
        break;

    case CV_32SC1:
    {
        int* ptr_in = reinterpret_cast<int*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
            if(*ptr_in != 0 || !ignore_zeros)
                vValues.push_back(static_cast<double>(*ptr_in));
    }
        break;

    case CV_32FC1:
    {
        float* ptr_in = reinterpret_cast<float*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
            if(*ptr_in != 0 || !ignore_zeros)
                vValues.push_back(static_cast<double>(*ptr_in));
    }
        break;

    case CV_64FC1:
    {
        double* ptr_in = reinterpret_cast<double*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
            if(*ptr_in != 0 || !ignore_zeros)
                vValues.push_back(static_cast<double>(*ptr_in));
    }
        break;

    case CV_8UC3:
    {
        Vec3b* ptr_in = reinterpret_cast<Vec3b*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
        {
            for(int c = 0; c < pMA_In->channels(); c++)
            {
                double val = (*ptr_in)[c];
                if(val != 0 || !ignore_zeros)
                    vValues.push_back(val);
            }
        }
    }
        break;

    case CV_16UC3:
    {
        Vec3w* ptr_in = reinterpret_cast<Vec3w*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
        {
            for(int c = 0; c < pMA_In->channels(); c++)
            {
                double val = (*ptr_in)[c];
                if(val != 0 || !ignore_zeros)
                    vValues.push_back(val);
            }
        }
    }
        break;

    case CV_16SC3:
    {
        Vec3s* ptr_in = reinterpret_cast<Vec3s*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
        {
            for(int c = 0; c < pMA_In->channels(); c++)
            {
                double val = (*ptr_in)[c];
                if(val != 0 || !ignore_zeros)
                    vValues.push_back(val);
            }
        }
    }
        break;

    case CV_32SC3:
    {
        Vec3i* ptr_in = reinterpret_cast<Vec3i*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
        {
            for(int c = 0; c < pMA_In->channels(); c++)
            {
                double val = (*ptr_in)[c];
                if(val != 0 || !ignore_zeros)
                    vValues.push_back(val);
            }
        }
    }
        break;

    case CV_32FC3:
    {
        Vec3f* ptr_in = reinterpret_cast<Vec3f*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
        {
            for(int c = 0; c < pMA_In->channels(); c++)
            {
                double val = (*ptr_in)[c];
                if(val != 0 || !ignore_zeros)
                    vValues.push_back(val);
            }
        }
    }
        break;

    case CV_64FC3:
    {
        Vec3d* ptr_in = reinterpret_cast<Vec3d*>(pMA_In->data);
        for(size_t px = 0; px < area; px++, ptr_in++)
        {
            for(int c = 0; c < pMA_In->channels(); c++)
            {
                double val = (*ptr_in)[c];
                if(val != 0 || !ignore_zeros)
                    vValues.push_back(val);
            }
        }
    }
        break;

    default:
        return ER_type_bad;
    }

    //calc quantiles
    //qDebug() << "sort";
    sort(vValues.begin(), vValues.end());
    if(vValues.size() > 0)
    {
        //qDebug() << "get quantiles";
        size_t i_low  = static_cast<size_t>(low_rel   * (vValues.size() - 1));
        size_t i_high = static_cast<size_t>(high_rel  * (vValues.size() - 1));
        //qDebug() << "size, low, high" << vValues.size() << i_low << i_high;
        *q_low  = vValues[i_low];
        *q_high = vValues[i_high];
        //qDebug() << "got quantiles" << *q_low << *q_high;
    }
    else
    {
        //qDebug() << "set to default values";
        *q_low = 0.0;
        *q_high = 0.0;
    }

    return ER_okay;
}


int D_Img_Proc::Convert_Mat_to_QImage(QImage *pQI_Out, Mat *pMA_In)
{
    if(pMA_In->empty())     return ER_empty;

    //Error handler
    int ER;

    /*
    //get output QI_format
    QImage::Format  QI_format;
    switch (pMA_In->channels()) {
    case 1:         QI_format = QImage::Format_Grayscale8;      break;
    //case 2:         QI_format = QImage::Format_RGB888;          break;
    case 3:         QI_format = QImage::Format_RGB888;          break;
    case 4:         QI_format = QImage::Format_RGBA8888;        break;
    default:                                                    return ER_channel_bad;}

    //allocate output QI
    *pQI_Out = QImage(
                pMA_In->cols,
                pMA_In->rows,
                QI_format);
*/

    //Normalize to 8bit / copy
    Mat MA_tmp_8bit;
    if(pMA_In->depth() == CV_8U)
    {
        ER = Duplicate(
                    &MA_tmp_8bit,
                    pMA_In);
        if(ER != ER_okay)   return ER;
    }
    else
    {
        ER = Normalize(
                    &MA_tmp_8bit,
                    pMA_In,
                    CV_MINMAX,
                    CV_8U,
                    0,
                    255);
        if(ER != ER_okay)   return ER;
    }

    //conversion
    switch (MA_tmp_8bit.channels()) {

    case 1://=======================================================================================
    {
        *pQI_Out = QImage(
                    MA_tmp_8bit.data,
                    MA_tmp_8bit.cols,
                    MA_tmp_8bit.rows,
                    static_cast<int>(MA_tmp_8bit.step),
                    QImage::Format_Grayscale8).copy();
    }
        break;

    case 2://=======================================================================================
    {
        *pQI_Out = QImage(pMA_In->cols, pMA_In->rows, QImage::Format_RGB888);
        for(int y = 0; y < MA_tmp_8bit.rows; y++)
            for(int x = 0; x < MA_tmp_8bit.cols; x++)
            {
                Vec2b px = MA_tmp_8bit.at<Vec2b>(y, x);

                pQI_Out->setPixel(
                            x,
                            y,
                            qRgb(
                                0,
                                px[1],
                                px[0])
                            );
            }
    }
        break;

    case 3://=======================================================================================
    {
        *pQI_Out = QImage(
                    MA_tmp_8bit.data,
                    MA_tmp_8bit.cols,
                    MA_tmp_8bit.rows,
                    static_cast<int>(MA_tmp_8bit.step),
                    QImage::Format_RGB888).rgbSwapped();
    }
        break;

    case 4://=======================================================================================
    {
        *pQI_Out = QImage(
                    MA_tmp_8bit.data,
                    MA_tmp_8bit.cols,
                    MA_tmp_8bit.rows,
                    static_cast<int>(MA_tmp_8bit.step),
                    QImage::Format_RGBA8888).rgbSwapped();
    }
        break;

    default:
        return ER_channel_bad;
    }

    MA_tmp_8bit.release();
    return ER_okay;
}

/*
int D_Img_Proc::Convert_Mat_to_QImage(QImage *pQI_Out, Mat *pMA_In)
{
    if(pMA_In->empty())     return ER_empty;

    //Error handler
    int ER;

    //get output QI_format
    QImage::Format  QI_format;
    switch (pMA_In->channels()) {
    case 1:         QI_format = QImage::Format_Grayscale8;      break;
    case 2:         QI_format = QImage::Format_RGB888;          break;
    case 3:         QI_format = QImage::Format_RGB888;          break;
    case 4:         QI_format = QImage::Format_RGBA8888;        break;
    default:                                                    return ER_channel_bad;}

    //allocate output QI
    *pQI_Out = QImage(
                pMA_In->cols,
                pMA_In->rows,
                QI_format);

    //Normalize to 8bit / copy
    Mat MA_tmp_8bit;
    if(pMA_In->depth() == CV_8U)
    {
        ER = Duplicate(
                    &MA_tmp_8bit,
                    pMA_In);
        if(ER != ER_okay)   return ER;
    }
    else
    {
        ER = Normalize(
                    &MA_tmp_8bit,
                    pMA_In,
                    CV_MINMAX,
                    CV_8UC1,
                    0,
                    255);
        if(ER != ER_okay)   return ER;
    }

    //conversion
    switch (pMA_In->channels()) {

    case 1://=======================================================================================
    {
        for(int y = 0; y < MA_tmp_8bit.rows; y++)
            for(int x = 0; x < MA_tmp_8bit.cols; x++)
                pQI_Out->setPixel(
                            x,
                            y,
                            pMA_In->at<uchar>(y, x));
    }
        break;

    case 2://=======================================================================================
    {
        for(int y = 0; y < MA_tmp_8bit.rows; y++)
            for(int x = 0; x < MA_tmp_8bit.cols; x++)
            {
                Vec2b px = pMA_In->at<Vec2b>(y, x);

                pQI_Out->setPixel(
                            x,
                            y,
                            qRgb(
                                px[2],
                                px[1],
                                0)
                            );
            }
    }
        break;

    case 3://=======================================================================================
    {
        for(int y = 0; y < MA_tmp_8bit.rows; y++)
            for(int x = 0; x < MA_tmp_8bit.cols; x++)
            {
                Vec3b px = pMA_In->at<Vec3b>(y, x);

                pQI_Out->setPixel(
                            x,
                            y,
                            qRgb(
                                px[2],
                                px[1],
                                px[0])
                            );
            }
    }
        break;

    case 4://=======================================================================================
    {
        for(int y = 0; y < MA_tmp_8bit.rows; y++)
            for(int x = 0; x < MA_tmp_8bit.cols; x++)
            {
                Vec4b px = pMA_In->at<Vec4b>(y, x);

                pQI_Out->setPixel(
                            x,
                            y,
                            qRgb(
                                px[2],
                                px[1],
                                px[0])
                            );
            }
    }
        break;

    default:
        return ER_channel_bad;
    }


}
*/

/*
int D_Img_Proc::Convert_Mat_to_QImage(QImage *pQI_Out, Mat *pMA_In)
{
    if(pMA_In->empty())     return ER_empty;

    //check, if empty
    if(pMA_In->empty())
        return ER_empty;

    //type defines conversion method
    switch (pMA_In->type()) {

    case CV_8UC1://--------------------------------------------
        *pQI_Out = QImage(
                    static_cast<uchar*>(pMA_In->data),
                    pMA_In->cols,
                    pMA_In->rows,
                    static_cast<int>(pMA_In->step),
                    QImage::Format_Grayscale8);
        break;

    case CV_8UC3://--------------------------------------------
        *pQI_Out = QImage(
                    static_cast<uchar*>(pMA_In->data),
                    pMA_In->cols,
                    pMA_In->rows,
                    static_cast<int>(pMA_In->step),
                    QImage::Format_RGB888).rgbSwapped();
        break;

    case CV_8UC4://--------------------------------------------
        *pQI_Out = QImage(
                    static_cast<uchar*>(pMA_In->data),
                    pMA_In->cols,
                    pMA_In->rows,
                    static_cast<int>(pMA_In->step),
                    QImage::Format_RGBA8888).rgbSwapped();
        break;

    case CV_16UC1://--------------------------------------------
    case CV_32SC1:
    case CV_32FC1:
    case CV_64FC1:
    {
        Mat MA_Tmp;
        normalize(*pMA_In, MA_Tmp, 0, 255, NORM_MINMAX, CV_8UC1);
        *pQI_Out = QImage(
                    static_cast<uchar*>(MA_Tmp.data),
                    MA_Tmp.cols,
                    MA_Tmp.rows,
                    QImage::Format_Grayscale8).copy();
    }
        break;

    case CV_16UC3://--------------------------------------------
    case CV_32SC3:
    case CV_32FC3:
    case CV_64FC3:
    {
        Mat MA_Tmp;
        normalize(*pMA_In, MA_Tmp, 0, 255, NORM_MINMAX, CV_8UC3);
        *pQI_Out = QImage(
                    static_cast<uchar*>(MA_Tmp.data),
                    MA_Tmp.cols,
                    MA_Tmp.rows,
                    static_cast<int>(MA_Tmp.step),
                    QImage::Format_RGB888).rgbSwapped();
    }
        break;

    case CV_16UC4://--------------------------------------------
    case CV_32SC4:
    case CV_32FC4:
    case CV_64FC4:
    {
        Mat MA_Tmp;
        normalize(*pMA_In, MA_Tmp, 0, 255, NORM_MINMAX, CV_8UC3);
        *pQI_Out = QImage(
                    static_cast<uchar*>(MA_Tmp.data),
                    MA_Tmp.cols,
                    MA_Tmp.rows,
                    static_cast<int>(MA_Tmp.step),
                    QImage::Format_RGBA8888).rgbSwapped();
    }
        break;


    default:
        return ER_type_bad;
        break;
    }

    return ER_okay;
}
*/

int D_Img_Proc::Convert_QImage_to_Mat(Mat *pMA_Out, QImage *pQI_In)
{
    if(pQI_In->format() != QImage::Format_RGB888)   return ER_type_bad;

    *pMA_Out = Mat(
                pQI_In->height(),
                pQI_In->width(),
                CV_8UC3,
                pQI_In->data_ptr());

    imshow("qi2mat", *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::MinMax_of_Mat(Mat *pMA_In, double *min_ext, double *max_ext)
{
    if(pMA_In->empty()) return ER_empty;

    switch (pMA_In->channels()) {

    case 1:
    {
        int ER = MinMax_of_Mat_1C(
                    pMA_In,
                    min_ext,
                    max_ext);
        if(ER != ER_okay)   return ER;
    }
        break;

    case 2:
    {
        Mat MA_tmp_in[2];
        split(
                    *pMA_In,
                    MA_tmp_in);

        double min;
        double max;
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = MinMax_of_Mat_1C(
                        &(MA_tmp_in[c]),
                        &min,
                        &max);
            if(ER != ER_okay)   return ER;

            if(c == 0)
            {
                *min_ext = min;
                *max_ext = max;
            }
            else
            {
                if(min < *min_ext)  *min_ext = min;
                if(max > *max_ext)  *max_ext = max;
            }

        }

        for(int c = 0; c < pMA_In->channels(); c++)
            MA_tmp_in[c].release();
    }
        break;

    case 3:
    {
        Mat MA_tmp_in[3];
        split(
                    *pMA_In,
                    MA_tmp_in);

        double min;
        double max;
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = MinMax_of_Mat_1C(
                        &(MA_tmp_in[c]),
                        &min,
                        &max);
            if(ER != ER_okay)   return ER;

            if(c == 0)
            {
                *min_ext = min;
                *max_ext = max;
            }
            else
            {
                if(min < *min_ext)  *min_ext = min;
                if(max > *max_ext)  *max_ext = max;
            }

        }

        for(int c = 0; c < pMA_In->channels(); c++)
            MA_tmp_in[c].release();
    }
        break;

    case 4:
    {
        Mat MA_tmp_in[4];
        split(
                    *pMA_In,
                    MA_tmp_in);

        double min;
        double max;
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = MinMax_of_Mat_1C(
                        &(MA_tmp_in[c]),
                        &min,
                        &max);
            if(ER != ER_okay)   return ER;

            if(c == 0)
            {
                *min_ext = min;
                *max_ext = max;
            }
            else
            {
                if(min < *min_ext)  *min_ext = min;
                if(max > *max_ext)  *max_ext = max;
            }

        }

        for(int c = 0; c < pMA_In->channels(); c++)
            MA_tmp_in[c].release();
    }
        break;

    default:
        break;
    }

    return ER_okay;
}

int D_Img_Proc::MinMax_of_Mat_1C(Mat *pMA_In, double *min_ext, double *max_ext)
{
    if(pMA_In->empty())     return ER_empty;

    minMaxLoc(
                *pMA_In,
                min_ext,
                max_ext);

    return ER_okay;
}

int D_Img_Proc::ValAtPix(vector<double> *v_value, Mat *pMA_In, unsigned int x_pos, unsigned int y_pos)
{
    if(pMA_In->empty())                                             return ER_empty;
    if(((int)x_pos >= pMA_In->cols) || (int)y_pos >= pMA_In->rows)  return ER_index_out_of_range;

    v_value->clear();
    v_value->resize(pMA_In->channels(), 0.0);

    if(pMA_In->channels() == 1)
    {
        switch (pMA_In->type()) {
        case CV_8UC1:   (*v_value)[0] = pMA_In->at<uchar>(y_pos, x_pos);    break;
        case CV_16UC1:  (*v_value)[0] = pMA_In->at<ushort>(y_pos, x_pos);   break;
        case CV_32SC1:  (*v_value)[0] = pMA_In->at<int>(y_pos, x_pos);      break;
        case CV_32FC1:  (*v_value)[0] = pMA_In->at<float>(y_pos, x_pos);    break;
        case CV_64FC1:  (*v_value)[0] = pMA_In->at<double>(y_pos, x_pos);   break;
        default:        return ER_type_bad;                                 break;}
    }
    else
    {
        switch (pMA_In->type()) {

        case CV_8UC2:
        {
            Vec2b val = pMA_In->at<Vec2b>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_8UC3:
        {
            Vec3b val = pMA_In->at<Vec3b>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_8UC4:
        {
            Vec4b val = pMA_In->at<Vec4b>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_16UC2:
        {
            Vec2w val = pMA_In->at<Vec2w>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_16UC3:
        {
            Vec3w val = pMA_In->at<Vec3w>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_16UC4:
        {
            Vec4w val = pMA_In->at<Vec4w>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_16SC2:
        {
            Vec2s val = pMA_In->at<Vec2s>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_16SC3:
        {
            Vec3s val = pMA_In->at<Vec3s>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_16SC4:
        {
            Vec4s val = pMA_In->at<Vec4s>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_32SC2:
        {
            Vec2i val = pMA_In->at<Vec2i>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_32SC3:
        {
            Vec3i val = pMA_In->at<Vec3i>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_32SC4:
        {
            Vec4i val = pMA_In->at<Vec4i>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_32FC2:
        {
            Vec2f val = pMA_In->at<Vec2f>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_32FC3:
        {
            Vec3f val = pMA_In->at<Vec3f>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_32FC4:
        {
            Vec4f val = pMA_In->at<Vec4f>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_64FC2:
        {
            Vec2d val = pMA_In->at<Vec2d>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_64FC3:
        {
            Vec3d val = pMA_In->at<Vec3d>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        case CV_64FC4:
        {
            Vec4d val = pMA_In->at<Vec4d>(y_pos, x_pos);
            for(int c = 0; c < pMA_In->channels(); c++)
                (*v_value)[c] = val[c];
        }
            break;

        default:
            return ER_type_bad;
            break;
        }
    }




    return ER_okay;
}

int D_Img_Proc::ValAtPix(QString *QS_value, Mat *pMA_In, unsigned int x_pos, unsigned int y_pos)
{
    vector<double> v_value;

    int ER = ValAtPix(
                &v_value,
                pMA_In,
                x_pos,
                y_pos);

    if(ER != ER_okay)
    {
        (*QS_value) = "Error";
        return ER;
    }

    for(unsigned int c = 0; c < v_value.size(); c++)
    {
        if(c != 0)
            QS_value->append("/");
        QS_value->append(QString::number(v_value[c], 'g', 6));
    }

    return ER_okay;
}



int D_Img_Proc::Duplicate(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty())     return ER_empty;

    *pMA_Out = pMA_In->clone();
    return ER_okay;
}

int D_Img_Proc::Invert(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty())     return ER_empty;
    int ER;

    double min;
    double max;

    if(pMA_In->depth() == CV_8U)
    {
        max = 255;
    }
    else
    {
        ER = MinMax_of_Mat(
                    pMA_In,
                    &min,
                    &max);
        if(ER != ER_okay)
            return ER;
    }

    return Math_ScalImg_Sub(
                pMA_Out,
                pMA_In,
                max);
}

int D_Img_Proc::Convert_Color(Mat *pMA_Out, Mat *pMA_In, int cvt_mode)
{
    if(pMA_In->empty())
        return ER_empty;

    if((pMA_In->depth() != CV_8U))
        if((cvt_mode != CV_GRAY2BGR) && (cvt_mode != CV_BGR2GRAY) && (cvt_mode != CV_GRAY2RGB) && (cvt_mode != CV_RGB2GRAY))
            return ER_type_bad;

    if(pMA_In->channels() != 1 && pMA_In->channels() != 3)
        return ER_channel_bad;

    if(pMA_In->channels() == 1)
        if(cvt_mode != CV_GRAY2BGR && cvt_mode != CV_GRAY2RGB)
            return ER_channel_missmatch;

    if(pMA_In->channels() == 3)
        if(cvt_mode == CV_GRAY2BGR || cvt_mode == CV_GRAY2RGB)
            return ER_channel_missmatch;

    cvtColor(
                pMA_In->clone(),
                *pMA_Out,
                cvt_mode);

    return ER_okay;
}

int D_Img_Proc::Convert_Color_RGBA(Mat *pMA_Out, Mat *pMA_In, double r, double g, double b, double a, double range_rgba)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->channels() != 1)     return ER_channel_bad;
    if(r < 0 || r > 255)            return ER_parameter_bad;
    if(g < 0 || g > 255)            return ER_parameter_bad;
    if(b < 0 || b > 255)            return ER_parameter_bad;

    //scales
    double r_scale = (r * a) / (range_rgba * range_rgba);
    double g_scale = (g * a) / (range_rgba * range_rgba);
    double b_scale = (b * a) / (range_rgba * range_rgba);

    //size
    int area = pMA_In->rows * pMA_In->cols;

    //in img
    switch (pMA_In->type()) {

    case CV_8UC1:
    {
        *pMA_Out = Mat(pMA_In->size(), CV_8UC3);
        Vec3b* ptr_out = reinterpret_cast<Vec3b*>(pMA_Out->data);
        uchar* ptr_in = reinterpret_cast<uchar*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
        {
            (*ptr_out)[0] = static_cast<uchar>(*ptr_in * b_scale);
            (*ptr_out)[1] = static_cast<uchar>(*ptr_in * g_scale);
            (*ptr_out)[2] = static_cast<uchar>(*ptr_in * r_scale);
        }
    }
        break;

    case CV_16UC1:
    {
        *pMA_Out = Mat(pMA_In->size(), CV_16UC3);
        Vec3w* ptr_out = reinterpret_cast<Vec3w*>(pMA_Out->data);
        ushort* ptr_in = reinterpret_cast<ushort*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
        {
            (*ptr_out)[0] = static_cast<ushort>(*ptr_in * b_scale);
            (*ptr_out)[1] = static_cast<ushort>(*ptr_in * g_scale);
            (*ptr_out)[2] = static_cast<ushort>(*ptr_in * r_scale);
        }
    }
        break;

    case CV_16SC1:
    {
        *pMA_Out = Mat(pMA_In->size(), CV_16SC3);
        Vec3s* ptr_out = reinterpret_cast<Vec3s*>(pMA_Out->data);
        short* ptr_in = reinterpret_cast<short*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
        {
            (*ptr_out)[0] = static_cast<short>(*ptr_in * b_scale);
            (*ptr_out)[1] = static_cast<short>(*ptr_in * g_scale);
            (*ptr_out)[2] = static_cast<short>(*ptr_in * r_scale);
        }
    }
        break;

    case CV_32SC1:
    {
        *pMA_Out = Mat(pMA_In->size(), CV_32SC3);
        Vec3i* ptr_out = reinterpret_cast<Vec3i*>(pMA_Out->data);
        int* ptr_in = reinterpret_cast<int*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
        {
            (*ptr_out)[0] = static_cast<int>(*ptr_in * b_scale);
            (*ptr_out)[1] = static_cast<int>(*ptr_in * g_scale);
            (*ptr_out)[2] = static_cast<int>(*ptr_in * r_scale);
        }
    }
        break;

    case CV_32FC1:
    {
        *pMA_Out = Mat(pMA_In->size(), CV_32FC3);
        Vec3f* ptr_out = reinterpret_cast<Vec3f*>(pMA_Out->data);
        float* ptr_in = reinterpret_cast<float*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
        {
            (*ptr_out)[0] = static_cast<float>(*ptr_in * b_scale);
            (*ptr_out)[1] = static_cast<float>(*ptr_in * g_scale);
            (*ptr_out)[2] = static_cast<float>(*ptr_in * r_scale);
        }
    }
        break;

    case CV_64FC1:
    {
        *pMA_Out = Mat(pMA_In->size(), CV_64FC3);
        Vec3d* ptr_out = reinterpret_cast<Vec3d*>(pMA_Out->data);
        double* ptr_in = reinterpret_cast<double*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
        {
            (*ptr_out)[0] = static_cast<double>(*ptr_in * b_scale);
            (*ptr_out)[1] = static_cast<double>(*ptr_in * g_scale);
            (*ptr_out)[2] = static_cast<double>(*ptr_in * r_scale);
        }
    }
        break;

    default:
        return ER_bitdepth_bad;
    }

    return ER_okay;
}

int D_Img_Proc::Convert_Color2Mono(Mat *pMA_Out, Mat *pMA_In, int col2mono_code)
{
    if(pMA_In->empty())                         return ER_empty;
    if(pMA_In->channels() != 3)                 return ER_channel_bad;
    if(pMA_In->depth() != CV_8U)                return ER_bitdepth_bad;
    if(col2mono_code < 0)                       return ER_parameter_bad;
    if(col2mono_code >= c_COL2MONO_NUMBER_OF)   return ER_parameter_bad;
    int ER;

    Mat MA_tmp_transform;

    switch (col2mono_code) {

    case c_COL2MONO_GRAY:
        MA_tmp_transform.release();
        return Convert_Color(
                    pMA_Out,
                    pMA_In,
                    CV_BGR2GRAY);

    case c_COL2MONO_BLUE:
    case c_COL2MONO_GREEN:
    case c_COL2MONO_RED:
        ER = Duplicate(
                    &MA_tmp_transform,
                    pMA_In);
        break;

    case c_COL2MONO_X:
    case c_COL2MONO_Y:
    case c_COL2MONO_Z:
        ER = Convert_Color(
                    &MA_tmp_transform,
                    pMA_In,
                    CV_BGR2XYZ);
        break;

    case c_COL2MONO_HUE:
    case c_COL2MONO_SATURATION:
    case c_COL2MONO_VALUE:
        ER = Convert_Color(
                    &MA_tmp_transform,
                    pMA_In,
                    CV_BGR2HSV_FULL);
        break;

    case c_COL2MONO_BRIGHTNESS:
    case c_COL2MONO_RED_GREEN:
    case c_COL2MONO_BLUE_YELLOW:
        ER = Convert_Color(
                    &MA_tmp_transform,
                    pMA_In,
                    CV_BGR2YCrCb);
        break;

    case c_COL2MONO_LUMINANZ:
        ER = Convert_Color(
                    &MA_tmp_transform,
                    pMA_In,
                    CV_BGR2Lab);
        break;

    default:
        ER = ER_parameter_bad;
        break;
    }


    if(ER != ER_okay)
        return ER_okay;


    switch (col2mono_code) {

    case c_COL2MONO_BLUE:
    case c_COL2MONO_X:
    case c_COL2MONO_BRIGHTNESS:
    case c_COL2MONO_HUE:
    case c_COL2MONO_LUMINANZ:
        ER = Split(
                    pMA_Out,
                    &MA_tmp_transform,
                    0);
        break;

    case c_COL2MONO_GREEN:
    case c_COL2MONO_Y:
    case c_COL2MONO_BLUE_YELLOW:
    case c_COL2MONO_SATURATION:
        ER = Split(
                    pMA_Out,
                    &MA_tmp_transform,
                    1);
        break;

    case c_COL2MONO_RED:
    case c_COL2MONO_Z:
    case c_COL2MONO_RED_GREEN:
    case c_COL2MONO_VALUE:
        ER = Split(
                    pMA_Out,
                    &MA_tmp_transform,
                    2);
        break;

    default:
        ER = ER_parameter_bad;
        break;
    }


    MA_tmp_transform.release();
    return ER;
}

int D_Img_Proc::Convert_Double_1C(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->channels() != 1)                                              return ER_channel_bad;

    //size
    int area = pMA_In->rows * pMA_In->cols;

    //out img
    *pMA_Out = Mat::zeros(pMA_In->size(), CV_64FC1);
    double* ptr_out = reinterpret_cast<double*>(pMA_Out->data);

    //in img
    switch (pMA_In->type()) {

    case CV_8UC1:
    {
        uchar* ptr_in = reinterpret_cast<uchar*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<double>(*ptr_in);
    }
        break;

    case CV_8SC1:
    {
        char* ptr_in = reinterpret_cast<char*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<double>(*ptr_in);
    }
        break;

    case CV_16UC1:
    {
        ushort* ptr_in = reinterpret_cast<ushort*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<double>(*ptr_in);
    }
        break;

    case CV_16SC1:
    {
        short* ptr_in = reinterpret_cast<short*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<double>(*ptr_in);
    }
        break;

    case CV_32SC1:
    {
        int* ptr_in = reinterpret_cast<int*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<double>(*ptr_in);
    }
        break;

    case CV_32FC1:
    {
        float* ptr_in = reinterpret_cast<float*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<double>(*ptr_in);
    }
        break;

    case CV_64FC1:
    {
        double* ptr_in = reinterpret_cast<double*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<double>(*ptr_in);
    }
        break;

    default:
        return ER_bitdepth_bad;
    }

    return ER_okay;
}

int D_Img_Proc::Convert_Double(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty()) return ER_empty;

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

int D_Img_Proc::Convert_UChar_1C(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->channels() != 1)                                              return ER_channel_bad;

    //size
    int area = pMA_In->rows * pMA_In->cols;

    //out img
    *pMA_Out = Mat::zeros(pMA_In->size(), CV_8UC1);
    uchar* ptr_out = reinterpret_cast<uchar*>(pMA_Out->data);

    //in img
    switch (pMA_In->type()) {

    case CV_8UC1:
    {
        uchar* ptr_in = reinterpret_cast<uchar*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(*ptr_in);
    }
        break;

    case CV_8SC1:
    {
        char* ptr_in = reinterpret_cast<char*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(*ptr_in);
    }
        break;

    case CV_16UC1:
    {
        ushort* ptr_in = reinterpret_cast<ushort*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(*ptr_in);
    }
        break;

    case CV_16SC1:
    {
        short* ptr_in = reinterpret_cast<short*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(*ptr_in);
    }
        break;

    case CV_32SC1:
    {
        int* ptr_in = reinterpret_cast<int*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(*ptr_in);
    }
        break;

    case CV_32FC1:
    {
        float* ptr_in = reinterpret_cast<float*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(*ptr_in);
    }
        break;

    case CV_64FC1:
    {
        double* ptr_in = reinterpret_cast<double*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(*ptr_in);
    }
        break;

    default:
        return ER_bitdepth_bad;
    }

    return ER_okay;
}

int D_Img_Proc::Convert_UChar(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty()) return ER_empty;

    switch (pMA_In->channels()) {

    case 1:
    {
        int ER = Convert_UChar_1C(
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

        Mat MA_tmp_uchar[2];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Convert_UChar_1C(
                        &(MA_tmp_uchar[c]),
                        &(MA_tmp_in[c]));
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_uchar,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_uchar[c].release();
        }
    }
        break;

    case 3:
    {
        Mat MA_tmp_in[3];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_uchar[3];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Convert_UChar_1C(
                        &(MA_tmp_uchar[c]),
                        &(MA_tmp_in[c]));
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_uchar,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_uchar[c].release();
        }
    }
        break;

    case 4:
    {
        Mat MA_tmp_in[4];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_uchar[4];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Convert_UChar_1C(
                        &(MA_tmp_uchar[c]),
                        &(MA_tmp_in[c]));
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_uchar,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_uchar[c].release();
        }
    }
        break;

    default:
        break;
    }

    return ER_okay;
}

int D_Img_Proc::Convert_8UC1(Mat *pMA_Out, Mat *pMA_In)
{
    //errors
    if(pMA_In->empty())     return ER_empty;
    if(pMA_In->dims != 2)   return ER_dim_2D_only;
    int ER;

    //8bit buffer
    Mat MA_tmp_8bit;
    if(pMA_In->depth() == CV_8U)
        MA_tmp_8bit = pMA_In->clone();
    else
    {
        ER = Normalize(
                    &MA_tmp_8bit,
                    pMA_In,
                    CV_MINMAX,
                    CV_8U,
                    0,
                    255);
        if(ER != ER_okay)
        {
            MA_tmp_8bit.release();
            return ER;
        }
    }

    //size & out
    int px_count = pMA_In->rows * pMA_In->cols;
    *pMA_Out = Mat(pMA_In->size(), CV_8UC1);
    uchar* ptr_out = reinterpret_cast<uchar*>(pMA_Out->data);

    //types
    switch (pMA_In->type()) {

    case CV_8UC1:
        *pMA_Out = MA_tmp_8bit.clone();
        break;

    case CV_8UC2:
    {
        Vec2b* ptr_in = reinterpret_cast<Vec2b*>(MA_tmp_8bit.data);
        for(int px = 0; px < px_count; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(((*ptr_in)[0] + (*ptr_in)[1])/ 2);
    }
        break;

    case CV_8UC3:
    {
        Vec3b* ptr_in = reinterpret_cast<Vec3b*>(MA_tmp_8bit.data);
        for(int px = 0; px < px_count; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(((*ptr_in)[0] + (*ptr_in)[1] + (*ptr_in)[2])/ 3);
    }
        break;

    case CV_8UC4:
    {
        Vec4b* ptr_in = reinterpret_cast<Vec4b*>(MA_tmp_8bit.data);
        for(int px = 0; px < px_count; px++, ptr_in++, ptr_out++)
            *ptr_out = static_cast<uchar>(((*ptr_in)[0] + (*ptr_in)[1] + (*ptr_in)[2] + (*ptr_in)[3])/ 4);
    }
        break;

    default:
        return ER_type_bad;
    }

    MA_tmp_8bit.release();
    return ER_okay;
}

int D_Img_Proc::Convert_Complex2Real_1C(Mat *pMA_Out, Mat *pMA_InRe, Mat *pMA_InIm, int mode)
{
    //Errors
    if(pMA_InRe->empty())                               return ER_empty;
    if(pMA_InIm->empty())                               return ER_empty;
    if(pMA_InRe->channels() != 1)                       return ER_channel_bad;
    if(pMA_InIm->channels() != 1)                       return ER_channel_bad;
    if(pMA_InRe->type() != pMA_InIm->type())            return ER_type_missmatch;
    if(pMA_InRe->size != pMA_InIm->size)                return ER_size_missmatch;
    int ER;

    //select mode
    switch (mode) {

    case c_COMPLEX2REAL_REAL:
        *pMA_Out = pMA_InRe->clone();
        return ER_okay;

    case c_COMPLEX2REAL_IMAG:
        *pMA_Out = pMA_InIm->clone();
        return ER_okay;

    case c_COMPLEX2REAL_ABS_SQUARE:
        return Math_MagnitudeSquared(
                    pMA_Out,
                    pMA_InRe,
                    pMA_InIm);

    case c_COMPLEX2REAL_RE_IM:
    {
        Mat MA_tmp_Array[2] = {*pMA_InRe, *pMA_InIm};
        merge(
                    MA_tmp_Array,
                    2,
                    *pMA_Out);
        MA_tmp_Array->release();
    }
        break;

    case c_COMPLEX2REAL_PHASE:
    case c_COMPLEX2REAL_ABS:
    {
        if(pMA_InRe->depth() == CV_32F || pMA_InRe->depth() == CV_64F)
        {
            if(mode == c_COMPLEX2REAL_ABS)
                return Math_Magnitude(
                            pMA_Out,
                            pMA_InRe,
                            pMA_InIm);
            else
                return Math_Phase(
                            pMA_Out,
                            pMA_InRe,
                            pMA_InIm);
        }
        else
        {
            //re
            Mat MA_tmp_re_double;
            ER = Convert_Double(
                        &MA_tmp_re_double,
                        pMA_InRe);
            if(ER != ER_okay)
            {
                MA_tmp_re_double.release();
                return ER;
            }

            //im
            Mat MA_tmp_im_double;
            ER = Convert_Double(
                        &MA_tmp_im_double,
                        pMA_InIm);
            if(ER != ER_okay)
            {
                MA_tmp_re_double.release();
                MA_tmp_im_double.release();
                return ER;
            }

            if(mode == c_COMPLEX2REAL_ABS)
                ER = Math_Magnitude(
                            pMA_Out,
                            &MA_tmp_re_double,
                            &MA_tmp_im_double);
            else
                ER = Math_Phase(
                            pMA_Out,
                            &MA_tmp_re_double,
                            &MA_tmp_im_double);

            //finish
            MA_tmp_re_double.release();
            MA_tmp_im_double.release();
            return ER;
        }
    }

    case c_COMPLEX2REAL_HUE_SAT:
    case c_COMPLEX2REAL_HUE_VAL:
    {
        //re
        Mat MA_tmp_re_double;
        ER = Convert_Double(
                    &MA_tmp_re_double,
                    pMA_InRe);
        if(ER != ER_okay)
        {
            MA_tmp_re_double.release();
            return ER;
        }

        //im
        Mat MA_tmp_im_double;
        ER = Convert_Double(
                    &MA_tmp_im_double,
                    pMA_InIm);
        if(ER != ER_okay)
        {
            MA_tmp_re_double.release();
            MA_tmp_im_double.release();
            return ER;
        }

        //abs
        Mat MA_tmp_Abs;
        Math_Magnitude(
                            &MA_tmp_Abs,
                            pMA_InRe,
                            pMA_InIm);
        if(ER != ER_okay)
        {
            MA_tmp_re_double.release();
            MA_tmp_im_double.release();
            MA_tmp_Abs.release();
            return ER;
        }

        //phase
        Mat MA_tmp_Phase;
        Math_Phase(
                            &MA_tmp_Phase,
                            pMA_InRe,
                            pMA_InIm);
        if(ER != ER_okay)
        {
            MA_tmp_re_double.release();
            MA_tmp_im_double.release();
            MA_tmp_Phase.release();
            MA_tmp_Abs.release();
            return ER;
        }

        //extrema
        double val_min, val_max;
        ER = MinMax_of_Mat(
                    &MA_tmp_Abs,
                    &val_min,
                    &val_max);
        if(ER != ER_okay)
        {
            MA_tmp_re_double.release();
            MA_tmp_im_double.release();
            MA_tmp_Phase.release();
            MA_tmp_Abs.release();
            return ER;
        }

        //range
        double val_range = val_max - val_min;

        //boring values dangerous for 0-divison?
        if(val_range == 0)
        {
            *pMA_Out = Mat::zeros(pMA_InRe->size(), CV_64FC3);
            MA_tmp_re_double.release();
            MA_tmp_im_double.release();
            MA_tmp_Phase.release();
            MA_tmp_Abs.release();
            return ER_okay;
        }

        //pixel count
        size_t area = pMA_InRe->rows * pMA_InRe->cols;

        //init out
        *pMA_Out = Mat(pMA_InRe->size(), CV_64FC3);

        //data pointers
        double* ptr_abs = reinterpret_cast<double*>(MA_tmp_Abs.data);
        double* ptr_phase = reinterpret_cast<double*>(MA_tmp_Phase.data);
        Vec3d* ptr_out = reinterpret_cast<Vec3d*>(pMA_Out->data);

        //loop img
        for(size_t px = 0; px < area; px++, ptr_abs++, ptr_phase++, ptr_out++)
        {
            double  val_normed  = (*ptr_abs - val_min) / val_range;
            double  H           = *ptr_phase;
            double  S           = mode == c_COMPLEX2REAL_HUE_SAT ? val_normed : 1;
            double  V           = mode == c_COMPLEX2REAL_HUE_SAT ? 1 : val_normed;
            int     hi          = floor(H / (PI / 3.0));
            double  f           = (H / (PI / 3.0)) - hi;
            double  p           = V * (1 - S);
            double  q           = V * (1 - (S * f));
            double  t           = V * (1 - (S * (1 - f)));
            double  R;
            double  G;
            double  B;

            //invers HSV Transfrom
            switch (hi) {

            case 1:
                R = q;
                G = V;
                B = p;
                break;

            case 2:
                R = p;
                G = V;
                B = t;
                break;

            case 3:
                R = p;
                G = q;
                B = V;
                break;

            case 4:
                R = t;
                G = p;
                B = V;
                break;

            case 5:
                R = V;
                G = p;
                B = q;
                break;

            default:
                R = V;
                G = t;
                B = p;
                break;
            }

            *ptr_out = Vec3d(B, G, R);
        }

        MA_tmp_re_double.release();
        MA_tmp_im_double.release();
        MA_tmp_Phase.release();
        MA_tmp_Abs.release();
        return ER;
    }
        break;

    default:
        return ER_parameter_bad;
    }

    return  ER_okay;
}

int D_Img_Proc::Convert_Complex2Real_1C(Mat *pMA_Out, Mat *pMA_InComplexChannels, int mode)
{
    //Errors
    if(pMA_InComplexChannels->empty())                          return ER_empty;
    if(pMA_InComplexChannels->channels() != 2)                  return ER_channel_bad;

    //array
    Mat MA_tmp_Array[2];
    split(
                *pMA_InComplexChannels,
                MA_tmp_Array);

    //use existing function
    int ER = Convert_Complex2Real_1C(
                pMA_Out,
                &(MA_tmp_Array[0]),
                &(MA_tmp_Array[1]),
                mode);

    //free mem
    MA_tmp_Array->release();

    //end
    return ER;
}

int D_Img_Proc::Convert_Angle2Color_Rad(Mat *pMA_Out, Mat *pMA_InAngleRad, uchar Saturation, uchar Value)
{
    if(pMA_InAngleRad->empty())                     return ER_empty;
    if(pMA_InAngleRad->type() != CV_64FC1)          return ER_type_bad;

    //Dummy Mat HSV
    Mat MA_tmp_HSV(pMA_InAngleRad->size(), CV_8UC3);

    //loop img
    for(int y = 0; y < pMA_InAngleRad->rows; y++)
        for(int x = 0; x < pMA_InAngleRad->cols; x++)
        {
            //get pixel value
            double val = pMA_InAngleRad->at<double>(y,x);

            //eliminate negative values
            if(val < 0)
                val += static_cast<int>(abs(val)/PI_2_0 + 1) * PI_2_0;

            //eliminate values greater than 2pi
            if(val > PI_2_0)
                val -= static_cast<int>(abs(val)/PI_2_0) * PI_2_0;

            //calc H and set SV in HSV
            MA_tmp_HSV.at<Vec3b>(y, x) = Vec3b(
                        static_cast<uchar>(val * (255/PI_2_0)),
                        Saturation,
                        Value);
        }

    //tranform to BGR that can be displayed
    int ER = Convert_Color(
                pMA_Out,
                &MA_tmp_HSV,
                CV_HSV2RGB_FULL);

    MA_tmp_HSV.release();
    return ER;
}

int D_Img_Proc::Normalize(Mat *pMA_Out, Mat *pMA_In, unsigned int norm, unsigned int type, double min, double max)
{
    if(pMA_In->empty())     return ER_empty;

    switch (type) {

    case CV_8U:
        switch (pMA_In->channels()) {
        case 1:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_8UC1);          break;
        case 2:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_8UC2);          break;
        case 3:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_8UC3);          break;
        case 4:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_8UC4);          break;
        default:
            break;
        }
        break;

    case CV_8S:
        switch (pMA_In->channels()) {
        case 1:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_8SC1);          break;
        case 2:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_8SC2);          break;
        case 3:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_8SC3);          break;
        case 4:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_8SC4);          break;
        default:
            break;
        }
        break;

    case CV_16U:
        switch (pMA_In->channels()) {
        case 1:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_16UC1);         break;
        case 2:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_16UC2);         break;
        case 3:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_16UC3);         break;
        case 4:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_16UC4);         break;
        default:
            break;
        }
        break;

    case CV_16S:
        switch (pMA_In->channels()) {
        case 1:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_16SC1);         break;
        case 2:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_16SC2);         break;
        case 3:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_16SC3);         break;
        case 4:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_16SC4);         break;
        default:
            break;
        }
        break;

    case CV_32S:
        switch (pMA_In->channels()) {
        case 1:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_32SC1);         break;
        case 2:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_32SC2);         break;
        case 3:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_32SC3);         break;
        case 4:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_32SC4);         break;
        default:
            break;
        }
        break;

    case CV_32F:
        switch (pMA_In->channels()) {
        case 1:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_32FC1);         break;
        case 2:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_32FC2);         break;
        case 3:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_32FC3);         break;
        case 4:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_32FC4);         break;
        default:
            break;
        }
        break;

    case CV_64F:
        switch (pMA_In->channels()) {
        case 1:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_64FC1);         break;
        case 2:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_64FC2);         break;
        case 3:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_64FC3);         break;
        case 4:     normalize(*pMA_In, *pMA_Out, min, max, norm, CV_64FC4);         break;
        default:
            break;
        }
        break;
    default:
        break;
    }

    return ER_okay;
}

int D_Img_Proc::Spread_16_bit_to_8bit(Mat *pMA_Out, Mat *pMA_In, double in_max, double out_max)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->type() != CV_16UC1)  return ER_type_bad;

    unsigned int width = pMA_In->cols;
    unsigned int height = pMA_In->rows;
    unsigned int area = width * height;

    double in_range = in_max - 0.0;
    double out_range = out_max - 0.0;
    double factor = out_range / in_range;

    *pMA_Out = Mat(pMA_In->size(), CV_8UC1);

    ushort* ptr_in = reinterpret_cast<ushort*>(pMA_In->data);           //cast to read as 16bit
    uchar*  ptr_out = reinterpret_cast<uchar*>(pMA_Out->data);          //8bit pointer
    for (unsigned int px = 0; px < area; px++, ptr_in++, ptr_out++)     //loop pixels
    {
        ushort val_in = *ptr_in;

        double val_out = val_in * factor;
        if(val_out > out_max)
            val_out = out_max;

        (*ptr_out) = (uchar)val_out;                       //calc and write out value
    }

    return ER_okay;
}

int D_Img_Proc::Spread_8bit_to_float01(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->type() != CV_8UC1)   return ER_type_bad;

    unsigned int width = pMA_In->cols;
    unsigned int height = pMA_In->rows;
    unsigned int area = width * height;

    *pMA_Out = Mat(pMA_In->size(), CV_32FC1);

    uchar* ptr_in = reinterpret_cast<uchar*>(pMA_In->data);             //8bit input
    float*  ptr_out = reinterpret_cast<float*>(pMA_Out->data);          //float output
    for (unsigned int px = 0; px < area; px++, ptr_in++, ptr_out++)     //loop pixels
        (*ptr_out) = (float)((*ptr_in) / 255.0);                        //calc and write out value

    return ER_okay;
}

int D_Img_Proc::Split(Mat *pMA_Out, Mat *pMA_In, unsigned int channel)
{
    if(pMA_In->empty())                     return ER_empty;
    if(pMA_In->channels() <= (int)channel)  return ER_channel_bad;

    switch (pMA_In->channels()) {

    case 1:
    {
        *pMA_Out = pMA_In->clone();
    }
        break;

    case 2:
    {
        Mat MA_tmp[2];
        split(*pMA_In, MA_tmp);
        *pMA_Out = MA_tmp[channel];

        for(int c = 0; c < pMA_In->channels(); c++)
            MA_tmp[c].release();
    }
        break;

    case 3:
    {
        Mat MA_tmp[3];
        split(*pMA_In, MA_tmp);
        *pMA_Out = MA_tmp[channel];

        for(int c = 0; c < pMA_In->channels(); c++)
            MA_tmp[c].release();
    }
        break;

    case 4:
    {
        Mat MA_tmp[4];
        split(*pMA_In, MA_tmp);
        *pMA_Out = MA_tmp[channel];

        for(int c = 0; c < pMA_In->channels(); c++)
            MA_tmp[c].release();
    }
        break;

    default:
        break;
    }

    return ER_okay;
}

int D_Img_Proc::Merge(Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, unsigned int channels, bool channel_use[4])
{
    //find used channel
    int channel_highest_used = -1;
    for(unsigned int c = 0; c < channels; c++)
        if(channel_use[c])
            channel_highest_used = c;

    //check, if there is at least one channel used
    if(channel_highest_used == -1)
        return ER_channel_bad;

    //copy pointer to used image
    Mat *pMA_highest_used;
    if     (channel_highest_used == 1)              pMA_highest_used = pMA_In0;
    else if(channel_highest_used == 2)              pMA_highest_used = pMA_In1;
    else if(channel_highest_used == 3)              pMA_highest_used = pMA_In2;
    else                                            pMA_highest_used = pMA_In3;

    //Create 0 image for channels not to be set
    Mat MA_tmp_0 = Mat(pMA_highest_used->size(), pMA_highest_used->type(), Scalar(0));

    //merge & check for errors
    switch (channels) {

    case 1:
    {
        Mat MA_Merge[1]     = {MA_tmp_0};
        if(channel_use[0])  MA_Merge[0] = *pMA_In0;

        for(unsigned int c = 0; c < channels; c++)
        {
            if(MA_Merge[c].type() != pMA_highest_used->type())      return ER_type_missmatch;
            if(MA_Merge[c].size() != pMA_highest_used->size())      return ER_size_missmatch;
            if(MA_Merge[c].depth() != pMA_highest_used->depth())    return ER_bitdepth_missmatch;
            if(MA_Merge[c].channels() > 1)                          return ER_type_missmatch;
        }

        merge(
                    MA_Merge,
                    channels,
                    *pMA_Out);

        for(unsigned int c = 0; c < channels; c++)
            MA_Merge[c].release();
    }
        break;

    case 2:
    {
        Mat MA_Merge[2]     = {MA_tmp_0, MA_tmp_0};
        if(channel_use[0])  MA_Merge[0] = *pMA_In0;
        if(channel_use[1])  MA_Merge[1] = *pMA_In1;

        for(unsigned int c = 0; c < channels; c++)
        {
            if(MA_Merge[c].type() != pMA_highest_used->type())      return ER_type_missmatch;
            if(MA_Merge[c].size() != pMA_highest_used->size())      return ER_size_missmatch;
            if(MA_Merge[c].depth() != pMA_highest_used->depth())    return ER_bitdepth_missmatch;
            if(MA_Merge[c].channels() > 1)                          return ER_type_missmatch;
        }

        merge(
                    MA_Merge,
                    channels,
                    *pMA_Out);

        for(unsigned int c = 0; c < channels; c++)
            MA_Merge[c].release();
    }
        break;

    case 3:
    {
        Mat MA_Merge[3]     = {MA_tmp_0, MA_tmp_0, MA_tmp_0};
        if(channel_use[0])  MA_Merge[0] = *pMA_In0;
        if(channel_use[1])  MA_Merge[1] = *pMA_In1;
        if(channel_use[2])  MA_Merge[2] = *pMA_In2;

        for(unsigned int c = 0; c < channels; c++)
        {
            if(MA_Merge[c].type() != pMA_highest_used->type())      return ER_type_missmatch;
            if(MA_Merge[c].size() != pMA_highest_used->size())      return ER_size_missmatch;
            if(MA_Merge[c].depth() != pMA_highest_used->depth())    return ER_bitdepth_missmatch;
            if(MA_Merge[c].channels() > 1)                          return ER_type_missmatch;
        }

        merge(
                    MA_Merge,
                    channels,
                    *pMA_Out);

        for(unsigned int c = 0; c < channels; c++)
            MA_Merge[c].release();
    }
        break;

    case 4:
    {
        Mat MA_Merge[4]     = {MA_tmp_0, MA_tmp_0, MA_tmp_0, MA_tmp_0};
        if(channel_use[0])  MA_Merge[0] = *pMA_In0;
        if(channel_use[1])  MA_Merge[1] = *pMA_In1;
        if(channel_use[2])  MA_Merge[2] = *pMA_In2;
        if(channel_use[3])  MA_Merge[3] = *pMA_In3;

        for(unsigned int c = 0; c < channels; c++)
        {
            if(MA_Merge[c].type() != pMA_highest_used->type())      return ER_type_missmatch;
            if(MA_Merge[c].size() != pMA_highest_used->size())      return ER_size_missmatch;
            if(MA_Merge[c].depth() != pMA_highest_used->depth())    return ER_bitdepth_missmatch;
            if(MA_Merge[c].channels() > 1)                          return ER_type_missmatch;
        }

        merge(
                    MA_Merge,
                    channels,
                    *pMA_Out);

        for(unsigned int c = 0; c < channels; c++)
            MA_Merge[c].release();
    }
        break;

    default:
        break;
    }

    MA_tmp_0.release();
    return ER_okay;
}

int D_Img_Proc::Duplicate2Channels(Mat *pMA_Out, Mat *pMA_In, int channels)
{
    if(pMA_In->empty())                 return ER_empty;
    if(pMA_In->channels() != 1)         return ER_channel_bad;
    if(channels < 1 || channels > 4)    return ER_parameter_bad;

    switch (channels) {

    case 1:
    {
        *pMA_Out = pMA_In->clone();
    }
        break;

    case 2:
    {
        Mat MA_Merge[2] = {*pMA_In, *pMA_In};

        merge(
                    MA_Merge,
                    channels,
                    *pMA_Out);

        for(int c = 0; c < channels; c++)
            MA_Merge[c].release();
    }
        break;

    case 3:
    {
        Mat MA_Merge[3] = {*pMA_In, *pMA_In,*pMA_In};

        merge(
                    MA_Merge,
                    channels,
                    *pMA_Out);

        for(int c = 0; c < channels; c++)
            MA_Merge[c].release();
    }
        break;

    case 4:
    {
        Mat MA_Merge[4] = {*pMA_In, *pMA_In, *pMA_In, *pMA_In};

        merge(
                    MA_Merge,
                    channels,
                    *pMA_Out);

        for(int c = 0; c < channels; c++)
            MA_Merge[c].release();
    }
        break;

    default:
        return ER_parameter_bad;

    }

    return  ER_okay;
}

int D_Img_Proc::Merge(Mat *pMA_Out, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2)
{
    bool channels_used[4] = {true, true, true};

    return Merge(
                pMA_Out,
                pMA_In0,
                pMA_In1,
                pMA_In2,
                pMA_In2,
                3,
                channels_used);
}

int D_Img_Proc::Merge(Mat *pMA_Out, vector<Mat> vMA_in, vector<int> v_R, vector<int> v_G, vector<int> v_B, vector<int> v_A)
{
    //checks
    if(vMA_in.empty())                         return ER_empty;
    if(vMA_in.size() != v_R.size())            return ER_size_missmatch;
    if(vMA_in.size() != v_G.size())            return ER_size_missmatch;
    if(vMA_in.size() != v_B.size())            return ER_size_missmatch;
    if(vMA_in.size() != v_A.size())            return ER_size_missmatch;
    for(int i = 0; i < vMA_in.size(); i++)
    {
        if(vMA_in[i].size != vMA_in[0].size)                                return ER_size_missmatch;
        if(vMA_in[i].type() != CV_64FC1 && vMA_in[i].type() != CV_8UC1)     return ER_type_bad;
        if(vMA_in[i].type() != vMA_in[0].type())                            return ER_type_missmatch;
        if(v_R[i] < 0 || v_R[i] > 255)                                      return ER_parameter_bad;
        if(v_G[i] < 0 || v_G[i] > 255)                                      return ER_parameter_bad;
        if(v_B[i] < 0 || v_B[i] > 255)                                      return ER_parameter_bad;
        if(v_A[i] < 0 || v_A[i] > 255)                                      return ER_parameter_bad;
    }

    //scaling factors
    vector<double> v_R_Scale;
    vector<double> v_G_Scale;
    vector<double> v_B_Scale;
    v_R_Scale.resize(vMA_in.size());
    v_G_Scale.resize(vMA_in.size());
    v_B_Scale.resize(vMA_in.size());
    for(int i = 0; i < vMA_in.size(); i++)
    {
        v_R_Scale[i] = (v_R[i] * v_A[i]) / (255.0 * 255.0);
        v_G_Scale[i] = (v_G[i] * v_A[i]) / (255.0 * 255.0);
        v_B_Scale[i] = (v_B[i] * v_A[i]) / (255.0 * 255.0);
    }

    //img out
    *pMA_Out = Mat(vMA_in[0].size(), CV_8UC3);

    //loop pixels
    switch (vMA_in[0].type()) {

    case CV_8UC1:
    {
        for(int y = 0; y < pMA_Out->rows; y++)
            for(int x = 0; x < pMA_Out->cols; x++)
            {
                //result values
                double r_out = 0;
                double g_out = 0;
                double b_out = 0;
                for(size_t i = 0; i < vMA_in.size(); i++)
                {
                    //weigth by color, alpha, intensity
                    uchar val_in = vMA_in[i].at<uchar>(y, x);
                    r_out += val_in * v_R_Scale[i];
                    g_out += val_in * v_G_Scale[i];
                    b_out += val_in * v_B_Scale[i];
                }

                //force in range
                if(r_out < 0)       r_out = 0;
                if(g_out < 0)       g_out = 0;
                if(b_out < 0)       b_out = 0;
                if(r_out > 255)     r_out = 255;
                if(g_out > 255)     g_out = 255;
                if(b_out > 255)     b_out = 255;

                //Out color
                Vec3b Color_Out;
                Color_Out[0] = static_cast<uchar>(b_out);
                Color_Out[1] = static_cast<uchar>(g_out);
                Color_Out[2] = static_cast<uchar>(r_out);

                pMA_Out->at<Vec3b>(y, x) = Color_Out;
            }
    }
        break;

    case CV_64FC1:
    {
        for(int y = 0; y < pMA_Out->rows; y++)
            for(int x = 0; x < pMA_Out->cols; x++)
            {
                //result values
                double r_out = 0;
                double g_out = 0;
                double b_out = 0;
                for(int i = 0; i < vMA_in.size(); i++)
                {
                    //weigth by color, alpha, intensity
                    double val_in = vMA_in[i].at<double>(y, x);
                    r_out += val_in * v_R_Scale[i];
                    g_out += val_in * v_G_Scale[i];
                    b_out += val_in * v_B_Scale[i];
                }

                //force in range
                if(r_out < 0)       r_out = 0;
                if(g_out < 0)       g_out = 0;
                if(b_out < 0)       b_out = 0;
                if(r_out > 255)     r_out = 255;
                if(g_out > 255)     g_out = 255;
                if(b_out > 255)     b_out = 255;

                //Out color
                Vec3b Color_Out;
                Color_Out[0] = static_cast<uchar>(b_out);
                Color_Out[1] = static_cast<uchar>(g_out);
                Color_Out[2] = static_cast<uchar>(r_out);

                pMA_Out->at<Vec3b>(y, x) = Color_Out;
            }
    }
        break;

    default:
        break;
    }

    return ER_okay;
}

int D_Img_Proc::Combi_8UC1_binary(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty())                                     return ER_empty;
    if(pMA_In->channels() != 1 && pMA_In->channels() != 3)  return ER_channel_bad;

    Mat MA_tmp = pMA_In->clone();

    //Error Handler
    int ER = ER_okay;

    //Depth -> 8U
    if(MA_tmp.depth() != CV_8U)
    {
        int type;
        switch (MA_tmp.channels()) {
        case 1:     type = CV_8UC1;                break;
        case 3:     type = CV_8UC3;                break;
        default:    return ER_channel_bad;   break;}

        ER = Normalize(
                    &MA_tmp,
                    &MA_tmp,
                    CV_MINMAX,
                    type,
                    0,
                    255);
    }
    if(ER != ER_okay)   return ER;

    //Channels -> 1
    if(MA_tmp.channels() != 1)
    {
        if(MA_tmp.channels() == 3)
            ER = Convert_Color(
                        &MA_tmp,
                        &MA_tmp,
                        CV_BGR2GRAY);
        else
            return ER_channel_bad;
    }
    if(ER != ER_okay)   return ER;

    //Binarize
    {
        ER = Threshold_Auto(
                    pMA_Out,
                    &MA_tmp,
                    CV_THRESH_BINARY,
                    255,
                    CV_THRESH_OTSU);
    }
    if(ER != ER_okay)   return ER;

    MA_tmp.release();
    return ER_okay;
}

int D_Img_Proc::GammaSpread_1C(Mat *pMA_Out, Mat *pMA_In, double gamma, double in_min, double in_max, double out_min, double out_max, bool force_8bit)
{
    if(pMA_In->empty())         return ER_empty;
    if(pMA_In->channels() != 1) return ER_channel_bad;

    //values
    double offset_in    = in_min;
    double offset_out   = out_min;
    double range_in     = in_max - in_min;
    double range_out    = out_max - out_min;

    //size
    int area = pMA_In->rows * pMA_In->cols;

    //output init
    if(force_8bit)
    {
        *pMA_Out        = Mat::zeros(pMA_In->size(), CV_8UC1);
        uchar* ptr_out = reinterpret_cast<uchar*>(pMA_Out->data);

        //apply thres
        switch (pMA_In->type()) {

        case CV_8UC1://==============================================================
        {
            uchar* ptr_in = reinterpret_cast<uchar*>(pMA_In->data);
            for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            {
                if(*ptr_in < in_min)
                    *ptr_out = static_cast<uchar>(out_min);
                else if (*ptr_in > in_max)
                    *ptr_out = static_cast<uchar>(out_max);
                else
                    *ptr_out = static_cast<uchar>(pow((*ptr_in - offset_in)/ range_in, gamma) * range_out + offset_out);
            }
        }
            break;

        case CV_8SC1://==============================================================
        {
            schar* ptr_in = reinterpret_cast<schar*>(pMA_In->data);
            for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            {
                if(*ptr_in < in_min)
                    *ptr_out = static_cast<uchar>(out_min);
                else if (*ptr_in > in_max)
                    *ptr_out = static_cast<uchar>(out_max);
                else
                    *ptr_out = static_cast<uchar>(pow((*ptr_in - offset_in)/ range_in, gamma) * range_out + offset_out);
            }
        }
            break;

        case CV_16UC1://=============================================================
        {
            ushort* ptr_in = reinterpret_cast<ushort*>(pMA_In->data);
            for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            {
                if(*ptr_in < in_min)
                    *ptr_out = static_cast<uchar>(out_min);
                else if (*ptr_in > in_max)
                    *ptr_out = static_cast<uchar>(out_max);
                else
                    *ptr_out = static_cast<uchar>(pow((*ptr_in - offset_in)/ range_in, gamma) * range_out + offset_out);
            }
        }
            break;

        case CV_16SC1://============================================================
        {
            short* ptr_in = reinterpret_cast<short*>(pMA_In->data);
            for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            {
                if(*ptr_in < in_min)
                    *ptr_out = static_cast<uchar>(out_min);
                else if (*ptr_in > in_max)
                    *ptr_out = static_cast<uchar>(out_max);
                else
                    *ptr_out = static_cast<uchar>(pow((*ptr_in - offset_in)/ range_in, gamma) * range_out + offset_out);
            }
        }
            break;

        case CV_32SC1://=============================================================
        {
            int* ptr_in = reinterpret_cast<int*>(pMA_In->data);
            for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            {
                if(*ptr_in < in_min)
                    *ptr_out = static_cast<uchar>(out_min);
                else if (*ptr_in > in_max)
                    *ptr_out = static_cast<uchar>(out_max);
                else
                    *ptr_out = static_cast<uchar>(pow((*ptr_in - offset_in)/ range_in, gamma) * range_out + offset_out);
            }
        }
            break;

        case CV_32FC1://==============================================================
        {
            float* ptr_in = reinterpret_cast<float*>(pMA_In->data);
            for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            {
                if(*ptr_in < in_min)
                    *ptr_out = static_cast<uchar>(out_min);
                else if (*ptr_in > in_max)
                    *ptr_out = static_cast<uchar>(out_max);
                else
                    *ptr_out = static_cast<uchar>(pow((*ptr_in - offset_in)/ range_in, gamma) * range_out + offset_out);
            }
        }
            break;

        case CV_64FC1://=============================================================
        {
            double* ptr_in = reinterpret_cast<double*>(pMA_In->data);
            for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            {
                if(*ptr_in < in_min)
                    *ptr_out = static_cast<uchar>(out_min);
                else if (*ptr_in > in_max)
                    *ptr_out = static_cast<uchar>(out_max);
                else
                    *ptr_out = static_cast<uchar>(pow((*ptr_in - offset_in)/ range_in, gamma) * range_out + offset_out);
            }
        }
            break;

        default:
            return ER_bitdepth_bad;
        }
    }
    else
    {
        *pMA_Out        = Mat::zeros(pMA_In->size(), CV_64FC1);
        double* ptr_out = reinterpret_cast<double*>(pMA_Out->data);

        //apply thres
        switch (pMA_In->type()) {

        case CV_8UC1://==============================================================
        {
            uchar* ptr_in = reinterpret_cast<uchar*>(pMA_In->data);
            for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            {
                if(*ptr_in < in_min)
                    *ptr_out = static_cast<double>(out_min);
                else if (*ptr_in > in_max)
                    *ptr_out = static_cast<double>(out_max);
                else
                    *ptr_out = static_cast<double>(pow((*ptr_in - offset_in)/ range_in, gamma) * range_out + offset_out);
            }
        }
            break;

        case CV_8SC1://==============================================================
        {
            schar* ptr_in = reinterpret_cast<schar*>(pMA_In->data);
            for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            {
                if(*ptr_in < in_min)
                    *ptr_out = static_cast<double>(out_min);
                else if (*ptr_in > in_max)
                    *ptr_out = static_cast<double>(out_max);
                else
                    *ptr_out = static_cast<double>(pow((*ptr_in - offset_in)/ range_in, gamma) * range_out + offset_out);
            }
        }
            break;

        case CV_16UC1://=============================================================
        {
            ushort* ptr_in = reinterpret_cast<ushort*>(pMA_In->data);
            for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            {
                if(*ptr_in < in_min)
                    *ptr_out = static_cast<double>(out_min);
                else if (*ptr_in > in_max)
                    *ptr_out = static_cast<double>(out_max);
                else
                    *ptr_out = static_cast<double>(pow((*ptr_in - offset_in)/ range_in, gamma) * range_out + offset_out);
            }
        }
            break;

        case CV_16SC1://============================================================
        {
            short* ptr_in = reinterpret_cast<short*>(pMA_In->data);
            for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            {
                if(*ptr_in < in_min)
                    *ptr_out = static_cast<double>(out_min);
                else if (*ptr_in > in_max)
                    *ptr_out = static_cast<double>(out_max);
                else
                    *ptr_out = static_cast<double>(pow((*ptr_in - offset_in)/ range_in, gamma) * range_out + offset_out);
            }
        }
            break;

        case CV_32SC1://=============================================================
        {
            int* ptr_in = reinterpret_cast<int*>(pMA_In->data);
            for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            {
                if(*ptr_in < in_min)
                    *ptr_out = static_cast<double>(out_min);
                else if (*ptr_in > in_max)
                    *ptr_out = static_cast<double>(out_max);
                else
                    *ptr_out = static_cast<double>(pow((*ptr_in - offset_in)/ range_in, gamma) * range_out + offset_out);
            }
        }
            break;

        case CV_32FC1://==============================================================
        {
            float* ptr_in = reinterpret_cast<float*>(pMA_In->data);
            for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            {
                if(*ptr_in < in_min)
                    *ptr_out = static_cast<double>(out_min);
                else if (*ptr_in > in_max)
                    *ptr_out = static_cast<double>(out_max);
                else
                    *ptr_out = static_cast<double>(pow((*ptr_in - offset_in)/ range_in, gamma) * range_out + offset_out);
            }
        }
            break;

        case CV_64FC1://=============================================================
        {
            double* ptr_in = reinterpret_cast<double*>(pMA_In->data);
            for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            {
                if(*ptr_in < in_min)
                    *ptr_out = static_cast<double>(out_min);
                else if (*ptr_in > in_max)
                    *ptr_out = static_cast<double>(out_max);
                else
                    *ptr_out = static_cast<double>(pow((*ptr_in - offset_in)/ range_in, gamma) * range_out + offset_out);
            }
        }
            break;

        default:
            return ER_bitdepth_bad;
        }
    }


    return ER_okay;
}

int D_Img_Proc::GammaSpread(Mat *pMA_Out, Mat *pMA_In, double gamma, double in_min, double in_max, double out_min, double out_max, bool force_8bit)
{
    if(pMA_In->empty()) return ER_empty;

    switch (pMA_In->channels()) {

    case 1:
    {
        int ER = GammaSpread_1C(
                    pMA_Out,
                    pMA_In,
                    gamma,
                    in_min,
                    in_max,
                    out_min,
                    out_max,
                    force_8bit);
        if(ER != ER_okay)   return ER;
    }
        break;

    case 2:
    {
        Mat MA_tmp_in[2];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_proc[2];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = GammaSpread_1C(
                        &(MA_tmp_proc[c]),
                        &(MA_tmp_in[c]),
                        gamma,
                        in_min,
                        in_max,
                        out_min,
                        out_max,
                        force_8bit);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_proc,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_proc[c].release();
        }
    }
        break;

    case 3:
    {
        Mat MA_tmp_in[3];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_proc[3];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = GammaSpread_1C(
                        &(MA_tmp_proc[c]),
                        &(MA_tmp_in[c]),
                        gamma,
                        in_min,
                        in_max,
                        out_min,
                        out_max,
                        force_8bit);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_proc,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_proc[c].release();
        }
    }
        break;

    case 4:
    {
        Mat MA_tmp_in[4];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_proc[4];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = GammaSpread_1C(
                        &(MA_tmp_proc[c]),
                        &(MA_tmp_in[c]),
                        gamma,
                        in_min,
                        in_max,
                        out_min,
                        out_max,
                        force_8bit);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_proc,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_proc[c].release();
        }
    }
        break;

    default:
        break;
    }

    return ER_okay;
}

int D_Img_Proc::GammaSpread_Quantiles(Mat *pMA_Out, Mat *pMA_In, double gamma, double quantile_low, double quantile_high, double out_min, double out_max, bool force_8bit, bool ignore_zeros)
{
    double in_min, in_max;
    int ER = Quantiles_ofPixelvalues(
                &in_min,
                &in_max,
                pMA_In,
                quantile_low,
                quantile_high,
                ignore_zeros);
    if(ER != ER_okay)
        return ER;

    return GammaSpread(
                pMA_Out,
                pMA_In,
                gamma,
                in_min,
                in_max,
                out_min,
                out_max,
                force_8bit);
}

int D_Img_Proc::Visualize_to8bit(Mat *pMA_Out, Mat *pMA_In, int mode_crop, int mode_trafo, int mode_anchor, int mode_range, double val_anchor, double val_range, double val_min, double val_max, double val_gamma, double val_center, double val_scale, bool keep_min_max, int mode_complex)
{
    //errors
    if(pMA_In->empty())     return ER_okay;
    if(val_min > val_max)   return ER_parameter_missmatch;
    int ER;

    //check if complex and handle it before vis trafo
    Mat MA_tmp_ComplexHandeled;
    if(pMA_In->channels() == 2 )
    {
        ER = Convert_Complex2Real_1C(
                    &MA_tmp_ComplexHandeled,
                    pMA_In,
                    mode_complex);
        if(ER != ER_okay)
        {
            MA_tmp_ComplexHandeled.release();
            return ER;
        }
    }
    else
    {
        MA_tmp_ComplexHandeled = pMA_In->clone();
    }


    //range to use
    double crop_min;
    double crop_max;
    if((mode_crop == c_VIS_TRAFO_CROP_FIXED) || keep_min_max)
    {
        crop_min = val_min;
        crop_max = val_max;
    }
    else
    {
        //value range
        double in_min;
        double in_max;
        int ER = MinMax_of_Mat(
                    &MA_tmp_ComplexHandeled,
                    &in_min,
                    &in_max);
        if(ER != ER_okay)
        {
            MA_tmp_ComplexHandeled.release();
            return ER;
        }

        if(mode_crop == c_VIS_TRAFO_CROP_DYNAMIC)
        {
            crop_min = in_min;
            crop_max = in_max;
            //qDebug() << "Visualize_to8bit min/max input" << in_min << in_max;
        }
        else
        {
            MA_tmp_ComplexHandeled.release();
            return ER_parameter_bad;
        }
    }

    //qDebug() << "Visualize_to8bit min/max crop" << crop_min << crop_max;

    //channel managment
    switch (MA_tmp_ComplexHandeled.channels()) {

    case 1:
    {
        int ER = Visualize_to8bit_1C(
                    pMA_Out,
                    &MA_tmp_ComplexHandeled,
                    mode_trafo,
                    mode_anchor,
                    mode_range,
                    val_anchor,
                    val_range,
                    crop_min,
                    crop_max,
                    val_gamma,
                    val_center,
                    val_scale);
        if(ER != ER_okay)
        {
            MA_tmp_ComplexHandeled.release();
            return ER;
        }
    }
        break;

    case 2:
    {
        //split
        Mat MA_tmp_in[2];
        split(
                    MA_tmp_ComplexHandeled,
                    MA_tmp_in);


        //proc channels
        Mat MA_tmp_proc[2];
        for(int c = 0; c < MA_tmp_ComplexHandeled.channels(); c++)
        {
            int ER = Visualize_to8bit_1C(
                        &(MA_tmp_proc[c]),
                        &(MA_tmp_in[c]),
                        mode_trafo,
                        mode_anchor,
                        mode_range,
                        val_anchor,
                        val_range,
                        crop_min,
                        crop_max,
                        val_gamma,
                        val_center,
                        val_scale);
            if(ER != ER_okay)
            {
                MA_tmp_ComplexHandeled.release();
                return ER;
            }
        }

        merge(
                    MA_tmp_proc,
                    MA_tmp_ComplexHandeled.channels(),
                    *pMA_Out);

        for(int c = 0; c < MA_tmp_ComplexHandeled.channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_proc[c].release();
        }
    }
        break;

    case 3:
    {
        Mat MA_tmp_in[3];
        split(
                    MA_tmp_ComplexHandeled,
                    MA_tmp_in);

        Mat MA_tmp_proc[3];
        for(int c = 0; c < MA_tmp_ComplexHandeled.channels(); c++)
        {
            int ER = Visualize_to8bit_1C(
                        &(MA_tmp_proc[c]),
                        &(MA_tmp_in[c]),
                        mode_trafo,
                        mode_anchor,
                        mode_range,
                        val_anchor,
                        val_range,
                        crop_min,
                        crop_max,
                        val_gamma,
                        val_center,
                        val_scale);
            if(ER != ER_okay)
            {
                MA_tmp_ComplexHandeled.release();
                return ER;
            }
        }

        merge(
                    MA_tmp_proc,
                    MA_tmp_ComplexHandeled.channels(),
                    *pMA_Out);

        for(int c = 0; c < MA_tmp_ComplexHandeled.channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_proc[c].release();
        }
    }
        break;

    case 4:
    {
        Mat MA_tmp_in[4];
        split(
                    MA_tmp_ComplexHandeled,
                    MA_tmp_in);

        Mat MA_tmp_proc[4];
        for(int c = 0; c < MA_tmp_ComplexHandeled.channels(); c++)
        {
            int ER = Visualize_to8bit_1C(
                        &(MA_tmp_proc[c]),
                        &(MA_tmp_in[c]),
                        mode_trafo,
                        mode_anchor,
                        mode_range,
                        val_anchor,
                        val_range,
                        crop_min,
                        crop_max,
                        val_gamma,
                        val_center,
                        val_scale);
            if(ER != ER_okay)
            {
                MA_tmp_ComplexHandeled.release();
                return ER;
            }
        }

        merge(
                    MA_tmp_proc,
                    MA_tmp_ComplexHandeled.channels(),
                    *pMA_Out);

        for(int c = 0; c < MA_tmp_ComplexHandeled.channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_proc[c].release();
        }
    }
        break;

    default:
        break;
    }

    return ER_okay;
}

int D_Img_Proc::Visualize_to8bit_1C(Mat *pMA_Out, Mat *pMA_In, int mode_trafo, int mode_anchor, int mode_range, double val_anchor, double val_range, double crop_min, double crop_max, double val_gamma, double val_center, double val_scale)
{
    //errors
    if(pMA_In->empty())                                                         return ER_empty;
    if(pMA_In->channels() != 1)                                                 return ER_empty;
    if(mode_anchor < 0 || mode_anchor >= c_VIS_TRAFO_ANCHOR_NUMBER_OF)          return ER_parameter_bad;
    if(mode_trafo < 0  || mode_trafo  >= c_VIS_TRAFO_NUMBER_OF)                 return ER_parameter_bad;
    if(mode_range < 0  || mode_range  >= c_VIS_TRAFO_RANGE_NUMBER_OF)           return ER_parameter_bad;

    //qDebug() << "Visualize_to8bit_1C min/max passed" << crop_min << crop_max;

    //function object to do the transformation
    function<double(double)> F_Trafo;
    switch (mode_trafo) {
    case c_VIS_TRAFO_LINEAR:    F_Trafo = D_Math::CopyValue();                                              break;
    case c_VIS_TRAFO_GAMMA:     F_Trafo = D_Math::GammaCorrect_to01(crop_min, crop_max, val_gamma);         break;
    case c_VIS_TRAFO_LOG:       F_Trafo = D_Math::Log_Centered(crop_min, crop_max, val_center, val_scale);  break;
    default:                                                                                                return ER_parameter_bad;}

    //Output range (assuming bijectivity and monotonous increase)
    double possible_after_trafo_min = F_Trafo(crop_min);
    double possible_after_trafo_max = F_Trafo(crop_max);
    //qDebug() << "Visualize_to8bit_1C min/max transformed range" << possible_after_trafo_min << possible_after_trafo_max;
    if(possible_after_trafo_min > possible_after_trafo_max)
        return ER_other;

    //anchor & range -> out limits to spread to 0-255
    double show_as000_min;
    double show_as255_max;
    if(mode_anchor == c_VIS_TRAFO_ANCHOR_DYNAMIC && mode_range == c_VIS_TRAFO_RANGE_DYNAMIC)
    {
        show_as000_min = possible_after_trafo_min;
        show_as255_max = possible_after_trafo_max;
    }
    else if(mode_anchor == c_VIS_TRAFO_ANCHOR_DYNAMIC && mode_range == c_VIS_TRAFO_RANGE_FIXED)
    {
        double center = (possible_after_trafo_min + possible_after_trafo_max) / 2.0;
        show_as000_min = center - val_range/2.0;
        show_as255_max = center + val_range/2.0;
    }
    else if(mode_anchor == c_VIS_TRAFO_ANCHOR_BLACK && mode_range == c_VIS_TRAFO_RANGE_DYNAMIC)
    {
        show_as000_min = val_anchor;
        show_as255_max = possible_after_trafo_max;
    }
    else if(mode_anchor == c_VIS_TRAFO_ANCHOR_BLACK && mode_range == c_VIS_TRAFO_RANGE_FIXED)
    {
        show_as000_min = val_anchor;
        show_as255_max = val_anchor + val_range;
    }
    else if(mode_anchor == c_VIS_TRAFO_ANCHOR_WHITE && mode_range == c_VIS_TRAFO_RANGE_DYNAMIC)
    {
        show_as000_min = possible_after_trafo_min;
        show_as255_max = val_anchor;
    }
    else if(mode_anchor == c_VIS_TRAFO_ANCHOR_WHITE && mode_range == c_VIS_TRAFO_RANGE_FIXED)
    {
        show_as000_min = val_anchor - val_range;
        show_as255_max = val_anchor;
    }
    else if(mode_anchor == c_VIS_TRAFO_ANCHOR_CENTER && mode_range == c_VIS_TRAFO_RANGE_DYNAMIC)
    {
        double center2min = abs(val_anchor - possible_after_trafo_min);
        double center2max = abs(val_anchor - possible_after_trafo_max);
        double dist_max = center2min < center2max ? center2max : center2min;
        show_as000_min = val_anchor - dist_max;
        show_as255_max = val_anchor + dist_max;
    }
    else if(mode_anchor == c_VIS_TRAFO_ANCHOR_CENTER && mode_range == c_VIS_TRAFO_RANGE_FIXED)
    {
        show_as000_min = val_anchor - val_range/2.0;
        show_as255_max = val_anchor + val_range/2.0;
    }
    else
        return ER_parameter_missmatch;

    //qDebug() << "Visualize_to8bit_1C min/max after anchor & range" << show_as000_min << show_as255_max;

    //transformation & range management function object
    function<uchar(double)> F_Trafo8bit = D_Math::Spread_2_8bit(show_as000_min, show_as255_max, F_Trafo);

    //size & init
    int area        = pMA_In->rows * pMA_In->cols;
    *pMA_Out        = Mat::zeros(pMA_In->size(), CV_8UC1);
    uchar* ptr_out  = reinterpret_cast<uchar*>(pMA_Out->data);

    //transform
    switch (pMA_In->type()) {

    case CV_8UC1://==============================================================
    {
        uchar* ptr_in = reinterpret_cast<uchar*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = F_Trafo8bit(*ptr_in);
    }
        break;

    case CV_8SC1://==============================================================
    {
        char* ptr_in = reinterpret_cast<char*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = F_Trafo8bit(*ptr_in);
    }
        break;

    case CV_16UC1://==============================================================
    {
        ushort* ptr_in = reinterpret_cast<ushort*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = F_Trafo8bit(*ptr_in);
    }
        break;

    case CV_16SC1://==============================================================
    {
        short* ptr_in = reinterpret_cast<short*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = F_Trafo8bit(*ptr_in);
    }
        break;

    case CV_32SC1://==============================================================
    {
        int* ptr_in = reinterpret_cast<int*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = F_Trafo8bit(*ptr_in);
    }
        break;

    case CV_32FC1://==============================================================
    {
        float* ptr_in = reinterpret_cast<float*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = F_Trafo8bit(*ptr_in);
    }
        break;

    case CV_64FC1://==============================================================
    {
        double* ptr_in = reinterpret_cast<double*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            *ptr_out = F_Trafo8bit(*ptr_in);
    }
        break;

    default:
        return ER_type_bad;
    }


    return ER_okay;
}



int D_Img_Proc::Crop_Rect_Rel(Mat *pMA_Out, Mat *pMA_In, double x1_rel, double y1_rel, double x2_rel, double y2_rel)
{
    int offset_x = 0;
    int offset_y = 0;
    int width = pMA_In->cols;
    int heigth = pMA_Out->cols;

    return Crop_Rect_Rel(
                pMA_Out,
                pMA_In,
                x1_rel,
                y1_rel,
                x2_rel,
                y2_rel,
                &offset_x,
                &offset_y,
                &width,
                &heigth);
}

int D_Img_Proc::Crop_Rect_Rel(Mat *pMA_Out, Mat *pMA_In, double x1_rel, double y1_rel, double x2_rel, double y2_rel, int *offset_x, int *offset_y, int *width, int *heigth)
{
    if(pMA_In->empty())                                             return ER_empty;
    if(x1_rel >= x2_rel || y1_rel >= y2_rel)                        return ER_parameter_missmatch;

    //-1 to get range from 0-100% and not 0-99%
    int x = x1_rel * (pMA_In->cols - 1);
    int y = y1_rel * (pMA_In->rows - 1);
    int w = (x2_rel - x1_rel) * (pMA_In->cols);
    int h = (y2_rel - y1_rel) * (pMA_In->rows);
    if(x < 0 || w <= 0 || y < 0 || h <= 0)                          return ER_size_bad;
    if(x >= pMA_In->cols || y >= pMA_In->rows)                      return ER_size_bad;
    if((x + w) > pMA_In->cols || (y + h) > pMA_In->rows)            return ER_size_bad;

    //imshow("full", *pMA_In);
    *pMA_Out = pMA_In->clone();
    *pMA_Out = (*pMA_Out)(Rect(x, y, w, h));
    //imshow("crop", *pMA_Out);

    (*offset_x) = x;
    (*offset_y) = y;
    (*width)    = w;
    (*heigth)   = h;

    return ER_okay;
}

int D_Img_Proc::Crop_Rect_Abs(Mat *pMA_Out, Mat *pMA_In, int x, int y, int width, int height)
{
    if(pMA_In->empty())                                         return ER_empty;
    if(x < 0 || y < 0)                                          return ER_size_bad;
    if(x + width > pMA_In->cols || y + height > pMA_In->rows)
    {
        qDebug() << "D_Img_Proc::Crop_Rect_Abs" << "Size w/h:" << pMA_In->cols << pMA_In->rows << "x/y/w/h" << x << y << width << height;
        return ER_size_missmatch;
    }

    *pMA_Out = pMA_In->clone();
    *pMA_Out = (*pMA_Out)(Rect(x, y, width, height)).clone();

    return ER_okay;
}

int D_Img_Proc::Crop_Rect_Rot(Mat *pMA_Out, Mat *pMA_In, int x, int y, int width, int height, double angle)
{
    if(pMA_In->empty())                         return ER_empty;
    if(x < 0 || y < 0)                          return ER_size_bad;
    if(width < 0 || height < 0)                 return ER_size_bad;
    if(x >= pMA_In->cols || y >= pMA_In->rows)  return ER_size_missmatch;

    //rot rect
    RotatedRect rrect(
                Point2f(x, y),
                Size2f(width, height),
                angle);

    return Crop_Rect_Rot(
                pMA_Out,
                pMA_In,
                rrect);
}

int D_Img_Proc::Crop_Rect_Rot(Mat *pMA_Out, Mat *pMA_In, RotatedRect rrect)
{
    if(pMA_In->empty())     return ER_empty;

    //Rotation Matrix
    Mat MA_tmp_rot = getRotationMatrix2D(
                Point2f(
                    rrect.center.y,
                    rrect.center.x),
                rrect.angle,
                1);

    //Rotate image
    Mat MA_tmp_img_rot;
    warpAffine(
                *pMA_In,
                MA_tmp_img_rot,
                MA_tmp_rot,
                Size2f(
                    pMA_In->cols,
                    pMA_In->rows));
    MA_tmp_rot.release();

    //crop bounding rect
    qDebug() << "Crop_Circle start: Crop_Rect_Abs";
    int ER = Crop_Rect_Abs(
                pMA_Out,
                &MA_tmp_img_rot,
                rrect.center.x - rrect.size.width  / 2,
                rrect.center.y - rrect.size.height / 2,
                rrect.size.width,
                rrect.size.height);
    MA_tmp_img_rot.release();

    return ER;
}

int D_Img_Proc::Crop_Circle(Mat *pMA_Out, Mat *pMA_In, int x, int y, int r)
{
    if(pMA_In->empty())                         return ER_empty;
    if(x < 0 || y < 0)                          return ER_size_bad;
    if(r <= 0)                                  return ER_parameter_bad;
    if(x >= pMA_In->cols || y >= pMA_In->rows)  return ER_size_missmatch;


    //create mask
    Mat MA_tmp_mask = Mat::zeros(
                pMA_In->size(),
                CV_8UC1);
    qDebug() << "Crop_Circle start: Draw_Circle";
    int ER = Draw_Circle(
                &MA_tmp_mask,
                x,
                y,
                r,
                255,
                1,
                true);
    if(ER != ER_okay)
    {
        MA_tmp_mask.release();
        qDebug() << "Crop_Circle failed: Draw_Circle";
        return ER;
    }


    //apply mask
    Mat MA_tmp_roi;
    qDebug() << "Crop_Circle start: Mask";
    ER = Mask(
                &MA_tmp_roi,
                pMA_In,
                &MA_tmp_mask);
    MA_tmp_mask.release();
    if(ER != ER_okay)
    {
        MA_tmp_roi.release();
        qDebug() << "Crop_Circle failed: Mask";
        return ER;
    }


    //crop bounding rect
    qDebug() << "Crop_Circle start: Crop_Rect_Abs";
    ER = Crop_Rect_Abs(
                pMA_Out,
                &MA_tmp_roi,
                x - r,
                y - r,
                2 * r + 1,
                2 * r + 1);
    MA_tmp_roi.release();
    if(ER != ER_okay)
    {
        qDebug() << "Crop_Circle failed: Crop_Rect_Abs";
    }

    return ER;
}

int D_Img_Proc::Zoom(Mat *pMA_Out, Mat *pMA_In, double x_rel, double y_rel, double factor)
{
    int offset_x = 0;
    int offset_y = 0;
    int width = pMA_In->cols;
    int heigth = pMA_Out->cols;

    return Zoom(
                pMA_Out,
                pMA_In,
                x_rel,
                y_rel,
                factor,
                &offset_x,
                &offset_y,
                &width,
                &heigth);
}

int D_Img_Proc::Zoom(Mat *pMA_Out, Mat *pMA_In, double x_rel, double y_rel, double factor, int *offset_x, int *offset_y, int *width, int *heigth)
{
    if(pMA_In->empty())                 return ER_empty;

    //make sure range fits
    if(factor < 0)  factor = 0;
    if(factor > 1)  factor = 1;
    if(x_rel < 0)  x_rel = 0;
    if(x_rel > 1)  x_rel = 1;
    if(y_rel < 0)  y_rel = 0;
    if(y_rel > 1)  y_rel = 1;

    //rel area
    double x1_rel       = x_rel - (factor / 2.0);
    double x2_rel       = x_rel + (factor / 2.0);
    double y1_rel       = y_rel - (factor / 2.0);
    double y2_rel       = y_rel + (factor / 2.0);

    //force in range
    if(x1_rel < 0)      {x1_rel = 0;            x2_rel = factor;}
    if(x2_rel > 1)      {x1_rel = 1 - factor;   x2_rel = 1;     }
    if(y1_rel < 0)      {y1_rel = 0;            y2_rel = factor;}
    if(y2_rel > 1)      {y1_rel = 1 - factor;   y2_rel = 1;     }

    //crop
    return Crop_Rect_Rel(
                pMA_Out,
                pMA_In,
                x1_rel,
                y1_rel,
                x2_rel,
                y2_rel,
                offset_x,
                offset_y,
                width,
                heigth);
}



int D_Img_Proc::Padding(Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y, int type)
{
    return Padding(
                pMA_Out,
                pMA_In,
                size_x,
                size_x,
                size_y,
                size_y,
                type);
}

int D_Img_Proc::Padding(Mat *pMA_Out, Mat *pMA_In, int right, int left, int top, int bottom, int type)
{
    if(pMA_In->empty()) return ER_empty;

    switch (pMA_In->channels()) {

    case 1:
    {
        int ER = Padding_1C(
                    pMA_Out,
                    pMA_In,
                    right,
                    left,
                    top,
                    bottom,
                    type);
        if(ER != ER_okay)   return ER;
    }
        break;

    case 2:
    {
        Mat MA_tmp_in[2];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_padded[2];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Padding_1C(
                        &(MA_tmp_padded[c]),
                        &(MA_tmp_in[c]),
                        right,
                        left,
                        top,
                        bottom,
                        type);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_padded,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_padded[c].release();
        }
    }
        break;

    case 3:
    {
        Mat MA_tmp_in[3];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_padded[3];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Padding_1C(
                        &(MA_tmp_padded[c]),
                        &(MA_tmp_in[c]),
                        right,
                        left,
                        top,
                        bottom,
                        type);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_padded,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_padded[c].release();
        }
    }
        break;

    case 4:
    {
        Mat MA_tmp_in[4];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_padded[4];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Padding_1C(
                        &(MA_tmp_padded[c]),
                        &(MA_tmp_in[c]),
                        right,
                        left,
                        top,
                        bottom,
                        type);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_padded,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_padded[c].release();
        }
    }
        break;

    default:
        break;
    }

    return ER_okay;
}

int D_Img_Proc::Padding_1C(Mat *pMA_Out, Mat *pMA_In, int right, int left, int top, int bottom, int type)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->channels() != 1)     return ER_channel_bad;
    if(right < 0)                   return ER_parameter_bad;
    if(left < 0)                    return ER_parameter_bad;
    if(top < 0)                     return ER_parameter_bad;
    if(bottom < 0)                  return ER_parameter_bad;

    copyMakeBorder(
                *pMA_In,
                *pMA_Out,
                top,
                bottom,
                left,
                right,
                type);

    return ER_okay;
}

int D_Img_Proc::ForceSize(Mat *pMA_Out, Mat *pMA_In, int width, int heigth, int border_type)
{
    //qDebug() << "D_Img_Proc::ForceSize" << "start";
    if(pMA_In->empty())         {qDebug() << "D_Img_Proc::ForceSize" << "ER_empty";             return ER_empty;}
    if(width < 1 || heigth < 1) {qDebug() << "D_Img_Proc::ForceSize" << "ER_parameter_bad";     return ER_parameter_bad;}
    int ER;
    //qDebug() << "D_Img_Proc::ForceSize" << "error checks passed";

    //fit
    if(pMA_In->rows == heigth && pMA_In->cols == width)
    {
        //qDebug() << "D_Img_Proc::ForceSize" << "fit";
        return Duplicate(pMA_Out, pMA_In);
    }

    //bigger and/or fitting in up to one dim
    if(pMA_In->rows >= heigth && pMA_In->cols >= width)
    {
        //qDebug() << "D_Img_Proc::ForceSize" << "bigger and/or fitting in up to one dim";
        return Crop_Rect_Abs(pMA_Out, pMA_In, 0, 0, width, heigth);
    }

    //smaller and/or fitting in up to one dim
    if(pMA_In->rows <= heigth && pMA_In->cols <= width)
    {
        //qDebug() << "D_Img_Proc::ForceSize" << "smaller and/or fitting in up to one dim";
        return Padding(pMA_Out, pMA_In, width - pMA_In->cols, 0, 0, heigth - pMA_In->rows, border_type);
    }

    //bigger in width, smaller in height
    if(pMA_In->rows <= heigth && pMA_In->cols >= width)
    {
        //qDebug() << "D_Img_Proc::ForceSize" << "bigger in width, smaller in height";
        Mat MA_tmp_croped;
        ER = Crop_Rect_Abs(&MA_tmp_croped, pMA_In, 0, 0, width, pMA_In->rows);
        if(ER != ER_okay) {MA_tmp_croped.release(); return ER;}
        ER = Padding(pMA_Out, &MA_tmp_croped, 0, 0, 0, heigth - MA_tmp_croped.rows, border_type);
        MA_tmp_croped.release();
        return ER;
    }

    //bigger in height, smaller in width
    if(pMA_In->rows >= heigth && pMA_In->cols <= width)
    {
        //qDebug() << "D_Img_Proc::ForceSize" << "bigger in height, smaller in width";
        Mat MA_tmp_croped;
        ER = Crop_Rect_Abs(&MA_tmp_croped, pMA_In, 0, 0, pMA_In->cols, heigth);
        if(ER != ER_okay) {MA_tmp_croped.release(); return ER;}
        ER = Padding(pMA_Out, &MA_tmp_croped, width - MA_tmp_croped.cols, 0, 0, 0, border_type);
        MA_tmp_croped.release();
        return ER;
    }

    //qDebug() << "D_Img_Proc::ForceSize" << "failed";
    return ER_size_missmatch;
}

int D_Img_Proc::Stitch_Border_abs(Mat *pMA_Out, Mat *pMA_In_Main, Mat *pMA_In_R, Mat *pMA_In_B, Mat *pMA_In_BR, int border_R, int border_B, int overlap_R, int overlap_B, Stitcher::Mode mode)
{
    //qDebug() << "D_Img_Proc::Stitch_Border_abs" << "start";

    //Errors
    if(pMA_In_Main->empty())                        return ER_empty;
    if(pMA_In_R->empty())                           return ER_empty;
    if(pMA_In_B->empty())                           return ER_empty;
    if(pMA_In_BR->empty())                          return ER_empty;
    if(pMA_In_Main->type() != pMA_In_R->type())     return ER_type_missmatch;
    if(pMA_In_Main->type() != pMA_In_B->type())     return ER_type_missmatch;
    if(pMA_In_Main->type() != pMA_In_BR->type())    return ER_type_missmatch;
    if(pMA_In_Main->rows != pMA_In_R->rows)         return ER_size_missmatch;
    if(pMA_In_Main->cols != pMA_In_B->cols)         return ER_size_missmatch;
    if(border_R < 0 || border_B < 0)                return ER_parameter_bad;
    if(overlap_R < 0 || overlap_B < 0)              return ER_parameter_bad;
    if(pMA_In_R->cols < border_R + overlap_R)       return ER_size_missmatch;
    if(pMA_In_BR->cols < border_R + overlap_R)      return ER_size_missmatch;
    if(pMA_In_B->rows < border_B + overlap_B)       return ER_size_missmatch;
    if(pMA_In_BR->rows < border_B + overlap_B)      return ER_size_missmatch;

    //qDebug() << "D_Img_Proc::Stitch_Border_abs" << "Error checks passed";

    //cut images and store in vector
    vector<Mat> vMA_Cut(4);
    //Main
    vMA_Cut[0] = pMA_In_Main->clone();
    vMA_Cut[1] = pMA_In_R->clone();
    vMA_Cut[2] = pMA_In_B->clone();
    vMA_Cut[3] = pMA_In_BR->clone();

    //qDebug() << "D_Img_Proc::Stitch_Border_abs" << "croped images";

    //tmp output
    Mat MA_tmp_out;

    //Here the magic happens: OpenCV Stitcher
    Ptr<Stitcher> stitcher = Stitcher::create(mode);
    Stitcher::Status status = stitcher->stitch(vMA_Cut, MA_tmp_out);
    //qDebug() << "D_Img_Proc::Stitch_Border_abs" << "stitcher done";

    //clear img vector
    vMA_Cut.clear();

    //check stitcher success
    if (status == Stitcher::OK)
    {
        //qDebug() << "D_Img_Proc::Stitch_Border_abs" << "stitcher success size(y/x):" << MA_tmp_out.rows << MA_tmp_out.cols;
        int ER = ForceSize(
                    pMA_Out,
                    &MA_tmp_out,
                    pMA_In_Main->cols + border_R,
                    pMA_In_Main->rows + border_B,
                    cv::BORDER_CONSTANT);
        MA_tmp_out.release();
        //qDebug() << "D_Img_Proc::Stitch_Border_abs" << "size forced(y/x):" << pMA_Out->rows << pMA_Out->cols;
        if(ER == ER_okay)
            return ER;
    }
    else
    {
        //qDebug() << "D_Img_Proc::Stitch_Border_abs" << "stitcher failed";

        //error check
        switch (status) {
        case Stitcher::ERR_NEED_MORE_IMGS:              qDebug() << "Stitch_Border_abs" << "ERR_NEED_MORE_IMGS";            break;
        case Stitcher::ERR_HOMOGRAPHY_EST_FAIL:         qDebug() << "Stitch_Border_abs" << "ERR_HOMOGRAPHY_EST_FAIL";       break;
        case Stitcher::ERR_CAMERA_PARAMS_ADJUST_FAIL:   qDebug() << "Stitch_Border_abs" << "ERR_CAMERA_PARAMS_ADJUST_FAIL"; break;
        default:                                        qDebug() << "Stitch_Border_abs" << "other";                         break;}
    }

    //if failed, try custom approach
    return Stitch_Border_abs_custom(
                pMA_Out,
                pMA_In_Main,
                pMA_In_R,
                pMA_In_B,
                pMA_In_BR,
                border_R,
                border_B,
                overlap_R,
                overlap_B);
}

int D_Img_Proc::Stitch_Border_rel(Mat *pMA_Out, Mat *pMA_In_Main, Mat *pMA_In_R, Mat *pMA_In_B, Mat *pMA_In_BR, double border_R, double border_B, double overlap_R, double overlap_B, Stitcher::Mode mode)
{
    if(pMA_In_Main->empty())                        return ER_empty;
    if(pMA_In_R->empty())                           return ER_empty;
    if(pMA_In_B->empty())                           return ER_empty;
    if(pMA_In_BR->empty())                          return ER_empty;

    //qDebug() << "D_Img_Proc::Stitch_Border_rel" << "call D_Img_Proc::Stitch_Border_abs with border(R/B)" <<  border_R * pMA_In_Main->cols << border_B * pMA_In_Main->rows << "and overlap(R/B)" << overlap_R * pMA_In_Main->cols << overlap_B * pMA_In_Main->rows;
    return Stitch_Border_abs(
                pMA_Out,
                pMA_In_Main,
                pMA_In_R,
                pMA_In_B,
                pMA_In_BR,
                static_cast<int>(border_R * pMA_In_Main->cols),
                static_cast<int>(border_B * pMA_In_Main->rows),
                static_cast<int>(overlap_R * pMA_In_Main->cols),
                static_cast<int>(overlap_B * pMA_In_Main->rows),
                mode);
}

int D_Img_Proc::Stitch_Border_abs_custom(Mat *pMA_Out, Mat *pMA_In_Main, Mat *pMA_In_R, Mat *pMA_In_B, Mat *pMA_In_BR, int border_R, int border_B, int overlap_R, int overlap_B)
{
    //Errors
    if(pMA_In_Main->empty())                        return ER_empty;
    if(pMA_In_R->empty())                           return ER_empty;
    if(pMA_In_B->empty())                           return ER_empty;
    if(pMA_In_BR->empty())                          return ER_empty;
    if(pMA_In_Main->type() != pMA_In_R->type())     return ER_type_missmatch;
    if(pMA_In_Main->type() != pMA_In_B->type())     return ER_type_missmatch;
    if(pMA_In_Main->type() != pMA_In_BR->type())    return ER_type_missmatch;
    if(pMA_In_Main->rows != pMA_In_R->rows)         return ER_size_missmatch;
    if(pMA_In_Main->cols != pMA_In_B->cols)         return ER_size_missmatch;
    if(border_R < 0 || border_B < 0)                return ER_parameter_bad;
    if(overlap_R < 0 || overlap_B < 0)              return ER_parameter_bad;
    if(pMA_In_R->cols < border_R + overlap_R)       return ER_size_missmatch;
    if(pMA_In_BR->cols < border_R + overlap_R)      return ER_size_missmatch;
    if(pMA_In_B->rows < border_B + overlap_B)       return ER_size_missmatch;
    if(pMA_In_BR->rows < border_B + overlap_B)      return ER_size_missmatch;

    //Do simple alternative
    //qDebug() << "D_Img_Proc::Stitch_Border_abs_custom" << "do manual approach";

    //init out
    *pMA_Out = Mat::zeros(pMA_In_Main->rows + border_B, pMA_In_Main->cols + border_R, pMA_In_Main->type());
    //qDebug() << "D_Img_Proc::Stitch_Border_abs_custom" << "Mat init size(y/x):" << pMA_Out->rows << pMA_Out->cols;

    //loop
    switch (pMA_In_Main->type()) {

    case CV_8UC1:
        for(int y = 0; y < pMA_Out->rows; y++)
            for(int x = 0; x < pMA_Out->cols; x++)
            {
                if(y < pMA_In_Main->rows && x < pMA_In_Main->cols)
                    pMA_Out->at<uchar>(y, x) = pMA_In_Main->at<uchar>(y, x);
                else if(y < pMA_In_Main->rows && x >= pMA_In_Main->cols)
                    pMA_Out->at<uchar>(y, x) = pMA_In_R->at<uchar>(y, x - pMA_In_Main->cols + overlap_R);
                else if(y >= pMA_In_Main->rows && x < pMA_In_Main->cols)
                    pMA_Out->at<uchar>(y, x) = pMA_In_B->at<uchar>(y - pMA_In_Main->rows + overlap_B, x);
                else
                    pMA_Out->at<uchar>(y, x) = pMA_In_BR->at<uchar>(y - pMA_In_Main->rows + overlap_B, x - pMA_In_Main->cols + overlap_R);
            }
    break;

    case CV_8SC1:
        for(int y = 0; y < pMA_Out->rows; y++)
            for(int x = 0; x < pMA_Out->cols; x++)
            {
                if(y < pMA_In_Main->rows && x < pMA_In_Main->cols)
                    pMA_Out->at<char>(y, x) = pMA_In_Main->at<char>(y, x);
                else if(y < pMA_In_Main->rows && x >= pMA_In_Main->cols)
                    pMA_Out->at<char>(y, x) = pMA_In_R->at<char>(y, x - pMA_In_Main->cols + overlap_R);
                else if(y >= pMA_In_Main->rows && x < pMA_In_Main->cols)
                    pMA_Out->at<char>(y, x) = pMA_In_B->at<char>(y - pMA_In_Main->rows + overlap_B, x);
                else
                    pMA_Out->at<char>(y, x) = pMA_In_BR->at<char>(y - pMA_In_Main->rows + overlap_B, x - pMA_In_Main->cols + overlap_R);
            }
    break;

    case CV_16UC1:
        for(int y = 0; y < pMA_Out->rows; y++)
            for(int x = 0; x < pMA_Out->cols; x++)
            {
                if(y < pMA_In_Main->rows && x < pMA_In_Main->cols)
                    pMA_Out->at<ushort>(y, x) = pMA_In_Main->at<ushort>(y, x);
                else if(y < pMA_In_Main->rows && x >= pMA_In_Main->cols)
                    pMA_Out->at<ushort>(y, x) = pMA_In_R->at<ushort>(y, x - pMA_In_Main->cols + overlap_R);
                else if(y >= pMA_In_Main->rows && x < pMA_In_Main->cols)
                    pMA_Out->at<ushort>(y, x) = pMA_In_B->at<ushort>(y - pMA_In_Main->rows + overlap_B, x);
                else
                    pMA_Out->at<ushort>(y, x) = pMA_In_BR->at<ushort>(y - pMA_In_Main->rows + overlap_B, x - pMA_In_Main->cols + overlap_R);
            }
    break;

    case CV_16SC1:
        for(int y = 0; y < pMA_Out->rows; y++)
            for(int x = 0; x < pMA_Out->cols; x++)
            {
                if(y < pMA_In_Main->rows && x < pMA_In_Main->cols)
                    pMA_Out->at<short>(y, x) = pMA_In_Main->at<short>(y, x);
                else if(y < pMA_In_Main->rows && x >= pMA_In_Main->cols)
                    pMA_Out->at<short>(y, x) = pMA_In_R->at<short>(y, x - pMA_In_Main->cols + overlap_R);
                else if(y >= pMA_In_Main->rows && x < pMA_In_Main->cols)
                    pMA_Out->at<short>(y, x) = pMA_In_B->at<short>(y - pMA_In_Main->rows + overlap_B, x);
                else
                    pMA_Out->at<short>(y, x) = pMA_In_BR->at<short>(y - pMA_In_Main->rows + overlap_B, x - pMA_In_Main->cols + overlap_R);
            }
    break;

    case CV_32SC1:
        for(int y = 0; y < pMA_Out->rows; y++)
            for(int x = 0; x < pMA_Out->cols; x++)
            {
                if(y < pMA_In_Main->rows && x < pMA_In_Main->cols)
                    pMA_Out->at<int>(y, x) = pMA_In_Main->at<int>(y, x);
                else if(y < pMA_In_Main->rows && x >= pMA_In_Main->cols)
                    pMA_Out->at<int>(y, x) = pMA_In_R->at<int>(y, x - pMA_In_Main->cols + overlap_R);
                else if(y >= pMA_In_Main->rows && x < pMA_In_Main->cols)
                    pMA_Out->at<int>(y, x) = pMA_In_B->at<int>(y - pMA_In_Main->rows + overlap_B, x);
                else
                    pMA_Out->at<int>(y, x) = pMA_In_BR->at<int>(y - pMA_In_Main->rows + overlap_B, x - pMA_In_Main->cols + overlap_R);
            }
    break;

    case CV_32FC1:
        for(int y = 0; y < pMA_Out->rows; y++)
            for(int x = 0; x < pMA_Out->cols; x++)
            {
                if(y < pMA_In_Main->rows && x < pMA_In_Main->cols)
                    pMA_Out->at<float>(y, x) = pMA_In_Main->at<float>(y, x);
                else if(y < pMA_In_Main->rows && x >= pMA_In_Main->cols)
                    pMA_Out->at<float>(y, x) = pMA_In_R->at<float>(y, x - pMA_In_Main->cols + overlap_R);
                else if(y >= pMA_In_Main->rows && x < pMA_In_Main->cols)
                    pMA_Out->at<float>(y, x) = pMA_In_B->at<float>(y - pMA_In_Main->rows + overlap_B, x);
                else
                    pMA_Out->at<float>(y, x) = pMA_In_BR->at<float>(y - pMA_In_Main->rows + overlap_B, x - pMA_In_Main->cols + overlap_R);
            }
    break;

    case CV_64FC1:
        for(int y = 0; y < pMA_Out->rows; y++)
            for(int x = 0; x < pMA_Out->cols; x++)
            {
                if(y < pMA_In_Main->rows && x < pMA_In_Main->cols)
                    pMA_Out->at<double>(y, x) = pMA_In_Main->at<double>(y, x);
                else if(y < pMA_In_Main->rows && x >= pMA_In_Main->cols)
                    pMA_Out->at<double>(y, x) = pMA_In_R->at<double>(y, x - pMA_In_Main->cols + overlap_R);
                else if(y >= pMA_In_Main->rows && x < pMA_In_Main->cols)
                    pMA_Out->at<double>(y, x) = pMA_In_B->at<double>(y - pMA_In_Main->rows + overlap_B, x);
                else
                    pMA_Out->at<double>(y, x) = pMA_In_BR->at<double>(y - pMA_In_Main->rows + overlap_B, x - pMA_In_Main->cols + overlap_R);
            }
    break;

    case CV_8UC3:
        for(int y = 0; y < pMA_Out->rows; y++)
            for(int x = 0; x < pMA_Out->cols; x++)
            {
                if(y < pMA_In_Main->rows && x < pMA_In_Main->cols)
                    pMA_Out->at<Vec3b>(y, x) = pMA_In_Main->at<Vec3b>(y, x);
                else if(y < pMA_In_Main->rows && x >= pMA_In_Main->cols)
                    pMA_Out->at<Vec3b>(y, x) = pMA_In_R->at<Vec3b>(y, x - pMA_In_Main->cols + overlap_R);
                else if(y >= pMA_In_Main->rows && x < pMA_In_Main->cols)
                    pMA_Out->at<Vec3b>(y, x) = pMA_In_B->at<Vec3b>(y - pMA_In_Main->rows + overlap_B, x);
                else
                    pMA_Out->at<Vec3b>(y, x) = pMA_In_BR->at<Vec3b>(y - pMA_In_Main->rows + overlap_B, x - pMA_In_Main->cols + overlap_R);
            }
    break;

    default:
        return ER_type_bad;
    }

    //qDebug() << "D_Img_Proc::Stitch_Border_abs_custom" << "manual approach end";
    return ER_okay;
}

int D_Img_Proc::Stitch_Border_rel_custom(Mat *pMA_Out, Mat *pMA_In_Main, Mat *pMA_In_R, Mat *pMA_In_B, Mat *pMA_In_BR, double border_R, double border_B, double overlap_R, double overlap_B)
{
    if(pMA_In_Main->empty())                        return ER_empty;
    if(pMA_In_R->empty())                           return ER_empty;
    if(pMA_In_B->empty())                           return ER_empty;
    if(pMA_In_BR->empty())                          return ER_empty;

    return Stitch_Border_abs_custom(
                pMA_Out,
                pMA_In_Main,
                pMA_In_R,
                pMA_In_B,
                pMA_In_BR,
                static_cast<int>(border_R * pMA_In_Main->cols),
                static_cast<int>(border_B * pMA_In_Main->rows),
                static_cast<int>(overlap_R * pMA_In_Main->cols),
                static_cast<int>(overlap_B * pMA_In_Main->rows));
}

int D_Img_Proc::Scale_Factor(Mat *pMA_Out, Mat *pMA_In, double scale_x, double scale_y)
{
    if(pMA_In->empty())             return ER_empty;

    resize(
                *pMA_In,
                *pMA_Out,
                cv::Size(),
                scale_x,
                scale_y);

    return ER_okay;
}

int D_Img_Proc::Scale_ToSize(Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y)
{
    if(pMA_In->empty())             return ER_empty;
    if(size_x < 0)                  return ER_parameter_bad;
    if(size_y < 0)                  return ER_parameter_bad;

        resize(
                    *pMA_In,
                    *pMA_Out,
                    cv::Size(
                        size_x,
                        size_y));

        return ER_okay;
}

int D_Img_Proc::Threshold_Relative(Mat *pMA_Out, Mat *pMA_In, double max_val, double thres_rel)
{
    if(pMA_In->empty()) return ER_empty;

    switch (pMA_In->channels()) {

    case 1:
    {
        int ER = Threshold_Relative_1C(
                    pMA_Out,
                    pMA_In,
                    max_val,
                    thres_rel);
        if(ER != ER_okay)   return ER;
    }
        break;

    case 2:
    {
        Mat MA_tmp_in[2];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_thres[2];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Threshold_Relative_1C(
                        &(MA_tmp_thres[c]),
                        &(MA_tmp_in[c]),
                        max_val,
                        thres_rel);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_thres,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_thres[c].release();
        }
    }
        break;

    case 3:
    {
        Mat MA_tmp_in[3];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_thres[3];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Threshold_Relative_1C(
                        &(MA_tmp_thres[c]),
                        &(MA_tmp_in[c]),
                        max_val,
                        thres_rel);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_thres,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_thres[c].release();
        }
    }
        break;

    case 4:
    {
        Mat MA_tmp_in[4];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_thres[4];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Threshold_Relative_1C(
                        &(MA_tmp_thres[c]),
                        &(MA_tmp_in[c]),
                        max_val,
                        thres_rel);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_thres,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_thres[c].release();
        }
    }
        break;

    default:
        break;
    }

    return ER_okay;
}

int D_Img_Proc::Threshold_Relative_1C(Mat *pMA_Out, Mat *pMA_In, double max_val, double thres_rel)
{
    if(pMA_In->empty())                     return ER_empty;
    if(pMA_In->channels() != 1)             return ER_channel_bad;

    //absolute Thres
    double thres    = max_val * thres_rel;

    //output image
    *pMA_Out        = Mat::zeros(pMA_In->size(), CV_8UC1);
    uchar* ptr_out  = reinterpret_cast<uchar*>(pMA_Out->data);

    //size
    int area = pMA_In->rows * pMA_In->cols;

    //apply thres
    switch (pMA_In->type()) {

    case CV_8UC1://==============================================================
    {
        uchar* ptr_in = reinterpret_cast<uchar*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if((*ptr_in) > thres)
                *ptr_out = static_cast<uchar>(255);
    }
        break;

    case CV_8SC1://==============================================================
    {
        schar* ptr_in = reinterpret_cast<schar*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if((*ptr_in) > thres)
                *ptr_out = static_cast<schar>(127);
    }
        break;

    case CV_16UC1://=============================================================
    {
        ushort* ptr_in = reinterpret_cast<ushort*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if((*ptr_in) > thres)
                *ptr_out = static_cast<ushort>(255);
    }
        break;

    case CV_16SC1://============================================================
    {
        short* ptr_in = reinterpret_cast<short*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if((*ptr_in) > thres)
                *ptr_out = static_cast<short>(255);
    }
        break;

    case CV_32SC1://=============================================================
    {
        int* ptr_in = reinterpret_cast<int*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if((*ptr_in) > thres)
                *ptr_out = static_cast<int>(255);
    }
        break;

    case CV_32FC1://==============================================================
    {
        float* ptr_in = reinterpret_cast<float*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if((*ptr_in) > thres)
                *ptr_out = static_cast<float>(255);
    }
        break;

    case CV_64FC1://=============================================================
    {
        double* ptr_in = reinterpret_cast<double*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if((*ptr_in) > thres)
                *ptr_out = static_cast<double>(255);
    }
        break;

    default:
        return ER_bitdepth_bad;
    }

    return ER_okay;
}

int D_Img_Proc::Threshold_Absolute(Mat *pMA_Out, Mat *pMA_In, double thres_abs)
{
    if(pMA_In->empty()) return ER_empty;

    switch (pMA_In->channels()) {

    case 1:
    {
        int ER = Threshold_Absolute_1C(
                    pMA_Out,
                    pMA_In,
                    thres_abs);
        if(ER != ER_okay)   return ER;
    }
        break;

    case 2:
    {
        Mat MA_tmp_in[2];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_thres[2];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Threshold_Absolute_1C(
                        &(MA_tmp_thres[c]),
                        &(MA_tmp_in[c]),
                        thres_abs);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_thres,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_thres[c].release();
        }
    }
        break;

    case 3:
    {
        Mat MA_tmp_in[3];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_thres[3];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Threshold_Absolute_1C(
                        &(MA_tmp_thres[c]),
                        &(MA_tmp_in[c]),
                        thres_abs);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_thres,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_thres[c].release();
        }
    }
        break;

    case 4:
    {
        Mat MA_tmp_in[4];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_thres[4];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Threshold_Absolute_1C(
                        &(MA_tmp_thres[c]),
                        &(MA_tmp_in[c]),
                        thres_abs);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_thres,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_thres[c].release();
        }
    }
        break;

    default:
        break;
    }

    return ER_okay;
}

int D_Img_Proc::Threshold_Absolute_1C(Mat *pMA_Out, Mat *pMA_In, double thres_abs)
{
    if(pMA_In->empty())                     return ER_empty;
    if(pMA_In->channels() != 1)             return ER_channel_bad;

    //output image
    *pMA_Out        = Mat::zeros(pMA_In->size(), CV_8UC1);
    uchar* ptr_out  = reinterpret_cast<uchar*>(pMA_Out->data);

    //size
    int area = pMA_In->rows * pMA_In->cols;

    //apply thres
    switch (pMA_In->type()) {

    case CV_8UC1://==============================================================
    {
        uchar* ptr_in = reinterpret_cast<uchar*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if((*ptr_in) > thres_abs)
                *ptr_out = 255;
    }
        break;

    case CV_8SC1://==============================================================
    {
        schar* ptr_in = reinterpret_cast<schar*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if((*ptr_in) > thres_abs)
                *ptr_out = 255;
    }
        break;

    case CV_16UC1://=============================================================
    {
        ushort* ptr_in = reinterpret_cast<ushort*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if((*ptr_in) > thres_abs)
                *ptr_out = 255;
    }
        break;

    case CV_16SC1://============================================================
    {
        short* ptr_in = reinterpret_cast<short*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if((*ptr_in) > thres_abs)
                *ptr_out = 255;
    }
        break;

    case CV_32SC1://=============================================================
    {
        int* ptr_in = reinterpret_cast<int*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if((*ptr_in) > thres_abs)
                *ptr_out = 255;
    }
        break;

    case CV_32FC1://==============================================================
    {
        float* ptr_in = reinterpret_cast<float*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if((*ptr_in) > thres_abs)
                *ptr_out = 255;
    }
        break;

    case CV_64FC1://=============================================================
    {
        double* ptr_in = reinterpret_cast<double*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if((*ptr_in) > thres_abs)
                *ptr_out = 255;
    }
        break;

    default:
        return ER_bitdepth_bad;
    }

    return ER_okay;
}

int D_Img_Proc::Threshold_Value(Mat *pMA_Out, Mat *pMA_In, int out_mode, double max_val, double thres)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->depth() != CV_8U)    return ER_bitdepth_bad;

    threshold(
                *pMA_In,
                *pMA_Out,
                thres,
                max_val,
                out_mode);

    return ER_okay;
}

int D_Img_Proc::Threshold_Auto(Mat *pMA_Out, Mat *pMA_In, int out_mode, double max_val, int auto_mode)
{
    if(pMA_In->empty())                                         return ER_empty;
    if(pMA_In->depth() != CV_8U)                                return ER_bitdepth_bad;
    if(auto_mode == CV_THRESH_OTSU && pMA_In->channels() > 1)   return ER_type_bad;

    threshold(
                *pMA_In,
                *pMA_Out,
                0,
                max_val,
                out_mode | auto_mode);

    return ER_okay;
}

int D_Img_Proc::Threshold_Adaptive(Mat *pMA_Out, Mat *pMA_In, int out_mode, double max_val, int adapt_mode, unsigned int mask_size, double offset)
{
    if(pMA_In->empty())                                                         return ER_empty;
    if(pMA_In->depth() != CV_8U)                                                return ER_bitdepth_bad;
    if(pMA_In->channels() > 1)                                                  return ER_channel_bad;
    if((out_mode != CV_THRESH_BINARY) && (out_mode != CV_THRESH_BINARY_INV))    return ER_type_bad;

    qDebug() << "Fix 2 * mask_size + 1 in D_Img_Proc::Threshold_Adaptive!!!!!!!!!!!";
    adaptiveThreshold(
                *pMA_In,
                *pMA_Out,
                max_val,
                adapt_mode,
                out_mode,
                2 * mask_size + 1,
                offset);

    return ER_okay;
}

int D_Img_Proc::Threshold_Adaptive_Gauss(Mat *pMA_Out, Mat *pMA_In, int size, double sigma, double offset, double scale)
{
    //multichannel vaersion will be added when needed
    return Threshold_Adaptive_Gauss_1C(
                pMA_Out,
                pMA_In,
                size,
                sigma,
                offset,
                scale);
}

/*!
 * \brief D_Img_Proc::Threshold_Adaptive_Gauss_1C lokall adaptive threshhold using comparison to gauss filtered image
 * \details Per pixel: (in + offset > blur(in, size, sigma)) ? 255 : 0
 * \param pMA_Out binary CV_8UC1 image
 * \param pMA_In 1C gray value image
 * \param size gauss filter size (must be odd)
 * \param sigma gauss filter sigma (>= 0)
 * \param offset comparision needed offset
 * \return error code
*/
int D_Img_Proc::Threshold_Adaptive_Gauss_1C(Mat *pMA_Out, Mat *pMA_In, int size, double sigma, double offset, double scale)
{
    if(pMA_In->empty())                     return ER_empty;
    if(pMA_In->channels() > 1)              return ER_channel_bad;
    if(size < 1)                            return ER_parameter_bad;
    if((size % 2) != 1)                     return ER_parameter_bad;
    if(sigma < 0)                           return ER_parameter_bad;
    int ER;

    Mat MA_tmp_Blur;
    ER = Filter_Gauss(
                &MA_tmp_Blur,
                pMA_In,
                size,
                size,
                BORDER_REPLICATE,
                sigma,
                sigma);
    if(ER != ER_okay)
    {
        MA_tmp_Blur.release();
        return ER;
    }

    size_t area = pMA_In->cols * pMA_In->rows;

    *pMA_Out = Mat::zeros(pMA_In->size(), CV_8UC1);

    switch (pMA_In->type()) {

    case CV_8UC1:
    {
        uchar* ptr_out      = reinterpret_cast<uchar*>(pMA_Out->data);
        uchar* ptr_in       = reinterpret_cast<uchar*>(pMA_In->data);
        uchar* ptr_blur     = reinterpret_cast<uchar*>(MA_tmp_Blur.data);
        for(size_t px = 0; px < area; px++, ptr_in++, ptr_out++, ptr_blur++)
            if((*ptr_in * scale) + offset > *ptr_blur)
                *ptr_out = 255;
    }
        break;

    case CV_8SC1:
    {
        uchar* ptr_out      = reinterpret_cast<uchar*>(pMA_Out->data);
        char* ptr_in        = reinterpret_cast<char*>(pMA_In->data);
        char* ptr_blur      = reinterpret_cast<char*>(MA_tmp_Blur.data);
        for(size_t px = 0; px < area; px++, ptr_in++, ptr_out++, ptr_blur++)
            if((*ptr_in * scale) + offset > *ptr_blur)
                *ptr_out = 255;
    }
        break;

    case CV_16UC1:
    {
        uchar* ptr_out      = reinterpret_cast<uchar*>(pMA_Out->data);
        ushort* ptr_in      = reinterpret_cast<ushort*>(pMA_In->data);
        ushort* ptr_blur    = reinterpret_cast<ushort*>(MA_tmp_Blur.data);
        for(size_t px = 0; px < area; px++, ptr_in++, ptr_out++, ptr_blur++)
            if((*ptr_in * scale) + offset > *ptr_blur)
                *ptr_out = 255;
    }
        break;

    case CV_16SC1:
    {
        uchar* ptr_out      = reinterpret_cast<uchar*>(pMA_Out->data);
        short* ptr_in       = reinterpret_cast<short*>(pMA_In->data);
        short* ptr_blur     = reinterpret_cast<short*>(MA_tmp_Blur.data);
        for(size_t px = 0; px < area; px++, ptr_in++, ptr_out++, ptr_blur++)
            if((*ptr_in * scale) + offset > *ptr_blur)
                *ptr_out = 255;
    }
        break;

    case CV_32SC1:
    {
        uchar* ptr_out      = reinterpret_cast<uchar*>(pMA_Out->data);
        int* ptr_in         = reinterpret_cast<int*>(pMA_In->data);
        int* ptr_blur       = reinterpret_cast<int*>(MA_tmp_Blur.data);
        for(size_t px = 0; px < area; px++, ptr_in++, ptr_out++, ptr_blur++)
            if((*ptr_in * scale) + offset > *ptr_blur)
                *ptr_out = 255;
    }
        break;

    case CV_32FC1:
    {
        uchar* ptr_out      = reinterpret_cast<uchar*>(pMA_Out->data);
        float* ptr_in       = reinterpret_cast<float*>(pMA_In->data);
        float* ptr_blur     = reinterpret_cast<float*>(MA_tmp_Blur.data);
        for(size_t px = 0; px < area; px++, ptr_in++, ptr_out++, ptr_blur++)
            if((*ptr_in * scale) + offset > *ptr_blur)
                *ptr_out = 255;
    }
        break;

    case CV_64FC1:
    {
        uchar* ptr_out      = reinterpret_cast<uchar*>(pMA_Out->data);
        double* ptr_in      = reinterpret_cast<double*>(pMA_In->data);
        double* ptr_blur    = reinterpret_cast<double*>(MA_tmp_Blur.data);
        for(size_t px = 0; px < area; px++, ptr_in++, ptr_out++, ptr_blur++)
            if((*ptr_in * scale) + offset > *ptr_blur)
                *ptr_out = 255;
    }
        break;

    default:
    {
        MA_tmp_Blur.release();
        return ER_type_bad;
    }

    }

    MA_tmp_Blur.release();
    return ER_okay;
}

int D_Img_Proc::Threshold_BlurThres(Mat *pMA_Out, Mat *pMA_In, int size, double sigma, double thres)
{
    int ER;

    //blur
    Mat MA_tmp_blur;
    ER = Filter_Gauss(
                &MA_tmp_blur,
                pMA_In,
                size,
                size,
                BORDER_DEFAULT,
                sigma,
                sigma);
    if(ER != ER_okay)
    {
        MA_tmp_blur.release();
        return ER;
    }

    //thresh
    ER = Threshold_Absolute_1C(
                pMA_Out,
                &MA_tmp_blur,
                thres);
    if(ER != ER_okay)
    {
        MA_tmp_blur.release();
        return ER;
    }

    MA_tmp_blur.release();
    return ER_okay;
}

int D_Img_Proc::Color_Grab(Mat *pMA_Out, Mat *pMA_In, int color_space, int out_mode, vector<uchar> min, vector<uchar> max)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->depth() != CV_8U)    return ER_bitdepth_bad;
    if(pMA_In->channels() != 3)     return ER_channel_bad;

    //error handler
    int ER;

    //covert color space
    Mat MA_tmp;
    if(color_space != 0)
    {
        int         cvt_mode;
        switch (color_space) {
        case 1:     cvt_mode = CV_BGR2XYZ;      break;
        case 2:     cvt_mode = CV_BGR2YCrCb;      break;
        case 3:     cvt_mode = CV_BGR2HSV;      break;
        case 4:     cvt_mode = CV_BGR2Lab;      break;
        case 5:     cvt_mode = CV_BGR2Luv;      break;
        default:                                return ER_parameter_bad;}

        ER = Convert_Color(
                    &MA_tmp,
                    pMA_In,
                    cvt_mode);
        if(ER != ER_okay)   return ER;
    }
    else
    {
        MA_tmp = pMA_In->clone();
    }

    //get size
    unsigned int width = MA_tmp.cols;
    unsigned int height = MA_tmp.rows;
    unsigned int area = width * height;

    Vec3b px_in;                                                    //input pixel
    Vec3b* ptr_in = reinterpret_cast<Vec3b*>(MA_tmp.data);          //pointer to input data
    *pMA_Out = Mat(MA_tmp.size(), CV_8UC1, Scalar(0));              //declare output image & init with background
    uchar* ptr_out = reinterpret_cast<uchar*>(pMA_Out->data);       //pointer to output data
    for (unsigned int px = 0; px < area; px++, ptr_in++, ptr_out++) //loop pixels
    {
        px_in = *ptr_in;
        int fails = 0;

        //check
        for(int c = 0; c < 3; c++)                                  //loop channels
        {
            if(min[c] <= max[c])                                    //min < = max
            {
                if(px_in[c] < min[c] || px_in[c] > max[c])
                    fails++;
            }
            else if(min[c] > max[c])                                //max < min
            {
                if(px_in[c] >= min[c] || px_in[c] <= max[c])
                    fails++;
            }
        }

        //mark, if foreground
        if(fails == 0)
            *ptr_out = (uchar) 255;
    }

    //mask
    if(out_mode == 1)
    {
        Mat MA_mask;
        ER = Convert_Color(
                    &MA_mask,
                    pMA_Out,
                    CV_GRAY2BGR);
        if(ER != ER_okay)   return ER;

        ER = Math_ImgImg_BitAnd(
                    pMA_Out,
                    &MA_mask,
                    pMA_In);
        if(ER != ER_okay)   return ER;

        MA_mask.release();
    }

    MA_tmp.release();
    return ER_okay;
}


int D_Img_Proc::Morphology_Elemental(Mat *pMA_Out, Mat *pMA_In, int morph_type, int elem_type, unsigned int elem_size_X, unsigned int elem_size_Y, int border_type, unsigned int iterations)
{
    if(pMA_In->empty())                                                                     return ER_empty;
    if((pMA_In->type() == CV_32F) || pMA_In->type() == CV_64F || pMA_In->type() == CV_32S)  return ER_bitdepth_bad;

    Mat MA_Kernel = getStructuringElement(
                elem_type,
                Size(2*elem_size_X + 1, 2*elem_size_Y + 1),
                Point(elem_size_X, elem_size_Y));

    morphologyEx(
                *pMA_In,
                *pMA_Out,
                morph_type,
                MA_Kernel,
                Point(-1, -1),
                iterations,
                border_type);

    MA_Kernel.release();
    return ER_okay;
}

int D_Img_Proc::Morphology_Skeleton(Mat *pMA_Out, Mat *pMA_In, int elem_type, unsigned int elem_size_X, unsigned int elem_size_Y, int border_type)
{
    return Morphology_Thinning(pMA_Out, pMA_In, 0);

    int ER;
    if(pMA_In->empty())                                                                     return ER_empty;
    if((pMA_In->type() == CV_32F) || pMA_In->type() == CV_64F || pMA_In->type() == CV_32S)  return ER_bitdepth_bad;

    //size
    int in_px_size = pMA_In->rows * pMA_In->cols;

    //tmp mats needed
    Mat MA_tmp_bin_in   = Mat::zeros(pMA_In->size(), CV_8UC1);
    Mat MA_tmp_eroded   = Mat::zeros(pMA_In->size(), CV_8UC1);
    Mat MA_tmp_dialte   = Mat::zeros(pMA_In->size(), CV_8UC1);
    Mat MA_tmp_subtract = Mat::zeros(pMA_In->size(), CV_8UC1);
    Mat MA_tmp_skeleton = Mat::zeros(pMA_In->size(), CV_8UC1);

    //bin input
    ER = Threshold_Auto(
                pMA_In,
                &MA_tmp_bin_in,
                CV_THRESH_BINARY,
                255,
                CV_THRESH_OTSU);
    if(ER != ER_okay && ER != ER_empty)
    {
        qDebug() << "Error in Thresh";
        MA_tmp_eroded.release();
        MA_tmp_dialte.release();
        MA_tmp_subtract.release();
        MA_tmp_skeleton.release();
        return ER;
    }

    //loop
    int loop = 0;
    bool done = false;
    while(!done)
    {
        qDebug() << "Loop:" << loop;

        //
        int ER = Morphology_Elemental(
                    &MA_tmp_eroded,
                    &MA_tmp_bin_in,
                    MORPH_ERODE,
                    elem_type,
                    elem_size_X,
                    elem_size_Y,
                    border_type,
                    1);
        if(ER != ER_okay && ER != ER_empty)
        {
            qDebug() << "Error in Erode";
            MA_tmp_eroded.release();
            MA_tmp_dialte.release();
            MA_tmp_subtract.release();
            MA_tmp_skeleton.release();
            return ER;
        }

        //
        ER = Morphology_Elemental(
                    &MA_tmp_dialte,
                    &MA_tmp_eroded,
                    MORPH_DILATE,
                    elem_type,
                    elem_size_X,
                    elem_size_Y,
                    border_type,
                    1);
        if(ER != ER_okay && ER != ER_empty)
        {
            qDebug() << "Error in Dilate";
            MA_tmp_eroded.release();
            MA_tmp_dialte.release();
            MA_tmp_subtract.release();
            MA_tmp_skeleton.release();
            return ER;
        }

        //
        ER = Math_ImgImg_Diff(
                    &MA_tmp_subtract,
                    &MA_tmp_bin_in,
                    &MA_tmp_dialte);
        if(ER != ER_okay && ER != ER_empty)
        {
            qDebug() << "Error in Diff";
            MA_tmp_eroded.release();
            MA_tmp_dialte.release();
            MA_tmp_subtract.release();
            MA_tmp_skeleton.release();
            return ER;
        }

        //
        ER = Math_ImgImg_BitOr(
                    &MA_tmp_skeleton,
                    &MA_tmp_subtract,
                    &MA_tmp_skeleton);
        if(ER != ER_okay && ER != ER_empty)
        {
            qDebug() << "Error in BitOr";
            MA_tmp_eroded.release();
            MA_tmp_dialte.release();
            MA_tmp_subtract.release();
            MA_tmp_skeleton.release();
            return ER;
        }

        MA_tmp_bin_in = MA_tmp_eroded.clone();

        int zeros = in_px_size - countNonZero(MA_tmp_bin_in);
        if(zeros == in_px_size)
            done = true;

        loop++;
    }

    //export out
    *pMA_Out = MA_tmp_skeleton.clone();

    //free mem
    MA_tmp_eroded.release();
    MA_tmp_dialte.release();
    MA_tmp_subtract.release();
    MA_tmp_skeleton.release();

    //end
    return ER_okay;
}

int D_Img_Proc::Morphology_Thinning(Mat *pMA_Out, Mat *pMA_In, int thinning_type)
{
    //Source of algorithm:
    //https://github.com/opencv/opencv_contrib/blob/master/modules/ximgproc/src/thinning.cpp

    // Apply the thinning procedure to a given image

    Mat processed = pMA_In->clone();
    // Enforce the range of the input image to be in between 0 - 255
    processed /= 255;

    Mat prev = Mat::zeros(processed.size(), CV_8UC1);
    Mat diff;

    do {
        Morphology_Thinning_Iteration(processed, 0, thinning_type);
        Morphology_Thinning_Iteration(processed, 1, thinning_type);
        absdiff(processed, prev, diff);
        processed.copyTo(prev);
    }
    while (countNonZero(diff) > 0);

    processed *= 255;

    *pMA_Out = processed.clone();
    processed.release();

    return ER_okay;
}

int D_Img_Proc::Morphology_Thinning_Iteration(Mat img, int iter, int thinning_type)
{
    //Source of algorithm:
    //https://github.com/opencv/opencv_contrib/blob/master/modules/ximgproc/src/thinning.cpp

    // Applies a thinning iteration to a binary image

    Mat marker = Mat::zeros(img.size(), CV_8UC1);

    if(thinning_type == 0){  //THINNING_ZHANGSUEN
        for (int i = 1; i < img.rows-1; i++)
        {
            for (int j = 1; j < img.cols-1; j++)
            {
                uchar p2 = img.at<uchar>(i-1, j);
                uchar p3 = img.at<uchar>(i-1, j+1);
                uchar p4 = img.at<uchar>(i, j+1);
                uchar p5 = img.at<uchar>(i+1, j+1);
                uchar p6 = img.at<uchar>(i+1, j);
                uchar p7 = img.at<uchar>(i+1, j-1);
                uchar p8 = img.at<uchar>(i, j-1);
                uchar p9 = img.at<uchar>(i-1, j-1);

                int A  = (p2 == 0 && p3 == 1) + (p3 == 0 && p4 == 1) +
                         (p4 == 0 && p5 == 1) + (p5 == 0 && p6 == 1) +
                         (p6 == 0 && p7 == 1) + (p7 == 0 && p8 == 1) +
                         (p8 == 0 && p9 == 1) + (p9 == 0 && p2 == 1);
                int B  = p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9;
                int m1 = iter == 0 ? (p2 * p4 * p6) : (p2 * p4 * p8);
                int m2 = iter == 0 ? (p4 * p6 * p8) : (p2 * p6 * p8);

                if (A == 1 && (B >= 2 && B <= 6) && m1 == 0 && m2 == 0)
                    marker.at<uchar>(i,j) = 1;
            }
        }
    }
    if(thinning_type == 1){      //THINNING_GUOHALL
        for (int i = 1; i < img.rows-1; i++)
        {
            for (int j = 1; j < img.cols-1; j++)
            {
                uchar p2 = img.at<uchar>(i-1, j);
                uchar p3 = img.at<uchar>(i-1, j+1);
                uchar p4 = img.at<uchar>(i, j+1);
                uchar p5 = img.at<uchar>(i+1, j+1);
                uchar p6 = img.at<uchar>(i+1, j);
                uchar p7 = img.at<uchar>(i+1, j-1);
                uchar p8 = img.at<uchar>(i, j-1);
                uchar p9 = img.at<uchar>(i-1, j-1);

                int C  = ((!p2) & (p3 | p4)) + ((!p4) & (p5 | p6)) +
                         ((!p6) & (p7 | p8)) + ((!p8) & (p9 | p2));
                int N1 = (p9 | p2) + (p3 | p4) + (p5 | p6) + (p7 | p8);
                int N2 = (p2 | p3) + (p4 | p5) + (p6 | p7) + (p8 | p9);
                int N  = N1 < N2 ? N1 : N2;
                int m  = iter == 0 ? ((p6 | p7 | (!p9)) & p8) : ((p2 | p3 | (!p5)) & p4);

                if ((C == 1) && ((N >= 2) && ((N <= 3)) & (m == 0)))
                    marker.at<uchar>(i,j) = 1;
            }
        }
    }

    img &= ~marker;


    return ER_okay;
}

int D_Img_Proc::Morphology_Erode_Rect(Mat *pMA_Out, Mat *pMA_In, int elem_size_X, int elem_size_Y)
{
    if(pMA_In->empty())                 return ER_empty;
    int ER;

    Mat MA_tmp_mask;

    if(pMA_In->depth() == CV_8U)
    {
        switch (pMA_In->channels()) {
        case 1:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_8UC1, Scalar(255));                  break;
        case 2:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_8UC2, Scalar(255, 255));             break;
        case 3:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_8UC3, Scalar(255, 255, 255));        break;
        case 4:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_8UC4, Scalar(255, 255, 255, 255));   break;
        default:    MA_tmp_mask.release();                                                              return ER_type_bad;}

        ER = Filter_Function_8bit(
                    pMA_Out,
                    pMA_In,
                    &MA_tmp_mask,
                    D_Math::Function_2D_to_1D_8bit(c_MATH_2D_TO_1D_Y),
                    D_Math::Function_2D_to_1D_8bit(c_MATH_2D_TO_1D_X_times_Y),
                    D_Stat::Function_SingleStat_8bit(c_STAT_MINIMUM),
                    D_Math::Function_2D_to_1D_8bit(c_MATH_2D_TO_1D_X),
                    BORDER_REPLICATE);
    }
    else
    {
        switch (pMA_In->channels()) {
        case 1:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_64FC1, Scalar(255));                 break;
        case 2:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_64FC2, Scalar(255, 255));            break;
        case 3:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_64FC3, Scalar(255, 255, 255));       break;
        case 4:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_64FC4, Scalar(255, 255, 255, 255));  break;
        default:    MA_tmp_mask.release();                                                              return ER_type_bad;}

        ER = Filter_Function(
                    pMA_Out,
                    pMA_In,
                    &MA_tmp_mask,
                    D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_Y),
                    D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_X_times_Y),
                    D_Stat::Function_SingleStat(c_STAT_MINIMUM),
                    D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_X),
                    BORDER_REPLICATE);
    }

    MA_tmp_mask.release();
    return ER;
}

int D_Img_Proc::Morphology_Dilate_Rect(Mat *pMA_Out, Mat *pMA_In, int elem_size_X, int elem_size_Y)
{
    if(pMA_In->empty())                 return ER_empty;
    int ER;

    Mat MA_tmp_mask;

    if(pMA_In->depth() == CV_8U)
    {
        switch (pMA_In->channels()) {
        case 1:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_8UC1, Scalar(255));                  break;
        case 2:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_8UC2, Scalar(255, 255));             break;
        case 3:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_8UC3, Scalar(255, 255, 255));        break;
        case 4:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_8UC4, Scalar(255, 255, 255, 255));   break;
        default:    MA_tmp_mask.release();                                                              return ER_type_bad;}

        ER = Filter_Function_8bit(
                    pMA_Out,
                    pMA_In,
                    &MA_tmp_mask,
                    D_Math::Function_2D_to_1D_8bit(c_MATH_2D_TO_1D_Y),
                    D_Math::Function_2D_to_1D_8bit(c_MATH_2D_TO_1D_X_times_Y),
                    D_Stat::Function_SingleStat_8bit(c_STAT_MAXIMUM),
                    D_Math::Function_2D_to_1D_8bit(c_MATH_2D_TO_1D_X),
                    BORDER_REPLICATE);
    }
    else
    {
        switch (pMA_In->channels()) {
        case 1:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_64FC1, Scalar(255));                 break;
        case 2:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_64FC2, Scalar(255, 255));            break;
        case 3:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_64FC3, Scalar(255, 255, 255));       break;
        case 4:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_64FC4, Scalar(255, 255, 255, 255));  break;
        default:    MA_tmp_mask.release();                                                              return ER_type_bad;}

        ER = Filter_Function(
                    pMA_Out,
                    pMA_In,
                    &MA_tmp_mask,
                    D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_Y),
                    D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_X_times_Y),
                    D_Stat::Function_SingleStat(c_STAT_MAXIMUM),
                    D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_X),
                    BORDER_REPLICATE);
    }

    MA_tmp_mask.release();
    return ER;
}

int D_Img_Proc::Morphology_LocMax_Rect(Mat *pMA_Out, Mat *pMA_In, int elem_size_X, int elem_size_Y)
{
    if(pMA_In->empty())     return ER_empty;
    int ER;

    Mat MA_tmp_mask;
    switch (pMA_In->channels()) {
    case 1:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_8UC1, Scalar(1));                break;
    case 2:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_8UC2, Scalar(1, 1));             break;
    case 3:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_8UC3, Scalar(1, 1, 1));          break;
    case 4:     MA_tmp_mask = Mat(elem_size_Y, elem_size_X, CV_8UC4, Scalar(1, 1, 1, 1));       break;
    default:    MA_tmp_mask.release();                                                          return ER_type_bad;}

    Mat MA_tmp_ranks;
    ER = Filter_Function(
                &MA_tmp_ranks,
                pMA_In,
                &MA_tmp_mask,
                D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_X_greater_Y),
                D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_X_times_Y),
                D_Stat::Function_SingleStat(c_STAT_SUM),
                D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_X_equals_Y, 1, 0, 0, elem_size_X * elem_size_Y - 1),
                BORDER_REPLICATE);

    MA_tmp_mask.release();
    if(ER != ER_okay)
    {
        MA_tmp_ranks.release();
        return ER;
    }

    ER = Threshold_Absolute(
                pMA_Out,
                &MA_tmp_ranks,
                0);

    MA_tmp_ranks.release();
    return ER;
}

int D_Img_Proc::Morphology_Reconstruction(Mat *pMA_Out, Mat *pMA_InSeed, Mat *pMA_InLimit, Mat *pMA_Mask, double quantil)
{
    if(pMA_InSeed->empty())                         return ER_empty;
    if(pMA_InLimit->empty())                        return ER_empty;
    if(pMA_InLimit->type() != pMA_InSeed->type())   return ER_type_missmatch;
    if(pMA_InSeed->channels() != 1)                 return ER_channel_bad;
    if(quantil < 0 || quantil > 1)                  return ER_parameter_bad;
    int ER;

    //Previous step result
    Mat MA_tmp_prev = pMA_InSeed->clone();

    //iterate
    while(true)
    {
        //dialte
        ER = Filter_RankOrder_1C(
                    pMA_Out,
                    &MA_tmp_prev,
                    pMA_Mask,
                    quantil);
        if(ER != ER_okay)
        {
            MA_tmp_prev.release();
            return ER;
        }

        //limit reconstructed to value of mask
        ER = Math_LimitTop(
                    pMA_Out,
                    pMA_InLimit);
        if(ER != ER_okay)
        {
            MA_tmp_prev.release();
            return ER;
        }

        //nothing changed?
        if(Check_IsSimilar(pMA_Out, &MA_tmp_prev))
        {
            MA_tmp_prev.release();
            return ER_okay;
        }

        //save current as next previous
        MA_tmp_prev = pMA_Out->clone();
    }
}

int D_Img_Proc::Transformation_Distance(Mat *pMA_Out, Mat *pMA_In, int metric, int precision)
{
    if(pMA_In->type() != CV_8U)     return ER_bitdepth_bad;
    if(pMA_In->channels() > 1)      return ER_channel_bad;

    double min, max;
    int ER = MinMax_of_Mat(
                pMA_In,
                &min,
                &max);
    if(ER != ER_okay)   return ER;

    if(min > 0)
    {
        Mat MA_tmp_Pad;
        copyMakeBorder(
                    *pMA_In,
                    MA_tmp_Pad,
                    1,
                    1,
                    1,
                    1,
                    BORDER_CONSTANT);

        Mat MA_tmp_Dist;
        distanceTransform(
                    MA_tmp_Pad,
                    MA_tmp_Dist,
                    metric,
                    precision);

        ER = Crop_Rect_Abs(
                    pMA_Out,
                    &MA_tmp_Dist,
                    1,
                    1,
                    pMA_In->cols,
                    pMA_In->rows);
        if(ER != ER_okay)
        {
            MA_tmp_Pad.release();
            MA_tmp_Dist.release();
            return ER;
        }
        MA_tmp_Pad.release();
        MA_tmp_Dist.release();
    }
    else
    {
        distanceTransform(
                    *pMA_In,
                    *pMA_Out,
                    metric,
                    precision);
    }

    return ER_okay;
}

/*
int D_Img_Proc::Transformation_Distance_Rel(Mat *pMA_Out, Mat *pMA_In, int metric, int precision)
{
    if(pMA_In->type() != CV_8U)     return ER_bitdepth_bad;
    if(pMA_In->channels() > 1)      return ER_channel_bad;



    return ER_other;
}
*/

int D_Img_Proc::Transformation_Watershed(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Marker)
{
    if(pMA_In->empty() || pMA_Marker->empty())  return ER_empty;
    if(pMA_In->size != pMA_Marker->size)        return ER_size_missmatch;
    if(pMA_In->type() != CV_8UC3)               return ER_type_bad;
    if(pMA_Marker->type() != CV_32SC1)          return ER_type_bad;

    *pMA_Out = pMA_Marker->clone();

    watershed(
                *pMA_In,
                *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::Transformation_Watershed_Auto(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Marker, bool include_not_seeded, bool conv_8bit, bool exclude_border)
{
    if(pMA_In->empty() || pMA_Marker->empty())                  return ER_empty;
    if(pMA_In->size != pMA_Marker->size)                        return ER_size_missmatch;
    if(pMA_In->type() != CV_8UC1)                               return ER_type_bad;
    if(pMA_Marker->type() != CV_8UC1)                           return ER_type_bad;

    unsigned int width = pMA_In->cols;
    unsigned int height = pMA_In->rows;
    unsigned int area = width * height;

    int ER;

    //labeling the seeds
    //0: background
    //1, 2, 3, ...: labeled seeds
    ER = Labeling(
                pMA_Out,
                pMA_Marker,
                8,
                CV_32S);
    if(ER != ER_okay)   return ER;

    //labeled seeds + 1 -> background is 1 not 0 anymore
    //0: does not exists
    //1: background
    //2, 3, 4, ...: labeled seeds
    ER = Math_ImgScal_Add(
                pMA_Out,
                pMA_Out,
                1);
    if(ER != ER_okay)   return ER;

    //unknown area is difference between binary input (0: sure bg) and binary markers (255: sure fg)
    //255: area that is neigther seed nor sure background
    //0: sure background
    //1-254: does not exist (at least if inputs are binary)
    Mat MA_unknown;
    //Make sure, Seeds not extend the area to be labeled
    ER = Math_ImgImg_BitAnd(
                &MA_unknown,
                pMA_In,
                pMA_Marker);
    if(ER != ER_okay)   return ER;
    //Get are which is input but not seed -> unknown
    ER = Math_ImgImg_Diff(
                &MA_unknown,
                pMA_In,
                &MA_unknown);
    if(ER != ER_okay)   return ER;

    //set unknown area to 0 (to be labeled) in seed image, so that the seeds fill the area around them but not the background (which is 1 and its own seed at this point)
    //0: unknown area to be labeled
    //1: sure background (technically its own seed)
    //2, 3, 4, ...: seeds
    uint* ptr_seeds = reinterpret_cast<uint*>(pMA_Out->data);               //cast to read markers as 32bit
    uchar*  ptr_unkown = reinterpret_cast<uchar*>(MA_unknown.data);         //8bit pointer to unkown
    for (unsigned int px = 0; px < area; px++, ptr_seeds++, ptr_unkown++)   //loop pixels
        if(*ptr_unkown > 0)                                                 //check, if area is unknown
            *ptr_seeds = (uint)0;                                           //set seed to 0 at this pixel

    //convert input to 3-channel
    Mat MA_in_3ch;
    ER = Convert_Color(
                &MA_in_3ch,
                pMA_In,
                CV_GRAY2RGB);
    if(ER != ER_okay)   return ER;

    //labeling the unkown area (0)
    //1: background
    //2, 3, 4, ...: segmented and labeled image
    watershed(
                MA_in_3ch,
                *pMA_Out);

    //labeled image - 1 -> background is 0 not 1 anymore
    //0: background
    //1, 2, 3, ...: labeled blobs
    ER = Math_ImgScal_Sub(
                pMA_Out,
                pMA_Out,
                1);
    if(ER != ER_okay)   return ER;

    //additional stuff============================================================================

    if(include_not_seeded || exclude_border)
    {
        //Convert "old" output to 8bit binary
        Mat MA_out_8bit;
        ER = Threshold_Relative(
                    &MA_out_8bit,
                    pMA_Out,
                    0,
                    0);
        if(ER != ER_okay)   return ER;

        //get foreground
        Mat MA_foreground;
        if(include_not_seeded)
        {
            //--------------------------------------------------------------    separate objects
            //find separators
            Mat MA_edges;

            //4-connectivity
            //only outlines to avoid making objects smaller or delete small objects
            ER = Reduce_Outlines(
                        &MA_edges,
                        &MA_out_8bit,
                        8,
                        1);
            //imshow("edges", MA_edges);

            //separate whole foreground (from input)
            ER = Math_ImgImg_Diff(
                        &MA_foreground,
                        pMA_In,
                        &MA_edges);
            if(ER != ER_okay)   return ER;

            MA_edges.release();
        }
        else
        {
            //make labels foreground
            ER = Threshold_Value(
                        &MA_foreground,
                        &MA_out_8bit,
                        CV_THRESH_BINARY,
                        255,
                        1);
            if(ER != ER_okay)   return ER;
        }

        //exclude border connected labels
        if(exclude_border)
        {
            //--------------------------------------------------------------    exlcude the objects connected to the border
            //Draw border white
            ER = Draw_Rect(
                        &MA_foreground,
                        0,
                        0,
                        MA_foreground.cols - 1,
                        MA_foreground.rows - 1,
                        2,
                        255);
            if(ER != ER_okay)   return ER;

            //fill everything connected with drawn rect with background
            ER = Floodfill(
                        &MA_foreground,
                        &MA_foreground,
                        0,
                        0,
                        0);
            if(ER != ER_okay)   return ER;
        }

        //imshow("before labeling", MA_foreground);
        //labeling again
        //--------------------------------------------------------------    labeling
        ER = Labeling(
                    pMA_Out,
                    &MA_foreground,
                    4,                  //only 4-px neighborhood to avoid "diagonally touching" objects beeing counted as one
                    CV_16U);
        if(ER != ER_okay)   return ER;
        //imshow("labeled", *pMA_Out);

        MA_foreground.release();
        MA_out_8bit.release();
    }

    //--------------------------------------------------------------    convert 8bit
    if(conv_8bit)
    {
        //get label number
        double min, max;
        ER = MinMax_of_Mat(
                    pMA_Out,
                    &min,
                    &max);
        if(max > 255)       max = 255;
        if(ER != ER_okay)   return ER;

        //convert to 8bit
        ER = Normalize(
                    pMA_Out,
                    pMA_Out,
                    CV_MINMAX,
                    CV_8U,
                    0,
                    max);
        if(ER != ER_okay)   return ER;
    }

    MA_in_3ch.release();
    MA_unknown.release();
    return ER_okay;
}

int D_Img_Proc::Transformation_Watershed_Auto(Mat *pMA_Out, Mat *pMA_In, double distance, bool include_not_seeded, bool conv_8bit, bool exclude_border)
{
    int ER;

    //distance transform
    Mat MA_tmp_dist;
    ER = Transformation_Distance(
                &MA_tmp_dist,
                pMA_In,
                DIST_L2,
                DIST_MASK_PRECISE);
    if(ER != ER_okay)
    {
        MA_tmp_dist.release();
        return ER;
    }

    //distance threshold
    Mat MA_tmp_marker;
    ER = Threshold_Absolute_1C(
                &MA_tmp_marker,
                &MA_tmp_dist,
                distance);
    if(ER != ER_okay)
    {
        MA_tmp_dist.release();
        MA_tmp_marker.release();
        return ER;
    }

    //watershed
    ER = Transformation_Watershed_Auto(
                pMA_Out,
                pMA_In,
                &MA_tmp_marker,
                include_not_seeded,
                conv_8bit,
                exclude_border);
    if(ER != ER_okay)   return ER;

    MA_tmp_dist.release();
    MA_tmp_marker.release();

    return ER_okay;
}

int D_Img_Proc::Transformation_Watershed_Auto(Mat *pMA_Out, Mat *pMA_In, int size, double sigma, bool include_not_seeded, bool conv_8bit, bool exclude_border)
{
    int ER;

    //distance transform
    Mat MA_tmp_dist;
    ER = Transformation_Distance(
                &MA_tmp_dist,
                pMA_In,
                DIST_L2,
                DIST_MASK_PRECISE);
    if(ER != ER_okay)
    {
        MA_tmp_dist.release();
        return ER;
    }

    //distance blur
    Mat MA_tmp_dist_blur;
    ER = Filter_Gauss(
                &MA_tmp_dist_blur,
                &MA_tmp_dist,
                size,
                size,
                BORDER_DEFAULT,
                sigma,
                sigma);
    if(ER != ER_okay)
    {
        MA_tmp_dist.release();
        MA_tmp_dist_blur.release();
        return ER;
    }

    //loc max
    Mat MA_tmp_loc_max;
    ER = Morphology_LocMax_Rect(
                &MA_tmp_loc_max,
                &MA_tmp_dist_blur,
                3,
                3);
    if(ER != ER_okay)
    {
        MA_tmp_dist.release();
        MA_tmp_dist_blur.release();
        MA_tmp_loc_max.release();
        return ER;
    }

    //watershed
    ER = Transformation_Watershed_Auto(
                pMA_Out,
                pMA_In,
                &MA_tmp_loc_max,
                include_not_seeded,
                conv_8bit,
                exclude_border);
    if(ER != ER_okay)   return ER;

    MA_tmp_dist.release();
    MA_tmp_dist_blur.release();
    MA_tmp_loc_max.release();

    return ER_okay;
}

int D_Img_Proc::Transformation_Watershed_Custom(Mat *pMA_Out, Mat *pMA_In2Fill, Mat *pMA_InMarker, Mat *pMA_FG_Mask, int mode_flood, int mode_marker, int mode_mask, int connectivity, int gauss_size, double gauss_sigma, int morphgrad_elem, int morphgrad_size, double thresh, bool exclude_border, bool include_non_seeded, bool draw_watersheds)
{
    //error checks
    if(pMA_In2Fill->empty())                                                return ER_empty;
    if(pMA_InMarker->empty())                                               return ER_empty;
    if(pMA_FG_Mask->empty())                                                return ER_empty;
    if(pMA_In2Fill->channels() != 1)                                        return ER_channel_bad;
    if(pMA_InMarker->channels() != 1)                                       return ER_channel_bad;
    if(pMA_FG_Mask->channels() != 1)                                        return ER_channel_bad;
    if(pMA_InMarker->depth() != CV_32S)                                     return ER_bitdepth_bad;
    if(pMA_FG_Mask->depth() != CV_8U)                                       return ER_bitdepth_bad;
    if(pMA_FG_Mask->size() != pMA_InMarker->size())                         return ER_size_missmatch;
    if(pMA_FG_Mask->size() != pMA_In2Fill->size())                          return ER_size_missmatch;
    if(connectivity != 4 && connectivity != 8)                              return ER_parameter_bad;
    if(mode_flood < 0 || mode_flood >= c_WATERSHED_FILL_NUMBER_OF)          return ER_parameter_bad;
    if(mode_marker < 0 || mode_marker >= c_WATERSHED_MARKER_NUMBER_OF)      return ER_parameter_bad;
    if(mode_mask < 0 || mode_mask >= c_WATERSHED_MASK_NUMBER_OF)            return ER_parameter_bad;
    if(gauss_size < 1)                                                      return ER_parameter_bad;
    if(gauss_size % 2 != 1)                                                 return ER_parameter_bad;
    if(gauss_sigma < 0)                                                     return ER_parameter_bad;
    if(morphgrad_elem != MORPH_CROSS && morphgrad_elem != MORPH_RECT)       return ER_parameter_bad;
    if(morphgrad_size < 1)                                                  return ER_parameter_bad;
    if(morphgrad_size % 2 != 1)                                             return ER_parameter_bad;
    int ER = ER_okay;

    //------------------------------------------------------- Preprocess fill
    Mat MA_PreProc_Fill;
    switch (mode_flood) {

    case c_WATERSHED_FILL_MASK_DIST:
    {
        Mat MA_tmp_dist;
        ER = Transformation_Distance(
                    &MA_tmp_dist,
                    pMA_FG_Mask,
                    DIST_L2,
                    DIST_MASK_PRECISE);
        if(ER != ER_okay)
        {
            MA_tmp_dist.release();
            MA_PreProc_Fill.release();
            return ER;
        }

        ER = Filter_Gauss(
                    &MA_PreProc_Fill,
                    &MA_tmp_dist,
                    gauss_size,
                    gauss_size,
                    BORDER_DEFAULT,
                    gauss_sigma,
                    gauss_sigma);
        if(ER != ER_okay)
        {
            MA_tmp_dist.release();
            MA_PreProc_Fill.release();
            return ER;
        }
    }
        break;

    case c_WATERSHED_FILL_MASK_DIST_INV:
    {
        Mat MA_tmp_dist;
        ER = Transformation_Distance(
                    &MA_tmp_dist,
                    pMA_FG_Mask,
                    DIST_L2,
                    DIST_MASK_PRECISE);
        if(ER != ER_okay)
        {
            MA_PreProc_Fill.release();
            MA_tmp_dist.release();
            return ER;
        }

        Mat MA_tmp_dist_blur;
        ER = Filter_Gauss(
                    &MA_tmp_dist_blur,
                    &MA_tmp_dist,
                    gauss_size,
                    gauss_size,
                    BORDER_DEFAULT,
                    gauss_sigma,
                    gauss_sigma);
        MA_tmp_dist.release();
        if(ER != ER_okay)
        {
            MA_tmp_dist_blur.release();
            MA_PreProc_Fill.release();
            return ER;
        }

        ER = Invert(
                    &MA_PreProc_Fill,
                    &MA_tmp_dist_blur);
        MA_tmp_dist_blur.release();
        if(ER != ER_okay)
        {
            MA_PreProc_Fill.release();
            return ER;
        }
    }
        break;

    case c_WATERSHED_FILL_MASK_COPY:
    {
        ER = Duplicate(
                    &MA_PreProc_Fill,
                    pMA_In2Fill);
        if(ER != ER_okay)
        {
            MA_PreProc_Fill.release();
            return ER;
        }
    }
        break;

    case c_WATERSHED_FILL_SOURCE_INV:
    {
        ER = Invert(
                    &MA_PreProc_Fill,
                    pMA_In2Fill);
        if(ER != ER_okay)
        {
            MA_PreProc_Fill.release();
            return ER;
        }
    }
        break;

    case c_WATERSHED_FILL_SOURCE_COPY:
    {
        ER = Duplicate(
                    &MA_PreProc_Fill,
                    pMA_In2Fill);
        if(ER != ER_okay)
        {
            MA_PreProc_Fill.release();
            return ER;
        }
    }
        break;

    case c_WATERSHED_FILL_SOURCE_LOG:
    {
        ER = Filter_LaplaceOfGaussian(
                    &MA_PreProc_Fill,
                    pMA_In2Fill,
                    gauss_size,
                    gauss_sigma,
                    3,
                    BORDER_DEFAULT,
                    CV_64F,
                    1,
                    0);
        if(ER != ER_okay)
        {
            MA_PreProc_Fill.release();
            return ER;
        }
    }
        break;

    case c_WATERSHED_FILL_SOURCE_MORPH_GRAD:
    {
        ER = Morphology_Elemental(
                    &MA_PreProc_Fill,
                    pMA_In2Fill,
                    MORPH_GRADIENT,
                    morphgrad_elem,
                    morphgrad_size,
                    morphgrad_size,
                    BORDER_DEFAULT,
                    1);
        if(ER != ER_okay)
        {
            MA_PreProc_Fill.release();
            return ER;
        }
    }
        break;

    default:
        return ER_parameter_bad;
    }


    //------------------------------------------------------- Preprocess marker
    Mat MA_PreProc_Marker;
    switch (mode_flood) {

    case c_WATERSHED_MARKER_FILL_LOC_MIN:
    {
        return ER_other;
    }
        break;


    default:
        return ER_parameter_bad;
    }

    return ER_other;
}

/*
int D_Img_Proc::Transformation_Watershed_Custom(Mat *pMA_Out, Mat *pMA_In2Fill, Mat *pMA_InMarker, Mat *pMA_FG_Mask, int connectivity)
{
    //error checks
    //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Error checks";
    if(pMA_In2Fill->empty())                                                return ER_empty;
    if(pMA_InMarker->empty())                                               return ER_empty;
    if(pMA_FG_Mask->empty())                                                return ER_empty;
    if(pMA_In2Fill->channels() != 1)                                        return ER_channel_bad;
    if(pMA_InMarker->channels() != 1)                                       return ER_channel_bad;
    if(pMA_FG_Mask->channels() != 1)                                        return ER_channel_bad;
    if(pMA_In2Fill->depth() == CV_32F || pMA_In2Fill->depth() == CV_64F)    return ER_bitdepth_bad;
    if(pMA_InMarker->depth() != CV_32S)                                     return ER_bitdepth_bad;
    if(pMA_FG_Mask->depth() != CV_8U)                                       return ER_bitdepth_bad;
    if(pMA_FG_Mask->size() != pMA_InMarker->size())                         return ER_size_missmatch;
    if(pMA_FG_Mask->size() != pMA_In2Fill->size())                          return ER_size_missmatch;
    if(connectivity != 4 && connectivity != 8)                              return ER_parameter_bad;
    int ER = ER_okay;

    //min and max value
    //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Min/Max";
    double global_min = 0;
    double global_max = 0;
    ER = MinMax_of_Mat_1C(
                pMA_In2Fill,
                &global_min,
                &global_max);
    if(ER != ER_okay)
        return ER;

    //value range
    //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Range";
    size_t n = global_max - global_min;

    //Point Lists
    qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Point Lists";
    vector<vector<Point>> vValuePoints(n);
    switch (pMA_In2Fill->type()) {

    case CV_8UC1:
        for(int y = 0; y < pMA_In2Fill->rows; y++)
            for(int x = 0; x < pMA_In2Fill->cols; x++)
                if(pMA_FG_Mask->at<uchar>(y, x) > 0)
                    vValuePoints[pMA_In2Fill->at<uchar>(y, x) - global_min].push_back(Point(x, y));
        break;

    case CV_8SC1:
        for(int y = 0; y < pMA_In2Fill->rows; y++)
            for(int x = 0; x < pMA_In2Fill->cols; x++)
                if(pMA_FG_Mask->at<uchar>(y, x) > 0)
                    vValuePoints[pMA_In2Fill->at<char>(y, x) - global_min].push_back(Point(x, y));
        break;

    case CV_16UC1:
        for(int y = 0; y < pMA_In2Fill->rows; y++)
            for(int x = 0; x < pMA_In2Fill->cols; x++)
                if(pMA_FG_Mask->at<uchar>(y, x) > 0)
                    vValuePoints[pMA_In2Fill->at<ushort>(y, x) - global_min].push_back(Point(x, y));
        break;

    case CV_16SC1:
        for(int y = 0; y < pMA_In2Fill->rows; y++)
            for(int x = 0; x < pMA_In2Fill->cols; x++)
                if(pMA_FG_Mask->at<uchar>(y, x) > 0)
                    vValuePoints[pMA_In2Fill->at<short>(y, x) - global_min].push_back(Point(x, y));
        break;

    case CV_32SC1:
        for(int y = 0; y < pMA_In2Fill->rows; y++)
            for(int x = 0; x < pMA_In2Fill->cols; x++)
                if(pMA_FG_Mask->at<uchar>(y, x) > 0)
                    vValuePoints[pMA_In2Fill->at<int>(y, x) - global_min].push_back(Point(x, y));
        break;

    default:
        return ER_type_bad;
    }

    //Pad label image
    //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Pad label image";
    Mat MA_tmp_LabelPadded;
    ER = Padding(
                &MA_tmp_LabelPadded,
                pMA_InMarker,
                1,
                1,
                BORDER_REPLICATE);
    if(ER != ER_okay)
    {
        MA_tmp_LabelPadded.release();
        return ER;
    }

    //Buffer to remember previous step
    Mat MA_BufferPrevious;

    //Point offsets for neighborhood
    //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Neighbors";
    vector<Point> vNeighbors;
    if(connectivity == 8)
        vNeighbors = {Point(1, 1), Point(1, 0), Point(1, -1), Point(0, 1), Point(0, -1), Point(-1, 1), Point(-1, 0), Point(-1, -1)};
    else
        vNeighbors = {Point(1, 0), Point(0, 1), Point(0, -1), Point(-1, 0)};

    //loop values
    qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Loop values";
    for(size_t i_value = 0; i_value < n; i_value++)
    {
        qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Value:" << i_value + global_min;

        //repeat until nothing changes
        bool something_changed = true;
        while(something_changed)
        {
            //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Loop remaining points at current value";

            //save previous step in buffer
            MA_BufferPrevious = MA_tmp_LabelPadded.clone();

            //reset change indicator
            something_changed = false;

            //loop points with current value
            size_t i_point = 0;
            while(i_point < vValuePoints[i_value].size())
            {
                //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Point index:" << i_point;

                //point to check
                Point P = vValuePoints[i_value][i_point];

                //look for 1st label
                //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Look for 1st label";
                int label_1st;
                size_t i = 0;
                bool found_1st_label = false;
                while (!found_1st_label && i < vNeighbors.size())
                {
                    int label = MA_BufferPrevious.at<int>(P + vNeighbors[i]);
                    if(label > 0)
                    {
                        label_1st = label;
                        found_1st_label = true;
                    }

                    i++;
                }

                //look for more labels
                //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Look for 2nd label";
                bool found_2nd_label = false;
                if(found_1st_label)
                    while (!found_2nd_label && i < vNeighbors.size())
                    {
                        int label = MA_BufferPrevious.at<int>(P + vNeighbors[i]);
                        if(label > 0)
                            if(label != label_1st)
                                found_2nd_label = true;

                        i++;
                    }

                //write result
                if(found_2nd_label)
                {
                    //more than one label in neighborhood -> build a watershed
                    //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Build Watershed";
                    MA_tmp_LabelPadded.at<int>(P) = -1;
                    something_changed = true;
                    vValuePoints[i_value].erase(vValuePoints[i_value].begin() + i_point);
                }
                else if(found_1st_label)
                {
                    //only one label in neighborhood -> enlarge label region
                    //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Expand Label";
                    MA_tmp_LabelPadded.at<int>(P) = label_1st;
                    something_changed = true;
                    vValuePoints[i_value].erase(vValuePoints[i_value].begin() + i_point);
                }
                else
                {
                    //only increase index if no lable value was assigned
                    //(if one was assigned, vector is shortened instead)
                    //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Do nothing, increase coounter";
                    i_point++;
                }

                //next point with current value
            }

            //next loop for all remaining points with current value
        }

        //next value
    }

    //write output
    qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Write Output";
    ER = Crop_Rect_Abs(
                pMA_Out,
                &MA_tmp_LabelPadded,
                1,
                1,
                pMA_In2Fill->cols,
                pMA_In2Fill->rows);

    MA_BufferPrevious.release();
    MA_tmp_LabelPadded.release();
    //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Finished :-)";
    return ER;
}
*/

int D_Img_Proc::Transformation_Watershed_Custom(Mat *pMA_Out, Mat *pMA_In2Fill, Mat *pMA_InMarker, Mat *pMA_FG_Mask, int connectivity)
{
    //error checks
    //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Error checks";
    if(pMA_In2Fill->empty())                                                return ER_empty;
    if(pMA_InMarker->empty())                                               return ER_empty;
    if(pMA_FG_Mask->empty())                                                return ER_empty;
    if(pMA_In2Fill->channels() != 1)                                        return ER_channel_bad;
    if(pMA_InMarker->channels() != 1)                                       return ER_channel_bad;
    if(pMA_FG_Mask->channels() != 1)                                        return ER_channel_bad;
    if(pMA_InMarker->depth() != CV_32S)                                     return ER_bitdepth_bad;
    if(pMA_FG_Mask->depth() != CV_8U)                                       return ER_bitdepth_bad;
    if(pMA_FG_Mask->size() != pMA_InMarker->size())                         return ER_size_missmatch;
    if(pMA_FG_Mask->size() != pMA_In2Fill->size())                          return ER_size_missmatch;
    if(connectivity != 4 && connectivity != 8)                              return ER_parameter_bad;

    //Point offsets for neighborhood
    //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Neighbors";
    vector<Point> vNeighbors;
    if(connectivity == 8)
        vNeighbors = {Point(1, 1), Point(1, 0), Point(1, -1), Point(0, 1), Point(0, -1), Point(-1, 1), Point(-1, 0), Point(-1, -1)};
    else
        vNeighbors = {Point(1, 0), Point(0, 1), Point(0, -1), Point(-1, 0)};

    //init out
    *pMA_Out = pMA_InMarker->clone();

    //Queues sorted by values
    vector<Point>  vQueue_Points;
    vector<double> vQueue_Values;
    vector<int>    vQueue_Labels;

    //Init Queue
    //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Init Queue";
    for(int y = 0; y < pMA_In2Fill->rows; y++)
        for(int x = 0; x < pMA_In2Fill->cols; x++)
        {
            //current point
            Point point_current = Point(x, y);

            //check, if in mask area (area that shall be labeled)
            if(pMA_FG_Mask->at<uchar>(point_current) > 0)
            {
                //check, if not labeled by initial marker
                int label_current = pMA_Out->at<int>(point_current);
                if(label_current <= 0)
                {
                    //check, if a labeled neighbor exists
                    bool labeled_neighbor_found = false;
                    int label_neighbor;
                    size_t i = 0;
                    while(i < vNeighbors.size() && !labeled_neighbor_found)
                    {
                        //neighbor candidate
                        Point point_neighbor = point_current + vNeighbors[i];

                        //check if neighbor pixel is in image range
                        if(point_neighbor.x > 0 && point_neighbor.x < pMA_Out->cols && point_neighbor.y > 0 && point_neighbor.y < pMA_Out->rows)
                        {
                            //check if neighbour is in mask
                            if(pMA_FG_Mask->at<uchar>(point_neighbor) > 0)
                            {
                                //check if neighbour is labeled
                                label_neighbor = pMA_Out->at<int>(point_neighbor);
                                if(label_neighbor > 0)
                                    labeled_neighbor_found = true;
                            }
                        }

                        i++;
                    }

                    //labeled neighbor exists?
                    if(labeled_neighbor_found)
                    {
                        //get value at current posisiton
                        double  value_current = 0;
                        switch (pMA_In2Fill->type()) {
                        case CV_8UC1:   value_current = pMA_In2Fill->at<uchar>(point_current);      break;
                        case CV_8SC1:   value_current = pMA_In2Fill->at<char>(point_current);       break;
                        case CV_16UC1:  value_current = pMA_In2Fill->at<ushort>(point_current);     break;
                        case CV_16SC1:  value_current = pMA_In2Fill->at<short>(point_current);      break;
                        case CV_32SC1:  value_current = pMA_In2Fill->at<int>(point_current);        break;
                        case CV_32FC1:  value_current = pMA_In2Fill->at<float>(point_current);      break;
                        case CV_64FC1:  value_current = pMA_In2Fill->at<double>(point_current);     break;
                        default:                                                                    return ER_type_bad;}

                        //push to queue
                        //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "Init Queue" << "x/y" << x << y << "label" << label_current << label_neighbor << "value" << value_current;
                        size_t i = 0;
                        bool pushed = false;
                        while (!pushed && i < vQueue_Values.size())
                        {
                            if(value_current < vQueue_Values[i])
                            {
                                vQueue_Points.insert(vQueue_Points.begin() + i, point_current);
                                vQueue_Values.insert(vQueue_Values.begin() + i, value_current);
                                vQueue_Labels.insert(vQueue_Labels.begin() + i, label_neighbor);
                                pushed = true;
                            }

                            i++;
                        }
                        if(!pushed)
                        {
                            vQueue_Points.push_back(point_current);
                            vQueue_Values.push_back(value_current);
                            vQueue_Labels.push_back(label_neighbor);
                        }
                    }
                }
            }
        }

    //copy mask to indicate pixels that are allready in queue to avoid to add them multiple times
    Mat MA_tmp_PossibleQueueElement = pMA_FG_Mask->clone();

    //process queue
    //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "process queue";
    while(!vQueue_Points.empty())
    {
        //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "points in queue:" << vQueue_Points.size();

        //process 1st in queue
        Point   point_current = vQueue_Points[0];
        double  value_current = vQueue_Values[0];
        int     label_pusher  = vQueue_Labels[0];

        //erase from queue
        vQueue_Points.erase(vQueue_Points.begin());
        vQueue_Values.erase(vQueue_Values.begin());
        vQueue_Labels.erase(vQueue_Labels.begin());

        //write label of pusher to out
        pMA_Out->at<int>(point_current) = label_pusher;

        //push neigbours to queue
        for(size_t i = 0; i < vNeighbors.size(); i++)
        {
            //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "neighbor" << i;

            //neighbor candidate
            Point point_neighbor = point_current + vNeighbors[i];

            //neighbor in image range?
            if(point_neighbor.x > 0 && point_neighbor.x < pMA_Out->cols && point_neighbor.y > 0 && point_neighbor.y < pMA_Out->rows)
            {
                //neighbor in mask area and has not been added to queue yet?
                if(MA_tmp_PossibleQueueElement.at<uchar>(point_neighbor) > 0)
                {
                    //neighbor not labeled yet?
                    if(pMA_Out->at<int>(point_neighbor) == 0)
                    {
                        //get neighbor value
                        double value_2push = 0;
                        switch (pMA_In2Fill->type()) {
                        case CV_8UC1:   value_2push = pMA_In2Fill->at<uchar>(point_neighbor);   break;
                        case CV_8SC1:   value_2push = pMA_In2Fill->at<char>(point_neighbor);    break;
                        case CV_16UC1:  value_2push = pMA_In2Fill->at<ushort>(point_neighbor);  break;
                        case CV_16SC1:  value_2push = pMA_In2Fill->at<short>(point_neighbor);   break;
                        case CV_32SC1:  value_2push = pMA_In2Fill->at<int>(point_neighbor);     break;
                        case CV_32FC1:  value_2push = pMA_In2Fill->at<float>(point_neighbor);   break;
                        case CV_64FC1:  value_2push = pMA_In2Fill->at<double>(point_neighbor);  break;
                        default:        MA_tmp_PossibleQueueElement.release();                  return ER_type_bad;}

                        //correct value to current if lower than current ("fill valley")
                        if(value_2push < value_current)
                            value_2push = value_current;

                        //push value to queue
                        //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "push";
                        size_t i = 0;
                        bool pushed = false;
                        while (!pushed && i < vQueue_Values.size())
                        {
                            if(value_2push < vQueue_Values[i])
                            {
                                vQueue_Points.insert(vQueue_Points.begin() + i, point_neighbor);
                                vQueue_Values.insert(vQueue_Values.begin() + i, value_2push);
                                vQueue_Labels.insert(vQueue_Labels.begin() + i, label_pusher);
                                pushed = true;
                            }

                            i++;
                        }
                        if(!pushed)
                        {
                            vQueue_Points.push_back(point_neighbor);
                            vQueue_Values.push_back(value_2push);
                            vQueue_Labels.push_back(label_pusher);
                        }

                        //rememeber, that this pixel has been added to queue
                        MA_tmp_PossibleQueueElement.at<uchar>(point_neighbor) = 0;
                    }
                }
            }
        }
    }

    //qDebug() << "D_Img_Proc::Transformation_Watershed_Custom" << "end";

    return ER_okay;
}

int D_Img_Proc::Transformation_Fourier(Mat *pMA_Out, Mat *pMA_In, bool invers)
{
    if(pMA_In->empty())                                             return ER_empty;
    if((pMA_In->type() != CV_32F) && (pMA_In->type() != CV_64F))    return ER_bitdepth_bad;
    if((pMA_In->channels() != 1) && (pMA_In->channels() != 2))      return ER_channel_bad;

    if(invers)
    {
        idft(
                    *pMA_In,
                    *pMA_Out,
                    DFT_REAL_OUTPUT);
    }
    else
    {
        dft(
                    *pMA_In,
                    *pMA_Out,
                    DFT_REAL_OUTPUT);
    }

    return ER_okay;
}

int D_Img_Proc::Transformation_Fourier(Mat *pMA_Out, Mat *pMA_In_Re, bool invers, bool force_fft, bool out_real, int out_complex_mode, bool out_scale, bool out_center, bool out_nof0)
{
    if(pMA_In_Re->empty())  return ER_empty;

    //empty imaginary image
    Mat MA_tmp_EmptyImaginary = Mat::zeros(pMA_In_Re->size(), pMA_In_Re->type());

    //proc as complex (maybe replace later for performance boost)
    int ER = Transformation_Fourier(
                pMA_Out,
                pMA_In_Re,
                &MA_tmp_EmptyImaginary,
                false,
                invers,
                force_fft,
                out_real,
                out_complex_mode,
                out_scale,
                out_center,
                out_nof0);

    //clear & return
    MA_tmp_EmptyImaginary.release();
    return ER;
}

int D_Img_Proc::Transformation_Fourier(Mat *pMA_Out, Mat *pMA_In_Re, Mat *pMA_In_Im, bool complex_input, bool invers, bool force_fft, bool out_real, int out_complex_mode, bool out_scale, bool out_center, bool out_nof0)
{
    //errors 1
    if(pMA_In_Re->empty())                                                          return ER_okay;
    if(out_complex_mode > c_COMPLEX2REAL_ABS_SQUARE && pMA_In_Re->channels() != 1)  return ER_parameter_bad;
    if(out_complex_mode > c_COMPLEX2REAL_ABS_SQUARE && pMA_In_Im->channels() != 1)  return ER_parameter_bad;

    //fake imaginary?
    Mat MA_tmp_Im2Use;
    if(complex_input)
        MA_tmp_Im2Use = *pMA_In_Im;
    else
        MA_tmp_Im2Use = Mat::zeros(pMA_In_Re->size(), pMA_In_Re->type());

    //errors 2
    if(MA_tmp_Im2Use.empty())                              return ER_okay;
    if(pMA_In_Re->size() != MA_tmp_Im2Use.size())          {qDebug() << "D_Img_Proc::Transformation_Fourier FAIL pMA_In_Re->size() != MA_tmp_Im2Use.size()"; return ER_size_missmatch;}
    if(pMA_In_Re->channels() != MA_tmp_Im2Use.channels())  {qDebug() << "D_Img_Proc::Transformation_Fourier FAIL pMA_In_Re->channels() != MA_tmp_Im2Use.channels()"; return ER_channel_missmatch;}
    int ER = ER_okay;

    //convert to double
    Mat MA_tmp_double_Re;
    ER = Convert_Double(
                &MA_tmp_double_Re,
                pMA_In_Re);
    if(ER != ER_okay)
    {
        MA_tmp_double_Re.release();
        MA_tmp_Im2Use.release();
        qDebug() << "D_Img_Proc::Transformation_Fourier FAIL Real part to doule";
        return ER;
    }

    Mat MA_tmp_double_Im;
    ER = Convert_Double(
                &MA_tmp_double_Im,
                &MA_tmp_Im2Use);
    if(ER != ER_okay)
    {
        MA_tmp_double_Re.release();
        MA_tmp_double_Im.release();
        MA_tmp_Im2Use.release();
        qDebug() << "D_Img_Proc::Transformation_Fourier FAIL Imaginary part to double";
        return ER;
    }

    //channel splitting
    switch (pMA_In_Re->channels()) {

    case 1:
    {
        int ER = Transformation_Fourier_1C(
                    pMA_Out,
                    pMA_In_Re,
                    &MA_tmp_Im2Use,
                    invers,
                    force_fft,
                    out_real,
                    out_complex_mode,
                    out_scale,
                    out_center,
                    out_nof0);
        if(ER != ER_okay)
        {
            MA_tmp_double_Re.release();
            MA_tmp_double_Im.release();
            MA_tmp_Im2Use.release();
            qDebug() << "D_Img_Proc::Transformation_Fourier FAIL transform (channels: 1)";
            return ER;
        }
    }
        break;

    case 2:
    {
        //split
        Mat MA_tmp_in_Re[2];
        Mat MA_tmp_in_Im[2];
        split(
                    MA_tmp_double_Re,
                    MA_tmp_in_Re);
        split(
                    MA_tmp_double_Im,
                    MA_tmp_in_Im);

        //proc
        Mat MA_tmp_proccessed[2];
        for(int c = 0; c < pMA_In_Re->channels(); c++)
        {
            int ER = Transformation_Fourier_1C(
                        &(MA_tmp_proccessed[c]),
                        &(MA_tmp_in_Re[c]),
                        &(MA_tmp_in_Im[c]),
                        invers,
                        force_fft,
                        out_real,
                        out_complex_mode,
                        out_scale,
                        out_center,
                        out_nof0);
            if(ER != ER_okay)
            {
                MA_tmp_double_Re.release();
                MA_tmp_double_Im.release();
                MA_tmp_Im2Use.release();
                qDebug() << "D_Img_Proc::Transformation_Fourier FAIL transform (channels: 2)";
                return ER;
            }
            if(MA_tmp_proccessed[c].channels() != 1)
            {
                MA_tmp_double_Re.release();
                MA_tmp_double_Im.release();
                MA_tmp_Im2Use.release();
                qDebug() << "D_Img_Proc::Transformation_Fourier FAIL multiple channels complex view is not possible";
                return ER;
            }
        }

        //merge
        merge(
                    MA_tmp_proccessed,
                    pMA_In_Re->channels(),
                    *pMA_Out);

        //release buffers
        for(int c = 0; c < pMA_In_Re->channels(); c++)
        {
            MA_tmp_in_Re[c].release();
            MA_tmp_in_Im[c].release();
            MA_tmp_proccessed[c].release();
        }
    }
        break;

    case 3:
    {
        //split
        Mat MA_tmp_in_Re[3];
        Mat MA_tmp_in_Im[3];
        split(
                    MA_tmp_double_Re,
                    MA_tmp_in_Re);
        split(
                    MA_tmp_double_Im,
                    MA_tmp_in_Im);

        //proc
        Mat MA_tmp_proccessed[3];
        for(int c = 0; c < pMA_In_Re->channels(); c++)
        {
            int ER = Transformation_Fourier_1C(
                        &(MA_tmp_proccessed[c]),
                        &(MA_tmp_in_Re[c]),
                        &(MA_tmp_in_Im[c]),
                        invers,
                        force_fft,
                        out_real,
                        out_complex_mode,
                        out_scale,
                        out_center,
                        out_nof0);
            if(ER != ER_okay)
            {
                MA_tmp_double_Re.release();
                MA_tmp_double_Im.release();
                MA_tmp_Im2Use.release();
                qDebug() << "D_Img_Proc::Transformation_Fourier FAIL transform (channels: 3)";
                return ER;
            }
            if(MA_tmp_proccessed[c].channels() != 1)
            {
                MA_tmp_double_Re.release();
                MA_tmp_double_Im.release();
                MA_tmp_Im2Use.release();
                qDebug() << "D_Img_Proc::Transformation_Fourier FAIL multiple channels complex view is not possible";
                return ER;
            }
        }

        //merge
        merge(
                    MA_tmp_proccessed,
                    pMA_In_Re->channels(),
                    *pMA_Out);

        //release buffers
        for(int c = 0; c < pMA_In_Re->channels(); c++)
        {
            MA_tmp_in_Re[c].release();
            MA_tmp_in_Im[c].release();
            MA_tmp_proccessed[c].release();
        }
    }
        break;

    case 4:
    {
        //split
        Mat MA_tmp_in_Re[4];
        Mat MA_tmp_in_Im[4];
        split(
                    MA_tmp_double_Re,
                    MA_tmp_in_Re);
        split(
                    MA_tmp_double_Im,
                    MA_tmp_in_Im);

        //proc
        Mat MA_tmp_proccessed[4];
        for(int c = 0; c < pMA_In_Re->channels(); c++)
        {
            int ER = Transformation_Fourier_1C(
                        &(MA_tmp_proccessed[c]),
                        &(MA_tmp_in_Re[c]),
                        &(MA_tmp_in_Im[c]),
                        invers,
                        force_fft,
                        out_real,
                        out_complex_mode,
                        out_scale,
                        out_center,
                        out_nof0);
            if(ER != ER_okay)
            {
                MA_tmp_double_Re.release();
                MA_tmp_double_Im.release();
                MA_tmp_Im2Use.release();
                qDebug() << "D_Img_Proc::Transformation_Fourier FAIL transform (channels: 4)";
                return ER;
            }
            if(MA_tmp_proccessed[c].channels() != 1)
            {
                MA_tmp_double_Re.release();
                MA_tmp_double_Im.release();
                MA_tmp_Im2Use.release();
                qDebug() << "D_Img_Proc::Transformation_Fourier FAIL multiple channels complex view is not possible";
                return ER;
            }
        }

        //merge
        merge(
                    MA_tmp_proccessed,
                    pMA_In_Re->channels(),
                    *pMA_Out);

        //release buffers
        for(int c = 0; c < pMA_In_Re->channels(); c++)
        {
            MA_tmp_in_Re[c].release();
            MA_tmp_in_Im[c].release();
            MA_tmp_proccessed[c].release();
        }
    }
        break;

    default:
        break;
    }

    MA_tmp_double_Re.release();
    MA_tmp_double_Im.release();
    MA_tmp_Im2Use.release();
    return ER_okay;
}

int D_Img_Proc::Transformation_Fourier_1C(Mat *pMA_Out, Mat *pMA_In_Re, Mat *pMA_In_Im, bool invers, bool force_fft, bool out_real, int out_complex_mode, bool out_scale, bool out_center, bool out_nof0)
{
    //Errors
    qDebug() << "D_Img_Proc::Transformation_Fourier_1C Errors";
    if(pMA_In_Re->empty())                              return ER_empty;
    if(pMA_In_Im->empty())                              return ER_empty;
    if(pMA_In_Re->channels() != 1)                      return ER_channel_bad;
    if(pMA_In_Im->channels() != 1)                      return ER_channel_bad;
    if(pMA_In_Re->size() != pMA_In_Im->size())          {qDebug() << "D_Img_Proc::Transformation_Fourier_1C FAIL pMA_In_Re->size() != pMA_In_Im->size()"; return ER_size_missmatch;}
    if(pMA_In_Re->depth() != CV_64F)                    return ER_bitdepth_bad;
    if(pMA_In_Im->depth() != CV_64F)                    return ER_bitdepth_bad;
    if(out_complex_mode < 0)                            return ER_parameter_bad;
    if(out_complex_mode >= c_COMPLEX2REAL_NUMBER_OF)    return ER_parameter_bad;
    int ER = ER_okay;

    //Pad to get optimal size for fft instead of dft
    qDebug() << "D_Img_Proc::Transformation_Fourier_1C Padding 2 force FFT";
    Mat MA_tmp_OptSize_Re;
    Mat MA_tmp_OptSize_Im;
    if(force_fft)
    {
        int opt_rows = getOptimalDFTSize(pMA_In_Re->rows);
        int opt_cols = getOptimalDFTSize(pMA_In_Re->rows);
        qDebug() << "D_Img_Proc::Transformation_Fourier_1C Padding 2 force FFT:";
        copyMakeBorder(
                    *pMA_In_Re,
                    MA_tmp_OptSize_Re,
                    0,
                    opt_rows - pMA_In_Re->rows,
                    0,
                    opt_cols - pMA_In_Re->cols,
                    BORDER_CONSTANT,
                    Scalar::all(0));
        copyMakeBorder(
                    *pMA_In_Im,
                    MA_tmp_OptSize_Im,
                    0,
                    opt_rows - pMA_In_Re->rows,
                    0,
                    opt_cols - pMA_In_Re->cols,
                    BORDER_CONSTANT,
                    Scalar::all(0));
    }
    else
    {
        MA_tmp_OptSize_Re = *pMA_In_Re;
        MA_tmp_OptSize_Im = *pMA_In_Im;
    }

    //merge to complex (2-channel) image
    qDebug() << "D_Img_Proc::Transformation_Fourier_1C merge to complex";
    Mat MA_tmp_InComplexArray[] = {MA_tmp_OptSize_Re, MA_tmp_OptSize_Im};
    Mat MA_tmp_InComplex;
    merge(
                MA_tmp_InComplexArray,
                2,
                MA_tmp_InComplex);

    //flags for the dft
    qDebug() << "D_Img_Proc::Transformation_Fourier_1C flags";
    int flags = DFT_COMPLEX_INPUT;
    if(invers)          flags = flags | DFT_INVERSE;
    if(out_real)        flags = flags | DFT_REAL_OUTPUT;
    if(out_scale)       flags = flags | DFT_SCALE;

    //do the dft/fft (chosen automatically based on image size)
    qDebug() << "D_Img_Proc::Transformation_Fourier_1C do the dft/fft";
    Mat MA_tmp_Trasformed;
    dft(
                MA_tmp_InComplex,
                MA_tmp_Trasformed,
                flags);

    //eliminate complexity (real values remain)
    qDebug() << "D_Img_Proc::Transformation_Fourier_1C complex 2 real";
    //containers
    Mat MA_tmp_Transformed_Real;
    ER = Convert_Complex2Real_1C(
                &MA_tmp_Transformed_Real,
                &MA_tmp_Trasformed,
                out_complex_mode);
    if(ER != ER_okay)
    {
        MA_tmp_InComplex.release();
        MA_tmp_OptSize_Im.release();
        MA_tmp_OptSize_Re.release();
        MA_tmp_Trasformed.release();
        MA_tmp_InComplexArray->release();
        MA_tmp_Transformed_Real.release();
        return ER;
    }


    //crop (remove added values for optimal size)
    qDebug() << "D_Img_Proc::Transformation_Fourier_1C crop (if fft was used)";
    Mat MA_tmp_Croped;
    if(force_fft)
        MA_tmp_Croped = MA_tmp_Transformed_Real(
                    Rect(
                        0,
                        0,
                        MA_tmp_Transformed_Real.cols & -2,  //magic trick i don't understand: https://docs.opencv.org/2.4/doc/tutorials/core/discrete_fourier_transform/discrete_fourier_transform.html
                        MA_tmp_Transformed_Real.rows & -2));
    else
        MA_tmp_Croped = MA_tmp_Transformed_Real;

    //center the image
    qDebug() << "D_Img_Proc::Transformation_Fourier_1C centering";
    Mat MA_tmp_Centerd;
    if(out_center)
    {
        //centers
        int center_x = MA_tmp_Croped.cols/2;
        int center_y = MA_tmp_Croped.rows/2;
        //Create a ROI per quadrant
        Mat q0(MA_tmp_Croped, Rect( 0,          0,          center_x,   center_y));     // Top-Left
        Mat q1(MA_tmp_Croped, Rect( center_x,   0,          center_x,   center_y));     // Top-Right
        Mat q2(MA_tmp_Croped, Rect( 0,          center_y,   center_x,   center_y));     // Bottom-Left
        Mat q3(MA_tmp_Croped, Rect( center_x,   center_y,   center_x,   center_y));     // Bottom-Right
        // swap quadrants (Top-Left with Bottom-Right)
        Mat MA_tmp_CopyAssistant;
        q0.copyTo(MA_tmp_CopyAssistant);
        q3.copyTo(q0);
        MA_tmp_CopyAssistant.copyTo(q3);
        // swap quadrant (Top-Right with Bottom-Left)
        q1.copyTo(MA_tmp_CopyAssistant);
        q2.copyTo(q1);
        MA_tmp_CopyAssistant.copyTo(q2);
        //export centered image
        MA_tmp_Centerd = MA_tmp_Croped;
        //release buffer
        MA_tmp_CopyAssistant.release();
    }
    else
        MA_tmp_Centerd = MA_tmp_Croped;

    //set center to 0
    qDebug() << "D_Img_Proc::Transformation_Fourier_1C set value(f=0) = 0";
    if(out_nof0)
    {
        if(MA_tmp_Centerd.channels() == 1)
            MA_tmp_Centerd.at<double>(MA_tmp_Croped.rows/2, MA_tmp_Croped.cols/2) = 0;
        else if(MA_tmp_Centerd.channels() == 2)
            MA_tmp_Centerd.at<Vec2d>(MA_tmp_Croped.rows/2, MA_tmp_Croped.cols/2) = Vec2d(0,0);
        else if(MA_tmp_Centerd.channels() == 3)
            MA_tmp_Centerd.at<Vec3d>(MA_tmp_Croped.rows/2, MA_tmp_Croped.cols/2) = Vec3d(0,0,0);
        else
            return ER_other;
    }

    //export result
    *pMA_Out = MA_tmp_Centerd.clone();

    //release buffer Mats
    MA_tmp_Croped.release();
    MA_tmp_Centerd.release();
    MA_tmp_InComplex.release();
    MA_tmp_OptSize_Im.release();
    MA_tmp_OptSize_Re.release();
    MA_tmp_Trasformed.release();
    MA_tmp_InComplexArray->release();
    MA_tmp_Transformed_Real.release();

    return ER_okay;
}

int D_Img_Proc::Segmentation_GaussDistWater(Mat *pMA_Out, Mat *pMA_In, int size, double sigma, double thres, double distance, bool include_not_seeded, bool conv_8bit, bool exclude_border)
{
    int ER;

    //blur & thres
    Mat MA_tmp_binary;
    ER = Threshold_BlurThres(
                &MA_tmp_binary,
                pMA_In,
                size,
                sigma,
                thres);
    if(ER != ER_okay)
    {
        MA_tmp_binary.release();
        return ER;
    }

    //segmentation
    ER = Transformation_Watershed_Auto(
                pMA_Out,
                &MA_tmp_binary,
                distance,
                include_not_seeded,
                conv_8bit,
                exclude_border);
    if(ER != ER_okay)
    {
        MA_tmp_binary.release();
        return ER;
    }

    MA_tmp_binary.release();
    return ER;
}

int D_Img_Proc::Filter_Box(Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y, int border, int out_depth, bool norm)
{
    if(pMA_In->empty())     return ER_empty;

    boxFilter(
                *pMA_In,
                *pMA_Out,
                out_depth,
                Size(2*size_x + 1, 2*size_y + 1),
                Point(-1, -1),
                norm,
                border);
    return ER_okay;
}

int D_Img_Proc::Filter_Box_RMS(Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y, int border, int out_depth, bool norm)
{
    if(pMA_In->empty())     return ER_empty;

    sqrBoxFilter(
                *pMA_In,
                *pMA_Out,
                out_depth,
                Size(2*size_x + 1, 2*size_y + 1),
                Point(-1, -1),
                norm,
                border);

    return ER_okay;
}

int D_Img_Proc::Filter_Gauss(Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y, int border, double sigma_x, double sigma_y)
{
    if(pMA_In->empty())     return ER_empty;

    GaussianBlur(
                *pMA_In,
                *pMA_Out,
                Size(2*size_x + 1, 2*size_y + 1),
                sigma_x,
                sigma_y,
                border);
    return ER_okay;
}

int D_Img_Proc::Filter_Median(Mat *pMA_Out, Mat *pMA_In, int size)
{
    if(pMA_In->empty())                             return ER_empty;
    if((pMA_In->depth() == CV_64F))                 return ER_type_bad;
    if((pMA_In->depth() == CV_32F) && (size > 3))   return ER_type_bad;

    medianBlur(
                *pMA_In,
                *pMA_Out,
                2*size + 1);
    return ER_okay;
}

/*!
 * \brief D_Img_Proc::Filter_Median performs median filtering with huang algorithm.
 * \details Any binary mask can be used. Non binary masks will be binarized automatically.
 * \details Unsigned 8bit and 16bit images are supported.
 * \details Multichanneled images are treated channel by channel.
 * \details Calls Filter_RankOrder with quantil_relPos=0.5.
 * \param pMA_Out pointer to output image
 * \param pMA_In pointer to input image (CV_8U or CV_16U)
 * \param pMA_Mask pointer to mask image (binary)
 * \return error code
 */
int D_Img_Proc::Filter_Median(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask)
{
    return Filter_RankOrder(
                pMA_Out,
                pMA_In,
                pMA_Mask,
                0.5);
}

/*!
 * \brief D_Img_Proc::Filter_RankOrder performs Rank order filtering with huang algorithm for any quantile.
 * \details Parallelized implementation of Huang's local histogram based rank oder filterig for any quantile.
 * \details Any binary mask can be used. Non binary masks will be binarized automatically.
 * \details Any quantile (0.0 to 1.0) is supported. Special cases for min and max filtering are implemented.
 * \details Unsigned 8bit and 16bit images are supported.
 * \details Multichanneled images are treated channel by channel.
 * \param pMA_Out pointer to output image
 * \param pMA_In pointer to input image (CV_8U or CV_16U)
 * \param pMA_Mask pointer to mask image (binary)
 * \param quantil_relPos qunatile value from 0.0 to 1.0. Speical cases: 0.0->min, 0.5->median, 1.0-> max
 * \return error code
 */
int D_Img_Proc::Filter_RankOrder(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, double quantil_relPos)
{
    if(pMA_In->empty())                             return ER_empty;
    if(pMA_Mask->empty())                           return ER_empty;
    if(pMA_Mask->channels() != pMA_In->channels())  return ER_channel_missmatch;

    switch (pMA_In->channels()) {

    case 1:
    {
        int ER = Filter_RankOrder_1C(
                    pMA_Out,
                    pMA_In,
                    pMA_Mask,
                    quantil_relPos);
        if(ER != ER_okay)   return ER;
    }
        break;

    case 2:
    {
        Mat MA_tmp_in[2];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_thres[2];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Filter_RankOrder_1C(
                        &(MA_tmp_thres[c]),
                        &(MA_tmp_in[c]),
                        pMA_Mask,
                        quantil_relPos);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_thres,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_thres[c].release();
        }
    }
        break;

    case 3:
    {
        Mat MA_tmp_in[3];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_thres[3];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Filter_RankOrder_1C(
                        &(MA_tmp_thres[c]),
                        &(MA_tmp_in[c]),
                        pMA_Mask,
                        quantil_relPos);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_thres,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_thres[c].release();
        }
    }
        break;

    case 4:
    {
        Mat MA_tmp_in[4];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_thres[4];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Filter_RankOrder_1C(
                        &(MA_tmp_thres[c]),
                        &(MA_tmp_in[c]),
                        pMA_Mask,
                        quantil_relPos);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_thres,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_thres[c].release();
        }
    }
        break;

    default:
        break;
    }

    return ER_okay;
}

/*!
 * \brief D_Img_Proc::Filter_RankOrder_Circular special case of Filter_RankOrder
 * \param pMA_Out pointer to output image
 * \param pMA_In pointer to input image (CV_8U or CV_16U)
 * \param pMA_Mask pointer to mask image (binary)
 * \param quantil_relPos qunatile value from 0.0 to 1.0. Speical cases: 0.0->min, 0.5->median, 1.0-> max
 * \param radius mask radius
 * \return error code
 */
int D_Img_Proc::Filter_RankOrder_Circular(Mat *pMA_Out, Mat *pMA_In, double quantil_relPos, double radius)
{
    if(pMA_In->empty())         return ER_empty;
    if(radius < 0)              return ER_parameter_bad;

    //image size must be an odd int
    int img_size = 2 * static_cast<int>(radius) + 1;

    //generate mask
    Mat MA_tmp_Mask_1C;
    Generate_byValueFunction(
                &MA_tmp_Mask_1C,
                img_size,
                img_size,
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_ELLIPSE,
                    radius,
                    img_size / 2,
                    radius,
                    img_size / 2,
                    1,
                    0,
                    0,
                    0));

    //apply filter
    int ER = Filter_RankOrder(
                pMA_Out,
                pMA_In,
                &MA_tmp_Mask_1C,
                quantil_relPos);

    MA_tmp_Mask_1C.release();
    return ER;
}

/*!
 * \brief D_Img_Proc::Filter_RankOrder_Rect special case of Filter_RankOrder for rect masks
 * \param pMA_Out pointer to output image
 * \param pMA_In pointer to input image (CV_8U or CV_16U)
 * \param pMA_Mask pointer to mask image (binary)
 * \param quantil_relPos qunatile value from 0.0 to 1.0. Speical cases: 0.0->min, 0.5->median, 1.0-> max
 * \param size_x mask size x
 * \param size_y mask size y
 * \return error code
 */
int D_Img_Proc::Filter_RankOrder_Rect(Mat *pMA_Out, Mat *pMA_In, double quantil_relPos, int size_x, int size_y)
{
    if(size_x < 1)                          return ER_parameter_bad;
    if(size_y < 1)                          return ER_parameter_bad;
    if(size_x % 2 != 1)                     return ER_parameter_bad;
    if(size_y % 2 != 1)                     return ER_parameter_bad;

    //generate mask
    Mat MA_tmp_Mask_1C = Mat::ones(size_y, size_x, CV_64FC1);

    //apply filter
    int ER = Filter_RankOrder(
                pMA_Out,
                pMA_In,
                &MA_tmp_Mask_1C,
                quantil_relPos);

    MA_tmp_Mask_1C.release();
    return ER;
}

/*!
 * \brief D_Img_Proc::Filter_RankOrder_1C performs Rank order filtering with huang algorithm for any quantile.
 * \details Parallelized implementation of Huang's local histogram based rank oder filterig for any quantile.
 * \details Any binary mask can be used. Non binary masks will be binarized automatically.
 * \details Any quantile (0.0 to 1.0) is supported. Special cases for min and max filtering are implemented.
 * \details Unsigned 8bit and 16bit single channel images are supported.
 * \param pMA_Out pointer to output image
 * \param pMA_In pointer to input image (CV_8UC1 or CV_16UC1)
 * \param pMA_Mask pointer to mask image (binary)
 * \param quantil_relPos qunatile value from 0.0 to 1.0. Speical cases: 0.0->min, 0.5->median, 1.0-> max
 * \return error code
 */
int D_Img_Proc::Filter_RankOrder_1C(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, double quantil_relPos)
{
    //------------------------------------------------------- Error checks

    //Errors
    if(pMA_In->empty())                                         return ER_empty;
    if(pMA_Mask->empty())                                       return ER_empty;
    if(pMA_In->channels() != 1)                                 return ER_channel_bad;
    if(pMA_Mask->channels() != 1)                               return ER_channel_bad;
    if(pMA_In->depth() != CV_8U && pMA_In->depth() != CV_16U)   return ER_bitdepth_bad;
    if(quantil_relPos < 0 || quantil_relPos > 1)                return ER_parameter_bad;
    int ER = ER_okay;


    //------------------------------------------------------- image and mask parameters

    //input img parameters
    //sizes
    size_t img_in_sy = pMA_In->rows;
    size_t img_in_sx = pMA_In->cols;

    //mask parameters
    //sizes
    int mask_sx = pMA_Mask->cols;
    int mask_sy = pMA_Mask->rows;
    //centers
    int mask_cx = mask_sx / 2;
    int mask_cy = mask_sy / 2;
    //center to border
    int mask_c2l = 0 - mask_cx;
    int mask_c2r = mask_sx - mask_cx - 1;
    int mask_c2t = 0 - mask_cy;
    int mask_c2b = mask_sy - mask_cy - 1;


    //------------------------------------------------------- mask preprocessing

    //binarize mask (should be binary input, but just to be safe it is binarized)
    Mat MA_tmp_MaskBinary;
    ER = Threshold_Relative_1C(
                &MA_tmp_MaskBinary,
                pMA_Mask,
                1,
                0);
    if(ER != ER_okay)
    {
        MA_tmp_MaskBinary.release();
        return ER;
    }

    //------------------------------------------------------- border handling

    //pad input image
    Mat MA_tmp_InPadded;
    ER = Padding(
                &MA_tmp_InPadded,
                pMA_In,
                abs(mask_c2r),
                abs(mask_c2l),
                abs(mask_c2t),
                abs(mask_c2b),
                BORDER_REPLICATE);
    if(ER != ER_okay)
    {
        MA_tmp_MaskBinary.release();
        MA_tmp_InPadded.release();
        return ER;
    }

    //------------------------------------------------------- init out image

    //init output
    *pMA_Out = Mat(pMA_In->size(), pMA_In->type());


    //------------------------------------------------------- histogram params

    //get range of values to deal with (for size of histogram)
    double val_min;
    double val_max;
    ER = MinMax_of_Mat_1C(
                pMA_In,
                &val_min,
                &val_max);
    if(ER != ER_okay)
    {
        MA_tmp_MaskBinary.release();
        MA_tmp_InPadded.release();
        return ER;
    }


    //------------------------------------------------------- relative coordinates for shifting

    //lists of indices to add/remove on shift
    vector<Point> vBorderL;
    vector<Point> vBorderR;
    vector<Point> vBorderT;
    vector<Point> vBorderB;
    size_t mask_relevant_px_count = 0;

    //init shift inidices
    for(int y = 0; y < mask_sy; y++)
        for(int x = 0; x < mask_sx; x++)
        {
            //current point (relative corrdinates) & value
            Point P_rel = Point(x - mask_cx, y - mask_cy);
            uchar Val_Mask = MA_tmp_MaskBinary.at<uchar>(y, x);

            //count relevant pixels (needed for beeing able to calc in absolute not relative quantities)
            if(Val_Mask != 0)
                mask_relevant_px_count++;

            //if position is at border of possible relevant mask
            //covered area or next to a mask background pixel in
            //relation to current "moving direction",
            //it is added to list of relative border corrdinates

            //check left border
            if(x == 0)
            {
                if(Val_Mask > 0)
                    vBorderL.push_back(P_rel);
            }
            else
            {
                if(Val_Mask > MA_tmp_MaskBinary.at<uchar>(y, x-1))
                    vBorderL.push_back(P_rel);
            }

            //check right border
            if(x == mask_sx - 1)
            {
                if(Val_Mask > 0)
                    vBorderR.push_back(P_rel);
            }
            else
            {
                if(Val_Mask > MA_tmp_MaskBinary.at<uchar>(y, x+1))
                    vBorderR.push_back(P_rel);
            }

            //check top border
            if(y == 0)
            {
                if(Val_Mask > 0)
                    vBorderT.push_back(P_rel);
            }
            else
            {
                if(Val_Mask > MA_tmp_MaskBinary.at<uchar>(y-1, x))
                    vBorderT.push_back(P_rel);
            }

            //check bottom border
            if(y == mask_sy - 1)
            {
                if(Val_Mask > 0)
                    vBorderB.push_back(P_rel);
            }
            else
            {
                if(Val_Mask > MA_tmp_MaskBinary.at<uchar>(y+1, x))
                    vBorderB.push_back(P_rel);
            }
        }


    //======================================================================    thread & synch

    //threads
    size_t thread_count = getNumberOfCPUs();
    vector<thread> v_threads(thread_count);
    vector<int> v_ER(thread_count);

    //start threads
    for(size_t t = 0; t < thread_count; t++)
    {
        //range for thread
        int y_start   = (((t    ) / static_cast<double>(thread_count))) * img_in_sy;
        int y_end     = (((t + 1) / static_cast<double>(thread_count))) * img_in_sy;

        //start thread
        v_threads[t] = thread(
                    Filter_RankOrder_1C_Thread,
                    pMA_Out,
                    &MA_tmp_InPadded,
                    &MA_tmp_MaskBinary,
                    quantil_relPos,
                    img_in_sx,
                    y_start,
                    y_end,
                    val_max,
                    mask_relevant_px_count,
                    &vBorderL,
                    &vBorderR,
                    &vBorderT,
                    &vBorderB);
    }

    //join threads
    for(size_t t = 0; t < thread_count; t++)
    {
        v_threads[t].join();
    }

    //finish
    MA_tmp_MaskBinary.release();
    MA_tmp_InPadded.release();
    return ER;
}

/*!
 * \brief D_Img_Proc::Filter_RankOrder_1C_Thread performs Rank order filtering with huang algorithm for any quantile on a region of an image
 * \details Used as in separte threads in Filter_RankOrder_1C
 * \details Parallelized implementation of Huang's local histogram based rank oder filterig for any quantile.
 * \details Any binary mask can be used. Non binary masks will be binarized automatically.
 * \details Any quantile (0.0 to 1.0) is supported. Special cases for min and max filtering are implemented.
 * \details Unsigned 8bit and 16bit single channel images are supported.
 * \param pMA_Out pointer to output image
 * \param pMA_In pointer to padded input image (CV_8UC1 or CV_16UC1)
 * \param pMA_Mask pointer to mask image (binary)
 * \param quantil_relPos qunatile value from 0.0 to 1.0. Speical cases: 0.0->min, 0.5->median, 1.0-> max
 * \param y_start start line of ROI
 * \param y_end end line of ROI
 * \param val_max size of local histogram (max value in image)
 * \param mask_relevant_px_count count of mask foreground pixels
 * \param vBorderL list of relative coordinates of pixels to add when moving left / removing when moving right
 * \param vBorderR list of relative coordinates of pixels to add when moving right / removing when moving left
 * \param vBorderT list of relative coordinates of pixels to add when moving up / removing when moving down
 * \param vBorderB list of relative coordinates of pixels to add when moving down / removing when moving up
 * \return error code
 */
int D_Img_Proc::Filter_RankOrder_1C_Thread(Mat *pMA_Out, Mat *pMA_InPadded, Mat *pMA_Mask, double quantil_relPos, size_t img_in_sx, size_t y_start, size_t y_end, double val_max, size_t mask_relevant_px_count, vector<Point> *vBorderL, vector<Point> *vBorderR, vector<Point> *vBorderT, vector<Point> *vBorderB)
{
    //------------------------------------------------------- Error checks

    //Errors
    if(pMA_InPadded->empty())                                               return ER_empty;
    if(pMA_Mask->empty())                                                   return ER_empty;
    if(pMA_InPadded->channels() != 1)                                       return ER_channel_bad;
    if(pMA_Mask->channels() != 1)                                           return ER_channel_bad;
    if(pMA_InPadded->depth() != CV_8U && pMA_InPadded->depth() != CV_16U)   return ER_bitdepth_bad;
    if(quantil_relPos < 0 || quantil_relPos > 1)                            return ER_parameter_bad;
    if(mask_relevant_px_count <= 0)                                         return ER_empty;


    //------------------------------------------------------- image and mask parameters

    //input img and ROI parameters
    //max index
    size_t x_min = 0;
    size_t x_max = img_in_sx - 1;
    size_t y_min = y_start;
    size_t y_max = y_end - 1;

    //mask parameters
    //sizes
    int mask_sx = pMA_Mask->cols;
    int mask_sy = pMA_Mask->rows;
    //centers
    int mask_cx = mask_sx / 2;
    int mask_cy = mask_sy / 2;


    //------------------------------------------------------- create and init histogram

    //create histogram
    vector<size_t> hist(static_cast<size_t>(val_max + 1), 0);

    //init hist
    for(int y = 0; y < mask_sy; y++)
        for(int x = 0; x < mask_sx; x++)
            if(pMA_Mask->at<uchar>(y, x) > 0)
                switch (pMA_InPadded->type()) {

                case CV_8UC1:
                    hist[pMA_InPadded->at<uchar>(y + y_start, x)]++;
                    break;

                case CV_16UC1:
                    hist[pMA_InPadded->at<ushort>(y + y_start, x)]++;
                    break;

                default:
                    return ER_type_bad;
                }

    //------------------------------------------------------- inital quantil

    //list of mask congruent pixel values at start position
    vector<double> values_init;

    //get the values of inital value list
    for(int y = 0; y < mask_sy; y++)
        for(int x = 0; x < mask_sx; x++)
            if(pMA_Mask->at<uchar>(y, x) > 0)
                switch (pMA_InPadded->type()) {

                case CV_8UC1:
                    values_init.push_back(static_cast<double>(pMA_InPadded->at<uchar>(y + y_start, x)));
                    break;

                case CV_16UC1:
                    values_init.push_back(static_cast<double>(pMA_InPadded->at<ushort>(y + y_start, x)));
                    break;

                default:
                    return ER_type_bad;
                }

    //init quantil value
    sort(values_init.begin(), values_init.end());
    double quantil_val = values_init[(values_init.size() - 1) * quantil_relPos];


    //------------------------------------------------------- advcanced looping parameters

    //looping parameters
    bool at_end = false;
    size_t x = x_min;           //start at 0. changed to x=1 at first iteration step. pos 0|y_start allready calced int init above
    size_t y = y_min;
    int direction = c_DIR2D_R;


    //------------------------------------------------------- assistant values for quantil value calculation on steps

    //count of values smaller than quantil value
    size_t mass_smaller = 0;
    for(size_t i = 0; i < static_cast<size_t>(quantil_val); i++)
        mass_smaller += hist[i];

    //count of values equal to quantil value
    size_t mass_quantil = hist[static_cast<size_t>(quantil_val)];

    //count of values greater than quantil value
    size_t mass_greater = 0;
    for(size_t i = static_cast<size_t>(quantil_val) + 1; i < hist.size(); i++)
        mass_greater += hist[i];

    //comparison value of needed absolute count for quantil determination
    double mass_smaller_or_equal_needed = quantil_relPos * static_cast<double>(mask_relevant_px_count);
    double mass_greater_or_equal_needed = (1.0 - quantil_relPos) * static_cast<double>(mask_relevant_px_count);

    //quantil == min
    if(quantil_relPos == 0)
    {
        mass_smaller_or_equal_needed = 0.5;
        mass_greater_or_equal_needed = mask_relevant_px_count - 0.5;
    }
    //quantil == max
    if(quantil_relPos == 1)
    {
        mass_smaller_or_equal_needed = mask_relevant_px_count - 0.5;
        mass_greater_or_equal_needed = 0.5;
    }


    //------------------------------------------------------- line reset parameters

    //histo and masses at start of line
    vector<size_t> hist_line_begin = hist;
    size_t mass_smaller_line_begin = mass_smaller;
    size_t mass_quantil_line_begin = mass_quantil;
    size_t mass_greater_line_begin = mass_greater;
    double quantil_val_line_begin  = quantil_val;

    //------------------------------------------------------- loop image and type switch

    //type switch
    switch (pMA_InPadded->type()) {

    //------------------------------------------------------- CV_8UC1 start
    case CV_8UC1:
    {
        //write inital quantil value
        pMA_Out->at<uchar>(y_min, x_min) = quantil_val;

        //loop until end of image
        while(!at_end)
        {
            //------------------------------------------------------- change position

            //change indices based on direction
            switch (direction) {
            case c_DIR2D_R:     x++;    break;
            case c_DIR2D_D:     y++;    break;
            default:                    return ER_parameter_bad;}


            //------------------------------------------------------- add/remove list/offsets for current direction

            vector<Point> *vBorderAdd;
            vector<Point> *vBorderRem;
            int dx_to_prev_pos = 0;
            int dy_to_prev_pos = 0;
            switch (direction) {
            case c_DIR2D_R:     vBorderAdd = vBorderR;      vBorderRem = vBorderL;      dx_to_prev_pos = -1;    break;
            case c_DIR2D_D:     vBorderAdd = vBorderB;      vBorderRem = vBorderT;      dy_to_prev_pos = -1;    break;
            default:                                                                                            return ER_other;}


            //======================================================= add/remove values for current pixel (start)

            //loop add/remove lists of relative coordinates
            for(size_t i = 0; i < vBorderAdd->size(); i++)
            {
                //get values to add/remove
                uchar val_add = pMA_InPadded->at<uchar>(y + mask_cy + (*vBorderAdd)[i].y,                  x + mask_cx + (*vBorderAdd)[i].x);
                uchar val_rem = pMA_InPadded->at<uchar>(y + mask_cy + (*vBorderRem)[i].y + dy_to_prev_pos, x + mask_cx + (*vBorderRem)[i].x + dx_to_prev_pos);

                //update histogram
                hist[val_add]++;
                hist[val_rem]--;

                //update masses
                //add
                if(val_add > quantil_val)           mass_greater++;
                else if (val_add < quantil_val)     mass_smaller++;
                else                                mass_quantil++;
                //remove
                if(val_rem > quantil_val)           mass_greater--;
                else if (val_rem < quantil_val)     mass_smaller--;
                else                                mass_quantil--;

                //mass checks
                bool check_smaller = mass_smaller + mass_quantil >= mass_smaller_or_equal_needed;
                bool check_greater = mass_greater + mass_quantil >= mass_greater_or_equal_needed;

                //update quantil value
                //decrease quantil value?
                if(check_smaller && !check_greater)
                {
                    mass_greater += mass_quantil;
                    do quantil_val--; while (hist[static_cast<size_t>(quantil_val)] == 0);
                    mass_quantil = hist[static_cast<size_t>(quantil_val)];
                    mass_smaller -= mass_quantil;
                }
                //increase quantil value?
                if(!check_smaller && check_greater)
                {
                    mass_smaller += mass_quantil;
                    do quantil_val++; while (hist[static_cast<size_t>(quantil_val)] == 0);
                    mass_quantil = hist[static_cast<size_t>(quantil_val)];
                    mass_greater -= mass_quantil;
                }
            }
            //======================================================= add/remove values for current pixel (end)


            //------------------------------------------------------- write result

           //write quantil value to output image
            pMA_Out->at<uchar>(y, x) = quantil_val;


            //------------------------------------------------------- change direction

            //check for direction change or end
            switch (direction) {

            case c_DIR2D_R:
                if(x >= x_max)                      //at right border from left
                {
                    if(y >= y_max)
                        at_end = true;              //at right and bottom border
                    else
                    {
                        direction = c_DIR2D_D;      //at right but not at bottom border

                        //jump back to leftmost position
                        x = x_min;
                        hist = hist_line_begin;
                        mass_smaller = mass_smaller_line_begin;
                        mass_quantil = mass_quantil_line_begin;
                        mass_greater = mass_greater_line_begin;
                        quantil_val  = quantil_val_line_begin;
                    }
                }
                break;

            case c_DIR2D_D:
            {
                direction = c_DIR2D_R;

                //update to new line begin (one line lower than old line begin)
                hist_line_begin = hist;
                mass_smaller_line_begin = mass_smaller;
                mass_quantil_line_begin = mass_quantil;
                mass_greater_line_begin = mass_greater;
                quantil_val_line_begin  = quantil_val;
            }
                break;

            default:
                return ER_parameter_bad;
            }


        }
    }
        break;
    //------------------------------------------------------- CV_8UC1 end


    //------------------------------------------------------- CV_16UC1 start
    case CV_16UC1:
    {
        //write inital quantil value
        pMA_Out->at<ushort>(y_min, x_min) = quantil_val;

        //loop until end of image
        while(!at_end)
        {
            //------------------------------------------------------- change position

            //change indices based on direction
            switch (direction) {
            case c_DIR2D_R:     x++;    break;
            case c_DIR2D_D:     y++;    break;
            default:                    return ER_parameter_bad;}


            //------------------------------------------------------- add/remove list/offsets for current direction

            vector<Point> *vBorderAdd;
            vector<Point> *vBorderRem;
            int dx_to_prev_pos = 0;
            int dy_to_prev_pos = 0;
            switch (direction) {
            case c_DIR2D_R:     vBorderAdd = vBorderR;      vBorderRem = vBorderL;      dx_to_prev_pos = -1;    break;
            case c_DIR2D_D:     vBorderAdd = vBorderB;      vBorderRem = vBorderT;      dy_to_prev_pos = -1;    break;
            default:                                                                                            return ER_other;}


            //======================================================= add/remove values for current pixel (start)

            //loop add/remove lists of relative coordinates
            for(size_t i = 0; i < vBorderAdd->size(); i++)
            {
                //get values to add/remove
                ushort val_add = pMA_InPadded->at<ushort>(y + mask_cy + (*vBorderAdd)[i].y,                  x + mask_cx + (*vBorderAdd)[i].x);
                ushort val_rem = pMA_InPadded->at<ushort>(y + mask_cy + (*vBorderRem)[i].y + dy_to_prev_pos, x + mask_cx + (*vBorderRem)[i].x + dx_to_prev_pos);

                //update histogram
                hist[val_add]++;
                hist[val_rem]--;

                //update masses
                //add
                if(val_add > quantil_val)           mass_greater++;
                else if (val_add < quantil_val)     mass_smaller++;
                else                                mass_quantil++;
                //remove
                if(val_rem > quantil_val)           mass_greater--;
                else if (val_rem < quantil_val)     mass_smaller--;
                else                                mass_quantil--;

                //mass checks
                bool check_smaller = mass_smaller + mass_quantil >= mass_smaller_or_equal_needed;
                bool check_greater = mass_greater + mass_quantil >= mass_greater_or_equal_needed;

                //update quantil value
                //decrease quantil value?
                if(check_smaller && !check_greater)
                {
                    mass_greater += mass_quantil;
                    do quantil_val--; while (hist[static_cast<size_t>(quantil_val)] == 0);
                    mass_quantil = hist[static_cast<size_t>(quantil_val)];
                    mass_smaller -= mass_quantil;
                }
                //increase quantil value?
                if(!check_smaller && check_greater)
                {
                    mass_smaller += mass_quantil;
                    do quantil_val++; while (hist[static_cast<size_t>(quantil_val)] == 0);
                    mass_quantil = hist[static_cast<size_t>(quantil_val)];
                    mass_greater -= mass_quantil;
                }
            }
            //======================================================= add/remove values for current pixel (end)


            //------------------------------------------------------- write result

           //write quantil value to output image
            pMA_Out->at<ushort>(y, x) = quantil_val;


            //------------------------------------------------------- change direction

            //check for direction change or end
            switch (direction) {

            case c_DIR2D_R:
                if(x >= x_max)                      //at right border from left
                {
                    if(y >= y_max)
                        at_end = true;              //at right and bottom border
                    else
                    {
                        direction = c_DIR2D_D;      //at right but not at bottom border

                        //jump back to leftmost position
                        x = x_min;
                        hist = hist_line_begin;
                        mass_smaller = mass_smaller_line_begin;
                        mass_quantil = mass_quantil_line_begin;
                        mass_greater = mass_greater_line_begin;
                        quantil_val  = quantil_val_line_begin;
                    }
                }
                break;

            case c_DIR2D_D:
            {
                direction = c_DIR2D_R;

                //update to new line begin (one line lower than old line begin)
                hist_line_begin = hist;
                mass_smaller_line_begin = mass_smaller;
                mass_quantil_line_begin = mass_quantil;
                mass_greater_line_begin = mass_greater;
                quantil_val_line_begin  = quantil_val;
            }
                break;

            default:
                return ER_parameter_bad;
            }


        }
    }
        break;
    //------------------------------------------------------- CV_16UC1 end

    default:
        return ER_type_bad;
    }


    //------------------------------------------------------- finish

    //clear & return
    return ER_okay;
}

int D_Img_Proc::Filter_Maximum_1C(Mat *pMA_Out, Mat *pMA_In, size_t mask_size_x, size_t mask_size_y)
{
    //------------------------------------------------------- Error checks

    //Errors
    if(pMA_In->empty())                                                                         return ER_empty;
    if(pMA_In->depth() != CV_8U && pMA_In->depth() != CV_16U && pMA_In->depth() != CV_64F)      return ER_type_bad;
    if(pMA_In->channels() != 1)                                                                 return ER_channel_bad;
    if(mask_size_x % 2 != 1)                                                                    return ER_parameter_bad;
    if(mask_size_y % 2 != 1)                                                                    return ER_parameter_bad;
    int ER = ER_okay;


    //------------------------------------------------------- params

    //mask offset
    size_t mask_offset_x = mask_size_x / 2;
    size_t mask_offset_y = mask_size_y / 2;

    //size in
    size_t n_in_x = pMA_In->cols;
    size_t n_in_y = pMA_In->rows;

    //makropixel count
    size_t n_makropixels_x = (n_in_x % mask_size_x) ? (n_in_x / mask_size_x + 1) : (n_in_x / mask_size_x);
    size_t n_makropixels_y = (n_in_y % mask_size_y) ? (n_in_y / mask_size_y + 1) : (n_in_y / mask_size_y);


    //------------------------------------------------------- border handling

    //pad input image
    Mat MA_tmp_InPadded;
    ER = Padding(
                &MA_tmp_InPadded,
                pMA_In,
                abs(mask_offset_x + n_makropixels_x * mask_size_x - n_in_x),
                abs(mask_offset_x),
                abs(mask_offset_y),
                abs(mask_offset_y + n_makropixels_y * mask_size_y - n_in_y),
                BORDER_REPLICATE);
    if(ER != ER_okay)
    {
        MA_tmp_InPadded.release();
        return ER;
    }


    //------------------------------------------------------- init images

    //buffer img
    Mat MA_tmpf_Buffer_x(MA_tmp_InPadded.size(), MA_tmp_InPadded.type());

    //init output
    *pMA_Out = Mat(pMA_In->size(), pMA_In->type());


    //======================================================================    thread & synch

    //thread count
    size_t thread_count = getNumberOfCPUs();

    //------------------------------------------------------- filtering in x

    //threads
    vector<thread> v_threads_x(thread_count);

    //start threads
    for(size_t t = 0; t < thread_count; t++)
    {
        //range for thread
        size_t y_start   = (((t    ) / static_cast<double>(thread_count))) * n_in_y + mask_offset_y;
        size_t y_end     = (((t + 1) / static_cast<double>(thread_count))) * n_in_y + mask_offset_y;

        //start thread
        v_threads_x[t] = thread(
                    Filter_Maximum_1C_Thread_X,
                    &MA_tmpf_Buffer_x,
                    &MA_tmp_InPadded,
                    mask_size_x,
                    n_in_x,
                    y_start,
                    y_end);
    }

    //join threads
    for(size_t t = 0; t < thread_count; t++)
    {
        v_threads_x[t].join();
    }

    //------------------------------------------------------- filtering in y

    //threads
    vector<thread> v_threads_y(thread_count);

    //start threads
    for(size_t t = 0; t < thread_count; t++)
    {
        //range for thread
        size_t x_start   = (((t    ) / static_cast<double>(thread_count))) * n_in_x + mask_offset_x;
        size_t x_end     = (((t + 1) / static_cast<double>(thread_count))) * n_in_x + mask_offset_x;

        //start thread
        v_threads_y[t] = thread(
                    Filter_Maximum_1C_Thread_Y,
                    pMA_Out,
                    &MA_tmpf_Buffer_x,
                    mask_size_x,
                    mask_size_y,
                    n_in_y,
                    x_start,
                    x_end);
    }

    //join threads
    for(size_t t = 0; t < thread_count; t++)
    {
        v_threads_y[t].join();
    }

    qDebug() << "Filter_Maximum_1C" << "finish";

    //finish
    MA_tmpf_Buffer_x.release();
    return ER;
}

int D_Img_Proc::Filter_Maximum_1C_Thread_X(Mat *pMA_Out, Mat *pMA_In, size_t mask_size_x, size_t n_in_x, size_t y_start, size_t y_end)
{
    //errors
    if(pMA_In->empty())                                                                         return ER_empty;
    if(pMA_In->channels() != 1)                                                                 return ER_channel_bad;
    if(pMA_In->depth() != CV_8U && pMA_In->depth() != CV_16U && pMA_In->depth() != CV_64F)      return ER_type_bad;
    if(mask_size_x % 2 != 1)                                                                    return ER_parameter_bad;
    if(y_start >= y_end)                                                                        return ER_parameter_missmatch;
    if(y_start < 0 || y_start >= pMA_In->rows)                                                  return ER_size_missmatch;

    //mask offset
    size_t mask_offset_x = mask_size_x / 2;

    //makropixel count
    size_t n_makropixels_x = (n_in_x % mask_size_x) ? (n_in_x / mask_size_x + 1) : (n_in_x / mask_size_x);

    //type switch
    switch (pMA_In->type()) {

    case CV_8UC1:
    {
        //set up R and S vectors
        vector<uchar> vR(mask_size_x);
        vector<uchar> vL(mask_size_x);

        //loop rows and makro pixels
        for(size_t y = y_start; y < y_end; y++)
        {
            //loop makro pixels
            for(size_t mpx = 0; mpx < n_makropixels_x; mpx++)
            {
                //center of makropixel (output list coordinates)
                size_t x_center = mpx * mask_size_x + mask_offset_x;

                //calc L
                if(mpx == 0)
                {
                    //first makropixel
                    vL[0] = pMA_In->at<uchar>(y, x_center + mask_offset_x);
                    for(size_t l = 1; l < vL.size(); l++)
                        vL[l] = max(vL[l-1], pMA_In->at<uchar>(y, x_center + mask_offset_x - l));
                }
                else
                {
                        vL[0] = pMA_In->at<uchar>(y, x_center + mask_offset_x);
                        uchar max_mpx_combi = max(vL[0], vR[mask_size_x - 1]);

                        size_t l = 1;
                        while(l < mask_size_x && vL[l-1] < vR[mask_size_x - 1 - l])
                        {
                            vL[l] = max(vL[l-1], pMA_In->at<uchar>(y, x_center + mask_offset_x - l));
                            l++;
                        }
                        while(l < mask_size_x)
                        {
                            vL[l] = max_mpx_combi;
                            l++;
                        }
                }

                //calc R
                vR[0] = pMA_In->at<uchar>(y, x_center + mask_offset_x);
                for(size_t r = 1; r < mask_size_x; r++)
                    vR[r] = max(vR[r-1], pMA_In->at<uchar>(y, x_center + mask_offset_x + r));

                //merge to output
                if(mpx < n_makropixels_x - 1)
                {
                    size_t i = 0;
                    while(i < mask_size_x && vR[i] < vL[mask_size_x - 1  - i])
                    {
                        //left is greater
                       pMA_Out->at<uchar>(y, x_center + i) = vL[mask_size_x - 1  - i];
                       i++;
                    }
                    while(i < mask_size_x)
                    {
                        //right is and always will be greater
                        pMA_Out->at<uchar>(y, x_center + i) = vR[i];
                        i++;
                    }
                }
                else
                {
                    size_t i = 0;
                    while(x_center + i - mask_offset_x < n_in_x && i < mask_size_x && vR[i] < vL[mask_size_x - 1  - i])
                    {
                        //left is greater
                       pMA_Out->at<uchar>(y, x_center + i) = vL[mask_size_x - 1  - i];
                       i++;
                    }
                    while(x_center + i - mask_offset_x < n_in_x && i < mask_size_x)
                    {
                        //right is and always will be greater
                        pMA_Out->at<uchar>(y, x_center + i) = vR[i];
                        i++;
                    }
                }
            }
        }
    }
        break;
        
    case CV_16UC1:
    {
        //set up R and S vectors
        vector<ushort> vR(mask_size_x);
        vector<ushort> vL(mask_size_x);

        //loop rows and makro pixels
        for(size_t y = y_start; y < y_end; y++)
        {
            //loop makro pixels
            for(size_t mpx = 0; mpx < n_makropixels_x; mpx++)
            {
                //center of makropixel (output list coordinates)
                size_t x_center = mpx * mask_size_x + mask_offset_x;

                //calc L
                if(mpx == 0)
                {
                    //first makropixel
                    vL[0] = pMA_In->at<ushort>(y, x_center + mask_offset_x);
                    for(size_t l = 1; l < vL.size(); l++)
                        vL[l] = max(vL[l-1], pMA_In->at<ushort>(y, x_center + mask_offset_x - l));
                }
                else
                {
                        vL[0] = pMA_In->at<ushort>(y, x_center + mask_offset_x);
                        ushort max_mpx_combi = max(vL[0], vR[mask_size_x - 1]);

                        size_t l = 1;
                        while(l < mask_size_x && vL[l-1] < vR[mask_size_x - 1 - l])
                        {
                            vL[l] = max(vL[l-1], pMA_In->at<ushort>(y, x_center + mask_offset_x - l));
                            l++;
                        }
                        while(l < mask_size_x)
                        {
                            vL[l] = max_mpx_combi;
                            l++;
                        }
                }

                //calc R
                vR[0] = pMA_In->at<ushort>(y, x_center + mask_offset_x);
                for(size_t r = 1; r < mask_size_x; r++)
                    vR[r] = max(vR[r-1], pMA_In->at<ushort>(y, x_center + mask_offset_x + r));

                //merge to output
                if(mpx < n_makropixels_x - 1)
                {
                    size_t i = 0;
                    while(i < mask_size_x && vR[i] < vL[mask_size_x - 1  - i])
                    {
                        //left is greater
                       pMA_Out->at<ushort>(y, x_center + i) = vL[mask_size_x - 1  - i];
                       i++;
                    }
                    while(i < mask_size_x)
                    {
                        //right is and always will be greater
                        pMA_Out->at<ushort>(y, x_center + i) = vR[i];
                        i++;
                    }
                }
                else
                {
                    size_t i = 0;
                    while(x_center + i - mask_offset_x < n_in_x && i < mask_size_x && vR[i] < vL[mask_size_x - 1  - i])
                    {
                        //left is greater
                       pMA_Out->at<ushort>(y, x_center + i) = vL[mask_size_x - 1  - i];
                       i++;
                    }
                    while(x_center + i - mask_offset_x < n_in_x && i < mask_size_x)
                    {
                        //right is and always will be greater
                        pMA_Out->at<ushort>(y, x_center + i) = vR[i];
                        i++;
                    }
                }
            }
        }
    }
        break;
        
    case CV_64FC1:
    {
        //set up R and S vectors
        vector<double> vR(mask_size_x);
        vector<double> vL(mask_size_x);

        //loop rows and makro pixels
        for(size_t y = y_start; y < y_end; y++)
        {
            //loop makro pixels
            for(size_t mpx = 0; mpx < n_makropixels_x; mpx++)
            {
                //center of makropixel (output list coordinates)
                size_t x_center = mpx * mask_size_x + mask_offset_x;

                //calc L
                if(mpx == 0)
                {
                    //first makropixel
                    vL[0] = pMA_In->at<double>(y, x_center + mask_offset_x);
                    for(size_t l = 1; l < vL.size(); l++)
                        vL[l] = max(vL[l-1], pMA_In->at<double>(y, x_center + mask_offset_x - l));
                }
                else
                {
                        vL[0] = pMA_In->at<double>(y, x_center + mask_offset_x);
                        double max_mpx_combi = max(vL[0], vR[mask_size_x - 1]);

                        size_t l = 1;
                        while(l < mask_size_x && vL[l-1] < vR[mask_size_x - 1 - l])
                        {
                            vL[l] = max(vL[l-1], pMA_In->at<double>(y, x_center + mask_offset_x - l));
                            l++;
                        }
                        while(l < mask_size_x)
                        {
                            vL[l] = max_mpx_combi;
                            l++;
                        }
                }

                //calc R
                vR[0] = pMA_In->at<double>(y, x_center + mask_offset_x);
                for(size_t r = 1; r < mask_size_x; r++)
                    vR[r] = max(vR[r-1], pMA_In->at<double>(y, x_center + mask_offset_x + r));

                //merge to output
                if(mpx < n_makropixels_x - 1)
                {
                    size_t i = 0;
                    while(i < mask_size_x && vR[i] < vL[mask_size_x - 1  - i])
                    {
                        //left is greater
                       pMA_Out->at<double>(y, x_center + i) = vL[mask_size_x - 1  - i];
                       i++;
                    }
                    while(i < mask_size_x)
                    {
                        //right is and always will be greater
                        pMA_Out->at<double>(y, x_center + i) = vR[i];
                        i++;
                    }
                }
                else
                {
                    size_t i = 0;
                    while(x_center + i - mask_offset_x < n_in_x && i < mask_size_x && vR[i] < vL[mask_size_x - 1  - i])
                    {
                        //left is greater
                       pMA_Out->at<double>(y, x_center + i) = vL[mask_size_x - 1  - i];
                       i++;
                    }
                    while(x_center + i - mask_offset_x < n_in_x && i < mask_size_x)
                    {
                        //right is and always will be greater
                        pMA_Out->at<double>(y, x_center + i) = vR[i];
                        i++;
                    }
                }
            }
        }
    }
        break;

    default:
        return ER_type_bad;
    }

    return ER_okay;
}

int D_Img_Proc::Filter_Maximum_1C_Thread_Y(Mat *pMA_Out, Mat *pMA_In, size_t mask_size_x, size_t mask_size_y, size_t n_in_y, size_t x_start, size_t x_end)
{
    //errors
    if(pMA_In->empty())                                                                         return ER_empty;
    if(pMA_In->channels() != 1)                                                                 return ER_channel_bad;
    if(pMA_In->depth() != CV_8U && pMA_In->depth() != CV_16U && pMA_In->depth() != CV_64F)      return ER_type_bad;
    if(mask_size_x % 2 != 1)                                                                    return ER_parameter_bad;
    if(mask_size_y % 2 != 1)                                                                    return ER_parameter_bad;
    if(x_start >= x_end)                                                                        return ER_parameter_missmatch;
    if(x_start < 0 || x_start >= pMA_In->cols)                                                  return ER_size_missmatch;

    //mask offset
    size_t mask_offset_y = mask_size_y / 2;
    size_t mask_offset_x = mask_size_x / 2;

    //makropixel count
    size_t n_makropixels_y = (n_in_y % mask_size_y) ? (n_in_y / mask_size_y + 1) : (n_in_y / mask_size_y);

    //type switch
    switch (pMA_In->type()) {

    case CV_8UC1:
    {
        //set up R and S vectors
        vector<uchar> vR(mask_size_y);
        vector<uchar> vL(mask_size_y);

        //loop cols and makro pixels
        for(size_t x = x_start; x < x_end; x++)
        {
            //loop makro pixels
            for(size_t mpx = 0; mpx < n_makropixels_y; mpx++)
            {
                //center of makropixel (output list coordinates)
                size_t y_center = mpx * mask_size_y + mask_offset_y;

                //calc L
                if(mpx == 0)
                {
                    //first makropixel
                    vL[0] = pMA_In->at<uchar>(y_center + mask_offset_y, x);
                    for(size_t l = 1; l < vL.size(); l++)
                        vL[l] = max(vL[l-1], pMA_In->at<uchar>(y_center + mask_offset_y - l, x));
                }
                else
                {
                        vL[0] = pMA_In->at<uchar>(y_center + mask_offset_y, x);
                        uchar max_mpx_combi = max(vL[0], vR[mask_size_y - 1]);

                        size_t l = 1;
                        while(l < mask_size_y && vL[l-1] < vR[mask_size_y - 1 - l])
                        {
                            vL[l] = max(vL[l-1], pMA_In->at<uchar>(y_center + mask_offset_y - l, x));
                            l++;
                        }
                        while(l < mask_size_y)
                        {
                            vL[l] = max_mpx_combi;
                            l++;
                        }
                }

                //calc R
                vR[0] = pMA_In->at<uchar>(y_center + mask_offset_y, x);
                for(size_t r = 1; r < mask_size_y; r++)
                    vR[r] = max(vR[r-1], pMA_In->at<uchar>(y_center + mask_offset_y + r, x));

                //merge to output
                if(mpx < n_makropixels_y - 1)
                {
                    size_t i = 0;
                    while(i < mask_size_y && vR[i] < vL[mask_size_y - 1  - i])
                    {
                        //left is greater
                       pMA_Out->at<uchar>(y_center + i - mask_offset_y, x - mask_offset_x) = vL[mask_size_y - 1  - i];
                       i++;
                    }
                    while(i < mask_size_y)
                    {
                        //right is and always will be greater
                        pMA_Out->at<uchar>(y_center + i - mask_offset_y, x - mask_offset_x) = vR[i];
                        i++;
                    }
                }
                else
                {
                    size_t i = 0;
                    while(y_center + i - mask_offset_y < n_in_y && i < mask_size_y && vR[i] < vL[mask_size_y - 1  - i])
                    {
                        //left is greater
                        pMA_Out->at<uchar>(y_center + i - mask_offset_y, x - mask_offset_x) = vL[mask_size_y - 1  - i];
                        i++;
                    }
                    while(y_center + i - mask_offset_y < n_in_y && i < mask_size_y)
                    {
                        //right is and always will be greater
                        pMA_Out->at<uchar>(y_center + i - mask_offset_y, x - mask_offset_x) = vR[i];
                        i++;
                    }
                }
            }
        }
    }
        break;
        
    case CV_16UC1:
    {
        //set up R and S vectors
        vector<ushort> vR(mask_size_y);
        vector<ushort> vL(mask_size_y);

        //loop cols and makro pixels
        for(size_t x = x_start; x < x_end; x++)
        {
            //loop makro pixels
            for(size_t mpx = 0; mpx < n_makropixels_y; mpx++)
            {
                //center of makropixel (output list coordinates)
                size_t y_center = mpx * mask_size_y + mask_offset_y;

                //calc L
                if(mpx == 0)
                {
                    //first makropixel
                    vL[0] = pMA_In->at<ushort>(y_center + mask_offset_y, x);
                    for(size_t l = 1; l < vL.size(); l++)
                        vL[l] = max(vL[l-1], pMA_In->at<ushort>(y_center + mask_offset_y - l, x));
                }
                else
                {
                        vL[0] = pMA_In->at<ushort>(y_center + mask_offset_y, x);
                        ushort max_mpx_combi = max(vL[0], vR[mask_size_y - 1]);

                        size_t l = 1;
                        while(l < mask_size_y && vL[l-1] < vR[mask_size_y - 1 - l])
                        {
                            vL[l] = max(vL[l-1], pMA_In->at<ushort>(y_center + mask_offset_y - l, x));
                            l++;
                        }
                        while(l < mask_size_y)
                        {
                            vL[l] = max_mpx_combi;
                            l++;
                        }
                }

                //calc R
                vR[0] = pMA_In->at<ushort>(y_center + mask_offset_y, x);
                for(size_t r = 1; r < mask_size_y; r++)
                    vR[r] = max(vR[r-1], pMA_In->at<ushort>(y_center + mask_offset_y + r, x));

                //merge to output
                if(mpx < n_makropixels_y - 1)
                {
                    size_t i = 0;
                    while(i < mask_size_y && vR[i] < vL[mask_size_y - 1  - i])
                    {
                        //left is greater
                       pMA_Out->at<ushort>(y_center + i - mask_offset_y, x - mask_offset_x) = vL[mask_size_y - 1  - i];
                       i++;
                    }
                    while(i < mask_size_y)
                    {
                        //right is and always will be greater
                        pMA_Out->at<ushort>(y_center + i - mask_offset_y, x - mask_offset_x) = vR[i];
                        i++;
                    }
                }
                else
                {
                    size_t i = 0;
                    while(y_center + i - mask_offset_y < n_in_y && i < mask_size_y && vR[i] < vL[mask_size_y - 1  - i])
                    {
                        //left is greater
                        pMA_Out->at<ushort>(y_center + i - mask_offset_y, x - mask_offset_x) = vL[mask_size_y - 1  - i];
                        i++;
                    }
                    while(y_center + i - mask_offset_y < n_in_y && i < mask_size_y)
                    {
                        //right is and always will be greater
                        pMA_Out->at<ushort>(y_center + i - mask_offset_y, x - mask_offset_x) = vR[i];
                        i++;
                    }
                }
            }
        }
    }
        break;
        
    case CV_64FC1:
    {
        //set up R and S vectors
        vector<double> vR(mask_size_y);
        vector<double> vL(mask_size_y);

        //loop cols and makro pixels
        for(size_t x = x_start; x < x_end; x++)
        {
            //loop makro pixels
            for(size_t mpx = 0; mpx < n_makropixels_y; mpx++)
            {
                //center of makropixel (output list coordinates)
                size_t y_center = mpx * mask_size_y + mask_offset_y;

                //calc L
                if(mpx == 0)
                {
                    //first makropixel
                    vL[0] = pMA_In->at<double>(y_center + mask_offset_y, x);
                    for(size_t l = 1; l < vL.size(); l++)
                        vL[l] = max(vL[l-1], pMA_In->at<double>(y_center + mask_offset_y - l, x));
                }
                else
                {
                        vL[0] = pMA_In->at<double>(y_center + mask_offset_y, x);
                        double max_mpx_combi = max(vL[0], vR[mask_size_y - 1]);

                        size_t l = 1;
                        while(l < mask_size_y && vL[l-1] < vR[mask_size_y - 1 - l])
                        {
                            vL[l] = max(vL[l-1], pMA_In->at<double>(y_center + mask_offset_y - l, x));
                            l++;
                        }
                        while(l < mask_size_y)
                        {
                            vL[l] = max_mpx_combi;
                            l++;
                        }
                }

                //calc R
                vR[0] = pMA_In->at<double>(y_center + mask_offset_y, x);
                for(size_t r = 1; r < mask_size_y; r++)
                    vR[r] = max(vR[r-1], pMA_In->at<double>(y_center + mask_offset_y + r, x));

                //merge to output
                if(mpx < n_makropixels_y - 1)
                {
                    size_t i = 0;
                    while(i < mask_size_y && vR[i] < vL[mask_size_y - 1  - i])
                    {
                        //left is greater
                       pMA_Out->at<double>(y_center + i - mask_offset_y, x - mask_offset_x) = vL[mask_size_y - 1  - i];
                       i++;
                    }
                    while(i < mask_size_y)
                    {
                        //right is and always will be greater
                        pMA_Out->at<double>(y_center + i - mask_offset_y, x - mask_offset_x) = vR[i];
                        i++;
                    }
                }
                else
                {
                    size_t i = 0;
                    while(y_center + i - mask_offset_y < n_in_y && i < mask_size_y && vR[i] < vL[mask_size_y - 1  - i])
                    {
                        //left is greater
                        pMA_Out->at<double>(y_center + i - mask_offset_y, x - mask_offset_x) = vL[mask_size_y - 1  - i];
                        i++;
                    }
                    while(y_center + i - mask_offset_y < n_in_y && i < mask_size_y)
                    {
                        //right is and always will be greater
                        pMA_Out->at<double>(y_center + i - mask_offset_y, x - mask_offset_x) = vR[i];
                        i++;
                    }
                }
            }
        }
    }
        break;

    default:
        return ER_type_bad;
    }

    return ER_okay;
}



int D_Img_Proc::Filter_Laplace(Mat *pMA_Out, Mat *pMA_In, int size, int border, int out_depth, double scale, double delta)
{
    if(pMA_In->empty())             return ER_empty;
    //if(pMA_In->depth() != CV_8U)    return ER_bitdepth_bad;
    if(size < 1)                    return ER_parameter_bad;
    if(size % 2 != 1)               return ER_parameter_bad;

    Laplacian(
                *pMA_In,
                *pMA_Out,
                out_depth,
                size,
                scale,
                delta,
                border);
    return ER_okay;
}

int D_Img_Proc::Filter_LaplaceOfGaussian(Mat *pMA_Out, Mat *pMA_In, int size_g, double sigma_g, int size_l, int border, int out_depth, double scale, double delta)
{
    Mat MA_gauss;
    int ER = Filter_Gauss(
                &MA_gauss,
                pMA_In,
                size_g,
                size_g,
                border,
                sigma_g,
                sigma_g);
    if(ER != ER_okay)
    {
        MA_gauss.release();
        return ER;
    }

    ER = Filter_Laplace(
                pMA_Out,
                &MA_gauss,
                size_l,
                border,
                out_depth,
                scale,
                delta);

    MA_gauss.release();
    return ER;
}

int D_Img_Proc::Filter_Sobel(Mat *pMA_Out, Mat *pMA_In, int size, int border, int out_depth, double scale, double delta, int d_x, int d_y)
{
    if(pMA_In->empty())             return ER_empty;
    if(size < 1)                    return ER_parameter_bad;
    if(size % 2 != 1)               return ER_parameter_bad;

    Sobel(
                *pMA_In,
                *pMA_Out,
                out_depth,
                d_x,
                d_y,
                size,
                scale,
                delta,
                border);
    return ER_okay;
}

int D_Img_Proc::Filter_Scharr(Mat *pMA_Out, Mat *pMA_In, int border, int out_depth, double scale, double delta, int d_x, int d_y)
{
    if(pMA_In->empty())     return ER_empty;

    Scharr(
                *pMA_In,
                *pMA_Out,
                out_depth,
                d_x,
                d_y,
                scale,
                delta,
                border);

    return ER_okay;
}

int D_Img_Proc::Filter_Canny(Mat *pMA_Out, Mat *pMA_In, int size, double thres_low, double thres_high, bool L2_gradient)
{
    if(pMA_In->empty())         return ER_empty;
    if(pMA_In->depth())         return ER_bitdepth_bad;
    if(size < 1 || size > 7)    return ER_parameter_bad;
    if(size % 2 != 1)           return ER_parameter_bad;

    Canny(
                *pMA_In,
                *pMA_Out,
                thres_low,
                thres_high,
                size,
                L2_gradient);

        return ER_okay;
}

int D_Img_Proc::Filter_Bilateral(Mat *pMA_Out, Mat *pMA_In, int diameter, int border, double sigma_color, double sigma_space)
{
    if(pMA_In->empty())     return ER_empty;

    bilateralFilter(
                *pMA_In,
                *pMA_Out,
                diameter,
                sigma_color,
                sigma_space,
                border);

    return ER_okay;
}

int D_Img_Proc::Filter_Gabor(Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y, int border, int out_depth, double sigma, double theta, double lambda, double gamma, double psi, double delta)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->depth() != CV_8U)    return ER_bitdepth_bad;

    Mat MA_Kernel = getGaborKernel(
                Size(2*size_x + 1, 2*size_y + 1),
                sigma,
                theta,
                lambda,
                gamma,
                psi,
                out_depth); //ktype (32F or 64F)

    filter2D(
                *pMA_In,
                *pMA_Out,
                out_depth,
                MA_Kernel,
                Point(-1, -1),
                delta,
                border);

    MA_Kernel.release();
    return ER_okay;
}

int D_Img_Proc::Filter_Eilenstein_Prototype(Mat *pMA_Out, Mat *pMA_In, bool cmp_fkt(double current, double neighbor, double C), unsigned int size_x, unsigned int size_y, bool normalized, double constant)
{
    if(pMA_In->empty())                                         return ER_empty;
    if((pMA_In->channels() != 1) && (pMA_In->channels() != 3))  return ER_channel_bad;

    //Sizes & variables
    unsigned int Wi = pMA_In->cols; //image width
    unsigned int Hi = pMA_In->rows; //image heigth
    unsigned int SYm = size_y;      //mask  shift y (center to border)
    unsigned int SXm = size_x;      //mask  shift x (center to border)
    unsigned int Yi;                //image position y
    unsigned int Xi;                //image position x
    unsigned int Ym;                //mask  position y
    unsigned int Xm;                //mask  position x
    unsigned int result;            //result of pixel relative to local environment
    double max_val = 255.0;         //max value to be used for normalisation

    //make sure type and size match
    *pMA_Out = Mat(pMA_In->size(), pMA_In->type(), Scalar(0));

    switch (pMA_In->type()) {

    case CV_8UC1:   //------------------------------------------
    {
        for(Yi = SYm; Yi < (Hi - SYm); Yi++)                                                    //loop rows image
            for(Xi = SXm; Xi < (Wi - SXm); Xi++)                                                //loop cols image
            {
                result = 0;                                                                     //reset result
                for(Ym = Yi - SYm; Ym <= (Yi + SYm); Ym++)                                      //loop rows mask
                    for(Xm = Xi - SXm; Xm <= (Xi + SXm); Xm++)                                  //loop cols mask
                        result += cmp_fkt(                                                      //call compare function
                                    pMA_In->at<uchar>(Yi, Xi),                                  //current pixel
                                    pMA_In->at<uchar>(Ym, Xm),                                  //neighbor pixel
                                    constant);                                                  //constant
                pMA_Out->at<uchar>(Yi, Xi) = (uchar) result;                                    //write out pixel
            }
        max_val = 255;
    }
        break;

    case CV_16UC1:  //------------------------------------------
    {
        for(Yi = SYm; Yi < (Hi - SYm); Yi++)                                                    //loop rows image
            for(Xi = SXm; Xi < (Wi - SXm); Xi++)                                                //loop cols image
            {
                result = 0;                                                                     //reset result
                for(Ym = Yi - SYm; Ym <= (Yi + SYm); Ym++)                                      //loop rows mask
                    for(Xm = Xi - SXm; Xm <= (Xi + SXm); Xm++)                                  //loop cols mask
                        result += cmp_fkt(                                                      //call compare function
                                    pMA_In->at<ushort>(Yi, Xi),                                 //current pixel
                                    pMA_In->at<ushort>(Ym, Xm),                                 //neighbor pixel
                                    constant);                                                  //constant
                pMA_Out->at<ushort>(Yi, Xi) = (ushort) result;                                  //write out pixel
            }
        max_val = 65535;
    }
        break;

    case CV_32FC1:  //------------------------------------------
    {
        for(Yi = SYm; Yi < (Hi - SYm); Yi++)                                                    //loop rows image
            for(Xi = SXm; Xi < (Wi - SXm); Xi++)                                                //loop cols image
            {
                result = 0;                                                                     //reset result
                for(Ym = Yi - SYm; Ym <= (Yi + SYm); Ym++)                                      //loop rows mask
                    for(Xm = Xi - SXm; Xm <= (Xi + SXm); Xm++)                                  //loop cols mask
                        result += cmp_fkt(                                                      //call compare function
                                    pMA_In->at<float>(Yi, Xi),                                  //current pixel
                                    pMA_In->at<float>(Ym, Xm),                                  //neighbor pixel
                                    constant);                                                  //constant
                pMA_Out->at<float>(Yi, Xi) = (float) result;                                    //write out pixel
            }
        max_val = 2147483647.0;
    }
        break;

    default:        //------------------------------------------
        return ER_type_bad;
        break;
    }

    if(normalized)
        Normalize(
                    pMA_Out,
                    pMA_Out,
                    CV_MINMAX,
                    pMA_In->depth(),
                    0,
                    max_val);

    return ER_okay;
}

int D_Img_Proc::Filter_Eilenstein_1C(Mat *pMA_Out, Mat *pMA_In, int comp, unsigned int size_x, unsigned int size_y, bool normalized, double constant)
{
    int ER;

    switch (comp) {

    case 0:
        ER = Filter_Eilenstein_Prototype(pMA_Out, pMA_In,
                                         [](double current, double neighbor, double C) -> bool {return (current + C) == neighbor;},
                                         size_x, size_y,
                                         normalized, constant);
        break;

    case 1:
        ER = Filter_Eilenstein_Prototype(pMA_Out, pMA_In,
                                         [](double current, double neighbor, double C) -> bool {return (current + C) > neighbor;},
                                         size_x, size_y, normalized, constant);
        break;

    case 2:
        ER = Filter_Eilenstein_Prototype(pMA_Out, pMA_In,
                                         [](double current, double neighbor, double C) -> bool {return (current + C) >= neighbor;},
                                         size_x, size_y, normalized, constant);
        break;

    case 3:
        ER = Filter_Eilenstein_Prototype(pMA_Out, pMA_In,
                                         [](double current, double neighbor, double C) -> bool {return (current + C) < neighbor;},
                                         size_x, size_y, normalized, constant);
        break;

    case 4:
        ER = Filter_Eilenstein_Prototype(pMA_Out, pMA_In,
                                         [](double current, double neighbor, double C) -> bool {return (current + C) <= neighbor;},
                                         size_x, size_y, normalized, constant);
        break;

    case 5:
        ER = Filter_Eilenstein_Prototype(pMA_Out, pMA_In,
                                         [](double current, double neighbor, double C) -> bool {return (current + C) != neighbor;},
                                         size_x, size_y, normalized, constant);
        break;

    default:
        ER = ER_type_bad;
        break;
    }

    return ER;
}

int D_Img_Proc::Filter_Eilenstein(Mat *pMA_Out, Mat *pMA_In, int comp, unsigned int size_x, unsigned int size_y, bool normalized, double constant)
{
    if(pMA_In->empty()) return ER_empty;

    switch (pMA_In->channels()) {

    case 1:
    {
        int ER = Filter_Eilenstein_1C(
                    pMA_Out,
                    pMA_In,
                    comp,
                    size_x,
                    size_y,
                    normalized,
                    constant);
        if(ER != ER_okay)   return ER;
    }
        break;

    case 2:
    {
        Mat MA_tmp_in[2];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_filtered[2];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Filter_Eilenstein_1C(
                        &(MA_tmp_filtered[c]),
                        &(MA_tmp_in[c]),
                        comp,
                        size_x,
                        size_y,
                        normalized,
                        constant);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_filtered,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_filtered[c].release();
        }
    }
        break;

    case 3:
    {
        Mat MA_tmp_in[3];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_filtered[3];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Filter_Eilenstein_1C(
                        &(MA_tmp_filtered[c]),
                        &(MA_tmp_in[c]),
                        comp,
                        size_x,
                        size_y,
                        normalized,
                        constant);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_filtered,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_filtered[c].release();
        }
    }
        break;

    case 4:
    {
        Mat MA_tmp_in[4];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_filtered[4];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Filter_Eilenstein_1C(
                        &(MA_tmp_filtered[c]),
                        &(MA_tmp_in[c]),
                        comp,
                        size_x,
                        size_y,
                        normalized,
                        constant);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_filtered,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_filtered[c].release();
        }
    }
        break;

    default:
        break;
    }

    return ER_okay;
}

int D_Img_Proc::Filter_Eilenstein(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<double (double cur, double nei)> response_CurNei, function<double (double res, double wei)> weight_ResWeigth, function<double (vector<double> v_res)> combine_Responses)
{
    if(pMA_In->empty())                             return ER_okay;
    if(pMA_In->channels() != pMA_Mask->channels())  return ER_channel_missmatch;

    int ER;

    //convert to double
    //in
    Mat MA_tmp_double_in;
    ER = Convert_Double(
                &MA_tmp_double_in,
                pMA_In);
    if(ER != ER_okay)   return ER;

    //mask
    Mat MA_tmp_double_mask;
    ER = Convert_Double(
                &MA_tmp_double_mask,
                pMA_Mask);
    if(ER != ER_okay)   return ER;

    qDebug() << "Filter_Eilenstein (Channel and Format Handler) - in channels switch";
    switch (pMA_In->channels()) {

    case 1:
    {
        qDebug() << "Filter_Eilenstein (Channel and Format Handler) - proc channel 1/1";
        int ER = Filter_Eilenstein_1C(
                    pMA_Out,
                    &MA_tmp_double_in,
                    &MA_tmp_double_mask,
                    response_CurNei,
                    weight_ResWeigth,
                    combine_Responses);
        if(ER != ER_okay)   return ER;
    }
        break;

    case 2:
    {
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
            qDebug() << "Filter_Eilenstein (Channel and Format Handler) - proc channel" << c << "/2";
            int ER = Filter_Eilenstein_1C(
                        &(MA_tmp_filtered[c]),
                        &(MA_tmp_in[c]),
                        &(MA_tmp_mask[c]),
                        response_CurNei,
                        weight_ResWeigth,
                        combine_Responses);
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
            qDebug() << "Filter_Eilenstein (Channel and Format Handler) - proc channel" << c << "/3";
            int ER = Filter_Eilenstein_1C(
                        &(MA_tmp_filtered[c]),
                        &(MA_tmp_in[c]),
                        &(MA_tmp_mask[c]),
                        response_CurNei,
                        weight_ResWeigth,
                        combine_Responses);
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
            qDebug() << "Filter_Eilenstein (Channel and Format Handler) - proc channel" << c << "/4";
            int ER = Filter_Eilenstein_1C(
                        &(MA_tmp_filtered[c]),
                        &(MA_tmp_in[c]),
                        &(MA_tmp_mask[c]),
                        response_CurNei,
                        weight_ResWeigth,
                        combine_Responses);
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

    MA_tmp_double_in.release();
    MA_tmp_double_mask.release();
    qDebug() << "Filter_Eilenstein (Channel and Format Handler) - end";
    return ER_okay;
}

int D_Img_Proc::Filter_Eilenstein_1C(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<double (double cur, double nei)> response_CurNei, function<double (double res, double wei)> weight_ResWeigth, function<double (vector<double> v_res)> combine_Responses)
{
    qDebug() << "Filter_Eilenstein (CV_64FC1, processing) - start";

    if(pMA_In->empty())                     return ER_empty;
    if(pMA_In->channels() != 1)             return ER_channel_bad;
    if(pMA_In->depth() != CV_64F)           return ER_bitdepth_bad;
    if(pMA_Mask->channels() != 1)           return ER_channel_bad;
    if(pMA_Mask->depth() != CV_64F)         return ER_bitdepth_bad;
    if(pMA_Mask->cols >= pMA_In->cols)      return ER_size_missmatch;
    if(pMA_Mask->rows >= pMA_In->rows)      return ER_size_missmatch;

    //image dimension
    int Wi = pMA_In->cols;              //image width
    int Hi = pMA_In->rows;              //image heigth

    //mask dimension
    int Wm = pMA_Mask->cols;            //mask width
    int Hm = pMA_Mask->rows;            //mask height
    int Am = Wm * Hm;                   //mask area

    //max shifts
    int SXm = static_cast<int>(Wm / 2); //mask  shift x (center to border, rounded down)
    int SYm = static_cast<int>(Hm / 2); //mask  shift y (center to border, rounded down)

    //looping & convoluting
    int Xi = 0;                         //image         position x
    int Yi = 0;                         //image         position y
    int Xn = 0;                         //neighborhood  position x
    int Yn = 0;                         //neighborhood  position y
    int Xm = 0;                         //mask          position x
    int Ym = 0;                         //mask          position y
    int pos = 0;                        //mask          position counter

    //results
    vector<double> v_responses;         //responses of pixel relative to local environment
    v_responses.resize(Am);             //resize: one respone per mask pixel

    //init out
    *pMA_Out = Mat::zeros(pMA_In->size(), CV_64FC1);

    //loop image
    qDebug() << "Filter_Eilenstein (CV_64FC1, processing) - start the looping";
    //qDebug() << "before " << "Image: Yi" << Yi << "Xi" << Xi << "- Mask:" << "Ym" << Ym << "Xm" << Xm << "- Neighbors:" << "Yn" << Yn << "Xn" << Xn;
    for(Yi = SYm; Yi < (Hi - SYm); Yi++)
    {
        //qDebug() << "loop Yi" << "Image: Yi" << Yi << "Xi" << Xi << "- Mask:" << "Ym" << Ym << "Xm" << Xm << "- Neighbors:" << "Yn" << Yn << "Xn" << Xn << "====================";
        for(Xi = SXm; Xi < (Wi - SXm); Xi++)
        {
            //qDebug() << "loop Xi" << "Image: Yi" << Yi << "Xi" << Xi << "- Mask:" << "Ym" << Ym << "Xm" << Xm << "- Neighbors:" << "Yn" << Yn << "Xn" << Xn << "---------------";
            //reset position
            pos = 0;
            Ym = 0;

            //loop mask kongruent columns
            for(Yn = Yi - SYm; Yn <= (Yi + SYm); Yn++)
            {
                //qDebug() << "loop Yn" << "Image: Yi" << Yi << "Xi" << Xi << "- Mask:" << "Ym" << Ym << "Xm" << Xm << "- Neighbors:" << "Yn" << Yn << "Xn" << Xn << ".....";
                //new row -> reset column
                Xm = 0;

                //loop mask kongruent rows
                for(Xn = Xi - SXm; Xn <= (Xi + SXm); Xn++)
                {
                    //calculate position
                    v_responses[pos] =
                            weight_ResWeigth(
                                response_CurNei(
                                    pMA_In->at<double>(Yi, Xi),
                                    pMA_In->at<double>(Yn, Xn)),
                                pMA_Mask->at<double>(Ym, Xm));

                    //qDebug() << "loop Xn" << "Image: Yi" << Yi << "Xi" << Xi << "- Mask:" << "Ym" << Ym << "Xm" << Xm << "- Neighbors:" << "Yn" << Yn << "Xn" << Xn
                    //         << "pos" << pos << "/" << v_responses.size() << "response" << v_responses[pos];

                    //next position and column
                    pos++;
                    Xm++;
                }

                //next row
                Ym++;
            }

            //write result for current pixel
            double response = combine_Responses(v_responses);
            //qDebug() << "response for pixel(y/x):" << Yi << Xi << "=" << response;
            pMA_Out->at<double>(Yi, Xi) = response;
        }
    }

    //imshow("Filter_Eilenstein (CV_64FC1, processing) - end", *pMA_Out);

    qDebug() << "Filter_Eilenstein (CV_64FC1, processing) - end";
    return ER_okay;
}

int D_Img_Proc::Filter_Function(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<double (double, double)> F1_CenterImage, function<double (double, double)> F2_f1mask, function<double (vector<double>)> F3_Combine, function<double (double, double)> F4_f3center, int border_type, bool DoNonZeroMaskOnly)
{
    if(pMA_In->empty())                             return ER_okay;
    if(pMA_In->channels() != pMA_Mask->channels())  return ER_channel_missmatch;

    int ER;

    //convert to double
    //in
    Mat MA_tmp_double_in;
    ER = Convert_Double(
                &MA_tmp_double_in,
                pMA_In);
    if(ER != ER_okay)   return ER;

    //mask
    Mat MA_tmp_double_mask;
    ER = Convert_Double(
                &MA_tmp_double_mask,
                pMA_Mask);
    if(ER != ER_okay)   return ER;

    switch (pMA_In->channels()) {

    case 1:
    {
        int ER = Filter_Function_1C(
                    pMA_Out,
                    &MA_tmp_double_in,
                    &MA_tmp_double_mask,
                    F1_CenterImage,
                    F2_f1mask,
                    F3_Combine,
                    F4_f3center,
                    border_type,
                    getNumberOfCPUs(),
                    DoNonZeroMaskOnly);
        if(ER != ER_okay)   return ER;
    }
        break;

    case 2:
    {
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
                        getNumberOfCPUs(),
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
                        getNumberOfCPUs(),
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
                        getNumberOfCPUs(),
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

    MA_tmp_double_in.release();
    MA_tmp_double_mask.release();
    return ER_okay;
}

int D_Img_Proc::Filter_Function_1C(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<double (double cur, double nei)> F1_CenterImage, function<double (double f1r, double msk)> F2_f1mask, function<double (vector<double> vf2r)> F3_Combine, function<double (double f3r, double cen)> F4_f3center, int border_type, int thread_number, bool DoNonZeroMaskOnly)
{
    //======================================================================    Error Checks

    if(pMA_In->empty())                         return ER_empty;
    if(pMA_In->channels() != 1)                 return ER_channel_bad;
    if(pMA_In->depth() != CV_64F)               return ER_bitdepth_bad;
    if(pMA_Mask->channels() != 1)               return ER_channel_bad;
    if(pMA_Mask->depth() != CV_64F)             return ER_bitdepth_bad;
    if(pMA_Mask->cols % 2 != 1)                 return ER_size_bad;
    if(pMA_Mask->rows % 2 != 1)                 return ER_size_bad;
    int ER = ER_okay;

    //======================================================================    Dimensions

    //image dimension
    int Wi = pMA_In->cols;              //image width
    int Hi = pMA_In->rows;              //image heigth

    //mask dimension
    int Wm = pMA_Mask->cols;            //mask width
    int Hm = pMA_Mask->rows;            //mask height

    //max shifts
    int SXm = static_cast<int>(Wm / 2); //mask  shift x (center to border, rounded down)
    int SYm = static_cast<int>(Hm / 2); //mask  shift y (center to border, rounded down)

    //======================================================================    pad & init

    //init out
    *pMA_Out = Mat::zeros(pMA_In->size(), CV_64FC1);

    //padding in
    Mat MA_tmp_in_padded;
    copyMakeBorder(
                *pMA_In,
                MA_tmp_in_padded,
                SYm,
                SYm,
                SXm,
                SXm,
                border_type);


    //======================================================================    thread & synch

    //threads
    vector<thread>     v_threads;
    vector<int>         v_ER;
    v_threads.resize(thread_number);
    v_ER.resize(thread_number);

    for(int t = 0; t < thread_number; t++)
    {
        //range for thread
        int row_start   = (((t    ) / static_cast<double>(thread_number))) * Hi + SYm;
        int row_end     = (((t + 1) / static_cast<double>(thread_number))) * Hi + SYm;
        int col_start   = SXm;
        int col_end     = Wi + SXm;

        //start thread
        //qDebug() << "start thread" << t << "of" << thread_number << "- from" << col_start << "/" << row_start << "to" << col_end << "/" << row_end;
        v_threads[t] = thread(
                    Filter_Function_1C_Thread,
                    pMA_Out,
                    &MA_tmp_in_padded,
                    pMA_Mask,
                    F1_CenterImage,
                    F2_f1mask,
                    F3_Combine,
                    F4_f3center,
                    row_start,
                    row_end,
                    col_start,
                    col_end,
                    DoNonZeroMaskOnly);
    }

    for(int t = 0; t < thread_number; t++)
    {
        v_threads[t].join();
        //qDebug() << "join thread" << t << "of" << thread_number;
    }

    MA_tmp_in_padded.release();

    return ER;
}

int D_Img_Proc::Filter_Function_1C_Thread(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<double (double cur, double nei)> F1_CenterImage, function<double (double f1r, double msk)> F2_f1mask, function<double (vector<double> vf2r)> F3_Combine, function<double (double f3r, double cen)> F4_f3center, int row_start, int row_end, int col_start, int col_end, bool DoNonZeroMaskOnly)
{
    //======================================================================    Error Checks

    if(pMA_In->empty())                                 return ER_empty;
    if(pMA_In->channels() != 1)                         return ER_channel_bad;
    if(pMA_In->depth() != CV_64F)                       return ER_bitdepth_bad;
    if(pMA_Mask->channels() != 1)                       return ER_channel_bad;
    if(pMA_Mask->depth() != CV_64F)                     return ER_bitdepth_bad;
    if(pMA_Mask->cols >= pMA_In->cols)                  return ER_size_missmatch;
    if(pMA_Mask->rows >= pMA_In->rows)                  return ER_size_missmatch;
    if(row_start < 0 || row_start >= pMA_In->rows)      return ER_size_missmatch;
    if(row_end < 0 || row_end >= pMA_In->rows)          return ER_size_missmatch;
    if(row_start >= row_end)                            return ER_parameter_missmatch;
    if(col_start < 0 || col_start >= pMA_In->cols)      return ER_size_missmatch;
    if(col_end < 0 || col_end >= pMA_In->cols)          return ER_size_missmatch;
    if(col_start >= col_end)                            return ER_parameter_missmatch;
    if(pMA_Mask->cols % 2 != 1)                         return ER_size_bad;
    if(pMA_Mask->rows % 2 != 1)                         return ER_size_bad;

    //======================================================================    Dimensions & Positions

    //image dimension
    //int Wi = pMA_In->cols;              //image width
    //int Hi = pMA_In->rows;              //image heigth

    //mask dimension
    int Wm = pMA_Mask->cols;            //mask width
    int Hm = pMA_Mask->rows;            //mask height

    //max shifts
    int SXm = static_cast<int>(Wm / 2); //mask  shift x (center to border, rounded down)
    int SYm = static_cast<int>(Hm / 2); //mask  shift y (center to border, rounded down)

    //looping & convoluting
    int Xi = 0;                         //image         position x
    int Yi = 0;                         //image         position y
    int Xn = 0;                         //neighborhood  position x
    int Yn = 0;                         //neighborhood  position y
    int Xm = 0;                         //mask          position x
    int Ym = 0;                         //mask          position y

    //======================================================================    Init Results

    //pMA_Out is already initilazied by Filter_Function_1C (caring for therads and init)

    //results
    vector<double> v_results;

    //======================================================================    Loop Image

    //loop part of image image (rect row/col start/end)
    for(Yi = row_start; Yi < row_end; Yi++)
    {
        for(Xi = col_start; Xi < col_end; Xi++)
        {
            //reset position
            v_results.clear();
            Ym = 0;

            //loop mask kongruent columns
            for(Yn = Yi - SYm; Yn <= (Yi + SYm); Yn++)
            {
                //new row -> reset column
                Xm = 0;

                //loop mask kongruent rows
                for(Xn = Xi - SXm; Xn <= (Xi + SXm); Xn++)
                {
                    //calculate position value
                    double val_mask = pMA_Mask->at<double>(Ym, Xm);
                    if(!DoNonZeroMaskOnly || val_mask != 0)
                    {
                        v_results.push_back(
                                F2_f1mask(
                                    F1_CenterImage(
                                        pMA_In->at<double>(Yi, Xi),
                                        pMA_In->at<double>(Yn, Xn)),
                                    val_mask));
                    }

                    //next column
                    Xm++;
                }

                //next row
                Ym++;
            }

            //write result for current pixel (shifted by border width/height in output)
            pMA_Out->at<double>(Yi - SYm, Xi - SXm) =
                    F4_f3center(
                        F3_Combine(v_results),
                        pMA_In->at<double>(Yi, Xi));
        }
    }

    //======================================================================    End
    return ER_okay;
}

int D_Img_Proc::Filter_Function_8bit(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<uchar (double, double)> F1_CenterImage, function<uchar (double, double)> F2_f1mask, function<uchar (vector<double>)> F3_Combine, function<uchar (double, double)> F4_f3center, int border_type, bool DoNonZeroMaskOnly)
{
    if(pMA_In->empty())                             return ER_okay;
    if(pMA_In->channels() != pMA_Mask->channels())  return ER_channel_missmatch;
    if(pMA_In->depth() != CV_8UC1)                  return ER_bitdepth_bad;
    if(pMA_Mask->depth() != CV_8UC1)                return ER_bitdepth_bad;
    if(pMA_In->dims != 2)                           return ER_dim_2D_only;
    if(pMA_Mask->dims != 2)                         return ER_dim_2D_only;

    switch (pMA_In->channels()) {

    case 1:
    {
        int ER = Filter_Function_8bit_1C(
                    pMA_Out,
                    pMA_In,
                    pMA_Mask,
                    F1_CenterImage,
                    F2_f1mask,
                    F3_Combine,
                    F4_f3center,
                    border_type,
                    getNumberOfCPUs(),
                    DoNonZeroMaskOnly);
        if(ER != ER_okay)   return ER;
    }
        break;

    case 2:
    {
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
                        getNumberOfCPUs(),
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
                        getNumberOfCPUs(),
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
                        getNumberOfCPUs(),
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

    return ER_okay;
}

int D_Img_Proc::Filter_Function_8bit_1C(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<uchar (double, double)> F1_CenterImage, function<uchar (double, double)> F2_f1mask, function<uchar (vector<double>)> F3_Combine, function<uchar (double, double)> F4_f3center, int border_type, int thread_number, bool DoNonZeroMaskOnly)
{
    //======================================================================    Error Checks

    if(pMA_In->empty())                         return ER_empty;
    if(pMA_In->dims != 2)                       return ER_dim_2D_only;
    if(pMA_In->channels() != 1)                 return ER_channel_bad;
    if(pMA_In->depth() != CV_8U)                return ER_bitdepth_bad;
    if(pMA_Mask->dims != 2)                     return ER_dim_2D_only;
    if(pMA_Mask->channels() != 1)               return ER_channel_bad;
    if(pMA_Mask->depth() != CV_8U)              return ER_bitdepth_bad;
    if(pMA_Mask->size[0] % 2 != 1)              return ER_size_bad;
    if(pMA_Mask->size[1] % 2 != 1)              return ER_size_bad;
    int ER = ER_okay;

    //======================================================================    Dimensions

    //image dimension
    int Wi = pMA_In->cols;              //image width
    int Hi = pMA_In->rows;              //image heigth

    //mask dimension
    int Wm = pMA_Mask->cols;            //mask width
    int Hm = pMA_Mask->rows;            //mask height

    //max shifts
    int SXm = static_cast<int>(Wm / 2); //mask  shift x (center to border, rounded down)
    int SYm = static_cast<int>(Hm / 2); //mask  shift y (center to border, rounded down)

    //======================================================================    pad & init

    //init out
    *pMA_Out = Mat::zeros(pMA_In->size(), CV_8UC1);

    //padding in
    Mat MA_tmp_in_padded;
    copyMakeBorder(
                *pMA_In,
                MA_tmp_in_padded,
                SYm,
                SYm,
                SXm,
                SXm,
                border_type);


    //======================================================================    thread & synch

    //threads
    vector<thread>     v_threads;
    vector<int>         v_ER;
    v_threads.resize(thread_number);
    v_ER.resize(thread_number);

    for(int t = 0; t < thread_number; t++)
    {
        //range for thread
        int row_start   = (((t    ) / static_cast<double>(thread_number))) * Hi + SYm;
        int row_end     = (((t + 1) / static_cast<double>(thread_number))) * Hi + SYm;
        int col_start   = SXm;
        int col_end     = Wi + SXm;

        //start thread
        qDebug() << "start thread" << t << "of" << thread_number << "- from" << col_start << "/" << row_start << "to" << col_end << "/" << row_end;
        v_threads[t] = thread(
                    Filter_Function_8bit_1C_Thread,
                    pMA_Out,
                    &MA_tmp_in_padded,
                    pMA_Mask,
                    F1_CenterImage,
                    F2_f1mask,
                    F3_Combine,
                    F4_f3center,
                    row_start,
                    row_end,
                    col_start,
                    col_end,
                    DoNonZeroMaskOnly);
    }

    for(int t = 0; t < thread_number; t++)
    {
        v_threads[t].join();
        qDebug() << "join thread" << t << "of" << thread_number;
    }

    MA_tmp_in_padded.release();

    return ER;
}

int D_Img_Proc::Filter_Function_8bit_1C_Thread(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, function<uchar (double, double)> F1_CenterImage, function<uchar (double, double)> F2_f1mask, function<uchar (vector<double>)> F3_Combine, function<uchar (double, double)> F4_f3center, int row_start, int row_end, int col_start, int col_end, bool DoNonZeroMaskOnly)
{
    //======================================================================    Error Checks

    if(pMA_In->empty())                                 return ER_empty;
    if(pMA_In->channels() != 1)                         return ER_channel_bad;
    if(pMA_In->depth() != CV_8U)                        return ER_bitdepth_bad;
    if(pMA_Mask->channels() != 1)                       return ER_channel_bad;
    if(pMA_Mask->depth() != CV_8U)                      return ER_bitdepth_bad;
    if(pMA_Mask->cols >= pMA_In->cols)                  return ER_size_missmatch;
    if(pMA_Mask->rows >= pMA_In->rows)                  return ER_size_missmatch;
    if(row_start < 0 || row_start >= pMA_In->rows)      return ER_size_missmatch;
    if(row_end < 0 || row_end >= pMA_In->rows)          return ER_size_missmatch;
    if(row_start >= row_end)                            return ER_parameter_missmatch;
    if(col_start < 0 || col_start >= pMA_In->cols)      return ER_size_missmatch;
    if(col_end < 0 || col_end >= pMA_In->cols)          return ER_size_missmatch;
    if(col_start >= col_end)                            return ER_parameter_missmatch;
    if(pMA_Mask->cols % 2 != 1)                         return ER_size_bad;
    if(pMA_Mask->rows % 2 != 1)                         return ER_size_bad;

    //======================================================================    Dimensions & Positions

    //mask dimension
    int Wm = pMA_Mask->cols;            //mask width
    int Hm = pMA_Mask->rows;            //mask height

    //max shifts
    int SXm = static_cast<int>(Wm / 2); //mask  shift x (center to border, rounded down)
    int SYm = static_cast<int>(Hm / 2); //mask  shift y (center to border, rounded down)

    //looping & convoluting
    int Xi = 0;                         //image         position x
    int Yi = 0;                         //image         position y
    int Xn = 0;                         //neighborhood  position x
    int Yn = 0;                         //neighborhood  position y
    int Xm = 0;                         //mask          position x
    int Ym = 0;                         //mask          position y

    //======================================================================    Init Results

    //pMA_Out is already initilazied by Filter_Function_1C (caring for therads and init)

    //results
    vector<double> v_results;

    //======================================================================    Loop Image

    //loop part of image image (rect row/col start/end)
    for(Yi = row_start; Yi < row_end; Yi++)
    {
        for(Xi = col_start; Xi < col_end; Xi++)
        {
            //reset position
            v_results.clear();
            Ym = 0;

            //loop mask kongruent columns
            for(Yn = Yi - SYm; Yn <= (Yi + SYm); Yn++)
            {
                //new row -> reset column
                Xm = 0;

                //loop mask kongruent rows
                for(Xn = Xi - SXm; Xn <= (Xi + SXm); Xn++)
                {
                    //calculate position value
                    uchar val_mask = pMA_Mask->at<uchar>(Ym, Xm);
                    if(!DoNonZeroMaskOnly || val_mask != 0)
                    {
                        v_results.push_back(
                                F2_f1mask(
                                    F1_CenterImage(
                                        pMA_In->at<uchar>(Yi, Xi),
                                        pMA_In->at<uchar>(Yn, Xn)),
                                    val_mask));
                    }

                    //next column
                    Xm++;
                }

                //next row
                Ym++;
            }

            //write result for current pixel (shifted by border width/height in output)
            pMA_Out->at<uchar>(Yi - SYm, Xi - SXm) =
                    F4_f3center(
                        F3_Combine(v_results),
                        pMA_In->at<uchar>(Yi, Xi));
        }
    }

    //======================================================================    End
    return ER_okay;
}

int D_Img_Proc::Filter_Stat(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask, int stat, int border_type)
{
    return Filter_Function(
                pMA_Out,
                pMA_In,
                pMA_Mask,
                D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_Y),
                D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_X),
                D_Stat::Function_SingleStat(stat),
                D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_X),
                border_type,
                true);
}

int D_Img_Proc::Filter_Stat_Circular(Mat *pMA_Out, Mat *pMA_In, double radius, int stat, int border_type)
{
    if(radius < 0)              return ER_parameter_bad;

    //image size must be an odd int
    int img_size = 2 * static_cast<int>(radius) + 1;

    //generate mask
    Mat MA_tmp_Mask_1C;
    Generate_byValueFunction(
                &MA_tmp_Mask_1C,
                img_size,
                img_size,
                D_Math::Function_2D_to_1D(
                    c_MATH_2D_TO_1D_ELLIPSE,
                    radius,
                    img_size / 2,
                    radius,
                    img_size / 2,
                    1,
                    0,
                    0,
                    0));
    //qDebug() << "Filter_Stat_Circular" << radius << img_size << img_size / 2;

    //correct channel count
    Mat MA_tmp_Mask;
    int ER = Duplicate2Channels(
                &MA_tmp_Mask,
                &MA_tmp_Mask_1C,
                pMA_In->channels());
    if(ER != ER_okay)
    {
        MA_tmp_Mask_1C.release();
        MA_tmp_Mask.release();
        return ER;
    }

    //apply filter
    ER = Filter_Stat(
                pMA_Out,
                pMA_In,
                &MA_tmp_Mask,
                stat,
                border_type);

    MA_tmp_Mask_1C.release();
    MA_tmp_Mask.release();
    return ER;
}

int D_Img_Proc::Filter_Stat_Rect(Mat *pMA_Out, Mat *pMA_In, int size_x, int size_y, int stat, int border_type)
{
    if(size_x < 1)                          return ER_parameter_bad;
    if(size_y < 1)                          return ER_parameter_bad;
    if(size_x % 2 != 1)                     return ER_parameter_bad;
    if(size_y % 2 != 1)                     return ER_parameter_bad;

    //generate mask
    Mat MA_tmp_Mask_1C = Mat::ones(size_y, size_x, CV_64FC1);

    //correct channel count
    Mat MA_tmp_Mask;
    int ER = Duplicate2Channels(
                &MA_tmp_Mask,
                &MA_tmp_Mask_1C,
                pMA_In->channels());
    if(ER != ER_okay)
    {
        MA_tmp_Mask_1C.release();
        MA_tmp_Mask.release();
        return ER;
    }

    //apply filter
    ER = Filter_Stat(
                pMA_Out,
                pMA_In,
                &MA_tmp_Mask,
                stat,
                border_type);

    MA_tmp_Mask_1C.release();
    MA_tmp_Mask.release();
    return ER;
}

int D_Img_Proc::Fill_Holes(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->type() != CV_8U)     return ER_bitdepth_bad;

    int ER;

    //objects:      white
    //background:   black
    //holes:        black

    //fill background from boundaries with foreground
    Mat MA_tmp_holes;
    ER = Floodfill_Boundary(
                &MA_tmp_holes,
                pMA_In,
                255);
    if(ER != ER_okay)
    {
        qDebug() << "D_Img_Proc::Fill_Holes" << "Floodfill_Boundary" << "Error:" << ER;
        return ER;
    }

    //objects:      white
    //background:   white
    //holes:        black

    //invert, to get holes as foreground
    ER = Math_ImgSelf_Not(
                &MA_tmp_holes,
                &MA_tmp_holes);
    if(ER != ER_okay)
    {
        qDebug() << "D_Img_Proc::Fill_Holes" << "Math_ImgSelf_Not" << "Error:" << ER;
        return ER;
    }

    //objects:      black
    //background:   black
    //holes:        white

    //fill holes
    //qDebug() << "MA_tmp" << Type_of_Mat(&MA_tmp_holes) << "input" << Type_of_Mat(pMA_In);
    ER = Math_ImgImg_BitOr(
                pMA_Out,
                &MA_tmp_holes,
                pMA_In);
    if(ER != ER_okay)
    {
        qDebug() << "D_Img_Proc::Fill_Holes" << "Math_ImgImg_BitOr" << "Error:" << ER;
        return ER;
    }

    //objects:      white
    //background:   black
    //holes:        white

    MA_tmp_holes.release();
    return ER_okay;
}

int D_Img_Proc::Exclude_BorderConnected(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->type() != CV_8U)     return ER_bitdepth_bad;

    int ER;

    *pMA_Out = pMA_In->clone();

    //Draw border white
    ER = Draw_Rect(
                pMA_Out,
                0,
                0,
                pMA_Out->cols - 1,
                pMA_Out->rows - 1,
                2,
                255);
    if(ER != ER_okay)   return ER;

    //fill everything connected with drawn rect with background
    ER = Floodfill(
                pMA_Out,
                pMA_Out,
                0,
                0,
                0);

    return ER;
}


int D_Img_Proc::Labeling(Mat *pMA_Out, Mat *pMA_In, int connectivity, int out_depth)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->type() != CV_8U)     return ER_bitdepth_bad;

    connectedComponents(
                *pMA_In,
                *pMA_Out,
                connectivity,
                out_depth);

    return ER_okay;
}

int D_Img_Proc::Math_Add(Mat *pMA_Out, Mat *pMA_In1, double summand)
{
    return Math_ImgScal_Add(
                pMA_Out,
                pMA_In1,
                summand);
}

int D_Img_Proc::Math_Add(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)
{
    return Math_ImgImg_Add(
                pMA_Out,
                pMA_In1,
                pMA_In2);
}

int D_Img_Proc::Math_Add(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, double summand)
{
    int ER;

    Mat MA_tmp;
    ER = Math_Add(
                &MA_tmp,
                pMA_In1,
                pMA_In2);
    if(ER != ER_okay)
    {
        MA_tmp.release();
        return ER;
    }

    ER = Math_Add(
                pMA_Out,
                &MA_tmp,
                summand);

    MA_tmp.release();
    return ER;
}

int D_Img_Proc::Math_Add(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)
{
    int ER;

    Mat MA_tmp;
    ER = Math_Add(
                &MA_tmp,
                pMA_In1,
                pMA_In2);
    if(ER != ER_okay)
    {
        MA_tmp.release();
        return ER;
    }

    ER = Math_Add(
                pMA_Out,
                &MA_tmp,
                pMA_In3);

    MA_tmp.release();
    return ER;
}

int D_Img_Proc::Math_Add(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, double summand)
{
    int ER;

    Mat MA_tmp;
    ER = Math_Add(
                &MA_tmp,
                pMA_In1,
                pMA_In2,
                pMA_In3);
    if(ER != ER_okay)
    {
        MA_tmp.release();
        return ER;
    }

    ER = Math_Add(
                pMA_Out,
                &MA_tmp,
                summand);

    MA_tmp.release();
    return ER;
}

int D_Img_Proc::Math_Add(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat *pMA_In4)
{
    int ER;

    Mat MA_tmp;
    ER = Math_Add(
                &MA_tmp,
                pMA_In1,
                pMA_In2,
                pMA_In3);
    if(ER != ER_okay)
    {
        MA_tmp.release();
        return ER;
    }

    ER = Math_Add(
                pMA_Out,
                &MA_tmp,
                pMA_In4);

    MA_tmp.release();
    return ER;
}

int D_Img_Proc::Math_Add(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat *pMA_In4, double summand)
{
    int ER;

    Mat MA_tmp;
    ER = Math_Add(
                &MA_tmp,
                pMA_In1,
                pMA_In2,
                pMA_In3,
                pMA_In4);
    if(ER != ER_okay)
    {
        MA_tmp.release();
        return ER;
    }

    ER = Math_Add(
                pMA_Out,
                &MA_tmp,
                summand);

    MA_tmp.release();
    return ER;
}

int D_Img_Proc::Math_Mult(Mat *pMA_Out, Mat *pMA_In1, double factor)
{
    return Math_ImgScal_Mult(
                pMA_Out,
                pMA_In1,
                factor);
}

int D_Img_Proc::Math_Mult(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)
{
    return Math_ImgImg_Mult(
                pMA_Out,
                pMA_In1,
                pMA_In2,
                1);
}

int D_Img_Proc::Math_Mult(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, double factor)
{
    int ER;

    Mat MA_tmp;
    ER = Math_Mult(
                &MA_tmp,
                pMA_In1,
                pMA_In2);
    if(ER != ER_okay)
    {
        MA_tmp.release();
        return ER;
    }

    ER = Math_Mult(
                pMA_Out,
                &MA_tmp,
                factor);

    MA_tmp.release();
    return ER;
}

int D_Img_Proc::Math_Mult(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)
{
    int ER;

    Mat MA_tmp;
    ER = Math_Mult(
                &MA_tmp,
                pMA_In1,
                pMA_In2);
    if(ER != ER_okay)
    {
        MA_tmp.release();
        return ER;
    }

    ER = Math_Mult(
                pMA_Out,
                &MA_tmp,
                pMA_In3);

    MA_tmp.release();
    return ER;
}

int D_Img_Proc::Math_Mult(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, double factor)
{
    int ER;

    Mat MA_tmp;
    ER = Math_Mult(
                &MA_tmp,
                pMA_In1,
                pMA_In2,
                pMA_In3);
    if(ER != ER_okay)
    {
        MA_tmp.release();
        return ER;
    }

    ER = Math_Mult(
                pMA_Out,
                &MA_tmp,
                factor);

    MA_tmp.release();
    return ER;
}

int D_Img_Proc::Math_Mult(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat *pMA_In4)
{
    int ER;

    Mat MA_tmp;
    ER = Math_Mult(
                &MA_tmp,
                pMA_In1,
                pMA_In2,
                pMA_In3);
    if(ER != ER_okay)
    {
        MA_tmp.release();
        return ER;
    }

    ER = Math_Mult(
                pMA_Out,
                &MA_tmp,
                pMA_In4);

    MA_tmp.release();
    return ER;
}

int D_Img_Proc::Math_Mult(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat *pMA_In4, double factor)
{
    int ER;

    Mat MA_tmp;
    ER = Math_Mult(
                &MA_tmp,
                pMA_In1,
                pMA_In2,
                pMA_In3,
                pMA_In4);
    if(ER != ER_okay)
    {
        MA_tmp.release();
        return ER;
    }

    ER = Math_Mult(
                pMA_Out,
                &MA_tmp,
                factor);

    MA_tmp.release();
    return ER;
}

int D_Img_Proc::Math_And(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)
{
    return Math_ImgImg_BitAnd(
                pMA_Out,
                pMA_In1,
                pMA_In2);
}

int D_Img_Proc::Math_And(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)
{
    int ER;

    Mat MA_tmp;
    ER = Math_And(
                &MA_tmp,
                pMA_In1,
                pMA_In2);
    if(ER != ER_okay)
    {
        MA_tmp.release();
        return ER;
    }

    ER = Math_And(
                pMA_Out,
                &MA_tmp,
                pMA_In3);

    MA_tmp.release();
    return ER;
}

int D_Img_Proc::Math_And(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat *pMA_In4)
{
    int ER;

    Mat MA_tmp;
    ER = Math_And(
                &MA_tmp,
                pMA_In1,
                pMA_In2,
                pMA_In3);
    if(ER != ER_okay)
    {
        MA_tmp.release();
        return ER;
    }

    ER = Math_And(
                pMA_Out,
                &MA_tmp,
                pMA_In4);

    MA_tmp.release();
    return ER;
}

int D_Img_Proc::Math_Or(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)
{
    return Math_ImgImg_BitOr(
                pMA_Out,
                pMA_In1,
                pMA_In2);
}

int D_Img_Proc::Math_Or(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3)
{
    int ER;

    Mat MA_tmp;
    ER = Math_Or(
                &MA_tmp,
                pMA_In1,
                pMA_In2);
    if(ER != ER_okay)
    {
        MA_tmp.release();
        return ER;
    }

    ER = Math_Or(
                pMA_Out,
                &MA_tmp,
                pMA_In3);

    MA_tmp.release();
    return ER;
}

int D_Img_Proc::Math_Or(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat *pMA_In4)
{
    int ER;

    Mat MA_tmp;
    ER = Math_Or(
                &MA_tmp,
                pMA_In1,
                pMA_In2,
                pMA_In3);
    if(ER != ER_okay)
    {
        MA_tmp.release();
        return ER;
    }

    ER = Math_Or(
                pMA_Out,
                &MA_tmp,
                pMA_In4);

    MA_tmp.release();
    return ER;
}

int D_Img_Proc::Math_Magnitude(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)
{
    if(pMA_In1->empty())                                            return ER_empty;
    if(pMA_In2->empty())                                            return ER_empty;
    if(pMA_In1->depth() != CV_32F && pMA_In1->depth() != CV_64F)    return ER_type_bad;
    if(pMA_In2->depth() != CV_32F && pMA_In2->depth() != CV_64F)    return ER_type_bad;
    if(pMA_In1->size != pMA_In2->size)                              return ER_size_missmatch;
    if(pMA_In1->type() != pMA_In2->type())                          return ER_type_missmatch;

    magnitude(
            *pMA_In1,
            *pMA_In2,
            *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::Math_MagnitudeSquared(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)
{
    if(pMA_In1->empty())                    return ER_empty;
    if(pMA_In2->empty())                    return ER_empty;
    if(pMA_In1->size != pMA_In2->size)      return ER_size_missmatch;
    if(pMA_In1->type() != pMA_In2->type())  return ER_type_missmatch;
    int ER;

    Mat MA_tmp_Sqr1;
    ER = Math_Mult(
                &MA_tmp_Sqr1,
                pMA_In1,
                pMA_In1);
    if(ER != ER_okay)
    {
        MA_tmp_Sqr1.release();
        return ER;
    }

    Mat MA_tmp_Sqr2;
    ER = Math_Mult(
                &MA_tmp_Sqr2,
                pMA_In2,
                pMA_In2);
    if(ER != ER_okay)
    {
        MA_tmp_Sqr1.release();
        MA_tmp_Sqr2.release();
        return ER;
    }

    ER = Math_Add(
                pMA_Out,
                &MA_tmp_Sqr1,
                &MA_tmp_Sqr2);

    MA_tmp_Sqr1.release();
    MA_tmp_Sqr2.release();
    return ER_okay;
}

int D_Img_Proc::Math_Phase(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)
{
    if(pMA_In1->empty())                                            return ER_empty;
    if(pMA_In2->empty())                                            return ER_empty;
    if(pMA_In1->depth() != CV_32F && pMA_In1->depth() != CV_64F)    return ER_type_bad;
    if(pMA_In2->depth() != CV_32F && pMA_In2->depth() != CV_64F)    return ER_type_bad;
    if(pMA_In1->size != pMA_In2->size)                              return ER_size_missmatch;
    if(pMA_In1->type() != pMA_In2->type())                          return ER_type_missmatch;

    phase(
            *pMA_In1,
            *pMA_In2,
            *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::Math_LimitTop(Mat *pMA_Out, Mat *pMA_InThresh, Mat *pMA_InToLimit)
{
    if(pMA_InThresh->empty())                                       return ER_empty;
    if(pMA_InToLimit->empty())                                      return ER_empty;
    if(pMA_InThresh->type() != pMA_InToLimit->type())               return ER_type_missmatch;
    if(pMA_InThresh->channels() != 1)                               return ER_channel_bad;

    //init out
    *pMA_Out = pMA_InToLimit->clone();

    return Math_LimitTop(
                pMA_Out,
                pMA_InThresh);
}

int D_Img_Proc::Math_LimitTop(Mat *pMA_Target, Mat *pMA_InThresh)
{
    if(pMA_InThresh->empty())                                       return ER_empty;
    if(pMA_Target->empty())                                         return ER_empty;
    if(pMA_InThresh->type() != pMA_Target->type())                  return ER_type_missmatch;
    if(pMA_InThresh->channels() != 1)                               return ER_channel_bad;

    //type switch
    switch (pMA_InThresh->type()) {

    case CV_8UC1:
    {
        uchar* ptr_tar = reinterpret_cast<uchar*>(pMA_Target->data);
        uchar* ptr_thr = reinterpret_cast<uchar*>(pMA_InThresh->data);
        for(int px = 0; px < pMA_Target->cols * pMA_Target->rows; px++, ptr_tar++, ptr_thr++)
            if(*ptr_tar > *ptr_thr)
                *ptr_tar = *ptr_thr;
    }
        break;

    case CV_8SC1:
    {
        char* ptr_tar = reinterpret_cast<char*>(pMA_Target->data);
        char* ptr_thr = reinterpret_cast<char*>(pMA_InThresh->data);
        for(int px = 0; px < pMA_Target->cols * pMA_Target->rows; px++, ptr_tar++, ptr_thr++)
            if(*ptr_tar > *ptr_thr)
                *ptr_tar = *ptr_thr;
    }
        break;

    case CV_16UC1:
    {
        ushort* ptr_tar = reinterpret_cast<ushort*>(pMA_Target->data);
        ushort* ptr_thr = reinterpret_cast<ushort*>(pMA_InThresh->data);
        for(int px = 0; px < pMA_Target->cols * pMA_Target->rows; px++, ptr_tar++, ptr_thr++)
            if(*ptr_tar > *ptr_thr)
                *ptr_tar = *ptr_thr;
    }
        break;

    case CV_16SC1:
    {
        short* ptr_tar = reinterpret_cast<short*>(pMA_Target->data);
        short* ptr_thr = reinterpret_cast<short*>(pMA_InThresh->data);
        for(int px = 0; px < pMA_Target->cols * pMA_Target->rows; px++, ptr_tar++, ptr_thr++)
            if(*ptr_tar > *ptr_thr)
                *ptr_tar = *ptr_thr;
    }
        break;

    case CV_32SC1:
    {
        int* ptr_tar = reinterpret_cast<int*>(pMA_Target->data);
        int* ptr_thr = reinterpret_cast<int*>(pMA_InThresh->data);
        for(int px = 0; px < pMA_Target->cols * pMA_Target->rows; px++, ptr_tar++, ptr_thr++)
            if(*ptr_tar > *ptr_thr)
                *ptr_tar = *ptr_thr;
    }
        break;

    case CV_32FC1:
    {
        float* ptr_tar = reinterpret_cast<float*>(pMA_Target->data);
        float* ptr_thr = reinterpret_cast<float*>(pMA_InThresh->data);
        for(int px = 0; px < pMA_Target->cols * pMA_Target->rows; px++, ptr_tar++, ptr_thr++)
            if(*ptr_tar > *ptr_thr)
                *ptr_tar = *ptr_thr;
    }
        break;

    case CV_64FC1:
    {
        double* ptr_tar = reinterpret_cast<double*>(pMA_Target->data);
        double* ptr_thr = reinterpret_cast<double*>(pMA_InThresh->data);
        for(int px = 0; px < pMA_Target->cols * pMA_Target->rows; px++, ptr_tar++, ptr_thr++)
            if(*ptr_tar > *ptr_thr)
                *ptr_tar = *ptr_thr;
    }
        break;

    default:
        return ER_type_bad;
    }

    return ER_okay;
}

bool D_Img_Proc::Check_IsSimilar(Mat *pMA_In1, Mat *pMA_In2)
{
    if(pMA_In1->size != pMA_In2->size)
        return false;

    if(pMA_In1->type() != pMA_In2->type())
        return false;

    Mat MA_tmp_check;
    if(Math_ImgImg_BitXor(
                &MA_tmp_check,
                pMA_In1,
                pMA_In2) != ER_okay)
    {
        MA_tmp_check.release();
        return false;
    }

    if(countNonZero(MA_tmp_check) > 0)
    {
        MA_tmp_check.release();
        return false;
    }

    return true;
}

bool D_Img_Proc::Check_GreaterValue(Mat *pMA_InSmaller, Mat *pMA_InGreater)
{
    if(pMA_InSmaller->size != pMA_InGreater->size)
        return false;

    if(pMA_InSmaller->type() != pMA_InGreater->type())
        return false;

    Mat MA_tmp_check;
    if(Math_ImgImg_Diff(
                &MA_tmp_check,
                pMA_InGreater,
                pMA_InSmaller)
            != ER_okay)
    {
        MA_tmp_check.release();
        return false;
    }

    double min, max;
    if(MinMax_of_Mat(
                &MA_tmp_check,
                &min,
                &max)
            != ER_okay)
    {
        MA_tmp_check.release();
        return false;
    }

    if(min < 0)
        return false;

    return true;
}

int D_Img_Proc::Math_ImgSelf_Not(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty())     return ER_empty;

    bitwise_not(
                *pMA_In,
                *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::Math_ImgScal_Add(Mat *pMA_Out, Mat *pMA_In, double summmand)
{
    if(pMA_In->empty())     return ER_empty;

    *pMA_Out = *pMA_In + summmand;

    return ER_okay;
}

int D_Img_Proc::Math_ImgScal_Sub(Mat *pMA_Out, Mat *pMA_In, double subtrahend)
{
    if(pMA_In->empty())     return ER_empty;

    *pMA_Out = *pMA_In - subtrahend;

    return ER_okay;
}

int D_Img_Proc::Math_ScalImg_Sub(Mat *pMA_Out, Mat *pMA_In, double minuend)
{
    if(pMA_In->empty())     return ER_empty;

    *pMA_Out = minuend - *pMA_In;

    return ER_okay;
}

int D_Img_Proc::Math_ImgScal_Mult(Mat *pMA_Out, Mat *pMA_In, double factor)
{
    if(pMA_In->empty())     return ER_empty;

    *pMA_Out = *pMA_In * factor;

    return ER_okay;
}

int D_Img_Proc::Math_ImgScal_Div(Mat *pMA_Out, Mat *pMA_In, double divisor)
{
    if(pMA_In->empty())     return ER_empty;
    if(divisor == 0)        divisor = 0.000001;

    *pMA_Out = *pMA_In / divisor;

    return ER_okay;
}

int D_Img_Proc::Math_ImgScal_Pow(Mat *pMA_Out, Mat *pMA_In, double power)
{
    if(pMA_In->empty())     return ER_empty;

    pow(
                *pMA_In,
                power,
                *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::Math_ImgScal_Root(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty())                                             return ER_empty;
    if((pMA_In->type() != CV_32F) || (pMA_In->type() != CV_64F))    return ER_bitdepth_bad;

    sqrt(
                *pMA_In,
                *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::Math_ImgScal_Log(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty())                                             return ER_empty;
    if((pMA_In->type() != CV_32F) || (pMA_In->type() != CV_64F))    return ER_bitdepth_bad;

    log(
                *pMA_In,
                *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::Math_ImgImg_Add(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)
{
    if(pMA_In1->empty() || pMA_In2->empty())        return ER_empty;
    if(pMA_In1->size != pMA_In2->size)              return ER_size_missmatch;
    if(pMA_In1->channels() != pMA_In2->channels())  return ER_channel_missmatch;
    if(pMA_In1->depth() != pMA_In2->depth())        return ER_bitdepth_missmatch;

    add(
                *pMA_In1,
                *pMA_In2,
                *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::Math_ImgImg_AddWeighted(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, double weight_1, double weight_2, double weight_sum)
{
    if(pMA_In1->empty() || pMA_In2->empty())        return ER_empty;
    if(pMA_In1->size != pMA_In2->size)              return ER_size_missmatch;
    if(pMA_In1->channels() != pMA_In2->channels())  return ER_channel_missmatch;
    if(pMA_In1->depth() != pMA_In2->depth())        return ER_bitdepth_missmatch;

    addWeighted(
                *pMA_In1,
                weight_1,
                *pMA_In2,
                weight_2,
                weight_sum,
                *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::Math_ImgImg_Diff(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)
{
    if(pMA_In1->empty() || pMA_In2->empty())        return ER_empty;
    if(pMA_In1->size != pMA_In2->size)              return ER_size_missmatch;
    if(pMA_In1->channels() != pMA_In2->channels())  return ER_channel_missmatch;
    if(pMA_In1->depth() != pMA_In2->depth())        return ER_bitdepth_missmatch;

    subtract(
                *pMA_In1,
                *pMA_In2,
                *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::Math_ImgImg_DiffAbs(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)
{
    if(pMA_In1->empty() || pMA_In2->empty())        return ER_empty;
    if(pMA_In1->size != pMA_In2->size)              return ER_size_missmatch;
    if(pMA_In1->channels() != pMA_In2->channels())  return ER_channel_missmatch;
    if(pMA_In1->depth() != pMA_In2->depth())        return ER_bitdepth_missmatch;

    absdiff(
                *pMA_In1,
                *pMA_In2,
                *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::Math_ImgImg_Mult(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, double scale)
{
    if(pMA_In1->empty() || pMA_In2->empty())        return ER_empty;
    if(pMA_In1->size != pMA_In2->size)              return ER_size_missmatch;
    if(pMA_In1->channels() != pMA_In2->channels())  return ER_channel_missmatch;
    if(pMA_In1->depth() != pMA_In2->depth())        return ER_bitdepth_missmatch;

    multiply(
                *pMA_In1,
                *pMA_In2,
                *pMA_Out,
                scale);

    return ER_okay;
}

int D_Img_Proc::Math_ImgImg_Div(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, double scale)
{
    if(pMA_In1->empty() || pMA_In2->empty())        return ER_empty;
    if(pMA_In1->size != pMA_In2->size)              return ER_size_missmatch;
    if(pMA_In1->channels() != pMA_In2->channels())  return ER_channel_bad;
    if(pMA_In1->depth() != pMA_In2->depth())        return ER_bitdepth_missmatch;

    divide(
                *pMA_In1,
                *pMA_In2,
                *pMA_Out,
                scale);

    return ER_okay;
}

int D_Img_Proc::Math_ImgImg_BitAnd(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)
{
    if(pMA_In1->empty() || pMA_In2->empty())        return ER_empty;
    if(pMA_In1->size != pMA_In2->size)              return ER_size_missmatch;
    if(pMA_In1->channels() != pMA_In2->channels())  return ER_channel_missmatch;
    if(pMA_In1->depth() != pMA_In2->depth())        return ER_bitdepth_missmatch;

    bitwise_and(
                *pMA_In1,
                *pMA_In2,
                *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::Math_ImgImg_BitOr(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)
{
    if(pMA_In1->empty() || pMA_In2->empty())        return ER_empty;
    if(pMA_In1->size != pMA_In2->size)              return ER_size_missmatch;
    if(pMA_In1->channels() != pMA_In2->channels())  return ER_channel_missmatch;
    if(pMA_In1->depth() != pMA_In2->depth())        return ER_bitdepth_missmatch;

    bitwise_or(
                *pMA_In1,
                *pMA_In2,
                *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::Math_ImgImg_BitXor(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)
{
    if(pMA_In1->empty() || pMA_In2->empty())        return ER_empty;
    if(pMA_In1->size != pMA_In2->size)              return ER_size_missmatch;
    if(pMA_In1->channels() != pMA_In2->channels())  return ER_channel_missmatch;
    if(pMA_In1->depth() != pMA_In2->depth())        return ER_bitdepth_missmatch;

    bitwise_xor(
                *pMA_In1,
                *pMA_In2,
                *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::Math_ImgImg_Min(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)
{
    if(pMA_In1->empty() || pMA_In2->empty())        return ER_empty;
    if(pMA_In1->size != pMA_In2->size)              return ER_size_missmatch;
    if(pMA_In1->channels() != pMA_In2->channels())  return ER_channel_missmatch;
    if(pMA_In1->depth() != pMA_In2->depth())        return ER_bitdepth_missmatch;

    min(
                *pMA_In1,
                *pMA_In2,
                *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::Math_ImgImg_Max(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2)
{
    if(pMA_In1->empty() || pMA_In2->empty())        return ER_empty;
    if(pMA_In1->size != pMA_In2->size)              return ER_size_missmatch;
    if(pMA_In1->channels() != pMA_In2->channels())  return ER_channel_missmatch;
    if(pMA_In1->depth() != pMA_In2->depth())        return ER_bitdepth_missmatch;

    max(
                *pMA_In1,
                *pMA_In2,
                *pMA_Out);

    return ER_okay;
}

int D_Img_Proc::Math_ImgImg_Comp(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, int comp)
{
    if(pMA_In1->empty() || pMA_In2->empty())        return ER_empty;
    if(pMA_In1->size != pMA_In2->size)              return ER_size_missmatch;
    if(pMA_In1->channels() != pMA_In2->channels())  return ER_channel_missmatch;
    if(pMA_In1->depth() != pMA_In2->depth())        return ER_bitdepth_missmatch;

    compare(
                *pMA_In1,
                *pMA_In2,
                *pMA_Out,
                comp);

    return ER_okay;
}

int D_Img_Proc::Math_ImgImg_Function(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, function<double (double, double)> function_img1_img2)
{
    if(pMA_In1->empty())                    return ER_empty;
    if(pMA_In2->empty())                    return ER_empty;
    if(pMA_In1->size != pMA_In2->size)      return ER_size_missmatch;
    if(pMA_In1->channels() != 1)            return ER_channel_bad;
    if(pMA_In2->channels() != 1)            return ER_channel_bad;
    int ER;

    //double tmp_img
    Mat MA_tmp_double_1;
    ER = Convert_Double_1C(
                &MA_tmp_double_1,
                pMA_In1);
    if(ER != ER_okay)
    {
        MA_tmp_double_1.release();
        return ER;
    }

    Mat MA_tmp_double_2;
    ER = Convert_Double_1C(
                &MA_tmp_double_2,
                pMA_In2);
    if(ER != ER_okay)
    {
        MA_tmp_double_1.release();
        MA_tmp_double_2.release();
        return ER;
    }

    //output img
    *pMA_Out = Mat(pMA_In1->size(), CV_64FC1);

    //pixel pointers
    double* ptr_out = reinterpret_cast<double*>(pMA_Out->data);
    double* ptr_in1 = reinterpret_cast<double*>(MA_tmp_double_1.data);
    double* ptr_in2 = reinterpret_cast<double*>(MA_tmp_double_2.data);

    //loop pixels
    for(int px = 0; px < pMA_In1->cols * pMA_In1->rows; px++, ptr_in1++, ptr_in2++, ptr_out++)
        *ptr_out = function_img1_img2(*ptr_in1, *ptr_in2);

    //end
    MA_tmp_double_1.release();
    MA_tmp_double_2.release();
    return ER_okay;
}

int D_Img_Proc::Math_ImgImg_Function_8bit(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, function<uchar (double, double)> function_img1_img2)
{
    if(pMA_In1->empty())                    return ER_empty;
    if(pMA_In2->empty())                    return ER_empty;
    if(pMA_In1->size != pMA_In2->size)      return ER_size_missmatch;
    if(pMA_In1->channels() != 1)            return ER_channel_bad;
    if(pMA_In2->channels() != 1)            return ER_channel_bad;
    int ER;

    //double tmp_img
    Mat MA_tmp_double_1;
    ER = Convert_Double_1C(
                &MA_tmp_double_1,
                pMA_In1);
    if(ER != ER_okay)
    {
        MA_tmp_double_1.release();
        return ER;
    }

    Mat MA_tmp_double_2;
    ER = Convert_Double_1C(
                &MA_tmp_double_2,
                pMA_In2);
    if(ER != ER_okay)
    {
        MA_tmp_double_1.release();
        MA_tmp_double_2.release();
        return ER;
    }

    //output img
    *pMA_Out = Mat(pMA_In1->size(), CV_8UC1);

    //pixel pointers
    uchar*  ptr_out = reinterpret_cast<uchar* >(pMA_Out->data);
    double* ptr_in1 = reinterpret_cast<double*>(MA_tmp_double_1.data);
    double* ptr_in2 = reinterpret_cast<double*>(MA_tmp_double_2.data);

    //loop pixels
    for(int px = 0; px < pMA_In1->cols * pMA_In1->rows; px++, ptr_in1++, ptr_in2++, ptr_out++)
        *ptr_out = function_img1_img2(*ptr_in1, *ptr_in2);

    //end
    MA_tmp_double_1.release();
    MA_tmp_double_2.release();
    return ER_okay;
}

int D_Img_Proc::Math_ImgImg_Function_Complex(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, function<complex<double> (complex<double> x, complex<double> y)> function_img1_img2)
{
    if(pMA_In1->empty())                    return ER_empty;
    if(pMA_In2->empty())                    return ER_empty;
    if(pMA_In1->size != pMA_In2->size)      return ER_size_missmatch;
    if(pMA_In1->channels() != 2)            return ER_channel_bad;
    if(pMA_In2->channels() != 2)            return ER_channel_bad;
    int ER;

    //double tmp_img
    Mat MA_tmp_double_1;
    ER = Convert_Double(
                &MA_tmp_double_1,
                pMA_In1);
    if(ER != ER_okay)
    {
        MA_tmp_double_1.release();
        return ER;
    }

    Mat MA_tmp_double_2;
    ER = Convert_Double(
                &MA_tmp_double_2,
                pMA_In2);
    if(ER != ER_okay)
    {
        MA_tmp_double_1.release();
        MA_tmp_double_2.release();
        return ER;
    }

    //output img
    *pMA_Out = Mat(pMA_In1->size(), CV_64FC2);

    //pixel pointers
    Vec2d* ptr_out = reinterpret_cast<Vec2d*>(pMA_Out->data);
    Vec2d* ptr_in1 = reinterpret_cast<Vec2d*>(MA_tmp_double_1.data);
    Vec2d* ptr_in2 = reinterpret_cast<Vec2d*>(MA_tmp_double_2.data);

    //loop pixels
    for(int px = 0; px < pMA_In1->cols * pMA_In1->rows; px++, ptr_in1++, ptr_in2++, ptr_out++)
    {
        complex<double> in1((*ptr_in1)[0], (*ptr_in1)[1]);      //read img1
        complex<double> in2((*ptr_in2)[0], (*ptr_in2)[1]);      //read img2
        complex<double> out = function_img1_img2(in1, in2);     //calc out
        *ptr_out = Vec2d(out.real(), out.imag());               //write out
    }

    //end
    MA_tmp_double_1.release();
    MA_tmp_double_2.release();
    return ER_okay;
}

int D_Img_Proc::Math_ImgStack_Project(Mat *pMA_Out, vector<Mat> *pvMA_In, int stat)
{
    if(pvMA_In->empty())    return ER_empty;
    for(size_t i = 0; i < pvMA_In->size(); i++)
    {
        //qDebug() << i;
        if((*pvMA_In)[i].empty())                           return ER_empty;
        if((*pvMA_In)[i].channels() != 1)                   return ER_channel_bad;
        if((*pvMA_In)[0].size != (*pvMA_In)[i].size)        return ER_size_missmatch;
        if((*pvMA_In)[0].depth() != (*pvMA_In)[i].depth())  return ER_bitdepth_missmatch;
    }

    //size
    size_t n = pvMA_In->size();
    size_t area = (*pvMA_In)[0].cols * (*pvMA_In)[0].rows;

    //out
    *pMA_Out = Mat::zeros((*pvMA_In)[0].size(), CV_64FC1);
    double* ptr_out = reinterpret_cast<double*>(pMA_Out->data);

    //stack data
    vector<double> vd_pixel_data;
    vd_pixel_data.resize(n, 0);

    //stat function to be used
    function<double (vector<double>)> Stat_Function = D_Stat::Function_SingleStat(stat);

    switch ((*pvMA_In)[0].type()) {

    case CV_8UC1:
    {
        //qDebug() << "CV_8UC1";

        //pointers inputs
        vector<uchar*> vptr_in;
        vptr_in.resize(n);
        for(size_t img = 0; img < n; img++)
        {
            //qDebug() << "image data pointer init:" << img << "/" << n;
            vptr_in[img] = reinterpret_cast<uchar*>((*pvMA_In)[img].data);
        }

        //loop pixels
        for(size_t px = 0; px < area; px++, ptr_out++)
        {
            //qDebug() << "loop pixels:" << px << "/" << area << "---------------------------------";

            for(size_t img = 0; img < n; img++)
            {
                //qDebug() << "loop image layers in pixel:" << img << "/" << n;
                vd_pixel_data[img] = *(vptr_in[img]);
                vptr_in[img]++;
            }

            *ptr_out = Stat_Function(vd_pixel_data);
        }
    }
        break;

    case CV_8SC1:
    {
        //qDebug() << "CV_8SC1";

        //pointers inputs
        vector<char*> vptr_in;
        vptr_in.resize(n);
        for(size_t img = 0; img < n; img++)
            vptr_in[img] = reinterpret_cast<char*>((*pvMA_In)[img].data);

        //loop pixels
        for(size_t px = 0; px < area; px++, ptr_out++)
        {
            for(size_t img = 0; img < n; img++)
            {
                vd_pixel_data[img] = *(vptr_in[img]);
                vptr_in[img]++;
            }

            *ptr_out = Stat_Function(vd_pixel_data);
        }
    }
        break;

    case CV_16UC1:
    {
        //qDebug() << "CV_16UC1";

        //pointers inputs
        vector<ushort*> vptr_in;
        vptr_in.resize(n);
        for(size_t img = 0; img < n; img++)
            vptr_in[img] = reinterpret_cast<ushort*>((*pvMA_In)[img].data);

        //loop pixels
        for(size_t px = 0; px < area; px++, ptr_out++)
        {
            for(size_t img = 0; img < n; img++)
            {
                vd_pixel_data[img] = *(vptr_in[img]);
                vptr_in[img]++;
            }

            *ptr_out = Stat_Function(vd_pixel_data);
        }
    }
        break;

    case CV_16SC1:
    {
        //qDebug() << "CV_16SC1";

        //pointers inputs
        vector<short*> vptr_in;
        vptr_in.resize(n);
        for(size_t img = 0; img < n; img++)
            vptr_in[img] = reinterpret_cast<short*>((*pvMA_In)[img].data);

        //loop pixels
        for(size_t px = 0; px < area; px++, ptr_out++)
        {
            for(size_t img = 0; img < n; img++)
            {
                vd_pixel_data[img] = *(vptr_in[img]);
                vptr_in[img]++;
            }

            *ptr_out = Stat_Function(vd_pixel_data);
        }
    }
        break;

    case CV_32SC1:
    {
        //qDebug() << "CV_32SC1";

        //pointers inputs
        vector<int*> vptr_in;
        vptr_in.resize(n);
        for(size_t img = 0; img < n; img++)
            vptr_in[img] = reinterpret_cast<int*>((*pvMA_In)[img].data);

        //loop pixels
        for(size_t px = 0; px < area; px++, ptr_out++)
        {
            for(size_t img = 0; img < n; img++)
            {
                vd_pixel_data[img] = *(vptr_in[img]);
                vptr_in[img]++;
            }

            *ptr_out = Stat_Function(vd_pixel_data);
        }
    }
        break;

    case CV_32FC1:
    {
        //qDebug() << "CV_32FC1";

        //pointers inputs
        vector<float*> vptr_in;
        vptr_in.resize(n);
        for(size_t img = 0; img < n; img++)
            vptr_in[img] = reinterpret_cast<float*>((*pvMA_In)[img].data);

        //loop pixels
        for(size_t px = 0; px < area; px++, ptr_out++)
        {
            for(size_t img = 0; img < n; img++)
            {
                vd_pixel_data[img] = *(vptr_in[img]);
                vptr_in[img]++;
            }

            *ptr_out = Stat_Function(vd_pixel_data);
        }
    }
        break;

    case CV_64FC1:
    {
        //qDebug() << "CV_64FC1";

        //pointers inputs
        vector<double*> vptr_in;
        vptr_in.resize(n);
        for(size_t img = 0; img < n; img++)
            vptr_in[img] = reinterpret_cast<double*>((*pvMA_In)[img].data);

        //loop pixels
        for(size_t px = 0; px < area; px++, ptr_out++)
        {
            for(size_t img = 0; img < n; img++)
            {
                vd_pixel_data[img] = *(vptr_in[img]);
                vptr_in[img]++;
            }

            *ptr_out = Stat_Function(vd_pixel_data);
        }
    }
        break;

    default:
        break;
    }

    return ER_okay;
}

int D_Img_Proc::Math_ImgStack_StatCombine(Mat *pMA_Out, vector<Mat> *pvMA_In0, vector<Mat> *pvMA_In1, function<double (vector<double>)> f_stat_0, function<double (vector<double>)> f_stat_1, function<double (double, double)> f_combi, bool force8bit)
{
    //qDebug() << "Math_ImgStack_StatCombine";

    //======================================================================    Error Checks

    if(pvMA_In0->empty())                                       return ER_empty;
    if(pvMA_In1->empty())                                       return ER_empty;
    if((*pvMA_In0)[0].size() != (*pvMA_In1)[0].size())          {qDebug() << "Math_ImgStack_StatCombine" << "Sizes Missmatch" << "1st vMA0 / 1st vMA1"; return ER_size_missmatch;}

    for(int i = 0; i < pvMA_In0->size(); i++)
    {
        if((*pvMA_In0)[i].empty())                              return ER_empty;
        if((*pvMA_In0)[i].type() != CV_8UC1)                    return ER_type_bad;
        if((*pvMA_In0)[i].size() != (*pvMA_In0)[0].size())      {qDebug() << "Math_ImgStack_StatCombine" << "Sizes Missmatch" << i << "vMA0 / 1st vMA0";return ER_size_missmatch;}
    }

    for(int i = 0; i < pvMA_In1->size(); i++)
    {
        if((*pvMA_In1)[i].empty())                              return ER_empty;
        if((*pvMA_In1)[i].type() != CV_8UC1)                    return ER_type_bad;
        if((*pvMA_In1)[i].size() != (*pvMA_In1)[0].size())      {qDebug() << "Math_ImgStack_StatCombine" << "Sizes Missmatch" << i << "vMA1 / 1st vMA1";return ER_size_missmatch;}
    }

    //======================================================================    Dimensions

    //image dimension
    int Hi = (*pvMA_In0)[0].rows;       //image heigth

    //======================================================================    init

    //init out
    if(force8bit)
        *pMA_Out = Mat::zeros((*pvMA_In0)[0].size(), CV_8UC1);
    else
        *pMA_Out = Mat::zeros((*pvMA_In0)[0].size(), CV_64FC1);

    //======================================================================    thread & synch

    //threads
    int                 thread_number = getNumberOfCPUs();
    vector<thread>      v_threads;
    v_threads.resize(thread_number);

    //asynch
    for(int t = 0; t < thread_number; t++)
    {
        //range for thread
        int row_start   = (((t    ) / static_cast<double>(thread_number))) * Hi;
        int row_end     = (((t + 1) / static_cast<double>(thread_number))) * Hi;

        //start thread
        v_threads[t] = thread(
                    Math_ImgStack_StatCombine_Thread,
                    pMA_Out,
                    pvMA_In0,
                    pvMA_In1,
                    f_stat_0,
                    f_stat_1,
                    f_combi,
                    force8bit,
                    row_start,
                    row_end);
    }

    //synch
    for(int t = 0; t < thread_number; t++)
        v_threads[t].join();

    return ER_okay;
}

int D_Img_Proc::Math_ImgStack_StatCombine_Thread(Mat *pMA_Out, vector<Mat> *pvMA_In0, vector<Mat> *pvMA_In1, function<double (vector<double>)> f_stat_0, function<double (vector<double>)> f_stat_1, function<double (double, double)> f_combi, bool force8bit, int row_start, int row_end)
{
    //qDebug() << "Math_ImgStack_StatCombine_Thread" << "from line" << row_start << "to" << row_end;

    //area to proc in
    int px_proc         = pMA_Out->cols * (row_end - row_start);
    int px_offset       = pMA_Out->cols * row_start;

    //vector sizes
    size_t n0           = pvMA_In0->size();
    size_t n1           = pvMA_In1->size();

    //input pointers 0
    vector<uchar*> vptr_in0(n0);
    for(int i = 0; i < n0; i++)
        vptr_in0[i] = reinterpret_cast<uchar*>((*pvMA_In0)[i].data) + px_offset;

    //input pointers 1
    vector<uchar*> vptr_in1(n1);
    for(int i = 0; i < n1; i++)
        vptr_in1[i] = reinterpret_cast<uchar*>((*pvMA_In1)[i].data) + px_offset;

    //px value vectors
    vector<double> vpx0(n0);
    vector<double> vpx1(n1);

    //8bit or double?
    if(force8bit)
    {
        uchar*  ptr_out  = reinterpret_cast<uchar* >(pMA_Out->data) + px_offset;

        for(int px = 0; px < px_proc; px++, ptr_out++)
        {
            //qDebug() << "px" << px;

            //fill pixel vector 0
            for(int i = 0; i < n0; i++)
            {
                vpx0[i] = *(vptr_in0[i]);
                vptr_in0[i]++;
            }

            //fill pixel vector 1
            for(int i = 0; i < n1; i++)
            {
                vpx1[i] = *(vptr_in1[i]);
                vptr_in1[i]++;
            }

            //calc & write result
            *ptr_out = static_cast<uchar>(
                        f_combi(
                            f_stat_0(vpx0),
                            f_stat_1(vpx1)));
        }
    }
    else
    {
        double* ptr_out  = reinterpret_cast<double*>(pMA_Out->data) + px_offset;

        for(int px = 0; px < px_proc; px++, ptr_out++)
        {
            //fill pixel vector 0
            for(int i = 0; i < n0; i++)
            {
                vpx0[i] = *(vptr_in0[i]);
                vptr_in0[i]++;
            }

            //fill pixel vector 1
            for(int i = 0; i < n1; i++)
            {
                vpx1[i] = *(vptr_in1[i]);
                vptr_in1[i]++;
            }

            //calc & write result
            *ptr_out = f_combi(
                            f_stat_0(vpx0),
                            f_stat_1(vpx1));
        }
    }

    return ER_okay;
}

int D_Img_Proc::Math_Special_Add_Color(Mat *pMA_Out, Mat *pMA_In_Color, Mat *pMA_In0, Mat *pMA_In1, Mat *pMA_In2)
{
    int ER;

    //split channels
    Mat MA_split[3];
    split(
                *pMA_In_Color,
                MA_split);


    //channel 0
    ER = Math_ImgImg_Add(
                &(MA_split[0]),
                &(MA_split[0]),
                pMA_In0);
    if(ER != ER_okay)   return ER;

    ER = Math_ImgImg_Diff(
                &(MA_split[1]),
                &(MA_split[1]),
                pMA_In0);
    if(ER != ER_okay)   return ER;

    ER = Math_ImgImg_Diff(
                &(MA_split[2]),
                &(MA_split[2]),
                pMA_In0);
    if(ER != ER_okay)   return ER;


    //channel 1
    ER = Math_ImgImg_Diff(
                &(MA_split[0]),
                &(MA_split[0]),
                pMA_In1);
    if(ER != ER_okay)   return ER;

    ER = Math_ImgImg_Add(
                &(MA_split[1]),
                &(MA_split[1]),
                pMA_In1);
    if(ER != ER_okay)   return ER;

    ER = Math_ImgImg_Diff(
                &(MA_split[2]),
                &(MA_split[2]),
                pMA_In1);
    if(ER != ER_okay)   return ER;


    //channel 2
    ER = Math_ImgImg_Diff(
                &(MA_split[0]),
                &(MA_split[0]),
                pMA_In2);
    if(ER != ER_okay)   return ER;

    ER = Math_ImgImg_Diff(
                &(MA_split[1]),
                &(MA_split[1]),
                pMA_In2);
    if(ER != ER_okay)   return ER;

    ER = Math_ImgImg_Add(
                &(MA_split[2]),
                &(MA_split[2]),
                pMA_In2);
    if(ER != ER_okay)   return ER;


    //merge channels again (to output)
    merge(
                MA_split,
                3,
                *pMA_Out);

    for(int c = 0; c < 3; c++)
        MA_split[c].release();
    return ER_okay;
}

int D_Img_Proc::Math_Special_NADH(Mat *pMA_NADH, Mat *pMA_I, Mat *pMA_A2, Mat *pMA_T1, Mat *pMA_T2, float k, bool ignore_0, float T2_Max_Thres, float T2_Max_Const)
{
    if(pMA_I->empty() || pMA_A2->empty() || pMA_T1->empty() || pMA_T2->empty())                                                 return ER_empty;
    if((pMA_I->size() != pMA_A2->size()) || (pMA_I->size() != pMA_T1->size()) || (pMA_I->size() != pMA_T2->size()))             return ER_size_missmatch;
    if((pMA_I->channels() != 1) || (pMA_A2->channels() != 1) || (pMA_T1->channels() != 1) || (pMA_T2->channels() != 1))         return ER_channel_bad;
    if((pMA_I->depth() != CV_32F) || (pMA_A2->depth() != CV_32F) || (pMA_T1->depth() != CV_32F) || (pMA_T2->depth() != CV_32F)) return ER_bitdepth_bad;

    *pMA_NADH = Mat(pMA_I->size(), CV_32FC1, Scalar(0));

    unsigned int width = pMA_I->cols;
    unsigned int height = pMA_I->rows;
    unsigned int area = width * height;

    float* ptr_N = reinterpret_cast<float*>(pMA_NADH->data);
    float* ptr_I = reinterpret_cast<float*>(pMA_I->data);
    float* ptr_A2 = reinterpret_cast<float*>(pMA_A2->data);
    float* ptr_T1 = reinterpret_cast<float*>(pMA_T1->data);
    float* ptr_T2 = reinterpret_cast<float*>(pMA_T2->data);
    for (unsigned int px = 0; px < area; px++, ptr_N++, ptr_I++, ptr_A2++, ptr_T1++, ptr_T2++)
    {
        float I = *ptr_I;
        float A2 = *ptr_A2;
        float T1 = *ptr_T1;
        float T2 = *ptr_T2;

        if(T2 > T2_Max_Thres)
            T2 = T2_Max_Thres;

        if(!ignore_0 || (I != 0 && A2 != 0 && T1 != 0 && T2 != 0))
            *ptr_N = (float)
                    (k * I * (T2_Max_Const - T2))
                    /
                    (((1 - A2) * T1) + (A2 * T2));
    }

    return ER_okay;
}

int D_Img_Proc::Math_Special_NADPH(Mat *pMA_NADPH, Mat *pMA_I, Mat *pMA_A2, Mat *pMA_T1, Mat *pMA_T2, float k, bool ignore_0, float T2_Min_Thres, float T2_Min_Const)
{
    if(pMA_I->empty() || pMA_A2->empty() || pMA_T1->empty() || pMA_T2->empty())                                                 return ER_empty;
    if((pMA_I->size() != pMA_A2->size()) || (pMA_I->size() != pMA_T1->size()) || (pMA_I->size() != pMA_T2->size()))             return ER_size_missmatch;
    if((pMA_I->channels() != 1) || (pMA_A2->channels() != 1) || (pMA_T1->channels() != 1) || (pMA_T2->channels() != 1))         return ER_channel_bad;
    if((pMA_I->depth() != CV_32F) || (pMA_A2->depth() != CV_32F) || (pMA_T1->depth() != CV_32F) || (pMA_T2->depth() != CV_32F)) return ER_bitdepth_bad;

    *pMA_NADPH = Mat(pMA_I->size(), CV_32FC1, Scalar(0));

    unsigned int width = pMA_I->cols;
    unsigned int height = pMA_I->rows;
    unsigned int area = width * height;

    float* ptr_N = reinterpret_cast<float*>(pMA_NADPH->data);
    float* ptr_I = reinterpret_cast<float*>(pMA_I->data);
    float* ptr_A2 = reinterpret_cast<float*>(pMA_A2->data);
    float* ptr_T1 = reinterpret_cast<float*>(pMA_T1->data);
    float* ptr_T2 = reinterpret_cast<float*>(pMA_T2->data);
    for (unsigned int px = 0; px < area; px++, ptr_N++, ptr_I++, ptr_A2++, ptr_T1++, ptr_T2++)
    {
        float I = *ptr_I;
        float A2 = *ptr_A2;
        float T1 = *ptr_T1;
        float T2 = *ptr_T2;

        if(T2 < T2_Min_Thres)
            T2 = T2_Min_Thres;

        if(!ignore_0 || (I != 0 && A2 != 0 && T1 != 0 && T2 != 0))
            *ptr_N = (float)
                    (k * I * (T2 - T2_Min_Const))
                    /
                    (((1 - A2) * T1) + (A2 * T2));
    }

    return ER_okay;
}

int D_Img_Proc::Math_Special_NADPH_NADH(Mat *pMA_NADPH_NADH, Mat *pMA_T2, bool ignore_0, float T2_Min_Thres, float T2_Max_Thres, float T2_Min_Const, float T2_Max_Const)
{
    if(pMA_T2->empty())             return ER_empty;
    if(pMA_T2->channels() != 1)     return ER_channel_bad;
    if(pMA_T2->depth() != CV_32F)   return ER_bitdepth_bad;

    *pMA_NADPH_NADH = Mat(pMA_T2->size(), CV_32FC1, Scalar(0));

    unsigned int width = pMA_T2->cols;
    unsigned int height = pMA_T2->rows;
    unsigned int area = width * height;

    float* ptr_N = reinterpret_cast<float*>(pMA_NADPH_NADH->data);
    float* ptr_T2 = reinterpret_cast<float*>(pMA_T2->data);
    for (unsigned int px = 0; px < area; px++, ptr_N++, ptr_T2++)
    {
        float T2 = *ptr_T2;

        if(T2 < T2_Min_Thres)
            T2 = T2_Min_Thres;
        if(T2 > T2_Max_Thres)
            T2 = T2_Max_Thres;

        if(!ignore_0 || (T2 != 0))
            *ptr_N = (float)
                    (T2 - T2_Min_Const)
                    /
                    (T2_Max_Const - T2);
    }

    return ER_okay;
}

int D_Img_Proc::Math_Special_Trans2Count(Mat *pMA_Count, Mat *pMA_Trans, float base, float scale)
{
    if(pMA_Trans->empty())              return ER_empty;
    if(pMA_Trans->channels() != 1)      return ER_channel_bad;
    if(pMA_Trans->depth() != CV_32F)    return ER_bitdepth_bad;
    if(scale <= 0)                      return ER_parameter_bad;
    if(base <= 0)                       return ER_parameter_bad;

    //size
    unsigned int area = pMA_Trans->cols * pMA_Trans->rows;

    //base transformation
    double lambda = log(base);

    //pointers to data
    *pMA_Count = Mat::zeros(pMA_Trans->size(), CV_32FC1);
    float* ptr_trans = reinterpret_cast<float*>(pMA_Trans->data);
    float* ptr_count = reinterpret_cast<float*>(pMA_Count->data);

    //loop pixels and calc
    for (unsigned int px = 0; px < area; px++, ptr_count++, ptr_trans++)
    {
        float trans = *ptr_trans;

        if((trans > 0) && (trans < 1))
            *ptr_count = static_cast<float>((log(trans) * scale) / lambda);
    }

    //qDebug() << "Math_Special_Trans2Count" << "sucess";
    return ER_okay;
}

int D_Img_Proc::Math_Special_IncreaseIfSet(Mat *pMA_Count, Mat *pMA_Check)
{
    if(pMA_Count->empty())                  return ER_empty;
    if(pMA_Check->empty())                  return ER_empty;
    if(pMA_Count->channels() != 1)          return ER_channel_bad;
    if(pMA_Check->channels() != 1)          return ER_channel_bad;
    if(pMA_Count->depth() != CV_32S)        return ER_bitdepth_bad;
    if(pMA_Check->depth() != CV_8U)         return ER_bitdepth_bad;
    if(pMA_Check->size != pMA_Count->size)  return ER_size_missmatch;

    //size
    unsigned int area = pMA_Count->cols * pMA_Count->rows;

    //pointers to data
    uchar* ptr_check = reinterpret_cast<uchar*>(pMA_Check->data);
    int* ptr_count   = reinterpret_cast<int*  >(pMA_Count->data);

    //loop pixels and increase, if set
    for (unsigned int px = 0; px < area; px++, ptr_check++, ptr_count++)
        if(*ptr_check)
            *ptr_count = *ptr_count + 1;

    //test
    double min, max;
    minMaxLoc(*pMA_Count, &min, &max);
    //qDebug() << "Math_Special_IncreaseIfSet max:" << max;

    return ER_okay;
}

int D_Img_Proc::Shading_Correct(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Reference)
{
    return Math_ImgImg_Div(
                pMA_Out,
                pMA_In,
                pMA_Reference,
                mean(*pMA_Reference).val[0]);
}

int D_Img_Proc::Mask(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask)
{
    if(pMA_In->empty())                     return ER_empty;
    if(pMA_Mask->empty())                   return ER_empty;
    if(pMA_In->size() != pMA_Mask->size())  return ER_size_missmatch;
    if(pMA_Mask->type() != CV_8UC1)         return ER_type_bad;

    switch (pMA_In->channels()) {

    case 1:
    {
        int ER = Mask_1C(
                    pMA_Out,
                    pMA_In,
                    pMA_Mask);
        if(ER != ER_okay)   return ER;
    }
        break;

    case 2:
    {
        Mat MA_tmp_in[2];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_roi[2];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Mask_1C(
                        &(MA_tmp_roi[c]),
                        &(MA_tmp_in[c]),
                        pMA_Mask);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_roi,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_roi[c].release();
        }
    }
        break;

    case 3:
    {
        Mat MA_tmp_in[3];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_roi[3];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Mask_1C(
                        &(MA_tmp_roi[c]),
                        &(MA_tmp_in[c]),
                        pMA_Mask);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_roi,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_roi[c].release();
        }
    }
        break;

    case 4:
    {
        Mat MA_tmp_in[4];
        split(
                    *pMA_In,
                    MA_tmp_in);

        Mat MA_tmp_roi[4];
        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Mask_1C(
                        &(MA_tmp_roi[c]),
                        &(MA_tmp_in[c]),
                        pMA_Mask);
            if(ER != ER_okay)   return ER;
        }

        merge(
                    MA_tmp_roi,
                    pMA_In->channels(),
                    *pMA_Out);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
            MA_tmp_roi[c].release();
        }
    }
        break;

    default:
        break;
    }

    return ER_okay;
}

int D_Img_Proc::Mask_1C(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Mask)
{
    if(pMA_In->empty() || pMA_Mask->empty())                        return ER_empty;
    if(pMA_In->size() != pMA_Mask->size())                          return ER_size_missmatch;
    if((pMA_In->channels() != 1) || (pMA_Mask->channels() != 1))    return ER_channel_bad;
    if(pMA_Mask->depth() != CV_8UC1)                                return ER_bitdepth_bad;

    //Output image
    *pMA_Out = Mat::zeros(pMA_In->size(), pMA_In->type());

    //mask pointer
    uchar* ptr_mask = reinterpret_cast<uchar*>(pMA_Mask->data);

    //dimensions
    unsigned int width = pMA_In->cols;
    unsigned int height = pMA_In->rows;
    unsigned int area = width * height;

    //masking (type switch)
    switch (pMA_In->type()) {

    case CV_8UC1://------------------------------------------------
    {
        uchar* ptr_in = reinterpret_cast<uchar*>(pMA_In->data);
        uchar* ptr_out = reinterpret_cast<uchar*>(pMA_Out->data);
        for (unsigned int px = 0; px < area; px++, ptr_in++, ptr_out++, ptr_mask++)
            if(*ptr_mask)
                *ptr_out = *ptr_in;
    }
        break;

    case CV_8SC1://------------------------------------------------
    {
        char* ptr_in = reinterpret_cast<char*>(pMA_In->data);
        char* ptr_out = reinterpret_cast<char*>(pMA_Out->data);
        for (unsigned int px = 0; px < area; px++, ptr_in++, ptr_out++, ptr_mask++)
            if(*ptr_mask)
                *ptr_out = *ptr_in;
    }
        break;

    case CV_16UC1://------------------------------------------------
    {
        ushort* ptr_in = reinterpret_cast<ushort*>(pMA_In->data);
        ushort* ptr_out = reinterpret_cast<ushort*>(pMA_Out->data);
        for (unsigned int px = 0; px < area; px++, ptr_in++, ptr_out++, ptr_mask++)
            if(*ptr_mask)
                *ptr_out = *ptr_in;
    }
        break;

    case CV_16SC1://------------------------------------------------
    {
        short* ptr_in = reinterpret_cast<short*>(pMA_In->data);
        short* ptr_out = reinterpret_cast<short*>(pMA_Out->data);
        for (unsigned int px = 0; px < area; px++, ptr_in++, ptr_out++, ptr_mask++)
            if(*ptr_mask)
                *ptr_out = *ptr_in;
    }
        break;

    case CV_32SC1://------------------------------------------------
    {
        int* ptr_in = reinterpret_cast<int*>(pMA_In->data);
        int* ptr_out = reinterpret_cast<int*>(pMA_Out->data);
        for (unsigned int px = 0; px < area; px++, ptr_in++, ptr_out++, ptr_mask++)
            if(*ptr_mask)
                *ptr_out = *ptr_in;
    }
        break;

    case CV_32FC1://------------------------------------------------
    {
        float* ptr_in = reinterpret_cast<float*>(pMA_In->data);
        float* ptr_out = reinterpret_cast<float*>(pMA_Out->data);
        for (unsigned int px = 0; px < area; px++, ptr_in++, ptr_out++, ptr_mask++)
            if(*ptr_mask)
                *ptr_out = *ptr_in;
    }
        break;

    case CV_64FC1://------------------------------------------------
    {
        double* ptr_in = reinterpret_cast<double*>(pMA_In->data);
        double* ptr_out = reinterpret_cast<double*>(pMA_Out->data);
        for (unsigned int px = 0; px < area; px++, ptr_in++, ptr_out++, ptr_mask++)
            if(*ptr_mask)
                *ptr_out = *ptr_in;
    }
        break;

    default://--------------------------------------------------
        return ER_type_bad;
        break;
    }

    return ER_okay;
}

int D_Img_Proc::Value_to_MinOrMax(Mat *pMA_Out, Mat *pMA_In, double val_src, bool to_min)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->channels() != 1)     return ER_channel_bad;

    double min = 0.0;
    double max = 0.0;
    minMaxLoc(
                *pMA_In,
                &min,
                &max);

    double      target = 0.0;
    if(to_min)  target = min;
    else        target = max;

    return Value_to_Value(
                pMA_Out,
                pMA_In,
                val_src,
                target);
}

int D_Img_Proc::Value_to_Value(Mat *pMA_Out, Mat *pMA_In, double val_src, double val_dst)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->channels() != 1)     return ER_channel_bad;

    *pMA_Out = pMA_In->clone();

    unsigned int width = pMA_In->cols;
    unsigned int height = pMA_In->rows;
    unsigned int area = width * height;

    switch (pMA_In->type()) {

    case CV_8UC1://------------------------------------------------
    {
        uchar* ptr_in = reinterpret_cast<uchar*>(pMA_In->data);
        uchar* ptr_out = reinterpret_cast<uchar*>(pMA_Out->data);
        for (unsigned int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if(*ptr_in == val_src)
                *ptr_out = (uchar)val_dst;
    }
        break;

    case CV_16UC1://-----------------------------------------------
    {
        ushort* ptr_in = reinterpret_cast<ushort*>(pMA_In->data);
        ushort* ptr_out = reinterpret_cast<ushort*>(pMA_Out->data);
        for (unsigned int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if(*ptr_in == val_src)
                *ptr_out = (uchar)val_dst;
    }
        break;

    case CV_32FC1://-----------------------------------------------
    {
        float* ptr_in = reinterpret_cast<float*>(pMA_In->data);
        float* ptr_out = reinterpret_cast<float*>(pMA_Out->data);
        for (unsigned int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if(*ptr_in == val_src)
                *ptr_out = (uchar)val_dst;
    }
        break;

    case CV_64FC1://-----------------------------------------------
    {
        double* ptr_in = reinterpret_cast<double*>(pMA_In->data);
        double* ptr_out = reinterpret_cast<double*>(pMA_Out->data);
        for (unsigned int px = 0; px < area; px++, ptr_in++, ptr_out++)
            if(*ptr_in == val_src)
                *ptr_out = (uchar)val_dst;
    }
        break;

    default://--------------------------------------------------
        return ER_type_bad;
        break;
    }

    return ER_okay;
}

int D_Img_Proc::Histo_Equal(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->type() != CV_8UC1)   return ER_type_bad;

    equalizeHist(
                *pMA_In,
                *pMA_Out);

    return ER_okay;
}


int D_Img_Proc::Calc_Hist(Mat *pMA_Hist, Mat *pMA_In, bool uniform, bool accum)
{
    //i dont understand what this does and will write my own...
    //https://docs.opencv.org/3.1.0/d6/dc7/group__imgproc__hist.html#ga4b2b5fd75503ff9e6844cc4dcdaed35d
    return -1;

    if(pMA_In->empty())                 return ER_empty;
    if((pMA_In->type() != CV_8UC1))     return ER_bitdepth_bad;

    int         channels[]  = {0};

    int         bin         = 255;

    int         hist_size[] = {bin};

    float       range[]   = {0, 256};
    const float *ranges[]   = {range};

    calcHist(
                pMA_In,     //Input image(s)
                1,          //Number of images
                channels,   //Channels to be analyzed
                Mat(),      //Mask (no mask in this case)
                *pMA_Hist,  //Histogram Output
                1,          //Number of Channels to be analyzed
                hist_size,  //Size of hist
                ranges,     //range
                uniform,    //uniform
                accum);     //accum

    return ER_okay;
}

int D_Img_Proc::Calc_Hist(vector<vector<double> > *vv_hist, Mat *pMA_In, bool uniform, bool accum)
{
    if(pMA_In->empty())                                             return ER_empty;
    if((pMA_In->channels() != 1) && (pMA_In->channels() != 3))      return ER_channel_bad;


    //==========================================================  read and export values
    //qDebug() << "read and export values";
    unsigned int ch = pMA_In->channels();

    unsigned int width = pMA_In->cols;
    unsigned int height = pMA_In->rows;
    unsigned int area = width * height;

    unsigned int max;
    switch (pMA_In->depth()) {
    case        CV_8U:      max = 256;       break;
    case        CV_16U:     max = 65336;     break;
    case        CV_32S:     max = 65336;     break;
    default:    return ER_bitdepth_bad;      break;}

    //==========================================================  allocate memory for hist
    //qDebug() << "allocate memory for hist";
    vv_hist->resize(ch);
    for(unsigned int c = 0; c < ch; c++)
        (*vv_hist)[c].resize(max, 0);


    //==========================================================  calc hist
    //qDebug() << "calc hist";
    switch (pMA_In->type()) {

    case CV_8UC1://-----------------------------------------------
    {
        //qDebug() << "CV_8UC1";
        uchar* ptr = reinterpret_cast<uchar*>(pMA_In->data);    //not needed, but for clarification
        for (unsigned int px = 0; px < area; px++, ptr++)       //loop pixels
            (*vv_hist)[0][*ptr]++;                              //cummmulate hist
    }
        break;

    case CV_8UC3://-----------------------------------------------
    {
        //qDebug() << "CV_8UC3";
        for (unsigned int y = 0; y < height; y++)               //loop rows
            for (unsigned int x = 0; x < width; x++)            //loop columns
            {
                Vec3b pixel = pMA_In->at<Vec3b>(Point(x,y));    //get pixe value
                //qDebug() << "XY" << x << y << "BGR:" << pixel[0] << pixel[1] << pixel[2];
                for(unsigned int c = 0; c < ch; c++)            //loop channels
                    (*vv_hist)[c][pixel[c]]++;                  //cummmulate hist
            }
    }
        break;

    case CV_16UC1://----------------------------------------------
    {
        //qDebug() << "CV_16UC1";
        ushort* ptr = reinterpret_cast<ushort*>(pMA_In->data);  //cast to read as 16bit
        for (unsigned int px = 0; px < area; px++, ptr++)       //loop pixels
            (*vv_hist)[0][*ptr]++;                              //cummmulate hist
    }
        break;

    case CV_32SC1://----------------------------------------------
    {
        //qDebug() << "CV_32SC1";
        int* ptr = reinterpret_cast<int*>(pMA_In->data);        //cast to read as 32bit
        for (unsigned int px = 0; px < area; px++, ptr++)       //loop pixels
        {
            if(*ptr < static_cast<int>(max))
                (*vv_hist)[0][*ptr]++;                          //cummmulate hist
            else
                (*vv_hist)[0][max - 1]++;
        }
    }
        break;

    default://--------------------------------------------------
        return ER_type_bad;
        break;
    }


    //==========================================================  accumulate/uniform
    //qDebug() << "accumulate/uniform";
    if(accum)
        for(unsigned int c = 0; c < ch; c++)
            for(unsigned int v = 1; v < max; v++)
                (*vv_hist)[c][v] += (*vv_hist)[c][v - 1];

    if(uniform)
        for(unsigned int c = 0; c < ch; c++)
            for(unsigned int v = 0; v < max; v++)
                (*vv_hist)[c][v] /= (double)area;

    //qDebug() << "img_proc calc hist succeces";
    return ER_okay;
}

int D_Img_Proc::Calc_Hist_Multi(vector<vector<double> > *vv_hist, Mat *pMA_In, bool uniform, bool accum, unsigned int class_count, vector<double> *v_min_ext, vector<double> *v_max_ext, vector<double> *v_step_ext)
{
    if(pMA_In->empty()) return ER_empty;

    //clear and resize
    vv_hist->clear();
    v_min_ext->clear();
    v_max_ext->clear();
    v_step_ext->clear();
    vv_hist->resize(pMA_In->channels());
    v_min_ext->resize(pMA_In->channels());
    v_max_ext->resize(pMA_In->channels());
    v_step_ext->resize(pMA_In->channels());

    switch (pMA_In->channels()) {

    case 1:
    {
        int ER = Calc_Hist_1C(
                    &((*vv_hist)[0]),
                    pMA_In,
                    uniform,
                    accum,
                    class_count,
                    &((*v_min_ext)[0]),
                    &((*v_max_ext)[0]),
                    &((*v_step_ext)[0]));
        if(ER != ER_okay)   return ER;
    }
        break;

    case 2:
    {
        Mat MA_tmp_in[2];
        split(
                    *pMA_In,
                    MA_tmp_in);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Calc_Hist_1C(
                        &((*vv_hist)[c]),
                        &(MA_tmp_in[c]),
                        uniform,
                        accum,
                        class_count,
                        &((*v_min_ext)[c]),
                        &((*v_max_ext)[c]),
                        &((*v_step_ext)[c]));
            if(ER != ER_okay)   return ER;
        }

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
        }
    }
        break;

    case 3:
    {
        Mat MA_tmp_in[3];
        split(
                    *pMA_In,
                    MA_tmp_in);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Calc_Hist_1C(
                        &((*vv_hist)[c]),
                        &(MA_tmp_in[c]),
                        uniform,
                        accum,
                        class_count,
                        &((*v_min_ext)[c]),
                        &((*v_max_ext)[c]),
                        &((*v_step_ext)[c]));
            if(ER != ER_okay)   return ER;
        }

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
        }
    }
        break;

    case 4:
    {
        Mat MA_tmp_in[4];
        split(
                    *pMA_In,
                    MA_tmp_in);

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            int ER = Calc_Hist_1C(
                        &((*vv_hist)[c]),
                        &(MA_tmp_in[c]),
                        uniform,
                        accum,
                        class_count,
                        &((*v_min_ext)[c]),
                        &((*v_max_ext)[c]),
                        &((*v_step_ext)[c]));
            if(ER != ER_okay)   return ER;
        }

        for(int c = 0; c < pMA_In->channels(); c++)
        {
            MA_tmp_in[c].release();
        }
    }
        break;

    default:
        break;
    }

    return ER_okay;
}

int D_Img_Proc::Calc_Hist_1C(vector<double> *v_hist, Mat *pMA_In, bool uniform, bool accum, unsigned int class_count, double *min_ext, double *max_ext, double *step_ext)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->channels() != 1)     return ER_channel_bad;

    //==========================================================  read and export values
    //qDebug() << "read and export values";
    unsigned int width = pMA_In->cols;
    unsigned int height = pMA_In->rows;
    unsigned int area = width * height;


    //==========================================================  allocate memory for hist
    //qDebug() << "allocate memory for hist";
    v_hist->resize(class_count, 0);


    //==========================================================  range & step
    minMaxLoc(
                *pMA_In,
                min_ext,
                max_ext);

    double min      = *min_ext;
    double max      = *max_ext;
    double range    = max - min;
    double step     = range / (class_count - 1);

    *step_ext = step;

    //qDebug() << "min" << min;
    //qDebug() << "max" << max;
    //qDebug() << "range" << range;
    //qDebug() << "class_count" << class_count;
    //qDebug() << "step" << step;


    //==========================================================  calc hist
    //qDebug() << "calc hist";
    switch (pMA_In->type()) {

    case CV_8UC1://-----------------------------------------------
    {
        //qDebug() << "CV_8UC1";
        uchar* ptr = reinterpret_cast<uchar*>(pMA_In->data);    //not needed, but for clarification
        for (unsigned int px = 0; px < area; px++, ptr++)       //loop pixels
        {
            uchar           val = *ptr;                         //read value
            unsigned int    pos = (val - min) / step;           //calc position
            (*v_hist)[pos]++;                                   //cummmulate hist
        }
    }
        break;

    case CV_8SC1://-----------------------------------------------
    {
        //qDebug() << "CV_8SC1";
        char* ptr = reinterpret_cast<char*>(pMA_In->data);      //not needed, but for clarification
        for (unsigned int px = 0; px < area; px++, ptr++)       //loop pixels
        {
            char           val = *ptr;                          //read value
            unsigned int    pos = (val - min) / step;           //calc position
            (*v_hist)[pos]++;                                   //cummmulate hist
        }
    }
        break;


    case CV_16UC1://----------------------------------------------
    {
        //qDebug() << "CV_16UC1";
        ushort* ptr = reinterpret_cast<ushort*>(pMA_In->data);  //cast to read as 16bit
        for (unsigned int px = 0; px < area; px++, ptr++)       //loop pixels
        {
            ushort          val = *ptr;                         //read value
            unsigned int    pos = (val - min) / step;           //calc position
            (*v_hist)[pos]++;                                   //cummmulate hist
        }
    }
        break;

    case CV_16SC1://-----------------------------------------------
    {
        //qDebug() << "CV_16SC1";
        short* ptr = reinterpret_cast<short*>(pMA_In->data);    //not needed, but for clarification
        for (unsigned int px = 0; px < area; px++, ptr++)       //loop pixels
        {
            short           val = *ptr;                         //read value
            unsigned int    pos = (val - min) / step;           //calc position
            (*v_hist)[pos]++;                                   //cummmulate hist
        }
    }
        break;

    case CV_32FC1://----------------------------------------------
    {
        //qDebug() << "CV_32FC1";
        float* ptr = reinterpret_cast<float*>(pMA_In->data);    //cast to read as 16bit
        for (unsigned int px = 0; px < area; px++, ptr++)       //loop pixels
        {
            float           val = *ptr;                         //read value
            unsigned int    pos = (val - min) / step;           //calc position
            (*v_hist)[pos]++;                                   //cummmulate hist
        }
    }
        break;

    case CV_64FC1://----------------------------------------------
    {
        //qDebug() << "CV_64FC1";
        double* ptr = reinterpret_cast<double*>(pMA_In->data);  //cast to read as 16bit
        for (unsigned int px = 0; px < area; px++, ptr++)       //loop pixels
        {
            double          val = *ptr;                         //read value
            unsigned int    pos = (val - min) / step;           //calc position
            (*v_hist)[pos]++;                                   //cummmulate hist
        }
    }
        break;

    default://--------------------------------------------------
        return ER_type_bad;
        break;
    }


    //==========================================================  accumulate/uniform
    //qDebug() << "accumulate/uniform";
    if(accum)
        for(unsigned int v = 1; v < v_hist->size(); v++)
            (*v_hist)[v] += (*v_hist)[v - 1];

    if(uniform)
        for(unsigned int v = 0; v < v_hist->size(); v++)
            (*v_hist)[v] /= (double)area;


    //qDebug() << "hist success";
    return ER_okay;
}

int D_Img_Proc::Calc_LUT(vector<int> *vLUT, Mat *pMA_Label)
{
    if(pMA_Label->empty())                                                  return ER_empty;
    if((pMA_Label->type() != CV_8UC1) && (pMA_Label->type() != CV_16UC1))   return ER_type_bad;

    //error handling
    int ER;

    //calc hist (labels)
    vector<vector<double>> vv_hist;
    ER = Calc_Hist(
                &vv_hist,
                pMA_Label,
                false,
                false);
    if(ER != ER_okay)
        return ER;

    //write LUT
    vLUT->clear();                                          //clear LUT
    for(int l = 0; l < vv_hist[0].size(); l++)              //loop possible labels
        if(vv_hist[0][l] > 0)                               //label exits?
            vLUT->push_back(l);                             //add label value, so it can be read by known index

    return ER_okay;
}

int D_Img_Proc::Split_img2vv_value(vector<vector<double> > *vv_data_LabPix, Mat *pMA_Value, Mat *pMA_Label, bool ignore_0)
{
    qDebug() << "Value" << Type_of_Mat(pMA_Value);
    qDebug() << "Label" << Type_of_Mat(pMA_Label);

    if(pMA_Label->empty() || pMA_Value->empty())                                                                return ER_empty;
    if(pMA_Value->channels() != 1)                                                                              return ER_channel_bad;
    if((pMA_Label->type() != CV_16UC1) && (pMA_Label->type() != CV_32SC1))                                      return ER_type_bad;
    if(pMA_Label->size() != pMA_Value->size())                                                                  return ER_size_missmatch;
    qDebug() << "Split_img2vv-------------------------------";

    //values
    unsigned int width = pMA_Label->cols;
    unsigned int height = pMA_Label->rows;
    unsigned int area = width * height;

    //error handler
    int ER;

    //calc hist (labels)
    //qDebug() << "calc hist (labels)";
    vector<vector<double>> vv_hist;
    ER = Calc_Hist(
                &vv_hist,
                pMA_Label,
                false,
                false);
    if(ER != ER_okay)
        return ER;

    //count labels
    //qDebug() << "count labels";
    unsigned int label_count = 0;
    while(vv_hist[0][label_count] > 0)
        label_count++;

    if(label_count < 1)
        return ER_empty;

    //allocate memory for output
    //qDebug() << "allocate memory for output";
    vv_data_LabPix->resize(label_count);

    //loop image and export data

    //switch label type
    switch (pMA_Label->type()) {

    case CV_16UC1://============================================================
    {
        switch (pMA_Value->type()) {

        case CV_8UC1://--------------------------------------------------------
        {
            //qDebug() << "loop image and export data";
            uchar* ptr_Val  = reinterpret_cast<uchar*>(pMA_Value->data);         //
            ushort* ptr_Lab = reinterpret_cast<ushort*>(pMA_Label->data);       //cast to read as 16bit
            for (unsigned int px = 0; px < area; px++, ptr_Val++, ptr_Lab++)    //loop pixels
            {
                uchar   val = *ptr_Val;                                         //read value
                ushort  index_l = *ptr_Lab;                                     //get assigned label
                if(index_l > 0)                                                 //ignore backgound
                    if(!(ignore_0 && (val == 0)))                               //ignore zeros if wanted
                        (*vv_data_LabPix)[index_l].push_back(static_cast<double>(val));              //export value to vector
            }
        }
            break;

        case CV_8SC1://--------------------------------------------------------
        {
            //qDebug() << "loop image and export data";
            char* ptr_Val   = reinterpret_cast<char*>(pMA_Value->data);         //
            ushort* ptr_Lab = reinterpret_cast<ushort*>(pMA_Label->data);       //cast to read as 16bit
            for (unsigned int px = 0; px < area; px++, ptr_Val++, ptr_Lab++)    //loop pixels
            {
                char    val = *ptr_Val;                                         //read value
                ushort  index_l = *ptr_Lab;                                     //get assigned label
                if(index_l > 0)                                                 //ignore backgound
                    if(!(ignore_0 && (val == 0)))                               //ignore zeros if wanted
                        (*vv_data_LabPix)[index_l].push_back(static_cast<double>(val));              //export value to vector
            }
        }
            break;

        case CV_16UC1://--------------------------------------------------------
        {
            //qDebug() << "loop image and export data";
            ushort* ptr_Val = reinterpret_cast<ushort*>(pMA_Value->data);         //cast to read as 16bit
            ushort* ptr_Lab = reinterpret_cast<ushort*>(pMA_Label->data);       //cast to read as 16bit
            for (unsigned int px = 0; px < area; px++, ptr_Val++, ptr_Lab++)    //loop pixels
            {
                ushort  val = *ptr_Val;                                         //read value
                ushort  index_l = *ptr_Lab;                                     //get assigned label
                if(index_l > 0)                                                 //ignore backgound
                    if(!(ignore_0 && (val == 0)))                               //ignore zeros if wanted
                        (*vv_data_LabPix)[index_l].push_back(static_cast<double>(val));              //export value to vector
            }
        }
            break;

        case CV_16SC1://--------------------------------------------------------
        {
            //qDebug() << "loop image and export data";
            int*    ptr_Val = reinterpret_cast<int*>(pMA_Value->data);         //
            ushort* ptr_Lab = reinterpret_cast<ushort*>(pMA_Label->data);       //cast to read as 16bit
            for (unsigned int px = 0; px < area; px++, ptr_Val++, ptr_Lab++)    //loop pixels
            {
                int     val = *ptr_Val;                                         //read value
                ushort  index_l = *ptr_Lab;                                     //get assigned label
                if(index_l > 0)                                                 //ignore backgound
                    if(!(ignore_0 && (val == 0)))                               //ignore zeros if wanted
                        (*vv_data_LabPix)[index_l].push_back(static_cast<double>(val));              //export value to vector
            }
        }
            break;

        case CV_32FC1://--------------------------------------------------------
        {
            //qDebug() << "loop image and export data";
            float* ptr_Val = reinterpret_cast<float*>(pMA_Value->data);         //cast to read as float
            ushort* ptr_Lab = reinterpret_cast<ushort*>(pMA_Label->data);       //cast to read as 16bit
            for (unsigned int px = 0; px < area; px++, ptr_Val++, ptr_Lab++)    //loop pixels
            {
                float   val = *ptr_Val;                                         //read value
                ushort  index_l = *ptr_Lab;                                     //get assigned label
                if(index_l > 0)                                                 //ignore backgound
                    if(!(ignore_0 && (val == 0)))                               //ignore zeros if wanted
                        (*vv_data_LabPix)[index_l].push_back(val);              //export value to vector
            }
        }
            break;

        case CV_64FC1://--------------------------------------------------------
        {
            //qDebug() << "loop image and export data";
            double* ptr_Val = reinterpret_cast<double*>(pMA_Value->data);       //cast to read as double
            ushort* ptr_Lab = reinterpret_cast<ushort*>(pMA_Label->data);       //cast to read as 16bit
            for (unsigned int px = 0; px < area; px++, ptr_Val++, ptr_Lab++)    //loop pixels
            {
                double   val = *ptr_Val;                                        //read value
                ushort  index_l = *ptr_Lab;                                     //get assigned label
                if(index_l > 0)                                                 //ignore backgound
                    if(!(ignore_0 && (val == 0)))                               //ignore zeros if wanted
                        (*vv_data_LabPix)[index_l].push_back(val);              //export value to vector
            }
        }
            break;

        default://--------------------------------------------------------------
            qDebug() << "Split_img2vv_value failed - CV_16UC1_Label: Value Type not supported.";
            return ER_bitdepth_bad;
        }
    }
        break;

    case CV_32SC1://========================================================================================================================================
    {
        switch (pMA_Value->type()) {

        case CV_8UC1://--------------------------------------------------------
        {
            //qDebug() << "loop image and export data";
            uchar* ptr_Val = reinterpret_cast<uchar*>(pMA_Value->data);                 //
            int* ptr_Lab = reinterpret_cast<int*>(pMA_Label->data);                     //cast to read as 16bit
            for (unsigned int px = 0; px < area; px++, ptr_Val++, ptr_Lab++)            //loop pixels
            {
                uchar   val = *ptr_Val;                                                 //read value
                int  index_l = *ptr_Lab;                                                //get assigned label
                if(index_l > 0)                                                         //ignore backgound
                    if(!(ignore_0 && (val == 0)))                                       //ignore zeros if wanted
                        (*vv_data_LabPix)[index_l].push_back(static_cast<double>(val)); //export value to vector
            }
        }
            break;

        case CV_8SC1://--------------------------------------------------------
        {
            //qDebug() << "loop image and export data";
            char* ptr_Val = reinterpret_cast<char*>(pMA_Value->data);                   //
            int* ptr_Lab = reinterpret_cast<int*>(pMA_Label->data);                     //cast to read as 16bit
            for (unsigned int px = 0; px < area; px++, ptr_Val++, ptr_Lab++)            //loop pixels
            {
                char   val = *ptr_Val;                                                  //read value
                int  index_l = *ptr_Lab;                                                //get assigned label
                if(index_l > 0)                                                         //ignore backgound
                    if(!(ignore_0 && (val == 0)))                                       //ignore zeros if wanted
                        (*vv_data_LabPix)[index_l].push_back(static_cast<double>(val)); //export value to vector
            }
        }
            break;

        case CV_16UC1://--------------------------------------------------------
        {
            //qDebug() << "loop image and export data";
            ushort* ptr_Val = reinterpret_cast<ushort*>(pMA_Value->data);         //cast to read as 16bit
            int* ptr_Lab = reinterpret_cast<int*>(pMA_Label->data);       //cast to read as 16bit
            for (unsigned int px = 0; px < area; px++, ptr_Val++, ptr_Lab++)    //loop pixels
            {
                ushort   val = *ptr_Val;                                         //read value
                int  index_l = *ptr_Lab;                                     //get assigned label
                if(index_l > 0)                                                 //ignore backgound
                    if(!(ignore_0 && (val == 0)))                               //ignore zeros if wanted
                        (*vv_data_LabPix)[index_l].push_back(static_cast<double>(val));              //export value to vector
            }
        }
            break;

        case CV_16SC1://--------------------------------------------------------
        {
            //qDebug() << "loop image and export data";
            int* ptr_Val = reinterpret_cast<int*>(pMA_Value->data);                     //
            int* ptr_Lab = reinterpret_cast<int*>(pMA_Label->data);                     //cast to read as 16bit
            for (unsigned int px = 0; px < area; px++, ptr_Val++, ptr_Lab++)            //loop pixels
            {
                int  val = *ptr_Val;                                                    //read value
                int  index_l = *ptr_Lab;                                                //get assigned label
                if(index_l > 0)                                                         //ignore backgound
                    if(!(ignore_0 && (val == 0)))                                       //ignore zeros if wanted
                        (*vv_data_LabPix)[index_l].push_back(static_cast<double>(val)); //export value to vector
            }
        }
            break;

        case CV_32FC1://--------------------------------------------------------
        {
            //qDebug() << "loop image and export data";
            float* ptr_Val = reinterpret_cast<float*>(pMA_Value->data);         //cast to read as float
            int* ptr_Lab = reinterpret_cast<int*>(pMA_Label->data);             //cast to read as 32bit
            for (unsigned int px = 0; px < area; px++, ptr_Val++, ptr_Lab++)    //loop pixels
            {
                float   val = *ptr_Val;                                         //read value
                int index_l = *ptr_Lab;                                         //get assigned label
                if(index_l > 0)                                                 //ignore backgound
                    if(!(ignore_0 && (val == 0)))                               //ignore zeros if wanted
                        (*vv_data_LabPix)[index_l].push_back(val);              //export value to vector
            }
        }
            break;

        case CV_64FC1://--------------------------------------------------------
        {
            qDebug() << "loop image and export data";
            double* ptr_Val = reinterpret_cast<double*>(pMA_Value->data);       //cast to read as double
            int* ptr_Lab = reinterpret_cast<int*>(pMA_Label->data);             //cast to read as 32bit
            for (unsigned int px = 0; px < area; px++, ptr_Val++, ptr_Lab++)    //loop pixels
            {
                double   val = *ptr_Val;                                        //read value
                int  index_l = *ptr_Lab;                                        //get assigned label
                if(index_l > 0)                                                 //ignore backgound
                    if(!(ignore_0 && (val == 0)))                               //ignore zeros if wanted
                        (*vv_data_LabPix)[index_l].push_back(val);              //export value to vector
            }
        }
            break;

        default://--------------------------------------------------------------
            qDebug() << "Split_img2vv_value failed - CV_32SC1_Label: Value Type not supported.";
            return ER_bitdepth_bad;
        }
    }
        break;

    default://==================================================================
        qDebug() << "Split_img2vv_value failed - Label Type not supported.";
        return ER_bitdepth_bad;
    }





    //dirty way of removing the 1st element. i cant find why it is there
    vv_data_LabPix->erase(vv_data_LabPix->begin());

    qDebug() << "============================================ sucess (Split_img2vv)";
    return ER_okay;
}

int D_Img_Proc::Split_img2vv_coord(vector<vector<Point> > *vvp_data_LabCooPt, Mat *pMA_Label)
{
    if(pMA_Label->empty())                                              return ER_empty;
    if(pMA_Label->type() != CV_16UC1 && pMA_Label->type() != CV_32SC1)  return ER_type_bad;

    //error handler
    int ER;

    //values
    int width = pMA_Label->cols;
    int heigth = pMA_Label->rows;
    double min, max;
    ER = MinMax_of_Mat(
                pMA_Label,
                &min,
                &max);

    //qDebug() << "Split_img2vv_coord" << "labels detetced:" << max;

    //allocate memory for output
    vvp_data_LabCooPt->clear();
    vvp_data_LabCooPt->resize(static_cast<size_t>(max));

    //loop image and get coords
    if(pMA_Label->type() == CV_16UC1)
    {
        for(int y = 0; y < heigth; y++)
        {
            for(int x = 0; x < width; x++)
            {
                ushort val = pMA_Label->at<ushort>(y, x);

                if(val > 0)
                {
                    (*vvp_data_LabCooPt)[val - 1].push_back(Point(x, y));
                }
            }
        }
    }
    else//CV_32SC1
    {
        for(int y = 0; y < heigth; y++)
        {
            for(int x = 0; x < width; x++)
            {
                int val = pMA_Label->at<int>(y, x);

                if(val > 0)
                {
                    (*vvp_data_LabCooPt)[val - 1].push_back(Point(x, y));
                }
            }
        }
    }

    return ER_okay;
}

int D_Img_Proc::Split_img2components(D_Component_List *pCompList, Mat *pMA_In, int connectivity)
{
    if(pMA_In->empty())                                                                             return ER_empty;
    if(pMA_In->channels() != 1)                                                                     return ER_channel_bad;
    if((pMA_In->depth() != CV_8U) && (pMA_In->depth() != CV_32S) && (pMA_In->depth() != CV_16U))    return ER_bitdepth_bad;
    if(connectivity != 4 && connectivity != 8)                                                      return ER_parameter_bad;

    return pCompList->set_Mat(pMA_In, connectivity);
}

int D_Img_Proc::Split_ObjectAreas(vector<double> *v_objects, vector<double> *v_areas, Mat *pMA_Label, Mat *pMA_Objects, int connectivity)
{
    //qDebug() << "Split_ObjectAreas";
    if(pMA_Label->empty() || pMA_Objects->empty())                      return ER_empty;
    if(pMA_Label->channels() > 1 || pMA_Objects->channels() > 1)        return ER_channel_bad;
    if(pMA_Label->depth() != CV_16U && pMA_Label->depth() != CV_32S)    return ER_bitdepth_bad;
    if(pMA_Objects->depth() != CV_8U)                                   return ER_bitdepth_bad;
    if(pMA_Label->size() != pMA_Objects->size())                        return ER_size_missmatch;
    if(connectivity != 4 && connectivity != 8)                          return ER_parameter_bad;

    //Error handler
    int ER;

    //dimensions
    int area = pMA_Label->cols * pMA_Label->rows;
    //qDebug() << "Area:" << area;

    //range
    double min, max;
    ER = MinMax_of_Mat(
                pMA_Label,
                &min,
                &max);
    //qDebug() << "range:" << min << "to" << max;
    if(ER != ER_okay)   return ER;

    //resize
    //qDebug() << "Number of components:" << max;
    v_objects->clear();
    v_objects->resize(static_cast<int>(max), 0);
    v_areas->clear();
    v_areas->resize(static_cast<int>(max), 0);

    //centroid image
    Mat MA_tmp_Centroids;
    ER = Reduce_Geometric(
                &MA_tmp_Centroids,
                pMA_Objects,
                c_GEO_CENTROID,
                connectivity,
                1,
                255);
    if(ER != ER_okay)   return ER;

    //loop
    switch (pMA_Label->type()) {

    case CV_16UC1:
    {
        //qDebug() << "Label image of type CV_16UC1";
        ushort *ptr_lab = reinterpret_cast<ushort*>(pMA_Label->data);
        uchar *ptr_obj = reinterpret_cast<uchar*>(pMA_Objects->data);
        uchar *ptr_cen = reinterpret_cast<uchar*>(MA_tmp_Centroids.data);
        for(int px = 0; px < area; px++, ptr_lab++, ptr_obj++, ptr_cen++)
        {
            if(*ptr_cen > 0 && *ptr_lab > 0)
            {
                //qDebug() << "Found centroid @px" << px << "in type CV_16UC1";
                (*v_objects)[*ptr_lab - 1] = (*v_objects)[*ptr_lab - 1] + 1;
            }

            if(*ptr_obj > 0 && *ptr_lab > 0)
            {
                //qDebug() << "Found something @px" << px << "in type CV_16UC1";
                (*v_areas)[*ptr_lab - 1] = (*v_areas)[*ptr_lab - 1] + 1;
            }
        }
    }
        break;

    case CV_32SC1:
    {
        //qDebug() << "Label image of type CV_32SC1";
        int *ptr_lab = reinterpret_cast<int*>(pMA_Label->data);
        uchar *ptr_obj = reinterpret_cast<uchar*>(pMA_Objects->data);
        uchar *ptr_cen = reinterpret_cast<uchar*>(MA_tmp_Centroids.data);
        for(int px = 0; px < area; px++, ptr_lab++, ptr_obj++, ptr_cen++)
        {
            if(*ptr_cen > 0 && *ptr_lab > 0)
            {
                //qDebug() << "Found centroid @px" << px << "in type CV_32SC1";
                (*v_objects)[*ptr_lab - 1] = (*v_objects)[*ptr_lab - 1] + 1;
            }

            if(*ptr_obj > 0 && *ptr_lab > 0)
            {
                //qDebug() << "Found something @px" << px << "in type CV_32SC1";
                (*v_areas)[*ptr_lab - 1] = (*v_areas)[*ptr_lab - 1] + 1;
            }
        }
    }
        break;

    default:
        return ER_type_bad;

    }

    MA_tmp_Centroids.release();
    return ER_okay;
}


int D_Img_Proc::LUT_Apply_to_Label_Int(Mat *pMA_Out, Mat *pMA_Label, vector<int> vLUT)
{
    if(pMA_Label->empty())              return ER_empty;
    if(pMA_Label->channels() != 1)      return ER_channel_bad;
    if(pMA_Label->depth() != CV_16U)    return ER_bitdepth_bad;

    //Check, if sizes match
    double min, max;
    int ER = MinMax_of_Mat(
                pMA_Label,
                &min,
                &max);
    if(ER != ER_okay)           return ER;
    if(max + 1 != vLUT.size())  return ER_size_missmatch;

    //apply LUT
    int px_max = pMA_Label->cols * pMA_Label->rows;                     //number of pixels to loop
    *pMA_Out = Mat(pMA_Label->size(), CV_8UC1);                         //define output image
    ushort* ptr_lab = reinterpret_cast<ushort*>(pMA_Label->data);       //pointer to label image data
    uchar*  ptr_out = reinterpret_cast<uchar* >(pMA_Out->data);         //pointer to output image data
    for (int px = 0; px < px_max; px++, ptr_lab++, ptr_out++)           //loop pixels and pointers
        *ptr_out = vLUT[*ptr_lab];

    return ER_okay;
}

int D_Img_Proc::LUT_Apply_to_Label_Double(Mat *pMA_Out, Mat *pMA_Label, vector<double> vLUT)
{
    if(pMA_Label->empty())                                                  return ER_empty;
    if(pMA_Label->channels() != 1)                                          return ER_channel_bad;
    if((pMA_Label->depth() != CV_16U) && (pMA_Label->depth() != CV_32S))    return ER_bitdepth_bad;

    //Check, if sizes match
    double min, max;
    int ER = MinMax_of_Mat(
                pMA_Label,
                &min,
                &max);
    if(ER != ER_okay)           return ER;
    if(max + 1 != vLUT.size())  return ER_size_missmatch;

    //apply LUT
    int px_max = pMA_Label->cols * pMA_Label->rows;                         //number of pixels to loop
    *pMA_Out = Mat(pMA_Label->size(), CV_64FC1);                            //define output image
    double* ptr_out = reinterpret_cast<double*>(pMA_Out->data);             //pointer to output image data

    switch (pMA_Label->type()) {

    case CV_16UC1:
    {
        ushort* ptr_lab = reinterpret_cast<ushort*>(pMA_Label->data);       //pointer to label image data
        for (int px = 0; px < px_max; px++, ptr_lab++, ptr_out++)           //loop pixels and pointers
            *ptr_out = vLUT[*ptr_lab];
    }
        break;

    case CV_32SC1:
    {
        int* ptr_lab = reinterpret_cast<int*>(pMA_Label->data);             //pointer to label image data
        for (int px = 0; px < px_max; px++, ptr_lab++, ptr_out++)           //loop pixels and pointers
            *ptr_out = vLUT[*ptr_lab];
    }
        break;

    default:
        return ER_type_bad;
    }

    return ER_okay;
}

int D_Img_Proc::LUT_Apply_to_Label_Binary(Mat *pMA_Out, Mat *pMA_Label, vector<int> vLUT, bool ignore_BG)
{
    //qDebug() << "LUT_Apply_to_Label_Binary - Start";
    if(pMA_Label->empty())                                                  return ER_empty;
    if(pMA_Label->channels() != 1)                                          return ER_channel_bad;
    if((pMA_Label->depth() != CV_16U) && (pMA_Label->depth() != CV_32S))    return ER_bitdepth_bad;

    //Check, if sizes match
    //qDebug() << "LUT_Apply_to_Label_Binary - Check Sizes";
    double min, max;
    int ER = MinMax_of_Mat(
                pMA_Label,
                &min,
                &max);
    //qDebug() << "max" << max << "lut_size" << vLUT.size();
    if(ER != ER_okay)           return ER;
    if(max + 1 != vLUT.size())  return ER_size_missmatch;   //+1 because background is value/label 0 but not index 0, index 0 is value/label 1

    //get size
    int width = pMA_Label->cols;
    int height = pMA_Label->rows;
    int area = width * height;
    //qDebug() << "size" << width << height << area;

    //apply LUT
    //qDebug() << "LUT_Apply_to_Label_Binary - Apply LUT";
    *pMA_Out = Mat::zeros(pMA_Label->size(), CV_8UC1);                      //init output
    uchar* ptr_out = reinterpret_cast<uchar*>(pMA_Out->data);               //pointer to output image data

    switch (pMA_Label->type()) {

    case CV_16UC1:
    {
        ushort* ptr_lab = reinterpret_cast<ushort*>(pMA_Label->data);       //pointer to label image data
        for (int px = 0; px < area; px++, ptr_lab++, ptr_out++)             //loop pixels and pointers
        {
            ushort label = *ptr_lab;
                if(vLUT[label])                                             //if LUT is true for label
                    if(!((label == 0) && ignore_BG))                        //ignore background if wanted
                        *ptr_out = 255;                                     //255/true
        }
    }
        break;

    case CV_32SC1:
    {
        int* ptr_lab = reinterpret_cast<int*>(pMA_Label->data);             //pointer to label image data
        for (int px = 0; px < area; px++, ptr_lab++, ptr_out++)             //loop pixels and pointers
        {
            int label = *ptr_lab;
                if(vLUT[label])                                             //if LUT is true for label
                    if(!((label == 0) && ignore_BG))                        //ignore background if wanted
                        *ptr_out = 255;                                     //255/true
        }
    }
        break;

    default:
        return ER_type_bad;
    }

    //imshow("LUT apply", *pMA_Out);
    //qDebug() << "LUT_Apply_to_Label_Binary - Success";
    return ER_okay;
}

int D_Img_Proc::LUT_Apply_to_Label_TrueFalse(Mat *pMA_Out_true, Mat *pMA_Out_false, Mat *pMA_Label, vector<int> vLUT, bool edges, bool ignore_BG)
{
    //qDebug() << "LUT_Apply_to_Label_GreenRed - Start";
    if(pMA_Label->empty())              return ER_empty;
    if(pMA_Label->channels() != 1)      return ER_channel_bad;
    if(pMA_Label->depth() != CV_16U)    return ER_bitdepth_bad;

    int ER;

    //true
    //qDebug() << "LUT_Apply_to_Label_GreenRed - true image";
    ER = LUT_Apply_to_Label_Binary(
                pMA_Out_true,
                pMA_Label,
                vLUT,
                ignore_BG);
    if(ER != ER_okay)                   return ER;
    //imshow("true", *pMA_Out_true);

    //invert LUT
    //qDebug() << "LUT_Apply_to_Label_GreenRed - invert image";
    for(int i = 0; i < vLUT.size(); i++)
        vLUT[i] = !(vLUT[i]);

    //false
    //qDebug() << "LUT_Apply_to_Label_GreenRed - false image";
    ER = LUT_Apply_to_Label_Binary(
                pMA_Out_false,
                pMA_Label,
                vLUT,
                ignore_BG);
    if(ER != ER_okay)                   return ER;
    //imshow("false", *pMA_Out_false);

    //edges
    //qDebug() << "LUT_Apply_to_Label_GreenRed - edges";
    if(edges)
    {
        ER = Reduce_Contours(
                    pMA_Out_true,
                    pMA_Out_true);
        if(ER != ER_okay)                   return ER;

        ER = Reduce_Contours(
                    pMA_Out_false,
                    pMA_Out_false);
        if(ER != ER_okay)                   return ER;
    }

    //qDebug() << "LUT_Apply_to_Label_GreenRed - Success";
    return ER_okay;
}

int D_Img_Proc::LUT_Apply_to_Label_Color(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Label, vector<int> vLUT, int channel_true, int channel_false, bool edges, bool ignore_BG)
{
    //qDebug() << "LUT_Apply_to_Label_TrueFalse - Start";
    if(pMA_Label->empty())                                          return ER_empty;
    if(pMA_Label->channels() != 1)                                  return ER_channel_bad;
    if(pMA_Label->depth() != CV_16U)                                return ER_bitdepth_bad;
    if(pMA_In->size != pMA_Label->size)                             return ER_size_missmatch;
    if((pMA_In->type() != CV_8UC1) && (pMA_In->type() != CV_8UC3))  return ER_channel_bad;
    if((channel_true > 3) || (channel_false > 3))                   return ER_parameter_bad;

    int ER;


    //get true/false images
    //qDebug() << "LUT_Apply_to_Label_TrueFalse - get true/false images";
    Mat MA_true;
    Mat MA_false;
    ER = LUT_Apply_to_Label_TrueFalse(
                &MA_true,
                &MA_false,
                pMA_Label,
                vLUT,
                edges,
                ignore_BG);
    if(ER != ER_okay)   return ER;


    //split images
    //qDebug() << "LUT_Apply_to_Label_TrueFalse - Split";
    Mat arrMA_split[3];
    split(*pMA_In, arrMA_split);


    //make areas/edges black to be abled to color it in the next step
    //qDebug() << "LUT_Apply_to_Label_TrueFalse - black";
    for(int c = 0; c < 3; c++)
    {
        ER = Math_ImgImg_Diff(
                    &(arrMA_split[c]),
                    &(arrMA_split[c]),
                    &MA_true);
        if(ER != ER_okay)   return ER;

        ER = Math_ImgImg_Diff(
                    &(arrMA_split[c]),
                    &(arrMA_split[c]),
                    &MA_false);
        if(ER != ER_okay)   return ER;
    }


    //adding the true/false images in the wanted channel
    ER = Math_ImgImg_Add(
                &(arrMA_split[channel_false]),
                &(arrMA_split[channel_false]),
                &MA_false);
    if(ER != ER_okay)   return ER;

    ER = Math_ImgImg_Add(
                &(arrMA_split[channel_true]),
                &(arrMA_split[channel_true]),
                &MA_true);
    if(ER != ER_okay)   return ER;


    //merge channels again (to output)
    //qDebug() << "LUT_Apply_to_Label_TrueFalse - Merge";
    merge(
                arrMA_split,
                3,
                *pMA_Out);

    //imshow("merged", *pMA_Out);
    //qDebug() << "LUT_Apply_to_Label_TrueFalse - Succsess";
    MA_true.release();
    MA_false.release();
    return ER_okay;
}

int D_Img_Proc::Feature_Value(Mat *pMA_Out, Mat *pMA_In, int feature, int connectivity)
{
    if(pMA_In->empty())                                                                             return ER_empty;
    if(pMA_In->channels() != 1)                                                                     return ER_channel_bad;
    if((pMA_In->depth() != CV_8U) && (pMA_In->depth() != CV_32S) && (pMA_In->depth() != CV_16U))    return ER_bitdepth_bad;
    if(feature >= c_FEAT_NUMBER_OF_FEATS || feature < 0)                                            return ER_parameter_bad;
    if(connectivity != 4 && connectivity != 8)                                                      return ER_parameter_bad;

    //qDebug() << "Feature_Index:" << feature << "Feature_Name:" << QSL_FeatureList[feature];

    int ER;

    //split
    D_Component_List CompList;
    ER = CompList.set_Mat(pMA_In, connectivity);
    if(ER != ER_okay)   return ER;

    //save in file for debugging
    //CompList.save_all("D:/David_Eilenstein/ImageD/StepsStream/feature_test");

    //get Features
    vector<double> v_Features = CompList.get_FeatureVector_BG(feature);

    //write features as values
    ER = LUT_Apply_to_Label_Double(
                pMA_Out,
                CompList.get_pMatLabels(),
                v_Features);
    if(ER != ER_okay)   return ER;

    return ER_okay;
}

int D_Img_Proc::FeatureContext_Value(Mat *pMA_Out, Mat *pMA_In, int pt_type1, int pt_type2, double dist_min, double dist_max, int feat, int stat, int connectivity)
{
    //checks
    if(pMA_In->empty())                                                                             return ER_empty;
    if(pMA_In->channels() != 1)                                                                     return ER_channel_bad;
    if((pMA_In->depth() != CV_8U) && (pMA_In->depth() != CV_32S) && (pMA_In->depth() != CV_16U))    return ER_bitdepth_bad;
    if(feat >= c_FEAT_NUMBER_OF_FEATS || feat < 0)                                                  return ER_parameter_bad;
    if(stat >= c_STAT_NUMBER_OF_STATS || stat < 0)                                                  return ER_parameter_bad;
    if(pt_type1 >= c_COMPDIST_NUMBER_OF || pt_type1 < 0)                                            return ER_parameter_bad;
    if(pt_type2 >= c_COMPDIST_NUMBER_OF || pt_type2 < 0)                                            return ER_parameter_bad;
    if(connectivity != 4 && connectivity != 8)                                                      return ER_parameter_bad;
    int ER;

    //comp context list
    D_Component_List_Context CompListContext;
    ER = CompListContext.set_Mat(pMA_In, connectivity);
    if(ER != ER_okay)   return ER;

    //get Stats of Features in Comps in Dist
    vector<double> v_Values = CompListContext.get_AllComps_StatFeatInDist_BG(pt_type1, pt_type2, dist_min, dist_max, feat, stat);

    //write features as values
    ER = LUT_Apply_to_Label_Double(
                pMA_Out,
                CompListContext.get_pCompList()->get_pMatLabels(),
                v_Values);
    if(ER != ER_okay)   return ER;

    return ER_okay;
}

int D_Img_Proc::Feature_Select(Mat *pMA_Out, Mat *pMA_In, int feature, double f_min, double f_max, int connectivity)
{
    if(pMA_In->empty())                                                                             return ER_empty;
    if(pMA_In->channels() != 1)                                                                     return ER_channel_bad;
    if((pMA_In->depth() != CV_8U) && (pMA_In->depth() != CV_32S) && (pMA_In->depth() != CV_16U))    return ER_bitdepth_bad;
    if(feature >= c_FEAT_NUMBER_OF_FEATS || feature < 0)                                            return ER_parameter_bad;
    if(connectivity != 4 && connectivity != 8)                                                      return ER_parameter_bad;

    /*
    //use faster alternative for area
    if(feature == c_FEAT_AREA)
        return Select_Area(
                    pMA_Out,
                    pMA_In,
                    f_min,
                    f_max,
                    connectivity);
                    */

    int ER;

    //split
    D_Component_List CompList;
    ER = CompList.set_Mat(pMA_In, connectivity);
    if(ER != ER_okay)   return ER;

    //get Features
    vector<double> v_Features = CompList.get_FeatureVector_BG(feature);

    //create LUT
    vector<int> v_LUT;
    v_LUT.resize(v_Features.size(), 0);

    //add false(0) for background
    v_LUT[0] = 0;

    //calc LUT (but not for background -> start at 1 not 0)
    if(f_min <= f_max)
    {
        for(int i = 1; i < v_Features.size(); i++)
            if((f_min <= v_Features[i]) && (v_Features[i] <= f_max))
                v_LUT[i] = 255;
    }
    else    //invert if range is negative
    {
        for(int i = 1; i < v_Features.size(); i++)
            if(!((f_min <= v_Features[i]) && (v_Features[i] <= f_max)))
                v_LUT[i] = 255;
    }

    //apply LUT
    ER = LUT_Apply_to_Label_Binary(
                pMA_Out,
                CompList.get_pMatLabels(),
                v_LUT);
    if(ER != ER_okay)   return ER;

    return ER_okay;
}

int D_Img_Proc::FeatureContext_Select(Mat *pMA_Out, Mat *pMA_In, int pt_type1, int pt_type2, double dist_min, double dist_max, int feat, int stat, double t_min, double t_max, int connectivity)
{
    //checks
    if(pMA_In->empty())                                                                             return ER_empty;
    if(pMA_In->channels() != 1)                                                                     return ER_channel_bad;
    if((pMA_In->depth() != CV_8U) && (pMA_In->depth() != CV_32S) && (pMA_In->depth() != CV_16U))    return ER_bitdepth_bad;
    if(feat >= c_FEAT_NUMBER_OF_FEATS || feat < 0)                                                  return ER_parameter_bad;
    if(stat >= c_STAT_NUMBER_OF_STATS || stat < 0)                                                  return ER_parameter_bad;
    if(pt_type1 >= c_COMPDIST_NUMBER_OF || pt_type1 < 0)                                            return ER_parameter_bad;
    if(pt_type2 >= c_COMPDIST_NUMBER_OF || pt_type2 < 0)                                            return ER_parameter_bad;
    if(connectivity != 4 && connectivity != 8)                                                      return ER_parameter_bad;
    int ER;

    //comp context list
    D_Component_List_Context CompListContext;
    ER = CompListContext.set_Mat(pMA_In, connectivity);
    if(ER != ER_okay)   return ER;

    //get Stats of Features in Comps in Dist
    vector<double> v_Values = CompListContext.get_AllComps_StatFeatInDist_BG(pt_type1, pt_type2, dist_min, dist_max, feat, stat);

    //create LUT
    vector<int> v_LUT;
    v_LUT.resize(v_Values.size(), 0);

    //add false(0) for background
    v_LUT[0] = 0;

    //calc LUT (but not for background -> start at 1 not 0)
    if(t_min <= t_max)
    {
        for(int i = 1; i < v_Values.size(); i++)
            if((t_min <= v_Values[i]) && (v_Values[i] <= t_max))
                v_LUT[i] = 255;
    }
    else    //invert if range is negative
    {
        for(int i = 1; i < v_Values.size(); i++)
            if(!((t_min <= v_Values[i]) && (v_Values[i] <= t_max)))
                v_LUT[i] = 255;
    }

    //write features as values
    ER = LUT_Apply_to_Label_Binary(
                pMA_Out,
                CompListContext.get_pCompList()->get_pMatLabels(),
                v_LUT);
    if(ER != ER_okay)   return ER;

    return ER_okay;
}

int D_Img_Proc::Feature_Visualize(Mat *pMA_Out, Mat *pMA_In, int feature, int connectivity, int thickness, double scale)
{
    if(pMA_In->empty())                                                                             return ER_empty;
    if(pMA_In->channels() != 1)                                                                     return ER_channel_bad;
    if((pMA_In->depth() != CV_8U) && (pMA_In->depth() != CV_32S) && (pMA_In->depth() != CV_16U))    return ER_bitdepth_bad;
    if(feature >= c_FEAT_NUMBER_OF_FEATS || feature < 0)                                            return ER_parameter_bad;
    if(connectivity != 4 && connectivity != 8)                                                      return ER_parameter_bad;

    int ER;

    //calc componet list
    D_Component_List CompList;
    ER = CompList.set_Mat(pMA_In, connectivity);
    if(ER != ER_okay)   return ER;

    //get Features
    vector<double> v_Features = CompList.get_FeatureVector_BG(feature);

    //===================== Features

    //write features as values
    Mat MA_tmp_feature;
    ER = LUT_Apply_to_Label_Double(
                &MA_tmp_feature,
                CompList.get_pMatLabels(),
                v_Features);
    if(ER != ER_okay)   return ER;

    double min, max;
    minMaxLoc(
                MA_tmp_feature,
                &min,
                &max);

    //convert to 8bit
    ER = Normalize(
                &MA_tmp_feature,
                &MA_tmp_feature,
                CV_MINMAX,
                CV_8U,
                0,
                255);
    if(ER != ER_okay)   return ER;

    //===================== Edges

    //outlines
    Mat MA_tmp_edges = CompList.get_MatBinary();
    ER = Reduce_Outlines(
                &MA_tmp_edges,
                &MA_tmp_edges,
                connectivity,
                1);
    if(ER != ER_okay)   return ER;

    //===================== Merge

    //merge
    Mat MA_tmp_black = Mat::zeros(pMA_In->size(), CV_8UC1);
    ER = Merge(
                pMA_Out,
                &MA_tmp_black,
                &MA_tmp_edges,
                &MA_tmp_feature);
    if(ER != ER_okay)   return ER;

    //===================== text

    //text

    putText(
                *pMA_Out,
                QString(
                    QSL_FeatureList[feature] + " -" +
                    " min: " + QString::number(min, 'g', 3) +
                    " max: " + QString::number(max, 'g', 3)).toStdString(),
                Point(
                    pMA_Out->cols * 0.02,
                    pMA_Out->rows * 0.98),
                FONT_HERSHEY_COMPLEX_SMALL,
                scale,
                Scalar(255, 255, 255),
                thickness,
                CV_AA);

    MA_tmp_black.release();
    MA_tmp_edges.release();
    MA_tmp_feature.release();
    return ER_okay;
}

int D_Img_Proc::Feature_Connect(Mat *pMA_Out, Mat *pMA_In, int pt_type1, int pt_type2, double dist_min, double dist_max, int feat1, int feat2, function<bool (double, double)> comp, int connect_mode, int connectivity, int thickness)
{
    //checks
    if(pMA_In->empty())                                                                             return ER_empty;
    if(pMA_In->channels() != 1)                                                                     return ER_channel_bad;
    if((pMA_In->depth() != CV_8U) && (pMA_In->depth() != CV_32S) && (pMA_In->depth() != CV_16U))    return ER_bitdepth_bad;
    if(feat1 >= c_FEAT_NUMBER_OF_FEATS || feat1 < 0)                                                return ER_parameter_bad;
    if(feat2 >= c_FEAT_NUMBER_OF_FEATS || feat2 < 0)                                                return ER_parameter_bad;
    if(pt_type1 >= c_COMPDIST_NUMBER_OF || pt_type1 < 0)                                            return ER_parameter_bad;
    if(pt_type2 >= c_COMPDIST_NUMBER_OF || pt_type2 < 0)                                            return ER_parameter_bad;
    if(connect_mode >= c_CONNECT_NUMBER_OF || connect_mode < 0)                                     return ER_parameter_bad;
    if(connectivity != 4 && connectivity != 8)                                                      return ER_parameter_bad;
    int ER;

    //comp context list
    D_Component_List_Context CompListContext;
    ER = CompListContext.set_Mat(pMA_In, connectivity);
    if(ER != ER_okay)   return ER;

    //get points to connect
    vector<vector<Point>> vvPointCouples;

    switch (connect_mode) {

    case c_CONNECT_CLOSEST:
        vvPointCouples  = CompListContext.get_PointCouples_Closest(
                    pt_type1,
                    pt_type2,
                    dist_min,
                    dist_max,
                    feat1,
                    feat2,
                    comp);
        break;

    case c_CONNECT_IN_RANGE:
        vvPointCouples  = CompListContext.get_PointCouples_AllInRange(
                    pt_type1,
                    pt_type2,
                    dist_min,
                    dist_max,
                    feat1,
                    feat2,
                    comp);
        break;

    default:
        return ER_parameter_bad;
    }

    //init out
    *pMA_Out = CompListContext.get_pCompList()->get_pMatBinary()->clone();

    //draw line between point couples
    for(int pc = 0; pc < vvPointCouples.size(); pc++)
        line(
                    *pMA_Out,
                    vvPointCouples[pc][0],
                    vvPointCouples[pc][1],
                    Scalar(255),
                    thickness,
                    8);

    //end :-)
    return ER_okay;
}

int D_Img_Proc::Detect_CornerHarris(Mat *pMA_Out, Mat *pMA_In, int blockSize, int sobelAperture, double harrisParam, double thres)
{
    D_FeatureSet FeatSet;
    int ER = FeatSet.detect_Harris(
                pMA_In,
                blockSize,
                sobelAperture,
                harrisParam,
                thres);
    if(ER != ER_okay)
        return ER;

    //WIP
    return ER_okay;
}

int D_Img_Proc::Select_Area(Mat *pMA_Out, Mat *pMA_In, unsigned int area_min, unsigned int area_max, int connectivity)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->channels() != 1)     return ER_channel_bad;

    //error handling
    int ER;

    //label
    Mat MA_Label;
    ER = Labeling(
                &MA_Label,
                pMA_In,
                connectivity,
                CV_16U);
    if(ER != ER_okay)
        return ER;

    //calc hist (area of labels)
    vector<vector<double>> vv_hist;
    ER = Calc_Hist(
                &vv_hist,
                &MA_Label,
                false,
                false);
    if(ER != ER_okay)
        return ER;

    //binarize hist (select from area)
    for(unsigned int l = 0; l < vv_hist[0].size(); l++)
        if(vv_hist[0][l] >= area_min && vv_hist[0][l] <= area_max)
            vv_hist[0][l] = 255;
        else
            vv_hist[0][l] = 0;

    //use hist as LUT to eliminate labels with not wanted area
    unsigned int px_max = pMA_In->cols * pMA_In->rows;                  //number of pixels to loop
    *pMA_Out = Mat(pMA_In->size(), CV_8UC1);                            //define output image
    ushort* ptr_lab = reinterpret_cast<ushort*>(MA_Label.data);         //pointer to label image data
    uchar*  ptr_out = reinterpret_cast<uchar* >(pMA_Out->data);         //pointer to output image data

    for (unsigned int px = 0; px < px_max; px++, ptr_lab++, ptr_out++)  //loop pixels and pointers
        *ptr_out = vv_hist[0][*ptr_lab];                                //use binarized hist as LUT (depending on labels area)

    MA_Label.release();
    return ER_okay;
}

int D_Img_Proc::Reduce_Geometric(Mat *pMA_Out, Mat *pMA_In, int geometric, int connectivity, int thickness, uchar value)
{
    if(pMA_In->empty())                                     return ER_empty;
    if((geometric < 0) || (geometric > c_GEO_NUMBER_OF))    return ER_parameter_bad;
    if((connectivity != 4) && (connectivity != 8))          return ER_parameter_bad;
    if(thickness < 0)                                       return ER_parameter_bad;

    //Error
    int ER;

    //Outlines does not need component list, so it is treated separated
    if(geometric == c_GEO_OUTLINE)
        return Reduce_Outlines(
                    pMA_Out,
                    pMA_In,
                    connectivity,
                    thickness);

    //Components
    D_Component_List CompList;
    ER = CompList.set_Mat(pMA_In, connectivity);
    if(ER != ER_okay)   return ER;

    //allocate/init
    *pMA_Out = Mat::zeros(pMA_In->size(), CV_8UC1);

    //geometric
    switch (geometric) {

    //Points
    case c_GEO_OFFSET:
    case c_GEO_CENTROID:
    {
        vector<double> v_x;
        switch (geometric) {
        case c_GEO_OFFSET:      v_x = CompList.get_FeatureVector(c_FEAT_RECT_AXEPAR_LEFT);  break;
        case c_GEO_CENTROID:    v_x = CompList.get_FeatureVector(c_FEAT_MASS_CENTER_X);      break;
        default:                return ER_parameter_bad;}

        vector<double> v_y;
        switch (geometric) {
        case c_GEO_OFFSET:      v_y = CompList.get_FeatureVector(c_FEAT_RECT_AXEPAR_TOP);   break;
        case c_GEO_CENTROID:    v_y = CompList.get_FeatureVector(c_FEAT_MASS_CENTER_Y);      break;
        default:                return ER_parameter_bad;}

        for(int c = 0; c < CompList.size(); c++)
            ER = Draw_Dot(
                        pMA_Out,
                        v_x[c],
                        v_y[c],
                        thickness,
                        value);
    }
        break;
/*
    //Straight Lines
    case c_GEO_AXIS_MAJOR:
    case c_GEO_AXIS_MINOR:
    {
        vector<double> v_length;
        switch (geometric) {
        case c_GEO_AXIS_MAJOR:  v_length = CompList.get_FeatureVector(c_FEAT_MAJOR_AXIS);   break;
        case c_GEO_AXIS_MINOR:  v_length = CompList.get_FeatureVector(c_FEAT_MINOR_AXIS);   break;
        default:                return ER_parameter_bad;}

        vector<double> v_angle = CompList.get_FeatureVector(c_FEAT_ELLIPSE_FIT_ANGLE);
        if(c_GEO_AXIS_MINOR)
            for(int c = 0; c < v_angle.size(); c++)
                v_angle[c] += 90.0;

        vector<double> v_center_x = CompList.get_FeatureVector(c_FEAT_ELLIPSE_FIT_CENTER_X);
        vector<double> v_center_y = CompList.get_FeatureVector(c_FEAT_ELLIPSE_FIT_CENTER_Y);

        for(int c = 0; c < CompList.size(); c++)
            ER = Draw_Line_Angle(
                        pMA_Out,
                        v_length[c],
                        v_center_x[c],
                        v_center_y[c],
                        v_angle[c],
                        thickness,
                        value);
    }
        break;
*/
    //Closed Lines
    case c_GEO_CONTOUR:
    case c_GEO_CONVEX_HULL:
    {
        //get contour
        vector<vector<Point>> vv_contours;
        switch (geometric) {
        case c_GEO_CONTOUR:     vv_contours = CompList.get_ContourVector();             break;
        case c_GEO_CONVEX_HULL: vv_contours = CompList.get_ContourVector_ConvexHull();  break;
        default:                return ER_parameter_bad;}

        //make sure that all contours are valid
        int c = 0;
        while (c < vv_contours.size())
        {
            if(vv_contours[c].empty())
                vv_contours.erase(vv_contours.begin() + c);
            else
                c++;
        }

        //draw contours, if at least one is valid
        if(!vv_contours.empty())
            drawContours(
                        *pMA_Out,
                        vv_contours,
                        -1,
                        Scalar(value),
                        thickness);
    }
        break;

    case c_GEO_CONVEX_DEFICIT:
    {
        Mat MA_Convex_Hull_tmp = Mat::zeros(pMA_In->size(), CV_8UC1);

        //get contour
        vector<vector<Point>> vv_contours;
        vv_contours = CompList.get_ContourVector_ConvexHull();

        //make sure that all contours are valid
        int c = 0;
        while (c < vv_contours.size())
        {
            if(vv_contours[c].empty())
                vv_contours.erase(vv_contours.begin() + c);
            else
                c++;
        }

        //draw contours, if at least one is valid
        if(!vv_contours.empty())
            drawContours(
                        MA_Convex_Hull_tmp,
                        vv_contours,
                        -1,
                        Scalar(255),
                        1);

        //fill convex hulls
        Mat MA_Convex_Hull_Filled_tmp;
        ER = Fill_Holes(
                    &MA_Convex_Hull_Filled_tmp,
                    &MA_Convex_Hull_tmp);
        if(ER != ER_okay)
        {
            MA_Convex_Hull_tmp.release();
            MA_Convex_Hull_Filled_tmp.release();
            return ER;
        }

        //Convex Deficit
        ER = Math_ImgImg_Diff(
                    pMA_Out,
                    &MA_Convex_Hull_Filled_tmp,
                    pMA_In);

        MA_Convex_Hull_Filled_tmp.release();
        MA_Convex_Hull_tmp.release();
        if(ER != ER_okay)
            return ER;
    }
        break;

    case c_GEO_RECT_AXEPAR:
    {
        for(int c = 0; c < CompList.size(); c++)
            rectangle(
                        *pMA_Out,
                        CompList.get_BndBox_Rect(c),
                        Scalar(value),
                        thickness);
    }
        break;

    case c_GEO_RECT_ROTATE:
    {
        for(int c = 0; c < CompList.size(); c++)
            Draw_Rect_Rotate(
                        pMA_Out,
                        CompList.get_BndBox_Rotate(c),
                        thickness,
                        value);
    }
        break;

    case c_GEO_CIRCLE_INSCRIB:
    case c_GEO_CIRCLE_INCLOSE:
    case c_GEO_CIRCLE_EQUIVAL:
    case c_GEO_CIRCLE_ENCLOSE:
    case c_GEO_CIRCLE_CIRCUMS:
    {
        vector<double> v_radius;
        switch (geometric) {
        case c_GEO_CIRCLE_INSCRIB:      v_radius = CompList.get_FeatureVector(c_FEAT_CIRC_INSCRIB_RADIUS);      break;
        case c_GEO_CIRCLE_INCLOSE:      v_radius = CompList.get_FeatureVector(c_FEAT_CIRC_INCLOSE_RADIUS);      break;
        case c_GEO_CIRCLE_EQUIVAL:      v_radius = CompList.get_FeatureVector(c_FEAT_CIRC_EQUIVAL_RADIUS);      break;
        case c_GEO_CIRCLE_ENCLOSE:      v_radius = CompList.get_FeatureVector(c_FEAT_CIRC_ENCLOSE_RADIUS);      break;
        case c_GEO_CIRCLE_CIRCUMS:      v_radius = CompList.get_FeatureVector(c_FEAT_CIRC_CIRCUMS_RADIUS);      break;
        default:                        return ER_parameter_bad;}

        vector<double> v_center_x;
        switch (geometric) {
        case c_GEO_CIRCLE_INSCRIB:      v_center_x = CompList.get_FeatureVector(c_FEAT_MASS_CENTER_X);          break;
        case c_GEO_CIRCLE_INCLOSE:      v_center_x = CompList.get_FeatureVector(c_FEAT_CIRC_INCLOSE_CENTER_X);  break;
        case c_GEO_CIRCLE_EQUIVAL:      v_center_x = CompList.get_FeatureVector(c_FEAT_MASS_CENTER_X);          break;
        case c_GEO_CIRCLE_ENCLOSE:      v_center_x = CompList.get_FeatureVector(c_FEAT_CIRC_ENCLOSE_CENTER_X);  break;
        case c_GEO_CIRCLE_CIRCUMS:      v_center_x = CompList.get_FeatureVector(c_FEAT_MASS_CENTER_X);          break;
        default:                        return ER_parameter_bad;}

        vector<double> v_center_y;
        switch (geometric) {
        case c_GEO_CIRCLE_INSCRIB:      v_center_y = CompList.get_FeatureVector(c_FEAT_MASS_CENTER_Y);          break;
        case c_GEO_CIRCLE_INCLOSE:      v_center_y = CompList.get_FeatureVector(c_FEAT_CIRC_INCLOSE_CENTER_Y);  break;
        case c_GEO_CIRCLE_EQUIVAL:      v_center_y = CompList.get_FeatureVector(c_FEAT_MASS_CENTER_Y);          break;
        case c_GEO_CIRCLE_ENCLOSE:      v_center_y = CompList.get_FeatureVector(c_FEAT_CIRC_ENCLOSE_CENTER_Y);  break;
        case c_GEO_CIRCLE_CIRCUMS:      v_center_y = CompList.get_FeatureVector(c_FEAT_MASS_CENTER_Y);          break;
        default:                        return ER_parameter_bad;}

        for(int c = 0; c < CompList.size(); c++)
        {
            qDebug() << "c/x/y/r" << c << v_center_x[c] << v_center_y[c] << v_radius[c];

            circle(
                        *pMA_Out,
                        Point2f(v_center_x[c], v_center_y[c]),
                        v_radius[c],
                        Scalar(value),
                        thickness);
        }
    }
       break;

    case c_GEO_ELLIPSE_FIT:
    {
        for(int c = 0; c < CompList.size(); c++)
            ellipse(
                        *pMA_Out,
                        CompList.get_Ellipse_Fitted(c),
                        Scalar(value),
                        thickness);
    }
       break;

    }

    return ER_okay;
}

int D_Img_Proc::Reduce_Outlines(Mat *pMA_Out, Mat *pMA_In, int neighborhood, int thickness)
{
    if(pMA_In->empty())                         return ER_empty;
    if(neighborhood != 4 && neighborhood != 8)  return ER_parameter_bad;
    if(thickness < 0)                           return ER_parameter_bad;

    int elem = MORPH_RECT;
    if(neighborhood == 4)
        elem = MORPH_CROSS;

    int ER;

    //make sure input is binary 8bit
    Mat MA_bin8bit;
    ER = Threshold_Relative(
                &MA_bin8bit,
                pMA_In,
                0,
                0);
    if(ER != ER_okay)   return ER;

    /*
    //Fill Holes
    Mat MA_bin8bit_noHoles;
    ER = Fill_Holes(
                &MA_bin8bit_noHoles,
                &MA_bin8bit);
    if(ER != ER_okay)   return ER;
    */

    //everything connected to at least one white pixel (potential outline)
    Mat MA_outlines;
    ER = Morphology_Elemental(
                &MA_outlines,
                &MA_bin8bit,
                MORPH_DILATE,
                elem,
                thickness,
                thickness,
                BORDER_DEFAULT,
                1);
    if(ER != ER_okay)   return ER;

    //get only outlines, not the objects as well
    ER = Math_ImgImg_Diff(
                pMA_Out,
                &MA_outlines,
                &MA_bin8bit);
    if(ER != ER_okay)   return ER;

    MA_bin8bit.release();
    MA_outlines.release();
    return ER_okay;
}

int D_Img_Proc::Reduce_Centroid(Mat *pMA_Out, Mat *pMA_In, int thickness)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->channels() != 1)     return ER_channel_bad;
    if(pMA_In->depth() != CV_8U)    return ER_bitdepth_bad;

    //allocate/init
    *pMA_Out = Mat::zeros(pMA_In->size(), CV_8UC1);

    //containers
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    //find contours
    findContours(*pMA_In, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

    //get the moments
    vector<Moments> v_mom(contours.size());
    for(int i = 0; i < contours.size(); i++ )
        v_mom[i] = moments(contours[i], false);

    // get the centroid of figures.
    for(int i = 0; i < contours.size(); i++)
        Draw_Dot(
                            pMA_Out,
                            static_cast<int>(v_mom[i].m10 / v_mom[i].m00),
                            static_cast<int>(v_mom[i].m01 / v_mom[i].m00),
                            thickness,
                            255);

    /*
    //split
    D_Component_List CompList;
    ER = Split_img2components(
                &CompList,
                pMA_In);
    if(ER != ER_okay)   return ER_okay;

    //get and draw
    for(int cmp = 0; cmp < CompList.size(); cmp++)
        ER = Draw_Dot(
                    pMA_Out,
                    CompList.get_Component(cmp).get_Feature(c_FEAT_MASS_CENTER_X),
                    CompList.get_Component(cmp).get_Feature(c_FEAT_MASS_CENTER_Y),
                    thickness,
                    255);
    */

    return ER_okay;
}

int D_Img_Proc::Reduce_Contours(Mat *pMA_Out, Mat *pMA_In, int thickness)
{
    if(pMA_In->empty())                                                                             return ER_empty;
    if(pMA_In->channels() != 1)                                                                     return ER_channel_bad;
    if((pMA_In->depth() != CV_8U) && (pMA_In->depth() != CV_32S) && (pMA_In->depth() != CV_16U))    return ER_bitdepth_bad;

    D_Component_List CompList;
    Split_img2components(
                &CompList,
                pMA_In,
                4);

    vector<vector<Point>> vv_contours = CompList.get_ContourVector();

    *pMA_Out = Mat::zeros(pMA_In->size(), CV_8UC1);

    //make sure that all contours are valid
    int c = 0;
    while (c < vv_contours.size())
    {
        if(vv_contours[c].empty())
            vv_contours.erase(vv_contours.begin() + c);
        else
            c++;
    }

    //draw contours, if at least one is valid
    if(!vv_contours.empty())
        drawContours(
                    *pMA_Out,
                    vv_contours,
                    -1,
                    Scalar(255),
                    thickness);

    return ER_okay;
}

int D_Img_Proc::Calc_Centroids(vector<Point2f> *pvCentroids, Mat *pMA_In, int connectivity)
{
    if(pMA_In->empty())                                                 return ER_empty;
    if(pMA_In->type() != CV_8UC1 && pMA_In->type() != CV_16UC1)         return ER_type_bad;
    if(connectivity != 4 && connectivity != 8)                          return ER_parameter_bad;
    int ER;

    //labeling new image
    Mat MA_tmp_Labels;

    switch (pMA_In->type()) {

    case CV_8UC1:
    {
        ER = Labeling(
                    &MA_tmp_Labels,
                    pMA_In,
                    connectivity,
                    CV_32S);
        if(ER != ER_okay)
        {
            MA_tmp_Labels.release();
            return ER;
        }
    }
        break;

    case CV_16UC1:
    case CV_32SC1:
    {
        ER = Duplicate(
                    &MA_tmp_Labels,
                    pMA_In);
        if(ER != ER_okay)
        {
            MA_tmp_Labels.release();
            return ER;
        }
    }
        break;

    default:
        return ER_type_bad;
    }

    //get coordinates
    vector<vector<Point>> vvPoints;
    ER = Split_img2vv_coord(
                &vvPoints,
                &MA_tmp_Labels);
    MA_tmp_Labels.release();
    if(ER != ER_okay)
        return ER;

    //qDebug() << "Calc_Centroids - Split_img2vv_coord - detected labes" << vvPoints.size();

    //calc centroids
    pvCentroids->clear();
    pvCentroids->resize(vvPoints.size());
    for(size_t lab = 0; lab < vvPoints.size(); lab++)
    {
        size_t sum_x = 0;
        size_t sum_y = 0;
        for(int pt = 0; pt < vvPoints[lab].size(); pt++)
        {
            sum_x += vvPoints[lab][pt].x;
            sum_y += vvPoints[lab][pt].y;
        }

        (*pvCentroids)[lab] = Point2f(
                    sum_x / static_cast<float>(vvPoints[lab].size()),
                    sum_y / static_cast<float>(vvPoints[lab].size()));
    }

    return ER_okay;
}

int D_Img_Proc::Floodfill(Mat *pMA_Out, Mat *pMA_In, unsigned int seed_x, unsigned int seed_y, double new_val)
{
    if(pMA_In->empty())                                                                             return ER_empty;
    if((pMA_In->depth() != CV_8U) && (pMA_In->depth() != CV_32F) && (pMA_In->depth() != CV_64F))    return ER_type_bad;
    if(pMA_In->channels() != 1)                                                                     return ER_channel_bad;
    if(((int)seed_x >= pMA_In->cols) || ((int)seed_y >= pMA_In->rows))                              return ER_size_missmatch;

    *pMA_Out = pMA_In->clone();

    floodFill(
                *pMA_Out,
                Point(seed_x, seed_y),
                Scalar(new_val));

    return ER_okay;
}

int D_Img_Proc::Floodfill(Mat *pMA_Target, unsigned int seed_x, unsigned int seed_y, double new_val)
{
    if(pMA_Target->empty())                                                                                     return ER_empty;
    if((pMA_Target->depth() != CV_8U) && (pMA_Target->depth() != CV_32F) && (pMA_Target->depth() != CV_64F))    return ER_type_bad;
    if(pMA_Target->channels() != 1)                                                                             return ER_channel_bad;
    if(((int)seed_x >= pMA_Target->cols) || ((int)seed_y >= pMA_Target->rows))                                  return ER_size_missmatch;

    floodFill(
                *pMA_Target,
                Point(seed_x, seed_y),
                Scalar(new_val));

    return ER_okay;
}

int D_Img_Proc::Floodfill_Boundary(Mat *pMA_Out, Mat *pMA_In, double new_val)
{
    if(pMA_In->empty())             return ER_empty;

    int ER;

    //padding with boundary value
    //qDebug() << "size:" << pMA_In->cols << "x" << pMA_In->rows;
    ER = Padding(
                pMA_Out,
                pMA_In,
                1,
                1,
                BORDER_CONSTANT);
    if(ER != ER_okay)
    {
        qDebug() << "D_Img_Proc::Floodfill_Boundary" << "Padding" << "Error:" << ER;
        return ER;
    }

    //floodfill from new 0/0 -> from boundary
    //qDebug() << "size:" << pMA_Out->cols << "x" << pMA_Out->rows;
    ER = Floodfill(
                pMA_Out,
                pMA_Out,
                0,
                0,
                new_val);
    if(ER != ER_okay)
    {
        qDebug() << "D_Img_Proc::Floodfill_Boundary" << "Floodfill" << "Error:" << ER;
        return ER;
    }

    //corp image back to original size
    //qDebug() << "size:" << pMA_Out->cols << "x" << pMA_Out->rows;
    ER = Crop_Rect_Abs(
                pMA_Out,
                pMA_Out,
                1,
                1,
                pMA_In->cols,
                pMA_In->rows);
    if(ER != ER_okay)
    {
        qDebug() << "D_Img_Proc::Floodfill_Boundary" << "Crop_Rect_Abs" << "Error:" << ER;
        return ER;
    }

    //qDebug() << "size:" << pMA_Out->cols << "x" << pMA_Out->rows;
    return ER_okay;
}

int D_Img_Proc::Floodfill_Delta(Mat *pMA_Out, Mat *pMA_In, int seed_x, int seed_y, uchar val_new, uchar val_delta)
{
    //Errors
    if(pMA_In->empty())                 return ER_empty;
    if(pMA_In->type() != CV_8UC1)       return ER_type_bad;

    //Init Out img
    *pMA_Out = pMA_In->clone();

    //Errors 2
    if(seed_x < 0)                      return ER_index_out_of_range;
    if(seed_x > pMA_In->cols - 1)       return ER_index_out_of_range;
    if(seed_y < 0)                      return ER_index_out_of_range;
    if(seed_y > pMA_In->rows - 1)       return ER_index_out_of_range;

    //Label image
    Mat MA_tmp_label = Mat::zeros(pMA_In->size(), CV_16UC1);

    //start recursion
    qDebug() << "Floodfill_Delta Start recursion: Floodfill_Delta_Step";
    Floodfill_Delta_Step(
                pMA_Out,
                &MA_tmp_label,
                seed_x,
                seed_y,
                0,
                0,
                val_new,
                val_delta,
                pMA_Out->at<uchar>(seed_y,seed_x));

    return ER_okay;
}

bool D_Img_Proc::Floodfill_Delta_Step(Mat *pMA_Target, Mat *pMA_Check, int x, int y, int dx, int dy, int val_new, int val_delta, int val_origin)
{
    //recursion onnly works on small images!!!!!!!!!!!!!!!!!!!!!! avoid to use this if possible

    //type check
    if(pMA_Check->type() != CV_16UC1)   return false;
    if(pMA_Target->type() != CV_8UC1)   return false;

    //change coordinates
    x += dx;
    y += dy;

    //check coordinates
    if(x < 0)                       {qDebug() << "Floodfill_Delta_Step: x to small" << x  << y; return false;}
    if(x > pMA_Target->cols - 1)    {qDebug() << "Floodfill_Delta_Step: x to big"   << x  << y; return false;}
    if(y < 0)                       {qDebug() << "Floodfill_Delta_Step: y to small" << x  << y; return false;}
    if(y > pMA_Target->rows - 1)    {qDebug() << "Floodfill_Delta_Step: y to big"   << x  << y; return false;}

    //position allready drawn to?
    if(pMA_Check->at<ushort>(y, x) != 0)
    {
        qDebug() << "Floodfill_Delta_Step: pixel" << x << y << "already painted to.";
        return false;
    }

    //get values
    int val_current = pMA_Target->at<uchar>(y, x);

    //value out of draw value range?
    if(abs(val_current - val_origin) > val_delta)
    {
        qDebug() << "Floodfill_Delta_Step: Value difference to origin is too high" << "val_current" << val_current << "val_origin" << val_origin << "val_delta" << val_delta;
        return false;
    }

    //replace value in out image
    pMA_Target->at<uchar>(y, x) = val_new;
    pMA_Check->at<ushort>(y, x) = 1;
    qDebug() << "Set pixel" << x << y << "to value" << val_new;

    //recursive call to neighbors
    Floodfill_Delta_Step(pMA_Target, pMA_Check, x, y, +1,  0, val_new, val_delta, val_current);
    Floodfill_Delta_Step(pMA_Target, pMA_Check, x, y, -1,  0, val_new, val_delta, val_current);
    Floodfill_Delta_Step(pMA_Target, pMA_Check, x, y,  0, +1, val_new, val_delta, val_current);
    Floodfill_Delta_Step(pMA_Target, pMA_Check, x, y,  0, -1, val_new, val_delta, val_current);
    return true;
}



int D_Img_Proc::Draw_Dot(Mat *pMA_Target, int x, int y, int r, uchar val)
{
    if(pMA_Target->empty())             return ER_empty;
    if(pMA_Target->type() != CV_8UC1)   return ER_type_bad;

    line(
                *pMA_Target,
                Point(x, y),
                Point(x, y),
                Scalar((uchar) val),
                r,
                8);

    return ER_okay;
}

int D_Img_Proc::Draw_Line(Mat *pMA_Target, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int thickness, double value)
{
    if(pMA_Target->empty())             return ER_empty;
    //if(pMA_Target->depth() != CV_8U)    return ER_bitdepth_bad;

    switch (pMA_Target->channels()) {

    case 1:
        line(
                    *pMA_Target,
                    Point(x1, y1),
                    Point(x2, y2),
                    Scalar(value),
                    thickness,
                    8);
        break;

    case 2:
        line(
                    *pMA_Target,
                    Point(x1, y1),
                    Point(x2, y2),
                    Scalar(value, value),
                    thickness,
                    8);
        break;

    case 3:
        line(
                    *pMA_Target,
                    Point(x1, y1),
                    Point(x2, y2),
                    Scalar(value, value, value),
                    thickness,
                    8);
        break;

    case 4:
        line(
                    *pMA_Target,
                    Point(x1, y1),
                    Point(x2, y2),
                    Scalar(value, value, value, value),
                    thickness,
                    8);
        break;

    default:
        break;
    }

    return ER_okay;
}

/*!
 * \brief D_Img_Proc::Draw_Line_Bresenham custum function to draw a line between 0° and 45°
 * \details recommended to use cv's draw line function instead. This code is limited in fuction and is not tested properly!
 * \param pMA_Target image to draw to
 * \param P1 start point
 * \param P2 end point
 * \return error code
 */
int D_Img_Proc::Draw_Line_Bresenham(Mat *pMA_Target, Point P1, Point P2, double val)
{
    if(pMA_Target->empty())                     return ER_empty;
    if(P1.x < 0 || P1.x >= pMA_Target->cols)    return ER_index_out_of_range;
    if(P1.y < 0 || P1.y >= pMA_Target->rows)    return ER_index_out_of_range;
    if(P2.x < 0 || P2.x >= pMA_Target->cols)    return ER_index_out_of_range;
    if(P2.y < 0 || P2.y >= pMA_Target->rows)    return ER_index_out_of_range;
    if(pMA_Target->type() != CV_8UC1)           return ER_type_bad;

    //shifts in x and y
    int dx = P2.x - P1.x;
    int dy = P2.y - P1.y;

    //point to draw to (changes in while loop)
    int x = P1.x;
    int y = P1.y;

    //set starting pixel
    pMA_Target->at<uchar>(y, x) = static_cast<uchar>(val);

    //error
    int errorXdx = 0;

    //loop line in x direction
    while(x < P2.x)
    {
        //step to the right
        x++;

        //deviation of point to line as an effect of the slope of the line and discretisation
        errorXdx += dy;

        //check, if correction is needed
        if(errorXdx > (dx / 2.0))
        {
            y++;
            errorXdx -= dx;
        }

        //set new pixel
        pMA_Target->at<uchar>(y, x) = static_cast<uchar>(val);
    }

    return ER_okay;
}

int D_Img_Proc::Draw_Line_Angle(Mat *pMA_Target, double length, double center_x, double center_y, double angle, unsigned int thickness, double value)
{
    if(pMA_Target->empty())             return ER_empty;
    if(pMA_Target->type() != CV_8UC1)   return ER_type_bad;
    if(length < 0)                      return ER_parameter_bad;
    if((angle < 0) || (angle > 180))    return ER_parameter_bad;

    //get attributes
    Point2d center(center_x, center_y);
    double   l = length / 2.0;
    double   s = sin(angle);
    double   c = cos(angle);

    //endpoints
    Point2d p1 = Point2d(+c*l, +s*l) + center;
    Point2d p2 = Point2d(-c*l, -s*l) + center;

    //draw line
    line(
                *pMA_Target,
                p1,
                p2,
                Scalar(value),
                thickness,
                8);

    return ER_okay;
}

int D_Img_Proc::Draw_Vector(Mat *pMA_Target, int offset_x, int offset_y, double length_value, double angle_value, double length_error, double angle_error, int vector_thickness, uchar value, int error_steps, int error_thickness)
{
    if(pMA_Target->empty())                                     return ER_empty;
    if(pMA_Target->type() != CV_8UC1)                           return ER_type_bad;

    //offsets
    int ox = offset_x;
    int oy = offset_y;

    //angles main/low/high
    double am = angle_value;
    double al = D_Math::Difference_AngleRad(angle_value, angle_error);
    double ah = D_Math::Sum_AngleRad(angle_value, angle_error);

    //lengths main/low/high
    double lm = length_value;
    double ll = length_value - length_error;
    double lh = length_value + length_error;

    //points
    //center
    Point2d pt_lm_am(cos(am) * lm + ox, sin(am) * lm + oy);
    //errors angle
    Point2d pt_lm_al(cos(al) * lm + ox, sin(al) * lm + oy);
    Point2d pt_lm_ah(cos(ah) * lm + ox, sin(ah) * lm + oy);
    //errors length
    Point2d pt_ll_am(cos(am) * ll + ox, sin(am) * ll + oy);
    Point2d pt_lh_am(cos(am) * lh + ox, sin(am) * lh + oy);

    //Draw vector
    Draw_Line(
                pMA_Target,
                ox, oy,
                static_cast<unsigned int>(pt_lm_am.x), static_cast<unsigned int>(pt_lm_am.y),
                vector_thickness,
                value);

    //Draw Error-Kindey (polar transformed ellipse)
    Point2d pt_err_old = pt_lm_ah;//start on the right (perspective in vector direction)
    Point2d pt_err_new;

    double a_sampling = 0;
    double a_sampling_step = PI_2_0 / error_steps;

    while(a_sampling < PI_2_0)
    {
        //pairs of errors beeing on ellipse/kidney
        double a_error = cos(a_sampling) * angle_error;
        double l_error = sin(a_sampling) * length_error;

        //calc new point on kidney line
        double a_new = am + a_error;
        double l_new = lm + l_error;

        //make sure vector length is not negative
        if(l_new < 0)
            l_new = 0;

        pt_err_new = Point2d(cos(a_new) * l_new + ox, sin(a_new) * l_new + oy);

        //draw line (part of kidney line)
        Draw_Line(
                    pMA_Target,
                    static_cast<unsigned int>(pt_err_old.x), static_cast<unsigned int>(pt_err_old.y),
                    static_cast<unsigned int>(pt_err_new.x), static_cast<unsigned int>(pt_err_new.y),
                    error_thickness,
                    value);

        //save new pint as old one for next one
        pt_err_old = pt_err_new;

        //next angle
        a_sampling += a_sampling_step;
    }

    return ER_okay;
}

int D_Img_Proc::Draw_VectorField(Mat *pMA_Target, vector<vector<double> > vv_XY_length_value, vector<vector<double> > vv_XY_angle_value, vector<vector<double> > vv_XY_length_error, vector<vector<double> > vv_XY_angle_error, uchar value, int vector_thickness, int error_steps, int error_thickness, bool grid_add, int grid_thicknes, bool label_add, int label_thickness, double label_scale)
{
    if(pMA_Target->empty())                                 return ER_empty;
    if(pMA_Target->type() != CV_8UC1)                       return ER_type_bad;
    if(vv_XY_length_value.empty())                          return ER_empty;

    //size checks x
    size_t nx = vv_XY_length_value.size();
    if(vv_XY_length_error.size() != nx)         {qDebug() << "Draw_VectorField size checks x vv_XY_length_error.size() != nx" << nx;        return ER_size_missmatch;}
    if(vv_XY_angle_value.size() != nx)          {qDebug() << "Draw_VectorField size checks x vv_XY_angle_value.size() != nx" << nx;         return ER_size_missmatch;}
    if(vv_XY_angle_error.size() != nx)          {qDebug() << "Draw_VectorField size checks x vv_XY_angle_error.size() != nx" << nx;         return ER_size_missmatch;}

    //size checks y
    size_t ny = vv_XY_length_value[0].size();
    for(size_t ix = 0; ix < nx; ix++)
    {
        if(vv_XY_length_value[ix].size() != ny) {qDebug() << "Draw_VectorField size checks y vv_XY_length_value[ix].size() != ny" << ny;    return ER_size_missmatch;}
        if(vv_XY_length_error[ix].size() != ny) {qDebug() << "Draw_VectorField size checks y vv_XY_length_error[ix].size() != ny" << ny;    return ER_size_missmatch;}
        if(vv_XY_angle_value[ix].size() != ny)  {qDebug() << "Draw_VectorField size checks y vv_XY_angle_value[ix].size() != ny" << ny;     return ER_size_missmatch;}
        if(vv_XY_angle_error[ix].size() != ny)  {qDebug() << "Draw_VectorField size checks y vv_XY_angle_error[ix].size() != ny" << ny;     return ER_size_missmatch;}
    }
    int ER;

    //draw grid
    ER = Draw_Grid(
                pMA_Target,
                nx,
                ny,
                grid_add,
                grid_thicknes,
                label_add,
                label_thickness,
                label_scale,
                static_cast<uchar>(value));
    if(ER != ER_okay)
        return ER;

    //size (as double to save cast operations later)
    double w = pMA_Target->cols;
    double h = pMA_Target->rows;

    //shift box corner to box center
    double sx = w / (2 * nx);
    double sy = h / (2 * ny);

    //draw vectors
    for(size_t gx = 0; gx < nx; gx++)
        for(size_t gy = 0; gy < ny; gy++)
        {
            //center of box = offset of vector
            int ox = static_cast<int>((static_cast<double>(gx) / nx) * w + sx);
            int oy = static_cast<int>((static_cast<double>(gy) / ny) * h + sy);

            //test output
            //qDebug() << "Draw_VectorField" << "draw at" << ox << "/" << oy << "length" << vv_XY_length_value[gx][gy] << vv_XY_length_error[gx][gy] << "angle" << vv_XY_angle_value[gx][gy] << vv_XY_angle_error[gx][gy];

            //draw vector
            Draw_Vector(
                        pMA_Target,
                        ox,
                        oy,
                        vv_XY_length_value[gx][gy],
                        vv_XY_angle_value[gx][gy],
                        vv_XY_length_error[gx][gy],
                        vv_XY_angle_error[gx][gy],
                        vector_thickness,
                        value,
                        error_steps,
                        error_thickness);
        }

    return ER_okay;
}

int D_Img_Proc::Draw_CircleField(Mat *pMA_Target, vector<vector<double>> vv_XY_radius_value, vector<vector<double>> vv_XY_radius_error, uchar value, int circle_thickness_min, bool circles_filled, bool grid_add, int grid_thicknes, bool label_add, int label_thickness, double label_scale)
{
    if(pMA_Target->empty())                                 return ER_empty;
    if(pMA_Target->type() != CV_8UC1)                       return ER_type_bad;
    if(vv_XY_radius_value.empty())                          return ER_empty;

    //size checks x
    size_t nx = vv_XY_radius_value.size();
    if(vv_XY_radius_error.size() != nx)         {qDebug() << "Draw_CircleField size checks x vv_XY_radius_error.size() != nx" << nx;        return ER_size_missmatch;}

    //size checks y
    size_t ny = vv_XY_radius_value[0].size();
    for(size_t ix = 0; ix < nx; ix++)
    {
        if(vv_XY_radius_value[ix].size() != ny) {qDebug() << "Draw_CircleField size checks y vv_XY_radius_value[ix].size() != ny" << ny;    return ER_size_missmatch;}
        if(vv_XY_radius_error[ix].size() != ny) {qDebug() << "Draw_CircleField size checks y vv_XY_radius_error[ix].size() != ny" << ny;    return ER_size_missmatch;}
    }
    int ER;

    //draw grid
    ER = Draw_Grid(
                pMA_Target,
                nx,
                ny,
                grid_add,
                grid_thicknes,
                label_add,
                label_thickness,
                label_scale,
                static_cast<uchar>(value));
    if(ER != ER_okay)
        return ER;

    //size (as double to avoid cast operations later)
    double w = pMA_Target->cols;
    double h = pMA_Target->rows;

    //shift box corner to box center
    double sx = w / (2 * nx);
    double sy = h / (2 * ny);

    //draw circles
    for(size_t gx = 0; gx < nx; gx++)
        for(size_t gy = 0; gy < ny; gy++)
        {
            //center of box = offset of circle
            int ox = static_cast<int>((static_cast<double>(gx) / nx) * w + sx);
            int oy = static_cast<int>((static_cast<double>(gy) / ny) * h + sy);

            if(circles_filled)
            {
                //draw circle
                Draw_Circle(
                            pMA_Target,
                            ox,
                            oy,
                            vv_XY_radius_value[gx][gy],
                            value,
                            2 * vv_XY_radius_error[gx][gy] >= circle_thickness_min ? 2 * vv_XY_radius_error[gx][gy] : circle_thickness_min,
                            false);
            }
            else
            {
                //radii
                double r_inner = vv_XY_radius_value[gx][gy] - vv_XY_radius_error[gx][gy];
                double r_outer = vv_XY_radius_value[gx][gy] + vv_XY_radius_error[gx][gy];
                if(r_inner < 0)
                    r_inner = 0;

                //draw circle inner
                Draw_Circle(
                            pMA_Target,
                            ox,
                            oy,
                            r_inner,
                            value,
                            circle_thickness_min,
                            false);

                //draw circle outer
                Draw_Circle(
                            pMA_Target,
                            ox,
                            oy,
                            r_outer,
                            value,
                            circle_thickness_min,
                            false);
            }
        }

    return ER_okay;
}

int D_Img_Proc::Draw_Rect(Mat *pMA_Target, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int thickness, double val)
{
    if(pMA_Target->empty())             return ER_empty;
    //if(pMA_Target->type() != CV_8UC1)   return ER_type_bad;

    int ER;

    //Top
    ER = Draw_Line(pMA_Target, x1, y1, x2, y1, thickness, val);
    if(ER != ER_okay)   return ER;

    //Bottom
    ER = Draw_Line(pMA_Target, x1, y2, x2, y2, thickness, val);
    if(ER != ER_okay)   return ER;

    //Left
    ER = Draw_Line(pMA_Target, x1, y1, x1, y2, thickness, val);
    if(ER != ER_okay)   return ER;

    //Right
    ER = Draw_Line(pMA_Target, x2, y1, x2, y2, thickness, val);
    if(ER != ER_okay)   return ER;

    return ER_okay;
}

int D_Img_Proc::Draw_Rect_Rotate(Mat *pMA_Target, RotatedRect rrect, int thickness, double value)
{
    if(pMA_Target->empty())             return ER_empty;
    if(pMA_Target->type() != CV_8UC1)   return ER_type_bad;

    //get attributes
    Point2f center = rrect.center;
    float   w = rrect.size.width / 2.f;
    float   h = rrect.size.height / 2.f;
    float   s = sin(rrect.angle * Grad2Rad);
    float   c = cos(rrect.angle * Grad2Rad);

    //point on vertice rel
    Point2f v1 = Point2f(+c*w, +s*w);
    Point2f v2 = Point2f(-s*h, +c*h);
    Point2f v3 = Point2f(-c*w, -s*w);
    Point2f v4 = Point2f(+s*h, -c*h);

    //corner
    Point2f p1 = center + v1 + v2;
    Point2f p2 = center + v2 + v3;
    Point2f p3 = center + v3 + v4;
    Point2f p4 = center + v4 + v1;

    //draw vertices
    Draw_Line(pMA_Target, p1.x, p1.y, p2.x, p2.y, thickness, value);
    Draw_Line(pMA_Target, p3.x, p3.y, p2.x, p2.y, thickness, value);
    Draw_Line(pMA_Target, p3.x, p3.y, p4.x, p4.y, thickness, value);
    Draw_Line(pMA_Target, p1.x, p1.y, p4.x, p4.y, thickness, value);

    return ER_okay;
}

int D_Img_Proc::Draw_GridSimple(Mat *pMA_Target, int nx, int ny, Scalar value)
{
    if(pMA_Target->empty())             return ER_empty;

    //size
    double w = pMA_Target->cols;
    double h = pMA_Target->rows;

    if(w < nx)                          return ER_parameter_bad;
    if(h < ny)                          return ER_parameter_bad;

    switch (pMA_Target->type()) {

    case CV_8UC1:
    {
        uchar val = value[0];
        for(int iy = 1; iy < ny; iy++)
        {//horizontal line
            int y = static_cast<int>((static_cast<double>(iy) / ny) * h);
            for(int x = 0; x < w; x++)
                pMA_Target->at<uchar>(y, x) = val;
        }
        for(int ix = 1; ix < nx; ix++)
        {//vertical line
            int x = static_cast<int>((static_cast<double>(ix) / nx) * w);
            for(int y = 0; y < h; y++)
                pMA_Target->at<uchar>(y, x) = val;
        }
    }
        break;

    case CV_16UC1:
    {
        ushort val = value[0];
        for(int iy = 1; iy < ny; iy++)
        {//horizontal line
            int y = static_cast<int>((static_cast<double>(iy) / ny) * h);
            for(int x = 0; x < w; x++)
                pMA_Target->at<ushort>(y, x) = val;
        }
        for(int ix = 1; ix < nx; ix++)
        {//vertical line
            int x = static_cast<int>((static_cast<double>(ix) / nx) * w);
            for(int y = 0; y < h; y++)
                pMA_Target->at<ushort>(y, x) = val;
        }
    }
        break;

    case CV_8UC3:
    {
        Vec3b val;
        val[0] = value[0];
        val[1] = value[1];
        val[2] = value[2];
        for(int iy = 1; iy < ny; iy++)
        {//horizontal line
            int y = static_cast<int>((static_cast<double>(iy) / ny) * h);
            for(int x = 0; x < w; x++)
                pMA_Target->at<Vec3b>(y, x) = val;
        }
        for(int ix = 1; ix < nx; ix++)
        {//vertical line
            int x = static_cast<int>((static_cast<double>(ix) / nx) * w);
            for(int y = 0; y < h; y++)
                pMA_Target->at<Vec3b>(y, x) = val;
        }
    }
        break;

    case CV_16UC3:
    {
        Vec3w val;
        val[0] = value[0];
        val[1] = value[1];
        val[2] = value[2];
        for(int iy = 1; iy < ny; iy++)
        {//horizontal line
            int y = static_cast<int>((static_cast<double>(iy) / ny) * h);
            for(int x = 0; x < w; x++)
                pMA_Target->at<Vec3w>(y, x) = val;
        }
        for(int ix = 1; ix < nx; ix++)
        {//vertical line
            int x = static_cast<int>((static_cast<double>(ix) / nx) * w);
            for(int y = 0; y < h; y++)
                pMA_Target->at<Vec3w>(y, x) = val;
        }
    }
        break;

    case CV_64FC3:
    {
        Vec3d val;
        val[0] = value[0];
        val[1] = value[1];
        val[2] = value[2];
        for(int iy = 1; iy < ny; iy++)
        {//horizontal line
            int y = static_cast<int>((static_cast<double>(iy) / ny) * h);
            for(int x = 0; x < w; x++)
                pMA_Target->at<Vec3d>(y, x) = val;
        }
        for(int ix = 1; ix < nx; ix++)
        {//vertical line
            int x = static_cast<int>((static_cast<double>(ix) / nx) * w);
            for(int y = 0; y < h; y++)
                pMA_Target->at<Vec3d>(y, x) = val;
        }
    }
        break;

    default:
        return ER_type_bad;
    }

    return ER_okay;
}

int D_Img_Proc::Draw_Grid(Mat *pMA_Target, int nx, int ny, bool lines_add, int grid_thickness, bool label_add, int label_thickness, double label_scale, double value)
{
    if(pMA_Target->empty())                                                 return ER_empty;
    if(grid_thickness < 1)                                                  return ER_parameter_bad;
    if(label_thickness < 1)                                                 return ER_parameter_bad;
    if(label_scale <= 0)                                                    return ER_parameter_bad;
    if(pMA_Target->depth() != CV_8U)                                        return ER_bitdepth_bad;

    //size
    double w = pMA_Target->cols;
    double h = pMA_Target->rows;

    if(w < nx)                                                              return ER_parameter_bad;
    if(h < ny)                                                              return ER_parameter_bad;

    //grid
    if(lines_add)
    {
        //vertical lines
        for(int ix = 1; ix < nx; ix++)
        {
            int x = static_cast<int>((static_cast<double>(ix) / nx) * w);
            Draw_Line(
                        pMA_Target,
                        x, 0,
                        x, static_cast<unsigned int>(h-1),
                        grid_thickness,
                        value);
        }

        //horizontal lines
        for(int iy = 1; iy < ny; iy++)
        {
            int y = static_cast<int>((static_cast<double>(iy) / ny) * h);
            Draw_Line(
                        pMA_Target,
                        0, y,
                        static_cast<unsigned int>(w-1), y,
                        grid_thickness,
                        value);
        }
    }

    //labels
    if(label_add)
    {
        //vertical lines
        int box_number = 0;
        for(int iy = 0; iy < ny; iy++)
        {
            //pos form number offset
            int y = static_cast<int>((static_cast<double>(iy + 1) / ny) * h) - 3 * grid_thickness;
            for(int ix = 0; ix < nx; ix++)
            {
                //pos for number offset
                int x = static_cast<int>((static_cast<double>(ix) / nx) * w) + 2 * grid_thickness;

                Draw_Text(
                            pMA_Target,
                            QString::number(box_number),
                            x,
                            y,
                            label_thickness,
                            label_scale,
                            value);

                //next number
                box_number++;
            }
        }
    }


   return ER_okay;
}

int D_Img_Proc::Draw_Boundaries(Mat *pMA_Target, int width, int val)
{
    if(pMA_Target->empty())             return ER_empty;
    if(pMA_Target->type() != CV_8UC1)   return ER_type_bad;

    return Draw_Rect(
                pMA_Target,
                0,
                0,
                pMA_Target->cols - 1,
                pMA_Target->rows - 1,
                width,
                val);

    return ER_okay;
}

int D_Img_Proc::Draw_Circle(Mat *pMA_Out, Mat *pMA_In, int x, int y, int r, int val, int thickness, bool filled)
{
    if(pMA_In->empty())     return ER_empty;

    *pMA_Out = Mat::zeros(pMA_In->size(), pMA_In->type());

    return Draw_Circle(
                pMA_Out,
                x,
                y,
                r,
                val,
                thickness,
                filled);
}

int D_Img_Proc::Draw_Circle(Mat *pMA_Target, int x, int y, int r, int val, int thickness, bool filled)
{
    if(pMA_Target->empty())             return ER_empty;
    if(pMA_Target->channels() != 1)     return ER_channel_bad;
    if(x < 0 || x >= pMA_Target->cols)  return ER_size_missmatch;
    if(y < 0 || y >= pMA_Target->rows)  return ER_size_missmatch;

    if(filled)
        return Draw_Dot(
                    pMA_Target,
                    x,
                    y,
                    2 * r,
                    val);
    else
        circle(
                    *pMA_Target,
                    Point(x, y),
                    r,
                    Scalar(val),
                    thickness);

    return ER_okay;
}

int D_Img_Proc::Draw_Text(QImage *pQI_Target, QString text_tl, QString text_tr, QString text_bl, QString text_br, unsigned int size, QColor color)
{
    if(pQI_Target->isNull())    return ER_empty;

    QPainter painter(pQI_Target);
    QPen pen(color);
    painter.setPen(pen);
    QFont font("Times", size, QFont::Bold);
    painter.setFont(font);

    painter.drawText(
                pQI_Target->rect(),
                Qt::AlignTop | Qt::AlignLeft,
                text_tl);

    painter.drawText(
                pQI_Target->rect(),
                Qt::AlignTop | Qt::AlignRight,
                text_tr);

    painter.drawText(
                pQI_Target->rect(),
                Qt::AlignBottom | Qt::AlignLeft,
                text_bl);

    painter.drawText(
                pQI_Target->rect(),
                Qt::AlignBottom | Qt::AlignRight,
                text_br);

    painter.end();

    return ER_okay;
}

int D_Img_Proc::Draw_Text(Mat *pMA_Target, QString text, int x, int y, int thickness, double scale, double value)
{
    if(pMA_Target->empty())             return ER_empty;
    if(x < 0 || x > pMA_Target->cols)   return ER_index_out_of_range;
    if(y < 0 || y > pMA_Target->rows)   return ER_index_out_of_range;

    switch (pMA_Target->channels()) {

    case 1:
        putText(
                    *pMA_Target,
                    text.toStdString(),
                    Point(x, y),
                    FONT_HERSHEY_TRIPLEX,
                    scale,
                    Scalar(value),
                    thickness,
                    CV_AA);
        break;

    case 2:
        putText(
                    *pMA_Target,
                    text.toStdString(),
                    Point(x, y),
                    FONT_HERSHEY_TRIPLEX,
                    scale,
                    Scalar(value, value),
                    thickness,
                    CV_AA);
        break;

    case 3:
        putText(
                    *pMA_Target,
                    text.toStdString(),
                    Point(x, y),
                    FONT_HERSHEY_TRIPLEX,
                    scale,
                    Scalar(value, value, value),
                    thickness,
                    CV_AA);
        break;

    case 4:
        putText(
                    *pMA_Target,
                    text.toStdString(),
                    Point(x, y),
                    FONT_HERSHEY_TRIPLEX,
                    scale,
                    Scalar(value, value, value, value),
                    thickness,
                    CV_AA);
        break;

    default:
        break;
    }

    return ER_okay;
}

int D_Img_Proc::Draw_Text_ContrastColor(Mat *pMA_Target, QString text, int x, int y, int thickness, double scale)
{
    if(pMA_Target->empty())             return ER_empty;
    if(x < 0 || x > pMA_Target->cols)   return ER_index_out_of_range;
    if(y < 0 || y > pMA_Target->rows)   return ER_index_out_of_range;
    if(pMA_Target->type() != CV_64FC3)  return ER_type_bad;

    putText(
                *pMA_Target,
                text.toStdString(),
                Point(x, y),
                FONT_HERSHEY_TRIPLEX,
                scale,
                Contrast_Color(pMA_Target->at<Vec3d>(y, x)),
                thickness,
                CV_AA);

    return ER_okay;
}

int D_Img_Proc::Draw_Label_Numbers_LUT(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Label, vector<double> v_LUT, bool border, double scale, double thickness, bool center, int precision, uchar r, uchar g, uchar b)
{
    if(pMA_In->empty() || pMA_Label->empty())                                                               return ER_empty;
    if(pMA_Label->channels() != 1)                                                                          return ER_channel_bad;
    if((pMA_In->channels() != 1) && (pMA_In->channels() != 3))                                              return ER_channel_bad;
    if(pMA_In->size() != pMA_Label->size())                                                                 return ER_size_missmatch;
    if((pMA_Label->depth() != CV_8U) && (pMA_Label->depth() != CV_16U) && (pMA_Label->depth() != CV_32S))   return ER_type_bad;

    int ER;


    //Copy input image to output and force 3 channels
    if(pMA_In->channels() == 1)
    {
        ER = Convert_Color(
                    pMA_Out,
                    pMA_In,
                    CV_GRAY2BGR);
        if(ER != ER_okay)   return ER;
    }
    else
    {
        ER = Duplicate(
                    pMA_Out,
                    pMA_In);
        if(ER != ER_okay)   return ER;
    }

    //borders
    if(border)
    {
        Mat MA_tmp_border;

        //get binary
        ER = Threshold_Relative_1C(
                    &MA_tmp_border,
                    pMA_Label,
                    0,
                    0);
        if(ER != ER_okay)   return ER;

        //outlines = borders
        ER = Reduce_Outlines(
                    &MA_tmp_border,
                    &MA_tmp_border);
        if(ER != ER_okay)   return ER;

        //fit channels
        ER = Convert_Color(
                    &MA_tmp_border,
                    &MA_tmp_border,
                    CV_GRAY2BGR);
        if(ER != ER_okay)   return ER;

        //subtract borders
        ER = Math_ImgImg_Diff(
                    pMA_Out,
                    pMA_Out,
                    &MA_tmp_border);
        if(ER != ER_okay)   return ER;

        MA_tmp_border.release();
    }


    //split to comp list
    D_Component_List CompList;
    ER = CompList.set_Mat(pMA_Label);
    if(ER != ER_okay)   return ER;


    //get wanted pos
    vector<Point2f> v_pos;
    if(center)
        v_pos = CompList.get_CentroidVector();
    else
        v_pos = CompList.get_OffsetVector_2f();

    //cehck sizes
    if(v_LUT.size() != v_pos.size())
        return ER_size_missmatch;

    //Write Number from LUT as Text at Position
    for(size_t i = 0; i < v_pos.size(); i++)
        putText(
                    *pMA_Out,
                    QString::number(v_LUT[i], 'g', precision).toStdString(),
                    v_pos[i],
                    FONT_HERSHEY_COMPLEX_SMALL,
                    scale,
                    Scalar(b, g, r),
                    thickness,
                    CV_AA);


    return ER_okay;
}

int D_Img_Proc::Draw_Label_Text(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Label, QStringList QSL_LabelTexts, bool border, double scale, double thickness, bool center, uchar r, uchar g, uchar b, int connectivity)
{
    if(pMA_In->empty() || pMA_Label->empty())                                                               return ER_empty;
    if(pMA_Label->channels() != 1)                                                                          return ER_channel_bad;
    if((pMA_In->channels() != 1) && (pMA_In->channels() != 3))                                              return ER_channel_bad;
    if(pMA_In->size() != pMA_Label->size())                                                                 return ER_size_missmatch;
    if((pMA_Label->depth() != CV_8U) && (pMA_Label->depth() != CV_16U) && (pMA_Label->depth() != CV_32S))   return ER_type_bad;
    if(connectivity != 4 && connectivity != 8)                                                              return ER_parameter_bad;

    int ER;


    //Copy input image to output and force 3 channels
    if(pMA_In->channels() == 1)
    {
        ER = Convert_Color(
                    pMA_Out,
                    pMA_In,
                    CV_GRAY2BGR);
        if(ER != ER_okay)   return ER;
    }
    else
    {
        ER = Duplicate(
                    pMA_Out,
                    pMA_In);
        if(ER != ER_okay)   return ER;
    }

    //borders
    if(border)
    {
        Mat MA_tmp_border;

        //get binary
        ER = Threshold_Relative_1C(
                    &MA_tmp_border,
                    pMA_Label,
                    0,
                    0);
        if(ER != ER_okay)   return ER;

        //outlines = borders
        ER = Reduce_Outlines(
                    &MA_tmp_border,
                    &MA_tmp_border);
        if(ER != ER_okay)   return ER;

        //fit channels
        ER = Convert_Color(
                    &MA_tmp_border,
                    &MA_tmp_border,
                    CV_GRAY2BGR);
        if(ER != ER_okay)   return ER;

        //subtract borders
        ER = Math_ImgImg_Diff(
                    pMA_Out,
                    pMA_Out,
                    &MA_tmp_border);
        if(ER != ER_okay)   return ER;

        MA_tmp_border.release();
    }


    //split to comp list
    D_Component_List CompList;
    ER = CompList.set_Mat(pMA_Label, connectivity);
    if(ER != ER_okay)   return ER;


    //get wanted pos
    vector<Point2f> v_pos;
    if(center)
        v_pos = CompList.get_CentroidVector();
    else
        v_pos = CompList.get_OffsetVector_2f();

    //cehck sizes
    if(static_cast<size_t>(QSL_LabelTexts.size()) != v_pos.size())
    {
        qDebug() << "Draw_Label_Text" << "Label detected:" << v_pos.size() << "- Texts count:" << QSL_LabelTexts.size();
        return ER_size_missmatch;
    }

    //Write Number from LUT as Text at Position
    for(size_t i = 0; i < v_pos.size(); i++)
        putText(
                    *pMA_Out,
                    QSL_LabelTexts[i].toStdString(),
                    v_pos[i],
                    FONT_HERSHEY_COMPLEX_SMALL,
                    scale,
                    Scalar(b, g, r),
                    thickness,
                    CV_AA);


    return ER_okay;
}

int D_Img_Proc::Draw_Label_Numbers_LUT_Gray(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Label, vector<double> v_LUT, int geometric, double scale, int thickness, bool center, int precision)
{
    if(pMA_In->empty() || pMA_Label->empty())                               return ER_empty;
    if(pMA_Label->channels() != 1)                                          return ER_channel_bad;
    if(pMA_In->channels() != 1)                                             return ER_channel_bad;
    if(pMA_In->size() != pMA_Label->size())                                 return ER_size_missmatch;
    if((geometric < 0) || (geometric > c_GEO_NUMBER_OF))                    return ER_parameter_bad;
    if((pMA_Label->depth() != CV_16U) && (pMA_Label->depth() != CV_32S))    return ER_type_bad;

    int ER;

    //split to comp list
    D_Component_List CompList;
    ER = CompList.set_Mat(pMA_Label);
    if(ER != ER_okay)   return ER;

    //Out images
    Mat MA_tmp_geo;
    Mat MA_tmp_val;
    Mat MA_tmp_num;

    //geometric------------------------------------------------
    ER = Reduce_Geometric(
                &MA_tmp_geo,
                pMA_Label,
                geometric,
                8,
                thickness,
                255);
    if(ER != ER_okay)   return ER;

    //value----------------------------------------------------
    ER = Normalize(
                &MA_tmp_val,
                pMA_In,
                CV_MINMAX,
                CV_8U,
                0,
                255);
    if(ER != ER_okay)   return ER;

    //numbers---------------------------------------------------

    //allocate
    MA_tmp_num = Mat::zeros(pMA_In->size(), CV_8UC1);

    //get wanted pos
    vector<Point2f> v_pos;
    if(center)
        v_pos = CompList.get_CentroidVector();
    else
        v_pos = CompList.get_OffsetVector_2f();

    //cehck sizes
    if(v_LUT.size() != v_pos.size())
        return ER_size_missmatch;

    //Write Number from LUT as Text at Position
    for(int com = 0; com < v_pos.size(); com++)
        putText(
                    MA_tmp_num,
                    QString::number(v_LUT[com], 'g', precision).toStdString(),
                    v_pos[com],
                    FONT_HERSHEY_COMPLEX_SMALL,
                    scale,
                    Scalar(255),
                    thickness,
                    CV_AA);

    //merge---------------------------------------------------------

    ER = Merge(
                pMA_Out,
                &MA_tmp_geo,
                &MA_tmp_num,
                &MA_tmp_val);
    if(ER != ER_okay)   return ER;


    MA_tmp_geo.release();
    MA_tmp_num.release();
    MA_tmp_val.release();
    return ER_okay;
}

int D_Img_Proc::Draw_Label_Numbers(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Label, double scale, double thickness, bool center)
{
    if(pMA_In->empty() || pMA_Label->empty())                               return ER_empty;
    if(pMA_In->channels() != 1 || pMA_Label->channels() != 1)               return ER_channel_bad;
    if(pMA_In->size() != pMA_Label->size())                                 return ER_size_missmatch;
    if((pMA_Label->depth() != CV_16U) && (pMA_Label->depth() != CV_32S))    return ER_type_bad;

    int ER;

    *pMA_Out = Mat(pMA_In->size(),CV_8UC3);

    Mat MA_labels8bit;
    ER = Normalize(
                &MA_labels8bit,
                pMA_Label,
                CV_MINMAX,
                CV_8U,
                0,
                255);
    if(ER != ER_okay)   return ER;

    Mat MA_edges8bit;
    ER = Reduce_Outlines(
                &MA_edges8bit,
                &MA_labels8bit);
    if(ER != ER_okay)   return ER;

    Mat MA_in8bit;
    ER = Normalize(
                &MA_in8bit,
                pMA_In,
                CV_MINMAX,
                CV_8U,
                0,
                255);
    if(ER != ER_okay)   return ER;

    Mat MA_numbers8bit = Mat(pMA_In->size(), CV_8UC1, Scalar(0));
    ER = Draw_Label_Numbers(
                &MA_numbers8bit,
                pMA_Label,
                scale,
                thickness,
                center);
    if(ER != ER_okay)   return ER;

    bool channel_use[4];
    channel_use[0] = true;
    channel_use[1] = true;
    channel_use[2] = true;
    channel_use[3] = false;
    ER = Merge(
                pMA_Out,
                &MA_numbers8bit,
                &MA_edges8bit,
                &MA_in8bit,
                &MA_in8bit,
                3,
                channel_use);
    if(ER != ER_okay)   return ER;

    MA_edges8bit.release();
    MA_in8bit.release();
    MA_labels8bit.release();
    MA_numbers8bit.release();
    return ER_okay;
}

int D_Img_Proc::Draw_Label_Numbers(Mat *pMA_Out, Mat *pMA_Label, double scale, double thickness, bool center)
{
    if(center)
        return Draw_Label_Numbers_Center(
                    pMA_Out,
                    pMA_Label,
                    scale,
                    thickness);
    else
        return Draw_Label_Numbers_Corner(
                    pMA_Out,
                    pMA_Label,
                    scale,
                    thickness);
}

int D_Img_Proc::Draw_Label_Numbers_Center(Mat *pMA_Out, Mat *pMA_Label, double scale, double thickness)
{
    if(pMA_Label->empty())                                              return ER_empty;
    if(pMA_Label->channels() != 1)                                      return ER_channel_bad;
    if(pMA_Label->depth() != CV_16U && pMA_Label->depth() != CV_32S)    return ER_bitdepth_bad;

    //split
    D_Component_List CompList;
    int ER = CompList.set_Mat(pMA_Label);
    if(ER != ER_okay)   return ER;

    //draw text at centroids
    //qDebug() << "Draw_Label_Numbers_Center - put text";
    *pMA_Out = Mat::zeros(pMA_Label->size(), CV_8UC1);
    for(int c = 0; c < CompList.size(); c++)
    {
        putText(
                    *pMA_Out,
                    to_string(c),
                    CompList.get_Centroid(c),
                    FONT_HERSHEY_COMPLEX_SMALL,
                    scale,
                    Scalar(255),
                    thickness,
                    CV_AA);
    }

    return ER_okay;
}

/*!
 * \brief D_Img_Proc::Draw_ContourText draw contours in an image with added text at contours centers
 * \param pMA_Target image to draw in
 * \param vContours contours
 * \param QSL_Texts texts
 * \param line_thickness thickness of contours
 * \param text_thickness thickness of text
 * \param text_scale scale of text
 * \return error code
 */
int D_Img_Proc::Draw_ContourText(Mat *pMA_Target, vector<vector<Point>> vContours, QStringList QSL_Texts, vector<Point2f> vTextOrigins, int line_thickness, int text_thickness, double text_scale, double value)
{
    ///error checks
    if(pMA_Target->empty())                                         return ER_empty;
    if(static_cast<size_t>(QSL_Texts.size()) != vContours.size())   return ER_size_missmatch;
    if(vContours.size() != vTextOrigins.size())                     return ER_size_missmatch;

    ///calc draw color with fitting channel count
    Scalar color;
    switch (pMA_Target->channels()) {
    case 1: color = Scalar(value);                      break;
    case 2: color = Scalar(value, value);               break;
    case 3: color = Scalar(value, value, value);        break;
    case 4: color = Scalar(value, value, value, value); break;
    default:                                            return ER_type_bad;}

    ///draw contours
    drawContours(
                *pMA_Target,
                vContours,
                -1,
                color,
                line_thickness);

    ///loop and draw texts
    size_t n = vContours.size();
    for(size_t i = 0; i < n; i++)
        putText(
                    *pMA_Target,
                    QSL_Texts[i].toStdString(),
                    vTextOrigins[i],
                    FONT_HERSHEY_COMPLEX_SMALL,
                    text_scale,
                    color,
                    text_thickness,
                    CV_AA);

    return ER_okay;
}

Scalar D_Img_Proc::Contrast_Color(Vec3d val_RGB)
{
    //original RGB
    double R = val_RGB[2];
    double G = val_RGB[1];
    double B = val_RGB[0];

    //HSV transform
    double H, S, V;
    double max = std::max(R, std::max(G, B));
    double min = std::min(R, std::min(G, B));
    double range = max - min;
    if(range == 0)      H = 0;
    else if(max == R)   H = (PI / 3.0) * (0 + ((G - B)/range));
    else if(max == G)   H = (PI / 3.0) * (2 + ((B - R)/range));
    else /*(max == B)*/ H = (PI / 3.0) * (4 + ((R - G)/range));
    if(max == 0)        S = 0;
    else                S = range / max;
                        V = max;

    //"contrast color" (not a nice version, but it works for the moment)
    qDebug() << "HSV in" << H << S << V;
    if(V >= 0.5)        V = 0;
    else                V = 1;
    if(((7.0 / 12) * PI_2_0) < H && H < ((9.0 / 12) * PI_2_0))  V = 1;  //white on blue is always better than black on blue
    if(H >= PI)         H -= PI;
    else                H += PI;
    /*always*/          S = 0;
    qDebug() << "HSV out" << H << S << V;

    //HSV transfrom invers
    int     hi  = floor(H / (PI / 3.0));
    double  f   = (H / (PI / 3.0)) - hi;
    double  p   = V * (1 - S);
    double  q   = V * (1 - (S * f));
    double  t   = V * (1 - (S * (1 - f)));
    switch (hi) {
    case 1:     R = q;      G = V;      B = p;      break;
    case 2:     R = p;      G = V;      B = t;      break;
    case 3:     R = p;      G = q;      B = V;      break;
    case 4:     R = t;      G = p;      B = V;      break;
    case 5:     R = V;      G = p;      B = q;      break;
    default:    R = V;      G = t;      B = p;      break;}

    //contrast RGB
    return Scalar(B, G, R);
}

int D_Img_Proc::Highlight_NumericalProblems(Mat *pMA_Out, Mat *pMA_In)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->type() != CV_64FC1)  return ER_type_bad;

    //extrema
    double min = numeric_limits<double>::min();
    double max = numeric_limits<double>::max();

    size_t px_count = pMA_In->rows * pMA_In->cols;
    double* ptr_in = reinterpret_cast<double*>(pMA_In->data);

    //look for problems
    bool problem_found = false;
    for(size_t px = 0; px < px_count && !problem_found; px++, ptr_in++)
        if(!isfinite(*ptr_in))
            problem_found = true;

    //found problem?
    if(problem_found)
    {
        qDebug() << "shitty value detected";

        *pMA_Out = Mat(pMA_In->size(), CV_8UC3);
        ptr_in = reinterpret_cast<double*>(pMA_In->data);
        Vec3b * ptr_out = reinterpret_cast<Vec3b*>(pMA_Out->data);
        for(size_t px = 0; px < px_count; px++, ptr_in++, ptr_out++)
        {
            double val = *ptr_in;

            if(isfinite(val))
            {
                if(val > 0)
                    *ptr_out = Vec3b(255, 255, 255);    //positive -> white
                else if(val < 0)
                    *ptr_out = Vec3b(0, 0, 0);          //negative -> black
                else
                    *ptr_out = Vec3b(127, 127, 127);    //zero -> gray
            }
            else if(isnan(val))
                *ptr_out = Vec3b(0, 255, 0);            //nan -> green
            else if(val < min)
                *ptr_out = Vec3b(255, 0, 0);            //-inf -> blue
            else if(val > max)
                *ptr_out = Vec3b(0, 255, 0);            //+inf -> red
            else
                *ptr_out = Vec3b(255/2, 255/2, 255);    //mysterium -> pink
        }

        return ER_NumericProblem;
    }
    else
    {
        *pMA_Out = pMA_In->clone();
    }

    return ER_okay;
}

int D_Img_Proc::OverlayOverwrite(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Overlay, QColor color, double intensity_overlay, double intensity_backgr)
{
    return OverlayOverwrite(
                pMA_Out,
                pMA_In,
                pMA_Overlay,
                color.red(),
                color.green(),
                color.blue(),
                intensity_overlay,
                intensity_backgr);
}

int D_Img_Proc::OverlayOverwrite(Mat *pMA_Out, Mat *pMA_In, Mat *pMA_Overlay, uchar r, uchar g, uchar b, double intensity_overlay, double intensity_backgr)
{
    if(pMA_In->type() != CV_8UC3)                       return ER_type_bad;
    if(pMA_Overlay->type() != CV_8UC1)                  return ER_type_bad;
    if(pMA_In->size() != pMA_Overlay->size())           return ER_size_missmatch;
    if(intensity_overlay < 0 || intensity_overlay > 1)  return ER_parameter_bad;

    //init out
    int ER = Math_ImgScal_Mult(
                pMA_Out,
                pMA_In,
                intensity_backgr);
    if(ER != ER_okay && ER != ER_empty)
        return ER;

    //px count
    int area = pMA_Out->rows * pMA_Out->cols;

    //overlay color as pixel
    Vec3b val_overlay = {
        static_cast<uchar>(b * intensity_overlay),
        static_cast<uchar>(g * intensity_overlay),
        static_cast<uchar>(r * intensity_overlay)};

    //loop & replace
    Vec3b* ptr_out = reinterpret_cast<Vec3b*>(pMA_Out->data);
    uchar* ptr_ovr = reinterpret_cast<uchar*>(pMA_Overlay->data);
    for(int px = 0; px < area; px++, ptr_out++, ptr_ovr++)
        if(*ptr_ovr)
            *ptr_out = val_overlay;

    return ER_okay;
}

int D_Img_Proc::ExtremeValuesColor(Mat *pMA_Out, Mat *pMA_In, double rel_low, double rel_high, double gamma, bool color_low, bool color_high, bool zero_as_lowest)
{
    if(pMA_In->empty())                 return ER_empty;
    if(pMA_In->channels() != 1)         return ER_channel_bad;
    if(rel_low > rel_high)              return ER_parameter_bad;
    if(rel_low < 0 || rel_low > 1)      return ER_parameter_bad;
    if(rel_high < 0 || rel_high > 1)    return ER_parameter_bad;
    if(gamma < 0)                       return ER_parameter_bad;
    int ER = ER_okay;

    //get absolut extreme values
    double val_min;
    double val_max;
    ER = MinMax_of_Mat(
                pMA_In,
                &val_min,
                &val_max);
    if(ER != ER_okay)
        return ER;
    if(zero_as_lowest)
        val_min = 0;

    //range
    double val_offset_in = val_min;
    double val_range_in = val_max - val_min;
    double thresh_low = rel_low * val_range_in + val_offset_in;
    double thresh_high = rel_high * val_range_in + val_offset_in;
    double val_range_inR = thresh_high - thresh_low;
    double val_offset_inR = thresh_low;

    //init out
    *pMA_Out = Mat(pMA_In->size(), CV_8UC3);
    Vec3b* ptr_out = reinterpret_cast<Vec3b*>(pMA_Out->data);

    //area
    int area = pMA_In->cols * pMA_In->rows;

    switch (pMA_In->type()) {

    case CV_8UC1:
    {
        uchar* ptr_in = reinterpret_cast<uchar*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
        {
            double val = *ptr_in;
            if(val <= thresh_low && color_low)
                *ptr_out = Vec3b(255, 0, 0);
            else if(val > thresh_high && color_high)
                *ptr_out = Vec3b(0, 0, 255);
            else
            {
                double val_out = pow((val - val_offset_inR)/ val_range_inR, gamma) * 255.0;

                if(val_out < 0)
                    val_out = 0;
                if(val_out > 255)
                    val_out = 255;

                *ptr_out = Vec3b(
                            static_cast<uchar>(val_out),
                            static_cast<uchar>(val_out),
                            static_cast<uchar>(val_out));
            }
        }
    }
        break;

    case CV_8SC1:
    {
        char* ptr_in = reinterpret_cast<char*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
        {
            double val = *ptr_in;
            if(val <= thresh_low && color_low)
                *ptr_out = Vec3b(255, 0, 0);
            else if(val > thresh_high && color_high)
                *ptr_out = Vec3b(0, 0, 255);
            else
            {
                double val_out = pow((val - val_offset_inR)/ val_range_inR, gamma) * 255.0;

                if(val_out < 0)
                    val_out = 0;
                if(val_out > 255)
                    val_out = 255;

                *ptr_out = Vec3b(
                            static_cast<uchar>(val_out),
                            static_cast<uchar>(val_out),
                            static_cast<uchar>(val_out));
            }
        }
    }
        break;

    case CV_16UC1:
    {
        ushort* ptr_in = reinterpret_cast<ushort*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
        {
            double val = *ptr_in;
            if(val <= thresh_low && color_low)
                *ptr_out = Vec3b(255, 0, 0);
            else if(val > thresh_high && color_high)
                *ptr_out = Vec3b(0, 0, 255);
            else
            {
                double val_out = pow((val - val_offset_inR)/ val_range_inR, gamma) * 255.0;

                if(val_out < 0)
                    val_out = 0;
                if(val_out > 255)
                    val_out = 255;

                *ptr_out = Vec3b(
                            static_cast<uchar>(val_out),
                            static_cast<uchar>(val_out),
                            static_cast<uchar>(val_out));
            }
        }
    }
        break;

    case CV_16SC1:
    {
        short* ptr_in = reinterpret_cast<short*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
        {
            double val = *ptr_in;
            if(val <= thresh_low && color_low)
                *ptr_out = Vec3b(255, 0, 0);
            else if(val > thresh_high && color_high)
                *ptr_out = Vec3b(0, 0, 255);
            else
            {
                double val_out = pow((val - val_offset_inR)/ val_range_inR, gamma) * 255.0;

                if(val_out < 0)
                    val_out = 0;
                if(val_out > 255)
                    val_out = 255;

                *ptr_out = Vec3b(
                            static_cast<uchar>(val_out),
                            static_cast<uchar>(val_out),
                            static_cast<uchar>(val_out));
            }
        }
    }
        break;

    case CV_32SC1:
    {
        int* ptr_in = reinterpret_cast<int*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
        {
            double val = *ptr_in;
            if(val <= thresh_low && color_low)
                *ptr_out = Vec3b(255, 0, 0);
            else if(val > thresh_high && color_high)
                *ptr_out = Vec3b(0, 0, 255);
            else
            {
                double val_out = pow((val - val_offset_inR)/ val_range_inR, gamma) * 255.0;

                if(val_out < 0)
                    val_out = 0;
                if(val_out > 255)
                    val_out = 255;

                *ptr_out = Vec3b(
                            static_cast<uchar>(val_out),
                            static_cast<uchar>(val_out),
                            static_cast<uchar>(val_out));
            }
        }
    }
        break;

    case CV_32FC1:
    {
        float* ptr_in = reinterpret_cast<float*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
        {
            double val = *ptr_in;
            if(val <= thresh_low && color_low)
                *ptr_out = Vec3b(255, 0, 0);
            else if(val > thresh_high && color_high)
                *ptr_out = Vec3b(0, 0, 255);
            else
            {
                double val_out = pow((val - val_offset_inR)/ val_range_inR, gamma) * 255.0;

                if(val_out < 0)
                    val_out = 0;
                if(val_out > 255)
                    val_out = 255;

                *ptr_out = Vec3b(
                            static_cast<uchar>(val_out),
                            static_cast<uchar>(val_out),
                            static_cast<uchar>(val_out));
            }
        }
    }
        break;

    case CV_64FC1:
    {
        double* ptr_in = reinterpret_cast<double*>(pMA_In->data);
        for(int px = 0; px < area; px++, ptr_in++, ptr_out++)
        {
            double val = *ptr_in;
            if(val <= thresh_low && color_low)
                *ptr_out = Vec3b(255, 0, 0);
            else if(val > thresh_high && color_high)
                *ptr_out = Vec3b(0, 0, 255);
            else
            {
                double val_out = pow((val - val_offset_inR)/ val_range_inR, gamma) * 255.0;

                if(val_out < 0)
                    val_out = 0;
                if(val_out > 255)
                    val_out = 255;

                *ptr_out = Vec3b(
                            static_cast<uchar>(val_out),
                            static_cast<uchar>(val_out),
                            static_cast<uchar>(val_out));
            }
        }
    }
        break;

    default:
        return  ER_type_bad;
    }

    return ER_okay;
}

int D_Img_Proc::Legend_HSV(Mat *pMA_Out, int width, int height, QStringList QSL_H, QStringList QSL_S, QStringList QSL_V, QString QS_H, QString QS_S, QString QS_V, double H_angle_min, double H_angle_range, double scale, double thickness)
{
    qDebug() << "Legend_HSV" << "Errors";
    if(QSL_H.empty())                           return ER_empty;
    if(QSL_S.empty())                           return ER_empty;
    if(QSL_V.empty())                           return ER_empty;
    if(QSL_H.size() < 2)                        return ER_size_bad;
    if(QSL_S.size() < 2)                        return ER_size_bad;
    if(QSL_V.size() < 2)                        return ER_size_bad;
    if(QSL_H.size() != QSL_S.size())            return ER_size_missmatch;
    if(QSL_H.size() != QSL_V.size())            return ER_size_missmatch;
    if(width <= 30 || height <= 30)             return ER_size_bad;

    //alloc out
    qDebug() << "Legend_HSV" << "Alloc";
    *pMA_Out = Mat::zeros(height, width, CV_64FC3);

    //Segments
    //horizontal
    qDebug() << "Legend_HSV" << "Segments horizontal";
    size_t n_horizontal = QSL_H.size() + 1;
    vector<size_t> vOffsets_horizontal(n_horizontal+1);
    for(size_t i = 0; i < vOffsets_horizontal.size(); i++)
        vOffsets_horizontal[i] = i * (static_cast<double>(width)/n_horizontal);
    qDebug() << "Legend_HSV" << "Segments horizontal" << vOffsets_horizontal;

    size_t width_colored = (width/n_horizontal) * (n_horizontal - 2);

    //vertical
    qDebug() << "Legend_HSV" << "Segments vertical";
    size_t n_vertical = 3;
    vector<size_t> vOffsets_vertical(n_vertical+1);
    for(size_t i = 0; i < vOffsets_vertical.size(); i++)
        vOffsets_vertical[i] = i * (static_cast<double>(height)/n_vertical);
    qDebug() << "Legend_HSV" << "Segments vertical" << vOffsets_vertical;

    size_t height_segment_vertical = height/n_vertical;

    //init img with color

    //hue
    qDebug() << "Legend_HSV" << "Color init hue";
    for(size_t x = 0; x < width_colored; x++)
    {
        double H    = ((static_cast<double>(x) / width_colored) * H_angle_range) + H_angle_min;
        double S    = 1;
        double V    = 1;

        int     hi      = floor(H / (PI / 3.0));
        double  f       = (H / (PI / 3.0)) - hi;
        double  p       = V * (1 - S);
        double  q       = V * (1 - (S * f));
        double  t       = V * (1 - (S * (1 - f)));

        //invers HSV Transfrom
        double R, G, B;
        switch (hi) {
        case 1:     R = q;      G = V;      B = p;      break;
        case 2:     R = p;      G = V;      B = t;      break;
        case 3:     R = p;      G = q;      B = V;      break;
        case 4:     R = t;      G = p;      B = V;      break;
        case 5:     R = V;      G = p;      B = q;      break;
        default:    R = V;      G = t;      B = p;      break;}
        Vec3d col(B, G, R);

        for(size_t y = 0; y < height_segment_vertical; y++)
            pMA_Out->at<Vec3d>(y + vOffsets_vertical[0], x + vOffsets_horizontal[1]) = col;
    }

    //saturation
    qDebug() << "Legend_HSV" << "Color init saturation";
    for(size_t x = 0; x < width_colored; x++)
    {
        qDebug() << "Legend_HSV" << "Color init saturation x=" << x;
        double H    = 0;
        double S    = (static_cast<double>(x) / width_colored);
        double V    = 1;

        int     hi      = floor(H / (PI / 3.0));
        double  f       = (H / (PI / 3.0)) - hi;
        double  p       = V * (1 - S);
        double  q       = V * (1 - (S * f));
        double  t       = V * (1 - (S * (1 - f)));

        //invers HSV Transfrom
        double R, G, B;
        switch (hi) {
        case 1:     R = q;      G = V;      B = p;      break;
        case 2:     R = p;      G = V;      B = t;      break;
        case 3:     R = p;      G = q;      B = V;      break;
        case 4:     R = t;      G = p;      B = V;      break;
        case 5:     R = V;      G = p;      B = q;      break;
        default:    R = V;      G = t;      B = p;      break;}
        Vec3d col(B, G, R);
        qDebug() << "Legend_HSV" << "Color init saturation R/G/B" << R << G << B;

        for(size_t y = 0; y < height_segment_vertical; y++)
            pMA_Out->at<Vec3d>(y + vOffsets_vertical[1], x + vOffsets_horizontal[1]) = col;
    }

    //value
    qDebug() << "Legend_HSV" << "Color init value";
    for(size_t x = 0; x < width_colored; x++)
    {
        double H    = 0;
        double S    = 0;
        double V    = (static_cast<double>(x) / width_colored);

        int     hi      = floor(H / (PI / 3.0));
        double  f       = (H / (PI / 3.0)) - hi;
        double  p       = V * (1 - S);
        double  q       = V * (1 - (S * f));
        double  t       = V * (1 - (S * (1 - f)));

        //invers HSV Transfrom
        double R, G, B;
        switch (hi) {
        case 1:     R = q;      G = V;      B = p;      break;
        case 2:     R = p;      G = V;      B = t;      break;
        case 3:     R = p;      G = q;      B = V;      break;
        case 4:     R = t;      G = p;      B = V;      break;
        case 5:     R = V;      G = p;      B = q;      break;
        default:    R = V;      G = t;      B = p;      break;}
        Vec3d col(B, G, R);

        for(size_t y = 0; y < height_segment_vertical; y++)
            pMA_Out->at<Vec3d>(y + vOffsets_vertical[2], x + vOffsets_horizontal[1]) = col;
    }

    //text offsets
    size_t text_offset_v = -5;//px
    size_t text_offset_h = +1;//px

    //put text on it
    qDebug() << "Legend_HSV" << "Put text";
    Draw_Text_ContrastColor(
            pMA_Out,
            QS_H,
            vOffsets_horizontal[0] + text_offset_h,
            vOffsets_vertical[1] + text_offset_v,
            thickness,
            scale);
    Draw_Text_ContrastColor(
            pMA_Out,
            QS_S,
            vOffsets_horizontal[0] + text_offset_h,
            vOffsets_vertical[2] + text_offset_v,
            thickness,
            scale);
    Draw_Text_ContrastColor(
            pMA_Out,
            QS_V,
            vOffsets_horizontal[0] + text_offset_h,
            vOffsets_vertical[3] + text_offset_v,
            thickness,
            scale);

    //put values on it
    qDebug() << "Legend_HSV" << "Put values hue";
    //hue
    for(int i = 0; i < QSL_H.size(); i++)
        Draw_Text_ContrastColor(
                pMA_Out,
                QSL_H[i],
                vOffsets_horizontal[i+1] + text_offset_h,
                vOffsets_vertical[1] + text_offset_v,
                thickness,
                scale);
    //saturation
    qDebug() << "Legend_HSV" << "Put values saturation";
    for(int i = 0; i < QSL_S.size(); i++)
        Draw_Text_ContrastColor(
                pMA_Out,
                QSL_S[i],
                vOffsets_horizontal[i+1] + text_offset_h,
                vOffsets_vertical[2] + text_offset_v,
                thickness,
                scale);
    //value
    qDebug() << "Legend_HSV" << "Put values value";
    for(int i = 0; i < QSL_V.size(); i++)
        Draw_Text_ContrastColor(
                pMA_Out,
                QSL_V[i],
                vOffsets_horizontal[i+1] + text_offset_h,
                vOffsets_vertical[3] + text_offset_v,
                thickness,
                scale);

    qDebug() << "Legend_HSV" << "end";
    return ER_okay;
}

int D_Img_Proc::ClassBorder_kNN(Mat *pMA_Out, Mat *pMA_Class0, Mat *pMA_Class1, int n)
{
    if(pMA_Class0->empty())                                                                                 return ER_empty;
    if(pMA_Class1->empty())                                                                                 return ER_empty;
    if(pMA_Class0->size() != pMA_Class1->size())                                                            return ER_size_missmatch;
    if(pMA_Class0->type() != CV_8UC1 && pMA_Class0->type() != CV_16UC1 && pMA_Class0->type() != CV_32SC1)   return ER_type_bad;
    if(pMA_Class1->type() != CV_8UC1 && pMA_Class1->type() != CV_16UC1 && pMA_Class1->type() != CV_32SC1)   return ER_type_bad;

    //Class Representants
    D_Component_List CompList_0(pMA_Class0, 4);
    D_Component_List CompList_1(pMA_Class1, 4);

    if(CompList_0.size() + CompList_1.size() <= n)
        return ER_other;

    //Centers of Masses
    vector<Point2f> vCOM_0 = CompList_0.get_CentroidVector();
    vector<Point2f> vCOM_1 = CompList_1.get_CentroidVector();

    //Nearest n found
    vector<double> vDist_0(vCOM_0.size(), 0);
    vector<double> vDist_1(vCOM_1.size(), 0);

    *pMA_Out = Mat::zeros(pMA_Class0->size(), CV_8UC3);

    for(int y = 0; y < pMA_Out->rows; y++)
        for(int x = 0; x < pMA_Out->cols; x++)
        {
            for(size_t i0 = 0; i0 < vCOM_0.size(); i0++)
                vDist_0[i0] = D_Math::Distance(vCOM_0[i0], Point2f(x, y));

            for(size_t i1 = 0; i1 < vCOM_1.size(); i1++)
                vDist_1[i1] = D_Math::Distance(vCOM_1[i1], Point2f(x, y));

            int score_0 = 0;
            int score_1 = 0;
            vector<size_t> v_winner_index_0;
            vector<size_t> v_winner_index_1;
            for(int s = 0; s < n; s++)
            {
                //qDebug() << "y" << y << "x" << x << "n" << s;

                double winner_value = INFINITY;
                int winner_class = 0;
                size_t winner_index = 0;

                //class 0
                for(size_t i0 = 0; i0 < vCOM_0.size(); i0++)
                {
                    bool former_winner = false;
                    for(size_t w0 = 0; w0 < v_winner_index_0.size(); w0++)
                        if(i0 == v_winner_index_0[w0])
                            former_winner = true;

                    if(!former_winner)
                    {
                        double dist = vDist_0[i0];
                        if(dist < winner_value)
                        {
                            winner_value = dist;
                            winner_class = 0;
                            winner_index = i0;
                        }
                    }
                }

                //class 1
                for(size_t i1 = 0; i1 < vCOM_1.size(); i1++)
                {
                    bool former_winner = false;
                    for(size_t w1 = 0; w1 < v_winner_index_1.size(); w1++)
                        if(i1 == v_winner_index_1[w1])
                            former_winner = true;

                    if(!former_winner)
                    {
                        double dist = vDist_1[i1];
                        if(dist < winner_value)
                        {
                            winner_value = dist;
                            winner_class = 1;
                            winner_index = i1;
                        }
                    }
                }

                if(winner_class == 0)
                {
                    score_0++;
                    v_winner_index_0.push_back(winner_index);
                }
                else if(winner_class == 1)
                {
                    score_1++;
                    v_winner_index_1.push_back(winner_index);
                }
            }

            //qDebug() << "y" << y << "x" << x << "score_0" << score_0 << "score_1" << score_1;

            //and the winner is:
            if(score_0 > score_1)
                pMA_Out->at<Vec3b>(y, x) = Vec3b((255.0 * score_0) / n, 0, 0);
            else if(score_1 > score_0)
                pMA_Out->at<Vec3b>(y, x) = Vec3b(0, 0, (255.0 * score_1) / n);
            else
                pMA_Out->at<Vec3b>(y, x) = Vec3b(0, 255, 0);
        }

    return ER_okay;
}

int D_Img_Proc::ObjectsMovement(vector<double> *pvShift_PxPerFrame, vector<double> *pvDirection_Rad, vector<Point2f> *pvPositions, vector<Mat> *pvMA_In, vector<vector<Point2f>> *pvvCentroids, double max_Shift_PxPerFrame, size_t index_NewImg, int connectivity)
{
    //qDebug() << "ObjectsMovement" << "Start" << "================================================================";

    if(pvMA_In->empty())                                    return ER_empty;
    if(pvvCentroids->empty())                               return ER_empty;
    if(pvMA_In->size() <= 1)                                return ER_size_bad;
    if(pvMA_In->size() != pvvCentroids->size())             return ER_size_missmatch;
    if(connectivity != 4 && connectivity != 8)              return ER_parameter_bad;
    if(index_NewImg >= pvMA_In->size())                     return ER_index_out_of_range;
    for(size_t i = 0; i < pvMA_In->size(); i++)
    {
        if((*pvMA_In)[i].empty())                           return ER_empty;
        if((*pvMA_In)[i].type() != CV_8UC1)                 return ER_type_bad;
        if((*pvMA_In)[i].size() != (*pvMA_In)[0].size())    return ER_size_missmatch;
    }
    int ER;

    //qDebug() << "ObjectsMovement" << "Error checks passed";

    //number of images
    size_t n = pvMA_In->size();

    //create index LUT (needed for circular list, save copy operations)
    vector<size_t> vIndexOldToNew(n);
    for(size_t i = 0; i < n; i++)
        vIndexOldToNew[i] = (i + index_NewImg + 1) % n;

    vector<size_t> vIndexNewToOld(n);
    for(size_t i = 0; i < n; i++)
        vIndexNewToOld[i] = vIndexOldToNew[n - 1 - i];

    //qDebug() << "ObjectsMovement" << "n =" << n << "vIndexOldToNew" << vIndexOldToNew << "vIndexNewToOld" << vIndexNewToOld;

    //calc centroids of new image
    //imshow("label img", (*pvMA_In)[index_NewImg]);
    ER = Calc_Centroids(
                &((*pvvCentroids)[index_NewImg]),
                &((*pvMA_In)[index_NewImg]),
                connectivity);
    if(ER != ER_okay)
        return ER;

    //qDebug() << "ObjectsMovement" << "Centroids calced";

    //at this point we know all centroids in all n images
    //one calced just right now and the others were given externally (from previous frame analysis by for example this function)

    //extract centroids of objects that are present in all n images
    //maximum number of frames is number of objects in newest frame (refernce)
    //"try to find objects in current frame in older ones"

    //List of labeled centroids in all n frames (only the ones that appear in newest frame)
    vector<vector<Point2f>> vvCentroidsLabled(n);
    vvCentroidsLabled[vIndexNewToOld[0]] = (*pvvCentroids)[vIndexNewToOld[0]];
    size_t label_count_potential = vvCentroidsLabled[vIndexNewToOld[0]].size();
    for(size_t frm = 1; frm < n; frm++)
        vvCentroidsLabled[vIndexNewToOld[frm]].resize(label_count_potential);

    //remember, if an object is still persistent
    vector<int> vObjectPersistent((*pvvCentroids)[vIndexNewToOld[0]].size(), static_cast<int>(true));

    //qDebug() << "ObjectsMovement" << "Start Frame Loop (Loop" << n-1 << "steps in" << n << "frames), potential labels:" << label_count_potential;

    //loop frames, newest -> oldest, skip oldest one (measurement takes place between two frames)
    for(size_t frm = 0; frm < n-1; frm++)
    {
        //indices of current and previous frames
        size_t idx_frm_curr = vIndexNewToOld[frm];
        size_t idx_frm_prev = vIndexNewToOld[frm+1];

        //qDebug() << "ObjectsMovement" << "loop frm =" << frm << "idx_frm_curr" << idx_frm_curr << "idx_frm_prev" << idx_frm_prev;

        //loop centroids in current frame and see if they are persistent in next frame
        for(size_t lab_check = 0; lab_check < label_count_potential; lab_check++)
        {
            //only search, if object is still a candidate for persistence in all n frames
            if(vObjectPersistent[lab_check])
            {
                //centroid of current label in current frame
                Point2f CentroidCur = vvCentroidsLabled[idx_frm_curr][lab_check];

                //get closest centroid in previous frame
                double dist_min = D_Stat::Optimize_Init(c_OPT_1D_MINIMUM);
                size_t label_closest = 0;

                //loop all potential labels
                size_t label_count_prev = (*pvvCentroids)[idx_frm_prev].size();
                for(size_t lab_comp = 0; lab_comp < label_count_prev; lab_comp++)
                {
                    double dist = D_Math::Distance(
                                CentroidCur,
                                (*pvvCentroids)[idx_frm_prev][lab_comp]);

                    //closer?
                    if(dist < dist_min)
                    {
                        dist_min = dist;
                        label_closest = lab_comp;
                    }
                }
                //closest label in previous frame found

                //closest is in range?
                if(dist_min <= max_Shift_PxPerFrame && label_count_prev != 0)
                {
                    vvCentroidsLabled[idx_frm_prev][lab_check] = (*pvvCentroids)[idx_frm_prev][label_closest];
                }
                else//too far
                {
                    vObjectPersistent[lab_check] = static_cast<int>(false);
                }
            }
        }
    }

    //at this point all persistent centroids are labeled

    //qDebug() << "ObjectsMovement" << "End Frame Loop";

    //number of persistent centroids
    int labels_count_persistent = 0;
    for(size_t lab = 0; lab < label_count_potential; lab++)
        if(vObjectPersistent[lab])
            labels_count_persistent++;

    //resize results containers
    pvShift_PxPerFrame->resize(labels_count_persistent);
    pvDirection_Rad->resize(labels_count_persistent);
    pvPositions->resize(labels_count_persistent);

    //qDebug() << "ObjectsMovement" << "Start Results Export - persistens labels:" << labels_count_persistent;

    //loop labels
    size_t lab_pers = 0;
    for(size_t lab = 0; lab < label_count_potential; lab++)
        if(vObjectPersistent[lab])
        {
            //Newest and oldest centroids
            Point2f Centroid_Newest = vvCentroidsLabled[vIndexNewToOld[0]][lab];
            Point2f Centroid_Oldest = vvCentroidsLabled[vIndexOldToNew[0]][lab];

            /*
            qDebug() << "Label" << lab << "...............";
            for(size_t f = 0; f < n; f++)
                qDebug() << "Centroids in frame" << f << ":" << vvCentroidsLabled[vIndexNewToOld[f]][lab].x << "/" << vvCentroidsLabled[vIndexNewToOld[f]][lab].y;
            */

            //calc shift attributes
            (*pvShift_PxPerFrame)[lab_pers] = D_Math::Distance(Centroid_Oldest, Centroid_Newest) / (n - 1); //(n-1) because there are n-1 gaps between n frames.
            (*pvDirection_Rad)[lab_pers]    = D_Math::AngleRad(Centroid_Oldest, Centroid_Newest);
            (*pvPositions)[lab_pers]        = D_Math::Center(Centroid_Oldest, Centroid_Newest);

            //index for persistent only
            lab_pers++;
        }

    //qDebug() << "ObjectsMovement" << "End" << "================================================================";

    return ER_okay;
}

int D_Img_Proc::ObjectsMovement_Heatmap(Mat *pMA_OutHeatmap, Mat *pMA_OutLegend, Mat *pMA_InValue, vector<vector<Point2f> > vv_FrmObjPositions, vector<vector<double> > vv_FrmObjShifts, vector<vector<double> > vv_FrmObjAngles, double shift_scale, double value_scale, int blur_size_x, int blur_size_y, int mode, int legend_width, int legend_height, double legend_scale, double legend_thickness, size_t legend_examples, double min_rel, double max_rel, double frame2time)
{
    //errors
    if(pMA_InValue->empty())            return ER_empty;
    if(blur_size_x < 1)                 return ER_parameter_bad;
    if(blur_size_y < 1)                 return ER_parameter_bad;
    if(pMA_InValue->channels() != 1)    return ER_channel_bad;
    if(min_rel  < 0 || min_rel  > 1)    return ER_parameter_bad;
    if(max_rel < 0 || max_rel > 1)      return ER_parameter_bad;
    if(min_rel >= max_rel)              return ER_parameter_missmatch;
    if(frame2time <= 0)                 return ER_parameter_bad;
    int ER;

    //qDebug() << "Value img: size" << pMA_InValue->cols << pMA_InValue->rows << "type" << Type_of_Mat(pMA_InValue);

    //img size
    size_t sz_x = pMA_InValue->cols;
    size_t sz_y = pMA_InValue->rows;
    size_t area = sz_x * sz_y;

    //Accumulator images
    Mat MA_tmp_Acc_Count = Mat::zeros(pMA_InValue->size(), CV_64FC1);
    Mat MA_tmp_Acc_Shift = Mat::zeros(pMA_InValue->size(), CV_64FC1);
    Mat MA_tmp_Acc_A_Cos = Mat::zeros(pMA_InValue->size(), CV_64FC1);
    Mat MA_tmp_Acc_A_Sin = Mat::zeros(pMA_InValue->size(), CV_64FC1);
    Mat MA_tmp_Acc_Time  = Mat::zeros(pMA_InValue->size(), CV_64FC1);

    //loop data
    for(size_t frm = 0; frm < vv_FrmObjPositions.size(); frm++)
        for(size_t obj = 0; obj < vv_FrmObjPositions[frm].size(); obj++)
        {
            //get coordinate of movement
            size_t x = static_cast<size_t>(vv_FrmObjPositions[frm][obj].x);
            size_t y = static_cast<size_t>(vv_FrmObjPositions[frm][obj].y);

            //check, if valid coord
            if(x >= 0 && x < sz_x && y >= 0 && y < sz_y)
            {
                //qDebug() << "Found valid movement" << x << y << vv_FrmObjShifts[frm][obj] << vv_FrmObjAngles[frm][obj];

                //accumulate values
                MA_tmp_Acc_Count.at<double>(y, x)++;
                MA_tmp_Acc_Shift.at<double>(y, x) += vv_FrmObjShifts[frm][obj];
                MA_tmp_Acc_A_Sin.at<double>(y, x) += sin(vv_FrmObjAngles[frm][obj]);
                MA_tmp_Acc_A_Cos.at<double>(y, x) += cos(vv_FrmObjAngles[frm][obj]);
                MA_tmp_Acc_Time.at<double>(y, x)   = frm;


                //qDebug() << "Accumulation x/y/count/shift/sin/cos" << x << y << MA_tmp_Acc_Count.at<double>(y, x) << MA_tmp_Acc_Shift.at<double>(y, x) << MA_tmp_Acc_A_Sin.at<double>(y, x) << MA_tmp_Acc_A_Cos.at<double>(y, x);
            }
        }


    //norm accumulated images
    double* ptr_count = reinterpret_cast<double*>(MA_tmp_Acc_Count.data);
    double* ptr_shift = reinterpret_cast<double*>(MA_tmp_Acc_Shift.data);
    double* ptr_a_sin = reinterpret_cast<double*>(MA_tmp_Acc_A_Sin.data);
    double* ptr_a_cos = reinterpret_cast<double*>(MA_tmp_Acc_A_Cos.data);
    double* ptr_time  = reinterpret_cast<double*>(MA_tmp_Acc_Time.data);
    for(size_t px = 0; px < area; px++, ptr_count++, ptr_shift++, ptr_a_cos++, ptr_a_sin++, ptr_time++)
    {
        //norm accumulations
        *ptr_shift = *ptr_count > 0 ? *ptr_shift / *ptr_count : 0;
        *ptr_a_sin = *ptr_count > 0 ? *ptr_a_sin / *ptr_count : 0;
        *ptr_a_cos = *ptr_count > 0 ? *ptr_a_cos / *ptr_count : 0;
        *ptr_time *= frame2time;
    }

    //blur accumulations
    Mat MA_tmp_Mask = Mat::ones(blur_size_x, blur_size_y, CV_64FC1);

    Mat MA_tmp_Mean_Shift;
    ER = Filter_Function(
                &MA_tmp_Mean_Shift,
                &MA_tmp_Acc_Shift,
                &MA_tmp_Mask,
                D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_Y),
                D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_X),
                D_Stat::Function_SingleStat(c_STAT_MEAN_ARITMETIC_OF_NON_ZERO),
                D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_X),
                BORDER_REPLICATE);
    if(ER != ER_okay)
    {
        MA_tmp_Acc_Count.release();
        MA_tmp_Acc_Shift.release();
        MA_tmp_Acc_A_Sin.release();
        MA_tmp_Acc_A_Cos.release();
        MA_tmp_Mask.release();
        MA_tmp_Mean_Shift.release();
        return ER;
    }

    Mat MA_tmp_Mean_A_Cos;
    ER = Filter_Function(
                &MA_tmp_Mean_A_Cos,
                &MA_tmp_Acc_A_Cos,
                &MA_tmp_Mask,
                D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_Y),
                D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_X),
                D_Stat::Function_SingleStat(c_STAT_MEAN_ARITMETIC_OF_NON_ZERO),
                D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_X),
                BORDER_REPLICATE);
    if(ER != ER_okay)
    {
        MA_tmp_Acc_Count.release();
        MA_tmp_Acc_Shift.release();
        MA_tmp_Acc_A_Sin.release();
        MA_tmp_Acc_A_Cos.release();
        MA_tmp_Mask.release();
        MA_tmp_Mean_Shift.release();
        MA_tmp_Mean_A_Cos.release();
        return ER;
    }

    Mat MA_tmp_Mean_A_Sin;
    ER = Filter_Function(
                &MA_tmp_Mean_A_Sin,
                &MA_tmp_Acc_A_Sin,
                &MA_tmp_Mask,
                D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_Y),
                D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_X),
                D_Stat::Function_SingleStat(c_STAT_MEAN_ARITMETIC_OF_NON_ZERO),
                D_Math::Function_2D_to_1D(c_MATH_2D_TO_1D_X),
                BORDER_REPLICATE);
    if(ER != ER_okay)
    {
        MA_tmp_Acc_Count.release();
        MA_tmp_Acc_Shift.release();
        MA_tmp_Acc_A_Sin.release();
        MA_tmp_Acc_A_Cos.release();
        MA_tmp_Mask.release();
        MA_tmp_Mean_Shift.release();
        MA_tmp_Mean_A_Cos.release();
        MA_tmp_Mean_A_Sin.release();
        return ER;
    }

    MA_tmp_Mask.release();

    //newest time is displayed dominant
    Mat MA_tmp_TimeNewest;
    ER = Filter_Maximum_1C(
                &MA_tmp_TimeNewest,
                &MA_tmp_Acc_Time,
                blur_size_x,
                blur_size_y);
    if(ER != ER_okay)
    {
        MA_tmp_Acc_Count.release();
        MA_tmp_Acc_Shift.release();
        MA_tmp_Acc_A_Sin.release();
        MA_tmp_Acc_A_Cos.release();
        MA_tmp_Mean_Shift.release();
        MA_tmp_Mean_A_Cos.release();
        MA_tmp_Mean_A_Sin.release();
        MA_tmp_TimeNewest.release();
        return ER;
    }



    //transform value image to double
    Mat MA_tmp_Value_Double;
    ER = Convert_Double(
                &MA_tmp_Value_Double,
                pMA_InValue);
    if(ER != ER_okay)
    {
        MA_tmp_Acc_Count.release();
        MA_tmp_Acc_Shift.release();
        MA_tmp_Acc_A_Sin.release();
        MA_tmp_Acc_A_Cos.release();
        MA_tmp_Mean_Shift.release();
        MA_tmp_Mean_A_Cos.release();
        MA_tmp_Mean_A_Sin.release();
        MA_tmp_Value_Double.release();
        MA_tmp_TimeNewest.release();
        return ER;
    }

    //get quantiles and range of shifts
    //qDebug() << "get extrema";
    double shift_min, shift_max;
    ER = Quantiles_ofPixelvalues(
                &shift_min,
                &shift_max,
                &MA_tmp_Mean_Shift,
                min_rel,
                max_rel,
                true);
    if(ER != ER_okay)
    {
        MA_tmp_Acc_Count.release();
        MA_tmp_Acc_Shift.release();
        MA_tmp_Acc_A_Sin.release();
        MA_tmp_Acc_A_Cos.release();
        MA_tmp_Mean_Shift.release();
        MA_tmp_Mean_A_Cos.release();
        MA_tmp_Mean_A_Sin.release();
        MA_tmp_Value_Double.release();
        MA_tmp_TimeNewest.release();
        return ER;
    }
    double range_shifts = shift_max - shift_min;
    //qDebug() << "Shift range" << range_shifts << shift_min << shift_max;

    //get range of value
    double value_max, value_min;
    ER = MinMax_of_Mat(
                &MA_tmp_Value_Double,
                &value_min,
                &value_max);
    if(ER != ER_okay)
    {
        MA_tmp_Acc_Count.release();
        MA_tmp_Acc_Shift.release();
        MA_tmp_Acc_A_Sin.release();
        MA_tmp_Acc_A_Cos.release();
        MA_tmp_Mean_Shift.release();
        MA_tmp_Mean_A_Cos.release();
        MA_tmp_Mean_A_Sin.release();
        MA_tmp_Value_Double.release();
        MA_tmp_TimeNewest.release();
        return ER;
    }
    double range_value = value_max - value_min;
    //qDebug() << "Value range" << range_value << value_min << value_max;

    //get range of value
    double time_max, time_min;
    ER = MinMax_of_Mat(
                &MA_tmp_TimeNewest,
                &time_min,
                &time_max);
    if(ER != ER_okay)
    {
        MA_tmp_Acc_Count.release();
        MA_tmp_Acc_Shift.release();
        MA_tmp_Acc_A_Sin.release();
        MA_tmp_Acc_A_Cos.release();
        MA_tmp_Mean_Shift.release();
        MA_tmp_Mean_A_Cos.release();
        MA_tmp_Mean_A_Sin.release();
        MA_tmp_Value_Double.release();
        MA_tmp_TimeNewest.release();
        return ER;
    }
    double range_time = time_max - time_min;


    //alloc out
    *pMA_OutHeatmap = Mat(pMA_InValue->size(), CV_64FC3);

    //invers HSV transform
    double* ptr_value   = reinterpret_cast<double*>(MA_tmp_Value_Double.data);
    ptr_shift           = reinterpret_cast<double*>(MA_tmp_Mean_Shift.data);
    ptr_a_sin           = reinterpret_cast<double*>(MA_tmp_Mean_A_Sin.data);
    ptr_a_cos           = reinterpret_cast<double*>(MA_tmp_Mean_A_Cos.data);
    ptr_time            = reinterpret_cast<double*>(MA_tmp_TimeNewest.data);
    Vec3d* ptr_out      = reinterpret_cast<Vec3d*>(pMA_OutHeatmap->data);
    for(size_t px = 0; px < area; px++, ptr_shift++, ptr_a_cos++, ptr_a_sin++, ptr_value++, ptr_out++, ptr_time++)
    {
        double shift = *ptr_shift;
        if(shift < shift_min)   shift = shift_min;
        if(shift > shift_max)   shift = shift_max;

        double H;
        double S;
        double V;
        if(mode == 0)//speed only
        {
            H           = range_shifts > 0 ? ((2/3.0) * PI_2_0) * (1 - ((shift - shift_min) / range_shifts)) : ((2/3.0) * PI_2_0);
            S           = 1;
            V           = (range_value > 0) ? ((*ptr_value - value_min) / range_value) : 0;
        }
        else if(mode == 1)//angle only
        {
            H           = atan2(*ptr_a_cos, *ptr_a_sin);
            if(H < 0)   H += PI_2_0;
            S           = 1;
            V           = (range_value > 0) && ((abs(*ptr_a_cos) + abs(*ptr_a_sin)) > 0) ? ((*ptr_value - value_min) / range_value) : 0;
        }
        else if(mode == 2)//both (speed and angle)
        {
            H           = atan2(*ptr_a_cos, *ptr_a_sin);
            if(H < 0)   H += PI_2_0;
            S           = range_shifts > 0 ? (shift - shift_min) / range_shifts : 0;
            V           = (range_value > 0) && ((abs(*ptr_a_cos) + abs(*ptr_a_sin)) > 0) ? ((*ptr_value - value_min) / range_value) : 0;
        }
        else//time
        {
            H           = ((time_max - *ptr_time) / range_time) * ((2/3.0) * PI_2_0);
            S           = *ptr_value > 0 ? 1 : 0;
            V           = (range_value > 0)  && (*ptr_time > 0) ? ((*ptr_value - value_min) / range_value) : 0;
        }

        int     hi      = floor(H / (PI / 3.0));
        double  f       = (H / (PI / 3.0)) - hi;
        double  p       = V * (1 - S);
        double  q       = V * (1 - (S * f));
        double  t       = V * (1 - (S * (1 - f)));

        //invers HSV Transfrom
        double R, G, B;
        switch (hi) {
        case 1:     R = q;      G = V;      B = p;      break;
        case 2:     R = p;      G = V;      B = t;      break;
        case 3:     R = p;      G = q;      B = V;      break;
        case 4:     R = t;      G = p;      B = V;      break;
        case 5:     R = V;      G = p;      B = q;      break;
        default:    R = V;      G = t;      B = p;      break;}

        //if(V != 0) qDebug() << "HSV" << H << S << V << "RGB" << R << G << B;

        *ptr_out = Vec3d(B, G, R);
    }

    //Legend
    QStringList QSL_H;
    QStringList QSL_S;
    QStringList QSL_V;
    QString QS_H;
    QString QS_S;
    QString QS_V;
    double H_angle_min = 0;
    double H_angle_range = PI_2_0;
    switch (mode) {

    case 0://speed only
    {
        QS_H = "Speed um/s";
        QS_S = "-";
        QS_V = "\"Count\"";
        H_angle_range = (2/3.0) * PI_2_0;
        for(size_t i = 0; i < legend_examples; i++)
        {
            if(i == 0)
                QSL_H.append("<=" + QString::number(((legend_examples - 1 - i) * (range_shifts / static_cast<double>(legend_examples-1)) * shift_scale) + shift_min, 'g', 3));
            else if(i == legend_examples - 1)
                QSL_H.append(">=" + QString::number(((legend_examples - 1 - i) * (range_shifts / static_cast<double>(legend_examples-1)) * shift_scale) + shift_min, 'g', 3));
            else
                QSL_H.append(QString::number(((legend_examples - 1 - i) * (range_shifts / static_cast<double>(legend_examples-1)) * shift_scale) + shift_min, 'g', 3));

            QSL_S.append("-");
            QSL_V.append(QString::number((i * (range_value / static_cast<double>(legend_examples-1)) * value_scale) + value_min, 'g', 3));
        }
    }
        break;

    case 1://angle only
    {
        QS_H = "Angle deg";
        QS_S = "-";
        QS_V = "\"Count\"";
        for(size_t i = 0; i < legend_examples; i++)
        {
            double h = i * (360.0 / static_cast<double>(legend_examples-1));
            if(h > 180.0) h -= 360.0;
            QSL_H.append(QString::number(h, 'g', 3));
            QSL_S.append("-");
            QSL_V.append(QString::number((i * (range_value / static_cast<double>(legend_examples-1)) * value_scale) + value_min, 'g', 3));
        }
    }
        break;

    case 2://both (speed and angle)
    {
        QS_H = "Angle deg";
        QS_S = "Speed um/s";
        QS_V = "\"Count\"";
        for(size_t i = 0; i < legend_examples; i++)
        {
            double h = i * (360.0 / static_cast<double>(legend_examples-1));
            if(h > 180.0) h -= 360.0;
            QSL_H.append(QString::number(h, 'g', 3));

            if(i == 0)
                QSL_S.append("<=" + QString::number((i * (range_shifts / static_cast<double>(legend_examples-1)) * shift_scale) + shift_min, 'g', 3));
            else if(i == legend_examples - 1)
                QSL_S.append(">=" + QString::number((i * (range_shifts / static_cast<double>(legend_examples-1)) * shift_scale) + shift_min, 'g', 3));
            else
                QSL_S.append(QString::number((i * (range_shifts / static_cast<double>(legend_examples-1)) * shift_scale) + shift_min, 'g', 3));

            QSL_V.append(QString::number((i * (range_value / static_cast<double>(legend_examples-1)) * value_scale) + value_min, 'g', 3));
        }
    }
        break;

    case 3://time
    {
        QS_H = "Time s";
        QS_S = "-";
        QS_V = "\"Count\"";
        H_angle_range = (2/3.0) * PI_2_0;
        for(size_t i = 0; i < legend_examples; i++)
        {
            QSL_H.append(QString::number(((legend_examples - 1 - i) * (range_time / static_cast<double>(legend_examples-1))), 'g', 3));
            QSL_S.append("-");
            QSL_V.append(QString::number((i * (range_value / static_cast<double>(legend_examples-1)) * value_scale) + value_min, 'g', 3));
        }
    }
        break;

    default:
    {
        MA_tmp_Acc_Count.release();
        MA_tmp_Acc_Shift.release();
        MA_tmp_Acc_A_Sin.release();
        MA_tmp_Acc_A_Cos.release();
        MA_tmp_Mean_Shift.release();
        MA_tmp_Mean_A_Cos.release();
        MA_tmp_Mean_A_Sin.release();
        MA_tmp_Value_Double.release();
        MA_tmp_TimeNewest.release();
        return ER_parameter_bad;
    }
        break;
    }

    ER = Legend_HSV(
                pMA_OutLegend,
                legend_width,
                legend_height,
                QSL_H,
                QSL_S,
                QSL_V,
                QS_H,
                QS_S,
                QS_V,
                H_angle_min,
                H_angle_range);


    MA_tmp_Acc_Count.release();
    MA_tmp_Acc_Shift.release();
    MA_tmp_Acc_A_Sin.release();
    MA_tmp_Acc_A_Cos.release();
    MA_tmp_Mean_Shift.release();
    MA_tmp_Mean_A_Cos.release();
    MA_tmp_Mean_A_Sin.release();
    MA_tmp_Value_Double.release();
    MA_tmp_TimeNewest.release();
    return ER;
}


int D_Img_Proc::DistancesStat(Mat *pMA_Out, Mat *pMA_In, function<double (vector<double>)> F_Stat)
{
    if(pMA_In->empty())             return ER_empty;
    if(pMA_In->type() != CV_8UC1)   return ER_type_bad;

    //init
    *pMA_Out = Mat::zeros(pMA_In->rows, pMA_In->cols, CV_64FC1);

    //get FG points
    vector<Point> vFG;
    for(int y = 0; y < pMA_In->rows; y++)
        for(int x = 0; x < pMA_In->cols; x++)
            if(pMA_In->at<uchar>(y, x))
                vFG.push_back(Point(x, y));

    //get distances and stat
    vector<double> vDist(vFG.size(), 0);
    for(int y = 0; y < pMA_In->rows; y++)
        for(int x = 0; x < pMA_In->cols; x++)
        {
            for(size_t f = 0; f < vFG.size(); f++)
            {
                double dx = x - vFG[f].x;
                double dy = y - vFG[f].y;
                vDist[f] = sqrt(dx * dx + dy * dy);
            }

            pMA_Out->at<double>(y, x) = F_Stat(vDist);
        }

    return ER_okay;
}

int D_Img_Proc::RadiometricStereo(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, double S1X, double S1Y, double S1Z, double S2X, double S2Y, double S2Z, double S3X, double S3Y, double S3Z, int out_mode)
{
    Mat S = Mat::zeros(3, 3, CV_64FC1);
    S.at<double>(0, 0) = S1X;
    S.at<double>(0, 1) = S1Y;
    S.at<double>(0, 2) = S1Z;
    S.at<double>(1, 0) = S2X;
    S.at<double>(1, 1) = S2Y;
    S.at<double>(1, 2) = S2Z;
    S.at<double>(2, 0) = S3X;
    S.at<double>(2, 1) = S3Y;
    S.at<double>(2, 2) = S3Z;

    return RadiometricStereo(
                pMA_Out,
                pMA_In1,
                pMA_In2,
                pMA_In3,
                S,
                out_mode);
}

int D_Img_Proc::RadiometricStereo(Mat *pMA_Out, Mat *pMA_In1, Mat *pMA_In2, Mat *pMA_In3, Mat S, int out_mode)
{
    //check errors
    if(pMA_In1->empty())                    return ER_empty;
    if(pMA_In2->empty())                    return ER_empty;
    if(pMA_In3->empty())                    return ER_empty;
    if(pMA_In1->size != pMA_In2->size)      return ER_size_missmatch;
    if(pMA_In1->size != pMA_In3->size)      return ER_size_missmatch;
    if(pMA_In1->type() != CV_8UC1)          return ER_type_bad;
    if(pMA_In2->type() != CV_8UC1)          return ER_type_bad;
    if(pMA_In3->type() != CV_8UC1)          return ER_type_bad;
    if(S.type() != CV_64FC1)                return ER_type_bad;
    if(S.cols != 3)                         return ER_size_bad;
    if(S.rows != 3)                         return ER_size_bad;
    if(out_mode < 0)                        return ER_parameter_bad;
    if(out_mode >= c_STEREO_NUMBER_OF)      return ER_parameter_bad;
    if(determinant(S) == 0)                 return ER_MatrixNotInvertable;

    //invert S
    Mat S_inv = S.inv();

    //init out
    if(out_mode == c_STEREO_ALBEDO)
        *pMA_Out = Mat::zeros(pMA_In1->size(), CV_64FC1);
    else if(out_mode == c_STEREO_NORMAL)
        *pMA_Out = Mat::zeros(pMA_In1->size(), CV_64FC3);

    //data pointers
    uchar* ptr_in1 = reinterpret_cast<uchar*>(pMA_In1->data);
    uchar* ptr_in2 = reinterpret_cast<uchar*>(pMA_In2->data);
    uchar* ptr_in3 = reinterpret_cast<uchar*>(pMA_In3->data);

    //Input values
    Mat I = Mat::zeros(3, 1, CV_64FC1);

    //select mode and loop image
    if(out_mode == c_STEREO_ALBEDO)
    {
        uchar* ptr_out = reinterpret_cast<uchar*>(pMA_Out->data);
        for(int px = 0; px < pMA_Out->cols * pMA_Out->rows; px++, ptr_in1++, ptr_in2++, ptr_in3++, ptr_out++)
        {
            I.at<double>(0, 0) = static_cast<double>(*ptr_in1);
            I.at<double>(1, 0) = static_cast<double>(*ptr_in2);
            I.at<double>(2, 0) = static_cast<double>(*ptr_in3);
            Mat M = S_inv * I;
            Mat Mpow2 = M.mul(M);
            *ptr_out = sqrt(Mpow2.dot(Mpow2));
        }
    }
    else if(out_mode == c_STEREO_NORMAL)
    {
        Vec3d* ptr_out = reinterpret_cast<Vec3d*>(pMA_Out->data);
        for(int px = 0; px < pMA_Out->cols * pMA_Out->rows; px++, ptr_in1++, ptr_in2++, ptr_in3++, ptr_out++)
        {
            I.at<double>(0, 0) = static_cast<double>(*ptr_in1);
            I.at<double>(1, 0) = static_cast<double>(*ptr_in2);
            I.at<double>(2, 0) = static_cast<double>(*ptr_in3);
            Mat M = S_inv * I;
            Mat Mpow2 = M.mul(M);
            double p = sqrt(Mpow2.dot(Mpow2));
            Mat n = M * (1/p);
            *ptr_out = Vec3d(n.at<double>(0, 0), n.at<double>(1, 0), n.at<double>(2, 0));
        }
    }

    return ER_okay;
}

int D_Img_Proc::InterferometerMichelson(Mat *pMA_Out, int scene_size_x_px, int scene_size_y_px, int scale_px, double scale_m, double wavelength_m, double dist_source_m, double dist_detector_m, double dist_mirror1_m, double dist_mirror2_m, double angle_mirror1_m, double angle_mirror1_y, double angle_mirror2_x, double angle_mirror2_y)
{
    //errors
    if(scene_size_x_px < 6)         return ER_parameter_bad;
    if(scene_size_y_px < 6)         return ER_parameter_bad;

    //init out
    *pMA_Out = Mat::zeros(scene_size_x_px, scene_size_y_px, CV_64FC1);

    //coordinates of objects (splitter centric)
    Point3f P_SP(0,                   0               , 1);   //Splitter
    Point3f P_M1(dist_mirror1_m,      0               , 1);   //Mirror 1
    Point3f P_M2(0,                   dist_mirror2_m  , 1);   //Mirror 2
    Point3f P_SO(0,                   -dist_source_m  , 1);   //Source
    Point3f P_DE(-dist_detector_m,    0               , 1);   //Detector

    //path A: Source -> Splitter refelect   -> Mirror2 -> Splitter pass     -> Detector
    //path B: Source -> Splitter refelect   -> Mirror2 -> Splitter reflect  -> Source
    //path C: Source -> Splitter pass       -> Mirror1 -> Splitter reflect  -> Detector
    //path D: Source -> Splitter pass       -> Mirror1 -> Splitter pass     -> Source

    //init out
    *pMA_Out = Mat::zeros(scene_size_x_px, scene_size_y_px, CV_64FC1);

    //zone between splitter and



            /*
    //loop
    for(int y = 0; y < scene_size_y_px; y++)
        for(int x = 0; x < scene_size_x_px; x++)
        {
            Point2f P_calc(x, y);
            Point2f P_
        }
                */

    return ER_okay;
}

int D_Img_Proc::Draw_Label_Numbers_Corner(Mat *pMA_Out, Mat *pMA_Label, double scale, double thickness)
{
    if(pMA_Label->empty())                                                  return ER_empty;
    if(pMA_Label->channels() != 1)                                          return ER_channel_bad;
    if((pMA_Label->depth() != CV_16U) && (pMA_Label->depth() != CV_32S))    return ER_type_bad;

    *pMA_Out = Mat(pMA_Label->size(), CV_8UC1, Scalar(0));

    unsigned int label_number = 1;

    if(pMA_Label->type() == CV_16UC1)
    {
        for(int y = 0; y < pMA_Label->rows; y++)
            for(int x = 0; x < pMA_Label->cols; x++)
                if(pMA_Label->at<ushort>(y, x) == label_number)
                {
                    putText(
                                *pMA_Out,
                                to_string(label_number),
                                cvPoint(x, y),
                                FONT_HERSHEY_COMPLEX_SMALL,
                                scale,
                                Scalar(255),
                                thickness,
                                CV_AA);
                    label_number++;
                }
    }
    else
    {
        for(int y = 0; y < pMA_Label->rows; y++)
            for(int x = 0; x < pMA_Label->cols; x++)
                if(pMA_Label->at<int>(y, x) == label_number)
                {
                    putText(
                                *pMA_Out,
                                to_string(label_number),
                                cvPoint(x, y),
                                FONT_HERSHEY_COMPLEX_SMALL,
                                scale,
                                Scalar(255),
                                thickness,
                                CV_AA);
                    label_number++;
                }
    }

    return ER_okay;
}
