#pragma once

#include "Collectable.h"
#include "../ResourceManager.h"

class TimeIncreaser :
        public Collectable{
public:
    TimeIncreaser(float x, float y): Collectable(x,y){
        time.setPosition(x,y);
        time.setTexture(ResourceManager::getTexture("../graphics/time.png"));
        time.setScale(0.05,0.05);

    }
    void setPosition(float x, float y) override;
    void draw(sf::RenderWindow& window) override;
    sf::Vector2<float> getSize() override;
    bool isStackable() const override;
    int getId() override;
private:
    sf::Sprite time;
    sf::Text popUp;
    bool Stackable = false;
    int id = 6;
};
