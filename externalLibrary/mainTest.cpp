#include <iostream>
#include "liste_chainee.h"
#include "../include/Shape.h"

int main()
{
    ListeShape myList;
    Shape myShape;
    Shape myShape2({10,45});
    std::cout<<"length : " << myList.GetLength() <<std::endl;
    myList.AppendFirst(myShape);
    myList.Display();
    myList.Delete(10);
    myList.Display();
    myList.AppendFirst(myShape2);
    myList.Display();
    std::cout<<"length : " << myList.GetLength() <<std::endl;
    myList.Delete(10);
    myList.Display();
    std::cout<<"length : " << myList.GetLength() <<std::endl;
    myList.AppendFirst(myShape2);
    myList.Display();
    return 0;
}