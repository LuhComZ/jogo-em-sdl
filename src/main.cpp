#include "game.h"

int WinMain()
{
	Game* game = new Game("nome legal", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (game->isRunning())
	{
		game->handleEvents();
		game->update();
		game->draw();
	}
	
	delete game;

	return 0;
}