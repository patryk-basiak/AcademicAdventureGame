#pragma once

#include "Collectable.h"
#include "../ResourceManager.h"

class UniCard :
        public Collectable{
public:
    UniCard(float x, float y): Collectable(x,y, sf::Color{255,215,0,255}){
        card.setPosition(x,y);

        card.setTexture(ResourceManager::getTexture("../graphics/UniCard.png"));
        popUp.setFont(Collectable::font);
        popUp.setString("University ID card");
        popUp.setFillColor((sf::Color{55,148,110,255}));
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
    void setPosition(float x, float y) override;
    void draw(sf::RenderWindow& window) override;
    sf::Vector2<float> getSize() override;
    bool isStackable() const override;
    std::unique_ptr<Collectable> clone() const override;
    int getId() override;


private:
    sf::Sprite card;
    sf::Text popUp;
    bool Stackable = false;
    int index = 5;

};
