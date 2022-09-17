// Constexpr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define POW3 2*2*2

constexpr int factorialCPP11(int n) 
{
    return n > 0 ? n * factorialCPP11(n - 1) : 1;
}

constexpr int factorialCPP14(int n)
{
    int result = 1;

    for (int i = 1; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}

int main()
{
    const int z = POW3; //kiedys sie tak robilo


    constexpr int pow1 = 2;
    constexpr int pow2 = 2 * 2;
    constexpr int pow3 = 2 * 2 * 2;
    constexpr int pow4 = 2 * 2 * 2 * 2;
    int x = pow3;

    auto lambada = [&]() {};

    //constexpr int aaa = pow4 * factorialCPP11(3) + x;

    int tab[pow4];
    int a[factorialCPP11(2)];
    int b[factorialCPP14(3)];

    int nonConstexpr = factorialCPP11(5);

    std::cout << factorialCPP11(2) << " " << factorialCPP11(3) << " " << factorialCPP11(4) << std::endl;
}