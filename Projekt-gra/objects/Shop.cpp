//
// Created by UseR on 05.06.2024.
//

#include "Shop.h"
#include "fmt/core.h"

void Shop::draw(sf::RenderWindow &window) {
    window.draw(shop);
    if(isOpen){

    }
}

sf::Vector2<float> Shop::getPosition() {
    return shop.getPosition();
}

std::vector<float> Shop::getSize() {
    return std::vector<float>{62.6, 57,4};
}

void Shop::update(sf::RenderWindow &window, Player &player, Equipment &eq) {
//    Interactable::update(window, player, eq);
}

void Shop::collision(Player &player, sf::RenderWindow &window) {
    if(!isOpen){
        window.draw(popUp);
    }
    fmt::println("collision with shop");
}

bool Shop::getStatus() {
    return isOpen;
}

Shop::~Shop() = default;
