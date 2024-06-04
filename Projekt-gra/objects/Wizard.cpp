//
// Created by UseR on 05.06.2024.
//

#include "Wizard.h"
#include <fmt/core.h>

void Wizard::draw(sf::RenderWindow &window)
{
    window.draw(wizard);
}

sf::FloatRect Wizard::getGlobalBounds() {
    return wizard.getGlobalBounds();
}

void Wizard::update(sf::Time time, Player &player) {

}

void Wizard::collision(Player &player) {
    fmt::println("collison with wizard");
}

sf::Vector2<float> Wizard::getPosition() {
    return Entity::getPosition();
}

sf::Vector2<float> Wizard::getSize() {
    return Entity::getSize();
}

void Wizard::setPosition(float d, float d1) {
    wizard.setPosition(d,d1);
}
void Wizard::setVerticalVelocity(int i){

}

bool Wizard::isFriendly() {
    return friendly;
}

Wizard::~Wizard() = default;