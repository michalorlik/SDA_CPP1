#pragma once
#include "Employee.h"

#include <vector>

class IEmployeeFileWriter
{
public:
	virtual void writeEmployees(std::vector<Employee> employees, std::string filePath) = 0;
	virtual void writeLogin(std::vector<Employee> employees, std::string filePath) = 0;
};

