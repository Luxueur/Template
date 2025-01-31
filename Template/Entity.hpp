//Entity (classe de base) : classe abstraite servant de base aux objets du jeu(ennemis, joueur...)
#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#pragma once
using namespace sf;
using namespace std;

class Entity {
public:


	Entity();
	~Entity();

	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

};

#endif // !ENTITY_HPP