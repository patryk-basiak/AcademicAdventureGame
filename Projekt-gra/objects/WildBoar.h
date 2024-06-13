#pragma once

#include "Entity.h"
#include <random>
#include "../ResourceManager.h"

class WildBoar
        : public Entity{

public :WildBoar(float x, float y) : Entity(x, y, sf::Color::Black) {
        gen = std::mt19937(rd());
        destination = std::uniform_int_distribution<>(300, 1500);
        wantedPos = (float)destination(gen);
        wild.setTexture(ResourceManager::getTexture("../graphics/0wildboarLeft.png"));
        wild.setPosition(x, y);
        wild.scale(0.1, 0.1);
        initialPositionX = x;
        initialPositionY = y;
        velocity = 50; //TODO
        health = 3;
        horizontalVelocity = 0;
        healthLine.setPosition(wild.getPosition().x, wild.getPosition().y - 15);
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
    ~WildBoar() override;
    void setPosition(float d, float d1);
    void setVerticalVelocity(int i) override;
    void setVelocity(int i) override;
    void setHealth(int i) override;
    int getHealth()  override;


private:
    int id =2;
    bool followingPlayer = false;
    float gravity = 50;
    int health = 3;
    sf::Sprite wild;
    float velocity;
    float horizontalVelocity;
    float initialPositionX;
    float initialPositionY;
    float wantedPos;
    sf::RectangleShape healthLine;
    float part;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> destination;


};

