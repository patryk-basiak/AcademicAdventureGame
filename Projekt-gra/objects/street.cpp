//
// Created by UseR on 07.06.2024.
//

#include "street.h"
void Street::collision(Player &player, sf::RenderWindow &window) {
    player.setPosition(player.getPosition().x, street.getPosition().y - player.getSize()[1] - 0.18);
    player.setVerticalVelocity(0);
}

sf::Vector2<float> Street::getPosition() {
    return street.getPosition();
}

sf::Vector2<float> Street::getSize() {
    return sf::Vector2f {(float)street.getTexture()->getSize().x * street.getScale().x, (float)street.getTexture()->getSize().y * street.getScale().y};
}

void Street::update() {
    ;
}

void Street::draw(sf::RenderWindow &window) const {
    window.draw(street);
}
