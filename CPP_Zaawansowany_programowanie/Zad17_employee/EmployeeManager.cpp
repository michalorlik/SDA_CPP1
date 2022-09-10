#include "EmployeeManager.h"
#include <memory>

EmployeeManager::EmployeeManager(std::shared_ptr<IEmployeeFileReader> fileReader, std::shared_ptr<IEmployeeFileWriter> fileWriter)
	: _fileReader(fileReader)
	, _fileWriter(fileWriter)
{
};

void EmployeeManager::readDataFromFile(std::string filePath)
{
	employees = _fileReader->readEmployees(filePath);
}

void EmployeeManager::saveToFile(std::string filePath)
{
	_fileWriter->writeEmployees(employees, filePath);
}

void EmployeeManager::saveLogins(std::string filePath)
{
	_fileWriter->writeLogin(employees, filePath);
}