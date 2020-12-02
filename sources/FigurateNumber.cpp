#include <cmath>
#include <stdexcept>
#include <iostream>


#define DLLE __declspec (dllexport)

#include <FigurateNumber.h>


using namespace mt;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool DLLE operator== (const FigurateNumber& a, const FigurateNumber& b)
{
    return a.type() == b.type() && a.index() == b.index();
}

bool DLLE operator!= (const FigurateNumber& a, const FigurateNumber& b)
{
    return !(a == b);
}

std::ostream& DLLE operator<< (std::ostream& outputStream, const FigurateNumber& n)
{
    outputStream<<n.get();

    return outputStream;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


FigurateNumber::FigurateNumber (unsigned long int type, unsigned long int index)
{
    if (type > 2)
        _type = type;

    else
        throw std::invalid_argument("Invalid type : it must be greater than 2");

    _index = index;
}


unsigned long int FigurateNumber::type () const
{
    return _type;
}

unsigned long int FigurateNumber::index () const
{
    return _index;
}


unsigned long long int FigurateNumber::get () const
{
    if (!_index)
        return 0;

    return ((_type - 2) * pow(_index, 2) - (_type - 4) * _index) / 2;
}


void FigurateNumber::setType (unsigned long int nType)
{
    if (nType < 3)
        throw std::invalid_argument("Invalid new type : it must be greater than 2");

    _type = nType;
}

void FigurateNumber::setIndex (unsigned long int nIndex)
{
    _index = nIndex;
}


void FigurateNumber::set (unsigned long long int nVal)
{
    if (nVal < 0)
        throw std::invalid_argument("Invalid new value : it must be greater or equals than 0");


    long double nIndex = (sqrt(8 * (_type - 2) * nVal + (_type - 4) * (_type - 4)) + _type - 4) / (2 * _type - 4);

    if (nIndex != floor(nIndex))
        throw std::invalid_argument ("Invalid new value : it doesn't match a valid index");

    _index = nIndex;
}
