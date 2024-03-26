#include "../include/Stroke.h"

Stroke::Stroke(point origin, point endP, int angle, std::string stroke_color, int stroke_width) : Shape(origin, angle, stroke_color, stroke_width), m_endP(endP)
{
	m_type = 1ULL << 0;
	m_sideNb = 1;
}

Stroke* Stroke::Modify(point origin, point endP, int angle, std::string stroke_color, int stroke_width)
{
	m_origin = origin;
	m_endP = endP;
	m_angle = angle;
	m_stroke_color = stroke_color;
	m_stroke_width = stroke_width;

	return this;
}

std::string Stroke::ConvertSVG() const
{
	return "<line x1=\""+ std::to_string(m_origin.x) + "\" x2=\""+ std::to_string(m_endP.x) +"\" y1=\""+ std::to_string(m_origin.y) +"\" y2=\""+ std::to_string(m_endP.y) +"\" stroke=\""+ m_stroke_color +"\" stroke-width=\""+ std::to_string(m_stroke_width) +"\" transform = \"rotate("+ std::to_string(m_angle)  +") translate("+ std::to_string(m_translate.x) + ","+  std::to_string(m_translate.y) + ") scale("+ std::to_string(m_scale) +") \"/>\n";
}


Stroke* Stroke::Display()
{
	std::cout<<"end point x : "<< m_endP.x<< std::endl;
	std::cout<<"end point y : "<< m_endP.y<< std::endl;
	Shape::Display();
	
	return this;
}
