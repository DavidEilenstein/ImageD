#include "d_visdat_range.h"

D_VisDat_Range::D_VisDat_Range()
{
    Init();
}

D_VisDat_Range::D_VisDat_Range(int X1, int X2, int Y1, int Y2, int Z1, int Z2, int T1, int T2, int S1, int S2, int P1, int P2)
{
    Init();

    vMin = {X1, Y1, Z1, T1, S1, P1};
    vMax = {X2, Y2, Z2, T2, S2, P2};

    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(!(vMin[d] >= 0 && vMax[d] > 0 && vMin[d] < vMax[d]))
        {
            vMin[d] = -1;
            vMax[d] = -1;
        }
}

D_VisDat_Range::D_VisDat_Range(D_VisDat_Slice_2D Slice_2d)
{
    Init();

    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
    {
        vMin[d] = Slice_2d.pos_Dim(d);
        vMax[d] = Slice_2d.pos_Dim(d) + 1;
    }
}

vector<Range> D_VisDat_Range::Ranges()
{
    vector<Range> vRG;
    vRG.resize(c_DIM_NUMBER_OF);

    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        vRG[d] = Range(vMin[d], vMax[d]);

    return vRG;
}

vector<Range> D_VisDat_Range::Ranges(D_VisDat_Dim VD_Dim_Source)
{
    vector<Range> vRG;
    vRG.resize(c_DIM_NUMBER_OF, Range::all());

    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(vMin[d] >= 0 && vMax[d] > 0 && vMin[d] < vMax[d] && vMin[d] < VD_Dim_Source.size_Dim(d) && vMax[d] <= VD_Dim_Source.size_Dim(d))
            vRG[d] = Range(vMin[d], vMax[d]);

    return vRG;
}

void D_VisDat_Range::Dim4Range_Init(D_VisDat_Dim *range_in_this_dim)
{
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
    {
        //force ranges/sizes to make sense in given dim/size

        vMin_inDim[d] = vMin[d];
        if(vMin_inDim[d] < 0)                                       vMin_inDim[d] = 0;
        if(vMin_inDim[d] >= range_in_this_dim->size_Dim(d) - 1)     vMin_inDim[d] = range_in_this_dim->size_Dim(d) - 1;

        vMax_inDim[d] = vMax[d];
        if(vMax_inDim[d] < 0)                                       vMax_inDim[d] = range_in_this_dim->size_Dim(d) - 1;
        if(vMax_inDim[d] >= range_in_this_dim->size_Dim(d))         vMax_inDim[d] = range_in_this_dim->size_Dim(d) - 1;

        if(vMin_inDim[d] > vMax_inDim[d])
        {
            int tmp = vMax_inDim[d];
            vMax_inDim[d] = vMin_inDim[d];
            vMax_inDim[d] = tmp;
        }
    }
}

vector<int> D_VisDat_Range::Dim4Range_Size()
{
    vector<int> v_size(c_DIM_NUMBER_OF);
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        v_size[d] = vMax_inDim[d] - vMin_inDim[d] + 1;
    return v_size;
}

void D_VisDat_Range::Init()
{
    vMin.resize(c_DIM_NUMBER_OF, -1);
    vMax.resize(c_DIM_NUMBER_OF, -1);
    vMin_inDim = {0, 0, 0, 0, 0, 0};
    vMax_inDim = {0, 0, 0, 0, 0, 0};
}
