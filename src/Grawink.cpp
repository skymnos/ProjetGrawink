#include <iostream>
#include "../include/Grawink.h"
#include <fstream>
#include <string>


ListeShape m_lShapes;
ListeAction m_lUndo;
ListeAction m_lRedo;

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

ListeShape GrawEditor::getlShapes()
{
    return m_lShapes;
}
ListeAction GrawEditor::getlUndo()
{
    return m_lUndo;
}
ListeAction GrawEditor::getlRedo()
{
    return m_lRedo;
}
int GrawEditor::GetCountId()
{
    return countId;
}


GrawEditor& GrawEditor::Delete(int shapeId)
{
    return m_GrawEditor;
}

GrawEditor& GrawEditor::Resize(int width, int height)
{
    int scaleX,scaleY;
    scaleX = width/canvasWidth;
    scaleY = height/canvasHeight;
    canvasHeight = height;
    canvasWidth = width;
    ElementShape *current = m_lShapes.GetHead();

    if (current == nullptr)
    {
        std::cout<<"No shape to resize" <<std::endl;
    }
    else
    {
        int shapeHeight;
        int shapeWidth;
        point shapeOrigin;

        for (int i =0; i < m_lShapes.GetLength(); i++)
        {
            // reflechir à comment faire selon le shapeType
            /*shapeHeight = current->shape.GetHeight();
            shapeWidth = current->shape.GetWidth();
            shapeOrigin = current->shape.GetOrigin();

            current->shape.Resize(shapeHeight * scaleY, shapeWidth * scaleX);
            current->shape.Translate(shapeOrigin.x * scaleX, shapeOrigin.y * scaleY);
            */

            current = current->next;
        }
    }

    return m_GrawEditor;
}


GrawEditor& GrawEditor::Add(Shape& newShape)
{
    m_lShapes.AppendFirst(newShape);
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


    ElementShape* current = m_lShapes.GetHead(); // cause une erreure de segmentation

    if (current == nullptr)
    {
        std::cout<<"No shape in the list" <<std::endl;
    }
    else
    {
        std::cout<<"Check" <<std::endl;
        MyFile << current->shape.ConvertSVG(); //appelle la fonction de chaque forme qui ressort le format svg (� cr�er pour chaque shape)
        std::cout << "convert" << std::endl;
        for (int i = 1; i < m_lShapes.GetLength(); i++) 
        {
            current = current->next;
            MyFile << current->shape.ConvertSVG(); //appelle la fonction de chaque forme qui ressort le format svg (� cr�er pour chaque shape)
        }
    }

    MyFile << "</svg>";
    // Close the file
    MyFile.close();

    return m_GrawEditor;
}

