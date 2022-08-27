#pragma once
#include <string>

class FizzBuzz
{
public:
	std::string fizzBuzz(int i)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			return "FizzBuzz";
		} 
		else if (i % 3 == 0)
		{
			return "Fizz";
		}
		else if (i % 5 == 0)
		{
			return "Buzz";
		}
		else
		{
		return std::to_string(i);
		}
	}
};
