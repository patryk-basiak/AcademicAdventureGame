#include "WildBoar.h"
#include "fmt/core.h"

void WildBoar::draw(sf::RenderWindow &window) {
    window.draw(wild);

}

sf::FloatRect WildBoar::getGlobalBounds() {
    return wild.getGlobalBounds();
}


void WildBoar::collision(Player &player) {
    player.setHealth(player.getHealth() - 1);
}

sf::Vector2<float> WildBoar::getPosition() {
    return wild.getPosition();
}

sf::Vector2<float> WildBoar::getSize() {
    return sf::Vector2f {64,40.5};
}

WildBoar::~WildBoar() = default;
void WildBoar::update(sf::Time time, Player &player) {
    fmt::println("{}", followingPlayer);

    float deltaTime = time.asSeconds();

    horizontalVelocity += gravity * deltaTime;
    wild.move(velocity * deltaTime, horizontalVelocity);

    if (velocity < 0) {
        wild.setTexture(ResourceManager::getTexture("../graphics/wildboar.png"));
    } else {
        wild.setTexture(ResourceManager::getTexture("../graphics/0wildboarLeft.png"));
    }

    float distanceToPlayerX = player.getPosition().x - wild.getPosition().x;
    float distanceToPlayerY = player.getPosition().y - wild.getPosition().y;
    if (std::abs(distanceToPlayerX) < 70 and std::abs(distanceToPlayerY) < 70 ) {
        followingPlayer = true;
        velocity = (distanceToPlayerX > 0) ? 50 : -50;
    } else if (std::abs(distanceToPlayerX) < 100 and std::abs(distanceToPlayerY) < 100 ) {
        followingPlayer = false;
    }
    if (!followingPlayer && std::abs(initialPositionX - wild.getPosition().x) > 250) {
        velocity *= -1;
    }
}

void WildBoar::setPosition(float d, float d1) {
    wild.setPosition(d,d1);
}

void WildBoar::setVerticalVelocity(int i) {
    horizontalVelocity = i;
}
