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

    
        // rotation de l'objet
         void Rotate(double angle); 

        // deplacement de l'objet
        void Translate(int x, int y);

        // change la couleur de l'objet
        void Color(std::string color);

        // redimention de l'objet
        void Resize(double scale);
        
    private:
        bool selected = false;
        point origin;

};


#endif 