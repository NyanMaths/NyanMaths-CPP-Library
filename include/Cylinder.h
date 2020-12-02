#ifndef __CYLINDER_H__
#define __CYLINDER_H__


#include <Disk.h>

#ifndef DLLE
#define DLLE __declspec (dllimport)
#endif


namespace mt
{
    class DLLE Cylinder
    {
        public:
            Cylinder(double, double);
            Cylinder(const mt::Disk&, double);


            double radius() const;
            double height() const;

            double diameter() const;
            double baseSurface() const;
            double lateralSurface() const;
            double surface() const;
            double volume() const;

            mt::Disk base() const;


            void setRadius(double);
            void setHeight(double);

            void setDiameter(double);
            void setBaseSurface(double);
            void setLateralSurface(double);
            void setSurface(double);
            void setVolume(double);

            void setBase(const mt::Disk&);


            Cylinder& operator*= (double);
            Cylinder& operator/= (double);


        private:
            double _radius;
            double _height;
    };  /// Class Cylinder
}  /// Namespace mt


mt::Cylinder DLLE operator* (const mt::Cylinder&, double);
mt::Cylinder DLLE operator/ (const mt::Cylinder&, double);
mt::Cylinder DLLE operator* (double, const mt::Cylinder&);

bool DLLE operator== (const mt::Cylinder&, const mt::Cylinder&);
bool DLLE operator!= (const mt::Cylinder&, const mt::Cylinder&);


#endif // __CYLINDER_H__
