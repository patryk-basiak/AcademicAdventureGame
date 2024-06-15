//
// Created by UseR on 07.06.2024.
//

#include "Quartz.h"
void Quartz::collision(Player &player, sf::RenderWindow &window) {
    player.setPosition(player.getPosition().x, quartz.getPosition().y - player.getSize()[1] - 0.18);
    player.setVerticalVelocity(0);
}

sf::Vector2<float> Quartz::getPosition() {
    return quartz.getPosition();
}

sf::Vector2<float> Quartz::getSize() {
    return sf::Vector2f {(float)quartz.getTexture()->getSize().x * quartz.getScale().x, (float)quartz.getTexture()->getSize().y * quartz.getScale().y};
}

void Quartz::update() {
    ;
}

void Quartz::draw(sf::RenderWindow &window) const {
    window.draw(quartz);
}
