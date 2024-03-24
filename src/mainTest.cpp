#include <iostream>
#include "../include/Shape.h"
#include "../include/Rectangle.h"
#include "../include/Stroke.h"
#include "../include/Ellipsis.h"
<<<<<<< HEAD


int main()
{
    ListeShape myList;
    Shape myShape;
    Shape myShape2({10,45});
    Rectangle rectangle({20,20}, 50, 20, 0, "black", 1, "red");
    Stroke stroke({0,0},{200,200},0, "blue", 5);
    Ellipsis ellipsis({100,100},20,30,0,"blue",1,"black");
=======
#include "../include/Polygone.h"

int main()
{
    Shape *rectangle, *stroke;
    rectangle = new Rectangle({20,20}, 50, 20, 0, "black", 1, "red");
    stroke = new Stroke({0,0},{100,200},0, "blue", 5);
>>>>>>> main
    GrawEditor::m_GrawEditor.Resize(200, 200);
    std::cout<<"ID count : " << GrawEditor::GetEditor().GetCountId() <<std::endl;


    GrawEditor::m_GrawEditor.Add(rectangle);
    GrawEditor::m_GrawEditor.Add(stroke);
<<<<<<< HEAD
    GrawEditor::m_GrawEditor.Add(ellipsis);
    GrawEditor::m_GrawEditor.Delete(0);
    std::cout<<"____________________________________"<<std::endl;
    stroke.Resize({20,20},{100,50});
    std::cout<<"____________________________________"<<std::endl;
    std::cout << "lShapes : " << GrawEditor::m_GrawEditor.getlShapes().GetLength() << std::endl;
    //GrawEditor::m_GrawEditor.Resize(400, 400);
=======
>>>>>>> main
    GrawEditor::m_GrawEditor.ExportSVG();
    std::cout<<"ID count : " << GrawEditor::GetEditor().GetCountId() <<std::endl;
    std::cout<<"CHECK" <<std::endl;
    return 0;
}