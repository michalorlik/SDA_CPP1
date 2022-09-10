#include <iostream>
#include "json/json.hpp"
#include <fstream>

using json = nlohmann::json;

int main()
{
    json j;

    j["praca"]["dodatkowa"] = "szklarz";
    j["imie"]["pierwsze"] = "Michal";
    j["nazwisko"] = "Orlikowski";
    j["lista"] = { 1, 0, 2 };
    j["praca"]["sda"] = "trener";
    j["praca"]["hexagon"] = "developer";
    j["imie"]["drugie"] = "Zbigniew";
    j["lista"].push_back(77);

    std::ofstream o("ja2.json");
    o << std::setw(4) << j << std::endl;

}
