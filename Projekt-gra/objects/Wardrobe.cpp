//
// Created by UseR on 20.05.2024.
//

#include "Wardrobe.h"
#include "fmt/core.h"
#include "../Settings.h"

void Wardrobe::draw(sf::RenderWindow &window) {
    window.draw(wardrobeTexture);
    if(isOpen){
        window.draw(shelf);
        for(auto &item: itemsInside){
            item.first->draw(window);
        }
    }
}

sf::Vector2<float> Wardrobe::getPosition() {
    return wardrobeTexture.getPosition();
}

sf::Vector2<float> Wardrobe::getSize() {
    return sf::Vector2f {size[0], size[1]};
}

void Wardrobe::update(sf::RenderWindow &window, Player &player, Equipment& eq, sf::Time time, sf::Time deltatime) {
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
                stage_2 = true;



            }
        }
    }
}

void Wardrobe::collision(Player &player, sf::RenderWindow &window) {
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

bool Wardrobe::getStatus() {
    return isOpen;
}

Wardrobe::~Wardrobe() = default;
