#pragma once

#include <vector>
#include <fstream>
#include "Map.h"
#include "HUD.h"
#include "DialogElement.h"

class Game {


public:
    Game(){
        loaded = false;
        maps.emplace_back(0, 0, MapTypes::STARTING, 0);
        maps.emplace_back(0, 0, MapTypes::FOREST, 0);
        maps.emplace_back(15, 0, MapTypes::FOREST, 1);
        maps.emplace_back(0, 1, MapTypes::FOREST, 2);
        maps.emplace_back(0, 1, MapTypes::CITY, 0);
        maps.emplace_back(0, 1, MapTypes::CITY, 1);
        maps.emplace_back(0, 1, MapTypes::CITY, 2);
        maps.emplace_back(0, 1, MapTypes::PJATK, 0);
        maps.emplace_back(0, 1, MapTypes::PJATK, 1);
        maps.emplace_back(0, 1, MapTypes::PJATK, 0);
        currentLvl = 0;
        currentMap = std::move(maps[currentLvl]);
        lastLvl = maps.size();
        for(auto &e : maps) {
            spawnPoints.insert({{e.getMainType(), e.getSubType()},
                                {e.getSpawnPoint(),e.getSpawnPoint() }}); //TODO
        }
        fmt::println("game constructed");

    }

    void loadGraphics();
    void update(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Clock& Time, HUD& hud, FPS& fps, sf::Time deltatime);
    void gameRules(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Time deltaTime, HUD& hud);
    int getCurrentLvl() const;
    bool getNextRoomAvailability() const;

    void startGame();
    void gameSave(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Clock Time, bool permanent);
    void gameLoad(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Clock Time, bool newGame, std::string file_path);

private:

    void nextLvl(sf::RenderWindow& window, Player& player, Equipment& eq, sf::Clock Time);
    sf::Clock clockLvl0;
//    std::vector<DialogElement> dialog = std::vector<DialogElement>{DialogElement("What a lovely sunday!")};
    bool loaded;
    bool nextRoomAvailable  = false;
    bool debug = false;
    bool started;
    bool clockedRestarted = false;
    int currentLvl = 0;
    std::vector<Map> maps;
    float lastLvlChanged = 0;
    Map currentMap = Map(0, 0, MapTypes::STARTING, 0);
    unsigned int lastLvl = maps.size();
    std::vector<int> decisions = std::vector<int>();
    std::map<std::pair<MapTypes::types, int>, std::pair<std::vector<float>, std::vector<float>>> spawnPoints;
    std::map<int, float> spawn;
    bool game_started = false;
    std::string file_path;
    std::string temp_path;

};
