/************************************
 *   added:     02.02.2020          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_MULTIDIMLOOP_H
#define D_MULTIDIMLOOP_H

#include <vector>

using namespace std;

class D_MultiDimLoop
{
public:
    D_MultiDimLoop(vector<size_t> start, vector<size_t> end);
    bool valid();
    bool next();
    vector<size_t> pos() {return m_pos;}

private:
    vector<size_t> m_start;
    vector<size_t> m_end;
    vector<size_t> m_pos;
    size_t n = 0;
};

#endif // D_MULTIDIMLOOP_H

