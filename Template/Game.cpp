#include "game.hpp"
//Game : classe principale gérant la boucle de jeu.

using namespace std;
using namespace sf;


Game::Game(){

	window = new RenderWindow(VideoMode(1300, 1080), "Zeldo");
	window->setFramerateLimit(60);
	Image icon;
	icon.loadFromFile("icon.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window->setMouseCursorVisible(false);
	
	//cursor
	cursorTexture.loadFromFile("Images/Menu/Pointers/cursor.png");
	cursor.setTexture(cursorTexture);
	cursor.setScale(Vector2f(.75f, 0.75f));
	
}

void Game::gameloop() {
	while (window->isOpen()) {
		Event event;
		while (window->pollEvent(event)) {
			if (event.type == Event::Closed)
				window->close();
		}

	window->clear();
	cursor.setPosition(Vector2f(static_cast<float>(Mouse::getPosition(*window).x), static_cast<float>(Mouse::getPosition(*window).y)));
	window->draw(cursor);

	window->display();




	}

	
	
}
