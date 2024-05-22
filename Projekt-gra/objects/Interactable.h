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
    virtual std::vector<float> getSize();
    virtual ~Interactable();
    virtual void update(sf::RenderWindow& window, Player& player, Equipment& eq);
    virtual void collision(Player& player, sf::RenderWindow &window) ;
    virtual bool getStatus();

protected:
    sf::Font font;

private:
    sf::Sprite graphic;
    std::vector<float>size;
    bool inUse;

};





