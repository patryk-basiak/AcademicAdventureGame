//
// Created by UseR on 19.05.2024.
//

#include "Icons.h"
#include "../ResourceManager.h"

Icons::Icons(float x, float y) {
    this->icon.setPosition(sf::Vector2f{x,y});
    if(id == 1){
        this->icon.setTexture(ResourceManager::getTexture("../graphics/googleIcon.png"));
        this->icon.scale(0.55,0.58);
    }
}

void Icons::draw(sf::RenderWindow &window) const {
    window.draw(icon);

}

void Icons::update() {

}

void Icons::collision() {

}
