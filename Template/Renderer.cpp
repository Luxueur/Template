#include "Renderer.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

//Renderer : classe gérant l'affichage graphique.

Map::Map() {
	 
	textureMer.loadFromFile("Images/Terrain/Water/Foam/FoamC.png"); 
	textureRocks.loadFromFile("Images/Terrain/Water/Rocks/Rocks04.png"); 
	textureSolCarreJaune.loadFromFile("Images/Terrain/Water/Foam/SolCarreJaune.png");
	textureSolJauneL.loadFromFile("Images/Terrain/Water/Foam/SolJauneL.png");
	textureSolJaune_.loadFromFile("Images/Terrain/Water/Foam/SolJaune_.png");
	textureSolJaune.loadFromFile("Images/Terrain/Water/Foam/SolJaune.png");



	textureSol.loadFromFile("Images/Terrain/Ground/SolCarreVert.png");
	textureSable.loadFromFile("Images/Terrain/Ground/SolCarreVert.png");
	

	int frame = 0;
	timeSinceLastFrameMap = 0.f ;

};

void Map::update(float deltaTimeMap) {
	
	timeSinceLastFrameMap += deltaTimeMap;

	if (timeSinceLastFrameMap >= 0.1f) {
		timeSinceLastFrameMap = 0.f;
		frame ++;
	}
	if (frame > 7) {
		frame = 0;
	}
	for (auto& mer : mers) {
		mer->setTextureRect(IntRect(frame * 192, 0, 96, 85));
	}
	for (auto& rock : rocks) {
		rock->setTextureRect(IntRect(frame * 128, 0, 128, 128));
	}






}


void Map::collision() {

};

void Map::loadMap() {
	ifstream Map1("Map.txt");
	ifstream Map2("Map2.txt");  
	string line;
	float z = 0;
	float p = 0;

	while (getline(Map1, line)) {
		for (int i = 0; i < line.size(); i++) {
			switch (line[i]) {
			case '0': {
				Sprite* mer = new Sprite;
				mer->setTexture(textureMer);
				mer->setPosition({ (float)i * 64, (float)z * 64 });
				mers.push_back(mer);
				break;
			}
			case '1': {
				Sprite* sol = new Sprite;
				sol->setTexture(textureSol);
				sol->setPosition({ (float)i * 64, (float)z * 64 });
				sols.push_back(sol);
				break;
			}
			case '2': {
				Sprite* jaune = new Sprite;
				jaune->setTexture(textureSolJaune);
				jaune->setPosition({ (float)i * 64, (float)z * 64 });
				sableJaune.push_back(jaune);
				break;
			}
			case '3': {
				Sprite* jauneL = new Sprite; 
				jauneL->setTexture(textureSolJauneL);
				jauneL->setPosition({ (float)i * 64, (float)z * 64 });
				sableJauneL.push_back(jauneL);
				break;
			}
			case '4': {
				Sprite* jaune_ = new Sprite;
				jaune_->setTexture(textureSolJaune_);
				jaune_->setPosition({ (float)i * 64, (float)z * 64 });
				sableJaune_.push_back(jaune_);
				break;
			}
			case '5': {
				Sprite* jauneCarre = new Sprite;
				jauneCarre->setTexture(textureSolCarreJaune);
				jauneCarre->setPosition({ (float)i * 64, (float)z * 64 });
				sableJauneCarre.push_back(jauneCarre);
				break;
			}
			case '6': {
				Sprite* rock = new Sprite;
				rock->setTexture(textureRocks);
				rock->setPosition({ (float)i * 64, (float)z * 64 });
				rocks.push_back(rock);
				break;
			}
			}
			cout << endl;
		}
		z++;
	}

	while (getline(Map2, line)) {		
		for (int i = 0; i < line.size(); i++) { 
			switch (line[i]) { 
			case '0': {
				Sprite* mer = new Sprite;
				mer->setTexture(textureMer);
				mer->setPosition({ (float)i * 64, (float)z * 64 });
				mers.push_back(mer);
				break;
			}
			case '1': {
				Sprite* sol = new Sprite;
				sol->setTexture(textureSol);
				sol->setPosition({ (float)i * 64, (float)z * 64 });
				sols.push_back(sol);
				break;
			}
			case '2': {
				Sprite* jaune = new Sprite;
				jaune->setTexture(textureSolJaune);
				jaune->setPosition({ (float)i * 64, (float)z * 64 });
				sableJaune.push_back(jaune);
				break;
			}
			case '3': {
				Sprite* jauneL = new Sprite;
				jauneL->setTexture(textureSolJauneL);
				jauneL->setPosition({ (float)i * 64, (float)z * 64 });
				sableJauneL.push_back(jauneL);
				break;
			}
			case '4': {
				Sprite* jaune_ = new Sprite;
				jaune_->setTexture(textureSolJaune_);
				jaune_->setPosition({ (float)i * 64, (float)z * 64 });
				sableJaune_.push_back(jaune_);
				break;
			}
			case '5': {
				Sprite* jauneCarre = new Sprite;
				jauneCarre->setTexture(textureSolCarreJaune);
				jauneCarre->setPosition({ (float)i * 64, (float)z * 64 });
				sableJauneCarre.push_back(jauneCarre);
				break;
			}
			case '6': {
				Sprite* rock = new Sprite;
				rock->setTexture(textureRocks);
				rock->setPosition({ (float)i * 64, (float)z * 64 });
				rocks.push_back(rock);
				break;
			}
			}
			cout << endl;
		}
		p++; 
	}
};

void Map::draw(RenderWindow& window) {
	for (auto& mer : mers) {
		window.draw(*mer);
	}
	for (auto& sol : sols) {
		window.draw(*sol);
	}	
	for (auto& rock : rocks) {
		window.draw(*rock);
	}
	for (auto& jaune : sableJaune) {
		window.draw(*jaune);
	}
	for (auto& jauneL : sableJauneL) {
		window.draw(*jauneL);
	}
	for (auto& jaune_ : sableJaune_) {
		window.draw(*jaune_);
	}
	for (auto& jauneCarre : sableJauneCarre) {
		window.draw(*jauneCarre);
	}







	for (auto& rock : rocks) {
		window.draw(*rock);
	}
};