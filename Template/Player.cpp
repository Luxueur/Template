#include "Player.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Camera.hpp"


using namespace sf;
using namespace std;

<<<<<<< Updated upstream
Player::Player() : pv(3), speed(200.0f), animationTime(0.0f), currentFrame(0), currentState(State::Idle) {
    loadTextures();
    playerSprite = make_unique<Sprite>();
    playerSprite->setTexture(*idleTextures[0]);
    playerSprite->setOrigin(Vector2f(idleTextures[0]->getSize()) / 2.f);
    playerSprite->setPosition(Vector2f(400.0f, 300.0f));
	direction = Vector2f(0.0f, 0.0f);

	

	for (int i = 0; i < pv; i++)
	{
		auto heart = make_unique<Sprite>();
		heart->setTexture(playerTexture); //texture pour les pv a rajouter et remplacer par celle du player
		heart->setPosition(10+i*30,10);
		healthBar.push_back(move(heart));
	}
	cout << "initialisation des pv: " << pv << endl;
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

	if (!playerTexture.loadFromFile("Images/Factions/Knights/Troops/Warrior/Blue/Idle/Warrior_Blue_Idle0.png")) {
		throw std::runtime_error("Failed to load future health texture");
	}
}


void Player::update(RenderWindow& window, float deltaTime) {
	
	playerSprite->move(direction * speed * deltaTime);

	updateAnimation(deltaTime);
	updateHealthBar(window, playerSprite->getPosition());
}

void Player::render(RenderWindow& window) {
	window.draw(*playerSprite);
	for (const auto& heart: healthBar)
	{
		window.draw(*heart);
	}
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
=======
Player::Player() : speed(200.0f){
	if (!playerTexture.loadFromFile("Images/Factions/Knights/Troops/Warrior/Blue/Idle/Warrior_Blue_Idle0.png"))
	{
		throw std::runtime_error("Phillipe Ou tu te caches ?");
	}
	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(Vector2f(playerTexture.getSize()) / 2.f);
	playerSprite.setPosition(Vector2f(400.0f, 300.0f));
}

void Player::update(float deltaTime){
	playerSprite.move(direction * speed * deltaTime);
}

void Player::render(RenderWindow& window){
	window.draw(playerSprite);
}

void Player::setDirection(Vector2f direction){
	this->direction = direction;
>>>>>>> Stashed changes
}

Vector2f Player::getDirection() {
	return direction;
<<<<<<< Updated upstream
}
void Player::prendDesDegats(RenderWindow& window) {
	if (pv > 0) {
		--pv;
		cout << "Pv aprés avoir pris les degats : " << pv << endl;
		updateHealthBar(window,playerSprite->getPosition());
	}
}
void Player::soigneDesPv(RenderWindow& window) {
	++pv;
	cout << "Pv aprés les soins : " << pv << endl;
	updateHealthBar(window,playerSprite->getPosition());
}
int Player::getPv() const {
	return pv;
}
void Player::updateHealthBar(RenderWindow& window, const Vector2f& playerPosition){

	healthBar.clear();
	View view = window.getView();
	FloatRect viewport = view.getViewport();
	Vector2f healthBarPosition(viewport.left + playerPosition.x - 645.0f,viewport.top + playerPosition.y - 480.0f);
	for (int i = 0; i < pv; ++i) {
		auto heart = make_unique<Sprite>();
		heart->setTexture(playerTexture); // texture pour les pv a remplacer par le playerTexture
		heart->setPosition(healthBarPosition + Vector2f(i * 30, 10)); // position du pv (x, y));
		healthBar.push_back(move(heart));
	}
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
=======
}
>>>>>>> Stashed changes
