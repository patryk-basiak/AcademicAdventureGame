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
        this->google.setTexture(ResourceManager::getTexture("../graphics/dinoRun.png"));
        this->google.scale(0.643,0.6);
        this->google.setPosition(425,125);
        this->windowScreen.setSize(sf::Vector2f(750, 450));
        this->windowScreen.setOutlineThickness(10);
        this->windowScreen.setOutlineColor(sf::Color::Black);
        this->windowScreen.setFillColor(sf::Color::White);
        this->windowScreen.setPosition(425, 125);
        this->icon.scale(0.55, 0.58);
        this->centerX = icon.getPosition().x + 64;
        this->centerY = icon.getPosition().y + 64;
    }
    void draw(sf::RenderWindow& window) override;
    void update(sf::RenderWindow& window) override;
    void collision() override;
    bool isActive() override;
    void drawApp(sf::RenderWindow& window) override;


private:
    sf::Sprite icon;
    sf::Sprite closeWindow;
    sf::RectangleShape windowScreen;
    sf::Sprite google;
    float centerX;
    float centerY;
    int id = 1;
    bool active = false;


};


