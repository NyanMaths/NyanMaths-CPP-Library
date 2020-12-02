#include <cmath>
#include <stdexcept>


#define PI 3.14159265358979323846
#define DLLE __declspec (dllexport)

#include <Cone.h>


using namespace mt;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Cone DLLE operator* (const Cone& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Cone(a.radius() * n, a.height() * n);
}

Cone DLLE operator* (double n, const Cone& a)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Cone(a.radius() * n, a.height() * n);
}


Cone DLLE operator/ (const Cone& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Cone(a.radius() / n, a.height() / n);
}


Cone& Cone::operator*= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _radius *= n;
    _height *= n;
    return *this;
}

Cone& Cone::operator/= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _radius /= n;
    _height *= n;
    return *this;
}


bool DLLE operator== (const Cone& a, const Cone& b)
{
    return (a.radius() == b.radius()) && (a.height() == b.height());
}

bool DLLE operator!= (const Cone& a, const Cone& b)
{
    return !(a == b);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Cone::Cone (double radius, double height)
{
    if (radius > 0 && height > 0)
    {
        _radius = radius;
        _height = height;
    }
    else
        throw std::invalid_argument("Invalid radius or height : they must be greater than 0");
}

Cone::Cone (const Disk& base, double height)
{
    if (height > 0)
    {
        _radius = base.radius();
        _height = height;
    }
    else
        throw std::invalid_argument("Invalid height : it must be greater than 0");
}


double Cone::radius () const
{
    return _radius;
}

double Cone::height () const
{
    return _height;
}


double Cone::diameter () const
{
    return _radius * 2;
}

double Cone::apothem () const
{
    return sqrt(_radius * _radius + _height * _height);
}

double Cone::baseSurface () const
{
    return PI * _radius * _radius;
}

double Cone::lateralSurface () const
{
    return PI * _radius * sqrt(_radius * _radius + _height * _height);
}

double Cone::surface () const
{
    return baseSurface() + lateralSurface();
}

double Cone::volume () const
{
    return PI * _radius * _radius * _height / 3;
}

Disk Cone::base () const
{
    return Disk(_radius);
}


void Cone::setRadius (double nRadius)
{
    if (nRadius > 0)
        _radius = nRadius;

    else
        throw std::invalid_argument("Invalid new radius : it must be greater than 0");
}

void Cone::setHeight (double nHeight)
{
    if (nHeight > 0)
        _height = nHeight;

    else
        throw std::invalid_argument("Invalid new height : it must be greater than 0");
}


void Cone::setDiameter (double nDiameter)
{
    if (nDiameter > 0)
        _radius = nDiameter / 2;

    else
        throw std::invalid_argument("Invalid new diameter : it must be greater than 0");
}

void Cone::setBaseSurface (double nBaseSurface)
{
    if (nBaseSurface > 0)
        _radius = sqrt(nBaseSurface / PI);

    else
        throw std::invalid_argument("Invalid new base surface : it must be greater than 0");
}

void Cone::setLateralSurface (double nLateralSurface)
{
    if (nLateralSurface > 0)
    {
        double n = sqrt(nLateralSurface / lateralSurface());

        _radius *= n;
        _height *= n;
    }
    else
        throw std::invalid_argument("Invalid new lateral surface : it must be greater than 0");
}

void Cone::setSurface (double nSurface)
{
    if (nSurface > 0)
    {
        double n = sqrt(nSurface / surface());

        _radius *= n;
        _height *= n;
    }
    else
        throw std::invalid_argument("Invalid new surface : it must be greater than 0");
}

void Cone::setVolume (double nVolume)
{
    if (nVolume > 0)
    {
        double n = pow (nVolume / volume(), 1.0 / 3.0);

        _radius *= n;
        _height *= n;
    }
    else
        throw std::invalid_argument("Invalid new volume : it must be greater than 0");
}

void Cone::setBase (const Disk& nBase)
{
    _radius = nBase.radius();
}
