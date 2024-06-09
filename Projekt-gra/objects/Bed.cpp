//
// Created by UseR on 18.05.2024.
//

#include "Bed.h"
#include "fmt/core.h"

void Bed::collision(Player &player, sf::RenderWindow &window) {
    player.setPosition(player.getPosition().x, bed.getPosition().y - player.getSize()[1]);
    player.setVerticalVelocity(0);
}

Bed::~Bed() =default;

void Bed::draw(sf::RenderWindow &window) const {
    window.draw(bed);
}

void Bed::collisionRight(Player &player, sf::RenderWindow &window) {
    player.setVelocity(0);
    player.setPosition(bed.getPosition().x + this->getSize().x, player.getPosition().y);
}

void Bed::collisionLeft(Player &player, sf::RenderWindow &window) {
    player.setVelocity(0);
    player.setPosition(bed.getPosition().x - player.getSize()[0], player.getPosition().y);
}

void Bed::collisionBottom(Player &player, sf::RenderWindow &window) {
    player.setVerticalVelocity(0);
    player.setPosition(player.getPosition().x, bed.getPosition().y + this->getSize().y);
}

sf::Vector2<float> Bed::getPosition() {
    return bed.getPosition();
}

sf::Vector2<float> Bed::getSize() {
    return sf::Vector2f {(float)bed.getTexture()->getSize().x * bed.getScale().x, (float)bed.getTexture()->getSize().y * bed.getScale().y};
}
