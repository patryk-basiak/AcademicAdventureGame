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
        this->centerX = icon.getPosition().x + 64;
        this->centerY = icon.getPosition().y + 64;
    }
    void draw(sf::RenderWindow& window) override;
    void update(sf::RenderWindow& window) override;
    void collision() override;
    bool isActive() override;
    void drawApp(sf::RenderWindow& window) override;


private:
    float centerX;
    float centerY;
    sf::Sprite icon;
    int id = 2;
    bool active = false;


};




