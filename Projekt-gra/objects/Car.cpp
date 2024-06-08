//
// Created by UseR on 05.06.2024.
//

#include "Car.h"
#include "fmt/core.h"

Car::~Car() = default;

sf::Vector2<float> Car::getSize() {
    return sf::Vector2f {(float)car.getTexture()->getSize().x*car.getScale().x,(float)car.getTexture()->getSize().y* car.getScale().y};
}
sf::Vector2<float> Car::getPosition()
{
    return car.getPosition();
}

void Car::collision(Player &player, sf::RenderWindow &window) {
    fmt::println("collison with car");
    player.setPosition(player.getPosition().x, car.getPosition().y - player.getSize()[1] - 0.18);
    player.setVerticalVelocity(0);
}

void Car::draw(sf::RenderWindow &window) const {
    window.draw(car);
}

void Car::update() {
    ;
}

void Car::setPosition(float x, float y) {
    car.setPosition(x,y);
}


