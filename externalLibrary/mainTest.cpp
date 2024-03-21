#include <iostream>
#include "liste_chainee.h"
#include "../include/Shape.h"

int main()
{
    ListeShape myList;
    Shape myShape;
    Shape myShape2(21);
    std::cout<<"length : " << myList.GetLength() <<std::endl;
    myList.AppendFirst(myShape);
    myList.Display();
    myList.AppendFirst(myShape2);
    myList.Display();
    std::cout<<"length : " << myList.GetLength() <<std::endl;
    myList.Delete(0);
    myList.Display();
    std::cout<<"length : " << myList.GetLength() <<std::endl;
    myList.AppendFirst(myShape2);
    myList.Display();
    return 0;
}