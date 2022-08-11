#pragma once
#include "Level.h"

class Game
{
public:	
	Game()
		: currentLevel()
	{
	}

	void loadLevel();

	void start();

private:
	Level currentLevel;
};

