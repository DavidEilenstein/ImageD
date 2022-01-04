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
    //Existance of parent and childs ist optional
    //Only members are taken into account for calcs

public:
    D_Bio_NucleusLife();

    bool set_ScalePx2Um(double scale);

    bool set_Parent(D_Bio_NucleusBlob* nuc_parent)          {if(has_NoParent()) {pNucParent = nuc_parent; return true;} else {return false;}}
    bool set_Child1(D_Bio_NucleusBlob* nuc_child1)          {if(has_Child1()) {pNucChild1 = nuc_child1; return true;} else {return false;}}
    bool set_Child2(D_Bio_NucleusBlob* nuc_child2)          {if(has_Child2()) {pNucChild2 = nuc_child2; return true;} else {return false;}}
    bool set_Child (D_Bio_NucleusBlob* nuc_child)           {if(has_Child1()) {return set_Child1(nuc_child);} else {return set_Child2(nuc_child);}}
    bool add_Member(D_Bio_NucleusBlob* nuc);

    bool has_Parent()                                       {return pNucParent == nullptr;}
    bool has_Child1()                                       {return pNucChild1 == nullptr;}
    bool has_Child2()                                       {return pNucChild2 == nullptr;}
    bool has_NoParent()                                     {return !has_Parent();}
    bool has_NoChild()                                      {return !has_Child1() && !has_Child2();}
    bool has_NoChild1()                                     {return !has_Child1();}
    bool has_NoChild2()                                     {return !has_Child2();}
    bool has_ExactlyOneChild()                              {return (has_Child1() && !has_Child2()) || (!has_Child1() && has_Child2());}
    bool has_AtLeastOneChild()                              {return has_Child1() || has_Child2();}
    bool has_ExactlyTwoChilds()                             {return has_Child1() && has_Child2();}
    bool has_LessThenTwoChilds()                            {return has_ExactlyOneChild() || has_NoChild();}
    bool has_Sibbling()                                     {return has_Parent() ? pNucParent->matching_isMitosis() : false;}
    bool has_NoSibbling()                                   {return !has_Sibbling();}

    bool has_MitosisStart()                                 {return has_Parent();}
    bool has_MitosisEnd()                                   {return has_AtLeastOneChild();}
    bool has_MitosisStartEnd()                              {return has_MitosisStart() && has_MitosisEnd();}

    D_Bio_NucleusBlob*          pNuc_parent()               {return has_Parent() ? pNucParent : nullptr;}
    D_Bio_NucleusBlob*          pNuc_child1()               {return has_Child1() ? pNucChild1 : nullptr;}
    D_Bio_NucleusBlob*          pNuc_child2()               {return has_Child2() ? pNucChild2 : nullptr;}
    vector<D_Bio_NucleusBlob*>  pNuc_members()              {return vpNucMembers;}

    size_t                      members_count()             {return vpNucMembers.size();}

    double                      attrib_geo( size_t i_attrib,            size_t i_obj);
    double                      attrib_val( size_t i_attrib, size_t ch, size_t i_obj);
    double                      attrib(     size_t i_attrib, size_t ch, size_t i_obj);

    vector<double>              attrib_geo( size_t i_attrib);
    vector<double>              attrib_val( size_t i_attrib, size_t ch);
    vector<double>              attrib(     size_t i_attrib, size_t ch);

private:
    D_Bio_NucleusBlob*          pNucParent = nullptr;
    vector<D_Bio_NucleusBlob*>  vpNucMembers;           //last one is possible end mitosis
    D_Bio_NucleusBlob*          pNucChild1 = nullptr;
    D_Bio_NucleusBlob*          pNucChild2 = nullptr;

    double                      scale_px2um = 1.0;
    double                      scale_um2px = 1.0;



};

#endif // D_BIO_NUCLEUSLIFE_H
