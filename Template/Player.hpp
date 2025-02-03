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
	void prendDesDegats();
	void soigneDesPv();
	int getPv()const;
	unique_ptr<Sprite> playerSprite;
private:
	void loadTextures();
	void updateAnimation(float deltaTime);
	void updateHealthBar();
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
