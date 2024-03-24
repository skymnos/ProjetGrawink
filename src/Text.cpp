#include "../include/Text.h"

Text::Text(point origin, std::string text, std::string font_family, int font_size, int angle, std::string stroke_color, int stroke_width, std::string fill_color, double fill_opacity) : Shape(origin, angle, stroke_color, stroke_width, fill_color, fill_opacity), m_text(text), m_font_family(font_family), m_font_size(font_size)
{

}

std::string Text::ConvertSVG() const
{
	return "<text x=\""+ std::to_string(m_origin.x) +"\" y=\""+ std::to_string(m_origin.y) +"\" font-family=\""+ m_font_family +"\" font-size=\""+ std::to_string(m_font_size) +"\" stroke=\""+ m_stroke_color +"\" fill=\""+ m_fill_color +"\" stroke-width=\""+ std::to_string(m_stroke_width) +"\" fill-opacity =\""+ std::to_string(m_fill_opacity) +"\" transform = \"rotate("+ std::to_string(m_angle) +") translate("+ std::to_string(m_translate.x) + ","+  std::to_string(m_translate.y) + ") scale("+ std::to_string(m_scale) +") \">" + m_text + "</text>\n";
}

Text* Text::Display()
{
    std::cout << "text : " << m_text << std::endl;
	std::cout<<"font size : " << m_font_size <<std::endl;
	std::cout<<"font family : " << m_font_family <<std::endl;
	Shape::Display();

	return this;

}