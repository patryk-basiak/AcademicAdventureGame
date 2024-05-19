//
// Created by UseR on 19.05.2024.
//

#include "HUD.h"

void HUD::draw(sf::RenderWindow &window, Equipment &eq, Player& player) {
    eq.update(window, player);
    window.draw(mission);

}

void HUD::update(Player &player) {
    //TODO health
}

void HUD::hideDebug() {
 //TODO
}

void HUD::showDebug() {
//TODO
}
