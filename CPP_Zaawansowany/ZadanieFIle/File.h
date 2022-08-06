#pragma once

#include <fstream>
//Klasa File
//* RAII
//* c - tor przyjmujacy nazwê pliku, rzuca wyj¹tek gdy nie uda siê otwrzyc pliku 
//* d - tor zamyka plik
//* Mile widziane funkjce szablonowe zapisuj¹ce / wczytj¹ce dowonly typ danych(wspieraj¹cy operator << >>)
//* Zak³adamy, ze 1 linia pliku 1 wartoœæ(dane nie mog¹ zwieraæ bia³ych znaków)
//* Zak³adamy, ¿e u¿ytkownik zna format pliku i bêdzie wczytywa³ ró¿ne typy wed³ug znanej sobie kolejnoœci
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


	//operatorory << >> s¹ rzadkim przypadkiem w którym zaprzyjaŸnianie ma sens
	//poniewa¿ z obowi¹zku s¹ deklarowane poza klas¹, a korzystamy z nich tak jakby by³y w tej klasie
	//sama idea zaprzyjaŸniania jest "œliska", poniewa¿ omija mechanizmy enkapsulacji
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
