#ifndef __VECTOR_H__
#define __VECTOR_H__


#include <iostream>

#ifndef DLLE
#define DLLE __declspec (dllimport)
#endif


namespace mt
{
    class DLLE Vector2
    {
        public:
            Vector2(double, double);


            double x() const;
            double y() const;

            double length() const;


            void setX(double);
            void setY(double);

            void setLength(double);


            bool isCollinear(const Vector2&) const;


            Vector2& operator+= (const Vector2&);
            Vector2& operator-= (const Vector2&);
            Vector2& operator*= (double);
            Vector2& operator/= (double);


        private:
            double _x;
            double _y;
    };  /// Class Vector2
}  /// Namespace mt


mt::Vector2 DLLE operator+ (const mt::Vector2&, const mt::Vector2&);
mt::Vector2 DLLE operator- (const mt::Vector2&, const mt::Vector2&);


double DLLE operator* (const mt::Vector2&, const mt::Vector2&);
mt::Vector2 DLLE operator* (const mt::Vector2&, double);
mt::Vector2 DLLE operator* (double, const mt::Vector2&);

mt::Vector2 DLLE operator/ (const mt::Vector2&, double);


mt::Vector2 DLLE operator- (const mt::Vector2&);


bool DLLE operator== (const mt::Vector2&, const mt::Vector2&);
bool DLLE operator!= (const mt::Vector2&, const mt::Vector2&);


std::ostream& DLLE operator<< (std::ostream&, const mt::Vector2&);


#endif // __VECTOR_H__
