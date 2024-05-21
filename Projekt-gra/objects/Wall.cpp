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

Wall::~Wall() = default;
