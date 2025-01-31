//Enemy : classe gérant les ennemis et leur comportement.
#include "Enemy.hpp"
#include <stdexcept>

// --- Enemy Base Class ---
Enemy::Enemy() : currentFrame(0), animationSpeed(0.2f), timeSinceLastFrame(0.0f) {}

Enemy::~Enemy() {}

void Enemy::update(float deltaTime) {
    // Handle animation timing
    timeSinceLastFrame += deltaTime;
    if (timeSinceLastFrame >= animationSpeed) {
        timeSinceLastFrame = 0.0f;
        currentFrame = (currentFrame + 1) % frames.size();
        enemy.setTexture(frames[currentFrame]);
    }
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(enemy);
}

// --- TorcheEnemy ---
TorcheEnemy::TorcheEnemy() {
    if (!frames[0].loadFromFile("Images/torche/idle1.png")) {
        throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
    }
    if (!frames[1].loadFromFile("Images/torche/idle2.png")) {
        throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
    }
    if (!frames[2].loadFromFile("Images/torche/idle3.png")) {
        throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
    }
    if (!frames[3].loadFromFile("Images/torche/idle4.png")) {
        throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
    }
    if (!frames[4].loadFromFile("Images/torche/idle5.png")) {
        throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
    }
    if (!frames[5].loadFromFile("Images/torche/idle6.png")) {
        throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
    }
    if (!frames[9].loadFromFile("Images/torche/idle7.png")) {
        throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
    }

    enemy.setTexture(frames[0]);  // Set the first frame initially
    enemy.setPosition(935, 515);

}

TorcheEnemy::~TorcheEnemy() {}

void TorcheEnemy::update(float deltaTime) {
    // Call base class update to handle animation
    Enemy::update(deltaTime);

    // Additional specific behaviors for TorcheEnemy can be added here
}

void TorcheEnemy::draw(sf::RenderWindow& window) {
    Enemy::draw(window);
}
