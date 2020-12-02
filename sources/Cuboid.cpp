#include <cmath>
#include <stdexcept>


#define DLLE __declspec (dllexport)

#include <Cuboid.h>


using namespace mt;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Cuboid DLLE operator* (const Cuboid& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Cuboid(a.length() * n, a.width() * n, a.height() * n);
}


Cuboid DLLE operator* (double n, const Cuboid& a)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Cuboid(a.length() * n, a.width() * n, a.height() * n);
}

Cuboid DLLE operator/ (const Cuboid& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Cuboid(a.length () / n, a.width () / n, a.height () / n);
}


Cuboid& Cuboid::operator*= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _length *= n;
    _width *= n;
    _height *= n;

    return *this;
}

Cuboid& Cuboid::operator/= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _length /= n;
    _width /= n;
    _height /= n;

    return *this;
}


bool DLLE operator== (const Cuboid& a, const Cuboid& b)
{
    return a.length() == b.length() && a.width() == b.width() && a.height() == b.height();
}

bool DLLE operator!= (const Cuboid& a, const Cuboid& b)
{
    return !(a == b);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Cuboid::Cuboid (double length, double width, double height)
{
    if (length > 0 && width > 0 && height > 0)
    {
        if (length < width)
            throw std::logic_error("Impossible to create this cuboid : length < width");

        _length = length;
        _width = width;
        _height = height;
    }
    else
        throw std::invalid_argument("Invalid measurements : they must be greater than 0");
}

Cuboid::Cuboid (double edge)
{
    if (edge > 0)
    {
        _length = edge;
        _width = edge;
        _height = edge;
    }
    else
        throw std::invalid_argument("Invalid edge : it must be greater than 0");
}


double Cuboid::length () const
{
    return _length;
}

double Cuboid::width () const
{
    return _width;
}

double Cuboid::height () const
{
    return _height;
}

double Cuboid::edge () const
{
    if (_length != _width || _length != _height)
        throw std::logic_error("Unable to access to edge : length must be equal to width and height");

    return _length;
}


double Cuboid::diagonal () const
{
    return sqrt (_length * _length + _width * _width + _height * _height);
}

double Cuboid::surface () const
{
    return 2 * (_length * _width + _length * _height + _width * _height);
}

double Cuboid::volume () const
{
    return _length * _width * _height;
}


Ball Cuboid::insphere () const
{
    if (_length != _width || _length != _height)
        throw std::logic_error("Unable to access to insphere : your object must be a cube");

    return Ball(_length / 2);
}

Ball Cuboid::circumsphere () const
{
    return Ball(diagonal() / 2);
}


bool Cuboid::isCube () const
{
    return _length == _width && _length == _height;
}


void Cuboid::setLength (double nLength)
{
    if (nLength > 0)
        _length = nLength;

    else
        throw std::invalid_argument("Invalid new length : it must be greater than 0");
}

void Cuboid::setWidth (double nWidth)
{
    if (nWidth > 0)
        _width = nWidth;

    else
        throw std::invalid_argument("Invalid new width : it must be greater than 0");
}

void Cuboid::setHeight (double nHeight)
{
    if (nHeight > 0)
        _height = nHeight;

    else
        throw std::invalid_argument("Invalid new height : it must be greater than 0");
}

void Cuboid::setEdge (double nEdge)
{
    if (nEdge > 0)
    {
        _length = nEdge;
        _width = nEdge;
        _height = nEdge;
    }
    else
        throw std::invalid_argument("Invalid new edge : it must be greater than 0");
}


void Cuboid::setDiagonal (double nDiagonal)
{
    if (nDiagonal > 0)
    {
        double n = nDiagonal / diagonal();

        _length *= n;
        _width *= n;
        _height *= n;
    }
    else
        throw std::invalid_argument("Invalid new diagonal : it must be greater than 0");
}

void Cuboid::setSurface (double nSurface)
{
    if (nSurface > 0)
    {
        double n = sqrt(nSurface / surface());

        _length *= n;
        _width *= n;
        _height *= n;
    }
    else
        throw std::invalid_argument("Invalid new surface : it must be greater than 0");
}

void Cuboid::setVolume (double nVolume)
{
    if (nVolume > 0)
    {
        double n = pow(nVolume / volume(), 1.0 / 3.0);

        _length *= n;
        _width *= n;
        _height *= n;
    }
    else
        throw std::invalid_argument("Invalid new volume : it must be greater than 0");
}


void Cuboid::setInsphere (const Ball& nInsphere)
{
    setEdge(nInsphere.diameter());
}

void Cuboid::setCircumsphere (const Ball& nCircumsphere)
{
    double n = nCircumsphere.diameter() / diagonal();

    _length *= n;
    _width *= n;
    _height *= n;
}


