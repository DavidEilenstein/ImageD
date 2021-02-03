/************************************
 *   added:     02.02.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_multidimloop.h"

D_MultiDimLoop::D_MultiDimLoop(vector<size_t> start, vector<size_t> end)
{
    if(start.size() == end.size())
    {
        m_start = start;
        m_end = end;
        m_pos = m_start;
        n = start.size();
    }
}

bool D_MultiDimLoop::valid()
{
    bool found_existent_pos = false;
    for(size_t i = 0; i < n; i++)
    {
        if(m_start[i] > m_end[i])
            return false;

        if(m_start[i] < m_end[i])
            found_existent_pos = true;
    }

    return found_existent_pos;
}

bool D_MultiDimLoop::next()
{
    for(size_t i = 0; i < n; i++)               //loop dims
    {
        if(m_pos[i] < m_end[i])                 //first dim that is not at max
        {
            for(size_t j = 0; j < i; j++)       //loop dims that are lesser significant
                m_pos[j] = m_start[j];          //reset lesser significant dims to start

            m_pos[i]++;                         //increase least siginificant dim that is not at max
            return true;                        //return true (next step found)
        }
    }

    return false;                               //end of loop reached
}
