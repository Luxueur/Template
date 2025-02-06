#include "Player.hpp"
using namespace sf;
using namespace std;

Player::Player() : pv(3), speed(200.0f), animationTime(0.0f), currentFrame(0), currentState(State::Idle), currentAttack(1), attackCooldown(0.0f), isAttacking(false), newAttackRequested(false), attackSoundTimer(0.0f), bowTimer(0.0f), bowCooldown(2.5f) {
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
    if (!attackSoundBuffer.loadFromFile("Audio/Player_projectile_attack_sword_0.wav")) {
        throw std::runtime_error("Failed to load attack sound");
    }
    attackSound.setBuffer(attackSoundBuffer);

    for (int i = 0; i < 8; ++i) {
        auto texture = make_shared<Texture>();
        if (!texture->loadFromFile("Images/Factions/Knights/Troops/Archer/Blue/Attack/Attack_variant/Up/Archer_Blue_Attack_Up" + to_string(i) + ".png")) {
            throw std::runtime_error("Failed to load bow attack texture");
        }
        attackBowTexturesUp.push_back(texture);
    }
    for (int i = 0; i < 8; i++) {
        auto texture = make_shared<Texture>();
        if (!texture->loadFromFile("Images/Factions/Knights/Troops/Archer/Blue/Attack/Attack_variant/Down/Archer_Blue_Attack_Down" + to_string(i) + ".png")) {
            throw std::runtime_error("Failed to load bow attack texture");
        }
        attackBowTexturesDown.push_back(texture);
    }
    for (int i = 0; i < 8; i++) {
        auto texture = make_shared<Texture>();
        if (!texture->loadFromFile("Images/Factions/Knights/Troops/Archer/Blue/Attack/Archer_BlueAttack" + to_string(i) + ".png")) {
            throw std::runtime_error("Failed to load bow attack texture");
        }
        attackBowTexturesLeft.push_back(texture);
    }
    for (int i = 0; i < 8; i++) {
        auto texture = make_shared<Texture>();
        if (!texture->loadFromFile("Images/Factions/Knights/Troops/Archer/Blue/Attack/Archer_BlueAttack" + to_string(i) + ".png")) {
            throw std::runtime_error("Failed to load bow attack texture");
        }
        attackBowTexturesRight.push_back(texture);
    }
    for (int i = 0; i < 8; i++) {
        auto texture = make_shared<Texture>();
        if (!texture->loadFromFile("Images/Factions/Knights/Troops/Archer/Blue/Attack/Attack_variant/UpRight/Archer_Blue_Attack_UpRight" + to_string(i) + ".png")) {
            throw std::runtime_error("Failed to load bow attack texture");
        }
        attackBowTexturesUpRight.push_back(texture);
    }
    for (int i = 0; i < 8; i++) {
        auto texture = make_shared<Texture>();
        if (!texture->loadFromFile("Images/Factions/Knights/Troops/Archer/Blue/Attack/Attack_variant/DownRight/Archer_Blue_Attack_DownRight" + to_string(i) + ".png")) {
            throw std::runtime_error("Failed to load bow attack texture");
        }
        attackBowTexturesDownRight.push_back(texture);
    }

    if (!arrowTexture.loadFromFile("Images/Factions/Knights/Troops/Archer/Arrow/Arrow0.png")) {
        throw std::runtime_error("Failed to load arrow texture");
    }

    if (!bowSoundBuffer.loadFromFile("Audio/621470__atg65__love-arrow.wav")) {
        throw std::runtime_error("Failed to load bow sound");
    }
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
    for (size_t i = 0; i < arrows.size(); ++i) {
        arrows[i]->move(arrowDirections[i] * arrowSpeed * deltaTime);
        // Vérifier les collisions et la durée de vie de la flèche
        // (à implémenter plus tard)
    }

    updateAnimation(deltaTime);
    updateHealthBar(window, playerSprite->getPosition());
}

void Player::render(RenderWindow& window) {
    window.draw(*playerSprite);
    for (const auto& heart : healthBar) {
        window.draw(*heart);
    }
    for (const auto& arrow : arrows) {
        window.draw(*arrow);
    }
}

void Player::setDirection(Vector2f direction) {
    this->direction = direction;
    if (currentState != State::Attacking && currentState != State::AttackingBow) {
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

void Player::attackWithBow(Vector2f target) {
    if (bowTimer >= bowCooldown) {
        currentState = State::AttackingBow;
        isAttacking = true;
        attackFrame = 0;
        bowTimer = 0.0f;
        //arrows
   

        shootArrow(direction);
        bowSound.play();
    }
}

void Player::shootArrow(Vector2f direction) {
    auto arrow = make_shared<Sprite>();
    arrow->setTexture(arrowTexture);
    arrow->setPosition(playerSprite->getPosition());
    Vector2f moveArrow;
    float angle;

    // Capture la position de la souris
    Vector2i posSouris = Mouse::getPosition();
    Vector2f posJoueur = playerSprite->getPosition();

    float deltaX = posSouris.x - posJoueur.x;
    float deltaY = posSouris.y - posJoueur.y;
    angle = atan2(deltaY, deltaX) * 180.f / 3.14159;
    arrow->setRotation(angle - 90.f);

    moveArrow.x = cos(angle) * arrowSpeed;
    moveArrow.y = sin(angle) * arrowSpeed;
    arrows.push_back(arrow);
    arrowDirections.push_back(direction);


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
        else if (currentState == State::Attacking || currentState == State::AttackingBow) {
            updateAttackAnimation(deltaTime);
        }
    }
}

void Player::updateAttackAnimation(float deltaTime) {
    if (currentState == State::Attacking || currentState == State::AttackingBow) {
        cout << "Mise à jour de l'animation d'attaque" << endl;
        attackTimer += deltaTime;
        if (attackSoundTimer >= 0.5f) {
            attackSound.play();
            attackSoundTimer = 0.0f;
        }
        else {
            attackSoundTimer += deltaTime;
        }
        if (attackTimer >= 0.1f) {
            attackTimer = 0.0f;
            attackFrame++;
            if (currentState == State::Attacking && attackFrame >= 12) { // Nombre de frames dans l'animation d'attaque
                currentState = State::Idle;
                attackCooldown = 0.5f;
                isAttacking = false;
            }
            else if (currentState == State::AttackingBow && attackFrame >= 8) { // Nombre de frames dans l'animation d'attaque à l'arc
                currentState = State::Idle;
                attackCooldown = 2.5f;
                isAttacking = false;
            }
            else {
                // Mettez à jour le sprite en fonction de la direction du joueur
                if (currentState == State::AttackingBow) {
                    if (direction.y < 0) {
                        playerSprite->setTexture(*attackBowTexturesUp[attackFrame]);
                    }
                    else if (direction.y > 0) {
                        playerSprite->setTexture(*attackBowTexturesDown[attackFrame]);
                    }
                    else if (direction.x < 0) {
                        playerSprite->setTexture(*attackBowTexturesLeft[attackFrame]);
                    }
                    else if (direction.x > 0) {
                        playerSprite->setTexture(*attackBowTexturesRight[attackFrame]);
                    }
                }
                else {
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

void Player::handleMouseInput(const Event& event) {
    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
        Vector2f target = Vector2f(event.mouseButton.x, event.mouseButton.y);
        attackWithBow(target);
    }
}