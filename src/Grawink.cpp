#include <iostream>
#include "../externalLibrary/liste_chainee.h"
#include "../include/Grawink.h"

// constructeur par default
GrawEditor::GrawEditor():lShapes(initialiser()),lUndo(initialiser()),lRedo(initialiser())
{

}

Liste* GrawEditor::getlShapes()
{
    return lShapes;
}
Liste* GrawEditor::getlUndo()
{
    return lUndo;
}
Liste* GrawEditor::getlRedo()
{
    return lRedo;
}

GrawEditor& GrawEditor::Add(Shape shape)
{
    insererDebut(lShapes,shape);
}


