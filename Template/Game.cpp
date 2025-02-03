#include "game.hpp"
//Game : classe principale gérant la boucle de jeu.

#include <vector>

using namespace std;
using namespace sf;


Game::Game() {

	window = new RenderWindow(VideoMode(screenWidth, screenlenght), "Zeldo");
	window->setFramerateLimit(60);
	Image icon;
	icon.loadFromFile("icon.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	//window->setMouseCursorVisible(false);

	//cursor
	cursorTexture.loadFromFile("Images/Menu/Pointers/cursor.png");
	cursorSprite.setTexture(cursorTexture);
	cursorSprite.setScale(Vector2f(.85f, .85f));

	//Menu Principal 
	bannerVerticalUpTexture.loadFromFile("Images/Menu/Banners/Banner_Connection.png");
	bannerVerticalUpSprite.setTexture(bannerVerticalUpTexture); bannerVerticalUpSprite.setPosition(Vector2f(float(screenWidth / 2), float(screenlenght / 2))); bannerVerticalUpSprite.setOrigin(Vector2f(bannerVerticalUpTexture.getSize()) / 2.f);
	bannerVerticalUpSprite.setScale(2.5f, 1.5f);
	exitButtonOnTexture.loadFromFile("Images/Menu/Buttons/Button_Red_3Slides.png");
	exitButtonOffTexture.loadFromFile("Images/Menu/Buttons/Button_Red_3Slides_Pressed.png");
	exitButtonSprite.setTexture(exitButtonOffTexture); exitButtonSprite.setPosition(Vector2f(float(screenWidth / 2), float(screenlenght / 2) + 10)); exitButtonSprite.setOrigin(Vector2f(exitButtonOffTexture.getSize()) / 2.f);
	exitButtonSprite.setTexture(exitButtonOnTexture); exitButtonSprite.setOrigin(Vector2f(exitButtonOnTexture.getSize()) / 2.f);
	startButtonOnTexture.loadFromFile("Images/Menu/Buttons/Button_Blue_3Slides.png");
	startButtonOffTexture.loadFromFile("Images/Menu/Buttons/Button_Blue_3Slides_Pressed.png");
	startButtonSprite.setTexture(startButtonOffTexture); startButtonSprite.setPosition(Vector2f(float(screenWidth / 2), float(screenlenght / 2) - 118)); startButtonSprite.setOrigin(Vector2f(startButtonOffTexture.getSize()) / 2.f);
	startButtonSprite.setTexture(startButtonOnTexture); startButtonSprite.setOrigin(Vector2f(startButtonOnTexture.getSize()) / 2.f);
	settingsButtonOnTexture.loadFromFile("Images/Menu/Buttons/Button_Hover_3Slides.png");
	settingsButtonOffTexture.loadFromFile("Images/Menu/Buttons/Button_Disable_3Slides.png");
	settingsButtonSprite.setTexture(settingsButtonOffTexture); settingsButtonSprite.setPosition(Vector2f(float(screenWidth / 2), float(screenlenght / 2) - 54)); settingsButtonSprite.setOrigin(Vector2f(settingsButtonOffTexture.getSize()) / 2.f);
	settingsButtonSprite.setTexture(settingsButtonOnTexture); settingsButtonSprite.setOrigin(Vector2f(settingsButtonOnTexture.getSize()) / 2.f);
	fontMain.loadFromFile("Fonts/font.ttf"); titleButtonFont.setString("ZELDO");
	titleButtonFont.setFont(fontMain); titleButtonFont.setCharacterSize(50); titleButtonFont.setPosition(Vector2f(float(screenWidth / 2), float(screenlenght) / 2 - 182)); titleButtonFont.setFillColor(Color::Black);
	textTitleBounds = titleButtonFont.getLocalBounds(); titleButtonFont.setOrigin(textTitleBounds.left + textTitleBounds.width / 2.0f, textTitleBounds.top + textTitleBounds.height / 2.0f);
	startButtonFont.setString("Ztart");
	startButtonFont.setFont(fontMain); startButtonFont.setCharacterSize(40); startButtonFont.setPosition(Vector2f(float(screenWidth / 2), float(screenlenght) / 2 - 123)); startButtonFont.setFillColor(Color::Black);
	textStartBounds = startButtonFont.getLocalBounds(); startButtonFont.setOrigin(textStartBounds.left + textStartBounds.width / 2.0f, textStartBounds.top + textStartBounds.height / 2.0f);
	settingsButtonFont.setString("Zettings");
	settingsButtonFont.setFont(fontMain); settingsButtonFont.setCharacterSize(40); settingsButtonFont.setPosition(Vector2f(float(screenWidth / 2), float(screenlenght) / 2 - 59)); settingsButtonFont.setFillColor(Color::Black);
	textSettingsBounds = settingsButtonFont.getLocalBounds(); settingsButtonFont.setOrigin(textSettingsBounds.left + textSettingsBounds.width / 2.0f, textSettingsBounds.top + textSettingsBounds.height / 2.0f);
	exitButtonFont.setString("Zexit");
	exitButtonFont.setFont(fontMain); exitButtonFont.setCharacterSize(40); exitButtonFont.setPosition(Vector2f(float(screenWidth / 2), float(screenlenght) / 2 + 5)); exitButtonFont.setFillColor(Color::Black);
	textExitBounds = exitButtonFont.getLocalBounds(); exitButtonFont.setOrigin(textExitBounds.left + textExitBounds.width / 2.0f, textExitBounds.top + textExitBounds.height / 2.0f);


}

void Game::playingGame() {
	Map* m = new Map();
	m->loadMap();

	Player player;
	InputHandler handleInput;
	TorcheEnemy torche(&player);
	Clock clock,clock6;
	Clock clockMap,clockMap6; 
	while (window->isOpen()) {
		Event event;
		while (window->pollEvent(event)) {
			if (event.type == Event::Closed) {
				window->close();
			}
		}

		Vector2f direction = player.getDirection();
		handleInput.handleInput(event, direction);
		player.setDirection(direction);

		float deltaTime = clock.restart().asSeconds();
		player.update(deltaTime);
		float deltaTime6 = clock6.restart().asSeconds(); 

		if (Keyboard::isKeyPressed(Keyboard::H)) {
			player.prendDesDegats();
		}
		if (Keyboard::isKeyPressed(Keyboard::J)) {
			player.soigneDesPv();
		}

		float deltaTimeMap = clockMap.restart().asSeconds(); 
		float deltaTimeMap6 = clockMap6.restart().asSeconds(); 
		m->update(deltaTimeMap,deltaTimeMap6); 

		window->clear();
		window->clear(Color(71, 171, 169));

		m->draw(*window);
		player.render(*window);
		torche.draw(*window);
		torche.enemyMove();
		torche.update(deltaTime);
		window->display();

	}
}

void Game::mainMenu() {
	Event event;
	while (window->isOpen()) {
		while (window->pollEvent(event)) {
			if (event.type == Event::Closed)
				window->close();
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				state = GameState::Exit;
				window->close();
			}
			else if (event.type == Event::MouseButtonPressed and Mouse::isButtonPressed(Mouse::Left)) {
				if (onStart) {
					state = GameState::Playing;

					//Player - joueur - map
					return gameloop();
				}
				if (onSettings) {
					state = GameState::Settings;
				}
				if (onExit) {
					state = GameState::Exit;
					window->close();
				}
			}
		}

		window->clear();
		window->clear(Color(71, 171, 169));
		window->draw(bannerVerticalUpSprite);
		window->draw(startButtonSprite); window->draw(startButtonFont);
		if (startButtonSprite.getGlobalBounds().contains(window->mapPixelToCoords(Mouse::getPosition(*window)))) {
			if (!onStart) {
				startButtonSprite.setTexture(startButtonOffTexture);
				startButtonFont.setPosition(Vector2f(float(screenWidth / 2), float(screenlenght) / 2 - 118));
				onStart = true; // mettre du son
			}
		}
		else if (onStart) {
			startButtonSprite.setTexture(startButtonOnTexture); onStart = false; startButtonFont.setPosition(Vector2f(float(screenWidth / 2), float(screenlenght) / 2 - 123));
		}
		window->draw(settingsButtonSprite);	window->draw(settingsButtonFont);
		if (settingsButtonSprite.getGlobalBounds().contains(window->mapPixelToCoords(Mouse::getPosition(*window)))) {
			if (!onSettings) {
				settingsButtonSprite.setTexture(settingsButtonOffTexture);
				settingsButtonFont.setPosition(Vector2f(float(screenWidth / 2), float(screenlenght) / 2 - 54));
				onSettings = true; // mettre du son
			}
		}
		else if (onSettings) {
			settingsButtonSprite.setTexture(settingsButtonOnTexture); onSettings = false; settingsButtonFont.setPosition(Vector2f(float(screenWidth / 2), float(screenlenght) / 2 - 59));
		}
		window->draw(exitButtonSprite);	window->draw(exitButtonFont);
		if (exitButtonSprite.getGlobalBounds().contains(window->mapPixelToCoords(Mouse::getPosition(*window)))) {
			if (!onExit) {
				exitButtonSprite.setTexture(exitButtonOffTexture);
				exitButtonFont.setPosition(Vector2f(float(screenWidth / 2), float(screenlenght) / 2 + 10));
				onExit = true; // mettre du son
			}
		}
		else if (onExit) {
			exitButtonSprite.setTexture(exitButtonOnTexture); onExit = false; exitButtonFont.setPosition(Vector2f(float(screenWidth / 2), float(screenlenght) / 2 + 5));
		}
		window->draw(titleButtonFont);
		cursorSprite.setPosition(Vector2f(static_cast<float>(Mouse::getPosition(*window).x), static_cast<float>(Mouse::getPosition(*window).y)));
		window->draw(cursorSprite);
		window->display();
	}
}

void Game::gameloop() {

	while (window->isOpen()) {
		if (state == GameState::Menu) {
			mainMenu();
		
		}
		else if (state == GameState::Pause) {
			pauseMenu();
		}
		else if (state == GameState::Playing) {
			playingGame();
			//userInput();
			//update();
			//display();

			//window.draw(chronoText);
			//window.draw(cursor);
			//window.display();
		}
		else if (state == GameState::Settings) {
			settingsMenu();
		}
	}
}
