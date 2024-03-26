#ifndef _SHAPE_H
#define _SHAPE_H
#include <iostream>
#include <string>
#include <cstdint>


typedef struct point {
 int x;
 int y;
} point;

class Shape 
{
    public :

        Shape(point m_origin = {0,0}, int m_angle = 0, std::string m_stroke_color = "black", int m_stroke_width = 4, std::string m_fill_color = "black", double fill_opacity = 1);
        int GetId() const;

        // rotation de l'objet
        Shape* Rotate(double angle); 

        // deplacement de l'objet
        Shape* Translate(point translate);

        Shape* Scale(double scale);

        // change la couleur de l'objet
        Shape* Color(std::string stroke_color, std::string fill_color, double fill_opacity);

        // redimention de l'objet

        virtual Shape* Display();

        int GetAngle() const;

        point GetOrigin() const;

        virtual std::string ConvertSVG() const;

        uint64_t GetShapeType();
        int GetSideNb();
        
    protected:
        bool m_selected = false;
        point m_origin;
        int m_id;
        std::string m_stroke_color;
        std::string m_fill_color;
        //int m_width, m_height;
        uint64_t m_type;
        double m_angle;
        double m_scale;
        point m_translate;
        int m_stroke_width;
        double m_fill_opacity;
        int m_sideNb;

};

bool operator==(Shape const& a, Shape const& b);


#endif