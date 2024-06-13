

#include "Glass.h"
#include "fmt/core.h"

void Glass::collision(Player &player, sf::RenderWindow &window) {
    player.setPosition(player.getPosition().x, glass.getPosition().y - player.getSize()[1] - 0.18);
    player.setVerticalVelocity(0);
}

sf::Vector2<float> Glass::getPosition() {
    return glass.getPosition();
}

sf::Vector2<float> Glass::getSize() {
    return sf::Vector2f {(float)glass.getTexture()->getSize().x * glass.getScale().x, (float)glass.getTexture()->getSize().y * glass.getScale().y};
}

void Glass::update() {
    ;
}

void Glass::draw(sf::RenderWindow &window) const {
    window.draw(glass);
}
