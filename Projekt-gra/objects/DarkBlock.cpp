#include "DarkBlock.h"
#include "fmt/core.h"

void DarkBlock::collision(Player &player, sf::RenderWindow &window) {
    player.setPosition(player.getPosition().x, darkBlock.getPosition().y - player.getSize()[1] - 0.18);
    player.setVerticalVelocity(0);
}

sf::Vector2<float> DarkBlock::getPosition() {
    return darkBlock.getPosition();
}

sf::Vector2<float> DarkBlock::getSize() {
    return sf::Vector2f {(float)darkBlock.getTexture()->getSize().x * darkBlock.getScale().x, (float)darkBlock.getTexture()->getSize().y * darkBlock.getScale().y};
}

void DarkBlock::update() {
    ;
}

void DarkBlock::draw(sf::RenderWindow &window) const {
    window.draw(darkBlock);
}
