#include <iostream>
#include <utility>

int main()
{
	std::pair<int, std::string> parka(4,"SDA");
	std::pair parka2(4, "SDA"); //OD 17
	std::pair<int, std::string> parka5(4, "SDA"); //PRZED 17
	auto parka3 = std::make_pair(4, "SDA");//PRZED 17
	auto parka4 = std::pair(4, "SDA"); // OD 17
	auto parka4 = std::pair<int, std::string>(4, "SDA"); //PRZED 17
}
