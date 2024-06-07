//
// Created by UseR on 07.06.2024.
//

#include "CarWinch.h"

void CarWinch::draw(sf::RenderWindow &window) {
    window.draw(winch);

}

sf::Vector2<float> CarWinch::getPosition() {
    return winch.getPosition();
}

std::vector<float> CarWinch::getSize() {
    return std::vector<float>{0,0}; // TODO
}

void CarWinch::update(sf::RenderWindow &window, Player &player, Equipment &eq) {
    Interactable::update(window, player, eq);
}

void CarWinch::collision(Player &player, sf::RenderWindow &window) {
    Interactable::collision(player, window);
}

bool CarWinch::getStatus() {
    return isPlaced;
}

CarWinch::~CarWinch() = default;