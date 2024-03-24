#include <iostream>
#include "../include/Shape.h"
#include "../include/Rectangle.h"
#include "../include/Stroke.h"
#include "../include/Ellipsis.h"
#include "../include/Polygone.h"

int main()
{
    Shape *rectangle, *stroke;
    rectangle = new Rectangle({20,20}, 50, 20, 0, "black", 1, "red");
    stroke = new Stroke({0,0},{200,200},0, "blue", 5);
    std::cout<<"CHECK" <<std::endl;
    ListeShape myList;
    Shape shape;
    //Rectangle rectangle({20,20}, 50, 20, 0, "black", 1, "red");
    //Stroke stroke({0,0},{200,200},0, "blue", 5);
    //Ellipsis ellipsis;
    //Polygone polygone;
    std::cout<<"CHECK" <<std::endl;
    GrawEditor::m_GrawEditor.Resize(200, 200);
    std::cout<<"ID count : " << GrawEditor::GetEditor().GetCountId() <<std::endl;
    //std::cout << "lShapes : " << GrawEditor::m_GrawEditor.getlShapes().GetLength() << std::endl;

    //Polygone &test = polygone;

    //myList.AppendFirst(test);
    ElementShape* current = myList.GetHead(); // cause une erreure de segmentation

    /*for (int i = 1; i < 20; i++) 
    {
        std::cout << "enter for loop : " << i << std::endl;
        std::cout << current->shape.ConvertSVG() << std::endl; //appelle la fonction de chaque forme qui ressort le format svg (� cr�er pour chaque shape)
        std::cout << "loop finished: " << i  << std::endl;
    }*/


    GrawEditor::m_GrawEditor.Add(rectangle);
    GrawEditor::m_GrawEditor.Add(stroke);
    //GrawEditor::m_GrawEditor.Add(polygone);
    //GrawEditor::m_GrawEditor.Add(ellipsis);
    //GrawEditor::m_GrawEditor.Add(shape);

    //GrawEditor::m_GrawEditor.Delete(0);
    //std::cout << "lShapes : " << GrawEditor::m_GrawEditor.getlShapes().GetLength() << std::endl;
    //GrawEditor::m_GrawEditor.Resize(400, 400);
    GrawEditor::m_GrawEditor.ExportSVG();
    std::cout<<"ID count : " << GrawEditor::GetEditor().GetCountId() <<std::endl;
    std::cout<<"CHECK" <<std::endl;
    return 0;
}