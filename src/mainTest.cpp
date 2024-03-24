#include <iostream>
#include "../include/Shape.h"
#include "../include/Rectangle.h"
#include "../include/Stroke.h"
#include "../include/Ellipsis.h"
#include "../include/Polygone.h"

int main()
{
    Shape *rectangle, *stroke, *polygone;
    Polygone *poly1;
    rectangle = new Rectangle({20,20}, 50, 20, 0, "black", 1, "red");
    stroke = new Stroke({0,0},{100,300},0, "green", 3);
    polygone = new Polygone({0,0}, {{30, 30}, {0, 30}, {30,0}});
    poly1 = new Polygone({100,300}, {{80,300}, {80, 250}, {100,250}});
    GrawEditor::m_GrawEditor.Resize(500, 500);
    std::cout<<"ID count : " << GrawEditor::GetEditor().GetCountId() <<std::endl;


    GrawEditor::m_GrawEditor.Add(rectangle);
    GrawEditor::m_GrawEditor.Add(stroke);
    GrawEditor::m_GrawEditor.Add(polygone);
    GrawEditor::m_GrawEditor.Add(poly1);

    std::cout<<"_______________________________"<<std::endl;
    poly1->Resize({{120,140},{130,160},{10, 250}});
    std::cout<<"_______________________________"<<std::endl;
    std::cout<<polygone->ConvertSVG()<<std::endl;
    GrawEditor::m_GrawEditor.ExportSVG();
    
    std::cout<<"ID count : " << GrawEditor::GetEditor().GetCountId() <<std::endl;
    std::cout<<"CHECK" <<std::endl;
    return 0;
}