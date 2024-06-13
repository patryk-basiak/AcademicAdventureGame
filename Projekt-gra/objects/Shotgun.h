#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Player.h"
#include "Collectable.h"
#include "fmt/core.h"
#include "../ResourceManager.h"


class Shotgun
        : public Collectable{

public:
    Shotgun(float x, float y) : Collectable(x, y, sf::Color{255, 165, 0, 255 }, 60, 60){
        fmt::println("shotgun created");
        shotgun.setTexture(ResourceManager::getTexture("../graphics/shotgun.png"));
        shotgun.scale((float)64/shotgun.getTexture()->getSize().x,(float)32/shotgun.getTexture()->getSize().y);
        shotgun.setPosition(x,y);
    }
    


    void setPosition(float x, float y) override;
    void usage(Player& player) override;
    std::vector<sf::RectangleShape> getAmmoList() override;
    void draw(sf::RenderWindow& window) override;
    void collision(Player& player) override;
    void update(sf::RenderWindow& window, Player& player) override;
    bool isStackable() const override;
    int getId() override;
    std::string getInfo() override;

private:
    sf::Clock clock;
    float lastShotTime = 0;
    float shotCooldown = 1;
    float reloadTime = 3;
    float reloadStart = 0;
    bool reloading = false;
    bool ready = true;
    void shot();
    int ID = 12;
    int ammunition = 12;
    bool Stackable = false;
    std::vector<sf::RectangleShape> ammo;
    sf::Sprite shotgun;
    std::vector<int> am;
    bool toAdd = false;

};