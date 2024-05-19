//
// Created by UseR on 18.05.2024.
//

#include "Computer.h"
#include "fmt/core.h"
#include "../Settings.h"


void Computer::collision(Player &player, sf::RenderWindow& window) {
    fmt::println("collison with computer");
    sf::Event event = sf::Event();
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::F) {
                if (inUse) {
                    movable = false;
                    inUse = false;
                } else {
                    movable = true;
                    inUse = true;
                }
            }
        }
    }
}

void Computer::update(sf::RenderWindow& window) {
    for(auto &e: icons){
        e->update(window);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and inUse) {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        fmt::println("{} {}", pos.x, pos.y);
    }

}

void Computer::draw(sf::RenderWindow &window) {
    sf::Event event = sf::Event();
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::F) {
                if (inUse) {
                    movable = true;
                    inUse = false;
                } else {
                    movable = false;
                    inUse = true;
                }
            }
        }
    }
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

std::vector<float> Computer::getSize() {
    return size;
}
