#include <vector>
#include <memory>
class GameObject;

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void draw();
	void update();

	void addObj(GameObject* obj);

private:
	std::vector<std::unique_ptr<GameObject>> objects;
};