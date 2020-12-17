#include "Scene.h"
#include "map.h"
#include "ObjectManager.h"

Scene::Scene()
{}

Scene::~Scene()
{
	delete map;
	delete manager;
}

void Scene::draw()
{
	map->draw();
	manager->draw();
}
