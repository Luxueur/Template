//Entity (classe de base) : classe abstraite servant de base aux objets du jeu(ennemis, joueur...)
#include "Entity.hpp"

Entity::Entity() {}
Entity::~Entity() {}

void Entity::setPosition(float x, float y) {
    enemy.setPosition(x, y);
}

Vector2f Entity::getPosition() const {
    return enemy.getPosition();
}

void Entity::update(float deltaTime,RenderWindow& window) {}

void Entity::draw(RenderWindow& window) {
    window.draw(enemy);
}
