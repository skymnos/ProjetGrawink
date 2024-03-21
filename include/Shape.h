#ifndef _SHAPE_H
#define _SHAPE_H
#include <iostream>

typedef struct point {
 int x;
 int y;
} point;

class Shape 
{
    public :

        Shape(const point& m_origin = {0,0}, int m_width = 1, int m_height = 1, int m_angle = 0, std::string m_color = "black");
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
        
    private:
        bool m_selected = false;
        point m_origin;
        int m_id;
        std::string m_color;
        int m_width, m_height;
        GrawEditor::ShapeType m_type;
        double m_angle;

};

bool operator==(Shape const& a, Shape const& b);


#endif