#include <fstream>

#include "EmployeeCSVWriter.h"

void EmployeeCSVWriter::writeEmployees(std::vector<Employee> employees, std::string filePath)
{

}

void EmployeeCSVWriter::writeLogin(std::vector<Employee> employees, std::string filePath)
{
	std::ofstream o(filePath);

	o << "email,login\n";

	for (const auto& empl : employees)
	{
		o << empl.getEmail();
		o << ",";
		o << empl.getLogin();
		o << "\n";
	}

	o.close();  //nie jest niezbêdne bo RAII
}