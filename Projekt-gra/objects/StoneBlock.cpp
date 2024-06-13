#include "StoneBlock.h"
#include "fmt/core.h"

void StoneBlock::collision(Player &player, sf::RenderWindow &window) {
    player.setPosition(player.getPosition().x, stoneBlock.getPosition().y - player.getSize()[1] - 0.18);
    player.setVerticalVelocity(0);
}

sf::Vector2<float> StoneBlock::getPosition() {
    return stoneBlock.getPosition();
}

sf::Vector2<float> StoneBlock::getSize() {
    return sf::Vector2f {(float)stoneBlock.getTexture()->getSize().x * stoneBlock.getScale().x, (float)stoneBlock.getTexture()->getSize().y * stoneBlock.getScale().y};
}

void StoneBlock::update() {
    ;
}

void StoneBlock::draw(sf::RenderWindow &window) const {
    window.draw(stoneBlock);
}
