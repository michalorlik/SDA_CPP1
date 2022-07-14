#include <iostream>

template<typename T>
T max(T a, T b)
{
    //if (a > b)
    //{
    //    return a;
    //}
    //else
    //{
    //    return b;
    //}

    return a > b ? a : b; //operator potrójny (ternary)
}

template<typename T>
T* max(T* a, T* b)
{
    return *a > *b ? a : b;
}

int main()
{
    int num1 = 100;
    int num2 = 10;
    std::cout << "Wieksza int: " << max(num1, num2) << std::endl;
    std::cout << "Wieksza double: " << max(1.23, 21.55) << std::endl;

    int* ptr1 = &num1;
    int* ptr2 = &num2;
    std::cout << "Wiekszy ptr: " << *max(ptr1, ptr2) << std::endl;
}
