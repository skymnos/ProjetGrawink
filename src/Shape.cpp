#include "../include/Shape.h"

using namespace std;

Shape::Shape(int id) : m_id(id)
{

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

void Shape::SetOrigin(int x, int y)
{
    m_origin.x = x;
    m_origin.y = y;
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
    
}

