#include "map.h"
#include "game.h"

Map::Map(const char *path)
{
	SDL_Surface *surface = IMG_Load(path);
	if (surface)
	{
		texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
		SDL_FreeSurface(surface);
	}
}

Map::~Map()
{
	SDL_DestroyTexture(texture);
}

void Map::draw()
{
	for (int row = 0; row < 25; row++)
	{
		for (int column = 0; column < 20; column++)
		{
			Vector2D tile = map[row][column];

			src.x = tile.x * 64;
			src.y = tile.y * 64;
			src.h = 64;
			src.w = 64;

			dest.x = 800 /25 * row;
			dest.y = 640 /25 * column;

			dest.w = 64;
			dest.h = 64;

			std::cout << SDL_RenderCopy(Game::renderer, texture, &src, &dest) << std::endl;
		}
	}
}

void Map::changeTile(int x, int y, Vector2D newTile)
{
	map[x][y] = newTile;
}