#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
#include "Shape.h"

class Rectangle : public Shape
{
    public:
        Rectangle(point origin = {0,0}, int m_width = 10, int m_height = 10, int angle = 0, std::string stroke_color = "black", int stroke_width = 3, std::string fill_color = "black");

        virtual std::string ConvertSVG() const;

        virtual Rectangle* Display();
    
    private:
        int m_width, m_height;
};

#endif