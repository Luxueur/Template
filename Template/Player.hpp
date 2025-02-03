#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Camera.hpp"

using namespace sf;
using namespace std;

class Player
{
public:
	Player();
	void update(RenderWindow& window, float deltaTime);
	void render(RenderWindow& window);
	void setDirection(Vector2f direction);
	Vector2f getDirection();
	void prendDesDegats(RenderWindow& window);
	void soigneDesPv(RenderWindow& window);
	int getPv()const;
	void updateHealthBar(RenderWindow& window, const Vector2f& playerPosition);
	unique_ptr<Sprite> playerSprite;

private:
	void loadTextures();
	void updateAnimation(float deltaTime);
	enum class State { Idle, Walk };
	State currentState;
	vector<shared_ptr<Texture>> idleTextures;
	vector<shared_ptr<Texture>> walkTextures;
	vector<shared_ptr<Sprite>> healthBar;
	//shared_ptr<Texture> heartTexture;
	int pv;
	Texture playerTexture;
	Vector2f direction;
	float speed;
	float animationTime;
	size_t currentFrame;

};