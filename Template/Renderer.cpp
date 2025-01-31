#include "Renderer.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

//Renderer : classe gérant l'affichage graphique.

Map::Map() {
	 
	textureMer.loadFromFile("Images/Terrain/Water/Foam/foam.png"); 
	textureSol.loadFromFile("Images/Terrain/Ground/SolCarreVert.png");
	
	spriteSol.setTexture(textureSol);
	spriteMer.setTextureRect(IntRect(0, 0, 192,192));
	int frame = 0;
	timeSinceLastFrame = 0.f ;

};

void Map::update(float deltaTimeMap) {
	
	timeSinceLastFrame += deltaTimeMap;
	if (timeSinceLastFrame >= 0.1f) { timeSinceLastFrame = 0.f;frame++; }
	if (frame / 10 > 7) { frame = 0; }
	else { frame++; }
	
};

void Map::collision() {

};

void Map::loadMap() {
	ifstream Map1("Map.txt");  
	string line;
	float z = 0;

	while (getline(Map1, line)) {
		for (int i = 0; i < line.size(); i++) {
			switch (line[i]) {
			case '0': {
				Sprite* mer = new Sprite;
				mer->setTextureRect(IntRect(0, 0, 192, 192));
				mer->setPosition({ (float)i * 192, (float)z * 192 });
				mers.push_back(mer);
				break;
			}
			case '1': {
				Sprite* sol = new Sprite;
				sol->setTexture(textureSol);
				sol->setPosition({ (float)i * 32, (float)z * 32 });
				sols.push_back(sol);
				break;
			}

			//case '2': {
			//	Sprite* porte = new Sprite;
			//	porte->setTexture(texturePorte);
			//	porte->setPosition({ (float)i * 32, (float)z * 32 });
			//	portes.push_back(porte);
			//	break;
			//}
			}
			cout << endl;
		}
		z++;
	}
};

void Map::draw(RenderWindow& window) {
	for (auto& mer : mers) {
		window.draw(*mer);
	}
	for (auto& sol : sols) {
		window.draw(*sol);
	}
	//for (auto& porte : portes) {
	//	window.draw(*porte);
	//}
};