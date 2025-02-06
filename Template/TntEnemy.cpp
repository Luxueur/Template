#include "Enemy.hpp"

TNTEnemy::TNTEnemy(Player* p)
    : Enemy(p), throwCooldown(2.0f), currentAnimationState(AnimationState::Idle),
    currentFrame(0), animationSpeed(0.2f), timeSinceLastFrame(0.0f) {
    loadTextures();
}

TNTEnemy::~TNTEnemy() {
    // Clean up any remaining dynamites
    for (auto& dynamite : dynamites) {
        delete dynamite;
    }
}

vector<Texture> TNTEnemy::loadAnimationFrames(const string& basePath, int numFrames) {
    vector<Texture> frames;
    for (int i = 0; i < numFrames; ++i) {
        Texture texture;
        if (!texture.loadFromFile(basePath + to_string(i + 1) + ".png")) {
            throw runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
        frames.push_back(texture);
    }
    return frames;
}

void TNTEnemy::loadTextures() {
    idleFrames = loadAnimationFrames("Images/tnt/idle/idle", 6);
    throwFrames = loadAnimationFrames("Images/tnt/atk/atk", 7);
    walkFrames = loadAnimationFrames("Images/tnt/walk/walk", 6);
}

vector<Texture>& TNTEnemy::getCurrentAnimationFrames() {
    switch (currentAnimationState) {
    case AnimationState::Idle:
        return idleFrames;
    case AnimationState::Attack:
        return throwFrames;
    case AnimationState::Walk:
        return walkFrames;
    default:
        return idleFrames;
    }
}

void TNTEnemy::update(float deltaTime, RenderWindow& window) {
    timeSinceLastFrame += deltaTime;

    // Update the animation frame based on the current state
    if (timeSinceLastFrame >= animationSpeed) {
        timeSinceLastFrame = 0.0f;
        currentFrame = (currentFrame + 1) % getCurrentAnimationFrames().size();
        enemy.setTexture(getCurrentAnimationFrames()[currentFrame]);
    }

    // Throw dynamite if cooldown is over
    throwCooldown -= deltaTime;
    if (throwCooldown <= 0.0f) {
        throwDynamite();
        throwCooldown = 2.0f; // Reset cooldown
    }

    // Update dynamites
    for (auto& dynamite : dynamites) {
        dynamite->update(deltaTime);
        if (dynamite->checkCollision(player)) {
            // Handle player getting hit by dynamite
            player->prendDesDegats(window);
        }
    }

    // Remove dynamites that are out of screen
    dynamites.erase(remove_if(dynamites.begin(), dynamites.end(),
        [&window](Dynamite* dynamite) { return dynamite->isOutOfScreen(window); }), dynamites.end());
}

void TNTEnemy::draw(RenderWindow& window) {
    Enemy::draw(window);  // Draw the TNT enemy

    // Draw all dynamites
    for (auto& dynamite : dynamites) {
        dynamite->draw(window);
    }
}

void TNTEnemy::attaque(RenderWindow& window) {
    // You can also trigger the attack here (if you want to use this method for throwing dynamite)
    throwDynamite();
}

void TNTEnemy::throwDynamite() {
    // Calculate where to throw the dynamite (towards the player's current position)
    Vector2f dynamitePosition = enemy.getPosition();
    Vector2f targetPosition = player->playerSprite->getPosition();
    dynamites.push_back(new Dynamite(dynamitePosition, targetPosition, 200.0f)); // 200.0f is the speed
}