#include <vector>
#include "Vector2D.h"
#include "sdl.h"
#include "Vector3D.h"

struct Tile
{
	Vector3D position;
	Vector2D index;
};

class Map
{
public:
	Map(const char* path);
	~Map();

	void draw();
	std::vector<std::vector<Vector2D>> map;
private:
	SDL_Texture* texture;
	SDL_Rect src;
	SDL_Rect dest;
};