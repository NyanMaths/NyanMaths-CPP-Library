#include <cmath>
#include <stdexcept>
#include <iostream>


#define DLLE __declspec (dllexport)

#include <Vector2.h>


using namespace mt;


////////////////////////////////////////////////////////////////////////////////////////////////////////


Vector2 DLLE operator+ (const Vector2& a, const Vector2& b)
{
    return Vector2(a.x() + b.x(), a.y() + b.y());
}


Vector2 DLLE operator- (const Vector2& a, const Vector2& b)
{
    return Vector2(a.x() - b.x(), a.y() - b.y());
}


double DLLE operator* (const Vector2& a, const Vector2& b)
{
    return a.x() * b.x() + a.y() * b.y();
}

Vector2 DLLE operator* (const Vector2& a, double b)
{
    return Vector2(a.x() * b, a.y() * b);
}

Vector2 DLLE operator* (double a, const Vector2& b)
{
    return Vector2(b.x() * a, b.y() * a);
}


Vector2 DLLE operator/ (const Vector2& a, double b)
{
    return Vector2(a.x() / b, a.y() / b);
}


Vector2& Vector2::operator+= (const Vector2& n)
{
    _x += n.x();
    _y += n.y();

    return *this;
}


Vector2& Vector2::operator-= (const Vector2& n)
{
    _x -= n.x();
    _y -= n.y();

    return *this;
}


Vector2& Vector2::operator*= (double n)
{
    _x *= n;
    _y *= n;

    return *this;
}


Vector2& Vector2::operator/= (double n)
{
    _x /= n;
    _y /= n;

    return *this;
}


Vector2 DLLE operator- (const Vector2& n)
{
    return Vector2(-n.x(), -n.y());
}


bool DLLE operator== (const Vector2& a, const Vector2& b)
{
    return a.x() == b.x() && a.y() == b.y();
}

bool DLLE operator!= (const Vector2& a, const Vector2& b)
{
    return !(a == b);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////


std::ostream& DLLE operator<< (std::ostream& stream, const mt::Vector2& n)
{
    stream<<'('<<n.x()<<' '<<n.y()<<')';

    return stream;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////


Vector2::Vector2 (double x, double y)
{
    _x = x;
    _y = y;
}


double Vector2::x () const
{
    return _x;
}

double Vector2::y () const
{
    return _y;
}


double Vector2::length () const
{
    return sqrt(_x * _x + _y * _y);
}


void Vector2::setX (double nX)
{
    _x = nX;
}

void Vector2::setY (double nY)
{
    _y = nY;
}


void Vector2::setLength (double nLength)
{
    if (nLength < 0)
        throw std::invalid_argument("The length of your vector can not be negative");

    double n = nLength / length();
    _x *= n;
    _y *= n;
}


bool Vector2::isCollinear (const Vector2& n) const
{
    return _x / n.x() == _y / n.y();
}
