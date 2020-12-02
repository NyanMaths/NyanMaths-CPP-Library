#ifndef __SQUARE_H__
#define __SQUARE_H__


#include <Disk.h>

#ifndef DLLE
#define DLLE __declspec (dllimport)
#endif


namespace mt
{
    class DLLE Square
    {
        public:
            Square(double);


            double side() const;

            double apothem() const;
            double diagonal() const;
            double perimeter() const;
            double surface() const;

            mt::Disk incircle() const;
            mt::Disk circumcircle() const;


            void setSide(double);

            void setApothem(double);
            void setDiagonal(double);
            void setPerimeter(double);
            void setSurface(double);

            void setIncircle(const mt::Disk&);
            void setCircumcircle(const mt::Disk&);


            Square& operator*= (double);
            Square& operator/= (double);


        private:
            double _side;
    };  /// Class Square
}  /// Namespace mt


mt::Square DLLE operator* (const mt::Square&, double);
mt::Square DLLE operator/ (const mt::Square&, double);
mt::Square DLLE operator* (double, const mt::Square&);

bool DLLE operator== (const mt::Square&, const mt::Square&);
bool DLLE operator!= (const mt::Square&, const mt::Square&);


#endif // __SQUARE_H__
