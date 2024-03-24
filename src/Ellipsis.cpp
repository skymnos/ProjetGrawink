#include "../include/Ellipsis.h"

Ellipsis::Ellipsis(point origin, double r1, double r2, int angle, std::string stroke_color, int stroke_width, std::string fill_color) : Shape(origin, angle, stroke_color, stroke_width, fill_color), m_r1(r1), m_r2(r2)
{

}

std::string Ellipsis::ConvertSVG() const
{
	return "<ellipse cx=\""+ std::to_string(m_origin.x) + "\" cy=\""+ std::to_string(m_origin.y) +"\" rx=\""+ std::to_string(m_r1) +"\" ry=\""+ std::to_string(m_r2) +"\" stroke=\""+ m_stroke_color +"\" fill=\""+ m_fill_color +"\" stroke-width=\""+ std::to_string(m_stroke_width) +"\" transform = \"rotate("+ std::to_string(m_angle) +") translate("+ std::to_string(m_translate.x) + ","+  std::to_string(m_translate.y) + ") scale("+ std::to_string(m_scale) +") \"/>\n";
}


Ellipsis* Ellipsis::Display()
{
	std::cout<<"rayon 1 : "<<m_r1<<std::endl;
	std::cout<<"rayon 2 : "<<m_r2<<std::endl;
	Shape::Display();

	return this;
}