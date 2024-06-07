
#include "stone.h"

void Stone::collision(Player &player, sf::RenderWindow &window) {
    player.setPosition(player.getPosition().x, stone.getPosition().y - player.getSize()[1] - 0.18);
    player.setVerticalVelocity(0);
}

sf::Vector2<float> Stone::getPosition() {
    return stone.getPosition();
}

sf::Vector2<float> Stone::getSize() {
    return sf::Vector2f {(float)stone.getTexture()->getSize().x * stone.getScale().x, (float)stone.getTexture()->getSize().y * stone.getScale().y};
}

void Stone::update() {
    ;
}

void Stone::draw(sf::RenderWindow &window) const {
    window.draw(stone);
}
