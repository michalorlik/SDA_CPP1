#include <iostream>
#include "PositiveNumber.h"

int main()
{
    PositiveNumber num1(100);
    double num = 10;
    PositiveNumber num2 = num1 - num;

    PositiveNumber num3 = (num2 + (num1 + (num1 + num1)));


    PositiveNumber num4 = num1.operator+(10); //taka funkcje mamy to jest to samo co (num1 + 10)

    PositiveNumber num5 = 5;
    PositiveNumber num6 = 10 - num5; // nie dzia³a bo: ten zapis oznacza 10.operator+(num5)

    std::cout << "Wartosc po odjeciu " << num6.getValue();
}
