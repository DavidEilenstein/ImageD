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

        //force m to fit definition or return 0
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

    case c_MATH_6D_TO_1D_TEST_3D_CHESS:
        return [sx, ox, sy, oy, sz, oz, st, ot, ss, os, sp, op](double x, double y, double z, double t, double s, double p)
        {
            x = sx * x + ox;
            y = sy * y + oy;
            z = sz * z + oz;
            t = st * t + ot;
            s = ss * s + os;
            p = sp * p + op;

            x = abs(x);
            y = abs(y);
            z = abs(z);

            return ((int(x) % 2) + (int(y) % 2) + (int(z) % 2)) % 2;
        };

    case c_MATH_6D_TO_1D_TEST_3D_Z_LAYERS:
        return [sx, ox, sy, oy, sz, oz, st, ot, ss, os, sp, op](double x, double y, double z, double t, double s, double p)
        {
            x = sx * x + ox;
            y = sy * y + oy;
            z = sz * z + oz;
            t = st * t + ot;
            s = ss * s + os;
            p = sp * p + op;

            return z;
        };

    default:
        return [nan_val](double x, double y, double z, double t, double s, double p)
        {
            x;y;z;t;s;p;//independent dims
            return nan_val;
        };
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

bool D_Math::Compare(size_t compare_index, double v1, double v2)
{
    switch (compare_index) {
    case c_COMPARE_EQUAL:           return v1 == v2;
    case c_COMPARE_SMALLER:         return v1 <  v2;
    case c_COMPARE_SMALLER_EQUAL:   return v1 <= v2;
    case c_COMPARE_GREATER:         return v1 >  v2;
    case c_COMPARE_GREATER_EQUAL:   return v1 >= v2;
    case c_COMPARE_NOT_EQUAL:       return v1 != v2;
    default:                        return false;}
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

    //symmetry
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

double D_Math::Distance(Point2d pt1, Point2d pt2)
{
    double dx = pt1.x - pt2.x;
    double dy = pt1.y - pt2.y;
    return sqrt((dx * dx) + (dy * dy));
}

double D_Math::Distance(Point2f pt, Rect r)
{
    double dist_min = INFINITY;
    double dist = INFINITY;

    dist = abs(pt.x - r.tl().x);
    if(dist < dist_min)
        dist_min = dist;

    dist = abs(pt.x - r.br().x);
    if(dist < dist_min)
        dist_min = dist;

    dist = abs(pt.y - r.tl().y);
    if(dist < dist_min)
        dist_min = dist;

    dist = abs(pt.y - r.br().y);
    if(dist < dist_min)
        dist_min = dist;

    return dist_min;
}

double D_Math::Distance(Point pt, Rect r)
{
    double dist_min = INFINITY;
    double dist = INFINITY;

    dist = abs(pt.x - r.tl().x);
    if(dist < dist_min)
        dist_min = dist;

    dist = abs(pt.x - r.br().x);
    if(dist < dist_min)
        dist_min = dist;

    dist = abs(pt.y - r.tl().y);
    if(dist < dist_min)
        dist_min = dist;

    dist = abs(pt.y - r.br().y);
    if(dist < dist_min)
        dist_min = dist;

    return dist_min;
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
        double val_scaled = (div_8bit != 0.0) ? ((val_res - offset) / div_8bit) : (0);
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
                        (range != 0.0) ? ((val_arg - offset) / range) : (0),
                        gamma);
    };
}

function<double (double val_in)> D_Math::Log_Centered(double center, double divisor)
{
    return [center, divisor](double val_in)
        {
            double val_arg = (divisor != 0.0) ? ((val_in - center) / divisor) : (0);
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
            double val_arg = (divisor != 0.0) ? ((F_Limit(val_in) - center) / divisor) : (0);
            if(val_arg < 0)
                return -log(-val_arg + 1);
            else if(val_arg > 0)
                return log(val_arg + 1);
            else
                return 0.0;
    };
}

bool D_Math::Points_Are_Neighbors_8(Point P0, Point P1)
{
    return (abs(P0.x - P1.x) <= 1) && (abs(P0.y - P1.y) <= 1);
}

vector<Point> D_Math::Line_Bresenham_8(Point P0, Point P1)
{
    int x0 = P0.x;
    int y0 = P0.y;
    int x1 = P1.x;
    int y1 = P1.y;

    int dx = x1 - x0;
    int dy = y1 - y0;

    if(abs(dy) < abs(dx))
    {
        if(dx < 0)
            return Line_Bresenham_8_Low(x1, y1, x0, y0);
        else
            return Line_Bresenham_8_Low(x0, y0, x1, y1);
    }
    else
    {
        if(dy < 0)
            return Line_Bresenham_8_Low(x1, y1, x0, y0);
        else
            return Line_Bresenham_8_Low(x0, y0, x1, y1);
    }
}

vector<Point> D_Math::Line_Bresenham_8_Low(int x0, int y0, int x1, int y1)
{
    vector<Point> vLine;

    int dx = x1 - x0;
    int dy = y1 - y0;

    int yi = 1;
    if(dy < 0)
    {
        yi = -1;
        dy = -dy;
    }

    int D = (2 * dy) - dx;
    int y = y0;

    for(int x = x0; x <= x1; x++)
    {
        vLine.push_back(Point(x, y));

        if(D > 0)
        {
            y += yi;
            D += 2 * (dy - dx);
        }
        else
        {
            D += 2 * dy;
        }
    }

    return vLine;
}

vector<Point> D_Math::Line_Bresenham_8_High(int x0, int y0, int x1, int y1)
{
    vector<Point> vLine;

    int dx = x1 - x0;
    int dy = y1 - y0;

    int xi = 1;
    if(dx < 0)
    {
        xi = -1;
        dx = -dx;
    }

    int D = (2 * dx) - dy;
    int x = x0;

    for(int y = y0; y <= y1; y++)
    {
        vLine.push_back(Point(x, y));

        if(D > 0)
        {
            x += xi;
            D += 2 * (dx - dy);
        }
        else
        {
            D += 2 * dx;
        }
    }

    return vLine;
}

/*!
 * \brief D_Math::Close_Contour_Gaps_With_Lines_8 closes the gaps in between contour points with straight lines using <a href="https://en.wikipedia.org/wiki/Bresenham">bresenham algorithm</a>
 * \param pvContour vector of sorted contour pixels. The vector will be changed by adding the missing points in between
 * \return error code
 */
int D_Math::Close_Contour_Gaps_With_Lines_8(vector<Point> *pvContour)
{
    if(pvContour->empty())
        return ER_okay;

    size_t n = pvContour->size();

    ///if there is a gap between start and end, append start to end to close this gap in the follwoing
    Point P0 = (*pvContour)[0    ];
    Point P1 = (*pvContour)[n - 1];
    if(!Points_Are_Neighbors_8(P0, P1))
    {
        pvContour->push_back(P0);
        n++;
    }

    ///loop contour
    for(size_t p = 0; p < n - 1; p++)
    {
        ///detect gaps
        P0 = (*pvContour)[p    ];
        P1 = (*pvContour)[p + 1];
        if(!Points_Are_Neighbors_8(P0, P1))
        {
            ///calc closing lines for all gaps
            vector<Point> vConnectingLine = Line_Bresenham_8(P0, P1);
            int n_line_without_endings = int(vConnectingLine.size()) - 2;

            ///if closing lines include at least 3 Point, instert them into contour without start and end (should always be the case, since otherwise start and end would have been neighbors)
            if(n_line_without_endings > 0)
            {
                pvContour->insert(pvContour->begin() + p, vConnectingLine.begin() + 1, vConnectingLine.end() - 1);
                n += n_line_without_endings;
                p += n_line_without_endings;
            }
        }
    }

    return ER_okay;
}

int D_Math::Close_Contour_Gaps_With_Lines_8(vector<vector<Point> > *pvvContours)
{
    for(size_t c = 0; c < pvvContours->size(); c++)
    {
        int err = Close_Contour_Gaps_With_Lines_8(&((*pvvContours)[c]));
        if(err != ER_okay)
            return err;
    }

    return ER_okay;
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

int D_Math::MedianRunning(vector<uchar> *vDataOut, vector<uchar> vDataIn, size_t mask_size)
{
    return QuantilRunning(
                vDataOut,
                vDataIn,
                mask_size,
                0.5);
}

int D_Math::QuantilRunning(vector<uchar> *vDataOut, vector<uchar> vDataIn, size_t mask_size, double quantil_lower)
{
    if(vDataIn.size() < mask_size + 1)          return ER_size_missmatch;
    if(quantil_lower < 0 || quantil_lower > 1)  return ER_parameter_bad;

    //size
    size_t n = vDataIn.size();

    //hist
    vector<int> hist(256, 0);
    for(size_t i = 0; i < mask_size; i++)
        hist[vDataIn[i]]++;

    //init out
    vDataOut->clear();

    //median
    vector<int> val_init(mask_size);
    for(size_t i = 0; i < mask_size; i++)
        val_init[i] = vDataIn[i];
    sort(val_init.begin(), val_init.end());
    int median = val_init[(val_init.size() - 1) * quantil_lower];
    vDataOut->push_back(median);

    //count of values smaller than median
    int mass_smaller = 0;
    for(size_t i = 0; i < static_cast<size_t>(median); i++)
        mass_smaller += hist[i];

    //count of values equal to median value
    int mass_median = hist[static_cast<size_t>(median)];

    //count of values greater than median
    int mass_greater = 0;
    for(size_t i = static_cast<size_t>(median) + 1; i < hist.size(); i++)
        mass_greater += hist[i];

    //comparison value of needed absolute count for median determination
    double mass_smaller_or_equal_needed = quantil_lower * mask_size;
    double mass_greater_or_equal_needed = (1.0 - quantil_lower) * mask_size;

    qDebug() << "D_Math::MedianRunning:" << "n" << n << "mass_smaller" << mass_smaller << "mass_median" << mass_median << "mass_greater" << mass_greater << "median" << median;

    //data loop
    for(size_t i = 0; i < n - mask_size; i++)
    {
        //relevant values
        uchar val_add = vDataIn[i + mask_size];
        uchar val_rem = vDataIn[i];

        //update histogram
        hist[val_add]++;
        hist[val_rem]--;

        //update masses
        //add
        if(val_add > median)        mass_greater++;
        else if (val_add < median)  mass_smaller++;
        else                        mass_median++;
        //remove
        if(val_rem > median)        mass_greater--;
        else if (val_rem < median)  mass_smaller--;
        else                        mass_median--;

        //update median
        bool check_smaller = mass_smaller + mass_median >= mass_smaller_or_equal_needed;
        bool check_greater = mass_greater + mass_median >= mass_greater_or_equal_needed;
        //qDebug() << "D_Img_Proc::Filter_Median_1C" << "check_smaller" << check_smaller << "check_greater" << check_greater;
        if(check_smaller && !check_greater)
        {//decrease median

            mass_greater += mass_median;

            do
            {
                median -= 1;
            }
            while (hist[static_cast<size_t>(median)] == 0);

            mass_median = hist[static_cast<size_t>(median)];
            mass_smaller -= mass_median;
        }
        if(!check_smaller && check_greater)
        {//increase median

            mass_smaller += mass_median;

            do
            {
                median += 1;
            }
            while (hist[static_cast<size_t>(median)] == 0);

            mass_median = hist[static_cast<size_t>(median)];
            mass_greater -= mass_median;
        }


        //write result
        vDataOut->push_back(median);

        qDebug() << "D_Math::MedianRunning:" << "pos" << i << "of" << n << "add" << val_add << "remove" << val_rem << "mass_smaller" << mass_smaller << "mass_median" << mass_median << "mass_greater" << mass_greater << "check_smaller" << check_smaller << "check_greater" << check_greater << "median" << median;
    }

    return ER_okay;
}

int D_Math::Maximum_Gil(vector<double> *vDataOut, vector<double> *vDataIn, size_t mask_size)
{
    if(vDataIn->empty())            return ER_empty;
    if(vDataIn->size() < mask_size) return ER_size_missmatch;
    if(mask_size % 2 != 1)          return ER_parameter_bad;

    //mask offset
    size_t mask_offset = mask_size / 2;

    //size in
    size_t n_in = vDataIn->size();

    //makropixel count
    size_t n_makropixels = n_in / mask_size;
    if(n_in % mask_size)
        n_makropixels++;

    //pad input with 0
    vector<double> vDataInPadded(n_makropixels * mask_size + 2 * mask_offset, 0);
    for(size_t i = 0; i < n_in; i++)
        vDataInPadded[i + mask_offset] = (*vDataIn)[i];

    //init out
    vDataOut->resize(n_in);

    //set up R and S vectors
    vector<double> vR(mask_size);
    vector<double> vL(mask_size);

    //loop makro pixels
    for(size_t mpx = 0; mpx < n_makropixels; mpx++)
    {
        //center of makropixel (output list coordinates)
        size_t i_center = mpx * mask_size + mask_offset;

        //calc L
        if(mpx == 0)
        {
            //first makropixel
            vL[0] = vDataInPadded[i_center + mask_offset];
            for(size_t l = 1; l < vL.size(); l++)
                vL[l] = max(vL[l-1], vDataInPadded[i_center + mask_offset - l]);
        }
        else
        {
                vL[0] = vDataInPadded[i_center + mask_offset];
                double max_mpx_combi = vL[0] > vR[mask_size - 1] ? vL[0] : vR[mask_size - 1];

                size_t l = 1;
                while(l < mask_size && vL[l-1] < vR[mask_size - 1 - l])
                {
                    vL[l] = max(vL[l-1], vDataInPadded[i_center + mask_offset - l]);
                    l++;
                }
                while(l < mask_size)
                {
                    vL[l] = max_mpx_combi;
                    l++;
                }
        }

        //calc R
        vR[0] = vDataInPadded[i_center + mask_offset];
        for(size_t r = 1; r < mask_size; r++)
            vR[r] = max(vR[r-1], vDataInPadded[i_center + mask_offset + r]);

        //merge to output
        if(mpx < n_makropixels - 1)
        {
            size_t i = 0;
            while(i < mask_size && vR[i] < vL[mask_size - 1  - i])
            {
                //left is greater
               (*vDataOut)[i_center + i - mask_offset] = vL[mask_size - 1  - i];
               i++;
            }
            while(i < mask_size)
            {
                //right is and always will be greater
                (*vDataOut)[i_center + i - mask_offset] = vR[i];
                i++;
            }
        }
        else
        {
            size_t i = 0;
            while(i_center + i - mask_offset < n_in && i < mask_size && vR[i] < vL[mask_size - 1  - i])
            {
               (*vDataOut)[i_center + i - mask_offset] = vL[mask_size - 1  - i];
               i++;
            }
            while(i_center + i - mask_offset < n_in && i < mask_size)
            {
                (*vDataOut)[i_center + i - mask_offset] = vR[i];
                i++;
            }
        }
    }

    return ER_okay;
}



Mat D_Math::Homogenious_2D(double x, double y)
{
    Mat V_homo(3, 1, CV_64FC1);

    V_homo.at<double>(0, 0)  = x;
    V_homo.at<double>(1, 0)  = y;
    V_homo.at<double>(2, 0)  = 1;

    return V_homo;
}

Mat D_Math::Homogenious_2D(double u, double v, double w)
{
    Mat V_out(3, 1, CV_64FC1);

    V_out.at<double>(0, 0)  = u;
    V_out.at<double>(1, 0)  = v;
    V_out.at<double>(2, 0)  = w;

    return V_out;
}

Mat D_Math::Homogenious_2D(Mat V_inhomo)
{
    if(V_inhomo.cols == 1)
        if(V_inhomo.rows == 2)
            if(V_inhomo.type() == CV_64FC1)
                return Homogenious_2D(
                            V_inhomo.at<double>(0, 0),
                            V_inhomo.at<double>(1, 0));

    return Mat::zeros(3, 1, CV_64FC1);
}

Mat D_Math::Homogenious_3D(double x, double y, double z)
{
    Mat V_homo(4, 1, CV_64FC1);

    V_homo.at<double>(0, 0)  = x;
    V_homo.at<double>(1, 0)  = y;
    V_homo.at<double>(2, 0)  = z;
    V_homo.at<double>(3, 0)  = 1;

    return V_homo;
}

Mat D_Math::Homogenious_3D(double u, double v, double w, double q)
{
    if(q != 0)
    {
        Mat V_homo(4, 1, CV_64FC1);

        V_homo.at<double>(0, 0)  = u;
        V_homo.at<double>(1, 0)  = v;
        V_homo.at<double>(2, 0)  = w;
        V_homo.at<double>(3, 0)  = q;

        return V_homo;
    }

    return Mat::zeros(3, 1, CV_64FC1);
}

Mat D_Math::Homogenious_3D(Mat V_inhomo)
{
    if(V_inhomo.cols == 1)
        if(V_inhomo.rows == 3)
            if(V_inhomo.type() == CV_64FC1)
                return Homogenious_3D(
                            V_inhomo.at<double>(0, 0),
                            V_inhomo.at<double>(1, 0),
                            V_inhomo.at<double>(2, 0));

    return Mat::zeros(4, 1, CV_64FC1);
}

Mat D_Math::Inhomogenious_2D(double x, double y)
{
    Mat V_inhomo(2, 1, CV_64FC1);

    V_inhomo.at<double>(0, 0)  = x;
    V_inhomo.at<double>(1, 0)  = y;

    return V_inhomo;
}

Mat D_Math::Inhomogenious_2D(double u, double v, double w)
{
    if(w != 0)
    {
        Mat V_inhomo(2, 1, CV_64FC1);

        V_inhomo.at<double>(0, 0)  = u / w;
        V_inhomo.at<double>(1, 0)  = v / w;

        return V_inhomo;
    }

    return Mat::zeros(2, 1, CV_64FC1);
}

Mat D_Math::Inhomogenious_2D(Mat V_homo)
{
    if(V_homo.cols == 1)
        if(V_homo.rows == 3)
            if(V_homo.type() == CV_64FC1)
                if(V_homo.at<double>(2, 0) != 0)
                    return Inhomogenious_2D(
                                V_homo.at<double>(0, 0),
                                V_homo.at<double>(1, 0),
                                V_homo.at<double>(2, 0));

    return Mat::zeros(2, 1, CV_64FC1);
}

Mat D_Math::Inhomogenious_3D(double x, double y, double z)
{
    Mat V_inhomo(3, 1, CV_64FC1);

    V_inhomo.at<double>(0, 0)  = x;
    V_inhomo.at<double>(1, 0)  = y;
    V_inhomo.at<double>(2, 0)  = z;

    return V_inhomo;
}

Mat D_Math::Inhomogenious_3D(double u, double v, double w, double q)
{
    if(q != 0)
    {
        Mat V_inhomo(3, 1, CV_64FC1);

        V_inhomo.at<double>(0, 0)  = u / q;
        V_inhomo.at<double>(1, 0)  = v / q;
        V_inhomo.at<double>(2, 0)  = w / q;

        return V_inhomo;
    }

    return Mat::zeros(3, 1, CV_64FC1);
}

Mat D_Math::Inhomogenious_3D(Mat V_homo)
{
    if(V_homo.cols == 1)
        if(V_homo.rows == 4)
            if(V_homo.type() == CV_64FC1)
                if(V_homo.at<double>(3, 0) != 0)
                    return Inhomogenious_3D(
                                V_homo.at<double>(0, 0),
                                V_homo.at<double>(1, 0),
                                V_homo.at<double>(2, 0),
                                V_homo.at<double>(3, 0));

    return Mat::zeros(3, 1, CV_64FC1);
}

Mat D_Math::Shift_2D_h(double shift_x, double shift_y)
{
    Mat H = Mat(3, 3, CV_64FC1);

    H.at<double>(0, 0)  = 1;        H.at<double>(0, 1)  = 0;        H.at<double>(0, 2)  = shift_x;
    H.at<double>(1, 0)  = 0;        H.at<double>(1, 1)  = 1;        H.at<double>(1, 2)  = shift_y;
    H.at<double>(2, 0)  = 0;        H.at<double>(2, 1)  = 0;        H.at<double>(2, 2)  = 1;

    return H;
}

Mat D_Math::Shift_3D_h(double shift_x, double shift_y, double shift_z)
{
    Mat H = Mat(4, 4, CV_64FC1);

    H.at<double>(0, 0)  = 1;        H.at<double>(0, 1)  = 0;        H.at<double>(0, 2)  = 0;        H.at<double>(0, 3)  = shift_x;
    H.at<double>(1, 0)  = 0;        H.at<double>(1, 1)  = 1;        H.at<double>(1, 2)  = 0;        H.at<double>(1, 3)  = shift_y;
    H.at<double>(2, 0)  = 0;        H.at<double>(2, 1)  = 0;        H.at<double>(2, 2)  = 1;        H.at<double>(2, 3)  = shift_z;
    H.at<double>(3, 0)  = 0;        H.at<double>(3, 1)  = 0;        H.at<double>(3, 2)  = 0;        H.at<double>(3, 3)  = 1;

    return H;
}

Mat D_Math::Rotation_2D_i_deg(double angle)
{
    return Rotation_2D_i_rad(angle * Grad2Rad);
}

Mat D_Math::Rotation_3D_i_deg(double angle_x, double angle_y, double angle_z)
{
    return Rotation_3D_i_rad(angle_x * Grad2Rad, angle_y * Grad2Rad, angle_z * Grad2Rad);
}

Mat D_Math::Rotation_2D_i_rad(double angle)
{
    Mat R = Mat(2, 2, CV_64FC1);

    double c = cos(angle);
    double s = sin(angle);

    R.at<double>(0, 0)  = c;        R.at<double>(0, 1)  = -s;
    R.at<double>(1, 0)  = s;        R.at<double>(1, 1)  = c;

    return R;
}

Mat D_Math::Rotation_3D_i_rad(double angle_x, double angle_y, double angle_z)
{
    Mat R = Mat(3, 3, CV_64FC1);

    //sin/cos of alpha/beta/gamma
    double ca = cos(angle_x);
    double cb = cos(angle_y);
    double cg = cos(angle_z);
    double sa = sin(angle_x);
    double sb = sin(angle_y);
    double sg = sin(angle_z);

    R.at<double>(0, 0)  = ca*cg - sa*cb*sg;     R.at<double>(0, 1)  = - ca*sg - sa*cb*cg;   R.at<double>(0, 2)  =   sa*sb;
    R.at<double>(1, 0)  = sa*cg + ca*cb*sg;     R.at<double>(1, 1)  = - sa*sg + ca*cb*cg;   R.at<double>(1, 2)  = - ca*sb;
    R.at<double>(2, 0)  = sb*sg;                R.at<double>(2, 1)  =   sb*cg;              R.at<double>(2, 2)  =   cg;

    return R;
}

Mat D_Math::Rotation_2D_h_deg(double angle)
{
    return Rotation_2D_h_rad(angle * Grad2Rad);
}

Mat D_Math::Rotation_2D_h_deg(double angle, double center_x, double center_y)
{
    return Rotation_2D_h_rad(angle * Grad2Rad, center_x, center_y);
}

Mat D_Math::Rotation_3D_h_deg(double angle_x, double angle_y, double angle_z)
{
    return Rotation_3D_h_rad(angle_x * Grad2Rad, angle_y * Grad2Rad, angle_z * Grad2Rad);
}

Mat D_Math::Rotation_3D_h_deg(double angle_x, double angle_y, double angle_z, double center_x, double center_y, double center_z)
{
    return Rotation_3D_h_rad(angle_x * Grad2Rad, angle_y * Grad2Rad, angle_z * Grad2Rad, center_x, center_y, center_z);
}

Mat D_Math::Rotation_2D_h_rad(double angle)
{
    Mat H = Mat(3, 3, CV_64FC1);



    double c = cos(angle);
    double s = sin(angle);

    H.at<double>(0, 0)  = c;        H.at<double>(0, 1)  = -s;       H.at<double>(0, 2)  = 0;
    H.at<double>(1, 0)  = s;        H.at<double>(1, 1)  = c;        H.at<double>(1, 2)  = 0;
    H.at<double>(2, 0)  = 0;        H.at<double>(2, 1)  = 0;        H.at<double>(2, 2)  = 1;

    return H;
}

Mat D_Math::Rotation_2D_h_rad(double angle, double center_x, double center_y)
{
    return Shift_2D_h(-center_x, -center_y) * Euclidean_2D_h_rad(center_x, center_y, angle);
}

Mat D_Math::Rotation_3D_h_rad(double angle_x, double angle_y, double angle_z)
{
    Mat H = Mat(4, 4, CV_64FC1);

    //sin/cos of alpha/beta/gamma
    double ca = cos(angle_x);
    double cb = cos(angle_y);
    double cg = cos(angle_z);
    double sa = sin(angle_x);
    double sb = sin(angle_y);
    double sg = sin(angle_z);

    H.at<double>(0, 0)  = ca*cg - sa*cb*sg;     H.at<double>(0, 1)  = - ca*sg - sa*cb*cg;   H.at<double>(0, 2)  =   sa*sb;      H.at<double>(0, 3)  = 0;
    H.at<double>(1, 0)  = sa*cg + ca*cb*sg;     H.at<double>(1, 1)  = - sa*sg + ca*cb*cg;   H.at<double>(1, 2)  = - ca*sb;      H.at<double>(1, 3)  = 0;
    H.at<double>(2, 0)  = sb*sg;                H.at<double>(2, 1)  =   sb*cg;              H.at<double>(2, 2)  =   cg;         H.at<double>(2, 3)  = 0;
    H.at<double>(3, 0)  = 0;                    H.at<double>(3, 1)  =   0;                  H.at<double>(3, 2)  =   0;          H.at<double>(3, 3)  = 1;

    return H;
}

Mat D_Math::Rotation_3D_h_rad(double angle_x, double angle_y, double angle_z, double center_x, double center_y, double center_z)
{
    return Shift_3D_h(-center_x, -center_y, -center_z) * Euclidean_3D_h_rad(center_x, center_y, center_z, angle_x, angle_y, angle_z);
}

Mat D_Math::Euclidean_2D_h_deg(double shift_x, double shift_y, double angle)
{
    return Euclidean_2D_h_rad(shift_x, shift_y, angle * Grad2Rad);
}

Mat D_Math::Euclidean_3D_h_deg(double shift_x, double shift_y, double shift_z, double angle_x, double angle_y, double angle_z)
{
    return Euclidean_3D_h_rad(shift_x, shift_y, shift_z, angle_x * Grad2Rad, angle_y * Grad2Rad, angle_z * Grad2Rad);
}

Mat D_Math::Euclidean_2D_h_rad(double shift_x, double shift_y, double angle)
{
    Mat H = Mat(3, 3, CV_64FC1);

    double c = cos(angle);
    double s = sin(angle);

    H.at<double>(0, 0)  = c;        H.at<double>(0, 1)  = -s;       H.at<double>(0, 2)  = shift_x;
    H.at<double>(1, 0)  = s;        H.at<double>(1, 1)  = c;        H.at<double>(1, 2)  = shift_y;
    H.at<double>(2, 0)  = 0;        H.at<double>(2, 1)  = 0;        H.at<double>(2, 2)  = 1;

    return H;
}

Mat D_Math::Euclidean_3D_h_rad(double shift_x, double shift_y, double shift_z, double angle_x, double angle_y, double angle_z)
{
    Mat H = Mat(4, 4, CV_64FC1);

    //sin/cos of alpha/beta/gamma
    double ca = cos(angle_x);
    double cb = cos(angle_y);
    double cg = cos(angle_z);
    double sa = sin(angle_x);
    double sb = sin(angle_y);
    double sg = sin(angle_z);

    H.at<double>(0, 0)  = ca*cg - sa*cb*sg;     H.at<double>(0, 1)  = - ca*sg - sa*cb*cg;   H.at<double>(0, 2)  =   sa*sb;      H.at<double>(0, 3)  = shift_x;
    H.at<double>(1, 0)  = sa*cg + ca*cb*sg;     H.at<double>(1, 1)  = - sa*sg + ca*cb*cg;   H.at<double>(1, 2)  = - ca*sb;      H.at<double>(1, 3)  = shift_y;
    H.at<double>(2, 0)  = sb*sg;                H.at<double>(2, 1)  =   sb*cg;              H.at<double>(2, 2)  =   cg;         H.at<double>(2, 3)  = shift_z;
    H.at<double>(3, 0)  = 0;                    H.at<double>(3, 1)  =   0;                  H.at<double>(3, 2)  =   0;          H.at<double>(3, 3)  = 1;

    return H;
}

Mat D_Math::Similarity_2D_h_deg(double shift_x, double shift_y, double angle, double scale)
{
    return Similarity_2D_h_rad(shift_x, shift_y, angle * Grad2Rad, scale);
}

Mat D_Math::Similarity_3D_h_deg(double shift_x, double shift_y, double shift_z, double angle_x, double angle_y, double angle_z, double scale)
{
    return Similarity_3D_h_rad(shift_x, shift_y, shift_z, angle_x * Grad2Rad, angle_y * Grad2Rad, angle_z * Grad2Rad, scale);
}

Mat D_Math::Similarity_2D_h_rad(double shift_x, double shift_y, double angle, double scale)
{
    Mat H = Mat(3, 3, CV_64FC1);

    double c = cos(angle);
    double s = sin(angle);

    H.at<double>(0, 0)  = c * scale;    H.at<double>(0, 1)  = -s;       H.at<double>(0, 2)  = shift_x;
    H.at<double>(1, 0)  = s * scale;    H.at<double>(1, 1)  = c;        H.at<double>(1, 2)  = shift_y;
    H.at<double>(2, 0)  = 0;            H.at<double>(2, 1)  = 0;        H.at<double>(2, 2)  = 1;

    return H;
}

Mat D_Math::Similarity_3D_h_rad(double shift_x, double shift_y, double shift_z, double angle_x, double angle_y, double angle_z, double scale)
{
    Mat H = Mat(4, 4, CV_64FC1);

    //sin/cos of alpha/beta/gamma
    double ca = cos(angle_x);
    double cb = cos(angle_y);
    double cg = cos(angle_z);
    double sa = sin(angle_x);
    double sb = sin(angle_y);
    double sg = sin(angle_z);

    H.at<double>(0, 0)  = (ca*cg - sa*cb*sg) * scale;       H.at<double>(0, 1)  = - ca*sg - sa*cb*cg;   H.at<double>(0, 2)  =   sa*sb;      H.at<double>(0, 3)  = shift_x;
    H.at<double>(1, 0)  = (sa*cg + ca*cb*sg) * scale;       H.at<double>(1, 1)  = - sa*sg + ca*cb*cg;   H.at<double>(1, 2)  = - ca*sb;      H.at<double>(1, 3)  = shift_y;
    H.at<double>(2, 0)  = (sb*sg)            * scale;       H.at<double>(2, 1)  =   sb*cg;              H.at<double>(2, 2)  =   cg;         H.at<double>(2, 3)  = shift_z;
    H.at<double>(3, 0)  = 0;                                H.at<double>(3, 1)  =   0;                  H.at<double>(3, 2)  =   0;          H.at<double>(3, 3)  = 1;

    return H;
}

Mat D_Math::Affinity_2D_h(double shift_x, double shift_y, double a11, double a12, double a21, double a22)
{
    Mat H = Mat(3, 3, CV_64FC1);

    H.at<double>(0, 0)  = a11;          H.at<double>(0, 1)  = a12;      H.at<double>(0, 2)  = shift_x;
    H.at<double>(1, 0)  = a21;          H.at<double>(1, 1)  = a22;      H.at<double>(1, 2)  = shift_y;
    H.at<double>(2, 0)  = 0;            H.at<double>(2, 1)  = 0;        H.at<double>(2, 2)  = 1;

    return H;
}

Mat D_Math::Affinity_3D_h(double shift_x, double shift_y, double shift_z, double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33)
{
    Mat H = Mat(4, 4, CV_64FC1);

    H.at<double>(0, 0)  = a11;      H.at<double>(0, 1)  = a12;      H.at<double>(0, 2)  = a13;      H.at<double>(0, 3)  = shift_x;
    H.at<double>(1, 0)  = a21;      H.at<double>(1, 1)  = a22;      H.at<double>(1, 2)  = a23;      H.at<double>(1, 3)  = shift_y;
    H.at<double>(2, 0)  = a31;      H.at<double>(2, 1)  = a32;      H.at<double>(2, 2)  = a33;      H.at<double>(2, 3)  = shift_z;
    H.at<double>(3, 0)  = 0;        H.at<double>(3, 1)  = 0;        H.at<double>(3, 2)  = 0;        H.at<double>(3, 3)  = 1;

    return H;
}

Mat D_Math::Projektion_2D_h(double shift_x, double shift_y, double a11, double a12, double a21, double a22, double p1, double p2)
{
    Mat H = Mat(3, 3, CV_64FC1);

    H.at<double>(0, 0)  = a11;          H.at<double>(0, 1)  = a12;      H.at<double>(0, 2)  = shift_x;
    H.at<double>(1, 0)  = a21;          H.at<double>(1, 1)  = a22;      H.at<double>(1, 2)  = shift_y;
    H.at<double>(2, 0)  = p1;           H.at<double>(2, 1)  = p2;       H.at<double>(2, 2)  = 1;

    return H;
}

Mat D_Math::Projektion_3D_h(double shift_x, double shift_y, double shift_z, double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33, double p1, double p2, double p3)
{
    Mat H = Mat(4, 4, CV_64FC1);

    H.at<double>(0, 0)  = a11;      H.at<double>(0, 1)  = a12;      H.at<double>(0, 2)  = a13;      H.at<double>(0, 3)  = shift_x;
    H.at<double>(1, 0)  = a21;      H.at<double>(1, 1)  = a22;      H.at<double>(1, 2)  = a23;      H.at<double>(1, 3)  = shift_y;
    H.at<double>(2, 0)  = a31;      H.at<double>(2, 1)  = a32;      H.at<double>(2, 2)  = a33;      H.at<double>(2, 3)  = shift_z;
    H.at<double>(3, 0)  = p1;       H.at<double>(3, 1)  = p2;       H.at<double>(3, 2)  = p3;       H.at<double>(3, 3)  = 1;

    return H;
}

Mat D_Math::Projektion_ND_h(Mat A, Mat t, Mat P)
{
    if(!A.empty())
    {
        //dims
        int m = A.rows;
        int n = A.cols;

        //setup H
        Mat H = Mat::zeros(m + 1, n + 1, CV_64FC1);

        //Rotation
        if(A.type() == CV_64FC1)
            for(int y = 0; y < m; y++)
                for(int x = 0; x < n; x++)
                    H.at<double>(y, x) = A.at<double>(y, x);

        //Translation
        if(!t.empty())
            if(t.type() == CV_64FC1)
                if(t.cols == 1)
                    if(t.rows == m)
                        for(int y = 0; y < m; y++)
                            H.at<double>(y, n) = A.at<double>(y, 1);

        //Projection
        if(!P.empty())
            if(P.type() == CV_64FC1)
                if(P.cols == 1)
                    if(P.rows == n)
                        for(int x = 0; x < m; x++)
                            H.at<double>(m, x) = A.at<double>(x, 1);

        return H;
    }

    return Mat::zeros(1, 1, CV_64FC1);
}




