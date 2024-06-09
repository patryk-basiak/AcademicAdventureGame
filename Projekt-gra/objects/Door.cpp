//
// Created by UseR on 18.05.2024.
//

 #include "Door.h"
#include "fmt/core.h"



void Door::setStatus(bool status) {
    isOpen = status;
}

bool Door::status() const {
    return isOpen;
}

void Door::collisionLeft(Player &player, sf::RenderWindow &window) {
    if(!isOpen){
        player.setVelocity(0);
        player.setPosition(door.getPosition().x - player.getSize()[0], player.getPosition().y);
    }
    Interactable::setColl(true);
}

void Door::collisionRight(Player &player, sf::RenderWindow &window) {
    if(!isOpen) {
        player.setVelocity(0);
        player.setPosition(door.getPosition().x + this->getSize().x, player.getPosition().y);
    }
    Interactable::setColl(true);
}

sf::Vector2<float> Door::getSize() {
    return sf::Vector2f {(float)door.getTexture()->getSize().x * door.getScale().x, (float)door.getTexture()->getSize().y * door.getScale().y};
}

void Door::draw(sf::RenderWindow &window)  {
    window.draw(door);
}

sf::Vector2<float> Door::getPosition() {
    return door.getPosition();
}

void Door::update(sf::RenderWindow &window, Player &player, Equipment &eq,  sf::Time deltatime, sf::Time realDeltatime) {
    if(Interactable::coll) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            fmt::println("hello");
            if (deltatime.asSeconds() - lastUsed > 2) {
                fmt::println("inside");
                if (isOpen) {
                    isOpen = false;
                    fmt::println("door closed");
                } else {
                    isOpen = true;
                }
            }
            lastUsed = deltatime.asSeconds();
        }
    }
    if(isOpen){
        door.setTexture(ResourceManager::getTexture("../graphics/doorOpen.png"));
        door.setScale(0.3,(float)128/door.getTexture()->getSize().y);
    }if(!isOpen){
        door.setTexture(ResourceManager::getTexture("../graphics/doorClosed.png"));
        door.setScale(0.1,(float)128/door.getTexture()->getSize().y);
    }
}

Door::~Door() =default;
