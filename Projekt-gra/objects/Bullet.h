#pragma once

#include "Collectable.h"

class Bullet :
        public Collectable {

public:
    Bullet(float x, float y) : Collectable(x, y, sf::Color{255, 165, 0, 255 }, 16, 16){
        bullet.setPosition(x,y);
        bullet.setRadius(8);
        bullet.setFillColor(sf::Color::Black);
        initalPosX = x;
        initalPosY = y;
        type = 0;
    }Bullet(float x, float y, int n) : Collectable(x, y, sf::Color{255, 165, 0, 255 }, 16, 16){
        bullet.setPosition(x,y);
        bullet.setRadius(6);
        bullet.setFillColor(sf::Color::Blue);
        initalPosX = x;
        initalPosY = y;
        direction = n;
        type = 0;
    }Bullet(float x, float y, int n, float angle, float angleY) : Collectable(x, y, sf::Color{255, 165, 0, 255 }, 16, 16){
        bullet.setPosition(x,y);
        bullet.setRadius(8);
        bullet.setFillColor(sf::Color::Black);
        initalPosX = x;
        initalPosY = y;
        direction = n;
        this->degX = angle;
        this->degY = angleY;
        type = 2;
    }Bullet(float x, float y, int n, float angle, float angleY, float l) : Collectable(x, y, sf::Color{255, 165, 0, 255 }, 16, 16){
        bullet.setPosition(x,y);
        bullet.setRadius(8);
        bullet.setFillColor(sf::Color::Black);
        initalPosX = x;
        initalPosY = y;
        direction = n;
        this->degX = angle;
        this->degY = angleY;
        type = 3;
    }
    void setPosition(float x, float y) override;
    sf::Vector2<float> getPosition() override;
    sf::FloatRect getGlobalBounds() override;
    std::vector<sf::RectangleShape> getAmmoList() override;
    void draw(sf::RenderWindow& window) override;
    void collision(Player& player) override;
    void update(sf::RenderWindow& window, Player& player) override;
    bool isStackable() const override;
    int getId() override;

private:
    int direction;
    int id = 4;
    float initalPosX;
    float initalPosY;
    float velocity = 0.5;
    float degX;
    float degY;
    float type;
    sf::CircleShape bullet;
};


