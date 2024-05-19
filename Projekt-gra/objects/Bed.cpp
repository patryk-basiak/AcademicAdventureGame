//
// Created by UseR on 18.05.2024.
//

#include "Bed.h"
#include "fmt/core.h"

void Bed::collision(Player &player, sf::RenderWindow &window) {
    fmt::println("There is no time to go to sleep");
}

Bed::~Bed() {

}

void Bed::draw(sf::RenderWindow &window) const {
    window.draw(bed);
}
