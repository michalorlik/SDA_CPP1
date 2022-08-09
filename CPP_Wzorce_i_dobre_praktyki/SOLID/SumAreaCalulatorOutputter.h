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

	void outputCout() //aby ta metoda dzia³a³¹ te¿ dla VolumeCalc trzeba wydzielic klase bazow¹ dla obu Calculator(z czysto virtualna metoda sum)  i u¿ywaæ polimorfizmu
	{
		std::cout << "Summed area is equal to: " << _areaCalc.sum() << std::endl;
	}

	void outputFile()
	{
		//
	}

private:
	AreaCalculator _areaCalc;
};

