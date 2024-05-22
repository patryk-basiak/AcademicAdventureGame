//
// Created by UseR on 19.05.2024.
//

#include <cmath>
#include <utility>
#include "HUD.h"

void HUD::draw(sf::RenderWindow &window, Equipment &eq, Player& player) {

    if(dialogShow) {
        mess.draw(window);
    }
    window.draw(objective);
    if(decisionShow){
        decisionElement.draw(window);
        decisionElement.update(player, window); // TODO zrobic to w update

    }

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

}

bool HUD::dialogGet() const {
    return dialogShow;
}

void HUD::dialogSet(bool state) {
    dialogShow = state;
}

void HUD::setMessage(std::string newText) {
    mess.setText(std::move(newText));

}

void HUD::setObjective(std::string newObjective) {
    if(newObjective.size() > 25) {
        objective.setString("\tCurrent objective: \n" + std::move(newObjective));
    }else{
        objective.setString("\tCurrent objective: \n\t" + std::move(newObjective));
    }
}

void HUD::setDecision(std::vector<std::string> newDec, float x, float y) {
    decisionElement.setDecisions(newDec);
    decisionElement.setPosition(x,y);

}

void HUD::setDecisionVisibility(bool visible) {
    decisionShow = visible;
}

int HUD::getDecision() {
    return decisionElement.getDecision();
}
