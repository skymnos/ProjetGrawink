#include <iostream>
#include "../externalLibrary/liste_chainee.h"
#include "../include/Grawink.h"
#include <fstream>

// constructeur par default
GrawEditor::GrawEditor()
{
    countId = 0;
}

ListeShape* GrawEditor::getlShapes()
{
    return m_lShapes;
}
ListeAction* GrawEditor::getlUndo()
{
    return m_lUndo;
}
ListeAction* GrawEditor::getlRedo()
{
    return m_lRedo;
}
int GrawEditor::GetCountId()
{
    return countId;
}


GrawEditor& GrawEditor::Delete(int shapeId)
{

}

GrawEditor& GrawEditor::Resize(int width, int height)
{
    int scaleX,scaleY;
    scaleX = width/canvasWidth;
    scaleY = height/canvasHeight;
    canvasHeight = height;
    canvasWidth = width;
    ElementShape *current = m_lShapes->GetHead();

    int shapeHeight;
    int shapeWidth;
    point shapeOrigin;

    for (int i =0; i < m_lShapes->GetLength(); i++)
    {
        shapeHeight = current->shape.GetHeight();
        shapeWidth = current->shape.GetWidth();
        shapeOrigin = current->shape.GetOrigin();

        current->shape.Resize(shapeHeight * scaleY, shapeWidth * scaleX);
        current->shape.Translate(shapeOrigin.x * scaleX, shapeOrigin.y * scaleY);

        current = current->next;

        
    }
}


GrawEditor& GrawEditor::Add(Shape newShape)
{
    m_lShapes->AppendFirst(newShape);
    countId++;
}

GrawEditor& GrawEditor::ExportSVG(std::string fileName)
{
    std::ofstream MyFile(fileName);

    std::string header = "<svg width = \"" + std::to_string(100) + "\" height = \"" + std::to_string(100) + "\" version = \"1.1\" xmlns = \"http://www.w3.org/2000/svg\">\n";
    
    // Write to the file
    MyFile << header;

    ElementShape* current = m_lShapes->GetHead();
    //MyFile << current->shape //appeler la fonction de chaque forme qui ressort le format svg (à créer pour chaque shape)
    for (int i = 1; i < m_lShapes->GetLength(); i++) 
    {
        current = current->next
        //MyFile << current->shape //appeler la fonction de chaque forme qui ressort le format svg (à créer pour chaque shape)
    }
    MyFile << "</svg>";
    // Close the file
    MyFile.close();
}

