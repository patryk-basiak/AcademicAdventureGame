#include "Coin.h"
#include "fmt/core.h"
#include "../Equipment.h"

void Coin::collision(Player &player) {
    this->coin.setPosition(2000,2000);
    fmt::println("collision with coin");
}

void Coin::draw(sf::RenderWindow &window) {
    sf::Vector2 mouse = sf::Mouse::getPosition(window);
    if(mouse.x > coin.getPosition().x and mouse.x < coin.getPosition().x + this->getSize().x and
            mouse.y > coin.getPosition().x and mouse.y < coin.getPosition().y + this->getSize().y){
        window.draw(popUp);
    }

    window.draw(this->coin);
}


bool Coin::isStackable() const {
    return this->Stackable;
}


int Coin::getId() {
    return this->value;
}

void Coin::setPosition(float x, float y) {
    this->coin.setPosition(x,y);
}

sf::Vector2<float> Coin::getSize() {
    return sf::Vector2f{32,32};
}
