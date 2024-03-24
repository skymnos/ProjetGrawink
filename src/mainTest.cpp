#include <iostream>
#include "../include/Shape.h"
#include "../include/Rectangle.h"
#include "../include/Stroke.h"
#include "../include/Ellipsis.h"
#include "../include/Polygone.h"

int main()
{
    Shape *rectangle, *stroke, *polygone;
    rectangle = new Rectangle({20,20}, 50, 20, 0, "black", 1, "red");
    stroke = new Stroke({0,0},{100,300},0, "green", 3);
    polygone = new Polygone({0,0}, {{30, 30}, {0, 30}, {30,0}});
    GrawEditor::m_GrawEditor.Resize(200, 200);
    std::cout<<"ID count : " << GrawEditor::GetEditor().GetCountId() <<std::endl;


    GrawEditor::m_GrawEditor.Add(rectangle);
    GrawEditor::m_GrawEditor.Add(stroke);
    GrawEditor::m_GrawEditor.Add(polygone);
    GrawEditor::m_GrawEditor.ExportSVG();
    std::cout<<"ID count : " << GrawEditor::GetEditor().GetCountId() <<std::endl;
    std::cout<<"CHECK" <<std::endl;
    return 0;
}