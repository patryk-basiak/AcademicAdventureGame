
#include "CarWinchItem.h"
#include "fmt/core.h"
#include "../Equipment.h"

void CarWinchItem::collision(Player &player) {
    this->carWinchItem.setPosition(2000,2000);
    fmt::println("collision with carWinchItem");
}

void CarWinchItem::draw(sf::RenderWindow &window) {
    sf::Vector2 mouse = sf::Mouse::getPosition(window);
    if(mouse.x > carWinchItem.getPosition().x and mouse.x < carWinchItem.getPosition().x + this->getSize().x and
       mouse.y > carWinchItem.getPosition().x and mouse.y < carWinchItem.getPosition().y + this->getSize().y){
        window.draw(popUp);
    }

    window.draw(this->carWinchItem);
}


bool CarWinchItem::isStackable() const {
    return this->Stackable;
}


int CarWinchItem::getId() {
    return this->value;
}

void CarWinchItem::setPosition(float x, float y) {
    if(!inUse) {
        this->carWinchItem.setPosition(x, y);
    }
}

sf::Vector2<float> CarWinchItem::getSize() {
    return sf::Vector2f{32,32};
}

void CarWinchItem::usage(Player &player) {
    fmt::println("carWinchUsed");
    carWinchItem.setPosition(10, 15);
    inUse = true;
}
