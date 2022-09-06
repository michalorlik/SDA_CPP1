#pragma once
#include "Employee.h"

#include <vector>

class IEmployeeFileReader
{
public:
	virtual std::vector<Employee> readEmployees(std::string filePath)=0;
	//virtual Employee readEmployee()=0; //opcjonalnie mozna tez wczytywac pojedynczych pracowników
}; 

