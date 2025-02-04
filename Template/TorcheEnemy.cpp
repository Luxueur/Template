#include "Enemy.hpp"

// Constructor
TorcheEnemy::TorcheEnemy(Player* p)
    : Enemy(p), currentAnimationState(AnimationState::Idle), currentFrame(0), animationSpeed(0.2f), timeSinceLastFrame(0.0f), pv(3) { // Example health points
    // Load all animations using helper function
    loadTexturesForAnimation(idleFrames, "Images/torche/idle/idle", 6);
    loadTexturesForAnimation(walkFrames, "Images/torche/walk/walk", 6);
    loadTexturesForAnimation(attackFrames, "Images/torche/atk1/1atk", 5);
    loadTexturesForAnimation(attackFrames2, "Images/torche/atk2/2atk", 5);
    loadTexturesForAnimation(attackFrames3, "Images/torche/atk3/3atk", 5);

    // Set initial texture and position
    enemy.setTexture(idleFrames[0]);
    enemy.setPosition(935, 515); // Example initial position
}

// Destructor
TorcheEnemy::~TorcheEnemy() {
    // Any necessary cleanup goes here
}

// Helper function to load textures for a given animation
void TorcheEnemy::loadTexturesForAnimation(vector<Texture>& textureVector, const string& folder, int frameCount) {
    textureVector.resize(frameCount);
    for (int i = 0; i < frameCount; ++i) {
        if (!textureVector[i].loadFromFile(folder + to_string(i) + ".png")) {
            throw runtime_error("Erreur : texture de l'enemy est introuvable : " + folder + to_string(i) + ".png");
        }
    }
}

// Update method for handling enemy state and animation updates
void TorcheEnemy::update(float deltaTime, RenderWindow& window) {
    timeSinceLastFrame += deltaTime;

    // Update animation frame if enough time has passed
    if (timeSinceLastFrame >= animationSpeed) {
        timeSinceLastFrame = 0.0f;
        currentFrame = (currentFrame + 1) % idleFrames.size();
        // Update texture based on current frame
        switch (currentAnimationState) {
        case AnimationState::Idle:
            enemy.setTexture(idleFrames[currentFrame]);
            break;
        case AnimationState::Walk:
            enemy.setTexture(walkFrames[currentFrame]);
            break;
        case AnimationState::Attack:
            // Use attack animation depending on the type of attack
            if (currentFrame < attackFrames.size()) {
                enemy.setTexture(attackFrames[currentFrame]);
            }
            break;
        case AnimationState::Dead:
            // Handle death animation if needed (optional)
            break;
        }
    }

    // Handle enemy state based on the player's position
    float distance = sqrt(pow(player->playerSprite->getPosition().x - enemy.getPosition().x, 2) +
        pow(player->playerSprite->getPosition().y - enemy.getPosition().y, 2));

    // Set the state based on distance to player
    if (distance > 100.0f) {
        currentAnimationState = AnimationState::Walk;
    }
    else if (distance < 50.0f) {
        currentAnimationState = AnimationState::Attack;
    }
    else {
        currentAnimationState = AnimationState::Idle;
    }

    // Update behavior based on animation state
    switch (currentAnimationState) {
    case AnimationState::Idle:
        break;
    case AnimationState::Walk:
        enemyMove();
        break;
    case AnimationState::Attack:
        attaque(window);
        break;
    case AnimationState::Dead:
        // Optionally handle death state (stop moving, play death animation, etc.)
        break;
    }

    Enemy::update(deltaTime, window);{}
}

void TorcheEnemy::draw(RenderWindow& window) {
    Enemy::draw(window);
}

// Movement logic for the enemy
void TorcheEnemy::enemyMove() {
    float distance = sqrt(pow(player->playerSprite->getPosition().x - enemy.getPosition().x, 2) +
        pow(player->playerSprite->getPosition().y - enemy.getPosition().y, 2));

    if (distance < 200.0f) { // Move towards player if within range
        if (enemy.getPosition().x > player->playerSprite->getPosition().x + 20) {
            enemy.move(-1.f, 0); 
        }
        if (enemy.getPosition().x < player->playerSprite->getPosition().x + 20) {
            enemy.move(1.f, 0);
        }
        if (enemy.getPosition().y > player->playerSprite->getPosition().y + 20) {
            enemy.move(0, -1.f); 
        }
        if (enemy.getPosition().y < player->playerSprite->getPosition().y + 20) {
            enemy.move(0, 1.f); 
        }
    }
}

// Attack logic when the player is within attack range
void TorcheEnemy::attaque(RenderWindow& window) {
    float distance = sqrt(pow(player->playerSprite->getPosition().x - enemy.getPosition().x, 2) +
        pow(player->playerSprite->getPosition().y - enemy.getPosition().y, 2));

    if (distance < 20.0f) {
        player->prendDesDegats(window);
        cout << "Player is within attack range!" << endl;
    }
}

// Method for taking damage and updating health
void TorcheEnemy::prendDesDegats(RenderWindow& window) {
    if (pv > 0) {
        --pv;
        cout << "Pv après avoir pris les dégâts : " << pv << endl;
        if (pv <= 0) {
            currentAnimationState = AnimationState::Dead;
            // Optionally set a death animation or perform any necessary cleanup
            // enemy.setTexture(deathTexture); // You could implement a death animation here
        }
    }
}
