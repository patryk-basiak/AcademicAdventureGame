
#include "Icons.h"
#include "../ResourceManager.h"

Icons::Icons(float x, float y) {
    this->icon.setPosition(sf::Vector2f{x,y});
}

void Icons::draw(sf::RenderWindow &window) {
    window.draw(icon);

}

void Icons::update(sf::RenderWindow& window) {

}

void Icons::collision() {

}

bool Icons::isActive() {
    return active;
}

void Icons::drawApp(sf::RenderWindow &window) {

}
