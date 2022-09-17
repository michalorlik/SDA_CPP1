#include <iostream>
#include <utility>

int postIncrement10(int& init)
{
    return std::exchange(init, init + 10);
}

int postIncrement10_old(int& init)
{
    int tmp = init;
    init += 10;

    return tmp;
}

int main()
{
    int x = 10;

    int z = std::exchange(x, 15);


    std::cout << "x= " << x << " ,z= " << z << std::endl;
    std::cout << fun(x)<<std::endl;
    std::cout << "x= " << x << " ,z= " << z << std::endl;
}
