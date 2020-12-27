#include "ObjectManager.h"
#include "GameObject.h"

ObjectManager::ObjectManager()
{

};

ObjectManager::~ObjectManager()
{
	objects.clear();
};

void ObjectManager::draw()
{
	for (auto&& object : objects)
	{
		if (object->active)
		{
			object->draw();
		}
	}
};

void ObjectManager::update()
{
	for (auto&& object : objects)
	{
		if (object->active)
		{
			object->update();
		}
	}
};

void ObjectManager::addObj(GameObject* obj)
{
	std::unique_ptr<GameObject> newObj;
	newObj.reset(obj);
	objects.push_back(std::move(newObj));
}