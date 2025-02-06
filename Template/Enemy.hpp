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

<<<<<<< Updated upstream
    void startThread(RenderWindow& window);
    void stopThread();

private:
    // To hold the animation frames (textures)
    vector<Texture> idleFrames;  // Idle animation frames
=======
protected:
    // To hold the animation frames (textures)
  /* vector<Texture> frames;*/
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

protected:
    // Vectors to hold animation frames for each type
    std::vector<sf::Texture> idleFrames;  // Idle animation frames
    std::vector<sf::Texture> walkFrames;  // Walk animation frames
    std::vector<sf::Texture> attackFrames; // Attack animation frames
>>>>>>> Stashed changes

    int currentFrame;
    float animationSpeed;
    float timeSinceLastFrame;
    thread enemyThread;
    bool running;
    mutex mtx;

};

#endif // ENEMY_HPP