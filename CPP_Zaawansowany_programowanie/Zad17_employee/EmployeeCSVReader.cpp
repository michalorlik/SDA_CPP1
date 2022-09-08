#include "EmployeeCSVReader.h"

#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>>

std::vector<Employee> EmployeeCSVReader::readEmployees(std::string filePath)
{
	std::vector<Employee> employees;
	std::ifstream file(filePath);
	const char delimiter = ',';

	if (!file.is_open())
	{
		std::cout << "Nie udalo sie otworzyc pliku: " << filePath << std::endl;
		return employees;
	}

	std::string line;

	if (std::getline(file, line))
	{
		std::cout << "Otworzylem plik i wczytalem naglowek" << std::endl;
	}

	//first_name,last_name,email,gender,salary
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string data;
		Employee tmpEmployee;

		if (std::getline(ss, data, delimiter))
		{
			tmpEmployee.setFirstName(data);
		}
		else
		{
			continue;
		}

		if (std::getline(ss, data, delimiter))
		{
			tmpEmployee.setLastName(data);
		}
		else
		{
			continue;
		}

		if (std::getline(ss, data, delimiter))
		{
			tmpEmployee.setEmail(data);
		}
		else
		{
			continue;
		}

		if (std::getline(ss, data, delimiter))
		{
			tmpEmployee.setGender(Employee::toGender(data));
		}
		else
		{
			continue;
		}

		if (std::getline(ss, data))
		{
			try
			{
				tmpEmployee.setSalary(std::stod(data)); 
			}
			catch (std::exception& e) //std::invalid_argument i std::out_of_range
			{
				continue;
			}
		}

		employees.push_back(tmpEmployee);
	}

	return employees;
}