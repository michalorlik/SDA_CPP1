#pragma once
#include "IEmployeeFileReader.h"

#include <vector>

class EmployeeCSVReader : public IEmployeeFileReader
{
public:
	std::vector<Employee> readEmployees(std::string filePath) override; //wewnatrz tej funkcji mozemy sobie tez od razu tymczasowo utworzyc wszystkie zmienne do oblsugi plikow


private:
	//pola potrzbene do obslugi plików
};

