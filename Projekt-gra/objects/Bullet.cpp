//
// Created by UseR on 10.05.2024.
//

#include "Bullet.h"

void Bullet::setPosition(float x, float y) {
    bullet.setPosition(x,y);
}

void Bullet::draw(sf::RenderWindow &window) {
    window.draw(bullet);
}

void Bullet::update(sf::RenderWindow &window, Player& player) {
    bullet.setPosition(bullet.getPosition().x + velocity*direction, bullet.getPosition().y);
}

bool Bullet::isStackable() const {
    return false;
}

int Bullet::getId() {
    return id;
}


void Bullet::collision(Player &player) {
    ;
}

std::vector<sf::RectangleShape> Bullet::getAmmoList() {
    return std::vector<sf::RectangleShape>();
}

sf::FloatRect Bullet::getGlobalBounds() {
    return this->bullet.getGlobalBounds();
}
