#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Player.h"
#include "Collectable.h"
#include "fmt/core.h"
#include "../ResourceManager.h"


class Pistol
        : public Collectable{

public:
    Pistol(float x, float y) : Collectable(x, y, sf::Color{255, 165, 0, 255 }, 60, 60){
        fmt::println("pistol created");
        pistol.scale(0.042,0.042);
        pistol.setTexture(ResourceManager::getTexture("../graphics/pistol.png"));
        pistol.setPosition(x,y);
    }

    Pistol(const Pistol& other) // copy constructor
            : Collectable(other)
    {
        ID = other.ID;
        Stackable = other.Stackable;
        am = other.am;
        toAdd = other.toAdd;

        for (const auto& shape : other.ammo) {
            ammo.push_back(shape);
        }

        pistol = other.pistol;
    }


    void setPosition(float x, float y) override;
    void usage(Player& player) override;
    std::vector<sf::RectangleShape> getAmmoList() override;
    void draw(sf::RenderWindow& window) override;
    bool operator==(const Collectable& other) const override;
    bool operator==(const Pistol& other) const;
    void collision(Player& player) override;
    void update(sf::RenderWindow& window) override;
    bool isStackable() const override;
    std::unique_ptr<Collectable> clone() const override;
    int getId() override;

private:
    sf::Clock clock;
    float lastShotTime = 0;
    float shotCooldown = 2;
    float reloadTime = 4;
    float reloadStart = 0;
    bool reloading = false;
    bool ready = true;
    void shot();
    int ID = 2;
    int ammunition = 15;
    bool Stackable = false;
    std::vector<sf::RectangleShape> ammo;
    sf::Sprite pistol;
    std::vector<int> am;
    bool toAdd = false;

};