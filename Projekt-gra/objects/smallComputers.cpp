
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
    return sf::Vector2f {computer.getTexture()->getSize().x*computer.getScale().x, computer.getTexture()->getSize().y*computer.getScale().y};
}

SmallComputers::~SmallComputers() = default;
void SmallComputers::update(sf::Time time, Player &player) {
    float distanceToPlayerX = player.getPosition().x - computer.getPosition().x;
    float distanceToPlayerY = player.getPosition().y - computer.getPosition().y;
    if(!respawnTimeSet){
        respawnTime = time.asSeconds();
        respawnTimeSet = true;
        velocity = (distanceToPlayerX > 0) ? 50 : -50;
    }
    healthLine.setSize(sf::Vector2f (part * health, healthLine.getSize().y));
    healthLine.setPosition(computer.getPosition().x, computer.getPosition().y - 15);
    float deltaTime = time.asSeconds();

    if (std::abs(distanceToPlayerX) < 200 and std::abs(distanceToPlayerY) < 64 ) {
        followingPlayer = true;
        velocity = (distanceToPlayerX > 0) ? 50 : -50;
    }
    else if (std::abs(distanceToPlayerX) > 300){
        followingPlayer = false;
    }if(!followingPlayer){
        velocity = 50;
    }

    horizontalVelocity += gravity * deltaTime;
    computer.move(velocity * deltaTime, horizontalVelocity);
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
