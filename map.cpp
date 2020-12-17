#include "map.h"
#include "game.h"

Map::Map(const char* path)
{
	SDL_Surface* surface = IMG_Load(path);
	if (surface)
	{
		texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
	}
}

void Map::draw()
{
	for (int row = 0; row < map.size(); row++)
	{
		for (int column = 0; column < map[row].size(); column++)
		{
			Vector2D tile = map[row][column];

			src.x = tile.x * 64;
			src.y = tile.y * 64;
			src.h = 64;
			src.w = 64;

			dest.x = row * 64;
			dest.y = column * 64;

			dest.w = 64;
			dest.h = 64;

			SDL_RenderCopy(Game::renderer, texture, &src, &dest);
		}
	}
}