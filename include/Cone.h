#ifndef __CONE_H__
#define __CONE_H__


#include <Disk.h>

#ifndef DLLE
#define DLLE __declspec (dllimport)
#endif


namespace mt
{
    class DLLE Cone
    {
        public:
            Cone(double, double);
            Cone(const mt::Disk&, double);


            double radius() const;
            double height() const;

            double diameter() const;
            double apothem() const;
            double baseSurface() const;
            double lateralSurface() const;
            double surface() const;
            double volume() const;

            mt::Disk base() const;


            void setRadius(double);
            void setHeight(double);

            void setDiameter(double);
            void setApothem(double);
            void setBaseSurface(double);
            void setLateralSurface(double);
            void setSurface(double);
            void setVolume(double);

            void setBase(const mt::Disk&);


            Cone& operator*= (double);
            Cone& operator/= (double);


        private:
            double _radius;
            double _height;
    };  /// Class Cone
}  /// Namespace mt


mt::Cone DLLE operator* (const mt::Cone&, double);
mt::Cone DLLE operator/ (const mt::Cone&, double);
mt::Cone DLLE operator* (double, const mt::Cone&);

bool DLLE operator== (const mt::Cone&, const mt::Cone&);
bool DLLE operator!= (const mt::Cone&, const mt::Cone&);


#endif // __CONE_H__
