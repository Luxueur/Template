#ifndef DYNAMITE_HPP
#define DYNAMITE_HPP
#include "TntEnemy.hpp"

// Déclaration minimale de la classe Dynamite
class Dynamite {
public:
    Dynamite(Vector2f position, Vector2f target, float speed);
    ~Dynamite();
    void update(float deltaTime);
    void draw(RenderWindow& window);
    bool checkCollision(Player* player);
    bool isOutOfScreen(RenderWindow& window);
private:
    Sprite dynamiteSprite;
    Texture dynamiteTexture; // Ajout de la déclaration de dynamiteTexture
    Vector2f velocity;
    bool exploded;
};

#endif // !DYNAMITE_HPP
