#pragma once

#include <random>
#include "Interactable.h"
#include "../ResourceManager.h"

class Shop
        : public Interactable{
public:
    Shop(float x, float y) : Interactable(x,y){
        std::random_device rd;
        std::mt19937 gen(rd()); // Mersenne Twister engine
        std::uniform_int_distribution<> shopN(0, 2);
        int shopNumber = shopN(gen);
        if(shopNumber == 0)
        {
            this->shop.setTexture(ResourceManager::getTexture("../graphics/shop.png"));
            this->shop.setPosition(x, y - 50.8);
            this->shop.scale(0.2, 0.2);
        }
        if(shopNumber == 1)
        {
            this->shop.setTexture(ResourceManager::getTexture("../graphics/shop1.png"));
            this->shop.setPosition(x, y - 50.8);
            this->shop.scale(0.2, 0.2);
        }
        if(shopNumber == 2)
        {
            this->shop.setTexture(ResourceManager::getTexture("../graphics/shop2.png"));
            this->shop.setPosition(x, y - 50.8);
            this->shop.scale(0.2, 0.2);
        }


        popUp.setString("Press F to buy");
        popUp.setFont(Interactable::font);
        popUp.setFillColor(sf::Color::Black);
        popUp.setPosition(shop.getPosition().x, shop.getPosition().y - 30);
    }
    void draw(sf::RenderWindow& window) override;
    sf::Vector2<float> getPosition()override;
    sf::Vector2<float> getSize()override;
    ~Shop()override;
    void update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time) override;
    void collision(Player& player, sf::RenderWindow &window) override;
    bool getStatus() override;
    
private:

    sf::Text popUp;
    sf::Sprite shop;
    std::map<std::unique_ptr<Collectable>, int> itemsInside;
//    sf::Sprite shelf;
    bool active = false;
    
    int id=300;
    bool isOpen = false;
    std::vector<float> position;
    
};