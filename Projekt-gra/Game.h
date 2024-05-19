#pragma once

#include <vector>
#include "Map.h"
#include "HUD.h"

class Game {


public:
    Game(){
      maps = std::vector<Map>{
//        Map(0,0, MapTypes::TESTING, 0),
              Map(0,0, MapTypes::STARTING, 0),
              Map(0,0, MapTypes::STARTING, 0),
              Map(3,0, MapTypes::FOREST, 0),
              Map(5,1, MapTypes::FOREST, 1),
              Map(1,10, MapTypes::CITY, 0),
              Map(0,6, MapTypes::CITY, 1),
              Map(1,3, MapTypes::PJATK, 0),
              Map(2,14, MapTypes::PJATK, 1),
              Map(0,6, MapTypes::CITY, 2),
              Map(2,4, MapTypes::FOREST, 2),
              Map(2,4, MapTypes::ENDING, 0),
      };
      currentLvl = 0;
      currentMap = maps[currentLvl];
    }
    void update(sf::RenderWindow& window, Player& player, Equipment eq, sf::Time deltaTime, HUD& hud);

private:
    bool game;
    bool debug = false;
    bool pause;
    bool menu;
    int currentLvl;
    std::vector<Map> maps;
    Map currentMap = Map(0, 0, MapTypes::STARTING, 0);
    unsigned int lastLvl = maps.size();

};
