#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include <memory>
#include "Settings.h"
#include "objects/Collectable.h"
#include "Player.h"

class Equipment {

protected:

private:
    int size = 9;
    float padding = 10;
    int currentEq;
    bool isEmpty = true;
    bool isShown = false;
    std::vector<std::shared_ptr<Collectable>> temp_items;
    std::map<int, std::pair<std::shared_ptr<Collectable>, int>> items;
    std::vector<int> numberOfItems;


    sf::Font font;
public:

    Equipment();
//    static int currentPos;
    static std::vector<int> eq;
    void movedMouse();
    std::shared_ptr<Collectable> getItemInHand();
    void movedMouseDown();
    int itemInHand() const;
    bool getStatus();
    sf::RectangleShape eqRect;
    sf::RectangleShape smallEq;
    sf::RectangleShape pointer;
    void showInHand(Player& player, sf::RenderWindow& window) const;
    void update(sf::RenderWindow& window, Player& player);
    void show();
    void addItem(int ID);
    std::vector<std::shared_ptr<Collectable>> throwable;

    void useItemInHand(Player& player);

    int getMoney();
    void setMoney(int n);
};


