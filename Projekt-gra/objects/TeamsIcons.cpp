#include "TeamsIcon.h"
#include "../ResourceManager.h"
#include <cmath>

void TeamsIcon::draw(sf::RenderWindow &window)  {
    window.draw(icon);
}

void TeamsIcon::update(sf::RenderWindow& window) {
    sf::Vector2 vec = sf::Mouse::getPosition(window);
    if(std::pow(vec.x - centerX, 2) + std::pow(vec.y - centerY, 2) <= 4096){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            active = true;
        }
    }
    if(std::pow(vec.x - 1175, 2) + std::pow(vec.y - 125, 2) <= 1500 and active){
        active = false;
    }

}

void TeamsIcon::collision() {
    Icons::collision();
}

bool TeamsIcon::isActive() {
    return active;
}

void TeamsIcon::drawApp(sf::RenderWindow &window) {

}
