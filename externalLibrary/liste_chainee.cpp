#include "liste_chainee.h"
#include "../include/Grawink.h"

// Constructeur par défaut
ListeShape::ListeShape() : head(nullptr), length(0) {}

// Destructeur
ListeShape::~ListeShape() {
    ElementShape* current = head;
    while (current != nullptr) {
        ElementShape* next = current->next;
        delete current;
        current = next;
    }
}

// Méthode pour ajouter un élément à la fin de la liste
void ListeShape::AppendFirst(const Shape& shape) {
    ElementShape* newElement = new ElementShape{shape, nullptr};

    if (head == nullptr) {
        head = newElement;
    } else {
        newElement->next = head;
        head = newElement;
        /*ElementShape* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newElement;*/
    }

    length ++;
}

void ListeShape::DeleteFirst()
{
    if (head == nullptr)
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        ElementShape* toDelete = head;
        head = head->next;
    }
    length --;
}

// Méthode pour afficher les éléments de la liste
void ListeShape::Display() const {
    ElementShape* current = head;
    while (current != nullptr) {
        // Supposons que Shape possède une méthode display() pour afficher ses détails
        current->shape.Display();
        current = current->next;
    }
}


// Méthode pour rechercher un élément dans la liste
ElementShape* ListeShape::Find(const Shape& shape) const {
    ElementShape* current = head;
    while (current != nullptr) {
        if (current->shape == shape) {
            return current;
        }
        current = current->next;
    }
    return nullptr; // Si l'élément n'est pas trouvé
}

// Méthode pour insérer un élément à un emplacement spécifique de la liste
void ListeShape::Append(const Shape& shape, int index) {
    if (index < 0) {
        std::cerr << "Index invalide." << std::endl;
        return;
    }

    ElementShape* newElement = new ElementShape{shape, nullptr};
    if (index == 0) {
        newElement->next = head;
        head = newElement;
        return;
    }

    ElementShape* current = head;
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
}

void ListeShape::Delete(int id)
{
    ElementShape* current = head;
    ElementShape* previous = nullptr;
    while (current->shape.getId() != id)
    {
        previous = current;
        current = current->next;
    }
    ElementShape* toDelete = current;
    previous->next = current->next;

    length--;
}

int ListeShape::GetLength()
{
    return length;
}
ElementShape* ListeShape::GetHead()
{
    return head;
}

//   ......................... LISTEACTION ..................

// Constructeur par défaut
ListeAction::ListeAction() : head(nullptr) {}

// Destructeur
ListeAction::~ListeAction() {
    ElementAction* current = head;
    while (current != nullptr) {
        ElementAction* next = current->next;
        delete current;
        current = next;
    }
}

// Méthode pour ajouter un élément à la fin de la liste
void ListeAction::append(const Shape& shape) {
    ElementAction* newElement = new ElementAction{shape, nullptr};

    if (head == nullptr) {
        head = newElement;
    } else {
        ElementAction* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newElement;
    }
}

// Méthode pour afficher les éléments de la liste
void ListeAction::Display() const {
    ElementAction* current = head;
    while (current != nullptr) {
        // Supposons que Shape possède une méthode display() pour afficher ses détails
        current->shape.Display();
        current = current->next;
    }
}


// Méthode pour rechercher un élément dans la liste
ElementAction* ListeAction::rechercher(const Shape& shape) const {
    ElementAction* current = head;
    while (current != nullptr) {
        if (current->shape == shape) {
            return current;
        }
        current = current->next;
    }
    return nullptr; // Si l'élément n'est pas trouvé
}

// Méthode pour insérer un élément à un emplacement spécifique de la liste
void ListeAction::inserer(const Shape& shape, int index) {
    if (index < 0) {
        std::cerr << "Index invalide." << std::endl;
        return;
    }

    ElementAction* newElement = new ElementAction{shape, nullptr};
    if (index == 0) {
        newElement->next = head;
        head = newElement;
        return;
    }

    ElementAction* current = head;
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