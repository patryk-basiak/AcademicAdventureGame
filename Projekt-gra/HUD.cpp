//
// Created by UseR on 19.05.2024.
//

#include <cmath>
#include "HUD.h"

void HUD::draw(sf::RenderWindow &window, Equipment &eq, Player& player) {
    window.draw(mission);
//    lvlNumber.setString("Current lvl: " + std::to_string(current_Lvl))
if(debug) {
    window.draw(positionX);
    window.draw(positionY);
    window.draw(fps);
    window.draw(lvlNumber);
}
    window.draw(health);

}

void HUD::update(Player &player, FPS& fps1, int lvl) {
    positionX.setString("Position X:" + std::to_string(player.getPosition().x));
    positionY.setString("Position Y:" + std::to_string(player.getPosition().y));
    fps.setString("FPS: " + std::to_string((int) std::round(fps1.getFPS())));
    lvlNumber.setString("Current Lvl: " + std::to_string(lvl));
    health.setString("Health: " + std::to_string(player.getHealth()));
}

void HUD::hideDebug() {
     debug = false;
}

void HUD::showDebug() {
    debug = true;
}
