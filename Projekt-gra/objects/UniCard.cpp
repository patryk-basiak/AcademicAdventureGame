//
// Created by UseR on 22.05.2024.
//

#include "UniCard.h"

void UniCard::collision(Player &player) {
    ;
}

void UniCard::setPosition(float x, float y) {
    card.setPosition(x,y);
}

void UniCard::draw(sf::RenderWindow &window) {
    window.draw(card);
}


sf::Vector2<float> UniCard::getSize() {
    return sf::Vector2f {32,32};
}

bool UniCard::isStackable() const {
    return Stackable;
}

std::unique_ptr<Collectable> UniCard::clone() const {
    return Collectable::clone();
}

int UniCard::getId() {
    return index;
}
