#pragma once

#include <string>
#include <fstream>

class Logger
{
public:
	static Logger* getInstance(); // 3. publiczna metoda twor�ca i zwracajaca instancje. Tworzy 1 instancje dopiero wtedy kiedy jest potrzebna

	void log(const std::string& str); //pozosta�e pola i metody nie musz� by� static

private:
	Logger() //1 prywatny c-tor
	{
		_file = std::ofstream("Log.txt", std::ios::out | std::ios::app);
	}
	
	~Logger() = delete;

	//singleton nie ma destruktora, bo nigdy sie nie wywo�a 
	static Logger* _instance; //2 prywatne statyczne pole wskazujace na samego siebie

	std::ofstream _file; //pozosta�e pola i metody nie musz� by� static
};

