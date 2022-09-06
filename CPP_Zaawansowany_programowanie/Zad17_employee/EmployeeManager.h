#pragma once
#include "Employee.h"
#include "IEmployeeFileReader.h"
#include "IEmployeeFileWriter.h"

#include <vector>
#include <memory>


class EmployeeManager
{
public:
	EmployeeManager(std::shared_ptr<IEmployeeFileReader> fileReader, std::shared_ptr<IEmployeeFileWriter> fileWriter);

	//void readDataFromFile(std::string filePath);
	//a) generateLogins
	//b) generate passwords
	//b) storeLoginDataToFile
	//c) int calculateFirstNameStarting(char firstLetter)
	//c) std::map calculateUniqueNames()
	//c) calculateAvarageSalary()
	//c) calculateAvarageSalaryMen()
	//c) calculateAvarageSalaryWomen()
	//d) std::vector<E> calculateTop10Salary()
	//d) std::vector<E> calculateTop10Salary()
	//d) storeEmployeeSalary(std::vector<E>)

private:
	std::vector<Employee> employees;
	std::shared_ptr<IEmployeeFileReader> _fileReader;
	std::shared_ptr<IEmployeeFileWriter> _fileWriter;
};

