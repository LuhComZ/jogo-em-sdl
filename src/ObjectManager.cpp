#include "ObjectManager.h"
#include "GameObject.h"

ObjectManager::ObjectManager(){

};

ObjectManager::~ObjectManager()
{
	for (GameObject *obj : objects)
	{
		delete obj;
	}

	objects.clear();
};

void ObjectManager::draw()
{
	for (GameObject *obj : objects)
	{
		if (obj->active)
		{
			obj->draw();
		}
	}
};

void ObjectManager::update()
{
	for (GameObject *obj : objects)
	{
		if (obj->active)
		{
			obj->update();
		}
	}
};

GameObject *ObjectManager::addObj(GameObject *obj)
{
	objects.emplace_back(obj);
	return obj;
}