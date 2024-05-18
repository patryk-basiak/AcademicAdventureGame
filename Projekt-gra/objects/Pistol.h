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
    Pistol(float x, float y, float width, float height) : Collectable(x, y, sf::Color{255, 165, 0, 255 }, width, height){
        fmt::println("pistol created v2 ");
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

    Pistol& operator=(const Pistol& other) {
        if (this != &other) { // Check for self-assignment
            // Assign base class members
            Collectable::operator=(other);

            // Assign member variables
            ID = other.ID;
            Stackable = other.Stackable;
            am = other.am;
            toAdd = other.toAdd;

            // Assign the ammo vector
            ammo.clear(); // Clear existing content
            for (const auto& shape : other.ammo) {
                ammo.push_back(shape);
            }

            // Assign the pistol shape
            pistol = other.pistol;
        }
        return *this;
    }


    void setPosition(float x, float y) override;
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
    int ammunition = 3;
    bool Stackable = false;
    std::vector<sf::RectangleShape> ammo;
    sf::Sprite pistol;
    std::vector<int> am;
    bool toAdd = false;

};