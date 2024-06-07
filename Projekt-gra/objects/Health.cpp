//
// Created by UseR on 04.06.2024.
//

#include "Health.h"

void Health::setPosition(float x, float y) {
   health.setPosition(x,y);
}

void Health::draw(sf::RenderWindow &window) {
    window.draw(health);
}

sf::Vector2<float> Health::getSize() {
    return sf::Vector2f {30,30};
}

bool Health::isStackable() const {
    return Stackable;
}

int Health::getId() {
    return id;
}

bool Health::isOneTimeUse() {
    return OneTimeUse;
}

void Health::usage(Player &player) {
    player.setHealth(player.getHealth() + 1);
}
