#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "../include/Shape.h"


struct Element {
    Shape shape ;
    Element* next; 
};


class Liste {
private:
    Element* head;

public:

    Liste();
    ~Liste();

    void append(const Shape& shape);

    void Display() const;

    Element* rechercher(const Shape& shape) const;

    void inserer(const Shape& shape, int index);

};

#endif
