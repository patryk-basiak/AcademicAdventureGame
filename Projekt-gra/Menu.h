#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "ResourceManager.h"

class Menu {
public:
    Menu(){
        menuImage.setTexture(ResourceManager::getTexture("../graphics/menu.png"));
        menuImage.setScale((float)1600/menuImage.getTexture()->getSize().x,(float)900/menuImage.getTexture()->getSize().y);
        settings = false;
    }




   void draw(sf::RenderWindow& window);
   void update();





private:
    sf::Sprite menuImage;
    bool settings;



};

