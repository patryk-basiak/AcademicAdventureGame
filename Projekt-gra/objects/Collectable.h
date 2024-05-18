#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Player.h"

class Collectable {
public:
    Collectable(float x, float y, sf::Color color);

    Collectable(float x, float y, sf::Color color, float d, float d1);
    virtual bool operator==(const Collectable& other) const;
    virtual void collision(Player& player);

    sf::FloatRect getGlobalBounds();
    virtual void draw(sf::RenderWindow& window);
    sf::Vector2<float> getPosition();
    void reColor(sf::Color color);
    virtual void setPosition(float x, float y);
    virtual void usage();
    virtual void update(sf::RenderWindow& window);
    virtual std::unique_ptr<Collectable> clone() const;
    virtual bool isStackable() const;
    virtual int getId();
    int id = 0;

private:
    sf::RectangleShape collect;
    bool Stackable = false;


};

