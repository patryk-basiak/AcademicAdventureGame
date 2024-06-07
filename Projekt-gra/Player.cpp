
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
    if(isShown) {
        isFacingRight ? player.setTexture(ResourceManager::getTexture("../graphics/player.png")) : player.setTexture(
                ResourceManager::getTexture("../graphics/player1.png"));
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

    float horizontalVelocity = 0.0f;
    float verticalVelocityIncrement = gravity * deltaTime;

    if (health <= 0) {
        game = false;
        return;
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

    collisionRect.left += horizontalVelocity * deltaTime;
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {
        verticalVelocity = jumpVelocity;
        isGround = false;
        lastJumpTime = clock.getElapsedTime().asSeconds();
    }

    if (!isGround) {
        verticalVelocity += verticalVelocityIncrement;
    }


    collisionRect.top += verticalVelocity * deltaTime;

    if (verticalVelocity == 0) {
        isGround = true;
    }else {
        isGround = false;
    }

    // Update the player's position based on the collision rect
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

