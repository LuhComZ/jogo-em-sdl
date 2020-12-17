#include <vector>
class GameObject;

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void draw();
	void update();

	GameObject *addObj(GameObject *obj);

private:
	std::vector<GameObject *> objects;
};