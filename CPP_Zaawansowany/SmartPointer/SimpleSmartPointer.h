#pragma once

class SimpleSmartPointer
{
public:
	SimpleSmartPointer(int* data)
		: _data(data)
	{
		//_data = data;
	}

	~SimpleSmartPointer()
	{
		delete _data;
		// _data = nullptr; //tutaj nie potrzeba bo po delete juz obiekt naszej klasy nie istnieje i nie ma mozliwosci odwolac sie do taj pamieci niechcacy
	}

	int operator*()
	{
		return *_data;
	}

	int* operator->()
	{
		return _data;
	}

private:
	int* _data;
};

