#include <cmath>
#include <stdexcept>


#define DLLE __declspec (dllexport)

#include <Cube.h>


using namespace mt;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Cube DLLE operator* (const Cube& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Cube (a.edge() * n);
}

Cube DLLE operator* (double n, const Cube& a)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Cube (a.edge() * n);
}


Cube DLLE operator/ (const Cube& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Cube (a.edge() / n);
}


Cube& Cube::operator*= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _edge *= n;
    return *this;
}

Cube& Cube::operator/= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _edge /= n;
    return *this;
}


bool DLLE operator== (const Cube& a, const Cube& b)
{
    return a.edge() == b.edge();
}

bool DLLE operator!= (const Cube& a, const Cube& b)
{
    return a.edge() != b.edge();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Cube::Cube (double edge)
{
    if (edge > 0)
        _edge = edge;

    else
        throw std::invalid_argument("Invalid edge : it must be greater than 0");
}

Cube::Cube (const Square& face)
{
    _edge = face.side();
}


double Cube::edge () const
{
    return _edge;
}


double Cube::diagonal () const
{
    return sqrt(3) * _edge;
}

double Cube::surface () const
{
    return _edge * _edge * 6;
}

double Cube::volume () const
{
    return _edge * _edge * _edge;
}

Square Cube::face () const
{
    return Square(_edge);
}

Ball Cube::insphere () const
{
    return Ball(_edge / 2);
}

Ball Cube::circumsphere () const
{
    return Ball(sqrt(3) * _edge / 2);
}


void Cube::setEdge (double nEdge)
{
    if (nEdge > 0)
        _edge = nEdge;

    else
        throw std::invalid_argument("Invalid new edge : it must be greater than 0");
}


void Cube::setDiagonal (double nDiagonal)
{
    if (nDiagonal > 0)
        _edge = nDiagonal / sqrt(3);

    else
        throw std::invalid_argument("Invalid new diagonal : it must be greater than 0");
}

void Cube::setSurface (double nSurface)
{
    if (nSurface > 0)
        _edge = sqrt(nSurface / 6);

    else
        throw std::invalid_argument("Invalid new surface : it must be greater than 0");
}

void Cube::setVolume (double nVolume)
{
    if (nVolume > 0)
        _edge = pow(nVolume, 1.0 / 3.0);

    else
        throw std::invalid_argument("Invalid new volume : it must be greater than 0");
}


void Cube::setFace (const Square& nFace)
{
    _edge = nFace.side();
}

void Cube::setInsphere (const Ball& nInsphere)
{
    _edge = nInsphere.diameter();
}

void Cube::setCircumsphere (const Ball& nCircumsphere)
{
    _edge = nCircumsphere.diameter() / sqrt(3);
}


