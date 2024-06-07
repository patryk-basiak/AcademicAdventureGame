#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../Player.h"
#include "../Equipment.h"

class Interactable {
public:
    Interactable(float x, float y);
    virtual void draw(sf::RenderWindow& window) ;
    virtual sf::Vector2<float> getPosition();
    virtual sf::Vector2<float> getSize();
    virtual ~Interactable();
    virtual void update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time); //TODO deltatime
    virtual void collision(Player& player, sf::RenderWindow &window) ;
    virtual bool getStatus();
    virtual void setColl(bool collide);
    virtual void collisionRight(Player& player, sf::RenderWindow &window);
    virtual void collisionLeft(Player& player, sf::RenderWindow &window);
    virtual void collisionBottom(Player& player, sf::RenderWindow &window);
protected:
    sf::Font font;
    bool coll = false;

private:
    sf::Sprite graphic;

    std::vector<float>size;
    bool inUse;

};





