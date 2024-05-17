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
    this->pistol.setPosition(2000,2000);
}

void Pistol::usage() {
    fmt::println("pistol was used");
    this->am.push_back(1);
}

void Pistol::update(sf::RenderWindow& window){
    for(auto i : am){
        if(i == 1){
            auto ammoTemp = sf::RectangleShape();
            ammoTemp.setPosition(80,80);
            ammoTemp.setSize(sf::Vector2f(20,20));
            ammoTemp.setFillColor(sf::Color::Green);
            this->ammo.push_back(ammoTemp);
        }
    }
}

void Pistol::draw(sf::RenderWindow &window) {
    window.draw(pistol);
    fmt::println("{}", am.size());
    if(!ammo.empty()){
        for (auto const &e: ammo) {
            window.draw(e);
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






