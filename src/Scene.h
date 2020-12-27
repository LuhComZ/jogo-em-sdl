#include "sdl.h"
class ObjectManager;
class Map;

class Scene
{
public:
	Scene();
	~Scene();

	void update();
	void draw();
	virtual void handleEvents(SDL_Event event);

private:
	ObjectManager *manager;
	Map* map;
};