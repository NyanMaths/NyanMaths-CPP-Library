#ifndef __PRISM_H__
#define __PRISM_H__


#ifndef DLLE
#define DLLE __declspec (dllimport)
#endif


namespace mt
{
    class DLLE Prism
    {
        public:
            Prism(double, double);


            double baseSurface() const;
            double height() const;

            double volume() const;


            void setBaseSurface(double);
            void setHeight(double);

            void setVolume(double);


            Prism& operator*= (double);
            Prism& operator/= (double);


        private:
            double _baseSurface;
            double _height;
    };  /// Class Prism
}  /// Namespace mt


mt::Prism DLLE operator* (const mt::Prism&, double);
mt::Prism DLLE operator/ (const mt::Prism&, double);
mt::Prism DLLE operator* (double, const mt::Prism&);


#endif // __PRISM_H__
