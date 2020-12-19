#include "sprite.h"

Sprite::Sprite(const char *path)
{
	SDL_Surface *surface = IMG_Load(path);
	if (surface)
	{
		animations = surface->h / 64;
		frames = surface->w / 64;
		texture = SDL_CreateTextureFromSurface(Game::renderer, surface);

		SDL_FreeSurface(surface);
	}
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
}

void Sprite::draw(int x, int y)
{
	src.x = 64 * (currentFrame % frames);
	src.y = 64 * currentAnim;
	src.w = 64;
	src.h = 64;

	dest.x = x;
	dest.y = y;
	dest.w = 64;
	dest.h = 64;

	SDL_RenderCopy(Game::renderer, texture, &src, &dest);
	currentFrame++;
}

void Sprite::changeAnimation(Animations animation)
{
	currentAnim = animation;
}