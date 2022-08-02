//a) Wygeneruj 100000 losowych liczb z przdzia³u -100000 100000
//b) zapisz je do pliku
//c) nastepnie wczytaj je z tego pliku do vectora
//d) wypiszcie 100 pierwszych wczytanych liczb(uzycjie std::advance)
//e) Wypisz od 50-150 pozycji z tego wektora

#include <iostream>
#include <random>
#include <fstream>
#include <iostream>

void saveVectorToFile(const std::vector<int>& vec, const std::string& fileName)
{
    std::ofstream file(fileName); //otworzenie pliki, jesli nie istnieje to ostream nam ten plik utworzy

    if (file.is_open()) //sprawdzenie czy otworzy³em plik
    {
        std::cout << "Plik zostal otwarty: " << fileName << std::endl << std::endl;

        for (const auto& el : vec)
        {
            file << el << '\n';
        }

        file.close();
    }
}

void loadFromFile(const std::string& fileName)
{
    std::ifstream file(fileName);
    std::vector<int> nums;


    if (file.is_open())
    {
        std::cout << "Plik zostal otwarty: " << fileName << std::endl << std::endl;

        while (file.good() && !file.eof())
        {
            int val;
            file >> val;
            nums.push_back(val);
        }

        file.close();
    }

    auto it = nums.begin();
    std::advance(it, 100);

    std::for_each(nums.begin(), it, [](int i) { std::cout << i << '\n'; }); //od pocz¹tku do iteratora

    std::for_each(nums.begin()+50, nums.begin()+150, [](int i) { std::cout << i << '\n'; }); //wypisz od 50 do 150 elementy

    std::cout << std::endl << std::endl << std::endl;
    std::for_each(nums.end() - 100, nums.end(), [](int i) { std::cout << i << '\n'; }); // wypisze 100 ostatnie elementów

    auto it2 = std::find(nums.begin(), nums.end(), 1231);
    std::for_each(it2, nums.end(), [](int i) { std::cout << i << '\n'; });
    std::for_each(nums.begin(), it2, [](int i) { std::cout << i << '\n'; });


}

int main()
{
    std::random_device ranDev; //urzadzenie sluzace do generowania ziarna (seed)
    std::default_random_engine randomEngine(ranDev()); // silnik zwracajacy faktycznie losowe liczby, ziarno przekazane do c-tora daje nam to, ¿e przy ka¿dym uruchomieniu, otrzymamy inn¹ sekwencje liczb
    std::uniform_int_distribution<int> intDist(-100000, 100000); // rozklad, który generuje mi losowe liczby z podanego przedzia³u

    const size_t howManyNumbers = 100000;
    std::vector<int> nums;
    nums.reserve(howManyNumbers);

    for (int i = 0; i < howManyNumbers; ++i)
    {
        nums.push_back(intDist(randomEngine));
    }

    const std::string fileName = "wylosowaneLiczby.txt"; //nazwa pliku
    saveVectorToFile(nums, fileName);
    loadFromFile(fileName);
}


