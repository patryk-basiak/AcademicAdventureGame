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
        window.draw(number);
    }
    if(active and !isOpen and stage_1){
        window.draw(popUp);
    }
}

sf::Vector2<float> Chest::getPosition() {
    return chestTexture.getPosition();
}

sf::Vector2<float> Chest::getSize() {
    return sf::Vector2<float>{chestTexture.getTexture()->getSize().x * chestTexture.getScale().x, chestTexture.getTexture()->getSize().y * chestTexture.getScale().y};
}

void Chest::update(sf::RenderWindow &window, Player &player, Equipment& eq, sf::Time time, sf::Time deltatime) {
    if(stage_1){
        active = true;
    }
    sf::Vector2 mouse = sf::Mouse::getPosition(window);
    for(auto it = itemsInside.begin(); it!= itemsInside.end(); it++){
        if((*it).first->getPosition().x < mouse.x and (*it).first->getPosition().x + (*it).first->getSize().x > mouse.x and
                (*it).first->getPosition().y < mouse.y and (*it).first->getPosition().y + (*it).first->getSize().y > mouse.y){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                for(int i = 0; i < (*it).second; ++i) {
                    eq.addItem((*it).first->getId());
                }
                itemsInside.erase(it); // na macu to nie dziala
                it--;
                number.setString("");
                return;

            }
        }
    }
    if (player.getPosition().x - chestTexture.getPosition().x < 128 and
        player.getPosition().x - chestTexture.getPosition().x > 0 and
        std::abs(player.getPosition().y - chestTexture.getPosition().y) < 80 and stage_1) {
        active = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            if (time.asSeconds() - lastUsed > 0.5) {
                if (isOpen) {
                    isOpen = false;
                } else {
                    isOpen = true;
                }
            }
            lastUsed = time.asSeconds();
        }
    } else {
        active = false;
    }
}

void Chest::collision(Player &player, sf::RenderWindow &window) {
    
    
}

bool Chest::getStatus() {
    return isOpen;
}

Chest::~Chest() = default;
