#pragma once

#include "Wall.h"
#include "../ResourceManager.h"

class Dirt
        :public Wall {

public:
    Dirt(float x, float y) : Wall(x,y){
        dirt.setPosition(x,y);
        dirt.setTexture(ResourceManager::getTexture("../graphics/dirt.png"));
        float sizeX = (float)dirt.getTexture()->getSize().x;
        float sizeY = (float)dirt.getTexture()->getSize().y;
        dirt.setScale(64/sizeX, 64/sizeY);
    }
    void collision(Player& player, sf::RenderWindow &window) override;
    sf::Vector2<float> getPosition() override;
    sf::Vector2<float> getSize() override;
    void update() override;
    void draw(sf::RenderWindow &window) const override;

private:
    sf::Sprite dirt;
    int id = 4;
};
