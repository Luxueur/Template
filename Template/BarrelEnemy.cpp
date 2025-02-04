#include "Enemy.hpp"
// --- BarrelEnemy ---

BarrelEnemy::BarrelEnemy(Player* p) : Enemy(p), currentAnimationState(AnimationState::Idle), currentFrame(0), animationSpeed(0.2f), timeSinceLastFrame(0.0f){

    idleFrames.resize(6);
    for (int i = 0; i < 6; ++i) {
        if (!idleFrames[i].loadFromFile("Images/barrel/idle1/idle" + to_string(i) + ".png")) {
            throw std::runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }

    // Set the initial texture (idle frame)
    enemy.setTexture(idleFrames[0]);
    enemy.setPosition(800, 515); // Set position

}
BarrelEnemy::~BarrelEnemy() {}


void BarrelEnemy::update(float deltaTime, RenderWindow& window) {
    timeSinceLastFrame += deltaTime;

    if (timeSinceLastFrame >= animationSpeed) {
        timeSinceLastFrame = 0.0f;
        currentFrame = (currentFrame + 1) % idleFrames.size();
        enemy.setTexture(idleFrames[currentFrame]);
    }

    // Update animation based on state
    switch (currentAnimationState) {
    case AnimationState::Idle:
        // Update idle animation
        break;
    case AnimationState::Attack:
        attaque(window);
        break;
    }

}

void BarrelEnemy::draw(RenderWindow& window) {
    Enemy::draw(window);
}

void BarrelEnemy::attaque(RenderWindow& window) {

}