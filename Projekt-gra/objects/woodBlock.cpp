//
// Created by UseR on 07.06.2024.
//

#include "woodBlock.h"
void WoodBlock::collision(Player &player, sf::RenderWindow &window) {
    player.setPosition(player.getPosition().x, woodBlock.getPosition().y - player.getSize()[1] - 0.18);
    player.setVerticalVelocity(0);
}

sf::Vector2<float> WoodBlock::getPosition() {
    return woodBlock.getPosition();
}

sf::Vector2<float> WoodBlock::getSize() {
    return sf::Vector2f {(float)woodBlock.getTexture()->getSize().x * woodBlock.getScale().x, (float)woodBlock.getTexture()->getSize().y * woodBlock.getScale().y};
}

void WoodBlock::update() {
    ;
}

void WoodBlock::draw(sf::RenderWindow &window) const {
    window.draw(woodBlock);
}
