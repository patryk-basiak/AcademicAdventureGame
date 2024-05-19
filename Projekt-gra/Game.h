#pragma once

#include <vector>
#include "Map.h"
#include "HUD.h"

class Game {


public:
    Game(){
        loaded = false;
        fmt::println("game constructed");
    }
    void loadGraphics();
    void update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time deltaTime, HUD& hud);
    void gameRules(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time deltaTime, HUD& hud);
    int getCurrentLvl() const;

private:
    sf::Clock clockLvl0;
    bool loaded;
    bool game;
    bool debug = false;
    bool pause;
    bool menu;
    int currentLvl;
    std::vector<Map> maps;
    Map currentMap = Map(0, 0, MapTypes::STARTING, 0);
    unsigned int lastLvl = maps.size();

};
