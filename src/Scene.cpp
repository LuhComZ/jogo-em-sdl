#include "Scene.h"
#include "map.h"
#include "ObjectManager.h"
#include "GameObject.h"
#include <iostream>

Scene::Scene()
{
	map = new Map("../assets/t.png");
	manager = new ObjectManager();
	GameObject* obj = new GameObject("../assets/g.png");

	manager->addObj(obj);
}

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

void Scene::update()
{
	manager->update();
}
