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
    virtual bool isFriendly();
    virtual void setVerticalVelocity(int i);
    virtual void setVelocity(int i);
    virtual void setHealth(int i);
    virtual int getHealth();
    virtual bool diesOutsideScreen();

private:

    int health = 1;
    float velocity = 0;
    float VerticalVelocity = 0;
    sf::RectangleShape entity;
    sf::Vector2<float> startPosition;
    bool toRight = true;
    bool friendly = false;

};
