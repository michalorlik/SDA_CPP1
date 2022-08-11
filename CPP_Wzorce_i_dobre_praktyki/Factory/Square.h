#pragma once
#include <iostream>
#include "Shape.h"

class Square : public Shape
{
public:

	Square(float sideLength)
		: _sideLength(sideLength)
	{
	}

	void draw() override
	{
		std::cout << "Draw()::Square\n";
	}

private:
	float _sideLength;
	//wiecej mozliwych pol np kolor, obrot idt
};

