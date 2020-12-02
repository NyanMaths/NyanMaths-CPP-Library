#ifndef __MATHS_H__
#define __MATHS_H__


#include <complex>

#ifndef DLLE
#define DLLE __declspec (dllimport)
#endif


namespace mt
{
    double DLLE pythagore(double, double, double);

    bool DLLE prime(unsigned long long int);


    unsigned long long int DLLE fact(unsigned short int);

    double DLLE inverse(double);
    std::complex<double> DLLE inverse(const std::complex<double>&);

    double DLLE root(double, double);
    std::complex<double> DLLE root(const std::complex<double>&, const std::complex<double>&);

    double DLLE square(double);
    std::complex<double> DLLE square(const std::complex<double>&);

    double DLLE cube(double);
    std::complex<double> DLLE cube(const std::complex<double>&);


    namespace consts
    {
        const long double pi = 3.14159265358979323846;
        const long double tau = 6.28318530717958647693;
        const long double e = 2.71828182845904523536;
        const long double phi = 1.6180339887498948482;

        const double h = 6.62607015e-34;
        const double hBar = 1.054571817e-34;
        const double G = 6.6743015e-11;
        const double E = 1.602176634e-19;


        const float inch = 0.0254;
        const float foot = 0.3048;
        const float yard = 0.9144;
        const float mile = 1609.344;
        const unsigned short int nauticalMile = 1852;
        const float league = 4828.032;

        const double planckLength = 1.616255e-35;
        const unsigned long long int ua = 149597870000;
        const unsigned long long int ly = 9460730472580800;
        const unsigned long long int parsec = 30856775670528308;


        const float sunAcceleration = 273.95;
        const float mercuryAcceleration = 3.701;
        const float venusAcceleration = 8.87;
        const float earthAcceleration = 9.80665;
        const float moonAcceleration = 1.622;
        const float marsAcceleration = 3.711;
        const float jupiterAcceleration = 24.796;
        const float saturnAcceleration = 10.44;
        const float uranusAcceleration = 8.87;
        const float neptuneAcceleration = 11.15;
        const float plutoAcceleration = 0.62;


        const double electronWeight = 9.10938356e-31;
        const double protonWeight = 1.672649e-27;
        const double neutronWeight = 1.674927471e-27;

        const float moonWeight = 7.342e+22;
        const float earthWeight = 5.97237e+24;
        const float sunWeight = 1.9885e+30;

        const unsigned int lightSpeed = 299792458;
        const unsigned short int soundSpeed = 347;
    }  /// Namespace consts
}  /// Namespace mt


#endif // __MATHS_H__
