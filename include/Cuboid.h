#ifndef __CUBOID_H__
#define __CUBOID_H__


#include <Ball.h>

#ifndef DLLE
#define DLLE __declspec (dllimport)
#endif


namespace mt
{
    class DLLE Cuboid
    {
        public:
            Cuboid(double, double, double);
            Cuboid(double);


            double length() const;
            double width() const;
            double height() const;

            double edge() const;

            double diagonal() const;
            double surface() const;
            double volume() const;

            mt::Ball insphere() const;
            mt::Ball circumsphere() const;

            bool isCube() const;


            void setLength(double);
            void setWidth(double);
            void setHeight(double);

            void setEdge(double);

            void setDiagonal(double);
            void setSurface(double);
            void setVolume(double);

            void setInsphere(const mt::Ball&);
            void setCircumsphere(const mt::Ball&);


            Cuboid& operator*= (double);
            Cuboid& operator/= (double);


        private:
            double _length;
            double _width;
            double _height;
    };  /// Class Cuboid
}  /// Namespace mt


mt::Cuboid DLLE operator* (const mt::Cuboid&, double);
mt::Cuboid DLLE operator/ (const mt::Cuboid&, double);
mt::Cuboid DLLE operator* (double, const mt::Cuboid&);

bool DLLE operator== (const mt::Cuboid&, const mt::Cuboid&);
bool DLLE operator!= (const mt::Cuboid&, const mt::Cuboid&);


#endif // __CUBOID_H__
