#include <cmath>
#include <stdexcept>
#include <sstream>


#define DLLE __declspec (dllexport)

#include <Polynomial2.h>


using namespace mt;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


std::string toString (double x)
{
    std::ostringstream stream;
    stream<<x;

    return stream.str();
}

std::string toString (const std::complex<double>& x)
{
    std::string xStr("(" + toString (x.real()));

    if (x.imag() < 0)
        xStr += " - " + toString (-x.imag()) + "i)";

    if (x.imag() > 0)
        xStr += " + " + toString (x.imag()) + "i)";

    return xStr;
}

double abs (double x)
{
    if (x < 0 || x == -0)
        return -x;

    return x;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Polynomial2 DLLE operator+ (const Polynomial2& a, const Polynomial2& b)
{
    if (a.a() + b.a() == 0)
        throw std::invalid_argument("Invalid coefficient : a must be different than 0");

    return Polynomial2(a.a() + b.a(), a.b() + b.b(), a.c() + b.c());
}

Polynomial2 DLLE operator+ (const Polynomial2& a, double b)
{
    return Polynomial2(a.a(), a.b(), a.c() + b);
}

Polynomial2 DLLE operator+ (double a, const Polynomial2& b)
{
    return Polynomial2(b.a(), b.b(), a + b.c());
}


Polynomial2 DLLE operator- (const Polynomial2& a, const Polynomial2& b)
{
    if (a.a() - b.a() == 0)
        throw std::invalid_argument("Invalid coefficient : a must be different than 0");

    return Polynomial2(a.a() - b.a(), a.b() - b.b(), a.c() - b.c());
}

Polynomial2 DLLE operator- (const Polynomial2& a, double b)
{
    return Polynomial2(a.a(), a.b(), a.c() - b);
}

Polynomial2 DLLE operator- (double a, const Polynomial2& b)
{
    return Polynomial2(-b.a(), -b.b(), a - b.c());
}


Polynomial2 DLLE operator* (const Polynomial2& a, double b)
{
    if (b == 0)
        throw std::invalid_argument("Invalid coefficient : it must be different than 0");

    return Polynomial2(a.a() * b, a.b() * b, a.c() * b);
}

Polynomial2 DLLE operator* (double a, const Polynomial2& b)
{
    if (a == 0)
        throw std::invalid_argument("Invalid coefficient : it must be different than 0");

    return Polynomial2(a * b.a(), a * b.b(), a * b.c());
}


Polynomial2 DLLE operator/ (const Polynomial2& a, double b)
{
    if (b == 0)
        throw std::invalid_argument("Invalid coefficient : it must be different than 0");

    return Polynomial2(a.a() / b, a.b() / b, a.c() / b);
}


Polynomial2 DLLE operator- (const Polynomial2& n)
{
    return Polynomial2(-n.a(), -n.b(), -n.c());
}


Polynomial2& Polynomial2::operator+= (const Polynomial2& n)
{
    if (_a + n.a() == 0)
        throw std::invalid_argument("Invalid coefficient : a must be different than 0");

    _a += n.a();
    _b += n.b();
    _c += n.c();

    return *this;
}

Polynomial2& Polynomial2::operator+= (double n)
{
    _c += n;

    return *this;
}


Polynomial2& Polynomial2::operator-= (const Polynomial2& n)
{
    if (_a - n.a() == 0)
        throw std::invalid_argument("Invalid coefficient : a must be different than 0");

    _a -= n.a();
    _b -= n.b();
    _c -= n.c();

    return *this;
}

Polynomial2& Polynomial2::operator-= (double n)
{
    _c -= n;

    return *this;
}


Polynomial2& Polynomial2::operator*= (double n)
{
    if (n == 0)
        throw std::invalid_argument("Invalid coefficient : a must be different than 0");

    _a *= n;
    _b *= n;
    _c *= n;

    return *this;
}


Polynomial2& Polynomial2::operator/= (double n)
{
    if (n == 0)
        throw std::invalid_argument("Error : division by 0");

    _a /= n;
    _b /= n;
    _c /= n;

    return *this;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool DLLE operator< (const mt::Polynomial2& a, double b)
{
    return a.a() < 0 && a.beta() < b;
}

bool DLLE operator< (double a, const mt::Polynomial2& b)
{
    return b.a() > 0 && b.beta() > a;
}


bool DLLE operator<= (const mt::Polynomial2& a, double b)
{
    return a.a() < 0 && a.beta() <= b;
}

bool DLLE operator<= (double a, const mt::Polynomial2& b)
{
    return b.a() > 0 && b.beta() >= a;
}


bool DLLE operator== (const Polynomial2& a, const Polynomial2& b)
{
    return a.a() == b.a() && a.b() == b.b() && a.c() == b.c();
}

bool DLLE operator!= (const Polynomial2& a, const Polynomial2& b)
{
    return !(a == b);
}


bool DLLE operator>= (const mt::Polynomial2& a, double b)
{
    return a.a() > 0 && a.beta() >= b;
}

bool DLLE operator>= (double a, const mt::Polynomial2& b)
{
    return b.a() < 0 && b.beta() <= a;
}


bool DLLE operator> (const mt::Polynomial2& a, double b)
{
    return a.a() > 0 && a.beta() > b;
}

bool DLLE operator> (double a, const mt::Polynomial2& b)
{
    return b.a() < 0 && b.beta() < a;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


std::ostream& DLLE operator<< (std::ostream& stream, const mt::Polynomial2& n)
{
    if (Polynomial2::preferredForm() == Polynomial2::VERTEX)
        stream<<n.vertexForm();

    else if (Polynomial2::preferredForm() == Polynomial2::FACTORED)
        stream<<n.factoredForm();

    else
        stream<<n.expandedForm();

    return stream;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Polynomial2::Polynomial2 (double a, double b, double c)
{
    if (a == 0)
        throw std::invalid_argument("Invalid coefficient : a must be different than 0");

    _a = a;
    _b = b;
    _c = c;
}


double Polynomial2::a () const
{
    return _a;
}

double Polynomial2::b () const
{
    return _b;
}

double Polynomial2::c () const
{
    return _c;
}


double Polynomial2::exec (double x) const
{
    return _a * x * x + _b * x + _c;
}

std::complex<double> Polynomial2::exec (std::complex<double> x) const
{
    return _a * x * x + _b * x + _c;
}

double Polynomial2::execDerivative (double x) const
{
    return 2 * _a * x + _b;
}

std::complex<double> Polynomial2::execDerivative (std::complex<double> x) const
{
    return 2 * _a * x + _b;
}

double Polynomial2::execAntiderivative (double x) const
{
    return _a * x * x * x / 3 + _b * x * x / 2 + _c * x;
}

std::complex<double> Polynomial2::execAntiderivative (std::complex<double> x) const
{
    return _a * x * x * x / 3.0 + _b * x * x / 2.0 + _c * x;
}


double Polynomial2::delta (bool reduced) const
{
    if (reduced)
        return _b * _b / 4 - _a * _c;

    return _b * _b - 4 * _a * _c;
}

double Polynomial2::alpha () const
{
    return -_b / (2 * _a);
}

double Polynomial2::beta () const
{
    return exec(alpha());
}


uint8_t Polynomial2::realRootsCount () const
{
    if (delta() < 0)
        return 0;

    else if (delta() > 0)
        return 2;

    else
        return 1;
}

double Polynomial2::root (uint8_t whichOne) const
{
    if (delta() < 0)
        throw std::logic_error("This polynomial has no real roots");


    if (whichOne == 1)
        return (-_b - sqrt(delta())) / (2 * _a);

    else if (whichOne == 2)
        return (-_b + sqrt(delta())) / (2 * _a);

    else
        throw std::logic_error("Sorry, but you can only ask for root 1 or 2...");
}

std::complex<double> Polynomial2::complexRoot (uint8_t whichOne) const
{
    if (whichOne == 1)
    {
        if (delta() < 0)
            return std::complex<double>(-_b, -sqrt(abs(delta()))) / (2 * _a);

        return std::complex<double>((-_b - sqrt(delta())) / (2 * _a), 0);
    }
    else if (whichOne == 2)
    {
        if (delta() < 0)
            return std::complex<double>(-_b, sqrt(abs(delta()))) / (2 * _a);

        return std::complex<double>((-_b + sqrt(delta())) / (2 * _a), 0);
    }
    else
        throw std::logic_error("Sorry, but you can only ask for root 1 or 2...");
}

double Polynomial2::rootsSum () const
{
    return -_b / _a;
}

double Polynomial2::rootsProduct () const
{
    return _c / _a;
}


std::string Polynomial2::expandedForm () const
{
    std::string func;

    if (_a == -1)
        func = "-x^2";

    else if (_a == 1)
        func = "x^2";

    else
        func = toString (_a) + "x^2";

    if (_b < 0)
    {
        if (_b == -1)
            func += " - x";

        else
            func += " - " + toString(abs(_b)) + "x";
    }
    if (_b > 0)
    {
        if (_b == 1)
            func += " + x";

        else
            func += " + " + toString(_b) + "x";
    }

    if (_c < 0)
        func += " - " + toString(abs(_c));

    if (_c > 0)
        func += " + " + toString(_c);


    return func;
}

std::string Polynomial2::vertexForm () const
{
    std::string func;

    if (_a == -1)
        func = "-(x";

    else if (_a == 1)
        func = "(x";

    else
        func = toString(_a) + "(x";


    if (alpha() < 0)
        func += " + " + toString(abs(alpha())) + ")";

    else
        func += " - " + toString(abs(alpha())) + ")";

    if (beta() < 0)
        func += " - " + toString(abs(beta()));

    else
        func += " + " + toString(abs(beta()));

    return func;
}

std::string Polynomial2::factoredForm () const
{
    std::string func;

    if (_a == -1)
        func = "-(x";

    else if (_a == 1)
        func = "(x";

    else
        func = toString(_a) + "(x";


    if (abs(delta()) == 0)
    {
        double tmpRoot = root(2);

        if (tmpRoot < 0)
            func += " + " + toString(abs(tmpRoot)) + ")^2";

        else
            func += " - " + toString(tmpRoot) + ")^2";
    }
    else if (delta() < 0)
        func += " - " + toString(complexRoot(1)) + ")(x - " + toString(complexRoot(2)) + ")";

    else
    {
        double tmpRoot1 = root(1);
        double tmpRoot2 = root(2);

        if (tmpRoot1 < 0)
            func += " + " + toString(abs(tmpRoot1)) + ")(x";

        else
            func += " - " + toString(abs(tmpRoot1)) + ")(x";

        if (tmpRoot2 < 0)
            func += " + " + toString(abs(tmpRoot2)) + ")";

        else
            func += " - " + toString(abs(tmpRoot2)) + ")";
    }

    return func;
}


std::string Polynomial2::derivative () const
{
    std::string func;

    if (_a * 2 == -1)
        func = "-x";

    else if (_a * 2 == 1)
        func = "x";

    else
        func = toString(_a * 2) + "x";

    if (_b < 0)
        func += " - " + toString(abs(_b));

    if (_b > 0)
        func += " + " + toString(_b);

    return func;
}

std::string Polynomial2::antiderivative () const
{
    std::string func;

    if (_a / 3 == -1)
        func = "-x^3";

    else if (_a / 3 == 1)
        func = "x^3";

    else
        func = toString(_a / 3) + "x^3";

    if (_b < 0)
    {
        if (_b / 2 == -1)
            func += " - x^2";

        else
            func += " - " + toString(abs(_b) / 2) + "x^2";
    }
    if (_b > 0)
    {
        if (_b / 2 == 1)
            func += " + x^2";

        else
            func += " + " + toString(_b / 2) + "x^2";
    }

    if (_c < 0)
        func += " - " + toString(abs(_c)) + "x";

    if (_c > 0)
        func += " + " + toString(_c) + "x";

    return func;
}


double Polynomial2::integral (double x, double y) const
{
    if (x == y)
        return 0;

    if (y < x)
    {
        double tmp = x;
        x = y;
        y = tmp;
    }


    if (realRootsCount() < 2)
        return abs(execAntiderivative(y) - execAntiderivative(x));


    double minRoot = std::min (root(1), root(2));
    double maxRoot = std::max (root(1), root(2));


    if (y <= minRoot || (x >= minRoot && y <= maxRoot) || x >= maxRoot)
        return abs(execAntiderivative(y) - execAntiderivative(x));

    else if (x < minRoot && y <= maxRoot)
        return abs(execAntiderivative(minRoot) - execAntiderivative(x)) +
               abs(execAntiderivative(y) - execAntiderivative(minRoot));

    else if (x >= minRoot && y > maxRoot)
        return abs(execAntiderivative(maxRoot) - execAntiderivative(x)) +
               abs(execAntiderivative(y) - execAntiderivative(maxRoot));

    else
        return abs(execAntiderivative(minRoot) - execAntiderivative(x)) +
               abs(execAntiderivative(maxRoot) - execAntiderivative(minRoot)) +
               abs(execAntiderivative(y) - execAntiderivative(maxRoot));
}


void Polynomial2::setA (double nA)
{
    if (nA == 0)
        throw std::invalid_argument("Invalid coefficient : a must be different than 0");

    _a = nA;
}

void Polynomial2::setB (double nB)
{
    _b = nB;
}

void Polynomial2::setC (double nC)
{
    _c = nC;
}


Polynomial2::form Polynomial2::_preferredForm(Polynomial2::EXPANDED);

Polynomial2::form Polynomial2::preferredForm ()
{
    return _preferredForm;
}

void Polynomial2::setPreferredForm (Polynomial2::form nForm)
{
    _preferredForm = nForm;
}

