#include <iostream>
#include "../include/Shape.h"
#include "../include/Rectangle.h"
#include "../include/Stroke.h"

int main()
{
    ListeShape myList;
    Shape myShape;
    Shape myShape2({10,45});
    Rectangle rectangle({20,20}, 50, 20, 0, "black", 1, "red");
    Stroke stroke({0,0},{200,200},0, "blue", 5);
    GrawEditor::m_GrawEditor.Resize(200, 200);
    std::cout<<"length : " << myList.GetLength() <<std::endl;
    std::cout<<"ID count : " << GrawEditor::GetEditor().GetCountId() <<std::endl;
    std::cout << "lShapes : " << GrawEditor::m_GrawEditor.getlShapes().GetLength() << std::endl;
    GrawEditor::m_GrawEditor.Add(rectangle);
    GrawEditor::m_GrawEditor.Add(stroke);
    GrawEditor::m_GrawEditor.Delete(0);
    std::cout << "lShapes : " << GrawEditor::m_GrawEditor.getlShapes().GetLength() << std::endl;
    //GrawEditor::m_GrawEditor.Resize(400, 400);
    GrawEditor::m_GrawEditor.ExportSVG();
    std::cout<<"ID count : " << GrawEditor::GetEditor().GetCountId() <<std::endl;
    std::cout<<"ID SHApe1 : " << myShape.GetId() <<std::endl;
    std::cout<<"ID SHApe2 : " << myShape2.GetId() <<std::endl;
    myList.AppendFirst(myShape);
    myList.Display();
    myList.Delete(0);
    myList.Display();
    myList.AppendFirst(myShape2);
    myList.Display();
    std::cout<<"length : " << myList.GetLength() <<std::endl;
    myList.Delete(0);
    myList.Display();
    std::cout<<"length : " << myList.GetLength() <<std::endl;
    myList.AppendFirst(myShape2);
    myList.Display();
    std::cout<<"CHECK" <<std::endl;
    return 0;
}