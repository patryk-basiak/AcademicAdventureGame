#pragma once


#include <SFML/Graphics.hpp>
#include "../Player.h"
#include "Wall.h"
#include "../ResourceManager.h"

class OakTree
        : public Wall{

public:
    OakTree(float x, float y) : Wall(x,y, 64,65, sf::Color{ 255, 255, 0, 255 }){
        wood.setTexture(ResourceManager::getTexture("../graphics/oakWood.png"));
        wood.setScale(0.16,0.16);
        wood.setPosition(x,y);
    }
    void draw(sf::RenderWindow &window) const override;
    ~OakTree() override;

    void collision(Player& player, sf::RenderWindow &window) override;

private:
    int id = 200;
    sf::Sprite wood;


};