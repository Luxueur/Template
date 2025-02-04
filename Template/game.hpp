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
	//Fenetre principale
	RenderWindow* window;
	float screenWidth = 1300;
	float screenlenght = screenWidth / 4 * 3;
	Vector2f mousePos;
	//Menu principale
	Texture cursorTexture;	Sprite cursorSprite;
	bool isStart = false;
	bool isExit = false;
	bool isSettings = false;
	bool onStart = false;
	bool onExit = false;
	bool onSettings = false;
	Texture bannerVerticalUpTexture, bannerVerticalDownTexture;	Sprite bannerVerticalUpSprite, bannerVerticalDownSprite;
	Texture exitButtonOnTexture, exitButtonOffTexture; Sprite exitButtonSprite;
	Texture startButtonOnTexture, startButtonOffTexture; Sprite startButtonSprite;
	Texture settingsButtonOnTexture, settingsButtonOffTexture; Sprite settingsButtonSprite;
	Font fontMain;
	Text startButtonFont, settingsButtonFont, exitButtonFont, titleButtonFont;
	FloatRect textTitleBounds, textStartBounds, textSettingsBounds, textExitBounds;



	enum class GameState {
		Menu,
		Adventure,
		Pause,
		Settings,
		Exit
	};

	GameState state;
	//Texture settingsButtonOn, settingsButtonOff; Sprite settingsButton;


	Game();

	void pauseMenu() {};

	void playingGame();

	void settingsMenu() {};

	void mainMenu();

	void gameloop();
};


#endif // !GAME_HPP