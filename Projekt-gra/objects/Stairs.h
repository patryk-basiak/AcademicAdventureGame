#pragma once

#include "Wall.h"
#include "../ResourceManager.h"

class Stairs
        :public Wall {

public:
    Stairs(float x, float y) : Wall(x,y){
        stairs.setPosition(x,y);
        stairs.setTexture(ResourceManager::getTexture("../graphics/Stairs.png"));
        float sizeX = (float)stairs.getTexture()->getSize().x;
        float sizeY = (float)stairs.getTexture()->getSize().y;
        stairs.setScale(64/sizeX, 64/sizeY);
    }Stairs(float x, float y, int n) : Wall(x,y){
        if(n == 0) {
            stairs.setPosition(x, y);
            stairs.setTexture(ResourceManager::getTexture("../graphics/brickStairs.png"));
        }else{
            stairs.setPosition(x, y);
            stairs.setTexture(ResourceManager::getTexture("../graphics/brickStairsReversed.png"));
        }
        float sizeX = (float)stairs.getTexture()->getSize().x;
        float sizeY = (float)stairs.getTexture()->getSize().y;
        stairs.setScale(64/sizeX, 64/sizeY);
    }
    void collision(Player& player, sf::RenderWindow &window) override;
    sf::Vector2<float> getPosition() override;
    sf::Vector2<float> getSize() override;
    void update() override;
    void draw(sf::RenderWindow &window) const override;

private:
    sf::Sprite stairs;
    int id = 11;
};
