#pragma once
#include "IEmployeeFileWriter.h"

#include <vector>

class EmployeeJSONWriter : public IEmployeeFileWriter
{
public:
	void writeEmployees(std::vector<Employee> employees, std::string filePath) override;
	void writeLogin(std::vector<Employee> employees, std::string filePath) override;
private:

};

