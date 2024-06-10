
#include "smallComputers.h"

#include "fmt/core.h"
#include "../ThrowableContainer.h"

void SmallComputers::draw(sf::RenderWindow &window) {
    window.draw(computer);
//    if(health != 3){
    window.draw(healthLine);
//    }
}

sf::FloatRect SmallComputers::getGlobalBounds() {
    return computer.getGlobalBounds();
}


void SmallComputers::collision(Player &player) {
    player.setHealth(player.getHealth() - 1);
    computer.setPosition(computer.getPosition().x + 10, computer.getPosition().y);
}

sf::Vector2<float> SmallComputers::getPosition() {
    return computer.getPosition();
}

sf::Vector2<float> SmallComputers::getSize() {
    return sf::Vector2f {64,40.5};
}

SmallComputers::~SmallComputers() = default;
void SmallComputers::update(sf::Time time, Player &player) {
    if(!respawnTimeSet){
        respawnTime = time.asSeconds();
        respawnTimeSet = true;
    }
    healthLine.setSize(sf::Vector2f (part * health, healthLine.getSize().y));
    healthLine.setPosition(computer.getPosition().x, computer.getPosition().y - 15);
    float deltaTime = time.asSeconds();
    velocity = 50;
    horizontalVelocity += gravity * deltaTime;
    computer.move(velocity * deltaTime, horizontalVelocity);
    if(computer.getPosition().x < 0){
        velocity = 50;
    }if(computer.getPosition().y > 1600){
        velocity = -50;
    }
//    if (velocity < 0) {
//        computer.setTexture(ResourceManager::getTexture("../graphics/SmallComputers.png"));
//    } else {
//        computer.setTexture(ResourceManager::getTexture("../graphics/0SmallComputersLeft.png"));
//    }

    float distanceToPlayerX = player.getPosition().x - computer.getPosition().x;
    float distanceToPlayerY = player.getPosition().y - computer.getPosition().y;
    if (std::abs(distanceToPlayerX) < 70 and std::abs(distanceToPlayerY) < 70 ) {
        followingPlayer = true;
        velocity = (distanceToPlayerX > 0) ? 50 : -50;
    } else if (std::abs(distanceToPlayerX) < 100 and std::abs(distanceToPlayerY) < 100 ) {
        followingPlayer = false;
    }
    if (!followingPlayer && std::abs(initialPositionX - computer.getPosition().x) > 250) {
        velocity *= -1;
    }
    if(time.asSeconds() == respawnTime and respawnTime != 0){
        ThrowableContainer::addItem(4, computer.getPosition().x, computer.getPosition().y);
        velocity = 0;
        lastShot = time.asSeconds();
    }
    if(lastShot != 0 and time.asSeconds() - lastShot > 0){
        ThrowableContainer::addItem(4, computer.getPosition().x, computer.getPosition().y);
        velocity = 0;
        lastShot = time.asSeconds();
    }
}

void SmallComputers::setPosition(float d, float d1) {
    computer.setPosition(d,d1);
}

void SmallComputers::setVerticalVelocity(int i) {
    horizontalVelocity = i;
}

void SmallComputers::setVelocity(int i) {
//    velocity = i;
}

void SmallComputers::setHealth(int i) {
    health = i;
}

int SmallComputers::getHealth() {
    return health;
}
