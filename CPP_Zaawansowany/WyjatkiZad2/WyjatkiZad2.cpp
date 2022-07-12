#include <iostream>
#include "PositiveNumber.h"

int main()
{
    PositiveNumber num1(100);
    double num = 10;
    PositiveNumber num2 = num1 - num;

    PositiveNumber num2 = num - num1;

    std::cout << "Hello World!\n";
}
