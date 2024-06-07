//
// Created by UseR on 07.06.2024.
//

#include "Brick.h"
void Brick::collision(Player &player, sf::RenderWindow &window) {
    player.setPosition(player.getPosition().x, brick.getPosition().y - player.getSize()[1] - 0.18);
    player.setVerticalVelocity(0);
}

sf::Vector2<float> Brick::getPosition() {
    return brick.getPosition();
}

sf::Vector2<float> Brick::getSize() {
    return sf::Vector2f {(float)brick.getTexture()->getSize().x * brick.getScale().x, (float)brick.getTexture()->getSize().y * brick.getScale().y};
}

void Brick::update() {
    ;
}

void Brick::draw(sf::RenderWindow &window) const {
    window.draw(brick);
}
