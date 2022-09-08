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

	static Gender toGender(std::string str)
	{
		if (str == "Female")
		{
			return Gender::FEMALE;
		}
		else if (str == "Male")
		{
			return Gender::MALE;
		}
		else
		{
			return Gender::UNKNOWN;
		}
	}

	void setFirstName(const std::string name)
	{
		firstName = name;
	}

	void setLastName(const std::string name)
	{
		lastName = name;
	}

	void setEmail(const std::string mail)
	{
		email = mail;
	}

	void setGender(const Gender gender)
	{
		this->gender = gender;
	}

	void setSalary(const double salary)
	{
		this->salary = salary;
	}

private:

	std::string firstName;
	std::string lastName;
	std::string email;
	Gender gender;
	double salary;
	//......
};

