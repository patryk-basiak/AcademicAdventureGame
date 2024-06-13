#pragma once

#include "Wall.h"
#include "../ResourceManager.h"

class DarkBlock
        :public Wall {

public:
    DarkBlock(float x, float y) : Wall(x,y){
        darkBlock.setPosition(x,y);
        darkBlock.setTexture(ResourceManager::getTexture("../graphics/DarkBlock.png"));
        float sizeX = (float)darkBlock.getTexture()->getSize().x;
        float sizeY = (float)darkBlock.getTexture()->getSize().y;
        darkBlock.setScale(64/sizeX, 64/sizeY);
    }
    void collision(Player& player, sf::RenderWindow &window) override;
    sf::Vector2<float> getPosition() override;
    sf::Vector2<float> getSize() override;
    void update() override;
    void draw(sf::RenderWindow &window) const override;

private:
    sf::Sprite darkBlock;
    int id = 13;
};
