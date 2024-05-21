//
// Created by UseR on 21.05.2024.
//

#include "OakLeaves.h"

void OakLeaves::collision(Player &player, sf::RenderWindow &window) {
    Wall::collision(player, window);
}

void OakLeaves::draw(sf::RenderWindow &window) const {
    window.draw(leaves);
}

OakLeaves::~OakLeaves() = default;