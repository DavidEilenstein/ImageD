/************************************
 *   added:     16.04.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_visdat_proc.h"

D_VisDat_Proc::D_VisDat_Proc()
{
    //never call it (wrapper class - all methods static)
}

int D_VisDat_Proc::Wrap_VD(D_VisDat_Slicing slice, function<int (Mat *)> img_proc, D_VisDat_Obj *pVD_Out)
{
    //Slicing
    slice.loop_Init(pVD_Out->Dim());              //pVD_Out must have a valid dim here or random things will happen!
    int sub_img_count = slice.loop_SliceCount();

    //errors
    vector<int>     vErrors(sub_img_count, ER_okay);

    //threads
    vector<thread>  vThread(sub_img_count);

    //dimensionality to wrap
    switch (slice.ProcDims_Count()) {

    /*case 1:
        //start threads
        for(size_t t = 0; t < vThread.size(); t++)
            vThread[t] = thread(                        //in new thread
                        Wrap_1D_img0,                   //Wrap_1D is executed
                        &(vErrors[t]),                  //returning an error code
                        slice.loop1D_SliceByIndex(t),   //for processing given 1D slice
                        img_proc,                       //with passed img_proc function
                        pVD_Out);
        break;*/

    case 2:
        //start threads
        for(size_t t = 0; t < vThread.size(); t++)
            vThread[t] = thread(                        //in new thread
                        Wrap_2D_img0,                   //Wrap_2D is executed
                        &(vErrors[t]),                  //returning an error code
                        slice.loop2D_SliceByIndex(t),   //for processing given 2D slice
                        img_proc,                       //with passed img_proc function
                        pVD_Out);
        break;

    case 3:
        //start threads
        for(size_t t = 0; t < vThread.size(); t++)
            vThread[t] = thread(                        //in new thread
                        Wrap_3D_img0,                   //Wrap_3D is executed
                        &(vErrors[t]),                  //returning an error code
                        slice.loop3D_SliceByIndex(t),   //for processing given 3D slice
                        img_proc,                       //with passed img_proc function
                        pVD_Out);
        break;

    default:
        return ER_dim_missmatch;
        break;
    }

    //synch threads
    for(size_t t = 0; t < vThread.size(); t++)
        vThread[t].join();

    //check for errors
    for(size_t t = 0; t < vThread.size(); t++)
        if(vErrors[t] != ER_okay)
            return vErrors[t];

    //no error occured :-)
    return ER_okay;
}

int D_VisDat_Proc::Wrap_VD(D_VisDat_Slicing slice, function<int (Mat *, Mat *)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In)
{
    //Slicing
    slice.loop_Init(pVD_In->Dim());
    int sub_img_count = slice.loop_SliceCount();

    //errors
    vector<int>     vErrors(sub_img_count, ER_okay);

    //threads
    vector<thread>  vThread(sub_img_count);

    //dimensionality to wrap
    switch (slice.ProcDims_Count()) {

    /*case 1:
        //start threads
        for(size_t t = 0; t < vThread.size(); t++)
            vThread[t] = thread(                        //in new thread
                        Wrap_1D_img1,                   //Wrap_1D is executed
                        &(vErrors[t]),                  //returning an error code
                        slice.loop1D_SliceByIndex(t),   //for processing given 1D slice
                        img_proc,                       //with passed img_proc function
                        pVD_Out,
                        pVD_In);
        break;*/

    case 2:
        //start threads
        for(size_t t = 0; t < vThread.size(); t++)
            vThread[t] = thread(                        //in new thread
                        Wrap_2D_img1,                   //Wrap_2D is executed
                        &(vErrors[t]),                  //returning an error code
                        slice.loop2D_SliceByIndex(t),   //for processing given 2D slice
                        img_proc,                       //with passed img_proc function
                        pVD_Out,
                        pVD_In);
        break;

    case 3:
        //start threads
        for(size_t t = 0; t < vThread.size(); t++)
            vThread[t] = thread(                        //in new thread
                        Wrap_3D_img1,                   //Wrap_3D is executed
                        &(vErrors[t]),                  //returning an error code
                        slice.loop3D_SliceByIndex(t),   //for processing given 3D slice
                        img_proc,                       //with passed img_proc function
                        pVD_Out,
                        pVD_In);
        break;

    default:
        return ER_dim_missmatch;
        break;
    }


    //synch threads
    for(size_t t = 0; t < vThread.size(); t++)
        vThread[t].join();

    //check for errors
    for(size_t t = 0; t < vThread.size(); t++)
        if(vErrors[t] != ER_okay)
            return vErrors[t];

    //no error occured :-)
    return ER_okay;
}

int D_VisDat_Proc::Wrap_VD(D_VisDat_Slicing slice, function<int (Mat *, Mat *, Mat *)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2)
{
    //Slicing
    slice.loop_Init(pVD_In1->Dim());
    int sub_img_count = slice.loop_SliceCount();

    //errors
    vector<int>     vErrors(sub_img_count, ER_okay);

    //threads
    vector<thread>  vThread(sub_img_count);

    //dimensionality to wrap
    switch (slice.ProcDims_Count()) {

    /*case 1:
        //start threads
        for(size_t t = 0; t < vThread.size(); t++)
            vThread[t] = thread(                        //in new thread
                        Wrap_1D_img2,                   //Wrap_1D is executed
                        &(vErrors[t]),                  //returning an error code
                        slice.loop1D_SliceByIndex(t),   //for processing given 1D slice
                        img_proc,                       //with passed img_proc function
                        pVD_Out,
                        pVD_In1,
                        pVD_In2);
        break;*/

    case 2:
        //start threads
        for(size_t t = 0; t < vThread.size(); t++)
            vThread[t] = thread(                        //in new thread
                        Wrap_2D_img2,                   //Wrap_2D is executed
                        &(vErrors[t]),                  //returning an error code
                        slice.loop2D_SliceByIndex(t),   //for processing given 2D slice
                        img_proc,                       //with passed img_proc function
                        pVD_Out,
                        pVD_In1,
                        pVD_In2);
        break;

    case 3:
        //start threads
        for(size_t t = 0; t < vThread.size(); t++)
            vThread[t] = thread(                        //in new thread
                        Wrap_3D_img2,                   //Wrap_3D is executed
                        &(vErrors[t]),                  //returning an error code
                        slice.loop3D_SliceByIndex(t),   //for processing given 3D slice
                        img_proc,                       //with passed img_proc function
                        pVD_Out,
                        pVD_In1,
                        pVD_In2);
        break;

    default:
        return ER_dim_missmatch;
        break;
    }


    //synch threads
    for(size_t t = 0; t < vThread.size(); t++)
        vThread[t].join();

    //check for errors
    for(size_t t = 0; t < vThread.size(); t++)
        if(vErrors[t] != ER_okay)
            return vErrors[t];

    //no error occured :-)
    return ER_okay;
}

int D_VisDat_Proc::Wrap_VD(D_VisDat_Slicing slice, function<int (Mat *, Mat *, Mat *, Mat *)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3)
{
    //Slicing
    slice.loop_Init(pVD_In1->Dim());
    int sub_img_count = slice.loop_SliceCount();

    //errors
    vector<int>     vErrors(sub_img_count, ER_okay);

    //threads
    vector<thread>  vThread(sub_img_count);

    //dimensionality to wrap
    switch (slice.ProcDims_Count()) {

    /*case 1:
        //start threads
        for(size_t t = 0; t < vThread.size(); t++)
            vThread[t] = thread(                        //in new thread
                        Wrap_1D_img3,                   //Wrap_1D is executed
                        &(vErrors[t]),                  //returning an error code
                        slice.loop1D_SliceByIndex(t),   //for processing given 31 slice
                        img_proc,                       //with passed img_proc function
                        pVD_Out,
                        pVD_In1,
                        pVD_In2,
                        pVD_In3);
        break;*/

    case 2:
        //start threads
        for(size_t t = 0; t < vThread.size(); t++)
            vThread[t] = thread(                        //in new thread
                        Wrap_2D_img3,                   //Wrap_2D is executed
                        &(vErrors[t]),                  //returning an error code
                        slice.loop2D_SliceByIndex(t),   //for processing given 2D slice
                        img_proc,                       //with passed img_proc function
                        pVD_Out,
                        pVD_In1,
                        pVD_In2,
                        pVD_In3);
        break;

    case 3:
        //start threads
        for(size_t t = 0; t < vThread.size(); t++)
            vThread[t] = thread(                        //in new thread
                        Wrap_3D_img3,                   //Wrap_3D is executed
                        &(vErrors[t]),                  //returning an error code
                        slice.loop3D_SliceByIndex(t),   //for processing given 3D slice
                        img_proc,                       //with passed img_proc function
                        pVD_Out,
                        pVD_In1,
                        pVD_In2,
                        pVD_In3);
        break;

    default:
        return ER_dim_missmatch;
        break;
    }


    //synch threads
    for(size_t t = 0; t < vThread.size(); t++)
        vThread[t].join();

    //check for errors
    for(size_t t = 0; t < vThread.size(); t++)
        if(vErrors[t] != ER_okay)
            return vErrors[t];

    //no error occured :-)
    return ER_okay;
}

int D_VisDat_Proc::Wrap_VD(D_VisDat_Slicing slice, function<int (Mat *, Mat *, Mat *, Mat *, Mat *)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3, D_VisDat_Obj *pVD_In4)
{
    //Slicing
    slice.loop_Init(pVD_In1->Dim());
    int sub_img_count = slice.loop_SliceCount();

    //errors
    vector<int>     vErrors(sub_img_count, ER_okay);

    //threads
    vector<thread>  vThread(sub_img_count);

    //dimensionality to wrap
    switch (slice.ProcDims_Count()) {

    /*case 1:
        //start threads
        for(size_t t = 0; t < vThread.size(); t++)
            vThread[t] = thread(                        //in new thread
                        Wrap_1D_img4,                   //Wrap_1D is executed
                        &(vErrors[t]),                  //returning an error code
                        slice.loop1D_SliceByIndex(t),   //for processing given 1D slice
                        img_proc,                       //with passed img_proc function
                        pVD_Out,
                        pVD_In1,
                        pVD_In2,
                        pVD_In3,
                        pVD_In4);
        break;*/

    case 2:
        //start threads
        for(size_t t = 0; t < vThread.size(); t++)
            vThread[t] = thread(                        //in new thread
                        Wrap_2D_img4,                   //Wrap_2D is executed
                        &(vErrors[t]),                  //returning an error code
                        slice.loop2D_SliceByIndex(t),   //for processing given 2D slice
                        img_proc,                       //with passed img_proc function
                        pVD_Out,
                        pVD_In1,
                        pVD_In2,
                        pVD_In3,
                        pVD_In4);
        break;

    case 3:
        //start threads
        for(size_t t = 0; t < vThread.size(); t++)
            vThread[t] = thread(                        //in new thread
                        Wrap_3D_img4,                   //Wrap_3D is executed
                        &(vErrors[t]),                  //returning an error code
                        slice.loop3D_SliceByIndex(t),   //for processing given 3D slice
                        img_proc,                       //with passed img_proc function
                        pVD_Out,
                        pVD_In1,
                        pVD_In2,
                        pVD_In3,
                        pVD_In4);
        break;

    default:
        return ER_dim_missmatch;
        break;
    }


    //synch threads
    for(size_t t = 0; t < vThread.size(); t++)
        vThread[t].join();

    //check for errors
    for(size_t t = 0; t < vThread.size(); t++)
        if(vErrors[t] != ER_okay)
            return vErrors[t];

    //no error occured :-)
    return ER_okay;
}

int D_VisDat_Proc::Wrap_VD_SameSizeType(D_VisDat_Slicing slice, function<int (Mat *, Mat *)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In)
{
    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                pVD_In->type());

    return Wrap_VD(
                slice,
                img_proc,
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Wrap_VD_SameSizeType(D_VisDat_Slicing slice, function<int (Mat *, Mat *, Mat *)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2)
{
    *pVD_Out = D_VisDat_Obj(
                pVD_In1->Dim(),
                pVD_In1->type());

    return Wrap_VD(
                slice,
                img_proc,
                pVD_Out,
                pVD_In1,
                pVD_In2);
}

int D_VisDat_Proc::Wrap_VD_SameSizeType(D_VisDat_Slicing slice, function<int (Mat *, Mat *, Mat *, Mat *)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3)
{
    *pVD_Out = D_VisDat_Obj(
                pVD_In1->Dim(),
                pVD_In1->type());

    return Wrap_VD(
                slice,
                img_proc,
                pVD_Out,
                pVD_In1,
                pVD_In2,
                pVD_In3);
}

int D_VisDat_Proc::Wrap_VD_SameSizeType(D_VisDat_Slicing slice, function<int (Mat *, Mat *, Mat *, Mat *, Mat *)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3, D_VisDat_Obj *pVD_In4)
{
    *pVD_Out = D_VisDat_Obj(
                pVD_In1->Dim(),
                pVD_In1->type());

    return Wrap_VD(
                slice,
                img_proc,
                pVD_Out,
                pVD_In1,
                pVD_In2,
                pVD_In3,
                pVD_In4);
}


void D_VisDat_Proc::Wrap_2D_img0(int *ER, D_VisDat_Slice_2D plane, function<int (Mat *)> img_proc, D_VisDat_Obj *pVD_Out)
{
    //tmp 2D mats
    Mat MA_tmp2d_out;

    //proc
    *ER = img_proc(
                &MA_tmp2d_out);
    if(*ER != ER_okay)
    {
        MA_tmp2d_out.release();
        return;
    }

    //write
    *ER = D_VisDat_Proc::Write_2D_Plane(
                pVD_Out,
                &MA_tmp2d_out,
                plane);

    //free memory & return
    MA_tmp2d_out.release();
    return;
}

void D_VisDat_Proc::Wrap_2D_img1(int *ER, D_VisDat_Slice_2D plane, function<int (Mat *, Mat *)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In)
{
    //tmp 2D mats
    Mat MA_tmp2d_in;
    Mat MA_tmp2d_out;

    //read
    *ER = D_VisDat_Proc::Read_2D_Plane(
                &MA_tmp2d_in,
                pVD_In,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp2d_in.release();
        MA_tmp2d_out.release();
        return;
    }

    //proc
    *ER = img_proc(
                &MA_tmp2d_out,
                &MA_tmp2d_in);
    if(*ER != ER_okay)
    {
        MA_tmp2d_in.release();
        MA_tmp2d_out.release();
        return;
    }

    //write
    *ER = D_VisDat_Proc::Write_2D_Plane(
                pVD_Out,
                &MA_tmp2d_out,
                plane);

    //free memory & return
    MA_tmp2d_in.release();
    MA_tmp2d_out.release();
    return;
}

void D_VisDat_Proc::Wrap_2D_img2(int *ER, D_VisDat_Slice_2D plane, function<int (Mat *, Mat *, Mat *)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2)
{
    //tmp 2D mats
    Mat MA_tmp2d_in1;
    Mat MA_tmp2d_in2;
    Mat MA_tmp2d_out;

    //read1
    *ER = D_VisDat_Proc::Read_2D_Plane(
                &MA_tmp2d_in1,
                pVD_In1,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp2d_in1.release();
        MA_tmp2d_in2.release();
        MA_tmp2d_out.release();
        return;
    }

    //read2
    *ER = D_VisDat_Proc::Read_2D_Plane(
                &MA_tmp2d_in2,
                pVD_In2,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp2d_in1.release();
        MA_tmp2d_in2.release();
        MA_tmp2d_out.release();
        return;
    }

    //proc
    *ER = img_proc(
                &MA_tmp2d_out,
                &MA_tmp2d_in1,
                &MA_tmp2d_in2);
    if(*ER != ER_okay)
    {
        MA_tmp2d_in1.release();
        MA_tmp2d_in2.release();
        MA_tmp2d_out.release();
        return;
    }

    //write
    *ER = D_VisDat_Proc::Write_2D_Plane(
                pVD_Out,
                &MA_tmp2d_out,
                plane);

    //free memory & return
    MA_tmp2d_in1.release();
    MA_tmp2d_in2.release();
    MA_tmp2d_out.release();
    return;
}

void D_VisDat_Proc::Wrap_2D_img3(int *ER, D_VisDat_Slice_2D plane, function<int (Mat *, Mat *, Mat *, Mat *)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3)
{
    //tmp 2D mats
    Mat MA_tmp2d_in1;
    Mat MA_tmp2d_in2;
    Mat MA_tmp2d_in3;
    Mat MA_tmp2d_out;

    //read1
    *ER = D_VisDat_Proc::Read_2D_Plane(
                &MA_tmp2d_in1,
                pVD_In1,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp2d_in1.release();
        MA_tmp2d_in2.release();
        MA_tmp2d_in3.release();
        MA_tmp2d_out.release();
        return;
    }

    //read2
    *ER = D_VisDat_Proc::Read_2D_Plane(
                &MA_tmp2d_in2,
                pVD_In2,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp2d_in1.release();
        MA_tmp2d_in2.release();
        MA_tmp2d_in3.release();
        MA_tmp2d_out.release();
        return;
    }

    //read3
    *ER = D_VisDat_Proc::Read_2D_Plane(
                &MA_tmp2d_in3,
                pVD_In3,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp2d_in1.release();
        MA_tmp2d_in2.release();
        MA_tmp2d_in3.release();
        MA_tmp2d_out.release();
        return;
    }

    //proc
    *ER = img_proc(
                &MA_tmp2d_out,
                &MA_tmp2d_in1,
                &MA_tmp2d_in2,
                &MA_tmp2d_in3);
    if(*ER != ER_okay)
    {
        MA_tmp2d_in1.release();
        MA_tmp2d_in2.release();
        MA_tmp2d_in3.release();
        MA_tmp2d_out.release();
        return;
    }

    //write
    *ER = D_VisDat_Proc::Write_2D_Plane(
                pVD_Out,
                &MA_tmp2d_out,
                plane);

    //free memory & return
    MA_tmp2d_in1.release();
    MA_tmp2d_in2.release();
    MA_tmp2d_in3.release();
    MA_tmp2d_out.release();
    return;
}

void D_VisDat_Proc::Wrap_2D_img4(int *ER, D_VisDat_Slice_2D plane, function<int (Mat *, Mat *, Mat *, Mat *, Mat *)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3, D_VisDat_Obj *pVD_In4)
{
    //tmp 2D mats
    Mat MA_tmp2d_in1;
    Mat MA_tmp2d_in2;
    Mat MA_tmp2d_in3;
    Mat MA_tmp2d_in4;
    Mat MA_tmp2d_out;

    //read1
    *ER = D_VisDat_Proc::Read_2D_Plane(
                &MA_tmp2d_in1,
                pVD_In1,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp2d_in1.release();
        MA_tmp2d_in2.release();
        MA_tmp2d_in3.release();
        MA_tmp2d_in4.release();
        MA_tmp2d_out.release();
        return;
    }

    //read2
    *ER = D_VisDat_Proc::Read_2D_Plane(
                &MA_tmp2d_in2,
                pVD_In2,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp2d_in1.release();
        MA_tmp2d_in2.release();
        MA_tmp2d_in3.release();
        MA_tmp2d_in4.release();
        MA_tmp2d_out.release();
        return;
    }

    //read3
    *ER = D_VisDat_Proc::Read_2D_Plane(
                &MA_tmp2d_in3,
                pVD_In3,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp2d_in1.release();
        MA_tmp2d_in2.release();
        MA_tmp2d_in3.release();
        MA_tmp2d_in4.release();
        MA_tmp2d_out.release();
        return;
    }

    //read4
    *ER = D_VisDat_Proc::Read_2D_Plane(
                &MA_tmp2d_in4,
                pVD_In4,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp2d_in1.release();
        MA_tmp2d_in2.release();
        MA_tmp2d_in3.release();
        MA_tmp2d_in4.release();
        MA_tmp2d_out.release();
        return;
    }

    //proc
    *ER = img_proc(
                &MA_tmp2d_out,
                &MA_tmp2d_in1,
                &MA_tmp2d_in2,
                &MA_tmp2d_in3,
                &MA_tmp2d_in4);
    if(*ER != ER_okay)
    {
        MA_tmp2d_in1.release();
        MA_tmp2d_in2.release();
        MA_tmp2d_in3.release();
        MA_tmp2d_in4.release();
        MA_tmp2d_out.release();
        return;
    }

    //write
    *ER = D_VisDat_Proc::Write_2D_Plane(
                pVD_Out,
                &MA_tmp2d_out,
                plane);

    //free memory & return
    MA_tmp2d_in1.release();
    MA_tmp2d_in2.release();
    MA_tmp2d_in3.release();
    MA_tmp2d_in4.release();
    MA_tmp2d_out.release();
    return;
}

void D_VisDat_Proc::Wrap_3D_img0(int *ER, D_VisDat_Slice_3D plane, function<int (Mat *)> img_proc, D_VisDat_Obj *pVD_Out)
{
    //tmp 3D mats
    Mat MA_tmp3d_out;

    //proc
    *ER = img_proc(
                &MA_tmp3d_out);
    if(*ER != ER_okay)
    {
        MA_tmp3d_out.release();
        return;
    }

    //write
    *ER = D_VisDat_Proc::Write_3D_Cuboid(
                pVD_Out,
                &MA_tmp3d_out,
                plane);

    //free memory & return
    MA_tmp3d_out.release();
    return;
}

void D_VisDat_Proc::Wrap_3D_img1(int *ER, D_VisDat_Slice_3D plane, function<int (Mat *, Mat *)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In)
{
    //tmp 3D mats
    Mat MA_tmp3d_in;
    Mat MA_tmp3d_out;

    //read
    *ER = D_VisDat_Proc::Read_3D_Cuboid(
                &MA_tmp3d_in,
                pVD_In,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp3d_in.release();
        MA_tmp3d_out.release();
        return;
    }

    //proc
    *ER = img_proc(
                &MA_tmp3d_out,
                &MA_tmp3d_in);
    if(*ER != ER_okay)
    {
        MA_tmp3d_in.release();
        MA_tmp3d_out.release();
        return;
    }

    //write
    *ER = D_VisDat_Proc::Write_3D_Cuboid(
                pVD_Out,
                &MA_tmp3d_out,
                plane);

    //free memory & return
    MA_tmp3d_in.release();
    MA_tmp3d_out.release();
    return;
}

void D_VisDat_Proc::Wrap_3D_img2(int *ER, D_VisDat_Slice_3D plane, function<int (Mat *, Mat *, Mat *)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2)
{
    //tmp 3D mats
    Mat MA_tmp3d_in1;
    Mat MA_tmp3d_in2;
    Mat MA_tmp3d_out;

    //read1
    *ER = D_VisDat_Proc::Read_3D_Cuboid(
                &MA_tmp3d_in1,
                pVD_In1,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp3d_in1.release();
        MA_tmp3d_in2.release();
        MA_tmp3d_out.release();
        return;
    }

    //read2
    *ER = D_VisDat_Proc::Read_3D_Cuboid(
                &MA_tmp3d_in2,
                pVD_In2,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp3d_in1.release();
        MA_tmp3d_in2.release();
        MA_tmp3d_out.release();
        return;
    }

    //proc
    *ER = img_proc(
                &MA_tmp3d_out,
                &MA_tmp3d_in1,
                &MA_tmp3d_in2);
    if(*ER != ER_okay)
    {
        MA_tmp3d_in1.release();
        MA_tmp3d_in2.release();
        MA_tmp3d_out.release();
        return;
    }

    //write
    *ER = D_VisDat_Proc::Write_3D_Cuboid(
                pVD_Out,
                &MA_tmp3d_out,
                plane);

    //free memory & return
    MA_tmp3d_in1.release();
    MA_tmp3d_in2.release();
    MA_tmp3d_out.release();
    return;
}

void D_VisDat_Proc::Wrap_3D_img3(int *ER, D_VisDat_Slice_3D plane, function<int (Mat *, Mat *, Mat *, Mat *)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3)
{
    //tmp 3D mats
    Mat MA_tmp3d_in1;
    Mat MA_tmp3d_in2;
    Mat MA_tmp3d_in3;
    Mat MA_tmp3d_out;

    //read1
    *ER = D_VisDat_Proc::Read_3D_Cuboid(
                &MA_tmp3d_in1,
                pVD_In1,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp3d_in1.release();
        MA_tmp3d_in2.release();
        MA_tmp3d_in3.release();
        MA_tmp3d_out.release();
        return;
    }

    //read2
    *ER = D_VisDat_Proc::Read_3D_Cuboid(
                &MA_tmp3d_in2,
                pVD_In2,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp3d_in1.release();
        MA_tmp3d_in2.release();
        MA_tmp3d_in3.release();
        MA_tmp3d_out.release();
        return;
    }

    //read3
    *ER = D_VisDat_Proc::Read_3D_Cuboid(
                &MA_tmp3d_in3,
                pVD_In3,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp3d_in1.release();
        MA_tmp3d_in2.release();
        MA_tmp3d_in3.release();
        MA_tmp3d_out.release();
        return;
    }

    //proc
    *ER = img_proc(
                &MA_tmp3d_out,
                &MA_tmp3d_in1,
                &MA_tmp3d_in2,
                &MA_tmp3d_in3);
    if(*ER != ER_okay)
    {
        MA_tmp3d_in1.release();
        MA_tmp3d_in2.release();
        MA_tmp3d_in3.release();
        MA_tmp3d_out.release();
        return;
    }

    //write
    *ER = D_VisDat_Proc::Write_3D_Cuboid(
                pVD_Out,
                &MA_tmp3d_out,
                plane);

    //free memory & return
    MA_tmp3d_in1.release();
    MA_tmp3d_in2.release();
    MA_tmp3d_in3.release();
    MA_tmp3d_out.release();
    return;
}

void D_VisDat_Proc::Wrap_3D_img4(int *ER, D_VisDat_Slice_3D plane, function<int (Mat *, Mat *, Mat *, Mat *, Mat *)> img_proc, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3, D_VisDat_Obj *pVD_In4)
{
    //tmp 3D mats
    Mat MA_tmp3d_in1;
    Mat MA_tmp3d_in2;
    Mat MA_tmp3d_in3;
    Mat MA_tmp3d_in4;
    Mat MA_tmp3d_out;

    //read1
    *ER = D_VisDat_Proc::Read_3D_Cuboid(
                &MA_tmp3d_in1,
                pVD_In1,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp3d_in1.release();
        MA_tmp3d_in2.release();
        MA_tmp3d_in3.release();
        MA_tmp3d_in4.release();
        MA_tmp3d_out.release();
        return;
    }

    //read2
    *ER = D_VisDat_Proc::Read_3D_Cuboid(
                &MA_tmp3d_in2,
                pVD_In2,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp3d_in1.release();
        MA_tmp3d_in2.release();
        MA_tmp3d_in3.release();
        MA_tmp3d_in4.release();
        MA_tmp3d_out.release();
        return;
    }

    //read3
    *ER = D_VisDat_Proc::Read_3D_Cuboid(
                &MA_tmp3d_in3,
                pVD_In3,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp3d_in1.release();
        MA_tmp3d_in2.release();
        MA_tmp3d_in3.release();
        MA_tmp3d_in4.release();
        MA_tmp3d_out.release();
        return;
    }

    //read4
    *ER = D_VisDat_Proc::Read_3D_Cuboid(
                &MA_tmp3d_in4,
                pVD_In4,
                plane);
    if(*ER != ER_okay)
    {
        MA_tmp3d_in1.release();
        MA_tmp3d_in2.release();
        MA_tmp3d_in3.release();
        MA_tmp3d_in4.release();
        MA_tmp3d_out.release();
        return;
    }

    //proc
    *ER = img_proc(
                &MA_tmp3d_out,
                &MA_tmp3d_in1,
                &MA_tmp3d_in2,
                &MA_tmp3d_in3,
                &MA_tmp3d_in4);
    if(*ER != ER_okay)
    {
        MA_tmp3d_in1.release();
        MA_tmp3d_in2.release();
        MA_tmp3d_in3.release();
        MA_tmp3d_in4.release();
        MA_tmp3d_out.release();
        return;
    }

    //write
    *ER = D_VisDat_Proc::Write_3D_Cuboid(
                pVD_Out,
                &MA_tmp3d_out,
                plane);

    //free memory & return
    MA_tmp3d_in1.release();
    MA_tmp3d_in2.release();
    MA_tmp3d_in3.release();
    MA_tmp3d_in4.release();
    MA_tmp3d_out.release();
    return;
}

int D_VisDat_Proc::Save_VD_ToBinaryFile(D_VisDat_Obj *pVD_Save, QString QS_SavePath)
{
    //FileInfo
    QFileInfo FI_Path(QS_SavePath);

    //Errors
    if(FI_Path.suffix() != "visdat")
        return ER_other;

    //open file
    ofstream file(FI_Path.absoluteFilePath().toStdString(), ios::binary);
    if(!file.is_open())
        return ER_other;
    file.seekp(0);//start at the beginning

    //Create Header
    D_VisDat_Header Header(
                pVD_Save->pDim()->size_DimsVec(),
                pVD_Save->type());

    //Save Header
    file.write(reinterpret_cast<char*>(&Header), sizeof(D_VisDat_Header));

    //Save Mat content
    file.write(reinterpret_cast<char*>(pVD_Save->pMA_full()->data), pVD_Save->size_Byte());

    //finish
    file.close();
    return ER_okay;
}

int D_VisDat_Proc::Save_VD_Single(D_VisDat_Obj *pVD_Save, QString QS_SavePath, D_VisDat_Slice_2D slice)
{
    if(QS_SavePath.isEmpty())                       return ER_file_not_exist;

    QFileInfo FI_Save(QS_SavePath);

    Mat MA_tmp_Slice;
    Read_2D_Plane(
                &MA_tmp_Slice,
                pVD_Save,
                slice);

    bool bER = imwrite(
                FI_Save.absoluteFilePath().toStdString(),
                MA_tmp_Slice);

    if(bER)
        return ER_okay;
    else
        return ER_other;
}

int D_VisDat_Proc::Save_VD_List(D_VisDat_Obj *pVD_Save, QString QS_Dir, QString QS_ImgName, QString QS_Suffix, int DimList, int DimImgX, int DimImgY)
{
    //checks
    if(DimList >= c_DIM_NUMBER_OF || DimList < 0)   return ER_dim_out_of_range;
    if(DimImgX >= c_DIM_NUMBER_OF || DimImgX < 0)   return ER_dim_out_of_range;
    if(DimImgY >= c_DIM_NUMBER_OF || DimImgY < 0)   return ER_dim_out_of_range;

    //number of images
    int img_count = pVD_Save->pDim()->size_Dim(DimList);

    //Create SaveDir
    QDir DIR_Save = QDir(QS_Dir);
    if(!DIR_Save.exists())
        QDir().mkdir(DIR_Save.path());

    //loop images
    for(int img = 0; img < img_count; img++)
    {
        QString QS_SaveSingle = DIR_Save.path() + "/" + QS_ImgName + "_" + QSL_DimIndices[DimList] + QString::number(img) + "." + QS_Suffix;

        D_VisDat_Slice_2D slice;
        slice.set_Pos_Dim(DimImgX, -1);
        slice.set_Pos_Dim(DimImgY, -1);
        slice.set_Pos_Dim(DimList, img);

        Save_VD_Single(
                    pVD_Save,
                    QS_SaveSingle,
                    slice);
    }

    return ER_okay;
}

int D_VisDat_Proc::Save_VD_ListFull(D_VisDat_Obj *pVD_Save, QString QS_Dir, QString QS_ImgName, QString QS_Suffix, int plane2D, bool transVis, int mode_crop, int mode_trafo, int mode_anchor, int mode_range, double val_anchor, double val_range, double val_min, double val_max, double val_gamma, double val_center, double val_scale, bool keep_min_max)
{
    //checks
    if(plane2D >= c_PLANE_NUMBER_OF || plane2D < 0) return ER_dim_out_of_range;
    if(pVD_Save->pMA_full()->empty())               return ER_empty;

    //Create SaveDir
    QDir DIR_Save = QDir(QS_Dir);
    if(!DIR_Save.exists())
        QDir().mkdir(DIR_Save.path());

    //slicing
    D_VisDat_Slicing slicing(2, plane2D);
    slicing.loop_Init(pVD_Save->Dim());

    //transform?
    if(transVis)
    {
        //transform
        D_VisDat_Obj VD_trans;
        int ER = Visualize_to8bit(
                    slicing,
                    &VD_trans,
                    pVD_Save,
                    mode_crop,
                    mode_trafo,
                    mode_anchor,
                    mode_range,
                    val_anchor,
                    val_range,
                    val_min,
                    val_max,
                    val_gamma,
                    val_center,
                    val_scale,
                    keep_min_max);
        if(ER != ER_okay)
            return ER;

        //loop
        do
        {
            D_VisDat_Slice_2D slice = slicing.loop2D_SliceCurrent();

            int ER = Save_VD_Single(
                        &VD_trans,
                        DIR_Save.path() + "/" + QS_ImgName + "_" + slice.QS_pos_nonProcOnly() + "." + QS_Suffix,
                        slice);
            if(ER != ER_okay)
                return ER;
        }
        while (slicing.loop_Next());
    }
    else
    {
        //loop
        do
        {
            D_VisDat_Slice_2D slice = slicing.loop2D_SliceCurrent();

            int ER = Save_VD_Single(
                        pVD_Save,
                        DIR_Save.path() + "/" + QS_ImgName + "_" + slice.QS_pos_nonProcOnly() + "." + QS_Suffix,
                        slice);
            if(ER != ER_okay)
                return ER;
        }
        while (slicing.loop_Next());
    }

    return ER_okay;
}

int D_VisDat_Proc::Create_VD_Single_Constant(D_VisDat_Obj *pVD_New, D_VisDat_Dim dim_new, int type, double value)
{
    *pVD_New = D_VisDat_Obj(
                dim_new,
                type,
                value);

    return ER_okay;
}

int D_VisDat_Proc::Create_VD_Single(D_VisDat_Obj *pVD_New, QString QS_Path, int DimImgX, int DimImgY)
{
    return Create_VD_Single(
                pVD_New,
                QFileInfo(QS_Path),
                DimImgX,
                DimImgY);
}

int D_VisDat_Proc::Create_VD_Single(D_VisDat_Obj *pVD_New, QFileInfo FI_Path, int DimImgX, int DimImgY)
{
    //checks
    if(DimImgX >= c_DIM_NUMBER_OF || DimImgX < 0)   return ER_dim_out_of_range;
    if(DimImgY >= c_DIM_NUMBER_OF || DimImgY < 0)   return ER_dim_out_of_range;
    if(!FI_Path.exists())                           return ER_file_not_exist;

    //buffer
    Mat MA_tmp_in;
    int ER = D_Img_Proc::Load_From_Path(
                &MA_tmp_in,
                FI_Path.absoluteFilePath());
    if(ER != ER_okay)
    {
        MA_tmp_in.release();
        return ER;
    }

    //Dimesnions (all dims are 1 by default)
    D_VisDat_Dim DimNew;
    DimNew.set_size_Dim(DimImgX, MA_tmp_in.cols);
    DimNew.set_size_Dim(DimImgY, MA_tmp_in.rows);

    //VD
    *pVD_New = D_VisDat_Obj(DimNew, MA_tmp_in.type());

    //target slice (pos 0_n by default)
    D_VisDat_Slice_2D TargetPlane;
    TargetPlane.set_Pos_Dim(DimImgX, -1);
    TargetPlane.set_Pos_Dim(DimImgY, -1);

    //push Mat->VD
    ER = D_VisDat_Proc::Write_2D_Plane(
                pVD_New,
                &MA_tmp_in,
                TargetPlane);
    if(ER != ER_okay)
    {
        MA_tmp_in.release();
        return ER;
    }

    //finish
    MA_tmp_in.release();
    return ER_okay;
}

int D_VisDat_Proc::Create_VD_Single_Raw(D_VisDat_Obj *pVD_New, string path, int width, int height, int out_type)
{
    *pVD_New = D_VisDat_Obj(
                D_VisDat_Dim(width, height, 1, 1, 1, 1),
                out_type);

    return Wrap_VD(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Load_From_Path_Raw(
                    path,
                    width,
                    height,
                    out_type),
                pVD_New);
}

int D_VisDat_Proc::Create_VD_SinglePaged(D_VisDat_Obj *pVD_New, QString QS_Path, int DimPage, int DimImgX, int DimImgY)
{
    return Create_VD_SinglePaged(
                pVD_New,
                QFileInfo(QS_Path),
                DimPage,
                DimImgX,
                DimImgY);
}

int D_VisDat_Proc::Create_VD_SinglePaged(D_VisDat_Obj *pVD_New, QFileInfo FI_Path, int DimPage, int DimImgX, int DimImgY)
{
    //checks
    if(DimPage >= c_DIM_NUMBER_OF || DimPage < 0)   return ER_dim_out_of_range;
    if(DimImgX >= c_DIM_NUMBER_OF || DimImgX < 0)   return ER_dim_out_of_range;
    if(DimImgY >= c_DIM_NUMBER_OF || DimImgY < 0)   return ER_dim_out_of_range;

    //Load img in mat
    vector<Mat> vMA_tmp_Load;
    bool bER = imreadmulti(
                FI_Path.absoluteFilePath().toStdString(),
                vMA_tmp_Load,
                cv::IMREAD_ANYCOLOR | cv::IMREAD_ANYDEPTH);
    if(!bER)
    {
        vMA_tmp_Load.clear();
        return ER_other;
    }

    //Dimensions (all dims are 1 by default)
    D_VisDat_Dim DimNew;
    DimNew.set_size_Dim(DimImgX, vMA_tmp_Load[0].cols);
    DimNew.set_size_Dim(DimImgY, vMA_tmp_Load[0].rows);
    DimNew.set_size_Dim(DimPage, static_cast<int>(vMA_tmp_Load.size()));

    //VD
    *pVD_New = D_VisDat_Obj(DimNew, vMA_tmp_Load[0].type());

    //loop pages
    for(size_t p = 0; p < vMA_tmp_Load.size(); p++)
    {
        //target slice (pos 0_n by default)
        D_VisDat_Slice_2D TargetPlane;
        TargetPlane.set_Pos_Dim(DimImgX, -1);
        TargetPlane.set_Pos_Dim(DimImgY, -1);
        TargetPlane.set_Pos_Dim(DimPage, static_cast<int>(p));

        //push Mat->VD
        int ER = D_VisDat_Proc::Write_2D_Plane(
                    pVD_New,
                    &(vMA_tmp_Load[p]),
                    TargetPlane);
        if(ER != ER_okay)
        {
            vMA_tmp_Load.clear();
            return ER;
        }
    }

    //finish
    vMA_tmp_Load.clear();
    return ER_okay;
}

int D_VisDat_Proc::Create_VD_List(D_VisDat_Obj *pVD_New, QStringList QSL_InPaths, int DimList, int DimImgX, int DimImgY)
{
    QFileInfoList FIL_InPaths;
    for(int f = 0; f < QSL_InPaths.size(); f++)
        FIL_InPaths.append(QFileInfo(QSL_InPaths[f]));

    return Create_VD_List(
                pVD_New,
                FIL_InPaths,
                DimList,
                DimImgX,
                DimImgY);
}

int D_VisDat_Proc::Create_VD_List(D_VisDat_Obj *pVD_New, QFileInfoList FIL_InPaths, int DimList, int DimImgX, int DimImgY)
{
    //checks
    if(DimList >= c_DIM_NUMBER_OF || DimList < 0)   return ER_dim_out_of_range;
    if(DimImgX >= c_DIM_NUMBER_OF || DimImgX < 0)   return ER_dim_out_of_range;
    if(DimImgY >= c_DIM_NUMBER_OF || DimImgY < 0)   return ER_dim_out_of_range;
    if(FIL_InPaths.empty())                         return ER_list_empty;

    //Dimension Definition by first image
    //qDebug() << "Create_VD_List" << "load first as dim def";
    Mat MA_tmp_DimDef;
    int ER = D_Img_Proc::Load_From_Path(
                &MA_tmp_DimDef,
                FIL_InPaths.first().absoluteFilePath());
    if(ER != ER_okay)
    {
        //qDebug() << "Create_VD_List" << "dim def img error";
        MA_tmp_DimDef.release();
        return ER;
    }

    //Dimensions (all dims are 1 by default)
    D_VisDat_Dim DimNew;
    DimNew.set_size_Dim(DimImgX, MA_tmp_DimDef.cols);
    DimNew.set_size_Dim(DimImgY, MA_tmp_DimDef.rows);
    DimNew.set_size_Dim(DimList, FIL_InPaths.size());

    //VD
    *pVD_New = D_VisDat_Obj(DimNew, MA_tmp_DimDef.type());

    //input buffer
    Mat MA_tmp_InBuffer;

    //loop list
    for(int f = 0; f < FIL_InPaths.size(); f++)
    {
        //qDebug() << "Create_VD_List" << "load img:" << FIL_InPaths[f].absoluteFilePath();

        //load to Mat buffer
        int ER = D_Img_Proc::Load_From_Path(
                    &MA_tmp_InBuffer,
                    FIL_InPaths[f].absoluteFilePath());
        if(ER != ER_okay)
        {
            MA_tmp_InBuffer.release();
            MA_tmp_DimDef.release();
            return ER;
        }

        //target slice (pos 0_n by default)
        D_VisDat_Slice_2D TargetPlane;
        TargetPlane.set_Pos_Dim(DimImgX, -1);
        TargetPlane.set_Pos_Dim(DimImgY, -1);
        TargetPlane.set_Pos_Dim(DimList, f);

        //push Mat->VD
        ER = D_VisDat_Proc::Write_2D_Plane(
                    pVD_New,
                    &MA_tmp_InBuffer,
                    TargetPlane);
        if(ER != ER_okay)
        {
            MA_tmp_InBuffer.release();
            MA_tmp_DimDef.release();
            return ER;
        }
    }

    //finish
    MA_tmp_InBuffer.release();
    MA_tmp_DimDef.release();
    return ER_okay;
}

int D_VisDat_Proc::Create_VD_ListPaged(D_VisDat_Obj *pVD_New, QStringList QSL_InPaths, int DimList, int DimPage, int DimImgX, int DimImgY)
{
    QFileInfoList FIL_InPaths;
    for(int f = 0; f < QSL_InPaths.size(); f++)
        FIL_InPaths.append(QFileInfo(QSL_InPaths[f]));

    return Create_VD_ListPaged(
                pVD_New,
                FIL_InPaths,
                DimPage,
                DimList,
                DimImgX,
                DimImgY);
}

int D_VisDat_Proc::Create_VD_ListPaged(D_VisDat_Obj *pVD_New, QFileInfoList FIL_InPaths, int DimList, int DimPage, int DimImgX, int DimImgY)
{
    //checks
    if(DimPage >= c_DIM_NUMBER_OF || DimPage < 0)   return ER_dim_out_of_range;
    if(DimList >= c_DIM_NUMBER_OF || DimList < 0)   return ER_dim_out_of_range;
    if(DimImgX >= c_DIM_NUMBER_OF || DimImgX < 0)   return ER_dim_out_of_range;
    if(DimImgY >= c_DIM_NUMBER_OF || DimImgY < 0)   return ER_dim_out_of_range;
    if(FIL_InPaths.empty())                             return ER_list_empty;

    //Dimension Definition by first image
    vector<Mat> vMA_tmp_DimDef;
    bool bER = imreadmulti(
                FIL_InPaths.first().absoluteFilePath().toStdString(),
                vMA_tmp_DimDef,
                cv::IMREAD_ANYCOLOR | cv::IMREAD_ANYDEPTH);
    if(!bER)
    {
        //qDebug() << "Create_VD_List" << "dim def img error";
        vMA_tmp_DimDef.clear();
        return ER_other;
    }

    //Dimensions (all dims are 1 by default)
    D_VisDat_Dim DimNew;
    DimNew.set_size_Dim(DimImgX, vMA_tmp_DimDef[0].cols);
    DimNew.set_size_Dim(DimImgY, vMA_tmp_DimDef[0].rows);
    DimNew.set_size_Dim(DimList, FIL_InPaths.size());
    DimNew.set_size_Dim(DimPage, static_cast<int>(vMA_tmp_DimDef.size()));
    //qDebug() << DimNew.info();

    //VD
    *pVD_New = D_VisDat_Obj(DimNew, vMA_tmp_DimDef[0].type());

    //loop list
    for(int f = 0; f < FIL_InPaths.size(); f++)
        for(int p = 0; p < vMA_tmp_DimDef.size(); p++)
        {
            //qDebug() << "Create_VD_List" << "load img:" << FIL_InPaths[f].absoluteFilePath();

            //load to Mat buffer
            vector<Mat> vMA_tmp_InBuffer;
            bER = imreadmulti(
                        FIL_InPaths[f].absoluteFilePath().toStdString(),
                        vMA_tmp_InBuffer,
                        cv::IMREAD_ANYCOLOR | cv::IMREAD_ANYDEPTH);
            if(bER == false)
            {
                //qDebug() << "Create_VD_List" << "dim def img error";
                vMA_tmp_DimDef.clear();
                return ER_other;
            }

            //target slice (pos 0_n by default)
            D_VisDat_Slice_2D TargetPlane;
            TargetPlane.set_Pos_Dim(DimImgX, -1);
            TargetPlane.set_Pos_Dim(DimImgY, -1);
            TargetPlane.set_Pos_Dim(DimList, f);
            TargetPlane.set_Pos_Dim(DimPage, p);
            //qDebug() << TargetPlane.info();

            //push Mat->VD
            int ER = D_VisDat_Proc::Write_2D_Plane(
                        pVD_New,
                        &(vMA_tmp_InBuffer[p]),
                        TargetPlane);
            if(ER != ER_okay)
            {
                vMA_tmp_DimDef.clear();
                vMA_tmp_InBuffer.clear();
                return ER;
            }
        }

    //finish
    vMA_tmp_DimDef.clear();
    return ER_okay;
}

int D_VisDat_Proc::Create_VD_Video(D_VisDat_Obj *pVD_New, QString QS_VideoPath, int DimTime, int DimImgX, int DimImgY, bool force8UC1)
{
    return Create_VD_Video(
                pVD_New,
                QFileInfo(QS_VideoPath),
                DimTime,
                DimImgX,
                DimImgY,
                force8UC1);
}


int D_VisDat_Proc::Create_VD_Video(D_VisDat_Obj *pVD_New, QFileInfo FI_VideoPath, int DimTime, int DimImgX, int DimImgY, bool force8UC1)
{
    //checks
    if(DimTime >= c_DIM_NUMBER_OF || DimTime < 0)   return ER_dim_out_of_range;
    if(DimImgX >= c_DIM_NUMBER_OF || DimImgX < 0)   return ER_dim_out_of_range;
    if(DimImgY >= c_DIM_NUMBER_OF || DimImgY < 0)   return ER_dim_out_of_range;
    if(!FI_VideoPath.exists())                      return ER_file_not_exist;
    int ER;

    //Load video
    VideoCapture VC_tmp = VideoCapture(FI_VideoPath.absoluteFilePath().toStdString());
    if(!VC_tmp.isOpened())
    {
        VC_tmp.release();
        qDebug() << "Failed to load Video:" << FI_VideoPath.absoluteFilePath();
        return ER_VideoCaptureClosed;
    }

    //Dimension & type
    int n_x = VC_tmp.get(CAP_PROP_FRAME_WIDTH);
    int n_y = VC_tmp.get(CAP_PROP_FRAME_HEIGHT);
    int n_t = VC_tmp.get(CAP_PROP_FRAME_COUNT);

    //Dimensions (all dims are 1 by default)
    D_VisDat_Dim DimNew;
    DimNew.set_size_Dim(DimImgX, n_x);
    DimNew.set_size_Dim(DimImgY, n_y);
    DimNew.set_size_Dim(DimTime, n_t);
    if(n_x <= 0 || n_y <= 0 || n_t <= 0)
    {
        qDebug() << "Videodimensions Error - x:" << n_x << "y:" << n_y << "t:" << n_t;
        VC_tmp.release();
        return ER_empty;
    }

    //Read Mat
    Mat MA_read;
    VC_tmp >> MA_read;    //read 1st frame
    if(MA_read.empty())
    {
        MA_read.release();
        VC_tmp.release();
        qDebug() << "1st frame empty";
        return ER_empty;
    }

    //Buffer Mat
    Mat MA_buffer;
    if(force8UC1 && MA_read.type() != CV_8UC1)
    {
        ER = D_Img_Proc::Convert_8UC1(
                    &MA_buffer,
                    &MA_read);
        if(ER != ER_okay)
        {
            qDebug() << "Could not convert 1st frame to CV_8UC1";
            MA_read.release();
            MA_buffer.release();
            VC_tmp.release();
            return ER;
        }
    }
    else
        MA_buffer = MA_read;

    //VD
    *pVD_New = D_VisDat_Obj(DimNew, MA_buffer.type());

    //Target plane & store 1st mat
    D_VisDat_Slice_2D TargetPlane;
    TargetPlane.set_Pos_Dim(DimImgX, -1);
    TargetPlane.set_Pos_Dim(DimImgY, -1);
    TargetPlane.set_Pos_Dim(DimTime, 0);

    ER = D_VisDat_Proc::Write_2D_Plane(
                pVD_New,
                &MA_buffer,
                TargetPlane);
    if(ER != ER_okay)
    {
        qDebug() << "failed to export 1st frame to VD";
        MA_buffer.release();
        VC_tmp.release();
        return ER;
    }

    //loop time (first read allready)
    for(int t = 1; t < n_t; t++)
    {
        TargetPlane.set_Pos_Dim(DimTime, t);

        //read frame
        VC_tmp >> MA_read;

        //forece CV_8UC1?
        if(force8UC1 && MA_read.type() != CV_8UC1)
        {
            ER = D_Img_Proc::Convert_8UC1(
                        &MA_buffer,
                        &MA_read);
            if(ER != ER_okay)
            {
                qDebug() << "failed to convert frame" << t << "to CV_8UC1";
                MA_read.release();
                MA_buffer.release();
                VC_tmp.release();
                return ER;
            }
        }
        else
            MA_buffer = MA_read;

        //write frame to VD
        ER = D_VisDat_Proc::Write_2D_Plane(
                    pVD_New,
                    &MA_buffer,
                    TargetPlane);
        if(ER != ER_okay)
        {
            qDebug() << "failed to export frame" << t << "to VD";
            MA_buffer.release();
            VC_tmp.release();
            return ER;
        }
    }

    MA_buffer.release();
    VC_tmp.release();
    return ER_okay;
}

int D_VisDat_Proc::Create_VD_Video_Proc(D_VisDat_Obj *pVD_New, QFileInfo FI_VideoPath, int blur_size, double blur_sigma, int t1_size, function<double (vector<double>)> f_stat_t1, int t2_size, function<double (vector<double>)> f_stat_t2, int t_offset, function<double (double, double)> f_combi, bool force8bit)
{
    //checks
    if(!FI_VideoPath.exists())                      return ER_file_not_exist;
    if(blur_size < 1)                               return ER_parameter_bad;
    if(blur_sigma < 0)                              return ER_parameter_bad;
    if(t1_size < 1)                                 return ER_parameter_bad;
    if(t2_size < 1)                                 return ER_parameter_bad;
    if(t_offset < 0)                                return ER_parameter_bad;
    int ER;

    //Load video
    VideoCapture VC_tmp = VideoCapture(FI_VideoPath.absoluteFilePath().toStdString());
    if(!VC_tmp.isOpened())
    {
        qDebug() << "unable to open video capture:" << FI_VideoPath.absoluteFilePath();
        VC_tmp.release();
        return ER_VideoCaptureClosed;
    }

    //Dimension of input
    int n_x = VC_tmp.get(CAP_PROP_FRAME_WIDTH);
    int n_y = VC_tmp.get(CAP_PROP_FRAME_HEIGHT);
    int n_t_in = VC_tmp.get(CAP_PROP_FRAME_COUNT);

    //time frames sizes
    int t1_shift = t1_size / 2;
    int t2_shift = t2_size / 2;
    int t_span   = max(max(t1_size, t2_size), t1_shift + t2_shift + t_offset);

    //calc number of out frames
    int n_t_out = n_t_in - t_span + 1;
    qDebug() << "n_x/n_y           " << n_x << n_y;
    qDebug() << "t1_size/t2_size   " << t1_size << t2_size;
    qDebug() << "t1_shift/t2_shift " << t1_shift << t2_shift;
    qDebug() << "t_span            " << t_span;
    qDebug() << "n_t_in/n_t_out    " << n_t_in << n_t_out;

    //Dimensions out (all dims are 1 by default)
    D_VisDat_Dim DimNew;
    DimNew.set_size_Dim(c_DIM_X, n_x);
    DimNew.set_size_Dim(c_DIM_Y, n_y);
    DimNew.set_size_Dim(c_DIM_T, n_t_out);
    if(n_x <= 0 || n_y <= 0 || n_t_out <= 0)
    {
        VC_tmp.release();
        return ER_empty;
    }

    //create output VD
    int tp_out = CV_64FC1;
    if(force8bit)
        tp_out = CV_8UC1;
    *pVD_New = D_VisDat_Obj(DimNew, tp_out);

    //time frames
    vector<Mat> vMA_TSpan(  t_span,     Mat::zeros(n_y, n_x, CV_8UC1));
    vector<Mat> vMA_T1(     t1_size,    Mat::zeros(n_y, n_x, CV_8UC1));
    vector<Mat> vMA_T2(     t2_size,    Mat::zeros(n_y, n_x, CV_8UC1));
    int i_t1_inSpan = 0;
    int i_t2_inSpan = 0;
    int i_t1        = 0;
    int i_t2        = 0;

    //Buffer output frame
    Mat MA_tmp_Buffer_read;
    Mat MA_tmp_Buffer_gray;
    Mat MA_tmp_Buffer_blur;
    Mat MA_tmp_Buffer_proc;

    //Target plane & store 1st mat
    D_VisDat_Slice_2D TargetPlane;
    TargetPlane.set_Pos_Dim(c_DIM_X, -1);
    TargetPlane.set_Pos_Dim(c_DIM_Y, -1);
    TargetPlane.set_Pos_Dim(c_DIM_T, 0);

    //loop frames
    for(int f_in = 0, f_out = 1 - t_span; f_in < n_t_in; f_in++, f_out++)
    {
        //looping and reseting indices for acess in Mat vectors to avoid more loading than needed
        i_t1_inSpan     = (f_in + t1_shift           ) % t_span;
        i_t2_inSpan     = (f_in + t2_shift + t_offset) % t_span;
        i_t1            =  f_in                        % t1_size;
        i_t2            =  f_in                        % t2_size;

        //Output
        qDebug() << "Create_VD_Video_Proc"
                 << "---" << "FrameIn:"  << f_in  << "/" << n_t_in
                 << "---" << "FrameOut:" << f_out << "/" << n_t_out
                 << "---" << "T1:" << i_t1_inSpan << "->" << i_t1
                 << "---" << "T2:" << i_t2_inSpan << "->" << i_t2;

        //read frame f
        VC_tmp >> MA_tmp_Buffer_read;

        //to gray
        ER = D_Img_Proc::Convert_8UC1(
                    &MA_tmp_Buffer_gray,
                    &MA_tmp_Buffer_read);
        if(ER != ER_okay)
        {
            vMA_TSpan.clear();
            vMA_T1.clear();
            vMA_T2.clear();
            MA_tmp_Buffer_read.release();
            MA_tmp_Buffer_gray.release();
            MA_tmp_Buffer_blur.release();
            MA_tmp_Buffer_proc.release();
            VC_tmp.release();
            return ER;
        }

        //blur
        if(blur_size >= 3 && blur_sigma > 0)
        {
            ER = D_Img_Proc::Filter_Gauss(
                        &MA_tmp_Buffer_blur,
                        &MA_tmp_Buffer_gray,
                        blur_size / 2,
                        blur_size / 2,
                        BORDER_DEFAULT,
                        blur_sigma,
                        blur_sigma);
            if(ER != ER_okay)
            {
                vMA_TSpan.clear();
                vMA_T1.clear();
                vMA_T2.clear();
                MA_tmp_Buffer_read.release();
                MA_tmp_Buffer_gray.release();
                MA_tmp_Buffer_blur.release();
                MA_tmp_Buffer_proc.release();
                VC_tmp.release();
                return ER;
            }
            vMA_TSpan[i_t1_inSpan] = MA_tmp_Buffer_blur.clone();
        }
        else
        {
            vMA_TSpan[i_t1_inSpan] = MA_tmp_Buffer_gray.clone();
        }

        //initialize time frame vectors before first iteration of processing (vMA_TSpan is filled properly but due tu looping indices vMA_T1 & vMA_T2 are not yet)
        if(f_out == 0)
            for(int f_fill = 0; f_fill < t_span; f_fill++)
            {
                int i_fill_t1_inSpan     = (f_fill + t1_shift           ) % t_span;
                int i_fill_t2_inSpan     = (f_fill + t2_shift + t_offset) % t_span;
                int i_fill_t1            =  f_fill                        % t1_size;
                int i_fill_t2            =  f_fill                        % t2_size;

                vMA_T1[i_fill_t1] = vMA_TSpan[i_fill_t1_inSpan];
                vMA_T2[i_fill_t2] = vMA_TSpan[i_fill_t2_inSpan];
            }

        //proc frame, if vectors are full
        if(f_out >= 0)
        {
            //export read frame to Time frames (no copy is done, the Mats point to the same memory)
            vMA_T1[i_t1] = vMA_TSpan[i_t1_inSpan];
            vMA_T2[i_t2] = vMA_TSpan[i_t2_inSpan];

            //proc frame
            ER = D_Img_Proc::Math_ImgStack_StatCombine(
                        &MA_tmp_Buffer_proc,
                        &vMA_T1,
                        &vMA_T2,
                        f_stat_t1,
                        f_stat_t2,
                        f_combi,
                        force8bit);
            if(ER != ER_okay)
            {
                vMA_TSpan.clear();
                vMA_T1.clear();
                vMA_T2.clear();
                MA_tmp_Buffer_read.release();
                MA_tmp_Buffer_gray.release();
                MA_tmp_Buffer_blur.release();
                MA_tmp_Buffer_proc.release();
                VC_tmp.release();
                return ER;
            }

            //Write Mat to target 2d slice
            TargetPlane.set_Pos_T(f_out);
            ER = D_VisDat_Proc::Write_2D_Plane(
                        pVD_New,
                        &MA_tmp_Buffer_proc,
                        TargetPlane);
            if(ER != ER_okay)
            {
                vMA_TSpan.clear();
                vMA_T1.clear();
                vMA_T2.clear();
                MA_tmp_Buffer_read.release();
                MA_tmp_Buffer_gray.release();
                MA_tmp_Buffer_blur.release();
                MA_tmp_Buffer_proc.release();
                VC_tmp.release();
                return ER;
            }
        }
    }

    vMA_TSpan.clear();
    vMA_T1.clear();
    vMA_T2.clear();
    MA_tmp_Buffer_read.release();
    MA_tmp_Buffer_gray.release();
    MA_tmp_Buffer_blur.release();
    MA_tmp_Buffer_proc.release();
    VC_tmp.release();
    return ER_okay;
}

int D_VisDat_Proc::Create_VD_PageVector(D_VisDat_Obj *pVD_New, QFileInfo FI_Path, D_VisDat_Dim DimNew, vector<int> vI_Pages2Load, vector<D_VisDat_Slice_2D> v2D_PageSource_DimsPosTarget, int DimImgX, int DimImgY)
{
    //checks
    if(vI_Pages2Load.size() != v2D_PageSource_DimsPosTarget.size())     return ER_size_missmatch;

    //Load img in mat
    vector<Mat> vMA_tmp_Load;
    bool bER = imreadmulti(
                FI_Path.absoluteFilePath().toStdString(),
                vMA_tmp_Load,
                cv::IMREAD_ANYCOLOR | cv::IMREAD_ANYDEPTH);
    if(!bER || vMA_tmp_Load.empty())
    {
        vMA_tmp_Load.clear();
        return ER_other;
    }

    //check if dim fits
    if(DimNew.size_Dim(DimImgX) != vMA_tmp_Load[0].cols)
    {
        qDebug() << "Create_VD_PageVector X missmatch: Dim" << DimNew.size_Dim(DimImgX) << "Img" << vMA_tmp_Load[0].cols;
        qDebug() << DimNew.info();
        vMA_tmp_Load.clear();
        return ER_dim_X_missmatch;
    }
    if(DimNew.size_Dim(DimImgY) != vMA_tmp_Load[0].rows)
    {
        qDebug() << "Create_VD_PageVector Y missmatch: Dim" << DimNew.size_Dim(DimImgY) << "Img" << vMA_tmp_Load[0].rows;
        qDebug() << DimNew.info();
        vMA_tmp_Load.clear();
        return ER_dim_Y_missmatch;
    }

    //VD
    *pVD_New = D_VisDat_Obj(DimNew, vMA_tmp_Load[0].type());

    //loop needed pages
    for(size_t ip = 0; ip < vI_Pages2Load.size(); ip++)
    {
        //push Mat->VD
        int ER = D_VisDat_Proc::Write_2D_Plane(
                    pVD_New,
                    &(vMA_tmp_Load[vI_Pages2Load[ip]]),
                    v2D_PageSource_DimsPosTarget[ip]);
        if(ER != ER_okay)
        {
            vMA_tmp_Load.clear();
            qDebug() << "Create_VD_PageVector Error at Slice:" << v2D_PageSource_DimsPosTarget[ip].info();
            return ER;
        }
    }

    //finish
    vMA_tmp_Load.clear();
    return ER_okay;
}

int D_VisDat_Proc::Create_VD_PageVector_or0(D_VisDat_Obj *pVD_New, QFileInfo FI_Path, D_VisDat_Dim DimNew, vector<int> vI_Pages2Load, vector<D_VisDat_Slice_2D> v2D_PageSource_DimsPosTarget, int DimImgX, int DimImgY, bool full_0_instead, int type_if_full_0)
{
    if(full_0_instead)
        return Create_VD_Single_Constant(
                    pVD_New,
                    DimNew,
                    type_if_full_0);
    else
        return Create_VD_PageVector(
                    pVD_New,
                    FI_Path,
                    DimNew,
                    vI_Pages2Load,
                    v2D_PageSource_DimsPosTarget,
                    DimImgX,
                    DimImgY);
}


int D_VisDat_Proc::Create_VD_ValueFunction(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_New, D_VisDat_Dim dim_new, function<double (double, double)> value_function)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_New = D_VisDat_Obj(
                dim_new,
                CV_64FC1);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Generate_byValueFunction(
                    dim_new.size_Dim(slice.ProcDim(0)),
                    dim_new.size_Dim(slice.ProcDim(1)),
                    value_function),
                pVD_New);
}

int D_VisDat_Proc::Create_VD_ValueFunction_Complex(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_New, D_VisDat_Dim dim_new, function<complex<double> (complex<double> x, complex<double> y)> value_function)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_New = D_VisDat_Obj(
                dim_new,
                CV_64FC2);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Generate_byValueFunction_Complex(
                    dim_new.size_Dim(slice.ProcDim(0)),
                    dim_new.size_Dim(slice.ProcDim(1)),
                    value_function),
                pVD_New);
}

int D_VisDat_Proc::Create_VD_ValueFunction_6D(D_VisDat_Obj *pVD_New, D_VisDat_Dim dim_new, function<double (double, double, double, double, double, double)> value_function)
{
    //init
    *pVD_New = D_VisDat_Obj(
                dim_new,
                CV_64FC1);

    //size
    int x_max = dim_new.size_X();
    int y_max = dim_new.size_Y();
    int z_max = dim_new.size_Z();
    int t_max = dim_new.size_T();
    int s_max = dim_new.size_S();
    int p_max = dim_new.size_P();

    //loop & fill
    Vec<int, c_DIM_NUMBER_OF> pos;
    for(int x = 0; x < x_max; x++)
        for(int y = 0; y < y_max; y++)
            for(int z = 0; z < z_max; z++)
                for(int t = 0; t < t_max; t++)
                    for(int s = 0; s < s_max; s++)
                        for(int p = 0; p < p_max; p++)
                        {
                            pos = {x, y, z, t, s, p};
                            pVD_New->pMA_full()->at<double>(pos) = value_function(x, y, z, t, s, p);
                        }

    return ER_okay;
}

int D_VisDat_Proc::Create_VD_Random(D_VisDat_Obj *pVD_New, D_VisDat_Dim dim_new, int type, double min, double max, double a, double b, double c, double d, double e, double f)
{
    //init
    *pVD_New = D_VisDat_Obj(
                dim_new,
                CV_64FC1);

    //reset type
    dim_new.loop_Reset();

    //seed random generator
    mt19937 seed(time(NULL));

    //select type and loop
    switch (type) {

    case c_RAND_NORMAL:
    {
        normal_distribution<double> gen(a, b);
        do
        {
            double val = gen(seed);
            if(val < min)
                pVD_New->pMA_full()->at<double>(dim_new.loop_PosCurrent()) = min;
            else if(val > max)
                pVD_New->pMA_full()->at<double>(dim_new.loop_PosCurrent()) = max;
            else
                pVD_New->pMA_full()->at<double>(dim_new.loop_PosCurrent()) = val;
        }
        while(dim_new.loop_Next());
    }
        break;

    default:
        return ER_parameter_bad;
    }

    return ER_okay;
}

int D_VisDat_Proc::Create_VD_FromBinaryFile(D_VisDat_Obj *pVD_New, QString QS_Path)
{
    //FileInfo
    QFileInfo FI_Path(QS_Path);

    //Errors
    if(!FI_Path.exists())
        return ER_file_not_exist;
    if(FI_Path.suffix() != "visdat")
        return ER_other;

    //open file
    ifstream file(FI_Path.absoluteFilePath().toStdString(), ios::binary | ios::in);
    if(!file.is_open())
        return ER_other;

    //Read Header
    D_VisDat_Header header;
    file.read(reinterpret_cast<char*>(&header), sizeof(D_VisDat_Header));

    //Create new VD
    *pVD_New = D_VisDat_Obj(header);

    //Read Mat data
    file.read(reinterpret_cast<char*>(pVD_New->pMA_full()->data), pVD_New->size_Byte());

    //finish
    file.close();
    return ER_okay;
}

int D_VisDat_Proc::Write_2D_Plane(D_VisDat_Obj *pVD_Out, Mat *pMA_In, D_VisDat_Slice_2D OutPlane)
{
    //qDebug() << "test Write_2D_Plane - start";

    //dims/sizes
    //qDebug() << "test Write_2D_Plane - dims";
    int ext1 = OutPlane.extended_Dim(0);
    int ext2 = OutPlane.extended_Dim(1);
    int sz1 = pMA_In->cols;
    int sz2 = pMA_In->rows;

    //check content, in range, size, type
    //qDebug() << "test Write_2D_Plane - checks";
    int ER = OutPlane.ER_OutOfrange(pVD_Out->Dim());
    if(ER != ER_okay)                                                                     return ER;
    if(pVD_Out->pDim()->size_Dim(ext1) != sz1 || pVD_Out->pDim()->size_Dim(ext2) != sz2)  return ER_size_missmatch;
    if(pMA_In->empty())                                                                   return ER_empty;
    if(pMA_In->type() != pVD_Out->type())
    {
        //qDebug() << "IN:" << D_Img_Proc::Type_of_Mat(pMA_In) << "OUT:" << D_Img_Proc::Type_of_Mat(pVD_Out->pMA_full());
        return ER_type_missmatch;
    }

    //position
    //qDebug() << "test Write_2D_Plane - pos";
    Vec<int, c_DIM_NUMBER_OF> v_pos = OutPlane.pos_Dims();

    //loop extended dims (SLOW!!! - to be replaced later)
    //qDebug() << "test Write_2D_Plane - switch";
    switch (pMA_In->type()) {

    case CV_8UC1:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<uchar>(v_pos) = pMA_In->at<uchar>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_8SC1:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<char>(v_pos) = pMA_In->at<char>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_16UC1:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<ushort>(v_pos) = pMA_In->at<ushort>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_16SC1:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<short>(v_pos) = pMA_In->at<short>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_32SC1:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<int>(v_pos) = pMA_In->at<int>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_32FC1:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<float>(v_pos) = pMA_In->at<float>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_64FC1:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<double>(v_pos) = pMA_In->at<double>(v_pos[ext2], v_pos[ext1]);
        break;

        //2 Channels

    case CV_8UC2:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec2b>(v_pos) = pMA_In->at<Vec2b>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_16UC2:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec2w>(v_pos) = pMA_In->at<Vec2w>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_16SC2:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec2s>(v_pos) = pMA_In->at<Vec2s>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_32SC2:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec2i>(v_pos) = pMA_In->at<Vec2i>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_32FC2:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec2f>(v_pos) = pMA_In->at<Vec2f>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_64FC2:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec2d>(v_pos) = pMA_In->at<Vec2d>(v_pos[ext2], v_pos[ext1]);
        break;

        //3 Channels

    case CV_8UC3:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec3b>(v_pos) = pMA_In->at<Vec3b>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_16UC3:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec3w>(v_pos) = pMA_In->at<Vec3w>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_16SC3:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec3s>(v_pos) = pMA_In->at<Vec3s>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_32SC3:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec3i>(v_pos) = pMA_In->at<Vec3i>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_32FC3:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec3f>(v_pos) = pMA_In->at<Vec3f>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_64FC3:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec3d>(v_pos) = pMA_In->at<Vec3d>(v_pos[ext2], v_pos[ext1]);
        break;

        //4 Channels

    case CV_8UC4:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec4b>(v_pos) = pMA_In->at<Vec4b>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_16UC4:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec4w>(v_pos) = pMA_In->at<Vec4w>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_16SC4:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec4s>(v_pos) = pMA_In->at<Vec4s>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_32SC4:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec4i>(v_pos) = pMA_In->at<Vec4i>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_32FC4:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec4f>(v_pos) = pMA_In->at<Vec4f>(v_pos[ext2], v_pos[ext1]);
        break;

    case CV_64FC4:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pVD_Out->pMA_full()->at<Vec4d>(v_pos) = pMA_In->at<Vec4d>(v_pos[ext2], v_pos[ext1]);
        break;

    default:
        return ER_type_bad;
        break;
    }

    //sucess :-)
    //qDebug() << "test Write_2D_Plane - end";
    return ER_okay;
}

int D_VisDat_Proc::Write_2D_Plane(D_VisDat_Obj *pVD_Out, QString path, D_VisDat_Slice_2D OutPlane)
{
    Mat MA_tmp_load;
    int ER = D_Img_Proc::Load_From_Path(&MA_tmp_load, path);
    if(ER != ER_okay)   return ER;

    ER = Write_2D_Plane(
                pVD_Out,
                &MA_tmp_load,
                OutPlane);

    MA_tmp_load.release();
    return ER;
}

int D_VisDat_Proc::Write_3D_Cuboid(D_VisDat_Obj *pVD_Out, Mat *pMA_In, D_VisDat_Slice_3D OutPlane)
{
    if(pMA_In->dims != 3)   return ER_dim_missmatch;

    //qDebug() << "test Write_3D_Cuboid - start";

    //dims/sizes
    int ext1 = OutPlane.extended_Dim(0);
    int ext2 = OutPlane.extended_Dim(1);
    int ext3 = OutPlane.extended_Dim(2);

    int sz1 = pMA_In->size[0];
    int sz2 = pMA_In->size[1];
    int sz3 = pMA_In->size[2];

    //check content, in range, size, type
    int ER = OutPlane.ER_OutOfrange(pVD_Out->Dim());
    if(ER != ER_okay)                                                                                                               return ER;
    if(pVD_Out->pDim()->size_Dim(ext1) != sz1 || pVD_Out->pDim()->size_Dim(ext2) != sz2 || pVD_Out->pDim()->size_Dim(ext3) != sz3)  return ER_size_missmatch;
    if(pMA_In->empty())                                                                                                             return ER_empty;
    if(pMA_In->type() != pVD_Out->type())
    {
        //qDebug() << "IN:" << D_Img_Proc::Type_of_Mat(pMA_In) << "OUT:" << D_Img_Proc::Type_of_Mat(pVD_Out->pMA_full());
        return ER_type_missmatch;
    }

    //position
    Vec<int, c_DIM_NUMBER_OF> v_pos = OutPlane.pos_Dims();
    Vec<int, 3> v_pos3d = {0, 0, 0};

    //loop extended dims (SLOW!!! - to be replaced later)
    switch (pMA_In->type()) {

    case CV_8UC1:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<uchar>(v_pos) = pMA_In->at<uchar>(v_pos3d);
                }
        break;

    case CV_8SC1:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<char>(v_pos) = pMA_In->at<char>(v_pos3d);
                }
        break;

    case CV_16UC1:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<ushort>(v_pos) = pMA_In->at<ushort>(v_pos3d);
                }
        break;

    case CV_16SC1:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<short>(v_pos) = pMA_In->at<short>(v_pos3d);
                }
        break;

    case CV_32SC1:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<int>(v_pos) = pMA_In->at<int>(v_pos3d);
                }
        break;

    case CV_32FC1:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<float>(v_pos) = pMA_In->at<float>(v_pos3d);
                }
        break;

    case CV_64FC1:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<double>(v_pos) = pMA_In->at<double>(v_pos3d);
                }
        break;

        //2 Channels

    case CV_8UC2:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec2b>(v_pos) = pMA_In->at<Vec2b>(v_pos3d);
                }
        break;

    case CV_16UC2:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec2w>(v_pos) = pMA_In->at<Vec2w>(v_pos3d);
                }
        break;

    case CV_16SC2:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec2s>(v_pos) = pMA_In->at<Vec2s>(v_pos3d);
                }
        break;

    case CV_32SC2:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec2i>(v_pos) = pMA_In->at<Vec2i>(v_pos3d);
                }
        break;

    case CV_32FC2:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec2f>(v_pos) = pMA_In->at<Vec2f>(v_pos3d);
                }
        break;

    case CV_64FC2:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec2d>(v_pos) = pMA_In->at<Vec2d>(v_pos3d);
                }
        break;

        //3 Channels

    case CV_8UC3:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec3b>(v_pos) = pMA_In->at<Vec3b>(v_pos3d);
                }
        break;

    case CV_16UC3:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec3w>(v_pos) = pMA_In->at<Vec3w>(v_pos3d);
                }
        break;

    case CV_16SC3:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec3s>(v_pos) = pMA_In->at<Vec3s>(v_pos3d);
                }
        break;

    case CV_32SC3:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec3i>(v_pos) = pMA_In->at<Vec3i>(v_pos3d);
                }
        break;

    case CV_32FC3:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec3f>(v_pos) = pMA_In->at<Vec3f>(v_pos3d);
                }
        break;

    case CV_64FC3:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec3d>(v_pos) = pMA_In->at<Vec3d>(v_pos3d);
                }
        break;

        //4 Channels

    case CV_8UC4:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec4b>(v_pos) = pMA_In->at<Vec4b>(v_pos3d);
                }
        break;

    case CV_16UC4:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec4w>(v_pos) = pMA_In->at<Vec4w>(v_pos3d);
                }
        break;

    case CV_16SC4:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec4s>(v_pos) = pMA_In->at<Vec4s>(v_pos3d);
                }
        break;

    case CV_32SC4:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec4i>(v_pos) = pMA_In->at<Vec4i>(v_pos3d);
                }
        break;

    case CV_32FC4:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec4f>(v_pos) = pMA_In->at<Vec4f>(v_pos3d);
                }
        break;

    case CV_64FC4:
        for(            v_pos[ext3] = 0, v_pos3d[2] = 0;    v_pos[ext3] < sz3;      v_pos[ext3]++, v_pos3d[2]++)
            for(        v_pos[ext2] = 0, v_pos3d[1] = 0;    v_pos[ext2] < sz2;      v_pos[ext2]++, v_pos3d[1]++)
                for(    v_pos[ext1] = 0, v_pos3d[0] = 0;    v_pos[ext1] < sz1;      v_pos[ext1]++, v_pos3d[0]++)
                {
                    pVD_Out->pMA_full()->at<Vec4d>(v_pos) = pMA_In->at<Vec4d>(v_pos3d);
                }
        break;

    default:
        return ER_type_bad;
        break;
    }

    //sucess :-)
    //qDebug() << "test Write_3D_Cuboid - end";
    return ER_okay;
}

int D_VisDat_Proc::Instert_atPos(D_VisDat_Obj *pVD_Target, D_VisDat_Obj *pVD_Source, vector<int> vOffset)
{
    if(pVD_Target->pMA_full()->empty())             return ER_empty;
    if(pVD_Source->pMA_full()->empty())             return ER_empty;
    if(pVD_Target->type() != pVD_Source->type())    return ER_type_missmatch;
    if(vOffset.size() != c_DIM_NUMBER_OF)           return ER_dim_missmatch;
    for(size_t d = 0; d < c_DIM_NUMBER_OF; d++)
        if(vOffset[d] < 0)                          return ER_parameter_bad;

    //sizes
    vector<int> sz_target = pVD_Target->pDim()->size_DimsVec();
    vector<int> sz_source = pVD_Source->pDim()->size_DimsVec();

    //pos
    Vec<int, 6> pos_target      = {0, 0, 0, 0, 0, 0};
    Vec<int, 6> pos_source      = {0, 0, 0, 0, 0, 0};

    //project
    switch (pVD_Target->type()) {

    case CV_8UC1:
        for(                    pos_source[c_DIM_P] = 0, pos_target[c_DIM_P] = pos_source[c_DIM_P] + vOffset[c_DIM_P];      pos_target[c_DIM_P] < sz_target[c_DIM_P] && pos_source[c_DIM_P] < sz_source[c_DIM_P];   pos_target[c_DIM_P]++, pos_source[c_DIM_P]++)
            for(                pos_source[c_DIM_S] = 0, pos_target[c_DIM_S] = pos_source[c_DIM_S] + vOffset[c_DIM_S];      pos_target[c_DIM_S] < sz_target[c_DIM_S] && pos_source[c_DIM_S] < sz_source[c_DIM_S];   pos_target[c_DIM_S]++, pos_source[c_DIM_S]++)
                for(            pos_source[c_DIM_T] = 0, pos_target[c_DIM_T] = pos_source[c_DIM_T] + vOffset[c_DIM_T];      pos_target[c_DIM_T] < sz_target[c_DIM_T] && pos_source[c_DIM_T] < sz_source[c_DIM_T];   pos_target[c_DIM_T]++, pos_source[c_DIM_T]++)
                    for(        pos_source[c_DIM_Z] = 0, pos_target[c_DIM_Z] = pos_source[c_DIM_Z] + vOffset[c_DIM_Z];      pos_target[c_DIM_Z] < sz_target[c_DIM_Z] && pos_source[c_DIM_Z] < sz_source[c_DIM_Z];   pos_target[c_DIM_Z]++, pos_source[c_DIM_Z]++)
                        for(    pos_source[c_DIM_Y] = 0, pos_target[c_DIM_Y] = pos_source[c_DIM_Y] + vOffset[c_DIM_Y];      pos_target[c_DIM_Y] < sz_target[c_DIM_Y] && pos_source[c_DIM_Y] < sz_source[c_DIM_Y];   pos_target[c_DIM_Y]++, pos_source[c_DIM_Y]++)
                            for(pos_source[c_DIM_X] = 0, pos_target[c_DIM_X] = pos_source[c_DIM_X] + vOffset[c_DIM_X];      pos_target[c_DIM_X] < sz_target[c_DIM_X] && pos_source[c_DIM_X] < sz_source[c_DIM_X];   pos_target[c_DIM_X]++, pos_source[c_DIM_X]++)
                                pVD_Target->pMA_full()->at<uchar>(pos_target) = pVD_Source->pMA_full()->at<uchar>(pos_source);
        break;

    case CV_8SC1:
        for(                    pos_source[c_DIM_P] = 0, pos_target[c_DIM_P] = pos_source[c_DIM_P] + vOffset[c_DIM_P];      pos_target[c_DIM_P] < sz_target[c_DIM_P] && pos_source[c_DIM_P] < sz_source[c_DIM_P];   pos_target[c_DIM_P]++, pos_source[c_DIM_P]++)
            for(                pos_source[c_DIM_S] = 0, pos_target[c_DIM_S] = pos_source[c_DIM_S] + vOffset[c_DIM_S];      pos_target[c_DIM_S] < sz_target[c_DIM_S] && pos_source[c_DIM_S] < sz_source[c_DIM_S];   pos_target[c_DIM_S]++, pos_source[c_DIM_S]++)
                for(            pos_source[c_DIM_T] = 0, pos_target[c_DIM_T] = pos_source[c_DIM_T] + vOffset[c_DIM_T];      pos_target[c_DIM_T] < sz_target[c_DIM_T] && pos_source[c_DIM_T] < sz_source[c_DIM_T];   pos_target[c_DIM_T]++, pos_source[c_DIM_T]++)
                    for(        pos_source[c_DIM_Z] = 0, pos_target[c_DIM_Z] = pos_source[c_DIM_Z] + vOffset[c_DIM_Z];      pos_target[c_DIM_Z] < sz_target[c_DIM_Z] && pos_source[c_DIM_Z] < sz_source[c_DIM_Z];   pos_target[c_DIM_Z]++, pos_source[c_DIM_Z]++)
                        for(    pos_source[c_DIM_Y] = 0, pos_target[c_DIM_Y] = pos_source[c_DIM_Y] + vOffset[c_DIM_Y];      pos_target[c_DIM_Y] < sz_target[c_DIM_Y] && pos_source[c_DIM_Y] < sz_source[c_DIM_Y];   pos_target[c_DIM_Y]++, pos_source[c_DIM_Y]++)
                            for(pos_source[c_DIM_X] = 0, pos_target[c_DIM_X] = pos_source[c_DIM_X] + vOffset[c_DIM_X];      pos_target[c_DIM_X] < sz_target[c_DIM_X] && pos_source[c_DIM_X] < sz_source[c_DIM_X];   pos_target[c_DIM_X]++, pos_source[c_DIM_X]++)
                                pVD_Target->pMA_full()->at<char>(pos_target) = pVD_Source->pMA_full()->at<char>(pos_source);
        break;

    case CV_16UC1:
        for(                    pos_source[c_DIM_P] = 0, pos_target[c_DIM_P] = pos_source[c_DIM_P] + vOffset[c_DIM_P];      pos_target[c_DIM_P] < sz_target[c_DIM_P] && pos_source[c_DIM_P] < sz_source[c_DIM_P];   pos_target[c_DIM_P]++, pos_source[c_DIM_P]++)
            for(                pos_source[c_DIM_S] = 0, pos_target[c_DIM_S] = pos_source[c_DIM_S] + vOffset[c_DIM_S];      pos_target[c_DIM_S] < sz_target[c_DIM_S] && pos_source[c_DIM_S] < sz_source[c_DIM_S];   pos_target[c_DIM_S]++, pos_source[c_DIM_S]++)
                for(            pos_source[c_DIM_T] = 0, pos_target[c_DIM_T] = pos_source[c_DIM_T] + vOffset[c_DIM_T];      pos_target[c_DIM_T] < sz_target[c_DIM_T] && pos_source[c_DIM_T] < sz_source[c_DIM_T];   pos_target[c_DIM_T]++, pos_source[c_DIM_T]++)
                    for(        pos_source[c_DIM_Z] = 0, pos_target[c_DIM_Z] = pos_source[c_DIM_Z] + vOffset[c_DIM_Z];      pos_target[c_DIM_Z] < sz_target[c_DIM_Z] && pos_source[c_DIM_Z] < sz_source[c_DIM_Z];   pos_target[c_DIM_Z]++, pos_source[c_DIM_Z]++)
                        for(    pos_source[c_DIM_Y] = 0, pos_target[c_DIM_Y] = pos_source[c_DIM_Y] + vOffset[c_DIM_Y];      pos_target[c_DIM_Y] < sz_target[c_DIM_Y] && pos_source[c_DIM_Y] < sz_source[c_DIM_Y];   pos_target[c_DIM_Y]++, pos_source[c_DIM_Y]++)
                            for(pos_source[c_DIM_X] = 0, pos_target[c_DIM_X] = pos_source[c_DIM_X] + vOffset[c_DIM_X];      pos_target[c_DIM_X] < sz_target[c_DIM_X] && pos_source[c_DIM_X] < sz_source[c_DIM_X];   pos_target[c_DIM_X]++, pos_source[c_DIM_X]++)
                                pVD_Target->pMA_full()->at<ushort>(pos_target) = pVD_Source->pMA_full()->at<ushort>(pos_source);
        break;

    case CV_16SC1:
        for(                    pos_source[c_DIM_P] = 0, pos_target[c_DIM_P] = pos_source[c_DIM_P] + vOffset[c_DIM_P];      pos_target[c_DIM_P] < sz_target[c_DIM_P] && pos_source[c_DIM_P] < sz_source[c_DIM_P];   pos_target[c_DIM_P]++, pos_source[c_DIM_P]++)
            for(                pos_source[c_DIM_S] = 0, pos_target[c_DIM_S] = pos_source[c_DIM_S] + vOffset[c_DIM_S];      pos_target[c_DIM_S] < sz_target[c_DIM_S] && pos_source[c_DIM_S] < sz_source[c_DIM_S];   pos_target[c_DIM_S]++, pos_source[c_DIM_S]++)
                for(            pos_source[c_DIM_T] = 0, pos_target[c_DIM_T] = pos_source[c_DIM_T] + vOffset[c_DIM_T];      pos_target[c_DIM_T] < sz_target[c_DIM_T] && pos_source[c_DIM_T] < sz_source[c_DIM_T];   pos_target[c_DIM_T]++, pos_source[c_DIM_T]++)
                    for(        pos_source[c_DIM_Z] = 0, pos_target[c_DIM_Z] = pos_source[c_DIM_Z] + vOffset[c_DIM_Z];      pos_target[c_DIM_Z] < sz_target[c_DIM_Z] && pos_source[c_DIM_Z] < sz_source[c_DIM_Z];   pos_target[c_DIM_Z]++, pos_source[c_DIM_Z]++)
                        for(    pos_source[c_DIM_Y] = 0, pos_target[c_DIM_Y] = pos_source[c_DIM_Y] + vOffset[c_DIM_Y];      pos_target[c_DIM_Y] < sz_target[c_DIM_Y] && pos_source[c_DIM_Y] < sz_source[c_DIM_Y];   pos_target[c_DIM_Y]++, pos_source[c_DIM_Y]++)
                            for(pos_source[c_DIM_X] = 0, pos_target[c_DIM_X] = pos_source[c_DIM_X] + vOffset[c_DIM_X];      pos_target[c_DIM_X] < sz_target[c_DIM_X] && pos_source[c_DIM_X] < sz_source[c_DIM_X];   pos_target[c_DIM_X]++, pos_source[c_DIM_X]++)
                                pVD_Target->pMA_full()->at<short>(pos_target) = pVD_Source->pMA_full()->at<short>(pos_source);
        break;

    case CV_32SC1:
        for(                    pos_source[c_DIM_P] = 0, pos_target[c_DIM_P] = pos_source[c_DIM_P] + vOffset[c_DIM_P];      pos_target[c_DIM_P] < sz_target[c_DIM_P] && pos_source[c_DIM_P] < sz_source[c_DIM_P];   pos_target[c_DIM_P]++, pos_source[c_DIM_P]++)
            for(                pos_source[c_DIM_S] = 0, pos_target[c_DIM_S] = pos_source[c_DIM_S] + vOffset[c_DIM_S];      pos_target[c_DIM_S] < sz_target[c_DIM_S] && pos_source[c_DIM_S] < sz_source[c_DIM_S];   pos_target[c_DIM_S]++, pos_source[c_DIM_S]++)
                for(            pos_source[c_DIM_T] = 0, pos_target[c_DIM_T] = pos_source[c_DIM_T] + vOffset[c_DIM_T];      pos_target[c_DIM_T] < sz_target[c_DIM_T] && pos_source[c_DIM_T] < sz_source[c_DIM_T];   pos_target[c_DIM_T]++, pos_source[c_DIM_T]++)
                    for(        pos_source[c_DIM_Z] = 0, pos_target[c_DIM_Z] = pos_source[c_DIM_Z] + vOffset[c_DIM_Z];      pos_target[c_DIM_Z] < sz_target[c_DIM_Z] && pos_source[c_DIM_Z] < sz_source[c_DIM_Z];   pos_target[c_DIM_Z]++, pos_source[c_DIM_Z]++)
                        for(    pos_source[c_DIM_Y] = 0, pos_target[c_DIM_Y] = pos_source[c_DIM_Y] + vOffset[c_DIM_Y];      pos_target[c_DIM_Y] < sz_target[c_DIM_Y] && pos_source[c_DIM_Y] < sz_source[c_DIM_Y];   pos_target[c_DIM_Y]++, pos_source[c_DIM_Y]++)
                            for(pos_source[c_DIM_X] = 0, pos_target[c_DIM_X] = pos_source[c_DIM_X] + vOffset[c_DIM_X];      pos_target[c_DIM_X] < sz_target[c_DIM_X] && pos_source[c_DIM_X] < sz_source[c_DIM_X];   pos_target[c_DIM_X]++, pos_source[c_DIM_X]++)
                                pVD_Target->pMA_full()->at<int>(pos_target) = pVD_Source->pMA_full()->at<int>(pos_source);
        break;

    case CV_32FC1:
        for(                    pos_source[c_DIM_P] = 0, pos_target[c_DIM_P] = pos_source[c_DIM_P] + vOffset[c_DIM_P];      pos_target[c_DIM_P] < sz_target[c_DIM_P] && pos_source[c_DIM_P] < sz_source[c_DIM_P];   pos_target[c_DIM_P]++, pos_source[c_DIM_P]++)
            for(                pos_source[c_DIM_S] = 0, pos_target[c_DIM_S] = pos_source[c_DIM_S] + vOffset[c_DIM_S];      pos_target[c_DIM_S] < sz_target[c_DIM_S] && pos_source[c_DIM_S] < sz_source[c_DIM_S];   pos_target[c_DIM_S]++, pos_source[c_DIM_S]++)
                for(            pos_source[c_DIM_T] = 0, pos_target[c_DIM_T] = pos_source[c_DIM_T] + vOffset[c_DIM_T];      pos_target[c_DIM_T] < sz_target[c_DIM_T] && pos_source[c_DIM_T] < sz_source[c_DIM_T];   pos_target[c_DIM_T]++, pos_source[c_DIM_T]++)
                    for(        pos_source[c_DIM_Z] = 0, pos_target[c_DIM_Z] = pos_source[c_DIM_Z] + vOffset[c_DIM_Z];      pos_target[c_DIM_Z] < sz_target[c_DIM_Z] && pos_source[c_DIM_Z] < sz_source[c_DIM_Z];   pos_target[c_DIM_Z]++, pos_source[c_DIM_Z]++)
                        for(    pos_source[c_DIM_Y] = 0, pos_target[c_DIM_Y] = pos_source[c_DIM_Y] + vOffset[c_DIM_Y];      pos_target[c_DIM_Y] < sz_target[c_DIM_Y] && pos_source[c_DIM_Y] < sz_source[c_DIM_Y];   pos_target[c_DIM_Y]++, pos_source[c_DIM_Y]++)
                            for(pos_source[c_DIM_X] = 0, pos_target[c_DIM_X] = pos_source[c_DIM_X] + vOffset[c_DIM_X];      pos_target[c_DIM_X] < sz_target[c_DIM_X] && pos_source[c_DIM_X] < sz_source[c_DIM_X];   pos_target[c_DIM_X]++, pos_source[c_DIM_X]++)
                                pVD_Target->pMA_full()->at<float>(pos_target) = pVD_Source->pMA_full()->at<float>(pos_source);
        break;

    case CV_64FC1:
        for(                    pos_source[c_DIM_P] = 0, pos_target[c_DIM_P] = pos_source[c_DIM_P] + vOffset[c_DIM_P];      pos_target[c_DIM_P] < sz_target[c_DIM_P] && pos_source[c_DIM_P] < sz_source[c_DIM_P];   pos_target[c_DIM_P]++, pos_source[c_DIM_P]++)
            for(                pos_source[c_DIM_S] = 0, pos_target[c_DIM_S] = pos_source[c_DIM_S] + vOffset[c_DIM_S];      pos_target[c_DIM_S] < sz_target[c_DIM_S] && pos_source[c_DIM_S] < sz_source[c_DIM_S];   pos_target[c_DIM_S]++, pos_source[c_DIM_S]++)
                for(            pos_source[c_DIM_T] = 0, pos_target[c_DIM_T] = pos_source[c_DIM_T] + vOffset[c_DIM_T];      pos_target[c_DIM_T] < sz_target[c_DIM_T] && pos_source[c_DIM_T] < sz_source[c_DIM_T];   pos_target[c_DIM_T]++, pos_source[c_DIM_T]++)
                    for(        pos_source[c_DIM_Z] = 0, pos_target[c_DIM_Z] = pos_source[c_DIM_Z] + vOffset[c_DIM_Z];      pos_target[c_DIM_Z] < sz_target[c_DIM_Z] && pos_source[c_DIM_Z] < sz_source[c_DIM_Z];   pos_target[c_DIM_Z]++, pos_source[c_DIM_Z]++)
                        for(    pos_source[c_DIM_Y] = 0, pos_target[c_DIM_Y] = pos_source[c_DIM_Y] + vOffset[c_DIM_Y];      pos_target[c_DIM_Y] < sz_target[c_DIM_Y] && pos_source[c_DIM_Y] < sz_source[c_DIM_Y];   pos_target[c_DIM_Y]++, pos_source[c_DIM_Y]++)
                            for(pos_source[c_DIM_X] = 0, pos_target[c_DIM_X] = pos_source[c_DIM_X] + vOffset[c_DIM_X];      pos_target[c_DIM_X] < sz_target[c_DIM_X] && pos_source[c_DIM_X] < sz_source[c_DIM_X];   pos_target[c_DIM_X]++, pos_source[c_DIM_X]++)
                                pVD_Target->pMA_full()->at<double>(pos_target) = pVD_Source->pMA_full()->at<double>(pos_source);
        break;

    case CV_8UC3:
        for(                    pos_source[c_DIM_P] = 0, pos_target[c_DIM_P] = pos_source[c_DIM_P] + vOffset[c_DIM_P];      pos_target[c_DIM_P] < sz_target[c_DIM_P] && pos_source[c_DIM_P] < sz_source[c_DIM_P];   pos_target[c_DIM_P]++, pos_source[c_DIM_P]++)
            for(                pos_source[c_DIM_S] = 0, pos_target[c_DIM_S] = pos_source[c_DIM_S] + vOffset[c_DIM_S];      pos_target[c_DIM_S] < sz_target[c_DIM_S] && pos_source[c_DIM_S] < sz_source[c_DIM_S];   pos_target[c_DIM_S]++, pos_source[c_DIM_S]++)
                for(            pos_source[c_DIM_T] = 0, pos_target[c_DIM_T] = pos_source[c_DIM_T] + vOffset[c_DIM_T];      pos_target[c_DIM_T] < sz_target[c_DIM_T] && pos_source[c_DIM_T] < sz_source[c_DIM_T];   pos_target[c_DIM_T]++, pos_source[c_DIM_T]++)
                    for(        pos_source[c_DIM_Z] = 0, pos_target[c_DIM_Z] = pos_source[c_DIM_Z] + vOffset[c_DIM_Z];      pos_target[c_DIM_Z] < sz_target[c_DIM_Z] && pos_source[c_DIM_Z] < sz_source[c_DIM_Z];   pos_target[c_DIM_Z]++, pos_source[c_DIM_Z]++)
                        for(    pos_source[c_DIM_Y] = 0, pos_target[c_DIM_Y] = pos_source[c_DIM_Y] + vOffset[c_DIM_Y];      pos_target[c_DIM_Y] < sz_target[c_DIM_Y] && pos_source[c_DIM_Y] < sz_source[c_DIM_Y];   pos_target[c_DIM_Y]++, pos_source[c_DIM_Y]++)
                            for(pos_source[c_DIM_X] = 0, pos_target[c_DIM_X] = pos_source[c_DIM_X] + vOffset[c_DIM_X];      pos_target[c_DIM_X] < sz_target[c_DIM_X] && pos_source[c_DIM_X] < sz_source[c_DIM_X];   pos_target[c_DIM_X]++, pos_source[c_DIM_X]++)
                                pVD_Target->pMA_full()->at<Vec3b>(pos_target) = pVD_Source->pMA_full()->at<Vec3b>(pos_source);
        break;

    case CV_16UC3:
        for(                    pos_source[c_DIM_P] = 0, pos_target[c_DIM_P] = pos_source[c_DIM_P] + vOffset[c_DIM_P];      pos_target[c_DIM_P] < sz_target[c_DIM_P] && pos_source[c_DIM_P] < sz_source[c_DIM_P];   pos_target[c_DIM_P]++, pos_source[c_DIM_P]++)
            for(                pos_source[c_DIM_S] = 0, pos_target[c_DIM_S] = pos_source[c_DIM_S] + vOffset[c_DIM_S];      pos_target[c_DIM_S] < sz_target[c_DIM_S] && pos_source[c_DIM_S] < sz_source[c_DIM_S];   pos_target[c_DIM_S]++, pos_source[c_DIM_S]++)
                for(            pos_source[c_DIM_T] = 0, pos_target[c_DIM_T] = pos_source[c_DIM_T] + vOffset[c_DIM_T];      pos_target[c_DIM_T] < sz_target[c_DIM_T] && pos_source[c_DIM_T] < sz_source[c_DIM_T];   pos_target[c_DIM_T]++, pos_source[c_DIM_T]++)
                    for(        pos_source[c_DIM_Z] = 0, pos_target[c_DIM_Z] = pos_source[c_DIM_Z] + vOffset[c_DIM_Z];      pos_target[c_DIM_Z] < sz_target[c_DIM_Z] && pos_source[c_DIM_Z] < sz_source[c_DIM_Z];   pos_target[c_DIM_Z]++, pos_source[c_DIM_Z]++)
                        for(    pos_source[c_DIM_Y] = 0, pos_target[c_DIM_Y] = pos_source[c_DIM_Y] + vOffset[c_DIM_Y];      pos_target[c_DIM_Y] < sz_target[c_DIM_Y] && pos_source[c_DIM_Y] < sz_source[c_DIM_Y];   pos_target[c_DIM_Y]++, pos_source[c_DIM_Y]++)
                            for(pos_source[c_DIM_X] = 0, pos_target[c_DIM_X] = pos_source[c_DIM_X] + vOffset[c_DIM_X];      pos_target[c_DIM_X] < sz_target[c_DIM_X] && pos_source[c_DIM_X] < sz_source[c_DIM_X];   pos_target[c_DIM_X]++, pos_source[c_DIM_X]++)
                                pVD_Target->pMA_full()->at<Vec3w>(pos_target) = pVD_Source->pMA_full()->at<Vec3w>(pos_source);
        break;

    case CV_16SC3:
        for(                    pos_source[c_DIM_P] = 0, pos_target[c_DIM_P] = pos_source[c_DIM_P] + vOffset[c_DIM_P];      pos_target[c_DIM_P] < sz_target[c_DIM_P] && pos_source[c_DIM_P] < sz_source[c_DIM_P];   pos_target[c_DIM_P]++, pos_source[c_DIM_P]++)
            for(                pos_source[c_DIM_S] = 0, pos_target[c_DIM_S] = pos_source[c_DIM_S] + vOffset[c_DIM_S];      pos_target[c_DIM_S] < sz_target[c_DIM_S] && pos_source[c_DIM_S] < sz_source[c_DIM_S];   pos_target[c_DIM_S]++, pos_source[c_DIM_S]++)
                for(            pos_source[c_DIM_T] = 0, pos_target[c_DIM_T] = pos_source[c_DIM_T] + vOffset[c_DIM_T];      pos_target[c_DIM_T] < sz_target[c_DIM_T] && pos_source[c_DIM_T] < sz_source[c_DIM_T];   pos_target[c_DIM_T]++, pos_source[c_DIM_T]++)
                    for(        pos_source[c_DIM_Z] = 0, pos_target[c_DIM_Z] = pos_source[c_DIM_Z] + vOffset[c_DIM_Z];      pos_target[c_DIM_Z] < sz_target[c_DIM_Z] && pos_source[c_DIM_Z] < sz_source[c_DIM_Z];   pos_target[c_DIM_Z]++, pos_source[c_DIM_Z]++)
                        for(    pos_source[c_DIM_Y] = 0, pos_target[c_DIM_Y] = pos_source[c_DIM_Y] + vOffset[c_DIM_Y];      pos_target[c_DIM_Y] < sz_target[c_DIM_Y] && pos_source[c_DIM_Y] < sz_source[c_DIM_Y];   pos_target[c_DIM_Y]++, pos_source[c_DIM_Y]++)
                            for(pos_source[c_DIM_X] = 0, pos_target[c_DIM_X] = pos_source[c_DIM_X] + vOffset[c_DIM_X];      pos_target[c_DIM_X] < sz_target[c_DIM_X] && pos_source[c_DIM_X] < sz_source[c_DIM_X];   pos_target[c_DIM_X]++, pos_source[c_DIM_X]++)
                                pVD_Target->pMA_full()->at<Vec3s>(pos_target) = pVD_Source->pMA_full()->at<Vec3s>(pos_source);
        break;

    case CV_32SC3:
        for(                    pos_source[c_DIM_P] = 0, pos_target[c_DIM_P] = pos_source[c_DIM_P] + vOffset[c_DIM_P];      pos_target[c_DIM_P] < sz_target[c_DIM_P] && pos_source[c_DIM_P] < sz_source[c_DIM_P];   pos_target[c_DIM_P]++, pos_source[c_DIM_P]++)
            for(                pos_source[c_DIM_S] = 0, pos_target[c_DIM_S] = pos_source[c_DIM_S] + vOffset[c_DIM_S];      pos_target[c_DIM_S] < sz_target[c_DIM_S] && pos_source[c_DIM_S] < sz_source[c_DIM_S];   pos_target[c_DIM_S]++, pos_source[c_DIM_S]++)
                for(            pos_source[c_DIM_T] = 0, pos_target[c_DIM_T] = pos_source[c_DIM_T] + vOffset[c_DIM_T];      pos_target[c_DIM_T] < sz_target[c_DIM_T] && pos_source[c_DIM_T] < sz_source[c_DIM_T];   pos_target[c_DIM_T]++, pos_source[c_DIM_T]++)
                    for(        pos_source[c_DIM_Z] = 0, pos_target[c_DIM_Z] = pos_source[c_DIM_Z] + vOffset[c_DIM_Z];      pos_target[c_DIM_Z] < sz_target[c_DIM_Z] && pos_source[c_DIM_Z] < sz_source[c_DIM_Z];   pos_target[c_DIM_Z]++, pos_source[c_DIM_Z]++)
                        for(    pos_source[c_DIM_Y] = 0, pos_target[c_DIM_Y] = pos_source[c_DIM_Y] + vOffset[c_DIM_Y];      pos_target[c_DIM_Y] < sz_target[c_DIM_Y] && pos_source[c_DIM_Y] < sz_source[c_DIM_Y];   pos_target[c_DIM_Y]++, pos_source[c_DIM_Y]++)
                            for(pos_source[c_DIM_X] = 0, pos_target[c_DIM_X] = pos_source[c_DIM_X] + vOffset[c_DIM_X];      pos_target[c_DIM_X] < sz_target[c_DIM_X] && pos_source[c_DIM_X] < sz_source[c_DIM_X];   pos_target[c_DIM_X]++, pos_source[c_DIM_X]++)
                                pVD_Target->pMA_full()->at<Vec3i>(pos_target) = pVD_Source->pMA_full()->at<Vec3i>(pos_source);
        break;

    case CV_32FC3:
        for(                    pos_source[c_DIM_P] = 0, pos_target[c_DIM_P] = pos_source[c_DIM_P] + vOffset[c_DIM_P];      pos_target[c_DIM_P] < sz_target[c_DIM_P] && pos_source[c_DIM_P] < sz_source[c_DIM_P];   pos_target[c_DIM_P]++, pos_source[c_DIM_P]++)
            for(                pos_source[c_DIM_S] = 0, pos_target[c_DIM_S] = pos_source[c_DIM_S] + vOffset[c_DIM_S];      pos_target[c_DIM_S] < sz_target[c_DIM_S] && pos_source[c_DIM_S] < sz_source[c_DIM_S];   pos_target[c_DIM_S]++, pos_source[c_DIM_S]++)
                for(            pos_source[c_DIM_T] = 0, pos_target[c_DIM_T] = pos_source[c_DIM_T] + vOffset[c_DIM_T];      pos_target[c_DIM_T] < sz_target[c_DIM_T] && pos_source[c_DIM_T] < sz_source[c_DIM_T];   pos_target[c_DIM_T]++, pos_source[c_DIM_T]++)
                    for(        pos_source[c_DIM_Z] = 0, pos_target[c_DIM_Z] = pos_source[c_DIM_Z] + vOffset[c_DIM_Z];      pos_target[c_DIM_Z] < sz_target[c_DIM_Z] && pos_source[c_DIM_Z] < sz_source[c_DIM_Z];   pos_target[c_DIM_Z]++, pos_source[c_DIM_Z]++)
                        for(    pos_source[c_DIM_Y] = 0, pos_target[c_DIM_Y] = pos_source[c_DIM_Y] + vOffset[c_DIM_Y];      pos_target[c_DIM_Y] < sz_target[c_DIM_Y] && pos_source[c_DIM_Y] < sz_source[c_DIM_Y];   pos_target[c_DIM_Y]++, pos_source[c_DIM_Y]++)
                            for(pos_source[c_DIM_X] = 0, pos_target[c_DIM_X] = pos_source[c_DIM_X] + vOffset[c_DIM_X];      pos_target[c_DIM_X] < sz_target[c_DIM_X] && pos_source[c_DIM_X] < sz_source[c_DIM_X];   pos_target[c_DIM_X]++, pos_source[c_DIM_X]++)
                                pVD_Target->pMA_full()->at<Vec3f>(pos_target) = pVD_Source->pMA_full()->at<Vec3f>(pos_source);
        break;

    case CV_64FC3:
        for(                    pos_source[c_DIM_P] = 0, pos_target[c_DIM_P] = pos_source[c_DIM_P] + vOffset[c_DIM_P];      pos_target[c_DIM_P] < sz_target[c_DIM_P] && pos_source[c_DIM_P] < sz_source[c_DIM_P];   pos_target[c_DIM_P]++, pos_source[c_DIM_P]++)
            for(                pos_source[c_DIM_S] = 0, pos_target[c_DIM_S] = pos_source[c_DIM_S] + vOffset[c_DIM_S];      pos_target[c_DIM_S] < sz_target[c_DIM_S] && pos_source[c_DIM_S] < sz_source[c_DIM_S];   pos_target[c_DIM_S]++, pos_source[c_DIM_S]++)
                for(            pos_source[c_DIM_T] = 0, pos_target[c_DIM_T] = pos_source[c_DIM_T] + vOffset[c_DIM_T];      pos_target[c_DIM_T] < sz_target[c_DIM_T] && pos_source[c_DIM_T] < sz_source[c_DIM_T];   pos_target[c_DIM_T]++, pos_source[c_DIM_T]++)
                    for(        pos_source[c_DIM_Z] = 0, pos_target[c_DIM_Z] = pos_source[c_DIM_Z] + vOffset[c_DIM_Z];      pos_target[c_DIM_Z] < sz_target[c_DIM_Z] && pos_source[c_DIM_Z] < sz_source[c_DIM_Z];   pos_target[c_DIM_Z]++, pos_source[c_DIM_Z]++)
                        for(    pos_source[c_DIM_Y] = 0, pos_target[c_DIM_Y] = pos_source[c_DIM_Y] + vOffset[c_DIM_Y];      pos_target[c_DIM_Y] < sz_target[c_DIM_Y] && pos_source[c_DIM_Y] < sz_source[c_DIM_Y];   pos_target[c_DIM_Y]++, pos_source[c_DIM_Y]++)
                            for(pos_source[c_DIM_X] = 0, pos_target[c_DIM_X] = pos_source[c_DIM_X] + vOffset[c_DIM_X];      pos_target[c_DIM_X] < sz_target[c_DIM_X] && pos_source[c_DIM_X] < sz_source[c_DIM_X];   pos_target[c_DIM_X]++, pos_source[c_DIM_X]++)
                                pVD_Target->pMA_full()->at<Vec3d>(pos_target) = pVD_Source->pMA_full()->at<Vec3d>(pos_source);
        break;

    default:
        return ER_type_bad;
    }

    return ER_okay;
}

int D_VisDat_Proc::Read_2D_Plane(Mat *pMA_Out, D_VisDat_Obj *pVD_In, D_VisDat_Slice_2D InPlane)
{
    //qDebug() << "Read_2D_Plane";

    //checks
    int ER = InPlane.ER_OutOfrange(pVD_In->Dim());
    if(ER != ER_okay)                               return ER;

    //position/extension/dimension
    int ext1 = InPlane.extended_Dim(0);
    int ext2 = InPlane.extended_Dim(1);
    //qDebug() << "ext1/2" << QSL_DimIndices[ext1] << QSL_DimIndices[ext2];
    int sz1 = pVD_In->Dim().size_Dim(ext1);
    int sz2 = pVD_In->Dim().size_Dim(ext2);
    int tpIn = pVD_In->type();
    Vec<int, c_DIM_NUMBER_OF> v_pos = InPlane.pos_Dims();

    //init out
    *pMA_Out = Mat(sz2, sz1, tpIn);

    //loop extended dims (SLOW!!! - to be replaced later)
    switch (tpIn) {

    case CV_8UC1:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<uchar>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<uchar>(v_pos);
        break;

    case CV_8SC1:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<char>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<char>(v_pos);
        break;

    case CV_16UC1:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<ushort>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<ushort>(v_pos);
        break;

    case CV_16SC1:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<short>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<short>(v_pos);
        break;

    case CV_32SC1:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<int>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<int>(v_pos);
        break;

    case CV_32FC1:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<float>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<float>(v_pos);
        break;

    case CV_64FC1:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<double>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<double>(v_pos);
        break;

        //2 Channels

    case CV_8UC2:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec2b>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec2b>(v_pos);
        break;

    case CV_16UC2:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec2w>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec2w>(v_pos);
        break;

    case CV_16SC2:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec2s>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec2s>(v_pos);
        break;

    case CV_32SC2:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec2i>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec2i>(v_pos);
        break;

    case CV_32FC2:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec2f>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec2f>(v_pos);
        break;

    case CV_64FC2:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec2d>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec2d>(v_pos);
        break;

        //3 Channels

    case CV_8UC3:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec3b>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec3b>(v_pos);
        break;

    case CV_16UC3:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec3w>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec3w>(v_pos);
        break;

    case CV_16SC3:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec3s>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec3s>(v_pos);
        break;

    case CV_32SC3:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec3i>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec3i>(v_pos);
        break;

    case CV_32FC3:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec3f>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec3f>(v_pos);
        break;

    case CV_64FC3:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec3d>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec3d>(v_pos);
        break;

        //4 Channels

    case CV_8UC4:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec4b>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec4b>(v_pos);
        break;

    case CV_16UC4:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec4w>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec4w>(v_pos);
        break;

    case CV_16SC4:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec4s>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec4s>(v_pos);
        break;

    case CV_32SC4:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec4i>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec4i>(v_pos);
        break;

    case CV_32FC4:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec4f>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec4f>(v_pos);
        break;

    case CV_64FC4:
        for(v_pos[ext2] = 0; v_pos[ext2] < sz2; v_pos[ext2]++)
            for(v_pos[ext1] = 0; v_pos[ext1] < sz1; v_pos[ext1]++)
                pMA_Out->at<Vec4d>(v_pos[ext2], v_pos[ext1]) = pVD_In->pMA_full()->at<Vec4d>(v_pos);
        break;

    default:
        return ER_type_bad;
        break;
    }

    //sucess :-)
    //qDebug() << "test Read_2D_Plane - end";
    return ER_okay;
}

int D_VisDat_Proc::Read_3D_Cuboid(Mat *pMA_Out, D_VisDat_Obj *pVD_In, D_VisDat_Slice_3D InPlane)
{
    //qDebug() << "Read_3D_Cuboid";

    //checks
    int ER = InPlane.ER_OutOfrange(pVD_In->Dim());
    if(ER != ER_okay)                               return ER;

    //position/extension/dimension
    int ext1 = InPlane.extended_Dim(0);
    int ext2 = InPlane.extended_Dim(1);
    int ext3 = InPlane.extended_Dim(2);

    int sz1 = pVD_In->Dim().size_Dim(ext1);
    int sz2 = pVD_In->Dim().size_Dim(ext2);
    int sz3 = pVD_In->Dim().size_Dim(ext3);

    int tpIn = pVD_In->type();

    Vec<int, c_DIM_NUMBER_OF>   v_pos6d = InPlane.pos_Dims();
    Vec<int, 3>                 v_pos3d = {0, 0, 0};

    //init out
    int sz[] = {sz1, sz2, sz3};
    *pMA_Out = Mat(3, sz, tpIn);

    //loop extended dims (SLOW!!! - to be replaced later)
    switch (tpIn) {

    case CV_8UC1:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<uchar>(v_pos3d) = pVD_In->pMA_full()->at<uchar>(v_pos6d);
                }
        break;

    case CV_8SC1:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<char>(v_pos3d) = pVD_In->pMA_full()->at<char>(v_pos6d);
                }
        break;

    case CV_16UC1:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<ushort>(v_pos3d) = pVD_In->pMA_full()->at<ushort>(v_pos6d);
                }
        break;

    case CV_16SC1:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<short>(v_pos3d) = pVD_In->pMA_full()->at<short>(v_pos6d);
                }
        break;

    case CV_32SC1:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<int>(v_pos3d) = pVD_In->pMA_full()->at<int>(v_pos6d);
                }
        break;

    case CV_32FC1:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<float>(v_pos3d) = pVD_In->pMA_full()->at<float>(v_pos6d);
                }
        break;

    case CV_64FC1:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<double>(v_pos3d) = pVD_In->pMA_full()->at<double>(v_pos6d);
                }
        break;

        //2 Channels

    case CV_8UC2:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec2b>(v_pos3d) = pVD_In->pMA_full()->at<Vec2b>(v_pos6d);
                }
        break;

    case CV_16UC2:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec2w>(v_pos3d) = pVD_In->pMA_full()->at<Vec2w>(v_pos6d);
                }
        break;

    case CV_16SC2:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec2s>(v_pos3d) = pVD_In->pMA_full()->at<Vec2s>(v_pos6d);
                }
        break;

    case CV_32SC2:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec2i>(v_pos3d) = pVD_In->pMA_full()->at<Vec2i>(v_pos6d);
                }
        break;

    case CV_32FC2:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec2f>(v_pos3d) = pVD_In->pMA_full()->at<Vec2f>(v_pos6d);
                }
        break;

    case CV_64FC2:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec2d>(v_pos3d) = pVD_In->pMA_full()->at<Vec2d>(v_pos6d);
                }
        break;



        //3 Channels

    case CV_8UC3:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec3b>(v_pos3d) = pVD_In->pMA_full()->at<Vec3b>(v_pos6d);
                }
        break;

    case CV_16UC3:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec3w>(v_pos3d) = pVD_In->pMA_full()->at<Vec3w>(v_pos6d);
                }
        break;

    case CV_16SC3:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec3s>(v_pos3d) = pVD_In->pMA_full()->at<Vec3s>(v_pos6d);
                }
        break;

    case CV_32SC3:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec3i>(v_pos3d) = pVD_In->pMA_full()->at<Vec3i>(v_pos6d);
                }
        break;

    case CV_32FC3:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec3f>(v_pos3d) = pVD_In->pMA_full()->at<Vec3f>(v_pos6d);
                }
        break;

    case CV_64FC3:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec3d>(v_pos3d) = pVD_In->pMA_full()->at<Vec3d>(v_pos6d);
                }
        break;

        //4 Channels

    case CV_8UC4:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec4b>(v_pos3d) = pVD_In->pMA_full()->at<Vec4b>(v_pos6d);
                }
        break;

    case CV_16UC4:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec4w>(v_pos3d) = pVD_In->pMA_full()->at<Vec4w>(v_pos6d);
                }
        break;

    case CV_16SC4:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec4s>(v_pos3d) = pVD_In->pMA_full()->at<Vec4s>(v_pos6d);
                }
        break;

    case CV_32SC4:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec4i>(v_pos3d) = pVD_In->pMA_full()->at<Vec4i>(v_pos6d);
                }
        break;

    case CV_32FC4:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec4f>(v_pos3d) = pVD_In->pMA_full()->at<Vec4f>(v_pos6d);
                }
        break;

    case CV_64FC4:
        for(            v_pos6d[ext3] = 0, v_pos3d[2] = 0;      v_pos6d[ext3] < sz3;    v_pos6d[ext3]++, v_pos3d[2]++)
            for(        v_pos6d[ext2] = 0, v_pos3d[1] = 0;      v_pos6d[ext2] < sz2;    v_pos6d[ext2]++, v_pos3d[1]++)
                for(    v_pos6d[ext1] = 0, v_pos3d[0] = 0;      v_pos6d[ext1] < sz1;    v_pos6d[ext1]++, v_pos3d[0]++)
                {
                    pMA_Out->at<Vec4d>(v_pos3d) = pVD_In->pMA_full()->at<Vec4d>(v_pos6d);
                }
        break;

    default:
        return ER_type_bad;
        break;
    }

    //sucess :-)
    //qDebug() << "test Read_3D_Cuboid - end";
    return ER_okay;
}

int D_VisDat_Proc::Copy(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In)
{
    *pVD_Out = *pVD_In;

    return ER_okay;
}

int D_VisDat_Proc::Dim_Pick(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, vector<int> pick_pos)
{
    //Errors
    if(pick_pos.size() != c_DIM_NUMBER_OF)  return ER_dim_missmatch;
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(pick_pos[d] >= 0)
            if(pick_pos[d] >= pVD_In->Dim().size_Dim(d))
                return ER_dim_out_of_range;

    //new size_out and offset_in2out
    D_VisDat_Dim dim_out;
    Vec<int, c_DIM_NUMBER_OF> offset_in2out;

    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
    {
        if(pick_pos[d] >= 0)                                    //pick pos in dim
        {                                                       //->
            dim_out.set_size_Dim(d, 1);                         //picked dim is size 1
            offset_in2out[d] = pick_pos[d];                     //offset is picked pos
        }
        else                                                    //full range in this dim
        {                                                       //->
            dim_out.set_size_Dim(d, pVD_In->Dim().size_Dim(d)); //same size as input
            offset_in2out[d] = 0;                               //no offset
        }
    }

    dim_out.loop_SetOffset(offset_in2out);                      //set offset

    //new VD
    *pVD_Out = D_VisDat_Obj(
                dim_out,
                pVD_In->type());


    switch (pVD_In->type()) {

    //1ch

    case CV_8UC1:
        do      {pVD_Out->pMA_full()->at<uchar>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<uchar>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_8SC1:
        do      {pVD_Out->pMA_full()->at<char>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<char>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_16UC1:
        do      {pVD_Out->pMA_full()->at<ushort>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<ushort>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_16SC1:
        do      {pVD_Out->pMA_full()->at<short>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<short>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_32SC1:
        do      {pVD_Out->pMA_full()->at<int>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<int>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_32FC1:
        do      {pVD_Out->pMA_full()->at<float>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<float>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_64FC1:
        do      {pVD_Out->pMA_full()->at<double>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<double>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    //2ch

    case CV_8UC2:
        do      {pVD_Out->pMA_full()->at<Vec2b>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec2b>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_16UC2:
        do      {pVD_Out->pMA_full()->at<Vec2w>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec2w>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_16SC2:
        do      {pVD_Out->pMA_full()->at<Vec2s>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec2s>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_32SC2:
        do      {pVD_Out->pMA_full()->at<Vec2i>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec2i>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_32FC2:
        do      {pVD_Out->pMA_full()->at<Vec2f>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec2f>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_64FC2:
        do      {pVD_Out->pMA_full()->at<Vec2d>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec2d>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    //3ch

    case CV_8UC3:
        do      {pVD_Out->pMA_full()->at<Vec3b>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec3b>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_16UC3:
        do      {pVD_Out->pMA_full()->at<Vec3w>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec3w>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_16SC3:
        do      {pVD_Out->pMA_full()->at<Vec3s>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec3s>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_32SC3:
        do      {pVD_Out->pMA_full()->at<Vec3i>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec3i>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_32FC3:
        do      {pVD_Out->pMA_full()->at<Vec3f>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec3f>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_64FC3:
        do      {pVD_Out->pMA_full()->at<Vec3d>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec3d>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    //4ch

    case CV_8UC4:
        do      {pVD_Out->pMA_full()->at<Vec4b>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec4b>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_16UC4:
        do      {pVD_Out->pMA_full()->at<Vec4w>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec4w>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_16SC4:
        do      {pVD_Out->pMA_full()->at<Vec4s>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec4s>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_32SC4:
        do      {pVD_Out->pMA_full()->at<Vec4i>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec4i>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_32FC4:
        do      {pVD_Out->pMA_full()->at<Vec4f>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec4f>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_64FC4:
        do      {pVD_Out->pMA_full()->at<Vec4d>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec4d>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    default:
        return ER_type_bad;
    }


    return ER_okay;
}

int D_VisDat_Proc::Dim_Crop(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Range crop_range)
{
    //new size_out, offset_in2out, VD
    crop_range.Dim4Range_Init(pVD_In->pDim());                      //init range with dim to crop from
    D_VisDat_Dim dim_out = crop_range.Dim4Range_DimIntersect();     //croped_size out of in_size
    dim_out.loop_SetOffset(crop_range.Dim4Range_Offset());          //set offset
    *pVD_Out = D_VisDat_Obj(dim_out, pVD_In->type());               //new VD
    //qDebug() << "in " << pVD_In->info();
    //qDebug() << "out" << pVD_Out->info();


    switch (pVD_In->type()) {

    //1ch

    case CV_8UC1:
        do
        {pVD_Out->pMA_full()->at<uchar>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<uchar>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_8SC1:
        do      {pVD_Out->pMA_full()->at<char>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<char>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_16UC1:
        do      {pVD_Out->pMA_full()->at<ushort>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<ushort>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_16SC1:
        do      {pVD_Out->pMA_full()->at<short>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<short>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_32SC1:
        do      {pVD_Out->pMA_full()->at<int>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<int>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_32FC1:
        do      {pVD_Out->pMA_full()->at<float>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<float>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_64FC1:
        do      {pVD_Out->pMA_full()->at<double>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<double>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    //2ch

    case CV_8UC2:
        do      {pVD_Out->pMA_full()->at<Vec2b>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec2b>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_16UC2:
        do      {pVD_Out->pMA_full()->at<Vec2w>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec2w>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_16SC2:
        do      {pVD_Out->pMA_full()->at<Vec2s>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec2s>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_32SC2:
        do      {pVD_Out->pMA_full()->at<Vec2i>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec2i>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_32FC2:
        do      {pVD_Out->pMA_full()->at<Vec2f>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec2f>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_64FC2:
        do      {pVD_Out->pMA_full()->at<Vec2d>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec2d>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    //3ch

    case CV_8UC3:
        do      {pVD_Out->pMA_full()->at<Vec3b>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec3b>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_16UC3:
        do      {pVD_Out->pMA_full()->at<Vec3w>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec3w>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_16SC3:
        do      {pVD_Out->pMA_full()->at<Vec3s>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec3s>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_32SC3:
        do      {pVD_Out->pMA_full()->at<Vec3i>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec3i>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_32FC3:
        do      {pVD_Out->pMA_full()->at<Vec3f>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec3f>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_64FC3:
        do      {pVD_Out->pMA_full()->at<Vec3d>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec3d>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    //4ch

    case CV_8UC4:
        do      {pVD_Out->pMA_full()->at<Vec4b>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec4b>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_16UC4:
        do      {pVD_Out->pMA_full()->at<Vec4w>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec4w>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_16SC4:
        do      {pVD_Out->pMA_full()->at<Vec4s>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec4s>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_32SC4:
        do      {pVD_Out->pMA_full()->at<Vec4i>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec4i>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_32FC4:
        do      {pVD_Out->pMA_full()->at<Vec4f>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec4f>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    case CV_64FC4:
        do      {pVD_Out->pMA_full()->at<Vec4d>(dim_out.loop_PosCurrent()) = pVD_In->pMA_full()->at<Vec4d>(dim_out.loop_PosCurrent_Offset());}
        while   (dim_out.loop_Next());
        break;

    default:
        return ER_type_bad;
    }

    return ER_okay;
}

int D_VisDat_Proc::Dim_Project(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int dim_project, int stat, int out_type)
{
    //errors
    if(pVD_In->pMA_full()->empty())                                             return ER_empty;
    if(pVD_In->pMA_full()->channels() != 1)                                     return ER_channel_bad;
    if(out_type != CV_64FC1 && out_type != CV_8UC1 && out_type != CV_16UC1)     return ER_parameter_bad;

    //dims normal
    vector<int> dims_loop;
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(d != dim_project)
            dims_loop.push_back(d);

    //create output
    D_VisDat_Dim Dim_out = pVD_In->Dim();
    Dim_out.set_size_Dim(dim_project, 1);
    *pVD_Out = D_VisDat_Obj(Dim_out, out_type);

    //sizes
    vector<int> sz_out = Dim_out.size_DimsVec();

    //pos
    Vec<int, 6> pos_in      = {0, 0, 0, 0, 0, 0};
    Vec<int, 6> pos_out     = {0, 0, 0, 0, 0, 0};

    //projection
    int sz_project = pVD_In->pDim()->size_Dim(dim_project);
    vector<double> v_project(sz_project);

    //porjection function
    function<double (vector<double>)> F_project_64 = D_Stat::Function_SingleStat(stat);
    function<uchar  (vector<double>)> F_project_8u = D_Stat::Function_SingleStat_8bit(stat);

    //project
    switch (pVD_In->type()) {

    case CV_8UC1:
        for(                pos_out[dims_loop[4]] = 0, pos_in[dims_loop[4]] = 0;    pos_out[dims_loop[4]] < sz_out[dims_loop[4]];   pos_out[dims_loop[4]]++, pos_in[dims_loop[4]]++)
            for(            pos_out[dims_loop[3]] = 0, pos_in[dims_loop[3]] = 0;    pos_out[dims_loop[3]] < sz_out[dims_loop[3]];   pos_out[dims_loop[3]]++, pos_in[dims_loop[3]]++)
                for(        pos_out[dims_loop[2]] = 0, pos_in[dims_loop[2]] = 0;    pos_out[dims_loop[2]] < sz_out[dims_loop[2]];   pos_out[dims_loop[2]]++, pos_in[dims_loop[2]]++)
                    for(    pos_out[dims_loop[1]] = 0, pos_in[dims_loop[1]] = 0;    pos_out[dims_loop[1]] < sz_out[dims_loop[1]];   pos_out[dims_loop[1]]++, pos_in[dims_loop[1]]++)
                        for(pos_out[dims_loop[0]] = 0, pos_in[dims_loop[0]] = 0;    pos_out[dims_loop[0]] < sz_out[dims_loop[0]];   pos_out[dims_loop[0]]++, pos_in[dims_loop[0]]++)
                        {
                            for(pos_in[dim_project] = 0; pos_in[dim_project] < sz_project; pos_in[dim_project]++)
                                v_project[pos_in[dim_project]] = static_cast<double>(pVD_In->pMA_full()->at<uchar>(pos_in));

                            switch (out_type) {
                            case CV_64FC1:  pVD_Out->pMA_full()->at<double>(pos_out) = F_project_64(v_project);                             break;
                            case CV_16UC1:  pVD_Out->pMA_full()->at<ushort>(pos_out) = static_cast<ushort>(F_project_64(v_project));        break;
                            case CV_8UC1:   pVD_Out->pMA_full()->at<uchar>(pos_out)  = F_project_8u(v_project);                             break;
                            default:                                                                                                        return ER_type_bad;}
                        }
        break;

    case CV_8SC1:
        for(                pos_out[dims_loop[4]] = 0, pos_in[dims_loop[4]] = 0;    pos_out[dims_loop[4]] < sz_out[dims_loop[4]];   pos_out[dims_loop[4]]++, pos_in[dims_loop[4]]++)
            for(            pos_out[dims_loop[3]] = 0, pos_in[dims_loop[3]] = 0;    pos_out[dims_loop[3]] < sz_out[dims_loop[3]];   pos_out[dims_loop[3]]++, pos_in[dims_loop[3]]++)
                for(        pos_out[dims_loop[2]] = 0, pos_in[dims_loop[2]] = 0;    pos_out[dims_loop[2]] < sz_out[dims_loop[2]];   pos_out[dims_loop[2]]++, pos_in[dims_loop[2]]++)
                    for(    pos_out[dims_loop[1]] = 0, pos_in[dims_loop[1]] = 0;    pos_out[dims_loop[1]] < sz_out[dims_loop[1]];   pos_out[dims_loop[1]]++, pos_in[dims_loop[1]]++)
                        for(pos_out[dims_loop[0]] = 0, pos_in[dims_loop[0]] = 0;    pos_out[dims_loop[0]] < sz_out[dims_loop[0]];   pos_out[dims_loop[0]]++, pos_in[dims_loop[0]]++)
                        {
                            for(pos_in[dim_project] = 0; pos_in[dim_project] < sz_project; pos_in[dim_project]++)
                                v_project[pos_in[dim_project]] = static_cast<double>(pVD_In->pMA_full()->at<char>(pos_in));

                            switch (out_type) {
                            case CV_64FC1:  pVD_Out->pMA_full()->at<double>(pos_out) = F_project_64(v_project);                             break;
                            case CV_16UC1:  pVD_Out->pMA_full()->at<ushort>(pos_out) = static_cast<ushort>(F_project_64(v_project));        break;
                            case CV_8UC1:   pVD_Out->pMA_full()->at<uchar>(pos_out)  = F_project_8u(v_project);                             break;
                            default:                                                                                                        return ER_type_bad;}
                        }
        break;

    case CV_16UC1:
        for(                pos_out[dims_loop[4]] = 0, pos_in[dims_loop[4]] = 0;    pos_out[dims_loop[4]] < sz_out[dims_loop[4]];   pos_out[dims_loop[4]]++, pos_in[dims_loop[4]]++)
            for(            pos_out[dims_loop[3]] = 0, pos_in[dims_loop[3]] = 0;    pos_out[dims_loop[3]] < sz_out[dims_loop[3]];   pos_out[dims_loop[3]]++, pos_in[dims_loop[3]]++)
                for(        pos_out[dims_loop[2]] = 0, pos_in[dims_loop[2]] = 0;    pos_out[dims_loop[2]] < sz_out[dims_loop[2]];   pos_out[dims_loop[2]]++, pos_in[dims_loop[2]]++)
                    for(    pos_out[dims_loop[1]] = 0, pos_in[dims_loop[1]] = 0;    pos_out[dims_loop[1]] < sz_out[dims_loop[1]];   pos_out[dims_loop[1]]++, pos_in[dims_loop[1]]++)
                        for(pos_out[dims_loop[0]] = 0, pos_in[dims_loop[0]] = 0;    pos_out[dims_loop[0]] < sz_out[dims_loop[0]];   pos_out[dims_loop[0]]++, pos_in[dims_loop[0]]++)
                        {
                            for(pos_in[dim_project] = 0; pos_in[dim_project] < sz_project; pos_in[dim_project]++)
                                v_project[pos_in[dim_project]] = static_cast<double>(pVD_In->pMA_full()->at<ushort>(pos_in));

                            switch (out_type) {
                            case CV_64FC1:  pVD_Out->pMA_full()->at<double>(pos_out) = F_project_64(v_project);                             break;
                            case CV_16UC1:  pVD_Out->pMA_full()->at<ushort>(pos_out) = static_cast<ushort>(F_project_64(v_project));        break;
                            case CV_8UC1:   pVD_Out->pMA_full()->at<uchar>(pos_out)  = F_project_8u(v_project);                             break;
                            default:                                                                                                        return ER_type_bad;}
                        }
        break;

    case CV_16SC1:
        for(                pos_out[dims_loop[4]] = 0, pos_in[dims_loop[4]] = 0;    pos_out[dims_loop[4]] < sz_out[dims_loop[4]];   pos_out[dims_loop[4]]++, pos_in[dims_loop[4]]++)
            for(            pos_out[dims_loop[3]] = 0, pos_in[dims_loop[3]] = 0;    pos_out[dims_loop[3]] < sz_out[dims_loop[3]];   pos_out[dims_loop[3]]++, pos_in[dims_loop[3]]++)
                for(        pos_out[dims_loop[2]] = 0, pos_in[dims_loop[2]] = 0;    pos_out[dims_loop[2]] < sz_out[dims_loop[2]];   pos_out[dims_loop[2]]++, pos_in[dims_loop[2]]++)
                    for(    pos_out[dims_loop[1]] = 0, pos_in[dims_loop[1]] = 0;    pos_out[dims_loop[1]] < sz_out[dims_loop[1]];   pos_out[dims_loop[1]]++, pos_in[dims_loop[1]]++)
                        for(pos_out[dims_loop[0]] = 0, pos_in[dims_loop[0]] = 0;    pos_out[dims_loop[0]] < sz_out[dims_loop[0]];   pos_out[dims_loop[0]]++, pos_in[dims_loop[0]]++)
                        {
                            for(pos_in[dim_project] = 0; pos_in[dim_project] < sz_project; pos_in[dim_project]++)
                                v_project[pos_in[dim_project]] = static_cast<double>(pVD_In->pMA_full()->at<short>(pos_in));

                            switch (out_type) {
                            case CV_64FC1:  pVD_Out->pMA_full()->at<double>(pos_out) = F_project_64(v_project);                             break;
                            case CV_16UC1:  pVD_Out->pMA_full()->at<ushort>(pos_out) = static_cast<ushort>(F_project_64(v_project));        break;
                            case CV_8UC1:   pVD_Out->pMA_full()->at<uchar>(pos_out)  = F_project_8u(v_project);                             break;
                            default:                                                                                                        return ER_type_bad;}
                        }
        break;

    case CV_32SC1:
        for(                pos_out[dims_loop[4]] = 0, pos_in[dims_loop[4]] = 0;    pos_out[dims_loop[4]] < sz_out[dims_loop[4]];   pos_out[dims_loop[4]]++, pos_in[dims_loop[4]]++)
            for(            pos_out[dims_loop[3]] = 0, pos_in[dims_loop[3]] = 0;    pos_out[dims_loop[3]] < sz_out[dims_loop[3]];   pos_out[dims_loop[3]]++, pos_in[dims_loop[3]]++)
                for(        pos_out[dims_loop[2]] = 0, pos_in[dims_loop[2]] = 0;    pos_out[dims_loop[2]] < sz_out[dims_loop[2]];   pos_out[dims_loop[2]]++, pos_in[dims_loop[2]]++)
                    for(    pos_out[dims_loop[1]] = 0, pos_in[dims_loop[1]] = 0;    pos_out[dims_loop[1]] < sz_out[dims_loop[1]];   pos_out[dims_loop[1]]++, pos_in[dims_loop[1]]++)
                        for(pos_out[dims_loop[0]] = 0, pos_in[dims_loop[0]] = 0;    pos_out[dims_loop[0]] < sz_out[dims_loop[0]];   pos_out[dims_loop[0]]++, pos_in[dims_loop[0]]++)
                        {
                            for(pos_in[dim_project] = 0; pos_in[dim_project] < sz_project; pos_in[dim_project]++)
                                v_project[pos_in[dim_project]] = static_cast<double>(pVD_In->pMA_full()->at<int>(pos_in));

                            switch (out_type) {
                            case CV_64FC1:  pVD_Out->pMA_full()->at<double>(pos_out) = F_project_64(v_project);                             break;
                            case CV_16UC1:  pVD_Out->pMA_full()->at<ushort>(pos_out) = static_cast<ushort>(F_project_64(v_project));        break;
                            case CV_8UC1:   pVD_Out->pMA_full()->at<uchar>(pos_out)  = F_project_8u(v_project);                             break;
                            default:                                                                                                        return ER_type_bad;}
                        }
        break;

    case CV_32FC1:
        for(                pos_out[dims_loop[4]] = 0, pos_in[dims_loop[4]] = 0;    pos_out[dims_loop[4]] < sz_out[dims_loop[4]];   pos_out[dims_loop[4]]++, pos_in[dims_loop[4]]++)
            for(            pos_out[dims_loop[3]] = 0, pos_in[dims_loop[3]] = 0;    pos_out[dims_loop[3]] < sz_out[dims_loop[3]];   pos_out[dims_loop[3]]++, pos_in[dims_loop[3]]++)
                for(        pos_out[dims_loop[2]] = 0, pos_in[dims_loop[2]] = 0;    pos_out[dims_loop[2]] < sz_out[dims_loop[2]];   pos_out[dims_loop[2]]++, pos_in[dims_loop[2]]++)
                    for(    pos_out[dims_loop[1]] = 0, pos_in[dims_loop[1]] = 0;    pos_out[dims_loop[1]] < sz_out[dims_loop[1]];   pos_out[dims_loop[1]]++, pos_in[dims_loop[1]]++)
                        for(pos_out[dims_loop[0]] = 0, pos_in[dims_loop[0]] = 0;    pos_out[dims_loop[0]] < sz_out[dims_loop[0]];   pos_out[dims_loop[0]]++, pos_in[dims_loop[0]]++)
                        {
                            for(pos_in[dim_project] = 0; pos_in[dim_project] < sz_project; pos_in[dim_project]++)
                                v_project[pos_in[dim_project]] = static_cast<double>(pVD_In->pMA_full()->at<float>(pos_in));

                            switch (out_type) {
                            case CV_64FC1:  pVD_Out->pMA_full()->at<double>(pos_out) = F_project_64(v_project);                             break;
                            case CV_16UC1:  pVD_Out->pMA_full()->at<ushort>(pos_out) = static_cast<ushort>(F_project_64(v_project));        break;
                            case CV_8UC1:   pVD_Out->pMA_full()->at<uchar>(pos_out)  = F_project_8u(v_project);                             break;
                            default:                                                                                                        return ER_type_bad;}
                        }
        break;

    case CV_64FC1:
        for(                pos_out[dims_loop[4]] = 0, pos_in[dims_loop[4]] = 0;    pos_out[dims_loop[4]] < sz_out[dims_loop[4]];   pos_out[dims_loop[4]]++, pos_in[dims_loop[4]]++)
            for(            pos_out[dims_loop[3]] = 0, pos_in[dims_loop[3]] = 0;    pos_out[dims_loop[3]] < sz_out[dims_loop[3]];   pos_out[dims_loop[3]]++, pos_in[dims_loop[3]]++)
                for(        pos_out[dims_loop[2]] = 0, pos_in[dims_loop[2]] = 0;    pos_out[dims_loop[2]] < sz_out[dims_loop[2]];   pos_out[dims_loop[2]]++, pos_in[dims_loop[2]]++)
                    for(    pos_out[dims_loop[1]] = 0, pos_in[dims_loop[1]] = 0;    pos_out[dims_loop[1]] < sz_out[dims_loop[1]];   pos_out[dims_loop[1]]++, pos_in[dims_loop[1]]++)
                        for(pos_out[dims_loop[0]] = 0, pos_in[dims_loop[0]] = 0;    pos_out[dims_loop[0]] < sz_out[dims_loop[0]];   pos_out[dims_loop[0]]++, pos_in[dims_loop[0]]++)
                        {
                            for(pos_in[dim_project] = 0; pos_in[dim_project] < sz_project; pos_in[dim_project]++)
                                v_project[pos_in[dim_project]] = static_cast<double>(pVD_In->pMA_full()->at<double>(pos_in));

                            switch (out_type) {
                            case CV_64FC1:  pVD_Out->pMA_full()->at<double>(pos_out) = F_project_64(v_project);                             break;
                            case CV_16UC1:  pVD_Out->pMA_full()->at<ushort>(pos_out) = static_cast<ushort>(F_project_64(v_project));        break;
                            case CV_8UC1:   pVD_Out->pMA_full()->at<uchar>(pos_out)  = F_project_8u(v_project);                             break;
                            default:                                                                                                        return ER_type_bad;}
                        }
        break;

    default:
        return ER_type_bad;
        break;
    }

    return ER_okay;
}



int D_VisDat_Proc::Dim_Deserialise(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int dim_from, int dim_to, int spacing)
{
    //errors
    if(pVD_In->pMA_full()->empty())                         return ER_empty;
    if(dim_from == dim_to)                                  return ER_dim_missmatch;
    if(pVD_In->pDim()->size_Dim(dim_to) != 1)               return ER_size_missmatch;
    if(spacing <= 0)                                        return ER_parameter_bad;
    if(pVD_In->pDim()->size_Dim(dim_from) % spacing != 0)   return ER_size_missmatch;
    if(pVD_In->pMA_full()->channels() != 1)                 return ER_channel_bad;

    //size change
    int dim_size_from_old = pVD_In->pDim()->size_Dim(dim_from);
    int dim_size_from_new = spacing;
    int dim_size_to_new   = dim_size_from_old / spacing;

    //dims normal - just loop them
    vector<int> dims_loop;
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(d != dim_from && d != dim_to)
            dims_loop.push_back(d);
    if(dims_loop.size() != c_DIM_NUMBER_OF - 2)
        return ER_dim_missmatch;//should never happen, but just to be safe it is checked again here

    //create output
    D_VisDat_Dim Dim_out = pVD_In->Dim();
    Dim_out.set_size_Dim(dim_from, dim_size_from_new);
    Dim_out.set_size_Dim(dim_to, dim_size_to_new);
    *pVD_Out = D_VisDat_Obj(
                Dim_out,
                pVD_In->type());

    //sizes
    vector<int> sz_out = Dim_out.size_DimsVec();

    //pos
    Vec<int, 6> pos_in      = {0, 0, 0, 0, 0, 0};
    Vec<int, 6> pos_out     = {0, 0, 0, 0, 0, 0};

    //project
    switch (pVD_In->type()) {

    case CV_8UC1:
        for(                pos_out[dims_loop[3]] = 0, pos_in[dims_loop[3]] = 0;    pos_out[dims_loop[3]] < sz_out[dims_loop[3]];   pos_out[dims_loop[3]]++, pos_in[dims_loop[3]]++)
            for(            pos_out[dims_loop[2]] = 0, pos_in[dims_loop[2]] = 0;    pos_out[dims_loop[2]] < sz_out[dims_loop[2]];   pos_out[dims_loop[2]]++, pos_in[dims_loop[2]]++)
                for(        pos_out[dims_loop[1]] = 0, pos_in[dims_loop[1]] = 0;    pos_out[dims_loop[1]] < sz_out[dims_loop[1]];   pos_out[dims_loop[1]]++, pos_in[dims_loop[1]]++)
                    for(    pos_out[dims_loop[0]] = 0, pos_in[dims_loop[0]] = 0;    pos_out[dims_loop[0]] < sz_out[dims_loop[0]];   pos_out[dims_loop[0]]++, pos_in[dims_loop[0]]++)
                    {
                        for(int i_from = 0; i_from < dim_size_from_old; i_from++)
                        {
                            //pos in dims in in/out
                            pos_in[dim_from]    = i_from;
                            pos_out[dim_from]   = i_from % spacing;
                            pos_out[dim_to]     = i_from / spacing;
                            //copy data
                            pVD_Out->pMA_full()->at<uchar>(pos_out) = pVD_In->pMA_full()->at<uchar>(pos_in);
                        }
                    }
        break;

    case CV_8SC1:
        for(                pos_out[dims_loop[3]] = 0, pos_in[dims_loop[3]] = 0;    pos_out[dims_loop[3]] < sz_out[dims_loop[3]];   pos_out[dims_loop[3]]++, pos_in[dims_loop[3]]++)
            for(            pos_out[dims_loop[2]] = 0, pos_in[dims_loop[2]] = 0;    pos_out[dims_loop[2]] < sz_out[dims_loop[2]];   pos_out[dims_loop[2]]++, pos_in[dims_loop[2]]++)
                for(        pos_out[dims_loop[1]] = 0, pos_in[dims_loop[1]] = 0;    pos_out[dims_loop[1]] < sz_out[dims_loop[1]];   pos_out[dims_loop[1]]++, pos_in[dims_loop[1]]++)
                    for(    pos_out[dims_loop[0]] = 0, pos_in[dims_loop[0]] = 0;    pos_out[dims_loop[0]] < sz_out[dims_loop[0]];   pos_out[dims_loop[0]]++, pos_in[dims_loop[0]]++)
                    {
                        for(int i_from = 0; i_from < dim_size_from_old; i_from++)
                        {
                            //pos in dims in in/out
                            pos_in[dim_from]    = i_from;
                            pos_out[dim_from]   = i_from % spacing;
                            pos_out[dim_to]     = i_from / spacing;
                            //copy data
                            pVD_Out->pMA_full()->at<char>(pos_out) = pVD_In->pMA_full()->at<char>(pos_in);
                        }
                    }
        break;

    case CV_16UC1:
        for(                pos_out[dims_loop[3]] = 0, pos_in[dims_loop[3]] = 0;    pos_out[dims_loop[3]] < sz_out[dims_loop[3]];   pos_out[dims_loop[3]]++, pos_in[dims_loop[3]]++)
            for(            pos_out[dims_loop[2]] = 0, pos_in[dims_loop[2]] = 0;    pos_out[dims_loop[2]] < sz_out[dims_loop[2]];   pos_out[dims_loop[2]]++, pos_in[dims_loop[2]]++)
                for(        pos_out[dims_loop[1]] = 0, pos_in[dims_loop[1]] = 0;    pos_out[dims_loop[1]] < sz_out[dims_loop[1]];   pos_out[dims_loop[1]]++, pos_in[dims_loop[1]]++)
                    for(    pos_out[dims_loop[0]] = 0, pos_in[dims_loop[0]] = 0;    pos_out[dims_loop[0]] < sz_out[dims_loop[0]];   pos_out[dims_loop[0]]++, pos_in[dims_loop[0]]++)
                    {
                        for(int i_from = 0; i_from < dim_size_from_old; i_from++)
                        {
                            //pos in dims in in/out
                            pos_in[dim_from]    = i_from;
                            pos_out[dim_from]   = i_from % spacing;
                            pos_out[dim_to]     = i_from / spacing;
                            //copy data
                            pVD_Out->pMA_full()->at<ushort>(pos_out) = pVD_In->pMA_full()->at<ushort>(pos_in);
                        }
                    }
        break;

    case CV_16SC1:
        for(                pos_out[dims_loop[3]] = 0, pos_in[dims_loop[3]] = 0;    pos_out[dims_loop[3]] < sz_out[dims_loop[3]];   pos_out[dims_loop[3]]++, pos_in[dims_loop[3]]++)
            for(            pos_out[dims_loop[2]] = 0, pos_in[dims_loop[2]] = 0;    pos_out[dims_loop[2]] < sz_out[dims_loop[2]];   pos_out[dims_loop[2]]++, pos_in[dims_loop[2]]++)
                for(        pos_out[dims_loop[1]] = 0, pos_in[dims_loop[1]] = 0;    pos_out[dims_loop[1]] < sz_out[dims_loop[1]];   pos_out[dims_loop[1]]++, pos_in[dims_loop[1]]++)
                    for(    pos_out[dims_loop[0]] = 0, pos_in[dims_loop[0]] = 0;    pos_out[dims_loop[0]] < sz_out[dims_loop[0]];   pos_out[dims_loop[0]]++, pos_in[dims_loop[0]]++)
                    {
                        for(int i_from = 0; i_from < dim_size_from_old; i_from++)
                        {
                            //pos in dims in in/out
                            pos_in[dim_from]    = i_from;
                            pos_out[dim_from]   = i_from % spacing;
                            pos_out[dim_to]     = i_from / spacing;
                            //copy data
                            pVD_Out->pMA_full()->at<short>(pos_out) = pVD_In->pMA_full()->at<short>(pos_in);
                        }
                    }
        break;

    case CV_32SC1:
        for(                pos_out[dims_loop[3]] = 0, pos_in[dims_loop[3]] = 0;    pos_out[dims_loop[3]] < sz_out[dims_loop[3]];   pos_out[dims_loop[3]]++, pos_in[dims_loop[3]]++)
            for(            pos_out[dims_loop[2]] = 0, pos_in[dims_loop[2]] = 0;    pos_out[dims_loop[2]] < sz_out[dims_loop[2]];   pos_out[dims_loop[2]]++, pos_in[dims_loop[2]]++)
                for(        pos_out[dims_loop[1]] = 0, pos_in[dims_loop[1]] = 0;    pos_out[dims_loop[1]] < sz_out[dims_loop[1]];   pos_out[dims_loop[1]]++, pos_in[dims_loop[1]]++)
                    for(    pos_out[dims_loop[0]] = 0, pos_in[dims_loop[0]] = 0;    pos_out[dims_loop[0]] < sz_out[dims_loop[0]];   pos_out[dims_loop[0]]++, pos_in[dims_loop[0]]++)
                    {
                        for(int i_from = 0; i_from < dim_size_from_old; i_from++)
                        {
                            //pos in dims in in/out
                            pos_in[dim_from]    = i_from;
                            pos_out[dim_from]   = i_from % spacing;
                            pos_out[dim_to]     = i_from / spacing;
                            //copy data
                            pVD_Out->pMA_full()->at<int>(pos_out) = pVD_In->pMA_full()->at<int>(pos_in);
                        }
                    }
        break;

    case CV_32FC1:
        for(                pos_out[dims_loop[3]] = 0, pos_in[dims_loop[3]] = 0;    pos_out[dims_loop[3]] < sz_out[dims_loop[3]];   pos_out[dims_loop[3]]++, pos_in[dims_loop[3]]++)
            for(            pos_out[dims_loop[2]] = 0, pos_in[dims_loop[2]] = 0;    pos_out[dims_loop[2]] < sz_out[dims_loop[2]];   pos_out[dims_loop[2]]++, pos_in[dims_loop[2]]++)
                for(        pos_out[dims_loop[1]] = 0, pos_in[dims_loop[1]] = 0;    pos_out[dims_loop[1]] < sz_out[dims_loop[1]];   pos_out[dims_loop[1]]++, pos_in[dims_loop[1]]++)
                    for(    pos_out[dims_loop[0]] = 0, pos_in[dims_loop[0]] = 0;    pos_out[dims_loop[0]] < sz_out[dims_loop[0]];   pos_out[dims_loop[0]]++, pos_in[dims_loop[0]]++)
                    {
                        for(int i_from = 0; i_from < dim_size_from_old; i_from++)
                        {
                            //pos in dims in in/out
                            pos_in[dim_from]    = i_from;
                            pos_out[dim_from]   = i_from % spacing;
                            pos_out[dim_to]     = i_from / spacing;
                            //copy data
                            pVD_Out->pMA_full()->at<float>(pos_out) = pVD_In->pMA_full()->at<float>(pos_in);
                        }
                    }
        break;

    case CV_64FC1:
        for(                pos_out[dims_loop[3]] = 0, pos_in[dims_loop[3]] = 0;    pos_out[dims_loop[3]] < sz_out[dims_loop[3]];   pos_out[dims_loop[3]]++, pos_in[dims_loop[3]]++)
            for(            pos_out[dims_loop[2]] = 0, pos_in[dims_loop[2]] = 0;    pos_out[dims_loop[2]] < sz_out[dims_loop[2]];   pos_out[dims_loop[2]]++, pos_in[dims_loop[2]]++)
                for(        pos_out[dims_loop[1]] = 0, pos_in[dims_loop[1]] = 0;    pos_out[dims_loop[1]] < sz_out[dims_loop[1]];   pos_out[dims_loop[1]]++, pos_in[dims_loop[1]]++)
                    for(    pos_out[dims_loop[0]] = 0, pos_in[dims_loop[0]] = 0;    pos_out[dims_loop[0]] < sz_out[dims_loop[0]];   pos_out[dims_loop[0]]++, pos_in[dims_loop[0]]++)
                    {
                        for(int i_from = 0; i_from < dim_size_from_old; i_from++)
                        {
                            //pos in dims in in/out
                            pos_in[dim_from]    = i_from;
                            pos_out[dim_from]   = i_from % spacing;
                            pos_out[dim_to]     = i_from / spacing;
                            //copy data
                            pVD_Out->pMA_full()->at<double>(pos_out) = pVD_In->pMA_full()->at<double>(pos_in);
                        }
                    }
        break;


    default:
        return ER_type_bad;
        break;
    }

    return ER_okay;
}

int D_VisDat_Proc::Dim_Pages2Color(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int p_red, int p_green, int p_blue)
{
    //errors
    if(pVD_In->pMA_full()->empty())         return ER_empty;
    if(pVD_In->pMA_full()->channels() != 1) return ER_channel_bad;
    if(p_red < 0)                           return ER_parameter_bad;
    if(p_green < 0)                         return ER_parameter_bad;
    if(p_blue < 0)                          return ER_parameter_bad;
    if(p_blue == p_red)                     return ER_parameter_bad;
    if(p_blue == p_green)                   return ER_parameter_bad;
    if(p_green == p_red)                    return ER_parameter_bad;

    //size pages
    int size_p_in = pVD_In->pDim()->size_P();

    //create output
    D_VisDat_Dim Dim_out = pVD_In->Dim();
    Dim_out.set_size_P(1);
    *pVD_Out = D_VisDat_Obj(
                Dim_out,
                D_Img_Proc::TypeIndex_of_Mat(
                    3,
                    pVD_In->pMA_full()->depth()));

    //buffer images
    Mat MA_tmp_Black = Mat::zeros(
                pVD_In->pDim()->size_Y(),
                pVD_In->pDim()->size_X(),
                pVD_In->type());
    Mat MA_tmp_R = MA_tmp_Black.clone();
    Mat MA_tmp_G = MA_tmp_Black.clone();
    Mat MA_tmp_B = MA_tmp_Black.clone();
    Mat MA_tmp_Color = Mat::zeros(
                pVD_In->pDim()->size_Y(),
                pVD_In->pDim()->size_X(),
                D_Img_Proc::TypeIndex_of_Mat(
                    3,
                    pVD_In->pMA_full()->depth()));

    //page to color merge function object (out/r/g/b)
    static function<int (Mat *, Mat *, Mat *, Mat *)> pages2color = D_Img_Proc_2dFactory::Channel_Merge();

    //sizes
    vector<int> sz_out = Dim_out.size_DimsVec();

    //loop dims
    for(int s = 0; s < sz_out[c_DIM_S]; s++)
        for(int t = 0; t < sz_out[c_DIM_T]; t++)
            for(int z = 0; z < sz_out[c_DIM_Z]; z++)
            {
                //get relevant page-slices
                if(p_red   < size_p_in)     Read_2D_Plane(&MA_tmp_R, pVD_In, D_VisDat_Slice_2D(-1, -1, z, t, s, p_red));
                if(p_green < size_p_in)     Read_2D_Plane(&MA_tmp_G, pVD_In, D_VisDat_Slice_2D(-1, -1, z, t, s, p_green));
                if(p_blue  < size_p_in)     Read_2D_Plane(&MA_tmp_B, pVD_In, D_VisDat_Slice_2D(-1, -1, z, t, s, p_blue));

                //convert pages to color
                pages2color(
                            &MA_tmp_Color,
                            &MA_tmp_R,
                            &MA_tmp_G,
                            &MA_tmp_B);

                //write page-merged colored slice
                Write_2D_Plane(
                            pVD_Out,
                            &MA_tmp_Color,
                            D_VisDat_Slice_2D(-1, -1, z, t, s, 0));
            }


    return ER_okay;
}

int D_VisDat_Proc::Stitch_Border_abs(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In_Main, D_VisDat_Obj *pVD_In_R, D_VisDat_Obj *pVD_In_B, D_VisDat_Obj *pVD_In_BR, int border_R, int border_B, int overlap_R, int overlap_B, Stitcher::Mode mode)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    //stitched size
    D_VisDat_Dim DimNew = pVD_In_Main->Dim();
    int proc_dim_0 = slice.ProcDim(0);
    int proc_dim_1 = slice.ProcDim(1);
    DimNew.set_size_Dim(proc_dim_0, pVD_In_Main->pDim()->size_Dim(proc_dim_0) + border_R);
    DimNew.set_size_Dim(proc_dim_1, pVD_In_Main->pDim()->size_Dim(proc_dim_1) + border_B);

    *pVD_Out = D_VisDat_Obj(
                DimNew,
                pVD_In_Main->type());
    qDebug() << "D_VisDat_Proc::Stitch_Border_abs" << "VD size(y/x):" << pVD_Out->info();

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Stitch_Border_abs(
                    border_R,
                    border_B,
                    overlap_R,
                    overlap_B,
                    mode),
                pVD_Out,
                pVD_In_Main,
                pVD_In_R,
                pVD_In_B,
                pVD_In_BR);
}

int D_VisDat_Proc::Stitch_Border_rel(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In_Main, D_VisDat_Obj *pVD_In_R, D_VisDat_Obj *pVD_In_B, D_VisDat_Obj *pVD_In_BR, double border_R, double border_B, double overlap_R, double overlap_B, Stitcher::Mode mode)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    //stitched size
    D_VisDat_Dim DimNew = pVD_In_Main->Dim();
    int proc_dim_0 = slice.ProcDim(0);
    int proc_dim_1 = slice.ProcDim(1);
    DimNew.set_size_Dim(proc_dim_0, static_cast<int>(pVD_In_Main->pDim()->size_Dim(proc_dim_0) * (1 + border_R)));
    DimNew.set_size_Dim(proc_dim_1, static_cast<int>(pVD_In_Main->pDim()->size_Dim(proc_dim_1) * (1 + border_B)));

    *pVD_Out = D_VisDat_Obj(
                DimNew,
                pVD_In_Main->type());
    qDebug() << "D_VisDat_Proc::Stitch_Border_rel" << "VD size(y/x):" << pVD_Out->info();

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Stitch_Border_rel(
                    border_R,
                    border_B,
                    overlap_R,
                    overlap_B,
                    mode),
                pVD_Out,
                pVD_In_Main,
                pVD_In_R,
                pVD_In_B,
                pVD_In_BR);
}

int D_VisDat_Proc::Stitch_Border_abs_custom(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In_Main, D_VisDat_Obj *pVD_In_R, D_VisDat_Obj *pVD_In_B, D_VisDat_Obj *pVD_In_BR, int border_R, int border_B, int overlap_R, int overlap_B)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    //stitched size
    D_VisDat_Dim DimNew = pVD_In_Main->Dim();
    int proc_dim_0 = slice.ProcDim(0);
    int proc_dim_1 = slice.ProcDim(1);
    DimNew.set_size_Dim(proc_dim_0, pVD_In_Main->pDim()->size_Dim(proc_dim_0) + border_R);
    DimNew.set_size_Dim(proc_dim_1, pVD_In_Main->pDim()->size_Dim(proc_dim_1) + border_B);

    *pVD_Out = D_VisDat_Obj(
                DimNew,
                pVD_In_Main->type());
    qDebug() << "D_VisDat_Proc::Stitch_Border_abs_custom" << "VD size(y/x):" << pVD_Out->info();

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Stitch_Border_abs_custom(
                    border_R,
                    border_B,
                    overlap_R,
                    overlap_B),
                pVD_Out,
                pVD_In_Main,
                pVD_In_R,
                pVD_In_B,
                pVD_In_BR);
}

int D_VisDat_Proc::Stitch_Border_rel_custom(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In_Main, D_VisDat_Obj *pVD_In_R, D_VisDat_Obj *pVD_In_B, D_VisDat_Obj *pVD_In_BR, double border_R, double border_B, double overlap_R, double overlap_B)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    //stitched size
    D_VisDat_Dim DimNew = pVD_In_Main->Dim();
    int proc_dim_0 = slice.ProcDim(0);
    int proc_dim_1 = slice.ProcDim(1);
    DimNew.set_size_Dim(proc_dim_0, static_cast<int>(pVD_In_Main->pDim()->size_Dim(proc_dim_0) * (1 + border_R)));
    DimNew.set_size_Dim(proc_dim_1, static_cast<int>(pVD_In_Main->pDim()->size_Dim(proc_dim_1) * (1 + border_B)));

    *pVD_Out = D_VisDat_Obj(
                DimNew,
                pVD_In_Main->type());
    //qDebug() << "D_VisDat_Proc::Stitch_Border_rel_custom" << "VD size(y/x):" << pVD_Out->info();

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Stitch_Border_rel_custom(
                    border_R,
                    border_B,
                    overlap_R,
                    overlap_B),
                pVD_Out,
                pVD_In_Main,
                pVD_In_R,
                pVD_In_B,
                pVD_In_BR);
}

/*
int D_VisDat_Proc::Dim_Stitching(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int dim_source, Stitcher::Mode mode, bool divide_images)
{
    if(slice.is_proc_Dim(dim_source))       return ER_SpecialDimPartOfProcPlane;
    if(pVD_In->pMA_full()->empty())         return ER_empty;
    if(!slice.is_2D())                      return ER_dim_2D_only;

    //find roles of dims
    vector<int> vDim_Independent;
    vector<int> vDim_Mosaik;
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
    {
        if(slice.is_proc_Dim(d))
            vDim_Mosaik.push_back(d);
        else if(d != dim_source)
            vDim_Independent.push_back(d);
    }


    Mat pano;
    Ptr<Stitcher> stitcher = Stitcher::create(mode);
    Stitcher::Status status = stitcher->stitch(imgs, pano);
    if (status != Stitcher::OK)
    {
        cout << "Can't stitch images, error code = " << int(status) << endl;
        return EXIT_FAILURE;
    }

    return ER_okay;
}
*/


int D_VisDat_Proc::Crop_Rect_Rel(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double x1_rel, double y1_rel, double x2_rel, double y2_rel)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    //croped size
    D_VisDat_Dim DimNew = pVD_In->Dim();
    int proc_dim_0 = slice.ProcDim(0);
    int proc_dim_1 = slice.ProcDim(1);
    int size_old_0 = pVD_In->Dim().size_Dim(proc_dim_0);
    int size_old_1 = pVD_In->Dim().size_Dim(proc_dim_1);
    int size_new_0 = size_old_0 * (x2_rel - x1_rel);
    int size_new_1 = size_old_1 * (y2_rel - y1_rel);
    DimNew.set_size_Dim(proc_dim_0, size_new_0);
    DimNew.set_size_Dim(proc_dim_1, size_new_1);

    *pVD_Out = D_VisDat_Obj(
                DimNew,
                pVD_In->type());

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Crop_Rect_Rel(
                    x1_rel,
                    y1_rel,
                    x2_rel,
                    y2_rel),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Crop_Rect_Abs(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int x, int y, int width, int height)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    //croped size
    D_VisDat_Dim DimNew = pVD_In->Dim();
    int proc_dim_0 = slice.ProcDim(0);
    int proc_dim_1 = slice.ProcDim(1);
    DimNew.set_size_Dim(proc_dim_0, width);
    DimNew.set_size_Dim(proc_dim_1, height);

    *pVD_Out = D_VisDat_Obj(
                DimNew,
                pVD_In->type());

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Crop_Rect_Abs(
                    x,
                    y,
                    width,
                    height),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Crop_Rect_Rot(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int x, int y, int width, int height, double angle)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    //croped size
    D_VisDat_Dim DimNew = pVD_In->Dim();
    int proc_dim_0 = slice.ProcDim(0);
    int proc_dim_1 = slice.ProcDim(1);
    DimNew.set_size_Dim(proc_dim_0, width);
    DimNew.set_size_Dim(proc_dim_1, height);

    *pVD_Out = D_VisDat_Obj(
                DimNew,
                pVD_In->type());

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Crop_Rect_Rot(
                    x,
                    y,
                    width,
                    height,
                    angle),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Crop_Circle(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int x, int y, int r)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    //croped size
    D_VisDat_Dim DimNew = pVD_In->Dim();
    int proc_dim_0 = slice.ProcDim(0);
    int proc_dim_1 = slice.ProcDim(1);
    DimNew.set_size_Dim(proc_dim_0, 2 * r + 1);
    DimNew.set_size_Dim(proc_dim_1, 2 * r + 1);

    *pVD_Out = D_VisDat_Obj(
                DimNew,
                pVD_In->type());

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Crop_Circle(
                    x,
                    y,
                    r),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Pad_Border(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_x, int size_y, int size_z, int type, double border_value)
{
    if(!slice.is_2D() && !slice.is_3D())
        return ER_dim_missmatch;

    D_VisDat_Dim DimNew = pVD_In->Dim();
    int proc_dim_0 = slice.ProcDim(0);
    int proc_dim_1 = slice.ProcDim(1);
    int size_old_0 = pVD_In->Dim().size_Dim(proc_dim_0);
    int size_old_1 = pVD_In->Dim().size_Dim(proc_dim_1);
    int size_new_0 = size_old_0 + 2 * size_x;
    int size_new_1 = size_old_1 + 2 * size_y;
    DimNew.set_size_Dim(proc_dim_0, size_new_0);
    DimNew.set_size_Dim(proc_dim_1, size_new_1);

    if(slice.is_3D())
    {
        int proc_dim_2 = slice.ProcDim(2);
        int size_old_2 = pVD_In->Dim().size_Dim(proc_dim_2);
        int size_new_2 = size_old_2 + 2 * size_z;
        DimNew.set_size_Dim(proc_dim_2, size_new_2);
    }

    *pVD_Out = D_VisDat_Obj(
                DimNew,
                pVD_In->type());

    if(slice.is_2D())
    {
        return Wrap_VD(
                    slice,
                    D_Img_Proc_2dFactory::Pad_Border(
                        size_x,
                        size_y,
                        type),
                    pVD_Out,
                    pVD_In);
    }
    else if(slice.is_3D())
    {
        return Wrap_VD(
                    slice,
                    D_Img_Proc_3dFactory::Pad_Border(
                        size_x,
                        size_y,
                        size_z,
                        type,
                        border_value),
                    pVD_Out,
                    pVD_In);
    }

    return ER_dim_missmatch;
}

int D_VisDat_Proc::ForceSize(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int width, int heigth, int border_type)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    //forced size
    D_VisDat_Dim DimNew = pVD_In->Dim();
    DimNew.set_size_Dim(slice.ProcDim(0), width);
    DimNew.set_size_Dim(slice.ProcDim(1), heigth);

    *pVD_Out = D_VisDat_Obj(
                DimNew,
                pVD_In->type());

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::ForceSize(
                    width,
                    heigth,
                    border_type),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Floodfill_Border(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double new_val)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    return Wrap_VD_SameSizeType(
                slice,
                D_Img_Proc_2dFactory::Floodfill_Border(
                    new_val),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Floodfill_Delta(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int seed_x, int seed_y, uchar val_new, uchar val_delta)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    return Wrap_VD_SameSizeType(
                slice,
                D_Img_Proc_2dFactory::Floodfill_Delta(
                    seed_x,
                    seed_y,
                    val_new,
                    val_delta),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Scale_Factor(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double scale_dim_0, double scale_dim_1)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    //croped size
    D_VisDat_Dim DimNew = pVD_In->Dim();
    int proc_dim_0 = slice.ProcDim(0);
    int proc_dim_1 = slice.ProcDim(1);
    DimNew.set_size_Dim(proc_dim_0, static_cast<int>(pVD_In->Dim().size_Dim(proc_dim_0) * scale_dim_0));
    DimNew.set_size_Dim(proc_dim_1, static_cast<int>(pVD_In->Dim().size_Dim(proc_dim_1) * scale_dim_1));

    *pVD_Out = D_VisDat_Obj(
                DimNew,
                pVD_In->type());

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Scale_Factor(
                    scale_dim_0,
                    scale_dim_1),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Scale_ToSize(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_dim_0, int size_dim_1)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    //croped size
    D_VisDat_Dim DimNew = pVD_In->Dim();
    int proc_dim_0 = slice.ProcDim(0);
    int proc_dim_1 = slice.ProcDim(1);
    DimNew.set_size_Dim(proc_dim_0, size_dim_0);
    DimNew.set_size_Dim(proc_dim_1, size_dim_1);

    *pVD_Out = D_VisDat_Obj(
                DimNew,
                pVD_In->type());

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Scale_ToSize(
                    size_dim_0,
                    size_dim_1),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Convert_Color(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int cvt_mode)
{
    //output channels
    int ch_out = 3;
    if(cvt_mode == CV_BGR2GRAY || cvt_mode == CV_RGB2GRAY)
        ch_out = 1;

    //create output VD
    if(ch_out == 1 && pVD_In->pMA_full()->depth() == CV_8U)
        *pVD_Out = D_VisDat_Obj(pVD_In->Dim(), CV_8UC1);
    else if(ch_out == 1 && pVD_In->pMA_full()->depth() == CV_16U)
        *pVD_Out = D_VisDat_Obj(pVD_In->Dim(), CV_16UC1);
    else if(ch_out == 1 && pVD_In->pMA_full()->depth() == CV_32F)
        *pVD_Out = D_VisDat_Obj(pVD_In->Dim(), CV_32FC1);
    else
        *pVD_Out = D_VisDat_Obj(pVD_In->Dim(), pVD_In->MA_Type);

    //proc
    return Wrap_VD(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Convert_Color(
                    cvt_mode),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Convert_Color2Mono(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int col2mono_code)
{
    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                CV_8UC1);

    return Wrap_VD(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Convert_Color2Mono(
                    col2mono_code),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Normalize(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int norm, int type, double min, double max)
{
    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    pVD_In->pMA_full()->channels(),
                    type));

    return Wrap_VD(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Normalize(
                    norm,
                    type,
                    min,
                    max),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Convert_Double(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In)
{
    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    pVD_In->pMA_full()->channels(),
                    CV_64F));

    return Wrap_VD(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Convert_Double(),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Channels_Merge(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3, int channels_count, bool channels_use[])
{
    *pVD_Out = D_VisDat_Obj(
                pVD_In0->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    channels_count,
                    pVD_In0->pMA_full()->depth()));

    return Wrap_VD(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Channel_Merge(
                    channels_count,
                    channels_use),
                pVD_Out,
                pVD_In0,
                pVD_In1,
                pVD_In2,
                pVD_In3);
}

int D_VisDat_Proc::Channels_Merge(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2)
{
    *pVD_Out = D_VisDat_Obj(
                pVD_In0->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    3,
                    pVD_In0->pMA_full()->depth()));

    return Wrap_VD(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Channel_Merge(),
                pVD_Out,
                pVD_In0,
                pVD_In1,
                pVD_In2);
}

int D_VisDat_Proc::Channels_Split(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int channel)
{
    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    1,
                    pVD_In->pMA_full()->depth()));

    return Wrap_VD(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Channel_Split(
                    channel),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Convert_8UC1_binary(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In)
{
    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    1,
                    pVD_In->pMA_full()->depth()));

    return Wrap_VD(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Convert_8UC1_binary(),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Visualize_to8bit(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int mode_crop, int mode_trafo, int mode_anchor, int mode_range, double val_anchor, double val_range, double val_min, double val_max, double val_gamma, double val_center, double val_scale, bool keep_min_max)
{
    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    pVD_In->pMA_full()->channels(),
                    CV_8U));

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Visualize_to8bit(
                    mode_crop,
                    mode_trafo,
                    mode_anchor,
                    mode_range,
                    val_anchor,
                    val_range,
                    val_min,
                    val_max,
                    val_gamma,
                    val_center,
                    val_scale,
                    keep_min_max),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Convert_Angle2Color_Rad(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_InAngleRad, uchar Saturation, uchar Value)
{
    *pVD_Out = D_VisDat_Obj(
                pVD_InAngleRad->Dim(),
                CV_8UC3);

    return Wrap_VD(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Convert_Angle2Color_Rad(
                    Saturation,
                    Value),
                pVD_Out,
                pVD_InAngleRad);
}

int D_VisDat_Proc::Threshold_Auto(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int mode, int max, int auto_type)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Threshold_Auto(
                    mode,
                    max,
                    auto_type),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Threshold_Auto_Otsu(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int mode, int max)
{
    return Threshold_Auto(
                pVD_Out,
                pVD_In,
                mode,
                max,
                CV_THRESH_OTSU);
}

int D_VisDat_Proc::Threshold_Absolute_8U(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int mode, int max, int thresh)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Threshold_Value(
                    mode,
                    max,
                    thresh),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Threshold_Absolute(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double thresh)
{
    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    pVD_In->pMA_full()->channels(),
                    CV_8U));

    return Wrap_VD(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Threshold_Absolute(
                    thresh),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Threshold_Relative_8U(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double thresh_rel)
{
    return Threshold_Relative(
                pVD_Out,
                pVD_In,
                255,
                thresh_rel);
}

int D_VisDat_Proc::Threshold_Relative(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double base, double thresh_rel)
{
    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    pVD_In->pMA_full()->channels(),
                    CV_8U));

    return Wrap_VD(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Threshold_Realtive(
                    base,
                    thresh_rel),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Threshold_Adaptive(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int mode, int max, int mask_type, int mask_size, double offset)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Threshold_Adaptive(
                    mode,
                    max,
                    mask_type,
                    mask_size,
                    offset),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Threshold_Adaptive_Gauss(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size, double sigma, double offset)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    pVD_In->pMA_full()->channels(),
                    CV_8U));

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Threshold_Adaptive_Gauss(
                    size,
                    sigma,
                    offset),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Color_Grab(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int color_space, int out_mode, vector<uchar> min, vector<uchar> max)
{
    int out_type = CV_8UC1;
    if(out_mode == 1)
        out_type = CV_8UC3;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                out_type);

    return Wrap_VD(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Grab_Color(
                    color_space,
                    out_mode,
                    min,
                    max),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Labeling(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int connecivity, int out_depth)
{
    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    1,
                    out_depth));

    return Wrap_VD(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Labeling(
                    connecivity,
                    out_depth),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Fill_Holes(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Fill_Holes(),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Shading_Correct(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Ref)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Shading_Correct(),
                pVD_Out,
                pVD_In,
                pVD_Ref);
}

int D_VisDat_Proc::Filter_Mean(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_x, int size_y, int border, int out_depth, bool norm)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    return Wrap_VD_SameSizeType(
                slice,
                D_Img_Proc_2dFactory::Filter_Mean(
                    size_x,
                    size_y,
                    border,
                    out_depth,
                    norm),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Filter_RootMeanSquare(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_x, int size_y, int border, int out_depth, bool norm)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    pVD_In->pMA_full()->channels(),
                    CV_32F));

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Filter_RootMeanSquare(
                    size_x,
                    size_y,
                    border,
                    out_depth,
                    norm),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Filter_Gauss(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_x, int size_y, int border, double sigma_x, double sigma_y)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    return Wrap_VD_SameSizeType(
                slice,
                D_Img_Proc_2dFactory::Filter_Gauss(
                    size_x,
                    size_y,
                    border,
                    sigma_x,
                    sigma_y),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Filter_Median(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_x3d_or_xy2d, int size_y, int size_z)
{
    if(slice.is_2D())
    {
        return Wrap_VD_SameSizeType(
                    slice,
                    D_Img_Proc_2dFactory::Filter_Median(
                        size_x3d_or_xy2d),
                    pVD_Out,
                    pVD_In);
    }
    else if(slice.is_3D())
    {
        if(pVD_In->pMA_full()->depth() == CV_8U)
            *pVD_Out = D_VisDat_Obj(
                        pVD_In->Dim(),
                        D_Img_Proc::TypeIndex_of_Mat(
                            pVD_In->pMA_full()->channels(),
                            CV_8U));
        else
            *pVD_Out = D_VisDat_Obj(
                        pVD_In->Dim(),
                        D_Img_Proc::TypeIndex_of_Mat(
                            pVD_In->pMA_full()->channels(),
                            CV_64F));

        return Wrap_VD(
                    slice,
                    D_Img_Proc_3dFactory::Filter_Median(
                        size_x3d_or_xy2d,
                        size_y,
                        size_z),
                    pVD_Out,
                    pVD_In);
    }
    else
    {
        return ER_dim_missmatch;
    }


    if(!slice.is_2D())
        return ER_dim_2D_only;


}

int D_VisDat_Proc::Filter_RankOrder(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Mask, double quantil)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    return Wrap_VD_SameSizeType(
                slice,
                D_Img_Proc_2dFactory::Filter_RankOrder(
                    quantil),
                pVD_Out,
                pVD_In,
                pVD_Mask);
}

int D_VisDat_Proc::Filter_RankOrder_Circular(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double quantil, double radius)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    return Wrap_VD_SameSizeType(
                slice,
                D_Img_Proc_2dFactory::Filter_RankOrder_Circular(
                    quantil,
                    radius),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Filter_RankOrder_Rect(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double quantil, int size_x, int size_y)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    return Wrap_VD_SameSizeType(
                slice,
                D_Img_Proc_2dFactory::Filter_RankOrder_Rect(
                    quantil,
                    size_x,
                    size_y),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Filter_Median(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Mask)
{
    return Filter_RankOrder(
                slice,
                pVD_Out,
                pVD_In,
                pVD_Mask,
                0.5);
}

int D_VisDat_Proc::Filter_Median_Circular(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double radius)
{
    return Filter_RankOrder_Circular(
                slice,
                pVD_Out,
                pVD_In,
                0.5,
                radius);
}

int D_VisDat_Proc::Filter_Median_Rect(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_x, int size_y)
{
    return Filter_RankOrder_Rect(
                slice,
                pVD_Out,
                pVD_In,
                0.5,
                size_x,
                size_y);
}

int D_VisDat_Proc::Filter_Laplace(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size, int border, int out_depth, double scale, double delta)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    return Wrap_VD_SameSizeType(
                slice,
                D_Img_Proc_2dFactory::Filter_Laplace(
                    size,
                    border,
                    out_depth,
                    scale,
                    delta),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Filter_Sobel(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size, int border, int out_depth, double scale, double delta, int d_x, int d_y)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    return Wrap_VD_SameSizeType(
                slice,
                D_Img_Proc_2dFactory::Filter_Sobel(
                    size,
                    border,
                    out_depth,
                    scale,
                    delta,
                    d_x,
                    d_y),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Filter_Canny(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size, double thres_low, double thres_high, bool L2_gradient)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                CV_8UC1);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Filter_Canny(
                    size,
                    thres_low,
                    thres_high,
                    L2_gradient),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Filter_Bilateral(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int diameter, int border, double sigma_color, double sigma_space)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    return Wrap_VD_SameSizeType(
                slice,
                D_Img_Proc_2dFactory::Filter_Bilateral(
                    diameter,
                    border,
                    sigma_color,
                    sigma_space),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Filter_Gabor(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_x, int size_y, int border, int out_depth, double sigma, double theta, double lambda, double gamma, double psi, double delta)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    pVD_In->pMA_full()->channels(),
                    out_depth));

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Filter_Gabor(
                    size_x,
                    size_y,
                    border,
                    out_depth,
                    sigma,
                    theta,
                    lambda,
                    gamma,
                    psi,
                    delta),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Filter_Eilenstein(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int comp, int size_x, int size_y, bool normalized, double constant)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    pVD_In->pMA_full()->channels(),
                    CV_8U));

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Filter_Eilenstein(
                    comp,
                    size_x,
                    size_y,
                    normalized,
                    constant),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Filter_Eilenstein(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Mask, function<double (double, double)> response_CurNei, function<double (double, double)> weight_ResWeigth, function<double (vector<double>)> combine_Responses)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    pVD_In->pMA_full()->channels(),
                    CV_64F));

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Filter_Eilenstein(
                    response_CurNei,
                    weight_ResWeigth,
                    combine_Responses),
                pVD_Out,
                pVD_In,
                pVD_Mask);
}

int D_VisDat_Proc::Filter_Eilenstein_Greater_Sum(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_x, int size_y, int size_z)
{
    if(!slice.is_3D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    pVD_In->pMA_full()->channels(),
                    CV_64F));

    return Wrap_VD(
                slice,
                D_Img_Proc_3dFactory::Filter_Eilenstein_Greater_Sum(
                    size_x,
                    size_y,
                    size_z),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Filter_Function(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Mask, function<double (double, double)> F1_CenterImage, function<double (double, double)> F2_f1mask, function<double (vector<double>)> F3_Combine, function<double (double, double)> F4_f3center, int border_type, bool DoNonZeroMaskOnly)
{
    if(!slice.is_2D() && !slice.is_3D())
        return ER_dim_missmatch;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    pVD_In->pMA_full()->channels(),
                    CV_64F));

    if(slice.is_2D())
    {
        //qDebug() << "Filter_Function 2D";
        return Wrap_VD(
                    slice,
                    D_Img_Proc_2dFactory::Filter_Function(
                        F1_CenterImage,
                        F2_f1mask,
                        F3_Combine,
                        F4_f3center,
                        border_type,
                        DoNonZeroMaskOnly),
                    pVD_Out,
                    pVD_In,
                    pVD_Mask);
    }

    if(slice.is_3D())
    {
        //qDebug() << "Filter_Function 3D";
        return Wrap_VD(
                    slice,
                    D_Img_Proc_3dFactory::Filter_Function(
                        F1_CenterImage,
                        F2_f1mask,
                        F3_Combine,
                        F4_f3center,
                        border_type,
                        DoNonZeroMaskOnly),
                    pVD_Out,
                    pVD_In,
                    pVD_Mask);
    }

    return ER_dim_missmatch;
}

int D_VisDat_Proc::Filter_Function_8bit(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Mask, function<uchar (double, double)> F1_CenterImage, function<uchar (double, double)> F2_f1mask, function<uchar (vector<double>)> F3_Combine, function<uchar (double, double)> F4_f3center, int border_type, bool DoNonZeroMaskOnly)
{
    if(!slice.is_2D() && !slice.is_3D())
        return ER_dim_missmatch;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    pVD_In->pMA_full()->channels(),
                    CV_8U));

    if(slice.is_2D())
    {
        return Wrap_VD(
                    slice,
                    D_Img_Proc_2dFactory::Filter_Function_8bit(
                        F1_CenterImage,
                        F2_f1mask,
                        F3_Combine,
                        F4_f3center,
                        border_type,
                        DoNonZeroMaskOnly),
                    pVD_Out,
                    pVD_In,
                    pVD_Mask);
    }

    if(slice.is_3D())
    {
        return Wrap_VD(
                    slice,
                    D_Img_Proc_3dFactory::Filter_Function_8bit(
                        F1_CenterImage,
                        F2_f1mask,
                        F3_Combine,
                        F4_f3center,
                        border_type,
                        DoNonZeroMaskOnly),
                    pVD_Out,
                    pVD_In,
                    pVD_Mask);
    }

    return ER_dim_missmatch;
}

int D_VisDat_Proc::Filter_Stat(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Mask, int stat, int border_type)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    pVD_In->pMA_full()->channels(),
                    CV_64F));

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Filter_Stat(
                    stat,
                    border_type),
                pVD_Out,
                pVD_In,
                pVD_Mask);
}

int D_VisDat_Proc::Filter_Stat_Circular(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double radius, int stat, int border_type)
{
    if(!slice.is_2D())
            return ER_dim_2D_only;

        *pVD_Out = D_VisDat_Obj(
                    pVD_In->Dim(),
                    D_Img_Proc::TypeIndex_of_Mat(
                        pVD_In->pMA_full()->channels(),
                        CV_64F));

        return Wrap_VD(
                    slice,
                    D_Img_Proc_2dFactory::Filter_Stat_Circular(
                        radius,
                        stat,
                        border_type),
                    pVD_Out,
                    pVD_In);
}

int D_VisDat_Proc::Filter_Stat_Rect(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_x, int size_y, int stat, int border_type)
{
    if(!slice.is_2D())
            return ER_dim_2D_only;

        *pVD_Out = D_VisDat_Obj(
                    pVD_In->Dim(),
                    D_Img_Proc::TypeIndex_of_Mat(
                        pVD_In->pMA_full()->channels(),
                        CV_64F));

        return Wrap_VD(
                    slice,
                    D_Img_Proc_2dFactory::Filter_Stat_Rect(
                        stat,
                        size_x,
                        size_y,
                        border_type),
                    pVD_Out,
                    pVD_In);
}

int D_VisDat_Proc::Morphology_Elemental(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int morph_type, int elem_type, int elem_size_X, int elem_size_Y, int border_type, int iterations)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    return Wrap_VD_SameSizeType(
                slice,
                D_Img_Proc_2dFactory::Morphology_Elemental(
                    morph_type,
                    elem_type,
                    elem_size_X,
                    elem_size_Y,
                    border_type,
                    iterations),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Morphology_Skeleton(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int elem_type, int elem_size_X, int elem_size_Y, int border_type)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    return Wrap_VD_SameSizeType(
                slice,
                D_Img_Proc_2dFactory::Morphology_Skeleton(
                    elem_type,
                    elem_size_X,
                    elem_size_Y,
                    border_type),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Morphology_Dilation(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int elem_size_X, int elem_size_Y, int elem_size_Z)
{
    if(!slice.is_3D())
        return ER_dim_3D_only;

    if(pVD_In->pMA_full()->depth() == CV_8U)
        *pVD_Out = D_VisDat_Obj(
                    pVD_In->Dim(),
                    D_Img_Proc::TypeIndex_of_Mat(
                        pVD_In->pMA_full()->channels(),
                        CV_8U));
    else
        *pVD_Out = D_VisDat_Obj(
                    pVD_In->Dim(),
                    D_Img_Proc::TypeIndex_of_Mat(
                        pVD_In->pMA_full()->channels(),
                        CV_64F));

    return Wrap_VD(
                slice,
                D_Img_Proc_3dFactory::Morphology_Dilation(
                    elem_size_X,
                    elem_size_Y,
                    elem_size_Z),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Morphology_Erosion(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int elem_size_X, int elem_size_Y, int elem_size_Z)
{
    if(!slice.is_3D())
        return ER_dim_3D_only;

    if(pVD_In->pMA_full()->depth() == CV_8U)
        *pVD_Out = D_VisDat_Obj(
                    pVD_In->Dim(),
                    D_Img_Proc::TypeIndex_of_Mat(
                        pVD_In->pMA_full()->channels(),
                        CV_8U));
    else
        *pVD_Out = D_VisDat_Obj(
                    pVD_In->Dim(),
                    D_Img_Proc::TypeIndex_of_Mat(
                        pVD_In->pMA_full()->channels(),
                        CV_64F));

    return Wrap_VD(
                slice,
                D_Img_Proc_3dFactory::Morphology_Erosion(
                    elem_size_X,
                    elem_size_Y,
                    elem_size_Z),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Morphology_LocMax_Rect(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int elem_size_X, int elem_size_Y)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    pVD_In->pMA_full()->channels(),
                    CV_8U));

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Morphology_LocMax_Rect(
                    elem_size_X,
                    elem_size_Y),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Math_1img_Inversion(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_1img_Inversion(),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Math_1img_Addition(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double summmand)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_1img_Addition(
                    summmand),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Math_1img_Subtraction(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double subtrahend)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_1img_Subtraction(
                    subtrahend),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Math_1img_Multiplication(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double factor)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_1img_Multiplication(
                    factor),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Math_1img_Division(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double divisor)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_1img_Division(
                    divisor),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Math_1img_Power(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double power)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_1img_Power(
                    power),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Math_1img_Root(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_1img_Root(),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Math_1img_Log(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_1img_Log(),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Math_2img_Addition(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_2img_Addition(),
                pVD_Out,
                pVD_In0,
                pVD_In1);
}

int D_VisDat_Proc::Math_2img_AdditionWeighted(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, double weight_1, double weight_2, double weight_sum)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_2img_AdditionWeighted(
                    weight_1,
                    weight_2,
                    weight_sum),
                pVD_Out,
                pVD_In0,
                pVD_In1);
}

int D_VisDat_Proc::Math_2img_Subtraction(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_2img_Subtraction(),
                pVD_Out,
                pVD_In0,
                pVD_In1);
}

int D_VisDat_Proc::Math_2img_SubtractionAbsolute(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_2img_SubtractionAbsolute(),
                pVD_Out,
                pVD_In0,
                pVD_In1);
}

int D_VisDat_Proc::Math_2img_Multiplication(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, double scale)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_2img_Multiplication(
                    scale),
                pVD_Out,
                pVD_In0,
                pVD_In1);
}

int D_VisDat_Proc::Math_2img_Division(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, double scale)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_2img_Division(
                    scale),
                pVD_Out,
                pVD_In0,
                pVD_In1);
}

int D_VisDat_Proc::Math_2img_BitwiseAnd(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_2img_BitwiseAnd(),
                pVD_Out,
                pVD_In0,
                pVD_In1);
}

int D_VisDat_Proc::Math_2img_BitwiseOr(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_2img_BitwiseOr(),
                pVD_Out,
                pVD_In0,
                pVD_In1);
}

int D_VisDat_Proc::Math_2img_BitwiseXor(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_2img_BitwiseXor(),
                pVD_Out,
                pVD_In0,
                pVD_In1);
}

int D_VisDat_Proc::Math_2img_Minimum(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_2img_Minimum(),
                pVD_Out,
                pVD_In0,
                pVD_In1);
}

int D_VisDat_Proc::Math_2img_Maximum(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_2img_Maximum(),
                pVD_Out,
                pVD_In0,
                pVD_In1);
}

int D_VisDat_Proc::Math_2img_Compare(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, int comp)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_2img_Compare(
                    comp),
                pVD_Out,
                pVD_In0,
                pVD_In1);
}

int D_VisDat_Proc::Math_2img_Function(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, function<double (double, double)> function_img1_img2)
{
    if(pVD_In0->Dim().isEqual(pVD_In1->Dim()))
    {
        *pVD_Out = D_VisDat_Obj(
                    pVD_In0->Dim(),
                    CV_64FC1);

        return Wrap_VD(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    D_Img_Proc_2dFactory::Math_2img_Function(
                        function_img1_img2),
                    pVD_Out,
                    pVD_In0,
                    pVD_In1);
    }
    else
        return Math_2img_Function_UnequalSize(
                    pVD_Out,
                    pVD_In0,
                    pVD_In1,
                    function_img1_img2);
}

int D_VisDat_Proc::Math_2img_Function_Complex(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, function<complex<double> (complex<double>, complex<double>)> function_img1_img2)
{
    if(pVD_In0->Dim().isEqual(pVD_In1->Dim()))
    {
        *pVD_Out = D_VisDat_Obj(
                    pVD_In0->Dim(),
                    CV_64FC2);

        return Wrap_VD(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    D_Img_Proc_2dFactory::Math_2img_Function_Complex(
                        function_img1_img2),
                    pVD_Out,
                    pVD_In0,
                    pVD_In1);
    }
    else
        return ER_size_missmatch;
}

int D_VisDat_Proc::Math_2img_Function_8bit(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, function<uchar (double, double)> function_img1_img2)
{
    if(pVD_In0->Dim().isEqual(pVD_In1->Dim()))
    {
        *pVD_Out = D_VisDat_Obj(
                    pVD_In0->Dim(),
                    CV_8UC1);

        return Wrap_VD(
                    D_VisDat_Slicing(c_SLICE_2D_XY),
                    D_Img_Proc_2dFactory::Math_2img_Function_8bit(
                        function_img1_img2),
                    pVD_Out,
                    pVD_In0,
                    pVD_In1);
    }
    else
        return Math_2img_Function_UnequalSize_8bit(
                    pVD_Out,
                    pVD_In0,
                    pVD_In1,
                    function_img1_img2);
}

int D_VisDat_Proc::Math_2img_Function_UnequalSize(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, function<double (double, double)> function_img1_img2)
{
    //errors
    if(pVD_In0->pMA_full()->type() != pVD_In1->pMA_full()->type())      return ER_type_missmatch;
    if(pVD_In0->pMA_full()->channels() != 1)                            return ER_channel_bad;
    if(pVD_In1->pMA_full()->channels() != 1)                            return ER_channel_bad;

    //loop dims
    vector<int> sz_in0(c_DIM_NUMBER_OF);
    vector<int> sz_in1(c_DIM_NUMBER_OF);
    vector<int> sz_out(c_DIM_NUMBER_OF);
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
    {
        sz_in0[d]   = pVD_In0->Dim().size_Dim(d);
        sz_in1[d]   = pVD_In1->Dim().size_Dim(d);
        sz_out[d] = max(sz_in0[d], sz_in1[d]);
    }

    //init out
    *pVD_Out = D_VisDat_Obj(
                D_VisDat_Dim(sz_out),
                CV_64FC1);

    //pos
    Vec<int, c_DIM_NUMBER_OF> pos_in0 = {0, 0, 0, 0, 0, 0};
    Vec<int, c_DIM_NUMBER_OF> pos_in1 = {0, 0, 0, 0, 0, 0};
    Vec<int, c_DIM_NUMBER_OF> pos_out = {0, 0, 0, 0, 0, 0};

    //type switch & loop
    switch (pVD_In0->type()) {

    case CV_8UC1:
        do
        {
            pos_out                                     = pVD_Out->pDim()->loop_PosCurrent();
            pos_in0                                     = pVD_In0->pDim()->ForcePosInRange(pos_out);
            pos_in1                                     = pVD_In1->pDim()->ForcePosInRange(pos_out);
            pVD_Out->pMA_full()->at<double>(pos_out)    = function_img1_img2(pVD_In0->pMA_full()->at<uchar>(pos_in0), pVD_In1->pMA_full()->at<uchar>(pos_in1));
        }
        while(pVD_Out->pDim()->loop_Next());
        break;

    case CV_8SC1:
        do
        {
            pos_out                                     = pVD_Out->pDim()->loop_PosCurrent();
            pos_in0                                     = pVD_In0->pDim()->ForcePosInRange(pos_out);
            pos_in1                                     = pVD_In1->pDim()->ForcePosInRange(pos_out);
            pVD_Out->pMA_full()->at<double>(pos_out)    = function_img1_img2(pVD_In0->pMA_full()->at<char>(pos_in0), pVD_In1->pMA_full()->at<char>(pos_in1));
        }
        while(pVD_Out->pDim()->loop_Next());
        break;

    case CV_16UC1:
        do
        {
            pos_out                                     = pVD_Out->pDim()->loop_PosCurrent();
            pos_in0                                     = pVD_In0->pDim()->ForcePosInRange(pos_out);
            pos_in1                                     = pVD_In1->pDim()->ForcePosInRange(pos_out);
            pVD_Out->pMA_full()->at<double>(pos_out)    = function_img1_img2(pVD_In0->pMA_full()->at<ushort>(pos_in0), pVD_In1->pMA_full()->at<ushort>(pos_in1));
        }
        while(pVD_Out->pDim()->loop_Next());
        break;

    case CV_16SC1:
        do
        {
            pos_out                                     = pVD_Out->pDim()->loop_PosCurrent();
            pos_in0                                     = pVD_In0->pDim()->ForcePosInRange(pos_out);
            pos_in1                                     = pVD_In1->pDim()->ForcePosInRange(pos_out);
            pVD_Out->pMA_full()->at<double>(pos_out)    = function_img1_img2(pVD_In0->pMA_full()->at<short>(pos_in0), pVD_In1->pMA_full()->at<short>(pos_in1));
        }
        while(pVD_Out->pDim()->loop_Next());
        break;

    case CV_32SC1:
        do
        {
            pos_out                                     = pVD_Out->pDim()->loop_PosCurrent();
            pos_in0                                     = pVD_In0->pDim()->ForcePosInRange(pos_out);
            pos_in1                                     = pVD_In1->pDim()->ForcePosInRange(pos_out);
            pVD_Out->pMA_full()->at<double>(pos_out)    = function_img1_img2(pVD_In0->pMA_full()->at<int>(pos_in0), pVD_In1->pMA_full()->at<int>(pos_in1));
        }
        while(pVD_Out->pDim()->loop_Next());
        break;

    case CV_32FC1:
        do
        {
            pos_out                                     = pVD_Out->pDim()->loop_PosCurrent();
            pos_in0                                     = pVD_In0->pDim()->ForcePosInRange(pos_out);
            pos_in1                                     = pVD_In1->pDim()->ForcePosInRange(pos_out);
            pVD_Out->pMA_full()->at<double>(pos_out)    = function_img1_img2(pVD_In0->pMA_full()->at<float>(pos_in0), pVD_In1->pMA_full()->at<float>(pos_in1));
        }
        while(pVD_Out->pDim()->loop_Next());
        break;

    case CV_64FC1:
        do
        {
            pos_out                                     = pVD_Out->pDim()->loop_PosCurrent();
            pos_in0                                     = pVD_In0->pDim()->ForcePosInRange(pos_out);
            pos_in1                                     = pVD_In1->pDim()->ForcePosInRange(pos_out);
            pVD_Out->pMA_full()->at<double>(pos_out)    = function_img1_img2(pVD_In0->pMA_full()->at<double>(pos_in0), pVD_In1->pMA_full()->at<double>(pos_in1));
        }
        while(pVD_Out->pDim()->loop_Next());
        break;

    default:
        return ER_type_bad;
    }

    return ER_okay;
}

int D_VisDat_Proc::Math_2img_Function_UnequalSize_8bit(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, function<uchar (double, double)> function_img1_img2)
{
    //errors
    if(pVD_In0->pMA_full()->type() != pVD_In1->pMA_full()->type())      return ER_type_missmatch;
    if(pVD_In0->pMA_full()->channels() != 1)                            return ER_channel_bad;
    if(pVD_In1->pMA_full()->channels() != 1)                            return ER_channel_bad;

    //loop dims
    vector<int> sz_in0(c_DIM_NUMBER_OF);
    vector<int> sz_in1(c_DIM_NUMBER_OF);
    vector<int> sz_out(c_DIM_NUMBER_OF);
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
    {
        sz_in0[d]   = pVD_In0->Dim().size_Dim(d);
        sz_in1[d]   = pVD_In1->Dim().size_Dim(d);
        sz_out[d]   = max(sz_in0[d], sz_in1[d]);
    }

    //init out
    *pVD_Out = D_VisDat_Obj(
                D_VisDat_Dim(sz_out),
                CV_8UC1);

    //pos
    Vec<int, c_DIM_NUMBER_OF> pos_in0 = {0, 0, 0, 0, 0, 0};
    Vec<int, c_DIM_NUMBER_OF> pos_in1 = {0, 0, 0, 0, 0, 0};
    Vec<int, c_DIM_NUMBER_OF> pos_out = {0, 0, 0, 0, 0, 0};

    //type switch & loop
    switch (pVD_In0->type()) {

    case CV_8UC1:
        do
        {
            pos_out                                     = pVD_Out->pDim()->loop_PosCurrent();
            pos_in0                                     = pVD_In0->pDim()->ForcePosInRange(pos_out);
            pos_in1                                     = pVD_In1->pDim()->ForcePosInRange(pos_out);
            pVD_Out->pMA_full()->at<uchar >(pos_out)    = function_img1_img2(pVD_In0->pMA_full()->at<uchar>(pos_in0), pVD_In1->pMA_full()->at<uchar>(pos_in1));
        }
        while(pVD_Out->pDim()->loop_Next());
        break;

    case CV_8SC1:
        do
        {
            pos_out                                     = pVD_Out->pDim()->loop_PosCurrent();
            pos_in0                                     = pVD_In0->pDim()->ForcePosInRange(pos_out);
            pos_in1                                     = pVD_In1->pDim()->ForcePosInRange(pos_out);
            pVD_Out->pMA_full()->at<uchar >(pos_out)    = function_img1_img2(pVD_In0->pMA_full()->at<char>(pos_in0), pVD_In1->pMA_full()->at<char>(pos_in1));
        }
        while(pVD_Out->pDim()->loop_Next());
        break;

    case CV_16UC1:
        do
        {
            pos_out                                     = pVD_Out->pDim()->loop_PosCurrent();
            pos_in0                                     = pVD_In0->pDim()->ForcePosInRange(pos_out);
            pos_in1                                     = pVD_In1->pDim()->ForcePosInRange(pos_out);
            pVD_Out->pMA_full()->at<uchar >(pos_out)    = function_img1_img2(pVD_In0->pMA_full()->at<ushort>(pos_in0), pVD_In1->pMA_full()->at<ushort>(pos_in1));
        }
        while(pVD_Out->pDim()->loop_Next());
        break;

    case CV_16SC1:
        do
        {
            pos_out                                     = pVD_Out->pDim()->loop_PosCurrent();
            pos_in0                                     = pVD_In0->pDim()->ForcePosInRange(pos_out);
            pos_in1                                     = pVD_In1->pDim()->ForcePosInRange(pos_out);
            pVD_Out->pMA_full()->at<uchar >(pos_out)    = function_img1_img2(pVD_In0->pMA_full()->at<short>(pos_in0), pVD_In1->pMA_full()->at<short>(pos_in1));
        }
        while(pVD_Out->pDim()->loop_Next());
        break;

    case CV_32SC1:
        do
        {
            pos_out                                     = pVD_Out->pDim()->loop_PosCurrent();
            pos_in0                                     = pVD_In0->pDim()->ForcePosInRange(pos_out);
            pos_in1                                     = pVD_In1->pDim()->ForcePosInRange(pos_out);
            pVD_Out->pMA_full()->at<uchar >(pos_out)    = function_img1_img2(pVD_In0->pMA_full()->at<int>(pos_in0), pVD_In1->pMA_full()->at<int>(pos_in1));
        }
        while(pVD_Out->pDim()->loop_Next());
        break;

    case CV_32FC1:
        do
        {
            pos_out                                     = pVD_Out->pDim()->loop_PosCurrent();
            pos_in0                                     = pVD_In0->pDim()->ForcePosInRange(pos_out);
            pos_in1                                     = pVD_In1->pDim()->ForcePosInRange(pos_out);
            pVD_Out->pMA_full()->at<uchar >(pos_out)    = function_img1_img2(pVD_In0->pMA_full()->at<float>(pos_in0), pVD_In1->pMA_full()->at<float>(pos_in1));
        }
        while(pVD_Out->pDim()->loop_Next());
        break;

    case CV_64FC1:
        do
        {
            pos_out                                     = pVD_Out->pDim()->loop_PosCurrent();
            pos_in0                                     = pVD_In0->pDim()->ForcePosInRange(pos_out);
            pos_in1                                     = pVD_In1->pDim()->ForcePosInRange(pos_out);
            pVD_Out->pMA_full()->at<uchar >(pos_out)    = function_img1_img2(pVD_In0->pMA_full()->at<double>(pos_in0), pVD_In1->pMA_full()->at<double>(pos_in1));
        }
        while(pVD_Out->pDim()->loop_Next());
        break;

    default:
        return ER_type_bad;
    }

    return ER_okay;
}

int D_VisDat_Proc::Math_3img_Addition(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_3img_Addition(),
                pVD_Out,
                pVD_In0,
                pVD_In1,
                pVD_In2);
}

int D_VisDat_Proc::Math_3img_Addition(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, double summand)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_3img_Addition(
                    summand),
                pVD_Out,
                pVD_In0,
                pVD_In1,
                pVD_In2);
}

int D_VisDat_Proc::Math_3img_Multiplication(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_3img_Multiplication(),
                pVD_Out,
                pVD_In0,
                pVD_In1,
                pVD_In2);
}

int D_VisDat_Proc::Math_3img_Multiplication(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, double factor)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_3img_Multiplication(
                    factor),
                pVD_Out,
                pVD_In0,
                pVD_In1,
                pVD_In2);
}

int D_VisDat_Proc::Math_3img_BitwiseAnd(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_3img_BitwiseAnd(),
                pVD_Out,
                pVD_In0,
                pVD_In1,
                pVD_In2);
}

int D_VisDat_Proc::Math_3img_BitwiseOr(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_3img_BitwiseOr(),
                pVD_Out,
                pVD_In0,
                pVD_In1,
                pVD_In2);
}

int D_VisDat_Proc::Math_4img_Addition(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_4img_Addition(),
                pVD_Out,
                pVD_In0,
                pVD_In1,
                pVD_In2,
                pVD_In3);
}

int D_VisDat_Proc::Math_4img_Addition(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3, double summand)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_4img_Addition(
                    summand),
                pVD_Out,
                pVD_In0,
                pVD_In1,
                pVD_In2,
                pVD_In3);
}

int D_VisDat_Proc::Math_4img_Multiplication(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_4img_Multiplication(),
                pVD_Out,
                pVD_In0,
                pVD_In1,
                pVD_In2,
                pVD_In3);
}

int D_VisDat_Proc::Math_4img_Multiplication(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3, double factor)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_4img_Multiplication(
                    factor),
                pVD_Out,
                pVD_In0,
                pVD_In1,
                pVD_In2,
                pVD_In3);
}

int D_VisDat_Proc::Math_4img_BitwiseAnd(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_4img_BitwiseAnd(),
                pVD_Out,
                pVD_In0,
                pVD_In1,
                pVD_In2,
                pVD_In3);
}

int D_VisDat_Proc::Math_4img_BitwiseOr(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In0, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3)
{
    return Wrap_VD_SameSizeType(
                D_VisDat_Slicing(c_SLICE_2D_XY),
                D_Img_Proc_2dFactory::Math_4img_BitwiseOr(),
                pVD_Out,
                pVD_In0,
                pVD_In1,
                pVD_In2,
                pVD_In3);
}

int D_VisDat_Proc::Transformation_Distance(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int metric, int precision, double spacing_x3d, double spacing_y3d, double spacing_z3d)
{
    if(slice.is_2D())
    {
        *pVD_Out = D_VisDat_Obj(
                    pVD_In->Dim(),
                    D_Img_Proc::TypeIndex_of_Mat(
                        pVD_In->pMA_full()->channels(),
                        CV_32F));

        return Wrap_VD(
                    slice,
                    D_Img_Proc_2dFactory::Transformation_Distance(
                        metric,
                        precision),
                    pVD_Out,
                    pVD_In);
    }
    else if(slice.is_3D())
    {
        *pVD_Out = D_VisDat_Obj(
                    pVD_In->Dim(),
                    CV_64FC1);

        return Wrap_VD(
                    slice,
                    D_Img_Proc_3dFactory::Distance_Transformation_EDT(
                        spacing_x3d,
                        spacing_y3d,
                        spacing_z3d),
                    pVD_Out,
                    pVD_In);
    }
    else
    {
        return ER_dim_missmatch;
    }
}

int D_VisDat_Proc::Transformation_Fourier(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In_Re, D_VisDat_Obj *pVD_In_Im, bool complex_input, bool invers, bool force_fft, bool out_real, int out_complex_mode, bool out_scale, bool out_center, bool out_nof0)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    int channels = pVD_In_Re->pMA_full()->channels();
    if(out_complex_mode == c_COMPLEX2REAL_RE_IM)
        channels = 2;
    else if(out_complex_mode > c_COMPLEX2REAL_RE_IM)
        channels = 3;

    *pVD_Out = D_VisDat_Obj(
                pVD_In_Re->Dim(),
                D_Img_Proc::TypeIndex_of_Mat(
                    channels,
                    CV_64F));

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Transformation_Fourier(
                    complex_input,
                    invers,
                    force_fft,
                    out_real,
                    out_complex_mode,
                    out_scale,
                    out_center,
                    out_nof0),
                pVD_Out,
                pVD_In_Re,
                pVD_In_Im);
}

int D_VisDat_Proc::Transformation_Watershed(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Marker)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                CV_32SC1);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Transformation_Watershed(),
                pVD_Out,
                pVD_In,
                pVD_Marker);
}

int D_VisDat_Proc::Transformation_Watershed_Auto(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Marker, bool include_not_seeded, bool conv_8bit, bool exclude_border)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    if(conv_8bit)
        *pVD_Out = D_VisDat_Obj(
                    pVD_In->Dim(),
                    CV_8UC1);
    else
        *pVD_Out = D_VisDat_Obj(
                    pVD_In->Dim(),
                    CV_16UC1);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Transformation_Watershed_Auto(
                    include_not_seeded,
                    conv_8bit,
                    exclude_border),
                pVD_Out,
                pVD_In,
                pVD_Marker);
}

int D_VisDat_Proc::Transformation_Watershed_Auto(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double distance, bool include_not_seeded, bool conv_8bit, bool exclude_border)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    if(conv_8bit)
        *pVD_Out = D_VisDat_Obj(
                    pVD_In->Dim(),
                    CV_8UC1);
    else
        *pVD_Out = D_VisDat_Obj(
                    pVD_In->Dim(),
                    CV_16UC1);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Transformation_Watershed_Auto(
                    distance,
                    include_not_seeded,
                    conv_8bit,
                    exclude_border),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Transformation_Watershed_Auto(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size, double sigma, bool include_not_seeded, bool conv_8bit, bool exclude_border)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    if(conv_8bit)
        *pVD_Out = D_VisDat_Obj(
                    pVD_In->Dim(),
                    CV_8UC1);
    else
        *pVD_Out = D_VisDat_Obj(
                    pVD_In->Dim(),
                    CV_16UC1);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Transformation_Watershed_Auto(
                    size,
                    sigma,
                    include_not_seeded,
                    conv_8bit,
                    exclude_border),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Feature_Value(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int feature, int connectivity)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                CV_64FC1);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Feature_Value(
                    feature,
                    connectivity),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::FeatureContext_Value(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int pt_type1, int pt_type2, double dist_min, double dist_max, int feat, int stat, int connectivity)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                CV_64FC1);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::FeatureContext_Value(
                    pt_type1,
                    pt_type2,
                    dist_min,
                    dist_max,
                    feat,
                    stat,
                    connectivity),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Feature_Select(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int feature, double f_min, double f_max, int connectivity)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                CV_8UC1);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Feature_Select(
                    feature,
                    f_min,
                    f_max,
                    connectivity),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::FeatureContext_Select(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int pt_type1, int pt_type2, double dist_min, double dist_max, int feat, int stat, double t_min, double t_max, int connectivity)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                CV_8UC1);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::FeatureContext_Select(
                    pt_type1,
                    pt_type2,
                    dist_min,
                    dist_max,
                    feat,
                    stat,
                    t_min,
                    t_max,
                    connectivity),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Feature_Visualize(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int feature, int connectivity, int thickness, double scale)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                CV_8UC3);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Feature_Visualize(
                    feature,
                    connectivity,
                    thickness,
                    scale),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Feature_Connect(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int pt_type1, int pt_type2, double dist_min, double dist_max, int feat1, int feat2, function<bool (double, double)> comp, int connect_mode, int connectivity, int thickness)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                CV_8UC1);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Feature_Connect(
                    pt_type1,
                    pt_type2,
                    dist_min,
                    dist_max,
                    feat1,
                    feat2,
                    comp,
                    connect_mode,
                    connectivity,
                    thickness),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Geometric_Reduce(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int geometric, int connectivity, int thickness, uchar value)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                CV_8UC1);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Geometric_Reduce(
                    geometric,
                    connectivity,
                    thickness,
                    value),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Histogram_Equalize(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                CV_8UC1);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Histogram_Equalize(),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::GammaSpread(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, double gamma, double in_min, double in_max, double out_min, double out_max, bool force_8bit)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    if(force_8bit)
        *pVD_Out = D_VisDat_Obj(
                    pVD_In->Dim(),
                    D_Img_Proc::TypeIndex_of_Mat(
                        pVD_In->pMA_full()->channels(),
                        CV_8U));
    else
        *pVD_Out = D_VisDat_Obj(
                    pVD_In->Dim(),
                    D_Img_Proc::TypeIndex_of_Mat(
                        pVD_In->pMA_full()->channels(),
                        CV_64F));

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::GammaSpread(
                    gamma,
                    in_min,
                    in_max,
                    out_min,
                    out_max,
                    force_8bit),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Draw_Label_Numbers(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, D_VisDat_Obj *pVD_Label, double scale, double thickness, bool center)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                CV_8UC3);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::Draw_Label_Numbers(
                    scale,
                    thickness,
                    center),
                pVD_Out,
                pVD_In,
                pVD_Label);
}

int D_VisDat_Proc::Neighborhood_Configs(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In)
{
    if(!slice.is_3D())
        return ER_dim_3D_only;

    return Wrap_VD_SameSizeType(
                slice,
                D_Img_Proc_3dFactory::Neighborhood_Configs(),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::Euler_Number(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, double *euler_number, D_VisDat_Obj *pVD_In)
{
    if(!slice.is_3D())
        return ER_dim_3D_only;

    return Wrap_VD_SameSizeType(
                slice,
                D_Img_Proc_3dFactory::Euler_Number(
                    euler_number),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::MotionField(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int size_space, int size_time)
{
    //THERE IS A BUG - THIS COMPILES AND RUNS BUT I CALCULATES NOT WHAT WAS INTENDED

    qDebug() << "MotionField" << "start";

    //Errors
    if(pVD_In->pMA_full()->empty())                         return ER_empty;
    if(pVD_In->pMA_full()->channels() != 1)                 return ER_channel_bad;
    if(pVD_In->pMA_full()->depth() != CV_8U)                return ER_bitdepth_bad;
    if(pVD_In->pDim()->size_X() < size_space)               return ER_dim_X_out_of_range;
    if(pVD_In->pDim()->size_Y() < size_space)               return ER_dim_Y_out_of_range;
    if(pVD_In->pDim()->size_T() < size_time)                return ER_dim_T_out_of_range;
    if(size_space < 3)                                      return ER_parameter_bad;
    if(size_space % 2 != 1)                                 return ER_parameter_bad;
    if(size_time < 3)                                       return ER_parameter_bad;
    if(size_time % 2 != 1)                                  return ER_parameter_bad;

    //Idices of infos in channels
    const int CH_INFO_DIRECTION = 0;
    const int CH_INFO_NORM      = 1;
    const int CH_INFO_WEIGHT    = 2;

    //Size in
    int n_x_in  = pVD_In->pDim()->size_X();
    int n_y_in  = pVD_In->pDim()->size_Y();
    int n_t_in  = pVD_In->pDim()->size_T();
    qDebug() << "MotionField" << "size in x/y/t" << n_x_in << n_y_in << n_t_in;

    //Size both
    int n_z     = pVD_In->pDim()->size_Z();
    int n_s     = pVD_In->pDim()->size_S();
    int n_p     = pVD_In->pDim()->size_P();
    qDebug() << "MotionField" << "size both z/s/p" << n_z << n_s << n_p;

    //Size out
    int n_x_out = n_x_in - size_space + 1;
    int n_y_out = n_y_in - size_space + 1;
    int n_t_out = 1;
    int n_t_loop = n_t_in - size_time + 1;
    qDebug() << "MotionField" << "size out x/y/t" << n_x_out << n_y_out << n_t_out;
    qDebug() << "MotionField" << "size loop t" << n_t_loop;

    //Shifts mask
    int s_x     = size_space / 2;
    int s_y     = size_space / 2;
    int s_t     = size_time  / 2;
    qDebug() << "MotionField" << "shifts x/y/t" << s_x << s_y << s_t;

    //Init out
    *pVD_Out = D_VisDat_Obj(
                D_VisDat_Dim(
                    n_x_out,
                    n_y_out,
                    pVD_In->pDim()->size_Z(),
                    n_t_out,
                    pVD_In->pDim()->size_S(),
                    pVD_In->pDim()->size_P()),
                CV_64FC3);
    qDebug() << "MotionField" << "Out" << pVD_Out->info();

    //pos
    Vec<int, c_DIM_NUMBER_OF> pos_bef   = {0, 0, 0, 0, 0, 0};
    Vec<int, c_DIM_NUMBER_OF> pos_cur   = {0, 0, 0, 0, 0, 0};
    Vec<int, c_DIM_NUMBER_OF> pos_aft   = {0, 0, 0, 0, 0, 0};
    Vec<int, c_DIM_NUMBER_OF> pos_out   = {0, 0, 0, 0, 0, 0};

    qDebug() << "MotionField" << "start loop";

    //loop irrelevant dims
    for(int p = 0; p < n_p; p++)
    {
        pos_bef[c_DIM_P] = p;
        pos_cur[c_DIM_P] = p;
        pos_aft[c_DIM_P] = p;
        pos_out[c_DIM_P] = p;

        for(int s = 0; s < n_s; s++)
        {
            pos_bef[c_DIM_S] = s;
            pos_cur[c_DIM_S] = s;
            pos_aft[c_DIM_S] = s;
            pos_out[c_DIM_S] = s;

            for(int z = 0; z < n_z; z++)
            {
                pos_bef[c_DIM_Z] = z;
                pos_cur[c_DIM_Z] = z;
                pos_aft[c_DIM_Z] = z;
                pos_out[c_DIM_Z] = z;

                //loop pixels input
                for(int yi = s_y; yi < n_y_in - s_y; yi++)
                {
                    pos_cur[c_DIM_Y] = yi;
                    pos_out[c_DIM_Y] = yi - s_y;

                    for(int xi = s_x; xi < n_x_in - s_x; xi++)
                    {
                        pos_cur[c_DIM_X] = xi;
                        pos_out[c_DIM_X] = xi - s_x;

                        double t_stack_w = 0;
                        double t_stack_x = 0;
                        double t_stack_y = 0;

                        //loop frames
                        for(int t = s_t; t <= (n_t_in + s_t); t++)
                        {
                            pos_bef[c_DIM_T] = t - s_t;
                            pos_cur[c_DIM_T] = t;
                            pos_aft[c_DIM_T] = t + s_t;
                            pos_out[c_DIM_T] = 0;

                            //qDebug() << "MotionField" << "loop t" << t << "img_x/y" << xi << yi;

                            //center of mass
                            double com_bef_x = 0;
                            double com_bef_y = 0;
                            double com_bef_w = 0;
                            double com_aft_x = 0;
                            double com_aft_y = 0;
                            double com_aft_w = 0;

                            //loop pixels mask
                            for(int ym = yi - s_y; ym <= (yi + s_y); ym++)
                            {
                                pos_bef[c_DIM_Y] = ym;
                                pos_aft[c_DIM_Y] = ym;

                                for(int xm = xi - s_x; xm <= (xi + s_x); xm++)
                                {
                                    pos_bef[c_DIM_X] = xm;
                                    pos_aft[c_DIM_X] = xm;

                                    //qDebug() << "MotionField" << "mask_x/y" << xm << ym;

                                    //cummulate center of mass weighted by value - before
                                    double bef_w = static_cast<double>(pVD_In->pMA_full()->at<uchar>(pos_bef));
                                    com_bef_x   += static_cast<double>((xm - xi) * bef_w);
                                    com_bef_y   += static_cast<double>((ym - yi) * bef_w);
                                    com_bef_w   += bef_w;

                                    //cummulate center of mass weighted by value - after
                                    double aft_w = static_cast<double>(pVD_In->pMA_full()->at<uchar>(pos_aft));
                                    com_aft_x   += static_cast<double>((xm - xi) * aft_w);
                                    com_aft_y   += static_cast<double>((ym - yi) * aft_w);
                                    com_aft_w   += aft_w;
                                }
                            }

                            //avoid zero division (can only occur if coresponding value is 0 too, so value doesn't matter as long as it is not 0)
                            if(com_bef_w <= 0)  com_bef_w = 1.0;
                            if(com_aft_w <= 0)  com_aft_w = 1.0;

                            //shift of center of mass between before and after frame weighted by current frame
                            double shift_x      = ((com_aft_x / com_aft_w) - (com_bef_x / com_bef_w)) / (s_x * 2);
                            double shift_y      = ((com_aft_y / com_aft_w) - (com_bef_y / com_bef_w)) / (s_y * 2);

                            //weight of current px
                            double cur_w        = pVD_In->pMA_full()->at<uchar>(pos_cur);
                            t_stack_w           += cur_w;
                            t_stack_x           += shift_x;
                            t_stack_y           += shift_y;
                        }

                        //avoid zero division (can only occur if coresponding value is 0 too, so value doesn't matter as long as it is not 0)
                        if(t_stack_w <= 0)
                            t_stack_w = 1.0;
                        double t_stack_norm = sqrt(t_stack_x * t_stack_x + t_stack_y * t_stack_y) / t_stack_w;
                        double t_stack_direction = atan2(t_stack_y, t_stack_x);


                      //qDebug() << "MotionField" << "x/y" << xi << yi << "weight" << t_stack_w << "norm" << t_stack_norm << "direction" << t_stack_direction;

                        pVD_Out->pMA_full()->at<Vec3d>(pos_out)[CH_INFO_WEIGHT]     = t_stack_w;
                        pVD_Out->pMA_full()->at<Vec3d>(pos_out)[CH_INFO_NORM]       = t_stack_norm;
                        pVD_Out->pMA_full()->at<Vec3d>(pos_out)[CH_INFO_DIRECTION]  = t_stack_direction;
                    }
                }
            }
        }
    }

    return ER_okay;
}

int D_VisDat_Proc::ClassBorder_kNN(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_Class0, D_VisDat_Obj *pVD_Class1, int n)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_Class0->Dim(),
                CV_8UC3);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::ClassBorder_kNN(
                    n),
                pVD_Out,
                pVD_Class0,
                pVD_Class1);
}

int D_VisDat_Proc::HDR(D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, int dim_exposures, double exp_min, double exp_fac, bool project_do, int stat, bool thres_do, double thres_low, double thres_high, double val_default)
{
    //errors
    if(pVD_In->pMA_full()->empty())             return ER_empty;
    if(pVD_In->pMA_full()->channels() != 1)     return ER_channel_bad;

    //dims normal
    vector<int> dims_loop;
    for(int d = 0; d < c_DIM_NUMBER_OF; d++)
        if(d != dim_exposures)
            dims_loop.push_back(d);

    //create output
    D_VisDat_Dim Dim_out = pVD_In->Dim();
    if(project_do)
        Dim_out.set_size_Dim(dim_exposures, 1);
    *pVD_Out = D_VisDat_Obj(Dim_out, CV_64FC1);

    //sizes
    vector<int> sz_out = Dim_out.size_DimsVec();

    //pos
    Vec<int, 6> pos_full        = {0, 0, 0, 0, 0, 0};
    Vec<int, 6> pos_projected   = {0, 0, 0, 0, 0, 0};

    //projection
    int sz_project = pVD_In->pDim()->size_Dim(dim_exposures);
    vector<double> v_normed;

    //porjection function
    function<double (vector<double>)> F_project = D_Stat::Function_SingleStat(stat);

    //project
    switch (pVD_In->type()) {

    case CV_8UC1:
        for(                pos_projected[dims_loop[4]] = 0, pos_full[dims_loop[4]] = 0;    pos_projected[dims_loop[4]] < sz_out[dims_loop[4]];   pos_projected[dims_loop[4]]++, pos_full[dims_loop[4]]++)
            for(            pos_projected[dims_loop[3]] = 0, pos_full[dims_loop[3]] = 0;    pos_projected[dims_loop[3]] < sz_out[dims_loop[3]];   pos_projected[dims_loop[3]]++, pos_full[dims_loop[3]]++)
                for(        pos_projected[dims_loop[2]] = 0, pos_full[dims_loop[2]] = 0;    pos_projected[dims_loop[2]] < sz_out[dims_loop[2]];   pos_projected[dims_loop[2]]++, pos_full[dims_loop[2]]++)
                    for(    pos_projected[dims_loop[1]] = 0, pos_full[dims_loop[1]] = 0;    pos_projected[dims_loop[1]] < sz_out[dims_loop[1]];   pos_projected[dims_loop[1]]++, pos_full[dims_loop[1]]++)
                        for(pos_projected[dims_loop[0]] = 0, pos_full[dims_loop[0]] = 0;    pos_projected[dims_loop[0]] < sz_out[dims_loop[0]];   pos_projected[dims_loop[0]]++, pos_full[dims_loop[0]]++)
                        {
                            if(project_do)
                            {
                                //get values
                                v_normed.clear();
                                double exp_time = exp_min;
                                for(pos_full[dim_exposures] = 0; pos_full[dim_exposures] < sz_project; pos_full[dim_exposures]++)
                                {
                                    double val = static_cast<double>(pVD_In->pMA_full()->at<uchar>(pos_full));
                                    if((thres_low < val && val < thres_high) || !thres_do)
                                        v_normed.push_back(val / exp_time);
                                    exp_time *= exp_fac;
                                }

                                //calc result
                                if(!v_normed.empty())
                                    pVD_Out->pMA_full()->at<double>(pos_projected) = F_project(v_normed);
                                else
                                    pVD_Out->pMA_full()->at<double>(pos_projected) = val_default;
                            }
                            else
                            {
                                double exp_time = exp_min;
                                for(pos_full[dim_exposures] = 0; pos_full[dim_exposures] < sz_project; pos_full[dim_exposures]++)
                                {
                                    pVD_Out->pMA_full()->at<double>(pos_full) = static_cast<double>(pVD_In->pMA_full()->at<uchar>(pos_full) / exp_time);
                                    exp_time *= exp_fac;
                                }
                            }
                        }
        break;

    case CV_8SC1:
        for(                pos_projected[dims_loop[4]] = 0, pos_full[dims_loop[4]] = 0;    pos_projected[dims_loop[4]] < sz_out[dims_loop[4]];   pos_projected[dims_loop[4]]++, pos_full[dims_loop[4]]++)
            for(            pos_projected[dims_loop[3]] = 0, pos_full[dims_loop[3]] = 0;    pos_projected[dims_loop[3]] < sz_out[dims_loop[3]];   pos_projected[dims_loop[3]]++, pos_full[dims_loop[3]]++)
                for(        pos_projected[dims_loop[2]] = 0, pos_full[dims_loop[2]] = 0;    pos_projected[dims_loop[2]] < sz_out[dims_loop[2]];   pos_projected[dims_loop[2]]++, pos_full[dims_loop[2]]++)
                    for(    pos_projected[dims_loop[1]] = 0, pos_full[dims_loop[1]] = 0;    pos_projected[dims_loop[1]] < sz_out[dims_loop[1]];   pos_projected[dims_loop[1]]++, pos_full[dims_loop[1]]++)
                        for(pos_projected[dims_loop[0]] = 0, pos_full[dims_loop[0]] = 0;    pos_projected[dims_loop[0]] < sz_out[dims_loop[0]];   pos_projected[dims_loop[0]]++, pos_full[dims_loop[0]]++)
                        {
                            if(project_do)
                            {
                                //get values
                                v_normed.clear();
                                double exp_time = exp_min;
                                for(pos_full[dim_exposures] = 0; pos_full[dim_exposures] < sz_project; pos_full[dim_exposures]++)
                                {
                                    double val = static_cast<double>(pVD_In->pMA_full()->at<char>(pos_full));
                                    if((thres_low < val && val < thres_high) || !thres_do)
                                        v_normed.push_back(val / exp_time);
                                    exp_time *= exp_fac;
                                }

                                //calc result
                                if(!v_normed.empty())
                                    pVD_Out->pMA_full()->at<double>(pos_projected) = F_project(v_normed);
                                else
                                    pVD_Out->pMA_full()->at<double>(pos_projected) = val_default;
                            }
                            else
                            {
                                double exp_time = exp_min;
                                for(pos_full[dim_exposures] = 0; pos_full[dim_exposures] < sz_project; pos_full[dim_exposures]++)
                                {
                                    pVD_Out->pMA_full()->at<double>(pos_full) = static_cast<double>(pVD_In->pMA_full()->at<uchar>(pos_full) / exp_time);
                                    exp_time *= exp_fac;
                                }
                            }
                        }
        break;

    case CV_16UC1:
        for(                pos_projected[dims_loop[4]] = 0, pos_full[dims_loop[4]] = 0;    pos_projected[dims_loop[4]] < sz_out[dims_loop[4]];   pos_projected[dims_loop[4]]++, pos_full[dims_loop[4]]++)
            for(            pos_projected[dims_loop[3]] = 0, pos_full[dims_loop[3]] = 0;    pos_projected[dims_loop[3]] < sz_out[dims_loop[3]];   pos_projected[dims_loop[3]]++, pos_full[dims_loop[3]]++)
                for(        pos_projected[dims_loop[2]] = 0, pos_full[dims_loop[2]] = 0;    pos_projected[dims_loop[2]] < sz_out[dims_loop[2]];   pos_projected[dims_loop[2]]++, pos_full[dims_loop[2]]++)
                    for(    pos_projected[dims_loop[1]] = 0, pos_full[dims_loop[1]] = 0;    pos_projected[dims_loop[1]] < sz_out[dims_loop[1]];   pos_projected[dims_loop[1]]++, pos_full[dims_loop[1]]++)
                        for(pos_projected[dims_loop[0]] = 0, pos_full[dims_loop[0]] = 0;    pos_projected[dims_loop[0]] < sz_out[dims_loop[0]];   pos_projected[dims_loop[0]]++, pos_full[dims_loop[0]]++)
                        {
                            if(project_do)
                            {
                                //get values
                                v_normed.clear();
                                double exp_time = exp_min;
                                for(pos_full[dim_exposures] = 0; pos_full[dim_exposures] < sz_project; pos_full[dim_exposures]++)
                                {
                                    double val = static_cast<double>(pVD_In->pMA_full()->at<ushort>(pos_full));
                                    if((thres_low < val && val < thres_high) || !thres_do)
                                        v_normed.push_back(val / exp_time);
                                    exp_time *= exp_fac;
                                }

                                //calc result
                                if(!v_normed.empty())
                                    pVD_Out->pMA_full()->at<double>(pos_projected) = F_project(v_normed);
                                else
                                    pVD_Out->pMA_full()->at<double>(pos_projected) = val_default;
                            }
                            else
                            {
                                double exp_time = exp_min;
                                for(pos_full[dim_exposures] = 0; pos_full[dim_exposures] < sz_project; pos_full[dim_exposures]++)
                                {
                                    pVD_Out->pMA_full()->at<double>(pos_full) = static_cast<double>(pVD_In->pMA_full()->at<uchar>(pos_full) / exp_time);
                                    exp_time *= exp_fac;
                                }
                            }
                        }
        break;

    case CV_16SC1:
        for(                pos_projected[dims_loop[4]] = 0, pos_full[dims_loop[4]] = 0;    pos_projected[dims_loop[4]] < sz_out[dims_loop[4]];   pos_projected[dims_loop[4]]++, pos_full[dims_loop[4]]++)
            for(            pos_projected[dims_loop[3]] = 0, pos_full[dims_loop[3]] = 0;    pos_projected[dims_loop[3]] < sz_out[dims_loop[3]];   pos_projected[dims_loop[3]]++, pos_full[dims_loop[3]]++)
                for(        pos_projected[dims_loop[2]] = 0, pos_full[dims_loop[2]] = 0;    pos_projected[dims_loop[2]] < sz_out[dims_loop[2]];   pos_projected[dims_loop[2]]++, pos_full[dims_loop[2]]++)
                    for(    pos_projected[dims_loop[1]] = 0, pos_full[dims_loop[1]] = 0;    pos_projected[dims_loop[1]] < sz_out[dims_loop[1]];   pos_projected[dims_loop[1]]++, pos_full[dims_loop[1]]++)
                        for(pos_projected[dims_loop[0]] = 0, pos_full[dims_loop[0]] = 0;    pos_projected[dims_loop[0]] < sz_out[dims_loop[0]];   pos_projected[dims_loop[0]]++, pos_full[dims_loop[0]]++)
                        {
                            if(project_do)
                            {
                                //get values
                                v_normed.clear();
                                double exp_time = exp_min;
                                for(pos_full[dim_exposures] = 0; pos_full[dim_exposures] < sz_project; pos_full[dim_exposures]++)
                                {
                                    double val = static_cast<double>(pVD_In->pMA_full()->at<short>(pos_full));
                                    if((thres_low < val && val < thres_high) || !thres_do)
                                        v_normed.push_back(val / exp_time);
                                    exp_time *= exp_fac;
                                }

                                //calc result
                                if(!v_normed.empty())
                                    pVD_Out->pMA_full()->at<double>(pos_projected) = F_project(v_normed);
                                else
                                    pVD_Out->pMA_full()->at<double>(pos_projected) = val_default;
                            }
                            else
                            {
                                double exp_time = exp_min;
                                for(pos_full[dim_exposures] = 0; pos_full[dim_exposures] < sz_project; pos_full[dim_exposures]++)
                                {
                                    pVD_Out->pMA_full()->at<double>(pos_full) = static_cast<double>(pVD_In->pMA_full()->at<uchar>(pos_full) / exp_time);
                                    exp_time *= exp_fac;
                                }
                            }
                        }
        break;

    case CV_32SC1:
        for(                pos_projected[dims_loop[4]] = 0, pos_full[dims_loop[4]] = 0;    pos_projected[dims_loop[4]] < sz_out[dims_loop[4]];   pos_projected[dims_loop[4]]++, pos_full[dims_loop[4]]++)
            for(            pos_projected[dims_loop[3]] = 0, pos_full[dims_loop[3]] = 0;    pos_projected[dims_loop[3]] < sz_out[dims_loop[3]];   pos_projected[dims_loop[3]]++, pos_full[dims_loop[3]]++)
                for(        pos_projected[dims_loop[2]] = 0, pos_full[dims_loop[2]] = 0;    pos_projected[dims_loop[2]] < sz_out[dims_loop[2]];   pos_projected[dims_loop[2]]++, pos_full[dims_loop[2]]++)
                    for(    pos_projected[dims_loop[1]] = 0, pos_full[dims_loop[1]] = 0;    pos_projected[dims_loop[1]] < sz_out[dims_loop[1]];   pos_projected[dims_loop[1]]++, pos_full[dims_loop[1]]++)
                        for(pos_projected[dims_loop[0]] = 0, pos_full[dims_loop[0]] = 0;    pos_projected[dims_loop[0]] < sz_out[dims_loop[0]];   pos_projected[dims_loop[0]]++, pos_full[dims_loop[0]]++)
                        {
                            if(project_do)
                            {
                                //get values
                                v_normed.clear();
                                double exp_time = exp_min;
                                for(pos_full[dim_exposures] = 0; pos_full[dim_exposures] < sz_project; pos_full[dim_exposures]++)
                                {
                                    double val = static_cast<double>(pVD_In->pMA_full()->at<int>(pos_full));
                                    if((thres_low < val && val < thres_high) || !thres_do)
                                        v_normed.push_back(val / exp_time);
                                    exp_time *= exp_fac;
                                }

                                //calc result
                                if(!v_normed.empty())
                                    pVD_Out->pMA_full()->at<double>(pos_projected) = F_project(v_normed);
                                else
                                    pVD_Out->pMA_full()->at<double>(pos_projected) = val_default;
                            }
                            else
                            {
                                double exp_time = exp_min;
                                for(pos_full[dim_exposures] = 0; pos_full[dim_exposures] < sz_project; pos_full[dim_exposures]++)
                                {
                                    pVD_Out->pMA_full()->at<double>(pos_full) = static_cast<double>(pVD_In->pMA_full()->at<uchar>(pos_full) / exp_time);
                                    exp_time *= exp_fac;
                                }
                            }
                        }
        break;

    case CV_32FC1:
        for(                pos_projected[dims_loop[4]] = 0, pos_full[dims_loop[4]] = 0;    pos_projected[dims_loop[4]] < sz_out[dims_loop[4]];   pos_projected[dims_loop[4]]++, pos_full[dims_loop[4]]++)
            for(            pos_projected[dims_loop[3]] = 0, pos_full[dims_loop[3]] = 0;    pos_projected[dims_loop[3]] < sz_out[dims_loop[3]];   pos_projected[dims_loop[3]]++, pos_full[dims_loop[3]]++)
                for(        pos_projected[dims_loop[2]] = 0, pos_full[dims_loop[2]] = 0;    pos_projected[dims_loop[2]] < sz_out[dims_loop[2]];   pos_projected[dims_loop[2]]++, pos_full[dims_loop[2]]++)
                    for(    pos_projected[dims_loop[1]] = 0, pos_full[dims_loop[1]] = 0;    pos_projected[dims_loop[1]] < sz_out[dims_loop[1]];   pos_projected[dims_loop[1]]++, pos_full[dims_loop[1]]++)
                        for(pos_projected[dims_loop[0]] = 0, pos_full[dims_loop[0]] = 0;    pos_projected[dims_loop[0]] < sz_out[dims_loop[0]];   pos_projected[dims_loop[0]]++, pos_full[dims_loop[0]]++)
                        {
                            if(project_do)
                            {
                                //get values
                                v_normed.clear();
                                double exp_time = exp_min;
                                for(pos_full[dim_exposures] = 0; pos_full[dim_exposures] < sz_project; pos_full[dim_exposures]++)
                                {
                                    double val = static_cast<double>(pVD_In->pMA_full()->at<float>(pos_full));
                                    if((thres_low < val && val < thres_high) || !thres_do)
                                        v_normed.push_back(val / exp_time);
                                    exp_time *= exp_fac;
                                }

                                //calc result
                                if(!v_normed.empty())
                                    pVD_Out->pMA_full()->at<double>(pos_projected) = F_project(v_normed);
                                else
                                    pVD_Out->pMA_full()->at<double>(pos_projected) = val_default;
                            }
                            else
                            {
                                double exp_time = exp_min;
                                for(pos_full[dim_exposures] = 0; pos_full[dim_exposures] < sz_project; pos_full[dim_exposures]++)
                                {
                                    pVD_Out->pMA_full()->at<double>(pos_full) = static_cast<double>(pVD_In->pMA_full()->at<uchar>(pos_full) / exp_time);
                                    exp_time *= exp_fac;
                                }
                            }
                        }
        break;

    case CV_64FC1:
        for(                pos_projected[dims_loop[4]] = 0, pos_full[dims_loop[4]] = 0;    pos_projected[dims_loop[4]] < sz_out[dims_loop[4]];   pos_projected[dims_loop[4]]++, pos_full[dims_loop[4]]++)
            for(            pos_projected[dims_loop[3]] = 0, pos_full[dims_loop[3]] = 0;    pos_projected[dims_loop[3]] < sz_out[dims_loop[3]];   pos_projected[dims_loop[3]]++, pos_full[dims_loop[3]]++)
                for(        pos_projected[dims_loop[2]] = 0, pos_full[dims_loop[2]] = 0;    pos_projected[dims_loop[2]] < sz_out[dims_loop[2]];   pos_projected[dims_loop[2]]++, pos_full[dims_loop[2]]++)
                    for(    pos_projected[dims_loop[1]] = 0, pos_full[dims_loop[1]] = 0;    pos_projected[dims_loop[1]] < sz_out[dims_loop[1]];   pos_projected[dims_loop[1]]++, pos_full[dims_loop[1]]++)
                        for(pos_projected[dims_loop[0]] = 0, pos_full[dims_loop[0]] = 0;    pos_projected[dims_loop[0]] < sz_out[dims_loop[0]];   pos_projected[dims_loop[0]]++, pos_full[dims_loop[0]]++)
                        {
                            if(project_do)
                            {
                                //get values
                                v_normed.clear();
                                double exp_time = exp_min;
                                for(pos_full[dim_exposures] = 0; pos_full[dim_exposures] < sz_project; pos_full[dim_exposures]++)
                                {
                                    double val = static_cast<double>(pVD_In->pMA_full()->at<double>(pos_full));
                                    if((thres_low < val && val < thres_high) || !thres_do)
                                        v_normed.push_back(val / exp_time);
                                    exp_time *= exp_fac;
                                }

                                //calc result
                                if(!v_normed.empty())
                                    pVD_Out->pMA_full()->at<double>(pos_projected) = F_project(v_normed);
                                else
                                    pVD_Out->pMA_full()->at<double>(pos_projected) = val_default;
                            }
                            else
                            {
                                double exp_time = exp_min;
                                for(pos_full[dim_exposures] = 0; pos_full[dim_exposures] < sz_project; pos_full[dim_exposures]++)
                                {
                                    pVD_Out->pMA_full()->at<double>(pos_full) = static_cast<double>(pVD_In->pMA_full()->at<uchar>(pos_full) / exp_time);
                                    exp_time *= exp_fac;
                                }
                            }
                        }
        break;

    default:
        return ER_type_bad;
        break;
    }

    return ER_okay;
}

int D_VisDat_Proc::DistancesStat(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In, function<double (vector<double>)> F_Stat)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    *pVD_Out = D_VisDat_Obj(
                pVD_In->Dim(),
                CV_64FC1);

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::DistancesStat(
                    F_Stat),
                pVD_Out,
                pVD_In);
}

int D_VisDat_Proc::ZernikeStack(D_VisDat_Obj *pVD_Out, int r_max, int j_max)
{
    *pVD_Out = D_VisDat_Obj(
                D_VisDat_Dim(2 * r_max + 1, 2 * r_max + 1, 1, 1, j_max + 1, 1),
                CV_64FC1);

    int ER;
    for(int j = 0; j <= j_max; j++)
    {
        Mat MA_tmp_result;
        ER = D_Img_Proc::Generate_byValueFunction(
                    &MA_tmp_result,
                    pVD_Out->pDim()->size_X(),
                    pVD_Out->pDim()->size_Y(),
                    D_Math::Function_2D_to_1D(
                        c_MATH_2D_TO_1D_ZERNIKE_J,
                        r_max,
                        j));
        if(ER != ER_okay)
        {
            MA_tmp_result.release();
            return ER;
        }

        ER = Write_2D_Plane(
                    pVD_Out,
                    &MA_tmp_result,
                    D_VisDat_Slice_2D(-1, -1, 0, 0, j, 0));
        if(ER != ER_okay)
        {
            MA_tmp_result.release();
            return ER;
        }
    }

    return ER_okay;
}

int D_VisDat_Proc::RadiometricStereo(D_VisDat_Slicing slice, D_VisDat_Obj *pVD_Out, D_VisDat_Obj *pVD_In1, D_VisDat_Obj *pVD_In2, D_VisDat_Obj *pVD_In3, double S1X, double S1Y, double S1Z, double S2X, double S2Y, double S2Z, double S3X, double S3Y, double S3Z, int out_mode)
{
    if(!slice.is_2D())
        return ER_dim_2D_only;

    if(out_mode == c_STEREO_ALBEDO)
        *pVD_Out = D_VisDat_Obj(
                    pVD_In1->Dim(),
                    CV_64FC3);
    else if(out_mode == c_STEREO_ALBEDO)
        *pVD_Out = D_VisDat_Obj(
                    pVD_In1->Dim(),
                    CV_64FC3);
    else
        return ER_parameter_bad;

    return Wrap_VD(
                slice,
                D_Img_Proc_2dFactory::RadiometricStereo(
                    S1X, S1Y, S1Z, S2X, S2Y, S2Z, S3X, S3Y, S3Z,
                    out_mode),
                pVD_Out,
                pVD_In1,
                pVD_In2,
                pVD_In3);
}

int D_VisDat_Proc::Calc_MinMax(D_VisDat_Obj *pVD_In, double *min_ext, double *max_ext)
{
    if(pVD_In->pMA_full()->empty())             return ER_empty;

    int vol = pVD_In->pDim()->size_PixelCount();

    switch (pVD_In->pMA_full()->type()) {

    case CV_8UC1:
    {
        uchar* ptr = reinterpret_cast<uchar*>(pVD_In->pMA_full()->data);
        *min_ext = *max_ext = static_cast<double>(*ptr);
        for(int px = 0; px < vol; px++, ptr++)
        {
            double val = static_cast<double>(*ptr);
            if(val < *min_ext)  *min_ext = val;
            if(val > *max_ext)  *max_ext = val;
        }
    }
        break;

    case CV_8SC1:
    {
        char* ptr = reinterpret_cast<char*>(pVD_In->pMA_full()->data);
        *min_ext = *max_ext = static_cast<double>(*ptr);
        for(int px = 0; px < vol; px++, ptr++)
        {
            double val = static_cast<double>(*ptr);
            if(val < *min_ext)  *min_ext = val;
            if(val > *max_ext)  *max_ext = val;
        }
    }
        break;

    case CV_16UC1:
    {
        ushort* ptr = reinterpret_cast<ushort*>(pVD_In->pMA_full()->data);
        *min_ext = *max_ext = static_cast<double>(*ptr);
        for(int px = 0; px < vol; px++, ptr++)
        {
            double val = static_cast<double>(*ptr);
            if(val < *min_ext)  *min_ext = val;
            if(val > *max_ext)  *max_ext = val;
        }
    }
        break;

    case CV_16SC1:
    {
        short* ptr = reinterpret_cast<short*>(pVD_In->pMA_full()->data);
        *min_ext = *max_ext = static_cast<double>(*ptr);
        for(int px = 0; px < vol; px++, ptr++)
        {
            double val = static_cast<double>(*ptr);
            if(val < *min_ext)  *min_ext = val;
            if(val > *max_ext)  *max_ext = val;
        }
    }
        break;

    case CV_32SC1:
    {
        int* ptr = reinterpret_cast<int*>(pVD_In->pMA_full()->data);
        *min_ext = *max_ext = static_cast<double>(*ptr);
        for(int px = 0; px < vol; px++, ptr++)
        {
            double val = static_cast<double>(*ptr);
            if(val < *min_ext)  *min_ext = val;
            if(val > *max_ext)  *max_ext = val;
        }
    }
        break;

    case CV_32FC1:
    {
        float* ptr = reinterpret_cast<float*>(pVD_In->pMA_full()->data);
        *min_ext = *max_ext = static_cast<double>(*ptr);
        for(int px = 0; px < vol; px++, ptr++)
        {
            double val = static_cast<double>(*ptr);
            if(val < *min_ext)  *min_ext = val;
            if(val > *max_ext)  *max_ext = val;
        }
    }
        break;

    case CV_64FC1:
    {
        double* ptr = reinterpret_cast<double*>(pVD_In->pMA_full()->data);
        *min_ext = *max_ext = *ptr;
        for(int px = 0; px < vol; px++, ptr++)
        {
            double val = *ptr;
            if(val < *min_ext)  *min_ext = val;
            if(val > *max_ext)  *max_ext = val;
        }
    }
        break;

    //2 Channels ------------------------------------------------------

    case CV_8UC2:
    {
        Vec2b* ptr = reinterpret_cast<Vec2b*>(pVD_In->pMA_full()->data);
        *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
        for(int px = 0; px < vol; px++, ptr++)
            for(int c = 0; c < 2; c++)
            {
                double val = static_cast<double>((*ptr)[c]);
                if(val < *min_ext)  *min_ext = val;
                if(val > *max_ext)  *max_ext = val;
            }
    }
        break;

    case CV_16UC2:
    {
        Vec2w* ptr = reinterpret_cast<Vec2w*>(pVD_In->pMA_full()->data);
        *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
        for(int px = 0; px < vol; px++, ptr++)
            for(int c = 0; c < 2; c++)
            {
                double val = static_cast<double>((*ptr)[c]);
                if(val < *min_ext)  *min_ext = val;
                if(val > *max_ext)  *max_ext = val;
            }
    }
        break;

    case CV_16SC2:
    {
        Vec2s* ptr = reinterpret_cast<Vec2s*>(pVD_In->pMA_full()->data);
        *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
        for(int px = 0; px < vol; px++, ptr++)
            for(int c = 0; c < 2; c++)
            {
                double val = static_cast<double>((*ptr)[c]);
                if(val < *min_ext)  *min_ext = val;
                if(val > *max_ext)  *max_ext = val;
            }
    }
        break;

    case CV_32SC2:
    {
        Vec2i* ptr = reinterpret_cast<Vec2i*>(pVD_In->pMA_full()->data);
        *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
        for(int px = 0; px < vol; px++, ptr++)
            for(int c = 0; c < 2; c++)
            {
                double val = static_cast<double>((*ptr)[c]);
                if(val < *min_ext)  *min_ext = val;
                if(val > *max_ext)  *max_ext = val;
            }
    }
        break;

    case CV_32FC2:
    {
        Vec2f* ptr = reinterpret_cast<Vec2f*>(pVD_In->pMA_full()->data);
        *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
        for(int px = 0; px < vol; px++, ptr++)
            for(int c = 0; c < 2; c++)
            {
                double val = static_cast<double>((*ptr)[c]);
                if(val < *min_ext)  *min_ext = val;
                if(val > *max_ext)  *max_ext = val;
            }
    }
        break;

    case CV_64FC2:
    {
        Vec2d* ptr = reinterpret_cast<Vec2d*>(pVD_In->pMA_full()->data);
        *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
        for(int px = 0; px < vol; px++, ptr++)
            for(int c = 0; c < 2; c++)
            {
                double val = static_cast<double>((*ptr)[c]);
                if(val < *min_ext)  *min_ext = val;
                if(val > *max_ext)  *max_ext = val;
            }
    }
        break;

        //3 Channels ------------------------------------------------------

        case CV_8UC3:
        {
            Vec3b* ptr = reinterpret_cast<Vec3b*>(pVD_In->pMA_full()->data);
            *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
            for(int px = 0; px < vol; px++, ptr++)
                for(int c = 0; c < 3; c++)
                {
                    double val = static_cast<double>((*ptr)[c]);
                    if(val < *min_ext)  *min_ext = val;
                    if(val > *max_ext)  *max_ext = val;
                }
        }
            break;

        case CV_16UC3:
        {
            Vec3w* ptr = reinterpret_cast<Vec3w*>(pVD_In->pMA_full()->data);
            *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
            for(int px = 0; px < vol; px++, ptr++)
                for(int c = 0; c < 3; c++)
                {
                    double val = static_cast<double>((*ptr)[c]);
                    if(val < *min_ext)  *min_ext = val;
                    if(val > *max_ext)  *max_ext = val;
                }
        }
            break;

        case CV_16SC3:
        {
            Vec3s* ptr = reinterpret_cast<Vec3s*>(pVD_In->pMA_full()->data);
            *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
            for(int px = 0; px < vol; px++, ptr++)
                for(int c = 0; c < 3; c++)
                {
                    double val = static_cast<double>((*ptr)[c]);
                    if(val < *min_ext)  *min_ext = val;
                    if(val > *max_ext)  *max_ext = val;
                }
        }
            break;

        case CV_32SC3:
        {
            Vec3i* ptr = reinterpret_cast<Vec3i*>(pVD_In->pMA_full()->data);
            *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
            for(int px = 0; px < vol; px++, ptr++)
                for(int c = 0; c < 3; c++)
                {
                    double val = static_cast<double>((*ptr)[c]);
                    if(val < *min_ext)  *min_ext = val;
                    if(val > *max_ext)  *max_ext = val;
                }
        }
            break;

        case CV_32FC3:
        {
            Vec3f* ptr = reinterpret_cast<Vec3f*>(pVD_In->pMA_full()->data);
            *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
            for(int px = 0; px < vol; px++, ptr++)
                for(int c = 0; c < 3; c++)
                {
                    double val = static_cast<double>((*ptr)[c]);
                    if(val < *min_ext)  *min_ext = val;
                    if(val > *max_ext)  *max_ext = val;
                }
        }
            break;

        case CV_64FC3:
        {
            Vec3d* ptr = reinterpret_cast<Vec3d*>(pVD_In->pMA_full()->data);
            *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
            for(int px = 0; px < vol; px++, ptr++)
                for(int c = 0; c < 3; c++)
                {
                    double val = static_cast<double>((*ptr)[c]);
                    if(val < *min_ext)  *min_ext = val;
                    if(val > *max_ext)  *max_ext = val;
                }
        }
            break;

        //4 Channels ------------------------------------------------------

        case CV_8UC4:
        {
            Vec4b* ptr = reinterpret_cast<Vec4b*>(pVD_In->pMA_full()->data);
            *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
            for(int px = 0; px < vol; px++, ptr++)
                for(int c = 0; c < 4; c++)
                {
                    double val = static_cast<double>((*ptr)[c]);
                    if(val < *min_ext)  *min_ext = val;
                    if(val > *max_ext)  *max_ext = val;
                }
        }
            break;

        case CV_16UC4:
        {
            Vec4w* ptr = reinterpret_cast<Vec4w*>(pVD_In->pMA_full()->data);
            *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
            for(int px = 0; px < vol; px++, ptr++)
                for(int c = 0; c < 4; c++)
                {
                    double val = static_cast<double>((*ptr)[c]);
                    if(val < *min_ext)  *min_ext = val;
                    if(val > *max_ext)  *max_ext = val;
                }
        }
            break;

        case CV_16SC4:
        {
            Vec4s* ptr = reinterpret_cast<Vec4s*>(pVD_In->pMA_full()->data);
            *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
            for(int px = 0; px < vol; px++, ptr++)
                for(int c = 0; c < 4; c++)
                {
                    double val = static_cast<double>((*ptr)[c]);
                    if(val < *min_ext)  *min_ext = val;
                    if(val > *max_ext)  *max_ext = val;
                }
        }
            break;

        case CV_32SC4:
        {
            Vec4i* ptr = reinterpret_cast<Vec4i*>(pVD_In->pMA_full()->data);
            *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
            for(int px = 0; px < vol; px++, ptr++)
                for(int c = 0; c < 4; c++)
                {
                    double val = static_cast<double>((*ptr)[c]);
                    if(val < *min_ext)  *min_ext = val;
                    if(val > *max_ext)  *max_ext = val;
                }
        }
            break;

        case CV_32FC4:
        {
            Vec4f* ptr = reinterpret_cast<Vec4f*>(pVD_In->pMA_full()->data);
            *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
            for(int px = 0; px < vol; px++, ptr++)
                for(int c = 0; c < 4; c++)
                {
                    double val = static_cast<double>((*ptr)[c]);
                    if(val < *min_ext)  *min_ext = val;
                    if(val > *max_ext)  *max_ext = val;
                }
        }
            break;

        case CV_64FC4:
        {
            Vec4d* ptr = reinterpret_cast<Vec4d*>(pVD_In->pMA_full()->data);
            *min_ext = *max_ext = static_cast<double>((*ptr)[0]);
            for(int px = 0; px < vol; px++, ptr++)
                for(int c = 0; c < 4; c++)
                {
                    double val = static_cast<double>((*ptr)[c]);
                    if(val < *min_ext)  *min_ext = val;
                    if(val > *max_ext)  *max_ext = val;
                }
        }
            break;

    default:
        return ER_type_bad;
    }

    return ER_okay;
}

int D_VisDat_Proc::Calc_Hist_Multi(vector<vector<double> > *vv_hist, D_VisDat_Obj *pVD_In, bool uniform, bool accum, unsigned int class_count, vector<double> *v_min_ext, vector<double> *v_max_ext, vector<double> *v_step_ext)
{
    if(pVD_In->pMA_full()->empty()) return ER_okay;

    //clear and resize
    vv_hist->clear();
    v_min_ext->clear();
    v_max_ext->clear();
    v_step_ext->clear();
    vv_hist->resize(pVD_In->pMA_full()->channels());
    v_min_ext->resize(pVD_In->pMA_full()->channels());
    v_max_ext->resize(pVD_In->pMA_full()->channels());
    v_step_ext->resize(pVD_In->pMA_full()->channels());

    switch (pVD_In->pMA_full()->channels()) {

    case 1:
    {
        int ER = Calc_Hist_1C(
                    &((*vv_hist)[0]),
                    pVD_In,
                    uniform,
                    accum,
                    class_count,
                    &((*v_min_ext)[0]),
                    &((*v_max_ext)[0]),
                    &((*v_step_ext)[0]));
        if(ER != ER_okay)   return ER;
    }
        break;

    case 2:
    case 3:
    case 4:
    {
        for(int c = 0; c < pVD_In->pMA_full()->channels(); c++)
        {
            D_VisDat_Obj VD_channel_tmp;
            int ER = D_VisDat_Proc::Channels_Split(
                        &VD_channel_tmp,
                        pVD_In,
                        c);
            if(ER != ER_okay)   return ER;

            ER = Calc_Hist_1C(
                        &((*vv_hist)[c]),
                        &VD_channel_tmp,
                        uniform,
                        accum,
                        class_count,
                        &((*v_min_ext)[c]),
                        &((*v_max_ext)[c]),
                        &((*v_step_ext)[c]));
            if(ER != ER_okay)   return ER;
        }
    }
        break;

    default:
        return ER_channel_bad;
    }

    return ER_okay;
}

int D_VisDat_Proc::Calc_Hist_1C(vector<double> *v_hist, D_VisDat_Obj *pVD_In, bool uniform, bool accum, unsigned int class_count, double *min_ext, double *max_ext, double *step_ext)
{
    if(pVD_In->pMA_full()->empty())             return ER_empty;
    if(pVD_In->pMA_full()->channels() != 1)     return ER_channel_bad;

    //==========================================================  read and export values
    //qDebug() << "read and export values";
    unsigned int vol = pVD_In->pDim()->size_PixelCount();

    //==========================================================  allocate memory for hist
    //qDebug() << "allocate memory for hist";
    v_hist->resize(class_count, 0);


    //==========================================================  range & step

    //default values
    *min_ext = 0;
    *max_ext = 0;

    //calc
    int ER = Calc_MinMax(
                pVD_In,
                min_ext,
                max_ext);
    if(ER != ER_okay)
        return ER;

    double min      = *min_ext;
    double max      = *max_ext;
    double range    = max - min;
    double step     = range / (class_count - 1);

    *step_ext = step;

    //qDebug() << "min" << min;
    //qDebug() << "max" << max;
    //qDebug() << "range" << range;
    //qDebug() << "class_count" << class_count;
    //qDebug() << "step" << step;


    //==========================================================  calc hist
    //qDebug() << "calc hist";
    switch (pVD_In->pMA_full()->type()) {

    case CV_8UC1://-----------------------------------------------
    {
        //qDebug() << "CV_8UC1";
        uchar* ptr = reinterpret_cast<uchar*>(pVD_In->pMA_full()->data);    //ptr input
        for (unsigned int px = 0; px < vol; px++, ptr++)                    //loop pixels
        {
            uchar           val = *ptr;                                     //read value
            unsigned int    pos = (val - min) / step;                       //calc position
            (*v_hist)[pos]++;                                               //cummmulate hist
        }
    }
        break;

    case CV_8SC1://-----------------------------------------------
    {
        //qDebug() << "CV_8SC1";
        char* ptr = reinterpret_cast<char*>(pVD_In->pMA_full()->data);
        for (unsigned int px = 0; px < vol; px++, ptr++)       //loop pixels
        {
            char           val = *ptr;                          //read value
            unsigned int    pos = (val - min) / step;           //calc position
            (*v_hist)[pos]++;                                   //cummmulate hist
        }
    }
        break;


    case CV_16UC1://----------------------------------------------
    {
        //qDebug() << "CV_16UC1";
        ushort* ptr = reinterpret_cast<ushort*>(pVD_In->pMA_full()->data);
        for (unsigned int px = 0; px < vol; px++, ptr++)       //loop pixels
        {
            ushort          val = *ptr;                         //read value
            unsigned int    pos = (val - min) / step;           //calc position
            (*v_hist)[pos]++;                                   //cummmulate hist
        }
    }
        break;

    case CV_16SC1://-----------------------------------------------
    {
        //qDebug() << "CV_16SC1";
        short* ptr = reinterpret_cast<short*>(pVD_In->pMA_full()->data);
        for (unsigned int px = 0; px < vol; px++, ptr++)       //loop pixels
        {
            short           val = *ptr;                         //read value
            unsigned int    pos = (val - min) / step;           //calc position
            (*v_hist)[pos]++;                                   //cummmulate hist
        }
    }
        break;

    case CV_32SC1://----------------------------------------------
    {
        //qDebug() << "CV_32SC1";
        int* ptr = reinterpret_cast<int*>(pVD_In->pMA_full()->data);
        for (unsigned int px = 0; px < vol; px++, ptr++)       //loop pixels
        {
            float           val = *ptr;                         //read value
            unsigned int    pos = (val - min) / step;           //calc position
            (*v_hist)[pos]++;                                   //cummmulate hist
        }
    }
        break;

    case CV_32FC1://----------------------------------------------
    {
        //qDebug() << "CV_32FC1";
        float* ptr = reinterpret_cast<float*>(pVD_In->pMA_full()->data);
        for (unsigned int px = 0; px < vol; px++, ptr++)       //loop pixels
        {
            float           val = *ptr;                         //read value
            unsigned int    pos = (val - min) / step;           //calc position
            (*v_hist)[pos]++;                                   //cummmulate hist
        }
    }
        break;

    case CV_64FC1://----------------------------------------------
    {
        //qDebug() << "CV_64FC1";
        double* ptr = reinterpret_cast<double*>(pVD_In->pMA_full()->data);
        for (unsigned int px = 0; px < vol; px++, ptr++)       //loop pixels
        {
            double          val = *ptr;                         //read value
            unsigned int    pos = (val - min) / step;           //calc position
            (*v_hist)[pos]++;                                   //cummmulate hist
        }
    }
        break;

    default://--------------------------------------------------
        return ER_type_bad;
        break;
    }


    //==========================================================  accumulate/uniform
    //qDebug() << "accumulate/uniform";
    if(accum)
        for(unsigned int v = 1; v < v_hist->size(); v++)
            (*v_hist)[v] += (*v_hist)[v - 1];

    if(uniform)
        for(unsigned int v = 0; v < v_hist->size(); v++)
            (*v_hist)[v] /= (double)vol;


    //qDebug() << "hist success";
    return ER_okay;
}

int D_VisDat_Proc::Calc_Hist_1C_8bit(vector<double> *v_hist, D_VisDat_Obj *pVD_In, bool uniform, bool accum)
{
    if(pVD_In->pMA_full()->empty()) return ER_empty;
    if(pVD_In->type() != CV_8UC1)   return ER_type_bad;

    //clear & resize
    v_hist->clear();
    v_hist->resize(256, 0);

    //vol
    int vol = pVD_In->pDim()->size_PixelCount();

    //calc hist
    uchar* ptr = reinterpret_cast<uchar*>(pVD_In->pMA_full()->data);    //ptr input
    for (int px = 0; px < vol; px++, ptr++)                    //loop pixels
        (*v_hist)[*ptr]++;                                              //hist

    //accumulate
    if(accum)
        for(int v = 1; v < v_hist->size(); v++)
            (*v_hist)[v] += (*v_hist)[v - 1];

    //uniform
    if(uniform)
        for(int v = 0; v < v_hist->size(); v++)
            (*v_hist)[v] /= static_cast<double>(vol);

    return ER_okay;
}

int D_VisDat_Proc::Calc_DataVector_1C(vector<double> *v_data_out, D_VisDat_Obj *pVD_In, bool ignore_zeros)
{
    //Errors
    if(pVD_In->pMA_full()->empty())             return ER_empty;
    if(pVD_In->pMA_full()->channels() != 1)     return ER_channel_bad;

    //size
    int vol = pVD_In->pDim()->size_PixelCount();

    //clear
    v_data_out->clear();

    //do the stuff
    switch (pVD_In->pMA_full()->type()) {

    case CV_8UC1:
    {
        uchar* ptr = reinterpret_cast<uchar*>(pVD_In->pMA_full()->data);
        for(int px = 0; px < vol; px++, ptr++)
            if(*ptr != 0 || !ignore_zeros)
                v_data_out->push_back(static_cast<double>(*ptr));
    }
        break;

    case CV_8SC1:
    {
        char* ptr = reinterpret_cast<char*>(pVD_In->pMA_full()->data);
        for(int px = 0; px < vol; px++, ptr++)
            if(*ptr != 0 || !ignore_zeros)
                v_data_out->push_back(static_cast<double>(*ptr));
    }
        break;

    case CV_16UC1:
    {
        ushort* ptr = reinterpret_cast<ushort*>(pVD_In->pMA_full()->data);
        for(int px = 0; px < vol; px++, ptr++)
            if(*ptr != 0 || !ignore_zeros)
                v_data_out->push_back(static_cast<double>(*ptr));
    }
        break;

    case CV_16SC1:
    {
        short* ptr = reinterpret_cast<short*>(pVD_In->pMA_full()->data);
        for(int px = 0; px < vol; px++, ptr++)
            if(*ptr != 0 || !ignore_zeros)
                v_data_out->push_back(static_cast<double>(*ptr));
    }
        break;

    case CV_32SC1:
    {
        int* ptr = reinterpret_cast<int*>(pVD_In->pMA_full()->data);
        for(int px = 0; px < vol; px++, ptr++)
            if(*ptr != 0 || !ignore_zeros)
                v_data_out->push_back(static_cast<double>(*ptr));
    }
        break;

    case CV_32FC1:
    {
        float* ptr = reinterpret_cast<float*>(pVD_In->pMA_full()->data);
        for(int px = 0; px < vol; px++, ptr++)
            if(*ptr != 0 || !ignore_zeros)
                v_data_out->push_back(static_cast<double>(*ptr));
    }
        break;

    case CV_64FC1:
    {
        double* ptr = reinterpret_cast<double*>(pVD_In->pMA_full()->data);
        for(int px = 0; px < vol; px++, ptr++)
            if(*ptr != 0 || !ignore_zeros)
                v_data_out->push_back(*ptr);
    }
        break;

    default:
        break;
    }

    return ER_okay;
}
