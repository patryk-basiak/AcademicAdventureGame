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
        this->itemsInside.insert({std::make_shared<Coin>(x, y), numberOfItems});
        //TODO jakie inne itemy
        if(xID == 0){
            this->itemsInside.insert({std::make_shared<UniCard>(x + 30, y), 1});
        }
        popUp.setString("Press F to open chest");
        popUp.setFont(Interactable::font);
        popUp.setPosition(chestTexture.getPosition().x, chestTexture.getPosition().y - this->size[1]);

    }
     void draw(sf::RenderWindow& window) override;
     sf::Vector2<float> getPosition()override;
    sf::Vector2<float> getSize()override;
     ~Chest()override;
     void update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time)override;
     void collision(Player& player, sf::RenderWindow &window) override;
     bool getStatus() override;

private:
    sf::Text popUp;
    sf::Sprite chestTexture;
    std::map<std::shared_ptr<Collectable>, int> itemsInside;
    sf::Sprite content;
    int id=103;
    int xID;
    bool isOpen = false;
    bool active = false;
    std::vector<float> position;
    std::vector<float> size;
};

