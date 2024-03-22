#include "../include/Shape.h"
#include "../include/Grawink.h"

using namespace std;

Shape::Shape(point origin, int width, int height, int angle, std::string stroke_color, std::string fill_color, int stroke_width) : m_origin(origin),m_width(width),m_height(height),m_angle(angle),m_stroke_color(stroke_color),m_fill_color(fill_color),m_stroke_width(stroke_width)
{
    m_id = GrawEditor::GetEditor().GetCountId();
}
int Shape::GetId() const
{
    return m_id;
}
int Shape::GetAngle() const
{
    return m_angle;
}
int Shape::GetWidth() const
{
    return m_width;
}

int Shape::GetHeight() const
{
    return m_height;
}

point Shape::GetOrigin() const
{
    return m_origin;
}

bool operator==(Shape const& a, Shape const& b)
{
    return  a.GetId()== b.GetId();
}

void Shape::Display() const
{
    cout<<"id : "<< m_id << endl;
}

void Shape::Rotate(double angle) 
{
    m_angle = angle;
}

void Shape::Translate(int x , int y)
{
    m_origin.x = x;
    m_origin.y = y;
}

void Shape::Resize(int width,int height)
{
    m_width = width;
    m_height = height;
}

void Shape::Color(std::string stroke_color, std::string fill_color = "none")
{
    m_stroke_color = stroke_color;
    m_fill_color = fill_color;
}

