//
// Created by UseR on 23.04.2024.
//

#include "Collectable.h"
#include <fmt/core.h>
#include <iostream>

Collectable::Collectable(float x, float y, sf::Color color) {
    collect.setPosition(x,y);
    collect.setSize(sf::Vector2f(100.f,50.f));
    collect.setFillColor(color);
}
Collectable::Collectable(float x, float y, sf::Color color, float d, float d1) {
    collect.setPosition(x,y);
    collect.setSize(sf::Vector2f(d,d1));
    collect.setFillColor(color);
}
void Collectable::setPosition(float x, float y){
    collect.setPosition(x,y);

}
void Collectable::draw(sf::RenderWindow& window) {
    window.draw(collect);
}

void Collectable::reColor(sf::Color color){
    collect.setFillColor(color);
}
sf::FloatRect Collectable::getGlobalBounds(){
    return collect.getGlobalBounds();
}




sf::Vector2<float> Collectable::getPosition() {
    return collect.getPosition();
}

void Collectable::collision(Player& player) {
    fmt::println("base");
}

void Collectable::usage() {

}

void Collectable::update(sf::RenderWindow &window) {

}

bool Collectable::isStackable() const {
    return this->Stackable;
}

bool Collectable::operator==(const Collectable &other) const {
    return this->id == other.id;
}

std::unique_ptr<Collectable> Collectable::clone() const {
    return std::make_unique<Collectable>(*this);
}

int Collectable::getId() {
    return this->id;
}

std::vector<sf::RectangleShape> Collectable::getAmmoList() {
    return std::vector<sf::RectangleShape>();
}


