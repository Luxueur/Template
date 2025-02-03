#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

using namespace sf;
using namespace std;

//Renderer : classe gérant l'affichage graphique.

class Map {
public:

	Texture textureMer, textureRocks, textureSable, textureSolCarreJaune, textureSolJaune, textureSolJaune_, textureSolJauneL,textureSolCarreVert, textureSolVert,textureSolVert_, textureSolVertL, textureElevationCarre, textureElevationL, textureElevation_, textureElevation, textureEscalier_, textureEscalier;
	Texture textureTree;
	vector<Sprite*> mers;
	vector<Sprite*> herbeVert; 
	vector<Sprite*> herbeVert_; 
	vector<Sprite*> herbeVertL; 
	vector<Sprite*> herbeVertCarre; 
	vector<Sprite*> rocks; 
	vector<Sprite*> sableJauneCarre; 
	vector<Sprite*> sableJauneL; 
	vector<Sprite*> sableJaune_; 
	vector<Sprite*> sableJaune; 
	vector<Sprite*> vElevationCarre; 
	vector<Sprite*> vElevation_;
	vector<Sprite*> vElevationL;
	vector<Sprite*> vElevation;
	vector<Sprite*> vEscalier_;
	vector<Sprite*> vEscalier;
	vector<Sprite*> trees;

	int frame,frame6;
	float timeSinceLastFrameMap, timeSinceLastFrameMap6;

	Map();

	void update(float deltaTime,float deltaTimeMap6);

	void collision();

	void loadMap();

	void draw(RenderWindow& window);

};