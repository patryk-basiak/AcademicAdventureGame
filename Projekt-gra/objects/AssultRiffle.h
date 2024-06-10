#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Player.h"
#include "Collectable.h"
#include "fmt/core.h"
#include "../ResourceManager.h"


class AssultRiffle
        : public Collectable{

public:
    AssultRiffle(float x, float y) : Collectable(x, y, sf::Color{255, 165, 0, 255 }, 60, 60){
        fmt::println("AssaltRifle created");
        assultRifle.setTexture(ResourceManager::getTexture("../graphics/ak.png"));
        assultRifle.scale((float)64 / assultRifle.getTexture()->getSize().x, (float)32 / assultRifle.getTexture()->getSize().y);
        assultRifle.setPosition(x,y);
    }



    void setPosition(float x, float y) override;
    void usage(Player& player) override;
    std::vector<sf::RectangleShape> getAmmoList() override;
    void draw(sf::RenderWindow& window) override;
    void collision(Player& player) override;
    void update(sf::RenderWindow& window, Player& player) override;
    bool isStackable() const override;
    int getId() override;

private:
    sf::Clock clock;
    float lastShotTime = 0;
    float shotCooldown = 0.2;
    float reloadTime = 3;
    float reloadStart = 0;
    bool reloading = false;
    bool ready = true;
    void shot();
    int ID = 13;
    int ammunition = 30;
    bool Stackable = false;
    std::vector<sf::RectangleShape> ammo;
    sf::Sprite assultRifle;
    std::vector<int> am;
    bool toAdd = false;

};