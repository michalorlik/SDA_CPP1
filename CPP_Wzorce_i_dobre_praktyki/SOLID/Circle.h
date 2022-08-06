#pragma once
#include "Shape2D.h"

class Circle : public Shape2D
{
public:
	Circle(float radius)
		:_radius(radius)
	{
	}

	virtual ~Circle() = default;

	float area() const override //override dodaje slowo kluczowe virtual i dodatkowo sprawdza czy na pewno przys³aniamy metode z klasy bazowej
	{
		return 3.1415 * getRadius() * getRadius();
	}

	float getRadius() const
	{
		return _radius;
	}

	void setRadius(float radius)
	{
		_radius = radius;
	}

private:
	float _radius;
};

