#include <iostream>
#include <string>

void fun(std::string twoNumbers)
{
    size_t pos = 0;

    int i1 = std::stoi(twoNumbers, &pos); //zamienia na int pierwsz¹ liczbê w ³añcuchu, ale nie modyfikuje stringa
    int i2 = std::stoi(twoNumbers.substr(pos)); //substr zwróci nam pod³añcuch(czeœæ oryginalnego stringa), zaczynaj¹cego siê od pos.
                                                //Zmienna pos przechowuje ile znaków zosta³o przeczytanych ¿eby zaminieæ string na inta za pierwszym razem
    std::cout << "i1=" << i1 << std::endl;
    std::cout << "i2=" << i2 << std::endl;
}

int main()
{

    //fun("13214 -123");

    while (true)
    {
        std::string number;
        std::cout << "Podaj wartosc do wczytania ";
        std::getline(std::cin, number);
        //std::cin >> number;

        int i = 0;

        try
        {
            i = std::stoi(number);
        }
        catch (const std::out_of_range& ex)
        {
            std::cout << ex.what() << std::endl;
            std::cout << " Wartosc " << number << " jest za duza zeby zmiescic do int" << std::endl;
        }
        catch (const std::invalid_argument& ex)
        {
            std::cout << ex.what() << std::endl;
            std::cout << " Wartosc " << number << " nie moze byc przekonwertowana na liczbe calkowita" << std::endl;
        }

        std::cout << "wartosc pobrana od uzytkownika: " << number <<std::endl;
        std::cout << "i=" << i << std::endl;
    }
}
