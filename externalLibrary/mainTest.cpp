#include <iostream>
#include "liste_chainee.h"
#include "../include/Shape.h"

int main()
{
    Liste myList;
    Shape myShape;
    Shape myShape2(21);
    myList.append(myShape);
    myList.Display();
    myList.append(myShape2);
    myList.Display();
    return 0;
}