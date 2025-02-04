//Enemy : classe g�rant les ennemis et leur comportement.
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

void Enemy::stopThread() {
    running = false;
    if (enemyThread.joinable()) {
        enemyThread.join();
    }
}

// --- TorcheEnemy ---
TorcheEnemy::TorcheEnemy(Player* p) : Enemy(p), currentAnimationState(AnimationState::Idle), currentFrame(0),animationSpeed(0.2f),timeSinceLastFrame(0.0f) {
    // Load Idle animation frames

    idleFrames.resize(6);
    for (int i = 0; i < 6; ++i) {
        if (!idleFrames[i].loadFromFile("Images/torche/idle/idle" + to_string(i) + ".png")) {
            throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }

    walkFrames.resize(6); 
    for (int i = 0; i < 5; ++i) {
        if (!walkFrames[i].loadFromFile("Images/torche/walk/walk" + to_string(i + 1) + ".png")) {
            throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }

    attackFrames.resize(6);
     for (int i = 0; i < 5; ++i) {
        if (!attackFrames[i].loadFromFile("Images/torche/atk1/1atk" + to_string(i + 1) + ".png")) {
           throw runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }
    
    attackFrames2.resize(6);
    for (int i = 0; i < 5; ++i) {
        if (!attackFrames2[i].loadFromFile("Images/torche/atk2/2atk" + to_string(i + 1) + ".png")) {
            throw runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }
    
    attackFrames3.resize(6);
    for (int i = 0; i < 5; ++i) {
        if (!attackFrames3[i].loadFromFile("Images/torche/atk3/3atk" + to_string(i + 1) + ".png")) {
           throw runtime_error("Erreur : texture de l'enemy est introuvable.");
       }
    }

    // Set the initial texture (idle frame)
    enemy.setTexture(idleFrames[0]);
    enemy.setPosition(935, 515); // Set position
}

TorcheEnemy::~TorcheEnemy() {}


void TorcheEnemy::update(float deltaTime,RenderWindow& window) {

    timeSinceLastFrame += deltaTime;

    if (timeSinceLastFrame >= animationSpeed) {
        timeSinceLastFrame = 0.0f;
        currentFrame = (currentFrame + 1) % idleFrames.size();
        enemy.setTexture(idleFrames[currentFrame]);
    }

    float distance = sqrt(pow(player->playerSprite->getPosition().x - enemy.getPosition().x, 2) +
        pow(player->playerSprite->getPosition().y - enemy.getPosition().y, 2));

    // Set state based on distance to player
    if (distance > 100.0f) {
        currentAnimationState = AnimationState::Walk;
    }
    else if (distance < 50.0f) {
        currentAnimationState = AnimationState::Attack;
    }
    else {
        currentAnimationState = AnimationState::Idle;
    }

    // Update animation based on state
    switch (currentAnimationState) {
    case AnimationState::Idle:
        // Update idle animation
        break;
    case AnimationState::Walk:
        enemyMove();
        break;
    case AnimationState::Attack:
        attaque(window);
        break;
    }

    Enemy::update(deltaTime,window);
}

void TorcheEnemy::draw(RenderWindow& window) {
    Enemy::draw(window);
}

void TorcheEnemy::enemyMove() {

    float distance = sqrt(pow(player->playerSprite->getPosition().x - enemy.getPosition().x, 2) +
        pow(player->playerSprite->getPosition().y - enemy.getPosition().y, 2));
    if (distance < 200.0f) {
        if (enemy.getPosition().x > player->playerSprite->getPosition().x +20) {
            enemy.move(-1.5f, 0);
        }
        if (enemy.getPosition().x < player->playerSprite->getPosition().x + 20) {
            enemy.move(1.5f, 0);
        }
        if (enemy.getPosition().y > player->playerSprite->getPosition().y + 20) {
            enemy.move(0, -1.5f);
        }
        if (enemy.getPosition().y < player->playerSprite->getPosition().y + 20) {
            enemy.move(0, 1.5f);
        }
    }
}

bool Enemy::checkCollision() const {
    // Get the bounding boxes of both the player and the enemy
    FloatRect boundingBox = player->playerSprite->getGlobalBounds();
    FloatRect otherBox = enemy.getGlobalBounds();
    // Check for intersection
    if (boundingBox.intersects(otherBox)) {
        return true;  // Collision detected
    }
    return false;  // No collision
}

void TorcheEnemy::attaque(RenderWindow& window) {
    float distance = sqrt(pow(player->playerSprite->getPosition().x - enemy.getPosition().x, 2) + pow(player->playerSprite->getPosition().y - enemy.getPosition().y, 2));
    if (distance < 20.0f) {
        // Attack logic here (e.g., reduce player health)
        player->prendDesDegats(window);
        cout << "Player is within attack range!" <<endl;
    }
}