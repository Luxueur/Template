#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <memory>
#include "Camera.hpp"

using namespace sf;
using namespace std;

class Player {
public:
    Player();
    void update(RenderWindow& window, float deltaTime);
    void render(RenderWindow& window);
    void setDirection(Vector2f direction);
    Vector2f getDirection();
    void prendDesDegats(RenderWindow& window);
    void soigneDesPv(RenderWindow& window);
    int getPv() const;
    void updateHealthBar(RenderWindow& window, const Vector2f& playerPosition);
    void updateAttackAnimation(float deltaTime);
    void attack();
    // Mise � jour de la d�claration
    void shootArrow(Vector2f direction); // Mise � jour de la d�claration
    void attackWithBow(Vector2f target); // Mise � jour de la d�claration
    void loadTextures();
    void updateAnimation(float deltaTime);
    void handleMouseInput(const Event& event); // Nouvelle m�thode

    unique_ptr<Sprite> playerSprite;

private:
    enum class State { Idle, Walk, Attacking, AttackingBow };
    State currentState;
    vector<shared_ptr<Texture>> idleTextures;
    vector<shared_ptr<Texture>> walkTextures;
    vector<shared_ptr<Texture>> attackTexturesUp;
    vector<shared_ptr<Texture>> attackTexturesDown;
    vector<shared_ptr<Texture>> attackTexturesLeft;
    vector<shared_ptr<Texture>> attackTexturesRight;
    vector<shared_ptr<Texture>> attackBowTexturesUp;
    vector<shared_ptr<Texture>> attackBowTexturesDown;
    vector<shared_ptr<Texture>> attackBowTexturesLeft;
    vector<shared_ptr<Texture>> attackBowTexturesRight;
    vector<shared_ptr<Texture>> attackBowTexturesUpRight;
    vector<shared_ptr<Texture>> attackBowTexturesDownRight;
    vector<shared_ptr<Sprite>> healthBar;
    Texture arrowTexture;
    vector<shared_ptr<Sprite>> arrows;
    vector<Vector2f> arrowDirections; // D�claration de la variable
    float arrowSpeed = 500.0f; // D�claration de la variable
    SoundBuffer attackSoundBuffer;
    Sound attackSound;
    SoundBuffer bowSoundBuffer;
    Sound bowSound;
    int pv;
    int currentAttack;
    float attackCooldown;
    float attackTimer;
    bool isAttacking;
    bool newAttackRequested;
    Texture playerTexture;
    Vector2f direction;
    float speed;
    float animationTime;
    int attackFrame;
    size_t currentFrame;
    float attackSoundTimer;
    float bowTimer;
    float bowCooldown;
};

