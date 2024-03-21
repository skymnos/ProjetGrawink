#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "../include/Shape.h"


struct ElementShape {
    Shape shape ;
    ElementShape* next; 
}; 
struct ElementAction {
    Shape shape;  //................. a modifier plus tard .......................
    ElementAction* next; 
}; 


class ListeShape {
private:
    ElementShape* head;
    int length;

public:

    ListeShape();
    ~ListeShape();

    void AppendFirst(const Shape& shape);

    void DeleteFirst();

    void Display() const;

    ElementShape* Find(const Shape& shape) const;

    void Append(const Shape& shape, int index);

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

    void append(const Shape& shape);

    void Display() const;

    ElementAction* rechercher(const Shape& shape) const;

    void inserer(const Shape& shape, int index);

};

#endif
