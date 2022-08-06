#pragma once
#include "Shape2D.h"

class Square : public Shape2D
{
public:
	Square(float sideLength)
		: _sideLength(sideLength)
	{
	}

	virtual ~Square() = default;

	float area() const override //override dodaje slowo kluczowe virtual i dodatkowo sprawdza czy na pewno przys³aniamy metode z klasy bazowej
	{
		return getSideLength() * getSideLength();
	}

	float getSideLength() const
	{
		return _sideLength;
	}

	void setSideLength(float sideLength)
	{
		_sideLength = sideLength;
	}

private:
	float _sideLength;

};

