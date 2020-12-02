#include <cmath>
#include <stdexcept>


#define PI 3.14159265358979323846
#define DLLE __declspec (dllexport)

#include <Ball.h>


using namespace mt;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Ball DLLE operator* (const Ball& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Ball(a.radius() * n);
}

Ball DLLE operator* (double n, const Ball& a)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Ball(a.radius() * n);
}


Ball DLLE operator/ (const Ball& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Ball(a.radius() / n);
}


Ball& Ball::operator*= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _radius *= n;
    return *this;
}


Ball& Ball::operator/= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _radius /= n;
    return *this;
}


bool DLLE operator== (const Ball& a, const Ball& b)
{
    return a.radius() == b.radius();
}

bool DLLE operator!= (const Ball& a, const Ball& b)
{
    return a.radius() != b.radius();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Ball::Ball (double radius)
{
    if (radius > 0)
        _radius = radius;

    else
        throw std::invalid_argument("Invalid radius : it must be greater than 0");
}


double Ball::radius () const
{
    return _radius;
}


double Ball::diameter () const
{
    return _radius * 2;
}

double Ball::surface () const
{
    return _radius * _radius * PI * 4;
}

double Ball::volume () const
{
    return _radius * _radius * _radius * 4 * PI / 3;
}


void Ball::setRadius (double nRadius)
{
    if (nRadius > 0)
        _radius = nRadius;

    else
        throw std::invalid_argument("Invalid new radius : it must be greater than 0");
}


void Ball::setDiameter (double nDiameter)
{
    if (nDiameter > 0)
        _radius = nDiameter / 2;

    else
        throw std::invalid_argument("Invalid new diameter : it must be greater than 0");
}

void Ball::setSurface (double nSurface)
{
    if (nSurface > 0)
        _radius = sqrt(nSurface / 4 / PI);

    else
        throw std::invalid_argument("Invalid new surface : it must be greater than 0");
}

void Ball::setVolume (double nVolume)
{
    if (nVolume > 0)
        _radius = pow(nVolume / 4 / PI * 3, 1.0 / 3.0);

    else
        throw std::invalid_argument("Invalid new volume : it must be greater than 0");
}
