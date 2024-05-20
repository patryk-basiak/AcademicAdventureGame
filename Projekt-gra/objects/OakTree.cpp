//
// Created by UseR on 20.05.2024.
//

#include "OakTree.h"

void OakTree::draw(sf::RenderWindow &window) const {
    window.draw(wood);
}

void OakTree::collision(Player &player, sf::RenderWindow &window) {
    Wall::collision(player, window);
}

OakTree::~OakTree() = default;
