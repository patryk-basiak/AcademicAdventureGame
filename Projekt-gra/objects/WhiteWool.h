#pragma once

#include "Wall.h"
#include "../ResourceManager.h"

class WhiteWool
        :public Wall {

public:
    WhiteWool(float x, float y) : Wall(x,y){
        whiteWool.setPosition(x,y);
        whiteWool.setTexture(ResourceManager::getTexture("../graphics/whiteWool.png"));
        float sizeX = (float)whiteWool.getTexture()->getSize().x;
        float sizeY = (float)whiteWool.getTexture()->getSize().y;
        whiteWool.setScale(64/sizeX, 64/sizeY);
    }
    void collision(Player& player, sf::RenderWindow &window) override;
    sf::Vector2<float> getPosition() override;
    sf::Vector2<float> getSize() override;
    void update() override;
    void draw(sf::RenderWindow &window) const override;

private:
    sf::Sprite whiteWool;
    int id = 12;
};
