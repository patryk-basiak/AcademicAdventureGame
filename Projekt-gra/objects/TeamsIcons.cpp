#include "TeamsIcon.h"
#include "../ResourceManager.h"

void TeamsIcon::draw(sf::RenderWindow &window)  {
    window.draw(icon);
}

void TeamsIcon::update() {
    Icons::update();
}

void TeamsIcon::collision() {
    Icons::collision();
}