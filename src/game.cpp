#include "GameObject.h"
#include "game.h"
#include "map.h"

int wa, ha;
GameObject *obj;
SDL_Renderer *Game::renderer = nullptr;

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
				obj = new GameObject("../assets/g.png");
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
	delete obj;
};

bool Game::isRunning() const
{
	return running;
};

void Game::update()
{
	obj->update();
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
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_d:
			obj->getSpeed()->x = 1;
			break;
		case SDLK_a:
			obj->getSpeed()->x = -1;
			break;
		case SDLK_w:
			obj->getSpeed()->y = -1;
			break;
		case SDLK_s:
			obj->getSpeed()->y = 1;
			break;
		}
		break;
	case SDL_KEYUP:
		switch (event.key.keysym.sym)
		{
		case SDLK_a:
			obj->getSpeed()->x = 0;
			if (obj->getPos()->x % 64 != 0)
			{
				obj->getPos()->x -= obj->getPos()->x % 64;
			}
			break;
		case SDLK_d:
			obj->getSpeed()->x = 0;
			if (obj->getPos()->x % 64 != 0)
			{
				obj->getPos()->x += 64 - obj->getPos()->x % 64;
			}
			break;
		case SDLK_w:
			obj->getSpeed()->y = 0;
			if (obj->getPos()->y % 64 != 0)
			{
				obj->getPos()->y -= obj->getPos()->y % 64;
			}
			break;
		case SDLK_s:
			obj->getSpeed()->y = 0;
			if (obj->getPos()->y % 64 != 0)
			{
				obj->getPos()->y += 64 - obj->getPos()->y % 64;
			}
			break;
		}
	default:
		break;
	}
}

void Game::draw()
{
	SDL_RenderClear(Game::renderer);
	// map->draw();
	obj->draw();
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
	SDL_RenderPresent(Game::renderer);
};