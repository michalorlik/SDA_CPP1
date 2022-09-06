#pragma once
#include "IEmployeeFileWriter.h"

#include <vector>

class EmployeeCSVWriter : public IEmployeeFileWriter
{
public:
	void writeEmployees(std::vector<Employee> employees, std::string filePath) override;


private:
};
