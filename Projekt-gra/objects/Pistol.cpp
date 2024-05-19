//
// Created by UseR on 18.04.2024.
//
#include <iostream>
#include "jumpPad.h"
#include "../Player.h"
#include "Pistol.h"
#include "../Equipment.h"
#include <fmt/core.h>


// constructor created in Pistol.h file


void Pistol::shot() {
    ;
}

void Pistol::collision(Player& player) {

}

void Pistol::usage() {
    fmt::println("pistol was used");
    if(ammunition > 0){
        auto ammoTemp = sf::RectangleShape();
        ammoTemp.setPosition(this->pistol.getPosition().x + 1,this->pistol.getPosition().y);
        ammoTemp.setSize(sf::Vector2f(20,20));
        ammoTemp.setFillColor(sf::Color::Green);
        this->ammo.push_back(ammoTemp);
        ammunition--;
    }
    else{
        fmt::println("out of ammo");
    }

}

void Pistol::update(sf::RenderWindow& window){

}

void Pistol::draw(sf::RenderWindow &window) {
    window.draw(pistol);
    if(!ammo.empty()){
        for (auto &e: ammo) {
            window.draw(e);
            e.setPosition(e.getPosition().x + 0.5, e.getPosition().y);
//            e.setPosition(e.getPosition().x,e.getPosition().y +1);
        }
    }

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






