#pragma once

#include "Entity.h"
#include "../ResourceManager.h"
#include <random>
class ComputerBoss
        : public Entity{

public :ComputerBoss(float x, float y) : Entity(x, y, sf::Color::Black) {
        computer.setTexture(ResourceManager::getTexture("../graphics/computerBoss.png"));
        computer.setPosition(x, y);
        computer.scale((float)512/computer.getTexture()->getSize().x, (float)320/computer.getTexture()->getSize().y);
        initialPositionX = x;
        initialPositionY = y;
        velocity = 50; //TODO
        health = 31;
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
    ~ComputerBoss() override;
    void setPosition(float d, float d1);
    void setVerticalVelocity(int i) override;
    void setVelocity(int i) override;
    void setHealth(int i) override;
    int getHealth()  override;


private:
    int id =6;
    bool followingPlayer = false;
    float gravity = 50;
    int health;
    sf::Sprite computer;
    float velocity;
    float horizontalVelocity;
    float initialPositionX;
    float initialPositionY;
    sf::RectangleShape healthLine;
    float part;
    bool addMoney = false;
    bool bulletSpawn = false;
    std::random_device rd;
    std::mt19937 gen = std::mt19937(this->rd());
    std::uniform_int_distribution<> coinPos = std::uniform_int_distribution<>(0, 150);
    std::uniform_int_distribution<> coinPosY= std::uniform_int_distribution<>(280, 320);
    std::uniform_int_distribution<> bulletPosY= std::uniform_int_distribution<>(0, 300);
    std::uniform_int_distribution<> sign = std::uniform_int_distribution<>(-1, 1);
    std::uniform_int_distribution<> bulletAmount = std::uniform_int_distribution<>(0, 3);

};

