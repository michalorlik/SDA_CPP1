#include <iostream>
#include "AreaCalculator.h"
#include "SumAreaCalulatorOutputter.h"

#include "Square.h"
#include "Circle.h"

int main()
{
	//przygotowanie danych 
	std::vector<std::shared_ptr<Shape2D>> shapes; // wektor do trzymania r�nych ksztalt�w
	
	shapes.push_back(std::make_shared<Square>(3.4)); //umieszczam w tym wektorze wska�nik na Kwadrat
	shapes.push_back(std::make_shared<Square>(7.0));
	shapes.push_back(std::make_shared<Square>(1.0));
	shapes.push_back(std::make_shared<Square>(2.5));
	shapes.push_back(std::make_shared<Square>(3.9));
	shapes.push_back(std::make_shared<Circle>(5.0));
	shapes.push_back(std::make_shared<Circle>(1.3));

	//faktycznie wykonana praca naszego progrmu
	AreaCalculator areaCalc(shapes); //tworze sobie obiekt klasy AreaCalculator, czyli ten kt�ry zajmuje si� zliczaniem
	SumAreaCalulatorOutputter areaOutputter(areaCalc); //Tworze sobie obiekt klasy SumAreaCalulatorOutputter, czyli ten kt�ry faktycznie bedzie zajmowa� si� wypisywaniem
	areaOutputter.outputCout(); // uzywam klasy wypisujacej do wypisanie wyniku

	//POCZATEK: DEMO POLIMORFIZMU PRZY UZYCIU KONTENEROW I SHARED_PTR
	//for (auto it = shapes.begin(); it != shapes.end(); it++)
	//{
	//	// (*it) wy�uskuje iterator czyli daje nam shared_ptr<Shape2D>
	//	std::cout << "Pole: " << (*it)->area() << std::endl; // (*it) to zwraca nam shared_ptr dopiero na kt�rym mog� wo�a� ->
	//}

	//for (const auto& shape : shapes)
	//{
	//	std::cout << "Pole: " << shape->area() << std::endl;
	//}
	//KONIEC: DEMO POLIMORFIZMU PRZY UZYCIU KONTENEROW I SHARED_PTR


}
