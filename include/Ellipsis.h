#ifndef _ELLIPSIS_H_
#define _ELLIPSIS_H_
#include "Shape.h"

class Ellipsis : public Shape
{
    public:
        Ellipsis(point m_origin = {0,0}, double r1 = 10, double r2 = 10, int m_angle = 0, std::string m_stroke_color = "black", int m_stroke_width = 4, std::string m_fill_color = "black", double fill_opacity = 1);

        Ellipsis* Modify(point origin = {0,0}, double r1 = 10, double r2 = 10, int angle = 0, std::string stroke_color = "black", int stroke_width = 4, std::string fill_color = "black", double fill_opacity = 1);

        std::string ConvertSVG() const;

        virtual Ellipsis* Display();
    

    private:
        double m_r1,m_r2;
};

#endif