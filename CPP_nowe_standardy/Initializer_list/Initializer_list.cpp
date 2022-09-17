#include <iostream>
#include <vector>

class Klasa
{
public:
    Klasa(std::initializer_list<char> il)
    {
        for (auto& c : il)
        {
            value+=c;
        }
    }

    std::string getValue() const
    {
        return value;
    }

private:
    std::string value;
};

int main()
{

    Klasa obj{'S','D','A','1','2','3'};

    auto initList = { 'H','E','L','l','o' }; // auto oznacza std::initializer_list<char>
    std::vector<char>(initList);
    Klasa obj2(initList);

    std::cout << obj.getValue() <<std::endl;
    std::cout << obj2.getValue();
}
