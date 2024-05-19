#include "Interactable.h"
#include "fmt/core.h"

Interactable::Interactable(float x, float y) {
    graphic.setPosition(x,y);
    fmt::println("Interact created");
    size = std::vector<float>{0,1};

}

void Interactable::update(sf::RenderWindow& window) {

}

void Interactable::collision(Player &player, sf::RenderWindow &window) {

}

bool Interactable::getStatus() {
    return false;
}

Interactable::~Interactable() = default;

void Interactable::draw(sf::RenderWindow &window) {
    window.draw(graphic);

}

sf::Vector2<float> Interactable::getPosition() {
    return graphic.getPosition();
}

std::vector<float> Interactable::getSize() {
    return size;
}
