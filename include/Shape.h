#ifndef _SHAPE_H
#define _SHAPE_H
#include <iostream>
#include "Grawink.h"

typedef struct point {
 int x;
 int y;
} point;

class Shape 
{
    public :

        Shape(int id = 0);
        int GetId() const;

        // rotation de l'objet
        void Rotate(double angle); 

        // deplacement de l'objet
        void Translate(int x, int y);

        // change la couleur de l'objet
        void Color(std::string color);

        // redimention de l'objet
        void Resize(int height, int width);

        void Display() const;

        int GetWidth() const;

        int GetHeight() const;

        int GetAngle() const;

        point GetOrigin() const;

        void SetOrigin(int x, int y);
        
    private:
        bool m_selected = false;
        point m_origin;
        int m_id;
        int m_width, m_height;
        GrawEditor::ShapeType m_type;
        double m_angle;

};

bool operator==(Shape const& a, Shape const& b);


#endif 