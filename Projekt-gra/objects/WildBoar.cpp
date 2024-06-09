#include "WildBoar.h"
#include "fmt/core.h"

void WildBoar::draw(sf::RenderWindow &window) {
    window.draw(wild);
//    if(health != 3){
        window.draw(healthLine);
//    }
}

sf::FloatRect WildBoar::getGlobalBounds() {
    return wild.getGlobalBounds();
}


void WildBoar::collision(Player &player) {
    player.setHealth(player.getHealth() - 1);
    wild.setPosition(wild.getPosition().x + 10, wild.getPosition().y);
}

sf::Vector2<float> WildBoar::getPosition() {
    return wild.getPosition();
}

sf::Vector2<float> WildBoar::getSize() {
    return sf::Vector2f {64,40.5};
}

WildBoar::~WildBoar() = default;
void WildBoar::update(sf::Time time, Player &player) {
    healthLine.setSize(sf::Vector2f (part * health, healthLine.getSize().y));
    healthLine.setPosition(wild.getPosition().x, wild.getPosition().y - 15);
    float deltaTime = time.asSeconds();
    velocity = 50;
    horizontalVelocity += gravity * deltaTime;
    wild.move(velocity * deltaTime, horizontalVelocity);
    if(wild.getPosition().x < 0){
        velocity = 50;
    }if(wild.getPosition().y > 1600){
        velocity = -50;
    }
    if (velocity < 0) {
        wild.setTexture(ResourceManager::getTexture("../graphics/wildboar.png"));
    } else {
        wild.setTexture(ResourceManager::getTexture("../graphics/0wildboarLeft.png"));
    }

    float distanceToPlayerX = player.getPosition().x - wild.getPosition().x;
    float distanceToPlayerY = player.getPosition().y - wild.getPosition().y;
    if (std::abs(distanceToPlayerX) < 70 and std::abs(distanceToPlayerY) < 70 ) {
        followingPlayer = true;
        velocity = (distanceToPlayerX > 0) ? 50 : -50;
    } else if (std::abs(distanceToPlayerX) < 100 and std::abs(distanceToPlayerY) < 100 ) {
        followingPlayer = false;
    }
    if (!followingPlayer && std::abs(initialPositionX - wild.getPosition().x) > 250) {
        velocity *= -1;
    }
}

void WildBoar::setPosition(float d, float d1) {
    wild.setPosition(d,d1);
}

void WildBoar::setVerticalVelocity(int i) {
    horizontalVelocity = i;
}

void WildBoar::setVelocity(int i) {
//    velocity = i;
}

void WildBoar::setHealth(int i) {
    health = i;
}

int WildBoar::getHealth() {
    return health;
}
