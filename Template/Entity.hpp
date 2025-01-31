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
    virtual ~Entity();

    // Setters and Getters
    void setPosition(float x, float y);
    Vector2f getPosition() const;

    // Virtual functions for updating and drawing
    virtual void update(float deltaTime);
    virtual void draw(RenderWindow& window);

protected:
    Sprite enemy;
    Texture enemyTexture;
};

#endif // ENTITY_HPP