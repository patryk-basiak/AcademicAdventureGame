#pragma once
#include "SFML/Graphics.hpp"
#include "../Player.h"
#include "Wall.h"
#include "../ResourceManager.h"

class Car
        : public Wall{

public:
    Car(float x, float y) : Wall(x,y, 64,64, sf::Color{ 255, 255, 0, 255 }){
        isMoving = false;
        car.setPosition(x,y);
        car.setTexture(ResourceManager::getTexture("../graphics/truck.png"));
        float sizeX = (float)car.getTexture()->getSize().x;
        car.setScale(200/sizeX, 200/sizeX);
    }

    ~Car() override;

    void collision(Player& player, sf::RenderWindow &window) override;
    sf::Vector2<float> getPosition() override;
    sf::Vector2<float> getSize() override;
    void update() override;
    void draw(sf::RenderWindow &window) const override;

private:
    sf::Sprite car;
    bool isMoving;
    int id = 300;

};