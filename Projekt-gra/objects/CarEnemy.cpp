//
// Created by UseR on 07.06.2024.
//

#include "CarEnemy.h"
void CarEnemy::draw(sf::RenderWindow &window) {
    window.draw(car);

}

sf::FloatRect CarEnemy::getGlobalBounds() {
    return car.getGlobalBounds();
}


void CarEnemy::collision(Player &player) {
    player.setHealth(player.getHealth() - 1);
}

sf::Vector2<float> CarEnemy::getPosition() {
    return car.getPosition();
}

sf::Vector2<float> CarEnemy::getSize() {
    return sf::Vector2f {(float)car.getTexture()->getSize().x * car.getScale().x, (float)car.getTexture()->getSize().y * car.getScale().y};
}

CarEnemy::~CarEnemy() = default;
void CarEnemy::update(sf::Time time, Player &player) {

    float deltaTime = time.asSeconds();

    horizontalVelocity += gravity * deltaTime;
    car.move(velocity * deltaTime, horizontalVelocity);
    if(car.getPosition().x < 0 - this->getSize().x){
        car.setPosition(1600, car.getPosition().y);
    }
}

void CarEnemy::setPosition(float d, float d1) {
    car.setPosition(d,d1);
}

void CarEnemy::setVerticalVelocity(int i) {
    horizontalVelocity = i;
}
