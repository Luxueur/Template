#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

using namespace sf;
using namespace std;

//Renderer : classe gérant l'affichage graphique.

class Map {
public:

	Texture textureMer, textureSol, textureRocks, textureSable, textureSolCarreJaune, textureSolJaune, textureSolJaune_, textureSolJauneL;
	Sprite spriteMer, spriteSol;

	vector<Sprite*> mers;
	vector<Sprite*> sols; 
	vector<Sprite*> rocks; 
	vector<Sprite*> sableJauneCarre; 
	vector<Sprite*> sableJauneL; 
	vector<Sprite*> sableJaune_; 
	vector<Sprite*> sableJaune; 

	int frame;
	float timeSinceLastFrameMap;

	Map();

	void update(float deltaTimeMap);

	void collision();

	void loadMap();

	void draw(RenderWindow& window);





};