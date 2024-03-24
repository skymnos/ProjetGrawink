#ifndef _STROKE_H_
#define _STROKE_H_
#include "Shape.h"

class Stroke : public Shape
{
    public:
        Stroke(point origin, point endP, int angle, std::string stroke_color, int stroke_width);

        std::string ConvertSVG() const;

        virtual Stroke* Resize(point endP);

        Stroke* ResizeScale(double scale_x, double scale_y);

        virtual Stroke* Display();


    private:
        point m_endP;
};

#endif