#ifndef BARRELENEMY_HPP
#define BARRELENEMY_HPP
#include "Enemy.hpp"

class BarrelEnemy : public Enemy {
public:
    BarrelEnemy(Player* p);
    ~BarrelEnemy();

    void update(float deltaTime, RenderWindow& window) override;
    void draw(RenderWindow& window) override;
    void attaque(RenderWindow& window);

private:
    void loadTextures();

    vector<Texture> loadAnimationFrames(const string& basePath, int numFrames);
    vector<Texture>& getCurrentAnimationFrames();
    vector<Texture> idleFrames;
    vector<Texture> caughtFrames;
    vector<Texture> damageFrames;

    // Animation state control
    enum class AnimationState { Idle, Caught, Explode };
    AnimationState currentAnimationState;

    // Animation control variables
    int currentFrame;
    float animationSpeed;
    float timeSinceLastFrame;
};
#endif // !BARRELENEMY_HPP