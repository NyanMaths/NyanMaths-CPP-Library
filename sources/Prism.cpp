#include <cmath>
#include <stdexcept>


#define DLLE __declspec (dllexport)

#include <Prism.h>


using namespace mt;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Prism DLLE operator* (const Prism& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Prism(a.baseSurface() * n * n, a.height() * n);
}

Prism DLLE operator* (double n, const Prism& a)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Prism(a.baseSurface() * n * n, a.height() * n);
}

Prism DLLE operator/ (const Prism& a, double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    return Prism(a.baseSurface() / (n * n), a.height() / n);
}

Prism& Prism::operator*= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _baseSurface *= n * n;
    _height *= n;
    return *this;
}

Prism& Prism::operator/= (double n)
{
    if (n <= 0)
        throw std::invalid_argument("Invalid coefficient : it must be greater than 0");

    _baseSurface /= n * n;
    _height /= n;
    return *this;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Prism::Prism (double baseSurface, double height)
{
    if (baseSurface > 0 && height > 0)
    {
        _baseSurface = baseSurface;
        _height = height;
    }
    else
        throw std::invalid_argument("Invalid measurements : they must be greater than 0");
}


double Prism::baseSurface () const
{
    return _baseSurface;
}

double Prism::height () const
{
    return _height;
}


double Prism::volume () const
{
    return _baseSurface * _height;
}


void Prism::setBaseSurface (double nBaseSurface)
{
    if (nBaseSurface > 0)
        _baseSurface = nBaseSurface;

    else
        throw std::invalid_argument("Invalid new base surface : it must be greater than 0");
}

void Prism::setHeight (double nHeight)
{
    if (nHeight > 0)
        _height = nHeight;

    else
        throw std::invalid_argument("Invalid new height : it must be greater than 0");
}


void Prism::setVolume (double nVolume)
{
    if (nVolume > 0)
    {
        double n = pow(nVolume / volume(), 1.0 / 3.0);

        _baseSurface *= n * n;
        _height *= n;
    }
    else
        throw std::invalid_argument("Invalid new volume : it must be greater than 0");
}
