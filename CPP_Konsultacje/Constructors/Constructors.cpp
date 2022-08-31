#include <iostream>
#include <vector>
#include <algorithm>

class Cow
{
};

struct Point
{
    /*    Point(int x1, int y1)
        {
            std::cout<<"Point"<<std::endl;
            x = x1;
            y= y1;
        };*/

    int x;
    int y;
};

//https://en.cppreference.com/w/cpp/language/copy_assignment
class CopiableClass
{
public:
    CopiableClass(size_t howMany)
        : size(howMany)
    {
        tab = new int[size];

        for (int i = 0; i < size; ++i)
        {
            tab[i] = i;
        }
    };

    ~CopiableClass()
    {
        delete[] tab;
    }

    CopiableClass(const CopiableClass& other)
    {
        this->size = other.size;
        //this->tab = other.tab; //to jest plytka kopia (shallow copy) tutaj niebezpieczna
        
        //G³êboka kopia (deep copy)
        this->tab = new int[this->size];
        for (int i = 0; i < size; ++i)
        {
            this->tab[i] = other.tab[i];
        }
    }

    CopiableClass& operator=(const CopiableClass& other)
    {
        
        if (this != &other) // not a self-assignment
        {
            if (this->size > 0) //je¿eli ju¿ mielismy jakies dane to trzeba je usunac,dlatego najpierw trzeba sprawdziæ czy nie kopiujemy samego siebie
            {
                delete[] tab; //dziêki temu unikamy wycieków pamiêci
            }

            this->size = other.size;
            this->tab = new int[this->size];
            for (int i = 0; i < size; ++i)
            {
                this->tab[i] = other.tab[i];
            }

        }
        

        return *this; //dodatkowy element przy robieniu operatora=
    }

private:
    int * tab;
    size_t size;
};

//dziêki zwracaniu *this w operatorze= mo¿emy zrobiæ tak¹ konstrukcje
//CopiableClass a;
//CopiableClass b;
//CopiableClass c;
//
//a = b = c;

int main()
{
    //Wszystkie 3 wersje robi¹ dok³adnie to samo
    Cow cow1;
    Cow cow2{};
    Cow cow3();

    Point p1{ 1, 2 };
    //Point p2(1, 2); //to nie dzia³a bo nie mam c-tora ktory przyjmuje takei parametry

    std::vector<int> v1(10, 2);
    std::vector<int> v2{ 10, 2,11,12,13 };
    std::cout << "******" << std::endl;
    std::for_each(v1.begin(), v1.end(), [](int i) { std::cout << i << std::endl; });

    std::cout << "******" << std::endl;

    std::for_each(v2.begin(), v2.end(), [](int i) { std::cout << i << std::endl; });

    return 0;
}
