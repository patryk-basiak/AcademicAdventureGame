#pragma once

#include <vector>
#include <unordered_map>
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
    int currentEq = 0;
    bool isEmpty = true;
    bool isShown = false;
    std::vector<std::unique_ptr<Collectable>> temp_items;
    std::map<int, std::pair<std::unique_ptr<Collectable>, int>> items;
    std::vector<int> numberOfItems;
    std::vector<int> itemPos;
    int holding = 99;
    bool mouseClicked = false;
    bool isHolding = false;
    float lastClicked = 0;
    float lastOpen = 0;
    sf::Font font;
public:

    Equipment();
//    static int currentPos;
    static std::vector<int> eq;
    void movedMouse();
    void movedMouseDown();
    int itemInHand() const;
    bool getStatus();
    sf::RectangleShape eqRect;
    sf::RectangleShape smallEq;
    sf::RectangleShape pointer;
    void showInHand(Player& player, sf::RenderWindow& window) const;
    void update(sf::RenderWindow& window, Player& player, sf::Time timer);
    void show();
    void addItem(int ID);
    bool hasItem(int ID);

    void useItemInHand(Player& player);

    int getMoney();
    void setMoney(int n);
};


