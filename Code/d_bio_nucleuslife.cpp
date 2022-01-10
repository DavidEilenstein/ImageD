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

D_Bio_Focus *D_Bio_NucleusLife::pFocus(size_t i_nuc, size_t ch_foc, size_t i_foc)
{
    size_t n_nuc = members_count();
    if(i_nuc >= n_nuc)
        return nullptr;

    D_Bio_NucleusBlob* pNuc = vpNucMembers[i_nuc];
    if(pNuc == nullptr)
        return nullptr;

    size_t n_ch_foc = pNuc->get_FociChannels();
    if(ch_foc >= n_ch_foc)
        return nullptr;

    size_t n_foc = pNuc->get_FociCount(ch_foc);
    if(i_foc >= n_foc)
        return nullptr;

    return pNuc->get_pFocus(ch_foc, i_foc);
}

double D_Bio_NucleusLife::attrib_foc(size_t i_attrib, size_t ch_val, size_t ch_foc, size_t i_nuc, size_t i_foc)
{
    if(i_attrib >= ATTRIB_FOC_NUMBER_OF)
        return 0;

    D_Bio_Focus* pFoc = pFocus(i_nuc, ch_foc, i_foc);
    if(pFoc == nullptr)
        return 0;

    switch (i_attrib) {

    case ATTRIB_FOC_CENTER_X_PX:    return pFoc->centroid().x;
    case ATTRIB_FOC_CENTER_Y_PX:    return pFoc->centroid().y;
    case ATTRIB_FOC_AREA_PX:        return pFoc->area();
    case ATTRIB_FOC_CENTER_X_UM:    return pFoc->centroid().x * scale_px2um;
    case ATTRIB_FOC_CENTER_Y_UM:    return pFoc->centroid().y * scale_px2um;
    case ATTRIB_FOC_AREA_UM:        return pFoc->area() * scale_px2um * scale_px2um;
    case ATTRIB_FOC_CONVEXITY:      return pFoc->convexity();
    case ATTRIB_FOC_COMPACTNESS:    return pFoc->compactness();

    case ATTRIB_FOC_COUNT_CHX:      return pFoc->signal_stat(ch_val, VAL_STAT_COUNT);
    case ATTRIB_FOC_MEAN_CHX:       return pFoc->signal_stat(ch_val, VAL_STAT_MEAN);
    case ATTRIB_FOC_STD_CHX:        return pFoc->signal_stat(ch_val, VAL_STAT_STD);
    case ATTRIB_FOC_SKEWNESS_CHX:   return pFoc->signal_stat(ch_val, VAL_STAT_SKEW);
    case ATTRIB_FOC_KURTOSIS_CHX:   return pFoc->signal_stat(ch_val, VAL_STAT_KURTOSIS);
    case ATTRIB_FOC_MEDIAN_CHX:     return pFoc->signal_stat(ch_val, VAL_STAT_MEDIAN);
    case ATTRIB_FOC_ABSDEVMED_CHX:  return pFoc->signal_stat(ch_val, VAL_STAT_MEDIAN_DEVIATION);

    case ATTRIB_FOC_DETECTED_IN_CH: return double(ch_foc);
    default:                        return 0;}
}

vector<double> D_Bio_NucleusLife::attrib_foc(size_t i_attrib, size_t ch_val, size_t ch_foc, size_t i_nuc)
{
    vector<double> vRes;

    size_t n_nuc = members_count();
    if(i_nuc >= n_nuc)
        return vRes;

    if(i_attrib >= ATTRIB_NUC_NUMBER_OF)
        return vRes;

    D_Bio_NucleusBlob* pNuc = vpNucMembers[i_nuc];
    if(pNuc == nullptr)
        return vRes;

    size_t n_ch_val = pNuc->channels();
    if(ch_val >= n_ch_val)
        return vRes;

    size_t n_ch_foc = pNuc->get_FociChannels();
    if(ch_foc >= n_ch_foc)
        return vRes;

    size_t n_foc = pNuc->get_FociCount(n_ch_foc);
    if(n_ch_foc >= n_foc)
        return vRes;

    vRes.resize(n_foc);
    for(size_t f = 0; f < n_foc; f++)
        vRes[f] = attrib_foc(i_attrib, ch_val, ch_foc, i_nuc, f);

    return vRes;
}

vector<vector<double> > D_Bio_NucleusLife::attrib_foc(size_t i_attrib, size_t ch_val, size_t ch_foc)
{
    size_t n_nuc = members_count();

    vector<vector<double>> vvRes(n_nuc);

    for(size_t i_nuc = 0; i_nuc < n_nuc; i_nuc++)
        vvRes[i_nuc] = attrib_foc(i_attrib, ch_val, ch_foc, i_nuc);

    return vvRes;
}

vector<vector<vector<double> > > D_Bio_NucleusLife::attrib_foc(size_t i_attrib, size_t ch_val)
{
    vector<vector<vector<double>>> vvvRes;

    size_t n_nuc = members_count();
    if(n_nuc <= 0)
        return vvvRes;

    D_Bio_NucleusBlob* pNuc = vpNucMembers[0];
    if(pNuc == nullptr)
        return vvvRes;

    size_t n_ch_foc = pNuc->get_FociChannels();

    vvvRes.resize(n_ch_foc, vector<vector<double>>(n_nuc));

    for(size_t ch_foc = 0; ch_foc < n_ch_foc; ch_foc++)
        vvvRes[ch_foc] = attrib_foc(i_attrib, ch_val, ch_foc);

    return vvvRes;
}

double D_Bio_NucleusLife::attrib_nuc(size_t i_attrib, size_t ch_val, size_t i_nuc)
{
    if(i_attrib >= ATTRIB_NUC_NUMBER_OF)
        return 0;

    size_t n_nuc = members_count();
    if(i_nuc >= n_nuc)
        return 0;

    D_Bio_NucleusBlob* pNuc = vpNucMembers[i_nuc];
    if(pNuc == nullptr)
        return 0;

    size_t n_ch_val = pNuc->channels();
    if(ch_val >= n_ch_val)
        return 0;

    switch (i_attrib) {

    case ATTRIB_NUC_CENTER_X_PX:                return pNuc->centroid().x;
    case ATTRIB_NUC_CENTER_Y_PX:                return pNuc->centroid().y;
    case ATTRIB_NUC_AREA_PX:                    return pNuc->area();
    case ATTRIB_NUC_CENTER_X_UM:                return pNuc->centroid().x * scale_px2um;
    case ATTRIB_NUC_CENTER_Y_UM:                return pNuc->centroid().y * scale_px2um;
    case ATTRIB_NUC_AREA_UM:                    return pNuc->area() * scale_px2um * scale_px2um;
    case ATTRIB_NUC_CONVEXITY:                  return pNuc->convexity();
    case ATTRIB_NUC_COMPACTNESS:                return pNuc->compactness();

    case ATTRIB_NUC_SHIFT_PX:
    {
        D_Bio_NucleusBlob* pNucBefore = i_nuc > 0 && members_count() > 0 ? vpNucMembers[i_nuc - 1] : pNuc_parent();
        return pNucBefore == nullptr ? 0 : D_Math::Distance(pNuc->centroid(), pNucBefore->centroid());
    }
    case ATTRIB_NUC_SHIFT_UM:                   return attrib_nuc(ATTRIB_NUC_SHIFT_PX, ch_val, i_nuc) * scale_px2um;

    case ATTRIB_NUC_COUNT_CHX:                  return pNuc->signal_stat(ch_val, VAL_STAT_COUNT);
    case ATTRIB_NUC_MEAN_CHX:                   return pNuc->signal_stat(ch_val, VAL_STAT_MEAN);
    case ATTRIB_NUC_STD_CHX:                    return pNuc->signal_stat(ch_val, VAL_STAT_STD);
    case ATTRIB_NUC_SKEWNESS_CHX:               return pNuc->signal_stat(ch_val, VAL_STAT_SKEW);
    case ATTRIB_NUC_KURTOSIS_CHX:               return pNuc->signal_stat(ch_val, VAL_STAT_KURTOSIS);
    case ATTRIB_NUC_MEDIAN_CHX:                 return pNuc->signal_stat(ch_val, VAL_STAT_MEDIAN);
    case ATTRIB_NUC_ABSDEVMED_CHX:              return pNuc->signal_stat(ch_val, VAL_STAT_MEDIAN_DEVIATION);

    case ATTRIB_NUC_FOCI_COUNT_CHX:             return pNuc->get_FociCount(ch_val);
    case ATTRIB_NUC_FOCI_COUNT_CHX_PER_AREA_PX: return pNuc->get_FociCount(ch_val) / pNuc->area();
    case ATTRIB_NUC_FOCI_COUNT_CHX_PER_AREA_UM: return pNuc->get_FociCount(ch_val) / (pNuc->area() * scale_px2um * scale_px2um);
    case ATTRIB_NUC_FOCI_COUNT_ALL:
    {
        double foci_sum = 0;
        for(size_t ch = 0; ch < n_ch_val; ch++)
            foci_sum += pNuc->get_FociCount(ch);
        return foci_sum;
    }
    case ATTRIB_NUC_FOCI_COUNT_ALL_PER_AREA_PX: return attrib_nuc(ATTRIB_NUC_FOCI_COUNT_ALL, ch_val, i_nuc) / pNuc->area();
    case ATTRIB_NUC_FOCI_COUNT_ALL_PER_AREA_UM: return attrib_nuc(ATTRIB_NUC_FOCI_COUNT_ALL, ch_val, i_nuc) / (pNuc->area() * scale_px2um * scale_px2um);

    default:                                    return 0;
    }
}

vector<double> D_Bio_NucleusLife::attrib_nuc(size_t i_attrib, size_t ch_val)
{
    size_t n_nuc = members_count();

    vector<double> vRes(n_nuc, 0.0);
    for(size_t i = 0; i < n_nuc; i++)
        vRes[i] = attrib_nuc(i_attrib, ch_val, i);

    return vRes;
}

double D_Bio_NucleusLife::attrib_nuclife(size_t i_attrib_nuclife)
{
    if(i_attrib_nuclife <= ATTRIB_NUCLIFE_NUMBER_OF)
        return 0;

    switch (i_attrib_nuclife)
    {

    case ATTRIB_NUCLIFE_AGE:                                return members_count();
    case ATTRIB_NUCLIFE_START:                              return members_count() > 0 ? vpNucMembers[0]->time_index() : 0;
    case ATTRIB_NUCLIFE_END:                                return members_count() > 0 ? vpNucMembers[members_count() - 1]->time_index() : 0;
    case ATTRIB_NUCLIFE_MID:                                return (attrib_nuclife(ATTRIB_NUCLIFE_START) + attrib_nuclife(ATTRIB_NUCLIFE_END)) / 2.0;

    case ATTRIB_NUCLIFE_SHIFT_PX:
    {
        Point P0(attrib_nuc_begin(ATTRIB_NUC_CENTER_X_PX, 0), attrib_nuc_begin(ATTRIB_NUC_CENTER_Y_PX, 0));
        Point P1(attrib_nuc_begin(ATTRIB_NUC_CENTER_X_PX, 0), attrib_nuc_begin(ATTRIB_NUC_CENTER_Y_PX, 0));
        return D_Math::Distance(P0, P1);
    }
    case ATTRIB_NUCLIFE_SHIFT_UM:                           return attrib_nuclife(ATTRIB_NUCLIFE_SHIFT_PX) * scale_px2um;
    case ATTRIB_NUCLIFE_PATHLENGTH_PX:
    {
        double sum_shifts = 0;
        for(size_t i = 0; i < members_count(); i++)
            sum_shifts += attrib_nuc(ATTRIB_NUC_SHIFT_PX, 0, i);
        return sum_shifts;
    }
    case ATTRIB_NUCLIFE_PATHLENGTH_UM:                      return attrib_nuclife(ATTRIB_NUCLIFE_PATHLENGTH_PX) * scale_px2um;
    case ATTRIB_NUCLIFE_SHIFT_PX_PER_T:                     return members_count() > 0 ? attrib_nuclife(ATTRIB_NUCLIFE_SHIFT_PX) / members_count() : 0;
    case ATTRIB_NUCLIFE_SHIFT_UM_PER_T:                     return members_count() > 0 ? attrib_nuclife(ATTRIB_NUCLIFE_SHIFT_UM) / members_count() : 0;
    case ATTRIB_NUCLIFE_PATHLENGTH_PX_PER_T:                return members_count() > 0 ? attrib_nuclife(ATTRIB_NUCLIFE_PATHLENGTH_PX) / members_count() : 0;
    case ATTRIB_NUCLIFE_PATHLENGTH_UM_PER_T:                return members_count() > 0 ? attrib_nuclife(ATTRIB_NUCLIFE_PATHLENGTH_UM) / members_count() : 0;

    case ATTRIB_NUCLIFE_AREA_GROWTH:                        return attrib_nuclife_growth        (ATTRIB_NUC_AREA_PX, 0);
    case ATTRIB_NUCLIFE_AREA_GROWTH_PER_T:                  return attrib_nuclife_growth_per_T  (ATTRIB_NUC_AREA_PX, 0);
    case ATTRIB_NUCLIFE_FOCICOUNT_GROWTH:                   return attrib_nuclife_growth        (ATTRIB_NUC_FOCI_COUNT_ALL, 0);
    case ATTRIB_NUCLIFE_FOCICOUNT_GROWTH_PER_T:             return attrib_nuclife_growth_per_T  (ATTRIB_NUC_FOCI_COUNT_ALL, 0);
    case ATTRIB_NUCLIFE_FOCICOUNT_PER_AREA_PX_GROWTH:       return attrib_nuclife_growth        (ATTRIB_NUC_FOCI_COUNT_ALL_PER_AREA_PX, 0);
    case ATTRIB_NUCLIFE_FOCICOUNT_PER_AREA_PX_GROWTH_PER_T: return attrib_nuclife_growth_per_T  (ATTRIB_NUC_FOCI_COUNT_ALL_PER_AREA_PX, 0);
    case ATTRIB_NUCLIFE_FOCICOUNT_PER_AREA_UM_GROWTH:       return attrib_nuclife_growth        (ATTRIB_NUC_FOCI_COUNT_ALL_PER_AREA_UM, 0);
    case ATTRIB_NUCLIFE_FOCICOUNT_PER_AREA_UM_GROWTH_PER_T: return attrib_nuclife_growth_per_T  (ATTRIB_NUC_FOCI_COUNT_ALL_PER_AREA_UM, 0);

    default:                                                return 0;
    }
}

bool D_Bio_NucleusLife::nearBorderAtLeastOnce()
{
    size_t n_nuc = members_count();

    for(size_t i = 0; i < n_nuc; i++)
    {
        D_Bio_NucleusBlob* pNuc = vpNucMembers[i];

        if(pNuc == nullptr)
            return true;

        if(pNuc->centroid().x < FrameInRegularRangeXY.tl().x)
            return true;

        if(pNuc->centroid().x > FrameInRegularRangeXY.br().x)
            return true;

        if(pNuc->centroid().y < FrameInRegularRangeXY.tl().y)
            return true;

        if(pNuc->centroid().y > FrameInRegularRangeXY.br().y)
            return true;
    }

    return false;
}


