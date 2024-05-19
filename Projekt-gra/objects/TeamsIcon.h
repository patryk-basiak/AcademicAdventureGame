#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "Icons.h"
#include "../ResourceManager.h"

class TeamsIcon
        : public Icons{
public:
    TeamsIcon(float x, float y) : Icons(x, y) {
        this->icon.setPosition(x, y);
        this->icon.setTexture(ResourceManager::getTexture("../graphics/microsoftTeamsIcon.png"));
        this->icon.scale(0.13, 0.13);
    }
    void draw(sf::RenderWindow& window) override;
    void update() override;
    void collision() override;


private:
    sf::Sprite icon;
    int id = 2;
    bool isActive = false;


};




