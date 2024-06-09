#pragma once

#include <random>
#include "Interactable.h"
#include "Collectable.h"
#include "../ResourceManager.h"
#include "Coin.h"
#include "Pistol.h"

class Wardrobe
        : public Interactable{
public:
    Wardrobe(float x, float y) : Interactable(x,y){
        this->wardrobeTexture.setTexture(ResourceManager::getTexture("../graphics/wardrobe.png"));
        this->wardrobeTexture.setPosition(x,y-36 );
        this->wardrobeTexture.scale((float)64/wardrobeTexture.getTexture()->getSize().x,(float)100/wardrobeTexture.getTexture()->getSize().y);
        this->shelf.setTexture(ResourceManager::getTexture("../graphics/shelf.png"));
        this->shelf.setPosition(wardrobeTexture.getPosition().x - 30, wardrobeTexture.getPosition().y);
        std::random_device rd;
        std::mt19937 gen(rd()); // Mersenne Twister engine
        std::uniform_int_distribution<> dist(1, 3);
        int numberOfItems = dist(gen);
        if(numberOfItems > 0) {
            this->itemsInside.insert({std::make_shared<Coin>(shelf.getPosition().x +  15, shelf.getPosition().y + 15), numberOfItems});

        }
        this->itemsInside.insert({std::make_shared<Pistol>(shelf.getPosition().x +  50, shelf.getPosition().y + 15), 1});
        popUp.setString("Press F to open wardrobe");
        popUp.setFont(Interactable::font);
        popUp.setPosition(wardrobeTexture.getPosition().x, wardrobeTexture.getPosition().y - (this->getSize().y/2));
    }
     void draw(sf::RenderWindow& window) override;
     sf::Vector2<float> getPosition()override;
        sf::Vector2<float>  getSize()override;
     ~Wardrobe()override;
     void update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time time, sf::Time deltatime)override;
     void collision(Player& player, sf::RenderWindow &window) override;
     bool getStatus() override;
private:
    sf::Text popUp;
    sf::Sprite wardrobeTexture;
    std::map<std::shared_ptr<Collectable>, int> itemsInside;
    sf::Sprite shelf;
    bool active = false;
    bool possible = false;
    int id=103;
    bool isOpen = false;
    std::vector<float> position;
    float lastUsed = 0;
};

