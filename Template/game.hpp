#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
#include <conio.h>

#include "Player.hpp"
#include "Entity.hpp"
#include "Enemy.hpp"
#include "InputHandler.hpp"
#include "Renderer.hpp"
#include "Physics.hpp"
#include "ThreadManager.hpp"

using namespace std;
using namespace sf;


class Game {
public:

	RenderWindow* window;
	Texture cursorTexture;
	Sprite cursor;


	Game();

	void gameloop();
};


#endif // !GAME_HPP