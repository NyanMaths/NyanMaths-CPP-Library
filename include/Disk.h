#ifndef __DISK_H__
#define __DISK_H__


#ifndef DLLE
#define DLLE __declspec (dllimport)
#endif


namespace mt
{
    class DLLE Disk
    {
        public:
            Disk(double);


            double radius() const;

            double diameter() const;
            double perimeter() const;
            double surface() const;


            void setRadius(double);

            void setDiameter(double);
            void setPerimeter(double);
            void setSurface(double);


            Disk& operator*= (double);
            Disk& operator/= (double);


        private:
            double _radius;
    };  /// Class Disk
}  /// Namespace mt


mt::Disk DLLE operator* (const mt::Disk&, double);
mt::Disk DLLE operator/ (const mt::Disk&, double);
mt::Disk DLLE operator* (double, const mt::Disk&);

bool DLLE operator== (const mt::Disk&, const mt::Disk&);
bool DLLE operator!= (const mt::Disk&, const mt::Disk&);


#endif // __DISK_H__
