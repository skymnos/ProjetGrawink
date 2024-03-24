#ifndef _POLYGONE_H_
#define _POLYGONE_H_
#include "Shape.h"

class Polygone : public Shape
{
    public:
        Polygone(point origin, point m_tabPoint[], int angle, std::string stroke_color, int stroke_width, std::string fill_color); //je ne sais pas comment initialiser le tabPoint dans le .h et .cpp

        std::string ConvertSVG() const;

        void Resize();

        void Display() const;

    private:
        point m_tabPoint[50];


};

#endif