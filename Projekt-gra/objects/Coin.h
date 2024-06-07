#pragma once

#include "Collectable.h"
#include "../ResourceManager.h"

class Coin :
        public Collectable{

public:
    Coin(float x, float y): Collectable(x,y, sf::Color{255,215,0,255}){
        coin.setPosition(x,y);
        coin.setScale(0.052,0.052);

        coin.setTexture(ResourceManager::getTexture("../graphics/coin.png"));
        popUp.setFont(Collectable::font);
        popUp.setString("Coin");
        popUp.setFillColor((sf::Color{255,215,0,255}));
        popUp.setPosition(x + (this->getSize().x + 8), y - 4 );
    }
//    Coin(float x, float y, float scale): Collectable(x,y, sf::Color{255,215,0,255}){
//        coin.setPosition(x,y);
//        coin.setScale(0.052*scale,0.052*scale);
//
//        coin.setTexture(ResourceManager::getTexture("../graphics/coin.png"));
//        popUp.setFont(Collectable::font);
//        popUp.setString("Coin");
//        popUp.setFillColor((sf::Color{255,215,0,255}));
//        popUp.setPosition(x + 3*radius,y);
//    }
    void collision(Player& player) override;
    bool operator==(const Collectable& other) const override {
        const Coin* otherCoin = dynamic_cast<const Coin*>(&other);
        return otherCoin && this->value == otherCoin->value;
    }
    void setPosition(float x, float y) override;
    void draw(sf::RenderWindow& window) override;
    sf::Vector2<float> getSize() override;
    bool isStackable() const override;
    int getId() override;


private:
    sf::Sprite coin;
    sf::Text popUp;
    bool Stackable = true;
    int value = 3;

};