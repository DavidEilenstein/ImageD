#include "d_physics.h"

D_Physics::D_Physics()
{

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
