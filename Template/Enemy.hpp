//Enemy : classe gérant les ennemis et leur comportement.
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"
#include "Player.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace sf;
using namespace std;

class Enemy : public Entity {
public:
    Player* player;
    Enemy(Player* p);
    ~Enemy();
    
    //bool checkCollision() const;

    virtual void update(float deltaTime) override;
    virtual void draw(RenderWindow& window) override;

    virtual void enemyMove() = 0;
    virtual void attaque() = 0;

protected:
    // To hold the animation frames (textures)
    vector<Texture> frames;
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
    void attaque() override;

private:
    // Vectors to hold animation frames for each type
    std::vector<sf::Texture> idleFrames;  // Idle animation frames
    std::vector<sf::Texture> walkFrames;  // Walk animation frames
    std::vector<sf::Texture> attackFrames; // Attack animation frames

    // A variable to track which animation to use
    enum class AnimationState { Idle, Walk, Attack };
    AnimationState currentAnimationState;
    
    int currentFrame;
    float animationSpeed;
    float timeSinceLastFrame;
};


#endif // ENEMY_HPP



