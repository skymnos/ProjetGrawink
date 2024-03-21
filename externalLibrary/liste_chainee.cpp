#include "liste_chainee.h"
#include "../include/Grawink.h"

// Constructeur par défaut
Liste::Liste() : head(nullptr) {}

// Destructeur
Liste::~Liste() {
    Element* current = head;
    while (current != nullptr) {
        Element* next = current->next;
        delete current;
        current = next;
    }
}

// Méthode pour ajouter un élément à la fin de la liste
void Liste::append(const Shape& shape) {
    Element* newElement = new Element{shape, nullptr};

    if (head == nullptr) {
        head = newElement;
    } else {
        Element* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newElement;
    }
}

// Méthode pour afficher les éléments de la liste
void Liste::Display() const {
    Element* current = head;
    while (current != nullptr) {
        // Supposons que Shape possède une méthode display() pour afficher ses détails
        current->shape.Display();
        current = current->next;
    }
}


// Méthode pour rechercher un élément dans la liste
Element* Liste::rechercher(const Shape& shape) const {
    Element* current = head;
    while (current != nullptr) {
        if (current->shape == shape) {
            return current;
        }
        current = current->next;
    }
    return nullptr; // Si l'élément n'est pas trouvé
}

// Méthode pour insérer un élément à un emplacement spécifique de la liste
void Liste::inserer(const Shape& shape, int index) {
    if (index < 0) {
        std::cerr << "Index invalide." << std::endl;
        return;
    }

    Element* newElement = new Element{shape, nullptr};
    if (index == 0) {
        newElement->next = head;
        head = newElement;
        return;
    }

    Element* current = head;
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
}
