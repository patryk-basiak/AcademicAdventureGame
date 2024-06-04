#pragma once

//TODO

#include "Collectable.h"
#include "../ResourceManager.h"

class Health :
        public Collectable{
public:
    Health(float x, float y): Collectable(x,y){
        health.setPosition(x,y);
        health.setTexture(ResourceManager::getTexture("../graphics/health.png"));
        health.setScale(0.05,0.05);

    }
    void setPosition(float x, float y) override;
    void draw(sf::RenderWindow& window) override;
    sf::Vector2<float> getSize() override;
    bool isStackable() const override;
    std::unique_ptr<Collectable> clone() const override;
    int getId() override;
    void usage(Player& player) override;
    bool isOneTimeUse() override;
private:
    sf::Sprite health;
    sf::Text popUp;
    bool Stackable = false;
    bool OneTimeUse = true;
    int id = 7;
};

