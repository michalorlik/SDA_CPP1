#pragma once
#include <iostream>

#include "AreaCalculator.h"

class SumAreaCalulatorOutputter
{
public:
	SumAreaCalulatorOutputter(AreaCalculator areaCalc)
		: _areaCalc(areaCalc)
	{
	}

	void outputCout() //aby ta metoda dzia�a�� te� dla VolumeCalc trzeba wydzielic klase bazow� dla obu Calculator(z czysto virtualna metoda sum)  i u�ywa� polimorfizmu
	{
		std::cout << "Summed area is equal to: " << _areaCalc.sum() << std::endl;
	}

private:
	AreaCalculator _areaCalc;
};

