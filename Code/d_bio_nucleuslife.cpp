/************************************
 *   added:     04.01.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_bio_nucleuslife.h"

D_Bio_NucleusLife::D_Bio_NucleusLife()
{

}

bool D_Bio_NucleusLife::set_ScalePx2Um(double scale)
{
    if(scale <= 0 || isnan(scale) || isinf(scale))
        return false;

    scale_px2um = scale;
    scale_um2px = 1.0 / scale;

    return true;
}

bool D_Bio_NucleusLife::add_Member(D_Bio_NucleusBlob *nuc)
{
    if(vpNucMembers.empty())
    {
        vpNucMembers.push_back(nuc);
        return true;
    }
    else
    {
        size_t n = vpNucMembers.size();
        size_t t_add = nuc->time_index();

        for(size_t i = 0; i < n; i++)
        {
            size_t t_pos = vpNucMembers[i]->time_index();

            if(t_add == t_pos)
                return false;

            if(t_add < t_pos || i == n - 1)
            {
                vpNucMembers.insert(vpNucMembers.begin() + i, nuc);
                return true;
            }
        }
    }

    return false; //should never happen
}

double D_Bio_NucleusLife::attrib_geo(size_t i_attrib, size_t i_obj)
{
    if(i_attrib >= ATTRIB_GEO_NUMBER_OF)
        return 0;

    size_t n_obj = members_count();
    if(i_obj >= n_obj)
        return 0;

    D_Bio_NucleusBlob* pNuc = vpNucMembers[i_obj];
    if(pNuc == nullptr)
        return 0;

    switch (i_attrib) {
    case ATTRIB_GEO_CENTER_X_PX:    return pNuc->centroid().x;
    case ATTRIB_GEO_CENTER_Y_PX:    return pNuc->centroid().y;
    case ATTRIB_GEO_AREA_PX:        return pNuc->area();
    case ATTRIB_GEO_CENTER_X_UM:    return pNuc->centroid().x   * scale_px2um;
    case ATTRIB_GEO_CENTER_Y_UM:    return pNuc->centroid().y   * scale_px2um;
    case ATTRIB_GEO_AREA_UM:        return pNuc->area()         * scale_px2um * scale_px2um;
    case ATTRIB_GEO_CONVEXITY:      return pNuc->convexity();
    case ATTRIB_GEO_COMPACTNESS:    return pNuc->compactness();
    default:                        return 0;}
}

double D_Bio_NucleusLife::attrib_val(size_t i_attrib, size_t ch, size_t i_obj)
{
    if(i_attrib >= VAL_STAT_NUMBER_OF)
        return 0;

    size_t n_obj = members_count();
    if(i_obj >= n_obj)
        return 0;

    D_Bio_NucleusBlob* pNuc = vpNucMembers[i_obj];
    if(pNuc == nullptr)
        return 0;

    size_t n_ch = pNuc->get_FociChannels();
    if(ch >= n_ch)
        return 0;

    return pNuc->signal_stat(ch, i_attrib);
}

double D_Bio_NucleusLife::attrib(size_t i_attrib, size_t ch, size_t i_obj)
{
    switch (i_attrib) {
    case ATTRIB_NUC_CENTER_X_PX:    return attrib_geo(ATTRIB_GEO_CENTER_X_PX,       i_obj);
    case ATTRIB_NUC_CENTER_Y_PX:    return attrib_geo(ATTRIB_GEO_CENTER_Y_PX,       i_obj);
    case ATTRIB_NUC_AREA_PX:        return attrib_geo(ATTRIB_GEO_AREA_PX,           i_obj);
    case ATTRIB_NUC_CENTER_X_UM:    return attrib_geo(ATTRIB_GEO_CENTER_X_UM,       i_obj);
    case ATTRIB_NUC_CENTER_Y_UM:    return attrib_geo(ATTRIB_GEO_CENTER_Y_UM,       i_obj);
    case ATTRIB_NUC_AREA_UM:        return attrib_geo(ATTRIB_GEO_AREA_UM,           i_obj);
    case ATTRIB_NUC_CONVEXITY:      return attrib_geo(ATTRIB_GEO_CONVEXITY,         i_obj);
    case ATTRIB_NUC_COMPACTNESS:    return attrib_geo(ATTRIB_GEO_COMPACTNESS,       i_obj);
    case ATTRIB_NUC_COUNT_CHX:      return attrib_val(VAL_STAT_COUNT,           ch, i_obj);
    case ATTRIB_NUC_MEAN_CHX:       return attrib_val(VAL_STAT_MEAN,            ch, i_obj);
    case ATTRIB_NUC_STD_CHX:        return attrib_val(VAL_STAT_STD,             ch, i_obj);
    case ATTRIB_NUC_SKEWNESS_CHX:   return attrib_val(VAL_STAT_SKEW,            ch, i_obj);
    case ATTRIB_NUC_KURTOSIS_CHX:   return attrib_val(VAL_STAT_KURTOSIS,        ch, i_obj);
    case ATTRIB_NUC_MEDIAN_CHX:     return attrib_val(VAL_STAT_MEDIAN,          ch, i_obj);
    case ATTRIB_NUC_ABSDEVMED_CHX:  return attrib_val(VAL_STAT_MEDIAN_DEVIATION,ch, i_obj);
    default:                        return 0;}
}

vector<double> D_Bio_NucleusLife::attrib_geo(size_t i_attrib)
{
    size_t n = members_count();

    vector<double> vRes(n, 0.0);
    for(size_t i = 0; i < n; i++)
        vRes[i] = attrib_geo(i_attrib, i);

    return vRes;
}

vector<double> D_Bio_NucleusLife::attrib_val(size_t i_attrib, size_t ch)
{
    size_t n = members_count();

    vector<double> vRes(n, 0.0);
    for(size_t i = 0; i < n; i++)
        vRes[i] = attrib_val(i_attrib, ch, i);

    return vRes;
}

vector<double> D_Bio_NucleusLife::attrib(size_t i_attrib, size_t ch)
{
    size_t n = members_count();

    vector<double> vRes(n, 0.0);
    for(size_t i = 0; i < n; i++)
        vRes[i] = attrib(i_attrib, ch, i);

    return vRes;
}


