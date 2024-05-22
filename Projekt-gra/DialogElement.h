#pragma once


#include <string>
#include "SFML/Graphics/RenderWindow.hpp"
#include "Player.h"

class DialogElement {

public:
    explicit DialogElement(std::string sentces);
    void setPosition(float x, float y);
    void draw(sf::RenderWindow& window) ;
    void update(Player& player);
    void setText(std::string text);




private:
    std::string Sentences;
    bool isShown = false;
    sf::Font font;
    sf::Text message;
    sf::RectangleShape base;


};

