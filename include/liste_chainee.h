#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Shape.h"

class Shape;

template <typename T>
struct Element {
    T* data ;
    Element* next; 
}; 
/*struct ElementAction {
    Shape* shape;  //................. a modifier plus tard .......................
    ElementAction* next; 
}; */


template <typename T>
class List {
private:
    Element<T>* head;
    int length;

public:

    List(): head(nullptr), length(0) {};
    ~List()
    {
        Element<T>* current = head;
        while (current != nullptr) {
            Element<T>* next = current->next;
            delete current;
            current = next;
        }
    };

    void AppendFirst( T *t)
    {
        Element<T>* newElement = new Element<T>{t, nullptr};

        if (head == nullptr) {
            head = newElement;
        } else {
            newElement->next = head;
            head = newElement;
        }

        length ++;
    };

    void DeleteFirst()
    {
        if (head == nullptr)
        {
            exit(EXIT_FAILURE);
        }
        else
        {
            Element<T>* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        length --;
    };

    void Display() const
    {
        Element<T>* current = head;
        while (current != nullptr) {
            // Supposons que Shape possède une méthode display() pour afficher ses détails
            current->data->Display();
            current = current->next;
        }
    };

    Element<T>* Find( T *t) const
    {
        Element<T>* current = head;
        while (current != nullptr) {
            if (current->data == t) {
                return current;
            }
            current = current->next;
        }
        return nullptr; // Si l'élément n'est pas trouvé
    };

    void Append( T *t, int index)
    {
        if (index < 0) {
            std::cerr << "Index invalide." << std::endl;
            return;
        }

        Element<T>* newElement = new Element<T>{t, nullptr};
        if (index == 0) {
            newElement->next = head;
            head = newElement;
            return;
        }

        Element<T>* current = head;
        int currentIndex = 0;
        while (current != nullptr && currentIndex < index - 1) {
            current = current->next;
            ++currentIndex;
        }
        if (current == nullptr) {
            std::cerr << "Index hors limites." << std::endl;
            return;
        }
        newElement->next = current->next;
        current->next = newElement;
        length ++;
    };

    void Delete(T *t)
    {
        Element<T>* current = head;
        Element<T>* previous = nullptr;

        if (current->data == t)
        {
            head = current->next;
            delete current;
        }
        else
        {
            while (current->data != t)
            {
                previous = current;
                current = current->next;
            }
            Element<T>* toDelete = current;
            previous->next = current->next;
            delete toDelete;
        }

        length--;
    };

    int GetLength()
    {
        return length;
    };
    Element<T>* GetHead()
    {
        return head;
    };


};

/*class ListeAction {
private:
    ElementAction* head;

public:

    ListeAction();
    ~ListeAction();

    void append( Shape *shape);

    void Display() const;

    ElementAction* rechercher( Shape *shape) const;

    void inserer( Shape *shape, int index);

};*/

#endif
