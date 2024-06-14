#pragma once

#include <random>
#include "Interactable.h"
#include "Collectable.h"
#include "../ResourceManager.h"
#include "Coin.h"
#include "UniCard.h"

static int idnum = 0;
class Chest
        : public Interactable{
public:
    Chest(float x, float y) : Interactable(x,y){
        xID = idnum++;
        this->chestTexture.setTexture(ResourceManager::getTexture("../graphics/chest.png"));
        this->chestTexture.setPosition(x, y);
        this->chestTexture.scale(0.1, 0.1);
        this->size = std::vector<float>{61, 60};
        this->content.setTexture(ResourceManager::getTexture("../graphics/shelf.png"));
        this->content.setPosition(chestTexture.getPosition().x - 30, chestTexture.getPosition().y);
        std::random_device rd;
        std::mt19937 gen(rd()); // Mersenne Twister engine
        std::uniform_int_distribution<> dist(1, 5);
        int numberOfItems = dist(gen);
        this->itemsInside.emplace(std::make_unique<Coin>(content.getPosition().x +  15, content.getPosition().y + 15), numberOfItems);
//        if(xID == 0){
//            this->itemsInside.emplace(std::make_unique<UniCard>(x + 30, y), 1);
//        }
        popUp.setString("Press F to open chest");
        popUp.setFont(Interactable::font);
        popUp.setPosition(chestTexture.getPosition().x, chestTexture.getPosition().y - this->size[1]);
        number.setString(std::to_string(itemsInside.begin()->second));
        number.setFont(Interactable::font);
        number.setFillColor(sf::Color::Black);
        number.setPosition(itemsInside.begin()->first->getPosition().x + (itemsInside.begin()->first->getSize().x), itemsInside.begin()->first->getPosition().y );
//        number.setCharacterSize(10);

    }
     void draw(sf::RenderWindow& window) override;
     sf::Vector2<float> getPosition()override;
     sf::Vector2<float> getSize()override;
     ~Chest()override;
     void update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time, sf::Time deltatime)override;
     void collision(Player& player, sf::RenderWindow &window) override;
     bool getStatus() override;

private:
    sf::Text popUp;
    sf::Sprite chestTexture;
    std::map<std::unique_ptr<Collectable>, int> itemsInside;
    sf::Sprite content;
    sf::Text number;
    int id=103;
    int xID;
    bool isOpen = false;
    bool active = false;
    std::vector<float> position;
    std::vector<float> size;
    float lastUsed = 0;
    float lastActive = 0;
};

