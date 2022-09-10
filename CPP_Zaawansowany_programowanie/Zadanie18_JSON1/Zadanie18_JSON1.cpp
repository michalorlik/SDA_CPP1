#include <iostream>
#include <string>
#include "json.hpp"

int main()
{
    using json = nlohmann::json;

    std::string jsonStefana(R"({ 
   "company":{ 
      "employee":{ 
         "name":"Stefan",
         "payroll":{ 
            "salary":1500,
            "bonus":800
         }
      }
   }
})");

    json j = json::parse(jsonStefana);

    json employee = j["company"]["employee"];

    std::string employeeName = employee["name"];
    int salary = employee["payroll"]["salary"];
    int bonus = employee["payroll"]["bonus"];
    int sum = salary + bonus;
    //int sum = employee["payroll"]["salary"].get<int>() + employee["payroll"]["bonus"].get<int>(); //mozmey wymusic konwersje na konkretny typ

    std::cout << "Zarobki pracownika " << employeeName << " to: " << sum << std::endl;
}
