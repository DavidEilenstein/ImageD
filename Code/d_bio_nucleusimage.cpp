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

    //nuclei stats
    //qDebug() << "calc_NucleiDecomposition" << "nuclei stats";
    vector<vector<vector<double>>> vvvNucleusStatChannel(n_nuclei, vector<vector<double>>(VAL_STAT_NUMBER_OF, vector<double>(n_channels_values, 0)));
    //loop nuclei
    for(size_t nuc = 0; nuc < n_nuclei; nuc++)
    {
        //loop value channels
        for(size_t chv = 0; chv < n_channels_values; chv++)
        {
            //calc stats
            vector<double> vValueStats;
            D_Stat::Calc_Stats(
                        &vValueStats,
                        vvvNucleiChannelsValues[nuc][chv],
                        true);

            vvvNucleusStatChannel[nuc][VAL_STAT_COUNT][chv]             = vValueStats[c_STAT_COUNT];
            vvvNucleusStatChannel[nuc][VAL_STAT_MEAN][chv]              = vValueStats[c_STAT_MEAN_ARITMETIC];
            vvvNucleusStatChannel[nuc][VAL_STAT_STD][chv]               = vValueStats[c_STAT_STAN_DEV_SAMPLE];
            vvvNucleusStatChannel[nuc][VAL_STAT_SKEW][chv]              = vValueStats[c_STAT_SKEWNESS_SAMPLE];
            vvvNucleusStatChannel[nuc][VAL_STAT_KURTOSIS][chv]          = vValueStats[c_STAT_KURTOSIS_SAMPLE];
            vvvNucleusStatChannel[nuc][VAL_STAT_MEDIAN][chv]            = vValueStats[c_STAT_MEDIAN];
            vvvNucleusStatChannel[nuc][VAL_STAT_MEDIAN_DEVIATION][chv]  = vValueStats[c_STAT_ABS_DEV_MED];
        }
    }

    //foci stats
    //qDebug() << "calc_NucleiDecomposition" << "foci stats";
    vector<vector<vector<vector<double>>>> vvvv_FChannel_Focus_Stat_VChannel(n_channels_foci);
    //loop channels where foci are detected in
    for(size_t chf = 0; chf < n_channels_foci; chf++)
    {
        //loop foci in focus channel
        vvvv_FChannel_Focus_Stat_VChannel[chf].resize(vn_foci[chf]);
        for(size_t foc = 0; foc < vn_foci[chf]; foc++)
        {
            //loop stats
            vvvv_FChannel_Focus_Stat_VChannel[chf][foc].resize(VAL_STAT_NUMBER_OF);
            for(size_t stat = 0; stat < VAL_STAT_NUMBER_OF; stat++)
                vvvv_FChannel_Focus_Stat_VChannel[chf][foc][stat].resize(n_channels_values, 0);

            //loop value channels per focus and calc stats
            for(size_t chv = 0; chv < n_channels_values; chv++)
            {
                //calc stats
                vector<double> vValueStats;
                D_Stat::Calc_Stats(
                            &vValueStats,
                            vvvvFChannelFNumberChannelsValues[chf][foc][chv],
                            true);

                vvvv_FChannel_Focus_Stat_VChannel[chf][foc][VAL_STAT_COUNT][chv]             = vValueStats[c_STAT_COUNT];
                vvvv_FChannel_Focus_Stat_VChannel[chf][foc][VAL_STAT_MEAN][chv]              = vValueStats[c_STAT_MEAN_ARITMETIC];
                vvvv_FChannel_Focus_Stat_VChannel[chf][foc][VAL_STAT_STD][chv]               = vValueStats[c_STAT_STAN_DEV_SAMPLE];
                vvvv_FChannel_Focus_Stat_VChannel[chf][foc][VAL_STAT_SKEW][chv]              = vValueStats[c_STAT_SKEWNESS_SAMPLE];
                vvvv_FChannel_Focus_Stat_VChannel[chf][foc][VAL_STAT_KURTOSIS][chv]          = vValueStats[c_STAT_KURTOSIS_SAMPLE];
                vvvv_FChannel_Focus_Stat_VChannel[chf][foc][VAL_STAT_MEDIAN][chv]            = vValueStats[c_STAT_MEDIAN];
                vvvv_FChannel_Focus_Stat_VChannel[chf][foc][VAL_STAT_MEDIAN_DEVIATION][chv]  = vValueStats[c_STAT_ABS_DEV_MED];
            }
        }
    }

    //nucleus list
    //qDebug() << "calc_NucleiDecomposition" << "nucleus list";
    vNuclei.clear();
    for(size_t i = 0; i < n_nuclei; i++)
    {
        //create nucleus
        D_Bio_NucleusBlob NucBlob(
                            CompList_Nuclei.get_Component(i).get_Contour(),
                            vvvNucleusStatChannel[i],
                            time,
                            P_Offset);

        NucBlob.set_FociChannels(n_channels_foci);

        if(blockSave_StichBorder_BottomRight)
            NucBlob.block_save_StitchingBorder_BottomRight(
                        block_x_right,
                        block_y_bottom);

        vNuclei.push_back(NucBlob);
    }

    //foci list
    //qDebug() << "calc_NucleiDecomposition" << "foci list";
    vvFoci.clear();
    vvFoci.resize(n_channels_foci);
    for(size_t cf = 0; cf < n_channels_foci; cf++)
        for(size_t f = 0; f < vn_foci[cf]; f++)
            vvFoci[cf].push_back(D_Bio_Focus(
                        vCompList_Foci[cf].get_Component(f).get_Contour(),
                        vvvv_FChannel_Focus_Stat_VChannel[cf][f],
                        P_Offset));

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
                /*
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
                */
            }
        }

    //finish
    //qDebug() << "calc_NucleiDecomposition" << "finished :-)";
    return ER_okay;
}

int D_Bio_NucleusImage::save(QString path, bool save_foci_in_nuclei, bool save_foci_separate)
{
    //qDebug() << "D_Bio_NucleusImage::save";

    //add time to path
    path += "/Time_" + QString::number(m_time);
    QDir DIR_Time(path);
    if(!DIR_Time.exists())
    {
        QDir().mkdir(DIR_Time.path());
        if(!DIR_Time.exists())
            return ER_file_not_exist;
    }

    //add offset to path
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

        int ER = vNuclei[i].save_simple(DIR_Image.path(), save_foci_in_nuclei);
        if(ER != ER_okay)
        {
            //qDebug() << "D_Bio_NucleusImage::save" << "nucleus" << i << "ERROR:" << QSL_Errors[ER];
            return ER;
        }
    }

    //save foci separate
    if(save_foci_separate)
    {
        //qDebug() << "D_Bio_NucleusImage::save" << "save_foci_separate";

        //parent directory
        QDir DIR_Save(path);
        if(!DIR_Save.exists())
        {
            QDir().mkdir(DIR_Save.path());
            if(!DIR_Save.exists())
                return ER_file_not_exist;
        }

        //TYX coordinate
        QString QS_Coordinate_TYX = "_T" + QString::number(m_time) + "_Y" + QString::number(static_cast<int>(m_Offset.y)) + "_X" + QString::number(static_cast<int>(m_Offset.x));
        QString QS_PathFoci_Base = path + "/Foci_" + QS_Coordinate_TYX;

        //loop channels
        for(size_t c = 0; c < vvFoci.size(); c++)
        {
            //File
            //qDebug() << "D_Bio_NucleusImage::save" << "get filename" << "channel" << c;
            QFileInfo FI_FociChannel(QS_PathFoci_Base + "_C" + QString::number(c) + ".txt");

            //stream to text file
            //qDebug() << "D_Bio_NucleusImage::save" << "open stream";
            ofstream OS_FociChannel(FI_FociChannel.absoluteFilePath().toStdString());
            if(!OS_FociChannel.is_open())
                return ER_StreamNotOpen;

            OS_FociChannel << QSL_FileSubsections[FILE_SUBSECTION_NEW_FOCI_CHANNEL].toStdString() << ";" << c;

            //loop foci
            //qDebug() << "D_Bio_NucleusImage::save" << "loop foci";
            for(size_t f = 0; f < vvFoci[c].size(); f++)
            {
              //qDebug() << "D_Bio_NucleusImage::save" << "focus" << f << "of" << vvFoci[c].size();

                OS_FociChannel << "\n" << QSL_FileSubsections[FILE_SUBSECTION_FOCUS_BEGIN].toStdString();

                //qDebug() << "D_Bio_NucleusImage::save" << "get focus";
                D_Bio_Focus focus = vvFoci[c][f];

                //qDebug() << "D_Bio_NucleusImage::save" << "center";
                OS_FociChannel << "\n" << QSL_FileSubsections[FILE_SUBSECTION_POSITION].toStdString() << ";" << focus.centroid().x << ";" << focus.centroid().y;
                //qDebug() << "D_Bio_NucleusImage::save" << "shape";
                OS_FociChannel << "\n" << QSL_FileSubsections[FILE_SUBSECTION_SHAPE].toStdString() << ";" << focus.area() << ";" << focus.convexity() << ";" << focus.compactness();

                //qDebug() << "D_Bio_NucleusImage::save" << "loop stats";
                for(size_t stat = 0; stat < VAL_STAT_NUMBER_OF; stat++)
                {
                    OS_FociChannel << "\n" << QSL_ValueStat_Subsection[stat].toStdString();
                    for(size_t ch = 0; ch < focus.channels(); ch++)
                        OS_FociChannel << ";" << focus.signal_stat(ch, stat);
                }

                //qDebug() << "D_Bio_NucleusImage::save" << "focus end";
                OS_FociChannel << "\n" << QSL_FileSubsections[FILE_SUBSECTION_FOCUS_END].toStdString();
            }

            OS_FociChannel.close();
            //qDebug() << "D_Bio_NucleusImage::save" << "end of chanel ---------------------------------";
        }
    }
    //qDebug() << "D_Bio_NucleusImage::save" << "end of foci save";

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
