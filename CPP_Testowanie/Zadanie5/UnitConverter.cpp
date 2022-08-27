#include "UnitConverter.h"

double UnitConverter::feetToMeter(double feet)
{
	return feet / feetToMeterFactor;
}

double UnitConverter::meterToFeet(double meter)
{
	return meter * feetToMeterFactor;
}

double UnitConverter::celciusToFarenheit(double celcius)
{
	return (celcius * 9 / 5) + 32;
}

double UnitConverter::farenheitToCelcius(double farenheit)
{
	return (farenheit - 32) * 5 / 9;
}