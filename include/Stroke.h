#ifndef _STROKE_H_
#define _STROKE_H_
#include "Shape.h"

class Stroke : public Shape
{
    public:
        Stroke(point origin = {0,0}, point endP = {10, 10}, int angle = 0, std::string stroke_color = "black", int stroke_width = 1);

        Stroke* Modify(point origin = {0,0}, point endP = {10, 10}, int angle = 0, std::string stroke_color = "black", int stroke_width = 1);

        std::string ConvertSVG() const;

        virtual Stroke* Display();


    private:
        point m_endP;
};

#endif