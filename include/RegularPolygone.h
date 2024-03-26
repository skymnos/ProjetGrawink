#ifndef _REGULARPOLYGONE_H_
#define _REGULARPOLYGONE_H_
#include "Shape.h"
#include <vector>
class RegularPolygone : public Shape
{
    public:
        RegularPolygone(point origin = {0,0}, int sideNb = 5, int radius = 30, int angle = 0, std::string stroke_color = "black", int stroke_width = 2, std::string fill_color = "black", double fill_opacity = 1);

        RegularPolygone* Modify(point origin = {0,0}, int sideNb = 5, int radius = 30, int angle = 0, std::string stroke_color = "black", int stroke_width = 2, std::string fill_color = "black", double fill_opacity = 1);

        std::string ConvertSVG() const;

        virtual RegularPolygone* Display();

    private:
        std::vector<point> m_vectorPoint;
        int m_radius;


};

#endif