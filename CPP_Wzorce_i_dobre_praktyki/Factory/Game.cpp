#include "Game.h"

void Game::loadLevel()
{
	currentLevel.load();
}

void Game::start()
{
	currentLevel.draw();
}