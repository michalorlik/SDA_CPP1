#include <iostream>

template<typename T>
void printMe(T value) // ten szablon s³u¿y zatrzymaniu rozwijania parameter pack
{
    std::cout << value <<std::endl;
}

template<typename T, typename ... Args> //deklaracja szablonu ktory moze przyjac 1 + 0+ argumentów
void printMe(T first, Args ... args)  //deklaracja funkcji 
{
   std::cout << first << " , "; //wypisujemy zmienna first, która jest znanego typu T

   printMe(args ...); //nastepnie rozwijamy ten pack poprzez rekurencyjne wywolanie tego szablonu
}

int main()
{
    int x =10;
    bool logic = true;
    float f = 3.14;
    std::string sda = "SDA";
    printMe(x, logic, f, sda, "jeszcze jeden string", 13);
    std::cout << std::endl;
    printMe(logic, f, sda, "jeszcze jeden string", 13, x);
}

