#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"

class Icons {
public:
    Icons(float x, float y);
    virtual void draw(sf::RenderWindow& window);
    virtual void update(sf::RenderWindow& window);
    virtual void collision();
    virtual bool isActive();
    virtual void drawApp(sf::RenderWindow& window);


private:
    sf::Sprite icon;
    int id = 1;
    bool active = false;


};

