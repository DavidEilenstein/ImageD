/************************************
 *   added:     04.01.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_bio_nucleusimage.h"

D_Bio_NucleusImage::D_Bio_NucleusImage()
{

}

D_Bio_NucleusImage::D_Bio_NucleusImage(Mat *pMA_NucleiBinary, vector<Mat> *pvMA_FociBinary, vector<Mat> *pvMA_Values, Point P_Offset, size_t time, int neighborhood, bool blockSave_StichBorder_BottomRight, size_t block_x_right, size_t block_y_bottom)
{
    calc_NucleiDecomposition(pMA_NucleiBinary, pvMA_FociBinary, pvMA_Values, P_Offset, time, neighborhood, blockSave_StichBorder_BottomRight, block_x_right, block_y_bottom);
}

D_Bio_NucleusImage::D_Bio_NucleusImage(D_VisDat_Obj *pVD_NucleiBinary, vector<D_VisDat_Obj> *pvVD_FociBinary, vector<D_VisDat_Obj> *pvVD_Values, Point P_Offset, size_t time, int neighborhood, bool blockSave_StichBorder_BottomRight, size_t block_x_right, size_t block_y_bottom)
{
    calc_NucleiDecomposition(pVD_NucleiBinary, pvVD_FociBinary, pvVD_Values, P_Offset, time, neighborhood, blockSave_StichBorder_BottomRight, block_x_right, block_y_bottom);
}

D_Bio_NucleusImage::D_Bio_NucleusImage(vector<D_VisDat_Obj> *pvVD_Images, size_t index_NucleiBinary, vector<size_t> vIndices_FociBinary, vector<size_t> vIndices_Values, Point P_Offset, size_t time, int neighborhood, bool blockSave_StichBorder_BottomRight, size_t block_x_right, size_t block_y_bottom)
{
    calc_NucleiDecomposition(pvVD_Images, index_NucleiBinary, vIndices_FociBinary, vIndices_Values, P_Offset, time, neighborhood, blockSave_StichBorder_BottomRight, block_x_right, block_y_bottom);
}

int D_Bio_NucleusImage::calc_NucleiDecomposition(D_VisDat_Obj *pVD_NucleiBinary, vector<D_VisDat_Obj> *pvVD_FociBinary, vector<D_VisDat_Obj> *pvVD_Values, Point P_Offset, size_t time, int neighborhood, bool blockSave_StichBorder_BottomRight, size_t block_x_right, size_t block_y_bottom)
{
    //error code
    int ER = ER_okay;

    //counts
    size_t n_channels_foci = pvVD_FociBinary->size();
    size_t n_channels_values = pvVD_Values->size();

    //slice for extraction
    D_VisDat_Slice_2D slice_simple2Dimage(-1, -1, 0, 0, 0, 0);

    //foci segmentation
    vector<Mat> vMA_FociBinary(n_channels_foci);
    for(size_t i = 0; i < n_channels_foci; i++)
    {
        ER = D_VisDat_Proc::Read_2D_Plane(
                    &(vMA_FociBinary[i]),
                    &((*pvVD_FociBinary)[i]),
                    slice_simple2Dimage);

        if(ER != ER_okay)
        {
            qDebug() << "D_Bio_NucleusImage performing D_VisDat_Proc::Read_2D_Plane at" << i << "with vpVD_FociBinary -> vMA_FociBinary failed:" << QSL_Errors[ER];
            return ER;
        }
    }

    //values
    vector<Mat> vMA_Values(n_channels_values);
    for(size_t i = 0; i < n_channels_values; i++)
    {
        ER = D_VisDat_Proc::Read_2D_Plane(
                    &(vMA_Values[i]),
                    &((*pvVD_Values)[i]),
                    slice_simple2Dimage);

        if(ER != ER_okay)
        {
            qDebug() << "D_Bio_NucleusImage performing D_VisDat_Proc::Read_2D_Plane at" << i << "with vpVD_Values -> vMA_Values failed:" << QSL_Errors[ER];
            return ER;
        }
    }

    //nucleui segmentation
    Mat MA_NucleiBinary;
    ER = D_VisDat_Proc::Read_2D_Plane(
                &MA_NucleiBinary,
                pVD_NucleiBinary,
                slice_simple2Dimage);

    if(ER != ER_okay)
    {
        qDebug() << "D_Bio_NucleusImage performing D_VisDat_Proc::Read_2D_Plane with pVD_NucleiBinary -> MA_NucleiBinary failed:" << QSL_Errors[ER];
        MA_NucleiBinary.release();
        return ER;
    }


    //call Mat version of this function
    ER = calc_NucleiDecomposition(&MA_NucleiBinary, &vMA_FociBinary, &vMA_Values, P_Offset, time, neighborhood, blockSave_StichBorder_BottomRight, block_x_right, block_y_bottom);

    //finish
    MA_NucleiBinary.release();
    return ER;
}

int D_Bio_NucleusImage::calc_NucleiDecomposition(vector<D_VisDat_Obj> *pvVD_Images, size_t index_NucleiBinary, vector<size_t> vIndices_FociBinary, vector<size_t> vIndices_Values, Point P_Offset, size_t time, int neighborhood, bool blockSave_StichBorder_BottomRight, size_t block_x_right, size_t block_y_bottom)
{
    //error code
    int ER = ER_okay;

    //counts
    size_t n_channels_foci = vIndices_FociBinary.size();
    size_t n_channels_values = vIndices_Values.size();

    //slice for extraction
    D_VisDat_Slice_2D slice_simple2Dimage(-1, -1, 0, 0, 0, 0);

    //foci segmentation
    vector<Mat> vMA_FociBinary(n_channels_foci);
    for(size_t i = 0; i < n_channels_foci; i++)
    {
        ER = D_VisDat_Proc::Read_2D_Plane(
                    &(vMA_FociBinary[i]),
                    &((*pvVD_Images)[vIndices_FociBinary[i]]),
                    slice_simple2Dimage);

        if(ER != ER_okay)
        {
            qDebug() << "D_Bio_NucleusImage performing D_VisDat_Proc::Read_2D_Plane at" << i << "with vpVD_FociBinary -> vMA_FociBinary failed:" << QSL_Errors[ER];
            return ER;
        }
    }

    //values
    vector<Mat> vMA_Values(n_channels_values);
    for(size_t i = 0; i < n_channels_values; i++)
    {
        ER = D_VisDat_Proc::Read_2D_Plane(
                    &(vMA_Values[i]),
                    &((*pvVD_Images)[vIndices_Values[i]]),
                    slice_simple2Dimage);

        if(ER != ER_okay)
        {
            qDebug() << "D_Bio_NucleusImage performing D_VisDat_Proc::Read_2D_Plane at" << i << "with vpVD_Values -> vMA_Values failed:" << QSL_Errors[ER];
            return ER;
        }
    }

    //nucleui segmentation
    Mat MA_NucleiBinary;
    ER = D_VisDat_Proc::Read_2D_Plane(
                &MA_NucleiBinary,
                &(*pvVD_Images)[index_NucleiBinary],
                slice_simple2Dimage);

    if(ER != ER_okay)
    {
        qDebug() << "D_Bio_NucleusImage performing D_VisDat_Proc::Read_2D_Plane with pVD_NucleiBinary -> MA_NucleiBinary failed:" << QSL_Errors[ER];
        MA_NucleiBinary.release();
        return ER;
    }


    //call Mat version of this function
    ER = calc_NucleiDecomposition(&MA_NucleiBinary, &vMA_FociBinary, &vMA_Values, P_Offset, time, neighborhood, blockSave_StichBorder_BottomRight, block_x_right, block_y_bottom);

    //finish
    MA_NucleiBinary.release();
    return ER;
}

int D_Bio_NucleusImage::calc_NucleiDecomposition(Mat *pMA_NucleiBinary, vector<Mat> *pvMA_FociBinary, vector<Mat> *pvMA_Values, Point P_Offset, size_t time, int neighborhood, bool blockSave_StichBorder_BottomRight, size_t block_x_right, size_t block_y_bottom)
{
    //qDebug() << "calc_NucleiDecomposition" << "Start";

    //save
    m_time = time;
    m_Offset = P_Offset;

    //counts
    size_t n_channels_foci = pvMA_FociBinary->size();
    size_t n_channels_values = pvMA_Values->size();

    //Errors
    int ER;
    //qDebug() << "calc_NucleiDecomposition" << "Errors";

    //empty
    //channels
    if(pMA_NucleiBinary->empty())
        return ER_empty;
    for(size_t i = 0; i < n_channels_foci; i++)
        if((*pvMA_FociBinary)[i].empty())
            return ER_empty;
    for(size_t i = 0; i < n_channels_values; i++)
        if((*pvMA_Values)[i].empty())
            return ER_empty;

    //size
    for(size_t i = 0; i < n_channels_foci; i++)
        if(pMA_NucleiBinary->size != (*pvMA_FociBinary)[i].size)
            return ER_size_missmatch;
    for(size_t i = 0; i < n_channels_values; i++)
        if(pMA_NucleiBinary->size != (*pvMA_Values)[i].size)
            return ER_size_missmatch;

    //channels
    if(pMA_NucleiBinary->channels() != 1)
        return ER_channel_bad;
    for(size_t i = 0; i < n_channels_foci; i++)
        if((*pvMA_FociBinary)[i].channels() != 1)
            return ER_channel_bad;
    for(size_t i = 0; i < n_channels_values; i++)
        if((*pvMA_Values)[i].channels() != 1)
            return ER_channel_bad;

    //depth
    if(pMA_NucleiBinary->depth() != CV_8U && pMA_NucleiBinary->depth() != CV_16U)
        return ER_bitdepth_bad;
    for(size_t i = 0; i < n_channels_foci; i++)
        if((*pvMA_FociBinary)[i].depth() != CV_8U && (*pvMA_FociBinary)[i].depth() != CV_16U)
            return ER_bitdepth_bad;

    //neighborhood
    if(neighborhood != 4 && neighborhood != 8)
        return ER_parameter_bad;

    //qDebug() << "calc_NucleiDecomposition" << "Error checks passed";

    //nuclei components
    //qDebug() << "calc_NucleiDecomposition" << "nuclei comps";
    D_Component_List CompList_Nuclei;
    ER = CompList_Nuclei.set_Mat(pMA_NucleiBinary, neighborhood);
    if(ER != ER_okay)
        return ER;
    size_t n_nuclei = CompList_Nuclei.size();
    //qDebug() << "calc_NucleiDecomposition" << "nuclei comps" << "n_nuclei" << n_nuclei;

    //foci components
    //qDebug() << "calc_NucleiDecomposition" << "foci comps";
    vector<size_t> vn_foci(n_channels_foci);
    vector<D_Component_List> vCompList_Foci(n_channels_foci);
    for(size_t i = 0; i < n_channels_foci; i++)
    {
        vCompList_Foci[i] = D_Component_List();
        ER = vCompList_Foci[i].set_Mat(&(*pvMA_FociBinary)[i], neighborhood);
        if(ER != ER_okay)
            return ER;

        vn_foci[i] = vCompList_Foci[i].size();
    }
    //qDebug() << "calc_NucleiDecomposition" << "foci contours" << "vn_foci" << vn_foci;


    //get values
    //qDebug() << "calc_NucleiDecomposition" << "get values";
    //nuclei
    //qDebug() << "calc_NucleiDecomposition" << "get values: nuclei";
    vector<vector<vector<double>>> vvvNucleiChannelsValues(n_nuclei);
    for(size_t i = 0; i < n_nuclei; i++)
        vvvNucleiChannelsValues[i].resize(n_channels_values);
    //foci
    //qDebug() << "calc_NucleiDecomposition" << "get values: foci";
    vector<vector<vector<vector<double>>>> vvvvFChannelFNumberChannelsValues(n_channels_foci);
    for(size_t fc = 0; fc < n_channels_foci; fc++)
    {
        vvvvFChannelFNumberChannelsValues[fc].resize(vn_foci[fc]);
        for(size_t fn = 0; fn < vn_foci[fc]; fn++)
            vvvvFChannelFNumberChannelsValues[fc][fn].resize(n_channels_values);
    }

    //loop image
    //qDebug() << "calc_NucleiDecomposition" << "loop image";
    int n_x = pMA_NucleiBinary->cols;
    int n_y = pMA_NucleiBinary->rows;
    int label_nuclei = 0;
    vector<int> v_label_foci(n_channels_foci, 0);
    vector<double> v_values(n_channels_values, 0);
    for(int y = 0; y < n_y; y++)
        for(int x = 0; x < n_x; x++)
        {
            //qDebug() << "x:" << x << "/" << n_x << "y:" << y << n_y;

            //read
            //qDebug() << "calc_NucleiDecomposition" << "read";

            //nuclei
            //qDebug() << "calc_NucleiDecomposition" << "read nuclei";
            label_nuclei = CompList_Nuclei.get_pMatLabels()->at<int>(y, x);
            //qDebug() << "calc_NucleiDecomposition" << "read nuclei" << label_nuclei;

            //foci
            //qDebug() << "calc_NucleiDecomposition" << "read foci";
            for(size_t cf = 0; cf < n_channels_foci; cf++)
                v_label_foci[cf] = vCompList_Foci[cf].get_pMatLabels()->at<int>(y, x);
            //qDebug() << "calc_NucleiDecomposition" << "read foci" << v_label_foci;

            //values
            //qDebug() << "calc_NucleiDecomposition" << "read values";
            for(size_t cv = 0; cv < n_channels_values; cv++)
                switch ((*pvMA_Values)[cv].type()) {
                case CV_8UC1:       v_values[cv] = (*pvMA_Values)[cv].at<uchar>(y, x);      break;
                case CV_8SC1:       v_values[cv] = (*pvMA_Values)[cv].at<char>(y, x);       break;
                case CV_16UC1:      v_values[cv] = (*pvMA_Values)[cv].at<ushort>(y, x);     break;
                case CV_16SC1:      v_values[cv] = (*pvMA_Values)[cv].at<short>(y, x);      break;
                case CV_32SC1:      v_values[cv] = (*pvMA_Values)[cv].at<int>(y, x);        break;
                case CV_32FC1:      v_values[cv] = (*pvMA_Values)[cv].at<float>(y, x);      break;
                case CV_64FC1:      v_values[cv] = (*pvMA_Values)[cv].at<double>(y, x);     break;
                default:                                                                    return ER_type_bad;}
            //qDebug() << "calc_NucleiDecomposition" << "read values" << v_values;

            //write/export
            //qDebug() << "calc_NucleiDecomposition" << "write";

            //nuclei
            //qDebug() << "calc_NucleiDecomposition" << "write nuclei";
            for(size_t cv = 0; cv < n_channels_values; cv++)
                if(label_nuclei > 0)
                    vvvNucleiChannelsValues[label_nuclei - 1][cv].push_back(v_values[cv]);  //-1 to crrect indexing to start at 0 (label 0 is background)

            //foci
            //qDebug() << "calc_NucleiDecomposition" << "write foci";
            for(size_t cf = 0; cf < n_channels_foci; cf++)
                for(size_t cv = 0; cv < n_channels_values; cv++)
                    if(v_label_foci[cf] > 0)
                        vvvvFChannelFNumberChannelsValues[cf][v_label_foci[cf] - 1][cv].push_back(v_values[cv]);    //-1 to crrect indexing to start at 0 (label 0 is background)

            //qDebug() << "calc_NucleiDecomposition" << "PIXEL FINISHED";
        }
    //qDebug() << "calc_NucleiDecomposition" << "loop image finished";

    //stats
    //qDebug() << "calc_NucleiDecomposition" << "stats";
    function<double (vector<double>)> F_Median = D_Stat::Function_SingleStat(c_STAT_MEDIAN);
    function<double (vector<double>)> F_MedDev = D_Stat::Function_SingleStat(c_STAT_ABS_DEV_MED);

    //nuclei stats
    //qDebug() << "calc_NucleiDecomposition" << "nuclei stats";
    vector<vector<double>> vvNuclei_Median(n_nuclei);
    vector<vector<double>> vvNuclei_MedDev(n_nuclei);
    for(size_t i = 0; i < n_nuclei; i++)
    {
        vvNuclei_Median[i].resize(n_channels_values);
        vvNuclei_MedDev[i].resize(n_channels_values);
        for(size_t cv = 0; cv < n_channels_values; cv++)
        {
            vvNuclei_Median[i][cv] = F_Median(vvvNucleiChannelsValues[i][cv]);
            vvNuclei_MedDev[i][cv] = F_MedDev(vvvNucleiChannelsValues[i][cv]);
        }
    }

    //foci stats
    //qDebug() << "calc_NucleiDecomposition" << "foci stats";
    vector<vector<vector<double>>> vvvFChannelFNumber_Median(n_channels_foci);
    vector<vector<vector<double>>> vvvFChannelFNumber_MedDev(n_channels_foci);
    for(size_t cf = 0; cf < n_channels_foci; cf++)
    {
        vvvFChannelFNumber_Median[cf].resize(vn_foci[cf]);
        vvvFChannelFNumber_MedDev[cf].resize(vn_foci[cf]);
        for(size_t f = 0; f < vn_foci[cf]; f++)
        {
            vvvFChannelFNumber_Median[cf][f].resize(n_channels_values);
            vvvFChannelFNumber_MedDev[cf][f].resize(n_channels_values);
            for(size_t cv = 0; cv < n_channels_values; cv++)
            {
                vvvFChannelFNumber_Median[cf][f][cv] = F_Median(vvvvFChannelFNumberChannelsValues[cf][f][cv]);
                vvvFChannelFNumber_MedDev[cf][f][cv] = F_MedDev(vvvvFChannelFNumberChannelsValues[cf][f][cv]);
            }
        }
    }

    //nucleus list
    //qDebug() << "calc_NucleiDecomposition" << "nucleus list";
    vNuclei.resize(n_nuclei);
    for(size_t i = 0; i < n_nuclei; i++)
    {
        vNuclei[i] = D_Bio_NucleusBlob(
                    CompList_Nuclei.get_Component(i).get_Contour(),
                    vvNuclei_Median[i],
                    vvNuclei_MedDev[i],
                    time,
                    P_Offset);
        vNuclei[i].set_FociChannels(n_channels_foci);

        if(blockSave_StichBorder_BottomRight)
            vNuclei[i].block_save_StitchingBorder_BottomRight(
                        block_x_right,
                        block_y_bottom);
    }

    //foci list
    //qDebug() << "calc_NucleiDecomposition" << "foci list";
    vector<vector<D_Bio_Focus>> vvFoci(n_channels_foci);
    for(size_t cf = 0; cf < n_channels_foci; cf++)
    {
        vvFoci[cf].resize(vn_foci[cf]);
        for(size_t f = 0; f < vn_foci[cf]; f++)
            vvFoci[cf][f] = D_Bio_Focus(
                        vCompList_Foci[cf].get_Component(f).get_Contour(),
                        vvvFChannelFNumber_Median[cf][f],
                        vvvFChannelFNumber_MedDev[cf][f],
                        P_Offset);
    }

    //match foci to nuclei
    //qDebug() << "calc_NucleiDecomposition" << "match foci to nuclei";
    for(size_t cf = 0; cf < n_channels_foci; cf++)
        for(size_t f = 0; f < vn_foci[cf]; f++)
        {
            //centroid of focus
            Point centroid_focus = vvFoci[cf][f].centroid();
            centroid_focus -= P_Offset; //correct offset to be able to acces image coordinate system

            //nucleus label of focus
            int nucleus_label_focus = CompList_Nuclei.get_pMatLabels()->at<int>(centroid_focus);

            //match
            if(nucleus_label_focus > 0)
            {
                vNuclei[nucleus_label_focus - 1].add_Focus(cf, vvFoci[cf][f]);      //-1 to crrect indexing to start at 0 (label 0 is background)
            }
            else
            {
                //centroid in background -> find nearest contour of nucleus

                double dist_nearest = INFINITY;
                double i_opt = 0;
                for(size_t i = 0; i < n_nuclei; i++)
                {
                    double dist = vNuclei[i].dist2contour(centroid_focus); //negative inside, positive outside
                    if(dist < dist_nearest)
                    {
                        i_opt = i;
                        dist_nearest = dist;
                    }
                }

                vNuclei[i_opt].add_Focus(cf, vvFoci[cf][f]);
            }
        }

    //finish
    //qDebug() << "calc_NucleiDecomposition" << "finished :-)";
    return ER_okay;
}

int D_Bio_NucleusImage::save(QString path)
{
    //qDebug() << "D_Bio_NucleusImage::save";

    //add time
    path += "/Time_" + QString::number(m_time);
    QDir DIR_Time(path);
    if(!DIR_Time.exists())
    {
        QDir().mkdir(DIR_Time.path());
        if(!DIR_Time.exists())
            return ER_file_not_exist;
    }

    //add offset
    path += "/Image_T" + QString::number(m_time) + "_Y" + QString::number(m_Offset.y) + "_X" + QString::number(m_Offset.x);
    QDir DIR_Image(path);
    if(!DIR_Image.exists())
    {
        QDir().mkdir(DIR_Image.path());
        if(!DIR_Image.exists())
            return ER_file_not_exist;
    }

    //save nuclei
    for(size_t i = 0; i < vNuclei.size(); i++)
    {
        //qDebug() << "D_Bio_NucleusImage::save" << "nucleus" << i;

        int ER = vNuclei[i].save(DIR_Image.path());
        if(ER != ER_okay)
        {
            qDebug() << "D_Bio_NucleusImage::save" << "nucleus" << i << "ERROR:" << QSL_Errors[ER];
            return ER;
        }
    }

    //finished
    return ER_okay;
}

int D_Bio_NucleusImage::get_Contours_append(vector<vector<Point> > *pvScaledContours, double scale)
{
    for(size_t i = 0; i < vNuclei.size(); i++)
        vNuclei[i].get_Contours_append(pvScaledContours, scale);

    return ER_okay;
}

int D_Bio_NucleusImage::get_FociCount_append(QStringList *pQSL_FociCounts)
{
    for(size_t i = 0; i < vNuclei.size(); i++)
        vNuclei[i].get_FociCount_append(pQSL_FociCounts);

    return ER_okay;
}

int D_Bio_NucleusImage::get_Centroids_append(vector<Point2f> *pvScaledCentroids, double scale)
{
    size_t n = vNuclei.size();
    for(size_t i = 0; i < n; i++)
        pvScaledCentroids->push_back(vNuclei[i].centroid() * scale);

    return ER_okay;
}
