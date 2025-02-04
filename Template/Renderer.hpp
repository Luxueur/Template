#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

//#include "game.hpp"

using namespace sf;
using namespace std;

//Renderer : classe gérant l'affichage graphique.

class Map {
public:

	Texture textureMer, textureRocks, textureSable, textureSolCarreJaune, textureSolJaune, textureSolJaune_, textureSolJauneL,textureSolCarreVert, textureSolVert,textureSolVert_, textureSolVertL, textureElevationCarre, textureElevationL, textureElevation_, textureElevation, textureEscalier_, textureEscalier;
	Texture textureTree, textureSheepBouncing, textureSheep,texturePawn,textureCastle, textureCastleD,textureArcher, textureGoblinHouse,textureCitrouille, textureEpouventail, textureChamp, textureBuisson, textureCroix, textureFleche, textureOs;
	Texture textureDungeon,textureCloud;
	vector<Sprite*> mers;
	vector<Sprite*> dungeonS;
	vector<Sprite*> herbeVert,herbeVert_,herbeVertL, herbeVertCarre; 
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
	vector<Sprite*> cloudS;
	vector<Sprite*> vArcher;
	vector<Sprite*> goblinHouses;
	vector<Sprite*> osS,epouventailS,citrouilleS,champS,buissonS,flecheS,croixS;

	vector<ifstream*> maps;
	int frame,frame6;
	float timeSinceLastFrameMap, timeSinceLastFrameMap6;

	enum class StatePlaying {
		Adventure,
		Dungeon,
	};

	StatePlaying statePlaying;

	Map();

	void update(float deltaTime,float deltaTimeMap6);

	void collision();
	
	void loadMap();

	void monSwitch(ifstream& Map, string line, int z);

	void draw(RenderWindow& window);
};