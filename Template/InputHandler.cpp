#include "InputHandler.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

<<<<<<< Updated upstream

    void InputHandler::handleInput(Event& event, Vector2f& direction) {
=======
namespace Game {
    void InputHandler::handleInput(Event& event, Vector2f direction) {
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
        if (direction.x != 0.f || direction.y != 0.f) {
            float length = sqrt(direction.x * direction.x + direction.y * direction.y);
            direction /= length;
        }
    }
=======
        if (direction.x != 0.f || direction.y != 0.f)
        {
            float length = sqrt(direction.x * direction.x + direction.y * direction.y);
            direction /= length;

        }
    }
}


>>>>>>> Stashed changes

