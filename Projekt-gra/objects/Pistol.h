#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Player.h"
#include "Collectable.h"


class Pistol
        : public Collectable{

public:
    Pistol(float x, float y) : Collectable(x, y, sf::Color{255, 165, 0, 255 }, 60, 60){
        pistol.setSize(sf::Vector2f(60,60));
        pistol.setPosition(x,y);
        pistol.setFillColor(sf::Color{ 255, 165, 0, 255 });
    }
    Pistol(float x, float y, float width, float height) : Collectable(x, y, sf::Color{255, 165, 0, 255 }, width, height){
        pistol.setSize(sf::Vector2f(width,height));
        pistol.setPosition(x,y);
        pistol.setFillColor(sf::Color{ 255, 165, 0, 255 });
    }

    void usage() override;
    void draw(sf::RenderWindow& window) override;
    bool operator==(const Collectable& other) const override;
    bool operator==(const Pistol& other) const;
    void collision(Player& player) override;
    void update(sf::RenderWindow& window) override;
    bool isStackable() const override;
    std::unique_ptr<Collectable> clone() const override;
    int getId() override;

private:
    void shot();
    int ID = 2;
    bool Stackable = false;
    std::vector<sf::RectangleShape> ammo;
    sf::RectangleShape pistol;
    std::vector<int> am;
    bool toAdd = false;

};