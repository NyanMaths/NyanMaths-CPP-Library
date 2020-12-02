#ifndef POLYNOMIAL2_H
#define POLYNOMIAL2_H


#include <iostream>
#include <string>
#include <complex>

#ifndef DLLE
#define DLLE __declspec (dllimport)
#endif


namespace mt
{
    class DLLE Polynomial2
    {
        public:
            Polynomial2(double, double, double);


            double a() const;
            double b() const;
            double c() const;

            double exec(double) const;
            std::complex<double> exec(std::complex<double>) const;

            double execDerivative(double) const;
            std::complex<double> execDerivative(std::complex<double>) const;

            double execAntiderivative(double) const;
            std::complex<double> execAntiderivative(std::complex<double>) const;

            double integral(double, double) const;


            double delta(bool reduced = false) const;

            double alpha() const;
            double beta() const;


            uint8_t realRootsCount() const;

            double root(uint8_t) const;
            std::complex<double> complexRoot(uint8_t) const;

            double rootsSum() const;
            double rootsProduct() const;


            std::string expandedForm() const;
            std::string vertexForm() const;
            std::string factoredForm() const;
            std::string derivative() const;
            std::string antiderivative() const;


            void setA(double);
            void setB(double);
            void setC(double);


            Polynomial2& operator+= (const Polynomial2&);
            Polynomial2& operator+= (double);

            Polynomial2& operator-= (const Polynomial2&);
            Polynomial2& operator-= (double);

            Polynomial2& operator*= (double);

            Polynomial2& operator/= (double);


            enum form : uint8_t { EXPANDED, VERTEX, FACTORED };

            static form preferredForm();
            static void setPreferredForm(form);


        private:
            double _a;
            double _b;
            double _c;

            static form _preferredForm;
    };  /// Class Polynomial2
}  /// Namespace mt


mt::Polynomial2 DLLE operator+ (const mt::Polynomial2&, const mt::Polynomial2&);
mt::Polynomial2 DLLE operator+ (const mt::Polynomial2&, double);
mt::Polynomial2 DLLE operator+ (double, const mt::Polynomial2&);

mt::Polynomial2 DLLE operator- (const mt::Polynomial2&, const mt::Polynomial2&);
mt::Polynomial2 DLLE operator- (const mt::Polynomial2&, double);
mt::Polynomial2 DLLE operator- (double, const mt::Polynomial2&);

mt::Polynomial2 DLLE operator* (const mt::Polynomial2&, double);
mt::Polynomial2 DLLE operator* (double, const mt::Polynomial2&);

mt::Polynomial2 DLLE operator/ (const mt::Polynomial2&, double);

mt::Polynomial2 DLLE operator- (const mt::Polynomial2&);


bool DLLE operator< (const mt::Polynomial2&, double);
bool DLLE operator< (double, const mt::Polynomial2&);

bool DLLE operator<= (const mt::Polynomial2&, double);
bool DLLE operator<= (double, const mt::Polynomial2&);

bool DLLE operator== (const mt::Polynomial2&, const mt::Polynomial2&);
bool DLLE operator!= (const mt::Polynomial2&, const mt::Polynomial2&);

bool DLLE operator>= (const mt::Polynomial2&, double);
bool DLLE operator>= (double, const mt::Polynomial2&);

bool DLLE operator> (const mt::Polynomial2&, double);
bool DLLE operator> (double, const mt::Polynomial2&);


std::ostream& DLLE operator<< (std::ostream&, const mt::Polynomial2&);


#endif // POLYNOMIAL2_H
