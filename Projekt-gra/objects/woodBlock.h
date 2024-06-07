//
// Created by UseR on 07.06.2024.
//
#include "Wall.h"
#include "../ResourceManager.h"

class WoodBlock
        :public Wall {

public:
    WoodBlock(float x, float y) : Wall(x,y){
        woodBlock.setPosition(x,y);
        woodBlock.setTexture(ResourceManager::getTexture("../graphics/woodPlank.png"));
        float sizeX = (float)woodBlock.getTexture()->getSize().x;
        float sizeY = (float)woodBlock.getTexture()->getSize().y;
        woodBlock.setScale(64/sizeX, 64/sizeY);
    }
    void collision(Player& player, sf::RenderWindow &window) override;
    sf::Vector2<float> getPosition() override;
    sf::Vector2<float> getSize() override;
    void update() override;
    void draw(sf::RenderWindow &window) const override;

private:
    sf::Sprite woodBlock;
    int id = 6;
};