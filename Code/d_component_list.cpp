/************************************
 *   added:     30.11.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_component_list.h"

D_Component_List::D_Component_List()
{
    //qDebug() << "D_Component_List - standard constructor";
}

D_Component_List::D_Component_List(Mat *pMA_BinaryOrLabel, int connectivity)
{
    //qDebug() << "D_Component_List - mat constructor";
    set_Mat(pMA_BinaryOrLabel, connectivity);
}

int D_Component_List::set_Mat(Mat *pMA_BinaryOrLabel, int connectivity)
{
    //qDebug() << "D_Component_List - set Mats";

    initialized = false;

    if(pMA_BinaryOrLabel->empty())                                                                                                  return ER_empty;
    if(pMA_BinaryOrLabel->channels() != 1)                                                                                          return ER_channel_bad;
    if((connectivity != 4) && (connectivity != 8))                                                                                  return ER_parameter_bad;
    if((pMA_BinaryOrLabel->depth() != CV_8U) && (pMA_BinaryOrLabel->depth() != CV_16U) && (pMA_BinaryOrLabel->depth() != CV_32S))   return ER_bitdepth_bad;

    //treat 8U as binary/to_label and 16U/32S as labeled image

    int     area        = pMA_BinaryOrLabel->rows * pMA_BinaryOrLabel->cols;

    //binary
    MA_Binary           = Mat::zeros(pMA_BinaryOrLabel->size(), CV_8UC1);
    uchar*  ptr_bin     = reinterpret_cast<uchar*>(MA_Binary.data);

    //label
    MA_Labels           = Mat(pMA_BinaryOrLabel->size(), CV_32SC1);
    int*    ptr_label   = reinterpret_cast<int*>(MA_Labels.data);


    //qDebug() << "D_Component_List - type switch";

    switch (pMA_BinaryOrLabel->type()) {

    case CV_8UC1:
    {
        //qDebug() << "D_Component_List - 8UC1";

        //binary
        uchar*  ptr_init    = reinterpret_cast<uchar*>(pMA_BinaryOrLabel->data);
        for(int px = 0; px < area; px++, ptr_init++, ptr_bin++)
            if(*ptr_init)
                *ptr_bin = 255;

        //label
        connectedComponents(
                    MA_Binary,
                    MA_Labels,
                    connectivity,
                    CV_32SC1);
    }
        break;

    case CV_16UC1:
    {
        //qDebug() << "D_Component_List - 16UC1";

        //binary
        ushort*  ptr_init   = reinterpret_cast<ushort*>(pMA_BinaryOrLabel->data);
        for(int px = 0; px < area; px++, ptr_init++, ptr_bin++, ptr_label++)
        {
            //binary
            if(*ptr_init)
                *ptr_bin = 255;

            //label
            *ptr_label = static_cast<int>(*ptr_init);
        }
    }
        break;

    case CV_32SC1:
    {
        //qDebug() << "D_Component_List - 32SC1";

        //binary
        int*    ptr_init    = reinterpret_cast<int*>(pMA_BinaryOrLabel->data);
        for(int px = 0; px < area; px++, ptr_init++, ptr_bin++)
            if(*ptr_init)
                *ptr_bin = 255;

        //label
        MA_Labels = pMA_BinaryOrLabel->clone();
    }

        break;

    default:
        break;
    }

    /*
    qDebug() << "save mat";
    Mat MA_tmp_label_norm;
    normalize(MA_Labels, MA_tmp_label_norm, 0, 255, CV_MINMAX, CV_8UC1);
    imwrite(("c/Binary Mat.jpg"), MA_Binary);
    imwrite(("D:/David_Eilenstein/ImageD/StepsStream/stack_test/Labels Mat.jpg"), MA_tmp_label_norm);
    */

    initialized = true;
    return Split_Labels_2_Components();
}

vector<double> D_Component_List::get_FeatureVector(int feature)
{
    //allocate
    vector<double> v_Features;
    v_Features.resize(m_Components.size());

    //get values
    for(size_t c = 0; c < m_Components.size(); c++)
        v_Features[c] = m_Components[c].get_Feature(feature);

    return v_Features;
}

vector<double> D_Component_List::get_FeatureVector_BG(int feature)
{
    //allocate
    vector<double> v_Features;
    v_Features.resize(m_Components.size() + 1);

    //add background
    v_Features[0] = 0;

    //get values
    for(size_t c = 0; c < m_Components.size(); c++)
        v_Features[c + 1] = m_Components[c].get_Feature(feature);

    return v_Features;
}

vector<Point2f> D_Component_List::get_CentroidVector()
{
    //allocate
    vector<Point2f> v_Centroids;
    v_Centroids.resize(m_Components.size());

    //get values
    for(size_t c = 0; c < m_Components.size(); c++)
        v_Centroids[c] = m_Components[c].get_Centroid();

    return v_Centroids;
}

vector<Point2f> D_Component_List::get_CentroidVector_BG()
{
    //allocate
    vector<Point2f> v_Centroids;
    v_Centroids.resize(m_Components.size() + 1);

    //add background
    v_Centroids[0] = Point2f(0, 0);

    //get values
    for(size_t c = 0; c < m_Components.size(); c++)
        v_Centroids[c + 1] = m_Components[c].get_Centroid();

    return v_Centroids;
}

vector<Point> D_Component_List::get_OffsetVector()
{
    //allocate
    vector<Point> v_Offsets;
    v_Offsets.resize(m_Components.size());

    //get values
    for(size_t c = 0; c < m_Components.size(); c++)
        v_Offsets[c] = m_Components[c].get_Offset();

    return v_Offsets;
}

vector<Point2f> D_Component_List::get_OffsetVector_2f()
{
    //allocate
    vector<Point2f> v_Offsets;
    v_Offsets.resize(m_Components.size());

    //get values
    for(size_t c = 0; c < m_Components.size(); c++)
        v_Offsets[c] = Point2f(m_Components[c].get_Offset());

    return v_Offsets;
}

vector<Point> D_Component_List::get_OffsetVector_BG()
{
    //allocate
    vector<Point> v_Offsets;
    v_Offsets.resize(m_Components.size() + 1);

    //add background
    v_Offsets[0] = Point(0, 0);

    //get values
    for(size_t c = 0; c < m_Components.size(); c++)
        v_Offsets[c + 1] = m_Components[c].get_Offset();

    return v_Offsets;
}



vector<vector<Point> > D_Component_List::get_ContourVector()
{
    //allocate
    vector<vector<Point>> vv_Contours;
    vv_Contours.resize(m_Components.size());

    //get values
    for(size_t c = 0; c < m_Components.size(); c++)
        vv_Contours[c] = m_Components[c].get_Contour();

    return vv_Contours;
}

vector<vector<Point> > D_Component_List::get_ContourVector_BG()
{
    //allocate
    vector<vector<Point>> vv_Contours;
    vv_Contours.resize(m_Components.size() + 1);

    //add background
    vector<Point> v_background;
    v_background.push_back(Point(0, 0));
    vv_Contours[0] = v_background;

    //get values
    for(size_t c = 0; c < m_Components.size(); c++)
        vv_Contours[c] = m_Components[c].get_Contour();

    return vv_Contours;
}

vector<vector<Point> > D_Component_List::get_ContourVector_ConvexHull()
{
    //allocate
    vector<vector<Point>> vv_ContoursConvex;
    vv_ContoursConvex.resize(m_Components.size());

    //get values
    for(size_t c = 0; c < m_Components.size(); c++)
        vv_ContoursConvex[c] = m_Components[c].get_Contour_ConvexHull();

    return vv_ContoursConvex;
}

vector<Rect> D_Component_List::get_BndBox_Rect_Vector()
{
    //allocate
    vector<Rect> v_BndBox;
    v_BndBox.resize(m_Components.size());

    //get values
    for(size_t c = 0; c < m_Components.size(); c++)
        v_BndBox[c] = m_Components[c].get_BndBox_Rect();

    return v_BndBox;
}

vector<RotatedRect> D_Component_List::get_BndBox_Rotate_Vector()
{
    //allocate
    vector<RotatedRect> v_BndBox_Rot;
    v_BndBox_Rot.resize(m_Components.size());

    //get values
    for(size_t c = 0; c < m_Components.size(); c++)
        v_BndBox_Rot[c] = m_Components[c].get_BndBox_Rotate();

    return v_BndBox_Rot;
}

vector<RotatedRect> D_Component_List::get_Ellipse_Fitted_Vector()
{
    //allocate
    vector<RotatedRect> v_Ellipse;
    v_Ellipse.resize(m_Components.size());

    //get values
    for(size_t c = 0; c < m_Components.size(); c++)
        v_Ellipse[c] = m_Components[c].get_Ellipse_Fitted();

    return v_Ellipse;
}

void D_Component_List::Components_Updated()
{

}

void D_Component_List::save_all(QString path_dir)
{
    //create dir
    DIR_Save.setPath(path_dir);
    if(!DIR_Save.exists())
        QDir().mkdir(path_dir);

    //save mats
    for(size_t c = 0; c < m_Components.size(); c++)
        imwrite(
                    DIR_Save.path().toStdString() + "/Component_" + (QString::number(c)).toStdString() + ".jpg",
                    *(m_Components[c].get_pMat()));

    //open stream
    OS_Save.open(DIR_Save.path().toStdString() + "/Features.csv");

    //Feature list
    OS_Save << "Component";
    for(int f = 0; f < c_FEAT_NUMBER_OF_FEATS; f++)
        OS_Save << "," << QSL_FeatureList[f].toStdString();
    OS_Save << "\n\n";

    //feature values
    for(size_t c = 0; c < m_Components.size(); c++)
    {
        OS_Save << c;
        for(int f = 0; f < c_FEAT_NUMBER_OF_FEATS; f++)
            OS_Save << "," << m_Components[c].get_Feature(f);
        OS_Save << "\n";
    }

    //close stream
    OS_Save.close();
}

int D_Component_List::Split_Labels_2_Components()
{
    //qDebug() << "D_Component_List - labeles -> components";

    //values
    int width = MA_Labels.cols;
    int heigth = MA_Labels.rows;
    double min, max;

    //number of components
    minMaxLoc(
                MA_Labels,
                &min,
                &max);
    m_Components.resize(max);

    //loop image and get coords
    for(int y = 0; y < heigth; y++)
    {
        for(int x = 0; x < width; x++)
        {
            int val = MA_Labels.at<int>(y, x);

            if(val > 0)
            {
                m_Components[val - 1].add_Point(x, y);
            }
        }
    }

    for(size_t l = 0; l < m_Components.size(); l++)
    {
        m_Components[l].set_Number(l);
        m_Components[l].Calc_All();
    }

    return ER_okay;
}




