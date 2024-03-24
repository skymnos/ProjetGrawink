#include "../include/Shape.h"
//#include "../include/Grawink.h"

using namespace std;

Shape::Shape(point origin, int angle, std::string stroke_color, int stroke_width, std::string fill_color) : m_origin(origin),m_angle(angle),m_stroke_color(stroke_color),m_stroke_width(stroke_width),m_fill_color(fill_color)
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

void Shape::Resize()
{
}

void Shape::Color(std::string stroke_color, std::string fill_color = "none")
{
    m_stroke_color = stroke_color;
    m_fill_color = fill_color;
}

std::string Shape::ConvertSVG() const
{
    std::cout << "isconverted in shape" << std::endl;
    return "";
}

