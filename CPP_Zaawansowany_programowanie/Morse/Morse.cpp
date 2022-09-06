#include <iostream>
#include <string>
#include <map>
#include <sstream>

std::string decypher(std::string morse)
{
    std::map<std::string, char> dictionary{ {".-", 'a'},{"-...", 'b'} ,{"-.-.", 'c'} ,{"-..", 'd'} ,{".", 'e'} };

    std::string result;
    std::string tmp;

    while (morse.find(' ') != std::string::npos) //szukamy spacji
    {
        tmp = morse.substr(0, morse.find(' ')); //wszystko do spacji kopiuje do osobnego stringa
        result += dictionary.at(tmp); //tutaj dokonuje tlumaczenia, i wrzucam przetlumaczony znak do wyjsciowego stringa
        morse.erase(0, morse.find(' ') + 1); //usuwam juz przetlumaczona czesc 
    }

    result += dictionary.at(morse);

    return result;
}

std::string decypher2(std::string morse)
{
    std::map<std::string, char> dictionary{ {".-", 'a'},{"-...", 'b'} ,{"-.-.", 'c'} ,{"-..", 'd'} ,{".", 'e'} };

    std::stringstream ss(morse);
    std::string result;
    std::string tmp;

    while (std::getline(ss, tmp , ' '))
    {
        result += dictionary.at(tmp);
    }

    return result;
}


int main()
{
    std::cout << decypher2(".- -... -.-. -.. .");
}

