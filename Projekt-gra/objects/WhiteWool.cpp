#include "WhiteWool.h"
#include "fmt/core.h"

void WhiteWool::collision(Player &player, sf::RenderWindow &window) {
    player.setPosition(player.getPosition().x, whiteWool.getPosition().y - player.getSize()[1] - 0.18);
    player.setVerticalVelocity(0);
}

sf::Vector2<float> WhiteWool::getPosition() {
    return whiteWool.getPosition();
}

sf::Vector2<float> WhiteWool::getSize() {
    return sf::Vector2f {(float)whiteWool.getTexture()->getSize().x * whiteWool.getScale().x, (float)whiteWool.getTexture()->getSize().y * whiteWool.getScale().y};
}

void WhiteWool::update() {
    ;
}

void WhiteWool::draw(sf::RenderWindow &window) const {
    window.draw(whiteWool);
}
