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
    
    bool checkCollision() const;

    //virtual void update(float deltaTime,RenderWindow& window) override;
    virtual void draw(RenderWindow& window) override;

    virtual void enemyMove() = 0;
    virtual void attaque(RenderWindow& window) = 0;
 
protected:
    // To hold the animation frames (textures)
    vector<Texture> idleFrames;  // Idle animation frames

    int currentFrame;
    float animationSpeed;
    float timeSinceLastFrame;

};

class TorcheEnemy : public Enemy {
public:
    TorcheEnemy(Player* p);
    ~TorcheEnemy();

    void update(float deltaTime,RenderWindow& window) override;
    void draw(RenderWindow& window) override;
    void enemyMove() override;
    void attaque(RenderWindow& window) override;

private:
    // Vectors to hold animation frames for each type
    vector<Texture> idleFrames;  // Idle animation frames
    vector<Texture> walkFrames;  // Walk animation frames
    vector<Texture> attackFrames; // Attack animation frames
    vector<Texture> attackFrames2; // Attack animation frames
    vector<Texture> attackFrames3; // Attack animation frames

    // A variable to track which animation to use
    enum class AnimationState { Idle, Walk, Attack };
    AnimationState currentAnimationState;
    
    int currentFrame;
    float animationSpeed;
    float timeSinceLastFrame;
};


#endif // ENEMY_HPP



