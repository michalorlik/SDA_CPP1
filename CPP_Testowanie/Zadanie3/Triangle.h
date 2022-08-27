#pragma once

#include <cmath>

//Napisz i przetestuje klas� Triangle, kt�ra w c - torze przyjmuje 3 boki
//- dodaj metode getArea, kt�ra wyliczy pole
//pole wylicz za pomoc� wzoru Herona : https://www.mathopenref.com/heronsformula.html
//-dodaj metod� getPerimeter, kt�ra wyliczy obw�d
//- dodaj metod� isValid, kt�ra zwr�ci prawd� je�eli tr�j�kt jest poprwany
//Tr�jk�t jest porpwany, gdy suma d�ugo�ci dw�ch bok�w tr�jk�ta jest zawsze wi�ksza od d�ugo�ci trzeciego boku
//- je�eli tr�jk�t nie moze istnie� to niech wszystkie funkcje co� wyliczaj�ce zwracaj� 0

class Triangle
{
public:
	Triangle(double side1, double side2, double side3)
		: a(side1), b(side2), c(side3)
	{
	}

	double getPerimeter() const
	{
		double perimeter = 0;

		if (isValid())
		{
			perimeter = a + b + c;
		}

		return perimeter;
	}

	double getArea() const
	{
		double area = 0;

		if (isValid())
		{
			double p = getPerimeter() / 2;
			area = sqrt(p * (p - a) * (p - b) * (p - c));
		}

		return area;
	}

	bool isValid() const
	{
		return (((a + b) > c) && ((b + c) > a) && ((a + c) > b));
	}

private:
	double a, b, c;
};

