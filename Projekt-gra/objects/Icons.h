#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"

class Icons {
public:
    Icons(float x, float y);
    void draw(sf::RenderWindow& window) const;
    void update();
    void collision();


private:
    sf::Sprite icon;
    int id = 1;
    bool isActive = false;


};

