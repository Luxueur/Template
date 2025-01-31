#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Player
{
public:
	Player();
	void update(float deltaTime);
	void render(RenderWindow& window);
	void setDirection(Vector2f direction);
	Vector2f getDirection();
private:
	Texture playerTexture;
	Sprite playerSprite;
	Vector2f direction;
	float speed;
};
