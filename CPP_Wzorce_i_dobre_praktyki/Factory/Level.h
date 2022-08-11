#pragma once
#include <vector>

#include "Shape.h"
#include "Circle.h"
#include "Square.h"


class Level
{
public:
	Level()
	{
	}

	enum class ShapeToCreate
	{
		CIRCLE,
		SQUARE
	};

	std::shared_ptr<Shape> createShape(ShapeToCreate shape) //metodaFabrykujaca decyduje ktory kszta³t utworzyæ
	{
		std::shared_ptr<Shape> createdShape;

		switch (shape)
		{
		case Level::ShapeToCreate::CIRCLE:
			createdShape = std::make_shared<Circle>(0.5);
			break;
		case Level::ShapeToCreate::SQUARE:
			createdShape = std::make_shared<Square>(6.0);
			break;
		default:
			std::cout << "Niewspirany ShapeToCreate\n";
			break;
		}

		return createdShape;
	}

	void load() //w przyszlosci moze miec jakis parametr z poziomem do wczytania
	{
		//wyobraŸmy sobie ¿e nasz level sk³ada siê z 1 samochodu
		shapes.push_back(createShape(Level::ShapeToCreate::CIRCLE));
		shapes.push_back(createShape(Level::ShapeToCreate::SQUARE));
		shapes.push_back(createShape(Level::ShapeToCreate::CIRCLE));
	}

	void draw()
	{
		for (const auto& shape : shapes)
		{
			shape->draw();
		}
	}

private:
	std::vector<std::shared_ptr<Shape>> shapes;
};

