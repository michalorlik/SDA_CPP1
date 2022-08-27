#pragma once

#include <cmath>

//Napisz i przetestuje klasê Triangle, która w c - torze przyjmuje 3 boki
//- dodaj metode getArea, która wyliczy pole
//pole wylicz za pomoc¹ wzoru Herona : https://www.mathopenref.com/heronsformula.html
//-dodaj metodê getPerimeter, która wyliczy obwód
//- dodaj metodê isValid, która zwróci prawdê je¿eli trój¹kt jest poprwany
//Trójk¹t jest porpwany, gdy suma d³ugoœci dwóch boków trójk¹ta jest zawsze wiêksza od d³ugoœci trzeciego boku
//- je¿eli trójk¹t nie moze istnieæ to niech wszystkie funkcje coœ wyliczaj¹ce zwracaj¹ 0

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

