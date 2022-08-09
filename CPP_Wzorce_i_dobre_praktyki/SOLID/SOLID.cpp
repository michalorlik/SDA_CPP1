#include <iostream>
#include "AreaCalculator.h"
#include "SumAreaCalulatorOutputter.h"

#include "Square.h"
#include "Circle.h"

int main()
{
	//przygotowanie danych 
	std::vector<std::shared_ptr<Shape2D>> shapes; // wektor do trzymania ró¿nych ksztaltów
	
	shapes.push_back(std::make_shared<Square>(3.4)); //umieszczam w tym wektorze wskaŸnik na Kwadrat
	shapes.push_back(std::make_shared<Square>(7.0));
	shapes.push_back(std::make_shared<Square>(1.0));
	shapes.push_back(std::make_shared<Square>(2.5));
	shapes.push_back(std::make_shared<Square>(3.9));
	shapes.push_back(std::make_shared<Circle>(5.0));
	shapes.push_back(std::make_shared<Circle>(1.3));

	//faktycznie wykonana praca naszego progrmu
	AreaCalculator areaCalc(shapes); //tworze sobie obiekt klasy AreaCalculator, czyli ten który zajmuje siê zliczaniem
	SumAreaCalulatorOutputter areaOutputter(areaCalc); //Tworze sobie obiekt klasy SumAreaCalulatorOutputter, czyli ten który faktycznie bedzie zajmowa³ siê wypisywaniem
	areaOutputter.outputCout(); // uzywam klasy wypisujacej do wypisanie wyniku

	//POCZATEK: DEMO POLIMORFIZMU PRZY UZYCIU KONTENEROW I SHARED_PTR
	//for (auto it = shapes.begin(); it != shapes.end(); it++)
	//{
	//	// (*it) wy³uskuje iterator czyli daje nam shared_ptr<Shape2D>
	//	std::cout << "Pole: " << (*it)->area() << std::endl; // (*it) to zwraca nam shared_ptr dopiero na którym mogê wo³aæ ->
	//}

	//for (const auto& shape : shapes)
	//{
	//	std::cout << "Pole: " << shape->area() << std::endl;
	//}
	//KONIEC: DEMO POLIMORFIZMU PRZY UZYCIU KONTENEROW I SHARED_PTR


}
