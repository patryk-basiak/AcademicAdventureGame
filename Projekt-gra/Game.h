#pragma once

#include <vector>
#include "Map.h"
#include "HUD.h"
#include "DialogElement.h"

class Game {


public:
    Game(){
        loaded = false;
        maps.emplace_back(0, 0, MapTypes::FOREST, 2);
        fmt::println("game constructed");

    }

    void loadGraphics();
    void update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time deltaTime, HUD& hud, FPS& fps);
    void gameRules(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time deltaTime, HUD& hud);
    int getCurrentLvl() const;
    bool getNextRoomAvailability() const;

private:
    void nextLvl(Player & player);
    sf::Clock clockLvl0;
//    std::vector<DialogElement> dialog = std::vector<DialogElement>{DialogElement("What a lovely sunday!")};
    bool loaded;
    bool nextRoomAvailable  = false;
    bool debug = false;
    bool pause;
    bool started;
    int currentLvl = 0;
    std::vector<Map> maps;
    Map currentMap = Map(0, 0, MapTypes::STARTING, 0);
    unsigned int lastLvl = maps.size();
    std::vector<int> decisions = std::vector<int>();

};
