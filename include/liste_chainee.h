#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Shape.h"

class Shape;

struct ElementShape {
    Shape& shape ;
    ElementShape* next; 
}; 
struct ElementAction {
    Shape& shape;  //................. a modifier plus tard .......................
    ElementAction* next; 
}; 


class ListeShape {
private:
    ElementShape* head;
    int length;

public:

    ListeShape();
    ~ListeShape();

    void AppendFirst( Shape& shape);

    void DeleteFirst();

    void Display() const;

    ElementShape* Find( Shape& shape) const;

    void Append( Shape& shape, int index);

    void Delete(int id);

    int GetLength();
    ElementShape* GetHead();


};

class ListeAction {
private:
    ElementAction* head;

public:

    ListeAction();
    ~ListeAction();

    void append( Shape& shape);

    void Display() const;

    ElementAction* rechercher( Shape& shape) const;

    void inserer( Shape& shape, int index);

};

#endif
