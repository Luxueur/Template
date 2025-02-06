#include "Player.hpp"
using namespace sf;
using namespace std;

Player::Player() : pv(3), speed(200.0f), animationTime(0.0f), currentFrame(0), currentState(State::Idle), currentAttack(1), attackCooldown(0.0f), isAttacking(false), newAttackRequested(false) , attackSoundTimer(0.0f) {
    loadTextures();
    playerSprite = make_unique<Sprite>();
    playerSprite->setTexture(*idleTextures[0]);
    playerSprite->setOrigin(Vector2f(idleTextures[0]->getSize()) / 2.f);
    playerSprite->setPosition(Vector2f(400.0f, 300.0f));
    direction = Vector2f(0.0f, 0.0f);

    for (int i = 0; i < pv; i++) {
        auto heart = make_unique<Sprite>();
        heart->setTexture(playerTexture); // texture pour les pv a rajouter et remplacer par celle du player
        heart->setPosition(10 + i * 30, 10);
        healthBar.push_back(move(heart));
    }
    cout << "initialisation des pv: " << pv << endl;
}

void Player::loadTextures() {
    for (int i = 0; i < 4; ++i) {
        auto texture = make_shared<Texture>();
        if (!texture->loadFromFile("Images/Factions/Knights/Troops/Warrior/Blue/Idle/Warrior_Blue_Idle" + to_string(i) + ".png")) {
            throw std::runtime_error("Failed to load idle texture");
        }
        idleTextures.push_back(texture);
    }

    for (int i = 0; i < 5; i++) {
        auto texture = make_shared<Texture>();
        if (!texture->loadFromFile("Images/Factions/Knights/Troops/Warrior/Blue/Walk/Warrior_Blue_Walk" + to_string(i) + ".png")) {
            throw std::runtime_error("Failed to load walk texture");
        }
        walkTextures.push_back(texture);
    }

    for (int i = 0; i < 12; i++) {
        auto texture = make_shared<Texture>();
        if (!texture->loadFromFile("Images/Factions/Knights/Troops/Warrior/Blue/Attack/Warrior_Blue_Attack" + to_string(i) + ".png")) {
            throw std::runtime_error("Failed to load attack1 texture");
        }
        attackTexturesRight.push_back(texture);
    }
    for (int i = 0; i < 12; i++) {
        auto texture = make_shared<Texture>();
        if (!texture->loadFromFile("Images/Factions/Knights/Troops/Warrior/Blue/Attack/Warrior_Blue_Attack" + to_string(i) + ".png")) {
            throw std::runtime_error("Failed to load attack1 texture");
        }
        attackTexturesLeft.push_back(texture);
    }
    for (int i = 0; i < 12; i++) {
        auto texture = make_shared<Texture>();
        if (!texture->loadFromFile("Images/Factions/Knights/Troops/Warrior/Blue/Attack/Attack_Variant/Up/Warrior_Blue_Attack_Up" + to_string(i) + ".png")) {
            throw std::runtime_error("Failed to load attack1 texture");
        }
        attackTexturesUp.push_back(texture);
    }
    for (int i = 0; i < 12; i++) {
        auto texture = make_shared<Texture>();
        if (!texture->loadFromFile("Images/Factions/Knights/Troops/Warrior/Blue/Attack/Attack_Variant/Down/Warrior_Blue_Attack_Down" + to_string(i) + ".png")) {
            throw std::runtime_error("Failed to load attack1 texture");
        }
        attackTexturesDown.push_back(texture);
    }

    if (!playerTexture.loadFromFile("Images/Factions/Knights/Troops/Warrior/Blue/Idle/Warrior_Blue_Idle0.png")) {
        throw std::runtime_error("Failed to load future health texture");
    }
    if (!attackSoundBuffer.loadFromFile("Audio/Player_projectile_attack_sword_0.wav"))
    {
        throw std::runtime_error("Failed to load attack sound");
    }
	attackSound.setBuffer(attackSoundBuffer);

    for (int i = 0; i < 8; ++i) {
        auto texture = make_shared<Texture>();
        texture->loadFromFile("path/to/attackBowUp" + to_string(i) + ".png");
        attackBowTexturesUp.push_back(texture);

        texture = make_shared<Texture>();
        texture->loadFromFile("path/to/attackBowDown" + to_string(i) + ".png");
        attackBowTexturesDown.push_back(texture);

        texture = make_shared<Texture>();
        texture->loadFromFile("path/to/attackBowLeft" + to_string(i) + ".png");
        attackBowTexturesLeft.push_back(texture);

        texture = make_shared<Texture>();
        texture->loadFromFile("path/to/attackBowRight" + to_string(i) + ".png");
        attackBowTexturesRight.push_back(texture);

        texture = make_shared<Texture>();
        texture->loadFromFile("path/to/attackBowUpRight" + to_string(i) + ".png");
        attackBowTexturesUpRight.push_back(texture);

        texture = make_shared<Texture>();
        texture->loadFromFile("path/to/attackBowDownRight" + to_string(i) + ".png");
        attackBowTexturesDownRight.push_back(texture);
    }

    
    arrowTexture.loadFromFile("path/to/arrow.png");

 
    bowSoundBuffer.loadFromFile("path/to/bowSound.wav");
    bowSound.setBuffer(bowSoundBuffer);
}

void Player::update(RenderWindow& window, float deltaTime) {
    playerSprite->move(direction * speed * deltaTime);
    if (bowTimer < bowCooldown) {
        bowTimer += deltaTime;
    }

    // Mise à jour de l'animation d'attaque à l'arc
    if (currentState == State::AttackingBow) {
        updateAttackAnimation(deltaTime);
    }
    for (auto& arrow : arrows) {
       
        arrow->move(direction * speed * deltaTime);
        // Vérifier les collisions et la durée de vie de la flèche
        // (à implémenter plus tard)
    }

    updateAnimation(deltaTime);
    //updateAttackAnimation(deltaTime);
    updateHealthBar(window, playerSprite->getPosition());
}

void Player::render(RenderWindow& window) {
    window.draw(*playerSprite);
    for (const auto& heart : healthBar) {
        window.draw(*heart);
    }
}

void Player::setDirection(Vector2f direction) {
    this->direction = direction;
    if (currentState != State::Attacking) {
        if (direction.x != 0.f || direction.y != 0.f) {
            currentState = State::Walk;
        }
        else {
            currentState = State::Idle;
        }
    }

    if (direction.x < 0) {
        playerSprite->setScale(-1.f, 1.f);
    }
    else if (direction.x > 0) {
        playerSprite->setScale(1.f, 1.f);
    }
}

Vector2f Player::getDirection() {
    return direction;
}

void Player::prendDesDegats(RenderWindow& window) {
    if (pv > 0) {
        --pv;
        cout << "Pv après avoir pris les degats : " << pv << endl;
        updateHealthBar(window, playerSprite->getPosition());
    }
}

void Player::attack() {
    if (!isAttacking && attackCooldown <= 0.0f) {
        cout << "Attaque déclenchée" << endl;
        currentState = State::Attacking;
        attackFrame = 0;
        attackTimer = 0.0f;
        isAttacking = true;
		//attackSound.play();
    }
}
void Player::attackWithBow() {
    if (bowTimer >= bowCooldown) {
        currentState = State::AttackingBow;
        isAttacking = true;
        attackFrame = 0;
        bowTimer = 0.0f;
        shootArrow();
        bowSound.play();
    }
}

void Player::shootArrow() {
    auto arrow = make_shared<Sprite>();
    arrow->setTexture(arrowTexture);
    arrow->setPosition(playerSprite->getPosition());
    arrows.push_back(arrow);
}
void Player::soigneDesPv(RenderWindow& window) {
    ++pv;
    cout << "Pv après les soins : " << pv << endl;
    updateHealthBar(window, playerSprite->getPosition());
}

int Player::getPv() const {
    return pv;
}

void Player::updateHealthBar(RenderWindow& window, const Vector2f& playerPosition) {
    healthBar.clear();
    View view = window.getView();
    FloatRect viewport = view.getViewport();
    Vector2f healthBarPosition(viewport.left + playerPosition.x - 645.0f, viewport.top + playerPosition.y - 480.0f);
    for (int i = 0; i < pv; ++i) {
        auto heart = make_unique<Sprite>();
        heart->setTexture(playerTexture); // texture pour les pv a remplacer par le playerTexture
        heart->setPosition(healthBarPosition + Vector2f(i * 30, 10)); // position du pv (x, y));
        healthBar.push_back(move(heart));
    }
}

void Player::updateAnimation(float deltaTime) {
    animationTime += deltaTime;
    if (animationTime >= 0.1f) {
        animationTime = 0.f;
        if (currentState == State::Idle) {
            currentFrame = (currentFrame + 1) % idleTextures.size();
            playerSprite->setTexture(*idleTextures[currentFrame]);
        }
        else if (currentState == State::Walk) {
            currentFrame = (currentFrame + 1) % walkTextures.size();
            playerSprite->setTexture(*walkTextures[currentFrame]);
        }
        else if (currentState == State::Attacking) {
            updateAttackAnimation(deltaTime);
        }
    }
}

void Player::updateAttackAnimation(float deltaTime) {
    if (currentState == State::Attacking) {
        cout << "Mise à jour de l'animation d'attaque" << endl;
        attackTimer += deltaTime;
        if(attackSoundTimer >=0.5f)
        {
			attackSound.play();
			attackSoundTimer = 0.0f;
		}
		else
		{
			attackSoundTimer += deltaTime;
        }
        if (attackTimer >= 0.1f) {
            attackTimer = 0.0f;
            attackFrame++;
            if (attackFrame >= 12) { // Nombre de frames dans l'animation d'attaque
                currentState = State::Idle;
                attackCooldown = 0.5f;
                isAttacking = false;
            }
            else {
                // Mettez à jour le sprite en fonction de la direction du joueur
                if (direction.y < 0) {
                    playerSprite->setTexture(*attackTexturesUp[attackFrame]);
                }
                else if (direction.y > 0) {
                    playerSprite->setTexture(*attackTexturesDown[attackFrame]);
                }
                else if (direction.x < 0) {
                    playerSprite->setTexture(*attackTexturesLeft[attackFrame]);
                }
                else if (direction.x > 0) {
                    playerSprite->setTexture(*attackTexturesRight[attackFrame]);
                }

                // Adaptez la direction du sprite
                if (direction.x < 0) {
                    playerSprite->setScale(-1.f, 1.f);
                }
                else if (direction.x > 0) {
                    playerSprite->setScale(1.f, 1.f);
                }
            }
        }
    }
    if (attackCooldown > 0.0f) {
        attackCooldown -= deltaTime;
    }
}