#include <cmath>
#include <stdexcept>


#define DLLE __declspec (dllexport)

#include <Maths.h>


//////////////////////////////////////////////////////////////////////////////////////////////


double DLLE mt::pythagore (double a, double b, double greatest)
{
    if (greatest != 0 && (a <= greatest || b <= greatest))
        throw std::invalid_argument("Invalid argument in pythagore(a, b, greatest) : greatest must be the greatest one");

    else if (a < 0 || b < 0 || greatest < 0)
        throw std::invalid_argument("Invalid argument in pythagore(a, b, greatest) : all arguments must be positive");

    else if (!(a + b) || !(b + greatest) || !(a + greatest))
        throw std::invalid_argument("Invalid argument(s) in pythagore(a, b, greatest) : only one argument should be null");

    else if ((!a) ^ (!b) ^ (!greatest))
    {
        if (!greatest)
            return sqrt (a * a + b * b);

        else if (!a)
            return sqrt(greatest * greatest - b * b);

        else
            return sqrt(greatest * greatest - a * a);
    }
    else
    {
        if (a * a + b * b == greatest * greatest)
            return 1;

        return 0;
    }
}

bool DLLE mt::prime (unsigned long long int x)
{
    if (x < 2)
        return false;

    else if (x < 4)
        return true;

    else if (!(x % 2))
        return false;

    else
    {
        for (unsigned long long int halfOfX = x / 2, div = 3 ; div < halfOfX ; div += 2)
        {
            if (!(x % div))
                return false;
        }
        return true;
    }
}


unsigned long long int DLLE mt::fact (unsigned short int x)
{
    unsigned long long int result = 1;

    for (unsigned short int n = 2 ; n <= x ; n++)
        result *= n;

    return result;
}

double DLLE mt::inverse (double x)
{
    if (!x)
        throw std::invalid_argument("Exception in mt::inverse(double) : division by zero");

    return 1.0 / x;
}

std::complex<double> DLLE mt::inverse (const std::complex<double>& x)
{
    if (x == std::complex<double> (0, 0))
        throw std::invalid_argument ("Exception in mt::inverse(std::complex) : division by zero");

    return std::complex<double> (1, 0) / x;
}

double DLLE mt::root (double x, double n)
{
    return pow(x, 1.0 / n);
}

std::complex<double> DLLE mt::root (const std::complex<double>& x, const std::complex<double>& n)
{
    return pow(x, 1.0 / n);
}

double DLLE mt::square (double x)
{
    return x * x;
}

std::complex<double> DLLE mt::square (const std::complex<double>& x)
{
    return x * x;
}


double DLLE mt::cube (double x)
{
    return x * x * x;
}

std::complex<double> DLLE mt::cube (const std::complex<double>& x)
{
    return x * x * x;
}
