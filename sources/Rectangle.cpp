#include <cmath>
#include <stdexcept>


#define DLLE __declspec (dllexport)

#include <Rectangle.h>


using namespace mt;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


double round (double x)
{
    return (unsigned int)(x * 1000 + 0.5) / 1000;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Rectangle DLLE operator* (const Rectangle& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Rectangle(a.length() * n, a.width() * n);
}

Rectangle DLLE operator* (double n, const Rectangle& a)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Rectangle(a.length() * n, a.width() * n);
}


Rectangle DLLE operator/ (const Rectangle& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Rectangle(a.length() / n, a.width() / n);
}


Rectangle& Rectangle::operator*= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _length *= n;
    _width *= n;
    return *this;
}


Rectangle& Rectangle::operator/= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _length /= n;
    _width /= n;
    return *this;
}


bool DLLE operator== (const Rectangle& a, const Rectangle& b)
{
    return a.length() == b.length() && a.width() == b.width();
}

bool DLLE operator!= (const Rectangle& a, const Rectangle& b)
{
    return !(a == b);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Rectangle::Rectangle (double length, double width)
{
    if (length > 0 && width > 0)
    {
        if (length < width)
            throw std::logic_error("Invalid length : it must be greater or equal than width");

        _length = length;
        _width = width;
    }
    else
        throw std::invalid_argument("Invalid length or width : they must be greater than 0");
}

Rectangle::Rectangle (double side)
{
    if (side > 0)
    {
        _length = side;
        _width = side;
    }
    else
        throw std::invalid_argument("Invalid side : it must be greater than 0");
}


double Rectangle::length () const
{
    return _length;
}

double Rectangle::width () const
{
    return _width;
}


double Rectangle::side () const
{
    if (_length != _width)
        throw std::logic_error("Unable to access to side : length != width");

    return _length;
}


double Rectangle::diagonal () const
{
    return sqrt(_length * _length + _width * _width);
}

double Rectangle::perimeter () const
{
    return 2 * (_length + _width);
}

double Rectangle::surface () const
{
    return _length * _width;
}


Disk Rectangle::incircle () const
{
    if (_length != _width)
        throw std::logic_error("Unable to access to the inscribed circle of this rectangle : length != width");

    return Disk (_length / 2);
}

Disk Rectangle::circumcircle () const
{
    return Disk(sqrt(_length * _length + _width * _width) / 2);
}


bool Rectangle::isGolden () const
{
    return round(_length / _width) == 1.618;
}

bool Rectangle::isSquare () const
{
    return _length == _width;
}


void Rectangle::setLength (double nLength)
{
    if (nLength > 0)
        _length = nLength;

    else
        throw std::invalid_argument("Invalid new length : it must be greater than 0");
}

void Rectangle::setWidth (double nWidth)
{
    if (nWidth > 0)
        _width = nWidth;

    else
        throw std::invalid_argument("Invalid new width : it must be greater than 0");
}

void Rectangle::setSide (double nSide)
{
    if (nSide > 0)
    {
        _length = nSide;
        _width = nSide;
    }
    else
        throw std::invalid_argument("Invalid new side : it must be greater than 0");
}


void Rectangle::setDiagonal (double nDiagonal)
{
    if (nDiagonal > 0)
    {
        double n = nDiagonal / diagonal();

        _length *= n;
        _width *= n;
    }
    else
        throw std::invalid_argument("Invalid new diagonal : it must be greater than 0");
}

void Rectangle::setPerimeter (double nPerimeter)
{
    if (nPerimeter > 0)
    {
        double n = nPerimeter / perimeter();

        _length *= n;
        _width *= n;
    }
    else
        throw std::invalid_argument("Invalid new perimeter : it must be greater than 0");
}

void Rectangle::setSurface (double nSurface)
{
    if (nSurface > 0)
    {
        double n = sqrt(nSurface / surface());

        _length *= n;
        _width *= n;
    }
    else
        throw std::invalid_argument("Invalid new surface : it must be greater than 0");
}


void Rectangle::setIncircle (const Disk& nIncircle)
{
    setSide(nIncircle.radius() * 2);
}

void Rectangle::setCircumcircle (const Disk& nCircumcircle)
{
    double n = nCircumcircle.diameter() / diagonal();

    _length *= n;
    _width *= n;
}
