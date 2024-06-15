
#include "Player.h"
#include "ResourceManager.h"
#include "fmt/core.h"
#include "Settings.h"


Player::Player() {
    collisionRect = sf::FloatRect(1230,654, 46.88, 71.76);
    player.setPosition(1230,654);
    player.setScale(2,2);
    this->isFacingRight = false;
    size.push_back(42);
    size.push_back(70);
    for(int i = 0; i<12; ++i){
        sf::Sprite temp;
        temp.setPosition(player.getPosition().x, player.getPosition().y);
        temp.setTexture(ResourceManager::getTexture("../graphics/player/idle/idle" + std::to_string(i) + ".png"));
    }for(int i = 0; i<12; ++i){
        sf::Sprite temp;
        temp.setPosition(player.getPosition().x, player.getPosition().y);
        temp.setTexture(ResourceManager::getTexture("../graphics/player/idle/idle" + std::to_string(i) + "r.png"));
    }for(int i = 0; i<8; ++i){
        sf::Sprite temp;
        temp.setPosition(player.getPosition().x, player.getPosition().y);
        temp.setTexture(ResourceManager::getTexture("../graphics/player/run/run" + std::to_string(i) + ".png"));
    }for(int i = 0; i<8; ++i){
        sf::Sprite temp;
        temp.setPosition(player.getPosition().x, player.getPosition().y);
        temp.setTexture(ResourceManager::getTexture("../graphics/player/run/run" + std::to_string(i) + "r.png"));
    }
    player.setTexture(ResourceManager::getTexture("../graphics/player/idle/idle" + std::to_string(0) + ".png"));
}

void Player::move(float x, float y) {
    player.move(x, y);
}
void Player::setX(float x){
//    if(isGround) {
//        player.setPosition() = x;
//    }
}
void Player::setY(float y){
//    this->velocity.y = y;
}
void Player::draw(sf::RenderWindow& window) {
    if(isShown) {
        this->player.setPosition(collisionRect.left, collisionRect.top);
        window.draw(this->player);
    }
}
void Player::jump(){
    if(isGround) {
        verticalVelocity = jumpVelocity;
        isGround = false;
    }
}

void Player::update(sf::Time time) {
    float deltaTime = time.asSeconds();
    if(!game_started){
        animation_clock.restart();
        deltaTime = 0; // first delta time was always so big that I have make it zero.
        game_started = true;
    }
    float horizontalVelocity = 0.0f;
    float verticalVelocityIncrement = gravity * deltaTime;

    if(player.getPosition().y > 1000){
        health = 0;
    }


    if (movable) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            isFacingRight = true;
            horizontalVelocity = speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            isFacingRight = false;
            horizontalVelocity = -speed;
        }
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) and jumpable and isGround) {
        if(clock.getElapsedTime().asSeconds() - lastJumpTime > JumpCooldown) {
            isGround = false;
            verticalVelocity = jumpVelocity;
            isGround = false;
            lastJumpTime = clock.getElapsedTime().asSeconds();
        }
    }
    if (animation_clock.getElapsedTime().asSeconds() > 0.5 and horizontalVelocity == 0 and !isFacingRight) {
        currentTextureMove = 0;
        if(currentTexture < 11){
            currentTexture++;
        }else{
            currentTexture = 0;
        }
        player.setTexture(ResourceManager::getTexture("../graphics/player/idle/idle" + std::to_string(currentTexture) + "r.png") );
        animation_clock.restart();
    }if (animation_clock.getElapsedTime().asSeconds() > 0.5 and horizontalVelocity == 0 and isFacingRight) {
        currentTextureMove = 0;
        if(currentTexture < 11){
            currentTexture++;
        }else{
            currentTexture = 0;
        }
        player.setTexture(ResourceManager::getTexture("../graphics/player/idle/idle" + std::to_string(currentTexture) + ".png") );
        animation_clock.restart();
    }if (animation_clock.getElapsedTime().asSeconds() > 0.5 and horizontalVelocity != 0 and isFacingRight) {
        currentTexture = 0;
        if(currentTextureMove < 7){
            currentTextureMove++;
        }else{
            currentTextureMove = 0;
        }
        player.setTexture(ResourceManager::getTexture("../graphics/player/run/run" + std::to_string(currentTextureMove) + ".png") );
        animation_clock.restart();
    }if (animation_clock.getElapsedTime().asSeconds() > 0.5 and horizontalVelocity != 0 and !isFacingRight) {
        currentTexture = 0;
        if(currentTextureMove < 7){
            currentTextureMove++;
        }else{
            currentTextureMove = 0;
        }
        player.setTexture(ResourceManager::getTexture("../graphics/player/run/run" + std::to_string(currentTextureMove) + "r.png") );
        animation_clock.restart();
    }
    if(!game or paused){
        player.setPosition(1500,200);
        velocity = 0;
        verticalVelocity = 0;
        horizontalVelocity = 0;
        verticalVelocityIncrement = 0;
    }

    if (!isGround and jumpable) {
        verticalVelocity += verticalVelocityIncrement;
    }

    if (verticalVelocity == 0) {
        isGround = true;
    }else {
        isGround = false;
    }
    collisionRect.left += horizontalVelocity * deltaTime;
    collisionRect.top += verticalVelocity * deltaTime;

    player.setPosition(collisionRect.left, collisionRect.top);

}
sf::FloatRect Player::getGlobalBounds(){
    return player.getGlobalBounds();
}

sf::Vector2<float> Player::getPosition() {
    return player.getPosition();

}

void Player::setPosition(float x, float y) {
    collisionRect.left = x;
    collisionRect.top = y;
    player.setPosition(x,y);

}

const std::vector<float> &Player::getSize() {
    return size;

}

float Player::getSurface() const {
    return this->surface;
}

void Player::setSurface(float x) {
    this->surface = x;
}

int Player::getHealth() const {
    return this->health;
}

void Player::setHealth(int n) {
    this->health = n;
}

void Player::setStartPosition() {
    collisionRect.left = 100;
    collisionRect.top = 654;

}

void Player::setEndPosition() {
    collisionRect.left = 1560;
}

void Player::setVelocity(float i) {
    this->velocity = i;

}

void Player::setVerticalVelocity(float i) {
    this->verticalVelocity = i;
}

void Player::isGroundCheck(bool boolean) {
    isGround = boolean;
}

void Player::hide() {
    isShown = false;
}

void Player::showPlayer() {
    isShown = true;

}

bool Player::isSeen() {
    return isShown;
}

bool Player::getFacingRight() {
    return isFacingRight;
}

int Player::getStrength() const {
    return strength;
}

int Player::getIntelligence() const {
    return intelligence;
}

int Player::getLuck() const {
    return luck;
}

int Player::getAgile() const {
    return agile;
}

int Player::getEndurance() const {
    return endurance;
}

void Player::setStrength(int xstrength) {
    Player::strength = xstrength;
    damage = 1 + (xstrength/3);
}

void Player::setIntelligence(int xintelligence) {
    Player::intelligence = xintelligence;
}

void Player::setLuck(int xluck) {
    Player::luck = xluck;
}

void Player::setAgile(int xagile) {
    Player::agile = xagile;
    jumpVelocity = -150 - ((float)(150*agile)/40);
}

void Player::setEndurance(int xendurance) {
    Player::endurance = xendurance;
    health = 3 + (xendurance/3);
}

bool Player::isGround1() const {
    return isGround;
}

void Player::setIsGround(bool ground) {
    Player::isGround = ground;
}

