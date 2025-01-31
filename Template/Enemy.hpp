#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Entity.hpp"
using namespace sf;
using namespace std;

//Enemy : classe gérant les ennemis et leur comportement.
class Enemy : public Entity{
public:
	Enemy();
	~Enemy();

	void update(float deltaTime) override;
	void draw(RenderWindow& window) override;
};

class torcheENemy : public Enemy{
public:
	torcheENemy();
	~torcheENemy();
};




#endif // !ENEMY_HPP


