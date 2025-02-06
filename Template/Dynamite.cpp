/*#include "Entity.hpp"
Dynamite::Dynamite(Vector2f position, Vector2f targetPosition, float speed)
    : exploded(false) {
    // Set dynamite sprite and position
    if (!dynamiteTexture.loadFromFile("path_to_dynamite_image.png")) {
        throw std::runtime_error("Failed to load dynamite texture");
    }
    dynamite.setTexture(dynamiteTexture);
    dynamite.setPosition(position);

    // Calculate velocity based on target (player's position)
    Vector2f direction = targetPosition - position;
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    direction /= length; // Normalize direction vector
    velocity = direction * speed;
}

void Dynamite::update(float deltaTime) {
    if (exploded) return; // Stop moving if it exploded

    dynamite.move(velocity * deltaTime);  // Move dynamite
}

void Dynamite::draw(RenderWindow& window) {
    if (exploded) return;

    window.draw(dynamite);  // Draw dynamite
}



bool Dynamite::checkCollision(Player* player) {
    // Collision check between dynamite and player
    if (dynamite.getGlobalBounds().intersects(player->playerSprite->getGlobalBounds())) {
        exploded = true;
        return true;  // Dynamite explodes if it hits the player
    }
    return false;
}

bool Dynamite::isOutOfScreen(sf::RenderWindow& window) {
    sf::FloatRect bounds = dynamite.getGlobalBounds();
    return !window.getGlobalBounds().intersects(bounds);  // Check if dynamite is out of screen
}*/