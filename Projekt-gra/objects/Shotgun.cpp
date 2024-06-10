//
// Created by UseR on 10.06.2024.
//

#include "Shotgun.h"
#include <iostream>
#include "../Player.h"
#include "Bullet.h"
#include "../ThrowableContainer.h"
#include <fmt/core.h>



void Shotgun::shot() {
    ;
}

void Shotgun::collision(Player& player) {

}

void Shotgun::usage(Player& player) {
    if(combat) {
        if (ammunition > 0) {
            if (ready) {
                int n = player.getFacingRight() ? 1: -1;
                ThrowableContainer::addItem(4,shotgun.getPosition().x +15*n,shotgun.getPosition().y - 10,n, 15, 15);
                ThrowableContainer::addItem(4,shotgun.getPosition().x + 15*n,shotgun.getPosition().y,n);
                ThrowableContainer::addItem(4,shotgun.getPosition().x + 15*n,shotgun.getPosition().y+10,n, -15, -15);
                Collectable::throwable.push_back(std::make_unique<Bullet>(shotgun.getPosition().x,shotgun.getPosition().y,n));
                ammunition -= 3;
                ready = false;
            } else {
                fmt::println("not ready to shot");
            }
        } else {
            fmt::println("out of ammo");
        }
    }

}

void Shotgun::update(sf::RenderWindow& window, Player& player){
    float currentTime = clock.getElapsedTime().asSeconds();
    if(!player.getFacingRight()){
        shotgun.setTexture(ResourceManager::getTexture("../graphics/shotgunReversed.png"));
    }
    else{
        shotgun.setTexture(ResourceManager::getTexture("../graphics/shotgun.png"));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) and ammunition <= 0) {
        fmt::println("reload started");
        reloading = true;
        reloadStart = clock.getElapsedTime().asSeconds();
    }
    if(reloading) {
        if (currentTime - reloadStart >= reloadTime) {
            fmt::println("reloaded");
            ammunition = 12;
            reloading = false;
        }
    }
    if(currentTime - lastShotTime >= shotCooldown){
        ready = true;
    }

}

void Shotgun::draw(sf::RenderWindow &window) {
    window.draw(shotgun);
}

bool Shotgun::isStackable() const {
    return this->Stackable;
}

int Shotgun::getId() {
    return this->ID;
}

void Shotgun::setPosition(float x, float y) {
    this->shotgun.setPosition(x,y);
}

std::vector<sf::RectangleShape> Shotgun::getAmmoList() {
    return this->ammo;
}






