#ifndef __ELLIPSOID_H__
#define __ELLIPSOID_H__


#ifndef DLLE
#define DLLE __declspec (dllimport)
#endif


namespace mt
{
    class DLLE Ellipsoid
    {
        public:
            Ellipsoid(double, double, double);
            Ellipsoid(double);


            double a() const;
            double b() const;
            double c() const;

            double radius() const;
            double diameter() const;

            double surface() const;
            double volume() const;

            double eccentricity() const;

            bool isBall() const;


            void setA(double);
            void setB(double);
            void setC(double);
            void setRadius(double);

            void setSurface(double);
            void setVolume(double);


            Ellipsoid& operator*= (double);
            Ellipsoid& operator/= (double);


        private:
            double _a;
            double _b;
            double _c;
    };  /// Class Ellipsoid
}  /// Namespace mt


mt::Ellipsoid DLLE operator* (const mt::Ellipsoid&, double);
mt::Ellipsoid DLLE operator/ (const mt::Ellipsoid&, double);
mt::Ellipsoid DLLE operator* (double, const mt::Ellipsoid&);

bool DLLE operator== (const mt::Ellipsoid&, const mt::Ellipsoid&);
bool DLLE operator!= (const mt::Ellipsoid&, const mt::Ellipsoid&);


#endif // __ELLIPSOID_H__
