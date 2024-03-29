#include "../include/Polygone.h"
#include <cmath>

Polygone::Polygone(point origin, std::vector<point> vectorPoint, int angle, std::string stroke_color, int stroke_width, std::string fill_color, double fill_opacity) : Shape(origin, angle, stroke_color, stroke_width, fill_color, fill_opacity), m_vectorPoint(vectorPoint)
{
	m_sideNb = m_vectorPoint.size() + 1;

	switch (m_sideNb)
    {
        case 3:
            m_type = 1ULL << 1;
            break;
        case 5:
            m_type = 1ULL << 3;
            break;
        case 6:
            m_type = 1ULL << 4;
            break;
        case 7:
            m_type = 1ULL << 5;
            break;
        case 8:
            m_type = 1ULL << 6;
            break;
        
        default:
            m_type = 1ULL << 8;
            break;
    }
}

Polygone* Polygone::Modify(point origin, std::vector<point> vectorPoint, int angle, std::string stroke_color, int stroke_width, std::string fill_color, double fill_opacity)
{
	m_origin = origin;
	m_vectorPoint = vectorPoint;
	m_angle = angle;
	m_stroke_color = stroke_color;
	m_stroke_width = stroke_width;
	m_fill_color = fill_color;
	m_fill_opacity = fill_opacity;
	
	switch (m_sideNb)
    {
        case 3:
            m_type = 1ULL << 1;
            break;
        case 5:
            m_type = 1ULL << 3;
            break;
        case 6:
            m_type = 1ULL << 4;
            break;
        case 7:
            m_type = 1ULL << 5;
            break;
        case 8:
            m_type = 1ULL << 6;
            break;
        
        default:
            m_type = 1ULL << 8;
            break;
    }

	return this;
}


std::string Polygone::ConvertSVG() const
{
	std::string points = std::to_string(m_origin.x) + "," +std::to_string(m_origin.y) + " ";
	for (uint i = 0; i < m_vectorPoint.size(); i++)
	{
		points += std::to_string(m_vectorPoint[i].x) + ", " + std::to_string(m_vectorPoint[i].y) + " ";
	}

	return "<polygon points=\""+ points +"\" stroke = \""+ m_stroke_color +"\" fill = \""+ m_fill_color +"\" stroke-width = \""+ std::to_string(m_stroke_width) +"\" fill-opacity =\""+ std::to_string(m_fill_opacity) +"\" transform = \"rotate("+ std::to_string(m_angle)  +") translate("+ std::to_string(m_translate.x) + ","+  std::to_string(m_translate.y) + ") scale("+ std::to_string(m_scale) +") \"/>\n";
}


Polygone* Polygone::Display()
{

	for (uint i = 0; i < m_vectorPoint.size(); i++)
	{
		std::cout<<"point "<<i<< " x : "<<m_vectorPoint[i].x<<" y : "<<m_vectorPoint[i].y<<std::endl;
	}
	Shape::Display();

	return this;
}