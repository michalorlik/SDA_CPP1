#include <iostream>
#include <memory>

class Chicken
{
public:

    Chicken()
    {
        std::cout << "Chicken" << std::endl;
    }

    Chicken(const Chicken& second)
    {
        std::cout << "Chicken copy" << std::endl;
    }

    ~Chicken()
    {
        std::cout << "~Chicken" << std::endl;
    }
};

void fun()
{
    Chicken* rawPtr = new Chicken();

    std::unique_ptr<Chicken> smartPtr(new Chicken());

    delete rawPtr;
}

int main()
{
    fun();
    std::cout << "Hello World!\n";
}

