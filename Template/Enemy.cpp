//Enemy : classe gérant les ennemis et leur comportement.
#include <thread>
#include <mutex>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"


// --- Enemy Base Class ---
Enemy::Enemy(Player* p) : currentFrame(0), animationSpeed(0.2f), timeSinceLastFrame(0.0f) , running(false){
    player = p;
}

Enemy::~Enemy() 
{
	stopThread();
}



void Enemy::draw(sf::RenderWindow& window) {
    window.draw(enemy);
}

void Enemy::startThread(RenderWindow& window) {
    running = true;
    enemyThread = thread([this, &window]() {
        while (running) {
            this_thread::sleep_for(chrono::milliseconds(16)); 
            lock_guard<mutex> lock(mtx);
            update(0.016f, window); 
        }
        });
}

void Enemy::stopThread() 
{
    running = false;
    if (enemyThread.joinable()) {
        enemyThread.join();
    }
}
   


