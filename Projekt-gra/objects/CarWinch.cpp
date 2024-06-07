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

sf::Vector2<float> CarWinch::getSize() {
    return sf::Vector2<float>{0,0}; // TODO
}

void CarWinch::update(sf::RenderWindow &window, Player &player, Equipment &eq, sf::Time time) {
    Interactable::update(window, player, eq, time);
}

void CarWinch::collision(Player &player, sf::RenderWindow &window) {
    Interactable::collision(player, window);
}

bool CarWinch::getStatus() {
    return isPlaced;
}

CarWinch::~CarWinch() = default;