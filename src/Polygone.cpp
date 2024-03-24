#include "../include/Polygone.h"
#include <cmath>

Polygone::Polygone(point origin, std::vector<point> vectorPoint, int angle, std::string stroke_color, int stroke_width, std::string fill_color) : Shape(origin, angle, stroke_color, stroke_width, fill_color), m_vectorPoint(vectorPoint)
{
}


std::string Polygone::ConvertSVG() const
{
	std::string points = std::to_string(m_origin.x) + "," +std::to_string(m_origin.y) + " ";
	for (int i = 0; i < m_vectorPoint.size(); i++)
	{
		points += std::to_string(m_vectorPoint[i].x) + ", " + std::to_string(m_vectorPoint[i].y) + " ";
	}

	return "<polygon points=\""+ points +"\" stroke = \""+ m_stroke_color +"\" fill = \""+ m_fill_color +"\" stroke-width = \""+ std::to_string(m_stroke_width) +"\" transform = \"rotate("+ std::to_string(m_angle) +")\" />\n";
}

Polygone* Polygone::Resize(std::vector<point> vectorPoint)
{
	if (vectorPoint.size() <= m_vectorPoint.size())
	{
		for (int i = 0; i < vectorPoint.size(); i++)
		{
			m_vectorPoint[i] = vectorPoint[i];
		}		
	}
	else
	{
		for (int i = 0; i < m_vectorPoint.size()+1; i++)
		{
			m_vectorPoint[i] = vectorPoint[i];
		}
	}
	
	return this;
}

Polygone* Polygone::ResizeScale(double scale)
{
	for (int i = 0; i < m_vectorPoint.size(); i++)
	{
		double vectX = m_vectorPoint[i].x - m_origin.x;
		double vectY = m_vectorPoint[i].y - m_origin.y;
		m_vectorPoint[i].x = vectX * scale + m_origin.x;
		m_vectorPoint[i].y = vectY * scale + m_origin.y;
	}

	return this;
}


Polygone* Polygone::Display()
{
	Shape::Display();

	for (int i = 0; i < m_vectorPoint.size(); i++)
	{
		std::cout<<"point "<<i<< " x : "<<m_vectorPoint[i].x<<" y : "<<m_vectorPoint[i].y<<std::endl;
	}

	return this;
}