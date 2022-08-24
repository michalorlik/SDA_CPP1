#include <iostream>
#include <string>

class Cow
{
public:
    Cow(std::string name, int weight, int age)
        : _name(name)
        , _weight(weight)
        , _age(age)
    {
    };

    Cow(std::string name)
        : Cow(name, 0, 0) //delegacja do c-tora z 3 parametrami
    {
    }

    Cow() = delete;

    std::string getName() const
    {
        return _name;
    };

    int getAge() const
    {
        return _age;
    };

    void addAge(int years) //dzieki enkapsulacji mozemy miec pewnosc ze wiek bedzie tylko rós³
    {
        _age += years;
    }

    int getWeight() const
    {
        return _weight;
    }

    void setWeight(int weight) 
    {
        _weight= weight;
    }

    void print() // lepiej, ale nadal nie to (*S*OLID)
    {
        std::cout << "Name= " << getName()
            << ";age= " << getAge()
            << ";weight=" << getWeight() << "\n";
    }

    std::string toString() const //to jest w miare ok bo ta funkcja zwraca to co przechowuje klasa Cow
    {
        std::string output;
        output.append("Name= ");
        output.append(getName());
        output.append(";age= ");
        output.append(std::to_string(getAge())); 
        output.append(";weight= ");
        output.append(std::to_string(getWeight()));
        return output;
    }

    //this jest po lewej stronie a text w nawiasie
    void operator[](std::string text) //operator muczenia tekstu
    {
        std::cout << "Muuuu " << text << "muuuuuuuuuuuuu" << std::endl;
    }

    //this jest po lewej stornie a cow po prawej
    Cow operator+(const Cow& cow)
    {
        Cow newCow(cow.getName() + this->getName());
        return newCow;
    }

private:

    std::string _name; //imie moze byc przydzielone tylko raz
    int _weight; //wage mozemy ustawiac dowolnie (w domysle po kazdym wazeniu krowy)
    int _age; //wiek mozemy tylko przesuwac do przodu
};

//cow jest tym co bedzie po lewej stronie operatora, weight po prawej
void operator&(Cow& cow, int weight)
{
    cow.setWeight(weight);
};


//operator poza klasa
std::ostream& operator<<(std::ostream& s, const Cow& cow)//s jest po lewej stronie operatora, cow jest po prawej
{
    return s << cow.toString();

  /*  return s << "Name= " << cow.getName()
        << ";age= " << cow.getAge()
        << ";weight=" << cow.getWeight() << "\n";*/
}

void printCow(Cow cow)  //podejscie nie obiektowe :(
{
    std::cout << "Name= " << cow.getName()
        << ";age= " << cow.getAge()
        << ";weight=" << cow.getWeight()<<"\n";
}

int main()
{
    Cow cow1("Krasulka", 500, 3);
    Cow cow2("CorkaKrasulki");
    cow2.setWeight(30);

    std::cout << cow1.toString() << std::endl;
    std::cout << cow2 << std::endl;

    cow1["Glosuj na PSL"]; //cow1.operator[]("jakis teskt")

    Cow cow3 = cow1 + cow2;

    std::cout << cow3 << std::endl;

    cow3 & 100; //    to samo: operator&(cow3, 100);

    std::cout << cow3;
}
