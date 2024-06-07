//
// Created by UseR on 07.06.2024.
//

#include "Dirt.h"
#include "fmt/core.h"

void Dirt::collision(Player &player, sf::RenderWindow &window) {
    player.setPosition(player.getPosition().x, dirt.getPosition().y - player.getSize()[1] - 0.18);
    player.setVerticalVelocity(0);
}

sf::Vector2<float> Dirt::getPosition() {
    return dirt.getPosition();
}

sf::Vector2<float> Dirt::getSize() {
    return sf::Vector2f {(float)dirt.getTexture()->getSize().x * dirt.getScale().x, (float)dirt.getTexture()->getSize().y * dirt.getScale().y};
}

void Dirt::update() {
    ;
}

void Dirt::draw(sf::RenderWindow &window) const {
    window.draw(dirt);
}
