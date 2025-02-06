#ifndef TORCHEENEMY2_HPP
#define TORCHEENEMY2_HPP
#include "Enemy.hpp"

enum class AnimationState {
    Idle,
    Walk,
    Attack,
    Dead
};

class TorcheEnemy : public Enemy {
public:
    TorcheEnemy(Player* p);  // Constructor
    virtual ~TorcheEnemy();  // Destructor

    void update(float deltaTime, RenderWindow& window) override;
    void draw(RenderWindow& window) override;
    void enemyMove();
    void attaque(RenderWindow& window);
    void prendDesDegats(RenderWindow& window);

private:
    void loadTextures();
    vector<Texture> loadAnimationFrames(const string& basePath, int numFrames);
    vector<Texture>& getCurrentAnimationFrames();

    int pv;

    vector<Texture> idleFrames;
    vector<Texture> walkFrames;
    vector<Texture> attackFrames;
    vector<Texture> attackFrames2;
    vector<Texture> attackFrames3;
    vector<Texture> deathFrames;

    // Animation control variables
    AnimationState currentAnimationState;
    int currentFrame;
    float animationSpeed;
    float timeSinceLastFrame;
};
#endif // !TORCHEENEMY2_HPP
