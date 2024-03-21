#include <iostream>
#include "../externalLibrary/liste_chainee.h"
#include "../include/Grawink.h"

// constructeur par default
GrawEditor::GrawEditor()
{

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

GrawEditor& GrawEditor::Add(Shape shape)
{
    m_lShapes->AppendFirst(shape);
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
        current->shape.SetOrigin(shapeOrigin.x * scaleX, shapeOrigin.y * scaleY);

        current = current->next;

        
    }
}


