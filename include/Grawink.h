#ifndef _GRAWINK_H_
#define _GRAWINK_H_


#include <cstdint>
#include <iostream>
#include "Shape.h"
#include "../externalLibrary/liste_chainee.h"

class GrawEditor {

  
  public:

    enum class ShapeType: uint64_t {
      Stroke    = 1ULL << 0,  // = 0000 0001 = 0x01 =   1
      Triangle  = 1ULL << 1,  // = 0000 0010 = 0x02 =   2
      Rectangle = 1ULL << 2,  // = 0000 0100 = 0x04 =   4
      Pentagon  = 1ULL << 3,  // = 0000 1000 = 0x08 =   8
      Hexagon   = 1ULL << 4,  // = 0001 0000 = 0x10 =  16
      Heptagon  = 1ULL << 5,  // = 0010 0000 = 0x20 =  32
      Octogon   = 1ULL << 6,  // = 0100 0000 = 0x40 =  64
      Ellipsis  = 1ULL << 7,  // = 1000 0000 = 0x80 = 128
      All       = ~0ULL       // = 111...111 = 0xff...ff = (2^64)-1
    };

    Liste* getlShapes();
    Liste* getlUndo();
    Liste* getlRedo();
    GrawEditor();
    static GrawEditor& GetEditor();

    // Ajoute un nouveau objet au canevas
    //template <typename Shape>  (ne sait pas si necessaire)
    GrawEditor& Add(Shape shape);

    // Supprime un objet du canevas
    GrawEditor& Delete(int shapeId);

    // Annule le dernier ajout d'objet
    GrawEditor& Undo(int nbStep);

    // Réinsère le dernier objet supprimé
    GrawEditor& Redo(int nbStep);

    // Redimensionne le canevas
    GrawEditor& Resize( int width , int height);

    // Redimensionne le canevas en supprimant les objets extérieurs */
    GrawEditor& Crop(double center,double width, double height);

    // Sélectionne les objets à exporter/afficher.
    // La sélection pourra se faire sous la forme d'une disjonction ("OU" binaires) de `enum ShapeType`.
    // Par exemple pour sélectionner uniquement les triangles, les rectangles et les octogones, on pourra passer en paramètre :
    //  ShapeType::Triangle | ShapeType::Rectangle | ShapeType::Octogon, ou
    //  bien l'équivalent en hexadécimal (0x46ULL), ou en décimal (70ULL).
    // Passer ShapeType::All resélectionne l'ensemble des formes du canevas.
    GrawEditor& Select(ShapeType type, int shapeId);

    // Affiche l'ensemble des objets contenus dans le canevas, triés par
    // catégorie, dans la sortie standard.
    GrawEditor& Print();

    // Écrit le code SVG résultant des objets contenus dans le canevas
    GrawEditor& ExportSVG();

    // Crée une nouvelle instance de la classe `Shape` (i.e. Rectangle,
    // Triangle, Stroke, Circle, etc.) et retourne un pointeur vers l'objet nouvellement alloué.
    // Cet objet peut ensuite être transformé, passé en paramètre à `Add` ou à `Delete`.
    template <typename Shape> Shape *GetNew();

  private:
    Liste *lShapes;
    Liste *lUndo;
    Liste *lRedo;
};

#endif /* _GRAWINK_H_ */
