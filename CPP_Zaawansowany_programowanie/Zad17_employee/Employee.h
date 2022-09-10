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

	static std::string toString(Gender g)
	{
		switch (g)
		{
		case Gender::FEMALE:
			return "Female";
			break;
		case Gender::MALE:
			return "Male";
			break;
		case Gender::UNKNOWN:
		default:
			return "Unknown";
			break;
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

	std::string getFirstName() const
	{
		return firstName;
	}

	std::string getLastName() const
	{
		return lastName;
	}

	std::string getEmail() const
	{
		return email;
	}

	Gender getGender() const
	{
		return gender;
	}

	double getSalary() const
	{
		return salary;
	}

	std::string getLogin() const
	{
		//return login;
		return "abcd";
	}

private:

	std::string firstName;
	std::string lastName;
	std::string email;
	Gender gender;
	double salary;
	std::string login;
};

