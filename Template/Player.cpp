#include "Player.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

Player::Player() : speed(200.0f) {
	if (!playerTexture.loadFromFile("Images/Factions/Knights/Troops/Warrior/Blue/Idle/Warrior_Blue_Idle0.png"))
	{
		throw std::runtime_error("Phillipe Ou tu te caches ?");
	}
	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(Vector2f(playerTexture.getSize()) / 2.f);
	playerSprite.setPosition(Vector2f(400.0f, 300.0f));
}

void Player::update(float deltaTime) {
	playerSprite.move(direction * speed * deltaTime);
}

void Player::render(RenderWindow& window) {
	window.draw(playerSprite);
}

void Player::setDirection(Vector2f direction) {
	this->direction = direction;
}

Vector2f Player::getDirection() {
	return direction;
}
