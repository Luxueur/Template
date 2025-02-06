#include "TorcheEnemy2.hpp"

TorcheEnemy::TorcheEnemy(Player* p) : Enemy(p), currentAnimationState(AnimationState::Idle), currentFrame(0), animationSpeed(0.2f), timeSinceLastFrame(0.0f), pv(5) {
    // Load all animation frames using a helper function
    loadTextures();

    // Set the initial texture (idle frame)
    enemy.setTexture(idleFrames[0]);
    enemy.setPosition(935, 515); // Set position
}

TorcheEnemy::~TorcheEnemy() {}

void TorcheEnemy::loadTextures() {
    // Load Idle animation frames
    idleFrames = loadAnimationFrames("Images/torche/idle/idle", 6);
    walkFrames = loadAnimationFrames("Images/torche/walk/walk", 6);
    attackFrames = loadAnimationFrames("Images/torche/atk1/1atk", 5);
    attackFrames2 = loadAnimationFrames("Images/torche/atk2/2atk", 5);
    attackFrames3 = loadAnimationFrames("Images/torche/atk3/3atk", 5);
    deathFrames = loadAnimationFrames("Images/Deco/14.png", 1);
}

vector<Texture> TorcheEnemy::loadAnimationFrames(const string& basePath, int numFrames) {

    vector<Texture> idleFrames(6);
    for (int i = 0; i < 6; ++i) {
        if (!idleFrames[i].loadFromFile("Images/torche/idle/idle" + to_string(i + 1) + ".png")) {
            throw runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }
    return idleFrames;

    vector<Texture> walkFrames(6);
    for (int i = 0; i < 6; ++i) {
        if (!walkFrames[i].loadFromFile("Images/torche/walk/walk" + to_string(i + 1) + ".png")) {
            throw runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }
    return walkFrames;

    vector<Texture> attackFrames(5);
    for (int i = 0; i < 5; ++i) {
        if (!attackFrames[i].loadFromFile("Images/torche/atk1/1atk" + to_string(i + 1) + ".png")) {
            throw runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }
    return attackFrames;

    vector<Texture> attackFrames2(5);
    for (int i = 0; i < 5; ++i) {
        if (!attackFrames2[i].loadFromFile("Images/torche/atk2/2atk" + to_string(i + 1) + ".png")) {
            throw runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }
    return attackFrames2;

    vector<Texture> attackFrames3(5);
    for (int i = 0; i < 5; ++i) {
        if (!attackFrames3[i].loadFromFile("Images/torche/atk3/3atk" + to_string(i + 1) + ".png")) {
            throw runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }
    return attackFrames3;

    vector<Texture> deathFrames(5);
    for (int i = 0; i < 5; ++i) {
        if (!deathFrames[i].loadFromFile("Images/Deco/14.png")){
            throw runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }
    return deathFrames;

}

void TorcheEnemy::update(float deltaTime, RenderWindow& window) {
    timeSinceLastFrame += deltaTime;
    if (timeSinceLastFrame >= animationSpeed) {
        timeSinceLastFrame = 0.0f;
        currentFrame = (currentFrame + 1) % getCurrentAnimationFrames().size();
        enemy.setTexture(getCurrentAnimationFrames()[currentFrame]);
    }

    float distance = sqrt(pow(player->playerSprite->getPosition().x - enemy.getPosition().x, 2) +
        pow(player->playerSprite->getPosition().y - enemy.getPosition().y, 2));

    // Set state based on distance to player
    if (pv <= 0) {
        currentAnimationState = AnimationState::Dead;
    }
    else if (distance > 100.0f) {
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
        break;
    case AnimationState::Walk:
        enemyMove();
        break;
    case AnimationState::Attack:
        attaque(window);
        break;
    case AnimationState::Dead:
        enemy.setTexture(deathFrames[currentFrame]);
        break;
    }

    Enemy::update(deltaTime, window);
}

vector<Texture>& TorcheEnemy::getCurrentAnimationFrames() {
    switch (currentAnimationState) {
    case AnimationState::Idle:
        return idleFrames;
    case AnimationState::Walk:
        return walkFrames;
    case AnimationState::Attack:
        return attackFrames; 
    case AnimationState::Dead:
        return deathFrames;
    default:
        return idleFrames;
    }
}

void TorcheEnemy::draw(RenderWindow& window) {
    Enemy::draw(window);
}

// Movement logic for the enemy
void TorcheEnemy::enemyMove() {
    Vector2f direction = player->playerSprite->getPosition() - enemy.getPosition();
    float distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

    if (distance < 200.0f) {
        direction /= distance; // Normalize the vector
        enemy.move(direction * 1.f); // Move towards the player
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
        }
    }
}
