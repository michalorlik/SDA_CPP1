#include "EmployeeManager.h"

void EmployeeManager::readDataFromFile(std::string filePath)
{
	employees = _fileReader->readEmployees(filePath);
}