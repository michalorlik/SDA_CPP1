#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main()
{
    std::map<std::string, int> products;
    std::string input;
    int howMuch = 0 ;
    bool end = false;
    std::string produkt;

    while (!end)
    {
        std::cout << "Podaj produkt do zapisania na liste [napisz end zeby zakonczyc]: ";
        std::getline(std::cin, input); //tutaj wczytuje od uzytkownika

        if (input == "end") //sprawdzam czy uzytkownik poda³ komende koñca wczytywania
        {
            end = true; // zmieniam wartoœæ flagi
            break;
        }

        produkt = input; //wiem ze mam produkt w zmiennej input, wiec sobie ja teraz moge skopiowac

        std::cout << "Podaj ile kupic: ";
        //std::cin >> howMuch; //UWAGA! cin nie usuwa znaku /n
        //std::cin.ignore(1);  //usuwa ten pozostawiony znak nowej lini - usuwam 1 znak
        
        std::getline(std::cin, input);
        howMuch = std::stoi(input); //zamieniam string na inta //UWAGA: TRZEBA DODAC try-catch

//todo:: zamien na male litery

        auto it = products.find(produkt); //sprawdzam czy juz mam taki element w mapie

        if (it == products.end()) //oznacza to ze nie ma takiego elementu w mapie
        {
            products.emplace(produkt, howMuch); //wstawiam do mapy
        }
        else // juz jest taki element w mapie
        {
            std::cout << "Juz masz taki element na liscie, co mam z nim zrobic??\n";
            std::cout << "Podaj + jesli chcesz zsumowac\n";
            std::cout << "Podaj * jesli chcesz zachowac stara wartosc\n";
            std::cout << "Podaj = jesli chcesz zachowac nowa wartosc\n";
            std::cout << "Podaj opcje: ";

            std::getline(std::cin, input);

            if (input == "+")
            {
                it->second += howMuch;
            }
            else if (input == "*")
            {
                //nic nie trzeba robiæ
            }
            else if (input == "=")
            {
                it->second = howMuch;
                //products[produkt] = howMuch; //nieoptymalne, bo wszykuje po raz kolejny
            }
            else
            {
                std::cout << "Nieprawidlowa opcja\n";
            }
        }
    }

    std::cout << "\n\nTwoja lista zakupow\n";

    std::for_each(products.begin(), products.end(), [](std::pair<const std::string, int>& listItem) {
        std::cout << "- " << listItem.first << " : " << listItem.second << std::endl;
        });

}

