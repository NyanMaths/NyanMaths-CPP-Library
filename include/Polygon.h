#ifndef __POLYGON_H__
#define __POLYGON_H__


#include <Disk.h>

#ifndef DLLE
#define DLLE __declspec (dllimport)
#endif


namespace mt
{
    class DLLE Polygon
    {
        public:
            Polygon(unsigned int, double);


            unsigned int nSides() const;
            double side() const;

            double apothem() const;
            double perimeter() const;
            double surface() const;

            mt::Disk incircle() const;
            mt::Disk circumcircle() const;


            void setNSides(unsigned int);
            void setSide(double);

            void setApothem(double);
            void setPerimeter(double);
            void setSurface(double);

            void setIncircle(const mt::Disk&);
            void setCircumcircle(const mt::Disk&);


            Polygon& operator*= (double);
            Polygon& operator/= (double);


        private:
            unsigned int _nSides;
            double _side;
    };  /// Class Polygon
}  /// Namespace mt


mt::Polygon DLLE operator* (const mt::Polygon&, double);
mt::Polygon DLLE operator/ (const mt::Polygon&, double);
mt::Polygon DLLE operator* (double, const mt::Polygon&);

bool DLLE operator== (const mt::Polygon&, const mt::Polygon&);
bool DLLE operator!= (const mt::Polygon&, const mt::Polygon&);


#endif // __POLYGON_H__
