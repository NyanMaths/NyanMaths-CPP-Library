#include <cmath>
#include <stdexcept>


#define PI 3.14159265358979323846
#define DLLE __declspec (dllexport)

#include <Disk.h>


using namespace mt;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Disk DLLE operator* (const Disk& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Disk(a.radius() * n);
}

Disk DLLE operator* (double n, const Disk& a)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Disk(a.radius() * n);
}


Disk DLLE operator/ (const Disk& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Disk(a.radius() / n);
}


Disk& Disk::operator*= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _radius *= n;
    return *this;
}


Disk& Disk::operator/= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _radius /= n;
    return *this;
}


bool DLLE operator== (const Disk& a, const Disk& b)
{
    return a.radius() == b.radius();
}

bool DLLE operator!= (const Disk& a, const Disk& b)
{
    return a.radius() != b.radius();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Disk::Disk (double radius)
{
    if (radius > 0)
        _radius = radius;

    else
        throw std::invalid_argument("Invalid radius : it must be greater than 0");
}


double Disk::radius () const
{
    return _radius;
}


double Disk::diameter () const
{
    return _radius * 2;
}

double Disk::perimeter () const
{
    return _radius * 2 * PI;
}

double Disk::surface () const
{
    return PI * _radius * _radius;
}


void Disk::setRadius (double nRadius)
{
    if (nRadius > 0)
        _radius = nRadius;

    else
        throw std::invalid_argument("Invalid new radius : it must be greater than 0");
}


void Disk::setDiameter (double nDiameter)
{
    if (nDiameter > 0)
        _radius = nDiameter / 2;

    else
        throw std::invalid_argument("Invalid new diameter : it must be greater than 0");
}

void Disk::setPerimeter (double nPerimeter)
{
    if (nPerimeter > 0)
        _radius = nPerimeter / PI / 2;

    else
        throw std::invalid_argument("Invalid new perimeter : it must be greater than 0");
}

void Disk::setSurface (double nSurface)
{
    if (nSurface > 0)
        _radius = sqrt(nSurface / PI);

    else
        throw std::invalid_argument ("Invalid new surface : it must be greater than 0");
}
