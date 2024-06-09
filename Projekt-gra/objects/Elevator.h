#pragma once


#include "../ResourceManager.h"
#include "Interactable.h"
static int num = 0;
class Elevator
        : public Interactable{

public:
    Elevator(float x, float y) : Interactable(x,y){
        val = num++;
        isOpen = false;
        elevator.setTexture(ResourceManager::getTexture("../graphics/elevatorClosed.png"));
        elevator.setPosition(x,y);
        elevator.setScale((float)128/elevator.getTexture()->getSize().x,(float)128/elevator.getTexture()->getSize().y);
        popUp.setString("Press F to use elevator");
        popUp.setFont(Interactable::font);
        popUp.setPosition(elevator.getPosition().x, elevator.getPosition().y - (elevator.getTexture()->getSize().y*elevator.getScale().y/3));
        chooser.setPosition(elevator.getPosition().x - ( this->getSize().x /2), elevator.getPosition().y +( this->getSize().y /3) );
        chooser.setSize(sf::Vector2f (175,150));
        pointer.setSize(sf::Vector2f (100, 2));
        pointer.setFillColor(sf::Color::Blue);
        for(int i = 0; i<3; ++i){
            sf::Text temp;
            if(i == 0) {
                temp.setString("Ground floor");
            }else{
                temp.setString(std::to_string(i) + " floor");
            }
            temp.setPosition(chooser.getPosition().x + 25, chooser.getPosition().y + 25 + (35*i));
            temp.setFont(Interactable::font);
            if(i != 2 - val){
                temp.setFillColor(sf::Color::Black);
            }else{
                temp.setFillColor(sf::Color{192,192,192,255});
            }
            floors.push_back(temp);
        }
    }
    sf::Vector2<float> getSize() override;
    sf::Vector2<float> getPosition() override;
    ~Elevator() override;
    void collisionRight(Player& player, sf::RenderWindow &window) override;
    void collisionLeft(Player& player, sf::RenderWindow &window) override;
    void draw(sf::RenderWindow &window) override;
    void update(sf::RenderWindow& window, Player& player, Equipment& eq,  sf::Time, sf::Time deltatime) override;
    bool status() const;
    void setStatus(bool status);

private:
    int val = 0;
    int id = 401;
    float lastUsed = 0;
    float lastActive = 0;
    float pickedTime = 0;
    float tempPositionY = 0;
    sf::Text popUp;
    std::vector<sf::Text> floors;
    sf::Sprite elevator;
    sf::RectangleShape chooser;
    sf::RectangleShape pointer;
    bool isOpen;
    bool isActive = false;
    bool blocked = false;


};
