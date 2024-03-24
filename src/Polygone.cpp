#include "../include/Polygone.h"

Polygone::Polygone(point origin, std::vector<point> vectorPoint, int angle, std::string stroke_color, int stroke_width, std::string fill_color) : Shape(origin, angle, stroke_color, stroke_width, fill_color), m_vectorPoint(vectorPoint)
{
		//je ne sais pas comment initialiser le tabPoint dans le .h et .cpp
}


std::string Polygone::ConvertSVG() const
{
	std::string points = "";
	for (int i = 0; i < m_vectorPoint.size(); i++)
	{
		points += std::to_string(m_vectorPoint[i].x) + ", " + std::to_string(m_vectorPoint[i].y) + " ";
	}

	return "<polygon points=\""+ points +"\" stroke = \""+ m_stroke_color +"\" fill = \""+ m_fill_color +"\" stroke-width = \""+ std::to_string(m_stroke_width) +"\"/>\n";
}

void Polygone::Resize()
{

}

void Polygone::Display() const
{
	Shape::Display();
}