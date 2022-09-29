#include <iostream>
#include <cassert>

#define MACRO(X,Y) \
( \
( std::cout<< X <<std::endl), \
( std::cout<< Y <<std::endl), \
( std::cout<< ((X) + (Y)) <<std::endl) \
)

void fun(int x)
{
    assert(x > 0);

    std::cout << "x=" << x<<std::endl;
}

template <class T, int Size>
struct Kontener {
    static_assert(Size > 0, "Size musi byc liczba wieksze od 0");
    static_assert(std::is_integral_v<T>, "Musi byc to typ calkowity");
    T value[Size];
};

int main()
{
    //int x = 1;
    //int y = 2;
    //MACRO(x++, y++);

    //std::cout<< "x=" << x << std::endl;
    //std::cout << "y=" << y << std::endl;
    //fun(0);
    //fun(1);
    //fun(2);

    Kontener<int, 10> tenInts;
    Kontener<float, 10> tenFloats;
    //Kontener<float, 0> zeros;
}
