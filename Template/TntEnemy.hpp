#ifndef TNTENEMY_HPP
#define TNTENEMY_HPP
#include "Enemy.hpp"
#include "Dynamite.hpp"


enum class AnimationState2 {
    Idle,
    Attack,
    Dead
};

class TNTEnemy : public Enemy {
public:
    TNTEnemy(Player* p);
    ~TNTEnemy();

    void update(float deltaTime, RenderWindow& window) override;
    void draw(RenderWindow& window) override;
    void attaque(RenderWindow& window) override;

private:
    void loadTextures();
    void throwDynamite();
    Texture textureOs;
    vector<Texture> idleFrames;
    vector<Texture> throwFrames;
    vector<Texture> loadAnimationFrames(const string& basePath, int numFrames);
    vector<Texture>& getCurrentAnimationFrames();

    // Dynamite-related properties
    vector<Dynamite*> dynamites;  // List of dynamites thrown at the player
    float throwCooldown; // Time between throws

    AnimationState2 currentAnimationState;
    int currentFrame;
    float animationSpeed;
    float timeSinceLastFrame;
};
#endif // !TNTENEMY_HPP
