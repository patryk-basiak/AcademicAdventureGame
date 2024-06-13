#pragma once
#include "Collectable.h"
#include "../ResourceManager.h"

class Disk :
        public Collectable{

public:
    Disk(float x, float y): Collectable(x,y, sf::Color{255,215,0,255}){
        disk.setPosition(x,y);
        disk.setTexture(ResourceManager::getTexture("../graphics/disk.png"));
        disk.setScale((float)48/disk.getTexture()->getSize().x,(float)48/disk.getTexture()->getSize().y);
        popUp.setFont(Collectable::font);
        popUp.setString("Disk");
        popUp.setFillColor((sf::Color{255,215,0,255}));
        popUp.setPosition(x + (this->getSize().x + 8), y - 4 );
    }
    void collision(Player& player) override;
    void usage(Player& player) override;
    void setPosition(float x, float y) override;
    void draw(sf::RenderWindow& window) override;
    sf::Vector2<float> getSize() override;
    bool isStackable() const override;
    bool isOneTimeUse() override;
    int getId() override;


private:
    bool OneTimeUse = true;
    sf::Sprite disk;
    sf::Text popUp;
    bool Stackable = false;
    bool inUse = false;
    int value = 20;

};