#include "../include/Rectangle.h"

Rectangle::Rectangle(point origin, int width, int height, int angle, std::string stroke_color, int stroke_width, std::string fill_color) : Shape(origin, angle, stroke_color, stroke_width, fill_color), m_width(width), m_height(height)
{

}

std::string Rectangle::ConvertSVG() const
{
	return "<rect x=\""+ std::to_string(m_origin.x) +"\" y=\""+ std::to_string(m_origin.y) +"\" width=\""+ std::to_string(m_width) +"\" height=\""+ std::to_string(m_height) +"\" stroke=\""+ m_stroke_color +"\" fill=\""+ m_fill_color +"\" stroke-width=\""+ std::to_string(m_stroke_width) +"\"/>\n";
}

void Rectangle::Resize(int width, int height)
{
	m_width = width;
	m_height = height;
}

void Rectangle::ResizeScale(double scale_width, double scale_height)
{
	m_width *= scale_width;
	m_height *= scale_height; 
}

void Rectangle::Display() const
{
	std::cout<<"width : "<<m_width<<std::endl;
	std::cout<<"height : "<<m_height<<std::endl;
	Shape::Display();

}