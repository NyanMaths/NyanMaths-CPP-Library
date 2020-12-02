#ifndef __FIGURATENUMBER_H__
#define __FIGURATENUMBER_H__


#include <iostream>

#ifndef DLLE
#define DLLE __declspec (dllimport)
#endif


namespace mt
{
    class DLLE FigurateNumber
    {
        public:
            FigurateNumber(unsigned long int, unsigned long int);


            unsigned long int type() const;
            unsigned long int index() const;
            unsigned long long int get() const;


            void setType(unsigned long int);
            void setIndex(unsigned long int);
            void set(unsigned long long int);


        private:
            unsigned long int _type;
            unsigned long int _index;
    };  /// Class FigurateNumber
}  /// Namespace mt


bool DLLE operator== (const mt::FigurateNumber&, const mt::FigurateNumber&);
bool DLLE operator!= (const mt::FigurateNumber&, const mt::FigurateNumber&);

std::ostream& DLLE operator<< (std::ostream&, const mt::FigurateNumber&);


#endif // __FIGURATENUMBER_H__
