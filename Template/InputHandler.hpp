#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class InputHandler {
public:
    void handleInput(sf::Event& event, sf::Vector2f& direction);
};

//InputHandler classe g�rant les entr�es utilisateur.
