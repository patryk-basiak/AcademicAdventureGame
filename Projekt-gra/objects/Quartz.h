//
// Created by UseR on 07.06.2024.
//
#include "Wall.h"
#include "../ResourceManager.h"

class Quartz
        :public Wall {

public:
    Quartz(float x, float y) : Wall(x,y){
        quartz.setPosition(x,y);
        quartz.setTexture(ResourceManager::getTexture("../graphics/quartz.png"));
        float sizeX = (float)quartz.getTexture()->getSize().x;
        float sizeY = (float)quartz.getTexture()->getSize().y;
        quartz.setScale(64/sizeX, 64/sizeY);
    }
    void collision(Player& player, sf::RenderWindow &window) override;
    sf::Vector2<float> getPosition() override;
    sf::Vector2<float> getSize() override;
    void update() override;
    void draw(sf::RenderWindow &window) const override;

private:
    sf::Sprite quartz;
    int id = 17;
};