#include "../include/Stroke.h"

Stroke::Stroke(point origin, point endP, int angle, std::string stroke_color, int stroke_width) : Shape(origin, angle, stroke_color, stroke_width), m_endP(endP)
{

}

std::string Stroke::ConvertSVG() const
{
	return "<line x1=\""+ std::to_string(m_origin.x) + "\" x2=\""+ std::to_string(m_endP.x) +"\" y1=\""+ std::to_string(m_origin.y) +"\" y2=\""+ std::to_string(m_endP.y) +"\" stroke=\""+ m_stroke_color +"\" stroke-width=\""+ std::to_string(m_stroke_width) +"\" transform = \"rotate("+ std::to_string(m_angle) +")\"/>\n";
}

Stroke* Stroke::Resize(point endP)
{
	m_endP = endP;

	return this;
}

Stroke* Stroke::ResizeScale(double scale_x, double scale_y)
{
	m_endP.x *= scale_x;
	m_endP.y *= scale_y; 

	return this;
}


Stroke* Stroke::Display()
{
	std::cout<<"end point x : "<< m_endP.x<< std::endl;
	std::cout<<"end point y : "<< m_endP.y<< std::endl;
	Shape::Display();
	
	return this;
}
