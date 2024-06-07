#pragma once

#include <SFML/Graphics.hpp>
#include "../Player.h"
#include "Wall.h"
#include "../ResourceManager.h"

class JumpPad
        : public Wall{

public:
    JumpPad(float x, float y)  : Wall(x,y){
        jumpPad.setPosition(x,y);
        jumpPad.setTexture(ResourceManager::getTexture("../graphics/slimeBlock.png"));
        float sizeX = (float)jumpPad.getTexture()->getSize().x;
        float sizeY = (float)jumpPad.getTexture()->getSize().y;
        jumpPad.setScale(64/sizeX, 64/sizeY);
    }
    void collision(Player& player, sf::RenderWindow &window) override;
    sf::Vector2<float> getPosition() override;
    sf::Vector2<float> getSize() override;
    void update() override;
    void draw(sf::RenderWindow &window) const override;

private:
    sf::Sprite jumpPad;
    int id = 6;
};