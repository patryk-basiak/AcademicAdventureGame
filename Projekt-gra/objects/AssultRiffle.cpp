//
// Created by UseR on 10.06.2024.
//

#include "AssultRiffle.h"
//
// Created by UseR on 10.06.2024.
//

#include <iostream>
#include "../Player.h"
#include "Bullet.h"
#include "../ThrowableContainer.h"
#include <fmt/core.h>



void AssultRiffle::shot() {
    ;
}

void AssultRiffle::collision(Player& player) {

}

void AssultRiffle::usage(Player& player) {
    if(combat) {
        if (ammunition > 0) {
            if (ready) {
                int n = player.getFacingRight() ? 1: -1;
                ThrowableContainer::addItem(4,  assultRifle.getPosition().x + 15*n , assultRifle.getPosition().y,n);\
                ammunition -= 1;
                ready = false;
            } else {
                fmt::println("not ready to shot");
            }
        } else {
            fmt::println("out of ammo");
        }
    }

}

void AssultRiffle::update(sf::RenderWindow& window, Player& player){
    float currentTime = clock.getElapsedTime().asSeconds();
    if(!player.getFacingRight()){
        assultRifle.setTexture(ResourceManager::getTexture("../graphics/akReversed.png"));
    }
    else{
        assultRifle.setTexture(ResourceManager::getTexture("../graphics/ak.png"));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) and ammunition <= 0) {
        fmt::println("reload started");
        reloading = true;
        reloadStart = clock.getElapsedTime().asSeconds();
    }
    if(reloading) {
        if (currentTime - reloadStart >= reloadTime - (float)(player.getIntelligence()/4)) {
            fmt::println("reloaded");
            ammunition = 30;
            reloading = false;
        }
    }
    if(currentTime - lastShotTime >= shotCooldown){
        ready = true;
    }

}

void AssultRiffle::draw(sf::RenderWindow &window) {
    window.draw(assultRifle);
}

bool AssultRiffle::isStackable() const {
    return this->Stackable;
}

int AssultRiffle::getId() {
    return this->ID;
}

void AssultRiffle::setPosition(float x, float y) {
    this->assultRifle.setPosition(x,y);
}

std::vector<sf::RectangleShape> AssultRiffle::getAmmoList() {
    return this->ammo;
}

std::string AssultRiffle::getInfo() {
    return "Ammunition " + std::to_string(ammunition);
}






