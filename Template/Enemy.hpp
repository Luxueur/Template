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
#include <string>

using namespace sf;
using namespace std;



class Enemy : public Entity {
public:
    Player* player;
    Enemy(Player* p);
    ~Enemy(); 

    //bool checkCollision() const;

    //virtual void update(float deltaTime,RenderWindow& window) override;
    virtual void draw(RenderWindow& window) override;
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

#endif // ENEMY_HPP