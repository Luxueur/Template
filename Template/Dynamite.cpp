#include "TntEnemy.hpp"

Dynamite::Dynamite(Vector2f position, Vector2f target, float speed) {
    // Load the texture for the dynamite
    if (!dynamiteTexture.loadFromFile("Images/dynamite.png")) {
        throw runtime_error("Erreur : texture de la dynamite est introuvable.");
    }
    dynamiteSprite.setTexture(dynamiteTexture);
    dynamiteSprite.setPosition(position);

    // Calculate the velocity
    Vector2f direction = target - position;
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    velocity = direction / length * speed;

    exploded = false;
}

Dynamite::~Dynamite() {
    // Destructor logic if needed
}

void Dynamite::update(float deltaTime) {
    if (!exploded) {
        dynamiteSprite.move(velocity * deltaTime);
    }
}

void Dynamite::draw(RenderWindow& window) {
    if (!exploded) {
        window.draw(dynamiteSprite);
    }
}

bool Dynamite::checkCollision(Player* player) {
    if (dynamiteSprite.getGlobalBounds().intersects(player->playerSprite->getGlobalBounds())) {
        exploded = true;
        return true;
    }
    return false;
}

bool Dynamite::isOutOfScreen(RenderWindow& window) {
    FloatRect bounds = dynamiteSprite.getGlobalBounds();
    FloatRect screenBounds(0.f, 0.f, static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y));
    return !screenBounds.intersects(bounds);
}