#include "InputHandler.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;


void InputHandler::handleInput(sf::Event& event, sf::Vector2f& direction, Player& player) {
    direction = Vector2f(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        direction.y -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        direction.y += 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        direction.x -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        direction.x += 1.f;
    }
    if (direction.x != 0.f || direction.y != 0.f) {
        float length = sqrt(direction.x * direction.x + direction.y * direction.y);
        direction /= length;
    }
    if (direction.x != 0.f || direction.y != 0.f)
    {
        float length = sqrt(direction.x * direction.x + direction.y * direction.y);
        direction /= length;
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        player.attack();
    }
}