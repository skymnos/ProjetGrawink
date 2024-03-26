#include "../include/RegularPolygone.h"
#include <cmath>
RegularPolygone::RegularPolygone(point origin, int sideNb, int radius, int angle, std::string stroke_color, int stroke_width, std::string fill_color, double fill_opacity) : Shape(origin, angle, stroke_color, stroke_width, fill_color, fill_opacity), m_radius(radius)
{
    m_sideNb = sideNb;
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

    for (int i = 0; i < m_sideNb; i++)
    {
        double constructionAngle = 2 * 3.14159265358979323846 * i /m_sideNb;
        point point;
        point.x = m_origin.x + radius * std::cos(constructionAngle);
        point.y = m_origin.y + radius * std::sin(constructionAngle);
        m_vectorPoint.push_back(point);
    }
}

std::string RegularPolygone::ConvertSVG() const
{
	std::string points ="";
	for (int i = 0; i < m_vectorPoint.size(); i++)
	{
		points += std::to_string(m_vectorPoint[i].x) + ", " + std::to_string(m_vectorPoint[i].y) + " ";
	}

	return "<polygon points=\""+ points +"\" stroke = \""+ m_stroke_color +"\" fill = \""+ m_fill_color +"\" stroke-width = \""+ std::to_string(m_stroke_width) +"\" fill-opacity =\""+ std::to_string(m_fill_opacity) +"\" transform = \"rotate("+ std::to_string(m_angle)  +") translate("+ std::to_string(m_translate.x) + ","+  std::to_string(m_translate.y) + ") scale("+ std::to_string(m_scale) +") \"/>\n";
}


RegularPolygone* RegularPolygone::Display()
{

	for (int i = 0; i < m_vectorPoint.size(); i++)
	{
		std::cout<<"point "<<i<< " x : "<<m_vectorPoint[i].x<<" y : "<<m_vectorPoint[i].y<<std::endl;
	}
	Shape::Display();

	return this;
}