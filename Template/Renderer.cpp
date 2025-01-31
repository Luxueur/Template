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
	spriteMer.setTexture(textureMer);
	spriteSol.setTexture(textureSol);



};

void Map::update() {

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
				mer->setTexture(textureMer);
				mer->setPosition({ (float)i * 32, (float)z * 32 });
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