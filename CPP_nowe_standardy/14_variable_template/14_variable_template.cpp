#include <iostream>

template<typename T>
constexpr T pi = T(3.141592653589793238462643383);

template<>
constexpr char pi<char> = 'p';

template<>
constexpr const char* pi<const char*> = "pi";

int main()
{
    int i = pi<int>;
    float f = pi<float>;

    std::cout << "int = " << i << std::endl;
    std::cout << "float = " << f << std::endl;
    std::cout << "double = " << pi<double> << std::endl;
    std::cout << "char = " << pi<char> << std::endl;
    std::cout << "char = " << pi<const char*> << std::endl;
}

