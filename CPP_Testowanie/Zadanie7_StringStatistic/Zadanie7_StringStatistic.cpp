#include <iostream>

#include "StringUtils.h"


int main()
{
	std::cout << "Hello World!\n";

	char c = '7';

	std::cout << "StringUtils::isDigit " << StringUtils::isDigit(c) << std::endl;
	std::cout << "A teraz zawolam druga metode" << std::endl;
	std::cout << "StringUtilsWithCout::isDigit " << StringUtilsWithCout::isDigit(c) << std::endl;
}
