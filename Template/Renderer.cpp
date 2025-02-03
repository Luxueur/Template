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
	textureSolCarreJaune.loadFromFile("Images/Terrain/Water/Ground/SolCarreJaune.png");
	textureSolJauneL.loadFromFile("Images/Terrain/Ground/SolJauneL.png");
	textureSolJaune_.loadFromFile("Images/Terrain/Ground/SolJaune_.png");
	textureSolJaune.loadFromFile("Images/Terrain/Ground/SolJaune.png");
	textureSolCarreVert.loadFromFile("Images/Terrain/Ground/SolCarreVert.png");
	textureSolVert.loadFromFile("Images/Terrain/Ground/SolVert.png");
	textureSolVert_.loadFromFile("Images/Terrain/Ground/SolVert_.png");
	textureSolVertL.loadFromFile("Images/Terrain/Ground/SolVertL.png");
	textureElevationCarre.loadFromFile("Images/Terrain/Ground/ElevationCarre.png");
	textureElevationL.loadFromFile("Images/Terrain/Ground/ElevationL.png");
	textureElevation_.loadFromFile("Images/Terrain/Ground/Elevation_.png");
	textureElevation.loadFromFile("Images/Terrain/Ground/Elevation.png");
	textureEscalier_.loadFromFile("Images/Terrain/Ground/Escalier_.png");
	textureEscalier.loadFromFile("Images/Terrain/Ground/Escalier.png");
	textureEscalier.loadFromFile("Images/Terrain/Ground/Escalier.png");
	textureTree.loadFromFile("Images/Resources/Trees/TreeC.png");
	
	

	int frame = 0;
	int frame6 = 0;
	timeSinceLastFrameMap = 0.f ;
	timeSinceLastFrameMap6 = 0.f ;

};

void Map::update(float deltaTime,float deltaTimeMap6) {
	
	timeSinceLastFrameMap += deltaTime;
	timeSinceLastFrameMap6 += deltaTimeMap6; 

	if (timeSinceLastFrameMap >= 0.1f) {
		timeSinceLastFrameMap = 0.f;
		frame ++;
	}
	if (frame > 7) {
		frame = 0;
	}

	if (timeSinceLastFrameMap6 >= 0.1f) {
		timeSinceLastFrameMap6 = 0.f;
		frame6++;
	}
	if (frame6 > 5) {
		frame6 = 0;
	}

	for (auto& mer : mers) {
		mer->setTextureRect(IntRect(frame * 192, 0, 96, 85));
	}
	for (auto& rock : rocks) {
		rock->setTextureRect(IntRect(frame * 128, 0, 128, 128));
	}
	for (auto& tree : trees) {
		tree->setTextureRect(IntRect(frame6 * 192, 0, 192, 192));
	}
}


void Map::collision() {

};

void Map::loadMap() {
	ifstream Map1("Map.txt");
	ifstream Map2("Map2.txt");  
	ifstream Map3("Map3.txt");  
	string line;
	float z = 0;


	while (getline(Map1, line)) {
		for (int i = 0; i < line.size(); i++) {
			switch (line[i]) {
			case '0': {
				Sprite* mer = new Sprite;
				mer->setTexture(textureMer);
				mer->setOrigin(10, 10); 
				mer->setPosition({ (float)i * 64, (float)z * 64 });
				mers.push_back(mer);
				break;
			}
			case '1': {
				Sprite* rock = new Sprite;
				rock->setTexture(textureRocks);
				rock->setPosition({ (float)i * 64, (float)z * 64 });
				rocks.push_back(rock);
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
				Sprite* vert = new Sprite;
				vert->setTexture(textureSolVert);
				vert->setPosition({ (float)i * 64, (float)z * 64 });
				herbeVert.push_back(vert);
				break;
			}
			case '7': {
				Sprite* vertL = new Sprite;
				vertL->setTexture(textureSolVertL);
				vertL->setPosition({ (float)i * 64, (float)z * 64 });
				herbeVertL.push_back(vertL);
				break;
			}
			case '8': {
				Sprite* vert_ = new Sprite;
				vert_->setTexture(textureSolVert_);
				vert_->setPosition({ (float)i * 64, (float)z * 64 });
				herbeVert_.push_back(vert_);
				break;
			}
			case '9': {
				Sprite* vertCarre = new Sprite;
				vertCarre->setTexture(textureSolCarreVert);
				vertCarre->setPosition({ (float)i * 64, (float)z * 64 });
				herbeVertCarre.push_back(vertCarre);
				break;
			}
			case 'A': {
				Sprite* elevation = new Sprite;
				elevation->setTexture(textureSolCarreVert);
				elevation->setPosition({ (float)i * 64, (float)z * 64 });
				vElevation.push_back(elevation);
				break;
			}
			case 'B': {
				Sprite* elevationL = new Sprite;
				elevationL->setTexture(textureSolCarreVert);
				elevationL->setPosition({ (float)i * 64, (float)z * 64 });
				vElevationL.push_back(elevationL);
				break;
			}
			case 'C': {
				Sprite* elevation_ = new Sprite;
				elevation_->setTexture(textureSolCarreVert);
				elevation_->setPosition({ (float)i * 64, (float)z * 64 });
				vElevation_.push_back(elevation_);
				break;
			}
			case 'D': {
				Sprite* elevationCarre = new Sprite;
				elevationCarre->setTexture(textureSolCarreVert);
				elevationCarre->setPosition({ (float)i * 64, (float)z * 64 });
				vElevationCarre.push_back(elevationCarre);
				break;
			}
			case 'E': {
				Sprite* escalier = new Sprite;
				escalier->setTexture(textureSolCarreVert);
				escalier->setPosition({ (float)i * 64, (float)z * 64 });
				vEscalier.push_back(escalier);
				break;
			}
			case 'F': {
				Sprite* escalier_ = new Sprite;
				escalier_->setTexture(textureSolCarreVert);
				escalier_->setPosition({ (float)i * 64, (float)z * 64 });
				vEscalier_.push_back(escalier_);
				break;
			}
			case 'G': {
				Sprite* tree = new Sprite;
				tree->setTexture(textureTree);
				tree->setPosition({ (float)i * 64, (float)z * 64 });
				trees.push_back(tree);
				break;
			}






			}
			cout << endl;
		}
		z++;
	}
	z = 0;
	while (getline(Map2, line)) {		
		for (int i = 0; i < line.size(); i++) { 
			switch (line[i]) { 
			case '0': {
				Sprite* mer = new Sprite;
				mer->setTexture(textureMer);
				mer->setOrigin(10, 10);
				mer->setPosition({ (float)i * 64, (float)z * 64 });
				mers.push_back(mer);
				break;
			}
			case '1': {
				Sprite* rock = new Sprite;
				rock->setTexture(textureRocks);
				rock->setPosition({ (float)i * 64, (float)z * 64 });
				rocks.push_back(rock);
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
				Sprite* vert = new Sprite;
				vert->setTexture(textureSolVert);
				vert->setPosition({ (float)i * 64, (float)z * 64 });
				herbeVert.push_back(vert);
				break;
			}
			case '7': {
				Sprite* vertL = new Sprite;
				vertL->setTexture(textureSolVertL);
				vertL->setPosition({ (float)i * 64, (float)z * 64 });
				herbeVertL.push_back(vertL);
				break;
			}
			case '8': {
				Sprite* vert_ = new Sprite;
				vert_->setTexture(textureSolVert_);
				vert_->setPosition({ (float)i * 64, (float)z * 64 });
				herbeVert_.push_back(vert_);
				break;
			}
			case '9': {
				Sprite* vertCarre = new Sprite;
				vertCarre->setTexture(textureSolCarreVert);
				vertCarre->setPosition({ (float)i * 64, (float)z * 64 });
				herbeVertCarre.push_back(vertCarre);
				break;
			}
			case 'A': {
				Sprite* elevation = new Sprite;
				elevation->setTexture(textureSolCarreVert);
				elevation->setPosition({ (float)i * 64, (float)z * 64 });
				vElevation.push_back(elevation);
				break;
			}
			case 'B': {
				Sprite* elevationL = new Sprite;
				elevationL->setTexture(textureSolCarreVert);
				elevationL->setPosition({ (float)i * 64, (float)z * 64 });
				vElevationL.push_back(elevationL);
				break;
			}
			case 'C': {
				Sprite* elevation_ = new Sprite;
				elevation_->setTexture(textureSolCarreVert);
				elevation_->setPosition({ (float)i * 64, (float)z * 64 });
				vElevation_.push_back(elevation_);
				break;
			}
			case 'D': {
				Sprite* elevationCarre = new Sprite;
				elevationCarre->setTexture(textureSolCarreVert);
				elevationCarre->setPosition({ (float)i * 64, (float)z * 64 });
				vElevationCarre.push_back(elevationCarre);
				break;
			}
			case 'E': {
				Sprite* escalier = new Sprite;
				escalier->setTexture(textureSolCarreVert);
				escalier->setPosition({ (float)i * 64, (float)z * 64 });
				vEscalier.push_back(escalier);
				break;
			}
			case 'F': {
				Sprite* escalier_ = new Sprite;
				escalier_->setTexture(textureSolCarreVert);
				escalier_->setPosition({ (float)i * 64, (float)z * 64 });
				vEscalier_.push_back(escalier_);
				break;
			}
			case 'G': {
				Sprite* tree = new Sprite;
				tree->setTexture(textureTree);
				tree->setPosition({ (float)i * 64, (float)z * 64 });
				trees.push_back(tree);
				break;
			}
			}
			cout << endl;
		}
		z++; 
	}
	z = 0;
	while (getline(Map3, line)) {
		for (int i = 0; i < line.size(); i++) {
			switch (line[i]) {
			case '0': {
				Sprite* mer = new Sprite;
				mer->setTexture(textureMer);
				mer->setOrigin(10, 10);
				mer->setPosition({ (float)i * 64, (float)z * 64 });
				mers.push_back(mer);
				break;
			}
			case '1': {
				Sprite* rock = new Sprite;
				rock->setTexture(textureRocks);
				rock->setPosition({ (float)i * 64, (float)z * 64 });
				rocks.push_back(rock);
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
				Sprite* vert = new Sprite;
				vert->setTexture(textureSolVert);
				vert->setPosition({ (float)i * 64, (float)z * 64 });
				herbeVert.push_back(vert);
				break;
			}
			case '7': {
				Sprite* vertL = new Sprite;
				vertL->setTexture(textureSolVertL);
				vertL->setPosition({ (float)i * 64, (float)z * 64 });
				herbeVertL.push_back(vertL);
				break;
			}
			case '8': {
				Sprite* vert_ = new Sprite;
				vert_->setTexture(textureSolVert_);
				vert_->setPosition({ (float)i * 64, (float)z * 64 });
				herbeVert_.push_back(vert_);
				break;
			}
			case '9': {
				Sprite* vertCarre = new Sprite;
				vertCarre->setTexture(textureSolCarreVert);
				vertCarre->setPosition({ (float)i * 64, (float)z * 64 });
				herbeVertCarre.push_back(vertCarre);
				break;
			}
			case 'A': {
				Sprite* elevation = new Sprite;
				elevation->setTexture(textureSolCarreVert);
				elevation->setPosition({ (float)i * 64, (float)z * 64 });
				vElevation.push_back(elevation);
				break;
			}
			case 'B': {
				Sprite* elevationL = new Sprite;
				elevationL->setTexture(textureSolCarreVert);
				elevationL->setPosition({ (float)i * 64, (float)z * 64 });
				vElevationL.push_back(elevationL);
				break;
			}
			case 'C': {
				Sprite* elevation_ = new Sprite;
				elevation_->setTexture(textureSolCarreVert);
				elevation_->setPosition({ (float)i * 64, (float)z * 64 });
				vElevation_.push_back(elevation_);
				break;
			}
			case 'D': {
				Sprite* elevationCarre = new Sprite;
				elevationCarre->setTexture(textureSolCarreVert);
				elevationCarre->setPosition({ (float)i * 64, (float)z * 64 });
				vElevationCarre.push_back(elevationCarre);
				break;
			}
			case 'E': {
				Sprite* escalier = new Sprite;
				escalier->setTexture(textureSolCarreVert);
				escalier->setPosition({ (float)i * 64, (float)z * 64 });
				vEscalier.push_back(escalier);
				break;
			}
			case 'F': {
				Sprite* escalier_ = new Sprite;
				escalier_->setTexture(textureSolCarreVert);
				escalier_->setPosition({ (float)i * 64, (float)z * 64 });
				vEscalier_.push_back(escalier_);
				break;
			}
			case 'G': {
				Sprite* tree = new Sprite;
				tree->setTexture(textureTree);
				tree->setPosition({ (float)i * 192, (float)z * 192});
				trees.push_back(tree);
				break;
			}
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
	for (auto& vert : herbeVert) {
		window.draw(*vert);
	}
	for (auto& vertL : herbeVertL) {
		window.draw(*vertL);
	}
	for (auto& vert_ : herbeVert_) {
		window.draw(*vert_);
	}
	for (auto& vertCarre : herbeVertCarre) {
		window.draw(*vertCarre);
	}
	for (auto& rock : vElevation) {
		window.draw(*rock);
	}
	for (auto& rock : vElevationL) {
		window.draw(*rock);
	}
	for (auto& rock : vElevation_) {
		window.draw(*rock);
	}
	for (auto& rock : vElevationCarre) {
		window.draw(*rock);
	}
	for (auto& rock : vEscalier) { 
		window.draw(*rock);
	}
	for (auto& rock : vEscalier_) {
		window.draw(*rock);
	}
	for (auto& tree : trees) {
		window.draw(*tree);
	}
};