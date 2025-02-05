#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	void updateAttackAnimation(float deltaTime);
	unique_ptr<Sprite> playerSprite;
	void attack();
	

private:
	void loadTextures();
	void updateAnimation(float deltaTime);
	
	enum class State { Idle, Walk,Attacking,AttackingBow };
	State currentState;
	vector<shared_ptr<Texture>> idleTextures;
	vector<shared_ptr<Texture>> walkTextures;
	vector<shared_ptr<Texture>> attackTexturesUp;
	vector<shared_ptr<Texture>> attackTexturesDown;
	vector<shared_ptr<Texture>> attackTexturesLeft;
	vector<shared_ptr<Texture>> attackTexturesRight;
	vector<shared_ptr<Sprite>> healthBar;
	//shared_ptr<Texture> heartTexture;
	int pv;
	int currentAttack;
	float attackCooldown;
	float attackTimer;
	bool isAttacking;
	bool newAttackRequested;
	Texture playerTexture;
	Vector2f direction;
	float speed;
	float animationTime;
	int attackFrame;
	size_t currentFrame;
	float attackSoundTimer;
	SoundBuffer attackSoundBuffer;
	Sound attackSound;
	SoundBuffer bowSoundBuffer;
	Sound bowSound;

};