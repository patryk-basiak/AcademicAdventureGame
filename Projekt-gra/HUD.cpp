//
// Created by UseR on 19.05.2024.
//

#include <cmath>
#include "HUD.h"

void HUD::draw(sf::RenderWindow &window, Equipment &eq, Player& player) {
    window.draw(mission);
    if(dialogShow) {
        mess.draw(window);
    }
//    lvlNumber.setString("Current lvl: " + std::to_string(current_Lvl))


if(debug) {
    window.draw(positionX);
    window.draw(positionY);
    window.draw(fps);
    window.draw(lvlNumber);
    window.draw(roomAvail);
}
    window.draw(health);

}

void HUD::update(Player &player, FPS& fps1, int lvl, bool nextRoomAvailable ) {
    health.setString("Health: " + std::to_string(player.getHealth()));
    if(dialogShow) {
        mess.update(player);
    }
    if(debug) {
        positionX.setString("Position X:" + std::to_string(player.getPosition().x));
        positionY.setString("Position Y:" + std::to_string(player.getPosition().y));
        fps.setString("FPS: " + std::to_string((int) std::round(fps1.getFPS())));
        lvlNumber.setString("Current Lvl: " + std::to_string(lvl));
        roomAvail.setString("Next room available: " + std::to_string(nextRoomAvailable));
    }
}
void HUD::hideDebug() {
     debug = false;
}

void HUD::showDebug() {
    debug = true;
}

void HUD::lvls(int roomlvl) {

    if(roomlvl == 0 ){
        float currentTime = clock.getElapsedTime().asSeconds();
        if(currentTime >= 6){
            dialogShow = false;

            // choose option
        }
        if(currentTime >= 12){
            mess.setText("Should I go on a walk or ride a bike with friends?");
            dialogShow = true;
        }
        if(currentTime >= 16){
            dialogShow = false;

        }
    }
}
