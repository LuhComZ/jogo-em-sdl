#include "sdl.h"
// #include "discord.h"
#include <iostream>

class Game
{
public:
	Game(const char *title, int x, int y, int w, int h, bool fullscreen);
	~Game();

	void update();
	void draw();
	void handleEvents();

	bool isRunning();

	static SDL_Renderer *renderer;

private:
	SDL_Event event;
	SDL_Window *window;
	// Discord* discord;
	bool running = false;
};