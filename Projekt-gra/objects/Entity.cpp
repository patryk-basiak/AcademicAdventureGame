
#include "Entity.h"
#include "fmt/core.h"

Entity::Entity(float x, float y, sf::Color color) {
    this->entity.setPosition(x, y);
    this->entity.setFillColor(color);
}

Entity::Entity(float x, float y) {
    this->entity.setPosition(x, y);
    this->startPosition = sf::Vector2f(x,y);
    this->entity.setFillColor(sf::Color{255, 0, 0});
    this->entity.setSize(sf::Vector2f(64,32));
}

sf::FloatRect Entity::getGlobalBounds() {
    return this->entity.getGlobalBounds();
}

void Entity::draw(sf::RenderWindow &window) {
    window.draw(this->entity);

}

void Entity::update(sf::Time time) {
    if (toRight) {
        entity.move(sf::Vector2f(100*time.asSeconds(), 0));
        if (std::abs(entity.getPosition().x - this->startPosition.x) > 50) {
            this->toRight = false;
        }
    }
    if (!toRight) {
        entity.move(sf::Vector2f(-100*time.asSeconds(), 0));
        if (std::abs(entity.getPosition().x - this->startPosition.x) > 50) {
            this->toRight = true;

        }
    }
}

void Entity::collision(Player &player) {
    player.setHealth(player.getHealth()-1);
}

sf::Vector2<float> Entity::getPosition() {
    return this->entity.getPosition();
}

sf::Vector2<float> Entity::getSize() {
    return this->entity.getSize();
}

void Entity::setPosition(float d, float d1) {
    this->entity.setPosition(d,d1);
}

Entity::~Entity() {

}

