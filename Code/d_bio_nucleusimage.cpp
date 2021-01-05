/************************************
 *   added:     04.01.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_bio_nucleusimage.h"

D_Bio_NucleusImage::D_Bio_NucleusImage()
{

}

D_Bio_NucleusImage::D_Bio_NucleusImage(Mat *pMA_NucleiBinary, vector<Mat *> vpMA_FociBinary, vector<Mat *> vpMA_Values, Point P_Offset, double time, int neighborhood)
{
    calc_NucleiDecomposition(pMA_NucleiBinary, vpMA_FociBinary, vpMA_Values, P_Offset, time, neighborhood);
}

int D_Bio_NucleusImage::calc_NucleiDecomposition(Mat *pMA_NucleiBinary, vector<Mat *> vpMA_FociBinary, vector<Mat *> vpMA_Values, Point P_Offset, double time, int neighborhood)
{
    //save
    m_time = time;

    //counts
    size_t n_channels_foci = vpMA_FociBinary.size();
    size_t n_channels_values = vpMA_Values.size();

    //Errors

    //empty
    //channels
    if(pMA_NucleiBinary->empty())
        return ER_empty;
    for(size_t i = 0; i < n_channels_foci; i++)
        if(vpMA_FociBinary[i]->empty())
            return ER_empty;
    for(size_t i = 0; i < n_channels_values; i++)
        if(vpMA_Values[i]->empty())
            return ER_empty;

    //size
    for(size_t i = 0; i < n_channels_foci; i++)
        if(pMA_NucleiBinary->size != vpMA_FociBinary[i]->size)
            return ER_size_missmatch;
    for(size_t i = 0; i < n_channels_values; i++)
        if(pMA_NucleiBinary->size != vpMA_Values[i]->size)
            return ER_size_missmatch;

    //channels
    if(pMA_NucleiBinary->channels() != 1)
        return ER_channel_bad;
    for(size_t i = 0; i < n_channels_foci; i++)
        if(vpMA_FociBinary[i]->channels() != 1)
            return ER_channel_bad;
    for(size_t i = 0; i < n_channels_values; i++)
        if(vpMA_Values[i]->channels() != 1)
            return ER_channel_bad;

    //depth
    if(pMA_NucleiBinary->depth() != CV_8U && pMA_NucleiBinary->depth() != CV_16U)
        return ER_bitdepth_bad;
    for(size_t i = 0; i < n_channels_foci; i++)
        if(vpMA_FociBinary[i]->depth() != CV_8U && vpMA_FociBinary[i]->depth() != CV_16U)
            return ER_bitdepth_bad;

    //neighborhood
    if(neighborhood != 4 && neighborhood != 8)
        return ER_parameter_bad;


    //nuclei labeling
    Mat MA_tmp_NucleiLabel;
    if(pMA_NucleiBinary->type() == CV_16UC1)
        MA_tmp_NucleiLabel = pMA_NucleiBinary->clone();
    else
        connectedComponents(
                    *pMA_NucleiBinary,
                    MA_tmp_NucleiLabel,
                    neighborhood,
                    CV_16UC1);

    //foci labeling
    vector<Mat> vMA_tmp_FociLabel(n_channels_foci);
    for(size_t i = 0; i < n_channels_foci; i++)
    {
        if(pMA_NucleiBinary->type() == CV_16UC1)
            MA_tmp_NucleiLabel = pMA_NucleiBinary->clone();
        else
            connectedComponents(
                        *(vpMA_FociBinary[i]),
                        vMA_tmp_FociLabel[i],
                        neighborhood,
                        CV_16UC1);
    }

    //nuclei contours
    vector<vector<Point>> vvP_tmp_Contours_Nuclei;
    findContours(
                MA_tmp_NucleiLabel,
                vvP_tmp_Contours_Nuclei,
                RETR_CCOMP,
                CV_CHAIN_APPROX_NONE,
                P_Offset);
    size_t n_nuclei = vvP_tmp_Contours_Nuclei.size();

    //foci contours
    vector<vector<vector<Point>>> vvvP_tmp_Contours_Foci(n_channels_foci);
    vector<size_t> vn_foci(n_channels_foci);
    for(size_t i = 0; i < n_channels_foci; i++)
    {
        findContours(
                    vMA_tmp_FociLabel[i],
                    vvvP_tmp_Contours_Foci[i],
                    RETR_CCOMP,
                    CV_CHAIN_APPROX_NONE,
                    P_Offset);
        vn_foci[i] = vvvP_tmp_Contours_Foci[i].size();
    }


    //get values
    //nuclei
    vector<vector<vector<double>>> vvvNucleiChannelsValues(n_nuclei);
    for(size_t i = 0; i < n_nuclei; i++)
        vvvNucleiChannelsValues[i].resize(n_channels_values);
    //foci
    vector<vector<vector<vector<double>>>> vvvvFChannelFNumberChannelsValues(n_channels_foci);
    for(size_t fc = 0; fc < n_channels_foci; fc++)
    {
        vvvvFChannelFNumberChannelsValues[fc].resize(vn_foci[fc]);
        for(size_t fn = 0; fn < vn_foci[fc]; fn++)
            vvvvFChannelFNumberChannelsValues[fc][fn].resize(n_channels_values);
    }

    //loop image
    ushort label_nuclei = 0;
    vector<ushort> v_label_foci(n_channels_foci, 0);
    vector<double> v_values(n_channels_values, 0);
    for(int y = 0; y < pMA_NucleiBinary->rows; y++)
        for(int x = 0; x < pMA_NucleiBinary->cols; x++)
        {
            //read
            //nuclei
            label_nuclei = MA_tmp_NucleiLabel.at<ushort>(y, x);
            //foci
            for(size_t cf = 0; cf < n_channels_foci; cf++)
                v_label_foci[cf] = vMA_tmp_FociLabel[cf].at<ushort>(y, x);
            //values
            for(size_t cv = 0; cv < n_channels_values; cv++)
                switch (vpMA_Values[cv]->type()) {
                case CV_8UC1:   v_values[cv] = vpMA_Values[cv]->at<uchar>(y, x);    break;
                case CV_8SC1:   v_values[cv] = vpMA_Values[cv]->at<char>(y, x);     break;
                case CV_16UC1:  v_values[cv] = vpMA_Values[cv]->at<ushort>(y, x);   break;
                case CV_16SC1:  v_values[cv] = vpMA_Values[cv]->at<short>(y, x);    break;
                case CV_32SC1:  v_values[cv] = vpMA_Values[cv]->at<int>(y, x);      break;
                case CV_32FC1:  v_values[cv] = vpMA_Values[cv]->at<float>(y, x);    break;
                case CV_64FC1:  v_values[cv] = vpMA_Values[cv]->at<double>(y, x);   break;
                default:        MA_tmp_NucleiLabel.release();                       return ER_type_bad;}

            //write/export
            //nuclei
            for(size_t cv = 0; cv < n_channels_values; cv++)
                if(label_nuclei > 0)
                    vvvNucleiChannelsValues[label_nuclei - 1][cv].push_back(v_values[cv]);
            //foci
            for(size_t cf = 0; cf < n_channels_foci; cf++)
                for(size_t cv = 0; cv < n_channels_values; cv++)
                    if(v_label_foci[cf] > 0)
                        vvvvFChannelFNumberChannelsValues[cf][v_label_foci[cf] - 1][cv].push_back(v_values[cv]);
        }

    //stats
    function<double (vector<double>)> F_Median = D_Stat::Function_SingleStat(c_STAT_MEDIAN);
    function<double (vector<double>)> F_MedDev = D_Stat::Function_SingleStat(c_STAT_ABS_DEV_MED);

    //nuclei stats
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
    vector<vector<vector<double>>> vvvFChannelFNumber_Median(n_channels_foci);
    vector<vector<vector<double>>> vvvFChannelFNumber_MedDev(n_channels_foci);
    for(size_t cf = 0; cf < n_channels_foci; cf++)
    {
        vvvFChannelFNumber_Median[cf].resize(vn_foci[cf]);
        vvvFChannelFNumber_MedDev[cf].resize(vn_foci[cf]);
        for(size_t f = 0; f < n_nuclei; f++)
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
    vNuclei.resize(n_nuclei);
    for(size_t i = 0; i < n_nuclei; i++)
    {
        vNuclei[i] = D_Bio_NucleusBlob(
                    vvP_tmp_Contours_Nuclei[i],
                    vvNuclei_Median[i],
                    vvNuclei_MedDev[i],
                    time);
        vNuclei[i].set_FociChannels(n_channels_foci);
    }

    //foci list
    vector<vector<D_Bio_Focus>> vvFoci;
    for(size_t cf = 0; cf < n_channels_foci; cf++)
    {
        vvFoci[cf].resize(vn_foci[cf]);
        for(size_t f = 0; f < n_nuclei; f++)
            vvFoci[cf][f] = D_Bio_Focus(
                        vvvP_tmp_Contours_Foci[cf][f],
                        vvvFChannelFNumber_Median[cf][f],
                        vvvFChannelFNumber_MedDev[cf][f]);
    }

    //match foci to nuclei
    for(size_t cf = 0; cf < n_channels_foci; cf++)
        for(size_t f = 0; f < n_nuclei; f++)
        {
            //centroid of focus
            Point2f centroid_focus = vvFoci[cf][f].centroid();

            //nucleus label of focus
            ushort nucleus_label_focus = MA_tmp_NucleiLabel.at<ushort>(centroid_focus);

            //match
            if(nucleus_label_focus > 0)
            {
                vNuclei[nucleus_label_focus].add_Focus(cf, vvFoci[cf][f]);
            }
            else
            {
                //centroid in background -> find nearest contour of nucleus

                double dist_nearest = INFINITY;
                double i_opt = 0;
                for(size_t i = 0; i < n_nuclei; i++)
                {
                    double dist = - vNuclei[i].dist2contour(centroid_focus); //positive inside, negative outside
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
    MA_tmp_NucleiLabel.release();
    return ER_okay;
}
