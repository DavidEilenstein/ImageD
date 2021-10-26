/************************************
 *   added:     04.01.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_bio_nucleuspedigree.h"

D_Bio_NucleusPedigree::D_Bio_NucleusPedigree()
{
    //init score weights
    vScoreWeights.resize(SCORE_WEIGHT_NUMBER_OF, 0);
    vScoreWeights[SCORE_WEIGHT_SPEED] = 1;
}

void D_Bio_NucleusPedigree::clear()
{
    size_time = 0;
    vvNucBlobs.clear();
}

void D_Bio_NucleusPedigree::set_size_time(size_t t_size)
{
    size_time = t_size;
    vvNucBlobs.resize(size_time);
}
