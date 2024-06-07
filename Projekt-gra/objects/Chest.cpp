//
// Created by UseR on 20.05.2024.
//

#include "Chest.h"
#include "fmt/core.h"
#include "../Settings.h"

void Chest::draw(sf::RenderWindow &window) {
    window.draw(chestTexture);
    if(isOpen){
        window.draw(content);
        for(auto &item: itemsInside){
            item.first->draw(window);
        }
    }
}

sf::Vector2<float> Chest::getPosition() {
    return chestTexture.getPosition();
}

sf::Vector2<float> Chest::getSize() {
    return sf::Vector2<float>{size[0], size[1]};
}

void Chest::update(sf::RenderWindow &window, Player &player, Equipment& eq, sf::Time time) {
    if(stage_1){
        active = true;
    }
    sf::Vector2 mouse = sf::Mouse::getPosition(window);
    std::map<std::shared_ptr<Collectable>, int>::iterator();
    for(auto it = itemsInside.begin(); it!= itemsInside.end(); it++){
        if((*it).first->getPosition().x < mouse.x and (*it).first->getPosition().x + (*it).first->getSize().x > mouse.x and
                (*it).first->getPosition().y < mouse.y and (*it).first->getPosition().y + (*it).first->getSize().y > mouse.y){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                for(int i = 0; i < (*it).second; ++i) {
                    eq.addItem((*it).first->getId());
                }
                itemsInside.erase(it);
                


            }
        }
    }
}

void Chest::collision(Player &player, sf::RenderWindow &window) {
    if(active and !isOpen){
        window.draw(popUp);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) and stage_1){
        fmt::println("wardrobe open");
        if(!isOpen){
            isOpen = true;
            movable = false;
    }
        else{
            isOpen = false;
            movable = true;
        }
    }
}

bool Chest::getStatus() {
    return isOpen;
}

Chest::~Chest() = default;
