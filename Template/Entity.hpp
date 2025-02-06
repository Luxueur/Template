//Entity (classe de base) : classe abstraite servant de base aux objets du jeu(ennemis, joueur...)
#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.hpp"
#pragma once
using namespace sf;
using namespace std;

class Entity {
public:
    Entity();
    virtual ~Entity();

    // Setters and Getters
    void setPosition(float x, float y);
    Vector2f getPosition() const;

    // Virtual functions for updating and drawing
    virtual void update(float deltaTime,RenderWindow& window);
    virtual void draw(RenderWindow& window);

protected:
    Sprite enemy;
    Texture enemyTexture;
};


/*class Dynamite {
public:
    Dynamite(Vector2f position, Vector2f targetPosition, float speed);
    void update(float deltaTime);
    void draw(RenderWindow& window);
    bool isOutOfScreen(RenderWindow& window);
    bool checkCollision(Player* player); // Check if it hits the player

private:
    Sprite dynamite;
	Texture dynamiteTexture;
    Vector2f velocity;
    bool exploded;
};*/
#endif // ENTITY_HPP