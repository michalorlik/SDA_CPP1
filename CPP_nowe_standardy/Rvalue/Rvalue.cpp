#include <iostream>

class A
{
public :
    A(std::string str)
        :value(str)
    {
    }

    A(A&& other) noexcept //move c-tor
    {
        std::cout << "A(A&& other)" << std::endl;
        value = std::move(other.value);
    }

    A(const A& other) //copy c-tor
        : A(other.value)
    {
        std::cout << "A(const A& other)" << std::endl;
    }

    A& operator=(const A& other) //copy assignment, kopiujacy operator przypisania
    {
        std::cout << "operator=(const A& other)" << std::endl;
        return *this = A(other.value);
    }

    A& operator=(A&& other) noexcept //move assignment, przenoszacym operatorem przypisania
    {
        std::cout << "operator=(A&& other)" << std::endl;
        this->value = std::move(other.value);
        return *this;
    }

    virtual ~A() = default;

    A& getMe()
    {
        return *this;
    }

    std::string getValue() const
    {
        return value;
    }

private:
    std::string value;
};

A getA1()
{
    return A("Created A1"); //zwracana wartosc tymczasowa
}

A getA2()
{
    A a("Created A2");

    return a;
}

void swapOld(int& a, int& b) 
{
    //kazde wywolanie = to wywo³anie copy assignment operatora
    int tmp(a); //od teraz mamy 2 kopie a bo wo³amy c-tor kopiujacy 
    a = b; //kopiowanko, mamy 2 kopie b 
    b = tmp; // kopiowanko mamy 2 kopie tmp;  
}

void swapMove(int& a, int& b)
{
    int tmp(std::move(a)); //jawnie rzadamy zamiany obiektu a na rvalue ref, nie robi sie kopia, 
    //nie wolno teraz odwolywac sie do zawartosci a
    a = std::move(b); //jawnie rzadymy zamiany b na rvalue i przeniesie jego pamieci do a
    //od teraz a jest OK, natomiast b nie wolno dotykac 
    b = std::move(tmp); //jawnie rzadamy przeniesienia pamieci tmp do b
    //a,b jest ok natomiast tmp nie wolno odczytywac/pisac
}

void swap(A& a, A& b) //funkcja swap dla klasy A
{
    A tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

template<typename T>
void swapMoveT(T& a, T& b)
{
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

template<typename T>
void swapCopyT(T& a, T& b)
{
    T tmp(a);
    a = b;
    b = tmp;
}

int main()
{
    A a("Variable");
    A a1 = getA1(); //tutaj jest tworzona kopia

    A& a_ref1 = a;
    //A& a_ref3 = A(); //zwykla refrerencja (lvalue) nie moze wskazywac na obiekt tymczasowy
    //A& a_ref5 = getA1();
    //A& a_ref7 = getA2();
    A& a_ref9 = a.getMe();

    //A&& a_ref2 = a; // rvalue ref nie moze wskazywac na zmienne
    A&& a_ref4 = A("Temporary");
    A&& a_ref6 = getA1();
    A&& a_ref8 = getA2();
    //A&& a_ref10 = a.getMe();

    int var1 = 17;
    int var2 = 23;

    std::cout << "var1=" <<var1<<" var2="<<var2<<std::endl;

    swapMove(var1, var2);

    std::cout << "var1=" << var1 << " var2=" << var2 << std::endl;

    std::string someString("Some string");
    std::string other(someString);
    std::cout << "C(" << someString << ", " << other << ")" << std::endl;
    std::string moved(std::move(someString));
    std::cout << "C(" << someString << ", " << other << ")" << std::endl;
    std::cout << "M(" << someString << ", " << moved << ")" << std::endl;

    A a11("A11");
    A a12("A12");
    std::cout << std::endl << std::endl;
    std::cout << "a11=" << a11.getValue() << " a12=" << a12.getValue() << std::endl;
    swap(a11, a12);
    std::cout << "a11=" << a11.getValue() << " a12=" << a12.getValue() << std::endl;

    std::cout << std::endl << std::endl;

    A pierwszy("Pierwszy");
    A drugi("Drugi");
    std::cout << "pierwszy=" << pierwszy.getValue() << " drugi=" << drugi.getValue() << std::endl << std::endl;
    swapCopyT(pierwszy, drugi);
    std::cout << "pierwszy=" << pierwszy.getValue() << " drugi=" << drugi.getValue() << std::endl << std::endl;
    swapMoveT(pierwszy, drugi);
    std::cout << "pierwszy=" << pierwszy.getValue() << " drugi=" << drugi.getValue() << std::endl << std::endl;
}


