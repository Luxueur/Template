#include "ThreadManager.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;

//ThreadManager : classe gérant l'exécution de tâches en parallèle.

void ThreadManager::start(RenderWindow& window) {
    running = true;
    for (auto& enemy : enemies) {
        threads.emplace_back([this, &window, enemy]() {
            while (running) {
                std::this_thread::sleep_for(std::chrono::milliseconds(16)); // Simulate frame time
                lock_guard<std::mutex> lock(mtx);
                enemy->update(0.016f, window); // Assuming 60 FPS
            }
            });
    }
}

void ThreadManager::stop() {
	running = false;
	for (auto& t : threads) {
        if (t.joinable())
        {
            t.join();
        }
        
	}
}

void ThreadManager::addEnemy(Enemy* enemy) {
	lock_guard<std::mutex> lock(mtx);
	enemies.push_back(enemy);
}

void ThreadManager::updateEnemies(float deltaTime, sf::RenderWindow& window) {
    std::lock_guard<std::mutex> lock(mtx);
    for (auto& enemy : enemies) {
        enemy->update(deltaTime, window);
    }
}