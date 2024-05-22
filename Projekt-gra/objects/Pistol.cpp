#include <iostream>
#include "jumpPad.h"
#include "../Player.h"
#include "Pistol.h"
#include "../Equipment.h"
#include "Bullet.h"
#include <fmt/core.h>


// constructor created in Pistol.h file

void Pistol::shot() {
    ;
}

void Pistol::collision(Player& player) {

}

void Pistol::usage(Player& player) {
    if(combat) {
        if (ammunition > 0) {
            if (ready) {
                int n = player.getFacingRight() ? 1: -1;
                Collectable::throwable.push_back(std::make_shared<Bullet>(pistol.getPosition().x,pistol.getPosition().y,n));
                ammunition--;
                ready = false;
            } else {
                fmt::println("not ready to shot");
            }
        } else {
            fmt::println("out of ammo");
        }
    }

}

void Pistol::update(sf::RenderWindow& window){
    float currentTime = clock.getElapsedTime().asSeconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) and ammunition <= 0) {
        fmt::println("reload started");
        reloading = true;
        reloadStart = clock.getElapsedTime().asSeconds();
    }
    if(reloading) {
        if (currentTime - reloadStart >= reloadTime) {
            fmt::println("reloaded");
            ammunition = 3;
            reloading = false;
        }
    }
    if(currentTime - lastShotTime >= shotCooldown){
        ready = true;
    }

}

void Pistol::draw(sf::RenderWindow &window) {
    window.draw(pistol);
}

bool Pistol::isStackable() const {
    return this->Stackable;
}

std::unique_ptr<Collectable> Pistol::clone() const {
    return std::make_unique<Pistol>(*this);
}

int Pistol::getId() {
    return this->ID;
}

bool Pistol::operator==(const Collectable &other) const {
    fmt::println("hey");
    return this->ID == other.id;
}

bool Pistol::operator==(const Pistol &other) const {
    fmt::println("help");
    return this->ID == other.id;
}

void Pistol::setPosition(float x, float y) {
    this->pistol.setPosition(x,y);
}

std::vector<sf::RectangleShape> Pistol::getAmmoList() {
    return this->ammo;
}






