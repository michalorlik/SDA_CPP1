#pragma once

namespace StringUtils
{

	bool isBetween(const char c, const char lower, const char higher)
	{
		return (c >= lower && c <= higher);
	}

	bool isDigit(const char c)
	{
		// return (c >= 48 && c <= 57);
		return isBetween(c, 48, 57);
	}

	bool isLetter(const char c)
	{
		//return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
		return isBetween(c, 65, 90) || isBetween(c, 97, 122);
	}

	bool isSpecial(const char c)
	{
		return !isDigit(c) && !isLetter(c);
	}

}
