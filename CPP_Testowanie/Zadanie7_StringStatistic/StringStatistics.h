#pragma once
#include <string>
#include <algorithm>

#include "StringUtils.h"

class StringStatisticsWithUtils //wersja z Utils
{
public:
	StringStatisticsWithUtils(std::string str)
		: _str(str)
	{
	}

	int getLetterCharCount()
	{
		return std::count_if(_str.begin(), _str.end(), StringUtils::isLetter);
	}

	int getDigitCharCount()
	{
		return std::count_if(_str.begin(), _str.end(), StringUtils::isDigit);
	}

	int getSpecialCharCount() 
	{
		return std::count_if(_str.begin(), _str.end(), StringUtils::isSpecial);
	}

private:
	std::string _str;
};

//********************************************************************************************
class StringStatisticsWithStaticMethods // wersja ze statycznymi metodami
{
public:
	StringStatisticsWithStaticMethods(std::string str)
		: _str(str)
	{
	}

	int getLetterCharCount()
	{
		return std::count_if(_str.begin(), _str.end(), isLetter);
	}

	int getDigitCharCount()
	{
		//auto isDigit = [](const char c) {return isBetween(c, 48, 57); };
		return std::count_if(_str.begin(), _str.end(), isDigit);
	}

	int getSpecialCharCount()
	{
		return std::count_if(_str.begin(), _str.end(), isSpecial);
	}

private:
	std::string _str;

	static bool isBetween(const char c, const char lower, const char higher)
	{
		return (c >= lower && c <= higher);
	}

	static bool isDigit(const char c)
	{
		// return (c >= 48 && c <= 57);
		return isBetween(c, 48, 57);
	}

	static bool isLetter(const char c)
	{
		//return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
		return isBetween(c, 65, 90) || isBetween(c, 97, 122);
	}

	static bool isSpecial(const char c)
	{
		return !isDigit(c) && !isLetter(c);
	}
};

//********************************************************************************************
class StringStatisticsWithLambdas // wersja z lambdami
{
public:
	StringStatisticsWithLambdas(std::string str)
		: _str(str)
	{
	}

	int getLetterCharCount()
	{
		auto isLetter = [](const char c) {return isBetween(c, 65, 90) || isBetween(c, 97, 122); };
		return std::count_if(_str.begin(), _str.end(), isLetter);
	}

	int getDigitCharCount()
	{
		auto isDigit = [](const char c) {return isBetween(c, 48, 57); };
		return std::count_if(_str.begin(), _str.end(), isDigit);
	}

	int getSpecialCharCount()
	{
		auto isSpecial = [](const char c) { return !isBetween(c, 65, 90) && !isBetween(c, 97, 122) && !isBetween(c, 48, 57); };
		return std::count_if(_str.begin(), _str.end(), isSpecial);
	}

private:
	std::string _str;

	static bool isBetween(const char c, const char lower, const char higher)
	{
		return (c >= lower && c <= higher);
	}
};