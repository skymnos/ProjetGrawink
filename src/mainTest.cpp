#include <iostream>
#include "../include/Shape.h"
#include "../include/Rectangle.h"
#include "../include/Stroke.h"
#include "../include/Ellipsis.h"
#include "../include/Polygone.h"

int main()
{
    Stroke *stroke;
    Polygone *polygone;
    Polygone *poly1;
    Rectangle *rectangle;
    GrawEditor::m_GrawEditor.Resize(2000, 2000);
    rectangle = new Rectangle({20,20}, 50, 20, 0, "black", 1, "red");
    stroke = new Stroke({0,0},{100,300},0, "green", 3);
    polygone = new Polygone({0,0}, {{30, 30}, {0, 30}, {30,0}});
    poly1 = new Polygone({1000,1000}, {{800,600}, {700, 500}, {1300,450}});
    std::cout<<"ID count : " << GrawEditor::GetEditor().GetCountId() <<std::endl;

    rectangle->Rotate(30);
    GrawEditor::m_GrawEditor.Add(rectangle);
    GrawEditor::m_GrawEditor.Add(stroke);
    GrawEditor::m_GrawEditor.Add(polygone);
    GrawEditor::m_GrawEditor.Undo();
    GrawEditor::m_GrawEditor.Add(poly1);

    std::cout<<"_______________________________"<<std::endl;
    //poly1->Resize({{120,140},{130,160},{10, 250}});
    poly1->ResizeScale(1.2);
    rectangle->ResizeScale(2,2);
    std::cout<<"_______________________________"<<std::endl;
    std::cout<<polygone->ConvertSVG()<<std::endl;
    GrawEditor::m_GrawEditor.ExportSVG();
    
    std::cout<<"ID count : " << GrawEditor::GetEditor().GetCountId() <<std::endl;
    std::cout<<"CHECK" <<std::endl;
    return 0;
}