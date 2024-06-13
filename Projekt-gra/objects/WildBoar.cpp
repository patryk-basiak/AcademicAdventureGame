#include "WildBoar.h"
#include "fmt/core.h"
#include "../ThrowableContainer.h"

void WildBoar::draw(sf::RenderWindow &window) {
    if (velocity < 0) {
        wild.setTexture(ResourceManager::getTexture("../graphics/wildboar.png"));
    } else {
        wild.setTexture(ResourceManager::getTexture("../graphics/0wildboarLeft.png"));
    }
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

    if(wild.getPosition().x < 10){
        velocity = 50;
    }if(wild.getPosition().x > 1550){
        velocity = -50;
    }
    float distanceToPlayerX = player.getPosition().x - wild.getPosition().x;
    float distanceToPlayerY = player.getPosition().y - wild.getPosition().y;
    if (std::abs(distanceToPlayerX) < 150 and std::abs(distanceToPlayerY) < 64 ) {
        followingPlayer = true;
        velocity = (distanceToPlayerX > 0) ? 50 : -50;
    }
    else if (std::abs(distanceToPlayerX) > 200){
        followingPlayer = false;
    }

    if(!followingPlayer){
        if(wantedPos > wild.getPosition().x){
            velocity =  50;
        }
        if(wantedPos <= wild.getPosition().x){
            velocity =  -50;
        }if(wantedPos == wild.getPosition().x){
            wantedPos = (float)destination(gen);
        }
    }
    horizontalVelocity += gravity * deltaTime;
    wild.move(velocity * deltaTime, horizontalVelocity);
}

void WildBoar::setPosition(float d, float d1) {
    wild.setPosition(d,d1);
}

void WildBoar::setVerticalVelocity(int i) {
    horizontalVelocity = i;
}

void WildBoar::setVelocity(int i) {
    velocity = i;
}

void WildBoar::setHealth(int i) {
    health = i;

}

int WildBoar::getHealth() {
    return health;
}
