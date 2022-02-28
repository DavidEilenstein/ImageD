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

D_Bio_NucleusImage::D_Bio_NucleusImage(vector<D_Bio_NucleusImage> vNucImgs2Merge, Point P_Offset_coordinates, Point P_Offset_mosaicgrid, size_t time)
{
    m_Offset_Grid = P_Offset_mosaicgrid;
    m_Offset_Coord = P_Offset_coordinates;
    m_time = time;

    for(size_t i = 0; i < vNucImgs2Merge.size(); i++)
    {
        vector<D_Bio_NucleusBlob> vNucs2add = vNucImgs2Merge[i].get_nuclei();
        for(size_t nuc = 0; nuc < vNucs2add.size(); nuc++)
            add_nucleus(vNucs2add[nuc]);
    }
}

D_Bio_NucleusImage::D_Bio_NucleusImage(Point P_Offset_coordinates, Point P_Offset_mosaicgrid, size_t time)
{
    m_Offset_Grid = P_Offset_mosaicgrid;
    m_Offset_Coord = P_Offset_coordinates;
    m_time = time;
}

D_Bio_NucleusImage::D_Bio_NucleusImage(Mat *pMA_NucleiBinary, vector<Mat> *pvMA_FociBinary, vector<Mat> *pvMA_Values, Point P_Offset_coordinates, Point P_Offset_mosaicgrid, size_t time, int neighborhood, bool blockSave_StichBorder_BottomRight, size_t block_x_right, size_t block_y_bottom)
{
    calc_NucleiDecomposition(pMA_NucleiBinary, pvMA_FociBinary, pvMA_Values, P_Offset_coordinates, P_Offset_mosaicgrid, time, neighborhood, blockSave_StichBorder_BottomRight, block_x_right, block_y_bottom);
}

D_Bio_NucleusImage::D_Bio_NucleusImage(D_VisDat_Obj *pVD_NucleiBinary, vector<D_VisDat_Obj> *pvVD_FociBinary, vector<D_VisDat_Obj> *pvVD_Values, Point P_Offset_coordinates, Point P_Offset_mosaicgrid, size_t time, int neighborhood, bool blockSave_StichBorder_BottomRight, size_t block_x_right, size_t block_y_bottom)
{
    calc_NucleiDecomposition(pVD_NucleiBinary, pvVD_FociBinary, pvVD_Values, P_Offset_coordinates, P_Offset_mosaicgrid, time, neighborhood, blockSave_StichBorder_BottomRight, block_x_right, block_y_bottom);
}

D_Bio_NucleusImage::D_Bio_NucleusImage(vector<D_VisDat_Obj> *pvVD_Images, size_t index_NucleiBinary, vector<size_t> vIndices_FociBinary, vector<size_t> vIndices_Values, Point P_Offset_coordinates, Point P_Offset_mosaicgrid, size_t time, int neighborhood, bool blockSave_StichBorder_BottomRight, size_t block_x_right, size_t block_y_bottom)
{
    calc_NucleiDecomposition(pvVD_Images, index_NucleiBinary, vIndices_FociBinary, vIndices_Values, P_Offset_coordinates, P_Offset_mosaicgrid, time, neighborhood, blockSave_StichBorder_BottomRight, block_x_right, block_y_bottom);
}

int D_Bio_NucleusImage::calc_NucleiDecomposition(D_VisDat_Obj *pVD_NucleiBinary, vector<D_VisDat_Obj> *pvVD_FociBinary, vector<D_VisDat_Obj> *pvVD_Values, Point P_Offset_coordinates, Point P_Offset_mosaicgrid, size_t time, int neighborhood, bool blockSave_StichBorder_BottomRight, size_t block_x_right, size_t block_y_bottom)
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
    ER = calc_NucleiDecomposition(&MA_NucleiBinary, &vMA_FociBinary, &vMA_Values, P_Offset_coordinates, P_Offset_mosaicgrid, time, neighborhood, blockSave_StichBorder_BottomRight, block_x_right, block_y_bottom);

    //finish
    MA_NucleiBinary.release();
    return ER;
}

int D_Bio_NucleusImage::calc_NucleiDecomposition(vector<D_VisDat_Obj> *pvVD_Images, size_t index_NucleiBinary, vector<size_t> vIndices_FociBinary, vector<size_t> vIndices_Values, Point P_Offset_coordinates, Point P_Offset_mosaicgrid, size_t time, int neighborhood, bool blockSave_StichBorder_BottomRight, size_t block_x_right, size_t block_y_bottom)
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
    ER = calc_NucleiDecomposition(&MA_NucleiBinary, &vMA_FociBinary, &vMA_Values, P_Offset_coordinates, P_Offset_mosaicgrid, time, neighborhood, blockSave_StichBorder_BottomRight, block_x_right, block_y_bottom);

    //finish
    MA_NucleiBinary.release();
    return ER;
}

int D_Bio_NucleusImage::calc_NucleiDecomposition(Mat *pMA_NucleiBinary, vector<Mat> *pvMA_FociBinary, vector<Mat> *pvMA_Values, Point P_Offset_coordinates, Point P_Offset_mosaicgrid, size_t time, int neighborhood, bool blockSave_StichBorder_BottomRight, size_t block_x_right, size_t block_y_bottom)
{
    //qDebug() << "calc_NucleiDecomposition" << "Start";

    //save
    m_time = time;
    m_Offset_Coord = P_Offset_coordinates;
    m_Offset_Grid = P_Offset_mosaicgrid;

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
                            P_Offset_coordinates);

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
                        P_Offset_coordinates));

    //match foci to nuclei
    //qDebug() << "calc_NucleiDecomposition" << "match foci to nuclei";
    for(size_t cf = 0; cf < n_channels_foci; cf++)
        for(size_t f = 0; f < vn_foci[cf]; f++)
        {
            //centroid of focus
            Point centroid_focus = vvFoci[cf][f].centroid();
            centroid_focus -= P_Offset_coordinates; //correct offset to be able to acces image coordinate system

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

int D_Bio_NucleusImage::load(QString path, bool foci_are_part_of_nuc_files)
{
    QDir DIR(path);
    if(!DIR.exists())
        return ER_file_not_exist;

    //clear old
    vNuclei.clear();
    vvFoci.clear();

    //foci (to be loaded later)
    QFileInfoList FIL_foci;

    //list of files
    QFileInfoList FIL = DIR.entryInfoList(QDir::Files | QDir::NoDot | QDir::NoDotDot);
    for(int f = 0; f < FIL.size(); f++)
    {
        //file
        QFileInfo FI = FIL[f];

        //check if .txt
        if(FI.suffix() == "txt")
        {
            //nuclei?
            if(FI.baseName().contains("Nucleus_T"))
            {
                D_Bio_NucleusBlob NucLoad;
                if(NucLoad.load_simple(FI.absoluteFilePath(), foci_are_part_of_nuc_files))
                {
                    //qDebug() << NucLoad.info();
                    vNuclei.push_back(NucLoad);
                }
            }

            //foci?
            if(FI.baseName().contains("Foci_T") && !foci_are_part_of_nuc_files)
            {
                FIL_foci.push_back(FI);
            }
        }
    }

    //load foci
    if(foci_are_part_of_nuc_files)
        return ER_okay;
    else
        return load_foci(FIL_foci);
}

int D_Bio_NucleusImage::load_foci(QFileInfoList FIL_foci)
{
    //FIX ME FIX ME FIX ME FIX ME FIX ME FIX ME FIX ME FIX ME FIX ME FIX ME FIX ME FIX ME FIX ME FIX ME FIX ME FIX ME FIX ME

    //foci channels
    size_t n_foci_channels = FIL_foci.size();
    vvFoci.resize(n_foci_channels);

    //qDebug() << "D_Bio_NucleusImage::load_foci" << "start" << "----------------------------------------------------------------------------";

    //loop channels
    for(size_t ch = 0; ch < n_foci_channels; ch++)
    {
        QFileInfo FI = FIL_foci[static_cast<int>(ch)];
        //qDebug() << "D_Bio_NucleusImage::load_foci" << "channel" << ch << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";

        if(FI.suffix() == "txt")
        {
            QString QS_filename = FI.baseName();
            //qDebug() << "D_Bio_NucleusImage::load_foci" << "filename" << QS_filename;

            if(QS_filename.contains("Foci_T") && QS_filename.contains("_Y") && QS_filename.contains("_X"))
            {
                //---------------------------------- read foci channel file (start) ----------------------------------
                //qDebug() << "D_Bio_NucleusImage::load_foci" << "_corrdinate indicators contained";

                //file
                QFile F_Nucleus(FI.absoluteFilePath());
                if (!F_Nucleus.open(QIODevice::ReadOnly))
                    return ER_StreamNotOpen;

                //text stream
                QTextStream TS_FociChannel(&F_Nucleus);

                //info needed for interpretation
                size_t subsection = FILE_SUBSECTION_DEFAULT;
                int foci_channel_current = -1;



                //read line by line
                for(size_t l = 0; !TS_FociChannel.atEnd(); l++)
                {
                    //line and entrys in line
                    QString QS_Line = TS_FociChannel.readLine();
                    QStringList QSL_LineEntrys = QS_Line.split(";");
                    QString QS_LineFirst = QSL_LineEntrys.empty() ? "" : QSL_LineEntrys.first();
                    //qDebug() << "D_Bio_NucleusImage::load_foci" << "read line" << QSL_LineEntrys << "------------------------------------------------------";

                    //get subsection
                    bool subsection_found = false;
                    for(size_t i = 0; i < FILE_SECTION_NUMBER_OF && !subsection_found; i++)
                        if(QS_LineFirst == QSL_FileSubsections[i])
                        {
                            subsection = i;
                            subsection_found = true;
                            //qDebug() << "D_Bio_NucleusImage::load_foci" << "subsection found" << QSL_FileSubsections[i];
                        }
                    if(!subsection_found)
                    {
                        //qDebug() << "D_Bio_NucleusImage::load_foci" << "no subsection found XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
                    }

                    //subsection switch
                    switch (subsection)
                    {

                    case FILE_SUBSECTION_NEW_FOCI_CHANNEL:
                    {
                        //qDebug() << "D_Bio_NucleusImage::load_foci" << "FILE_SUBSECTION_NEW_FOCI_CHANNEL";

                        if(QSL_LineEntrys.size() == 2)
                        {
                            bool ok;
                            int channel = QSL_LineEntrys[1].toInt(&ok);
                            foci_channel_current = ok ? channel : -1;

                            if(ok)
                            {
                                //qDebug() << "D_Bio_NucleusImage::load_foci" << "new channel" << channel;
                            }
                            else
                            {
                                //qDebug() << "D_Bio_NucleusImage::load_foci" << "IVALID CHANNEL ERROR";
                            }
                        }
                    }
                        break;

                    case FILE_SUBSECTION_FOCUS_BEGIN:
                    {
                        D_Bio_Focus FocLoad;
                        if(load_focus(&FocLoad, &TS_FociChannel))
                        {
                            if(foci_channel_current >= 0 && foci_channel_current < static_cast<int>(vvFoci.size()))
                            {
                                FocLoad.set_detected_in_channel(foci_channel_current);
                                vvFoci[foci_channel_current].push_back(FocLoad);
                                //qDebug() << "D_Bio_NucleusImage::load_foci" << "ADD NEW FOCUS :-)";
                            }
                        }
                    }
                        break;

                    default:
                    {
                        //do nothing / skip lines that don't make sense here
                    }
                        break;
                    }

                }

                //---------------------------------- read foci channel file (end) ----------------------------------
            }
        }
    }

    return ER_okay;
}

int D_Bio_NucleusImage::save(QString path, bool save_foci_in_nuclei, bool save_foci_separate, bool save_name_mosaic_not_coordiante)
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

    //which offset to use in names?
    Point P_OffsetNames;
    if(save_name_mosaic_not_coordiante)
        P_OffsetNames = m_Offset_Grid;
    else
        P_OffsetNames = m_Offset_Grid;

    //add offset to path
    path += "/Image_T" + QString::number(m_time) + "_Y" + QString::number(P_OffsetNames.y) + "_X" + QString::number(P_OffsetNames.x);

    return save_PathExactDir(path, save_foci_in_nuclei, save_foci_separate, P_OffsetNames.x, P_OffsetNames.y, m_time);
}

int D_Bio_NucleusImage::save_PathExactDir(QString path, bool save_foci_in_nuclei, bool save_foci_separate, size_t x, size_t y, size_t t)
{
    //qDebug() << "D_Bio_NucleusImage::save_PathExactDir" << path;

    QDir DIR_Image(path);
    if(!DIR_Image.exists())
    {
        QDir().mkdir(DIR_Image.path());
        if(!DIR_Image.exists())
        {
            qDebug() << "D_Bio_NucleusImage::save_PathExactDir" << "dir does not exist";
            return ER_file_not_exist;
        }
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
        QString QS_Coordinate_TYX = "_T" + QString::number(t) + "_Y" + QString::number(y) + "_X" + QString::number(x);
        QString QS_PathFoci_Base = path + "/Foci" + QS_Coordinate_TYX;

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

QStringList D_Bio_NucleusImage::get_FociCounts()
{
    QStringList QSL_FociCounts;

    for(size_t i = 0; i < vNuclei.size(); i++)
        vNuclei[i].get_FociCount_append(&QSL_FociCounts);

    return QSL_FociCounts;
}

int D_Bio_NucleusImage::get_FociCount_append(QStringList *pQSL_FociCounts)
{
    for(size_t i = 0; i < vNuclei.size(); i++)
        vNuclei[i].get_FociCount_append(pQSL_FociCounts);

    return ER_okay;
}

int D_Bio_NucleusImage::get_ShapeInfo_append(QStringList *pQSL_ShapeInfo)
{
    for(size_t i = 0; i < vNuclei.size(); i++)
        vNuclei[i].get_ShapeInfo_append(pQSL_ShapeInfo);

    return ER_okay;
}

int D_Bio_NucleusImage::get_ChannelStat_append(QStringList *pQSL_Stat, size_t stat_index_bio_enum)
{
    if(stat_index_bio_enum >= VAL_STAT_NUMBER_OF)
        return ER_index_out_of_range;

    for(size_t i = 0; i < vNuclei.size(); i++)
        vNuclei[i].get_ChannelStat_append(pQSL_Stat, stat_index_bio_enum);

    return ER_okay;
}

vector<Point2f> D_Bio_NucleusImage::get_Centroids(double scale, Point2f scaled_offset)
{
    size_t n = vNuclei.size();

    vector<Point2f> vCentroids(n);

    for(size_t i = 0; i < n; i++)
        vCentroids[i] = (vNuclei[i].centroid() * scale) + scaled_offset;

    return vCentroids;
}

int D_Bio_NucleusImage::get_Centroids_append(vector<Point2f> *pvScaledCentroids, double scale)
{
    size_t n = vNuclei.size();
    for(size_t i = 0; i < n; i++)
        pvScaledCentroids->push_back(vNuclei[i].centroid() * scale);

    return ER_okay;
}

vector<D_Contour> D_Bio_NucleusImage::get_nuclei_contour_objects()
{
    size_t n = vNuclei.size();
    vector<D_Contour> vC;
    for(size_t i = 0; i < n; i++)
        vNuclei[i].get_Contours_append(&vC);

    return vC;
}

void D_Bio_NucleusImage::get_nuclei_contour_objects_append(vector<D_Contour> *pvContours)
{
    size_t n = vNuclei.size();
    for(size_t i = 0; i < n; i++)
        vNuclei[i].get_Contours_append(pvContours);
}

vector<vector<Point>> D_Bio_NucleusImage::get_nuclei_contours(double scale, Point scaled_offset)
{
    //qDebug() << "D_Bio_NucleusImage::get_nuclei_contours" << "scale" << scale << "offset x/y" << scaled_offset.x << scaled_offset.y;
    vector<vector<Point>> vvPointsContour(vNuclei.size());
    for(size_t nuc = 0; nuc < vNuclei.size(); nuc++)
    {
        vector<Point> v_contour = vNuclei[nuc].contour();

        for(size_t px = 0; px < v_contour.size(); px++)
        {
            int x = v_contour[px].x;
            int y = v_contour[px].y;
            vvPointsContour[nuc].push_back(
                        Point(
                            static_cast<int>(x * scale) + scaled_offset.x,
                            static_cast<int>(y * scale) + scaled_offset.y));
        }
    }

    return vvPointsContour;
}

vector<Point2f> D_Bio_NucleusImage::get_nuclei_centers(double scale, Point scaled_offset)
{
    vector<Point2f> vCenters;

    for(size_t nuc = 0; nuc < vNuclei.size(); nuc++)
    {
        double x = vNuclei[nuc].centroid().x;
        double y = vNuclei[nuc].centroid().y;
        vCenters.push_back(
                    Point(
                        static_cast<int>(x * scale) + scaled_offset.x,
                        static_cast<int>(y * scale) + scaled_offset.y));
    }

    return vCenters;
}

vector<Point2f> D_Bio_NucleusImage::get_foci_centers(size_t channel, double scale, Point scaled_offset)
{
    vector<Point2f> vCenters;

    if(channel >= vvFoci.size())
        return vCenters;

    for(size_t f = 0; f < vvFoci[channel].size(); f++)
    {
            double x = vvFoci[channel][f].centroid().x;
            double y = vvFoci[channel][f].centroid().y;
            vCenters.push_back(
                        Point(
                            static_cast<int>(x * scale) + scaled_offset.x,
                            static_cast<int>(y * scale) + scaled_offset.y));
    }

    return vCenters;
}

vector<double> D_Bio_NucleusImage::get_foci_radii(size_t channel, double scale)
{
    vector<double> vRadii;

    if(channel >= vvFoci.size())
        return vRadii;

    for(size_t f = 0; f < vvFoci[channel].size(); f++)
            vRadii.push_back(vvFoci[channel][f].radius_circle_equivalent() * scale);

    return vRadii;
}

vector<double> D_Bio_NucleusImage::get_foci_diameters(size_t channel, double scale)
{
    return get_foci_radii(channel, scale * 2);
}

QString D_Bio_NucleusImage::info()
{
    return
            "D_Bio_NucleusImage::info - " +
            QString::number(get_nuclei_count()) + " nuclei - "
            "offset grid " + QString::number(m_Offset_Grid.x) + "/" + QString::number(m_Offset_Grid.y) + " - " +
            "offset coord " + QString::number(m_Offset_Coord.x) + "/" + QString::number(m_Offset_Coord.y) + " - " +
            QString::number(get_foci_channel_count()) + " foci channels";
}

void D_Bio_NucleusImage::add_focus(size_t channel, D_Bio_Focus Foc)
{
    if(channel >= vvFoci.size())
        return;

    vvFoci[channel].push_back(Foc);
}

void D_Bio_NucleusImage::add_foci(size_t channel, vector<D_Bio_Focus> vFoc)
{
    if(channel >= vvFoci.size())
        return;

    for(size_t i = 0; i < vFoc.size(); i++)
        add_focus(channel, vFoc[i]);
}

void D_Bio_NucleusImage::add_nucleus(D_Bio_NucleusBlob Nuc)
{
    vNuclei.push_back(Nuc);
}

void D_Bio_NucleusImage::add_nuclei(vector<D_Bio_NucleusBlob> vNuc)
{
    for(size_t i = 0; i < vNuc.size(); i++)
        add_nucleus(vNuc[i]);
}

bool D_Bio_NucleusImage::remove_focus(Point P, size_t channel, double margin)
{
    if(channel >= vvFoci.size())
        return false;

    double dist_closest = INFINITY;
    size_t index_closest = 0;
    for(size_t f = 0; f < vvFoci[channel].size(); f++)
    {
        double dist = vvFoci[channel][f].dist2contour_circle_equivalent(P);
        if(dist < dist_closest)
        {
            dist_closest = dist;
            index_closest = f;
        }
    }

    if(dist_closest <= margin)
    {
        vvFoci[channel].erase(vvFoci[channel].begin() + index_closest);
        return true;
    }
    else
    {
        return false;
    }
}

void D_Bio_NucleusImage::remove_foci(vector<Point> vP, size_t channel, double margin)
{
    for(size_t p = 0; p < vP.size(); p++)
        remove_focus(vP[p], channel, margin);

}

bool D_Bio_NucleusImage::remove_nucleus(Point P, double margin)
{
    double dist_closest = INFINITY;
    size_t index_closest = 0;
    for(size_t i = 0; i < vNuclei.size(); i++)
    {
        double dist = vNuclei[i].dist2contour(P);
        if(dist < dist_closest)
        {
            dist_closest = dist;
            index_closest = i;
        }
    }

    if(dist_closest <= margin)
    {
        vNuclei.erase(vNuclei.begin() + index_closest);
        return true;
    }
    else
    {
        return false;
    }
}

void D_Bio_NucleusImage::remove_nuclei(vector<Point> vP, double margin)
{
    for(size_t p = 0; p < vP.size(); p++)
        remove_nucleus(vP[p], margin);
}

void D_Bio_NucleusImage::remove_nuclei_foci_all()
{
    remove_foci_all();
    remove_nuclei_all();
}

void D_Bio_NucleusImage::remove_foci_all()
{
    for(size_t ch = 0; ch < vvFoci.size(); ch++)
        vvFoci[ch].clear();
}

void D_Bio_NucleusImage::remove_nuclei_all()
{
    vNuclei.clear();
}

void D_Bio_NucleusImage::remove_nuclei_dulicates(vector<D_Bio_NucleusImage> vNucImgOther, double min_rel_intersection_for_remove)
{
    //qDebug() << "number of neighbor imgs:" << vNucImgOther.size();

    //contours in this img
    vector<D_Contour> vC1 = get_nuclei_contour_objects();
    size_t n_nuclei = vC1.size();

    //contours in other img
    vector<D_Contour> vC2;
    for(size_t i = 0; i < vNucImgOther.size(); i++)
    {
        vNucImgOther[i].get_nuclei_contour_objects_append(&vC2);
        //qDebug() << "img" << i << vNucImgOther[i].info() << "nucs total" << vC2.size();
    }


    //loop nuclei in this img
    vector<size_t> vDuplicateIndices;
    //qDebug() << "loop nuclei =================================";
    for(size_t i1 = 0; i1 < n_nuclei; i1++)
    {
        //qDebug() << "..........." << i1 << vC2.size();

        //find duplicate
        bool duplicate = false;
        for(size_t i2 = 0; i2 < vC2.size() && !duplicate; i2++)
        {
            double intersection_area_rel = vC1[i1].intersection_area_relative(vC2[i2]);
            //qDebug() << i1 << i2 << intersection_area_rel;
            if(intersection_area_rel >= min_rel_intersection_for_remove)
            {
                duplicate = true;
                vDuplicateIndices.push_back(i1);
            }
        }
    }

    //remove nuclei with a duplicate in another img
    size_t n_duplicates = vDuplicateIndices.size();
    for(size_t i_dup = 0; i_dup < n_duplicates; i_dup++)
    {
        //reverse order to keep indices valid on remove
        size_t i_dup_rev = n_duplicates - 1 - i_dup;

        //nucleus index to be removed
        size_t i_nuc_rem = vDuplicateIndices[i_dup_rev];

        //qDebug() << "remove_nuclei_dulicates - remove" << i_nuc_rem << vNuclei[i_nuc_rem].info();
        vNuclei.erase(vNuclei.begin() + i_nuc_rem);
    }
}

bool D_Bio_NucleusImage::load_focus(D_Bio_Focus *FocusLoad, QTextStream *pTS_FociChannel)
{
    //........................................... read focus (start) ...........................................
    //qDebug() << "D_Bio_NucleusImage::load_focus" << "READ NEW FOCUS" << "......................................................................................";

    //data of new focus
    Point2f focus_centroid(0, 0);
    double focus_area = 0;
    double focus_compactness = 0;
    double focus_convexity = 0;
    vector<vector<double>> focus_StatsChannels(VAL_STAT_NUMBER_OF, vector<double>(vvFoci.size(), 0));

    bool focus_end = false;
    while(!pTS_FociChannel->atEnd() && !focus_end)
    {
        //line and entrys in line in focus
        QString QS_Line_focus = pTS_FociChannel->readLine();
        QStringList QSL_LineEntrys_focus = QS_Line_focus.split(";");
        QString QS_LineFirst_focus = QSL_LineEntrys_focus.empty() ? "" : QSL_LineEntrys_focus.first();
        //qDebug() << "D_Bio_NucleusImage::load_focus" << "read line in foucs" << QSL_LineEntrys_focus << "- - - - - - - - - - - - - - - - - - - - - - - - ";

        //get subsection in focus
        bool subsection_found_focus = false;
        size_t subsection_focus = FILE_SUBSECTION_DEFAULT;
        for(size_t i = 0; i < FILE_SUBSECTION_NUMBER_OF && !subsection_found_focus; i++)
            if(QS_LineFirst_focus == QSL_FileSubsections[i])
            {
                subsection_focus = i;
                subsection_found_focus = true;
                //qDebug() << "D_Bio_NucleusImage::load_focus" << "found focus subsection" << QSL_FileSubsections[i];
            }
        if(!subsection_found_focus)
        {
            //qDebug() << "D_Bio_NucleusImage::load_focus" << "no focus seubsection found xxxxxxxxxxxxxxxxxxxxx";
        }

        //add data to focus
        //qDebug() << "D_Bio_NucleusImage::load_focus" << "start focus subsection switch";
        switch (subsection_focus) {

        case FILE_SUBSECTION_POSITION:
        {
            //qDebug() << "D_Bio_NucleusImage::load_focus" << "FILE_SUBSECTION_POSITION";
            if(QSL_LineEntrys_focus.size() == 3)
            {
                bool ok_x;
                double x = QSL_LineEntrys_focus[1].toDouble(&ok_x);
                bool ok_y;
                double y = QSL_LineEntrys_focus[2].toDouble(&ok_y);
                if(ok_x && ok_y)
                {
                    focus_centroid = Point2f(x, y);
                    //qDebug() << "D_Bio_NucleusImage::load_focus" << "loaded centroid:" << focus_centroid.x << focus_centroid.y;
                }
                else
                {
                    //qDebug() << "D_Bio_NucleusImage::load_focus" << "unable to read centroid";
                }
            }
        }
            break;

        case FILE_SUBSECTION_SHAPE:
        {
            //qDebug() << "D_Bio_NucleusImage::load_focus" << "FILE_SUBSECTION_SHAPE";

            if(QSL_LineEntrys_focus.size() == 4)
            {
                //qDebug() << "D_Bio_NucleusImage::load_focus" << "correct block count in shape line in focus";

                bool ok_area;
                double load_area = QSL_LineEntrys_focus[1].toDouble(&ok_area);
                if(ok_area)
                {
                    focus_area = load_area;
                    //qDebug() << "D_Bio_NucleusImage::load_focus" << "load area" << focus_area;
                }
                else
                {
                    //qDebug() << "D_Bio_NucleusImage::load_focus" << "area load error";
                }


                bool ok_compactness;
                double load_compactness = QSL_LineEntrys_focus[2].toDouble(&ok_compactness);
                if(ok_compactness)
                {
                    focus_compactness = load_compactness;
                    //qDebug() << "D_Bio_NucleusImage::load_focus" << "load compactness" << focus_compactness;
                }
                else
                {
                    //qDebug() << "D_Bio_NucleusImage::load_focus" << "compactness error";
                }

                bool ok_convexity;
                double load_convexity = QSL_LineEntrys_focus[3].toDouble(&ok_convexity);
                if(ok_convexity)
                {
                    focus_convexity = load_convexity;
                    //qDebug() << "D_Bio_NucleusImage::load_focus" << "load convexity" << load_convexity;
                }
                else
                {
                    //qDebug() << "D_Bio_NucleusImage::load_focus" << "convexity error";
                }
            }
        }
            break;

        case FILE_SUBSECTION_VAL_COUNT:
        case FILE_SUBSECTION_MEAN:
        case FILE_SUBSECTION_STD:
        case FILE_SUBSECTION_SKEW:
        case FILE_SUBSECTION_KURTOSIS:
        case FILE_SUBSECTION_MEDIAN:
        case FILE_SUBSECTION_MEDIAN_DEVIATION:
        {
            bool ok_stat = true;
            size_t stat_index;
            switch (subsection_focus) {
            case FILE_SUBSECTION_VAL_COUNT:         stat_index = VAL_STAT_COUNT;            break;
            case FILE_SUBSECTION_MEAN:              stat_index = VAL_STAT_MEAN;             break;
            case FILE_SUBSECTION_STD:               stat_index = VAL_STAT_STD;              break;
            case FILE_SUBSECTION_SKEW:              stat_index = VAL_STAT_SKEW;             break;
            case FILE_SUBSECTION_KURTOSIS:          stat_index = VAL_STAT_KURTOSIS;         break;
            case FILE_SUBSECTION_MEDIAN:            stat_index = VAL_STAT_MEDIAN;           break;
            case FILE_SUBSECTION_MEDIAN_DEVIATION:  stat_index = VAL_STAT_MEDIAN_DEVIATION; break;
            default:                                ok_stat = false;                        break;}

            if(ok_stat)
            {
                //qDebug() << "D_Bio_NucleusImage::load_focus" << "stat read" << QSL_ValueStat_Subsection[stat_index];
                for(int block = 1; block < QSL_LineEntrys_focus.size(); block++)
                {
                    bool ok;
                    double value = QSL_LineEntrys_focus[block].toDouble(&ok);
                    size_t channel = block - 1;

                    //qDebug() << "D_Bio_NucleusImage::load_focus" << "read block" << block << QSL_LineEntrys_focus[block] << "to channel" << channel;

                    if(stat_index >= 0 && stat_index < focus_StatsChannels.size())
                        if(channel >= 0 && channel < focus_StatsChannels[stat_index].size())
                        {
                            focus_StatsChannels[stat_index][channel] = ok ? value : 0;
                            if(ok)
                            {
                                //qDebug() << "D_Bio_NucleusImage::load_focus" << "read stat" << value;
                            }
                            else
                            {
                                //qDebug() << "D_Bio_NucleusImage::load_focus" << "value read error (Value)";
                            }
                        }
                }
            }
            else
            {
                //qDebug() << "D_Bio_NucleusImage::load_focus" << "value read error (ID)";
            }
        }
            break;

        case FILE_SUBSECTION_DEFAULT:
        {
            //do nothing / proceed with next line
        }
            break;

        case FILE_SUBSECTION_FOCUS_END:
        default:
        {
            //qDebug() << "D_Bio_NucleusImage::load_focus" << "END / DEFAULT";
            focus_end = true;
        }
        }
    }

    //........................................... reading focus (end) ...........................................

    *FocusLoad = D_Bio_Focus(
                focus_centroid,
                focus_area,
                focus_compactness,
                focus_convexity,
                focus_StatsChannels,
                0);//detection channel is set later when foc is pushed to container

    return true;
}
