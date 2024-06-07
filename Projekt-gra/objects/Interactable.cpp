#include "Interactable.h"
#include "fmt/core.h"

Interactable::Interactable(float x, float y) {
    graphic.setPosition(x,y);
    fmt::println("Interact created");
    size = std::vector<float>{0,1};
    if(!font.loadFromFile("../graphics/PIXELAR REGULAR.OTF")) {
        fmt::println("font loading error");
    }

}

void Interactable::update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time) {

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

void Interactable::collisionRight(Player &player, sf::RenderWindow &window) {
    coll = true;
}

void Interactable::collisionLeft(Player &player, sf::RenderWindow &window) {
    coll = true;
}

void Interactable::collisionBottom(Player &player, sf::RenderWindow &window) {
    coll = true;
}

sf::Vector2<float> Interactable::getSize() {
    return sf::Vector2<float>{graphic.getTexture()->getSize().x * graphic.getScale().x,graphic.getTexture()->getSize().y * graphic.getScale().y };
}

void Interactable::setColl(bool collide) {
    coll = collide;
}
