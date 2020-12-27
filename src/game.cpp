#include "GameObject.h"
#include "game.h"
#include "map.h"
#include "Scene.h"

int wa, ha;
Scene* scene;
SDL_Renderer *Game::renderer = nullptr;

void drawGrid(SDL_Window* window)
{
	SDL_GetWindowSize(window, &wa, &ha);
	SDL_SetRenderDrawColor(Game::renderer, 0x00, 0x00, 0x00, 1);
	for (int w0 = 0; w0 <= wa / 64; w0++)
	{
		SDL_RenderDrawLine(Game::renderer, w0 * 64, 0, w0 * 64, ha);
	}
	for (int h0 = 0; h0 <= ha / 64; h0++)
	{
		SDL_RenderDrawLine(Game::renderer, 0, h0 * 64, wa, h0 * 64);
	}
	SDL_SetRenderDrawColor(Game::renderer, 0xFF, 0xFF, 0xFF, 1);
}

Game::Game(const char *title, int x, int y, int w, int h, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		int flags = !fullscreen ? SDL_WINDOW_RESIZABLE : SDL_WINDOW_FULLSCREEN | SDL_WINDOW_RESIZABLE;
		window = SDL_CreateWindow(title, x, y, w, h, flags);

		if (window)
		{
			Game::renderer = SDL_CreateRenderer(window, -1, 0);
			if (Game::renderer)
			{
				IMG_Init(IMG_INIT_PNG);
				SDL_SetRenderDrawColor(Game::renderer, 0xFF, 0xFF, 0xFF, 1);
				running = true;
				scene = new Scene();
			};
		};
	}
};

Game::~Game()
{
	SDL_DestroyRenderer(Game::renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	IMG_Quit();
	delete scene;
};

bool Game::isRunning() const
{
	return running;
};

void Game::update()
{
	scene->update();
	// discord->update();
};

void Game::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		running = false;
		break;
	default:
		scene->handleEvents(event);
		break;
	}
}

void Game::draw()
{
	SDL_RenderClear(Game::renderer);
	scene->draw();
	drawGrid(window);
	SDL_RenderPresent(Game::renderer);
};