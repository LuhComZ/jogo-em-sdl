#include "game.h"

enum Animations
{
	IDLE = 0,
};

class Sprite
{
public:
	Sprite(const char *path);
	~Sprite();

	void draw(int x, int y);
	void changeAnimation(Animations animation);

private:
	SDL_Texture *texture;
	SDL_Rect src;
	SDL_Rect dest;
	int animations;
	int frames;
	int currentFrame = 0;
	int currentAnim = 0;
};