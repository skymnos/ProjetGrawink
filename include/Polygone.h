#ifndef _POLYGONE_H_
#define _POLYGONE_H_
#include "Shape.h"
#include <vector>
class Polygone : public Shape
{
    public:
        Polygone(point origin = {0,0}, std::vector<point> vectorPoint = {{3,3}, {0,3}}, int angle = 0, std::string stroke_color = "black", int stroke_width = 2, std::string fill_color = "black"); //je ne sais pas comment initialiser le tabPoint dans le .h et .cpp

        std::string ConvertSVG() const;

        virtual void Resize(std::vector<point> vectorPoint);

        void ResizeScale(double scale);

        virtual void Display() const;

    private:
        std::vector<point> m_vectorPoint;


};

#endif