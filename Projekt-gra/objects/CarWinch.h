#pragma once

#include "Interactable.h"
#include "../ResourceManager.h"

class CarWinch
        : public Interactable{
public:
    CarWinch(float x , float y) : Interactable(x, y){
        isPicked = false;
        isAttached = false;
        isPlaced = false;
        winch.setPosition(x,y);
        winch.setTexture(ResourceManager::getTexture("../graphics/carWinch.png"));
        winch.setScale(0.1,0.1);
        popUp.setString("Press F to use winch");
        popUp.setFont(Interactable::font);
        popUp.setPosition(winch.getPosition().x, winch.getPosition().y - winch.getTexture()->getSize().y);
        attach.setString("Press Q to attach winch");
        attach.setFont(Interactable::font);
    }

    void draw(sf::RenderWindow& window) override;
    sf::Vector2<float> getPosition()override;
    sf::Vector2<float> getSize()override;
    ~CarWinch()override;
    void update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time)override;
    void collision(Player& player, sf::RenderWindow &window) override;
    bool getStatus() override;






private:
    int id = 301;
    sf::Sprite winch;
    sf::RectangleShape line;
    bool isPicked;
    bool isPlaced;
    sf::Text popUp;
    sf::Text attach;
    bool isAttached;

};

