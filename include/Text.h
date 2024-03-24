#ifndef _TEXT_H_
#define _TEXT_H_
#include "Shape.h"

class Text : public Shape
{
    public:
        Text(point origin = {0,0}, std::string text = "text", std::string font_family ="Verdana", int font_size = 20 , int angle = 0, std::string stroke_color = "black", int stroke_width = 3, std::string fill_color = "black", double m_fill_opacity = 1);

        virtual std::string ConvertSVG() const;

        virtual Text* Display();
    
    private:
        std::string m_text, m_font_family;
        int m_font_size;
};

#endif