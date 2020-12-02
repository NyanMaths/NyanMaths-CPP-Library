#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__


#include <string>
#include <Disk.h>

#ifndef DLLE
#define DLLE __declspec (dllimport)
#endif


namespace mt
{
    class DLLE Rectangle
    {
        public:
            Rectangle(double, double);
            Rectangle(double);


            double length() const;
            double width() const;

            double side() const;

            double diagonal() const;
            double perimeter() const;
            double surface() const;

            mt::Disk incircle() const;
            mt::Disk circumcircle() const;


            bool isGolden() const;
            bool isSquare() const;


            void setLength(double);
            void setWidth(double);
            void setSide(double);

            void setDiagonal(double);
            void setPerimeter(double);
            void setSurface(double);

            void setIncircle(const mt::Disk&);
            void setCircumcircle(const mt::Disk&);


            Rectangle& operator*= (double);
            Rectangle& operator/= (double);

        private:
            double _length;
            double _width;
    };  /// Class Rectangle
}  /// Namespace mt


mt::Rectangle DLLE operator* (const mt::Rectangle&, double);
mt::Rectangle DLLE operator/ (const mt::Rectangle&, double);
mt::Rectangle DLLE operator* (double, const mt::Rectangle&);

bool DLLE operator== (const mt::Rectangle&, const mt::Rectangle&);
bool DLLE operator!= (const mt::Rectangle&, const mt::Rectangle&);


#endif // __RECTANGLE_H__
