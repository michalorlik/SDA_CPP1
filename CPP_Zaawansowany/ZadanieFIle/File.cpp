#include "File.h"
#include <iostream>

File::File(const std::string& filePath, OpenMode openMode)
{
	if (openMode == OpenMode::READ)
	{
		_filestream = std::fstream(filePath, std::ios::in);
	}
	else if (openMode == OpenMode::WRITE)
	{
		_filestream = std::fstream(filePath, std::ios::out | std::ios::app);
	}
	else
	{
		std::cout << "Nieznany tryb otwarcia pliku/n";
	}
}