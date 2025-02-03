//Enemy : classe gérant les ennemis et leur comportement.
#include "Enemy.hpp"

// --- Enemy Base Class ---
Enemy::Enemy(Player* p) : currentFrame(0), animationSpeed(0.2f), timeSinceLastFrame(0.0f) {
    player = p;
}

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
TorcheEnemy::TorcheEnemy(Player* p) : Enemy(p) {
    frames.resize(7); 
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
    if (!frames[6].loadFromFile("Images/torche/idle7.png")) {
        throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
    }

    enemy.setTexture(frames[0]);
    enemy.setPosition(935, 515);

}

TorcheEnemy::~TorcheEnemy() {}

void TorcheEnemy::update(float deltaTime) {
    Enemy::update(deltaTime);
}

void TorcheEnemy::draw(RenderWindow& window) {
    Enemy::draw(window);
}

void TorcheEnemy::enemyMove() {
    if (player->playerSprite->getPosition().x > enemy.getPosition().x + 100 ||
        player->playerSprite->getPosition().x > enemy.getPosition().y + 100 || 
        player->playerSprite->getPosition().y > enemy.getPosition().x + 100 ||
        player->playerSprite->getPosition().y > enemy.getPosition().y + 100) {

        if (enemy.getPosition().x > player->playerSprite->getPosition().x) {
            enemy.move(-1.5f, 0);
        }
        if (enemy.getPosition().x < player->playerSprite->getPosition().x) {
            enemy.move(1.5f, 0);
        }
        if (enemy.getPosition().y > player->playerSprite->getPosition().y) {
            enemy.move(0, -1.5f);
        }
        if (enemy.getPosition().y < player->playerSprite->getPosition().y) {
            enemy.move(0, 1.5f);
        }
    }
    
}


void TorcheEnemy::animation() {

}