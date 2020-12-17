#include "GameObject.h"
#include "sprite.h"
#include "Vector2D.h"

GameObject::GameObject(const char *path)
{
	sprite = new Sprite(path);
	position = new Vector2D(0, 0);
	speed = new Vector2D(0, 0);

	if (sprite && position && speed)
	{
		active = true;
	}
}

GameObject::~GameObject()
{
	delete sprite;
	delete position;
	delete speed;
}

void GameObject::draw()
{
	sprite->draw(position->x, position->y);
}

void GameObject::update()
{
	position->x += speed->x;
	position->y += speed->y;
}