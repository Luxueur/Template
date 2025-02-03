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
	textureSheep.loadFromFile("Images/Resources/Sheep/Sheep.png");
	textureSheepBouncing.loadFromFile("Images/Resources/Sheep/SheepBouncing.png");
	texturePawn.loadFromFile("Images/Resources/Sheep/Troupe.png");
	textureCastle.loadFromFile("Images/Factions/Knights/Buildings/Castle/Castle.png");
	textureCastleD.loadFromFile("Images/Factions/Knights/Buildings/Castle/CastleD.png");
	textureArcher.loadFromFile("Images/Factions/Knights/Troops/Archer/Blue/Archer_Blue.png");
	textureGoblinHouse.loadFromFile("Images/Factions/Goblins/Buildings/Wood_House/GoblinHouse.png");

	textureBuisson.loadFromFile("Images/Deco/buisson.png");
	textureChamp.loadFromFile("Images/Deco/champ.png");
	textureCitrouille.loadFromFile("Images/Deco/citrouille.png");
	textureCroix.loadFromFile("Images/Deco/croix.png");
	textureEpouventail.loadFromFile("Images/Deco/epouventail.png");
	textureFleche.loadFromFile("Images/Deco/fleche.png");
	textureOs.loadFromFile("Images/Deco/os.png");

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
	for (auto& sheeps : sheeps) {
		sheeps->setTextureRect(IntRect(frame * 128, 0, 128, 128));
	}
	for (auto& sheepsBouncing : sheepsBouncing) {
		sheepsBouncing->setTextureRect(IntRect(frame6 * 128, 0, 128, 128));
	}
	for (auto& pawnM : pawnsM) {
		pawnM->setTextureRect(IntRect(frame6 * 192, 384, 192, 192));
	}
	for (auto& pawnH : pawnsH) {
		pawnH->setTextureRect(IntRect(frame6 * 192, 576, 192, 192));
	}
	for (auto& archer : vArcher) {
		archer->setTextureRect(IntRect(frame6 * 192, 0, 192, 192));
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
			case 'H': {
				Sprite* sheep = new Sprite;
				sheep->setTexture(textureSheep);
				sheep->setPosition({ (float)i * 64, (float)z * 64 });
				sheeps.push_back(sheep);
				break;
			}
			case 'I': {
				Sprite* sheepBouncing = new Sprite;
				sheepBouncing->setTexture(textureSheepBouncing);
				sheepBouncing->setPosition({ (float)i * 64, (float)z * 64 });
				sheepsBouncing.push_back(sheepBouncing);
				break;
			}
			case 'J': {
				Sprite* pawnM = new Sprite;
				pawnM->setTexture(texturePawn);
				pawnM->setPosition({ (float)i * 64, (float)z * 64 });
				pawnsM.push_back(pawnM);
				break;
			}
			case 'K': {
				Sprite* pawnH = new Sprite;
				pawnH->setTexture(texturePawn);
				pawnH->setPosition({ (float)i * 64, (float)z * 64 });
				pawnsH.push_back(pawnH);
				break;
			}
			case 'L': {
				Sprite* castle = new Sprite;
				castle->setTexture(textureCastle);
				castle->setPosition({ (float)i * 64, (float)z * 64 });
				vCastles.push_back(castle);
				break;
			}
			case 'M': {
				Sprite* castleD = new Sprite;
				castleD->setTexture(textureCastleD);
				castleD->setPosition({ (float)i * 64, (float)z * 64 });
				vCastleDs.push_back(castleD);
				break;
			}
			case 'N': {
				Sprite* archer = new Sprite;
				archer->setTexture(textureArcher);
				archer->setPosition({ (float)i * 64, (float)z * 64 });
				vArcher.push_back(archer);
				break;
			}
			case 'O': {
				Sprite* goblinHouse = new Sprite;
				goblinHouse->setTexture(textureGoblinHouse);
				goblinHouse->setPosition({ (float)i * 64, (float)z * 64 });
				goblinHouses.push_back(goblinHouse);
				break;
			}
			case 'P': {
				Sprite* croix = new Sprite;
				croix->setTexture(textureCroix);
				croix->setPosition({ (float)i * 64, (float)z * 64 });
				croixS.push_back(croix);
				break;
			}
			case 'Q': {
				Sprite* fleche = new Sprite;
				fleche->setTexture(textureFleche);
				fleche->setPosition({ (float)i * 64, (float)z * 64 });
				flecheS.push_back(fleche);
				break;
			}
			case 'R': {
				Sprite* epouventail = new Sprite;
				epouventail->setTexture(textureEpouventail);
				epouventail->setPosition({ (float)i * 64, (float)z * 64 });
				epouventailS.push_back(epouventail);
				break;
			}
			case 'S': {
				Sprite* citrouille = new Sprite;
				citrouille->setTexture(textureCitrouille);
				citrouille->setPosition({ (float)i * 64, (float)z * 64 });
				citrouilleS.push_back(citrouille);
				break;
			}
			case 'T': {
				Sprite* champ = new Sprite;
				champ->setTexture(textureChamp);
				champ->setPosition({ (float)i * 64, (float)z * 64 });
				champS.push_back(champ);
				break;
			}
			case 'U': {
				Sprite* os = new Sprite;
				os->setTexture(textureOs);
				os->setPosition({ (float)i * 64, (float)z * 64 });
				osS.push_back(os);
				break;
			}
			case 'V': {
				Sprite* buisson = new Sprite;
				buisson->setTexture(textureBuisson);
				buisson->setPosition({ (float)i * 64, (float)z * 64 });
				buissonS.push_back(buisson);
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
			case 'H': {
				Sprite* sheep = new Sprite;
				sheep->setTexture(textureSheep);
				sheep->setPosition({ (float)i * 64, (float)z * 64 });
				sheeps.push_back(sheep);
				break;
			}
			case 'I': {
				Sprite* sheepBouncing = new Sprite;
				sheepBouncing->setTexture(textureSheepBouncing);
				sheepBouncing->setPosition({ (float)i * 64, (float)z * 64 });
				sheepsBouncing.push_back(sheepBouncing);
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
	for (auto& sheep : sheeps) {
		window.draw(*sheep);
	}
	for (auto& sheepBouncing : sheepsBouncing) {
		window.draw(*sheepBouncing);
	}
	for (auto& pawnM : pawnsM) {
		window.draw(*pawnM);
	}
	for (auto& pawnH : pawnsH) {
		window.draw(*pawnH);
	}
	for (auto& castle : vCastles) {
		window.draw(*castle);
	}
	for (auto& castleD : vCastleDs) {
		window.draw(*castleD);
	}
	for (auto& archer : vArcher) {
		window.draw(*archer);
	}
	for (auto& goblinHouse : goblinHouses) {
		window.draw(*goblinHouse);
	}
	for (auto& croix : croixS) {
		window.draw(*croix);
	}
	for (auto& fleche : flecheS) {
		window.draw(*fleche);
	}
	for (auto& epouventail : epouventailS) {
		window.draw(*epouventail);
	}
	for (auto& champ : champS) {
		window.draw(*champ);
	}
	for (auto& citrouille : citrouilleS) {
		window.draw(*citrouille);
	}
	for (auto& os : osS) {
		window.draw(*os);
	}
	for (auto& buisson : buissonS) {
		window.draw(*buisson);
	}
};