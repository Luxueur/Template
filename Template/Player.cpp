#include "Player.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

Player::Player() : speed(200.0f), animationTime(0.0f), currentFrame(0), currentState(State::Idle) {
    loadTextures();
    playerSprite = make_unique<Sprite>();
    playerSprite->setTexture(*idleTextures[0]);
    playerSprite->setOrigin(Vector2f(idleTextures[0]->getSize()) / 2.f);
    playerSprite->setPosition(Vector2f(400.0f, 300.0f));
}

void Player::loadTextures()
{
	for (int i = 0; i < 4; ++i) {
		auto texture = make_shared<Texture>();
		if (!texture->loadFromFile("Images/Factions/Knights/Troops/Warrior/Blue/Idle/Warrior_Blue_Idle" + to_string(i) + ".png")) {
			throw std::runtime_error("Failed to load idle texture");
		}
		idleTextures.push_back(texture);
	}

	for (int i = 0; i < 5; i++) {
		auto texture = make_shared<Texture>();
		if (!texture->loadFromFile("Images/Factions/Knights/Troops/Warrior/Blue/Walk/Warrior_Blue_Walk" + to_string(i) + ".png")) {
			throw std::runtime_error("Failed to load walk texture");
		}
		walkTextures.push_back(texture);
	}
}


void Player::update(float deltaTime) {
	playerSprite->move(direction * speed * deltaTime);
	updateAnimation(deltaTime);
}

void Player::render(RenderWindow& window) {
	window.draw(*playerSprite);
}

void Player::setDirection(Vector2f direction) {
	this->direction = direction;
	if (direction.x != 0.f || direction.y != 0.f)
	{
		currentState = State::Walk;
	}else
	{
		currentState = State::Idle;
	}

	if (direction.x < 0)
	{
		playerSprite->setScale(-1.f,1.f);
	}
	else if(direction.x > 0)
	{
		playerSprite->setScale(1.f,1.f);
	}
}

Vector2f Player::getDirection() {
	return direction;
}

void Player::updateAnimation(float deltaTime)
{
	animationTime += deltaTime;
	if (animationTime >= 0.1f)
	{
		animationTime = 0.f;
		currentFrame = (currentFrame + 1) % (currentState == State::Idle ? idleTextures.size() : walkTextures.size());
		playerSprite->setTexture(* (currentState == State::Idle ? idleTextures[currentFrame] : walkTextures[currentFrame]));
	}
}
