#pragma once
#include <SFML/Graphics.hpp>
#include "../Player.h"
class Wall {
public:
    Wall(float x, float y, float sX, float sY, sf::Color color);

    Wall(const Wall&) = delete;
    Wall& operator=(const Wall&) = delete;
    Wall(Wall&&) noexcept = default;
    Wall& operator=(Wall&&) noexcept = default;
    virtual ~Wall();

    virtual sf::Vector2<float> getPosition();
    virtual sf::Vector2<float> getSize();
    virtual void update();
    virtual void draw(sf::RenderWindow &window) const;
    virtual void collision(Player& player, sf::RenderWindow &window);
    sf::FloatRect getGlobalBounds() const;
    virtual bool isCollision() const;

private:
    sf::RectangleShape wall;
    bool collisionON = true;

};
