//
// Created by UseR on 18.05.2024.
//

#include "Computer.h"
#include "fmt/core.h"
#include "../Settings.h"


void Computer::collision(Player &player, sf::RenderWindow& window) {
    if(!inUse) {
        window.draw(text);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
                if (inUse) {
                    movable = true;
                    inUse = false;
                } else {
                    movable = false;
                    inUse = true;
                }
            }
        }



void Computer::update(sf::RenderWindow& window, Player& player, Equipment& eq) {
    if(inUse){
        player.hide();
    }
    else{
        player.showPlayer();
    }
    for(auto &e: icons){
        e->update(window);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and inUse) {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        fmt::println("{} {}", pos.x, pos.y);
    }

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

std::vector<float> Computer::getSize() {
    return size;
}
