
#include "Player.h"
#include "ResourceManager.h"
#include "fmt/core.h"
#include "Settings.h"



Player::Player() {
    collisionRect = sf::FloatRect(1230,654, 46.88, 71.76);
    player.setPosition(1230,654);
    player.setScale(0.06,0.06);
    this->isFacingRight = false;
    size.push_back(35.16);
    size.push_back(53.82);
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
    isFacingRight ? player.setTexture(ResourceManager::getTexture("../graphics/player.png")) : player.setTexture(ResourceManager::getTexture("../graphics/player1.png"))
    ;
    this->player.setPosition(collisionRect.left,collisionRect.top);
    window.draw(this->player);
}
void Player::jump(){
    if(isGround) {
        verticalVelocity = jumpVelocity;
        isGround = false;
    }
}

void Player::update(sf::Time time) {
    float deltaTime = time.asSeconds();

    velocity = 0.0f;
    float currentTime = clock.getElapsedTime().asSeconds();

    if (player.getPosition().y == surface) {
        isGround = true;
    }

    if (movable) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            isFacingRight = true;
            velocity = speed * deltaTime;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            isFacingRight = false;
            velocity = -speed * deltaTime;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
//                    sf::Vector2 pos = player.getPosition();
//                    player.move(3,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
//                    sf::Vector2 pos = player.getPosition();
//                    player.move(3,0);
        }
        collisionRect.left += velocity;
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) or sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {
            if(currentTime - lastJumpTime >= JumpCooldown ){
                verticalVelocity = jumpVelocity;
                isGround = false;
                lastJumpTime = currentTime;
            }

        }
        if(!isGround){
            verticalVelocity += gravity * deltaTime;
        }
        if ((collisionRect.top + collisionRect.height) > surface) {
            collisionRect.top = surface - collisionRect.height;

        }
        collisionRect.top += verticalVelocity * deltaTime;
        player.setPosition(collisionRect.left, collisionRect.top);
    }
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


//void Player::itemInHand(Collectable &collactable) {
//
//}

//void Player::itemInHand(Collectable& collactable) {
//    // kiedys to zrobie
//}

