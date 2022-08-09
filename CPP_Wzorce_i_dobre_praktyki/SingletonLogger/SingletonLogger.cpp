#include <iostream>

#include "Logger.h"

void bar()
{
	Logger* logger = Logger::getInstance();

	logger->log("bar() BEGIN");
	//tutaj sie dzieje jakas magia
	logger->log("bar() cos zrobila");
	logger->log("bar() END");
}

void fun(int x)
{
	Logger* logger = Logger::getInstance();

	logger->log("fun() BEGIN");
	logger->log("fun() param x");
	logger->log(std::to_string(x));
	bar();
	logger->log("fun() END");
}


int main()
{
	//Logger* logger = Logger::getInstance(); //tutaj wo³am publiczna metoda, która jest static
	//logger->log("SDA");
	//logger->log("Yabadabadu");
	//logger->log("2+2");
	//logger->log("ERROR:KONIEC ");

	fun(13);

}

