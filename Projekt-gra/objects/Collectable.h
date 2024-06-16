#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Player.h"

class Collectable {
public:
    Collectable(float x, float y, sf::Color color);
    Collectable(float x, float y);

    Collectable(float x, float y, sf::Color color, float d, float d1);
    virtual bool operator==(const Collectable& other) const;
    virtual void collision(Player& player);

    virtual sf::FloatRect getGlobalBounds();
    virtual void draw(sf::RenderWindow& window);
    virtual sf::Vector2<float> getPosition();
    void reColor(sf::Color color);
    virtual sf::Vector2<float> getSize();
    virtual void setPosition(float x, float y);
    virtual std::vector<sf::RectangleShape> getAmmoList();
    virtual void usage(Player& player);
    virtual void update(sf::RenderWindow& window, Player& player);
    virtual bool isStackable() const;
    virtual int getId();
    int id = 0;
    virtual bool isOneTimeUse();
    virtual bool canHurtPlayer();


    virtual std::string getInfo();

protected:
    sf::Font font;

private:
    sf::RectangleShape collect;
    bool Stackable = false;
    bool oneTimeUse = false;


};

