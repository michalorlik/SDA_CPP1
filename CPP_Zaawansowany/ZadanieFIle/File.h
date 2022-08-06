#pragma once

#include <fstream>
//Klasa File
//* RAII
//* c - tor przyjmujacy nazw� pliku, rzuca wyj�tek gdy nie uda si� otwrzyc pliku 
//* d - tor zamyka plik
//* Mile widziane funkjce szablonowe zapisuj�ce / wczytj�ce dowonly typ danych(wspieraj�cy operator << >>)
//* Zak�adamy, ze 1 linia pliku 1 warto��(dane nie mog� zwiera� bia�ych znak�w)
//* Zak�adamy, �e u�ytkownik zna format pliku i b�dzie wczytywa� r�ne typy wed�ug znanej sobie kolejno�ci
//np :
//string
//int
//double
//int

class File
{
public:
	enum class OpenMode {
		WRITE, //out | app
		READ //in
	};

	File(const std::string& filePath, OpenMode openMode); //w c-torze otwieramy plik (in, out | app)
	~File(); //w d-torze zamykamy plik


	//operatorory << >> s� rzadkim przypadkiem w kt�rym zaprzyja�nianie ma sens
	//poniewa� z obowi�zku s� deklarowane poza klas�, a korzystamy z nich tak jakby by�y w tej klasie
	//sama idea zaprzyja�niania jest "�liska", poniewa� omija mechanizmy enkapsulacji
	template<typename T>
	friend const File& operator<<(const File& file, T data);

	template<typename T>
	friend const File& operator>>(const File& file, T data);

	//T readValue();
	//writeValue(T);

private:
	std::fstream _filestream;
};

template<typename T>
const File& operator<<(const File& file, T data) 
{
	if (READ)
		throw std::invalid_argument;
}

template<typename T>
const File& operator>>(const File& file, T data)
{
	if (WRITE)
		throw std::invalid_argument;
}
