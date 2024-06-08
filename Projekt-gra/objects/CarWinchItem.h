#pragma once
#include "Collectable.h"
#include "../ResourceManager.h"

class CarWinchItem :
        public Collectable{

public:
    CarWinchItem(float x, float y): Collectable(x,y, sf::Color{255,215,0,255}){
        carWinchItem.setPosition(x,y);
        carWinchItem.setTexture(ResourceManager::getTexture("../graphics/carWinch.png"));
        carWinchItem.setScale((float)64/carWinchItem.getTexture()->getSize().x,(float)64/carWinchItem.getTexture()->getSize().y);
        popUp.setFont(Collectable::font);
        popUp.setString("CarWinchItem");
        popUp.setFillColor((sf::Color{255,215,0,255}));
        popUp.setPosition(x + (this->getSize().x + 8), y - 4 );
    }
    void collision(Player& player) override;
    void usage(Player& player) override;
    void setPosition(float x, float y) override;
    void draw(sf::RenderWindow& window) override;
    sf::Vector2<float> getSize() override;
    bool isStackable() const override;
    bool isOneTimeUse() override;
    int getId() override;


private:
    bool OneTimeUse = true;
    sf::Sprite carWinchItem;
    sf::Text popUp;
    bool Stackable = false;
    bool inUse = false;
    int value = 11;

};