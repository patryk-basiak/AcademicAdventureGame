#pragma once

#include "Entity.h"
#include "../ResourceManager.h"

class WildBoar
        : public Entity{

public :WildBoar(float x, float y) : Entity(x, y, sf::Color::Black) {
        wild.setTexture(ResourceManager::getTexture("../graphics/0wildboarLeft.png"));
        wild.setPosition(x, y);
        wild.scale(0.1, 0.1);
        initialPositionX = x;
        initialPositionY = y;
        velocity = 50; //TODO
        health = 1;
        horizontalVelocity = 0;
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


private:
    int id =2;
    bool followingPlayer = false;
    float gravity = 50;
    int health;
    sf::Sprite wild;
    float velocity;
    float horizontalVelocity;
    float initialPositionX;
    float initialPositionY;

};

