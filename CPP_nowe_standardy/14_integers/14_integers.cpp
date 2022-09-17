#include <iostream>

int main()
{
    int d = 42; //decimal
    int o = 052; // oct
    int x = 0x2a; //hex
    int X = 0X2A; //hex
    int b = 0b101010; //binary

    std::cout << d << std::endl;
    std::cout << o << std::endl;
    std::cout << x << std::endl;
    std::cout << X << std::endl;
    std::cout << b << std::endl;

    auto integer_literal = 1'000'000;
    auto floating_point_literal = 0.000'015'3;
    auto binary_literal = 0b0100'1100'0110;
    auto a_dozen_crores = 12'00'00'000;
    auto sda = 1'2'3'4'5'6'7'8'9'0;

    std::cout << integer_literal << std::endl;
    std::cout << floating_point_literal << std::endl;
    std::cout << binary_literal << std::endl;
    std::cout << a_dozen_crores << std::endl;
    std::cout << sda << std::endl;



    std::cout << "Hello World!\n";
}
