#include "../include/Polygone.h"

Polygone::Polygone(point origin, point tabPoint[], int angle, std::string stroke_color, int stroke_width, std::string fill_color) : Shape(origin, angle, stroke_color, stroke_width, fill_color)
{
		//je ne sais pas comment initialiser le tabPoint dans le .h et .cpp
}


std::string Polygone::ConvertSVG() const
{
	std::string points = "";
	for (int i = 0; i < sizeof(m_tabPoint); i++)
	{
		points += std::to_string(m_tabPoint[i].x) + ", " + std::to_string(m_tabPoint[i].y) + " ";
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