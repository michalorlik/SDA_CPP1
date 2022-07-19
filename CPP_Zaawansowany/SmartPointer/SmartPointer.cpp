#include <iostream>
#include "SimpleSmartPointer.h"

struct Foo
{
    Foo(int in) : a(in) {}
    void print() const
    {
        std::cout << "a = " << a << '\n';
    }
    int a;
};

int main()
{
    SimpleSmartPointer<int> ptr(new int(7));

    std::cout << "Wartosc pod wskaznikiem: " << *ptr;

    SimpleSmartPointer<Foo> ptrFoo(new Foo(666));
    ptrFoo->print();
    (*ptrFoo).print();
}
