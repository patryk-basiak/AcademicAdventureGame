//
// Created by UseR on 07.06.2024.
//

#include "Grass.h"
#include "fmt/core.h"

void Grass::collision(Player &player, sf::RenderWindow &window) {
    player.setPosition(player.getPosition().x, grass.getPosition().y - player.getSize()[1] - 0.18);
    player.setVerticalVelocity(0);
}

sf::Vector2<float> Grass::getPosition() {
    return grass.getPosition();
}

sf::Vector2<float> Grass::getSize() {
    return sf::Vector2f {(float)grass.getTexture()->getSize().x * grass.getScale().x, (float)grass.getTexture()->getSize().y * grass.getScale().y};
}

void Grass::update() {
    ;
}

void Grass::draw(sf::RenderWindow &window) const {
    window.draw(grass);
}
