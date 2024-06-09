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
        winch.setScale((float)64/winch.getTexture()->getSize().x,(float)64/winch.getTexture()->getSize().y);
        popUp.setString("Press F to use winch");
        popUp.setFont(Interactable::font);
        popUp.setPosition(winch.getPosition().x, winch.getPosition().y - winch.getTexture()->getSize().y*winch.getScale().y);
        attach.setString("Press Q to attach winch");
        attach.setFont(Interactable::font);
        line.setSize(sf::Vector2f {10,5});
        line.setPosition(sf::Vector2f {winch.getPosition().x + 40,winch.getPosition().y});
        line.setFillColor(sf::Color::Blue);
    }

    void draw(sf::RenderWindow& window) override;
    sf::Vector2<float> getPosition()override;
    sf::Vector2<float> getSize()override;
    ~CarWinch()override;
    void update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time, sf::Time deltatime)override;
    void collision(Player& player, sf::RenderWindow &window) override;
    bool getStatus() override;
    void check(std::unique_ptr<Wall>& wall) override;






private:
    int id = 301;
    sf::Sprite winch;
    sf::RectangleShape line;
    bool isPicked;
    bool active = false;
    bool isPlaced;
    sf::Text popUp;
    sf::Text attach;
    bool isAttached;
    bool possibleToAttached;
    bool run = false;
    float deltaTimeX = 0;

};

