#include <cmath>
#include <stdexcept>


#define PI 3.14159265358979323846
#define DLLE __declspec (dllexport)

#include <Ellipsoid.h>


using namespace mt;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double min (double a, double b, double c)
{
    if (b < a)
        a = b;

    if (c < a)
        a = c;

    return a;
}

double max (double a, double b, double c)
{
    if (b > a)
        a = b;

    if (c > a)
        a = c;

    return a;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Ellipsoid DLLE operator* (const Ellipsoid& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Ellipsoid(a.a() * n, a.b() * n, a.c() * n);
}

Ellipsoid DLLE operator* (double n, const Ellipsoid& a)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Ellipsoid(a.a() * n, a.b() * n, a.c() * n);
}

Ellipsoid DLLE operator/ (const Ellipsoid& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Ellipsoid (a.a() / n, a.b() / n, a.c() / n);
}


Ellipsoid& Ellipsoid::operator*= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _a *= n;
    _b *= n;
    _c *= n;

    return *this;
}


Ellipsoid& Ellipsoid::operator/= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _a /= n;
    _b /= n;
    _c /= n;

    return *this;
}


bool DLLE operator== (const Ellipsoid& a, const Ellipsoid& b)
{
    return a.a() == b.a() && a.b() == b.b() && a.c() == b.c();
}

bool DLLE operator!= (const Ellipsoid& a, const Ellipsoid& b)
{
    return !(a == b);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Ellipsoid::Ellipsoid (double a, double b, double c)
{
    if (a > 0 && b > 0 && c > 0)
    {
        _a = a;
        _b = b;
        _c = c;
    }
    else
        throw std::invalid_argument("Impossible to create this object : its measurements must be greater than 0");
}

Ellipsoid::Ellipsoid (double radius)
{
    if (radius > 0)
    {
        _a = radius;
        _b = radius;
        _c = radius;
    }
    else
        throw std::invalid_argument("Invalid radius : it must be greater than 0");
}


double Ellipsoid::a () const
{
    return _a;
}

double Ellipsoid::b () const
{
    return _b;
}

double Ellipsoid::c () const
{
    return _c;
}


double Ellipsoid::radius () const
{
    if (_a != _b || _a != _c)
        throw std::logic_error("Unable to access to radius : a must be equal to b and c");

    return _a;
}

double Ellipsoid::diameter () const
{
    if (_a != _b || _a != _c)
        throw std::logic_error("Unable to access to diameter : a must be equal to b and c");

    return _a * 2;
}


double Ellipsoid::surface () const
{
    if (_a == _b && _a == _c)
        return PI * _a * _a * 4;

    else
        throw std::logic_error("Unable to access to surface : your object must be a ball");
}

double Ellipsoid::volume () const
{
    return PI * _a * _b * _c * 4 / 3;
}


double Ellipsoid::eccentricity () const
{
    return sqrt(pow(max(_a, _b, _c), 2) - pow(min(_a, _b, _c), 2)) / max(_a, _b, _c);
}


bool Ellipsoid::isBall () const
{
    return _a == _b && _a == _c;
}


void Ellipsoid::setA (double nA)
{
    if (nA > 0)
        _a = nA;

    else
        throw std::invalid_argument("Invalid new value : it must be greater than 0");
}

void Ellipsoid::setB (double nB)
{
    if (nB > 0)
        _b = nB;

    else
        throw std::invalid_argument("Invalid new value : it must be greater than 0");
}

void Ellipsoid::setC (double nC)
{
    if (nC > 0)
        _c = nC;

    else
        throw std::invalid_argument("Invalid new value : it must be greater than 0");
}

void Ellipsoid::setRadius (double nRadius)
{
    if (nRadius > 0)
    {
        _a = nRadius;
        _b = nRadius;
        _c = nRadius;
    }
    else
        throw std::invalid_argument("Invalid new radius : it must be greater than 0");
}


void Ellipsoid::setSurface (double nSurface)
{
    if (nSurface > 0)
    {
        double n = sqrt(nSurface / surface());

        _a *= n;
        _b *= n;
        _c *= n;
    }
    else
        throw std::invalid_argument("Invalid new surface : it must be greater than 0");
}

void Ellipsoid::setVolume (double nVolume)
{
    if (nVolume > 0)
    {
        double n = pow(nVolume / volume(), 1.0 / 3.0);

        _a *= n;
        _b *= n;
        _c *= n;
    }
    else
        throw std::invalid_argument("Invalid new volume : it must be greater than 0");
}
