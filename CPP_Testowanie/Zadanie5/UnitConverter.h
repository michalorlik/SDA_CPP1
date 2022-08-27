#pragma once
class UnitConverter
{
public:
	double feetToMeter(double feet);
	double meterToFeet(double meter);
	double celciusToFarenheit(double celcius);
	double farenheitToCelcius(double farenheit);
private:
	const double feetToMeterFactor = 3.281;
};

