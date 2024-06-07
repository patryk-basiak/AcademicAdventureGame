//
// Created by UseR on 07.06.2024.
//
#include "Wall.h"
#include "../ResourceManager.h"

class Brick
        :public Wall {

public:
    Brick(float x, float y) : Wall(x,y){
        brick.setPosition(x,y);
        brick.setTexture(ResourceManager::getTexture("../graphics/brick.png"));
        float sizeX = (float)brick.getTexture()->getSize().x;
        float sizeY = (float)brick.getTexture()->getSize().y;
        brick.setScale(64/sizeX, 64/sizeY);
    }
    void collision(Player& player, sf::RenderWindow &window) override;
    sf::Vector2<float> getPosition() override;
    sf::Vector2<float> getSize() override;
    void update() override;
    void draw(sf::RenderWindow &window) const override;

private:
    sf::Sprite brick;
    int id = 5;
};