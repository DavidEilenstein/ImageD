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
    if(scale <= 0)
        return false;

    scale_px2um = scale;
    scale_um2px = 1.0 / scale;

    return true;
}

bool D_Bio_NucleusLife::add_Member(D_Bio_NucleusBlob nuc)
{
    if(vNucMembers.empty())
    {
        //add nuc
        vNucMembers.push_back(nuc);

        //init time span
        time_index_earliest = nuc.time_index();
        time_index_latest   = nuc.time_index();

        //finish
        return true;
    }
    else
    {
        //nuc count added previously
        size_t n_old = vNucMembers.size();

        //time index
        size_t t_add = nuc.time_index();

        //add front/end/mid
        if(t_add < time_index_earliest)
        {
            time_index_earliest = t_add;
            vNucMembers.insert(vNucMembers.begin(), nuc);
        }
        else if (t_add > time_index_latest)
        {
            time_index_latest = t_add;
            vNucMembers.push_back(nuc);
        }
        else
        {
            //find pos to add new nuc
            for(size_t i = 0; i < n_old; i++)
            {
                size_t t_pos = vNucMembers[i].time_index();

                if(t_add == t_pos)
                    return false;

                if(t_add < t_pos || i == n_old - 1)
                {
                    vNucMembers.insert(vNucMembers.begin() + i, nuc);
                    return true;
                }
            }
        }
    }

    return false; //should never happen
}

D_Bio_NucleusBlob *D_Bio_NucleusLife::pNuc_member_byTime(size_t t)
{
    for(size_t b = 0; b < vNucMembers.size(); b++)
        if(vNucMembers[b].time_index() == t)
            return &(vNucMembers[b]);

    return nullptr;
}

D_Bio_Focus *D_Bio_NucleusLife::pFocus(size_t i_nuc, size_t ch_foc, size_t i_foc)
{
    size_t n_nuc = members_count();
    if(i_nuc >= n_nuc)
        return nullptr;

    D_Bio_NucleusBlob* pNuc = &(vNucMembers[i_nuc]);
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

bool D_Bio_NucleusLife::is_excluded()
{
    if(members_count() < 1)
        return false;

    //may be true for connected nucs (mega foci tracker S4 or S5)
    if(vNucMembers[0].matching_excluded_life())
    {
        //qDebug() << "D_Bio_NucleusLife::is_excluded" << "exclusion member recursion";
        return true;
    }

    //may be true for filtered nuc lifes (mega foci tracker S6)
    for(size_t b = 0; b < vNucMembers.size(); b++)
    {
        if(vNucMembers[b].matching_excluded_this())
        {
            //qDebug() << "D_Bio_NucleusLife::is_excluded" << "exclusion member loop";
            return true;
        }
    }

    return false;
}

bool D_Bio_NucleusLife::set_excluded(size_t t, bool exclude)
{
    D_Bio_NucleusBlob* pNuc = pNuc_member_byTime(t);

    if(pNuc == nullptr)
        return false;

    pNuc->matching_set_excluded(exclude);
    return true;
}

double D_Bio_NucleusLife::attrib_foc(size_t i_attrib, size_t ch_val, size_t ch_foc, size_t i_nuc, size_t i_foc)
{
    if(i_attrib >= ATTRIB_FOC_NUMBER_OF)
        return 0;

    D_Bio_Focus* pFoc = pFocus(i_nuc, ch_foc, i_foc);
    if(pFoc == nullptr)
        return 0;

    return pFoc->attribute(i_attrib, ch_val, scale_px2um);
}

vector<double> D_Bio_NucleusLife::attrib_foc(size_t i_attrib, size_t ch_val, size_t ch_foc, size_t i_nuc)
{
    vector<double> vRes;

    size_t n_nuc = members_count();
    if(i_nuc >= n_nuc)
        return vRes;

    if(i_attrib >= ATTRIB_NUC_NUMBER_OF)
        return vRes;

    D_Bio_NucleusBlob* pNuc = &(vNucMembers[i_nuc]);
    if(pNuc == nullptr)
        return vRes;

    size_t n_ch_val = pNuc->channels();
    if(ch_val >= n_ch_val)
        return vRes;

    size_t n_ch_foc = pNuc->get_FociChannels();
    if(ch_foc >= n_ch_foc)
        return vRes;

    size_t n_foc = pNuc->get_FociCount(ch_foc);
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

    D_Bio_NucleusBlob* pNuc = &(vNucMembers[0]);
    if(pNuc == nullptr)
        return vvvRes;

    size_t n_ch_foc = pNuc->get_FociChannels();

    vvvRes.resize(n_ch_foc, vector<vector<double>>(n_nuc));

    for(size_t ch_foc = 0; ch_foc < n_ch_foc; ch_foc++)
        vvvRes[ch_foc] = attrib_foc(i_attrib, ch_val, ch_foc);

    return vvvRes;
}

bool D_Bio_NucleusLife::attrib_foc(vector<double> *pvAttribsToAppendTo, size_t i_attrib, size_t ch_val)
{
    if(i_attrib >= ATTRIB_FOC_NUMBER_OF)
        return false;

    size_t n_nuc = members_count();
    for(size_t i_nuc = 0; i_nuc < n_nuc; i_nuc++)
    {
        D_Bio_NucleusBlob* pNuc = &(vNucMembers[i_nuc]);
        if(pNuc == nullptr)
            return false;

        size_t n_ch_foc = pNuc->get_FociChannels();
        for(size_t ch_foc = 0; ch_foc < n_ch_foc; ch_foc++)
        {
            size_t n_foc = pNuc->get_FociCount(ch_foc);
            for(size_t i_foc = 0; i_foc < n_foc; i_foc++)
            {
                pvAttribsToAppendTo->push_back(attrib_foc(i_attrib, ch_val, ch_foc, i_nuc, i_foc));
            }
        }
    }

    return true;
}

bool D_Bio_NucleusLife::attrib_foc(vector<double> *pvAttribsToAppendTo, size_t i_attrib, size_t ch_val, size_t ch_foc)
{
    if(i_attrib >= ATTRIB_FOC_NUMBER_OF)
        return false;

    size_t n_nuc = members_count();
    for(size_t i_nuc = 0; i_nuc < n_nuc; i_nuc++)
    {
        D_Bio_NucleusBlob* pNuc = &(vNucMembers[i_nuc]);
        if(pNuc == nullptr)
            return false;

        size_t n_ch_foc = pNuc->get_FociChannels();
        if(ch_foc >= n_ch_foc)
        {
            qDebug() << "D_Bio_NucleusLife::attrib_foc - nuc" << i_nuc << " has no foci channels";
            return false;
        }

        size_t n_foc = pNuc->get_FociCount(ch_foc);
        for(size_t i_foc = 0; i_foc < n_foc; i_foc++)
        {
            pvAttribsToAppendTo->push_back(attrib_foc(i_attrib, ch_val, ch_foc, i_nuc, i_foc));
        }
    }

    return true;
}

double D_Bio_NucleusLife::attrib_nuc(size_t i_attrib, size_t ch_val, size_t i_nuc)
{
    if(i_attrib >= ATTRIB_NUC_NUMBER_OF)
        return 0;

    size_t n_nuc = members_count();
    if(i_nuc >= n_nuc)
        return 0;

    D_Bio_NucleusBlob* pNuc = &(vNucMembers[i_nuc]);
    if(pNuc == nullptr)
        return 0;

    size_t n_ch_val = pNuc->channels();
    if(ch_val >= n_ch_val)
        return 0;

    return pNuc->attribute(i_attrib, ch_val, scale_px2um);
}

vector<double> D_Bio_NucleusLife::attrib_nuc(size_t i_attrib, size_t ch_val)
{
    size_t n_nuc = members_count();

    vector<double> vRes(n_nuc, 0.0);
    for(size_t i = 0; i < n_nuc; i++)
        vRes[i] = attrib_nuc(i_attrib, ch_val, i);

    return vRes;
}

bool D_Bio_NucleusLife::attrib_nuc(vector<double> *pvAttribsToAppendTo, size_t i_attrib, size_t ch_val)
{
    if(i_attrib >= ATTRIB_NUC_NUMBER_OF)
        return false;

    size_t n_nuc = members_count();
    for(size_t i_nuc = 0; i_nuc < n_nuc; i_nuc++)
    {
        D_Bio_NucleusBlob* pNuc = &(vNucMembers[i_nuc]);
        if(pNuc == nullptr)
            return false;

        pvAttribsToAppendTo->push_back(attrib_nuc(i_attrib, ch_val, i_nuc));
    }

    return true;
}

double D_Bio_NucleusLife::attrib_nuclife(size_t i_attrib_nuclife)
{
    if(i_attrib_nuclife >= ATTRIB_NUCLIFE_NUMBER_OF)
        return 0;

    switch (i_attrib_nuclife)
    {

    case ATTRIB_NUCLIFE_AGE:                                return time_index_latest - time_index_earliest;
    case ATTRIB_NUCLIFE_START:                              return time_index_earliest;
    case ATTRIB_NUCLIFE_END:                                return time_index_latest;
    case ATTRIB_NUCLIFE_MID:                                return double(time_index_earliest + time_index_latest) / 2.0;

    case ATTRIB_NUCLIFE_SHIFT_PX:
    {
        Point2d P0(attrib_nuc_begin(ATTRIB_NUC_CENTER_X_PX, 0), attrib_nuc_begin(ATTRIB_NUC_CENTER_Y_PX, 0));
        Point2d P1(attrib_nuc_end  (ATTRIB_NUC_CENTER_X_PX, 0), attrib_nuc_end  (ATTRIB_NUC_CENTER_Y_PX, 0));
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
    case ATTRIB_NUCLIFE_FOCICOUNT_PER_AREA_GROWTH:          return attrib_nuclife_growth        (ATTRIB_NUC_FOCI_COUNT_ALL_PER_AREA_PX, 0);
    case ATTRIB_NUCLIFE_FOCICOUNT_PER_AREA_GROWTH_PER_T:    return attrib_nuclife_growth_per_T  (ATTRIB_NUC_FOCI_COUNT_ALL_PER_AREA_PX, 0);

    case ATTRIB_NUCLIFE_CLOSTEST_DIST_TO_BORDER_PX:         return closestDist2Border();
    case ATTRIB_NUCLIFE_CLOSTEST_DIST_TO_BORDER_UM:         return closestDist2Border() * scale_px2um;
    case ATTRIB_NUCLIFE_IN_RANGE_PERMANENT:                 return double(inRangeAtAllTimes());

    case ATTRIB_NUCLIFE_MITOSIS_STARTS_WITH:                return double(has_MitosisStart());
    case ATTRIB_NUCLIFE_MITOSIS_ENDS_WITH:                  return double(has_MitosisEnd());
    case ATTRIB_NUCLIFE_MITOSIS_STARTS_ENDS_WITH:           return double(has_MitosisStartAndEnd());

    case ATTRIB_NUCLIFE_EXCLUDED:                           return double(is_excluded());

    default:                                                return 0;
    }
}

bool D_Bio_NucleusLife::attribute_is_focus_channel_dependent(size_t i_attrib)
{
    switch (i_attrib) {

    /*
    case DOES_NOT_EXIST_YET:
        return true;
        */

    default:
        return false;
    }
}

bool D_Bio_NucleusLife::attribute_is_value_channel_dependent(size_t i_attrib)
{
    switch (i_attrib) {

    /*
    case DOES_NOT_EXIST_YET:
        return true;
        */

    default:
        return false;
    }
}

double D_Bio_NucleusLife::closestDist2Border()
{
    double dist_min = INFINITY;

    for(size_t i = 0; i < vNucMembers.size(); i++)
    {
        double dist = D_Math::Distance(vNucMembers[i].centroid(), FrameBorderXY);
        if(dist < dist_min)
            dist_min = dist;
    }

    return dist_min;
}

bool D_Bio_NucleusLife::nearBorderAtLeastOnce()
{
    size_t n_nuc = members_count();

    for(size_t i = 0; i < n_nuc; i++)
    {
        D_Bio_NucleusBlob* pNuc = &(vNucMembers[i]);

        if(pNuc == nullptr)
            return true;

        if(pNuc->centroid().x < FrameInMarginXY.tl().x)
            return true;

        if(pNuc->centroid().x > FrameInMarginXY.br().x)
            return true;

        if(pNuc->centroid().y < FrameInMarginXY.tl().y)
            return true;

        if(pNuc->centroid().y > FrameInMarginXY.br().y)
            return true;
    }

    return false;
}


