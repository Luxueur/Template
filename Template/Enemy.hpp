//Enemy : classe gérant les ennemis et leur comportement.
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"
#include "Player.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <thread> 
#include <mutex>  

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
    virtual void loadTextures() = 0;
    virtual void attaque(RenderWindow& window) = 0;

    void startThread(RenderWindow& window);
    void stopThread();
 
private:
    // To hold the animation frames (textures)
    vector<Texture> idleFrames;  // Idle animation frames

    int currentFrame;
    float animationSpeed;
    float timeSinceLastFrame;
    thread enemyThread;
    bool running;
    mutex mtx;

};

class TorcheEnemy : public Enemy {
public:
    // Constructor and Destructor
    TorcheEnemy(Player* p);
    ~TorcheEnemy();

    void update(float deltaTime, RenderWindow& window) override;
    void draw(RenderWindow& window) override;
	//void loadTextures() override; 
    void enemyMove();
    void attaque(RenderWindow& window) override;
    void prendDesDegats(RenderWindow& window);

private:
    void loadTexturesForAnimation(vector<Texture>& textureVector, const string& folder, int frameCount);

    vector<Texture> idleFrames;
    vector<Texture> walkFrames;
    vector<Texture> attackFrames;
    vector<Texture> attackFrames2;
    vector<Texture> attackFrames3;

    enum class AnimationState { Idle, Walk, Attack, Dead };
    AnimationState currentAnimationState;

    int pv;
    int currentFrame;
    float animationSpeed;
    float timeSinceLastFrame;
};


class BarrelEnemy : public Enemy{
public:
    BarrelEnemy(Player* p);
    ~BarrelEnemy();

    void update(float deltaTime, RenderWindow& window) override;
    void draw(RenderWindow& window) override;
    void attaque(RenderWindow& window) override;
private:
    // Vectors to hold animation frames for each type
    vector<Texture> idleFrames;  // Idle animation frames
    vector<Texture> attackFrames;
    // A variable to track which animation to use
    enum class AnimationState { Idle, Attack };
    AnimationState currentAnimationState;

    int currentFrame;
    float animationSpeed;
    float timeSinceLastFrame;
};



#endif // ENEMY_HPP