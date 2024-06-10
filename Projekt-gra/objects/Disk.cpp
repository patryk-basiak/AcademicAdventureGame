//
// Created by UseR on 09.06.2024.
//

#include "Disk.h"
#include "fmt/core.h"
#include "../Equipment.h"
#include "../ThrowableContainer.h"

void Disk::collision(Player &player) {
    this->disk.setPosition(2000,2000);
    fmt::println("collision with disk");
}

void Disk::draw(sf::RenderWindow &window) {
    sf::Vector2 mouse = sf::Mouse::getPosition(window);
    if(mouse.x > disk.getPosition().x and mouse.x < disk.getPosition().x + this->getSize().x and
       mouse.y > disk.getPosition().x and mouse.y < disk.getPosition().y + this->getSize().y){
        window.draw(popUp);
    }

    window.draw(this->disk);
}


bool Disk::isStackable() const {
    return this->Stackable;
}


int Disk::getId() {
    return this->value;
}

void Disk::setPosition(float x, float y) {
    if(!inUse) {
        this->disk.setPosition(x, y);
    }
}

sf::Vector2<float> Disk::getSize() {
    return sf::Vector2f{(float)disk.getTexture()->getSize().x*disk.getScale().x, (float)disk.getTexture()->getSize().y*disk.getScale().y};
}

void Disk::usage(Player &player) {
}
bool Disk::isOneTimeUse() {
    return true;
}
