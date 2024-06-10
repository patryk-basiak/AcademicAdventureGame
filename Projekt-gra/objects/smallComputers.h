#pragma once



#include "Entity.h"
#include "../ResourceManager.h"

class SmallComputers
        : public Entity{

public :SmallComputers(float x, float y) : Entity(x, y, sf::Color::Black) {
        computer.setTexture(ResourceManager::getTexture("../graphics/computerBoss.png"));
        computer.scale((float)64/computer.getTexture()->getSize().x, (float)64/computer.getTexture()->getSize().y);
        computer.setPosition(x, y);
        initialPositionX = x;
        initialPositionY = y;
        velocity = 50; //TODO
        health = 2;
        horizontalVelocity = 0;
        healthLine.setPosition(computer.getPosition().x, computer.getPosition().y - 15);
        healthLine.setFillColor(sf::Color::Red);
        healthLine.setSize(sf::Vector2f (this->getSize().x, 4));
        part = (float)this->getSize().x/health;
    }


public:
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getGlobalBounds()override;
    void update(sf::Time time, Player& player)override;
    void collision(Player& player)override;
    sf::Vector2<float> getPosition()override;
    sf::Vector2<float> getSize()override;
    ~SmallComputers() override;
    void setPosition(float d, float d1);
    void setVerticalVelocity(int i) override;
    void setVelocity(int i) override;
    void setHealth(int i) override;
    int getHealth()  override;


private:
    int id =7;
    bool followingPlayer = false;
    float gravity = 50;
    int health = 2;
    sf::Sprite computer;
    float velocity;
    float horizontalVelocity;
    float initialPositionX;
    float initialPositionY;
    float lastShot = 0;
    float shootCooldown = 2;
    float respawnTime = 0;
    bool respawnTimeSet = false;
    sf::RectangleShape healthLine;
    float part;

};

