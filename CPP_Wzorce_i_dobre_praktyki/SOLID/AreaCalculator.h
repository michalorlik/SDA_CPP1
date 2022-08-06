#pragma once

#include <vector>

#include "Shape2D.h"

class AreaCalculator
{
public:
	AreaCalculator(std::vector<Shape2D*> shapes)
		: _shapes(shapes)
	{
	}

	float sum()
	{
		float result = 0.0;
		for (const auto& shape : _shapes)
		{
			result += shape->area(); //RTTI Real Time Type Information przy u¿yciu v-table
		}

		return result;
	}

	////Ta metoda ³amie S
	//void output(float value)
	//{
	//	std::cout << "Summed aread is equal to: " << value << std::endl;
	//}

private:
	std::vector<Shape2D*> _shapes;
};

//class PerimeterCalculator : AreaCalculator
//{
//	std::vector<float> sum(); // £amanie literki L z SOLID
//
//};