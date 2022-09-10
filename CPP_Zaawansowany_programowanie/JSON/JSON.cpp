#include <iostream>
#include "json/json.hpp"
#include <fstream>

using json = nlohmann::json;

int main()
{
    json j;

    j["imie"] = "Michal";
    j["nazwisko"] = "Orlikowski";
    j["lista"] = { 1, 0, 2 };
    j["praca"]["sda"] = "trener";
    j["praca"]["hexagon"] = "developer";

    std::ofstream o("ja.json");
    o << std::setw(4) << j << std::endl;

}
