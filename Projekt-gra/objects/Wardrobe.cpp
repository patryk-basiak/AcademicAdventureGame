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
    if(active and !isOpen and stage_1){
        window.draw(popUp);
    }

}

sf::Vector2<float> Wardrobe::getPosition() {
    return wardrobeTexture.getPosition();
}

sf::Vector2<float> Wardrobe::getSize() {
    return sf::Vector2f {wardrobeTexture.getTexture()->getSize().x * wardrobeTexture.getScale().x, wardrobeTexture.getTexture()->getSize().y * wardrobeTexture.getScale().y};
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
    if (player.getPosition().x - wardrobeTexture.getPosition().x < 128 and
        player.getPosition().x - wardrobeTexture.getPosition().x > 0 and
        std::abs(player.getPosition().y - wardrobeTexture.getPosition().y) < 70 and stage_1) {
        active = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            if (time.asSeconds() - lastUsed > 0.5) {
                if (isOpen) {
                    isOpen = false;
                } else {
                    isOpen = true;
                    player.hide();
                }
            }
            lastUsed = time.asSeconds();
        }
    } else {
        active = false;
    }
    if(!isOpen and time.asSeconds() - lastUsed > 0.3 and time.asSeconds() - lastUsed < 0.4 ){
        player.showPlayer();
    }
}

void Wardrobe::collision(Player &player, sf::RenderWindow &window) {

}

bool Wardrobe::getStatus() {
    return isOpen;
}

Wardrobe::~Wardrobe() = default;
