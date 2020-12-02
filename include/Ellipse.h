#ifndef __ELLIPSE_H__
#define __ELLIPSE_H__


#ifndef DLLE
#define DLLE __declspec (dllimport)
#endif


namespace mt
{
    class DLLE Ellipse
    {
        public:
            Ellipse(double, double);
            Ellipse(double);


            double a() const;
            double b() const;

            double radius() const;
            double diameter() const;

            double perimeter() const;
            double surface() const;

            double linearEccentricity() const;
            double eccentricity() const;

            bool isDisk() const;


            void setA(double);
            void setB(double);
            void setRadius(double);

            void setPerimeter(double);
            void setSurface(double);


            Ellipse& operator*= (double);
            Ellipse& operator/= (double);


        private:
            double _a;
            double _b;
    };  /// Class Ellipse
}  /// Namespace mt


mt::Ellipse DLLE operator* (const mt::Ellipse&, double);
mt::Ellipse DLLE operator/ (const mt::Ellipse&, double);
mt::Ellipse DLLE operator* (double, const mt::Ellipse&);

bool DLLE operator== (const mt::Ellipse&, const mt::Ellipse&);
bool DLLE operator!= (const mt::Ellipse&, const mt::Ellipse&);


#endif // __ELLIPSE_H__
