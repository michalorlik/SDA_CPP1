#pragma once
#include "Employee.h"

#include <vector>

class IEmployeeFileWriter
{
public:
	virtual void writeEmployees(std::vector<Employee> employees, std::string filePath) = 0;
	//virtual void readEmployee(Employee employee)=0; //opcjonalnie mozna tez wczytywac pojedynczych pracowników
};

