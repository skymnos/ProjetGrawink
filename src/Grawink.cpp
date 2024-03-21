#include <iostream>
#include "../externalLibrary/liste_chainee.h"
#include "../include/Grawink.h"

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


