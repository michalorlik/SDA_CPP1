#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void zad1()
{
    std::cout << "Podaj nazwe produktu";
    std::string s;
    std::getline(std::cin, s); //wczytaj az do napotkania zaku nowej lini

    std::cout << "Wczytano: " << s;
}

void zad2()
{
    std::ifstream file("zdania.csv");

    if (!file.is_open())
    {
        std::cout << "nie udalo sie otworzyc pliku";
        return;
    }

    std::string str;
    std::vector<std::string> strings;

    while (std::getline(file, str))
    {
        strings.push_back(str);
    }

    file.close();

    std::cout << "Wczytano " << strings.size() << " lancuchow";


}

int main()
{
    //zad1();
    zad2();

    return 0;
}
