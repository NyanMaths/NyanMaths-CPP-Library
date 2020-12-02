#include <cmath>
#include <stdexcept>


#define DLLE __declspec (dllexport)

#include <Square.h>


using namespace mt;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Square DLLE operator* (const Square& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Square(a.side() * n);
}

Square DLLE operator* (double n, const Square& a)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Square(a.side() * n);
}


Square DLLE operator/ (const Square& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Square(a.side() / n);
}


Square& Square::operator*= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _side *= n;
    return *this;
}

Square& Square::operator/= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _side /= n;
    return *this;
}


bool DLLE operator== (const Square& a, const Square& b)
{
    return a.side() == b.side();
}

bool DLLE operator!= (const Square& a, const Square& b)
{
    return a.side() != b.side();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Square::Square (double side)
{
    if (side > 0)
        _side = side;

    else
        throw std::invalid_argument("Invalid side : it must be greater than 0");
}


double Square::side () const
{
    return _side;
}


double Square::apothem () const
{
    return _side / 2;
}

double Square::diagonal () const
{
    return _side * sqrt(2);
}

double Square::perimeter () const
{
    return _side * 4;
}

double Square::surface () const
{
    return _side * _side;
}


Disk Square::incircle () const
{
    return Disk(_side / 2);
}

Disk Square::circumcircle () const
{
    return Disk(_side * sqrt(0.5));
}


void Square::setSide (double nSide)
{
    if (nSide > 0)
        _side = nSide;

    else
        throw std::invalid_argument("Invalid new side : it must be greater than 0");
}


void Square::setApothem (double nApothem)
{
    if (nApothem > 0)
        _side = nApothem * 2;

    else
        throw std::invalid_argument("Invalid new apothem : it must be greater than 0");
}

void Square::setDiagonal (double nDiagonale)
{
    if (nDiagonale > 0)
        _side = nDiagonale / sqrt(2);

    else
        throw std::invalid_argument("Invalid new diagonale : it must be greater than 0");
}

void Square::setPerimeter (double nPerimeter)
{
    if (nPerimeter > 0)
        _side = nPerimeter / 4;

    else
        throw std::invalid_argument("Invalid new perimeter : it must be greater than 0");
}

void Square::setSurface (double nSurface)
{
    if (nSurface > 0)
        _side = sqrt(nSurface);

    else
        throw std::invalid_argument("Invalid new surface : it must be greater than 0");
}


void Square::setIncircle (const Disk& nIncircle)
{
    _side = nIncircle.radius() * 2;
}

void Square::setCircumcircle (const Disk& nCircumcircle)
{
    _side = nCircumcircle.radius() / sqrt(0.5);
}
