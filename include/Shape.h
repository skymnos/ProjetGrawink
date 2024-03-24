#ifndef _SHAPE_H
#define _SHAPE_H
#include <iostream>
#include <string>
#include "Grawink.h"


typedef struct point {
 int x;
 int y;
} point;

class Shape 
{
    public :

        Shape(point m_origin = {0,0}, int m_angle = 0, std::string m_stroke_color = "black", int m_stroke_width = 4, std::string m_fill_color = "black");
        int GetId() const;

        // rotation de l'objet
        void Rotate(double angle); 

        // deplacement de l'objet
        void Translate(int x, int y);

        // change la couleur de l'objet
        void Color(std::string stroke_color, std::string fill_color);

        // redimention de l'objet

        virtual void Display() const;

        int GetAngle() const;

        point GetOrigin() const;

        virtual std::string ConvertSVG() const;
        
    protected:
        bool m_selected = false;
        point m_origin;
        int m_id;
        std::string m_stroke_color;
        std::string m_fill_color;
        //int m_width, m_height;
        //GrawEditor::ShapeType m_type;
        double m_angle;
        int m_stroke_width;

};

bool operator==(Shape const& a, Shape const& b);


#endif