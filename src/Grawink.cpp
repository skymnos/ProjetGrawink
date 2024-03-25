#include <iostream>
#include <fstream>
#include <string>
#include "../include/Grawink.h"
#include "../include/Shape.h"


List<Shape> m_lShapes;
List<Shape> m_lUndo;
List<Shape> m_lRedo;

GrawEditor GrawEditor::m_GrawEditor = GrawEditor();

// constructeur par default
GrawEditor::GrawEditor()
{
    countId = 0;
    canvasHeight = 100;
    canvasWidth = 100;
}

GrawEditor& GrawEditor::GetEditor()
{
    return m_GrawEditor;
}

List<Shape> GrawEditor::getlShapes()
{
    return m_lShapes;
}
List<Shape> GrawEditor::getlUndo()
{
    return m_lUndo;
}
List<Shape> GrawEditor::getlRedo()
{
    return m_lRedo;
}
int GrawEditor::GetCountId()
{
    return countId;
}


GrawEditor& GrawEditor::Delete(Shape *newShape)
{
    m_lRedo.AppendFirst(newShape);
    m_lShapes.Delete(newShape);
    return m_GrawEditor;
}

GrawEditor& GrawEditor::Resize(int width, int height)
{
    int scaleX,scaleY;
    scaleX = width/canvasWidth;
    scaleY = height/canvasHeight;
    canvasHeight = height;
    canvasWidth = width;
    /*ElementShape *current = m_lShapes->GetHead();

    if (current == nullptr)
    {
        std::cout<<"No shape to resize" <<std::endl;
    }
    else
    {
        int shapeHeight;
        int shapeWidth;
        point shapeOrigin;

        for (int i =0; i < m_lShapes->GetLength(); i++)
        {
            // reflechir à comment faire selon le shapeType
            shapeHeight = current->shape.GetHeight();
            shapeWidth = current->shape.GetWidth();
            shapeOrigin = current->shape.GetOrigin();

            current->shape.Resize(shapeHeight * scaleY, shapeWidth * scaleX);
            current->shape.Translate(shapeOrigin.x * scaleX, shapeOrigin.y * scaleY);
            

            current = current->next;
        }
    }
*/
    return m_GrawEditor;
}


GrawEditor& GrawEditor::Add(Shape *newShape)
{
    m_lUndo.AppendFirst(newShape);
    Element<Shape>* current = m_lShapes.GetHead();
    
    if (current == nullptr)
    {
        m_lShapes.AppendFirst(newShape);
        return m_GrawEditor;
    }
    
    int index = 0;
    while (newShape->GetSideNb() > current->data->GetSideNb() && current->next != nullptr)
    {
        index ++;
        current = current->next;
    }
    if (newShape->GetSideNb() > current->data->GetSideNb())
    {
        index ++;
    }
    m_lShapes.Append(newShape, index);
    countId++;

    return m_GrawEditor;
}

GrawEditor& GrawEditor::ExportSVG()
{
    std::cout<<"Check" <<std::endl;

    std::ofstream MyFile("test.svg");

    std::string header = "<svg width = \"" + std::to_string(canvasHeight) + "\" height = \"" + std::to_string(canvasWidth) + "\" version = \"1.1\" xmlns = \"http://www.w3.org/2000/svg\">\n";
    
    // Write to the file
    MyFile << header;


    Element<Shape>* current = m_lShapes.GetHead(); // cause une erreure de segmentation

    if (current == nullptr)
    {
        std::cout<<"No shape in the list" <<std::endl;
    }
    else
    {
        MyFile << current->data->ConvertSVG(); //appelle la fonction de chaque forme qui ressort le format svg (� cr�er pour chaque shape)

        while (current->next != nullptr)
        {
            current = current->next;
            MyFile << current->data->ConvertSVG(); //appelle la fonction de chaque forme qui ressort le format svg (� cr�er pour chaque shape)
        }
        
    }

    MyFile << "</svg>";
    // Close the file
    MyFile.close();

    return m_GrawEditor;
}

GrawEditor& GrawEditor::Undo()
{
    if (m_lUndo.GetHead() != nullptr)
    {
        m_GrawEditor.Delete(m_lUndo.GetHead()->data);
        m_lUndo.DeleteFirst();
    }
    else
    {
        std::cout << "no undo possible" << std::endl;
    }
    
    return m_GrawEditor;
}

GrawEditor& GrawEditor::Redo()
{
    if (m_lRedo.GetHead() != nullptr)
    {
        m_GrawEditor.Add(m_lRedo.GetHead()->data);
        m_lRedo.DeleteFirst();
    }
    else
    {
        std::cout << "no redo possible" << std::endl;
    }
    return m_GrawEditor;
}

