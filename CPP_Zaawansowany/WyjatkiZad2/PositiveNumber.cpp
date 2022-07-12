#include "PositiveNumber.h"

#include <string>

PositiveNumber::PositiveNumber(double value)
{
	setValue(value);
}

PositiveNumber::PositiveNumber()
	: PositiveNumber(0.0)
{
}

PositiveNumber::PositiveNumber(float value)
	: PositiveNumber(static_cast<double>(value))
{
}

PositiveNumber::PositiveNumber(int value)
	: PositiveNumber(static_cast<double>(value))
{
}

double PositiveNumber::getValue() const
{
	return _value;
}

void PositiveNumber::setValue(double value)
{
	if (value < 0)
	{
		throw std::string("NIE MOZE BYC LICZBA UJEMNA");
	}
	else
	{
		_value = value;
	}
}

void PositiveNumber::setValue(float value)
{
	setValue(static_cast<double>(value));
}

void PositiveNumber::setValue(int value)
{
	setValue(static_cast<double>(value));
}

void PositiveNumber::add(double value)
{
	if (value < 0 && abs(value) > getValue())
	{
		throw std::string("PROBUJESZ DODAC ZA DUZA LICZBE WYNIK BY£BY LICZBA UJEMNA");
	}
	else
	{
		setValue(getValue() + value);
	}
	
}

void PositiveNumber::add(float value)
{
	add(static_cast<double>(value));
}

void PositiveNumber::add(int value)
{
	add(static_cast<double>(value));
}

PositiveNumber& PositiveNumber::operator+(const PositiveNumber& second)
{
	add(second.getValue());
}

void PositiveNumber::substract(double value)
{
	if (abs(value) > getValue())
	{
		throw std::string("PROBUJESZ ODJAC ZA DUZA LICZBE WYNIK BY£BY LICZBA UJEMNA");
	}
	else
	{
		setValue(getValue() - value);
	}
}

void PositiveNumber::substract(float value)
{
	substract(static_cast<double>(value));
}

void PositiveNumber::substract(int value)
{
	substract(static_cast<double>(value));
}

PositiveNumber& PositiveNumber::operator-(const PositiveNumber& second)
{
	this->substract(second.getValue());
}

PositiveNumber& PositiveNumber::operator+(double number)
{
	add(number);
}

PositiveNumber& PositiveNumber::operator-(double number)
{
	substract(number);
}

PositiveNumber& PositiveNumber::operator=(const PositiveNumber& second)
{
	this->setValue(second.getValue());
}