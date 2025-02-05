//
// Created by UseR on 05/02/2025.
//

#include "Button.h"

void Button::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    window.draw(text);
}
