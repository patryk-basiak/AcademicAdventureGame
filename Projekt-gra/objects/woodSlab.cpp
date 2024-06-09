//
// Created by UseR on 07.06.2024.
//

#include "woodSlab.h"
void WoodSlab::collision(Player &player, sf::RenderWindow &window) {
    player.setPosition(player.getPosition().x, woodSlab.getPosition().y - player.getSize()[1]);
    player.setVerticalVelocity(0);
}

sf::Vector2<float> WoodSlab::getPosition() {
    return woodSlab.getPosition();
}

sf::Vector2<float> WoodSlab::getSize() {
    return sf::Vector2f {(float)woodSlab.getTexture()->getSize().x * woodSlab.getScale().x, (float)woodSlab.getTexture()->getSize().y * woodSlab.getScale().y};
}

void WoodSlab::update() {
    ;
}

void WoodSlab::draw(sf::RenderWindow &window) const {
    window.draw(woodSlab);
}
void WoodSlab::collisionBottom(Player &player, sf::RenderWindow &window) {
    player.setVerticalVelocity(0);
    player.setPosition(player.getPosition().x, woodSlab.getPosition().y + this->getSize().y);
}
