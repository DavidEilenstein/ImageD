/************************************
 *   added:     04.01.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_BIO_NUCLEUSLIFE_H
#define D_BIO_NUCLEUSLIFE_H

//own
#include <d_enum.h>
#include <d_stat.h>
#include <d_math.h>
#include <d_bio_nucleusblob.h>
#include <d_bio_enum.h>

//Qt
#include <QFileDialog>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QDateTime>
#include <QInputDialog>

//general
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

//openCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespaces
using namespace std;
//using namespace cv; (prohibited because of abigous names with qtdatavisualization)
#include <d_opencv_typedefs.h>

class D_Bio_NucleusLife
{
    //              Parent
    //             |      |
    //     Sibbling        Member1
    //       ...           Member2
    //                       ...
    //                     MemberN (may be mitosis)
    //                    |       |
    //              Child1         Child2
    //
    //Existance of parent and childs is optional
    //Only members are taken into account for calcs

public:
    D_Bio_NucleusLife();

    bool set_ScalePx2Um(double scale);
    void set_range_XY(int x_min, int x_max, int y_min, int y_max)   {int w = x_max - x_min; int h = y_max - y_min; if(w > 0 && h > 0) set_range_XY(Rect(x_min, y_min, w, h));}
    void set_range_XY(Rect FrameOk)                                 {FrameInRegularRangeXY = FrameOk;}
    void set_sizeTime(size_t t_size)                                {size_time = t_size;}
    void set_time_irradiation(double t_irr)                         {time_irradiation = t_irr;}

    bool set_Parent(D_Bio_NucleusBlob* nuc_parent)                  {if(has_NoParent()) {pNucParent = nuc_parent; return true;} else {return false;}}
    bool set_Child1(D_Bio_NucleusBlob* nuc_child1)                  {if(has_Child1()) {pNucChild1 = nuc_child1; return true;} else {return false;}}
    bool set_Child2(D_Bio_NucleusBlob* nuc_child2)                  {if(has_Child2()) {pNucChild2 = nuc_child2; return true;} else {return false;}}
    bool set_Child (D_Bio_NucleusBlob* nuc_child)                   {if(has_Child1()) {return set_Child1(nuc_child);} else {return set_Child2(nuc_child);}}
    bool add_Member(D_Bio_NucleusBlob nuc);

    bool has_Parent()                                               {return pNucParent == nullptr;}
    bool has_Child1()                                               {return pNucChild1 == nullptr;}
    bool has_Child2()                                               {return pNucChild2 == nullptr;}
    bool has_NoParent()                                             {return !has_Parent();}
    bool has_NoChild()                                              {return !has_Child1() && !has_Child2();}
    bool has_NoChild1()                                             {return !has_Child1();}
    bool has_NoChild2()                                             {return !has_Child2();}
    bool has_ExactlyOneChild()                                      {return (has_Child1() && !has_Child2()) || (!has_Child1() && has_Child2());}
    bool has_AtLeastOneChild()                                      {return has_Child1() || has_Child2();}
    bool has_ExactlyTwoChilds()                                     {return has_Child1() && has_Child2();}
    bool has_LessThenTwoChilds()                                    {return has_ExactlyOneChild() || has_NoChild();}
    bool has_Sibbling()                                             {return has_Parent() ? pNucParent->matching_isMitosis() : false;}
    bool has_NoSibbling()                                           {return !has_Sibbling();}

    bool has_MitosisStart()                                         {return has_Parent();}
    bool has_MitosisEnd()                                           {return has_AtLeastOneChild();}
    bool has_MitosisStartEnd()                                      {return has_MitosisStart() && has_MitosisEnd();}

    D_Bio_NucleusBlob*              pNuc_parent()                   {return has_Parent() ? pNucParent : nullptr;}
    D_Bio_NucleusBlob*              pNuc_child1()                   {return has_Child1() ? pNucChild1 : nullptr;}
    D_Bio_NucleusBlob*              pNuc_child2()                   {return has_Child2() ? pNucChild2 : nullptr;}
    vector<D_Bio_NucleusBlob>       Nuc_members()                   {return vNucMembers;}
    D_Bio_NucleusBlob               Nuc_member(size_t i)            {return i < members_count() ? vNucMembers[i] : D_Bio_NucleusBlob();}
    D_Bio_NucleusBlob*              pNuc_member(size_t i)           {return i < members_count() ? &(vNucMembers[i]) : nullptr;}

    size_t                          members_count()                 {return vNucMembers.size();}

    D_Bio_Focus*                    pFocus(size_t i_nuc, size_t ch_foc, size_t i_foc);


    //foci attribs
    double                          attrib_foc      (size_t i_attrib, size_t ch_val, size_t ch_foc, size_t i_nuc, size_t i_foc);
    vector<double>                  attrib_foc      (size_t i_attrib, size_t ch_val, size_t ch_foc, size_t i_nuc);
    vector<vector<double>>          attrib_foc      (size_t i_attrib, size_t ch_val, size_t ch_foc);
    vector<vector<vector<double>>>  attrib_foc      (size_t i_attrib, size_t ch_val);
    bool                            attrib_foc      (vector<double>* pvAttribsToAppendTo, size_t i_attrib, size_t ch_val);
    bool                            attrib_foc      (vector<double>* pvAttribsToAppendTo, size_t i_attrib, size_t ch_val, size_t ch_foc);

    //nuc attribs
    double                          attrib_nuc      (size_t i_attrib, size_t ch_val, size_t i_nuc);
    double                          attrib_nuc_begin(size_t i_attrib, size_t ch_val)                    {return attrib_nuc(i_attrib, ch_val, 0);}
    double                          attrib_nuc_end  (size_t i_attrib, size_t ch_val)                    {return attrib_nuc(i_attrib, ch_val, members_count() - 1);}
    vector<double>                  attrib_nuc      (size_t i_attrib, size_t ch_val);
    bool                            attrib_nuc      (vector<double>* pvAttribsToAppendTo, size_t i_attrib, size_t ch_val);

    //nuc life attribs
    double                          attrib_nuclife(size_t i_attrib_nuclife);
    double                          attrib_nuclife_growth(size_t i_attrib_nuc, size_t ch_val)           {double v0 = attrib_nuc_begin(i_attrib_nuc, ch_val); double v1 = attrib_nuc_end(i_attrib_nuc, ch_val); return v0 > 0 ? v1 / v0 : 0;}
    double                          attrib_nuclife_growth_per_T(size_t i_attrib_nuc, size_t ch_val)     {double nt = members_count(); return nt > 0 ? attrib_nuclife_growth(i_attrib_nuc, ch_val) / nt : 0;}
    static bool                     attrib_nuclife_is_channel_dependent(size_t i_attrib);

    //thresholds
    bool                            nearBorderAtLeastOnce();
    bool                            inRangeAtAllTimes()             {return !nearBorderAtLeastOnce();}
    bool                            starts_before(size_t t)         {return attrib_nuclife(ATTRIB_NUCLIFE_START) < t;}
    bool                            starts_at(size_t t)             {return attrib_nuclife(ATTRIB_NUCLIFE_START) == t;}
    bool                            starts_after(size_t t)          {return attrib_nuclife(ATTRIB_NUCLIFE_START) > t;}
    bool                            ends_before(size_t t)           {return attrib_nuclife(ATTRIB_NUCLIFE_END) < t;}
    bool                            ends_at(size_t t)               {return attrib_nuclife(ATTRIB_NUCLIFE_END) == t;}
    bool                            ends_after(size_t t)            {return attrib_nuclife(ATTRIB_NUCLIFE_END) > t;}

private:
    //nuclei
    D_Bio_NucleusBlob*              pNucParent = nullptr;
    vector<D_Bio_NucleusBlob>       vNucMembers;           //last one is possible end mitosis
    D_Bio_NucleusBlob*              pNucChild1 = nullptr;
    D_Bio_NucleusBlob*              pNucChild2 = nullptr;

    //age
    size_t                          time_index_earliest = 0;
    size_t                          time_index_latest = 0;

    //scale
    double                          scale_px2um = 1.0;
    double                          scale_um2px = 1.0;

    //range and context
    Rect                            FrameInRegularRangeXY = Rect(-INT_MAX/2, -INT_MAX/2, INT_MAX, INT_MAX);
    size_t                          size_time = 0;
    double                          time_irradiation = 0;
};

#endif // D_BIO_NUCLEUSLIFE_H
