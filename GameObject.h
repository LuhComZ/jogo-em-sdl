class Vector2D;
class Sprite;

class GameObject
{
public:
	GameObject(const char* path);

	~GameObject();

	void update();
	void draw();
	bool active = false;
		Vector2D* getPos()
	{
		return position;
	};
	Vector2D* getSpeed()
	{
		return speed;
	};

private:
	Sprite* sprite;
	Vector2D* speed;
	Vector2D* position;
};