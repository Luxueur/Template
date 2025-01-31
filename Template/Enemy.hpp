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
    Player* player;
    Enemy(Player* p);
    virtual ~Enemy();

    virtual void update(float deltaTime) override;
    virtual void draw(RenderWindow& window) override;


    virtual void enemyMove() = 0;

protected:
    // To hold the animation frames (textures)
    std::vector<sf::Texture> frames;
    int currentFrame;
    float animationSpeed;
    float timeSinceLastFrame;
};

class TorcheEnemy : public Enemy {
public:
    TorcheEnemy(Player* p);
    ~TorcheEnemy();

    void update(float deltaTime) override;
    void draw(RenderWindow& window) override;
    void enemyMove() override;
};

#endif // ENEMY_HPP



