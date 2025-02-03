//Enemy : classe gérant les ennemis et leur comportement.
#include "Enemy.hpp"

// --- Enemy Base Class ---
Enemy::Enemy(Player* p) : currentFrame(0), animationSpeed(0.2f), timeSinceLastFrame(0.0f){
    player = p;
}

Enemy::~Enemy() {}

void Enemy::update(float deltaTime) {
    // Handle animation timing
    //timeSinceLastFrame += deltaTime;

    //    if (timeSinceLastFrame >= animationSpeed) {
    //        timeSinceLastFrame = 0.0f;
    //        currentFrame = (currentFrame + 1) % frames.size();
    //        enemy.setTexture(frames[currentFrame]);
    //    }
    
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(enemy);
}

// --- TorcheEnemy ---
TorcheEnemy::TorcheEnemy(Player* p) : Enemy(p), currentAnimationState(AnimationState::Idle) {
    // Load Idle animation frames

    //idleFrames.resize(6);
    //for (int i = 0; i < 6; ++i) {
    //    if (!idleFrames[i].loadFromFile("Images/torche/idle" + std::to_string(i) + ".png")) {
    //        throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
    //    }
    //}

    //walkFrames.resize(6); 
    //for (int i = 0; i < 6; ++i) {
    //    if (!walkFrames[i].loadFromFile("Images/torche/walk" + std::to_string(i + 1) + ".png")) {
    //        throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
    //    }
    //}

    //attackFrames.resize(6);
    //for (int i = 0; i < 6; ++i) {
    //    if (!attackFrames[i].loadFromFile("Images/torche/atk1" + std::to_string(i + 1) + ".png")) {
    //        throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
    //    }
    //}
    ///*
    //attack2Frames.resize(6);
    //for (int i = 0; i < 6; ++i) {
    //    if (!attack2Frames[i].loadFromFile("Images/torche/atk2" + std::to_string(i + 1) + ".png")) {
    //        throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
    //    }
    //}
    //
    //attack3Frames.resize(6);
    //for (int i = 0; i < 6; ++i) {
    //    if (!attack3Frames[i].loadFromFile("Images/torche/atk3" + std::to_string(i + 1) + ".png")) {
    //        throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
    //    }
    //}*/

    //// Set the initial texture (idle frame)
    //enemy.setTexture(idleFrames[0]);
    //enemy.setPosition(935, 515); // Set position
}

TorcheEnemy::~TorcheEnemy() {}


void TorcheEnemy::update(float deltaTime) {
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
        attaque();
        break;
    }

    Enemy::update(deltaTime);
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

/*bool Enemy::checkCollision() const {
    // Get the bounding boxes of both the player and the enemy
    sf::FloatRect boundingBox = player->playerSprite->getGlobalBounds();
    sf::FloatRect otherBox = enemy.getGlobalBounds();
    // Check for intersection
    if (boundingBox.intersects(otherBox)) {
        return true;  // Collision detected
    }
    return false;  // No collision
}*/

void TorcheEnemy::attaque() {
    float distance = sqrt(pow(player->playerSprite->getPosition().x - enemy.getPosition().x, 2) + pow(player->playerSprite->getPosition().y - enemy.getPosition().y, 2));
    if (distance < 20.0f) {
        // Attack logic here (e.g., reduce player health)
        //player->prendDesDegats();
        cout << "Player is within attack range!" << std::endl;
    }
}