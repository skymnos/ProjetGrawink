#ifndef _STROKE_H_
#define _STROKE_H_
#include "Shape.h"

class Stroke : public Shape
{
    public:
        Stroke(point origin, point endP, int angle, std::string stroke_color, int stroke_width);

        std::string ConvertSVG() const;

    private:
        point m_endP;
};

#endif