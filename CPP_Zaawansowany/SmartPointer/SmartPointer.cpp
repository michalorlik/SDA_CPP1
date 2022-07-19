#include <iostream>
#include "SimpleSmartPointer.h"

int main()
{
    SimpleSmartPointer<int> ptr(new int(7));

    std::cout << "Wartosc pod wskaznikiem: " << *ptr;
}
