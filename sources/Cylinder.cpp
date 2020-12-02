#include <cmath>
#include <stdexcept>


#define PI 3.14159265358979323846
#define DLLE __declspec (dllexport)

#include <Cylinder.h>


using namespace mt;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Cylinder DLLE operator* (const Cylinder& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Cylinder (a.radius() * n, a.height() * n);
}

Cylinder DLLE operator* (double n, const Cylinder& a)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Cylinder (a.radius() * n, a.height() * n);
}


Cylinder DLLE operator/ (const Cylinder& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Cylinder (a.radius() / n, a.height() / n);
}


Cylinder& Cylinder::operator*= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _radius *= n;
    _height *= n;
    return *this;
}


Cylinder& Cylinder::operator/= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _radius /= n;
    _height /= n;
    return *this;
}


bool DLLE operator== (const Cylinder& a, const Cylinder& b)
{
    return (a.radius() == b.radius()) && (a.height() == b.height());
}

bool DLLE operator!= (const Cylinder& a, const Cylinder& b)
{
    return !(a == b);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Cylinder::Cylinder (double radius, double height)
{
    if (radius > 0 && height > 0)
    {
        _radius = radius;
        _height = height;
    }
    else
        throw std::invalid_argument("Invalid measurements : they must be greater than 0");
}

Cylinder::Cylinder (const Disk& base, double height)
{
    if (height > 0)
    {
        _radius = base.radius();
        _height = height;
    }
    else
        throw std::invalid_argument("Invalid height : it must be greater than 0");
}


double Cylinder::radius () const
{
    return _radius;
}

double Cylinder::height () const
{
    return _height;
}


double Cylinder::diameter () const
{
    return _radius * 2;
}

double Cylinder::baseSurface () const
{
    return _radius * _radius * PI;
}

double Cylinder::lateralSurface () const
{
    return _height * 2 * PI * _radius;
}

double Cylinder::surface () const
{
    return baseSurface() * 2 + lateralSurface();
}

double Cylinder::volume () const
{
    return PI * _radius * _radius * _height;
}

Disk Cylinder::base () const
{
    return Disk (_radius);
}


void Cylinder::setRadius (double nRadius)
{
    if (nRadius > 0)
        _radius = nRadius;

    else
        throw std::invalid_argument("Invalid new radius : it must be greater than 0");
}

void Cylinder::setHeight (double nHeight)
{
    if (nHeight > 0)
        _height = nHeight;

    else
        throw std::invalid_argument("Invalid new height : it must be greater than 0");
}


void Cylinder::setDiameter (double nDiameter)
{
    if (nDiameter > 0)
        _radius = nDiameter / 2;

    else
        throw std::invalid_argument("Invalid new diameter : it must be greater than 0");
}

void Cylinder::setBaseSurface (double nBaseSurface)
{
    if (nBaseSurface > 0)
        _radius = sqrt(nBaseSurface / PI);

    else
        throw std::invalid_argument("Invalid new base surface : it must be greater than 0");
}

void Cylinder::setLateralSurface (double nLateralSurface)
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

void Cylinder::setSurface (double nSurface)
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

void Cylinder::setVolume (double nVolume)
{
    if (nVolume > 0)
    {
        double n = pow(nVolume / volume(), 1.0 / 3.0);

        _radius *= n;
        _height *= n;
    }
    else
        throw std::invalid_argument("Invalid new volume : it must be greater than 0");
}


void Cylinder::setBase (const Disk& nBase)
{
    _radius = nBase.radius();
}
