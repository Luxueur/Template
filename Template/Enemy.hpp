//Enemy : classe gérant les ennemis et leur comportement.
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;

class Enemy : public Entity {
public:
    Enemy();
    virtual ~Enemy();

    virtual void update(float deltaTime) override;
    virtual void draw(RenderWindow& window) override;

protected:
    // To hold the animation frames (textures)
    std::vector<sf::Texture> frames;
    int currentFrame;
    float animationSpeed;  // How fast the animation plays
    float timeSinceLastFrame;
};

class TorcheEnemy : public Enemy {
public:
    TorcheEnemy();
    ~TorcheEnemy();

    void update(float deltaTime) override;
    void draw(RenderWindow& window) override;
};

#endif // ENEMY_HPP



