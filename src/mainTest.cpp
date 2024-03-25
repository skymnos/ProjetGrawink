#include <iostream>
#include "../include/Shape.h"
#include "../include/Rectangle.h"
#include "../include/Stroke.h"
#include "../include/Ellipsis.h"
#include "../include/Polygone.h"
#include "../include/Text.h"

int main()
{
    GrawEditor canvas = GrawEditor::GetEditor();
    Shape *rectangle, *poly1, *text1, *rectangle2, *ellipsis, *poly2;
    Stroke *stroke;
    Polygone *polygone;
    //Polygone *poly1;
    //Rectangle *rectangle;
    canvas.Resize(2000, 2000);
    rectangle2 = canvas.GetNew<Rectangle>();
    rectangle = new Rectangle({20,20}, 50, 20, 0, "black", 1, "red", 0.5);
    stroke = new Stroke({0,0},{100,300},0, "green", 3);
    polygone = new Polygone({0,0}, {{30, 30}, {0, 30}, {30,0}});
    poly1 = new Polygone({1000,1000}, {{800,600}, {700, 500}, {1300,450}});
    poly2 = new Polygone({300,500}, {{1500,300}, {50, 600}, {1100,1100}, {250, 250}});
    text1 = new Text({200, 200}, "je suis Matteo");
    ellipsis = canvas.GetNew<Ellipsis>();
    std::cout<<"ID count : " << canvas.GetCountId() <<std::endl;

    rectangle->Rotate(30);
    rectangle2->Scale(3);
    rectangle2->Color("blue", "green", 0.3);
    canvas.Add(poly2);
    canvas.Add(rectangle2);
    canvas.Add(rectangle);
    canvas.Add(stroke);
    canvas.Add(polygone);
    canvas.Undo();
    canvas.Add(poly1);
    canvas.Add(text1);
    canvas.Add(ellipsis);

    if (rectangle2->GetShapeType() == GrawEditor::ShapeType::Rectangle)
    {
        std::cout<< "c'est un rectangle" <<std::endl;
    }
    else
    {
        std::cout<< "ce n'est pas un rectangle" <<std::endl;
    }
    std::cout<<"_______________________________"<<std::endl;
    //poly1->Resize({{120,140},{130,160},{10, 250}});
    poly1->Scale(0.5);
    rectangle->Scale(2);
    std::cout<<"_______________________________"<<std::endl;
    std::cout<<polygone->ConvertSVG()<<std::endl;
    canvas.ExportSVG();
    
    std::cout<<"ID count : " << canvas.GetCountId() <<std::endl;
    std::cout<<"CHECK" <<std::endl;
    return 0;
}