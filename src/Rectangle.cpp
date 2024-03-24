#include "../include/Rectangle.h"

Rectangle::Rectangle(point origin, int width, int height, int angle, std::string stroke_color, int stroke_width, std::string fill_color, double fill_opacity) : Shape(origin, angle, stroke_color, stroke_width, fill_color, fill_opacity), m_width(width), m_height(height)
{

}

std::string Rectangle::ConvertSVG() const
{
	return "<rect x=\""+ std::to_string(m_origin.x) +"\" y=\""+ std::to_string(m_origin.y) +"\" width=\""+ std::to_string(m_width) +"\" height=\""+ std::to_string(m_height) +"\" stroke=\""+ m_stroke_color +"\" fill=\""+ m_fill_color +"\" stroke-width=\""+ std::to_string(m_stroke_width) +"\" fill-opacity =\""+ std::to_string(m_fill_opacity) +"\" transform = \"rotate("+ std::to_string(m_angle) +") translate("+ std::to_string(m_translate.x) + ","+  std::to_string(m_translate.y) + ") scale("+ std::to_string(m_scale) +") \"/>\n";
}

Rectangle* Rectangle::Display()
{
	std::cout<<"width : "<<m_width<<std::endl;
	std::cout<<"height : "<<m_height<<std::endl;
	Shape::Display();

	return this;

}