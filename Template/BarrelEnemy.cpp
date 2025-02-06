#include "Enemy.hpp"
// --- BarrelEnemy ---
BarrelEnemy::BarrelEnemy(Player* p)
    : Enemy(p), currentAnimationState(AnimationState::Idle), currentFrame(0), animationSpeed(0.2f), timeSinceLastFrame(0.0f) {

    loadTextures();

    enemy.setTexture(idleFrames[0]);
    enemy.setPosition(800, 515); // Set position of the barrel enemy
}

BarrelEnemy::~BarrelEnemy() {}

vector<Texture> BarrelEnemy::loadAnimationFrames(const string& basePath, int numFrames) {

    vector<Texture> idleFrames(8);
    for (int i = 0; i < 8; ++i) {
        if (!idleFrames[i].loadFromFile("Images/barrel/idle1/idle" + to_string(i) + ".png")) {
            throw runtime_error("Erreur : texture de l'enemy est introuvable.");
            cout << "Loading texture from: " << "Images/barrel/idle1/idle" + to_string(i) + ".png" << endl;

        }
		idleFrames.push_back(idleFrames[i]);
    }
    return idleFrames;

    vector<Texture> caughtFrames(10);
    for (int i = 0; i < 10; ++i) {
        if (!caughtFrames[i].loadFromFile("Images/barrel/idle2/idle" + to_string(i) + ".png")) {
            throw runtime_error("Erreur : texture de l'enemy est introuvable.");
            cout << "Loading texture from: " << "Images/barrel/idle2/idle" + to_string(i) + ".png" << endl;

        }
		caughtFrames.push_back(caughtFrames[i]);
    }
    return caughtFrames;

    vector<Texture> damageFrames(12);
    for (int i = 0; i < 12; ++i) {
        if (!damageFrames[i].loadFromFile("Images/barrel/explode/soon" + to_string(i) + ".png")) {
            throw runtime_error("Erreur : texture de l'enemy est introuvable.");
            cout << "Loading texture from: " << "Images/barrel/explode/soon" + to_string(i) + ".png" << endl;

        }
		damageFrames.push_back(damageFrames[i]);
    }
    return damageFrames;
}

void BarrelEnemy::loadTextures() {
    // Load idle frames
    idleFrames = loadAnimationFrames("Images/barrel/idle1/idle", 8);
    caughtFrames = loadAnimationFrames("Images/barrel/idle2/idle", 10);
    damageFrames = loadAnimationFrames("Images/barrel/explode/soon", 12);
}

void BarrelEnemy::update(float deltaTime, RenderWindow& window) {
    timeSinceLastFrame += deltaTime;

    // Update the animation frame based on the current state
    if (timeSinceLastFrame >= animationSpeed) {
        timeSinceLastFrame = 0.0f;
        currentFrame = (currentFrame + 1) % getCurrentAnimationFrames().size();
        enemy.setTexture(getCurrentAnimationFrames()[currentFrame]);
    }


    // Calculate distance to the player
    float distance = sqrt(pow(player->playerSprite->getPosition().x - enemy.getPosition().x, 2) +
        pow(player->playerSprite->getPosition().y - enemy.getPosition().y, 2));

    // Update animation state based on the distance to the player
    if (distance < 50.0f) {  // Or a different range
        currentAnimationState = AnimationState::Caught;
    }
    else if (distance > 10.0f) {
        currentAnimationState = AnimationState::Idle;
    }

    // Handle the animation state
    switch (currentAnimationState) {
    case AnimationState::Idle:
        break;
    case AnimationState::Caught:
        break;
    case AnimationState::Explode:
        attaque(window);
        break;
    }

    // Update base class logic (if any)
    Enemy::update(deltaTime, window);
}


void BarrelEnemy::draw(RenderWindow& window) {
    Enemy::draw(window);  // Calls the draw function of the parent class
}

void BarrelEnemy::attaque(RenderWindow& window) {
    // Check the distance between the player and this enemy
    float distance = sqrt(pow(player->playerSprite->getPosition().x - enemy.getPosition().x, 2) +
        pow(player->playerSprite->getPosition().y - enemy.getPosition().y, 2));

    // If the player is within attack range, deal damage
    if (distance < 10.0f) {
        player->prendDesDegats(window);  // Apply damage to the player
        cout << "Player is within attack range!" << endl;
        // Change to Explode state after the attack
        currentAnimationState = AnimationState::Explode;
    }
}


vector<Texture>& BarrelEnemy::getCurrentAnimationFrames() {
    switch (currentAnimationState) {
    case AnimationState::Idle:
        return idleFrames;
    case AnimationState::Caught:
        return caughtFrames; 
    case AnimationState::Explode:
        return damageFrames;  
    default:
        return idleFrames;  
    }
}

