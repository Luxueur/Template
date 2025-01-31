#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
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
	Sprite playerSprite;
private:
	void loadTextures();
	void updateAnimation(float deltaTime);
	
	enum class State { Idle, Walk };
	State currentState;
	
	vector<shared_ptr<Texture>> idleTextures;
	vector<shared_ptr<Texture>> walkTextures;
	unique_ptr<Sprite> playerSprite;
	Texture playerTexture;
	//Sprite playerSprite;
	Vector2f direction;
	float speed;
	float animationTime;
	size_t currentFrame;
};
