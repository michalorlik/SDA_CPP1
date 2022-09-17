#include <iostream>

auto Correct(int i)
{
    if (i == 1)
        return i;             // return type deduced as int

    return Correct(i - 1) + i;  // ok to call it now
}

auto Wrong(int i)
{
    if (i != 1)
        return Wrong(i - 1) + i;  // Too soon to call this. No prior return statement.

    return i;               // return type deduced as int
}


int main()
{
    auto lambda = [](int a) -> int {return a - 1; }; //C++11
    auto lambda = [](int a){return a - 1; }; //C++14

    std::cout << "Hello World!\n";
}