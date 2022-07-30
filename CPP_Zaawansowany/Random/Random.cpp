#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>

int main() 
{
    std::vector<int> numbers;
    std::random_device r; //urz¹dzenie do generowania entropii (zalezne od systemu operacyjnego)
    std::default_random_engine defEngine(r()); //tworzymy sobie silnik losowosci, ktory bedzie zwraca³ nam losowe liczby
    std::uniform_int_distribution<int> intDistro(-10, 10); // ubiermy ten nasz silnik w klase zapewniaj¹c¹ nam odpowiedni rozk³ad liczb
    for (int i = 1; i <= 10; i++) 
    {
        numbers.push_back(intDistro(defEngine)); //pobiernie kolejnych liczb losowych
    }
    for (const int n : numbers) 
    {
        std::cout << n << " ";
    }

    std::cout << std::endl << std::endl;

    std::vector<double> doubles;
    std::mt19937_64 mt_engine(r());
    std::uniform_real_distribution<double> realDistrbituion(-1, 1);

    for (int i = 1; i <= 10; i++)
    {
        doubles.push_back(realDistrbituion(mt_engine));
    }

    for (auto d : doubles)
    {
        std::cout << d << " ";
    }


    //Utwórz wektor 100 losowych liczb z przedzia³u 0 10, nastêpnie:
    //a) wypisz ten wektor
    //b) zlicz iloœæ wyst¹pieñ liczby 5
    //c) Wylicz œrednia wartoœæ
    //d) Zrób to samo dla innego rozk³adu wartoœci
    std::cout << std::endl << std::endl << std::endl;

    std::vector<int> uniformNumbers(100);
    std::random_device randomDevice;
    std::default_random_engine randomEngine(randomDevice());
    std::uniform_int_distribution<int> dist(0, 10);

    //std::normal_distribution<> dist(5,1.75);

    for (auto it = uniformNumbers.begin(); it != uniformNumbers.end(); it++)
    {
        *it = dist(randomEngine);
    }

    std::for_each(uniformNumbers.begin(), uniformNumbers.end(), [](const int i) { std::cout << i << "; "; });

    auto count5 = std::count(uniformNumbers.cbegin(), uniformNumbers.cend(), 5);

    std::cout << std::endl << "Liczba 5 wystepuje " << count5 << " razy" << std::endl;

    int sum = std::accumulate(uniformNumbers.begin(), uniformNumbers.end(), 0);

    double mean = sum / static_cast<double>(uniformNumbers.size());

    std::cout << std::endl << "Srednia wynosi " << mean << std::endl;

    return 0;
}
