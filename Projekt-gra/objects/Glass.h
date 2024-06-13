#pragma once

#include "Wall.h"
#include "../ResourceManager.h"

class Glass
        :public Wall {

public:
    Glass(float x, float y) : Wall(x,y){
        glass.setPosition(x,y);
        glass.setTexture(ResourceManager::getTexture("../graphics/Glass.png"));
        float sizeX = (float)glass.getTexture()->getSize().x;
        float sizeY = (float)glass.getTexture()->getSize().y;
        glass.setScale(64/sizeX, 64/sizeY);
    }
    void collision(Player& player, sf::RenderWindow &window) override;
    sf::Vector2<float> getPosition() override;
    sf::Vector2<float> getSize() override;
    void update() override;
    void draw(sf::RenderWindow &window) const override;

private:
    sf::Sprite glass;
    int id = 3;
};
