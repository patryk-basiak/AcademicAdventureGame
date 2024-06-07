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
    Wardrobe(float x, float y) : Interactable(x+15,y-15){
        this->wardrobeTexture.setTexture(ResourceManager::getTexture("../graphics/wardrobe.png"));
        this->wardrobeTexture.setPosition(x + 15,y - 15);
        this->wardrobeTexture.scale(0.2,0.2);
        this->size = std::vector<float>{64.6, 80};
        this->shelf.setTexture(ResourceManager::getTexture("../graphics/shelf.png"));
        this->shelf.setPosition(wardrobeTexture.getPosition().x - 30, wardrobeTexture.getPosition().y);
        std::random_device rd;
        std::mt19937 gen(rd()); // Mersenne Twister engine
        std::uniform_int_distribution<> dist(1, 3);
        int numberOfItems = dist(gen);
        if(numberOfItems > 0) {
            this->itemsInside.insert({std::make_shared<Coin>(x + 15, y), numberOfItems});

        }
        this->itemsInside.insert({std::make_shared<Pistol>(x + 30, y), 1});
        popUp.setString("Press F to open wardrobe");
        popUp.setFont(Interactable::font);
        popUp.setPosition(wardrobeTexture.getPosition().x, wardrobeTexture.getPosition().y - this->size[1]);
    }
     void draw(sf::RenderWindow& window) override;
     sf::Vector2<float> getPosition()override;
        sf::Vector2<float>  getSize()override;
     ~Wardrobe()override;
     void update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time time)override;
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
    std::vector<float> size;
    float lastUsed = 0;
};

