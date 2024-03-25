#include "../include/Shape.h"

using namespace std;

Shape::Shape(point origin, int angle, std::string stroke_color, int stroke_width, std::string fill_color, double fill_opacity) : m_origin(origin),m_angle(angle),m_stroke_color(stroke_color),m_stroke_width(stroke_width),m_fill_color(fill_color),m_fill_opacity(fill_opacity)
{
    m_translate = {0,0};
    m_scale = 1;
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

Shape* Shape::Display()
{
    cout<<"point x : "<<m_origin.x<<endl;
    cout<<"point y : "<<m_origin.x<<endl;
    cout<<"angle : "<<m_angle<<endl;
    cout<<"stroke color : "<<m_stroke_color<<endl;
    cout<<"stroke width : "<<m_stroke_width<<endl;
    cout<<"fill color : "<<m_fill_color<<endl;

    return this;
}

Shape* Shape::Rotate(double angle) 
{
    m_angle = angle;

    return this;
}

Shape* Shape::Translate(point translate)
{
    m_translate = translate;

    return this;
}

Shape* Shape::Scale(double scale)
{
    m_scale = scale;

    return this;
}

Shape* Shape::Color(std::string stroke_color, std::string fill_color = "none", double fill_opacity = 1)
{
    m_stroke_color = stroke_color;
    m_fill_color = fill_color;
    m_fill_opacity = fill_opacity;

    return this;
}

std::string Shape::ConvertSVG() const
{
    std::cout << "isconverted in shape" << std::endl;
    return "";
}

GrawEditor::ShapeType Shape::GetShapeType()
{
    return m_type;
}

int Shape::GetSideNb()
{
    return m_sideNb;
}

