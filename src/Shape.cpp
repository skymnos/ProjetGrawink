#include "../include/Shape.h"

using namespace std;

Shape::Shape(int id) : m_id(id)
{

}

int Shape::getId() const
{
    return m_id;
}

bool operator==(Shape const& a, Shape const& b)
{
    return  a.getId()== b.getId();
}

void Shape::Display() const
{
    cout<<"id : "<< getId() << endl;
}

