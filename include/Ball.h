#ifndef __BALL_H__
#define __BALL_H__


#ifndef DLLE
#define DLLE __declspec (dllimport)
#endif


namespace mt
{
    class DLLE Ball
    {
        public:
            Ball(double);


            double radius() const;

            double diameter() const;
            double surface() const;
            double volume() const;


            void setRadius(double);

            void setDiameter(double);
            void setSurface(double);
            void setVolume(double);


            Ball& operator*= (double);
            Ball& operator/= (double);


        private:
            double _radius;
    };  /// Class Ball
}  /// Namespace mt


mt::Ball DLLE operator* (const mt::Ball&, double);
mt::Ball DLLE operator/ (const mt::Ball&, double);
mt::Ball DLLE operator* (double, const mt::Ball&);

bool DLLE operator== (const mt::Ball&, const mt::Ball&);
bool DLLE operator!= (const mt::Ball&, const mt::Ball&);


#endif // __BALL_H__
