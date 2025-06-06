//
// Created by UseR on 19.05.2024.
//

#include <cmath>
#include <utility>
#include "HUD.h"
#include <iomanip>
#include <sstream>
void HUD::draw(sf::RenderWindow &window, Equipment &eq, Player& player) {

    if(dialogShow) {
        mess.draw(window);
    }
    window.draw(objective);
    if(decisionShow){
        decisionElement.draw(window);
        decisionElement.update(player, window); // TODO zrobic to w update

    }
if(finished){
    window.draw(endTime);
}
if(debug) {
    window.draw(positionX);
    window.draw(positionY);
    window.draw(fps);
    window.draw(lvlNumber);
    window.draw(roomAvail);
    window.draw(numberOfEnemies);
}
    window.draw(health);
    window.draw(timer);
    window.draw(itemInfo);
    itemInfo.setString(eq.getItemInfo());
}

void HUD::update(Player &player, FPS& fps1, int lvl, bool nextRoomAvailable, int numOfEnemies, float hours, float minutes ) {

    health.setString("Health: " + std::to_string(player.getHealth()));
    if(minutes > 10) {
        timer.setString("Time: " + std::to_string((int) std::round(((int) hours))) + ":" + std::to_string((int)std::round((int)minutes)));
    }else{
        timer.setString("Time: " + std::to_string((int) std::round(((int) hours))) + ":" + "0" + std::to_string((int)std::round((int)minutes)));
    }
    if(dialogShow) {
        mess.update(player);
    }
    if(debug) {
        numberOfEnemies.setString("Number of Enemies:" + std::to_string(numOfEnemies));
        positionX.setString("Position X:" + std::to_string(player.getPosition().x));
        positionY.setString("Position Y:" + std::to_string(player.getPosition().y));
        fps.setString("FPS: " + std::to_string((int) std::round(fps1.getFPS())));
        lvlNumber.setString("Current Lvl: " + std::to_string(lvl));
        roomAvail.setString("Next room available: " + std::to_string(nextRoomAvailable));
    }if(finished){
        endTime.setString("Minutes:" + std::to_string((int) std::round(((int) hours))) + " Seconds:" + std::to_string((int)std::round((int)minutes)));
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
    if(!visible){
        mousekeyListener = false;
    }else{
        mousekeyListener = true;
    }

}

int HUD::getDecision() {
    return decisionElement.getDecision();
}
