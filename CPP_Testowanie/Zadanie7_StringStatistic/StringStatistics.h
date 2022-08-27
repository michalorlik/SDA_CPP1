#pragma once
#include <string>
#include <algorithm>

#include "StringUtils.h"

class StringStatistics
{
public:
	StringStatistics(std::string str)
		: _str(str)
	{
	}

	int getLetterCharCount()
	{
		//int count = 0;
		//for (auto it = _str.begin(); it != _str.end(); ++it)
		//{
		//	if (isLetter(*it))
		//	{
		//		++count;
		//	}
		//}
		//return count;
		return std::count_if(_str.begin(), _str.end(), StringUtils::isLetter);
	}

	int getDigitCharCount()
	{
		//auto isDigit = [](const char c) {return isBetween(c, 48, 57); };
		return std::count_if(_str.begin(), _str.end(), StringUtils::isDigit);
	}

	int getSpecialCharCount() 
	{
		return std::count_if(_str.begin(), _str.end(), StringUtils::isSpecial);
	}

private:
	std::string _str;
	
	//static bool isBetween(const char c, const char lower, const char higher)
	//{
	//	return (c >= lower && c <= higher);
	//}

	//static bool isDigit(const char c)
	//{
	//	// return (c >= 48 && c <= 57);
	//	return isBetween(c, 48, 57);
	//}

	//static bool isLetter(const char c)
	//{
	//	//return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
	//	return isBetween(c, 65, 90) || isBetween(c, 97, 122);
	//}

	//static bool isSpecial(const char c)
	//{
	//	return !isDigit(c) && !isLetter(c);
	//}
};

