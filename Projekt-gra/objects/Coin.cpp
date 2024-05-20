#include "Coin.h"
#include "fmt/core.h"
#include "../Equipment.h"

void Coin::collision(Player &player) {
    this->coin.setPosition(2000,2000);
    fmt::println("collision with coin");
}

void Coin::draw(sf::RenderWindow &window) {
    window.draw(this->coin);
}

void Coin::usage() {
    Collectable::usage();
}

bool Coin::isStackable() const {
    return this->Stackable;
}

std::unique_ptr<Collectable> Coin::clone() const {
    return std::make_unique<Coin>(*this);
}

int Coin::getId() {
    return this->value;
}

void Coin::setPosition(float x, float y) {
    this->coin.setPosition(x,y);
}

sf::Vector2<float> Coin::getSize() {
    return sf::Vector2f{radius,radius};
}
