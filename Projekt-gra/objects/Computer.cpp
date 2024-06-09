//
// Created by UseR on 18.05.2024.
//

#include "Computer.h"
#include "fmt/core.h"
#include "../Settings.h"
#include <iostream>
#include <chrono>
#include <thread>

void Computer::collision(Player &player, sf::RenderWindow& window) {
    if (!inUse) {
        window.draw(text);
    }
    coll = true;
}


void Computer::update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time time, sf::Time deltatime) {
    if(coll){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            if(time.asSeconds() - lastUsed > 2) {
                if (inUse) {
                    movable = true;
                    inUse = false;
                } else {
                    movable = false;
                    inUse = true;
                }
            }
            lastUsed = time.asSeconds();
        }
    }

    if(inUse){
        player.hide();
    }
    else{
        player.showPlayer();
    }
    for(auto &e: icons){
        e->update(window);
    }
    coll = false;

}

void Computer::draw(sf::RenderWindow &window) {
    window.draw(computer);
    if(inUse){
        window.draw(screen);
        window.draw(wallpaper);
        for(auto &e: icons){
            e->draw(window);
        }
        for(auto &e: icons){
            if(e->isActive()){
                e->drawApp(window);
            }
        }
    }
}

bool Computer::getStatus() {
    return this->inUse;
}

Computer::~Computer() {

}

sf::Vector2<float> Computer::getPosition() {
    return this->computer.getPosition();
}

sf::Vector2<float> Computer::getSize() {
    return sf::Vector2<float>{size[0], size[1] };
}

void Computer::collisionRight(Player &player, sf::RenderWindow &window) {
    if (!inUse) {
        window.draw(text);
    }
    coll = true;
}

void Computer::collisionLeft(Player &player, sf::RenderWindow &window) {
    if (!inUse) {
        window.draw(text);
    }
    coll = true;
}

void Computer::collisionBottom(Player &player, sf::RenderWindow &window) {
    if (!inUse) {
        window.draw(text);
    }
    coll = true;
}
