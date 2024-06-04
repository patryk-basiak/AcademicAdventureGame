#pragma once

#include "Interactable.h"
#include "../ResourceManager.h"
#include "Coin.h"

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
        price.setFont(Interactable::font);
        price0.setFont(Interactable::font);
        price1.setFont(Interactable::font);

        text.setPosition(kiosk.getPosition().x, kiosk.getPosition().y - (this->size[1]/2));
        tempInside.setSize(sf::Vector2f{400,400});
        tempInside.setPosition(kiosk.getPosition().x + (size[0]/2) - 200, kiosk.getPosition().y + (size[1]/2) - 200 );
        tempInside.setFillColor(sf::Color::White);
        items.emplace(std::make_unique<Coin>(x,y), std::make_pair(5,0));
        items.emplace(std::make_unique<Coin>(x,y), std::make_pair(3,0));
        items.emplace(std::make_unique<Coin>(x,y), std::make_pair(3,0));

        price.setPosition(items.begin()->first->getPosition().x +5, items.begin()->first->getPosition().y + 5);
        price.setString("Price: " + std::to_string(items.begin()->second.first));
        price.setFillColor(sf::Color::Black);

    }


    ~Kiosk() override;
    void draw(sf::RenderWindow& window) override;
    void update(sf::RenderWindow& window, Player& player, Equipment& eq) override;
    void collision(Player& player, sf::RenderWindow &window) override;
    bool getStatus() override;
    sf::Vector2<float> getPosition() override;
    std::vector<float> getSize() override;


private:
    std::map<std::unique_ptr<Collectable>, std::pair<int, int>> items; // First is Price second is how many
    bool inUse = false;
    int id = 201;
    sf::Text text;
    sf::Text price;
    sf::Text price0;
    sf::Text price1;
    std::vector<float> size;
    sf::Sprite kiosk;
    sf::Sprite inside; // TODO
    sf::RectangleShape tempInside;

};


