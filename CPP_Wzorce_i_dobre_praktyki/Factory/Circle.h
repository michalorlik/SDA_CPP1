#pragma once
#include <iostream>
#include "Shape.h"

class Circle : public Shape
{
public:

	Circle(float radius)
		: _radius(radius)
	{
	}

	void draw() override
	{
		std::cout << "Draw()::Circle\n";
	}

private:
	float _radius;
};

