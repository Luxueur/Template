#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include <vector>


using namespace sf;
using namespace std;


class InputHandler {
public:
    void handleInput(sf::Event& event, sf::Vector2f& direction, Player& player);
};