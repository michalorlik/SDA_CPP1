#include <iostream>
#include "EmployeeManager.h"
#include "EmployeeCSVReader.h"
#include "EmployeeCSVWriter.h"

int main()
{
    EmployeeManager empManager(std::make_shared<EmployeeCSVReader>(), std::make_shared<EmployeeCSVWriter>());
    //EmployeeManager empManager2(std::make_shared<EmployeeJSONReader>(), std::make_shared<EmployeeJSONWriter>());
    empManager.readDataFromFile("employee_input.csv");
    //empManager.generateLogins();
}
