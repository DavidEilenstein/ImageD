/************************************
 *   added:     11.02.2019          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_math.h"

D_Math::D_Math()
{

}

function<double (double)> D_Math::Function_1D_to_1D(int type, double a, double b, double c, double d)
{
    a; b; c; d;//dirty way to prevent "unsed variable" warning

    switch (type) {

    case c_MATH_1D_TO_1D_X:
        return [](double x)
        {
            return x;
        };

    case c_MATH_1D_TO_1D_X_power_2:
        return [](double x)
        {
            return x * x;
        };

    case c_MATH_1D_TO_1D_A_times_X:
        return [a](double x)
        {
            return a * x;
        };

    case c_MATH_1D_TO_1D_X_FACULTY:
        return [](double x)
        {
            uint fac = 1;
            for(uint i = 1; i < x; i++)
                fac *= i;
            return fac;
        };

    case c_MATH_1D_TO_1D_BINOMIAL_X_OUTOF_D:
        return [a, b, d](double x)
        {
            x = a * x + b;

            return Binomial_Coefficient(d, x);
        };

    case c_MATH_1D_TO_1D_GAMMA:
        return [b, c, d](double x)
        {
            double range = c - b;
            x = (x - c) / range;

            return pow(x, d);
        };

    case c_MATH_1D_TO_1D_LOG_CENTERED:
        return [b](double x)
        {
            x = x - b;

            if(x < 0)
                return -log(-x + 1);
            else if(x > 0)
                return log(x + 1);
            else
                return 0.0;
        };

    default:
        return [](double x)
        {
            x;
            return NAN;
        };
    }
}

function<double (double x, double y)> D_Math::Function_2D_to_1D(int type, double a, double b, double c, double d, double e, double f, double nan_val, double inf_val)
{
    switch (type) {

    case c_MATH_2D_TO_1D_const_E:
        return [e](double x, double y)
        {
            x; y;
            return e;
        };

    case c_MATH_2D_TO_1D_X:
        return [a, b](double x, double y)
        {
            x = a * x + b;
            y;

            return x;
        };

    case c_MATH_2D_TO_1D_Y:
        return [c, d](double x, double y)
        {
            x;
            y = c * y + d;

            return y;
        };

    case c_MATH_2D_TO_1D_X_plus_Y:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return x + y;
        };

    case c_MATH_2D_TO_1D_X_minus_Y:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return x - y;
        };

    case c_MATH_2D_TO_1D_X_minus_Y_abs:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return abs(x - y);
        };




    case c_MATH_2D_TO_1D_X_times_Y:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return x * y;
        };

    case c_MATH_2D_TO_1D_X_divby_Y:
        return [a, b, c, d, inf_val](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            if(y == 0)
                return inf_val;
            else
                return x / y;
        };

    case c_MATH_2D_TO_1D_Y_divby_X:
        return [a, b, c, d, inf_val](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            if(x == 0)
                return inf_val;
            else
                return y / x;
        };




    case c_MATH_2D_TO_1D_X_equals_Y:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<double>(x == y + e);
        };

    case c_MATH_2D_TO_1D_X_greater_Y:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<double>(x > y + e);
        };

    case c_MATH_2D_TO_1D_X_smaller_Y:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<double>(x < y + e);
        };




    case c_MATH_2D_TO_1D_X_difference_Y_equal_E:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<double>((x - y) == e);
        };

    case c_MATH_2D_TO_1D_X_difference_Y_greater_E:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<double>((x - y) > e);
        };

    case c_MATH_2D_TO_1D_X_difference_Y_smaller_E:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<double>((x - y) < e);
        };

    case c_MATH_2D_TO_1D_X_difference_Y_smaller_F_greater_E:
        return [a, b, c, d, e, f](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<double>((e < (x - y)) && ((x - y) < f));
        };

    case c_MATH_2D_TO_1D_X_difference_Y_equal_E_abs:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<double>(abs(x - y) == e);
        };

    case c_MATH_2D_TO_1D_X_difference_Y_greater_E_abs:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<double>(abs(x - y) > e);
        };

    case c_MATH_2D_TO_1D_X_difference_Y_smaller_E_abs:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<double>(abs(x - y) < e);
        };

    case c_MATH_2D_TO_1D_X_difference_Y_smaller_F_greater_E_abs:
        return [a, b, c, d, e, f](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<double>((e < abs(x - y)) && (abs(x - y) < f));
        };



    case c_MATH_2D_TO_1D_X_Y_norm:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<double>(sqrt(x * x + y * y));
        };

    case c_MATH_2D_TO_1D_X_Y_atan2:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<double>(atan2(y, x));
        };


    case c_MATH_2D_TO_1D_SIN_X_Y:
        return [a, c, d, e, f](double x, double y)
        {
            x = a * x;
            y = c * y;

            return static_cast<double>(e * sin(x + y + d) + f);
        };



    case c_MATH_2D_TO_1D_SIN_X_Y_PI:
        return [a, b, c, d, e, f](double x, double y)
        {
            x = (a*x)/b;
            y = (y*c)/d;

            return static_cast<double>(e * sin(PI_2_0 * (x + y + f)));
        };

    case c_MATH_2D_TO_1D_SINC_ABS_X_Y:
        return [a, b, c, d, e, f, inf_val](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            double arg_sinc = sqrt(x * x + y * y);

            if(arg_sinc == 0.0)
                return inf_val;
            else
                return static_cast<double>(e * (sin(arg_sinc) / arg_sinc) + f);
        };

    case c_MATH_2D_TO_1D_GAUSS:
        return [a, b, c, d, e, f](double x, double y)
        {
            x = x + b;
            y = y + d;

            double e_arg = - ((a * x * x) + (f * x * y) + (c * y * y));

            return static_cast<double>(e * exp(e_arg));
        };

    case c_MATH_2D_TO_1D_LN_GAUSS:
        return [a, b, c, d, e, f](double x, double y)
        {
            x = x + b;
            y = y + d;

            return static_cast<double>(e * - ((a * x * x) + (f * x * y) + (c * y * y)));
        };

    case c_MATH_2D_TO_1D_2SPHERES:
        return [a, b, c, d, e, f](double x, double y)
        {
            double r_1_square = (x - a) * (x - a) + (y - b) * (y - b) + c * c;
            double r_2_square = x * x + y * y + e * e;
            double r_delta = sqrt(r_1_square) - sqrt(r_2_square);
            return static_cast<double>(1 + cos(f * r_delta + d));
        };

    case c_MATH_2D_TO_1D_FOURIER_MATRIX_COSINUS:
        return [a, b, c, d, e, f](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;
            double angle = (PI_2_0 * x * y) / f;

            return static_cast<double>(e * cos(angle));
        };

    case c_MATH_2D_TO_1D_FOURIER_MATRIX_SINUS:
        return [a, b, c, d, e, f](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;
            double angle = (PI_2_0 * x * y) / f;

            return static_cast<double>(e * sin(angle));
        };

    case c_MATH_2D_TO_1D_BINOMIAL_XoutofE_times_YoutofF:
        return [a, b, c, d, e, f](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return Binomial_Coefficient(e, x) * Binomial_Coefficient(f, y);
        };

    case c_MATH_2D_TO_1D_BINOMIAL_XoutofE_times_YoutofF_normed:
        return [a, b, c, d, e, f](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            double sum = 0;
            for(int xi = 0; xi <= e; xi++)
                for(int yi = 0; yi <= f; yi++)
                    sum += Binomial_Coefficient(e, xi) * Binomial_Coefficient(f, yi);

            double weight = 1.0 / sum;

            return Binomial_Coefficient(e, x) * Binomial_Coefficient(f, y) * weight;
        };

    case c_MATH_2D_TO_1D_STRIPES_RECT_X_Y:
        return [a, b, c, d, e, f](double x, double y)
        {
            //rotataion angles to rad
            double f_rad = Grad2Rad * f;

            //rotate
            double x1 = x * cos(f_rad) - y * sin(f_rad);
          //double y2 = x * sin(f_rad) + y * cos(f_rad);

            //shift
            double x2 = x1 - a;

            //periodic (kind of modulo)
            double x3 = abs(x2 - static_cast<double>(static_cast<int>(x2/b)) * b);

            //check & return
            if(x3 <= c/2 || x3 >= b-c/2)
                return  e + d;
            else
                return -e + d;
        };

    case c_MATH_2D_TO_1D_ELLIPSE:
        return [a, b, c, d, e, f](double x, double y)
        {
            //shift
            double x1 = x - b;
            double y1 = y - d;

            //rotataion angles to rad
            double f_rad = Grad2Rad * f;

            //rotate
            double x2 = x1 * cos(f_rad) - y1 * sin(f_rad);
            double y2 = x1 * sin(f_rad) + y1 * cos(f_rad);

            return (x2 * x2)/(a * a) + (y2 * y2)/(c * c) <= 1 ? e : 0;
        };

    case c_MATH_2D_TO_1D_ZERNIKE_NM:
    {
        //a = radius of definition circle
        //b = n
        //c = m

        //force n to fit definition or return 0
        int n = static_cast<int>(b);
        if(n<0)
            return Function_2D_to_1D(c_MATH_2D_TO_1D_const_E);

        //force m to fot definition or return 0
        int m = static_cast<int>(c);
        if((m<-n) || (m>n) || ((n%2) && !(abs(m)%2)) || (!(n%2) && (abs(m)%2)))
            return Function_2D_to_1D(c_MATH_2D_TO_1D_const_E);

        //for radial polynom save factors only dependant on n and m in a vector
        vector<double> vR_factors(((n-abs(m))/2)+1);
        for(int s = 0; s <= ((n-abs(m))/2); s++)
            vR_factors[s] = (pow(-1, s) * tgamma(n-s+1)) / (tgamma(s+1) * tgamma(0.5 * (n+abs(m) - s) + 1) * tgamma(0.5 * (n-abs(m) - s) + 1));

        return [a, n, m, vR_factors, nan_val](double x, double y)
        {
            //0|0 to center and range check
            x = x - a;
            y = y - a;

            //normalized polar coordinates and check range
            double r = sqrt(x*x + y*y) / a;     //rho
            double t = atan2(y, x);             //theta
            if(r>1)
                return 0.0;

            //angle dependent function
            double A = m>=0 ? cos(m*t) : sin(abs(m)*t);

            //normalization
            double N = m!=0 ? sqrt(2*(n+1)) : sqrt(n+1);

            //radial polynom
            double R = 0.0;
            for(int s = 0; s <= ((n-abs(m))/2); s++)
                R += pow(r, n-2*s) * vR_factors[s];

            //combine elements, return
            double z = N*R*A;
            if(z!=z)            //check if nan
                return nan_val;
            else
                return z;
        };
    }

    case c_MATH_2D_TO_1D_ZERNIKE_J:
        {
            //a = radius of definition circle
            //b = j

            int n = ceil((-3 + sqrt(9 + 8*b))/2);
            int m = 2*b - n*(n+2);

            return Function_2D_to_1D(c_MATH_2D_TO_1D_ZERNIKE_NM, a, n, m, 0, 0, 0, nan_val, 0);
        };

    default:
        return [nan_val](double x, double y)
        {
            x; y;
            return nan_val;
        };
    }
}

function<uchar (double x, double y)> D_Math::Function_2D_to_1D_8bit(int type, double a, double b, double c, double d, double e, double f, uchar nan_val, uchar inf_val)
{
    switch (type) {

    case c_MATH_2D_TO_1D_const_E:
        return [e](double x, double y)
        {
            x; y;
            return static_cast<uchar>(e);
        };

    case c_MATH_2D_TO_1D_X:
        return [a, b](double x, double y)
        {
            x = a * x + b;
            y;

            return static_cast<uchar>(x);
        };

    case c_MATH_2D_TO_1D_Y:
        return [c, d](double x, double y)
        {
            x;
            y = c * y + d;

            return static_cast<uchar>(y);
        };

    case c_MATH_2D_TO_1D_X_plus_Y:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>(x + y);
        };

    case c_MATH_2D_TO_1D_X_minus_Y:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>(x - y);
        };

    case c_MATH_2D_TO_1D_X_minus_Y_abs:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>(abs(x - y));
        };




    case c_MATH_2D_TO_1D_X_times_Y:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>(x * y);
        };

    case c_MATH_2D_TO_1D_X_divby_Y:
        return [a, b, c, d, inf_val](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            if(y == 0)
                return inf_val;
            else
                return static_cast<uchar>(x / y);
        };

    case c_MATH_2D_TO_1D_Y_divby_X:
        return [a, b, c, d, inf_val](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            if(x == 0)
                return inf_val;
            else
                return static_cast<uchar>(y / x);
        };




    case c_MATH_2D_TO_1D_X_equals_Y:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>(x == y + e);
        };

    case c_MATH_2D_TO_1D_X_greater_Y:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>(x > y + e);
        };

    case c_MATH_2D_TO_1D_X_smaller_Y:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>(x < y + e);
        };




    case c_MATH_2D_TO_1D_X_difference_Y_equal_E:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>((x - y) == e);
        };

    case c_MATH_2D_TO_1D_X_difference_Y_greater_E:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>((x - y) > e);
        };

    case c_MATH_2D_TO_1D_X_difference_Y_smaller_E:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>((x - y) < e);
        };

    case c_MATH_2D_TO_1D_X_difference_Y_smaller_F_greater_E:
        return [a, b, c, d, e, f](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>((e < (x - y)) && ((x - y) < f));
        };

    case c_MATH_2D_TO_1D_X_difference_Y_equal_E_abs:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>(abs(x - y) == e);
        };

    case c_MATH_2D_TO_1D_X_difference_Y_greater_E_abs:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>(abs(x - y) > e);
        };

    case c_MATH_2D_TO_1D_X_difference_Y_smaller_E_abs:
        return [a, b, c, d, e](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>(abs(x - y) < e);
        };

    case c_MATH_2D_TO_1D_X_difference_Y_smaller_F_greater_E_abs:
        return [a, b, c, d, e, f](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>((e < abs(x - y)) && (abs(x - y) < f));
        };



    case c_MATH_2D_TO_1D_X_Y_norm:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>(sqrt(x * x + y * y));
        };

    case c_MATH_2D_TO_1D_X_Y_atan2:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            return static_cast<uchar>(atan2(y, x));
        };


    case c_MATH_2D_TO_1D_SIN_X_Y:
        return [a, c, d, e, f](double x, double y)
        {
            x = a * x;
            y = c * y;

            return static_cast<uchar>(e * sin(x + y + d) + f);
        };

    case c_MATH_2D_TO_1D_SIN_X_Y_PI:
        return [a, b, c, d, e, f](double x, double y)
        {
            x = (a*x)/b;
            y = (y*c)/d;

            return static_cast<uchar>(e * sin(PI_2_0 * (x + y + f)));
        };

    case c_MATH_2D_TO_1D_SINC_ABS_X_Y:
        return [a, b, c, d, e, f, inf_val](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;

            double arg_sinc = sqrt(x * x + y * y);

            if(arg_sinc == 0.0)
                return inf_val;
            else
                return static_cast<uchar>(e * (sin(arg_sinc) / arg_sinc) + f);
        };

    case c_MATH_2D_TO_1D_GAUSS:
        return [a, b, c, d, e, f](double x, double y)
        {
            x = x + b;
            y = y + d;

            double e_arg = - ((a * x * x) + (f * x * y) + (c * y * y));

            return static_cast<uchar>(e * exp(e_arg));
        };

    case c_MATH_2D_TO_1D_LN_GAUSS:
        return [a, b, c, d, e, f](double x, double y)
        {
            x = x + b;
            y = y + d;

            return static_cast<uchar>(e * - ((a * x * x) + (f * x * y) + (c * y * y)));
        };

    case c_MATH_2D_TO_1D_2SPHERES:
        return [a, b, c, d, e, f](double x, double y)
        {
            double r_1_square = (x - a) * (x - a) + (y - b) * (y - b) + c * c;
            double r_2_square = x * x + y * y + e * e;
            double r_delta = sqrt(r_1_square) - sqrt(r_2_square);
            return static_cast<uchar>(1 + cos(f * r_delta + d));
        };

    case c_MATH_2D_TO_1D_FOURIER_MATRIX_COSINUS:
        return [a, b, c, d, e, f](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;
            double angle = (PI_2_0 * x * y) / f;

            return static_cast<uchar>(e * cos(angle));
        };

    case c_MATH_2D_TO_1D_FOURIER_MATRIX_SINUS:
        return [a, b, c, d, e, f](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;
            double angle = (PI_2_0 * x * y) / f;

            return static_cast<uchar>(e * sin(angle));
        };

    case c_MATH_2D_TO_1D_ELLIPSE:
        return [a, b, c, d, e, f](double x, double y)
        {
            //shift
            double x1 = x - b;
            double y1 = y - d;

            //rotataion angles to rad
            double f_rad = Grad2Rad * f;

            //rotate
            double x2 = x1 * cos(f_rad) - y1 * sin(f_rad);
            double y2 = x1 * sin(f_rad) + y1 * cos(f_rad);

            return (x2 * x2)/(a * a) + (y2 * y2)/(c * c) <= 1 ? static_cast<uchar>(e) : 0;
        };

    default:
        //reuse double implementation, if no uchar-version is implemented
        return [type, a, b, c, d, e, f, nan_val, inf_val](double x, double y)
        {
            //cast data to double
            double x_double = static_cast<double>(x);
            double y_double = static_cast<double>(y);

            //use double function
            function<double (double, double)> f_double = Function_2D_to_1D(type, a, b, c, d, e, f, nan_val, inf_val);

            //and cast back to uchar
            return static_cast<uchar>(f_double(x_double, y_double));
        };
    }
}

function<complex<double> (complex<double> x, complex<double> y)> D_Math::Function_2D_to_1D_Complex(int type, double sx, double ox, double sy, double oy, double a, double b, double c, double d, double e, double f, double nan_val, double inf_val)
{
    switch (type) {

    case c_MATH_2D_TO_1D_COMPLEX_CONST_E_iF:
        return [e, f](complex<double> x, complex<double> y)
        {
            x; y;
            return complex<double>(e, f);
        };

    case c_MATH_2D_TO_1D_COMPLEX_X_iY:
        return [sx, ox, sy, oy](complex<double> x, complex<double> y)
        {
            x = sx * x + ox;
            y = sy * y + oy;
            return x + c_I * y;
        };

    case c_MATH_2D_TO_1D_COMPLEX_X_PLUS_Y:
        return [sx, ox, sy, oy](complex<double> x, complex<double> y)
        {
            x = sx * x + ox;
            y = sy * y + oy;
            return x + y;
        };

    case c_MATH_2D_TO_1D_COMPLEX_X_MINUS_Y:
        return [sx, ox, sy, oy](complex<double> x, complex<double> y)
        {
            x = sx * x + ox;
            y = sy * y + oy;
            return x - y;
        };

    case c_MATH_2D_TO_1D_COMPLEX_X_TIMES_Y:
        return [sx, ox, sy, oy](complex<double> x, complex<double> y)
        {
            x = sx * x + ox;
            y = sy * y + oy;
            return x * y;
        };

    case c_MATH_2D_TO_1D_COMPLEX_X_DIV_Y:
        return [sx, ox, sy, oy](complex<double> x, complex<double> y)
        {
            x = sx * x + ox;
            y = sy * y + oy;
            return x / y;
        };

    case c_MATH_2D_TO_1D_COMPLEX_X_POW_Y:
        return [sx, ox, sy, oy](complex<double> x, complex<double> y)
        {
            x = sx * x + ox;
            y = sy * y + oy;
            return pow(x, y);
        };

    case c_MATH_2D_TO_1D_COMPLEX_LOGISTIC_MAP_SIMPLE:
        return [a, sx, ox](complex<double> x, complex<double> y)
        {
            x = sx * x + ox;
            y;
            return (a * x) * (1.0 - x);
        };

    case c_MATH_2D_TO_1D_COMPLEX_LOGISTIC_MAP:
        return [a, b, c, d, sx, ox](complex<double> x, complex<double> y)
        {
            x = sx * x + ox;
            y;
            return (a * x + b) * (c * x + d);
        };

    default:
        return [nan_val](complex<double> x, complex<double> y)
        {
            x; y;
            return complex<double>(nan_val, 0);
        };
    }
}

function<bool (double x, double y)> D_Math::Condition_2D(int type, double a, double b, double c, double d, double e, double f, double g, double h)
{
    switch (type) {

    case c_COND_EQUAL:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;
            return x == y;
        };
        break;

    case c_COND_SMALLER:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;
            return x < y;
        };
        break;

    case c_COND_SMALLER_EQUAL:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;
            return x <= y;
        };
        break;

    case c_COND_GREATER:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;
            return x > y;
        };
        break;

    case c_COND_GREATER_EQUAL:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;
            return x >= y;
        };
        break;

    case c_COND_NOT_EQUAL:
        return [a, b, c, d](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;
            return x != y;
        };
        break;

    case c_COND_INTERVALS_IN_EXCL_AND:
        return [a, b, c, d, e, f, g, h](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;
            return ((e < x) && (x < f)) && ((g < y) && (y < h));
        };
        break;

    case c_COND_INTERVALS_IN_INCL_AND:
        return [a, b, c, d, e, f, g, h](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;
            return ((e <= x) && (x <= f)) && ((g <= y) && (y <= h));
        };
        break;

    case c_COND_INTERVALS_IN_EXCL_OR:
        return [a, b, c, d, e, f, g, h](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;
            return ((e < x) && (x < f)) || ((g < y) && (y < h));
        };
        break;

    case c_COND_INTERVALS_IN_INCL_OR:
        return [a, b, c, d, e, f, g, h](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;
            return ((e <= x) && (x <= f)) || ((g <= y) && (y <= h));
        };
        break;

    case c_COND_INTERVALS_IN_EXCL_XOR:
        return [a, b, c, d, e, f, g, h](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;
            return ((e < x) && (x < f)) != ((g < y) && (y < h));
        };
        break;

    case c_COND_INTERVALS_IN_INCL_XOR:
        return [a, b, c, d, e, f, g, h](double x, double y)
        {
            x = a * x + b;
            y = c * y + d;
            return ((e <= x) && (x <= f)) != ((g <= y) && (y <= h));
        };
        break;

    default:
        return [](double x, double y)
        {
            x; y;
            return false;
        };
        break;
    }
}

function<double (double x, double y, double z, double t, double s, double p)> D_Math::Function_6D_to_1D(int type, double sx, double ox, double sy, double oy, double sz, double oz, double st, double ot, double ss, double os, double sp, double op, double a, double b, double c, double d, double e, double f, double nan_val, double inf_val)
{
    //s_ = scaling_
    //o_ = offset_
    //a-f = params of function

    switch (type) {

    case c_MATH_6D_TO_1D_const_E:
        return [e](double x, double y, double z, double t, double s, double p)
        {
            x;y;z;t;s;p;//independent dims
            return e;
        };

    case c_MATH_6D_TO_1D_PRODUCT:
        return [sx, ox, sy, oy, sz, oz, st, ot, ss, os, sp, op](double x, double y, double z, double t, double s, double p)
        {
            x = sx * x + ox;
            y = sy * y + oy;
            z = sz * z + oz;
            t = st * t + ot;
            s = ss * s + os;
            p = sp * p + op;

            return x * y * z * t * s * p;
        };

    case c_MATH_6D_TO_1D_CUBOID_3D:
        return [sx, ox, sy, oy, sz, oz, a, b, c, d, e, f](double x, double y, double z, double t, double s, double p)
        {
            t;s;p;//independent dims

            //scale & offset
            x = sx * x + ox;
            y = sy * y + oy;
            z = sz * z + oz;

            //rotataion angles to rad
            double e_rad = Grad2Rad * e;
            double f_rad = Grad2Rad * f;

            //rotate around z
            double x1 = x * cos(e_rad) - y * sin(e_rad);
            double y2 = x * sin(e_rad) + y * cos(e_rad);

            //rotate around y
            double x2 = x1 * cos(f_rad) - z * sin(f_rad);
            double z2 = x1 * sin(f_rad) + z * cos(f_rad);

            //height
            double h05x = b/2;
            double h05y = c/2;
            double h05z = d/2;

            //check if coordiantes in cuboid
            return a * static_cast<int>(
                        (x2 >= -h05x) && (h05x >= x2) &&
                        (y2 >= -h05y) && (h05y >= y2) &&
                        (z2 >= -h05z) && (h05z >= z2));
        };

    case c_MATH_6D_TO_1D_CYLINDER_3D:
        return [sx, ox, sy, oy, sz, oz, a, b, c, d, e, f](double x, double y, double z, double t, double s, double p)
        {
            t;s;p;//independent dims

            //scale & offset
            x = sx * x + ox;
            y = sy * y + oy;
            z = sz * z + oz;

            //rotataion angles to rad
            double e_rad = Grad2Rad * e;
            double f_rad = Grad2Rad * f;

            //rotate around z
            double x1 = x * cos(e_rad) - y * sin(e_rad);
            double y2 = x * sin(e_rad) + y * cos(e_rad);

            //rotate around y
            double x2 = x1 * cos(f_rad) - z * sin(f_rad);
            double z2 = x1 * sin(f_rad) + z * cos(f_rad);

            //height
            double h05z = d/2;

            //check if coordiantes in cylinder
            return a * static_cast<int>((((x2 * x2)/(b * b)) + ((y2 * y2)/(c * c)) <= 1) & (z2 <= h05z) & (-h05z <= z2));
        };

    case c_MATH_6D_TO_1D_ASM_REAL:
        return [sx, ox, sy, oy, sz, oz, a, b, e, f](double x, double y, double z, double t, double s, double p)
        {
            t;s;p;//independent dims

            //a=k
            //b=lambda

            //scale & offset
            x = sx * x + ox;
            y = sy * y + oy;
            z = sz * z + oz;

            //rotataion angles to rad
            double e_rad = Grad2Rad * e;
            double f_rad = Grad2Rad * f;

            //rotate around z
            double x1 = x * cos(e_rad) - y * sin(e_rad);
            double y2 = x * sin(e_rad) + y * cos(e_rad);

            //rotate around y
            double x2 = x1 * cos(f_rad) - z * sin(f_rad);
            double z2 = x1 * sin(f_rad) + z * cos(f_rad);

            //calc complex argument
            complex<double> val_i(0, 1.0);
            complex<double> val_exp = val_i * a * z2 * sqrt(1 - (b * (x2 * x2 + y2 * y2)));
            complex<double> val = pow(c_E, val_exp);
            return val.real();
        };

    case c_MATH_6D_TO_1D_ASM_IMAG:
        return [sx, ox, sy, oy, sz, oz, a, b, e, f](double x, double y, double z, double t, double s, double p)
        {
            t;s;p;//independent dims

            //a=k
            //b=lambda

            //scale & offset
            x = sx * x + ox;
            y = sy * y + oy;
            z = sz * z + oz;

            //rotataion angles to rad
            double e_rad = Grad2Rad * e;
            double f_rad = Grad2Rad * f;

            //rotate around z
            double x1 = x * cos(e_rad) - y * sin(e_rad);
            double y2 = x * sin(e_rad) + y * cos(e_rad);

            //rotate around y
            double x2 = x1 * cos(f_rad) - z * sin(f_rad);
            double z2 = x1 * sin(f_rad) + z * cos(f_rad);

            //calc complex argument
            complex<double> val_i(0, 1.0);
            complex<double> val_exp = val_i * a * z2 * sqrt(1 - (b * (x2 * x2 + y2 * y2)));
            complex<double> val = pow(c_E, val_exp);
            return val.imag();
        };

    default:
        return [nan_val](double x, double y, double z, double t, double s, double p)
        {
            x;y;z;t;s;p;//independent dims
            return nan_val;
        };
        break;
    }
}

int D_Math::Distance_Transformation_1D(vector<double> *v_edt, vector<double> v_line, double spacing)
{
    //Algorithm:
    //
    //T. Saito and J. Toriwaki
    //New algorithms for Euclidean distance transformations of an n-dimensional digitised picture with applications
    //Pattern Recognition
    //27(11):1551–1565
    //1994

    //Implementation ispired by:
    //
    //Joachim Ohser
    //Hochschule Darmstadt
    //3D-Bildverarbeitung - Konzepte und Algorithmen
    //Pages 96-107
    //07.07.2016

    //size
    int n = static_cast<int>(v_line.size());

    //resize out
    v_edt->resize(n);

    //iterators
    int i = 0, j = 0;

    //pos of px with nearest dist bg considering parabolic enveloping
    vector<int>     v_near(n, 0);
    int             near = 0;

    //dist to nearest bg
    vector<double>  v_dist(n, 0.0);
    double          dist = 0.0;

    //init
    for(i = 0; i < n; i++)
    {
        v_dist[i] = v_line[i];                                          //dist = input values
        v_near[i] = i;                                                  //each px is itselfs nearest
    }

    //qDebug() << "init" << "i:" << i << "j:" << j << "near:" << near << "dist:" << dist << endl << "v_dist" << v_dist << endl << "v_near" << v_near << endl;

    //qDebug() << endl << "foreward========================================================================foreward" << endl;

    //foreward scan
    for(i = 1; i < n; i++)                                              //(skip 1st on left) loop line rightwards
    {
        //qDebug() << "----------------------------------------------- i:" << i << endl;

        near = v_near[i - 1];                                           //position of px with closest dist to bg of left nighbor

        for(j = near; j <= i; j++)                                      //scan every px between px with closest dist to bg of left nighbor and this px ->
        {
            dist = v_line[j] + static_cast<double>((i - j) * (i - j));  //parabolic enveloping of neighbors distances

            if(dist < v_dist[i])                                        //if current dist is smaller
            {
                v_near[i] = j;                                          //remember position of px with closets dist to bg considering parabolic enveloping
                v_dist[i] = dist;                                       //remember closest dist to bg
                //qDebug() << "CHANGE:";
            }

            //qDebug() << "foreward" << "i:" << i << "j:" << j << "near:" << near << "dist:" << dist << endl << "v_dist" << v_dist << endl << "v_near" << v_near << endl;
        }
    }

    //qDebug() << endl << "backward========================================================================backward" << endl;

    //backward scan
    for(i = n-2; i >= 0; i--)                                           //(skip 1st on right) loop line leftwards
    {
        //qDebug() << "----------------------------------------------- i:" << i << endl;

        near = v_near[i + 1];                                           //right neighbor

        for(j = i; j <= near; j++)                                       //scan every px between px with closest dist to bg of left nighbor and this px <-
        {
            dist = v_line[j] + static_cast<double>((i - j) * (i - j));  //parabolic enveloping of neighbors distances

            if(dist < v_dist[i])                                        //if current dist is smaller
            {
                v_near[i] = j;                                          //remember position of px with closets dist to bg considering parabolic enveloping
                v_dist[i] = dist;                                       //remember closest dist to bg
                //qDebug() << "CHANGE:";
            }

            //qDebug() << "backward" << "i:" << i << "j:" << j << "near:" << near << "dist:" << dist << endl << "v_dist" << v_dist << endl << "v_near" << v_near << endl;
        }
    }

    //scale & export
    for(i = 0; i < n; i++)
        (*v_edt)[i] = v_dist[i] * spacing;

    //qDebug() << "scaled     - v_dist:" << v_dist;

    //finish
    v_near.clear();
    v_dist.clear();
    return ER_okay;
}

function<double (double x, double a, double b, double c, double d, double e, double f)> D_Math::Curve_Array(int prototype)
{
    switch (prototype) {

    case c_CURVE_ARRAY_POLYNOM_DG_5:
        return [](double x, double a, double b, double c, double d, double e, double f)
        {
           return static_cast<double>(
                       a * x * x * x * x * x +
                       b * x * x * x * x +
                       c * x * x * x +
                       d * x * x +
                       e * x +
                       f);
        };

    default:
        return [](double x, double a, double b, double c, double d, double e, double f)
        {
            x;
            a;
            b;
            c;
            d;
            e;
            f;
           return NAN;
        };
    }
}

/*double D_Math::RandomNumberDistribution(int type, double min, double max, double a, double b, double c, double d, double e, double f)
{
    //seed
    mt19937 seed(time(NULL));

    //value
    double val;

    //generate value
    int count = 0;
    do
    {
        switch (type) {

        case c_RAND_NORMAL:
        {
            normal_distribution<double> gen(a, b);
            val = gen(seed);
            break;
        }

        default:
            return 0;
        }

        //catch silly long loops
        count++;
        if(count > 1000000000)
            return ER_other;
    }
    while(val < min || val > max);

    return val;
}*/

double D_Math::Binomial_Coefficient(double n, double k)
{
    //errors
    if(n < 0)   return 0;
    if(k < 0)   return 0;
    if(k > n)   return 0;

    //init
    double b = 1;

    //symmetrie
    if(2 * k > n)
        k = n - k;

    //calc
    for(int i = 1; i <= k; i++)
        b *= (n - k + i) / i;

    return b;
}

double D_Math::Distance(Point pt1, Point pt2)
{
    double dx = pt1.x - pt2.x;
    double dy = pt1.y - pt2.y;
    return sqrt((dx * dx) + (dy * dy));
}

double D_Math::Distance(Point2f pt1, Point pt2)
{
    double dx = pt1.x - pt2.x;
    double dy = pt1.y - pt2.y;
    return sqrt((dx * dx) + (dy * dy));
}

double D_Math::Distance(Point pt1, Point2f pt2)
{
    double dx = pt1.x - pt2.x;
    double dy = pt1.y - pt2.y;
    return sqrt((dx * dx) + (dy * dy));
}

double D_Math::Distance(Point2f pt1, Point2f pt2)
{
    double dx = pt1.x - pt2.x;
    double dy = pt1.y - pt2.y;
    return sqrt((dx * dx) + (dy * dy));
}

double D_Math::AngleRad(Point2f pt1, Point2f pt2)
{
    double dx = pt2.x - pt1.x;
    double dy = pt2.y - pt1.y;
    return atan2(dy, dx);
}

double D_Math::Pythagoras(double x, double y)
{
    return sqrt(x * x + y * y);
}

Point2f D_Math::Center(Point2f pt1, Point2f pt2)
{
    float x = (pt2.x + pt1.x) / 2.f;
    float y = (pt2.y + pt1.y) / 2.f;
    return Point2f(x, y);
}

double D_Math::Difference_AngleRad(double a1, double a2)
{
    double diff = a1-a2;
    while(diff < 0)         diff += PI_2_0;
    while(diff > PI_2_0)    diff -= PI_2_0;
    return diff;
}

double D_Math::Distance_AngleRad_Shortest_Unsigned(double a1, double a2)
{
    return abs(Distance_AngleRad_Shortest_Signed(a1, a2));
}

double D_Math::Distance_AngleRad_Shortest_Signed(double a1, double a2)
{
    //input expected:                    [  0,    2PI ]

    double diff = a1 - a2;          //   [ -2PI,  2PI ]

    if (diff < -PI)                 //   [ -2PI, -PI  )
        return diff + PI_2_0;       //-> [  0,    PI  )
    else if(diff > PI)              //   (  PI,   2PI ]
        return diff - PI_2_0;       //-> [  0,    PI  )
    else                            //   [  0,    PI  ]
        return diff;                //-> [  0,    PI  ]
}


double D_Math::Sum_AngleRad(double a1, double a2)
{
    double sum = a1+a2;
    while(sum < 0)          sum += PI_2_0;
    while(sum > PI_2_0)     sum -= PI_2_0;
    return sum;
}

function<double (double val_in)> D_Math::CopyValue()
{
    return [](double val_in)
        {
            return val_in;
        };
}

function<double (double val_in)> D_Math::LimitRange(double min, double max)
{
    return [min, max](double val_in)
        {
            if(val_in < min)
                return min;
            else if(val_in > max)
                return max;
            else
                return val_in;
    };
}

function<uchar (double val_in)> D_Math::Spread_2_8bit(double min, double max, function<double (double)> F)
{
    double range = max - min;
    double div_8bit = range / 255.0;
    double offset = min;

    return [F, div_8bit, offset](double val_in)
        {
        double val_res = F(val_in);
        double val_scaled = (val_res - offset) / div_8bit;
        if(val_scaled < 0)
            return static_cast<uchar>(0);
        else if(val_scaled > 255)
            return static_cast<uchar>(255);
        else
            return static_cast<uchar>(val_scaled);
    };
}

function<double (double val_in)> D_Math::GammaCorrect_to01(double min, double max, double gamma)
{
    function<double (double val)> F_Limit = D_Math::LimitRange(min, max);

    double range = max - min;
    double offset = min;

    return [F_Limit, offset, range, gamma](double val_in)
        {
            double val_arg = F_Limit(val_in);
            return pow(
                        (val_arg - offset) / range,
                        gamma);
    };
}

function<double (double val_in)> D_Math::Log_Centered(double center, double divisor)
{
    return [center, divisor](double val_in)
        {
            double val_arg = (val_in - center) / divisor;
            if(val_arg < 0)
                return -log(-val_arg + 1);
            else if(val_arg > 0)
                return log(val_arg + 1);
            else
                return 0.0;
    };
}

function<double (double val_in)> D_Math::Log_Centered(double min, double max, double center, double divisor)
{
    function<double (double val)> F_Limit = D_Math::LimitRange(min, max);

    return [center, divisor, F_Limit](double val_in)
        {
            double val_arg = (F_Limit(val_in) - center) / divisor;
            if(val_arg < 0)
                return -log(-val_arg + 1);
            else if(val_arg > 0)
                return log(val_arg + 1);
            else
                return 0.0;
    };
}

/*!
 * \brief D_Math::Minimum_TrisectionInterval use trisection of interval to determin the minimum of a convex function within a given interval
 * \details NOT TESTED YET!
 * \param F function to search for minimum
 * \param start_border_low
 * \param start_border_high
 * \param resolution_needed
 * \return
 */
Point D_Math::Minimum_TrisectionInterval(function<double (double)> F, double start_border_low, double start_border_high, double resolution_needed)
{
    //interval borders
    double x0 = start_border_low;
    double x3 = start_border_high;

    //interval size
    double dx_full = x3 - x0;

    //loop until precision is reached
    while(dx_full > resolution_needed)
    {
        //subinterval size
        double dx_sub = dx_full / 3.0;

        //calc interval borders
        double x1 = x0 + dx_sub;
        double x2 = x1 + dx_sub;

        //calc function values
        double y0 = F(x0);
        double y1 = F(x1);
        double y2 = F(x2);
        double y3 = F(x3);

        //calc signs of the interval border differences (true means +)
        bool s01 = y0 > y1;
        bool s12 = y1 > y2;
        bool s23 = y2 > y3;

        //check sign constellation and chancge interval borders
        if(!s01 && s12 && s23)
            x3 = x2;
        else if(!s01 && !s12 && s23)
            x0 = x1;
        else
        {
            qDebug() << "Feeding D_Math::Minimum_TrisectionInterval with non convex function or wrong interval causes stomach pain. Point(0|0) is vomitted.";
            return Point(0,0);
        }

        //new interval size
        dx_full = x3 - x0;
    }

    //clac result
    double x_final = (x0 + x3) / 2.0;
    double y_final = F(x_final);
    return Point(x_final, y_final);
}




