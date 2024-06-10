//
// Created by UseR on 10.05.2024.
//
#include <cmath>
#include "Bullet.h"

void Bullet::setPosition(float x, float y) {
    bullet.setPosition(x,y);
}

void Bullet::draw(sf::RenderWindow &window) {
    window.draw(bullet);
}

void Bullet::update(sf::RenderWindow &window, Player& player) {
    if(type == 2){
        bullet.setPosition(bullet.getPosition().x + (cos(degX*M_PI/180.0)  *  velocity*direction), bullet.getPosition().y + sin(degY*M_PI/180.0)*(velocity));
    }if(type == 0){
        bullet.setPosition(bullet.getPosition().x + (0.5*direction), bullet.getPosition().y);
    }

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
