#pragma once
#include "Enemy.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <vector>
#include <mutex>


using namespace sf;
using namespace std;

//ThreadManager: classe g�rant l'ex�cution de t�ches en parall�le.
class ThreadManager
{
public:
	void start(RenderWindow& window);
	void stop();
	void addEnemy(Enemy* enemy);
	void updateEnemies(float deltaTime, RenderWindow& window);

private:
	vector<thread> threads;
	vector<Enemy*> enemies;
	mutex mtx;
	bool running = false;

};

