#pragma once

#include "Interactable.h"
#include "../ResourceManager.h"
#include "Coin.h"
#include "Health.h"
#include "TimeIncreaser.h"

class Kiosk
    : public Interactable{


public:
    Kiosk(float x, float y) : Interactable(x-38.4,y - 38.4){

        kiosk.setTexture(ResourceManager::getTexture("../graphics/kiosk.png"));
        kiosk.setPosition(x-38.4, y - 38.4);
        kiosk.scale(0.2,0.2);
        size = std::vector<float>{102.4,102.4};
        text.setString("Press F to use Kiosk");
        text.setFont(Interactable::font);
        price.emplace_back();
        price.emplace_back();
        price.emplace_back();

        text.setPosition(kiosk.getPosition().x, kiosk.getPosition().y - (this->size[1]/2));
        tempInside.setSize(sf::Vector2f{400,400});
        tempInside.setPosition(kiosk.getPosition().x + (size[0]/2) - 200, kiosk.getPosition().y + (size[1]/2) - 200 );
        tempInside.setFillColor(sf::Color::White);
        items.emplace(std::make_unique<Health>(x,y - 100), std::make_pair(10,0));
        items.emplace(std::make_unique<TimeIncreaser>(x,y), std::make_pair(15,0));
        items.emplace(std::make_unique<Coin>(x,y + 100), std::make_pair(3,0));
        auto it = items.begin();
        for(auto & e : price)
        {
            e.setFont(Interactable::font);
            e.setFillColor(sf::Color::Black);
            e.setString("Price: " + std::to_string(it->second.first));
            e.setPosition(it->first->getPosition().x + 15, it->first->getPosition().y + 10);
            it++;
        }

//        price.setPosition(items.begin()->first->getPosition().x +5, items.begin()->first->getPosition().y + 5);
//        price.setString("Price: " + std::to_string(items.begin()->second.first));
//        price.setFillColor(sf::Color::Black);

    }


    ~Kiosk() override;
    void draw(sf::RenderWindow& window) override;
    void update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time, sf::Time deltatime) override;
    void collision(Player& player, sf::RenderWindow &window) override;
    bool getStatus() override;
    sf::Vector2<float> getPosition() override;
    sf::Vector2<float> getSize() override;


private:
    std::map<std::unique_ptr<Collectable>, std::pair<int, int>> items; // First is Price second is how many
    bool inUse = false;
    int id = 201;
    sf::Text text;
    std::vector<sf::Text> price;
    std::vector<float> size;
    sf::Sprite kiosk;
    sf::Sprite inside; // TODO
    sf::RectangleShape tempInside;

};


