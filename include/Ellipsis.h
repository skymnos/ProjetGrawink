#ifndef _ELLIPSIS_H_
#define _ELLIPSIS_H_
#include "Shape.h"

class Ellipsis : public Shape
{
    public:
        Ellipsis(point m_origin = {0,0}, double r1 = 10, double r2 = 10, int m_angle = 0, std::string m_stroke_color = "black", int m_stroke_width = 4, std::string m_fill_color = "black");

        std::string ConvertSVG() const;

        void Resize(int r1, int r2);

        void Display() const;
    

    private:
        double m_r1,m_r2;
};

#endif