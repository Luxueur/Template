#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

using namespace sf;
using namespace std;

//Renderer : classe gérant l'affichage graphique.

class Map {
public:

	Texture textureMer, textureSol;
	Sprite spriteMer, spriteSol;

	vector<Sprite*> mers;
	vector<Sprite*> sols; 

	Map();

	void update();

	void collision();

	void loadMap();

	void draw(RenderWindow& window);





};