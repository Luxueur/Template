#include "TntEnemy.hpp"

TNTEnemy::TNTEnemy(Player* p)
    : Enemy(p), throwCooldown(2.0f), currentAnimationState(AnimationState2::Idle),
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

    vector<Texture> idleFrames(6);
    for (int i = 0; i < 6; ++i) {
        string filename = "Images/tnt/idle/idle" + to_string(i + 1) + ".png";
        if (!idleFrames[i].loadFromFile(filename)) {
            throw runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }
    return idleFrames;

    vector<Texture> attackFrames(7);
    for (int i = 0; i < 7; ++i) {
        string filename2 = "Images/tnt/atk/atk1" + to_string(i + 1) + ".png";
        if (!attackFrames[i].loadFromFile(filename2)) {
            throw runtime_error("Erreur : texture de l'enemy est introuvable.");
        }
    }
    return attackFrames;
}

void TNTEnemy::loadTextures() {
    idleFrames = loadAnimationFrames("Images/tnt/idle/idle", 6);
    throwFrames = loadAnimationFrames("Images/tnt/atk/atk", 7);
    textureOs.loadFromFile("Images/Deco/os.png");
}


vector<Texture>& TNTEnemy::getCurrentAnimationFrames() {
    switch (currentAnimationState) {
    case AnimationState2::Idle:
        return idleFrames;
    case AnimationState2::Attack:
        return throwFrames;
    case AnimationState2::Dead:
        return throwFrames;
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

    // Update animation based on state
    switch (currentAnimationState) {
    case AnimationState2::Idle:
        break;
    case AnimationState2::Attack:
        attaque(window);
        break;
    case AnimationState2::Dead:
        enemy.setTexture(textureOs);
        break;
    }
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