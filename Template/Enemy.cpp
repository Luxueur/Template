// Enemy : classe gérant les ennemis et leur comportement.
#include <thread>
#include <mutex>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"

// --- Enemy Base Class ---
Enemy::Enemy(Player* p) : currentFrame(0), animationSpeed(0.2f), timeSinceLastFrame(0.0f), running(false) {
    player = p;
    
}

<<<<<<< Updated upstream
Enemy::~Enemy() {
    stopThread();
=======
Enemy::~Enemy() {}

void Enemy::update(float deltaTime,RenderWindow& window) {
   // Handle animation timing
   //timeSinceLastFrame += deltaTime;

   //     if (timeSinceLastFrame >= animationSpeed) {
   //         timeSinceLastFrame = 0.0f;
   //         currentFrame = (currentFrame + 1) % Frames.size();
   //         enemy.setTexture(idleFrames[currentFrame]);
   //     }
    
>>>>>>> Stashed changes
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(enemy); 
}

<<<<<<< Updated upstream
void Enemy::startThread(sf::RenderWindow& window) {
    running = true;
    enemyThread = std::thread([this, &window]() {
        while (running) {
            std::this_thread::sleep_for(std::chrono::milliseconds(16));
            std::lock_guard<std::mutex> lock(mtx);
            update(0.016f, window);
=======
// --- TorcheEnemy ---
TorcheEnemy::TorcheEnemy(Player* p) : Enemy(p), currentAnimationState(AnimationState::Idle), currentFrame(0),animationSpeed(0.2f),timeSinceLastFrame(0.0f) {
    // Load Idle animation frames

    idleFrames.resize(6);
    for (int i = 0; i < 5; ++i) {
        if (!idleFrames[i].loadFromFile("Images/torche/idle/idle" + std::to_string(i) + ".png")) {
            throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }

    walkFrames.resize(6); 
    for (int i = 0; i < 5; ++i) {
        if (!walkFrames[i].loadFromFile("Images/torche/walk/walk" + std::to_string(i + 1) + ".png")) {
            throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }

    attackFrames.resize(6);
     for (int i = 0; i < 5; ++i) {
        if (!attackFrames[i].loadFromFile("Images/torche/atk1/1atk" + std::to_string(i + 1) + ".png")) {
           throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }
    
    attackFrames.resize(6);
    for (int i = 0; i < 5; ++i) {
        if (!attackFrames[i].loadFromFile("Images/torche/atk2/2atk" + std::to_string(i + 1) + ".png")) {
            throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }
    
    attackFrames.resize(6);
    for (int i = 0; i < 5; ++i) {
        if (!attackFrames[i].loadFromFile("Images/torche/atk3/3atk" + std::to_string(i + 1) + ".png")) {
           throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
       }
    }

    // Set the initial texture (idle frame)
    enemy.setTexture(idleFrames[0]);
    enemy.setPosition(935, 515); // Set position
}

TorcheEnemy::~TorcheEnemy() {}


void TorcheEnemy::update(float deltaTime,RenderWindow& window) {
    float distance = std::sqrt(std::pow(player->playerSprite->getPosition().x - enemy.getPosition().x, 2) +
        std::pow(player->playerSprite->getPosition().y - enemy.getPosition().y, 2));

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
>>>>>>> Stashed changes
        }
    });
}

void Enemy::stopThread() {
    running = false;
    if (enemyThread.joinable()) {
        enemyThread.join();
    }
}