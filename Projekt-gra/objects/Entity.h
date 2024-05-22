#pragma once
#include <SFML/Graphics.hpp>
#include "../Player.h"

class Entity {

public:
    Entity(float x, float y, sf::Color color);
    Entity(float x, float y);
    virtual void draw(sf::RenderWindow& window);
    virtual sf::FloatRect getGlobalBounds();
    virtual void update(sf::Time time, Player& player);
    virtual void collision(Player& player);
    virtual sf::Vector2<float> getPosition();
    virtual sf::Vector2<float> getSize();
    virtual ~Entity();

    virtual void setPosition(float d, float d1);

    virtual void setVerticalVelocity(int i);

private:
    int health;
    sf::RectangleShape entity;
    sf::Vector2<float> startPosition;
    bool toRight = true;


};
