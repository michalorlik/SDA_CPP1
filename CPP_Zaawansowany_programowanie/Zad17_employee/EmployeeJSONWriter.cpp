#include "EmployeeJSONWriter.h"
#include "Employee.h"

#include <fstream>
#include "json/json.hpp"

using json = nlohmann::json;

void to_json(json& j, const Employee& e)
{
	j = { {"firstName", e.getFirstName()} , {"lastName", e.getLastName()}, {"email" , e.getEmail()}, 
		{"gender", Employee::toString(e.getGender()) }, {"salary", e.getSalary()} };
}

void EmployeeJSONWriter::writeEmployees(std::vector<Employee> employees, std::string filePath)
{
	std::ofstream o(filePath);

	json j;
	j["Employees"] = employees;

	o << std::setw(4) << j << std::endl;
}

void EmployeeJSONWriter::writeLogin(std::vector<Employee> employees, std::string filePath)
{
	std::ofstream o(filePath);
	json employeeArray;

	for (const auto& empl : employees)
	{
		json employee{ {"email" , empl.getEmail()}, {"login" , empl.getLogin()} };
		employeeArray.push_back(employee);
	}

	json j;
	j["LoginData"] = employeeArray;

	o << std::setw(4) << j << std::endl;
}
