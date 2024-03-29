#include <iostream>
#include <fstream>
#include <string>
#include "../include/Grawink.h"
#include "../include/Shape.h"


List<Shape> m_lShapes;
List<Shape> m_lSelectedShapes;
List<Shape> m_lUndo;
List<Shape> m_lRedo;

GrawEditor GrawEditor::m_GrawEditor = GrawEditor();

// constructeur par default
GrawEditor::GrawEditor()
{
    canvasHeight = 100;
    canvasWidth = 100;
    canvasOrigin = {0,0};
}

GrawEditor& GrawEditor::GetEditor()
{
    return m_GrawEditor;
}

List<Shape> GrawEditor::getlShapes()
{
    return m_lShapes;
}
List<Shape> GrawEditor::getlSelectedShapes()
{
    return m_lSelectedShapes;
}
List<Shape> GrawEditor::getlUndo()
{
    return m_lUndo;
}
List<Shape> GrawEditor::getlRedo()
{
    return m_lRedo;
}


GrawEditor& GrawEditor::Delete(Shape *newShape)
{
    m_lRedo.AppendFirst(newShape);
    m_lUndo.Delete(newShape);
    m_lSelectedShapes.Delete(newShape);
    m_lShapes.Delete(newShape);
    return m_GrawEditor;
}

GrawEditor& GrawEditor::Resize(point origin, int width, int height)
{
    canvasHeight = height;
    canvasWidth = width;
    canvasOrigin = origin;

    return m_GrawEditor;
}

GrawEditor& GrawEditor::Crop(point origin, int width, int height)
{
    canvasHeight = height;
    canvasWidth = width;
    canvasOrigin = origin;

    Element<Shape>* current = m_lShapes.GetHead();

    while (current != nullptr)
    { 
        Shape* toDelete = nullptr;
        point shapeOrigin = current->data->GetOrigin();
        if (shapeOrigin.x > canvasWidth || shapeOrigin.x < -canvasOrigin.x || shapeOrigin.y > canvasHeight || shapeOrigin.y < -canvasOrigin.y)
        {
            toDelete = current->data;
        }
        current = current->next;
        if (toDelete != nullptr)
        {
            Delete(toDelete);
        }
    }
    

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

    return m_GrawEditor;
}

GrawEditor& GrawEditor::ExportSVG( std::string fileName)
{

    std::ofstream MyFile(fileName + ".svg");

    std::string header = "<svg width = \"" + std::to_string(canvasHeight) + "\" height = \"" + std::to_string(canvasWidth) + "\" version = \"1.1\" xmlns = \"http://www.w3.org/2000/svg\">\n<svg x=\""+ std::to_string(canvasOrigin.x) +"\" y=\""+ std::to_string(canvasOrigin.y) +"\" overflow = \"visible\">\n";
    
    // Write to the file
    MyFile << header;

    Element<Shape>* current = m_lSelectedShapes.GetHead(); // cause une erreure de segmentation

    while (current != nullptr)
    {
        MyFile << current->data->ConvertSVG(); //appelle la fonction de chaque forme qui ressort le format svg (� cr�er pour chaque shape)
        current = current->next;
    }
    
    MyFile << "</svg>\n</svg>";
    // Close the file
    MyFile.close();

    return m_GrawEditor;
}

GrawEditor& GrawEditor::Undo(int step)
{
    for (int i = 0; i < step; i++)
    {
        if (m_lUndo.GetHead() != nullptr)
        {
            Shape *toDelete = m_lUndo.GetHead()->data;
            m_GrawEditor.Delete(m_lUndo.GetHead()->data);
        }
        else
        {
            std::cout << "no undo possible" << std::endl;
        }   
    }
    
    return m_GrawEditor;
}

GrawEditor& GrawEditor::Redo(int step)
{
    for (int i = 0; i < step; i++)
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
    }

    return m_GrawEditor;
}

GrawEditor& GrawEditor::Print()
{
    Element<Shape>* current = m_lSelectedShapes.GetHead();
    if (current == nullptr)
    {
        std::cout << "No Shape in the list" << std::endl;
        return m_GrawEditor;
    }

    std::cout << "List of all shapes selected : " << std::endl;

    for (int i = 0; i < m_lSelectedShapes.GetLength(); i++)
    {
        std::cout << current->data->ConvertSVG() << std::endl;
        current = current->next;
    }

    std::cout << "_______________________________" << std::endl;

    return m_GrawEditor;
}

GrawEditor& GrawEditor::Select(ShapeType type, Shape *shape)
{
    m_lSelectedShapes.Clear();

    Element<Shape>* current = m_lShapes.GetHead();

    if (current == nullptr)
    {
        std::cout << "nothing to select" << std::endl;
    }

    if (shape != nullptr)
    {
        while (shape != current->data && current != nullptr)
        {
            current = current->next;
        }
        if (current != nullptr)
        {
            m_lSelectedShapes.AppendFirst(current->data);
        }
        return m_GrawEditor;
    }

    while (current != nullptr)
    {
        if (static_cast<uint64_t>(current->data->GetShapeType()) & static_cast<uint64_t>(type))
        {
            m_lSelectedShapes.AppendFirst(current->data);
        }
        current = current->next;
    }

    return m_GrawEditor;
}

GrawEditor& GrawEditor::ClearCanvas()
{
    std::cout << m_lShapes.GetLength() << std::endl;
    std::cout << m_lUndo.GetLength() << std::endl;
    std::cout << m_lRedo.GetLength() << std::endl;

    Element<Shape> *current = m_lShapes.GetHead();

    while (current != nullptr)
    {
        std::cout << current->data->ConvertSVG() << std::endl;
        current = current->next;
    }
    std::cout << "********************************************************" << std::endl;

    current = m_lUndo.GetHead();

    while (current != nullptr)
    {
        if (current->data != nullptr)
        {
            std::cout << current->data->ConvertSVG() << std::endl;
            delete current->data;
        }
        current = current->next;
    }

    current = m_lRedo.GetHead();

    while (current != nullptr)
    {

        if (current->data != nullptr)
        {
            std::cout << current->data->ConvertSVG() << std::endl;
            delete current->data ;
        }
        current = current->next;
    }

    m_lShapes.Clear();
    m_lSelectedShapes.Clear();
    m_lUndo.Clear();
    m_lRedo.Clear();  

    return m_GrawEditor;
}

