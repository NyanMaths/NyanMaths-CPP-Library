#ifndef __CUBE_H__
#define __CUBE_H__


#include <Square.h>
#include <Ball.h>

#ifndef DLLE
#define DLLE __declspec (dllimport)
#endif


namespace mt
{
    class DLLE Cube
    {
        public:
            Cube(double);
            Cube(const mt::Square&);


            double edge() const;

            double diagonal() const;
            double surface() const;
            double volume() const;

            mt::Square face() const;
            mt::Ball insphere() const;
            mt::Ball circumsphere() const;



            void setEdge(double);

            void setDiagonal(double);
            void setSurface(double);
            void setVolume(double);

            void setFace(const mt::Square&);
            void setInsphere(const mt::Ball&);
            void setCircumsphere(const mt::Ball&);


            Cube& operator*= (double);
            Cube& operator/= (double);

        private:
            double _edge;
    };  /// Class Cube
}  /// Namespace mt


mt::Cube DLLE operator* (const mt::Cube&, double);
mt::Cube DLLE operator/ (const mt::Cube&, double);
mt::Cube DLLE operator* (double, const mt::Cube&);

bool DLLE operator== (const mt::Cube&, const mt::Cube&);
bool DLLE operator!= (const mt::Cube&, const mt::Cube&);


#endif // __CUBE_H__
