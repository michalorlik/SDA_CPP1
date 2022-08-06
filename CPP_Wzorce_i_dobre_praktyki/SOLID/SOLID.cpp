#include <iostream>
#include "AreaCalculator.h"
#include "SumAreaCalulatorOutputter.h"

#include "Square.h"
#include "Circle.h"

int main()
{
	std::vector<Shape2D*> shapes;
	
	shapes.push_back(new Square(3.4));
	shapes.push_back(new Square(7.0));
	shapes.push_back(new Square(1.0));
	shapes.push_back(new Square(2.5));
	shapes.push_back(new Square(3.9));
	shapes.push_back(new Circle(5.0));
	shapes.push_back(new Circle(1.3));

	AreaCalculator areaCalc(shapes);
	SumAreaCalulatorOutputter areaOutputter(areaCalc);

	areaOutputter.outputCout();

	for (auto it = shapes.begin(); it != shapes.end(); it++)
	{
		delete *it;
	}
}
