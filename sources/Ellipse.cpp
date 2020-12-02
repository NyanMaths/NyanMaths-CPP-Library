#include <cmath>
#include <stdexcept>


#define PI 3.14159265358979323846
#define DLLE __declspec (dllexport)

#include <Ellipse.h>


using namespace mt;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Ellipse DLLE operator* (const Ellipse& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Ellipse(a.a() * n, a.b() * n);
}

Ellipse DLLE operator* (double n, const Ellipse& a)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Ellipse(a.a() * n, a.b() * n);
}


Ellipse DLLE operator/ (const Ellipse& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Ellipse (a.a() / n, a.b() / n);
}


Ellipse& Ellipse::operator*= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _a *= n;
    _b *= n;
    return *this;
}


Ellipse& Ellipse::operator/= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _a /= n;
    _b /= n;
    return *this;
}


bool DLLE operator== (const Ellipse& a, const Ellipse& b)
{
    return a.a() == b.a() && a.b() == b.b();
}

bool DLLE operator!= (const Ellipse& a, const Ellipse& b)
{
    return !(a == b);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Ellipse::Ellipse (double a, double b)
{
    if (a > 0 && b > 0)
    {
        _a = a;
        _b = b;
    }
    else
        throw std::invalid_argument("Impossible to create this ellipse : its measurements must be greater than 0");
}

Ellipse::Ellipse (double radius)
{
    if (radius > 0)
    {
        _a = radius;
        _b = radius;
    }
    else
        throw std::invalid_argument("Invalid radius : it must be greater than 0");
}


double Ellipse::a () const
{
    return _a;
}

double Ellipse::b () const
{
    return _b;
}


double Ellipse::radius () const
{
    if (_a != _b)
        throw std::logic_error("Unable to access to radius : your object must be a disk");

    return _a;
}

double Ellipse::diameter () const
{
    if (_a != _b)
        throw std::logic_error("Unable to access to diameter : your object must be a disk");

    return _a * 2;
}


double Ellipse::perimeter () const
{
    return PI * sqrt((_a * _a + _b * _b) / 2) * 2;
}

double Ellipse::surface () const
{
    return PI * _a * _b;
}


double Ellipse::linearEccentricity () const
{
    return sqrt(pow(std::max(_a, _b), 2) - pow(std::min(_a, _b), 2));
}

double Ellipse::eccentricity () const
{
    return linearEccentricity() / std::max(_a, _b);
}


bool Ellipse::isDisk () const
{
    return _a == _b;
}


void Ellipse::setA (double nA)
{
    if (nA > 0)
        _a = nA;

    else
        throw std::invalid_argument("Invalid new measure : it must be greater than 0");
}

void Ellipse::setB (double nB)
{
    if (nB > 0)
        _b = nB;

    else
        throw std::invalid_argument("Invalid new measure : it must be greater than 0");
}


void Ellipse::setRadius (double nRadius)
{
    if (nRadius > 0)
    {
        _a = nRadius;
        _b = nRadius;
    }
    else
        throw std::invalid_argument("Invalid new radius : it must be greater than 0");
}


void Ellipse::setPerimeter (double nPerimeter)
{
    if (nPerimeter > 0)
    {
        double n = nPerimeter / perimeter();

        _a *= n;
        _b *= n;
    }
    else
        throw std::invalid_argument("Invalid new perimeter : it must be greater than 0");
}

void Ellipse::setSurface (double nSurface)
{
    if (nSurface > 0)
    {
        double n = sqrt(nSurface / surface());

        _a *= n;
        _b *= n;
    }
    else
        throw std::invalid_argument("Invalid new surface : it must be greater than 0");
}
