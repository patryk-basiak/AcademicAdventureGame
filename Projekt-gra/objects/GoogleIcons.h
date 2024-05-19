#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "Icons.h"
#include "../ResourceManager.h"

class GoogleIcons
        : public Icons{
public:
    GoogleIcons(float x, float y) : Icons(x, y){
        this->icon.setPosition(x, y);
        this->icon.setTexture(ResourceManager::getTexture("../graphics/googleIcon.png"));
        this->icon.scale(0.55, 0.58);
    }
    void draw(sf::RenderWindow& window) override;
    void update() override;
    void collision() override;


private:
    sf::Sprite icon;
    int id = 1;
    bool isActive = false;


};


