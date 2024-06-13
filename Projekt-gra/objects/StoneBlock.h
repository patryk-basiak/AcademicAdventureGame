#pragma once

#include "Wall.h"
#include "../ResourceManager.h"

class StoneBlock
        :public Wall {

public:
    StoneBlock(float x, float y) : Wall(x,y){
        stoneBlock.setPosition(x,y);
        stoneBlock.setTexture(ResourceManager::getTexture("../graphics/stoneBlock.png"));
        float sizeX = (float)stoneBlock.getTexture()->getSize().x;
        float sizeY = (float)stoneBlock.getTexture()->getSize().y;
        stoneBlock.setScale(64/sizeX, 64/sizeY);
    }
    void collision(Player& player, sf::RenderWindow &window) override;
    sf::Vector2<float> getPosition() override;
    sf::Vector2<float> getSize() override;
    void update() override;
    void draw(sf::RenderWindow &window) const override;

private:
    sf::Sprite stoneBlock;
    int id = 14;
};
