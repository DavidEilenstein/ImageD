#include "d_physics.h"

D_Physics::D_Physics()
{

}

double D_Physics::FieldStrength(Mat Position, Mat Source, double fieldstrength, double phaseoffset_rad, double wavelength_m)
{
    if(Position.empty())                            return 0;
    if(Position.type() != CV_64FC1)                 return 0;
    if(Position.rows != 3 || Position.cols != 1)    return 0;
    if(Source.empty())                              return 0;
    if(Source.type() != CV_64FC1)                   return 0;
    if(Source.rows != 3 || Position.cols != 1)      return 0;
    if(wavelength_m <= 0)                           return 0;

    //distance to phase
    /*
    double dist_meters      = sqrt(
                (Position.at<double>(0, 0) - Source.at<double>(0, 0)) * (Position.at<double>(0, 0) - Source.at<double>(0, 0)) +
                (Position.at<double>(1, 0) - Source.at<double>(1, 0)) * (Position.at<double>(1, 0) - Source.at<double>(1, 0)) +
                (Position.at<double>(2, 0) - Source.at<double>(2, 0)) * (Position.at<double>(2, 0) - Source.at<double>(2, 0)));
                */
    double dist_meters      = norm(Source, Position);
    double dist_wavelength  = dist_meters / wavelength_m;
    double phase_full       = dist_wavelength * PI_2_0 + phaseoffset_rad;
    double phase_single     = phase_full - static_cast<int>(phase_full / PI_2_0) * PI_2_0;

    //phase to fieldstrength
    return fieldstrength * cos(phase_single);
}

double D_Physics::FieldStrength(Point3d Position, Point3d Source, double fieldstrength, double phaseoffset_rad, double wavelength_m)
{
    if(wavelength_m <= 0)                           return 0;

    //distance to phase
    double dist_meters      = norm(Position - Source);
    double dist_wavelength  = dist_meters / wavelength_m;
    double phase_full       = dist_wavelength * PI_2_0 + phaseoffset_rad;
    double phase_single     = phase_full - static_cast<int>(phase_full / PI_2_0) * PI_2_0;

    //phase to fieldstrength
    return fieldstrength * cos(phase_single);
}

double D_Physics::Interference(Mat Position, vector<Mat> v_Source, vector<double> v_fieldstrength, vector<double> v_phaseoffset_rad, double wavelength_m)
{
    if(v_Source.empty())                            return 0;
    if(v_fieldstrength.empty())                     return 0;
    if(v_phaseoffset_rad.empty())                   return 0;
    if(v_Source.size() != v_fieldstrength.size())   return 0;
    if(v_Source.size() != v_phaseoffset_rad.size()) return 0;
    if(wavelength_m <= 0)                           return 0;
    if(Position.empty())                            return 0;
    if(Position.type() != CV_64FC1)                 return 0;
    if(Position.rows != 3 || Position.cols != 1)    return 0;
    for(size_t i = 0; i < v_Source.size(); i++)
    {
        if(v_Source[i].empty())                             return 0;
        if(v_Source[i].type() != Position.type())           return 0;
        if(v_Source[i].size() != Position.size())           return 0;
    }

    //result
    double fieldstrength_interference = 0;

    //loop sources
    for(size_t i = 0; i < v_Source.size(); i++)
    {
        //distance to phase
        double dist_meters      = norm(Position - v_Source[i]);
        double dist_wavelength  = dist_meters / wavelength_m;
        double phase_full       = dist_wavelength * PI_2_0 + v_phaseoffset_rad[i];
        double phase_single     = phase_full - static_cast<int>(phase_full / PI_2_0) * PI_2_0;

        //phase to fieldstrength
        fieldstrength_interference += v_fieldstrength[i] * cos(phase_single);
    }

    return fieldstrength_interference;
}

double D_Physics::Interference(Point3d Position, vector<Point3d> v_Source, vector<double> v_fieldstrength, vector<double> v_phaseoffset_rad, double wavelength_m)
{
    if(v_Source.empty())                            return 0;
    if(v_fieldstrength.empty())                     return 0;
    if(v_phaseoffset_rad.empty())                   return 0;
    if(v_Source.size() != v_fieldstrength.size())   return 0;
    if(v_Source.size() != v_phaseoffset_rad.size()) return 0;
    if(wavelength_m <= 0)                           return 0;

    //result
    double fieldstrength_interference = 0;

    //loop sources
    for(size_t i = 0; i < v_Source.size(); i++)
    {
        //distance to phase
        double dist_meters      = norm(Position - v_Source[i]);
        double dist_wavelength  = dist_meters / wavelength_m;
        double phase_full       = dist_wavelength * PI_2_0 + v_phaseoffset_rad[i];
        double phase_single     = phase_full - static_cast<int>(phase_full / PI_2_0) * PI_2_0;

        //phase to fieldstrength
        fieldstrength_interference += v_fieldstrength[i] * cos(phase_single);
    }

    return fieldstrength_interference;
}

function<double (double v)> D_Physics::Force_Drag(double rho, double A, double cw)
{
    double factor = 0.5 * rho * A * cw;
    return [factor](double v)
        {
            return  factor * v * v;
    };
}

double D_Physics::Force_Gravity(double m)
{
    return  PH_g_earth * m;
}

double D_Physics::Force_Upthrust(double V, double rho)
{
    return PH_g_earth * V * rho;
}
