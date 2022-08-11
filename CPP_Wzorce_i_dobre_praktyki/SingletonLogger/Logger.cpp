#include <iostream>

#include "Logger.h"

Logger* Logger::_instance = nullptr; //4.  inicjalizacja pola statycznego

Logger* Logger::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Logger(); // to sie wywo�a tylko raz podczas ca�ego naszego programu
	}
	return _instance;
}

void Logger::log(const std::string& str)
{
	_file << str << "\n";
}