#pragma once
#include <string>

class Employee
{
public:
	enum class Gender
	{
		MALE,
		FEMALE,
		UNKNOWN
	};

	//Dodac gettery/settery/c-tor

private:

	std::string firstName;
	std::string lastName;
	std::string email;
	Gender gender;
	double salary;
	//......
};

