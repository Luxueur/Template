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
	Texture textureTree, textureSheepBouncing, textureSheep,texturePawn,textureCastle, textureCastleD,textureArcher, textureGoblinHouse,textureCitrouille, textureEpouventail, textureChamp, textureBuisson, textureCroix, textureFleche, textureOs;
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
	vector<Sprite*> sheeps;
	vector<Sprite*> sheepsBouncing;
	vector<Sprite*> pawnsM;
	vector<Sprite*> pawnsH;
	vector<Sprite*> vCastles;
	vector<Sprite*> vCastleDs;
	vector<Sprite*> vArcher;
	vector<Sprite*> goblinHouses;
	vector<Sprite*> osS,epouventailS,citrouilleS,champS,buissonS,flecheS,croixS;

	int frame,frame6;
	float timeSinceLastFrameMap, timeSinceLastFrameMap6;

	Map();

	void update(float deltaTime,float deltaTimeMap6);

	void collision();
	
	void loadMap();

	void draw(RenderWindow& window);
};