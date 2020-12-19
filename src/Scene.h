class ObjectManager;
class Map;

class Scene
{
public:
	Scene();
	~Scene();

	void update();
	void draw();
private:
	ObjectManager *manager;
	Map* map;
};