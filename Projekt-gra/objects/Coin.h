#pragma once

#include "Collectable.h"

class Coin :
        public Collectable{

public:
    Coin(float x, float y, float r): Collectable(x,y, sf::Color{255,215,0,255}){
        this->coin.setPosition(x,y);
        this->coin.setRadius(r);
        this->coin.setFillColor(sf::Color{255,215,0,255});
        this->radius = r;
    }
    void collision(Player& player) override;
    bool operator==(const Collectable& other) const override {
        const Coin* otherCoin = dynamic_cast<const Coin*>(&other);
        return otherCoin && this->value == otherCoin->value;
    }
    void setPosition(float x, float y) override;
    void draw(sf::RenderWindow& window) override;
    void usage() override;
    sf::Vector2<float> getSize() override;
    bool isStackable() const override;
    std::unique_ptr<Collectable> clone() const override;
    int getId() override;


private:
    float radius;
    sf::CircleShape coin;
    bool Stackable = true;
    int value = 3;

};