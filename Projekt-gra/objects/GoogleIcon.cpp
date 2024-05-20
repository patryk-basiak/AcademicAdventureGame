#include <cmath>
#include "GoogleIcons.h"
#include "../ResourceManager.h"
#include "fmt/core.h"


void GoogleIcons::draw(sf::RenderWindow &window) {
    window.draw(icon);

}

void GoogleIcons::update(sf::RenderWindow &window) {
    sf::Vector2 vec = sf::Mouse::getPosition(window);
    if(std::pow(vec.x - centerX, 2) + std::pow(vec.y - centerY, 2) <= 4096){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            active = true;
        }
    }
    if(std::pow(vec.x - 1175, 2) + std::pow(vec.y - 125, 2) <= 800 and active){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            active = false;
        }
    }
}

void GoogleIcons::collision() {

}

bool GoogleIcons::isActive() {
    return active;
}

void GoogleIcons::drawApp(sf::RenderWindow &window) {
        window.draw(this->windowScreen);
        window.draw(google);

}
