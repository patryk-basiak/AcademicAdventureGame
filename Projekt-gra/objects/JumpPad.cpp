//
// Created by UseR on 18.04.2024.
//
#include <iostream>
#include "jumpPad.h"
#include "../Player.h"
#include "fmt/core.h"


void JumpPad::collision(Player& player, sf::RenderWindow &window){
//    player.setPosition(player.getPosition().x, jumpPad.getPosition().y - player.getSize()[1]);
    player.setVerticalVelocity(-400);
}

sf::Vector2<float> JumpPad::getPosition() {
    return jumpPad.getPosition();
}

sf::Vector2<float> JumpPad::getSize() {
    return sf::Vector2f {(float)jumpPad.getTexture()->getSize().x * jumpPad.getScale().x, (float)jumpPad.getTexture()->getSize().y * jumpPad.getScale().y};
}

void JumpPad::draw(sf::RenderWindow &window) const {
    window.draw(jumpPad);
}

void JumpPad::update() {

}

