#pragma once
#include <SFML/Graphics.hpp>
#include "../Player.h"
#include "Entity.h"
#include <memory>
class Wall {
public:
    Wall(float x, float y, float sX, float sY, sf::Color color);
    Wall(float x, float y);

    Wall(const Wall&) = delete;
    Wall& operator=(const Wall&) = delete;
    Wall(Wall&&) noexcept = default;
    Wall& operator=(Wall&&) noexcept = default;
    virtual ~Wall();

    virtual sf::Vector2<float> getPosition();
    virtual sf::Vector2<float> getSize();
    virtual void update();
    virtual void setPosition(float x, float y);
    virtual void draw(sf::RenderWindow &window) const;
    virtual void collision(Player& player, sf::RenderWindow &window);
    virtual void collisionRight(Player& player, sf::RenderWindow &window);
    virtual void collisionLeft(Player& player, sf::RenderWindow &window);
    virtual void collisionBottom(Player& player, sf::RenderWindow &window);
    virtual void collision(std::unique_ptr<Entity>&, sf::RenderWindow &window);
    virtual void collisionRight(std::unique_ptr<Entity>&, sf::RenderWindow &window);
    virtual void collisionLeft(std::unique_ptr<Entity>&, sf::RenderWindow &window);
    virtual void collisionBottom(std::unique_ptr<Entity>&, sf::RenderWindow &window);
    sf::FloatRect getGlobalBounds() const;
    virtual bool isCollision() const;

private:
    sf::RectangleShape wall;
    bool collisionON = true;

};
