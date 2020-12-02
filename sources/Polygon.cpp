#include <cmath>
#include <stdexcept>


#define PI 3.14159265358979323846
#define DLLE __declspec (dllexport)

#include <Polygon.h>


using namespace mt;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Polygon DLLE operator* (const Polygon& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Polygon(a.nSides(), a.side() * n);
}

Polygon DLLE operator* (double n, const Polygon& a)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Polygon(a.nSides(), a.side() * n);
}


Polygon DLLE operator/ (const Polygon& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Polygon(a.nSides(), a.side() / n);
}


Polygon& Polygon::operator*= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _side *= n;
    return *this;
}


Polygon& Polygon::operator/= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _side /= n;
    return *this;
}


bool DLLE operator== (const Polygon& a, const Polygon& b)
{
    return a.nSides() == b.nSides() && a.side() == b.side();
}

bool DLLE operator!= (const Polygon& a, const Polygon& b)
{
    return !(a == b);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Polygon::Polygon (unsigned int nSides, double side)
{
	if (nSides > 2)
        _nSides = nSides;

    else
        throw std::invalid_argument("Invalid number of sides : it must be greater than 2");

    if (side > 0)
        _side = side;

    else
        throw std::invalid_argument("Invalid side : it must be greater than 0");
}


unsigned int Polygon::nSides () const
{
    return _nSides;
}

double Polygon::side () const
{
    return _side;
}


double Polygon::apothem () const
{
    return _side / tan(PI / _nSides) / 2;
}

double Polygon::perimeter () const
{
    return _nSides * _side;
}

double Polygon::surface () const
{
    return apothem() * perimeter() / 2.0;
}


Disk Polygon::incircle () const
{
    return Disk(apothem());
}

Disk Polygon::circumcircle () const
{
    return Disk(_side / 2 / sin (PI / _nSides));
}


void Polygon::setNSides (unsigned int nNSides)
{
	if (nNSides > 2)
        _nSides = nNSides;

    else
        throw std::invalid_argument("Invalid new number of sides : it must be greater than 2");
}

void Polygon::setSide (double nSide)
{
	if (nSide > 0)
        _side = nSide;

    else
        throw std::invalid_argument("Invalid new side : it must be greater than 0");
}


void Polygon::setApothem (double nApothem)
{
	if (nApothem > 0)
        _side = nApothem * 2 * tan(PI / _nSides);

    else
        throw std::invalid_argument("Invalid new apothem : it must be greater than 0");
}

void Polygon::setPerimeter (double nPerimeter)
{
	if (nPerimeter > 0)
        _side = nPerimeter / _nSides;

    else
        throw std::invalid_argument("Invalid new perimeter : it must be greater than 0");
}

void Polygon::setSurface (double nSurface)
{
	if (nSurface > 0)
        _side = sqrt((tan(PI / _nSides) * nSurface / _nSides)) * 2;

    else
        throw std::invalid_argument("Invalid new surface : it must be greater than 0");
}


void Polygon::setIncircle (const Disk& d)
{
    _side = d.radius() * tan(PI / _nSides) * 2;
}

void Polygon::setCircumcircle (const Disk& d)
{
    _side = d.radius() * sin(PI / _nSides) * 2;
}
