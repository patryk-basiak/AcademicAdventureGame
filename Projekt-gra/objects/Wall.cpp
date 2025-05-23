#include "Wall.h"
#include "fmt/core.h"

Wall::Wall(float x, float y, float sX, float sY, sf::Color color) {
    fmt::println("wall created");
    this->wall.setSize(sf::Vector2f(sX,sY));
    this->wall.setPosition(x,y);
    this->wall.setFillColor(color);
}
void Wall::draw(sf::RenderWindow& window) const {
    window.draw(this->wall);
}

void Wall::collision(Player &player, sf::RenderWindow &window) {
    player.setPosition(player.getPosition().x, wall.getPosition().y - player.getSize()[1] - 0.18);
    player.setVerticalVelocity(0);
}

sf::FloatRect Wall::getGlobalBounds() const {
    return this->wall.getGlobalBounds();
}

bool Wall::isCollision() const {
    return collisionON;
}

sf::Vector2<float> Wall::getPosition() {
    return this->wall.getPosition();
}

sf::Vector2<float> Wall::getSize() {
    return this->wall.getSize();
}

void Wall::update() {

}

Wall::Wall(float x, float y) {
    wall.setPosition(x,y);
    wall.setSize(sf::Vector2f (64,64));

}

void Wall::collisionRight(Player &player, sf::RenderWindow &window) {
    player.setVelocity(0);
    player.setPosition(wall.getPosition().x + wall.getSize().x, player.getPosition().y);
}

void Wall::collisionLeft(Player &player, sf::RenderWindow &window) {
    player.setVelocity(0);
    player.setPosition(wall.getPosition().x - player.getSize()[0], player.getPosition().y);

}

void Wall::collisionBottom(Player &player, sf::RenderWindow &window) {
    player.setVerticalVelocity(0);
    player.setPosition(player.getPosition().x, wall.getPosition().y + wall.getSize().y);
}
void Wall::collisionRight(std::unique_ptr<Entity>& entity, sf::RenderWindow &window) {
    entity->setVelocity(0);
    entity->setPosition(wall.getPosition().x + wall.getSize().x, entity->getPosition().y);
}

void Wall::collisionLeft(std::unique_ptr<Entity>& entity, sf::RenderWindow &window) {
    entity->setVelocity(0);
    entity->setPosition(wall.getPosition().x - entity->getSize().x, entity->getPosition().y);

}

void Wall::collisionBottom(std::unique_ptr<Entity>& entity, sf::RenderWindow &window) {
    entity->setVerticalVelocity(0);
    entity->setPosition(entity->getPosition().x, wall.getPosition().y + wall.getSize().y);
}

void Wall::collision(std::unique_ptr<Entity> &entity, sf::RenderWindow &window) {
    entity->setPosition(entity->getPosition().x, wall.getPosition().y - entity->getSize().y);
    entity->setVerticalVelocity(0);
}

void Wall::setPosition(float x, float y) {
    wall.setPosition(x,y);
}

Wall::~Wall() = default;
