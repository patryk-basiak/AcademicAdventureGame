#pragma once


#include "../ResourceManager.h"
#include "Interactable.h"

class Door
            : public Interactable{

    public:
        Door(float x, float y) : Interactable(x,y){
            isOpen = false;
            door.setTexture(ResourceManager::getTexture("../graphics/doorClosed.png"));
            door.setPosition(x,y);
            door.setScale(0.1,(float)128/door.getTexture()->getSize().y);
            doorOpen.setTexture(ResourceManager::getTexture("../graphics/doorOpen.png"));
            doorOpen.setPosition(x,y);
            doorOpen.setScale((float)64/doorOpen.getTexture()->getSize().x,(float)128/doorOpen.getTexture()->getSize().y);
        }
        sf::Vector2<float> getSize() override;
        sf::Vector2<float> getPosition() override;
        ~Door() override;
        void collisionRight(Player& player, sf::RenderWindow &window) override;
        void collisionLeft(Player& player, sf::RenderWindow &window) override;
        void draw(sf::RenderWindow &window) override;
        void update(sf::RenderWindow& window, Player& player, Equipment& eq,  sf::Time, sf::Time deltatime) override;
        bool status() const;
        void setStatus(bool status);

    private:
        int id = 99;
        float lastUsed;
        sf::Sprite door;
        sf::Sprite doorOpen;
        bool isOpen;


    };
